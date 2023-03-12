/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_WRS_DB_H
#define CL_WRS_DB_H

#include <linux/workqueue.h>
#include "cl_debug.h"
#include "def.h"
#include "cl_wrs_tables.h"

#define WRS_MAINTENANCE_PERIOD_MS         40
#define WRS_DATA_RATE_FACTOR              10
#define WRS_RSSI_PROTECT_UP_THR           10
#define WRS_RSSI_PROTECT_DN_THR           10
#define WRS_MIN_FRAMES_FOR_DECISION       15
#define WRS_EPR_FACTOR                    105
#define WRS_CONVERGE_IDLE_PACKET_TH       5
#define WRS_CONVERGE_IDLE_INTERVAL_RESET  6000  /* 6 sec */
#define WRS_CONVERGE_IDLE_INTERVAL_RSSI   2000  /* 2 sec */
#define WRS_CONVERGE_TRFC_INTERVAL_STATIC 30000 /* 30 sec */
#define WRS_IMMEDIATE_DROP_EPR_FACTOR     70    /* 70% */
#define WRS_IMMEDIATE_DROP_MAX_IN_ROW     U32_MAX
#define WRS_SYNC_MIN_ATTEMPTS             4
#define WRS_SYNC_TIMEOUT                  1000  /* 1 sec */
#define WRS_QUICK_UP_BA_THR               5
#define WRS_QUICK_UP_INTERVAL_MS          1000
#define WRS_QUICK_DOWN_EPR_FACTOR         85
#define WRS_QUICK_DOWN_AGG_THR            3
#define WRS_QUICK_DOWN_PKT_THR            60
#define WRS_RSSI_PROTECT_SHIFT            7
#define WRS_RSSI_PROTECT_BUF_SZ_OLD       BIT(WRS_RSSI_PROTECT_SHIFT) /* 2 ^ 7 = 128 */
#define WRS_RSSI_PROTECT_BUF_SZ_NEW       3
#define WRS_BA_NOT_RCV_TIME_SINCE_SYNC    1000

enum cl_wrs_rssi_prot_mode {
	WRS_RSSI_PROT_MODE_RSSI,     /* Up/down based on rssi */
	WRS_RSSI_PROT_MODE_NEIGHBOR, /* Up/down based on neighbors */

	WRS_RSSI_PROTECT_MODE_MAX
};

enum cl_wrs_fixed_rate {
	WRS_AUTO_RATE,
	WRS_FIXED_FALLBACK_EN,
	WRS_FIXED_FALLBACK_DIS,

	WRS_FIXED_RATE_MAX
};

enum cl_wrs_fixed_param {
	WRS_FIXED_PARAM_MODE,
	WRS_FIXED_PARAM_BW,
	WRS_FIXED_PARAM_NSS,
	WRS_FIXED_PARAM_MCS,
	WRS_FIXED_PARAM_GI,

	WRS_FIXED_PARAM_MAX
};

#define FIXED_RATE_STR(x) \
	(((x) == WRS_AUTO_RATE) ? "auto rate" : \
	(((x) == WRS_FIXED_FALLBACK_EN) ? "fixed rate (fallbacks enabled)" : \
	"fixed rate (fallbacks disabled)"))

enum cl_wrs_decision {
	WRS_DECISION_NONE,
	WRS_DECISION_SAME,
	WRS_DECISION_UP,
	WRS_DECISION_UP_QUICK,
	WRS_DECISION_UP_RSSI,
	WRS_DECISION_UP_MCS1,
	WRS_DECISION_DOWN,
	WRS_DECISION_DOWN_RSSI,
	WRS_DECISION_DOWN_IMMEDIATE,
	WRS_DECISION_DOWN_QUICK,
	WRS_DECISION_DOWN_NO_SYNC,
	WRS_DECISION_RSSI_MGMT,
	WRS_DECISION_RX_RATE,

	WRS_DECISION_MAX,
};

enum cl_wrs_mcs {
	WRS_MCS_0,
	WRS_MCS_1,
	WRS_MCS_2,
	WRS_MCS_3,
	WRS_MCS_4,
	WRS_MCS_5,
	WRS_MCS_6,
	WRS_MCS_7,
	WRS_MCS_8,
	WRS_MCS_9,
	WRS_MCS_10,
	WRS_MCS_11,
	WRS_MCS_MAX,
};

#define WRS_MCS_MAX_CCK  WRS_MCS_4
#define WRS_MCS_MAX_OFDM WRS_MCS_8
#define WRS_MCS_MAX_HT   WRS_MCS_8
#define WRS_MCS_MAX_VHT  WRS_MCS_10
#define WRS_MCS_MAX_HE   WRS_MCS_MAX

enum cl_wrs_ss {
	WRS_SS_1,
	WRS_SS_2,

	WRS_SS_MAX
};

enum cl_wrs_gi {
	WRS_GI_LONG,
	WRS_GI_SHORT,
	WRS_GI_VSHORT,

	WRS_GI_MAX
};

#define WRS_GI_MAX_HT  WRS_GI_VSHORT
#define WRS_GI_MAX_VHT WRS_GI_VSHORT
#define WRS_GI_MAX_HE  WRS_GI_MAX

enum cl_wrs_ltf {
	LTF_X1,
	LTF_X2,
	LTF_X4,
	LTF_MAX
};

enum cl_wrs_converge_mode {
	WRS_CONVERGE_MODE_RESET,
	WRS_CONVERGE_MODE_RSSI,

	WRS_CONVERGE_MODE_MAX,
};

enum cl_wrs_mode {
	WRS_MODE_CCK,
	WRS_MODE_OFDM,
	WRS_MODE_HT,
	WRS_MODE_VHT,
	WRS_MODE_HE,

	WRS_MODE_MAX,
};

enum cl_wrs_type {
	WRS_TYPE_TX_SU,
	WRS_TYPE_RX,

	WRS_TYPE_MAX,
};

#define WRS_TYPE_STR(type) \
		((type) == WRS_TYPE_TX_SU ? "TX_SU" : \
		((type) == WRS_TYPE_RX ? "RX" : ""))

#define WRS_TYPE_IS_TX_SU(wrs_params) ((wrs_params)->type == WRS_TYPE_TX_SU)
#define WRS_TYPE_IS_RX(wrs_params) ((wrs_params)->type == WRS_TYPE_RX)

#define wrs_pr(wrs_db, level, ...) \
	do { \
		if ((level) <= (wrs_db)->debug_level) \
			pr_debug(__VA_ARGS__); \
	} while (0)

#define wrs_pr_verbose(wrs_db, ...) wrs_pr(wrs_db, DBG_LVL_VERBOSE, ##__VA_ARGS__)
#define wrs_pr_err(wrs_db, ...)     wrs_pr(wrs_db, DBG_LVL_ERROR, ##__VA_ARGS__)
#define wrs_pr_warn(wrs_db, ...)    wrs_pr(wrs_db, DBG_LVL_WARNING, ##__VA_ARGS__)
#define wrs_pr_trace(wrs_db, ...)   wrs_pr(wrs_db, DBG_LVL_TRACE, ##__VA_ARGS__)
#define wrs_pr_info(wrs_db, ...)    wrs_pr(wrs_db, DBG_LVL_INFO, ##__VA_ARGS__)

#define WRS_LOGGER wrs_params->logger[wrs_params->logger_idx]

/* m MUST be power of 2 ! */
#define WRS_INC_POW2(c, m) (((c) + 1) & ((m) - 1))

#define WRS_INC(c, m) \
	do { \
		(c)++; \
		if ((c) == (m)) \
			(c) = 0; \
	} while (0)

#define WRS_IS_DECISION_UP(decision) \
	(((decision) >= WRS_DECISION_UP) && ((decision) <= WRS_DECISION_UP_MCS1))
#define WRS_IS_DECISION_DOWN(decision) \
	(((decision) >= WRS_DECISION_DOWN) && ((decision) <= WRS_DECISION_DOWN_NO_SYNC))

#define WRS_DECISION_STR(decision) (                                   \
	(decision) == WRS_DECISION_NONE           ? "NONE"           : \
	(decision) == WRS_DECISION_SAME           ? "SAME"           : \
	(decision) == WRS_DECISION_UP             ? "UP"             : \
	(decision) == WRS_DECISION_UP_QUICK       ? "UP QUICK"       : \
	(decision) == WRS_DECISION_UP_RSSI        ? "UP RSSI"        : \
	(decision) == WRS_DECISION_UP_MCS1        ? "UP MCS1"        : \
	(decision) == WRS_DECISION_DOWN           ? "DOWN"           : \
	(decision) == WRS_DECISION_DOWN_RSSI      ? "DOWN RSSI"      : \
	(decision) == WRS_DECISION_DOWN_IMMEDIATE ? "DOWN IMMEDIATE" : \
	(decision) == WRS_DECISION_DOWN_QUICK     ? "DOWN QUICK"     : \
	(decision) == WRS_DECISION_DOWN_NO_SYNC   ? "DOWN NO_SYNC"   : \
	(decision) == WRS_DECISION_RSSI_MGMT      ? "RSSI MGMT"      : \
	(decision) == WRS_DECISION_RX_RATE        ? "RX_RATE"        : \
	"ERROR")

#define WRS_MODE_STR(mode) (               \
	(mode) == WRS_MODE_CCK  ? "CCK"  : \
	(mode) == WRS_MODE_OFDM ? "OFDM" : \
	(mode) == WRS_MODE_HT   ? "HT"   : \
	(mode) == WRS_MODE_VHT  ? "VHT"  : \
	(mode) == WRS_MODE_HE   ? "HE"   : \
	"ERR")

#define WRS_CONVERGE_MODE_STR(mode) \
	((mode) == WRS_CONVERGE_MODE_RESET ? "RESET" : "RSSI")

#define WRS_BW_STR(bw) (                  \
	(bw) == CHNL_BW_20  ? "20"  : \
	(bw) == CHNL_BW_40  ? "40"  : \
	(bw) == CHNL_BW_80  ? "80"  : \
	(bw) == CHNL_BW_160 ? "160" : \
	"ERR")

#define WRS_GI_STR(gi) (                       \
	(gi) == WRS_GI_LONG   ? "Long"       : \
	(gi) == WRS_GI_SHORT  ? "Short"      : \
	(gi) == WRS_GI_VSHORT ? "VeryShort" :  \
	"ERROR")

struct cl_wrs_cntrs {
	u64 epr_acc;
	u32 total;
	u32 fail;
	u32 ba_not_rcv;
	u32 ba_not_rcv_consecutive;
};

struct cl_wrs_rate_params {
	u16 mode        : 3, /* Mode - 0 = CCK, 1 = OFDM, 2 = HT, 3 = VHT, 4 = HE. */
	    gi          : 2, /* GI - O = Long, 1 = Short, 2 = Very short. */
	    bw          : 2, /* Bandwidth - 0 = 20M, 1 = 40M, 2 = 80M, 3 = 160M. */
	    nss         : 3, /* Spatial Streams - 0 = 1SS, 1 = 2SS, .. 7 = 8SS. */
	    mcs         : 4, /* MCS - CCK (0 - 3), OFDM/HT (0 - 7), VHT (0 - 9), HE (0 - 11). */
	    fallback_en : 1,
	    is_fixed    : 1;
};

struct cl_wrs_logger {
	unsigned long timestamp;
	u16 rate_idx;
	u32 success;
	u32 fail;
	u32 ba_not_rcv;
	u16 down_rate_idx;
	u16 up_rate_idx;
	u16 curr_epr;
	u16 down_epr;
	u16 down_epr_factorized;
	u16 penalty;
	u16 up_time;
	enum cl_wrs_decision decision;
	u16 new_rate_idx;
};

struct cl_wrs_per_stats {
	struct list_head list;
	u8 mcs;
	u8 bw;
	u8 nss;
	u8 gi;
	u32 frames_total;
	u32 frames_failed;
	u64 epr_acc;
};

struct cl_wrs_rssi_prot_db {
	s8 samples_old[WRS_RSSI_PROTECT_BUF_SZ_OLD];
	s8 samples_new[WRS_RSSI_PROTECT_BUF_SZ_NEW];
	u8 curr_idx_old;
	u8 curr_idx_new;
	s32 sum;
};

struct cl_wrs_params {
	u8 group_id;
	u8 is_fixed_rate  : 2,
	   is_logger_en   : 1,
	   quick_up_check : 1,
	   type           : 2,
	   rsv            : 2;
	u32 up_same_time_cnt;
	u32 down_time_cnt;
	enum cl_wrs_converge_mode converge_mode;
	u32 converge_time_idle;
	u32 converge_time_trfc;
	u16 data_rate;
	u16 rate_idx;
	u16 initial_rate_idx;
	struct cl_wrs_table *table;
	u16 table_size;
	u16 penalty_decision_dn;
	struct cl_wrs_rate_params rate_params;
	struct cl_wrs_rate rx_rate_idle;
	enum cl_wrs_decision last_decision;
	u32 decision_cnt[WRS_DECISION_MAX];
	struct list_head list_rates;
	u32 frames_total;
	u32 fail_total;
	u32 ba_not_rcv_total;
	u64 epr_acc;
	bool calc_ba_not_rcv;
	bool sync;
	unsigned long sync_timestamp;
	unsigned long no_sync_timestamp;
	struct cl_wrs_logger *logger;
	u16 logger_idx;
	u16 logger_size;
	u32 immediate_drop_cntr;
	u32 immediate_drop_ignore;
};

struct cl_wrs_sta {
	u8 sta_idx;
	bool smps_enable;
	u8 assoc_bw;
	u8 he_minrate;
	u8 mu_ofdma_bw;
	u8 mu_ofdma_gi;
	u8 gi_cap[CHNL_BW_MAX];
	u64 supported_rates[CHNL_BW_MAX];
	enum cl_wrs_mode mode;
	struct cl_wrs_rate max_rate_cap;
	struct cl_wrs_rssi_prot_db rssi_prot_db;
	struct cl_wrs_params tx_su_params;
	struct cl_wrs_params *rx_params;
};

struct cl_wrs_db {
	/* General */
	spinlock_t lock;
	enum cl_dbg_level debug_level;
	struct delayed_work work_maintenance;
	u32 interval;
	/* Fixed rate */
	u8 is_fixed_rate;
	/* Conservative initial rate */
	bool conservative_mcs_noisy_env;
	bool conservative_nss_noisy_env;
	/* Immediate drop */
	bool immediate_drop_en;
	u8 immediate_drop_epr_factor;
	u32 immediate_drop_max_in_row;
	/* Converge idle */
	bool converge_idle_en;
	u32 converge_idle_interval_reset;
	u32 converge_idle_interval_rssi;
	u32 converge_idle_packet_th;
	/* Converge traffic */
	bool converge_trfc_en;
	u32 converge_trfc_interval_static;
	/* Supported rates */
	u8 mode;
	u64 ap_supported_rates[CHNL_BW_MAX]; /* Bit array for each bw */
	struct cl_wrs_rate max_cap;
	u8 coex_bw;
	/* RSSI protect */
	bool rssi_protect_en;
	u8 rssi_protect_mode;
	s8 rssi_protect_up_thr;
	s8 rssi_protect_dn_thr;
	/* Time + step thresholds */
	u16 time_th_min;
	u16 time_th_max_up;
	u16 time_th_max_down;
	u16 step_down;
	u16 step_up_same;
	/* Quick up */
	bool quick_up_en;
	u8 quick_up_ba_thr;
	u16 quick_up_interval;
	/* Quick down */
	bool quick_down_en;
	u8 quick_down_epr_factor;
	u8 quick_down_agg_thr;
	u16 quick_down_pkt_thr;
	/* BA not received */
	bool ba_not_rcv_collision_filter;
	bool ba_not_rcv_force;
	u32 ba_not_rcv_time_since_sync;
	/* Sync */
	u16 sync_timeout;
	u8 sync_min_attempts;
	/* All the rest */
	u32 min_frames_for_decision;
	u8 epr_factor;
};

#endif /* CL_WRS_DB_H */
