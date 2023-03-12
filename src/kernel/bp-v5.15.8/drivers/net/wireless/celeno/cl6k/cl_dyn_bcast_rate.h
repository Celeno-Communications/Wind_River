/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_DYN_BCAST_RATE_H
#define CL_DYN_BCAST_RATE_H

#include "cl_hw.h"

void cl_dyn_bcast_rate_init(struct cl_hw *cl_hw);
void cl_dyn_bcast_rate_set(struct cl_hw *cl_hw, u8 bcast_mcs);
u16 cl_dyn_bcast_rate_get(struct cl_hw *cl_hw);
void cl_dyn_bcast_rate_recovery(struct cl_hw *cl_hw);
void cl_dyn_bcast_rate_change(struct cl_hw *cl_hw, struct cl_sta *cl_sta_change,
			      u8 old_mcs, u8 new_mcs);
void cl_dyn_bcast_rate_update_upon_assoc(struct cl_hw *cl_hw, u8 mcs, u8 num_sta);
void cl_dyn_bcast_rate_update_upon_disassoc(struct cl_hw *cl_hw, u8 mcs, u8 num_sta);

#endif /* CL_DYN_BCAST_RATE_H */
