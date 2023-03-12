/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CONFIG_H
#define CL_CONFIG_H

#include <linux/types.h>
#include <linux/kernel.h>
#include "config.h"
#include "cl_vendor_cmd.h"

extern char *cl_config_dir;
extern char *cl_install_dir;

struct cl_hw;

int cl_config_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_CONFIG_H */
