// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_power_cli.h"
#include "cl_power.h"
#include "cl_band.h"
#include "chip.h"
#include "cl_utils.h"

static void cl_power_float_to_buf(char **buf, int *len, ssize_t *buf_size,
				  s32 x, s32 y, bool zero_pad)
{
	bool sign = (x >= 0 && y > 0) || (x < 0 && y < 0);
	s32 absx = abs(x);
	s32 absy = abs(y);
	s32 abs_integer = 0;
	s32 fraction = 0;
	s32 signed_integer = 0;

	if (x != 0 && y != 0) {
		abs_integer = (absx / absy);
		if (y == 2)
			fraction = (10 * (absx - absy * abs_integer) / absy);
		else
			fraction = (100 * (absx - absy * abs_integer) / absy);
		signed_integer = sign ? abs_integer : -abs_integer;
	}

	if (y == 2) {
		if (signed_integer == 0 && !sign)
			cl_snprintf(buf, len, buf_size, "-0.%d", fraction);
		else if (zero_pad)
			cl_snprintf(buf, len, buf_size, "%2d.%d", signed_integer, fraction);
		else
			cl_snprintf(buf, len, buf_size, "%d.%d", signed_integer, fraction);
	} else {
		if (signed_integer == 0 && !sign)
			cl_snprintf(buf, len, buf_size, "-0.%02d", fraction);
		else if (zero_pad)
			cl_snprintf(buf, len, buf_size, "%2d.%02d", signed_integer, fraction);
		else
			cl_snprintf(buf, len, buf_size, "%d.%02d", signed_integer, fraction);
	}
}

static void cl_power_q1_to_buf(char **buf, int *len, ssize_t *buf_size, const s8 *prefix, s32 x,
			       const s8 *suffix, bool zero_pad)
{
	cl_snprintf(buf, len, buf_size, "%s", prefix);
	cl_power_float_to_buf(buf, len, buf_size, x, 2, zero_pad);
	cl_snprintf(buf, len, buf_size, "%s", suffix);
}

static void cl_power_q8_to_buf(char **buf, int *len, ssize_t *buf_size, const s8 *prefix, s32 x,
			       const s8 *suffix, bool zero_pad)
{
	cl_snprintf(buf, len, buf_size, "%s", prefix);
	cl_power_float_to_buf(buf, len, buf_size, x, 256, zero_pad);
	cl_snprintf(buf, len, buf_size, "%s", suffix);
}

static void multi_print(char **buf, int *len, ssize_t *buf_size, u8 num_prints, const s8 *str)
{
	u8 i;

	for (i = 0; i < num_prints; i++)
		cl_snprintf(buf, len, buf_size, "%s", str);

	cl_snprintf(buf, len, buf_size, "\n");
}

static void cl_power_offset_to_buf(struct cl_hw *cl_hw, char **buf,
				   int *len, ssize_t *buf_size,
				   u8 mode, u8 max_bw, u8 max_mcs)
{
	u8 bw, mcs;
	s8 offset_q1;

	cl_snprintf(buf, len, buf_size, "\nPower Offset per BW & MCS\n");

	cl_snprintf(buf, len, buf_size, "-----");
	multi_print(buf, len, buf_size, max_mcs, "-----");

	cl_snprintf(buf, len, buf_size, "|   ");
	for (mcs = 0; mcs < max_mcs; mcs++)
		cl_snprintf(buf, len, buf_size, "|%4u", mcs);

	cl_snprintf(buf, len, buf_size, "|\n");

	cl_snprintf(buf, len, buf_size, "|---");
	for (mcs = 0; mcs < max_mcs - 1; mcs++)
		cl_snprintf(buf, len, buf_size, "+----");

	cl_snprintf(buf, len, buf_size, "+----|\n");

	for (bw = 0; bw < max_bw; bw++) {
		cl_snprintf(buf, len, buf_size, "|%3u", BW_TO_MHZ(bw));

		for (mcs = 0; mcs < max_mcs; mcs++) {
			offset_q1 = cl_power_offset_q1(cl_hw, mode, bw, mcs);
			cl_power_q1_to_buf(buf, len, buf_size, "|", offset_q1, "", true);
		}

		cl_snprintf(buf, len, buf_size, "|\n");
	}

	cl_snprintf(buf, len, buf_size, "-----");
	multi_print(buf, len, buf_size, max_mcs, "-----");
}

static void cl_power_bf_gain_to_buf(char **buf, int *len, ssize_t *buf_size,
				    u8 max_nss, s32 *bf_gain_q1)
{
	u8 nss;

	cl_snprintf(buf, len, buf_size, "BF gain per NSS = ");

	for (nss = 0; nss < max_nss; nss++) {
		if (nss == max_nss - 1)
			cl_power_q1_to_buf(buf, len, buf_size, "", bf_gain_q1[nss], "\n", false);
		else
			cl_power_q1_to_buf(buf, len, buf_size, "", bf_gain_q1[nss], ",", false);
	}
}

static void cl_power_table_ht_vht_he_to_buf(struct cl_hw *cl_hw, char **buf, int *len,
					    ssize_t *buf_size, u8 max_bw, u8 max_nss,
					    u8 max_mcs, u8 max_nss_arr,
					    u8 max_mcs_arr, s8 *ant_pwr_q1,
					    s32 *bf_gain_q1, s32 arr_gain_q1,
					    s32 ant_gain_q1)
{
	u8 bw, nss, mcs, one_d_idx;
	s32 conducted_q1, final_q1;

	cl_snprintf(buf, len, buf_size, "\nPower Table\n");

	cl_snprintf(buf, len, buf_size, "---------");
	multi_print(buf, len, buf_size, max_bw, "----------");

	cl_snprintf(buf, len, buf_size, "|MCS|BF |");
	for (bw = 0; bw < max_bw; bw++)
		cl_snprintf(buf, len, buf_size, " %3uMHz  |", BW_TO_MHZ(bw));

	cl_snprintf(buf, len, buf_size, "\n");

	cl_snprintf(buf, len, buf_size, "|   |NSS|");
	multi_print(buf, len, buf_size, max_bw, "Cond|Finl|");

	for (mcs = 0; mcs < max_mcs; mcs++) {
		cl_snprintf(buf, len, buf_size, "|---+---|");
		multi_print(buf, len, buf_size, max_bw, "----+----|");

		for (nss = 0; nss < max_nss; nss++) {
			cl_snprintf(buf, len, buf_size, "|%3u|%3u|", mcs, nss);

			for (bw = 0; bw < max_bw; bw++) {
				one_d_idx = (bw * max_mcs_arr + mcs) * max_nss_arr + nss;
				conducted_q1 = ant_pwr_q1[one_d_idx];
				final_q1 = conducted_q1 + ant_gain_q1 +
					arr_gain_q1 + bf_gain_q1[nss];

				if (cl_hw->channel_info.standard == CL_STANDARD_FCC)
					final_q1 -= min(bf_gain_q1[nss] + ant_gain_q1, 6 << 1);

				cl_power_q1_to_buf(buf, len, buf_size, "", conducted_q1, "|", true);
				cl_power_q1_to_buf(buf, len, buf_size, "", final_q1, "|", true);
			}

			cl_snprintf(buf, len, buf_size, "\n");
		}
	}

	cl_snprintf(buf, len, buf_size, "---------");
	multi_print(buf, len, buf_size, max_bw, "----------");

	cl_snprintf(buf, len, buf_size, "(*) BF disabled = BF NSS #%u", max_nss - 1);
}

static void cl_power_table_cck_ofdm_to_buf(struct cl_hw *cl_hw, char **buf,
					   int *len, ssize_t *buf_size,
					   u8 max_mcs, s8 *ant_pwr_q1,
					   s32 arr_gain_q1, s32 ant_gain_q1)
{
	u8 mcs;
	s32 conducted_q1, final_q1;

	cl_snprintf(buf, len, buf_size,
		    "\nPower Table\n"
		    "|-------------|\n"
		    "|MCS|Cond|Finl|\n"
		    "|---+----+----|\n");

	for (mcs = 0; mcs < max_mcs; mcs++) {
		conducted_q1 = ant_pwr_q1[mcs];
		final_q1 = conducted_q1 + ant_gain_q1 + arr_gain_q1;

		if (cl_hw->channel_info.standard == CL_STANDARD_FCC)
			final_q1 -= min(ant_gain_q1, 6 << 1);

		cl_snprintf(buf, len, buf_size, "|%3u|", mcs);
		cl_power_q1_to_buf(buf, len, buf_size, "", conducted_q1, "|", true);
		cl_power_q1_to_buf(buf, len, buf_size, "",  final_q1, "|\n", true);
	}

	cl_snprintf(buf, len, buf_size, "|-------------|\n");
}

static void cl_power_trunc_ht_vht_he_to_buf(struct cl_hw *cl_hw, char **buf,
					    int *len, ssize_t *buf_size,
					    enum cl_wrs_mode mode, u8 max_bw,
					    u8 max_nss, u8 max_mcs,
					    u8 max_nss_arr, u8 max_mcs_arr,
					    u8 *trunc_pwr_q1)
{
	u8 bw, nss, mcs, one_d_idx;
	u8 tx_ant = cl_power_tx_ant(cl_hw, mode);
	s8 pwr_offset_q1;
	s32 truncate_q1, total_q1;

	cl_snprintf(buf, len, buf_size, "\nTruncate Table\n");

	cl_snprintf(buf, len, buf_size, "---------");
	multi_print(buf, len, buf_size, max_bw, "----------");

	cl_snprintf(buf, len, buf_size, "|MCS|BF |");
	for (bw = 0; bw < max_bw; bw++)
		cl_snprintf(buf, len, buf_size, " %3uMHz  |", BW_TO_MHZ(bw));

	cl_snprintf(buf, len, buf_size, "\n");

	cl_snprintf(buf, len, buf_size, "|   |NSS|");
	multi_print(buf, len, buf_size, max_bw, "Totl|Trnc|");

	for (mcs = 0; mcs < max_mcs; mcs++) {
		cl_snprintf(buf, len, buf_size, "|---+---|");
		multi_print(buf, len, buf_size, max_bw, "----+----|");

		for (nss = 0; nss < max_nss; nss++) {
			cl_snprintf(buf, len, buf_size, "|%3u|%3u|", mcs, nss);

			for (bw = 0; bw < max_bw; bw++) {
				one_d_idx = (bw * max_mcs_arr + mcs) * max_nss_arr + nss;
				truncate_q1 = (s32)trunc_pwr_q1[one_d_idx];
				pwr_offset_q1 = cl_power_offset_q1(cl_hw, mode, bw, mcs);
				total_q1 = cl_power_total_q1(cl_hw, pwr_offset_q1,
							     tx_ant, nss, mode, false);

				cl_power_q1_to_buf(buf, len, buf_size, "", total_q1, "|", true);
				cl_power_q1_to_buf(buf, len, buf_size, "", truncate_q1, "|", true);
			}

			cl_snprintf(buf, len, buf_size, "\n");
		}
	}

	cl_snprintf(buf, len, buf_size, "---------");
	multi_print(buf, len, buf_size, max_bw, "----------");
}

static void cl_power_trunc_cck_ofdm_to_buf(struct cl_hw *cl_hw, char **buf,
					   int *len, ssize_t *buf_size,
					   enum cl_wrs_mode mode, u8 max_mcs, u8 *trunc_pwr_q1)
{
	u8 mcs;
	u8 tx_ant = cl_power_tx_ant(cl_hw, mode);
	s8 pwr_offset_q1;
	s32 truncate_q1, total_q1;

	cl_snprintf(buf, len, buf_size,
		    "\nTruncate Table\n"
		    "|-------------|\n"
		    "|MCS|Totl|Trnc|\n"
		    "|---+----+----|\n");

	for (mcs = 0; mcs < max_mcs; mcs++) {
		truncate_q1 = (s32)trunc_pwr_q1[mcs];
		pwr_offset_q1 = cl_power_offset_q1(cl_hw, mode, CHNL_BW_20, mcs);
		total_q1 = cl_power_total_q1(cl_hw, pwr_offset_q1, tx_ant, 0, mode, false);

		cl_snprintf(buf, len, buf_size, "|%3u|", mcs);
		cl_power_q1_to_buf(buf, len, buf_size, "", total_q1, "|", true);
		cl_power_q1_to_buf(buf, len, buf_size, "", truncate_q1, "|\n", true);
	}

	cl_snprintf(buf, len, buf_size, "|-------------|\n");
}

static void cl_power_config_to_buf(char **buf, int *len,
				   ssize_t *buf_size,
				   char *mode,
				   u8 tx_ant_num,
				   s32 arr_gain_q1,
				   s32 calib_power_q1,
				   s8 ant_pwr_vns,
				   s8 pwr_auto_resp_vns,
				   s32 vns_actual_q1)
{
	cl_snprintf(buf, len, buf_size,
		    "%s power debug info\n", mode);
	cl_snprintf(buf, len, buf_size,
		    "-----------------------\n");
	cl_snprintf(buf, len, buf_size,
		    "Tx antenna = %u\n", tx_ant_num);
	cl_power_q1_to_buf(buf, len, buf_size, "Array gain = ",
			   arr_gain_q1, "\n", false);
	cl_power_q1_to_buf(buf, len, buf_size, "Calib power = ",
			   calib_power_q1, "\n", false);
	cl_power_q1_to_buf(buf, len, buf_size, "VNS power = ",
			   ant_pwr_vns, "\n", false);
	cl_power_q1_to_buf(buf, len, buf_size, "VNS auto resp power = ",
			   pwr_auto_resp_vns, "\n", false);
	cl_power_q1_to_buf(buf, len, buf_size, "VNS actual = ",
			   vns_actual_q1, "\n", false);
}

static void _cl_power_table_print_he(struct cl_hw *cl_hw, char **buf, int *len, ssize_t *buf_size)
{
	struct cl_pwr_tables *pwr_tables = &cl_hw->phy_data_info.data->pwr_tables;
	u8 tx_ant = cl_power_tx_ant(cl_hw, WRS_MODE_HE);
	u8 max_bw = max_bw_idx(WRS_MODE_HE, cl_band_is_24g(cl_hw));
	u8 max_nss = min_t(u8, tx_ant, PWR_TBL_BF_SIZE);
	u8 nss;
	s32 ant_gain_q1 = cl_power_antenna_gain_q1(cl_hw);
	s32 arr_gain_q1 = cl_power_array_gain_q1(cl_hw, tx_ant);
	s32 calib_power_q1 = cl_power_average_calib_q1(cl_hw, tx_ant);
	s32 bf_gain_tbl_q1[PWR_TBL_BF_SIZE] = {0};
	s32 vns_actual_q1 = pwr_tables->ant_pwr_vns_he + ant_gain_q1 + arr_gain_q1;

	for (nss = 0; nss < max_nss; nss++)
		bf_gain_tbl_q1[nss] = cl_power_bf_gain_q1(cl_hw, nss);

	cl_power_config_to_buf(buf, len, buf_size, "HE", tx_ant, arr_gain_q1,
			       calib_power_q1, pwr_tables->ant_pwr_vns_he,
			       pwr_tables->pwr_auto_resp_vns_he, vns_actual_q1);

	cl_power_bf_gain_to_buf(buf, len, buf_size, max_nss, bf_gain_tbl_q1);

	cl_power_offset_to_buf(cl_hw, buf, len, buf_size, WRS_MODE_HE,
			       CHNL_BW_MAX_HE, WRS_MCS_MAX_HE);

	cl_power_table_ht_vht_he_to_buf(cl_hw, buf, len, buf_size,
					max_bw, max_nss, WRS_MCS_MAX_HE,
					PWR_TBL_BF_SIZE, WRS_MCS_MAX_HE,
					&pwr_tables->ant_pwr_he[0][0][0],
					bf_gain_tbl_q1, arr_gain_q1, ant_gain_q1);
}

static void _cl_power_table_print_ht_vht(struct cl_hw *cl_hw, char **buf,
					 int *len, ssize_t *buf_size)
{
	struct cl_pwr_tables *pwr_tables = &cl_hw->phy_data_info.data->pwr_tables;
	bool is_24g = cl_band_is_24g(cl_hw);
	bool is_5g = cl_band_is_5g(cl_hw);
	u8 tx_ant = cl_power_tx_ant(cl_hw, WRS_MODE_VHT);
	u8 max_bw = max_bw_idx(WRS_MODE_VHT, is_24g);
	u8 max_nss = min_t(u8, tx_ant, PWR_TBL_BF_SIZE);
	u8 max_mcs = (is_5g || (is_24g && cl_hw->conf->ci_vht_cap_24g)) ?
		WRS_MCS_MAX_VHT : WRS_MCS_MAX_HT;
	u8 nss;
	s32 ant_gain_q1 = cl_power_antenna_gain_q1(cl_hw);
	s32 arr_gain_q1 = cl_power_array_gain_q1(cl_hw, tx_ant);
	s32 calib_power_q1 = cl_power_average_calib_q1(cl_hw, tx_ant);
	s32 bf_gain_tbl_q1[PWR_TBL_BF_SIZE] = {0};
	s32 vns_actual_q1 = pwr_tables->ant_pwr_vns_ht_vht + ant_gain_q1 + arr_gain_q1;

	for (nss = 0; nss < max_nss; nss++)
		bf_gain_tbl_q1[nss] = cl_power_bf_gain_q1(cl_hw, nss);

	cl_power_config_to_buf(buf, len, buf_size, "HT/VHT", tx_ant, arr_gain_q1,
			       calib_power_q1, pwr_tables->ant_pwr_vns_ht_vht,
			       pwr_tables->pwr_auto_resp_vns_ht_vht, vns_actual_q1);

	cl_power_bf_gain_to_buf(buf, len, buf_size, max_nss, bf_gain_tbl_q1);

	cl_power_offset_to_buf(cl_hw, buf, len, buf_size,
			       WRS_MODE_VHT, CHNL_BW_MAX_VHT, WRS_MCS_MAX_VHT);

	cl_power_table_ht_vht_he_to_buf(cl_hw, buf, len, buf_size,
					max_bw, max_nss, max_mcs,
					PWR_TBL_BF_SIZE, WRS_MCS_MAX_VHT,
					&pwr_tables->ant_pwr_ht_vht[0][0][0],
					bf_gain_tbl_q1, arr_gain_q1, ant_gain_q1);
}

static void _cl_power_table_print_ofdm(struct cl_hw *cl_hw, char **buf,
				       int *len, ssize_t *buf_size)
{
	struct cl_pwr_tables *pwr_tables = &cl_hw->phy_data_info.data->pwr_tables;
	u8 tx_ant = cl_power_tx_ant(cl_hw, WRS_MODE_OFDM);
	s32 ant_gain_q1 = cl_power_antenna_gain_q1(cl_hw);
	s32 arr_gain_q1 = cl_power_array_gain_q1(cl_hw, tx_ant);
	s32 calib_power_q1 = cl_power_average_calib_q1(cl_hw, tx_ant);
	s32 vns_actual_q1 = pwr_tables->ant_pwr_vns_ofdm + ant_gain_q1 + arr_gain_q1;

	cl_power_config_to_buf(buf, len, buf_size, "OFDM", tx_ant, arr_gain_q1,
			       calib_power_q1, pwr_tables->ant_pwr_vns_ofdm,
			       pwr_tables->pwr_auto_resp_vns_ofdm, vns_actual_q1);

	cl_power_offset_to_buf(cl_hw, buf, len, buf_size, WRS_MODE_OFDM,
			       CHNL_BW_MAX_OFDM, WRS_MCS_MAX_OFDM);

	cl_power_table_cck_ofdm_to_buf(cl_hw, buf, len, buf_size, WRS_MCS_MAX_OFDM,
				       pwr_tables->ant_pwr_ofdm,
				       arr_gain_q1, ant_gain_q1);
}

static void _cl_power_table_print_cck(struct cl_hw *cl_hw, char **buf,
				      int *len, ssize_t *buf_size)
{
	struct cl_pwr_tables *pwr_tables = &cl_hw->phy_data_info.data->pwr_tables;
	u8 tx_ant = cl_power_tx_ant(cl_hw, WRS_MODE_CCK);
	s32 ant_gain_q1 = cl_power_antenna_gain_q1(cl_hw);
	s32 arr_gain_q1 = cl_power_array_gain_q1(cl_hw, tx_ant);
	s32 calib_power_q1 = cl_power_average_calib_q1(cl_hw, tx_ant);
	s32 vns_actual_q1 = pwr_tables->ant_pwr_vns_cck + ant_gain_q1 + arr_gain_q1;

	cl_power_config_to_buf(buf, len, buf_size, "CCK", tx_ant, arr_gain_q1,
			       calib_power_q1, pwr_tables->ant_pwr_vns_cck,
			       pwr_tables->pwr_auto_resp_vns_cck,
			       vns_actual_q1);

	cl_power_offset_to_buf(cl_hw, buf, len, buf_size, WRS_MODE_CCK,
			       CHNL_BW_MAX_CCK, WRS_MCS_MAX_CCK);

	cl_power_table_cck_ofdm_to_buf(cl_hw, buf, len, buf_size, WRS_MCS_MAX_CCK,
				       pwr_tables->ant_pwr_cck,
				       arr_gain_q1, ant_gain_q1);
}

static void _cl_power_trunc_print_he(struct cl_hw *cl_hw, char **buf,
				     int *len, ssize_t *buf_size)
{
	u8 tx_ant = cl_power_tx_ant(cl_hw, WRS_MODE_HE);
	u8 max_bw = max_bw_idx(WRS_MODE_HE, cl_band_is_24g(cl_hw));
	u8 max_nss = min_t(u8, tx_ant, PWR_TBL_BF_SIZE);

	cl_power_trunc_ht_vht_he_to_buf(cl_hw, buf, len, buf_size, WRS_MODE_HE,
					max_bw, max_nss, WRS_MCS_MAX_HE,
					PWR_TBL_BF_SIZE, WRS_MCS_MAX_HE,
					&cl_hw->pwr_trunc.he[0][0][0]);
}

static void _cl_power_trunc_print_ht_vht(struct cl_hw *cl_hw, char **buf,
					 int *len, ssize_t *buf_size)
{
	bool is_24g = cl_band_is_24g(cl_hw);
	bool is_5g = cl_band_is_5g(cl_hw);
	enum cl_wrs_mode mode;
	u8 tx_ant, max_bw, max_nss, max_mcs;

	if (is_5g || (is_24g && cl_hw->conf->ci_vht_cap_24g)) {
		mode = WRS_MODE_VHT;
		max_bw = CHNL_BW_MAX_VHT;
		max_mcs = WRS_MCS_MAX_VHT;
	} else {
		mode = WRS_MODE_HT;
		max_bw = CHNL_BW_MAX_HT;
		max_mcs = WRS_MCS_MAX_HT;
	}

	tx_ant = cl_power_tx_ant(cl_hw, mode);
	max_nss = min_t(u8, tx_ant, PWR_TBL_BF_SIZE);

	cl_power_trunc_ht_vht_he_to_buf(cl_hw, buf, len, buf_size, mode,
					max_bw, max_nss, max_mcs,
					PWR_TBL_BF_SIZE, WRS_MCS_MAX_VHT,
					&cl_hw->pwr_trunc.ht_vht[0][0][0]);
}

static void _cl_power_trunc_print_ofdm(struct cl_hw *cl_hw, char **buf,
				       int *len, ssize_t *buf_size)
{
	cl_power_trunc_cck_ofdm_to_buf(cl_hw, buf, len, buf_size,
				       WRS_MODE_OFDM, WRS_MCS_MAX_OFDM,
				       cl_hw->pwr_trunc.ofdm);
}

static void _cl_power_trunc_print_cck(struct cl_hw *cl_hw, char **buf,
				      int *len, ssize_t *buf_size)
{
	cl_power_trunc_cck_ofdm_to_buf(cl_hw, buf, len, buf_size,
				       WRS_MODE_CCK, WRS_MCS_MAX_CCK,
				       cl_hw->pwr_trunc.cck);
}

static void cl_power_print_limits(struct cl_hw *cl_hw, char **buf,
				  int *len, ssize_t *buf_size, u8 channel)
{
	bool is_24g = cl_band_is_24g(cl_hw);
	bool country_limit = cl_hw->channel_info.use_channel_info;
	bool hardware_limit = strlen(cl_hw->conf->ce_hardware_power_table) > 0;
	bool eirp_limit = cl_hw->conf->ci_eirp_regulatory_en;
	u8 bw = 0;
	s16 country_val_q8 = 0;
	s16 hardware_val_q8 = 0;
	s16 eirp_val_q8 = 0;

	cl_snprintf(buf, len, buf_size,
		    "\nPower regulation/limitations\n"
		    "============================\n");
	cl_snprintf(buf, len, buf_size,
		    "Country regulation  = %s\n", country_limit ?
		    "On" : "Off");
	cl_snprintf(buf, len, buf_size,
		    "Hardware limitation = %s\n", hardware_limit ?
		    "On" : "Off");
	cl_snprintf(buf, len, buf_size,
		    "EIRP enable         = %s\n\n", eirp_limit ?
		    "True" : "False");

	if (!eirp_limit || (!country_limit && !hardware_limit))
		return;

	cl_snprintf(buf, len, buf_size,
		    "|-----------------------------------|\n"
		    "| BW  | COUNTRY | HARDWARE |  EIRP  |\n"
		    "|-----------------------------------|\n");

	for (bw = 0; bw < max_bw_idx(WRS_MODE_HE, is_24g); bw++) {
		country_val_q8 = cl_chan_info_get_country_limit_q8(cl_hw, channel, bw);
		hardware_val_q8 = cl_chan_info_get_hardware_limit_q8(cl_hw, channel, bw);
		eirp_val_q8 = cl_chan_info_get_eirp_limit_q8(cl_hw, bw);

		cl_snprintf(buf, len, buf_size, "| %3u |", BW_TO_MHZ(bw));

		if (country_limit)
			cl_power_q8_to_buf(buf, len, buf_size, "   ",
					   country_val_q8, " |", true);
		else
			cl_snprintf(buf, len, buf_size, "    X    |");

		if (hardware_limit)
			cl_power_q8_to_buf(buf, len, buf_size, "    ",
					   hardware_val_q8, " |", true);
		else
			cl_snprintf(buf, len, buf_size, "    X     |");

		cl_power_q8_to_buf(buf, len, buf_size, "  ", eirp_val_q8, " |\n", true);
	}
	cl_snprintf(buf, len, buf_size,
		    "|-----------------------------------|\n"
		    "(*) EIRP = MIN(COUNTRY, HARDWARE)\n\n");
}

static int cl_power_general_print(struct cl_hw *cl_hw)
{
	u8 channel = cl_hw->channel;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "Power general information\n"
		    "=========================\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "Channel               = %u\n", channel);
	cl_snprintf(&buf, &len, &buf_size,
		    "Standard              = %s\n",
		    (cl_hw->channel_info.standard == CL_STANDARD_FCC) ?
		    "FCC" : "ETSI");
	cl_snprintf(&buf, &len, &buf_size,
		    "Country code          = %s\n",
		    cl_hw->chip->conf->ce_country_code);
	cl_power_q8_to_buf(&buf, &len, &buf_size, "Antenna gain          = ",
			   cl_power_antenna_gain_q8(cl_hw), "\n", false);
	cl_snprintf(&buf, &len, &buf_size,
		    "Power control percent = %u%%\n",
		    cl_hw->power_db.curr_percentage);
	cl_snprintf(&buf, &len, &buf_size,
		    "Power control offset  = %d\n",
		    cl_hw->power_db.curr_offset);
	cl_snprintf(&buf, &len, &buf_size,
		    "VNS mode              = %u\n",
		    cl_hw->conf->ci_vns_pwr_mode);

	if (cl_hw->conf->ci_vns_pwr_mode)
		cl_snprintf(&buf, &len, &buf_size,
			    "VNS limit             = %u\n",
			    cl_hw->conf->ci_vns_pwr_limit);

	cl_power_print_limits(cl_hw, &buf, &len, &buf_size, channel);

	cl_snprintf(&buf, &len, &buf_size,
		    "!!! Notice:\n"
		    "Conducted power = Calibrated power + PPMCS offset - EIRP delta value\n"
		    "where EIRP delata value = Total - Truncated !!!\n");

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_power_table_print_he(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	_cl_power_table_print_he(cl_hw, &buf, &len, &buf_size);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_power_table_print_ht_vht(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	if (cl_band_is_6g(cl_hw))
		return 0;

	_cl_power_table_print_ht_vht(cl_hw, &buf, &len, &buf_size);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_power_table_print_ofdm(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	if (cl_band_is_6g(cl_hw))
		return 0;

	_cl_power_table_print_ofdm(cl_hw, &buf, &len, &buf_size);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_power_table_print_cck(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	if (!cl_band_is_24g(cl_hw))
		return 0;

	_cl_power_table_print_cck(cl_hw, &buf, &len, &buf_size);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_power_trunc_print_he(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	_cl_power_trunc_print_he(cl_hw, &buf, &len, &buf_size);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_power_trunc_print_ht_vht(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	if (cl_band_is_6g(cl_hw))
		return 0;

	_cl_power_trunc_print_ht_vht(cl_hw, &buf, &len, &buf_size);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_power_trunc_print_ofdm(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	if (cl_band_is_6g(cl_hw))
		return 0;

	_cl_power_trunc_print_ofdm(cl_hw, &buf, &len, &buf_size);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_power_trunc_print_cck(struct cl_hw *cl_hw)
{
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	if (!cl_band_is_24g(cl_hw))
		return 0;

	_cl_power_trunc_print_cck(cl_hw, &buf, &len, &buf_size);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void cl_power_auto_resp_to_buf(struct cl_hw *cl_hw, char **buf,
				      int *len, ssize_t *buf_size, u8 mode,
				      u8 max_mcs, s8 *pwr_auto_resp, const char *text)
{
	u8 mcs;
	u8 tx_ant_num = cl_power_tx_ant(cl_hw, mode);
	s32 ant_gain_q1 = cl_power_antenna_gain_q1(cl_hw);
	s32 arr_gain_q1 = cl_power_array_gain_q1(cl_hw, tx_ant_num);
	s32 conducted_q1, truncated_q1;

	cl_snprintf(buf, len, buf_size,
		    "\n%s Auto response\n"
		    "|------------------|\n"
		    "|MCS|Cond|Tot |Tab |\n"
		    "|---+----+----+----|\n",
		    text);

	for (mcs = 0; mcs < max_mcs; mcs++) {
		conducted_q1 = pwr_auto_resp[mcs] - arr_gain_q1;
		truncated_q1 = pwr_auto_resp[mcs] + ant_gain_q1;

		cl_snprintf(buf, len, buf_size,
			    "|%3u|", mcs);
		cl_power_q1_to_buf(buf, len, buf_size, "",
				   conducted_q1, "|", true);
		cl_power_q1_to_buf(buf, len, buf_size, "",
				   truncated_q1, "|", true);
		cl_power_q1_to_buf(buf, len, buf_size, "",
				   pwr_auto_resp[mcs], "|\n", true);
	}

	cl_snprintf(buf, len, buf_size,
		    "|------------------|\n");
}

static int cl_power_auto_response_print(struct cl_hw *cl_hw)
{
	struct cl_pwr_tables *pwr_tables = &cl_hw->phy_data_info.data->pwr_tables;
	char *buf = NULL;
	ssize_t buf_size;
	int len = 0;
	int err = 0;
	bool is_24g = cl_band_is_24g(cl_hw);
	bool is_5g = cl_band_is_5g(cl_hw);
	bool is_6g = cl_band_is_6g(cl_hw);

	cl_power_auto_resp_to_buf(cl_hw, &buf, &len, &buf_size, WRS_MODE_HE, WRS_MCS_MAX_HE,
				  pwr_tables->pwr_auto_resp_he, "HE");

	if (is_6g)
		goto out;

	if (is_5g || (is_24g && cl_hw->conf->ci_vht_cap_24g))
		cl_power_auto_resp_to_buf(cl_hw, &buf, &len, &buf_size,
					  WRS_MODE_VHT, WRS_MCS_MAX_VHT,
					  pwr_tables->pwr_auto_resp_ht_vht, "VHT/HT");
	else
		cl_power_auto_resp_to_buf(cl_hw, &buf, &len, &buf_size,
					  WRS_MODE_HT, WRS_MCS_MAX_HT,
					  pwr_tables->pwr_auto_resp_ht_vht, "HT");

	cl_power_auto_resp_to_buf(cl_hw, &buf, &len, &buf_size,
				  WRS_MODE_OFDM, WRS_MCS_MAX_OFDM,
				  pwr_tables->pwr_auto_resp_ofdm, "OFDM");

	if (is_24g)
		cl_power_auto_resp_to_buf(cl_hw, &buf, &len, &buf_size,
					  WRS_MODE_CCK, WRS_MCS_MAX_CCK,
					  pwr_tables->pwr_auto_resp_cck, "CCK");

out:
	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_power_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "usage:\n"
		 "-a : General power information\n"
		 "-b : HE power table\n"
		 "-c : HT/VHT power table\n"
		 "-d : OFDM power table\n"
		 "-e : CCK power table\n"
		 "-f : HE power truncate\n"
		 "-g : HT/VHT power truncate\n"
		 "-h : OFDM power truncate\n"
		 "-i : CCK power truncate\n"
		 "-j : Auto-response power tables\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_power_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	if (cli_params->num_params != 0)
		goto err_num_params;

	switch (cli_params->option) {
	case 'a':
		return cl_power_general_print(cl_hw);
	case 'b':
		return cl_power_table_print_he(cl_hw);
	case 'c':
		return cl_power_table_print_ht_vht(cl_hw);
	case 'd':
		return cl_power_table_print_ofdm(cl_hw);
	case 'e':
		return cl_power_table_print_cck(cl_hw);
	case 'f':
		return cl_power_trunc_print_he(cl_hw);
	case 'g':
		return cl_power_trunc_print_ht_vht(cl_hw);
	case 'h':
		return cl_power_trunc_print_ofdm(cl_hw);
	case 'i':
		return cl_power_trunc_print_cck(cl_hw);
	case 'j':
		return cl_power_auto_response_print(cl_hw);
	case '?':
		return cl_power_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		break;
	}

	return 0;

err_num_params:
	cl_dbg_err(cl_hw, "Wrong number of arguments\n");

	return 0;
}

