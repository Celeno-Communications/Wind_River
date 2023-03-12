// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_traffic.h"
#include "cl_rx_sens.h"
#include "cl_env_det.h"
#include "cl_edca.h"
#include "cl_bf.h"
#include "cl_prot_mode.h"
#include "cl_vw.h"
#include "cl_band.h"
#include "cl_bsrp.h"
#include "cl_utils.h"

#define TRAFFIC_CNTR_ACTIVE_THR     3       /* 3 * 100ms = 300ms */
#define TRAFFIC_CNTR_IDLE_THR       20      /* 20 * 100ms = 2sec */

/* Threshold in bytes */
#define TRAFFIC_ACTIVE_THR_DRV      1920    /* = 150Kbit/sec (150 * 1024 / 8 / 10) */
#define TRAFFIC_ACTIVE_THR_BF       26214   /* = 2mbit/sec (2 * 1024 * 1024 / 8 / 10) */
#define TRAFFIC_ACTIVE_THR_EDCA_6G  2621440 /* = 200mbit/sec (200 * 1024 * 1024 / 8 / 10) */
#define TRAFFIC_ACTIVE_THR_EDCA_5G  2621440 /* = 200mbit/sec (200 * 1024 * 1024 / 8 / 10) */
#define TRAFFIC_ACTIVE_THR_EDCA_24G 655360  /* = 50mbit/sec (50 * 1024 * 1024 / 8 / 10) */

static const s8 *level_str[TRAFFIC_LEVEL_MAX] = {"DRV", "BF", "EDCA"};

static void cl_traffic_sta_start(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
				 enum cl_traffic_level level, enum cl_traffic_direction direction)
{
	cl_hw->traffic_db.num_active_sta_dir[direction][level]++;

	/* If other direction is not active increase num_active_sta */
	if (!cl_sta->traffic_db[1 - direction].activity_db[level].is_active)
		cl_hw->traffic_db.num_active_sta[level]++;

	if (level == TRAFFIC_LEVEL_DRV)	{
		cl_env_det_disable(cl_hw);
		cl_rx_sens_sta_active(cl_hw, cl_sta);

		/* BSR/BSRP flow */
		if (cl_hw->conf->ce_bsrp_en &&
		    direction == TRAFFIC_DIRECTION_RX)
			cl_bsrp_send_su((unsigned long)cl_sta);

		/*
		 * Dynamic CTS:
		 * If protection mode is disabled, environment is clean,
		 * VW is not detected and station threshold was reached switch to CTS.
		 */
		if (cl_hw->traffic_db.num_active_sta[TRAFFIC_LEVEL_DRV] ==
		     cl_hw->conf->ci_dyn_cts_sta_thr)
			if (cl_env_det_is_clean(cl_hw) &&
			    !cl_vw_is_detected(cl_hw) &&
			    (cl_prot_mode_get(cl_hw) == TXL_NO_PROT)) {
				cl_hw->traffic_db.dynamic_cts = true;
				cl_prot_mode_set(cl_hw, TXL_PROT_CTS_FW);
			}
	} else if (level == TRAFFIC_LEVEL_BF) {
		if (direction == TRAFFIC_DIRECTION_TX)
			cl_bf_sta_active(cl_hw, cl_sta, true);
	} else if (level == TRAFFIC_LEVEL_EDCA) {
		/*
		 * In clean environment, single active station and high rate use
		 * special EDCA configuration, otherwise use default
		 */
		if (cl_env_det_is_clean(cl_hw)) {
			if (cl_hw->traffic_db.num_active_sta[TRAFFIC_LEVEL_EDCA] == 1)
				cl_edca_dynamic_update_single_sta(cl_hw, cl_sta, true);
			else
				cl_edca_dynamic_update_single_sta(cl_hw, NULL, false);
		}
	}
}

static void cl_traffic_sta_stop(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
				enum cl_traffic_level level, enum cl_traffic_direction direction)
{
	cl_hw->traffic_db.num_active_sta_dir[direction][level]--;

	/* If other direction is not active decrease num_active_sta */
	if (!cl_sta->traffic_db[1 - direction].activity_db[level].is_active)
		cl_hw->traffic_db.num_active_sta[level]--;

	if (level == TRAFFIC_LEVEL_DRV) {
		if (cl_hw->traffic_db.num_active_sta[TRAFFIC_LEVEL_DRV] == 0)
			cl_env_det_enable(cl_hw);

		cl_rx_sens_sta_not_active(cl_hw, cl_sta);

		/* Dynamic CTS:
		 * If it was turned on and active station count became lower than
		 * threshold --> return to no protection
		 */
		if (cl_hw->traffic_db.dynamic_cts) {
			if (cl_hw->traffic_db.num_active_sta[TRAFFIC_LEVEL_DRV] ==
			    (cl_hw->conf->ci_dyn_cts_sta_thr - 1)) {
				cl_hw->traffic_db.dynamic_cts = false;
				cl_prot_mode_set(cl_hw, TXL_NO_PROT);
			}
		}
	} else if (level == TRAFFIC_LEVEL_BF) {
		if (direction == TRAFFIC_DIRECTION_TX)
			cl_bf_sta_active(cl_hw, cl_sta, false);
	} else if (level == TRAFFIC_LEVEL_EDCA) {
		/*
		 * In clean environment, single active station and high rate use
		 * special EDCA configuration, otherwise use default
		 */
		if (cl_env_det_is_clean(cl_hw))	{
			if (cl_hw->traffic_db.num_active_sta[TRAFFIC_LEVEL_EDCA] == 1)
				cl_edca_dynamic_update_single_sta(cl_hw, cl_sta, true);
			else
				cl_edca_dynamic_update_single_sta(cl_hw, NULL, false);
		}
	}
}

static void cl_traffic_check_activity(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
				      enum cl_traffic_level level,
				      enum cl_traffic_direction direction)
{
	struct cl_traffic_activity *activity_db =
		&cl_sta->traffic_db[direction].activity_db[level];
	u32 num_bytes = cl_sta->traffic_db[direction].num_bytes;

	if (num_bytes > cl_hw->traffic_db.active_bytes_thr[level]) {
		activity_db->cntr_active++;
		activity_db->cntr_idle = 0;

		/* If traffic is above threshold for X consective times change state to active */
		if (!activity_db->is_active &&
		    activity_db->cntr_active >= TRAFFIC_CNTR_ACTIVE_THR) {
			activity_db->is_active = true;
			cl_traffic_sta_start(cl_hw, cl_sta, level, direction);
		}
	} else {
		activity_db->cntr_active = 0;
		activity_db->cntr_idle++;

		/* If traffic is below threshold for Y consective times change state to idle */
		if (activity_db->is_active && activity_db->cntr_idle >= TRAFFIC_CNTR_IDLE_THR) {
			activity_db->is_active = false;
			cl_traffic_sta_stop(cl_hw, cl_sta, level, direction);
		}
	}
}

static void cl_traffic_monitor_sta_traffic(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	enum cl_traffic_level level = 0;

	/* Check Tx & Rx activity in all levels */
	for (level = 0; level < TRAFFIC_LEVEL_MAX; level++) {
		cl_traffic_check_activity(cl_hw, cl_sta, level, TRAFFIC_DIRECTION_TX);
		cl_traffic_check_activity(cl_hw, cl_sta, level, TRAFFIC_DIRECTION_RX);
	}

	/* Reset num_bytes */
	cl_sta->traffic_db[TRAFFIC_DIRECTION_TX].num_bytes = 0;
	cl_sta->traffic_db[TRAFFIC_DIRECTION_RX].num_bytes = 0;
}

static int cl_traffic_print_state(struct cl_hw *cl_hw,
				  enum cl_traffic_level level)
{
	struct cl_sta *cl_sta = NULL;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;
	struct cl_traffic_main *db = &cl_hw->traffic_db;

	if (level >= TRAFFIC_LEVEL_MAX) {
		cl_snprintf(&buf, &len, &buf_size,
			    "invalid level %d\n", level);
		goto out;
	}

	cl_snprintf(&buf, &len, &buf_size,
		    "Level %s (%d)\n", level_str[level], level);
	cl_snprintf(&buf, &len, &buf_size,
		    "Active stations    - %u\n",
		    db->num_active_sta[level]);
	cl_snprintf(&buf, &len, &buf_size,
		    "Active stations TX - %u\n",
		    db->num_active_sta_dir[TRAFFIC_DIRECTION_TX][level]);
	cl_snprintf(&buf, &len, &buf_size,
		    "Active stations RX - %u\n",
		    db->num_active_sta_dir[TRAFFIC_DIRECTION_RX][level]);

	if (db->num_active_sta[level] == 0)
		goto out;

	cl_snprintf(&buf, &len, &buf_size,
		    "|---------------------|\n"
		    "|Sta|ActiveTx|ActiveRx|\n"
		    "|---------------------|\n");

	/* Go over all stations */
	cl_sta_lock_bh(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list)
		cl_snprintf(&buf, &len, &buf_size,
			    "|%3u|%-8s|%-8s|\n",
			    cl_sta->sta_idx,
			    cl_sta->traffic_db[TRAFFIC_DIRECTION_TX].activity_db[level].is_active ?
			    "True" : "False",
			    cl_sta->traffic_db[TRAFFIC_DIRECTION_RX].activity_db[level].is_active ?
			    "True" : "False");

	cl_sta_unlock_bh(cl_hw);

	cl_snprintf(&buf, &len, &buf_size,
		    "|---------------------|\n");
out:
	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static int cl_traffic_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "traffic usage:\n"
		 "-m : Print traffic monitor\n"
		 "-s : Print traffic state [0-drv/1-bf/2-edca]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

void cl_traffic_init(struct cl_hw *cl_hw)
{
	struct cl_traffic_main *traffic_db = &cl_hw->traffic_db;

	traffic_db->active_bytes_thr[TRAFFIC_LEVEL_DRV] = TRAFFIC_ACTIVE_THR_DRV;
	traffic_db->active_bytes_thr[TRAFFIC_LEVEL_BF] = TRAFFIC_ACTIVE_THR_BF;

	if (cl_band_is_6g(cl_hw))
		traffic_db->active_bytes_thr[TRAFFIC_LEVEL_EDCA] = TRAFFIC_ACTIVE_THR_EDCA_6G;
	else if (cl_band_is_5g(cl_hw))
		traffic_db->active_bytes_thr[TRAFFIC_LEVEL_EDCA] = TRAFFIC_ACTIVE_THR_EDCA_5G;
	else
		traffic_db->active_bytes_thr[TRAFFIC_LEVEL_EDCA] = TRAFFIC_ACTIVE_THR_EDCA_24G;

	cl_env_det_enable(cl_hw);
}

void cl_traffic_tx_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u32 num_bytes)
{
	cl_sta->traffic_db[TRAFFIC_DIRECTION_TX].num_bytes += num_bytes;
}

void cl_traffic_rx_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u32 num_bytes)
{
	cl_sta->traffic_db[TRAFFIC_DIRECTION_RX].num_bytes += num_bytes;
}

void cl_traffic_maintenance(struct cl_hw *cl_hw)
{
	cl_sta_loop(cl_hw, cl_traffic_monitor_sta_traffic);
}

void cl_traffic_sta_remove(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	/* Check if station disconnected during traffic */
	enum cl_traffic_level level = 0;
	enum cl_traffic_direction direction = 0;

	for (direction = 0; direction < TRAFFIC_DIRECTION_MAX; direction++) {
		for (level = 0; level < TRAFFIC_LEVEL_MAX; level++) {
			if (cl_sta->traffic_db[direction].activity_db[level].is_active)
				cl_traffic_sta_stop(cl_hw, cl_sta, level, direction);
		}

		memset(&cl_sta->traffic_db, 0, sizeof(cl_sta->traffic_db));
	}
}

bool cl_traffic_is_sta_active(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	return (cl_sta->traffic_db[TRAFFIC_DIRECTION_TX].activity_db[TRAFFIC_LEVEL_DRV].is_active ||
		cl_sta->traffic_db[TRAFFIC_DIRECTION_RX].activity_db[TRAFFIC_LEVEL_DRV].is_active);
}

bool cl_traffic_is_sta_active_tx(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	return cl_sta->traffic_db[TRAFFIC_DIRECTION_TX].activity_db[TRAFFIC_LEVEL_DRV].is_active;
}

u32 cl_traffic_num_active_sta(struct cl_hw *cl_hw)
{
	return cl_hw->traffic_db.num_active_sta[TRAFFIC_LEVEL_DRV];
}

int cl_traffic_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	bool print_state = false;
	bool print_traffic_monitor = false;
	int expected_params = -1;

	switch (cli_params->option) {
	case 's':
		print_state = true;
		expected_params = 1;
		break;
	case 'm':
		print_traffic_monitor = true;
		expected_params = 0;
		break;
	case '?':
		return cl_traffic_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (print_state)
		return cl_traffic_print_state(cl_hw,
					      (u8)(cli_params->params[0]));

	if (print_traffic_monitor)
		return cl_traffic_mon_print(cl_hw);

out_err:
	return -EIO;
}
