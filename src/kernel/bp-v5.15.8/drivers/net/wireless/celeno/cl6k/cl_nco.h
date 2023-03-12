/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_NCO_H
#define CL_NCO_H

#include "cl_hw.h"
#include "cl_vendor_cmd.h"

int cl_nco_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_NCO_H */
