// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_wrs_sta.h"
#include "cl_wrs.h"
#include "cl_wrs_rssi.h"
#include "cl_math.h"
#include "cl_sta.h"
#include "cl_wrs_stats.h"
#include "cl_band.h"
#include "cl_utils.h"

static void cl_wrs_sta_info_set_he(struct cl_wrs_sta *wrs_sta)
{
	wrs_sta->mode = WRS_MODE_HE;

	wrs_sta->gi_cap[CHNL_BW_20] = WRS_GI_VSHORT;
	wrs_sta->gi_cap[CHNL_BW_40] = WRS_GI_VSHORT;
	wrs_sta->gi_cap[CHNL_BW_80] = WRS_GI_VSHORT;
	wrs_sta->gi_cap[CHNL_BW_160] = WRS_GI_VSHORT;
}

static void cl_wrs_sta_info_set_vht(struct cl_wrs_sta *wrs_sta,
				    struct ieee80211_sta_vht_cap *vht_cap,
				    struct ieee80211_sta_ht_cap *ht_cap)
{
	wrs_sta->mode = WRS_MODE_VHT;

	wrs_sta->gi_cap[CHNL_BW_20] =
		(ht_cap->cap & IEEE80211_HT_CAP_SGI_20) ? WRS_GI_SHORT : WRS_GI_LONG;
	wrs_sta->gi_cap[CHNL_BW_40] =
		(ht_cap->cap & IEEE80211_HT_CAP_SGI_40) ? WRS_GI_SHORT : WRS_GI_LONG;
	wrs_sta->gi_cap[CHNL_BW_80] =
		(vht_cap->cap & IEEE80211_VHT_CAP_SHORT_GI_80) ? WRS_GI_SHORT : WRS_GI_LONG;
	wrs_sta->gi_cap[CHNL_BW_160] =
		(vht_cap->cap & IEEE80211_VHT_CAP_SHORT_GI_160) ? WRS_GI_SHORT : WRS_GI_LONG;
}

static void cl_wrs_sta_info_set_ht(struct cl_wrs_sta *wrs_sta,
				   struct ieee80211_sta_ht_cap *ht_cap)
{
	wrs_sta->mode = WRS_MODE_HT;

	wrs_sta->gi_cap[CHNL_BW_20] =
		(ht_cap->cap & IEEE80211_HT_CAP_SGI_20) ? WRS_GI_SHORT : WRS_GI_LONG;
	wrs_sta->gi_cap[CHNL_BW_40] =
		(ht_cap->cap & IEEE80211_HT_CAP_SGI_40) ? WRS_GI_SHORT : WRS_GI_LONG;
}

static void cl_wrs_sta_info_set_legacy(struct cl_wrs_sta *wrs_sta,
				       struct ieee80211_sta *sta)
{
	if (sta->supp_rates[NL80211_BAND_5GHZ] ||
	    (sta->supp_rates[NL80211_BAND_2GHZ] & 0xFF0))
		wrs_sta->mode = WRS_MODE_OFDM;
	else
		wrs_sta->mode = WRS_MODE_CCK;
}

static void cl_wrs_sta_info_set(struct cl_hw *cl_hw, struct cl_wrs_sta *wrs_sta,
				struct ieee80211_sta *sta)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct ieee80211_sta_ht_cap *ht_cap = &sta->ht_cap;
	struct ieee80211_sta_vht_cap *vht_cap = &sta->vht_cap;
	struct ieee80211_sta_he_cap *he_cap = &sta->he_cap;
	u8 bw = min_t(u8, sta->bandwidth, wrs_db->max_cap.bw);

	if (he_cap->has_he)
		cl_wrs_sta_info_set_he(wrs_sta);
	else if (vht_cap->vht_supported && ht_cap->ht_supported)
		cl_wrs_sta_info_set_vht(wrs_sta, vht_cap, ht_cap);
	else if (ht_cap->ht_supported)
		cl_wrs_sta_info_set_ht(wrs_sta, ht_cap);
	else
		cl_wrs_sta_info_set_legacy(wrs_sta, sta);

	wrs_sta->max_rate_cap.nss = min_t(u8, sta->rx_nss, WRS_SS_MAX) - 1;

	if (cl_band_is_24g(cl_hw))
		wrs_sta->max_rate_cap.bw = min(bw, wrs_db->coex_bw);
	else
		wrs_sta->max_rate_cap.bw = bw;

	wrs_sta->assoc_bw = bw;
}

#define TWO_BITS_MASK 0x3

static u8 cl_wrs_calc_max_nss(u16 rx_mcs, u8 max_nss)
{
	u8 i, nss = 0;

	for (i = 0; i <= max_nss; i++) {
		if (((rx_mcs >> (2 * i)) & TWO_BITS_MASK) != IEEE80211_HE_MCS_NOT_SUPPORTED)
			nss++;
		else
			break;
	}

	return nss;
}

static void cl_supported_rates_he_cap(struct cl_wrs_db *wrs_db,
				      struct ieee80211_sta *sta)
{
	struct cl_sta *cl_sta = (struct cl_sta *)sta->drv_priv;
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;
	struct ieee80211_he_mcs_nss_supp *mcs_nss = &sta->he_cap.he_mcs_nss_supp;
	int mcs = 0;
	int supported_mcs = 0;
	u16 rx_mcs = 0;
	u8 max_nss = wrs_sta->max_rate_cap.nss;
	u8 nss = 0, bw = 0;
	u8 max_nss_80, max_nss_160;

	for (bw = 0; bw <= wrs_sta->max_rate_cap.bw; bw++) {
		if (bw < CHNL_BW_160) {
			rx_mcs = le16_to_cpu(mcs_nss->rx_mcs_80);
		} else if (bw == CHNL_BW_160) {
			u16 rx_mcs_80 = le16_to_cpu(mcs_nss->rx_mcs_80);

			max_nss_80 = cl_wrs_calc_max_nss(rx_mcs_80,
							 max_nss) + 1;
			rx_mcs = le16_to_cpu(mcs_nss->rx_mcs_160);
			max_nss_160 = cl_wrs_calc_max_nss(rx_mcs, max_nss) + 1;
			max_nss = max_nss * max_nss_160 / max_nss_80;
		} else {
			wrs_pr_err(wrs_db, "[WRS] bw %u is not supported\n", bw);
		}

		for (nss = 0; nss <= max_nss; nss++) {
			switch ((rx_mcs >> (2 * nss)) & TWO_BITS_MASK) {
			case IEEE80211_HE_MCS_SUPPORT_0_7:
				supported_mcs = WRS_MCS_7;
				break;
			case IEEE80211_HE_MCS_SUPPORT_0_9:
				supported_mcs = WRS_MCS_9;
				break;
			case IEEE80211_HE_MCS_SUPPORT_0_11:
				supported_mcs = WRS_MCS_11;
				break;
			case IEEE80211_HE_MCS_NOT_SUPPORTED:
				supported_mcs = -1;
				break;
			}

			for (mcs = 0; mcs <= supported_mcs; mcs++)
				cl_wrs_sta_set_supported_rate(wrs_sta, bw, nss, mcs);
		}
	}
}

static void cl_supported_rates_vht_cap(struct ieee80211_sta *sta)
{
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;
	u16 mcs_map = le16_to_cpu(sta->vht_cap.vht_mcs.rx_mcs_map);
	u8 bw = 0;
	u8 nss = 0;
	int mcs = 0;
	int supported_mcs = 0;

	for (bw = 0; bw <= wrs_sta->max_rate_cap.bw; bw++) {
		for (nss = 0; nss <= wrs_sta->max_rate_cap.nss; nss++) {
			switch ((mcs_map >> (2 * nss)) & TWO_BITS_MASK) {
			case 0:
				supported_mcs = WRS_MCS_7;
				break;
			case 1:
				supported_mcs = WRS_MCS_8;
				break;
			case 2:
				supported_mcs = WRS_MCS_9;
				break;
			case 3:
				supported_mcs = -1;
				break;
			}

			for (mcs = 0; mcs <= supported_mcs; mcs++)
				cl_wrs_sta_set_supported_rate(wrs_sta, bw, nss, mcs);
		}
	}
}

static void cl_supported_rates_ht_cap(struct ieee80211_sta *sta)
{
	struct ieee80211_sta_ht_cap *ht_cap = &sta->ht_cap;
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;
	u8 bw = 0;
	u8 nss = 0;
	u8 mcs = 0;

	for (mcs = 0; mcs <= WRS_MCS_7; mcs++) {
		for (nss = 0; nss <= wrs_sta->max_rate_cap.nss; nss++) {
			if ((ht_cap->mcs.rx_mask[nss] & (1 << mcs)) == 0)
				continue;

			for (bw = 0; bw <= wrs_sta->max_rate_cap.bw; bw++)
				cl_wrs_sta_set_supported_rate(wrs_sta, bw, nss, mcs);
		}
	}
}

static void cl_supported_rates_legacy_cap(struct cl_hw *cl_hw,
					  struct ieee80211_sta *sta,
					  u8 max_mcs)
{
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;
	u8 mcs = 0;

	for (mcs = 0; mcs < max_mcs; mcs++)
		if (rate_supported(sta, cl_hw->nl_band, mcs))
			cl_wrs_sta_set_supported_rate(wrs_sta, CHNL_BW_20, WRS_SS_1, mcs);
}

void cl_wrs_sta_add(struct cl_hw *cl_hw, struct ieee80211_sta *sta)
{
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;
	struct cl_wrs_params *wrs_params = &wrs_sta->tx_su_params;

	wrs_params->type = WRS_TYPE_TX_SU;
	wrs_params->rate_idx = WRS_INVALID_RATE;
	wrs_params->initial_rate_idx = WRS_INVALID_RATE;

	wrs_sta->sta_idx = cl_sta->sta_idx;
	wrs_sta->mu_ofdma_bw = CHNL_BW_MAX;
	wrs_sta->mu_ofdma_gi = WRS_GI_MAX_HE;

	cl_wrs_rssi_prot_start(cl_hw, cl_sta);
	cl_wrs_stats_per_init(wrs_params);
	cl_wrs_sta_info_set(cl_hw, wrs_sta, sta);
	cl_wrs_sta_capabilities_set(wrs_db, sta);
	cl_wrs_tables_build(cl_hw, wrs_sta, wrs_params);
	cl_wrs_sta_select_first_rate(cl_hw, wrs_db, wrs_sta, wrs_params);

	wrs_pr_trace(wrs_db, "[WRS][%s] Add station %pM to database (sta_idx %u)\n",
		     WRS_TYPE_STR(wrs_params->type), cl_sta->addr, cl_sta->sta_idx);
}

void cl_wrs_sta_add_rx(struct cl_hw *cl_hw, struct ieee80211_sta *sta)
{
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;
	struct cl_wrs_params *wrs_params;

	if (wrs_sta->rx_params) {
		wrs_pr_warn(wrs_db, "[WRS][RX] Params already allocated (sta_idx %u)\n",
			    wrs_sta->sta_idx);
		return;
	}

	wrs_params = kzalloc(sizeof(*wrs_params), GFP_ATOMIC);

	if (!wrs_params)
		return;

	wrs_sta->rx_params = wrs_params;
	wrs_params->type = WRS_TYPE_RX;
	wrs_params->rate_idx = WRS_INVALID_RATE;
	wrs_params->initial_rate_idx = WRS_INVALID_RATE;

	wrs_sta->sta_idx = cl_sta->sta_idx;
	wrs_sta->mu_ofdma_bw = CHNL_BW_MAX;
	wrs_sta->mu_ofdma_gi = WRS_GI_MAX_HE;

	cl_wrs_rssi_prot_start(cl_hw, cl_sta);
	cl_wrs_stats_per_init(wrs_params);
	cl_wrs_sta_info_set(cl_hw, wrs_sta, sta);
	cl_wrs_sta_capabilities_set(wrs_db, sta);
	cl_wrs_tables_build(cl_hw, wrs_sta, wrs_params);
	cl_wrs_sta_select_first_rate(cl_hw, wrs_db, wrs_sta, wrs_params);
	cl_wrs_rx_rate_idle_reset(wrs_params);

	wrs_pr_trace(wrs_db, "[WRS][%s] Add station %pM to database (sta_idx %u)\n",
		     WRS_TYPE_STR(wrs_params->type), cl_sta->addr, cl_sta->sta_idx);
}

static void _cl_wrs_sta_remove(struct cl_wrs_params *wrs_params)
{
	if (wrs_params->is_logger_en) {
		kfree(wrs_params->logger);
		wrs_params->logger = NULL;
	}

	kfree(wrs_params->table);
	wrs_params->table = NULL;

	cl_wrs_stats_per_remove(wrs_params);
}

static void cl_wrs_sta_remove_rx(struct cl_wrs_db *wrs_db, struct cl_wrs_sta *wrs_sta)
{
	struct cl_wrs_params *wrs_params = wrs_sta->rx_params;

	if (!wrs_params) {
		wrs_pr_warn(wrs_db, "[WRS][RX] Params already removed (sta_idx %u)\n",
			    wrs_sta->sta_idx);
		return;
	}

	_cl_wrs_sta_remove(wrs_params);

	kfree(wrs_params);
	wrs_sta->rx_params = NULL;

	wrs_pr_err(wrs_db, "[WRS][RX] Remove params (sta_idx %u)\n", wrs_sta->sta_idx);
}

void cl_wrs_sta_remove(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db, struct cl_sta *cl_sta)
{
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;

	_cl_wrs_sta_remove(&wrs_sta->tx_su_params);

	if (wrs_sta->rx_params)
		cl_wrs_sta_remove_rx(wrs_db, wrs_sta);

	wrs_pr_trace(wrs_db, "[WRS] Remove station %pM from database (sta_idx %u)\n",
		     cl_sta->addr, cl_sta->sta_idx);
}

struct cl_wrs_sta *cl_wrs_sta_get(struct cl_hw *cl_hw, u8 sta_idx)
{
	struct cl_sta *cl_sta = cl_sta_get(cl_hw, sta_idx);

	return cl_sta ? &cl_sta->wrs_sta : NULL;
}

void cl_wrs_sta_print_list(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db)
{
	struct cl_sta *cl_sta = NULL;
	struct cl_wrs_sta *wrs_sta = NULL;
	struct cl_wrs_rate *max_rate_cap = NULL;
	u8 num_sta = cl_sta_num_bh(cl_hw);
	char *buf = NULL;
	ssize_t buf_size;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "Station list [%u]\n", num_sta);
	cl_snprintf(&buf, &len, &buf_size,
		    "-------------------------------------------------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "|Sta|    Mac Address    |Mode|MaxBW|MaxSS|MaxMCS|MaxGI|\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "|-----------------------------------------------------|\n");

	read_lock_bh(&cl_hw->cl_sta_db.lock);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		wrs_sta = &cl_sta->wrs_sta;
		max_rate_cap = &wrs_sta->max_rate_cap;

		cl_snprintf(&buf, &len, &buf_size,
			    "|%3u| %pM |%-4s|%-5s|%-5u|%-6u|%-5u|\n",
			    cl_sta->sta_idx,
			    cl_sta->addr,
			    WRS_MODE_STR(wrs_sta->mode),
			    WRS_BW_STR(max_rate_cap->bw),
			    max_rate_cap->nss,
			    max_rate_cap->mcs,
			    max_rate_cap->gi);
	}

	read_unlock_bh(&cl_hw->cl_sta_db.lock);

	cl_snprintf(&buf, &len, &buf_size,
		    "-------------------------------------------------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "\n");

	cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);
}

void cl_wrs_sta_select_first_rate(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
				  struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params)
{
	if (wrs_db->is_fixed_rate) {
		s8 *fixed_rate = cl_hw->conf->ci_wrs_fixed_rate;

		cl_wrs_fixed_rate_set(cl_hw, wrs_db, wrs_sta, wrs_params, wrs_db->is_fixed_rate,
				      fixed_rate[WRS_FIXED_PARAM_MODE],
				      fixed_rate[WRS_FIXED_PARAM_BW],
				      fixed_rate[WRS_FIXED_PARAM_NSS],
				      fixed_rate[WRS_FIXED_PARAM_MCS],
				      fixed_rate[WRS_FIXED_PARAM_GI]);
	} else {
		struct cl_sta *cl_sta = container_of(wrs_sta, struct cl_sta, wrs_sta);
		struct cl_wrs_rate_params *vif_fixed_params = &cl_sta->cl_vif->fixed_params;

		if (vif_fixed_params->is_fixed)
			cl_wrs_fixed_rate_set(cl_hw, wrs_db, wrs_sta, wrs_params,
					      WRS_FIXED_FALLBACK_DIS,
					      vif_fixed_params->mode,
					      vif_fixed_params->bw,
					      vif_fixed_params->nss,
					      vif_fixed_params->mcs,
					      vif_fixed_params->gi);
	}

	if (!wrs_params->is_fixed_rate) {
		bool result = cl_wrs_set_rate_idle(cl_hw, wrs_db, wrs_sta, wrs_params);

		/*
		 * If new rate wasn't selected according to
		 * rssi (no samples) or data packets set rate to lowest possible
		 */
		if (!result)
			cl_wrs_rate_params_update(cl_hw, wrs_db, wrs_sta,
						  wrs_params, 0, false);
	}
}

void cl_wrs_sta_capabilities_set(struct cl_wrs_db *wrs_db, struct ieee80211_sta *sta)
{
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);
	enum cl_wrs_mode mode = cl_sta->wrs_sta.mode;

	if (mode == WRS_MODE_HE)
		cl_supported_rates_he_cap(wrs_db, sta);
	else if (mode == WRS_MODE_VHT)
		cl_supported_rates_vht_cap(sta);
	else if (mode == WRS_MODE_HT)
		cl_supported_rates_ht_cap(sta);
	else {
		struct cl_hw *cl_hw = cl_sta->cl_vif->cl_hw;
		u8 max_mcs = (mode == WRS_MODE_OFDM) ? WRS_MCS_MAX_OFDM : WRS_MCS_MAX_CCK;

		cl_supported_rates_legacy_cap(cl_hw, sta, max_mcs);
	}
}

void cl_wrs_sta_set_supported_rate(struct cl_wrs_sta *wrs_sta, u8 bw, u8 nss, u8 mcs)
{
	u8 rate_idx = mcs + (nss * WRS_MCS_MAX);

	wrs_sta->supported_rates[bw] |= BIT(rate_idx);
}

