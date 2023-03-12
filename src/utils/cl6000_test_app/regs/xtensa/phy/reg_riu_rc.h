#ifndef _REG_RIU_RC_H_
#define _REG_RIU_RC_H_

#include <stdint.h>
#include "phy/_reg_riu_rc.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_RIU_RC__H__FILEID__

#define REG_RIU_RC_COUNT  73


/**
 * @brief RC_TX_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 TX_ALLOCATED_CHAINS       0x0
 * </pre>
 */
#define RIU_RC_RC_TX_CONFIG_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000000)
#define RIU_RC_RC_TX_CONFIG_OFFSET      0x00000000
#define RIU_RC_RC_TX_CONFIG_INDEX       0x00000000
#define RIU_RC_RC_TX_CONFIG_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_tx_config_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_CONFIG_ADDR);
}

__INLINE void riu_rc_rc_tx_config_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_CONFIG_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_CONFIG_TX_ALLOCATED_CHAINS_MASK    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_CONFIG_TX_ALLOCATED_CHAINS_LSB    0
#define RIU_RC_RC_TX_CONFIG_TX_ALLOCATED_CHAINS_WIDTH    ((uint32_t)0x00000002)

#define RIU_RC_RC_TX_CONFIG_TX_ALLOCATED_CHAINS_RST    0x0

__INLINE uint8_t riu_rc_rc_tx_config_tx_allocated_chains_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_CONFIG_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_config_tx_allocated_chains_setf(uint8_t txallocatedchains)
{
	ASSERT_ERR((((uint32_t)txallocatedchains << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_CONFIG_ADDR, (uint32_t)txallocatedchains << 0);
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
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000004)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_OFFSET      0x00000004
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_INDEX       0x00000001
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_RESET       0x00004014

__INLINE uint32_t  riu_rc_rc_tx_dac_fsm_state_0_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);
}

__INLINE void riu_rc_rc_tx_dac_fsm_state_0_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_OUT_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_0_OUT_RST    0x4

__INLINE void riu_rc_rc_tx_dac_fsm_state_0_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_dac_fsm_state_0_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_0_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_0_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_0_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_0_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_0_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_0_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_0_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_0_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_0_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_0_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_0_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_0_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_0_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_0_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_0_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_0_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_0_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000008)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_OFFSET      0x00000008
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_INDEX       0x00000002
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_RESET       0x0000A1A4

__INLINE uint32_t  riu_rc_rc_tx_dac_fsm_state_1_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);
}

__INLINE void riu_rc_rc_tx_dac_fsm_state_1_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_OUT_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_2_RST    0x3
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_NEXT_STATE_1_RST    0x2
#define RIU_RC_RC_TX_DAC_FSM_STATE_1_OUT_RST    0x4

__INLINE void riu_rc_rc_tx_dac_fsm_state_1_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_dac_fsm_state_1_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_1_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_1_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_1_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_1_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_1_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_1_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_1_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_1_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_1_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_1_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_1_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_1_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_1_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_1_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_1_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_1_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR        (REG_RIU_RC_BASE_ADDR+0x0000000C)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_OFFSET      0x0000000C
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_INDEX       0x00000003
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_RESET       0x00004037

__INLINE uint32_t  riu_rc_rc_tx_dac_fsm_state_2_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);
}

__INLINE void riu_rc_rc_tx_dac_fsm_state_2_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_OUT_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_NEXT_STATE_1_RST    0x3
#define RIU_RC_RC_TX_DAC_FSM_STATE_2_OUT_RST    0x7

__INLINE void riu_rc_rc_tx_dac_fsm_state_2_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_dac_fsm_state_2_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_2_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_2_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_2_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_2_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_2_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_2_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_2_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_2_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_2_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_2_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_2_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_2_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_2_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_2_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_2_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_2_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000010)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_OFFSET      0x00000010
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_INDEX       0x00000004
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_RESET       0x00002047

__INLINE uint32_t  riu_rc_rc_tx_dac_fsm_state_3_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);
}

__INLINE void riu_rc_rc_tx_dac_fsm_state_3_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_OUT_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_NEXT_STATE_1_RST    0x4
#define RIU_RC_RC_TX_DAC_FSM_STATE_3_OUT_RST    0x7

__INLINE void riu_rc_rc_tx_dac_fsm_state_3_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_dac_fsm_state_3_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_3_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_3_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_3_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_3_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_3_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_3_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_3_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_3_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_3_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_3_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_3_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_3_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_3_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_3_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_3_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_3_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_3_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000014)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_OFFSET      0x00000014
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_INDEX       0x00000005
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_RESET       0x00002004

__INLINE uint32_t  riu_rc_rc_tx_dac_fsm_state_4_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);
}

__INLINE void riu_rc_rc_tx_dac_fsm_state_4_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_OUT_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_DAC_FSM_STATE_4_OUT_RST    0x4

__INLINE void riu_rc_rc_tx_dac_fsm_state_4_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_dac_fsm_state_4_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_4_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_4_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_4_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_4_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_4_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_4_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_4_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_4_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_4_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_4_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_4_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_4_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_4_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_4_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_dac_fsm_state_4_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_dac_fsm_state_4_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_STATE_4_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
}

/**
 * @brief RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000018)
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_OFFSET      0x00000018
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_INDEX       0x00000006
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_tx_dac_fsm_s_0_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_dac_fsm_s_0_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

__INLINE uint32_t riu_rc_rc_tx_dac_fsm_s_0_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_dac_fsm_s_0_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x7
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x0000001C)
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_OFFSET      0x0000001C
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_INDEX       0x00000007
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_RESET       0x00000007

__INLINE uint32_t  riu_rc_rc_tx_dac_fsm_s_1_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_dac_fsm_s_1_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x7

__INLINE uint32_t riu_rc_rc_tx_dac_fsm_s_1_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_dac_fsm_s_1_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000020)
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_OFFSET      0x00000020
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_INDEX       0x00000008
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_tx_dac_fsm_s_2_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_dac_fsm_s_2_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

__INLINE uint32_t riu_rc_rc_tx_dac_fsm_s_2_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_dac_fsm_s_2_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:00 TIMER_TO_NEXT_STATE_1     0x80
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000024)
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_OFFSET      0x00000024
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_INDEX       0x00000009
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_RESET       0x00000080

__INLINE uint32_t  riu_rc_rc_tx_dac_fsm_s_3_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_dac_fsm_s_3_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0x7FFFFFFF)
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x0000001F)

#define RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x80

__INLINE uint32_t riu_rc_rc_tx_dac_fsm_s_3_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_dac_fsm_s_3_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0x7FFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000028)
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_OFFSET      0x00000028
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_INDEX       0x0000000A
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_RESET       0x00000005

__INLINE uint32_t  riu_rc_rc_tx_dac_fsm_s_4_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_dac_fsm_s_4_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

__INLINE uint32_t riu_rc_rc_tx_dac_fsm_s_4_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_dac_fsm_s_4_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
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
#define RIU_RC_RC_TX_DAC_SW_CTRL_ADDR        (REG_RIU_RC_BASE_ADDR+0x0000002C)
#define RIU_RC_RC_TX_DAC_SW_CTRL_OFFSET      0x0000002C
#define RIU_RC_RC_TX_DAC_SW_CTRL_INDEX       0x0000000B
#define RIU_RC_RC_TX_DAC_SW_CTRL_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_tx_dac_sw_ctrl_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_DAC_SW_CTRL_ADDR);
}

__INLINE void riu_rc_rc_tx_dac_sw_ctrl_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_DAC_SW_CTRL_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_VALID_BIT    ((uint32_t)0x00000008)
#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_VALID_POS    3
#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_MASK    ((uint32_t)0x00000007)
#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_LSB    0
#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_WIDTH    ((uint32_t)0x00000003)

#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_VALID_RST    0x0
#define RIU_RC_RC_TX_DAC_SW_CTRL_GOTO_STATE_RST    0x0

__INLINE void riu_rc_rc_tx_dac_sw_ctrl_pack(uint8_t goto_state_valid, uint8_t goto_state)
{
	ASSERT_ERR((((uint32_t)goto_state_valid << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)goto_state << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_SW_CTRL_ADDR,  ((uint32_t)goto_state_valid << 3) |((uint32_t)goto_state << 0));
}

__INLINE void riu_rc_rc_tx_dac_sw_ctrl_unpack(uint8_t* goto_state_valid, uint8_t* goto_state)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_SW_CTRL_ADDR);

	*goto_state_valid = (localVal & ((uint32_t)0x00000008)) >>  3;
	*goto_state = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_dac_sw_ctrl_goto_state_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void riu_rc_rc_tx_dac_sw_ctrl_goto_state_valid_setf(uint8_t gotostatevalid)
{
	ASSERT_ERR((((uint32_t)gotostatevalid << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_SW_CTRL_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)gotostatevalid <<3));
}
__INLINE uint8_t riu_rc_rc_tx_dac_sw_ctrl_goto_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_DAC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void riu_rc_rc_tx_dac_sw_ctrl_goto_state_setf(uint8_t gotostate)
{
	ASSERT_ERR((((uint32_t)gotostate << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_DAC_SW_CTRL_ADDR, (REG_PL_RD(RIU_RC_RC_TX_DAC_SW_CTRL_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)gotostate <<0));
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
#define RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000030)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_OFFSET      0x00000030
#define RIU_RC_RC_TX_RF_FSM_STATE_0_INDEX       0x0000000C
#define RIU_RC_RC_TX_RF_FSM_STATE_0_RESET       0x00004010

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_state_0_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_0_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_0_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_0_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_0_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_0_OUT_RST    0x0

__INLINE void riu_rc_rc_tx_rf_fsm_state_0_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_0_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_0_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_0_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_0_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_0_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_0_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_0_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_0_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_0_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_0_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_0_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_0_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_0_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_0_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_0_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_0_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_0_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000034)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_OFFSET      0x00000034
#define RIU_RC_RC_TX_RF_FSM_STATE_1_INDEX       0x0000000D
#define RIU_RC_RC_TX_RF_FSM_STATE_1_RESET       0x0000A320

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_state_1_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_1_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_1_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_1_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_2_RST    0x6
#define RIU_RC_RC_TX_RF_FSM_STATE_1_NEXT_STATE_1_RST    0x2
#define RIU_RC_RC_TX_RF_FSM_STATE_1_OUT_RST    0x0

__INLINE void riu_rc_rc_tx_rf_fsm_state_1_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_1_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_1_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_1_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_1_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_1_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_1_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_1_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_1_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_1_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_1_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_1_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_1_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_1_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_1_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_1_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_1_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_1_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000038)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_OFFSET      0x00000038
#define RIU_RC_RC_TX_RF_FSM_STATE_2_INDEX       0x0000000E
#define RIU_RC_RC_TX_RF_FSM_STATE_2_RESET       0x0000A331

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_state_2_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_2_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_2_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_2_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_2_RST    0x6
#define RIU_RC_RC_TX_RF_FSM_STATE_2_NEXT_STATE_1_RST    0x3
#define RIU_RC_RC_TX_RF_FSM_STATE_2_OUT_RST    0x1

__INLINE void riu_rc_rc_tx_rf_fsm_state_2_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_2_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_2_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_2_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_2_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_2_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_2_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_2_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_2_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_2_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_2_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_2_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_2_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_2_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_2_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_2_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_2_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_2_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR        (REG_RIU_RC_BASE_ADDR+0x0000003C)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_OFFSET      0x0000003C
#define RIU_RC_RC_TX_RF_FSM_STATE_3_INDEX       0x0000000F
#define RIU_RC_RC_TX_RF_FSM_STATE_3_RESET       0x0000A341

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_state_3_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_3_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_3_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_3_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_2_RST    0x6
#define RIU_RC_RC_TX_RF_FSM_STATE_3_NEXT_STATE_1_RST    0x4
#define RIU_RC_RC_TX_RF_FSM_STATE_3_OUT_RST    0x1

__INLINE void riu_rc_rc_tx_rf_fsm_state_3_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_3_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_3_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_3_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_3_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_3_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_3_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_3_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_3_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_3_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_3_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_3_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_3_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_3_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_3_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_3_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_3_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_3_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000040)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_OFFSET      0x00000040
#define RIU_RC_RC_TX_RF_FSM_STATE_4_INDEX       0x00000010
#define RIU_RC_RC_TX_RF_FSM_STATE_4_RESET       0x0000A357

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_state_4_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_4_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_4_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_4_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_2_RST    0x6
#define RIU_RC_RC_TX_RF_FSM_STATE_4_NEXT_STATE_1_RST    0x5
#define RIU_RC_RC_TX_RF_FSM_STATE_4_OUT_RST    0x7

__INLINE void riu_rc_rc_tx_rf_fsm_state_4_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_4_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_4_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_4_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_4_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_4_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_4_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_4_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_4_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_4_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_4_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_4_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_4_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_4_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_4_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_4_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_4_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_4_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000044)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_OFFSET      0x00000044
#define RIU_RC_RC_TX_RF_FSM_STATE_5_INDEX       0x00000011
#define RIU_RC_RC_TX_RF_FSM_STATE_5_RESET       0x0000C267

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_state_5_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_5_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_5_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_5_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_2_RST    0x4
#define RIU_RC_RC_TX_RF_FSM_STATE_5_NEXT_STATE_1_RST    0x6
#define RIU_RC_RC_TX_RF_FSM_STATE_5_OUT_RST    0x7

__INLINE void riu_rc_rc_tx_rf_fsm_state_5_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_5_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_5_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_5_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_5_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_5_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_5_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_5_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_5_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_5_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_5_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_5_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_5_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_5_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_5_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_5_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_5_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_5_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
}

/**
 * @brief RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000048)
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_OFFSET      0x00000048
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_INDEX       0x00000012
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_s_0_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_s_0_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

__INLINE uint32_t riu_rc_rc_tx_rf_fsm_s_0_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_s_0_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0xB
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x0000004C)
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_OFFSET      0x0000004C
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_INDEX       0x00000013
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_RESET       0x0000000B

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_s_1_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_s_1_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0xB

__INLINE uint32_t riu_rc_rc_tx_rf_fsm_s_1_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_s_1_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x3
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000050)
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_OFFSET      0x00000050
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_INDEX       0x00000014
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_RESET       0x00000003

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_s_2_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_s_2_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x3

__INLINE uint32_t riu_rc_rc_tx_rf_fsm_s_2_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_s_2_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000054)
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_OFFSET      0x00000054
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_INDEX       0x00000015
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_s_3_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_s_3_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

__INLINE uint32_t riu_rc_rc_tx_rf_fsm_s_3_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_s_3_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x30
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000058)
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_OFFSET      0x00000058
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_INDEX       0x00000016
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_RESET       0x00000030

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_s_4_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_s_4_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x30

__INLINE uint32_t riu_rc_rc_tx_rf_fsm_s_4_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_s_4_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x0000005C)
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_OFFSET      0x0000005C
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_INDEX       0x00000017
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_RESET       0x00000005

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_s_5_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_s_5_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

__INLINE uint32_t riu_rc_rc_tx_rf_fsm_s_5_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_s_5_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
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
#define RIU_RC_RC_TX_RF_SW_CTRL_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000060)
#define RIU_RC_RC_TX_RF_SW_CTRL_OFFSET      0x00000060
#define RIU_RC_RC_TX_RF_SW_CTRL_INDEX       0x00000018
#define RIU_RC_RC_TX_RF_SW_CTRL_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_tx_rf_sw_ctrl_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_SW_CTRL_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_sw_ctrl_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_SW_CTRL_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_VALID_BIT    ((uint32_t)0x00000008)
#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_VALID_POS    3
#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_MASK    ((uint32_t)0x00000007)
#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_LSB    0
#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_WIDTH    ((uint32_t)0x00000003)

#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_VALID_RST    0x0
#define RIU_RC_RC_TX_RF_SW_CTRL_GOTO_STATE_RST    0x0

__INLINE void riu_rc_rc_tx_rf_sw_ctrl_pack(uint8_t goto_state_valid, uint8_t goto_state)
{
	ASSERT_ERR((((uint32_t)goto_state_valid << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)goto_state << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_SW_CTRL_ADDR,  ((uint32_t)goto_state_valid << 3) |((uint32_t)goto_state << 0));
}

__INLINE void riu_rc_rc_tx_rf_sw_ctrl_unpack(uint8_t* goto_state_valid, uint8_t* goto_state)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_SW_CTRL_ADDR);

	*goto_state_valid = (localVal & ((uint32_t)0x00000008)) >>  3;
	*goto_state = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_rf_sw_ctrl_goto_state_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void riu_rc_rc_tx_rf_sw_ctrl_goto_state_valid_setf(uint8_t gotostatevalid)
{
	ASSERT_ERR((((uint32_t)gotostatevalid << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_SW_CTRL_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_SW_CTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)gotostatevalid <<3));
}
__INLINE uint8_t riu_rc_rc_tx_rf_sw_ctrl_goto_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void riu_rc_rc_tx_rf_sw_ctrl_goto_state_setf(uint8_t gotostate)
{
	ASSERT_ERR((((uint32_t)gotostate << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_SW_CTRL_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_SW_CTRL_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)gotostate <<0));
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
#define RIU_RC_RC_TX_FSM_STATUS_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000064)
#define RIU_RC_RC_TX_FSM_STATUS_OFFSET      0x00000064
#define RIU_RC_RC_TX_FSM_STATUS_INDEX       0x00000019
#define RIU_RC_RC_TX_FSM_STATUS_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_tx_fsm_status_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_FSM_STATUS_ADDR);
}

// field definitions
#define RIU_RC_RC_TX_FSM_STATUS_TX_RF_FSM_STAT_MASK    ((uint32_t)0x00000038)
#define RIU_RC_RC_TX_FSM_STATUS_TX_RF_FSM_STAT_LSB    3
#define RIU_RC_RC_TX_FSM_STATUS_TX_RF_FSM_STAT_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_FSM_STATUS_TX_DAC_FSM_STAT_MASK    ((uint32_t)0x00000007)
#define RIU_RC_RC_TX_FSM_STATUS_TX_DAC_FSM_STAT_LSB    0
#define RIU_RC_RC_TX_FSM_STATUS_TX_DAC_FSM_STAT_WIDTH    ((uint32_t)0x00000003)

#define RIU_RC_RC_TX_FSM_STATUS_TX_RF_FSM_STAT_RST    0x0
#define RIU_RC_RC_TX_FSM_STATUS_TX_DAC_FSM_STAT_RST    0x0

__INLINE void riu_rc_rc_tx_fsm_status_unpack(uint8_t* tx_rf_fsm_stat, uint8_t* tx_dac_fsm_stat)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_FSM_STATUS_ADDR);

	*tx_rf_fsm_stat = (localVal & ((uint32_t)0x00000038)) >>  3;
	*tx_dac_fsm_stat = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_fsm_status_tx_rf_fsm_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_FSM_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE uint8_t riu_rc_rc_tx_fsm_status_tx_dac_fsm_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_FSM_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief RC_TX_TO_RIU_TIMERS_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RC_TX_ACK_ON_CLKS         0x19
 * </pre>
 */
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000068)
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_OFFSET      0x00000068
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_INDEX       0x0000001A
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_RESET       0x00000019

__INLINE uint32_t  riu_rc_rc_tx_to_riu_timers_0_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_TO_RIU_TIMERS_0_ADDR);
}

__INLINE void riu_rc_rc_tx_to_riu_timers_0_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_TO_RIU_TIMERS_0_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_RC_TX_ACK_ON_CLKS_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_RC_TX_ACK_ON_CLKS_LSB    0
#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_RC_TX_ACK_ON_CLKS_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_TO_RIU_TIMERS_0_RC_TX_ACK_ON_CLKS_RST    0x19

__INLINE uint32_t riu_rc_rc_tx_to_riu_timers_0_rc_tx_ack_on_clks_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_TO_RIU_TIMERS_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_to_riu_timers_0_rc_tx_ack_on_clks_setf(uint32_t rctxackonclks)
{
	ASSERT_ERR((((uint32_t)rctxackonclks << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_TO_RIU_TIMERS_0_ADDR, (uint32_t)rctxackonclks << 0);
}

/**
 * @brief RC_TX_TO_RIU_TIMERS_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RC_TX_ACK_OFF_CLKS        0x90
 * </pre>
 */
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_ADDR        (REG_RIU_RC_BASE_ADDR+0x0000006C)
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_OFFSET      0x0000006C
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_INDEX       0x0000001B
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_RESET       0x00000090

__INLINE uint32_t  riu_rc_rc_tx_to_riu_timers_1_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_TO_RIU_TIMERS_1_ADDR);
}

__INLINE void riu_rc_rc_tx_to_riu_timers_1_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_TO_RIU_TIMERS_1_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_RC_TX_ACK_OFF_CLKS_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_RC_TX_ACK_OFF_CLKS_LSB    0
#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_RC_TX_ACK_OFF_CLKS_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_TO_RIU_TIMERS_1_RC_TX_ACK_OFF_CLKS_RST    0x90

__INLINE uint32_t riu_rc_rc_tx_to_riu_timers_1_rc_tx_ack_off_clks_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_TO_RIU_TIMERS_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_to_riu_timers_1_rc_tx_ack_off_clks_setf(uint32_t rctxackoffclks)
{
	ASSERT_ERR((((uint32_t)rctxackoffclks << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_TO_RIU_TIMERS_1_ADDR, (uint32_t)rctxackoffclks << 0);
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
#define RIU_RC_RC_TX_GAIN_1_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000070)
#define RIU_RC_RC_TX_GAIN_1_OFFSET      0x00000070
#define RIU_RC_RC_TX_GAIN_1_INDEX       0x0000001C
#define RIU_RC_RC_TX_GAIN_1_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_tx_gain_1_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_GAIN_1_ADDR);
}

__INLINE void riu_rc_rc_tx_gain_1_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_GAIN_1_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_1_MASK    ((uint32_t)0x0000FF00)
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_1_LSB    8
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_1_WIDTH    ((uint32_t)0x00000008)
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_0_MASK    ((uint32_t)0x000000FF)
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_0_LSB    0
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_0_WIDTH    ((uint32_t)0x00000008)

#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_1_RST    0x0
#define RIU_RC_RC_TX_GAIN_1_TX_GAIN_1_CH_0_RST    0x0

__INLINE void riu_rc_rc_tx_gain_1_pack(uint8_t tx_gain_1_ch_1, uint8_t tx_gain_1_ch_0)
{
	ASSERT_ERR((((uint32_t)tx_gain_1_ch_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)tx_gain_1_ch_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_GAIN_1_ADDR,  ((uint32_t)tx_gain_1_ch_1 << 8) |((uint32_t)tx_gain_1_ch_0 << 0));
}

__INLINE void riu_rc_rc_tx_gain_1_unpack(uint8_t* tx_gain_1_ch_1, uint8_t* tx_gain_1_ch_0)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_GAIN_1_ADDR);

	*tx_gain_1_ch_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*tx_gain_1_ch_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_gain_1_tx_gain_1_ch_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_GAIN_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void riu_rc_rc_tx_gain_1_tx_gain_1_ch_1_setf(uint8_t txgain1ch1)
{
	ASSERT_ERR((((uint32_t)txgain1ch1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_GAIN_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_GAIN_1_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)txgain1ch1 <<8));
}
__INLINE uint8_t riu_rc_rc_tx_gain_1_tx_gain_1_ch_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_GAIN_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void riu_rc_rc_tx_gain_1_tx_gain_1_ch_0_setf(uint8_t txgain1ch0)
{
	ASSERT_ERR((((uint32_t)txgain1ch0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_GAIN_1_ADDR, (REG_PL_RD(RIU_RC_RC_TX_GAIN_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)txgain1ch0 <<0));
}

/**
 * @brief RC_RX_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 RX_ALLOCATED_CHAINS       0x0
 * </pre>
 */
#define RIU_RC_RC_RX_CONFIG_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000074)
#define RIU_RC_RC_RX_CONFIG_OFFSET      0x00000074
#define RIU_RC_RC_RX_CONFIG_INDEX       0x0000001D
#define RIU_RC_RC_RX_CONFIG_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_config_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_CONFIG_ADDR);
}

__INLINE void riu_rc_rc_rx_config_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_CONFIG_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_CONFIG_RX_ALLOCATED_CHAINS_MASK    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_CONFIG_RX_ALLOCATED_CHAINS_LSB    0
#define RIU_RC_RC_RX_CONFIG_RX_ALLOCATED_CHAINS_WIDTH    ((uint32_t)0x00000002)

#define RIU_RC_RC_RX_CONFIG_RX_ALLOCATED_CHAINS_RST    0x0

__INLINE uint8_t riu_rc_rc_rx_config_rx_allocated_chains_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_CONFIG_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_config_rx_allocated_chains_setf(uint8_t rxallocatedchains)
{
	ASSERT_ERR((((uint32_t)rxallocatedchains << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_CONFIG_ADDR, (uint32_t)rxallocatedchains << 0);
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
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000078)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_OFFSET      0x00000078
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_INDEX       0x0000001E
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_RESET       0x00004013

__INLINE uint32_t  riu_rc_rc_rx_adc_fsm_state_0_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_fsm_state_0_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_OUT_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_0_OUT_RST    0x3

__INLINE void riu_rc_rc_rx_adc_fsm_state_0_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_adc_fsm_state_0_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_0_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_0_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_0_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_0_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_0_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_0_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_0_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_0_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_0_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_0_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_0_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_0_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_0_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_0_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_0_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_0_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_0_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR        (REG_RIU_RC_BASE_ADDR+0x0000007C)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_OFFSET      0x0000007C
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_INDEX       0x0000001F
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_RESET       0x0000A223

__INLINE uint32_t  riu_rc_rc_rx_adc_fsm_state_1_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_fsm_state_1_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_OUT_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_2_RST    0x4
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_NEXT_STATE_1_RST    0x2
#define RIU_RC_RC_RX_ADC_FSM_STATE_1_OUT_RST    0x3

__INLINE void riu_rc_rc_rx_adc_fsm_state_1_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_adc_fsm_state_1_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_1_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_1_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_1_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_1_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_1_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_1_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_1_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_1_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_1_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_1_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_1_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_1_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_1_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_1_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_1_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_1_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000080)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_OFFSET      0x00000080
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_INDEX       0x00000020
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_RESET       0x0000A231

__INLINE uint32_t  riu_rc_rc_rx_adc_fsm_state_2_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_fsm_state_2_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_OUT_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_2_RST    0x4
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_NEXT_STATE_1_RST    0x3
#define RIU_RC_RC_RX_ADC_FSM_STATE_2_OUT_RST    0x1

__INLINE void riu_rc_rc_rx_adc_fsm_state_2_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_adc_fsm_state_2_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_2_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_2_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_2_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_2_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_2_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_2_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_2_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_2_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_2_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_2_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_2_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_2_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_2_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_2_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_2_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_2_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000084)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_OFFSET      0x00000084
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_INDEX       0x00000021
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_RESET       0x00004049

__INLINE uint32_t  riu_rc_rc_rx_adc_fsm_state_3_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_fsm_state_3_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_OUT_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_NEXT_STATE_1_RST    0x4
#define RIU_RC_RC_RX_ADC_FSM_STATE_3_OUT_RST    0x9

__INLINE void riu_rc_rc_rx_adc_fsm_state_3_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_adc_fsm_state_3_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_3_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_3_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_3_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_3_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_3_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_3_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_3_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_3_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_3_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_3_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_3_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_3_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_3_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_3_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_3_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_3_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_3_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000088)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_OFFSET      0x00000088
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_INDEX       0x00000022
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_RESET       0x00002059

__INLINE uint32_t  riu_rc_rc_rx_adc_fsm_state_4_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_fsm_state_4_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_OUT_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_NEXT_STATE_1_RST    0x5
#define RIU_RC_RC_RX_ADC_FSM_STATE_4_OUT_RST    0x9

__INLINE void riu_rc_rc_rx_adc_fsm_state_4_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_adc_fsm_state_4_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_4_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_4_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_4_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_4_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_4_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_4_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_4_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_4_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_4_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_4_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_4_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_4_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_4_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_4_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_4_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_4_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_4_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR        (REG_RIU_RC_BASE_ADDR+0x0000008C)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_OFFSET      0x0000008C
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_INDEX       0x00000023
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_RESET       0x00002003

__INLINE uint32_t  riu_rc_rc_rx_adc_fsm_state_5_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_fsm_state_5_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_OUT_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_ADC_FSM_STATE_5_OUT_RST    0x3

__INLINE void riu_rc_rc_rx_adc_fsm_state_5_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_adc_fsm_state_5_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_5_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_5_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_5_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_5_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_5_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_5_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_5_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_5_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_5_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_5_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_5_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_5_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_5_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_5_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_adc_fsm_state_5_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_adc_fsm_state_5_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_STATE_5_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
}

/**
 * @brief RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000090)
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_OFFSET      0x00000090
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_INDEX       0x00000024
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_adc_fsm_s_0_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_fsm_s_0_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

__INLINE uint32_t riu_rc_rc_rx_adc_fsm_s_0_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_adc_fsm_s_0_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x3
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000094)
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_OFFSET      0x00000094
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_INDEX       0x00000025
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_RESET       0x00000003

__INLINE uint32_t  riu_rc_rc_rx_adc_fsm_s_1_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_fsm_s_1_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x3

__INLINE uint32_t riu_rc_rc_rx_adc_fsm_s_1_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_adc_fsm_s_1_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x3C0
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000098)
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_OFFSET      0x00000098
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_INDEX       0x00000026
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_RESET       0x000003C0

__INLINE uint32_t  riu_rc_rc_rx_adc_fsm_s_2_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_fsm_s_2_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x3C0

__INLINE uint32_t riu_rc_rc_rx_adc_fsm_s_2_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_adc_fsm_s_2_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x0000009C)
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_OFFSET      0x0000009C
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_INDEX       0x00000027
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_adc_fsm_s_3_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_fsm_s_3_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

__INLINE uint32_t riu_rc_rc_rx_adc_fsm_s_3_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_adc_fsm_s_3_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000A0)
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_OFFSET      0x000000A0
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_INDEX       0x00000028
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_RESET       0x00000005

__INLINE uint32_t  riu_rc_rc_rx_adc_fsm_s_4_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_fsm_s_4_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

__INLINE uint32_t riu_rc_rc_rx_adc_fsm_s_4_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_adc_fsm_s_4_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000A4)
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_OFFSET      0x000000A4
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_INDEX       0x00000029
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_RESET       0x00000005

__INLINE uint32_t  riu_rc_rc_rx_adc_fsm_s_5_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_fsm_s_5_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

__INLINE uint32_t riu_rc_rc_rx_adc_fsm_s_5_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_adc_fsm_s_5_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
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
#define RIU_RC_RC_RX_ADC_SW_CTRL_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000A8)
#define RIU_RC_RC_RX_ADC_SW_CTRL_OFFSET      0x000000A8
#define RIU_RC_RC_RX_ADC_SW_CTRL_INDEX       0x0000002A
#define RIU_RC_RC_RX_ADC_SW_CTRL_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_adc_sw_ctrl_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_ADC_SW_CTRL_ADDR);
}

__INLINE void riu_rc_rc_rx_adc_sw_ctrl_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_ADC_SW_CTRL_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_VALID_BIT    ((uint32_t)0x00000008)
#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_VALID_POS    3
#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_MASK    ((uint32_t)0x00000007)
#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_LSB    0
#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_WIDTH    ((uint32_t)0x00000003)

#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_VALID_RST    0x0
#define RIU_RC_RC_RX_ADC_SW_CTRL_GOTO_STATE_RST    0x0

__INLINE void riu_rc_rc_rx_adc_sw_ctrl_pack(uint8_t goto_state_valid, uint8_t goto_state)
{
	ASSERT_ERR((((uint32_t)goto_state_valid << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)goto_state << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_SW_CTRL_ADDR,  ((uint32_t)goto_state_valid << 3) |((uint32_t)goto_state << 0));
}

__INLINE void riu_rc_rc_rx_adc_sw_ctrl_unpack(uint8_t* goto_state_valid, uint8_t* goto_state)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_SW_CTRL_ADDR);

	*goto_state_valid = (localVal & ((uint32_t)0x00000008)) >>  3;
	*goto_state = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_adc_sw_ctrl_goto_state_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void riu_rc_rc_rx_adc_sw_ctrl_goto_state_valid_setf(uint8_t gotostatevalid)
{
	ASSERT_ERR((((uint32_t)gotostatevalid << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_SW_CTRL_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)gotostatevalid <<3));
}
__INLINE uint8_t riu_rc_rc_rx_adc_sw_ctrl_goto_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_ADC_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void riu_rc_rc_rx_adc_sw_ctrl_goto_state_setf(uint8_t gotostate)
{
	ASSERT_ERR((((uint32_t)gotostate << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_ADC_SW_CTRL_ADDR, (REG_PL_RD(RIU_RC_RC_RX_ADC_SW_CTRL_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)gotostate <<0));
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
#define RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000AC)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_OFFSET      0x000000AC
#define RIU_RC_RC_RX_RF_FSM_STATE_0_INDEX       0x0000002B
#define RIU_RC_RC_RX_RF_FSM_STATE_0_RESET       0x00004010

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_state_0_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_0_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_0_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_0_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_0_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_0_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_0_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_0_OUT_RST    0x0

__INLINE void riu_rc_rc_rx_rf_fsm_state_0_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_0_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_0_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_0_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_0_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_0_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_0_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_0_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_0_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_0_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_0_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_0_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_0_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_0_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_0_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_0_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_0_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_0_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_0_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000B0)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_OFFSET      0x000000B0
#define RIU_RC_RC_RX_RF_FSM_STATE_1_INDEX       0x0000002C
#define RIU_RC_RC_RX_RF_FSM_STATE_1_RESET       0x0000A2A0

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_state_1_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_1_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_1_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_1_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_1_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_1_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_2_RST    0x5
#define RIU_RC_RC_RX_RF_FSM_STATE_1_NEXT_STATE_1_RST    0x2
#define RIU_RC_RC_RX_RF_FSM_STATE_1_OUT_RST    0x0

__INLINE void riu_rc_rc_rx_rf_fsm_state_1_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_1_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_1_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_1_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_1_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_1_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_1_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_1_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_1_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_1_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_1_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_1_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_1_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_1_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_1_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_1_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_1_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_1_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000B4)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_OFFSET      0x000000B4
#define RIU_RC_RC_RX_RF_FSM_STATE_2_INDEX       0x0000002D
#define RIU_RC_RC_RX_RF_FSM_STATE_2_RESET       0x0001D1D1

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_state_2_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_2_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_2_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_2_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_2_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_2_TIMER_EN_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_3_RST    0x4
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_2_RST    0x3
#define RIU_RC_RC_RX_RF_FSM_STATE_2_NEXT_STATE_1_RST    0x5
#define RIU_RC_RC_RX_RF_FSM_STATE_2_OUT_RST    0x1

__INLINE void riu_rc_rc_rx_rf_fsm_state_2_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_2_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_2_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_2_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_2_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_2_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_2_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_2_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_2_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_2_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_2_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_2_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_2_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_2_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_2_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_2_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_2_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_2_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000B8)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_OFFSET      0x000000B8
#define RIU_RC_RC_RX_RF_FSM_STATE_3_INDEX       0x0000002E
#define RIU_RC_RC_RX_RF_FSM_STATE_3_RESET       0x0000A2A1

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_state_3_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_3_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_3_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_3_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_3_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_3_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_2_RST    0x5
#define RIU_RC_RC_RX_RF_FSM_STATE_3_NEXT_STATE_1_RST    0x2
#define RIU_RC_RC_RX_RF_FSM_STATE_3_OUT_RST    0x1

__INLINE void riu_rc_rc_rx_rf_fsm_state_3_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_3_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_3_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_3_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_3_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_3_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_3_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_3_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_3_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_3_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_3_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_3_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_3_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_3_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_3_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_3_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_3_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_3_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_3_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000BC)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_OFFSET      0x000000BC
#define RIU_RC_RC_RX_RF_FSM_STATE_4_INDEX       0x0000002F
#define RIU_RC_RC_RX_RF_FSM_STATE_4_RESET       0x0000A2A1

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_state_4_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_4_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_4_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_4_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_4_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_4_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_2_RST    0x5
#define RIU_RC_RC_RX_RF_FSM_STATE_4_NEXT_STATE_1_RST    0x2
#define RIU_RC_RC_RX_RF_FSM_STATE_4_OUT_RST    0x1

__INLINE void riu_rc_rc_rx_rf_fsm_state_4_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_4_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_4_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_4_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_4_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_4_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_4_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_4_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_4_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_4_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_4_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_4_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_4_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_4_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_4_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_4_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_4_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_4_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_4_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000C0)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_OFFSET      0x000000C0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_INDEX       0x00000030
#define RIU_RC_RC_RX_RF_FSM_STATE_5_RESET       0x00002061

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_state_5_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_5_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_5_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_5_NEXT_STATE_1_RST    0x6
#define RIU_RC_RC_RX_RF_FSM_STATE_5_OUT_RST    0x1

__INLINE void riu_rc_rc_rx_rf_fsm_state_5_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_5_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_5_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_5_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_5_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_5_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_5_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_5_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_5_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_5_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_5_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_5_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_5_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_5_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_5_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_5_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_5_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_5_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_5_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000C4)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_OFFSET      0x000000C4
#define RIU_RC_RC_RX_RF_FSM_STATE_6_INDEX       0x00000031
#define RIU_RC_RC_RX_RF_FSM_STATE_6_RESET       0x00002000

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_state_6_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_6_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_RX_RF_FSM_STATE_6_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_RX_RF_FSM_STATE_6_OUT_LSB    0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_RX_RF_FSM_STATE_6_OUT_RST    0x0

__INLINE void riu_rc_rc_rx_rf_fsm_state_6_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_rx_rf_fsm_state_6_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_6_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_6_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_6_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_6_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_6_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_6_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_6_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_6_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_6_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_6_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_6_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_6_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_6_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_6_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_rx_rf_fsm_state_6_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_state_6_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
}

/**
 * @brief RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000C8)
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_OFFSET      0x000000C8
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_INDEX       0x00000032
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_s_0_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_s_0_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

__INLINE uint32_t riu_rc_rc_rx_rf_fsm_s_0_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_s_0_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_0_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0xA
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000CC)
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_OFFSET      0x000000CC
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_INDEX       0x00000033
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_RESET       0x0000000A

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_s_1_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_s_1_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0xA

__INLINE uint32_t riu_rc_rc_rx_rf_fsm_s_1_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_s_1_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_1_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x0
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000D0)
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_OFFSET      0x000000D0
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_INDEX       0x00000034
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_s_2_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_s_2_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x0

__INLINE uint32_t riu_rc_rc_rx_rf_fsm_s_2_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_s_2_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_2_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x20
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000D4)
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_OFFSET      0x000000D4
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_INDEX       0x00000035
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_RESET       0x00000020

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_s_3_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_s_3_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x20

__INLINE uint32_t riu_rc_rc_rx_rf_fsm_s_3_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_s_3_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_3_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x10
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000D8)
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_OFFSET      0x000000D8
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_INDEX       0x00000036
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_RESET       0x00000010

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_s_4_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_s_4_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x10

__INLINE uint32_t riu_rc_rc_rx_rf_fsm_s_4_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_s_4_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_4_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0xA
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000DC)
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_OFFSET      0x000000DC
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_INDEX       0x00000037
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_RESET       0x0000000A

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_s_5_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_s_5_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0xA

__INLINE uint32_t riu_rc_rc_rx_rf_fsm_s_5_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_s_5_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_5_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000E0)
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_OFFSET      0x000000E0
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_INDEX       0x00000038
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_RESET       0x00000005

__INLINE uint32_t  riu_rc_rc_rx_rf_fsm_s_6_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_fsm_s_6_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

__INLINE uint32_t riu_rc_rc_rx_rf_fsm_s_6_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_rf_fsm_s_6_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
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
#define RIU_RC_RC_RX_RF_SW_CTRL_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000E4)
#define RIU_RC_RC_RX_RF_SW_CTRL_OFFSET      0x000000E4
#define RIU_RC_RC_RX_RF_SW_CTRL_INDEX       0x00000039
#define RIU_RC_RC_RX_RF_SW_CTRL_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_rf_sw_ctrl_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_RF_SW_CTRL_ADDR);
}

__INLINE void riu_rc_rc_rx_rf_sw_ctrl_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_RF_SW_CTRL_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_VALID_BIT    ((uint32_t)0x00000008)
#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_VALID_POS    3
#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_MASK    ((uint32_t)0x00000007)
#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_LSB    0
#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_WIDTH    ((uint32_t)0x00000003)

#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_VALID_RST    0x0
#define RIU_RC_RC_RX_RF_SW_CTRL_GOTO_STATE_RST    0x0

__INLINE void riu_rc_rc_rx_rf_sw_ctrl_pack(uint8_t goto_state_valid, uint8_t goto_state)
{
	ASSERT_ERR((((uint32_t)goto_state_valid << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)goto_state << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_SW_CTRL_ADDR,  ((uint32_t)goto_state_valid << 3) |((uint32_t)goto_state << 0));
}

__INLINE void riu_rc_rc_rx_rf_sw_ctrl_unpack(uint8_t* goto_state_valid, uint8_t* goto_state)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_SW_CTRL_ADDR);

	*goto_state_valid = (localVal & ((uint32_t)0x00000008)) >>  3;
	*goto_state = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_rf_sw_ctrl_goto_state_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void riu_rc_rc_rx_rf_sw_ctrl_goto_state_valid_setf(uint8_t gotostatevalid)
{
	ASSERT_ERR((((uint32_t)gotostatevalid << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_SW_CTRL_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_SW_CTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)gotostatevalid <<3));
}
__INLINE uint8_t riu_rc_rc_rx_rf_sw_ctrl_goto_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_RF_SW_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void riu_rc_rc_rx_rf_sw_ctrl_goto_state_setf(uint8_t gotostate)
{
	ASSERT_ERR((((uint32_t)gotostate << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_RF_SW_CTRL_ADDR, (REG_PL_RD(RIU_RC_RC_RX_RF_SW_CTRL_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)gotostate <<0));
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
#define RIU_RC_RC_RX_FSM_STATUS_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000E8)
#define RIU_RC_RC_RX_FSM_STATUS_OFFSET      0x000000E8
#define RIU_RC_RC_RX_FSM_STATUS_INDEX       0x0000003A
#define RIU_RC_RC_RX_FSM_STATUS_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_fsm_status_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_FSM_STATUS_ADDR);
}

// field definitions
#define RIU_RC_RC_RX_FSM_STATUS_RX_RF_FSM_STAT_MASK    ((uint32_t)0x00000038)
#define RIU_RC_RC_RX_FSM_STATUS_RX_RF_FSM_STAT_LSB    3
#define RIU_RC_RC_RX_FSM_STATUS_RX_RF_FSM_STAT_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_RX_FSM_STATUS_RX_ADC_FSM_STAT_MASK    ((uint32_t)0x00000007)
#define RIU_RC_RC_RX_FSM_STATUS_RX_ADC_FSM_STAT_LSB    0
#define RIU_RC_RC_RX_FSM_STATUS_RX_ADC_FSM_STAT_WIDTH    ((uint32_t)0x00000003)

#define RIU_RC_RC_RX_FSM_STATUS_RX_RF_FSM_STAT_RST    0x0
#define RIU_RC_RC_RX_FSM_STATUS_RX_ADC_FSM_STAT_RST    0x0

__INLINE void riu_rc_rc_rx_fsm_status_unpack(uint8_t* rx_rf_fsm_stat, uint8_t* rx_adc_fsm_stat)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_FSM_STATUS_ADDR);

	*rx_rf_fsm_stat = (localVal & ((uint32_t)0x00000038)) >>  3;
	*rx_adc_fsm_stat = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_fsm_status_rx_rf_fsm_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_FSM_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE uint8_t riu_rc_rc_rx_fsm_status_rx_adc_fsm_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_FSM_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief RC_RX_TO_RIU_TIMERS_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RC_RX_ACK_ON_CLKS         0x79
 * </pre>
 */
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000EC)
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_OFFSET      0x000000EC
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_INDEX       0x0000003B
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_RESET       0x00000079

__INLINE uint32_t  riu_rc_rc_rx_to_riu_timers_0_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_TO_RIU_TIMERS_0_ADDR);
}

__INLINE void riu_rc_rc_rx_to_riu_timers_0_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_TO_RIU_TIMERS_0_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_RC_RX_ACK_ON_CLKS_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_RC_RX_ACK_ON_CLKS_LSB    0
#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_RC_RX_ACK_ON_CLKS_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_TO_RIU_TIMERS_0_RC_RX_ACK_ON_CLKS_RST    0x79

__INLINE uint32_t riu_rc_rc_rx_to_riu_timers_0_rc_rx_ack_on_clks_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_TO_RIU_TIMERS_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_to_riu_timers_0_rc_rx_ack_on_clks_setf(uint32_t rcrxackonclks)
{
	ASSERT_ERR((((uint32_t)rcrxackonclks << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_TO_RIU_TIMERS_0_ADDR, (uint32_t)rcrxackonclks << 0);
}

/**
 * @brief RC_RX_TO_RIU_TIMERS_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RC_RX_ACK_OFF_CLKS        0xf
 * </pre>
 */
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000F0)
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_OFFSET      0x000000F0
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_INDEX       0x0000003C
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_RESET       0x0000000F

__INLINE uint32_t  riu_rc_rc_rx_to_riu_timers_1_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_TO_RIU_TIMERS_1_ADDR);
}

__INLINE void riu_rc_rc_rx_to_riu_timers_1_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_TO_RIU_TIMERS_1_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_RC_RX_ACK_OFF_CLKS_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_RC_RX_ACK_OFF_CLKS_LSB    0
#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_RC_RX_ACK_OFF_CLKS_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_RX_TO_RIU_TIMERS_1_RC_RX_ACK_OFF_CLKS_RST    0xf

__INLINE uint32_t riu_rc_rc_rx_to_riu_timers_1_rc_rx_ack_off_clks_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_TO_RIU_TIMERS_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_to_riu_timers_1_rc_rx_ack_off_clks_setf(uint32_t rcrxackoffclks)
{
	ASSERT_ERR((((uint32_t)rcrxackoffclks << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_TO_RIU_TIMERS_1_ADDR, (uint32_t)rcrxackoffclks << 0);
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
#define RIU_RC_RC_RX_FORCE_GAIN_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000F4)
#define RIU_RC_RC_RX_FORCE_GAIN_OFFSET      0x000000F4
#define RIU_RC_RC_RX_FORCE_GAIN_INDEX       0x0000003D
#define RIU_RC_RC_RX_FORCE_GAIN_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_force_gain_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_FORCE_GAIN_ADDR);
}

__INLINE void riu_rc_rc_rx_force_gain_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_FORCE_GAIN_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_FORCE_GAIN_RX_GAIN_FORCE_EN_BIT    ((uint32_t)0x00040000)
#define RIU_RC_RC_RX_FORCE_GAIN_RX_GAIN_FORCE_EN_POS    18
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_1_MASK    ((uint32_t)0x0003FE00)
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_1_LSB    9
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_1_WIDTH    ((uint32_t)0x00000009)
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_0_MASK    ((uint32_t)0x000001FF)
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_0_LSB    0
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_0_WIDTH    ((uint32_t)0x00000009)

#define RIU_RC_RC_RX_FORCE_GAIN_RX_GAIN_FORCE_EN_RST    0x0
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_1_RST    0x0
#define RIU_RC_RC_RX_FORCE_GAIN_FORCE_RX_GAIN_0_RST    0x0

__INLINE void riu_rc_rc_rx_force_gain_pack(uint8_t rx_gain_force_en, uint16_t force_rx_gain_1, uint16_t force_rx_gain_0)
{
	ASSERT_ERR((((uint32_t)rx_gain_force_en << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)force_rx_gain_1 << 9) & ~((uint32_t)0x0003FE00)) == 0);
	ASSERT_ERR((((uint32_t)force_rx_gain_0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_FORCE_GAIN_ADDR,  ((uint32_t)rx_gain_force_en << 18) |((uint32_t)force_rx_gain_1 << 9) |((uint32_t)force_rx_gain_0 << 0));
}

__INLINE void riu_rc_rc_rx_force_gain_unpack(uint8_t* rx_gain_force_en, uint16_t* force_rx_gain_1, uint16_t* force_rx_gain_0)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_FORCE_GAIN_ADDR);

	*rx_gain_force_en = (localVal & ((uint32_t)0x00040000)) >>  18;
	*force_rx_gain_1 = (localVal & ((uint32_t)0x0003FE00)) >>  9;
	*force_rx_gain_0 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_force_gain_rx_gain_force_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_FORCE_GAIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void riu_rc_rc_rx_force_gain_rx_gain_force_en_setf(uint8_t rxgainforceen)
{
	ASSERT_ERR((((uint32_t)rxgainforceen << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_FORCE_GAIN_ADDR, (REG_PL_RD(RIU_RC_RC_RX_FORCE_GAIN_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)rxgainforceen <<18));
}
__INLINE uint16_t riu_rc_rc_rx_force_gain_force_rx_gain_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_FORCE_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0003FE00)) >> 9);
}
__INLINE void riu_rc_rc_rx_force_gain_force_rx_gain_1_setf(uint16_t forcerxgain1)
{
	ASSERT_ERR((((uint32_t)forcerxgain1 << 9) & ~((uint32_t)0x0003FE00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_FORCE_GAIN_ADDR, (REG_PL_RD(RIU_RC_RC_RX_FORCE_GAIN_ADDR) & ~((uint32_t)0x0003FE00)) | ((uint32_t)forcerxgain1 <<9));
}
__INLINE uint16_t riu_rc_rc_rx_force_gain_force_rx_gain_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_FORCE_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void riu_rc_rc_rx_force_gain_force_rx_gain_0_setf(uint16_t forcerxgain0)
{
	ASSERT_ERR((((uint32_t)forcerxgain0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_FORCE_GAIN_ADDR, (REG_PL_RD(RIU_RC_RC_RX_FORCE_GAIN_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)forcerxgain0 <<0));
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
#define RIU_RC_RC_RX_INITIAL_GAIN_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000F8)
#define RIU_RC_RC_RX_INITIAL_GAIN_OFFSET      0x000000F8
#define RIU_RC_RC_RX_INITIAL_GAIN_INDEX       0x0000003E
#define RIU_RC_RC_RX_INITIAL_GAIN_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_initial_gain_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_INITIAL_GAIN_ADDR);
}

__INLINE void riu_rc_rc_rx_initial_gain_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_INITIAL_GAIN_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_1_MASK    ((uint32_t)0x0003FE00)
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_1_LSB    9
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_1_WIDTH    ((uint32_t)0x00000009)
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_0_MASK    ((uint32_t)0x000001FF)
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_0_LSB    0
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_0_WIDTH    ((uint32_t)0x00000009)

#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_1_RST    0x0
#define RIU_RC_RC_RX_INITIAL_GAIN_INITIAL_RX_GAIN_0_RST    0x0

__INLINE void riu_rc_rc_rx_initial_gain_pack(uint16_t initial_rx_gain_1, uint16_t initial_rx_gain_0)
{
	ASSERT_ERR((((uint32_t)initial_rx_gain_1 << 9) & ~((uint32_t)0x0003FE00)) == 0);
	ASSERT_ERR((((uint32_t)initial_rx_gain_0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_INITIAL_GAIN_ADDR,  ((uint32_t)initial_rx_gain_1 << 9) |((uint32_t)initial_rx_gain_0 << 0));
}

__INLINE void riu_rc_rc_rx_initial_gain_unpack(uint16_t* initial_rx_gain_1, uint16_t* initial_rx_gain_0)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_INITIAL_GAIN_ADDR);

	*initial_rx_gain_1 = (localVal & ((uint32_t)0x0003FE00)) >>  9;
	*initial_rx_gain_0 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t riu_rc_rc_rx_initial_gain_initial_rx_gain_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_INITIAL_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0003FE00)) >> 9);
}
__INLINE void riu_rc_rc_rx_initial_gain_initial_rx_gain_1_setf(uint16_t initialrxgain1)
{
	ASSERT_ERR((((uint32_t)initialrxgain1 << 9) & ~((uint32_t)0x0003FE00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_INITIAL_GAIN_ADDR, (REG_PL_RD(RIU_RC_RC_RX_INITIAL_GAIN_ADDR) & ~((uint32_t)0x0003FE00)) | ((uint32_t)initialrxgain1 <<9));
}
__INLINE uint16_t riu_rc_rc_rx_initial_gain_initial_rx_gain_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_INITIAL_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void riu_rc_rc_rx_initial_gain_initial_rx_gain_0_setf(uint16_t initialrxgain0)
{
	ASSERT_ERR((((uint32_t)initialrxgain0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_INITIAL_GAIN_ADDR, (REG_PL_RD(RIU_RC_RC_RX_INITIAL_GAIN_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)initialrxgain0 <<0));
}

/**
 * @brief RC_RX_INITIAL_FRAC_FREQ register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    INITIAL_RX_FRAC_FREQ      0              
 * </pre>
 */
#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_ADDR        (REG_RIU_RC_BASE_ADDR+0x000000FC)
#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_OFFSET      0x000000FC
#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_INDEX       0x0000003F
#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_initial_frac_freq_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_INITIAL_FRAC_FREQ_ADDR);
}

__INLINE void riu_rc_rc_rx_initial_frac_freq_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_INITIAL_FRAC_FREQ_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_INITIAL_RX_FRAC_FREQ_BIT    ((uint32_t)0x00000001)
#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_INITIAL_RX_FRAC_FREQ_POS    0

#define RIU_RC_RC_RX_INITIAL_FRAC_FREQ_INITIAL_RX_FRAC_FREQ_RST    0x0

__INLINE uint8_t riu_rc_rc_rx_initial_frac_freq_initial_rx_frac_freq_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_INITIAL_FRAC_FREQ_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_rx_initial_frac_freq_initial_rx_frac_freq_setf(uint8_t initialrxfracfreq)
{
	ASSERT_ERR((((uint32_t)initialrxfracfreq << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_INITIAL_FRAC_FREQ_ADDR, (uint32_t)initialrxfracfreq << 0);
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
#define RIU_RC_RC_RX_GAIN_STATUS_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000100)
#define RIU_RC_RC_RX_GAIN_STATUS_OFFSET      0x00000100
#define RIU_RC_RC_RX_GAIN_STATUS_INDEX       0x00000040
#define RIU_RC_RC_RX_GAIN_STATUS_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_gain_status_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_GAIN_STATUS_ADDR);
}

// field definitions
#define RIU_RC_RC_RX_GAIN_STATUS_CH_1_RX_GAIN_STAT_MASK    ((uint32_t)0x0003FE00)
#define RIU_RC_RC_RX_GAIN_STATUS_CH_1_RX_GAIN_STAT_LSB    9
#define RIU_RC_RC_RX_GAIN_STATUS_CH_1_RX_GAIN_STAT_WIDTH    ((uint32_t)0x00000009)
#define RIU_RC_RC_RX_GAIN_STATUS_CH_0_RX_GAIN_STAT_MASK    ((uint32_t)0x000001FF)
#define RIU_RC_RC_RX_GAIN_STATUS_CH_0_RX_GAIN_STAT_LSB    0
#define RIU_RC_RC_RX_GAIN_STATUS_CH_0_RX_GAIN_STAT_WIDTH    ((uint32_t)0x00000009)

#define RIU_RC_RC_RX_GAIN_STATUS_CH_1_RX_GAIN_STAT_RST    0x0
#define RIU_RC_RC_RX_GAIN_STATUS_CH_0_RX_GAIN_STAT_RST    0x0

__INLINE void riu_rc_rc_rx_gain_status_unpack(uint16_t* ch_1_rx_gain_stat, uint16_t* ch_0_rx_gain_stat)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_GAIN_STATUS_ADDR);

	*ch_1_rx_gain_stat = (localVal & ((uint32_t)0x0003FE00)) >>  9;
	*ch_0_rx_gain_stat = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t riu_rc_rc_rx_gain_status_ch_1_rx_gain_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_GAIN_STATUS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0003FE00)) >> 9);
}
__INLINE uint16_t riu_rc_rc_rx_gain_status_ch_0_rx_gain_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_GAIN_STATUS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
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
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000104)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_OFFSET      0x00000104
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_INDEX       0x00000041
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RESET       0x80000000

__INLINE uint32_t  riu_rc_rc_unallocated_chain_config_get(void)
{
	return REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);
}

__INLINE void riu_rc_rc_unallocated_chain_config_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, value);
}

// field definitions
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RC_SW_ENABLE_BIT    ((uint32_t)0x80000000)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RC_SW_ENABLE_POS    31
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADC_OUT_MASK    ((uint32_t)0x1E000000)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADC_OUT_LSB    25
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADC_OUT_WIDTH    ((uint32_t)0x00000004)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_DAC_OUT_MASK    ((uint32_t)0x01E00000)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_DAC_OUT_LSB    21
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_DAC_OUT_WIDTH    ((uint32_t)0x00000004)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_3_MASK    ((uint32_t)0x001FE000)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_3_LSB    13
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_3_WIDTH    ((uint32_t)0x00000008)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_2_MASK    ((uint32_t)0x00001FF0)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_2_LSB    4
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_2_WIDTH    ((uint32_t)0x00000009)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_1_MASK    ((uint32_t)0x0000000E)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_1_LSB    1
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_0_BIT    ((uint32_t)0x00000001)
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_0_POS    0

#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RC_SW_ENABLE_RST    0x1
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADC_OUT_RST    0x0
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_DAC_OUT_RST    0x0
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_3_RST    0x0
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_2_RST    0x0
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_1_RST    0x0
#define RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_RF_OUT_0_RST    0x0

__INLINE void riu_rc_rc_unallocated_chain_config_pack(uint8_t rc_sw_enable, uint8_t adc_out, uint8_t dac_out, uint8_t rf_out_3, uint16_t rf_out_2, uint8_t rf_out_1, uint8_t rf_out_0)
{
	ASSERT_ERR((((uint32_t)rc_sw_enable << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)adc_out << 25) & ~((uint32_t)0x1E000000)) == 0);
	ASSERT_ERR((((uint32_t)dac_out << 21) & ~((uint32_t)0x01E00000)) == 0);
	ASSERT_ERR((((uint32_t)rf_out_3 << 13) & ~((uint32_t)0x001FE000)) == 0);
	ASSERT_ERR((((uint32_t)rf_out_2 << 4) & ~((uint32_t)0x00001FF0)) == 0);
	ASSERT_ERR((((uint32_t)rf_out_1 << 1) & ~((uint32_t)0x0000000E)) == 0);
	ASSERT_ERR((((uint32_t)rf_out_0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR,  ((uint32_t)rc_sw_enable << 31) |((uint32_t)adc_out << 25) |((uint32_t)dac_out << 21) |((uint32_t)rf_out_3 << 13) |((uint32_t)rf_out_2 << 4) |((uint32_t)rf_out_1 << 1) |((uint32_t)rf_out_0 << 0));
}

__INLINE void riu_rc_rc_unallocated_chain_config_unpack(uint8_t* rc_sw_enable, uint8_t* adc_out, uint8_t* dac_out, uint8_t* rf_out_3, uint16_t* rf_out_2, uint8_t* rf_out_1, uint8_t* rf_out_0)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);

	*rc_sw_enable = (localVal & ((uint32_t)0x80000000)) >>  31;
	*adc_out = (localVal & ((uint32_t)0x1E000000)) >>  25;
	*dac_out = (localVal & ((uint32_t)0x01E00000)) >>  21;
	*rf_out_3 = (localVal & ((uint32_t)0x001FE000)) >>  13;
	*rf_out_2 = (localVal & ((uint32_t)0x00001FF0)) >>  4;
	*rf_out_1 = (localVal & ((uint32_t)0x0000000E)) >>  1;
	*rf_out_0 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t riu_rc_rc_unallocated_chain_config_rc_sw_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void riu_rc_rc_unallocated_chain_config_rc_sw_enable_setf(uint8_t rcswenable)
{
	ASSERT_ERR((((uint32_t)rcswenable << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)rcswenable <<31));
}
__INLINE uint8_t riu_rc_rc_unallocated_chain_config_adc_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1E000000)) >> 25);
}
__INLINE void riu_rc_rc_unallocated_chain_config_adc_out_setf(uint8_t adcout)
{
	ASSERT_ERR((((uint32_t)adcout << 25) & ~((uint32_t)0x1E000000)) == 0);
	REG_PL_WR(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((uint32_t)0x1E000000)) | ((uint32_t)adcout <<25));
}
__INLINE uint8_t riu_rc_rc_unallocated_chain_config_dac_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01E00000)) >> 21);
}
__INLINE void riu_rc_rc_unallocated_chain_config_dac_out_setf(uint8_t dacout)
{
	ASSERT_ERR((((uint32_t)dacout << 21) & ~((uint32_t)0x01E00000)) == 0);
	REG_PL_WR(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((uint32_t)0x01E00000)) | ((uint32_t)dacout <<21));
}
__INLINE uint8_t riu_rc_rc_unallocated_chain_config_rf_out_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001FE000)) >> 13);
}
__INLINE void riu_rc_rc_unallocated_chain_config_rf_out_3_setf(uint8_t rfout3)
{
	ASSERT_ERR((((uint32_t)rfout3 << 13) & ~((uint32_t)0x001FE000)) == 0);
	REG_PL_WR(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((uint32_t)0x001FE000)) | ((uint32_t)rfout3 <<13));
}
__INLINE uint16_t riu_rc_rc_unallocated_chain_config_rf_out_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00001FF0)) >> 4);
}
__INLINE void riu_rc_rc_unallocated_chain_config_rf_out_2_setf(uint16_t rfout2)
{
	ASSERT_ERR((((uint32_t)rfout2 << 4) & ~((uint32_t)0x00001FF0)) == 0);
	REG_PL_WR(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((uint32_t)0x00001FF0)) | ((uint32_t)rfout2 <<4));
}
__INLINE uint8_t riu_rc_rc_unallocated_chain_config_rf_out_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000E)) >> 1);
}
__INLINE void riu_rc_rc_unallocated_chain_config_rf_out_1_setf(uint8_t rfout1)
{
	ASSERT_ERR((((uint32_t)rfout1 << 1) & ~((uint32_t)0x0000000E)) == 0);
	REG_PL_WR(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((uint32_t)0x0000000E)) | ((uint32_t)rfout1 <<1));
}
__INLINE uint8_t riu_rc_rc_unallocated_chain_config_rf_out_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void riu_rc_rc_unallocated_chain_config_rf_out_0_setf(uint8_t rfout0)
{
	ASSERT_ERR((((uint32_t)rfout0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR, (REG_PL_RD(RIU_RC_RC_UNALLOCATED_CHAIN_CONFIG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rfout0 <<0));
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
#define RIU_RC_RC_RX_SW_GAIN_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000108)
#define RIU_RC_RC_RX_SW_GAIN_OFFSET      0x00000108
#define RIU_RC_RC_RX_SW_GAIN_INDEX       0x00000042
#define RIU_RC_RC_RX_SW_GAIN_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_rx_sw_gain_get(void)
{
	return REG_PL_RD(RIU_RC_RC_RX_SW_GAIN_ADDR);
}

__INLINE void riu_rc_rc_rx_sw_gain_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_RX_SW_GAIN_ADDR, value);
}

// field definitions
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_UPDATE_BIT    ((uint32_t)0x00040000)
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_UPDATE_POS    18
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_1_MASK    ((uint32_t)0x0003FE00)
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_1_LSB    9
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_1_WIDTH    ((uint32_t)0x00000009)
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_0_MASK    ((uint32_t)0x000001FF)
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_0_LSB    0
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_0_WIDTH    ((uint32_t)0x00000009)

#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_UPDATE_RST    0x0
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_1_RST    0x0
#define RIU_RC_RC_RX_SW_GAIN_RX_SW_GAIN_CH_0_RST    0x0

__INLINE void riu_rc_rc_rx_sw_gain_pack(uint8_t rx_sw_gain_update, uint16_t rx_sw_gain_ch1, uint16_t rx_sw_gain_ch0)
{
	ASSERT_ERR((((uint32_t)rx_sw_gain_update << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)rx_sw_gain_ch1 << 9) & ~((uint32_t)0x0003FE00)) == 0);
	ASSERT_ERR((((uint32_t)rx_sw_gain_ch0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_SW_GAIN_ADDR,  ((uint32_t)rx_sw_gain_update << 18) |((uint32_t)rx_sw_gain_ch1 << 9) |((uint32_t)rx_sw_gain_ch0 << 0));
}

__INLINE void riu_rc_rc_rx_sw_gain_unpack(uint8_t* rx_sw_gain_update, uint16_t* rx_sw_gain_ch1, uint16_t* rx_sw_gain_ch0)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_SW_GAIN_ADDR);

	*rx_sw_gain_update = (localVal & ((uint32_t)0x00040000)) >>  18;
	*rx_sw_gain_ch1 = (localVal & ((uint32_t)0x0003FE00)) >>  9;
	*rx_sw_gain_ch0 = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t riu_rc_rc_rx_sw_gain_rx_sw_gain_update_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_SW_GAIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void riu_rc_rc_rx_sw_gain_rx_sw_gain_update_setf(uint8_t rxswgainupdate)
{
	ASSERT_ERR((((uint32_t)rxswgainupdate << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_SW_GAIN_ADDR, (REG_PL_RD(RIU_RC_RC_RX_SW_GAIN_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)rxswgainupdate <<18));
}
__INLINE uint16_t riu_rc_rc_rx_sw_gain_rx_sw_gain_ch_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_SW_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0003FE00)) >> 9);
}
__INLINE void riu_rc_rc_rx_sw_gain_rx_sw_gain_ch_1_setf(uint16_t rxswgainch1)
{
	ASSERT_ERR((((uint32_t)rxswgainch1 << 9) & ~((uint32_t)0x0003FE00)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_SW_GAIN_ADDR, (REG_PL_RD(RIU_RC_RC_RX_SW_GAIN_ADDR) & ~((uint32_t)0x0003FE00)) | ((uint32_t)rxswgainch1 <<9));
}
__INLINE uint16_t riu_rc_rc_rx_sw_gain_rx_sw_gain_ch_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_RX_SW_GAIN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void riu_rc_rc_rx_sw_gain_rx_sw_gain_ch_0_setf(uint16_t rxswgainch0)
{
	ASSERT_ERR((((uint32_t)rxswgainch0 << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(RIU_RC_RC_RX_SW_GAIN_ADDR, (REG_PL_RD(RIU_RC_RC_RX_SW_GAIN_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)rxswgainch0 <<0));
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
#define RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR        (REG_RIU_RC_BASE_ADDR+0x0000010C)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_OFFSET      0x0000010C
#define RIU_RC_RC_TX_RF_FSM_STATE_6_INDEX       0x00000043
#define RIU_RC_RC_TX_RF_FSM_STATE_6_RESET       0x00002077

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_state_6_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_6_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_6_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_6_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_6_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_6_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_6_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_6_NEXT_STATE_1_RST    0x7
#define RIU_RC_RC_TX_RF_FSM_STATE_6_OUT_RST    0x7

__INLINE void riu_rc_rc_tx_rf_fsm_state_6_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_6_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_6_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_6_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_6_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_6_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_6_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_6_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_6_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_6_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_6_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_6_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_6_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_6_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_6_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_6_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_6_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_6_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_6_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
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
#define RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000110)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_OFFSET      0x00000110
#define RIU_RC_RC_TX_RF_FSM_STATE_7_INDEX       0x00000044
#define RIU_RC_RC_TX_RF_FSM_STATE_7_RESET       0x00002000

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_state_7_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_7_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_3_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_3_POS    16
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_2_BIT    ((uint32_t)0x00008000)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_2_POS    15
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00004000)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_1_POS    14
#define RIU_RC_RC_TX_RF_FSM_STATE_7_TIMER_EN_TO_NEXT_STATE_1_BIT    ((uint32_t)0x00002000)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_TIMER_EN_TO_NEXT_STATE_1_POS    13
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_3_MASK    ((uint32_t)0x00001C00)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_3_LSB    10
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_3_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_2_MASK    ((uint32_t)0x00000380)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_2_LSB    7
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_2_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_1_MASK    ((uint32_t)0x00000070)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_1_LSB    4
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000003)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_OUT_MASK    ((uint32_t)0x0000000F)
#define RIU_RC_RC_TX_RF_FSM_STATE_7_OUT_LSB    0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_OUT_WIDTH    ((uint32_t)0x00000004)

#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_EN_HW_SIGNAL_TO_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_TIMER_EN_TO_NEXT_STATE_1_RST    0x1
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_3_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_2_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_NEXT_STATE_1_RST    0x0
#define RIU_RC_RC_TX_RF_FSM_STATE_7_OUT_RST    0x0

__INLINE void riu_rc_rc_tx_rf_fsm_state_7_pack(uint8_t en_hw_signal_to_next_state_3, uint8_t en_hw_signal_to_next_state_2, uint8_t en_hw_signal_to_next_state_1, uint8_t timer_en_to_next_state_1, uint8_t next_state_3, uint8_t next_state_2, uint8_t next_state_1, uint8_t out)
{
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_3 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_2 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)en_hw_signal_to_next_state_1 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)timer_en_to_next_state_1 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)next_state_3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)next_state_2 << 7) & ~((uint32_t)0x00000380)) == 0);
	ASSERT_ERR((((uint32_t)next_state_1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR,  ((uint32_t)en_hw_signal_to_next_state_3 << 16) |((uint32_t)en_hw_signal_to_next_state_2 << 15) |((uint32_t)en_hw_signal_to_next_state_1 << 14) |((uint32_t)timer_en_to_next_state_1 << 13) |((uint32_t)next_state_3 << 10) |((uint32_t)next_state_2 << 7) |((uint32_t)next_state_1 << 4) |((uint32_t)out << 0));
}

__INLINE void riu_rc_rc_tx_rf_fsm_state_7_unpack(uint8_t* en_hw_signal_to_next_state_3, uint8_t* en_hw_signal_to_next_state_2, uint8_t* en_hw_signal_to_next_state_1, uint8_t* timer_en_to_next_state_1, uint8_t* next_state_3, uint8_t* next_state_2, uint8_t* next_state_1, uint8_t* out)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);

	*en_hw_signal_to_next_state_3 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*en_hw_signal_to_next_state_2 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*en_hw_signal_to_next_state_1 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*timer_en_to_next_state_1 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*next_state_3 = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*next_state_2 = (localVal & ((uint32_t)0x00000380)) >>  7;
	*next_state_1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*out = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_7_en_hw_signal_to_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_7_en_hw_signal_to_next_state_3_setf(uint8_t enhwsignaltonextstate3)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate3 << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)enhwsignaltonextstate3 <<16));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_7_en_hw_signal_to_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_7_en_hw_signal_to_next_state_2_setf(uint8_t enhwsignaltonextstate2)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate2 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)enhwsignaltonextstate2 <<15));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_7_en_hw_signal_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_7_en_hw_signal_to_next_state_1_setf(uint8_t enhwsignaltonextstate1)
{
	ASSERT_ERR((((uint32_t)enhwsignaltonextstate1 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)enhwsignaltonextstate1 <<14));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_7_timer_en_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_7_timer_en_to_next_state_1_setf(uint8_t timerentonextstate1)
{
	ASSERT_ERR((((uint32_t)timerentonextstate1 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)timerentonextstate1 <<13));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_7_next_state_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_7_next_state_3_setf(uint8_t nextstate3)
{
	ASSERT_ERR((((uint32_t)nextstate3 << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)nextstate3 <<10));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_7_next_state_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000380)) >> 7);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_7_next_state_2_setf(uint8_t nextstate2)
{
	ASSERT_ERR((((uint32_t)nextstate2 << 7) & ~((uint32_t)0x00000380)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((uint32_t)0x00000380)) | ((uint32_t)nextstate2 <<7));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_7_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_7_next_state_1_setf(uint8_t nextstate1)
{
	ASSERT_ERR((((uint32_t)nextstate1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)nextstate1 <<4));
}
__INLINE uint8_t riu_rc_rc_tx_rf_fsm_state_7_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_state_7_out_setf(uint8_t out)
{
	ASSERT_ERR((((uint32_t)out << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR, (REG_PL_RD(RIU_RC_RC_TX_RF_FSM_STATE_7_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)out <<0));
}

/**
 * @brief RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000114)
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_OFFSET      0x00000114
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_INDEX       0x00000045
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_RESET       0x00000005

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_s_6_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_s_6_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

__INLINE uint32_t riu_rc_rc_tx_rf_fsm_s_6_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_s_6_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_6_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
}

/**
 * @brief RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TIMER_TO_NEXT_STATE_1     0x5
 * </pre>
 */
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000118)
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_OFFSET      0x00000118
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_INDEX       0x00000046
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_RESET       0x00000005

__INLINE uint32_t  riu_rc_rc_tx_rf_fsm_s_7_to_next_state_timer_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_ADDR);
}

__INLINE void riu_rc_rc_tx_rf_fsm_s_7_to_next_state_timer_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_MASK    ((uint32_t)0xFFFFFFFF)
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_LSB    0
#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_WIDTH    ((uint32_t)0x00000020)

#define RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_TIMER_TO_NEXT_STATE_1_RST    0x5

__INLINE uint32_t riu_rc_rc_tx_rf_fsm_s_7_to_next_state_timer_timer_to_next_state_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void riu_rc_rc_tx_rf_fsm_s_7_to_next_state_timer_timer_to_next_state_1_setf(uint32_t timertonextstate1)
{
	ASSERT_ERR((((uint32_t)timertonextstate1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_RF_FSM_S_7_TO_NEXT_STATE_TIMER_ADDR, (uint32_t)timertonextstate1 << 0);
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
#define RIU_RC_RC_TX_INITIAL_GAIN_ADDR        (REG_RIU_RC_BASE_ADDR+0x0000011C)
#define RIU_RC_RC_TX_INITIAL_GAIN_OFFSET      0x0000011C
#define RIU_RC_RC_TX_INITIAL_GAIN_INDEX       0x00000047
#define RIU_RC_RC_TX_INITIAL_GAIN_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_tx_initial_gain_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_INITIAL_GAIN_ADDR);
}

__INLINE void riu_rc_rc_tx_initial_gain_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_INITIAL_GAIN_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_1_MASK    ((uint32_t)0x0000FF00)
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_1_LSB    8
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_1_WIDTH    ((uint32_t)0x00000008)
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_0_MASK    ((uint32_t)0x000000FF)
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_0_LSB    0
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_0_WIDTH    ((uint32_t)0x00000008)

#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_1_RST    0x0
#define RIU_RC_RC_TX_INITIAL_GAIN_INITIAL_TX_GAIN_0_RST    0x0

__INLINE void riu_rc_rc_tx_initial_gain_pack(uint8_t initial_tx_gain_1, uint8_t initial_tx_gain_0)
{
	ASSERT_ERR((((uint32_t)initial_tx_gain_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)initial_tx_gain_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_INITIAL_GAIN_ADDR,  ((uint32_t)initial_tx_gain_1 << 8) |((uint32_t)initial_tx_gain_0 << 0));
}

__INLINE void riu_rc_rc_tx_initial_gain_unpack(uint8_t* initial_tx_gain_1, uint8_t* initial_tx_gain_0)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_INITIAL_GAIN_ADDR);

	*initial_tx_gain_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*initial_tx_gain_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_initial_gain_initial_tx_gain_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_INITIAL_GAIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void riu_rc_rc_tx_initial_gain_initial_tx_gain_1_setf(uint8_t initialtxgain1)
{
	ASSERT_ERR((((uint32_t)initialtxgain1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_INITIAL_GAIN_ADDR, (REG_PL_RD(RIU_RC_RC_TX_INITIAL_GAIN_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)initialtxgain1 <<8));
}
__INLINE uint8_t riu_rc_rc_tx_initial_gain_initial_tx_gain_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_INITIAL_GAIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void riu_rc_rc_tx_initial_gain_initial_tx_gain_0_setf(uint8_t initialtxgain0)
{
	ASSERT_ERR((((uint32_t)initialtxgain0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_INITIAL_GAIN_ADDR, (REG_PL_RD(RIU_RC_RC_TX_INITIAL_GAIN_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)initialtxgain0 <<0));
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
#define RIU_RC_RC_TX_GAIN_2_ADDR        (REG_RIU_RC_BASE_ADDR+0x00000120)
#define RIU_RC_RC_TX_GAIN_2_OFFSET      0x00000120
#define RIU_RC_RC_TX_GAIN_2_INDEX       0x00000048
#define RIU_RC_RC_TX_GAIN_2_RESET       0x00000000

__INLINE uint32_t  riu_rc_rc_tx_gain_2_get(void)
{
	return REG_PL_RD(RIU_RC_RC_TX_GAIN_2_ADDR);
}

__INLINE void riu_rc_rc_tx_gain_2_set(uint32_t value)
{
	REG_PL_WR(RIU_RC_RC_TX_GAIN_2_ADDR, value);
}

// field definitions
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_UPDATE_BIT    ((uint32_t)0x00010000)
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_UPDATE_POS    16
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_1_MASK    ((uint32_t)0x0000FF00)
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_1_LSB    8
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_1_WIDTH    ((uint32_t)0x00000008)
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_0_MASK    ((uint32_t)0x000000FF)
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_0_LSB    0
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_0_WIDTH    ((uint32_t)0x00000008)

#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_UPDATE_RST    0x0
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_1_RST    0x0
#define RIU_RC_RC_TX_GAIN_2_TX_GAIN_2_CH_0_RST    0x0

__INLINE void riu_rc_rc_tx_gain_2_pack(uint8_t tx_gain_update, uint8_t tx_gain_2_ch_1, uint8_t tx_gain_2_ch_0)
{
	ASSERT_ERR((((uint32_t)tx_gain_update << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)tx_gain_2_ch_1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)tx_gain_2_ch_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_GAIN_2_ADDR,  ((uint32_t)tx_gain_update << 16) |((uint32_t)tx_gain_2_ch_1 << 8) |((uint32_t)tx_gain_2_ch_0 << 0));
}

__INLINE void riu_rc_rc_tx_gain_2_unpack(uint8_t* tx_gain_update, uint8_t* tx_gain_2_ch_1, uint8_t* tx_gain_2_ch_0)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_GAIN_2_ADDR);

	*tx_gain_update = (localVal & ((uint32_t)0x00010000)) >>  16;
	*tx_gain_2_ch_1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*tx_gain_2_ch_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t riu_rc_rc_tx_gain_2_tx_gain_update_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_GAIN_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void riu_rc_rc_tx_gain_2_tx_gain_update_setf(uint8_t txgainupdate)
{
	ASSERT_ERR((((uint32_t)txgainupdate << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_GAIN_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_GAIN_2_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)txgainupdate <<16));
}
__INLINE uint8_t riu_rc_rc_tx_gain_2_tx_gain_2_ch_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_GAIN_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void riu_rc_rc_tx_gain_2_tx_gain_2_ch_1_setf(uint8_t txgain2ch1)
{
	ASSERT_ERR((((uint32_t)txgain2ch1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_GAIN_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_GAIN_2_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)txgain2ch1 <<8));
}
__INLINE uint8_t riu_rc_rc_tx_gain_2_tx_gain_2_ch_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(RIU_RC_RC_TX_GAIN_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void riu_rc_rc_tx_gain_2_tx_gain_2_ch_0_setf(uint8_t txgain2ch0)
{
	ASSERT_ERR((((uint32_t)txgain2ch0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(RIU_RC_RC_TX_GAIN_2_ADDR, (REG_PL_RD(RIU_RC_RC_TX_GAIN_2_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)txgain2ch0 <<0));
}


#undef DBG_FILEID
#endif //_REG_RIU_RC_H_
