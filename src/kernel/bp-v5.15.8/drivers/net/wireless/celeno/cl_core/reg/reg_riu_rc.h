/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef REG_RC_H
#define REG_RC_H

#include <linux/types.h>
#include "chip.h"

#define REG_RIU_RC_BASE_ADDR 0x004A5000

/**
 * @brief RC_TX_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 TX_ALLOCATED_CHAINS       0x0
 * </pre>
 */
#define RIU_RC_RC_TX_CONFIG_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000000)
#define RIU_RC_RC_TX_CONFIG_OFFSET      0x00000000
#define RIU_RC_RC_TX_CONFIG_INDEX       0x00000000
#define RIU_RC_RC_TX_CONFIG_RESET       0x00000000

static inline u32 riu_rc_rc_tx_config_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_CONFIG_ADDR);
}

static inline void riu_rc_rc_tx_config_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_CONFIG_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_CONFIG_TX_ALLOCATED_CHAINS_MASK    ((u32)0x00000003)
#define RIU_RC_RC_TX_CONFIG_TX_ALLOCATED_CHAINS_LSB    0
#define RIU_RC_RC_TX_CONFIG_TX_ALLOCATED_CHAINS_WIDTH    ((u32)0x00000002)

#define RIU_RC_RC_TX_CONFIG_TX_ALLOCATED_CHAINS_RST    0x0

static inline u8 riu_rc_rc_tx_config_tx_allocated_chains_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_CONFIG_ADDR);

	return (u8)(local_val >> 0);
}

static inline void riu_rc_rc_tx_config_tx_allocated_chains_setf(struct cl_chip *chip, u8 txallocatedchains)
{
	ASSERT_ERR_CHIP((((u32)txallocatedchains << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_CONFIG_ADDR, (u32)txallocatedchains << 0);
}

/**
 * @brief RC_TX_DAC_FSM_STATE_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 1
 *    13    TIMER_EN_TO_NEXT_STATE_1  0
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x1
 *    03:00 OUT                       0x4
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000004)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_OFFSET      0x00000004
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_INDEX       0x00000001
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_RESET       0x00004014

static inline u32 riu_rc_rc_tx_dac_fsm_state_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);
}

static inline void riu_rc_rc_tx_dac_fsm_state_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_OUT_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_OUT_RST    0x4

static inline void riu_rc_rc_tx_dac_fsm_state_0_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_dac_fsm_state_0_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_0_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_dac_fsm_state_0_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_0_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_dac_fsm_state_0_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_0_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_dac_fsm_state_0_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_0_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_dac_fsm_state_0_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_0_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_dac_fsm_state_0_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_0_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_dac_fsm_state_0_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_0_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_dac_fsm_state_0_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_0_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_dac_fsm_state_0_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_DAC_FSM_STATE_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 1
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x3
 *    06:04 NEXT_STATE_1              0x2
 *    03:00 OUT                       0x4
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000008)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_OFFSET      0x00000008
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_INDEX       0x00000002
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_RESET       0x0000A1A4

static inline u32 riu_rc_rc_tx_dac_fsm_state_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);
}

static inline void riu_rc_rc_tx_dac_fsm_state_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_OUT_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_2_RST    0x3
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_1_RST    0x2
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_OUT_RST    0x4

static inline void riu_rc_rc_tx_dac_fsm_state_1_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_dac_fsm_state_1_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_1_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_dac_fsm_state_1_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_1_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_dac_fsm_state_1_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_1_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_dac_fsm_state_1_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_1_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_dac_fsm_state_1_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_1_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_dac_fsm_state_1_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_1_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_dac_fsm_state_1_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_1_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_dac_fsm_state_1_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_1_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_dac_fsm_state_1_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_DAC_FSM_STATE_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 1
 *    13    TIMER_EN_TO_NEXT_STATE_1  0
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x3
 *    03:00 OUT                       0x7
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR        (REG_RIU_RC_BASE_ADDR + 0x0000000C)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_OFFSET      0x0000000C
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_INDEX       0x00000003
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_RESET       0x00004037

static inline u32 riu_rc_rc_tx_dac_fsm_state_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);
}

static inline void riu_rc_rc_tx_dac_fsm_state_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_OUT_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_1_RST    0x3
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_OUT_RST    0x7

static inline void riu_rc_rc_tx_dac_fsm_state_2_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_dac_fsm_state_2_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_2_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_dac_fsm_state_2_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_2_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_dac_fsm_state_2_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_2_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_dac_fsm_state_2_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_2_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_dac_fsm_state_2_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_2_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_dac_fsm_state_2_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_2_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_dac_fsm_state_2_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_2_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_dac_fsm_state_2_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_2_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_dac_fsm_state_2_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_DAC_FSM_STATE_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x4
 *    03:00 OUT                       0x7
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000010)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_OFFSET      0x00000010
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_INDEX       0x00000004
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_RESET       0x00002047

static inline u32 riu_rc_rc_tx_dac_fsm_state_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);
}

static inline void riu_rc_rc_tx_dac_fsm_state_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_OUT_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_1_RST    0x4
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_OUT_RST    0x7

static inline void riu_rc_rc_tx_dac_fsm_state_3_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_dac_fsm_state_3_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_3_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_dac_fsm_state_3_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_3_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_dac_fsm_state_3_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_3_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_dac_fsm_state_3_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_3_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_dac_fsm_state_3_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_3_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_dac_fsm_state_3_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_3_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_dac_fsm_state_3_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_3_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_dac_fsm_state_3_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_3_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_dac_fsm_state_3_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_DAC_FSM_STATE_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x0
 *    03:00 OUT                       0x4
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000014)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_OFFSET      0x00000014
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_INDEX       0x00000005
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_RESET       0x00002004

static inline u32 riu_rc_rc_tx_dac_fsm_state_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);
}

static inline void riu_rc_rc_tx_dac_fsm_state_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_OUT_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_OUT_RST    0x4

static inline void riu_rc_rc_tx_dac_fsm_state_4_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_dac_fsm_state_4_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_4_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_dac_fsm_state_4_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_4_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_dac_fsm_state_4_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_4_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_dac_fsm_state_4_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_4_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_dac_fsm_state_4_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_4_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_dac_fsm_state_4_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_4_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_dac_fsm_state_4_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_4_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_dac_fsm_state_4_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_dac_fsm_state_4_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_dac_fsm_state_4_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000018)
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_OFFSET      0x00000018
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_INDEX       0x00000006
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_RESET       0x00000000

static inline u32 riu_rc_rc_tx_dac_fsm_s_0_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_dac_fsm_s_0_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

static inline u32 riu_rc_rc_tx_dac_fsm_s_0_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_dac_fsm_s_0_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x7
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x0000001C)
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_OFFSET      0x0000001C
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_INDEX       0x00000007
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_RESET       0x00000007

static inline u32 riu_rc_rc_tx_dac_fsm_s_1_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_dac_fsm_s_1_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x7

static inline u32 riu_rc_rc_tx_dac_fsm_s_1_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_dac_fsm_s_1_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000020)
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_OFFSET      0x00000020
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_INDEX       0x00000008
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_RESET       0x00000000

static inline u32 riu_rc_rc_tx_dac_fsm_s_2_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_dac_fsm_s_2_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

static inline u32 riu_rc_rc_tx_dac_fsm_s_2_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_dac_fsm_s_2_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:00 TIMER_TO_NEXT_STATE_1     0x80
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000024)
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_OFFSET      0x00000024
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_INDEX       0x00000009
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_RESET       0x00000080

static inline u32 riu_rc_rc_tx_dac_fsm_s_3_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_dac_fsm_s_3_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0x7FFFFFFF)
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x0000001F)

#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x80

static inline u32 riu_rc_rc_tx_dac_fsm_s_3_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_dac_fsm_s_3_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0x7FFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000028)
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_OFFSET      0x00000028
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_INDEX       0x0000000A
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_RESET       0x00000005

static inline u32 riu_rc_rc_tx_dac_fsm_s_4_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_dac_fsm_s_4_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

static inline u32 riu_rc_rc_tx_dac_fsm_s_4_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_dac_fsm_s_4_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_DAC_SW_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    GOTO_STATE_VALID          0
 *    02:00 GOTO_STATE                0x0
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_SW_CTRL_ADDR        (REG_RIU_RC_BASE_ADDR + 0x0000002C)
#define RIU_RC_RC_TX_DAC_SW_CTRL_OFFSET      0x0000002C
#define RIU_RC_RC_TX_DAC_SW_CTRL_INDEX       0x0000000B
#define RIU_RC_RC_TX_DAC_SW_CTRL_RESET       0x00000000

static inline u32 riu_rc_rc_tx_dac_sw_ctrl_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_DAC_SW_CTRL_ADDR);
}

static inline void riu_rc_rc_tx_dac_sw_ctrl_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_SW_CTRL_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_VALID_BIT    ((u32)0x00000008)
#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_VALID_POS    3
#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_MASK    ((u32)0x00000007)
#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_LSB    0
#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_WIDTH    ((u32)0x00000003)

#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_VALID_RST    0x0
#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_RST    0x0

static inline void riu_rc_rc_tx_dac_sw_ctrl_pack(struct cl_chip *chip, u8 goto_state_valid, u8 goto_state)
{
	ASSERT_ERR_CHIP((((u32)goto_state_valid << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)goto_state << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_SW_CTRL_ADDR, ((u32)goto_state_valid << 3) | ((u32)goto_state << 0));
}

static inline void riu_rc_rc_tx_dac_sw_ctrl_unpack(struct cl_chip *chip, u8 *goto_state_valid, u8 *goto_state)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_SW_CTRL_ADDR);

	*goto_state_valid = (local_val & ((u32)0x00000008)) >> 3;
	*goto_state = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 riu_rc_rc_tx_dac_sw_ctrl_goto_state_valid_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_SW_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void riu_rc_rc_tx_dac_sw_ctrl_goto_state_valid_setf(struct cl_chip *chip, u8 gotostatevalid)
{
	ASSERT_ERR_CHIP((((u32)gotostatevalid << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_SW_CTRL_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_SW_CTRL_ADDR) & ~((u32)0x00000008)) | ((u32)gotostatevalid << 3));
}

static inline u8 riu_rc_rc_tx_dac_sw_ctrl_goto_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_DAC_SW_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void riu_rc_rc_tx_dac_sw_ctrl_goto_state_setf(struct cl_chip *chip, u8 gotostate)
{
	ASSERT_ERR_CHIP((((u32)gotostate << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_DAC_SW_CTRL_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_DAC_SW_CTRL_ADDR) & ~((u32)0x00000007)) | ((u32)gotostate << 0));
}

/**
 * @brief RC_TX_RF_FSM_STATE_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 1
 *    13    TIMER_EN_TO_NEXT_STATE_1  0
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x1
 *    03:00 OUT                       0x0
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000030)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_OFFSET      0x00000030
#define RIU_RC_RC_TX_RF_FSM_STATE_0_INDEX       0x0000000C
#define RIU_RC_RC_TX_RF_FSM_STATE_0_RESET       0x00004010

static inline u32 riu_rc_rc_tx_rf_fsm_state_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_state_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_0_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_0_OUT_RST    0x0

static inline void riu_rc_rc_tx_rf_fsm_state_0_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_rf_fsm_state_0_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_0_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_rf_fsm_state_0_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_0_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_rf_fsm_state_0_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_0_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_rf_fsm_state_0_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_0_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_rf_fsm_state_0_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_0_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_rf_fsm_state_0_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_0_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_rf_fsm_state_0_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_0_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_rf_fsm_state_0_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_0_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_state_0_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_RF_FSM_STATE_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 1
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x6
 *    06:04 NEXT_STATE_1              0x2
 *    03:00 OUT                       0x0
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000034)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_OFFSET      0x00000034
#define RIU_RC_RC_TX_RF_FSM_STATE_1_INDEX       0x0000000D
#define RIU_RC_RC_TX_RF_FSM_STATE_1_RESET       0x0000A320

static inline u32 riu_rc_rc_tx_rf_fsm_state_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_state_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_1_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_2_RST    0x6
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_1_RST    0x2
#define RIU_RC_RC_TX_RF_FSM_STATE_1_OUT_RST    0x0

static inline void riu_rc_rc_tx_rf_fsm_state_1_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_rf_fsm_state_1_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_1_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_rf_fsm_state_1_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_1_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_rf_fsm_state_1_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_1_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_rf_fsm_state_1_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_1_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_rf_fsm_state_1_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_1_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_rf_fsm_state_1_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_1_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_rf_fsm_state_1_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_1_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_rf_fsm_state_1_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_1_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_state_1_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_RF_FSM_STATE_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 1
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x6
 *    06:04 NEXT_STATE_1              0x3
 *    03:00 OUT                       0x1
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000038)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_OFFSET      0x00000038
#define RIU_RC_RC_TX_RF_FSM_STATE_2_INDEX       0x0000000E
#define RIU_RC_RC_TX_RF_FSM_STATE_2_RESET       0x0000A331

static inline u32 riu_rc_rc_tx_rf_fsm_state_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_state_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_2_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_2_RST    0x6
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_1_RST    0x3
#define RIU_RC_RC_TX_RF_FSM_STATE_2_OUT_RST    0x1

static inline void riu_rc_rc_tx_rf_fsm_state_2_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_rf_fsm_state_2_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_2_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_rf_fsm_state_2_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_2_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_rf_fsm_state_2_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_2_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_rf_fsm_state_2_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_2_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_rf_fsm_state_2_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_2_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_rf_fsm_state_2_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_2_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_rf_fsm_state_2_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_2_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_rf_fsm_state_2_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_2_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_state_2_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_RF_FSM_STATE_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 1
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x6
 *    06:04 NEXT_STATE_1              0x4
 *    03:00 OUT                       0x1
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR        (REG_RIU_RC_BASE_ADDR + 0x0000003C)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_OFFSET      0x0000003C
#define RIU_RC_RC_TX_RF_FSM_STATE_3_INDEX       0x0000000F
#define RIU_RC_RC_TX_RF_FSM_STATE_3_RESET       0x0000A341

static inline u32 riu_rc_rc_tx_rf_fsm_state_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_state_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_3_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_2_RST    0x6
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_1_RST    0x4
#define RIU_RC_RC_TX_RF_FSM_STATE_3_OUT_RST    0x1

static inline void riu_rc_rc_tx_rf_fsm_state_3_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_rf_fsm_state_3_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_3_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_rf_fsm_state_3_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_3_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_rf_fsm_state_3_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_3_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_rf_fsm_state_3_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_3_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_rf_fsm_state_3_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_3_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_rf_fsm_state_3_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_3_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_rf_fsm_state_3_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_3_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_rf_fsm_state_3_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_3_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_state_3_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_RF_FSM_STATE_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 1
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x6
 *    06:04 NEXT_STATE_1              0x5
 *    03:00 OUT                       0x7
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000040)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_OFFSET      0x00000040
#define RIU_RC_RC_TX_RF_FSM_STATE_4_INDEX       0x00000010
#define RIU_RC_RC_TX_RF_FSM_STATE_4_RESET       0x0000A357

static inline u32 riu_rc_rc_tx_rf_fsm_state_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_state_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_4_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_2_RST    0x6
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_1_RST    0x5
#define RIU_RC_RC_TX_RF_FSM_STATE_4_OUT_RST    0x7

static inline void riu_rc_rc_tx_rf_fsm_state_4_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_rf_fsm_state_4_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_4_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_rf_fsm_state_4_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_4_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_rf_fsm_state_4_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_4_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_rf_fsm_state_4_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_4_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_rf_fsm_state_4_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_4_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_rf_fsm_state_4_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_4_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_rf_fsm_state_4_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_4_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_rf_fsm_state_4_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_4_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_state_4_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_RF_FSM_STATE_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 1
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 1
 *    13    TIMER_EN_TO_NEXT_STATE_1  0
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x4
 *    06:04 NEXT_STATE_1              0x6
 *    03:00 OUT                       0x7
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000044)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_OFFSET      0x00000044
#define RIU_RC_RC_TX_RF_FSM_STATE_5_INDEX       0x00000011
#define RIU_RC_RC_TX_RF_FSM_STATE_5_RESET       0x0000C267

static inline u32 riu_rc_rc_tx_rf_fsm_state_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_state_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_5_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_2_RST    0x4
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_1_RST    0x6
#define RIU_RC_RC_TX_RF_FSM_STATE_5_OUT_RST    0x7

static inline void riu_rc_rc_tx_rf_fsm_state_5_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_rf_fsm_state_5_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_5_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_rf_fsm_state_5_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_5_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_rf_fsm_state_5_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_5_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_rf_fsm_state_5_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_5_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_rf_fsm_state_5_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_5_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_rf_fsm_state_5_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_5_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_rf_fsm_state_5_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_5_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_rf_fsm_state_5_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_5_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_state_5_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000048)
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_OFFSET      0x00000048
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_INDEX       0x00000012
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_RESET       0x00000000

static inline u32 riu_rc_rc_tx_rf_fsm_s_0_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_s_0_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

static inline u32 riu_rc_rc_tx_rf_fsm_s_0_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_s_0_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0xB
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x0000004C)
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_OFFSET      0x0000004C
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_INDEX       0x00000013
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_RESET       0x0000000B

static inline u32 riu_rc_rc_tx_rf_fsm_s_1_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_s_1_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0xB

static inline u32 riu_rc_rc_tx_rf_fsm_s_1_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_s_1_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x3
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000050)
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_OFFSET      0x00000050
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_INDEX       0x00000014
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_RESET       0x00000003

static inline u32 riu_rc_rc_tx_rf_fsm_s_2_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_s_2_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x3

static inline u32 riu_rc_rc_tx_rf_fsm_s_2_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_s_2_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000054)
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_OFFSET      0x00000054
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_INDEX       0x00000015
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_RESET       0x00000000

static inline u32 riu_rc_rc_tx_rf_fsm_s_3_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_s_3_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

static inline u32 riu_rc_rc_tx_rf_fsm_s_3_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_s_3_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x30
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000058)
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_OFFSET      0x00000058
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_INDEX       0x00000016
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_RESET       0x00000030

static inline u32 riu_rc_rc_tx_rf_fsm_s_4_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_s_4_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x30

static inline u32 riu_rc_rc_tx_rf_fsm_s_4_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_s_4_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x0000005C)
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_OFFSET      0x0000005C
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_INDEX       0x00000017
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_RESET       0x00000005

static inline u32 riu_rc_rc_tx_rf_fsm_s_5_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_s_5_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

static inline u32 riu_rc_rc_tx_rf_fsm_s_5_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_s_5_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_SW_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    GOTO_STATE_VALID          0
 *    02:00 GOTO_STATE                0x0
 * </pre>
 */
#define RIU_RC_RC_TX_RF_SW_CTRL_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000060)
#define RIU_RC_RC_TX_RF_SW_CTRL_OFFSET      0x00000060
#define RIU_RC_RC_TX_RF_SW_CTRL_INDEX       0x00000018
#define RIU_RC_RC_TX_RF_SW_CTRL_RESET       0x00000000

static inline u32 riu_rc_rc_tx_rf_sw_ctrl_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_SW_CTRL_ADDR);
}

static inline void riu_rc_rc_tx_rf_sw_ctrl_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_SW_CTRL_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_VALID_BIT    ((u32)0x00000008)
#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_VALID_POS    3
#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_MASK    ((u32)0x00000007)
#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_LSB    0
#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_WIDTH    ((u32)0x00000003)

#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_VALID_RST    0x0
#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_RST    0x0

static inline void riu_rc_rc_tx_rf_sw_ctrl_pack(struct cl_chip *chip, u8 goto_state_valid, u8 goto_state)
{
	ASSERT_ERR_CHIP((((u32)goto_state_valid << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)goto_state << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_SW_CTRL_ADDR, ((u32)goto_state_valid << 3) | ((u32)goto_state << 0));
}

static inline void riu_rc_rc_tx_rf_sw_ctrl_unpack(struct cl_chip *chip, u8 *goto_state_valid, u8 *goto_state)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_SW_CTRL_ADDR);

	*goto_state_valid = (local_val & ((u32)0x00000008)) >> 3;
	*goto_state = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 riu_rc_rc_tx_rf_sw_ctrl_goto_state_valid_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_SW_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void riu_rc_rc_tx_rf_sw_ctrl_goto_state_valid_setf(struct cl_chip *chip, u8 gotostatevalid)
{
	ASSERT_ERR_CHIP((((u32)gotostatevalid << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_SW_CTRL_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_SW_CTRL_ADDR) & ~((u32)0x00000008)) | ((u32)gotostatevalid << 3));
}

static inline u8 riu_rc_rc_tx_rf_sw_ctrl_goto_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_SW_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void riu_rc_rc_tx_rf_sw_ctrl_goto_state_setf(struct cl_chip *chip, u8 gotostate)
{
	ASSERT_ERR_CHIP((((u32)gotostate << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_SW_CTRL_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_SW_CTRL_ADDR) & ~((u32)0x00000007)) | ((u32)gotostate << 0));
}

/**
 * @brief RC_TX_FSM_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:03 TX_RF_FSM_STAT            0x0
 *    02:00 TX_DAC_FSM_STAT           0x0
 * </pre>
 */
#define RIU_RC_RC_TX_FSM_STATUS_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000064)
#define RIU_RC_RC_TX_FSM_STATUS_OFFSET      0x00000064
#define RIU_RC_RC_TX_FSM_STATUS_INDEX       0x00000019
#define RIU_RC_RC_TX_FSM_STATUS_RESET       0x00000000

static inline u32 riu_rc_rc_tx_fsm_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_FSM_STATUS_ADDR);
}

/* Field definitions */
#define RIU_RC_RC_TX_FSM_STATUS_TX_RF_FSM_STAT_MASK    ((u32)0x00000038)
#define RIU_RC_RC_TX_FSM_STATUS_TX_RF_FSM_STAT_LSB    3
#define RIU_RC_RC_TX_FSM_STATUS_TX_RF_FSM_STAT_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_FSM_STATUS_TX_DAC_FSM_STAT_MASK    ((u32)0x00000007)
#define RIU_RC_RC_TX_FSM_STATUS_TX_DAC_FSM_STAT_LSB    0
#define RIU_RC_RC_TX_FSM_STATUS_TX_DAC_FSM_STAT_WIDTH    ((u32)0x00000003)

#define RIU_RC_RC_TX_FSM_STATUS_TX_RF_FSM_STAT_RST    0x0
#define RIU_RC_RC_TX_FSM_STATUS_TX_DAC_FSM_STAT_RST    0x0

static inline void riu_rc_rc_tx_fsm_status_unpack(struct cl_chip *chip, u8 *tx_rf_fsm_stat, u8 *tx_dac_fsm_stat)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_FSM_STATUS_ADDR);

	*tx_rf_fsm_stat = (local_val & ((u32)0x00000038)) >> 3;
	*tx_dac_fsm_stat = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 riu_rc_rc_tx_fsm_status_tx_rf_fsm_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_FSM_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline u8 riu_rc_rc_tx_fsm_status_tx_dac_fsm_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_FSM_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

/**
 * @brief RC_TX_TO_RIU_TIMERS_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RC_TX_ACK_ON_CLKS         0x19
 * </pre>
 */
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000068)
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_OFFSET      0x00000068
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_INDEX       0x0000001A
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_RESET       0x00000019

static inline u32 riu_rc_rc_tx_to_riu_timers_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_TO_RIU_TIMERS_0_ADDR);
}

static inline void riu_rc_rc_tx_to_riu_timers_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_TO_RIU_TIMERS_0_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_RC_TX_ACK_ON_CLKS_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_RC_TX_ACK_ON_CLKS_LSB    0
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_RC_TX_ACK_ON_CLKS_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_RC_TX_ACK_ON_CLKS_RST    0x19

static inline u32 riu_rc_rc_tx_to_riu_timers_0_rc_tx_ack_on_clks_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_TO_RIU_TIMERS_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_to_riu_timers_0_rc_tx_ack_on_clks_setf(struct cl_chip *chip, u32 rctxackonclks)
{
	ASSERT_ERR_CHIP((((u32)rctxackonclks << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_TO_RIU_TIMERS_0_ADDR, (u32)rctxackonclks << 0);
}

/**
 * @brief RC_TX_TO_RIU_TIMERS_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RC_TX_ACK_OFF_CLKS        0x90
 * </pre>
 */
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_ADDR        (REG_RIU_RC_BASE_ADDR + 0x0000006C)
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_OFFSET      0x0000006C
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_INDEX       0x0000001B
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_RESET       0x00000090

static inline u32 riu_rc_rc_tx_to_riu_timers_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_TO_RIU_TIMERS_1_ADDR);
}

static inline void riu_rc_rc_tx_to_riu_timers_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_TO_RIU_TIMERS_1_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_RC_TX_ACK_OFF_CLKS_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_RC_TX_ACK_OFF_CLKS_LSB    0
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_RC_TX_ACK_OFF_CLKS_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_RC_TX_ACK_OFF_CLKS_RST    0x90

static inline u32 riu_rc_rc_tx_to_riu_timers_1_rc_tx_ack_off_clks_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_TO_RIU_TIMERS_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_to_riu_timers_1_rc_tx_ack_off_clks_setf(struct cl_chip *chip, u32 rctxackoffclks)
{
	ASSERT_ERR_CHIP((((u32)rctxackoffclks << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_TO_RIU_TIMERS_1_ADDR, (u32)rctxackoffclks << 0);
}

/**
 * @brief RC_TX_GAIN_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:08 TX_GAIN_1_CH_1            0x0
 *    07:00 TX_GAIN_1_CH_0            0x0
 * </pre>
 */
#define RIU_RC_RC_TX_GAIN_1_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000070)
#define RIU_RC_RC_TX_GAIN_1_OFFSET      0x00000070
#define RIU_RC_RC_TX_GAIN_1_INDEX       0x0000001C
#define RIU_RC_RC_TX_GAIN_1_RESET       0x00000000

static inline u32 riu_rc_rc_tx_gain_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_GAIN_1_ADDR);
}

static inline void riu_rc_rc_tx_gain_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_GAIN_1_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_1_MASK    ((u32)0x0000FF00)
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_1_LSB    8
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_1_WIDTH    ((u32)0x00000008)
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_0_MASK    ((u32)0x000000FF)
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_0_LSB    0
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_0_WIDTH    ((u32)0x00000008)

#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_1_RST    0x0
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_0_RST    0x0

static inline void riu_rc_rc_tx_gain_1_pack(struct cl_chip *chip, u8 tx_gain_1_ch_1, u8 tx_gain_1_ch_0)
{
	ASSERT_ERR_CHIP((((u32)tx_gain_1_ch_1 << 8) & ~((u32)0x0000FF00)) == 0);
	ASSERT_ERR_CHIP((((u32)tx_gain_1_ch_0 << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_GAIN_1_ADDR, ((u32)tx_gain_1_ch_1 << 8) | ((u32)tx_gain_1_ch_0 << 0));
}

static inline void riu_rc_rc_tx_gain_1_unpack(struct cl_chip *chip, u8 *tx_gain_1_ch_1, u8 *tx_gain_1_ch_0)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_GAIN_1_ADDR);

	*tx_gain_1_ch_1 = (local_val & ((u32)0x0000FF00)) >> 8;
	*tx_gain_1_ch_0 = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u8 riu_rc_rc_tx_gain_1_tx_gain_1_ch_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_GAIN_1_ADDR);

	return (u8)((local_val & ((u32)0x0000FF00)) >> 8);
}

static inline void riu_rc_rc_tx_gain_1_tx_gain_1_ch_1_setf(struct cl_chip *chip, u8 txgain1ch1)
{
	ASSERT_ERR_CHIP((((u32)txgain1ch1 << 8) & ~((u32)0x0000FF00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_GAIN_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_GAIN_1_ADDR) & ~((u32)0x0000FF00)) | ((u32)txgain1ch1 << 8));
}

static inline u8 riu_rc_rc_tx_gain_1_tx_gain_1_ch_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_GAIN_1_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void riu_rc_rc_tx_gain_1_tx_gain_1_ch_0_setf(struct cl_chip *chip, u8 txgain1ch0)
{
	ASSERT_ERR_CHIP((((u32)txgain1ch0 << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_GAIN_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_GAIN_1_ADDR) & ~((u32)0x000000FF)) | ((u32)txgain1ch0 << 0));
}

/**
 * @brief RC_RX_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 RX_ALLOCATED_CHAINS       0x0
 * </pre>
 */
#define RIU_RC_RC_RX_CONFIG_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000074)
#define RIU_RC_RC_RX_CONFIG_OFFSET      0x00000074
#define RIU_RC_RC_RX_CONFIG_INDEX       0x0000001D
#define RIU_RC_RC_RX_CONFIG_RESET       0x00000000

static inline u32 riu_rc_rc_rx_config_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_CONFIG_ADDR);
}

static inline void riu_rc_rc_rx_config_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_CONFIG_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_CONFIG_RX_ALLOCATED_CHAINS_MASK    ((u32)0x00000003)
#define RIU_RC_RC_RX_CONFIG_RX_ALLOCATED_CHAINS_LSB    0
#define RIU_RC_RC_RX_CONFIG_RX_ALLOCATED_CHAINS_WIDTH    ((u32)0x00000002)

#define RIU_RC_RC_RX_CONFIG_RX_ALLOCATED_CHAINS_RST    0x0

static inline u8 riu_rc_rc_rx_config_rx_allocated_chains_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_CONFIG_ADDR);

	return (u8)(local_val >> 0);
}

static inline void riu_rc_rc_rx_config_rx_allocated_chains_setf(struct cl_chip *chip, u8 rxallocatedchains)
{
	ASSERT_ERR_CHIP((((u32)rxallocatedchains << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_CONFIG_ADDR, (u32)rxallocatedchains << 0);
}

/**
 * @brief RC_RX_ADC_FSM_STATE_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 1
 *    13    TIMER_EN_TO_NEXT_STATE_1  0
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x1
 *    03:00 OUT                       0x3
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000078)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_OFFSET      0x00000078
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_INDEX       0x0000001E
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_RESET       0x00004013

static inline u32 riu_rc_rc_rx_adc_fsm_state_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);
}

static inline void riu_rc_rc_rx_adc_fsm_state_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_OUT_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_OUT_RST    0x3

static inline void riu_rc_rc_rx_adc_fsm_state_0_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_adc_fsm_state_0_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_0_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_adc_fsm_state_0_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_0_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_adc_fsm_state_0_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_0_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_adc_fsm_state_0_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_0_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_adc_fsm_state_0_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_0_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_adc_fsm_state_0_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_0_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_adc_fsm_state_0_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_0_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_adc_fsm_state_0_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_0_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_adc_fsm_state_0_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_ADC_FSM_STATE_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 1
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x4
 *    06:04 NEXT_STATE_1              0x2
 *    03:00 OUT                       0x3
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR        (REG_RIU_RC_BASE_ADDR + 0x0000007C)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_OFFSET      0x0000007C
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_INDEX       0x0000001F
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_RESET       0x0000A223

static inline u32 riu_rc_rc_rx_adc_fsm_state_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);
}

static inline void riu_rc_rc_rx_adc_fsm_state_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_OUT_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_2_RST    0x4
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_1_RST    0x2
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_OUT_RST    0x3

static inline void riu_rc_rc_rx_adc_fsm_state_1_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_adc_fsm_state_1_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_1_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_adc_fsm_state_1_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_1_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_adc_fsm_state_1_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_1_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_adc_fsm_state_1_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_1_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_adc_fsm_state_1_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_1_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_adc_fsm_state_1_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_1_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_adc_fsm_state_1_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_1_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_adc_fsm_state_1_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_1_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_adc_fsm_state_1_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_ADC_FSM_STATE_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 1
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x4
 *    06:04 NEXT_STATE_1              0x3
 *    03:00 OUT                       0x1
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000080)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_OFFSET      0x00000080
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_INDEX       0x00000020
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_RESET       0x0000A231

static inline u32 riu_rc_rc_rx_adc_fsm_state_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);
}

static inline void riu_rc_rc_rx_adc_fsm_state_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_OUT_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_2_RST    0x4
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_1_RST    0x3
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_OUT_RST    0x1

static inline void riu_rc_rc_rx_adc_fsm_state_2_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_adc_fsm_state_2_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_2_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_adc_fsm_state_2_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_2_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_adc_fsm_state_2_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_2_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_adc_fsm_state_2_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_2_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_adc_fsm_state_2_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_2_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_adc_fsm_state_2_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_2_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_adc_fsm_state_2_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_2_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_adc_fsm_state_2_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_2_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_adc_fsm_state_2_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_ADC_FSM_STATE_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 1
 *    13    TIMER_EN_TO_NEXT_STATE_1  0
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x4
 *    03:00 OUT                       0x9
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000084)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_OFFSET      0x00000084
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_INDEX       0x00000021
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_RESET       0x00004049

static inline u32 riu_rc_rc_rx_adc_fsm_state_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);
}

static inline void riu_rc_rc_rx_adc_fsm_state_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_OUT_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_1_RST    0x4
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_OUT_RST    0x9

static inline void riu_rc_rc_rx_adc_fsm_state_3_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_adc_fsm_state_3_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_3_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_adc_fsm_state_3_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_3_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_adc_fsm_state_3_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_3_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_adc_fsm_state_3_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_3_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_adc_fsm_state_3_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_3_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_adc_fsm_state_3_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_3_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_adc_fsm_state_3_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_3_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_adc_fsm_state_3_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_3_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_adc_fsm_state_3_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_ADC_FSM_STATE_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x5
 *    03:00 OUT                       0x9
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000088)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_OFFSET      0x00000088
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_INDEX       0x00000022
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_RESET       0x00002059

static inline u32 riu_rc_rc_rx_adc_fsm_state_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);
}

static inline void riu_rc_rc_rx_adc_fsm_state_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_OUT_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_1_RST    0x5
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_OUT_RST    0x9

static inline void riu_rc_rc_rx_adc_fsm_state_4_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_adc_fsm_state_4_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_4_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_adc_fsm_state_4_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_4_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_adc_fsm_state_4_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_4_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_adc_fsm_state_4_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_4_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_adc_fsm_state_4_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_4_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_adc_fsm_state_4_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_4_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_adc_fsm_state_4_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_4_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_adc_fsm_state_4_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_4_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_adc_fsm_state_4_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_ADC_FSM_STATE_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x0
 *    03:00 OUT                       0x3
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR        (REG_RIU_RC_BASE_ADDR + 0x0000008C)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_OFFSET      0x0000008C
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_INDEX       0x00000023
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_RESET       0x00002003

static inline u32 riu_rc_rc_rx_adc_fsm_state_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);
}

static inline void riu_rc_rc_rx_adc_fsm_state_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_OUT_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_OUT_RST    0x3

static inline void riu_rc_rc_rx_adc_fsm_state_5_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_adc_fsm_state_5_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_5_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_adc_fsm_state_5_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_5_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_adc_fsm_state_5_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_5_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_adc_fsm_state_5_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_5_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_adc_fsm_state_5_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_5_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_adc_fsm_state_5_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_5_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_adc_fsm_state_5_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_5_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_adc_fsm_state_5_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_adc_fsm_state_5_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_adc_fsm_state_5_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000090)
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_OFFSET      0x00000090
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_INDEX       0x00000024
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_RESET       0x00000000

static inline u32 riu_rc_rc_rx_adc_fsm_s_0_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_adc_fsm_s_0_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

static inline u32 riu_rc_rc_rx_adc_fsm_s_0_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_adc_fsm_s_0_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x3
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000094)
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_OFFSET      0x00000094
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_INDEX       0x00000025
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_RESET       0x00000003

static inline u32 riu_rc_rc_rx_adc_fsm_s_1_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_adc_fsm_s_1_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x3

static inline u32 riu_rc_rc_rx_adc_fsm_s_1_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_adc_fsm_s_1_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x3C0
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000098)
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_OFFSET      0x00000098
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_INDEX       0x00000026
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_RESET       0x000003C0

static inline u32 riu_rc_rc_rx_adc_fsm_s_2_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_adc_fsm_s_2_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x3C0

static inline u32 riu_rc_rc_rx_adc_fsm_s_2_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_adc_fsm_s_2_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x0000009C)
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_OFFSET      0x0000009C
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_INDEX       0x00000027
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_RESET       0x00000000

static inline u32 riu_rc_rc_rx_adc_fsm_s_3_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_adc_fsm_s_3_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

static inline u32 riu_rc_rc_rx_adc_fsm_s_3_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_adc_fsm_s_3_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000A0)
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_OFFSET      0x000000A0
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_INDEX       0x00000028
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_RESET       0x00000005

static inline u32 riu_rc_rc_rx_adc_fsm_s_4_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_adc_fsm_s_4_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

static inline u32 riu_rc_rc_rx_adc_fsm_s_4_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_adc_fsm_s_4_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000A4)
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_OFFSET      0x000000A4
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_INDEX       0x00000029
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_RESET       0x00000005

static inline u32 riu_rc_rc_rx_adc_fsm_s_5_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_adc_fsm_s_5_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

static inline u32 riu_rc_rc_rx_adc_fsm_s_5_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_adc_fsm_s_5_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_ADC_SW_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    GOTO_STATE_VALID          0
 *    02:00 GOTO_STATE                0x0
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_SW_CTRL_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000A8)
#define RIU_RC_RC_RX_ADC_SW_CTRL_OFFSET      0x000000A8
#define RIU_RC_RC_RX_ADC_SW_CTRL_INDEX       0x0000002A
#define RIU_RC_RC_RX_ADC_SW_CTRL_RESET       0x00000000

static inline u32 riu_rc_rc_rx_adc_sw_ctrl_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_ADC_SW_CTRL_ADDR);
}

static inline void riu_rc_rc_rx_adc_sw_ctrl_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_SW_CTRL_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_VALID_BIT    ((u32)0x00000008)
#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_VALID_POS    3
#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_MASK    ((u32)0x00000007)
#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_LSB    0
#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_WIDTH    ((u32)0x00000003)

#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_VALID_RST    0x0
#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_RST    0x0

static inline void riu_rc_rc_rx_adc_sw_ctrl_pack(struct cl_chip *chip, u8 goto_state_valid, u8 goto_state)
{
	ASSERT_ERR_CHIP((((u32)goto_state_valid << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)goto_state << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_SW_CTRL_ADDR, ((u32)goto_state_valid << 3) | ((u32)goto_state << 0));
}

static inline void riu_rc_rc_rx_adc_sw_ctrl_unpack(struct cl_chip *chip, u8 *goto_state_valid, u8 *goto_state)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_SW_CTRL_ADDR);

	*goto_state_valid = (local_val & ((u32)0x00000008)) >> 3;
	*goto_state = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 riu_rc_rc_rx_adc_sw_ctrl_goto_state_valid_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_SW_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void riu_rc_rc_rx_adc_sw_ctrl_goto_state_valid_setf(struct cl_chip *chip, u8 gotostatevalid)
{
	ASSERT_ERR_CHIP((((u32)gotostatevalid << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_SW_CTRL_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_SW_CTRL_ADDR) & ~((u32)0x00000008)) | ((u32)gotostatevalid << 3));
}

static inline u8 riu_rc_rc_rx_adc_sw_ctrl_goto_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_ADC_SW_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void riu_rc_rc_rx_adc_sw_ctrl_goto_state_setf(struct cl_chip *chip, u8 gotostate)
{
	ASSERT_ERR_CHIP((((u32)gotostate << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_ADC_SW_CTRL_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_ADC_SW_CTRL_ADDR) & ~((u32)0x00000007)) | ((u32)gotostate << 0));
}

/**
 * @brief RC_RX_RF_FSM_STATE_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 1
 *    13    TIMER_EN_TO_NEXT_STATE_1  0
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x1
 *    03:00 OUT                       0x0
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000AC)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_OFFSET      0x000000AC
#define RIU_RC_RC_RX_RF_FSM_STATE_0_INDEX       0x0000002B
#define RIU_RC_RC_RX_RF_FSM_STATE_0_RESET       0x00004010

static inline u32 riu_rc_rc_rx_rf_fsm_state_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_state_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_0_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_0_OUT_RST    0x0

static inline void riu_rc_rc_rx_rf_fsm_state_0_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_rf_fsm_state_0_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_0_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_rf_fsm_state_0_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_0_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_rf_fsm_state_0_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_0_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_rf_fsm_state_0_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_0_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_rf_fsm_state_0_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_0_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_rf_fsm_state_0_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_0_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_rf_fsm_state_0_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_0_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_rf_fsm_state_0_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_0_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_state_0_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_RF_FSM_STATE_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 1
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x5
 *    06:04 NEXT_STATE_1              0x2
 *    03:00 OUT                       0x0
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000B0)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_OFFSET      0x000000B0
#define RIU_RC_RC_RX_RF_FSM_STATE_1_INDEX       0x0000002C
#define RIU_RC_RC_RX_RF_FSM_STATE_1_RESET       0x0000A2A0

static inline u32 riu_rc_rc_rx_rf_fsm_state_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_state_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_1_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_2_RST    0x5
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_1_RST    0x2
#define RIU_RC_RC_RX_RF_FSM_STATE_1_OUT_RST    0x0

static inline void riu_rc_rc_rx_rf_fsm_state_1_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_rf_fsm_state_1_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_1_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_rf_fsm_state_1_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_1_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_rf_fsm_state_1_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_1_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_rf_fsm_state_1_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_1_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_rf_fsm_state_1_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_1_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_rf_fsm_state_1_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_1_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_rf_fsm_state_1_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_1_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_rf_fsm_state_1_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_1_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_state_1_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_RF_FSM_STATE_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 1
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 1
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 1
 *    13    TIMER_EN_TO_NEXT_STATE_1  0
 *    12:10 NEXT_STATE_3              0x4
 *    09:07 NEXT_STATE_2              0x3
 *    06:04 NEXT_STATE_1              0x5
 *    03:00 OUT                       0x1
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000B4)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_OFFSET      0x000000B4
#define RIU_RC_RC_RX_RF_FSM_STATE_2_INDEX       0x0000002D
#define RIU_RC_RC_RX_RF_FSM_STATE_2_RESET       0x0001D1D1

static inline u32 riu_rc_rc_rx_rf_fsm_state_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_state_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_2_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_3_RST    0x4
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_2_RST    0x3
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_1_RST    0x5
#define RIU_RC_RC_RX_RF_FSM_STATE_2_OUT_RST    0x1

static inline void riu_rc_rc_rx_rf_fsm_state_2_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_rf_fsm_state_2_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_2_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_rf_fsm_state_2_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_2_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_rf_fsm_state_2_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_2_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_rf_fsm_state_2_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_2_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_rf_fsm_state_2_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_2_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_rf_fsm_state_2_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_2_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_rf_fsm_state_2_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_2_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_rf_fsm_state_2_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_2_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_state_2_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_RF_FSM_STATE_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 1
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x5
 *    06:04 NEXT_STATE_1              0x2
 *    03:00 OUT                       0x1
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000B8)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_OFFSET      0x000000B8
#define RIU_RC_RC_RX_RF_FSM_STATE_3_INDEX       0x0000002E
#define RIU_RC_RC_RX_RF_FSM_STATE_3_RESET       0x0000A2A1

static inline u32 riu_rc_rc_rx_rf_fsm_state_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_state_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_3_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_2_RST    0x5
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_1_RST    0x2
#define RIU_RC_RC_RX_RF_FSM_STATE_3_OUT_RST    0x1

static inline void riu_rc_rc_rx_rf_fsm_state_3_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_rf_fsm_state_3_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_3_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_rf_fsm_state_3_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_3_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_rf_fsm_state_3_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_3_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_rf_fsm_state_3_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_3_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_rf_fsm_state_3_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_3_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_rf_fsm_state_3_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_3_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_rf_fsm_state_3_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_3_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_rf_fsm_state_3_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_3_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_state_3_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_RF_FSM_STATE_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 1
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x5
 *    06:04 NEXT_STATE_1              0x2
 *    03:00 OUT                       0x1
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000BC)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_OFFSET      0x000000BC
#define RIU_RC_RC_RX_RF_FSM_STATE_4_INDEX       0x0000002F
#define RIU_RC_RC_RX_RF_FSM_STATE_4_RESET       0x0000A2A1

static inline u32 riu_rc_rc_rx_rf_fsm_state_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_state_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_4_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_2_RST    0x5
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_1_RST    0x2
#define RIU_RC_RC_RX_RF_FSM_STATE_4_OUT_RST    0x1

static inline void riu_rc_rc_rx_rf_fsm_state_4_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_rf_fsm_state_4_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_4_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_rf_fsm_state_4_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_4_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_rf_fsm_state_4_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_4_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_rf_fsm_state_4_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_4_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_rf_fsm_state_4_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_4_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_rf_fsm_state_4_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_4_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_rf_fsm_state_4_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_4_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_rf_fsm_state_4_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_4_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_state_4_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_RF_FSM_STATE_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x6
 *    03:00 OUT                       0x1
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000C0)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_OFFSET      0x000000C0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_INDEX       0x00000030
#define RIU_RC_RC_RX_RF_FSM_STATE_5_RESET       0x00002061

static inline u32 riu_rc_rc_rx_rf_fsm_state_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_state_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_1_RST    0x6
#define RIU_RC_RC_RX_RF_FSM_STATE_5_OUT_RST    0x1

static inline void riu_rc_rc_rx_rf_fsm_state_5_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_rf_fsm_state_5_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_5_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_rf_fsm_state_5_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_5_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_rf_fsm_state_5_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_5_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_rf_fsm_state_5_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_5_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_rf_fsm_state_5_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_5_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_rf_fsm_state_5_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_5_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_rf_fsm_state_5_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_5_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_rf_fsm_state_5_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_5_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_state_5_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_RF_FSM_STATE_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x0
 *    03:00 OUT                       0x0
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000C4)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_OFFSET      0x000000C4
#define RIU_RC_RC_RX_RF_FSM_STATE_6_INDEX       0x00000031
#define RIU_RC_RC_RX_RF_FSM_STATE_6_RESET       0x00002000

static inline u32 riu_rc_rc_rx_rf_fsm_state_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_state_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_6_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_OUT_RST    0x0

static inline void riu_rc_rc_rx_rf_fsm_state_6_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_rx_rf_fsm_state_6_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_6_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_rx_rf_fsm_state_6_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_6_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_rx_rf_fsm_state_6_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_6_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_rx_rf_fsm_state_6_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_6_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_rx_rf_fsm_state_6_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_6_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_rx_rf_fsm_state_6_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_6_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_rx_rf_fsm_state_6_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_6_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_rx_rf_fsm_state_6_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_rx_rf_fsm_state_6_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_state_6_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000C8)
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_OFFSET      0x000000C8
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_INDEX       0x00000032
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_RESET       0x00000000

static inline u32 riu_rc_rc_rx_rf_fsm_s_0_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_s_0_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

static inline u32 riu_rc_rc_rx_rf_fsm_s_0_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_s_0_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0xA
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000CC)
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_OFFSET      0x000000CC
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_INDEX       0x00000033
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_RESET       0x0000000A

static inline u32 riu_rc_rc_rx_rf_fsm_s_1_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_s_1_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0xA

static inline u32 riu_rc_rc_rx_rf_fsm_s_1_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_s_1_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000D0)
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_OFFSET      0x000000D0
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_INDEX       0x00000034
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_RESET       0x00000000

static inline u32 riu_rc_rc_rx_rf_fsm_s_2_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_s_2_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

static inline u32 riu_rc_rc_rx_rf_fsm_s_2_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_s_2_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x20
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000D4)
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_OFFSET      0x000000D4
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_INDEX       0x00000035
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_RESET       0x00000020

static inline u32 riu_rc_rc_rx_rf_fsm_s_3_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_s_3_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x20

static inline u32 riu_rc_rc_rx_rf_fsm_s_3_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_s_3_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x10
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000D8)
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_OFFSET      0x000000D8
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_INDEX       0x00000036
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_RESET       0x00000010

static inline u32 riu_rc_rc_rx_rf_fsm_s_4_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_s_4_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x10

static inline u32 riu_rc_rc_rx_rf_fsm_s_4_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_s_4_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0xA
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000DC)
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_OFFSET      0x000000DC
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_INDEX       0x00000037
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_RESET       0x0000000A

static inline u32 riu_rc_rc_rx_rf_fsm_s_5_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_s_5_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0xA

static inline u32 riu_rc_rc_rx_rf_fsm_s_5_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_s_5_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000E0)
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_OFFSET      0x000000E0
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_INDEX       0x00000038
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_RESET       0x00000005

static inline u32 riu_rc_rc_rx_rf_fsm_s_6_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_rx_rf_fsm_s_6_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

static inline u32 riu_rc_rc_rx_rf_fsm_s_6_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_rf_fsm_s_6_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_SW_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    GOTO_STATE_VALID          0
 *    02:00 GOTO_STATE                0x0
 * </pre>
 */
#define RIU_RC_RC_RX_RF_SW_CTRL_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000E4)
#define RIU_RC_RC_RX_RF_SW_CTRL_OFFSET      0x000000E4
#define RIU_RC_RC_RX_RF_SW_CTRL_INDEX       0x00000039
#define RIU_RC_RC_RX_RF_SW_CTRL_RESET       0x00000000

static inline u32 riu_rc_rc_rx_rf_sw_ctrl_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_RF_SW_CTRL_ADDR);
}

static inline void riu_rc_rc_rx_rf_sw_ctrl_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_RF_SW_CTRL_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_VALID_BIT    ((u32)0x00000008)
#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_VALID_POS    3
#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_MASK    ((u32)0x00000007)
#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_LSB    0
#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_WIDTH    ((u32)0x00000003)

#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_VALID_RST    0x0
#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_RST    0x0

static inline void riu_rc_rc_rx_rf_sw_ctrl_pack(struct cl_chip *chip, u8 goto_state_valid, u8 goto_state)
{
	ASSERT_ERR_CHIP((((u32)goto_state_valid << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)goto_state << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_SW_CTRL_ADDR, ((u32)goto_state_valid << 3) | ((u32)goto_state << 0));
}

static inline void riu_rc_rc_rx_rf_sw_ctrl_unpack(struct cl_chip *chip, u8 *goto_state_valid, u8 *goto_state)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_SW_CTRL_ADDR);

	*goto_state_valid = (local_val & ((u32)0x00000008)) >> 3;
	*goto_state = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 riu_rc_rc_rx_rf_sw_ctrl_goto_state_valid_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_SW_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void riu_rc_rc_rx_rf_sw_ctrl_goto_state_valid_setf(struct cl_chip *chip, u8 gotostatevalid)
{
	ASSERT_ERR_CHIP((((u32)gotostatevalid << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_SW_CTRL_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_SW_CTRL_ADDR) & ~((u32)0x00000008)) | ((u32)gotostatevalid << 3));
}

static inline u8 riu_rc_rc_rx_rf_sw_ctrl_goto_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_RF_SW_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void riu_rc_rc_rx_rf_sw_ctrl_goto_state_setf(struct cl_chip *chip, u8 gotostate)
{
	ASSERT_ERR_CHIP((((u32)gotostate << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_RF_SW_CTRL_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_RF_SW_CTRL_ADDR) & ~((u32)0x00000007)) | ((u32)gotostate << 0));
}

/**
 * @brief RC_RX_FSM_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:03 RX_RF_FSM_STAT            0x0
 *    02:00 RX_ADC_FSM_STAT           0x0
 * </pre>
 */
#define RIU_RC_RC_RX_FSM_STATUS_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000E8)
#define RIU_RC_RC_RX_FSM_STATUS_OFFSET      0x000000E8
#define RIU_RC_RC_RX_FSM_STATUS_INDEX       0x0000003A
#define RIU_RC_RC_RX_FSM_STATUS_RESET       0x00000000

static inline u32 riu_rc_rc_rx_fsm_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_FSM_STATUS_ADDR);
}

/* Field definitions */
#define RIU_RC_RC_RX_FSM_STATUS_RX_RF_FSM_STAT_MASK    ((u32)0x00000038)
#define RIU_RC_RC_RX_FSM_STATUS_RX_RF_FSM_STAT_LSB    3
#define RIU_RC_RC_RX_FSM_STATUS_RX_RF_FSM_STAT_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_RX_FSM_STATUS_RX_ADC_FSM_STAT_MASK    ((u32)0x00000007)
#define RIU_RC_RC_RX_FSM_STATUS_RX_ADC_FSM_STAT_LSB    0
#define RIU_RC_RC_RX_FSM_STATUS_RX_ADC_FSM_STAT_WIDTH    ((u32)0x00000003)

#define RIU_RC_RC_RX_FSM_STATUS_RX_RF_FSM_STAT_RST    0x0
#define RIU_RC_RC_RX_FSM_STATUS_RX_ADC_FSM_STAT_RST    0x0

static inline void riu_rc_rc_rx_fsm_status_unpack(struct cl_chip *chip, u8 *rx_rf_fsm_stat, u8 *rx_adc_fsm_stat)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_FSM_STATUS_ADDR);

	*rx_rf_fsm_stat = (local_val & ((u32)0x00000038)) >> 3;
	*rx_adc_fsm_stat = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 riu_rc_rc_rx_fsm_status_rx_rf_fsm_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_FSM_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline u8 riu_rc_rc_rx_fsm_status_rx_adc_fsm_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_FSM_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

/**
 * @brief RC_RX_TO_RIU_TIMERS_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RC_RX_ACK_ON_CLKS         0x79
 * </pre>
 */
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000EC)
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_OFFSET      0x000000EC
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_INDEX       0x0000003B
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_RESET       0x00000079

static inline u32 riu_rc_rc_rx_to_riu_timers_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_TO_RIU_TIMERS_0_ADDR);
}

static inline void riu_rc_rc_rx_to_riu_timers_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_TO_RIU_TIMERS_0_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_RC_RX_ACK_ON_CLKS_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_RC_RX_ACK_ON_CLKS_LSB    0
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_RC_RX_ACK_ON_CLKS_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_RC_RX_ACK_ON_CLKS_RST    0x79

static inline u32 riu_rc_rc_rx_to_riu_timers_0_rc_rx_ack_on_clks_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_TO_RIU_TIMERS_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_to_riu_timers_0_rc_rx_ack_on_clks_setf(struct cl_chip *chip, u32 rcrxackonclks)
{
	ASSERT_ERR_CHIP((((u32)rcrxackonclks << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_TO_RIU_TIMERS_0_ADDR, (u32)rcrxackonclks << 0);
}

/**
 * @brief RC_RX_TO_RIU_TIMERS_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RC_RX_ACK_OFF_CLKS        0xf
 * </pre>
 */
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000F0)
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_OFFSET      0x000000F0
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_INDEX       0x0000003C
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_RESET       0x0000000F

static inline u32 riu_rc_rc_rx_to_riu_timers_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_TO_RIU_TIMERS_1_ADDR);
}

static inline void riu_rc_rc_rx_to_riu_timers_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_TO_RIU_TIMERS_1_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_RC_RX_ACK_OFF_CLKS_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_RC_RX_ACK_OFF_CLKS_LSB    0
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_RC_RX_ACK_OFF_CLKS_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_RC_RX_ACK_OFF_CLKS_RST    0xf

static inline u32 riu_rc_rc_rx_to_riu_timers_1_rc_rx_ack_off_clks_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_TO_RIU_TIMERS_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_rx_to_riu_timers_1_rc_rx_ack_off_clks_setf(struct cl_chip *chip, u32 rcrxackoffclks)
{
	ASSERT_ERR_CHIP((((u32)rcrxackoffclks << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_TO_RIU_TIMERS_1_ADDR, (u32)rcrxackoffclks << 0);
}

/**
 * @brief RC_RX_FORCE_GAIN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    18    RX_GAIN_FORCE_EN          0
 *    17:09 FORCE_RX_GAIN_1           0x0
 *    08:00 FORCE_RX_GAIN_0           0x0
 * </pre>
 */
#define RIU_RC_RC_RX_FORCE_GAIN_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000F4)
#define RIU_RC_RC_RX_FORCE_GAIN_OFFSET      0x000000F4
#define RIU_RC_RC_RX_FORCE_GAIN_INDEX       0x0000003D
#define RIU_RC_RC_RX_FORCE_GAIN_RESET       0x00000000

static inline u32 riu_rc_rc_rx_force_gain_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR);
}

static inline void riu_rc_rc_rx_force_gain_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_FORCE_GAIN_RX_GAIN_FORCE_EN_BIT    ((u32)0x00040000)
#define RIU_RC_RC_RX_FORCE_GAIN_RX_GAIN_FORCE_EN_POS    18
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_1_MASK    ((u32)0x0003FE00)
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_1_LSB    9
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_1_WIDTH    ((u32)0x00000009)
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_0_MASK    ((u32)0x000001FF)
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_0_LSB    0
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_0_WIDTH    ((u32)0x00000009)

#define RIU_RC_RC_RX_FORCE_GAIN_RX_GAIN_FORCE_EN_RST    0x0
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_1_RST    0x0
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_0_RST    0x0

static inline void riu_rc_rc_rx_force_gain_pack(struct cl_chip *chip, u8 rx_gain_force_en, u16 force_rx_gain_1, u16 force_rx_gain_0)
{
	ASSERT_ERR_CHIP((((u32)rx_gain_force_en << 18) & ~((u32)0x00040000)) == 0);
	ASSERT_ERR_CHIP((((u32)force_rx_gain_1 << 9) & ~((u32)0x0003FE00)) == 0);
	ASSERT_ERR_CHIP((((u32)force_rx_gain_0 << 0) & ~((u32)0x000001FF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR, ((u32)rx_gain_force_en << 18) | ((u32)force_rx_gain_1 << 9) | ((u32)force_rx_gain_0 << 0));
}

static inline void riu_rc_rc_rx_force_gain_unpack(struct cl_chip *chip, u8 *rx_gain_force_en, u16 *force_rx_gain_1, u16 *force_rx_gain_0)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR);

	*rx_gain_force_en = (local_val & ((u32)0x00040000)) >> 18;
	*force_rx_gain_1 = (local_val & ((u32)0x0003FE00)) >> 9;
	*force_rx_gain_0 = (local_val & ((u32)0x000001FF)) >> 0;
}

static inline u8 riu_rc_rc_rx_force_gain_rx_gain_force_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR);

	return (u8)((local_val & ((u32)0x00040000)) >> 18);
}

static inline void riu_rc_rc_rx_force_gain_rx_gain_force_en_setf(struct cl_chip *chip, u8 rxgainforceen)
{
	ASSERT_ERR_CHIP((((u32)rxgainforceen << 18) & ~((u32)0x00040000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR) & ~((u32)0x00040000)) | ((u32)rxgainforceen << 18));
}

static inline u16 riu_rc_rc_rx_force_gain_force_rx_gain_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR);

	return (u16)((local_val & ((u32)0x0003FE00)) >> 9);
}

static inline void riu_rc_rc_rx_force_gain_force_rx_gain_1_setf(struct cl_chip *chip, u16 forcerxgain1)
{
	ASSERT_ERR_CHIP((((u32)forcerxgain1 << 9) & ~((u32)0x0003FE00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR) & ~((u32)0x0003FE00)) | ((u32)forcerxgain1 << 9));
}

static inline u16 riu_rc_rc_rx_force_gain_force_rx_gain_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR);

	return (u16)((local_val & ((u32)0x000001FF)) >> 0);
}

static inline void riu_rc_rc_rx_force_gain_force_rx_gain_0_setf(struct cl_chip *chip, u16 forcerxgain0)
{
	ASSERT_ERR_CHIP((((u32)forcerxgain0 << 0) & ~((u32)0x000001FF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_FORCE_GAIN_ADDR) & ~((u32)0x000001FF)) | ((u32)forcerxgain0 << 0));
}

/**
 * @brief RC_RX_INITIAL_GAIN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:09 INITIAL_RX_GAIN_1         0x0
 *    08:00 INITIAL_RX_GAIN_0         0x0
 * </pre>
 */
#define RIU_RC_RC_RX_INITIAL_GAIN_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000F8)
#define RIU_RC_RC_RX_INITIAL_GAIN_OFFSET      0x000000F8
#define RIU_RC_RC_RX_INITIAL_GAIN_INDEX       0x0000003E
#define RIU_RC_RC_RX_INITIAL_GAIN_RESET       0x00000000

static inline u32 riu_rc_rc_rx_initial_gain_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_INITIAL_GAIN_ADDR);
}

static inline void riu_rc_rc_rx_initial_gain_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_INITIAL_GAIN_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_1_MASK    ((u32)0x0003FE00)
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_1_LSB    9
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_1_WIDTH    ((u32)0x00000009)
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_0_MASK    ((u32)0x000001FF)
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_0_LSB    0
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_0_WIDTH    ((u32)0x00000009)

#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_1_RST    0x0
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_0_RST    0x0

static inline void riu_rc_rc_rx_initial_gain_pack(struct cl_chip *chip, u16 initial_rx_gain_1, u16 initial_rx_gain_0)
{
	ASSERT_ERR_CHIP((((u32)initial_rx_gain_1 << 9) & ~((u32)0x0003FE00)) == 0);
	ASSERT_ERR_CHIP((((u32)initial_rx_gain_0 << 0) & ~((u32)0x000001FF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_INITIAL_GAIN_ADDR, ((u32)initial_rx_gain_1 << 9) | ((u32)initial_rx_gain_0 << 0));
}

static inline void riu_rc_rc_rx_initial_gain_unpack(struct cl_chip *chip, u16 *initial_rx_gain_1, u16 *initial_rx_gain_0)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_INITIAL_GAIN_ADDR);

	*initial_rx_gain_1 = (local_val & ((u32)0x0003FE00)) >> 9;
	*initial_rx_gain_0 = (local_val & ((u32)0x000001FF)) >> 0;
}

static inline u16 riu_rc_rc_rx_initial_gain_initial_rx_gain_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_INITIAL_GAIN_ADDR);

	return (u16)((local_val & ((u32)0x0003FE00)) >> 9);
}

static inline void riu_rc_rc_rx_initial_gain_initial_rx_gain_1_setf(struct cl_chip *chip, u16 initialrxgain1)
{
	ASSERT_ERR_CHIP((((u32)initialrxgain1 << 9) & ~((u32)0x0003FE00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_INITIAL_GAIN_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_INITIAL_GAIN_ADDR) & ~((u32)0x0003FE00)) | ((u32)initialrxgain1 << 9));
}

static inline u16 riu_rc_rc_rx_initial_gain_initial_rx_gain_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_INITIAL_GAIN_ADDR);

	return (u16)((local_val & ((u32)0x000001FF)) >> 0);
}

static inline void riu_rc_rc_rx_initial_gain_initial_rx_gain_0_setf(struct cl_chip *chip, u16 initialrxgain0)
{
	ASSERT_ERR_CHIP((((u32)initialrxgain0 << 0) & ~((u32)0x000001FF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_INITIAL_GAIN_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_INITIAL_GAIN_ADDR) & ~((u32)0x000001FF)) | ((u32)initialrxgain0 << 0));
}

/**
 * @brief RC_RX_INITIAL_FRAC_FREQ register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    INITIAL_RX_FRAC_FREQ      0
 * </pre>
 */
#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_ADDR        (REG_RIU_RC_BASE_ADDR + 0x000000FC)
#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_OFFSET      0x000000FC
#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_INDEX       0x0000003F
#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_RESET       0x00000000

static inline u32 riu_rc_rc_rx_initial_frac_freq_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_INITIAL_FRAC_FREQ_ADDR);
}

static inline void riu_rc_rc_rx_initial_frac_freq_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_INITIAL_FRAC_FREQ_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_INITIAL_RX_FRAC_FREQ_BIT    ((u32)0x00000001)
#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_INITIAL_RX_FRAC_FREQ_POS    0

#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_INITIAL_RX_FRAC_FREQ_RST    0x0

static inline u8 riu_rc_rc_rx_initial_frac_freq_initial_rx_frac_freq_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_INITIAL_FRAC_FREQ_ADDR);

	return (u8)(local_val >> 0);
}

static inline void riu_rc_rc_rx_initial_frac_freq_initial_rx_frac_freq_setf(struct cl_chip *chip, u8 initialrxfracfreq)
{
	ASSERT_ERR_CHIP((((u32)initialrxfracfreq << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_INITIAL_FRAC_FREQ_ADDR, (u32)initialrxfracfreq << 0);
}

/**
 * @brief RC_RX_GAIN_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:09 CH_1_RX_GAIN_STAT         0x0
 *    08:00 CH_0_RX_GAIN_STAT         0x0
 * </pre>
 */
#define RIU_RC_RC_RX_GAIN_STATUS_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000100)
#define RIU_RC_RC_RX_GAIN_STATUS_OFFSET      0x00000100
#define RIU_RC_RC_RX_GAIN_STATUS_INDEX       0x00000040
#define RIU_RC_RC_RX_GAIN_STATUS_RESET       0x00000000

static inline u32 riu_rc_rc_rx_gain_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_GAIN_STATUS_ADDR);
}

/* Field definitions */
#define RIU_RC_RC_RX_GAIN_STATUS_CH_1_RX_GAIN_STAT_MASK    ((u32)0x0003FE00)
#define RIU_RC_RC_RX_GAIN_STATUS_CH_1_RX_GAIN_STAT_LSB    9
#define RIU_RC_RC_RX_GAIN_STATUS_CH_1_RX_GAIN_STAT_WIDTH    ((u32)0x00000009)
#define RIU_RC_RC_RX_GAIN_STATUS_CH_0_RX_GAIN_STAT_MASK    ((u32)0x000001FF)
#define RIU_RC_RC_RX_GAIN_STATUS_CH_0_RX_GAIN_STAT_LSB    0
#define RIU_RC_RC_RX_GAIN_STATUS_CH_0_RX_GAIN_STAT_WIDTH    ((u32)0x00000009)

#define RIU_RC_RC_RX_GAIN_STATUS_CH_1_RX_GAIN_STAT_RST    0x0
#define RIU_RC_RC_RX_GAIN_STATUS_CH_0_RX_GAIN_STAT_RST    0x0

static inline void riu_rc_rc_rx_gain_status_unpack(struct cl_chip *chip, u16 *ch_1_rx_gain_stat, u16 *ch_0_rx_gain_stat)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_GAIN_STATUS_ADDR);

	*ch_1_rx_gain_stat = (local_val & ((u32)0x0003FE00)) >> 9;
	*ch_0_rx_gain_stat = (local_val & ((u32)0x000001FF)) >> 0;
}

static inline u16 riu_rc_rc_rx_gain_status_ch_1_rx_gain_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_GAIN_STATUS_ADDR);

	return (u16)((local_val & ((u32)0x0003FE00)) >> 9);
}

static inline u16 riu_rc_rc_rx_gain_status_ch_0_rx_gain_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_GAIN_STATUS_ADDR);

	return (u16)((local_val & ((u32)0x000001FF)) >> 0);
}

/**
 * @brief RC_UNALLOCATED_CHAIN_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    rc_sw_enable              1
 *    28:25 ADC_OUT                   0x0
 *    24:21 DAC_OUT                   0x0
 *    20:13 RF_OUT_3                  0x0
 *    12:04 RF_OUT_2                  0x0
 *    03:01 RF_OUT_1                  0x0
 *    00    RF_OUT_0                  0
 * </pre>
 */
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000104)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_OFFSET      0x00000104
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_INDEX       0x00000041
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RESET       0x80000000

static inline u32 riu_rc_rc_unallocated_chain_config_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);
}

static inline void riu_rc_rc_unallocated_chain_config_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RC_SW_ENABLE_BIT    ((u32)0x80000000)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RC_SW_ENABLE_POS    31
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADC_OUT_MASK    ((u32)0x1E000000)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADC_OUT_LSB    25
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADC_OUT_WIDTH    ((u32)0x00000004)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_DAC_OUT_MASK    ((u32)0x01E00000)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_DAC_OUT_LSB    21
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_DAC_OUT_WIDTH    ((u32)0x00000004)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_3_MASK    ((u32)0x001FE000)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_3_LSB    13
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_3_WIDTH    ((u32)0x00000008)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_2_MASK    ((u32)0x00001FF0)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_2_LSB    4
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_2_WIDTH    ((u32)0x00000009)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_1_MASK    ((u32)0x0000000E)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_1_LSB    1
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_0_BIT    ((u32)0x00000001)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_0_POS    0

#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RC_SW_ENABLE_RST    0x1
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADC_OUT_RST    0x0
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_DAC_OUT_RST    0x0
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_3_RST    0x0
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_2_RST    0x0
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_1_RST    0x0
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_0_RST    0x0

static inline void riu_rc_rc_unallocated_chain_config_pack(struct cl_chip *chip, u8 rc_sw_enable, u8 adc_out, u8 dac_out, u8 rf_out_3, u16 rf_out_2, u8 rf_out_1, u8 rf_out_0)
{
	ASSERT_ERR_CHIP((((u32)rc_sw_enable << 31) & ~((u32)0x80000000)) == 0);
	ASSERT_ERR_CHIP((((u32)adc_out << 25) & ~((u32)0x1E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)dac_out << 21) & ~((u32)0x01E00000)) == 0);
	ASSERT_ERR_CHIP((((u32)rf_out_3 << 13) & ~((u32)0x001FE000)) == 0);
	ASSERT_ERR_CHIP((((u32)rf_out_2 << 4) & ~((u32)0x00001FF0)) == 0);
	ASSERT_ERR_CHIP((((u32)rf_out_1 << 1) & ~((u32)0x0000000E)) == 0);
	ASSERT_ERR_CHIP((((u32)rf_out_0 << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, ((u32)rc_sw_enable << 31) | ((u32)adc_out << 25) | ((u32)dac_out << 21) | ((u32)rf_out_3 << 13) | ((u32)rf_out_2 << 4) | ((u32)rf_out_1 << 1) | ((u32)rf_out_0 << 0));
}

static inline void riu_rc_rc_unallocated_chain_config_unpack(struct cl_chip *chip, u8 *rc_sw_enable, u8 *adc_out, u8 *dac_out, u8 *rf_out_3, u16 *rf_out_2, u8 *rf_out_1, u8 *rf_out_0)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);

	*rc_sw_enable = (local_val & ((u32)0x80000000)) >> 31;
	*adc_out = (local_val & ((u32)0x1E000000)) >> 25;
	*dac_out = (local_val & ((u32)0x01E00000)) >> 21;
	*rf_out_3 = (local_val & ((u32)0x001FE000)) >> 13;
	*rf_out_2 = (local_val & ((u32)0x00001FF0)) >> 4;
	*rf_out_1 = (local_val & ((u32)0x0000000E)) >> 1;
	*rf_out_0 = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 riu_rc_rc_unallocated_chain_config_rc_sw_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);

	return (u8)((local_val & ((u32)0x80000000)) >> 31);
}

static inline void riu_rc_rc_unallocated_chain_config_rc_sw_enable_setf(struct cl_chip *chip, u8 rcswenable)
{
	ASSERT_ERR_CHIP((((u32)rcswenable << 31) & ~((u32)0x80000000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((u32)0x80000000)) | ((u32)rcswenable << 31));
}

static inline u8 riu_rc_rc_unallocated_chain_config_adc_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);

	return (u8)((local_val & ((u32)0x1E000000)) >> 25);
}

static inline void riu_rc_rc_unallocated_chain_config_adc_out_setf(struct cl_chip *chip, u8 adcout)
{
	ASSERT_ERR_CHIP((((u32)adcout << 25) & ~((u32)0x1E000000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((u32)0x1E000000)) | ((u32)adcout << 25));
}

static inline u8 riu_rc_rc_unallocated_chain_config_dac_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);

	return (u8)((local_val & ((u32)0x01E00000)) >> 21);
}

static inline void riu_rc_rc_unallocated_chain_config_dac_out_setf(struct cl_chip *chip, u8 dacout)
{
	ASSERT_ERR_CHIP((((u32)dacout << 21) & ~((u32)0x01E00000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((u32)0x01E00000)) | ((u32)dacout << 21));
}

static inline u8 riu_rc_rc_unallocated_chain_config_rf_out_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);

	return (u8)((local_val & ((u32)0x001FE000)) >> 13);
}

static inline void riu_rc_rc_unallocated_chain_config_rf_out_3_setf(struct cl_chip *chip, u8 rfout3)
{
	ASSERT_ERR_CHIP((((u32)rfout3 << 13) & ~((u32)0x001FE000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((u32)0x001FE000)) | ((u32)rfout3 << 13));
}

static inline u16 riu_rc_rc_unallocated_chain_config_rf_out_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);

	return (u16)((local_val & ((u32)0x00001FF0)) >> 4);
}

static inline void riu_rc_rc_unallocated_chain_config_rf_out_2_setf(struct cl_chip *chip, u16 rfout2)
{
	ASSERT_ERR_CHIP((((u32)rfout2 << 4) & ~((u32)0x00001FF0)) == 0);
	cl_reg_write(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((u32)0x00001FF0)) | ((u32)rfout2 << 4));
}

static inline u8 riu_rc_rc_unallocated_chain_config_rf_out_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);

	return (u8)((local_val & ((u32)0x0000000E)) >> 1);
}

static inline void riu_rc_rc_unallocated_chain_config_rf_out_1_setf(struct cl_chip *chip, u8 rfout1)
{
	ASSERT_ERR_CHIP((((u32)rfout1 << 1) & ~((u32)0x0000000E)) == 0);
	cl_reg_write(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((u32)0x0000000E)) | ((u32)rfout1 << 1));
}

static inline u8 riu_rc_rc_unallocated_chain_config_rf_out_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void riu_rc_rc_unallocated_chain_config_rf_out_0_setf(struct cl_chip *chip, u8 rfout0)
{
	ASSERT_ERR_CHIP((((u32)rfout0 << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (cl_reg_read(chip, RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((u32)0x00000001)) | ((u32)rfout0 << 0));
}

/**
 * @brief RC_RX_SW_GAIN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    18    RX_SW_GAIN_UPDATE         0
 *    17:09 RX_SW_GAIN_CH1            0x0
 *    08:00 RX_SW_GAIN_CH0            0x0
 * </pre>
 */
#define RIU_RC_RC_RX_SW_GAIN_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000108)
#define RIU_RC_RC_RX_SW_GAIN_OFFSET      0x00000108
#define RIU_RC_RC_RX_SW_GAIN_INDEX       0x00000042
#define RIU_RC_RC_RX_SW_GAIN_RESET       0x00000000

static inline u32 riu_rc_rc_rx_sw_gain_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_RX_SW_GAIN_ADDR);
}

static inline void riu_rc_rc_rx_sw_gain_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_RX_SW_GAIN_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_UPDATE_BIT    ((u32)0x00040000)
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_UPDATE_POS    18
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_1_MASK    ((u32)0x0003FE00)
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_1_LSB    9
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_1_WIDTH    ((u32)0x00000009)
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_0_MASK    ((u32)0x000001FF)
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_0_LSB    0
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_0_WIDTH    ((u32)0x00000009)

#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_UPDATE_RST    0x0
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_1_RST    0x0
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_0_RST    0x0

static inline void riu_rc_rc_rx_sw_gain_pack(struct cl_chip *chip, u8 rx_sw_gain_update, u16 rx_sw_gain_ch1, u16 rx_sw_gain_ch0)
{
	ASSERT_ERR_CHIP((((u32)rx_sw_gain_update << 18) & ~((u32)0x00040000)) == 0);
	ASSERT_ERR_CHIP((((u32)rx_sw_gain_ch1 << 9) & ~((u32)0x0003FE00)) == 0);
	ASSERT_ERR_CHIP((((u32)rx_sw_gain_ch0 << 0) & ~((u32)0x000001FF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_SW_GAIN_ADDR, ((u32)rx_sw_gain_update << 18) | ((u32)rx_sw_gain_ch1 << 9) | ((u32)rx_sw_gain_ch0 << 0));
}

static inline void riu_rc_rc_rx_sw_gain_unpack(struct cl_chip *chip, u8 *rx_sw_gain_update, u16 *rx_sw_gain_ch1, u16 *rx_sw_gain_ch0)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_SW_GAIN_ADDR);

	*rx_sw_gain_update = (local_val & ((u32)0x00040000)) >> 18;
	*rx_sw_gain_ch1 = (local_val & ((u32)0x0003FE00)) >> 9;
	*rx_sw_gain_ch0 = (local_val & ((u32)0x000001FF)) >> 0;
}

static inline u8 riu_rc_rc_rx_sw_gain_rx_sw_gain_update_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_SW_GAIN_ADDR);

	return (u8)((local_val & ((u32)0x00040000)) >> 18);
}

static inline void riu_rc_rc_rx_sw_gain_rx_sw_gain_update_setf(struct cl_chip *chip, u8 rxswgainupdate)
{
	ASSERT_ERR_CHIP((((u32)rxswgainupdate << 18) & ~((u32)0x00040000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_SW_GAIN_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_SW_GAIN_ADDR) & ~((u32)0x00040000)) | ((u32)rxswgainupdate << 18));
}

static inline u16 riu_rc_rc_rx_sw_gain_rx_sw_gain_ch_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_SW_GAIN_ADDR);

	return (u16)((local_val & ((u32)0x0003FE00)) >> 9);
}

static inline void riu_rc_rc_rx_sw_gain_rx_sw_gain_ch_1_setf(struct cl_chip *chip, u16 rxswgainch1)
{
	ASSERT_ERR_CHIP((((u32)rxswgainch1 << 9) & ~((u32)0x0003FE00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_SW_GAIN_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_SW_GAIN_ADDR) & ~((u32)0x0003FE00)) | ((u32)rxswgainch1 << 9));
}

static inline u16 riu_rc_rc_rx_sw_gain_rx_sw_gain_ch_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_RX_SW_GAIN_ADDR);

	return (u16)((local_val & ((u32)0x000001FF)) >> 0);
}

static inline void riu_rc_rc_rx_sw_gain_rx_sw_gain_ch_0_setf(struct cl_chip *chip, u16 rxswgainch0)
{
	ASSERT_ERR_CHIP((((u32)rxswgainch0 << 0) & ~((u32)0x000001FF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_RX_SW_GAIN_ADDR, (cl_reg_read(chip, RIU_RC_RC_RX_SW_GAIN_ADDR) & ~((u32)0x000001FF)) | ((u32)rxswgainch0 << 0));
}

/**
 * @brief RC_TX_RF_FSM_STATE_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x7
 *    03:00 OUT                       0x7
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR        (REG_RIU_RC_BASE_ADDR + 0x0000010C)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_OFFSET      0x0000010C
#define RIU_RC_RC_TX_RF_FSM_STATE_6_INDEX       0x00000043
#define RIU_RC_RC_TX_RF_FSM_STATE_6_RESET       0x00002077

static inline u32 riu_rc_rc_tx_rf_fsm_state_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_state_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_6_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_6_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_6_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_1_RST    0x7
#define RIU_RC_RC_TX_RF_FSM_STATE_6_OUT_RST    0x7

static inline void riu_rc_rc_tx_rf_fsm_state_6_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_rf_fsm_state_6_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_6_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_rf_fsm_state_6_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_6_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_rf_fsm_state_6_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_6_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_rf_fsm_state_6_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_6_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_rf_fsm_state_6_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_6_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_rf_fsm_state_6_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_6_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_rf_fsm_state_6_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_6_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_rf_fsm_state_6_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_6_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_state_6_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_RF_FSM_STATE_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    EN_HW_SIGNAL_TO_NEXT_STATE_3 0
 *    15    EN_HW_SIGNAL_TO_NEXT_STATE_2 0
 *    14    EN_HW_SIGNAL_TO_NEXT_STATE_1 0
 *    13    TIMER_EN_TO_NEXT_STATE_1  1
 *    12:10 NEXT_STATE_3              0x0
 *    09:07 NEXT_STATE_2              0x0
 *    06:04 NEXT_STATE_1              0x0
 *    03:00 OUT                       0x0
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000110)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_OFFSET      0x00000110
#define RIU_RC_RC_TX_RF_FSM_STATE_7_INDEX       0x00000044
#define RIU_RC_RC_TX_RF_FSM_STATE_7_RESET       0x00002000

static inline u32 riu_rc_rc_tx_rf_fsm_state_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_state_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((u32)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((u32)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_7_TIMER_EN_TO_NEXT_STATE_1_BIT    ((u32)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_3_MASK    ((u32)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_3_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_2_MASK    ((u32)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_2_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_1_MASK    ((u32)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_1_WIDTH    ((u32)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_OUT_MASK    ((u32)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_OUT_WIDTH    ((u32)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_OUT_RST    0x0

static inline void riu_rc_rc_tx_rf_fsm_state_7_pack(struct cl_chip *chip, u8 en_hw_signal_to_next_state_3, u8 en_hw_signal_to_next_state_2, u8 en_hw_signal_to_next_state_1, u8 timer_en_to_next_state_1, u8 next_state_3, u8 next_state_2, u8 next_state_1, u8 out)
{
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_3 << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_2 << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)en_hw_signal_to_next_state_1 << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)timer_en_to_next_state_1 << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_3 << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_2 << 7) & ~((u32)0x00000380)) == 0);
	ASSERT_ERR_CHIP((((u32)next_state_1 << 4) & ~((u32)0x00000070)) == 0);
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, ((u32)en_hw_signal_to_next_state_3 << 16) | ((u32)en_hw_signal_to_next_state_2 << 15) | ((u32)en_hw_signal_to_next_state_1 << 14) | ((u32)timer_en_to_next_state_1 << 13) | ((u32)next_state_3 << 10) | ((u32)next_state_2 << 7) | ((u32)next_state_1 << 4) | ((u32)out << 0));
}

static inline void riu_rc_rc_tx_rf_fsm_state_7_unpack(struct cl_chip *chip, u8 *en_hw_signal_to_next_state_3, u8 *en_hw_signal_to_next_state_2, u8 *en_hw_signal_to_next_state_1, u8 *timer_en_to_next_state_1, u8 *next_state_3, u8 *next_state_2, u8 *next_state_1, u8 *out)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);

	*en_hw_signal_to_next_state_3 = (local_val & ((u32)0x00010000)) >> 16;
	*en_hw_signal_to_next_state_2 = (local_val & ((u32)0x00008000)) >> 15;
	*en_hw_signal_to_next_state_1 = (local_val & ((u32)0x00004000)) >> 14;
	*timer_en_to_next_state_1 = (local_val & ((u32)0x00002000)) >> 13;
	*next_state_3 = (local_val & ((u32)0x00001C00)) >> 10;
	*next_state_2 = (local_val & ((u32)0x00000380)) >> 7;
	*next_state_1 = (local_val & ((u32)0x00000070)) >> 4;
	*out = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_7_en_hw_signal_to_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_rf_fsm_state_7_en_hw_signal_to_next_state_3_setf(struct cl_chip *chip, u8 enhwsignaltonextstate3)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate3 << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((u32)0x00010000)) | ((u32)enhwsignaltonextstate3 << 16));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_7_en_hw_signal_to_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void riu_rc_rc_tx_rf_fsm_state_7_en_hw_signal_to_next_state_2_setf(struct cl_chip *chip, u8 enhwsignaltonextstate2)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate2 << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((u32)0x00008000)) | ((u32)enhwsignaltonextstate2 << 15));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_7_en_hw_signal_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void riu_rc_rc_tx_rf_fsm_state_7_en_hw_signal_to_next_state_1_setf(struct cl_chip *chip, u8 enhwsignaltonextstate1)
{
	ASSERT_ERR_CHIP((((u32)enhwsignaltonextstate1 << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((u32)0x00004000)) | ((u32)enhwsignaltonextstate1 << 14));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_7_timer_en_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void riu_rc_rc_tx_rf_fsm_state_7_timer_en_to_next_state_1_setf(struct cl_chip *chip, u8 timerentonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timerentonextstate1 << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((u32)0x00002000)) | ((u32)timerentonextstate1 << 13));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_7_next_state_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void riu_rc_rc_tx_rf_fsm_state_7_next_state_3_setf(struct cl_chip *chip, u8 nextstate3)
{
	ASSERT_ERR_CHIP((((u32)nextstate3 << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((u32)0x00001C00)) | ((u32)nextstate3 << 10));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_7_next_state_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);

	return (u8)((local_val & ((u32)0x00000380)) >> 7);
}

static inline void riu_rc_rc_tx_rf_fsm_state_7_next_state_2_setf(struct cl_chip *chip, u8 nextstate2)
{
	ASSERT_ERR_CHIP((((u32)nextstate2 << 7) & ~((u32)0x00000380)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((u32)0x00000380)) | ((u32)nextstate2 << 7));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_7_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);

	return (u8)((local_val & ((u32)0x00000070)) >> 4);
}

static inline void riu_rc_rc_tx_rf_fsm_state_7_next_state_1_setf(struct cl_chip *chip, u8 nextstate1)
{
	ASSERT_ERR_CHIP((((u32)nextstate1 << 4) & ~((u32)0x00000070)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((u32)0x00000070)) | ((u32)nextstate1 << 4));
}

static inline u8 riu_rc_rc_tx_rf_fsm_state_7_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_state_7_out_setf(struct cl_chip *chip, u8 out)
{
	ASSERT_ERR_CHIP((((u32)out << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((u32)0x0000000F)) | ((u32)out << 0));
}

/**
 * @brief RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000114)
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_OFFSET      0x00000114
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_INDEX       0x00000045
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_RESET       0x00000005

static inline u32 riu_rc_rc_tx_rf_fsm_s_6_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_s_6_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

static inline u32 riu_rc_rc_tx_rf_fsm_s_6_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_s_6_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000118)
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_OFFSET      0x00000118
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_INDEX       0x00000046
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_RESET       0x00000005

static inline u32 riu_rc_rc_tx_rf_fsm_s_7_to_next_state_timer_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_ADDR);
}

static inline void riu_rc_rc_tx_rf_fsm_s_7_to_next_state_timer_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((u32)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((u32)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

static inline u32 riu_rc_rc_tx_rf_fsm_s_7_to_next_state_timer_timer_to_next_state_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void riu_rc_rc_tx_rf_fsm_s_7_to_next_state_timer_timer_to_next_state_1_setf(struct cl_chip *chip, u32 timertonextstate1)
{
	ASSERT_ERR_CHIP((((u32)timertonextstate1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_ADDR, (u32)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_INITIAL_GAIN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:08 INITIAL_TX_GAIN_1         0x0
 *    07:00 INITIAL_TX_GAIN_0         0x0
 * </pre>
 */
#define RIU_RC_RC_TX_INITIAL_GAIN_ADDR        (REG_RIU_RC_BASE_ADDR + 0x0000011C)
#define RIU_RC_RC_TX_INITIAL_GAIN_OFFSET      0x0000011C
#define RIU_RC_RC_TX_INITIAL_GAIN_INDEX       0x00000047
#define RIU_RC_RC_TX_INITIAL_GAIN_RESET       0x00000000

static inline u32 riu_rc_rc_tx_initial_gain_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_INITIAL_GAIN_ADDR);
}

static inline void riu_rc_rc_tx_initial_gain_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_INITIAL_GAIN_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_1_MASK    ((u32)0x0000FF00)
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_1_LSB    8
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_1_WIDTH    ((u32)0x00000008)
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_0_MASK    ((u32)0x000000FF)
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_0_LSB    0
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_0_WIDTH    ((u32)0x00000008)

#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_1_RST    0x0
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_0_RST    0x0

static inline void riu_rc_rc_tx_initial_gain_pack(struct cl_chip *chip, u8 initial_tx_gain_1, u8 initial_tx_gain_0)
{
	ASSERT_ERR_CHIP((((u32)initial_tx_gain_1 << 8) & ~((u32)0x0000FF00)) == 0);
	ASSERT_ERR_CHIP((((u32)initial_tx_gain_0 << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_INITIAL_GAIN_ADDR, ((u32)initial_tx_gain_1 << 8) | ((u32)initial_tx_gain_0 << 0));
}

static inline void riu_rc_rc_tx_initial_gain_unpack(struct cl_chip *chip, u8 *initial_tx_gain_1, u8 *initial_tx_gain_0)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_INITIAL_GAIN_ADDR);

	*initial_tx_gain_1 = (local_val & ((u32)0x0000FF00)) >> 8;
	*initial_tx_gain_0 = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u8 riu_rc_rc_tx_initial_gain_initial_tx_gain_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_INITIAL_GAIN_ADDR);

	return (u8)((local_val & ((u32)0x0000FF00)) >> 8);
}

static inline void riu_rc_rc_tx_initial_gain_initial_tx_gain_1_setf(struct cl_chip *chip, u8 initialtxgain1)
{
	ASSERT_ERR_CHIP((((u32)initialtxgain1 << 8) & ~((u32)0x0000FF00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_INITIAL_GAIN_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_INITIAL_GAIN_ADDR) & ~((u32)0x0000FF00)) | ((u32)initialtxgain1 << 8));
}

static inline u8 riu_rc_rc_tx_initial_gain_initial_tx_gain_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_INITIAL_GAIN_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void riu_rc_rc_tx_initial_gain_initial_tx_gain_0_setf(struct cl_chip *chip, u8 initialtxgain0)
{
	ASSERT_ERR_CHIP((((u32)initialtxgain0 << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_INITIAL_GAIN_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_INITIAL_GAIN_ADDR) & ~((u32)0x000000FF)) | ((u32)initialtxgain0 << 0));
}

/**
 * @brief RC_TX_GAIN_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    TX_GAIN_UPDATE            0
 *    15:08 TX_GAIN_2_CH_1            0x0
 *    07:00 TX_GAIN_2_CH_0            0x0
 * </pre>
 */
#define RIU_RC_RC_TX_GAIN_2_ADDR        (REG_RIU_RC_BASE_ADDR + 0x00000120)
#define RIU_RC_RC_TX_GAIN_2_OFFSET      0x00000120
#define RIU_RC_RC_TX_GAIN_2_INDEX       0x00000048
#define RIU_RC_RC_TX_GAIN_2_RESET       0x00000000

static inline u32 riu_rc_rc_tx_gain_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, RIU_RC_RC_TX_GAIN_2_ADDR);
}

static inline void riu_rc_rc_tx_gain_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, RIU_RC_RC_TX_GAIN_2_ADDR, value);
}

/* Field definitions */
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_UPDATE_BIT    ((u32)0x00010000)
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_UPDATE_POS    16
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_1_MASK    ((u32)0x0000FF00)
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_1_LSB    8
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_1_WIDTH    ((u32)0x00000008)
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_0_MASK    ((u32)0x000000FF)
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_0_LSB    0
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_0_WIDTH    ((u32)0x00000008)

#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_UPDATE_RST    0x0
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_1_RST    0x0
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_0_RST    0x0

static inline void riu_rc_rc_tx_gain_2_pack(struct cl_chip *chip, u8 tx_gain_update, u8 tx_gain_2_ch_1, u8 tx_gain_2_ch_0)
{
	ASSERT_ERR_CHIP((((u32)tx_gain_update << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)tx_gain_2_ch_1 << 8) & ~((u32)0x0000FF00)) == 0);
	ASSERT_ERR_CHIP((((u32)tx_gain_2_ch_0 << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_GAIN_2_ADDR, ((u32)tx_gain_update << 16) | ((u32)tx_gain_2_ch_1 << 8) | ((u32)tx_gain_2_ch_0 << 0));
}

static inline void riu_rc_rc_tx_gain_2_unpack(struct cl_chip *chip, u8 *tx_gain_update, u8 *tx_gain_2_ch_1, u8 *tx_gain_2_ch_0)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_GAIN_2_ADDR);

	*tx_gain_update = (local_val & ((u32)0x00010000)) >> 16;
	*tx_gain_2_ch_1 = (local_val & ((u32)0x0000FF00)) >> 8;
	*tx_gain_2_ch_0 = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u8 riu_rc_rc_tx_gain_2_tx_gain_update_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_GAIN_2_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void riu_rc_rc_tx_gain_2_tx_gain_update_setf(struct cl_chip *chip, u8 txgainupdate)
{
	ASSERT_ERR_CHIP((((u32)txgainupdate << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_GAIN_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_GAIN_2_ADDR) & ~((u32)0x00010000)) | ((u32)txgainupdate << 16));
}

static inline u8 riu_rc_rc_tx_gain_2_tx_gain_2_ch_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_GAIN_2_ADDR);

	return (u8)((local_val & ((u32)0x0000FF00)) >> 8);
}

static inline void riu_rc_rc_tx_gain_2_tx_gain_2_ch_1_setf(struct cl_chip *chip, u8 txgain2ch1)
{
	ASSERT_ERR_CHIP((((u32)txgain2ch1 << 8) & ~((u32)0x0000FF00)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_GAIN_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_GAIN_2_ADDR) & ~((u32)0x0000FF00)) | ((u32)txgain2ch1 << 8));
}

static inline u8 riu_rc_rc_tx_gain_2_tx_gain_2_ch_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, RIU_RC_RC_TX_GAIN_2_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void riu_rc_rc_tx_gain_2_tx_gain_2_ch_0_setf(struct cl_chip *chip, u8 txgain2ch0)
{
	ASSERT_ERR_CHIP((((u32)txgain2ch0 << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, RIU_RC_RC_TX_GAIN_2_ADDR, (cl_reg_read(chip, RIU_RC_RC_TX_GAIN_2_ADDR) & ~((u32)0x000000FF)) | ((u32)txgain2ch0 << 0));
}

#endif /* REG_RC_H */
