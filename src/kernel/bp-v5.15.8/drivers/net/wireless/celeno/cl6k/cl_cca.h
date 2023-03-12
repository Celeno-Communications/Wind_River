/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CCA_H
#define CL_CCA_H

struct cl_hw;
struct cli_params;

enum cl_cca_opt {
	CCA_OPT_CNT_CS = 0x1,
	CCA_OPT_CNT_MDM_STATE = 0x2,
	CCA_OPT_CNT_MP = 0x4,
	CCA_OPT_CNT_ENERGY = 0x8,
	CCA_OPT_CNT_ENERGY_BAND = 0x10,
	CCA_OPT_UTIL = 0x20,
	CCA_OPT_TX_RX_MINE = 0x40,
	CCA_OPT_EDCA = 0x80,
	CCA_OPT_EDCA_NAV = 0x100,
	CCA_OPT_REC_HIST = 0x200
};

void cl_cca_maintenance(struct cl_hw *cl_hw);
int cl_cca_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_CCA_H */
