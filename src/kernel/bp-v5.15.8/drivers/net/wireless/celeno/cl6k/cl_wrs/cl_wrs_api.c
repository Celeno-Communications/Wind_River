// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_wrs_api.h"
#include "cl_wrs.h"
#include "cl_wrs_sta.h"
#include "cl_wrs_ap.h"
#include "cl_wrs_cli.h"
#include "cl_rate_ctrl.h"
#include "cl_prot_mode.h"
#include "cl_utils.h"
#include "cl_sta.h"
#include "cl_data_rates.h"
#include "cl_msg_tx.h"

void cl_wrs_api_init(struct cl_hw *cl_hw)
{
	cl_wrs_init(cl_hw);
	cl_wrs_ap_capab_set(cl_hw);
}

void cl_wrs_api_close(struct cl_hw *cl_hw)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;

	cancel_delayed_work_sync(&wrs_db->work_maintenance);
}

void cl_wrs_api_sta_add(struct cl_hw *cl_hw, struct ieee80211_sta *sta)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;

	cl_wrs_lock_bh(wrs_db);
	cl_wrs_sta_add(cl_hw, sta);

	if (sta->he_cap.has_he && cl_hw->conf->ce_wrs_rx_en)
		cl_wrs_sta_add_rx(cl_hw, sta);

	cl_wrs_unlock_bh(wrs_db);
}

void cl_wrs_api_sta_remove(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;

	cl_wrs_lock_bh(wrs_db);
	cl_wrs_sta_remove(cl_hw, wrs_db, cl_sta);
	cl_wrs_unlock_bh(wrs_db);
}

void cl_wrs_api_bss_coexistence(struct cl_hw *cl_hw)
{
	/* Downgrade to 20MHz support only */
	struct cl_sta *cl_sta = NULL;
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_wrs_sta *wrs_sta;

	cl_wrs_lock_bh(wrs_db);

	if (wrs_db->coex_bw == CHNL_BW_20)
		goto out;

	wrs_db->coex_bw = CHNL_BW_20;
	cl_wrs_ap_capab_modify_bw(cl_hw, wrs_db, CHNL_BW_20);

	cl_sta_lock(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		wrs_sta = &cl_sta->wrs_sta;

		if (wrs_sta->assoc_bw == CHNL_BW_40) {
			wrs_sta->max_rate_cap.bw = CHNL_BW_20;
			cl_wrs_tables_build(cl_hw, wrs_sta, &wrs_sta->tx_su_params);
		}
	}

	cl_sta_unlock(cl_hw);

out:
	cl_wrs_unlock_bh(wrs_db);
}

void cl_wrs_api_bss_set_bw(struct cl_hw *cl_hw, u8 bw)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;

	cl_wrs_lock_bh(wrs_db);
	cl_wrs_ap_capab_modify_bw(cl_hw, wrs_db, bw);
	cl_wrs_unlock_bh(wrs_db);
}

void cl_wrs_api_bw_changed(struct cl_hw *cl_hw, struct ieee80211_sta *sta, u8 bw)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;

	cl_wrs_lock_bh(wrs_db);

	wrs_sta->max_rate_cap.bw = bw;
	cl_wrs_sta_capabilities_set(wrs_db, sta);
	cl_wrs_tables_build(cl_hw, wrs_sta, &wrs_sta->tx_su_params);

	cl_wrs_unlock_bh(wrs_db);
}

void cl_wrs_api_nss_changed(struct cl_hw *cl_hw, struct ieee80211_sta *sta, u8 nss)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;

	cl_wrs_lock_bh(wrs_db);

	wrs_sta->max_rate_cap.nss = nss;
	cl_wrs_sta_capabilities_set(wrs_db, sta);
	cl_wrs_tables_build(cl_hw, wrs_sta, &wrs_sta->tx_su_params);

	cl_wrs_unlock_bh(wrs_db);
}

void cl_wrs_api_he_minrate_changed(struct cl_sta *cl_sta, u8 he_minrate)
{
	struct cl_hw *cl_hw = cl_sta->cl_vif->cl_hw;
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;
	u8 mcs = 0, nss = 0, bw = 0;
	u16 data_rate_x10 = 0;

	cl_wrs_lock_bh(wrs_db);

	wrs_sta->he_minrate = he_minrate;
	cl_wrs_tables_build(cl_hw, wrs_sta, &wrs_sta->tx_su_params);

	cl_wrs_unlock_bh(wrs_db);

	for (bw = 0; bw < wrs_sta->max_rate_cap.bw; bw++) {
		for (nss = 0; nss < wrs_sta->max_rate_cap.nss; nss++) {
			for (mcs = 0; mcs < wrs_sta->max_rate_cap.mcs; mcs++) {
				data_rate_x10 = cl_data_rates_get_x10(WRS_MODE_HE, bw,
								      nss, mcs,
								      WRS_GI_LONG);
				if (data_rate_x10 >= (he_minrate * 10)) {
					cl_rate_ctrl_set_default_per_he_minrate(cl_hw, bw,
										nss, mcs,
										WRS_GI_LONG);
					return;
				}
			}
		}
	}
}

static void _cl_wrs_api_recovery(struct cl_hw *cl_hw, struct cl_wrs_sta *wrs_sta,
				 struct cl_wrs_params *wrs_params)
{
	u16 fallback_rate_idx = wrs_params->table[wrs_params->rate_idx].rate_down.rate_idx;
	struct cl_wrs_rate *rate_fallback = &wrs_params->table[fallback_rate_idx].rate;
	struct cl_wrs_rate_params *rate_params = &wrs_params->rate_params;

	cl_wrs_rate_param_set(cl_hw, wrs_sta, wrs_params, rate_params,
			      rate_fallback, true);
}

void cl_wrs_api_recovery(struct cl_hw *cl_hw)
{
	struct cl_sta *cl_sta = NULL;
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_wrs_sta *wrs_sta = NULL;

	cl_wrs_lock_bh(wrs_db);
	cl_sta_lock(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		wrs_sta = &cl_sta->wrs_sta;

		_cl_wrs_api_recovery(cl_hw, wrs_sta, &wrs_sta->tx_su_params);

		if (wrs_sta->rx_params)
			_cl_wrs_api_recovery(cl_hw, wrs_sta, wrs_sta->rx_params);
	}

	cl_sta_unlock(cl_hw);
	cl_wrs_unlock_bh(wrs_db);
}

void cl_wrs_api_beamforming_sync(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_wrs_params *wrs_params = &cl_sta->wrs_sta.tx_su_params;
	u8 up_idx = 0;
	u16 rate_idx = wrs_params->rate_idx;

	cl_wrs_lock(wrs_db);

	for (up_idx = 0; up_idx < WRS_TABLE_NODE_UP_MAX; up_idx++)
		wrs_params->table[rate_idx].rate_up[up_idx].time_th = WRS_INIT_MSEC_WEIGHT_UP;

	cl_wrs_unlock(wrs_db);

	wrs_pr_info(wrs_db, "[WRS][%s] sta %u - beamforming sync\n",
		    WRS_TYPE_STR(wrs_params->type), cl_sta->sta_idx);
}

void cl_wrs_api_quick_down_check(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
				 struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;

	cl_wrs_lock(wrs_db);
	cl_wrs_quick_down_check(cl_hw, wrs_db, &cl_sta->wrs_sta, wrs_params);
	cl_wrs_unlock(wrs_db);
}

void cl_wrs_api_rate_sync(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			  struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;

	cl_wrs_lock(wrs_db);
	cl_wrs_rate_param_sync(wrs_db, &cl_sta->wrs_sta, wrs_params);
	cl_wrs_unlock(wrs_db);
}

bool cl_wrs_api_up_mcs1(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	bool result = false;

	cl_wrs_lock(wrs_db);
	result = cl_wrs_up_mcs1(cl_hw, wrs_db, &cl_sta->wrs_sta, wrs_params);
	cl_wrs_unlock(wrs_db);

	return result;
}

void cl_wrs_api_set_smps_mode(struct cl_hw *cl_hw, struct ieee80211_sta *sta, const u8 bw)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;
	u8 min_bw;

	if (sta->smps_mode == IEEE80211_SMPS_STATIC ||
	    sta->smps_mode == IEEE80211_SMPS_DYNAMIC) {
		/* If RTS is enabled, there is no need to go down to 1ss */
		if (cl_prot_mode_get(cl_hw) == TXL_PROT_RTS_FW)
			return;

		wrs_sta->smps_enable = true;
	} else if (sta->smps_mode == IEEE80211_SMPS_OFF && wrs_sta->smps_enable) {
		wrs_sta->smps_enable = false;
	}

	cl_wrs_lock_bh(wrs_db);
	min_bw = min_t(u8, bw, wrs_db->max_cap.bw);

	if (wrs_sta->max_rate_cap.bw != min_bw) {
		wrs_sta->max_rate_cap.bw = min_bw;
		wrs_pr_trace(wrs_db, "[WRS][TX_SU] SMPS mode: sta %u, bw %u\n",
			     wrs_sta->sta_idx, min_bw);
		cl_wrs_tables_build(cl_hw, wrs_sta, &wrs_sta->tx_su_params);
	}

	cl_wrs_unlock_bh(wrs_db);
}

u16 cl_wrs_api_get_max_data_rate(struct cl_hw *cl_hw)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_wrs_rate *max_rate = &wrs_db->max_cap;

	return cl_data_rates_get(wrs_db->mode, max_rate->bw, max_rate->nss,
				 max_rate->mcs, max_rate->gi);
}

u16 cl_wrs_api_get_tx_sta_data_rate(struct cl_sta *cl_sta)
{
	return cl_sta->wrs_sta.tx_su_params.data_rate;
}

u16 cl_wrs_api_get_rate_from_params(struct cl_wrs_rate_params *rate_params)
{
	return cl_data_rates_get_x10(rate_params->mode, rate_params->bw,
				     rate_params->nss, rate_params->mcs,
				     rate_params->gi);
}

int cl_wrs_api_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cli_params *cli_params)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	int ret;

	cl_wrs_lock_bh(wrs_db);
	ret = cl_wrs_cli(cl_hw, cl_vif, cli_params);
	cl_wrs_unlock_bh(wrs_db);

	return ret;
}

void cl_wrs_api_set_omi_rate(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 bw, u8 nss)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_wrs_params *wrs_params = cl_sta->wrs_sta.rx_params;
	struct cl_wrs_rate_params *rate_params = NULL;
	u8 sta_idx = cl_sta->sta_idx;

	if (!wrs_params)
		return;

	rate_params = &wrs_params->rate_params;

	/* Update WRS with Nsts from OMI */
	cl_msg_tx_update_rate_ul(cl_hw, sta_idx, bw, nss, rate_params->mcs, rate_params->gi);

	wrs_pr_trace(wrs_db, "sta_idx = %u, bw = %u, nss = %u\n", sta_idx, bw, nss);
}
