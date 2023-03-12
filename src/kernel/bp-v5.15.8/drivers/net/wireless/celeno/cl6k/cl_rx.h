/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RX_H
#define CL_RX_H

#include "cl_wrs_db.h"
#include "cl_hw.h"

/* Decryption status subfields */
enum cl_rx_hd_decr {
	CL_RX_HD_DECR_UNENC,
	CL_RX_HD_DECR_ICVFAIL,
	CL_RX_HD_DECR_CCMPFAIL,
	CL_RX_HD_DECR_AMSDUDISCARD,
	CL_RX_HD_DECR_NULLKEY,
	CL_RX_HD_DECR_WEPSUCCESS,
	CL_RX_HD_DECR_TKIPSUCCESS,
	CL_RX_HD_DECR_CCMPSUCCESS
};

#define CL_PADDING_IN_BYTES 2

struct phy_mean_snr_info {
	u32 mean_snr_info[WRS_SS_MAX];
};

struct cl_rx_w2e_hdr {
	__le16 frame_ctrl;
	__le16 seq_ctrl;
	__le16 qos_ctrl;
	/* Optional 0 to 10 bytes: HT_CTL(0/4) + PN/TSC(0/6) */
	u8 optional[];
};

struct hw_rxhdr {
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 msdu_cnt           : 8,   /* [7:0] */
	    corrupted_amsdu    : 1,   /* [8] */
	    reserved           : 1,   /* [9] */
	    msdu_dma_align     : 2,   /* [11:10] */
	    amsdu_error_code   : 4,   /* [15:12] */
	    w2e_done           : 1,   /* [16] */
	    w2e_padding        : 1,   /* [17] */
	    reserved_2         :14;   /* [31:18] */
#else
	u32 reserved_2         :14,   /* [13:0] */
	    w2e_padding        : 1,   /* [14] */
	    w2e_done           : 1,   /* [15] */
	    amsdu_error_code   : 4,   /* [19:16] */
	    msdu_dma_align     : 2,   /* [21:20] */
	    reserved           : 1,   /* [22] */
	    corrupted_amsdu    : 1,   /* [23] */
	    msdu_cnt           : 8;   /* [31:24] */
#endif
	/* Total length for the MPDU transfer */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 len                :14,   /* [13:0] */
	    ampdu_cnt          : 2,   /* [15:14] */
	    rx_padding_done    : 1,   /* [16] */
	    rx_class_rule_res  : 7,   /* [23:17] */
	/* AMPDU Status Information */
	    mpdu_cnt           : 8;   /* [31:24] */
#else
	u32 mpdu_cnt           : 8,  /* [7:0] */
	    rx_class_rule_res  : 7,  /* [14:8] */
	    rx_padding_done    : 1,  /* [15] */
	    ampdu_cnt          : 2,  /* [17:16] */
	    len                :14;  /* [31:18] */
#endif

	/* TSF Low */
	__le32 tsf_lo;
	/* TSF High */
	__le32 tsf_hi;

	/* Receive Vector 1a */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 leg_length         :12,   /* [11:0] */
	    leg_rate           : 4,   /* [15:12] */
	    ht_length_l        :16;   /* [31:16] */
#else
	u32 ht_length_l        :16,   /* [15:0] */
	    leg_rate           : 4,   /* [19:16] */
	    leg_length         :12;   /* [31:20] */
#endif

	/* Receive Vector 1b */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 ht_length_h        : 8,   /* [7:0] */
	    mcs                : 7,   /* [14:8] */
	    pre_type           : 1,   /* [15] */
	    format_mod         : 4,   /* [19:16] */
	    reserved_1b        : 1,   /* [20] */
	    n_sts              : 3,   /* [23:21] */
	    lsig_valid         : 1,   /* [24] */
	    sounding           : 1,   /* [25] */
	    num_extn_ss        : 2,   /* [27:26] */
	    aggregation        : 1,   /* [28] */
	    fec_coding         : 1,   /* [29] */
	    dyn_bw             : 1,   /* [30] */
	    doze_not_allowed   : 1;   /* [31] */
#else
	u32 doze_not_allowed   : 1,   /* [0] */
	    dyn_bw             : 1,   /* [1] */
	    fec_coding         : 1,   /* [2] */
	    aggregation        : 1,   /* [3] */
	    num_extn_ss        : 2,   /* [5:4] */
	    sounding           : 1,   /* [6] */
	    lsig_valid         : 1,   /* [7] */
	    n_sts              : 3,   /* [10:8] */
	    reserved_1b        : 1,   /* [11] */
	    format_mod         : 4,   /* [15:12] */
	    pre_type           : 1,   /* [16] */
	    mcs                : 7,   /* [23:17] */
	    ht_length_h        : 8;   /* [31:24] */
#endif

	/* Receive Vector 1c */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 sn                 : 4,  /* [3:0] */
	    warn_1c            : 1,  /* [4] */
	    stbc               : 2,  /* [6:5] */
	    smoothing          : 1,  /* [7] */
	    partial_aid        : 9,  /* [16:8] */
	    group_id           : 6,  /* [22:17] */
	    reserved_1c        : 1,  /* [23] */
	    rssi1              : 8;  /* [31:24] */
#else
	u32 rssi1              : 8,  /* [7:0] */
	    reserved_1c        : 1,  /* [8] */
	    group_id           : 6,  /* [14:9] */
	    partial_aid        : 9,  /* [23:15] */
	    smoothing          : 1,  /* [24] */
	    stbc               : 2,  /* [26:25] */
	    warn_1c            : 1,  /* [27] */
	    sn                 : 4;  /* [31:28] */
#endif

	/* Receive Vector 1d */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	s32 rssi2              : 8,  /* [7:0] */
	    rssi3              : 8,  /* [15:8] */
	    rssi4              : 8,  /* [23:16] */
	    rx_chains          : 8;  /* [31:24] */
#else
	s32 rx_chains          : 8,  /* [7:0] */
	    rssi4              : 8,  /* [15:8] */
	    rssi3              : 8,  /* [23:16] */
	    rssi2              : 8;  /* [31:24] */
#endif

	/* Receive Vector 1e */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 txop_duration      : 7,  /* [6:0] */
	    beam_change        : 1,  /* [7] */
	    mcs_sig_b          : 3,  /* [10:8] */
	    dcm                : 1,  /* [11] */
	    dcm_sig_b          : 1,  /* [12] */
	    beamformed         : 1,  /* [13] */
	    ltf_type           : 2,  /* [15:14] */
	    ru_band            : 1,  /* [16] */
	    ru_type            : 3,  /* [19:17] */
	    ru_index           : 6,  /* [25:20] */
	    pe_duration        : 3,  /* [28:26] */
	    ch_bw              : 2,  /* [30:29] */
	    reserved_1e        : 1;  /* [31] */
#else
	u32 reserved_1e        : 1,  /* [0] */
	    ch_bw              : 2,  /* [2:1] */
	    pe_duration        : 3,  /* [5:3] */
	    ru_index           : 6,  /* [11:6] */
	    ru_type            : 3,  /* [14:12] */
	    ru_band            : 1,  /* [15] */
	    ltf_type           : 2,  /* [17:16] */
	    beamformed         : 1,  /* [18] */
	    dcm_sig_b          : 1,  /* [19] */
	    dcm                : 1,  /* [20] */
	    mcs_sig_b          : 3,  /* [23:21] */
	    beam_change        : 1,  /* [24] */
	    txop_duration      : 7;  /* [31:25] */
#endif

	/* Receive Vector 1f */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 spatial_reuse      :16, /* [15:0] */
	    service            :16; /* [31:17] */
#else
	u32 service            :16, /* [15:0] */
	    spatial_reuse      :16; /* [31:16] */
#endif

	/* Receive Vector 1g */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 bss_color          : 6,  /* [5:0] */
	    gi_type            : 2,  /* [7:6] */
	    antenna_set        : 16, /* [23:8] */
	    rssi5              : 8;  /* [31:24] */
#else
	u32 rssi5              : 8,  /* [7:0] */
	    antenna_set        :16,  /* [23:8] */
	    gi_type            : 2,  /* [25:24] */
	    bss_color          : 6;  /* [31:26] */
#endif

	/* Receive Vector 1h */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	s32 rssi6              : 8,  /* [7:0] */
	    rssi7              : 8,  /* [15:8] */
	    rssi8              : 8,  /* [23:16] */
	    future_1           : 8;  /* [31:24] */
#else
	s32 future_1           : 8,  /* [7:0] */
	    rssi8              : 8,  /* [15:8] */
	    rssi7              : 8,  /* [23:16] */
	    rssi6              : 8;  /* [31:24] */
#endif

	/* Receive Vector 2a */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 rcpi               : 8,  /* [7:0] */
	    evm1               : 8,  /* [15:8] */
	    evm2               : 8,  /* [23:16] */
	    evm3               : 8;  /* [31:24] */
#else
	u32 evm3              : 8,  /* [7:0] */
	    evm2              : 8,  /* [15:8] */
	    evm1              : 8,  /* [23:16] */
	    rcpi              : 8;  /* [31:24] */
#endif

	/* Receive Vector 2b */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 evm4               : 8,  /* [7:0] */
	    warn_2b            : 1,  /* [8] */
	    reserved2b_1       : 7,  /* [15:9] */
	    reserved2b_2       : 8,  /* [23:16] */
	    reserved2b_3       : 8;  /* [31:24] */
#else
	u32 reserved2b_3       : 8,  /* [7:0] */
	    reserved2b_2       : 8,  /* [15:8] */
	    reserved2b_1       : 7,  /* [22:16] */
	    warn_2b            : 1,  /* [23] */
	    evm4               : 8;  /* [31:24] */
#endif

	/* Status **/
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 rx_vect2_valid     : 1,  /* [0] */
	    resp_frame         : 1,  /* [1] */
	    decr_status        : 3,  /* [4:2] */
	    rx_fifo_oflow      : 1,  /* [5] */
	    undef_err          : 1,  /* [6] */
	    phy_err            : 1,  /* [7] */
	    fcs_err            : 1,  /* [8] */
	    addr_mismatch      : 1,  /* [9] */
	    ga_frame           : 1,  /* [10] */
	    first_qos_data     : 1,  /* [11] */
	    amsdu_present      : 1,  /* [12] */
	    frm_successful_rx  : 1,  /* [13] */
	    desc_done_rx       : 1,  /* [14] */
	    desc_spare         : 1,  /* [15] */
	    key_sram_index     : 9,  /* [24:16] */
	    key_sram_v         : 1,  /* [25] */
	    type               : 2,  /* [27:26] */
	    subtype            : 4;  /* [31:28] */
#else
	u32 subtype            : 4,  /* [3:0] */
	    type               : 2,  /* [5:4] */
	    key_sram_v         : 1,  /* [6] */
	    key_sram_index     : 9,  /* [15:7] */
	    desc_spare         : 1,  /* [16] */
	    desc_done_rx       : 1,  /* [17] */
	    frm_successful_rx  : 1,  /* [18] */
	    amsdu_present      : 1,  /* [19] */
	    first_qos_data     : 1,  /* [20] */
	    ga_frame           : 1,  /* [21] */
	    addr_mismatch      : 1,  /* [22] */
	    fcs_err            : 1,  /* [23] */
	    phy_err            : 1,  /* [24] */
	    undef_err          : 1,  /* [25] */
	    rx_fifo_oflow      : 1,  /* [26] */
	    decr_status        : 3,  /* [29:27] */
	    resp_frame         : 1,  /* [30] */
	    rx_vect2_valid     : 1;  /* [31] */
#endif

	/* PHY channel information 1 */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 phy_band           : 8,  /* [7:0] */
	    phy_channel_type   : 8,  /* [15:8] */
	    phy_prim20_freq    :16;  /* [31:16] */
#else
	u32 phy_prim20_freq    :16,  /* [15:0] */
	    phy_channel_type   : 8,  /* [23:16] */
	    phy_band           : 8;  /* [31:24] */
#endif

	/* PHY channel information 2 */
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u32 phy_center1_freq   : 16, /* [15:0] */
	    phy_center2_freq   : 16; /* [31:16] */
#else
	u32 phy_center2_freq   : 16, /* [15:0] */
	    phy_center1_freq   : 16; /* [31:16] */
#endif
	/* Patten **/
	__le32 pattern;
};

void cl_rx_init(struct cl_hw *cl_hw);
void cl_rx_off(struct cl_hw *cl_hw);
void cl_rx_remote_tasklet_sched(void *t);
void cl_rx_remote_cpu_info(struct cl_hw *cl_hw);
void cl_rx_push_queue(struct cl_hw *cl_hw, struct sk_buff *skb);
void cl_rx_skb_alloc_handler(struct sk_buff *skb);
void cl_rx_skb_error(struct cl_hw *cl_hw);
void cl_rx_post_recovery(struct cl_hw *cl_hw);
void cl_rx_info_reset(struct cl_hw *cl_hw);
int cl_rx_info_print(struct cl_hw *cl_hw);
void cl_rx_netif(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct sk_buff *skb);
void cl_rx_finish(struct cl_hw *cl_hw, struct sk_buff *skb, struct ieee80211_sta *sta);
void cl_rx_strip_llc(struct cl_hw *cl_hw, struct sk_buff *skb);
void cl_rx_wlan_to_8023(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			struct sk_buff_head *skb_list);

#endif /* CL_RX_H */
