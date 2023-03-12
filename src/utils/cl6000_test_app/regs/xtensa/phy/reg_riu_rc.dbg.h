X_REMOTE_ROM static const struct rom_table_direct_mem rom_riu_rc[] = {{
    CE_DEBUG_STR("\t\t------ RC_TX_CONFIG                   [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000000, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tx_allocated_chains            = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_DAC_FSM_STATE_0          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000004, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_DAC_FSM_STATE_1          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000008, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_DAC_FSM_STATE_2          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x0000000C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_DAC_FSM_STATE_3          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000010, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_DAC_FSM_STATE_4          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000014, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_DAC_FSM_S_0_TO_NEXT_STAT [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000018, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_DAC_FSM_S_1_TO_NEXT_STAT [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x0000001C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_DAC_FSM_S_2_TO_NEXT_STAT [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000020, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_DAC_FSM_S_3_TO_NEXT_STAT [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000024, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0x7FFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_DAC_FSM_S_4_TO_NEXT_STAT [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000028, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_DAC_SW_CTRL              [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x0000002C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("goto_state_valid               = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("goto_state                     = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_STATE_0           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000030, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_STATE_1           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000034, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_STATE_2           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000038, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_STATE_3           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x0000003C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_STATE_4           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000040, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_STATE_5           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000044, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_S_0_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000048, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_S_1_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x0000004C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_S_2_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000050, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_S_3_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000054, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_S_4_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000058, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_S_5_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x0000005C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_SW_CTRL               [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000060, .mask=0, .offset=0 },{
    CE_DEBUG_STR("goto_state_valid               = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("goto_state                     = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_FSM_STATUS               [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000064, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tx_rf_fsm_stat                 = [0x%08x]  \n"), .addr=0, .mask=0x00000038, .offset= 3,                             },{
    CE_DEBUG_STR("tx_dac_fsm_stat                = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_TO_RIU_TIMERS_0          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000068, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rc_tx_ack_on_clks              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_TO_RIU_TIMERS_1          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x0000006C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rc_tx_ack_off_clks             = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_GAIN_1                   [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000070, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tx_gain_1_ch_1                 = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("tx_gain_1_ch_0                 = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_CONFIG                   [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000074, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_allocated_chains            = [0x%08x]  \n"), .addr=0, .mask=0x00000003, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_FSM_STATE_0          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000078, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_FSM_STATE_1          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x0000007C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_FSM_STATE_2          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000080, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_FSM_STATE_3          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000084, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_FSM_STATE_4          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000088, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_FSM_STATE_5          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x0000008C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_FSM_S_0_TO_NEXT_STAT [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000090, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_FSM_S_1_TO_NEXT_STAT [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000094, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_FSM_S_2_TO_NEXT_STAT [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000098, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_FSM_S_3_TO_NEXT_STAT [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x0000009C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_FSM_S_4_TO_NEXT_STAT [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000A0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_FSM_S_5_TO_NEXT_STAT [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000A4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_ADC_SW_CTRL              [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000A8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("goto_state_valid               = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("goto_state                     = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_STATE_0           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000AC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_STATE_1           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000B0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_STATE_2           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000B4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_STATE_3           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000B8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_STATE_4           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000BC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_STATE_5           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000C0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_STATE_6           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000C4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_S_0_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000C8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_S_1_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000CC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_S_2_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000D0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_S_3_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000D4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_S_4_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000D8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_S_5_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000DC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_FSM_S_6_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000E0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_RF_SW_CTRL               [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000E4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("goto_state_valid               = [0x%08x]  \n"), .addr=0, .mask=0x00000008, .offset= 3,                             },{
    CE_DEBUG_STR("goto_state                     = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_FSM_STATUS               [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000E8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_rf_fsm_stat                 = [0x%08x]  \n"), .addr=0, .mask=0x00000038, .offset= 3,                             },{
    CE_DEBUG_STR("rx_adc_fsm_stat                = [0x%08x]  \n"), .addr=0, .mask=0x00000007, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_TO_RIU_TIMERS_0          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000EC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rc_rx_ack_on_clks              = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_TO_RIU_TIMERS_1          [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000F0, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rc_rx_ack_off_clks             = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_FORCE_GAIN               [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000F4, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_gain_force_en               = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("force_rx_gain_1                = [0x%08x]  \n"), .addr=0, .mask=0x0003FE00, .offset= 9,                             },{
    CE_DEBUG_STR("force_rx_gain_0                = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_INITIAL_GAIN             [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000F8, .mask=0, .offset=0 },{
    CE_DEBUG_STR("initial_rx_gain_1              = [0x%08x]  \n"), .addr=0, .mask=0x0003FE00, .offset= 9,                             },{
    CE_DEBUG_STR("initial_rx_gain_0              = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_INITIAL_FRAC_FREQ        [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x000000FC, .mask=0, .offset=0 },{
    CE_DEBUG_STR("initial_rx_frac_freq           = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_GAIN_STATUS              [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000100, .mask=0, .offset=0 },{
    CE_DEBUG_STR("ch_1_rx_gain_stat              = [0x%08x]  \n"), .addr=0, .mask=0x0003FE00, .offset= 9,                             },{
    CE_DEBUG_STR("ch_0_rx_gain_stat              = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_UNALLOCATED_CHAIN_CONFIG    [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000104, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rc_sw_enable                   = [0x%08x]  \n"), .addr=0, .mask=0x80000000, .offset=31,                             },{
    CE_DEBUG_STR("adc_out                        = [0x%08x]  \n"), .addr=0, .mask=0x1E000000, .offset=25,                             },{
    CE_DEBUG_STR("dac_out                        = [0x%08x]  \n"), .addr=0, .mask=0x01E00000, .offset=21,                             },{
    CE_DEBUG_STR("rf_out_3                       = [0x%08x]  \n"), .addr=0, .mask=0x001FE000, .offset=13,                             },{
    CE_DEBUG_STR("rf_out_2                       = [0x%08x]  \n"), .addr=0, .mask=0x00001FF0, .offset= 4,                             },{
    CE_DEBUG_STR("rf_out_1                       = [0x%08x]  \n"), .addr=0, .mask=0x0000000E, .offset= 1,                             },{
    CE_DEBUG_STR("rf_out_0                       = [0x%08x]  \n"), .addr=0, .mask=0x00000001, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_RX_SW_GAIN                  [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000108, .mask=0, .offset=0 },{
    CE_DEBUG_STR("rx_sw_gain_update              = [0x%08x]  \n"), .addr=0, .mask=0x00040000, .offset=18,                             },{
    CE_DEBUG_STR("rx_sw_gain_ch_1                = [0x%08x]  \n"), .addr=0, .mask=0x0003FE00, .offset= 9,                             },{
    CE_DEBUG_STR("rx_sw_gain_ch_0                = [0x%08x]  \n"), .addr=0, .mask=0x000001FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_STATE_6           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x0000010C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_STATE_7           [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000110, .mask=0, .offset=0 },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_3   = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_2   = [0x%08x]  \n"), .addr=0, .mask=0x00008000, .offset=15,                             },{
    CE_DEBUG_STR("en_hw_signal_to_next_state_1   = [0x%08x]  \n"), .addr=0, .mask=0x00004000, .offset=14,                             },{
    CE_DEBUG_STR("timer_en_to_next_state_1       = [0x%08x]  \n"), .addr=0, .mask=0x00002000, .offset=13,                             },{
    CE_DEBUG_STR("next_state_3                   = [0x%08x]  \n"), .addr=0, .mask=0x00001C00, .offset=10,                             },{
    CE_DEBUG_STR("next_state_2                   = [0x%08x]  \n"), .addr=0, .mask=0x00000380, .offset= 7,                             },{
    CE_DEBUG_STR("next_state_1                   = [0x%08x]  \n"), .addr=0, .mask=0x00000070, .offset= 4,                             },{
    CE_DEBUG_STR("out                            = [0x%08x]  \n"), .addr=0, .mask=0x0000000F, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_S_6_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000114, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_RF_FSM_S_7_TO_NEXT_STATE [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000118, .mask=0, .offset=0 },{
    CE_DEBUG_STR("timer_to_next_state_1          = [0x%08x]  \n"), .addr=0, .mask=0xFFFFFFFF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_INITIAL_GAIN             [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x0000011C, .mask=0, .offset=0 },{
    CE_DEBUG_STR("initial_tx_gain_1              = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("initial_tx_gain_0              = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    CE_DEBUG_STR("\t\t------ RC_TX_GAIN_2                   [0x%08x]\n" ) , .addr=REG_RIU_RC_BASE_ADDR + 0x00000120, .mask=0, .offset=0 },{
    CE_DEBUG_STR("tx_gain_update                 = [0x%08x]  \n"), .addr=0, .mask=0x00010000, .offset=16,                             },{
    CE_DEBUG_STR("tx_gain_2_ch_1                 = [0x%08x]  \n"), .addr=0, .mask=0x0000FF00, .offset= 8,                             },{
    CE_DEBUG_STR("tx_gain_2_ch_0                 = [0x%08x]  \n"), .addr=0, .mask=0x000000FF, .offset= 0,                             },{
    .str=NULL }
};//RIU_RC 
