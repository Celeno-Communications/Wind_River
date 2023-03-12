// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/kernel.h>
#include "cl_wrs.h"
#include "cl_wrs_stats.h"
#include "cl_wrs_tables.h"
#include "cl_wrs_rssi.h"
#include "cl_env_det.h"
#include "cl_math.h"
#include "cl_rssi.h"
#include "cl_band.h"
#include "cl_rate_ctrl.h"
#include "chip.h"
#include "cl_dyn_bcast_rate.h"
#include "cl_msg_tx.h"
#include "cl_data_rates.h"

static void cl_wrs_reset_params_cntrs(struct cl_wrs_params *wrs_params)
{
	wrs_params->frames_total = 0;
	wrs_params->fail_total = 0;
	wrs_params->ba_not_rcv_total = 0;
	wrs_params->epr_acc = 0;
	wrs_params->up_same_time_cnt = 0;
	wrs_params->down_time_cnt = 0;
}

static bool cl_wrs_down_epr_check(struct cl_wrs_db *wrs_db, struct cl_wrs_sta *wrs_sta,
				  struct cl_wrs_params *wrs_params, u8 drop_factor,
				  enum cl_wrs_decision decision)
{
	u16 curr_rate_idx = wrs_params->rate_idx;
	struct cl_wrs_table *curr_rate = &wrs_params->table[curr_rate_idx];
	u64 curr_epr_acc = curr_rate->epr_acc;
	u32 curr_total = curr_rate->frames_total;
	u16 down_rate_idx = curr_rate->rate_down.rate_idx;
	struct cl_wrs_table *down_rate = &wrs_params->table[down_rate_idx];
	u64 down_epr_acc = down_rate->epr_acc;
	u32 down_total = down_rate->frames_total;
	u16 down_data_rate = 0;
	u64 condition1 = 0, condition2 = 0;
	bool down_decision = false, allow_penalty = true;

	if (wrs_params->calc_ba_not_rcv) {
		curr_total += curr_rate->ba_not_rcv_total;
		down_total += down_rate->ba_not_rcv_total;
	}

	/*
	 * In the EPR of down candidate is better than or equal to current EPR => return true
	 *
	 * (1) curr_epr <= down_epr * factor(%)
	 *
	 *       curr_epr_acc     down_epr_acc     factor
	 * (2)  -------------- <= -------------- * --------
	 *        curr_total       down_total       100
	 *
	 * (3) curr_epr_acc * down_total * 100 <= down_epr_acc * curr_total * factor
	 *
	 * (4) conditation1 <= conditation2
	 *                                                         down_epr_acc
	 * If (down_total == 0) we use down_data_rate instead of: --------------
	 *                                                          down_total
	 */
	if (down_total) {
		condition1 = curr_epr_acc * down_total * 100;
		condition2 = down_epr_acc * curr_total * drop_factor;
	} else {
		down_data_rate = cl_data_rates_get_x10(wrs_params->rate_params.mode,
						       down_rate->rate.bw,
						       down_rate->rate.nss,
						       down_rate->rate.mcs,
						       down_rate->rate.gi);

		condition1 = curr_epr_acc * 100;
		condition2 = (u64)down_data_rate * curr_total * drop_factor;
		allow_penalty = false;
	}

	wrs_params->penalty_decision_dn = wrs_db->step_down;

	if (condition2 && condition1 <= condition2) {
		down_decision = true;

		if (allow_penalty) {
			/*
			 * The penalty is calculated as follow:
			 *
			 * penalty = MAX_STEP * penalty_factor
			 *                                      epr_curr
			 * penalty = MAX_STEP * (100% - 100% * ----------)
			 *                                      epr_down
			 *
			 *                                    conditation1
			 * penalty = MAX_STEP * (100% - 100% --------------)
			 *                                    conditation2
			 */

			u64 penalty_factor = 100 - div64_u64(condition1 * 100, condition2);
			u16 max_step = wrs_db->time_th_max_up - wrs_db->step_down;

			wrs_params->penalty_decision_dn +=
				div64_u64(max_step * penalty_factor, 100);
		}

		if (decision != WRS_DECISION_SAME)
			wrs_pr_info(wrs_db,
				    "[WRS][%s] EPR check: sta = %u, pkt_curr = %u, "
				    "pkt_down = %u, epr_curr = %llu, epr_down * %u%% = %llu, "
				    "penalty = %u\n",
				    WRS_TYPE_STR(wrs_params->type),
				    wrs_sta->sta_idx,
				    curr_total,
				    down_total,
				    div64_u64(curr_epr_acc, curr_total * 10),
				    drop_factor,
				    down_total ?
				    div64_u64(down_epr_acc * drop_factor, down_total * 1000) :
				    (down_data_rate / 10),
				    wrs_params->penalty_decision_dn);
	}

	if (wrs_params->is_logger_en && down_decision) {
		WRS_LOGGER.curr_epr = (u16)div64_u64(curr_epr_acc, 10 * curr_total);
		WRS_LOGGER.down_epr = down_total ?
			(u16)div64_u64(down_epr_acc, down_total * 10) : (down_data_rate / 10),
		WRS_LOGGER.down_epr_factorized = WRS_LOGGER.down_epr * drop_factor / 100;
		WRS_LOGGER.penalty = wrs_params->penalty_decision_dn;
	}

	return down_decision;
}

static void cl_wrs_time_thr_max_handler(struct cl_wrs_db *wrs_db,
					struct cl_wrs_table *table, u8 up_idx)
{
	/*
	 * Check if there are at least two UP rates,
	 * and all UP rates reached max time threshold
	 */
	u8 i = 0;
	u8 time_th_max = 0;

	for (i = 0; i < WRS_TABLE_NODE_UP_MAX; i++) {
		if (table->rate_up[i].rate_idx == WRS_INVALID_RATE)
			continue;

		if (table->rate_up[i].time_th != wrs_db->time_th_max_up)
			return;

		time_th_max++;
	}

	if (time_th_max < 2)
		return;

	/* Find the next max rate, and decrease its time threshold by 1 */
	i = 0;
	while (i < WRS_TABLE_NODE_UP_MAX) {
		up_idx++;
		if (up_idx == WRS_TABLE_NODE_UP_MAX)
			up_idx = WRS_TABLE_NODE_UP_MCS;

		if (table->rate_up[up_idx].rate_idx != WRS_INVALID_RATE) {
			/*
			 * If all up rates reached max time threshold,the first up
			 * rate will always be selected.
			 * To overcome it, we decrease the time threshold of the next
			 * up rate by 1 (so it will be samller and selected next time)
			 */
			table->rate_up[up_idx].time_th--;
			break;
		}

		i++;
	}
}

static bool cl_wrs_find_up_candidate(struct cl_wrs_db *wrs_db, struct cl_wrs_params *wrs_params,
				     u16 *up_rate_idx, u32 *up_time_th)
{
	bool up_rate_valid = false;
	u8 up_idx = 0;
	u8 up_candidate = 0;
	u16 rate_idx = 0;
	struct cl_wrs_table *table = &wrs_params->table[wrs_params->rate_idx];

	*up_rate_idx = WRS_INVALID_RATE;
	*up_time_th = U32_MAX;

	for (up_idx = 0; up_idx < WRS_TABLE_NODE_UP_MAX; up_idx++) {
		rate_idx = table->rate_up[up_idx].rate_idx;

		if (rate_idx == WRS_INVALID_RATE)
			continue;

		if (wrs_db->quick_up_en && table->rate_up[up_idx].quick_up_check) {
			*up_rate_idx = rate_idx;
			*up_time_th = wrs_db->quick_up_interval;
			up_rate_valid = true;
			up_candidate = up_idx;
			break;
		} else if (table->rate_up[up_idx].time_th < *up_time_th) {
			*up_rate_idx = rate_idx;
			*up_time_th = table->rate_up[up_idx].time_th;
			up_rate_valid = true;
			up_candidate = up_idx;
		}
	}

	if (wrs_db->time_th_max_up == *up_time_th)
		cl_wrs_time_thr_max_handler(wrs_db, table, up_candidate);

	return up_rate_valid;
}

static bool cl_wrs_epr_immeidate_down(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
				      struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params,
				      u16 down_rate_idx)
{
	if (cl_wrs_down_epr_check(wrs_db, wrs_sta, wrs_params,
				  wrs_db->immediate_drop_epr_factor,
				  WRS_DECISION_DOWN_IMMEDIATE)) {
		/*
		 * If there are several immediate drops in a row ignore them,
		 * because it is probably not realted to bad TX rate
		 */
		wrs_params->immediate_drop_cntr++;

		if (wrs_params->immediate_drop_cntr > wrs_db->immediate_drop_max_in_row) {
			wrs_params->immediate_drop_ignore++;

			cl_wrs_tables_reset(wrs_db, wrs_sta, wrs_params);
			cl_wrs_reset_params_cntrs(wrs_params);

			wrs_pr_info(wrs_db,
				    "[WRS][%s] sta %u - ignore immediate down decision (cntr=%u)\n",
				    WRS_TYPE_STR(wrs_params->type), wrs_sta->sta_idx,
				    wrs_params->immediate_drop_cntr);
			return true;
		}

		cl_wrs_decision_make(cl_hw, wrs_db, wrs_sta, wrs_params,
				     WRS_DECISION_DOWN_IMMEDIATE, down_rate_idx);
		return true;
	}

	return false;
}

static void cl_wrs_decision_up(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			       struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params,
			       u16 up_rate_idx, u32 up_th)
{
	enum cl_wrs_decision up_decision = (up_th == wrs_db->quick_up_interval) ?
		WRS_DECISION_UP_QUICK : WRS_DECISION_UP;

	if (wrs_params->is_logger_en)
		WRS_LOGGER.up_time = wrs_params->up_same_time_cnt;

	cl_wrs_decision_make(cl_hw, wrs_db, wrs_sta, wrs_params, up_decision, up_rate_idx);
}

static void cl_wrs_decision_same(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
				 struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params,
				 u16 rate_idx)
{
	cl_wrs_decision_make(cl_hw, wrs_db, wrs_sta, wrs_params, WRS_DECISION_SAME, rate_idx);
}

static void cl_wrs_epr_decision(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
				struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params)
{
	u16 curr_rate_idx = wrs_params->rate_idx;
	struct cl_wrs_table *table = &wrs_params->table[curr_rate_idx];
	u16 down_rate_idx = table->rate_down.rate_idx;
	u16 up_rate_idx = 0;
	u16 down_th = table->rate_down.time_th;
	u32 up_th = 0;
	bool up_rate_valid = false;

	/* Check if we transmitted enough frames for taking decision */
	if ((wrs_params->frames_total + wrs_params->ba_not_rcv_total) <
	    wrs_db->min_frames_for_decision)
		return;

	if (wrs_params->is_logger_en) {
		WRS_LOGGER.timestamp = jiffies_to_msecs(jiffies);
		WRS_LOGGER.rate_idx = wrs_params->rate_idx;
		WRS_LOGGER.success = wrs_params->frames_total - wrs_params->fail_total;
		WRS_LOGGER.fail = wrs_params->fail_total;
		WRS_LOGGER.ba_not_rcv = wrs_params->ba_not_rcv_total;
	}

	up_rate_valid = cl_wrs_find_up_candidate(wrs_db, wrs_params, &up_rate_idx, &up_th);

	/* RSSI protect */
	if (wrs_db->rssi_protect_en)
		if (cl_wrs_rssi_prot_decision(cl_hw, wrs_db, wrs_sta, wrs_params,
					      up_rate_valid, up_rate_idx, down_rate_idx))
			return;

	if (down_rate_idx != curr_rate_idx) {
		/* Down immediate */
		if (wrs_db->immediate_drop_en)
			if (cl_wrs_epr_immeidate_down(cl_hw, wrs_db, wrs_sta,
						      wrs_params, down_rate_idx))
				return;

		/* Down */
		if (wrs_params->down_time_cnt >= down_th) {
			if (cl_wrs_down_epr_check(wrs_db, wrs_sta, wrs_params,
						  wrs_db->epr_factor, WRS_DECISION_DOWN)) {
				cl_wrs_decision_make(cl_hw, wrs_db, wrs_sta, wrs_params,
						     WRS_DECISION_DOWN, down_rate_idx);
				return;
			}

			wrs_params->down_time_cnt = 0;
		}
	}

	/* Up-same */
	if (wrs_params->up_same_time_cnt >= up_th) {
		if (up_rate_valid)
			cl_wrs_decision_up(cl_hw, wrs_db, wrs_sta, wrs_params, up_rate_idx, up_th);
		else
			cl_wrs_decision_same(cl_hw, wrs_db, wrs_sta, wrs_params, curr_rate_idx);

		return;
	}

	/*
	 * If there is no valid UP rate and the EPR is more
	 * than EPR down threshold => make a same decision
	 */
	if (!up_rate_valid &&
	    !cl_wrs_down_epr_check(wrs_db, wrs_sta, wrs_params,
				   wrs_db->epr_factor, WRS_DECISION_SAME))
		cl_wrs_decision_same(cl_hw, wrs_db, wrs_sta, wrs_params, curr_rate_idx);
}

static void cl_wrs_divide_weights_by_two(struct cl_wrs_table *table_node)
{
	u8 up_idx = 0;
	struct cl_wrs_table_node *rate_up;

	/*
	 * Converge weights - divide all weights by 2
	 * (make sure they do not go below their init value)
	 */
	if (table_node->rate_down.rate_idx != WRS_INVALID_RATE)
		table_node->rate_down.time_th = max(table_node->rate_down.time_th >> 1,
						    WRS_INIT_MSEC_WEIGHT_DOWN);

	for (up_idx = 0; up_idx < WRS_TABLE_NODE_UP_MAX; up_idx++) {
		rate_up = &table_node->rate_up[up_idx];

		if (rate_up->rate_idx != WRS_INVALID_RATE)
			rate_up->time_th = max(rate_up->time_th >> 1, WRS_INIT_MSEC_WEIGHT_UP);

		if (rate_up->time_th == WRS_INIT_MSEC_WEIGHT_UP)
			rate_up->quick_up_check = false;
	}
}

static void cl_wrs_converge_weights(struct cl_wrs_params *wrs_params)
{
	/*
	 * Converge weights - divide the weights by 2 (except for the current rate),
	 * and reset PER counters (except for current rate, down rate, and down-down rate).
	 */
	u16 i;
	u16 curr_idx = wrs_params->rate_idx;
	u16 down_idx = wrs_params->table[curr_idx].rate_down.rate_idx;
	u16 down2_idx = wrs_params->table[down_idx].rate_down.rate_idx;

	for (i = 0; i < wrs_params->table_size; i++) {
		if (i == curr_idx)
			continue;

		cl_wrs_divide_weights_by_two(&wrs_params->table[i]);

		if (i != down_idx && i != down2_idx) {
			wrs_params->table[i].frames_total = 0;
			wrs_params->table[i].ba_not_rcv_total = 0;
			wrs_params->table[i].epr_acc = 0;
		}
	}
}

static void cl_wrs_converge_weights_idle_decision(struct cl_hw *cl_hw,
						  struct cl_wrs_db *wrs_db,
						  struct cl_wrs_sta *wrs_sta,
						  struct cl_wrs_params *wrs_params)
{
	/*
	 * Continue normal converge (just like during traffic).
	 * After 6 seconds reset table, and select rate based on RSSI.
	 */
	if (!wrs_db->converge_idle_en)
		return;

	wrs_params->converge_time_idle += wrs_db->interval;

	if (wrs_params->converge_mode == WRS_CONVERGE_MODE_RESET) {
		if (wrs_params->converge_time_idle < wrs_db->converge_idle_interval_reset) {
			cl_wrs_converge_weights(wrs_params);
		} else {
			wrs_params->converge_mode = WRS_CONVERGE_MODE_RSSI;
			wrs_params->converge_time_idle = 0;

			wrs_pr_info(wrs_db, "[WRS][%s] Converge weights: sta %u - RSSI\n",
				    WRS_TYPE_STR(wrs_params->type), wrs_sta->sta_idx);

			/* Reset table and choose new rate based on RSSI */
			cl_wrs_tables_reset(wrs_db, wrs_sta, wrs_params);

			cl_wrs_set_rate_idle(cl_hw, wrs_db, wrs_sta, wrs_params);
		}
	} else {
		if (wrs_params->converge_time_idle < wrs_db->converge_idle_interval_rssi)
			return;

		/* Choose new rate */
		wrs_params->converge_time_idle = 0;
		cl_wrs_set_rate_idle(cl_hw, wrs_db, wrs_sta, wrs_params);
	}
}

static void cl_wrs_converge_weights_idle_reset(struct cl_wrs_db *wrs_db,
					       struct cl_wrs_sta *wrs_sta,
					       struct cl_wrs_params *wrs_params)
{
	/* There was traffic in last maintenance interval - reset converge parameteres */
	wrs_params->converge_time_idle = 0;

	if (wrs_params->converge_mode != WRS_CONVERGE_MODE_RESET) {
		wrs_params->converge_mode = WRS_CONVERGE_MODE_RESET;
		wrs_pr_info(wrs_db, "[WRS][%s] Converge weights: sta %u - RESET\n",
			    WRS_TYPE_STR(wrs_params->type), wrs_sta->sta_idx);
	}
}

static void cl_wrs_converge_weights_trfc_decision(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
						  struct cl_wrs_db *wrs_db,
						  struct cl_wrs_params *wrs_params)
{
	u32 converge_interval = 0;

	if (!wrs_db->converge_trfc_en)
		return;

	wrs_params->converge_time_trfc += wrs_db->interval;

	if (wrs_params->converge_time_trfc >= converge_interval) {
		wrs_params->converge_time_trfc = 0;
		cl_wrs_converge_weights(wrs_params);
	}
}

static u32 cl_wrs_get_sync_attempts(struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params)
{
	struct cl_sta *cl_sta = container_of(wrs_sta, struct cl_sta, wrs_sta);
	struct cl_wrs_info *wrs_info = cl_wrs_info_get(cl_sta, wrs_params->type);

	return wrs_info->sync_attempts;
}

static void cl_wrs_sta_no_sync_handler(struct cl_hw *cl_hw,
				       struct cl_wrs_db *wrs_db,
				       struct cl_wrs_sta *wrs_sta,
				       struct cl_wrs_params *wrs_params)
{
	unsigned long time_delta = jiffies_to_msecs(jiffies - wrs_params->no_sync_timestamp);

	if (time_delta < wrs_db->sync_timeout)
		return;

	if (cl_wrs_get_sync_attempts(wrs_sta, wrs_params) < wrs_db->sync_min_attempts) {
		/*
		 * Rate not synced but there is also hardly no traffic -
		 * change mode to synced!
		 */
		wrs_params->sync = true;
		wrs_params->sync_timestamp = jiffies;
	} else {
		struct cl_wrs_table *wrs_table = &wrs_params->table[wrs_params->rate_idx];
		struct cl_wrs_rate *curr_rate = &wrs_table->rate;

		if (IS_REAL_PHY(cl_hw->chip) && !cl_hw->ate_db.active)
			pr_warn("[WRS][%s] NO SYNC - sta = %u, bw = %u, nss = %u, mcs = %u, gi = %u\n",
				WRS_TYPE_STR(wrs_params->type), wrs_sta->sta_idx, curr_rate->bw,
				curr_rate->nss, curr_rate->mcs, curr_rate->gi);

		if (WRS_IS_DECISION_UP(wrs_params->last_decision)) {
			cl_wrs_decision_make(cl_hw, wrs_db, wrs_sta, wrs_params,
					     WRS_DECISION_DOWN_NO_SYNC,
					     wrs_table->rate_down.rate_idx);
		} else {
			/* If the last decision was DOWN - change state to SYNCED. */
			wrs_params->sync = true;
			wrs_params->sync_timestamp = jiffies;
		}
	}
}

static void cl_wrs_update_ba_not_rcv(struct cl_wrs_db *wrs_db, struct cl_wrs_params *wrs_params)
{
	unsigned long time_since_sync = jiffies_to_msecs(jiffies - wrs_params->sync_timestamp);

	wrs_params->calc_ba_not_rcv = (wrs_db->ba_not_rcv_force ||
				       (time_since_sync < wrs_db->ba_not_rcv_time_since_sync));
}

static void _cl_wrs_cntrs_reset(struct cl_wrs_info *wrs_info)
{
	wrs_info->epr_acc = 0;
	wrs_info->success = 0;
	wrs_info->fail = 0;
	wrs_info->ba_not_rcv = 0;
	wrs_info->ba_not_rcv_consecutive_max = 0;
}

static void cl_wrs_cntrs_read(struct cl_wrs_sta *wrs_sta,
			      struct cl_wrs_cntrs *cntrs,
			      u8 type)
{
	struct cl_sta *cl_sta = container_of(wrs_sta, struct cl_sta, wrs_sta);
	struct cl_wrs_info *wrs_info = cl_wrs_info_get(cl_sta, type);

	cntrs->epr_acc = wrs_info->epr_acc;
	cntrs->total = wrs_info->success + wrs_info->fail;
	cntrs->fail = wrs_info->fail;
	cntrs->ba_not_rcv = wrs_info->ba_not_rcv;
	cntrs->ba_not_rcv_consecutive = wrs_info->ba_not_rcv_consecutive_max;

	_cl_wrs_cntrs_reset(wrs_info);
}

static void _cl_wrs_sta_maintenance(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
				    struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;
	struct cl_wrs_sta *wrs_sta = &cl_sta->wrs_sta;
	struct cl_wrs_cntrs cntrs = {0};

	if (wrs_params->is_logger_en)
		memset(&WRS_LOGGER, 0, sizeof(struct cl_wrs_logger));

	if (!wrs_params->sync) {
		cl_wrs_sta_no_sync_handler(cl_hw, wrs_db, wrs_sta, wrs_params);
		goto end_logger;
	}

	if (!WRS_TYPE_IS_RX(wrs_params))
		cl_wrs_update_ba_not_rcv(wrs_db, wrs_params);

	cl_wrs_cntrs_read(wrs_sta, &cntrs, wrs_params->type);

	if (wrs_params->is_fixed_rate) {
		cl_wrs_stats_per_update(wrs_db, wrs_sta, wrs_params, &cntrs);
		goto end_logger;
	}

	wrs_params->down_time_cnt += wrs_db->interval;
	wrs_params->up_same_time_cnt += wrs_db->interval;

	if ((cntrs.total + cntrs.ba_not_rcv) < wrs_db->converge_idle_packet_th) {
		/*
		 * Very few frames were sent in last maintenance interval
		 * Check if weights should be converged
		 */
		cl_wrs_converge_weights_idle_decision(cl_hw, wrs_db, wrs_sta, wrs_params);

		cl_wrs_stats_per_update(wrs_db, wrs_sta, wrs_params, &cntrs);

		goto end_logger;
	} else {
		/* There was traffic in last maintenance interval - reset converge parameteres */
		cl_wrs_converge_weights_idle_reset(wrs_db, wrs_sta, wrs_params);
	}

	cl_wrs_stats_per_update(wrs_db, wrs_sta, wrs_params, &cntrs);

	wrs_params->quick_up_check =
		(cntrs.ba_not_rcv_consecutive >= wrs_db->quick_up_ba_thr) ? 1 : 0;
	cl_wrs_epr_decision(cl_hw, wrs_db, wrs_sta, wrs_params);

	cl_wrs_converge_weights_trfc_decision(cl_hw, cl_sta, wrs_db, wrs_params);

end_logger:
	if (wrs_params->is_logger_en && WRS_LOGGER.decision != WRS_DECISION_NONE)
		wrs_params->logger_idx = WRS_INC_POW2(wrs_params->logger_idx,
						      wrs_params->logger_size);
}

static void cl_wrs_sta_maintenance(struct cl_hw *cl_hw, struct cl_sta *cl_sta)
{
	_cl_wrs_sta_maintenance(cl_hw, cl_sta, &cl_sta->wrs_sta.tx_su_params);

	if (cl_sta->wrs_sta.rx_params)
		_cl_wrs_sta_maintenance(cl_hw, cl_sta, cl_sta->wrs_sta.rx_params);
}

static void cl_wrs_maintenance(struct work_struct *work)
{
	struct cl_wrs_db *wrs_db = container_of(work, struct cl_wrs_db,
						work_maintenance.work);
	struct cl_hw *cl_hw = container_of(wrs_db, struct cl_hw, wrs_db);

	cl_wrs_lock_bh(wrs_db);
	cl_sta_loop(cl_hw, cl_wrs_sta_maintenance);
	cl_wrs_unlock_bh(wrs_db);

	schedule_delayed_work(&wrs_db->work_maintenance,
			      msecs_to_jiffies(wrs_db->interval));
}

static void cl_wrs_down_decision_weights_update(struct cl_wrs_db *wrs_db,
						struct cl_wrs_sta *wrs_sta,
						u16 new_rate_idx,
						struct cl_wrs_params *wrs_params)
{
	u16 old_rate_idx = wrs_params->rate_idx;
	u8 up_idx = 0;
	u16 down_th_min = wrs_db->time_th_min;
	u16 step = wrs_db->step_down;
	u16 *th_down = &wrs_params->table[old_rate_idx].rate_down.time_th;
	u16 *th_up = NULL;
	struct cl_wrs_table *table_node = &wrs_params->table[new_rate_idx];

	/* Decrease the weight from old rate to new rate */
	if (*th_down > (down_th_min + step))
		*th_down -= step;
	else
		*th_down = down_th_min;

	/* Increase the weight from new rate to old rate */
	for (up_idx = 0; up_idx < WRS_TABLE_NODE_UP_MAX; up_idx++) {
		if (old_rate_idx == table_node->rate_up[up_idx].rate_idx) {
			th_up = &table_node->rate_up[up_idx].time_th;
			table_node->rate_up[up_idx].quick_up_check = !!wrs_params->quick_up_check;
			step = wrs_params->penalty_decision_dn;
			*th_up = min_t(u16, *th_up + step, wrs_db->time_th_max_up);
			break;
		}
	}

	wrs_pr_info(wrs_db,
		    "[WRS][%s] Down update - sta = %u, "
		    "down weight [%u-->%u] = %u, up weight [%u-->%u] = %u\n",
		    WRS_TYPE_STR(wrs_params->type), wrs_sta->sta_idx, old_rate_idx, new_rate_idx,
		    *th_down, new_rate_idx, old_rate_idx, th_up ? *th_up : 0);
}

static void cl_wrs_up_same_decision_weights_update(struct cl_wrs_db *wrs_db,
						   struct cl_wrs_sta *wrs_sta,
						   struct cl_wrs_params *wrs_params)
{
	u16 curr_rate_idx = wrs_params->rate_idx;
	u16 down_rate_idx = wrs_params->table[curr_rate_idx].rate_down.rate_idx;
	u8 up_idx = 0;
	u16 up_th_min = wrs_db->time_th_min;
	u16 step = wrs_db->step_up_same;
	u16 *th_down = &wrs_params->table[curr_rate_idx].rate_down.time_th;
	u16 *th_up = NULL;
	u16 th_down_orig = *th_down;
	u16 th_up_orig = 0;
	struct cl_wrs_table *table_node = &wrs_params->table[down_rate_idx];

	/* Increase the weight from current rate to down rate */
	*th_down = min_t(u16, *th_down + step, wrs_db->time_th_max_down);

	/* Decrease the weight from down rate to current rate */
	for (up_idx = 0; up_idx < WRS_TABLE_NODE_UP_MAX; up_idx++) {
		if (curr_rate_idx == table_node->rate_up[up_idx].rate_idx) {
			th_up = &table_node->rate_up[up_idx].time_th;
			table_node->rate_up[up_idx].quick_up_check = false;

			th_up_orig = *th_up;

			if (*th_up > (up_th_min + step))
				*th_up -= step;
			else
				*th_up = up_th_min;
			break;
		}
	}

	if (th_up && (th_up_orig != *th_up || th_down_orig != *th_down))
		wrs_pr_info(wrs_db,
			    "[WRS][%s] Up/same update - sta = %u, "
			    "down weight [%u-->%u] = %u, up weight [%u-->%u] = %u\n",
			    WRS_TYPE_STR(wrs_params->type), wrs_sta->sta_idx, curr_rate_idx,
			    down_rate_idx, *th_down, down_rate_idx, curr_rate_idx, *th_up);
}

static bool cl_wrs_is_rate_params_valid(struct cl_wrs_rate *rate_params)
{
	return (*(u16 *)rate_params != U16_MAX);
}

void cl_wrs_init(struct cl_hw *cl_hw)
{
	struct cl_wrs_db *wrs_db = &cl_hw->wrs_db;

	/* Default configuration */
	wrs_db->debug_level = DBG_LVL_ERROR;
	wrs_db->rssi_protect_en = true;
	wrs_db->rssi_protect_mode = WRS_RSSI_PROT_MODE_RSSI;
	wrs_db->rssi_protect_up_thr = WRS_RSSI_PROTECT_UP_THR;
	wrs_db->rssi_protect_dn_thr = WRS_RSSI_PROTECT_DN_THR;
	wrs_db->min_frames_for_decision = WRS_MIN_FRAMES_FOR_DECISION;
	wrs_db->epr_factor = WRS_EPR_FACTOR;
	wrs_db->converge_idle_en = true;
	wrs_db->converge_idle_interval_reset = WRS_CONVERGE_IDLE_INTERVAL_RESET;
	wrs_db->converge_idle_interval_rssi = WRS_CONVERGE_IDLE_INTERVAL_RSSI;
	wrs_db->converge_idle_packet_th = WRS_CONVERGE_IDLE_PACKET_TH;
	wrs_db->converge_trfc_en = true;
	wrs_db->converge_trfc_interval_static = WRS_CONVERGE_TRFC_INTERVAL_STATIC;
	wrs_db->immediate_drop_en = true;
	wrs_db->immediate_drop_epr_factor = WRS_IMMEDIATE_DROP_EPR_FACTOR;
	wrs_db->immediate_drop_max_in_row = WRS_IMMEDIATE_DROP_MAX_IN_ROW;
	wrs_db->time_th_min = WRS_MSEC_WEIGHT_MIN;
	wrs_db->time_th_max_up = WRS_MSEC_WEIGHT_MAX_UP;
	wrs_db->time_th_max_down = WRS_MSEC_WEIGHT_MAX_DOWN;
	wrs_db->step_down = WRS_MSEC_STEP_DOWN;
	wrs_db->step_up_same = WRS_MSEC_STEP_UP_SAME;
	wrs_db->interval = msecs_round(WRS_MAINTENANCE_PERIOD_MS);
	wrs_db->conservative_mcs_noisy_env = false;
	wrs_db->conservative_nss_noisy_env = false;
	wrs_db->quick_up_en = true;
	wrs_db->quick_up_ba_thr = WRS_QUICK_UP_BA_THR;
	wrs_db->quick_up_interval = msecs_round(WRS_QUICK_UP_INTERVAL_MS);
	wrs_db->quick_down_en = true;
	wrs_db->quick_down_epr_factor = WRS_QUICK_DOWN_EPR_FACTOR;
	wrs_db->quick_down_agg_thr = WRS_QUICK_DOWN_AGG_THR;
	wrs_db->quick_down_pkt_thr = WRS_QUICK_DOWN_PKT_THR;
	wrs_db->ba_not_rcv_collision_filter = true;
	/* Environment of 2.4 is much more noisy, so 'BA not received' are ignored. */
	wrs_db->ba_not_rcv_force = cl_band_is_24g(cl_hw) ? false : true;
	wrs_db->ba_not_rcv_time_since_sync = WRS_BA_NOT_RCV_TIME_SINCE_SYNC;
	wrs_db->sync_timeout = WRS_SYNC_TIMEOUT;
	wrs_db->sync_min_attempts = WRS_SYNC_MIN_ATTEMPTS;

	INIT_DELAYED_WORK(&wrs_db->work_maintenance,
			  cl_wrs_maintenance);

	if (!cl_hw->chip->conf->ce_production_mode)
		schedule_work(&wrs_db->work_maintenance.work);

	spin_lock_init(&wrs_db->lock);

	if ((cl_hw->conf->ci_wrs_fixed_rate[WRS_FIXED_PARAM_MODE] != -1) &&
	    (cl_hw->conf->ci_wrs_fixed_rate[WRS_FIXED_PARAM_BW] != -1) &&
	    (cl_hw->conf->ci_wrs_fixed_rate[WRS_FIXED_PARAM_NSS] != -1) &&
	    (cl_hw->conf->ci_wrs_fixed_rate[WRS_FIXED_PARAM_MCS] != -1) &&
	    (cl_hw->conf->ci_wrs_fixed_rate[WRS_FIXED_PARAM_GI] != -1))
		wrs_db->is_fixed_rate = WRS_FIXED_FALLBACK_DIS;
}

inline void cl_wrs_lock_bh(struct cl_wrs_db *wrs_db)
{
	spin_lock_bh(&wrs_db->lock);
}

inline void cl_wrs_unlock_bh(struct cl_wrs_db *wrs_db)
{
	spin_unlock_bh(&wrs_db->lock);
}

inline void cl_wrs_lock(struct cl_wrs_db *wrs_db)
{
	spin_lock(&wrs_db->lock);
}

inline void cl_wrs_unlock(struct cl_wrs_db *wrs_db)
{
	spin_unlock(&wrs_db->lock);
}

void cl_wrs_rate_param_sync(struct cl_wrs_db *wrs_db, struct cl_wrs_sta *wrs_sta,
			    struct cl_wrs_params *wrs_params)
{
	if (wrs_params->sync)
		return;

	cl_wrs_cntrs_reset(wrs_sta, wrs_params);

	/* Reset counters */
	cl_wrs_reset_params_cntrs(wrs_params);

	/* Change state to SYNCED */
	wrs_params->sync = true;
	wrs_params->sync_timestamp = jiffies;

	wrs_pr_trace(wrs_db, "[WRS][%s] Sync - timestamp = %u, sta = %u, rate_idx = %u\n",
		     WRS_TYPE_STR(wrs_params->type),
		     jiffies_to_msecs(jiffies),
		     wrs_sta->sta_idx,
		     wrs_params->rate_idx);
}

void cl_wrs_rate_params_update(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			       struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params,
			       u16 new_rate_idx, bool is_sync_required)
{
	struct cl_sta *cl_sta = container_of(wrs_sta, struct cl_sta, wrs_sta);
	struct cl_wrs_rate_params *rate_params = &wrs_params->rate_params;
	struct cl_wrs_rate *rate = &wrs_params->table[new_rate_idx].rate;
	u16 fallback_rate_idx = wrs_params->table[new_rate_idx].rate_down.rate_idx;
	struct cl_wrs_rate *rate_fallback = &wrs_params->table[fallback_rate_idx].rate;

	if (!WRS_TYPE_IS_RX(wrs_params))
		cl_dyn_bcast_rate_change(cl_hw, cl_sta, rate_params->mcs, rate->mcs);

	rate_params->bw = rate->bw;
	rate_params->nss = rate->nss;
	rate_params->mcs = rate->mcs;
	rate_params->gi = rate->gi;
	rate_params->mode = wrs_sta->mode;
	rate_params->fallback_en = (wrs_params->is_fixed_rate != WRS_FIXED_FALLBACK_DIS);

	wrs_pr_trace(wrs_db,
		     "[WRS][%s] Rate params update - "
		     "sta = %u, rate_idx = %u, bw = %u, nss = %u, mcs = %u, gi = %u\n",
		     WRS_TYPE_STR(wrs_params->type), wrs_sta->sta_idx,
		     new_rate_idx, rate_params->bw, rate_params->nss,
		     rate_params->mcs, rate_params->gi);

	wrs_params->rate_idx = new_rate_idx;

	/* Converge - restart the time for converging weights of all old rates */
	wrs_params->converge_time_trfc = 0;

	cl_wrs_rate_param_set(cl_hw, wrs_sta, wrs_params, rate_params,
			      rate_fallback, true);

	if (is_sync_required) {
		wrs_params->sync = false;
		wrs_params->no_sync_timestamp = jiffies;
	} else {
		wrs_params->sync = true;
	}

	/* Reset Counters */
	cl_wrs_reset_params_cntrs(wrs_params);
}

void cl_wrs_decision_make(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			  struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params,
			  enum cl_wrs_decision decision, u16 new_rate_idx)
{
	if (WRS_IS_DECISION_DOWN(decision)) {
		cl_wrs_down_decision_weights_update(wrs_db, wrs_sta, new_rate_idx, wrs_params);
	} else if (WRS_IS_DECISION_UP(decision)) {
		cl_wrs_up_same_decision_weights_update(wrs_db, wrs_sta, wrs_params);

		if (wrs_params->rate_idx != wrs_params->table[new_rate_idx].rate_down.rate_idx) {
			/*
			 * In case the down rate is different from the previous rate,
			 * update down rate index and reset the thresholds
			 */
			struct cl_wrs_table_node *rate_down =
				&wrs_params->table[new_rate_idx].rate_down;

			rate_down->rate_idx = wrs_params->rate_idx;
			rate_down->time_th = WRS_INIT_MSEC_WEIGHT_DOWN;
		}
	} else if (decision == WRS_DECISION_SAME) {
		cl_wrs_up_same_decision_weights_update(wrs_db, wrs_sta, wrs_params);

		/* Reset counters besides down_time_cnt */
		wrs_params->frames_total = 0;
		wrs_params->fail_total = 0;
		wrs_params->ba_not_rcv_total = 0;
		wrs_params->epr_acc = 0;
		wrs_params->up_same_time_cnt = 0;
	}

	cl_wrs_decision_update(wrs_db, wrs_sta, wrs_params, decision, new_rate_idx);

	if (WRS_IS_DECISION_DOWN(decision) || WRS_IS_DECISION_UP(decision))
		cl_wrs_rate_params_update(cl_hw, wrs_db, wrs_sta, wrs_params,
					  new_rate_idx, true);
}

void cl_wrs_decision_update(struct cl_wrs_db *wrs_db, struct cl_wrs_sta *wrs_sta,
			    struct cl_wrs_params *wrs_params, enum cl_wrs_decision decision,
			    u16 new_rate_idx)
{
	wrs_params->last_decision = decision;
	wrs_params->decision_cnt[decision]++;

	if (decision != WRS_DECISION_DOWN_IMMEDIATE)
		wrs_params->immediate_drop_cntr = 0;

	if (wrs_params->is_logger_en) {
		WRS_LOGGER.decision = decision;
		WRS_LOGGER.new_rate_idx = new_rate_idx;
	}

	if (decision == WRS_DECISION_SAME)
		return;

	wrs_pr_trace(wrs_db,
		     "[WRS][%s] Decision update - timestamp [%u] sta [%u] decision [%s]\n",
		     WRS_TYPE_STR(wrs_params->type),
		     jiffies_to_msecs(jiffies),
		     wrs_sta->sta_idx,
		     WRS_DECISION_STR(decision));
}

void cl_wrs_fixed_rate_set(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			   struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params,
			   u8 is_fixed_rate, u8 mode, u8 bw, u8 nss, u8 mcs, u8 gi)
{
	u16 rate_idx = 0;
	u8 type = wrs_params->type;

	if (!is_fixed_rate) {
		wrs_params->is_fixed_rate = WRS_AUTO_RATE;
		wrs_pr_verbose(wrs_db, "[WRS][%s] Station %u was set to auto rate!\n",
			       WRS_TYPE_STR(type), wrs_sta->sta_idx);
		cl_wrs_set_rate_idle(cl_hw, wrs_db, wrs_sta, wrs_params);
		return;
	}

	if (mode != wrs_sta->mode) {
		/* Set fixed rate with a different format-mode */
		struct cl_wrs_rate_params *rate_params = &wrs_params->rate_params;
		struct cl_sta *cl_sta = container_of(wrs_sta, struct cl_sta, wrs_sta);

		if (cl_band_is_6g(cl_hw) && mode != WRS_MODE_HE) {
			wrs_pr_verbose(wrs_db, "[WRS][%s] Invalid format mode [%u] for 6GHz band\n",
				       WRS_TYPE_STR(type), mode);
			return;
		}

		if (!WRS_TYPE_IS_RX(wrs_params))
			cl_dyn_bcast_rate_change(cl_hw, cl_sta, rate_params->mcs, mcs);

		rate_params->bw = bw;
		rate_params->nss = nss;
		rate_params->mcs = mcs;
		rate_params->gi = gi;
		rate_params->mode = mode;
		rate_params->fallback_en = (wrs_params->is_fixed_rate != WRS_FIXED_FALLBACK_DIS);

		wrs_params->is_fixed_rate = is_fixed_rate;

		cl_wrs_rate_param_set(cl_hw, wrs_sta, wrs_params, rate_params,
				      NULL, true);
		wrs_pr_verbose(wrs_db,
			       "[WRS][%s] Station %u set to %s - "
			       "mode=%u, bw=%u, nss=%u, mcs=%u, gi=%u\n",
			       WRS_TYPE_STR(type), wrs_sta->sta_idx, FIXED_RATE_STR(is_fixed_rate),
			       mode, bw, nss, mcs, gi);
		return;
	}

	rate_idx = cl_wrs_tables_find_rate_idx(wrs_params, bw, nss, mcs, gi);

	if (rate_idx == WRS_INVALID_RATE) {
		wrs_pr_err(wrs_db,
			   "[WRS][%s] Invalid fixed rate - mode=%u, bw=%u, nss=%u, mcs=%u, gi=%u\n",
			   WRS_TYPE_STR(type), mode, bw, nss, mcs, gi);
		return;
	}

	wrs_params->is_fixed_rate = is_fixed_rate;
	cl_wrs_rate_params_update(cl_hw, wrs_db, wrs_sta, wrs_params, rate_idx, false);
	wrs_pr_verbose(wrs_db,
		       "[WRS][%s] Station %u set to %s - mode=%u, bw=%u, nss=%u, mcs=%u, gi=%u\n",
			WRS_TYPE_STR(type), wrs_sta->sta_idx, FIXED_RATE_STR(is_fixed_rate),
			mode, bw, nss, mcs, gi);
}

void cl_wrs_initial_rate_set(struct cl_wrs_db *wrs_db, struct cl_wrs_sta *wrs_sta,
			     u8 bw, u8 nss, u8 mcs, u8 gi)
{
	struct cl_wrs_params *wrs_params = &wrs_sta->tx_su_params;
	u8 type = wrs_params->type;

	wrs_params->initial_rate_idx = cl_wrs_tables_find_rate_idx(wrs_params, bw, nss, mcs, gi);

	if (wrs_params->initial_rate_idx == WRS_INVALID_RATE)
		wrs_pr_verbose(wrs_db,
			       "[WRS][%s] Initial rate based on rssi (sta=%u)\n",
			       WRS_TYPE_STR(type), wrs_sta->sta_idx);
	else
		wrs_pr_verbose(wrs_db,
			       "[WRS][%s] Initial rate - sta=%u, bw=%u, nss=%u, mcs=%u, gi=%u\n",
			       WRS_TYPE_STR(type), wrs_sta->sta_idx, bw, nss, mcs, gi);
}

void cl_wrs_quick_down_check(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			     struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_cntrs cntrs = {0};
	struct cl_wrs_table *table = NULL;
	u16 curr_rate_idx = 0;
	u16 down_rate_idx = 0;
	u8 type = wrs_params->type;

	if (!wrs_params->sync ||
	    wrs_params->is_fixed_rate ||
	    !WRS_IS_DECISION_UP(wrs_params->last_decision))
		return;

	if (!WRS_TYPE_IS_RX(wrs_params))
		cl_wrs_update_ba_not_rcv(wrs_db, wrs_params);

	cl_wrs_cntrs_read(wrs_sta, &cntrs, type);
	cl_wrs_stats_per_update(wrs_db, wrs_sta, wrs_params, &cntrs);

	curr_rate_idx = wrs_params->rate_idx;
	table = &wrs_params->table[curr_rate_idx];
	down_rate_idx = table->rate_down.rate_idx;

	/* Check if we transmitted enough frames for taking decision */
	if (wrs_params->frames_total < wrs_db->min_frames_for_decision)
		return;

	if (wrs_params->is_logger_en) {
		memset(&WRS_LOGGER, 0, sizeof(struct cl_wrs_logger));
		WRS_LOGGER.timestamp = jiffies_to_msecs(jiffies);
		WRS_LOGGER.rate_idx = curr_rate_idx;
		WRS_LOGGER.success = wrs_params->frames_total - wrs_params->fail_total;
		WRS_LOGGER.fail = wrs_params->fail_total;
		WRS_LOGGER.ba_not_rcv = wrs_params->ba_not_rcv_total;
	}

	/* Down decision check */
	if (down_rate_idx != curr_rate_idx &&
	    cl_wrs_down_epr_check(wrs_db, wrs_sta, wrs_params,
				  wrs_db->quick_down_epr_factor, WRS_DECISION_DOWN_QUICK))
		cl_wrs_decision_make(cl_hw, wrs_db, wrs_sta, wrs_params,
				     WRS_DECISION_DOWN_QUICK, down_rate_idx);

	if (wrs_params->is_logger_en && WRS_LOGGER.decision != WRS_DECISION_NONE)
		wrs_params->logger_idx = WRS_INC_POW2(wrs_params->logger_idx,
						      wrs_params->logger_size);
}

bool cl_wrs_up_mcs1(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
		    struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params)
{
	/*
	 * In case of big packets (4300 in VHT and 5400 in HE) and low
	 * rate (BW 20, NSS 1, MCS 0), firmware will increase rate to MCS 1,
	 * and give an indication to driver (set rate_fix_mcs1 in cl_agg_tx_report).
	 * WRS should also move to MCS 1, and give the maximum time
	 * penalty time from MCS 0 toMCS 1.
	 */
	u16 curr_rate_idx = wrs_params->rate_idx;
	u16 up_rate_idx = 0;
	struct cl_wrs_table *table = &wrs_params->table[curr_rate_idx];

	if (!table || wrs_params->is_fixed_rate)
		return false;

	if (table->rate.bw != CHNL_BW_20 ||
	    table->rate.nss != WRS_SS_1 ||
	    table->rate.mcs != WRS_MCS_0)
		return false;

	up_rate_idx = cl_wrs_tables_find_rate_idx(wrs_params,
						  CHNL_BW_20, WRS_SS_1, WRS_MCS_1, table->rate.gi);

	if (up_rate_idx == WRS_INVALID_RATE)
		return false;

	if (wrs_params->is_logger_en) {
		memset(&WRS_LOGGER, 0, sizeof(struct cl_wrs_logger));
		WRS_LOGGER.timestamp = jiffies_to_msecs(jiffies);
		WRS_LOGGER.rate_idx = curr_rate_idx;
	}

	wrs_params->table[up_rate_idx].rate_down.time_th = wrs_db->time_th_max_up;

	cl_wrs_cntrs_reset(wrs_sta, wrs_params);
	cl_wrs_decision_update(wrs_db, wrs_sta, wrs_params, WRS_DECISION_UP_MCS1, up_rate_idx);
	cl_wrs_rate_params_update(cl_hw, wrs_db, wrs_sta, wrs_params,
				  up_rate_idx, true);

	if (wrs_params->is_logger_en)
		wrs_params->logger_idx = WRS_INC_POW2(wrs_params->logger_idx,
						      wrs_params->logger_size);

	return true;
}

void cl_wrs_rate_param_set(struct cl_hw *cl_hw, struct cl_wrs_sta *wrs_sta,
			   struct cl_wrs_params *wrs_params,
			   struct cl_wrs_rate_params *rate_params,
			   struct cl_wrs_rate *rate_fallback,
			   bool set_su)
{
	struct cl_sta *cl_sta = container_of(wrs_sta, struct cl_sta, wrs_sta);
	struct cl_wrs_info *wrs_info = NULL;
	u8 op_mode = 0;
	u8 ltf = 0;
	u8 ltf_fallback = 0;
	u8 sta_idx = cl_sta->sta_idx;
	union cl_rate_ctrl_info rate_ctrl;
	union cl_rate_ctrl_info rate_ctrl_fallback;
	union cl_rate_ctrl_info_he rate_ctrl_he;

	if (cl_hw->ate_db.active)
		return;

	rate_ctrl_he.word = 0;
	wrs_info = cl_wrs_info_get(cl_sta, wrs_params->type);

	wrs_params->data_rate = cl_data_rates_get(rate_params->mode,
						  rate_params->bw,
						  rate_params->nss,
						  rate_params->mcs,
						  rate_params->gi);

	rate_ctrl.word = cl_rate_ctrl_generate(cl_hw, cl_sta, rate_params->mode,
					       rate_params->bw, rate_params->nss,
					       rate_params->mcs, rate_params->gi,
					       rate_params->fallback_en);

	/* For fallback rate use same mode (if it is NULL use same rate). */
	if (rate_fallback) {
		rate_ctrl_fallback.word = cl_rate_ctrl_generate(cl_hw,
								cl_sta,
								rate_params->mode,
								rate_fallback->bw,
								rate_fallback->nss,
								rate_fallback->mcs,
								rate_fallback->gi,
								rate_params->fallback_en);
		ltf_fallback = cl_map_gi_to_ltf(rate_params->mode, rate_fallback->gi);
	} else {
		rate_ctrl_fallback.word = rate_ctrl.word;
	}

	/* Save current BF state and SS for the fallback rate */
	if (WRS_TYPE_IS_TX_SU(wrs_params)) {
		struct cl_bf_sta_db *bf_db = &cl_sta->bf_db;

		bf_db->is_on = rate_ctrl.field.tx_bf;
		bf_db->is_on_fallback = rate_ctrl_fallback.field.tx_bf;
		bf_db->num_ss = rate_params->nss;
		bf_db->num_ss_fallback = rate_fallback ? rate_fallback->nss : rate_params->nss;
	}

	/* Reset counters */
	wrs_info->success = 0;
	wrs_info->fail = 0;

	/* Mark rate as unsynced */
	wrs_info->synced = false;
	wrs_info->quick_rate_check = false;
	wrs_info->sync_attempts = 0;

	ltf = cl_map_gi_to_ltf(rate_params->mode, rate_params->gi);

	if (rate_params->mode == WRS_MODE_HE)
		rate_ctrl_he.field.spatial_conf = RATE_CNTRL_HE_SPATIAL_CONF_DEF;

	/* Send new rate to firmware */
	if (set_su) {
		if (WRS_TYPE_IS_TX_SU(wrs_params)) {
			op_mode = RATE_OP_MODE_STA_SU;
			cl_msg_tx_update_rate_dl(cl_hw, sta_idx, rate_ctrl.word,
						 rate_ctrl_fallback.word, rate_params->bw,
						 op_mode, wrs_params->group_id,
						 ltf, ltf_fallback, rate_ctrl_he.word);
		} else if (WRS_TYPE_IS_RX(wrs_params)) {
			u8 ul_gi_ltf = CL_TF_GI_TO_GI_LTF(rate_params->gi);

			cl_msg_tx_update_rate_ul(cl_hw, sta_idx, rate_params->bw,
						 rate_params->nss, rate_params->mcs, ul_gi_ltf);
		}
	}

	if (WRS_TYPE_IS_TX_SU(wrs_params)) {
		cl_edca_dynamic_update_sta_rate(cl_hw, cl_sta);
	}
}

s8 cl_wrs_rssi_eq_calc(struct cl_hw *cl_hw, struct cl_wrs_sta *wrs_sta,
		       bool read_clear, s8 *sorted_rssi)
{
	struct cl_sta *cl_sta = container_of(wrs_sta, struct cl_sta, wrs_sta);
	struct cl_wrs_rssi *wrs_rssi = &cl_sta->wrs_rssi;
	int i;

	if (wrs_rssi->cnt == 0) {
		memcpy(sorted_rssi, cl_sta->last_rssi, cl_hw->num_antennas);
		goto sort;
	}

	for (i = 0; i < cl_hw->num_antennas; i++)
		sorted_rssi[i] = (s8)(wrs_rssi->sum[i] / wrs_rssi->cnt);

	if (read_clear)
		memset(wrs_rssi, 0, sizeof(struct cl_wrs_rssi));

sort:
	/* Sort RSSI values in descending order */
	cl_rssi_sort_descending(sorted_rssi, cl_hw->num_antennas);

	/* Calc equivalent RSSI */
	return cl_rssi_calc_equivalent(cl_hw, sorted_rssi);
}

void cl_wrs_cntrs_reset(struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params)
{
	struct cl_sta *cl_sta = container_of(wrs_sta, struct cl_sta, wrs_sta);
	struct cl_wrs_info *wrs_info = cl_wrs_info_get(cl_sta, wrs_params->type);

	_cl_wrs_cntrs_reset(wrs_info);
}

struct cl_wrs_info *cl_wrs_info_get(struct cl_sta *cl_sta, u8 type)
{
	if (type == WRS_TYPE_TX_SU)
		return &cl_sta->wrs_info_tx_su;
	else if (type == WRS_TYPE_RX)
		return &cl_sta->wrs_info_rx;
	else
		return NULL;
}

struct cl_wrs_params *cl_wrs_params_get(struct cl_wrs_sta *wrs_sta, u8 type)
{
	if (type == WRS_TYPE_TX_SU)
		return &wrs_sta->tx_su_params;
	else if (type == WRS_TYPE_RX)
		return wrs_sta->rx_params;
	else
		return NULL;
}

void cl_wrs_update_rx_rate(struct cl_hw *cl_hw, struct cl_sta *cl_sta, struct hw_rxhdr *rxhdr)
{
	struct cl_wrs_rate *rate_params = NULL;

	if (!cl_sta ||
	    !cl_sta->wrs_sta.rx_params ||
	    rxhdr->format_mod == FORMATMOD_HE_TRIG)
		return;

	rate_params = &cl_sta->wrs_sta.rx_params->rx_rate_idle;

	rate_params->bw = rxhdr->ch_bw;
	rate_params->nss = rxhdr->n_sts;
	rate_params->mcs = rxhdr->mcs;
	rate_params->gi = rxhdr->gi_type;
}

bool cl_wrs_set_rate_idle(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			  struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_rate *rx_rate_idle = &wrs_params->rx_rate_idle;
	s8 rssi_sort[MAX_ANTENNAS] = {0};
	u16 new_rate_idx = 0;
	u8 decision;

	if (WRS_TYPE_IS_RX(wrs_params) &&
	    cl_wrs_is_rate_params_valid(rx_rate_idle)) {
		decision = WRS_DECISION_RX_RATE;
		if (wrs_params->initial_rate_idx != WRS_INVALID_RATE)
			new_rate_idx = wrs_params->initial_rate_idx;
		else
			/* Get rate from last data packet */
			new_rate_idx = cl_wrs_tables_find_rate_idx(wrs_params,
								   rx_rate_idle->bw,
								   rx_rate_idle->nss,
								   rx_rate_idle->mcs,
								   rx_rate_idle->gi);

		cl_wrs_rx_rate_idle_reset(wrs_params);
	} else {
		/* Get rate from rssi */
		cl_wrs_rssi_eq_calc(cl_hw, wrs_sta, true, rssi_sort);
		new_rate_idx = cl_wrs_rssi_find_rate(cl_hw, wrs_db, wrs_sta, wrs_params, rssi_sort);
		decision = WRS_DECISION_RSSI_MGMT;
	}

	if (new_rate_idx != wrs_params->rate_idx) {
		if (wrs_params->is_logger_en) {
			memset(&WRS_LOGGER, 0, sizeof(struct cl_wrs_logger));
			WRS_LOGGER.timestamp = jiffies_to_msecs(jiffies);
			WRS_LOGGER.rate_idx = wrs_params->rate_idx;
		}

		cl_wrs_decision_update(wrs_db, wrs_sta, wrs_params, decision, new_rate_idx);
		cl_wrs_rate_params_update(cl_hw, wrs_db, wrs_sta, wrs_params,
					  new_rate_idx, false);
	} else {
		wrs_params->sync = true;
	}

	return true;
}

struct cl_wrs_rate_params *cl_wrs_rx_rate_get(struct cl_sta *cl_sta)
{
	struct cl_wrs_params *rx_params = cl_sta->wrs_sta.rx_params;

	if (rx_params)
		return &rx_params->rate_params;

	return NULL;
}

void cl_wrs_rx_rate_idle_reset(struct cl_wrs_params *rx_params)
{
	struct cl_wrs_rate *rate_idle = &rx_params->rx_rate_idle;

	*(u16 *)rate_idle = U16_MAX;
}

