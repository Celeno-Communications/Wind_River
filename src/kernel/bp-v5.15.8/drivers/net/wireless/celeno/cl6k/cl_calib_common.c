// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_calib_common_db.h"
#include "cl_calib_common_api.h"
#include "cl_calib_dcoc.h"
#include "cl_calib_iq.h"
#include "cl_utils.h"
#include "file.h"
#include "chip.h"
#include "cl_chandef.h"
#include "cl_temperature.h"
#include "cl_msg_tx.h"
#include "cl_band.h"
#include "cl_config.h"
#include "chip_ops.h"

#define FILE_ERROR_CALIB "# Error: TCV = %u, Exceed threshold = %u\n"

#define WRONG_NUM_OF_PARAM 2

int cl_calib_db_alloc(struct cl_hw *cl_hw)
{
	cl_hw->calib_db = kzalloc(sizeof(*cl_hw->calib_db), GFP_KERNEL);

	if (!cl_hw->calib_db)
		return -ENOMEM;

	return 0;
}

void cl_calib_db_free(struct cl_hw *cl_hw)
{
	kfree(cl_hw->calib_db);
	cl_hw->calib_db = NULL;
}

static int cl_calib_common_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf,
		 PAGE_SIZE,
		 "calib usage:\n"
		 "-a : Write IQ-TX and LOLC registers to file\n"
		 "-b : Write IQ-RX registers to file\n"
		 "-c : Execute DSP Calib Request command\n"
			"[wifi_bt_sel : 0 WIFI | 1 BT]\n"
			"[wifi channel or BT RF channel index (0-79)\n"
			"[wifi channel BW : 0 - 20MHz | 1 - 40MHz  | 2- 80MHz  | 3 -80MHz_PLUS_80 ] or BT bw bitmap 0x1 - 1mhz | 0x2 2Mhz]\n"
			"[sx_freq_offset]\n"
			"[CalibModeBitmap: RX DCOC 0x01 | TX_LO 0x02 | RX GAIN 0x04 | TX_IQ 0x08 | RX_IQ 0X10 | RX_GAIN_DPD 0x20 | RX_IQ_DPD 0x40 | TX_IQ_DPD 0x80 | DPD 0x100]\n"
			"[ChainBitmap: CH0 0x01 | CH0 0x02]\n"
			"[DCOC SX: SX0  0x0 |SX1 0x01 | NO DCOC 0x02 ]\n"
		 "-d : Write LOLC Calibration data in to file "
			"[channel][bw][ant][sx][temp][tx_dc_i][tx_dc_q]\n"
		 "-e : Write LOLC calibration report to file "
			"[channel][bw][ant][sx][temp][i][q][iterations][quality]\n"
		 "-f : Write IQ parameters to file "
			"[direction][channel][bw][ant][sx][temperature]\n"
		 "-g : Set channel with both SXs [channel][bw][sx_freq_offset]\n"
		 "-i : Set channel [channel][bw][sx_freq_offset]"
			"[calib_mode: 4:IQ|8:LO|12:IQ+LO][plan_bitmap (RIU chains)]\n"
		 "-l : Load calibration data from file "
			"[0:DCOC|1:LOLC|2:IQ_TX|3:IQ_RX]\n"
		 "-q : Initiate full IQ calibration\n"
		 "-r : Write DCOC calibration report to file "
			"[channel][bw][ant][sx][lna][temp][i_mv][i_iter][q_mv][q_iter]\n"
		 "-s : Write DCOC calibration to file "
			"[channel][bw][ant][sx][lna][temp][i][q]\n"
		 "-t : RIU loopback config for debug [len]\n"
			"[riu_rx_chain][riu_tx_chain][bw]\n"
		 "-m : Execute Matlab Calib Request command\n"
			"[wifi_bt_sel : 0 WIFI | 1 BT]\n"
			"[wifi channel BW : 0 - 20MHz | 1 - 40MHz  | 2- 80MHz  | 3 -80MHz_PLUS_80 ] or  BT RF channel index (0-79)\n"
			"[bw]\n"
			"[sx_freq_offset]\n"
			"[CalibModeBitmap: RX DCOC 0x01 | TX_LO 0x02 | RX GAIN 0x04 | TX_IQ 0x08 | RX_IQ 0X10 | RX_GAIN_DPD 0x20 | RX_IQ_DPD 0x40 | TX_IQ_DPD 0x80 | DPD 0x100]\n"
			"[ChainBitmap: CH0 0x01 | CH0 0x02]\n"
			"[DCOC SX: SX0  0x0 |SX1 0x01 | NO DCOC 0x02 ]\n"
		 "-p : Tx/Rx WIFI frame for DPD Matlab calibration\n"
			"[FrameType: Matlab_DPD_Frame][Frame_BW][MCS][TxChain_index]\n"
		 "-w : Calibrate current channel\n"
			"[0:DCOC | 1:IQ]\n"
		 "-o : Forwrd Matlab calib Response paramrters [len]\n"
		 "-j : Forwrd Matlab parameters [response type: 4:DCOC|5:LO|:6:IQ|7:GAIN]");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));

	return err;
}

static void cl_calib_common_handle_error(struct cl_chip *chip, enum calib_files_idx file_idx)
{
	if (file_idx == WIFI_DCOC_FILE)
		CL_DBG_ERROR_CHIP(chip, "Found errors on WIFI DCOC calibration file. Aborting.\n");
	else if (file_idx == BT_DCOC_FILE)
		CL_DBG_ERROR_CHIP(chip, "Found errors on BT DCOC calibration file. Aborting.\n");
	else if (file_idx == LOLC_FILE)
		CL_DBG_ERROR_CHIP(chip, "Found errors on LOLC calibration file. Aborting.\n");
	else if (file_idx == IQ_TX_FILE)
		CL_DBG_ERROR_CHIP(chip, "Found errors on IQ TX calibration file. Aborting.\n");
	else if (file_idx == IQ_RX_FILE)
		CL_DBG_ERROR_CHIP(chip, "Found errors on IQ RX calibration file. Aborting.\n");
	else if (file_idx == CALIB_IQ_PLAN)
		CL_DBG_ERROR_CHIP(chip,
				  "Found errors on CALIB IQ PLAN calibration file. Aborting.\n");
}

static int cl_calib_common_parse_from_buf(struct cl_chip *chip, char *buf, loff_t size,
					  void (*parse_func)(struct cl_chip *chip, char *str,
					  enum calib_files_idx file_idx),
					  enum calib_files_idx file_idx)
{
	char *line = buf;
	char str[MAX_CALIB_LINE_LENGTH];
	char *end;
	int line_length = 0;
	u8 tcv_idx = CL_INVALID_TCV_IDX;

	while (line && (line < (buf + size))) {
		if (*line >= '0' && *line <= '9') {
			end = strstr(line, "\n");

			if (end > line)
				line_length = end - line + 1;
			else
			/*
			 * In case the last line in file has no '\n' in the end
			 * of it, line_length need to be calculated in this way
			 */
				line_length = size - (line - buf) + 1;

			if (line_length >= MAX_CALIB_LINE_LENGTH) {
				cl_dbg_chip_err(chip, "Line too long (%u)\n", line_length);
				return -1;
			}

			snprintf(str, line_length, "%s", line);
			parse_func(chip, str, file_idx);
			line += line_length;
		} else {
			u8 ant_num;

			if (chip->conf->ci_calib_check_errors)
				if (strstr(line, "Error")) {
					cl_calib_common_handle_error(chip, file_idx);
					return -1;
				}
			if (sscanf(line, FILE_TCV_HEADER, &tcv_idx, &ant_num) == 2) {
				if (tcv_idx < TCV_MAX && cl_chip_is_tcv_enabled(chip, tcv_idx)) {
					if (file_idx == WIFI_DCOC_FILE) {
						chip->iq_dcoc_conf.dcoc_calib_needed =
							false;
						chip->iq_dcoc_conf.dcoc_file_num_ant =
							ant_num;
						cl_dbg_chip_verbose(chip, "DCOC: TCV = %u, "
								    "ant_num = %u\n",
								    tcv_idx, ant_num);
					} else if (file_idx == BT_DCOC_FILE) {
						chip->iq_dcoc_conf.bt_dcoc_calib_needed =
							false;
						chip->iq_dcoc_conf.bt_dcoc_file_num_ant =
							ant_num;
						cl_dbg_chip_verbose(chip, "BT DCOC: TCV = %u, "
								    "ant_num = %u\n",
								    tcv_idx, ant_num);
					}  else {
						chip->iq_dcoc_conf.iq_calib_needed = false;
						chip->iq_dcoc_conf.iq_file_num_ant =
							ant_num;
						cl_dbg_chip_verbose(chip, "IQ: TCV = %u, "
								    "ant_num = %u\n",
								    tcv_idx, ant_num);
					}
				}
			} else
				if (sscanf(line, FILE_TCV_FOOTER, &tcv_idx, &ant_num) == 2)
					tcv_idx = CL_INVALID_TCV_IDX;

			/* Skip lines that do not start with a frequency */
			line = strstr(line, "\n") + 1;
		}
	}

	return 0;
}

static void cl_calib_common_init_cfm(struct cl_iq_dcoc_data *iq_dcoc_data)
{
	int i;

	for (i = 0; i < CALIB_CFM_MAX; i++)
		iq_dcoc_data->dcoc_iq_cfm[i].status = CALIB_FAIL;
}

static int cl_calib_common_read_file(struct cl_chip *chip, enum calib_files_idx file_idx)
{
	struct cl_calib_file_flags *calib_file_flags = &chip->cl_hw_tcv0->calib_db->file_flags;
	char *buf = NULL;
	loff_t size = 0;
	char filename[CL_FILENAME_MAX] = {0};
	void (*parse_func)(struct cl_chip *chip, char *str, enum calib_files_idx file_idx) = NULL;
	int ret = 0;

	switch (file_idx) {
	case CALIB_IQ_PLAN:
		snprintf(filename, sizeof(filename), "%s%u.dat", FILE_PREFIX_CALIB_IQ_PLAN,
			 chip->idx);
		parse_func = cl_calib_iq_plan_parse_str;
		size = cl_file_open_and_read(chip, filename, &buf);

		if (size) {
			calib_file_flags->iq_plan = true;
		} else {
			cl_dbg_chip_err(chip, "ERROR! Failed reading: 'cl_calib_iq_plan_chip'\n");
			calib_file_flags->iq_plan = false;

			goto out_close;
		}
		break;
	case WIFI_DCOC_FILE:
		snprintf(filename, sizeof(filename), "%s%u.txt", FILE_PREFIX_DCOC, chip->idx);
		parse_func = cl_calib_dcoc_parse_str;
		size = cl_file_open_and_read(chip, filename, &buf);

		if (size) {
			calib_file_flags->dcoc = CALIB_FLAG_HEADER_TCV0;
			calib_file_flags->dcoc_report = 0;

			if (cl_calib_dcoc_post_read_actions(chip, buf))
				goto out_close;
		} else {
			calib_file_flags->dcoc = CALIB_FLAG_ALL;
			calib_file_flags->dcoc_report = CALIB_FLAG_ALL_REPORT;
			chip->iq_dcoc_conf.dcoc_calib_needed = true;

			goto out_close;
		}
		break;
	case BT_DCOC_FILE:
		snprintf(filename, sizeof(filename), "%s%u.txt", FILE_PREFIX_BT_DCOC, chip->idx);
		parse_func = cl_calib_bt_dcoc_parse_str;
		size = cl_file_open_and_read(chip, filename, &buf);

		if (size) {
			calib_file_flags->bt_dcoc = CALIB_FLAG_HEADER_TCV0;
			calib_file_flags->bt_dcoc_report = 0;
		} else {
			calib_file_flags->bt_dcoc = CALIB_FLAG_ALL;
			calib_file_flags->bt_dcoc_report = CALIB_FLAG_ALL_REPORT;

			goto out_close;
		}
		break;
	case LOLC_FILE:
		snprintf(filename, sizeof(filename), "%s%u.txt", FILE_PREFIX_LOLC, chip->idx);
		parse_func = cl_calib_iq_lolc_parse_str;
		size = cl_file_open_and_read(chip, filename, &buf);

		if (size) {
			cl_calib_iq_file_flags_clear(chip);

			if (cl_calib_iq_post_read_actions(chip, buf))
				goto out_close;
		} else {
			chip->iq_dcoc_conf.iq_calib_needed = true;
			chip->iq_dcoc_conf.iq_calib_mode_bmp = chip->conf->ci_calib_iq_mode_bitmap;
			cl_calib_iq_file_flags_set(chip);

			goto out_close;
		}
		break;
	case IQ_TX_FILE:
		snprintf(filename, sizeof(filename), "%s%u.txt", FILE_PREFIX_IQ_TX, chip->idx);
		parse_func = cl_calib_iq_parse_str;
		size = cl_file_open_and_read(chip, filename, &buf);
		calib_file_flags->iq_tx = size ? 0 : CALIB_FLAG_ALL;

		if (size) {
			calib_file_flags->iq_tx = CALIB_FLAG_HEADER_TCV0;
			calib_file_flags->iq_tx_report = 0;

			if (cl_calib_iq_post_read_actions(chip, buf))
				goto out_close;
		} else {
			calib_file_flags->iq_tx = CALIB_FLAG_ALL;
			calib_file_flags->iq_tx_report = CALIB_FLAG_ALL_REPORT;

			goto out_close;
		}
		break;
	case IQ_RX_FILE:
		snprintf(filename, sizeof(filename), "%s%u.txt", FILE_PREFIX_IQ_RX, chip->idx);
		parse_func = cl_calib_iq_parse_str;
		size = cl_file_open_and_read(chip, filename, &buf);
		calib_file_flags->iq_rx = size ? 0 : CALIB_FLAG_ALL;

		if (size) {
			calib_file_flags->iq_rx = CALIB_FLAG_HEADER_TCV0;
			calib_file_flags->iq_rx_report = 0;

			if (cl_calib_iq_post_read_actions(chip, buf))
				goto out_close;
		} else {
			calib_file_flags->iq_rx = CALIB_FLAG_ALL;
			calib_file_flags->iq_rx_report = CALIB_FLAG_ALL_REPORT;

			goto out_close;
		}
		/* Need to add post calib file read actions, when TX IQ Calibration is enabled */
		break;
	default:
		return -1;
	}

	if (size) {
		cl_dbg_chip_verbose(chip, "parsing %s\n", filename);
		ret = cl_calib_common_parse_from_buf(chip, buf, size, parse_func, file_idx);
	}

out_close:
	kfree(buf);
	return ret;
}

static int cl_calib_common_init_and_set_channel(struct cl_hw *cl_hw, u32 channel, u8 bw,
						s8 sx_freq_offset)
{
	u32 primary = 0, center = 0;
	enum nl80211_chan_width width = NL80211_CHAN_WIDTH_20;
	s8 sx_freq_offset_mhz_TBD = 0;

	if (cl_chandef_calc(cl_hw, channel, bw, &width, &primary, &center)) {
		cl_dbg_info(cl_hw, "cl_chandef_calc failed\n");
		return -EINVAL;
	}

	cl_msg_tx_set_channel(cl_hw, channel, bw, primary, center, sx_freq_offset_mhz_TBD);
	return 0;
}

static int cl_calib_common_set_channel(struct cl_hw *cl_hw, u32 channel, u8 bw, s8 sx_freq_offset,
				       u32 plan_bitmap)
{

	u32 primary = 0, center = 0;
	enum nl80211_chan_width width = NL80211_CHAN_WIDTH_20;
	s8 sx_freq_offset_mhz_TBD = 0;
	u8 max_bw = cl_band_is_24g(cl_hw) ? CHNL_BW_40 : CHNL_BW_160;

	if (bw > max_bw) {
		cl_dbg_err(cl_hw, "bw [%u] exceeds maximum allowed bw [%u]\n", bw, max_bw);
		return -1;
	}

	if (cl_chandef_calc(cl_hw, channel, bw, &width, &primary, &center)) {
		cl_dbg_err(cl_hw, "cl_chandef_calc failed\n");
		return -EINVAL;
	}

	cl_msg_tx_set_channel(cl_hw, channel, bw, primary, center, sx_freq_offset_mhz_TBD);
	cl_dbg_info(cl_hw, "channel = %u, bw = %u, sx_freq_offset = %d, primary = %u, "
		    "center = %u\n", channel, bw, sx_freq_offset, primary, center);
	return 0;
}

void cl_calib_params_fill(struct cl_calib_params *params,
			  u8 wifi_mode_bitmap,
			  u8 bt_mode_bitmap,
			  u8 band,
			  u8 channel,
			  u8 wifi_bw,
			  bool first_channel,
			  s8 sx_freq_off,
			  u8 wifi_chain_bitmap,
			  u8 dcoc_sx_bmp,
			  bool is_matlab,
			  u8 bt_bw_bitmap,
			  bool is_sys_flow)
{
	params->wifi_mode_bmp = wifi_mode_bitmap;
	params->bt_mode_bmp = bt_mode_bitmap;
	params->band = band;
	params->channel = channel;
	params->wifi_bw = wifi_bw;
	params->first_channel = first_channel;
	params->sx_freq_offset_mhz = sx_freq_off;
	params->wifi_chain_bmp = wifi_chain_bitmap;
	params->dcoc_sx_bmp = dcoc_sx_bmp;
	params->is_matlab = is_matlab;
	params->bt_bw_bmp = bt_bw_bitmap;
	params->is_sys_flow = is_sys_flow;
}

static int cl_calib_common_set_calib_wifi(struct cl_hw *cl_hw, u8 channel,
					  u8 bw, s8 sx_freq_offset, u8 calib_mode_bitmap,
					  u8 chain_bitmap, u8 dcoc_sx_bitmap, bool is_matlab)
{
	//iwcl wlan0_0 cecli calib -m.1.1.4.1.2.2
	/*
	 * "-m /-c: Execute Matlab Calib Request command\n"
	 * "[wifi channel] [bw] [sx_freq_offset]\n"
	 * "[CalibModeBitmap: RX DCOC 0x01 | 0x02 | RX GAIN 0x04 | TX_IQ 0x08 |
	 * RX_IQ 0X10 | RX_GAIN_DPD 0x20 | RX_IQ_DPD 0x40
	 * | TX_IQ_DPD 0x80 | DPD 0x100]\n"
	 * "[ChainBitmap] [DCOC SX: SX0  0x0 |SX1 0x01 | NO DCOC 0x02 ]\n"
	 */

	/* Manual iw cmd calibration, rewrite all files */
	cl_hw->calib_db->file_flags.dcoc = CALIB_FLAG_ALL;
	cl_hw->calib_db->file_flags.dcoc_report = CALIB_FLAG_ALL_REPORT;
	cl_hw->calib_db->file_flags.lolc = CALIB_FLAG_ALL;
	cl_hw->calib_db->file_flags.lolc_report = CALIB_FLAG_ALL_REPORT;
	cl_hw->calib_db->file_flags.iq_rx = CALIB_FLAG_ALL;
	cl_hw->calib_db->file_flags.iq_rx_report = CALIB_FLAG_ALL_REPORT;
	cl_hw->calib_db->file_flags.iq_tx = CALIB_FLAG_ALL;
	cl_hw->calib_db->file_flags.iq_tx_report = CALIB_FLAG_ALL_REPORT;
	cl_hw->calib_db->file_flags.rx_gain_report = CALIB_FLAG_ALL_REPORT;

	u32 primary = 0, center = 0;
	enum nl80211_chan_width width = NL80211_CHAN_WIDTH_20;
	u8 max_bw = cl_band_is_24g(cl_hw) ? CHNL_BW_40 : CHNL_BW_160;

	cl_calib_params_fill(&cl_hw->calib_params,
			     calib_mode_bitmap,
			     0,
			     cl_hw->conf->ci_band_num,
			     channel,
			     bw,
			     false,
			     sx_freq_offset,
			     chain_bitmap,
			     dcoc_sx_bitmap,
			     is_matlab,
			     0,
			     false);

	if (!(calib_mode_bitmap & SET_CALIB_MODE)) {
		cl_dbg_err(cl_hw, "Only supported WIFI Calibration types are DCOC - %u,TX LO - %u, RX GAIN - %u, TX_IQ - %u, RX_IQ - %u, RX_GAIN_DPD - %u, RX_IQ_DPD - %u, TX_IQ_DPD - %u\n",
			   WIFI_CALIB_MODE_RX_DCOC,
			   WIFI_CALIB_MODE_TX_LO,
			   WIFI_CALIB_MODE_RX_GAIN,
			   WIFI_CALIB_MODE_TX_IQ,
			   WIFI_CALIB_MODE_RX_IQ,
			   WIFI_CALIB_MODE_RX_GAIN_DPD,
			   WIFI_CALIB_MODE_RX_IQ_DPD,
			   WIFI_CALIB_MODE_TX_IQ_DPD);
		return -1;
	}

	if (bw > max_bw) {
		cl_dbg_err(cl_hw, "bw [%u] exceeds maximum allowed bw [%u]\n", bw, max_bw);
		return -1;
	}

//the primary and the center is been calculated using the channel and BW
	if (cl_chandef_calc(cl_hw, channel, bw, &width, &primary, &center)) {
		cl_dbg_err(cl_hw, "cl_chandef_calc failed\n");
		return -EINVAL;
	}

	cl_msg_tx_set_calib(cl_hw, primary, center, &cl_hw->calib_params);
	cl_hw->chip->is_calib_in_progress = false;

	return 0;
}

static int cl_calib_common_set_calib_bt(struct cl_hw *cl_hw, u8 channel,
					u8 bw, s8 sx_freq_offset,
					u8 calib_mode_bitmap, bool is_matlab)
{
	/*
	 * "-m : Execute Matlab Calib Request command\n"
	 * "[wifi channel] [bw] [sx_freq_offset]\n"
	 * "[CalibModeBitmap: RX DCOC 0x01 |   0x02 | RX GAIN 0x04 |
	 * TX_IQ 0x08 | RX_IQ 0X10 | RX_GAIN_DPD 0x20 | RX_IQ_DPD 0x40
	 * | TX_IQ_DPD 0x80 | DPD 0x100]\n"
	 * "[ChainBitmap] [DCOC SX: SX0  0x0 |SX1 0x01 | NO DCOC 0x02 ]\n"
	 */

	/* Manual iw cmd calibration, rewrite all files */
	cl_hw->calib_db->file_flags.bt_dcoc = CALIB_FLAG_ALL;
	cl_hw->calib_db->file_flags.bt_dcoc_report = CALIB_FLAG_ALL_REPORT;

	u32 primary = 2402, center = 2402;

	cl_calib_params_fill(&cl_hw->calib_params,
			     0,
			     calib_mode_bitmap,
			     channel,
			     BAND_24G,
			     0,
			     false,
			     sx_freq_offset,
			     0,
			     0,
			     is_matlab,
			     bw,
			     false);

	if (!(calib_mode_bitmap & SET_CALIB_MODE_BT)) {
		cl_dbg_err(cl_hw, "Only supported BT Calibration types are DCOC - %u,TX LO - %u, TX GAIN - %u, TX_IQ - %u, RX_IQ - %u\n",
			   BT_CALIB_MODE_RX_DCOC,
			   BT_CALIB_MODE_TX_LO,
			   BT_CALIB_MODE_RX_GAIN,
			   BT_CALIB_MODE_TX_IQ,
			   BT_CALIB_MODE_RX_IQ);
		return -1;
	}

	cl_msg_tx_set_calib(cl_hw, primary, center, &cl_hw->calib_params);

	return 0;
}

int cl_calib_common_write_error(struct cl_hw *cl_hw, char *file_prefix, u16 num_errors)
{
	char filename[CL_PATH_MAX];
	char buf[CALIB_MAX_BUF];
	int len = 0;

	snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt", cl_config_dir, file_prefix,
		 cl_hw->chip->idx);

	len = snprintf(buf, sizeof(buf), FILE_ERROR_CALIB, cl_hw->tcv_idx, num_errors);

	return cl_file_open_and_write(filename, O_WRONLY | O_APPEND, buf, len);
}

void cl_calib_common_fill_phy_data(struct cl_hw *cl_hw, struct cl_iq_dcoc_info *iq_dcoc_db,
				   u8 flags, bool is_calib)
{
	u8 bw = cl_hw->bw;
	u8 channel_idx = cl_calib_dcoc_channel_bw_to_idx(cl_hw, cl_hw->channel, bw);
	u8 band = cl_band_to_fw_idx(cl_hw);

	if (flags & SET_PHY_DATA_FLAGS_DCOC)
		cl_calib_dcoc_fill_data(cl_hw, iq_dcoc_db, is_calib);

	if (flags & SET_PHY_DATA_FLAGS_IQ_TX_LOLC)
		cl_calib_iq_lolc_fill_data(cl_hw, iq_dcoc_db->iq_tx_lolc, is_calib);

	if (flags & SET_PHY_DATA_FLAGS_IQ_TX)
		cl_calib_iq_fill_data(cl_hw, iq_dcoc_db->iq_tx,
				      cl_hw->calib_db->iq_tx[band][channel_idx][bw]);

	if (flags & SET_PHY_DATA_FLAGS_IQ_RX)
		cl_calib_iq_fill_data(cl_hw, iq_dcoc_db->iq_rx,
				      cl_hw->calib_db->iq_rx[band][channel_idx][bw]);
}

char *cl_calib_common_non_empty_strsep(char **str, const char *delims)
{
	char *token = NULL;

	while ((token = strsep(str, delims))) {
		if (*token != '\0')
			return token;
	}
	return token;
}

int cl_calib_common_tables_alloc(struct cl_hw *cl_hw)
{
	struct cl_iq_dcoc_data *buf = NULL;
	u32 len = sizeof(struct cl_iq_dcoc_data);
	dma_addr_t phys_dma_addr;

	buf = chip_ops_alloc_coherent(cl_hw->chip, len, GFP_KERNEL, &phys_dma_addr);

	if (!buf)
		return -1;

	cl_hw->iq_dcoc_data_info.iq_dcoc_data = buf;
	cl_hw->iq_dcoc_data_info.dma_addr = phys_dma_addr;

	cl_calib_common_init_cfm(cl_hw->iq_dcoc_data_info.iq_dcoc_data);

	return 0;
}

void cl_calib_common_tables_free(struct cl_hw *cl_hw)
{
	struct cl_iq_dcoc_data_info *iq_dcoc_data_info = &cl_hw->iq_dcoc_data_info;
	u32 len = sizeof(struct cl_iq_dcoc_data);
	dma_addr_t phys_dma_addr = iq_dcoc_data_info->dma_addr;

	if (!iq_dcoc_data_info->iq_dcoc_data)
		return;

	chip_ops_free_coherent(cl_hw->chip, len, (void *)iq_dcoc_data_info->iq_dcoc_data,
			       phys_dma_addr);
	iq_dcoc_data_info->iq_dcoc_data = NULL;
}

int cl_calib_common_read_files(struct cl_chip *chip)
{
	int ret = 0;

	if (!IS_REAL_PHY(chip))
		return ret;

	if (chip->conf->ci_calib_iq_plan_en)
		ret += cl_calib_common_read_file(chip, CALIB_IQ_PLAN);

	/*
	 * If runtime is enable, dont read DCOC, IQ, LO calib files.
	 * Must be after calib plan condition.
	 */
	if (chip->conf->ce_calib_runtime_en)
		return ret;

	ret += cl_calib_common_read_file(chip, WIFI_DCOC_FILE);
	ret += cl_calib_common_read_file(chip, BT_DCOC_FILE);
	ret += cl_calib_common_read_file(chip, LOLC_FILE);
	ret += cl_calib_common_read_file(chip, IQ_TX_FILE);
	ret += cl_calib_common_read_file(chip, IQ_RX_FILE);

	return ret;
}

int cl_calib_common_write_version(struct cl_hw *cl_hw, u8 *calib_flags, char *file_prefix,
				  char *title, u32 version_id)
{
	char filename[CL_PATH_MAX];
	char buf[CALIB_MAX_BUF];
	int flags = 0;
	int len = 0;

	if (*calib_flags == 0)
		return 0;

	if (*calib_flags & CALIB_FLAG_CREATE) {
		*calib_flags &= ~CALIB_FLAG_CREATE;
		flags = (O_WRONLY | O_CREAT | O_TRUNC);
	} else {
		flags = (O_WRONLY | O_APPEND);
	}

	if (*calib_flags & CALIB_FLAG_VERSION) {
		*calib_flags &= ~CALIB_FLAG_VERSION;
		len += snprintf(buf + len, sizeof(buf) - len, FILE_VERSION_ID, version_id);
	}

	if (*calib_flags & CALIB_FLAG_TITLE) {
		*calib_flags &= ~CALIB_FLAG_TITLE;
		len += snprintf(buf + len, sizeof(buf) - len, title);
	}

	if (*calib_flags & CALIB_FLAG_HEADER_TCV0) {
		*calib_flags &= ~CALIB_FLAG_HEADER_TCV0;
		len += snprintf(buf + len, sizeof(buf) - len, FILE_TCV_HEADER, TCV0,
				cl_hw->num_antennas);

		cl_calib_common_write_hr_factor(cl_hw, buf, &len, sizeof(buf));
	}

	if (len == 0)
		return 0;

	snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt", cl_config_dir, file_prefix,
		 cl_hw->chip->idx);
	return cl_file_open_and_write(filename, flags, buf, len);
}

s16 cl_calib_common_get_temperature(struct cl_hw *cl_hw, u8 cfm_type)
{
	struct calib_cfm *dcoc_iq_cfm =
		&cl_hw->iq_dcoc_data_info.iq_dcoc_data->dcoc_iq_cfm[cfm_type];
	u16 raw_bits = (le16_to_cpu(dcoc_iq_cfm->raw_bits_data_0) +
		le16_to_cpu(dcoc_iq_cfm->raw_bits_data_1)) / 2;

	return cl_temperature_calib_calc(cl_hw, raw_bits);
}

int cl_calib_common_handle_set_calib_cfm(struct cl_hw *cl_hw)
{
	struct cl_calib_params *calib_params = &cl_hw->calib_params;
	struct cl_iq_dcoc_data *iq_dcoc_data = cl_hw->iq_dcoc_data_info.iq_dcoc_data;
	u8 mode = calib_params->wifi_mode_bmp;
	u8 bt_mode = calib_params->bt_mode_bmp;
	cl_dbg_trace(cl_hw, "\n ------  FINISH CALIB CHANNEL  -----\n");

	/*
	 * In case any of the requested calibrations failed - no need to copy
	 * the other Calibration data, and fail the whole calibration process.
	 */
	if ((mode & WIFI_CALIB_MODE_RX_DCOC &&
	     iq_dcoc_data->dcoc_iq_cfm[CALIB_CFM_WIFI_DCOC].status != CALIB_SUCCESS) ||
	    (mode & SET_CALIB_MODE_IQ_ALL &&
	     iq_dcoc_data->dcoc_iq_cfm[CALIB_CFM_WIFI_IQ].status != CALIB_SUCCESS)) {
		cl_dbg_err(cl_hw, "Calibration failed! mode = %u, DCOC_CFM_STATUS = %u, "
			   "IQ_CFM_STATUS = %u\n", mode,
			   iq_dcoc_data->dcoc_iq_cfm[CALIB_CFM_WIFI_DCOC].status,
			   iq_dcoc_data->dcoc_iq_cfm[CALIB_CFM_WIFI_IQ].status);
		/* Set status to CALIB_FAIL to ensure that FW is writing the values. */
		iq_dcoc_data->dcoc_iq_cfm[CALIB_CFM_WIFI_DCOC].status = CALIB_FAIL;
		iq_dcoc_data->dcoc_iq_cfm[CALIB_CFM_WIFI_IQ].status = CALIB_FAIL;
		return -1;
	}

	if (mode & WIFI_CALIB_MODE_RX_DCOC)
		cl_calib_wifi_dcoc_handle_set_calib_cfm(cl_hw);

	if (mode & WIFI_CALIB_MODE_RX_GAIN)
		cl_calib_iq_rx_gain_write_report_file(cl_hw, calib_params);

	if (mode & WIFI_CALIB_MODE_TX_IQ) {
		if (calib_params->first_channel) {
			cl_calib_iq_tx_write_version(cl_hw);
			cl_calib_iq_tx_report_write_version(cl_hw);
		}
	}

	if (mode & WIFI_CALIB_MODE_RX_IQ) {
		if (calib_params->first_channel) {
			cl_calib_iq_rx_write_version(cl_hw);
			cl_calib_iq_rx_report_write_version(cl_hw);
		}
	}

	if (mode & SET_CALIB_MODE_IQ_ALL)
		cl_calib_iq_handle_set_calib_cfm(cl_hw, calib_params->wifi_chain_bmp);

	if (mode & WIFI_CALIB_MODE_TX_LO) {
		if (calib_params->first_channel) {
			cl_calib_iq_lolc_write_version(cl_hw);
			cl_calib_iq_lolc_report_write_version(cl_hw);
		}

		cl_calib_iq_lolc_handle_set_channel_cfm(cl_hw, calib_params->wifi_chain_bmp);
	}

	if (bt_mode & BT_CALIB_MODE_RX_DCOC)
		cl_calib_bt_dcoc_handle_set_calib_cfm(cl_hw);

#ifdef CL_EEPROM_STM24256
	if (cl_hw->chip->conf->ci_calib_eeprom_en && cl_hw->chip->conf->ce_production_mode &&
	    cl_hw->chip->is_calib_eeprom_loaded && cl_hw->chip->conf->ce_calib_runtime_en)
		if (cl_calib_common_is_channel_included_in_eeprom_bitmap(cl_hw))
			cl_calib_common_write_eeprom(cl_hw, cl_hw->channel, cl_hw->bw,
						     cl_hw->sx_idx, cl_hw->tcv_idx);
#endif

	return 0;
}

void cl_calib_common_remove_tcv_entries(struct cl_hw *cl_hw, enum calib_files_idx file_idx,
					u8 num_calib_ant)
{
	struct cl_chip *chip = cl_hw->chip;
	char tcv_header[CALIB_MAX_HEADER_FOOTER];
	char tcv_footer[CALIB_MAX_HEADER_FOOTER];
	char filename[CL_FILENAME_MAX] = {0};
	char path_name[CL_PATH_MAX] = {0};
	char *file_tmp = NULL;
	char *file_curr = NULL;
	size_t size = 0;
	char *line_src, *line_dst;
	char str[MAX_CALIB_LINE_LENGTH];
	char *end;
	int line_length = 0;
	bool skip_line = false;
	u8 tcv_idx = cl_hw->tcv_idx;
	int len = 0;

	snprintf(tcv_header, sizeof(tcv_header), FILE_TCV_HEADER, tcv_idx, num_calib_ant);
	snprintf(tcv_footer, sizeof(tcv_footer), FILE_TCV_FOOTER, tcv_idx, num_calib_ant);

	if (file_idx == WIFI_DCOC_FILE)
		snprintf(filename, sizeof(filename), "%s%u.txt", FILE_PREFIX_DCOC, chip->idx);
	else if (file_idx == LOLC_FILE)
		snprintf(filename, sizeof(filename), "%s%u.txt", FILE_PREFIX_LOLC, chip->idx);
	else if (file_idx == IQ_TX_FILE)
		snprintf(filename, sizeof(filename), "%s%u.txt", FILE_PREFIX_IQ_TX, chip->idx);
	else if (file_idx == IQ_RX_FILE)
		snprintf(filename, sizeof(filename), "%s%u.txt", FILE_PREFIX_IQ_RX, chip->idx);
	else
		return;

	size = cl_file_open_and_read(chip, filename, &file_curr);
	if (!file_curr)
		return;

	/* Allocate ALIGN(size + 1, 4) just like cl_file_open_and_read() does */
	file_tmp = kzalloc(ALIGN(size + 1, 4), GFP_KERNEL);
	if (!file_tmp)
		goto out_close;

	/* Line helpers for source and destination files. */
	line_src = file_curr;
	line_dst = file_tmp;

	while (line_src && (line_src != (file_curr + size))) {
		end = strchr(line_src, '\n');
		line_length = end - line_src + 1;

		if (line_length >= MAX_CALIB_LINE_LENGTH) {
			cl_dbg_err(cl_hw, "Line too long (%u)\n", line_length);
			goto out_close;
		}

		snprintf(str, line_length + 1, "%s", line_src);

		if (!strncmp(tcv_header, str, line_length)) {
			skip_line = true;
		} else if (!strncmp(tcv_footer, str, line_length)) {
			skip_line = false;
		} else if (!skip_line) {
			strncpy(line_dst, str, line_length);

			line_dst += line_length;
			len += line_length;
		}

		line_src += line_length;
	}

	/* Truncate file to zero, to enable rewriting the file. */
	snprintf(path_name, sizeof(path_name), "%s/calib/%s", cl_config_dir, filename);
	cl_file_open_and_write(path_name, O_WRONLY | O_TRUNC, file_tmp, len);

out_close:
	kfree(file_curr);
	kfree(file_tmp);
}

static int cl_calib_common_init_calibration_channel(struct cl_hw *cl_hw, u8 calib_type)
{
	if (calib_type == 0)
		return cl_calib_dcoc_init_calibration_channel(cl_hw);
	else if (calib_type == 1)
		return cl_calib_iq_init_calibration_channel(cl_hw);

	cl_dbg_err(cl_hw, "Invalid calib type [%u]. 0 - DCOC, 1 - IQ+LOLC\n", calib_type);
	return -EIO;
}

void cl_calib_common_write_hr_factor(struct cl_hw *cl_hw, char *buf, int *len, int size)
{
	char hr_factor[CALIB_MAX_HR_FACTOR_LEN];
	u8 hr_factor_len = 0;
	u8 i;

	for (i = 0; i < CHNL_BW_MAX; i++)
		hr_factor_len += snprintf(hr_factor + hr_factor_len,
					 sizeof(hr_factor) - hr_factor_len,
					 "%u ", cl_hw->conf->ci_hr_factor[i]);

	*len += snprintf(buf + *len, size - *len, FILE_HR_FACTOR, hr_factor);
}

static int cl_matlab_calib_res_read_file(struct cl_hw *cl_hw,
					 struct mm_matlab_calib_res *matlab_calib_res)
{
	char *buf = NULL;
	loff_t size = 0;
	char filename[CL_FILENAME_MAX] = {0};
	u8 lower_byte, higher_byte;
	u16 data_len;
	int res = 0;

	//Set Matlab calib param into file
	snprintf(filename, sizeof(filename), "%s", FILE_PREFIX_MATLAB_CALIB_RES);

	cl_dbg_err(cl_hw, "%s :%s chip %d\n", __func__, filename, cl_hw->chip->idx);

	size = cl_file_open_and_read(cl_hw->chip, filename, &buf);
	lower_byte = buf[MM_MATLAB_CALIB_RES_LEN_IDX];
	higher_byte = buf[MM_MATLAB_CALIB_RES_LEN_IDX + 1];
	data_len = (uint16_t)(((higher_byte & 0xF) << 8) | lower_byte);

	if (size) {
		memcpy((void *)(matlab_calib_res),
		       (void *)buf,
		       size);
		cl_dbg_chip_err(cl_hw->chip,
				"READ %lld bytes from Matlab calib file %s\n",
				size,
				filename);

		kfree(buf);
		res = 0;
	} else {
		cl_dbg_chip_err(cl_hw->chip, "ERROR! Failed reading: %s\n", filename);
		kfree(buf);
		res = -1;
	}

	return res;
}

/* Matlab call res function - when Matlab calib is done
 * and result should pass to the FW
 */
static int cl_calib_common_handle_matlab_calib_res(struct cl_hw *cl_hw, u16 len)
{
	struct mm_matlab_calib_res matlab_calib_res;
	int res = 0;

	/*-O : [Len][Data] */
	if (len == 0) {
		cl_dbg_err(cl_hw, "%s: Matlab calib data is empty%d\n", __func__, len);
		return -1;
	}

	/* read calib data into buffer and parse data */
	res = cl_matlab_calib_res_read_file(cl_hw, &matlab_calib_res);

	/* send matlab calib data to the FW */
	if (!res)
		res = cl_msg_tx_matlab_response(cl_hw, &matlab_calib_res);

	return res;
}

void cl_calib_cl_umh_matlab_call(struct cl_hw *cl_hw, char *matlab_input_file_name)
{
	char cfg_dir_env[CL_PATH_MAX];
	char install_dir_env[CL_PATH_MAX];
	char cmd[U8_MAX];
	char *matlab_pc_user_name = "Math.Amir";
	char matlab_pc_ip_addr_char_represent[ETH_IP_ADDR_CHAR_LEN];

	char *argv[4] = { "/bin/sh", "-c", cmd, NULL };
	char *envp[5] = { "HOME=/", "PATH=/home:/sbin:/bin:/usr/sbin:/usr/bin",
		cfg_dir_env, install_dir_env, NULL };

	snprintf(matlab_pc_ip_addr_char_represent,
		 ETH_IP_ADDR_CHAR_LEN,
		 "%u.%u.%u.%u",
		 cl_hw->chip->conf->ci_calib_matlab_ip[0],
		 cl_hw->chip->conf->ci_calib_matlab_ip[1],
		 cl_hw->chip->conf->ci_calib_matlab_ip[2],
		 cl_hw->chip->conf->ci_calib_matlab_ip[3]);

	snprintf(cmd, sizeof(cmd), "%s/%s %s %s %s> /dev/null 2>&1",
		 cl_install_dir,
		 MATLAB_UMH_SCRIPT,
		 matlab_pc_user_name,
		 matlab_pc_ip_addr_char_represent,
		 matlab_input_file_name);

	cl_dbg_verbose(cl_hw, "%s\n", cmd);

	call_usermodehelper(argv[0], argv, envp, UMH_NO_WAIT);
	/*
	 * DON'T REMOVE THIS LINE.
	 */
	cl_dbg_verbose(cl_hw, "\n");
}

void cl_calib_common_handle_matlab_calib_req(struct cl_hw *cl_hw, u16 file_len)
{

	/* Host receives from the FW, req for matlab calibration*/
	/* Host opens a file*/
	/* write the FW Calib request struct into file - matlab_calib_request_mac*/
	/* Struct contain the Board IP*/
	char filename[CL_FILENAME_MAX];
	char filepath[CL_PATH_MAX];
	unsigned char *start_ptr;
	struct cl_iq_dcoc_data *iq_dcoc_data = NULL;
	int res;

	if (!cl_hw->iq_dcoc_data_info.iq_dcoc_data) {
		cl_dbg_err(cl_hw, "%s: cl_hw->iq_dcoc_data_info.iq_dcoc_data is NULL\n", __func__);
	} else {
		iq_dcoc_data = cl_hw->iq_dcoc_data_info.iq_dcoc_data;
	}

	start_ptr = iq_dcoc_data->matlab_params.data;

	if (!start_ptr) {
		cl_dbg_err(cl_hw, "%s: padata error\n", __func__);
	}

	/* Set Matlab calib param into file */
	snprintf(filename, sizeof(filename), "%s.txt", FILE_PREFIX_MATLAB_CALIB_REQ);
	snprintf(filepath, sizeof(filepath), "/tmp/%s", filename);

	cl_dbg_info(cl_hw, "%s :%s chip %d\n", __func__, filepath, cl_hw->chip->idx);
	cl_dbg_info(cl_hw, "%s: Attend to write[%s] [%d]bytes\n ", __func__, start_ptr, file_len);
	cl_dbg_info(cl_hw, "%s: file name:[%s]\n", __func__, filename);
	cl_dbg_info(cl_hw, "%s: path:[%s]\n", __func__, filepath);

	res = cl_file_open_and_write(filepath,
				     O_WRONLY | O_CREAT | O_TRUNC,
				     start_ptr,
				     file_len);

	if (!res) {
		cl_dbg_verbose(cl_hw, "write [%d] bytes to Matlab file %s\n", res, filepath);
		cl_dbg_err(cl_hw, "%s : calling cl_calib_cl_umh_matlab_call\n", __func__);
		cl_calib_cl_umh_matlab_call(cl_hw, filename);
	} else {
		cl_dbg_err(cl_hw, "cl_file_open_and_write error[%d] in [%s]\n", res, filepath);
	}
}

static int cl_calib_dpd_request_msg(struct cl_hw *cl_hw, u8 resp_type)
{
	/*For test use only!!!!*/
	/*struct mm_dpd_calib_res matlab_calib_res;*/
	/*matlab_calib_res.data[2] = resp_type;*/
	/*return cl_msg_tx_matlab_response(cl_hw, &matlab_calib_res);*/
	return 1;
}

static int cl_calib_matlab_response_msg(struct cl_hw *cl_hw, u8 resp_type)
{
	/*For test use only!!!!*/
	struct mm_matlab_calib_res matlab_calib_res;

	matlab_calib_res.data[2] = resp_type;
	return cl_msg_tx_matlab_response(cl_hw, &matlab_calib_res);
}

static int cl_calib_msg(struct cl_hw *cl_hw, struct cli_params *cli_params, bool is_matlab)
{
	s32 *params = cli_params->params;

	if (cli_params->num_params != MATLAB_CALIB_REQ_PARAM_MAX) {
		cl_dbg_err(cl_hw, "params:%d : Platform[%u] Channel[%u] BW[%u] Offset[%d] CalibTypeBMP[%d] Chain[%d] SX[%d]\n",
			   cli_params->num_params,
			   (u8)params[0],//platform
			   (u8)params[1],//channel
			   (u8)params[2],//BW
			   (u8)params[3],//sx_freq_offset
			   (u8)params[4],//CalibModeBitmap
			   (u8)params[5],//chain bmp
			   (u8)params[6]);//DCOC SX bmp
		return WRONG_NUM_OF_PARAM;
	}

	if ((u8)params[0] >= CALIB_PLATFORM_MAX) {
		cl_dbg_err(cl_hw, "platform:%d: is out of range[0-1].\n",
			   (u8)params[0]);//platform
		cl_dbg_err(cl_hw, "Wrong argument value\n");
		return 0;
	}
	//matlab
	cl_dbg_err(cl_hw,
		   "params:%d : Platform[%u] Channel[%u]"
		   "BW[%u] Offset[%d] CalibTypeBMP[%d]"
		   "Chain[%d] SX[%d] Is Matlab?[%d]\n",
		   cli_params->num_params,
		   (u8)params[0],//platform 0/1
		   (u8)params[1],//channel
		   (u8)params[2],//BW
		   (u8)params[3],//sx_freq_offset
		   (u8)params[4],//CalibModeBitmap
		   (u8)params[5],//chain bmp
		   (u8)params[6],
		   is_matlab);//isMatlab = 1/DSP = 0

	if ((u8)params[0] == CALIB_PLATFORM_WIFI)
		cl_calib_common_set_calib_wifi(cl_hw,
					       (u8)params[1], /* channel */
					       (u8)params[2], /* bw */
					       (u8)params[3], /* sx_freq_offset */
					       (s8)params[4], /* calib_mode bitmap */
					       (u8)params[5], /* chain bmp */
					       (u8)params[6], /* DCOC SX bmp */
					       is_matlab);    /* is Matlab */
	else
		cl_calib_common_set_calib_bt(cl_hw,
					     (u8)params[1], /* channel */
					     (u8)params[2], /* bw */
					     (u8)params[3], /* sx_freq_offset */
					     (s8)params[4], /* calib_mode bitmap */
					     is_matlab);    /* is Matlab */

	return 0;
}

int cl_calib_common_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	s32 *params = cli_params->params;

	switch (cli_params->option) {
	case 'a':
		if (cli_params->num_params)
			goto err_num_of_arg;

		cl_calib_iq_tx_and_lolc_write_registers_to_file(cl_hw);
		return 0;
	case 'b':
		if (cli_params->num_params)
			goto err_num_of_arg;

		cl_calib_iq_write_registers_to_file(cl_hw, IQ_RX_FILE);
		return 0;
	case 'c':
		if (cl_calib_msg(cl_hw, cli_params, false) == WRONG_NUM_OF_PARAM)
			goto err_num_of_arg;
		return 0;
	case 'd':
		if (cli_params->num_params != LOLC_PARAM_MAX)
			goto err_num_of_arg;

		cl_calib_iq_lolc_write_file(cl_hw, params);
		return 0;
	case 'e':
		if (cli_params->num_params != LOLC_REPORT_PARAM_MAX)
			goto err_num_of_arg;

		cl_calib_iq_lolc_report_write_file(cl_hw, params);
		return 0;
	case 'f':
		if (cli_params->num_params != 6)
			goto err_num_of_arg;

		cl_calib_iq_write_single_line_to_file(cl_hw, (u8)params[0], (u16)params[1],
						      (u8)params[2], (u8)params[3], (u8)params[4],
						      (s16)params[5]);
		return 0;
	case 'g':
		if (cli_params->num_params != 3)
			goto err_num_of_arg;

		return cl_calib_common_init_and_set_channel(cl_hw, (u8)params[0], (u16)params[1],
							    (u8)params[2]);
	case 'i':
		if (cli_params->num_params != 5)
			goto err_num_of_arg;

		cl_calib_common_set_channel(cl_hw, (u32)params[0], (u8)params[1], (s8)params[2],
					    (u8)params[3]);
		return 0;
	case 'l':
		if (cli_params->num_params != 1)
			goto err_num_of_arg;

		cl_calib_common_read_file(cl_hw->chip, (enum calib_files_idx)params[0]);
		return 0;
	case 'q':
		cl_hw->chip->iq_dcoc_conf.force_calib = true;
		cl_calib_iq_file_flags_set(cl_hw->chip);
		cl_calib_iq_init_calibration(cl_hw);
		cl_hw->chip->iq_dcoc_conf.force_calib = false;
		return 0;
	case 'r':
		if (cli_params->num_params != DCOC_REPORT_PARAM_MAX)
			goto err_num_of_arg;

		cl_calib_dcoc_report_write_file(cl_hw, params);
		return 0;
	case 's':
		if (cli_params->num_params != DCOC_PARAM_MAX)
			goto err_num_of_arg;

		cl_calib_dcoc_write_file(cl_hw, params);
		return 0;
	case 'm':
		if (cl_calib_msg(cl_hw, cli_params, true) == WRONG_NUM_OF_PARAM)
			goto err_num_of_arg;
		return 0;
	case 'o':
		if (cli_params->num_params != MATLAB_CALIB_RES_PARAM_MAX) {
			cl_dbg_info(cl_hw,
				    "--->Matlab output params:%d : [%u]\n",
				    cli_params->num_params,
				    (u8)params[0]);

			goto err_num_of_arg;
		}
		/* Send matlab calib data - to the FW */
		return cl_calib_common_handle_matlab_calib_res(cl_hw, (u16)params[0]);
	case 'j':
		return cl_calib_matlab_response_msg(cl_hw, params[0]);
	case 'p':
		return cl_calib_dpd_request_msg(cl_hw, params[0]);
		/*	if (cli_params->num_params !=DPD_MATLAB_CALIB_REQ_PARAM_MAX) {*/
		/*	cl_dbg_info(cl_hw,"---> DPD Matlab calib request params:%d : [%u]\n",*/
		/*	cli_params->num_params,*/
		/*	(u8)params[0],//FrameType: Matlab_DPD_Frame*/
		/*	(u8)params[1],//Frame_BW*/
		/*	(u8)params[2],//MCS*/
		/*	(u8)params[3]);//TxChain_index*/
		/*	goto err_num_of_arg;}*/
	case 'w':
		/* calibrate current used channel (eq to everest '-c' flag) */
		if (cli_params->num_params != 1)
			goto err_num_of_arg;

		return cl_calib_common_init_calibration_channel(cl_hw, (u8)params[0]);
	case 't':
		/* calibration loopback configuration for tulip */
		if (cli_params->num_params != 3)
			goto err_num_of_arg;

		if (params[0] >= MAX_ANTENNAS) {
			cl_dbg_err(cl_hw, "rx_chain is out of range [0-1]=%d\n", params[0]);
			return 0;
		}

		if (params[1] >= MAX_ANTENNAS) {
			cl_dbg_err(cl_hw, "tx_chain is out of range [0-1]=%d\n", params[0]);
			return 0;
		}

		return cl_msg_tx_riu_loopback_config(cl_hw, (u8)params[0], (u8)params[1],
						     (u8)params[2]);
	case '?':
		return cl_calib_common_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n",
			   cli_params->option);
		return 0;
	}

err_num_of_arg:
	cl_dbg_err(cl_hw, "Wrong number of arguments\n");
	return 0;
}
