// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_dyn_bcast_rate.h"
#include "cl_band.h"
#include "cl_sta.h"
#include "cl_rate_ctrl.h"
#include "cl_msg_tx.h"
#include "cl_utils.h"
#include "cl_data_rates.h"

/*
 * MIN_MCS | BCAST_MCS
 * -------------------
 * 0 - 1   | 0
 * 2 - 3   | 1
 * 4 - 5   | 2
 * 6 - 7   | 3
 * 8 - 9   | 4
 * 10 - 11 | 5
 */

static u8 conv_min_mcs_to_bcast_mcs[WRS_MCS_MAX] = {
	0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5
};

static void cl_dyn_bcast_rate_update(struct cl_hw *cl_hw, u8 min_mcs)
{
	struct cl_dyn_bcast_rate *dyn_bcast_rate = &cl_hw->dyn_bcast_rate;
	u8 bcast_mcs = conv_min_mcs_to_bcast_mcs[min_mcs];

	dyn_bcast_rate->sta_min_mcs = min_mcs;

	if (bcast_mcs != dyn_bcast_rate->bcast_mcs)
		cl_dyn_bcast_rate_set(cl_hw, bcast_mcs);
}

void cl_dyn_bcast_rate_init(struct cl_hw *cl_hw)
{
	struct cl_dyn_bcast_rate *dyn_bcast_rate = &cl_hw->dyn_bcast_rate;

	dyn_bcast_rate->sta_min_mcs = 0;
	dyn_bcast_rate->bcast_mcs = conv_min_mcs_to_bcast_mcs[0];

	if (cl_band_is_6g(cl_hw)) {
		dyn_bcast_rate->wrs_mode = WRS_MODE_HE;
		dyn_bcast_rate->ltf = LTF_X4;
	} else if (cl_band_is_24g(cl_hw) && cl_hw_mode_is_b_or_bg(cl_hw) &&
		   cl_hw->conf->ci_cck_en) {
		dyn_bcast_rate->wrs_mode = WRS_MODE_CCK;
		dyn_bcast_rate->ltf = 0;
	} else {
		dyn_bcast_rate->wrs_mode = WRS_MODE_OFDM;
		dyn_bcast_rate->ltf = 0;
	}
}

void cl_dyn_bcast_rate_set(struct cl_hw *cl_hw, u8 bcast_mcs)
{
	struct cl_dyn_bcast_rate *dyn_bcast_rate = &cl_hw->dyn_bcast_rate;
	u8 wrs_mode = dyn_bcast_rate->wrs_mode;
	u8 ltf = dyn_bcast_rate->ltf;
	u32 rate_ctrl;

	cl_hw->dyn_bcast_rate.bcast_mcs = bcast_mcs;

	rate_ctrl = cl_rate_ctrl_generate(cl_hw, NULL, wrs_mode, 0, 0, bcast_mcs,
					  0, false);
	cl_msg_tx_update_rate_dl(cl_hw, U8_MAX, rate_ctrl, 0, 0,
				 RATE_OP_MODE_BCAST, 0, ltf, 0, 0);

	cl_dbg_info(cl_hw, "Broadcast MCS set to %u\n", bcast_mcs);
}

u16 cl_dyn_bcast_rate_get(struct cl_hw *cl_hw)
{
	struct cl_dyn_bcast_rate *dyn_bcast_rate = &cl_hw->dyn_bcast_rate;

	return cl_data_rates_get(dyn_bcast_rate->wrs_mode, 0, 0, dyn_bcast_rate->bcast_mcs, 0);
}

void cl_dyn_bcast_rate_recovery(struct cl_hw *cl_hw)
{
	cl_dyn_bcast_rate_set(cl_hw, cl_hw->dyn_bcast_rate.bcast_mcs);
}

void cl_dyn_bcast_rate_change(struct cl_hw *cl_hw, struct cl_sta *cl_sta_change,
			      u8 old_mcs, u8 new_mcs)
{
	struct cl_dyn_bcast_rate *dyn_bcast_rate = &cl_hw->dyn_bcast_rate;
	struct cl_sta *cl_sta = NULL;
	u8 min_mcs = WRS_MCS_MAX - 1;
	u8 sta_mcs = 0;

	if (!cl_hw->conf->ce_dyn_bcast_rate_en)
		return;

	if (!cl_sta_change->add_complete)
		return;

	/* Single station */
	if (cl_sta_num_bh(cl_hw) == 1) {
		cl_dyn_bcast_rate_update(cl_hw, new_mcs);
		return;
	}

	/*
	 * If this station did not have the minimum mcs,
	 * and the new rate is now below the minimum mcs there is nothing to do
	 */
	if (old_mcs > dyn_bcast_rate->sta_min_mcs &&
	    new_mcs > dyn_bcast_rate->sta_min_mcs)
		return;

	/* Multi station - find new minimum MCS of all stations */
	cl_sta_lock_bh(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		sta_mcs = (cl_sta->sta_idx == cl_sta_change->sta_idx) ?
			new_mcs : cl_sta->wrs_sta.tx_su_params.rate_params.mcs;

		if (sta_mcs < min_mcs) {
			min_mcs = sta_mcs;

			if (min_mcs == 0)
				break;
		}
	}

	cl_sta_unlock_bh(cl_hw);

	cl_dyn_bcast_rate_update(cl_hw, min_mcs);
}

void cl_dyn_bcast_rate_update_upon_assoc(struct cl_hw *cl_hw, u8 mcs, u8 num_sta)
{
	struct cl_dyn_bcast_rate *dyn_bcast_rate = &cl_hw->dyn_bcast_rate;

	if (!cl_hw->conf->ce_dyn_bcast_rate_en)
		return;

	if (num_sta == 1 || mcs < dyn_bcast_rate->sta_min_mcs)
		cl_dyn_bcast_rate_update(cl_hw, mcs);
}

void cl_dyn_bcast_rate_update_upon_disassoc(struct cl_hw *cl_hw, u8 mcs, u8 num_sta)
{
	struct cl_dyn_bcast_rate *dyn_bcast_rate = &cl_hw->dyn_bcast_rate;
	struct cl_sta *cl_sta = NULL;
	u8 min_mcs = WRS_MCS_MAX - 1;

	if (!cl_hw->conf->ce_dyn_bcast_rate_en)
		return;

	/* When the last station disconnects - set bcast back to 0 */
	if (num_sta == 0) {
		cl_dyn_bcast_rate_update(cl_hw, 0);
		return;
	}

	/* If this station did not have the minimum rate there is nothing to do */
	if (mcs > dyn_bcast_rate->sta_min_mcs)
		return;

	/*
	 * Find new minimum MCS of all station (the disassociating
	 * station is not in list at this stage)
	 */
	cl_sta_lock_bh(cl_hw);

	list_for_each_entry(cl_sta, &cl_hw->cl_sta_db.head, list) {
		if (cl_sta->wrs_sta.tx_su_params.rate_params.mcs < min_mcs) {
			min_mcs = cl_sta->wrs_sta.tx_su_params.rate_params.mcs;

			if (min_mcs == 0)
				break;
		}
	}

	cl_sta_unlock_bh(cl_hw);

	cl_dyn_bcast_rate_update(cl_hw, min_mcs);
}
