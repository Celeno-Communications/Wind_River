// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_rx_pci.h"
#include "cl_prof.h"
#include "cl_ipc.h"
#include "cl_rx.h"
#include "cl_ipc_shared.h"
#include "def.h"
#include "cl_irq.h"
#ifdef TRACE_SUPPORT
#include "cl_trace.h"
#endif

static DEFINE_PER_CPU(struct tasklet_struct, rx_remote_tasklet_drv[TCV_TOTAL]);

static void cl_rx_pci_stats_rxm(struct cl_hw *cl_hw, u16 bucket_idx)
{
	if (bucket_idx < IPC_RXBUF_NUM_BUCKETS_RXM)
		cl_hw->rx_info.pkt_handle_bucket_rxm[bucket_idx]++;
	else
		cl_hw->rx_info.pkt_handle_bucket_rxm[IPC_RXBUF_NUM_BUCKETS_RXM - 1]++;
}

static void cl_rx_pci_stats_fw(struct cl_hw *cl_hw, u16 bucket_idx)
{
	if (bucket_idx < IPC_RXBUF_NUM_BUCKETS_FW)
		cl_hw->rx_info.pkt_handle_bucket_fw[bucket_idx]++;
	else
		cl_hw->rx_info.pkt_handle_bucket_fw[IPC_RXBUF_NUM_BUCKETS_FW - 1]++;
}

static void cl_rx_pci_stats(struct cl_hw *cl_hw, u16 pkt_cnt, enum rx_buf_type type)
{
	/* Collect stats - fill the bucket stats */
	if (pkt_cnt) {
		u16 bucket_idx = pkt_cnt >> IPC_RXBUF_BUCKET_POW_SIZE;

		if (type == CL_RX_BUF_RXM)
			cl_rx_pci_stats_rxm(cl_hw, bucket_idx);
		else
			cl_rx_pci_stats_fw(cl_hw, bucket_idx);
	}
}

static int _cl_rx_pci_start(struct cl_hw *cl_hw, u32 rxdesc_read_idx, u32 host_read_idx,
			    enum rx_buf_type type)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_ipc_host_rxbuf *rx_hostbuf = &ipc_env->rx_hostbuf_array[type];
	struct cl_rx_elem *rxelem =
		(struct cl_rx_elem *)rx_hostbuf->ipc_host_rxdesc_ptr[host_read_idx];
	struct sk_buff *skb;
	int ret = 0;
	dma_addr_t dma_addr;
	u32 size = cl_hw->conf->ci_ipc_rxbuf_size[type];

	/* For profiling - capture time to handle single rxdesc */
	PROF_REG_SW_SET(cl_hw, SW_PROF_RX_DATA_IND);

	cl_hw->rx_info.rx_desc[type]++;

	/* Copy the current skb buffer & dma_addr. */
	skb = rxelem->skb;
	dma_addr = rxelem->dma_addr;

	/* Try to populate the rxelem with new skb */
	if (cl_ipc_rx_elem_alloc(cl_hw, rxelem, size)) {
		cl_hw->rx_info.elem_alloc_fail++;
		/* Restore skb and dma_addr value */
		rxelem->skb = skb;
		rxelem->dma_addr = dma_addr;
		ret = -ENOMEM;
		goto handle_done;
	}

	/* Release dma virtual memory early */
	dma_unmap_single(cl_hw->chip->dev, dma_addr, size, DMA_FROM_DEVICE);

	if (!skb) {
		cl_hw->rx_info.skb_null++;
		cl_rx_skb_error(cl_hw);
		cl_dbg_verbose(cl_hw, "skb is NULL\n");
		goto handle_done;
	}

	cl_ipc_rxbuf_push(ipc_env, rxelem, rxdesc_read_idx, host_read_idx, type);

	cl_rx_push_queue(cl_hw, skb);

handle_done:
	PROF_REG_SW_CLR(cl_hw, SW_PROF_RX_DATA_IND);

	return ret;
}

static void cl_rx_pci_start(struct cl_hw *cl_hw, enum rx_buf_type type,
			    u16 rx_buf_cnt)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_ipc_ring_indices *indices = ipc_env->ring_indices_elem->indices;
	u16 buf_cnt_mask = rx_buf_cnt - 1;
	u16 pkt_cnt = 0;
	u32 rxdesc_read_idx = le32_to_cpu(indices->rxdesc_read_idx[type]);
	u32 host_read_idx = 0;
	u32 rxdesc_write_idx = le32_to_cpu(indices->rxdesc_write_idx[type]);
	u32 host_write_idx = 0;

	/*
	 * Firmware has triggered an interrupt saying that a reception has occurred.
	 * Iterate over all valid rxdesc pushed by embedded.
	 * The read index is incremented once the callback function finishes meaning
	 * a new allocated skb pushed the rxbuff.
	 * The write index is incremented in direct write by the embedded layer,
	 * indicating that allocated skb was populated with packet data.
	 */

	do {
		host_write_idx = rxdesc_write_idx;

		while (ipc_env->host_rxdesc_read_idx[type] != host_write_idx) {
			host_read_idx = rxdesc_read_idx & buf_cnt_mask;

			if (_cl_rx_pci_start(cl_hw, rxdesc_read_idx, host_read_idx, type) == 0) {
				/* Local application follower of embedded read idx */
				ipc_env->host_rxdesc_read_idx[type]++;
				rxdesc_read_idx++;
				pkt_cnt++;
			} else {
				/*
				 * Replacing old skb with new allocated skb failed
				 * (should not happen). Postpone the handle of the
				 * old skb until this function is reschduled again.
				 */
				if (!test_bit(CL_DEV_STOP_HW, &cl_hw->drv_flags))
					tasklet_schedule(&ipc_env->rxdesc_tasklet);
				goto out;
			}
		}

		/* Check if firmware pushed new descriptors */
		rxdesc_write_idx = le32_to_cpu(indices->rxdesc_write_idx[type]);
	} while (host_write_idx != rxdesc_write_idx);

out:
	cl_rx_pci_stats(cl_hw, pkt_cnt, type);
}

static void cl_rx_pci_remote_tasklet_handler(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;

	cl_rx_remote_cpu_info(cl_hw);
	cl_rx_pci_desc_handler(cl_hw);
}

static void cl_rx_pci_remote_cpu_sched(struct cl_hw *cl_hw)
{
	int cpu = cl_hw->conf->ci_rx_remote_cpu_drv;
	struct tasklet_struct *t = &per_cpu(rx_remote_tasklet_drv[cl_hw->idx], cpu);

	if (!test_bit(TASKLET_STATE_SCHED, &t->state))
		smp_call_function_single(cpu, cl_rx_remote_tasklet_sched, t, 0);
}

void cl_rx_pci_init(struct cl_hw *cl_hw)
{
	s8 cpu = cl_hw->conf->ci_rx_remote_cpu_drv;

	if (cpu >= 0)
		tasklet_init(&per_cpu(rx_remote_tasklet_drv[cl_hw->idx], cpu),
			     cl_rx_pci_remote_tasklet_handler,
			     (unsigned long)cl_hw);
}

void cl_rx_pci_deinit(struct cl_hw *cl_hw)
{
	s8 cpu = cl_hw->conf->ci_rx_remote_cpu_drv;

	if (cpu >= 0)
		tasklet_kill(&per_cpu(rx_remote_tasklet_drv[cl_hw->idx], cpu));
}

void cl_rx_pci_desc_handler(struct cl_hw *cl_hw)
{
#ifdef TRACE_SUPPORT
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;

	trace_cl_trace_rx_desc_tasklet_start(cl_hw->idx,
					     ipc_env->host_rxdesc_read_idx[CL_RX_BUF_RXM],
					     ipc_env->host_rxdesc_read_idx[CL_RX_BUF_FW]);
#endif

	/* Handle all RXM rx elements */
	cl_rx_pci_start(cl_hw, CL_RX_BUF_RXM, IPC_RXBUF_CNT_RXM);
	/* Handle all FW rx elements */
	cl_rx_pci_start(cl_hw, CL_RX_BUF_FW, IPC_RXBUF_CNT_FW);

	/* Initiate interrupt to embbeded when all rx elements were handled */
	if (!test_bit(CL_DEV_HW_RESTART, &cl_hw->drv_flags))
		cl_hw->ipc_host2xmac_trigger_set(cl_hw->chip, IPC_IRQ_A2E_RXBUF_BACK);

	/*
	 * Finished handle all valid rx elements, restore the RX interrupt
	 * to enable handling new populated rx elements
	 */
	if (!test_bit(CL_DEV_STOP_HW, &cl_hw->drv_flags))
		cl_irq_enable(cl_hw, cl_hw->ipc_e2a_irq.rxdesc);

#ifdef TRACE_SUPPORT
	trace_cl_trace_rx_desc_tasklet_end(cl_hw->idx,
					   ipc_env->host_rxdesc_read_idx[CL_RX_BUF_RXM],
					   ipc_env->host_rxdesc_read_idx[CL_RX_BUF_FW]);
#endif
}

void cl_rx_pci_desc_tasklet(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;

	if (cl_hw->conf->ci_rx_remote_cpu_drv == -1)
		cl_rx_pci_desc_handler(cl_hw);
	else
		cl_rx_pci_remote_cpu_sched(cl_hw);
}

