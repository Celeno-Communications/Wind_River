// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_wrs_tables.h"
#include "cl_wrs.h"
#include "cl_wrs_db.h"
#include "cl_wrs_sta.h"
#include "cl_data_rates.h"
#include "cl_hw.h"

static struct cl_wrs_table
	ap_rate_table_he[CHNL_BW_MAX][WRS_SS_MAX][WRS_MCS_MAX_HE][WRS_GI_MAX_HE];
static struct cl_wrs_table
	ap_rate_table_ht_vht[CHNL_BW_MAX][WRS_SS_MAX][WRS_MCS_MAX_VHT][WRS_GI_MAX_VHT];

/* Rate indexes sorted by data rate */
static u16 rate_idx_sorted_by_data_rate_he[WRS_HE_RATE_TABLE_SIZE] = {0};
static u16 rate_idx_sorted_by_data_rate_ht_vht[WRS_HT_VHT_RATE_TABLE_SIZE] = {0};

static void cl_wrs_extract_rate_idx_vht(u16 idx, u8 *bw, u8 *nss, u8 *mcs, u8 *gi)
{
	*gi = idx % WRS_GI_MAX_VHT;
	idx = (idx - *gi) / WRS_GI_MAX_VHT;
	*mcs = idx % WRS_MCS_MAX_VHT;
	idx = (idx - *mcs) / WRS_MCS_MAX_VHT;
	*nss = idx % WRS_SS_MAX;
	*bw = (idx - *nss) / CHNL_BW_MAX;
}

static void cl_wrs_extract_rate_idx_he(u16 idx, u8 *bw, u8 *nss, u8 *mcs, u8 *gi)
{
	*gi = idx % WRS_GI_MAX_HE;
	idx = (idx - *gi) / WRS_GI_MAX_HE;
	*mcs = idx % WRS_MCS_MAX_HE;
	idx = (idx - *mcs) / WRS_MCS_MAX_HE;
	*nss = idx % WRS_SS_MAX;
	*bw = (idx - *nss) / CHNL_BW_MAX;
}

static void cl_wrs_tables_build_sorted_ht_vht(void)
{
	/* Sort according to HT/VHT data rate */
	u16 i, j;
	u8 bw1, nss1, mcs1, gi1, bw2, nss2, mcs2, gi2;

	for (i = 0; i < WRS_HT_VHT_RATE_TABLE_SIZE; i++)
		rate_idx_sorted_by_data_rate_ht_vht[i] = i;

	for (i = 0; i < WRS_HT_VHT_RATE_TABLE_SIZE - 1; i++) {
		for (j = 0; j < WRS_HT_VHT_RATE_TABLE_SIZE - i - 1; j++) {
			cl_wrs_extract_rate_idx_vht(rate_idx_sorted_by_data_rate_ht_vht[j],
						    &bw1, &nss1, &mcs1, &gi1);
			cl_wrs_extract_rate_idx_vht(rate_idx_sorted_by_data_rate_ht_vht[j + 1],
						    &bw2, &nss2, &mcs2, &gi2);

			if (data_rate_ht_vht_x10[bw1][nss1][mcs1][gi1] >
			    data_rate_ht_vht_x10[bw2][nss2][mcs2][gi2])
				swap(rate_idx_sorted_by_data_rate_ht_vht[j],
				     rate_idx_sorted_by_data_rate_ht_vht[j + 1]);
		}
	}
}

static void cl_wrs_tables_build_sorted_he(void)
{
	/* Sort according to HE data rate */
	u16 i, j;
	u8 bw1, nss1, mcs1, gi1, bw2, nss2, mcs2, gi2;

	for (i = 0; i < WRS_HE_RATE_TABLE_SIZE; i++)
		rate_idx_sorted_by_data_rate_he[i] = i;

	for (i = 0; i < WRS_HE_RATE_TABLE_SIZE - 1; i++) {
		for (j = 0; j < WRS_HE_RATE_TABLE_SIZE - i - 1; j++) {
			cl_wrs_extract_rate_idx_he(rate_idx_sorted_by_data_rate_he[j],
						   &bw1, &nss1, &mcs1, &gi1);
			cl_wrs_extract_rate_idx_he(rate_idx_sorted_by_data_rate_he[j + 1],
						   &bw2, &nss2, &mcs2, &gi2);

			if (data_rate_he_x10[nss1][bw1][mcs1][gi1] >
			    data_rate_he_x10[nss2][bw2][mcs2][gi2])
				swap(rate_idx_sorted_by_data_rate_he[j],
				     rate_idx_sorted_by_data_rate_he[j + 1]);
		}
	}
}

static u16 idx_to_offt_ht_vht(u32 bw, u32 nss, u32 mcs, u32 gi)
{
	if (bw < CHNL_BW_MAX &&
	    nss < WRS_SS_MAX &&
	    mcs < WRS_MCS_MAX_VHT &&
	    gi < WRS_GI_MAX_VHT)
		return (gi + WRS_GI_MAX_VHT * (mcs + WRS_MCS_MAX_VHT * (nss + bw * WRS_SS_MAX)));
	else
		return -1;
}

static u16 idx_to_offt_he(u32 bw, u32 nss, u32 mcs, u32 gi)
{
	if (bw < CHNL_BW_MAX &&
	    nss < WRS_SS_MAX &&
	    mcs < WRS_MCS_MAX_HE &&
	    gi < WRS_GI_MAX_HE)
		return (gi + WRS_GI_MAX_HE * (mcs + WRS_MCS_MAX_HE * (nss + bw * WRS_SS_MAX)));
	else
		return -1;
}

static u16 find_down_rate_idx(u32 bw, u32 nss, u32 mcs, u32 gi, u16 *data_rates,
			      u16 (*idx_to_offt)(u32 bw, u32 nss, u32 mcs, u32 gi))
{
	u16 idx;

	if (mcs > 0) {
		idx = idx_to_offt(bw, nss, mcs - 1, gi);
		if (data_rates[idx])
			return idx;
		if (mcs > 1)
			return idx_to_offt(bw, nss, mcs - 2, gi);
	}

	if (bw > 0) {
		idx = idx_to_offt(bw - 1, nss, mcs, gi);
		if (data_rates[idx])
			return idx;
		if (bw > 1)
			return idx_to_offt(bw - 2, nss, mcs, gi);
	}

	if (nss > 0) {
		idx = idx_to_offt(bw, nss - 1, mcs, gi);
		if (data_rates[idx])
			return idx;
		if (nss > 1) {
			idx = idx_to_offt(bw, nss - 2, mcs, gi);
			if (data_rates[idx])
				return idx;
		}
	}

	if (gi > 0)
		return idx_to_offt(bw, nss, mcs, gi - 1);

	return 0;
}

static u16 find_up_mcs_rate_idx(u32 bw, u32 nss, u32 mcs, u32 gi, u16 *data_rates,
				u16 (*idx_to_offt)(u32 bw, u32 nss, u32 mcs, u32 gi))
{
	s16 idx = idx_to_offt(bw, nss, mcs + 1, gi);

	if (idx < 0 || !data_rates[idx])
		idx = idx_to_offt(bw, nss, mcs + 2, gi);

	return (idx < 0) ? WRS_INVALID_RATE : idx;
}

static u16 find_up_bw_rate_idx(u32 bw, u32 nss, u32 mcs, u32 gi,
			       u16 *data_rates,
			       u16 (*idx_to_offt)(u32 bw, u32 nss, u32 mcs, u32 gi))
{
	s16 cur_data_rate = data_rates[idx_to_offt(bw, nss, mcs, gi)];
	s16 min_idx = WRS_INVALID_RATE;
	s16 idx;
	s32 min_rate_diff = S32_MAX;
	s32 rate_diff;

	for (idx = idx_to_offt(++bw, nss, mcs, gi); !(idx < 0);
	     idx = idx_to_offt(bw, nss, --mcs, gi)) {
		/*
		 * If data_rates[idx] == 0, the difference will be negative,
		 * so the condition below will not hold.
		 * Therefore, no need to check this possiblity specifically.
		 */
		rate_diff = data_rates[idx] - cur_data_rate;
		if (rate_diff > 0 &&
		    rate_diff < min_rate_diff &&
		    (data_rates[idx] * 100) > (cur_data_rate * WRS_EPR_FACTOR)) {
			min_rate_diff = rate_diff;
			min_idx = idx;
		}
	}

	return min_idx;
}

static u16 find_up_nss_rate_idx(u32 bw, u32 nss, u32 mcs, u32 gi,
				u16 *data_rates,
				u16 (*idx_to_offt)(u32 bw, u32 nss, u32 mcs, u32 gi))
{
	s16 cur_data_rate = data_rates[idx_to_offt(bw, nss, mcs, gi)];
	s16 min_idx = WRS_INVALID_RATE;
	s16 idx;
	s32 min_rate_diff = S32_MAX;
	s32 rate_diff;

	for (idx = idx_to_offt(bw, ++nss, mcs, gi); !(idx < 0);
	     idx = idx_to_offt(bw, nss, --mcs, gi)) {
		/*
		 * If data_rates[idx] == 0, the difference will be negative,
		 * so the condition below will not hold.
		 * Therefore, no need to check this possiblity specifically.
		 */
		rate_diff = data_rates[idx] - cur_data_rate;
		if (rate_diff > 0 &&
		    rate_diff < min_rate_diff &&
		    (data_rates[idx] * 100) > (cur_data_rate * WRS_EPR_FACTOR)) {
			min_rate_diff = rate_diff;
			min_idx = idx;
		}
	}

	return min_idx;
}

static u16 find_up_bf_rate_idx(u32 bw, u32 nss, u32 mcs, u32 gi,
			       u16 *data_rates,
			       u16 (*idx_to_offt)(u32 bw, u32 nss, u32 mcs, u32 gi))
{
	s16 cur_data_rate = data_rates[idx_to_offt(bw, nss, mcs, gi)];
	s16 min_idx = WRS_INVALID_RATE;
	s16 idx;
	s32 min_rate_diff = S32_MAX;
	s16 rate_diff;

	for (idx = idx_to_offt(bw, --nss, mcs, gi); !(idx < 0);
	     idx = idx_to_offt(bw, nss, ++mcs, gi)) {
		/*
		 * If data_rates[idx] == 0, the difference will be negative,
		 * so the condition below will not hold.
		 * Therefore, no need to check this possiblity specifically.
		 */
		rate_diff = data_rates[idx] - cur_data_rate;
		if (rate_diff > 0 &&
		    rate_diff < min_rate_diff &&
		    (data_rates[idx] * 100) > (cur_data_rate * WRS_EPR_FACTOR)) {
			min_rate_diff = rate_diff;
			min_idx = idx;
		}
	}

	return min_idx;
}

static u16 find_up_gi_rate_idx(u32 bw, u32 nss, u32 mcs, u32 gi,
			       u16 (*idx_to_offt)(u32 bw, u32 nss, u32 mcs, u32 gi))
{
	s16 idx = idx_to_offt(bw, nss, mcs, gi + 1);

	return (idx < 0) ? WRS_INVALID_RATE : idx;
}

static void _cl_wrs_tables_init(struct cl_wrs_table *ap_rate_table,
				u16 *data_rates,
				u32 bw, u32 nss, u32 mcs, u32 gi,
				u16 (*idx_to_offt)(u32 bw, u32 nss, u32 mcs, u32 gi))
{
	struct cl_wrs_table *cur_entry = NULL;
	int i = 0;
	u16 offt = idx_to_offt(bw, nss, mcs, gi);

	cur_entry = &ap_rate_table[offt];
	cur_entry->rate.bw = bw;
	cur_entry->rate.nss = nss;
	cur_entry->rate.mcs = mcs;
	cur_entry->rate.gi = gi;

	/* If current rate is invalid, mark it as such and skip it. */
	if (!data_rates[offt]) {
		cur_entry->rate_down.rate_idx = WRS_INVALID_RATE;
		cur_entry->rate_down.time_th = WRS_MSEC_WEIGHT_MAX_DOWN;

		for (i = 0; i < WRS_TABLE_NODE_UP_MAX; i++) {
			cur_entry->rate_up[i].rate_idx = WRS_INVALID_RATE;
			cur_entry->rate_up[i].time_th = WRS_MSEC_WEIGHT_MAX_UP;
		}

		return;
	}

	cur_entry->rate_down.rate_idx =
		find_down_rate_idx(bw, nss, mcs, gi, data_rates, idx_to_offt);
	cur_entry->rate_up[WRS_TABLE_NODE_UP_MCS].rate_idx =
		find_up_mcs_rate_idx(bw, nss, mcs, gi, data_rates, idx_to_offt);
	cur_entry->rate_up[WRS_TABLE_NODE_UP_BW].rate_idx =
		find_up_bw_rate_idx(bw, nss, mcs, gi, data_rates, idx_to_offt);
	cur_entry->rate_up[WRS_TABLE_NODE_UP_NSS].rate_idx =
		find_up_nss_rate_idx(bw, nss, mcs, gi, data_rates, idx_to_offt);
	cur_entry->rate_up[WRS_TABLE_NODE_UP_BF].rate_idx =
		find_up_bf_rate_idx(bw, nss, mcs, gi, data_rates, idx_to_offt);
	cur_entry->rate_up[WRS_TABLE_NODE_UP_GI].rate_idx =
		find_up_gi_rate_idx(bw, nss, mcs, gi, idx_to_offt);

	cur_entry->rate_down.time_th = WRS_INIT_MSEC_WEIGHT_DOWN;

	for (i = 0; i < WRS_TABLE_NODE_UP_MAX; i++)
		cur_entry->rate_up[i].time_th =
			(cur_entry->rate_up[i].rate_idx == WRS_INVALID_RATE) ?
			WRS_MSEC_WEIGHT_MAX_UP : WRS_INIT_MSEC_WEIGHT_UP;
}

static void cl_wrs_tables_init(u8 mode)
{
	u32 bw, nss, mcs, gi;
	u32 max_bw, max_nss, max_mcs, max_gi;
	u16 (*idx_to_offt)(u32 bw, u32 nss, u32 mcs, u32 gi);
	struct cl_wrs_table *ap_rate_table = NULL;
	u16 *data_rates = NULL;

	if (mode == WRS_MODE_HE) {
		idx_to_offt = idx_to_offt_he;
		max_bw = CHNL_BW_MAX;
		max_nss = WRS_SS_MAX;
		max_mcs = WRS_MCS_MAX_HE;
		max_gi = WRS_GI_MAX_HE;
		ap_rate_table = (struct cl_wrs_table *)ap_rate_table_he;
		data_rates = (u16 *)data_rate_he_x10;
	} else if (mode == WRS_MODE_VHT) {
		idx_to_offt = idx_to_offt_ht_vht;
		max_bw = CHNL_BW_MAX;
		max_nss = WRS_SS_MAX;
		max_mcs = WRS_MCS_MAX_VHT;
		max_gi = WRS_GI_MAX_VHT;
		ap_rate_table = (struct cl_wrs_table *)ap_rate_table_ht_vht;
		data_rates = (u16 *)data_rate_ht_vht_x10;
	} else {
		return;
	}

	for (bw = 0; bw < max_bw; bw++)
		for (nss = 0; nss < max_nss; nss++)
			for (mcs = 0; mcs < max_mcs; mcs++)
				for (gi = 0; gi < max_gi; gi++)
					_cl_wrs_tables_init(ap_rate_table,
							    data_rates,
							    bw,
							    nss,
							    mcs,
							    gi,
							    idx_to_offt);
}

void cl_wrs_tables_global_build(void)
{
	cl_wrs_tables_init(WRS_MODE_HE);
	cl_wrs_tables_init(WRS_MODE_VHT);
	cl_wrs_tables_build_sorted_he();
	cl_wrs_tables_build_sorted_ht_vht();
}

void cl_wrs_tables_print(struct cl_hw *cl_hw, struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_table *table;
	u16 i = 0, idx_dn = 0, idx_up1 = 0, idx_up2 = 0, idx_up3 = 0, idx_up4 = 0, idx_up5 = 0;

	pr_debug("\n");
	pr_debug("                 -------------------------------------------------------------------------------\n");
	pr_debug("                 ||   Down    || Up #1 mcs || Up #2 bw  || Up #3 ss  || Up #4 bf  || Up #5 gi  |\n");
	pr_debug("-----------------||-----------||-----------||-----------||-----------||-----------||-----------|\n");
	pr_debug("|idx|bw|ss|mcs|gi|| idx | thr || idx | thr || idx | thr || idx | thr || idx | thr || idx | thr |\n");
	pr_debug("|----------------||-----------||-----------||-----------||-----------||-----------||-----------|\n");

	for (i = 0; i < wrs_params->table_size; i++) {
		table = &wrs_params->table[i];

		idx_dn = table->rate_down.rate_idx;
		idx_up1 = table->rate_up[WRS_TABLE_NODE_UP_MCS].rate_idx;
		idx_up2 = table->rate_up[WRS_TABLE_NODE_UP_BW].rate_idx;
		idx_up3 = table->rate_up[WRS_TABLE_NODE_UP_NSS].rate_idx;
		idx_up4 = table->rate_up[WRS_TABLE_NODE_UP_BF].rate_idx;
		idx_up5 = table->rate_up[WRS_TABLE_NODE_UP_GI].rate_idx;

		pr_debug("|%3u|%2u|%2u|%3u|%2u||%5u|%5u||%5u|%5u||%5u|%5u||%5u|%5u||%5u|%5u||%5u|%5u|\n",
			 i,
			 table->rate.bw, table->rate.nss, table->rate.mcs, table->rate.gi,
			 idx_dn, table->rate_down.time_th,
			 idx_up1, table->rate_up[WRS_TABLE_NODE_UP_MCS].time_th,
			 idx_up2, table->rate_up[WRS_TABLE_NODE_UP_BW].time_th,
			 idx_up3, table->rate_up[WRS_TABLE_NODE_UP_NSS].time_th,
			 idx_up4, table->rate_up[WRS_TABLE_NODE_UP_BF].time_th,
			 idx_up5, table->rate_up[WRS_TABLE_NODE_UP_GI].time_th);
	}

	pr_debug("------------------------------------------------------------------------------------------------\n\n");
}

void cl_wrs_tables_reset(struct cl_wrs_db *wrs_db, struct cl_wrs_sta *wrs_sta,
			 struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_table_node *rate_up;
	u16 rate_idx = 0;
	u8 up_idx = 0;

	for (rate_idx = 0; rate_idx < wrs_params->table_size; rate_idx++) {
		if (wrs_params->table[rate_idx].rate_down.rate_idx != WRS_INVALID_RATE)
			wrs_params->table[rate_idx].rate_down.time_th = WRS_INIT_MSEC_WEIGHT_DOWN;
		else
			wrs_params->table[rate_idx].rate_down.time_th = wrs_db->time_th_max_down;

		wrs_params->table[rate_idx].rate_down.quick_up_check = false;

		for (up_idx = 0; up_idx < WRS_TABLE_NODE_UP_MAX; up_idx++) {
			rate_up = &wrs_params->table[rate_idx].rate_up[up_idx];

			if (rate_up->rate_idx != WRS_INVALID_RATE)
				rate_up->time_th = WRS_INIT_MSEC_WEIGHT_UP;
			else
				rate_up->time_th = wrs_db->time_th_max_up;

			rate_up->quick_up_check = false;
		}

		wrs_params->table[rate_idx].frames_total = 0;
		wrs_params->table[rate_idx].ba_not_rcv_total = 0;
		wrs_params->table[rate_idx].epr_acc = 0;
	}
}

static bool cl_wrs_is_rate_valid_he(struct cl_hw *cl_hw, struct cl_wrs_sta *wrs_sta,
				    struct cl_wrs_params *wrs_params, u8 bw,
				    u8 nss, u8 mcs, u8 gi)
{
	/* Disable rates according to ce_he_mcs_nss_supp_tx */
	if ((cl_hw->conf->ce_he_mcs_nss_supp_tx[nss] + 1) <= mcs)
		return false;

	if (wrs_sta->mu_ofdma_bw != CHNL_BW_MAX && wrs_sta->mu_ofdma_bw != bw)
		return false;

	/* TB flow doesn't support 0.8us GI */
	if (WRS_TYPE_IS_RX(wrs_params) && gi == WRS_GI_VSHORT)
		return false;

	if (wrs_sta->mu_ofdma_gi != WRS_GI_MAX_HE && wrs_sta->mu_ofdma_gi != gi)
		return false;

	if (data_rate_he_x10[nss][bw][mcs][gi] < (10 * wrs_sta->he_minrate))
		return false;

	return true;
}

static bool cl_wrs_is_rate_valid_vht(struct cl_hw *cl_hw, u8 bw, u8 nss, u8 mcs)
{
	/* Disable BW160 */
	if (bw == CHNL_BW_160)
		return false;

	/* Disable VHT invalid rates (MCS9 20M 1SS, MCS9 20M 2SS) */
	if (bw == CHNL_BW_20 && mcs == WRS_MCS_9)
		if (nss == WRS_SS_1 || nss == WRS_SS_2)
			return false;

	/* Disable rates according to ce_vht_mcs_nss_supp_tx */
	if ((cl_hw->conf->ce_vht_mcs_nss_supp_tx[nss] + 1) <= mcs)
		return false;

	return true;
}

static bool cl_wrs_is_rate_valid(struct cl_hw *cl_hw, struct cl_wrs_sta *wrs_sta,
				 struct cl_wrs_params *wrs_params,
				 u8 mode, u8 bw, u8 nss, u8 mcs, u8 gi)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;

	if (gi > wrs_db->max_cap.gi || gi > wrs_sta->gi_cap[bw])
		return false;

	if (mcs < cl_hw->conf->ci_mcs_min || mcs > cl_hw->conf->ci_mcs_max)
		return false;

	if (mode == WRS_MODE_HE)
		return cl_wrs_is_rate_valid_he(cl_hw, wrs_sta, wrs_params, bw, nss, mcs, gi);

	if (mode == WRS_MODE_VHT)
		return cl_wrs_is_rate_valid_vht(cl_hw, bw, nss, mcs);

	return true;
}

static bool cl_wrs_is_rate_supported(u64 *rate_bitmap, u8 bw, u8 nss, u8 mcs)
{
	u8 rate_idx = mcs + (nss * WRS_MCS_MAX);
	u64 mask = BIT(rate_idx);

	return ((rate_bitmap[bw] & mask) ? true : false);
}

static bool cl_wrs_tables_is_up_invalid(struct cl_wrs_table *table)
{
	/*
	 * The UP_GI is not part of this if condition, because we would
	 * like to set the same up candidate for LGI & SGI (except the
	 * up from LGI to SGI).
	 */
	return ((table->rate_up[WRS_TABLE_NODE_UP_MCS].rate_idx == WRS_INVALID_RATE) &&
		(table->rate_up[WRS_TABLE_NODE_UP_BW].rate_idx == WRS_INVALID_RATE) &&
		(table->rate_up[WRS_TABLE_NODE_UP_NSS].rate_idx == WRS_INVALID_RATE) &&
		(table->rate_up[WRS_TABLE_NODE_UP_BF].rate_idx == WRS_INVALID_RATE) &&
		(table->rate_up[WRS_TABLE_NODE_UP_GI].rate_idx == WRS_INVALID_RATE));
}

static int cl_wrs_tables_max(struct cl_hw *cl_hw, struct cl_wrs_sta *wrs_sta,
			     u8 *max_bw, u8 *max_nss, u8 *max_mcs, u8 *max_gi)
{
	*max_bw = wrs_sta->max_rate_cap.bw;
	*max_nss = wrs_sta->smps_enable ? WRS_SS_1 : wrs_sta->max_rate_cap.nss;

	switch (wrs_sta->mode) {
	case WRS_MODE_CCK:
		*max_mcs = WRS_MCS_3;
		*max_gi = WRS_GI_LONG;
		break;
	case WRS_MODE_OFDM:
		*max_mcs = WRS_MCS_7;
		*max_gi = WRS_GI_LONG;
		break;
	case WRS_MODE_HT:
		*max_mcs = WRS_MCS_7;
		*max_gi = WRS_GI_SHORT;
		break;
	case WRS_MODE_VHT:
		*max_mcs = WRS_MCS_9;
		*max_gi = WRS_GI_SHORT;
		break;
	case WRS_MODE_HE:
		*max_mcs = WRS_MCS_11;
		*max_gi = WRS_GI_VSHORT;

		if (!cl_hw->conf->ce_txldpc_en) {
			struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;

			wrs_pr_verbose(wrs_db,
				       "[WRS] TX LDPC disabled: limit BW to 20MHz and MCS to 9\n");
			*max_mcs = WRS_MCS_9;
			*max_bw = CHNL_BW_20;
		}
		break;
	default:
		return -1;
	}

	return 0;
}

void cl_wrs_tables_build(struct cl_hw *cl_hw, struct cl_wrs_sta *wrs_sta,
			 struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	u8 bw = 0;
	u8 nss = 0;
	u8 mcs = 0;
	u8 gi = 0;
	u8 max_bw = 0;
	u8 max_nss = 0;
	u8 max_mcs = 0;
	u8 max_gi = 0;
	u8 up_idx = 0;
	u8 type = wrs_params->type;
	u16 rate_idx = 0;
	u16 new_rate_idx = 0;
	u16 tmp_rate_idx = 0;
	u16 max_table_size = 0;
	u16 new_table_size = 0;
	u16 (*idx_to_offt)(u32 bw, u32 nss, u32 mcs, u32 gi);
	u16 *rate_idx_sorted_by_data_rate;
	struct cl_wrs_table *ap_rate_table;
	struct cl_wrs_table *new_table = NULL;
	struct cl_wrs_table_validity *valid_rates = NULL;

	if (cl_wrs_tables_max(cl_hw, wrs_sta, &max_bw, &max_nss, &max_mcs, &max_gi))
		return;

	if (wrs_sta->mode == WRS_MODE_HE) {
		max_table_size = WRS_HE_RATE_TABLE_SIZE;
		idx_to_offt = idx_to_offt_he;
		ap_rate_table = (struct cl_wrs_table *)ap_rate_table_he;
		rate_idx_sorted_by_data_rate = rate_idx_sorted_by_data_rate_he;
	} else {
		max_table_size = WRS_HT_VHT_RATE_TABLE_SIZE;
		idx_to_offt = idx_to_offt_ht_vht;
		ap_rate_table = (struct cl_wrs_table *)ap_rate_table_ht_vht;
		rate_idx_sorted_by_data_rate = rate_idx_sorted_by_data_rate_ht_vht;
	}

	valid_rates = kzalloc(max_table_size * sizeof(struct cl_wrs_table_validity), GFP_ATOMIC);
	if (!valid_rates)
		goto out;

	wrs_sta->max_rate_cap.mcs = WRS_MCS_0;
	wrs_sta->max_rate_cap.gi = WRS_GI_LONG;

	for (bw = 0; bw <= max_bw; bw++) {
		for (nss = 0; nss <= max_nss; nss++) {
			for (mcs = 0; mcs <= max_mcs; mcs++) {
				for (gi = 0; gi <= max_gi; gi++) {
					rate_idx = idx_to_offt(bw, nss, mcs, gi);
					valid_rates[rate_idx].is_valid =
						cl_wrs_is_rate_supported(wrs_sta->supported_rates,
									 bw, nss, mcs) &&
						cl_wrs_is_rate_supported(wrs_db->ap_supported_rates,
									 bw, nss, mcs) &&
						cl_wrs_is_rate_valid(cl_hw, wrs_sta, wrs_params,
								     wrs_sta->mode,
								     bw, nss, mcs, gi);

					if (!valid_rates[rate_idx].is_valid)
						continue;

					valid_rates[rate_idx].new_rate_idx = new_table_size;
					new_table_size++;

					if (mcs > wrs_sta->max_rate_cap.mcs)
						wrs_sta->max_rate_cap.mcs = mcs;

					if (gi > wrs_sta->max_rate_cap.gi)
						wrs_sta->max_rate_cap.gi = gi;
				}
			}
		}
	}

	if (new_table_size == 0) {
		/* Error - size of table is 0, add single rate (mcs 0, 1 SS, bw 20 Mhz) */
		wrs_pr_err(wrs_db, "[WRS][%s] Table build error - Size of table is 0\n",
			   WRS_TYPE_STR(type));
		cl_wrs_sta_set_supported_rate(wrs_sta, CHNL_BW_20, WRS_SS_1, WRS_MCS_0);
		valid_rates[0].new_rate_idx = 0;
		valid_rates[0].is_valid = 1;
		new_table_size = 1;
	}

	new_table = kzalloc(new_table_size * sizeof(struct cl_wrs_table), GFP_ATOMIC);

	if (!new_table)
		goto out;

	for (rate_idx = 0; rate_idx < max_table_size; rate_idx++) {
		if (!valid_rates[rate_idx].is_valid)
			continue;

		memcpy(new_table + new_rate_idx,
		       ap_rate_table + rate_idx,
		       sizeof(struct cl_wrs_table));

		/* Set down rate */
		tmp_rate_idx = ap_rate_table[rate_idx].rate_down.rate_idx;

		while ((!valid_rates[tmp_rate_idx].is_valid) &&
		       (ap_rate_table[tmp_rate_idx].rate_down.rate_idx != tmp_rate_idx))
			tmp_rate_idx = ap_rate_table[tmp_rate_idx].rate_down.rate_idx;

		if (valid_rates[tmp_rate_idx].is_valid) {
			new_table[new_rate_idx].rate_down.rate_idx =
				valid_rates[tmp_rate_idx].new_rate_idx;
		} else {
			u16 i = 0;
			u16 down_idx = 0;
			u16 down_rate_idx = new_rate_idx;

			while (new_table[new_rate_idx].rate_down.rate_idx !=
			       rate_idx_sorted_by_data_rate[i]) {
				down_idx = rate_idx_sorted_by_data_rate[i];

				if (valid_rates[down_idx].is_valid)
					down_rate_idx = valid_rates[down_idx].new_rate_idx;
				i++;
			}

			new_table[new_rate_idx].rate_down.rate_idx = down_rate_idx;
		}

		/* Set up rates */
		for (up_idx = 0; up_idx < WRS_TABLE_NODE_UP_MAX; up_idx++) {
			tmp_rate_idx = new_table[new_rate_idx].rate_up[up_idx].rate_idx;

			if (tmp_rate_idx != WRS_INVALID_RATE &&
			    valid_rates[tmp_rate_idx].is_valid)
				new_table[new_rate_idx].rate_up[up_idx].rate_idx =
					valid_rates[tmp_rate_idx].new_rate_idx;
			else
				new_table[new_rate_idx].rate_up[up_idx].rate_idx = WRS_INVALID_RATE;
		}

		/*
		 * In case all the UP rates are invalid, find one available UP
		 * rate based on PHY rate
		 */
		if (cl_wrs_tables_is_up_invalid(&new_table[new_rate_idx])) {
			u16 i = 0;

			for (i = 0; i < max_table_size; i++)
				if (rate_idx == rate_idx_sorted_by_data_rate[i])
					break;

			i++;

			while (i < max_table_size) {
				tmp_rate_idx = rate_idx_sorted_by_data_rate[i];
				if (!valid_rates[tmp_rate_idx].is_valid) {
					i++;
					continue;
				}

				new_table[new_rate_idx].rate_up[WRS_TABLE_NODE_UP_MCS].rate_idx =
					valid_rates[tmp_rate_idx].new_rate_idx;
				break;
			}
		}

		new_rate_idx++;
	}

	if (wrs_params->table) {
		/*
		 * Copy epr_acc, frames_total and ba_not_rcv_total
		 * from the old table to the new table.
		 * Also, if initial_rate_idx is set, find the new
		 * value in the new table.
		 */
		u16 old_rate_idx = 0;
		struct cl_wrs_rate *initial_old_rate = NULL;

		if (wrs_params->initial_rate_idx != WRS_INVALID_RATE) {
			initial_old_rate = &wrs_params->table[wrs_params->initial_rate_idx].rate;
			wrs_params->initial_rate_idx = WRS_INVALID_RATE;
		}

		for (rate_idx = 0; rate_idx < new_table_size; rate_idx++) {
			old_rate_idx = cl_wrs_tables_find_rate_idx(wrs_params,
								   new_table[rate_idx].rate.bw,
								   new_table[rate_idx].rate.nss,
								   new_table[rate_idx].rate.mcs,
								   new_table[rate_idx].rate.gi);

			if (initial_old_rate &&
			    new_table[rate_idx].rate.bw == initial_old_rate->bw &&
			    new_table[rate_idx].rate.nss == initial_old_rate->nss &&
			    new_table[rate_idx].rate.mcs == initial_old_rate->mcs &&
			    new_table[rate_idx].rate.gi == initial_old_rate->gi) {
				wrs_params->initial_rate_idx = rate_idx;
				initial_old_rate = NULL;
			}

			if (old_rate_idx == WRS_INVALID_RATE)
				continue;

			new_table[rate_idx].epr_acc =
				wrs_params->table[old_rate_idx].epr_acc;
			new_table[rate_idx].frames_total =
				wrs_params->table[old_rate_idx].frames_total;
			new_table[rate_idx].ba_not_rcv_total =
				wrs_params->table[old_rate_idx].ba_not_rcv_total;
		}

		kfree(wrs_params->table);
	}

	wrs_params->table = new_table;
	wrs_params->table_size = new_table_size;

	if (wrs_params->rate_idx != WRS_INVALID_RATE) {
		/*
		 * Check if current rate is included in the new table.
		 * If not select a rate from the new table accroding to rssi.
		 */
		struct cl_wrs_rate_params *rate_params = &wrs_params->rate_params;

		rate_idx = cl_wrs_tables_find_rate_idx(wrs_params,
						       rate_params->bw, rate_params->nss,
						       rate_params->mcs, rate_params->gi);

		if (rate_idx != WRS_INVALID_RATE) {
			wrs_params->rate_idx = rate_idx;
		} else {
			if (wrs_params->is_fixed_rate) {
				wrs_params->is_fixed_rate = false;
				wrs_pr_verbose(wrs_db,
					       "[WRS][%s] Disable fixed rate for station %u\n",
					       WRS_TYPE_STR(type), wrs_sta->sta_idx);
			}

			cl_wrs_sta_select_first_rate(cl_hw, wrs_db, wrs_sta, wrs_params);
			cl_wrs_cntrs_reset(wrs_sta, wrs_params);
		}
	}

out:
	kfree(valid_rates);
}

u16 cl_wrs_tables_find_rate_idx(struct cl_wrs_params *wrs_params,
				u8 bw, u8 nss, u8 mcs, u8 gi)
{
	struct cl_wrs_table *table = wrs_params->table;
	u16 rate_idx = 0;

	for (rate_idx = 0; rate_idx < wrs_params->table_size; rate_idx++)
		if (bw == table[rate_idx].rate.bw &&
		    nss == table[rate_idx].rate.nss &&
		    mcs == table[rate_idx].rate.mcs &&
		    gi == table[rate_idx].rate.gi)
			return rate_idx;

	return WRS_INVALID_RATE;
}
