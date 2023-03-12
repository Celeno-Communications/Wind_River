// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/interrupt.h>
#include <linux/irq.h>
#include "reg_access.h"
#include "cl_ipc.h"
#include "cl_msg_pci.h"
#include "cl_prof.h"
#include "cl_irq.h"
#include "reg_ipc.h"
#include "chip.h"
#include "cl_hw.h"
#include "cl_tx.h"
#include "cl_radar.h"
#include "cl_rx_pci.h"
#include "pci.h"

static bool cl_rx_process_in_irq(struct cl_hw *cl_hw)
{
	struct cl_ipc_ring_indices *indices = cl_hw->ipc_env->ring_indices_elem->indices;
	u32 read_idx = le32_to_cpu(indices->rxdesc_read_idx[CL_RX_BUF_RXM]);
	u32 write_idx = le32_to_cpu(indices->rxdesc_write_idx[CL_RX_BUF_RXM]);
	u32 free_buffers = read_idx - write_idx;

	if (free_buffers < (IPC_RXBUF_CNT_RXM / 2)) {
		cl_hw->rx_info.buffer_process_irq++;

		return true;
	}

	cl_hw->rx_info.buffer_process_tasklet++;

	return false;
}

static void cl_irq_status_rxdesc(struct cl_hw *cl_hw, struct cl_ipc_host_env *ipc_env)
{
	/* Handle the reception of a Rx Descriptor */

	/* For profiling - capture time to handel all used rxdesc by embedded */
	PROF_REG_SW_SET(cl_hw, SW_PROF_IRQ_E2A_RXDESC);

	/*
	 * Disable the RX interrupt until rxelement/skb handled
	 * this would avoid redundant context switch + redundant tasklet scheduling
	 */
	cl_irq_disable(cl_hw, cl_hw->ipc_e2a_irq.rxdesc);

	/* Acknowledge the interrupt BEFORE handling the packet */
	ipc_xmac_2_host_ack_set(cl_hw->chip, cl_hw->ipc_e2a_irq.rxdesc);

	/*
	 * If more than 50% of buffer are populated handle them in the interrupt,
	 * otherwise schedule a tasklet to handle the buffers.
	 */
	if (cl_rx_process_in_irq(cl_hw))
		cl_rx_pci_desc_handler(cl_hw);
	else
		tasklet_schedule(&ipc_env->rxdesc_tasklet);

	/* For profiling */
	PROF_REG_SW_CLR(cl_hw, SW_PROF_IRQ_E2A_RXDESC);
}

static void cl_irq_status_txcfm(struct cl_hw *cl_hw, struct cl_ipc_host_env *ipc_env)
{
	/* TX confirmation descriptors have been received */
	PROF_REG_SW_SET(cl_hw, SW_PROF_IRQ_E2A_TXCFM);

	/*
	 * Disable the TXCFM interrupt bit - will be enabled
	 * at the end of cl_tx_pci_single_cfm_tasklet()
	 */
	cl_irq_disable(cl_hw, cl_hw->ipc_e2a_irq.txcfm);

	/* Acknowledge the TXCFM interrupt */
	ipc_xmac_2_host_ack_set(cl_hw->chip, cl_hw->ipc_e2a_irq.txcfm);

	/* Schedule tasklet to handle the TXCFM */
	tasklet_schedule(&cl_hw->tx_single_cfm_tasklet);

	PROF_REG_SW_CLR(cl_hw, SW_PROF_IRQ_E2A_TXCFM);
}

static void cl_irq_status_tbtt(struct cl_hw *cl_hw)
{
	/* For profiling */
	PROF_REG_SW_SET(cl_hw, SW_PROF_IRQ_E2A_TBTT);

	/* Acknowledge the interrupt BEFORE handling the request */
	ipc_xmac_2_host_ack_set(cl_hw->chip, cl_hw->ipc_e2a_irq.tbtt);

	cl_tx_bcns(cl_hw);

	PROF_REG_SW_CLR(cl_hw, SW_PROF_IRQ_E2A_TBTT);
}

static void cl_irq_status_msg(struct cl_hw *cl_hw, struct cl_ipc_host_env *ipc_env)
{
	PROF_REG_SW_SET(cl_hw, SW_PROF_IRQ_E2A_MSG);

	/* Acknowledge the interrupt BEFORE handling the request */
	ipc_xmac_2_host_ack_set(cl_hw->chip, cl_hw->ipc_e2a_irq.msg);

	/* Copy firmware messages to host */
	cl_msg_pci_copy_to_host(cl_hw, ipc_env);

	/* Schedule tasklet to handle the messages */
	tasklet_schedule(&cl_hw->rx_msg_tasklet);

	PROF_REG_SW_CLR(cl_hw, SW_PROF_IRQ_E2A_MSG);
}

static u8 cl_radar_handler(struct cl_hw *cl_hw, ptrdiff_t hostid)
{
	struct cl_radar_elem *radar_elem = (struct cl_radar_elem *)hostid;
	u8 ret = 0;
	struct cl_radar_pulse_array *pulses;

	/* Retrieve the radar pulses structure */
	pulses = (struct cl_radar_pulse_array *)radar_elem->radarbuf_ptr;

	/* Look for pulse count meaning that this hostbuf contains RADAR pulses */
	if (pulses->cnt == 0) {
		ret = -1;
		goto radar_no_push;
	}

	/* Push pulse information to queue and schedule a tasklet to handle it */
	cl_radar_push(cl_hw, radar_elem);

	/* Reset the radar element and re-use it */
	pulses->cnt = 0;

	/* Make sure memory is written before push to HW */
	wmb();

	/* Push back the buffer to the firmware */
	cl_ipc_radarbuf_push(cl_hw->ipc_env, (ptrdiff_t)radar_elem, radar_elem->dma_addr);

radar_no_push:
	return ret;
}

static void cl_irq_status_radar(struct cl_hw *cl_hw, struct cl_ipc_host_env *ipc_env)
{
	/*
	 * Firmware has triggered an IT saying that a radar event has been sent to upper layer.
	 * Then we first need to check the validity of the current msg buf, and the validity
	 * of the next buffers too, because it is likely that several buffers have been
	 * filled within the time needed for this irq handling
	 */

	PROF_REG_SW_SET(cl_hw, SW_PROF_IRQ_E2A_RADAR);

	/* Disable the RADAR interrupt bit - will be enabled at the end of cl_radar_tasklet() */
	cl_irq_disable(cl_hw, cl_hw->ipc_e2a_irq.radar);

	/* Acknowledge the RADAR interrupt */
	ipc_xmac_2_host_ack_set(cl_hw->chip, cl_hw->ipc_e2a_irq.radar);

	/* Push all new radar pulses to queue */
	while (cl_radar_handler(cl_hw,
				ipc_env->radar_hostbuf_array[ipc_env->radar_host_idx].hostid) == 0)
		;

	/* Schedule tasklet to handle the radar pulses */
	cl_radar_tasklet_schedule(cl_hw);

	PROF_REG_SW_CLR(cl_hw, SW_PROF_IRQ_E2A_RADAR);
}

static void cl_irq_status_dbg(struct cl_hw *cl_hw, struct cl_ipc_host_env *ipc_env)
{
	PROF_REG_SW_SET(cl_hw, SW_PROF_IRQ_E2A_DBG);

	/* Disable the DBG interrupt bit - will be enabled at the end of cl_dbgfile_tasklet() */
	cl_irq_disable(cl_hw, cl_hw->ipc_e2a_irq.dbg);

	/* Acknowledge the DBG interrupt */
	ipc_xmac_2_host_ack_set(cl_hw->chip, cl_hw->ipc_e2a_irq.dbg);

	/* Schedule tasklet to handle the debug */
	tasklet_schedule(&cl_hw->dbg_tasklet);

	PROF_REG_SW_CLR(cl_hw, SW_PROF_IRQ_E2A_DBG);
}

void cl_irq_status(struct cl_hw *cl_hw, u32 status)
{
	/* Handle all IPC interrupts on the host side */
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;

	if (status & cl_hw->ipc_e2a_irq.rxdesc)
		cl_irq_status_rxdesc(cl_hw, ipc_env);

	if (status & cl_hw->ipc_e2a_irq.txcfm)
		cl_irq_status_txcfm(cl_hw, ipc_env);

	if (status & cl_hw->ipc_e2a_irq.tbtt)
		cl_irq_status_tbtt(cl_hw);

	if (status & cl_hw->ipc_e2a_irq.msg)
		cl_irq_status_msg(cl_hw, ipc_env);

	if (status & cl_hw->ipc_e2a_irq.radar)
		cl_irq_status_radar(cl_hw, ipc_env);

	if (status & cl_hw->ipc_e2a_irq.dbg)
		cl_irq_status_dbg(cl_hw, ipc_env);
}

static void cl_irq_handler(struct cl_chip *chip)
{
	/* Interrupt handler */
	u32 status, statuses = 0;
	unsigned long now = jiffies;
	struct cl_irq_stats *irq_stats = &chip->irq_stats;

	while ((status = ipc_xmac_2_host_status_get(chip))) {
		statuses |= status;

		if (status & IPC_IRQ_L2H_ALL)
			cl_irq_status(chip->cl_hw_tcv0, status);

#ifdef CONFIG_DEMO_ENABLED
		if (status & IPC_IRQ_S2H_ALL) {
			ipc_xmac_2_host_ack_set(chip, status & IPC_IRQ_S2H_ALL);
			cl_chip_smac_irq_status(chip, status & IPC_IRQ_S2H_ALL);
		}
#endif
	}

	if (statuses & (IPC_IRQ_L2H_RXDESC))
		irq_stats->last_rx = now;

	if (statuses & (IPC_IRQ_L2H_TXCFM))
		irq_stats->last_tx = now;

	irq_stats->last_isr = now;
	irq_stats->last_isr_statuses = statuses;
}

/* Split the 32 ipc bits between lmac & umac & smac - should be the same division in FW test. */
#define LMAC_IPC_IRQ_BITS_SHIFT 0
#define UMAC_IPC_IRQ_BITS_SHIFT 16
#define SMAC_IPC_IRQ_BITS_SHIFT 22

/*
 * For bits 0-15 => 0xFFFF
 * For bits 16-21 => 0x3F
 * For bits 22-31 => 0x3FF
 */
#define LMAC_IPC_IRQ_BITS_MASK (((0x1 << UMAC_IPC_IRQ_BITS_SHIFT) - 1) >> LMAC_IPC_IRQ_BITS_SHIFT)
#define UMAC_IPC_IRQ_BITS_MASK (((0x1 << SMAC_IPC_IRQ_BITS_SHIFT) - 1) >> UMAC_IPC_IRQ_BITS_SHIFT)
#define SMAC_IPC_IRQ_BITS_MASK ((0xFFFFFFFF) >> SMAC_IPC_IRQ_BITS_SHIFT)

static void cl_irq_handler_test(struct cl_chip *chip)
{
	/* This Interrupt handler is only used for IPC test */
	u32 status = 0, statuses = 0, expected_statuses = 0;
	u32 lmac_status = 0, umac_status = 0, smac_status = 0;
	struct cl_hw *cl_hw_tcv0 = chip->cl_hw_tcv0;
	struct cl_irq_stats *irq_stats = &chip->irq_stats;

	while ((status = ipc_xmac_2_host_status_get(chip))) {
		statuses |= status;
		ipc_xmac_2_host_ack_set(chip, status);
	}

	if (cl_hw_tcv0 && cl_hw_tcv0->fw_active) {
		expected_statuses |= (LMAC_IPC_IRQ_BITS_MASK << LMAC_IPC_IRQ_BITS_SHIFT);
		lmac_status = ((statuses >> LMAC_IPC_IRQ_BITS_SHIFT) & LMAC_IPC_IRQ_BITS_MASK);
	}

	if (chip->smac_active) {
		expected_statuses |= (SMAC_IPC_IRQ_BITS_MASK << SMAC_IPC_IRQ_BITS_SHIFT);
		smac_status = ((statuses >> SMAC_IPC_IRQ_BITS_SHIFT) & SMAC_IPC_IRQ_BITS_MASK);
	}

	if (chip->umac_active) {
		expected_statuses |= (UMAC_IPC_IRQ_BITS_MASK << UMAC_IPC_IRQ_BITS_SHIFT);
		umac_status = ((statuses >> UMAC_IPC_IRQ_BITS_SHIFT) & UMAC_IPC_IRQ_BITS_MASK);
	}

	irq_stats->last_isr_statuses |= statuses;
	irq_stats->count_irq++;

	pr_debug("%s: IPC Status %x. (total=%Xh,count=%u)\n",
		 __func__, statuses, irq_stats->last_isr_statuses, irq_stats->count_irq);

	if (lmac_status) {
		pr_debug("%s: LMAC Triggering - %Xh\n", __func__, lmac_status);
		cl_hw_tcv0->ipc_host2xmac_trigger_set(chip, lmac_status);
	}

	if (umac_status) {
		pr_debug("%s: UMAC Triggering - %Xh\n", __func__, umac_status);
		ipc_host_2_umac_trigger_set(chip, umac_status);
	}

	if (smac_status) {
		pr_debug("%s: SMAC Triggering - %Xh\n", __func__, smac_status);
		ipc_host_2_smac_trigger_set(chip, smac_status);
	}

	if (irq_stats->last_isr_statuses == expected_statuses) {
		irq_stats->ipc_success = 1;
		pr_debug("%s: Host 2 FW IRQ done 0x%x\n", __func__, expected_statuses);
	}
}

static irqreturn_t cl_irq_request_handler(int irq, void *dev_id)
{
	struct cl_chip *chip = (struct cl_chip *)dev_id;

	if (chip->fw_test)
		cl_irq_handler_test(chip);
	else
		cl_irq_handler(chip);

	return IRQ_HANDLED;
}

#ifdef CONFIG_SMP
static void cl_irq_set_affinity(struct cl_chip *chip, struct pci_dev *pci_dev)
{
	s32 irq_smp_affinity = chip->conf->ce_irq_smp_affinity;

	if (irq_smp_affinity != -1) {
		struct irq_data *data = irq_get_irq_data(pci_dev->irq);

		if (data) {
			struct cpumask *mask = kmalloc(sizeof(*mask), GFP_KERNEL);

			if (!mask) {
				pr_debug("Alloc failed!");
				return;
			}

			cpumask_clear(mask);
			cpumask_set_cpu(irq_smp_affinity, mask);

			if (data->chip->irq_set_affinity) {
				data->chip->irq_set_affinity(data, mask, false);
				pr_debug("irq=%d, affinity=%d\n", pci_dev->irq, irq_smp_affinity);
			}

			kfree(mask);
		}
	}
}
#endif

int cl_irq_request(struct cl_chip *chip)
{
	/*
	 * Allocate host irq line.
	 * Enable PCIe device interrupts
	 */
	int ret;
	/* Request exclusive PCI interrupt in firmware test mode */
	unsigned long flags = chip->fw_test ? 0 : IRQF_SHARED;
	struct cl_chip_pci *chip_pci = cl_chip_pci_priv(chip);
	struct pci_dev *pci_dev = chip_pci->pci_dev;

	ret = request_irq(pci_dev->irq, cl_irq_request_handler, flags, "cl", chip);

	if (ret) {
		pr_err("ERROR: could not assign interrupt %d, err=%d\n", pci_dev->irq, ret);
		return ret;
	}

#ifdef CONFIG_SMP
	cl_irq_set_affinity(chip, pci_dev);
#endif

	return ret;
}

void cl_irq_free(struct cl_chip *chip)
{
	struct cl_chip_pci *chip_pci = cl_chip_pci_priv(chip);
	struct pci_dev *pci_dev = chip_pci->pci_dev;

	/* Disable PCI device interrupt and release irq line */
	free_irq(pci_dev->irq, chip);
}

void cl_irq_enable(struct cl_hw *cl_hw, u32 value)
{
	/* Enable IPC interrupts */
	ipc_xmac_2_host_enable_set_set(cl_hw->chip, value);
}

void cl_irq_disable(struct cl_hw *cl_hw, u32 value)
{
	/* Disable IPC interrupts */
	ipc_xmac_2_host_enable_clear_set(cl_hw->chip, value);
}
