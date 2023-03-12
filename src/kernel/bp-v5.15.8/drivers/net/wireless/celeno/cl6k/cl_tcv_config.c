// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/slab.h>
#include <linux/moduleparam.h>
#include <linux/uaccess.h>
#include "cl_tcv_config.h"
#include "file.h"
#include "cl_utils.h"
#include "cl_prot_mode.h"
#include "chip.h"
#include "cl_tx_amsdu.h"
#include "cl_recovery.h"
#include "cl_band.h"
#include "cl_vns.h"
#include "cl_age_out.h"
#include "string.h"
#include "cl_twt.h"
#include "cl_rx.h"
#include "cl_cap.h"
#include "cl_rx_usb.h"
#include "cl_config.h"
#include "cl_calib_iq.h"

#define TX_BCN_PENDING_CHAIN_MIN_TIME 10 /* Usec */

#define CL_MAX_NUM_OF_RETRY 15

/*
 * the calculation is conducted as follow:
 * 1500 - max ethernet frame
 * conversion of ETH to MSDU:
 * 1500[eth max] - 12[hdr frame] + 14[msdu frame] + 8[llc snap] + 4[MSDU Padding] = 1514
 * MSDU + WLAN HDR = 1514[MSDU MAX] + 36[MAX WLAN HDR] = 1550
 * 2 bytes is being PADDED by SKB alloc for alignment.
 * 18 byte encryption
 * sizeof(struct hw_rxhdr)
 */
#define IPC_RXBUF_SIZE (1570 + sizeof(struct hw_rxhdr))

static struct cl_tcv_conf conf = {
	.ce_bss_num = 1,
	.ce_debug_level = DBG_LVL_ERROR,
	.ce_radio_on = true,
	.ce_ps_ctrl_enabled = true,
	.ha_channel = 0,
	.ha_ieee80211w = {0},
	.ws_ieee80211w = 0,
	.ha_ieee80211h = false,
	.ha_short_guard_interval = 1,
	.ha_max_mpdu_len = IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_7991,
	.ha_vht_max_ampdu_len_exp = IEEE80211_VHT_MAX_AMPDU_1024K,
	.ha_beacon_int = 100,
	.ce_dsp_code = "fwC.hex",
	.ce_dsp_data = "fwD.hex",
	.ce_dsp_external_data = "fwD.ext.hex",
	.ce_uapsd_en = true,
	.ci_eirp_regulatory_en = true,
	.ci_agg_tx = true,
	.ci_agg_rx = true,
	.ce_txldpc_en = true,
	.ce_ht_rxldpc_en = true,
	.ce_vht_rxldpc_en = true,
	.ce_he_rxldpc_en = true,
	.ci_cs_required = false,
	.ci_rx_sens_en = true,
	.ci_rx_sens_rssi = {-50, -60, -75},
	.ci_rx_sens_val = {-95, -95, -95, -99},
	.ci_rx_sensitivity_prod = {-100, -100},
	.ci_rx_sensitivity_op = {-100, -100},
	.ci_cck_en = false,
	.ci_min_he_en = false,
	.ce_cck_tx_ant_mask = 0x1,
	.ce_cck_rx_ant_mask = 0x1,
	.ce_rx_nss = 2,
	.ce_tx_nss = 2,
	.ce_num_antennas = 2,
	.ce_wireless_mode = WIRELESS_MODE_HT_VHT_HE,
	.ha_wmm_enabled = {1, 1, 1, 1, 1, 1, 1, 1},
	.ce_max_agg_size_tx = IEEE80211_MAX_AMPDU_BUF,
	.ce_max_agg_size_rx = IEEE80211_MAX_AMPDU_BUF_HT,
	.ci_rx_ampdu_window_size = {
		IEEE80211_MAX_AMPDU_BUF_HT, IEEE80211_MAX_AMPDU_BUF_HT,
		IEEE80211_MAX_AMPDU_BUF_HT, IEEE80211_MAX_AMPDU_BUF_HT,
		IEEE80211_MAX_AMPDU_BUF_HT, IEEE80211_MAX_AMPDU_BUF_HT,
		IEEE80211_MAX_AMPDU_BUF_HT, IEEE80211_MAX_AMPDU_BUF_HT,
	},
	.ce_rxamsdu_en = true,
	.ce_txamsdu_en = CL_AMSDU_TX_PAYLOAD_MAX,
	.ci_tx_amsdu_min_data_rate = 26, /* 26Mbps (= BW 20, NSS 0, MCS 3, GI 0) */
	.ci_rx_amsdu_max_packets = RX_MAX_MSDU_IN_AMSDU,
	.ci_tx_sw_amsdu_max_packets = 0,
	.ci_tx_amsdu_min_len_x2 = CL_TX_AMSDU_MIN_LEN_X2,
	.ci_tx_amsdu_min_len_x3 = CL_TX_AMSDU_MIN_LEN_X3,
	.ci_tx_packet_limit = 5000,
	.ci_sw_txhdr_pool = 0,
	.ci_amsdu_txhdr_pool = 0,
	.ci_tx_queue_size_agg = 500,
	.ci_tx_queue_size_single = 50,
	.ci_traffic_mon_en = false,
	.ci_ipc_rxbuf_size = {IPC_RXBUF_SIZE, IPC_RXBUF_SIZE},
	.ce_max_retry = 8,
	.ce_short_retry_limit = 4,
	.ce_long_retry_limit = 4,
	.ci_assoc_auth_retry_limit = 0,
	.ce_channel_bandwidth = 0,
	.ce_iface_type = {NL80211_IFTYPE_AP, 0, 0, 0, 0, 0, 0, 0},
	.ha_hw_mode = HW_MODE_A,
	.ce_temp_comp_slope = 8,
	.ce_sta_age_out = 300, /* 5 min */
	.ci_fw_dbg_severity = CL_MACFW_DBG_SEV_WARNING,
	.ci_fw_dbg_module = 0x0FFFFF,
	.ci_lcu_dbg_cfg_inx = 4,
	.ci_dsp_lcu_mode = 1,
	.ci_hal_idle_to = CL_DEFAULT_HAL_IDLE_TIMEOUT,
	.ci_tx_ac0_to = CL_TX_DEFAULT_AC0_TIMEOUT,
	.ci_tx_ac1_to = CL_TX_DEFAULT_AC1_TIMEOUT,
	.ci_tx_ac2_to = CL_TX_DEFAULT_AC2_TIMEOUT,
	.ci_tx_ac3_to = CL_TX_DEFAULT_AC3_TIMEOUT,
	.ci_tx_bcn_to = CL_TX_DEFAULT_BCN_TIMEOUT,
	.ce_hardware_power_table = {0},
	.ce_arr_gain = "0,3",
	.ce_bf_gain = "0",
	.ce_ant_gain = "0",
	.ce_ant_gain_36_64 = "0",
	.ce_ant_gain_100_140 = "0",
	.ce_ant_gain_149_165 = "0",
	.ci_min_ant_pwr = "0",
	.ci_bw_factor = "0,0,0,0",
	.ce_radio_traffic_stats_enable = false,
	.ce_radio_traffic_stats_rate = 30,
	.ce_radio_traffic_stats_interval = 30,
	.ce_mcast_rate = 0,
	.ce_dyn_mcast_rate_en = false,
	.ce_dyn_bcast_rate_en = false,
	.ce_default_mcs_ofdm = 0,
	.ce_default_mcs_cck = 0,
	.ce_snr_event_thr = -100,
	.ce_wl_event_logger = 0,
	.ce_prot_log_nav_en = false,
	.ce_prot_mode = TXL_NO_PROT,
	.ce_prot_rate_format = 1,
	.ce_prot_rate_mcs = 4,
	.ce_prot_rate_pre_type = 0,
	.ce_bw_signaling_mode = 0,
	.ci_dyn_cts_sta_thr = 2,
	.ci_vns_pwr_limit = 13,
	.ci_vns_pwr_mode = VNS_MODE_ALL,
	.ci_vns_rssi_auto_resp_thr = -35,
	.ci_iqdc_dpd_mode = 0,
	.ci_vns_rssi_thr = -35,
	.ci_vns_rssi_hys = 3,
	.ci_vns_maintenance_time = 2000,
	.ce_bcn_tx_path_min_time = 1000,
	.ci_backup_bcn_en = true,
	.ce_tx_txop_cut_en = true,
	.ci_bcns_flushed_cnt_thr = 9,
	.ci_phy_err_prevents_phy_dump = false,
	.ci_tx_rx_delay = 0,
	.ci_fw_assert_time_diff_sec = 5,
	.ci_fw_assert_storm_detect_thd = 15,
	.ce_hw_assert_time_max  = CL_HW_ASSERT_TIME_MAX,
	.ce_fw_watchdog_mode = FW_WD_INTERNAL_RECOVERY,
	.ce_fw_watchdog_limit_count = 5,
	.ce_fw_watchdog_limit_time = 30 * 1000, /* Msecs */
	.ce_m2u_enable = true,
	.ci_rx_remote_cpu_drv = -1,
	.ci_pending_queue_size = 500,
	.ce_tx_power_control = 100,
	.ci_fixed_tx_power = -10,
	.ce_promiscuous_timeout = 0,
	.ce_extension_channel = 1,
	/* 6G */
	.ce_ppmcs_offset_he_6g = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/* 5G */
	.ce_ppmcs_offset_he_36_64 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	.ce_ppmcs_offset_he_100_140 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	.ce_ppmcs_offset_he_149_165 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	.ce_ppmcs_offset_ht_vht_36_64 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	.ce_ppmcs_offset_ht_vht_100_140 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	.ce_ppmcs_offset_ht_vht_149_165 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	.ce_ppmcs_offset_ofdm_36_64 = {0, 0, 0, 0, 0, 0, 0, 0},
	.ce_ppmcs_offset_ofdm_100_140 = {0, 0, 0, 0, 0, 0, 0, 0},
	.ce_ppmcs_offset_ofdm_149_165 = {0, 0, 0, 0, 0, 0, 0, 0},
	/* 24G */
	.ce_ppmcs_offset_he = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	.ce_ppmcs_offset_ht = {0, 0, 0, 0, 0, 0, 0, 0},
	.ce_ppmcs_offset_ofdm = {0, 0, 0, 0, 0, 0, 0, 0},
	.ce_ppmcs_offset_cck = {0, 0, 0, 0},
	.ce_ppbw_offset = {0, 0, 0, 0},
	.ce_power_offset_prod_en = true,
	.ce_bf_en = 0,
	.ci_bf_max_nss = 2,
	.ce_sounding_interval_coefs = {100, 4, 50, 500},
	.ci_rate_fallback = {4, 2, 2, 25, 2, 1},
	.ci_env_det_thr = {MAX_CCA_CLEAN_DEF, MAX_CCA_AVERAGE_DEF, MAX_CCA_NOISY_DEF,
		MIN_CCA_CLEAN_DEF, MIN_CCA_AVERAGE_DEF, MIN_CCA_NOISY_DEF},
	.ci_env_det_flags = 0,
	.ce_rx_pkts_budget = 512,
	.ci_band_num = 5,
	.ci_mult_ampdu_in_txop_en = false,
	.ce_dynamic_edca = {0, 0, 0, 0},
	.ce_wmm_aifsn = {3, 7, 1, 1},
	.ce_wmm_cwmin = {4, 4, 3, 2},
	.ce_wmm_cwmax = {10, 10, 4, 3},
	.ce_wmm_txop = {0, 0, 94, 47},
	.ci_su_force_min_spacing = CL_TX_MPDU_SPACING_INVALID,
	.ci_mu_force_min_spacing = CL_TX_MPDU_SPACING_INVALID,
	.ci_tf_mac_pad_dur = 0,
	.ci_cca_src = 0x0ffa0107,
	.ci_cca_timeout = 300,
	.ci_vw_en = false,
	.ci_vw_start_ba_session = true,
	.ci_vw_delta_rssi = 25,
	.ci_vw_delta_time = 3000,
	.ce_tx_ba_session_timeout = 30000,
	.ci_wrs_max_bw = CHNL_BW_160,
	.ci_wrs_min_bw = CHNL_BW_20,
	.ci_wrs_fixed_rate = {-1, -1, -1, -1, -1},
	.ce_he_mcs_nss_supp_tx = {11, 11},
	.ce_he_mcs_nss_supp_rx = {11, 11},
	.ce_vht_mcs_nss_supp_tx = {9, 9},
	.ce_vht_mcs_nss_supp_rx = {9, 9},
	.ci_pe_duration = U8_MAX,
	.ci_pe_duration_bcast = PPE_16US,
	.ci_umh_diff_time_ms = 0,
	.ci_gain_update_enable = 1,
	.ci_mcs_sig_b = 0,
	.ci_mcs_min = 0,
	.ci_mcs_max = WRS_MCS_MAX - 1,
	.ci_spp_ksr_value = 1,
	.ci_rx_padding_en = false,
	.ci_stats_en = false,
	.ci_bar_disable = false,
	.ci_ofdm_only = true,
	.ci_hw_bsr = false,
	.ci_drop_to_lower_bw = false,
	.ci_force_icmp_single = false,
	.ce_twt_en = false,
	.ce_bsr_en = false,
	.ce_bsrp_en = false,
	.ce_wrs_rx_en = false,
	.ce_twt_default_interval = CL_TWT_DEFAULT_INTERVAL_US,
	.ce_twt_default_min_wake_duration = CL_TWT_DEFAULT_MIN_WAKE_DURATION_US,
	.ce_twt_max_sessions = CL_TWT_MAX_SESSIONS,
	.ci_hr_factor = {1, 1, 1, 1},
	.ci_csd_en = false,
	.ci_signal_extension_en = false,
	.ce_dscp_vlan_enable = {true},
	.ce_up0_7_default_vlan_user_prio = {0},
	.ce_up0_7_layer_based = {0},
	.ce_dscp_to_up0_7dec0 = "0,8,16,24,32,40,48,56",
	.ce_dscp_to_up0_7dec1 = "0,8,16,24,32,40,48,56",
	.ce_dscp_to_up0_7dec2 = "0,8,16,24,32,40,48,56",
	.ce_dscp_to_up0_7dec3 = "0,8,16,24,32,40,48,56",
	.ce_dscp_to_up0_7dec4 = "0,8,16,24,32,40,48,56",
	.ce_dscp_to_up0_7dec5 = "0,8,16,24,32,40,48,56",
	.ce_dscp_to_up0_7dec6 = "0,8,16,24,32,40,48,56",
	.ce_dscp_to_up0_7dec7 = "0,8,16,24,32,40,48,56",
	.ce_vlan_to_up0_7dec0 = "7,5,6,4,3,1,1,0",
	.ce_vlan_to_up0_7dec1 = "7,5,6,4,3,1,1,0",
	.ce_vlan_to_up0_7dec2 = "7,5,6,4,3,1,1,0",
	.ce_vlan_to_up0_7dec3 = "7,5,6,4,3,1,1,0",
	.ce_vlan_to_up0_7dec4 = "7,5,6,4,3,1,1,0",
	.ce_vlan_to_up0_7dec5 = "7,5,6,4,3,1,1,0",
	.ce_vlan_to_up0_7dec6 = "7,5,6,4,3,1,1,0",
	.ce_vlan_to_up0_7dec7 = "7,5,6,4,3,1,1,0",
	.ci_vht_cap_24g = false,
	.ce_omi_en = false,
	.ci_tx_digital_gain = 0x28282828,
	.ci_tx_dig_gain_single_ant = 0x14141414,
	.ci_tx_dig_gain_all_ants = 0x28282828,
	.ci_mac_clk_gating_en = true,
	.ci_phy_clk_gating_en = true,
	.ci_imaging_blocker = false,
	.ci_ndp_tx_chain_mask = NDP_TX_PHY0,
	.ci_ndp_tx_bw = CHNL_BW_MAX,
	.ci_ndp_tx_format = FORMATMOD_NON_HT,
	.ci_ndp_tx_num_ltf = LTF_X1,
	.ci_cca_ed_rise_thr_dbm = -62,
	.ci_cca_ed_fall_thr_dbm = -65,
	.ci_cca_cs_en = 1,
	.ci_cca_modem_en = 0xf,
	.ci_cca_main_ant = 0,
	.ci_cca_second_ant = 1,
	.ci_cca_flag0_ctrl = 0x8,
	.ci_cca_flag1_ctrl = 0x8,
	.ci_cca_flag2_ctrl = 0x2,
	.ci_cca_flag3_ctrl = 0xa,
	.ci_cca_gi_rise_thr_dbm = -72,
	.ci_cca_gi_fall_thr_dbm = -75,
	.ci_cca_gi_pow_lim_dbm = -59,
	.ci_cca_ed_en = 0x7ff,
	.ci_cca_gi_en = 0,
	.ci_trigger_base_en = 0,
	.ci_rx_he_mu_ppdu = false,
	.ci_offload_reorder_mode = RX_REORDER_BY_DRIVER,
	.ci_calib_conf_lo_coarse_step = LO_COARSE_STEP,
	.ci_calib_conf_lo_fine_step = LO_FINE_STEP,
	.ci_usb_single_queue_for_agg_en = true,
	.ci_calib_conf_tone_vector_20bw = {6, 10, 14, 18, 22, 24, 26, 26},
	.ci_calib_conf_tone_vector_40bw = {10, 18, 26, 34, 41, 48, 53, 58},
	.ci_calib_conf_tone_vector_80bw = {18, 34, 50, 66, 82, 98, 110, 122},
	.ci_calib_conf_tone_vector_160bw = {18, 34, 66, 98, 130, 164, 224, 250},
	.ci_calib_conf_ga_lin_upper_trshld = GA_LIN_UPPER_TRSHLD_DEFAULT,
	.ci_calib_conf_ga_lin_lower_trshld = GA_LIN_LOWER_TRSHLD_DEFAULT,
	.ci_calib_conf_gp_rad_trshld = GP_RAD_TRSHLD_DEFAULT,
	.ci_calib_conf_singletons_num = SINGLETONS_NUM_DEFAULT,
	.ci_calib_conf_comp_fiter_len = COMP_FILTER_LEN_DEFAULT,
};

static int update_config(struct cl_hw *cl_hw, char *name, char *value)
{
	struct cl_tcv_conf *conf = cl_hw->conf;
	int ret = -ENOENT;

	do {
		READ_U8(ce_bss_num);
		READ_S8(ce_debug_level);
		READ_BOOL(ce_radio_on);
		READ_BOOL(ce_ps_ctrl_enabled);
		READ_U8(ha_channel);
		READ_U8_ARR(ha_ieee80211w, MAX_BSS_NUM);
		READ_U8(ws_ieee80211w);
		READ_BOOL(ha_ieee80211h);
		READ_U8(ha_short_guard_interval);
		READ_U8(ha_max_mpdu_len);
		READ_U8(ha_vht_max_ampdu_len_exp);
		READ_U32(ha_beacon_int);
		READ_STR(ce_dsp_code);
		READ_STR(ce_dsp_data);
		READ_STR(ce_dsp_external_data);
		READ_BOOL(ce_uapsd_en);
		READ_BOOL(ci_eirp_regulatory_en);
		READ_BOOL(ci_agg_tx);
		READ_BOOL(ci_agg_rx);
		READ_BOOL(ce_txldpc_en);
		READ_BOOL(ce_ht_rxldpc_en);
		READ_BOOL(ce_vht_rxldpc_en);
		READ_BOOL(ce_he_rxldpc_en);
		READ_BOOL(ci_cs_required);
		READ_BOOL(ci_rx_sens_en);
		READ_S8_ARR(ci_rx_sensitivity_prod, MAX_ANTENNAS);
		READ_S8_ARR(ci_rx_sensitivity_op, MAX_ANTENNAS);
		READ_S8_ARR(ci_rx_sens_rssi, RX_SENS_THR_MAX);
		READ_S8_ARR(ci_rx_sens_val, RX_SENS_VAL_MAX);
		READ_BOOL(ci_cck_en);
		READ_BOOL(ci_min_he_en);
		READ_U8(ce_cck_tx_ant_mask);
		READ_U8(ce_cck_rx_ant_mask);
		READ_U8(ce_rx_nss);
		READ_U8(ce_tx_nss);
		READ_U8(ce_num_antennas);
		READ_U8(ce_wireless_mode);
		READ_BOOL_ARR(ha_wmm_enabled, MAX_BSS_NUM);
		READ_U16(ce_max_agg_size_tx);
		READ_U16(ce_max_agg_size_rx);
		READ_U16_ARR(ci_rx_ampdu_window_size, TID_MAX);
		READ_BOOL(ce_rxamsdu_en);
		READ_U8(ce_txamsdu_en);
		READ_U16(ci_tx_amsdu_min_data_rate);
		READ_U8(ci_rx_amsdu_max_packets);
		READ_U8(ci_tx_sw_amsdu_max_packets);
		READ_U16(ci_tx_amsdu_min_len_x2);
		READ_U16(ci_tx_amsdu_min_len_x3);
		READ_U16(ci_tx_packet_limit);
		READ_U16(ci_sw_txhdr_pool);
		READ_U16(ci_amsdu_txhdr_pool);
		READ_U16(ci_tx_queue_size_agg);
		READ_U16(ci_tx_queue_size_single);
		READ_BOOL(ci_traffic_mon_en);
		READ_U16_ARR(ci_ipc_rxbuf_size, CL_RX_BUF_MAX);
		READ_U16(ce_max_retry);
		READ_U8(ce_short_retry_limit);
		READ_U8(ce_long_retry_limit);
		READ_U8(ci_assoc_auth_retry_limit);
		READ_U8(ce_channel_bandwidth);
		READ_U8_ARR(ce_iface_type, MAX_BSS_NUM);
		READ_U8(ha_hw_mode);
		READ_S8(ce_temp_comp_slope);
		READ_U32(ce_sta_age_out);
		READ_U32(ci_fw_dbg_severity);
		READ_U32(ci_fw_dbg_module);
		READ_U8(ci_lcu_dbg_cfg_inx);
		READ_U8(ci_dsp_lcu_mode);
		READ_U32(ci_hal_idle_to);
		READ_U32(ci_tx_ac0_to);
		READ_U32(ci_tx_ac1_to);
		READ_U32(ci_tx_ac2_to);
		READ_U32(ci_tx_ac3_to);
		READ_U32(ci_tx_bcn_to);
		READ_STR(ce_hardware_power_table);
		READ_STR(ce_arr_gain);
		READ_STR(ce_bf_gain);
		READ_STR(ce_ant_gain);
		READ_STR(ce_ant_gain_36_64);
		READ_STR(ce_ant_gain_100_140);
		READ_STR(ce_ant_gain_149_165);
		READ_STR(ci_min_ant_pwr);
		READ_STR(ci_bw_factor);
		READ_BOOL(ce_radio_traffic_stats_enable);
		READ_U16(ce_radio_traffic_stats_rate);
		READ_U16(ce_radio_traffic_stats_interval);
		READ_U8(ce_mcast_rate);
		READ_BOOL(ce_dyn_mcast_rate_en);
		READ_BOOL(ce_dyn_bcast_rate_en);
		READ_U8(ce_default_mcs_ofdm);
		READ_U8(ce_default_mcs_cck);
		READ_S8(ce_snr_event_thr);
		READ_U8(ce_wl_event_logger);
		READ_BOOL(ce_prot_log_nav_en);
		READ_U8(ce_prot_mode);
		READ_U8(ce_prot_rate_format);
		READ_U8(ce_prot_rate_mcs);
		READ_U8(ce_prot_rate_pre_type);
		READ_U8(ce_bw_signaling_mode);
		READ_U8(ci_dyn_cts_sta_thr);
		READ_U8(ci_vns_pwr_limit);
		READ_U8(ci_vns_pwr_mode);
		READ_S8(ci_vns_rssi_auto_resp_thr);
		READ_U8(ci_iqdc_dpd_mode);
		READ_S8(ci_vns_rssi_thr);
		READ_S8(ci_vns_rssi_hys);
		READ_U16(ci_vns_maintenance_time);
		READ_U16(ce_bcn_tx_path_min_time);
		READ_BOOL(ci_backup_bcn_en);
		READ_BOOL(ce_tx_txop_cut_en);
		READ_U8(ci_bcns_flushed_cnt_thr);
		READ_BOOL(ci_phy_err_prevents_phy_dump);
		READ_U8(ci_tx_rx_delay);
		READ_U8(ci_fw_assert_time_diff_sec);
		READ_U8(ci_fw_assert_storm_detect_thd);
		READ_U32(ce_hw_assert_time_max);
		READ_U8(ce_fw_watchdog_mode);
		READ_U8(ce_fw_watchdog_limit_count);
		READ_U32(ce_fw_watchdog_limit_time);
		READ_BOOL(ce_m2u_enable);
		READ_S8(ci_rx_remote_cpu_drv);
		READ_U16(ci_pending_queue_size);
		READ_U8(ce_tx_power_control);
		READ_S8(ci_fixed_tx_power);
		READ_U32(ce_promiscuous_timeout);
		READ_S8(ce_extension_channel);
		READ_S8_ARR(ce_ppmcs_offset_he_6g, WRS_MCS_MAX_HE);
		READ_S8_ARR(ce_ppmcs_offset_he_36_64, WRS_MCS_MAX_HE);
		READ_S8_ARR(ce_ppmcs_offset_he_100_140, WRS_MCS_MAX_HE);
		READ_S8_ARR(ce_ppmcs_offset_he_149_165, WRS_MCS_MAX_HE);
		READ_S8_ARR(ce_ppmcs_offset_ht_vht_36_64, WRS_MCS_MAX_VHT);
		READ_S8_ARR(ce_ppmcs_offset_ht_vht_100_140, WRS_MCS_MAX_VHT);
		READ_S8_ARR(ce_ppmcs_offset_ht_vht_149_165, WRS_MCS_MAX_VHT);
		READ_S8_ARR(ce_ppmcs_offset_ofdm_36_64, WRS_MCS_MAX_OFDM);
		READ_S8_ARR(ce_ppmcs_offset_ofdm_100_140, WRS_MCS_MAX_OFDM);
		READ_S8_ARR(ce_ppmcs_offset_ofdm_149_165, WRS_MCS_MAX_OFDM);
		READ_S8_ARR(ce_ppmcs_offset_he, WRS_MCS_MAX_HE);
		READ_S8_ARR(ce_ppmcs_offset_ht, WRS_MCS_MAX_HT);
		READ_S8_ARR(ce_ppmcs_offset_ofdm, WRS_MCS_MAX_OFDM);
		READ_S8_ARR(ce_ppmcs_offset_cck, WRS_MCS_MAX_CCK);
		READ_S8_ARR(ce_ppbw_offset, CHNL_BW_MAX);
		READ_BOOL(ce_power_offset_prod_en);
		READ_BOOL(ce_bf_en);
		READ_U8(ci_bf_max_nss);
		READ_U16_ARR(ce_sounding_interval_coefs, SOUNDING_INTERVAL_COEF_MAX);
		READ_U8_ARR(ci_rate_fallback, CL_RATE_FALLBACK_MAX);
		READ_U32_ARR(ci_env_det_thr, CL_ENV_DET_THR_CNT);
		READ_U16(ci_env_det_flags);
		READ_U16(ce_rx_pkts_budget);
		READ_U8(ci_band_num);
		READ_BOOL(ci_mult_ampdu_in_txop_en);
		READ_U16_ARR(ce_dynamic_edca, EDCA_MAX_PARAMS);
		READ_U8_ARR(ce_wmm_aifsn, AC_MAX);
		READ_U8_ARR(ce_wmm_cwmin, AC_MAX);
		READ_U8_ARR(ce_wmm_cwmax, AC_MAX);
		READ_U16_ARR(ce_wmm_txop, AC_MAX);
		READ_U8(ci_su_force_min_spacing);
		READ_U8(ci_mu_force_min_spacing);
		READ_U8(ci_tf_mac_pad_dur);
		READ_U32(ci_cca_src);
		READ_U32(ci_cca_timeout);
		READ_BOOL(ci_vw_en);
		READ_BOOL(ci_vw_start_ba_session);
		READ_S8(ci_vw_delta_rssi);
		READ_U32(ci_vw_delta_time);
		READ_U16(ce_tx_ba_session_timeout);
		READ_U8(ci_wrs_max_bw);
		READ_U8(ci_wrs_min_bw);
		READ_S8_ARR(ci_wrs_fixed_rate, WRS_FIXED_PARAM_MAX);
		READ_U8_ARR(ce_he_mcs_nss_supp_tx, WRS_SS_MAX);
		READ_U8_ARR(ce_he_mcs_nss_supp_rx, WRS_SS_MAX);
		READ_U8_ARR(ce_vht_mcs_nss_supp_tx, WRS_SS_MAX);
		READ_U8_ARR(ce_vht_mcs_nss_supp_rx, WRS_SS_MAX);
		READ_U8(ci_pe_duration);
		READ_U8(ci_pe_duration_bcast);
		READ_U32(ci_umh_diff_time_ms);
		READ_U8(ci_gain_update_enable);
		READ_U8(ci_mcs_sig_b);
		READ_U8(ci_mcs_min);
		READ_U8(ci_mcs_max);
		READ_U8(ci_spp_ksr_value);
		READ_BOOL(ci_rx_padding_en);
		READ_BOOL(ci_stats_en);
		READ_BOOL(ci_bar_disable);
		READ_BOOL(ci_ofdm_only);
		READ_BOOL(ci_hw_bsr);
		READ_BOOL(ci_drop_to_lower_bw);
		READ_BOOL(ci_force_icmp_single);
		READ_BOOL(ce_twt_en);
		READ_BOOL(ce_bsr_en);
		READ_BOOL(ci_csd_en);
		READ_BOOL(ce_bsrp_en);
		READ_BOOL(ce_wrs_rx_en);
		READ_U32(ce_twt_default_interval);
		READ_U32(ce_twt_default_min_wake_duration);
		READ_U8(ce_twt_max_sessions);
		READ_U8_ARR(ci_hr_factor, CHNL_BW_MAX);
		READ_BOOL(ci_signal_extension_en);
		READ_BOOL_ARR(ce_dscp_vlan_enable, MAX_BSS_NUM);
		READ_U8_ARR(ce_up0_7_default_vlan_user_prio, MAX_BSS_NUM);
		READ_U8_ARR(ce_up0_7_layer_based, MAX_BSS_NUM);
		READ_STR(ce_dscp_to_up0_7dec0);
		READ_STR(ce_dscp_to_up0_7dec1);
		READ_STR(ce_dscp_to_up0_7dec2);
		READ_STR(ce_dscp_to_up0_7dec3);
		READ_STR(ce_dscp_to_up0_7dec4);
		READ_STR(ce_dscp_to_up0_7dec5);
		READ_STR(ce_dscp_to_up0_7dec6);
		READ_STR(ce_dscp_to_up0_7dec7);
		READ_STR(ce_vlan_to_up0_7dec0);
		READ_STR(ce_vlan_to_up0_7dec1);
		READ_STR(ce_vlan_to_up0_7dec2);
		READ_STR(ce_vlan_to_up0_7dec3);
		READ_STR(ce_vlan_to_up0_7dec4);
		READ_STR(ce_vlan_to_up0_7dec5);
		READ_STR(ce_vlan_to_up0_7dec6);
		READ_STR(ce_vlan_to_up0_7dec7);
		READ_BOOL(ci_vht_cap_24g);
		READ_BOOL(ce_omi_en);
		READ_U32(ci_tx_digital_gain);
		READ_U32(ci_tx_dig_gain_single_ant);
		READ_U32(ci_tx_dig_gain_all_ants);
		READ_BOOL(ci_mac_clk_gating_en);
		READ_BOOL(ci_phy_clk_gating_en);
		READ_BOOL(ci_imaging_blocker);
		READ_U8(ci_ndp_tx_chain_mask);
		READ_U8(ci_ndp_tx_bw);
		READ_U8(ci_ndp_tx_format);
		READ_U8(ci_ndp_tx_num_ltf);
		READ_S8(ci_cca_ed_rise_thr_dbm);
		READ_S8(ci_cca_ed_fall_thr_dbm);
		READ_U8(ci_cca_cs_en);
		READ_U8(ci_cca_modem_en);
		READ_U8(ci_cca_main_ant);
		READ_U8(ci_cca_second_ant);
		READ_U8(ci_cca_flag0_ctrl);
		READ_U8(ci_cca_flag1_ctrl);
		READ_U8(ci_cca_flag2_ctrl);
		READ_U8(ci_cca_flag3_ctrl);
		READ_S8(ci_cca_gi_rise_thr_dbm);
		READ_S8(ci_cca_gi_fall_thr_dbm);
		READ_S8(ci_cca_gi_pow_lim_dbm);
		READ_U16(ci_cca_ed_en);
		READ_U8(ci_cca_gi_en);
		READ_BOOL(ci_rx_he_mu_ppdu);
		READ_BOOL(ci_trigger_base_en);
		READ_U8(ci_offload_reorder_mode);
		READ_U16(ci_calib_conf_lo_coarse_step);
		READ_U16(ci_calib_conf_lo_fine_step);
		READ_U8(ci_usb_single_queue_for_agg_en);
		READ_U8_ARR(ci_calib_conf_tone_vector_20bw, IQ_NUM_TONES_REQ);
		READ_U8_ARR(ci_calib_conf_tone_vector_40bw, IQ_NUM_TONES_REQ);
		READ_U8_ARR(ci_calib_conf_tone_vector_80bw, IQ_NUM_TONES_REQ);
		READ_U8_ARR(ci_calib_conf_tone_vector_160bw, IQ_NUM_TONES_REQ);
		READ_U32(ci_calib_conf_gp_rad_trshld);
		READ_U32(ci_calib_conf_ga_lin_upper_trshld);
		READ_U32(ci_calib_conf_ga_lin_lower_trshld);
		READ_U8(ci_calib_conf_singletons_num);
		READ_U8(ci_calib_conf_comp_fiter_len);
	} while (0);

	if (ret == -ENOENT) {
		if (cl_config_is_non_driver_param(name))
			ret = 0;
		else
			CL_DBG_ERROR(cl_hw, "No matching conf for nvram parameter %s\n", name);
	}

	return ret;
}

static int set_all_params_from_buf(struct cl_hw *cl_hw, char *buf, size_t size)
{
	char *line = buf;
	char name[MAX_PARAM_NAME_LENGTH];
	char value[STR_LEN_256B];
	char *begin;
	char *end;
	int name_length = 0;
	int value_length = 0;

	while (line && strlen(line) && (line != (buf + size))) {
		if ((*line == '#') || (*line == '\n')) {
			/* Skip comment or blank line */
			line = strstr(line, "\n") + 1;
		} else if (*line) {
			begin = line;
			end = strstr(begin, "=");

			if (!end)
				return -1;

			end++;
			name_length = end - begin;
			value_length = strstr(end, "\n") - end + 1;

			if (name_length >= MAX_PARAM_NAME_LENGTH) {
				cl_dbg_err(cl_hw, "Name too long (%u)\n", name_length);
				return -1;
			}
			if (value_length >= STR_LEN_256B) {
				cl_dbg_err(cl_hw, "Value too long (%u)\n", value_length);
				return -1;
			}

			snprintf(name, name_length, "%s", begin);
			snprintf(value, value_length, "%s", end);

			if (update_config(cl_hw, name, value))
				return -1;

			line = strstr(line, "\n") + 1;
		}
	}

	return 0;
}

static u8 get_highest_ieee80211w(struct cl_hw *cl_hw)
{
	struct cl_tcv_conf *conf = cl_hw->conf;
	u8 i, ha_ieee80211w_max = 0;

	for (i = 0; i < conf->ce_bss_num; i++) {
		if (conf->ce_iface_type[i] == NL80211_IFTYPE_AP &&
		    conf->ha_ieee80211w[i] > ha_ieee80211w_max)
			ha_ieee80211w_max = conf->ha_ieee80211w[i];
	}

	if (cl_hw->iface_conf == CL_IFCONF_AP)
		return ha_ieee80211w_max;

	if (cl_hw->iface_conf == CL_IFCONF_STA ||
	    cl_hw->iface_conf == CL_IFCONF_MESH_ONLY)
		return cl_hw->conf->ws_ieee80211w;

	if (cl_hw->iface_conf == CL_IFCONF_REPEATER ||
	    cl_hw->iface_conf == CL_IFCONF_MESH_AP)
		return max(ha_ieee80211w_max, conf->ws_ieee80211w);

	return 0;
}

static bool is_valid_min_spacing(u8 min_spacing)
{
	return ((min_spacing == 0) ||
		(min_spacing == 1) ||
		(min_spacing == 2) ||
		(min_spacing == 3) ||
		(min_spacing == 4) ||
		(min_spacing == 6) ||
		(min_spacing == 8) ||
		(min_spacing == 10) ||
		(min_spacing == 12) ||
		(min_spacing == 14) ||
		(min_spacing == 16) ||
		(min_spacing == 18) ||
		(min_spacing == 20) ||
		(min_spacing == 24) ||
		(min_spacing ==  CL_TX_MPDU_SPACING_INVALID));
}

static bool is_valid_cca_config(struct cl_hw *cl_hw, struct cl_tcv_conf *conf)
{
	if (conf->ci_cca_ed_rise_thr_dbm <= conf->ci_cca_ed_fall_thr_dbm) {
		CL_DBG_ERROR(cl_hw, "cca_ed_rise_thr_dbm (%u) <= cca_ed_fall_thr_dbm (%u)\n",
			     conf->ci_cca_ed_rise_thr_dbm, conf->ci_cca_ed_fall_thr_dbm);
		return false;
	}

	if (conf->ci_cca_gi_rise_thr_dbm <= conf->ci_cca_gi_fall_thr_dbm) {
		CL_DBG_ERROR(cl_hw, "cca_gi_rise_thr_dbm (%u) <= cca_gi_fall_thr_dbm (%u)\n",
			     conf->ci_cca_gi_rise_thr_dbm, conf->ci_cca_gi_fall_thr_dbm);
		return false;
	}

	if (conf->ci_cca_gi_pow_lim_dbm <= conf->ci_cca_ed_rise_thr_dbm) {
		CL_DBG_ERROR(cl_hw, "cca_gi_pow_lim_dbm (%u) <= cca_ed_rise_thr_dbm (%u)\n",
			     conf->ci_cca_gi_pow_lim_dbm, conf->ci_cca_ed_rise_thr_dbm);
		return false;
	}

	return true;
}

static enum cl_iface_conf get_iface_conf(struct cl_tcv_conf *conf)
{
	u8 i, num_ap = 0, num_sta = 0, num_mp = 0;

	for (i = 0; i < conf->ce_bss_num; i++) {
		if (conf->ce_iface_type[i] == NL80211_IFTYPE_AP)
			num_ap++;
		else if (conf->ce_iface_type[i] == NL80211_IFTYPE_STATION)
			num_sta++;
		else if (conf->ce_iface_type[i] == NL80211_IFTYPE_MESH_POINT)
			num_mp++;
	}

	if (num_ap > 0 && num_sta == 0 && num_mp == 0)
		return CL_IFCONF_AP;

	if (num_ap == 0 && num_sta == 1 && num_mp == 0)
		return CL_IFCONF_STA;

	if (num_ap == 1 && num_sta == 1 && num_mp == 0)
		return CL_IFCONF_REPEATER;

	if (num_ap > 0 && num_sta == 0 && num_mp == 1)
		return CL_IFCONF_MESH_AP;

	if (num_ap == 0 && num_sta == 0 && num_mp == 1)
		return CL_IFCONF_MESH_ONLY;

	return CL_IFCONF_MAX;
}

static int post_configuration(struct cl_hw *cl_hw, const char *buf)
{
	struct cl_tcv_conf *conf = cl_hw->conf;
	struct cl_chip *chip = cl_hw->chip;

	/* Production mode */
	if (chip->conf->ce_production_mode) {
		memcpy(cl_hw->rx_sensitivity, conf->ci_rx_sensitivity_prod, MAX_ANTENNAS);
		conf->ce_prot_mode = TXL_NO_PROT;
		/* Production is done in station mode */
		conf->ce_iface_type[0] = NL80211_IFTYPE_STATION;
	} else {
		if (chip->conf->ci_twin_peak_mode == TWINPEAK_MODE_NO_RF) {
			s8 rx_sens_loopback[MAX_ANTENNAS] = {-96, -96};

			memcpy(cl_hw->rx_sensitivity, rx_sens_loopback, MAX_ANTENNAS);
		} else {
			memcpy(cl_hw->rx_sensitivity, conf->ci_rx_sensitivity_op, MAX_ANTENNAS);
		}
	}

	if (chip->conf->ci_phy_dev == PHY_DEV_FRU) {
		strncpy(conf->ce_dsp_code, "fwC_B2B.hex",
		       sizeof(conf->ce_dsp_code));
		strncpy(conf->ce_dsp_data, "fwD_B2B.hex",
		       sizeof(conf->ce_dsp_data));
		strncpy(conf->ce_dsp_external_data, "fwD_B2B.ext.hex",
		       sizeof(conf->ce_dsp_external_data));
	}

	cl_hw->iface_conf = get_iface_conf(conf);

	if (cl_hw->iface_conf == CL_IFCONF_MAX) {
		CL_DBG_ERROR(cl_hw, "Invalid interface configuration\n");
		return -1;
	}

	if (conf->ce_prot_mode != TXL_NO_PROT &&
	    conf->ce_prot_mode != TXL_PROT_RTS_FW &&
	    conf->ce_prot_mode != TXL_PROT_CTS_FW) {
		cl_dbg_err(cl_hw, "Invalid ce_prot_mode (%u), set to 0\n",
			   conf->ce_prot_mode);
		conf->ce_prot_mode = TXL_NO_PROT;
	}

	cl_hw->ieee80211w = get_highest_ieee80211w(cl_hw);

	if (!is_valid_cca_config(cl_hw, conf))
		return -1;

	/* Validate: ce_bss_num */
	if (conf->ce_bss_num > MAX_BSS_NUM) {
		CL_DBG_ERROR(cl_hw, "Invalid ce_bss_num (%u). Must be <= %u\n",
			     conf->ce_bss_num, MAX_BSS_NUM);
		return -1;
	}

	/* Validate: ce_num_antennas, ce_rx_nss, ce_tx_nss */
	if (conf->ce_num_antennas < MIN_ANTENNAS ||
	    conf->ce_num_antennas > MAX_ANTENNAS) {
		CL_DBG_ERROR(cl_hw, "Invalid ce_num_antennas (%u)\n", conf->ce_num_antennas);
		return -1;
	}

	if (conf->ce_rx_nss < 1 ||
	    conf->ce_rx_nss > WRS_SS_MAX ||
	    conf->ce_rx_nss > conf->ce_num_antennas) {
		CL_DBG_ERROR(cl_hw, "Invalid ce_rx_nss (%u)\n", conf->ce_rx_nss);
		return -1;
	}

	if (conf->ce_tx_nss < 1 ||
	    conf->ce_tx_nss > WRS_SS_MAX ||
	    conf->ce_tx_nss > conf->ce_num_antennas) {
		CL_DBG_ERROR(cl_hw, "Invalid ce_tx_nss (%u)\n", conf->ce_tx_nss);
		return -1;
	}

	/* Validate: ce_cck_tx_ant_mask and ce_cck_rx_ant_mask */
	if (cl_band_is_24g(cl_hw)) {
		u8 ant_bitmap = ((1 << conf->ce_num_antennas) - 1);
		u8 num_cck_ant_tx = hweight8(conf->ce_cck_tx_ant_mask);
		u8 num_cck_ant_rx = hweight8(conf->ce_cck_rx_ant_mask);

		if ((ant_bitmap & conf->ce_cck_tx_ant_mask) != conf->ce_cck_tx_ant_mask) {
			CL_DBG_ERROR(cl_hw, "Invalid ce_cck_tx_ant_mask (0x%x), "
					    "does not match ce_num_antennas mask (0x%x)\n",
				     conf->ce_cck_tx_ant_mask, ant_bitmap);
			return -1;
		}

		if ((ant_bitmap & conf->ce_cck_rx_ant_mask) != conf->ce_cck_rx_ant_mask) {
			CL_DBG_ERROR(cl_hw, "Invalid ce_cck_rx_ant_mask (0x%x), "
					    "does not match ce_num_antennas mask (0x%x)\n",
				     conf->ce_cck_rx_ant_mask, ant_bitmap);
			return -1;
		}

		if (conf->ce_cck_tx_ant_mask == 0) {
			CL_DBG_ERROR(cl_hw, "Invalid ce_cck_tx_ant_mask, can't be 0x0\n");
			return -1;
		}

		if (conf->ce_cck_rx_ant_mask == 0) {
			CL_DBG_ERROR(cl_hw, "Invalid ce_cck_rx_ant_mask, can't be 0x0\n");
			return -1;
		}

		if (num_cck_ant_tx > MAX_ANTENNAS) {
			CL_DBG_ERROR(cl_hw, "Invalid ce_cck_tx_ant_mask (0x%x), "
					    "number of set bits exceeds %u\n",
				     num_cck_ant_tx, MAX_ANTENNAS);
			return -1;
		}

		if (num_cck_ant_rx > MAX_ANTENNAS) {
			CL_DBG_ERROR(cl_hw, "Invalid ce_cck_rx_ant_mask (0x%x), "
					    "number of set bits exceeds %u\n",
				     num_cck_ant_rx, MAX_ANTENNAS);
			return -1;
		}
	}

	/* Validate channel bandwidth */
	if (cl_band_is_24g(cl_hw)) {
		/* Verify 2.4 bandwidth validity only in operational mode */
		if (!cl_hw->chip->conf->ce_production_mode &&
		    conf->ce_channel_bandwidth > CHNL_BW_40) {
			CL_DBG_ERROR(cl_hw, "Invalid channel bandwidth (%u) for 24g\n",
				     conf->ce_channel_bandwidth);
			return -1;
		}
	} else if (cl_band_is_5g(cl_hw)) {
		if (conf->ce_channel_bandwidth > CHNL_BW_160) {
			CL_DBG_ERROR(cl_hw, "Invalid channel bandwidth (%u) for 5g\n",
				     conf->ce_channel_bandwidth);
			return -1;
		}
	} else {
		if (conf->ce_channel_bandwidth > CHNL_BW_160) {
			CL_DBG_ERROR(cl_hw, "Invalid channel bandwidth (%u) for 6g\n",
				     conf->ce_channel_bandwidth);
			return -1;
		}
	}

	if (cl_band_is_5g(cl_hw)) {
		if (!conf->ci_ofdm_only) {
			CL_DBG_ERROR(cl_hw, "ci_ofdm_only must be set to 1 for 5g band\n");
			return -1;
		}
	}

	/* Validate ce_bcn_tx_path_min_time */
	if (conf->ce_bcn_tx_path_min_time <= TX_BCN_PENDING_CHAIN_MIN_TIME) {
		CL_DBG_ERROR(cl_hw, "Invalid ce_bcn_tx_path_min_time (%u)\n",
			     conf->ce_bcn_tx_path_min_time);
		return -1;
	}

	if (conf->ci_rx_amsdu_max_packets > RX_MAX_MSDU_IN_AMSDU) {
		cl_dbg_err(cl_hw, "ERROR: Invalid ci_rx_amsdu_max_packets (%u), set default (%u)\n",
			   conf->ci_rx_amsdu_max_packets, RX_MAX_MSDU_IN_AMSDU);

		conf->ci_rx_amsdu_max_packets = RX_MAX_MSDU_IN_AMSDU;
	}

	if (conf->ci_tx_sw_amsdu_max_packets > MAX_TX_SW_AMSDU_PACKET) {
		cl_dbg_err(cl_hw, "ERROR: Invalid ci_tx_sw_amsdu_max_packets (%u), set default (%u)\n",
			   conf->ci_tx_sw_amsdu_max_packets, MAX_TX_SW_AMSDU_PACKET);

		conf->ci_tx_sw_amsdu_max_packets = MAX_TX_SW_AMSDU_PACKET;
	}

	if (conf->ce_txamsdu_en > CL_AMSDU_TX_PAYLOAD_MAX) {
		CL_DBG_ERROR(cl_hw, "Invalid ce_txamsdu_en (%u), set default %u\n",
			     conf->ce_txamsdu_en, CL_AMSDU_TX_PAYLOAD_MAX);

		conf->ce_txamsdu_en = CL_AMSDU_TX_PAYLOAD_MAX;
	}

	if (conf->ce_tx_power_control > 100 || conf->ce_tx_power_control < 1) {
		cl_dbg_err(cl_hw, "ERROR: Invalid ce_tx_power_control (%u), set default 100\n",
			   conf->ce_tx_power_control);

		conf->ce_tx_power_control = 100;
	}

	if (conf->ce_max_retry > CL_MAX_NUM_OF_RETRY) {
		cl_dbg_err(cl_hw, "ERROR: Invalid ce_max_retry (%u), set default to maximum (%u)\n",
			   conf->ce_max_retry, CL_MAX_NUM_OF_RETRY);

		conf->ce_max_retry = CL_MAX_NUM_OF_RETRY;
	}

	if (!is_valid_min_spacing(conf->ci_su_force_min_spacing)) {
		cl_dbg_err(cl_hw, "ERROR: Invalid ci_su_force_min_spacing (%u), must be 0/1/2/3/4/6/8/10/12/14/16/18/20/24, set default %u\n",
			   conf->ci_su_force_min_spacing, CL_TX_MPDU_SPACING_INVALID);

		conf->ci_su_force_min_spacing = CL_TX_MPDU_SPACING_INVALID;
	}

	if (!is_valid_min_spacing(conf->ci_mu_force_min_spacing)) {
		cl_dbg_err(cl_hw, "ERROR: Invalid ci_mu_force_min_spacing (%u), must be 0/1/2/3/4/6/8/10/12/14/16/18/20/24, set default %u\n",
			   conf->ci_mu_force_min_spacing, CL_TX_MPDU_SPACING_INVALID);

		conf->ci_mu_force_min_spacing = CL_TX_MPDU_SPACING_INVALID;
	}

	if (conf->ce_sta_age_out < CL_AGE_OUT_MINIMUM_THR_SEC) {
		cl_dbg_err(cl_hw, "ERROR: 'ce_sta_age_out' is too small %u, using %d instead!\n",
			   conf->ce_sta_age_out, CL_AGE_OUT_MINIMUM_THR_SEC);

		conf->ce_sta_age_out = CL_AGE_OUT_MINIMUM_THR_SEC;
	}

	if (conf->ha_max_mpdu_len != IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_3895 &&
	    conf->ha_max_mpdu_len != IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_7991 &&
	    conf->ha_max_mpdu_len != IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_11454) {
		cl_dbg_err(cl_hw, "ERROR: Invalid 'ha_max_mpdu_len' (%u). Must be 0/1/2. Setting to 0\n",
			   conf->ha_max_mpdu_len);

		conf->ha_max_mpdu_len = IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_3895;
	}

	if (conf->ce_bsr_en && conf->ce_bsrp_en && cl_hw->iface_conf != CL_IFCONF_REPEATER) {
		cl_dbg_err(cl_hw, "ERROR: ce_bsr_en and ce_bsrp_en are both be enabled\n");
		conf->ce_bsr_en = false;
		conf->ce_bsrp_en = false;
	}

	if (chip->conf->ce_production_mode && !conf->ce_power_offset_prod_en) {
		cl_dbg_err(cl_hw, "Disable PPMCS/PPBW in production mode\n");

		if (cl_band_is_6g(cl_hw)) {
			memset(conf->ce_ppmcs_offset_he_6g, 0,
			       sizeof(conf->ce_ppmcs_offset_he_6g));
		} else if (cl_band_is_5g(cl_hw)) {
			memset(conf->ce_ppmcs_offset_he_36_64, 0,
			       sizeof(conf->ce_ppmcs_offset_he_36_64));
			memset(conf->ce_ppmcs_offset_he_100_140, 0,
			       sizeof(conf->ce_ppmcs_offset_he_100_140));
			memset(conf->ce_ppmcs_offset_he_149_165, 0,
			       sizeof(conf->ce_ppmcs_offset_he_149_165));
			memset(conf->ce_ppmcs_offset_ht_vht_36_64, 0,
			       sizeof(conf->ce_ppmcs_offset_ht_vht_36_64));
			memset(conf->ce_ppmcs_offset_ht_vht_100_140, 0,
			       sizeof(conf->ce_ppmcs_offset_ht_vht_100_140));
			memset(conf->ce_ppmcs_offset_ht_vht_149_165, 0,
			       sizeof(conf->ce_ppmcs_offset_ht_vht_149_165));
			memset(conf->ce_ppmcs_offset_ofdm_36_64, 0,
			       sizeof(conf->ce_ppmcs_offset_ofdm_36_64));
			memset(conf->ce_ppmcs_offset_ofdm_100_140, 0,
			       sizeof(conf->ce_ppmcs_offset_ofdm_100_140));
			memset(conf->ce_ppmcs_offset_ofdm_149_165, 0,
			       sizeof(conf->ce_ppmcs_offset_ofdm_149_165));
		} else {
			memset(conf->ce_ppmcs_offset_he, 0, sizeof(conf->ce_ppmcs_offset_he));
			memset(conf->ce_ppmcs_offset_ht, 0, sizeof(conf->ce_ppmcs_offset_ht));
			memset(conf->ce_ppmcs_offset_ofdm, 0, sizeof(conf->ce_ppmcs_offset_ofdm));
			memset(conf->ce_ppmcs_offset_cck, 0, sizeof(conf->ce_ppmcs_offset_cck));
		}

		memset(conf->ce_ppbw_offset, 0, sizeof(conf->ce_ppbw_offset));
	}

	if (conf->ce_twt_default_min_wake_duration > conf->ce_twt_default_interval) {
		CL_DBG_ERROR(cl_hw, "ce_twt_default_min_wake_duration > ce_twt_default_interval\n");
		return -1;
	}

	/* 6g supports HE only */
	if (cl_band_is_6g(cl_hw) && conf->ce_wireless_mode < WIRELESS_MODE_HE) {
		CL_DBG_ERROR(cl_hw, "Invalid wireless_mode (%u) for 6g\n", conf->ce_wireless_mode);
		return -1;
	}

	if (conf->ce_twt_max_sessions > CL_TWT_MAX_SESSIONS) {
		cl_dbg_err(cl_hw, "ce_twt_max_sessions (%u) is too high. "
				  "Setting it to the max value %u\n",
			   conf->ce_twt_max_sessions, CL_TWT_MAX_SESSIONS);
		conf->ce_twt_max_sessions = CL_TWT_MAX_SESSIONS;
	}

	if (!cl_band_is_24g(cl_hw) && cl_hw->conf->ci_signal_extension_en) {
		cl_dbg_err(cl_hw, "ERROR: Invalid 'ci_signal_extension_en' (%u). Must be 0 for non 2.4Ghz band. Setting to 0\n",
			   conf->ce_dyn_mcast_rate_en);

		conf->ci_signal_extension_en = false;
	}

	if (conf->ce_dyn_mcast_rate_en && cl_band_is_6g(cl_hw)) {
		cl_dbg_err(cl_hw, "ERROR: Invalid 'ce_dyn_mcast_rate_en' (%u). Must be 0 on 6Ghz band. Setting to 0\n",
			   conf->ce_dyn_mcast_rate_en);

		conf->ce_dyn_mcast_rate_en = 0;
	}

	if (conf->ce_dyn_bcast_rate_en && cl_band_is_6g(cl_hw)) {
		cl_dbg_err(cl_hw, "ERROR: Invalid 'ce_dyn_bcast_rate_en' (%u). Must be 0 on 6Ghz band. Setting to 0\n",
			   conf->ce_dyn_bcast_rate_en);

		conf->ce_dyn_bcast_rate_en = 0;
	}

	if (IS_PCI_BUS_TYPE(chip) && conf->ce_max_agg_size_tx > IEEE80211_MAX_AMPDU_BUF_HT) {
		cl_dbg_err(cl_hw, "Warning: PCIE ce_max_agg_size_tx is %u but limited to %u\n",
			   conf->ce_max_agg_size_tx,
			   IEEE80211_MAX_AMPDU_BUF_HT);
		conf->ce_max_agg_size_tx = IEEE80211_MAX_AMPDU_BUF_HT;
	}

	if (IS_PCI_BUS_TYPE(chip) && conf->ce_max_agg_size_rx > IEEE80211_MAX_AMPDU_BUF_HT) {
		cl_dbg_err(cl_hw, "Warning: PCIE ce_max_agg_size_rx is %u but limited to %u\n",
			   conf->ce_max_agg_size_rx,
			   IEEE80211_MAX_AMPDU_BUF_HT);
		conf->ce_max_agg_size_rx = IEEE80211_MAX_AMPDU_BUF_HT;
	}

#ifdef CE_DUMMY_PHY
	if (!IS_REAL_PHY(chip))
		ce_scale_down = 600;
#endif

	if (conf->ci_offload_reorder_mode >= RX_REORDER_MAX) {
		CL_DBG_ERROR(cl_hw, "Invalid ci_offload_reorder_mode (%u)\n",
				  conf->ci_offload_reorder_mode);
		return -EINVAL;
	}

	return 0;
}

int cl_tcv_config_read(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	char *buf = NULL;
	size_t size = 0;
	char filename[CL_FILENAME_MAX] = {0};
	u8 tcv_idx = cl_hw->idx;

	snprintf(filename, sizeof(filename), "cl_tcv%u.dat", tcv_idx);
	pr_debug("%s: %s\n", __func__, filename);
	size = cl_file_open_and_read(chip, filename, &buf);

	if (!buf) {
		pr_err("read %s failed !!!\n", filename);
		return -1;
	}

	if (set_all_params_from_buf(cl_hw, buf, size)) {
		kfree(buf);
		return -1;
	}

	if (post_configuration(cl_hw, NULL)) {
		kfree(buf);
		return -1;
	}

	kfree(buf);

	return 0;
}

int cl_tcv_config_set(struct cl_hw *cl_hw, char *buf, size_t size)
{
	size_t new_size = size + 1;
	char *new_buf = kzalloc(new_size, GFP_KERNEL);
	int ret;

	if (!new_buf)
		return -1;

	/* Add '\n' at the end of the string, before the NULL */
	memcpy(new_buf, buf, size);
	new_buf[size - 1] = '\n';

	ret = set_all_params_from_buf(cl_hw, new_buf, new_size);

	if (ret == 0)
		ret = post_configuration(cl_hw, new_buf);

	kfree(new_buf);

	return ret;
}

u8 cl_tcv_config_get_num_ap(struct cl_hw *cl_hw)
{
	u8 i;
	u8 num_ap = 0;

	for (i = 0; i < cl_hw->conf->ce_bss_num; i++)
		if (cl_hw->conf->ce_iface_type[i] == NL80211_IFTYPE_AP)
			num_ap++;

	return num_ap;
}

int cl_tcv_config_alloc(struct cl_hw *cl_hw)
{
	cl_hw->conf = kzalloc(sizeof(*cl_hw->conf), GFP_KERNEL);

	if (!cl_hw->conf)
		return -ENOMEM;

	/* Copy default values */
	memcpy(cl_hw->conf, &conf, sizeof(struct cl_tcv_conf));

	return 0;
}

void cl_tcv_config_free(struct cl_hw *cl_hw)
{
	kfree(cl_hw->conf);
	cl_hw->conf = NULL;
}

void cl_tcv_config_print(struct cl_hw *cl_hw)
{
	struct cl_tcv_conf *conf = cl_hw->conf;

	pr_debug("======================\n");
	pr_debug("  TCV%u configuration\n", cl_hw->tcv_idx);
	pr_debug("======================\n");

	print_unsigned(ce_bss_num);
	print_signed(ce_debug_level);
	print_bool(ce_radio_on);
	print_bool(ce_ps_ctrl_enabled);
	print_unsigned(ha_channel);
	print_unsigned_arr(ha_ieee80211w, MAX_BSS_NUM);
	print_unsigned(ws_ieee80211w);
	print_bool(ha_ieee80211h);
	print_unsigned(ha_short_guard_interval);
	print_unsigned(ha_max_mpdu_len);
	print_unsigned(ha_vht_max_ampdu_len_exp);
	print_unsigned(ha_beacon_int);
	print_str(ce_dsp_code);
	print_str(ce_dsp_data);
	print_str(ce_dsp_external_data);
	print_bool(ce_uapsd_en);
	print_bool(ci_eirp_regulatory_en);
	print_bool(ci_agg_tx);
	print_bool(ci_agg_rx);
	print_bool(ce_txldpc_en);
	print_bool(ce_ht_rxldpc_en);
	print_bool(ce_vht_rxldpc_en);
	print_bool(ce_he_rxldpc_en);
	print_bool(ci_cs_required);
	print_bool(ci_rx_sens_en);
	print_signed_arr(ci_rx_sensitivity_prod, MAX_ANTENNAS);
	print_signed_arr(ci_rx_sensitivity_op, MAX_ANTENNAS);
	print_signed_arr(ci_rx_sens_rssi, RX_SENS_THR_MAX);
	print_signed_arr(ci_rx_sens_val, RX_SENS_VAL_MAX);
	print_bool(ci_cck_en);
	print_bool(ci_min_he_en);
	print_hex(ce_cck_tx_ant_mask);
	print_hex(ce_cck_rx_ant_mask);
	print_unsigned(ce_rx_nss);
	print_unsigned(ce_tx_nss);
	print_unsigned(ce_num_antennas);
	print_unsigned(ce_wireless_mode);
	print_unsigned_arr(ha_wmm_enabled, MAX_BSS_NUM);
	print_unsigned(ce_max_agg_size_tx);
	print_unsigned(ce_max_agg_size_rx);
	print_unsigned_arr(ci_rx_ampdu_window_size, TID_MAX);
	print_bool(ce_rxamsdu_en);
	print_unsigned(ce_txamsdu_en);
	print_unsigned(ci_tx_amsdu_min_data_rate);
	print_unsigned(ci_rx_amsdu_max_packets);
	print_unsigned(ci_tx_sw_amsdu_max_packets);
	print_unsigned(ci_tx_amsdu_min_len_x2);
	print_unsigned(ci_tx_amsdu_min_len_x3);
	print_unsigned(ci_tx_packet_limit);
	print_unsigned(ci_sw_txhdr_pool);
	print_unsigned(ci_amsdu_txhdr_pool);
	print_unsigned(ci_tx_queue_size_agg);
	print_unsigned(ci_tx_queue_size_single);
	print_bool(ci_traffic_mon_en);
	print_unsigned_arr(ci_ipc_rxbuf_size, CL_RX_BUF_MAX);
	print_unsigned(ce_max_retry);
	print_unsigned(ce_short_retry_limit);
	print_unsigned(ce_long_retry_limit);
	print_unsigned(ci_assoc_auth_retry_limit);
	print_unsigned(ce_channel_bandwidth);
	print_unsigned_arr(ce_iface_type, MAX_BSS_NUM);
	print_unsigned(ha_hw_mode);
	print_signed(ce_temp_comp_slope);
	print_unsigned(ce_sta_age_out);
	print_unsigned(ci_fw_dbg_severity);
	print_hex(ci_fw_dbg_module);
	print_unsigned(ci_lcu_dbg_cfg_inx);
	print_unsigned(ci_dsp_lcu_mode);
	print_unsigned(ci_hal_idle_to);
	print_unsigned(ci_tx_ac0_to);
	print_unsigned(ci_tx_ac1_to);
	print_unsigned(ci_tx_ac2_to);
	print_unsigned(ci_tx_ac3_to);
	print_unsigned(ci_tx_bcn_to);
	print_str(ce_hardware_power_table);
	print_str(ce_arr_gain);
	print_str(ce_bf_gain);
	print_str(ce_ant_gain);
	print_str(ce_ant_gain_36_64);
	print_str(ce_ant_gain_100_140);
	print_str(ce_ant_gain_149_165);
	print_str(ci_min_ant_pwr);
	print_str(ci_bw_factor);
	print_bool(ce_radio_traffic_stats_enable);
	print_unsigned(ce_radio_traffic_stats_rate);
	print_unsigned(ce_radio_traffic_stats_interval);
	print_unsigned(ce_mcast_rate);
	print_bool(ce_dyn_mcast_rate_en);
	print_bool(ce_dyn_bcast_rate_en);
	print_unsigned(ce_default_mcs_ofdm);
	print_unsigned(ce_default_mcs_cck);
	print_signed(ce_snr_event_thr);
	print_unsigned(ce_wl_event_logger);
	print_bool(ce_prot_log_nav_en);
	print_unsigned(ce_prot_mode);
	print_unsigned(ce_prot_rate_format);
	print_unsigned(ce_prot_rate_mcs);
	print_unsigned(ce_prot_rate_pre_type);
	print_unsigned(ce_bw_signaling_mode);
	print_unsigned(ci_dyn_cts_sta_thr);
	print_unsigned(ci_vns_pwr_limit);
	print_unsigned(ci_vns_pwr_mode);
	print_signed(ci_vns_rssi_auto_resp_thr);
	print_unsigned(ci_iqdc_dpd_mode);
	print_signed(ci_vns_rssi_thr);
	print_signed(ci_vns_rssi_hys);
	print_unsigned(ci_vns_maintenance_time);
	print_unsigned(ce_bcn_tx_path_min_time);
	print_bool(ci_backup_bcn_en);
	print_bool(ce_tx_txop_cut_en);
	print_unsigned(ci_bcns_flushed_cnt_thr);
	print_bool(ci_phy_err_prevents_phy_dump);
	print_unsigned(ci_tx_rx_delay);
	print_unsigned(ci_fw_assert_time_diff_sec);
	print_unsigned(ci_fw_assert_storm_detect_thd);
	print_unsigned(ce_hw_assert_time_max);
	print_unsigned(ce_fw_watchdog_mode);
	print_unsigned(ce_fw_watchdog_limit_count);
	print_unsigned(ce_fw_watchdog_limit_time);
	print_bool(ce_m2u_enable);
	print_signed(ci_rx_remote_cpu_drv);
	print_unsigned(ci_pending_queue_size);
	print_unsigned(ce_tx_power_control);
	print_signed(ci_fixed_tx_power);
	print_unsigned(ce_promiscuous_timeout);
	print_unsigned(ce_extension_channel);
	print_signed_arr(ce_ppmcs_offset_he_36_64, WRS_MCS_MAX_HE);
	print_signed_arr(ce_ppmcs_offset_he_100_140, WRS_MCS_MAX_HE);
	print_signed_arr(ce_ppmcs_offset_he_149_165, WRS_MCS_MAX_HE);
	print_signed_arr(ce_ppmcs_offset_he_6g, WRS_MCS_MAX_HE);
	print_signed_arr(ce_ppmcs_offset_ht_vht_36_64, WRS_MCS_MAX_VHT);
	print_signed_arr(ce_ppmcs_offset_ht_vht_100_140, WRS_MCS_MAX_VHT);
	print_signed_arr(ce_ppmcs_offset_ht_vht_149_165, WRS_MCS_MAX_VHT);
	print_signed_arr(ce_ppmcs_offset_ofdm_36_64, WRS_MCS_MAX_OFDM);
	print_signed_arr(ce_ppmcs_offset_ofdm_100_140, WRS_MCS_MAX_OFDM);
	print_signed_arr(ce_ppmcs_offset_ofdm_149_165, WRS_MCS_MAX_OFDM);
	print_signed_arr(ce_ppmcs_offset_he, WRS_MCS_MAX_HE);
	print_signed_arr(ce_ppmcs_offset_ht, WRS_MCS_MAX_HT);
	print_signed_arr(ce_ppmcs_offset_ofdm, WRS_MCS_MAX_OFDM);
	print_signed_arr(ce_ppmcs_offset_cck, WRS_MCS_MAX_CCK);
	print_signed_arr(ce_ppbw_offset, CHNL_BW_MAX);
	print_bool(ce_power_offset_prod_en);
	print_bool(ce_bf_en);
	print_unsigned(ci_bf_max_nss);
	print_unsigned_arr(ce_sounding_interval_coefs, SOUNDING_INTERVAL_COEF_MAX);
	print_unsigned_arr(ci_rate_fallback, CL_RATE_FALLBACK_MAX);
	print_unsigned_arr(ci_env_det_thr, CL_ENV_DET_THR_CNT);
	print_unsigned(ci_env_det_flags);
	print_unsigned(ce_rx_pkts_budget);
	print_unsigned(ci_band_num);
	print_bool(ci_mult_ampdu_in_txop_en);
	print_unsigned_arr(ce_dynamic_edca, EDCA_MAX_PARAMS);
	print_unsigned_arr(ce_wmm_aifsn, AC_MAX);
	print_unsigned_arr(ce_wmm_cwmin, AC_MAX);
	print_unsigned_arr(ce_wmm_cwmax, AC_MAX);
	print_unsigned_arr(ce_wmm_txop, AC_MAX);
	print_unsigned(ci_su_force_min_spacing);
	print_unsigned(ci_mu_force_min_spacing);
	print_unsigned(ci_tf_mac_pad_dur);
	print_hex(ci_cca_src);
	print_unsigned(ci_cca_timeout);
	print_bool(ci_vw_en);
	print_bool(ci_vw_start_ba_session);
	print_unsigned(ci_vw_delta_rssi);
	print_unsigned(ci_vw_delta_time);
	print_unsigned(ce_tx_ba_session_timeout);
	print_unsigned(ci_wrs_max_bw);
	print_unsigned(ci_wrs_min_bw);
	print_signed_arr(ci_wrs_fixed_rate, WRS_FIXED_PARAM_MAX);
	print_unsigned_arr(ce_he_mcs_nss_supp_tx, WRS_SS_MAX);
	print_unsigned_arr(ce_he_mcs_nss_supp_rx, WRS_SS_MAX);
	print_unsigned_arr(ce_vht_mcs_nss_supp_tx, WRS_SS_MAX);
	print_unsigned_arr(ce_vht_mcs_nss_supp_rx, WRS_SS_MAX);
	print_unsigned(ci_pe_duration);
	print_unsigned(ci_pe_duration_bcast);
	print_unsigned(ci_umh_diff_time_ms);
	print_unsigned(ci_gain_update_enable);
	print_unsigned(ci_mcs_sig_b);
	print_unsigned(ci_mcs_min);
	print_unsigned(ci_mcs_max);
	print_unsigned(ci_spp_ksr_value);
	print_bool(ci_rx_padding_en);
	print_bool(ci_stats_en);
	print_bool(ci_bar_disable);
	print_bool(ci_ofdm_only);
	print_bool(ci_hw_bsr);
	print_bool(ci_drop_to_lower_bw);
	print_bool(ci_force_icmp_single);
	print_bool(ce_twt_en);
	print_bool(ce_bsr_en);
	print_bool(ce_bsrp_en);
	print_bool(ce_wrs_rx_en);
	print_bool(ci_csd_en);
	print_unsigned(ce_twt_default_interval);
	print_unsigned(ce_twt_default_min_wake_duration);
	print_unsigned(ce_twt_max_sessions);
	print_unsigned_arr(ci_hr_factor, CHNL_BW_MAX);
	print_bool(ci_signal_extension_en);
	print_unsigned_arr(ce_dscp_vlan_enable, MAX_BSS_NUM);
	print_unsigned_arr(ce_up0_7_default_vlan_user_prio, MAX_BSS_NUM);
	print_unsigned_arr(ce_up0_7_layer_based, MAX_BSS_NUM);
	print_str(ce_dscp_to_up0_7dec0);
	print_str(ce_dscp_to_up0_7dec1);
	print_str(ce_dscp_to_up0_7dec2);
	print_str(ce_dscp_to_up0_7dec3);
	print_str(ce_dscp_to_up0_7dec4);
	print_str(ce_dscp_to_up0_7dec5);
	print_str(ce_dscp_to_up0_7dec6);
	print_str(ce_dscp_to_up0_7dec7);
	print_str(ce_vlan_to_up0_7dec0);
	print_str(ce_vlan_to_up0_7dec1);
	print_str(ce_vlan_to_up0_7dec2);
	print_str(ce_vlan_to_up0_7dec3);
	print_str(ce_vlan_to_up0_7dec4);
	print_str(ce_vlan_to_up0_7dec5);
	print_str(ce_vlan_to_up0_7dec6);
	print_str(ce_vlan_to_up0_7dec7);
	print_bool(ci_vht_cap_24g);
	print_bool(ce_omi_en);
	print_hex(ci_tx_digital_gain);
	print_hex(ci_tx_dig_gain_single_ant);
	print_hex(ci_tx_dig_gain_all_ants);
	print_bool(ci_mac_clk_gating_en);
	print_bool(ci_phy_clk_gating_en);
	print_bool(ci_imaging_blocker);
	print_hex(ci_ndp_tx_chain_mask);
	print_unsigned(ci_ndp_tx_bw);
	print_unsigned(ci_ndp_tx_format);
	print_unsigned(ci_ndp_tx_num_ltf);
	print_signed(ci_cca_ed_rise_thr_dbm);
	print_signed(ci_cca_ed_fall_thr_dbm);
	print_hex(ci_cca_cs_en);
	print_hex(ci_cca_modem_en);
	print_hex(ci_cca_main_ant);
	print_hex(ci_cca_second_ant);
	print_hex(ci_cca_flag0_ctrl);
	print_hex(ci_cca_flag1_ctrl);
	print_hex(ci_cca_flag2_ctrl);
	print_hex(ci_cca_flag3_ctrl);
	print_signed(ci_cca_gi_rise_thr_dbm);
	print_signed(ci_cca_gi_fall_thr_dbm);
	print_signed(ci_cca_gi_pow_lim_dbm);
	print_hex(ci_cca_ed_en);
	print_hex(ci_cca_gi_en);
	print_bool(ci_rx_he_mu_ppdu);
	print_bool(ci_trigger_base_en);
	print_unsigned(ci_offload_reorder_mode);
	print_unsigned_arr(ci_calib_conf_tone_vector_20bw, IQ_NUM_TONES_REQ);
	print_unsigned_arr(ci_calib_conf_tone_vector_40bw, IQ_NUM_TONES_REQ);
	print_unsigned_arr(ci_calib_conf_tone_vector_80bw, IQ_NUM_TONES_REQ);
	print_unsigned_arr(ci_calib_conf_tone_vector_160bw, IQ_NUM_TONES_REQ);
	print_unsigned(ci_calib_conf_gp_rad_trshld);
	print_unsigned(ci_calib_conf_ga_lin_upper_trshld);
	print_unsigned(ci_calib_conf_ga_lin_lower_trshld);
	print_unsigned(ci_calib_conf_singletons_num);
	print_unsigned(ci_calib_conf_comp_fiter_len);
	print_unsigned(ci_calib_conf_lo_coarse_step);
	print_unsigned(ci_calib_conf_lo_fine_step);
	print_unsigned(ci_usb_single_queue_for_agg_en);
}
