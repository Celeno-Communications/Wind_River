/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_IPC_SHARED_H
#define CL_IPC_SHARED_H

#include "def.h"
#include "ipc_shared.h"
#include <net/mac80211.h>
#include "cl_math.h"

/*
 * Number of Host buffers available for Data Rx handling (through DMA)
 * Must correspond to FW code definition, and must be power of 2.
 */
#define IPC_RXBUF_CNT_RXM 512
#define IPC_RXBUF_CNT_FW  128

#if !IS_POWER2(IPC_RXBUF_CNT_RXM)
#error "IPC_RXBUF_CNT_RXM not power of 2"
#endif

#if !IS_POWER2(IPC_RXBUF_CNT_FW)
#error "IPC_RXBUF_CNT_FW not power of 2"
#endif

/* Bucket debug */
#define IPC_RXBUF_BUCKET_POW_SIZE 5
#define IPC_RXBUF_BUCKET_SIZE     BIT(IPC_RXBUF_BUCKET_POW_SIZE) /* 2 ^ 5 = 32 */
#define IPC_RXBUF_NUM_BUCKETS_RXM (IPC_RXBUF_CNT_RXM / IPC_RXBUF_BUCKET_SIZE)
#define IPC_RXBUF_NUM_BUCKETS_FW  (IPC_RXBUF_CNT_FW / IPC_RXBUF_BUCKET_SIZE)

#define MU_MAX_STREAMS     1

#define POLICY_TABLE_MU_USERS     8

#define IPC_TX_QUEUE_CNT 5

#define IPC_TX_QUEUE_IDX_TO_COMMON_QUEUE_IDX(idx) ((idx) * 2)

#define IPC_RX_QUEUE_IDX_TO_COMMON_QUEUE_IDX(idx) (((idx) * 2) + 1)

#define CL_MAX_BA_PHYSICAL_QUEUE_CNT (AC_MAX)

#define CE_AC_MAX (IPC_TX_QUEUE_CNT)

enum {
	AGG_AC0_IDX = AC_BK,
	AGG_AC1_IDX = AC_BE,
	AGG_AC2_IDX = AC_VI,
	AGG_AC3_IDX = AC_VO,
	AGG_IDX_MAX,
};

#define DBG_DUMP_BUFFER_SIZE (1024 * 40)

#define IPC_TXDESC_CNT_SINGLE 16
#define IPC_TXDESC_CNT_BCMC   16

/* Max count of Tx MSDU in A-MSDU */
#define CL_AMSDU_TX_PAYLOAD_MAX 3

/* Max count of packet_addr & packet_len at txdesc */
#define CL_TXDESC_AMSDU_MAX 3

#define TXDESC_AGG_Q_SIZE_MAX 512
#define TXDESC_AGG_Q_SIZE_USB 256

#define CL_MAX_AGG_IN_TXOP 20

/* Keep LMAC & SMAC debug agg stats arrays size aligned */
#define DBG_STATS_MAX_AGG_SIZE (64 + 1)

/* USB retry list info */
#define DBG_USB_TX_CNT 2

/* Must be power of 2 */
#define IPC_CFM_CNT 4096

#define IPC_CFM_SIZE (IPC_CFM_CNT * sizeof(struct cl_ipc_cfm_msg))

/* Number of rates in Policy table */
#define CL_RATE_CONTROL_STEPS 4

#if (IPC_CFM_CNT & (IPC_CFM_CNT - 1))
#error "IPC_CFM_CNT Not a power of 2"
#endif

/* Pattern indication for validity */
#define IPC_RX_DMA_OVER_PATTERN   0xAAAAAA00
#define IPC_E2A_MSG_VALID_PATTERN 0xADDEDE2A
#define IPC_DBG_VALID_PATTERN     0x000CACA0
#define IPC_EXCEPTION_PATTERN     0xDEADDEAD

/* Tensilica backtrace depth */
#define IPC_BACKTRACT_DEPTH  5

/* Maximum length of the SW diag trace */
#define DBG_SW_DIAG_MAX_LEN  1024

/* Maximum length of the error trace */
#define DBG_ERROR_TRACE_SIZE 256

/* Number of MAC diagnostic port banks */
#define DBG_DIAGS_MAC_MAX    48

/* Number of PHY diagnostic port banks */
#define DBG_DIAGS_PHY_MAX    32

/* Maximum size of the RX header descriptor information in the debug dump */
#define DBG_RHD_MEM_LEN      (5 * 1024)

/* Maximum size of the RX buffer descriptor information in the debug dump */
#define DBG_RBD_MEM_LEN      (5 * 1024)

/* Maximum size of the TX header descriptor information in the debug dump */
#define DBG_THD_MEM_LEN      (10 * 1024)

/* Driver mem size used for THDs PTs & PBDs */
#define DBG_THD_CHAINS_INFO_THD_CNT 5
#define DBG_THD_CHAINS_INFO_PBD_CNT 9
#define DBG_THD_CHAINS_INFO_PT_CNT  1
#define DBG_THD_CHAINS_INFO_ARRAY_SIZE \
	((DBG_THD_CHAINS_INFO_THD_CNT * sizeof(struct tx_hd)) + \
	 (DBG_THD_CHAINS_INFO_PBD_CNT * sizeof(struct tx_pbd)) + \
	 (DBG_THD_CHAINS_INFO_PT_CNT * sizeof(struct tx_policy_tbl)))

#define DBG_CHAINS_INFO_ELEM_CNT 10

enum DBG_CHAINS_INFO_ELEMENTS {
	DBG_CHAINS_INFO_EMPTY,
	DBG_CHAINS_INFO_THD,
	DBG_CHAINS_INFO_PBD,
	DBG_CHAINS_INFO_PT,
	DBG_CHAINS_INFO_MAX
};

/* Txl chain info - per ac */
#define DBG_TXL_FRAME_EXCH_TRACE_DEPTH 5

/* FW debug trace size */
#define DBG_FW_TRACE_SIZE    30
#define DBG_FW_TRACE_STR_MAX 20

/* Number of embedded logic analyzers */
#define LA_CNT               1
#define CL_USB_READ_REQ_DATA_SIZE 5
#define CL_USB_AGG_PKT_REQ_BITMAP_SIZE 8

/* Structure containing the configuration data of a logic analyzer */
struct la_conf_tag {
	u8 conf[LA_CONF_LEN];
};

/* Size of a logic analyzer memory */
#define LA_MEM_LEN (128 * 1024)

struct cl_rx_msg {
	struct list_head list;
	struct cl_ipc_e2a_msg buf;
};

struct cl_dbg_msg {
	struct list_head list;
	u8 string[IPC_DBG_PARAM_SIZE];
};

struct cl_usb_single_pkt_req_msg {
#ifdef __LITTLE_ENDIAN_BITFIELD
	u32 single_queue_idx : 12, // [11:0]
	    num_packets      : 4,  // [15:12]
	    ep_idx           : 4,  // [19:16]
	    is_bcmc          : 1,  // [20]
	    rsv              : 11; // [31:21]
#else /* __BIG_ENDIAN_BITFIELD */
	u32 rsv              : 11, // [10:0]
	    is_bcmc          : 1,  // [11]
	    ep_idx           : 4,  // [15:12]
	    num_packets      : 4,  // [19:16]
	    single_queue_idx : 12; // [31:20]
#endif
	__le32 first_txdesc_packet_addr;
};

struct cl_single_pkt_req_msg {
	struct list_head list;
	struct cl_usb_single_pkt_req_msg msg;
};

struct cl_usb_agg_pkt_req_msg {
#ifdef __LITTLE_ENDIAN_BITFIELD
	u32 start_sn    : 12, // [11:0]
	    session_idx : 8,  // [19:12]
	    ep_idx      : 4,  // [23:20]
	    txdesc_cnt  : 7,  // [30:24]
	    rsv         : 1;  // [31]
#else /* __BIG_ENDIAN_BITFIELD */
	u32 rsv         : 1,  // [0]
	    txdesc_cnt  : 7,  // [7:1]
	    ep_idx      : 4,  // [11:8]
	    session_idx : 8,  // [19:12]
	    start_sn    : 12; // [31:20]
#endif
	__le16 msdu_cnt;
	__le32 bitmap[CL_USB_AGG_PKT_REQ_BITMAP_SIZE];
};

struct cl_agg_pkt_req_msg {
	struct list_head list;
	struct cl_usb_agg_pkt_req_msg msg;
};

/*
 * Structs & function  associated with HW & SW debug data
 * The Debug information forwarded to host when an error occurs, and printed to stdout
 * This data must be consistent with firmware, any new debug data should exist also in
 * firmware side
 */

struct tx_hd {
	u32 upatterntx;
	u32 nextfrmexseq_ptr;
	u32 nextmpdudesc_ptr;
	u32 first_pbd_ptr;
	u32 datastartptr;
	u32 dataendptr;
	u32 frmlen;
	u32 spacinginfo;
	u32 phyctrlinfo1;
	u32 policyentryaddr;
	u32 bar_thd_desc_ptr;
	u32 reserved1;
	u32 macctrlinfo1;
	u32 macctrlinfo2;
	u32 statinfo;
	u32 phyctrlinfo2;
};

struct tx_policy_tbl {
	u32 upatterntx;
	u32 phycntrlinfo1;
	u32 phycntrlinfo2;
	u32 maccntrlinfo1;
	u32 maccntrlinfo2;
	u32 ratecntrlinfo[CL_RATE_CONTROL_STEPS];
	u32 phycntrlinfo3;
	u32 phycntrlinfo4;
	u32 phycntrlinfo5;
	u32 stationinfo;
	u32 ratecntrlinfohe[CL_RATE_CONTROL_STEPS];
	u32 maccntrlinfo3;
	u32 triggercommoninfo;
	u32 triggerinforuallocationu0u3;
	u32 triggerinforuallocationu4u7;
	u32 triggerperuserinfo[POLICY_TABLE_MU_USERS];
};

struct tx_pbd {
	u32 upatterntx;
	u32 next;
	u32 datastartptr;
	u32 dataendptr;
	u32 bufctrlinfo;
};

enum cl_macfw_dbg_severity {
	CL_MACFW_DBG_SEV_NONE,
	CL_MACFW_DBG_SEV_ERROR,
	CL_MACFW_DBG_SEV_WARNING,
	CL_MACFW_DBG_SEV_INFO,
	CL_MACFW_DBG_SEV_VERBOSE,

	CL_MACFW_DBG_SEV_MAX
};

struct phy_channel_info {
	u32 info1;
	u32 info2;
};

struct dbg_debug_info_tag {
	u32 error_type; /* (0: recoverable, 1: fatal) */
	u32 hw_diag;
	char error[DBG_ERROR_TRACE_SIZE];
	u32 sw_diag_len;
	char sw_diag[DBG_SW_DIAG_MAX_LEN];
	struct phy_channel_info chan_info;
	struct la_conf_tag la_conf[LA_CNT];
	u16 diags_mac[DBG_DIAGS_MAC_MAX];
};

/*
 * Defines, enums and structs below are used at TX statistics
 * structure.
 * Because of the TX statistics structure should be same at
 * host and at firmware,the change of these parameters requires
 * similar firmware changes
 */

struct cl_txl_ba_statistics {
	u32 total_cnt;
	u32 total_rtx_cnt;
	u16 total_ba_received;
	u16 total_ba_not_received_cnt;
	u16 total_lifetime_expired_cnt;
	u16 total_rtx_limit_reached;
	u16 total_packets_below_baw;
	u16 total_packets_above_baw;
	u16 total_ba_not_received_cnt_ps;
	u16 total_cleard_ba;
	u16 total_unexpected_ba;
	u16 total_invalid_ba;
	u16 total_ack_instead_ba;
};

struct cl_txl_single_statistics {
	u32 total_cnt;
	u32 total_rtx_cnt;
	u16 total_lifetime_expired_cnt;
	u16 total_rtx_limit_reached;
	u16 total_rtx_limit_reached_ps;
};

enum {
	CE_BACKOFF_25,
	CE_BACKOFF_50,
	CE_BACKOFF_100,
	CE_BACKOFF_500,
	CE_BACKOFF_1000,
	CE_BACKOFF_5000,
	CE_BACKOFF_10000,
	CE_BACKOFF_20000,
	CE_BACKOFF_20000_ABOVE,
	CE_BACKOFF_MAX
};

struct cl_txl_backoff_statistics {
	u32 chain_time;
	u32 backoff_hist[CE_BACKOFF_MAX];
};

struct cl_txl_tid_statistics {
	u32 total_tid_desc_cnt;
};

/* Natt closed an aggregation due to one of the bellow reasons. */
enum {
	NATT_REASON_MAX_LEN    = 0x1,
	NATT_REASON_TXOP_LIMIT = 0x2,
	NATT_REASON_MPDU_NUM   = 0x4,
	NATT_REASON_LAST_BIT   = 0x8,
	NATT_REASON_MAX
};

/* Tx BW */
enum {
	NATT_BW_20,
	NATT_BW_40,
	NATT_BW_80,
	NATT_BW_160,
	NATT_BW_MAX
};

struct cl_txl_natt_statistics {
	u32 agg_close_reason[NATT_REASON_MAX];
	u32 chosen_frame_bw[NATT_BW_MAX];
	u32 operation_mode[8];
};

enum {
	AGG_IN_TXOP_CLOSE_REASON_NO_TXDESC,
	AGG_IN_TXOP_CLOSE_REASON_TXOP_EXPIRED,
	AGG_IN_TXOP_CLOSE_REASON_ACTIVE_DELBA,
	AGG_IN_TXOP_CLOSE_REASON_MAX
};

struct amsdu_stat {
	u16 packet_cnt_2;
	u16 packet_cnt_3;
	u16 packet_cnt_4;
	u16 packet_cnt_5_or_more;
};

struct cl_txl_mu_statistics {
	u16 chain_cnt;
	u16 status_cnt;
	u16 ba_received;
	u16 ba_no_received;
	u16 clear_ba;
	u16 correct_ba;
	u16 unexpected_ba;
	u16 invalid_ba;
};

struct cl_txl_agg_statistics {
	u16 agg_size_statistics[DBG_STATS_MAX_AGG_SIZE];
	u32 packet_failed_statistics[DBG_STATS_MAX_AGG_SIZE];
	u32 packet_passed_statistics[DBG_STATS_MAX_AGG_SIZE];
	u16 htp_agg_size_statistics[DBG_STATS_MAX_AGG_SIZE];
	u32 htp_packet_failed_statistics[DBG_STATS_MAX_AGG_SIZE];
	u32 htp_packet_passed_statistics[DBG_STATS_MAX_AGG_SIZE];
	u16 agg_in_txop_statistics[CL_MAX_AGG_IN_TXOP];
	u16 agg_in_txop_close_reason[AGG_IN_TXOP_CLOSE_REASON_MAX];
	u16 agg_in_txop_queue_switch;
	u16 agg_in_txop_queue_switch_abort_bw;
	struct amsdu_stat amsdu_stat[IPC_MAX_BA_SESSIONS];
	u16 mu_agg_size_statistics[MU_MAX_STREAMS][DBG_STATS_MAX_AGG_SIZE];
	struct cl_txl_mu_statistics mu_stats[MU_MAX_STREAMS];
};

struct cl_txl_ac_statistics {
	u32 total_q_switch_cnt;
	u32 total_ac_desc_cnt;
};

struct cl_txl_underrun_statistics {
	u16 length_cnt;
	u16 pattern_cnt;
	u16 flushed_frames_cnt;
};

struct cl_txl_rts_cts_statistics {
	u32 fw_rts_cnt;
	u32 hw_rts_cnt;
	u32 fw_cts_cnt;
	u32 hw_cts_cnt;
};

struct cl_txl_backoff_params {
	u32 singelton_total[AC_MAX];
	u32 singelton_cnt[AC_MAX];
	u32 agg_total[AC_MAX];
	u32 agg_cnt[AC_MAX];
};

struct cl_txl_htp_statistics {
	u32 total_cnt[TID_MAX];
	u32 need_response;
	u32 tb_response_required;
	u32 ac_not_found;
	u32 end_of_packet_int;
	u32 tb_bw_decision;
	u32 tb_ba_thd_removed;
	u32 tb_ac_unchain;
	u32 tb_htp_unchain;
	u32 tb_dummy_htp_tx;
	u32 tb_dummy_no_tx;
	u32 msta_ba_received;
	u32 msta_ba_aid_not_found;
#ifdef PRESILICON_TESTING
	u32 uora_cnt_trigger_frame_tx;
	u32 uora_cnt_trigger_frame_rx;
	u32 uora_cnt_probe_req_tx;
	u32 uora_cnt_probe_req_rx;
#endif
};

struct cl_txl_vns_statistics {
	u32 off_he;
	u32 off_ht_vht;
	u32 off_ofdm;
	u32 off_cck;
	u32 on_he;
	u32 on_ht_vht;
	u32 on_ofdm;
	u32 on_cck;
};

struct cl_txl_fec_statistics {
	u32 ldpc;
	u32 bcc;
};

struct cl_txl_mu_desision_statistics {
	u32 num_sta_in_mu_group[MU_MAX_STREAMS];
	u32 mu_tx_active;
	u32 prim_not_in_mu_group;
	u32 prim_rate_invalid;
	u32 other_reason;
	u32 total_num_su;
	u32 is_2nd_rate_invalid;
	u32 is_2nd_awake;
	u32 is_2nd_enouhg_data;
};

struct cl_txl_statistics {
	u32 type; /* This field should be first in the struct */
	u32 recovery_count;
	u32 tx_obtain_bw_fail_cnt;
	struct cl_txl_single_statistics single[IPC_TX_QUEUE_CNT];
	struct cl_txl_ba_statistics ba[IPC_MAX_BA_SESSIONS];
	struct cl_txl_backoff_statistics backoff_stats[AC_MAX];
	struct cl_txl_natt_statistics natt;
	struct cl_txl_tid_statistics tid[TID_MAX];
	struct cl_txl_agg_statistics agg;
	struct cl_txl_ac_statistics ac[CE_AC_MAX];
	struct cl_txl_underrun_statistics underrun;
	struct cl_txl_rts_cts_statistics rts_cts;
	struct cl_txl_backoff_params backoff_params;
	struct cl_txl_htp_statistics htp;
	struct cl_txl_vns_statistics vns;
	struct cl_txl_fec_statistics fec;
	struct cl_txl_mu_desision_statistics mu_desision;
};

/* Flushed beacon list options */
enum {
	BCN_FLUSH_PENDING,
	BCN_FLUSH_DOWNLOADING,
	BCN_FLUSH_TRANSMITTING,
	BCN_FLUSH_MAX,
};

struct bcn_backup_stats {
	u32 bcn_backup_used_cnt;
	u32 bcn_backup_tx_cnt;
	u32 bcn_backup_flushed_cnt;
	u32 bcn_backup_used_in_arow_cnt;
	u32 bcn_backup_max_used_in_arow_cnt;
};

struct beacon_timing {
	/* Time measurements between beacons */
	u32 last_bcn_start_time;
	u32 max_time_from_last_bcn;
	u32 min_time_from_last_bcn;
	u32 total_bcn_time;
	/* Time measurements until beacon chained */
	u32 imp_tbtt_start_time;
	u32 bcn_chain_total_time;
	u32 bcn_chain_max_time;
	u32 bcn_chain_min_time;
	/* Time measurements until received beacon from host */
	u32 bcn_last_request_time;
	u32 max_bcn_time_until_get_beacon_from_driver_in_tbtt;
	u32 bcn_last_req_rec_time;
	/* Time measurements of bcn from pending to chain */
	u32 bcn_push_pending_start_time;
	u32 bcn_pending_2_chain_max_time;
};

struct beacon_counters {
	u32 bcn_time_from_driver_not_in_threshold_cnt;
	u32 nof_time_intervals_between_beacons;
	u32 total_cnt;
	u32 bcn_chain_total_cnt;
	u32 ce_txl_flushed_beacons[BCN_FLUSH_MAX];
	u32 pending2chain_not_in_threshold_cnt;
	u16 total_bcn_req_without_rec_from_host;
	u16 max_bcn_not_received_from_host;
	u32 total_beacons_received_from_host;
};

struct cl_bcn_statistics {
	u32 type; /* This field should be first in the struct */
	struct beacon_counters beacon_counters;
	struct beacon_timing beacon_timing;
	struct bcn_backup_stats bcn_backup_stats;
};

enum agg_tx_rate_drop_reason {
	AGG_TX_RATE_DROP_MAX_BA_NOT_RECEIVED_REACHED,
	AGG_TX_RATE_DROP_MAX_BA_PER_REACHED,
	AGG_TX_RATE_DROP_MAX_RETRY_REACHED,
	AGG_TX_RATE_DROP_MAX,
};

struct cl_rate_drop_statistics {
	u32 type;
	u32 drop_reason[AGG_TX_RATE_DROP_MAX];
};

#define BF_DB_MAX 16

enum bfr_rx_err {
	BFR_RX_ERR_BW_MISMATCH,
	BFR_RX_ERR_NSS_MISMATCH,
	BFR_RX_ERR_SOUNDING_CHBW,
	BFR_RX_ERR_TOKEN_MISMATCH,
	BFR_RX_ERR_NDP_DROP,
	BFR_SEGMENTED_DROP,
	BFR_RX_ERR_MISS_ACK,
	BFR_RX_ERR_RESOURCE_NA,
	BFR_RX_ERR_MAX
};

enum TX_BF_DATA_STAT {
	TX_BF_DATA_OK = 0,
	TX_BF_DATA_BUFFERED_RESOURCE_ERR,
	TX_BF_DATA_RELEASED_RESOURCE_ERR,
	TX_BF_DATA_BUFFERED_PS_STA,
	TX_BF_DATA_RELEASED_PS_STA,
	TX_BF_DATA_ERR_BFR_MISS,
	TX_BF_DATA_ERR_BFR_OUTDATED,
	TX_BF_DATA_ERR_MISMATCH_BW,
	TX_BF_DATA_ERR_MISMATCH_NSS,
	TX_BF_DATA_ERR_MAX
};

struct bf_ctrl_dbg {
	u16 ndp_cnt;
	u16 bfp_cnt;
	u16 su_bfr_cnt;
	u16 mu_bfr_cnt;
	u16 bf_invalid_cnt[BFR_RX_ERR_MAX];
	u16 tx_bf_data_err[TX_BF_DATA_ERR_MAX];
};

struct bf_stats_database {
	bool is_active_list;
	struct bf_ctrl_dbg dbg;
	u8 sta_idx;
	u16 active_dsp_idx;
	u16 passive_dsp_idx;
};

struct cl_bf_statistics {
	u32 type;
	bool print_active_free_list;
	struct bf_stats_database stats_data[BF_DB_MAX];
};

#define RX_MAX_CLASSIFICATION   6

enum amsdu_deaggregation_err {
	AMSDU_DEAGGREGATION_ERR_MAX_MSDU_REACH,
	AMSDU_DEAGGREGATION_ERR_MSDU_GT_AMSDU_LEN,
	AMSDU_DEAGGREGATION_ERR_MSDU_LEN,
	AMSDU_ENCRYPTION_KEY_GET_ERR,

	AMSDU_DEAGGREGATION_ERR_MAX
};

enum emb_ll1_handled_frm_type {
	BA_FRM_TYPE,
	NDPA_FRM_TYPE,
	NDP_FRM_TYPE,
	ACTION_NO_ACK_FRM_TYPE,

	MAX_HANDLED_FRM_TYPE
};

enum rhd_decr_idx {
	RHD_DECR_UNENC_IDX,
	RHD_DECR_ICVFAIL_IDX,
	RHD_DECR_CCMPFAIL_IDX,
	RHD_DECR_AMSDUDISCARD_IDX,
	RHD_DECR_NULLKEY_IDX,
	RHD_DECR_IDX_MAX
};

#define MAX_NUM_OF_FORMATS 9

#define MAX_NUM_OF_SIMULTANEUS_UL_STREAMS 1

#define CL_RX_CLASSIFICATION_MAX 6
#define FREQ_OFFSET_TABLE_MAX_IDX 8 /* Must be a power of 2 */

struct cl_rxl_statistics {
	u32 type; /* This field should be first in the struct */
	u32 rx_imp_bf_counter[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rx_imp_bf_int_counter[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rx_class_counter[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS][CL_RX_CLASSIFICATION_MAX];
	u32 rx_class_int_counter[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 counter_timer_trigger_ll1[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 counter_timer_trigger_ll2[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 total_rx_packets[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 total_agg_packets[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rx_fifo_overflow_err_cnt[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rx_dma_discard_cnt;
	u32 host_rxelem_not_ready_cnt;
	u32 msdu_host_rxelem_not_ready_cnt;
	u32 dma_rx_pool_not_ready_cnt;
	u32 rx_pckt_exceed_max_len_cnt[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rx_pckt_bad_ba_statinfo_cnt[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 nav_value[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u16 max_mpdu_data_len[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u8 rhd_ll2_max_cnt[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS]; /* Rhd first list */
	u8 rhd_ll1_max_cnt[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS]; /* Rhd second list */
	u8 cca_busy_percent;
	u8 rx_mine_busy_percent;
	u8 tx_mine_busy_percent;
	u8 sample_cnt;
	/* Emb handled frames */
	u32 emb_ll1_handled_frame_counter[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS][MAX_HANDLED_FRM_TYPE];
	u32 rxm_stats_overflow[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	/* RX AMSDU statistics counters */
	u32 stats_tot_rx_amsdu_cnt[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 stats_rx_amsdu_cnt[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS][RX_MAX_MSDU_IN_AMSDU];
	u32 stats_rx_amsdu_err[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS][AMSDU_DEAGGREGATION_ERR_MAX];
	u32 stats_rx_format[MAX_NUM_OF_FORMATS];
	/* RX decryption error */
	u32 decrypt_err[RHD_DECR_IDX_MAX];
	u32 rx_incorrect_format_mode[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 fcs_error_counter[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 phy_error_counter[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 ampdu_received_counter[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 delimiter_error_counter[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 ampdu_incorrect_received_counter[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 correct_received_mpdu[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 incorrect_received_mpdu[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 discarded_mpdu[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 incorrect_delimiter[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_mpdu_cnt[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_rule0_match[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_rule1_match[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_rule2_match[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_rule3_match[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_rule4_match[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_rule5_match[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_rule6_match[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_default_rule_match[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_amsdu_1[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_amsdu_2[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_amsdu_3[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_amsdu_4[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_amsdu_5_15[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 rxm_amsdu_16_or_more[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
	u32 frequency_offset[FREQ_OFFSET_TABLE_MAX_IDX];
	u32 frequency_offset_idx;
	u32 rts_bar_cnt[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
};

enum trigger_flow_single_trigger_type {
	TRIGGER_FLOW_BASIC_TRIGGER_TYPE,
	TRIGGER_FLOW_BSRP_TYPE,
	TRIGGER_FLOW_BFRP_TYPE,
	TRIGGER_FLOW_MAX
};

struct cl_trigger_flow_statistics {
	u32 type; /* This field should be first in the struct */
	u32 single_trigger_sent[TRIGGER_FLOW_MAX][AC_MAX];
	u32 htp_rx_failure[AC_MAX];
	u32 trigger_based_mpdu[MAX_NUM_OF_SIMULTANEUS_UL_STREAMS];
};

struct cl_pta_statistics {
	u32 type; /* This field should be first in the struct */

	__le32 wifi_rx_20_m_pkt;
	__le32 wifi_rx_20_m_wait;
	__le32 wifi_rx_20_m_air;
	__le32 wifi_tx_20_m_pkt;
	__le32 wifi_tx_20_m_wait;
	__le32 wifi_tx_20_m_air;
	__le32 wifi_rx_40_m_pkt;
	__le32 wifi_rx_40_m_wait;
	__le32 wifi_rx_40_m_air;
	__le32 wifi_tx_40_m_pkt;
	__le32 wifi_tx_40_m_wait;
	__le32 wifi_tx_40_m_air;
	__le32 wifi_rx_80_m_pkt;
	__le32 wifi_rx_80_m_wait;
	__le32 wifi_rx_80_m_air;
	__le32 wifi_tx_80_m_pkt;
	__le32 wifi_tx_80_m_wait;
	__le32 wifi_tx_80_m_air;
	__le32 wifi_rx_160_m_pkt;
	__le32 wifi_rx_160_m_wait;
	__le32 wifi_rx_160_m_air;
	__le32 wifi_tx_160_m_pkt;
	__le32 wifi_tx_160_m_wait;
	__le32 wifi_tx_160_m_air;
	__le32 edr_rx_pkt;
	__le32 edr_rx_wait;
	__le32 edr_rx_air;
	__le32 edr_tx_pkt;
	__le32 edr_tx_wait;
	__le32 edr_tx_air;
	__le32 ble_rx_pkt;
	__le32 ble_rx_wait;
	__le32 ble_rx_air;
	__le32 ble_tx_pkt;
	__le32 ble_tx_wait;
	__le32 ble_tx_air;
	__le32 ext_1_pkt;
	__le32 ext_1_wait;
	__le32 ext_1_air;
	__le32 ext_1_dummy;
	__le32 ext_2_pkt;
	__le32 ext_2_wait;
	__le32 ext_2_air;
	__le32 ext_2_dummy;
	__le32 img_pkt;
	__le32 img_wait;
	__le32 img_air;
	__le32 img_2_dummy;
	__le32 wifi_rx_dev_rx_collision;
	__le32 wifi_rx_dev_tx_collision;
	__le32 wifi_tx_dev_rx_collision;
	__le32 wifi_tx_dev_tx_collision;
	__le32 dev_1_rx_dev_2_rx_collision;
	__le32 dev_1_rx_dev_2_tx_collision;
	__le32 dev_1_tx_dev_2_rx_collision;
	__le32 dev_1_tx_dev_2_tx_collision;
	__le32 dev_1_dev_2_collision_sel_dev_1;
	__le32 dev_1_dev_2_collision_sel_dev_2;
};

#define DYN_CAL_DEBUG_NUM_ITER  3

struct dyn_cal_debug_info_t {
	u16 calib_num;
	u8 curr_config;
	union {
		struct {
			u8 iter_num;
			u32 measured_val;
		};
		struct {
			u8 min_config;
			u32 dyn_cal_min_val;
			u32 dyn_cal_max_val;
			u8 max_config;
		};
	};

	u8 new_config;
};

struct cl_dyn_calib_statistics {
	u32 type; /* This field should be first in the struct */
	u8 is_multi_client_mode;
	u8 default_dyn_cal_val;
	u8 dyn_cal_debug_info_ix;
	u16 dyn_cal_process_cnt;
	u16 mac_phy_sync_err_cnt;
	struct dyn_cal_debug_info_t dyn_cal_debug_info[DYN_CAL_DEBUG_NUM_ITER];
};

struct ac_info_t {
	u8 active_session;
	u32 total_q_switch_cnt;
	u32 total_ac_desc_cnt;
	u8 mult_ampdu_in_txop_cnt;
};

/* End of parameters that require host changes */

/* Structure containing the parameters for assert prints DBG_PRINT_IND message. */
struct dbg_print_ind {
	__le16 file_id;
	__le16 line;
	__le16 has_param;
	u8 err_no_dump;
	u8 reserved;
	__le32 param;
};

enum {
	CE_TXL_TX_PATH_IDLE,
	CE_TXL_TX_PATH_START,
	CE_TXL_TX_PATH_POST_START_DOWNLOAD,
	CE_TXL_TX_PATH_TX_DATA_DOWNLOADING,
	CE_TXL_TX_PATH_MU_RECOVERY,
	CE_TXL_TX_PATH_LAST_DOWNLOADING,
	CE_TXL_TX_PATH_NEXT_SESSION_PREPARED,
	CE_TXL_TX_PATH_MU_NEXT_JOB_READY,
	CE_TXL_TX_PATH_MAX
};

/* 4 ACs + BCN + HTP + current THD */
#define MACHW_THD_REGS_CNT (IPC_TX_QUEUE_CNT + 2)

/* Enumeration of MAC-HW registers (debug dump at recovery event) */
enum {
	HAL_MACHW_AGGR_STATUS,
	HAL_MACHW_DEBUG_HWSM_1,
	HAL_MACHW_DEBUG_HWSM_2,
	HAL_MACHW_DEBUG_HWSM_3,
	HAL_MACHW_DMA_STATUS_1,
	HAL_MACHW_DMA_STATUS_2,
	HAL_MACHW_DMA_STATUS_3,
	HAL_MACHW_DMA_STATUS_4,
	HAL_MACHW_RX_HEADER_H_PTR,
	HAL_MACHW_RX_PAYLOAD_H_PTR,
	HAL_MACHW_DEBUG_BCN_S_PTR,
	HAL_MACHW_DEBUG_AC0_S_PTR,
	HAL_MACHW_DEBUG_AC1_S_PTR,
	HAL_MACHW_DEBUG_AC2_S_PTR,
	HAL_MACHW_DEBUG_AC3_S_PTR,
	HAL_MACHW_DEBUG_HTP_S_PTR,
	HAL_MACHW_DEBUG_TX_C_PTR,
	HAL_MACHW_DEBUG_RX_HDR_C_PTR,
	HAL_MACHW_DEBUG_RX_PAY_C_PTR,
	HAL_MACHW_MU0_TX_POWER_LEVEL_DELTA_1,
	HAL_MACHW_MU0_TX_POWER_LEVEL_DELTA_2,
	HAL_MACHW_POWER_BW_CALIB_FACTOR,
	HAL_MACHW_TX_POWER_ANTENNA_FACTOR_1_ADDR,
	HAL_MACHW_TX_POWER_ANTENNA_FACTOR_2_ADDR,
	/* Keep this entry last */
	HAL_MACHW_REG_NUM
};

#define HAL_MACHW_FSM_REG_NUM ((HAL_MACHW_DEBUG_HWSM_3 - HAL_MACHW_AGGR_STATUS) + 1)

enum {
	MPU_COMMON_FORMAT,
	MPU_COMMON_FIELD_CTRL,
	MPU_COMMON_LEGACY_INFO,
	MPU_COMMON_COMMON_CFG_1,
	MPU_COMMON_COMMON_CFG_2,
	MPU_COMMON_COMMON_CFG_3,
	MPU_COMMON_HE_CFG_1,
	MPU_COMMON_HE_CFG_2,
	MPU_COMMON_INT_STAT_RAW,
	RIU_CCAGENSTAT,
	PHY_HW_DBG_REGS_CNT
};

/* Error trace CE_AC info */
struct dbg_ac_info {
	u8 chk_state;
	u8 tx_path_state;
	u8 physical_queue_idx;
	u16 active_session;
	u32 last_frame_exch_ptr;
};

/* Error trace txdesc lists info */
struct dbg_txlist_info {
	u8 curr_session_idx;
	u8 next_session_idx;
	u16 pending_cnt;
	u16 download_cnt;
	u16 transmit_cnt;
	u16 wait_for_ba_cnt;
	u16 next_pending_cnt;
};

// Error trace usb retry txdesc lists info
struct dbg_txlist_usb_retry_info {
	u8 session_idx;
	__le16 curr_pending_cnt[DBG_USB_TX_CNT];
	__le16 next_pending_cnt[DBG_USB_TX_CNT];
	__le16 transmit_cnt[DBG_USB_TX_CNT];
	__le16 wait_for_ba_cnt[DBG_USB_TX_CNT];
};

/* Txl chain info */
struct cl_dbg_txl_chain_info {
	u32 count;
	u32 frm_type;
	u32 first_thd_ptr;
	u32 last_thd_ptr;
	u32 prev_thd_ptr;
	u32 req_phy_flags;
	u8 reqbw;
	u8 ce_txq_idx;
	u16 mpdu_count;
	u8 chbw;
	u32 rate_ctrl_info;
	u32 rate_ctrl_info_he;
	u32 txstatus;
	u32 length;
	u32 tx_time;
};

struct dbg_txl_ac_chain_trace {
	struct cl_dbg_txl_chain_info data[DBG_TXL_FRAME_EXCH_TRACE_DEPTH];
	u32 count;
	u8 next_chain_index;
	u8 next_done_index;
	u8 delta;
};

struct dbg_fw_trace {
	u32 string_ptr;
	u32 var_1;
	u32 var_2;
	u32 var_3;
	u32 var_4;
	u32 var_5;
	u32 var_6;
	/*
	 * This field is used only for driver pring dump file.
	 * collect string char is done at error dump collect data function.
	 */
	char string_char[DBG_FW_TRACE_STR_MAX];
};

/* Error trace MAC-FW info */
struct dbg_fw_info {
	struct dbg_ac_info ac_info[CE_AC_MAX];
	struct dbg_txlist_info txlist_info_singles[IPC_TX_QUEUE_CNT];
	struct dbg_txlist_info txlist_info_agg[AGG_IDX_MAX];
	struct dbg_txlist_usb_retry_info usb_retry_txlist_info;
	struct dbg_txl_ac_chain_trace txl_ac_chain_trace[CE_AC_MAX];
	struct dbg_fw_trace fw_trace[DBG_FW_TRACE_SIZE];
	u32 fw_trace_idx;
};

/* TXM regs */
struct dbg_txm_regs {
	u8 hw_state;
	u8 fw_state;
	u8 spx_state;
	u8 free_buf_state;
	u8 mpdu_cnt;
	u8 lli_cnt;
	u8 lli_done_reason;
	u8 lli_done_mpdu_num;
	u16 active_bytes;
	u16 prefetch_bytes;
	u32 last_thd_done_addr;
	u16 last_thd_done_mpdu_num;
	u16 underrun_cnt;
};

/* Error trace HW registers */
struct dbg_hw_reg_info {
	u32 mac_hw_reg[HAL_MACHW_REG_NUM];
	u32 phy_mpu_hw_reg[PHY_HW_DBG_REGS_CNT];
	struct dbg_txm_regs txm_regs[AGG_IDX_MAX];
};

struct dbg_meta_data {
	__le32 lmac_req_buf_size;
	u8 physical_queue_cnt;
	u8 agg_index_max;
	u8 ce_ac_max;
	u8 mu_user_max;
	u8 txl_exch_trace_depth;
	__le16 mac_hw_regs_max;
	__le16 phy_hw_regs_max;
	__le16 thd_chains_data_size;
	u8 chains_info_elem_cnt;
	__le16 la_conf_len;
};

struct dbg_agg_thds_addr {
	u32 rts_cts_thd_addr;
	u32 athd_addr;
	u32 tf_thd_addr;
	u32 bar_thd_addr;
	u32 policy_table_addr;
};

struct dbg_agg_thd_info {
	struct tx_hd rts_cts_thd;
	struct tx_hd athd;
	struct tx_hd tf_thd;
	struct tx_hd bar_thd;
	struct tx_policy_tbl policy_table;
};

struct dbg_machw_regs_thd_info {
	struct tx_hd thd[MACHW_THD_REGS_CNT];
};

struct dbg_thd_chains_info {
	u8 type_array[DBG_CHAINS_INFO_ELEM_CNT];
	u32 elem_address[DBG_CHAINS_INFO_ELEM_CNT];
};

struct dbg_thd_chains_data {
	u8 data[DBG_THD_CHAINS_INFO_ARRAY_SIZE];
};

/* Error trace debug structure. common to fw & drv */
struct dbg_error_trace_info_common {
	struct dbg_print_ind error_info;
	struct dbg_meta_data dbg_metadata;
	struct dbg_hw_reg_info hw_info;
	struct dbg_fw_info fw_info;
	struct dbg_agg_thds_addr agg_thds_addr[AGG_IDX_MAX];
};

/* Dbg error info driver side */
struct dbg_error_trace_info_drv {
	struct dbg_error_trace_info_common common_info;
	struct dbg_agg_thd_info agg_thd_info[AGG_IDX_MAX];
	struct dbg_machw_regs_thd_info machw_thd_info;
	struct dbg_thd_chains_info thd_chains_info[CE_AC_MAX];
	struct dbg_thd_chains_data thd_chains_data[CE_AC_MAX];
};

/*
 * This is the main debug struct, the kernel allocate the needed spaces using kmalloc().
 * the firmware holds a pointer to this struct.
 */
struct dbg_dump_info {
	u32 dbg_info; /* Should be first member in the struct */
	/* Dump data transferred to host */
	struct dbg_debug_info_tag general_data;
	struct dbg_error_trace_info_drv fw_dump;
	u8 la_mem[LA_CNT][LA_MEM_LEN];
};

struct dbg_info {
	union {
		u32 type;
		struct dbg_dump_info dump;
		struct cl_txl_statistics tx_stats;
		struct cl_bcn_statistics bcn_stats;
		struct cl_rxl_statistics rx_stats;
		struct cl_dyn_calib_statistics dyn_calib_stats;
		struct cl_rate_drop_statistics rate_drop_stats;
		struct cl_bf_statistics bf_stats;
		struct cl_trigger_flow_statistics trigger_flow_stats;
		struct cl_pta_statistics pta_stats;
	} u;
};

/* Structure of a list element header */
struct co_list_hdr {
	__le32 next;
};

/* ETH2WLAN and NATT common parameters field (e2w_natt_param) struct definition: */
struct cl_e2w_natt_param {
#ifdef __LITTLE_ENDIAN_BITFIELD
	u32 valid           : 1,  /* [0] */
	    ampdu           : 1,  /* [1] */
	    last_mpdu       : 1,  /* [2] */
	    lc_snap         : 1,  /* [3] */
	    vlan            : 1,  /* [4] */
	    amsdu           : 1,  /* [5] Step B0 */
	    e2w_band_id     : 1,  /* [6] */
	    use_local_addr  : 1,  /* [7] Step B0 */
	    hdr_conv_enable : 1,  /* [8] */
	    sta_index       : 7,  /* [9:15] */
	    packet_length   : 15, /* [30:16] */
	    e2w_int_enable  : 1;  /* [31] */
#else /* __BIG_ENDIAN_BITFIELD */
	u32 e2w_int_enable  : 1,  /* [0] */
	    packet_length   : 15, /* [15:1] */
	    sta_index       : 7,  /* [22:16] */
	    hdr_conv_enable : 1,  /* [23] */
	    use_local_addr  : 1,  /* [24] */
	    e2w_band_id     : 1,  /* [25] Step B0 */
	    amsdu           : 1,  /* [26] */
	    vlan            : 1,  /* [27] Step B0 */
	    llc_snap        : 1,  /* [28] */
	    last_mpdu       : 1,  /* [29] */
	    ampdu           : 1,  /* [30] */
	    valid           : 1;  /* [31] */
#endif
};

#define CL_CCMP_GCMP_PN_SIZE 6

struct cl_e2w_txhdr_param {
	__le16 frame_ctrl;
	__le16 seq_ctrl;
	__le32 ht_ctrl;
	u8 encrypt_pn[CL_CCMP_GCMP_PN_SIZE];
	__le16 qos_ctrl;
};

/* This structure is not filled by the driver, so there is no need to support LITTLE/BIG ENDIAN */
struct cl_natt_result {
	u32 n_zld     : 16, /* [15:0] Number of Zero-Length Delimiters */
	    reserved  : 15, /* [30:16] */
	    natt_done : 1;  /* [31] NATT Tx Descriptor */
};

/* Bit 16 Has different usage for single (valid sta - set by host) or agg (tx done - set by HW) */
struct cl_e2w_result {
#ifdef __LITTLE_ENDIAN_BITFIELD
	u32 tid                               : 4,  /* [3:0] */
	    which_descriptor                  : 2,  /* [5:4] */
	    is_first_in_AMPDU                 : 1,  /* [6] */
	    is_ext_buff                       : 1,  /* [7] */
	    hw_key_idx                        : 8,  /* [15:8] */
	    single_valid_sta__agg_e2w_tx_done : 1,  /* [16] */
	    msdu_length                       : 13, /* [29:17] */
	    is_txinject                       : 1,  /* [30] */
	    sw_padding                        : 1;  /* [31] */

#else /* __BIG_ENDIAN_BITFIELD */
	u32 sw_padding                        : 1,  /* [0] */
	    is_txinject                       : 1,  /* [1] */
	    msdu_length                       : 13, /* [14:2] */
	    single_valid_sta__agg_e2w_tx_done : 1,  /* [15] */
	    hw_key_idx                        : 8,  /* [23:16] */
	    is_ext_buff                       : 1,  /* [24] */
	    is_first_in_AMPDU                 : 1,  /* [25] */
	    which_descriptor                  : 2,  /* [27:26] */
	    tid                               : 4,  /* [31:28] */
#endif
};

struct tx_host_info {
#ifdef __LITTLE_ENDIAN_BITFIELD
	u32 packet_cnt               : 4, /* [3:0] */
	    host_padding             : 8, /* [11:4] */
	    last_MSDU_LLI_INT_enable : 1, /* [12] */
	    is_eth_802_3             : 1, /* [13] */
	    is_protected             : 1, /* [14] */
	    vif_index                : 4, /* [18:15] */
	    rate_ctrl_entry          : 3, /* [21:19] */
	    expected_ack             : 1, /* [22] */
	    is_vns                   : 1, /* [23] */
	    cksum_update_enable      : 8; /* [31:24] */
#else /* __BIG_ENDIAN_BITFIELD */
	u32 cksum_update_enable      : 8, /* [7:0] */
	    is_vns                   : 1, /* [8] */
	    expected_ack             : 1, /* [9] */
	    rate_ctrl_entry          : 3, /* [12:10] */
	    vif_index                : 4, /* [16:13] */
	    is_protected             : 1, /* [17] */
	    is_eth_802_3             : 1, /* [18] */
	    last_MSDU_LLI_INT_enable : 1, /* [19] */
	    host_padding             : 8, /* [27:20] */
	    packet_cnt               : 4; /* [31:28] */
#endif
};

struct single_frame_flags
{
#ifdef __LITTLE_ENDIAN_BITFIELD
	u32 frame_type               : 8,  /* [7:0] */
	    rx_req_trigger           : 1,  /* [8] */
	    sngl_frame_type          : 4,  /* [12:9] */
	    backup_bcn               : 1,  /* [13] */
	    dont_chain               : 1,  /* [14] */
	    is_flush_needed          : 1,  /* [15] */
	    is_internal              : 1,  /* [16] */
	    bcmc                     : 1,  /* [17] */
	    single_type              : 2,  /* [19:18] */
	    is_bcn                   : 1,  /* [20] */
	    reserved                 : 11; /* [31:21] */
#else
	u32 reserved                 : 11, /* [10:0] */
	    is_bcn                   : 1,  /* [11] */
	    single_type              : 2,  /* [13:12] */
	    bcmc                     : 1,  /* [14] */
	    is_internal              : 1,  /* [15] */
	    is_flush_needed          : 1,  /* [16] */
	    dont_chain               : 1,  /* [17] */
	    backup_bcn               : 1,  /* [18] */
	    sngl_frame_type          : 4,  /* [22:19] */
	    rx_req_trigger           : 1,  /* [23] */
	    frame_type               : 8;  /* [31:24] */
#endif
};

struct lmacpriv {
	__le32 buffer;
};

struct agg_info {
	/* Pointers to packet payloads */
	__le32 packet_addr[CL_AMSDU_TX_PAYLOAD_MAX];
	/* Sizes of the MPDU/MSDU payloads */
	__le16 packet_len[CL_AMSDU_TX_PAYLOAD_MAX];
};

struct sngl_info {
	__le32 packet_addr;
	struct single_frame_flags single_frm_flags;
	/* Information provided by LMAC for internal use */
	struct lmacpriv lmacdesc;
	__le16 packet_len; // must be CL_AMSDU_PAYLOAD_MAX words from start
	__le32 cfm_status;
};

struct lmacapi {
	union {
		struct agg_info agg_info;
		struct sngl_info sngl_info;
	};
	__le16 push_timestamp; /* Milisec */
};

struct txdesc {
	/* Pointer to the next element in the queue */
	struct co_list_hdr list_hdr;
	/* E2w txhdr parameters */
	struct cl_e2w_txhdr_param e2w_txhdr_param __aligned(4);
	/* Celeno flags field */
	struct tx_host_info host_info __aligned(4);
	/* Common parameters for ETH2WLAN and NATT hardware modules */
	struct cl_e2w_natt_param  e2w_natt_param;
	/* ETH2WLAN status and NATT calculation results */
	struct cl_e2w_result e2w_result;
	/* Information provided by UMAC to LMAC */
	struct lmacapi umacdesc;
};

struct dma_desc_hdr {
	struct co_list_hdr list_hdr;
	struct dma_desc dma_desc;
};

enum {
	DBG_ERROR_RECOVERABLE = 0,
	DBG_ERROR_FATAL
};

/* Message structure for CFMs from Emb to App */
struct cl_ipc_cfm_msg {
	__le32 status;
	__le32 dma_addr;
	__le32 single_queue_idx;
};

/* Message structure for read req messages from Emb to App */
struct cl_usb_read_req_msg {
#ifdef __LITTLE_ENDIAN_BITFIELD
	u32 rsv        : 16, /* [15:0] */
	    ep_idx     : 8,  /* [23:16] */
	    num_trans  : 8;  /* [31:24] */
#else /* __BIG_ENDIAN_BITFIELD */
	u32 num_trans  : 8,  /* [7:0] */
	    ep_idx     : 8,  /* [15:8] */
	    rsv        : 16; /* [31:16] */
#endif
	__le16 length[CL_USB_READ_REQ_DATA_SIZE];
	__le32 src_addr[CL_USB_READ_REQ_DATA_SIZE];
};

struct cl_usb_write_req_msg {
	__le32 dest_addr;
};

struct cl_usb_e2a_irq_msg {
	__le32 status;
};


/* IRQs from app to emb */
#define IPC_IRQ_A2E_TXDESC     0xFF00
#define IPC_IRQ_A2E_RXBUF_BACK BIT(2)
#define IPC_IRQ_A2E_MSG        BIT(1)
#define IPC_IRQ_A2E_RXREQ      0x78
#define IPC_IRQ_A2E_ALL        (IPC_IRQ_A2E_TXDESC | IPC_IRQ_A2E_MSG)

#define IPC_IRQ_A2E_TXDESC_FIRSTBIT 8
#define IPC_IRQ_A2E_RXREQ_FIRSTBIT  3

#define IPC_IRQ_A2E_TXDESC_AGG_MAP(ac)    (IPC_IRQ_A2E_TXDESC_FIRSTBIT + IPC_TXQ_CNT + (ac))
#define IPC_IRQ_A2E_TXDESC_SINGLE_MAP(ac) (IPC_IRQ_A2E_TXDESC_FIRSTBIT + (ac))
#define IPC_IRQ_A2E_RX_STA_MAP(ac)        (IPC_IRQ_A2E_RXREQ_FIRSTBIT + (ac))

struct cl_ipc_e2a_irq {
	u32 dbg;
	u32 msg;
	u32 rxdesc;
	u32 txcfm;
	u32 radar;
	u32 tbtt;
	u32 all;
};

#endif /* CL_IPC_SHARED_H */
