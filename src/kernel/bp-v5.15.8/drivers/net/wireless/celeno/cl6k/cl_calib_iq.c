// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd.*/

#include "cl_calib_common_db.h"
#include "cl_calib_common_api.h"
#include "cl_calib_iq.h"
#include "cl_calib_dcoc.h"
#include "cl_utils.h"
#include "cl_temperature.h"
#include "file.h"
#include "cl_chandef.h"
#include "cl_band.h"
#include "cl_config.h"
#include "cl_rfic.h"
#include "cl_msg_tx.h"
#include "reg_riu.h"

#define VERSION_ID_IQ 2

#define S12_S_BIT (0x00000800)
#define CAST_S12_TO_S32(i) ((~(i) & S12_S_BIT) ? (i) : ((i) | ~RIU_IQDC_TX_0_DC_IQDC_TX_0_DCI_MASK))

#define OTHER_RIU_CHAIN(_chain) (1 - (_chain))

struct cl_calib_iq_params {
	u16 channel;
	u8 bw;
	u8 chain;
	u8 band;
	s16 temperature;
	u32 coef0;
	u32 coef1;
	u32 coef2;
	u32 gain;
	u32 tx_dc;
	u8 loop_idx;
	s8 tone_vector[IQ_NUM_TONES_CFM];
	s8 tone_vector_avg;
};

static int cl_calib_iq_write_footer(struct cl_hw *cl_hw, enum calib_files_idx file_idx)
{
	char filename[CL_PATH_MAX];
	char buf[CALIB_MAX_BUF];
	int len;

	if (file_idx == LOLC_FILE)
		snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt", cl_config_dir,
			 FILE_PREFIX_LOLC, cl_hw->chip->idx);
	else if (file_idx == IQ_TX_FILE)
		snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt", cl_config_dir,
			 FILE_PREFIX_IQ_TX, cl_hw->chip->idx);
	else if (file_idx == IQ_RX_FILE)
		snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt",
			 cl_config_dir, FILE_PREFIX_IQ_RX, cl_hw->chip->idx);

	len = snprintf(buf, sizeof(buf), FILE_TCV_FOOTER, cl_hw->tcv_idx,
		       cl_hw->num_antennas);

	return cl_file_open_and_write(filename, O_WRONLY | O_APPEND, buf, len);
}

static int cl_calib_iq_rx_gain_write_line(struct cl_hw *cl_hw, u32 channel, u8 bw, u8 ant_tx,
					  u8 ant_rx, u16 init_rx_gain, u8 tx_gain, u16 init_p2p,
					  u16 final_rx_gain, u16 final_p2p)
{
	char filename[CL_PATH_MAX];
	char buf[CALIB_MAX_BUF];
	int len = 0;

	snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt", cl_config_dir,
		 FILE_PREFIX_RX_GAIN_REPORT, cl_hw->chip->idx);

	len = snprintf(buf, sizeof(buf), "%u,\t\t%u,\t\t%u,\t\t%u,\t\t0x%03X,\t\t0x%02X,\t\t%u,"
		       "\t\t0x%03X,\t\t%u\n",
		       channel, bw, ant_tx, ant_rx, init_rx_gain, tx_gain, init_p2p, final_rx_gain,
		       final_p2p);

	return cl_file_open_and_write(filename, O_WRONLY | O_APPEND, buf, len);
}

static int cl_calib_iq_write_file(struct cl_hw *cl_hw, char *file_prefix,
				  struct cl_calib_iq_params *iq_params)
{
	char filename[CL_PATH_MAX];
	char buf[CALIB_MAX_BUF];
	int len = 0;
	u8 tone = 0;

	snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt", cl_config_dir, file_prefix,
		 cl_hw->chip->idx);

	if (!strcmp(file_prefix, FILE_PREFIX_LOLC)) {
		s32 tx_dc_i =
			CAST_S12_TO_S32(iq_params->tx_dc & RIU_IQDC_TX_0_DC_IQDC_TX_0_DCI_MASK);
		s32 tx_dc_q =
			CAST_S12_TO_S32((iq_params->tx_dc & RIU_IQDC_TX_0_DC_IQDC_TX_0_DCQ_MASK) >>
					RIU_IQDC_TX_0_DC_IQDC_TX_0_DCQ_LSB);

		len = snprintf(buf, sizeof(buf), "%u\t\t%u\t%u\t%u\t%d\t%d\t%d\n",
			       iq_params->channel, iq_params->bw, iq_params->chain, iq_params->band,
			       iq_params->temperature, tx_dc_i, tx_dc_q);

		if (cl_hw->calib_db->file_flags.lolc)
			cl_calib_iq_lolc_write_version(cl_hw);
	} else if (!strcmp(file_prefix, FILE_PREFIX_IQ_TX)) {
		len = snprintf(buf, sizeof(buf), "%u\t\t%u\t%u\t%u\t%d\t0x%08X\t0x%08X\t0x%08X"
			       "\t0x%08X\n",
			       iq_params->channel, iq_params->bw, iq_params->chain, iq_params->band,
			       iq_params->temperature, iq_params->coef0, iq_params->coef1,
			       iq_params->coef2, iq_params->gain);

		if (cl_hw->calib_db->file_flags.iq_tx)
			cl_calib_iq_tx_write_version(cl_hw);
	} else if (!strcmp(file_prefix, FILE_PREFIX_IQ_RX)) {
		len = snprintf(buf, sizeof(buf), "%u\t\t%u\t%u\t%u\t%d\t0x%08X\t0x%08X\t0x%08X"
			       "\t0x%08X\n",
			       iq_params->channel, iq_params->bw, iq_params->chain, iq_params->band,
			       iq_params->temperature, iq_params->coef0, iq_params->coef1,
			       iq_params->coef2, iq_params->gain);

		if (cl_hw->calib_db->file_flags.iq_rx)
			cl_calib_iq_rx_write_version(cl_hw);
	} else if (!strcmp(file_prefix, FILE_PREFIX_IQ_TX_REPORT)) {
		if (iq_params->loop_idx == IQ_PRE_IDX)
			len += snprintf(buf + len, sizeof(buf) - len, "tx_pre,");
		else if (iq_params->loop_idx == IQ_POST_IDX)
			len += snprintf(buf + len, sizeof(buf) - len, "tx_post,");
		else
			len += snprintf(buf + len, sizeof(buf) - len, "tx_singleton,");

		len += snprintf(buf + len, sizeof(buf) - len, "%u,%u,%u,%u,%d",
				iq_params->channel, iq_params->bw, iq_params->chain,
				iq_params->band, iq_params->temperature);

		for (tone = 0; tone < IQ_NUM_TONES_CFM; tone++)
			len += snprintf(buf + len, sizeof(buf) - len, ",%d",
					iq_params->tone_vector[tone]);

		if (iq_params->loop_idx == IQ_POST_IDX)
			len += snprintf(buf + len, sizeof(buf) - len, ",%d\n",
					iq_params->tone_vector_avg);
		else
			len += snprintf(buf + len, sizeof(buf) - len, ",NA-\n");

		if (cl_hw->calib_db->file_flags.iq_tx_report)
			cl_calib_iq_tx_write_version(cl_hw);
	} else if (!strcmp(file_prefix, FILE_PREFIX_IQ_RX_REPORT)) {
		if (iq_params->loop_idx == IQ_PRE_IDX)
			len += snprintf(buf + len, sizeof(buf) - len, "rx_pre,");
		else if (iq_params->loop_idx == IQ_POST_IDX)
			len += snprintf(buf + len, sizeof(buf) - len, "rx_post,");
		else
			len += snprintf(buf + len, sizeof(buf) - len, "rx_singleton,");

		len += snprintf(buf + len, sizeof(buf) - len, "%u,%u,%u,%u,%d",
				iq_params->channel, iq_params->bw, iq_params->chain,
				iq_params->band, iq_params->temperature);

		for (tone = 0; tone < IQ_NUM_TONES_CFM; tone++)
			len += snprintf(buf + len, sizeof(buf) - len, ",%d",
					iq_params->tone_vector[tone]);

		if (iq_params->loop_idx == IQ_POST_IDX)
			len += snprintf(buf + len, sizeof(buf) - len, ",%d\n",
					iq_params->tone_vector_avg);
		else
			len += snprintf(buf + len, sizeof(buf) - len, ",NA\n");

		if (cl_hw->calib_db->file_flags.iq_rx_report)
			cl_calib_iq_tx_write_version(cl_hw);
	} else {
		return -1;
	}

	return cl_file_open_and_write(filename, O_WRONLY | O_APPEND, buf, len);
}

static void cl_calib_iq_write_data_file(struct cl_hw *cl_hw, s16 calib_temperature, u8 channel,
					u8 bw, u8 plan_bitmap)
{
	struct cl_calib_iq_params iq_params = {};
	int chain;
	u8 band_idx = cl_band_num_to_fw_idx(cl_hw->calib_params.band);
	u8 channel_idx = cl_calib_dcoc_channel_bw_to_idx(cl_hw, channel, bw);
	struct cl_iq_calib iq_calib_dma;

	iq_params.channel = channel;
	iq_params.bw = BW_TO_MHZ(bw);
	iq_params.band = cl_hw->calib_params.band;
	iq_params.temperature = calib_temperature;

	riu_chain_for_each(chain) {
		if ((plan_bitmap & (1 << chain)) == 0)
			continue;

		iq_params.chain = chain;
		iq_calib_dma = cl_hw->iq_dcoc_data_info.iq_dcoc_data->iq_dcoc_db.iq_tx[chain];
		iq_params.coef0 = le32_to_cpu(iq_calib_dma.coef0);
		iq_params.coef1 = le32_to_cpu(iq_calib_dma.coef1);
		iq_params.coef2 = le32_to_cpu(iq_calib_dma.coef2);
		iq_params.gain = le32_to_cpu(iq_calib_dma.gain);
		cl_hw->calib_db->iq_tx[band_idx][channel_idx][bw][chain] = iq_calib_dma;

		if (!cl_hw->chip->conf->ce_calib_runtime_en ||
		    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
			cl_calib_iq_write_file(cl_hw, FILE_PREFIX_IQ_TX, &iq_params);

		iq_calib_dma = cl_hw->iq_dcoc_data_info.iq_dcoc_data->iq_dcoc_db.iq_rx[chain];
		iq_params.coef0 = le32_to_cpu(iq_calib_dma.coef0);
		iq_params.coef1 = le32_to_cpu(iq_calib_dma.coef1);
		iq_params.coef2 = le32_to_cpu(iq_calib_dma.coef2);
		iq_params.gain = le32_to_cpu(iq_calib_dma.gain);
		cl_hw->calib_db->iq_rx[band_idx][channel_idx][bw][chain] = iq_calib_dma;

		if (!cl_hw->chip->conf->ce_calib_runtime_en ||
		    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
			cl_calib_iq_write_file(cl_hw, FILE_PREFIX_IQ_RX, &iq_params);
	}
}

static void cl_calib_iq_write_report_file(struct cl_hw *cl_hw, s16 calib_temperature, u8 ch, u8 bw,
					  u8 plan_bitmap)
{
	struct cl_calib_iq_params iq_params = {};
	u8 chain = 0;
	u8 tone = 0;
	struct cl_iq_report iq_report_dma;
	s8 iq_threshold = cl_hw->chip->conf->ci_iq_db_thr;
	s8 ir_db_avg_post;

	iq_params.channel = ch;
	iq_params.bw = BW_TO_MHZ(bw);
	iq_params.band = cl_hw->calib_params.band;
	iq_params.temperature = calib_temperature;

	riu_chain_for_each(chain) {
		if ((plan_bitmap & (1 << chain)) == 0)
			continue;

		iq_params.chain = chain;
		iq_report_dma = cl_hw->iq_dcoc_data_info.iq_dcoc_data->report.iq_tx[chain];
		ir_db_avg_post = iq_report_dma.ir_db_avg_post;

		iq_params.loop_idx = IQ_PRE_IDX;
		for (tone = 0; tone < IQ_NUM_TONES_CFM; tone++)
			iq_params.tone_vector[tone] = iq_report_dma.ir_db[IQ_PRE_IDX][tone];

		if (!cl_hw->chip->conf->ce_calib_runtime_en ||
		    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
			cl_calib_iq_write_file(cl_hw, FILE_PREFIX_IQ_TX_REPORT, &iq_params);

		iq_params.loop_idx = IQ_SINGLETON_IDX;
		for (tone = 0; tone < IQ_NUM_TONES_CFM; tone++)
			iq_params.tone_vector[tone] = iq_report_dma.ir_db[IQ_SINGLETON_IDX][tone];

		if (!cl_hw->chip->conf->ce_calib_runtime_en ||
		    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
			cl_calib_iq_write_file(cl_hw, FILE_PREFIX_IQ_TX_REPORT, &iq_params);

		iq_params.loop_idx = IQ_POST_IDX;
		for (tone = 0; tone < IQ_NUM_TONES_CFM; tone++)
			iq_params.tone_vector[tone] = iq_report_dma.ir_db[IQ_POST_IDX][tone];

		iq_params.tone_vector_avg = iq_report_dma.ir_db_avg_post;

		if (!cl_hw->chip->conf->ce_calib_runtime_en ||
		    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
			cl_calib_iq_write_file(cl_hw, FILE_PREFIX_IQ_TX_REPORT, &iq_params);

		cl_dbg_trace(cl_hw, "IQ TX[chain = %u]: Average IR Post = %d\n",
			     chain, ir_db_avg_post);

		if (ir_db_avg_post > iq_threshold) {
			cl_dbg_warn(cl_hw,
				    "Warning: IQ TX value exceeds threshold [%ddB]: channel %u, "
				    "bw  = %u, chain = %u, AVG_IQ_POST_DB = %d\n",
				    iq_threshold, ch, iq_params.bw, chain, ir_db_avg_post);
			cl_hw->calib_db->errors.iq_tx++;
		}

		iq_report_dma = cl_hw->iq_dcoc_data_info.iq_dcoc_data->report.iq_rx[chain];
		ir_db_avg_post = iq_report_dma.ir_db_avg_post;

		iq_params.loop_idx = IQ_PRE_IDX;
		for (tone = 0; tone < IQ_NUM_TONES_CFM; tone++)
			iq_params.tone_vector[tone] = iq_report_dma.ir_db[IQ_PRE_IDX][tone];

		if (!cl_hw->chip->conf->ce_calib_runtime_en ||
		    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
			cl_calib_iq_write_file(cl_hw, FILE_PREFIX_IQ_RX_REPORT, &iq_params);

		iq_params.loop_idx = IQ_SINGLETON_IDX;
		for (tone = 0; tone < IQ_NUM_TONES_CFM; tone++)
			iq_params.tone_vector[tone] = iq_report_dma.ir_db[IQ_SINGLETON_IDX][tone];

		if (!cl_hw->chip->conf->ce_calib_runtime_en ||
		    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
			cl_calib_iq_write_file(cl_hw, FILE_PREFIX_IQ_RX_REPORT, &iq_params);

		iq_params.loop_idx = IQ_POST_IDX;
		for (tone = 0; tone < IQ_NUM_TONES_CFM; tone++)
			iq_params.tone_vector[tone] = iq_report_dma.ir_db[IQ_POST_IDX][tone];

		iq_params.tone_vector_avg = iq_report_dma.ir_db_avg_post;

		if (!cl_hw->chip->conf->ce_calib_runtime_en ||
		    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
			cl_calib_iq_write_file(cl_hw, FILE_PREFIX_IQ_RX_REPORT, &iq_params);

		cl_dbg_trace(cl_hw, "IQ RX[chain = %u]: Average IR Post = %d\n",
			     chain, ir_db_avg_post);

		if (ir_db_avg_post > iq_threshold) {
			cl_dbg_warn(cl_hw,
				    "Warning: IQ RX value exceeds threshold [%ddB]: channel %u, "
				    "bw  = %u, chain = %u, AVG_IQ_POST_DB = %d\n",
				    iq_threshold, ch, iq_params.bw, chain, ir_db_avg_post);
			cl_hw->calib_db->errors.iq_rx++;
		}
	}
}

static void cl_calib_iq_write_lolc_registers_to_file(struct cl_hw *cl_hw)
{
	struct cl_calib_iq_params iq_params = {};
	u8 bw = cl_hw->bw;
	u8 chain;

	iq_params.channel = cl_hw->channel;
	iq_params.bw = BW_TO_MHZ(bw);
	iq_params.band = cl_hw->conf->ci_band_num;
	iq_params.temperature = cl_temperature_get_internal(cl_hw);

	riu_chain_for_each(chain) {
		iq_params.chain = chain;
		cl_rfic_get_iq_dc(cl_hw, chain, CL_IQ_TX_DC_TYPE_COMBINATION, &iq_params.tx_dc);

		cl_calib_iq_write_file(cl_hw, FILE_PREFIX_LOLC, &iq_params);
	}
}

static void cl_calib_iq_lolc_write_data_file(struct cl_hw *cl_hw, s16 calib_temperature,
					     u8 channel, u8 bw, u8 plan_bitmap)
{
	int chain;
	u8 bw_mhz = BW_TO_MHZ(bw);
	u8 band = cl_hw->calib_params.band;
	u8 band_idx = cl_band_num_to_fw_idx(band);
	u8 channel_idx = cl_calib_dcoc_channel_bw_to_idx(cl_hw, channel, bw);
	s32 params[DCOC_PARAM_MAX] = {0};
	__le32 lolc_calib_dma;

	/* "<Channel> <BW> <Antenna> <Sx#> <Temperature> <I> <Q>" */
	params[LOLC_CHANNEL] = channel;
	params[LOLC_BW] = bw_mhz;
	params[LOLC_BAND] = band;
	params[LOLC_TEMPERATURE] = calib_temperature;

	riu_chain_for_each(chain) {
		if ((plan_bitmap & (1 << chain)) == 0)
			continue;

		params[LOLC_ANTENNA] = chain;
		lolc_calib_dma =
			cl_hw->iq_dcoc_data_info.iq_dcoc_data->iq_dcoc_db.iq_tx_lolc[chain];
		cl_hw->calib_db->iq_tx_lolc[band_idx][channel_idx][bw][chain] =
			le32_to_cpu(lolc_calib_dma);
		params[LOLC_I] = CAST_S12_TO_S32(le32_to_cpu(lolc_calib_dma) &
						 RIU_IQDC_TX_0_DC_IQDC_TX_0_DCI_MASK);
		params[LOLC_Q] = CAST_S12_TO_S32((le32_to_cpu(lolc_calib_dma) &
						  RIU_IQDC_TX_0_DC_IQDC_TX_0_DCQ_MASK) >>
						 RIU_IQDC_TX_0_DC_IQDC_TX_0_DCQ_LSB);

		if (!cl_hw->chip->conf->ce_calib_runtime_en ||
		    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
			cl_calib_iq_lolc_write_file(cl_hw, params);
	}
}

static void cl_calib_iq_lolc_write_report_file(struct cl_hw *cl_hw, s16 calib_temperature,
					       int channel, u8 bw, u8 plan_bitmap)
{
	struct cl_iq_dcoc_report *report = &cl_hw->iq_dcoc_data_info.iq_dcoc_data->report;
	int chain;
	struct cl_lolc_report lolc_report_dma;
	int bw_mhz = BW_TO_MHZ(bw);
	s32 params[DCOC_REPORT_PARAM_MAX] = {0};
	u8 band = cl_hw->calib_params.band;
	s16 lolc_threshold = cl_hw->chip->conf->ci_lolc_db_thr;
	s32 lolc_qual = 0;

	/* "<Channel>      <BW>    <Ant.>  <Sx#>   <Temp.> <Itr.>  <Qual>" */
	params[LOLC_REPORT_CHANNEL] = channel;
	params[LOLC_REPORT_BW] = bw_mhz;
	params[LOLC_REPORT_BAND] = band;
	params[LOLC_REPORT_TEMPERATURE] = calib_temperature;

	/* "<Ant.>  <Sx#>   <Temp.> <Itr.>  <Qual>" */
	riu_chain_for_each(chain) {
		if ((plan_bitmap & (1 << chain)) == 0)
			continue;

		params[LOLC_REPORT_ANTENNA] = chain;
		lolc_report_dma = report->lolc_report[chain];
		lolc_qual = (s16)(le16_to_cpu(lolc_report_dma.lolc_qual)) >> 8;
		params[LOLC_REPORT_QUAL_DB] = lolc_qual;
		params[LOLC_REPORT_ITERATIONS] = lolc_report_dma.n_iter;

		cl_dbg_trace(cl_hw, "LOLC Quality [chain = %u] = %d, Iter = %u\n",
			     chain, lolc_qual, lolc_report_dma.n_iter);

		cl_calib_iq_lolc_report_write_file(cl_hw, params);

		if (lolc_qual > lolc_threshold) {
			cl_dbg_warn(cl_hw,
				    "Warning: LOLC value exceeds threshold [%ddB]: channel %u, "
				    "bw  = %u, chain = %u, LOLC[dB] = %d, I[Iter] = %u\n",
				    lolc_threshold, channel, bw_mhz, chain, lolc_qual,
				    params[LOLC_REPORT_ITERATIONS]);
			cl_hw->calib_db->errors.lolc++;
		}
	}
}

static int cl_calib_iq_calibrate_channel(struct cl_hw *cl_hw, u32 channel, u32 bw,
					 bool first_channel, u8 band)
{
	u32 primary = 0;
	u32 center = 0;
	enum nl80211_chan_width width = NL80211_CHAN_WIDTH_20;
	struct cl_calib_params params = {0};

	cl_calib_params_fill(&params,
			     cl_hw->chip->iq_dcoc_conf.iq_calib_mode_bmp,
			     0,
			     band,
			     channel,
			     bw,
			     first_channel,
			     SX_FREQ_OFFSET_Q2,
			     ANT_MASK(cl_hw->num_antennas),
			     0,
			     false,
			     0,
			     true);

	if (cl_chandef_calc_calib(cl_hw, channel, bw, &width, &primary, &center, band)) {
		cl_dbg_err(cl_hw, "cl_chandef_calc failed\n");
		return -EINVAL;
	}

	cl_dbg_trace(cl_hw, "\n ------  START CALIB IQ CHANNEL  -----\n");
	cl_dbg_trace(cl_hw, "channel = %u first_channel = %d\n", channel, first_channel);

	return cl_msg_tx_set_calib(cl_hw, primary, center, &params);
}

static u8 cl_calib_iq_convert_plan_to_calib_db_idx(u8 chan_idx_src, u8 bw)
{
	u8 shift_idx = 0;
	/*
	 * Calibration data is fetched from calibrated channels to previous uncalibrated channels in
	 * plan list.
	 *
	 * For example: channel 65 was calibrated due the channels plan list. Calibration data of
	 * channel 65 saved in calib_db struct in the relevant chan idx place due the BW, as the
	 * follow:
	 * chan_idx 16 for BW 20,
	 * chan_idx 8 for BW 40
	 * chan_idx 4 for BW 80
	 * chan_idx 2 for BW 160.
	 *
	 * We want to copy calib data of IQ & LOLC from channel 65 to channel 49. Doing the same
	 * also to the other uncalib channels: 33->17, 65->49, 97->81 etc.
	 *
	 * The chan idx of channel 49 in the calib_db by BW is:
	 * chan_idx 12 for BW 20,
	 * chan_idx 6 for BW 40
	 * chan_idx 3 for BW 80
	 * (no exist chan_idx for BW 160)
	 *
	 * We copy the data in calib_db from idx of channel 65 to the idx of channel 49:
	 * chan_idx 16 to chan_idx 12 (in BW 20)
	 * chan_idx 8 to chan_idx 6 (in BW 40)
	 * chan_idx 4 to chan_idx 3 (in BW 80)
	 *
	 * In general, the dst chan idx will be calculated by;
	 * dst_idx = src_idx - 4 (for BW 20)
	 * dst_idx = src_idx - 2 (for BW 40)
	 * dst_idx = src_idx - 1 (for BW 80)
	 *
	 * The way to calc this is shiftting is by the follow bitmask:
	 * 4 >> bw
	 */
	shift_idx = 4 >> bw;

	return chan_idx_src - shift_idx;
}

static void cl_calib_iq_copy_data_to_uncalibrated_channels_6g(struct cl_hw *cl_hw)
{
	struct cl_calib_db *calib_db = cl_hw->calib_db;
	int i;
	u8 band = cl_band_num_to_fw_idx(cl_hw->calib_params.band);
	u8 chan_idx_src = 0;
	u8 chan_idx_dst = 0;
	u8 chain = 0;
	u8 bw = 0;

	/*
	 * Copy iq & lo calib data from 6g list plan calibrate channels: 1, 33, 65, 97, 129, 161,
	 * 193, 22 to uncalibrated channels 17, 49, 81, 113, 145, 177, 209. copy to the correct
	 * channel idx for each different bw
	 */
	for (i = 1; i < CALIB_CHAN_6G_PLAN - 1; i += 2)
		riu_chain_for_each(chain)
			/* Iterate only CHNL_BW_80 and CHNL_BW_20 */
			for (bw = CHNL_BW_20; bw <= CHNL_BW_80; bw += 2) {
				chan_idx_src =
					cl_calib_dcoc_channel_bw_to_idx(cl_hw,
									calib_channels_6g_plan[i],
									bw);
				chan_idx_dst =
					cl_calib_iq_convert_plan_to_calib_db_idx(chan_idx_src, bw);
				memcpy(&calib_db->iq_tx[band][chan_idx_dst][bw][chain],
				       &calib_db->iq_tx[band][chan_idx_src][bw][chain],
				       sizeof(struct cl_iq_calib));
				memcpy(&calib_db->iq_rx[band][chan_idx_dst][bw][chain],
				       &calib_db->iq_rx[band][chan_idx_src][bw][chain],
				       sizeof(struct cl_iq_calib));
				calib_db->iq_tx_lolc[band][chan_idx_dst][bw][chain] =
					calib_db->iq_tx_lolc[band][chan_idx_src][bw][chain];
			}
}

static bool cl_calib_iq_calibrate_6g(struct cl_hw *cl_hw)
{
	int i;
	bool first_channel = true;

	/* Calibrate channels: 1, 33, 65, 97, 129, 161, 193, 225 */
	for (i = 0; i < CALIB_CHAN_6G_PLAN; i += 2) {
		if ((cl_calib_iq_calibrate_channel(cl_hw, calib_channels_6g_plan[i], CHNL_BW_160,
						   first_channel, BAND_6G) == 0))
			first_channel = false;

		if (cl_calib_iq_calibrate_channel(cl_hw, calib_channels_6g_plan[i], CHNL_BW_80,
						  first_channel, BAND_6G) == 0)
			first_channel = false;

		if (cl_calib_iq_calibrate_channel(cl_hw, calib_channels_6g_plan[i], CHNL_BW_20,
						  first_channel, BAND_6G) == 0)
			first_channel = false;
	}

	/* For these channels 17, 49, 81, 113, 145, 177, 209*/
	/* copy data of next neighbor */
	cl_calib_iq_copy_data_to_uncalibrated_channels_6g(cl_hw);
	return first_channel;
}

static bool cl_calib_iq_calibrate_5g(struct cl_hw *cl_hw)
{
	int i;
	bool first_channel = true;

	/* TODO - add 160 Mhz band when supported */

	for (i = 0; i < CALIB_CHAN_5G_PLAN; i++) {
		if (cl_calib_iq_calibrate_channel(cl_hw, calib_channels_5g_plan[i], CHNL_BW_80,
						  first_channel, BAND_5G) == 0)
			first_channel = false;

		if (cl_calib_iq_calibrate_channel(cl_hw, calib_channels_5g_plan[i], CHNL_BW_20,
						  first_channel, BAND_5G) == 0)
			first_channel = false;
	}
	return first_channel;
}

static bool cl_calib_iq_calibrate_24g(struct cl_hw *cl_hw)
{
	int i;
	bool first_channel = true;

	for (i = 0; i < CALIB_CHAN_24G_MAX; i++) {
		if (cl_calib_iq_calibrate_channel(cl_hw, calib_channels_24g[i], CHNL_BW_40,
						  first_channel, BAND_24G) == 0)
			first_channel = false;

		if (cl_calib_iq_calibrate_channel(cl_hw, calib_channels_24g[i], CHNL_BW_20,
						  first_channel, BAND_24G) == 0)
			first_channel = false;
	}
	return first_channel;
}

static bool cl_calib_iq_plan_calibrate_band(struct cl_hw *cl_hw)
{
	bool first_channel = true;
	u8 chan_idx, bw_idx;
	struct cl_calib_iq_plan *calib_iq_plan = NULL;
	struct list_head *plan;

	for (chan_idx = 0; chan_idx < CALIB_CHAN_MAX; chan_idx++) {
		for (bw_idx = 0; bw_idx < CHNL_BW_MAX; bw_idx++) {
			plan = &cl_hw->calib_db->plan[chan_idx][bw_idx];

			list_for_each_entry(calib_iq_plan, plan, list) {
				cl_hw->calib_iq_plan = calib_iq_plan;
				if (cl_calib_iq_calibrate_channel(cl_hw, calib_iq_plan->channel,
								  bw_idx, first_channel,
								  cl_hw->conf->ci_band_num) == 0)
					first_channel = false;
			}
		}
	}
	return first_channel;
}

static void cl_calib_iq_calibrate(struct cl_hw *cl_hw)
{
	bool first_channel = true;
	/* TODO - delete when 6g is supported */
	bool is_6g = false;
	/* If calib iq plan file was parsed ,do the calibration by plan file, else, do by default */
	if (cl_hw->calib_db->file_flags.iq_plan) {
		first_channel = cl_calib_iq_plan_calibrate_band(cl_hw);
	} else {
		cl_dbg_verbose(cl_hw, "Strating to calibrate IQ for all bands"
			       "- this may take several seconds\n");
		if (is_6g)
			first_channel = cl_calib_iq_calibrate_6g(cl_hw);
		first_channel = cl_calib_iq_calibrate_5g(cl_hw);
		first_channel = cl_calib_iq_calibrate_24g(cl_hw);
	}
	/* Mark that calibration flow has finished */
	cl_hw->chip->is_calib_in_progress = false;

	/* In case first_channel is false, it means that at least one channel was written*/
	/* to the DCOC calibration file, so TCV footer needs to be written.*/
	if (!first_channel) {
		u16 iq_tx_erros = cl_hw->calib_db->errors.iq_tx;
		u16 iq_rx_erros = cl_hw->calib_db->errors.iq_rx;

		if (iq_tx_erros)
			cl_calib_common_write_error(cl_hw, FILE_PREFIX_IQ_TX, iq_tx_erros);

		if (iq_rx_erros)
			cl_calib_common_write_error(cl_hw, FILE_PREFIX_IQ_RX, iq_rx_erros);
	}
}

static void cl_calib_iq_remov_all_tcv_entries(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_calib_file_flags *calib_file_flags = &cl_hw->calib_db->file_flags;
	u8 num_calib_ant = chip->iq_dcoc_conf.iq_file_num_ant;

	calib_file_flags->lolc |= CALIB_FLAG_HEADER_TCV0;
	calib_file_flags->iq_tx |= CALIB_FLAG_HEADER_TCV0;
	calib_file_flags->iq_rx |= CALIB_FLAG_HEADER_TCV0;

	cl_calib_common_remove_tcv_entries(cl_hw, LOLC_FILE, num_calib_ant);
	cl_calib_common_remove_tcv_entries(cl_hw, IQ_TX_FILE, num_calib_ant);
	cl_calib_common_remove_tcv_entries(cl_hw, IQ_RX_FILE, num_calib_ant);
}

static int cl_calib_iq_validate_version(struct cl_chip *chip, char *buf)
{
	u32 version_id;

	if (sscanf(buf, FILE_VERSION_ID, &version_id) == 1) {
		if (version_id == VERSION_ID_IQ)
			return 0;

		cl_dbg_chip_err(chip,
				"Calibration file's Version Id [%u] and current Version Id [%d] "
				"aren't equal\n", version_id, VERSION_ID_IQ);
		return -1;
	}
	cl_dbg_chip_err(chip, "Calibration file doesn't contain a Version Id\n");
	return -1;
}

static void cl_calib_iq_init_calibration_tcv(struct cl_hw *cl_hw)
{
	cl_calib_iq_calibrate(cl_hw);
	cl_hw->chip->iq_dcoc_conf.iq_file_num_ant = cl_hw->num_antennas;
}

void cl_calib_restore_channel(struct cl_hw *cl_hw, struct cl_calib_iq_restore *iq_restore)
{
	s8 sx_freq_offset_mhz_TBD = 0;
	u8 bw = iq_restore->bw;
	u32 primary = iq_restore->primary;
	u32 center = iq_restore->center;
	u8 channel = iq_restore->channel;

	cl_msg_tx_set_channel(cl_hw, channel, bw, primary, center, sx_freq_offset_mhz_TBD);
}

void cl_calib_save_channel(struct cl_hw *cl_hw, struct cl_calib_iq_restore *iq_restore)
{
	iq_restore->bw = cl_hw->bw;
	iq_restore->primary = cl_hw->primary_freq;
	iq_restore->center = cl_hw->center_freq;
	iq_restore->channel = ieee80211_frequency_to_channel(cl_hw->primary_freq);

	cl_dbg_chip_trace(cl_hw, "bw = %u, primary = %d, center = %d, channel = %u\n",
			  iq_restore->bw, iq_restore->primary,
			  iq_restore->center, iq_restore->channel);
}

bool cl_calib_iq_calibration_needed(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_iq_dcoc_conf *iq_dcoc_conf = &chip->iq_dcoc_conf;
	bool calib_needed = false;

	if (!IS_REAL_PHY(chip))
		return false;

	if (cl_hw->chip->conf->ce_calib_runtime_en)
		return false;

	if (iq_dcoc_conf->iq_calib_needed)
		return true;

	if (cl_chip_is_tcv0_enabled(chip)) {
		u8 num_antennas_tcv0 = chip->cl_hw_tcv0->num_antennas;

		if (iq_dcoc_conf->iq_file_num_ant < num_antennas_tcv0) {
			cl_dbg_verbose(cl_hw,
				       "Num of antennas [%u], is larger than LOLC Calibration File "
				       "num of antennas [%u], recalibration is needed\n",
				       num_antennas_tcv0, iq_dcoc_conf->iq_file_num_ant);
			cl_calib_iq_remov_all_tcv_entries(chip->cl_hw_tcv0);
			calib_needed = true;
		}
	}

	return calib_needed;
}

void cl_calib_iq_file_flags_clear(struct cl_chip *chip)
{
	struct cl_hw *cl_hw = chip->cl_hw_tcv0;
	struct cl_calib_file_flags *calib_file_flags = &cl_hw->calib_db->file_flags;

	calib_file_flags->lolc = CALIB_FLAG_HEADER_TCV0;
	calib_file_flags->lolc_report = 0;
	calib_file_flags->iq_tx = CALIB_FLAG_HEADER_TCV0;
	calib_file_flags->iq_tx_report = 0;
	calib_file_flags->iq_rx = CALIB_FLAG_HEADER_TCV0;
	calib_file_flags->iq_rx_report = 0;
	calib_file_flags->rx_gain_report = 0;
}

void cl_calib_iq_file_flags_set(struct cl_chip *chip)
{
	struct cl_hw *cl_hw = chip->cl_hw_tcv0;
	struct cl_calib_file_flags *calib_file_flags = &cl_hw->calib_db->file_flags;

	calib_file_flags->lolc = CALIB_FLAG_ALL;
	calib_file_flags->lolc_report = CALIB_FLAG_ALL_REPORT;
	calib_file_flags->iq_tx = CALIB_FLAG_ALL;
	calib_file_flags->iq_tx_report = CALIB_FLAG_ALL_REPORT;
	calib_file_flags->iq_rx = CALIB_FLAG_ALL;
	calib_file_flags->iq_rx_report = CALIB_FLAG_ALL_REPORT;
	calib_file_flags->rx_gain_report = CALIB_FLAG_ALL_REPORT;
}

int cl_calib_iq_post_read_actions(struct cl_chip *chip, char *buf)
{
	/*
	 * Assume LO+IQ Calibration are needed. Will be reverted once LO+IQ Calibrations
	 * values that matches the TCV will be found in the Calibration File.
	 */
	chip->iq_dcoc_conf.iq_calib_needed = true;
	chip->iq_dcoc_conf.iq_calib_mode_bmp = chip->conf->ci_calib_iq_mode_bitmap;

	if (cl_calib_iq_validate_version(chip, buf) != 0) {
		/* Remove LO+IQ Calibration File and re-calibrate LO+IQ */
		cl_calib_iq_file_flags_set(chip);

		cl_dbg_chip_verbose(chip, "Need to Calibrate LO+IQ\n");
		return -1;
	}

	return 0;
}

void cl_calib_iq_init_calibration(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_iq_dcoc_conf *iq_dcoc_conf = &chip->iq_dcoc_conf;

	if ((iq_dcoc_conf->force_calib ||
	     iq_dcoc_conf->iq_calib_needed))
		cl_calib_iq_init_calibration_tcv(cl_hw);

	iq_dcoc_conf->iq_calib_needed = false;
}

int cl_calib_iq_init_calibration_channel(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_hw *cl_hw_tcv0 = chip->cl_hw_tcv0;
	struct cl_calib_iq_restore iq_restore_tcv0;
	u32 channel = cl_hw->channel;
	u8 bw = cl_hw->bw;
	u8 band = cl_hw->conf->ci_band_num;
	int ret = 0;
	u8 save_tcv0_needed = cl_hw_tcv0 && !!cl_hw_tcv0->primary_freq;

	if (save_tcv0_needed)
		cl_calib_save_channel(cl_hw_tcv0, &iq_restore_tcv0);

	if (cl_calib_iq_calibrate_channel(cl_hw, channel, bw, false, band)) {
		cl_dbg_chip_err(cl_hw, "Failed to calibrate channel %u, bw %u", channel, bw);
		ret = -1;
	}

	if (save_tcv0_needed)
		cl_calib_restore_channel(cl_hw_tcv0, &iq_restore_tcv0);

	return ret;
}

void cl_calib_iq_fill_data(struct cl_hw *cl_hw, struct cl_iq_calib *iq_data,
			   struct cl_iq_calib *iq_chip_data)
{
	u8 ant = 0;

	for (ant = 0; ant < MAX_ANTENNAS; ant++) {
		iq_data[ant].coef0 = iq_chip_data[ant].coef0;
		iq_data[ant].coef1 = iq_chip_data[ant].coef1;
		iq_data[ant].coef2 = iq_chip_data[ant].coef2;
		iq_data[ant].gain = iq_chip_data[ant].gain;
	}
}

void cl_calib_iq_lolc_fill_data(struct cl_hw *cl_hw, __le32 *iq_lolc, bool is_calib)
{
	struct cl_calib_db *calib_db = cl_hw->calib_db;
	u8 ant = 0;
	u8 bw = cl_hw->bw;
	u8 chan_idx = cl_calib_dcoc_channel_bw_to_idx(cl_hw, cl_hw->channel, bw);
	u8 band = cl_hw->conf->ci_band_num;
	u8 band_idx;

	if (is_calib) {
		bw = cl_hw->calib_params.wifi_bw;
		chan_idx = cl_calib_dcoc_channel_bw_to_idx(cl_hw, cl_hw->calib_params.channel, bw);
		band = cl_hw->calib_params.band;
	}

	band_idx = cl_band_num_to_fw_idx(band);

	for (ant = 0; ant < MAX_ANTENNAS; ant++)
		iq_lolc[ant] = cpu_to_le32(calib_db->iq_tx_lolc[band_idx][chan_idx][bw][ant]);
}

void cl_calib_iq_parse_str(struct cl_chip *chip, char *str, enum calib_files_idx file_idx)
{
	struct cl_hw *cl_hw = chip->cl_hw_tcv0;
	int ret = 0;
	u32 channel = 0;
	u32 bw_mhz = 0;
	u32 ant = 0;
	s32 temperature = 0;
	u32 coef0 = 0;
	u32 coef1 = 0;
	u32 coef2 = 0;
	u32 gain = 0;
	u8 channel_idx = 0;
	u8 chan_idx_max = cl_band_is_6g(chip->cl_hw_tcv0) ? CALIB_CHAN_6G_MAX : CALIB_CHAN_5G_MAX;
	u8 bw = 0;
	u8 chan_idx_dst = 0;
	u32 band = 0;
	u8 band_idx = 0;
	const char *delims = " \t";
	struct cl_iq_calib *iq_db;

	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &channel);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing channel from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &bw_mhz);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing bw from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &ant);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing ant from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &band);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing band from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtos32(cl_calib_common_non_empty_strsep(&str, delims), 10, &temperature);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing temp. from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 16, &coef0);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing coef0 from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 16, &coef1);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing coef1 from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 16, &coef2);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing coef2 from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 16, &gain);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing gain from str=%s failed with ret %d\n", str, ret);
		return;
	}

	bw = MHZ_TO_BW(bw_mhz);
	channel_idx = cl_calib_dcoc_tcv_channel_to_idx(chip, band, channel, bw);

	if (channel_idx >= chan_idx_max ||
	    bw >= CHNL_BW_MAX ||
	    ant >= MAX_ANTENNAS ||
	    band > BAND_24G ||
	    temperature >= CL_MAX_TEMPERATURE) {
		cl_dbg_chip_err(chip, "some wrong parameter parsed: channel=%u, bw=%u, ant=%u, "
				"band=%u, temperature=%d\n",
				channel, bw_mhz, ant, band, temperature);
		return;
	}

	band_idx = cl_band_num_to_fw_idx(band);
	if (file_idx == IQ_TX_FILE) {
		iq_db = &cl_hw->calib_db->iq_tx[band_idx][channel_idx][bw][ant];
	} else if (file_idx == IQ_RX_FILE) {
		iq_db = &cl_hw->calib_db->iq_rx[band_idx][channel_idx][bw][ant];
	} else {
		cl_dbg_chip_err(chip, "Wrong type of file. Aborting. file_idx = %d\n", file_idx);
		return;
	}

	iq_db->coef0 = cpu_to_le32(coef0);
	iq_db->coef1 = cpu_to_le32(coef1);
	iq_db->coef2 = cpu_to_le32(coef2);
	iq_db->gain = cpu_to_le32(gain);

	/* For 6g band copy data from calib channel non calib channel in plan list */
	if (!cl_band_is_6g(chip->cl_hw_tcv0) || channel_idx == 0 || bw == CHNL_BW_160)
		return;

	chan_idx_dst = cl_calib_iq_convert_plan_to_calib_db_idx(channel_idx, bw);
	if (file_idx == IQ_TX_FILE)
		cl_hw->calib_db->iq_tx[band_idx][channel_idx][bw][ant] = *iq_db;
	else
		cl_hw->calib_db->iq_rx[band_idx][channel_idx][bw][ant] = *iq_db;
}

void cl_calib_iq_plan_init(struct cl_chip *chip)
{
	struct cl_hw *cl_hw = chip->cl_hw_tcv0;
	u8 tcv_idx, chan_idx, bw_idx;

	for (tcv_idx = 0; tcv_idx < TCV_MAX; tcv_idx++)
		for (chan_idx = 0; chan_idx < CALIB_CHAN_MAX; chan_idx++)
			for (bw_idx = 0; bw_idx < CHNL_BW_MAX; bw_idx++)
				INIT_LIST_HEAD(&cl_hw->calib_db->plan[chan_idx][bw_idx]);
}

void cl_calib_iq_plan_deinit(struct cl_chip *chip)
{
	struct cl_hw *cl_hw = chip->cl_hw_tcv0;
	struct cl_calib_iq_plan *calib_iq_plan = NULL;
	struct cl_calib_iq_plan *tmp_calib_iq_plan = NULL;
	struct list_head *plan;
	u8 tcv_idx, chan_idx, bw_idx;

	for (tcv_idx = 0; tcv_idx < TCV_MAX; tcv_idx++) {
		for (chan_idx = 0; chan_idx < CALIB_CHAN_MAX; chan_idx++) {
			for (bw_idx = 0; bw_idx < CHNL_BW_MAX; bw_idx++) {
				plan = &cl_hw->calib_db->plan[chan_idx][bw_idx];

				list_for_each_entry_safe(calib_iq_plan, tmp_calib_iq_plan, plan,
							 list) {
					list_del(&calib_iq_plan->list);
					kfree(calib_iq_plan);
				}
			}
		}
	}
}

static bool cl_calib_iq_plan_is_bw_mhz_valid(u8 bw_mhz)
{
	if (bw_mhz == 20 || bw_mhz == 40 || bw_mhz == 80 || bw_mhz == 160)
		return true;

	return false;
}

static struct cl_calib_iq_plan *cl_calib_iq_plan_add_elem_to_list(struct list_head *plan)
{
	struct cl_calib_iq_plan *elem = kzalloc(sizeof(*elem), GFP_KERNEL);

	list_add_tail(&elem->list, plan);
	return elem;
}

static void cl_calib_iq_plan_fill_data(struct list_head *plan, bool is_tx, u8 tx_chain, u8 rx_chain,
				       u8 tx_gain, u8 rx_gain, s8 sx_diff, u16 channel)
{
	struct cl_calib_iq_plan *calib_iq_plan = NULL;
	struct cl_calib_iq_plan_chain *chain_ptr;
	bool elem_found = false;

	list_for_each_entry(calib_iq_plan, plan, list) {

		/* Check if fill data to TX or RX struct */
		chain_ptr = is_tx ? &calib_iq_plan->tx_chain[tx_chain] :
			&calib_iq_plan->rx_chain[rx_chain];

		/* If chain_ptr wasn't fill from parse yet - there is a free place to fill in */
		if (!chain_ptr->occupy && sx_diff == calib_iq_plan->sx_diff) {
			elem_found = true;
			break;
		}
	}

	/* If no free place in all the list of calib_iq_plan elements - add new elemnt to list */
	if (!elem_found) {
		calib_iq_plan = cl_calib_iq_plan_add_elem_to_list(plan);
		chain_ptr = is_tx ? &calib_iq_plan->tx_chain[tx_chain] :
			&calib_iq_plan->rx_chain[rx_chain];
	}

	chain_ptr->occupy = true;
	chain_ptr->calib_chain.pair = is_tx ? rx_chain : tx_chain;
	chain_ptr->calib_chain.initial_tx_gain = tx_gain;
	chain_ptr->calib_chain.initial_rx_gain = rx_gain;
	calib_iq_plan->sx_diff = sx_diff;
	calib_iq_plan->channel = channel;
}

void cl_calib_iq_plan_parse_str(struct cl_chip *chip, char *str, enum calib_files_idx file_idx)
{
	struct cl_hw *cl_hw = chip->cl_hw_tcv0;
	int ret = 0;
	u16 channel = 0;
	u8 bw_mhz = 0;
	u8 phy = 0;
	u8 tx_sx = 0;
	u8 tx_chain = 0;
	u8 rx_chain = 0;
	u8 tx_gain = 0;
	u8 rx_gain = 0;
	s8 sx_diff = 0;
	u8 channel_idx = 0;
	u8 chan_idx_max = cl_band_is_6g(chip->cl_hw_tcv0) ? CALIB_CHAN_6G_MAX : CALIB_CHAN_5G_MAX;
	u8 bw = 0;
	const char *delims = " \t";
	struct list_head *plan;
	bool is_tx;

	ret = kstrtou16(cl_calib_common_non_empty_strsep(&str, delims), 10, &channel);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing channel from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou8(cl_calib_common_non_empty_strsep(&str, delims), 10, &bw_mhz);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing bw from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou8(cl_calib_common_non_empty_strsep(&str, delims), 10, &phy);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing phy from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou8(cl_calib_common_non_empty_strsep(&str, delims), 10, &tx_sx);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing tx_sx from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou8(cl_calib_common_non_empty_strsep(&str, delims), 10, &tx_chain);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing tx_chain from str=%s failed with ret %d\n", str,
				ret);
		return;
	}
	ret = kstrtou8(cl_calib_common_non_empty_strsep(&str, delims), 10, &rx_chain);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing rx_chain from str=%s failed with ret %d\n", str,
				ret);
		return;
	}
	ret = kstrtou8(cl_calib_common_non_empty_strsep(&str, delims), 16, &tx_gain);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing tx_gain from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou8(cl_calib_common_non_empty_strsep(&str, delims), 16, &rx_gain);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing rx_gain from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtos8(cl_calib_common_non_empty_strsep(&str, delims), 10, &sx_diff);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing sx_diff from str=%s failed with ret %d\n", str, ret);
		return;
	}

	if (cl_calib_iq_plan_is_bw_mhz_valid(bw_mhz)) {
		bw = MHZ_TO_BW(bw_mhz);
		channel_idx = cl_calib_dcoc_tcv_channel_to_idx(chip, 0, channel, bw);
	}

	if (!cl_calib_iq_plan_is_bw_mhz_valid(bw_mhz) ||
	    channel_idx >= chan_idx_max ||
	    phy > 1 ||
	    tx_sx >= MAX_SX ||
	    tx_chain >= MAX_ANTENNAS ||
	    rx_chain >= MAX_ANTENNAS ||
	    tx_chain == rx_chain ||
	    tx_gain > 0xff ||
	    rx_gain > 0xff) {
		cl_dbg_chip_err(chip, "Some wrong parameter parsed: channel=%u, bw=%u, phy=%u,"
				"tx_sx=%u, tx_chain=%u, rx_chain=%u, tx_gain=0x%X, rx_gain=0x%X\n",
				channel, bw_mhz, phy, tx_sx, tx_chain, rx_chain, tx_gain, rx_gain);
		return;
	}

	plan = &cl_hw->calib_db->plan[channel_idx][bw];
	cl_dbg_chip_info(chip, "phy = %u, channel = %u, channel_idx = %u, bw_mhz = %u,"
			 "bw = %u\n", phy, channel, channel_idx, bw_mhz, bw);

	/* Fill data plan of calibrate TX when phy = tx_sx, else fill data of calibrate RX */
	is_tx = (phy == tx_sx) ? true : false;
	cl_calib_iq_plan_fill_data(plan, is_tx, tx_chain, rx_chain, tx_gain, rx_gain, sx_diff,
				   channel);
}

void cl_calib_iq_lolc_parse_str(struct cl_chip *chip, char *str, enum calib_files_idx file_idx)
{
	struct cl_hw *cl_hw = chip->cl_hw_tcv0;
	int ret = 0;
	u32 channel = 0;
	u32 bw_mhz = 0;
	u32 ant = 0;
	s32 temperature = 0;
	s32 tx_dc_i = 0;
	s32 tx_dc_q = 0;
	u32 tx_dc = 0;
	u8 channel_idx = 0;
	u8 chan_idx_max = cl_band_is_6g(chip->cl_hw_tcv0) ? CALIB_CHAN_6G_MAX : CALIB_CHAN_5G_MAX;
	u8 bw = 0;
	u8 chan_idx_dst = 0;
	u32 band = 0;
	u8 band_idx = 0;
	const char *delims = " \t";

	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &channel);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing channel from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &bw_mhz);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing bw from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &ant);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing ant from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtou32(cl_calib_common_non_empty_strsep(&str, delims), 10, &band);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing band from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtos32(cl_calib_common_non_empty_strsep(&str, delims), 10, &temperature);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing temp. from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtos32(cl_calib_common_non_empty_strsep(&str, delims), 10, &tx_dc_i);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing tx_dc_i from str=%s failed with ret %d\n", str, ret);
		return;
	}
	ret = kstrtos32(cl_calib_common_non_empty_strsep(&str, delims), 10, &tx_dc_q);
	if (ret) {
		cl_dbg_chip_err(chip, "parsing tx_dc_q from str=%s failed with ret %d\n", str, ret);
		return;
	}

	bw = MHZ_TO_BW(bw_mhz);
	channel_idx = cl_calib_dcoc_tcv_channel_to_idx(chip, band, channel, bw);

	if (channel_idx >= chan_idx_max ||
	    bw >= CHNL_BW_MAX ||
	    ant >= MAX_ANTENNAS ||
	    band > BAND_24G ||
	    temperature >= CL_MAX_TEMPERATURE) {
		cl_dbg_chip_err(chip, "some wrong parameter parsed: channel=%u, bw=%u, ant=%u, "
				"band=%u, temperature=%d\n",
				channel, bw_mhz, ant, band, temperature);
		return;
	}

	tx_dc = ((tx_dc_i & RIU_IQDC_TX_0_DC_IQDC_TX_0_DCI_MASK) |
		 ((tx_dc_q << RIU_IQDC_TX_0_DC_IQDC_TX_0_DCQ_LSB) &
		  RIU_IQDC_TX_0_DC_IQDC_TX_0_DCQ_MASK));
	band_idx = cl_band_num_to_fw_idx(band);
	cl_hw->calib_db->iq_tx_lolc[band_idx][channel_idx][bw][ant] = tx_dc;

	/* For 6g band copy data from calib channel non calib channel in plan list */
	if (!cl_band_is_6g(chip->cl_hw_tcv0) || channel_idx == 0 || bw == CHNL_BW_160)
		return;

	chan_idx_dst = cl_calib_iq_convert_plan_to_calib_db_idx(channel_idx, bw);
	cl_hw->calib_db->iq_tx_lolc[band_idx][chan_idx_dst][bw][ant] = tx_dc;
}

void cl_calib_iq_write_registers_to_file(struct cl_hw *cl_hw, enum calib_files_idx files_idx)
{
	/* IQ calibration is not supported yet! */
	struct cl_calib_iq_params iq_params = {0};
	u8 bw = cl_hw->bw;
	u8 chain;
	enum cl_iq_direction iq_direction;

	iq_params.channel = cl_hw->channel;
	iq_params.bw = BW_TO_MHZ(bw);
	iq_params.band = cl_hw->conf->ci_band_num;
	iq_params.temperature = cl_temperature_get_internal(cl_hw);

	if (files_idx == IQ_TX_FILE)
		iq_direction = CL_IQ_DIRECTION_TX;
	else if (files_idx == IQ_RX_FILE)
		iq_direction = CL_IQ_DIRECTION_RX;
	else
		return;

	riu_chain_for_each(chain) {
		iq_params.chain = chain;

		cl_rfic_get_iq_gain(cl_hw, chain, iq_direction, CL_IQ_GAIN_TYPE_COMBINATION,
				    &iq_params.gain);

		if ((enum cl_iq_direction)iq_direction == CL_IQ_DIRECTION_TX)
			cl_calib_iq_write_file(cl_hw, FILE_PREFIX_IQ_TX, &iq_params);
		else if ((enum cl_iq_direction)iq_direction == CL_IQ_DIRECTION_RX)
			cl_calib_iq_write_file(cl_hw, FILE_PREFIX_IQ_RX, &iq_params);
	}
}

void cl_calib_iq_write_single_line_to_file(struct cl_hw *cl_hw, u8 iq_direction, u16 channel,
					   u8 bw, u8 ant, u8 sx, s16 temperature)
{
	/* IQ calibration is not supported yet! */
	struct cl_calib_iq_params iq_params = {0};

	iq_params.channel = channel;
	iq_params.bw = bw;
	iq_params.band = cl_hw->conf->ci_band_num;
	iq_params.temperature = temperature;
	iq_params.chain = ant;

	cl_rfic_get_iq_gain(cl_hw, ant, iq_direction, CL_IQ_GAIN_TYPE_COMBINATION, &iq_params.gain);

	if ((enum cl_iq_direction)iq_direction == CL_IQ_DIRECTION_TX)
		cl_calib_iq_write_file(cl_hw, FILE_PREFIX_IQ_TX, &iq_params);
	else if ((enum cl_iq_direction)iq_direction == CL_IQ_DIRECTION_RX)
		cl_calib_iq_write_file(cl_hw, FILE_PREFIX_IQ_RX, &iq_params);
}

void cl_calib_iq_tx_and_lolc_write_registers_to_file(struct cl_hw *cl_hw)
{
	cl_calib_iq_write_registers_to_file(cl_hw, IQ_TX_FILE);
	cl_calib_iq_write_lolc_registers_to_file(cl_hw);
}

void cl_calib_iq_handle_set_calib_cfm(struct cl_hw *cl_hw, u8 plan_bitmap)
{
	struct calib_cfm *dcoc_iq_cfm =
		&cl_hw->iq_dcoc_data_info.iq_dcoc_data->dcoc_iq_cfm[CALIB_CFM_WIFI_IQ];

	s16 calib_temperature = cl_calib_common_get_temperature(cl_hw, CALIB_CFM_WIFI_IQ);
	u8 channel = cl_hw->channel;
	u8 bw = cl_hw->bw;

	CL_DBG(cl_hw, DBG_LVL_TRACE, "calib_temperature = %d, channel = %u, bw = %u\n",
	       calib_temperature, channel, bw);

	cl_calib_iq_write_data_file(cl_hw, calib_temperature, channel, bw, plan_bitmap);
	cl_calib_iq_write_report_file(cl_hw, calib_temperature, channel, bw, plan_bitmap);

	/* If all channels calibration is finished - write footer */
	if (!cl_hw->chip->is_calib_in_progress) {
		cl_calib_iq_write_footer(cl_hw, IQ_TX_FILE);
		cl_calib_iq_write_footer(cl_hw, IQ_RX_FILE);
	}

	/*
	 * Set the default status to FAIL, to ensure FW is actually changing the value,
	 * if the calibration succeeded.
	 */
	dcoc_iq_cfm->status = CALIB_FAIL;
}

void cl_calib_iq_lolc_handle_set_channel_cfm(struct cl_hw *cl_hw, u8 plan_bitmap)
{
	struct calib_cfm *dcoc_iq_cfm =
		&cl_hw->iq_dcoc_data_info.iq_dcoc_data->dcoc_iq_cfm[CALIB_CFM_WIFI_IQ];
	struct cl_calib_params *params = &cl_hw->calib_params;
	//s16 calib_temperature = cl_calib_common_get_temperature(cl_hw, CALIB_CFM_WIFI_IQ);
	s16 calib_temperature = 0;

	u8 channel = params->channel;
	u8 bw = params->wifi_bw;

	cl_dbg_trace(cl_hw, "calib_temperature = %d, channel = %u, bw = %u\n", calib_temperature,
		     channel, bw);

	cl_calib_iq_lolc_write_data_file(cl_hw, calib_temperature, channel, bw, plan_bitmap);
	cl_calib_iq_lolc_write_report_file(cl_hw, calib_temperature, channel, bw, plan_bitmap);

	/* If all channels calibration is finished - write footer */
	if (!cl_hw->chip->is_calib_in_progress) {
		u16 lolc_error = cl_hw->calib_db->errors.lolc;

		if (lolc_error)
			cl_calib_common_write_error(cl_hw, FILE_PREFIX_LOLC, lolc_error);

		cl_calib_iq_write_footer(cl_hw, LOLC_FILE);
		cl_dbg_verbose(cl_hw, "IQ calibration finished");
	}
	/*
	 * Set the default status to FAIL, to ensure FW is actually changing the value,
	 * if the calibration succeeded.
	 */
	dcoc_iq_cfm->status = CALIB_FAIL;
}

int cl_calib_iq_rx_gain_report_write_version(struct cl_hw *cl_hw)
{
	return cl_calib_common_write_version(cl_hw,
					     &cl_hw->calib_db->file_flags.rx_gain_report,
					     FILE_PREFIX_RX_GAIN_REPORT, FILE_TITLE_RX_GAIN_REPORT,
					     VERSION_ID_IQ);
}

int cl_calib_iq_get_initial_gain_array_index(u8 chain, bool is_tx)
{
	if (is_tx)
		return chain ?
			WIFI_TX_CALIBRATION_TYPE_GAIN_LO_IQ_CH0_IDX :
			WIFI_TX_CALIBRATION_TYPE_GAIN_LO_IQ_CH1_IDX;
	else
		return chain ?
			WIFI_RX_CALIBRATION_TYPE_GAIN_IQ_CH0_IDX :
			WIFI_RX_CALIBRATION_TYPE_GAIN_IQ_CH1_IDX;
}

void cl_calib_iq_rx_gain_write_report_file(struct cl_hw *cl_hw,
					   struct cl_calib_params *calib_params)
{
	/* CH, BW, tx_ant, rx_ant, Init rx_gain, tx_gain, Init P2P, Final rx_gain, Final P2P */
	struct cl_iq_dcoc_report *report = &cl_hw->iq_dcoc_data_info.iq_dcoc_data->report;
	u32 channel = calib_params->channel;
	u8 bw = BW_TO_MHZ(calib_params->wifi_bw);
	u8 chain_tx = 0;
	u8 chain_rx = 0;
	u8 init_gain_index;
	u16 init_rx_gain = 0;
	u8 tx_gain = 0;
	u16 final_rx_gain = 0;
	u16 init_p2p = 0;
	u16 final_p2p = 0;
	struct cl_calib_chain calib_chain;
	struct cl_gain_report *gain_report_dma;
	struct cl_chip *chip = cl_hw->chip;

	if (cl_hw->calib_db->file_flags.rx_gain_report)
		cl_calib_iq_rx_gain_report_write_version(cl_hw);

	if (calib_params->wifi_mode_bmp & SET_CALIB_MODE_TX_ALL) {
		riu_chain_for_each(chain_tx) {
			gain_report_dma = &report->gain_tx[chain_tx];
			final_rx_gain = le16_to_cpu(gain_report_dma->rx_gain);
			final_p2p = le16_to_cpu(gain_report_dma->final_p2p);
			init_p2p = le16_to_cpu(gain_report_dma->initial_p2p);
			init_gain_index =
				cl_calib_iq_get_initial_gain_array_index(chain_tx, true);
			cl_dbg_trace(cl_hw, "CHAIN_TX[%u]: final_rx_gain = 0x%02X, final_p2p = %u, "
				     "init_p2p = %u, gain_quality[Q1] = %d\n",
				     chain_tx, final_rx_gain, final_p2p, init_p2p,
				     (s8)gain_report_dma->gain_quality);

			if (cl_hw->calib_iq_plan) {
				calib_chain = cl_hw->calib_iq_plan->tx_chain[chain_tx].calib_chain;
				tx_gain = calib_chain.initial_tx_gain;
				init_rx_gain = calib_chain.initial_rx_gain;
			} else {
				tx_gain = chip->conf->ci_calib_init_tx_gain[init_gain_index];
				init_rx_gain = chip->conf->ci_calib_init_rx_gain[init_gain_index];
			}

			cl_calib_iq_rx_gain_write_line(cl_hw, channel, bw,
						       chain_tx, OTHER_RIU_CHAIN(chain_tx),
						       init_rx_gain, tx_gain, init_p2p,
						       final_rx_gain, final_p2p);
		}
	}
	if (calib_params->wifi_mode_bmp & SET_CALIB_MODE_RX_ALL) {
		riu_chain_for_each(chain_rx) {
			gain_report_dma = &report->gain_rx[chain_rx];
			final_rx_gain = le16_to_cpu(gain_report_dma->rx_gain);
			final_p2p = le16_to_cpu(gain_report_dma->final_p2p);
			init_p2p = le16_to_cpu(gain_report_dma->initial_p2p);
			init_gain_index =
				cl_calib_iq_get_initial_gain_array_index(chain_tx, false);
			cl_dbg_trace(cl_hw, "CHAIN_RX[%u]: final_rx_gain = 0x%02X, final_p2p = %u, "
				     "init_p2p = %u, gain_quality[Q1] = %d\n",
				     chain_rx, final_rx_gain, final_p2p, init_p2p,
				     (s8)gain_report_dma->gain_quality);

			if (cl_hw->calib_iq_plan) {
				calib_chain = cl_hw->calib_iq_plan->rx_chain[chain_rx].calib_chain;
				tx_gain = calib_chain.initial_tx_gain;
				init_rx_gain = calib_chain.initial_rx_gain;
			} else {
				tx_gain = chip->conf->ci_calib_init_tx_gain[init_gain_index];
				init_rx_gain = chip->conf->ci_calib_init_rx_gain[init_gain_index];
			}

			cl_calib_iq_rx_gain_write_line(cl_hw, channel, bw,
						       OTHER_RIU_CHAIN(chain_rx),
						       chain_rx, init_rx_gain, tx_gain, init_p2p,
						       final_rx_gain, final_p2p);
		}
	}
}

int cl_calib_iq_tx_write_version(struct cl_hw *cl_hw)
{
	return cl_calib_common_write_version(cl_hw, &cl_hw->calib_db->file_flags.iq_tx,
					     FILE_PREFIX_IQ_TX, FILE_TITLE_IQ, VERSION_ID_IQ);
}

int cl_calib_iq_rx_write_version(struct cl_hw *cl_hw)
{
	return cl_calib_common_write_version(cl_hw, &cl_hw->calib_db->file_flags.iq_rx,
					     FILE_PREFIX_IQ_RX, FILE_TITLE_IQ, VERSION_ID_IQ);
}

int cl_calib_iq_tx_report_write_version(struct cl_hw *cl_hw)
{
	return cl_calib_common_write_version(cl_hw, &cl_hw->calib_db->file_flags.iq_tx_report,
					     FILE_PREFIX_IQ_TX_REPORT, FILE_TITLE_IQ_REPORT,
					     VERSION_ID_IQ);
}

int cl_calib_iq_rx_report_write_version(struct cl_hw *cl_hw)
{
	return cl_calib_common_write_version(cl_hw, &cl_hw->calib_db->file_flags.iq_rx_report,
					     FILE_PREFIX_IQ_RX_REPORT, FILE_TITLE_IQ_REPORT,
					     VERSION_ID_IQ);
}

int cl_calib_iq_lolc_write_version(struct cl_hw *cl_hw)
{
	return cl_calib_common_write_version(cl_hw, &cl_hw->calib_db->file_flags.lolc,
					     FILE_PREFIX_LOLC, FILE_TITLE_LOLC, VERSION_ID_IQ);
}

int cl_calib_iq_lolc_report_write_version(struct cl_hw *cl_hw)
{
	return cl_calib_common_write_version(cl_hw, &cl_hw->calib_db->file_flags.lolc_report,
					     FILE_PREFIX_LOLC_REPORT, FILE_TITLE_LOLC_REPORT,
					     VERSION_ID_IQ);
}

int cl_calib_iq_lolc_write_file(struct cl_hw *cl_hw, s32 *params)
{
	char filename[CL_PATH_MAX];
	char buf[CALIB_MAX_BUF];
	int len = 0;

	snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt", cl_config_dir, FILE_PREFIX_LOLC,
		 cl_hw->chip->idx);

	if (cl_hw->calib_db->file_flags.lolc)
		cl_calib_iq_lolc_write_version(cl_hw);

	len = snprintf(buf, sizeof(buf), "%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",
		       params[LOLC_CHANNEL], params[LOLC_BW],
		       params[LOLC_ANTENNA], params[LOLC_BAND],
		       params[LOLC_TEMPERATURE], params[LOLC_I], params[LOLC_Q]);

	return cl_file_open_and_write(filename, O_WRONLY | O_APPEND, buf, len);
}

int cl_calib_iq_lolc_report_write_file(struct cl_hw *cl_hw, s32 *params)
{
	char filename[CL_PATH_MAX];
	char buf[CALIB_MAX_BUF];
	int len = 0;

	snprintf(filename, sizeof(filename), "%s/calib/%s%u.txt", cl_config_dir,
		 FILE_PREFIX_LOLC_REPORT, cl_hw->chip->idx);

	if (cl_hw->calib_db->file_flags.lolc_report)
		cl_calib_iq_lolc_report_write_version(cl_hw);

	len = snprintf(buf, sizeof(buf), "%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",
		       params[LOLC_REPORT_CHANNEL], params[LOLC_REPORT_BW],
		       params[LOLC_REPORT_ANTENNA], params[LOLC_REPORT_BAND],
		       params[LOLC_REPORT_TEMPERATURE], params[LOLC_REPORT_ITERATIONS],
		       params[LOLC_REPORT_QUAL_DB]);

	return cl_file_open_and_write(filename, O_WRONLY | O_APPEND, buf, len);
}

void cl_calib_iq_get_tone_vector(struct cl_hw *cl_hw, __le16 *tone_vector)
{
	u8 tone = 0;
	u8 *vector_ptr = NULL;

	switch (cl_hw->bw) {
	case CHNL_BW_20:
		vector_ptr = cl_hw->conf->ci_calib_conf_tone_vector_20bw;
		break;
	case CHNL_BW_40:
		vector_ptr = cl_hw->conf->ci_calib_conf_tone_vector_40bw;
		break;
	case CHNL_BW_80:
		vector_ptr = cl_hw->conf->ci_calib_conf_tone_vector_80bw;
		break;
	case CHNL_BW_160:
		vector_ptr = cl_hw->conf->ci_calib_conf_tone_vector_160bw;
		break;
	default:
		vector_ptr = cl_hw->conf->ci_calib_conf_tone_vector_20bw;
		break;
	}

	for (tone = 0; tone < IQ_NUM_TONES_REQ; tone++)
		tone_vector[tone] = cpu_to_le16((u16)vector_ptr[tone]);
}

void cl_calib_iq_init_production(struct cl_hw *cl_hw)
{
	if (cl_calib_iq_calibration_needed(cl_hw))
		cl_calib_iq_init_calibration(cl_hw);
}
