/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_REG_CLI_H
#define CL_REG_CLI_H

#include "cl_hw.h"

enum cl_reg_type {
	GCU_REG,
	RIU_REG,
	RFIC_WRAP_REG
};

enum cl_bt_reg_type {
	BT_REG_CONTROLLER,
	BT_REG_MODEM,
};

int cl_reg_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_REG_CLI_H */
