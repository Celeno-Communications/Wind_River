// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_rx_sens.h"
#include "cl_rssi.h"
#include "cl_traffic.h"
#include "reg_access.h"
#include "cl_env_det.h"
#include "reg_riu.h"

#define RX_SENS_DEF_HYST 2
#define RX_SENS_DEF_PERIOD 3

typedef void (*riu_rwnxagcdsp_inbdpowmindbm_ant_x_setf)(struct cl_chip *, u8);
typedef u8 (*riu_rwnxagcdsp_inbdpowmindbm_ant_x_getf)(struct cl_chip *);

static riu_rwnxagcdsp_inbdpowmindbm_ant_x_setf ant_x_setf[MAX_ANTENNAS] = {
	riu_rwnxagcdsp_3_inbdpowmindbm_ant_0_setf,
	riu_rwnxagcdsp_3_inbdpowmindbm_ant_1_setf,
};

static riu_rwnxagcdsp_inbdpowmindbm_ant_x_getf ant_x_getf[MAX_ANTENNAS] = {
	riu_rwnxagcdsp_3_inbdpowmindbm_ant_0_getf,
	riu_rwnxagcdsp_3_inbdpowmindbm_ant_1_getf,
};

static void cl_rx_sens_write_ant(struct cl_hw *cl_hw, u8 ant, s8 rx_sens_new)
{
	if (rx_sens_new == cl_hw->rx_sens_db.rx_sens_curr[ant])
		return;

	ant_x_setf[ant](cl_hw->chip, (u8)rx_sens_new);
	cl_hw->rx_sens_db.rx_sens_curr[ant] = rx_sens_new;
	CL_RX_SENS_PRINT("RX_SENS: Ant%u - Sensitivity = %d\n", ant, rx_sens_new);
}

static void cl_rx_sens_write(struct cl_hw *cl_hw, s8 *rx_sens_new)
{
	u8 i;

	for (i = 0; i < cl_hw->num_antennas; i++)
		cl_rx_sens_write_ant(cl_hw, i, rx_sens_new[i]);

}

static void cl_rx_sens_reset_rssi_sta(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	/* Reset rssi of specific station */
	struct cl_rx_sens_info *rx_sens_info = &cl_sta->rx_sens_info;

	rx_sens_info->rssi_samples = 0;
	memset(rx_sens_info->rssi_sum, 0, sizeof(rx_sens_info->rssi_sum));
}

static s8 cl_rx_sens_get_strongest_rssi(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_rx_sens_info *rx_sens_info = &cl_sta->rx_sens_info;
	s8 rssi_avg = 0, rssi_max = S8_MIN;
	int i;

	if (rx_sens_info->rssi_samples == 0)
		return 0;

	/* Calculation average rssi for each antenna, and find the strongest one */
	for (i = 0; i < cl_hw->num_antennas; i++) {
		rssi_avg = (s8)(rx_sens_info->rssi_sum[i] / rx_sens_info->rssi_samples);

		if (rssi_avg > rssi_max)
			rssi_max = rssi_avg;
	}

	/* Return the strongest rssi */
	return rssi_max;
}

static s8 cl_rx_sens_check_rssi(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	struct cl_rx_sens_db *rx_sens_db = &cl_hw->rx_sens_db;
	struct cl_rx_sens_info *rx_sens_info = &cl_sta->rx_sens_info;
	struct cl_tcv_conf *conf = cl_hw->conf;
	s8 rx_sens_new = rx_sens_info->value;
	s8 strongest_rssi = cl_rx_sens_get_strongest_rssi(cl_hw, cl_sta);

	if (strongest_rssi == 0)
		return rx_sens_new;

	/* Compare stongest rssi to thresholds */
	if (rx_sens_info->first_decision) {
		/* For the first decision do not use hysteresis */
		rx_sens_info->first_decision = false;

		if (strongest_rssi > conf->ci_rx_sens_rssi[RX_SENS_THR_1]) {
			rx_sens_new = conf->ci_rx_sens_val[RX_SENS_VAL_NEAR];
		} else if (strongest_rssi > conf->ci_rx_sens_rssi[RX_SENS_THR_2]) {
			rx_sens_new = conf->ci_rx_sens_val[RX_SENS_VAL_MID];
		} else if (strongest_rssi > conf->ci_rx_sens_rssi[RX_SENS_THR_3]) {
			rx_sens_new = conf->ci_rx_sens_val[RX_SENS_VAL_FAR];
		} else {
			u32 rx_sens_val = cl_env_det_is_clean(cl_hw) ?
				RX_SENS_VAL_VERY_FAR : RX_SENS_VAL_FAR;

			rx_sens_new = conf->ci_rx_sens_val[rx_sens_val];
		}
	} else {
		s8 rssi_hyst = rx_sens_db->rssi_hyst;

		if (strongest_rssi > (conf->ci_rx_sens_rssi[RX_SENS_THR_1] + rssi_hyst)) {
			rx_sens_new = conf->ci_rx_sens_val[RX_SENS_VAL_NEAR];
		} else if ((strongest_rssi < (conf->ci_rx_sens_rssi[RX_SENS_THR_1] - rssi_hyst)) &&
			   (strongest_rssi > (conf->ci_rx_sens_rssi[RX_SENS_THR_2] + rssi_hyst))) {
			rx_sens_new = conf->ci_rx_sens_val[RX_SENS_VAL_MID];
		} else if ((strongest_rssi < (conf->ci_rx_sens_rssi[RX_SENS_THR_2] - rssi_hyst)) &&
			   (strongest_rssi > (conf->ci_rx_sens_rssi[RX_SENS_THR_3] + rssi_hyst))) {
			rx_sens_new = conf->ci_rx_sens_val[RX_SENS_VAL_FAR];
		} else if (strongest_rssi < (conf->ci_rx_sens_rssi[RX_SENS_THR_3] - rssi_hyst)) {
			if (cl_env_det_is_clean(cl_hw))
				rx_sens_new = conf->ci_rx_sens_val[RX_SENS_VAL_VERY_FAR];
			else
				rx_sens_new = conf->ci_rx_sens_val[RX_SENS_VAL_FAR];
		}
	}

	CL_RX_SENS_PRINT("RX_SENS: sta_idx = %u, strongest_rssi = %d, rx_sens_new = %d\n",
			 cl_sta->sta_idx, strongest_rssi, rx_sens_new);

	/* Inside hystersis - return previous rx sensitivity */
	return rx_sens_new;
}

static void cl_rx_sens_decision(struct cl_hw *cl_hw)
{
	struct cl_rx_sens_info *rx_sens_info = NULL;
	struct cl_sta *cl_sta = NULL;
	s8 rx_sens_min = S8_MAX;
	s8 rx_sens[MAX_ANTENNAS] = {0};

	/* Go over all stations */
	cl_sta_lock(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		if (!cl_traffic_is_sta_active(cl_hw, cl_sta))
			continue;

		rx_sens_info = &cl_sta->rx_sens_info;
		rx_sens_info->value = cl_rx_sens_check_rssi(cl_hw, cl_sta);

		if (rx_sens_info->value < rx_sens_min)
			rx_sens_min = rx_sens_info->value;

		/* Reset RSSI samples for next decision */
		cl_rx_sens_reset_rssi_sta(cl_hw, cl_sta);
	}

	cl_sta_unlock(cl_hw);

	if (rx_sens_min != S8_MAX) {
		/* Update sensitivity according to all active statinos */
		memset(rx_sens, rx_sens_min, cl_hw->num_antennas);

		cl_rx_sens_write(cl_hw, rx_sens);
	} else {
		/*
		 * No associated or active stations
		 * In clean environment use VERY_FAR value, otherwise use rx_sensitivity_op
		 */
		if (cl_env_det_is_clean(cl_hw)) {
			u8 i;

			for (i = 0; i < cl_hw->num_antennas; i++)
				rx_sens[i] = min(cl_hw->rx_sensitivity[i],
						 cl_hw->conf->ci_rx_sens_val[RX_SENS_VAL_VERY_FAR]);

			cl_rx_sens_write(cl_hw, rx_sens);
		} else {
			cl_rx_sens_write(cl_hw, cl_hw->rx_sensitivity);
		}
	}

	/* Reset maintenance counter */
	cl_hw->rx_sens_db.maintenance = 0;
}

static int cl_rx_sens_cli_configuration(struct cl_hw *cl_hw)
{
	struct cl_rx_sens_db *rx_sens_db = &cl_hw->rx_sens_db;
	struct cl_tcv_conf *conf = cl_hw->conf;
	s8 *rssi = conf->ci_rx_sens_rssi;
	s8 *val = conf->ci_rx_sens_val;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "RX sensitivity configuration\n"
		    "----------------------------\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "Debug      = %s\n", rx_sens_db->debug ?
		    "True" : "False");
	cl_snprintf(&buf, &len, &buf_size,
		    "Enable     = %s\n", cl_hw->conf->ci_rx_sens_en ?
		    "True" : "False");
	cl_snprintf(&buf, &len, &buf_size,
		    "Period     = %u (sec)\n", rx_sens_db->period);
	cl_snprintf(&buf, &len, &buf_size,
		    "Value      = %d, %d, %d, %d\n",
		    val[RX_SENS_VAL_NEAR],
		    val[RX_SENS_VAL_MID],
		    val[RX_SENS_VAL_FAR],
		    val[RX_SENS_VAL_VERY_FAR]);
	cl_snprintf(&buf, &len, &buf_size,
		    "RSSI       = %d, %d, %d\n",
		    rssi[RX_SENS_THR_1],
		    rssi[RX_SENS_THR_2],
		    rssi[RX_SENS_THR_3]);
	cl_snprintf(&buf, &len, &buf_size,
		    "Hysteresis = %d\n", rx_sens_db->rssi_hyst);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void cl_rx_sens_cli_debug(struct cl_hw *cl_hw, bool debug)
{
	cl_hw->rx_sens_db.debug = debug;
	pr_debug("RX_SENS: Debug = %s\n", debug ? "True" : "False");
}

static void cl_rx_sens_cli_enable(struct cl_hw *cl_hw, bool enable)
{
	if (cl_hw->conf->ci_rx_sens_en == enable)
		return;

	if (cl_traffic_num_active_sta(cl_hw) > 0) {
		pr_warn("RX_SENS: Can't modify while there are active stations\n");
		return;
	}

	if (enable) {
		cl_hw->rx_sens_db.maintenance = 0;
		cl_sta_loop_bh(cl_hw, cl_rx_sens_reset_rssi_sta);
	} else {
		/* Return to default NVRAM configuration */
		cl_rx_sens_write(cl_hw, cl_hw->rx_sensitivity);
	}

	cl_hw->conf->ci_rx_sens_en = enable;
	pr_debug("RX_SENS: Enable = %s\n", enable ? "True" : "False");
}

static void cl_rx_sens_cli_hysteresis(struct cl_hw *cl_hw, s8 hysteresis)
{
	if (hysteresis >= 0) {
		cl_hw->rx_sens_db.rssi_hyst = hysteresis;
		pr_debug("RX_SENS: Hysteresis = %d\n", hysteresis);
	} else {
		pr_err("RX_SENS: Invalid hysteresis [%d]\n", hysteresis);
	}
}

static void cl_rx_sens_info_sta(struct cl_hw *cl_hw,
				struct cl_sta *cl_sta,
				char **buf,
				int *len, ssize_t *buf_size)
{
	s32 strongest_rssi = 0;

	if (!cl_traffic_is_sta_active(cl_hw, cl_sta))
		return;

	strongest_rssi = cl_rx_sens_get_strongest_rssi(cl_hw, cl_sta);
	cl_snprintf(buf, len, buf_size,
		    "Sta = %u, RSSI = %d, Decision = %d\n",
		    cl_sta->sta_idx, strongest_rssi,
		    cl_sta->rx_sens_info.value);
}

static int cl_rx_sens_cli_info(struct cl_hw *cl_hw)
{
	struct cl_sta *cl_sta = NULL;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;
	u8 i;

	cl_snprintf(&buf, &len, &buf_size,
		    "RX sensitivity information\n"
		    "--------------------------\n");

	for (i = 0; i < cl_hw->num_antennas; i++) {
		cl_snprintf(&buf, &len, &buf_size,
			    "Antenna %u\n", i);
		cl_snprintf(&buf, &len, &buf_size,
			    "   - Current sensitivity = %d\n",
			    cl_hw->rx_sens_db.rx_sens_curr[i]);
		cl_snprintf(&buf, &len, &buf_size,
			    "   - Register value      = 0x%x\n",
			    ant_x_getf[i](cl_hw->chip));
	}

	if (cl_traffic_num_active_sta(cl_hw) == 0) {
		pr_debug("No active stations\n");
		goto out;
	}

	/* Go over all stations - use bottom-half lock */
	read_lock_bh(&cl_hw->cl_sta_db.lock);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list)
		cl_rx_sens_info_sta(cl_hw, cl_sta, &buf, &len, &buf_size);

	read_unlock_bh(&cl_hw->cl_sta_db.lock);
out:
	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void cl_rx_sens_cli_period(struct cl_hw *cl_hw, u32 period)
{
	cl_hw->rx_sens_db.period = period;
	pr_debug("RX_SENS: Period = %u\n", period);
}

static void cl_rx_sens_cli_rssi(struct cl_hw *cl_hw, s8 rssi1, s8 rssi2, s8 rssi3)
{
	if (rssi1 < 0 && rssi2 < rssi1 && rssi3 < rssi2) {
		struct cl_tcv_conf *conf = cl_hw->conf;

		conf->ci_rx_sens_rssi[RX_SENS_THR_1] = rssi1;
		conf->ci_rx_sens_rssi[RX_SENS_THR_2] = rssi2;
		conf->ci_rx_sens_rssi[RX_SENS_THR_3] = rssi3;

		pr_debug("RX_SENS: RSSI threshold = %d, %d, %d\n", rssi1, rssi2, rssi3);
	} else {
		pr_err("RX_SENS: Invalid RSSI threshold [%d, %d, %d]\n", rssi1, rssi2, rssi3);
	}
}

static void cl_rx_sens_cli_value(struct cl_hw *cl_hw,
				 s8 value_near, s8 value_mid, s8 value_far, s8 value_very_far)
{
	if (value_near < 0 &&
	    value_mid <= value_near &&
	    value_far <= value_mid &&
	    value_very_far <= value_far) {
		struct cl_tcv_conf *conf = cl_hw->conf;

		conf->ci_rx_sens_val[RX_SENS_VAL_NEAR] = value_near;
		conf->ci_rx_sens_val[RX_SENS_VAL_MID] = value_mid;
		conf->ci_rx_sens_val[RX_SENS_VAL_FAR] = value_far;
		conf->ci_rx_sens_val[RX_SENS_VAL_VERY_FAR] = value_very_far;

		pr_debug("RX_SENS: Value = %d, %d, %d, %d\n",
			 value_near, value_mid, value_far, value_very_far);
	} else {
		pr_err("RX_SENS: Invalid value [%d, %d, %d, %d]\n",
		       value_near, value_mid, value_far, value_very_far);
	}
}

static void cl_rx_sens_cli_write(struct cl_hw *cl_hw, s8 val)
{
	s8 rx_sens[MAX_ANTENNAS] = {val, val};

	if (cl_hw->conf->ci_rx_sens_en) {
		pr_warn("RX_SENS: Disable dynamic mode before setting manual value\n");
		return;
	}

	pr_debug("RX_SENS: Manual mode - value = %d\n", val);
	cl_rx_sens_write(cl_hw, rx_sens);
}

static void cl_rx_sens_cli_write_single(struct cl_hw *cl_hw, u8 ant, s8 val)
{
	if (cl_hw->conf->ci_rx_sens_en) {
		pr_warn("RX_SENS: Disable dynamic mode before setting manual value\n");
		return;
	}

	if (ant >= cl_hw->num_antennas) {
		pr_warn("RX_SENS: Invalid ant %u. Should be 0 - %u\n",
			ant, cl_hw->num_antennas - 1);
		return;
	}

	pr_debug("RX_SENS: Manual mode - antenna = %u, value = %d\n", ant, val);
	cl_rx_sens_write_ant(cl_hw, ant, val);
}

static int cl_rx_sens_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "rxsens usage:\n"
		 "-c : Print configuration\n"
		 "-d : Set debug [0/1]\n"
		 "-e : Disable/Enable [0/1]\n"
		 "-h : Set hysteresis [dBm]\n"
		 "-i : Print current information\n"
		 "-p : Set period [sec]\n"
		 "-r : Set rssi [rssi1].[rssi2].[rssi3]\n"
		 "-v : Set value [near].[mid].[far].[very-far]\n"
		 "-w : Set rx sensitivity manually for all antennas [value]\n"
		 "-x : Set rx sensitivity manually for single antenna [ant].[value]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

void cl_rx_sens_init(struct cl_hw *cl_hw)
{
	struct cl_rx_sens_db *rx_sens_db = &cl_hw->rx_sens_db;

	/* Set initial sensitivity to be wsent in the start-request message */
	memcpy(rx_sens_db->rx_sens_curr, cl_hw->rx_sensitivity, cl_hw->num_antennas);

	rx_sens_db->rssi_hyst = RX_SENS_DEF_HYST;
	rx_sens_db->period = RX_SENS_DEF_PERIOD;
}

void cl_rx_sens_maintenance(struct cl_hw *cl_hw)
{
	if (cl_hw->conf->ci_rx_sens_en) {
		struct cl_rx_sens_db *rx_sens_db = &cl_hw->rx_sens_db;

		rx_sens_db->maintenance++;
		if (rx_sens_db->maintenance >= rx_sens_db->period)
			cl_rx_sens_decision(cl_hw);
	}
}

void cl_rx_sens_sta_active(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	/*
	 * After station becomes active make a new decision.
	 * It takes 200ms for station to become active so it should already
	 * have rssi smaples.
	 */
	if (cl_hw->conf->ci_rx_sens_en) {
		struct cl_rx_sens_info *rx_sens_info = &cl_sta->rx_sens_info;

		rx_sens_info->first_decision = true;
		rx_sens_info->value = S8_MIN;

		CL_RX_SENS_PRINT("RX_SENS: Sta %u active\n", cl_sta->sta_idx);
		cl_rx_sens_decision(cl_hw);
	}
}

void cl_rx_sens_sta_not_active(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	/* After station becomes not active make a new decision. */
	if (cl_hw->conf->ci_rx_sens_en) {
		CL_RX_SENS_PRINT("RX_SENS: Sta %u not-active\n", cl_sta->sta_idx);
		cl_rx_sens_decision(cl_hw);
	}
}

void cl_rx_sens_handle_rssi(struct cl_hw *cl_hw, struct cl_sta *cl_sta, s8 rssi[MAX_ANTENNAS])
{
	/* Collect rssi samples */
	if (cl_hw->conf->ci_rx_sens_en) {
		int i;
		struct cl_rx_sens_info *rx_sens_info = &cl_sta->rx_sens_info;

		for (i = 0; i < cl_hw->num_antennas; i++)
			rx_sens_info->rssi_sum[i] += rssi[i];

		rx_sens_info->rssi_samples++;
	}
}

int cl_rx_sens_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool configuration = false;
	bool debug = false;
	bool enable = false;
	bool hystersis = false;
	bool info = false;
	bool period = false;
	bool rssi = false;
	bool value = false;
	bool write = false;
	bool write_single = false;

	switch (cli_params->option) {
	case 'c':
		configuration = true;
		expected_params = 0;
		break;
	case 'd':
		debug = true;
		expected_params = 1;
		break;
	case 'e':
		enable = true;
		expected_params = 1;
		break;
	case 'h':
		hystersis = true;
		expected_params = 1;
		break;
	case 'i':
		info = true;
		expected_params = 0;
		break;
	case 'p':
		period = true;
		expected_params = 1;
		break;
	case 'r':
		rssi = true;
		expected_params = 3;
		break;
	case 'v':
		value = true;
		expected_params = 4;
		break;
	case 'w':
		write = true;
		expected_params = 1;
		break;
	case 'x':
		write_single = true;
		expected_params = 2;
		break;
	case '?':
		return cl_rx_sens_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (configuration) {
		return cl_rx_sens_cli_configuration(cl_hw);
	} else if (debug) {
		cl_rx_sens_cli_debug(cl_hw, cli_params->params[0]);
	} else if (enable) {
		cl_rx_sens_cli_enable(cl_hw, cli_params->params[0]);
	} else if (hystersis) {
		cl_rx_sens_cli_hysteresis(cl_hw, cli_params->params[0]);
	} else if (info) {
		return cl_rx_sens_cli_info(cl_hw);
	} else if (period) {
		cl_rx_sens_cli_period(cl_hw, cli_params->params[0]);
	} else if (rssi) {
		s8 rssi1 = (s8)cli_params->params[0];
		s8 rssi2 = (s8)cli_params->params[1];
		s8 rssi3 = (s8)cli_params->params[2];

		cl_rx_sens_cli_rssi(cl_hw, rssi1, rssi2, rssi3);
	} else if (value) {
		s8 value_near = cli_params->params[0];
		s8 value_mid = cli_params->params[1];
		s8 value_far = cli_params->params[2];
		s8 value_very_far = cli_params->params[3];

		cl_rx_sens_cli_value(cl_hw, value_near, value_mid, value_far, value_very_far);
	} else if (write) {
		cl_rx_sens_cli_write(cl_hw, cli_params->params[0]);
	} else if (write_single) {
		u8 ant = (u8)cli_params->params[0];
		s8 sens = (s8)cli_params->params[1];

		cl_rx_sens_cli_write_single(cl_hw, ant, sens);
	}

out_err:
	return -EIO;
}
