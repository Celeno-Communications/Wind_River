// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_wrs_ap.h"

static void cl_wrs_ap_set_bitmap(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db)
{
	u8 mcs, bw, nss, rate_idx;

	memset(wrs_db->ap_supported_rates, 0, sizeof(wrs_db->ap_supported_rates));

	for (bw = cl_hw->conf->ci_wrs_min_bw; bw <= wrs_db->max_cap.bw; bw++)
		for (nss = 0; nss <= wrs_db->max_cap.nss; nss++)
			for (mcs = 0; mcs <= wrs_db->max_cap.mcs; mcs++) {
				rate_idx = mcs + (nss * WRS_MCS_MAX);
				wrs_db->ap_supported_rates[bw] |= BIT(rate_idx);
			}
}

static void cl_wrs_ap_capab_print(struct cl_hw *cl_hw)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_wrs_rate *max_cap = &wrs_db->max_cap;
	u8 bw_mhz = BW_TO_MHZ(max_cap->bw);

	pr_debug("\n");
	pr_debug("AP max capabilities\n");
	pr_debug("-------------------\n");
	pr_debug("Band : %ug\n", cl_hw->conf->ci_band_num);
	pr_debug("Mode : %s\n", WRS_MODE_STR(wrs_db->mode));
	pr_debug("BW   : %uMHz\n", bw_mhz);
	pr_debug("NSS  : %u\n", max_cap->nss);
	pr_debug("MCS  : %u\n", max_cap->mcs);
	pr_debug("GI   : %u\n", max_cap->gi);
}

void cl_wrs_ap_capab_set(struct cl_hw *cl_hw)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_wrs_rate *max_cap = &wrs_db->max_cap;
	u8 conf_bw = cl_hw->conf->ce_channel_bandwidth;
	u8 conf_nss = cl_hw->conf->ce_tx_nss - 1;
	u8 conf_gi = cl_hw->conf->ha_short_guard_interval;

	switch (cl_hw->conf->ce_wireless_mode) {
	case WIRELESS_MODE_HE:
	case WIRELESS_MODE_HT_VHT_HE:
		wrs_db->mode = WRS_MODE_HE;
		max_cap->bw = conf_bw;
		max_cap->nss = conf_nss;
		max_cap->mcs = WRS_MCS_11;
		max_cap->gi = conf_gi ? WRS_GI_VSHORT : 0;
		break;
	case WIRELESS_MODE_HT_VHT:
		wrs_db->mode = WRS_MODE_VHT;
		max_cap->bw = conf_bw;
		max_cap->nss = conf_nss;
		max_cap->mcs = WRS_MCS_9;
		max_cap->gi = conf_gi ? WRS_GI_SHORT : 0;
		break;
	case WIRELESS_MODE_HT:
		wrs_db->mode = WRS_MODE_HT;
		max_cap->bw = min_t(u8, conf_bw, CHNL_BW_80);
		max_cap->nss = conf_nss;
		max_cap->mcs = WRS_MCS_7;
		max_cap->gi = conf_gi ? WRS_GI_SHORT : 0;
		break;
	case WIRELESS_MODE_LEGACY:
	default:
		if (cl_hw->conf->ha_hw_mode == HW_MODE_B) {
			wrs_db->mode = WRS_MODE_CCK;
			max_cap->mcs = WRS_MCS_3;
		} else {
			wrs_db->mode = WRS_MODE_OFDM;
			max_cap->mcs = WRS_MCS_7;
		}

		max_cap->bw = CHNL_BW_20;
		max_cap->nss = 0;
		max_cap->gi = 0;
		break;
	}

	if (cl_hw->conf->ci_wrs_max_bw < max_cap->bw) {
		max_cap->bw = cl_hw->conf->ci_wrs_max_bw;
		pr_debug("[WRS] Max BW limited to %uMHz\n", BW_TO_MHZ(max_cap->bw));
	}

	wrs_db->coex_bw = max_t(u8, max_cap->bw, CHNL_BW_40);

	cl_wrs_ap_set_bitmap(cl_hw, wrs_db);

	cl_wrs_ap_capab_print(cl_hw);
}

void cl_wrs_ap_capab_modify_bw(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db, u8 max_bw)
{
	wrs_db->max_cap.bw = max_bw;

	cl_wrs_ap_set_bitmap(cl_hw, wrs_db);
}
