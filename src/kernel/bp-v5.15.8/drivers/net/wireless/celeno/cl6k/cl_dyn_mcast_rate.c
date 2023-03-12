// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_band.h"
#include "cl_sta.h"
#include "cl_dyn_mcast_rate.h"
#include "cl_rate_ctrl.h"
#include "cl_utils.h"

static void _cl_dyn_mcast_rate_send(struct cl_hw *cl_hw, u8 wrs_mode_new)
{
	struct cl_dyn_mcast_rate *dyn_mcast_rate = &cl_hw->dyn_mcast_rate;

	if (dyn_mcast_rate->wrs_mode_curr == wrs_mode_new)
		return;

	if (!cl_rate_ctrl_set_mcast(cl_hw, wrs_mode_new, cl_hw->conf->ce_mcast_rate))
		return;

	dyn_mcast_rate->wrs_mode_curr = wrs_mode_new;
	cl_dbg_trace(cl_hw, "New multicast mode = %u\n", wrs_mode_new);
}

void cl_dyn_mcast_rate_init(struct cl_hw *cl_hw)
{
	struct cl_dyn_mcast_rate *dyn_mcast_rate = &cl_hw->dyn_mcast_rate;

	if (cl_hw->conf->ci_min_he_en &&
	    cl_hw->conf->ce_wireless_mode == WIRELESS_MODE_HE)
		dyn_mcast_rate->wrs_mode_default = WRS_MODE_HE;
	else if (cl_band_is_24g(cl_hw) && cl_hw_mode_is_b_or_bg(cl_hw) &&
		 cl_hw->conf->ci_cck_en)
		dyn_mcast_rate->wrs_mode_default = WRS_MODE_CCK;
	else
		dyn_mcast_rate->wrs_mode_default = WRS_MODE_OFDM;

	cl_dbg_trace(cl_hw, "mode = %u, mcs = %u\n",
		     dyn_mcast_rate->wrs_mode_default, cl_hw->conf->ce_mcast_rate);
}

void cl_dyn_mcast_rate_set(struct cl_hw *cl_hw)
{
	/*
	 * Set wrs_mode_curr to 0xff so that the message will be sent to
	 * firmware when this function is called from cl_ops_start()
	 */
	struct cl_dyn_mcast_rate *dyn_mcast_rate = &cl_hw->dyn_mcast_rate;

	dyn_mcast_rate->wrs_mode_curr = U8_MAX;

	_cl_dyn_mcast_rate_send(cl_hw, dyn_mcast_rate->wrs_mode_default);
}

void cl_dyn_mcast_rate_recovery(struct cl_hw *cl_hw)
{
	/*
	 * cl_dyn_mcast_rate_recovery() is called during recovery process().
	 * Reset wrs_mode_curr so that message will be sent.
	 */
	struct cl_dyn_mcast_rate *dyn_mcast_rate = &cl_hw->dyn_mcast_rate;
	u8 wrs_mode_curr = dyn_mcast_rate->wrs_mode_curr;

	dyn_mcast_rate->wrs_mode_curr = U8_MAX;

	_cl_dyn_mcast_rate_send(cl_hw, wrs_mode_curr);
}

void cl_dyn_mcast_rate_update_upon_assoc(struct cl_hw *cl_hw, u8 wrs_mode, u8 num_sta)
{
	struct cl_dyn_mcast_rate *dyn_mcast_rate = &cl_hw->dyn_mcast_rate;

	if (!cl_hw->conf->ce_dyn_mcast_rate_en)
		return;

	/*
	 * If the wrs_mode of the new station is lower than the current multicast
	 * wrs_mode, or if this is the first station to connect - update multicast mode
	 */
	if (wrs_mode < dyn_mcast_rate->wrs_mode_curr || num_sta == 1)
		_cl_dyn_mcast_rate_send(cl_hw, wrs_mode);
}

void cl_dyn_mcast_rate_update_upon_disassoc(struct cl_hw *cl_hw, u8 wrs_mode, u8 num_sta)
{
	struct cl_dyn_mcast_rate *dyn_mcast_rate = &cl_hw->dyn_mcast_rate;
	struct cl_sta *cl_sta = NULL;
	u8 wrs_mode_min = WRS_MODE_HE;

	if (!cl_hw->conf->ce_dyn_mcast_rate_en)
		return;

	/* When the last station disconnects - set default mcast rate */
	if (num_sta == 0) {
		_cl_dyn_mcast_rate_send(cl_hw, dyn_mcast_rate->wrs_mode_default);
		return;
	}

	/*
	 * If wrs_mode of the disassociating station is bigger
	 * than the current mode then there is nothing to update.
	 */
	if (wrs_mode > dyn_mcast_rate->wrs_mode_curr)
		return;

	/*
	 * Find minimal wrs_mode among the connected stations (the
	 * disassociating station is not in list at this stage).
	 */
	cl_sta_lock_bh(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list)
		if (cl_sta->wrs_sta.mode < wrs_mode_min)
			wrs_mode_min = cl_sta->wrs_sta.mode;

	cl_sta_unlock_bh(cl_hw);

	_cl_dyn_mcast_rate_send(cl_hw, wrs_mode_min);
}
