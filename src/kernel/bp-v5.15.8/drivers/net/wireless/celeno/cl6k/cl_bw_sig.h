/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_BW_SIG_H
#define CL_BW_SIG_H

#include "cl_hw.h"
#include "cl_vendor_cmd.h"

enum {
	CL_BW_SIG_DEBUG_BAR = 1,
	CL_BW_SIG_DEBUG_RTS,
	CL_BW_SIG_DEBUG_SOUNDING,
	CL_BW_SIG_DEBUG_PS_POLL,
	CL_BW_SIG_DEBUG_MAX
};

int cl_bw_sig_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cli_params *cli_params);

#endif /* CL_BW_SIG_H */
