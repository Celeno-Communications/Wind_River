/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_AMPDU_H
#define CL_AMPDU_H

#include "cl_sta.h"

int cl_ampdu_rx_start(struct cl_hw *cl_hw,
		      struct cl_sta *cl_sta,
		      u16 tid,
		      u16 ssn,
		      u16 buf_size);

void cl_ampdu_rx_stop(struct cl_hw *cl_hw,
		      struct cl_sta *cl_sta,
		      u16 tid);

int cl_ampdu_tx_start(struct cl_hw *cl_hw,
		      struct ieee80211_vif *vif,
		      struct cl_sta *cl_sta,
		      u16 tid,
		      u16 ssn);

int cl_ampdu_tx_operational(struct cl_hw *hw,
			    struct cl_sta *cl_sta,
			    u16 tid,
			    u16 buf_size,
			    bool amsdu_supported);

void _cl_ampdu_tx_stop(struct cl_hw *cl_hw,
		       struct cl_tx_queue *tx_queue,
		       struct cl_sta *cl_sta,
		       u8 tid);

int cl_ampdu_tx_stop(struct cl_hw *cl_hw,
		     struct ieee80211_vif *vif,
		     enum ieee80211_ampdu_mlme_action action,
		     struct cl_sta *cl_sta,
		     u16 tid);

void cl_ampdu_size_exp(struct cl_hw *cl_hw, struct ieee80211_sta *sta,
		       u8 *ampdu_exp_he, u8 *ampdu_exp_vht, u8 *ampdu_exp_ht);

#endif /* CL_AMPDU_H */
