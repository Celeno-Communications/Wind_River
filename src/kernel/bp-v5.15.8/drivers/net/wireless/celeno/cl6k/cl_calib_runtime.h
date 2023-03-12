/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CALIB_RUNTIME_H
#define CL_CALIB_RUNTIME_H

#include "def.h"
#include "cl_hw.h"

int cl_calib_runtime_and_switch_channel(struct cl_hw *cl_hw, u32 channel, u8 bw, u32 primary,
					u32 center);
void cl_calib_runtime_work(struct cl_hw *cl_hw, u32 channel, u8 bw, u16 primary, u16 center);
void cl_calib_runtime_create_calib_files(struct cl_hw *cl_hw);

#endif /* CL_CALIB_RUNTIME_H */
