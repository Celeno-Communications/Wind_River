/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_EDCA_H
#define CL_EDCA_H

#include "cl_vendor_cmd.h"
#include "def.h"

enum edca_ac {
	EDCA_AC_BE,
	EDCA_AC_BK,
	EDCA_AC_VI,
	EDCA_AC_VO,

	EDCA_AC_MAX
};

#define EDCA_AIFSN      0
#define EDCA_CW_MIN     1
#define EDCA_CW_MAX     2
#define EDCA_TXOP       3
#define EDCA_MAX_PARAMS 4

struct edca_params {
	u16 txop;
	u8 cw_max;
	u8 cw_min;
	u8 aifsn;
};

struct edca_dynamic {
	bool enable;
	bool set;
	bool high_rate;
	bool is_single_sta;
	u8 sta_idx;
	struct edca_params params;
};

struct cl_edca_db {
	struct edca_params hw_params[AC_MAX];
	struct edca_dynamic dyn_param;
};

struct cl_hw;
struct cl_sta;
struct ieee80211_he_mu_edca_param_ac_rec;

void cl_edca_hw_conf(struct cl_hw *cl_hw);
void cl_edca_set(struct cl_hw *cl_hw, u8 ac, struct edca_params *params,
		 struct ieee80211_he_mu_edca_param_ac_rec *mu_edca);
void cl_edca_restore_conf(struct cl_hw *cl_hw, u8 ac);
void cl_edca_recovery(struct cl_hw *cl_hw);
int cl_edca_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);
void cl_edca_dynamic_update_single_sta(struct cl_hw *cl_hw,
				       struct cl_sta *cl_sta,
				       bool is_single_sta);
void cl_edca_dynamic_update_sta_rate(struct cl_hw *cl_hw, struct cl_sta *cl_sta);

#endif /* CL_EDCA_H */
