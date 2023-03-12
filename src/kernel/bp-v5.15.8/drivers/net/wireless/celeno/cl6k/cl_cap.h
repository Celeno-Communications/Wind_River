/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CAP_H
#define CL_CAP_H

#include "cl_hw.h"

#define PPE_0US 0
#define PPE_8US 1
#define PPE_16US 2

void cl_cap_dyn_params(struct cl_hw *cl_hw);
void cl_cap_ppe_duration(struct cl_hw *cl_hw, struct ieee80211_sta *sta,
			 u8 pe_dur[CHNL_BW_MAX][WRS_MCS_MAX_HE]);

#endif /* CL_CAP_H */
