/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_AGG_RX_REPORT_H
#define CL_AGG_RX_REPORT_H

#include "cl_hw.h"
#include "cl_sta.h"
#include "cl_fw_msg.h"

void cl_agg_rx_report_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			      struct mm_agg_rx_ind *agg_report);

#endif /* CL_AGG_RX_REPORT_H */
