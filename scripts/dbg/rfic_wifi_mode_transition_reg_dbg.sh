


#(3w->4w)
function wifibtoff2wifistandby()
{
    write_field 0x604b4808 26 0xfbffffff 0x00000000 # (SX0_PLL_CTRL2.SX0_bgren) 
    write_field 0x604b4888 26 0xfbffffff 0x00000000 # (SX1_PLL_CTRL2.SX1_bgren) 
    usleep 500
    if [ "$BGR_MODE" = "BGR0_EN" ] || [ "$BGR_MODE" = "BGR0_BGR1_EN" ];
    then
        write_field 0x604b4808 26 0xfbffffff 1 # (SX0_PLL_CTRL2.SX0_bgren) 
    fi
    if [ "$BGR_MODE" = "BGR1_EN" ] || [ "$BGR_MODE" = "BGR0_BGR1_EN" ];
    then
        write_field 0x604b4888 26 0xfbffffff 1 # (SX1_PLL_CTRL2.SX1_bgren) 
    fi
    usleep 500
}

#(4w->5w)
function wifistandby2wf_idle()
{
    write_field 0x604b4830 4 0xffffffef 0x1 # (SX0_LOGEN_CTRL0.SX0_logen_ldo_en) 
    write_field 0x604b4830 21 0xffdfffff 0x1 # (SX0_LOGEN_CTRL0.SX0_lobuff_ldo_en) 
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b48b0 4 0xffffffef 0x1 # (SX1_LOGEN_CTRL0.SX1_logen_ldo_en) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b48b0 21 0xffdfffff 0x1 # (SX1_LOGEN_CTRL0.SX1_lobuff_ldo_en) 
    fi
    write_field 0x604b4830 26 0xfbffffff 0x1 # (SX0_LOGEN_CTRL0.SX0_losync_ldo_en) 
    usleep 1
    write_field 0x604b4980 8 0xfffffeff 0x1 # (CH0_GEN_CTRL0.CH0_bb_bias_en) 
    write_field 0x604b4a00 8 0xfffffeff 0x1 # (CH1_GEN_CTRL0.CH1_bb_bias_en) 
    usleep 18
    write_field 0x604b49a0 13 0xffffdfff 0x1 # (CH0_ADC_CONF.CH0_adc_ldo_en) 
    write_field 0x604b4a20 13 0xffffdfff 0x1 # (CH1_ADC_CONF.CH1_adc_ldo_en) 
    write_field 0x604b4984 8 0xfffffeff 0x1 # (CH0_GEN_CTRL1.CH0_dac_ldo_en) 
    write_field 0x604b4a04 8 0xfffffeff 0x1 # (CH1_GEN_CTRL1.CH1_dac_ldo_en) 
    write_field 0x604b4984 21 0xffdfffff 0x1 # (CH0_GEN_CTRL1.CH0_localdiv_ldo_en) 
    write_field 0x604b4a04 21 0xffdfffff 0x1 # (CH1_GEN_CTRL1.CH1_localdiv_ldo_en) 
    write_field 0x604b4988 9 0xfffffdff 0x1 # (CH0_GEN_CTRL2.CH0_bb_en) 
    write_field 0x604b4a08 9 0xfffffdff 0x1 # (CH1_GEN_CTRL2.CH1_bb_en) 
    write_field 0x604b49bc 23 0xff7fffff 0x1 # (RF_FEM0_LNA_CTRL0.CH0_rx_lna_st1_ldo10_en) 
    write_field 0x604b49bc 24 0xfeffffff 0x1 # (RF_FEM0_LNA_CTRL0.CH0_rx_lna_st1_ldo14_en) 
    write_field 0x604b49d8 19 0xfff7ffff 0x1 # (RF_FEM0_LNA_ST2_CTRL0.CH0_rx_lna_st2_ldo10_en) 
    write_field 0x604b49d8 20 0xffefffff 0x1 # (RF_FEM0_LNA_ST2_CTRL0.CH0_rx_lna_st2_ldo14_en) 
    write_field 0x604b4a3c 23 0xff7fffff 0x1 # (RF_FEM1_LNA_CTRL0.CH1_rx_lna_st1_ldo10_en) 
    write_field 0x604b4a3c 24 0xfeffffff 0x1 # (RF_FEM1_LNA_CTRL0.CH1_rx_lna_st1_ldo14_en) 
    write_field 0x604b4a58 19 0xfff7ffff 0x1 # (RF_FEM1_LNA_ST2_CTRL0.CH1_rx_lna_st2_ldo10_en) 
    write_field 0x604b4a58 20 0xffefffff 0x1 # (RF_FEM1_LNA_ST2_CTRL0.CH1_rx_lna_st2_ldo14_en) 
    write_field 0x604b4988 10 0xfffffbff 0x1 # (CH0_GEN_CTRL2.CH0_pdet_ldo_en) 
    write_field 0x604b4a08 10 0xfffffbff 0x1 # (CH1_GEN_CTRL2.CH1_pdet_ldo_en) 
    write_field 0x604b4b40 26 0xfbffffff 0x1 # (AUX_ADC_CTRL0.ADC_aux_ldo_en) 
    usleep 1
    write_field 0x604b4a80 8 0xfffffeff 0x1 # (BT_BBIQ.BT_bb_bias_en) 
    usleep 1
    write_field 0x604b4ad4 14 0xffffbfff 0x1 # (BT_ADC_STATIC_CONF.BT_adc_bias_en) 
    usleep 1
    write_field 0x604b4ad4 23 0xff7fffff 0x1 # (BT_ADC_STATIC_CONF.BT_adc_ldo_en) 
    usleep 2
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b4898 0 0xfffffffe 0x0 # (SX1_FSM_CTRL0.SX1_fsm_rstn) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b4898 0 0xfffffffe 0x1 # (SX1_FSM_CTRL0.SX1_fsm_rstn) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b4880 25 0xfdffffff 0x1 # (SX1_PLL_CTRL0.SX1_fsm_en) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b489c 9 0xfffffdff 0x1 # (SX1_FSM_CTRL1.SX1_fsm_power_on_seq_start) 
    fi
    usleep 10
    write_field 0x604b4818 0 0xfffffffe 0x0 # (SX0_FSM_CTRL0.SX0_fsm_rstn) 
    write_field 0x604b4818 0 0xfffffffe 0x1 # (SX0_FSM_CTRL0.SX0_fsm_rstn) 
    write_field 0x604b4800 25 0xfdffffff 0x1 # (SX0_PLL_CTRL0.SX0_fsm_en) 
    write_field 0x604b481c 9 0xfffffdff 0x1 # (SX0_FSM_CTRL1.SX0_fsm_power_on_seq_start) 
    usleep 10
}

#(5w->6w)
function wf_idle2wf_chainconfig()
{
    write_field 0x604b4920 0 0xfffffffc ${1} # (DPLL_OUTDIV_CTRL0.dpll_dac_clk_div_sel) 
    write_field 0x604b4920 2 0xfffffffb 0x1 # (DPLL_OUTDIV_CTRL0.dpll_adc_clk_div2_sel) 
    write_field 0x604b4920 7 0xffffff7f 0x0 # (DPLL_OUTDIV_CTRL0.dpll_clk_div_rstn) 
    write_field 0x604b4920 7 0xffffff7f 0x1 # (DPLL_OUTDIV_CTRL0.dpll_clk_div_rstn) 
    write_field 0x604b4920 9 0xfffffdff 0x1 # (DPLL_OUTDIV_CTRL0.dpll_adc_clkout_drv_en) 
    write_field 0x604b4920 10 0xfffffbff 0x1 # (DPLL_OUTDIV_CTRL0.dpll_dac_clkout_drv_en) 
    write_field 0x604b4920 11 0xfffff7ff 0x1 # (DPLL_OUTDIV_CTRL0.dpll_bt_aux_clk_drv_en) 
    write_field 0x604b4920 12 0xffffefff 0x1 # (DPLL_OUTDIV_CTRL0.dpll_ch0_adc_clk_drv_en) 
    write_field 0x604b4920 13 0xffffdfff 0x1 # (DPLL_OUTDIV_CTRL0.dpll_ch1_adc_clk_drv_en) 
    write_field 0x604b4920 14 0xffffbfff 0x1 # (DPLL_OUTDIV_CTRL0.dpll_ch0_dac_clk_drv_en) 
    write_field 0x604b4920 15 0xffff7fff 0x1 # (DPLL_OUTDIV_CTRL0.dpll_ch1_dac_clk_drv_en) 
    write_field 0x604b4ad4 15 0xffff7fff 0x1 # (BT_ADC_STATIC_CONF.BT_adc_divider_en) 
    write_field 0x604b4a90 7 0xffffff7f 0x1 # (BT_CHANNEL_CONF.BT_adc_neg_bias_clk_en) 
    write_field 0x604b498c 19 0xff87ffff 0x8 # (CH0_RSSI_CONF.CH0_adc_lpbk_spare) 
    write_field 0x604b4a0c 19 0xff87ffff 0x8 # (CH1_RSSI_CONF.CH1_adc_lpbk_spare) 
    write_field 0x604b4ad4 25 0xfdffffff 0x1 # (BT_ADC_STATIC_CONF.BT_aux_adc_clk_buf_en) 
    write_field 0x604b4b40 13 0xffffdfff 0x1 # (AUX_ADC_CTRL0.adc_AUX_en) 
    write_field 0x604b4980 25 0xf1ffffff ${2} # (CH0_GEN_CTRL0.CH0_bb_bw) 
    write_field 0x604b4a00 25 0xf1ffffff ${3} # (CH1_GEN_CTRL0.CH1_bb_bw) 
    write_field 0x604b49a0 0 0xfffffffc ${4} # (CH0_ADC_CONF.CH0_adc_cf) 
    write_field 0x604b4a20 0 0xfffffffc ${5} # (CH1_ADC_CONF.CH1_adc_cf) 
    write_field 0x604b49a0 2 0xfffffffb 0x1 # (CH0_ADC_CONF.CH0_adc_df) 
    write_field 0x604b4a20 2 0xfffffffb 0x1 # (CH1_ADC_CONF.CH1_adc_df) 
    write_field 0x604b49a4 2 0xfffffffb 0x0 # (CH0_DAC_CONF.CH0_dac_outmode) 
    write_field 0x604b4a24 2 0xfffffffb 0x0 # (CH1_DAC_CONF.CH1_dac_outmode) 
    write_field 0x604b49a4 0 0xfffffffe 0x1 # (CH0_DAC_CONF.CH0_dac_twocom_ob_sel) 
    write_field 0x604b4a24 0 0xfffffffe 0x1 # (CH1_DAC_CONF.CH1_dac_twocom_ob_sel) 
    write_field 0x604b4004 1 0xfffffff9 0x1 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    write_field 0x604b4004 9 0xfffff9ff 0x1 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    write_field 0x604b49a0 14 0xffffbfff 0x1 # (CH0_ADC_CONF.CH0_adc_caln) 
    write_field 0x604b4a20 14 0xffffbfff 0x1 # (CH1_ADC_CONF.CH1_adc_caln) 
    write_field 0x604b4b40 13 0xffffdfff 0x1 # (AUX_ADC_CTRL0.adc_AUX_en) 
    write_field 0x604b4b40 27 0xf7ffffff 0x0 # (AUX_ADC_CTRL0.adc_AUX_rstn) 
    write_field 0x604b4b40 21 0xffdfffff 0x0 # (AUX_ADC_CTRL0.AUX_ADC_comp_offset_cal_fsm_rstn) 
    write_field 0x604b4b40 2 0xfffffffb 0x1 # (AUX_ADC_CTRL0.adc_AUX_DF) 
    write_field 0x604b4b40 27 0xf7ffffff 0x1 # (AUX_ADC_CTRL0.adc_AUX_rstn) 
    write_field 0x604b4b40 21 0xffdfffff 0x1 # (AUX_ADC_CTRL0.AUX_ADC_comp_offset_cal_fsm_rstn) 
    write_field 0x604b4b40 20 0xffefffff 0x1 # (AUX_ADC_CTRL0.AUX_ADC_comp_offset_cal_fsm_en) 
    write_field 0x604b4b40 19 0xfff7ffff 0x1 # (AUX_ADC_CTRL0.AUX_ADC_comp_offset_cal_start) 
    write_field 0x604b4000 5 0xffffffdf 0x1 # (WIFI_DAC_SW_CTRL.DAC0_PDN_OVR_VAL) 
    write_field 0x604b4000 13 0xffffdfff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_PDN_OVR_VAL) 
    usleep 10
    write_field 0x604b4000 3 0xfffffff7 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    write_field 0x604b4000 11 0xfffff7ff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    write_field 0x604b4000 1 0xfffffffd 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    write_field 0x604b4000 9 0xfffffdff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    write_field 0x604b4004 1 0xfffffff9 0x3 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    write_field 0x604b4004 9 0xfffff9ff 0x3 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    write_field 0x604b4000 3 0xfffffff7 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    write_field 0x604b4000 11 0xfffff7ff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    write_field 0x604b4000 1 0xfffffffd 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    write_field 0x604b4000 9 0xfffffdff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
}

#(6w->7w)
function wf_chainconfig2wf_sxon()
{
    write_field 0x604b4800 27 0xe7ffffff 0x2 # (SX0_PLL_CTRL0.SX0_sdm_out_high_limit_sel) 
    write_field 0x604b4800 29 0x9fffffff 0x1 # (Sx0_PLL_CTRL0.SX0_sdm_out_low_limit_sel) 
    write_field 0x604b4818 8 0xfffffcff 0x1 # (SX0_FSM_CTRL0.SX0_fsm_lockdet_acc) 
    write_field 0x604b4818 28 0xfffffff 0xA # (SX0_FSM_CTRL0.SX0_fsm_freq_meas_dur) 
    write_field 0x604b481c 19 0xffe7ffff 0x1 # (SX0_FSM_CTRL1.SX0_fsm_ampl_update_per) 
    write_field 0x604b481c 0 0xfffffff8 0x1 # (SX0_FSM_CTRL1.SX0_fsm_kvco_meas_wait_time) 
    write_field 0x604b481c 7 0xffffff7f 0x1 # (SX0_FSM_CTRL1.SX0_fsm_lock_det_en) 
    write_field 0x604b4808 6 0xfffffe3f 0x5 # (SX0_PLL_CTRL2.SX0_lpf_sell) 
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b4880 27 0xe7ffffff 0x2 # (SX1_PLL_CTRL0.SX1_sdm_out_high_limit_sel) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b4880 29 0x9fffffff 0x1 # (SX1_PLL_CTRL0.SX1_sdm_out_low_limit_sel) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b4898 8 0xfffffcff 0x1 # (SX1_FSM_CTRL0.SX1_fsm_lockdet_acc) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b4898 28 0xfffffff 0xA # (SX1_FSM_CTRL0.SX1_fsm_freq_meas_dur) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b489c 19 0xffe7ffff 0x1 # (SX1_FSM_CTRL1.SX1_fsm_ampl_update_per) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b489c 0 0xfffffff8 0x1 # (SX1_FSM_CTRL1.SX1_fsm_kvco_meas_wait_time) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b489c 7 0xffffff7f 0x1 # (SX1_FSM_CTRL1.SX1_fsm_lock_det_en) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b4888 6 0xfffffe3f 0x5 # (SX1_PLL_CTRL2.SX1_lpf_sell) 
    fi
}

#(7w->8w)
function wf_sxon2wf_sxlocked()
{
    write_field 0x604b480c 30 0xbfffffff 0x0 # (SX0_PLL_CTRL3.SX0_freq_cfg_sel) 
    write_field 0x604b480c 0 0xffffff00 ${1} # (SX0_PLL_CTRL3.SX0_div_int) 
    write_field 0x604b480c 8 0xe00000ff ${2} # (SX0_PLL_CTRL3.SX0_div_nfrac) 
    write_field 0x604b4818 10 0xf00003ff ${3} # (SX0_FSM_CTRL0.SX0_fsm_freq_meas_trgt) 
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b488c 30 0xbfffffff 0x0 # (SX1_PLL_CTRL3.SX1_freq_cfg_sel) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b488c 0 0xffffff00 ${4} # (SX1_PLL_CTRL3.SX1_div_int) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b488c 8 0xe00000ff ${5} # (SX1_PLL_CTRL3.SX1_div_nfrac) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b4898 10 0xf00003ff ${6} # (SX1_FSM_CTRL0.SX1_fsm_freq_meas_trgt) 
    fi
    write_field 0x604b481c 4 0xffffffef 0x1 # (SX0_FSM_CTRL1.SX0_fsm_cal_en) 
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b489c 4 0xffffffef 0x1 # (SX1_FSM_CTRL1.SX1_fsm_cal_en) 
    fi
    write_field 0x604b481c 26 0xfbffffff 0x1 # (SX0_FSM_CTRL1.SX0_fsm_lpf_vctrl_high_flag_clear) 
    write_field 0x604b481c 27 0xf7ffffff 0x1 # (SX0_FSM_CTRL1.SX0_fsm_lpf_vctrl_low_flag_clear) 
    write_field 0x604b481c 26 0xfbffffff 0x0 # (SX0_FSM_CTRL1.SX0_fsm_lpf_vctrl_high_flag_clear) 
    write_field 0x604b481c 27 0xf7ffffff 0x0 # (SX0_FSM_CTRL1.SX0_fsm_lpf_vctrl_low_flag_clear) 
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b489c 26 0xfbffffff 0x1 # (SX1_FSM_CTRL1.SX1_fsm_lpf_vctrl_high_flag_clear) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b489c 27 0xf7ffffff 0x1 # (SX1_FSM_CTRL1.SX1_fsm_lpf_vctrl_low_flag_clear) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b489c 26 0xfbffffff 0x0 # (SX1_FSM_CTRL1.SX1_fsm_lpf_vctrl_high_flag_clear) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b489c 27 0xf7ffffff 0x0 # (SX1_FSM_CTRL1.SX1_fsm_lpf_vctrl_low_flag_clear) 
    fi
    write_field 0x604b481c 4 0xffffffef 0x0 # (SX0_FSM_CTRL1.SX0_fsm_cal_en) 
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b489c 4 0xffffffef 0x0 # (SX1_FSM_CTRL1.SX1_fsm_cal_en) 
    fi
    write_field 0x604b4830 0 0xfffffffe 0x1 # (SX0_LOGEN_CTRL0.SX0_logen_buff_en) 
    write_field 0x604b4830 17 0xfffdffff 0x1 # (SX0_LOGEN_CTRL0.SX0_logen_mx_en) 
    write_field 0x604b4830 3 0xfffffff7 0x1 # (SX0_LOGEN_CTRL0.SX0_logen_div2_drv_en) 
    write_field 0x604b4830 18 0xfffbffff 0x1 # (SX0_LOGEN_CTRL0.SX0_losync_en) 
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b48b0 0 0xfffffffe 0x1 # (SX1_LOGEN_CTRL0.SX1_logen_buff_en) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b48b0 17 0xfffdffff 0x1 # (SX1_LOGEN_CTRL0.SX1_logen_mx_en) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ];
    then
        write_field 0x604b48b0 3 0xfffffff7 0x1 # (SX1_LOGEN_CTRL0.SX1_logen_div2_drv_en) 
    fi
    write_field 0x604b4834 0 0xfffffffe ${7} # (SX0_IN_SPARE0.SX0_lobuff_splitter_drv_CH0_LOX0_en) 
    write_field 0x604b4834 1 0xfffffffd ${8} # (SX0_IN_SPARE0.SX0_lobuff_splitter_drv_CH0_LOX1_en) 
    write_field 0x604b4834 2 0xfffffffb ${9} # (SX0_IN_SPARE0.SX0_lobuff_splitter_drv_CH1_LOX0_en) 
    write_field 0x604b4830 20 0xffefffff ${10} # (SX0_LOGEN_CTRL0.SX0_lobuff_rep_drv_CH0_LOX1_en) 
    write_field 0x604b4830 19 0xfff7ffff ${11} # (SX0_LOGEN_CTRL0.SX0_lobuff_rep_drv_CH0_LOX0_en) 
    write_field 0x604b48b4 0 0xfffffffe ${12} # (SX1_IN_SPARE0.SX1_lobuff_splitter_drv_CH1_LOX0_en) 
    write_field 0x604b48b4 1 0xfffffffd ${13} # (SX1_IN_SPARE0.SX1_lobuff_splitter_drv_CH1_LOX1_en) 
    write_field 0x604b48b4 2 0xfffffffb ${14} # (SX1_IN_SPARE0.SX1_lobuff_splitter_drv_CH0_LOX1_en) 
    write_field 0x604b48b0 19 0xfff7ffff ${15} # (SX1_LOGEN_CTRL0.SX1_lobuff_rep_drv_CH1_LOX0_en) 
    write_field 0x604b48b0 20 0xffefffff ${16} # (SX1_LOGEN_CTRL0.SX1_lobuff_rep_drv_CH1_LOX1_en) 
    write_field 0x604b4980 25 0xf1ffffff skip # (CH0_GEN_CTRL0.CH0_bb_bw) 
    write_field 0x604b4a00 25 0xf1ffffff skip # (CH1_GEN_CTRL0.CH1_bb_bw) 
    write_field 0x604b49b0 23 0xf07fffff 0x3 # (CH0_SPARE_IN.CH0_lpf_gain_index_offset) 
    write_field 0x604b49b0 28 0xfffffff 0x2 # (CH0_SPARE_IN.CH0_lpf_tx_mode_gain) 
    write_field 0x604b4a30 23 0xf07fffff 0x3 # (CH1_SPARE_IN.CH1_lpf_gain_index_offset) 
    write_field 0x604b4a30 28 0xfffffff 0x2 # (CH1_SPARE_IN.CH1_lpf_tx_mode_gain) 
    write_field 0x604b49a0 0 0xfffffffc skip # (CH0_ADC_CONF.CH0_adc_cf) 
    write_field 0x604b4a20 0 0xfffffffc skip # (CH1_ADC_CONF.CH1_adc_cf) 
    write_field 0x604b49b0 0 0xfffffffe 0x0 # (CH0_SPARE_IN.CH0_rssi_rstn) 
    write_field 0x604b49b0 0 0xfffffffe 0x1 # (CH0_SPARE_IN.CH0_rssi_rstn) 
    write_field 0x604b4a30 0 0xfffffffe 0x0 # (CH1_SPARE_IN.CH1_rssi_rstn) 
    write_field 0x604b4a30 0 0xfffffffe 0x1 # (CH1_SPARE_IN.CH1_rssi_rstn) 
    write_field 0x604b498c 1 0xfffffffd 0x1 # (CH0_RSSI_CONF.CH0_rssi_en) 
    write_field 0x604b4a0c 1 0xfffffffd 0x1 # (CH1_RSSI_CONF.CH1_rssi_en) 
    if [ "$LB_WIFI_MODE" = "NOLB" ] || [ "$LB_WIFI_MODE" = "LB5" ] || [ "$LB_WIFI_MODE" = "LB6" ] || [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ] || [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ] || [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4980 31 0x7fffffff 0x1 # (CH0_GEN_CTRL0.CH0_trsw_en) 
    fi
    if [ "$LB_WIFI_MODE" = "NOLB" ] || [ "$LB_WIFI_MODE" = "LB5" ] || [ "$LB_WIFI_MODE" = "LB6" ] || [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ] || [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ] || [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4a00 31 0x7fffffff 0x1 # (CH1_GEN_CTRL0.CH1_trsw_en) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB14" ] || [ "$LB_WIFI_MODE" = "LB15" ] || [ "$LB_WIFI_MODE" = "LB16" ] || [ "$LB_WIFI_MODE" = "LB17" ] || [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4980 31 0x7fffffff 0x0 # (CH0_GEN_CTRL0.CH0_trsw_en) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB14" ] || [ "$LB_WIFI_MODE" = "LB15" ] || [ "$LB_WIFI_MODE" = "LB16" ] || [ "$LB_WIFI_MODE" = "LB17" ] || [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4a00 31 0x7fffffff 0x0 # (CH1_GEN_CTRL0.CH1_trsw_en) 
    fi
    write_field 0x604b4984 18 0xfffbffff 0x1 # (CH0_GEN_CTRL1.CH0_localdiv_divbuff_en) 
    write_field 0x604b4a04 18 0xfffbffff 0x1 # (CH1_GEN_CTRL1.CH1_localdiv_divbuff_en) 
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4984 18 0xfffbffff 0x0 # (CH0_GEN_CTRL1.CH0_localdiv_divbuff_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4a04 18 0xfffbffff 0x0 # (CH1_GEN_CTRL1.CH1_localdiv_divbuff_en) 
    fi
    write_field 0x604b4984 30 0xbfffffff ${17} # (CH0_GEN_CTRL1.CH0_localdiv_sx_sel) 
    write_field 0x604b4a04 30 0xbfffffff ${18} # (CH1_GEN_CTRL1.CH1_localdiv_sx_sel) 
    write_field 0x604b499c 8 0xfffffcff 0x2 # (CH0_TX_CTRL3.CH0_pdet_gain) 
    write_field 0x604b499c 1 0xfffffffd 0x1 # (CH0_TX_CTRL3.CH0_pdet_en) 
    write_field 0x604b4a1c 8 0xfffffcff 0x2 # (CH1_TX_CTRL3.CH1_pdet_gain) 
    write_field 0x604b4a1c 1 0xfffffffd 0x1 # (CH1_TX_CTRL3.CH1_pdet_en) 
    write_field 0x604b4b40 14 0xfffc3fff 0x2 # (AUX_ADC_CTRL0.adc_AUX_input_sel) 
    write_field 0x604b4984 2 0xfffffffb 0x1 # (CH0_GEN_CTRL1.CH0_tempsens_en) 
    write_field 0x604b4c10 0 0xffffffc0 0x23 # (CH0_ATB_CTRL.CH0_atb_sel) 
    write_field 0x604b4c20 7 0xfffff87f 0x7 # (DPLL_TEST.atb_en_address) 
    write_field 0x604b4a04 2 0xfffffffb 0x1 # (CH1_GEN_CTRL1.CH1_tempsens_en) 
    write_field 0x604b4c14 0 0xffffffc0 0x23 # (CH1_ATB_CTRL.CH1_atb_sel) 
    write_field 0x604b4c20 7 0xfffff87f 0x9 # (DPLL_TEST.atb_en_address) 
    write_field 0x604b4b40 14 0xfffc3fff 0x1 # (AUX_ADC_CTRL0.adc_AUX_input_sel) 
    write_field 0x604b49d4 8 0xfffffeff 0x1 # (RF_FEM0_PA_CTRL0.CH0_tx_pa_lb_res_ladder_en) 
    write_field 0x604b49d4 7 0xffffff7f 0x1 # (RF_FEM0_PA_CTRL0.CH0_tx_pa_hb_res_ladder_en) 
    write_field 0x604b4a54 8 0xfffffeff 0x1 # (RF_FEM1_PA_CTRL0.CH1_tx_pa_lb_res_ladder_en) 
    write_field 0x604b4a54 7 0xffffff7f 0x1 # (RF_FEM1_PA_CTRL0.CH1_tx_pa_hb_res_ladder_en) 
    write_field 0x604b49c4 6 0xfffff83f 0x08 # (RF_FEM0_PA_2P5G_CTRL0.CH0_tx_pa_lb_stg1_vg2) 
    write_field 0x604b49c4 11 0xffff07ff 0x10 # (RF_FEM0_PA_2P5G_CTRL0.CH0_tx_pa_lb_stg1_vg3) 
    write_field 0x604b49c4 22 0xf83fffff 0x08 # (RF_FEM0_PA_2P5G_CTRL0.CH0_tx_pa_lb_stg2_vg2) 
    write_field 0x604b49c4 27 0x7ffffff 0x10 # (RF_FEM0_PA_2P5G_CTRL0.CH0_tx_pa_lb_stg2_vg3) 
    write_field 0x604b49c8 8 0xffffe0ff 0x08 # (RF_FEM0_PA_5G_CTRL0.CH0_tx_pa_hb_stg1_vg2) 
    write_field 0x604b49c8 13 0xfffc1fff 0x10 # (RF_FEM0_PA_5G_CTRL0.CH0_tx_pa_hb_stg1_vg3) 
    write_field 0x604b49c8 24 0xe0ffffff 0x08 # (RF_FEM0_PA_5G_CTRL0.CH0_tx_pa_hb_stg2_vg2) 
    write_field 0x604b49cc 0 0xffffffe0 0x10 # (RF_FEM0_PA_5G_CTRL1.CH0_tx_pa_hb_stg2_vg3) 
    write_field 0x604b4a44 6 0xfffff83f 0x08 # (RF_FEM1_PA_2P5G_CTRL0.CH1_tx_pa_lb_stg1_vg2) 
    write_field 0x604b4a44 11 0xffff07ff 0x10 # (RF_FEM1_PA_2P5G_CTRL0.CH1_tx_pa_lb_stg1_vg3) 
    write_field 0x604b4a44 22 0xf83fffff 0x08 # (RF_FEM1_PA_2P5G_CTRL0.CH1_tx_pa_lb_stg2_vg2) 
    write_field 0x604b4a44 27 0x7ffffff 0x10 # (RF_FEM1_PA_2P5G_CTRL0.CH1_tx_pa_lb_stg2_vg3) 
    write_field 0x604b4a48 8 0xffffe0ff 0x08 # (RF_FEM1_PA_5G_CTRL0.CH1_tx_pa_hb_stg1_vg2) 
    write_field 0x604b4a48 13 0xfffc1fff 0x10 # (RF_FEM1_PA_5G_CTRL0.CH1_tx_pa_hb_stg1_vg3) 
    write_field 0x604b4a48 24 0xe0ffffff 0x08 # (RF_FEM1_PA_5G_CTRL0.CH1_tx_pa_hb_stg2_vg2) 
    write_field 0x604b4a4c 0 0xffffffe0 0x10 # (RF_FEM1_PA_5G_CTRL1.CH1_tx_pa_hb_stg2_vg3) 
    write_field 0x604b49b0 3 0xffffff07 0x14 # (CH0_SPARE_IN.CH0_tx_pa_lb_stg1_vg2_pd) 
    write_field 0x604b49b0 8 0xffffe0ff 0x0A # (CH0_SPARE_IN.CH0_tx_pa_lb_stg1_vg3_pd) 
    write_field 0x604b49b0 13 0xfffc1fff 0x14 # (CH0_SPARE_IN.CH0_tx_pa_lb_stg2_vg2_pd) 
    write_field 0x604b49b0 18 0xff83ffff 0x0A # (CH0_SPARE_IN.CH0_tx_pa_lb_stg2_vg3_pd) 
    write_field 0x604b49cc 5 0xfffffc1f 0x14 # (RF_FEM0_PA_5G_CTRL1.CH0_tx_pa_hb_stg1_vg2_pd) 
    write_field 0x604b49cc 10 0xffff83ff 0x0A # (RF_FEM0_PA_5G_CTRL1.CH0_tx_pa_hb_stg1_vg3_pd) 
    write_field 0x604b49cc 15 0xfff07fff 0x14 # (RF_FEM0_PA_5G_CTRL1.CH0_tx_pa_hb_stg2_vg2_pd) 
    write_field 0x604b49cc 20 0xfe0fffff 0x0A # (RF_FEM0_PA_5G_CTRL1.CH0_tx_pa_hb_stg2_vg3_pd) 
    write_field 0x604b4a30 3 0xffffff07 0x14 # (CH1_SPARE_IN.CH1_tx_pa_lb_stg1_vg2_pd) 
    write_field 0x604b4a30 8 0xffffe0ff 0x0A # (CH1_SPARE_IN.CH1_tx_pa_lb_stg1_vg3_pd) 
    write_field 0x604b4a30 13 0xfffc1fff 0x14 # (CH1_SPARE_IN.CH1_tx_pa_lb_stg2_vg2_pd) 
    write_field 0x604b4a30 18 0xff83ffff 0x0A # (CH1_SPARE_IN.CH1_tx_pa_lb_stg2_vg3_pd) 
    write_field 0x604b4a4c 5 0xfffffc1f 0x14 # (RF_FEM1_PA_5G_CTRL1.CH1_tx_pa_hb_stg1_vg2_pd) 
    write_field 0x604b4a4c 10 0xffff83ff 0x0A # (RF_FEM1_PA_5G_CTRL1.CH1_tx_pa_hb_stg1_vg3_pd) 
    write_field 0x604b4a4c 15 0xfff07fff 0x14 # (RF_FEM1_PA_5G_CTRL1.CH1_tx_pa_hb_stg2_vg2_pd) 
    write_field 0x604b4a4c 20 0xfe0fffff 0x0A # (RF_FEM1_PA_5G_CTRL1.CH1_tx_pa_hb_stg2_vg3_pd) 
    if [ "$LB_WIFI_MODE" = "LB1" ];
    then
        write_field 0x604b4040 1 0xfffffff9 0x1 # (lb_cfg.WIFI_ADC1_LB_SEL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB2" ];
    then
        write_field 0x604b4040 0 0xfffffffe 0x1 # (lb_cfg.WIFI_ADC0_LB_SEL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB6" ];
    then
        write_field 0x604b4a24 3 0xfffffff7 0x1 # (CH1_DAC_CONF.CH1_dac_lpbk_en) 
    fi
    if [ "$LB_WIFI_MODE" = "LB6" ];
    then
        write_field 0x604b498c 14 0xffffbfff 0x1 # (CH0_RSSI_CONF.CH0_adc_lpbk_en) 
    fi
    if [ "$LB_WIFI_MODE" = "LB5" ];
    then
        write_field 0x604b49a4 3 0xfffffff7 0x1 # (CH0_DAC_CONF.CH0_dac_lpbk_en) 
    fi
    if [ "$LB_WIFI_MODE" = "LB5" ];
    then
        write_field 0x604b4a0c 14 0xffffbfff 0x1 # (CH1_RSSI_CONF.CH1_adc_lpbk_en) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ];
    then
        write_field 0x604b4988 23 0xff7fffff 0x1 # (CH0_GEN_CTRL2.CH0_loopbk_phase_shifter_ctrl) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ];
    then
        write_field 0x604b4988 31 0x7fffffff 0x1 # (CH0_GEN_CTRL2.CH0_loopbk_amp_en) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ];
then        write_field 0x604b4988 0 0x0 skip # (CH0_GEN_CTRL2.CH0_loopbk_atten_ctrl[3:2]) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ];
    then
        write_field 0x604b4a54 15 0xffff7fff 0x1 # (RF_FEM1_PA_CTRL0.CH1_rx_lna_loopbk_sw_en) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ];
    then
        write_field 0x604b4a08 23 0xff7fffff 0x0 # (CH1_GEN_CTRL2.CH1_loopbk_phase_shifter_ctrl) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ];
    then
        write_field 0x604b4a08 31 0x7fffffff 0x1 # (CH1_GEN_CTRL2.CH1_loopbk_amp_en) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ];
then        write_field 0x604b4a08 0 0x0 skip # (CH1_GEN_CTRL2.CH1_loopbk_atten_ctrl[3:2]) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ];
    then
        write_field 0x604b49d4 15 0xffff7fff 0x1 # (RF_FEM0_PA_CTRL0.CH0_rx_lna_loopbk_sw_en) 
    fi
    if [ "$LB_WIFI_MODE" = "LB14" ];
    then
        write_field 0x604b4a54 15 0xffff7fff 0x1 # (RF_FEM1_PA_CTRL0.CH1_rx_lna_loopbk_sw_en) 
    fi
    if [ "$LB_WIFI_MODE" = "LB15" ];
    then
        write_field 0x604b4988 31 0x7fffffff 0x1 # (CH0_GEN_CTRL2.CH0_loopbk_amp_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4980 28 0xefffffff 0x1 # (CH0_GEN_CTRL0.CH0_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4a00 28 0xefffffff 0x1 # (CH1_GEN_CTRL0.CH1_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ];
    then
        write_field 0x604b49b8 16 0xfffeffff 0x0 # (CH0_ADC_DAC_SPARE.CH0_dac_external_pad_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4a38 16 0xfffeffff 0x0 # (CH1_ADC_DAC_SPARE.CH1_dac_external_pad_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ];
    then
        write_field 0x604b4980 28 0xefffffff 0x0 # (CH0_GEN_CTRL0.CH0_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ];
    then
        write_field 0x604b4a00 28 0xefffffff 0x0 # (CH1_GEN_CTRL0.CH1_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b49b8 16 0xfffeffff 0x1 # (CH0_ADC_DAC_SPARE.CH0_dac_external_pad_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4a38 16 0xfffeffff 0x1 # (CH1_ADC_DAC_SPARE.CH1_dac_external_pad_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ];
    then
        write_field 0x604b4980 28 0xefffffff 0x0 # (CH0_GEN_CTRL0.CH0_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ];
    then
        write_field 0x604b4a00 28 0xefffffff 0x0 # (CH1_GEN_CTRL0.CH1_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b49b8 16 0xfffeffff 0x1 # (CH0_ADC_DAC_SPARE.CH0_dac_external_pad_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4a38 16 0xfffeffff 0x1 # (CH1_ADC_DAC_SPARE.CH1_dac_external_pad_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4980 28 0xefffffff 0x1 # (CH0_GEN_CTRL0.CH0_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4a00 28 0xefffffff 0x1 # (CH1_GEN_CTRL0.CH1_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b49b8 16 0xfffeffff 0x0 # (CH0_ADC_DAC_SPARE.CH0_dac_external_pad_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4a38 16 0xfffeffff 0x0 # (CH1_ADC_DAC_SPARE.CH1_dac_external_pad_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ];
    then
        write_field 0x604b4980 28 0xefffffff 0x1 # (CH0_GEN_CTRL0.CH0_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ];
    then
        write_field 0x604b4a00 28 0xefffffff 0x1 # (CH1_GEN_CTRL0.CH1_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4980 28 0xefffffff 0x0 # (CH0_GEN_CTRL0.CH0_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4a00 28 0xefffffff 0x0 # (CH1_GEN_CTRL0.CH1_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b49a4 3 0xfffffff7 0x1 # (CH0_DAC_CONF.CH0_dac_lpbk_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4a24 3 0xfffffff7 0x1 # (CH1_DAC_CONF.CH1_dac_lpbk_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b498c 14 0xffffbfff 0x1 # (CH0_RSSI_CONF.CH0_adc_lpbk_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4a0c 14 0xffffbfff 0x1 # (CH1_RSSI_CONF.CH1_adc_lpbk_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b49b8 16 0xfffeffff 0x1 # (CH0_ADC_DAC_SPARE.CH0_dac_external_pad_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4a38 16 0xfffeffff 0x1 # (CH1_ADC_DAC_SPARE.CH1_dac_external_pad_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b49b0 23 0xf07fffff 0x2 # (CH0_SPARE_IN.CH0_lpf_gain_index_offset) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4a30 23 0xf07fffff 0x2 # (CH1_SPARE_IN.CH1_lpf_gain_index_offset) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4980 28 0xefffffff 0x1 # (CH0_GEN_CTRL0.CH0_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4a00 28 0xefffffff 0x1 # (CH1_GEN_CTRL0.CH1_bb_exten) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b49a4 3 0xfffffff7 0x1 # (CH0_DAC_CONF.CH0_dac_lpbk_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4a24 3 0xfffffff7 0x1 # (CH1_DAC_CONF.CH1_dac_lpbk_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b498c 14 0xffffbfff 0x1 # (CH0_RSSI_CONF.CH0_adc_lpbk_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4a0c 14 0xffffbfff 0x1 # (CH1_RSSI_CONF.CH1_adc_lpbk_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b49b8 16 0xfffeffff 0x0 # (CH0_ADC_DAC_SPARE.CH0_dac_external_pad_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4a38 16 0xfffeffff 0x0 # (CH1_ADC_DAC_SPARE.CH1_dac_external_pad_en) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b49b0 23 0xf07fffff 0x2 # (CH0_SPARE_IN.CH0_lpf_gain_index_offset) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4a30 23 0xf07fffff 0x2 # (CH1_SPARE_IN.CH1_lpf_gain_index_offset) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 0 0xfffffffe 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 2 0xfffffffb 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 4 0xffffffef 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 8 0xfffffeff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 10 0xfffffbff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 12 0xffffefff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b400c 0 0xfffffffe 0x0 # (WIFI_RF_TX_SW_CTRL1.CH0_RF_TX_GAIN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b400c 12 0xffffefff 0x0 # (WIFI_RF_TX_SW_CTRL1.CH1_RF_TX_GAIN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b401c 0 0xfffffffe 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b401c 8 0xfffffeff 0x0 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4020 0 0xfffffffe 0x0 # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4020 12 0xffffefff 0x0 # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4024 0 0xfffffffe 0x0 # (WIFI_RF_RX_SW_CTRL2.SX0_FRAC_FREQ_SEL_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 4 0xffffffef 0x0 # (WIFI_DAC_SW_CTRL.DAC0_PDN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 2 0xfffffffb 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 0 0xfffffffe 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 12 0xffffefff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_PDN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 10 0xfffffbff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 8 0xfffffeff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4004 0 0xfffffffe 0x0 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4004 8 0xfffffeff 0x0 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4004 16 0xfffeffff 0x0 # (WIFI_ADC_SW_CTRL.ADC_DATA_EN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4028 0 0xfffffffe 0x0 # (WIFI_RF_RX_SW_CTRL3.CH0_RSSI_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4028 8 0xfffffeff 0x0 # (WIFI_RF_RX_SW_CTRL3.CH1_RSSI_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4028 4 0xffffffef 0x0 # (WIFI_RF_RX_SW_CTRL3.CH0_RSSI_VALID_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4028 12 0xffffefff 0x0 # (WIFI_RF_RX_SW_CTRL3.CH1_RSSI_VALID_OVR_EN) 
    fi
}

#(8w->9w)
function wf_sxlocked2rxon()
{
    write_field 0x604b4008 0 0xfffffffe 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_EN) 
    write_field 0x604b4008 2 0xfffffffb 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_EN) 
    write_field 0x604b4008 4 0xffffffef 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_EN) 
    write_field 0x604b4008 8 0xfffffeff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_EN) 
    write_field 0x604b4008 10 0xfffffbff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_EN) 
    write_field 0x604b4008 12 0xffffefff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_EN) 
    write_field 0x604b400c 0 0xfffffffe 0x1 # (WIFI_RF_TX_SW_CTRL1.CH0_RF_TX_GAIN_OVR_EN) 
    write_field 0x604b400c 12 0xffffefff 0x1 # (WIFI_RF_TX_SW_CTRL1.CH1_RF_TX_GAIN_OVR_EN) 
    write_field 0x604b401c 0 0xfffffffe 0x1 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_EN) 
    write_field 0x604b401c 8 0xfffffeff 0x1 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_EN) 
    write_field 0x604b4020 0 0xfffffffe 0x1 # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_EN) 
    write_field 0x604b4020 12 0xffffefff 0x1 # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_EN) 
    write_field 0x604b4024 0 0xfffffffe 0x1 # (WIFI_RF_RX_SW_CTRL2.SX0_FRAC_FREQ_SEL_OVR_EN) 
    write_field 0x604b4000 4 0xffffffef 0x1 # (WIFI_DAC_SW_CTRL.DAC0_PDN_OVR_EN) 
    write_field 0x604b4000 2 0xfffffffb 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_EN) 
    write_field 0x604b4000 0 0xfffffffe 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_EN) 
    write_field 0x604b4000 12 0xffffefff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_PDN_OVR_EN) 
    write_field 0x604b4000 10 0xfffffbff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_EN) 
    write_field 0x604b4000 8 0xfffffeff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_EN) 
    write_field 0x604b4004 0 0xfffffffe 0x1 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_EN) 
    write_field 0x604b4004 8 0xfffffeff 0x1 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_EN) 
    write_field 0x604b4004 16 0xfffeffff 0x1 # (WIFI_ADC_SW_CTRL.ADC_DATA_EN_OVR_EN) 
    write_field 0x604b4028 0 0xfffffffe 0x1 # (WIFI_RF_RX_SW_CTRL3.CH0_RSSI_OVR_EN) 
    write_field 0x604b4028 8 0xfffffeff 0x1 # (WIFI_RF_RX_SW_CTRL3.CH1_RSSI_OVR_EN) 
    write_field 0x604b4028 4 0xffffffef 0x1 # (WIFI_RF_RX_SW_CTRL3.CH0_RSSI_VALID_OVR_EN) 
    write_field 0x604b4028 12 0xffffefff 0x1 # (WIFI_RF_RX_SW_CTRL3.CH1_RSSI_VALID_OVR_EN) 
    if [ "$LB_WIFI_MODE" = "LB16" ] || [ "$LB_WIFI_MODE" = "LB17" ];
    then
        write_field 0x604b4020 0 0xfffffffe 0x0 # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_EN) 
    fi
    if [ "$LB_WIFI_MODE" = "LB16" ] || [ "$LB_WIFI_MODE" = "LB17" ];
    then
        write_field 0x604b4020 12 0xffffefff 0x0 # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_EN) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ] || [ "$SYSTEM_MODE" = "BT_CALIB" ];
    then
        write_field 0x604b4010 0 0xfffffffc 0x3 # (WIFI_SB_COMMON_CTRL.ADC_DATA_EN_MODE) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4000 3 0xfffffff7 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4000 11 0xfffff7ff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4000 1 0xfffffffd 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4000 9 0xfffffdff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x1 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x1 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4004 1 0xfffffff9 0x1 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4004 9 0xfffff9ff 0x1 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    fi
    usleep 4
    usleep 8
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4020 1 0xfffffc01 ${1} # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4020 13 0xffc01fff ${2} # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_VAL) 
    fi
    usleep 2
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4000 3 0xfffffff7 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4000 11 0xfffff7ff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4000 1 0xfffffffd 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4000 9 0xfffffdff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x1 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x0 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4004 1 0xfffffff9 0x1 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    fi
    usleep 4
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4004 9 0xfffff9ff 0x3 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    fi
    usleep 8
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4020 1 0xfffffc01 ${3} # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4020 13 0xffc01fff ${4} # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_VAL) 
    fi
    usleep 2
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 3 0xfffffff7 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 11 0xfffff7ff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 1 0xfffffffd 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 9 0xfffffdff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x1 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4004 1 0xfffffff9 0x3 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4004 9 0xfffff9ff 0x1 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    fi
    usleep 4
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4020 1 0xfffffc01 ${5} # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_VAL) 
    fi
    usleep 8
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4020 13 0xffc01fff ${6} # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ] || [ "$LB_WIFI_MODE" = "LB6" ];
    then
        write_field 0x604b4000 3 0xfffffff7 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ] || [ "$LB_WIFI_MODE" = "LB6" ];
    then
        write_field 0x604b4000 1 0xfffffffd 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ] || [ "$LB_WIFI_MODE" = "LB6" ];
    then
        write_field 0x604b4000 5 0xffffffdf 0x1 # (WIFI_DAC_SW_CTRL.DAC0_PDN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x1 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ] || [ "$LB_WIFI_MODE" = "LB6" ];
    then
        write_field 0x604b4004 1 0xfffffff9 0x1 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ];
    then
        write_field 0x604b4020 1 0xfffffc01 ${7} # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ] || [ "$LB_WIFI_MODE" = "LB5" ];
    then
        write_field 0x604b4000 11 0xfffff7ff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ] || [ "$LB_WIFI_MODE" = "LB5" ];
    then
        write_field 0x604b4000 9 0xfffffdff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ] || [ "$LB_WIFI_MODE" = "LB5" ];
    then
        write_field 0x604b4000 13 0xffffdfff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_PDN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x1 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ] || [ "$LB_WIFI_MODE" = "LB5" ];
    then
        write_field 0x604b4004 9 0xfffff9ff 0x1 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ];
    then
        write_field 0x604b4020 13 0xffc01fff ${8} # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x1 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4020 1 0xfffffc01 ${9} # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x1 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4020 13 0xffc01fff ${10} # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4004 1 0xfffffff9 0x1 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4004 9 0xfffff9ff 0x1 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x1 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4020 1 0xfffffc01 ${11} # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x1 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4020 13 0xffc01fff ${12} # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_RF_TO_EXTPAD_OBS" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4004 1 0xfffffff9 0x1 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4004 9 0xfffff9ff 0x1 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x0 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4004 1 0xfffffff9 0x1 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4004 9 0xfffff9ff 0x1 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x1 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4020 1 0xfffffc01 0x0 # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x1 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4020 13 0xffc01fff 0x0 # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_LPF_TO_IQ" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4000 3 0xfffffff7 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 1 0xfffffffd 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4000 11 0xfffff7ff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 9 0xfffffdff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4004 1 0xfffffff9 0x1 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4004 9 0xfffff9ff 0x1 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x1 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4020 1 0xfffffc01 0x0 # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x1 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4020 13 0xffc01fff 0x0 # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_LPF_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
}

#(8w->8w)
function wf_sxlocked2sxlocked()
{
    write_field 0x604b480c 30 0xbfffffff 0x0 # (SX0_PLL_CTRL3.SX0_freq_cfg_sel) 
    write_field 0x604b480c 0 0xffffff00 ${1} # (SX0_PLL_CTRL3.SX0_div_int) 
    write_field 0x604b480c 8 0xe00000ff ${2} # (SX0_PLL_CTRL3.SX0_div_nfrac) 
    write_field 0x604b4818 10 0xf00003ff ${3} # (SX0_FSM_CTRL0.SX0_fsm_freq_meas_trgt) 
    write_field 0x604b488c 30 0xbfffffff skip # (SX1_PLL_CTRL3.SX1_freq_cfg_sel) 
    write_field 0x604b488c 0 0xffffff00 skip # (SX1_PLL_CTRL3.SX1_div_int) 
    write_field 0x604b488c 8 0xe00000ff skip # (SX1_PLL_CTRL3.SX1_div_nfrac) 
    write_field 0x604b4898 10 0xf00003ff skip # (SX1_FSM_CTRL0.SX1_fsm_freq_meas_trgt) 
    write_field 0x604b481c 4 0xffffffef 0x1 # (SX0_FSM_CTRL1.SX0_fsm_cal_en) 
    write_field 0x604b489c 4 0xffffffef skip # (SX1_FSM_CTRL1.SX1_fsm_cal_en) 
    write_field 0x604b480c 31 0x7fffffff 0x0 # (SX0_PLL_CTRL3.SX0_soft_rstn) 
    write_field 0x604b480c 31 0x7fffffff 0x1 # (SX0_PLL_CTRL3.SX0_soft_rstn) 
    write_field 0x604b481c 4 0xffffffef 0x0 # (SX0_FSM_CTRL1.SX0_fsm_cal_en) 
    write_field 0x604b489c 4 0xffffffef skip # (SX1_FSM_CTRL1.SX1_fsm_cal_en) 
    write_field 0x604b4980 25 0xf1ffffff ${4} # (CH0_GEN_CTRL0.CH0_bb_bw) 
    write_field 0x604b4a00 25 0xf1ffffff ${5} # (CH1_GEN_CTRL0.CH1_bb_bw) 
    write_field 0x604b49a0 0 0xfffffffc ${6} # (CH0_ADC_CONF.CH0_adc_cf) 
    write_field 0x604b4a20 0 0xfffffffc ${7} # (CH1_ADC_CONF.CH1_adc_cf) 
    write_field 0x604b4920 0 0xfffffffc ${8} # (DPLL_OUTDIV_CTRL0.dpll_dac_clk_div_sel) 
    write_field 0x604b4920 2 0xfffffffb 0x1 # (DPLL_OUTDIV_CTRL0.dpll_adc_clk_div2_sel) 
    write_field 0x604b49b0 0 0xfffffffe 0x0 # (CH0_SPARE_IN.CH0_rssi_rstn) 
    write_field 0x604b49b0 0 0xfffffffe 0x1 # (CH0_SPARE_IN.CH0_rssi_rstn) 
    write_field 0x604b4a30 0 0xfffffffe 0x0 # (CH1_SPARE_IN.CH1_rssi_rstn) 
    write_field 0x604b4a30 0 0xfffffffe 0x1 # (CH1_SPARE_IN.CH1_rssi_rstn) 
    write_field 0x604b498c 1 0xfffffffd 0x1 # (CH0_RSSI_CONF.CH0_rssi_en) 
    write_field 0x604b4a0c 1 0xfffffffd 0x1 # (CH1_RSSI_CONF.CH1_rssi_en) 
    write_field 0x604b4980 31 0x7fffffff 0x1 # (CH0_GEN_CTRL0.CH0_trsw_en) 
    write_field 0x604b4a00 31 0x7fffffff 0x1 # (CH1_GEN_CTRL0.CH1_trsw_en) 
    write_field 0x604b4984 18 0xfffbffff 0x1 # (CH0_GEN_CTRL1.CH0_localdiv_divbuff_en) 
    write_field 0x604b4a04 18 0xfffbffff 0x1 # (CH1_GEN_CTRL1.CH1_localdiv_divbuff_en) 
    write_field 0x604b4984 30 0xbfffffff 0x0 # (CH0_GEN_CTRL1.CH0_localdiv_sx_sel) 
    write_field 0x604b4a04 30 0xbfffffff 0x0 # (CH1_GEN_CTRL1.CH1_localdiv_sx_sel) 
}

#(9w->8w)
function wf_rxon2sxlocked()
{
    write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    write_field 0x604b4000 3 0xfffffff7 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    write_field 0x604b4000 11 0xfffff7ff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    write_field 0x604b4000 1 0xfffffffd 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    write_field 0x604b4000 9 0xfffffdff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    write_field 0x604b4008 13 0xffffdfff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    write_field 0x604b401c 1 0xfffffffd 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    write_field 0x604b401c 9 0xfffffdff 0x0 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    write_field 0x604b4004 1 0xfffffff9 0x3 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    write_field 0x604b4004 9 0xfffff9ff 0x3 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    write_field 0x604b4020 1 0xfffffc01 TBD # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_VAL) 
    write_field 0x604b4020 13 0xffc01fff TBD # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_VAL) 
}

#(8w->10w)
function wf_sxlocked2txon()
{
    write_field 0x604b4008 0 0xfffffffe 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_EN) 
    write_field 0x604b4008 2 0xfffffffb 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_EN) 
    write_field 0x604b4008 4 0xffffffef 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_EN) 
    write_field 0x604b4008 8 0xfffffeff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_EN) 
    write_field 0x604b4008 10 0xfffffbff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_EN) 
    write_field 0x604b4008 12 0xffffefff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_EN) 
    write_field 0x604b400c 0 0xfffffffe 0x1 # (WIFI_RF_TX_SW_CTRL1.CH0_RF_TX_GAIN_OVR_EN) 
    write_field 0x604b400c 12 0xffffefff 0x1 # (WIFI_RF_TX_SW_CTRL1.CH1_RF_TX_GAIN_OVR_EN) 
    write_field 0x604b401c 0 0xfffffffe 0x1 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_EN) 
    write_field 0x604b401c 8 0xfffffeff 0x1 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_EN) 
    write_field 0x604b4020 0 0xfffffffe 0x1 # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_EN) 
    write_field 0x604b4020 12 0xffffefff 0x1 # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_EN) 
    write_field 0x604b4024 0 0xfffffffe 0x1 # (WIFI_RF_RX_SW_CTRL2.SX0_FRAC_FREQ_SEL_OVR_EN) 
    write_field 0x604b4000 4 0xffffffef 0x1 # (WIFI_DAC_SW_CTRL.DAC0_PDN_OVR_EN) 
    write_field 0x604b4000 2 0xfffffffb 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_EN) 
    write_field 0x604b4000 0 0xfffffffe 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_EN) 
    write_field 0x604b4000 12 0xffffefff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_PDN_OVR_EN) 
    write_field 0x604b4000 10 0xfffffbff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_EN) 
    write_field 0x604b4000 8 0xfffffeff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_EN) 
    write_field 0x604b4004 0 0xfffffffe 0x1 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_EN) 
    write_field 0x604b4004 8 0xfffffeff 0x1 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_EN) 
    write_field 0x604b4004 16 0xfffeffff 0x1 # (WIFI_ADC_SW_CTRL.ADC_DATA_EN_OVR_EN) 
    write_field 0x604b4028 0 0xfffffffe 0x1 # (WIFI_RF_RX_SW_CTRL3.CH0_RSSI_OVR_EN) 
    write_field 0x604b4028 8 0xfffffeff 0x1 # (WIFI_RF_RX_SW_CTRL3.CH1_RSSI_OVR_EN) 
    write_field 0x604b4028 4 0xffffffef 0x1 # (WIFI_RF_RX_SW_CTRL3.CH0_RSSI_VALID_OVR_EN) 
    write_field 0x604b4028 12 0xffffefff 0x1 # (WIFI_RF_RX_SW_CTRL3.CH1_RSSI_VALID_OVR_EN) 
    if [ "$SYSTEM_MODE" = "WIFI_CALIB" ] || [ "$SYSTEM_MODE" = "BT_CALIB" ];
    then
        write_field 0x604b4010 2 0xfffffff3 0x3 # (WIFI_SB_COMMON_CTRL.DAC_DATA_VALID_MODE) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4004 1 0xfffffff9 0x3 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4004 9 0xfffff9ff 0x3 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x0 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4000 3 0xfffffff7 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4000 1 0xfffffffd 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4000 11 0xfffff7ff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4000 9 0xfffffdff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    fi
    usleep 3
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b400c 1 0xfffffe01 ${1} # (WIFI_RF_TX_SW_CTRL1.CH0_RF_TX_GAIN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b400c 13 0xffe01fff ${2} # (WIFI_RF_TX_SW_CTRL1.CH1_RF_TX_GAIN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "WIFI_2X2" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4004 1 0xfffffff9 0x3 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4004 9 0xfffff9ff 0x3 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x0 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4000 3 0xfffffff7 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4000 1 0xfffffffd 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    fi
    usleep 3
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4000 11 0xfffff7ff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4000 9 0xfffffdff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    fi
    usleep 2
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b400c 1 0xfffffe01 ${3} # (WIFI_RF_TX_SW_CTRL1.CH0_RF_TX_GAIN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b400c 13 0xffe01fff ${4} # (WIFI_RF_TX_SW_CTRL1.CH1_RF_TX_GAIN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4004 1 0xfffffff9 0x3 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4004 9 0xfffff9ff 0x3 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x0 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 3 0xfffffff7 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 1 0xfffffffd 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 11 0xfffff7ff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 9 0xfffffdff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    fi
    usleep 3
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b400c 1 0xfffffe01 ${5} # (WIFI_RF_TX_SW_CTRL1.CH0_RF_TX_GAIN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b400c 13 0xffe01fff ${6} # (WIFI_RF_TX_SW_CTRL1.CH1_RF_TX_GAIN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ] || [ "$LB_WIFI_MODE" = "LB5" ];
    then
        write_field 0x604b4004 1 0xfffffff9 0x3 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ] || [ "$LB_WIFI_MODE" = "LB5" ];
    then
        write_field 0x604b4000 3 0xfffffff7 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ] || [ "$LB_WIFI_MODE" = "LB5" ];
    then
        write_field 0x604b4000 1 0xfffffffd 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    fi
    usleep 3
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ] || [ "$LB_WIFI_MODE" = "LB5" ];
    then
        write_field 0x604b4000 5 0xffffffdf 0x1 # (WIFI_DAC_SW_CTRL.DAC0_PDN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ];
    then
        write_field 0x604b400c 1 0xfffffe01 ${7} # (WIFI_RF_TX_SW_CTRL1.CH0_RF_TX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB12" ] || [ "$LB_WIFI_MODE" = "LB16" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ] || [ "$LB_WIFI_MODE" = "LB6" ];
    then
        write_field 0x604b4004 9 0xfffff9ff 0x3 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x0 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ] || [ "$LB_WIFI_MODE" = "LB6" ];
    then
        write_field 0x604b4000 11 0xfffff7ff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ] || [ "$LB_WIFI_MODE" = "LB6" ];
    then
        write_field 0x604b4000 9 0xfffffdff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    fi
    usleep 3
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ] || [ "$LB_WIFI_MODE" = "LB6" ];
    then
        write_field 0x604b4000 13 0xffffdfff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_PDN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ];
    then
        write_field 0x604b400c 13 0xffe01fff ${8} # (WIFI_RF_TX_SW_CTRL1.CH1_RF_TX_GAIN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "LB13" ] || [ "$LB_WIFI_MODE" = "LB17" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b401c 9 0xfffffdff 0x0 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 9 0xfffffdff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 13 0xffffdfff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_EXTPAD_TO_RF" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 11 0xfffff7ff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4000 3 0xfffffff7 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 1 0xfffffffd 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4000 11 0xfffff7ff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4000 9 0xfffffdff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH0" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b401c 1 0xfffffffd 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_WIFI_MODE" = "CHX_IQ_TO_EXTPAD" ] || [ "$SYSTEM_MODE" = "WIFI_2X2" ] || [ "$SYSTEM_MODE" = "CH1" ];
    then
        write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    fi
}

#(10w->8w)
function wf_txon2sxlocked()
{
    write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    write_field 0x604b4000 3 0xfffffff7 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    write_field 0x604b4000 11 0xfffff7ff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    write_field 0x604b4000 1 0xfffffffd 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    write_field 0x604b4000 9 0xfffffdff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    write_field 0x604b4008 13 0xffffdfff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    write_field 0x604b401c 1 0xfffffffd 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    write_field 0x604b401c 9 0xfffffdff 0x0 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    write_field 0x604b4004 1 0xfffffff9 0x3 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    write_field 0x604b4004 9 0xfffff9ff 0x3 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    write_field 0x604b4020 1 0xfffffc01 TBD # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_VAL) 
    write_field 0x604b4020 13 0xffc01fff TBD # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_VAL) 
}

#(all->3w)
function wf_reset2wifioff()
{
    write_field 0x604b4008 0 0xfffffffe 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_EN) 
    write_field 0x604b4008 2 0xfffffffb 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_EN) 
    write_field 0x604b4008 4 0xffffffef 0x1 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_EN) 
    write_field 0x604b4008 8 0xfffffeff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_EN) 
    write_field 0x604b4008 10 0xfffffbff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_EN) 
    write_field 0x604b4008 12 0xffffefff 0x1 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_EN) 
    write_field 0x604b400c 0 0xfffffffe 0x1 # (WIFI_RF_TX_SW_CTRL1.CH0_RF_TX_GAIN_OVR_EN) 
    write_field 0x604b400c 12 0xffffefff 0x1 # (WIFI_RF_TX_SW_CTRL1.CH1_RF_TX_GAIN_OVR_EN) 
    write_field 0x604b401c 0 0xfffffffe 0x1 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_EN) 
    write_field 0x604b401c 8 0xfffffeff 0x1 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_EN) 
    write_field 0x604b4020 0 0xfffffffe 0x1 # (WIFI_RF_RX_SW_CTRL1.CH0_RF_RX_GAIN_OVR_EN) 
    write_field 0x604b4020 12 0xffffefff 0x1 # (WIFI_RF_RX_SW_CTRL1.CH1_RF_RX_GAIN_OVR_EN) 
    write_field 0x604b4024 0 0xfffffffe 0x1 # (WIFI_RF_RX_SW_CTRL2.SX0_FRAC_FREQ_SEL_OVR_EN) 
    write_field 0x604b4000 4 0xffffffef 0x1 # (WIFI_DAC_SW_CTRL.DAC0_PDN_OVR_EN) 
    write_field 0x604b4000 2 0xfffffffb 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_EN) 
    write_field 0x604b4000 0 0xfffffffe 0x1 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_EN) 
    write_field 0x604b4000 12 0xffffefff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_PDN_OVR_EN) 
    write_field 0x604b4000 10 0xfffffbff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_EN) 
    write_field 0x604b4000 8 0xfffffeff 0x1 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_EN) 
    write_field 0x604b4004 0 0xfffffffe 0x1 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_EN) 
    write_field 0x604b4004 8 0xfffffeff 0x1 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_EN) 
    write_field 0x604b4004 16 0xfffeffff 0x1 # (WIFI_ADC_SW_CTRL.ADC_DATA_EN_OVR_EN) 
    write_field 0x604b4028 0 0xfffffffe 0x1 # (WIFI_RF_RX_SW_CTRL3.CH0_RSSI_OVR_EN) 
    write_field 0x604b4028 8 0xfffffeff 0x1 # (WIFI_RF_RX_SW_CTRL3.CH1_RSSI_OVR_EN) 
    write_field 0x604b4028 4 0xffffffef 0x1 # (WIFI_RF_RX_SW_CTRL3.CH0_RSSI_VALID_OVR_EN) 
    write_field 0x604b4028 12 0xffffefff 0x1 # (WIFI_RF_RX_SW_CTRL3.CH1_RSSI_VALID_OVR_EN) 
    write_field 0x604b4010 2 0xfffffff3 0x0 # (WIFI_SB_COMMON_CTRL.DAC_DATA_VALID_MODE) 
    write_field 0x604b4010 0 0xfffffffc 0x0 # (WIFI_SB_COMMON_CTRL.ADC_DATA_EN_MODE) 
    write_field 0x604b4008 3 0xfffffff7 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_PA_EN_OVR_VAL) 
    write_field 0x604b4008 11 0xfffff7ff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_PA_EN_OVR_VAL) 
    write_field 0x604b4008 1 0xfffffffd 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TX_EN_OVR_VAL) 
    write_field 0x604b4008 9 0xfffffdff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TX_EN_OVR_VAL) 
    write_field 0x604b401c 1 0xfffffffd 0x0 # (WIFI_RF_RX_SW_CTRL0.CH0_RF_RX_EN_OVR_VAL) 
    write_field 0x604b401c 9 0xfffffdff 0x0 # (WIFI_RF_RX_SW_CTRL0.CH1_RF_RX_EN_OVR_VAL) 
    write_field 0x604b4008 5 0xffffffdf 0x0 # (WIFI_RF_TX_SW_CTRL0.CH0_RF_TR_SW_OVR_VAL) 
    write_field 0x604b4008 13 0xffffdfff 0x0 # (WIFI_RF_TX_SW_CTRL0.CH1_RF_TR_SW_OVR_VAL) 
    write_field 0x604b4980 0 0x0 0x0e000000 # (CH0_GEN_CTRL0.) 
    write_field 0x604b4a00 0 0x0 0x0e000000 # (CH1_GEN_CTRL0.) 
    write_field 0x604b4984 0 0x0 0x00000038 # (CH0_GEN_CTRL1.) 
    write_field 0x604b4a04 0 0x0 0x00000038 # (CH1_GEN_CTRL1.) 
    write_field 0x604b4988 0 0x0 0x00003810 # (CH0_GEN_CTRL2.) 
    write_field 0x604b4a08 0 0x0 0x00003810 # (CH1_GEN_CTRL2.) 
    write_field 0x604b49d4 0 0x0 0x00000000 # (RF_FEM0_PA_CTRL0.) 
    write_field 0x604b4a54 0 0x0 0x00000000 # (RF_FEM1_PA_CTRL0.) 
    write_field 0x604b49b8 0 0x0 0x00000000 # (CH0_ADC_DAC_SPARE.) 
    write_field 0x604b49a4 0 0x0 0x00000000 # (CH0_DAC_CONF.) 
    write_field 0x604b498c 0 0x0 0x00000000 # (CH0_RSSI_CONF.) 
    write_field 0x604b49b0 0 0x0 0x00000000 # (CH0_SPARE_IN.) 
    write_field 0x604b4a38 0 0x0 0x00000000 # (CH1_ADC_DAC_SPARE.) 
    write_field 0x604b4a24 0 0x0 0x00000000 # (CH1_DAC_CONF.) 
    write_field 0x604b4a0c 0 0x0 0x00000000 # (CH1_RSSI_CONF.) 
    write_field 0x604b4a30 0 0x0 0x00000000 # (CH1_SPARE_IN.) 
    write_field 0x604b498c 1 0xfffffffd 0x0 # (CH0_RSSI_CONF.CH0_rssi_en) 
    write_field 0x604b4a0c 1 0xfffffffd 0x0 # (CH1_RSSI_CONF.CH1_rssi_en) 
    write_field 0x604b4004 1 0xfffffff9 0x1 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    write_field 0x604b4004 9 0xfffff9ff 0x1 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    write_field 0x604b4004 1 0xfffffff9 0x0 # (WIFI_ADC_SW_CTRL.ADC0_EN_OVR_VAL) 
    write_field 0x604b4004 9 0xfffff9ff 0x0 # (WIFI_ADC_SW_CTRL.ADC1_EN_OVR_VAL) 
    write_field 0x604b4000 5 0xffffffdf 0x0 # (WIFI_DAC_SW_CTRL.DAC0_PDN_OVR_VAL) 
    write_field 0x604b4000 13 0xffffdfff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_PDN_OVR_VAL) 
    write_field 0x604b4000 3 0xfffffff7 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNI_OVR_VAL) 
    write_field 0x604b4000 1 0xfffffffd 0x0 # (WIFI_DAC_SW_CTRL.DAC0_STANDBYNQ_OVR_VAL) 
    write_field 0x604b4000 11 0xfffff7ff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNI_OVR_VAL) 
    write_field 0x604b4000 9 0xfffffdff 0x0 # (WIFI_DAC_SW_CTRL.DAC1_STANDBYNQ_OVR_VAL) 
    write_field 0x604b4834 0 0xfffffffe 0x0 # (SX0_IN_SPARE0.SX0_lobuff_splitter_drv_CH0_LOX0_en) 
    write_field 0x604b4834 1 0xfffffffd 0x0 # (SX0_IN_SPARE0.SX0_lobuff_splitter_drv_CH0_LOX1_en) 
    write_field 0x604b4834 2 0xfffffffb 0x0 # (SX0_IN_SPARE0.SX0_lobuff_splitter_drv_CH1_LOX0_en) 
    write_field 0x604b4830 20 0xffefffff 0x0 # (SX0_LOGEN_CTRL0.SX0_lobuff_rep_drv_CH0_LOX1_en) 
    write_field 0x604b4830 19 0xfff7ffff 0x0 # (SX0_LOGEN_CTRL0.SX0_lobuff_rep_drv_CH0_LOX0_en) 
    write_field 0x604b48b4 0 0xfffffffe 0x0 # (SX1_IN_SPARE0.SX1_lobuff_splitter_drv_CH1_LOX0_en) 
    write_field 0x604b48b4 1 0xfffffffd 0x0 # (SX1_IN_SPARE0.SX1_lobuff_splitter_drv_CH1_LOX1_en) 
    write_field 0x604b48b4 2 0xfffffffb 0x0 # (SX1_IN_SPARE0.SX1_lobuff_splitter_drv_CH0_LOX1_en) 
    write_field 0x604b48b0 20 0xffefffff 0x0 # (SX1_LOGEN_CTRL0.SX1_lobuff_rep_drv_CH1_LOX1_en) 
    write_field 0x604b48b0 19 0xfff7ffff 0x0 # (SX1_LOGEN_CTRL0.SX1_lobuff_rep_drv_CH1_LOX0_en) 
    write_field 0x604b4830 0 0xfffffffe 0x0 # (SX0_LOGEN_CTRL0.SX0_logen_buff_en) 
    write_field 0x604b4830 17 0xfffdffff 0x0 # (SX0_LOGEN_CTRL0.SX0_logen_mx_en) 
    write_field 0x604b4830 3 0xfffffff7 0x0 # (SX0_LOGEN_CTRL0.SX0_logen_div2_drv_en) 
    write_field 0x604b4830 18 0xfffbffff 0x0 # (SX0_LOGEN_CTRL0.SX0_losync_en) 
    write_field 0x604b49a0 14 0xffffbfff 0x0 # (CH0_ADC_CONF.CH0_adc_caln) 
    write_field 0x604b4a20 14 0xffffbfff 0x0 # (CH1_ADC_CONF.CH1_adc_caln) 
    write_field 0x604b4830 4 0xffffffef 0x0 # (SX0_LOGEN_CTRL0.SX0_logen_ldo_en) 
    write_field 0x604b4830 21 0xffdfffff 0x0 # (SX0_LOGEN_CTRL0.SX0_lobuff_ldo_en) 
    write_field 0x604b4830 26 0xfbffffff 0x0 # (SX0_LOGEN_CTRL0.SX0_losync_ldo_en) 
    write_field 0x604b4980 8 0xfffffeff 0x0 # (CH0_GEN_CTRL0.CH0_bb_bias_en) 
    write_field 0x604b4a00 8 0xfffffeff 0x0 # (CH1_GEN_CTRL0.CH1_bb_bias_en) 
    write_field 0x604b49a0 13 0xffffdfff 0x0 # (CH0_ADC_CONF.CH0_adc_ldo_en) 
    write_field 0x604b4a20 13 0xffffdfff 0x0 # (CH1_ADC_CONF.CH1_adc_ldo_en) 
    write_field 0x604b4984 8 0xfffffeff 0x0 # (CH0_GEN_CTRL1.CH0_dac_ldo_en) 
    write_field 0x604b4a04 8 0xfffffeff 0x0 # (CH1_GEN_CTRL1.CH1_dac_ldo_en) 
    write_field 0x604b4984 21 0xffdfffff 0x0 # (CH0_GEN_CTRL1.CH0_localdiv_ldo_en) 
    write_field 0x604b4a04 21 0xffdfffff 0x0 # (CH1_GEN_CTRL1.CH1_localdiv_ldo_en) 
    write_field 0x604b4988 9 0xfffffdff 0x0 # (CH0_GEN_CTRL2.CH0_bb_en) 
    write_field 0x604b4a08 9 0xfffffdff 0x0 # (CH1_GEN_CTRL2.CH1_bb_en) 
    write_field 0x604b49bc 23 0xff7fffff 0x0 # (RF_FEM0_LNA_CTRL0.CH0_rx_lna_st1_ldo10_en) 
    write_field 0x604b49bc 24 0xfeffffff 0x0 # (RF_FEM0_LNA_CTRL0.CH0_rx_lna_st1_ldo14_en) 
    write_field 0x604b49d8 19 0xfff7ffff 0x0 # (RF_FEM0_LNA_ST2_CTRL0.CH0_rx_lna_st2_ldo10_en) 
    write_field 0x604b49d8 20 0xffefffff 0x0 # (RF_FEM0_LNA_ST2_CTRL0.CH0_rx_lna_st2_ldo14_en) 
    write_field 0x604b4a3c 23 0xff7fffff 0x0 # (RF_FEM1_LNA_CTRL0.CH1_rx_lna_st1_ldo10_en) 
    write_field 0x604b4a3c 24 0xfeffffff 0x0 # (RF_FEM1_LNA_CTRL0.CH1_rx_lna_st1_ldo14_en) 
    write_field 0x604b4a58 19 0xfff7ffff 0x0 # (RF_FEM1_LNA_ST2_CTRL0.CH1_rx_lna_st2_ldo10_en) 
    write_field 0x604b4a58 20 0xffefffff 0x0 # (RF_FEM1_LNA_ST2_CTRL0.CH1_rx_lna_st2_ldo14_en) 
    write_field 0x604b4988 10 0xfffffbff 0x0 # (CH0_GEN_CTRL2.CH0_pdet_ldo_en) 
    write_field 0x604b4a08 10 0xfffffbff 0x0 # (CH1_GEN_CTRL2.CH1_pdet_ldo_en) 
}
