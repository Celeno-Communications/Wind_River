/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_BSS_COLOR_H
#define CL_BSS_COLOR_H

#include "cl_hw.h"
#include "cl_vif.h"
#include "cl_sta.h"
#include "cl_vendor_cmd.h"

#define WMN_ACTION_EVENT_REPORT 1
#define WMN_ACTION_EVENT_REPORT_TYPE_COLOR_COLLISION 4
#define WMN_ACTION_EVENT_REPORT_TYPE_COLOR_IN_USE 5

struct wnm_event_report_collision {
	u8 wnm_action;
	u8 dialog_token;
	u8 elem_id;
	u8 length;
	u8 event_token;
	u8 event_type;
	u8 event_report_status;
	u64 color_mask;
};

struct wnm_event_report_in_use {
	u8 wnm_action;
	u8 dialog_token;
	u8 elem_id;
	u8 length;
	u8 event_token;
	u8 event_type;
	u8 event_report_status;
	u8 ap_color;
};

void cl_bss_color_update_counter(struct ieee80211_vif *vif);
void cl_bss_color_check_action(struct cl_vif *cl_vif,
			       struct ieee80211_mgmt *mgmt);
void cl_bss_color_repeater_handle(struct cl_vif *cl_vif,
				  struct cl_sta *cl_sta);
void cl_bss_color_collision_indication(struct cl_hw *cl_hw,
				       struct mm_bss_color_collision_ind *ind);
int cl_bss_color_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cli_params *cli_params);

#endif /* CL_BSS_COLOR_H */
