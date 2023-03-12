// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_wrs_stats.h"
#include "cl_wrs.h"
#include "cl_utils.h"

static struct cl_wrs_per_stats *cl_wrs_stats_per_entry(struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_per_stats *per_stats = NULL, *per_stats_new = NULL;
	struct cl_wrs_rate_params *rate_params = &wrs_params->rate_params;
	struct list_head *list_rates = &wrs_params->list_rates;
	u8 bw = rate_params->bw;
	u8 nss = rate_params->nss;
	u8 mcs = rate_params->mcs;
	u8 gi = rate_params->gi;

	list_for_each_entry(per_stats, list_rates, list) {
		if (per_stats->bw != bw ||
		    per_stats->nss != nss ||
		    per_stats->mcs != mcs ||
		    per_stats->gi != gi)
			continue;

		/*
		 * Move the entry to the beginning of the list, so that it
		 * will be faster to find next time.
		 */
		if (per_stats != list_entry(list_rates->next, struct cl_wrs_per_stats, list)) {
			list_del(&per_stats->list);
			list_add(&per_stats->list, list_rates);
		}

		return per_stats;
	}

	/* Entry not found - allocate new entry and add to list */
	per_stats_new = kzalloc(sizeof(*per_stats_new), GFP_ATOMIC);

	if (!per_stats_new)
		return NULL;

	per_stats_new->bw = bw;
	per_stats_new->nss = nss;
	per_stats_new->mcs = mcs;
	per_stats_new->gi = gi;

	list_add(&per_stats_new->list, &wrs_params->list_rates);

	return per_stats_new;
}

void cl_wrs_stats_per_update(struct cl_wrs_db *wrs_db,
			     struct cl_wrs_sta *wrs_sta,
			     struct cl_wrs_params *wrs_params,
			     struct cl_wrs_cntrs *cntrs)
{
	u16 curr_rate_idx = wrs_params->rate_idx;
	struct cl_wrs_table *table_node = &wrs_params->table[curr_rate_idx];
	struct cl_wrs_per_stats *per_stats = cl_wrs_stats_per_entry(wrs_params);

	if (!per_stats)
		return;

	wrs_params->frames_total += cntrs->total;
	wrs_params->fail_total += cntrs->fail;
	wrs_params->ba_not_rcv_total += cntrs->ba_not_rcv;
	wrs_params->epr_acc += cntrs->epr_acc;

	per_stats->frames_total += cntrs->total;
	per_stats->frames_failed += cntrs->fail;
	per_stats->epr_acc += cntrs->epr_acc;

	if (wrs_params->calc_ba_not_rcv) {
		per_stats->frames_total += cntrs->ba_not_rcv;
		per_stats->frames_failed += cntrs->ba_not_rcv;
	}

	table_node->frames_total = wrs_params->frames_total;
	table_node->ba_not_rcv_total = wrs_params->ba_not_rcv_total;
	table_node->epr_acc = wrs_params->epr_acc;
}

struct per_info {
	u32 frames_failed;
	u32 frames_total;
	u64 epr_acc;
};

static void _cl_wrs_stats_per_print(char **buf, int *len, ssize_t *buf_size,
				    struct cl_wrs_rate *curr_rate,
				    struct per_info *per_info,
				    u64 total_all_rates,
				    u8 bw, u8 nss, u8 mcs, u8 gi)
{
	u64 frames_total = per_info->frames_total;
	u64 frames_failed = per_info->frames_failed;
	u64 epr_acc = per_info->epr_acc;
	u32 per_high = 0, per_low = 0, usage_high = 0, usage_low = 0, epr_high = 0, epr_low = 0;

	if (frames_total == 0)
		return;

	cl_div64_decimal(100 * frames_failed, frames_total, &per_high, &per_low);
	cl_div64_decimal(100 * frames_total, total_all_rates, &usage_high, &usage_low);
	cl_div64_decimal(epr_acc, frames_total * WRS_DATA_RATE_FACTOR, &epr_high, &epr_low);

	cl_snprintf(buf, len, buf_size,
		    "|%3s|%3u|%3u|%-9s|%4u.%02u|%10llu|%10llu|%3u.%02u|%4u.%02u|",
		    WRS_BW_STR(bw), nss, mcs, WRS_GI_STR(gi),
		    usage_high, usage_low, frames_failed,
		    frames_total, per_high, per_low, epr_high,
		    epr_low);

	/* Add an arrow to the current rate */
	if (curr_rate->bw == bw &&
	    curr_rate->nss == nss &&
	    curr_rate->mcs == mcs &&
	    curr_rate->gi == gi)
		cl_snprintf(buf, len, buf_size, "<==\n");
	else
		cl_snprintf(buf, len, buf_size, "\n");

	cl_snprintf(buf, len, buf_size,
		    "|------------------------------------------------------------------|\n");
}

void cl_wrs_stats_per_print(struct cl_hw *cl_hw,
			    struct cl_wrs_sta *wrs_sta,
			    struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_rate *curr_rate = &wrs_params->table[wrs_params->rate_idx].rate;
	struct cl_wrs_per_stats *per_stats = NULL;
	u8 bw = 0, nss = 0, mcs = 0, gi = 0;
	u16 alloc_size = CHNL_BW_MAX * WRS_SS_MAX * WRS_MCS_MAX * WRS_GI_MAX;
	u32 total_epr_high = 0, total_epr_low = 0;
	u64 total_epr_acc = 0, total_all_rates = 0;
	char *buf = NULL;
	ssize_t buf_size;
	int len = 0;
	struct per_info (*per_info_arr)[WRS_SS_MAX][WRS_MCS_MAX][WRS_GI_MAX] =
		kzalloc(alloc_size * sizeof(struct per_info), GFP_ATOMIC);

	if (!per_info_arr)
		return;

	list_for_each_entry(per_stats, &wrs_params->list_rates, list) {
		bw = per_stats->bw;
		nss = per_stats->nss;
		mcs = per_stats->mcs;
		gi = per_stats->gi;

		total_all_rates += per_stats->frames_total;
		total_epr_acc += per_stats->epr_acc;

		per_info_arr[bw][nss][mcs][gi].frames_failed = per_stats->frames_failed;
		per_info_arr[bw][nss][mcs][gi].frames_total = per_stats->frames_total;
		per_info_arr[bw][nss][mcs][gi].epr_acc = per_stats->epr_acc;
	}

	if (total_all_rates == 0) {
		cl_snprintf(&buf, &len, &buf_size, "Table rate empty\n");
		goto out;
	}

	cl_snprintf(&buf, &len, &buf_size,
		    "|------------------------------------------------------------------|\n"
		    "|BW |NSS|MCS|GI       |Usage  |Fail      |Total     |PER   |EPR    |\n"
		    "|---+---+---+---------+-------+----------+----------+------+-------|\n");

	for (bw = 0; bw <= wrs_sta->max_rate_cap.bw; bw++)
		for (nss = 0; nss <= wrs_sta->max_rate_cap.nss; nss++)
			for (mcs = 0; mcs <= wrs_sta->max_rate_cap.mcs; mcs++)
				for (gi = 0; gi <= wrs_sta->max_rate_cap.gi; gi++)
					_cl_wrs_stats_per_print(&buf, &len, &buf_size,
								curr_rate,
								&per_info_arr[bw][nss][mcs][gi],
								total_all_rates,
								bw, nss, mcs, gi);

	cl_div64_decimal(total_epr_acc, total_all_rates * WRS_DATA_RATE_FACTOR,
			 &total_epr_high, &total_epr_low);
	cl_snprintf(&buf, &len, &buf_size,
		    "###  Effective PHY Rate = %u.%u Mbps  ###\n",
		    total_epr_high, total_epr_low);

out:
	kfree(per_info_arr);
	cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);
}

void cl_wrs_stats_per_reset(struct cl_wrs_params *wrs_params)
{
	cl_wrs_stats_per_remove(wrs_params);
}

void cl_wrs_stats_per_init(struct cl_wrs_params *wrs_params)
{
	INIT_LIST_HEAD(&wrs_params->list_rates);
}

void cl_wrs_stats_per_remove(struct cl_wrs_params *wrs_params)
{
	struct cl_wrs_per_stats *per_stats = NULL, *per_stats_next = NULL;

	list_for_each_entry_safe(per_stats, per_stats_next, &wrs_params->list_rates, list) {
		list_del(&per_stats->list);
		kfree(per_stats);
	}
}

void cl_wrs_stats_decision_print(struct cl_wrs_params *wrs_params)
{
	u32 *decision_cnt = wrs_params->decision_cnt;

	pr_debug("\n");
	pr_debug("----------------------------\n");
	pr_debug("|Decision       |Count     |\n");
	pr_debug("|--------------------------|\n");
	pr_debug("|NONE           |%10u|\n", decision_cnt[WRS_DECISION_NONE]);
	pr_debug("|SAME           |%10u|\n", decision_cnt[WRS_DECISION_SAME]);
	pr_debug("|UP             |%10u|\n", decision_cnt[WRS_DECISION_UP]);
	pr_debug("|UP QUICK       |%10u|\n", decision_cnt[WRS_DECISION_UP_QUICK]);
	pr_debug("|UP RSSI        |%10u|\n", decision_cnt[WRS_DECISION_UP_RSSI]);
	pr_debug("|UP MCS1        |%10u|\n", decision_cnt[WRS_DECISION_UP_MCS1]);
	pr_debug("|DOWN           |%10u|\n", decision_cnt[WRS_DECISION_DOWN]);
	pr_debug("|DOWN RSSI      |%10u|\n", decision_cnt[WRS_DECISION_DOWN_RSSI]);
	pr_debug("|DOWN IMMEDIATE |%10u|\n", decision_cnt[WRS_DECISION_DOWN_IMMEDIATE]);
	pr_debug("|DOWN QUICK     |%10u|\n", decision_cnt[WRS_DECISION_DOWN_QUICK]);
	pr_debug("|DOWN NO SYNC   |%10u|\n", decision_cnt[WRS_DECISION_DOWN_NO_SYNC]);
	pr_debug("|RSSI MGMT      |%10u|\n", decision_cnt[WRS_DECISION_RSSI_MGMT]);
	pr_debug("|RX RATE        |%10u|\n", decision_cnt[WRS_DECISION_RX_RATE]);
	pr_debug("----------------------------\n");
	pr_debug("\n");
	pr_debug("Immediate drop ignore = [%u]\n", wrs_params->immediate_drop_ignore);
}

void cl_wrs_stats_decision_reset(struct cl_wrs_params *wrs_params)
{
	memset(&wrs_params->decision_cnt, 0, sizeof(wrs_params->decision_cnt));
	wrs_params->immediate_drop_ignore = 0;
}
