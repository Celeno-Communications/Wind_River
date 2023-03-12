// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_calib_common_db.h"
#include "cl_calib_common_api.h"
#include "cl_calib_dcoc.h"
#include "cl_utils.h"
#include "file.h"
#include "cl_band.h"
#include "cl_chandef.h"
#include "chip.h"
#include "cl_msg_tx.h"
#include "cl_config.h"

const u8 calib_channels_24g[CALIB_CHAN_24G_MAX] = {
	1, 6, 11
};

const u8 calib_channels_5g_plan[CALIB_CHAN_5G_PLAN] = {
	36, 52, 100, 116, 132, 149
};

const u8 calib_channels_6g_plan[CALIB_CHAN_6G_PLAN] = {
	1, 17, 33, 49, 65, 81, 97, 113, 129, 145, 161, 177, 193, 209, 225
};

static const u8 calib_channels_5g_bw_20[] = {
	36, 40, 44, 48, 52, 56, 60, 64, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 144,
	149, 153, 157, 161, 165
};

static const u8 calib_channels_5g_bw_40[] = {
	36, 44, 52, 60, 100, 108, 116, 124, 132, 140, 149, 157
};

static const u8 calib_channels_5g_bw_80[] = {
	36, 52, 100, 116, 132, 149
};

static const u8 calib_channels_5g_bw_160[] = {
	36, 100
};

static const u8 calib_channels_6g_bw_20[] = {
	1, 5, 9, 13, 17, 21, 25, 29, 33, 37, 41, 45, 49, 53, 57, 61, 65, 69, 73, 77, 81, 85, 89, 93,
	97, 101, 105, 109, 113, 117, 121, 125, 129, 133, 137, 141, 145, 149, 153, 157, 161, 165,
	169, 173, 177, 181, 185, 189, 193, 197, 201, 205, 209, 213, 217, 221, 225, 229, 233
};

static const u8 calib_channels_6g_bw_40[] = {
	1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81, 89, 97, 105, 113, 121, 129, 137, 145, 153, 161,
	169, 177, 185, 193, 201, 209, 217, 225
};

static const u8 calib_channels_6g_bw_80[] = {
	1, 17, 33, 49, 65, 81, 97, 113, 129, 145, 161, 177, 193, 209, 225
};

static const u8 calib_channels_6g_bw_160[] = {
	1, 33, 65, 97, 129, 161, 193, 225
};

static int cl_calib_dcoc_write_footer(struct cl_hw *cl_hw)
{
	char filename[CL_PATH_MAX];
	char buf[CALIB_MAX_BUF];
	int len;

	snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt", cl_config_dir, FILE_PREFIX_DCOC,
		 cl_hw->chip->idx);
	len = snprintf(buf, sizeof(buf), FILE_TCV_FOOTER, cl_hw->tcv_idx,
		       cl_hw->num_antennas);

	return cl_file_open_and_write(filename, O_WRONLY | O_APPEND, buf, len);
}

static int cl_calib_dcoc_validate_version(struct cl_chip *chip, char *buf)
{
	u32 file_version_id = 0;

	if (sscanf(buf, FILE_VERSION_ID, &file_version_id) == 1) {
		if (file_version_id != VERSION_ID_DCOC) {
			cl_dbg_chip_err(chip,
					"Calibration file's Version Id [%u] and current "
					"Version Id [%u] aren't equal\n",
					file_version_id, VERSION_ID_DCOC);
			return -1;
		} else {
			return 0;
		}
	} else {
		cl_dbg_chip_err(chip, "Calibration file doesn't contain a Version Id\n");
		return -1;
	}
}

static void cl_calib_dcoc_write_file_cfm(struct cl_hw *cl_hw, s16 calib_temperature, u8 channel,
					 u8 bw)
{
	struct cl_chip *chip = cl_hw->chip;
	int lna, chain;
	u8 bw_mhz = BW_TO_MHZ(bw);
	u8 band = cl_hw->calib_params.band;
	u8 band_idx = cl_band_num_to_fw_idx(band);
	u8 channel_idx = cl_calib_dcoc_channel_bw_to_idx(cl_hw, channel, bw);
	s32 params[DCOC_PARAM_MAX] = {0};
	struct cl_dcoc_calib *dcoc_calib;
	struct cl_dcoc_calib *dcoc_calib_dma;
	struct cl_iq_dcoc_data *dcoc_data = cl_hw->iq_dcoc_data_info.iq_dcoc_data;

	/* "<Channel> <BW> <Antenna> <Sx#> <LNA> <Temperature> <Ip> <In> <Qp> <Qn>" */
	params[DCOC_CHANNEL] = channel;
	params[DCOC_BW] = bw_mhz;
	params[DCOC_BAND] = band;
	params[DCOC_TEMPERATURE] = calib_temperature;

	for (lna = 0; lna < DCOC_LNA_GAIN_NUM; lna++) {
		params[DCOC_LNA] = lna;
		riu_chain_for_each(chain) {
			params[DCOC_CHAIN] = chain;
			dcoc_calib =
				&cl_hw->calib_db->wifi_dcoc[band_idx][channel_idx][bw][chain][lna];
			dcoc_calib_dma = &dcoc_data->iq_dcoc_db.dcoc[lna][chain];
			dcoc_calib->i = dcoc_calib_dma->i;
			params[DCOC_I] = dcoc_calib_dma->i;
			dcoc_calib->q = dcoc_calib_dma->q;
			params[DCOC_Q] = dcoc_calib_dma->q;

			if (!chip->conf->ce_calib_runtime_en ||
			    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
				cl_calib_dcoc_write_file(cl_hw, params);
		}
	}
}

static void cl_calib_bt_dcoc_write_file_cfm(struct cl_hw *cl_hw, s16 calib_temperature)
{
	struct cl_chip *chip = cl_hw->chip;
	int lna;
	u8 bw_bmp = cl_hw->calib_params.bt_bw_bmp;
	u8 num_of_channels, ch_idx, bw;
	u8 *ch_arr;
	u8 *bw_channel_arr[BT_FILTER_BW_MAX];
	s32 params[DCOC_PARAM_MAX] = {0};
	struct cl_dcoc_calib *dcoc_calib;
	struct cl_dcoc_calib *dcoc_calib_dma;
	struct cl_iq_dcoc_data *dcoc_data = cl_hw->iq_dcoc_data_info.iq_dcoc_data;
	struct cl_calib_params *calib_params = &cl_hw->calib_params;

	params[DCOC_BAND] = BAND_24G;
	params[DCOC_TEMPERATURE] = calib_temperature;
	/* BT is always using chain 2 */
	params[DCOC_CHAIN] = 2;

	if (!calib_params->is_sys_flow) {
		num_of_channels = 1;
		bw_channel_arr[BT_FILTER_BW_1M] = &cl_hw->calib_params.channel;
		bw_channel_arr[BT_FILTER_BW_2M] = &cl_hw->calib_params.channel;
	} else {
		num_of_channels = cl_hw->chip->conf->ci_calib_bt_num_of_ch_idx;
		bw_channel_arr[BT_FILTER_BW_1M] = cl_hw->chip->conf->ci_calib_bt_channel_idx_1m;
		bw_channel_arr[BT_FILTER_BW_2M] = cl_hw->chip->conf->ci_calib_bt_channel_idx_2m;
	}
	for (bw = 0; bw < BT_FILTER_BW_MAX; bw++) {
		if (((1 << bw) & bw_bmp) == 0)
			continue;

		params[DCOC_BW] = (1 << bw);
		ch_arr = bw_channel_arr[bw];
		for (ch_idx = 0; ch_idx < num_of_channels; ch_idx++) {
			params[DCOC_CHANNEL] = ch_arr[ch_idx];
			for (lna = 0; lna < BT_DCOC_LNA_GAIN_NUM; lna++) {
				params[DCOC_LNA] = lna;
				dcoc_calib = &cl_hw->calib_db->bt_dcoc[ch_idx][bw][lna];
				dcoc_calib_dma = &dcoc_data->iq_dcoc_db.bt_dcoc[ch_idx]
									       [bw][lna];
				dcoc_calib->i = dcoc_calib_dma->i;
				params[DCOC_I] = dcoc_calib_dma->i;
				dcoc_calib->q = dcoc_calib_dma->q;
				params[DCOC_Q] = dcoc_calib_dma->q;

				if (!chip->conf->ce_calib_runtime_en ||
				    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
					cl_calib_bt_dcoc_write_file(cl_hw, params);
			}
		}
	}
}

static void cl_calib_bt_dcoc_report_write_file_cfm(struct cl_hw *cl_hw, s16 calib_temperature)
{
	struct cl_chip *chip = cl_hw->chip;
	int lna;
	u8 bw_bmp = cl_hw->calib_params.bt_bw_bmp;
	u8 num_of_channels, ch_idx, bw;
	u8 *ch_arr;
	u8 *bw_channel_arr[BT_FILTER_BW_MAX];
	s32 params[DCOC_REPORT_PARAM_MAX] = {0};
	struct cl_dcoc_report *dcoc_calib_report_dma;
	s16 i, q;
	struct cl_iq_dcoc_data *dcoc_data = cl_hw->iq_dcoc_data_info.iq_dcoc_data;
	struct cl_calib_params *calib_params = &cl_hw->calib_params;
	/* "<Channel> <BW> <Antenna> <Sx#> <LNA> <Temperature> <Ip> <In> <Qp> <Qn>" */

	params[DCOC_REPORT_BAND] = BAND_24G;
	params[DCOC_REPORT_TEMPERATURE] = calib_temperature;
	params[DCOC_REPORT_CHAIN] = 2;
	num_of_channels = chip->conf->ci_calib_bt_num_of_ch_idx;

	if (!calib_params->is_sys_flow) {
		num_of_channels = 1;
		bw_channel_arr[BT_FILTER_BW_1M] = &cl_hw->calib_params.channel;
		bw_channel_arr[BT_FILTER_BW_2M] = &cl_hw->calib_params.channel;
	} else {
		num_of_channels = cl_hw->chip->conf->ci_calib_bt_num_of_ch_idx;
		bw_channel_arr[BT_FILTER_BW_1M] = cl_hw->chip->conf->ci_calib_bt_channel_idx_1m;
		bw_channel_arr[BT_FILTER_BW_2M] = cl_hw->chip->conf->ci_calib_bt_channel_idx_2m;
	}

	for (bw = 0; bw < BT_FILTER_BW_MAX; bw++) {
		if (!((1 << bw) & bw_bmp))
			continue;
		params[DCOC_REPORT_BW] = (1 << bw);
		ch_arr = bw_channel_arr[bw];
		for (ch_idx = 0; ch_idx < num_of_channels; ch_idx++) {
			params[DCOC_REPORT_CHANNEL] = ch_arr[ch_idx];
			for (lna = 0; lna < BT_DCOC_LNA_GAIN_NUM; lna++) {
				params[DCOC_REPORT_LNA] = lna;
				dcoc_calib_report_dma =
				&dcoc_data->report.bt_dcoc[ch_idx][bw][lna];

				i = (s16)le16_to_cpu(dcoc_calib_report_dma->i_dc);
				params[DCOC_REPORT_I_MV] = i;

				params[DCOC_REPORT_I_ITERATIONS] =
					le16_to_cpu(dcoc_calib_report_dma->i_iterations);

				q = (s16)le16_to_cpu(dcoc_calib_report_dma->q_dc);
				params[DCOC_REPORT_Q_MV] = q;

				params[DCOC_REPORT_Q_ITERATIONS] =
					le16_to_cpu(dcoc_calib_report_dma->q_iterations);

				if (!chip->conf->ce_calib_runtime_en ||
				    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
					cl_calib_bt_dcoc_report_write_file(cl_hw, params);
			}
		}
	}
}

static void cl_calib_dcoc_report_write_file_cfm(struct cl_hw *cl_hw, s16 calib_temperature,
						int channel, u8 bw)
{
	struct cl_chip *chip = cl_hw->chip;
	int lna, chain;
	struct cl_dcoc_report *dcoc_calib_report_dma;
	int bw_mhz = BW_TO_MHZ(bw);
	s32 params[DCOC_REPORT_PARAM_MAX] = {0};
	u8 band = cl_hw->calib_params.band;
	u8 dcoc_threshold = chip->conf->ci_dcoc_mv_thr[bw];
	s16 i, q;

	/* "<CH> <BW> <Antenna> <Sx#> <LNA> <Temperature> <I_MV> <I_ITER> <Q_MV> <Q_ITERA>" */
	params[DCOC_REPORT_CHANNEL] = channel;
	params[DCOC_REPORT_BW] = bw_mhz;
	params[DCOC_REPORT_BAND] = band;
	params[DCOC_REPORT_TEMPERATURE] = calib_temperature;

	/* "<LNA> <Ant> <I DC> <I iterations> <Q DC> <Q iterations>" */
	for (lna = 0; lna < DCOC_LNA_GAIN_NUM; lna++) {
		params[DCOC_REPORT_LNA] = lna;
		riu_chain_for_each(chain) {
			params[DCOC_REPORT_CHAIN] = chain;
			dcoc_calib_report_dma =
				&cl_hw->iq_dcoc_data_info.iq_dcoc_data->report.dcoc[lna][chain];

			i = (s16)le16_to_cpu(dcoc_calib_report_dma->i_dc);
			params[DCOC_REPORT_I_MV] = i;

			params[DCOC_REPORT_I_ITERATIONS] =
				le16_to_cpu(dcoc_calib_report_dma->i_iterations);

			q = (s16)le16_to_cpu(dcoc_calib_report_dma->q_dc);
			params[DCOC_REPORT_Q_MV] = q;

			params[DCOC_REPORT_Q_ITERATIONS] =
				le16_to_cpu(dcoc_calib_report_dma->q_iterations);

			if (!cl_hw->chip->conf->ce_calib_runtime_en ||
			    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
				cl_calib_dcoc_report_write_file(cl_hw, params);

			if (abs(i) > dcoc_threshold || abs(q) > dcoc_threshold) {
				cl_dbg_warn(cl_hw,
					    "Warning: DCOC value exceeds threshold [%umV]: channel %u,"
					    " bw = %u, lna = %u, chain = %u, I[mV] = %d, "
					    "I[Iter] = %u, Q[mV] = %d, Q[Iter] = %u\n",
					    dcoc_threshold, channel, bw_mhz, lna, chain, i,
					    params[DCOC_REPORT_I_ITERATIONS], q,
					    params[DCOC_REPORT_Q_ITERATIONS]);
				cl_hw->calib_db->errors.dcoc++;
			}
		}
	}
}

static int cl_calib_dcoc_calibrate_channel(struct cl_hw *cl_hw, u32 channel, u32 bw,
					   bool first_channel, u8 band)
{
	u32 primary = 0;
	u32 center = 0;
	enum nl80211_chan_width width = NL80211_CHAN_WIDTH_20;
	struct cl_calib_params params = {0};

	cl_calib_params_fill(&params,
			     WIFI_CALIB_MODE_RX_DCOC,
			     0,
			     band,
			     channel,
			     bw,
			     first_channel,
			     0,
			     ANT_MASK(cl_hw->num_antennas),
			     0,
			     false,
			     0,
			     true);
	if (cl_chandef_calc_calib(cl_hw, channel, bw, &width, &primary, &center, band)) {
		cl_dbg_err(cl_hw, "cl_chandef_calc failed\n");
		return -EINVAL;
	}

	cl_dbg_trace(cl_hw, "\n ------  START CALIB DCOC CHANNEL  -----\n");
	cl_dbg_trace(cl_hw, "channel = %u first_channel = %u\n", channel, first_channel);

	/* Send set calib request */
	return cl_msg_tx_set_calib(cl_hw, primary, center, &params);
}

static void cl_calib_dcoc_average(struct cl_chip *chip, u8 band, u8 center,
				  u8 bw, u8 chain, u8 sx, u8 lna)
{
	struct cl_hw *cl_hw = chip->cl_hw_tcv0;
	struct cl_dcoc_calib *dcoc_db_left;
	struct cl_dcoc_calib *dcoc_db_center;
	struct cl_dcoc_calib *dcoc_db_right;
	u8 left_idx = cl_calib_dcoc_tcv_channel_to_idx(chip, band,
						       calib_channels_6g_plan[center - 1], bw);
	u8 center_idx = cl_calib_dcoc_tcv_channel_to_idx(chip, band,
							 calib_channels_6g_plan[center], bw);
	u8 right_idx = cl_calib_dcoc_tcv_channel_to_idx(chip, band,
							calib_channels_6g_plan[center + 1], bw);

	dcoc_db_left = &cl_hw->calib_db->wifi_dcoc[left_idx][bw][sx][chain][lna];
	dcoc_db_center = &cl_hw->calib_db->wifi_dcoc[center_idx][bw][sx][chain][lna];
	dcoc_db_right = &cl_hw->calib_db->wifi_dcoc[right_idx][bw][sx][chain][lna];

	dcoc_db_center->i = (dcoc_db_left->i + dcoc_db_right->i) / 2;
	dcoc_db_center->q = (dcoc_db_left->q + dcoc_db_right->q) / 2;
}

static int cl_calib_dcoc_calibrate_6g(struct cl_hw *cl_hw)
{
	int i;
	u8 chain, lna;
	u8 tcv_idx = cl_hw->tcv_idx;
	u8 sx = tcv_idx;
	bool first_channel = true;
	struct cl_chip *chip = cl_hw->chip;

	/* Calibrate channels: 1, 33, 65, 97, 129, 161, 193, 225 */
	for (i = 0; i < CALIB_CHAN_6G_PLAN; i += 2) {
		if (cl_hw->conf->ci_cap_bandwidth == CHNL_BW_160 &&
		    (cl_calib_dcoc_calibrate_channel(cl_hw, calib_channels_6g_plan[i], CHNL_BW_160,
						     first_channel, BAND_6G) == 0))
			first_channel = false;

		if (cl_calib_dcoc_calibrate_channel(cl_hw, calib_channels_6g_plan[i], CHNL_BW_80,
						    first_channel, BAND_6G) == 0)
			first_channel = false;

		if (cl_calib_dcoc_calibrate_channel(cl_hw, calib_channels_6g_plan[i], CHNL_BW_20,
						    first_channel, BAND_6G) == 0)
			first_channel = false;
	}

	/*
	 * For these channels 17, 49, 81, 113, 145, 177, 209
	 * calculate average of closest neighbors
	 */
	for (i = 1; i < CALIB_CHAN_6G_PLAN - 1; i += 2)
		riu_chain_for_each(chain)
			for (lna = 0; lna < DCOC_LNA_GAIN_NUM; lna++) {
				cl_calib_dcoc_average(chip, tcv_idx, i, CHNL_BW_80,
						      chain, sx, lna);
				cl_calib_dcoc_average(chip, tcv_idx, i, CHNL_BW_20,
						      chain, sx, lna);
			}

	return first_channel;
}

static int cl_calib_dcoc_calibrate_5g(struct cl_hw *cl_hw)
{
	int i;
	bool first_channel = true;

	if (cl_hw->conf->ci_cap_bandwidth == CHNL_BW_160) {
		if (cl_calib_dcoc_calibrate_channel(cl_hw, 36, CHNL_BW_160, first_channel,
						    BAND_5G) == 0)
			first_channel = false;

		if (cl_calib_dcoc_calibrate_channel(cl_hw, 100, CHNL_BW_160, first_channel,
						    BAND_5G) == 0)
			first_channel = false;
	}

	for (i = 0; i < CALIB_CHAN_5G_PLAN; i++) {
		if (cl_calib_dcoc_calibrate_channel(cl_hw, calib_channels_5g_plan[i], CHNL_BW_80,
						    first_channel, BAND_5G) == 0)
			first_channel = false;

		if (cl_calib_dcoc_calibrate_channel(cl_hw, calib_channels_5g_plan[i], CHNL_BW_40,
						    first_channel, BAND_5G) == 0)
			first_channel = false;

		if (cl_calib_dcoc_calibrate_channel(cl_hw, calib_channels_5g_plan[i], CHNL_BW_20,
						    first_channel, BAND_5G) == 0)
			first_channel = false;
	}

	return first_channel;
}

static void cl_calib_dcoc_calibrate_24g(struct cl_hw *cl_hw)
{
	int i;
	bool first_channel = true;

	for (i = 0; i < CALIB_CHAN_24G_MAX; i++) {
		if (cl_calib_dcoc_calibrate_channel(cl_hw, calib_channels_24g[i], CHNL_BW_40,
						    first_channel, BAND_24G) == 0)
			first_channel = false;

		if (cl_calib_dcoc_calibrate_channel(cl_hw, calib_channels_24g[i], CHNL_BW_20,
						    first_channel, BAND_24G) == 0)
			first_channel = false;
	}
}

static void cl_calib_dcoc_calibrate(struct cl_hw *cl_hw)
{
	/* TODO - delete this when 6g is supported */
	bool is_6g = false;

	cl_dbg_verbose(cl_hw, "Strating to calibrate dcoc for all bands"
		       "- this may take several seconds\n");
	if (is_6g)
		cl_calib_dcoc_calibrate_6g(cl_hw);
	cl_calib_dcoc_calibrate_5g(cl_hw);
	cl_calib_dcoc_calibrate_24g(cl_hw);

	/* Mark that calibration flow has finished */
	cl_hw->chip->is_calib_in_progress = false;
}

static void cl_calib_dcoc_remove_tcv_entries(struct cl_hw *cl_hw)
{
	u8 num_calib_ant = cl_hw->chip->iq_dcoc_conf.dcoc_file_num_ant;

	cl_calib_common_remove_tcv_entries(cl_hw, WIFI_DCOC_FILE, num_calib_ant);
}

void cl_calib_dcoc_init_calibration(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_iq_dcoc_conf *iq_dcoc_conf = &chip->iq_dcoc_conf;

	/* No need to init calibration to non-Olympus phy */
	if (!IS_REAL_PHY(chip))
		return;

	if (!iq_dcoc_conf->dcoc_calib_needed) {
		u8 file_num_antennas = iq_dcoc_conf->dcoc_file_num_ant;

		if (file_num_antennas < cl_hw->num_antennas) {
			cl_dbg_verbose(cl_hw,
				       "Num of antennas [%u], is larger than DCOC calibration file"
				       " num of antennas [%u], recalibration is needed\n",
				       cl_hw->num_antennas, file_num_antennas);
			cl_hw->calib_db->file_flags.dcoc |= CALIB_FLAG_HEADER_TCV0;
			cl_calib_dcoc_remove_tcv_entries(cl_hw);
		} else {
			return;
		}
	}

	cl_calib_dcoc_calibrate(cl_hw);

	iq_dcoc_conf->dcoc_calib_needed = false;
	iq_dcoc_conf->dcoc_file_num_ant = cl_hw->num_antennas;
}

int cl_calib_dcoc_init_calibration_channel(struct cl_hw *cl_hw)
{
	u32 channel = cl_hw->channel;
	u8 bw = cl_hw->bw;
	u8 band = cl_band_to_fw_idx(cl_hw);

	return cl_calib_dcoc_calibrate_channel(cl_hw, channel, bw, false, band);
}

int cl_calib_dcoc_post_read_actions(struct cl_chip *chip, char *buf)
{
	/*
	 * Assume DCOC Calibration is needed. Will be reverted once DCOC Calibration
	 * values that matches the TCV will be found in the Calibration File.
	 */
	struct cl_hw *cl_hw = chip->cl_hw_tcv0;

	chip->iq_dcoc_conf.dcoc_calib_needed = true;

	if (cl_calib_dcoc_validate_version(chip, buf) != 0) {
		cl_dbg_chip_verbose(chip, "Need to Calibrate DCOC\n");
		/* Remove DCOC Calibration File and re-calibrate DCOC */
		cl_hw->calib_db->file_flags.dcoc = CALIB_FLAG_ALL;
		cl_hw->calib_db->file_flags.dcoc_report = CALIB_FLAG_ALL_REPORT;
		return -1;
	}

	return 0;
}

static u8 cl_calib_dcoc_get_chan_idx(const u8 calib_chan_list[], u8 list_len, u8 channel)
{
	u8 i = 0;

	for (i = 1; i < list_len; i++)
		if (calib_chan_list[i] > channel)
			return (i - 1);

	return (list_len - 1);
}

void cl_calib_dcoc_parse_str(struct cl_chip *chip, char *str, enum calib_files_idx file_idx)
{
	struct cl_hw *cl_hw = chip->cl_hw_tcv0;
	int ret = 0;
	u32 channel = 0;
	u32 bw_mhz = 0;
	u32 chain = 0;
	u32 sx = 0;
	u32 lna = 0;
	s32 temperature = 0;
	s32 i_val = 0;
	s32 q_val = 0;
	u32 channel_idx = 0;
	u32 avg_chan_idx = 0;
	u32 bw = 0;
	u32 band = 0;
	u8 band_idx = 0;
	const char *delims = " \t";
	u8 chan_idx_max = cl_band_is_6g(chip->cl_hw_tcv0) ? CALIB_CHAN_6G_MAX : CALIB_CHAN_5G_MAX;

	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &channel);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing channel from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &bw_mhz);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing bw from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &chain);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing chain from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &band);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing band from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &lna);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing lna from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	ret = kstrtos32(cl_calib_common_non_empty_strsep(&str, delims), 10, &temperature);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing temp. from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	ret = kstrtos32(cl_calib_common_non_empty_strsep(&str, delims), 10, &i_val);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing ip from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	ret = kstrtos32(cl_calib_common_non_empty_strsep(&str, delims), 10, &q_val);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing qp from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	bw = MHZ_TO_BW(bw_mhz);
	channel_idx = cl_calib_dcoc_tcv_channel_to_idx(chip, band, channel, bw);

	if (channel_idx >= chan_idx_max || bw >= CHNL_BW_MAX || chain >= MAX_ANTENNAS ||
	    band > BAND_24G || lna >= DCOC_LNA_GAIN_NUM || temperature >= CL_MAX_TEMPERATURE) {
		cl_dbg_chip_err(chip, "some wrong parameter parsed: "
				"channel=%d, bw=%d, chain=%d, band=%d, lna=%d, temperature=%d\n",
				channel, bw_mhz, chain, band, lna, temperature);
		return;
	}

	band_idx = cl_band_num_to_fw_idx(band);
	cl_hw->calib_db->wifi_dcoc[band_idx][channel_idx][bw][chain][lna].i = i_val;
	cl_hw->calib_db->wifi_dcoc[band_idx][channel_idx][bw][chain][lna].q = q_val;

	/*
	 * For 6g, and channels 17, 49, 81, 113, 145, 177, 209
	 * calculate average of closest neighbors
	 */
	if (!cl_band_is_6g(chip->cl_hw_tcv0) || bw == CHNL_BW_160)
		return;

	if (channel_idx > 0 && channel_idx < CALIB_CHAN_6G_MAX) {
		avg_chan_idx = cl_calib_dcoc_get_chan_idx(calib_channels_6g_plan,
							  sizeof(calib_channels_6g_plan),
							  channel) - 1;
		cl_calib_dcoc_average(chip, band, avg_chan_idx, bw, chain, sx, lna);
	}
}

void cl_calib_bt_dcoc_parse_str(struct cl_chip *chip, char *str, enum calib_files_idx file_idx)
{
	struct cl_hw *cl_hw = chip->cl_hw_tcv0;
	int ret = 0;
	u32 bw_mhz = 0;
	u32 lna = 0;
	s32 temperature = 0;
	s32 i_val = 0;
	s32 q_val = 0;
	u32 channel_idx = 0;
	u32 bw = 0;
	u8 chan_idx_max = NUM_OF_BT_CHANNELS;
	const char *delims = " \t";

	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &channel_idx);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing channel from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &bw_mhz);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing bw from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &lna);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing lna from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	ret = kstrtos32(cl_calib_common_non_empty_strsep(&str, delims), 10, &temperature);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing temp. from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	ret = kstrtos32(cl_calib_common_non_empty_strsep(&str, delims), 10, &i_val);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing ip from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	ret = kstrtos32(cl_calib_common_non_empty_strsep(&str, delims), 10, &q_val);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing qp from str=%s failed (ret %d)\n", str, ret);
		return;
	}

	bw = BT_FILTER_BW_MHZ_TO_IDX(bw_mhz);

	if (channel_idx >= chan_idx_max || bw >= BT_FILTER_BW_MAX ||
	    lna >= BT_DCOC_LNA_GAIN_NUM || temperature >= CL_MAX_TEMPERATURE) {
		cl_dbg_chip_err(chip, "some wrong parameter parsed: "
				"channel=%d, bw=%d, lna=%d, temperature=%d\n",
				channel_idx, bw_mhz, lna, temperature);
		return;
	}

	cl_hw->calib_db->bt_dcoc[channel_idx][bw][lna].i = i_val;
	cl_hw->calib_db->bt_dcoc[channel_idx][bw][lna].q = q_val;
}

static u8 cl_calib_dcoc_convert_to_channel_in_plan(u8 channel, u8 band)
{
	u8 idx;

	if (band == BAND_6G) {
		idx = cl_calib_dcoc_get_chan_idx(calib_channels_6g_plan,
						 ARRAY_SIZE(calib_channels_6g_plan), channel);
		return calib_channels_6g_plan[idx];
	}

	idx = cl_calib_dcoc_get_chan_idx(calib_channels_5g_plan,
					 ARRAY_SIZE(calib_channels_5g_plan), channel);

	return calib_channels_5g_plan[idx];
}

u8 cl_calib_dcoc_channel_bw_to_idx(struct cl_hw *cl_hw, u8 channel, u8 bw)
{
	if (cl_band_is_6g(cl_hw)) {
		if (bw == CHNL_BW_160)
			return cl_calib_dcoc_get_chan_idx(calib_channels_6g_bw_160,
							  ARRAY_SIZE(calib_channels_6g_bw_160),
							  channel);
		/*
		 * In case of non runtime calib - channels that don't exist in the plan list will
		 * not be calibrated. Thus, the calib data need to be fetched from a close channel
		 * that was calibrated - AKA "fallback channel".
		 * In this case the channel value should convert to the "fallback channel" that had
		 * been calibrated. The func will return the idx value of the "fallback channel"
		 * instead of the original idx channel.
		 */
		if (!cl_hw->chip->conf->ce_calib_runtime_en)
			channel = cl_calib_dcoc_convert_to_channel_in_plan(channel, BAND_6G);

		if (bw == CHNL_BW_20)
			return cl_calib_dcoc_get_chan_idx(calib_channels_6g_bw_20,
							  ARRAY_SIZE(calib_channels_6g_bw_20),
							  channel);

		if (bw == CHNL_BW_40)
			return cl_calib_dcoc_get_chan_idx(calib_channels_6g_bw_40,
							  ARRAY_SIZE(calib_channels_6g_bw_40),
							  channel);

		if (bw == CHNL_BW_80)
			return cl_calib_dcoc_get_chan_idx(calib_channels_6g_bw_80,
							  ARRAY_SIZE(calib_channels_6g_bw_80),
							  channel);
	}

	if (cl_band_is_5g(cl_hw)) {
		if (bw == CHNL_BW_160)
			return cl_calib_dcoc_get_chan_idx(calib_channels_5g_bw_160,
							  ARRAY_SIZE(calib_channels_5g_bw_160),
							  channel);

		if (!cl_hw->chip->conf->ce_calib_runtime_en)
			channel = cl_calib_dcoc_convert_to_channel_in_plan(channel, BAND_5G);

		if (bw == CHNL_BW_20)
			return cl_calib_dcoc_get_chan_idx(calib_channels_5g_bw_20,
							  ARRAY_SIZE(calib_channels_5g_bw_20),
							  channel);

		if (bw == CHNL_BW_40)
			return cl_calib_dcoc_get_chan_idx(calib_channels_5g_bw_40,
							  ARRAY_SIZE(calib_channels_5g_bw_40),
							  channel);

		if (bw == CHNL_BW_80)
			return cl_calib_dcoc_get_chan_idx(calib_channels_5g_bw_80,
							  ARRAY_SIZE(calib_channels_5g_bw_80),
							  channel);
	}

	return cl_calib_dcoc_get_chan_idx(calib_channels_24g, ARRAY_SIZE(calib_channels_24g),
					  channel);
}

void cl_calib_dcoc_fill_data(struct cl_hw *cl_hw, struct cl_iq_dcoc_info *iq_dcoc_db, bool is_calib)
{
	u8 lna = 0, chain = 0;
	u8 bw = cl_hw->bw;
	u8 channel_idx = cl_calib_dcoc_channel_bw_to_idx(cl_hw, cl_hw->channel, bw);
	u8 band = cl_hw->conf->ci_band_num;
	u8 band_idx;

	if (is_calib) {
		bw = cl_hw->calib_params.wifi_bw;
		channel_idx = cl_calib_dcoc_channel_bw_to_idx(cl_hw,
							      cl_hw->calib_params.channel,
							      bw);
		band = cl_hw->calib_params.band;
	}

	band_idx = cl_band_num_to_fw_idx(band);

	for (lna = 0; lna < DCOC_LNA_GAIN_NUM; lna++)
		for (chain = 0; chain < MAX_ANTENNAS; chain++)
			iq_dcoc_db->dcoc[lna][chain] =
				cl_hw->calib_db->wifi_dcoc[band_idx][channel_idx][bw][chain][lna];
}

u8 cl_calib_dcoc_tcv_channel_to_idx(struct cl_chip *chip, u8 band, u8 channel, u8 bw)
{
	u8 i = 0;

	if (cl_band_is_6g_band(band)) {
		if (bw == CHNL_BW_20)
			return cl_calib_dcoc_get_chan_idx(calib_channels_6g_bw_20,
							  ARRAY_SIZE
							  (calib_channels_6g_bw_20),
							  channel);

		if (bw == CHNL_BW_40)
			return cl_calib_dcoc_get_chan_idx(calib_channels_6g_bw_40,
							  ARRAY_SIZE
							  (calib_channels_6g_bw_40),
							  channel);

		if (bw == CHNL_BW_80)
			return cl_calib_dcoc_get_chan_idx(calib_channels_6g_bw_80,
							  ARRAY_SIZE
							  (calib_channels_6g_bw_80),
							  channel);

		if (bw == CHNL_BW_160)
			return cl_calib_dcoc_get_chan_idx(calib_channels_6g_bw_160,
							  ARRAY_SIZE
							  (calib_channels_6g_bw_160),
							  channel);
	} else {
		if (channel <= NUM_CHANNELS_24G) {
			for (i = 0; i < CALIB_CHAN_24G_MAX; i++)
				if (calib_channels_24g[i] == channel)
					return i;
		} else {
			if (bw == CHNL_BW_20)
				return cl_calib_dcoc_get_chan_idx(calib_channels_5g_bw_20,
								ARRAY_SIZE
								(calib_channels_5g_bw_20),
								channel);

			if (bw == CHNL_BW_40)
				return cl_calib_dcoc_get_chan_idx(calib_channels_5g_bw_40,
								ARRAY_SIZE
								(calib_channels_5g_bw_40),
								channel);

			if (bw == CHNL_BW_80)
				return cl_calib_dcoc_get_chan_idx(calib_channels_5g_bw_80,
								ARRAY_SIZE
								(calib_channels_5g_bw_80),
								channel);

			if (bw == CHNL_BW_160)
				return cl_calib_dcoc_get_chan_idx(calib_channels_5g_bw_160,
								ARRAY_SIZE
								(calib_channels_5g_bw_160),
								channel);
		}
	}
	return 0;
}

void cl_calib_wifi_dcoc_handle_set_calib_cfm(struct cl_hw *cl_hw)
{
	struct calib_cfm *dcoc_iq_cfm =
		&cl_hw->iq_dcoc_data_info.iq_dcoc_data->dcoc_iq_cfm[CALIB_CFM_WIFI_DCOC];
	u8 channel = cl_hw->calib_params.channel;
	u8 bw = cl_hw->calib_params.wifi_bw;
	s16 calib_temperature = 0;

	cl_dbg_trace(cl_hw, "calib_temperature = %d, channel = %u, bw = %u\n", calib_temperature,
		     channel, bw);

	cl_calib_dcoc_write_file_cfm(cl_hw, calib_temperature, channel, bw);
	cl_calib_dcoc_report_write_file_cfm(cl_hw, calib_temperature, channel, bw);

	/* If all channels calibration is finished - write footer */
	if (!cl_hw->chip->is_calib_in_progress) {
		u16 dcoc_erros = cl_hw->calib_db->errors.dcoc;

		if (dcoc_erros)
			cl_calib_common_write_error(cl_hw, FILE_PREFIX_DCOC, dcoc_erros);

		cl_calib_dcoc_write_footer(cl_hw);
		cl_dbg_verbose(cl_hw, "DCOC calibration finished\n");
	}

	/* Set the default status to FAIL, to ensure FW is actually changing the value,*/
	/* if the calibration succeeded*/
	dcoc_iq_cfm->status = CALIB_FAIL;
}

void cl_calib_bt_dcoc_handle_set_calib_cfm(struct cl_hw *cl_hw)
{
	struct calib_cfm *dcoc_iq_cfm =
		&cl_hw->iq_dcoc_data_info.iq_dcoc_data->dcoc_iq_cfm[CALIB_CFM_BT_DCOC];
	s16 calib_temperature = 0;

	cl_calib_bt_dcoc_write_file_cfm(cl_hw, calib_temperature);
	cl_calib_bt_dcoc_report_write_file_cfm(cl_hw, calib_temperature);

	/* Set the default status to FAIL, to ensure FW is actually changing the value,*/
	/* if the calibration succeeded*/
	dcoc_iq_cfm->status = CALIB_FAIL;
}

int cl_calib_bt_dcoc_write_version(struct cl_hw *cl_hw)
{
	return cl_calib_common_write_version(cl_hw, &cl_hw->calib_db->file_flags.bt_dcoc,
					     FILE_PREFIX_BT_DCOC, FILE_TITLE_DCOC, VERSION_ID_DCOC);
}

int cl_calib_dcoc_write_version(struct cl_hw *cl_hw)
{
	return cl_calib_common_write_version(cl_hw, &cl_hw->calib_db->file_flags.dcoc,
					     FILE_PREFIX_DCOC, FILE_TITLE_DCOC, VERSION_ID_DCOC);
}

int cl_calib_dcoc_report_write_version(struct cl_hw *cl_hw)
{
	return cl_calib_common_write_version(cl_hw, &cl_hw->calib_db->file_flags.dcoc_report,
					     FILE_PREFIX_DCOC_REPORT, FILE_TITLE_DCOC_REPORT,
					     VERSION_ID_DCOC);
}

int cl_calib_bt_dcoc_report_write_version(struct cl_hw *cl_hw)
{
	return cl_calib_common_write_version(cl_hw,
					     &cl_hw->calib_db->file_flags.bt_dcoc_report,
					     FILE_PREFIX_BT_DCOC_REPORT,
					     FILE_TITLE_DCOC_REPORT,
					     VERSION_ID_DCOC);
}

int cl_calib_dcoc_write_file(struct cl_hw *cl_hw, s32 *params)
{
	char filename[CL_PATH_MAX];
	char buf[CALIB_MAX_BUF];
	int len = 0;

	snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt", cl_config_dir, FILE_PREFIX_DCOC,
		 cl_hw->chip->idx);

	if (cl_hw->calib_db->file_flags.dcoc)
		cl_calib_dcoc_write_version(cl_hw);

	len = snprintf(buf, sizeof(buf), "%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
		       params[DCOC_CHANNEL], params[DCOC_BW], params[DCOC_CHAIN],
		       params[DCOC_BAND], params[DCOC_LNA], params[DCOC_TEMPERATURE],
		       params[DCOC_I], params[DCOC_Q]);

	return cl_file_open_and_write(filename, O_WRONLY | O_APPEND, buf, len);
}

int cl_calib_bt_dcoc_write_file(struct cl_hw *cl_hw, s32 *params)
{
	char filename[CL_PATH_MAX];
	char buf[CALIB_MAX_BUF];
	int len = 0;

	snprintf(filename, sizeof(filename),
		 "%s/calib/%s%u.txt", cl_config_dir,
		 FILE_PREFIX_BT_DCOC,
		 cl_hw->chip->idx);

	if (cl_hw->calib_db->file_flags.dcoc)
		cl_calib_bt_dcoc_write_version(cl_hw);

	len = snprintf(buf, sizeof(buf), "%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
		       params[DCOC_CHANNEL], params[DCOC_BW], params[DCOC_CHAIN],
		       params[DCOC_BAND], params[DCOC_LNA], params[DCOC_TEMPERATURE],
		       params[DCOC_I], params[DCOC_Q]);

	return cl_file_open_and_write(filename, O_WRONLY | O_APPEND, buf, len);
}

int cl_calib_dcoc_report_write_file(struct cl_hw *cl_hw, s32 *params)
{
	char filename[CL_PATH_MAX];
	char buf[CALIB_MAX_BUF];
	int len = 0;

	snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt", cl_config_dir,
		 FILE_PREFIX_DCOC_REPORT, cl_hw->chip->idx);

	if (cl_hw->calib_db->file_flags.dcoc_report)
		cl_calib_dcoc_report_write_version(cl_hw);

	len = snprintf(buf, sizeof(buf), "%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
		       params[DCOC_REPORT_CHANNEL], params[DCOC_REPORT_BW],
		       params[DCOC_REPORT_CHAIN], params[DCOC_REPORT_BAND],
		       params[DCOC_REPORT_LNA], params[DCOC_REPORT_TEMPERATURE],
		       params[DCOC_REPORT_I_MV], params[DCOC_REPORT_I_ITERATIONS],
		       params[DCOC_REPORT_Q_MV], params[DCOC_REPORT_Q_ITERATIONS]);

	return cl_file_open_and_write(filename, O_WRONLY | O_APPEND, buf, len);
}

int cl_calib_bt_dcoc_report_write_file(struct cl_hw *cl_hw, s32 *params)
{
	char filename[CL_PATH_MAX];
	char buf[CALIB_MAX_BUF];
	int len = 0;

	snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt", cl_config_dir,
		 FILE_PREFIX_BT_DCOC_REPORT, cl_hw->chip->idx);

	if (cl_hw->calib_db->file_flags.bt_dcoc_report)
		cl_calib_bt_dcoc_report_write_version(cl_hw);

	len = snprintf(buf, sizeof(buf), "%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
		       params[DCOC_REPORT_CHANNEL], params[DCOC_REPORT_BW],
		       params[DCOC_REPORT_CHAIN], params[DCOC_REPORT_BAND],
		       params[DCOC_REPORT_LNA], params[DCOC_REPORT_TEMPERATURE],
		       params[DCOC_REPORT_I_MV], params[DCOC_REPORT_I_ITERATIONS],
		       params[DCOC_REPORT_Q_MV], params[DCOC_REPORT_Q_ITERATIONS]);

	return cl_file_open_and_write(filename, O_WRONLY | O_APPEND, buf, len);
}

