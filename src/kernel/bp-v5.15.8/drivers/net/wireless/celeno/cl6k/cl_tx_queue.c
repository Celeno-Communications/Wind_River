// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <net/cfg80211.h>
#include <net/mac80211.h>
#include <linux/ieee80211.h>
#include <linux/types.h>

#include "cl_tx_queue.h"
#include "cl_tx.h"
#include "cl_sw_txhdr.h"
#include "cl_tx_amsdu.h"
#include "cl_baw.h"
#include "cl_agg_cfm.h"
#include "chip.h"

static const u8 cl_tid2hwq[IEEE80211_NUM_TIDS] = {
	CL_HWQ_BE,
	CL_HWQ_BK,
	CL_HWQ_BK,
	CL_HWQ_BE,
	CL_HWQ_VI,
	CL_HWQ_VI,
	CL_HWQ_VO,
	CL_HWQ_VO,
	/* At the moment, all others TID are mapped to BE */
	CL_HWQ_BE,
	CL_HWQ_BE,
	CL_HWQ_BE,
	CL_HWQ_BE,
	CL_HWQ_BE,
	CL_HWQ_BE,
	CL_HWQ_BE,
	CL_HWQ_BE,
};

static u32 cl_txq_total_dump_drv(struct cl_tx_queue *tx_queue)
{
	return tx_queue->dump_queue_full + tx_queue->dump_dma_map_fail;
}

static void cl_txq_sched_list_add(struct cl_tx_queue *tx_queue, struct cl_hw *cl_hw)
{
	/* Add to schedule queue */
	if (tx_queue->sched)
		return;

	tx_queue->sched = true;
	if (tx_queue->type == QUEUE_TYPE_AGG)
		list_add_tail(&tx_queue->sched_list, &cl_hw->list_sched_q_agg);
	else
		list_add_tail(&tx_queue->sched_list, &cl_hw->list_sched_q_single);
}

static void cl_txq_sched_list_remove(struct cl_tx_queue *tx_queue)
{
	/* Remove from schedule queue */
	if (tx_queue->sched) {
		tx_queue->sched = false;
		list_del(&tx_queue->sched_list);
	}
}

static void cl_txq_sched_list_remove_if_empty(struct cl_tx_queue *tx_queue)
{
	/* If queue is empty remove it from schedule list */
	if (list_empty(&tx_queue->hdrs))
		cl_txq_sched_list_remove(tx_queue);
}

static void cl_txq_transfer_single_to_agg(struct cl_hw *cl_hw,
					  struct cl_tx_queue *single_queue,
					  struct cl_tx_queue *agg_queue, u8 tid)
{
	struct cl_sw_txhdr *sw_txhdr, *sw_txhdr_tmp;
	struct ieee80211_tx_info *tx_info;
	struct sk_buff *skb;
	u8 hdr_pads;

	spin_lock_bh(&cl_hw->tx_lock_single);

	if (single_queue->num_packets == 0)
		goto out;

	list_for_each_entry_safe(sw_txhdr, sw_txhdr_tmp, &single_queue->hdrs, tx_queue_list) {
		if (sw_txhdr->tid != tid)
			continue;

		if (!ieee80211_is_data_qos(sw_txhdr->fc))
			continue;

		cl_hw->tx_packet_cntr.transfer.single_to_agg++;

		/* Remove from single queue */
		list_del(&sw_txhdr->tx_queue_list);

		/* Update single queue counters */
		single_queue->num_packets--;
		single_queue->total_packets--;

		/* Turn on AMPDU flag */
		skb = sw_txhdr->skb;
		tx_info = IEEE80211_SKB_CB(skb);
		tx_info->flags |= IEEE80211_TX_CTL_AMPDU;

		/* Convert header back and Push skb to agg queue */
		cl_tx_wlan_to_8023(skb);
		hdr_pads = CL_SKB_DATA_ALIGN_PADS(skb->data);
		cl_tx_agg_prep(cl_hw, sw_txhdr, skb->len, hdr_pads, true);
		agg_queue->total_packets++;
		sw_txhdr->hdr80211 = NULL;
		sw_txhdr->tx_queue = agg_queue;
		sw_txhdr->hw_queue = agg_queue->hw_index;

		cl_txq_push(cl_hw, sw_txhdr);
		/* Schedule tasklet to try and empty the queue */
		tasklet_schedule(&cl_hw->tx_task);
	}

	/* If single queue is empty remove it from schedule list */
	cl_txq_sched_list_remove_if_empty(single_queue);

out:
	spin_unlock_bh(&cl_hw->tx_lock_single);
}

static void cl_txq_delete_packets(struct cl_hw *cl_hw, struct cl_tx_queue *tx_queue, u8 sta_idx)
{
	struct cl_sw_txhdr *sw_txhdr, *sw_txhdr_tmp;

	list_for_each_entry_safe(sw_txhdr, sw_txhdr_tmp, &tx_queue->hdrs, tx_queue_list) {
		/*
		 * Brodcast frames do not have cl_sta and should not be
		 * deleted at station remove sequence.
		 */
		if (!sw_txhdr->cl_sta)
			continue;

		if (sw_txhdr->sta_idx != sta_idx)
			continue;

		list_del(&sw_txhdr->tx_queue_list);
		tx_queue->num_packets--;

		cl_tx_single_free_skb(cl_hw, sw_txhdr->skb);
		cl_sw_txhdr_free(cl_hw, sw_txhdr);
	}

	/* If queue is empty remove it from schedule list */
	cl_txq_sched_list_remove_if_empty(tx_queue);
}

static void cl_txq_reset_counters(struct cl_tx_queue *tx_queue)
{
	tx_queue->total_fw_push_desc = 0;
	tx_queue->total_fw_push_skb = 0;
	tx_queue->total_fw_cfm = 0;
	tx_queue->total_packets = 0;
	tx_queue->dump_queue_full = 0;
	tx_queue->dump_dma_map_fail = 0;

	memset(tx_queue->stats_hw_amsdu_cnt, 0,
	       sizeof(tx_queue->stats_hw_amsdu_cnt));

	memset(tx_queue->stats_sw_amsdu_cnt, 0,
	       sizeof(tx_queue->stats_sw_amsdu_cnt));
}

static void cl_txq_reset_counters_during_traffic(struct cl_tx_queue *tx_queue)
{
	/*
	 * This function can be called during traffic, while descriptors
	 * are waiting in firmware. We set total_fw_cfm to minus the number
	 * of descriptors in firmware so that after confirmation arrives
	 * total_fw_cfm will be equal to total_fw_push_desc.
	 */
	u32 desc_in_fw = cl_txq_desc_in_fw(tx_queue);

	cl_txq_reset_counters(tx_queue);
	tx_queue->total_fw_cfm = -desc_in_fw;
}

static void cl_txq_flush(struct cl_hw *cl_hw, struct cl_tx_queue *tx_queue)
{
	struct cl_sw_txhdr *sw_txhdr, *sw_txhdr_tmp;
	struct ieee80211_tx_info *tx_info;

	if (tx_queue->num_packets == 0)
		return;

	list_for_each_entry_safe(sw_txhdr, sw_txhdr_tmp, &tx_queue->hdrs, tx_queue_list) {
		list_del(&sw_txhdr->tx_queue_list);
		tx_queue->num_packets--;

		/* Can not send AMSDU frames as singles */
		tx_info = IEEE80211_SKB_CB(sw_txhdr->skb);

		/* Free mid & last AMSDU sub frames */
		if (cl_tx_ctrl_is_amsdu(tx_info)) {
			cl_tx_amsdu_flush_sub_frames(cl_hw, sw_txhdr);
		} else {
			if (tx_queue->type == QUEUE_TYPE_SINGLE)
				cl_tx_single_free_skb(cl_hw, sw_txhdr->skb);
			else
				kfree_skb(sw_txhdr->skb);

			cl_hw->tx_packet_cntr.drop.queue_flush++;
			sw_txhdr->cl_vif->trfc_cntrs[sw_txhdr->ac].tx_dropped++;
			cl_sw_txhdr_free(cl_hw, sw_txhdr);
		}
	}

	/* Remove from schedule queue */
	cl_txq_sched_list_remove(tx_queue);

	/* Sanity check that queue is empty */
	WARN_ON(tx_queue->num_packets > 0);
}

static void cl_txq_agg_size_set(struct cl_hw *cl_hw)
{
	struct cl_tx_queue *tx_queue = NULL;
	u16 new_size = 0;
	u16 drv_max_size = 0;
	int i = 0;
	int j = 0;

	if (!cl_hw->used_agg_queues || !cl_hw->conf->ci_tx_packet_limit)
		return;

	new_size = cl_hw->conf->ci_tx_packet_limit / cl_hw->used_agg_queues;
	drv_max_size = max(new_size, cl_hw->conf->ci_tx_queue_size_agg);

	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++) {
		tx_queue = &cl_hw->tx_queues->agg[i];

		if (!tx_queue->cl_sta)
			continue;

		tx_queue->max_packets = drv_max_size;

		j++;
		if (j == cl_hw->used_agg_queues)
			break;
	}

	cl_dbg_trace(cl_hw, "drv_max_size = %u\n", drv_max_size);
}

static int cl_txq_request_find(struct cl_hw *cl_hw, u8 sta_idx, u8 tid)
{
	int i = 0;
	struct cl_req_agg_db *req_agg_db = NULL;
	u8 req_agg_queues = 0;

	for (i = 0; (i < IPC_MAX_BA_SESSIONS) && (req_agg_queues < cl_hw->req_agg_queues); i++) {
		req_agg_db = &cl_hw->req_agg_db[i];

		if (!req_agg_db->is_used)
			continue;

		req_agg_queues++;

		if (sta_idx == req_agg_db->sta_idx && tid == req_agg_db->tid)
			return i;
	}

	return -1;
}

static void cl_txq_traffic_counters_print_bcmc(struct cl_hw *cl_hw,
					       char **buf, int *len, ssize_t *buf_size)
{
	struct cl_tx_queue *tx_queue = &cl_hw->tx_queues->bcmc;
	unsigned long flags;
	u8 hw_index;
	u32 total_packets;
	u16 fw_curr;
	u32 total_push;
	u32 total_cfm;
	u32 dump;

	spin_lock_irqsave(&cl_hw->tx_lock_bcmc, flags);

	hw_index = tx_queue->hw_index;
	total_packets = tx_queue->total_packets;
	fw_curr = cl_txq_desc_in_fw(tx_queue);
	total_push = tx_queue->total_fw_push_skb;
	total_cfm = tx_queue->total_fw_cfm;
	dump = cl_txq_total_dump_drv(tx_queue);

	spin_unlock_irqrestore(&cl_hw->tx_lock_bcmc, flags);

	if (total_packets == 0)
		return;

	cl_snprintf(buf, len, buf_size,
		    "\nTX MULTICAST AND BOROADCAST QUEUE (MAX 1):\n"
		    "|-----------------------------------------------------------|\n"
		    "| hw  | driver   | fw      | fw total | fw total | dump     |\n"
		    "| idx | total    | current | push     | cfm      |          |\n"
		    "|-----+----------+---------+----------+----------+----------|\n"
		    "| %3u |%10u|%9u|%10u|%10u|%10u|\n",
		    hw_index, total_packets, fw_curr, total_push, total_cfm, dump);
	cl_snprintf(buf, len, buf_size,
		    "|-----------------------------------------------------------|\n");
}

static void cl_txq_traffic_counters_print_single(struct cl_hw *cl_hw,
						 char **buf, int *len, ssize_t *buf_size)
{
	u16 queue_idx = 0;
	u32 sta_idx = 0, ac = 0;
	struct cl_tx_queue *tx_queue;

	cl_snprintf(buf, len, buf_size,
		    "\nTX SINGLE QUEUES (MAX %d):\n", MAX_SINGLE_QUEUES);
	cl_snprintf(buf, len, buf_size,
		    "|----------------------------------------------------------------------"
		    "----------|\n"
		    "| idx | sta | ac | driver   | driver  | fw      | fw total | fw total |"
		    " dump     |\n"
		    "|     |     |    | total    | current | current | push     | cfm      |"
		    "          |\n"
		    "|-----+-----+----+----------+---------+---------+----------+----------+"
		    "----------|\n");

	spin_lock_bh(&cl_hw->tx_lock_single);

	for (sta_idx = 0; sta_idx < FW_MAX_NUM_STA; sta_idx++) {
		for (ac = 0; ac < AC_MAX; ac++) {
			queue_idx = QUEUE_IDX(sta_idx, ac);
			tx_queue = &cl_hw->tx_queues->single[queue_idx];

			if (tx_queue->total_packets == 0)
				continue;

			if (tx_queue->index == HIGH_PRIORITY_QUEUE)
				cl_snprintf(buf, len, buf_size,
					    "|-----+-----+----+----------+---------+---------+"
					    "----------+----------+----------|\n");

			cl_snprintf(buf, len, buf_size,
				    "| %3u | %3u | %2u |%10u|%9u|%9u|%10u|%10u|%10u|\n",
				    tx_queue->index,
				    sta_idx,
				    tx_queue->hw_index,
				    tx_queue->total_packets,
				    tx_queue->num_packets,
				    cl_txq_desc_in_fw(tx_queue),
				    tx_queue->total_fw_push_skb,
				    tx_queue->total_fw_cfm,
				    cl_txq_total_dump_drv(tx_queue));
		}
	}

	cl_snprintf(buf, len, buf_size,
		    "|------------------------------------------------------------------------"
		    "--------|\n");

	spin_unlock_bh(&cl_hw->tx_lock_single);
}

static void cl_txq_traffic_counters_print_agg(struct cl_hw *cl_hw,
					      char **buf, int *len, ssize_t *buf_size)
{
	u32 ba_idx = 0;
	struct cl_tx_queue *tx_queue;

	spin_lock_bh(&cl_hw->tx_lock_agg);

	if (cl_hw->used_agg_queues == 0)
		goto out;

	cl_snprintf(buf, len, buf_size,
		    "\nTX AGGREGATION QUEUES (MAX %d):\n", IPC_MAX_BA_SESSIONS);
	cl_snprintf(buf, len, buf_size,
		    "|-----------------------------------------------------------------------"
		    "---------------------|\n"
		    "| idx | sta | tid | driver   | driver  | fw      | fw total | fw total |"
		    " fw total | dump     |\n"
		    "|     | idx |     | total    | current | current | push skb | push desc|"
		    " cfm      |          |\n"
		    "|-----+-----+-----+----------+---------+---------+----------+----------+"
		    "----------+----------|\n");

	for (ba_idx = 0; ba_idx < IPC_MAX_BA_SESSIONS; ba_idx++) {
		tx_queue = &cl_hw->tx_queues->agg[ba_idx];

		if (!cl_hw->tx_queues->agg[ba_idx].cl_sta)
			continue;

		if (tx_queue->total_packets == 0)
			continue;

		cl_snprintf(buf, len, buf_size,
			    "| %3u | %3u | %3u |%10u|%9u|%9u|%10u|%10u|%10u|%10u|\n",
			    tx_queue->index,
			    tx_queue->cl_sta->sta_idx,
			    tx_queue->tid,
			    tx_queue->total_packets,
			    tx_queue->num_packets,
			    cl_txq_desc_in_fw(tx_queue),
			    tx_queue->total_fw_push_skb,
			    tx_queue->total_fw_push_desc,
			    tx_queue->total_fw_cfm,
			    cl_txq_total_dump_drv(tx_queue));
	}

	cl_snprintf(buf, len, buf_size,
		    "|------------------------------------------------------------------------"
		    "--------------------|\n");

out:
	spin_unlock_bh(&cl_hw->tx_lock_agg);
}

static void cl_txq_traffic_counters_print_mac(struct cl_hw *cl_hw,
					      char **buf, int *len, ssize_t *buf_size)
{
	struct ieee80211_local *local = hw_to_local(cl_hw->hw);
	u32 i = 0, total_len = 0, q_len[IEEE80211_MAX_QUEUES] = {0};
	unsigned long flags;

	spin_lock_irqsave(&local->queue_stop_reason_lock, flags);

	for (i = 0; i < IEEE80211_MAX_QUEUES; i++) {
		q_len[i] = skb_queue_len(&local->pending[i]);
		total_len += q_len[i];
	}

	spin_unlock_irqrestore(&local->queue_stop_reason_lock, flags);

	if (total_len == 0)
		return;

	cl_snprintf(buf, len, buf_size,
		    "\nMAC80211 PENDING QUEUES (MAX %d):\n", IEEE80211_MAX_QUEUES);
	cl_snprintf(buf, len, buf_size,
		    "|--------------------|\n"
		    "| queue |  current   |\n"
		    "|-------+------------|\n");

	for (i = 0; i < IEEE80211_MAX_QUEUES; i++)
		if (q_len[i] > 0)
			cl_snprintf(buf, len, buf_size, "| %5u | %10u |\n", i, q_len[i]);

	cl_snprintf(buf, len, buf_size, "|--------------------|\n");
}

static int cl_txq_traffic_counters_print(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_txq_traffic_counters_print_bcmc(cl_hw, &buf, &len, &buf_size);
	cl_txq_traffic_counters_print_single(cl_hw, &buf, &len, &buf_size);
	cl_txq_traffic_counters_print_agg(cl_hw, &buf, &len, &buf_size);
	cl_txq_traffic_counters_print_mac(cl_hw, &buf, &len, &buf_size);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void cl_txq_drop_reasons_print_bcmc(struct cl_hw *cl_hw,
					   char **buf, int *len, ssize_t *buf_size)
{
	u32 total = 0;
	u32 dump_queue_full = 0;
	u32 dump_dma_map_fail = 0;
	struct cl_tx_queue *tx_queue = &cl_hw->tx_queues->bcmc;
	unsigned long flags;

	spin_lock_irqsave(&cl_hw->tx_lock_bcmc, flags);

	total = cl_txq_total_dump_drv(tx_queue);
	dump_queue_full = tx_queue->dump_queue_full;
	dump_dma_map_fail = tx_queue->dump_dma_map_fail;

	spin_unlock_irqrestore(&cl_hw->tx_lock_bcmc, flags);

	if (total > 0)
		cl_snprintf(buf, len, buf_size,
			    "|bcmc  |     |%10u|%10u|%10u|\n",
			    dump_queue_full, dump_dma_map_fail, total);
}

static void cl_txq_drop_reasons_print_single(struct cl_hw *cl_hw,
					     char **buf, int *len, ssize_t *buf_size)
{
	u32 i = 0, total = 0;
	struct cl_tx_queue *tx_queue;

	spin_lock_bh(&cl_hw->tx_lock_single);

	for (i = 0; i < MAX_SINGLE_QUEUES; i++) {
		tx_queue = &cl_hw->tx_queues->single[i];
		total = cl_txq_total_dump_drv(tx_queue);

		if (total == 0)
			continue;

		cl_snprintf(buf, len, buf_size,
			    "|single|%5u|%10u|%10u|%10u|\n",
			    tx_queue->index,
			    tx_queue->dump_queue_full,
			    tx_queue->dump_dma_map_fail,
			    total);
	}

	spin_unlock_bh(&cl_hw->tx_lock_single);
}

static void cl_txq_drop_reasons_print_agg(struct cl_hw *cl_hw,
					  char **buf, int *len, ssize_t *buf_size)
{
	u32 i = 0, total = 0;
	struct cl_tx_queue *tx_queue;

	spin_lock_bh(&cl_hw->tx_lock_agg);

	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++) {
		tx_queue = &cl_hw->tx_queues->agg[i];
		total = cl_txq_total_dump_drv(tx_queue);

		if (total == 0)
			continue;

		cl_snprintf(buf, len, buf_size,
			    "|agg   |%5u|%10u|%10u|%10u|\n",
			    tx_queue->index,
			    tx_queue->dump_queue_full,
			    tx_queue->dump_dma_map_fail,
			    total);
	}

	spin_unlock_bh(&cl_hw->tx_lock_agg);
}

static int cl_txq_drop_reasons_print(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "-----------------------------------------------\n"
		    "| type | idx | queue    | dma map  | total    |\n"
		    "|      |     | full     | fail     | dump     |\n"
		    "|------+-----+----------+----------+----------|\n");

	cl_txq_drop_reasons_print_bcmc(cl_hw, &buf, &len, &buf_size);
	cl_txq_drop_reasons_print_single(cl_hw, &buf, &len, &buf_size);
	cl_txq_drop_reasons_print_agg(cl_hw, &buf, &len, &buf_size);

	cl_snprintf(&buf, &len, &buf_size,
		    "-----------------------------------------------\n");

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_txq_global_counters_print(struct cl_hw *cl_hw)
{
	struct cl_tx_forward_cntr *forward = &cl_hw->tx_packet_cntr.forward;
	struct cl_tx_drop_cntr *drop = &cl_hw->tx_packet_cntr.drop;
	struct cl_tx_transfer_cntr *transfer = &cl_hw->tx_packet_cntr.transfer;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "FORWARD\n"
		    "----------------------------\n"
		    "tx_start          = %u\n", forward->tx_start);
	cl_snprintf(&buf, &len, &buf_size,
		    "drv_fast_agg      = %u\n", forward->drv_fast_agg);
	cl_snprintf(&buf, &len, &buf_size,
		    "drv_fast_single   = %u\n", forward->drv_fast_single);
	cl_snprintf(&buf, &len, &buf_size,
		    "to_mac            = %u\n", forward->to_mac);
	cl_snprintf(&buf, &len, &buf_size,
		    "from_mac_single   = %u\n", forward->from_mac_single);
	cl_snprintf(&buf, &len, &buf_size,
		    "from_mac_agg      = %u\n", forward->from_mac_agg);
	cl_snprintf(&buf, &len, &buf_size,
		    "DROP\n"
		    "----------------------------\n"
		    "wd_restart        = %u\n", drop->wd_restart);
	cl_snprintf(&buf, &len, &buf_size,
		    "radio_off         = %u\n", drop->radio_off);
	cl_snprintf(&buf, &len, &buf_size,
		    "in_recovery       = %u\n", drop->in_recovery);
	cl_snprintf(&buf, &len, &buf_size,
		    "short_length      = %u\n", drop->short_length);
	cl_snprintf(&buf, &len, &buf_size,
		    "pending_full      = %u\n", drop->pending_full);
	cl_snprintf(&buf, &len, &buf_size,
		    "packet_limit      = %u\n", drop->packet_limit);
	cl_snprintf(&buf, &len, &buf_size,
		    "dev_flags         = %u\n", drop->dev_flags);
	cl_snprintf(&buf, &len, &buf_size,
		    "length_limit      = %u\n", drop->length_limit);
	cl_snprintf(&buf, &len, &buf_size,
		    "txhdr_alloc_fail  = %u\n", drop->txhdr_alloc_fail);
	cl_snprintf(&buf, &len, &buf_size,
		    "queue_null        = %u\n", drop->queue_null);
	cl_snprintf(&buf, &len, &buf_size,
		    "amsdu_alloc_fail  = %u\n", drop->amsdu_alloc_fail);
	cl_snprintf(&buf, &len, &buf_size,
		    "amsdu_dma_map_err = %u\n", drop->amsdu_dma_map_err);
	cl_snprintf(&buf, &len, &buf_size,
		    "build_hdr_fail    = %u\n", drop->build_hdr_fail);
	cl_snprintf(&buf, &len, &buf_size,
		    "key_disable       = %u\n", drop->key_disable);
	cl_snprintf(&buf, &len, &buf_size,
		    "queue_flush       = %u\n", drop->queue_flush);
	cl_snprintf(&buf, &len, &buf_size,
		    "probe_response    = %u\n", drop->probe_response);
	cl_snprintf(&buf, &len, &buf_size,
		    "sta_null_in_agg   = %u\n", drop->sta_null_in_agg);
	cl_snprintf(&buf, &len, &buf_size,
		    "sta_stop_tx       = %u\n", drop->sta_stop_tx);
	cl_snprintf(&buf, &len, &buf_size,
		    "TRANSFER\n"
		    "----------------------------\n"
		    "single_to_agg     = %u\n", transfer->single_to_agg);
	cl_snprintf(&buf, &len, &buf_size,
		    "agg_to_single     = %u\n", transfer->agg_to_single);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_txq_stop_reasons_print(struct cl_hw *cl_hw)
{
	struct ieee80211_local *local = hw_to_local(cl_hw->hw);
	unsigned long queue_stop_reasons;
	unsigned long flags;
	u8 i = 0;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "|------------------------|\n"
		    "|queue|queue_stop_reasons|\n"
		    "|-----+------------------|\n");

	for (i = 0; i < IEEE80211_MAX_QUEUES; i++) {
		spin_lock_irqsave(&local->queue_stop_reason_lock, flags);
		queue_stop_reasons = local->queue_stop_reasons[i];
		spin_unlock_irqrestore(&local->queue_stop_reason_lock, flags);

		if (queue_stop_reasons)
			cl_snprintf(&buf, &len, &buf_size, "|%5u|0x%-16lx|\n",
				    i, queue_stop_reasons);
	}

	cl_snprintf(&buf, &len, &buf_size, "|------------------------|\n");

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_txq_requested_agg_print(struct cl_hw *cl_hw)
{
	u8 i = 0;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	spin_lock_bh(&cl_hw->tx_lock_agg);

	cl_snprintf(&buf, &len, &buf_size,
		    "## used_agg_queues = %u\n", cl_hw->used_agg_queues);

	if (cl_hw->used_agg_queues) {
		for (i = 0; i < IPC_MAX_BA_SESSIONS; i++) {
			if (!cl_hw->tx_queues->agg[i].cl_sta)
				continue;

			cl_snprintf(&buf, &len, &buf_size,
				    "%u) sta_idx = %u, tid = %u\n", i + 1,
				    cl_hw->tx_queues->agg[i].cl_sta->sta_idx,
				    cl_hw->tx_queues->agg[i].tid);
		}
	}

	cl_snprintf(&buf, &len, &buf_size, "## req_agg_queues = %u\n", cl_hw->req_agg_queues);

	if (cl_hw->req_agg_queues) {
		for (i = 0; i < IPC_MAX_BA_SESSIONS; i++) {
			if (!cl_hw->req_agg_db[i].is_used)
				continue;

			cl_snprintf(&buf, &len, &buf_size, "%u) sta_idx = %u, tid = %u\n",
				    i + 1, cl_hw->req_agg_db[i].sta_idx,
				    cl_hw->req_agg_db[i].tid);
		}
	}

	spin_unlock_bh(&cl_hw->tx_lock_agg);
	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void cl_txq_hw_amsdu_stats_print(struct cl_hw *cl_hw,
					char **buf, int *len, ssize_t *buf_size)
{
	u32 i, j;
	struct cl_tx_queue *tx_queue;

	cl_snprintf(buf, len, buf_size, "HW TX-AMSDU STATS:\n");

	cl_snprintf(buf, len, buf_size, "|-----------");
	for (i = 0; i < CL_AMSDU_TX_PAYLOAD_MAX; i++)
		cl_snprintf(buf, len, buf_size, "-----------");

	cl_snprintf(buf, len, buf_size, "|\n|agg|sta|tid");
	for (i = 0; i < CL_AMSDU_TX_PAYLOAD_MAX; i++)
		cl_snprintf(buf, len, buf_size, "| amsdu #%u ", i + 1);

	cl_snprintf(buf, len, buf_size, "|\n|---+---+---");
	for (i = 0; i < CL_AMSDU_TX_PAYLOAD_MAX; i++)
		cl_snprintf(buf, len, buf_size, "+----------");

	cl_snprintf(buf, len, buf_size, "|\n");

	for (j = 0; j < IPC_MAX_BA_SESSIONS; j++) {
		tx_queue = &cl_hw->tx_queues->agg[j];

		if (!tx_queue->cl_sta)
			continue;

		if (tx_queue->total_packets == 0)
			continue;

		cl_snprintf(buf, len, buf_size, "|%3u|%3u|%3u",
			    tx_queue->index,
			    tx_queue->cl_sta->sta_idx,
			    tx_queue->tid);

		for (i = 0; i < CL_AMSDU_TX_PAYLOAD_MAX; i++)
			cl_snprintf(buf, len, buf_size, "|%10u", tx_queue->stats_hw_amsdu_cnt[i]);

		cl_snprintf(buf, len, buf_size, "|\n");
	}

	cl_snprintf(buf, len, buf_size,  "|-----------");
	for (i = 0; i < CL_AMSDU_TX_PAYLOAD_MAX; i++)
		cl_snprintf(buf, len, buf_size, "-----------");

	cl_snprintf(buf, len, buf_size, "|\n");
}

static void cl_txq_sw_amsdu_stats_print(struct cl_hw *cl_hw,
					char **buf, int *len, ssize_t *buf_size)
{
	u32 i, j;
	struct cl_tx_queue *tx_queue;

	if (cl_hw->conf->ci_tx_sw_amsdu_max_packets < 2)
		return;

	cl_snprintf(buf, len, buf_size, "SW TX-AMSDU STATS:\n");

	for (j = 0; j < IPC_MAX_BA_SESSIONS; j++) {
		tx_queue = &cl_hw->tx_queues->agg[j];

		if (!tx_queue->cl_sta)
			continue;

		if (tx_queue->total_packets == 0)
			continue;

		cl_snprintf(buf, len, buf_size,
			    "\nagg idx %u, sta %u, tid %u :\n",
			    tx_queue->index,
			    tx_queue->cl_sta->sta_idx,
			    tx_queue->tid);
		cl_snprintf(buf, len, buf_size, "----------------------------\n");

		for (i = 0; i < cl_hw->conf->ci_tx_sw_amsdu_max_packets; i++)
			if (tx_queue->stats_sw_amsdu_cnt[i] > 0)
				cl_snprintf(buf, len, buf_size,
					    "amsdu #%u = %u\n", i + 1,
					    tx_queue->stats_sw_amsdu_cnt[i]);
	}
}

static int cl_txq_amsdu_stats_print(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	spin_lock_bh(&cl_hw->tx_lock_agg);

	if (cl_hw->used_agg_queues == 0)
		goto out;

	cl_txq_hw_amsdu_stats_print(cl_hw, &buf, &len, &buf_size);
	cl_txq_sw_amsdu_stats_print(cl_hw, &buf, &len, &buf_size);
out:
	spin_unlock_bh(&cl_hw->tx_lock_agg);
	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void cl_txq_max_size_print_single(struct cl_hw *cl_hw,
					 char **buf, int *len, ssize_t *buf_size)
{
	u8 ac = 0;
	u8 sta_idx = 0;
	u16 queue_idx = 0;
	struct cl_tx_queue *tx_queue;

	cl_snprintf(buf, len, buf_size,
		    "MAX SIZE SINGLE QUEUES:\n"
		    "|----------------------|\n"
		    "|idx|sta|ac| drv | fw  |\n"
		    "|---+---+--+-----+-----|\n");

	spin_lock_bh(&cl_hw->tx_lock_single);

	for (sta_idx = 0; sta_idx < FW_MAX_NUM_STA; sta_idx++) {
		for (ac = 0; ac < AC_MAX; ac++) {
			queue_idx = QUEUE_IDX(sta_idx, ac);
			tx_queue = &cl_hw->tx_queues->single[queue_idx];

			if (tx_queue->total_fw_push_skb == 0)
				continue;

			cl_snprintf(buf, len, buf_size,
				    "|%3u|%3u|%2u|%5u|%5u|\n",
				    tx_queue->index,
				    sta_idx,
				    tx_queue->hw_index,
				    tx_queue->max_packets,
				    tx_queue->fw_max_size);
		}
	}

	spin_unlock_bh(&cl_hw->tx_lock_single);

	cl_snprintf(buf, len, buf_size, "|----------------------|\n");
}

static void cl_txq_max_size_print_agg(struct cl_hw *cl_hw,
				      char **buf, int *len, ssize_t *buf_size)
{
	u8 agg_idx = 0;
	struct cl_tx_queue *tx_queue;

	spin_lock_bh(&cl_hw->tx_lock_agg);

	if (cl_hw->used_agg_queues == 0)
		goto out;

	cl_snprintf(buf, len, buf_size,
		    "MAX SIZE AGGREGATION QUEUES:\n"
		    "|-----------------------|\n"
		    "|idx|sta|tid| drv | fw  |\n"
		    "|---+---+---+-----+-----|\n");

	for (agg_idx = 0; agg_idx < IPC_MAX_BA_SESSIONS; agg_idx++) {
		tx_queue = &cl_hw->tx_queues->agg[agg_idx];

		if (!tx_queue->cl_sta)
			continue;

		cl_snprintf(buf, len, buf_size,
			    "|%3u|%3u|%3u|%5u|%5u|\n",
			    tx_queue->index,
			    tx_queue->cl_sta->sta_idx,
			    tx_queue->tid,
			    tx_queue->max_packets,
			    tx_queue->fw_max_size);
	}

	cl_snprintf(buf, len, buf_size, "|----------------------|\n");

out:
	spin_unlock_bh(&cl_hw->tx_lock_agg);
}

static int cl_txq_max_size_print(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_txq_max_size_print_single(cl_hw, &buf, &len, &buf_size);
	cl_txq_max_size_print_agg(cl_hw, &buf, &len, &buf_size);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void cl_txq_stats_reset_bcmc(struct cl_hw *cl_hw)
{
	unsigned long flags;

	spin_lock_irqsave(&cl_hw->tx_lock_bcmc, flags);
	cl_txq_reset_counters_during_traffic(&cl_hw->tx_queues->bcmc);
	spin_unlock_irqrestore(&cl_hw->tx_lock_bcmc, flags);
}

static void cl_txq_stats_reset_single(struct cl_hw *cl_hw)
{
	u16 i = 0;

	spin_lock_bh(&cl_hw->tx_lock_single);

	for (i = 0; i < MAX_SINGLE_QUEUES; i++)
		cl_txq_reset_counters_during_traffic(&cl_hw->tx_queues->single[i]);

	spin_unlock_bh(&cl_hw->tx_lock_single);
}

static void cl_txq_stats_reset_agg(struct cl_hw *cl_hw)
{
	u16 i = 0;

	spin_lock_bh(&cl_hw->tx_lock_agg);

	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++)
		cl_txq_reset_counters_during_traffic(&cl_hw->tx_queues->agg[i]);

	spin_unlock_bh(&cl_hw->tx_lock_agg);
}

static void cl_txq_stats_reset(struct cl_hw *cl_hw)
{
	cl_txq_stats_reset_bcmc(cl_hw);
	cl_txq_stats_reset_single(cl_hw);
	cl_txq_stats_reset_agg(cl_hw);

	memset(&cl_hw->tx_packet_cntr, 0, sizeof(struct cl_tx_packet_cntr));

	pr_debug("Reset queue stats\n");
}

static void cl_txq_sched_list_print_single(struct cl_hw *cl_hw,
					   char **buf, int *len, ssize_t *buf_size)
{
	struct cl_tx_queue *tx_queue;
	u32 num_queues = 0;

	cl_snprintf(buf, len, buf_size, "TX single sched list:\n");

	spin_lock_bh(&cl_hw->tx_lock_single);

	list_for_each_entry(tx_queue, &cl_hw->list_sched_q_single, sched_list) {
		num_queues++;
		cl_snprintf(buf, len, buf_size, "%u) Index = %u\n", num_queues, tx_queue->index);
	}

	spin_unlock_bh(&cl_hw->tx_lock_single);

	if (num_queues == 0)
		cl_snprintf(buf, len, buf_size, "empty\n");
}

static void cl_txq_sched_list_print_agg(struct cl_hw *cl_hw,
					char **buf, int *len, ssize_t *buf_size)
{
	struct cl_tx_queue *tx_queue;
	u32 num_queues = 0;

	cl_snprintf(buf, len, buf_size, "\nTX agg sched list:\n");

	spin_lock_bh(&cl_hw->tx_lock_agg);

	list_for_each_entry(tx_queue, &cl_hw->list_sched_q_agg, sched_list) {
		num_queues++;
		cl_snprintf(buf, len, buf_size, "%u) Index = %u\n", num_queues, tx_queue->index);
	}

	spin_unlock_bh(&cl_hw->tx_lock_agg);

	if (num_queues == 0)
		cl_snprintf(buf, len, buf_size, "empty\n");
}

static int cl_txq_sched_list_print(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_txq_sched_list_print_single(cl_hw, &buf, &len, &buf_size);
	cl_txq_sched_list_print_agg(cl_hw, &buf, &len, &buf_size);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_txq_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "txq usage:\n"
		 "-a : Print traffic counters\n"
		 "-b : Print drop counters\n"
		 "-c : Print global counters\n"
		 "-d : Print stop reasons\n"
		 "-e : Print requested aggregations\n"
		 "-f : Print AMSDU statistics\n"
		 "-m : Print maximum queues size\n"
		 "-r : Reset queue stats\n"
		 "-s : Print schedule list\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static void cl_txq_task_single(struct cl_hw *cl_hw)
{
	/* Schedule single queues */
	struct cl_tx_queue *tx_queue, *tx_queue_tmp;

	spin_lock(&cl_hw->tx_lock_single);

	list_for_each_entry_safe(tx_queue, tx_queue_tmp, &cl_hw->list_sched_q_single, sched_list)
		cl_txq_sched(cl_hw, tx_queue);

	/* Rotate the queue so next schedule will start with a different queue */
	list_rotate_left(&cl_hw->list_sched_q_single);

	spin_unlock(&cl_hw->tx_lock_single);
}

static void cl_txq_task_agg(struct cl_hw *cl_hw)
{
	/* Schedule agg queueus */
	struct cl_tx_queue *tx_queue, *tx_queue_tmp;

	spin_lock(&cl_hw->tx_lock_agg);

	list_for_each_entry_safe(tx_queue, tx_queue_tmp, &cl_hw->list_sched_q_agg, sched_list)
		cl_txq_sched(cl_hw, tx_queue);

	/* Rotate the queue so next schedule will start with a different queue */
	list_rotate_left(&cl_hw->list_sched_q_agg);

	spin_unlock(&cl_hw->tx_lock_agg);
}

static void cl_txq_task(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;

	cl_txq_task_single(cl_hw);
	cl_txq_task_agg(cl_hw);
}

void cl_txq_init(struct cl_hw *cl_hw)
{
	u32 i;
	struct cl_tx_queue *tx_queue;

	tasklet_init(&cl_hw->tx_task, cl_txq_task, (unsigned long)cl_hw);

	INIT_LIST_HEAD(&cl_hw->list_sched_q_agg);
	INIT_LIST_HEAD(&cl_hw->list_sched_q_single);

	for (i = 0; i < MAX_SINGLE_QUEUES; i++) {
		tx_queue = &cl_hw->tx_queues->single[i];
		memset(tx_queue, 0, sizeof(struct cl_tx_queue));
		INIT_LIST_HEAD(&tx_queue->hdrs);
		tx_queue->hw_index = i / FW_MAX_NUM_STA;
		tx_queue->fw_max_size = IPC_TXDESC_CNT_SINGLE;
		tx_queue->fw_free_space = IPC_TXDESC_CNT_SINGLE;
		tx_queue->index = i;
		tx_queue->max_packets = cl_hw->conf->ci_tx_queue_size_single;
		tx_queue->type = QUEUE_TYPE_SINGLE;
	}

	/* BCMC queue init */
	tx_queue = &cl_hw->tx_queues->bcmc;
	memset(tx_queue, 0, sizeof(struct cl_tx_queue));
	INIT_LIST_HEAD(&tx_queue->hdrs);
	tx_queue->hw_index = CL_HWQ_BCN;
	tx_queue->fw_max_size = IPC_TXDESC_CNT_BCMC;
	tx_queue->fw_free_space = IPC_TXDESC_CNT_BCMC;
	tx_queue->index = 0;
	tx_queue->max_packets = 0;
	tx_queue->type = QUEUE_TYPE_BCMC;

	/* Init aggregation queues */
	memset(cl_hw->tx_queues->agg, 0, sizeof(struct cl_tx_queue));
	cl_hw->used_agg_queues = 0;
}

void cl_txq_stop(struct cl_hw *cl_hw)
{
	tasklet_kill(&cl_hw->tx_task);
}

struct cl_tx_queue *cl_txq_get(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr)
{
	struct cl_sta *cl_sta = sw_txhdr->cl_sta;
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(sw_txhdr->skb);
	u8 hw_queue = sw_txhdr->hw_queue;

	if (!cl_sta &&
	    hw_queue == CL_HWQ_VO &&
	    is_multicast_ether_addr(sw_txhdr->hdr80211->addr1)) {
		/*
		 * If HW queue is VO and packet is multicast, it was not buffered
		 * by mac80211, and it should be pushed to the high-priority queue
		 * and not to the bcmc queue.
		 */
		return &cl_hw->tx_queues->single[HIGH_PRIORITY_QUEUE];
	} else if (!cl_sta &&
		   (hw_queue != CL_HWQ_BCN) &&
		   !(tx_info->flags & IEEE80211_TX_CTL_NO_PS_BUFFER)) {
		/*
		 * If station is NULL, but HW queue is not BCN,
		 * it most go to the high-priority queue.
		 */
		tx_info->flags |= IEEE80211_TX_CTL_NO_PS_BUFFER;
		sw_txhdr->hw_queue = CL_HWQ_VO;
		return &cl_hw->tx_queues->single[HIGH_PRIORITY_QUEUE];
	} else if (cl_sta && (tx_info->flags & IEEE80211_TX_CTL_AMPDU)) {
		/* Agg packet */
		return cl_sta->agg_tx_queues[sw_txhdr->tid];
	} else if (hw_queue == CL_HWQ_BCN) {
		return &cl_hw->tx_queues->bcmc;
	} else if (tx_info->flags & IEEE80211_TX_CTL_NO_PS_BUFFER) {
		/*
		 * Only frames that are power save response or non-bufferable MMPDU
		 * will have this flag set our driver will push those frame to the
		 * highiest priority queue.
		 */
		return &cl_hw->tx_queues->single[HIGH_PRIORITY_QUEUE];
	}

	return &cl_hw->tx_queues->single[QUEUE_IDX(sw_txhdr->sta_idx, hw_queue)];
}

void cl_txq_push(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr)
{
	struct cl_tx_queue *tx_queue = sw_txhdr->tx_queue;

	if (tx_queue->num_packets < tx_queue->max_packets) {
		tx_queue->num_packets++;

		/*
		 * This prioritization of action frames helps Samsung Galaxy Note 8 to
		 * open BA session more easily, when phy dev is PHY_DEV_OLYMPUS
		 * and helps open BA on all system emulators
		 */
		if (ieee80211_is_action(sw_txhdr->fc) && !IS_REAL_PHY(cl_hw->chip))
			list_add(&sw_txhdr->tx_queue_list, &tx_queue->hdrs);
		else
			list_add_tail(&sw_txhdr->tx_queue_list, &tx_queue->hdrs);

		/* If it is the first packet in the queue, add the queue to the sched list */
		cl_txq_sched_list_add(tx_queue, cl_hw);
	} else {
		struct cl_sta *cl_sta = sw_txhdr->cl_sta;
		u8 tid = sw_txhdr->tid;

		/* If the SW queue full, release the packet */
		tx_queue->dump_queue_full++;

		if (cl_sta && cl_sta->amsdu_anchor[tid].sw_txhdr) {
			if (cl_sta->amsdu_anchor[tid].sw_txhdr == sw_txhdr) {
				cl_sta->amsdu_anchor[tid].sw_txhdr = NULL;
				cl_sta->amsdu_anchor[tid].packet_cnt = 0;
			}
		}

		dev_kfree_skb_any(sw_txhdr->skb);
		cl_sw_txhdr_free(cl_hw, sw_txhdr);

		/* Schedule tasklet to try and empty the queue */
		tasklet_schedule(&cl_hw->tx_task);
	}
}

void cl_txq_sched(struct cl_hw *cl_hw, struct cl_tx_queue *tx_queue)
{
	struct cl_sw_txhdr *sw_txhdr, *sw_txhdr_tmp;
	bool is_single_sta_q = false, is_resched = false;

	if (!test_bit(CL_DEV_STARTED, &cl_hw->drv_flags) ||
	    cl_hw->tx_disable_flags ||
	    cl_txq_is_fw_full(tx_queue))
		return;

	if (tx_queue->type == QUEUE_TYPE_SINGLE && tx_queue->cl_sta)
		is_single_sta_q = true;

	/* Go over all descriptors in queue */
	list_for_each_entry_safe(sw_txhdr, sw_txhdr_tmp, &tx_queue->hdrs, tx_queue_list) {
		/* verify there is no pending ADDBA */
		if (is_single_sta_q && tx_queue->cl_sta->baws[sw_txhdr->tid].action_start) {
			is_resched = true;
			continue;
		}

		list_del(&sw_txhdr->tx_queue_list);
		tx_queue->num_packets--;

		if (cl_hw->tx_db.force_amsdu &&
		    sw_txhdr->txdesc.host_info.packet_cnt < cl_hw->txamsdu_en)
			break;

		cl_tx_push(cl_hw, sw_txhdr, tx_queue);

		if (cl_txq_is_fw_full(tx_queue))
			break;
	}

	if (is_resched)
		tasklet_schedule(&cl_hw->tx_task);

	/* If queue is empty remove it from schedule list */
	cl_txq_sched_list_remove_if_empty(tx_queue);
}

void cl_txq_agg_alloc(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
		      struct mm_ba_add_cfm *ba_add_cfm, u16 buf_size)
{
	u8 tid = ba_add_cfm->tid;
	u8 fw_agg_idx = ba_add_cfm->agg_idx;
	u8 sta_idx = cl_sta->sta_idx;
	u8 ac = cl_tid2hwq[tid];
	u16 single_queue_idx = QUEUE_IDX(sta_idx, ac);
	struct cl_tx_queue *tx_queue = &cl_hw->tx_queues->agg[fw_agg_idx];
	u16 fw_size = IS_USB_BUS_TYPE(cl_hw->chip) ?
		TXDESC_AGG_Q_SIZE_USB : TXDESC_AGG_Q_SIZE_MAX;
	struct cl_baw *baw = &cl_sta->baws[tid];
	spin_lock_bh(&cl_hw->tx_lock_agg);

	/* Init aggregated queue struct */
	memset(tx_queue, 0, sizeof(struct cl_tx_queue));
	INIT_LIST_HEAD(&tx_queue->hdrs);

	/*
	 * Firmware agg queues size is static and set to 512, so that for the worst
	 * case of HE stations,that support AMPDU of 256, it has room for two full
	 * aggregation.
	 * To keep this logic, of room for two aggregations, for non-HE stations, or
	 * for HE stations that do not support AMPDU of 256, we initialize fw_max_size
	 to twice the buffer size supported by the station.
	 */
	tx_queue->fw_max_size = min(fw_size, (u16)(buf_size * 2));
	tx_queue->fw_free_space = tx_queue->fw_max_size;

	tx_queue->max_packets = cl_hw->conf->ci_tx_queue_size_agg;
	tx_queue->hw_index = (IS_USB_BUS_TYPE(cl_hw->chip) &&
			      cl_hw->conf->ci_usb_single_queue_for_agg_en) ?
			      CL_USB_AGG_QUEUE_IDX : ac;
	tx_queue->cl_sta = cl_sta;
	tx_queue->type = QUEUE_TYPE_AGG;
	tx_queue->tid = tid;
	tx_queue->index = fw_agg_idx;

	/* Reset the synchronization counters between the fw and the IPC layer */
	cl_hw->ipc_write_idx.txdesc_write_idx->agg[fw_agg_idx] = 0;

	/* Attach the cl_hw chosen queue to the station and agg queues DB */
	cl_sta->agg_tx_queues[tid] = tx_queue;
	/* Queue is ready, may remove baw list protection */
	baw->action_start = false;

	cl_agg_cfm_set_tx_queue(cl_hw, tx_queue, fw_agg_idx);

	/* Notify upper mac80211 layer of queues resources status */
	cl_hw->used_agg_queues++;
	cl_txq_agg_size_set(cl_hw);
	cl_txq_agg_request_del(cl_hw, sta_idx, tid);

	/*
	 * Move the qos descriptors to the new allocated aggregated queues,
	 * otherwise we might reorder packets)
	 */
	cl_txq_transfer_single_to_agg(cl_hw, &cl_hw->tx_queues->single[single_queue_idx],
				      tx_queue, tid);
	/* Move the BA window pending packets to agg path */
	cl_baw_pending_to_agg(cl_hw, cl_sta, tid);

	spin_unlock_bh(&cl_hw->tx_lock_agg);

	cl_dbg_trace(cl_hw, "Allocate queue [%u] to station [%u] tid [%u]\n",
		     fw_agg_idx, sta_idx, tid);
}

void cl_txq_agg_free(struct cl_hw *cl_hw, struct cl_tx_queue *tx_queue,
		     struct cl_sta *cl_sta, u8 tid)
{
	spin_lock_bh(&cl_hw->tx_lock_agg);

	cl_dbg_trace(cl_hw, "Free queue [%u] of station [%u] tid [%u]\n",
		     tx_queue->index, cl_sta->sta_idx, tid);

	memset(tx_queue, 0, sizeof(struct cl_tx_queue));

	cl_hw->used_agg_queues--;
	cl_txq_agg_size_set(cl_hw);

	spin_unlock_bh(&cl_hw->tx_lock_agg);
}

void cl_txq_agg_stop(struct cl_sta *cl_sta, u8 tid)
{
	cl_sta->agg_tx_queues[tid] = NULL;
}

u32 cl_txq_get_free_space(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 tid)
{
	struct cl_tx_queue *tx_queue = cl_sta->agg_tx_queues[tid];

	if (!tx_queue) {
		int ac = cl_tid_to_ac(tid);
		u16 queue_idx = QUEUE_IDX(cl_sta->sta_idx, ac);

		tx_queue = &cl_hw->tx_queues->single[queue_idx];
	}

	return (tx_queue->max_packets - tx_queue->num_packets);
}

void cl_txq_sta_add(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	/* Set cl_sta field for all single queues of this station */
	u8 ac;
	u16 queue_idx;

	for (ac = 0; ac < AC_MAX; ac++) {
		queue_idx = QUEUE_IDX(cl_sta->sta_idx, ac);
		cl_hw->tx_queues->single[queue_idx].cl_sta = cl_sta;
	}

	/* Reset pointers to TX agg queues */
	memset(cl_sta->agg_tx_queues, 0, sizeof(cl_sta->agg_tx_queues));
}

void cl_txq_sta_remove(struct cl_hw *cl_hw, u8 sta_idx)
{
	/* Clear cl_sta field for all single queues of this station */
	u8 ac;
	u16 queue_idx;

	for (ac = 0; ac < AC_MAX; ac++) {
		queue_idx = QUEUE_IDX(sta_idx, ac);
		cl_hw->tx_queues->single[queue_idx].cl_sta = NULL;
	}
}

void cl_txq_transfer_agg_to_single(struct cl_hw *cl_hw, struct cl_tx_queue *agg_queue)
{
	/*
	 * 1) Remove from aggregation queue
	 * 2) Free sw_txhdr
	 * 3) Push to single queue
	 */
	struct cl_sw_txhdr *sw_txhdr, *sw_txhdr_tmp;
	struct sk_buff *skb;
	struct ieee80211_tx_info *tx_info;
	struct cl_tx_queue *single_queue;
	struct cl_sta *cl_sta = agg_queue->cl_sta;
	u16 single_queue_idx = 0;

	if (agg_queue->num_packets == 0)
		return;

	single_queue_idx = QUEUE_IDX(cl_sta->sta_idx, agg_queue->hw_index);
	single_queue = &cl_hw->tx_queues->single[single_queue_idx];

	list_for_each_entry_safe(sw_txhdr, sw_txhdr_tmp, &agg_queue->hdrs, tx_queue_list) {
		list_del(&sw_txhdr->tx_queue_list);
		agg_queue->num_packets--;

		skb = sw_txhdr->skb;
		tx_info = IEEE80211_SKB_CB(skb);

		if (cl_tx_ctrl_is_amsdu(tx_info)) {
			cl_tx_amsdu_transfer_single(cl_hw, sw_txhdr);
		} else {
			tx_info->flags &= ~IEEE80211_TX_CTL_AMPDU;

			if (cl_tx_8023_to_wlan(cl_hw, skb, cl_sta, sw_txhdr->tid) == 0) {
				cl_hw->tx_packet_cntr.transfer.agg_to_single++;
				cl_tx_single(cl_hw, cl_sta, skb, false, false);
			}
		}

		cl_sw_txhdr_free(cl_hw, sw_txhdr);
	}

	/* If queue is empty remove it from schedule list */
	cl_txq_sched_list_remove_if_empty(agg_queue);
}

void cl_txq_flush_agg(struct cl_hw *cl_hw, struct cl_tx_queue *tx_queue, bool lock)
{
	if (lock) {
		spin_lock_bh(&cl_hw->tx_lock_agg);
		cl_txq_flush(cl_hw, tx_queue);
		spin_unlock_bh(&cl_hw->tx_lock_agg);
	} else {
		cl_txq_flush(cl_hw, tx_queue);
	}
}

void cl_txq_flush_single(struct cl_hw *cl_hw, u16 idx)
{
	spin_lock_bh(&cl_hw->tx_lock_single);
	cl_txq_flush(cl_hw, &cl_hw->tx_queues->single[idx]);
	spin_unlock_bh(&cl_hw->tx_lock_single);
}

void cl_txq_flush_all_agg(struct cl_hw *cl_hw)
{
	int i = 0;

	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++)
		cl_txq_flush(cl_hw, &cl_hw->tx_queues->agg[i]);

	/* Reset used_agg_queues counter */
	cl_hw->used_agg_queues = 0;
	cl_hw->req_agg_queues = 0;
	memset(cl_hw->req_agg_db, 0, sizeof(cl_hw->req_agg_db));
}

void cl_txq_flush_all_single(struct cl_hw *cl_hw)
{
	int i = 0;

	for (i = 0; i < MAX_SINGLE_QUEUES; i++)
		cl_txq_flush(cl_hw, &cl_hw->tx_queues->single[i]);
}

void cl_txq_flush_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	int i = 0;
	u8 sta_idx = cl_sta->sta_idx;
	u32 queue_idx = 0;
	struct cl_tx_queue *tx_queue = NULL;

	spin_lock_bh(&cl_hw->tx_lock_agg);

	/* Flush all aggregation queues for this station */
	for (i = 0; i < IEEE80211_NUM_TIDS; i++)
		if (cl_sta->agg_tx_queues[i])
			cl_txq_flush(cl_hw, cl_sta->agg_tx_queues[i]);

	spin_unlock_bh(&cl_hw->tx_lock_agg);

	spin_lock_bh(&cl_hw->tx_lock_single);

	/* Flush all single queues for this station */
	for (i = 0; i < AC_MAX; i++) {
		queue_idx = QUEUE_IDX(sta_idx, i);
		tx_queue = &cl_hw->tx_queues->single[queue_idx];
		cl_txq_flush(cl_hw, tx_queue);
		cl_txq_reset_counters(tx_queue);
	}

	/* Go over high prioirty queue and delete packets belonging to this station */
	cl_txq_delete_packets(cl_hw, &cl_hw->tx_queues->single[HIGH_PRIORITY_QUEUE], sta_idx);

	spin_unlock_bh(&cl_hw->tx_lock_single);
}

void cl_txq_agg_request_add(struct cl_hw *cl_hw, u8 sta_idx, u8 tid)
{
	int i = cl_txq_request_find(cl_hw, sta_idx, tid);
	struct cl_req_agg_db *req_agg_db = NULL;

	if (i != -1) {
		cl_dbg_trace(cl_hw, "ALREADY_ADDED - entry = %d, sta_idx = %u, tid = %u\n",
			     i, sta_idx, tid);
		return;
	}

	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++) {
		req_agg_db = &cl_hw->req_agg_db[i];

		if (!req_agg_db->is_used) {
			cl_dbg_trace(cl_hw, "ADD - entry = %d, sta_idx = %u, tid = %u\n",
				     i, sta_idx, tid);
			req_agg_db->is_used = true;
			req_agg_db->sta_idx = sta_idx;
			req_agg_db->tid = tid;
			cl_hw->req_agg_queues++;
			return;
		}
	}
}

void cl_txq_agg_request_del(struct cl_hw *cl_hw, u8 sta_idx, u8 tid)
{
	int i = cl_txq_request_find(cl_hw, sta_idx, tid);

	if (i != -1) {
		cl_dbg_trace(cl_hw, "DEL - entry = %d, sta_idx = %u, tid = %u\n",
			     i, sta_idx, tid);
		cl_hw->req_agg_db[i].is_used = false;
		cl_hw->req_agg_queues--;
	}
}

bool cl_txq_is_agg_available(struct cl_hw *cl_hw)
{
	u8 total_agg_queues = cl_hw->used_agg_queues + cl_hw->req_agg_queues;

	return (total_agg_queues < IPC_MAX_BA_SESSIONS);
}

bool cl_txq_single_is_full(struct cl_hw *cl_hw, u16 idx)
{
	struct cl_tx_queue *tx_queue = &cl_hw->tx_queues->single[idx];
	bool is_full = 0;

	spin_lock_bh(&cl_hw->tx_lock_single);
	is_full = (tx_queue->max_packets == tx_queue->num_packets);
	spin_unlock_bh(&cl_hw->tx_lock_single);

	return is_full;
}

void cl_txq_single_sched(struct cl_hw *cl_hw, u16 idx)
{
	/*
	 * Don't take lock because it is already taken by
	 * all functions that call cl_txq_single_sched().
	 */
	struct cl_tx_queue *tx_queue = &cl_hw->tx_queues->single[idx];

	if (tx_queue->num_packets)
		cl_txq_sched(cl_hw, tx_queue);
}

bool cl_txq_agg_is_full(struct cl_hw *cl_hw, u16 idx)
{
	struct cl_tx_queue *tx_queue = &cl_hw->tx_queues->agg[idx];
	bool is_full = 0;

	spin_lock_bh(&cl_hw->tx_lock_agg);
	is_full = (tx_queue->max_packets == tx_queue->num_packets);
	spin_unlock_bh(&cl_hw->tx_lock_agg);

	return is_full;
}

bool cl_txq_is_fw_empty(struct cl_tx_queue *tx_queue)
{
	return (tx_queue->fw_free_space == tx_queue->fw_max_size);
}

bool cl_txq_is_fw_full(struct cl_tx_queue *tx_queue)
{
	return (tx_queue->fw_free_space == 0);
}

u16 cl_txq_desc_in_fw(struct cl_tx_queue *tx_queue)
{
	return (tx_queue->fw_max_size - tx_queue->fw_free_space);
}

bool cl_txq_frames_pending(struct cl_hw *cl_hw)
{
	int i = 0;

	/* Check if we have multicast/bradcast frame in FW queues */
	if (!cl_txq_is_fw_empty(&cl_hw->tx_queues->bcmc))
		return true;

	/* Check if we have singles frame in FW queues */
	for (i = 0; i < MAX_SINGLE_QUEUES; i++)
		if (!cl_txq_is_fw_empty(&cl_hw->tx_queues->single[i]))
			return true;

	/* Check if we have aggregation frame in FW queues */
	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++)
		if (!cl_txq_is_fw_empty(&cl_hw->tx_queues->agg[i]))
			return true;

	return false;
}

int cl_txq_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	switch (cli_params->option) {
	case 'a':
		return cl_txq_traffic_counters_print(cl_hw);
	case 'b':
		return cl_txq_drop_reasons_print(cl_hw);
	case 'c':
		return cl_txq_global_counters_print(cl_hw);
	case 'd':
		return cl_txq_stop_reasons_print(cl_hw);
	case 'e':
		return cl_txq_requested_agg_print(cl_hw);
	case 'f':
		return cl_txq_amsdu_stats_print(cl_hw);
	case 'm':
		return cl_txq_max_size_print(cl_hw);
	case 'r':
		cl_txq_stats_reset(cl_hw);
		break;
	case 's':
		return cl_txq_sched_list_print(cl_hw);
	case '?':
		return cl_txq_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		break;
	}

	return 0;
}
