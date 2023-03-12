// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_agg_cfm.h"
#include "cl_sta.h"
#include "cl_enhanced_tim.h"
#include "cl_sw_txhdr.h"
#include "chip.h"
#include "cl_tx_inject.h"
#include "cl_tx_amsdu.h"
#ifdef TRACE_SUPPORT
#include "cl_trace.h"
#endif

#ifdef CE_DUMMY_PHY
#define AGG_POLL_TIMEOUT 400
#else
#define AGG_POLL_TIMEOUT 10
#endif

#define AGG_POLL_TIMEOUT_B2B 700

/*
 * cl_hw->agg_cfm_queues:
 * These queues are used to keep pointers to skb's sent
 * as aggregation and waiting for confirmation.
 */

void cl_agg_cfm_init(struct cl_hw *cl_hw)
{
	int i = 0;

	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++)
		INIT_LIST_HEAD(&cl_hw->agg_cfm_queues[i].head);
}

void cl_agg_cfm_add(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr, u8 agg_idx)
{
	spin_lock(&cl_hw->tx_lock_cfm_agg);
	list_add_tail(&sw_txhdr->cfm_list, &cl_hw->agg_cfm_queues[agg_idx].head);
	spin_unlock(&cl_hw->tx_lock_cfm_agg);
}

static void cl_agg_cfm_amsdu_free(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_amsdu_txhdr *amsdu_txhdr = NULL;
	struct cl_amsdu_txhdr *tmp = NULL;
	struct sk_buff *sub_skb = NULL;
	struct ieee80211_tx_info *tx_info_sub_skb = NULL;

	list_for_each_entry_safe(amsdu_txhdr, tmp, &sw_txhdr->amsdu_txhdr.list, list) {
		sub_skb = amsdu_txhdr->skb;
		tx_info_sub_skb = IEEE80211_SKB_CB(sub_skb);

		if (cl_tx_ctrl_is_inject(tx_info_sub_skb))
			cl_tx_inject_cfm(cl_hw);

		list_del(&amsdu_txhdr->list);
		if (IS_PCI_BUS_TYPE(chip))
			dma_unmap_single(chip->dev, amsdu_txhdr->dma_addr,
					 (size_t)sub_skb->len, DMA_TO_DEVICE);
		kfree_skb(sub_skb);
		cl_tx_amsdu_txhdr_free(cl_hw, amsdu_txhdr);
	}
}

static void cl_agg_cfm_free_head_skb(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr)
{
	struct cl_chip *chip = cl_hw->chip;
	struct sk_buff *skb = sw_txhdr->skb;
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
	dma_addr_t dma_addr;

	if (IS_PCI_BUS_TYPE(chip)) {
		dma_addr = le32_to_cpu(sw_txhdr->txdesc.umacdesc.agg_info.packet_addr[0]);
		dma_unmap_single(chip->dev, dma_addr, sw_txhdr->map_len, DMA_TO_DEVICE);
	}
	/* If amsdu list not empty free sub MSDU frames first, including amsdu_txhdr */
	if (cl_tx_ctrl_is_amsdu(tx_info))
		if (!list_empty(&sw_txhdr->amsdu_txhdr.list))
			cl_agg_cfm_amsdu_free(cl_hw, sw_txhdr);

	if (cl_tx_ctrl_is_inject(tx_info))
		cl_tx_inject_cfm(cl_hw);

	consume_skb(skb);
	list_del(&sw_txhdr->cfm_list);
	cl_sw_txhdr_free(cl_hw, sw_txhdr);
}

int cl_agg_cfm_handle(struct cl_hw *cl_hw, u16 new_ssn, u8 ba_queue_idx)
{
	struct cl_agg_cfm_queue *cfm_queue = &cl_hw->agg_cfm_queues[ba_queue_idx];
	u16 prev_ssn = cfm_queue->ssn;
	int free_space_add = 0;
	struct list_head cfm_head;
	struct cl_sw_txhdr *sw_txhdr;

	INIT_LIST_HEAD(&cfm_head);

	/*
	 * protect list with locks. use internal list for skb_release.
	 * this way we reduce lock duration.
	 * Continue to free skb's until:
	 * 1. list is empty.
	 * 2. agg ssn is equal to new ssn received from ssn.
	 */
	spin_lock(&cl_hw->tx_lock_cfm_agg);
	while (!list_empty(&cfm_queue->head) && (cfm_queue->ssn != new_ssn)) {
		sw_txhdr = list_first_entry(&cfm_queue->head, struct cl_sw_txhdr,
					    cfm_list);
		/* move to local queue */
		list_move_tail(&sw_txhdr->cfm_list, &cfm_head);
		cfm_queue->ssn = ((cfm_queue->ssn + 1) & 0xFFF);
	}

	/* Sanity check. test if all skb's marked to be free. */
	if (unlikely(cfm_queue->ssn != new_ssn))
		cl_dbg_err(cl_hw, "ssn diff - queue idx=%u, new ssn=%u, prev ssn=%u, cfm ssn=%u\n",
			   ba_queue_idx, new_ssn, prev_ssn, cfm_queue->ssn);

	spin_unlock(&cl_hw->tx_lock_cfm_agg);

	while (!list_empty(&cfm_head)) {
		sw_txhdr = list_first_entry(&cfm_head, struct cl_sw_txhdr,
					    cfm_list);

		cl_agg_cfm_free_head_skb(cl_hw, sw_txhdr);
		free_space_add++;
	}

	/* The FW used all session packets handled to him by our driver.
	 * lets indicate the FW.
	 * the indication is done by unsetting the session BITMAP
	 * only if this tasklet released frame we should update the TIM element,
	 * we should avoid redundant TIM update operation
	 */
	if (free_space_add > 0) {
		struct cl_tx_queue *tx_queue = cfm_queue->tx_queue;

		if (tx_queue) {
			spin_lock(&cl_hw->tx_lock_agg);
			tx_queue->fw_free_space += free_space_add;
			tx_queue->total_fw_cfm += free_space_add;

			if (cl_txq_is_fw_empty(tx_queue))
				cl_enhanced_tim_clear_tx_agg(cl_hw,
							     ba_queue_idx,
							     tx_queue->hw_index,
							     tx_queue->cl_sta,
							     tx_queue->tid);

			cl_txq_sched(cl_hw, tx_queue);
			spin_unlock(&cl_hw->tx_lock_agg);
		}
	}

	/* Sanity check. test if all skb's marked to be free. */
	if (unlikely(cfm_queue->ssn != new_ssn))
		cl_dbg_err(cl_hw,
			   "ssn diff - queue idx=%u, new ssn=%u, prev ssn=%u, cfm ssn=%u\n",
			   ba_queue_idx, new_ssn, prev_ssn, cfm_queue->ssn);

	return free_space_add;
}

static void cl_agg_cfm_flush_queue(struct cl_hw *cl_hw, u8 agg_idx)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_agg_cfm_queue *cfm_queue = &cl_hw->agg_cfm_queues[agg_idx];
	struct cl_tx_queue *tx_queue = cfm_queue->tx_queue;
	struct sk_buff *skb = NULL;
	struct cl_sw_txhdr *sw_txhdr = NULL;
	dma_addr_t dma_addr = 0;
	struct ieee80211_tx_info *tx_info;

	if (!tx_queue)
		return;

	if (list_empty(&cfm_queue->head))
		return;

	do {
		sw_txhdr = list_first_entry(&cfm_queue->head, struct cl_sw_txhdr, cfm_list);
		skb = sw_txhdr->skb;

		if (IS_PCI_BUS_TYPE(chip)) {
			dma_addr = le32_to_cpu(sw_txhdr->txdesc.umacdesc.agg_info.packet_addr[0]);
			dma_unmap_single(chip->dev, dma_addr, sw_txhdr->map_len, DMA_TO_DEVICE);
		}
		tx_info = IEEE80211_SKB_CB(skb);

		/* If amsdu list not empty free sub MSDU frames first, including amsdu_txhdr */
		if (cl_tx_ctrl_is_amsdu(tx_info))
			if (!list_empty(&sw_txhdr->amsdu_txhdr.list))
				cl_agg_cfm_amsdu_free(cl_hw, sw_txhdr);

		tx_queue->total_fw_cfm++;

		if (cl_tx_ctrl_is_inject(tx_info))
			cl_tx_inject_cfm(cl_hw);

		kfree_skb(skb);
		list_del(&sw_txhdr->cfm_list);
		cl_sw_txhdr_free(cl_hw, sw_txhdr);
	} while (!list_empty(&cfm_queue->head));

	/*
	 * Set fw_free_space back to maximum after flushing the queue
	 * and clear the enhanced TIM.
	 */
	tx_queue->fw_free_space = tx_queue->fw_max_size;
	cl_enhanced_tim_clear_tx_agg(cl_hw, agg_idx, tx_queue->hw_index,
				     tx_queue->cl_sta, tx_queue->tid);

	cfm_queue->tx_queue = NULL;
}

void cl_agg_cfm_flush_all(struct cl_hw *cl_hw)
{
	int i = 0;

	/* Don't use BH lock, because cl_agg_cfm_flush_all() is called with BH disabled */
	spin_lock(&cl_hw->tx_lock_cfm_agg);

	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++)
		cl_agg_cfm_flush_queue(cl_hw, i);

	spin_unlock(&cl_hw->tx_lock_cfm_agg);
}

static void cl_agg_cfm_poll_timeout(struct cl_hw *cl_hw, struct cl_tx_queue *tx_queue,
				    u8 agg_idx, bool flush)
{
	/*
	 * When polling failed clear the enhanced TIM so that firmware will
	 * not try to transmit these packets.
	 * If flush is set cl_enhanced_tim_clear_tx_agg() is called inside
	 * cl_agg_cfm_flush_queue().
	 */
	cl_dbg_err(cl_hw, "Polling timeout (queue_idx = %u)\n", agg_idx);

	spin_lock_bh(&cl_hw->tx_lock_cfm_agg);

	if (flush)
		cl_agg_cfm_flush_queue(cl_hw, agg_idx);
	else
		cl_enhanced_tim_clear_tx_agg(cl_hw, agg_idx, tx_queue->hw_index,
					     tx_queue->cl_sta, tx_queue->tid);

	spin_unlock_bh(&cl_hw->tx_lock_cfm_agg);
}

void cl_agg_cfm_poll_empty(struct cl_hw *cl_hw, u8 agg_idx, bool flush)
{
	struct cl_agg_cfm_queue *cfm_queue = &cl_hw->agg_cfm_queues[agg_idx];
	bool empty = false;
	int i = 0;
	int agg_poll_timeout = (cl_hw->chip->conf->ci_phy_dev == PHY_DEV_FRU) ?
			       (AGG_POLL_TIMEOUT_B2B) : AGG_POLL_TIMEOUT;

	if (test_bit(CL_DEV_FW_ERROR, &cl_hw->drv_flags))
		return;

	while (true) {
		spin_lock_bh(&cl_hw->tx_lock_cfm_agg);
		empty = list_empty(&cfm_queue->head);
		spin_unlock_bh(&cl_hw->tx_lock_cfm_agg);

		if (empty)
			return;

		if (++i == agg_poll_timeout) {
			cl_agg_cfm_poll_timeout(cl_hw, cfm_queue->tx_queue, agg_idx, flush);
			return;
		}

		msleep(20);
	}
}

void cl_agg_cfm_poll_empty_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	int i = 0;
	struct cl_tx_queue *tx_queue = NULL;

	for (i = 0; i < IEEE80211_NUM_TIDS; i++) {
		tx_queue = cl_sta->agg_tx_queues[i];

		if (tx_queue)
			cl_agg_cfm_poll_empty(cl_hw, tx_queue->index, false);
	}
}

void cl_agg_cfm_clear_tim_bit_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	int i = 0;
	struct cl_tx_queue *tx_queue = NULL;

	for (i = 0; i < IEEE80211_NUM_TIDS; i++) {
		tx_queue = cl_sta->agg_tx_queues[i];

		if (tx_queue) {
			spin_lock_bh(&cl_hw->tx_lock_agg);
			cl_enhanced_tim_clear_tx_agg(cl_hw, tx_queue->index, tx_queue->hw_index,
						     tx_queue->cl_sta, tx_queue->tid);
			spin_unlock_bh(&cl_hw->tx_lock_agg);
		}
	}
}

void cl_agg_cfm_set_ssn(struct cl_hw *cl_hw, u16 ssn, u8 idx)
{
	spin_lock_bh(&cl_hw->tx_lock_cfm_agg);
	cl_hw->agg_cfm_queues[idx].ssn = ssn;
	spin_unlock_bh(&cl_hw->tx_lock_cfm_agg);
}

void cl_agg_cfm_set_tx_queue(struct cl_hw *cl_hw, struct cl_tx_queue *tx_queue, u8 idx)
{
	spin_lock_bh(&cl_hw->tx_lock_cfm_agg);
	cl_hw->agg_cfm_queues[idx].tx_queue = tx_queue;
	spin_unlock_bh(&cl_hw->tx_lock_cfm_agg);
}
