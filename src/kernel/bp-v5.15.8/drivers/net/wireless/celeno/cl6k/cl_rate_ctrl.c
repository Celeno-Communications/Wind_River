// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_rate_ctrl.h"
#include "cl_tx.h"
#include "cl_band.h"
#include "cl_bf.h"
#include "cl_msg_tx.h"
#include "cl_utils.h"

u32 cl_rate_ctrl_generate(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			  u8 mode, u8 bw, u8 nss, u8 mcs, u8 gi,
			  bool fallback_en)
{
	union cl_rate_ctrl_info rate_ctrl_info;

	rate_ctrl_info.word = 0;

	/* Format_mod + mcs_index */
	if (mode == WRS_MODE_HE) {
		rate_ctrl_info.field.mcs_index = (nss << 4) | mcs;
		rate_ctrl_info.field.format_mod = FORMATMOD_HE_SU;
	} else if (mode == WRS_MODE_VHT) {
		rate_ctrl_info.field.mcs_index = (nss << 4) | mcs;
		rate_ctrl_info.field.format_mod = FORMATMOD_VHT;
	} else if (mode == WRS_MODE_HT) {
		rate_ctrl_info.field.mcs_index = (nss << 3) | mcs;
		rate_ctrl_info.field.format_mod = FORMATMOD_HT_MF;
	} else if (mode == WRS_MODE_OFDM) {
		rate_ctrl_info.field.mcs_index = mcs + RATE_CTRL_OFFSET_OFDM;
		rate_ctrl_info.field.format_mod =
			(bw == CHNL_BW_20) ? FORMATMOD_NON_HT : FORMATMOD_NON_HT_DUP_OFDM;
	} else { /* WRS_MODE_CCK */
		rate_ctrl_info.field.mcs_index = mcs;
		rate_ctrl_info.field.format_mod = FORMATMOD_NON_HT;
	}

	/* Gi */
	rate_ctrl_info.field.gi = convert_gi_format_wrs_to_fw(mode, gi);

	/* Bw */
	rate_ctrl_info.field.bw = bw;

	/* Fallback */
	rate_ctrl_info.field.fallback = fallback_en;

	/* Tx_bf */
	if (cl_sta && cl_bf_is_on(cl_hw, cl_sta, nss))
		rate_ctrl_info.field.tx_bf = true;

	/* Pre_type/stbc */
	if (rate_ctrl_info.field.format_mod == FORMATMOD_NON_HT)
		rate_ctrl_info.field.pre_type_or_stbc = 1;

	return rate_ctrl_info.word;
}

void cl_rate_ctrl_convert(union cl_rate_ctrl_info *rate_ctrl_info)
{
	u32 format_mod = rate_ctrl_info->field.format_mod;

	/*
	 * Convert gi from firmware format to driver format
	 * !!! Must be done before converting the format mode !!!
	 */
	rate_ctrl_info->field.gi = convert_gi_format_fw_to_wrs(format_mod,
							       rate_ctrl_info->field.gi);

	/* Convert format_mod from firmware format to WRS format */
	if (format_mod >= FORMATMOD_HE_SU) {
		rate_ctrl_info->field.format_mod = WRS_MODE_HE;
	} else if (format_mod == FORMATMOD_VHT) {
		rate_ctrl_info->field.format_mod = WRS_MODE_VHT;
	} else if (format_mod >= FORMATMOD_HT_MF) {
		rate_ctrl_info->field.format_mod = WRS_MODE_HT;
	} else if (format_mod == FORMATMOD_NON_HT_DUP_OFDM) {
		rate_ctrl_info->field.format_mod = WRS_MODE_OFDM;
	} else {
		if (rate_ctrl_info->field.mcs_index >= RATE_CTRL_OFFSET_OFDM)
			rate_ctrl_info->field.format_mod = WRS_MODE_OFDM;
		else
			rate_ctrl_info->field.format_mod = WRS_MODE_CCK;
	}
}

void cl_rate_ctrl_parse(union cl_rate_ctrl_info *rate_ctrl_info, u8 *nss, u8 *mcs)
{
	switch (rate_ctrl_info->field.format_mod) {
	case WRS_MODE_HE:
	case WRS_MODE_VHT:
		*nss = (rate_ctrl_info->field.mcs_index >> 4);
		*mcs = (rate_ctrl_info->field.mcs_index & 0xF);
		break;
	case WRS_MODE_HT:
		*nss = (rate_ctrl_info->field.mcs_index >> 3);
		*mcs = (rate_ctrl_info->field.mcs_index & 0x7);
		break;
	case WRS_MODE_OFDM:
		*nss = 0;
		*mcs = rate_ctrl_info->field.mcs_index - RATE_CTRL_OFFSET_OFDM;
		break;
	case WRS_MODE_CCK:
		*nss = 0;
		*mcs = rate_ctrl_info->field.mcs_index;
		break;
	default:
		*nss = *mcs = 0;
	}
}

void cl_rate_ctrl_set_default(struct cl_hw *cl_hw)
{
	u32 rate_ctrl = 0;
	union cl_rate_ctrl_info_he rate_ctrl_he;

	/* HE default */
	rate_ctrl_he.word = 0;
	rate_ctrl_he.field.spatial_conf = RATE_CNTRL_HE_SPATIAL_CONF_DEF;
	rate_ctrl = cl_rate_ctrl_generate(cl_hw, NULL, WRS_MODE_HE,
					  0, 0, 0, 0, false);

	cl_msg_tx_update_rate_dl(cl_hw, 0xff, rate_ctrl, 0, 0,
				 RATE_OP_MODE_DEFAULT_HE, 0, LTF_X4, 0, rate_ctrl_he.word);

	/* OFDM default */
	rate_ctrl = cl_rate_ctrl_generate(cl_hw, NULL, WRS_MODE_OFDM, 0, 0,
					  cl_hw->conf->ce_default_mcs_ofdm, 0, false);

	cl_msg_tx_update_rate_dl(cl_hw, 0xff, rate_ctrl, 0, 0,
				 RATE_OP_MODE_DEFAULT_OFDM, 0, 0, 0, 0);

	/* CCK default */
	if (cl_band_is_24g(cl_hw)) {
		rate_ctrl = cl_rate_ctrl_generate(cl_hw, NULL, WRS_MODE_CCK, 0, 0,
						  cl_hw->conf->ce_default_mcs_cck, 0, false);

		cl_msg_tx_update_rate_dl(cl_hw, 0xff, rate_ctrl, 0, 0,
					 RATE_OP_MODE_DEFAULT_CCK, 0, 0, 0, 0);
	}
}

void cl_rate_ctrl_set_default_per_he_minrate(struct cl_hw *cl_hw, u8 bw,
					     u8 nss, u8 mcs, u8 gi)
{
	union cl_rate_ctrl_info_he rate_ctrl_he;
	u32 rate_ctrl = 0;
	u8 ltf = cl_map_gi_to_ltf(WRS_MODE_HE, gi);

	rate_ctrl_he.word = 0;
	rate_ctrl_he.field.spatial_conf = RATE_CNTRL_HE_SPATIAL_CONF_DEF;
	rate_ctrl = cl_rate_ctrl_generate(cl_hw, NULL, WRS_MODE_HE, bw,
					  nss, mcs, gi, false);

	cl_msg_tx_update_rate_dl(cl_hw, 0xff, rate_ctrl, 0, 0,
				 RATE_OP_MODE_DEFAULT_HE, 0, ltf,
				 0, rate_ctrl_he.word);

	cl_msg_tx_update_rate_dl(cl_hw, 0xff, rate_ctrl, 0, 0,
				 RATE_OP_MODE_MCAST, 0, ltf, 0, 0);

	cl_msg_tx_update_rate_dl(cl_hw, 0xff, rate_ctrl, 0, 0,
				 RATE_OP_MODE_BCAST, 0, ltf, 0, 0);
}

bool cl_rate_ctrl_set_mcast(struct cl_hw *cl_hw, u8 mode, u8 mcs)
{
	u32 rate_ctrl_mcast = cl_rate_ctrl_generate(cl_hw, NULL, mode, 0, 0, mcs,
						    WRS_GI_LONG, false);
	u8 ltf = cl_map_gi_to_ltf(mode, WRS_GI_LONG);

	if (cl_msg_tx_update_rate_dl(cl_hw, 0xff, rate_ctrl_mcast, 0, 0,
				     RATE_OP_MODE_MCAST, 0, ltf, 0, 0))
		return false;

	return true;
}

bool cl_rate_ctrl_set_fixed(struct cl_hw *cl_hw, u32 rate_ctrl_he, u8 mode, u8 mcs, u8 nss,
			    u8 bw, u8 gi, u8 gid, u8 ltf_field)
{
	u32 rate_ctrl_fixed = cl_rate_ctrl_generate(cl_hw, NULL, mode, bw, nss,
						    mcs, gi, false);

	if (cl_msg_tx_update_rate_dl(cl_hw, 0xff, rate_ctrl_fixed, 0, bw, RATE_OP_MODE_FIXED,
				     gid, ltf_field, 0, rate_ctrl_he))
		return false;

	return true;
}

bool cl_rate_ctrl_set_dbgfs(struct cl_hw *cl_hw, u8 sta_idx, u32 rate_ctrl, u32 rate_ctrl_he,
			    u8 op_mode, u8 bw, u8 gid, u8 ltf_field)
{
	/*
	 * op_mode can be RATE_OP_MODE_FIXED or RATE_OP_MODE_STA_MU.
	 * Therefore rate_fallback should be 0.
	 */
	if (cl_msg_tx_update_rate_dl(cl_hw, sta_idx, rate_ctrl, 0, bw, op_mode, gid,
				     ltf_field, 0, rate_ctrl_he))
		return false;

	return true;
}

void cl_rate_ctrl_set_ate_agg(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_ate_db *ate_db = &cl_hw->ate_db;
	union cl_rate_ctrl_info rate_ctrl;
	union cl_rate_ctrl_info_he rate_ctrl_he;
	u8 ltf_mode = cl_map_gi_to_ltf(ate_db->mode, ate_db->gi);
	u8 sta_idx = cl_sta->sta_idx;

	rate_ctrl_he.word = 0;
	rate_ctrl_he.field.spatial_conf = RATE_CNTRL_HE_SPATIAL_CONF_DEF;

	rate_ctrl.word = cl_rate_ctrl_generate(cl_hw, cl_sta, ate_db->mode, ate_db->bw,
					       ate_db->nss, ate_db->mcs, ate_db->gi, false);

	cl_msg_tx_update_rate_dl(cl_hw, sta_idx, rate_ctrl.word, 0, ate_db->bw,
				 RATE_OP_MODE_STA_SU, 0, ltf_mode, 0, rate_ctrl_he.word);
}

static u8 cl_rate_ctrl_get_min(struct cl_hw *cl_hw)
{
	if (cl_hw->conf->ci_min_he_en &&
	    cl_hw->conf->ce_wireless_mode == WIRELESS_MODE_HE)
		return RATE_CTRL_ENTRY_MIN_HE;

	if (cl_hw_mode_is_b_or_bg(cl_hw) && cl_hw->conf->ci_cck_en)
		return RATE_CTRL_ENTRY_MIN_CCK;

	return RATE_CTRL_ENTRY_MIN_OFDM;
}

void cl_rate_ctrl_update_desc_single(struct cl_hw *cl_hw, struct tx_host_info *info,
				     struct cl_sw_txhdr *sw_txhdr)
{
	struct ieee80211_hdr *mac_hdr = sw_txhdr->hdr80211;
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(sw_txhdr->skb);
	bool is_data = ieee80211_is_data(sw_txhdr->fc);

	if (sw_txhdr->cl_sta && is_data) {
		if (cl_tx_ctrl_is_eapol(tx_info)) {
			info->rate_ctrl_entry = cl_rate_ctrl_get_min(cl_hw);
		} else {
			if (cl_hw->entry_fixed_rate)
				info->rate_ctrl_entry = RATE_CTRL_ENTRY_FIXED_RATE;
			else
				info->rate_ctrl_entry = RATE_CTRL_ENTRY_STA;
		}
	} else {
		if (sw_txhdr->is_bcn) {
			info->rate_ctrl_entry = cl_rate_ctrl_get_min(cl_hw);
		} else if (is_multicast_ether_addr(mac_hdr->addr1) &&
			   !is_broadcast_ether_addr(mac_hdr->addr1)) {
			info->rate_ctrl_entry = RATE_CTRL_ENTRY_MCAST;
		} else if (is_broadcast_ether_addr(mac_hdr->addr1) &&
			   !cl_hw->entry_fixed_rate) {
			info->rate_ctrl_entry = RATE_CTRL_ENTRY_BCAST;
		} else {
			if (cl_hw->entry_fixed_rate && is_data)
				info->rate_ctrl_entry = RATE_CTRL_ENTRY_FIXED_RATE;
			else
				info->rate_ctrl_entry = cl_rate_ctrl_get_min(cl_hw);
		}
	}
}

void cl_rate_ctrl_update_desc_agg(struct cl_hw *cl_hw, struct tx_host_info *info)
{
	/* For aggregation there are only two options - STA and FIXED_RATE */
	if (cl_hw->entry_fixed_rate)
		info->rate_ctrl_entry = RATE_CTRL_ENTRY_FIXED_RATE;
	else
		info->rate_ctrl_entry = RATE_CTRL_ENTRY_STA;
}
