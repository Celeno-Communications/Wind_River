/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_STA_H
#define CL_STA_H

#include "sta_info.h"
#include "cl_timer.h"
#include "cl_rate_ctrl.h"
#include "cl_traffic_mon.h"

#define IEEE80211_STA_TO_CL_STA(sta) ((struct cl_sta *)(sta)->drv_priv)
#define STA_INFO_TO_CL_STA(sta_info) ((struct cl_sta *)(sta_info)->sta.drv_priv)

#define STA_IDX_INVALID U8_MAX

struct cl_wrs_info {
	u64 epr_acc;
	u32 success;
	u32 fail;
	u32 fail_prev;
	u32 ba_not_rcv;
	u8 ba_not_rcv_consecutive;
	u8 ba_not_rcv_consecutive_max;
	bool synced;
	u32 sync_attempts;
	u8 quick_rate_agg_cntr;
	u16 quick_rate_pkt_cntr;
	bool quick_rate_check;
};

struct cl_wrs_rssi {
	s32 sum[MAX_ANTENNAS];
	s32 cnt;
};

struct cl_amsdu_ctrl {
	struct cl_sw_txhdr *sw_txhdr;
	u16 rem_len;
	u16 max_len;
	u16 hdrlen;
	u8 packet_cnt;
	bool is_sw_amsdu;
};

struct cl_bf_sta_db {
	bool traffic_active;
	bool sounding_start;
	bool indication_timeout;
	bool synced;
	bool is_on;
	bool is_on_fallback;
	u8 num_ss;
	u8 num_ss_fallback;
	u8 beamformee_sts;
	u8 nc;
	u32 sounding_indications;
	struct cl_timer timer;
};

#define RSSI_ARR_SIZE 128
#define BF_IDX_MAX 2

struct cl_tx_cntrs {
	u32 success;
	u32 fail;
};

struct cl_tx_stats {
	struct cl_tx_cntrs he[CHNL_BW_MAX][WRS_SS_MAX][WRS_MCS_MAX][WRS_GI_MAX][BF_IDX_MAX];
	struct cl_tx_cntrs
		vht[CHNL_BW_MAX_VHT][WRS_SS_MAX][WRS_MCS_MAX_VHT][WRS_GI_MAX_VHT][BF_IDX_MAX];
	struct cl_tx_cntrs ht[CHNL_BW_MAX_HT][WRS_SS_MAX][WRS_MCS_MAX_HT][WRS_GI_MAX_HT];
	struct cl_tx_cntrs ofdm[WRS_MCS_MAX_OFDM];
	struct cl_tx_cntrs cck[WRS_MCS_MAX_CCK];
	u32 agg_cntr;
	u32 fail_cntr;
};

enum cl_ps_period {
	PS_PERIOD_50MS,
	PS_PERIOD_100MS,
	PS_PERIOD_250MS,
	PS_PERIOD_500MS,
	PS_PERIOD_750MS,
	PS_PERIOD_1000MS,
	PS_PERIOD_2000MS,
	PS_PERIOD_5000MS,
	PS_PERIOD_10000MS,
	PS_PERIOD_ABOVE,

	PS_PERIOD_MAX
};

struct cl_ps_stats {
	bool is_ps;
	unsigned long timestamp_sleep;
	u32 period[PS_PERIOD_MAX];
};

enum cl_fec_coding {
	CL_FEC_CODING_BCC,
	CL_FEC_CODING_LDPC,
	CL_FEC_CODING_MAX
};

struct cl_stats {
	struct cl_tx_stats tx;
	struct cl_rx_stats rx;
	u32 rssi[RSSI_ARR_SIZE][MAX_ANTENNAS];
	u32 fec_coding[CL_FEC_CODING_MAX];
	struct cl_ps_stats ps;
};

/* Per RA/TID Data for AMPDU TX */
struct cl_baw {
	u8 fw_agg_idx;
	bool amsdu;
	bool action_start;
	u16 ssn;
	u16 tid_seq;
	struct sk_buff_head pending;
};

struct cl_vns_sta_db {
	bool is_very_near;
	bool prev_decision;
	s32 rssi_sum[MAX_ANTENNAS];
	s32 rssi_samples;
};

struct cl_agc_cd_rssi {
	s32 samples;
	s32 sum[MAX_ANTENNAS];
	s8 prev;
};

struct cl_ul_rssi_info {
	struct ieee80211_uph_ctrl uph;
	u32 rcpi_samples;
	u32 rcpi_sum;
	u8 rcpi;
};

struct cl_bsrp_info {
	struct cl_hw *cl_hw;
	struct cl_timer timeout_timer;
	u32 byte_threshold;
	u8 bsr_bitmap;
	bool is_ul_su;
	bool dbg;
};

struct cl_tid_ampdu_rx {
	spinlock_t reorder_lock;
	u64 reorder_buf_filtered;
	struct sk_buff_head *reorder_buf;
	struct hw_rxhdr **reorder_rxhdr;
	unsigned long *reorder_time;
	struct ieee80211_sta *sta;
	struct cl_timer reorder_timer;
	struct cl_hw *cl_hw;
	u16 head_seq_num;
	u16 stored_mpdu_num;
	u16 ssn;
	u16 buf_size;
	u16 timeout;
	u8 tid;
	u8 auto_seq:1,
	   removed:1,
	   started:1;
};

/*
 * Structure used to save information relative to the managed stations.
 * Will be used as the 'drv_priv' field of the "struct ieee80211_sta" structure.
 */
struct cl_sta {
	struct list_head list;
	struct list_head list_hash;
	u8 sta_idx;
	u8 su_sid;
	bool is_dummy;
	bool key_disable;
	u8 addr[ETH_ALEN];
	struct cl_baw baws[IEEE80211_NUM_TIDS];
	struct cl_amsdu_ctrl amsdu_anchor[IEEE80211_NUM_TIDS];
	struct cl_tx_queue *agg_tx_queues[IEEE80211_NUM_TIDS];
	u8 rx_pn[IEEE80211_NUM_TIDS][IEEE80211_CCMP_PN_LEN];
	u16 iv16[IEEE80211_NUM_TIDS];
	u32 iv32[IEEE80211_NUM_TIDS];
	struct cl_vif *cl_vif;
	struct sta_info *stainfo;
	struct ieee80211_key_conf *key_conf;
	struct cl_bf_sta_db bf_db;
	struct cl_stats *stats;
	s32 alpha_rssi;
	bool manual_alpha_rssi;
	s8 last_rssi[MAX_ANTENNAS];
	u8 ampdu_min_spacing;
	struct cl_traffic_sta traffic_db[TRAFFIC_DIRECTION_MAX];
	struct cl_traffic_mon traffic_mon[CL_TRFC_MON_PROT_MAX][CL_TRFC_MON_DIR_MAX];
	struct cl_vns_sta_db vns_db;
	struct cl_agc_cd_rssi agc_cd_rssi;
	u32 retry_count;
	u32 age_out_counter;
	u32 data_pending[AC_MAX];
	struct cl_wrs_info wrs_info_tx_su;
	struct cl_wrs_info wrs_info_rx;
	struct cl_wrs_rssi wrs_rssi;
	bool add_complete;
	bool remove_start;
	struct cl_wrs_sta wrs_sta;
	struct cl_rx_sens_info rx_sens_info;
	union cl_rate_ctrl_info_he rate_ctrl_he;
	struct cl_bsrp_info bsrp_info;
	struct cl_ul_rssi_info ul_rssi_info;
	bool tf_support_dis;
	struct cl_tid_ampdu_rx *tid_agg_rx[IEEE80211_NUM_TIDS];
	bool stop_tx;
};

typedef void (*sta_callback)(struct cl_hw *, struct cl_sta *);

void cl_sta_init(struct cl_hw *cl_hw);

/* These functions take the lock inside */
u32 cl_sta_num(struct cl_hw *cl_hw);
u32 cl_sta_num_bh(struct cl_hw *cl_hw);
bool cl_sta_is_assoc(struct cl_hw *cl_hw, u8 sta_idx);

/* Must take lock before calling these functions */
struct cl_sta *cl_sta_get(struct cl_hw *cl_hw, u8 sta_idx);
struct cl_sta *cl_sta_get_by_addr(struct cl_hw *cl_hw, u8 *addr);

/* Loop over list of stations and run the callback for each station */
void cl_sta_loop(struct cl_hw *cl_hw, sta_callback callback);
void cl_sta_loop_bh(struct cl_hw *cl_hw, sta_callback callback);
void cl_sta_loop_safe(struct cl_hw *cl_hw, sta_callback callback);

int cl_sta_init_stainfo(struct cl_hw *cl_hw, struct sta_info *stainfo);
int cl_sta_add(struct cl_hw *cl_hw, struct ieee80211_vif *vif, struct ieee80211_sta *sta);
void cl_sta_mgd_add(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct ieee80211_sta *sta);
int cl_sta_remove(struct cl_hw *cl_hw, struct ieee80211_vif *vif, struct ieee80211_sta *sta);
void cl_sta_disassociate_all(struct cl_hw *cl_hw);
void cl_sta_disassociate_ap_iface(struct cl_hw *cl_hw);
void cl_sta_ps_notify(struct cl_hw *cl_hw, struct cl_sta *cl_sta, bool is_ps);

static inline void cl_sta_lock_bh(struct cl_hw *cl_hw)
{
	read_lock_bh(&cl_hw->cl_sta_db.lock);
}

static inline void cl_sta_unlock_bh(struct cl_hw *cl_hw)
{
	read_unlock_bh(&cl_hw->cl_sta_db.lock);
}

static inline void cl_sta_lock(struct cl_hw *cl_hw)
{
	read_lock(&cl_hw->cl_sta_db.lock);
}

static inline void cl_sta_unlock(struct cl_hw *cl_hw)
{
	read_unlock(&cl_hw->cl_sta_db.lock);
}

#endif /* CL_STA_H */
