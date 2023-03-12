// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_wrs_cli.h"
#include "cl_wrs_sta.h"
#include "cl_wrs_rssi.h"
#include "cl_wrs.h"
#include "cl_wrs_stats.h"
#include "cl_utils.h"
#include "cl_debug.h"
#include "cl_sta.h"

#define WRS_ALL_STA U8_MAX

static void cl_wrs_cli_interval_set(struct cl_wrs_db *wrs_db, u32 interval)
{
	wrs_db->interval = msecs_round(interval);

	pr_debug("[WRS] Interval = %u\n", wrs_db->interval);
}

static void cl_wrs_cli_config_print(struct cl_hw *cl_hw)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;

	pr_debug("\n");
	pr_debug("--------------------------------\n");
	pr_debug("Main database configuration\n");
	pr_debug("--------------------------------\n");
	pr_debug("Interval                = [%u]\n",
		 wrs_db->interval);
	pr_debug("Debug level             = [%u]\n",
		 wrs_db->debug_level);
	pr_debug("Min frames for decision = [%u]\n",
		 wrs_db->min_frames_for_decision);
	pr_debug("EPR factor              = [%u]\n",
		 wrs_db->epr_factor);
	pr_debug("--------------------------------\n");
	pr_debug("Immediate drop configuration\n");
	pr_debug("--------------------------------\n");
	pr_debug("Enabled                 = [%s]\n",
		 wrs_db->immediate_drop_en ? "TRUE" : "FALSE");
	pr_debug("EPR Factor              = [%u]\n",
		 wrs_db->immediate_drop_epr_factor);
	pr_debug("Max in row              = [%u]\n",
		 wrs_db->immediate_drop_max_in_row);
	pr_debug("--------------------------------\n");
	pr_debug("RSSI protect configuration\n");
	pr_debug("--------------------------------\n");
	pr_debug("Enabled                 = [%s]\n",
		 wrs_db->rssi_protect_en ? "TRUE" : "FALSE");
	pr_debug("Mode                    = [%s]\n",
		 (wrs_db->rssi_protect_mode == WRS_RSSI_PROT_MODE_RSSI) ? "rssi" : "neighbor");
	pr_debug("Up threshold            = [%d]\n",
		 wrs_db->rssi_protect_up_thr);
	pr_debug("Down threshold          = [%d]\n",
		 wrs_db->rssi_protect_dn_thr);
	pr_debug("--------------------------------\n");
	pr_debug("Converge idle configuration\n");
	pr_debug("--------------------------------\n");
	pr_debug("Enable                  = [%s]\n",
		 wrs_db->converge_idle_en ? "TRUE" : "FALSE");
	pr_debug("Interval reset          = [%u]\n",
		 wrs_db->converge_idle_interval_reset);
	pr_debug("Interval rssi           = [%u]\n",
		 wrs_db->converge_idle_interval_rssi);
	pr_debug("Packet threshold        = [%u]\n",
		 wrs_db->converge_idle_packet_th);
	pr_debug("--------------------------------\n");
	pr_debug("Converge traffic configuration\n");
	pr_debug("--------------------------------\n");
	pr_debug("Traffic enable          = [%s]\n",
		 wrs_db->converge_trfc_en ? "TRUE" : "FALSE");
	pr_debug("Interval static         = [%u]\n",
		 wrs_db->converge_trfc_interval_static);
	pr_debug("--------------------------------\n");
	pr_debug("Steps and min/max thresholds\n");
	pr_debug("--------------------------------\n");
	pr_debug("Step down               = [%u]\n",
		 wrs_db->step_down);
	pr_debug("Step same/up            = [%u]\n",
		 wrs_db->step_up_same);
	pr_debug("Min threshold           = [%u]\n",
		 wrs_db->time_th_min);
	pr_debug("Max threshold up        = [%u]\n",
		 wrs_db->time_th_max_up);
	pr_debug("Max threshold down      = [%u]\n",
		 wrs_db->time_th_max_down);
	pr_debug("--------------------------------\n");
	pr_debug("Quick up configuration\n");
	pr_debug("--------------------------------\n");
	pr_debug("Enable                  = [%s]\n",
		 wrs_db->quick_up_en ? "TRUE" : "FALSE");
	pr_debug("BA threshold            = [%u]\n",
		 wrs_db->quick_up_ba_thr);
	pr_debug("Interval                = [%u]\n",
		 wrs_db->quick_up_interval);
	pr_debug("--------------------------------\n");
	pr_debug("Quick down configuration\n");
	pr_debug("--------------------------------\n");
	pr_debug("Enable                  = [%s]\n",
		 wrs_db->quick_down_en ? "TRUE" : "FALSE");
	pr_debug("EPR factor              = [%u]\n",
		 wrs_db->quick_down_epr_factor);
	pr_debug("Agg threshold           = [%u]\n",
		 wrs_db->quick_down_agg_thr);
	pr_debug("Packet threshold        = [%u]\n",
		 wrs_db->quick_down_pkt_thr);
	pr_debug("--------------------------------\n");
	pr_debug("BA not received configuration\n");
	pr_debug("--------------------------------\n");
	pr_debug("Collision filter        = [%s]\n",
		 wrs_db->ba_not_rcv_collision_filter ? "TRUE" : "FALSE");
	pr_debug("Force                   = [%s]\n",
		 wrs_db->ba_not_rcv_force ? "TRUE" : "FALSE");
	pr_debug("Time since sync         = [%u]\n",
		 wrs_db->ba_not_rcv_time_since_sync);
	pr_debug("--------------------------------\n");
	pr_debug("Sync rate\n");
	pr_debug("--------------------------------\n");
	pr_debug("Sync timeout            = [%u]\n",
		 wrs_db->sync_timeout);
	pr_debug("Sync min attempts       = [%u]\n",
		 wrs_db->sync_min_attempts);
	pr_debug("\n");
}

static void cl_wrs_cli_dbg_level_set(struct cl_wrs_db *wrs_db, u32 debug_level)
{
	if (debug_level < DBG_LVL_MAX) {
		wrs_db->debug_level = debug_level;
		pr_debug("[WRS] Debug level = %u\n", debug_level);
	} else {
		pr_err("[WRS] Invalid debug level = %u\n", debug_level);
	}
}

static void cl_wrs_cli_initial_rate_set(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
					u8 sta_idx, u8 bw, u8 nss, u8 mcs, u8 gi)
{
	struct cl_wrs_sta *wrs_sta;

	cl_sta_lock_bh(cl_hw);
	wrs_sta = cl_wrs_sta_get(cl_hw, sta_idx);

	if (wrs_sta)
		cl_wrs_initial_rate_set(wrs_db, wrs_sta, bw, nss, mcs, gi);
	else
		pr_err("[WRS] Invalid sta_idx [%u]\n", sta_idx);

	cl_sta_unlock_bh(cl_hw);
}

static void cl_wrs_cli_fixed_rate_set(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db, u8 sta_idx,
				      u8 is_fixed_rate, u8 mode, u8 bw, u8 nss,
				      u8 mcs, u8 gi, u8 type)
{
	struct cl_wrs_params *wrs_params = NULL;
	struct cl_wrs_sta *wrs_sta = NULL;

	if (type >= WRS_TYPE_MAX) {
		pr_err("[WRS] Invalid type [%u]\n", type);
		return;
	}

	if (is_fixed_rate >= WRS_FIXED_RATE_MAX) {
		pr_err("[WRS] Invalid fixed rate [%u] -\n"
		       "0 = auto\n"
		       "1 = fixed - fallback enable\n"
		       "2 = fixed - fallback disable\n",
		       is_fixed_rate);
		return;
	}

	if (sta_idx != WRS_ALL_STA) {
		cl_sta_lock_bh(cl_hw);
		wrs_sta = cl_wrs_sta_get(cl_hw, sta_idx);

		/* Fixed rate for single station */
		if (!wrs_sta) {
			pr_err("[WRS] Invalid sta_idx [%u]\n", sta_idx);
			goto unlock;
		}

		wrs_params = cl_wrs_params_get(wrs_sta, type);

		if (!wrs_params) {
			pr_err("[WRS] params is NULL\n");
			goto unlock;
		}

		cl_wrs_fixed_rate_set(cl_hw, wrs_db, wrs_sta, wrs_params, is_fixed_rate,
				      mode, bw, nss, mcs, gi);

unlock:
		cl_sta_unlock_bh(cl_hw);
	} else {
		/* Fixed rate for all connected station */
		struct cl_sta *cl_sta;

		cl_sta_lock_bh(cl_hw);

		list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
			wrs_sta = &cl_sta->wrs_sta;
			wrs_params = cl_wrs_params_get(wrs_sta, type);

			if (wrs_params)
				cl_wrs_fixed_rate_set(cl_hw, wrs_db, wrs_sta,
						      wrs_params, is_fixed_rate,
						      mode, bw, nss, mcs, gi);
		}

		cl_sta_unlock_bh(cl_hw);

		/* Save fixed rate parameters for stations that will connect in the future */
		wrs_db->is_fixed_rate = is_fixed_rate;

		if (is_fixed_rate) {
			cl_hw->conf->ci_wrs_fixed_rate[WRS_FIXED_PARAM_MODE] = mode;
			cl_hw->conf->ci_wrs_fixed_rate[WRS_FIXED_PARAM_BW] = bw;
			cl_hw->conf->ci_wrs_fixed_rate[WRS_FIXED_PARAM_NSS] = nss;
			cl_hw->conf->ci_wrs_fixed_rate[WRS_FIXED_PARAM_MCS] = mcs;
			cl_hw->conf->ci_wrs_fixed_rate[WRS_FIXED_PARAM_GI] = gi;
		}
	}
}

static void cl_wrs_cli_converge_idle_param_set(struct cl_wrs_db *wrs_db, u32 param, u32 value)
{
	switch (param) {
	case 0:
		wrs_db->converge_idle_en = (bool)value;
		break;
	case 1:
		wrs_db->converge_idle_interval_reset = value;
		break;
	case 2:
		wrs_db->converge_idle_interval_rssi = value;
		break;
	case 3:
		wrs_db->converge_idle_packet_th = value;
		break;
	default:
		pr_warn("[WRS] Invalid parameter [%u]\n", param);
		break;
	}
}

static void cl_wrs_cli_converge_trfc_param_set(struct cl_wrs_db *wrs_db, u32 param, u32 value)
{
	switch (param) {
	case 0:
		wrs_db->converge_trfc_en = (bool)value;
		break;
	case 1:
		wrs_db->converge_trfc_interval_static = value;
		break;
	default:
		pr_warn("[WRS] Invalid parameter [%u]\n", param);
		break;
	}
}

static void cl_wrs_cli_logger_alloc(struct cl_wrs_params *wrs_params, u8 sta_idx, u16 logger_size)
{
	u32 size = logger_size * sizeof(struct cl_wrs_logger);

	wrs_params->logger = kzalloc(size, GFP_ATOMIC);

	if (!wrs_params->logger)
		return;

	wrs_params->logger_size = logger_size;
	wrs_params->logger_idx = 0;
	wrs_params->is_logger_en = true;

	pr_debug("[WRS] Logger of sta_idx %u enabled\n", sta_idx);
}

static void cl_wrs_cli_logger_free(struct cl_wrs_params *wrs_params, u8 sta_idx)
{
	kfree(wrs_params->logger);
	wrs_params->logger = NULL;

	wrs_params->logger_size = 0;
	wrs_params->logger_idx = 0;
	wrs_params->is_logger_en = false;

	pr_debug("[WRS] Logger of sta_idx %u disabled\n", sta_idx);
}

static void cl_wrs_cli_logger_config(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
				     u8 sta_idx, u8 type, bool enable, u16 logger_size)
{
	struct cl_wrs_sta *wrs_sta = NULL;
	struct cl_wrs_params *wrs_params = NULL;

	cl_sta_lock_bh(cl_hw);
	wrs_sta = cl_wrs_sta_get(cl_hw, sta_idx);

	if (!wrs_sta) {
		pr_err("[WRS] Invalid sta_idx [%u]\n", sta_idx);
		goto out;
	}

	if (type >= WRS_TYPE_MAX) {
		pr_err("[WRS] Invalid type [%u]\n", type);
		goto out;
	}

	wrs_params = cl_wrs_params_get(wrs_sta, type);

	if (!wrs_params) {
		pr_err("[WRS] params is NULL\n");
		goto out;
	}

	if (enable && !is_power_of_2(logger_size)) {
		pr_err("[WRS] Logger size [%u] must be power of 2!\n", logger_size);
		goto out;
	}

	if (enable == wrs_params->is_logger_en && logger_size == wrs_params->logger_size) {
		pr_debug("[WRS] Logger config not changed!\n");
		goto out;
	}

	if (enable) {
		if (wrs_params->is_logger_en)
			cl_wrs_cli_logger_free(wrs_params, sta_idx);

		cl_wrs_cli_logger_alloc(wrs_params, sta_idx, logger_size);
	} else {
		cl_wrs_cli_logger_free(wrs_params, sta_idx);
	}

out:
	cl_sta_unlock_bh(cl_hw);
}

static int cl_wrs_cli_logger_print(struct cl_hw *cl_hw,
				   struct cl_wrs_db *wrs_db,
				   u8 sta_idx, u8 type)
{
	struct cl_wrs_sta *wrs_sta = NULL;
	struct cl_wrs_params *wrs_params = NULL;
	struct cl_wrs_logger *logger = NULL;
	u16 loop_idx = 0, print_idx = 0;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	if (type >= WRS_TYPE_MAX) {
		pr_err("[WRS] Invalid type [%u]\n", type);
		return 0;
	}

	cl_sta_lock_bh(cl_hw);
	wrs_sta = cl_wrs_sta_get(cl_hw, sta_idx);

	if (!wrs_sta) {
		cl_snprintf(&buf, &len, &buf_size, "[WRS] Invalid sta_idx [%u]\n", sta_idx);
		goto out;
	}

	wrs_params = cl_wrs_params_get(wrs_sta, type);

	if (!wrs_params) {
		cl_snprintf(&buf, &len, &buf_size, "[WRS] params is NULL\n");
		goto out;
	}

	if (!wrs_params->is_logger_en) {
		cl_snprintf(&buf, &len, &buf_size, "[WRS] Logger disabled\n");
		goto out;
	}

	print_idx = (wrs_params->logger_idx + 1);

	cl_snprintf(&buf, &len, &buf_size,
		    "=================================\n");
	cl_snprintf(&buf, &len, &buf_size,
		    " Logger - sta_idx [%u] type [%s]\n",
		    sta_idx, WRS_TYPE_STR(wrs_params->type));
	cl_snprintf(&buf, &len, &buf_size,
		    "=================================\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "timestamp,rate_idx,success,fail,ba_not_rcv,curr_epr,down_epr,"
		    "down_epr_factorized,penalty,up_time,decision,new_rate_idx\n");

	for (loop_idx = 0; loop_idx < (wrs_params->logger_size - 1);
	     loop_idx++) {
		logger = &wrs_params->logger[print_idx];

		if (logger->timestamp) {
			cl_snprintf(&buf, &len, &buf_size, "%lu.%lu,", logger->timestamp / 1000,
				    logger->timestamp % 1000);
			cl_snprintf(&buf, &len, &buf_size, "%u,", logger->rate_idx);
			cl_snprintf(&buf, &len, &buf_size, "%u,", logger->success);
			cl_snprintf(&buf, &len, &buf_size, "%u,", logger->fail);
			cl_snprintf(&buf, &len, &buf_size, "%u,", logger->ba_not_rcv);
			cl_snprintf(&buf, &len, &buf_size, "%u,", logger->curr_epr);
			cl_snprintf(&buf, &len, &buf_size, "%u,", logger->down_epr);
			cl_snprintf(&buf, &len, &buf_size, "%u,", logger->down_epr_factorized);
			cl_snprintf(&buf, &len, &buf_size, "%u,", logger->penalty);
			cl_snprintf(&buf, &len, &buf_size, "%u,", logger->up_time);
			cl_snprintf(&buf, &len, &buf_size, "%s,",
				    WRS_DECISION_STR(logger->decision));
			cl_snprintf(&buf, &len, &buf_size, "%u\n", logger->new_rate_idx);
		}

		print_idx = WRS_INC_POW2(print_idx, wrs_params->logger_size);
	}

out:
	cl_sta_unlock_bh(cl_hw);
	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_wrs_cli_logger_reset(struct cl_hw *cl_hw,
				   struct cl_wrs_db *wrs_db,
				   u8 sta_idx, u8 type)
{
	struct cl_wrs_sta *wrs_sta = NULL;
	struct cl_wrs_params *wrs_params = NULL;

	cl_sta_lock_bh(cl_hw);
	wrs_sta = cl_wrs_sta_get(cl_hw, sta_idx);

	if (!wrs_sta) {
		pr_err("[WRS] Invalid sta_idx [%u]\n", sta_idx);
		goto out;
	}

	wrs_params = cl_wrs_params_get(wrs_sta, type);

	if (!wrs_params) {
		pr_err("[WRS] params is NULL\n");
		goto out;
	}

	if (wrs_params->is_logger_en) {
		u32 total_logger_size = wrs_params->logger_size * sizeof(struct cl_wrs_logger);

		memset(wrs_params->logger, 0, total_logger_size);
		wrs_params->logger_idx = 0;
	}

	pr_debug("[WRS] Reset logger for sta_idx [%u]\n", sta_idx);

out:
	cl_sta_unlock_bh(cl_hw);

	return 0;
}

static void cl_wrs_cli_immediate_drop_set(struct cl_wrs_db *wrs_db, bool enable,
					  u8 epr_factor, u32 max_in_row)
{
	wrs_db->immediate_drop_en = enable;
	wrs_db->immediate_drop_epr_factor = epr_factor;
	wrs_db->immediate_drop_max_in_row = max_in_row;

	pr_debug("[WRS] Set immediate drop: %s, epr_factor = %u, max_in_row = %u\n",
		 enable ? "enable" : "disable", epr_factor, max_in_row);
}

static void cl_wrs_cli_step_max_min_set(struct cl_wrs_db *wrs_db, u16 step_dn, u16 step_same_up,
					u16 time_th_min, u16 time_th_max_up, u16 time_th_max_down)
{
	wrs_db->step_down = step_dn;
	wrs_db->step_up_same = step_same_up;
	wrs_db->time_th_min = time_th_min;
	wrs_db->time_th_max_up = time_th_max_up;
	wrs_db->time_th_max_down = time_th_max_down;

	pr_debug("------------------------------------------\n");
	pr_debug("Set steps and up/down decision thresholds:\n");
	pr_debug("------------------------------------------\n");
	pr_debug("Step down decision    = [%u]\n", wrs_db->step_down);
	pr_debug("Step same/up Decision = [%u]\n", wrs_db->step_up_same);
	pr_debug("Min threshold         = [%u]\n", wrs_db->time_th_min);
	pr_debug("Max threshold up      = [%u]\n", wrs_db->time_th_max_up);
	pr_debug("Max threshold down    = [%u]\n", wrs_db->time_th_max_down);
}

static void cl_wrs_cli_down_up_thr_set(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
				       u8 sta_idx, u8 type, u16 time_th_dn, u16 time_th_up_mcs,
				       u16 time_th_up_nss, u16 time_th_up_bw, u16 time_th_up_bf,
				       u16 time_th_up_gi)
{
	struct cl_wrs_sta *wrs_sta = NULL;
	struct cl_wrs_params *wrs_params = NULL;
	u16 rate_idx = 0;

	if (type >= WRS_TYPE_MAX) {
		pr_err("[WRS] Invalid type [%u]\n", type);
		return;
	}

	cl_sta_lock_bh(cl_hw);
	wrs_sta = cl_wrs_sta_get(cl_hw, sta_idx);

	if (!wrs_sta) {
		cl_sta_unlock_bh(cl_hw);
		pr_err("[WRS] Invalid sta_idx [%u]\n", sta_idx);
		return;
	}

	wrs_params = cl_wrs_params_get(wrs_sta, type);

	if (!wrs_params) {
		cl_sta_unlock_bh(cl_hw);
		pr_err("[WRS] params is NULL\n");
		return;
	}

	for (rate_idx = 0; rate_idx < wrs_params->table_size; rate_idx++) {
		wrs_params->table->rate_down.time_th = time_th_dn;
		wrs_params->table->rate_up[WRS_TABLE_NODE_UP_MCS].time_th = time_th_up_mcs;
		wrs_params->table->rate_up[WRS_TABLE_NODE_UP_BW].time_th = time_th_up_bw;
		wrs_params->table->rate_up[WRS_TABLE_NODE_UP_NSS].time_th = time_th_up_nss;
		wrs_params->table->rate_up[WRS_TABLE_NODE_UP_BF].time_th = time_th_up_bf;
		wrs_params->table->rate_up[WRS_TABLE_NODE_UP_GI].time_th = time_th_up_gi;
	}

	cl_sta_unlock_bh(cl_hw);

	pr_debug("Table thresholds - station [%u]\n", sta_idx);
	pr_debug("------------------------------------------\n");
	pr_debug("Down   = %u\n", time_th_dn);
	pr_debug("Up mcs = %u\n", time_th_up_mcs);
	pr_debug("Up nss = %u\n", time_th_up_nss);
	pr_debug("Up bw  = %u\n", time_th_up_bw);
	pr_debug("Up bf  = %u\n", time_th_up_bf);
	pr_debug("Up gi  = %u\n", time_th_up_gi);
}

static void cl_wrs_cli_main_print(struct cl_sta *cl_sta, struct cl_wrs_sta *wrs_sta,
				  struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_rate_params *rate_params = &wrs_params->rate_params;

	pr_debug("\n");
	pr_debug("--------------------------------------------\n");
	pr_debug("WRS info for station %u - %pM\n", cl_sta->sta_idx, cl_sta->addr);
	pr_debug("--------------------------------------------\n");
	pr_debug("Settings      = [%s]\n", FIXED_RATE_STR(wrs_params->is_fixed_rate));
	pr_debug("Converge mode = [%s]\n", WRS_CONVERGE_MODE_STR(wrs_params->converge_mode));
	pr_debug("Synced        = [%s]\n", wrs_params->sync ? "True" : "False");
	pr_debug("Type          = [%s]\n", WRS_TYPE_STR(wrs_params->type));
	pr_debug("Mode          = [%s]\n", WRS_MODE_STR(rate_params->mode));

	if (WRS_TYPE_IS_TX_SU(wrs_params)) {
		if (wrs_sta->mu_ofdma_bw != CHNL_BW_MAX)
			pr_debug("MU-OFDMA BW   = [%s]\n", WRS_BW_STR(wrs_sta->mu_ofdma_bw));

		if (wrs_sta->mu_ofdma_gi != WRS_GI_MAX_HE)
			pr_debug("MU-OFDMA GI   = [%s]\n", WRS_GI_STR(wrs_sta->mu_ofdma_gi));
	}

	if (wrs_sta->mode == rate_params->mode)
		pr_debug("Rate index    = [%u]\n", wrs_params->rate_idx);

	pr_debug("Rate params   = [bw=%s, nss=%u, mcs=%u, gi=%s]\n",
		 WRS_BW_STR(rate_params->bw),
		 rate_params->nss,
		 rate_params->mcs,
		 WRS_GI_STR(rate_params->gi));
}

static void cl_wrs_cli_sta_db_print(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
				    u8 sta_idx, u8 type, u32 print_type)
{
	struct cl_wrs_sta *wrs_sta = NULL;
	struct cl_wrs_params *wrs_params = NULL;
	struct cl_sta *cl_sta = NULL;

	if (type >= WRS_TYPE_MAX) {
		pr_err("[WRS] Invalid type [%u]\n", type);
		return;
	}

	cl_sta_lock_bh(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		wrs_sta = &cl_sta->wrs_sta;

		if (sta_idx != WRS_ALL_STA && sta_idx != wrs_sta->sta_idx)
			continue;

		wrs_params = cl_wrs_params_get(wrs_sta, type);

		if (!wrs_params)
			continue;

		cl_wrs_cli_main_print(cl_sta, wrs_sta, wrs_params);

		if (print_type & 0x1)
			cl_wrs_tables_print(cl_hw, wrs_params);

		if (print_type & 0x2)
			cl_wrs_stats_decision_print(wrs_params);

		if (print_type & 0x4)
			cl_wrs_stats_per_print(cl_hw, wrs_sta, wrs_params);
	}

	cl_sta_unlock_bh(cl_hw);

	if (sta_idx == WRS_ALL_STA)
		pr_debug("*** END OF WRS STATS ***\n");
}

static void cl_wrs_cli_sta_db_reset(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
				    u8 sta_idx, u8 type, u32 reset_type)
{
	struct cl_wrs_sta *wrs_sta = NULL;
	struct cl_wrs_params *wrs_params = NULL;
	struct cl_sta *cl_sta = NULL;

	if (type >= WRS_TYPE_MAX) {
		pr_err("[WRS] Invalid type [%u]\n", type);
		return;
	}

	cl_sta_lock_bh(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		wrs_sta = &cl_sta->wrs_sta;

		if (sta_idx != WRS_ALL_STA && sta_idx != wrs_sta->sta_idx)
			continue;

		wrs_params = cl_wrs_params_get(wrs_sta, type);

		if (!wrs_params)
			continue;

		if (reset_type & 0x1)
			cl_wrs_tables_reset(wrs_db, wrs_sta, wrs_params);

		if (reset_type & 0x2)
			cl_wrs_stats_decision_reset(wrs_params);

		if (reset_type & 0x4)
			cl_wrs_stats_per_reset(wrs_params);
	}

	cl_sta_unlock_bh(cl_hw);
}

static void cl_wrs_cli_sync_params_set(struct cl_wrs_db *wrs_db,
				       u16 sync_timeout, u8 sync_min_attempts)
{
	wrs_db->sync_timeout = sync_timeout;
	wrs_db->sync_min_attempts = sync_min_attempts;
	pr_debug("[WRS] sync_timeout = %u, sync_min_attempts = %u\n",
		 sync_timeout, sync_min_attempts);
}

static void cl_wrs_cli_min_frames_decision_set(struct cl_wrs_db *wrs_db, u32 min_frames)
{
	wrs_db->min_frames_for_decision = min_frames;
	pr_debug("[WRS] min_frames_for_decision = %u\n", min_frames);
}

static void cl_wrs_cli_conservative_mode_set(struct cl_wrs_db *wrs_db,
					     bool conservative_mcs, bool conservative_nss)
{
	wrs_db->conservative_mcs_noisy_env = conservative_mcs;
	wrs_db->conservative_nss_noisy_env = conservative_nss;

	pr_debug("[WRS] Conservative mode - mcs = %s, nss = %s\n",
		 conservative_mcs ? "true" : "false",
		 conservative_nss ? "true" : "false");
}

static void cl_wrs_cli_quick_up_set(struct cl_wrs_db *wrs_db, bool enable, u8 ba_thr, u16 interval)
{
	wrs_db->quick_up_en = enable;
	wrs_db->quick_up_ba_thr = ba_thr;
	wrs_db->quick_up_interval = msecs_round(interval);

	pr_debug("[WRS] Quick up: enable = %s, ba_thr = %u, interval = %u\n",
		 wrs_db->quick_up_en ? "true" : "false",
		 wrs_db->quick_up_ba_thr,
		 wrs_db->quick_up_interval);
}

static void cl_wrs_cli_quick_down_set(struct cl_wrs_db *wrs_db, bool enable,
				      u8 epr_factor, u8 agg_thr, u16 pkt_thr)
{
	wrs_db->quick_down_en = enable;
	wrs_db->quick_down_epr_factor = epr_factor;
	wrs_db->quick_down_agg_thr = agg_thr;
	wrs_db->quick_down_pkt_thr = pkt_thr;

	pr_debug("[WRS] Quick down: enable = %s, epr_factor = %u, agg_thr = %u, pkt_thr = %u\n",
		 enable ? "true" : "false", epr_factor, agg_thr, pkt_thr);
}

static void cl_wrs_cli_ba_not_rcv_set(struct cl_wrs_db *wrs_db, bool collision_filter,
				      bool force, u32 time_since_sync)
{
	wrs_db->ba_not_rcv_collision_filter = collision_filter;
	wrs_db->ba_not_rcv_force = force;
	wrs_db->ba_not_rcv_time_since_sync = msecs_round(time_since_sync);

	pr_debug("[WRS] BA not received: collision_filter = %s, force = %s, time_since_sync = %u\n",
		 wrs_db->ba_not_rcv_collision_filter ? "true" : "false",
		 wrs_db->ba_not_rcv_force ? "true" : "false",
		 wrs_db->ba_not_rcv_time_since_sync);
}

static void cl_wrs_cli_fixed_rate_set_vif(struct cl_hw *cl_hw, struct cl_vif *cl_vif,
					  struct cl_wrs_db *wrs_db, bool is_fixed,
					  u8 mode, u8 bw, u8 nss, u8 mcs, u8 gi)
{
	struct cl_sta *cl_sta = NULL;
	struct cl_wrs_rate_params *vif_fixed_params = &cl_vif->fixed_params;
	u8 fixed_rate_mode = is_fixed ? WRS_FIXED_FALLBACK_DIS : WRS_AUTO_RATE;

	vif_fixed_params->is_fixed = is_fixed;
	vif_fixed_params->mode = mode;
	vif_fixed_params->bw = bw;
	vif_fixed_params->nss = nss;
	vif_fixed_params->mcs = mcs;
	vif_fixed_params->gi = gi;

	cl_sta_lock_bh(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list)
		if (cl_sta->cl_vif->vif_index == cl_vif->vif_index)
			cl_wrs_cli_fixed_rate_set(cl_hw, wrs_db, cl_sta->sta_idx, fixed_rate_mode,
						  mode, bw, nss, mcs, gi, WRS_TYPE_TX_SU);

	cl_sta_unlock_bh(cl_hw);
}

static int cl_wrs_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;
	int len = 0;

	if (!buf)
		return -ENOMEM;

	len += snprintf(buf, PAGE_SIZE,
			"wrs usage\n"
			"-a : Print station list\n"
			"-b : Set maintenance interval [ms]\n"
			"-c : Print configuration\n"
			"-d : Set debug level [0-off, 1-error, 2-warning, "
				"3-trace, 4-info]\n"
			"-e : Set initial rate [sta_idx].[bw].[nss].[mcs]."
				"[gi]\n"
			"-f : Set fixed rate [sta_idx].[0-auto,1-fixed "
				"fallback en,2-fixed fallback dis].[mode]."
				"[bw].[nss].[mcs].[gi].[type (opt)]\n"
			"-g : Set converge idle parameters [0-en, "
				"1-interval_reset, 2-interval_rssi, "
				"3-packet_th].[value]\n"
			"-h : Set converge trfc parameters [0-en, 1-interval_static]."
				"[value]\n"
			"-i : Configure logger [sta_idx].[0-disable/1-enable]."
				"[size (power of 2)].[type (opt)]\n"
			"-j : Logger action [sta_idx].[0-reset, 1-print].[type (opt)]\n"
			"-k : Set EPR factor [factor]\n"
			"-l : Set immediate drop [0-disable/1-enable]."
				"[per factor].[max in row]\n"
			"-m : Print rssi protect debug [sta_idx]\n"
			"-n : Set rssi protect parameters [enable 0/1]."
				"[mode 0-rssi/1-neighbor].[rssi up thr]."
				"[rssi down th]\n"
			"-o : Set step and time thresholds [step down]."
				"[step same up].[time min].[time max up]."
				"[time max down]\n"
			"-p : Set down and up time thresholds [sta_idx]."
				"[down].[up mcs].[up nss].[up bw].[up bf]."
				"[up gi].[type (opt)]\n"
			"-q : Reset and print station data [sta_idx].[op:"
				" 1-weights, 2-decisions, 4-per, 7-all)].[type (opt)]\n"
			"-r : Reset station data [sta_idx].[op: 1-weights, "
				"2-decisions, 4-per, 7-all)].[type (opt)]\n"
			"-s : Print station data [sta_idx].[op: 1-weights, "
				"2-decisions, 4-per, 7-all)].[type (opt)]\n"
			"-t : Set sync parameters [timeout].[min attempts]\n"
			"-u : Set minimum frames for decision [min frames]\n"
			"-v : Set conservative mode [mcs-0/1].[nss-0/1]\n"
			"-w : Set quick up [enable].[ba_thr].[interval]\n"
			"-x : Set quick down [enable].[epr factor]."
				"[agg thr][pkt thr]\n"
			"-y : Set BA not received [collision filter][force]."
				"[time since sync]\n"
			"-z : Set fixed rate per interface [0-auto,1-fixed]."
				"[mode].[bw].[nss].[mcs].[gi]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_wrs_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cli_params *cli_params)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	u32 expected_params_min = 0;
	u32 expected_params_max = 0;
	bool sta_list_print = false;
	bool interval_set = false;
	bool config_print = false;
	bool set_debug_level = false;
	bool initial_rate_set = false;
	bool fixed_rate = false;
	bool converge_idle_set = false;
	bool converge_trfc_set = false;
	bool logger_config = false;
	bool logger_action = false;
	bool epr_factor_set = false;
	bool immediate_drop_set = false;
	bool rssi_prot_print = false;
	bool rssi_protect_set = false;
	bool set_step_max_min_th = false;
	bool set_up_dn_th = false;
	bool print_reset_sta_db = false;
	bool reset_sta_db = false;
	bool print_sta_db = false;
	bool sync_params_set = false;
	bool min_frames_set = false;
	bool conservative_mode_set = false;
	bool quick_up_set = false;
	bool quick_down_set = false;
	bool ba_not_rcv_set = false;
	bool fixed_rate_vif = false;

	switch (cli_params->option) {
	case 'a':
		sta_list_print = true;
		expected_params_min = 0;
		expected_params_max = 0;
		break;
	case 'b':
		interval_set = true;
		expected_params_min = 1;
		expected_params_max = 1;
		break;
	case 'c':
		config_print = true;
		expected_params_min = 0;
		expected_params_max = 0;
		break;
	case 'd':
		set_debug_level = true;
		expected_params_min = 1;
		expected_params_max = 1;
		break;
	case 'e':
		initial_rate_set = true;
		expected_params_min = 5;
		expected_params_max = 5;
		break;
	case 'f':
		fixed_rate = true;
		expected_params_min = 7;
		expected_params_max = 8;
		break;
	case 'g':
		converge_idle_set = true;
		expected_params_min = 2;
		expected_params_max = 2;
		break;
	case 'h':
		converge_trfc_set = true;
		expected_params_min = 2;
		expected_params_max = 2;
		break;
	case 'i':
		logger_config = true;
		expected_params_min = 3;
		expected_params_max = 4;
		break;
	case 'j':
		logger_action = true;
		expected_params_min = 2;
		expected_params_max = 3;
		break;
	case 'k':
		epr_factor_set = true;
		expected_params_min = 1;
		expected_params_max = 1;
		break;
	case 'l':
		immediate_drop_set = true;
		expected_params_min = 3;
		expected_params_max = 3;
		break;
	case 'm':
		rssi_prot_print = true;
		expected_params_min = 1;
		expected_params_max = 1;
		break;
	case 'n':
		rssi_protect_set = true;
		expected_params_min = 3;
		expected_params_max = 3;
		break;
	case 'o':
		set_step_max_min_th = true;
		expected_params_min = 5;
		expected_params_max = 5;
		break;
	case 'p':
		set_up_dn_th = true;
		expected_params_min = 7;
		expected_params_max = 8;
		break;
	case 'q':
		print_reset_sta_db = true;
		expected_params_min = 2;
		expected_params_max = 3;
		break;
	case 'r':
		reset_sta_db = true;
		expected_params_min = 2;
		expected_params_max = 3;
		break;
	case 's':
		print_sta_db = true;
		expected_params_min = 2;
		expected_params_max = 3;
		break;
	case 't':
		sync_params_set = true;
		expected_params_min = 2;
		expected_params_max = 2;
		break;
	case 'u':
		min_frames_set = true;
		expected_params_min = 1;
		expected_params_max = 1;
		break;
	case 'v':
		conservative_mode_set = true;
		expected_params_min = 2;
		expected_params_max = 2;
		break;
	case 'w':
		quick_up_set = true;
		expected_params_min = 3;
		expected_params_max = 3;
		break;
	case 'x':
		quick_down_set = true;
		expected_params_min = 4;
		expected_params_max = 4;
		break;
	case 'y':
		ba_not_rcv_set = true;
		expected_params_min = 3;
		expected_params_max = 3;
		break;
	case 'z':
		fixed_rate_vif = true;
		expected_params_min = 6;
		expected_params_max = 6;
		break;
	case '?':
		return cl_wrs_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (cli_params->num_params < expected_params_min ||
	    cli_params->num_params > expected_params_max) {
		if (expected_params_min == expected_params_max)
			cl_dbg_err(cl_hw,
				   "Wrong number of arguments (expected %u) (actual %u)\n",
				   expected_params_min, cli_params->num_params);
		else
			cl_dbg_err(cl_hw,
				   "Wrong number of arguments (expected %u/%u) (actual %u)\n",
				   expected_params_min, expected_params_max,
				   cli_params->num_params);

		goto out_err;
	}

	if (sta_list_print) {
		cl_wrs_sta_print_list(cl_hw, wrs_db);
		return 0;
	}

	if (interval_set) {
		u32 interval = (u32)cli_params->params[0];

		cl_wrs_cli_interval_set(wrs_db, interval);
		return 0;
	}

	if (config_print) {
		cl_wrs_cli_config_print(cl_hw);
		return 0;
	}

	if (set_debug_level) {
		u32 debug_level = (u32)cli_params->params[0];

		cl_wrs_cli_dbg_level_set(wrs_db, debug_level);
		return 0;
	}

	if (initial_rate_set) {
		u8 sta_idx = (u8)cli_params->params[0];
		u8 bw = (u8)cli_params->params[1];
		u8 nss = (u8)cli_params->params[2];
		u8 mcs = (u8)cli_params->params[3];
		u8 gi = (u8)cli_params->params[4];

		cl_wrs_cli_initial_rate_set(cl_hw, wrs_db, sta_idx, bw, nss, mcs, gi);
		return 0;
	}

	if (fixed_rate) {
		u8 sta_idx  = (u8)cli_params->params[0];
		u8 is_fixed_rate = (u8)cli_params->params[1];
		u8 mode = (u8)cli_params->params[2];
		u8 bw = (u8)cli_params->params[3];
		u8 nss = (u8)cli_params->params[4];
		u8 mcs = (u8)cli_params->params[5];
		u8 gi = (u8)cli_params->params[6];
		u8 type = WRS_TYPE_TX_SU;

		if (expected_params_max == 8)
			type = (u8)cli_params->params[7];

		cl_wrs_cli_fixed_rate_set(cl_hw, wrs_db, sta_idx, is_fixed_rate,
					  mode, bw, nss, mcs, gi, type);
		return 0;
	}

	if (converge_idle_set) {
		u32 param = (u32)cli_params->params[0];
		u32 value = (u32)cli_params->params[1];

		cl_wrs_cli_converge_idle_param_set(wrs_db, param, value);
		return 0;
	}

	if (converge_trfc_set) {
		u32 param = (u32)cli_params->params[0];
		u32 value = (u32)cli_params->params[1];

		cl_wrs_cli_converge_trfc_param_set(wrs_db, param, value);
		return 0;
	}

	if (logger_config) {
		u8 sta_idx = (u8)cli_params->params[0];
		bool is_en = (bool)cli_params->params[1];
		u16 logger_size = (u16)cli_params->params[2];
		u8 type = WRS_TYPE_TX_SU;

		if (expected_params_max == 4)
			type = (u8)cli_params->params[3];

		cl_wrs_cli_logger_config(cl_hw, wrs_db, sta_idx, type, is_en, logger_size);
		return 0;
	}

	if (logger_action) {
		u8 sta_idx = (u8)cli_params->params[0];
		u8 action = (u8)cli_params->params[1];
		u8 type = WRS_TYPE_TX_SU;

		if (expected_params_max == 3)
			type = (u8)cli_params->params[2];

		if (action)
			return cl_wrs_cli_logger_print(cl_hw, wrs_db, sta_idx, type);
		else
			return cl_wrs_cli_logger_reset(cl_hw, wrs_db, sta_idx, type);
	}

	if (epr_factor_set) {
		wrs_db->epr_factor = (u8)cli_params->params[0];
		pr_debug("[WRS] epr_factor = %u\n", wrs_db->epr_factor);
		return 0;
	}

	if (immediate_drop_set) {
		bool is_en = (bool)cli_params->params[0];
		u8 epr_factor = (u8)cli_params->params[1];
		u32 max_in_row = (u32)cli_params->params[2];

		cl_wrs_cli_immediate_drop_set(wrs_db, is_en, epr_factor, max_in_row);
		return 0;
	}

	if (rssi_prot_print) {
		u8 sta_idx = (u8)cli_params->params[0];
		struct cl_wrs_sta *wrs_sta;

		cl_sta_lock_bh(cl_hw);
		wrs_sta = cl_wrs_sta_get(cl_hw, sta_idx);

		if (wrs_sta)
			cl_wrs_rssi_prot_dbg(cl_hw, wrs_db, wrs_sta);
		else
			pr_err("[WRS] Invalid sta_idx [%u]\n", sta_idx);

		cl_sta_unlock_bh(cl_hw);

		return 0;
	}

	if (rssi_protect_set) {
		bool enable = (bool)cli_params->params[0];
		bool mode = (bool)cli_params->params[1];
		s32 rssi_up_th = cli_params->params[2];
		s32 rssi_dn_th = cli_params->params[3];

		cl_wrs_rssi_prot_config(cl_hw, wrs_db, enable, mode, rssi_up_th, rssi_dn_th);
		return 0;
	}

	if (set_step_max_min_th) {
		u16 step_dn = (u16)cli_params->params[0];
		u16 step_same_up = (u16)cli_params->params[1];
		u16 time_th_min = (u16)cli_params->params[2];
		u16 time_th_max_up = (u16)cli_params->params[3];
		u16 time_th_max_down = (u16)cli_params->params[4];

		cl_wrs_cli_step_max_min_set(wrs_db, step_dn, step_same_up,
					    time_th_min, time_th_max_up, time_th_max_down);
		return 0;
	}

	if (set_up_dn_th) {
		u8 sta_idx = (u8)cli_params->params[0];
		u16 time_th_dn = (u16)cli_params->params[1];
		u16 time_th_up_mcs = (u16)cli_params->params[2];
		u16 time_th_up_nss = (u16)cli_params->params[3];
		u16 time_th_up_bw = (u16)cli_params->params[4];
		u16 time_th_up_bf = (u16)cli_params->params[5];
		u16 time_th_up_gi = (u16)cli_params->params[6];
		u8 type = WRS_TYPE_TX_SU;

		if (expected_params_max == 8)
			type = (u8)cli_params->params[7];

		cl_wrs_cli_down_up_thr_set(cl_hw, wrs_db, sta_idx, type, time_th_dn,
					   time_th_up_mcs, time_th_up_nss, time_th_up_bw,
					   time_th_up_bf, time_th_up_gi);
		return 0;
	}

	if (print_reset_sta_db) {
		u8 sta_idx = (u8)cli_params->params[0];
		u32 print_type = (u32)cli_params->params[1];
		u8 type = WRS_TYPE_TX_SU;

		if (expected_params_max == 3)
			type = (u8)cli_params->params[2];

		cl_wrs_cli_sta_db_print(cl_hw, wrs_db, sta_idx, type, print_type);
		cl_wrs_cli_sta_db_reset(cl_hw, wrs_db, sta_idx, type, print_type);
		return 0;
	}

	if (reset_sta_db) {
		u8 sta_idx = (u8)cli_params->params[0];
		u32 reset_type = (u32)cli_params->params[1];
		u8 type = WRS_TYPE_TX_SU;

		if (expected_params_max == 3)
			type = (u8)cli_params->params[2];

		cl_wrs_cli_sta_db_reset(cl_hw, wrs_db, sta_idx, type, reset_type);
		return 0;
	}

	if (print_sta_db) {
		u8 sta_idx = (u8)cli_params->params[0];
		u32 print_type = (u32)cli_params->params[1];
		u8 type = WRS_TYPE_TX_SU;

		if (expected_params_max == 3)
			type = (u8)cli_params->params[2];

		cl_wrs_cli_sta_db_print(cl_hw, wrs_db, sta_idx, type, print_type);
		return 0;
	}

	if (sync_params_set) {
		u16 sync_timeout = (u16)cli_params->params[0];
		u8 sync_min_attempts = (u16)cli_params->params[1];

		cl_wrs_cli_sync_params_set(wrs_db, sync_timeout, sync_min_attempts);
		return 0;
	}

	if (min_frames_set) {
		u32 min_frames = (u32)cli_params->params[0];

		cl_wrs_cli_min_frames_decision_set(wrs_db, min_frames);
		return 0;
	}

	if (conservative_mode_set) {
		u32 conservative_mcs = (u32)cli_params->params[0];
		u32 conservative_nss = (u32)cli_params->params[1];

		cl_wrs_cli_conservative_mode_set(wrs_db, conservative_mcs, conservative_nss);
		return 0;
	}

	if (quick_up_set) {
		bool enable = (bool)cli_params->params[0];
		u8 ba_thr = (u8)cli_params->params[1];
		u16 interval = (u16)cli_params->params[2];

		cl_wrs_cli_quick_up_set(wrs_db, enable, ba_thr, interval);
		return 0;
	}

	if (quick_down_set) {
		bool enable = (bool)cli_params->params[0];
		u8 epr_factor = (u8)cli_params->params[1];
		u8 agg_thr = (u8)cli_params->params[2];
		u16 pkt_thr = (u16)cli_params->params[3];

		cl_wrs_cli_quick_down_set(wrs_db, enable, epr_factor, agg_thr, pkt_thr);
		return 0;
	}

	if (ba_not_rcv_set) {
		bool collision_filter = (bool)cli_params->params[0];
		bool force = (bool)cli_params->params[1];
		u32 time_since_sync = (u32)cli_params->params[2];

		cl_wrs_cli_ba_not_rcv_set(wrs_db, collision_filter, force, time_since_sync);
		return 0;
	}

	if (fixed_rate_vif) {
		bool is_fixed = (bool)cli_params->params[0];
		u8 mode = (u8)cli_params->params[1];
		u8 bw = (u8)cli_params->params[2];
		u8 nss = (u8)cli_params->params[3];
		u8 mcs = (u8)cli_params->params[4];
		u8 gi = (u8)cli_params->params[5];

		cl_wrs_cli_fixed_rate_set_vif(cl_hw, cl_vif, wrs_db,
					      is_fixed, mode, bw, nss, mcs, gi);
		return 0;
	}

out_err:
	return -EIO;
}
