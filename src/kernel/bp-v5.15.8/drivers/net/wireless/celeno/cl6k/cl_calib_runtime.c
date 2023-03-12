// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_calib_runtime.h"
#include "cl_calib_iq.h"
#include "cl_calib_common_api.h"
#include "cl_calib_common_db.h"
#include "cl_calib_dcoc.h"
#include "cl_band.h"
#include "cl_msg_tx.h"

static int _cl_calib_runtime_and_switch_channel(struct cl_hw *cl_hw, u32 channel, u8 bw,
						u16 primary, u16 center,
						struct cl_calib_params *calib_params)
{
	struct cl_calib_iq_plan *calib_iq_plan = NULL;
	s8 sx_freq_offset_mhz_TBD = 0;
	int ret = 0;
	u8 chan_idx = cl_calib_dcoc_channel_bw_to_idx(cl_hw, channel, bw);
	struct list_head *plan = &cl_hw->calib_db->plan[chan_idx][bw];

	cl_hw->calib_runtime_needed = false;
	cl_hw->calib_iq_plan = NULL;

	/*
	 * Calibration in case of the ci_calib_iq_plan_en is enable, the a calib iq plan file
	 * exist and there is relevant data for this current <channel,bw> pair, than, the channel
	 * will calibrate do according the calib iq plan file.
	 */
	if (cl_hw->calib_db->file_flags.iq_plan && !list_empty(plan)) {
		list_for_each_entry(calib_iq_plan, plan, list) {
			cl_hw->calib_iq_plan = calib_iq_plan;

			if (cl_msg_tx_set_calib(cl_hw, primary, center,
						calib_params)) {
				cl_dbg_chip_err(cl_hw, "Failed to calibrate channel %u, bw %u\n",
						channel, bw);
				ret = -1;
				break;
			}
		}
	} else {
		/* Calibration by the default values */
		if (cl_msg_tx_set_calib(cl_hw, primary, center, calib_params)) {
			cl_dbg_chip_err(cl_hw, "Failed to calibrate channel %u, bw %u\n",
					channel, bw);
			ret = -1;
		}
	}

	/* Set channel to load the new calib data */
	ret += cl_msg_tx_set_channel(cl_hw, channel, bw, primary, center, sx_freq_offset_mhz_TBD);

	return ret;
}

static bool cl_calib_runtime_is_channel_calibrated(struct cl_hw *cl_hw, u8 channel, u8 bw)
{
	int chain, lna;
	u8 chan_idx = cl_calib_dcoc_channel_bw_to_idx(cl_hw, channel, bw);
	u8 band_idx = cl_band_to_fw_idx(cl_hw);
	struct cl_calib_db *db = cl_hw->calib_db;

	riu_chain_for_each(chain) {
		if (!db->iq_tx[band_idx][chan_idx][bw][chain].gain &&
		    !db->iq_tx[band_idx][chan_idx][bw][chain].coef0 &&
		    !db->iq_tx[band_idx][chan_idx][bw][chain].coef1 &&
		    !db->iq_tx[band_idx][chan_idx][bw][chain].coef2) {
			cl_dbg_trace(cl_hw, "IQ TX calibration data is missing\n");
			return false;
		}

		if (!db->iq_rx[band_idx][chan_idx][bw][chain].gain &&
		    !db->iq_rx[band_idx][chan_idx][bw][chain].coef0 &&
		    !db->iq_rx[band_idx][chan_idx][bw][chain].coef1 &&
		    !db->iq_rx[band_idx][chan_idx][bw][chain].coef2) {
			cl_dbg_trace(cl_hw, "IQ RX calibration data is missing\n");
			return false;
		}

		if (!db->iq_tx_lolc[band_idx][chan_idx][bw][chain]) {
			cl_dbg_trace(cl_hw, "LOLC calibration data is missing\n");
			return false;
		}
	}

	for (lna = 0; lna < DCOC_LNA_GAIN_NUM; lna++) {
		riu_chain_for_each(chain) {
			if (!db->wifi_dcoc[band_idx][chan_idx][bw][chain][lna].i &&
			    !db->wifi_dcoc[band_idx][chan_idx][bw][chain][lna].q) {
				cl_dbg_trace(cl_hw, "DCOC calibration data is missing\n");
				return false;
			}
		}
	}

	/* If all the calibration data of channel exist */
	return true;
}

void cl_calib_runtime_create_calib_files(struct cl_hw *cl_hw)
{
	cl_calib_dcoc_write_version(cl_hw);
	cl_calib_bt_dcoc_write_version(cl_hw);
	cl_calib_dcoc_report_write_version(cl_hw);
	cl_calib_bt_dcoc_report_write_version(cl_hw);
	cl_calib_iq_rx_gain_report_write_version(cl_hw);
	cl_calib_iq_tx_write_version(cl_hw);
	cl_calib_iq_tx_report_write_version(cl_hw);
	cl_calib_iq_rx_write_version(cl_hw);
	cl_calib_iq_rx_report_write_version(cl_hw);
	cl_calib_iq_lolc_write_version(cl_hw);
	cl_calib_iq_lolc_report_write_version(cl_hw);
}

int cl_calib_runtime_and_switch_channel(struct cl_hw *cl_hw, u32 channel, u8 bw, u32 primary,
					u32 center)
{
	s8 sx_freq_offset_mhz_TBD = 0;
	struct cl_calib_params *calib_params = &cl_hw->calib_params;

	int ret = 0;
	bool calib_needed = (cl_hw->chip->conf->ci_calib_runtime_force ||
			     !cl_calib_runtime_is_channel_calibrated(cl_hw, channel, bw)) &&
			    !cl_hw->sw_scan_in_progress;

	cl_calib_params_fill(calib_params,
			     0,
			     0,
			     cl_hw->conf->ci_band_num,
			     channel,
			     bw,
			     false,
			     SX_FREQ_OFFSET_Q2,
			     0,
			     0,
			     false,
			     0,
			     true);

	if (!calib_needed) {
		/* Switch channel without calibration */
		ret = cl_msg_tx_set_channel(cl_hw,
					    channel,
					    bw,
					    primary,
					    center,
					    sx_freq_offset_mhz_TBD);
		return ret;
	}

	ret = _cl_calib_runtime_and_switch_channel(cl_hw,
						   channel,
						   bw,
						   primary,
						   center,
						   calib_params);
	return ret;
}
