/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_POWER_CLI_H
#define CL_POWER_CLI_H

#include "cl_vendor_cmd.h"
#include "cl_hw.h"

int cl_power_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_POWER_CLI_H */
