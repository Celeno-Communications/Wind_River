// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_twt_cli.h"
#include "cl_twt.h"
#include "cl_twt_frame.h"
#include "cl_sta.h"
#include "cl_utils.h"

#define CL_TWT_MIN_WAKE_DURATION_MAX_VAL_US (0xFFU << 10)

static int cl_twt_cli_configuration_print(struct cl_hw *cl_hw)
{
	struct cl_tcv_conf *conf = cl_hw->conf;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "TWT configuration:\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "TWT enabled:                   %u\n",
		    conf->ce_twt_en);
	cl_snprintf(&buf, &len, &buf_size,
		    "TWT default interval:          %u\n",
		    conf->ce_twt_default_interval);
	cl_snprintf(&buf, &len, &buf_size,
		    "TWT default min wake duration: %u\n",
		    conf->ce_twt_default_min_wake_duration);
	cl_snprintf(&buf, &len, &buf_size,
		    "TWT num of sessions:           %u\n",
		    cl_hw->twt_db.num_sessions);
	cl_snprintf(&buf, &len, &buf_size,
		    "TWT max sessions:              %u\n",
		    conf->ce_twt_max_sessions);

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_twt_cli_sessions_print(struct cl_hw *cl_hw)
{
	u8 i, handled_sessions = 0, num_sessions = cl_hw->twt_db.num_sessions;
	u8 max_sessions = cl_hw->conf->ce_twt_max_sessions;
	struct cl_twt_session_db *session;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "-----------------------------------------------------"
		    "---------------------------------\n"
		    "| STA idx | Flow id | Announced | Triggered | "
		    "Interval us | Min wake    | Start time |\n"
		    "|         |         |           |           |        "
		    "     | duration us |            |\n");
	for (i = 0, session = &cl_hw->twt_db.cl_twt_sessions[0];
	     (i < max_sessions) && (handled_sessions < num_sessions);
	     i++, session++) {
		if (!session->cl_sta)
			continue;

		cl_snprintf(&buf, &len, &buf_size,
			    "+---------+---------+-----------+-----------+"
			    "-------------+-------------+------------+\n"
			    "|   %3u   |    %1u    |     %1u     |     %1u"
			    "     | %10llu  |   %6u    | %10llu |\n",
			    session->cl_sta->sta_idx,
			    session->twt_setup.req_type.fields.flow_id,
			    !(session->twt_setup.req_type.fields.flow_type),
			    session->twt_setup.req_type.fields.trigger,
			    cl_twt_get_wake_interval_us(&session->twt_setup),
			    cl_twt_get_min_wake_time_us(&session->twt_setup),
			    session->twt_setup.target_wake_time);
		handled_sessions++;
	}

	cl_snprintf(&buf, &len, &buf_size,
		    "-----------------------------------------------------"
		    "---------------------------------\n");

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_twt_cli_send_individual_setup_request(struct cl_hw *cl_hw,
						    struct cli_params *cli_params,
						    bool simulate)
{
	u8 sta_idx = (u8)cli_params->params[0];
	u8 setup_cmd = (u8)cli_params->params[1];
	u8 flow_id = (u8)cli_params->params[2];
	bool announced = (bool)cli_params->params[3];
	bool triggered = (bool)cli_params->params[4];
	u32 interval = (u32)cli_params->params[5];
	u32 min_wake_dur = (u32)cli_params->params[6];
	struct cl_sta *cl_sta;
	int res = -1;

	cl_sta_lock_bh(cl_hw);
	cl_sta = cl_sta_get(cl_hw, sta_idx);

	if (!cl_sta) {
		cl_dbg_err(cl_hw, "Invalid sta idx %u\n", sta_idx);
		goto out;
	}

	if (setup_cmd > IEEE80211_TWT_SETUP_COMMAND_DEMAND) {
		cl_dbg_verbose(cl_hw,
			       "Invalid setup cmd %u. Must be lower than %u\n",
			       setup_cmd, IEEE80211_TWT_SETUP_COMMAND_DEMAND);
		goto out;
	}

	if (flow_id > CL_TWT_FLOW_ID_MAX) {
		cl_dbg_verbose(cl_hw,
			       "Invalid flow id %u. Must be lower than %u\n",
			       flow_id, CL_TWT_FLOW_ID_MAX);
		goto out;
	}

	if (min_wake_dur > CL_TWT_MIN_WAKE_DURATION_MAX_VAL_US) {
		cl_dbg_verbose(cl_hw,
			       "Invalid min wake duration (%u). Must be no greater than %u\n",
			       min_wake_dur, CL_TWT_MIN_WAKE_DURATION_MAX_VAL_US);
		goto out;
	}

	if (min_wake_dur > interval) {
		cl_dbg_verbose(cl_hw,
			       "Min wake duration (%u) cannot be greater than interval (%u)\n",
			       min_wake_dur, interval);
		goto out;
	}

	cl_dbg_info(cl_hw,
		    "sta_idx %u, setup_cmd %u, flow_id %u, announced %u, "
		    "triggered %u, interval %u, min wake duration %u\n",
		    sta_idx, setup_cmd, flow_id, announced, triggered, interval, min_wake_dur);

	if (simulate)
		res = cl_twt_frame_simulate_individual_setup_request(cl_hw, cl_sta,
								     setup_cmd, flow_id,
								     announced, triggered,
								     (u64)interval, min_wake_dur);
	else
		res = cl_twt_frame_send_individual_setup_request(cl_hw, cl_sta, setup_cmd,
								 flow_id, announced, triggered,
								 (u64)interval, min_wake_dur);

out:
	cl_sta_unlock_bh(cl_hw);

	return res;
}

static int cl_twt_cli_send_individual_teardown_request(struct cl_hw *cl_hw,
						       struct cli_params *cli_params,
						       bool simulate)
{
	u8 sta_idx = (u8)cli_params->params[0];
	u8 flow_id = (u8)cli_params->params[1];
	struct cl_sta *cl_sta;
	int res = 0;

	cl_sta_lock_bh(cl_hw);
	cl_sta = cl_sta_get(cl_hw, sta_idx);

	if (!cl_sta) {
		cl_dbg_err(cl_hw, "Invalid sta idx %u\n", sta_idx);
		res = -1;
		goto out;
	}

	if (flow_id > CL_TWT_FLOW_ID_MAX && flow_id != CL_TWT_FLOW_ID_ALL) {
		cl_dbg_verbose(cl_hw,
			       "Invalid flow id %u. Must be lower than %u or %u\n",
			       flow_id, CL_TWT_FLOW_ID_MAX, CL_TWT_FLOW_ID_ALL);
		res = -1;
		goto out;
	}

	if (simulate) {
		res = cl_twt_frame_simulate_individual_teardown_request(cl_hw, cl_sta, flow_id);
	} else {
		/*
		 * If the session doesn't exist or couldn't be removed -
		 * send a teardown request anyway
		 */
		if (cl_twt_teardown_individual_sesseion(cl_hw, cl_sta, flow_id, true))
			cl_twt_frame_send_individual_teardown_request(cl_hw, cl_sta, flow_id);
	}

out:
	cl_sta_unlock_bh(cl_hw);

	return res;
}

static void cl_twt_cli_enable(struct cl_hw *cl_hw, bool enable)
{
	if (cl_hw->conf->ce_twt_en == enable) {
		pr_debug("TWT is already %s\n", enable ? "enabled" : "disabled");
		return;
	}

	cl_hw->conf->ce_twt_en = enable;

	if (enable)
		cl_twt_init(cl_hw);
	else
		cl_twt_close(cl_hw);

	pr_debug("TWT has been %s\n", (enable ? "enabled" : "disabled"));
}

static int cl_twt_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "twt usage\n"
		 "-c: Print configuration\n"
		 "-e: Enable/Disable TWT [0 - disable, 1 - enable]\n"
		 "-m: Simulate a reception of a TWT individual request:\n"
			"\t[sta_idx].[setup_cmd (0:request, 1:suggest, "
			"2:demand)].[flow_id (0-7))].[announced].[triggered]."
			"[interval].[min_wake_duration]\n"
		 "-n: Simulate a reception of a TWT individual teardown "
			"request:\n\t[sta_idx].[flow_id (0-7; 255 all_twt)]\n"
		 "-p: Print sessions\n"
		 "-s: Send a TWT individual setup request:\n"
			"\t[sta_idx].[setup_cmd (0:request, 1:suggest, "
			"2:demand)].[flow_id (0-7))].[announced].[triggered]."
			"[interval].[min_wake_duration]\n"
		 "-t: Send a TWT individual teardown request:\n"
			"\t[sta_idx].[flow_id (0-7; 255 for all_twt)]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_twt_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool print_conf = false;
	bool enable = false;
	bool simulate_req = false;
	bool simulate_teardown = false;
	bool print_sessions = false;
	bool send_req = false;
	bool send_teardown = false;

	switch (cli_params->option) {
	case 'c':
		print_conf = true;
		expected_params = 0;
		break;
	case 'e':
		enable = true;
		expected_params = 1;
		break;
	case 'm':
		simulate_req = true;
		expected_params = 7;
		break;
	case 'n':
		simulate_teardown = true;
		expected_params = 2;
		break;
	case 'p':
		print_sessions = true;
		expected_params = 0;
		break;
	case 's':
		send_req = true;
		expected_params = 7;
		break;
	case 't':
		send_teardown = true;
		expected_params = 2;
		break;
	case '?':
		return cl_twt_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (print_conf)
		return cl_twt_cli_configuration_print(cl_hw);

	if (enable) {
		cl_twt_cli_enable(cl_hw, (bool)cli_params->params[0]);
		return 0;
	}

	if (simulate_req) {
		int res = cl_twt_cli_send_individual_setup_request(cl_hw, cli_params, true);

		if (res)
			cl_dbg_verbose(cl_hw, "Error %d trying to simulate TWT request\n", res);

		return 0;
	}

	if (simulate_teardown) {
		cl_twt_cli_send_individual_teardown_request(cl_hw, cli_params, true);
		return 0;
	}

	if (print_sessions)
		return cl_twt_cli_sessions_print(cl_hw);

	if (send_req) {
		int res = cl_twt_cli_send_individual_setup_request(cl_hw, cli_params, false);

		if (res)
			cl_dbg_verbose(cl_hw, "Error %d trying to send TWT request\n", res);

		return 0;
	}

	if (send_teardown) {
		cl_twt_cli_send_individual_teardown_request(cl_hw, cli_params, false);
		return 0;
	}

out_err:
	return -EIO;
}
