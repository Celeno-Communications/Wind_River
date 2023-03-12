/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_TCV_CONFIG_H
#define CL_TCV_CONFIG_H

#include "def.h"
#include "cl_ipc_shared.h"
#include "cl_wrs_db.h"
#include "cl_rx_sens.h"
#include "cl_edca.h"
#include "string.h"
#include "cl_sounding.h"

#define CL_ENV_DET_THR_CNT 6
#define CL_INVALID_TCV_IDX 0xFF

#define CL_DEFAULT_HAL_IDLE_TIMEOUT 16000  /* Idle request - 16ms */
#define CL_TX_DEFAULT_AC0_TIMEOUT   500000 /* Background - 500ms */
#define CL_TX_DEFAULT_AC1_TIMEOUT   300000 /* Best effort - 300ms */
#define CL_TX_DEFAULT_AC2_TIMEOUT   200000 /* Video - 200ms */
#define CL_TX_DEFAULT_AC3_TIMEOUT   200000 /* Voice - 200ms */
#define CL_TX_DEFAULT_BCN_TIMEOUT   150000 /* Beacon - 150ms */

/* Minimal MPDU spacing we support in TX - correspond to FW NX_TX_MPDU_SPACING */
#define CL_TX_MPDU_SPACING_INVALID 0xFF

enum {
	CL_RATE_FALLBACK_COUNT_SU,
	CL_RATE_FALLBACK_COUNT_MU,
	CL_RATE_FALLBACK_RETRY_COUNT_THR,
	CL_RATE_FALLBACK_BA_PER_THR,
	CL_RATE_FALLBACK_BA_NOT_RECEIVED_THR,
	CL_RATE_FALLBACK_DISABLE_MCS,

	CL_RATE_FALLBACK_MAX,
};

struct cl_tcv_conf {
	u8 ce_bss_num;
	s8 ce_debug_level;
	bool ce_radio_on;
	bool ce_ps_ctrl_enabled;
	u8 ha_channel;
	u8 ha_ieee80211w[MAX_BSS_NUM];
	u8 ws_ieee80211w;
	bool ha_ieee80211h;
	u8 ha_short_guard_interval;
	u8 ha_max_mpdu_len;
	u8 ha_vht_max_ampdu_len_exp;
	u32 ha_beacon_int;
	s8 ce_dsp_code[STR_LEN_32B];
	s8 ce_dsp_data[STR_LEN_32B];
	s8 ce_dsp_external_data[STR_LEN_32B];
	bool ce_uapsd_en;
	bool ci_eirp_regulatory_en;
	bool ci_agg_tx;
	bool ci_agg_rx;
	bool ce_txldpc_en;
	bool ce_ht_rxldpc_en;
	bool ce_vht_rxldpc_en;
	bool ce_he_rxldpc_en;
	bool ci_cs_required;
	bool ci_rx_sens_en;
	s8 ci_rx_sensitivity_prod[MAX_ANTENNAS];
	s8 ci_rx_sensitivity_op[MAX_ANTENNAS];
	s8 ci_rx_sens_rssi[RX_SENS_THR_MAX];
	s8 ci_rx_sens_val[RX_SENS_VAL_MAX];
	bool ci_cck_en;
	bool ci_min_he_en;
	u8 ce_cck_tx_ant_mask;
	u8 ce_cck_rx_ant_mask;
	u8 ce_rx_nss;
	u8 ce_tx_nss;
	u8 ce_num_antennas;
	u8 ce_wireless_mode;
	bool ha_wmm_enabled[MAX_BSS_NUM];
	u16 ce_max_agg_size_tx;
	u16 ce_max_agg_size_rx;
	u16 ci_rx_ampdu_window_size[TID_MAX];
	bool ce_rxamsdu_en;
	u8 ce_txamsdu_en;
	u16 ci_tx_amsdu_min_data_rate;
	u8 ci_rx_amsdu_max_packets;
	u8 ci_tx_sw_amsdu_max_packets;
	u16 ci_tx_amsdu_min_len_x2; /* For step A only */
	u16 ci_tx_amsdu_min_len_x3; /* For step A only */
	u16 ci_tx_packet_limit;
	u16 ci_sw_txhdr_pool;
	u16 ci_amsdu_txhdr_pool;
	u16 ci_tx_queue_size_agg;
	u16 ci_tx_queue_size_single;
	bool ci_traffic_mon_en;
	u16 ci_ipc_rxbuf_size[CL_RX_BUF_MAX];
	u16 ce_max_retry;
	u8 ce_short_retry_limit;
	u8 ce_long_retry_limit;
	u8 ci_assoc_auth_retry_limit;
	u8 ce_channel_bandwidth;
	u8 ce_iface_type[MAX_BSS_NUM];
	u8 ha_hw_mode;
	s8 ce_temp_comp_slope;
	u32 ce_sta_age_out;
	u32 ci_fw_dbg_severity;
	u32 ci_fw_dbg_module;
	u8 ci_lcu_dbg_cfg_inx;
	u8 ci_dsp_lcu_mode;
	u32 ci_hal_idle_to;
	u32 ci_tx_ac0_to;
	u32 ci_tx_ac1_to;
	u32 ci_tx_ac2_to;
	u32 ci_tx_ac3_to;
	u32 ci_tx_bcn_to;
	s8 ce_hardware_power_table[STR_LEN_256B];
	s8 ce_arr_gain[STR_LEN_16B];
	s8 ce_bf_gain[STR_LEN_16B];
	s8 ce_ant_gain[STR_LEN_32B];
	s8 ce_ant_gain_36_64[STR_LEN_32B];
	s8 ce_ant_gain_100_140[STR_LEN_32B];
	s8 ce_ant_gain_149_165[STR_LEN_32B];
	s8 ci_min_ant_pwr[STR_LEN_32B];
	s8 ci_bw_factor[STR_LEN_32B];
	bool ce_radio_traffic_stats_enable;
	u16 ce_radio_traffic_stats_rate;
	u16 ce_radio_traffic_stats_interval;
	u8 ce_mcast_rate;
	bool ce_dyn_mcast_rate_en;
	bool ce_dyn_bcast_rate_en;
	u8 ce_default_mcs_ofdm;
	u8 ce_default_mcs_cck;
	s8 ce_snr_event_thr;
	u8 ce_wl_event_logger;
	bool ce_prot_log_nav_en;
	u8 ce_prot_mode;
	u8 ce_prot_rate_format;
	u8 ce_prot_rate_mcs;
	u8 ce_prot_rate_pre_type;
	u8 ce_bw_signaling_mode;
	u8 ci_dyn_cts_sta_thr;
	u8 ci_vns_pwr_limit;
	u8 ci_vns_pwr_mode;
	s8 ci_vns_rssi_auto_resp_thr;
	u8 ci_iqdc_dpd_mode;
	s8 ci_vns_rssi_thr;
	s8 ci_vns_rssi_hys;
	u16 ci_vns_maintenance_time;
	u16 ce_bcn_tx_path_min_time;
	bool ci_backup_bcn_en;
	bool ce_tx_txop_cut_en;
	u8 ci_bcns_flushed_cnt_thr;
	bool ci_phy_err_prevents_phy_dump;
	u8 ci_tx_rx_delay;
	u8 ci_fw_assert_time_diff_sec;
	u8 ci_fw_assert_storm_detect_thd;
	u32 ce_hw_assert_time_max;
	u8 ce_fw_watchdog_mode;
	u8 ce_fw_watchdog_limit_count;
	u32 ce_fw_watchdog_limit_time;
	bool ce_m2u_enable;
	s8 ci_rx_remote_cpu_drv;
	u16 ci_pending_queue_size;
	u8 ce_tx_power_control;
	s8 ci_fixed_tx_power;
	u32 ce_promiscuous_timeout;
	s8 ce_extension_channel;
	/* Power Per MCS values - 6g */
	s8 ce_ppmcs_offset_he_6g[WRS_MCS_MAX_HE];
	/* Power Per MCS values - 5g */
	s8 ce_ppmcs_offset_he_36_64[WRS_MCS_MAX_HE];
	s8 ce_ppmcs_offset_he_100_140[WRS_MCS_MAX_HE];
	s8 ce_ppmcs_offset_he_149_165[WRS_MCS_MAX_HE];
	s8 ce_ppmcs_offset_ht_vht_36_64[WRS_MCS_MAX_VHT];
	s8 ce_ppmcs_offset_ht_vht_100_140[WRS_MCS_MAX_VHT];
	s8 ce_ppmcs_offset_ht_vht_149_165[WRS_MCS_MAX_VHT];
	s8 ce_ppmcs_offset_ofdm_36_64[WRS_MCS_MAX_OFDM];
	s8 ce_ppmcs_offset_ofdm_100_140[WRS_MCS_MAX_OFDM];
	s8 ce_ppmcs_offset_ofdm_149_165[WRS_MCS_MAX_OFDM];
	/* Power Per MCS values - 24g */
	s8 ce_ppmcs_offset_he[WRS_MCS_MAX_HE];
	s8 ce_ppmcs_offset_ht[WRS_MCS_MAX_HT];
	s8 ce_ppmcs_offset_ofdm[WRS_MCS_MAX_OFDM];
	s8 ce_ppmcs_offset_cck[WRS_MCS_MAX_CCK];
	/* Power Per BW values - all bands */
	s8 ce_ppbw_offset[CHNL_BW_MAX];
	bool ce_power_offset_prod_en;
	bool ce_bf_en;
	u8 ci_bf_max_nss;
	u16 ce_sounding_interval_coefs[SOUNDING_INTERVAL_COEF_MAX];
	u8 ci_rate_fallback[CL_RATE_FALLBACK_MAX];
	u32 ci_env_det_thr[CL_ENV_DET_THR_CNT];
	u16 ci_env_det_flags;
	u16 ce_rx_pkts_budget;
	u8 ci_band_num;
	bool ci_mult_ampdu_in_txop_en;
	u16 ce_dynamic_edca[EDCA_MAX_PARAMS];
	u8 ce_wmm_aifsn[AC_MAX];
	u8 ce_wmm_cwmin[AC_MAX];
	u8 ce_wmm_cwmax[AC_MAX];
	u16 ce_wmm_txop[AC_MAX];
	u8 ci_su_force_min_spacing;
	u8 ci_mu_force_min_spacing;
	u8 ci_tf_mac_pad_dur;
	u32 ci_cca_src;
	u32 ci_cca_timeout;
	bool ci_vw_en;
	bool ci_vw_start_ba_session;
	s8 ci_vw_delta_rssi;
	u32 ci_vw_delta_time;
	u16 ce_tx_ba_session_timeout;
	u8 ci_wrs_max_bw;
	u8 ci_wrs_min_bw;
	s8 ci_wrs_fixed_rate[WRS_FIXED_PARAM_MAX];
	u8 ce_he_mcs_nss_supp_tx[WRS_SS_MAX];
	u8 ce_he_mcs_nss_supp_rx[WRS_SS_MAX];
	u8 ce_vht_mcs_nss_supp_tx[WRS_SS_MAX];
	u8 ce_vht_mcs_nss_supp_rx[WRS_SS_MAX];
	u8 ci_pe_duration;
	u8 ci_pe_duration_bcast;
	u32 ci_umh_diff_time_ms;
	u8 ci_gain_update_enable;
	u8 ci_mcs_sig_b;
	u8 ci_mcs_min;
	u8 ci_mcs_max;
	u8 ci_spp_ksr_value;
	bool ci_rx_padding_en;
	bool ci_stats_en;
	bool ci_bar_disable;
	bool ci_ofdm_only;
	bool ci_hw_bsr;
	bool ci_drop_to_lower_bw;
	bool ci_force_icmp_single;
	bool ce_twt_en;
	bool ce_bsr_en;
	bool ce_bsrp_en;
	bool ce_wrs_rx_en;
	u32 ce_twt_default_interval;
	u32 ce_twt_default_min_wake_duration;
	u8 ce_twt_max_sessions;
	u8 ci_hr_factor[CHNL_BW_MAX];
	bool ci_csd_en;
	bool ci_signal_extension_en;
	bool ce_dscp_vlan_enable[MAX_BSS_NUM];
	u8 ce_up0_7_default_vlan_user_prio[MAX_BSS_NUM];
	u8 ce_up0_7_layer_based[MAX_BSS_NUM];
	s8 ce_dscp_to_up0_7dec0[STR_LEN_128B];
	s8 ce_dscp_to_up0_7dec1[STR_LEN_128B];
	s8 ce_dscp_to_up0_7dec2[STR_LEN_128B];
	s8 ce_dscp_to_up0_7dec3[STR_LEN_128B];
	s8 ce_dscp_to_up0_7dec4[STR_LEN_128B];
	s8 ce_dscp_to_up0_7dec5[STR_LEN_128B];
	s8 ce_dscp_to_up0_7dec6[STR_LEN_128B];
	s8 ce_dscp_to_up0_7dec7[STR_LEN_128B];
	s8 ce_vlan_to_up0_7dec0[STR_LEN_128B];
	s8 ce_vlan_to_up0_7dec1[STR_LEN_128B];
	s8 ce_vlan_to_up0_7dec2[STR_LEN_128B];
	s8 ce_vlan_to_up0_7dec3[STR_LEN_128B];
	s8 ce_vlan_to_up0_7dec4[STR_LEN_128B];
	s8 ce_vlan_to_up0_7dec5[STR_LEN_128B];
	s8 ce_vlan_to_up0_7dec6[STR_LEN_128B];
	s8 ce_vlan_to_up0_7dec7[STR_LEN_128B];
	bool ci_vht_cap_24g;
	bool ce_omi_en;
	u32 ci_tx_digital_gain; /* Step B */
	u32 ci_tx_dig_gain_single_ant; /* Step A */
	u32 ci_tx_dig_gain_all_ants; /* Step A */
	bool ci_mac_clk_gating_en;
	bool ci_phy_clk_gating_en;
	bool ci_imaging_blocker;
	u8 ci_ndp_tx_chain_mask;
	u8 ci_ndp_tx_bw;
	u8 ci_ndp_tx_format;
	u8 ci_ndp_tx_num_ltf;
	s8 ci_cca_ed_rise_thr_dbm;
	s8 ci_cca_ed_fall_thr_dbm;
	u8 ci_cca_cs_en;
	u8 ci_cca_modem_en;
	u8 ci_cca_main_ant;
	u8 ci_cca_second_ant;
	u8 ci_cca_flag0_ctrl;
	u8 ci_cca_flag1_ctrl;
	u8 ci_cca_flag2_ctrl;
	u8 ci_cca_flag3_ctrl;
	s8 ci_cca_gi_rise_thr_dbm;
	s8 ci_cca_gi_fall_thr_dbm;
	s8 ci_cca_gi_pow_lim_dbm;
	u16 ci_cca_ed_en;
	u8 ci_cca_gi_en;
	bool ci_trigger_base_en;
	bool ci_rx_he_mu_ppdu;
	u8 ci_offload_reorder_mode;
	u8 ci_calib_ant_tx[MAX_ANTENNAS];
	u8 ci_calib_ant_rx[MAX_ANTENNAS];
	/* driver api conf */
	u8 ci_calib_conf_rx_gain_upper_limit;
	u8 ci_calib_conf_rx_gain_lower_limit;
	u8 ci_calib_conf_tone_vector_20bw[IQ_NUM_TONES_REQ];
	u8 ci_calib_conf_tone_vector_40bw[IQ_NUM_TONES_REQ];
	u8 ci_calib_conf_tone_vector_80bw[IQ_NUM_TONES_REQ];
	u8 ci_calib_conf_tone_vector_160bw[IQ_NUM_TONES_REQ];
	u32 ci_calib_conf_gp_rad_trshld;
	u32 ci_calib_conf_ga_lin_upper_trshld;
	u32 ci_calib_conf_ga_lin_lower_trshld;
	u8 ci_calib_conf_singletons_num;
	u8 ci_calib_conf_comp_fiter_len;
	u16 ci_calib_conf_rampup_time;
	u16 ci_calib_conf_lo_coarse_step;
	u16 ci_calib_conf_lo_fine_step;
	u8 ci_usb_single_queue_for_agg_en;
	u8 ci_cap_bandwidth;
	/* New NVRAM parameters must be added to cl_tcv_config_print() */
};

struct cl_hw;

int cl_tcv_config_read(struct cl_hw *cl_hw);
int cl_tcv_config_set(struct cl_hw *cl_hw, char *buf, size_t size);
u8 cl_tcv_config_get_num_ap(struct cl_hw *cl_hw);
int cl_tcv_config_alloc(struct cl_hw *cl_hw);
void cl_tcv_config_free(struct cl_hw *cl_hw);
void cl_tcv_config_print(struct cl_hw *cl_hw);

#endif /* CL_TCV_CONFIG_H */
