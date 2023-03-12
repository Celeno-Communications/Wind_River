// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_agg_tx_report.h"
#include "cl_stats.h"
#include "cl_rate_ctrl.h"
#include "cl_wrs_api.h"
#include "cl_data_rates.h"

static bool is_same_rate(struct cl_agg_tx_report *agg_report,
			 struct cl_wrs_rate_params *rate_params)
{
	union cl_rate_ctrl_info rate_ctrl_info = {
			.word = le32_to_cpu(agg_report->rate_cntrl_info)};
	u8 mcs = U8_MAX, nss = U8_MAX;

	if (agg_report->bw_requested != rate_params->bw)
		return false;

	if (rate_ctrl_info.field.gi != rate_params->gi)
		return false;

	cl_rate_ctrl_parse(&rate_ctrl_info, &nss, &mcs);

	return ((mcs == rate_params->mcs) && (nss == rate_params->nss));
}

static void sync_tx_rate(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			 struct cl_agg_tx_report *agg_report,
			 struct cl_wrs_info *wrs_info, struct cl_wrs_params *wrs_params)
{
	if (!agg_report->is_fallback && is_same_rate(agg_report, &wrs_params->rate_params)) {
		cl_wrs_api_rate_sync(cl_hw, cl_sta, wrs_params);

		wrs_info->synced = true;
		wrs_info->quick_rate_check = true;
		wrs_info->quick_rate_agg_cntr = 0;
		wrs_info->quick_rate_pkt_cntr = 0;
	} else {
		wrs_info->sync_attempts++;
	}
}

static void ba_not_received_handler(struct cl_hw *cl_hw, struct cl_wrs_info *wrs_info,
				    struct cl_agg_tx_report *agg_report)
{
	/* Ignore 'BA not received' if station is in power-save or if RTS limit was reached */
	if (agg_report->is_sta_ps || agg_report->is_rts_retry_limit_reached)
		return;

	/* Count number of consecutive 'BA not received' */
	wrs_info->ba_not_rcv_consecutive++;

	/* Save longest sequence of consecutive 'BA not received' */
	if (wrs_info->ba_not_rcv_consecutive > wrs_info->ba_not_rcv_consecutive_max)
		wrs_info->ba_not_rcv_consecutive_max = wrs_info->ba_not_rcv_consecutive;

	if (cl_hw->wrs_db.ba_not_rcv_collision_filter) {
		/*
		 * First 'BA not received' - might just be a collision.
		 * Don't add fail to ba_not_rcv but keep aside.
		 * Second consecutive 'BA not received' - not likely to be a collisions.
		 * Add fail to ba_not_rcv including previous fail that was kept aside.
		 * More than two consecutive 'BA not received' - very unlikely to be a collisions.
		 * Add fail to ba_not_rcv.
		 */
		if (wrs_info->ba_not_rcv_consecutive == 1)
			wrs_info->fail_prev = agg_report->fail;
		else if (wrs_info->ba_not_rcv_consecutive == 2)
			wrs_info->ba_not_rcv += (agg_report->fail + wrs_info->fail_prev);
		else
			wrs_info->ba_not_rcv += agg_report->fail;
	} else {
		wrs_info->ba_not_rcv += agg_report->fail;
	}
}

void cl_agg_tx_report_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			      struct cl_agg_tx_report *agg_report)
{
	struct cl_wrs_info *wrs_info = &cl_sta->wrs_info_tx_su;
	struct cl_wrs_params *wrs_params = &cl_sta->wrs_sta.tx_su_params;
	bool skip_epr_update = false;
	union cl_rate_ctrl_info rate_ctrl_info = {
			.word = le32_to_cpu(agg_report->rate_cntrl_info)};

	/* Retry_count for cl_wlan */
	cl_sta->retry_count += agg_report->success_after_retry;

	/*
	 * In case of big packets (4300 in VHT and 5400 in HE) and low
	 * rate (BW 20, NSS 1, MCS 0), firmware will increase rate to MCS 1,
	 * and give an indication to driver (set rate_fix_mcs1 in cl_agg_tx_report).
	 * WRS should also move to MCS 1, and give the maximum time
	 * penalty time from MCS 0 toMCS 1.
	 */
	if (agg_report->rate_fix_mcs1 && !agg_report->is_fallback)
		if (cl_wrs_api_up_mcs1(cl_hw, cl_sta, wrs_params))
			return;

	/* WRS sync mechanism */
	if (!wrs_info->synced)
		sync_tx_rate(cl_hw, cl_sta, agg_report, wrs_info, wrs_params);

	if (agg_report->bf && cl_sta->bf_db.is_on && !cl_sta->bf_db.synced) {
		cl_sta->bf_db.synced = true;
		/* Resetting the WRS UP weights */
		cl_wrs_api_beamforming_sync(cl_hw, cl_sta);
	}

	if (agg_report->ba_not_received) {
		ba_not_received_handler(cl_hw, wrs_info, agg_report);
	} else {
		if (!skip_epr_update)
			wrs_info->fail += agg_report->fail;

		wrs_info->ba_not_rcv_consecutive = 0;
	}

	if (!skip_epr_update) {
		u8 mcs = 0, nss = 0;
		u16 data_rate = 0;

		cl_rate_ctrl_parse(&rate_ctrl_info, &nss, &mcs);

		data_rate = cl_data_rates_get_x10(rate_ctrl_info.field.format_mod,
						  rate_ctrl_info.field.bw,
						  nss,
						  mcs,
						  rate_ctrl_info.field.gi);

		wrs_info->epr_acc += ((u64)agg_report->success * data_rate);
		wrs_info->success += agg_report->success;
	}

	if (cl_hw->wrs_db.quick_down_en && wrs_info->quick_rate_check) {
		if (is_same_rate(agg_report, &wrs_params->rate_params)) {
			wrs_info->quick_rate_agg_cntr++;
			wrs_info->quick_rate_pkt_cntr += (agg_report->success + agg_report->fail);

			if (wrs_info->quick_rate_agg_cntr >= cl_hw->wrs_db.quick_down_agg_thr &&
			    wrs_info->quick_rate_pkt_cntr > cl_hw->wrs_db.quick_down_pkt_thr) {
				wrs_info->quick_rate_check = false;
				cl_wrs_api_quick_down_check(cl_hw, cl_sta, wrs_params);
			}
		}
	}
}

void cl_agg_tx_report_simulate_for_single(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
					  struct cl_hw_tx_status *status)
{
	/* Assign statistics struct */
	struct cl_agg_tx_report agg_report;
	union cl_rate_ctrl_info rate_ctrl_info;

	memset(&agg_report, 0, sizeof(struct cl_agg_tx_report));

	agg_report.bf = status->bf;
	agg_report.success = status->frm_successful;
	agg_report.fail = status->num_mpdu_retries + (status->frm_successful ? 0 : 1);
	agg_report.success_after_retry =
		(status->frm_successful && status->num_mpdu_retries) ? 1 : 0;
	agg_report.retry_limit_reached = !status->frm_successful ? 1 : 0;
	agg_report.success_more_one_retry =
		(status->frm_successful && (status->num_mpdu_retries > 1)) ? 1 : 0;
	agg_report.sta_idx = cl_sta->sta_idx;
	agg_report.bw_requested = status->bw_requested;

	rate_ctrl_info.field.bw = status->bw_transmitted;
	rate_ctrl_info.field.gi = status->gi;
	rate_ctrl_info.field.format_mod = status->format_mod;
	rate_ctrl_info.field.mcs_index = status->mcs_index;

	cl_rate_ctrl_convert(&rate_ctrl_info);

	agg_report.rate_cntrl_info = cpu_to_le32(rate_ctrl_info.word);
	cl_agg_tx_report_handler(cl_hw, cl_sta, &agg_report);
	cl_stats_update_tx_single(cl_hw, cl_sta, &agg_report);
}
