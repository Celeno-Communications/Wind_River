/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_PROT_MODE_H
#define CL_PROT_MODE_H

#include "cl_hw.h"

enum cl_txl_prot_mode {
	TXL_NO_PROT,
	TXL_PROT_RSV1,
	TXL_PROT_RSV2,
	TXL_PROT_RTS_FW,
	TXL_PROT_CTS_FW,

	TXL_PROT_MAX,
};

void cl_prot_mode_init(struct cl_hw *cl_hw);
void cl_prot_mode_disable(struct cl_hw *cl_hw);
void cl_prot_mode_enable(struct cl_hw *cl_hw);
void cl_prot_mode_restore_default(struct cl_hw *cl_hw);
void cl_prot_mode_set(struct cl_hw *cl_hw, u8 prot_mode_new);
u8 cl_prot_mode_get(struct cl_hw *cl_hw);

#endif /* CL_PROT_MODE_H */
