/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_VW_H
#define CL_VW_H

#include "cl_hw.h"

void cl_vw_sta_assoc(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
		     s8 rssi[MAX_ANTENNAS], u8 num_sta);
void cl_vw_sta_remove(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 num_sta);
bool cl_vw_is_detected(struct cl_hw *cl_hw);
void cl_vw_start_tx_ba_session(struct cl_hw *cl_hw, struct ieee80211_sta *sta);
int cl_vw_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_VW_H */
