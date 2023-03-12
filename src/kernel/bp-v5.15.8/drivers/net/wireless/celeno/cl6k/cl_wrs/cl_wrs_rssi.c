// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_wrs_rssi.h"
#include "cl_wrs.h"
#include "def.h"
#include "cl_rssi.h"
#include "cl_data_rates.h"
#include "cl_vw.h"

/*
 * Section #1:
 * rate based on rssi.
 */
static s8 rssi_threshold_he[WRS_MCS_MAX_HE] = {
	-35, -40, -45, -50, -55, -60, -65, -70, -75, -80, -85, -90
};

static s8 rssi_threshold_vht[WRS_MCS_MAX_VHT] = {
	-36, -42, -48, -54, -60, -66, -72, -78, -84, -90
};

static s8 rssi_threshold_ht[WRS_MCS_MAX_HT] = {
	-34, -42, -50, -58, -66, -74, -82, -90
};

static s8 rssi_threshold_ofdm[WRS_MCS_MAX_OFDM] = {
	-34, -42, -50, -58, -66, -74, -82, -90
};

static s8 rssi_threshold_cck[WRS_MCS_MAX_CCK] = {
	-45, -60, -75, -90
};

static u16 cl_wrs_rssi_find_rate_ht_vht_he(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
					   struct cl_wrs_sta *wrs_sta,
					   struct cl_wrs_params *wrs_params,
					   s8 *rssi_sort,
					   s8 *thresholds)
{
	s8 max_ss = (s8)wrs_sta->max_rate_cap.nss;
	s8 nss = 0;
	u8 max_bw = (wrs_sta->mu_ofdma_bw == CHNL_BW_MAX) ?
		wrs_sta->max_rate_cap.bw : wrs_sta->mu_ofdma_bw;
	u8 bw = 0;
	u8 max_mcs = wrs_sta->max_rate_cap.mcs;
	u8 mcs = 0;
	u8 gi = (wrs_sta->mu_ofdma_gi < WRS_GI_MAX_HE ? wrs_sta->mu_ofdma_gi : WRS_GI_LONG);
	u8 selected_mcs = 0;
	u8 selected_nss = 0;
	u8 selected_bw = 0;
	u8 i = 0;
	u16 rate_idx = 0;
	u16 data_rate = 0;
	u16 max_data_rate = 0;
	bool is_vw = cl_vw_is_detected(cl_hw);

	if (max_bw > cl_hw->conf->ci_wrs_max_bw)
		max_bw = cl_hw->conf->ci_wrs_max_bw;

	if (is_vw) {
		for (i = 1; i < cl_hw->num_antennas; i++)
			rssi_sort[i] = rssi_sort[0];
	}

	for (i = 0; i <= max_mcs; i++) {
		mcs = max_mcs - i;

		for (nss = max_ss; nss >= 0; nss--) {
			if (rssi_sort[nss] <= thresholds[i])
				continue;

			/* In last level decrease BW */
			bw = ((i == max_mcs) && (max_bw > CHNL_BW_20)) ? (max_bw - 1) : max_bw;

			if (wrs_sta->mode == WRS_MODE_HE)
				data_rate = data_rate_he_x10[nss][bw][mcs][WRS_GI_LONG];
			else
				data_rate = data_rate_ht_vht_x10[bw][nss][mcs][gi];

			if (data_rate > max_data_rate) {
				selected_mcs = mcs;
				selected_nss = nss;
				selected_bw = bw;
				max_data_rate = data_rate;
				rate_idx = cl_wrs_tables_find_rate_idx(wrs_params,
								       bw, nss, mcs, gi);
			}

			break;
		}
	}

	if (!is_vw && cl_env_det_is_noisy_or_very_noisy(cl_hw)) {
		/* In conservative mode select less agressive parameters */
		if (wrs_db->conservative_nss_noisy_env && selected_nss > 0)
			selected_nss--;

		if (wrs_db->conservative_nss_noisy_env && selected_mcs > 0)
			selected_mcs--;

		rate_idx = cl_wrs_tables_find_rate_idx(wrs_params,
						       selected_bw, selected_nss, selected_mcs, gi);
	}

	return rate_idx;
}

static u16 cl_wrs_rssi_find_rate_cck_ofdm(struct cl_wrs_sta *wrs_sta,
					  s8 *rssi_sort, s8 *thresholds)
{
	struct cl_wrs_params *wrs_params = &wrs_sta->tx_su_params;
	u8 max_mcs = wrs_sta->max_rate_cap.mcs;
	u8 mcs = 0;
	u8 i = 0;

	for (i = 0; i <= max_mcs; i++) {
		mcs = max_mcs - i;

		if (rssi_sort[WRS_SS_1] > thresholds[i])
			return cl_wrs_tables_find_rate_idx(wrs_params,
							   CHNL_BW_20, WRS_SS_1, mcs, WRS_GI_LONG);
	}

	return 0;
}

u16 cl_wrs_rssi_find_rate(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			  struct cl_wrs_sta *wrs_sta,
			  struct cl_wrs_params *wrs_params,
			  s8 *rssi_sort)
{
	u16 rate_idx = 0;

	if (wrs_params->initial_rate_idx != WRS_INVALID_RATE)
		return wrs_params->initial_rate_idx;

	switch (wrs_sta->mode) {
	case WRS_MODE_HE:
		rate_idx = cl_wrs_rssi_find_rate_ht_vht_he(cl_hw, wrs_db, wrs_sta, wrs_params,
							   rssi_sort, rssi_threshold_he);
		break;
	case WRS_MODE_VHT:
		rate_idx = cl_wrs_rssi_find_rate_ht_vht_he(cl_hw, wrs_db, wrs_sta, wrs_params,
							   rssi_sort, rssi_threshold_vht);
		break;
	case WRS_MODE_HT:
		rate_idx = cl_wrs_rssi_find_rate_ht_vht_he(cl_hw, wrs_db, wrs_sta, wrs_params,
							   rssi_sort, rssi_threshold_ht);
		break;
	case WRS_MODE_OFDM:
		rate_idx = cl_wrs_rssi_find_rate_cck_ofdm(wrs_sta, rssi_sort,
							  rssi_threshold_ofdm);
		break;
	case WRS_MODE_CCK:
		rate_idx = cl_wrs_rssi_find_rate_cck_ofdm(wrs_sta, rssi_sort,
							  rssi_threshold_cck);
		break;
	default:
		break;
	}

	if (rate_idx == WRS_INVALID_RATE)
		rate_idx = 0;

	wrs_pr_trace(wrs_db,
		     "[WRS][%s] Select rate based rssi - sta=%u, rssi [%d,%d], "
		     "rate_idx=%u, bw=%u, nss=%u, mcs=%u\n",
		     WRS_TYPE_STR(wrs_params->type),
		     wrs_sta->sta_idx,
		     rssi_sort[0],
		     rssi_sort[1],
		     rate_idx,
		     wrs_params->table[rate_idx].rate.bw,
		     wrs_params->table[rate_idx].rate.nss,
		     wrs_params->table[rate_idx].rate.mcs);

	return rate_idx;
}

/*
 * Section #2:
 * rssi protect.
 */
static void cl_wrs_rssi_prot_set_avg(struct cl_wrs_sta *wrs_sta, s8 avg)
{
	struct cl_wrs_rssi_prot_db *rssi_prot_db = &wrs_sta->rssi_prot_db;

	memset(rssi_prot_db->samples_old, avg, WRS_RSSI_PROTECT_BUF_SZ_OLD);
	memset(rssi_prot_db->samples_new, avg, WRS_RSSI_PROTECT_BUF_SZ_NEW);
	rssi_prot_db->sum = avg << WRS_RSSI_PROTECT_SHIFT;
}

static s8 cl_wrs_rssi_prot_add_smpl(struct cl_wrs_sta *wrs_sta, s8 rssi_eq)
{
	struct cl_wrs_rssi_prot_db *rssi_prot_db = &wrs_sta->rssi_prot_db;
	u8 curr_idx_old = rssi_prot_db->curr_idx_old;
	u8 curr_idx_new = rssi_prot_db->curr_idx_new;

	rssi_prot_db->sum +=
		rssi_prot_db->samples_new[curr_idx_new] - rssi_prot_db->samples_old[curr_idx_old];
	rssi_prot_db->samples_old[curr_idx_old] = rssi_prot_db->samples_new[curr_idx_new];
	rssi_prot_db->samples_new[curr_idx_new] = rssi_eq;

	rssi_prot_db->curr_idx_old =
		WRS_INC_POW2(rssi_prot_db->curr_idx_old, WRS_RSSI_PROTECT_BUF_SZ_OLD);
	WRS_INC(rssi_prot_db->curr_idx_new, WRS_RSSI_PROTECT_BUF_SZ_NEW);

	return (s8)(wrs_sta->rssi_prot_db.sum >> WRS_RSSI_PROTECT_SHIFT);
}

static bool cl_wrs_rssi_prot_decision_up(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
					 struct cl_wrs_sta *wrs_sta,
					 struct cl_wrs_params *wrs_params,
					 s8 rssi_avg, s8 rssi_eq,
					 s8 *rssi_sort, u8 up_rate_idx)
{
	/* Decide UP only if all new samples are greater than old average */
	s8 *samples_new = wrs_sta->rssi_prot_db.samples_new;
	s8 up_thr = rssi_avg + wrs_db->rssi_protect_up_thr;
	u8 i = 0;

	for (i = 0; i < WRS_RSSI_PROTECT_BUF_SZ_NEW; i++)
		if (samples_new[i] <= up_thr)
			return false;

	if (wrs_db->rssi_protect_mode == WRS_RSSI_PROT_MODE_RSSI) {
		u16 rate_idx_old = wrs_params->rate_idx;
		u16 rate_idx_new = cl_wrs_rssi_find_rate(cl_hw, wrs_db, wrs_sta,
							 wrs_params, rssi_sort);
		struct cl_wrs_rate *rate_old = &wrs_params->table[rate_idx_old].rate;
		struct cl_wrs_rate *rate_new = &wrs_params->table[rate_idx_new].rate;
		u16 data_rate_old = cl_data_rates_get_x10(wrs_sta->mode, rate_old->bw,
							  rate_old->nss, rate_old->mcs,
							  rate_old->gi);
		u16 data_rate_new = cl_data_rates_get_x10(wrs_sta->mode, rate_new->bw,
							  rate_new->nss, rate_new->mcs,
							  rate_new->gi);

		if (rate_idx_old == rate_idx_new || data_rate_old >= data_rate_new)
			rate_idx_new = up_rate_idx;

		wrs_pr_info(wrs_db, "[WRS][%s] Increase rate based on RSSI - old [%u], new [%u]\n",
			    WRS_TYPE_STR(wrs_params->type), rate_idx_old, rate_idx_new);
		cl_wrs_decision_update(wrs_db, wrs_sta, wrs_params,
				       WRS_DECISION_UP_RSSI, rate_idx_new);
		cl_wrs_rate_params_update(cl_hw, wrs_db, wrs_sta,
					  wrs_params, rate_idx_new, true);
	} else {
		cl_wrs_decision_make(cl_hw, wrs_db, wrs_sta, wrs_params,
				     WRS_DECISION_UP_RSSI, up_rate_idx);
	}

	cl_wrs_tables_reset(wrs_db, wrs_sta, wrs_params);
	cl_wrs_rssi_prot_set_avg(wrs_sta, rssi_eq);

	return true;
}

static bool cl_wrs_rssi_prot_decision_down(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
					   struct cl_wrs_sta *wrs_sta,
					   struct cl_wrs_params *wrs_params,
					   s8 rssi_avg, s8 rssi_eq,
					   s8 *rssi_sort, u8 down_rate_idx)
{
	/* Decide DOWN only if all new samples are smaller than old average */
	s8 *samples_new = wrs_sta->rssi_prot_db.samples_new;
	s8 dn_thr = rssi_avg - wrs_db->rssi_protect_dn_thr;
	u8 i = 0;

	if (wrs_params->rate_idx == 0)
		return false;

	for (i = 0; i < WRS_RSSI_PROTECT_BUF_SZ_NEW; i++)
		if (samples_new[i] >= dn_thr)
			return false;

	if (wrs_db->rssi_protect_mode == WRS_RSSI_PROT_MODE_RSSI) {
		u16 rate_idx_old = wrs_params->rate_idx;
		u16 rate_idx_new = cl_wrs_rssi_find_rate(cl_hw, wrs_db, wrs_sta,
							 wrs_params, rssi_sort);
		struct cl_wrs_rate *rate_old = &wrs_params->table[rate_idx_old].rate;
		struct cl_wrs_rate *rate_new = &wrs_params->table[rate_idx_new].rate;
		u16 data_rate_old = cl_data_rates_get_x10(wrs_sta->mode, rate_old->bw,
							  rate_old->nss, rate_old->mcs,
							  rate_old->gi);
		u16 data_rate_new = cl_data_rates_get_x10(wrs_sta->mode, rate_new->bw,
							  rate_new->nss, rate_new->mcs,
							  rate_new->gi);

		if (rate_idx_old == rate_idx_new || data_rate_old <= data_rate_new)
			rate_idx_new = down_rate_idx;

		wrs_pr_info(wrs_db, "[WRS][%s] Decrease rate based on RSSI - old [%u], new [%u]\n",
			    WRS_TYPE_STR(wrs_params->type), rate_idx_old, rate_idx_new);
		cl_wrs_decision_update(wrs_db, wrs_sta, wrs_params,
				       WRS_DECISION_DOWN_RSSI, rate_idx_new);
		cl_wrs_rate_params_update(cl_hw, wrs_db, wrs_sta, wrs_params,
					  rate_idx_new, true);
	} else {
		cl_wrs_decision_make(cl_hw, wrs_db, wrs_sta, wrs_params,
				     WRS_DECISION_DOWN_RSSI, down_rate_idx);
	}

	cl_wrs_tables_reset(wrs_db, wrs_sta, wrs_params);
	cl_wrs_rssi_prot_set_avg(wrs_sta, rssi_eq);

	return true;
}

static void cl_wrs_rssi_prot_reset(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	memset(&cl_sta->wrs_sta.rssi_prot_db, 0, sizeof(struct cl_wrs_rssi_prot_db));
}

void cl_wrs_rssi_prot_start(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;
	s8 rssi_sort[MAX_ANTENNAS] = {0};
	s8 rssi_eq = 0;

	if (!cl_hw->wrs_db.rssi_protect_en)
		return;

	rssi_eq = cl_wrs_rssi_eq_calc(cl_hw, wrs_sta, false, rssi_sort);
	cl_wrs_rssi_prot_set_avg(wrs_sta, rssi_eq);
}

bool cl_wrs_rssi_prot_decision(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			       struct cl_wrs_sta *wrs_sta,
			       struct cl_wrs_params *wrs_params,
			       bool up_rate_valid,
			       u8 up_rate_idx, u8 down_rate_idx)
{
	s8 rssi_avg = 0;
	s8 rssi_eq = 0;
	s8 rssi_sort[MAX_ANTENNAS] = {0};

	rssi_eq = cl_wrs_rssi_eq_calc(cl_hw, wrs_sta, true, rssi_sort);
	rssi_avg = cl_wrs_rssi_prot_add_smpl(wrs_sta, rssi_eq);

	if (up_rate_valid)
		if (cl_wrs_rssi_prot_decision_up(cl_hw, wrs_db, wrs_sta, wrs_params, rssi_avg,
						 rssi_eq, rssi_sort, up_rate_idx))
			return true;

	return cl_wrs_rssi_prot_decision_down(cl_hw, wrs_db, wrs_sta, wrs_params, rssi_avg,
					      rssi_eq, rssi_sort, down_rate_idx);
}

void cl_wrs_rssi_prot_dbg(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			  struct cl_wrs_sta *wrs_sta)
{
	struct cl_wrs_rssi_prot_db *rssi_prot_db = NULL;
	u8 curr_idx_old = 0;
	u8 curr_idx_new = 0;
	u8 rate_idx = 0;
	char *buf = NULL;
	ssize_t buf_size;
	int len = 0;

	if (!wrs_db->rssi_protect_en) {
		cl_snprintf(&buf, &len, &buf_size, "RSSI protect is disabled!\n");
		goto out;
	}

	rssi_prot_db = &wrs_sta->rssi_prot_db;
	curr_idx_old = rssi_prot_db->curr_idx_old;
	curr_idx_new = rssi_prot_db->curr_idx_new;

	cl_snprintf(&buf, &len, &buf_size, "sta %u\n", wrs_sta->sta_idx);
	cl_snprintf(&buf, &len, &buf_size, "Old rssi samples:");

	for (rate_idx = 0; rate_idx < WRS_RSSI_PROTECT_BUF_SZ_OLD; rate_idx++) {
		if (!(rate_idx & 0x7))
			cl_snprintf(&buf, &len, &buf_size, "\n");

		cl_snprintf(&buf, &len, &buf_size, "%3u) %d, ",
			    rate_idx, rssi_prot_db->samples_old[curr_idx_old]);
		curr_idx_old = WRS_INC_POW2(curr_idx_old, WRS_RSSI_PROTECT_BUF_SZ_OLD);
	}

	cl_snprintf(&buf, &len, &buf_size, "\nAvg = [%d]\n\n",
		    wrs_sta->rssi_prot_db.sum >> WRS_RSSI_PROTECT_SHIFT);

	cl_snprintf(&buf, &len, &buf_size, "New rssi samples:\n");
	for (rate_idx = 0; rate_idx < WRS_RSSI_PROTECT_BUF_SZ_NEW; rate_idx++) {
		cl_snprintf(&buf, &len, &buf_size, "%u) %d\n", rate_idx,
			    rssi_prot_db->samples_new[curr_idx_new]);
		curr_idx_new = WRS_INC_POW2(curr_idx_new, WRS_RSSI_PROTECT_BUF_SZ_NEW);
	}
out:
	cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);
}

void cl_wrs_rssi_prot_config(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			     bool enable, bool mode, s32 rssi_up_thr, s32 rssi_dn_thr)
{
	bool en_prev = wrs_db->rssi_protect_en;

	wrs_db->rssi_protect_en = enable;
	wrs_db->rssi_protect_mode = mode;
	wrs_db->rssi_protect_up_thr = (s8)rssi_up_thr;
	wrs_db->rssi_protect_dn_thr = (s8)rssi_dn_thr;

	if (!en_prev && wrs_db->rssi_protect_en)
		cl_sta_loop_bh(cl_hw, cl_wrs_rssi_prot_start);
	else if (en_prev && !wrs_db->rssi_protect_en)
		cl_sta_loop_bh(cl_hw, cl_wrs_rssi_prot_reset);

	pr_debug("[WRS] Enable = %s, Mode = %s, Up threshold = %d, Down threshold = %d\n",
		 wrs_db->rssi_protect_en ? "true" : "false",
		 wrs_db->rssi_protect_mode ? "rssi" : "neighbor",
		 wrs_db->rssi_protect_up_thr,
		 wrs_db->rssi_protect_dn_thr);
}
