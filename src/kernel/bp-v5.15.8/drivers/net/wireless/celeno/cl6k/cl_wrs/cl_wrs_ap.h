/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_WRS_AP_H
#define CL_WRS_AP_H

#include "cl_wrs_db.h"
#include "cl_hw.h"

void cl_wrs_ap_capab_set(struct cl_hw *cl_hw);
void cl_wrs_ap_capab_modify_bw(struct cl_hw *cl_hw, struct cl_wrs_db *wrs_db, u8 max_bw);

#endif /* CL_WRS_AP_H */
