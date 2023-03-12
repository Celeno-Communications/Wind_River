// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_twt_frame.h"
#include "cl_twt.h"
#include "cl_sta.h"
#include "cl_mac_addr.h"
#include "cl_tx.h"

static int cl_twt_frame_build_individual_setup(struct cl_hw *cl_hw,
					       struct sk_buff **skb_ptr,
					       struct cl_sta *cl_sta)
{
	struct ieee80211_sub_if_data *sdata = cl_sta->stainfo->sdata;
	struct sk_buff *skb;
	struct cl_ieee80211_mgmt *mgmt;
	int hdr_len = offsetof(struct cl_ieee80211_mgmt, u.action.u.twt_individual_setup) +
		sizeof(mgmt->u.action.u.twt_individual_setup);
	u8 *bssid;

	skb = dev_alloc_skb(cl_hw->hw->extra_tx_headroom + hdr_len);

	if (!skb)
		return -ENOMEM;

	if (sdata->vif.type == NL80211_IFTYPE_STATION)
		bssid = sdata->u.mgd.bssid;
	else
		bssid = sdata->vif.addr;

	skb_reserve(skb, cl_hw->hw->extra_tx_headroom);
	mgmt = (struct cl_ieee80211_mgmt *)skb_put_zero(skb, hdr_len);
	cl_mac_addr_copy(mgmt->sa, sdata->vif.addr);
	cl_mac_addr_copy(mgmt->da, cl_sta->addr);
	cl_mac_addr_copy(mgmt->bssid, bssid);
	mgmt->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT |
					  IEEE80211_STYPE_ACTION);

	mgmt->u.action.category = WLAN_CATEGORY_S1G;
	mgmt->u.action.u.twt_individual_setup.action_code = WLAN_UNPROT_S1G_ACTION_TWT_SETUP;
	mgmt->u.action.u.twt_individual_setup.dialog_token = cl_hw->twt_db.dialog_token++;

	mgmt->u.action.u.twt_individual_setup.twt_elem_id = WLAN_EID_TWT;
	mgmt->u.action.u.twt_individual_setup.twt_elem_length =
		sizeof(struct ieee80211_twt_individual_elem);

	*skb_ptr = skb;
	return 0;
}

static int cl_twt_frame_build_individual_teardown(struct cl_hw *cl_hw,
						  struct sk_buff **skb_ptr,
						  struct cl_sta *cl_sta,
						  u8 flow_id)
{
	struct ieee80211_sub_if_data *sdata = cl_sta->stainfo->sdata;
	struct sk_buff *skb;
	struct cl_ieee80211_mgmt *mgmt;
	int hdr_len = offsetof(struct cl_ieee80211_mgmt, u.action.u.twt_individual_teardown) +
		sizeof(mgmt->u.action.u.twt_individual_teardown);
	u8 *bssid;

	skb = dev_alloc_skb(cl_hw->hw->extra_tx_headroom + hdr_len);

	if (!skb)
		return -ENOMEM;

	if (sdata->vif.type == NL80211_IFTYPE_STATION)
		bssid = sdata->u.mgd.bssid;
	else
		bssid = sdata->vif.addr;

	skb_reserve(skb, cl_hw->hw->extra_tx_headroom);
	mgmt = (struct cl_ieee80211_mgmt *)skb_put_zero(skb, hdr_len);
	cl_mac_addr_copy(mgmt->sa, sdata->vif.addr);
	cl_mac_addr_copy(mgmt->da, cl_sta->addr);
	cl_mac_addr_copy(mgmt->bssid, bssid);
	mgmt->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT |
					  IEEE80211_STYPE_ACTION);

	mgmt->u.action.category = WLAN_CATEGORY_S1G;
	mgmt->u.action.u.twt_individual_teardown.action_code = WLAN_UNPROT_S1G_ACTION_TWT_TEARDOWN;
	mgmt->u.action.u.twt_individual_teardown.negotiation_type = 0;

	if (flow_id == CL_TWT_FLOW_ID_ALL) {
		mgmt->u.action.u.twt_individual_teardown.teardown_all_twt = 1;
		mgmt->u.action.u.twt_individual_teardown.flow_id = 0;
	} else {
		mgmt->u.action.u.twt_individual_teardown.teardown_all_twt = 0;
		mgmt->u.action.u.twt_individual_teardown.flow_id = flow_id;
	}

	*skb_ptr = skb;
	return 0;
}

static void
cl_twt_frame_fill_setup_response_parameters(struct cl_hw *cl_hw,
					    struct ieee80211_twt_individual_elem *request_ie,
					    struct cl_ieee80211_mgmt *mgmt)
{
	struct ieee80211_twt_individual_elem *twt_elem =
		&mgmt->u.action.u.twt_individual_setup.twt_elem;
	u64 interval;
	u32 default_interval = cl_hw->conf->ce_twt_default_interval;
	u32 default_min_wake_duration = cl_hw->conf->ce_twt_default_min_wake_duration;

	/* Copy TWT element parameters from the request */
	*twt_elem = *request_ie;

	/* Override the relevant parameters */
	twt_elem->req_type.fields.request = 0;
	twt_elem->control.fields.negotiation_type = 0;
	twt_elem->req_type.fields.setup_cmd = IEEE80211_TWT_SETUP_COMMAND_ACCEPT;
	twt_elem->req_type.fields.protection = 0;
	twt_elem->channel = 0;

	/*
	 * Set default values of wake interval exponent/mantissa and min
	 * wake duration in case that at least one of them equals to 0
	 */
	interval = cl_twt_get_wake_interval_us(twt_elem);

	if (!twt_elem->min_wake_duration) {
		if (default_min_wake_duration < interval) {
			cl_twt_set_min_wake_duration(cl_hw, twt_elem, default_min_wake_duration);
		} else if (interval) {
			/* If default min wake time > interval - set it to half of the interval */
			cl_twt_set_min_wake_duration(cl_hw, twt_elem, (interval >> 1));
		} else {
			/* Set default interval and min wake duration */
			cl_twt_set_interval(cl_hw, twt_elem, default_interval);
			cl_twt_set_min_wake_duration(cl_hw, twt_elem, default_min_wake_duration);
		}
	} else if (!interval) {
		u32 min_wake_duration = cl_twt_get_min_wake_time_us(twt_elem);

		if (min_wake_duration < default_interval)
			cl_twt_set_interval(cl_hw, twt_elem, default_interval);
		else
			/*
			 * If the default interval < min wake duration -
			 * set it to be double the min wake duration
			 */
			cl_twt_set_interval(cl_hw, twt_elem, (min_wake_duration << 1));
	}

	cl_twt_set_target_wake_time(cl_hw, twt_elem);
}

static void cl_twt_frmae_fill_setup_request_parameters(struct cl_hw *cl_hw,
						       struct cl_ieee80211_mgmt *mgmt,
						       enum ieee80211_twt_setup_command setup_cmd,
						       u8 flow_id,
						       bool announced,
						       bool triggered,
						       u64 interval_us,
						       u32 min_wake_duration_us)
{
	struct ieee80211_twt_individual_elem *twt_elem =
		&mgmt->u.action.u.twt_individual_setup.twt_elem;
	u64 _interval_us = interval_us;
	u32 _min_wake_duration_us = min_wake_duration_us;

	/* Override the relevant parameters */

	twt_elem->control.fields.negotiation_type = 0;
	twt_elem->req_type.fields.protection = 0;
	twt_elem->channel = 0;
	twt_elem->req_type.fields.request = 1;
	twt_elem->req_type.fields.implicit = 1;
	twt_elem->req_type.fields.setup_cmd = setup_cmd;
	twt_elem->req_type.fields.flow_id = flow_id;
	twt_elem->req_type.fields.flow_type = !announced;
	twt_elem->req_type.fields.trigger = triggered;

	if (!interval_us)
		_interval_us = cl_hw->conf->ce_twt_default_interval;

	if (!min_wake_duration_us)
		_min_wake_duration_us = cl_hw->conf->ce_twt_default_min_wake_duration;

	if (_min_wake_duration_us < _interval_us) {
		/* Min wake duration < interval */
		cl_twt_set_interval(cl_hw, twt_elem, _interval_us);
		cl_twt_set_min_wake_duration(cl_hw, twt_elem, _min_wake_duration_us);
	} else {
		if (!interval_us) {
			/*
			 * Min wake duration argument >= default interval =>
			 * Set the interval to be double the min wake duration
			 */
			cl_twt_set_min_wake_duration(cl_hw, twt_elem, _min_wake_duration_us);
			cl_twt_set_interval(cl_hw, twt_elem, (_min_wake_duration_us << 1));
		} else {
			/*
			 * Interval argument <= default min wake duration =>
			 * Set the min wake duration to be half the interval
			 */
			cl_twt_set_interval(cl_hw, twt_elem, _interval_us);
			cl_twt_set_min_wake_duration(cl_hw, twt_elem, (_interval_us >> 1));
		}
	}
}

bool cl_twt_frame_is_individual_setup_request_valid(struct cl_hw *cl_hw,
						    struct cl_ieee80211_mgmt *request)
{
	u8 twt_elem_len = request->u.action.u.twt_individual_setup.twt_elem_length;
	struct ieee80211_twt_individual_elem *twt_elem =
		&request->u.action.u.twt_individual_setup.twt_elem;
	u64 wake_interval_us;
	u32 min_wake_time_us;

	if (twt_elem_len != sizeof(struct ieee80211_twt_individual_elem)) {
		cl_dbg_err(cl_hw, "Illegal size of twt individual element %u (should be %zu)\n",
			   twt_elem_len, sizeof(struct ieee80211_twt_individual_elem));
		return false;
	}

	wake_interval_us = cl_twt_get_wake_interval_us(twt_elem);
	min_wake_time_us = cl_twt_get_min_wake_time_us(twt_elem);

	if (min_wake_time_us && wake_interval_us && min_wake_time_us > wake_interval_us) {
		cl_dbg_err(cl_hw, "min wake duration (%u) > wake interval (%llu)!\n",
			   min_wake_time_us, wake_interval_us);
		return false;
	}

	return true;
}

int cl_twt_frame_send_individual_setup_response(struct cl_hw *cl_hw,
						struct cl_sta *cl_sta,
						struct cl_ieee80211_mgmt *request,
						struct cl_twt_session_db **session)
{
	struct sk_buff *skb;
	struct cl_ieee80211_mgmt *mgmt;
	struct ieee80211_twt_individual_elem *req_twt_elem;
	struct ieee80211_twt_individual_elem *res_twt_elem;
	u8 flow_id;

	if (cl_twt_frame_build_individual_setup(cl_hw, &skb, cl_sta)) {
		cl_dbg_err(cl_hw, "Build of TWT individual setup request failed!\n");
		return -1;
	}

	req_twt_elem = &request->u.action.u.twt_individual_setup.twt_elem;
	mgmt = (struct cl_ieee80211_mgmt *)skb->data;
	cl_twt_frame_fill_setup_response_parameters(cl_hw, req_twt_elem, mgmt);
	flow_id = req_twt_elem->req_type.fields.flow_id;
	res_twt_elem = &mgmt->u.action.u.twt_individual_setup.twt_elem;

	/* Check if a session with the same sta_idx and flow_id already exists */
	*session = cl_twt_get_session(cl_hw, cl_sta, flow_id);

	/*
	 * If the seesion already exists - update it.
	 * Otherwise add a new TWT session to the db.
	 */
	if (*session) {
		cl_dbg_info(cl_hw, "Updating an existing TWT session sta_idx %u, flow_id %u\n",
			    cl_sta->sta_idx, flow_id);
		cl_twt_update_session(cl_hw, cl_sta, res_twt_elem, *session);
	} else if (cl_twt_add_session(cl_hw, cl_sta, res_twt_elem, session)) {
		cl_dbg_err(cl_hw, "Session for sta %u could not be added. Aborting\n",
			   cl_sta->sta_idx);
		dev_kfree_skb_any(skb);
		goto error;
	} else {
		cl_dbg_info(cl_hw, "A new TWT session was added. sta_idx %u, flow_id %u\n",
			    cl_sta->sta_idx, flow_id);
	}

	/* Send the TWT response */
	ieee80211_tx_prepare_skb(cl_hw->hw, cl_sta->cl_vif->vif, skb, cl_hw->nl_band, NULL);
	cl_tx_single(cl_hw, cl_sta, skb, false, true);
	cl_dbg_trace(cl_hw, "TWT individual setup response sent to STA %u\n", cl_sta->sta_idx);

	return 0;
 error:
	return -1;
}

int cl_twt_frame_send_individual_setup_request(struct cl_hw *cl_hw,
					       struct cl_sta *cl_sta,
					       enum ieee80211_twt_setup_command setup_cmd,
					       u8 flow_id,
					       bool announced,
					       bool triggered,
					       u64 interval_us,
					       u32 min_wake_duration_us)
{
	/* Send a TWT individual setup request (should be used in STA mode) */
	struct sk_buff *skb;

	if (cl_twt_frame_build_individual_setup(cl_hw, &skb, cl_sta)) {
		cl_dbg_err(cl_hw, "Build of TWT individual setup request failed!\n");
		return -1;
	}

	cl_twt_frmae_fill_setup_request_parameters(cl_hw, (struct cl_ieee80211_mgmt *)skb->data,
						   setup_cmd, flow_id, announced, triggered,
						   interval_us, min_wake_duration_us);

	/* Send the TWT request */
	ieee80211_tx_prepare_skb(cl_hw->hw, cl_sta->cl_vif->vif, skb, cl_hw->nl_band, NULL);
	cl_tx_single(cl_hw, cl_sta, skb, false, true);
	cl_dbg_trace(cl_hw, "TWT individual setup request sent\n");

	return 0;
}

int cl_twt_frame_simulate_individual_setup_request(struct cl_hw *cl_hw,
						   struct cl_sta *cl_sta,
						   enum ieee80211_twt_setup_command setup_cmd,
						   u8 flow_id,
						   bool announced,
						   bool triggered,
						   u64 interval_us,
						   u32 min_wake_duration_us)
{
	/* Simulates a TWT individual setup request in STA mode */
	struct sk_buff *skb;
	struct cl_ieee80211_mgmt *mgmt;

	if (cl_twt_frame_build_individual_setup(cl_hw, &skb, cl_sta)) {
		cl_dbg_err(cl_hw, "Build of TWT individual setup request failed!\n");
		return -1;
	}

	mgmt = (struct cl_ieee80211_mgmt *)skb->data;

	cl_twt_frmae_fill_setup_request_parameters(cl_hw, mgmt, setup_cmd,
						   flow_id, announced, triggered,
						   interval_us, min_wake_duration_us);
	cl_dbg_trace(cl_hw, "TWT individual setup request simulated\n");
	cl_twt_handle_individual_setup_request(cl_hw, cl_sta, mgmt);

	dev_kfree_skb_any(skb);
	return 0;
}

int cl_twt_frame_send_individual_teardown_request(struct cl_hw *cl_hw,
						  struct cl_sta *cl_sta,
						  u8 flow_id)
{
	/* Send a TWT individual teardown request */
	struct sk_buff *skb;

	if (cl_twt_frame_build_individual_teardown(cl_hw, &skb, cl_sta, flow_id)) {
		cl_dbg_err(cl_hw, "Build of a TWT individual teardown request failed!\n");
		return -1;
	}

	/* Send the TWT request */
	ieee80211_tx_prepare_skb(cl_hw->hw, cl_sta->cl_vif->vif, skb, cl_hw->nl_band, NULL);
	cl_tx_single(cl_hw, cl_sta, skb, false, true);
	cl_dbg_trace(cl_hw, "TWT individual teardown request sent\n");

	return 0;
}

int cl_twt_frame_simulate_individual_teardown_request(struct cl_hw *cl_hw,
						      struct cl_sta *cl_sta,
						      u8 flow_id)
{
	/* Simulate a TWT individual teardown request */
	struct sk_buff *skb;
	struct cl_ieee80211_mgmt *mgmt;

	if (cl_twt_frame_build_individual_teardown(cl_hw, &skb, cl_sta, flow_id)) {
		cl_dbg_err(cl_hw, "Build of TWT individual teardown request failed!\n");
		return -1;
	}

	mgmt = (struct cl_ieee80211_mgmt *)skb->data;

	cl_dbg_trace(cl_hw, "TWT individual teardown request simulated\n");
	cl_twt_handle_individual_teardown_request(cl_hw, cl_sta, mgmt);

	dev_kfree_skb_any(skb);
	return 0;
}
