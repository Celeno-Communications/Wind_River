/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_AGE_OUT_H
#define CL_AGE_OUT_H

#include "cl_hw.h"
#include "cl_sta.h"

#define CL_AGE_OUT_MINIMUM_THR_SEC 60

void cl_age_out_init(struct cl_hw *cl_hw);
void cl_age_out_close(struct cl_hw *cl_hw);
void cl_age_out_reset_counter(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_age_out_maintenance(struct cl_hw *cl_hw);

#endif /* CL_AGE_OUT_H */
