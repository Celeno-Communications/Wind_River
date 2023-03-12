/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_BSRP_H
#define CL_BSRP_H

#include "cl_hw.h"

#ifdef CE_DUMMY_PHY
#define BSRP_BYTE_THRESHOLD_DEFAULT 1000000
#define BSRP_MAINTENANCE_PERIOD_MS  100000
#define BSRP_TIMEOUT_PERIOD_MS      80000
#else
#define BSRP_BYTE_THRESHOLD_DEFAULT 10000
#define BSRP_MAINTENANCE_PERIOD_MS  1000
#define BSRP_TIMEOUT_PERIOD_MS      800
#endif

enum cl_bsrp_scal_factor {
	SCAL_FACTOR_0,
	SCAL_FACTOR_1,
	SCAL_FACTOR_2,
	SCAL_FACTOR_3
};

enum cl_bsrp_qs_factor {
	QS_FACTOR_16 = 16,
	QS_FACTOR_256 = 256,
	QS_FACTOR_2048 = 2048,
	QS_FACTOR_32768 = 32768
};

#define BSRP_DBG(...) \
	do { \
		if (unlikely(cl_hw->bsrp_dbg)) \
			pr_debug(__VA_ARGS__); \
	} while (0)

void cl_bsrp_init(struct cl_hw *cl_hw);
void cl_bsrp_close(struct cl_hw *cl_hw);
void cl_bsrp_send_su(unsigned long data);
int cl_bsrp_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);
void cl_bsrp_parse_bsr(struct cl_hw *cl_hw, struct sk_buff *skb,
		       struct cl_sta *cl_sta, struct cl_rx_w2e_hdr *w2e_hdr);
void cl_bsrp_data_pending_dec(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			      struct sk_buff *skb,
			      struct cl_rx_w2e_hdr *w2e_hdr, u16 bytes);
void cl_bsrp_set_su_ul(struct cl_hw *cl_hw, struct cl_sta *cl_sta);

#endif /* CL_BSRP_H */
