/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_WRS_CLI_H
#define CL_WRS_CLI_H

#include "cl_wrs_db.h"
#include "cl_hw.h"

int cl_wrs_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cli_params *cli_params);

#endif /* CL_WRS_CLI_H */
