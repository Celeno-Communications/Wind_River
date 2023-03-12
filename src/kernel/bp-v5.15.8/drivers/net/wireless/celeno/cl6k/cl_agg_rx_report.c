// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_agg_rx_report.h"
#include "cl_ul_rssi.h"

void cl_agg_rx_report_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			      struct mm_agg_rx_ind *agg_report)
{
	struct cl_ul_rssi_info *ul_rssi_info = &cl_sta->ul_rssi_info;
	u8 rcpi = agg_report->rcpi;

	if (!cl_ul_rssi_is_rcpi_valid(rcpi))
		return;

	ul_rssi_info->rcpi_sum += rcpi;
	ul_rssi_info->rcpi_samples++;

	ul_rssi_pr_info("STA%u, rcpi %u, rcpi sum %u, rcpi samples %u\n",
			cl_sta->sta_idx, rcpi, ul_rssi_info->rcpi_sum,
			ul_rssi_info->rcpi_samples);
}
