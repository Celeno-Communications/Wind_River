/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_WRS_API_H
#define CL_WRS_API_H

#include "cl_hw.h"
#include "cl_vif.h"

/* Driver --> WRS */
void cl_wrs_api_init(struct cl_hw *cl_hw);
void cl_wrs_api_close(struct cl_hw *cl_hw);
void cl_wrs_api_sta_add(struct cl_hw *cl_hw, struct ieee80211_sta *sta);
void cl_wrs_api_sta_remove(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_wrs_api_bss_coexistence(struct cl_hw *cl_hw);
void cl_wrs_api_bss_set_bw(struct cl_hw *cl_hw, u8 bw);
void cl_wrs_api_bw_changed(struct cl_hw *cl_hw, struct ieee80211_sta *sta, u8 bw);
void cl_wrs_api_nss_changed(struct cl_hw *cl_hw, struct ieee80211_sta *sta, u8 nss);
void cl_wrs_api_he_minrate_changed(struct cl_sta *cl_sta, u8 he_minrate);
void cl_wrs_api_recovery(struct cl_hw *cl_hw);
void cl_wrs_api_beamforming_sync(struct cl_hw *cl_hw, struct cl_sta *cl_sta);
void cl_wrs_api_quick_down_check(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
				 struct cl_wrs_params *wrs_params);
void cl_wrs_api_rate_sync(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			  struct cl_wrs_params *wrs_params);
bool cl_wrs_api_up_mcs1(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			struct cl_wrs_params *wrs_params);
void cl_wrs_api_set_smps_mode(struct cl_hw *cl_hw, struct ieee80211_sta *sta, const u8 bw);
u16 cl_wrs_api_get_max_data_rate(struct cl_hw *cl_hw);
u16 cl_wrs_api_get_tx_sta_data_rate(struct cl_sta *cl_sta);
u16 cl_wrs_api_get_rate_from_params(struct cl_wrs_rate_params *rate_params);
int cl_wrs_api_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cli_params *cli_params);
void cl_wrs_api_set_omi_rate(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 bw, u8 nss);

#endif /* CL_WRS_API_H */
