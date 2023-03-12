/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_WRS_H
#define CL_WRS_H

#include "cl_wrs_db.h"
#include "cl_hw.h"

void cl_wrs_init(struct cl_hw *cl_hw);
void cl_wrs_lock_bh(struct cl_wrs_db *wrs_db);
void cl_wrs_unlock_bh(struct cl_wrs_db *wrs_db);
void cl_wrs_lock(struct cl_wrs_db *wrs_db);
void cl_wrs_unlock(struct cl_wrs_db *wrs_db);
void cl_wrs_fixed_rate_set(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			   struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params,
			   u8 is_fixed_rate, u8 mode, u8 bw, u8 nss, u8 mcs, u8 gi);
void cl_wrs_initial_rate_set(struct cl_wrs_db *wrs_db, struct cl_wrs_sta *wrs_sta,
			     u8 bw, u8 nss, u8 mcs, u8 gi);
void cl_wrs_rate_param_sync(struct cl_wrs_db *wrs_db, struct cl_wrs_sta *wrs_sta,
			    struct cl_wrs_params *wrs_params);
void cl_wrs_rate_params_update(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			       struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params,
			       u16 new_rate_idx, bool is_sync_required);
void cl_wrs_decision_make(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			  struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params,
			  enum cl_wrs_decision decision, u16 new_rate_idx);
void cl_wrs_decision_update(struct cl_wrs_db *wrs_db, struct cl_wrs_sta *wrs_sta,
			    struct cl_wrs_params *wrs_params, enum cl_wrs_decision decision,
			    u16 new_rate_idx);
void cl_wrs_quick_down_check(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			     struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params);
bool cl_wrs_up_mcs1(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
		    struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params);
void cl_wrs_rate_param_set(struct cl_hw *cl_hw, struct cl_wrs_sta *wrs_sta,
			   struct cl_wrs_params *wrs_params,
			   struct cl_wrs_rate_params *rate_params,
			   struct cl_wrs_rate *rate_fallback,
			   bool set_su);
s8 cl_wrs_rssi_eq_calc(struct cl_hw *cl_hw, struct cl_wrs_sta *wrs_sta,
		       bool read_clear, s8 *sorted_rssi);
void cl_wrs_cntrs_reset(struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params);
struct cl_wrs_info *cl_wrs_info_get(struct cl_sta *cl_sta, u8 type);
struct cl_wrs_params *cl_wrs_params_get(struct cl_wrs_sta *wrs_sta, u8 type);
void cl_wrs_update_rx_rate(struct cl_hw *cl_hw, struct cl_sta *cl_sta, struct hw_rxhdr *rxhdr);
bool cl_wrs_set_rate_idle(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db,
			  struct cl_wrs_sta *wrs_sta, struct cl_wrs_params *wrs_params);
struct cl_wrs_rate_params *cl_wrs_rx_rate_get(struct cl_sta *cl_sta);
void cl_wrs_rx_rate_idle_reset(struct cl_wrs_params *rx_params);

#endif /* CL_WRS_H */
