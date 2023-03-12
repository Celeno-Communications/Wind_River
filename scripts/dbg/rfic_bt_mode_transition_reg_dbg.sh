


#(4b->5b)
function btstandby2bt_idle()
{
    write_field 0x604b48b0 4 0xffffffef 0x1 # (SX1_LOGEN_CTRL0.SX1_logen_ldo_en) 
    write_field 0x604b48b0 21 0xffdfffff 0x1 # (SX1_LOGEN_CTRL0.SX1_lobuff_ldo_en) 
    usleep 1
    write_field 0x604b4a80 8 0xfffffeff 0x1 # (BT_BBIQ.BT_bb_bias_en) 
    write_field 0x604b4ad4 14 0xffffbfff 0x1 # (BT_ADC_STATIC_CONF.BT_adc_bias_en) 
    write_field 0x604b4ad8 4 0xffffffef 0x1 # (BT_DAC_STATIC_CONF.BT_dac_bias_en) 
    usleep 1
    write_field 0x604b4ad4 23 0xff7fffff 0x1 # (BT_ADC_STATIC_CONF.BT_adc_ldo_en) 
    write_field 0x604b4ad8 6 0xffffffbf 0x1 # (BT_DAC_STATIC_CONF.BT_dac_ldo_en) 
    write_field 0x604b4a98 12 0xffffefff 0x1 # (BT_LOGEN_CONF.BT_localdiv_ldo_en) 
    usleep 2
    write_field 0x604b4a88 27 0xf7ffffff 0x1 # (BT_BB_STATIC_CTRL_1.BT_bb_filter_en) 
    usleep 10
    write_field 0x604b4af0 23 0xff7fffff 0x1 # (RF_FEM_BT_LNA_CTRL0.BT_rx_lna_ldo10_en) 
    write_field 0x604b4af0 24 0xfeffffff 0x1 # (RF_FEM_BT_LNA_CTRL0.BT_rx_lna_ldo14_en) 
    write_field 0x604b4a8c 16 0xfffeffff 0x1 # (BT_BB_STATIC_CTRL_2.BT_pdet_ldo_en) 
    write_field 0x604b4b40 26 0xfbffffff 0x1 # (AUX_ADC_CTRL0.ADC_aux_ldo_en) 
    usleep 1
    write_field 0x604b4898 0 0xfffffffe 0x0 # (SX1_FSM_CTRL0.SX1_fsm_rstn) 
    write_field 0x604b4898 0 0xfffffffe 0x1 # (SX1_FSM_CTRL0.SX1_fsm_rstn) 
    write_field 0x604b4880 25 0xfdffffff 0x1 # (SX1_PLL_CTRL0.SX1_fsm_en) 
    write_field 0x604b489c 9 0xfffffdff 0x1 # (SX1_FSM_CTRL1.SX1_fsm_power_on_seq_start) 
}

#(5b->6b)
function bt_idle2bt_chainconfig()
{
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
    write_field 0x604b4ad4 25 0xfdffffff 0x1 # (BT_ADC_STATIC_CONF.BT_aux_adc_clk_buf_en) 
    write_field 0x604b4b40 13 0xffffdfff 0x1 # (AUX_ADC_CTRL0.adc_AUX_en) 
    write_field 0x604b4118 13 0xffff9fff 0x0 # (BT_RF_COMMON_SW_CTRL.FILTER_BW_OVR_VAL) 
    write_field 0x604b4104 1 0xfffffffd 0x1 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    write_field 0x604b4ad8 7 0xffffff7f 0x0 # (BT_DAC_STATIC_CONF.dac_BT_rstn) 
    write_field 0x604b4ad8 7 0xffffff7f 0x1 # (BT_DAC_STATIC_CONF.dac_BT_rstn) 
    write_field 0x604b4ab0 3 0xfffffff7 0x0 # (BT_DAC_FSM_CTRL0.BT_dac_comp_offset_cal_fsm_rstn) 
    write_field 0x604b4ab0 27 0xf7ffffff 0x0 # (BT_DAC_FSM_CTRL0.BT_dac_cur_mismatch_cal_fsm_rstn) 
    write_field 0x604b4ab0 3 0xfffffff7 0x1 # (BT_DAC_FSM_CTRL0.BT_dac_comp_offset_cal_fsm_rstn) 
    write_field 0x604b4ab0 27 0xf7ffffff 0x1 # (BT_DAC_FSM_CTRL0.BT_dac_cur_mismatch_cal_fsm_rstn) 
    write_field 0x604b4ab0 0 0xfffffffe 0x0 # (BT_DAC_FSM_CTRL0.BT_dac_comp_offset_cal_bypass) 
    write_field 0x604b4ab0 24 0xfeffffff 0x0 # (BT_DAC_FSM_CTRL0.BT_dac_cur_mismatch_cal_bypass) 
    write_field 0x604b4ab0 2 0xfffffffb 0x1 # (BT_DAC_FSM_CTRL0.BT_dac_comp_offset_cal_fsm_en) 
    write_field 0x604b4ab0 26 0xfbffffff 0x1 # (BT_DAC_FSM_CTRL0.BT_dac_cur_mismatch_cal_fsm_en) 
    write_field 0x604b4100 1 0xfffffffd 0x1 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    write_field 0x604b4ad4 24 0xfeffffff 0x0 # (BT_ADC_STATIC_CONF.BT_adc_rstn) 
    write_field 0x604b4aac 3 0xfffffff7 0x0 # (BT_ADC_FSM.BT_adc_comp_offset_cal_fsm_rstn) 
    write_field 0x604b4ad4 24 0xfeffffff 0x1 # (BT_ADC_STATIC_CONF.BT_adc_rstn) 
    write_field 0x604b4ad4 2 0xfffffffb 0x1 # (BT_ADC_STATIC_CONF.BT_adc_df) 
    write_field 0x604b4aac 3 0xfffffff7 0x1 # (BT_ADC_FSM.BT_adc_comp_offset_cal_fsm_rstn) 
    write_field 0x604b4aac 2 0xfffffffb 0x1 # (BT_ADC_FSM.BT_adc_comp_offset_cal_fsm_en) 
    write_field 0x604b4aac 1 0xfffffffd 0x1 # (BT_ADC_FSM.BT_adc_comp_offset_cal_start) 
    write_field 0x604b4b40 13 0xffffdfff 0x1 # (AUX_ADC_CTRL0.adc_AUX_en) 
    write_field 0x604b4b40 27 0xf7ffffff 0x0 # (AUX_ADC_CTRL0.adc_AUX_rstn) 
    write_field 0x604b4b40 21 0xffdfffff 0x0 # (AUX_ADC_CTRL0.AUX_ADC_comp_offset_cal_fsm_rstn) 
    write_field 0x604b4b40 2 0xfffffffb 0x1 # (AUX_ADC_CTRL0.adc_AUX_DF) 
    write_field 0x604b4b40 27 0xf7ffffff 0x1 # (AUX_ADC_CTRL0.adc_AUX_rstn) 
    write_field 0x604b4b40 21 0xffdfffff 0x1 # (AUX_ADC_CTRL0.AUX_ADC_comp_offset_cal_fsm_rstn) 
    write_field 0x604b4b40 20 0xffefffff 0x1 # (AUX_ADC_CTRL0.AUX_ADC_comp_offset_cal_fsm_en) 
    write_field 0x604b4b40 19 0xfff7ffff 0x1 # (AUX_ADC_CTRL0.AUX_ADC_comp_offset_cal_start) 
    write_field 0x604b4ab0 1 0xfffffffd 0x1 # (BT_DAC_FSM_CTRL0.BT_dac_comp_offset_cal_start) 
    write_field 0x604b4ab0 25 0xfdffffff 0x1 # (BT_DAC_FSM_CTRL0.BT_dac_cur_mismatch_cal_start) 
    write_field 0x604b4100 1 0xfffffffd 0x0 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    write_field 0x604b4104 1 0xfffffffd 0x0 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    write_field 0x604b4880 27 0xe7ffffff 0x2 # (SX1_PLL_CTRL0.SX1_sdm_out_high_limit_sel) 
    write_field 0x604b4880 29 0x9fffffff 0x1 # (SX1_PLL_CTRL0.SX1_sdm_out_low_limit_sel) 
    write_field 0x604b4898 8 0xfffffcff 0x0 # (SX1_FSM_CTRL0.SX1_fsm_lockdet_acc) 
    write_field 0x604b4898 8 0xfffffcff 0x1 # (SX1_FSM_CTRL0.SX1_fsm_lockdet_acc) 
    write_field 0x604b4898 28 0xfffffff 0xA # (SX1_FSM_CTRL0.SX1_fsm_freq_meas_dur) 
    write_field 0x604b489c 19 0xffe7ffff 0x1 # (SX1_FSM_CTRL1.SX1_fsm_ampl_update_per) 
    write_field 0x604b489c 0 0xfffffff8 0x1 # (SX1_FSM_CTRL1.SX1_fsm_kvco_meas_wait_time) 
    write_field 0x604b489c 7 0xffffff7f 0x1 # (SX1_FSM_CTRL1.SX1_fsm_lock_det_en) 
    write_field 0x604b4888 6 0xfffffe3f 0x5 # (SX1_PLL_CTRL2.SX1_lpf_sell) 
    write_field 0x604b488c 30 0xbfffffff 0x1 # (SX1_PLL_CTRL3.SX1_freq_cfg_sel) 
    write_field 0x604b488c 30 0xbfffffff 0x0 # (SX1_PLL_CTRL3.SX1_freq_cfg_sel) 
    write_field 0x604b488c 0 0xffffff00 nan # (SX1_PLL_CTRL3.SX1_div_int) 
    write_field 0x604b488c 8 0xe00000ff nan # (SX1_PLL_CTRL3.SX1_div_nfrac) 
    write_field 0x604b4898 10 0xf00003ff nan # (SX1_FSM_CTRL0.SX1_fsm_freq_meas_trgt) 
    write_field 0x604b489c 4 0xffffffef nan # (SX1_FSM_CTRL1.SX1_fsm_cal_en) 
    write_field 0x604b48b0 0 0xfffffffe 0x1 # (SX1_LOGEN_CTRL0.SX1_logen_buff_en) 
    write_field 0x604b48b0 3 0xfffffff7 0x1 # (SX1_LOGEN_CTRL0.SX1_logen_div2_drv_en) 
    write_field 0x604b48b0 17 0xfffdffff 0x1 # (SX1_LOGEN_CTRL0.SX1_logen_mx_en) 
    write_field 0x604b48b4 0 0xfffffffe 0x0 # (SX1_IN_SPARE0.SX1_lobuff_splitter_drv_ch1_LOX0_en) 
    write_field 0x604b48b4 1 0xfffffffd 0x0 # (SX1_IN_SPARE0.SX1_lobuff_splitter_drv_ch1_LOX1_en) 
    write_field 0x604b48b4 2 0xfffffffb 0x1 # (SX1_IN_SPARE0.SX1_lobuff_splitter_drv_ch0_LOX1_en) 
    write_field 0x604b48b0 20 0xffefffff 0x0 # (SX1_LOGEN_CTRL0.SX1_lobuff_rep_drv_ch1_LOX1_en) 
    write_field 0x604b48b0 19 0xfff7ffff 0x0 # (SX1_LOGEN_CTRL0.SX1_lobuff_rep_drv_ch1_LOX0_en) 
    write_field 0x604b4a94 0 0xfffffffe 0x0 # (BT_SPARE.BT_rssi_rstn) 
    write_field 0x604b4a94 0 0xfffffffe 0x1 # (BT_SPARE.BT_rssi_rstn) 
    write_field 0x604b4a9c 1 0xfffffffd 0x1 # (BT_RSSI_CONF.BT_rssi_en) 
    if [ "$LB_BT_MODE" = "NOLB" ] || [ "$LB_BT_MODE" = "LB7" ] || [ "$LB_BT_MODE" = "LB8" ] || [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD" ] || [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD_OBS" ] || [ "$LB_BT_MODE" = "BT_EXTPAD_TO_RF" ];
    then
        write_field 0x604b4a90 11 0xfffff7ff 0x1 # (BT_CHANNEL_CONF.BT_trsw_en) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ] || [ "$LB_BT_MODE" = "LB15" ] || [ "$LB_BT_MODE" = "BT_IQ_TO_EXTPAD" ] || [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ] || [ "$LB_BT_MODE" = "BT_EXTPAD_TO_IQ" ] || [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4a90 11 0xfffff7ff 0x0 # (BT_CHANNEL_CONF.BT_trsw_en) 
    fi
    write_field 0x604b4a98 9 0xfffffdff 0x1 # (BT_LOGEN_CONF.BT_localdiv_divbuffen) 
    if [ "$LB_BT_MODE" = "BT_IQ_TO_EXTPAD" ] || [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ] || [ "$LB_BT_MODE" = "BT_EXTPAD_TO_IQ" ] || [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4a98 9 0xfffffdff 0x0 # (BT_LOGEN_CONF.BT_localdiv_divbuffen) 
    fi
    write_field 0x604b4a98 13 0xffffdfff 0x1 # (BT_LOGEN_CONF.BT_localdiv_sxsel) 
    write_field 0x604b4a84 10 0xfffffbff 0x0 # (BT_BB_STATIC_CONF.BT_localdiv_rstn) 
    write_field 0x604b4a84 10 0xfffffbff 0x1 # (BT_BB_STATIC_CONF.BT_localdiv_rstn) 
    write_field 0x604b4a94 2 0xffffff83 0x0 # (BT_SPARE.BT_lpf_gain_index_offset) 
    write_field 0x604b4a94 7 0xfffff87f 0xA # (BT_SPARE.BT_lpf_tx_mode_gain) 
    write_field 0x604b4a94 11 0xffffe7ff 0x2 # (BT_SPARE.BT_lpf_tx_mode_gain_sel) 
    write_field 0x604b4a80 0 0xfffffffc 0x2 # (BT_BBIQ.BT_bb_gainconf) 
    write_field 0x604b4a94 1 0xfffffffd 0x1 # (BT_SPARE.BT_tx_pa_res_ladder_en) 
    write_field 0x604b4afc 6 0xfffff83f 0x08 # (RF_FEM_BT_PA_2P5G_CTRL0.BT_tx_pa_vg2_ctrl) 
    write_field 0x604b4afc 11 0xffff07ff 0x10 # (RF_FEM_BT_PA_2P5G_CTRL0.BT_tx_pa_vg3_ctrl) 
    write_field 0x604b4afc 22 0xf83fffff 0x14 # (RF_FEM_BT_PA_2P5G_CTRL0.BT_tx_pa_vg2_ctrl_pd) 
    write_field 0x604b4afc 27 0x7ffffff 0x0A # (RF_FEM_BT_PA_2P5G_CTRL0.BT_tx_pa_vg3_ctrl_pd) 
    write_field 0x604b4aa8 14 0xffff3fff 0x2 # (BT_TX_CTRL2.BT_pdet_gain) 
    write_field 0x604b4aa8 7 0xffffff7f 0x1 # (BT_TX_CTRL2.BT_pdet_en) 
    write_field 0x604b4b40 14 0xfffc3fff 0x4 # (AUX_ADC_CTRL0.adc_AUX_input_sel) 
    write_field 0x604b4a90 10 0xfffffbff 0x1 # (BT_CHANNEL_CONF.BT_tempsens_en) 
    write_field 0x604b4c18 0 0xffffffc0 0x27 # (BT_ATB_CTRL.BT_atb_sel) 
    write_field 0x604b4c20 7 0xfffff87f 0x8 # (DPLL_TEST.atb_en_address) 
    write_field 0x604b4b40 14 0xfffc3fff 0x1 # (AUX_ADC_CTRL0.adc_AUX_input_sel) 
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4a84 15 0xfffe7fff 0x1 # (BT_BB_STATIC_CONF.BT_bb_extio_ctrl) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4a84 15 0xfffe7fff 0x1 # (BT_BB_STATIC_CONF.BT_bb_extio_ctrl) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_RF" ];
    then
        write_field 0x604b4a84 15 0xfffe7fff 0x2 # (BT_BB_STATIC_CONF.BT_bb_extio_ctrl) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_EXTPAD" ];
    then
        write_field 0x604b4a84 15 0xfffe7fff 0x2 # (BT_BB_STATIC_CONF.BT_bb_extio_ctrl) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4a84 15 0xfffe7fff 0x1 # (BT_BB_STATIC_CONF.BT_bb_extio_ctrl) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4ad4 13 0xffffdfff 0x1 # (BT_ADC_STATIC_CONF.BT_adc_lpbk_en) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4ad8 8 0xfffffeff 0x1 # (BT_DAC_STATIC_CONF.BT_DAC_lpbk_en) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4a80 0 0xfffffffc 0x2 # (BT_BBIQ.BT_bb_gainconf) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_IQ" ];
    then
        write_field 0x604b4a84 15 0xfffe7fff 0x1 # (BT_BB_STATIC_CONF.BT_bb_extio_ctrl) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4a84 15 0xfffe7fff 0x2 # (BT_BB_STATIC_CONF.BT_bb_extio_ctrl) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4ad4 13 0xffffdfff 0x1 # (BT_ADC_STATIC_CONF.BT_adc_lpbk_en) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4ad8 8 0xfffffeff 0x1 # (BT_DAC_STATIC_CONF.BT_DAC_lpbk_en) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4a80 0 0xfffffffc 0x2 # (BT_BBIQ.BT_bb_gainconf) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4100 0 0xfffffffe 0x0 # (BT_ADC_SW_CTRL.ADC_EN_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4100 2 0xfffffffb 0x0 # (BT_ADC_SW_CTRL.ADC_RESET_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4104 0 0xfffffffe 0x0 # (BT_DAC_SW_CTRL.DAC_EN_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4108 0 0xfffffffe 0x0 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4108 2 0xfffffffb 0x0 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4108 4 0xffffffef 0x0 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b410c 0 0xfffffffe 0x0 # (BT_RF_TX_SW_CTRL1.TX_POWER_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4110 0 0xfffffffe 0x0 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4114 0 0xfffffffe 0x0 # (BT_RF_RX_SW_CTRL1.LNA_GAIN_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4114 4 0xffffffef 0x0 # (BT_RF_RX_SW_CTRL1.LPF1_GAIN_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4114 8 0xfffffeff 0x0 # (BT_RF_RX_SW_CTRL1.LPF2_GAIN_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4114 16 0xfffeffff 0x0 # (BT_RF_RX_SW_CTRL1.LNA_SAT_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4118 0 0xfffffffe 0x0 # (BT_RF_COMMON_SW_CTRL.CHANNEL_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4118 8 0xfffffeff 0x0 # (BT_RF_COMMON_SW_CTRL.MOD_SEL_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4118 12 0xffffefff 0x0 # (BT_RF_COMMON_SW_CTRL.FILTER_BW_OVR_EN) 
    fi
    if [ "$CALIB_MODE" = "NO_CALIB" ];
    then
        write_field 0x604b4118 16 0xfffeffff 0x0 # (BT_RF_COMMON_SW_CTRL.CAL_PULSE_OVR_EN) 
    fi
}

#(6b->8b)
function bt_chaincgf2sx1locked()
{
    write_field 0x604b4100 0 0xfffffffe 0x1 # (BT_ADC_SW_CTRL.ADC_EN_OVR_EN) 
    write_field 0x604b4100 2 0xfffffffb 0x1 # (BT_ADC_SW_CTRL.ADC_RESET_OVR_EN) 
    write_field 0x604b4104 0 0xfffffffe 0x1 # (BT_DAC_SW_CTRL.DAC_EN_OVR_EN) 
    write_field 0x604b4108 0 0xfffffffe 0x1 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_EN) 
    write_field 0x604b4108 2 0xfffffffb 0x1 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_EN) 
    write_field 0x604b4108 4 0xffffffef 0x1 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_EN) 
    write_field 0x604b410c 0 0xfffffffe 0x1 # (BT_RF_TX_SW_CTRL1.TX_POWER_OVR_EN) 
    write_field 0x604b4110 0 0xfffffffe 0x1 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_EN) 
    write_field 0x604b4114 0 0xfffffffe 0x1 # (BT_RF_RX_SW_CTRL1.LNA_GAIN_OVR_EN) 
    write_field 0x604b4114 4 0xffffffef 0x1 # (BT_RF_RX_SW_CTRL1.LPF1_GAIN_OVR_EN) 
    write_field 0x604b4114 8 0xfffffeff 0x1 # (BT_RF_RX_SW_CTRL1.LPF2_GAIN_OVR_EN) 
    write_field 0x604b4114 16 0xfffeffff 0x1 # (BT_RF_RX_SW_CTRL1.LNA_SAT_OVR_EN) 
    write_field 0x604b4118 0 0xfffffffe 0x1 # (BT_RF_COMMON_SW_CTRL.CHANNEL_OVR_EN) 
    write_field 0x604b4118 8 0xfffffeff 0x1 # (BT_RF_COMMON_SW_CTRL.MOD_SEL_OVR_EN) 
    write_field 0x604b4118 12 0xffffefff 0x1 # (BT_RF_COMMON_SW_CTRL.FILTER_BW_OVR_EN) 
    write_field 0x604b4118 16 0xfffeffff 0x1 # (BT_RF_COMMON_SW_CTRL.CAL_PULSE_OVR_EN) 
    if [ "$BT_SYS_MODE" = "BT_CALIB" ];
    then
        write_field 0x604b4118 1 0xffffff01 ${1} # (BT_RF_COMMON_SW_CTRL.CHANNEL_OVR_VAL) 
    fi
    if [ "$BT_SYS_MODE" = "BT_CALIB" ];
    then
        write_field 0x604b4118 9 0xfffff1ff ${2} # (BT_RF_COMMON_SW_CTRL.MOD_SEL_OVR_VAL) 
    fi
    if [ "$BT_SYS_MODE" = "BT_CALIB" ];
    then
        write_field 0x604b4118 13 0xffff9fff ${3} # (BT_RF_COMMON_SW_CTRL.FILTER_BW_OVR_VAL) 
    fi
    if [ "$BT_SYS_MODE" = "BT_CALIB" ];
then        write_field 0x604b4180 0 0x0 0x700 # (IQDC_TX_CONTROL.) 
    fi
    if [ "$BT_SYS_MODE" = "BT_CALIB" ];
then        write_field 0x604b41b4 0 0x0 0x700 # (IQDC_RX_CONTROL.) 
    fi
    if [ "$LB_BT_MODE" = "LB3" ];
    then
        write_field 0x604b4040 1 0xfffffff9 0x2 # (lb_cfg.WIFI_ADC1_LB_SEL) 
    fi
    if [ "$LB_BT_MODE" = "LB3" ];
    then
        write_field 0x604b4040 3 0xfffffff7 0x1 # (lb_cfg.BT_TX_LB_SEL) 
    fi
    if [ "$LB_BT_MODE" = "LB4" ];
    then
        write_field 0x604b4040 4 0xffffffef 0x1 # (lb_cfg.BT_RX_LB_SEL) 
    fi
    if [ "$LB_BT_MODE" = "LB4" ];
    then
        write_field 0x604b4040 1 0xfffffff9 0x3 # (lb_cfg.WIFI_ADC1_LB_SEL) 
    fi
    if [ "$LB_BT_MODE" = "LB7" ];
    then
        write_field 0x604b4ad8 5 0xffffffdf 0x1 # (BT_DAC_STATIC_CONF.bt_dac_en) 
    fi
    if [ "$LB_BT_MODE" = "LB7" ];
    then
        write_field 0x604b4a0c 14 0xffffbfff 0x1 # (CH1_RSSI_CONF.CH1_adc_lpbk_en) 
    fi
    if [ "$LB_BT_MODE" = "LB7" ];
    then
        write_field 0x604b4ad8 8 0xfffffeff 0x1 # (BT_DAC_STATIC_CONF.bt_dac_lpbk_en) 
    fi
    if [ "$LB_BT_MODE" = "LB8" ];
    then
        write_field 0x604b4ad4 15 0xffff7fff 0x1 # (BT_ADC_STATIC_CONF.BT_adc_divider_en) 
    fi
    if [ "$LB_BT_MODE" = "LB8" ];
    then
        write_field 0x604b4ad4 22 0xffbfffff 0x1 # (BT_ADC_STATIC_CONF.BT_adc_en) 
    fi
    if [ "$LB_BT_MODE" = "LB8" ];
    then
        write_field 0x604b49a4 3 0xfffffff7 0x1 # (CH0_DAC_CONF.CH0_dac_lpbk_en) 
    fi
    if [ "$LB_BT_MODE" = "LB8" ];
    then
        write_field 0x604b4ad4 13 0xffffdfff 0x1 # (BT_ADC_STATIC_CONF.BT_adc_lpbk_en) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ];
    then
        write_field 0x604b4af4 29 0xdfffffff 0x0 # (RF_FEM_BT_LNA_CTRL1.BT_loopbk_phase_shifter_ctrl) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ];
    then
        write_field 0x604b4af4 25 0xe1ffffff 0x0 # (RF_FEM_BT_LNA_CTRL1.BT_loopbk_atten_ctrl) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ];
    then
        write_field 0x604b4af8 12 0xffffefff 0x1 # (RF_FEM_BT_PA_CTRL0.BT_tx_loopbk_sw_en) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ];
    then
        write_field 0x604b4af8 11 0xfffff7ff 0x0 # (RF_FEM_BT_PA_CTRL0.BT_rx_loopbk_sw_en) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ];
    then
        write_field 0x604b4af8 12 0xffffefff 0x0 # (RF_FEM_BT_PA_CTRL0.BT_tx_loopbk_sw_en) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ];
    then
        write_field 0x604b4af8 11 0xfffff7ff 0x1 # (RF_FEM_BT_PA_CTRL0.BT_rx_loopbk_sw_en) 
    fi
    if [ "$LB_BT_MODE" = "LB18" ];
    then
        write_field 0x604b4040 1 0xfffffff9 0x2 # (lb_cfg.WIFI_ADC1_LB_SEL) 
    fi
    if [ "$LB_BT_MODE" = "LB19" ];
    then
        write_field 0x604b4040 4 0xffffffef 0x1 # (lb_cfg.BT_RX_LB_SEL) 
    fi
}

#(8b->10b)
function bt_sx1locked2txon()
{
    if [ "$LB_BT_MODE" = "LB14" ] || [ "$LB_BT_MODE" = "LB7" ];
    then
        write_field 0x604b411c 2 0xfffffff3 0x3 # (BT_SYNC_BUFF_CTRL.DAC_DATA_VALID_MODE) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ] || [ "$LB_BT_MODE" = "LB8" ];
    then
        write_field 0x604b411c 2 0xfffffff3 0x2 # (BT_SYNC_BUFF_CTRL.DAC_DATA_VALID_MODE) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b411c 2 0xfffffff3 0x2 # (BT_SYNC_BUFF_CTRL.DAC_DATA_VALID_MODE) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ] || [ "$LB_BT_MODE" = "LB7" ];
    then
        write_field 0x604b4040 3 0xfffffff7 0x1 # (LB_CFG.BT_TX_LB_SEL) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ] || [ "$LB_BT_MODE" = "LB7" ];
    then
        write_field 0x604b4040 1 0xfffffff9 0x0 # (LB_CFG.WIFI_ADC1_LB_SEL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4100 1 0xfffffffd 0x0 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    fi
    usleep 3
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4110 1 0xfffffffd 0x0 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4108 5 0xffffffdf 0x1 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4108 1 0xfffffffd 0x1 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4104 1 0xfffffffd 0x1 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4108 3 0xfffffff7 0x1 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b410c 1 0xfffffe01 ${1} # (BT_RF_TX_SW_CTRL1.TX_POWER_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ] || [ "$LB_BT_MODE" = "LB7" ];
    then
        write_field 0x604b4100 1 0xfffffffd 0x0 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    fi
    usleep 3
    if [ "$LB_BT_MODE" = "LB14" ];
    then
        write_field 0x604b4110 1 0xfffffffd 0x0 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ];
    then
        write_field 0x604b4108 5 0xffffffdf 0x1 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ];
    then
        write_field 0x604b4108 1 0xfffffffd 0x1 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ] || [ "$LB_BT_MODE" = "LB7" ];
    then
        write_field 0x604b4104 1 0xfffffffd 0x1 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ];
    then
        write_field 0x604b4108 3 0xfffffff7 0x0 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ];
    then
        write_field 0x604b410c 1 0xfffffe01 ${2} # (BT_RF_TX_SW_CTRL1.TX_POWER_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_RF" ];
    then
        write_field 0x604b4104 1 0xfffffffd 0x0 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_RF" ];
    then
        write_field 0x604b4100 1 0xfffffffd 0x0 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_RF" ];
    then
        write_field 0x604b4110 1 0xfffffffd 0x0 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_RF" ];
    then
        write_field 0x604b4108 1 0xfffffffd 0x1 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_RF" ];
    then
        write_field 0x604b4108 5 0xffffffdf 0x1 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_RF" ];
    then
        write_field 0x604b4108 3 0xfffffff7 0x1 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_RF" ];
    then
        write_field 0x604b410c 1 0xfffffe01 ${3} # (BT_RF_TX_SW_CTRL1.TX_POWER_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_EXTPAD" ];
    then
        write_field 0x604b4104 1 0xfffffffd 0x1 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_EXTPAD" ];
    then
        write_field 0x604b4100 1 0xfffffffd 0x0 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_EXTPAD" ];
    then
        write_field 0x604b4110 1 0xfffffffd 0x0 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_EXTPAD" ];
    then
        write_field 0x604b4108 1 0xfffffffd 0x0 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_EXTPAD" ];
    then
        write_field 0x604b4108 5 0xffffffdf 0x0 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_EXTPAD" ];
    then
        write_field 0x604b4108 3 0xfffffff7 0x0 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_EXTPAD" ];
    then
        write_field 0x604b410c 1 0xfffffe01 ${4} # (BT_RF_TX_SW_CTRL1.TX_POWER_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4104 1 0xfffffffd 0x1 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4100 1 0xfffffffd 0x0 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4110 1 0xfffffffd 0x0 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4108 1 0xfffffffd 0x1 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4108 5 0xffffffdf 0x1 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b4108 3 0xfffffff7 0x1 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_IQ_TO_LPF_TO_EXTPAD" ];
    then
        write_field 0x604b410c 1 0xfffffe01 ${5} # (BT_RF_TX_SW_CTRL1.TX_POWER_OVR_VAL) 
    fi
    if [ "$BT_SYS_MODE" = "BT_CALIB" ];
    then
        write_field 0x604b4118 16 0xfffeffff 0x1 # (BT_RF_COMMON_SW_CTRL.CAL_PULSE_OVR_EN) 
    fi
    if [ "$BT_SYS_MODE" = "BT_CALIB" ];
    then
        write_field 0x604b4118 16 0xfffeffff 0x0 # (BT_RF_COMMON_SW_CTRL.CAL_PULSE_OVR_EN) 
    fi
}

#(10b->6b)
function bt_txon2chainconfig()
{
    write_field 0x604b4100 1 0xfffffffd 0x0 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    write_field 0x604b4110 1 0xfffffffd 0x0 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    write_field 0x604b4108 5 0xffffffdf 0x0 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    write_field 0x604b4108 0 0xfffffffe 0x0 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_EN) 
    write_field 0x604b4104 1 0xfffffffd 0x0 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    write_field 0x604b4108 3 0xfffffff7 0x0 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    write_field 0x604b410c 1 0xfffffe01 TBD # (BT_RF_TX_SW_CTRL1.TX_POWER_OVR_VAL) 
}

#(8b->9b)
function bt_sx1locked2rxon()
{
    if [ "$LB_BT_MODE" = "LB15" ] || [ "$LB_BT_MODE" = "LB8" ];
    then
        write_field 0x604b411c 0 0xfffffffc 0x3 # (BT_SYNC_BUFF_CTRL.ADC_DATA_EN_MODE) 
    fi
    if [ "$LB_BT_MODE" = "LB14" ] || [ "$LB_BT_MODE" = "LB7" ];
    then
        write_field 0x604b411c 0 0xfffffffc 0x2 # (BT_SYNC_BUFF_CTRL.ADC_DATA_EN_MODE) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b411c 0 0xfffffffc 0x3 # (BT_SYNC_BUFF_CTRL.ADC_DATA_EN_MODE) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ] || [ "$LB_BT_MODE" = "LB8" ];
    then
        write_field 0x604b4040 1 0xfffffff9 0x3 # (LB_CFG.WIFI_ADC1_LB_SEL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4108 0 0xfffffffe 0x0 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_EN) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4104 1 0xfffffffd 0x0 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4108 3 0xfffffff7 0x0 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4108 5 0xffffffdf 0x0 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4110 1 0xfffffffd 0x1 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4100 1 0xfffffffd 0x1 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4114 1 0xfffffff9 ${1} # (BT_RF_RX_SW_CTRL1.LNA_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4114 5 0xffffff9f ${2} # (BT_RF_RX_SW_CTRL1.LPF1_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "NOLB" ];
    then
        write_field 0x604b4114 9 0xffffe1ff ${3} # (BT_RF_RX_SW_CTRL1.LPF2_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ];
    then
        write_field 0x604b4108 0 0xfffffffe 0x0 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_EN) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ] || [ "$LB_BT_MODE" = "LB8" ];
    then
        write_field 0x604b4104 1 0xfffffffd 0x0 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ];
    then
        write_field 0x604b4108 3 0xfffffff7 0x0 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ];
    then
        write_field 0x604b4108 5 0xffffffdf 0x0 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ];
    then
        write_field 0x604b4110 1 0xfffffffd 0x1 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ] || [ "$LB_BT_MODE" = "LB8" ];
    then
        write_field 0x604b4100 1 0xfffffffd 0x1 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ];
    then
        write_field 0x604b4114 1 0xfffffff9 ${4} # (BT_RF_RX_SW_CTRL1.LNA_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ];
    then
        write_field 0x604b4114 5 0xffffff9f ${5} # (BT_RF_RX_SW_CTRL1.LPF1_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "LB15" ];
    then
        write_field 0x604b4114 9 0xffffe1ff ${6} # (BT_RF_RX_SW_CTRL1.LPF2_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4104 1 0xfffffffd 0x0 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4100 1 0xfffffffd 0x0 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4110 1 0xfffffffd 0x1 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4108 1 0xfffffffd 0x0 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4108 5 0xffffffdf 0x0 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4108 3 0xfffffff7 0x0 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4114 1 0xfffffff9 ${7} # (BT_RF_RX_SW_CTRL1.LNA_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4114 5 0xffffff9f ${8} # (BT_RF_RX_SW_CTRL1.LPF1_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD" ];
    then
        write_field 0x604b4114 9 0xffffe1ff ${9} # (BT_RF_RX_SW_CTRL1.LPF2_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4104 1 0xfffffffd 0x0 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4100 1 0xfffffffd 0x1 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4110 1 0xfffffffd 0x1 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4108 1 0xfffffffd 0x0 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4108 5 0xffffffdf 0x0 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4108 3 0xfffffff7 0x0 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4114 1 0xfffffff9 ${10} # (BT_RF_RX_SW_CTRL1.LNA_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4114 5 0xffffff9f ${11} # (BT_RF_RX_SW_CTRL1.LPF1_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_RF_TO_EXTPAD_OBS" ];
    then
        write_field 0x604b4114 9 0xffffe1ff ${12} # (BT_RF_RX_SW_CTRL1.LPF2_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_IQ" ];
    then
        write_field 0x604b4104 1 0xfffffffd 0x0 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_IQ" ];
    then
        write_field 0x604b4100 1 0xfffffffd 0x1 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_IQ" ];
    then
        write_field 0x604b4110 1 0xfffffffd 0x0 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_IQ" ];
    then
        write_field 0x604b4108 1 0xfffffffd 0x0 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_IQ" ];
    then
        write_field 0x604b4108 5 0xffffffdf 0x0 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_IQ" ];
    then
        write_field 0x604b4108 3 0xfffffff7 0x0 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_IQ" ];
    then
        write_field 0x604b4114 1 0xfffffff9 ${13} # (BT_RF_RX_SW_CTRL1.LNA_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_IQ" ];
    then
        write_field 0x604b4114 5 0xffffff9f ${14} # (BT_RF_RX_SW_CTRL1.LPF1_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_IQ" ];
    then
        write_field 0x604b4114 9 0xffffe1ff ${15} # (BT_RF_RX_SW_CTRL1.LPF2_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4104 1 0xfffffffd 0x0 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4100 1 0xfffffffd 0x1 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4110 1 0xfffffffd 0x1 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4108 1 0xfffffffd 0x0 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4108 5 0xffffffdf 0x0 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4108 3 0xfffffff7 0x0 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4114 1 0xfffffff9 ${16} # (BT_RF_RX_SW_CTRL1.LNA_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4114 5 0xffffff9f ${17} # (BT_RF_RX_SW_CTRL1.LPF1_GAIN_OVR_VAL) 
    fi
    if [ "$LB_BT_MODE" = "BT_EXTPAD_TO_LPF_TO_IQ" ];
    then
        write_field 0x604b4114 9 0xffffe1ff ${18} # (BT_RF_RX_SW_CTRL1.LPF2_GAIN_OVR_VAL) 
    fi
    if [ "$BT_SYS_MODE" = "BT_CALIB" ];
    then
        write_field 0x604b4118 16 0xfffeffff 0x1 # (BT_RF_COMMON_SW_CTRL.CAL_PULSE_OVR_EN) 
    fi
    if [ "$BT_SYS_MODE" = "BT_CALIB" ];
    then
        write_field 0x604b4118 16 0xfffeffff 0x0 # (BT_RF_COMMON_SW_CTRL.CAL_PULSE_OVR_EN) 
    fi
}

#(9b->6b)
function bt_rxon2chainconfig()
{
    write_field 0x604b4108 0 0xfffffffe 0x0 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_EN) 
    write_field 0x604b4104 1 0xfffffffd 0x0 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    write_field 0x604b4108 3 0xfffffff7 0x0 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_VAL) 
    write_field 0x604b410c 1 0xfffffe01 TBD # (BT_RF_TX_SW_CTRL1.TX_POWER_OVR_VAL) 
    write_field 0x604b4108 5 0xffffffdf 0x0 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_VAL) 
    write_field 0x604b4110 1 0xfffffffd 0x0 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_VAL) 
    write_field 0x604b4100 1 0xfffffffd 0x0 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
}

#(all->3b)
function bt_reset2btoff()
{
    write_field 0x604b4100 0 0xfffffffe 0x1 # (BT_ADC_SW_CTRL.ADC_EN_OVR_EN) 
    write_field 0x604b4100 2 0xfffffffb 0x1 # (BT_ADC_SW_CTRL.ADC_RESET_OVR_EN) 
    write_field 0x604b4104 0 0xfffffffe 0x1 # (BT_DAC_SW_CTRL.DAC_EN_OVR_EN) 
    write_field 0x604b4108 0 0xfffffffe 0x1 # (BT_RF_TX_SW_CTRL0.RF_TX_EN_OVR_EN) 
    write_field 0x604b4108 2 0xfffffffb 0x1 # (BT_RF_TX_SW_CTRL0.RF_PA_EN_OVR_EN) 
    write_field 0x604b4108 4 0xffffffef 0x1 # (BT_RF_TX_SW_CTRL0.RF_TR_SW_OVR_EN) 
    write_field 0x604b410c 0 0xfffffffe 0x1 # (BT_RF_TX_SW_CTRL1.TX_POWER_OVR_EN) 
    write_field 0x604b4110 0 0xfffffffe 0x1 # (BT_RF_RX_SW_CTRL0.RF_RX_EN_OVR_EN) 
    write_field 0x604b4114 0 0xfffffffe 0x1 # (BT_RF_RX_SW_CTRL1.LNA_GAIN_OVR_EN) 
    write_field 0x604b4114 4 0xffffffef 0x1 # (BT_RF_RX_SW_CTRL1.LPF1_GAIN_OVR_EN) 
    write_field 0x604b4114 8 0xfffffeff 0x1 # (BT_RF_RX_SW_CTRL1.LPF2_GAIN_OVR_EN) 
    write_field 0x604b4114 16 0xfffeffff 0x1 # (BT_RF_RX_SW_CTRL1.LNA_SAT_OVR_EN) 
    write_field 0x604b4118 0 0xfffffffe 0x1 # (BT_RF_COMMON_SW_CTRL.CHANNEL_OVR_EN) 
    write_field 0x604b4118 8 0xfffffeff 0x1 # (BT_RF_COMMON_SW_CTRL.MOD_SEL_OVR_EN) 
    write_field 0x604b4118 12 0xffffefff 0x1 # (BT_RF_COMMON_SW_CTRL.FILTER_BW_OVR_EN) 
    write_field 0x604b4118 16 0xfffeffff 0x1 # (BT_RF_COMMON_SW_CTRL.CAL_PULSE_OVR_EN) 
    write_field 0x604b411c 2 0xfffffff3 0x3 # (BT_SYNC_BUFF_CTRL.DAC_DATA_VALID_MODE) 
    write_field 0x604b411c 0 0xfffffffc 0x3 # (BT_SYNC_BUFF_CTRL.ADC_DATA_EN_MODE) 
    write_field 0x604b4040 0 0x0 0x0 # (LB_CFG.) 
    write_field 0x604b4108 0 0x0 0x15 # (BT_RF_TX_SW_CTRL0.) 
    write_field 0x604b4110 0 0x0 0x1 # (BT_RF_RX_SW_CTRL0.) 
    write_field 0x604b4114 0 0x0 0x10111 # (BT_RF_RX_SW_CTRL1.) 
    write_field 0x604b4a90 0 0x0 0x00000007 # (BT_CHANNEL_CONF.) 
    write_field 0x604b4a98 9 0xfffffdff 0x0 # (BT_LOGEN_CONF.BT_localdiv_divbuffen) 
    write_field 0x604b4af8 0 0x0 0x00000000 # (RF_FEM_BT_PA_CTRL0.) 
    write_field 0x604b4af4 0 0x0 0x00000000 # (RF_FEM_BT_LNA_CTRL1.) 
    write_field 0x604b4ad4 0 0x0 0x01800004 # (BT_ADC_STATIC_CONF.) 
    write_field 0x604b4ad8 0 0x0 0x000000c0 # (BT_DAC_STATIC_CONF.) 
    write_field 0x604b4a80 0 0x0 0x00000080 # (BT_BBIQ.) 
    write_field 0x604b4180 0 0x0 0x0 # (IQDC_TX_CONTROL.) 
    write_field 0x604b41b4 0 0x0 0x0 # (IQDC_RX_CONTROL.) 
    write_field 0x604b4a9c 1 0xfffffffd 0x0 # (BT_RSSI_CONF.BT_rssi_en) 
    write_field 0x604b4a84 15 0xfffe7fff 0x0 # (BT_BB_STATIC_CONF.BT_bb_extio_ctrl) 
    write_field 0x604b4100 1 0xfffffffd 0x0 # (BT_ADC_SW_CTRL.ADC_EN_OVR_VAL) 
    write_field 0x604b4104 1 0xfffffffd 0x0 # (BT_DAC_SW_CTRL.DAC_EN_OVR_VAL) 
    write_field 0x604b4834 0 0xfffffffe 0x0 # (SX0_IN_SPARE0.SX0_lobuff_splitter_drv_ch0_LOX0_en) 
    write_field 0x604b4834 1 0xfffffffd 0x0 # (SX0_IN_SPARE0.SX0_lobuff_splitter_drv_ch0_LOX1_en) 
    write_field 0x604b4834 2 0xfffffffb 0x0 # (SX0_IN_SPARE0.SX0_lobuff_splitter_drv_ch1_LOX0_en) 
    write_field 0x604b4830 20 0xffefffff 0x0 # (SX0_LOGEN_CTRL0.SX0_lobuff_rep_drv_ch0_LOX1_en) 
    write_field 0x604b4830 19 0xfff7ffff 0x0 # (SX0_LOGEN_CTRL0.SX0_lobuff_rep_drv_ch0_LOX0_en) 
    write_field 0x604b48b4 0 0xfffffffe 0x0 # (SX1_IN_SPARE0.SX1_lobuff_splitter_drv_ch1_LOX0_en) 
    write_field 0x604b48b4 1 0xfffffffd 0x0 # (SX1_IN_SPARE0.SX1_lobuff_splitter_drv_ch1_LOX1_en) 
    write_field 0x604b48b4 2 0xfffffffb 0x0 # (SX1_IN_SPARE0.SX1_lobuff_splitter_drv_ch0_LOX1_en) 
    write_field 0x604b48b0 20 0xffefffff 0x0 # (SX1_LOGEN_CTRL0.SX1_lobuff_rep_drv_ch1_LOX1_en) 
    write_field 0x604b48b0 19 0xfff7ffff 0x0 # (SX1_LOGEN_CTRL0.SX1_lobuff_rep_drv_ch1_LOX0_en) 
    write_field 0x604b4830 0 0xfffffffe 0x0 # (SX0_LOGEN_CTRL0.SX0_logen_buff_en) 
    write_field 0x604b4830 17 0xfffdffff 0x0 # (SX0_LOGEN_CTRL0.SX0_logen_mx_en) 
    write_field 0x604b4830 3 0xfffffff7 0x0 # (SX0_LOGEN_CTRL0.SX0_logen_div2_drv_en) 
    write_field 0x604b4830 18 0xfffbffff 0x0 # (SX0_LOGEN_CTRL0.SX0_losync_en) 
    write_field 0x604b48b0 4 0xffffffef 0x0 # (SX1_LOGEN_CTRL0.SX1_logen_ldo_en) 
    write_field 0x604b48b0 21 0xffdfffff 0x0 # (SX1_LOGEN_CTRL0.SX1_lobuff_ldo_en) 
    write_field 0x604b4a80 8 0xfffffeff 0x0 # (BT_BBIQ.BT_bb_bias_en) 
    write_field 0x604b4ad4 14 0xffffbfff 0x0 # (BT_ADC_STATIC_CONF.BT_adc_bias_en) 
    write_field 0x604b4ad8 4 0xffffffef 0x0 # (BT_DAC_STATIC_CONF.BT_dac_bias_en) 
    write_field 0x604b4ad4 23 0xff7fffff 0x0 # (BT_ADC_STATIC_CONF.BT_adc_ldo_en) 
    write_field 0x604b4ad8 6 0xffffffbf 0x0 # (BT_DAC_STATIC_CONF.BT_dac_ldo_en) 
    write_field 0x604b4a98 12 0xffffefff 0x0 # (BT_LOGEN_CONF.BT_localdiv_ldo_en) 
    write_field 0x604b4a88 27 0xf7ffffff 0x0 # (BT_BB_STATIC_CTRL_1.BT_bb_filter_en) 
    write_field 0x604b4af0 23 0xff7fffff 0x0 # (RF_FEM_BT_LNA_CTRL0.BT_rx_lna_ldo10_en) 
    write_field 0x604b4af0 24 0xfeffffff 0x0 # (RF_FEM_BT_LNA_CTRL0.BT_rx_lna_ldo14_en) 
    write_field 0x604b4a8c 16 0xfffeffff 0x0 # (BT_BB_STATIC_CTRL_2.BT_pdet_ldo_en) 
}
