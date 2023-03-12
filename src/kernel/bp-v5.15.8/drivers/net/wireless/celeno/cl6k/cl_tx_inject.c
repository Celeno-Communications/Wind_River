// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_tx_inject.h"
#include "cl_tx.h"
#include "cl_edca.h"
#include "cl_rate_ctrl.h"
#include "cl_edca.h"
#include "cl_tx_queue.h"
#include "cl_ate.h"
#include "cl_agg_cfm.h"
#include "cl_single_cfm.h"
#include "cl_mac_addr.h"
#include "cl_baw.h"
#include "cl_ampdu.h"
#include "cl_key.h"
#include "cl_msg_tx.h"

#ifdef CE_DUMMY_PHY
#define TX_BA_SESSION_TIMEOUT 100
#else
#define TX_BA_SESSION_TIMEOUT 10
#endif

/*
 * When set to 1 aggregated traffic will be sent to real and dummy stations.
 * When set to 0 aggregated traffic will be sent only dummy stations.
 */
int ce_tx_inject_real_sta = 1;
module_param(ce_tx_inject_real_sta, int, 0664);

static const u8 skb_inject_prefix_single[] = {
	0x88, 0x02,                         /* Frame control - DATA, QOS-DATA, FROM-DS */
	0x00, 0x00,                         /* Duration / ID */
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* Addr1 - RA = DA */
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, /* Addr2 - TA = BSSID */
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, /* Addr3 - SA */
	0x00, 0x00,                         /* Sequence control */
	0x00, 0x00,                         /* QoS control */
};

static const u8 skb_inject_prefix_agg[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* Destination MAC */
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, /* Source MAC */
	0x08, 0x00,                         /* Ether Type */
};

struct sk_buff *cl_tx_inject_alloc_skb(struct cl_hw *cl_hw, struct cl_sta *cl_sta, bool is_agg)
{
	u8 *skb_data = NULL;
	u8 cyclic_data = 0;
	u32 i;
	struct sk_buff *skb = NULL;
	struct ieee80211_tx_info *tx_info = NULL;
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;
	u32 prefix_size = is_agg ? sizeof(skb_inject_prefix_agg) : sizeof(skb_inject_prefix_single);

	skb = dev_alloc_skb(tx_inject->packet_len);

	if (!skb)
		return NULL;

	tx_info = IEEE80211_SKB_CB(skb);
	memset(tx_info, 0, sizeof(struct ieee80211_tx_info));

	/* Copy data */
	skb_data = skb_put(skb, tx_inject->packet_len);

	if (is_agg)
		memcpy(skb_data, skb_inject_prefix_agg, prefix_size);
	else
		memcpy(skb_data, skb_inject_prefix_single, prefix_size);

	if (cl_sta) {
		skb->dev = cl_sta->cl_vif->dev;

		if (is_agg) {
			struct ethhdr *ehdr = (struct ethhdr *)skb->data;

			cl_mac_addr_copy(ehdr->h_dest, cl_sta->addr);
			cl_mac_addr_copy(ehdr->h_source, cl_sta->cl_vif->vif->addr);
		} else {
			struct ieee80211_qos_hdr *qos_hdr = (struct ieee80211_qos_hdr *)skb->data;

			cl_mac_addr_copy(qos_hdr->addr1, cl_sta->addr);
			cl_mac_addr_copy(qos_hdr->addr2, cl_sta->cl_vif->vif->addr);
			cl_mac_addr_copy(qos_hdr->addr3, cl_sta->cl_vif->vif->addr);
		}
	}

	for (i = prefix_size; i < tx_inject->packet_len; i++) {
		*(skb_data + i) = cyclic_data;
		cyclic_data++;
	}

	tx_info->band = cl_hw->nl_band;
	tx_info->flags = IEEE80211_TX_CTL_INJECTED;

	if (cl_sta) {
		tx_info->control.vif = cl_sta->cl_vif->vif;
		tx_info->control.hw_key = cl_key_get(cl_sta);

		if (tx_inject->is_agg) {
			skb->priority = (skb->priority &
					 ~IEEE80211_QOS_CTL_TAG1D_MASK) |
					TX_INJECT_AGG_TID;
			tx_info->hw_queue = cl_tid_to_ac(TX_INJECT_AGG_TID);
			tx_info->flags |= IEEE80211_TX_CTL_AMPDU;

			if (cl_sta->baws[TX_INJECT_AGG_TID].amsdu)
				tx_info->control.flags |= IEEE80211_TX_CTRL_AMSDU;
		}
	} else {
		struct cl_vif *cl_vif = cl_vif_get_first(cl_hw);

		if (!cl_vif) {
			kfree_skb(skb);
			return NULL;
		}

		tx_info->hw_queue = TX_INJECT_SINGLE_AC;
		tx_info->flags |= IEEE80211_TX_CTL_NO_ACK;
		tx_info->control.vif = cl_vif->vif;
	}

	atomic_inc(&tx_inject->alloc_counter);

	return skb;
}

static struct cl_sta *first_sta(struct cl_hw *cl_hw)
{
	return list_first_entry_or_null(&cl_hw->cl_sta_db.head, struct cl_sta, list);
}

static struct cl_sta *first_dummy_sta(struct cl_hw *cl_hw)
{
	struct cl_sta *cl_sta = NULL;

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list)
		if (cl_sta->is_dummy)
			return cl_sta;

	return NULL;
}

static struct cl_sta *get_first_sta(struct cl_hw *cl_hw)
{
	if (ce_tx_inject_real_sta)
		return first_sta(cl_hw);
	else
		return first_dummy_sta(cl_hw);
}

static struct cl_sta *next_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	if (list_is_last(&cl_sta->list, &cl_hw->cl_sta_db.head))
		return first_sta(cl_hw);
	else
		return list_next_entry(cl_sta, list);
}

static struct cl_sta *next_dummy_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_sta *cl_sta_next;
	/* Move to next dummy cl_sta in list */
	if (list_is_last(&cl_sta->list, &cl_hw->cl_sta_db.head))
		return first_dummy_sta(cl_hw);

	cl_sta_next = list_next_entry(cl_sta, list);

	if (cl_sta_next->is_dummy)
		return cl_sta_next;
	else
		return next_dummy_sta(cl_hw, cl_sta_next);
}

static struct cl_sta *get_next_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	if (ce_tx_inject_real_sta)
		return next_sta(cl_hw, cl_sta);
	else
		return next_dummy_sta(cl_hw, cl_sta);
}

static void cl_tx_inject_tasklet(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;
	struct sk_buff *skb = NULL;

	while ((tx_inject->current_counter < tx_inject->max_counter) || tx_inject->continuous) {
		if (tx_inject->is_agg) {
			u8 fw_agg_idx = tx_inject->cl_sta->baws[TX_INJECT_AGG_TID].fw_agg_idx;

			if (cl_txq_agg_is_full(cl_hw, fw_agg_idx))
				return;
		} else {
			u16 queue_idx = tx_inject->cl_sta ?
				QUEUE_IDX(tx_inject->cl_sta->sta_idx, TX_INJECT_SINGLE_AC) :
				HIGH_PRIORITY_QUEUE;

			if (cl_txq_single_is_full(cl_hw, queue_idx))
				return;
		}

		if (atomic_read(&tx_inject->alloc_counter) == TX_INJECT_MAX_SKBS)
			return;

		skb = cl_tx_inject_alloc_skb(cl_hw, tx_inject->cl_sta, tx_inject->is_agg);

		if (!skb)
			return;

		if (tx_inject->is_agg)
			cl_tx_agg(cl_hw, tx_inject->cl_sta, skb, true, true);
		else
			cl_tx_single(cl_hw, tx_inject->cl_sta, skb, false, true);

		if (tx_inject->cl_sta)
			tx_inject->cl_sta = get_next_sta(cl_hw, tx_inject->cl_sta);

		if (!tx_inject->continuous)
			tx_inject->current_counter++;
	}
}

static void open_ba_session(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct mm_ba_add_cfm *ba_add_cfm;
	u16 buf_size = min_t(u16, TXDESC_AGG_Q_SIZE_MAX, cl_hw->conf->ce_max_agg_size_tx);
	u8 tid = TX_INJECT_AGG_TID;

	if (!ce_tx_inject_real_sta && !cl_sta->is_dummy)
		return;

	if (cl_sta->agg_tx_queues[tid])
		return;

	/* Open BA session */
	if (cl_msg_tx_ba_add(cl_hw, BA_AGMT_TX, cl_sta->sta_idx, tid, buf_size, 0)) {
		cl_dbg_err(cl_hw, "cl_msg_tx_ba_add failed\n");
		return;
	}

	ba_add_cfm = (struct mm_ba_add_cfm *)(cl_hw->msg_cfm_params[MM_BA_ADD_TX_CFM]);

	if (ba_add_cfm->status != BA_AGMT_ESTABLISHED) {
		cl_dbg_err(cl_hw, "Unexpected ba_add_cfm status [%u]\n", ba_add_cfm->status);
		cl_msg_tx_free_cfm_params(cl_hw, MM_BA_ADD_TX_CFM);
		return;
	}

	/* Reset ssn */
	cl_agg_cfm_set_ssn(cl_hw, 0, ba_add_cfm->agg_idx);
	cl_baw_tx_inject(cl_hw, &cl_sta->baws[tid], ba_add_cfm->agg_idx);
	cl_tx_amsdu_set_max_len(cl_hw, cl_sta, tid);
	cl_txq_agg_alloc(cl_hw, cl_sta, ba_add_cfm, buf_size);
	cl_msg_tx_free_cfm_params(cl_hw, MM_BA_ADD_TX_CFM);
}

static void stop_ba_session(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_tx_queue *tx_queue;
	u16 idx;

	spin_lock_bh(&cl_hw->tx_lock_agg);
	tx_queue = cl_sta->agg_tx_queues[TX_INJECT_AGG_TID];

	if ((!ce_tx_inject_real_sta && !cl_sta->is_dummy) || !tx_queue) {
		spin_unlock_bh(&cl_hw->tx_lock_agg);
		return;
	}

	/* Flush TX queue and wait for all confirmations */
	cl_txq_flush_agg(cl_hw, tx_queue, false);
	idx = tx_queue->index;
	spin_unlock_bh(&cl_hw->tx_lock_agg);

	cl_agg_cfm_poll_empty(cl_hw, idx, false);

	cl_tx_amsdu_anchor_reset(&cl_sta->amsdu_anchor[TX_INJECT_AGG_TID]);
}

static void free_ba_session(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_tx_queue *tx_queue = cl_sta->agg_tx_queues[TX_INJECT_AGG_TID];

	if (!tx_queue)
		return;

	cl_txq_agg_stop(cl_sta, TX_INJECT_AGG_TID);
	cl_txq_flush_agg(cl_hw, tx_queue, true);
	_cl_ampdu_tx_stop(cl_hw, tx_queue, cl_sta, TX_INJECT_AGG_TID);
}

static void free_dummy_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct sta_info *stainfo = cl_sta->stainfo;

	cl_sta_remove(cl_hw, &stainfo->sdata->vif, &stainfo->sta);
	kfree(stainfo);

	cl_hw->ate_db.num_dummy_sta--;
}

static void free_all_dummy_sta(struct cl_hw *cl_hw)
{
	struct cl_sta *cl_sta = NULL, *cl_sta_tmp = NULL;

	list_for_each_entry_safe(cl_sta, cl_sta_tmp, &cl_hw->cl_sta_db.head, list)
		if (cl_sta->is_dummy)
			free_dummy_sta(cl_hw, cl_sta);
}

static void edca_set_aggressive(struct cl_hw *cl_hw)
{
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;

	if (!tx_inject->aggressive_edca) {
		struct edca_params aggressive_params = {
			.aifsn = 1, .cw_min = 0, .cw_max = 1, .txop = 0
		};
		u8 hwq = tx_inject->is_agg ? EDCA_AC_BE : EDCA_AC_VO;

		cl_edca_set(cl_hw, hwq, &aggressive_params, NULL);
		tx_inject->aggressive_edca = true;
	}
}

static void edca_restore_default(struct cl_hw *cl_hw)
{
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;

	if (tx_inject->aggressive_edca) {
		u8 hwq = tx_inject->is_agg ? EDCA_AC_BE : EDCA_AC_VO;

		cl_edca_restore_conf(cl_hw, hwq);
		tx_inject->aggressive_edca = false;
	}
}

void cl_tx_inject_init(struct cl_hw *cl_hw)
{
	tasklet_init(&cl_hw->tx_inject.tasklet, cl_tx_inject_tasklet, (unsigned long)cl_hw);
}

void cl_tx_inject_close(struct cl_hw *cl_hw)
{
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;

	tasklet_kill(&tx_inject->tasklet);
	free_all_dummy_sta(cl_hw);
}

void cl_tx_inject_reset(struct cl_hw *cl_hw)
{
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;
	struct cl_sta *cl_sta = NULL;

	/* Return packet_len tp default */
	tx_inject->packet_len = TX_INJECT_SKB_LEN_DEFAULT;
	tx_inject->cl_sta = NULL;

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		if (cl_sta->is_dummy) {
			free_ba_session(cl_hw, cl_sta);
		} else {
			u8 timeout = TX_BA_SESSION_TIMEOUT;

			ieee80211_stop_tx_ba_session(&cl_sta->stainfo->sta, TX_INJECT_AGG_TID);
			while (cl_sta->agg_tx_queues[TX_INJECT_AGG_TID] && --timeout)
				msleep(200);
		}
	}

	free_all_dummy_sta(cl_hw);
}

static void _cl_tx_inject_start(struct cl_tx_inject *tx_inject,
				u32 max_counter,
				bool continuous,
				bool is_agg)

{
	tx_inject->current_counter = 0;
	tx_inject->max_counter = max_counter;
	tx_inject->continuous = continuous;
	tx_inject->is_agg = is_agg;
	tx_inject->is_running = true;
}

void cl_tx_inject_start(struct cl_hw *cl_hw, u32 tx_cnt)
{
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;

	edca_set_aggressive(cl_hw);

	_cl_tx_inject_start(tx_inject, tx_cnt, false, false);

	if (!tx_inject->cl_sta)
		tx_inject->cl_sta = get_first_sta(cl_hw);

	tasklet_schedule(&tx_inject->tasklet);
}

void cl_tx_inject_start_continuous(struct cl_hw *cl_hw)
{
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;

	edca_set_aggressive(cl_hw);

	_cl_tx_inject_start(tx_inject, 0, true, false);

	if (!tx_inject->cl_sta)
		tx_inject->cl_sta = get_first_sta(cl_hw);

	tasklet_schedule(&tx_inject->tasklet);
}

void cl_tx_inject_start_agg(struct cl_hw *cl_hw, u32 tx_cnt)
{
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;
	struct cl_sta *cl_sta = NULL;

	edca_set_aggressive(cl_hw);

	_cl_tx_inject_start(tx_inject, tx_cnt, false, true);

	if (!tx_inject->cl_sta)
		tx_inject->cl_sta = get_first_sta(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		if (cl_sta->is_dummy) {
			open_ba_session(cl_hw, cl_sta);
		} else {
			u8 timeout = TX_BA_SESSION_TIMEOUT;
			struct ieee80211_sta *sta = &cl_sta->stainfo->sta;

			ieee80211_start_tx_ba_session(sta, TX_INJECT_AGG_TID, 0);
			while (!cl_sta->agg_tx_queues[TX_INJECT_AGG_TID] && --timeout)
				msleep(200);
		}
	}

	tasklet_schedule(&tx_inject->tasklet);
}

static void _cl_tx_inject_stop(struct cl_tx_inject *tx_inject)
{
	tx_inject->current_counter = 0;
	tx_inject->max_counter = 0;
	tx_inject->continuous = false;
	tx_inject->is_agg = false;
	tx_inject->is_running = false;
}

void cl_tx_inject_stop(struct cl_hw *cl_hw)
{
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;
	bool is_agg = tx_inject->is_agg;

	/* Return to default EDCA */
	edca_restore_default(cl_hw);

	_cl_tx_inject_stop(tx_inject);

	if (is_agg) {
		struct cl_sta *cl_sta = NULL;

		list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list)
			stop_ba_session(cl_hw, cl_sta);
	} else {
		if (tx_inject->cl_sta) {
			struct cl_sta *cl_sta = NULL;

			list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
				u16 queue_idx = QUEUE_IDX(cl_sta->sta_idx, TX_INJECT_SINGLE_AC);

				cl_txq_flush_single(cl_hw, queue_idx);
				cl_single_cfm_poll_empty(cl_hw, queue_idx);
			}
		} else {
			cl_txq_flush_single(cl_hw, HIGH_PRIORITY_QUEUE);
			cl_single_cfm_poll_empty(cl_hw, HIGH_PRIORITY_QUEUE);
		}
	}
}

void cl_tx_inject_stop_in_recovery(struct cl_hw *cl_hw)
{
	/*
	 * When recovery starts:
	 *  - change edca back to default
	 *  - stop traffic
	 *  - kill tasklet
	 *  - free stations
	 */
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;

	if (!tx_inject->is_running)
		return;

	pr_debug("[TX inject] Stop due to recovery\n");

	edca_restore_default(cl_hw);

	_cl_tx_inject_stop(tx_inject);

	cl_tx_inject_close(cl_hw);

	cl_hw->ate_db.active = false;
	cl_hw->entry_fixed_rate = false;
}

void cl_tx_inject_stop_traffic(struct cl_hw *cl_hw)
{
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;

	_cl_tx_inject_stop(tx_inject);
}

void cl_tx_inject_stop_ba_session(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 tid)
{
	/* If real station stopped BA session during traffic, stop ATE process. */
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;

	if (cl_sta->is_dummy || !ce_tx_inject_real_sta)
		return;

	if (tx_inject->is_agg &&
	    cl_tx_inject_is_running(cl_hw) &&
	    tid == TX_INJECT_AGG_TID) {
		pr_debug("[TX inject] BA session stopped during traffic - stopping ATE\n");
		cl_ate_stop(cl_hw->hw->wiphy, NULL, NULL, 0);
	}
}

bool cl_tx_inject_is_running(struct cl_hw *cl_hw)
{
	return cl_hw->tx_inject.is_running;
}

static void cl_tx_inject_cfm_single(struct cl_hw *cl_hw)
{
	struct cl_sta *cl_sta = NULL;

	cl_sta_lock(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		u16 queue_idx =  QUEUE_IDX(cl_sta->sta_idx, TX_INJECT_SINGLE_AC);

		cl_txq_single_sched(cl_hw, queue_idx);
	}

	cl_sta_unlock(cl_hw);

	cl_txq_single_sched(cl_hw, HIGH_PRIORITY_QUEUE);
}

void cl_tx_inject_cfm(struct cl_hw *cl_hw)
{
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;
	int alloc_counter = atomic_dec_return(&tx_inject->alloc_counter);

	if (tx_inject->current_counter < tx_inject->max_counter || tx_inject->continuous) {
		/* Schedule the TX inject tasklet to send more packets */
		tasklet_schedule(&tx_inject->tasklet);
		return;
	}

	if (tx_inject->is_running &&
	    alloc_counter == 0 &&
	    tx_inject->current_counter == tx_inject->max_counter) {
		pr_debug("[TX inject] Complete - %u packets\n", tx_inject->max_counter);
		_cl_tx_inject_stop(tx_inject);
		return;
	}

	/*
	 * Packets are waiting in the driver queues to be sent.
	 * Empty the queues and push the packets to firmware.
	 * In case of agg, schedule a tasklet to avoid locking problems.
	 */
	if (tx_inject->is_agg)
		tasklet_schedule(&cl_hw->tx_task);
	else
		cl_tx_inject_cfm_single(cl_hw);
}

void cl_tx_inject_sta_remove(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	/* If real station disconnect during traffic, stop ATE process. */
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;

	if (cl_sta->is_dummy)
		return;

	if (tx_inject->is_agg && cl_tx_inject_is_running(cl_hw)) {
		pr_debug("[TX inject] Station disconnected during traffic - stopping ATE\n");
		cl_ate_stop(cl_hw->hw->wiphy, NULL, NULL, 0);
	}
}

void cl_tx_inject_iface_remove(struct cl_hw *cl_hw, struct cl_vif *cl_vif)
{
	/*
	 * Remove dummy stations when interface is removed (driver must
	 * do it because mac80211 is not aware of the dummy-stations).
	 */
	struct cl_sta *cl_sta = NULL, *cl_sta_tmp = NULL;
	bool iface_dummy_sta = false;

	cl_sta_lock_bh(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		if (cl_sta->is_dummy && cl_sta->cl_vif == cl_vif) {
			iface_dummy_sta = true;
			break;
		}
	}

	cl_sta_unlock_bh(cl_hw);

	if (!iface_dummy_sta)
		return;

	if (cl_tx_inject_is_running(cl_hw)) {
		/*
		 * Stop TX inject to prevent a kernel-panic in cl_tx_inject_alloc_skb()
		 * when it tries to use cl_sta->cl_vif->vif.
		 */
		pr_debug("[TX inject] Interface removed during traffic - stopping ATE\n");
		cl_ate_stop(cl_hw->hw->wiphy, NULL, NULL, 0);
		cl_tx_inject_close(cl_hw);
	} else {
		list_for_each_entry_safe(cl_sta, cl_sta_tmp, &cl_hw->cl_sta_db.head, list)
			if (cl_sta->is_dummy && cl_sta->cl_vif == cl_vif) {
				free_ba_session(cl_hw, cl_sta);
				free_dummy_sta(cl_hw, cl_sta);
			}
	}
}

int cl_tx_inject_set_length(struct cl_hw *cl_hw, u32 length)
{
	if (length >= TX_INJECT_SKB_LEN_MIN && length <= TX_INJECT_SKB_LEN_MAX) {
		cl_hw->tx_inject.packet_len = length;
		return 0;
	}

	pr_debug("[TX inject] Packet length must be between %u and %u\n",
		 TX_INJECT_SKB_LEN_MIN, TX_INJECT_SKB_LEN_MAX);

	return -EINVAL;
}
