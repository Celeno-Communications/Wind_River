// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/string.h>
#include "cl_power.h"
#include "cl_chan_info.h"
#include "cl_utils.h"
#include "cl_band.h"
#include "string.h"
#include "cl_channel.h"
#include "cl_e2p.h"
#include "cl_otp.h"

static s32 convert_str_int_q8(s8 *str)
{
	s32 x, y;

	if (!str)
		return 0;
	if (sscanf(str, "%d.%2d", &x, &y) == 0)
		return 0;
	if (!strstr(str, "."))
		return x << 8;
	if (y < 10 && (*(strstr(str, ".") + 1) != '0'))
		y *= 10;
	return ((x * 100 + y) << 8) / 100;
}

u8 cl_power_tx_ant(struct cl_hw *cl_hw, enum cl_wrs_mode mode)
{
	if (mode == WRS_MODE_CCK)
		return hweight8(cl_hw->conf->ce_cck_tx_ant_mask);

	return cl_hw->num_antennas;
}

s32 cl_power_antenna_gain_q8(struct cl_hw *cl_hw)
{
	u8 channel = cl_hw->channel;

	if (channel >= 36 && channel <= 64)
		return convert_str_int_q8(cl_hw->conf->ce_ant_gain_36_64);
	else if (channel >= 100 && channel <= 140)
		return convert_str_int_q8(cl_hw->conf->ce_ant_gain_100_140);
	else if (channel >= 149 && channel < 165)
		return convert_str_int_q8(cl_hw->conf->ce_ant_gain_149_165);
	else
		return convert_str_int_q8(cl_hw->conf->ce_ant_gain); /* 2.4g and 6g */
}

s32 cl_power_antenna_gain_q1(struct cl_hw *cl_hw)
{
	return cl_power_antenna_gain_q8(cl_hw) >> 7;
}

s32 cl_power_array_gain_q8(struct cl_hw *cl_hw, u8 tx_ant)
{
	/*
	 * Format in NVRAM of ce_arr_gain=A,B
	 * A is the array gain with 1 tx_ant, B is with 2 tx_ant.
	 */
	int arr_gain_val = 0;
	int arr_gain_len = 0;
	int idx = 0;
	s8 *arr_gain_cpy = NULL;
	s8 *arr_gain_str = NULL;
	s8 *arr_gain_tmp = NULL;

	arr_gain_len = strlen(cl_hw->conf->ce_arr_gain) + 1;
	arr_gain_cpy = kzalloc(arr_gain_len, GFP_ATOMIC);

	if (!arr_gain_cpy)
		return 0;

	/* Copy cl_hw->conf->ce_arr_gain so its value won't be changed by cl_strtok_r() */
	memcpy(arr_gain_cpy, cl_hw->conf->ce_arr_gain, arr_gain_len);

	/* Arr_gain_str points to the array gain of 1 tx_ant */
	arr_gain_str = cl_strtok_r(arr_gain_cpy, ",", &arr_gain_tmp);

	/* Only a single value in ce_arr_gain - same value will be applied for all tx_ant */
	if (!arr_gain_tmp) {
		arr_gain_val = convert_str_int_q8(arr_gain_cpy);
	} else {
		/* Keep iterating until getting to the correct ant idx */
		for (idx = 1; arr_gain_str && (idx < tx_ant); idx++)
			arr_gain_str = cl_strtok_r(NULL, ",", &arr_gain_tmp);

		arr_gain_val = arr_gain_str ? convert_str_int_q8(arr_gain_str) : 0;
	}

	kfree(arr_gain_cpy);

	return arr_gain_val;
}

s8 cl_power_array_gain_q2(struct cl_hw *cl_hw, u8 tx_ant)
{
	return (s8)(cl_power_array_gain_q8(cl_hw, tx_ant) >> 6);
}

s32 cl_power_array_gain_q1(struct cl_hw *cl_hw, u8 tx_ant)
{
	return cl_power_array_gain_q8(cl_hw, tx_ant) >> 7;
}

static s32 cl_power_bf_gain_q8(struct cl_hw *cl_hw, u8 nss)
{
	/*
	 * Format in NVRAM of ce_bf_gain=A,B
	 * A is the gain for 1 NSS, B is the gain for 2 NSS
	 */
	int bf_gain_val = 0;
	int bf_gain_len = 0;
	int idx = 0;
	s8 *bf_gain_ptr = NULL;
	s8 *bf_gain_cpy = NULL;
	s8 *bf_gain_str = NULL;
	s8 *bf_gain_tmp = NULL;

	bf_gain_ptr = cl_hw->conf->ce_bf_gain;
	bf_gain_len = strlen(bf_gain_ptr) + 1;
	bf_gain_cpy = kzalloc(bf_gain_len, GFP_ATOMIC);

	if (!bf_gain_cpy)
		return 0;

	/* Copy cl_hw->conf->ce_bf_gain_*_ant so its value won't be changed by cl_strtok_r() */
	memcpy(bf_gain_cpy, bf_gain_ptr, bf_gain_len);

	/* Bf_gain_str points to the bf gain of 1 SS */
	bf_gain_str = cl_strtok_r(bf_gain_cpy, ",", &bf_gain_tmp);

	/* Keep iterating until getting to the correct ss index */
	for (idx = 0; bf_gain_str && (idx < nss); idx++)
		bf_gain_str = cl_strtok_r(NULL, ",", &bf_gain_tmp);

	bf_gain_val = bf_gain_str ? convert_str_int_q8(bf_gain_str) : 0;

	kfree(bf_gain_cpy);

	return bf_gain_val;
}

s32 cl_power_bf_gain_q1(struct cl_hw *cl_hw, u8 nss)
{
	return cl_power_bf_gain_q8(cl_hw, nss) >> 7;
}

static s32 cl_power_min_ant_q8(struct cl_hw *cl_hw)
{
	return convert_str_int_q8(cl_hw->conf->ci_min_ant_pwr);
}

s32 cl_power_min_ant_q1(struct cl_hw *cl_hw)
{
	return cl_power_min_ant_q8(cl_hw) >> 7;
};

s8 cl_power_bw_factor_q2(struct cl_hw *cl_hw, u8 bw)
{
	/*
	 * Format in NVRAM of ci_bw_factor=A,B,C,D
	 * A is the bw factor for bw 20MHz, B is for 40MHz and so on..
	 */
	int bw_factor_val = 0;
	int bw_factor_len = 0;
	int idx = 0;
	s8 *bw_factor_cpy = NULL;
	s8 *bw_factor_str = NULL;
	s8 *bw_factor_tmp = NULL;

	bw_factor_len = strlen(cl_hw->conf->ci_bw_factor) + 1;
	bw_factor_cpy = kzalloc(bw_factor_len, GFP_ATOMIC);

	if (!bw_factor_cpy)
		return 0;

	/* Copy cl_hw->conf->ci_bw_factor so its value won't be changed by cl_strtok_r() */
	memcpy(bw_factor_cpy, cl_hw->conf->ci_bw_factor, bw_factor_len);

	/* Bw_factor_str points to the bw factor of 20MHz */
	bw_factor_str = cl_strtok_r(bw_factor_cpy, ",", &bw_factor_tmp);

	/* Only a single value in ci_bw_factor - same value will be applied for all bandwidths */
	if (!bw_factor_tmp) {
		bw_factor_val = convert_str_int_q8(bw_factor_cpy);
	} else {
		/* Keep iterating until getting to the correct bw index */
		for (idx = 0; bw_factor_str && (idx < bw); idx++)
			bw_factor_str = cl_strtok_r(NULL, ",", &bw_factor_tmp);

		bw_factor_val = bw_factor_str ? convert_str_int_q8(bw_factor_str) : 0;
	}

	kfree(bw_factor_cpy);

	return (s8)(bw_factor_val >> 6);
}

static s32 cl_power_average_calib_q8(struct cl_hw *cl_hw, u8 ant_num)
{
	u8 ant = 0;
	u8 chan_idx = cl_channel_to_index(cl_hw, cl_hw->channel);
	s32 total_calib_pow = 0;
	u8 first_power_offset = 0;

	if (chan_idx == INVALID_CHAN_IDX)
		return 0;

	if (cl_hw->chip->conf->ce_eeprom_en == E2P_MODE_ENABLED) {
		if (cl_e2p_read(cl_hw->chip, &first_power_offset, 1, ADDR_WIFI_VAL_PL0_E2P))
			return 0;
	} else {
		if (cl_otp_read_bytes(cl_hw->chip, &first_power_offset, 1, ADDR_WIFI_VAL_PL0_OTP))
			return 0;
	}

	for (ant = 0; ant < ant_num; ant++)
		total_calib_pow += first_power_offset;

	return ((total_calib_pow << 8) / ant_num);
}

s32 cl_power_average_calib_q1(struct cl_hw *cl_hw, u8 ant_num)
{
	return cl_power_average_calib_q8(cl_hw, ant_num) >> 7;
}

static s32 cl_power_total_q8(struct cl_hw *cl_hw, s8 pwr_offset_q1, u8 tx_ant, u8 nss,
			     enum cl_wrs_mode mode, bool is_auto_resp)
{
	s32 bf_gain_q8 =  0;
	s32 antenna_gain_q8 = cl_power_antenna_gain_q8(cl_hw);
	s32 array_gain_q8 = cl_power_array_gain_q8(cl_hw, tx_ant);
	s32 pwr_offset_q8 = (s32)pwr_offset_q1 << 7;
	s32 calib_power_q8 = cl_power_average_calib_q8(cl_hw, tx_ant);
	s32 total_power_q8 = 0;

	if (!is_auto_resp)
		bf_gain_q8 = (mode > WRS_MODE_OFDM) ? cl_power_bf_gain_q8(cl_hw, nss) : 0;

	total_power_q8 = calib_power_q8 + bf_gain_q8 + array_gain_q8 +
		antenna_gain_q8 + pwr_offset_q8;

	/* FCC calculation */
	if (cl_hw->channel_info.standard == CL_STANDARD_FCC)
		total_power_q8 -= min(bf_gain_q8 + antenna_gain_q8, 6 << 8);

	return total_power_q8;
}

s32 cl_power_total_q1(struct cl_hw *cl_hw, s8 pwr_offset_q1, u8 tx_ant, u8 nss,
		      enum cl_wrs_mode mode, bool is_auto_resp)
{
	return cl_power_total_q8(cl_hw, pwr_offset_q1, tx_ant, nss, mode, is_auto_resp) >> 7;
}

static s32 cl_power_eirp_delta_q1(struct cl_hw *cl_hw, u8 bw, s8 pwr_offset_q1, u8 tx_ant,
				  u8 nss, enum cl_wrs_mode mode, bool is_auto_resp)
{
	/* Calculate total TX power */
	s32 total_power_q8 = cl_power_total_q8(cl_hw, pwr_offset_q1, tx_ant, nss,
					       mode, is_auto_resp);

	/* EIRP power limit */
	s32 eirp_power_limit_q8 = cl_chan_info_get_eirp_limit_q8(cl_hw, bw);

	/* Delta between total TX power and EIRP limit */
	return (total_power_q8 - eirp_power_limit_q8) >> 7;
}

static s8 cl_power_calc_q1(struct cl_hw *cl_hw, s8 mcs_offset_q1, u8 bw, u8 nss,
			   enum cl_wrs_mode mode, bool is_auto_resp, u8 *trunc_pwr_q1)
{
	/* Result is in 0.5dBm resolution */
	u8 tx_ant = cl_power_tx_ant(cl_hw, mode);
	s32 calib_power_q1 = cl_power_average_calib_q1(cl_hw, tx_ant);
	s32 res_q1 = calib_power_q1 + mcs_offset_q1;
	s32 min_pwr_q1 = POWER_MIN_DB_Q1;

	if (cl_hw->channel_info.use_channel_info && cl_hw->conf->ci_eirp_regulatory_en) {
		s32 delta_power_q1 = cl_power_eirp_delta_q1(cl_hw, bw, mcs_offset_q1,
							    tx_ant, nss, mode, is_auto_resp);

		if (delta_power_q1 > 0) {
			/*
			 * If tx power is greater than the limitation
			 * subtract delta power from the result
			 */
			res_q1 -= delta_power_q1;
			*trunc_pwr_q1 = delta_power_q1;
		} else {
			*trunc_pwr_q1 = 0;
		}
	} else {
		*trunc_pwr_q1 = 0;
	}

	if (is_auto_resp)
		min_pwr_q1 += cl_power_min_ant_q1(cl_hw);

	if (res_q1 < min_pwr_q1) {
		*trunc_pwr_q1 = max((s32)(*trunc_pwr_q1) - min_pwr_q1 - res_q1, 0);
		res_q1 = min_pwr_q1;
	}

	if (is_auto_resp)
		res_q1 += cl_power_array_gain_q1(cl_hw, tx_ant);

	return (s8)res_q1;
}

static s8 cl_power_offset_he(struct cl_hw *cl_hw, u8 bw, u8 mcs)
{
	u8 channel = cl_hw->channel;
	s8 *ppmcs = NULL;

	switch (cl_hw->conf->ci_band_num) {
	case BAND_5G:
		if (channel >= 36 && channel <= 64)
			ppmcs = cl_hw->conf->ce_ppmcs_offset_he_36_64;
		else if (channel >= 100 && channel <= 140)
			ppmcs = cl_hw->conf->ce_ppmcs_offset_he_100_140;
		else
			ppmcs = cl_hw->conf->ce_ppmcs_offset_he_149_165;
		break;
	case BAND_24G:
		ppmcs = cl_hw->conf->ce_ppmcs_offset_he;
		break;
	case BAND_6G:
		ppmcs = cl_hw->conf->ce_ppmcs_offset_he_6g;
		break;
	default:
		return 0;
	}

	return ppmcs[mcs] + cl_hw->conf->ce_ppbw_offset[bw];
}

static s8 cl_power_offset_ht_vht(struct cl_hw *cl_hw, u8 bw, u8 mcs)
{
	u8 channel = cl_hw->channel;
	s8 *ppmcs = NULL;

	switch (cl_hw->conf->ci_band_num) {
	case BAND_5G:
		if (channel >= 36 && channel <= 64)
			ppmcs = cl_hw->conf->ce_ppmcs_offset_ht_vht_36_64;
		else if (channel >= 100 && channel <= 140)
			ppmcs = cl_hw->conf->ce_ppmcs_offset_ht_vht_100_140;
		else
			ppmcs = cl_hw->conf->ce_ppmcs_offset_ht_vht_149_165;
		break;
	case BAND_24G:
		ppmcs = cl_hw->conf->ce_ppmcs_offset_ht;
		break;
	case BAND_6G:
	default:
		return 0;
	}

	return ppmcs[mcs] + cl_hw->conf->ce_ppbw_offset[bw];
}

static s8 cl_power_offset_ofdm(struct cl_hw *cl_hw, u8 mcs)
{
	u8 channel = cl_hw->channel;
	s8 *ppmcs = NULL;

	switch (cl_hw->conf->ci_band_num) {
	case BAND_5G:
		if (channel >= 36 && channel <= 64)
			ppmcs = cl_hw->conf->ce_ppmcs_offset_ofdm_36_64;
		else if (channel >= 100 && channel <= 140)
			ppmcs = cl_hw->conf->ce_ppmcs_offset_ofdm_100_140;
		else
			ppmcs = cl_hw->conf->ce_ppmcs_offset_ofdm_149_165;
		break;
	case BAND_24G:
		ppmcs = cl_hw->conf->ce_ppmcs_offset_ofdm;
		break;
	case BAND_6G:
	default:
		return 0;
	}

	return ppmcs[mcs] + cl_hw->conf->ce_ppbw_offset[CHNL_BW_20];
}

static s8 cl_power_offset_cck(struct cl_hw *cl_hw, u8 mcs)
{
	s8 *ppmcs = cl_hw->conf->ce_ppmcs_offset_cck;

	if (cl_band_is_24g(cl_hw))
		return ppmcs[mcs] + cl_hw->conf->ce_ppbw_offset[CHNL_BW_20];

	return 0;
}

s8 cl_power_offset_q1(struct cl_hw *cl_hw, u8 mode, u8 bw, u8 mcs)
{
	if (mode == WRS_MODE_HE)
		return cl_power_offset_he(cl_hw, bw, mcs);
	else if (mode == WRS_MODE_HT || mode == WRS_MODE_VHT)
		return cl_power_offset_ht_vht(cl_hw, bw, mcs);
	else if (mode == WRS_MODE_OFDM)
		return cl_power_offset_ofdm(cl_hw, mcs);
	else if (mode == WRS_MODE_CCK)
		return cl_power_offset_cck(cl_hw, mcs);

	return 0;
}

#define UPPER_POWER_MARGIN_Q2 (38 << 2)
#define LOWER_POWER_MARGIN_Q2 (50 << 2)

s8 cl_power_offset_check_margin(struct cl_hw *cl_hw, u8 bw, u8 ant_idx, s8 offset_q2)
{
	s8 new_offset_q2 = 0;
	s8 bw_factor_q2 = cl_hw->power_db.bw_factor_q2[bw];
	s8 ant_factor_q2 = cl_hw->power_db.ant_factor_q2[ant_idx];
	s8 total_offset_upper_q2 = bw_factor_q2 + offset_q2;
	s8 total_offset_lower_q2 = bw_factor_q2 + ant_factor_q2 + offset_q2;
	bool upper_limit_valid = (total_offset_upper_q2 <= UPPER_POWER_MARGIN_Q2);
	bool lower_limit_valid = (total_offset_lower_q2 <= LOWER_POWER_MARGIN_Q2);

	if (upper_limit_valid && lower_limit_valid) {
		return offset_q2;
	} else if (!upper_limit_valid && lower_limit_valid) {
		new_offset_q2 = UPPER_POWER_MARGIN_Q2 - bw_factor_q2;

		return new_offset_q2;
	} else if (upper_limit_valid && !lower_limit_valid) {
		new_offset_q2 = LOWER_POWER_MARGIN_Q2 - bw_factor_q2 - ant_factor_q2;

		return new_offset_q2;
	}

	new_offset_q2 = min(UPPER_POWER_MARGIN_Q2 - bw_factor_q2,
			    LOWER_POWER_MARGIN_Q2 - bw_factor_q2 - ant_factor_q2);

	return new_offset_q2;
}

static void cl_power_tables_update_cck(struct cl_hw *cl_hw,
				       struct cl_pwr_tables *pwr_tables)
{
	u8 mcs;
	u8 trunc_value = 0;
	s8 pwr_offset_q1;

	/* CCK - Enforce EIRP limitations */
	for (mcs = 0; mcs < WRS_MCS_MAX_CCK; mcs++) {
		pwr_offset_q1 = cl_power_offset_q1(cl_hw, WRS_MODE_CCK, CHNL_BW_20, mcs);

		pwr_tables->ant_pwr_cck[mcs] =
			cl_power_calc_q1(cl_hw, pwr_offset_q1, 0, 0,
					 WRS_MODE_CCK, false, &trunc_value);

		cl_hw->pwr_trunc.cck[mcs] = trunc_value;

		/* Auto response */
		pwr_tables->pwr_auto_resp_cck[mcs] =
			cl_power_calc_q1(cl_hw, pwr_offset_q1, 0, 0,
					 WRS_MODE_CCK, true, &trunc_value);
	}
}

static void cl_power_tables_update_ofdm(struct cl_hw *cl_hw,
					struct cl_pwr_tables *pwr_tables)
{
	u8 mcs;
	u8 trunc_value = 0;
	s8 pwr_offset_q1;

	/* OFDM - Enforce EIRP limitations */
	for (mcs = 0; mcs < WRS_MCS_MAX_OFDM; mcs++) {
		pwr_offset_q1 = cl_power_offset_q1(cl_hw, WRS_MODE_OFDM, CHNL_BW_20, mcs);

		pwr_tables->ant_pwr_ofdm[mcs] =
			cl_power_calc_q1(cl_hw, pwr_offset_q1, 0, 0,
					 WRS_MODE_OFDM, false, &trunc_value);

		cl_hw->pwr_trunc.ofdm[mcs] = trunc_value;

		/* Auto response */
		pwr_tables->pwr_auto_resp_ofdm[mcs] =
			cl_power_calc_q1(cl_hw, pwr_offset_q1, 0, 0,
					 WRS_MODE_OFDM, true, &trunc_value);
	}
}

static u8 cl_power_tables_update_ht_vht(struct cl_hw *cl_hw,
					struct cl_pwr_tables *pwr_tables)
{
	bool is_24g = cl_band_is_24g(cl_hw);
	bool is_5g = cl_band_is_5g(cl_hw);
	u8 bw;
	u8 nss;
	u8 mcs;
	u8 trunc_value = 0;
	u8 min_bw_idx_limit_vht = 0;
	u8 max_mcs_ht_vht = (is_5g || (is_24g && cl_hw->conf->ci_vht_cap_24g)) ?
		WRS_MCS_MAX_VHT : WRS_MCS_MAX_HT;
	s8 pwr_offset_q1;
	s16 min_bw_limit = 0;
	s32 eirp_power_limit_q8;

	for (bw = 0, min_bw_limit = 0xFFFF; bw < max_bw_idx(WRS_MODE_VHT, is_24g); bw++) {
		if (!cl_hw->chip->conf->ce_production_mode &&
		    !cl_chan_info_get(cl_hw, cl_hw->channel, bw))
			continue;

		/* Find lowest EIRP power limitation among all bw for auto resp calculations */
		eirp_power_limit_q8 = cl_chan_info_get_eirp_limit_q8(cl_hw, bw);
		if (eirp_power_limit_q8 < min_bw_limit) {
			min_bw_limit = eirp_power_limit_q8;
			min_bw_idx_limit_vht = bw;
		}

		/* HT/VHT - Enforce EIRP limitations */
		for (mcs = 0; mcs < max_mcs_ht_vht; mcs++) {
			pwr_offset_q1 = cl_power_offset_q1(cl_hw, WRS_MODE_VHT, bw, mcs);

			for (nss = 0; nss < PWR_TBL_BF_SIZE; nss++) {
				pwr_tables->ant_pwr_ht_vht[bw][mcs][nss] =
					cl_power_calc_q1(cl_hw, pwr_offset_q1,
							 bw, nss, WRS_MODE_VHT, false,
							 &trunc_value);
				cl_hw->pwr_trunc.ht_vht[bw][mcs][nss] = trunc_value;
			}
		}
	}

	/* Auto resp HT/VHT - Enforce EIRP limitations */
	for (mcs = 0; mcs < max_mcs_ht_vht; mcs++) {
		pwr_offset_q1 = cl_power_offset_q1(cl_hw, WRS_MODE_VHT, CHNL_BW_20, mcs);

		pwr_tables->pwr_auto_resp_ht_vht[mcs] =
			cl_power_calc_q1(cl_hw, pwr_offset_q1,
					 min_bw_idx_limit_vht, 0, WRS_MODE_VHT,
					 true, &trunc_value);
	}

	return min_bw_idx_limit_vht;
}

static u8 cl_power_tables_update_he(struct cl_hw *cl_hw,
				    struct cl_pwr_tables *pwr_tables)
{
	bool is_24g = cl_band_is_24g(cl_hw);
	u8 bw;
	u8 nss;
	u8 mcs;
	u8 trunc_value = 0;
	u8 min_bw_idx_limit_he = 0;
	s8 pwr_offset_q1;
	s16 min_bw_limit = 0;
	s32 eirp_power_limit_q8;

	for (bw = 0, min_bw_limit = 0xFFFF; bw < max_bw_idx(WRS_MODE_HE, is_24g); bw++) {
		if (!cl_hw->chip->conf->ce_production_mode &&
		    !cl_chan_info_get(cl_hw, cl_hw->channel, bw))
			continue;

		/* Find lowest EIRP power limitation among all bw for auto resp calculations */
		eirp_power_limit_q8 = cl_chan_info_get_eirp_limit_q8(cl_hw, bw);
		if (eirp_power_limit_q8 < min_bw_limit) {
			min_bw_limit = eirp_power_limit_q8;
			min_bw_idx_limit_he = bw;
		}

		/* HE - Enforce EIRP limitations */
		for (mcs = 0; mcs < WRS_MCS_MAX_HE; mcs++) {
			pwr_offset_q1 = cl_power_offset_q1(cl_hw, WRS_MODE_HE, bw, mcs);

			for (nss = 0; nss < PWR_TBL_BF_SIZE; nss++) {
				pwr_tables->ant_pwr_he[bw][mcs][nss] =
					cl_power_calc_q1(cl_hw, pwr_offset_q1,
							 bw, nss, WRS_MODE_HE, false,
							 &trunc_value);
				cl_hw->pwr_trunc.he[bw][mcs][nss] = trunc_value;
			}
		}
	}

	/* Auto resp HE - Enforce EIRP limitations */
	for (mcs = 0; mcs < WRS_MCS_MAX_HE; mcs++) {
		pwr_offset_q1 = cl_power_offset_q1(cl_hw, WRS_MODE_HE, CHNL_BW_20, mcs);

		pwr_tables->pwr_auto_resp_he[mcs] =
			cl_power_calc_q1(cl_hw, pwr_offset_q1, min_bw_idx_limit_he,
					 nss, WRS_MODE_HE, true, &trunc_value);
	}

	return min_bw_idx_limit_he;
}

static u8 cl_power_calc_max(struct cl_hw *cl_hw, u8 bw, enum cl_wrs_mode mode)
{
	u8 tx_ant = cl_power_tx_ant(cl_hw, mode);
	/* Total TX power - pass is_auto_resp = true in order to ignore bf gain */
	s32 total_power_q8 = cl_power_total_q8(cl_hw, 0, tx_ant, 0, mode, true);
	/* EIRP power limit */
	s32 eirp_power_limit_q8 = cl_chan_info_get_eirp_limit_q8(cl_hw, bw);

	return (min(total_power_q8, eirp_power_limit_q8) >> 8);
}

static s8 cl_power_vns_calc_q1(struct cl_hw *cl_hw, u8 bw,
			       enum cl_wrs_mode mode, bool is_auto_resp)
{
	u8 max_tx_pwr = cl_power_calc_max(cl_hw, bw, mode);
	u8 tx_ant = cl_power_tx_ant(cl_hw, mode);
	u32 vns_pwr_limit_q8 = min(cl_hw->conf->ci_vns_pwr_limit, max_tx_pwr) << 8;
	s32 antenna_gain_q8 = cl_power_antenna_gain_q8(cl_hw);
	s32 array_gain_q8 = (is_auto_resp ? 0 : cl_power_array_gain_q8(cl_hw, tx_ant));
	s32 min_ant_pwr_q8 = cl_power_min_ant_q8(cl_hw);
	s32 min_pwr_q8 = is_auto_resp ? (POWER_MIN_DB_Q8 + min_ant_pwr_q8) : POWER_MIN_DB_Q8;
	s32 res_q8 = vns_pwr_limit_q8 - antenna_gain_q8 - array_gain_q8;

	if (res_q8 < min_pwr_q8)
		res_q8 = min_pwr_q8;

	/* Result should be in 0.5dBm resolution */
	return (s8)(res_q8 >> 7);
}

static void cl_power_tables_update_vns(struct cl_hw *cl_hw,
				       struct cl_pwr_tables *pwr_tables,
				       u8 min_bw_idx_limit_vht,
				       u8 min_bw_idx_limit_he)
{
	/* VNS */
	pwr_tables->ant_pwr_vns_he =
		cl_power_vns_calc_q1(cl_hw, min_bw_idx_limit_he, WRS_MODE_HE, false);
	pwr_tables->ant_pwr_vns_ht_vht =
		cl_power_vns_calc_q1(cl_hw, min_bw_idx_limit_vht, WRS_MODE_VHT, false);
	pwr_tables->ant_pwr_vns_ofdm =
		cl_power_vns_calc_q1(cl_hw, 0, WRS_MODE_OFDM, false);
	pwr_tables->ant_pwr_vns_cck =
		cl_power_vns_calc_q1(cl_hw, 0, WRS_MODE_CCK, false);

	/* Auto response VNS */
	pwr_tables->pwr_auto_resp_vns_he =
		cl_power_vns_calc_q1(cl_hw, min_bw_idx_limit_he, WRS_MODE_HE, true);
	pwr_tables->pwr_auto_resp_vns_ht_vht =
		cl_power_vns_calc_q1(cl_hw, min_bw_idx_limit_vht, WRS_MODE_VHT, true);
	pwr_tables->pwr_auto_resp_vns_ofdm =
		cl_power_vns_calc_q1(cl_hw, 0, WRS_MODE_OFDM, true);
	pwr_tables->pwr_auto_resp_vns_cck =
		cl_power_vns_calc_q1(cl_hw, 0, WRS_MODE_CCK, true);
}

static void cl_power_tables_update_by_offset(struct cl_hw *cl_hw,
					     struct cl_pwr_tables *pwr_tables,
					     s8 offset)
{
	u8 mcs = 0;
	u8 bw = 0;
	u8 nss = 0;

	/* CCK - Enforce EIRP limitations */
	for (mcs = 0; mcs < WRS_MCS_MAX_CCK; mcs++) {
		pwr_tables->ant_pwr_cck[mcs] += offset;

		/* Auto response */
		pwr_tables->pwr_auto_resp_cck[mcs] += offset;
	}

	/* OFDM - Enforce EIRP limitations */
	for (mcs = 0; mcs < WRS_MCS_MAX_OFDM; mcs++) {
		pwr_tables->ant_pwr_ofdm[mcs] += offset;

		/* Auto response */
		pwr_tables->pwr_auto_resp_ofdm[mcs] += offset;
	}

	for (bw = 0; bw < CHNL_BW_MAX; bw++) {
		/* HT/VHT - Enforce EIRP limitations */
		for (mcs = 0; mcs < WRS_MCS_MAX_VHT; mcs++) {
			for (nss = 0; nss < PWR_TBL_BF_SIZE; nss++)
				pwr_tables->ant_pwr_ht_vht[bw][mcs][nss] += offset;

			/*
			 * Auto response:
			 * always with disabled BF so the offset of the last nss is used
			 */
			pwr_tables->pwr_auto_resp_ht_vht[mcs] += offset;
		}

		/* HE - Enforce EIRP limitations */
		for (mcs = 0; mcs < WRS_MCS_MAX_HE; mcs++) {
			for (nss = 0; nss < PWR_TBL_BF_SIZE; nss++)
				pwr_tables->ant_pwr_he[bw][mcs][nss] += offset;

			/*
			 * Auto response:
			 * always with disabled BF so the offset of the last nss is used
			 */
			pwr_tables->pwr_auto_resp_he[mcs] += offset;
		}
	}
}

static s8 cl_power_get_offset(u16 percentage)
{
	if (percentage >= 94)
		return 0;
	else if (percentage >= 84)
		return -1; /* -0.5dBm */
	else if (percentage >= 75)
		return -2; /* -1dBm */
	else if (percentage >= 67)
		return -3; /* -1.5dBm */
	else if (percentage >= 59)
		return -4; /* -2dBm */
	else if (percentage >= 54)
		return -5; /* -2.5dBm */
	else if (percentage >= 48)
		return -6; /* -3dBm */
	else if (percentage >= 43)
		return -7; /* -3.5dBm */
	else if (percentage >= 38)
		return -8; /* -4dBm */
	else if (percentage >= 34)
		return -9; /* -4.5dBm */
	else if (percentage >= 30)
		return -10; /* -5dBm */
	else if (percentage >= 27)
		return -11; /* -5.5dBm */
	else if (percentage >= 24)
		return -12; /* -6dBm */
	else if (percentage >= 22)
		return -13; /* -6.5dBm */
	else if (percentage >= 19)
		return -14; /* -7dBm */
	else if (percentage >= 17)
		return -15; /* -7.5dBm */
	else if (percentage >= 15)
		return -16; /* -8dBm */
	else if (percentage >= 14)
		return -17; /* -8.5dBm */
	else if (percentage >= 12)
		return -18; /* -9dBm */
	else if (percentage >= 11)
		return -19; /* -9.5dBm */
	else if (percentage >= 10)
		return -20; /* -10dBm */
	else if (percentage >= 9)
		return -21; /* -10.5dBm */
	else if (percentage >= 8)
		return -22; /* -11dBm */
	else if (percentage >= 7)
		return -23; /* -11.5dBm */
	else if (percentage >= 6)
		return -24; /* -12dBm */
	else if (percentage >= 5)
		return -26; /* -13dBm */
	else if (percentage >= 4)
		return -28; /* -14dBm */
	else if (percentage >= 3)
		return -30; /* -15dBm */
	else if (percentage >= 2)
		return -34; /* -17dBm */
	else if (percentage >= 1)
		return -40; /* -20dBm */

	/* Should not get here */
	return 0;
}

static void cl_power_control_apply_percentage(struct cl_hw *cl_hw)
{
	struct cl_power_db *power_db = &cl_hw->power_db;
	u8 percentage = cl_hw->conf->ce_tx_power_control;

	power_db->curr_percentage = percentage;

	if (percentage != 100) {
		power_db->curr_offset = cl_power_get_offset(percentage);
		cl_power_tables_update_by_offset(cl_hw,
						 &cl_hw->phy_data_info.data->pwr_tables,
						 power_db->curr_offset);
	}
}

void cl_power_tables_update(struct cl_hw *cl_hw, struct cl_pwr_tables *pwr_tables)
{
	bool is_24g = cl_band_is_24g(cl_hw);
	bool is_6g = cl_band_is_6g(cl_hw);
	u8 min_bw_idx_limit_he = 0;
	u8 min_bw_idx_limit_vht = 0;

	/*
	 * If tx_power is set then we are in calibration process and
	 * need to set all values in power tables to this value x2.
	 */
	if (cl_hw->ate_db.active &&
	    cl_hw->ate_db.tx_power >= POWER_MIN_DB &&
	    cl_hw->ate_db.tx_power <= POWER_MAX_DB) {
		s8 tx_power_q1 = cl_hw->ate_db.tx_power << 1;

		memset(pwr_tables, tx_power_q1, sizeof(struct cl_pwr_tables));
		return;
	}

	if (cl_hw->conf->ci_fixed_tx_power) {
		s8 tx_power_q1 = cl_hw->conf->ci_fixed_tx_power << 1;

		memset(pwr_tables, tx_power_q1, sizeof(struct cl_pwr_tables));
		return;
	}

	memset(pwr_tables, 0, sizeof(struct cl_pwr_tables));

	if (is_24g)
		cl_power_tables_update_cck(cl_hw, pwr_tables);

	if (!is_6g) {
		cl_power_tables_update_ofdm(cl_hw, pwr_tables);
		min_bw_idx_limit_vht = cl_power_tables_update_ht_vht(cl_hw, pwr_tables);
	}

	min_bw_idx_limit_he = cl_power_tables_update_he(cl_hw, pwr_tables);

	cl_power_tables_update_vns(cl_hw, pwr_tables, min_bw_idx_limit_vht, min_bw_idx_limit_he);

	cl_power_control_apply_percentage(cl_hw);
}

static s32 cl_power_get_max_cck(struct cl_hw *cl_hw)
{
	struct cl_pwr_tables *pwr_tables = &cl_hw->phy_data_info.data->pwr_tables;
	u8 mcs = 0;
	u8 tx_ant = cl_power_tx_ant(cl_hw, WRS_MODE_CCK);
	s32 ant_gain_q1 = cl_power_antenna_gain_q1(cl_hw);
	s32 arr_gain_q1 = cl_power_array_gain_q1(cl_hw, tx_ant);
	s32 total_pwr_q1 = 0;
	s32 max_pwr_q1 = 0;

	for (mcs = 0; mcs < WRS_MCS_MAX_CCK; mcs++) {
		total_pwr_q1 = pwr_tables->ant_pwr_cck[mcs] + ant_gain_q1 + arr_gain_q1;

		if (total_pwr_q1 > max_pwr_q1)
			max_pwr_q1 = total_pwr_q1;
	}

	return max_pwr_q1;
}

static s32 cl_power_get_max_ofdm(struct cl_hw *cl_hw)
{
	struct cl_pwr_tables *pwr_tables = &cl_hw->phy_data_info.data->pwr_tables;
	u8 mcs = 0;
	u8 tx_ant = cl_power_tx_ant(cl_hw, WRS_MODE_OFDM);
	s32 ant_gain_q1 = cl_power_antenna_gain_q1(cl_hw);
	s32 arr_gain_q1 = cl_power_array_gain_q1(cl_hw, tx_ant);
	s32 total_pwr_q1 = 0;
	s32 max_pwr_q1 = 0;

	for (mcs = 0; mcs < WRS_MCS_MAX_OFDM; mcs++) {
		total_pwr_q1 = pwr_tables->ant_pwr_ofdm[mcs] + ant_gain_q1 + arr_gain_q1;

		if (total_pwr_q1 > max_pwr_q1)
			max_pwr_q1 = total_pwr_q1;
	}

	return max_pwr_q1;
}

static s32 cl_power_get_max_ht_vht(struct cl_hw *cl_hw)
{
	struct cl_pwr_tables *pwr_tables = &cl_hw->phy_data_info.data->pwr_tables;
	u8 tx_ant = cl_power_tx_ant(cl_hw, WRS_MODE_VHT);
	u8 mcs = 0;
	u8 bw = 0;
	u8 bf = 0;
	s32 ant_gain_q1 = cl_power_antenna_gain_q1(cl_hw);
	s32 arr_gain_q1 = cl_power_array_gain_q1(cl_hw, tx_ant);
	s32 total_pwr_q1 = 0;
	s32 max_pwr_q1 = 0;

	for (bw = 0; bw < CHNL_BW_MAX; bw++) {
		for (mcs = 0; mcs < WRS_MCS_MAX_VHT; mcs++) {
			for (bf = 0; bf < PWR_TBL_BF_SIZE; bf++) {
				total_pwr_q1 = pwr_tables->ant_pwr_ht_vht[bw][mcs][bf] +
					ant_gain_q1 + arr_gain_q1;

				if (total_pwr_q1 > max_pwr_q1)
					max_pwr_q1 = total_pwr_q1;
			}
		}
	}

	return max_pwr_q1;
}

static s32 cl_power_get_max_he(struct cl_hw *cl_hw)
{
	struct cl_pwr_tables *pwr_tables = &cl_hw->phy_data_info.data->pwr_tables;
	u8 tx_ant = cl_power_tx_ant(cl_hw, WRS_MODE_HE);
	u8 mcs = 0;
	u8 bw = 0;
	u8 bf = 0;
	s32 ant_gain_q1 = cl_power_antenna_gain_q1(cl_hw);
	s32 arr_gain_q1 = cl_power_array_gain_q1(cl_hw, tx_ant);
	s32 total_pwr_q1 = 0;
	s32 max_pwr_q1 = 0;

	for (bw = 0; bw < CHNL_BW_MAX; bw++) {
		for (mcs = 0; mcs < WRS_MCS_MAX_HE; mcs++) {
			for (bf = 0; bf < PWR_TBL_BF_SIZE; bf++) {
				total_pwr_q1 = pwr_tables->ant_pwr_he[bw][mcs][bf] +
					ant_gain_q1 + arr_gain_q1;

				if (total_pwr_q1 > max_pwr_q1)
					max_pwr_q1 = total_pwr_q1;
			}
		}
	}

	return max_pwr_q1;
}

s32 cl_power_get_max(struct cl_hw *cl_hw)
{
	bool is_24g = cl_band_is_24g(cl_hw);
	bool is_6g = cl_band_is_6g(cl_hw);
	s32 max_pwr_cck_q1 = is_24g ? cl_power_get_max_cck(cl_hw) : S32_MIN;
	s32 max_pwr_ofdm_q1 = !is_6g ? cl_power_get_max_ofdm(cl_hw) : S32_MIN;
	s32 max_pwr_ht_vht_q1 = !is_6g ? cl_power_get_max_ht_vht(cl_hw) : S32_MIN;
	s32 max_pwr_he_q1 = cl_power_get_max_he(cl_hw);
	s32 max_pwr_q1 = 0;

	max_pwr_q1 = max(max_pwr_q1, max_pwr_cck_q1);
	max_pwr_q1 = max(max_pwr_q1, max_pwr_ofdm_q1);
	max_pwr_q1 = max(max_pwr_q1, max_pwr_ht_vht_q1);
	max_pwr_q1 = max(max_pwr_q1, max_pwr_he_q1);

	return (max_pwr_q1 >> 1);
}

