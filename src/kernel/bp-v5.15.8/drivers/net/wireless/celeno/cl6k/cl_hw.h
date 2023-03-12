/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_HW_H
#define CL_HW_H

#include "chip.h"
#include "cl_wrs_db.h"
#include "cl_traffic.h"
#include "cl_edca.h"
#include "cl_env_det.h"
#include "cl_chan_info.h"
#include "cl_channel.h"
#include "cl_debugfs_defs.h"
#include "cl_ipc_shared.h"
#include "cl_fw_msg.h"
#include "cl_rx_sens.h"
#include "cl_radar.h"
#include "cl_rate_ctrl.h"
#include "cl_power_table.h"
#include "cl_cca.h"
#include "def.h"
#include "cl_noise.h"
#include "cl_mac80211.h"
#include "cl_tcv_config.h"
#include "cl_sounding.h"
#include "cl_bsr.h"
#include <linux/workqueue.h>
#include <linux/module.h>

/* Max flags for driver status description is defined as 32 * MAX_CFM_FLAGS */
#define MAX_CFM_FLAGS 2

enum cl_radio_stats {
	CL_RADIO_FCS_ERROR = 0,
	CL_RADIO_PHY_ERROR,
	CL_RADIO_RX_FIFO_OVERFLOW,
	CL_RADIO_ADDRESS_MISMATCH,
	CL_RADIO_UNDEFINED_ERROR,
	CL_RADIO_ERRORS_MAX
};

enum cl_rx_usb_msdu_split {
	MSDU_NO_SPLIT,
	MSDU_FIRST_PART,
	MSDU_INTERMEDIATE_PART,
	MSDU_LAST_PART,

	MSDU_SPLIT_MAX
};

enum cl_fw_band {
	FW_BAND_2GHZ,
	FW_BAND_5GHZ,
	FW_BAND_6GHZ,

	FW_BAND_MAX,
};

#define CHNL_BW_MAX_HE   CHNL_BW_MAX
#define CHNL_BW_MAX_VHT  CHNL_BW_MAX
#define CHNL_BW_MAX_HT   CHNL_BW_80
#define CHNL_BW_MAX_OFDM CHNL_BW_40
#define CHNL_BW_MAX_CCK  CHNL_BW_40

struct cl_rx_path_info {
	u32 rx_desc[CL_RX_BUF_MAX];
	u32 netif_rx;
	u32 elem_alloc_fail;
	u32 skb_null;
	u32 pkt_drop_amsdu_corrupted;
	u32 pkt_drop_sub_amsdu_corrupted;
	u32 pkt_drop_amsdu_len_error;
	u32 pkt_drop_sub_amsdu_len_error;
	u32 pkt_drop_wrong_pattern;
	u32 pkt_drop_not_success;
	u32 pkt_drop_sub_amsdu_not_success;
	u32 pkt_drop_unencrypted;
	u32 pkt_drop_sub_amsdu_unencrypted;
	u32 pkt_drop_decrypt_fail;
	u32 pkt_drop_sub_amsdu_decrypt_fail;
	u32 pkt_drop_tailroom_error;
	u32 pkt_drop_sub_amsdu_tailroom_error;
	u32 pkt_drop_sta_null;
	u32 pkt_drop_host_limit;
	u32 pkt_drop_invalid_pn_tsc;
	u32 remote_cpu[CPU_MAX_NUM];
	u32 exceed_pkt_budget;
	u32 pkt_handle_bucket_rxm[IPC_RXBUF_NUM_BUCKETS_RXM];
	u32 pkt_handle_bucket_fw[IPC_RXBUF_NUM_BUCKETS_FW];
	u32 amsdu_cnt[RX_MAX_MSDU_IN_AMSDU];
	u32 non_amsdu;
	u32 w2e_done;
	u32 buffer_process_irq;
	u32 buffer_process_tasklet;
	u32 msdu_split_cnt[MSDU_SPLIT_MAX];
};

/* Structure used to store information regarding E2A msg buffers in the driver */
struct cl_e2a_msg_elem {
	struct cl_ipc_e2a_msg *msgbuf_ptr;
	dma_addr_t dma_addr;
};

/* Structure used to store information regarding Debug msg buffers in the driver */
struct cl_dbg_elem {
	struct cl_ipc_dbg_msg *dbgbuf_ptr;
	dma_addr_t dma_addr;
};

struct cl_tx_power_info {
	s8 offset;
	s8 temperature;
};

struct cl_rx_elem {
	int passed;
	struct sk_buff *skb;
	dma_addr_t dma_addr;
};

struct cl_dbg_info {
	struct mutex mutex;
	struct dbg_info *buf;
	dma_addr_t dma_addr;
	int bufsz;
};

struct cl_dbg_data {
	char *str; /* Pointer to debug strings start address */
	int size; /* Size of debug strings pool */
};

struct cl_phy_data_info {
	struct cl_phy_data *data;
	u32 dma_addr;
};

struct cl_sec_phy_chan {
	u16 prim20_freq;
	u16 center_freq1;
	u16 center_freq2;
	enum nl80211_band band;
	u8 type;
};

struct cl_amsdu_rx_state {
	u8 msdu_cnt;
	u8 msdu_remaining_cnt;
	/*
	 * MSDU padding - all MSDU pkt within A-MSDU are 4byte aligned (this
	 * value holds the alignment value)
	 * According to ieee80211 spec all MSDU share the same alignment
	 */
	u8 msdu_dma_align;
	u8 amsdu_error;
	u8 encrypt_len;
	u8 sta_idx;
	u8 tid;
	u32 packet_len;
	struct hw_rxhdr *rxhdr;
	struct cl_rx_w2e_hdr *w2e_hdr;
	struct sk_buff *first_skb;
	struct sk_buff_head frames;
};

struct cma_table_entry {
	u32 ip_addr;
	u8 mac_addr[ETH_ALEN];
	unsigned long last_time;
	struct cma_table_entry *next;
};

#define CL_CMA_MAX_IP_HASH 64

struct cl_cma_table {
	int size;
	/* 0~63 for specific station, 64 for broadcast MAC address */
	struct cma_table_entry *hash[CL_CMA_MAX_IP_HASH + 1];
	/* The multicast mac addr for current received packet destined to ipv4 multicast addr */
	u8 cur_mcast_addr[ETH_ALEN];
};

struct cl_tx_queue {
	struct list_head sched_list;
	struct list_head hdrs;
	struct cl_sta *cl_sta;
	bool sched;
	u16 fw_free_space;
	u16 fw_max_size;
	u8 type;
	u8 tid;
	u8 hw_index;
	u16 index;
	u16 max_packets;
	u16 num_packets;
	u32 total_packets;
	u32 total_fw_push_desc;
	u32 total_fw_push_skb;
	u32 total_fw_cfm;
	u32 dump_queue_full;
	u32 dump_dma_map_fail;
	u32 stats_hw_amsdu_cnt[CL_AMSDU_TX_PAYLOAD_MAX];
	u32 stats_sw_amsdu_cnt[MAX_TX_SW_AMSDU_PACKET];
};

struct cl_req_agg_db {
	bool is_used;
	u8 sta_idx;
	u8 tid;
};

/*
 * struct cl_tx_queues:
 * This structure holds all driver TX queues,
 * The queues buffer frames pushed by upper layer and push them to lower IPC layer.
 */
struct cl_tx_queues {
	struct cl_tx_queue agg[IPC_MAX_BA_SESSIONS];
	struct cl_tx_queue single[MAX_SINGLE_QUEUES];
	struct cl_tx_queue bcmc;
};

struct cl_prot_mode {
	u8 current_val;
	u8 default_val;
	u8 dynamic_val;
};

struct cl_hw_asserts_info {

	/* Timestamp (jiffies) of the last CL_MIN_ASSERT_CNT hw assert. */
	unsigned long timestamp[CL_MIN_ASSERT_CNT];
	/* Hw assert index. */
	u8 index;
	/* Indicate if hw_restart was schedule */
	u8 restart_sched;
	/* Indicate if hw_restart is needed due to unrecoverable assert. */
	u8 restart_needed;
};

struct cl_ate_db {
	bool active;
	u8 num_dummy_sta;
	s8 tx_power;
	s8 tx_power_offset[MAX_ANTENNAS];
	u8 ant_mask;
	u8 mode;
	u8 bw;
	u8 nss;
	u8 mcs;
	u8 gi;
	u8 ltf;
	struct ate_stats stats;
};

struct cl_vw_db {
	bool dbg;
	bool force;
	bool is_vw_rssi;
	bool is_vw_mac;
	bool is_vw_time;
	bool is_vw_global; /* Is_vw_global = is_vw_time && (is_vw_rssi || is_vw_mac) */
	u64 mac_addr_prev;
	u32 mac_addr_delta;
	unsigned long assoc_timestamp_prev;
};

struct cl_agg_cfm_queue {
	struct list_head head;
	struct cl_tx_queue *tx_queue;
	u16 ssn;
};

struct cl_single_cfm_queue {
	struct list_head head;
};

struct cl_assoc_queue {
	struct list_head list;
	spinlock_t lock;
};

struct cl_agc_cd {
	/* Configuration */
	u32 period;
	bool debug;
	/* Internal parameters */
	bool is_on;
	bool use_hystersis;
	u32 maintenance;
};

struct cl_dyn_mcast_rate {
	u8 wrs_mode_default;
	u8 wrs_mode_curr;
};

struct cl_dyn_bcast_rate {
	u8 sta_min_mcs;
	u8 bcast_mcs;
	u8 wrs_mode;
	u8 ltf;
};

struct cl_power_db {
	u8 curr_percentage;
	s8 curr_offset;
	/* Used to validate margins of MAC power */
	s8 bw_factor_q2[CHNL_BW_MAX];
	s8 ant_factor_q2[MAX_ANTENNAS];
};

struct cl_bf_db {
	bool force;
	enum cl_dbg_level dbg_level;
};

struct cl_vns_rssi_entry {
	struct list_head list_all;
	struct list_head list_addr;
	unsigned long timestamp;
	s8 strongset_rssi;
	u8 addr[ETH_ALEN];
};

#define STA_HASH_SIZE 256

struct cl_vns_mgmt_db {
	u32 num_entries;
	struct list_head list_all;
	struct list_head list_addr[STA_HASH_SIZE];
};

struct cl_vns_db {
	bool enable;
	bool dbg;
	bool dbg_per_packet;
	u16 interval_period;
	spinlock_t lock;
	struct cl_vns_mgmt_db mgmt_db;
};

struct cl_calib_db {
	struct cl_dcoc_calib
		wifi_dcoc[FW_BAND_MAX][CALIB_CHAN_MAX][CHNL_BW_MAX][MAX_ANTENNAS]
			 [DCOC_LNA_GAIN_NUM];
	struct cl_dcoc_calib
		bt_dcoc[MAX_NUM_BT_CHANNELS_CALIB][BT_FILTER_BW_MAX][BT_DCOC_LNA_GAIN_NUM];
	u32 iq_tx_lolc[FW_BAND_MAX][CALIB_CHAN_MAX][CHNL_BW_MAX][MAX_ANTENNAS];
	struct cl_iq_calib iq_tx[FW_BAND_MAX][CALIB_CHAN_MAX][CHNL_BW_MAX][MAX_ANTENNAS];
	struct cl_iq_calib iq_rx[FW_BAND_MAX][CALIB_CHAN_MAX][CHNL_BW_MAX][MAX_ANTENNAS];
	struct cl_calib_file_flags file_flags;
	struct cl_calib_errors errors;
	struct list_head plan[CALIB_CHAN_MAX][CHNL_BW_MAX];
};

/* Cl_dbgfile.c - offload data */
struct cl_str_offload_env {
	char *block1;
	u32 size1;
	u32 base1;
	char *block2;
	u32 size2;
	u32 base2;
	char *block3;
	u32 size3;
	u32 base3;
	bool enabled;
	char buf[512];
};

struct cl_dma_accessed {
	void *drv_v_addr;
	u32 size;
	u32 fw_v_addr;
	u32 dma_addr;
};

struct cl_radar_queue {
	struct list_head head;
	spinlock_t lock;
};

struct cl_recovery_db {
	unsigned long last_restart;
	u32 restart_cnt;
	bool in_recovery;
};

struct cl_noise_reg {
	struct list_head list;
	u32 np_prim20_per_ant;
	u32 np_prim20_per_ant2;
	u32 nasp_prim20_per_ant;
	u32 nasp_prim20_per_ant2;
	u32 np_sub20_per_chn;
	u32 np_sub20_per_chn2;
	u32 nasp_sub20_per_chn;
	u32 nasp_sub20_per_chn2;
	u32 np_sec20_dens_per_ant;
	u32 nasp_sec20_dens_per_ant;
};

struct cl_noise_db {
	struct list_head reg_list;
	bool hist_record;
	u8 active_ant;
	u8 sample_cnt;
};

struct cl_chan_info {
	u8 channel;
	u8 max_bw;
	/* Resolution of 0.25dB */
	u8 max_power_q2; /* min(country_max_power_q2, hardware_max_power_q2) */
	u8 country_max_power_q2;
	u8 hardware_max_power_q2;
};

struct cl_channel_info {
	bool use_channel_info;
	struct cl_chan_info channels[CHNL_BW_MAX][MAX_CHANNELS];
	enum cl_reg_standard standard;
	struct ieee80211_regdomain *rd;
};

#define CL_STA_HASH_SIZE (CL_MAX_NUM_STA / 2)
#define CL_STA_HASH_MASK (CL_STA_HASH_SIZE - 1)
#define CL_STA_HASH_IDX(x) ((x) & CL_STA_HASH_MASK)

struct cl_sta_db {
	struct list_head head;
	struct cl_sta *lut[CL_MAX_NUM_STA];
	struct list_head hash[CL_STA_HASH_SIZE];
	rwlock_t lock;
	u32 num;
};

struct cl_tx_inject {
	bool continuous;
	bool is_agg;
	bool is_running;
	bool aggressive_edca;
	atomic_t alloc_counter;
	u32 current_counter;
	u32 max_counter;
	u32 packet_len;
	struct cl_sta *cl_sta;
	struct tasklet_struct tasklet;
};

#define CL_USER_PRIO_VALS 8
#define CL_USER_DSCP_VALS 64

struct cl_vid_user {
	u16 vid;
	u8 user_prio;
};

struct cl_vlan_dhcp_params {
	/* DSCP to user priority mapping */
	u8 dscp_to_up[CL_USER_DSCP_VALS];
	/* VLAN to user priority mapping */
	u8 vlan_to_up[CL_USER_PRIO_VALS];
	/*
	 * Vid-pbit to user priority mapping
	 * First index is the pbit. Second index is a running index 0
	 */
	struct cl_vid_user vlan_pbit_to_up[CL_USER_PRIO_VALS][CL_USER_PRIO_VALS];
	/* 2 - "VLAN" VLAN based only, 3 - "DSCP" DSCP based only. Any other number - Automatic */
	u8 up_layer_based;
	u8 default_vlan_up;
};

struct cl_vlan_dscp {
	struct cl_vlan_dhcp_params vlan_dhcp_params[MAX_BSS_NUM];
	bool enable[MAX_BSS_NUM];
	bool debug;
};

#define CCA_MAX_SAMPLE 21

struct cl_edca_hist_db {
	u16 air_util[CCA_MAX_SAMPLE];
	u16 wifi_air_util[CCA_MAX_SAMPLE];
	u16 not_mine_rx_wifi[CCA_MAX_SAMPLE];
	u16 mine[CCA_MAX_SAMPLE];
	u16 not_mine[CCA_MAX_SAMPLE];
	u16 non_wifi_util[CCA_MAX_SAMPLE];
	u16 not_mine_busy[CCA_MAX_SAMPLE];
	u16 sample_cnt;
};

struct cl_cca_db {
	struct cl_edca_hist_db edca_hist;
	unsigned long time;
	u32 edca_busy;
	u32 edca_busy_sec20;
	u32 edca_busy_sec40;
	u32 edca_busy_sec80;
	u32 cca_busy_nav;
	u32 cca_intra_bss_nav;
	u32 cca_inter_bss_nav;
	u32 tx_mine;
	u32 rx_mine;
	u32 print_tx_mine;
	u32 print_rx_mine;
	enum cl_cca_opt cca_opt;
};

struct cl_cpu_cntr {
	u32 tx_agg[CPU_MAX_NUM];
	u32 tx_single[CPU_MAX_NUM];
};

struct cl_tx_drop_cntr {
	u32 wd_restart;
	u32 radio_off;
	u32 in_recovery;
	u32 short_length;
	u32 pending_full;
	u32 packet_limit;
	u32 dev_flags;
	u32 tx_disable;
	u32 length_limit;
	u32 txhdr_alloc_fail;
	u32 queue_null;
	u32 amsdu_alloc_fail;
	u32 amsdu_dma_map_err;
	u32 build_hdr_fail;
	u32 key_disable;
	u32 queue_flush;
	u32 probe_response;
	u32 sta_null_in_agg;
	u32 sta_stop_tx;
};

struct cl_tx_forward_cntr {
	u32 tx_start;
	u32 drv_fast_agg;
	u32 drv_fast_single;
	u32 to_mac;
	u32 from_mac_single;
	u32 from_mac_agg;
};

struct cl_tx_transfer_cntr {
	u32 single_to_agg;
	u32 agg_to_single;
};

struct cl_tx_packet_cntr {
	struct cl_tx_forward_cntr forward;
	struct cl_tx_drop_cntr drop;
	struct cl_tx_transfer_cntr transfer;
};

struct cl_power_truncate {
	u8 he[CHNL_BW_MAX][WRS_MCS_MAX_HE][PWR_TBL_BF_SIZE];
	u8 ht_vht[CHNL_BW_MAX][WRS_MCS_MAX_VHT][PWR_TBL_BF_SIZE];
	u8 ofdm[WRS_MCS_MAX_OFDM];
	u8 cck[WRS_MCS_MAX_CCK];
};

#define CL_TWT_MAX_SESSIONS 8

struct cl_twt_session_db {
	struct cl_sta *cl_sta;
	struct ieee80211_twt_individual_elem twt_setup;
};

struct cl_twt_db {
	struct cl_twt_session_db cl_twt_sessions[CL_TWT_MAX_SESSIONS];
	u8 num_sessions;
	u8 dialog_token;
};

struct cl_vif_db {
	struct list_head head;
	u8 num_iface_bcn;
};

struct cl_switch_band {
	u32 channel;
	enum nl80211_band nl_band;
	u8 band_num;
};

struct cl_tx_db {
	bool force_amsdu;
	bool block_bcn;
	bool block_prob_resp;
	bool ac_idle[IEEE80211_NUM_ACS];
};

struct cl_ul_rssi_db {
	u32 period;
	u32 maintenance;
	enum cl_dbg_level dbg_lvl;
	s8 target_pwr;
};

enum cl_rx_stats_flag {
	RX_STATS_CCK = 0x01,
	RX_STATS_OFDM = 0x02,
	RX_STATS_HT = 0x04,
	RX_STATS_VHT = 0x08,
	RX_STATS_HE_SU = 0x10,
	RX_STATS_HE_MU = 0x20,
	RX_STATS_HE_EXT = 0x40,
	RX_STATS_HE_TRIG = 0x80,
};

struct cl_rx_stats {
	u32 he_trig[CHNL_BW_MAX_HE][WRS_SS_MAX][WRS_MCS_MAX_HE][WRS_GI_MAX_HE];
	u32 he_ext[CHNL_BW_MAX_HE][WRS_SS_MAX][WRS_MCS_MAX_HE][WRS_GI_MAX_HE];
	u32 he_mu[CHNL_BW_MAX_HE][WRS_SS_MAX][WRS_MCS_MAX_HE][WRS_GI_MAX_HE];
	u32 he_su[CHNL_BW_MAX_HE][WRS_SS_MAX][WRS_MCS_MAX_HE][WRS_GI_MAX_HE];
	u32 vht[CHNL_BW_MAX_VHT][WRS_SS_MAX][WRS_MCS_MAX_VHT][WRS_GI_MAX_VHT];
	u32 ht[CHNL_BW_MAX_HT][WRS_SS_MAX][WRS_MCS_MAX_HT][WRS_GI_MAX_HT];
	u32 ofdm[WRS_MCS_MAX_OFDM];
	u32 cck[WRS_MCS_MAX_CCK];
	u8 flag;
};

struct cl_fw_dbg {
	char *buf;
	int len;
};

struct cl_rx_trigger_based_stats {
	bool enable;
	bool valid;
	u8 ampdu_cnt;
	u16 data_per_agg;
	u16 qos_null_per_agg;
	u32 total;
	u32 data[DBG_STATS_MAX_AGG_SIZE];
	u32 qos_null[TID_MAX + 2];
};

enum cl_iface_conf {
	CL_IFCONF_AP,
	CL_IFCONF_STA,
	CL_IFCONF_REPEATER,
	CL_IFCONF_MESH_AP,
	CL_IFCONF_MESH_ONLY,

	CL_IFCONF_MAX
};

struct cl_vendor_msg {
	u8 *buf;
	u16 len;
	u16 offset;
	bool in_process;
};

struct cl_cached_fw {
	u8 *data;
	size_t size;
};

/*
 * struct tx_queues_dma_addr - ipc layer queues addresses casted to DMA addresses
 *
 * The ipc layer points to array of txdesc, there are:
 * 'IPC_MAX_BA_SESSIONS' arrays for aggregation queues
 * 'MAX_SINGLE_QUEUES' arrayes for singletons queues
 * '1' arrays for broadcast/unicast queue
 *
 * Each one of this arrays should be copied compeletly to the FW, therefore we should
 * cast all of the arrays to dma addresses.
 */
struct tx_queues_dma_addr {
	__le32 agg[IPC_MAX_BA_SESSIONS];
	__le32 single[MAX_SINGLE_QUEUES];
	__le32 bcmc;
};

/* struct cl_ipc_tx_queues - ipc layer tx queues */
struct cl_ipc_tx_queues {
	struct txdesc *ipc_txdesc_agg[IPC_MAX_BA_SESSIONS];
	struct txdesc *ipc_txdesc_single[MAX_SINGLE_QUEUES];
	struct txdesc *ipc_txdesc_bcmc;
	/* Mapping of the TXQ's addresses to DMA addresses */
	struct tx_queues_dma_addr *queues_dma_addr;
	/* DMA address of tx_queues_dma_addr */
	u32 dma_addr;
};

/*
 * Index in txdesc - updated by host on every push, used by firmware side
 * Keep this structure aligned to 4-byte
 */
struct cl_txdesc_write_idx {
	__le32 agg[IPC_MAX_BA_SESSIONS];
	__le32 single[MAX_SINGLE_QUEUES];
	__le32 bcmc;
};

struct cl_ipc_write_idx {
	struct cl_txdesc_write_idx *txdesc_write_idx;
	u32 dma_addr;
};

struct cl_driver_ops {
	int (*msg_fw_send)(struct cl_hw *cl_hw,
			   const void *msg_params,
			   bool background);
};

/* Keep 4-bytes fields for this struct */
struct cl_ipc_ring_indices {
	volatile __le32 dtim_count[MAX_BSS_NUM];
	/* Index in rxdesc array, updated by firmware on every payload push, used by host */
	volatile __le32 rxdesc_write_idx[CL_RX_BUF_MAX];
	/* Index in rxdesc array, updated by host on rxdesc copy completion, used by firmware */
	volatile __le32 rxdesc_read_idx[CL_RX_BUF_MAX];
};

struct cl_ring_indices {
	struct cl_ipc_ring_indices *params;
	dma_addr_t dma_addr;
	struct dma_pool *pool;
};

#define CL_TEMP_PROTECT_NUM_SAMPLES 4

struct cl_temp_protect_db {
	bool force_radio_off;
	u8 duty_cycle;
	u8 test_mode_duty_cycle;
	u8 curr_idx;
	s16 last_samples[CL_TEMP_PROTECT_NUM_SAMPLES];
	unsigned long last_timestamp;
};

struct cl_temperature {
	s8 diff_internal_external;
	u8 comp_iterations;
	struct cl_temp_protect_db protect_db;
	struct task_struct *kthread;
	wait_queue_head_t wait_q;
	s16 internal_last;
	s16 external_last;
	unsigned long internal_read_timestamp;
	unsigned long external_read_timestamp;
	struct mutex mutex;
};

struct cl_temp_comp_db {
	s8 calib_temperature;
	s8 power_offset;
	s32 acc_temp_delta;
	s32 avg_temp_delta;
};

struct cl_hw {
	u8 idx; /* Global index (0-3) */
	u8 tcv_idx; /* Transceiver index (0-1) */
	u8 sx_idx;
	struct cl_tcv_conf *conf;
	const struct cl_driver_ops *ops;
	struct cl_chip *chip;
	struct ieee80211_hw *hw;
	struct cl_vif_db vif_db;
	struct cl_fw_dbg fw_dbg;
	enum cl_iface_conf iface_conf;
	u32 num_ap_started;
	u8 tx_power_version;
	struct cl_temperature temperature;
	struct cl_vif *mc_vif;
	u8 bw;
	u32 channel;
	u32 primary_freq;
	u32 center_freq;
	enum nl80211_band nl_band;
	u8 num_antennas;
	struct cl_tx_db tx_db;
	struct cl_sta_db cl_sta_db;
	struct cl_ipc_e2a_irq ipc_e2a_irq;
	struct ieee80211_supported_band sband;
	void (*ipc_host2xmac_trigger_set)(struct cl_chip *chip, u32 value);
	unsigned long drv_flags;
	unsigned long tx_disable_flags;
	struct cl_ipc_host_env *ipc_env;
	struct cl_ipc_enhanced_tim enhanced_tim;
	spinlock_t tx_lock_agg;
	spinlock_t tx_lock_cfm_agg;
	spinlock_t tx_lock_single;
	spinlock_t tx_lock_bcmc;
	struct mutex msg_tx_mutex;
	wait_queue_head_t wait_queue; /* Synchronize driver<-->firmware message exchanges */
	unsigned long cfm_flags[MAX_CFM_FLAGS];
	void *msg_cfm_params[MM_MAX + DBG_MAX]; /* Array of pointers per received msg CFM */
	bool msg_background;
	wait_queue_head_t fw_sync_wq;
	wait_queue_head_t radio_wait_queue;
	struct cl_rx_elem *rx_elems;
	struct cl_e2a_msg_elem *e2a_msg_elems;
	struct cl_dbg_elem *dbg_elems;
	struct cl_radar_elem *radar_elems;
	struct dma_pool *txdesc_pool;
	struct dma_pool *dbg_pool;
	struct dma_pool *e2a_msg_pool;
	struct dma_pool *radar_pool;
	struct cl_dbg_info dbginfo;
	struct cl_debugfs debugfs;
	struct cl_hw_asserts_info assert_info;
	bool fw_active; /* Firmware is active */
	bool fw_send_start; /* Did driver already send a start request message to firmware? */
	struct cl_tx_inject tx_inject;
	bool chandef_set;
	struct cl_dbg_data dbg_data;
	bool set_calib;
	struct cl_tx_power_info tx_pow_info[MAX_CHANNELS][MAX_ANTENNAS][MAX_POWER_LEVELS];
	struct cl_channel_info channel_info;
	struct cl_phy_data_info phy_data_info;
	u32 mask_hi;
	u32 mask_low;
	struct delayed_work maintenance_slow;
	struct delayed_work maintenance_fast;
	struct cl_timer dual_nav_timer;
	struct cl_timer bsrp_maintenance_timer;
	struct tasklet_struct tx_task;
	struct list_head list_sched_q_agg;
	struct list_head list_sched_q_single;
	struct cl_ate_db ate_db;
	struct cl_vw_db vw_db;
	struct cl_req_agg_db req_agg_db[IPC_MAX_BA_SESSIONS];
	u8 req_agg_queues;
	u8 used_agg_queues;
	u16 max_agg_tx_q_size;
	bool wd_restart_drv;
	bool is_stop_context;
	struct workqueue_struct *drv_workqueue;
	struct cl_amsdu_rx_state amsdu_rx_state;
	struct cl_tx_queues *tx_queues;
	struct cl_ipc_tx_queues ipc_tx_queues;
	struct cl_ipc_write_idx ipc_write_idx;
	struct kmem_cache *sw_txhdr_cache;
	struct kmem_cache *amsdu_txhdr_cache;
	u32 radio_stats[CL_RADIO_ERRORS_MAX];
	time64_t radio_stats_start_time;
	short radio_noise_floor;
	short radio_avg_noise_floor;
	short radio_min_noise_floor;
	short radio_max_noise_floor;
	atomic_t tx_packet_count;
	struct cl_rx_path_info rx_info;
	struct cl_prot_mode prot_mode;
	struct cl_cma_table cma_table;
	struct cl_agg_cfm_queue agg_cfm_queues[IPC_MAX_BA_SESSIONS];
	struct cl_single_cfm_queue single_cfm_queues[MAX_SINGLE_QUEUES];
	struct cl_single_cfm_queue bcmc_cfm_queue;
	atomic_t radio_lock;
	struct cl_assoc_queue assoc_queue;
	struct cl_agc_cd agc_cd;
	struct list_head sta_capab_list;
	rwlock_t sta_capab_list_lock;
	struct cl_wrs_db wrs_db;
	struct cl_traffic_main traffic_db;
	struct cl_power_db power_db;
	struct workqueue_struct *ageout_workqueue;
	struct cl_bf_db bf_db;
	struct cl_edca_db edca_db;
	struct cl_env_det env_det;
	struct cl_vns_db vns_db;
	struct cl_str_offload_env str_offload_env;
	struct cl_dma_accessed fw_remote_rom;
	struct cl_recovery_db recovery_db;
	struct list_head rx_msg_head;
	struct list_head dbg_msg_head;
	struct list_head single_pkt_req_msg_head;
	struct list_head agg_pkt_req_msg_head;
	spinlock_t rx_msg_lock;
	spinlock_t dbg_msg_lock;
	spinlock_t single_pkt_req_msg_lock;
	spinlock_t agg_pkt_req_msg_lock;
	struct cl_radar_queue radar_queue;
	struct tasklet_struct radar_tasklet;
	struct cl_cached_fw cached_fw;
	s8 rx_sensitivity[MAX_ANTENNAS];
	struct cl_cca_db cca_db;
	struct cl_noise_db noise_db;
	struct cl_temp_comp_db temp_comp_db;
	struct cl_sounding_db sounding;
	struct cl_dyn_mcast_rate dyn_mcast_rate;
	struct cl_dyn_bcast_rate dyn_bcast_rate;
	struct cl_rx_sens_db rx_sens_db;
	bool entry_fixed_rate;
	struct cl_vlan_dscp vlan_dscp;
	s8 snr_timer;
	unsigned long last_tbtt_irq;
	u32 tbtt_cnt;
	u8 mesh_tbtt_div;
	struct tasklet_struct tx_mesh_bcn_task;
	u32 fw_recovery_cntr;
	u32 rx_filter;
	u8 bw_sig_debug_mode;
	struct list_head head_amsdu_txhdr_pool;
	struct list_head head_sw_txhdr_pool;
	spinlock_t lock_sw_txhdr_pool;
	struct sk_buff_head rx_skb_queue;
	struct tasklet_struct rx_tasklet;
	struct tasklet_struct rx_resched_tasklet;
	struct cl_tx_packet_cntr tx_packet_cntr;
	struct cl_cpu_cntr cpu_cntr;
	struct cl_power_table_info power_table_info;
	struct cl_tf_info tf_info;
	struct cl_bsr_info bsr_info;
	struct ieee80211_sband_iftype_data iftype_data[3];
	struct cl_power_truncate pwr_trunc;
	struct mutex set_channel_mutex;
	unsigned long umh_last_call_timestamp;
	u8 igmp_debug_level;
	u8 radio_status;
	bool iq_cal_ready;
	s8 rssi_simulate;
	u8 ieee80211w;
	u64 bss_color_blacklist; /* Bitmask of colors blacklist */
	struct cl_twt_db twt_db;
	struct mac_address addresses[MAX_BSS_NUM];
	struct cl_rx_stats *rx_stats; /* RX statistics for production mode. */
	spinlock_t lock_stats;
	u16 n_addresses;
	struct sock *nl_sock;
	u8 txamsdu_en;
	bool reg_dbg;
	struct cl_rx_trigger_based_stats tb_stats;
	struct cl_tf_params tf_params;
	bool idle_async_set;
	struct cl_ul_rssi_db ul_rssi_db;
	struct cl_vendor_msg vendor_msg;
	struct cl_timer vendor_timer;
	bool bsrp_dbg;
	u8 *single_cfm_virt_base_addr;
	dma_addr_t single_cfm_dma_base_addr;
	u32 single_cfm_read_idx;
	u32 single_cfm_write_idx;
	struct tasklet_struct tx_single_cfm_tasklet;
	struct tasklet_struct rx_msg_tasklet;
	struct tasklet_struct dbg_tasklet;
	struct tasklet_struct single_pkt_req_msg_tasklet;
	struct tasklet_struct agg_pkt_req_msg_tasklet;
	u8 first_riu_chain;
	u8 last_riu_chain;
	struct cl_calib_db *calib_db;
	struct cl_iq_dcoc_data_info iq_dcoc_data_info;
	struct cl_calib_iq_plan *calib_iq_plan;
	struct cl_calib_params calib_params;
	u8 sw_scan_in_progress;
	bool calib_runtime_needed;
	struct cl_ring_indices ring_indices;
	bool sta_del_force_trig;
};
#endif /* CL_HW_H */
