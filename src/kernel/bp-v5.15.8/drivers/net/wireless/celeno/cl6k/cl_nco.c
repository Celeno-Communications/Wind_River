// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_utils.h"
#include "cl_nco.h"
#include "reg_riu.h"
#include "reg_modem_gcu.h"

#define CL_NCO_EXP_TBL_SIZE 80
#define CL_NCO_EXP_TBL_Q 29

static u32 CL_NCO_INIT_EXP_10_Q29[CL_NCO_EXP_TBL_SIZE] = {
	0x20000000, 0x1C8520AF, 0x196B230B, 0x16A77DEB, 0x1430CD75, 0x11FEB33C, 0x1009B9CF,
	0x0E4B3B63, 0x0CBD4B3F, 0x0B5AA19C, 0x0A1E89B1, 0x0904D1BD, 0x0809BCC3, 0x0729F5DA,
	0x066284D6, 0x05B0C439, 0x05125831, 0x04852697, 0x04074FCB, 0x03972853, 0x03333333,
	0x02DA1CDE, 0x028AB6B4, 0x0243F2FE, 0x0204E158, 0x01CCAB86, 0x019A9294, 0x016DEC56,
	0x01462120, 0x0122A9C2, 0x01030DC5, 0x00E6E1C6, 0x00CDC613, 0x00B76562, 0x00A373AE,
	0x0091AD38, 0x0081D59F, 0x0073B70F, 0x00672194, 0x005BEA6E, 0x0051EB85, 0x004902E3,
	0x00411245, 0x0039FEB3, 0x0033B022, 0x002E1127, 0x00290EA8, 0x002497A2, 0x00209CE9,
	0x001D10FA, 0x0019E7C7, 0x00171693, 0x001493CE, 0x001256F0, 0x0010585E, 0x000E9152,
	0x000CFBC3, 0x000B924F, 0x000A5028, 0x0009310B, 0x00083127, 0x00074D17, 0x000681D3,
	0x0005CCAC, 0x00052B36, 0x00049B51, 0x00041B11, 0x0003A8C4, 0x000342E4, 0x0002E819,
	0x0002972E, 0x00024F0E, 0x00020EC8, 0x0001D57E, 0x0001A270, 0x000174EF, 0x00014C60,
	0x0001283B, 0x00010804, 0x0000EB4E
};

static int cl_nco_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "nco usage:\n"
		 "-c : NCO enable for calibration - [NCO0 channels bitmap]."
			"[NCO1 channels bitmap].[enable/disable - 0/1]\n"
		 "-e : NCO enable - [NCO0 channels bitmap]."
			"[NCO1 channels bitmap].[enable/disable - 0/1]\n"
		 "-n : NCO configure - [NCO# - valid: 0/1].[frequency - 0.5 Khz]."
			"[amplitude]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static int cl_nco_ctrl_calibration_configure(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u8 nco_en[MAX_ANTENNAS] = {0};
	u8 nco0_ch_bitmap = cli_params->params[0];
	u8 nco1_ch_bitmap = cli_params->params[1];
	u8 enable = cli_params->params[2];
	int i = 0;

	if (nco0_ch_bitmap > 0x3) {
		cl_dbg_err(cl_hw, "Invalid nco0_ch_bitmap %u - should be 0-3 (0b11)\n",
			   nco0_ch_bitmap);
		return -EINVAL;
	}

	if (nco1_ch_bitmap > 0x3) {
		cl_dbg_err(cl_hw, "Invalid nco1_ch_bitmap %u - should be 0-3 (0b11)\n",
			   nco1_ch_bitmap);
		return -EINVAL;
	}

	for (i = 0; i < MAX_ANTENNAS; i++)
		nco_en[i] |= (((nco0_ch_bitmap >> i) & 1) | (((nco1_ch_bitmap >> i) & 1) << 1));

	riu_nco_ctrl_pack(cl_hw->chip, 0, 0, 0, 0, 0, nco_en[1], nco_en[0], !!enable);

	return 0;
}

static void cl_nco_ctrl_disable(struct cl_hw *cl_hw)
{
	riu_rwnxstaticconfig_mode_setf(cl_hw->chip, RIU_RWNXSTATICCONFIG_MODE_RST);
	riu_rwnxstaticconfig_activeant_setf(cl_hw->chip, RIU_RWNXSTATICCONFIG_ACTIVEANT_RST);
}

static void cl_nco_ctrl_enable(struct cl_hw *cl_hw, u8 enable, u32 act_ants)
{
	riu_rwnxstaticconfig_mode_setf(cl_hw->chip, enable);
	riu_rwnxstaticconfig_activeant_setf(cl_hw->chip, act_ants);
}

static int cl_nco_ctrl_configure(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u8 nco_en[MAX_ANTENNAS] = {0};
	u8 nco0_ch_bitmap = cli_params->params[0];
	u8 nco1_ch_bitmap = cli_params->params[1];
	u8 enable = cli_params->params[2];
	u32 act_ants = 0;
	int i = 0;

	if (nco0_ch_bitmap > 0x3) {
		cl_dbg_err(cl_hw, "Invalid nco0_ch_bitmap %u - should be 0-3 (0b11)\n",
			   nco0_ch_bitmap);
		return -EINVAL;
	}

	if (nco1_ch_bitmap > 0x3) {
		cl_dbg_err(cl_hw, "Invalid nco1_ch_bitmap %u - should be 0-3 (0b11)\n",
			   nco1_ch_bitmap);
		return -EINVAL;
	}

	for (i = 0; i < MAX_ANTENNAS; i++) {
		nco_en[i] |= (((nco0_ch_bitmap >> i) & 1) | (((nco1_ch_bitmap >> i) & 1) << 1));
		if (nco_en[i] != 0)
			act_ants |= (0x1 << i);
	}

	if (enable == 0)
		cl_nco_ctrl_disable(cl_hw);
	else
		cl_nco_ctrl_enable(cl_hw, enable, act_ants);

	riu_nco_ctrl_pack(cl_hw->chip, 0, 0, 0, 0, 0, nco_en[1], nco_en[0], !!enable);

	return 0;
}

static int cl_nco_configure(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	struct cl_chip *chip = cl_hw->chip;
	s32 nco_idx = cli_params->params[0];
	s64 frequency = cli_params->params[1];
	s16 amplitude = cli_params->params[2];
	s64 bw_mhz = BW_TO_MHZ(modem_gcu_riu_clk_bw_riu_afe_clk_bw_getf(chip));
	/* RIU_NCO_INC = round( { 2^25 / (MODEM_GCU. RIU_CLK_BW.AFE_CLK_BW) } * freq) */
	u32 nco_inc_val = (u32)(div64_s64(BIT(25) * frequency, bw_mhz * 4 * 1000));
	/* RIU_NCO_INIT I/Q = (2^13-1) * (10^( nco_amp [dBFS] / 20)) */
	u64 nco_init_val = (u32)(BIT(13) - 1);

	if (abs(frequency) >= BIT(25)) {
		cl_dbg_err(cl_hw, "Invalid frequency %lld\n", frequency);
		return -EINVAL;
	}

	if (amplitude > 0) {
		cl_dbg_err(cl_hw, "Invalid amplitude %d. Should be in range %d-0 !\n",
			   amplitude, S16_MIN);
		return -EINVAL;
	}

	/* Avoid of out of bound access */
	amplitude = max(amplitude, (s16)-(CL_NCO_EXP_TBL_SIZE - 1));

	nco_init_val *= CL_NCO_INIT_EXP_10_Q29[abs(amplitude)];
	nco_init_val >>= CL_NCO_EXP_TBL_Q;

	if (nco_idx == 0) {
		riu_nco_inc_0_set(chip, nco_inc_val);
		riu_nco_init_0_nco_init_q_0_setf(chip, nco_init_val);
		riu_nco_init_0_nco_init_i_0_setf(chip, nco_init_val);
	} else if (nco_idx == 1) {
		riu_nco_inc_1_set(chip, nco_inc_val);
		riu_nco_init_1_nco_init_q_1_setf(chip, nco_init_val);
		riu_nco_init_1_nco_init_i_1_setf(chip, nco_init_val);
	} else {
		cl_dbg_err(cl_hw, "Invalid nco_idx %d\n", nco_idx);
		return -EINVAL;
	}

	return 0;
}

int cl_nco_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	switch (cli_params->option) {
	case 'c':
		if (cli_params->num_params != 3)
			goto err_num_of_arg;

		return cl_nco_ctrl_calibration_configure(cl_hw, cli_params);
	case 'e':
		if (cli_params->num_params != 3)
			goto err_num_of_arg;

		return cl_nco_ctrl_configure(cl_hw, cli_params);
	case 'n':
		if (cli_params->num_params != 3)
			goto err_num_of_arg;

		return cl_nco_configure(cl_hw, cli_params);
	case '?':
		return cl_nco_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		return -EINVAL;
	}

err_num_of_arg:
	cl_dbg_err(cl_hw, "Wrong number of arguments\n");

	return -EINVAL;
}
