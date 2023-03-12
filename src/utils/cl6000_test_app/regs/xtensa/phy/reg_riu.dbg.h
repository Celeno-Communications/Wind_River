X_REMOTE_ROM static const struct rom_table_direct_mem rom_riu[] = {{
    CE_DEBUG_STR("\t\t------ RWNXVERSION                    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000000, .mask=0, .offset=0 },{
    CE_DEBUG_STR("version                        = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXSTATICCONFIG               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000004, .mask=0, .offset=0 },{
    CE_DEBUG_STR("fe_alt_mode                    = [0x%08x]  \n"), .addr=0, .mask=0xC0000000, .offset=30,                             },{
    CE_DEBUG_STR("channelbw                      = [0x%08x]  \n"), .addr=0, .mask=0x30000000, .offset=28,                             },{
    CE_DEBUG_STR("loopback_rx_bw                 = [0x%08x]  \n"), .addr=0, .mask=0x06000000, .offset=25,                             },{
    CE_DEBUG_STR("loopback_tx_bw                 = [0x%08x]  \n"), .addr=0, .mask=0x01800000, .offset=23,                             },{
    CE_DEBUG_STR("feenable                       = [0x%08x]  \n"), .addr=0, .mask=0x00600000, .offset=21,                             },{
    CE_DEBUG_STR("mode                           = [0x%08x]  \n"), .addr=0, .mask=0x001C0000, .offset=18,                             },{
    CE_DEBUG_STR("txorrxn                        = [0x%08x]  \n"), .addr=0, .mask=0x0003F000, .offset=12,                             },{
    CE_DEBUG_STR("inchannelvalidant              = [0x%08x]  \n"), .addr=0, .mask=0x00000FC0, .offset= 6,                             },{
    CE_DEBUG_STR("activeant                      = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXDYNAMICCONFIG              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000008, .mask=0, .offset=0 },{
    CE_DEBUG_STR("\t\t------ RWNXLBCAPTUREDELAY             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000000C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lbtxseldefault                 = [0x%08x]  \n"), .addr=0, .mask=0x70000000, .offset=28,                             },{
    CE_DEBUG_STR("lcu_riu_port_mode              = [0x%08x]  \n"), .addr=0, .mask=0x07FF0000, .offset=16,                             },{
    CE_DEBUG_STR("agcfsm_init_sync_en            = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("dspen_2_sync_en                = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("lbncocaptureen                 = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("lbcapturedelay                 = [0x%08x]  \n"), .addr=0, .mask=0x00001FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXTXSTARTDELAY               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000010, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txstartdelay                   = [0x%08x]  \n"), .addr=0, .mask=0x00001FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXTXFEDELAY                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000014, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txenddelay_20                  = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("txfemdmbdelay                  = [0x%08x]  \n"), .addr=0, .mask=0x003FF000, .offset=12,                             },{
    CE_DEBUG_STR("txfedelay_20                   = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSMIND                      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000018, .mask=0, .offset=0 },{
    CE_DEBUG_STR("htsig_mcs_on_time              = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("agcfsmind                      = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXIQCTRL                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000001C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txiqswapsel                    = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("txiqswappath_3                 = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("txiqswappath_2                 = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("txiqswappath_1                 = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("txiqswappath_0                 = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("rxiqswappath_4                 = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("rxiqswappath_3                 = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("rxiqswappath_2                 = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("rxiqswappath_1                 = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("rxiqswappath_0                 = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("txiqdelpathq_3                 = [0x%08x]  \n"), .addr=0, .mask=0x00080000, .offset=19,                             },{
    CE_DEBUG_STR("txiqdelpathi_3                 = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("txiqdelpathq_2                 = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("txiqdelpathi_2                 = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("txiqdelpathq_1                 = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("txiqdelpathi_1                 = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("txiqdelpathq_0                 = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("txiqdelpathi_0                 = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("rxiqdelpathq_4                 = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("rxiqdelpathi_4                 = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("rxiqdelpathq_3                 = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("rxiqdelpathi_3                 = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("rxiqdelpathq_2                 = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("rxiqdelpathi_2                 = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("rxiqdelpathq_1                 = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("rxiqdelpathi_1                 = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("rxiqdelpathq_0                 = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("rxiqdelpathi_0                 = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("txc_2_sdisbcfg                 = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("rxc_2_sdisbcfg                 = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXRXUNLOCKTIMER              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000020, .mask=0, .offset=0 },{
    CE_DEBUG_STR("unlocktimeoutreload_set        = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("unlocktimeoutdisable_set       = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("unlocktimeoutenable_set        = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("unlocktimeout                  = [0x%08x]  \n"), .addr=0, .mask=0x00001FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXTXFEDELAY_40               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000024, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txenddelay_40                  = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("txfedelay_40                   = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXTXFEDELAY_80               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000028, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txenddelay_80                  = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("txfedelay_80                   = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FTM_CTL                        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000002C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_20_sync_20_mode            = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("frc_sync_start                 = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("frc_sync_type                  = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("frc_en                         = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FTM_TOD_LO                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000030, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tod_lo_cc                      = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("tod_more                       = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("tod_29_0                       = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FTM_TOA_LO                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000034, .mask=0, .offset=0 },{
    CE_DEBUG_STR("toa_lo_cc                      = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("toa_more                       = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("toa_29_0                       = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FTM_HI                         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000038, .mask=0, .offset=0 },{
    CE_DEBUG_STR("toa_hi_cc                      = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("toa_44_30                      = [0x%08x]  \n"), .addr=0, .mask=0x7FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("tod_hi_cc                      = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("tod_44_30                      = [0x%08x]  \n"), .addr=0, .mask=0x00007FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FTM_FRC                        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000003C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("frc                            = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ BTC_CTL                        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000040, .mask=0, .offset=0 },{
    CE_DEBUG_STR("btc_en                         = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("btc_debounce_en                = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("btc_3_mode_tdo                 = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("btc_2_mode_tdi                 = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("btc_1_mode_tms                 = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("btc_0_mode_trstn               = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ BTC_STAT                       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000044, .mask=0, .offset=0 },{
    CE_DEBUG_STR("btc_3_stat_tdo                 = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("btc_2_stat_tdi                 = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("btc_1_stat_tms                 = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("btc_0_stat_trstn               = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ EXACTTXSTART                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000048, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txstartfrccancel               = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("txstartfrctarget               = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ TX_ENV_DET                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000004C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("env_det_polarity               = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("env_det_delay                  = [0x%08x]  \n"), .addr=0, .mask=0x001F0000, .offset=16,                             },{
    CE_DEBUG_STR("env_det_scale                  = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("env_det_th                     = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCBWSEL                       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000050, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_bw_sw                      = [0x%08x]  \n"), .addr=0, .mask=0x00000C00, .offset=10,                             },{
    CE_DEBUG_STR("aci_bw_src_sel                 = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("rfg_bw_sw                      = [0x%08x]  \n"), .addr=0, .mask=0x000000C0, .offset= 6,                             },{
    CE_DEBUG_STR("rfg_bw_src_sel                 = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("cca_bw_sw                      = [0x%08x]  \n"), .addr=0, .mask=0x0000000C, .offset= 2,                             },{
    CE_DEBUG_STR("cca_bw_src_sel                 = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FTM_FRC_MOD_3                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000054, .mask=0, .offset=0 },{
    CE_DEBUG_STR("ftm_frc_mod_3                  = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_CS                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000058, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_cs                     = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_MDM_STATE                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000005C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_mdm_state                  = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_REV                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000060, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_rev                     = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ UNLOCK_TIMEOUT_MASK            [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000064, .mask=0, .offset=0 },{
    CE_DEBUG_STR("unlock_timeout_mask            = [0x%08x]  \n"), .addr=0, .mask=0x007FFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGC_UNLOCK_REASON              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000068, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agc_unlock_reason              = [0x%08x]  \n"), .addr=0, .mask=0x007FFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXSTATICCONFIG_2             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000006C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("digital_gain_calc_active_en    = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("bw_160_dc_radar_en             = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("bw_160_dc_prim_en              = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("bw_160_dc_center_en            = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("bw_80_dc_radar_en              = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("bw_80_dc_prim_en               = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("bw_80_dc_center_en             = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("bw_40_dc_radar_en              = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("bw_40_dc_prim_en               = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("bw_40_dc_center_en             = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("bw_20_dc_radar_en              = [0x%08x]  \n"), .addr=0, .mask=0x00080000, .offset=19,                             },{
    CE_DEBUG_STR("bw_20_dc_prim_en               = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("bw_20_dc_center_en             = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("fe_dc_sw_ctrl_en               = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("aci_margin_bw_type             = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("debug_en                       = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("adc_pow_dis_mode               = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("fe_clk_gate_dis                = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("lna_sel_cfg                    = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_20_PCOEF_0_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000070, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_20_pcoef_0_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_20_PCOEF_1_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000074, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_20_pcoef_1_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_20_PCOEF_2_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000078, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_20_pcoef_2_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_20_PCOEF_3_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000007C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_20_pcoef_3_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXMACSTATICCONFIG            [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000080, .mask=0, .offset=0 },{
    CE_DEBUG_STR("psselect                       = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_20_PCOEF_4_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000084, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_20_pcoef_4_1               = [0x%08x]  \n"), .addr=0, .mask=0x00007FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_40_PCOEF_0_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000088, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_40_pcoef_0_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_40_PCOEF_1_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000008C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_40_pcoef_1_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_40_PCOEF_2_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000090, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_40_pcoef_2_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_40_PCOEF_3_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000094, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_40_pcoef_3_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_40_PCOEF_4_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000098, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_40_pcoef_4_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_40_PCOEF_5_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000009C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_40_pcoef_5_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_0_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000A0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_0_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_1_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000A4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_1_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_2_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000A8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_2_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_3_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000AC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_3_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_4_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000B0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_4_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_5_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000B4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_5_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_6_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000B8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_6_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_7_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000BC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_7_1               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_8_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000C0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_8_1               = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_0_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000C4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_0_1              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_1_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000C8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_1_1              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_2_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000CC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_2_1              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_3_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000D0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_3_1              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_4_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000D4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_4_1              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_5_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000D8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_5_1              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_6_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000DC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_6_1              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_7_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000E0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_7_1              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_8_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000E4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_8_1              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_9_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000E8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_9_1              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_10_1             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000EC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_10_1             = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_11_1             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000F0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_11_1             = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_12_1             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000F4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_12_1             = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_13_1             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000F8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_13_1             = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_14_1             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000000FC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_14_1             = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXFECTRL_0                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000100, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tx_160_diggainlin_0            = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("tx_80_diggainlin_0             = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("tx_40_diggainlin_0             = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("tx_20_diggainlin_0             = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXFECTRL_1                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000104, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tx_160_diggainlin_1            = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("tx_80_diggainlin_1             = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("tx_40_diggainlin_1             = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("tx_20_diggainlin_1             = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXFECTRL_2                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000108, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tx_160_diggainlin_2            = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("tx_80_diggainlin_2             = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("tx_40_diggainlin_2             = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("tx_20_diggainlin_2             = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXFECTRL_3                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000010C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tx_160_diggainlin_3            = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("tx_80_diggainlin_3             = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("tx_40_diggainlin_3             = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("tx_20_diggainlin_3             = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXFECTRL_4                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000110, .mask=0, .offset=0 },{
    CE_DEBUG_STR("btxdiggainlin_3                = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("btxdiggainlin_2                = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("btxdiggainlin_1                = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("btxdiggainlin_0                = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_20_PCOEF_0                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000114, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_20_pcoef_0                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_20_PCOEF_1                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000118, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_20_pcoef_1                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_20_PCOEF_2                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000011C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_20_pcoef_2                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_20_PCOEF_3                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000120, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_20_pcoef_3                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_20_PCOEF_4                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000124, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_20_pcoef_4                 = [0x%08x]  \n"), .addr=0, .mask=0x00007FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_40_PCOEF_0                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000128, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_40_pcoef_0                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_40_PCOEF_1                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000012C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_40_pcoef_1                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_40_PCOEF_2                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000130, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_40_pcoef_2                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_40_PCOEF_3                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000134, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_40_pcoef_3                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_40_PCOEF_4                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000138, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_40_pcoef_4                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_40_PCOEF_5                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000013C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_40_pcoef_5                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_0                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000140, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_0                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_1                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000144, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_1                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_2                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000148, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_2                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_3                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000014C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_3                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_4                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000150, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_4                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_5                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000154, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_5                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_6                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000158, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_6                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_7                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000015C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_7                 = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_80_PCOEF_8                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000160, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_80_pcoef_8                 = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_0                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000164, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_0                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_1                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000168, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_1                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_2                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000016C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_2                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_3                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000170, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_3                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_4                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000174, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_4                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_5                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000178, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_5                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_6                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000017C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_6                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_7                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000180, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_7                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_8                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000184, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_8                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_9                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000188, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_9                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_10               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000018C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_10               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_11               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000190, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_11               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_12               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000194, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_12               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_13               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000198, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_13               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_14               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000019C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_14               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_15               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001A0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_15               = [0x%08x]  \n"), .addr=0, .mask=0x03FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RSF_CONF_0                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001A4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rsf_offset                     = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFF80, .offset= 7,                             },{
    CE_DEBUG_STR("rsf_delay                      = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RSF_CONTROL                    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001A8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rsf_init_en                    = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("rsf_tx_bypass_type             = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("rsf_tx_bypass_mode             = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("rsf_rx_bypass_type             = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("rsf_rx_bypass_mode             = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("rsf_rx_ctl_from_reg            = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("\t\t------ RSF_INIT                       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001AC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rsf_init_data                  = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_RAM_INIT_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001B0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agc_fsm_ram_init_en            = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("agc_fsm_ram_init_ainc_2        = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("agc_fsm_ram_init_ainc_1        = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("agc_fsm_ram_init_wptr_set      = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("agc_fsm_ram_init_wptr          = [0x%08x]  \n"), .addr=0, .mask=0x000007FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_RAM_INIT_2              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001B4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agc_fsm_ram_init_wdata         = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_RAM_INIT_3              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001B8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agc_fsm_ram_init_rdata         = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LCU_TRIG_DLY_CONF              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001BC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lcu_stop_trig_delay            = [0x%08x]  \n"), .addr=0, .mask=0xFFFF0000, .offset=16,                             },{
    CE_DEBUG_STR("lcu_start_trig_delay           = [0x%08x]  \n"), .addr=0, .mask=0x0000FFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LCU_TRIG_START_CONF            [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001C0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lcu_start_trig_clear_p         = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("lcu_start_trig_state           = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("lcu_start_trig_dsss_unlock     = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("lcu_start_trig_cmd             = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LCU_TRIG_STOP_CONF             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001C4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lcu_stop_trig_clear_p          = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("lcu_stop_trig_state            = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("lcu_stop_trig_dsss_unlock      = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("lcu_stop_trig_ofdm_unlock      = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lcu_stop_trig_cmd              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ SAS_CTL_0                      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001C8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("sas_io_pad_1_2_sw_ctrl         = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("sas_io_pad_1_2                 = [0x%08x]  \n"), .addr=0, .mask=0x00000006, .offset= 1,                             },{
    CE_DEBUG_STR("sas_io_pad_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RSF_CONF_1                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001CC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rsf_correction                 = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MICTOR_CONF_1                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001D0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("mictor_sel_3                   = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("mictor_sel_2                   = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("mictor_sel_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("mictor_sel_0                   = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MICTOR_CONF_2                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001D4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("mictor_sel_5                   = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("mictor_sel_4                   = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LCU_START_TRIG_UNLOCK          [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001D8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lcu_start_trig_unlock          = [0x%08x]  \n"), .addr=0, .mask=0x007FFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_160_PCOEF_15_1             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001DC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_pcoef_15_1             = [0x%08x]  \n"), .addr=0, .mask=0x03FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_SEL_1                      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001E0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dc_scale_set_sel               = [0x%08x]  \n"), .addr=0, .mask=0x000000C0, .offset= 6,                             },{
    CE_DEBUG_STR("hbf_160_sel_rx_1               = [0x%08x]  \n"), .addr=0, .mask=0x00000038, .offset= 3,                             },{
    CE_DEBUG_STR("hbf_160_sel_rx_0               = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_DETECTOR_CFG             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001E4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("radar_detector_en              = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("output_comb_type               = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("radar_cmd_73_pulse_disable     = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("evtdelay_50_ns                 = [0x%08x]  \n"), .addr=0, .mask=0x1F000000, .offset=24,                             },{
    CE_DEBUG_STR("evthighthrdbv                  = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("evtlowthrdbv                   = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("evtthrdbv                      = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RF_RSSI_STAT                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001E8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rfrssi_5                       = [0x%08x]  \n"), .addr=0, .mask=0x00000C00, .offset=10,                             },{
    CE_DEBUG_STR("rfrssi_4                       = [0x%08x]  \n"), .addr=0, .mask=0x00000300, .offset= 8,                             },{
    CE_DEBUG_STR("rfrssi_3                       = [0x%08x]  \n"), .addr=0, .mask=0x000000C0, .offset= 6,                             },{
    CE_DEBUG_STR("rfrssi_2                       = [0x%08x]  \n"), .addr=0, .mask=0x00000030, .offset= 4,                             },{
    CE_DEBUG_STR("rfrssi_1                       = [0x%08x]  \n"), .addr=0, .mask=0x0000000C, .offset= 2,                             },{
    CE_DEBUG_STR("rfrssi_0                       = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ NCO_CTRL                       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001EC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("nco_clear_p                    = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("nco_en_ch_5                    = [0x%08x]  \n"), .addr=0, .mask=0x0000C000, .offset=14,                             },{
    CE_DEBUG_STR("nco_en_ch_4                    = [0x%08x]  \n"), .addr=0, .mask=0x00003000, .offset=12,                             },{
    CE_DEBUG_STR("nco_en_ch_3                    = [0x%08x]  \n"), .addr=0, .mask=0x00000C00, .offset=10,                             },{
    CE_DEBUG_STR("nco_en_ch_2                    = [0x%08x]  \n"), .addr=0, .mask=0x00000300, .offset= 8,                             },{
    CE_DEBUG_STR("nco_en_ch_1                    = [0x%08x]  \n"), .addr=0, .mask=0x000000C0, .offset= 6,                             },{
    CE_DEBUG_STR("nco_en_ch_0                    = [0x%08x]  \n"), .addr=0, .mask=0x00000030, .offset= 4,                             },{
    CE_DEBUG_STR("nco_enable                     = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ NCO_INC_0                      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001F0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("nco_inc_0                      = [0x%08x]  \n"), .addr=0, .mask=0x01FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ NCO_INC_1                      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001F4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("nco_inc_1                      = [0x%08x]  \n"), .addr=0, .mask=0x01FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ NCO_INIT_0                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001F8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("nco_init_q_0                   = [0x%08x]  \n"), .addr=0, .mask=0x7FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("nco_init_i_0                   = [0x%08x]  \n"), .addr=0, .mask=0x00007FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ NCO_INIT_1                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000001FC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("nco_init_q_1                   = [0x%08x]  \n"), .addr=0, .mask=0x7FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("nco_init_i_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00007FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCGAINSTAT                    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000200, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcgain_3                      = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("agcgain_2                      = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("agcgain_1                      = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("agcgain_0                      = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCRFGAINSTAT                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000204, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcrfgain_2_extlna             = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("agcrfgain_2_lna                = [0x%08x]  \n"), .addr=0, .mask=0x0E000000, .offset=25,                             },{
    CE_DEBUG_STR("agcrfgain_2_vga                = [0x%08x]  \n"), .addr=0, .mask=0x01F00000, .offset=20,                             },{
    CE_DEBUG_STR("agcrfgain_1_extlna             = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("agcrfgain_1_lna                = [0x%08x]  \n"), .addr=0, .mask=0x00038000, .offset=15,                             },{
    CE_DEBUG_STR("agcrfgain_1_vga                = [0x%08x]  \n"), .addr=0, .mask=0x00007C00, .offset=10,                             },{
    CE_DEBUG_STR("agcrfgain_0_extlna             = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("agcrfgain_0_lna                = [0x%08x]  \n"), .addr=0, .mask=0x000000E0, .offset= 5,                             },{
    CE_DEBUG_STR("agcrfgain_0_vga                = [0x%08x]  \n"), .addr=0, .mask=0x0000001F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCADCPOWSTAT                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000208, .mask=0, .offset=0 },{
    CE_DEBUG_STR("adcpowdbv_3                    = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("adcpowdbv_2                    = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("adcpowdbv_1                    = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("adcpowdbv_0                    = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCINBDPOW_20_STAT             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000020C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpow_20_pdbm_3              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpow_20_pdbm_2              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpow_20_pdbm_1              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpow_20_pdbm_0              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCDIGGAIN_0_STAT              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000210, .mask=0, .offset=0 },{
    CE_DEBUG_STR("diggain_160_ant_0              = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("diggain_80_ant_0               = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("diggain_40_ant_0               = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("diggain_20_ant_0               = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCDIGGAIN_1_STAT              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000214, .mask=0, .offset=0 },{
    CE_DEBUG_STR("diggain_160_ant_1              = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("diggain_80_ant_1               = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("diggain_40_ant_1               = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("diggain_20_ant_1               = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCDIGGAIN_2_STAT              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000218, .mask=0, .offset=0 },{
    CE_DEBUG_STR("diggain_160_ant_2              = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("diggain_80_ant_2               = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("diggain_40_ant_2               = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("diggain_20_ant_2               = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCDIGGAIN_3_STAT              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000021C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("diggain_160_ant_3              = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("diggain_80_ant_3               = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("diggain_40_ant_3               = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("diggain_20_ant_3               = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADARSTAT_0                    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000220, .mask=0, .offset=0 },{
    CE_DEBUG_STR("pulse_length                   = [0x%08x]  \n"), .addr=0, .mask=0x1FE00000, .offset=21,                             },{
    CE_DEBUG_STR("agc_cmd_71_param_2             = [0x%08x]  \n"), .addr=0, .mask=0x001FE000, .offset=13,                             },{
    CE_DEBUG_STR("agc_cmd_71_param_1             = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("fsm_state                      = [0x%08x]  \n"), .addr=0, .mask=0x000003E0, .offset= 5,                             },{
    CE_DEBUG_STR("cur_pass_num                   = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("meas_done_3                    = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("meas_done_2                    = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("meas_done_1                    = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("radfifoempty                   = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ UNLOCKTIMESTAT                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000224, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsmstat                     = [0x%08x]  \n"), .addr=0, .mask=0xFFC00000, .offset=22,                             },{
    CE_DEBUG_STR("agcofdmunlocktime              = [0x%08x]  \n"), .addr=0, .mask=0x001FFF00, .offset= 8,                             },{
    CE_DEBUG_STR("\t\t------ AGCINBDPOW_20_PNOISESTAT       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000228, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpow_20_pnoisedbm_3         = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpow_20_pnoisedbm_2         = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpow_20_pnoisedbm_1         = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpow_20_pnoisedbm_0         = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCINBDPOWSECSTAT              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000022C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpow_80_sdbm                = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpow_40_sdbm                = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpow_20_sdbm                = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCINBDPOWSECNOISESTAT         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000230, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpow_80_snoisedbm           = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpow_40_snoisedbm           = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpow_20_snoisedbm           = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCADCPOWDBMSTAT               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000234, .mask=0, .offset=0 },{
    CE_DEBUG_STR("adcpowdbm_3                    = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("adcpowdbm_2                    = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("adcpowdbm_1                    = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("adcpowdbm_0                    = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGC_UNLOCK_REASON_RAW          [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000238, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agc_unlock_reason_raw          = [0x%08x]  \n"), .addr=0, .mask=0x007FFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000240, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_1              = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_2              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000244, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_2              = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_3              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000248, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_3              = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_4              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000024C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_4              = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_5              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000250, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_5              = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_6              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000254, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_6              = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_7              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000258, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_7              = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_0_REF_2       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000025C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_11_thrset_0_db             = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_10_thrset_0_db             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_9_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_8_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_0_REF_3       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000260, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_14_thrset_0_db             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_13_thrset_0_db             = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_12_thrset_0_db             = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_1_REF_2       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000264, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_11_thrset_1_db             = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_10_thrset_1_db             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_9_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_8_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_1_REF_3       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000268, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_14_thrset_1_db             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_13_thrset_1_db             = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_12_thrset_1_db             = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_2_REF_2       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000026C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_11_thrset_2_db             = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_10_thrset_2_db             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_9_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_8_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_2_REF_3       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000270, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_14_thrset_2_db             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_13_thrset_2_db             = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_12_thrset_2_db             = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAGAINSET_0_REF_2      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000274, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_11_gaindb                  = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_10_gaindb                  = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_9_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_8_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAGAINSET_0_REF_3      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000278, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_15_gaindb                  = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_14_gaindb                  = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_13_gaindb                  = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_12_gaindb                  = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNANFSET_0_REF_2        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000027C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_11_nfdb                    = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_10_nfdb                    = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_9_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_8_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNANFSET_0_REF_3        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000280, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_15_nfdb                    = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_14_nfdb                    = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_13_nfdb                    = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_12_nfdb                    = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAICP_1_SET_0_REF_2    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000284, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_11_icp_1_db                = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_10_icp_1_db                = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_9_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_8_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAICP_1_SET_0_REF_3    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000288, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_15_icp_1_db                = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_14_icp_1_db                = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_13_icp_1_db                = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_12_icp_1_db                = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCRSSILNA_0_SET_0         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000290, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rssi_lna_3_db                  = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("rssi_lna_2_db                  = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rssi_lna_1_db                  = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("rssi_lna_0_db                  = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCRSSILNA_1_SET_0         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000294, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rssi_lna_7_db                  = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("rssi_lna_6_db                  = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rssi_lna_5_db                  = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("rssi_lna_4_db                  = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCRSSILNA_2_SET_0         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000298, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rssi_lna_11_db                 = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("rssi_lna_10_db                 = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rssi_lna_9_db                  = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("rssi_lna_8_db                  = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCRSSILNA_3_SET_0         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000029C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rssi_lna_15_db                 = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("rssi_lna_14_db                 = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rssi_lna_13_db                 = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("rssi_lna_12_db                 = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_8              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002A0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_8              = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_9              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002A4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_9              = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_10             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002A8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_10             = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_11             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002AC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_11             = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_12             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002B0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_12             = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_13             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002B4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_13             = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_14             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002B8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_14             = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCFSM_PRESET_P_15             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002BC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcfsm_preset_p_15             = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DAC_SAT_CNT_CFG                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002C0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("sat_cnt_th                     = [0x%08x]  \n"), .addr=0, .mask=0x07FF0000, .offset=16,                             },{
    CE_DEBUG_STR("sat_cnt_mode                   = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("sat_cnt_en                     = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DAC_0_SAT_CNT                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002C4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dac_0_sat_cnt                  = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DAC_1_SAT_CNT                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002C8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dac_1_sat_cnt                  = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DAC_2_SAT_CNT                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002CC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dac_2_sat_cnt                  = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DAC_3_SAT_CNT                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002D0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dac_3_sat_cnt                  = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DAC_4_SAT_CNT                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002D4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dac_4_sat_cnt                  = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DAC_5_SAT_CNT                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002D8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dac_5_sat_cnt                  = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_MODEM_STATE_P          [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002DC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_modem_state_p          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_MODEM_STATE_20_S       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002E0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_modem_state_20_s       = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_MODEM_STATE_40_S       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002E4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_modem_state_40_s       = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_MODEM_STATE_80_S       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002E8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_modem_state_80_s       = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_RAMP_UP_P              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002EC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_ramp_up_p              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_RAMP_UP_20_S           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002F0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_ramp_up_20_s           = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_ENERGY_THR_P           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002F4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_energy_thr_p           = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_ENERGY_THR_20_S        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002F8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_energy_thr_20_s        = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_GI_20_P                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000002FC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_gi_20_p                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCANTLOSS                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000300, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rflossant_5_db                 = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("rflossant_4_db                 = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("rflossant_3_db                 = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("rflossant_2_db                 = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("rflossant_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("rflossant_0_db                 = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCGAINRANGE               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000304, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rfgainmax_4_detdb              = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("rfgainmin_4_detdb              = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("rfgainmaxdb                    = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("rfgainmindb                    = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCVGAREF_0                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000308, .mask=0, .offset=0 },{
    CE_DEBUG_STR("diggain_160_vs_20              = [0x%08x]  \n"), .addr=0, .mask=0xF0000000, .offset=28,                             },{
    CE_DEBUG_STR("diggain_80_vs_20               = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("diggain_40_vs_20               = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("dig_gain_fix_160_en            = [0x%08x]  \n"), .addr=0, .mask=0x00080000, .offset=19,                             },{
    CE_DEBUG_STR("dig_gain_fix_80_en             = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("dig_gain_fix_40_en             = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("vgaindmax                      = [0x%08x]  \n"), .addr=0, .mask=0x0001F000, .offset=12,                             },{
    CE_DEBUG_STR("vgastepdb                      = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("vgamindb                       = [0x%08x]  \n"), .addr=0, .mask=0x0000001F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAGAINSET_0_REF_0      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000030C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_3_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_2_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_1_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_0_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAGAINSET_0_REF_1      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000310, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_7_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_6_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_5_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_4_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_0_REF_0       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000314, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_3_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_2_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_1_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_0_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_0_REF_1       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000318, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_7_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_6_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_5_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_4_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_1_REF_0       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000031C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_3_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_2_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_1_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_0_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_1_REF_1       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000320, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_7_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_6_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_5_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_4_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_2_REF_0       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000324, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_3_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_2_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_1_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_0_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_2_REF_1       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000328, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_7_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_6_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_5_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_4_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNANFSET_0_REF_0        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000032C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_3_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_2_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_1_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_0_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNANFSET_0_REF_1        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000330, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_7_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_6_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_5_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_4_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAICP_1_SET_0_REF_0    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000334, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_3_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_2_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_1_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_0_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAICP_1_SET_0_REF_1    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000338, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_7_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_6_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_5_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_4_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAGAPSET_0             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000033C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("sdrx_2                         = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("lna_3_max                      = [0x%08x]  \n"), .addr=0, .mask=0x70000000, .offset=28,                             },{
    CE_DEBUG_STR("snrgapdb                       = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("sdrgapdb                       = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACI_20_MARG_0           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000340, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_20_margmcs_3               = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_20_margmcs_2               = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_20_margmcs_1               = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_20_margmcs_0               = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACI_20_MARG_1           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000344, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_20_margmcs_7               = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_20_margmcs_6               = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_20_margmcs_5               = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_20_margmcs_4               = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACI_20_MARG_2           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000348, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_20_margmcs_11              = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_20_margmcs_10              = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_20_margmcs_9               = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_20_margmcs_8               = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACI_40_MARG_0           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000034C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_40_margmcs_3               = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_40_margmcs_2               = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_40_margmcs_1               = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_40_margmcs_0               = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACI_40_MARG_1           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000350, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_40_margmcs_7               = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_40_margmcs_6               = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_40_margmcs_5               = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_40_margmcs_4               = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACI_40_MARG_2           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000354, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_40_margmcs_11              = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_40_margmcs_10              = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_40_margmcs_9               = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_40_margmcs_8               = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACI_80_MARG_0           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000358, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_80_margmcs_3               = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_80_margmcs_2               = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_80_margmcs_1               = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_80_margmcs_0               = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACI_80_MARG_1           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000035C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_80_margmcs_7               = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_80_margmcs_6               = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_80_margmcs_5               = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_80_margmcs_4               = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACI_80_MARG_2           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000360, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_80_margmcs_11              = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_80_margmcs_10              = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_80_margmcs_9               = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_80_margmcs_8               = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCSAT                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000364, .mask=0, .offset=0 },{
    CE_DEBUG_STR("satdelay_50_ns                 = [0x%08x]  \n"), .addr=0, .mask=0x1F000000, .offset=24,                             },{
    CE_DEBUG_STR("sathighthrdbv                  = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("satlowthrdbv                   = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("satthrdbv                      = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCROSS                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000368, .mask=0, .offset=0 },{
    CE_DEBUG_STR("crossdnthrqdbm                 = [0x%08x]  \n"), .addr=0, .mask=0x003FF000, .offset=12,                             },{
    CE_DEBUG_STR("crossupthrqdbm                 = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCRAMP                    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000036C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rampdnndlindex                 = [0x%08x]  \n"), .addr=0, .mask=0x07000000, .offset=24,                             },{
    CE_DEBUG_STR("rampdngapqdb                   = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rampupndlindex                 = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("rampupgapqdb                   = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCSTABDIS                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000370, .mask=0, .offset=0 },{
    CE_DEBUG_STR("adcpowdisndl                   = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("adcpowdisthrdbv                = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("platndlindex                   = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("platdpqdb                      = [0x%08x]  \n"), .addr=0, .mask=0x0000001F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCDCCOMP_0                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000374, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dcradartype                    = [0x%08x]  \n"), .addr=0, .mask=0x30000000, .offset=28,                             },{
    CE_DEBUG_STR("dccenteredfromagc              = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("dccenteredtype                 = [0x%08x]  \n"), .addr=0, .mask=0x03000000, .offset=24,                             },{
    CE_DEBUG_STR("dcagc_20_type                  = [0x%08x]  \n"), .addr=0, .mask=0x00300000, .offset=20,                             },{
    CE_DEBUG_STR("dcadctype                      = [0x%08x]  \n"), .addr=0, .mask=0x00030000, .offset=16,                             },{
    CE_DEBUG_STR("dcadcholdtime_50_ns            = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("dcadczerotime_50_ns            = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCDCCOMP_1                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000378, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dccenteredholdtime_50_ns       = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("dccenteredzerotime_50_ns       = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("dcagc_20_holdtime_50_ns        = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("dcagc_20_zerotime_50_ns        = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCDCCOMP_2                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000037C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("deldcstablecc_1                = [0x%08x]  \n"), .addr=0, .mask=0x3F800000, .offset=23,                             },{
    CE_DEBUG_STR("dcradarholdtime_50_ns          = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("dcradarzerotime_50_ns          = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("deldcstablecc_0                = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCEVT_0                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000380, .mask=0, .offset=0 },{
    CE_DEBUG_STR("evt_0_op_1                     = [0x%08x]  \n"), .addr=0, .mask=0xFC000000, .offset=26,                             },{
    CE_DEBUG_STR("evt_0_op_2                     = [0x%08x]  \n"), .addr=0, .mask=0x03F00000, .offset=20,                             },{
    CE_DEBUG_STR("evt_0_op_3                     = [0x%08x]  \n"), .addr=0, .mask=0x000FC000, .offset=14,                             },{
    CE_DEBUG_STR("evt_0_pathcomb                 = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("evt_0_opcomb                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("evt_0_tgtadd                   = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCEVT_1                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000384, .mask=0, .offset=0 },{
    CE_DEBUG_STR("evt_1_op_1                     = [0x%08x]  \n"), .addr=0, .mask=0xFC000000, .offset=26,                             },{
    CE_DEBUG_STR("evt_1_op_2                     = [0x%08x]  \n"), .addr=0, .mask=0x03F00000, .offset=20,                             },{
    CE_DEBUG_STR("evt_1_op_3                     = [0x%08x]  \n"), .addr=0, .mask=0x000FC000, .offset=14,                             },{
    CE_DEBUG_STR("evt_1_pathcomb                 = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("evt_1_opcomb                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("evt_1_tgtadd                   = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCEVT_2                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000388, .mask=0, .offset=0 },{
    CE_DEBUG_STR("evt_2_op_1                     = [0x%08x]  \n"), .addr=0, .mask=0xFC000000, .offset=26,                             },{
    CE_DEBUG_STR("evt_2_op_2                     = [0x%08x]  \n"), .addr=0, .mask=0x03F00000, .offset=20,                             },{
    CE_DEBUG_STR("evt_2_op_3                     = [0x%08x]  \n"), .addr=0, .mask=0x000FC000, .offset=14,                             },{
    CE_DEBUG_STR("evt_2_pathcomb                 = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("evt_2_opcomb                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("evt_2_tgtadd                   = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCEVT_3                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000038C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("evt_3_op_1                     = [0x%08x]  \n"), .addr=0, .mask=0xFC000000, .offset=26,                             },{
    CE_DEBUG_STR("evt_3_op_2                     = [0x%08x]  \n"), .addr=0, .mask=0x03F00000, .offset=20,                             },{
    CE_DEBUG_STR("evt_3_op_3                     = [0x%08x]  \n"), .addr=0, .mask=0x000FC000, .offset=14,                             },{
    CE_DEBUG_STR("evt_3_pathcomb                 = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("evt_3_opcomb                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("evt_3_tgtadd                   = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCNTL                    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000390, .mask=0, .offset=0 },{
    CE_DEBUG_STR("combpathsel                    = [0x%08x]  \n"), .addr=0, .mask=0xFC000000, .offset=26,                             },{
    CE_DEBUG_STR("gainkeep                       = [0x%08x]  \n"), .addr=0, .mask=0x03F00000, .offset=20,                             },{
    CE_DEBUG_STR("htstfgainen                    = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("noise_capture_delay_mode       = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("est_path_sel_2                 = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("cca_mdm_st_clear               = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("agcfsmreset                    = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("radardeten                     = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("rifsdeten                      = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("dsssonly                       = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("ofdmonly                       = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("gpstatus                       = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("est_path_sel                   = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("adc_sel_radar_detector         = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("adc_sel_comp_module            = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCDSP_0                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000394, .mask=0, .offset=0 },{
    CE_DEBUG_STR("nbitadc                        = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("vpeakadcqdbv                   = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("adcpowmindbv                   = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("adcpowbiasqdbv                 = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCDSP_1                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000398, .mask=0, .offset=0 },{
    CE_DEBUG_STR("adcpowmindbm                   = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("adcpowbiasqdbm                 = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCDSP_2                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000039C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpow_80_sbiasqdb            = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpow_40_sbiasqdb            = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpow_20_sbiasqdb            = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpow_20_pbiasqdb            = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCDSP_3                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003A0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpowmindbv                  = [0x%08x]  \n"), .addr=0, .mask=0x0FF00000, .offset=20,                             },{
    CE_DEBUG_STR("inbdrnd                        = [0x%08x]  \n"), .addr=0, .mask=0x00030000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpowmindbm_ant_1            = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpowmindbm_ant_0            = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCDSP_4                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003A4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("fe_80_gain                     = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("fe_40_gain                     = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("fe_20_gain                     = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCCA_0                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003A8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_inbd_pwr_sec_valid_num_sam = [0x%08x]  \n"), .addr=0, .mask=0xFE000000, .offset=25,                             },{
    CE_DEBUG_STR("cca_midpacket_agc_ctrl         = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("cca_midpacket_dsp_valid        = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("delccarampdntap                = [0x%08x]  \n"), .addr=0, .mask=0x00700000, .offset=20,                             },{
    CE_DEBUG_STR("delccarampuptap                = [0x%08x]  \n"), .addr=0, .mask=0x00070000, .offset=16,                             },{
    CE_DEBUG_STR("per_20_disccaen                = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("per_20_satccaen                = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("ccadetrampdn                   = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("ccadetrampup                   = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCCA_1                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003AC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_rate                   = [0x%08x]  \n"), .addr=0, .mask=0x60000000, .offset=29,                             },{
    CE_DEBUG_STR("inbdccapowmindbm               = [0x%08x]  \n"), .addr=0, .mask=0x1FF00000, .offset=20,                             },{
    CE_DEBUG_STR("ccafallthrdbm                  = [0x%08x]  \n"), .addr=0, .mask=0x000FF000, .offset=12,                             },{
    CE_DEBUG_STR("ccaenergy_reset_type           = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("disccaen                       = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("satccaen                       = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("ccarisethrdbm                  = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCCACTRL                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003B0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("ccaflag_3_ctrl                 = [0x%08x]  \n"), .addr=0, .mask=0xF0000000, .offset=28,                             },{
    CE_DEBUG_STR("ccaflag_2_ctrl                 = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("ccaflag_1_ctrl                 = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("ccaflag_0_ctrl                 = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("cca_second_ant_sel             = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("cca_main_ant_sel               = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("ccademod                       = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("ccacountersclock               = [0x%08x]  \n"), .addr=0, .mask=0x0000000C, .offset= 2,                             },{
    CE_DEBUG_STR("ccacountersreset               = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("ccacsen                        = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCCASTATE_0              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003B4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("ccamdmstforceen                = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("ccamdmstforce                  = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("rxstatecca_20_ssel             = [0x%08x]  \n"), .addr=0, .mask=0x00FFF000, .offset=12,                             },{
    CE_DEBUG_STR("rxstatecca_20_psel             = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCCASTATE_1              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003B8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rxstatecca_80_ssel             = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("rxstatecca_40_ssel             = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCCATIMEOUT              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003BC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("ccatimeout                     = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCOMP_0                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003C0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("idinbdpowgapdnqdbm             = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("idinbdpowgapupqdbm             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpowinfthrdbm               = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpowsupthrdbm               = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCOMP_1                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003C4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("adcpowinfthrdbv                = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("adcpowsupthrdbv                = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("adcpowinfthrdbm                = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("adcpowsupthrdbm                = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCRADAR                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003C8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("freqsinggap                    = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("freqsing                       = [0x%08x]  \n"), .addr=0, .mask=0x000FF000, .offset=12,                             },{
    CE_DEBUG_STR("fomsinggap                     = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("fomsing                        = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCRADARTIM                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003CC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("pulsetimerclear                = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("pulseirqfifothr                = [0x%08x]  \n"), .addr=0, .mask=0x001F0000, .offset=16,                             },{
    CE_DEBUG_STR("pulseirqtimeout                = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCCA_2                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003D0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("ccasgithr                      = [0x%08x]  \n"), .addr=0, .mask=0xF8000000, .offset=27,                             },{
    CE_DEBUG_STR("ccalgithr                      = [0x%08x]  \n"), .addr=0, .mask=0x07C00000, .offset=22,                             },{
    CE_DEBUG_STR("ccagisaten                     = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("ccagidisen                     = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("ccagifallthrdbm                = [0x%08x]  \n"), .addr=0, .mask=0x000FF000, .offset=12,                             },{
    CE_DEBUG_STR("giant_sel                      = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("ccanonheginbsymb               = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("ccagirisethrdbm                = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCAGENSTAT                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003D4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("frc_txendp_cnt                 = [0x%08x]  \n"), .addr=0, .mask=0xF0000000, .offset=28,                             },{
    CE_DEBUG_STR("frc_txstart_cnt                = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("cca_state_det_current          = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("cca_20_p_state_det_stat        = [0x%08x]  \n"), .addr=0, .mask=0x00080000, .offset=19,                             },{
    CE_DEBUG_STR("cca_20_p_rampup_det_stat       = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("cca_20_p_energy_det_stat       = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("cca_20_p_cs                    = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("cca_20_s_state_det_stat        = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("cca_20_s_rampup_det_stat       = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("cca_20_s_energy_det_stat       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("cca_20_s_gi_det_stat           = [0x%08x]  \n"), .addr=0, .mask=0x00001F00, .offset= 8,                             },{
    CE_DEBUG_STR("cca_40_s_state_det_stat        = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("cca_40_s_rampup_det_stat       = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("cca_40_s_energy_det_stat       = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("cca_40_s_gi_det_stat           = [0x%08x]  \n"), .addr=0, .mask=0x0000001F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCEVT_4                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003D8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("evt_4_op_1                     = [0x%08x]  \n"), .addr=0, .mask=0xFC000000, .offset=26,                             },{
    CE_DEBUG_STR("evt_4_op_2                     = [0x%08x]  \n"), .addr=0, .mask=0x03F00000, .offset=20,                             },{
    CE_DEBUG_STR("evt_4_op_3                     = [0x%08x]  \n"), .addr=0, .mask=0x000FC000, .offset=14,                             },{
    CE_DEBUG_STR("evt_4_pathcomb                 = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("evt_4_opcomb                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("evt_4_tgtadd                   = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCEVT_5                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003DC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("evt_5_op_1                     = [0x%08x]  \n"), .addr=0, .mask=0xFC000000, .offset=26,                             },{
    CE_DEBUG_STR("evt_5_op_2                     = [0x%08x]  \n"), .addr=0, .mask=0x03F00000, .offset=20,                             },{
    CE_DEBUG_STR("evt_5_op_3                     = [0x%08x]  \n"), .addr=0, .mask=0x000FC000, .offset=14,                             },{
    CE_DEBUG_STR("evt_5_pathcomb                 = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("evt_5_opcomb                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("evt_5_tgtaddr                  = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCEVT_6                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003E0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("evt_6_op_1                     = [0x%08x]  \n"), .addr=0, .mask=0xFC000000, .offset=26,                             },{
    CE_DEBUG_STR("evt_6_op_2                     = [0x%08x]  \n"), .addr=0, .mask=0x03F00000, .offset=20,                             },{
    CE_DEBUG_STR("evt_6_op_3                     = [0x%08x]  \n"), .addr=0, .mask=0x000FC000, .offset=14,                             },{
    CE_DEBUG_STR("evt_6_pathcomb                 = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("evt_6_opcomb                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("evt_6_tgtadd                   = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCEVT_7                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003E4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("evt_7_op_1                     = [0x%08x]  \n"), .addr=0, .mask=0xFC000000, .offset=26,                             },{
    CE_DEBUG_STR("evt_7_op_2                     = [0x%08x]  \n"), .addr=0, .mask=0x03F00000, .offset=20,                             },{
    CE_DEBUG_STR("evt_7_op_3                     = [0x%08x]  \n"), .addr=0, .mask=0x000FC000, .offset=14,                             },{
    CE_DEBUG_STR("evt_7_pathcomb                 = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("evt_7_opcomb                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("evt_7_tgtadd                   = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCEVTEXT                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003E8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("evt_7_ext                      = [0x%08x]  \n"), .addr=0, .mask=0xF0000000, .offset=28,                             },{
    CE_DEBUG_STR("evt_6_ext                      = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("evt_5_ext                      = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("evt_4_ext                      = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("evt_3_ext                      = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("evt_2_ext                      = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("evt_1_ext                      = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("evt_0_ext                      = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCDSP_5                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003EC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpowmindbm_ant_5            = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpowmindbm_ant_4            = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpowmindbm_ant_3            = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpowmindbm_ant_2            = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCCA_4                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003F0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("ccagi_pow_lim_thrd_bm          = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("ccagithrdbm_delta_80           = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("ccagithrdbm_delta_40           = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("ccagithrdbm_delta_per_20       = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DMAHWTRIG                      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000003FC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("trig_bitsel                    = [0x%08x]  \n"), .addr=0, .mask=0x001F0000, .offset=16,                             },{
    CE_DEBUG_STR("trig_delay                     = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("trig_cmd                       = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXDSPINTEN                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000400, .mask=0, .offset=0 },{
    CE_DEBUG_STR("irqdsprcrxenden                = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("irqdsprctxenden                = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("irqdsperrormdmben              = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("irqdsptxendmdmben              = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("irqdsprxendmdmben              = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("irqdsprxvectormdmben           = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("irqdsp_frc_rx_end_4_t_en       = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("irqdsp_frc_rx_sig_end_en       = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("irqdsp_frc_rx_phy_proc_lim_en  = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("irqdsplbcapturedoneen          = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("irqdspagcdssslocken            = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("irqdspagcdsssunlocken          = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("irqdsp_agc_fsm_3_en            = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("irqdspradartriggeren           = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("irqdspradardeten               = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("irqdsp_agc_fsm_2_en            = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("irqdsp_agc_fsm_1_en            = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("irqdsp_agc_fsm_0_en            = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("irqdspccatimeouten             = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("irqdspbtc_3_en                 = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("irqdspbtc_2_en                 = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("irqdspbtc_1_en                 = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("irqdspbtc_0_en                 = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("irqdspmputxenden               = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("irqdspagcofdmunlocktimeren     = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("irqdspagcofdmlocken            = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("irqdspagcofdmunlocken          = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXDSPINTSTATRAW              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000404, .mask=0, .offset=0 },{
    CE_DEBUG_STR("irqdsprcrxendraw               = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("irqdsprctxendraw               = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("irqdsperrormdmbraw             = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("irqdsptxendmdmbraw             = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("irqdsprxendmdmbraw             = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("irqdsprxvectormdmbraw          = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("irqdsp_frc_rx_end_4_t_raw      = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("irqdsp_frc_rx_sig_end_raw      = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("irqdsp_frc_rx_phy_proc_lim_raw = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("irqdsplbcapturedoneraw         = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("irqdspagcdssslockraw           = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("irqdspagcdsssunlockraw         = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("irqdsp_agc_fsm_3_raw           = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("irqdspradartriggerraw          = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("irqdspradardetraw              = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("irqdsp_agc_fsm_2_raw           = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("irqdsp_agc_fsm_1_raw           = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("irqdsp_agc_fsm_0_raw           = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("irqdspccatimeoutraw            = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("irqdspbtc_3_raw                = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("irqdspbtc_2_raw                = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("irqdspbtc_1_raw                = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("irqdspbtc_0_raw                = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("irqdspmputxendraw              = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("irqdspagcofdmunlocktimerraw    = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("irqdspagcofdmlockraw           = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("irqdspagcofdmunlockraw         = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXDSPINTSTATMASKED           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000408, .mask=0, .offset=0 },{
    CE_DEBUG_STR("irqdsprcrxendmasked            = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("irqdsprctxendmasked            = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("irqdsperrormdmbmasked          = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("irqdsptxendmdmbmasked          = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("irqdsprxendmdmbmasked          = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("irqdsprxvectormdmbmasked       = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("irqdsp_frc_rx_end_4_t_masked   = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("irqdsp_frc_rx_sig_end_masked   = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("irqdsp_frc_rx_proc_lim_masked  = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("irqdsplbcapturedonemasked      = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("irqdspagcdssslockmasked        = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("irqdspagcdsssunlockmasked      = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("irqdsp_agc_fsm_3_masked        = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("irqdspradartriggermasked       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("irqdspradardetmasked           = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("irqdsp_agc_fsm_2_masked        = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("irqdsp_agc_fsm_1_masked        = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("irqdsp_agc_fsm_0_masked        = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("irqdspccatimeoutmasked         = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("irqdspbtc_3_masked             = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("irqdspbtc_2_masked             = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("irqdspbtc_1_masked             = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("irqdspbtc_0_masked             = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("irqdspmputxendmasked           = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("irqdspagcofdmunlocktimermasked = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("irqdspagcofdmlockmasked        = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("irqdspagcofdmunlockmasked      = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXDSPINTACK                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000040C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("\t\t------ RWNXDSPINTGEN                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000410, .mask=0, .offset=0 },{
    CE_DEBUG_STR("\t\t------ RWNXMACINTEN                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000414, .mask=0, .offset=0 },{
    CE_DEBUG_STR("irqmacrcrxenden                = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("irqmacrctxenden                = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("irqmacerrormdmben              = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("irqmactxendmdmben              = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("irqmacrxendmdmben              = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("irqmacrxvectormdmben           = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("irqmac_frc_rx_end_4_t_en       = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("irqmac_frc_rx_sig_end_en       = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("irqmac_frc_rx_phy_proc_lim_en  = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("irqmaclbcapturedoneen          = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("irqmacagcdssslocken            = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("irqmacagcdsssunlocken          = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("irqmac_agc_fsm_3_en            = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("irqmacradartriggeren           = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("irqmacradardeten               = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("irqmac_agc_fsm_2_en            = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("irqmac_agc_fsm_1_en            = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("irqmac_agc_fsm_0_en            = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("irqmacccatimeouten             = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("irqmacbtc_3_en                 = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("irqmacbtc_2_en                 = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("irqmacbtc_1_en                 = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("irqmacbtc_0_en                 = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("irqmacmputxenden               = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("irqmacagcofdmunlocktimeren     = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("irqmacagcofdmlocken            = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("irqmacagcofdmunlocken          = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXMACINTSTATRAW              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000418, .mask=0, .offset=0 },{
    CE_DEBUG_STR("irqmacrcrxendraw               = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("irqmacrctxendraw               = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("irqmacerrormdmbraw             = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("irqmactxendmdmbraw             = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("irqmacrxendmdmbraw             = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("irqmacrxvectormdmbraw          = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("irqmac_frc_rx_end_4_t_raw      = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("irqmac_frc_rx_sig_end_raw      = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("irqmac_frc_rx_phy_proc_lim_raw = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("irqmaclbcapturedoneraw         = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("irqmacagcdssslockraw           = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("irqmacagcdsssunlockraw         = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("irqmac_agc_fsm_3_raw           = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("irqmacradartriggerraw          = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("irqmacradardetraw              = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("irqmac_agc_fsm_2_raw           = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("irqmac_agc_fsm_1_raw           = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("irqmac_agc_fsm_0_raw           = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("irqmacccatimeoutraw            = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("irqmacbtc_3_raw                = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("irqmacbtc_2_raw                = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("irqmacbtc_1_raw                = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("irqmacbtc_0_raw                = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("irqmacmputxendraw              = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("irqmacagcofdmunlocktimerraw    = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("irqmacagcofdmlockraw           = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("irqmacagcofdmunlockraw         = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXMACINTSTATMASKED           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000041C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("irqmacrcrxendmasked            = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("irqmacrctxendmasked            = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("irqmacerrormdmbmasked          = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("irqmactxendmdmbmasked          = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("irqmacrxendmdmbmasked          = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("irqmacrxvectormdmbmasked       = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("irqmac_frc_rx_end_4_t_masked   = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("irqmac_frc_rx_sig_end_masked   = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("irqmac_frc_rx_phy_proc_lim_mas = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("irqmaclbcapturedonemasked      = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("irqmacagcdssslockmasked        = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("irqmacagcdsssunlockmasked      = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("irqmac_agc_fsm_3_masked        = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("irqmacradartriggermasked       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("irqmacradardetmasked           = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("irqmac_agc_fsm_2_masked        = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("irqmac_agc_fsm_1_masked        = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("irqmac_agc_fsm_0_masked        = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("irqmacccatimeoutmasked         = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("irqmacbtc_3_masked             = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("irqmacbtc_2_masked             = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("irqmacbtc_1_masked             = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("irqmacbtc_0_masked             = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("irqmacmputxendmasked           = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("irqmacagcofdmunlocktimermasked = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("irqmacagcofdmlockmasked        = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("irqmacagcofdmunlockmasked      = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXMACINTACK                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000420, .mask=0, .offset=0 },{
    CE_DEBUG_STR("\t\t------ RWNXMACINTGEN                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000424, .mask=0, .offset=0 },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCCA_3                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000428, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_inbd_pwr_valid_num_samples = [0x%08x]  \n"), .addr=0, .mask=0xFE000000, .offset=25,                             },{
    CE_DEBUG_STR("ccahe_32_githr                 = [0x%08x]  \n"), .addr=0, .mask=0x01F00000, .offset=20,                             },{
    CE_DEBUG_STR("ccahe_16_githr                 = [0x%08x]  \n"), .addr=0, .mask=0x0001F000, .offset=12,                             },{
    CE_DEBUG_STR("ccahe_08_githr                 = [0x%08x]  \n"), .addr=0, .mask=0x000001F0, .offset= 4,                             },{
    CE_DEBUG_STR("ccaheginbsymb                  = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCCCACTRL_3               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000042C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("ccaoutresetcommand_1           = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("ccaper_20_mode                 = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("ccagien                        = [0x%08x]  \n"), .addr=0, .mask=0x03C00000, .offset=22,                             },{
    CE_DEBUG_STR("ccarampuden                    = [0x%08x]  \n"), .addr=0, .mask=0x003FF800, .offset=11,                             },{
    CE_DEBUG_STR("ccaenergyen                    = [0x%08x]  \n"), .addr=0, .mask=0x000007FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCAGENSTAT_2                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000434, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_20_s_7_energy_det_stat     = [0x%08x]  \n"), .addr=0, .mask=0x00080000, .offset=19,                             },{
    CE_DEBUG_STR("cca_20_s_6_energy_det_stat     = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("cca_20_s_5_energy_det_stat     = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("cca_20_s_4_energy_det_stat     = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("cca_20_s_3_energy_det_stat     = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("cca_20_s_2_energy_det_stat     = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("cca_80_s_state_det_stat        = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("cca_80_s_rampup_det_stat       = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("cca_80_s_energy_det_stat       = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("cca_80_s_gi_det_stat           = [0x%08x]  \n"), .addr=0, .mask=0x000007C0, .offset= 6,                             },{
    CE_DEBUG_STR("cca_20_p_2_energy_det_stat     = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("cca_20_p_gi_det_stat           = [0x%08x]  \n"), .addr=0, .mask=0x0000001F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LPF_160_PCOEFF_0               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000440, .mask=0, .offset=0 },{
    CE_DEBUG_STR("h_2_48                         = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("h_1_49                         = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("h_0_50                         = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LPF_160_PCOEFF_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000444, .mask=0, .offset=0 },{
    CE_DEBUG_STR("h_5_45                         = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("h_4_46                         = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("h_3_47                         = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LPF_160_PCOEFF_2               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000448, .mask=0, .offset=0 },{
    CE_DEBUG_STR("h_8_42                         = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("h_7_43                         = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("h_6_44                         = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LPF_160_PCOEFF_3               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000044C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("h_11_39                        = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("h_10_40                        = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("h_9_41                         = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LPF_160_PCOEFF_4               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000450, .mask=0, .offset=0 },{
    CE_DEBUG_STR("h_14_36                        = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("h_13_37                        = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("h_12_38                        = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LPF_160_PCOEFF_5               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000454, .mask=0, .offset=0 },{
    CE_DEBUG_STR("h_17_33                        = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("h_16_34                        = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("h_15_35                        = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LPF_160_PCOEFF_6               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000458, .mask=0, .offset=0 },{
    CE_DEBUG_STR("h_20_30                        = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("h_19_31                        = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("h_18_32                        = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LPF_160_PCOEFF_7               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000045C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("h_23_27                        = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("h_22_28                        = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("h_21_29                        = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LPF_160_PCOEFF_8               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000460, .mask=0, .offset=0 },{
    CE_DEBUG_STR("h_25                           = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("h_24_26                        = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LPF_160_BYPASS                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000464, .mask=0, .offset=0 },{
    CE_DEBUG_STR("bypass_type                    = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("bypass_mode                    = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCINBDPOWPER_20_STAT_0        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000470, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpowdbmper_20_3             = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpowdbmper_20_2             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpowdbmper_20_1             = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpowdbmper_20_0             = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCINBDPOWPER_20_STAT_1        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000474, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpowdbmper_20_7             = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpowdbmper_20_6             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpowdbmper_20_5             = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpowdbmper_20_4             = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCINBDPOWNOISEPER_20_STAT_0   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000478, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpownoisedbmper_20_3        = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpownoisedbmper_20_2        = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpownoisedbmper_20_1        = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpownoisedbmper_20_0        = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCINBDPOWNOISEPER_20_STAT_1   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000047C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpownoisedbmper_20_7        = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpownoisedbmper_20_6        = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpownoisedbmper_20_5        = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpownoisedbmper_20_4        = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ INBDPOWFORMAC_0                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000480, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpow_20_pdbma_3_mac         = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpow_20_pdbma_2_mac         = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpow_20_pdbma_1_mac         = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpow_20_pdbma_0_mac         = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ INBDPOWFORMAC_1                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000484, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpow_20_pdbma_5_mac         = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpow_20_pdbma_4_mac         = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ INBDPOWFORMAC_2                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000488, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpow_80_sdbm_mac            = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpow_40_sdbm_mac            = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpow_20_sdbm_mac            = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ INBDPOWFORMAC_3                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000048C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpowper_20_pdbm_3_mac       = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpowper_20_pdbm_2_mac       = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpowper_20_pdbm_1_mac       = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpowper_20_pdbm_0_mac       = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ INBDPOWFORMAC_4                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000490, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpowper_20_pdbm_7_mac       = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpowper_20_pdbm_6_mac       = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpowper_20_pdbm_5_mac       = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpowper_20_pdbm_4_mac       = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_GI_20_S                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000494, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_gi_20_s                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_GI_40_S                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000498, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_gi_40_s                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_GI_80_S                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000049C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_gi_80_s                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_ENERGY_THR_40_S        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004A0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_energy_thr_40_s        = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_ENERGY_THR_80_S        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004A4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_energy_thr_80_s        = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_ENERGY_THR_20_BAND_0   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004A8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_energy_thr_20_band_0   = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_ENERGY_THR_20_BAND_1   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004AC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_energy_thr_20_band_1   = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_ENERGY_THR_20_BAND_2   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004B0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_energy_thr_20_band_2   = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_ENERGY_THR_20_BAND_3   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004B4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_energy_thr_20_band_3   = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_ENERGY_THR_20_BAND_4   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004B8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_energy_thr_20_band_4   = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_ENERGY_THR_20_BAND_5   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004BC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_energy_thr_20_band_5   = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_ENERGY_THR_20_BAND_6   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004C0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_energy_thr_20_band_6   = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_CNT_ENERGY_THR_20_BAND_7   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004C4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_cnt_energy_thr_20_band_7   = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_0_COEF_3               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004C8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_11         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_10         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_9          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_1_COEF_3               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004CC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_11         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_10         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_9          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RX_FRONT_END_DELAY             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004D0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_fe_delay_160_en             = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("rx_fe_delay_80_en              = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("rx_fe_delay_40_en              = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("rx_fe_delay_160                = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rx_fe_delay_80                 = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("rx_fe_delay_40                 = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCDSP_6                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004D4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("sensitivity_sel_stat           = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("sw_sensitivity_sel_force       = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("sw_sensitivity_sel             = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("inbdpowmindbm_ant_1_set_1      = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("inbdpowmindbm_ant_0_set_1      = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_THRES                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004D8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_third_point_type          = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("iqdc_vga_thres_b               = [0x%08x]  \n"), .addr=0, .mask=0x00003E00, .offset= 9,                             },{
    CE_DEBUG_STR("iqdc_vga_thres_a               = [0x%08x]  \n"), .addr=0, .mask=0x000001F0, .offset= 4,                             },{
    CE_DEBUG_STR("iqdc_lna_thres                 = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ PTA_CS_FLAG_CTRL               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004DC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("pta_ccaflag_3                  = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("pta_ccaflag_2                  = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("pta_ccaflag_1                  = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("pta_ccaflag_0                  = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RX_INDICATIONS_TO_PTA_CTRL     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004E0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("pta_rxindication_status        = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("pta_ed_20_p_src_en             = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("pta_cs_src_en                  = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("pta_midpacket_20_p_src_en      = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("pta_mdm_state                  = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RX_INDICATIONS_TO_PTA_FORCE_OV [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004E4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("pta_rxindication_force_overrid = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("pta_force_rx_indication_value  = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCGAINCALIBSTAT               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004E8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcgaincalib_3                 = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("agcgaincalib_2                 = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("agcgaincalib_1                 = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("agcgaincalib_0                 = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCRFGAINCALIBSTAT             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004EC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcrfgaincalib_2               = [0x%08x]  \n"), .addr=0, .mask=0x1FF00000, .offset=20,                             },{
    CE_DEBUG_STR("agcrfgaincalib_1               = [0x%08x]  \n"), .addr=0, .mask=0x0007FC00, .offset=10,                             },{
    CE_DEBUG_STR("agcrfgaincalib_0               = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCRFGAINCALIBSTAT_1           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004F0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcrfgaincalib_3               = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_3_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004F4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_11         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_10         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_9          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_3_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004F8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_11         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_10         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_9          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_THRES                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000004FC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_third_point_type          = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("iqdc_vga_thres_b               = [0x%08x]  \n"), .addr=0, .mask=0x00003E00, .offset= 9,                             },{
    CE_DEBUG_STR("iqdc_vga_thres_a               = [0x%08x]  \n"), .addr=0, .mask=0x000001F0, .offset= 4,                             },{
    CE_DEBUG_STR("iqdc_lna_thres                 = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FEBCNTL                        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000500, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txnorm                         = [0x%08x]  \n"), .addr=0, .mask=0xFC000000, .offset=26,                             },{
    CE_DEBUG_STR("maxstage                       = [0x%08x]  \n"), .addr=0, .mask=0x03F00000, .offset=20,                             },{
    CE_DEBUG_STR("rxshift_4044                   = [0x%08x]  \n"), .addr=0, .mask=0x00070000, .offset=16,                             },{
    CE_DEBUG_STR("txshift_4044                   = [0x%08x]  \n"), .addr=0, .mask=0x0000C000, .offset=14,                             },{
    CE_DEBUG_STR("btxpathselreg                  = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("brxpathselreg                  = [0x%08x]  \n"), .addr=0, .mask=0x000000E0, .offset= 5,                             },{
    CE_DEBUG_STR("rxpathselfromreg               = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("firdisb                        = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("gaindisb                       = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("interpdisb                     = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("fircoefsel                     = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBCNTL                       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000504, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqmmdisb                       = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("precompdisb                    = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("dcoffdisb                      = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("compdisb                       = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("eqdisb                         = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("spreaddisb                     = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("scrambdisb                     = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("sfderr                         = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("sfdlen                         = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("prepre                         = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBPRMINIT                    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000508, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rho                            = [0x%08x]  \n"), .addr=0, .mask=0x00300000, .offset=20,                             },{
    CE_DEBUG_STR("mu                             = [0x%08x]  \n"), .addr=0, .mask=0x00030000, .offset=16,                             },{
    CE_DEBUG_STR("beta                           = [0x%08x]  \n"), .addr=0, .mask=0x00000030, .offset= 4,                             },{
    CE_DEBUG_STR("alpha                          = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBTALPHA                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000050C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("talpha_3                       = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("talpha_2                       = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("talpha_1                       = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("talpha_0                       = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBTBETA                      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000510, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tbeta_3                        = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("tbeta_2                        = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("tbeta_1                        = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("tbeta_0                        = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBTMU                        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000514, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tmu_3                          = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("tmu_2                          = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("tmu_1                          = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("tmu_0                          = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBCNTL_1                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000518, .mask=0, .offset=0 },{
    CE_DEBUG_STR("mdmb_exit_forced               = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("mdmb_exit_on_ofdmlock          = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("mdmb_exit_on_dsssunlock        = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("rxlenchken                     = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("rxmaxlength                    = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBRFCNTL                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000051C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txenddel                       = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBEQCNTL                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000520, .mask=0, .offset=0 },{
    CE_DEBUG_STR("eqhold                         = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("comptime                       = [0x%08x]  \n"), .addr=0, .mask=0x00007C00, .offset=10,                             },{
    CE_DEBUG_STR("esttime                        = [0x%08x]  \n"), .addr=0, .mask=0x000003E0, .offset= 5,                             },{
    CE_DEBUG_STR("eqtime                         = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBCNTL_2                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000524, .mask=0, .offset=0 },{
    CE_DEBUG_STR("precomp                        = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("synctime                       = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("looptime                       = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBSTAT_0                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000528, .mask=0, .offset=0 },{
    CE_DEBUG_STR("eqsumq                         = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("eqsumi                         = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("dcoffsetq                      = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("dcoffseti                      = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBSTAT_1                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000052C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rxerrorstat                    = [0x%08x]  \n"), .addr=0, .mask=0xC0000000, .offset=30,                             },{
    CE_DEBUG_STR("evm                            = [0x%08x]  \n"), .addr=0, .mask=0x1FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqgainestim                    = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("freqoffestim                   = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBTXVECTOR                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000530, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tx_pre_type                    = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("tx_leg_rate                    = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("tx_service                     = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("tx_leg_length                  = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBRXVECTORSTAT               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000534, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_pre_type                    = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("rx_leg_rate                    = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("rx_service                     = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rx_leg_length                  = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MDMBSTAT_2                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000538, .mask=0, .offset=0 },{
    CE_DEBUG_STR("ant_sel_dsss_stat              = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HE_LTF_ANTENNA_HOPPING_SEQ     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000540, .mask=0, .offset=0 },{
    CE_DEBUG_STR("he_ltf_antenna_hopping_seq     = [0x%08x]  \n"), .addr=0, .mask=0x0000FFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ START_HE_LTF_RX                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000054C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("start_he_ltf_rx_cancel         = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("start_he_ltf_rx_target         = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HE_LTF_RX_PARAMS               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000550, .mask=0, .offset=0 },{
    CE_DEBUG_STR("he_ltf_rx_nun_of_sym           = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("he_ltf_rx_duration             = [0x%08x]  \n"), .addr=0, .mask=0x0000FFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_CHAIN_0_0      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000554, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_th_20_s_0      = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_th_20_0        = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_CHAIN_0_1      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000558, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_th_80_0        = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_th_40_0        = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_CHAIN_0_2      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000055C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_th_160_0       = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_CHAIN_1_0      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000560, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_th_20_s_1      = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_th_20_1        = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_CHAIN_1_1      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000564, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_th_80_1        = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_th_40_1        = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_CTRL_CHAIN_1_2 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000568, .mask=0, .offset=0 },{
    CE_DEBUG_STR("sat_cnt_clear                  = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("sat_cnt_en                     = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_th_160_1       = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_20_P_STAT_0    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000056C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_20_p_stat_0    = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_20_S_STAT_0    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000570, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_20_s_stat_0    = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_40_STAT_0      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000574, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_40_stat_0      = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_80_STAT_0      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000578, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_80_stat_0      = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_160_STAT_0     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000057C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_160_stat_0     = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCRSSILNA_0_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000580, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rssi_lna_3_db                  = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("rssi_lna_2_db                  = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rssi_lna_1_db                  = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("rssi_lna_0_db                  = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCRSSILNA_1_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000584, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rssi_lna_7_db                  = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("rssi_lna_6_db                  = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rssi_lna_5_db                  = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("rssi_lna_4_db                  = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCRSSILNA_2_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000588, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rssi_lna_11_db                 = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("rssi_lna_10_db                 = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rssi_lna_9_db                  = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("rssi_lna_8_db                  = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCRSSILNA_3_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000058C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rssi_lna_15_db                 = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("rssi_lna_14_db                 = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rssi_lna_13_db                 = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("rssi_lna_12_db                 = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAGAINSET_1_REF_0      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000590, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_3_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_2_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_1_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_0_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAGAINSET_1_REF_1      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000594, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_7_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_6_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_5_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_4_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAGAINSET_1_REF_2      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000598, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_11_gaindb                  = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_10_gaindb                  = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_9_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_8_gaindb                   = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAGAINSET_1_REF_3      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000059C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_15_gaindb                  = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_14_gaindb                  = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_13_gaindb                  = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_12_gaindb                  = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNANFSET_1_REF_0        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005A0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_3_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_2_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_1_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_0_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNANFSET_1_REF_1        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005A4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_7_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_6_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_5_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_4_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNANFSET_1_REF_2        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005A8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_11_nfdb                    = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_10_nfdb                    = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_9_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_8_nfdb                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNANFSET_1_REF_3        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005AC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_15_nfdb                    = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_14_nfdb                    = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_13_nfdb                    = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_12_nfdb                    = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAICP_1_SET_1_REF_0    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005B0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_3_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_2_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_1_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_0_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAICP_1_SET_1_REF_1    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005B4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_7_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_6_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_5_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_4_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAICP_1_SET_1_REF_2    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005B8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_11_icp_1_db                = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_10_icp_1_db                = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_9_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_8_icp_1_db                 = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAICP_1_SET_1_REF_3    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005BC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_15_icp_1_db                = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_14_icp_1_db                = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_13_icp_1_db                = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_12_icp_1_db                = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_3_REF_0       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005C0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_3_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_2_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_1_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_0_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_3_REF_1       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005C4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_7_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_6_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_5_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_4_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_3_REF_2       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005C8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_11_thrset_0_db             = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_10_thrset_0_db             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_9_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_8_thrset_0_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_3_REF_3       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005CC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_14_thrset_0_db             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_13_thrset_0_db             = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_12_thrset_0_db             = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_4_REF_0       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005D0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_3_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_2_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_1_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_0_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_4_REF_1       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005D4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_7_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_6_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_5_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_4_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_4_REF_2       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005D8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_11_thrset_1_db             = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_10_thrset_1_db             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_9_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_8_thrset_1_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_4_REF_3       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005DC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_14_thrset_1_db             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_13_thrset_1_db             = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_12_thrset_1_db             = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_5_REF_0       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005E0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_3_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_2_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_1_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_0_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_5_REF_1       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005E4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_7_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_6_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_5_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_4_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_5_REF_2       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005E8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_11_thrset_2_db             = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("lna_10_thrset_2_db             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_9_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_8_thrset_2_db              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNATHRSET_5_REF_3       [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005EC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lna_14_thrset_2_db             = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("lna_13_thrset_2_db             = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("lna_12_thrset_2_db             = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCLNAGAPSET_1             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005F0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("sdrx_2                         = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("lna_3_max                      = [0x%08x]  \n"), .addr=0, .mask=0x70000000, .offset=28,                             },{
    CE_DEBUG_STR("snrgapdb                       = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("sdrgapdb                       = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DIGGAININBDDIFFTABLE_01        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005F4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dig_gain_inbd_diff_table_1     = [0x%08x]  \n"), .addr=0, .mask=0x007FF000, .offset=12,                             },{
    CE_DEBUG_STR("dig_gain_inbd_diff_table_0     = [0x%08x]  \n"), .addr=0, .mask=0x000007FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DIGGAININBDDIFFTABLE_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000005F8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dig_gain_inbd_diff_table_2     = [0x%08x]  \n"), .addr=0, .mask=0x000007FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACIMARGLATE             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000600, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_160_marglate               = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_80_marglate                = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_40_marglate                = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_20_marglate                = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACI_160_MARG_0          [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000604, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_160_margmcs_3              = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_160_margmcs_2              = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_160_margmcs_1              = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_160_margmcs_0              = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACI_160_MARG_1          [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000608, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_160_margmcs_7              = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_160_margmcs_6              = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_160_margmcs_5              = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_160_margmcs_4              = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXAGCACI_160_MARG_2          [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000060C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("aci_160_margmcs_11             = [0x%08x]  \n"), .addr=0, .mask=0x3F000000, .offset=24,                             },{
    CE_DEBUG_STR("aci_160_margmcs_10             = [0x%08x]  \n"), .addr=0, .mask=0x003F0000, .offset=16,                             },{
    CE_DEBUG_STR("aci_160_margmcs_9              = [0x%08x]  \n"), .addr=0, .mask=0x00003F00, .offset= 8,                             },{
    CE_DEBUG_STR("aci_160_margmcs_8              = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ HBF_SEL                        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000610, .mask=0, .offset=0 },{
    CE_DEBUG_STR("hbf_160_sel_tx                 = [0x%08x]  \n"), .addr=0, .mask=0x38000000, .offset=27,                             },{
    CE_DEBUG_STR("hbf_80_sel_tx                  = [0x%08x]  \n"), .addr=0, .mask=0x07000000, .offset=24,                             },{
    CE_DEBUG_STR("hbf_80_sel_rx_1                = [0x%08x]  \n"), .addr=0, .mask=0x00E00000, .offset=21,                             },{
    CE_DEBUG_STR("hbf_80_sel_rx_0                = [0x%08x]  \n"), .addr=0, .mask=0x001C0000, .offset=18,                             },{
    CE_DEBUG_STR("hbf_40_sel_tx                  = [0x%08x]  \n"), .addr=0, .mask=0x00038000, .offset=15,                             },{
    CE_DEBUG_STR("hbf_40_sel_rx_1                = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("hbf_40_sel_rx_0                = [0x%08x]  \n"), .addr=0, .mask=0x00000E00, .offset= 9,                             },{
    CE_DEBUG_STR("hbf_20_sel_tx                  = [0x%08x]  \n"), .addr=0, .mask=0x000001C0, .offset= 6,                             },{
    CE_DEBUG_STR("hbf_20_sel_rx_1                = [0x%08x]  \n"), .addr=0, .mask=0x00000038, .offset= 3,                             },{
    CE_DEBUG_STR("hbf_20_sel_rx_0                = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DC_SCALE_1                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000614, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dc_scale_set_1_160             = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("dc_scale_set_1_80              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("dc_scale_set_1_40              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("dc_scale_set_1_20              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ SW_TO_AGC_FSM_IND              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000618, .mask=0, .offset=0 },{
    CE_DEBUG_STR("sw_to_agc_fsm_ind              = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGC_FSM_TO_SW_IND              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000061C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agc_fsm_to_sw_ind              = [0x%08x]  \n"), .addr=0, .mask=0x00FFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FRC_AGC_GP_LO                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000620, .mask=0, .offset=0 },{
    CE_DEBUG_STR("frc_agc_gp_cc                  = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("frc_agc_gp_more                = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("frc_agc_gp_29_0                = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FTM_RXEND_LO                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000624, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rxend_lo_cc                    = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("rxend_more                     = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("rxend_29_0                     = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FTM_TXREQ_LO                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000628, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txreq_lo_cc                    = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("txreq_more                     = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("txreq_29_0                     = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FRC_UNLOCK_LO                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000062C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("frc_unlock_cc                  = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("frc_unlock_more                = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("frc_unlock_29_0                = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FRC_40_MHZ_LO                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000630, .mask=0, .offset=0 },{
    CE_DEBUG_STR("frc_40_mhz_cc                  = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("frc_40_mhz_29_0                = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FTM_TXEND_TRGT                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000634, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txend_cancel                   = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("txend_target                   = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FTM_TXREQ_FALL_LO              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000638, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txreq_fall_lo_cc               = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("txreq_fall_more                = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("txreq_fall_29_0                = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FTM_RXREQ_FALL_LO              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000063C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rxreq_fall_lo_cc               = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("rxreq_fall_more                = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("rxreq_fall_29_0                = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXTXFEDELAY_160              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000640, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txenddelay_160                 = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("dspfedcnodelayen               = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("fedcnodelayhbf_160             = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("fedcnodelayhbf_80              = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("fedcnodelayhbf_40              = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("fedcnodelayhbf_20              = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("txfedelay_160                  = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXDSPINTSTATREV              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000644, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rev_irqdspagcofdmunlockmasked  = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("rev_irqdspagcofdmlockmasked    = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("rev_irqdspagcofdmunlocktimerma = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("rev_irqdspmputxendmasked       = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("rev_irqdspbtc_0_masked         = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("rev_irqdspbtc_1_masked         = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("rev_irqdspbtc_2_masked         = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("rev_irqdspbtc_3_masked         = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("rev_irqdspccatimeoutmasked     = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("rev_irqdsp_agc_fsm_0_masked    = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("rev_irqdsp_agc_fsm_1_masked    = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("rev_irqdsp_agc_fsm_2_masked    = [0x%08x]  \n"), .addr=0, .mask=0x00080000, .offset=19,                             },{
    CE_DEBUG_STR("rev_irqdspradardetmasked       = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("rev_irqdspradartriggermasked   = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("rev_irqdsp_agc_fsm_3_masked    = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("rev_irqdspagcdsssunlockmasked  = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("rev_irqdspagcdssslockmasked    = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("rev_irqdsplbcapturedonemasked  = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("rev_irqdsp_frc_rx_phy_proc_lim = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("rev_irqdsp_frc_rx_sig_end_mask = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("rev_irqdsp_frc_rx_end_4_t_mask = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("rev_irqdsprxvectormdmbmasked   = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("rev_irqdsprxendmdmbmasked      = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("rev_irqdsptxendmdmbmasked      = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("rev_irqdsperrormdmbmasked      = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("rev_irqdsprctxendmasked        = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("rev_irqdsprcrxendmasked        = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("\t\t------ AGCGAINSTAT_3                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000648, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcrfgain_5_extlna             = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("agcrfgain_5_lna                = [0x%08x]  \n"), .addr=0, .mask=0x0E000000, .offset=25,                             },{
    CE_DEBUG_STR("agcrfgain_5_vga                = [0x%08x]  \n"), .addr=0, .mask=0x01F00000, .offset=20,                             },{
    CE_DEBUG_STR("agcrfgain_4_extlna             = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("agcrfgain_4_lna                = [0x%08x]  \n"), .addr=0, .mask=0x00038000, .offset=15,                             },{
    CE_DEBUG_STR("agcrfgain_4_vga                = [0x%08x]  \n"), .addr=0, .mask=0x00007C00, .offset=10,                             },{
    CE_DEBUG_STR("agcrfgain_3_extlna             = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("agcrfgain_3_lna                = [0x%08x]  \n"), .addr=0, .mask=0x000000E0, .offset= 5,                             },{
    CE_DEBUG_STR("agcrfgain_3_vga                = [0x%08x]  \n"), .addr=0, .mask=0x0000001F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DC_SCALE_2                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000064C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dc_scale_set_2_160             = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("dc_scale_set_2_80              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("dc_scale_set_2_40              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("dc_scale_set_2_20              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ TXFE_DELAY_LUT_0               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000650, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txfe_11_b_dly_chbw_80          = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("txfe_11_b_dly_chbw_40          = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("txfe_11_b_dly_chbw_20          = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ TXFE_DELAY_LUT_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000654, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txfe_20_dly_chbw_80            = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("txfe_20_dly_chbw_40            = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("txfe_20_dly_chbw_20            = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ TXFE_DELAY_LUT_2               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000658, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txfe_80_dly_chbw_80            = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("txfe_40_dly_chbw_80            = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("txfe_40_dly_chbw_40            = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXIQCTRL_2                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000065C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("txiqswappath_4                 = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("txiqswappath_5                 = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("rxiqswappath_5                 = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("txiqdelpathq_5                 = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("txiqdelpathi_5                 = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("txiqdelpathq_4                 = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("txiqdelpathi_4                 = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("rxiqdelpathq_5                 = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("rxiqdelpathi_5                 = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXFECTRL_5                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000660, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tx_160_diggainlin_4            = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("tx_80_diggainlin_4             = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("tx_40_diggainlin_4             = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("tx_20_diggainlin_4             = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXFECTRL_6                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000664, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tx_160_diggainlin_5            = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("tx_80_diggainlin_5             = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("tx_40_diggainlin_5             = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("tx_20_diggainlin_5             = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RWNXFECTRL_7                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000668, .mask=0, .offset=0 },{
    CE_DEBUG_STR("fecfsctrl                      = [0x%08x]  \n"), .addr=0, .mask=0xFE000000, .offset=25,                             },{
    CE_DEBUG_STR("dspextctrlen                   = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("extfectrl                      = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("dspcfsctrlen                   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("btxdiggainlin_5                = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("btxdiggainlin_4                = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCGAINSTAT_2                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000066C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("agcrfgain_5                    = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("agcrfgain_4                    = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("agcgain_5                      = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("agcgain_4                      = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCADCPOWSTAT_2                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000670, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpow_20_pdbm_5              = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpow_20_pdbm_4              = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("adcpowdbv_5                    = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("adcpowdbv_4                    = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCDIGGAIN_4_STAT              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000674, .mask=0, .offset=0 },{
    CE_DEBUG_STR("diggain_160_ant_4              = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("diggain_80_ant_4               = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("diggain_40_ant_4               = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("diggain_20_ant_4               = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCDIGGAIN_5_STAT              [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000678, .mask=0, .offset=0 },{
    CE_DEBUG_STR("diggain_160_ant_5              = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("diggain_80_ant_5               = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("diggain_40_ant_5               = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("diggain_20_ant_5               = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AGCINBDPOW_20_PNOISESTAT_2     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000067C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("inbdpow_20_pnoisedbm_5         = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("inbdpow_20_pnoisedbm_4         = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("adcpowdbm_5                    = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("adcpowdbm_4                    = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_4_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000680, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_14         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_13         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_12         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_5_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000684, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_17         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_16         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_15         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_6_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000688, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_20         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_19         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_18         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_4_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000068C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_14         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_13         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_12         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_5_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000690, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_17         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_16         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_15         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_6_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000694, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_20         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_19         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_18         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_4_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000698, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_14         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_13         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_12         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_5_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000069C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_17         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_16         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_15         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_6_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006A0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_20         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_19         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_18         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_0_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006A8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_2          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_1          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_0          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_1_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006AC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_5          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_4          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_3          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_2_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006B0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_8          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_7          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_6          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_3_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006B4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_11         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_10         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_9          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_0_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006B8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_2          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_1          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_0          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_1_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006BC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_5          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_4          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_3          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_2_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006C0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_8          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_7          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_6          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_3_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006C4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_11         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_10         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_9          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_DC                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006C8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_dcq                  = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqdc_rx_0_dci                  = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_DC                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006CC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_dcq                  = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqdc_rx_1_dci                  = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ LBRXSEL                        [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006D0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lbrxselmsb                     = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("lbrxsellsb                     = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ START_ESTIM_FRC                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006D4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("start_estim_frc_cancel         = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("start_estim_frc_target         = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ GAIN_UP_FRC                    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006D8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("gain_up_frc_cancel             = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("gain_up_frc_target             = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RX_END_4_T_FRC                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006DC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_end_4_t_frc_cancel          = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("rx_end_4_t_frc_target          = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RX_PHY_PROC_LIM_FRC            [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006E0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_phy_proc_lim_frc_cancel     = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("rx_phy_proc_lim_frc_target     = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RX_SIG_END_FRC                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006E4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_sig_end_frc_cancel          = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("rx_sig_end_frc_target          = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RX_AGC_BLOCK_END_FRC           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006E8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_agc_block_end_frc_cancel    = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("rx_agc_block_end_frc_target    = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RX_AGC_EVENT_FRC               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006EC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_agc_event_frc_cancel        = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("rx_agc_event_frc_target        = [0x%08x]  \n"), .addr=0, .mask=0x3FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FRC_COMP_STAT_1                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006F0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("frc_agc_event_cnt              = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("frc_agc_block_end_cnt          = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("frc_rx_sig_end_cnt             = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("frc_rx_phy_proc_lim_cnt        = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("frc_rx_end_4_t_cnt             = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("frc_gain_up_cnt                = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("frc_start_estim_cnt            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FRC_COMP_STAT_2                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000006F4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("frc_start_he_ltf_rx_cnt        = [0x%08x]  \n"), .addr=0, .mask=0x00078000, .offset=15,                             },{
    CE_DEBUG_STR("frc_start_he_ltf_rx_miss       = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("frc_agc_event_miss             = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("frc_agc_block_end_miss         = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("frc_rx_sig_end_miss            = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("frc_rx_phy_proc_lim_miss       = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("frc_rx_end_4_t_miss            = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("frc_gain_up_miss               = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("frc_start_estim_miss           = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("frc_txstart_miss               = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("frc_txend_miss                 = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_0_COEF_0               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000700, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_2          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_1          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_0          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_0_COEF_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000704, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_5          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_4          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_3          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_0_COEF_2               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000708, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_8          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_7          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_6          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_GAIN_SET_2           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000070C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_phase_gain           = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqdc_rx_1_amp_gain             = [0x%08x]  \n"), .addr=0, .mask=0x000007FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_GAIN_SET_3           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000710, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_phase_gain           = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqdc_rx_1_amp_gain             = [0x%08x]  \n"), .addr=0, .mask=0x000007FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_0_GAIN                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000714, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_0_phase_gain           = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqdc_tx_0_amp_gain             = [0x%08x]  \n"), .addr=0, .mask=0x000007FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_0_DC                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000718, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_0_dcq                  = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqdc_tx_0_dci                  = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_1_COEF_0               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000720, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_2          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_1          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_0          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_1_COEF_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000724, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_5          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_4          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_3          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_1_COEF_2               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000728, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_8          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_7          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_6          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_1_GAIN                 [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000734, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_1_phase_gain           = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqdc_tx_1_amp_gain             = [0x%08x]  \n"), .addr=0, .mask=0x000007FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_1_DC                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000738, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_1_dcq                  = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqdc_tx_1_dci                  = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_4_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000073C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_14         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_13         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_12         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_5_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000740, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_17         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_16         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_15         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_6_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000744, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_20         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_19         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_18         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_4_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000748, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_14         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_13         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_12         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_5_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000074C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_17         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_16         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_15         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_6_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000750, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_20         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_19         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_18         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_4_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000754, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_14         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_13         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_12         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_5_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000758, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_17         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_16         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_15         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_6_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000075C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_20         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_19         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_18         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FTM_TXREQ_MOD_3                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000077C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("ftm_txreq_mod_3                = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_0_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000780, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_2          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_1          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_0          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_1_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000784, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_5          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_4          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_3          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_2_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000788, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_8          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_7          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_6          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_GLITCH_FILTER_0            [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000078C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_glitch_filter_sw_reset     = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("cca_glitch_filter_th_20_s      = [0x%08x]  \n"), .addr=0, .mask=0x0FE00000, .offset=21,                             },{
    CE_DEBUG_STR("cca_glitch_filter_th_20_p      = [0x%08x]  \n"), .addr=0, .mask=0x001FC000, .offset=14,                             },{
    CE_DEBUG_STR("cca_glitch_filter_th_per_20    = [0x%08x]  \n"), .addr=0, .mask=0x00003F80, .offset= 7,                             },{
    CE_DEBUG_STR("cca_glitch_filter_window_size  = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ CCA_GLITCH_FILTER_1            [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000790, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cca_glitch_filter_th_80_s      = [0x%08x]  \n"), .addr=0, .mask=0x00003F80, .offset= 7,                             },{
    CE_DEBUG_STR("cca_glitch_filter_th_40_s      = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_GAIN_SET_1           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000794, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_phase_gain           = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqdc_rx_0_amp_gain             = [0x%08x]  \n"), .addr=0, .mask=0x000007FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_0_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007A0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("qdc_rx_1_fir_coeff_2           = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("qdc_rx_1_fir_coeff_1           = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("qdc_rx_1_fir_coeff_0           = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_1_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007A4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_5          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_4          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_3          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_COEF_2_SET_1         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007A8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_8          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_7          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_1_fir_coeff_6          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_1_GAIN_SET_1           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007B4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_1_phase_gain           = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqdc_rx_1_amp_gain             = [0x%08x]  \n"), .addr=0, .mask=0x000007FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_0_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007C0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_2          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_1          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_0          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_1_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007C4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_5          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_4          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_3          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_2_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007C8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_8          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_7          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_6          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_3_SET_2         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007CC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_11         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_10         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_9          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_GAIN_SET_2           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007D0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_phase_gain           = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqdc_rx_0_amp_gain             = [0x%08x]  \n"), .addr=0, .mask=0x000007FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_GAIN_SET_3           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007DC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_phase_gain           = [0x%08x]  \n"), .addr=0, .mask=0x0FFF0000, .offset=16,                             },{
    CE_DEBUG_STR("iqdc_rx_0_amp_gain             = [0x%08x]  \n"), .addr=0, .mask=0x000007FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_0_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007E0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_2          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_1          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_0          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_1_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007E4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_5          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_4          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_3          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_2_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007E8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_8          = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_7          = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_6          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_0_COEF_3_SET_3         [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007EC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_11         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_10         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_0_fir_coeff_9          = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_11_TX_CONTROL             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007F0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_fir_scale              = [0x%08x]  \n"), .addr=0, .mask=0x0000C000, .offset=14,                             },{
    CE_DEBUG_STR("iqdc_tx_bypass_type            = [0x%08x]  \n"), .addr=0, .mask=0x00000600, .offset= 9,                             },{
    CE_DEBUG_STR("iqdc_tx_bypass_mode            = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_RX_CONTROL                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007F4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_rx_fir_scale              = [0x%08x]  \n"), .addr=0, .mask=0x0000C000, .offset=14,                             },{
    CE_DEBUG_STR("iqdc_rx_length                 = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_rx_bypass_en_source       = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("iqdc_rx_bypass_type            = [0x%08x]  \n"), .addr=0, .mask=0x00000600, .offset= 9,                             },{
    CE_DEBUG_STR("iqdc_rx_bypass_mode            = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_21_TX_CONTROL             [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007F8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_fir_scale              = [0x%08x]  \n"), .addr=0, .mask=0x0000C000, .offset=14,                             },{
    CE_DEBUG_STR("iqdc_tx_location               = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("iqdc_tx_bypass_type            = [0x%08x]  \n"), .addr=0, .mask=0x00000600, .offset= 9,                             },{
    CE_DEBUG_STR("iqdc_tx_bypass_mode            = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("\t\t------ ADC_LB_MUX                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000007FC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lb_i_mode_5                    = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("lb_i_mode_4                    = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("lb_i_mode_3                    = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("lb_i_mode_2                    = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("lb_i_mode_1                    = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("lb_i_mode_0                    = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("lb_cyclic_mode                 = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_PULSE_FIFO               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000800, .mask=0, .offset=0 },{
    CE_DEBUG_STR("radar_pulse_fifo               = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_CTRL_0                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000804, .mask=0, .offset=0 },{
    CE_DEBUG_STR("sec_path_est_ant_mrc_flow      = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("sec_path_est_mrc_flow_en       = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("ant_num_to_proc                = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("mrc_en                         = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("sec_ant_sel                    = [0x%08x]  \n"), .addr=0, .mask=0x000000E0, .offset= 5,                             },{
    CE_DEBUG_STR("main_ant_sel                   = [0x%08x]  \n"), .addr=0, .mask=0x0000001C, .offset= 2,                             },{
    CE_DEBUG_STR("radar_sample_rate              = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_CTRL_1                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000808, .mask=0, .offset=0 },{
    CE_DEBUG_STR("gain_sec_path_est_mrc_en       = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("gain_sec_ant                   = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("gain_main_ant                  = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_CTRL_2                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000080C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("n_cp_2_param                   = [0x%08x]  \n"), .addr=0, .mask=0x0FF00000, .offset=20,                             },{
    CE_DEBUG_STR("n_cp_1_param                   = [0x%08x]  \n"), .addr=0, .mask=0x0003FC00, .offset=10,                             },{
    CE_DEBUG_STR("n_cp_0_param                   = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_CTRL_3                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000810, .mask=0, .offset=0 },{
    CE_DEBUG_STR("two_nplus_1_cp_0_param         = [0x%08x]  \n"), .addr=0, .mask=0x1FF00000, .offset=20,                             },{
    CE_DEBUG_STR("n_cp_4_param                   = [0x%08x]  \n"), .addr=0, .mask=0x0003FC00, .offset=10,                             },{
    CE_DEBUG_STR("n_cp_3_param                   = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_CTRL_4                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000814, .mask=0, .offset=0 },{
    CE_DEBUG_STR("two_nplus_1_cp_3_param         = [0x%08x]  \n"), .addr=0, .mask=0x1FF00000, .offset=20,                             },{
    CE_DEBUG_STR("two_nplus_1_cp_2_param         = [0x%08x]  \n"), .addr=0, .mask=0x0007FC00, .offset=10,                             },{
    CE_DEBUG_STR("two_nplus_1_cp_1_param         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_CTRL_5                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000818, .mask=0, .offset=0 },{
    CE_DEBUG_STR("d_1_cp_1_param                 = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("d_1_cp_0_param                 = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("two_nplus_1_cp_4_param         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_CTRL_6                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000081C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("d_1_cp_4_param                 = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("d_1_cp_3_param                 = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("d_1_cp_2_param                 = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_CTRL_7                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000820, .mask=0, .offset=0 },{
    CE_DEBUG_STR("d_2_cp_2_param                 = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("d_2_cp_1_param                 = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("d_2_cp_0_param                 = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_CTRL_8                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000824, .mask=0, .offset=0 },{
    CE_DEBUG_STR("s_cp_0_param                   = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("d_2_cp_4_param                 = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("d_2_cp_3_param                 = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_CTRL_9                   [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000828, .mask=0, .offset=0 },{
    CE_DEBUG_STR("s_cp_3_param                   = [0x%08x]  \n"), .addr=0, .mask=0x3FF00000, .offset=20,                             },{
    CE_DEBUG_STR("s_cp_2_param                   = [0x%08x]  \n"), .addr=0, .mask=0x000FFC00, .offset=10,                             },{
    CE_DEBUG_STR("s_cp_1_param                   = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_CTRL_10                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000082C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("unwrap_thresh                  = [0x%08x]  \n"), .addr=0, .mask=0x0007FC00, .offset=10,                             },{
    CE_DEBUG_STR("s_cp_4_param                   = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_SW_CTRL                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000830, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_rad_pause                   = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("rx_rad_fifo_wr_stop            = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("sw_ctrl_en                     = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADARSTAT_1                    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000834, .mask=0, .offset=0 },{
    CE_DEBUG_STR("second_pass_est_freq           = [0x%08x]  \n"), .addr=0, .mask=0xFF000000, .offset=24,                             },{
    CE_DEBUG_STR("first_pass_est_freq            = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("second_pass_est_fom            = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("first_pass_est_fom             = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADARSTAT_2                    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000838, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_rad_fifo_wr_ptr             = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADARSTAT_3                    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000084C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("mrc_phase                      = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADARSTAT_4                    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000850, .mask=0, .offset=0 },{
    CE_DEBUG_STR("pulse_fifo_wr_ptr              = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RADAR_IMPLEMENTATION           [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000854, .mask=0, .offset=0 },{
    CE_DEBUG_STR("unwrap_enhancement             = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("latency_corr                   = [0x%08x]  \n"), .addr=0, .mask=0x0000007E, .offset= 1,                             },{
    CE_DEBUG_STR("disable_clkgate                = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_0_COEF_4               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000858, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_14         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_13         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_12         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_0_COEF_5               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000085C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_17         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_16         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_15         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_0_COEF_6               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000860, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_20         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_19         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_0_fir_coeff_18         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_1_COEF_4               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000878, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_14         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_13         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_12         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_1_COEF_5               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000087C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_17         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_16         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_15         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ IQDC_TX_1_COEF_6               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000880, .mask=0, .offset=0 },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_20         = [0x%08x]  \n"), .addr=0, .mask=0xFF800000, .offset=23,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_19         = [0x%08x]  \n"), .addr=0, .mask=0x001FF000, .offset=12,                             },{
    CE_DEBUG_STR("iqdc_tx_1_fir_coeff_18         = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_20_P_STAT_1    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x0000089C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_20_p_stat_1    = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_20_S_STAT_1    [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000008A0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_20_s_stat_1    = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_40_STAT_1      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000008A4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_40_stat_1      = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_80_STAT_1      [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000008A8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_80_stat_1      = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RIU_TFU_SAT_CNT_160_STAT_1     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x000008AC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("riu_tfu_sat_cnt_160_stat_1     = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DPD_CONTROL_0                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000900, .mask=0, .offset=0 },{
    CE_DEBUG_STR("selected_conf_group            = [0x%08x]  \n"), .addr=0, .mask=0x0000000C, .offset= 2,                             },{
    CE_DEBUG_STR("bypass_type                    = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("en                             = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DPD_CONTROL_1                  [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000904, .mask=0, .offset=0 },{
    CE_DEBUG_STR("selected_conf_group            = [0x%08x]  \n"), .addr=0, .mask=0x0000000C, .offset= 2,                             },{
    CE_DEBUG_STR("bypass_type                    = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("en                             = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DPD_GAIN_0                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000920, .mask=0, .offset=0 },{
    CE_DEBUG_STR("out_gain_shift                 = [0x%08x]  \n"), .addr=0, .mask=0x03000000, .offset=24,                             },{
    CE_DEBUG_STR("out_gain_mult                  = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("in_gain_shift                  = [0x%08x]  \n"), .addr=0, .mask=0x00000300, .offset= 8,                             },{
    CE_DEBUG_STR("in_gain_mult                   = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DPD_GAIN_1                     [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000924, .mask=0, .offset=0 },{
    CE_DEBUG_STR("out_gain_shift                 = [0x%08x]  \n"), .addr=0, .mask=0x03000000, .offset=24,                             },{
    CE_DEBUG_STR("out_gain_mult                  = [0x%08x]  \n"), .addr=0, .mask=0x007F0000, .offset=16,                             },{
    CE_DEBUG_STR("in_gain_shift                  = [0x%08x]  \n"), .addr=0, .mask=0x00000300, .offset= 8,                             },{
    CE_DEBUG_STR("in_gain_mult                   = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DPD_CHAIN_SIZE_0               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000940, .mask=0, .offset=0 },{
    CE_DEBUG_STR("g_chain_major_node_conf_group_ = [0x%08x]  \n"), .addr=0, .mask=0xF0000000, .offset=28,                             },{
    CE_DEBUG_STR("g_chain_major_node_conf_group_ = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("g_chain_major_node_conf_group_ = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("g_chain_major_node_conf_group_ = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("g_chain_exit_node_conf_group_3 = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("g_chain_exit_node_conf_group_2 = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("g_chain_exit_node_conf_group_1 = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("g_chain_exit_node_conf_group_0 = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DPD_CHAIN_SIZE_1               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000944, .mask=0, .offset=0 },{
    CE_DEBUG_STR("g_chain_major_node_conf_group_ = [0x%08x]  \n"), .addr=0, .mask=0xF0000000, .offset=28,                             },{
    CE_DEBUG_STR("g_chain_major_node_conf_group_ = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("g_chain_major_node_conf_group_ = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("g_chain_major_node_conf_group_ = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("g_chain_exit_node_conf_group_3 = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("g_chain_exit_node_conf_group_2 = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("g_chain_exit_node_conf_group_1 = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("g_chain_exit_node_conf_group_0 = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DPD_GBLOCK_ADDR                [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000960, .mask=0, .offset=0 },{
    CE_DEBUG_STR("antenna_index                  = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("g_index                        = [0x%08x]  \n"), .addr=0, .mask=0x00001E00, .offset= 9,                             },{
    CE_DEBUG_STR("conf_group_index               = [0x%08x]  \n"), .addr=0, .mask=0x00000180, .offset= 7,                             },{
    CE_DEBUG_STR("gmem_index                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DPD_GBLOCK_WDATA               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000964, .mask=0, .offset=0 },{
    CE_DEBUG_STR("wdata                          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DPD_GBLOCK_RDATA               [0x%08x]\n" ) , .addr=REG_RIU_BASE_ADDR + 0x00000968, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rdata                          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    .str=NULL }
};//RIU 
