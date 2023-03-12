/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_PHY_H
#define CL_PHY_H

#include "cl_hw.h"

int cl_phy_load_recovery(struct cl_hw *cl_hw);
int cl_phy_data_alloc(struct cl_hw *cl_hw);
void cl_phy_data_free(struct cl_hw *cl_hw);

#endif /* CL_PHY_H */
