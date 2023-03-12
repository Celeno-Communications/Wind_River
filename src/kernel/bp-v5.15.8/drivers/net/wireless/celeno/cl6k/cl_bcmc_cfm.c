// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_bcmc_cfm.h"
#include "chip.h"
#include "cl_sw_txhdr.h"

/*
 * cl_hw->bcmc_cfm_queue:
 * This queue is used to keep pointers to already sent
 * beacon skb's that are waiting for confirmation.
 */

static void cl_bcmc_free_sw_txhdr(struct cl_hw *cl_hw,
				  struct cl_sw_txhdr *sw_txhdr)
{
	struct cl_chip *chip = cl_hw->chip;
	dma_addr_t dma_addr;
	struct sk_buff *skb = NULL;

	skb = sw_txhdr->skb;

	if (IS_PCI_BUS_TYPE(chip)) {
		dma_addr = le32_to_cpu(sw_txhdr->txdesc.umacdesc.sngl_info.packet_addr);
		dma_unmap_single(chip->dev, dma_addr, sw_txhdr->map_len, DMA_TO_DEVICE);
	}
	dev_kfree_skb_irq(skb);
	list_del(&sw_txhdr->cfm_list);
	cl_sw_txhdr_free(cl_hw, sw_txhdr);
}

static bool cl_bcmc_is_list_empty_per_vif(struct cl_hw *cl_hw,
					  struct cl_vif *cl_vif)
{
	struct cl_single_cfm_queue *cfm_queue = &cl_hw->bcmc_cfm_queue;
	struct cl_sw_txhdr *sw_txhdr = NULL;

	list_for_each_entry(sw_txhdr, &cfm_queue->head, cfm_list)
		if (sw_txhdr->cl_vif == cl_vif)
			return false;

	return true;
}

void cl_bcmc_cfm_init(struct cl_hw *cl_hw)
{
	INIT_LIST_HEAD(&cl_hw->bcmc_cfm_queue.head);
}

void cl_bcmc_cfm_add(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr)
{
	list_add_tail(&sw_txhdr->cfm_list, &cl_hw->bcmc_cfm_queue.head);
}

struct cl_sw_txhdr *cl_bcmc_cfm_find(struct cl_hw *cl_hw, dma_addr_t dma_addr, bool keep_in_list)
{
	struct cl_single_cfm_queue *cfm_queue = &cl_hw->bcmc_cfm_queue;
	struct cl_sw_txhdr *sw_txhdr = NULL;
	struct cl_sw_txhdr *tmp = NULL;

	list_for_each_entry_safe(sw_txhdr, tmp, &cfm_queue->head, cfm_list) {
		if (le32_to_cpu(sw_txhdr->txdesc.umacdesc.sngl_info.packet_addr) == dma_addr) {
			if (!keep_in_list)
				list_del(&sw_txhdr->cfm_list);

			return sw_txhdr;
		}
	}

	return NULL;
}

void cl_bcmc_cfm_flush_queue(struct cl_hw *cl_hw, struct cl_vif *cl_vif)
{
	struct cl_single_cfm_queue *cfm_queue = &cl_hw->bcmc_cfm_queue;
	struct cl_sw_txhdr *sw_txhdr = NULL;
	struct cl_sw_txhdr *tmp = NULL;

	/* Only flush the specific cl_vif related confirmations */
	if (cl_vif) {
		list_for_each_entry_safe(sw_txhdr, tmp, &cfm_queue->head, cfm_list) {
			if (sw_txhdr->cl_vif == cl_vif) {
				cl_bcmc_free_sw_txhdr(cl_hw, sw_txhdr);
				cl_hw->tx_queues->bcmc.fw_free_space++;
			}
		}

		return;
	}

	while (!list_empty(&cfm_queue->head)) {
		sw_txhdr = list_first_entry(&cfm_queue->head, struct cl_sw_txhdr, cfm_list);
		cl_bcmc_free_sw_txhdr(cl_hw, sw_txhdr);
	}

	/* Set fw_free_space back to maximum after flushing the queue */
	cl_hw->tx_queues->bcmc.fw_free_space = cl_hw->tx_queues->bcmc.fw_max_size;
}

void cl_bcmc_cfm_poll_empty_per_vif(struct cl_hw *cl_hw,
				    struct cl_vif *cl_vif)
{
	unsigned long flags;
	bool empty = false;
	int i = 0;

	if (test_bit(CL_DEV_FW_ERROR, &cl_hw->drv_flags))
		return;

	while (i++ < BCMC_POLL_TIMEOUT) {
		spin_lock_irqsave(&cl_hw->tx_lock_bcmc, flags);
		empty = cl_bcmc_is_list_empty_per_vif(cl_hw, cl_vif);
		spin_unlock_irqrestore(&cl_hw->tx_lock_bcmc, flags);

		if (empty)
			return;

		msleep(20);
	}

	cl_dbg_err(cl_hw, "Polling timeout vif_index %d\n", cl_vif->vif_index);

	spin_lock_irqsave(&cl_hw->tx_lock_bcmc, flags);
	cl_bcmc_cfm_flush_queue(cl_hw, cl_vif);
	spin_unlock_irqrestore(&cl_hw->tx_lock_bcmc, flags);
}

