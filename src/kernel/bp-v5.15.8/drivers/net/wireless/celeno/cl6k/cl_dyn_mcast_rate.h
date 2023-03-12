/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_DYN_MCAST_RATE_H
#define CL_DYN_MCAST_RATE_H

void cl_dyn_mcast_rate_init(struct cl_hw *cl_hw);
void cl_dyn_mcast_rate_set(struct cl_hw *cl_hw);
void cl_dyn_mcast_rate_recovery(struct cl_hw *cl_hw);
void cl_dyn_mcast_rate_update_upon_assoc(struct cl_hw *cl_hw, u8 wrs_mode, u8 num_sta);
void cl_dyn_mcast_rate_update_upon_disassoc(struct cl_hw *cl_hw, u8 wrs_mode, u8 num_sta);

#endif /* CL_DYN_MCAST_RATE_H */
