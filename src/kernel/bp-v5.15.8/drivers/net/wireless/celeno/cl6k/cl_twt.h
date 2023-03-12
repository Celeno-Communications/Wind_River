/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TWT_H
#define CL_TWT_H

#include "cl_hw.h"
#include <linux/ieee80211.h>

#define CL_TWT_DEFAULT_INTERVAL_US 524288 /* 512 TU */
#define CL_TWT_DEFAULT_MIN_WAKE_DURATION_US 64000 /* 62.5 TU */
#define CL_TWT_FLOW_ID_ALL 0xFF
#define CL_TWT_FLOW_ID_MAX 0x7

bool cl_twt_is_enabled(struct cl_hw *cl_hw);
void cl_twt_init(struct cl_hw *cl_hw);
void cl_twt_close(struct cl_hw *cl_hw);
struct cl_twt_session_db *
cl_twt_get_session(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 flow_id);
int cl_twt_update_session(struct cl_hw *cl_hw,
			  struct cl_sta *cl_sta,
			  struct ieee80211_twt_individual_elem *twt_elem,
			  struct  cl_twt_session_db *session);
int cl_twt_add_session(struct cl_hw *cl_hw,
		       struct cl_sta *cl_sta,
		       struct ieee80211_twt_individual_elem *twt_elem,
		       struct  cl_twt_session_db **session_ptr);
void cl_twt_remove_session(struct cl_hw *cl_hw,
			   struct cl_twt_session_db *session,
			   bool send_teardown_req);
int cl_twt_teardown_individual_sesseion(struct cl_hw *cl_hw,
					struct cl_sta *cl_sta,
					u8 flow_id,
					bool send_teardown_req);
void cl_twt_sta_remove(struct cl_hw *cl_hw,
		       struct cl_sta *cl_sta);
u64 cl_twt_get_wake_interval_us(struct ieee80211_twt_individual_elem *elem);
u32 cl_twt_get_min_wake_time_us(struct ieee80211_twt_individual_elem *elem);
void cl_twt_set_target_wake_time(struct cl_hw *cl_hw,
				 struct ieee80211_twt_individual_elem *elem);
void cl_twt_set_min_wake_duration(struct cl_hw *cl_hw,
				  struct ieee80211_twt_individual_elem *elem,
				  u32 duration_us);
void cl_twt_set_interval(struct cl_hw *cl_hw,
			 struct ieee80211_twt_individual_elem *elem,
			 u64 interval_us);
int cl_twt_handle_individual_setup_request(struct cl_hw *cl_hw,
					   struct cl_sta *cl_sta,
					   struct cl_ieee80211_mgmt *request);
int cl_twt_handle_individual_teardown_request(struct cl_hw *cl_hw,
					      struct cl_sta *cl_sta,
					      struct cl_ieee80211_mgmt *request);

#endif /* CL_TWT_H */
