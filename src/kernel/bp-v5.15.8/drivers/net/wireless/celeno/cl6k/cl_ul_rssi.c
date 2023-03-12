// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_ul_rssi.h"
#include "cl_sta.h"

#define TARGET_RCV_PWR_FACTOR  110
#define TARGET_RCV_PWR_INITIAL -40
#define TARGET_RCV_PWR_INVALID 0xFF
#define TARGET_RCV_PWR_TX_MAX  S8_MAX
#define TARGET_RCV_PWR_DBM_MIN -110
#define TARGET_RCV_PWR_DBM_MAX -20
#define TARGET_RCV_PWR_MAX     90
#define TARGET_RCV_PWR_MIN     0
#define TARGET_RCV_PWR_STEPS   4

#define RCPI_MAX     220
#define RCPI_FACTOR  110
#define RCPI_INVALID 0xFF

static int cl_ul_rssi_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "ul_rssi usage:\n"
		 "-d : Set debug level [0-OFF, 1-ERROR, 2-WARN, 3-TRACE, 4-INFO]\n"
		 "-i : Set initial target power [dBm]\n"
		 "-s : Set SU maintenance period [sec]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

/* RCPI values are between 0 to 220 and corresponds to -110dBm - 0dBm */
static s8 cl_ul_rssi_rcpi_to_dbm(u8 rcpi)
{
	return (s8)(rcpi >> 1) - RCPI_FACTOR;
}

static u8 cl_ul_rssi_dbm_to_target_pwr(s8 ul_rssi)
{
	if (ul_rssi > TARGET_RCV_PWR_DBM_MAX)
		return TARGET_RCV_PWR_TX_MAX;
	else if (ul_rssi < TARGET_RCV_PWR_DBM_MIN)
		return TARGET_RCV_PWR_MIN;
	else
		return ul_rssi + TARGET_RCV_PWR_FACTOR;
}

static s8 cl_ul_rssi_target_pwr_to_dbm(u8 target_pwr)
{
	if (target_pwr > TARGET_RCV_PWR_MAX)
		return TARGET_RCV_PWR_DBM_MAX;
	else
		return target_pwr - TARGET_RCV_PWR_FACTOR;
}

static u8 cl_ul_rssi_get_rcv_pwr(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
				 s8 rx_diff, s8 ul_rssi_dbm)
{
	struct ieee80211_uph_ctrl *uph_ctrl = &cl_sta->ul_rssi_info.uph;
	bool min_pwr = uph_ctrl->u.fields.min_pwr;
	u8 pwr_headroom = uph_ctrl->u.fields.pwr_headroom;
	s8 ul_rssi;

	/* No power adjustment needed */
	if (rx_diff == 0) {
		return TARGET_RCV_PWR_INVALID;
	} else if (rx_diff > 0 && !min_pwr) {
		/* Need to reduce power */
		ul_rssi = ul_rssi_dbm - rx_diff;
	} else if (rx_diff < 0 && pwr_headroom) {
		/* Need to increase power */
		if (pwr_headroom < abs(rx_diff))
			ul_rssi = ul_rssi_dbm + pwr_headroom;
		else
			ul_rssi = ul_rssi_dbm - rx_diff;
	} else {
		return TARGET_RCV_PWR_INVALID;
	}

	return cl_ul_rssi_dbm_to_target_pwr(ul_rssi);
}

static s8 cl_ul_rssi_find_rx_diff(struct cl_hw *cl_hw, struct cl_sta *cl_sta, s8 ul_rssi_dbm)
{
	struct cl_ul_rssi_info *ul_rssi_info = &cl_sta->ul_rssi_info;
	s8 rx_diff, rcpi_dbm;

	if (!ul_rssi_info->rcpi_samples)
		return RCPI_INVALID;

	rcpi_dbm = cl_ul_rssi_rcpi_to_dbm(ul_rssi_info->rcpi);

	/* According to MU-TX flow doc */
	rx_diff = rcpi_dbm - ul_rssi_dbm;
	ul_rssi_pr_info("STA%u rx_diff %d, rcpi %d\n", cl_sta->sta_idx, rx_diff, rcpi_dbm);

	return rx_diff;
}

static void cl_ul_sta_rssi_maintenance(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_ul_rssi_info *ul_rssi_info = &cl_sta->ul_rssi_info;
	bool min_pwr = ul_rssi_info->uph.u.fields.min_pwr;
	u8 pwr_headroom = ul_rssi_info->uph.u.fields.pwr_headroom;
	u8 target_rcv_pwr, sta_idx = cl_sta->sta_idx;
	u8 ul_rssi_su = cl_hw->tf_info.data->tf_sta_data[0][sta_idx].ul_rssi_su;
	s8 ul_rssi_dbm_su = cl_ul_rssi_target_pwr_to_dbm(ul_rssi_su);
	s8 rx_diff;

	if (!ul_rssi_info->rcpi_samples) {
		cl_hw->ul_rssi_db.maintenance = 0;
		return;
	}

	/* We can't do any power adjustment for this STA */
	if (min_pwr && !pwr_headroom)
		goto out;

	ul_rssi_info->rcpi = ul_rssi_info->rcpi_sum / ul_rssi_info->rcpi_samples;
	rx_diff = cl_ul_rssi_find_rx_diff(cl_hw, cl_sta, ul_rssi_dbm_su);
	if (rx_diff == RCPI_INVALID)
		return;

	target_rcv_pwr = cl_ul_rssi_get_rcv_pwr(cl_hw, cl_sta, rx_diff, ul_rssi_dbm_su);
	if (target_rcv_pwr != TARGET_RCV_PWR_INVALID) {
		u8 ac;

		/* Update ul target receive power for FW to use */
		for (ac = 0; ac < AC_MAX; ac++)
			cl_hw->tf_info.data->tf_sta_data[ac][sta_idx].ul_rssi_su = target_rcv_pwr;

		ul_rssi_pr_warn("Target pwr update : STA%u %u(%d)\n",
				sta_idx, target_rcv_pwr, ul_rssi_dbm_su);
	}

out:
	/* Clear RCPI stats */
	ul_rssi_info->rcpi_sum = 0;
	ul_rssi_info->rcpi_samples = 0;
	/* Reset maintenance counter */
	cl_hw->ul_rssi_db.maintenance = 0;
}

static void cl_ul_rssi_debug_set(struct cl_hw *cl_hw, u8 debug_level)
{
	if (debug_level < DBG_LVL_MAX) {
		cl_hw->ul_rssi_db.dbg_lvl = debug_level;
		ul_rssi_pr_verbose("Debug level [%u]\n", cl_hw->ul_rssi_db.dbg_lvl);
	}
}

static void cl_ul_rssi_set_initial_target_pwr(struct cl_hw *cl_hw, s8 power)
{
	if (power > TARGET_RCV_PWR_DBM_MAX ||
	    power < TARGET_RCV_PWR_DBM_MIN) {
		ul_rssi_pr_verbose("Initial power should be between %d to %d !\n",
				   TARGET_RCV_PWR_DBM_MIN, TARGET_RCV_PWR_DBM_MAX);
		return;
	}

	cl_hw->ul_rssi_db.target_pwr = power;
	ul_rssi_pr_verbose("Initial power set to %d\n", power);
}

static void cl_ul_rssi_set_period_su(struct cl_hw *cl_hw, u32 period)
{
	cl_hw->ul_rssi_db.period = period;
	ul_rssi_pr_verbose("UL RSSI period SU set to %u\n", period);
}

bool cl_ul_rssi_is_rcpi_valid(u8 rcpi)
{
	return (rcpi < RCPI_MAX);
}

void cl_ul_rssi_update_uph(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			   struct ieee80211_a_control a_ctl)
{
	struct ieee80211_uph_ctrl *uph = &cl_sta->ul_rssi_info.uph;

	/* Skip 2 bits HE varaint and 4 bits control id */
	uph->u.value = a_ctl.u.value >> IEEE80211_CTRL_UPH_OFFSET;
	ul_rssi_pr_info("UPH frame received : pwr_headroom %u, min_pwr %u\n",
			uph->u.fields.pwr_headroom, uph->u.fields.min_pwr);
}

void cl_ul_rssi_sta_maintenance(struct cl_hw *cl_hw)
{
	struct cl_ul_rssi_db *ul_rssi_db = &cl_hw->ul_rssi_db;

	ul_rssi_db->maintenance++;
	if (ul_rssi_db->maintenance >= ul_rssi_db->period)
		cl_sta_loop(cl_hw, cl_ul_sta_rssi_maintenance);
}

void cl_ul_rssi_init(struct cl_hw *cl_hw)
{
	cl_hw->ul_rssi_db.target_pwr = TARGET_RCV_PWR_INITIAL;
	cl_hw->ul_rssi_db.period = TARGET_RCV_PWR_PERIOD_SU;
}

void cl_ul_rssi_sta_init(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	u8 ac;
	u8 ul_rssi_su = cl_ul_rssi_dbm_to_target_pwr(cl_hw->ul_rssi_db.target_pwr);

	for (ac = 0; ac < AC_MAX; ac++)
		cl_hw->tf_info.data->tf_sta_data[ac][cl_sta->sta_idx].ul_rssi_su = ul_rssi_su;
}

int cl_ul_rssi_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	bool debug = false;
	bool set_initial_pwr = false;
	bool set_period_su = false;
	u32 expected_params = -1;

	switch (cli_params->option) {
	case 'd':
		debug = true;
		expected_params = 1;
		break;
	case 'i':
		set_initial_pwr = true;
		expected_params = 1;
		break;
	case 's':
		set_period_su = true;
		expected_params = 1;
		break;
	case '?':
		return cl_ul_rssi_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n",
			   cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw,
			   "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (debug) {
		cl_ul_rssi_debug_set(cl_hw, (u8)cli_params->params[0]);
		return 0;
	}

	if (set_initial_pwr) {
		cl_ul_rssi_set_initial_target_pwr(cl_hw, (s8)cli_params->params[0]);
		return 0;
	}

	if (set_period_su) {
		cl_ul_rssi_set_period_su(cl_hw, (u32)cli_params->params[0]);
		return 0;
	}

out_err:
	return -EIO;
}
