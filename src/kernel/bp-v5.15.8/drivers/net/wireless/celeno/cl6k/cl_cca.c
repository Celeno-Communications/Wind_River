// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_cca.h"
#include "reg_mac_hw.h"
#include "cl_band.h"
#include "reg_riu.h"
#include "cl_hw.h"

#define TO_PERCENT(val, interval) (100 * (val) / (interval))
#define SET_CCA_OPT(en, a, b) ((en) ? ((a) |= (b)) : ((a) &= ~(b)))
#define MDM_AFTER_L_SIG  0x3F0
#define MDM_BEFORE_L_SIG 0x3F8
#define SAMPLE_RES       5

static void cl_cca_print_cs(struct cl_hw *cl_hw, unsigned long time)
{
	u8 cca_cs = TO_PERCENT(riu_cca_cnt_cs_get(cl_hw->chip), time);

	pr_debug("cca_cs = %u%%\n", cca_cs);
}

static void cl_cca_print_mdm_state(struct cl_hw *cl_hw, unsigned long time)
{
	u32 cca_mdm_state_p = TO_PERCENT(riu_cca_cnt_modem_state_p_get(cl_hw->chip), time);
	u32 cca_mdm_state_20s = TO_PERCENT(riu_cca_cnt_modem_state_20_s_get(cl_hw->chip), time);
	u32 cca_mdm_state_40s = TO_PERCENT(riu_cca_cnt_modem_state_40_s_get(cl_hw->chip), time);
	u32 cca_mdm_state_80s = TO_PERCENT(riu_cca_cnt_modem_state_80_s_get(cl_hw->chip), time);

	pr_debug("cca_mdm_state: primary = %u%%, sec20 = %u%%, sec40 = %u%%, sec80 = %u%%\n",
		 cca_mdm_state_p, cca_mdm_state_20s, cca_mdm_state_40s, cca_mdm_state_80s);
}

static void cl_cca_print_mp(struct cl_hw *cl_hw, unsigned long time)
{
	u32 cca_mp_20p = TO_PERCENT(riu_cca_cnt_gi_20_p_get(cl_hw->chip), time);
	u32 cca_mp_20s = TO_PERCENT(riu_cca_cnt_gi_20_s_get(cl_hw->chip), time);
	u32 cca_mp_40s = TO_PERCENT(riu_cca_cnt_gi_40_s_get(cl_hw->chip), time);
	u32 cca_mp_80s = TO_PERCENT(riu_cca_cnt_gi_80_s_get(cl_hw->chip), time);

	pr_debug("cca_mp: primary = %u%%, sec20 = %u%%, sec40 = %u, sec80 = %u%%\n",
		 cca_mp_20p, cca_mp_20s, cca_mp_40s, cca_mp_80s);
}

static void cl_cca_print_energy(struct cl_hw *cl_hw, unsigned long time)
{
	u32 cca_energy_thr_p = TO_PERCENT(riu_cca_cnt_energy_thr_p_get(cl_hw->chip), time);
	u32 cca_energy_thr_20s = TO_PERCENT(riu_cca_cnt_energy_thr_20_s_get(cl_hw->chip), time);
	u32 cca_energy_thr_40s = TO_PERCENT(riu_cca_cnt_energy_thr_40_s_get(cl_hw->chip), time);
	u32 cca_energy_thr_80s = TO_PERCENT(riu_cca_cnt_energy_thr_80_s_get(cl_hw->chip), time);

	pr_debug("cca_energy_thr: primary = %u%%, sec20 = %u%%, sec40 = (%u%%), sec80 = %u%%\n",
		 cca_energy_thr_p, cca_energy_thr_20s, cca_energy_thr_40s, cca_energy_thr_80s);
}

static void cl_cca_print_energy_band(struct cl_hw *cl_hw, unsigned long time)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 cca_energy_20_band0 = TO_PERCENT(riu_cca_cnt_energy_thr_20_band_0_get(chip), time);
	u32 cca_energy_20_band1 = TO_PERCENT(riu_cca_cnt_energy_thr_20_band_1_get(chip), time);
	u32 cca_energy_20_band2 = TO_PERCENT(riu_cca_cnt_energy_thr_20_band_2_get(chip), time);
	u32 cca_energy_20_band3 = TO_PERCENT(riu_cca_cnt_energy_thr_20_band_3_get(chip), time);
	u32 cca_energy_20_band4 = TO_PERCENT(riu_cca_cnt_energy_thr_20_band_4_get(chip), time);
	u32 cca_energy_20_band5 = TO_PERCENT(riu_cca_cnt_energy_thr_20_band_5_get(chip), time);
	u32 cca_energy_20_band6 = TO_PERCENT(riu_cca_cnt_energy_thr_20_band_6_get(chip), time);
	u32 cca_energy_20_band7 = TO_PERCENT(riu_cca_cnt_energy_thr_20_band_7_get(chip), time);

	pr_debug("cca_energy_20: band0 = %u%%, band1 = %u%%, band2 = %u%%, band3 = %u%%, "
		 "band4 = %u%%, band5 = %u%%, band6 = %u%%, band7 = %u%%\n",
		 cca_energy_20_band0, cca_energy_20_band1, cca_energy_20_band2,
		 cca_energy_20_band3, cca_energy_20_band4, cca_energy_20_band5,
		 cca_energy_20_band6, cca_energy_20_band7);
}

static void cl_cca_update_counters(u16 *hist, u32 counter)
{
	if (counter == 0)
		hist[0]++;
	else if (counter > 100)
		hist[CCA_MAX_SAMPLE - 1]++;
	else
		hist[((counter - 1) / SAMPLE_RES) + 1]++;
}

static void cl_cca_print_utility(struct cl_hw *cl_hw, unsigned long time)
{
	struct cl_cca_db *cca_db = &cl_hw->cca_db;
	struct cl_edca_hist_db *hist_db = &cca_db->edca_hist;
	u32 cca_cs = riu_cca_cnt_cs_get(cl_hw->chip);
	u32 edca_busy = mac_hw_edca_cca_busy_get(cl_hw->chip);
	u32 cca_mdm_state_p = riu_cca_cnt_modem_state_p_get(cl_hw->chip);
	u32 tx_mine = mac_hw_tx_mine_busy_get(cl_hw->chip);
	u32 rx_mine = mac_hw_rx_mine_busy_get(cl_hw->chip);
	u32 sample_cnt = hist_db->sample_cnt;
	u32 edca_busy_diff = edca_busy - cca_db->edca_busy;
	u32 tx_mine_diff = tx_mine - cca_db->tx_mine;
	u32 rx_mine_diff = rx_mine - cca_db->rx_mine;

	/* Cca utility formulas */
	u32 air_util = cca_cs + tx_mine_diff;
	u32 wifi_air_util = cca_mdm_state_p + tx_mine_diff;
	u32 not_mine_rx_wifi = cca_mdm_state_p - rx_mine_diff;
	u32 mine_util = tx_mine_diff + rx_mine_diff;
	u32 non_wifi_util = edca_busy_diff - cca_mdm_state_p;
	u32 not_mine_util = edca_busy_diff - rx_mine_diff;
	u32 not_mine_time = time - mine_util;

	u32 air_util_percent = TO_PERCENT(air_util, time);
	u32 wifi_air_util_percent = TO_PERCENT(wifi_air_util, time);
	u32 not_mine_rx_wifi_percent = TO_PERCENT(not_mine_rx_wifi, time);
	u32 mine_util_percent = TO_PERCENT(mine_util, time);
	u32 non_wifi_util_percent = TO_PERCENT(non_wifi_util, time);
	u32 not_mine_util_percent = TO_PERCENT(not_mine_util, time);
	u32 not_mine_busy_util_percent =
		(not_mine_time > 0) ? TO_PERCENT(not_mine_util, not_mine_time) : 0;

	cca_db->edca_busy = edca_busy;
	cca_db->tx_mine = tx_mine;
	cca_db->rx_mine = rx_mine;

	if (sample_cnt > 0) {
		cl_cca_update_counters(hist_db->air_util, air_util_percent);
		cl_cca_update_counters(hist_db->wifi_air_util, wifi_air_util_percent);
		cl_cca_update_counters(hist_db->not_mine_rx_wifi, not_mine_rx_wifi_percent);
		cl_cca_update_counters(hist_db->mine, mine_util_percent);
		cl_cca_update_counters(hist_db->non_wifi_util, non_wifi_util_percent);
		cl_cca_update_counters(hist_db->not_mine, not_mine_util_percent);
		cl_cca_update_counters(hist_db->not_mine_busy, not_mine_busy_util_percent);

		hist_db->sample_cnt--;

		/* Stop sampling */
		if (hist_db->sample_cnt == 0) {
			SET_CCA_OPT(0, cca_db->cca_opt, CCA_OPT_REC_HIST);
			pr_debug("Record is done\n");
		}
	}

	if (cca_db->cca_opt & CCA_OPT_UTIL)
		pr_debug("air_util = %u%%, wifi_air_util = %u%%, not_mine_rx_wifi = %u%%, "
			 "mine_util = %u%%, non_wifi_util = %u%%, not_mine_util = %u%%, "
			 "not_mine_busy_util = %u%%\n",
			 air_util_percent, wifi_air_util_percent, not_mine_rx_wifi,
			 mine_util_percent, non_wifi_util_percent, not_mine_util_percent,
			 not_mine_busy_util_percent);
}

static void cl_cca_print_tx_rx_mine(struct cl_hw *cl_hw, unsigned long time)
{
	struct cl_cca_db *cca_db = &cl_hw->cca_db;

	u32 tx_mine = mac_hw_tx_mine_busy_get(cl_hw->chip);
	u32 rx_mine = mac_hw_rx_mine_busy_get(cl_hw->chip);

	u32 diff_tx_mine = tx_mine - cca_db->print_tx_mine;
	u32 diff_rx_mine = rx_mine - cca_db->print_rx_mine;

	cca_db->print_tx_mine = tx_mine;
	cca_db->print_rx_mine = rx_mine;

	pr_debug("tx_mine = %u (%lu%%), rx_mine = %u (%lu%%)\n",
		 diff_tx_mine,
		 TO_PERCENT(diff_tx_mine, time),
		 diff_rx_mine,
		 TO_PERCENT(diff_rx_mine, time));
}

static void cl_cca_edca(struct cl_hw *cl_hw, unsigned long time)
{
	struct cl_cca_db *cca_db = &cl_hw->cca_db;
	bool is_24g = cl_band_is_24g(cl_hw);

	u32 new_edca_busy = mac_hw_edca_cca_busy_get(cl_hw->chip);
	u32 new_edca_busy_sec20 = mac_hw_add_cca_busy_sec_20_get(cl_hw->chip);
	u32 new_edca_busy_sec40 = is_24g ? 0 : mac_hw_add_cca_busy_sec_40_get(cl_hw->chip);
	u32 new_edca_busy_sec80 = is_24g ? 0 : mac_hw_add_cca_busy_sec_80_get(cl_hw->chip);

	u32 diff_edca_busy = new_edca_busy - cca_db->edca_busy;
	u32 diff_edca_busy_sec20 = new_edca_busy_sec20 - cca_db->edca_busy_sec20;
	u32 diff_edca_busy_sec40 = new_edca_busy_sec40 - cca_db->edca_busy_sec40;
	u32 diff_edca_busy_sec80 = new_edca_busy_sec80 - cca_db->edca_busy_sec80;

	u32 percent_edca_busy = TO_PERCENT(diff_edca_busy, time);
	u32 percent_edca_busy_sec20 = TO_PERCENT(diff_edca_busy_sec20, time);
	u32 percent_edca_busy_sec40 = TO_PERCENT(diff_edca_busy_sec40, time);
	u32 percent_edca_busy_sec80 = TO_PERCENT(diff_edca_busy_sec80, time);

	cca_db->edca_busy = new_edca_busy;
	cca_db->edca_busy_sec20 = new_edca_busy_sec20;
	cca_db->edca_busy_sec40 = new_edca_busy_sec40;
	cca_db->edca_busy_sec80 = new_edca_busy_sec80;

	pr_debug("edca_busy: primary = %u (%u%%), sec20 = %u (%u%%), "
		 "sec40 = %u (%u%%), sec80 = %u (%u%%)\n",
		 diff_edca_busy, percent_edca_busy,
		 diff_edca_busy_sec20, percent_edca_busy_sec20,
		 diff_edca_busy_sec40, percent_edca_busy_sec40,
		 diff_edca_busy_sec80, percent_edca_busy_sec80);
}

static void cl_cca_print_edca_nav(struct cl_hw *cl_hw, unsigned long time)
{
	struct cl_cca_db *cca_db = &cl_hw->cca_db;

	u32 new_cca_busy_nav = mac_hw_edca_nav_busy_get(cl_hw->chip);
	u32 new_cca_intra_bss_nav = mac_hw_intra_bss_nav_busy_get(cl_hw->chip);
	u32 new_cca_inter_bss_nav = mac_hw_inter_bss_nav_busy_get(cl_hw->chip);

	u32 diff_cca_busy_nav = new_cca_busy_nav - cca_db->cca_busy_nav;
	u32 diff_cca_intra_bss_nav = new_cca_intra_bss_nav - cca_db->cca_intra_bss_nav;
	u32 diff_cca_inter_bss_nav = new_cca_inter_bss_nav - cca_db->cca_inter_bss_nav;

	u32 percent_cca_busy_nav = TO_PERCENT(diff_cca_busy_nav, time);
	u32 percent_cca_intra_bss_nav = TO_PERCENT(diff_cca_intra_bss_nav, time);
	u32 percent_cca_inter_bss_nav = TO_PERCENT(diff_cca_inter_bss_nav, time);

	cca_db->cca_busy_nav = new_cca_busy_nav;
	cca_db->cca_intra_bss_nav = new_cca_intra_bss_nav;
	cca_db->cca_inter_bss_nav = new_cca_inter_bss_nav;

	pr_debug("cca_busy_nav = %u%%, cca_intra_bass_nav = %u%%, cca_inter_bass_nav = %u%%\n",
		 percent_cca_busy_nav, percent_cca_intra_bss_nav, percent_cca_inter_bss_nav);
}

static int cl_cca_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "cca usage:\n"
		 "-a : Print TX mine and RX mine [0-dis, 1-en]\n"
		 "-b : Print energy detect registers per20 [0-dis, 1-en]\n"
		 "-c : Print EDCA registers [0-dis, 1-en]\n"
		 "-d : Enable/Disable CCA statistics - [0-dis, 0xff-en all]\n"
		 "-e : Print energy detect registers [0-dis, 1-en]\n"
		 "-g : Print mid-packet registers [0-dis, 1-en]\n"
		 "-h : Print histogram [0-reset, 1-print]\n"
		 "-i : Print NAV busy registers [0-dis, 1-en]\n"
		 "-m : Print modem-state registers [0-dis, 1-en]\n"
		 "-n : Set modem-state registers [0-before L-SIG, 1-after L-SIG]\n"
		 "-r : Record histogram [samples #]\n"
		 "-s : Print carrier-sense register [0-dis, 1-en]\n"
		 "-u : Print CCA utility [0-dis, 1-en]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static bool cl_cca_is_hist_empty(struct cl_edca_hist_db *hist_db, u8 cnt)
{
	if (!hist_db->air_util[cnt] &&
	    !hist_db->mine[cnt] &&
	    !hist_db->non_wifi_util[cnt] &&
	    !hist_db->not_mine[cnt] &&
	    !hist_db->not_mine_busy[cnt] &&
	    !hist_db->not_mine_rx_wifi[cnt] &&
	    !hist_db->wifi_air_util[cnt])
		return true;

	return false;
}

static void cl_cca_print_histogram(struct cl_hw *cl_hw)
{
	struct cl_edca_hist_db *hist_db = &cl_hw->cca_db.edca_hist;
	u8 i = 0;
	u8 range = 1;

	pr_debug("|---------------------------------------------------------------|\n");
	pr_debug("|Samples|AirUtil|WifiAir|NonWifi|Mine   |NotMine|NotMine|NotMine|\n");
	pr_debug("|       |       |Util   |Util   |       |       |Busy   |RxWifi |\n");
	pr_debug("|-------+-------+-------+-------+-------+-------+-------+-------|\n");

	for (i = 0; i < CCA_MAX_SAMPLE; i++) {
		if (cl_cca_is_hist_empty(hist_db, i))
			continue;

		if (i > 1)
			range = ((i - 1) * SAMPLE_RES) + 1;

		if (i != 0)
			pr_debug("|%3u-%-3u| %5u | %5u | %5u | %5u | %5u | %5u | %5u |\n",
				 range, range + SAMPLE_RES - 1, hist_db->air_util[i],
				 hist_db->wifi_air_util[i], hist_db->non_wifi_util[i],
				 hist_db->mine[i], hist_db->not_mine[i],
				 hist_db->not_mine_busy[i], hist_db->not_mine_rx_wifi[i]);
		else
			pr_debug("|0      | %5u | %5u | %5u | %5u | %5u | %5u | %5u |\n",
				 hist_db->air_util[i], hist_db->wifi_air_util[i],
				 hist_db->non_wifi_util[i], hist_db->mine[i],
				 hist_db->not_mine[i], hist_db->not_mine_busy[i],
				 hist_db->not_mine_rx_wifi[i]);
	}

	pr_debug("|---------------------------------------------------------------|\n");
}

static void cl_cca_opt_update(struct cl_hw *cl_hw, u32 cca_opt_prev)
{
	struct cl_cca_db *cca_db = &cl_hw->cca_db;
	u32 cca_opt_new = cca_db->cca_opt;

	if (cca_opt_prev == 0 && cca_opt_new != 0) {
		cca_db->time = jiffies_to_usecs(jiffies);
		riu_rwnxagccca_1_cca_cnt_clear_setf(cl_hw->chip, 0);
	}

	if (((cca_opt_prev & CCA_OPT_TX_RX_MINE) != CCA_OPT_TX_RX_MINE) &&
	    (cca_opt_new & CCA_OPT_TX_RX_MINE)) {
		cca_db->print_tx_mine = mac_hw_tx_mine_busy_get(cl_hw->chip);
		cca_db->print_rx_mine = mac_hw_rx_mine_busy_get(cl_hw->chip);
	}

	if (((cca_opt_prev & CCA_OPT_UTIL) != CCA_OPT_UTIL) &&
	    (cca_opt_new & CCA_OPT_UTIL)) {
		cca_db->tx_mine = mac_hw_tx_mine_busy_get(cl_hw->chip);
		cca_db->rx_mine = mac_hw_rx_mine_busy_get(cl_hw->chip);
		cca_db->edca_busy = mac_hw_edca_cca_busy_get(cl_hw->chip);
	}
}

int cl_cca_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	struct cl_cca_db *cca_db = &cl_hw->cca_db;
	u32 cca_opt_prev = cca_db->cca_opt;
	u32 expected_params = -1;
	u32 param = (u32)cli_params->params[0];
	bool print_tx_rx_mine = false;
	bool print_energy_band = false;
	bool print_edca = false;
	bool print_all = false;
	bool print_energy = false;
	bool print_mp = false;
	bool print_histogram = false;
	bool print_nav_edca = false;
	bool print_mdm = false;
	bool set_mdm = false;
	bool record_histogram = false;
	bool print_cs = false;
	bool print_util = false;

	switch (cli_params->option) {
	case 'a':
		print_tx_rx_mine = true;
		expected_params = 1;
		break;
	case 'b':
		print_energy_band = true;
		expected_params = 1;
		break;
	case 'c':
		print_edca = true;
		expected_params = 1;
		break;
	case 'd':
		print_all = true;
		expected_params = 1;
		break;
	case 'e':
		print_energy = true;
		expected_params = 1;
		break;
	case 'g':
		print_mp = true;
		expected_params = 1;
		break;
	case 'h':
		print_histogram = true;
		expected_params = 1;
		break;
	case 'i':
		print_nav_edca = true;
		expected_params = 1;
		break;
	case 'm':
		print_mdm = true;
		expected_params = 1;
		break;
	case 'n':
		set_mdm = true;
		expected_params = 1;
		break;
	case 'r':
		record_histogram = true;
		expected_params = 1;
		break;
	case 's':
		print_cs = true;
		expected_params = 1;
		break;
	case 'u':
		print_util = true;
		expected_params = 1;
		break;
	case '?':
		return cl_cca_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (print_tx_rx_mine)
		SET_CCA_OPT(param, cca_db->cca_opt, CCA_OPT_TX_RX_MINE);

	if (print_energy_band)
		SET_CCA_OPT(param, cca_db->cca_opt, CCA_OPT_CNT_ENERGY_BAND);

	if (print_all)
		cca_db->cca_opt = param;

	if (print_edca)
		SET_CCA_OPT(param, cca_db->cca_opt, CCA_OPT_EDCA);

	if (print_energy)
		SET_CCA_OPT(param, cca_db->cca_opt, CCA_OPT_CNT_ENERGY);

	if (print_mp)
		SET_CCA_OPT(param, cca_db->cca_opt, CCA_OPT_CNT_MP);

	if (print_histogram) {
		if (param)
			cl_cca_print_histogram(cl_hw);
		else
			memset(&cca_db->edca_hist, 0, sizeof(struct cl_edca_hist_db));

		return 0;
	}

	if (print_nav_edca)
		SET_CCA_OPT(param, cca_db->cca_opt, CCA_OPT_EDCA_NAV);

	if (print_mdm)
		SET_CCA_OPT(param, cca_db->cca_opt, CCA_OPT_CNT_MDM_STATE);

	if (set_mdm) {
		u16 psel = param ? MDM_AFTER_L_SIG : MDM_BEFORE_L_SIG;

		pr_debug("Modem state register set to : %s L-SIG detection!\n",
			 param ? "after" : "before");
		riu_rwnxagcccastate_0_rxstatecca_20_psel_setf(cl_hw->chip, psel);

		return 0;
	}

	if (record_histogram) {
		pr_debug("%s recording samples\n", param ? "Start" : "Stop");
		cca_db->edca_hist.sample_cnt = param;
		SET_CCA_OPT(!!param, cca_db->cca_opt, CCA_OPT_REC_HIST);
	}

	if (print_cs)
		SET_CCA_OPT(param, cca_db->cca_opt, CCA_OPT_CNT_CS);

	if (print_util)
		SET_CCA_OPT(param, cca_db->cca_opt, CCA_OPT_UTIL);

	cl_cca_opt_update(cl_hw, cca_opt_prev);
	return 0;

out_err:
	return -EIO;
}

void cl_cca_maintenance(struct cl_hw *cl_hw)
{
	struct cl_cca_db *cca_db = &cl_hw->cca_db;
	unsigned long time = jiffies_to_usecs(jiffies);
	unsigned long diff_time = time - cca_db->time;
	u32 cca_opt = cca_db->cca_opt;

	cca_db->time = time;

	if (!diff_time || !cca_opt)
		return;

	if (cca_opt & CCA_OPT_CNT_CS)
		cl_cca_print_cs(cl_hw, diff_time);

	if (cca_opt & CCA_OPT_CNT_MDM_STATE)
		cl_cca_print_mdm_state(cl_hw, diff_time);

	if (cca_opt & CCA_OPT_CNT_MP)
		cl_cca_print_mp(cl_hw, diff_time);

	if (cca_opt & CCA_OPT_CNT_ENERGY)
		cl_cca_print_energy(cl_hw, diff_time);

	if (cca_opt & CCA_OPT_CNT_ENERGY_BAND)
		cl_cca_print_energy_band(cl_hw, diff_time);

	if (cca_opt & (CCA_OPT_UTIL | CCA_OPT_REC_HIST))
		cl_cca_print_utility(cl_hw, diff_time);

	if (cca_opt & CCA_OPT_TX_RX_MINE)
		cl_cca_print_tx_rx_mine(cl_hw, diff_time);

	if (cca_opt & CCA_OPT_EDCA)
		cl_cca_edca(cl_hw, diff_time);

	if (cca_opt & CCA_OPT_EDCA_NAV)
		cl_cca_print_edca_nav(cl_hw, diff_time);

	/* Rest CCA counters */
	riu_rwnxagccca_1_cca_cnt_clear_setf(cl_hw->chip, 0);
}

