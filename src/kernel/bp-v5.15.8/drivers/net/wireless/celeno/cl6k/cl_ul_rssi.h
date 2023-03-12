/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_UL_RSSI_H
#define CL_UL_RSSI_H

#include "cl_hw.h"
#include "cl_agg_rx_report.h"

#define TARGET_RCV_PWR_PERIOD_SU 2

#define ul_rssi_pr(format, level, ...) \
	do { \
		if ((level) <= cl_hw->ul_rssi_db.dbg_lvl) \
			pr_debug("[UL-RSSI][%s][%d] " format, __func__, __LINE__, ##__VA_ARGS__); \
	} while (0)

#define ul_rssi_pr_verbose(...)       pr_debug(__VA_ARGS__)
#define ul_rssi_pr_err(format, ...)   ul_rssi_pr(format, DBG_LVL_ERROR, ##__VA_ARGS__)
#define ul_rssi_pr_warn(format, ...)  ul_rssi_pr(format, DBG_LVL_WARNING, ##__VA_ARGS__)
#define ul_rssi_pr_trace(format, ...) ul_rssi_pr(format, DBG_LVL_TRACE, ##__VA_ARGS__)
#define ul_rssi_pr_info(format, ...)  ul_rssi_pr(format, DBG_LVL_INFO, ##__VA_ARGS__)

bool cl_ul_rssi_is_rcpi_valid(u8 rcpi);
void cl_ul_rssi_update_uph(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			   struct ieee80211_a_control a_ctl);
void cl_ul_rssi_sta_maintenance(struct cl_hw *cl_hw);
void cl_ul_rssi_init(struct cl_hw *cl_hw);
void cl_ul_rssi_sta_init(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
int cl_ul_rssi_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_UL_RSSI_H */
