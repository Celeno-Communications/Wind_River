// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_utils.h"
#include "cl_lcu.h"
#include "reg_lcu_common.h"
#include "reg_lcu_phy.h"
#include "reg_modem_gcu.h"
#include "reg_bt_controller.h"
#include "reg_usbc.h"
#include "reg_riu.h"
#include "cl_msg_tx.h"

static int cl_lcu_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "lcu usage:\n"
		 "-a : Configure BT LCU - [0:tx_samples|1:rx_samples_wo_calib|"
			"2:rx_samples_wt_calib].[0:end_buffer|1:cyclic].[0:lcu_en_end_iw_cmd|"
			"1:lcu_en_rxtx_en]\n"
		 "-b : Configure LCU RIU Out (for manual calibration)\n"
		 "-c : Configure and trigger LCU - [chain bitmap]."
			"[capture mode: 0-end buffer, 1-cyclic]."
			"[sample size: 0-narrow, 1-wide].[sample type: 0-9]"
			"[0:20P|1:20P_20S|2:40MHZ|3:80MHZ|4:160MHZ|].[agc_start].[agc_stop]\n"
		 "-r : Reset LCU\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static void cl_lcu_wait_for_end_buffer(struct cl_chip *chip, u32 end_address, u8 *buff)
{
	u32 eq_counter = 0, reg_val = 0, prev_val = 0;
	int res = -1;

	/*
	 * Loop until the reg value doesn't change for CONSECUTIVE_EQUAL_TH
	 * times in a row
	 */
	while (eq_counter < CONSECUTIVE_EQUAL_TH) {
		cpu_relax();
		reg_val = lcu_common_write_addr_get(chip);

		if (prev_val == reg_val)
			eq_counter++;
		else
			eq_counter = 0;

		prev_val = reg_val;
	}

	/*
	 * If the reg value reaches end_address - hysteresis -> the buffer
	 * is filled successfully
	 */
	if (reg_val >= end_address - FULL_BUFFER_HYST)
		res = 0;

	snprintf(buff, PAGE_SIZE, "%d", res);
	cl_dbg_chip_trace(chip, "reg_val = 0x%x\n", reg_val);
}

static void cl_lcu_config(struct cl_hw *cl_hw, u32 chain_bitmap, u32 capture_mode,
			  u32 end_address, u8 ch0_conf_size, u8 ch0_conf_type,
			  u8 sample_bw, u8 lcu_start_agc_cmd,
			  u8 lcu_stop_agc_cmd)
{
	struct cl_chip *chip = cl_hw->chip;

	/* Stop LCU */
	cl_lcu_stop(chip);
	/* Start LCU clk */
	modem_gcu_lcu_set(chip, 0x7007);
	/* BUF_START_ADDR */
	lcu_common_buf_start_addr_set(chip, CL_LCU_BUFFER_START_ADDRESS);
	/* BUF_END_ADDR - end of the buffer */
	lcu_common_buf_end_addr_set(chip, end_address);

	if (capture_mode != CAPTURE_MODE_END_BUFFER) {
		/* STOP_EXTRA_CYCLES */
		lcu_common_stop_extra_cycles_set(chip, 0xa);
		/* STOP_EXTRA_SAMPLES */
		lcu_common_stop_extra_samples_set(chip, 0xa);
	}

	/* CAPTURE_MODE - 1 cyclic 0 end buffer */
	lcu_common_capture_mode_set(chip, capture_mode);
	/* LCU_COMMON_VCI - label CH2 to 0 */
	lcu_common_vci_set(chip, 0);
	/* LCU_COMMON_CH2_CONF - set CH2 to narow with VCI */
	if (ch0_conf_size)
		lcu_common_ch_2_conf_set(chip, 0x5);
	else
		lcu_common_ch_2_conf_set(chip, 0x4);

	/*
	 * phy0 configuration
	 * LCU_CH0_STOP_EN - enable stop signalling
	 */
	lcu_phy_lcu_ch_0_stop_en_set(chip, 0x0);

	/* LCU_CH0_CONF - CH2 */
	lcu_phy_lcu_ch_0_conf_ch_0_size_setf(chip, ch0_conf_size);
	lcu_phy_lcu_ch_0_conf_ch_0_type_setf(chip, ch0_conf_type);

	/* LCU_CH0_CHAINS_BITMAP - number of streams */
	lcu_phy_lcu_ch_0_chains_bitmap_set(chip, chain_bitmap);

	/* LCU_CH0_EN - enable channel 2 */
	lcu_phy_lcu_ch_0_en_set(chip, 0x1);

	/* LCU_CH0_START - CH2 */
	lcu_phy_lcu_ch_0_start_set(chip, 0x1);

	/* LCU_COMMON_REC_CMD  ARM */
	lcu_common_rec_cmd_pack(chip, 0, 0, 1);

	/* LCU_RX_RIU_OUT_EN sample BW */
	lcu_phy_lcu_rx_riu_out_sel_rx_riu_out_sel_setf(chip, sample_bw);

	/* RIU_LCU_TRIG_START_CONF AGC command trigger LCU start */
	riu_lcu_trig_start_conf_lcu_start_trig_cmd_setf(chip, lcu_start_agc_cmd);

	/* RIU_LCU_TRIG_START_CONF AGC command trigger LCU stop */
	riu_lcu_trig_stop_conf_lcu_stop_trig_cmd_setf(chip, lcu_stop_agc_cmd);

	/* RIU_LCU_TRIG_DLY_CONF start and stop delay of 1 cycle */
	riu_lcu_trig_dly_conf_set(chip, 0x10001);

	/* LCU_CH0_STOP_EN Configure LCU stop to manual or external trigger */
	if (lcu_stop_agc_cmd > 0)
		lcu_phy_lcu_ch_0_stop_en_ch_0_ext_stop_en_setf(chip, 0x1);
	else
		lcu_phy_lcu_ch_0_stop_en_ch_0_ext_stop_en_setf(chip, 0x0);

	/* LCU_CH0_STRT_EN Configure LCU start to manual or external trigger */
	if (lcu_start_agc_cmd > 0)
		lcu_phy_lcu_ch_0_start_en_ch_0_ext_strt_en_setf(chip, 0x1);
	else
		lcu_phy_lcu_ch_0_start_en_ch_0_ext_strt_en_setf(chip, 0x0);

	/* LCU_COMMON_REC_CMD  start */
	lcu_common_rec_cmd_pack(chip, 0, 1, 0);
}

void cl_lcu_bt_config_get(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_lcu_bt_conf *bt_conf = (struct cl_lcu_bt_conf *)
					 &cl_hw->dbginfo.buf->u.dump.general_data.la_conf;

	if (chip->conf->ce_bt_mode == BT_MODE_OFF)
		return;

	bt_conf->cont_modem_subch_en = bt_controller_cont_modem_subch_en_reg_get(chip);
	bt_conf->cont_subch_index_reg[0] = bt_controller_cont_subch_index_reg_0_get(chip);
	bt_conf->cont_subch_index_reg[1] = bt_controller_cont_subch_index_reg_1_get(chip);
	bt_conf->modem_subch_index_reg[0] = bt_controller_mod_subch_index_reg_0_get(chip);
	bt_conf->modem_subch_index_reg[1] = bt_controller_mod_subch_index_reg_1_get(chip);
	bt_conf->cont_ch_mask_index = bt_controller_ch_mask_index_reg_get(chip);
	bt_conf->cont_ch_mask_reg[0] = bt_controller_ch_mask_reg_1_get(chip);
	bt_conf->cont_ch_mask_reg[1] = bt_controller_ch_mask_reg_2_get(chip);
	bt_conf->cont_ch_mask_reg[2] = bt_controller_ch_mask_reg_3_get(chip);
	bt_conf->modem_ch_mask_index = 0;
	bt_conf->modem_ch_mask_reg[0] = 0xFFFFFFFF;
	bt_conf->modem_ch_mask_reg[1] = 0xFFFFFFFF;
	bt_conf->modem_ch_mask_reg[2] = 0x03FFFFFF;
}

void cl_lcu_usbc_config_get(struct cl_hw *cl_hw)
{
	u8 *p_la_conf = (u8 *)&cl_hw->dbginfo.buf->u.dump.general_data.la_conf;
	u32 *p_usbc_dbg_sel = (u32 *)(p_la_conf + sizeof(struct la_conf_tag) - sizeof(u32));

	if (!IS_USB_BUS_TYPE(cl_hw->chip))
		return;

	*p_usbc_dbg_sel = usbc_gdbglspmux_hst_logic_analyzer_trace_getf(cl_hw->chip);
}

static void cl_lcu_config_riu_out(struct cl_hw *cl_hw, u8 sample_bw)
{
	cl_lcu_config(cl_hw, 0x1, CAPTURE_MODE_CYCLIC,
		      CL_LCU_BUFFER_END_ADDRESS, LCU_CH0_CONF_SAMPLE_SIZE_NARROW, 2,
		      sample_bw, 0, 0);
}

static void cl_lcu_config_and_trigger(struct cl_hw *cl_hw, u32 chain_bitmap,
				      u8 capture_mode, u8 sample_size, u8 sample_type,
				      u8 sample_bw, u8 lcu_start_agc_cmd,
				      u8 lcu_stop_agc_cmd, u8 *buff)
{
	if (chain_bitmap > 0x3) {
		cl_dbg_err(cl_hw, "Illegal chain_bitmap 0x%x!\n", chain_bitmap);
		return;
	}

	if (capture_mode > 1) {
		cl_dbg_err(cl_hw, "Capture mode valid values are 0-1\n");
		return;
	}

	if (sample_size > 1) {
		cl_dbg_err(cl_hw, "Sample size valid values are 0-1\n");
		return;
	}

	if (sample_type > 9) {
		cl_dbg_err(cl_hw, "Sample type valid values are 0-9\n");
		return;
	}

	if (sample_type == 7 && sample_size == 0) {
		cl_dbg_err(cl_hw, "Sample type 7 must be used with wide sample size\n");
		return;
	}

	if (sample_bw >= 5) {
		cl_dbg_err(cl_hw, "Invalid sample_bw\n");
		return;
	}

	cl_lcu_config(cl_hw, chain_bitmap, capture_mode,
		      CL_LCU_BUFFER_END_ADDRESS, sample_size, sample_type, sample_bw,
		      lcu_start_agc_cmd, lcu_stop_agc_cmd);

	/*
	 * Wait for end of buffer only if capture mode is configured to end
	 * buffer.
	 */
	if (!capture_mode)
		cl_lcu_wait_for_end_buffer(cl_hw->chip, CL_LCU_BUFFER_END_ADDRESS, buff);
}

static void cl_bt_lcu_config(struct cl_chip *chip, enum cl_lcu_bt_mode mode,
			     u8 capture_mode, enum cl_lcu_bt_trigger_mode trigger_mode)
{
	/* Stop LCU */
	cl_lcu_stop(chip);

	/* Buffer start address */
	lcu_common_buf_start_addr_set(chip, CL_LCU_BUFFER_START_ADDRESS);

	/* Buffer end address */
	lcu_common_buf_end_addr_set(chip, CL_LCU_BUFFER_END_ADDRESS);

	if (capture_mode) /* cyclic */
		lcu_common_capture_mode_set(chip, 0x1);
	else /* end buffer */
		lcu_common_capture_mode_set(chip, 0x0);

	/* LCU_COMMON_VCI */
	lcu_common_vci_set(chip, 0x00030000);

	/* LCU_COMMON_CH_4_CONF */
	lcu_common_ch_4_conf_pack(chip, 1, 1, 0);

	/* LCU_COMMON_LCU_BT_EN */
	lcu_common_lcu_bt_en_set(chip, 0x0);

	/* LCU_COMMON_LCU_BT_START */
	lcu_common_lcu_bt_start_set(chip, 0x0);

	/* LCU_COMMON_LCU_BT_CH_VALID */
	lcu_common_lcu_bt_ch_valid_set(chip, 0x00001);

	/* LCU_COMMON_LCU_BT_CTPREV_EN */
	lcu_common_lcu_bt_ctprev_en_set(chip, 0x0);

	/* CONT_MODEM_SUBCH_EN_REG */
	bt_controller_cont_modem_subch_en_reg_set(chip, 0x00000c0f);

	/* CONT_SUBCH_INDEX_REG_0 */
	bt_controller_cont_subch_index_reg_0_set(chip, 0x050A0702);

	/* CONT_SUBCH_INDEX_REG_1 */
	bt_controller_cont_subch_index_reg_1_set(chip, 0x00000000);

	/* MOD_SUBCH_INDEX_REG_0 */
	bt_controller_mod_subch_index_reg_0_set(chip, 0x0);

	/* MOD_SUBCH_INDEX_REG_1 */
	if (mode == CL_LCU_TX_IQ_SAMPLES)
		bt_controller_mod_subch_index_reg_1_set(chip, 0x00001918);
	else if (mode == CL_LCU_RX_IQ_SAMPLES_WO_CALIB)
		bt_controller_mod_subch_index_reg_1_set(chip, 0x00001312);
	else /* CL_LCU_RX_IQ_SAMPLES_WT_CALIB */
		bt_controller_mod_subch_index_reg_1_set(chip, 0x00001514);

	/* CH_MASK_INDEX_REG */
	bt_controller_ch_mask_index_reg_set(chip, 0x00000000);

	/* CH_MASK_REG_1 */
	if (mode == CL_LCU_TX_IQ_SAMPLES && trigger_mode == CL_LCU_EN_RXTX_EN)
		bt_controller_ch_mask_reg_1_set(chip, 0x100);/* Tx + external trigger */
	else if ((mode == CL_LCU_RX_IQ_SAMPLES_WO_CALIB ||
		  mode == CL_LCU_RX_IQ_SAMPLES_WT_CALIB) && trigger_mode == CL_LCU_EN_RXTX_EN)
		bt_controller_ch_mask_reg_1_set(chip, 0x80);/* RX + ext trigger */
	else
		bt_controller_ch_mask_reg_1_set(chip, 0x0);/* LCU enabled at end of iw cmd */

	/* CH_MASK_REG_2 */
	bt_controller_ch_mask_reg_2_set(chip, 0x0);

	/* CH_MASK_REG_3 */
	bt_controller_ch_mask_reg_3_set(chip, 0xffFFFFFF);

	/* LCU_BT_START_EN, start trigger enable (by pattern 1 or by ext trigger 2) */
	lcu_common_lcu_bt_start_en_set(chip, 1);

	/* Trigger based on specific pattern */
	if (mode == CL_LCU_TX_IQ_SAMPLES && trigger_mode == CL_LCU_EN_RXTX_EN) {
		/* Tx + external trigger (TX EN)*/
		lcu_common_lcu_bt_start_ptrn_reg_0_set(chip, 0x100);
		lcu_common_lcu_bt_start_ptrn_reg_1_set(chip, 0x0000000);
		lcu_common_lcu_bt_start_ptrn_mask_reg_0_set(chip, 0x100);
		lcu_common_lcu_bt_start_ptrn_mask_reg_1_set(chip, 0x0000000);
	} else if ((mode == CL_LCU_RX_IQ_SAMPLES_WO_CALIB ||
		  mode == CL_LCU_RX_IQ_SAMPLES_WT_CALIB) && trigger_mode == CL_LCU_EN_RXTX_EN) {
		/* RX + ext trigger (RX EN) */
		lcu_common_lcu_bt_start_ptrn_reg_0_set(chip, 0x80);
		lcu_common_lcu_bt_start_ptrn_reg_1_set(chip, 0x0000000);
		lcu_common_lcu_bt_start_ptrn_mask_reg_0_set(chip, 0x80);
		lcu_common_lcu_bt_start_ptrn_mask_reg_1_set(chip, 0x0000000);
	} else if (mode == CL_LCU_TX_IQ_SAMPLES && trigger_mode == CL_LCU_EN_RX_ADC_TX_PA_EN) {
		/* TX + ext trigger (PA EN)*/
		lcu_common_lcu_bt_start_ptrn_reg_0_set(chip, 0x10000000);
		lcu_common_lcu_bt_start_ptrn_reg_1_set(chip, 0x0000000);
		lcu_common_lcu_bt_start_ptrn_mask_reg_0_set(chip, 0x10000000);
		lcu_common_lcu_bt_start_ptrn_mask_reg_1_set(chip, 0x0000000);
	} else if ((mode == CL_LCU_RX_IQ_SAMPLES_WO_CALIB ||
		  mode == CL_LCU_RX_IQ_SAMPLES_WT_CALIB) && trigger_mode ==
		   CL_LCU_EN_RX_ADC_TX_PA_EN) {
		/* RX + ext trigger (ADC EN)*/
		lcu_common_lcu_bt_start_ptrn_reg_0_set(chip, 0x0);
		lcu_common_lcu_bt_start_ptrn_reg_1_set(chip, 0x80);
		lcu_common_lcu_bt_start_ptrn_mask_reg_0_set(chip, 0x0);
		lcu_common_lcu_bt_start_ptrn_mask_reg_1_set(chip, 0x80);
	} else {
	/* LCU enabled at end of iw cmd */
		lcu_common_lcu_bt_start_ptrn_reg_0_set(chip, 0x0);
		lcu_common_lcu_bt_start_ptrn_reg_1_set(chip, 0x0);
		lcu_common_lcu_bt_start_ptrn_mask_reg_0_set(chip, 0x0);
		lcu_common_lcu_bt_start_ptrn_mask_reg_1_set(chip, 0x0);
	}

	/* LCU_BT_START_PTRN_REG_2 */
	lcu_common_lcu_bt_start_ptrn_reg_2_set(chip, 0x0000000);

	/* LCU_BT_START_PTRN_MASK_REG_2 */
	lcu_common_lcu_bt_start_ptrn_mask_reg_2_set(chip, 0x0000000);

	/* LCU_BT_PTRN_MATCH_SEL */
	lcu_common_lcu_bt_ptrn_match_sel_set(chip, 0x0000000);

	if (trigger_mode == CL_LCU_EN_END_IW_CMD) {
		/* LCU_COMMON_LCU_BT_EN */
		lcu_common_lcu_bt_en_set(chip, 0x1);

		/* LCU_COMMON_REC_CMD */
		lcu_common_rec_cmd_pack(chip, 0, 0, 1);

		/* LCU_COMMON_REC_CMD */
		lcu_common_rec_cmd_pack(chip, 0, 1, 0);
	} else {
		/* LCU_COMMON_REC_CMD */
		lcu_common_rec_cmd_pack(chip, 0, 0, 1);

		/* LCU_COMMON_LCU_BT_EN */
		lcu_common_lcu_bt_en_set(chip, 0x1);
	}
}

static void
cl_bt_lcu_config_and_trigger(struct cl_hw *cl_hw,
			     enum cl_lcu_bt_mode mode,
			     u8 capture_mode,
			     enum cl_lcu_bt_trigger_mode trigger_mode,
			     u8 *buff)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 param[TEST_MODE_PARAM_MAX + 1] = {0};

	if (mode >= CL_LCU_BT_MODE_MAX) {
		cl_dbg_err(cl_hw, "Invalid mode = %u\n", mode);
		return;
	}

	if (capture_mode > 0x1) {
		cl_dbg_err(cl_hw, "Invalid capture_mode = %u\n", capture_mode);
		return;
	}

	if (trigger_mode >= CL_LCU_BT_TRIGGER_MAX) {
		cl_dbg_err(cl_hw, "Invalid trigger_mode = %u\n", trigger_mode);
		return;
	}

	cl_bt_lcu_config(chip, mode, capture_mode, trigger_mode);

	/*
	 * Wait for end of buffer only if capture mode is configured to end
	 * buffer.
	 */
	if (!capture_mode) {
		cl_lcu_wait_for_end_buffer(chip, CL_LCU_BUFFER_END_ADDRESS, buff);
		param[0] = DBG_TEST_MODE_FORCE_TRIGGER;
		cl_msg_tx_dbg_test_mode(cl_hw, param);
	}
}

int cl_lcu_cli(struct cl_hw *cl_hw, struct cli_params *cli_params,
	       char *ret_buf, u16 *ret_buf_len)
{
	u32 *params = (u32 *)cli_params->params;

	switch (cli_params->option) {
	case 'a':
		if (cli_params->num_params != 3)
			goto err_num_of_arg;

		cl_bt_lcu_config_and_trigger(cl_hw, (enum cl_lcu_bt_mode)params[0], (u8)params[1],
					     (enum cl_lcu_bt_trigger_mode)params[2], ret_buf);
		*ret_buf_len = strlen(ret_buf);
		return 0;
	case 'b':
		cl_lcu_config_riu_out(cl_hw, (u8)params[0]);
		return 0;
	case 'c':
		if (cli_params->num_params != 7)
			goto err_num_of_arg;

		cl_lcu_config_and_trigger(cl_hw, (u32)params[0], (u8)params[1],
					  (u8)params[2], (u8)params[3], (u8)params[4],
					  (u8)params[5], (u8)params[6], ret_buf);
		*ret_buf_len = strlen(ret_buf);
		return 1;
	case 'r':
		cl_lcu_stop(cl_hw->chip);
		cl_lcu_apply_config(cl_hw->chip);
		return 0;
	case '?':
		return cl_lcu_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		return -1;
	}

err_num_of_arg:
	cl_dbg_err(cl_hw, "Wrong number of arguments\n");

	return -1;
}
