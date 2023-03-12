/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TWT_FRAME_H
#define CL_TWT_FRAME_H

#include "cl_hw.h"
#include "cl_mac80211.h"

bool cl_twt_frame_is_individual_setup_request_valid(struct cl_hw *cl_hw,
						    struct cl_ieee80211_mgmt *request);
int cl_twt_frame_send_individual_setup_response(struct cl_hw *cl_hw,
						struct cl_sta *cl_sta,
						struct cl_ieee80211_mgmt *request,
						struct cl_twt_session_db **session);
int cl_twt_frame_send_individual_setup_request(struct cl_hw *cl_hw,
					       struct cl_sta *cl_sta,
					       enum ieee80211_twt_setup_command setup_cmd,
					       u8 flow_id,
					       bool announced,
					       bool triggered,
					       u64 interval_us,
					       u32 min_wake_duration_us);
int cl_twt_frame_simulate_individual_setup_request(struct cl_hw *cl_hw,
						   struct cl_sta *cl_sta,
						   enum ieee80211_twt_setup_command setup_cmd,
						   u8 flow_id,
						   bool announced,
						   bool triggered,
						   u64 interval_us,
						   u32 min_wake_duration_us);
int cl_twt_frame_send_individual_teardown_request(struct cl_hw *cl_hw,
						  struct cl_sta *cl_sta,
						  u8 flow_id);
int cl_twt_frame_simulate_individual_teardown_request(struct cl_hw *cl_hw,
						      struct cl_sta *cl_sta,
						      u8 flow_id);

#endif /* CL_TWT_FRAME_H */
