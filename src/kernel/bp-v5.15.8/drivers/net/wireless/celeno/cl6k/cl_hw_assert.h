/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_HW_ASSERT_H
#define CL_HW_ASSERT_H

#include "cl_hw.h"

void cl_hw_assert_info_init(struct cl_hw *cl_hw);
void cl_hw_assert_print(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg);
void cl_hw_assert_check(struct cl_hw *cl_hw);

#endif /* CL_HW_ASSERT_H */
