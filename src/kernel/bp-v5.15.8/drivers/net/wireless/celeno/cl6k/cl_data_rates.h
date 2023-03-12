/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_DATA_RATES_H
#define CL_DATA_RATES_H

#include "cl_wrs_db.h"
#include "def.h"

#define DATA_RATE_INVERSE_Q 15

struct cl_inverse_data_rate {
	u16 he[CHNL_BW_MAX][WRS_SS_MAX][WRS_MCS_MAX_HE][WRS_GI_MAX_HE];
	u16 ht_vht[CHNL_BW_MAX][WRS_SS_MAX][WRS_MCS_MAX_VHT][WRS_GI_MAX_VHT];
	u16 ofdm[WRS_MCS_MAX_OFDM];
	u16 cck[WRS_MCS_MAX_CCK];
};

extern struct cl_inverse_data_rate inverse_data_rate;

extern const u16 data_rate_he_x10[CHNL_BW_MAX][WRS_SS_MAX][WRS_MCS_MAX_HE][WRS_GI_MAX_HE];
extern const u16 data_rate_ht_vht_x10[CHNL_BW_MAX][WRS_SS_MAX][WRS_MCS_MAX_VHT][WRS_GI_MAX_VHT];
extern const u16 data_rate_ofdm_x10[];
extern const u16 data_rate_cck_x10[];

void cl_data_rates_inverse_build(void);
u16 cl_data_rates_get(u8 mode, u8 bw, u8 nss, u8 mcs, u8 gi);
u16 cl_data_rates_get_x10(u8 mode, u8 bw, u8 nss, u8 mcs, u8 gi);

#endif /* CL_DATA_RATES_H */
