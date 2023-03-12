// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/list.h>
#include "cl_hw.h"
#include "cl_noise.h"
#include "reg_riu.h"
#include "cl_utils.h"

#define NOISE_LOWER_LIMIT -100
#define NOISE_UPPER_LIMIT -30
/* Range is -100dBm to -30dBm */
#define NOISE_SCALE_RANGE  (NOISE_UPPER_LIMIT - NOISE_LOWER_LIMIT + 1)
#define NOISE_MAX_SAMPLES  U8_MAX
#define MAX_20M_SUB_BAND   8
#define MAX_SEC_BW_CNT     3
#define MAX_ANT_PER_REG    2

static s8 cl_noise_process_sample(u32 sample, u8 cnt)
{
	s8 val = (s8)((sample >> (8 * cnt)) & 0xff);

	if (val < NOISE_LOWER_LIMIT)
		val = NOISE_LOWER_LIMIT;
	else if (val > NOISE_UPPER_LIMIT)
		val = NOISE_UPPER_LIMIT;

	return val;
}

static bool cl_noise_is_hist_line_empty(u8 *hist, u8 cnt)
{
	u8 i;

	for (i = 0; i < cnt; i++)
		if (hist[i] != 0)
			return false;

	return true;
}

static int cl_noise_print_hist(struct cl_hw *cl_hw, bool nasp_stats)
{
	struct cl_noise_db *noise_db = &cl_hw->noise_db;
	struct cl_noise_reg *reg = NULL;
	u8 hist[NOISE_SCALE_RANGE][MAX_ANTENNAS] = { { 0 } };
	u8 num_antennas = cl_hw->num_antennas;
	s8 val_stat;
	u8 i = 0, j = 0;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	if (list_empty(&noise_db->reg_list))
		return 0;

	list_for_each_entry(reg, &noise_db->reg_list, list) {
		for (i = 0; i < min_t(u8, num_antennas, MAX_ANT_PER_REG); i++) {
			if (nasp_stats)
				val_stat = cl_noise_process_sample(reg->nasp_prim20_per_ant, i);
			else
				val_stat = cl_noise_process_sample(reg->np_prim20_per_ant, i);

			hist[(val_stat * -1) + NOISE_UPPER_LIMIT][i]++;
		}
	}

	cl_snprintf(&buf, &len, &buf_size,
		    "Noise %sstrength histogram (dBm):\n", nasp_stats ? "and signal " : "");

	cl_snprintf(&buf, &len, &buf_size, "------------------");
	for (j = 0; j < num_antennas; j++)
		cl_snprintf(&buf, &len, &buf_size, "-------");

	cl_snprintf(&buf, &len, &buf_size, "\n| Noise Strength ");

	for (j = 0; j < num_antennas; j++)
		cl_snprintf(&buf, &len, &buf_size, "| Ant%u ", j);

	cl_snprintf(&buf, &len, &buf_size, "|\n|----------------");

	for (j = 0; j < num_antennas; j++)
		cl_snprintf(&buf, &len, &buf_size, "+------");

	cl_snprintf(&buf, &len, &buf_size, "|\n");

	for (i = 0; i < NOISE_SCALE_RANGE; i++) {
		if (cl_noise_is_hist_line_empty(hist[i], num_antennas))
			continue;

		cl_snprintf(&buf, &len, &buf_size, "|%9d       ", -i + NOISE_UPPER_LIMIT);
		for (j = 0; j < num_antennas; j++)
			cl_snprintf(&buf, &len, &buf_size, "| %3u  ", hist[i][j]);

		cl_snprintf(&buf, &len, &buf_size, "|\n");
	}

	cl_snprintf(&buf, &len, &buf_size, "|----------------");
	for (j = 0; j < num_antennas; j++)
		cl_snprintf(&buf, &len, &buf_size, "+------");

	cl_snprintf(&buf, &len, &buf_size, "|\n");

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_noise_print_hist_per_channel(struct cl_hw *cl_hw,
					   bool nasp_stats)
{
	struct cl_noise_db *noise_db = &cl_hw->noise_db;
	struct cl_noise_reg *reg = NULL;
	u8 ch_bw = cl_hw->conf->ce_channel_bandwidth;
	u8 ch_cnt = 1 << ch_bw;
	u8 hist[NOISE_SCALE_RANGE][MAX_20M_SUB_BAND] = { { 0 } };
	s8 val1, val2;
	u8 i = 0, j = 0;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	if (list_empty(&noise_db->reg_list))
		return 0;

	list_for_each_entry(reg, &noise_db->reg_list, list) {
		for (i = 0; i < min_t(u8, ch_cnt, MAX_ANT_PER_REG); i++) {
			if (nasp_stats) {
				val1 = cl_noise_process_sample(reg->nasp_sub20_per_chn, i);

				if (ch_bw == CHNL_BW_160)
					val2 = cl_noise_process_sample(reg->nasp_sub20_per_chn2, i);
			} else {
				val1 = cl_noise_process_sample(reg->np_sub20_per_chn, i);

				if (ch_bw == CHNL_BW_160)
					val2 = cl_noise_process_sample(reg->np_sub20_per_chn2, i);
			}

			hist[(val1 * -1) + NOISE_UPPER_LIMIT][i]++;
			if (ch_bw == CHNL_BW_160)
				hist[(val2 * -1) + NOISE_UPPER_LIMIT][i + MAX_ANT_PER_REG]++;
		}
	}

	cl_snprintf(&buf, &len, &buf_size,
		    "Noise %sstrength per 20 Mhz channel histogram ant %u (dBm):\n"
		    "------------------",
		    nasp_stats ? "and signal " : "", noise_db->active_ant);

	for (j = 0; j < ch_cnt; j++)
		cl_snprintf(&buf, &len, &buf_size, "--------");

	cl_snprintf(&buf, &len, &buf_size, "\n| Noise Strength ");
	for (j = 0; j < ch_cnt; j++)
		cl_snprintf(&buf, &len, &buf_size, "| Chan%u ", j);

	cl_snprintf(&buf, &len, &buf_size, "|\n|----------------");

	for (j = 0; j < ch_cnt; j++)
		cl_snprintf(&buf, &len, &buf_size, "+-------");

	cl_snprintf(&buf, &len, &buf_size, "|\n");

	for (i = 0; i < NOISE_SCALE_RANGE; i++) {
		if (cl_noise_is_hist_line_empty(hist[i], ch_cnt))
			continue;

		cl_snprintf(&buf, &len, &buf_size, "|%9d       ", -i + NOISE_UPPER_LIMIT);

		for (j = 0; j < ch_cnt; j++)
			cl_snprintf(&buf, &len, &buf_size, "| %3u   ", hist[i][j]);

		cl_snprintf(&buf, &len, &buf_size, "|\n");
	}

	cl_snprintf(&buf, &len, &buf_size, "|----------------");

	for (j = 0; j < ch_cnt; j++)
		cl_snprintf(&buf, &len, &buf_size, "+-------");

	cl_snprintf(&buf, &len, &buf_size, "|\n");

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_noise_print_hist_dens(struct cl_hw *cl_hw, bool nasp_stats)
{
	struct cl_noise_db *noise_db = &cl_hw->noise_db;
	struct cl_noise_reg *reg = NULL;
	u8 hist[NOISE_SCALE_RANGE][MAX_SEC_BW_CNT] = { { 0 } };
	u8 ch_bw = cl_hw->conf->ce_channel_bandwidth;
	s8 val;
	u8 i = 0, j = 0;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	if (list_empty(&noise_db->reg_list) || ch_bw == 0)
		return 0;

	list_for_each_entry(reg, &noise_db->reg_list, list) {
		for (i = 0; i < ch_bw; i++) {
			if (nasp_stats)
				val = cl_noise_process_sample(reg->nasp_sec20_dens_per_ant, i);
			else
				val = cl_noise_process_sample(reg->np_sec20_dens_per_ant, i);

			hist[(val * -1) + NOISE_UPPER_LIMIT][i]++;
		}
	}

	cl_snprintf(&buf, &len, &buf_size,
		    "Noise %spower density histogram ant %u (dBm/20Mhz):\n",
		    nasp_stats ? "and signal " : "", noise_db->active_ant);

	cl_snprintf(&buf, &len, &buf_size, "-----------------");

	for (j = 0; j < ch_bw; j++)
		cl_snprintf(&buf, &len, &buf_size, "--------");

	cl_snprintf(&buf, &len, &buf_size, "\n| Noise Density ");

	for (j = 0; j < ch_bw; j++)
		cl_snprintf(&buf, &len, &buf_size, "| SEC%u ", 20 * (1 << j));

	cl_snprintf(&buf, &len, &buf_size, "|\n|---------------");
	for (j = 0; j < ch_bw; j++)
		cl_snprintf(&buf, &len, &buf_size, "+-------");

	cl_snprintf(&buf, &len, &buf_size, "|\n");

	for (i = 0; i < NOISE_SCALE_RANGE; i++) {
		if (cl_noise_is_hist_line_empty(hist[i], ch_bw))
			continue;

		cl_snprintf(&buf, &len, &buf_size, "|%9d      ", -i + NOISE_UPPER_LIMIT);
		for (j = 0; j < ch_bw; j++)
			cl_snprintf(&buf, &len, &buf_size, "| %3u   ", hist[i][j]);

		cl_snprintf(&buf, &len, &buf_size, "|\n");
	}

	cl_snprintf(&buf, &len, &buf_size, "|---------------");
	for (j = 0; j < ch_bw; j++)
		cl_snprintf(&buf, &len, &buf_size, "+-------");

	cl_snprintf(&buf, &len, &buf_size, "|\n");

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_noise_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "stats usage:\n"
		 "-a : Set antenna\n"
		 "-b : En/Dis noise histogram [0-stop, max samples-255]\n"
		 "-c : Print 20Mhz channels noise power\n"
		 "-d : Print 20Mhz channels noise and signal power\n"
		 "-e : Print noise density histogram\n"
		 "-f : Print noise and signal density histogram\n"
		 "-g : Print noise power histogram\n"
		 "-h : Print noise and signal power histogram\n"
		 "-r : Reset histogram\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static void cl_noise_set_ant(struct cl_hw *cl_hw, u8 active_ant)
{
	struct cl_noise_db *noise_db = &cl_hw->noise_db;
	u8 max_ant = cl_hw->num_antennas - 1;

	if (noise_db->sample_cnt != 0) {
		pr_warn("Can't set antenna during statistics collection\n");
		return;
	}

	if (active_ant > max_ant) {
		pr_err("Invalid antennas configuration. Should be 0-%u!\n", max_ant);
		return;
	}

	if (active_ant == noise_db->active_ant) {
		pr_warn("Ant %u already set!\n", active_ant);
		return;
	}

	/* Antenna is different now so clear all stats */
	cl_noise_close(cl_hw);

	riu_rwnxagcccactrl_cca_main_ant_sel_setf(cl_hw->chip, active_ant);

	noise_db->active_ant = active_ant;

	pr_debug("Antenna selected : %u\n", active_ant);
}

void cl_noise_init(struct cl_hw *cl_hw)
{
	struct cl_noise_db *noise_db = &cl_hw->noise_db;

	INIT_LIST_HEAD(&noise_db->reg_list);
}

void cl_noise_close(struct cl_hw *cl_hw)
{
	struct cl_noise_db *noise_db = &cl_hw->noise_db;
	struct cl_noise_reg *elem = NULL;
	struct cl_noise_reg *tmp = NULL;

	list_for_each_entry_safe(elem, tmp, &noise_db->reg_list, list) {
		list_del(&elem->list);
		kfree(elem);
	}
}

void cl_noise_maintenance(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_noise_db *noise_db = &cl_hw->noise_db;
	struct cl_noise_reg *reg = NULL;
	u8 ch_bw = cl_hw->conf->ce_channel_bandwidth;

	if (noise_db->sample_cnt == 0)
		return;

	reg = kzalloc(sizeof(*reg), GFP_KERNEL);

	if (!reg)
		return;

	/*collect statistics */
	reg->np_prim20_per_ant = riu_agcinbdpow_20_pnoisestat_get(chip);
	reg->np_sub20_per_chn = riu_agcinbdpownoiseper_20_stat_0_get(chip);
	reg->np_sec20_dens_per_ant = riu_agcinbdpowsecnoisestat_get(chip);
	reg->nasp_prim20_per_ant = riu_inbdpowformac_0_get(chip);
	reg->nasp_sub20_per_chn = riu_inbdpowformac_3_get(chip);
	reg->nasp_sec20_dens_per_ant = riu_inbdpowformac_2_get(chip);

	if (ch_bw == CHNL_BW_160) {
		reg->np_sub20_per_chn2 = riu_agcinbdpownoiseper_20_stat_1_get(chip);
		reg->nasp_sub20_per_chn2 = riu_inbdpowformac_4_get(chip);
	}

	if (cl_hw->num_antennas > MAX_ANT_PER_REG) {
		reg->np_prim20_per_ant2 = riu_agcinbdpow_20_pnoisestat_2_get(chip);
		reg->nasp_prim20_per_ant2 = riu_inbdpowformac_1_get(chip);
	}

	list_add(&reg->list, &noise_db->reg_list);

	noise_db->sample_cnt--;

	if (noise_db->sample_cnt == 0)
		pr_debug("record done\n");
}

int cl_noise_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	struct cl_noise_db *noise_db = &cl_hw->noise_db;
	bool set_ant = false;
	bool hist_enable = false;
	bool hist_per_channel = false;
	bool hist_mac_per_channel = false;
	bool hist_dens = false;
	bool hist_mac_dens = false;
	bool hist_pwr_print = false;
	bool hist_mac_pwr_print = false;
	bool hist_reset = false;
	u32 param = (u32)cli_params->params[0];
	u32 expected_params = -1;

	switch (cli_params->option) {
	case 'a':
		set_ant = true;
		expected_params = 1;
		break;
	case 'b':
		hist_enable = true;
		expected_params = 1;
		break;
	case 'c':
		hist_per_channel = true;
		expected_params = 0;
		break;
	case 'd':
		hist_mac_per_channel = true;
		expected_params = 0;
		break;
	case 'e':
		hist_dens = true;
		expected_params = 0;
		break;
	case 'f':
		hist_mac_dens = true;
		expected_params = 0;
		break;
	case 'g':
		hist_pwr_print = true;
		expected_params = 0;
		break;
	case 'h':
		hist_mac_pwr_print = true;
		expected_params = 0;
		break;
	case 'r':
		hist_reset = true;
		expected_params = 0;
		break;
	case '?':
		return cl_noise_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (set_ant) {
		cl_noise_set_ant(cl_hw, (u8)param);
		return 0;
	}

	if (hist_enable) {
		if (param > NOISE_MAX_SAMPLES) {
			pr_err("Error! Max samples should be < %u\n", NOISE_MAX_SAMPLES);
		} else {
			pr_debug("%s record histogram\n", param ? "Start" : "Stop");
			noise_db->sample_cnt = param;
		}

		return 0;
	}

	if (hist_per_channel)
		return cl_noise_print_hist_per_channel(cl_hw, false);

	if (hist_mac_per_channel)
		return cl_noise_print_hist_per_channel(cl_hw, true);

	if (hist_dens)
		return cl_noise_print_hist_dens(cl_hw, false);

	if (hist_mac_dens)
		return cl_noise_print_hist_dens(cl_hw, true);

	if (hist_pwr_print)
		return cl_noise_print_hist(cl_hw, false);

	if (hist_mac_pwr_print)
		return cl_noise_print_hist(cl_hw, true);

	if (hist_reset) {
		pr_debug("Clear histogram\n");
		cl_noise_close(cl_hw);
		return 0;
	}

out_err:
	return -EIO;
}

