
/* This file was created automatically by the conv_nvram_csv2c.py script
 * Please don't modify the contents of this file manually */
struct nvram_element {
  const char * name;
  short offset;
  short length;
  short next;
};

const static struct nvram_element nvrams[] = {
  {"rw_data_company_id", 0x000, 2, 0},
  {"rw_data_white_list_size", 0x002, 1, 0},
  {"rw_data_periodic_list_size", 0x003, 1, 0},
  {"rw_data_local_supported_features", 0x004, 8, 0},
  {"rw_data_public_addr", 0x00c, 6, 0},
  {"rw_data_random_addr", 0x012, 6, 0},
  {"rw_data_general_flags", 0x018, 4, 0},
  {"rw_data_min_num_of_chnls", 0x01c, 3, 0},
  {"rw_data_adv_ch_tx_pwr", 0x01f, 1, 0},
  {"rw_data_prim_ch_pkt_delay", 0x020, 2, 0},
  {"rw_data_default_scan_intrvl", 0x022, 1, 0},
  {"rw_data_default_scan_window", 0x023, 1, 3},
  {"rw_data_anchor_point_distance", 0x024, 4, 0},
  {"rw_data_default_channel_map", 0x028, 5, 0},
  {"rw_data_power_threshold", 0x02d, 3, 0},
  {"rw_data_device_default_tx_pwr", 0x030, 1, 0},
  {"rw_data_dummy_1_byte_001", 0x031, 1, 0},
  {"rw_data_country_code", 0x032, 1, 0},
  {"rw_data_local_name_len", 0x033, 1, 0},
  {"rw_data_class_of_device", 0x034, 4, 0},
  {"rw_data_local_name", 0x038, 32, 0},
  {"rw_data_local_fea", 0x058, 8, 0},
  {"rw_data_scatternet_feature", 0x060, 1, 2},
  {"rw_data_inq_scan_after_conn", 0x061, 1, 9},
  {"rw_data_host_to_bc_acl_pkt_size", 0x062, 2, 6},
  {"rw_data_num_host_to_bc_acl_pkts", 0x064, 1, 5},
  {"rw_data_num_bc_to_host_acl_pkts", 0x065, 1, 26},
  {"rw_data_bc_to_host_acl_pkt_size", 0x066, 2, 25},
  {"rw_data_def_link_policy_settings", 0x068, 2, 0},
  {"rw_data_supervision_timeout", 0x06a, 2, 0},
  {"rw_data_page_timeout", 0x06c, 2, 27},
  {"rw_data_conn_accept_timeout", 0x06e, 2, 11},
  {"rw_data_lmp_resp_timeout", 0x070, 1, 0},
  {"rw_data_no_of_bcast_retran", 0x071, 1, 10},
  {"rw_data_sniff_min_slots_to_skip_mark_as_bad", 0x072, 1, 0},
  {"rw_data_min_sniff_int_to_skip_data_tx_opt", 0x073, 1, 0},
  {"rw_data_t_poll_master", 0x074, 2, 16},
  {"rw_data_t_poll_slave", 0x076, 2, 4},
  {"rw_data_page_scan_interval", 0x078, 2, 28},
  {"rw_data_page_scan_window", 0x07a, 2, 38},
  {"rw_data_inquiry_scan_interval", 0x07c, 2, 0},
  {"rw_data_inquiry_scan_window", 0x07e, 2, 0},
  {"rw_data_scan_enable", 0x080, 1, 30},
  {"rw_data_page_scan_mode", 0x081, 1, 19},
  {"rw_data_page_scan_period_mode", 0x082, 1, 41},
  {"rw_data_page_scan_repetition_mode", 0x083, 1, 0},
  {"rw_data_mss_min_slot_diff", 0x084, 1, 31},
  {"rw_data_mss_can_wait_min_slot_diff", 0x085, 1, 0},
  {"rw_data_min_sniff_interval_for_xtol", 0x086, 1, 44},
  {"rw_data_min_hold_interval_for_xtol", 0x087, 1, 23},
  {"rw_data_power_save_enable", 0x088, 1, 49},
  {"rw_data_sleep_mode_guard_interval", 0x089, 1, 0},
  {"rw_data_lmp_max_drift", 0x08a, 1, 24},
  {"rw_data_lmp_max_jitter", 0x08b, 1, 39},
  {"rw_data_sleep_mode_threshold", 0x08c, 2, 0},
  {"rw_data_deep_sleep_mode_threshold", 0x08e, 2, 0},
  {"rw_data_hold_max_interval", 0x090, 2, 0},
  {"rw_data_hold_min_interval", 0x092, 2, 0},
  {"rw_data_sniff_trigger_select", 0x094, 1, 56},
  {"rw_data_slot_based_nbc_enable", 0x095, 1, 57},
  {"rw_data_sniff_max_interval", 0x096, 2, 47},
  {"rw_data_sniff_min_interval", 0x098, 2, 0},
  {"rw_data_sniff_interval_to_allow_5_slot_pkt", 0x09a, 1, 0},
  {"rw_data_sniff_interval_to_allow_3_slot_pkt", 0x09b, 1, 0},
  {"rw_data_num_slots_before_sniff_to_stop_poll", 0x09c, 1, 48},
  {"rw_data_num_slots_to_force_nbc_for_sniff_pkt", 0x09d, 1, 36},
  {"rw_data_enable_bb_ch_assessment", 0x09e, 1, 62},
  {"rw_data_auto_generation_bad_ch_count", 0x09f, 1, 34},
  {"rw_data_rssi_dbm_tolerance", 0x0a0, 1, 64},
  {"rw_data_afh_good_ch_threshold", 0x0a1, 1, 20},
  {"rw_data_afh_bad_ch_threshold", 0x0a2, 1, 0},
  {"rw_data_afh_step_value_for_ch_recovery", 0x0a3, 1, 59},
  {"rw_data_afh_good_crc_pkt_weight", 0x0a4, 1, 45},
  {"rw_data_afh_poll_nunll_pkt_weight", 0x0a5, 1, 42},
  {"rw_data_afh_crc_error_pkt_weight", 0x0a6, 1, 0},
  {"rw_data_afh_hec_error_pkt_weight", 0x0a7, 1, 60},
  {"rw_data_afh_access_error_pkt_weight", 0x0a8, 1, 0},
  {"rw_data_afh_outband_access_error_pkt_weight", 0x0a9, 1, 40},
  {"rw_data_afh_skip_num_sniff_windows_for_afh", 0x0aa, 1, 67},
  {"rw_data_afh_min_slots", 0x0ab, 1, 50},
  {"rw_data_afh_min_distance_between_afh_pdus", 0x0ac, 1, 65},
  {"rw_data_lmp_dsm_drift", 0x0ad, 1, 33},
  {"rw_data_sca_priority_register1", 0x0ae, 2, 37},
  {"rw_data_sca_priority_register2", 0x0b0, 2, 78},
  {"rw_data_epr_upgradekey_level", 0x0b2, 1, 0},
  {"rw_data_hci_soft_transport", 0x0b3, 1, 0},
  {"rw_data_min_dsniff_multiple_conn", 0x0b4, 2, 63},
  {"rw_data_min_dsniff_single_conn", 0x0b6, 1, 15},
  {"rw_data_num_supported_std_codecs", 0x0b7, 1, 79},
  {"rw_data_supported_std_codec_id", 0x0b8, 7, 61},
  {"rw_data_supported_std_codec_transport", 0x0bf, 7, 52},
  {"rw_data_num_supported_vendor_codecs", 0x0c6, 1, 72},
  {"rw_data_supported_vendor_codec_transport", 0x0c7, 1, 0},
  {"rw_data_supported_vendor_company_id", 0x0c8, 2, 66},
  {"rw_data_supported_vendor_codec_id", 0x0ca, 2, 92},
  {"rw_data_min_scheduler_req_time_buffer", 0x0cc, 1, 0},
  {"rw_data_sll_scheduler_cb_delay", 0x0cd, 1, 0},
  {"rw_data_adv_packet_formation_time", 0x0ce, 1, 35},
  {"rw_data_ext_adv_packet_formation_time", 0x0cf, 1, 0},
  {"rw_data_per_adv_packet_formation_time", 0x0d0, 1, 8},
  {"rw_data_scan_packet_config_time", 0x0d1, 1, 21},
  {"rw_data_init_packet_config_time", 0x0d2, 1, 0},
  {"rw_data_conn_tx_packet_config_time", 0x0d3, 1, 0},
  {"rw_data_conn_rx_packet_config_time", 0x0d4, 1, 73},
  {"rw_data_sync_packet_config_time", 0x0d5, 1, 83},
  {"rw_data_bis_tx_packet_config_time", 0x0d6, 1, 29},
  {"rw_data_bis_rx_packet_config_time", 0x0d7, 1, 89},
  {"rw_data_cis_packet_config_time", 0x0d8, 1, 86},
  {"rw_data_config_enc_tx_start_offset", 0x0d9, 1, 46},
  {"rw_data_default_pkt_hdr_len", 0x0da, 1, 0},
  {"rw_data_dma_copy_threshold_size", 0x0db, 1, 84},
  {"rw_data_xcvr_interrupt_mask_reg_val", 0x0dc, 4, 105},
  {"rw_data_config_phy_sel_mode", 0x0e0, 1, 0},
  {"rw_data_bt_fw_hci_version", 0x0e1, 1, 81},
  {"rw_data_bt_fw_hci_sub_version", 0x0e2, 1, 90},
  {"rw_data_bt_fw_lmp_version", 0x0e3, 1, 115},
  {"rw_data_bt_fw_lmp_sub_version", 0x0e4, 2, 99},
  {"rw_data_pf_macro_flags_8bit", 0x0e6, 1, 97},
  {"rw_data_xcvr_tx_intr_delay", 0x0e7, 1, 76},
  {"rw_data_default_golden_range_lower_limit", 0x0e8, 1, 107},
  {"rw_data_default_golden_range_upper_limit", 0x0e9, 1, 74},
  {"rw_data_ll_isoc_bis_data_rate_allocation", 0x0ea, 1, 17},
  {"rw_data_ll_isoc_cis_data_rate_allocation", 0x0eb, 1, 12},
  {"rw_data_btc_gen_config", 0x0ec, 4, 122},
  {"rw_data_ll_bis_tx_dist_to_next_pdu_max_threshold", 0x0f0, 2, 7},
  {"rw_data_ll_cis_tx_dist_to_next_pdu_max_threshold", 0x0f2, 2, 88},
  {"rw_data_ll_cis_tx_dist_to_next_pdu_min_threshold", 0x0f4, 2, 109},
  {"rw_data_tmss_in_us", 0x0f6, 2, 110},
  {"rw_data_bis_tmss_in_us", 0x0f8, 2, 108},
  {"rw_data_ll_adv_prim_tx_miss_threshold", 0x0fa, 2, 124},
  {"rw_data_ll_adv_prim_tx_miss_threshold_priority", 0x0fc, 2, 0},
  {"rw_data_ll_adv_sec_aux_tx_miss_threshold", 0x0fe, 2, 0},
  {"rw_data_ll_adv_sec_aux_tx_miss_threshold_priority", 0x100, 2, 77},
  {"rw_data_ll_adv_aux_chain_tx_miss_threshold", 0x102, 2, 130},
  {"rw_data_ll_scan_aux_miss_threshold", 0x104, 2, 0},
  {"rw_data_ll_scan_rx_miss_threshold", 0x106, 2, 53},
  {"rw_data_ll_per_adv_tx_miss_threshold", 0x108, 2, 80},
  {"rw_data_ll_per_adv_chain_tx_miss_threshold", 0x10a, 2, 22},
  {"rw_data_ll_sec_init_rx_miss_threshold", 0x10c, 2, 127},
  {"rw_data_ll_prim_init_rx_miss_threshold", 0x10e, 2, 14},
  {"rw_data_ll_isoc_big_bis_pdu_tx_miss_threshold", 0x110, 2, 126},
  {"rw_data_ll_isoc_big_ctrl_pdu_tx_miss_threshold", 0x112, 2, 117},
  {"rw_data_db_to_dbm_conv_val", 0x114, 1, 0},
  {"rw_data_dummy", 0x115, 3, 128},
  {"radio_specific_params_radio_sys_clk_sel", 0x118, 1, 58},
  {"radio_specific_params_osc_delay", 0x119, 1, 13},
  {"radio_specific_params_is_rssi_read", 0x11a, 1, 133},
  {"radio_specific_params_edr_si_bit", 0x11b, 1, 106},
  {"radio_specific_params_rssi_interference_threshold", 0x11c, 1, 0},
  {"radio_specific_params_max_rssi_dbm_change", 0x11d, 1, 111},
  {"radio_specific_params_min_rssi_dbm", 0x11e, 1, 143},
  {"radio_specific_params_max_rssi_dbm", 0x11f, 1, 54},
  {"radio_specific_params_delay_vals", 0x120, 20, 120},
  {"radio_specific_params_radio_reg_address", 0x134, 10, 93},
  {"radio_specific_params_radio_reg_value", 0x13e, 10, 55},
  {"radio_specific_params_tx_power", 0x148, 128, 101},
  {"radio_specific_params_default_tx_gain", 0x1c8, 2, 0},
  {"radio_specific_params_max_tx_gain", 0x1ca, 2, 0},
  {"radio_specific_params_min_tx_gain", 0x1cc, 2, 82},
  {"radio_specific_params_temp_comp_slope", 0x1ce, 2, 103},
  {"radio_specific_params_base_temp", 0x1d0, 2, 155},
  {"radio_specific_params_temp_comp_interval", 0x1d2, 2, 156},
  {"radio_specific_params_curr_temp_addr", 0x1d4, 4, 0},
  {"radio_specific_params_process_offset", 0x1d8, 2, 146},
  {"radio_specific_params_m1", 0x1da, 1, 104},
  {"radio_specific_params_m2", 0x1db, 1, 154},
  {"radio_specific_params_seq_tx_power_inc", 0x1dc, 1, 123},
  {"radio_specific_params_low_clk_frac", 0x1dd, 1, 149},
  {"radio_specific_params_rf_correlation_threshold", 0x1de, 1, 164},
  {"radio_specific_params_pf_rf_general_flags_8bit", 0x1df, 1, 160},
  {"radio_specific_params_tx_start_delay_1m", 0x1e0, 1, 129},
  {"radio_specific_params_tx_start_delay_2m", 0x1e1, 1, 163},
  {"radio_specific_params_tx_start_delay_s2", 0x1e2, 1, 0},
  {"radio_specific_params_tx_start_delay_s8", 0x1e3, 1, 100},
  {"radio_specific_params_rx_end_delay_1m", 0x1e4, 1, 96},
  {"radio_specific_params_rx_end_delay_2m", 0x1e5, 1, 151},
  {"radio_specific_params_rx_end_delay_s2", 0x1e6, 1, 94},
  {"radio_specific_params_rx_end_delay_s8", 0x1e7, 1, 87},
  {"radio_specific_params_rx_addr_ind_delay_1m", 0x1e8, 1, 159},
  {"radio_specific_params_rx_addr_ind_delay_2m", 0x1e9, 1, 112},
  {"radio_specific_params_rx_addr_ind_delay_s2", 0x1ea, 1, 171},
  {"radio_specific_params_rx_addr_ind_delay_s8", 0x1eb, 1, 0},
  {"radio_specific_params_tx_end_delay_1m", 0x1ec, 1, 140},
  {"radio_specific_params_tx_end_delay_2m", 0x1ed, 1, 182},
  {"radio_specific_params_tx_end_delay_s2", 0x1ee, 1, 132},
  {"radio_specific_params_tx_end_delay_s8", 0x1ef, 1, 69},
  {"radio_specific_params_tx_path_delay_1m", 0x1f0, 1, 183},
  {"radio_specific_params_tx_path_delay_2m", 0x1f1, 1, 184},
  {"radio_specific_params_tx_path_delay_s2", 0x1f2, 1, 185},
  {"radio_specific_params_tx_path_delay_s8", 0x1f3, 1, 186},
  {"radio_specific_params_rx_path_delay_1m", 0x1f4, 1, 131},
  {"radio_specific_params_rx_path_delay_2m", 0x1f5, 1, 113},
  {"radio_specific_params_rx_path_delay_s2", 0x1f6, 1, 157},
  {"radio_specific_params_rx_path_delay_s8", 0x1f7, 1, 152},
  {"radio_specific_params_rf_tx_ramp_up_time", 0x1f8, 1, 176},
  {"radio_specific_params_rf_rx_ramp_up_time", 0x1f9, 1, 71},
  {"radio_specific_params_rf_tx_ramp_down_time", 0x1fa, 1, 150},
  {"radio_specific_params_rf_rx_ramp_down_time", 0x1fb, 1, 0},
  {"radio_specific_params_tx_low_config_reg_val_1m", 0x1fc, 2, 193},
  {"radio_specific_params_tx_low_config_reg_val_2m", 0x1fe, 2, 114},
  {"radio_specific_params_tx_low_config_reg_val_lr", 0x200, 2, 170},
  {"radio_specific_params_rx_low_config_reg_val_1m", 0x202, 2, 178},
  {"radio_specific_params_rx_low_config_reg_val_2m", 0x204, 2, 142},
  {"radio_specific_params_rx_low_config_reg_val_lr", 0x206, 2, 91},
  {"radio_specific_params_rf_adc_dac_delay_val_offset", 0x208, 4, 181},
  {"radio_specific_params_rf_pa_ramp_up_count_offset", 0x20c, 1, 144},
  {"radio_specific_params_start_immediate_threshold", 0x20d, 1, 51},
  {"radio_specific_params_rf_reserved_01", 0x20e, 2, 197},
  {"pf_cfg_pf_transport_type", 0x210, 1, 125},
  {"pf_cfg_pf_usb_cfg_usb_pdma_limit_cmd", 0x211, 1, 166},
  {"pf_cfg_pf_usb_cfg_usb_pdma_limit_resp", 0x212, 1, 210},
  {"pf_cfg_pf_usb_cfg_usb_pdma_limit_acl_dl", 0x213, 1, 32},
  {"pf_cfg_pf_usb_cfg_usb_pdma_limit_acl_ul", 0x214, 1, 137},
  {"pf_cfg_pf_usb_cfg_usb_pdma_limit_iso_dl", 0x215, 1, 102},
  {"pf_cfg_pf_usb_cfg_usb_pdma_limit_iso_ul", 0x216, 1, 201},
  {"pf_cfg_pf_usb_cfg_usb_pdma_limit_debug", 0x217, 1, 202},
  {"pf_cfg_pf_uart_cfg_uart_div_m", 0x218, 1, 211},
  {"pf_cfg_pf_uart_cfg_uart_div_l", 0x219, 1, 165},
  {"pf_cfg_pf_uart_cfg_uart_frac", 0x21a, 1, 204},
  {"pf_cfg_pf_uart_cfg_uart_if", 0x21b, 1, 214},
  {"pf_cfg_pf_debug_cfg_log_msg_lvl", 0x21c, 1, 208},
  {"pf_cfg_pf_debug_cfg_lcu_mode", 0x21d, 1, 190},
  {"pf_cfg_pf_debug_cfg_lcu_wrap", 0x21e, 1, 145},
  {"pf_cfg_pf_debug_cfg_dummy", 0x21f, 1, 180},
  {"pf_cfg_pf_debug_cfg_log_mod_lvl", 0x220, 4, 153},
  {"pf_cfg_pf_debug_cfg_lcu_trigger_pc", 0x224, 4, 187},
  {"pf_cfg_pf_gen_cfg", 0x228, 4, 222},
  {"pf_cfg_pf_logger_uart_cfg_logger_uart_div_m", 0x22c, 1, 198},
  {"pf_cfg_pf_logger_uart_cfg_logger_uart_div_l", 0x22d, 1, 134},
  {"pf_cfg_pf_logger_uart_cfg_logger_uart_frac", 0x22e, 1, 161},
  {"pf_cfg_pf_logger_uart_cfg_logger_res", 0x22f, 1, 138},
};
const static unsigned char nvram_value[560] = {
/* 000: */  0x6a,0x00,0x08,0x08,0xff,0x79,0x01,0xff,
/* 008: */  0x0e,0x00,0x00,0x00,0x12,0x13,0x14,0x15,
/* 010: */  0x16,0x17,0xd1,0xd2,0xd3,0xd3,0xd2,0xd1,
/* 018: */  0x67,0x02,0x00,0x00,0x04,0x04,0x02,0x06,
/* 020: */  0xc4,0x09,0x20,0x18,0x20,0xa1,0x07,0x00,
/* 028: */  0xff,0xff,0xff,0xff,0x1f,0x00,0x00,0x00,
/* 030: */  0x08,0x00,0x00,0x0a,0x00,0x00,0x00,0x00,
/* 038: */  0x49,0x55,0x54,0x5f,0x42,0x7a,0x5f,0x32,
/* 040: */  0x2e,0x31,0x00,0x00,0x00,0x00,0x00,0x00,
/* 048: */  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* 050: */  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* 058: */  0xff,0xff,0xff,0xfe,0x9b,0xff,0x79,0x83,
/* 060: */  0x01,0x01,0xfd,0x03,0x04,0x06,0xfd,0x03,
/* 068: */  0x00,0x00,0x00,0x7d,0x00,0x20,0x40,0x1f,
/* 070: */  0x5a,0x05,0x04,0x14,0x20,0x00,0x20,0x00,
/* 078: */  0x00,0x08,0x00,0x01,0x00,0x10,0x48,0x00,
/* 080: */  0x00,0x00,0x00,0x01,0x08,0x18,0x50,0x50,
/* 088: */  0x00,0x04,0xfa,0x0a,0x00,0x08,0xfe,0xff,
/* 090: */  0xff,0xff,0x01,0x00,0x01,0x00,0xff,0xff,
/* 098: */  0x01,0x00,0x15,0x0b,0x0e,0x20,0x00,0x18,
/* 0a0: */  0x01,0x80,0x7f,0x01,0x84,0x83,0x80,0x7f,
/* 0a8: */  0x81,0x81,0x06,0x60,0x01,0x7d,0x71,0xf2,
/* 0b0: */  0x17,0x00,0x00,0x00,0x40,0x01,0x08,0x06,
/* 0b8: */  0xfe,0x06,0x04,0x03,0x02,0x01,0x00,0x02,
/* 0c0: */  0x02,0x02,0x02,0x02,0x0c,0x00,0x00,0x00,
/* 0c8: */  0x00,0x00,0x00,0x00,0x50,0x64,0x0a,0x28,
/* 0d0: */  0x23,0x0a,0x0a,0x0f,0x0f,0x0e,0x1e,0x1e,
/* 0d8: */  0x1e,0x32,0x04,0x32,0xf7,0x7e,0x14,0x00,
/* 0e0: */  0x00,0x0b,0x0b,0x0b,0x04,0x15,0x07,0x40,
/* 0e8: */  0xba,0xdc,0x3c,0x4b,0x00,0xc0,0x00,0x00,
/* 0f0: */  0x2c,0x01,0x2c,0x01,0x46,0x00,0xc8,0x00,
/* 0f8: */  0xc8,0x00,0x05,0x00,0x03,0x00,0x05,0x00,
/* 100: */  0x03,0x00,0x14,0x00,0x14,0x00,0x64,0x00,
/* 108: */  0x03,0x00,0x14,0x00,0x0a,0x00,0x14,0x00,
/* 110: */  0x0a,0x00,0x03,0x00,0x1e,0x00,0x00,0x00,
/* 118: */  0x0f,0x08,0x01,0x01,0x1d,0x0f,0xab,0xe7,
/* 120: */  0xd5,0xd6,0xdb,0xd0,0x80,0x76,0x80,0x76,
/* 128: */  0x35,0x01,0x4b,0x01,0x38,0x01,0x49,0x01,
/* 130: */  0x3c,0x93,0xff,0xff,0xff,0xff,0xff,0xff,
/* 138: */  0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,
/* 140: */  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* 148: */  0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x11,
/* 150: */  0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
/* 158: */  0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,0x20,0x21,
/* 160: */  0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,
/* 168: */  0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,0x30,0x31,
/* 170: */  0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,
/* 178: */  0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,0x40,0x41,
/* 180: */  0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,
/* 188: */  0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,0x50,0x51,
/* 190: */  0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,
/* 198: */  0x5a,0x5b,0x5c,0x5d,0x5e,0x5f,0x60,0x61,
/* 1a0: */  0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,
/* 1a8: */  0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,0x70,0x71,
/* 1b0: */  0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,
/* 1b8: */  0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,0x80,0x81,
/* 1c0: */  0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,
/* 1c8: */  0x40,0x00,0xb8,0x00,0xbc,0xfe,0x08,0x00,
/* 1d0: */  0x18,0x00,0x3c,0x00,0x00,0x00,0x00,0x00,
/* 1d8: */  0x08,0x00,0x7f,0xbd,0x00,0x00,0x1f,0x07,
/* 1e0: */  0x07,0x05,0x05,0x05,0x02,0x02,0x06,0x06,
/* 1e8: */  0x06,0x02,0x11,0xff,0x07,0x05,0x03,0x09,
/* 1f0: */  0x04,0x04,0x04,0x04,0x05,0x02,0x08,0x08,
/* 1f8: */  0x3c,0x3c,0x32,0x2d,0x00,0x04,0x00,0x08,
/* 200: */  0x00,0x04,0x00,0x04,0x00,0x08,0x00,0x04,
/* 208: */  0x04,0x0a,0x07,0x03,0x02,0x04,0x00,0x00,
/* 210: */  0x01,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
/* 218: */  0x00,0x20,0x08,0x08,0xee,0x03,0x00,0x00,
/* 220: */  0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,
/* 228: */  0x01,0x00,0x00,0x01,0x00,0x20,0x08,0x00,
};
const static short nvram_hash[64] = {
  148,135,212,136,139,175,168,226,
  177,191,189, 98,199,206,216, 95,
  227,213,194,231,  0,209,141, 75,
    1,167,162, 85, 70,179,  0,121,
  205, 68,196,173,195,119,188,220,
  192,174, 43,200,116,203,118,158,
  207, 18,230,169,218,217,215,223,
  219,147,229,228,224,221,225,172,
};

static int nvram_getHash(const char * name) {
  unsigned short hashval = 0;
  for (; *name; name++)
    hashval = hashval * 31 + *name;
  return hashval & (sizeof(nvram_hash) / sizeof(nvram_hash[0]) - 1);
}

static const struct nvram_element * nvram_getElement(const char * name) {
  unsigned short index;
  index = nvram_getHash(name);
  index = nvram_hash[index];
  while (index) {
    if (!strcmp(name, nvrams[index - 1].name))
      return &nvrams[index - 1];
    index = nvrams[index - 1].next;
  }
  return NULL;
}
