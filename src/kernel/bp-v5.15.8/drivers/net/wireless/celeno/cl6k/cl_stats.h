/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_STATS_H
#define CL_STATS_H

#include "cl_hw.h"
#include "cl_rx.h"
#include "cl_timer.h"
#include "cl_agg_tx_report.h"
#include "cl_vendor_cmd.h"

void cl_stats_init(struct cl_hw *cl_hw);
void cl_stats_deinit(struct cl_hw *cl_hw);
void cl_stats_sta_add(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_stats_sta_remove(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_stats_update_tx_agg(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			    struct cl_agg_tx_report *agg_report);
void cl_stats_update_tx_single(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			       struct cl_agg_tx_report *agg_report);
void cl_stats_update_rx_rssi(struct cl_hw *cl_hw, struct cl_sta *cl_sta, s8 rssi[MAX_ANTENNAS]);
void cl_stats_update_rx_rate(struct cl_hw *cl_hw, struct cl_sta *cl_sta, struct hw_rxhdr *rxhdr);
void cl_stats_update_rx_rate_production(struct cl_hw *cl_hw, struct hw_rxhdr *rxhdr);
void cl_stats_update_ps(struct cl_hw *cl_hw, struct cl_sta *cl_sta, bool is_ps);
int cl_stats_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cli_params *cli_params);

#endif /* CL_STATS_H */
