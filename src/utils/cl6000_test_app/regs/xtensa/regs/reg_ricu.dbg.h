X_REMOTE_ROM static const struct rom_table_direct_mem rom_ricu[] = {{
    CE_DEBUG_STR("\t\t------ VERSION                        [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000000, .mask=0, .offset=0 },{
    CE_DEBUG_STR("version                        = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ STATIC_CONF_0                  [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000004, .mask=0, .offset=0 },{
    CE_DEBUG_STR("arb_oneshot_bypass             = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("btc_sel                        = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("clk_save_mode                  = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("rf_rst_n_default               = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("rf_rst_n_req                   = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("force_rssi_on                  = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("rssi_m                         = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("rssi_n                         = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("cdb_mode_maj                   = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ DYN_CONF                       [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000008, .mask=0, .offset=0 },{
    CE_DEBUG_STR("frc_event_req                  = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_0                      [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000010, .mask=0, .offset=0 },{
    CE_DEBUG_STR("pbias_ctrl_en_lc               = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("pbias_ctrl_en                  = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("lrd_en_lc                      = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("lrd_en                         = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("lock_en_lc                     = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("lock_en                        = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("en_gpadc_clk                   = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("en_gpadc                       = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("feed_en_lc                     = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("feed_en                        = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("en_cs                          = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("en_cml_gen                     = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("en_afe_ldo                     = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("en_adc_clk                     = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("afc_enb_lc                     = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("afc_enb                        = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("cp_mode_lc                     = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("bypass_lc                      = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("bypass                         = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("afcinit_sel_lc                 = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("afcinit_sel                    = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("en_clk_mon                     = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("en_dac_clk                     = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("en_cdb_dac_clk                 = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("en_cdb_adc_clk                 = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("en_cdb_gen                     = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("dacclk_phasesel                = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("adcclk_phasesel                = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("cdb_clk_resetb                 = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_1                      [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000014, .mask=0, .offset=0 },{
    CE_DEBUG_STR("vco_boost                      = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("sys_adcclk_sel                 = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("soc_phase_sel                  = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("soc_clk_sel                    = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("resetb_lc                      = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("resetb                         = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("pbias_ctrl_lc                  = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("pbias_ctrl                     = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("gp_clk_phasesel                = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("fsel_lc                        = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("fsel                           = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("fout_mask_lc                   = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("fout_mask                      = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("extclk_sel                     = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("en_pll_ldo                     = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_2                      [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000018, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lock_con_rev_lc                = [0x%08x]  \n"), .addr=0, .mask=0x00C00000, .offset=22,                             },{
    CE_DEBUG_STR("lock_con_rev                   = [0x%08x]  \n"), .addr=0, .mask=0x00300000, .offset=20,                             },{
    CE_DEBUG_STR("lock_con_out_lc                = [0x%08x]  \n"), .addr=0, .mask=0x000C0000, .offset=18,                             },{
    CE_DEBUG_STR("lock_con_out                   = [0x%08x]  \n"), .addr=0, .mask=0x00030000, .offset=16,                             },{
    CE_DEBUG_STR("lock_con_in_lc                 = [0x%08x]  \n"), .addr=0, .mask=0x0000C000, .offset=14,                             },{
    CE_DEBUG_STR("lock_con_in                    = [0x%08x]  \n"), .addr=0, .mask=0x00003000, .offset=12,                             },{
    CE_DEBUG_STR("lock_con_dly_lc                = [0x%08x]  \n"), .addr=0, .mask=0x00000C00, .offset=10,                             },{
    CE_DEBUG_STR("lock_con_dly                   = [0x%08x]  \n"), .addr=0, .mask=0x00000300, .offset= 8,                             },{
    CE_DEBUG_STR("icp                            = [0x%08x]  \n"), .addr=0, .mask=0x000000C0, .offset= 6,                             },{
    CE_DEBUG_STR("ctrl_ib                        = [0x%08x]  \n"), .addr=0, .mask=0x0000000C, .offset= 2,                             },{
    CE_DEBUG_STR("clk_mon_sel                    = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_3                      [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000001C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rsel                           = [0x%08x]  \n"), .addr=0, .mask=0xF0000000, .offset=28,                             },{
    CE_DEBUG_STR("i_csel_lc                      = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("gm_lc                          = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("csel_lc                        = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("cml_sel                        = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("s_lc                           = [0x%08x]  \n"), .addr=0, .mask=0x00000E00, .offset= 9,                             },{
    CE_DEBUG_STR("s                              = [0x%08x]  \n"), .addr=0, .mask=0x000001C0, .offset= 6,                             },{
    CE_DEBUG_STR("lbw_lc                         = [0x%08x]  \n"), .addr=0, .mask=0x00000038, .offset= 3,                             },{
    CE_DEBUG_STR("icp_lc                         = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_4                      [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000020, .mask=0, .offset=0 },{
    CE_DEBUG_STR("extafc_lc                      = [0x%08x]  \n"), .addr=0, .mask=0x3E000000, .offset=25,                             },{
    CE_DEBUG_STR("extafc                         = [0x%08x]  \n"), .addr=0, .mask=0x01F00000, .offset=20,                             },{
    CE_DEBUG_STR("vtrim_pll                      = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("vtrim_afe                      = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("vctrl_pll                      = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("vctrl_afe                      = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("rsel_lc                        = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_5                      [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000024, .mask=0, .offset=0 },{
    CE_DEBUG_STR("main_sel_7_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00FC0000, .offset=18,                             },{
    CE_DEBUG_STR("p_lc                           = [0x%08x]  \n"), .addr=0, .mask=0x0003F000, .offset=12,                             },{
    CE_DEBUG_STR("p                              = [0x%08x]  \n"), .addr=0, .mask=0x00000FC0, .offset= 6,                             },{
    CE_DEBUG_STR("cap_bias_code_lc               = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_6                      [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000028, .mask=0, .offset=0 },{
    CE_DEBUG_STR("m_lc                           = [0x%08x]  \n"), .addr=0, .mask=0x03FF0000, .offset=16,                             },{
    CE_DEBUG_STR("m                              = [0x%08x]  \n"), .addr=0, .mask=0x000003FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_7                      [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000002C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("comp_sel_7                     = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("comp_sel_6                     = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("comp_sel_5                     = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("comp_sel_4                     = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("comp_sel_3                     = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("comp_sel_2                     = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("comp_sel_1                     = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("comp_sel_0                     = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("clk_phase_sel_7                = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("clk_phase_sel_6                = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("clk_phase_sel_5                = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("clk_phase_sel_4                = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("clk_phase_sel_3                = [0x%08x]  \n"), .addr=0, .mask=0x00080000, .offset=19,                             },{
    CE_DEBUG_STR("clk_phase_sel_2                = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("clk_phase_sel_1                = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("clk_phase_sel_0                = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("ckc_sel_7                      = [0x%08x]  \n"), .addr=0, .mask=0x0000C000, .offset=14,                             },{
    CE_DEBUG_STR("ckc_sel_6                      = [0x%08x]  \n"), .addr=0, .mask=0x00003000, .offset=12,                             },{
    CE_DEBUG_STR("ckc_sel_5                      = [0x%08x]  \n"), .addr=0, .mask=0x00000C00, .offset=10,                             },{
    CE_DEBUG_STR("ckc_sel_4                      = [0x%08x]  \n"), .addr=0, .mask=0x00000300, .offset= 8,                             },{
    CE_DEBUG_STR("ckc_sel_3                      = [0x%08x]  \n"), .addr=0, .mask=0x000000C0, .offset= 6,                             },{
    CE_DEBUG_STR("ckc_sel_2                      = [0x%08x]  \n"), .addr=0, .mask=0x00000030, .offset= 4,                             },{
    CE_DEBUG_STR("ckc_sel_1                      = [0x%08x]  \n"), .addr=0, .mask=0x0000000C, .offset= 2,                             },{
    CE_DEBUG_STR("ckc_sel_0                      = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_8                      [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000030, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_ref_7                       = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("en_ref_6                       = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("en_ref_5                       = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("en_ref_4                       = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("en_ref_3                       = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("en_ref_2                       = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("en_ref_1                       = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("en_ref_0                       = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("en_ext_load_7                  = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("en_ext_load_6                  = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("en_ext_load_5                  = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("en_ext_load_4                  = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("en_ext_load_3                  = [0x%08x]  \n"), .addr=0, .mask=0x00080000, .offset=19,                             },{
    CE_DEBUG_STR("en_ext_load_2                  = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("en_ext_load_1                  = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("en_ext_load_0                  = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("ch_cml_sel_7                   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("ch_cml_sel_6                   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("ch_cml_sel_5                   = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("ch_cml_sel_4                   = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("ch_cml_sel_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("ch_cml_sel_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("ch_cml_sel_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("ch_cml_sel_0                   = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("en_bgr_7                       = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("en_bgr_6                       = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("en_bgr_5                       = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("en_bgr_4                       = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("en_bgr_3                       = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("en_bgr_2                       = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("en_bgr_1                       = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("en_bgr_0                       = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_9                      [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000034, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_sin_2_bias_7                = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("en_sin_2_bias_6                = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("en_sin_2_bias_5                = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("en_sin_2_bias_4                = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("en_sin_2_bias_3                = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("en_sin_2_bias_2                = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("en_sin_2_bias_1                = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("en_sin_2_bias_0                = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("en_dac_ref_7                   = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("en_dac_ref_6                   = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("en_dac_ref_5                   = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("en_dac_ref_4                   = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("en_dac_ref_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00080000, .offset=19,                             },{
    CE_DEBUG_STR("en_dac_ref_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("en_dac_ref_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("en_dac_ref_0                   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_10                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000038, .mask=0, .offset=0 },{
    CE_DEBUG_STR("vc_ld_7                        = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("vc_ld_6                        = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("vc_ld_5                        = [0x%08x]  \n"), .addr=0, .mask=0x20000000, .offset=29,                             },{
    CE_DEBUG_STR("vc_ld_4                        = [0x%08x]  \n"), .addr=0, .mask=0x10000000, .offset=28,                             },{
    CE_DEBUG_STR("vc_ld_3                        = [0x%08x]  \n"), .addr=0, .mask=0x08000000, .offset=27,                             },{
    CE_DEBUG_STR("vc_ld_2                        = [0x%08x]  \n"), .addr=0, .mask=0x04000000, .offset=26,                             },{
    CE_DEBUG_STR("vc_ld_1                        = [0x%08x]  \n"), .addr=0, .mask=0x02000000, .offset=25,                             },{
    CE_DEBUG_STR("vc_ld_0                        = [0x%08x]  \n"), .addr=0, .mask=0x01000000, .offset=24,                             },{
    CE_DEBUG_STR("twos_7                         = [0x%08x]  \n"), .addr=0, .mask=0x00800000, .offset=23,                             },{
    CE_DEBUG_STR("twos_6                         = [0x%08x]  \n"), .addr=0, .mask=0x00400000, .offset=22,                             },{
    CE_DEBUG_STR("twos_5                         = [0x%08x]  \n"), .addr=0, .mask=0x00200000, .offset=21,                             },{
    CE_DEBUG_STR("twos_4                         = [0x%08x]  \n"), .addr=0, .mask=0x00100000, .offset=20,                             },{
    CE_DEBUG_STR("twos_3                         = [0x%08x]  \n"), .addr=0, .mask=0x00080000, .offset=19,                             },{
    CE_DEBUG_STR("twos_2                         = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("twos_1                         = [0x%08x]  \n"), .addr=0, .mask=0x00020000, .offset=17,                             },{
    CE_DEBUG_STR("twos_0                         = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("minv_7                         = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("minv_6                         = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("minv_5                         = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("minv_4                         = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("minv_3                         = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("minv_2                         = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("minv_1                         = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("minv_0                         = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_11                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000003C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("ic_refamp_7                    = [0x%08x]  \n"), .addr=0, .mask=0xC0000000, .offset=30,                             },{
    CE_DEBUG_STR("ic_refamp_6                    = [0x%08x]  \n"), .addr=0, .mask=0x30000000, .offset=28,                             },{
    CE_DEBUG_STR("ic_refamp_5                    = [0x%08x]  \n"), .addr=0, .mask=0x0C000000, .offset=26,                             },{
    CE_DEBUG_STR("ic_refamp_4                    = [0x%08x]  \n"), .addr=0, .mask=0x03000000, .offset=24,                             },{
    CE_DEBUG_STR("ic_refamp_3                    = [0x%08x]  \n"), .addr=0, .mask=0x00C00000, .offset=22,                             },{
    CE_DEBUG_STR("ic_refamp_2                    = [0x%08x]  \n"), .addr=0, .mask=0x00300000, .offset=20,                             },{
    CE_DEBUG_STR("ic_refamp_1                    = [0x%08x]  \n"), .addr=0, .mask=0x000C0000, .offset=18,                             },{
    CE_DEBUG_STR("ic_refamp_0                    = [0x%08x]  \n"), .addr=0, .mask=0x00030000, .offset=16,                             },{
    CE_DEBUG_STR("ic_ld_7                        = [0x%08x]  \n"), .addr=0, .mask=0x0000C000, .offset=14,                             },{
    CE_DEBUG_STR("ic_ld_6                        = [0x%08x]  \n"), .addr=0, .mask=0x00003000, .offset=12,                             },{
    CE_DEBUG_STR("ic_ld_5                        = [0x%08x]  \n"), .addr=0, .mask=0x00000C00, .offset=10,                             },{
    CE_DEBUG_STR("ic_ld_4                        = [0x%08x]  \n"), .addr=0, .mask=0x00000300, .offset= 8,                             },{
    CE_DEBUG_STR("ic_ld_3                        = [0x%08x]  \n"), .addr=0, .mask=0x000000C0, .offset= 6,                             },{
    CE_DEBUG_STR("ic_ld_2                        = [0x%08x]  \n"), .addr=0, .mask=0x00000030, .offset= 4,                             },{
    CE_DEBUG_STR("ic_ld_1                        = [0x%08x]  \n"), .addr=0, .mask=0x0000000C, .offset= 2,                             },{
    CE_DEBUG_STR("ic_ld_0                        = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_12                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000040, .mask=0, .offset=0 },{
    CE_DEBUG_STR("eoc_ctrl_7                     = [0x%08x]  \n"), .addr=0, .mask=0xC0000000, .offset=30,                             },{
    CE_DEBUG_STR("eoc_ctrl_6                     = [0x%08x]  \n"), .addr=0, .mask=0x30000000, .offset=28,                             },{
    CE_DEBUG_STR("eoc_ctrl_5                     = [0x%08x]  \n"), .addr=0, .mask=0x0C000000, .offset=26,                             },{
    CE_DEBUG_STR("eoc_ctrl_4                     = [0x%08x]  \n"), .addr=0, .mask=0x03000000, .offset=24,                             },{
    CE_DEBUG_STR("eoc_ctrl_3                     = [0x%08x]  \n"), .addr=0, .mask=0x00C00000, .offset=22,                             },{
    CE_DEBUG_STR("eoc_ctrl_2                     = [0x%08x]  \n"), .addr=0, .mask=0x00300000, .offset=20,                             },{
    CE_DEBUG_STR("eoc_ctrl_1                     = [0x%08x]  \n"), .addr=0, .mask=0x000C0000, .offset=18,                             },{
    CE_DEBUG_STR("eoc_ctrl_0                     = [0x%08x]  \n"), .addr=0, .mask=0x00030000, .offset=16,                             },{
    CE_DEBUG_STR("ic_refssf_7                    = [0x%08x]  \n"), .addr=0, .mask=0x0000C000, .offset=14,                             },{
    CE_DEBUG_STR("ic_refssf_6                    = [0x%08x]  \n"), .addr=0, .mask=0x00003000, .offset=12,                             },{
    CE_DEBUG_STR("ic_refssf_5                    = [0x%08x]  \n"), .addr=0, .mask=0x00000C00, .offset=10,                             },{
    CE_DEBUG_STR("ic_refssf_4                    = [0x%08x]  \n"), .addr=0, .mask=0x00000300, .offset= 8,                             },{
    CE_DEBUG_STR("ic_refssf_3                    = [0x%08x]  \n"), .addr=0, .mask=0x000000C0, .offset= 6,                             },{
    CE_DEBUG_STR("ic_refssf_2                    = [0x%08x]  \n"), .addr=0, .mask=0x00000030, .offset= 4,                             },{
    CE_DEBUG_STR("ic_refssf_1                    = [0x%08x]  \n"), .addr=0, .mask=0x0000000C, .offset= 2,                             },{
    CE_DEBUG_STR("ic_refssf_0                    = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_13                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000044, .mask=0, .offset=0 },{
    CE_DEBUG_STR("force_adc_on_phy_1             = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("force_adc_on_phy_0             = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("en_lb_8_aux                    = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_lb_7                        = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_lb_6                        = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("en_lb_5                        = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("en_lb_4                        = [0x%08x]  \n"), .addr=0, .mask=0x00001000, .offset=12,                             },{
    CE_DEBUG_STR("en_lb_3                        = [0x%08x]  \n"), .addr=0, .mask=0x00000800, .offset=11,                             },{
    CE_DEBUG_STR("en_lb_2                        = [0x%08x]  \n"), .addr=0, .mask=0x00000400, .offset=10,                             },{
    CE_DEBUG_STR("en_lb_1                        = [0x%08x]  \n"), .addr=0, .mask=0x00000200, .offset= 9,                             },{
    CE_DEBUG_STR("en_lb_0                        = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_14                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000048, .mask=0, .offset=0 },{
    CE_DEBUG_STR("dec_7                          = [0x%08x]  \n"), .addr=0, .mask=0x70000000, .offset=28,                             },{
    CE_DEBUG_STR("dec_6                          = [0x%08x]  \n"), .addr=0, .mask=0x07000000, .offset=24,                             },{
    CE_DEBUG_STR("dec_5                          = [0x%08x]  \n"), .addr=0, .mask=0x00700000, .offset=20,                             },{
    CE_DEBUG_STR("dec_4                          = [0x%08x]  \n"), .addr=0, .mask=0x00070000, .offset=16,                             },{
    CE_DEBUG_STR("dec_3                          = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("dec_2                          = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("dec_1                          = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("dec_0                          = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_15                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000004C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_out_cm_7                    = [0x%08x]  \n"), .addr=0, .mask=0x70000000, .offset=28,                             },{
    CE_DEBUG_STR("en_out_cm_6                    = [0x%08x]  \n"), .addr=0, .mask=0x07000000, .offset=24,                             },{
    CE_DEBUG_STR("en_out_cm_5                    = [0x%08x]  \n"), .addr=0, .mask=0x00700000, .offset=20,                             },{
    CE_DEBUG_STR("en_out_cm_4                    = [0x%08x]  \n"), .addr=0, .mask=0x00070000, .offset=16,                             },{
    CE_DEBUG_STR("en_out_cm_3                    = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("en_out_cm_2                    = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("en_out_cm_1                    = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("en_out_cm_0                    = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_16                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000050, .mask=0, .offset=0 },{
    CE_DEBUG_STR("fs_ibuf_7                      = [0x%08x]  \n"), .addr=0, .mask=0x70000000, .offset=28,                             },{
    CE_DEBUG_STR("fs_ibuf_6                      = [0x%08x]  \n"), .addr=0, .mask=0x07000000, .offset=24,                             },{
    CE_DEBUG_STR("fs_ibuf_5                      = [0x%08x]  \n"), .addr=0, .mask=0x00700000, .offset=20,                             },{
    CE_DEBUG_STR("fs_ibuf_4                      = [0x%08x]  \n"), .addr=0, .mask=0x00070000, .offset=16,                             },{
    CE_DEBUG_STR("fs_ibuf_3                      = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("fs_ibuf_2                      = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("fs_ibuf_1                      = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("fs_ibuf_0                      = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_17                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000054, .mask=0, .offset=0 },{
    CE_DEBUG_STR("vc_ref_7                       = [0x%08x]  \n"), .addr=0, .mask=0x70000000, .offset=28,                             },{
    CE_DEBUG_STR("vc_ref_6                       = [0x%08x]  \n"), .addr=0, .mask=0x07000000, .offset=24,                             },{
    CE_DEBUG_STR("vc_ref_5                       = [0x%08x]  \n"), .addr=0, .mask=0x00700000, .offset=20,                             },{
    CE_DEBUG_STR("vc_ref_4                       = [0x%08x]  \n"), .addr=0, .mask=0x00070000, .offset=16,                             },{
    CE_DEBUG_STR("vc_ref_3                       = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("vc_ref_2                       = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("vc_ref_1                       = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("vc_ref_0                       = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_18                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000058, .mask=0, .offset=0 },{
    CE_DEBUG_STR("comp_ctrl_ext_7                = [0x%08x]  \n"), .addr=0, .mask=0xF0000000, .offset=28,                             },{
    CE_DEBUG_STR("comp_ctrl_ext_6                = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("comp_ctrl_ext_5                = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("comp_ctrl_ext_4                = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("comp_ctrl_ext_3                = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("comp_ctrl_ext_2                = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("comp_ctrl_ext_1                = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("comp_ctrl_ext_0                = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_19                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000005C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("comp_ctrl_7                    = [0x%08x]  \n"), .addr=0, .mask=0xF0000000, .offset=28,                             },{
    CE_DEBUG_STR("comp_ctrl_6                    = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("comp_ctrl_5                    = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("comp_ctrl_4                    = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("comp_ctrl_3                    = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("comp_ctrl_2                    = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("comp_ctrl_1                    = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("comp_ctrl_0                    = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_20                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000060, .mask=0, .offset=0 },{
    CE_DEBUG_STR("sin_2_ibias_ctrl_3             = [0x%08x]  \n"), .addr=0, .mask=0x1F000000, .offset=24,                             },{
    CE_DEBUG_STR("sin_2_ibias_ctrl_2             = [0x%08x]  \n"), .addr=0, .mask=0x001F0000, .offset=16,                             },{
    CE_DEBUG_STR("sin_2_ibias_ctrl_1             = [0x%08x]  \n"), .addr=0, .mask=0x00001F00, .offset= 8,                             },{
    CE_DEBUG_STR("sin_2_ibias_ctrl_0             = [0x%08x]  \n"), .addr=0, .mask=0x0000001F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_21                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000064, .mask=0, .offset=0 },{
    CE_DEBUG_STR("vswbs_ctrl_7                   = [0x%08x]  \n"), .addr=0, .mask=0xF0000000, .offset=28,                             },{
    CE_DEBUG_STR("vswbs_ctrl_6                   = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("vswbs_ctrl_5                   = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("vswbs_ctrl_4                   = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("vswbs_ctrl_3                   = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("vswbs_ctrl_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("vswbs_ctrl_1                   = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("vswbs_ctrl_0                   = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_22_PHY_0               [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000068, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_0_en_adc_5                 = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("phy_0_en_adc_4                 = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("phy_0_en_adc_3                 = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("phy_0_en_adc_2                 = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("phy_0_en_adc_1                 = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("phy_0_en_adc_0                 = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_23                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000006C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("vc_ld_avdi_7                   = [0x%08x]  \n"), .addr=0, .mask=0x70000000, .offset=28,                             },{
    CE_DEBUG_STR("vc_ld_avdi_6                   = [0x%08x]  \n"), .addr=0, .mask=0x07000000, .offset=24,                             },{
    CE_DEBUG_STR("vc_ld_avdi_5                   = [0x%08x]  \n"), .addr=0, .mask=0x00700000, .offset=20,                             },{
    CE_DEBUG_STR("vc_ld_avdi_4                   = [0x%08x]  \n"), .addr=0, .mask=0x00070000, .offset=16,                             },{
    CE_DEBUG_STR("vc_ld_avdi_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("vc_ld_avdi_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("vc_ld_avdi_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("vc_ld_avdi_0                   = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_24                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000070, .mask=0, .offset=0 },{
    CE_DEBUG_STR("vc_ld_avdq_7                   = [0x%08x]  \n"), .addr=0, .mask=0x70000000, .offset=28,                             },{
    CE_DEBUG_STR("vc_ld_avdq_6                   = [0x%08x]  \n"), .addr=0, .mask=0x07000000, .offset=24,                             },{
    CE_DEBUG_STR("vc_ld_avdq_5                   = [0x%08x]  \n"), .addr=0, .mask=0x00700000, .offset=20,                             },{
    CE_DEBUG_STR("vc_ld_avdq_4                   = [0x%08x]  \n"), .addr=0, .mask=0x00070000, .offset=16,                             },{
    CE_DEBUG_STR("vc_ld_avdq_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("vc_ld_avdq_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("vc_ld_avdq_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("vc_ld_avdq_0                   = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_25                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000074, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rosel_0                        = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("ro_ctrlq_0                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("ro_ctrli_0                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_26                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000078, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rosel_1                        = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("ro_ctrlq_1                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("ro_ctrli_1                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_27                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000007C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rosel_2                        = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("ro_ctrlq_2                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("ro_ctrli_2                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_28                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000080, .mask=0, .offset=0 },{
    CE_DEBUG_STR("sin_1_ctrl_7                   = [0x%08x]  \n"), .addr=0, .mask=0xF0000000, .offset=28,                             },{
    CE_DEBUG_STR("sin_1_ctrl_6                   = [0x%08x]  \n"), .addr=0, .mask=0x0F000000, .offset=24,                             },{
    CE_DEBUG_STR("sin_1_ctrl_5                   = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("sin_1_ctrl_4                   = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("sin_1_ctrl_3                   = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("sin_1_ctrl_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("sin_1_ctrl_1                   = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("sin_1_ctrl_0                   = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_29                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000084, .mask=0, .offset=0 },{
    CE_DEBUG_STR("vc_cml_7_i                     = [0x%08x]  \n"), .addr=0, .mask=0x70000000, .offset=28,                             },{
    CE_DEBUG_STR("vc_cml_6_i                     = [0x%08x]  \n"), .addr=0, .mask=0x07000000, .offset=24,                             },{
    CE_DEBUG_STR("vc_cml_5_i                     = [0x%08x]  \n"), .addr=0, .mask=0x00700000, .offset=20,                             },{
    CE_DEBUG_STR("vc_cml_4_i                     = [0x%08x]  \n"), .addr=0, .mask=0x00070000, .offset=16,                             },{
    CE_DEBUG_STR("vc_cml_3_i                     = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("vc_cml_2_i                     = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("vc_cml_1_i                     = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("vc_cml_0_i                     = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_30                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000088, .mask=0, .offset=0 },{
    CE_DEBUG_STR("vc_cml_7_q                     = [0x%08x]  \n"), .addr=0, .mask=0x70000000, .offset=28,                             },{
    CE_DEBUG_STR("vc_cml_6_q                     = [0x%08x]  \n"), .addr=0, .mask=0x07000000, .offset=24,                             },{
    CE_DEBUG_STR("vc_cml_5_q                     = [0x%08x]  \n"), .addr=0, .mask=0x00700000, .offset=20,                             },{
    CE_DEBUG_STR("vc_cml_4_q                     = [0x%08x]  \n"), .addr=0, .mask=0x00070000, .offset=16,                             },{
    CE_DEBUG_STR("vc_cml_3_q                     = [0x%08x]  \n"), .addr=0, .mask=0x00007000, .offset=12,                             },{
    CE_DEBUG_STR("vc_cml_2_q                     = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("vc_cml_1_q                     = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("vc_cml_0_q                     = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_31                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000008C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("afe_reserved                   = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_32                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000090, .mask=0, .offset=0 },{
    CE_DEBUG_STR("sin_2_ibias_ctrl_7             = [0x%08x]  \n"), .addr=0, .mask=0x1F000000, .offset=24,                             },{
    CE_DEBUG_STR("sin_2_ibias_ctrl_6             = [0x%08x]  \n"), .addr=0, .mask=0x001F0000, .offset=16,                             },{
    CE_DEBUG_STR("sin_2_ibias_ctrl_5             = [0x%08x]  \n"), .addr=0, .mask=0x00001F00, .offset= 8,                             },{
    CE_DEBUG_STR("sin_2_ibias_ctrl_4             = [0x%08x]  \n"), .addr=0, .mask=0x0000001F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_33                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000094, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rosel_3                        = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("ro_ctrl_3_q                    = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("ro_ctrl_3_i                    = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTL_22_PHY_1               [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000098, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_1_en_adc_5                 = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("phy_1_en_adc_4                 = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("phy_1_en_adc_3                 = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("phy_1_en_adc_2                 = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("phy_1_en_adc_1                 = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("phy_1_en_adc_0                 = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_34_PHY_0              [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000009C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_0_adc_sb_ignore_fifo_indic = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("phy_0_adc_sb_rd_delay          = [0x%08x]  \n"), .addr=0, .mask=0x0000003C, .offset= 2,                             },{
    CE_DEBUG_STR("phy_0_adc_sb_mode              = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_36_PHY_0              [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000A0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_0_adc_always_en_ld_ir      = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("phy_0_adc_always_en_ld_avdq    = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("phy_0_adc_always_en_ld_avdi    = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("phy_0_adc_always_en_adcq       = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("phy_0_adc_always_en_adci       = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("phy_0_hw_mode_dac              = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("phy_0_hw_mode_adc              = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_34_PHY_1              [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000A4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_1_adc_sb_ignore_fifo_indic = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("phy_1_adc_sb_rd_delay          = [0x%08x]  \n"), .addr=0, .mask=0x0000003C, .offset= 2,                             },{
    CE_DEBUG_STR("phy_1_adc_sb_mode              = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_35_PHY_0              [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000A8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_0_dac_sb_ignore_fifo_indic = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("phy_0_dac_sb_rd_delay          = [0x%08x]  \n"), .addr=0, .mask=0x0000003C, .offset= 2,                             },{
    CE_DEBUG_STR("phy_0_dac_sb_mode              = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_35_PHY_1              [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000AC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_1_dac_sb_ignore_fifo_indic = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("phy_1_dac_sb_rd_delay          = [0x%08x]  \n"), .addr=0, .mask=0x0000003C, .offset= 2,                             },{
    CE_DEBUG_STR("phy_1_dac_sb_mode              = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ BTC_CONF_0                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000B0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lut_btc_tms_dout               = [0x%08x]  \n"), .addr=0, .mask=0xFFFF0000, .offset=16,                             },{
    CE_DEBUG_STR("lut_btc_trst_n_dout            = [0x%08x]  \n"), .addr=0, .mask=0x0000FFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ BTC_CONF_1                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000B4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lut_btc_tdo_dout               = [0x%08x]  \n"), .addr=0, .mask=0xFFFF0000, .offset=16,                             },{
    CE_DEBUG_STR("lut_btc_tdi_dout               = [0x%08x]  \n"), .addr=0, .mask=0x0000FFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ BTC_CONF_2                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000B8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("lut_btc_tdo_oe                 = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("lut_btc_tdi_oe                 = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("lut_btc_tms_oe                 = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("lut_btc_trst_n_oe              = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_37_PHY_0              [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000BC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_0_en_dac_5                 = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("phy_0_en_dac_4                 = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("phy_0_en_dac_3                 = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("phy_0_en_dac_2                 = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("phy_0_en_dac_1                 = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("phy_0_en_dac_0                 = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_37_PHY_1              [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000C0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_1_en_dac_5                 = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("phy_1_en_dac_4                 = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("phy_1_en_dac_3                 = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("phy_1_en_dac_2                 = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("phy_1_en_dac_1                 = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("phy_1_en_dac_0                 = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_38_PHY_0              [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000C4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_0_dac_sb_clear_sticky      = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("phy_0_adc_sb_clear_sticky      = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("phy_0_dac_sb_underflow         = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("phy_0_dac_sb_overflow          = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("phy_0_adc_sb_underflow         = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("phy_0_adc_sb_overflow          = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_38_PHY_1              [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000C8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_1_dac_sb_clear_sticky      = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("phy_1_adc_sb_clear_sticky      = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("phy_1_dac_sb_underflow         = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("phy_1_dac_sb_overflow          = [0x%08x]  \n"), .addr=0, .mask=0x00000004, .offset= 2,                             },{
    CE_DEBUG_STR("phy_1_adc_sb_underflow         = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("phy_1_adc_sb_overflow          = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_39                    [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000CC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rosel_4                        = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("ro_ctrlq_4                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("ro_ctrli_4                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_40                    [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000D0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rosel_5                        = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("ro_ctrlq_5                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("ro_ctrli_5                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_41                    [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000D4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rosel_6                        = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("ro_ctrlq_6                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("ro_ctrli_6                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_42                    [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000D8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rosel_7                        = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("ro_ctrlq_7                     = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("ro_ctrli_7                     = [0x%08x]  \n"), .addr=0, .mask=0x0000007F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_43                    [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000DC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("freq_sel                       = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_44                    [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000E0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("cdb_freq_sel                   = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ SPI_CLK_CTRL                   [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000E4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("spi_clk_bitmap                 = [0x%08x]  \n"), .addr=0, .mask=0x0000003F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FEM_CONF_0                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000F0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("fem_5_ctl_sel                  = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("fem_4_ctl_sel                  = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("fem_3_ctl_sel                  = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("fem_2_ctl_sel                  = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("fem_1_ctl_sel                  = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("fem_0_ctl_sel                  = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FEM_CONF_1                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000F4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("fem_11_ctl_sel                 = [0x%08x]  \n"), .addr=0, .mask=0x00F00000, .offset=20,                             },{
    CE_DEBUG_STR("fem_10_ctl_sel                 = [0x%08x]  \n"), .addr=0, .mask=0x000F0000, .offset=16,                             },{
    CE_DEBUG_STR("fem_9_ctl_sel                  = [0x%08x]  \n"), .addr=0, .mask=0x0000F000, .offset=12,                             },{
    CE_DEBUG_STR("fem_8_ctl_sel                  = [0x%08x]  \n"), .addr=0, .mask=0x00000F00, .offset= 8,                             },{
    CE_DEBUG_STR("fem_7_ctl_sel                  = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("fem_6_ctl_sel                  = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_CTRL_36_PHY_1              [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000F8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_1_adc_always_en_ld_ir      = [0x%08x]  \n"), .addr=0, .mask=0x00000080, .offset= 7,                             },{
    CE_DEBUG_STR("phy_1_adc_always_en_ld_avdq    = [0x%08x]  \n"), .addr=0, .mask=0x00000040, .offset= 6,                             },{
    CE_DEBUG_STR("phy_1_adc_always_en_ld_avdi    = [0x%08x]  \n"), .addr=0, .mask=0x00000020, .offset= 5,                             },{
    CE_DEBUG_STR("phy_1_adc_always_en_adcq       = [0x%08x]  \n"), .addr=0, .mask=0x00000010, .offset= 4,                             },{
    CE_DEBUG_STR("phy_1_adc_always_en_adci       = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("phy_1_hw_mode_dac              = [0x%08x]  \n"), .addr=0, .mask=0x00000002, .offset= 1,                             },{
    CE_DEBUG_STR("phy_1_hw_mode_adc              = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AFE_ADC_CH_ALLOC               [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x000000FC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("afe_adc_ch_alloc               = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ PHY_0_RSSI_STATUS              [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000100, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rc_0_rssi_0                    = [0x%08x]  \n"), .addr=0, .mask=0xC0000000, .offset=30,                             },{
    CE_DEBUG_STR("rc_0_rssi_1                    = [0x%08x]  \n"), .addr=0, .mask=0x30000000, .offset=28,                             },{
    CE_DEBUG_STR("rc_0_rssi_2                    = [0x%08x]  \n"), .addr=0, .mask=0x0C000000, .offset=26,                             },{
    CE_DEBUG_STR("rc_0_rssi_3                    = [0x%08x]  \n"), .addr=0, .mask=0x03000000, .offset=24,                             },{
    CE_DEBUG_STR("rc_0_rssi_4                    = [0x%08x]  \n"), .addr=0, .mask=0x00C00000, .offset=22,                             },{
    CE_DEBUG_STR("rc_0_rssi_5                    = [0x%08x]  \n"), .addr=0, .mask=0x00300000, .offset=20,                             },{
    CE_DEBUG_STR("rc_0_rssi_6                    = [0x%08x]  \n"), .addr=0, .mask=0x000C0000, .offset=18,                             },{
    CE_DEBUG_STR("rc_0_rssi_7                    = [0x%08x]  \n"), .addr=0, .mask=0x00030000, .offset=16,                             },{
    CE_DEBUG_STR("rc_0_rssi_valid                = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ PHY_1_RSSI_STATUS              [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000104, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rc_1_rssi_0                    = [0x%08x]  \n"), .addr=0, .mask=0xC0000000, .offset=30,                             },{
    CE_DEBUG_STR("rc_1_rssi_1                    = [0x%08x]  \n"), .addr=0, .mask=0x30000000, .offset=28,                             },{
    CE_DEBUG_STR("rc_1_rssi_2                    = [0x%08x]  \n"), .addr=0, .mask=0x0C000000, .offset=26,                             },{
    CE_DEBUG_STR("rc_1_rssi_3                    = [0x%08x]  \n"), .addr=0, .mask=0x03000000, .offset=24,                             },{
    CE_DEBUG_STR("rc_1_rssi_4                    = [0x%08x]  \n"), .addr=0, .mask=0x00C00000, .offset=22,                             },{
    CE_DEBUG_STR("rc_1_rssi_5                    = [0x%08x]  \n"), .addr=0, .mask=0x00300000, .offset=20,                             },{
    CE_DEBUG_STR("rc_1_rssi_6                    = [0x%08x]  \n"), .addr=0, .mask=0x000C0000, .offset=18,                             },{
    CE_DEBUG_STR("rc_1_rssi_7                    = [0x%08x]  \n"), .addr=0, .mask=0x00030000, .offset=16,                             },{
    CE_DEBUG_STR("rc_1_rssi_valid                = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ PHY_0_FWR_STATUS               [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000108, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_0_fwr_req_pend             = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("phy_0_fwr_issued_num           = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("phy_0_fwr_grant_num            = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("phy_0_fwr_req_num              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ PHY_1_FWR_STATUS               [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000010C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("phy_1_fwr_req_pend             = [0x%08x]  \n"), .addr=0, .mask=0x40000000, .offset=30,                             },{
    CE_DEBUG_STR("phy_1_fwr_issued_num           = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("phy_1_fwr_grant_num            = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("phy_1_fwr_req_num              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RF_FWR_STATUS                  [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000110, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rf_fwr_last_master             = [0x%08x]  \n"), .addr=0, .mask=0x00000100, .offset= 8,                             },{
    CE_DEBUG_STR("rf_fwr_last_data               = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ PHY_0_SPI_STATUS               [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000114, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rc_0_spi_rd_addr               = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("rc_0_spi_rd_data               = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rc_0_spi_wr_addr               = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("rc_0_spi_wr_data               = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ PHY_1_SPI_STATUS               [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000118, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rc_1_spi_rd_addr               = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("rc_1_spi_rd_data               = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rc_1_spi_wr_addr               = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("rc_1_spi_wr_data               = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RF_SPI_STATUS                  [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000011C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rf_spi_rd_addr                 = [0x%08x]  \n"), .addr=0, .mask=0x7F000000, .offset=24,                             },{
    CE_DEBUG_STR("rf_spi_rd_data                 = [0x%08x]  \n"), .addr=0, .mask=0x00FF0000, .offset=16,                             },{
    CE_DEBUG_STR("rf_spi_wr_addr                 = [0x%08x]  \n"), .addr=0, .mask=0x00007F00, .offset= 8,                             },{
    CE_DEBUG_STR("rf_spi_wr_data                 = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FEM_STATUS                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000120, .mask=0, .offset=0 },{
    CE_DEBUG_STR("fem_status                     = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ BTC_STATUS                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000124, .mask=0, .offset=0 },{
    CE_DEBUG_STR("btc_status                     = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ FSM_STATUS                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000128, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rssi_seq                       = [0x%08x]  \n"), .addr=0, .mask=0x00000700, .offset= 8,                             },{
    CE_DEBUG_STR("fwr_state                      = [0x%08x]  \n"), .addr=0, .mask=0x00000030, .offset= 4,                             },{
    CE_DEBUG_STR("spi_arb_state                  = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ MICTOR_SEL                     [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000012C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("mictor_1_sel                   = [0x%08x]  \n"), .addr=0, .mask=0x000000F0, .offset= 4,                             },{
    CE_DEBUG_STR("mictor_0_sel                   = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AUXADC_STAT_0                  [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000130, .mask=0, .offset=0 },{
    CE_DEBUG_STR("auxadc_data_1                  = [0x%08x]  \n"), .addr=0, .mask=0x00FFF000, .offset=12,                             },{
    CE_DEBUG_STR("auxadc_data_0                  = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AUXADC_STAT_1                  [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000134, .mask=0, .offset=0 },{
    CE_DEBUG_STR("auxadc_data_3                  = [0x%08x]  \n"), .addr=0, .mask=0x00FFF000, .offset=12,                             },{
    CE_DEBUG_STR("auxadc_data_2                  = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AUXADC_STAT_2                  [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x00000138, .mask=0, .offset=0 },{
    CE_DEBUG_STR("auxadc_data_5                  = [0x%08x]  \n"), .addr=0, .mask=0x00FFF000, .offset=12,                             },{
    CE_DEBUG_STR("auxadc_data_4                  = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ AUXADC_STAT_3                  [0x%08x]\n" ) , .addr=REG_RICU_BASE_ADDR + 0x0000013C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("auxadc_wr_ptr                  = [0x%08x]  \n"), .addr=0, .mask=0x07000000, .offset=24,                             },{
    CE_DEBUG_STR("auxadc_data_7                  = [0x%08x]  \n"), .addr=0, .mask=0x00FFF000, .offset=12,                             },{
    CE_DEBUG_STR("auxadc_data_6                  = [0x%08x]  \n"), .addr=0, .mask=0x00000FFF, .offset= 0,                             },{
    .str=NULL }
};//RICU 
