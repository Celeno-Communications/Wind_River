// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_ampdu.h"
#include "cl_hw.h"
#include "cl_msg_tx.h"
#include "cl_tx_queue.h"
#include "cl_agg_cfm.h"
#include "cl_recovery.h"
#include "cl_tx_inject.h"
#include "cl_baw.h"
#include "cl_math.h"
#include "cl_band.h"
#include "cl_rx_reorder.h"

int cl_ampdu_rx_start(struct cl_hw *cl_hw,
		      struct cl_sta *cl_sta,
		      u16 tid,
		      u16 ssn,
		      u16 buf_size)
{
	/* @IEEE80211_AMPDU_RX_START: start RX aggregation */
	if (!cl_hw->conf->ci_agg_rx)
		return -EOPNOTSUPP;

	cl_dbg_trace(cl_hw, "sta_idx [%u] tid [%u]\n", cl_sta->sta_idx, tid);

	buf_size = min(buf_size, cl_hw->conf->ce_max_agg_size_rx);

	if (cl_hw->conf->ci_offload_reorder_mode == RX_REORDER_BY_DRIVER)
		cl_rx_reorder_init(cl_hw, cl_sta, tid, buf_size);
	else if (cl_hw->conf->ci_offload_reorder_mode == RX_REORDER_BY_FIRMWARE)
		buf_size = min(buf_size, cl_hw->conf->ci_rx_ampdu_window_size[tid]);

	cl_msg_tx_ba_add(cl_hw, BA_AGMT_RX, cl_sta->sta_idx, tid, buf_size, ssn);

	return 0;
}

void cl_ampdu_rx_stop(struct cl_hw *cl_hw,
		      struct cl_sta *cl_sta,
		      u16 tid)
{
	struct mm_ba_del_cfm *cfm = NULL;

	/* @IEEE80211_AMPDU_RX_STOP: stop RX aggregation */
	cl_dbg_trace(cl_hw, "sta_idx [%u] tid [%u]\n", cl_sta->sta_idx, tid);

	if (cl_hw->conf->ci_offload_reorder_mode == RX_REORDER_BY_DRIVER)
		cl_rx_reorder_close(cl_sta, tid);

	/* Send MM_BA_DEL_REQ message to firmware */
	if (cl_msg_tx_ba_del(cl_hw, BA_AGMT_RX, cl_sta->sta_idx, tid))
		return;

	cfm = (struct mm_ba_del_cfm *)(cl_hw->msg_cfm_params[MM_BA_DEL_CFM]);

	/* Check confirmation status */
	if (cfm->status != BA_AGMT_DELETED && cfm->status != BA_AGMT_DOES_NOT_EXIST)
		cl_dbg_verbose(cl_hw, "Status Error (%u)\n", cfm->status);

	cl_msg_tx_free_cfm_params(cl_hw, MM_BA_DEL_CFM);
}

int cl_ampdu_tx_start(struct cl_hw *cl_hw,
		      struct ieee80211_vif *vif,
		      struct cl_sta *cl_sta,
		      u16 tid,
		      u16 ssn)
{
	/* @IEEE80211_AMPDU_TX_START: start TX aggregation */
	struct mm_available_ba_txq_cfm *cfm = NULL;
	int ret;

	if (!ieee80211_hw_check(cl_hw->hw, AMPDU_AGGREGATION) || !cl_hw->conf->ci_agg_tx)
		return -EOPNOTSUPP;

	if (!cl_txq_is_agg_available(cl_hw)) {
		cl_dbg_warn(cl_hw, "No free aggregation queue for sta_idx [%u] tid [%u]\n",
			    cl_sta->sta_idx, tid);
		return -ENOSPC;
	}

	ret = cl_msg_tx_available_ba_txq(cl_hw, cl_sta->sta_idx, tid);
	if (ret)
		return ret;

	/* Read FW confirm message */
	cfm = (struct mm_available_ba_txq_cfm *)(cl_hw->msg_cfm_params[MM_AVAILABLE_BA_TXQ_CFM]);

	/* Check if status is valid */
	if (cfm->status != BA_TXQUEUE_INVALID && cfm->status != BA_TXQUEUE_VALID) {
		cl_dbg_verbose(cl_hw, "Status Error (%u)\n", cfm->status);
		cl_msg_tx_free_cfm_params(cl_hw, MM_AVAILABLE_BA_TXQ_CFM);
		return -EIO;
	}

	if (cfm->status == BA_TXQUEUE_INVALID) {
		cl_dbg_warn(cl_hw, "BA_TXQUEUE_INVALID - sta_idx [%u] tid [%u]\n",
			    cfm->sta_idx, cfm->tid);
		cl_msg_tx_free_cfm_params(cl_hw, MM_AVAILABLE_BA_TXQ_CFM);
		return -EINVAL;
	}

	cl_msg_tx_free_cfm_params(cl_hw, MM_AVAILABLE_BA_TXQ_CFM);
	cl_txq_agg_request_add(cl_hw, cl_sta->sta_idx, tid);
	cl_baw_start(&cl_sta->baws[tid], ssn);

	/* Mandatory callback once setup preparations are done at lower level */
	ieee80211_start_tx_ba_cb_irqsafe(vif, cl_sta->addr, tid);

	return 0;
}

int cl_ampdu_tx_operational(struct cl_hw *cl_hw,
			    struct cl_sta *cl_sta,
			    u16 tid,
			    u16 buf_size,
			    bool amsdu_supported)
{
	/* @IEEE80211_AMPDU_TX_OPERATIONAL: TX aggregation has become operational */
	struct mm_ba_add_cfm *cfm = NULL;
	struct cl_baw *baw = &cl_sta->baws[tid];
	u16 ssn = baw->ssn;
	int ret;

	buf_size = min(buf_size, cl_hw->conf->ce_max_agg_size_tx);

	/* Send MM_BA_ADD_TX_REQ message to firmware */
	ret = cl_msg_tx_ba_add(cl_hw, BA_AGMT_TX, cl_sta->sta_idx, tid, buf_size, ssn);
	if (ret)
		return ret;

	/* Handle message confirmation */
	cfm = (struct mm_ba_add_cfm *)(cl_hw->msg_cfm_params[MM_BA_ADD_TX_CFM]);

	if (cfm->status != BA_AGMT_ESTABLISHED) {
		cl_dbg_verbose(cl_hw, "Status Error (%u)\n", cfm->status);
		cl_msg_tx_free_cfm_params(cl_hw, MM_BA_ADD_TX_CFM);
		cl_txq_agg_request_del(cl_hw, cl_sta->sta_idx, tid);
		return -EIO;
	}

	cl_baw_operational(cl_hw, baw, cfm->agg_idx, amsdu_supported);
	cl_agg_cfm_set_ssn(cl_hw, ssn, cfm->agg_idx);

	if (amsdu_supported)
		cl_tx_amsdu_set_max_len(cl_hw, cl_sta, tid);
	else
		cl_dbg_trace(cl_hw, "AMSDU not supported - sta_idx=%u\n", cl_sta->sta_idx);

	cl_txq_agg_alloc(cl_hw, cl_sta, cfm, buf_size);
	cl_msg_tx_free_cfm_params(cl_hw, MM_BA_ADD_TX_CFM);

	return 0;
}

void _cl_ampdu_tx_stop(struct cl_hw *cl_hw,
		       struct cl_tx_queue *tx_queue,
		       struct cl_sta *cl_sta,
		       u8 tid)
{
	struct mm_ba_del_cfm *cfm = NULL;
	u8 fw_agg_idx = tx_queue->index;

	if (cl_recovery_in_progress(cl_hw))
		goto out;

	/*
	 * TX stop flow:
	 * 1) Flush TX queues - done in cl_ampdu_tx_stop()
	 * 2) Poll confirmation queue and clear enhanced TIM
	 * 3) Send MM_STA_DEL_REQ message to firmware
	 * 4) Poll again confirmation and flush confirmation queue
	 * 5) Reset write index
	 */
	cl_agg_cfm_poll_empty(cl_hw, fw_agg_idx, false);

	/* Send MM_BA_DEL_REQ message to firmware */
	if (cl_msg_tx_ba_del(cl_hw, BA_AGMT_TX, cl_sta->sta_idx, tid))
		goto out;

	cfm = (struct mm_ba_del_cfm *)(cl_hw->msg_cfm_params[MM_BA_DEL_CFM]);

	/* Check confirmation status */
	if (cfm->status != BA_AGMT_DELETED && cfm->status != BA_AGMT_DOES_NOT_EXIST)
		cl_dbg_verbose(cl_hw, "Status Error (%u)\n", cfm->status);

	cl_msg_tx_free_cfm_params(cl_hw, MM_BA_DEL_CFM);

out:
	cl_agg_cfm_poll_empty(cl_hw, fw_agg_idx, true);
	cl_txq_agg_free(cl_hw, tx_queue, cl_sta, tid);

	/* Reset the synchronization counters between the fw and the IPC layer */

	cl_hw->ipc_write_idx.txdesc_write_idx->agg[fw_agg_idx] = 0;
}

int cl_ampdu_tx_stop(struct cl_hw *cl_hw,
		     struct ieee80211_vif *vif,
		     enum ieee80211_ampdu_mlme_action action,
		     struct cl_sta *cl_sta,
		     u16 tid)
{
	/*
	 * @IEEE80211_AMPDU_TX_STOP_CONT: stop TX aggregation but continue transmitting
	 *	queued packets, now unaggregated. After all packets are transmitted the
	 *	driver has to call ieee80211_stop_tx_ba_cb_irqsafe().
	 * @IEEE80211_AMPDU_TX_STOP_FLUSH: stop TX aggregation and flush all packets,
	 *	called when the station is removed. There's no need or reason to call
	 *	ieee80211_stop_tx_ba_cb_irqsafe() in this case as mac80211 assumes the
	 *	session is gone and removes the station.
	 * @IEEE80211_AMPDU_TX_STOP_FLUSH_CONT: called when TX aggregation is stopped
	 *	but the driver hasn't called ieee80211_stop_tx_ba_cb_irqsafe() yet and
	 *	now the connection is dropped and the station will be removed. Drivers
	 *	should clean up and drop remaining packets when this is called.
	 */

	/* !!!  Comment in agg-tx.c, ___ieee80211_stop_tx_ba_session():  !!!
	 * !!!  HW shall not deny going back to legacy                   !!!
	 * !!!  Therefore cl_ampdu_tx_stop() always returns 0            !!!
	 */

	struct cl_tx_queue *tx_queue = cl_sta->agg_tx_queues[tid];
	struct cl_baw *baw = &cl_sta->baws[tid];

	spin_lock_bh(&cl_hw->tx_lock_agg);

	cl_baw_stop(baw);
	cl_txq_agg_request_del(cl_hw, cl_sta->sta_idx, tid);

	/* Check if BA session exist */
	if (!tx_queue) {
		cl_baw_pending_purge(baw);
		spin_unlock_bh(&cl_hw->tx_lock_agg);

		if (!cl_recovery_in_progress(cl_hw))
			cl_dbg_warn(cl_hw, "Queue doesn't exist - sta_idx [%u] tid [%u]\n",
				    cl_sta->sta_idx, tid);

		goto out;
	}

	if (action == IEEE80211_AMPDU_TX_STOP_CONT) {
		/*
		 * The order of flow here is very important here to avoid reorder problem!
		 * 1) Take single lock to block single traffic
		 * 2) Stop agg traffic.
		 * 3) Transfer agg-to-single and push all skbs from agg queue to single queue.
		 * 4) Transfer BA window pending queue to single queue.
		 * 5) Release single lock
		 */
		spin_lock_bh(&cl_hw->tx_lock_single);
		cl_txq_agg_stop(cl_sta, tid);
		cl_txq_transfer_agg_to_single(cl_hw, tx_queue);
		cl_baw_pending_to_single(cl_hw, cl_sta, baw);
		spin_unlock_bh(&cl_hw->tx_lock_single);
	} else {
		cl_txq_agg_stop(cl_sta, tid);
		cl_txq_flush_agg(cl_hw, tx_queue, false);
		cl_baw_pending_purge(baw);
	}

	cl_tx_amsdu_anchor_reset(&cl_sta->amsdu_anchor[tid]);

	spin_unlock_bh(&cl_hw->tx_lock_agg);

	cl_tx_inject_stop_ba_session(cl_hw, cl_sta, tid);

	_cl_ampdu_tx_stop(cl_hw, tx_queue, cl_sta, tid);

out:
	/* Mandatory callback once we've made our own tear down ops */
	if (action != IEEE80211_AMPDU_TX_STOP_FLUSH)
		ieee80211_stop_tx_ba_cb_irqsafe(vif, cl_sta->addr, tid);

	return 0;
}

#define HE_MAC_CAP3_MAX_AMPDU_LEN_EXP_OFFSET 3
#define HE_EXP_MAX 22 /* 2 ^ 22 = 4194304 < 6500631 */

static void _cl_ampdu_size_exp(struct ieee80211_sta *sta,
			       u8 *ampdu_exp_he,
			       u8 *ampdu_exp_vht,
			       u8 *ampdu_exp_ht)
{
	struct ieee80211_sta_he_cap *he_cap = &sta->he_cap;
	u8 mac_cap_info3 = he_cap->he_cap_elem.mac_cap_info[3];
	u32 he_exp;

	if (sta->ht_cap.ht_supported)
		*ampdu_exp_ht = IEEE80211_HT_MAX_AMPDU_FACTOR + sta->ht_cap.ampdu_factor;

	if (sta->vht_cap.vht_supported) {
		u32 vht_exp = (sta->vht_cap.cap &
			       IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_MASK) >>
			IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_SHIFT;

		*ampdu_exp_vht = IEEE80211_HT_MAX_AMPDU_FACTOR + vht_exp;
	}

	he_exp = (mac_cap_info3 & IEEE80211_HE_MAC_CAP3_MAX_AMPDU_LEN_EXP_MASK) >>
		HE_MAC_CAP3_MAX_AMPDU_LEN_EXP_OFFSET;

	if (sta->vht_cap.vht_supported) {
		if (he_exp)
			*ampdu_exp_he = min(IEEE80211_HE_VHT_MAX_AMPDU_FACTOR +
					    he_exp, (u32)HE_EXP_MAX);
		else
			*ampdu_exp_he = *ampdu_exp_vht;
	} else if (sta->ht_cap.ht_supported) {
		if (he_exp)
			*ampdu_exp_he = IEEE80211_HE_HT_MAX_AMPDU_FACTOR + he_exp;
		else
			*ampdu_exp_he = *ampdu_exp_ht;
	}
}

static void _cl_ampdu_size_exp_6g(struct ieee80211_sta *sta, u8 *ampdu_exp_he)
{
	u8 mac_cap_info3 = sta->he_cap.he_cap_elem.mac_cap_info[3];
	u32 he_exp_ext = (mac_cap_info3 &
			  IEEE80211_HE_MAC_CAP3_MAX_AMPDU_LEN_EXP_MASK) >>
			  HE_MAC_CAP3_MAX_AMPDU_LEN_EXP_OFFSET;

	if (he_exp_ext) {
		*ampdu_exp_he = min(IEEE80211_HE_VHT_MAX_AMPDU_FACTOR +
				    he_exp_ext, (u32)HE_EXP_MAX);
	} else {
		struct ieee80211_he_6ghz_capa *he_6g_cap = &sta->he_6ghz_capa;
		u32 he_exp_6ghz = (le16_to_cpu(he_6g_cap->capa) &
				   HE_6GHZ_CAP_MAX_AMPDU_LEN_EXP_MASK) >>
			HE_6GHZ_CAP_MAX_AMPDU_LEN_EXP_OFFSET;

		*ampdu_exp_he = min(HE_6GHZ_CAP_MAX_AMPDU_LEN_FACTOR +
				    he_exp_6ghz, (u32)HE_EXP_MAX);
	}
}

void cl_ampdu_size_exp(struct cl_hw *cl_hw, struct ieee80211_sta *sta,
		       u8 *ampdu_exp_he, u8 *ampdu_exp_vht, u8 *ampdu_exp_ht)
{
	if (cl_band_is_6g(cl_hw))
		_cl_ampdu_size_exp_6g(sta, ampdu_exp_he);
	else
		_cl_ampdu_size_exp(sta, ampdu_exp_he,
				   ampdu_exp_vht, ampdu_exp_ht);

	cl_dbg_info(cl_hw, "ampdu_size_exp: he = %u, vht = %u, ht = %u\n",
		    *ampdu_exp_he, *ampdu_exp_vht, *ampdu_exp_ht);
}

