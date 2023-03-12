/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_OMI_H
#define CL_OMI_H

#include "cl_hw.h"

struct cl_om_ctrl {
	union {
		struct {
			u32 rx_nss : 3,
			   chan_width : 2,
			   ul_mu_dis : 1,
			   tx_nsts : 3,
			   er_su_dis : 1,
			   dl_mu_mimo_resound : 1,
			   ul_mu_data_dis : 1;
		} __packed fields;
		u32 value;
	} u;
} __packed;

void cl_omi_parse_om_ctrl_frm(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			      struct ieee80211_a_control a_ctl);
int cl_omi_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_OMI_H */
