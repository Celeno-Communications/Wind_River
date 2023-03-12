/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_BAW_H
#define CL_BAW_H

#include "cl_hw.h"
#include "cl_sta.h"

void cl_baw_init(struct cl_sta *cl_sta);
void cl_baw_start(struct cl_baw *baw, u16 ssn);
void cl_baw_operational(struct cl_hw *cl_hw, struct cl_baw *baw,
			u8 fw_agg_idx, bool amsdu_supported);
void cl_baw_stop(struct cl_baw *baw);
void cl_baw_tx_inject(struct cl_hw *cl_hw,
		      struct cl_baw *baw,
		      u8 fw_agg_idx);
void cl_baw_pending_to_agg(struct cl_hw *cl_hw,
			   struct cl_sta *cl_sta,
			   u8 tid);
void cl_baw_pending_to_single(struct cl_hw *cl_hw,
			      struct cl_sta *cl_sta,
			      struct cl_baw *baw);
void cl_baw_pending_purge(struct cl_baw *baw);

#endif /* CL_BAW_H */
