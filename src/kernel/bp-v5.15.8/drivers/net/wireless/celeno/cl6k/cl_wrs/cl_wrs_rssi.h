/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_WRS_RSSI_H
#define CL_WRS_RSSI_H

#include "cl_hw.h"
#include "cl_wrs_db.h"

bool cl_wrs_rssi_set_rate(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			  struct cl_wrs_sta *wrs_sta);

void cl_wrs_rssi_prot_start(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
bool cl_wrs_rssi_prot_decision(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			       struct cl_wrs_sta *wrs_sta,
			       struct cl_wrs_params *wrs_params,
			       bool up_rate_valid,
			       u8 up_rate_idx, u8 down_rate_idx);
void cl_wrs_rssi_prot_dbg(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			  struct cl_wrs_sta *wrs_sta);
void cl_wrs_rssi_prot_config(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			     bool enable, bool mode, s32 rssi_up_thr, s32 rssi_dn_thr);
u16 cl_wrs_rssi_find_rate(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			  struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params,
			  s8 *rssi_sort);

#endif /* CL_WRS_RSSI_H */
