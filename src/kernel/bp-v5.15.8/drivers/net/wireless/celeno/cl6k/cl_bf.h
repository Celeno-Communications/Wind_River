/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_BF_H
#define CL_BF_H

#include "cl_fw_msg.h"
#include "cl_hw.h"
#include "cl_sta.h"

void cl_bf_update_rate(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_bf_sta_add(struct cl_hw *cl_hw, struct cl_sta *cl_sta, struct ieee80211_sta *sta);
void cl_bf_sta_remove(struct cl_sta *cl_sta);
void cl_bf_sta_active(struct cl_hw *cl_hw, struct cl_sta *cl_sta, bool active);
void cl_bf_reset_sounding_ind(struct cl_sta *cl_sta);
bool cl_bf_is_enabled(struct cl_hw *cl_hw);
int cl_bf_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);
bool cl_bf_is_on(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 nss);
void cl_bf_enable(struct cl_hw *cl_hw, bool enable);
void cl_bf_sounding_start(struct cl_hw *cl_hw, enum sounding_type type, struct cl_sta **cl_sta_arr,
			  u8 sta_num, struct cl_sounding_info *recovery_elem);
void cl_bf_sounding_stop(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_bf_sounding_decision(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_bf_sounding_req_success(struct cl_hw *cl_hw, struct cl_sounding_info *new_elem);
void cl_bf_sounding_req_failure(struct cl_hw *cl_hw, struct cl_sounding_info *new_elem);

#endif /* CL_BF_H */
