/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_AGG_TX_REPORT_H
#define CL_AGG_TX_REPORT_H

#include "cl_tx.h"

/* Structure containing the parameters of the MM_AGG_TX_REPORT_IND message. */
struct cl_agg_tx_report {
	__le32 rate_cntrl_info;
	__le32 rate_cntrl_info_he;
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 sta_idx                    : 8,
	    is_sta_ps                  : 1,
	    bw_requested               : 2,
	    is_agg                     : 1,
	    ba_not_received            : 1,
	    ba_received_empty          : 1,
	    bf                         : 1,
	    is_fallback                : 1,
	    mu_su_gid                  : 6,
	    mu_mimo_valid              : 1,
	    mu_ofdma_valid             : 1,
	    rate_fix_mcs1              : 1,
	    rsv0                       : 7;

	u32 success                    : 9,
	    fail                       : 9,
	    below_baw_cnt              : 9,
	    num_prot_retries           : 5;

	u32 success_after_retry        : 9,
	    success_more_one_retry     : 9,
	    retry_limit_reached        : 9,
	    is_retry                   : 1,
	    is_rts_retry_limit_reached : 1,
	    prot_type                  : 3;

	u32 rssi1                      : 8,
	    rssi2                      : 8,
	    rssi3                      : 8,
	    rssi4                      : 8;

	u32 rssi5                      : 8,
	    rssi6                      : 8,
	    rsv1                       : 16;
#else
	u32 rsv0                       : 7,
	    rate_fix_mcs1              : 1,
	    mu_ofdma_valid             : 1,
	    mu_mimo_valid              : 1,
	    mu_su_gid                  : 6,
	    is_fallback                : 1,
	    bf                         : 1,
	    ba_received_empty          : 1,
	    ba_not_received            : 1,
	    is_agg                     : 1,
	    bw_requested               : 2,
	    is_sta_ps                  : 1,
	    sta_idx                    : 8;

	u32 num_prot_retries           : 5,
	    below_baw_cnt              : 9,
	    fail                       : 9,
	    success                    : 9;

	u32 prot_type                  : 3,
	    is_rts_retry_limit_reached : 1,
	    is_retry                   : 1,
	    retry_limit_reached        : 9,
	    success_more_one_retry     : 9,
	    success_after_retry        : 9;

	u32 rssi4                      : 8,
	    rssi3                      : 8,
	    rssi2                      : 8,
	    rssi1                      : 8;

	u32 rsv1                       : 16,
	    rssi6                      : 8,
	    rssi5                      : 8;
#endif
	__le16 new_ssn;
	u8 queue_idx;
};

void cl_agg_tx_report_handler(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			      struct cl_agg_tx_report *agg_report);
void cl_agg_tx_report_simulate_for_single(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
					  struct cl_hw_tx_status *status);

#endif /* CL_AGG_TX_REPORT_H */
