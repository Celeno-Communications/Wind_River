/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_MAINTENANCE_H
#define CL_MAINTENANCE_H

#include "cl_hw.h"

#define CL_MAINTENANCE_PERIOD_SLOW_MS   1000
#define CL_MAINTENANCE_PERIOD_FAST_MS   100

void cl_maintenance_init(struct cl_hw *cl_hw);
void cl_maintenance_deinit(struct cl_hw *cl_hw);
void cl_maintenance_start(struct cl_hw *cl_hw);

#endif /* CL_MAINTENANCE_H */
