/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_WRS_STA_H
#define CL_WRS_STA_H

#include "cl_wrs_db.h"
#include "cl_vif.h"
#include "cl_hw.h"

void cl_wrs_sta_add(struct cl_hw *cl_hw, struct ieee80211_sta *sta);
bool cl_wrs_sta_add_mu(struct cl_hw *cl_hw, struct cl_wrs_sta *wrs_sta, u8 group_id);
void cl_wrs_sta_add_rx(struct cl_hw *cl_hw, struct ieee80211_sta *sta);
void cl_wrs_sta_remove(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db, struct cl_sta *cl_sta);
bool cl_wrs_sta_remove_mu(struct cl_wrs_db *wrs_db, struct cl_wrs_sta *wrs_sta);
struct cl_wrs_sta *cl_wrs_sta_get(struct cl_hw *cl_hw, u8 sta_idx);
void cl_wrs_sta_print_list(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db);
void cl_wrs_sta_select_first_rate(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
				  struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params);
void cl_wrs_sta_capabilities_set(struct cl_wrs_db *wrs_db, struct ieee80211_sta *sta);
void cl_wrs_sta_set_supported_rate(struct cl_wrs_sta *wrs_sta, u8 bw, u8 nss, u8 mcs);

#endif /* CL_WRS_STA_H */
