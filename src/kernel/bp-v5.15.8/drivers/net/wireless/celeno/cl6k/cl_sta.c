// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_sta.h"
#include "cl_rssi.h"
#include "cl_bf.h"
#include "cl_stats.h"
#include "cl_rx_sens.h"
#include "cl_vw.h"
#include "cl_wrs_api.h"
#include "cl_utils.h"
#include "cl_band.h"
#include "cl_vns.h"
#include "cl_radio.h"
#include "cl_tx_inject.h"
#include "cl_twt.h"
#include "cl_mac_addr.h"
#include "cl_bsr.h"
#include "cl_baw.h"
#include "cl_recovery.h"
#include "cl_tx_queue.h"
#include "cl_single_cfm.h"
#include "cl_dyn_mcast_rate.h"
#include "cl_dyn_bcast_rate.h"
#include "chip.h"
#include "cl_bsrp.h"
#include "cl_ul_rssi.h"
#include "cl_msg_tx.h"
#include "cl_netlink.h"

#ifdef CONFIG_CL_USB
#define CL_HT_MPDU_DENSITY  IEEE80211_HT_MPDU_DENSITY_4
#else
#define CL_HT_MPDU_DENSITY  IEEE80211_HT_MPDU_DENSITY_2
#endif

void cl_sta_init(struct cl_hw *cl_hw)
{
	u32 i;

	rwlock_init(&cl_hw->cl_sta_db.lock);
	INIT_LIST_HEAD(&cl_hw->cl_sta_db.head);

	for (i = 0; i < CL_STA_HASH_SIZE; i++)
		INIT_LIST_HEAD(&cl_hw->cl_sta_db.hash[i]);
}

int cl_sta_init_stainfo(struct cl_hw *cl_hw, struct sta_info *stainfo)
{
	struct cl_sta *cl_sta = STA_INFO_TO_CL_STA(stainfo);

	if (cl_recovery_in_progress(cl_hw) && !cl_sta->stainfo)
		return -EPERM;

	if (!cl_recovery_in_progress(cl_hw)) {
		/* Reset all cl_sta strcture */
		memset(cl_sta, 0, sizeof(struct cl_sta));
		cl_sta->stainfo = stainfo;
		/*
		 * Set sta_idx to 0xFF since FW expects this value as long as
		 * the STA is not fully connected
		 */
		cl_sta->sta_idx = STA_IDX_INVALID;
	}

	return 0;
}

static void cl_sta_add_to_lut(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cl_sta *cl_sta)
{
	write_lock_bh(&cl_hw->cl_sta_db.lock);

	cl_hw->cl_sta_db.num++;
	cl_vif->num_sta++;
	cl_hw->cl_sta_db.lut[cl_sta->sta_idx] = cl_sta;

	/* Done here inside the lock because it allocates cl_stats */
	cl_stats_sta_add(cl_hw, cl_sta);

	write_unlock_bh(&cl_hw->cl_sta_db.lock);

	cl_dbg_verbose(cl_hw, "mac=%pM, sta_idx=%u, vif_index=%u\n",
		       cl_sta->addr, cl_sta->sta_idx, cl_sta->cl_vif->vif_index);
}

static void cl_sta_add_to_list(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	u8 hash_idx = CL_STA_HASH_IDX(cl_sta->addr[5]);

	write_lock_bh(&cl_hw->cl_sta_db.lock);

	/* Add to hash table */
	list_add(&cl_sta->list_hash, &cl_hw->cl_sta_db.hash[hash_idx]);

	/* Make sure that cl_sta's are stored in the list according to their sta_idx. */
	if (list_empty(&cl_hw->cl_sta_db.head)) {
		list_add(&cl_sta->list, &cl_hw->cl_sta_db.head);
	} else if (list_is_singular(&cl_hw->cl_sta_db.head)) {
		struct cl_sta *cl_sta_singular =
			list_first_entry(&cl_hw->cl_sta_db.head, struct cl_sta, list);

		if (cl_sta_singular->sta_idx < cl_sta->sta_idx)
			list_add_tail(&cl_sta->list, &cl_hw->cl_sta_db.head);
		else
			list_add(&cl_sta->list, &cl_hw->cl_sta_db.head);
	} else {
		struct cl_sta *cl_sta_last =
			list_last_entry(&cl_hw->cl_sta_db.head, struct cl_sta, list);

		if (cl_sta->sta_idx > cl_sta_last->sta_idx) {
			list_add_tail(&cl_sta->list, &cl_hw->cl_sta_db.head);
		} else {
			struct cl_sta *cl_sta_next = NULL;
			struct cl_sta *cl_sta_prev = NULL;

			list_for_each_entry(cl_sta_next, &cl_hw->cl_sta_db.head, list) {
				if (cl_sta_next->sta_idx < cl_sta->sta_idx)
					continue;

				cl_sta_prev = list_prev_entry(cl_sta_next, list);
				__list_add(&cl_sta->list, &cl_sta_prev->list, &cl_sta_next->list);
				break;
			}
		}
	}

	write_unlock_bh(&cl_hw->cl_sta_db.lock);

	cl_sta->add_complete = true;
}

static void cl_connection_data_add(struct cl_vif *cl_vif)
{
	struct cl_connection_data *conn_data = cl_vif->conn_data;

	if (cl_vif->num_sta > conn_data->max_client) {
		conn_data->max_client = cl_vif->num_sta;
		conn_data->max_client_timestamp = ktime_get_real_seconds();
	}

	if (cl_vif->num_sta == conn_data->watermark_threshold)
		conn_data->watermark_reached_cnt++;
}

static void cl_connection_data_remove(struct cl_vif *cl_vif)
{
	struct cl_connection_data *conn_data = cl_vif->conn_data;

	if (cl_vif->num_sta == conn_data->watermark_threshold)
		conn_data->watermark_reached_cnt++;
}

static void _cl_sta_add(struct cl_hw *cl_hw, struct ieee80211_vif *vif, struct ieee80211_sta *sta)
{
	struct cl_vif *cl_vif = (struct cl_vif *)vif->drv_priv;
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);

	/* !!! Must be first !!! */
	cl_sta_add_to_lut(cl_hw, cl_vif, cl_sta);

	cl_baw_init(cl_sta);
	cl_txq_sta_add(cl_hw, cl_sta);
	cl_vns_sta_add(cl_hw, cl_sta);
	cl_connection_data_add(cl_vif);

	/*
	 * Add rssi of association request to rssi pool
	 * Make sure to call it before cl_wrs_api_sta_add()
	 */
	cl_rssi_assoc_find(cl_hw, cl_sta, cl_hw->cl_sta_db.num);

	cl_bf_sta_add(cl_hw, cl_sta, sta);
	cl_wrs_api_sta_add(cl_hw, sta);
	cl_wrs_api_set_smps_mode(cl_hw, sta,
				 cl_sta->stainfo->cur_max_bandwidth);
	/* Should be called after cl_wrs_api_sta_add() */
	cl_dyn_mcast_rate_update_upon_assoc(cl_hw, cl_sta->wrs_sta.mode,
					    cl_hw->cl_sta_db.num);
	cl_dyn_bcast_rate_update_upon_assoc(cl_hw,
					    cl_sta->wrs_sta.tx_su_params.rate_params.mcs,
					    cl_hw->cl_sta_db.num);
	cl_bsr_counters_reset(cl_hw);
	cl_bsrp_set_su_ul(cl_hw, cl_sta);
	cl_ul_rssi_sta_init(cl_hw, cl_sta);

	/* !!! Must be last !!! */
	cl_sta_add_to_list(cl_hw, cl_sta);
}

static void __cl_sta_remove(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	write_lock_bh(&cl_hw->cl_sta_db.lock);

	list_del(&cl_sta->list);
	list_del(&cl_sta->list_hash);

	cl_hw->cl_sta_db.lut[cl_sta->sta_idx] = NULL;
	cl_hw->cl_sta_db.num--;
	cl_sta->cl_vif->num_sta--;

	cl_dbg_verbose(cl_hw, "mac=%pM, sta_idx=%u, vif_index=%u\n",
		       cl_sta->addr, cl_sta->sta_idx, cl_sta->cl_vif->vif_index);

	write_unlock_bh(&cl_hw->cl_sta_db.lock);
}

static void _cl_sta_remove(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cl_sta *cl_sta)
{
	cl_sta->remove_start = true;

	/* !!! Must be first - remove from list and LUT !!! */
	__cl_sta_remove(cl_hw, cl_sta);

	cl_traffic_sta_remove(cl_hw, cl_sta);
	cl_bf_sta_remove(cl_sta);
	cl_connection_data_remove(cl_vif);
	cl_dyn_mcast_rate_update_upon_disassoc(cl_hw,
					       cl_sta->wrs_sta.mode,
					       cl_hw->cl_sta_db.num);
	cl_dyn_bcast_rate_update_upon_disassoc(cl_hw,
					       cl_sta->wrs_sta.tx_su_params.rate_params.mcs,
					       cl_hw->cl_sta_db.num);
	cl_wrs_api_sta_remove(cl_hw, cl_sta);
	cl_vw_sta_remove(cl_hw, cl_sta, cl_hw->cl_sta_db.num);
	cl_tx_inject_sta_remove(cl_hw, cl_sta);
	cl_twt_sta_remove(cl_hw, cl_sta);
	cl_stats_sta_remove(cl_hw, cl_sta);

	/* Flush existing frames and cfms of this removed STA */
	cl_txq_flush_sta(cl_hw, cl_sta);
	cl_single_cfm_poll_empty_sta(cl_hw, cl_sta->sta_idx);
	cl_txq_sta_remove(cl_hw, cl_sta->sta_idx);

	if (cl_vif->vif->type == NL80211_IFTYPE_MESH_POINT &&
	    cl_vif->num_sta == 0) {
		cl_sta_disassociate_ap_iface(cl_hw);
		cl_vif_ap_tx_enable(cl_hw, false);
		clear_bit(CL_DEV_MESH_AP, &cl_hw->drv_flags);
	}
}

static void cl_sta_disassociate(struct cl_hw *cl_hw, bool ap_only)
{
	struct cl_vif *cl_vif, *tmp;
	u8 macaddr[ETH_ALEN];

	memset(macaddr, 0xff, ETH_ALEN);

	/* Disassociate all associated stations */
	list_for_each_entry_safe(cl_vif, tmp, &cl_hw->vif_db.head, list) {
		if (ap_only && cl_vif->vif->type != NL80211_IFTYPE_AP)
			continue;
		cl_netlink_send_event_disassoc(cl_vif, macaddr);
	}
}

/*
 * Parse the ampdu density to retrieve the value in usec, according to
 * the values defined in ieee80211.h
 */
static u8 cl_sta_density2usec(u8 ampdu_density)
{
	switch (ampdu_density) {
	case IEEE80211_HT_MPDU_DENSITY_NONE:
		return 0;
		/* 1 microsecond is our granularity */
	case IEEE80211_HT_MPDU_DENSITY_0_25:
	case IEEE80211_HT_MPDU_DENSITY_0_5:
	case IEEE80211_HT_MPDU_DENSITY_1:
		return 1;
	case IEEE80211_HT_MPDU_DENSITY_2:
		return 2;
	case IEEE80211_HT_MPDU_DENSITY_4:
		return 4;
	case IEEE80211_HT_MPDU_DENSITY_8:
		return 8;
	case IEEE80211_HT_MPDU_DENSITY_16:
		return 16;
	default:
		return 0;
	}
}

static void cl_sta_set_min_spacing(struct cl_hw *cl_hw,
				   struct ieee80211_sta *sta)
{
	bool is_6g = cl_band_is_6g(cl_hw);
	u8 mpdu_dens = 0;
	u8 sta_min_spacing = 0;
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);

	if (is_6g) {
		mpdu_dens = le16_get_bits(sta->he_6ghz_capa.capa,
					  IEEE80211_HE_6GHZ_CAP_MIN_MPDU_START);
		sta_min_spacing = cl_sta_density2usec(mpdu_dens);
	} else if (sta->ht_cap.ht_supported) {
		mpdu_dens = sta->ht_cap.ampdu_density;
		sta_min_spacing = cl_sta_density2usec(mpdu_dens);
	} else {
		cl_dbg_err(cl_hw, "HT is not supported - cannot set sta_min_spacing\n");
	}

	cl_sta->ampdu_min_spacing =
			max(cl_sta_density2usec(CL_HT_MPDU_DENSITY),
			    sta_min_spacing);
}

u32 cl_sta_num(struct cl_hw *cl_hw)
{
	u32 num = 0;

	read_lock(&cl_hw->cl_sta_db.lock);
	num = cl_hw->cl_sta_db.num;
	read_unlock(&cl_hw->cl_sta_db.lock);

	return num;
}

u32 cl_sta_num_bh(struct cl_hw *cl_hw)
{
	u32 num = 0;

	read_lock_bh(&cl_hw->cl_sta_db.lock);
	num = cl_hw->cl_sta_db.num;
	read_unlock_bh(&cl_hw->cl_sta_db.lock);

	return num;
}

bool cl_sta_is_assoc(struct cl_hw *cl_hw, u8 sta_idx)
{
	bool is_assoc = false;

	if (sta_idx < CL_MAX_NUM_STA) {
		read_lock_bh(&cl_hw->cl_sta_db.lock);
		is_assoc = cl_hw->cl_sta_db.lut[sta_idx] ? true : false;
		read_unlock_bh(&cl_hw->cl_sta_db.lock);
	}

	return is_assoc;
}

struct cl_sta *cl_sta_get(struct cl_hw *cl_hw, u8 sta_idx)
{
	if (sta_idx < CL_MAX_NUM_STA)
		return cl_hw->cl_sta_db.lut[sta_idx];

	return NULL;
}

struct cl_sta *cl_sta_get_by_addr(struct cl_hw *cl_hw, u8 *addr)
{
	struct cl_sta *cl_sta = NULL;
	u8 hash_idx = CL_STA_HASH_IDX(addr[5]);

	if (is_multicast_ether_addr(addr))
		return NULL;

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.hash[hash_idx], list_hash)
		if (cl_mac_addr_compare(cl_sta->addr, addr))
			return cl_sta;

	return NULL;
}

void cl_sta_loop(struct cl_hw *cl_hw, sta_callback callback)
{
	struct cl_sta *cl_sta = NULL;

	/* Go over all stations */
	read_lock(&cl_hw->cl_sta_db.lock);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list)
		callback(cl_hw, cl_sta);

	read_unlock(&cl_hw->cl_sta_db.lock);
}

void cl_sta_loop_bh(struct cl_hw *cl_hw, sta_callback callback)
{
	struct cl_sta *cl_sta = NULL;

	/* Go over all stations - use bottom-half lock */
	read_lock_bh(&cl_hw->cl_sta_db.lock);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list)
		callback(cl_hw, cl_sta);

	read_unlock_bh(&cl_hw->cl_sta_db.lock);
}

void cl_sta_loop_safe(struct cl_hw *cl_hw, sta_callback callback)
{
	struct cl_sta *cl_sta = NULL;
	struct cl_sta *cl_sta_tmp = NULL;

	/* Go over all stations */
	read_lock(&cl_hw->cl_sta_db.lock);

	list_for_each_entry_safe(cl_sta, cl_sta_tmp, &cl_hw->cl_sta_db.head, list)
		callback(cl_hw, cl_sta);

	read_unlock(&cl_hw->cl_sta_db.lock);
}

static int cl_sta_add_to_firmware(struct cl_hw *cl_hw, struct ieee80211_vif *vif,
				  struct ieee80211_sta *sta)
{
	struct cl_sta *cl_sta = (struct cl_sta *)sta->drv_priv;
	struct cl_vif *cl_vif = (struct cl_vif *)vif->drv_priv;
	struct mm_sta_add_cfm *sta_add_cfm;
	int error = 0;
	u8 recovery_sta_idx = 0;
	u32 rate_ctrl_info = 0;

	if (cl_recovery_in_progress(cl_hw)) {
		struct cl_wrs_rate_params *rate_params = &cl_sta->wrs_sta.tx_su_params.rate_params;

		/*
		 * If station is added to firmware during recovery, the driver passes to firmware
		 * the station index to be used instead of firmware selecting a free index
		 */
		recovery_sta_idx = cl_sta->sta_idx;

		/* Keep current rate value */
		rate_ctrl_info = cl_rate_ctrl_generate(cl_hw, cl_sta, rate_params->mode,
						       rate_params->bw, rate_params->nss,
						       rate_params->mcs, rate_params->gi,
						       false);
	} else {
		bool is_cck = cl_band_is_24g(cl_hw) && cl_hw_mode_is_b_or_bg(cl_hw);
		u8 mode = is_cck ? WRS_MODE_CCK : WRS_MODE_OFDM;

		/*
		 * Not in recovery:
		 * firmware will set sta_idx and will return in confirmation message
		 */
		recovery_sta_idx = STA_IDX_INVALID;

		/* Default rate value */
		rate_ctrl_info = cl_rate_ctrl_generate(cl_hw, cl_sta, mode,
						       0, 0, 0, 0, false);
	}

	/* Must be called before cl_msg_tx_sta_add() */
	cl_sta_set_min_spacing(cl_hw, sta);

	/* Send message to firmware */
	error = cl_msg_tx_sta_add(cl_hw, sta, cl_vif, recovery_sta_idx, rate_ctrl_info);
	if (error)
		return error;

	sta_add_cfm = (struct mm_sta_add_cfm *)(cl_hw->msg_cfm_params[MM_STA_ADD_CFM]);

	if (sta_add_cfm->status != 0) {
		cl_dbg_verbose(cl_hw, "Status Error (%u)\n", sta_add_cfm->status);
		cl_msg_tx_free_cfm_params(cl_hw, MM_STA_ADD_CFM);
		return -EIO;
	}

	/* Save the index retrieved from firmware */
	cl_sta->sta_idx = sta_add_cfm->sta_idx;

	/* Release cfm msg */
	cl_msg_tx_free_cfm_params(cl_hw, MM_STA_ADD_CFM);

	return 0;
}

int cl_sta_add(struct cl_hw *cl_hw, struct ieee80211_vif *vif,
	       struct ieee80211_sta *sta)
{
	struct cl_sta *cl_sta = (struct cl_sta *)sta->drv_priv;
	struct cl_vif *cl_vif = (struct cl_vif *)vif->drv_priv;
	int error = 0;

	if (cl_radio_is_going_down(cl_hw))
		return -EPERM;

	cl_sta->cl_vif = cl_vif;
	cl_mac_addr_copy(cl_sta->addr, sta->addr);

	error = cl_sta_add_to_firmware(cl_hw, vif, sta);
	if (error)
		return error;

	if (!cl_recovery_in_progress(cl_hw))
		if (vif->type != NL80211_IFTYPE_STATION ||
		    cl_hw->chip->conf->ce_production_mode)
			_cl_sta_add(cl_hw, vif, sta);

	if (vif->type == NL80211_IFTYPE_MESH_POINT &&
	    cl_vif->num_sta == 1) {
		cl_vif_ap_tx_enable(cl_hw, true);
		set_bit(CL_DEV_MESH_AP, &cl_hw->drv_flags);
	}

	return 0;
}

void cl_sta_mgd_add(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct ieee80211_sta *sta)
{
	/* Should be called in station mode */
	struct cl_sta *cl_sta = (struct cl_sta *)sta->drv_priv;

	/* !!! Must be first !!! */
	cl_sta_add_to_lut(cl_hw, cl_vif, cl_sta);

	cl_baw_init(cl_sta);
	cl_txq_sta_add(cl_hw, cl_sta);
	cl_vns_sta_add(cl_hw, cl_sta);

	/*
	 * Add rssi of association response to rssi pool
	 * Make sure to call it before cl_wrs_api_sta_add()
	 */
	cl_rssi_assoc_find(cl_hw, cl_sta, cl_hw->cl_sta_db.num);

	cl_connection_data_add(cl_vif);

	cl_bf_sta_add(cl_hw, cl_sta, sta);
	cl_wrs_api_sta_add(cl_hw, sta);
	/* Should be called after cl_wrs_api_sta_add() */
	cl_dyn_mcast_rate_update_upon_assoc(cl_hw, cl_sta->wrs_sta.mode,
					    cl_hw->cl_sta_db.num);
	cl_dyn_bcast_rate_update_upon_assoc(cl_hw,
					    cl_sta->wrs_sta.tx_su_params.rate_params.mcs,
					    cl_hw->cl_sta_db.num);
	cl_bsr_counters_reset(cl_hw);

	/* !!! Must be last !!! */
	cl_sta_add_to_list(cl_hw, cl_sta);
}

int cl_sta_remove(struct cl_hw *cl_hw, struct ieee80211_vif *vif, struct ieee80211_sta *sta)
{
	struct cl_vif *cl_vif = (struct cl_vif *)vif->drv_priv;
	struct cl_sta *cl_sta = (struct cl_sta *)sta->drv_priv;
	int ret = 0;

	_cl_sta_remove(cl_hw, cl_vif, cl_sta);

	ret = cl_msg_tx_sta_del(cl_hw, cl_sta->sta_idx);

	if (cl_hw->assert_info.restart_needed)
		ret = 0;

	if (cl_vif->num_sta == 0)
		cl_radio_off_wake_up(cl_hw);

	return ret;
}

void cl_sta_disassociate_all(struct cl_hw *cl_hw)
{
	/* Disassociate all associated stations (AP + STA mode) */
	cl_sta_disassociate(cl_hw, false);
}

void cl_sta_disassociate_ap_iface(struct cl_hw *cl_hw)
{
	/* Disassociate all AP associated stations (AP mode only) */
	cl_sta_disassociate(cl_hw, true);
}

void cl_sta_ps_notify(struct cl_hw *cl_hw, struct cl_sta *cl_sta, bool is_ps)
{
	/*
	 * PS-Poll & UAPSD are handled by FW, by setting
	 * WLAN_STA_SP we ensure mac80211 does not re-handle.
	 * flag is unset at ieee80211_sta_ps_deliver_wakeup
	 */
	if (is_ps)
		set_sta_flag(cl_sta->stainfo, WLAN_STA_SP);

	cl_stats_update_ps(cl_hw, cl_sta, is_ps);
}

