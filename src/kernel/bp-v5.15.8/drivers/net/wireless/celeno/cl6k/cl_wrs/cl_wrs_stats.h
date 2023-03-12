/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_WRS_STATS_H
#define CL_WRS_STATS_H

#include "cl_wrs_db.h"

struct cl_hw;

void cl_wrs_stats_per_update(struct cl_wrs_db *wrs_db,
			     struct cl_wrs_sta *wrs_sta,
			     struct cl_wrs_params *wrs_params,
			     struct cl_wrs_cntrs *cntrs);
void cl_wrs_stats_per_print(struct cl_hw *cl_hw,
			    struct cl_wrs_sta *wrs_sta,
			    struct cl_wrs_params *wrs_params);
void cl_wrs_stats_per_reset(struct cl_wrs_params *wrs_params);
void cl_wrs_stats_per_init(struct cl_wrs_params *wrs_params);
void cl_wrs_stats_per_remove(struct cl_wrs_params *wrs_params);
void cl_wrs_stats_decision_print(struct cl_wrs_params *wrs_params);
void cl_wrs_stats_decision_reset(struct cl_wrs_params *wrs_params);

#endif /* CL_WRS_STATS_H */
