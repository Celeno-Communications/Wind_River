// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_twt.h"
#include "cl_twt_frame.h"
#include "cl_msg_tx.h"
#include "cl_sta.h"
#include "cl_utils.h"

#define CL_TWT_CONST_TARGET_WAKE_TIME_OFFSET_US 500000

struct cl_next_start_time {
	struct cl_twt_session_db *session;
	u64 time;
};

static struct cl_twt_session_db *cl_twt_get_free_session(struct cl_hw *cl_hw)
{
	u8 i, max_sessions = cl_hw->conf->ce_twt_max_sessions;
	struct cl_twt_session_db *session;

	for (i = 0, session = &cl_hw->twt_db.cl_twt_sessions[0];
	     i < max_sessions;
	     i++, session++)
		if (!session->cl_sta)
			return session;

	return NULL;
}

static void cl_twt_remove_session_by_params(struct cl_hw *cl_hw,
					    struct cl_sta *cl_sta,
					    u8 flow_id,
					    bool send_teardown_req)
{
	u8 i, handled_sessions = 0, num_sessions = cl_hw->twt_db.num_sessions;
	u8 max_sessions = cl_hw->conf->ce_twt_max_sessions;
	struct cl_twt_session_db *session;

	/* If flow_id == CL_TWT_FLOW_ID_INVALID then we'd like to remove all the sessions of STA */
	bool remove_all_flows = (flow_id == CL_TWT_FLOW_ID_ALL);

	for (i = 0, session = &cl_hw->twt_db.cl_twt_sessions[0];
	     (i < max_sessions) && (handled_sessions < num_sessions);
	     i++, session++) {
		if (session->cl_sta == cl_sta &&
		    (remove_all_flows ||
		     session->twt_setup.req_type.fields.flow_id == flow_id)) {
			cl_twt_remove_session(cl_hw, session, send_teardown_req);

			if (!remove_all_flows)
				break;

			handled_sessions++;
		}
	}
}

static void cl_twt_remove_all_sta_sessions(struct cl_hw *cl_hw,
					   struct cl_sta *cl_sta,
					   bool send_teardown_req)
{
	cl_twt_remove_session_by_params(cl_hw, cl_sta, CL_TWT_FLOW_ID_ALL, false);

	if (send_teardown_req)
		cl_twt_frame_send_individual_teardown_request(cl_hw, cl_sta, CL_TWT_FLOW_ID_ALL);
}

static u64 cl_twt_get_next_start_time(struct cl_hw *cl_hw,
				      struct cl_twt_session_db *session,
				      u64 tsf)
{
	struct ieee80211_twt_individual_elem *elem = &session->twt_setup;
	u64 start_time = elem->target_wake_time;
	u64 interval = cl_twt_get_wake_interval_us(elem);
	u64 remainder = 0;
	u64 intervals_from_start_to_tsf = div64_u64_rem(tsf - start_time, interval, &remainder);
	u64 next_time = 0;

	if (remainder)
		/* We add 1 to intervals_from_start_to_tsf to get next_time > tsf */
		next_time = ((intervals_from_start_to_tsf + 1) * interval + start_time);
	else
		/* No remainder means that the next start time equals exactly to tsf */
		next_time = tsf;

	return next_time;
}

static void cl_twt_get_next_start_times_sorted_array(struct cl_hw *cl_hw,
						     u64 tsf,
						     struct cl_next_start_time *next_start_times)
{
	u64 next_time;
	u8 i, j, handled_sessions = 0, num_sessions = cl_hw->twt_db.num_sessions;
	u8 max_sessions = cl_hw->conf->ce_twt_max_sessions;
	u8 bytes_to_move = 0;
	struct cl_twt_session_db *session;

	/* Calculate the next TWT time of all sessions and save them in a sorted array. */
	for (i = 0, session = &cl_hw->twt_db.cl_twt_sessions[0];
	     i < max_sessions && handled_sessions < num_sessions;
	     i++, session++) {
		if (!session->cl_sta)
			continue;

		/* Calculate the current session's next start time */
		next_time = cl_twt_get_next_start_time(cl_hw, session, tsf);

		/* Find the correct position in the sorted array */
		for (j = 0;
		     (j < handled_sessions) && (next_start_times[j].time <= next_time);
		      j++)
			;

		/* Make room for the current session's next start time */
		bytes_to_move = (handled_sessions - j) * sizeof(next_start_times[0]);

		if (bytes_to_move)
			memmove(&next_start_times[j + 1], &next_start_times[j],
				bytes_to_move);

		/* Insert the current session's next start time to the array */
		next_start_times[j].session = session;
		next_start_times[j].time = next_time;
		handled_sessions++;
	}
}

bool cl_twt_is_enabled(struct cl_hw *cl_hw)
{
	return cl_hw->conf->ce_twt_en;
}

void cl_twt_init(struct cl_hw *cl_hw)
{
	if (!cl_twt_is_enabled(cl_hw))
		return;

	memset(&cl_hw->twt_db, 0, sizeof(cl_hw->twt_db));
}

void cl_twt_close(struct cl_hw *cl_hw)
{
	u8 i, max_sessions = cl_hw->conf->ce_twt_max_sessions;
	struct cl_twt_session_db *session;

	if (!cl_hw->twt_db.num_sessions)
		return;

	/* Remove all sessions */
	for (i = 0, session = &cl_hw->twt_db.cl_twt_sessions[0];
	      (i < max_sessions) && (cl_hw->twt_db.num_sessions);
	      i++, session++) {
		if (!session->cl_sta)
			continue;

		cl_twt_remove_all_sta_sessions(cl_hw, session->cl_sta, true);
	}
}

struct cl_twt_session_db *
cl_twt_get_session(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 flow_id)
{
	u8 i, max_sessions = cl_hw->conf->ce_twt_max_sessions;
	struct cl_twt_session_db *session;

	for (i = 0, session = &cl_hw->twt_db.cl_twt_sessions[0];
	     i < max_sessions;
	     i++, session++)
		if (session->cl_sta == cl_sta &&
		    session->twt_setup.req_type.fields.flow_id == flow_id)
			return session;

	return NULL;
}

int cl_twt_update_session(struct cl_hw *cl_hw,
			  struct cl_sta *cl_sta,
			  struct ieee80211_twt_individual_elem *twt_elem,
			  struct  cl_twt_session_db *session)
{
	session->cl_sta = cl_sta;
	session->twt_setup = *twt_elem;

	return 0;
}

int cl_twt_add_session(struct cl_hw *cl_hw,
		       struct cl_sta *cl_sta,
		       struct ieee80211_twt_individual_elem *twt_elem,
		       struct  cl_twt_session_db **session)
{
	struct cl_twt_session_db *session_db = cl_twt_get_free_session(cl_hw);

	if (!session_db) {
		cl_dbg_err(cl_hw, "There are no available TWT sessions\n");
		return -1;
	}

	cl_twt_update_session(cl_hw, cl_sta, twt_elem, session_db);
	cl_hw->twt_db.num_sessions++;
	*session = session_db;

	return 0;
}

void cl_twt_remove_session(struct cl_hw *cl_hw,
			   struct cl_twt_session_db *session,
			   bool send_teardown_req)
{
	/* Send a TWT teardown frame */
	if (send_teardown_req) {
		u8 flow_id = session->twt_setup.req_type.fields.flow_id;

		cl_twt_frame_send_individual_teardown_request(cl_hw, session->cl_sta, flow_id);
	}

	session->cl_sta = NULL;
	memset(&session->twt_setup, 0, sizeof(session->twt_setup));
	cl_hw->twt_db.num_sessions--;
}

int cl_twt_teardown_individual_sesseion(struct cl_hw *cl_hw,
					struct cl_sta *cl_sta,
					u8 flow_id,
					bool send_teardown_req)
{
	struct cl_twt_session_db *session;
	struct mm_twt_teardown_req req_msg = {
		.sta_idx = cl_sta->sta_idx,
		.twt_flow_id = flow_id
	};

	/* There are no sessions */
	if (!cl_hw->twt_db.num_sessions)
		return -1;

	/* Remove the session(s) from the db */
	if (flow_id == CL_TWT_FLOW_ID_ALL) {
		cl_twt_remove_all_sta_sessions(cl_hw, cl_sta, send_teardown_req);
	} else {
		/* Check if the session exists */
		session = cl_twt_get_session(cl_hw, cl_sta, flow_id);

		if (!session) {
			cl_dbg_err(cl_hw, "Cannot handle the TWT teardown request "
					  "since no such session was found: "
					  "sta_idx %u, flow_id %u\n",
				   cl_sta->sta_idx, flow_id);
			return -1;
		}

		cl_twt_remove_session(cl_hw, session, send_teardown_req);
	}

	/* Send a msg to fw */
	cl_msg_tx_twt_teardown(cl_hw, &req_msg);
	return 0;
}

void cl_twt_sta_remove(struct cl_hw *cl_hw,
		       struct cl_sta *cl_sta)
{
	struct mm_twt_teardown_req req_msg = {
		.sta_idx = cl_sta->sta_idx,
		.twt_flow_id = CL_TWT_FLOW_ID_ALL
	};

	if (!cl_twt_is_enabled(cl_hw))
		return;

	/* Remove all sessions of STA from the db */
	cl_twt_remove_all_sta_sessions(cl_hw, cl_sta, false);

	/* Send a msg to fw */
	cl_msg_tx_twt_teardown(cl_hw, &req_msg);
}

u64 cl_twt_get_wake_interval_us(struct ieee80211_twt_individual_elem *elem)
{
	u8 exponent = elem->req_type.fields.wake_interval_exponent;
	u64 mantissa = elem->wake_interval_mantissa;

	return (mantissa << exponent);
}

u32 cl_twt_get_min_wake_time_us(struct ieee80211_twt_individual_elem *elem)
{
	u8 duration_unit_exp = (elem->control.fields.wake_duration_unit << 1);
	u32 wake_time = elem->min_wake_duration;

	/* Convert to us (1 unit = 256us/1024us) */
	return (wake_time << (8 + duration_unit_exp));
}

void cl_twt_set_target_wake_time(struct cl_hw *cl_hw,
				 struct ieee80211_twt_individual_elem *elem)
{
	/* Read TSF and add it an offset to make sure we set a future TSF */
	u64 tsf = cl_get_tsf_u64(cl_hw) + CL_TWT_CONST_TARGET_WAKE_TIME_OFFSET_US;
	u64 start_time = tsf;
	struct cl_next_start_time sorted_next_start_times[CL_TWT_MAX_SESSIONS] = {};
	u8 i, num_sessions = cl_hw->twt_db.num_sessions;

	if (cl_hw->twt_db.num_sessions > 0) {
		u32 min_wake_time = cl_twt_get_min_wake_time_us(elem);

		cl_twt_get_next_start_times_sorted_array(cl_hw, tsf, sorted_next_start_times);

		/* Find the closest time for the new session */

		for (i = 0; i < num_sessions; i++) {
			struct cl_twt_session_db *curr_session =
				sorted_next_start_times[i].session;
			u32 curr_min_wake_time =
				cl_twt_get_min_wake_time_us(&curr_session->twt_setup);
			u64 curr_next_time = sorted_next_start_times[i].time;
			u64 next_next_time;

			/*
			 * We set the new session's start time such that the new TWT window
			 * would start right after the min wake time of the last session since
			 * we couldn't find a closer time for it.
			 */

			if (i == num_sessions - 1) {
				start_time = curr_next_time + curr_min_wake_time;
				break;
			}

			next_next_time = sorted_next_start_times[i + 1].time;

			/*
			 * We can put the new session between sessions i and i+1 without
			 * overlapping.
			 * The TWT windows would not overlap only if the intervals are a
			 * multiply of each other.
			 */

			if (next_next_time - curr_next_time >=
			    curr_min_wake_time + min_wake_time) {
				start_time = curr_next_time + curr_min_wake_time;
				break;
			}
		}
	}

	elem->target_wake_time = start_time;
}

void cl_twt_set_min_wake_duration(struct cl_hw *cl_hw,
				  struct ieee80211_twt_individual_elem *elem,
				  u32 duration_us)
{
	u16 duration_in_units_of_256_us = (duration_us >> 8);

	if (duration_in_units_of_256_us <= U8_MAX) {
		elem->min_wake_duration = duration_in_units_of_256_us;
		elem->control.fields.wake_duration_unit = 0;
	} else {
		/* Convert to units of 1024us */
		duration_in_units_of_256_us >>= 2;
		elem->min_wake_duration = duration_in_units_of_256_us;
		elem->control.fields.wake_duration_unit = 1;
	}

	if (duration_in_units_of_256_us > U8_MAX)
		cl_dbg_err(cl_hw, "Invalid min wake duration %u! exceeds 8 bits\n", duration_us);

	cl_dbg_info(cl_hw, "Set TWT min wake duration to %u us: "
			   "duration val - %u, duration unit - %u us\n",
		    duration_us, elem->min_wake_duration,
		    (elem->control.fields.wake_duration_unit ? 1024 : 256));
}

void cl_twt_set_interval(struct cl_hw *cl_hw,
			 struct ieee80211_twt_individual_elem *elem,
			 u64 interval_us)
{
	u8 exponent;
	u16 mantissa;

	if (!interval_us)
		return;

	exponent = ffs((u32)interval_us) - 1;

	elem->req_type.fields.wake_interval_exponent = exponent;
	mantissa = (interval_us >> exponent);
	elem->wake_interval_mantissa = mantissa;

	if (mantissa > U16_MAX)
		cl_dbg_err(cl_hw, "Invalid interval! mantissa exceeds 16 bits\n");

	cl_dbg_info(cl_hw, "Set TWT interval to %llu us: exponent %u, mantissa %u\n",
		    interval_us, elem->req_type.fields.wake_interval_exponent,
		    elem->wake_interval_mantissa);
}

int cl_twt_handle_individual_setup_request(struct cl_hw *cl_hw,
					   struct cl_sta *cl_sta,
					   struct cl_ieee80211_mgmt *request)
{
	struct mm_twt_setup_req req_msg;
	struct cl_twt_session_db *session = NULL;

	/* Max sessions reached */
	if (cl_hw->twt_db.num_sessions >= cl_hw->conf->ce_twt_max_sessions)
		return -1;

	/* Check the validity of the request */
	if (!cl_twt_frame_is_individual_setup_request_valid(cl_hw, request)) {
		cl_dbg_err(cl_hw, "TWT individual request is invalid!\n");
		return -1;
	}

	/* Send a TWT response and add a new TWT session to the db */
	if (cl_twt_frame_send_individual_setup_response(cl_hw, cl_sta, request, &session)) {
		cl_dbg_err(cl_hw, "TWT response failed!\n");
		return -1;
	}

	/* Fill and send a msg to fw */
	req_msg.sta_idx = session->cl_sta->sta_idx;
	req_msg.twt_flow_id = session->twt_setup.req_type.fields.flow_id;
	req_msg.min_wake_duration_us =
		cpu_to_le32(cl_twt_get_min_wake_time_us(&session->twt_setup));
	req_msg.twt_interval_us =
		cpu_to_le64(cl_twt_get_wake_interval_us(&session->twt_setup));
	req_msg.twt_start_time_tsf =
			cpu_to_le64(session->twt_setup.target_wake_time);
	req_msg.announced = !(session->twt_setup.req_type.fields.flow_type);
	req_msg.triggered = session->twt_setup.req_type.fields.trigger;

	cl_msg_tx_twt_setup(cl_hw, &req_msg);
	return 0;
}

int cl_twt_handle_individual_teardown_request(struct cl_hw *cl_hw,
					      struct cl_sta *cl_sta,
					      struct cl_ieee80211_mgmt *request)
{
	u8 flow_id = request->u.action.u.twt_individual_teardown.flow_id;
	bool all_twt = request->u.action.u.twt_individual_teardown.teardown_all_twt;

	if (all_twt)
		flow_id = CL_TWT_FLOW_ID_ALL;

	cl_twt_teardown_individual_sesseion(cl_hw, cl_sta, flow_id, false);
	return 0;
}
