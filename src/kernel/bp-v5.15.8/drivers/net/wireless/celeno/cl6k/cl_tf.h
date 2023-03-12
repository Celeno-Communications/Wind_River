/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TF_H
#define CL_TF_H

#include "cl_timer.h"
#include <linux/skbuff.h>

struct cl_hw;
struct cl_sta;
struct cli_params;
struct cl_rx_w2e_hdr;

#define CL_TF_AP_TX_PWR_MAX 60

#define CL_TF_RU_ALLOC_MAX 69

#define CL_TF_STA_MAX 1

#define TARGET_RSSI_MAX    -20
#define TARGET_RSSI_MIN    -110
#define TARGET_RSSI_FACTOR -TARGET_RSSI_MIN

#define TF_TIMER_PERIOD_MS 500

#define QOS_NULL_LEN 34

#define CL_TF_RU_ALLOC_MAX_TYPE_1 36
#define CL_TF_RU_ALLOC_MAX_TYPE_2 52
#define CL_TF_RU_ALLOC_MAX_TYPE_3 60
#define CL_TF_RU_ALLOC_MAX_TYPE_4 64
#define CL_TF_RU_ALLOC_MAX_TYPE_5 66
#define CL_TF_RU_ALLOC_MAX_TYPE_6 67
#define CL_TF_RU_ALLOC_MAX_TYPE_7 68

#define CL_TF_TYPE_STR(tf_type) \
	((tf_type) == CL_TF_BASIC_TRIGGER ? "BASIC TRIGGER" : \
	 ((tf_type) == CL_TF_BFRP ? "BFRP" : \
	   ((tf_type) == CL_TF_BSRP ? "BSRP" : "Invalid")))

#define CL_TF_GI_LTF_TO_GI(gi_ltf) \
	((gi_ltf) == HE_LTF_X4_GI_32 ? WRS_GI_LONG : \
	 ((gi_ltf) == HE_LTF_X2_GI_16 ? WRS_GI_SHORT : \
	   ((gi_ltf) == HE_LTF_X1_GI_16 ? WRS_GI_SHORT : WRS_GI_LONG)))

#define CL_TF_GI_TO_GI_LTF(gi) \
	((gi) == WRS_GI_LONG ? HE_LTF_X4_GI_32 : \
	 ((gi) == WRS_GI_SHORT ? HE_LTF_X2_GI_16 : \
	   ((gi) == WRS_GI_VSHORT ? HE_LTF_X2_GI_16 : HE_LTF_X4_GI_32)))

struct cl_tf_data_sta {
	u16 ul_length[CL_TF_STA_MAX];
	u8 ul_rssi_su;
	u8 ul_rssi_mu;
	u16 reserved;
};

/* RSSI values are duplicate per AC in-order to allow FW to use
 * a single DMA transction while fetching STA TF data
 */
struct cl_tf_data {
	struct cl_tf_data_sta tf_sta_data[AC_MAX][CL_MAX_NUM_STA];
};

struct cl_tf_info {
	struct cl_tf_data *data;
	dma_addr_t dma_addr;
};

/*
 * GI_LTF field for common info
 * 0 - 1x HE-LTF + 1.6 us GI
 * 1 - 2x HE-LTF + 1.6 us GI
 * 2 - 4x HE-LTF + 3.2 us GI
 */
enum cl_tf_gi_ltf {
	HE_LTF_X1_GI_16, /* Not supported */
	HE_LTF_X2_GI_16,
	HE_LTF_X4_GI_32,

	HE_LTF_MAX
};

enum cl_tf_type {
	CL_TF_BASIC_TRIGGER = 0,
	CL_TF_BFRP = 1,
	CL_TF_BSRP = 4,
};

enum cl_tf_rx_params {
	CL_TF_RX_PARAMS_MODE_USER,
	CL_TF_RX_PARAMS_MODE_STA
};

struct cl_tf_common_info {
	u8 tf_type;
	__le32 ul_length;
	u8 more_tf;
	u8 cs_req;
	u8 ul_bw;
	u8 ul_gi_ltf;
	u8 he_ltf_mode;
	u8 ldpc_extra_sym;
	u8 num_he_ltf_symbols;
	u8 pe_disambiguity;
};

struct cl_tf_user_info {
	u8 ru_alloc;
	bool ru_band;
	bool ul_fec;
	bool ul_dcm;
	u8 ul_mcs;
	u8 ul_nss;
	u8 rssi;
};

struct cl_tf_params {
	bool enable;
	u8 sta_cnt;
	u8 sta_idx[CL_TF_STA_MAX];
	u32 pkt_send_cnt;
	u32 pkt_rcv_cnt;
	struct cl_tf_common_info common_info;
	struct cl_tf_user_info user_info[CL_TF_STA_MAX];
	u8 rate_entry;
	struct cl_timer tf_timer;
};

void cl_tf_init(struct cl_hw *cl_hw);
void cl_tf_close(struct cl_hw *cl_hw);
void cl_tf_handle_response(struct cl_hw *cl_hw);
void cl_tf_handler(struct cl_hw *cl_hw, struct sk_buff *skb,
		   struct cl_sta *cl_sta, struct cl_rx_w2e_hdr *w2e_hdr);
int cl_tf_alloc(struct cl_hw *cl_hw);
void cl_tf_free(struct cl_hw *cl_hw);
int cl_tf_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_TF_H */
