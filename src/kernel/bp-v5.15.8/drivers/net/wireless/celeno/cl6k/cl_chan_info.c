// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_chan_info.h"
#include "cl_utils.h"
#include "chip.h"
#include "cl_math.h"
#include "cl_band.h"
#include "string.h"
#include "cl_channel.h"
#include "file.h"

static struct ieee80211_regdomain cl_regdom_24g = {
	.n_reg_rules = 2,
	.alpha2 = "99",
	.reg_rules = {
		REG_RULE(2412 - 10, 2472 + 10, 40, 6, 20, 0),
		REG_RULE(2484 - 10, 2484 + 10, 20, 6, 20, 0),
	}
};

static struct ieee80211_regdomain cl_regdom_5g = {
	.n_reg_rules = 1,
	.alpha2 = "99",
	.reg_rules = {
		REG_RULE(5150 - 10, 5850 + 10, 80, 6, 30, 0),
	}
};

static struct ieee80211_regdomain cl_regdom_6g = {
	.n_reg_rules = 1,
	.alpha2 = "99",
	.reg_rules = {
		REG_RULE(5935 - 10, 7115 + 10, 80, 6, 30, 0),
	}
};

static inline s32 convert_str_int_q2(s8 *str)
{
	s32 x, y;

	if (!str)
		return 0;
	if (sscanf(str, "%d.%2d", &x, &y) != 2)
		return 0;
	if (!strstr(str, "."))
		return x * 4;
	if (y < 10 && (*(strstr(str, ".") + 1) != '0'))
		y *= 10;
	return (x * 100 + y) * 4 / 100;
}

static int cl_parse_reg_domain(struct cl_hw *cl_hw, char **str)
{
	/* Check if current line contains "FCC" or "ETSI" */
	char *token = strsep(str, "\n");

	if (!token)
		goto err;

	if (strstr(token, "FCC")) {
		cl_hw->channel_info.standard = CL_STANDARD_FCC;
		cl_dbg_info(cl_hw, "Standard = FCC\n");
		return 0;
	}

	if (strstr(token, "ETSI")) {
		cl_hw->channel_info.standard = CL_STANDARD_ETSI;
		cl_dbg_info(cl_hw, "Standard = ETSI\n");
		return 0;
	}

err:
	cl_dbg_err(cl_hw, "Illegal regulatory domain\n");
	cl_hw->channel_info.standard = CL_STANDARD_NONE;
	return -1;
}

#define MAX_CC_STR 4
#define MAX_BW_STR 8

static bool cl_parse_channel_info_txt(struct cl_hw *cl_hw)
{
	/*
	 * Example of country information in channel_info.txt:
	 *
	 * [EU (European Union)ETSI]
	 * 2.4GHz/20MHz: 2412(1,20) 2417(2,20) 2422(3,20) 2427(4,20) 2432(5,20) 2437(6,20)
	 *               2442(7,20) 2447(8,20) 2452(9,20) 2457(10,20) 2462(11,20) 2467(12,20)
	 *               2472(13,20)
	 * 2.4GHz/40MHz: 2422(1,20) 2427(2,20) 2432(3,20) 2437(4,20) 2442(5,20) 2447(6,20)
	 *               2452(7,20) 2457(8,20) 2462(9,20) 2467(10,20) 2472(11,20)
	 * 5.2GHz/20MHz: 5180(36,23) 5200(40,23) 5220(44,23) 5240(48,23) 5260(52,23) 5280(56,23)
	 *               5300(60,23) 5320(64,23) 5500(100,30) 5520(104,30) 5540(108,30)
	 *               5560(112,30)5580(116,30) 5600(120,30) 5620(124,30) 5640(128,30)
	 *               5660(132,30) 5680(136,30) 5700(140,30)
	 * 5.2GHz/40MHz: 5180(36,23) 5200(40,23) 5220(44,23) 5240(48,23) 5260(52,23) 5280(56,23)
	 *               5300(60,23) 5310(64,23) 5510(100,30) 5510(104,30) 5550(108,30)
	 *               5550(112,30) 5590(116,30) 5590(120,30) 5630(124,30) 5630(128,30)
	 *               5670(132,30) 5670(136,30)
	 * 5.2GHz/80MHz: 5180(36,23) 5200(40,23) 5220(44,23) 5240(48,23) 5260(52,23) 5280(56,23)
	 *               5300(60,23) 5310(64,23) 5510(100,30) 5510(104,30) 5550(108,30)
	 *               5550(112,30) 5590(116,30) 5590(120,30) 5630(124,30) 5630(128,30)
	 * 5.2GHz/160MHz: 5180(36,23) 5200(40,23) 5220(44,23) 5240(48,23) 5260(52,23) 5280(56,23)
	 *                5300(60,23) 5310(64,23) 5510(100,30) 5510(104,30) 5550(108,30)
	 *                5550(112,30) 5590(116,30) 5590(120,30) 5630(124,30) 5630(128,30)
	 */

	struct cl_channel_info *channel_info = &cl_hw->channel_info;
	char *buf = NULL, *ptr = NULL;
	char cc_str[MAX_CC_STR] = {0};
	char bw_str[MAX_BW_STR] = {0};
	size_t size;
	u8 bw, bw_mhz, bw_max, max_power, channel, i;

	/* Read channel_info.txt into buf */
	size = cl_file_open_and_read(cl_hw->chip, "channel_info.txt", &buf);

	if (!buf)
		return false;

	/* Jump to the correct country in the file */
	snprintf(cc_str, sizeof(cc_str), "[%s", cl_hw->chip->conf->ce_country_code);
	ptr = strstr(buf, cc_str);
	if (!ptr)
		goto out;

	if (cl_parse_reg_domain(cl_hw, &ptr))
		goto out;

	/* Jump to the relevant band */
	if (cl_band_is_24g(cl_hw)) {
		bw_max = CHNL_BW_40;
		ptr = strstr(ptr, "2.4GHz");
	} else if (cl_band_is_5g(cl_hw)) {
		ptr = strstr(ptr, "5.2GHz");
		bw_max = CHNL_BW_160;
	} else {
		ptr = strstr(ptr, "6GHz");
		bw_max = CHNL_BW_160;
	}

	for (bw = 0; bw <= bw_max; bw++) {
		if (!ptr)
			goto out;

		i = 0;

		/* Jump to relevant bandwidth */
		bw_mhz = BW_TO_MHZ(bw);
		snprintf(bw_str, sizeof(bw_str), "%uMHz:", bw_mhz);
		ptr = strstr(ptr, bw_str);

		/* Iterate until end of line and parse (channel, max_power) */
		while (ptr && (ptr + 1) && (*(ptr + 1) != '\n')) {
			ptr = strstr(ptr, "(");
			if (!ptr)
				goto out;

			if (sscanf(ptr, "(%hhu,%hhu)", &channel, &max_power) != 2)
				goto out;

			if (!cl_channel_is_valid(cl_hw, channel) ||
			    i == cl_channel_num(cl_hw))
				goto out;

			channel_info->channels[bw][i].channel = channel;
			channel_info->channels[bw][i].max_power_q2 = max_power << 2;
			channel_info->channels[bw][i].country_max_power_q2 = max_power << 2;

			i++;
			ptr = strstr(ptr, ")");
		}
	}

	kfree(buf);
	return true;

out:
	kfree(buf);
	return false;
}

static bool cl_is_parsing_success(struct cl_hw *cl_hw)
{
	/* Check that there is at least one channel in any bw */
	u8 bw;
	u8 max_bw = BAND_IS_5G_6G(cl_hw) ? CHNL_BW_160 : CHNL_BW_40;

	for (bw = 0; bw <= max_bw; bw++)
		if (!cl_hw->channel_info.channels[bw][0].channel)
			return false;

	return true;
}

static void cl_chan_info_set_max_bw_6g(struct cl_hw *cl_hw)
{
	u8 i, bw, bw_cnt, channel, channel_gap;
	struct cl_chan_info *chan_info;

	for (bw = 0; bw < CHNL_BW_MAX; bw++) {
		chan_info = cl_hw->channel_info.channels[bw];
		bw_cnt = 0;

		for (i = 0; i < NUM_CHANNELS_6G; i++) {
			channel = chan_info[i].channel;

			if (channel == 0)
				break;

			channel_gap = channel - START_CHAN_IDX_6G;

			/*
			 * Verify that we don't combine together channels
			 * from different 80MHz sections
			 */
			if ((channel_gap % CL_160MHZ_CH_GAP) == 0)
				bw_cnt = 0;

			if (i > 0)
				bw_cnt++;

			/* Verify that we don't make illegal 80MHz combination */
			if ((channel_gap % CL_80MHZ_CH_GAP == 0) && bw_cnt == 3)
				bw_cnt = 0;

			/* Verify that we don't make illegal 40MHz combination */
			if ((channel_gap % CL_40MHZ_CH_GAP == 0) && bw_cnt == 1)
				bw_cnt = 0;

			if ((((bw_cnt + 1) % CL_160MHZ_HOP) == 0) && bw == CHNL_BW_160) {
				chan_info[i].max_bw = CHNL_BW_160;
				chan_info[i - 1].max_bw = CHNL_BW_160;
				chan_info[i - 2].max_bw = CHNL_BW_160;
				chan_info[i - 3].max_bw = CHNL_BW_160;
				chan_info[i - 4].max_bw = CHNL_BW_160;
				chan_info[i - 5].max_bw = CHNL_BW_160;
				chan_info[i - 6].max_bw = CHNL_BW_160;
				chan_info[i - 7].max_bw = CHNL_BW_160;
			} else if ((((bw_cnt + 1) % CL_80MHZ_HOP) == 0) && (bw == CHNL_BW_80)) {
				chan_info[i].max_bw = CHNL_BW_80;
				chan_info[i - 1].max_bw = CHNL_BW_80;
				chan_info[i - 2].max_bw = CHNL_BW_80;
				chan_info[i - 3].max_bw = CHNL_BW_80;
			} else if ((((bw_cnt + 1) % CL_40MHZ_HOP) == 0) && (bw >= CHNL_BW_40)) {
				chan_info[i].max_bw = CHNL_BW_40;
				chan_info[i - 1].max_bw = CHNL_BW_40;
			} else {
				chan_info[i].max_bw = CHNL_BW_20;
			}
		}
	}
}

static void cl_chan_info_set_max_bw_5g(struct cl_hw *cl_hw)
{
	u8 i, bw, bw_cnt, channel, channel_gap;
	struct cl_chan_info *chan_info;

	for (bw = 0; bw < CHNL_BW_MAX; bw++) {
		chan_info = cl_hw->channel_info.channels[bw];
		bw_cnt = 0;

		for (i = 0; i < NUM_CHANNELS_5G; i++) {
			channel = chan_info[i].channel;

			if (channel == 0)
				break;

			if (channel < 149)
				channel_gap = channel - 36;
			else
				channel_gap = channel - 149;

			/*
			 * Verify that we don't combine together channels from
			 * different 80MHz sections
			 * (i.e. 36-48 can be combined into 80MHz channels, unlike 40-52)
			 */
			if ((channel_gap % CL_160MHZ_CH_GAP) == 0)
				bw_cnt = 0;

			/* Check if 20MHz channels can be combined into 40MHz or 80MHz channels */
			if (i > 0) {
				/*
				 * Verify that we don't combine together unsecutive channels
				 * (like 36 and 44 when 40 is missing)
				 */
				if ((chan_info[i].channel - chan_info[i - 1].channel) >
				    CL_20MHZ_CH_GAP)
					bw_cnt = 0;
				else
					bw_cnt++;
			}

			/* Verify that we don't make illegal 80MHz combination (like 44-56) */
			if ((channel_gap % CL_80MHZ_CH_GAP == 0) && bw_cnt == 3)
				bw_cnt = 0;

			/* Verify that we don't make illegal 40MHz combination (like 40-44) */
			if ((channel_gap % CL_40MHZ_CH_GAP == 0) && bw_cnt == 1)
				bw_cnt = 0;

			if ((((bw_cnt + 1) % CL_160MHZ_HOP) == 0) && bw == CHNL_BW_160) {
				chan_info[i].max_bw = CHNL_BW_160;
				chan_info[i - 1].max_bw = CHNL_BW_160;
				chan_info[i - 2].max_bw = CHNL_BW_160;
				chan_info[i - 3].max_bw = CHNL_BW_160;
				chan_info[i - 4].max_bw = CHNL_BW_160;
				chan_info[i - 5].max_bw = CHNL_BW_160;
				chan_info[i - 6].max_bw = CHNL_BW_160;
				chan_info[i - 7].max_bw = CHNL_BW_160;
			} else if ((((bw_cnt + 1) % CL_80MHZ_HOP) == 0) && bw == CHNL_BW_80) {
				chan_info[i].max_bw = CHNL_BW_80;
				chan_info[i - 1].max_bw = CHNL_BW_80;
				chan_info[i - 2].max_bw = CHNL_BW_80;
				chan_info[i - 3].max_bw = CHNL_BW_80;
			} else if ((((bw_cnt + 1) % CL_40MHZ_HOP) == 0) && bw >= CHNL_BW_40) {
				chan_info[i].max_bw = CHNL_BW_40;
				chan_info[i - 1].max_bw = CHNL_BW_40;
			} else {
				chan_info[i].max_bw = CHNL_BW_20;
			}
		}
	}
}

static void cl_chan_info_set_max_bw_24g(struct cl_hw *cl_hw)
{
	u8 i, bw, channel;
	struct cl_chan_info *chan_info;

	for (bw = 0; bw < CHNL_BW_80; bw++) {
		chan_info = cl_hw->channel_info.channels[bw];

		for (i = 0; i < NUM_CHANNELS_24G; i++) {
			channel = chan_info[i].channel;

			if (channel == 0)
				break;

			if (channel < 14)
				chan_info[i].max_bw = CHNL_BW_40;
			else
				chan_info[i].max_bw = CHNL_BW_20;
		}
	}
}

static void cl_chan_info_set_max_bw(struct cl_hw *cl_hw)
{
	if (cl_band_is_6g(cl_hw))
		cl_chan_info_set_max_bw_6g(cl_hw);
	else if (cl_band_is_5g(cl_hw))
		cl_chan_info_set_max_bw_5g(cl_hw);
	else
		cl_chan_info_set_max_bw_24g(cl_hw);
}

static void cl_chan_info_dbg(struct cl_hw *cl_hw)
{
	struct cl_chan_info *chan_info;
	u32 max_power_integer, max_power_fraction;
	u8 i, j;

	for (i = 0; i < CHNL_BW_MAX; i++) {
		cl_dbg_info(cl_hw, "Bandwidth = %uMHz\n", BW_TO_MHZ(i));
		for (j = 0; j < cl_channel_num(cl_hw); j++) {
			chan_info = &cl_hw->channel_info.channels[i][j];

			if (chan_info->channel == 0)
				continue;

			max_power_integer = (chan_info->max_power_q2 / 4);
			max_power_fraction =
				(100 * (chan_info->max_power_q2 - 4 * max_power_integer) / 4);

			cl_dbg_info(cl_hw, "Channel = %u, max EIRP = %3u.%02u, bw = %uMHz\n",
				    chan_info->channel, max_power_integer,
				    max_power_fraction, BW_TO_MHZ(chan_info->max_bw));
		}
	}
}

/* Band 6G - default power */
#define UNII_5_POW_Q2     (27 << 2)
#define UNII_6_POW_Q2     (27 << 2)
#define UNII_7_POW_Q2     (27 << 2)
#define UNII_8_POW_Q2     (27 << 2)

/* Band 5G - default power */
#define UNII_1_POW_Q2     (22 << 2)
#define UNII_2_POW_Q2     (27 << 2)
#define UNII_2_EXT_POW_Q2 (27 << 2)
#define UNII_3_POW_Q2     (27 << 2)

/* Band 2.4G - default power */
#define BAND_24G_POW_Q2   (36 << 2)

static void cl_fill_channel_info(struct cl_hw *cl_hw, u8 bw, u8 ch_idx, u8 channel,
				 u8 country_max_power_q2, u8 max_power_q2)
{
	struct cl_channel_info *channel_info = &cl_hw->channel_info;

	channel_info->channels[bw][ch_idx].channel = channel;
	channel_info->channels[bw][ch_idx].country_max_power_q2 = country_max_power_q2;
	channel_info->channels[bw][ch_idx].max_power_q2 = max_power_q2;
}

static void cl_set_default_channel_info_6g(struct cl_hw *cl_hw)
{
	u8 i, j, k;

	for (i = 0; i < CHNL_BW_MAX; i++) {
		k = 0;

		/* Ch2 is a special case */
		cl_fill_channel_info(cl_hw, i, k, 2, UNII_5_POW_Q2, UNII_5_POW_Q2);
		k++;

		for (j = START_CHAN_IDX_UNII5; j <= END_CHAN_IDX_UNII5; j += 4) {
			cl_fill_channel_info(cl_hw, i, k, j, UNII_5_POW_Q2, UNII_5_POW_Q2);
			k++;
		}

		for (j = START_CHAN_IDX_UNII6; j <= END_CHAN_IDX_UNII6; j += 4) {
			cl_fill_channel_info(cl_hw, i, k, j, UNII_6_POW_Q2, UNII_6_POW_Q2);
			k++;
		}

		for (j = START_CHAN_IDX_UNII7; j <= END_CHAN_IDX_UNII7; j += 4) {
			cl_fill_channel_info(cl_hw, i, k, j, UNII_7_POW_Q2, UNII_7_POW_Q2);
			k++;
		}

		for (j = START_CHAN_IDX_UNII8; j <= END_CHAN_IDX_UNII8; j += 4) {
			/* Channel 233 is valid only in 20MHz */
			if (i != CHNL_BW_20 && j == END_CHAN_IDX_UNII8)
				break;

			cl_fill_channel_info(cl_hw, i, k, j, UNII_8_POW_Q2, UNII_8_POW_Q2);
			k++;
		}
	}
}

static void cl_set_default_channel_info_5g(struct cl_hw *cl_hw)
{
	u8 i, j, k;

	for (i = 0; i < CHNL_BW_MAX; i++) {
		k = 0;

		for (j = 36; j <= 48; j += 4) {
			cl_fill_channel_info(cl_hw, i, k, j, UNII_1_POW_Q2, UNII_1_POW_Q2);
			k++;
		}

		for (j = 52; j <= 64; j += 4) {
			cl_fill_channel_info(cl_hw, i, k, j, UNII_2_POW_Q2, UNII_2_POW_Q2);
			k++;
		}

		for (j = 100; j <= 144; j += 4) {
			/* 160MHz is supported only in channel 36 - 64 and 100 - 128 */
			if (i == CHNL_BW_160 && j == 132)
				return;

			cl_fill_channel_info(cl_hw, i, k, j, UNII_2_EXT_POW_Q2, UNII_2_EXT_POW_Q2);
			k++;
		}

		for (j = 149; j <= 165; j += 4) {
			/* Channel 165 is valid only in 20MHz */
			if (i != CHNL_BW_20 && j == 165)
				break;

			cl_fill_channel_info(cl_hw, i, k, j, UNII_3_POW_Q2, UNII_3_POW_Q2);
			k++;
		}
	}
}

static void cl_set_default_channel_info_24g(struct cl_hw *cl_hw)
{
	u8 i, j;

	for (i = 0; i <= CHNL_BW_40; i++)
		for (j = 0; j < 13; j++)
			cl_fill_channel_info(cl_hw, i, j, j + 1, BAND_24G_POW_Q2, BAND_24G_POW_Q2);
}

static void cl_set_default_channel_info(struct cl_hw *cl_hw)
{
	struct cl_channel_info *channel_info = &cl_hw->channel_info;

	memset(channel_info->channels, 0, sizeof(channel_info->channels));

	channel_info->standard = CL_STANDARD_FCC;

	if (cl_band_is_6g(cl_hw))
		cl_set_default_channel_info_6g(cl_hw);
	else if (cl_band_is_5g(cl_hw))
		cl_set_default_channel_info_5g(cl_hw);
	else
		cl_set_default_channel_info_24g(cl_hw);
}

static u8 cl_regulatory_domain_max_power(struct cl_hw *cl_hw, int idx)
{
	u8 bw = 0;
	u8 max_power = 0;
	struct cl_channel_info *chan_info = &cl_hw->channel_info;

	for (bw = CHNL_BW_20; bw < CHNL_BW_MAX; bw++) {
		u8 power = chan_info->channels[bw][idx].country_max_power_q2;

		if (max_power < power)
			max_power = power;
	}

	/* Translate from country_power (.25dBm) to max_power (1dBm) */
	return (max_power >> 2);
}

static int cl_regulatory_domain_update_rule(struct cl_hw *cl_hw, int freq, int power)
{
	struct ieee80211_regdomain *rd = cl_hw->channel_info.rd;
	struct ieee80211_reg_rule *reg_rule = &rd->reg_rules[rd->n_reg_rules - 1];
	struct ieee80211_power_rule *power_rule = &reg_rule->power_rule;

	reg_rule->freq_range.end_freq_khz = MHZ_TO_KHZ(freq + 10);
	if (power_rule->max_eirp < DBM_TO_MBM(power))
		power_rule->max_eirp = DBM_TO_MBM(power);

	return (reg_rule->freq_range.end_freq_khz -
		reg_rule->freq_range.start_freq_khz);
}

static void cl_regulatory_domain_add_rule(struct cl_hw *cl_hw, int freq, int max_power, u8 bw)
{
	struct ieee80211_regdomain *rd = cl_hw->channel_info.rd;
	struct ieee80211_reg_rule *reg_rule = &rd->reg_rules[rd->n_reg_rules];
	struct ieee80211_freq_range *freq_range = &reg_rule->freq_range;
	struct ieee80211_power_rule *power_rule = &reg_rule->power_rule;

	freq_range->start_freq_khz = MHZ_TO_KHZ(freq - 10);
	freq_range->end_freq_khz = MHZ_TO_KHZ(freq + 10);
	freq_range->max_bandwidth_khz = BW_TO_KHZ(bw);

	power_rule->max_eirp = DBM_TO_MBM(max_power);
	power_rule->max_antenna_gain = DBI_TO_MBI(3);

	rd->n_reg_rules++;
}

static void cl_regulatory_domain_set(struct cl_hw *cl_hw)
{
	int j = 0;
	int diff = 0;
	int power = 0, prev_power = 0;
	u8 bw = 0, prev_bw = 0;
	int freq = 0, prev_freq = 0;
	u8 chan = 0;
	struct ieee80211_regdomain *rd = cl_hw->channel_info.rd;

	memcpy(rd->alpha2, cl_hw->chip->conf->ce_country_code, 2);

	if (cl_hw->channel_info.standard == CL_STANDARD_FCC)
		rd->dfs_region = NL80211_DFS_FCC;
	else if (cl_hw->channel_info.standard == CL_STANDARD_ETSI)
		rd->dfs_region = NL80211_DFS_ETSI;
	else
		rd->dfs_region = NL80211_DFS_UNSET;

	for (j = 0; j < cl_channel_num(cl_hw); j++) {
		chan = cl_hw->channel_info.channels[CHNL_BW_20][j].channel;
		if (!chan)
			continue;
		power = cl_regulatory_domain_max_power(cl_hw, j);
		bw = cl_chan_info_get_max_bw(cl_hw, chan);
		freq = ieee80211_channel_to_frequency(chan, cl_hw->nl_band);
		if (freq - prev_freq > 20 ||
		    (prev_power != power && diff >= BW_TO_KHZ(bw)) ||
		    prev_bw != bw) {
			cl_regulatory_domain_add_rule(cl_hw, freq, power, bw);
			diff = 0;
		} else {
			diff = cl_regulatory_domain_update_rule(cl_hw, freq, power);
		}

		prev_freq = freq;
		prev_power = power;
		prev_bw = bw;
	}
}

/*
 * cl_hardware_power_table_update: Applies individual regulatory table entry
 *   Inputs: cl_hw      - pointer to cl_hw
 *           bw_mhz     - current bandwidth in MHz
 *           chan_start - match channels greater or equal to chan_start
 *           chan_end   - match channels less than chan_end
 *           reg_pwr    - ensure channel_info.channels[bw][ch_idx].max_power does not exceed this
 *   Output: updated channel_info.channels[bw][ch_idx].max_power
 *           and channel_info.channels[bw][ch_idx].max_total_power
 *           on all channels that match specified range
 */
static void cl_hardware_power_table_update(struct cl_hw *cl_hw, u8 bw_mhz,
					   u8 chan_start, u8 chan_end, u8 pwr_q2)
{
	struct cl_chan_info *chan_info = NULL;
	u8 bw = 0;
	u8 ch_idx = 0;
	bool ch_found = false;
	bool is_24g = cl_band_is_24g(cl_hw);

	if (bw_mhz == 20 || bw_mhz == 40 || (!is_24g && (bw_mhz == 80 || bw_mhz == 160))) {
		bw = MHZ_TO_BW(bw_mhz);
	} else {
		cl_dbg_err(cl_hw, "Invalid bw %u\n", bw_mhz);
		return;
	}

	/* Iterate through all cl_channels[bw][ch_idx] - to find all matches */
	for (ch_idx = 0; ch_idx < cl_channel_num(cl_hw); ch_idx++) {
		chan_info = &cl_hw->channel_info.channels[bw][ch_idx];

		if (chan_start <= chan_info->channel && chan_info->channel < chan_end) {
			ch_found = true;

			/*
			 * Max-Power =
			 * minimum beteen hardware_power_table and country code definition
			 */
			chan_info->max_power_q2 = min(pwr_q2, chan_info->max_power_q2);
			chan_info->hardware_max_power_q2 = pwr_q2;
		}
	}

	if (!ch_found)
		cl_dbg_info(cl_hw, "Skipping invalid channel range: %u - %u\n",
			    chan_start, chan_end);
}

/*
 * cl_hardware_power_table_parse():
 * Iterate through hardware power table entries and apply each one.
 * Expected format:
 *     bw1(chan1=reg_pwr1;chan2=reg_pwr2;...)#bw2(chan3=reg_pwr3;chan4=reg_pwr4;...) ...
 * Example:
 *     20(36=22.0;40=22.75;149=21.75)#40(36=22.5;40=23.0;149=21.75)#80(36=21.75;40=21.5;149=22.25)
 */
static void cl_hardware_power_table_parse(struct cl_hw *cl_hw)
{
	s8 *table_str = NULL;
	s8 *channel_str = NULL;
	s8 *bw_set = NULL;
	s8 *out_tok = NULL;
	s8 *saveptr1 = NULL;
	s8 *saveptr2 = NULL;
	s8 in_reg_pwr[16] = {0};
	u8 bw_mhz = 0;
	u8 chan_start = 0;
	u8 chan_end = 0;
	u8 curr_pwr_q2 = 0;
	u8 next_pwr_q2 = 0;

	if (strlen(cl_hw->conf->ce_hardware_power_table) == 0)
		return; /* Not configured */

	table_str = kzalloc(CL_MAX_STR_BUFFER_SIZE / 2, GFP_KERNEL);
	if (!table_str)
		return;

	channel_str = kzalloc(CL_MAX_STR_BUFFER_SIZE / 2, GFP_KERNEL);
	if (!channel_str) {
		kfree(table_str);
		cl_dbg_err(cl_hw, "Failed to allocate channel_str\n");
		return;
	}

	strncpy(table_str,
		cl_hw->conf->ce_hardware_power_table,
		(CL_MAX_STR_BUFFER_SIZE / 2) - 1);

	/* Iterate through all bandwidth sets included in table_str */
	bw_set = cl_strtok_r(table_str, "#", &saveptr1);
	while (bw_set) {
		if (sscanf(bw_set, "%hhu(%s)", &bw_mhz, channel_str) != 2) {
			bw_set = cl_strtok_r(NULL, "#", &saveptr1);
			continue;
		}

		/* Iterate through each channel in this bandwidth set */
		chan_start = 0;
		chan_end = 0;
		curr_pwr_q2 = 0;
		next_pwr_q2 = 0;
		out_tok = cl_strtok_r(channel_str, ";", &saveptr2);

		while (out_tok) {
			if (sscanf(out_tok, "%hhu=%s", &chan_end, in_reg_pwr) == 2) {
				next_pwr_q2 = convert_str_int_q2(in_reg_pwr);

				/* Apply regulatory table rule. Skip initial case */
				if (curr_pwr_q2 != 0 && chan_start != 0)
					cl_hardware_power_table_update(cl_hw, bw_mhz, chan_start,
								       chan_end, curr_pwr_q2);

				/* Prepare next iteration */
				chan_start = chan_end;
				curr_pwr_q2 = next_pwr_q2;
			}
			out_tok = cl_strtok_r(NULL, ";", &saveptr2);
		}

		/* Handle last channel case */
		if (next_pwr_q2 != 0 && chan_start != 0) {
			u8 chan_end;

			if (cl_band_is_6g(cl_hw))
				chan_end = 234;
			else if (cl_band_is_5g(cl_hw))
				chan_end = 166;
			else
				chan_end = 15;

			cl_hardware_power_table_update(cl_hw, bw_mhz, chan_start,
						       chan_end, curr_pwr_q2);
		}

		bw_set = cl_strtok_r(NULL, "#", &saveptr1);
	}

	kfree(table_str);
	kfree(channel_str);
}

void cl_chan_info_init(struct cl_hw *cl_hw)
{
	struct cl_channel_info *channel_info = &cl_hw->channel_info;

	channel_info->use_channel_info = !cl_hw->chip->conf->ce_production_mode;

	if (channel_info->use_channel_info) {
		cl_hw->channel_info.rd = kzalloc(sizeof(*cl_hw->channel_info.rd) +
						 NL80211_MAX_SUPP_REG_RULES *
						 sizeof(struct ieee80211_reg_rule),
						 GFP_KERNEL);

		if (!cl_hw->channel_info.rd) {
			cl_dbg_err(cl_hw, "memory allocation failed!\n");
			return;
		}

		if (!cl_parse_channel_info_txt(cl_hw) || !cl_is_parsing_success(cl_hw)) {
			CL_DBG_WARNING(cl_hw, "Error parsing channel_info.txt. Using default!\n");
			cl_set_default_channel_info(cl_hw);
		}

		cl_chan_info_set_max_bw(cl_hw);
		cl_chan_info_dbg(cl_hw);
		cl_regulatory_domain_set(cl_hw);
	} else {
		cl_set_default_channel_info(cl_hw);

		if (cl_band_is_6g(cl_hw))
			cl_hw->channel_info.rd = &cl_regdom_6g;
		else if (cl_band_is_5g(cl_hw))
			cl_hw->channel_info.rd = &cl_regdom_5g;
		else
			cl_hw->channel_info.rd = &cl_regdom_24g;
	}

	cl_hardware_power_table_parse(cl_hw);
}

void cl_chan_info_deinit(struct cl_hw *cl_hw)
{
	if (cl_hw->channel_info.rd &&
	    cl_hw->channel_info.use_channel_info)
		kfree(cl_hw->channel_info.rd);
}

struct cl_chan_info *cl_chan_info_get(struct cl_hw *cl_hw, u8 channel, u8 bw)
{
	int i = 0;
	struct cl_chan_info *chan_info;

	for (i = 0; i < cl_channel_num(cl_hw); i++) {
		chan_info = &cl_hw->channel_info.channels[bw][i];

		if (chan_info->channel == channel)
			return chan_info;
	}

	return NULL;
}

u8 cl_chan_info_get_max_bw(struct cl_hw *cl_hw, u8 channel)
{
	s8 bw = 0;

	for (bw = CHNL_BW_160; bw > CHNL_BW_20; bw--)
		if (cl_chan_info_get(cl_hw, channel, bw))
			return (u8)bw;

	return CHNL_BW_20;
}

s16 cl_chan_info_get_eirp_limit_q8(struct cl_hw *cl_hw, u8 bw)
{
	/* Eirp_limit = min(country_limit, hw_limit) */
	struct cl_chan_info *chan_info = cl_chan_info_get(cl_hw, cl_hw->channel, bw);

	return chan_info ? (chan_info->max_power_q2 << 6) : CL_DEFAULT_CHANNEL_POWER_Q8;
}

s16 cl_chan_info_get_country_limit_q8(struct cl_hw *cl_hw, u8 channel, u8 bw)
{
	struct cl_chan_info *chan_info = cl_chan_info_get(cl_hw, channel, bw);

	return chan_info ? (chan_info->country_max_power_q2 << 6) : CL_DEFAULT_CHANNEL_POWER_Q8;
}

s16 cl_chan_info_get_hardware_limit_q8(struct cl_hw *cl_hw, u8 channel, u8 bw)
{
	struct cl_chan_info *chan_info = cl_chan_info_get(cl_hw, channel, bw);

	return chan_info ? (chan_info->hardware_max_power_q2 << 6) : CL_DEFAULT_CHANNEL_POWER_Q8;
}

u8 cl_chan_info_get_max_power(struct cl_hw *cl_hw, u8 channel)
{
	struct cl_chan_info *chan_info;
	u8 bw = 0;
	u8 max_power_q2 = 0;

	for (bw = 0; bw < CHNL_BW_MAX; bw++) {
		chan_info = cl_chan_info_get(cl_hw, channel, bw);

		if (!chan_info)
			continue;

		if (chan_info->max_power_q2 > max_power_q2)
			max_power_q2 = chan_info->max_power_q2;
	}

	return max_power_q2 >> 2;
}
