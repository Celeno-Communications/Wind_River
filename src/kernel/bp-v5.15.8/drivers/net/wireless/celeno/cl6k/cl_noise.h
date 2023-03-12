/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_NOISE_H
#define CL_NOISE_H

struct cl_hw;
struct cli_params;

void cl_noise_init(struct cl_hw *cl_hw);
void cl_noise_close(struct cl_hw *cl_hw);
void cl_noise_maintenance(struct cl_hw *cl_hw);
int cl_noise_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_NOISE_H */
