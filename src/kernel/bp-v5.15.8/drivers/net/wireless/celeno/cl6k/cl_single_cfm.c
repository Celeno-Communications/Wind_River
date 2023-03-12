// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_single_cfm.h"
#include "cl_tx_queue.h"
#include "cl_tx_inject.h"
#include "chip.h"
#include "cl_sw_txhdr.h"
#include "cl_enhanced_tim.h"
#include "cl_bcmc_cfm.h"
#include "cl_sta.h"
#include "cl_agg_tx_report.h"

/*
 * cl_hw->single_cfm_queues:
 * These queues are used to keep pointers to skb's sent
 * as singles and waiting for confirmation.
 */

#ifdef CE_DUMMY_PHY
#define SINGLE_POLL_TIMEOUT 400
#else
#define SINGLE_POLL_TIMEOUT 10
#endif

#define SINGLE_POLL_TIMEOUT_B2B 700

void cl_single_cfm_init(struct cl_hw *cl_hw)
{
	int i = 0;

	for (i = 0; i < MAX_SINGLE_QUEUES; i++)
		INIT_LIST_HEAD(&cl_hw->single_cfm_queues[i].head);
}

void cl_single_cfm_add(struct cl_hw *cl_hw,
		       struct cl_sw_txhdr *sw_txhdr,
		       u32 queue_idx)
{
	list_add_tail(&sw_txhdr->cfm_list,
		      &cl_hw->single_cfm_queues[queue_idx].head);
}

static struct cl_sw_txhdr *cl_single_cfm_find(struct cl_hw *cl_hw,
					      u32 queue_idx,
					      dma_addr_t dma_addr)
{
	struct cl_single_cfm_queue *cfm_queue = NULL;
	struct cl_sw_txhdr *sw_txhdr = NULL;
	struct cl_sw_txhdr *tmp = NULL;

	if (queue_idx >= MAX_SINGLE_QUEUES)
		return NULL;

	cfm_queue = &cl_hw->single_cfm_queues[queue_idx];

	list_for_each_entry_safe(sw_txhdr, tmp, &cfm_queue->head, cfm_list) {
		u32 packet_addr =
			le32_to_cpu(sw_txhdr->txdesc.umacdesc.sngl_info.packet_addr);
		if (packet_addr == dma_addr) {
			list_del(&sw_txhdr->cfm_list);

			return sw_txhdr;
		}
	}

	return NULL;
}

void cl_single_cfm_handler(struct cl_hw *cl_hw, u32 cfm_status,
			   u32 dma_addr, u32 single_queue_idx)
{
	struct cl_chip *chip = cl_hw->chip;
	struct sk_buff *skb = NULL;
	struct ieee80211_tx_info *tx_info = NULL;
	struct cl_hw_tx_status *status = (struct cl_hw_tx_status *)&cfm_status;
	struct cl_sw_txhdr *sw_txhdr = NULL;
	struct cl_tx_queue *tx_queue = NULL;
	struct cl_sta *cl_sta = NULL;
	u8 hw_queue;
	bool is_bcn;
	unsigned long flags = 0;

	if (status->is_bcmc) {
		if (IS_PCI_BUS_TYPE(chip))
			spin_lock_irqsave(&cl_hw->tx_lock_bcmc, flags);
		else
			spin_lock(&cl_hw->tx_lock_bcmc);
		sw_txhdr = cl_bcmc_cfm_find(cl_hw, dma_addr, status->keep_skb);
		tx_queue = &cl_hw->tx_queues->bcmc;
	} else {
		if (IS_PCI_BUS_TYPE(chip))
			spin_lock_bh(&cl_hw->tx_lock_single);
		else
			spin_lock(&cl_hw->tx_lock_single);
		sw_txhdr = cl_single_cfm_find(cl_hw, single_queue_idx, dma_addr);
		tx_queue = &cl_hw->tx_queues->single[single_queue_idx];
	}

	if (!sw_txhdr) {
		cl_dbg_trace(cl_hw, "Failed to find CFM for single_queue_idx %u status 0x%x\n",
			     single_queue_idx, cfm_status);
		goto out;
	}

	skb = sw_txhdr->skb;
	tx_info = IEEE80211_SKB_CB(skb);
	hw_queue = sw_txhdr->hw_queue;
	is_bcn = sw_txhdr->is_bcn;

	/*
	 * Used for beacon frames only !!
	 * if skb was already confirmed we do not need to inc FwFreeSpace counter
	 */
	if (likely(!status->freespace_inc_skip)) {
		tx_queue->total_fw_cfm++;
		tx_queue->fw_free_space++;

		/* Clear the TIM element if assoicated IPC queue is empty */
		if (!is_bcn && cl_txq_is_fw_empty(tx_queue)) {
			bool no_ps_buffer =
				(tx_info->flags & IEEE80211_TX_CTL_NO_PS_BUFFER) ? true : false;

			cl_sta_lock(cl_hw);
			cl_sta = cl_sta_get(cl_hw, sw_txhdr->sta_idx);
			cl_enhanced_tim_clear_tx_single(cl_hw, single_queue_idx, hw_queue,
							no_ps_buffer, cl_sta, sw_txhdr->tid);
			cl_sta_unlock(cl_hw);
		}
	} else  if (!is_bcn) {
		cl_dbg_verbose(cl_hw, "should no be here - is_bcn=%d hw_queue=%d\n",
			       is_bcn, hw_queue);
	}

	/*
	 * Used for beacon frames only !!
	 * if this flag is set, it means FW still need this beacon skb, therefore
	 * we do not free this skb.
	 */
	if (unlikely(status->keep_skb)) {
		if (!is_bcn)
			cl_dbg_verbose(cl_hw, "should not be here - is_bcn=%d hw_queue=%d\n",
				       is_bcn, hw_queue);
		goto out;
	}

	if (IS_PCI_BUS_TYPE(chip))
		dma_unmap_single(chip->dev, dma_addr, sw_txhdr->map_len, DMA_TO_DEVICE);

	/*
	 * If queue is not empty call cl_txq_sched() to
	 * transfer packets from the queue to firmware
	 */
	if (!list_empty(&tx_queue->hdrs))
		cl_txq_sched(cl_hw, tx_queue);

	/* Cl_tx_inject_cfm() must be called inside the lock */
	if (cl_tx_ctrl_is_inject(tx_info)) {
		cl_sta_lock(cl_hw);
		cl_sta = cl_sta_get(cl_hw, sw_txhdr->sta_idx);
		if (cl_sta)
			cl_agg_tx_report_simulate_for_single(cl_hw, cl_sta, status);
		cl_sta_unlock(cl_hw);

		cl_tx_inject_cfm(cl_hw);
		dev_kfree_skb_any(skb);
		cl_sw_txhdr_free(cl_hw, sw_txhdr);
		goto out;
	}

	if (status->is_bcmc) {
		if (IS_PCI_BUS_TYPE(chip))
			spin_unlock_irqrestore(&cl_hw->tx_lock_bcmc, flags);
		else
			spin_unlock(&cl_hw->tx_lock_bcmc);
	} else {
		if (IS_PCI_BUS_TYPE(chip))
			spin_unlock_bh(&cl_hw->tx_lock_single);
		else
			spin_unlock(&cl_hw->tx_lock_single);
	}

	if (is_bcn) {
		struct ieee80211_vif *vif = sw_txhdr->cl_vif->vif;

		if (vif) {
			if (vif->csa_active &&
			    ieee80211_beacon_cntdwn_is_complete(vif))
				ieee80211_csa_finish(vif);

			if (vif->color_change_active &&
			    ieee80211_beacon_cntdwn_is_complete(vif))
				ieee80211_color_change_finish(vif);
		}

		consume_skb(skb);
		cl_sw_txhdr_free(cl_hw, sw_txhdr);
		return;
	}

	if (status->frm_successful && !(tx_info->flags & IEEE80211_TX_CTL_NO_ACK))
		tx_info->flags |= IEEE80211_TX_STAT_ACK;

	cl_sta_lock(cl_hw);
	cl_sta = cl_sta_get(cl_hw, sw_txhdr->sta_idx);

	if (cl_sta) {
		if (tx_queue->type != QUEUE_TYPE_BCMC &&
		    ieee80211_is_data(sw_txhdr->fc) &&
		    !cl_tx_ctrl_is_eapol(tx_info))
			cl_agg_tx_report_simulate_for_single(cl_hw, cl_sta, status);

		cl_tx_check_start_ba_session(cl_hw, cl_sta->stainfo, skb);
	}

	cl_sta_unlock(cl_hw);

	if (tx_info->ack_frame_id)
		ieee80211_tx_status(cl_hw->hw, skb);
	else
		consume_skb(skb);

	cl_sw_txhdr_free(cl_hw, sw_txhdr);
	return;

out:
	if (status->is_bcmc) {
		if (IS_PCI_BUS_TYPE(chip))
			spin_unlock_irqrestore(&cl_hw->tx_lock_bcmc, flags);
		else
			spin_unlock(&cl_hw->tx_lock_bcmc);
	} else {
		if (IS_PCI_BUS_TYPE(chip))
			spin_unlock_bh(&cl_hw->tx_lock_single);
		else
			spin_unlock(&cl_hw->tx_lock_single);
	}
}

static void cl_single_cfm_flush_queue(struct cl_hw *cl_hw, u32 queue_idx)
{
	struct cl_single_cfm_queue *cfm_queue = &cl_hw->single_cfm_queues[queue_idx];
	struct cl_tx_queue *tx_queue = NULL;
	struct cl_sw_txhdr *sw_txhdr = NULL;
	struct sk_buff *skb = NULL;
	struct ieee80211_tx_info *tx_info = NULL;
	dma_addr_t dma_addr;
	struct cl_chip *chip = cl_hw->chip;

	if (list_empty(&cfm_queue->head))
		return;

	do {
		sw_txhdr = list_first_entry(&cfm_queue->head, struct cl_sw_txhdr, cfm_list);
		skb = sw_txhdr->skb;
		tx_info = IEEE80211_SKB_CB(skb);

		if (IS_PCI_BUS_TYPE(chip)) {
			dma_addr = le32_to_cpu(sw_txhdr->txdesc.umacdesc.sngl_info.packet_addr);
			dma_unmap_single(chip->dev, dma_addr, sw_txhdr->map_len, DMA_TO_DEVICE);
		}

		if (cl_tx_ctrl_is_inject(tx_info))
			cl_tx_inject_cfm(cl_hw);

		cl_tx_single_free_skb(cl_hw, skb);
		list_del(&sw_txhdr->cfm_list);
		cl_sw_txhdr_free(cl_hw, sw_txhdr);
	} while (!list_empty(&cfm_queue->head));

	/*
	 * Set fw_free_space back to maximum after flushing the queue
	 * and clear the enhanced TIM.
	 */
	tx_queue = &cl_hw->tx_queues->single[queue_idx];
	tx_queue->fw_free_space = tx_queue->fw_max_size;
	cl_enhanced_tim_clear_tx_single(cl_hw, queue_idx, tx_queue->hw_index,
					false, tx_queue->cl_sta, tx_queue->tid);
}

void cl_single_cfm_flush_all(struct cl_hw *cl_hw)
{
	u32 i = 0;

	for (i = 0; i < MAX_SINGLE_QUEUES; i++)
		cl_single_cfm_flush_queue(cl_hw, i);
}

static void cl_single_cfm_poll_timeout(struct cl_hw *cl_hw, u32 queue_idx)
{
	/*
	 * When polling failed clear the enhanced TIM so that firmware will
	 * not try to transmit these packets.
	 */
	struct cl_tx_queue *tx_queue = &cl_hw->tx_queues->single[queue_idx];

	cl_dbg_err(cl_hw, "Polling timeout (queue_idx = %u)\n", queue_idx);

	spin_lock_bh(&cl_hw->tx_lock_single);
	cl_enhanced_tim_clear_tx_single(cl_hw, queue_idx, tx_queue->hw_index,
					false, tx_queue->cl_sta, tx_queue->tid);
	spin_unlock_bh(&cl_hw->tx_lock_single);
}

void cl_single_cfm_poll_empty(struct cl_hw *cl_hw, u32 queue_idx)
{
	struct cl_single_cfm_queue *cfm_queue = &cl_hw->single_cfm_queues[queue_idx];
	bool empty = false;
	int i = 0;
	int single_poll_timeout = (cl_hw->chip->conf->ci_phy_dev == PHY_DEV_FRU) ?
				  (SINGLE_POLL_TIMEOUT_B2B) : SINGLE_POLL_TIMEOUT;

	if (test_bit(CL_DEV_FW_ERROR, &cl_hw->drv_flags))
		return;

	while (true) {
		spin_lock_bh(&cl_hw->tx_lock_single);
		empty = list_empty(&cfm_queue->head);
		spin_unlock_bh(&cl_hw->tx_lock_single);

		if (empty)
			return;

		if (++i == single_poll_timeout) {
			cl_single_cfm_poll_timeout(cl_hw, queue_idx);
			return;
		}

		msleep(20);
	}
}

static bool list_hp_empty_sta(struct cl_hw *cl_hw, u8 sta_idx)
{
	struct cl_single_cfm_queue *hp_cfm_queue = &cl_hw->single_cfm_queues[HIGH_PRIORITY_QUEUE];
	struct cl_sw_txhdr *sw_txhdr = NULL;

	list_for_each_entry(sw_txhdr, &hp_cfm_queue->head, cfm_list)
		if (sw_txhdr->sta_idx == sta_idx)
			return false;

	return true;
}

static void cl_single_cfm_poll_empty_hp(struct cl_hw *cl_hw, u8 sta_idx)
{
	bool empty = false;
	int i = 0;

	if (test_bit(CL_DEV_FW_ERROR, &cl_hw->drv_flags))
		return;

	while (true) {
		spin_lock_bh(&cl_hw->tx_lock_single);
		empty = list_hp_empty_sta(cl_hw, sta_idx);
		spin_unlock_bh(&cl_hw->tx_lock_single);

		if (empty)
			return;

		if (++i == SINGLE_POLL_TIMEOUT) {
			cl_single_cfm_poll_timeout(cl_hw, HIGH_PRIORITY_QUEUE);
			return;
		}

		msleep(20);
	}
}

void cl_single_cfm_poll_empty_sta(struct cl_hw *cl_hw, u8 sta_idx)
{
	/*
	 * Poll all single queues belonging to this station, and poll all
	 * packets belonging to this station in the high priority queue.
	 */
	u8 ac;
	u16 queue_idx;

	for (ac = 0; ac < AC_MAX; ac++) {
		queue_idx = QUEUE_IDX(sta_idx, ac);
		cl_single_cfm_poll_empty(cl_hw, queue_idx);
	}

	cl_single_cfm_poll_empty_hp(cl_hw, sta_idx);
}

void cl_single_cfm_clear_tim_bit_sta(struct cl_hw *cl_hw, u8 sta_idx)
{
	u8 ac;
	u16 queue_idx;
	struct cl_tx_queue *tx_queue = NULL;

	for (ac = 0; ac < AC_MAX; ac++) {
		queue_idx = QUEUE_IDX(sta_idx, ac);
		tx_queue = &cl_hw->tx_queues->single[queue_idx];

		spin_lock_bh(&cl_hw->tx_lock_single);
		cl_enhanced_tim_clear_tx_single(cl_hw, queue_idx, tx_queue->hw_index,
						false, tx_queue->cl_sta, tx_queue->tid);
		spin_unlock_bh(&cl_hw->tx_lock_single);
	}

	tx_queue = &cl_hw->tx_queues->single[HIGH_PRIORITY_QUEUE];

	spin_lock_bh(&cl_hw->tx_lock_single);
	cl_enhanced_tim_clear_tx_single(cl_hw, HIGH_PRIORITY_QUEUE, tx_queue->hw_index,
					false, tx_queue->cl_sta, tx_queue->tid);
	spin_unlock_bh(&cl_hw->tx_lock_single);
}
