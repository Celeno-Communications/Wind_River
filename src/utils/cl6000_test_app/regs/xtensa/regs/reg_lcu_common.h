#ifndef _REG_LCU_COMMON_H_
#define _REG_LCU_COMMON_H_

#include <stdint.h>
#include "_reg_lcu_common.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_LCU_COMMON__H__FILEID__

#define REG_LCU_COMMON_COUNT  98


/**
 * @brief LCU_COMMON_VCI register definition
 *  VCI Registet register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:20 CH5_VCI                   0x0
 *    17:16 CH4_VCI                   0x0
 *    13:12 CH3_VCI                   0x0
 *    09:08 CH2_VCI                   0x0
 *    05:04 CH1_VCI                   0x0
 *    01:00 CH0_VCI                   0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_VCI_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000000)
#define LCU_COMMON_LCU_COMMON_VCI_OFFSET      0x00000000
#define LCU_COMMON_LCU_COMMON_VCI_INDEX       0x00000000
#define LCU_COMMON_LCU_COMMON_VCI_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_vci_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR);
}

__INLINE void lcu_common_lcu_common_vci_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_VCI_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_VCI_CH_5_VCI_MASK    ((uint32_t)0x00300000)
#define LCU_COMMON_LCU_COMMON_VCI_CH_5_VCI_LSB    20
#define LCU_COMMON_LCU_COMMON_VCI_CH_5_VCI_WIDTH    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_VCI_CH_4_VCI_MASK    ((uint32_t)0x00030000)
#define LCU_COMMON_LCU_COMMON_VCI_CH_4_VCI_LSB    16
#define LCU_COMMON_LCU_COMMON_VCI_CH_4_VCI_WIDTH    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_VCI_CH_3_VCI_MASK    ((uint32_t)0x00003000)
#define LCU_COMMON_LCU_COMMON_VCI_CH_3_VCI_LSB    12
#define LCU_COMMON_LCU_COMMON_VCI_CH_3_VCI_WIDTH    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_VCI_CH_2_VCI_MASK    ((uint32_t)0x00000300)
#define LCU_COMMON_LCU_COMMON_VCI_CH_2_VCI_LSB    8
#define LCU_COMMON_LCU_COMMON_VCI_CH_2_VCI_WIDTH    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_VCI_CH_1_VCI_MASK    ((uint32_t)0x00000030)
#define LCU_COMMON_LCU_COMMON_VCI_CH_1_VCI_LSB    4
#define LCU_COMMON_LCU_COMMON_VCI_CH_1_VCI_WIDTH    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_VCI_CH_0_VCI_MASK    ((uint32_t)0x00000003)
#define LCU_COMMON_LCU_COMMON_VCI_CH_0_VCI_LSB    0
#define LCU_COMMON_LCU_COMMON_VCI_CH_0_VCI_WIDTH    ((uint32_t)0x00000002)

#define LCU_COMMON_LCU_COMMON_VCI_CH_5_VCI_RST    0x0
#define LCU_COMMON_LCU_COMMON_VCI_CH_4_VCI_RST    0x0
#define LCU_COMMON_LCU_COMMON_VCI_CH_3_VCI_RST    0x0
#define LCU_COMMON_LCU_COMMON_VCI_CH_2_VCI_RST    0x0
#define LCU_COMMON_LCU_COMMON_VCI_CH_1_VCI_RST    0x0
#define LCU_COMMON_LCU_COMMON_VCI_CH_0_VCI_RST    0x0

__INLINE void lcu_common_lcu_common_vci_pack(uint8_t ch5_vci, uint8_t ch4_vci, uint8_t ch3_vci, uint8_t ch2_vci, uint8_t ch1_vci, uint8_t ch0_vci)
{
	ASSERT_ERR((((uint32_t)ch5_vci << 20) & ~((uint32_t)0x00300000)) == 0);
	ASSERT_ERR((((uint32_t)ch4_vci << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ch3_vci << 12) & ~((uint32_t)0x00003000)) == 0);
	ASSERT_ERR((((uint32_t)ch2_vci << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)ch1_vci << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)ch0_vci << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_VCI_ADDR,  ((uint32_t)ch5_vci << 20) |((uint32_t)ch4_vci << 16) |((uint32_t)ch3_vci << 12) |((uint32_t)ch2_vci << 8) |((uint32_t)ch1_vci << 4) |((uint32_t)ch0_vci << 0));
}

__INLINE void lcu_common_lcu_common_vci_unpack(uint8_t* ch5_vci, uint8_t* ch4_vci, uint8_t* ch3_vci, uint8_t* ch2_vci, uint8_t* ch1_vci, uint8_t* ch0_vci)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR);

	*ch5_vci = (localVal & ((uint32_t)0x00300000)) >>  20;
	*ch4_vci = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ch3_vci = (localVal & ((uint32_t)0x00003000)) >>  12;
	*ch2_vci = (localVal & ((uint32_t)0x00000300)) >>  8;
	*ch1_vci = (localVal & ((uint32_t)0x00000030)) >>  4;
	*ch0_vci = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_vci_ch_5_vci_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00300000)) >> 20);
}
__INLINE void lcu_common_lcu_common_vci_ch_5_vci_setf(uint8_t ch5vci)
{
	ASSERT_ERR((((uint32_t)ch5vci << 20) & ~((uint32_t)0x00300000)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_VCI_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)ch5vci <<20));
}
__INLINE uint8_t lcu_common_lcu_common_vci_ch_4_vci_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void lcu_common_lcu_common_vci_ch_4_vci_setf(uint8_t ch4vci)
{
	ASSERT_ERR((((uint32_t)ch4vci << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_VCI_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)ch4vci <<16));
}
__INLINE uint8_t lcu_common_lcu_common_vci_ch_3_vci_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003000)) >> 12);
}
__INLINE void lcu_common_lcu_common_vci_ch_3_vci_setf(uint8_t ch3vci)
{
	ASSERT_ERR((((uint32_t)ch3vci << 12) & ~((uint32_t)0x00003000)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_VCI_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)ch3vci <<12));
}
__INLINE uint8_t lcu_common_lcu_common_vci_ch_2_vci_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void lcu_common_lcu_common_vci_ch_2_vci_setf(uint8_t ch2vci)
{
	ASSERT_ERR((((uint32_t)ch2vci << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_VCI_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)ch2vci <<8));
}
__INLINE uint8_t lcu_common_lcu_common_vci_ch_1_vci_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void lcu_common_lcu_common_vci_ch_1_vci_setf(uint8_t ch1vci)
{
	ASSERT_ERR((((uint32_t)ch1vci << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_VCI_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)ch1vci <<4));
}
__INLINE uint8_t lcu_common_lcu_common_vci_ch_0_vci_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void lcu_common_lcu_common_vci_ch_0_vci_setf(uint8_t ch0vci)
{
	ASSERT_ERR((((uint32_t)ch0vci << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_VCI_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_VCI_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)ch0vci <<0));
}

/**
 * @brief LCU_COMMON_REC_FIRST_SAMP_TS register definition
 *  Time Stamp of the first sample register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 REC_FIRST_SAMP_TS         0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_REC_FIRST_SAMP_TS_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000004)
#define LCU_COMMON_LCU_COMMON_REC_FIRST_SAMP_TS_OFFSET      0x00000004
#define LCU_COMMON_LCU_COMMON_REC_FIRST_SAMP_TS_INDEX       0x00000001
#define LCU_COMMON_LCU_COMMON_REC_FIRST_SAMP_TS_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_rec_first_samp_ts_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_FIRST_SAMP_TS_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_REC_FIRST_SAMP_TS_REC_FIRST_SAMP_TS_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_REC_FIRST_SAMP_TS_REC_FIRST_SAMP_TS_LSB    0
#define LCU_COMMON_LCU_COMMON_REC_FIRST_SAMP_TS_REC_FIRST_SAMP_TS_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_REC_FIRST_SAMP_TS_REC_FIRST_SAMP_TS_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_rec_first_samp_ts_rec_first_samp_ts_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_FIRST_SAMP_TS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_REC_START_TS register definition
 *  Time Stamp of the start trigger register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 REC_START_TS              0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_REC_START_TS_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000008)
#define LCU_COMMON_LCU_COMMON_REC_START_TS_OFFSET      0x00000008
#define LCU_COMMON_LCU_COMMON_REC_START_TS_INDEX       0x00000002
#define LCU_COMMON_LCU_COMMON_REC_START_TS_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_rec_start_ts_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_START_TS_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_REC_START_TS_REC_START_TS_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_REC_START_TS_REC_START_TS_LSB    0
#define LCU_COMMON_LCU_COMMON_REC_START_TS_REC_START_TS_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_REC_START_TS_REC_START_TS_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_rec_start_ts_rec_start_ts_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_START_TS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_REC_END_TS register definition
 *  Time Stamp of the last sample register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 REC_END_TS                0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_REC_END_TS_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000000C)
#define LCU_COMMON_LCU_COMMON_REC_END_TS_OFFSET      0x0000000C
#define LCU_COMMON_LCU_COMMON_REC_END_TS_INDEX       0x00000003
#define LCU_COMMON_LCU_COMMON_REC_END_TS_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_rec_end_ts_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_END_TS_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_REC_END_TS_REC_END_TS_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_REC_END_TS_REC_END_TS_LSB    0
#define LCU_COMMON_LCU_COMMON_REC_END_TS_REC_END_TS_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_REC_END_TS_REC_END_TS_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_rec_end_ts_rec_end_ts_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_END_TS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_REC_STOP_TS register definition
 *  Time Stamp when a stop trigger is accepted register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 REC_STOP_TS               0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_REC_STOP_TS_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000010)
#define LCU_COMMON_LCU_COMMON_REC_STOP_TS_OFFSET      0x00000010
#define LCU_COMMON_LCU_COMMON_REC_STOP_TS_INDEX       0x00000004
#define LCU_COMMON_LCU_COMMON_REC_STOP_TS_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_rec_stop_ts_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_STOP_TS_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_REC_STOP_TS_REC_STOP_TS_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_REC_STOP_TS_REC_STOP_TS_LSB    0
#define LCU_COMMON_LCU_COMMON_REC_STOP_TS_REC_STOP_TS_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_REC_STOP_TS_REC_STOP_TS_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_rec_stop_ts_rec_stop_ts_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_STOP_TS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_BUF_START_ADDR register definition
 *  Recording buffer start address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BUF_START_ADDR            0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_BUF_START_ADDR_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000014)
#define LCU_COMMON_LCU_COMMON_BUF_START_ADDR_OFFSET      0x00000014
#define LCU_COMMON_LCU_COMMON_BUF_START_ADDR_INDEX       0x00000005
#define LCU_COMMON_LCU_COMMON_BUF_START_ADDR_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_buf_start_addr_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_BUF_START_ADDR_ADDR);
}

__INLINE void lcu_common_lcu_common_buf_start_addr_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_BUF_START_ADDR_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_BUF_START_ADDR_BUF_START_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_BUF_START_ADDR_BUF_START_ADDR_LSB    0
#define LCU_COMMON_LCU_COMMON_BUF_START_ADDR_BUF_START_ADDR_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_BUF_START_ADDR_BUF_START_ADDR_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_buf_start_addr_buf_start_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_BUF_START_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_common_buf_start_addr_buf_start_addr_setf(uint32_t bufstartaddr)
{
	ASSERT_ERR((((uint32_t)bufstartaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_BUF_START_ADDR_ADDR, (uint32_t)bufstartaddr << 0);
}

/**
 * @brief LCU_COMMON_BUF_END_ADDR register definition
 *  Recording buffer end address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BUF_END_ADDR              0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_BUF_END_ADDR_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000018)
#define LCU_COMMON_LCU_COMMON_BUF_END_ADDR_OFFSET      0x00000018
#define LCU_COMMON_LCU_COMMON_BUF_END_ADDR_INDEX       0x00000006
#define LCU_COMMON_LCU_COMMON_BUF_END_ADDR_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_buf_end_addr_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_BUF_END_ADDR_ADDR);
}

__INLINE void lcu_common_lcu_common_buf_end_addr_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_BUF_END_ADDR_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_BUF_END_ADDR_BUF_END_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_BUF_END_ADDR_BUF_END_ADDR_LSB    0
#define LCU_COMMON_LCU_COMMON_BUF_END_ADDR_BUF_END_ADDR_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_BUF_END_ADDR_BUF_END_ADDR_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_buf_end_addr_buf_end_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_BUF_END_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_common_buf_end_addr_buf_end_addr_setf(uint32_t bufendaddr)
{
	ASSERT_ERR((((uint32_t)bufendaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_BUF_END_ADDR_ADDR, (uint32_t)bufendaddr << 0);
}

/**
 * @brief LCU_COMMON_CAPTURE_MODE register definition
 *  Stop at the Buffer end address or rollover register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CAPTURE_MODE              0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_CAPTURE_MODE_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000001C)
#define LCU_COMMON_LCU_COMMON_CAPTURE_MODE_OFFSET      0x0000001C
#define LCU_COMMON_LCU_COMMON_CAPTURE_MODE_INDEX       0x00000007
#define LCU_COMMON_LCU_COMMON_CAPTURE_MODE_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_capture_mode_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_CAPTURE_MODE_ADDR);
}

__INLINE void lcu_common_lcu_common_capture_mode_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CAPTURE_MODE_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_CAPTURE_MODE_CAPTURE_MODE_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_CAPTURE_MODE_CAPTURE_MODE_POS    0

#define LCU_COMMON_LCU_COMMON_CAPTURE_MODE_CAPTURE_MODE_RST    0x0

__INLINE uint8_t lcu_common_lcu_common_capture_mode_capture_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CAPTURE_MODE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_common_capture_mode_capture_mode_setf(uint8_t capturemode)
{
	ASSERT_ERR((((uint32_t)capturemode << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CAPTURE_MODE_ADDR, (uint32_t)capturemode << 0);
}

/**
 * @brief LCU_COMMON_REC_CMD register definition
 *  Move to ARMED start or stop register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    STOP_REC                  0              
 *    01    START_REC                 0              
 *    00    REC_ARM                   0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_REC_CMD_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000020)
#define LCU_COMMON_LCU_COMMON_REC_CMD_OFFSET      0x00000020
#define LCU_COMMON_LCU_COMMON_REC_CMD_INDEX       0x00000008
#define LCU_COMMON_LCU_COMMON_REC_CMD_RESET       0x00000000

__INLINE void lcu_common_lcu_common_rec_cmd_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_REC_CMD_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_REC_CMD_STOP_REC_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_REC_CMD_STOP_REC_POS    2
#define LCU_COMMON_LCU_COMMON_REC_CMD_START_REC_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_REC_CMD_START_REC_POS    1
#define LCU_COMMON_LCU_COMMON_REC_CMD_REC_ARM_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_REC_CMD_REC_ARM_POS    0

#define LCU_COMMON_LCU_COMMON_REC_CMD_STOP_REC_RST    0x0
#define LCU_COMMON_LCU_COMMON_REC_CMD_START_REC_RST    0x0
#define LCU_COMMON_LCU_COMMON_REC_CMD_REC_ARM_RST    0x0

__INLINE void lcu_common_lcu_common_rec_cmd_pack(uint8_t stop_rec, uint8_t start_rec, uint8_t rec_arm)
{
	ASSERT_ERR((((uint32_t)stop_rec << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)start_rec << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)rec_arm << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_REC_CMD_ADDR,  ((uint32_t)stop_rec << 2) |((uint32_t)start_rec << 1) |((uint32_t)rec_arm << 0));
}

__INLINE void lcu_common_lcu_common_rec_cmd_stop_rec_setf(uint8_t stoprec)
{
	ASSERT_ERR((((uint32_t)stoprec << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_REC_CMD_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_CMD_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)stoprec <<2));
}
__INLINE void lcu_common_lcu_common_rec_cmd_start_rec_setf(uint8_t startrec)
{
	ASSERT_ERR((((uint32_t)startrec << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_REC_CMD_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_CMD_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)startrec <<1));
}
__INLINE void lcu_common_lcu_common_rec_cmd_rec_arm_setf(uint8_t recarm)
{
	ASSERT_ERR((((uint32_t)recarm << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_REC_CMD_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_CMD_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)recarm <<0));
}

/**
 * @brief LCU_COMMON_STOP_EXTRA_SAMPLES register definition
 *  Number of samples to record after stop cmd register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 STOP_EXTRA_SAMPLES        0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_SAMPLES_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000024)
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_SAMPLES_OFFSET      0x00000024
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_SAMPLES_INDEX       0x00000009
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_SAMPLES_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_stop_extra_samples_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_STOP_EXTRA_SAMPLES_ADDR);
}

__INLINE void lcu_common_lcu_common_stop_extra_samples_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_STOP_EXTRA_SAMPLES_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_SAMPLES_STOP_EXTRA_SAMPLES_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_SAMPLES_STOP_EXTRA_SAMPLES_LSB    0
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_SAMPLES_STOP_EXTRA_SAMPLES_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_SAMPLES_STOP_EXTRA_SAMPLES_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_stop_extra_samples_stop_extra_samples_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_STOP_EXTRA_SAMPLES_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_common_stop_extra_samples_stop_extra_samples_setf(uint32_t stopextrasamples)
{
	ASSERT_ERR((((uint32_t)stopextrasamples << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_STOP_EXTRA_SAMPLES_ADDR, (uint32_t)stopextrasamples << 0);
}

/**
 * @brief LCU_COMMON_STOP_EXTRA_CYCLES register definition
 *  Number of cycles to record after stop cmd register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 STOP_EXTRA_CYCLES         0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_CYCLES_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000028)
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_CYCLES_OFFSET      0x00000028
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_CYCLES_INDEX       0x0000000A
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_CYCLES_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_stop_extra_cycles_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_STOP_EXTRA_CYCLES_ADDR);
}

__INLINE void lcu_common_lcu_common_stop_extra_cycles_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_STOP_EXTRA_CYCLES_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_CYCLES_STOP_EXTRA_CYCLES_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_CYCLES_STOP_EXTRA_CYCLES_LSB    0
#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_CYCLES_STOP_EXTRA_CYCLES_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_STOP_EXTRA_CYCLES_STOP_EXTRA_CYCLES_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_stop_extra_cycles_stop_extra_cycles_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_STOP_EXTRA_CYCLES_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_common_stop_extra_cycles_stop_extra_cycles_setf(uint32_t stopextracycles)
{
	ASSERT_ERR((((uint32_t)stopextracycles << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_STOP_EXTRA_CYCLES_ADDR, (uint32_t)stopextracycles << 0);
}

/**
 * @brief LCU_COMMON_WRITE_ADDR register definition
 *  Address of the last sample recorded  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 WRITE_ADDR                0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_WRITE_ADDR_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000002C)
#define LCU_COMMON_LCU_COMMON_WRITE_ADDR_OFFSET      0x0000002C
#define LCU_COMMON_LCU_COMMON_WRITE_ADDR_INDEX       0x0000000B
#define LCU_COMMON_LCU_COMMON_WRITE_ADDR_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_write_addr_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_WRITE_ADDR_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_WRITE_ADDR_WRITE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_WRITE_ADDR_WRITE_ADDR_LSB    0
#define LCU_COMMON_LCU_COMMON_WRITE_ADDR_WRITE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_WRITE_ADDR_WRITE_ADDR_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_write_addr_write_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_WRITE_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_REC_STOP_ADDR register definition
 *  The latched address when a stop condition occurs  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 REC_STOP_ADDR             0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_REC_STOP_ADDR_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000030)
#define LCU_COMMON_LCU_COMMON_REC_STOP_ADDR_OFFSET      0x00000030
#define LCU_COMMON_LCU_COMMON_REC_STOP_ADDR_INDEX       0x0000000C
#define LCU_COMMON_LCU_COMMON_REC_STOP_ADDR_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_rec_stop_addr_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_STOP_ADDR_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_REC_STOP_ADDR_REC_STOP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_REC_STOP_ADDR_REC_STOP_ADDR_LSB    0
#define LCU_COMMON_LCU_COMMON_REC_STOP_ADDR_REC_STOP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_REC_STOP_ADDR_REC_STOP_ADDR_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_rec_stop_addr_rec_stop_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_REC_STOP_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_BLOCK_SIZE_EXPONENT register definition
 *  The size of the block is 2^BLOCK_SIZE_EXP bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 BLOCK_SIZE_EXP            0xC
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_BLOCK_SIZE_EXPONENT_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000034)
#define LCU_COMMON_LCU_COMMON_BLOCK_SIZE_EXPONENT_OFFSET      0x00000034
#define LCU_COMMON_LCU_COMMON_BLOCK_SIZE_EXPONENT_INDEX       0x0000000D
#define LCU_COMMON_LCU_COMMON_BLOCK_SIZE_EXPONENT_RESET       0x0000000C

__INLINE uint32_t  lcu_common_lcu_common_block_size_exponent_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_BLOCK_SIZE_EXPONENT_ADDR);
}

__INLINE void lcu_common_lcu_common_block_size_exponent_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_BLOCK_SIZE_EXPONENT_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_BLOCK_SIZE_EXPONENT_BLOCK_SIZE_EXP_MASK    ((uint32_t)0x000000FF)
#define LCU_COMMON_LCU_COMMON_BLOCK_SIZE_EXPONENT_BLOCK_SIZE_EXP_LSB    0
#define LCU_COMMON_LCU_COMMON_BLOCK_SIZE_EXPONENT_BLOCK_SIZE_EXP_WIDTH    ((uint32_t)0x00000008)

#define LCU_COMMON_LCU_COMMON_BLOCK_SIZE_EXPONENT_BLOCK_SIZE_EXP_RST    0xC

__INLINE uint8_t lcu_common_lcu_common_block_size_exponent_block_size_exp_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_BLOCK_SIZE_EXPONENT_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_common_block_size_exponent_block_size_exp_setf(uint8_t blocksizeexp)
{
	ASSERT_ERR((((uint32_t)blocksizeexp << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_BLOCK_SIZE_EXPONENT_ADDR, (uint32_t)blocksizeexp << 0);
}

/**
 * @brief LCU_COMMON_BLOCK_WR_COUNTER register definition
 *  Counts the number of blocks that were recorded by  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BLOCK_COUNTER             0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_BLOCK_WR_COUNTER_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000038)
#define LCU_COMMON_LCU_COMMON_BLOCK_WR_COUNTER_OFFSET      0x00000038
#define LCU_COMMON_LCU_COMMON_BLOCK_WR_COUNTER_INDEX       0x0000000E
#define LCU_COMMON_LCU_COMMON_BLOCK_WR_COUNTER_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_block_wr_counter_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_BLOCK_WR_COUNTER_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_BLOCK_WR_COUNTER_BLOCK_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_BLOCK_WR_COUNTER_BLOCK_COUNTER_LSB    0
#define LCU_COMMON_LCU_COMMON_BLOCK_WR_COUNTER_BLOCK_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_BLOCK_WR_COUNTER_BLOCK_COUNTER_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_block_wr_counter_block_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_BLOCK_WR_COUNTER_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_BLOCK_RD_COUNTER_INC register definition
 *  Number of blocks that were copied by the DMA since register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 BLOCK_RD_COUNTER_INC      0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_INC_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000003C)
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_INC_OFFSET      0x0000003C
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_INC_INDEX       0x0000000F
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_INC_RESET       0x00000000

__INLINE void lcu_common_lcu_common_block_rd_counter_inc_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_INC_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_INC_BLOCK_RD_COUNTER_INC_MASK    ((uint32_t)0x0000000F)
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_INC_BLOCK_RD_COUNTER_INC_LSB    0
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_INC_BLOCK_RD_COUNTER_INC_WIDTH    ((uint32_t)0x00000004)

#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_INC_BLOCK_RD_COUNTER_INC_RST    0x0

__INLINE void lcu_common_lcu_common_block_rd_counter_inc_block_rd_counter_inc_setf(uint8_t blockrdcounterinc)
{
	ASSERT_ERR((((uint32_t)blockrdcounterinc << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_INC_ADDR, (uint32_t)blockrdcounterinc << 0);
}

/**
 * @brief LCU_COMMON_BLOCK_RD_COUNTER register definition
 *  Number of blocks that were copied by the DMA in to register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BLOCK_RD_COUNTER          0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000040)
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_OFFSET      0x00000040
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_INDEX       0x00000010
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_block_rd_counter_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_BLOCK_RD_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_BLOCK_RD_COUNTER_LSB    0
#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_BLOCK_RD_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_BLOCK_RD_COUNTER_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_block_rd_counter_block_rd_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_BLOCK_RD_COUNTER_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF register definition
 *  Difference between the Block counter and the DMA register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BLOCK_COUNTERS_MAX_DIFF   0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000044)
#define LCU_COMMON_LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_OFFSET      0x00000044
#define LCU_COMMON_LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_INDEX       0x00000011
#define LCU_COMMON_LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_block_counters_max_diff_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_BLOCK_COUNTERS_MAX_DIFF_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_BLOCK_COUNTERS_MAX_DIFF_LSB    0
#define LCU_COMMON_LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_BLOCK_COUNTERS_MAX_DIFF_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_BLOCK_COUNTERS_MAX_DIFF_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_block_counters_max_diff_block_counters_max_diff_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_SW_RST register definition
 *  Software reset register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    SW_RST                    0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_SW_RST_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000048)
#define LCU_COMMON_LCU_COMMON_SW_RST_OFFSET      0x00000048
#define LCU_COMMON_LCU_COMMON_SW_RST_INDEX       0x00000012
#define LCU_COMMON_LCU_COMMON_SW_RST_RESET       0x00000000

__INLINE void lcu_common_lcu_common_sw_rst_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_SW_RST_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_SW_RST_SW_RST_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_SW_RST_SW_RST_POS    0

#define LCU_COMMON_LCU_COMMON_SW_RST_SW_RST_RST    0x0

__INLINE void lcu_common_lcu_common_sw_rst_sw_rst_setf(uint8_t swrst)
{
	ASSERT_ERR((((uint32_t)swrst << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_SW_RST_ADDR, (uint32_t)swrst << 0);
}

/**
 * @brief LCU_COMMON_STATUS register definition
 *  Status Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    CH_PEND_IND               0              
 *    15:12 STOP_INITIATOR            0xF
 *    11:08 START_INITIATOR           0xF
 *    07    CH5_OVF                   0              
 *    06    CH4_OVF                   0              
 *    05    CH3_OVF                   0              
 *    04    CH2_OVF                   0              
 *    03:00 STATUS                    0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_STATUS_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000004C)
#define LCU_COMMON_LCU_COMMON_STATUS_OFFSET      0x0000004C
#define LCU_COMMON_LCU_COMMON_STATUS_INDEX       0x00000013
#define LCU_COMMON_LCU_COMMON_STATUS_RESET       0x0000FF00

__INLINE uint32_t  lcu_common_lcu_common_status_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_STATUS_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_STATUS_CH_PEND_IND_BIT    ((uint32_t)0x00010000)
#define LCU_COMMON_LCU_COMMON_STATUS_CH_PEND_IND_POS    16
#define LCU_COMMON_LCU_COMMON_STATUS_STOP_INITIATOR_MASK    ((uint32_t)0x0000F000)
#define LCU_COMMON_LCU_COMMON_STATUS_STOP_INITIATOR_LSB    12
#define LCU_COMMON_LCU_COMMON_STATUS_STOP_INITIATOR_WIDTH    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_STATUS_START_INITIATOR_MASK    ((uint32_t)0x00000F00)
#define LCU_COMMON_LCU_COMMON_STATUS_START_INITIATOR_LSB    8
#define LCU_COMMON_LCU_COMMON_STATUS_START_INITIATOR_WIDTH    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_STATUS_CH_5_OVF_BIT    ((uint32_t)0x00000080)
#define LCU_COMMON_LCU_COMMON_STATUS_CH_5_OVF_POS    7
#define LCU_COMMON_LCU_COMMON_STATUS_CH_4_OVF_BIT    ((uint32_t)0x00000040)
#define LCU_COMMON_LCU_COMMON_STATUS_CH_4_OVF_POS    6
#define LCU_COMMON_LCU_COMMON_STATUS_CH_3_OVF_BIT    ((uint32_t)0x00000020)
#define LCU_COMMON_LCU_COMMON_STATUS_CH_3_OVF_POS    5
#define LCU_COMMON_LCU_COMMON_STATUS_CH_2_OVF_BIT    ((uint32_t)0x00000010)
#define LCU_COMMON_LCU_COMMON_STATUS_CH_2_OVF_POS    4
#define LCU_COMMON_LCU_COMMON_STATUS_STATUS_MASK    ((uint32_t)0x0000000F)
#define LCU_COMMON_LCU_COMMON_STATUS_STATUS_LSB    0
#define LCU_COMMON_LCU_COMMON_STATUS_STATUS_WIDTH    ((uint32_t)0x00000004)

#define LCU_COMMON_LCU_COMMON_STATUS_CH_PEND_IND_RST    0x0
#define LCU_COMMON_LCU_COMMON_STATUS_STOP_INITIATOR_RST    0xF
#define LCU_COMMON_LCU_COMMON_STATUS_START_INITIATOR_RST    0xF
#define LCU_COMMON_LCU_COMMON_STATUS_CH_5_OVF_RST    0x0
#define LCU_COMMON_LCU_COMMON_STATUS_CH_4_OVF_RST    0x0
#define LCU_COMMON_LCU_COMMON_STATUS_CH_3_OVF_RST    0x0
#define LCU_COMMON_LCU_COMMON_STATUS_CH_2_OVF_RST    0x0
#define LCU_COMMON_LCU_COMMON_STATUS_STATUS_RST    0x0

__INLINE void lcu_common_lcu_common_status_unpack(uint8_t* ch_pend_ind, uint8_t* stop_initiator, uint8_t* start_initiator, uint8_t* ch5_ovf, uint8_t* ch4_ovf, uint8_t* ch3_ovf, uint8_t* ch2_ovf, uint8_t* status)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_STATUS_ADDR);

	*ch_pend_ind = (localVal & ((uint32_t)0x00010000)) >>  16;
	*stop_initiator = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*start_initiator = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*ch5_ovf = (localVal & ((uint32_t)0x00000080)) >>  7;
	*ch4_ovf = (localVal & ((uint32_t)0x00000040)) >>  6;
	*ch3_ovf = (localVal & ((uint32_t)0x00000020)) >>  5;
	*ch2_ovf = (localVal & ((uint32_t)0x00000010)) >>  4;
	*status = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_status_ch_pend_ind_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t lcu_common_lcu_common_status_stop_initiator_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE uint8_t lcu_common_lcu_common_status_start_initiator_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE uint8_t lcu_common_lcu_common_status_ch_5_ovf_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t lcu_common_lcu_common_status_ch_4_ovf_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t lcu_common_lcu_common_status_ch_3_ovf_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t lcu_common_lcu_common_status_ch_2_ovf_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t lcu_common_lcu_common_status_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief LCU_COMMON_INT_RAW_STAT register definition
 *  Interrupt RAW Status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    ERROR                     0              
 *    01    FINAL_SAMPLE              0              
 *    00    BLOCK_FILL                0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000050)
#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_OFFSET      0x00000050
#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_INDEX       0x00000014
#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_int_raw_stat_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_INT_RAW_STAT_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_ERROR_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_ERROR_POS    2
#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_FINAL_SAMPLE_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_FINAL_SAMPLE_POS    1
#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_BLOCK_FILL_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_BLOCK_FILL_POS    0

#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_ERROR_RST    0x0
#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_FINAL_SAMPLE_RST    0x0
#define LCU_COMMON_LCU_COMMON_INT_RAW_STAT_BLOCK_FILL_RST    0x0

__INLINE void lcu_common_lcu_common_int_raw_stat_unpack(uint8_t* error, uint8_t* final_sample, uint8_t* block_fill)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_INT_RAW_STAT_ADDR);

	*error = (localVal & ((uint32_t)0x00000004)) >>  2;
	*final_sample = (localVal & ((uint32_t)0x00000002)) >>  1;
	*block_fill = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_int_raw_stat_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t lcu_common_lcu_common_int_raw_stat_final_sample_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t lcu_common_lcu_common_int_raw_stat_block_fill_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief LCU_COMMON_LMAC_INT_EN register definition
 *  Interrupt enable to LMAC register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    ERROR_INT_EN              0              
 *    01    FINAL_SAMPLE_INT_EN       0              
 *    00    BLOCK_FILL_INT_EN         0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000054)
#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_OFFSET      0x00000054
#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_INDEX       0x00000015
#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_lmac_int_en_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR);
}

__INLINE void lcu_common_lcu_common_lmac_int_en_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ERROR_INT_EN_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ERROR_INT_EN_POS    2
#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_FINAL_SAMPLE_INT_EN_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_FINAL_SAMPLE_INT_EN_POS    1
#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_BLOCK_FILL_INT_EN_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_BLOCK_FILL_INT_EN_POS    0

#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ERROR_INT_EN_RST    0x0
#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_FINAL_SAMPLE_INT_EN_RST    0x0
#define LCU_COMMON_LCU_COMMON_LMAC_INT_EN_BLOCK_FILL_INT_EN_RST    0x0

__INLINE void lcu_common_lcu_common_lmac_int_en_pack(uint8_t error_int_en, uint8_t final_sample_int_en, uint8_t block_fill_int_en)
{
	ASSERT_ERR((((uint32_t)error_int_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)final_sample_int_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)block_fill_int_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR,  ((uint32_t)error_int_en << 2) |((uint32_t)final_sample_int_en << 1) |((uint32_t)block_fill_int_en << 0));
}

__INLINE void lcu_common_lcu_common_lmac_int_en_unpack(uint8_t* error_int_en, uint8_t* final_sample_int_en, uint8_t* block_fill_int_en)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR);

	*error_int_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*final_sample_int_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*block_fill_int_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_lmac_int_en_error_int_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void lcu_common_lcu_common_lmac_int_en_error_int_en_setf(uint8_t errorinten)
{
	ASSERT_ERR((((uint32_t)errorinten << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)errorinten <<2));
}
__INLINE uint8_t lcu_common_lcu_common_lmac_int_en_final_sample_int_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void lcu_common_lcu_common_lmac_int_en_final_sample_int_en_setf(uint8_t finalsampleinten)
{
	ASSERT_ERR((((uint32_t)finalsampleinten << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)finalsampleinten <<1));
}
__INLINE uint8_t lcu_common_lcu_common_lmac_int_en_block_fill_int_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void lcu_common_lcu_common_lmac_int_en_block_fill_int_en_setf(uint8_t blockfillinten)
{
	ASSERT_ERR((((uint32_t)blockfillinten << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)blockfillinten <<0));
}

/**
 * @brief LCU_COMMON_UMAC_INT_EN register definition
 *  Interrupt enable to UMAC register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    ERROR_INT_EN              0              
 *    01    FINAL_SAMPLE_INT_EN       0              
 *    00    BLOCK_FILL_INT_EN         0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000058)
#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_OFFSET      0x00000058
#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_INDEX       0x00000016
#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_umac_int_en_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR);
}

__INLINE void lcu_common_lcu_common_umac_int_en_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ERROR_INT_EN_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ERROR_INT_EN_POS    2
#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_FINAL_SAMPLE_INT_EN_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_FINAL_SAMPLE_INT_EN_POS    1
#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_BLOCK_FILL_INT_EN_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_BLOCK_FILL_INT_EN_POS    0

#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ERROR_INT_EN_RST    0x0
#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_FINAL_SAMPLE_INT_EN_RST    0x0
#define LCU_COMMON_LCU_COMMON_UMAC_INT_EN_BLOCK_FILL_INT_EN_RST    0x0

__INLINE void lcu_common_lcu_common_umac_int_en_pack(uint8_t error_int_en, uint8_t final_sample_int_en, uint8_t block_fill_int_en)
{
	ASSERT_ERR((((uint32_t)error_int_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)final_sample_int_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)block_fill_int_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR,  ((uint32_t)error_int_en << 2) |((uint32_t)final_sample_int_en << 1) |((uint32_t)block_fill_int_en << 0));
}

__INLINE void lcu_common_lcu_common_umac_int_en_unpack(uint8_t* error_int_en, uint8_t* final_sample_int_en, uint8_t* block_fill_int_en)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR);

	*error_int_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*final_sample_int_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*block_fill_int_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_umac_int_en_error_int_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void lcu_common_lcu_common_umac_int_en_error_int_en_setf(uint8_t errorinten)
{
	ASSERT_ERR((((uint32_t)errorinten << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)errorinten <<2));
}
__INLINE uint8_t lcu_common_lcu_common_umac_int_en_final_sample_int_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void lcu_common_lcu_common_umac_int_en_final_sample_int_en_setf(uint8_t finalsampleinten)
{
	ASSERT_ERR((((uint32_t)finalsampleinten << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)finalsampleinten <<1));
}
__INLINE uint8_t lcu_common_lcu_common_umac_int_en_block_fill_int_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void lcu_common_lcu_common_umac_int_en_block_fill_int_en_setf(uint8_t blockfillinten)
{
	ASSERT_ERR((((uint32_t)blockfillinten << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)blockfillinten <<0));
}

/**
 * @brief LCU_COMMON_SMAC_INT_EN register definition
 *  Interrupt enable to SMAC register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    ERROR_INT_EN              0              
 *    01    FINAL_SAMPLE_INT_EN       0              
 *    00    BLOCK_FILL_INT_EN         0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000005C)
#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_OFFSET      0x0000005C
#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_INDEX       0x00000017
#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_smac_int_en_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR);
}

__INLINE void lcu_common_lcu_common_smac_int_en_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ERROR_INT_EN_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ERROR_INT_EN_POS    2
#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_FINAL_SAMPLE_INT_EN_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_FINAL_SAMPLE_INT_EN_POS    1
#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_BLOCK_FILL_INT_EN_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_BLOCK_FILL_INT_EN_POS    0

#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ERROR_INT_EN_RST    0x0
#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_FINAL_SAMPLE_INT_EN_RST    0x0
#define LCU_COMMON_LCU_COMMON_SMAC_INT_EN_BLOCK_FILL_INT_EN_RST    0x0

__INLINE void lcu_common_lcu_common_smac_int_en_pack(uint8_t error_int_en, uint8_t final_sample_int_en, uint8_t block_fill_int_en)
{
	ASSERT_ERR((((uint32_t)error_int_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)final_sample_int_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)block_fill_int_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR,  ((uint32_t)error_int_en << 2) |((uint32_t)final_sample_int_en << 1) |((uint32_t)block_fill_int_en << 0));
}

__INLINE void lcu_common_lcu_common_smac_int_en_unpack(uint8_t* error_int_en, uint8_t* final_sample_int_en, uint8_t* block_fill_int_en)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR);

	*error_int_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*final_sample_int_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*block_fill_int_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_smac_int_en_error_int_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void lcu_common_lcu_common_smac_int_en_error_int_en_setf(uint8_t errorinten)
{
	ASSERT_ERR((((uint32_t)errorinten << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)errorinten <<2));
}
__INLINE uint8_t lcu_common_lcu_common_smac_int_en_final_sample_int_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void lcu_common_lcu_common_smac_int_en_final_sample_int_en_setf(uint8_t finalsampleinten)
{
	ASSERT_ERR((((uint32_t)finalsampleinten << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)finalsampleinten <<1));
}
__INLINE uint8_t lcu_common_lcu_common_smac_int_en_block_fill_int_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void lcu_common_lcu_common_smac_int_en_block_fill_int_en_setf(uint8_t blockfillinten)
{
	ASSERT_ERR((((uint32_t)blockfillinten << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)blockfillinten <<0));
}

/**
 * @brief LCU_COMMON_INT_FORCE register definition
 *  Interrupt Force register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    ERROR_INT_FORCE           0              
 *    01    FINAL_SAMPLE_INT_FORCE    0              
 *    00    BLOCK_FILL_INT_FORCE      0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_INT_FORCE_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000060)
#define LCU_COMMON_LCU_COMMON_INT_FORCE_OFFSET      0x00000060
#define LCU_COMMON_LCU_COMMON_INT_FORCE_INDEX       0x00000018
#define LCU_COMMON_LCU_COMMON_INT_FORCE_RESET       0x00000000

__INLINE void lcu_common_lcu_common_int_force_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_INT_FORCE_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_INT_FORCE_ERROR_INT_FORCE_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_INT_FORCE_ERROR_INT_FORCE_POS    2
#define LCU_COMMON_LCU_COMMON_INT_FORCE_FINAL_SAMPLE_INT_FORCE_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_INT_FORCE_FINAL_SAMPLE_INT_FORCE_POS    1
#define LCU_COMMON_LCU_COMMON_INT_FORCE_BLOCK_FILL_INT_FORCE_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_INT_FORCE_BLOCK_FILL_INT_FORCE_POS    0

#define LCU_COMMON_LCU_COMMON_INT_FORCE_ERROR_INT_FORCE_RST    0x0
#define LCU_COMMON_LCU_COMMON_INT_FORCE_FINAL_SAMPLE_INT_FORCE_RST    0x0
#define LCU_COMMON_LCU_COMMON_INT_FORCE_BLOCK_FILL_INT_FORCE_RST    0x0

__INLINE void lcu_common_lcu_common_int_force_pack(uint8_t error_int_force, uint8_t final_sample_int_force, uint8_t block_fill_int_force)
{
	ASSERT_ERR((((uint32_t)error_int_force << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)final_sample_int_force << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)block_fill_int_force << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_INT_FORCE_ADDR,  ((uint32_t)error_int_force << 2) |((uint32_t)final_sample_int_force << 1) |((uint32_t)block_fill_int_force << 0));
}

__INLINE void lcu_common_lcu_common_int_force_error_int_force_setf(uint8_t errorintforce)
{
	ASSERT_ERR((((uint32_t)errorintforce << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_INT_FORCE_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_INT_FORCE_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)errorintforce <<2));
}
__INLINE void lcu_common_lcu_common_int_force_final_sample_int_force_setf(uint8_t finalsampleintforce)
{
	ASSERT_ERR((((uint32_t)finalsampleintforce << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_INT_FORCE_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_INT_FORCE_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)finalsampleintforce <<1));
}
__INLINE void lcu_common_lcu_common_int_force_block_fill_int_force_setf(uint8_t blockfillintforce)
{
	ASSERT_ERR((((uint32_t)blockfillintforce << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_INT_FORCE_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_INT_FORCE_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)blockfillintforce <<0));
}

/**
 * @brief LCU_COMMON_INT_CLEAR register definition
 *  Interrupt clear register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    ERROR_INT_CLEAR           0              
 *    01    FINAL_SAMPLE_INT_CLEAR    0              
 *    00    BLOCK_FILL_INT_CLEAR      0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_INT_CLEAR_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000064)
#define LCU_COMMON_LCU_COMMON_INT_CLEAR_OFFSET      0x00000064
#define LCU_COMMON_LCU_COMMON_INT_CLEAR_INDEX       0x00000019
#define LCU_COMMON_LCU_COMMON_INT_CLEAR_RESET       0x00000000

__INLINE void lcu_common_lcu_common_int_clear_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_INT_CLEAR_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_INT_CLEAR_ERROR_INT_CLEAR_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_INT_CLEAR_ERROR_INT_CLEAR_POS    2
#define LCU_COMMON_LCU_COMMON_INT_CLEAR_FINAL_SAMPLE_INT_CLEAR_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_INT_CLEAR_FINAL_SAMPLE_INT_CLEAR_POS    1
#define LCU_COMMON_LCU_COMMON_INT_CLEAR_BLOCK_FILL_INT_CLEAR_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_INT_CLEAR_BLOCK_FILL_INT_CLEAR_POS    0

#define LCU_COMMON_LCU_COMMON_INT_CLEAR_ERROR_INT_CLEAR_RST    0x0
#define LCU_COMMON_LCU_COMMON_INT_CLEAR_FINAL_SAMPLE_INT_CLEAR_RST    0x0
#define LCU_COMMON_LCU_COMMON_INT_CLEAR_BLOCK_FILL_INT_CLEAR_RST    0x0

__INLINE void lcu_common_lcu_common_int_clear_pack(uint8_t error_int_clear, uint8_t final_sample_int_clear, uint8_t block_fill_int_clear)
{
	ASSERT_ERR((((uint32_t)error_int_clear << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)final_sample_int_clear << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)block_fill_int_clear << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_INT_CLEAR_ADDR,  ((uint32_t)error_int_clear << 2) |((uint32_t)final_sample_int_clear << 1) |((uint32_t)block_fill_int_clear << 0));
}

__INLINE void lcu_common_lcu_common_int_clear_error_int_clear_setf(uint8_t errorintclear)
{
	ASSERT_ERR((((uint32_t)errorintclear << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_INT_CLEAR_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_INT_CLEAR_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)errorintclear <<2));
}
__INLINE void lcu_common_lcu_common_int_clear_final_sample_int_clear_setf(uint8_t finalsampleintclear)
{
	ASSERT_ERR((((uint32_t)finalsampleintclear << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_INT_CLEAR_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_INT_CLEAR_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)finalsampleintclear <<1));
}
__INLINE void lcu_common_lcu_common_int_clear_block_fill_int_clear_setf(uint8_t blockfillintclear)
{
	ASSERT_ERR((((uint32_t)blockfillintclear << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_INT_CLEAR_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_INT_CLEAR_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)blockfillintclear <<0));
}

/**
 * @brief LCU_COMMON_LMAC_INT_STAT register definition
 *  LCU_COMMON interrupt status to the LMAC  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    ERROR_INT_STATUS          0              
 *    01    FINAL_SAMPLE_INT_STATUS   0              
 *    00    BLOCK_FILL_INT_STATUS     0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000068)
#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_OFFSET      0x00000068
#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_INDEX       0x0000001A
#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_lmac_int_stat_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_ERROR_INT_STATUS_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_ERROR_INT_STATUS_POS    2
#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_POS    1
#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_BLOCK_FILL_INT_STATUS_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_BLOCK_FILL_INT_STATUS_POS    0

#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_ERROR_INT_STATUS_RST    0x0
#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_RST    0x0
#define LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_BLOCK_FILL_INT_STATUS_RST    0x0

__INLINE void lcu_common_lcu_common_lmac_int_stat_unpack(uint8_t* error_int_status, uint8_t* final_sample_int_status, uint8_t* block_fill_int_status)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_ADDR);

	*error_int_status = (localVal & ((uint32_t)0x00000004)) >>  2;
	*final_sample_int_status = (localVal & ((uint32_t)0x00000002)) >>  1;
	*block_fill_int_status = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_lmac_int_stat_error_int_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t lcu_common_lcu_common_lmac_int_stat_final_sample_int_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t lcu_common_lcu_common_lmac_int_stat_block_fill_int_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief LCU_COMMON_UMAC_INT_STAT register definition
 *  LCU_COMMON interrupt status to the UMAC  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    ERROR_INT_STATUS          0              
 *    01    FINAL_SAMPLE_INT_STATUS   0              
 *    00    BLOCK_FILL_INT_STATUS     0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000006C)
#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_OFFSET      0x0000006C
#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_INDEX       0x0000001B
#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_umac_int_stat_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_ERROR_INT_STATUS_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_ERROR_INT_STATUS_POS    2
#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_POS    1
#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_BLOCK_FILL_INT_STATUS_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_BLOCK_FILL_INT_STATUS_POS    0

#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_ERROR_INT_STATUS_RST    0x0
#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_RST    0x0
#define LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_BLOCK_FILL_INT_STATUS_RST    0x0

__INLINE void lcu_common_lcu_common_umac_int_stat_unpack(uint8_t* error_int_status, uint8_t* final_sample_int_status, uint8_t* block_fill_int_status)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_ADDR);

	*error_int_status = (localVal & ((uint32_t)0x00000004)) >>  2;
	*final_sample_int_status = (localVal & ((uint32_t)0x00000002)) >>  1;
	*block_fill_int_status = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_umac_int_stat_error_int_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t lcu_common_lcu_common_umac_int_stat_final_sample_int_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t lcu_common_lcu_common_umac_int_stat_block_fill_int_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief LCU_COMMON_SMAC_INT_STAT register definition
 *  LCU_COMMON interrupt status to the SMAC  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    ERROR_INT_STATUS          0              
 *    01    FINAL_SAMPLE_INT_STATUS   0              
 *    00    BLOCK_FILL_INT_STATUS     0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000070)
#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_OFFSET      0x00000070
#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_INDEX       0x0000001C
#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_smac_int_stat_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_ERROR_INT_STATUS_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_ERROR_INT_STATUS_POS    2
#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_POS    1
#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_BLOCK_FILL_INT_STATUS_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_BLOCK_FILL_INT_STATUS_POS    0

#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_ERROR_INT_STATUS_RST    0x0
#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_RST    0x0
#define LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_BLOCK_FILL_INT_STATUS_RST    0x0

__INLINE void lcu_common_lcu_common_smac_int_stat_unpack(uint8_t* error_int_status, uint8_t* final_sample_int_status, uint8_t* block_fill_int_status)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_ADDR);

	*error_int_status = (localVal & ((uint32_t)0x00000004)) >>  2;
	*final_sample_int_status = (localVal & ((uint32_t)0x00000002)) >>  1;
	*block_fill_int_status = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_smac_int_stat_error_int_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t lcu_common_lcu_common_smac_int_stat_final_sample_int_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t lcu_common_lcu_common_smac_int_stat_block_fill_int_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief LCU_COMMON_PENDING_CH_REG_0 register definition
 *  Pending Channel bits 31:0 at the end of the record register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PENDING_CH                0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000074)
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_0_OFFSET      0x00000074
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_0_INDEX       0x0000001D
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_pending_ch_reg_0_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_PENDING_CH_REG_0_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_0_PENDING_CH_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_0_PENDING_CH_LSB    0
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_0_PENDING_CH_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_0_PENDING_CH_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_pending_ch_reg_0_pending_ch_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_PENDING_CH_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_PENDING_CH_REG_1 register definition
 *  Pending Channel bits 63:32 at the end of the recor register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PENDING_CH                0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000078)
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_1_OFFSET      0x00000078
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_1_INDEX       0x0000001E
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_pending_ch_reg_1_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_PENDING_CH_REG_1_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_1_PENDING_CH_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_1_PENDING_CH_LSB    0
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_1_PENDING_CH_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_1_PENDING_CH_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_pending_ch_reg_1_pending_ch_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_PENDING_CH_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_PENDING_CH_REG_2 register definition
 *  Pending Channel bits 95:64 at the end of the recor register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PENDING_CH                0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000007C)
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_2_OFFSET      0x0000007C
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_2_INDEX       0x0000001F
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_pending_ch_reg_2_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_PENDING_CH_REG_2_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_2_PENDING_CH_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_2_PENDING_CH_LSB    0
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_2_PENDING_CH_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_2_PENDING_CH_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_pending_ch_reg_2_pending_ch_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_PENDING_CH_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_PENDING_CH_REG_3 register definition
 *  Pending Channel bits 127:96 at the end of the rec register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PENDING_CH                0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_3_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000080)
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_3_OFFSET      0x00000080
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_3_INDEX       0x00000020
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_3_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_pending_ch_reg_3_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_PENDING_CH_REG_3_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_3_PENDING_CH_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_3_PENDING_CH_LSB    0
#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_3_PENDING_CH_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_PENDING_CH_REG_3_PENDING_CH_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_pending_ch_reg_3_pending_ch_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_PENDING_CH_REG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LCU_COMMON_CC_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    LCU_CC_MODE               0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_CC_MODE_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000084)
#define LCU_COMMON_LCU_COMMON_CC_MODE_OFFSET      0x00000084
#define LCU_COMMON_LCU_COMMON_CC_MODE_INDEX       0x00000021
#define LCU_COMMON_LCU_COMMON_CC_MODE_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_cc_mode_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_CC_MODE_ADDR);
}

__INLINE void lcu_common_lcu_common_cc_mode_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CC_MODE_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_CC_MODE_LCU_CC_MODE_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_CC_MODE_LCU_CC_MODE_POS    0

#define LCU_COMMON_LCU_COMMON_CC_MODE_LCU_CC_MODE_RST    0x0

__INLINE uint8_t lcu_common_lcu_common_cc_mode_lcu_cc_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CC_MODE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_common_cc_mode_lcu_cc_mode_setf(uint8_t lcuccmode)
{
	ASSERT_ERR((((uint32_t)lcuccmode << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CC_MODE_ADDR, (uint32_t)lcuccmode << 0);
}

/**
 * @brief LCU_COMMON_CC_START_STOP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    LCU_CC_STOP               0              
 *    00    LCU_CC_START              0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_CC_START_STOP_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000088)
#define LCU_COMMON_LCU_COMMON_CC_START_STOP_OFFSET      0x00000088
#define LCU_COMMON_LCU_COMMON_CC_START_STOP_INDEX       0x00000022
#define LCU_COMMON_LCU_COMMON_CC_START_STOP_RESET       0x00000000

__INLINE void lcu_common_lcu_common_cc_start_stop_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CC_START_STOP_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_CC_START_STOP_LCU_CC_STOP_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_CC_START_STOP_LCU_CC_STOP_POS    1
#define LCU_COMMON_LCU_COMMON_CC_START_STOP_LCU_CC_START_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_CC_START_STOP_LCU_CC_START_POS    0

#define LCU_COMMON_LCU_COMMON_CC_START_STOP_LCU_CC_STOP_RST    0x0
#define LCU_COMMON_LCU_COMMON_CC_START_STOP_LCU_CC_START_RST    0x0

__INLINE void lcu_common_lcu_common_cc_start_stop_pack(uint8_t lcu_cc_stop, uint8_t lcu_cc_start)
{
	ASSERT_ERR((((uint32_t)lcu_cc_stop << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)lcu_cc_start << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CC_START_STOP_ADDR,  ((uint32_t)lcu_cc_stop << 1) |((uint32_t)lcu_cc_start << 0));
}

__INLINE void lcu_common_lcu_common_cc_start_stop_lcu_cc_stop_setf(uint8_t lcuccstop)
{
	ASSERT_ERR((((uint32_t)lcuccstop << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CC_START_STOP_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CC_START_STOP_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)lcuccstop <<1));
}
__INLINE void lcu_common_lcu_common_cc_start_stop_lcu_cc_start_setf(uint8_t lcuccstart)
{
	ASSERT_ERR((((uint32_t)lcuccstart << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CC_START_STOP_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CC_START_STOP_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)lcuccstart <<0));
}

/**
 * @brief LCU_COMMON_CC_CPU_SEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 LCU_CC_CPU_SEL            0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_CC_CPU_SEL_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000008C)
#define LCU_COMMON_LCU_COMMON_CC_CPU_SEL_OFFSET      0x0000008C
#define LCU_COMMON_LCU_COMMON_CC_CPU_SEL_INDEX       0x00000023
#define LCU_COMMON_LCU_COMMON_CC_CPU_SEL_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_cc_cpu_sel_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_CC_CPU_SEL_ADDR);
}

__INLINE void lcu_common_lcu_common_cc_cpu_sel_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CC_CPU_SEL_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_CC_CPU_SEL_LCU_CC_CPU_SEL_MASK    ((uint32_t)0x00000003)
#define LCU_COMMON_LCU_COMMON_CC_CPU_SEL_LCU_CC_CPU_SEL_LSB    0
#define LCU_COMMON_LCU_COMMON_CC_CPU_SEL_LCU_CC_CPU_SEL_WIDTH    ((uint32_t)0x00000002)

#define LCU_COMMON_LCU_COMMON_CC_CPU_SEL_LCU_CC_CPU_SEL_RST    0x0

__INLINE uint8_t lcu_common_lcu_common_cc_cpu_sel_lcu_cc_cpu_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CC_CPU_SEL_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_common_cc_cpu_sel_lcu_cc_cpu_sel_setf(uint8_t lcucccpusel)
{
	ASSERT_ERR((((uint32_t)lcucccpusel << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CC_CPU_SEL_ADDR, (uint32_t)lcucccpusel << 0);
}

/**
 * @brief LCU_COMMON_CC_START_PC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_CC_START_PC           0x0
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_CC_START_PC_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000090)
#define LCU_COMMON_LCU_COMMON_CC_START_PC_OFFSET      0x00000090
#define LCU_COMMON_LCU_COMMON_CC_START_PC_INDEX       0x00000024
#define LCU_COMMON_LCU_COMMON_CC_START_PC_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_cc_start_pc_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_CC_START_PC_ADDR);
}

__INLINE void lcu_common_lcu_common_cc_start_pc_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CC_START_PC_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_CC_START_PC_LCU_CC_START_PC_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_COMMON_CC_START_PC_LCU_CC_START_PC_LSB    0
#define LCU_COMMON_LCU_COMMON_CC_START_PC_LCU_CC_START_PC_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_COMMON_CC_START_PC_LCU_CC_START_PC_RST    0x0

__INLINE uint32_t lcu_common_lcu_common_cc_start_pc_lcu_cc_start_pc_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CC_START_PC_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_common_cc_start_pc_lcu_cc_start_pc_setf(uint32_t lcuccstartpc)
{
	ASSERT_ERR((((uint32_t)lcuccstartpc << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CC_START_PC_ADDR, (uint32_t)lcuccstartpc << 0);
}

/**
 * @brief LCU_COMMON_CH_0_CONF register definition
 *  Channel 0 Configuration Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    CH0_WRITE_VCI             0              
 *    01    CH0_WRITE_TS              0              
 *    00    CH0_REC_FORMAT            0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000100)
#define LCU_COMMON_LCU_COMMON_CH_0_CONF_OFFSET      0x00000100
#define LCU_COMMON_LCU_COMMON_CH_0_CONF_INDEX       0x00000040
#define LCU_COMMON_LCU_COMMON_CH_0_CONF_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_ch_0_conf_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR);
}

__INLINE void lcu_common_lcu_common_ch_0_conf_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_CH_0_CONF_CH_0_WRITE_VCI_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_CH_0_CONF_CH_0_WRITE_VCI_POS    2
#define LCU_COMMON_LCU_COMMON_CH_0_CONF_CH_0_WRITE_TS_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_CH_0_CONF_CH_0_WRITE_TS_POS    1
#define LCU_COMMON_LCU_COMMON_CH_0_CONF_CH_0_REC_FORMAT_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_CH_0_CONF_CH_0_REC_FORMAT_POS    0

#define LCU_COMMON_LCU_COMMON_CH_0_CONF_CH_0_WRITE_VCI_RST    0x0
#define LCU_COMMON_LCU_COMMON_CH_0_CONF_CH_0_WRITE_TS_RST    0x0
#define LCU_COMMON_LCU_COMMON_CH_0_CONF_CH_0_REC_FORMAT_RST    0x0

__INLINE void lcu_common_lcu_common_ch_0_conf_pack(uint8_t ch0_write_vci, uint8_t ch0_write_ts, uint8_t ch0_rec_format)
{
	ASSERT_ERR((((uint32_t)ch0_write_vci << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)ch0_write_ts << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ch0_rec_format << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR,  ((uint32_t)ch0_write_vci << 2) |((uint32_t)ch0_write_ts << 1) |((uint32_t)ch0_rec_format << 0));
}

__INLINE void lcu_common_lcu_common_ch_0_conf_unpack(uint8_t* ch0_write_vci, uint8_t* ch0_write_ts, uint8_t* ch0_rec_format)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR);

	*ch0_write_vci = (localVal & ((uint32_t)0x00000004)) >>  2;
	*ch0_write_ts = (localVal & ((uint32_t)0x00000002)) >>  1;
	*ch0_rec_format = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_ch_0_conf_ch_0_write_vci_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void lcu_common_lcu_common_ch_0_conf_ch_0_write_vci_setf(uint8_t ch0writevci)
{
	ASSERT_ERR((((uint32_t)ch0writevci << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)ch0writevci <<2));
}
__INLINE uint8_t lcu_common_lcu_common_ch_0_conf_ch_0_write_ts_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void lcu_common_lcu_common_ch_0_conf_ch_0_write_ts_setf(uint8_t ch0writets)
{
	ASSERT_ERR((((uint32_t)ch0writets << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ch0writets <<1));
}
__INLINE uint8_t lcu_common_lcu_common_ch_0_conf_ch_0_rec_format_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void lcu_common_lcu_common_ch_0_conf_ch_0_rec_format_setf(uint8_t ch0recformat)
{
	ASSERT_ERR((((uint32_t)ch0recformat << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_0_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch0recformat <<0));
}

/**
 * @brief LCU_COMMON_CH_1_CONF register definition
 *  Channel 1 Configuration Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    CH1_WRITE_VCI             0              
 *    01    CH1_WRITE_TS              0              
 *    00    CH1_REC_FORMAT            0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000104)
#define LCU_COMMON_LCU_COMMON_CH_1_CONF_OFFSET      0x00000104
#define LCU_COMMON_LCU_COMMON_CH_1_CONF_INDEX       0x00000041
#define LCU_COMMON_LCU_COMMON_CH_1_CONF_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_ch_1_conf_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR);
}

__INLINE void lcu_common_lcu_common_ch_1_conf_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_CH_1_CONF_CH_1_WRITE_VCI_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_CH_1_CONF_CH_1_WRITE_VCI_POS    2
#define LCU_COMMON_LCU_COMMON_CH_1_CONF_CH_1_WRITE_TS_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_CH_1_CONF_CH_1_WRITE_TS_POS    1
#define LCU_COMMON_LCU_COMMON_CH_1_CONF_CH_1_REC_FORMAT_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_CH_1_CONF_CH_1_REC_FORMAT_POS    0

#define LCU_COMMON_LCU_COMMON_CH_1_CONF_CH_1_WRITE_VCI_RST    0x0
#define LCU_COMMON_LCU_COMMON_CH_1_CONF_CH_1_WRITE_TS_RST    0x0
#define LCU_COMMON_LCU_COMMON_CH_1_CONF_CH_1_REC_FORMAT_RST    0x0

__INLINE void lcu_common_lcu_common_ch_1_conf_pack(uint8_t ch1_write_vci, uint8_t ch1_write_ts, uint8_t ch1_rec_format)
{
	ASSERT_ERR((((uint32_t)ch1_write_vci << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)ch1_write_ts << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ch1_rec_format << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR,  ((uint32_t)ch1_write_vci << 2) |((uint32_t)ch1_write_ts << 1) |((uint32_t)ch1_rec_format << 0));
}

__INLINE void lcu_common_lcu_common_ch_1_conf_unpack(uint8_t* ch1_write_vci, uint8_t* ch1_write_ts, uint8_t* ch1_rec_format)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR);

	*ch1_write_vci = (localVal & ((uint32_t)0x00000004)) >>  2;
	*ch1_write_ts = (localVal & ((uint32_t)0x00000002)) >>  1;
	*ch1_rec_format = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_ch_1_conf_ch_1_write_vci_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void lcu_common_lcu_common_ch_1_conf_ch_1_write_vci_setf(uint8_t ch1writevci)
{
	ASSERT_ERR((((uint32_t)ch1writevci << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)ch1writevci <<2));
}
__INLINE uint8_t lcu_common_lcu_common_ch_1_conf_ch_1_write_ts_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void lcu_common_lcu_common_ch_1_conf_ch_1_write_ts_setf(uint8_t ch1writets)
{
	ASSERT_ERR((((uint32_t)ch1writets << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ch1writets <<1));
}
__INLINE uint8_t lcu_common_lcu_common_ch_1_conf_ch_1_rec_format_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void lcu_common_lcu_common_ch_1_conf_ch_1_rec_format_setf(uint8_t ch1recformat)
{
	ASSERT_ERR((((uint32_t)ch1recformat << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_1_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch1recformat <<0));
}

/**
 * @brief LCU_COMMON_CH_2_CONF register definition
 *  Channel 2 Configuration Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    CH2_WRITE_VCI             0              
 *    01    CH2_WRITE_TS              0              
 *    00    CH2_REC_FORMAT            0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000108)
#define LCU_COMMON_LCU_COMMON_CH_2_CONF_OFFSET      0x00000108
#define LCU_COMMON_LCU_COMMON_CH_2_CONF_INDEX       0x00000042
#define LCU_COMMON_LCU_COMMON_CH_2_CONF_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_ch_2_conf_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR);
}

__INLINE void lcu_common_lcu_common_ch_2_conf_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_CH_2_CONF_CH_2_WRITE_VCI_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_CH_2_CONF_CH_2_WRITE_VCI_POS    2
#define LCU_COMMON_LCU_COMMON_CH_2_CONF_CH_2_WRITE_TS_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_CH_2_CONF_CH_2_WRITE_TS_POS    1
#define LCU_COMMON_LCU_COMMON_CH_2_CONF_CH_2_REC_FORMAT_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_CH_2_CONF_CH_2_REC_FORMAT_POS    0

#define LCU_COMMON_LCU_COMMON_CH_2_CONF_CH_2_WRITE_VCI_RST    0x0
#define LCU_COMMON_LCU_COMMON_CH_2_CONF_CH_2_WRITE_TS_RST    0x0
#define LCU_COMMON_LCU_COMMON_CH_2_CONF_CH_2_REC_FORMAT_RST    0x0

__INLINE void lcu_common_lcu_common_ch_2_conf_pack(uint8_t ch2_write_vci, uint8_t ch2_write_ts, uint8_t ch2_rec_format)
{
	ASSERT_ERR((((uint32_t)ch2_write_vci << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)ch2_write_ts << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ch2_rec_format << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR,  ((uint32_t)ch2_write_vci << 2) |((uint32_t)ch2_write_ts << 1) |((uint32_t)ch2_rec_format << 0));
}

__INLINE void lcu_common_lcu_common_ch_2_conf_unpack(uint8_t* ch2_write_vci, uint8_t* ch2_write_ts, uint8_t* ch2_rec_format)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR);

	*ch2_write_vci = (localVal & ((uint32_t)0x00000004)) >>  2;
	*ch2_write_ts = (localVal & ((uint32_t)0x00000002)) >>  1;
	*ch2_rec_format = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_ch_2_conf_ch_2_write_vci_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void lcu_common_lcu_common_ch_2_conf_ch_2_write_vci_setf(uint8_t ch2writevci)
{
	ASSERT_ERR((((uint32_t)ch2writevci << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)ch2writevci <<2));
}
__INLINE uint8_t lcu_common_lcu_common_ch_2_conf_ch_2_write_ts_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void lcu_common_lcu_common_ch_2_conf_ch_2_write_ts_setf(uint8_t ch2writets)
{
	ASSERT_ERR((((uint32_t)ch2writets << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ch2writets <<1));
}
__INLINE uint8_t lcu_common_lcu_common_ch_2_conf_ch_2_rec_format_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void lcu_common_lcu_common_ch_2_conf_ch_2_rec_format_setf(uint8_t ch2recformat)
{
	ASSERT_ERR((((uint32_t)ch2recformat << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_2_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch2recformat <<0));
}

/**
 * @brief LCU_COMMON_CH_3_CONF register definition
 *  Channel 3 Configuration Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    CH3_WRITE_VCI             0              
 *    01    CH3_WRITE_TS              0              
 *    00    CH3_REC_FORMAT            0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000010C)
#define LCU_COMMON_LCU_COMMON_CH_3_CONF_OFFSET      0x0000010C
#define LCU_COMMON_LCU_COMMON_CH_3_CONF_INDEX       0x00000043
#define LCU_COMMON_LCU_COMMON_CH_3_CONF_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_ch_3_conf_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR);
}

__INLINE void lcu_common_lcu_common_ch_3_conf_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_CH_3_CONF_CH_3_WRITE_VCI_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_CH_3_CONF_CH_3_WRITE_VCI_POS    2
#define LCU_COMMON_LCU_COMMON_CH_3_CONF_CH_3_WRITE_TS_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_CH_3_CONF_CH_3_WRITE_TS_POS    1
#define LCU_COMMON_LCU_COMMON_CH_3_CONF_CH_3_REC_FORMAT_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_CH_3_CONF_CH_3_REC_FORMAT_POS    0

#define LCU_COMMON_LCU_COMMON_CH_3_CONF_CH_3_WRITE_VCI_RST    0x0
#define LCU_COMMON_LCU_COMMON_CH_3_CONF_CH_3_WRITE_TS_RST    0x0
#define LCU_COMMON_LCU_COMMON_CH_3_CONF_CH_3_REC_FORMAT_RST    0x0

__INLINE void lcu_common_lcu_common_ch_3_conf_pack(uint8_t ch3_write_vci, uint8_t ch3_write_ts, uint8_t ch3_rec_format)
{
	ASSERT_ERR((((uint32_t)ch3_write_vci << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)ch3_write_ts << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ch3_rec_format << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR,  ((uint32_t)ch3_write_vci << 2) |((uint32_t)ch3_write_ts << 1) |((uint32_t)ch3_rec_format << 0));
}

__INLINE void lcu_common_lcu_common_ch_3_conf_unpack(uint8_t* ch3_write_vci, uint8_t* ch3_write_ts, uint8_t* ch3_rec_format)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR);

	*ch3_write_vci = (localVal & ((uint32_t)0x00000004)) >>  2;
	*ch3_write_ts = (localVal & ((uint32_t)0x00000002)) >>  1;
	*ch3_rec_format = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_ch_3_conf_ch_3_write_vci_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void lcu_common_lcu_common_ch_3_conf_ch_3_write_vci_setf(uint8_t ch3writevci)
{
	ASSERT_ERR((((uint32_t)ch3writevci << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)ch3writevci <<2));
}
__INLINE uint8_t lcu_common_lcu_common_ch_3_conf_ch_3_write_ts_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void lcu_common_lcu_common_ch_3_conf_ch_3_write_ts_setf(uint8_t ch3writets)
{
	ASSERT_ERR((((uint32_t)ch3writets << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ch3writets <<1));
}
__INLINE uint8_t lcu_common_lcu_common_ch_3_conf_ch_3_rec_format_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void lcu_common_lcu_common_ch_3_conf_ch_3_rec_format_setf(uint8_t ch3recformat)
{
	ASSERT_ERR((((uint32_t)ch3recformat << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_3_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch3recformat <<0));
}

/**
 * @brief LCU_COMMON_CH_4_CONF register definition
 *  Channel 4 Configuration Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    CH4_WRITE_VCI             0              
 *    01    CH4_WRITE_TS              0              
 *    00    CH4_REC_FORMAT            0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000110)
#define LCU_COMMON_LCU_COMMON_CH_4_CONF_OFFSET      0x00000110
#define LCU_COMMON_LCU_COMMON_CH_4_CONF_INDEX       0x00000044
#define LCU_COMMON_LCU_COMMON_CH_4_CONF_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_ch_4_conf_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR);
}

__INLINE void lcu_common_lcu_common_ch_4_conf_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_CH_4_CONF_CH_4_WRITE_VCI_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_CH_4_CONF_CH_4_WRITE_VCI_POS    2
#define LCU_COMMON_LCU_COMMON_CH_4_CONF_CH_4_WRITE_TS_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_CH_4_CONF_CH_4_WRITE_TS_POS    1
#define LCU_COMMON_LCU_COMMON_CH_4_CONF_CH_4_REC_FORMAT_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_CH_4_CONF_CH_4_REC_FORMAT_POS    0

#define LCU_COMMON_LCU_COMMON_CH_4_CONF_CH_4_WRITE_VCI_RST    0x0
#define LCU_COMMON_LCU_COMMON_CH_4_CONF_CH_4_WRITE_TS_RST    0x0
#define LCU_COMMON_LCU_COMMON_CH_4_CONF_CH_4_REC_FORMAT_RST    0x0

__INLINE void lcu_common_lcu_common_ch_4_conf_pack(uint8_t ch4_write_vci, uint8_t ch4_write_ts, uint8_t ch4_rec_format)
{
	ASSERT_ERR((((uint32_t)ch4_write_vci << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)ch4_write_ts << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ch4_rec_format << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR,  ((uint32_t)ch4_write_vci << 2) |((uint32_t)ch4_write_ts << 1) |((uint32_t)ch4_rec_format << 0));
}

__INLINE void lcu_common_lcu_common_ch_4_conf_unpack(uint8_t* ch4_write_vci, uint8_t* ch4_write_ts, uint8_t* ch4_rec_format)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR);

	*ch4_write_vci = (localVal & ((uint32_t)0x00000004)) >>  2;
	*ch4_write_ts = (localVal & ((uint32_t)0x00000002)) >>  1;
	*ch4_rec_format = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_ch_4_conf_ch_4_write_vci_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void lcu_common_lcu_common_ch_4_conf_ch_4_write_vci_setf(uint8_t ch4writevci)
{
	ASSERT_ERR((((uint32_t)ch4writevci << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)ch4writevci <<2));
}
__INLINE uint8_t lcu_common_lcu_common_ch_4_conf_ch_4_write_ts_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void lcu_common_lcu_common_ch_4_conf_ch_4_write_ts_setf(uint8_t ch4writets)
{
	ASSERT_ERR((((uint32_t)ch4writets << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ch4writets <<1));
}
__INLINE uint8_t lcu_common_lcu_common_ch_4_conf_ch_4_rec_format_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void lcu_common_lcu_common_ch_4_conf_ch_4_rec_format_setf(uint8_t ch4recformat)
{
	ASSERT_ERR((((uint32_t)ch4recformat << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_4_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch4recformat <<0));
}

/**
 * @brief LCU_COMMON_CH_5_CONF register definition
 *  Channel 5 Configuration Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    CH5_WRITE_VCI             0              
 *    01    CH5_WRITE_TS              0              
 *    00    CH5_REC_FORMAT            0              
 * </pre>
 */
#define LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000114)
#define LCU_COMMON_LCU_COMMON_CH_5_CONF_OFFSET      0x00000114
#define LCU_COMMON_LCU_COMMON_CH_5_CONF_INDEX       0x00000045
#define LCU_COMMON_LCU_COMMON_CH_5_CONF_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_common_ch_5_conf_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR);
}

__INLINE void lcu_common_lcu_common_ch_5_conf_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_COMMON_CH_5_CONF_CH_5_WRITE_VCI_BIT    ((uint32_t)0x00000004)
#define LCU_COMMON_LCU_COMMON_CH_5_CONF_CH_5_WRITE_VCI_POS    2
#define LCU_COMMON_LCU_COMMON_CH_5_CONF_CH_5_WRITE_TS_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_COMMON_CH_5_CONF_CH_5_WRITE_TS_POS    1
#define LCU_COMMON_LCU_COMMON_CH_5_CONF_CH_5_REC_FORMAT_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_COMMON_CH_5_CONF_CH_5_REC_FORMAT_POS    0

#define LCU_COMMON_LCU_COMMON_CH_5_CONF_CH_5_WRITE_VCI_RST    0x0
#define LCU_COMMON_LCU_COMMON_CH_5_CONF_CH_5_WRITE_TS_RST    0x0
#define LCU_COMMON_LCU_COMMON_CH_5_CONF_CH_5_REC_FORMAT_RST    0x0

__INLINE void lcu_common_lcu_common_ch_5_conf_pack(uint8_t ch5_write_vci, uint8_t ch5_write_ts, uint8_t ch5_rec_format)
{
	ASSERT_ERR((((uint32_t)ch5_write_vci << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)ch5_write_ts << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ch5_rec_format << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR,  ((uint32_t)ch5_write_vci << 2) |((uint32_t)ch5_write_ts << 1) |((uint32_t)ch5_rec_format << 0));
}

__INLINE void lcu_common_lcu_common_ch_5_conf_unpack(uint8_t* ch5_write_vci, uint8_t* ch5_write_ts, uint8_t* ch5_rec_format)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR);

	*ch5_write_vci = (localVal & ((uint32_t)0x00000004)) >>  2;
	*ch5_write_ts = (localVal & ((uint32_t)0x00000002)) >>  1;
	*ch5_rec_format = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_common_ch_5_conf_ch_5_write_vci_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void lcu_common_lcu_common_ch_5_conf_ch_5_write_vci_setf(uint8_t ch5writevci)
{
	ASSERT_ERR((((uint32_t)ch5writevci << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)ch5writevci <<2));
}
__INLINE uint8_t lcu_common_lcu_common_ch_5_conf_ch_5_write_ts_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void lcu_common_lcu_common_ch_5_conf_ch_5_write_ts_setf(uint8_t ch5writets)
{
	ASSERT_ERR((((uint32_t)ch5writets << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ch5writets <<1));
}
__INLINE uint8_t lcu_common_lcu_common_ch_5_conf_ch_5_rec_format_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void lcu_common_lcu_common_ch_5_conf_ch_5_rec_format_setf(uint8_t ch5recformat)
{
	ASSERT_ERR((((uint32_t)ch5recformat << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR, (REG_PL_RD(LCU_COMMON_LCU_COMMON_CH_5_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ch5recformat <<0));
}

/**
 * @brief MAC_ELA_CH_01_MASK_REG_0 register definition
 *  Channel 01 Mask Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_MASK_REG0            0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000800)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_OFFSET      0x00000800
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_INDEX       0x00000200
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_mask_reg_0_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_mask_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_CH_01_MASK_REG_0_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_CH_01_MASK_REG_0_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_CH_01_MASK_REG_0_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_CH_01_MASK_REG_0_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_mask_reg_0_ch_01_mask_reg_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_mask_reg_0_ch_01_mask_reg_0_setf(uint32_t ch01maskreg0)
{
	ASSERT_ERR((((uint32_t)ch01maskreg0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_ADDR, (uint32_t)ch01maskreg0 << 0);
}

/**
 * @brief MAC_ELA_CH_01_MASK_REG_1 register definition
 *  Channel 01 Mask Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_MASK_REG1            0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000804)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_OFFSET      0x00000804
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_INDEX       0x00000201
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_mask_reg_1_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_mask_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_CH_01_MASK_REG_1_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_CH_01_MASK_REG_1_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_CH_01_MASK_REG_1_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_CH_01_MASK_REG_1_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_mask_reg_1_ch_01_mask_reg_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_mask_reg_1_ch_01_mask_reg_1_setf(uint32_t ch01maskreg1)
{
	ASSERT_ERR((((uint32_t)ch01maskreg1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_ADDR, (uint32_t)ch01maskreg1 << 0);
}

/**
 * @brief MAC_ELA_CH_01_MASK_REG_2 register definition
 *  Channel 01 Mask Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_MASK_REG2            0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000808)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_OFFSET      0x00000808
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_INDEX       0x00000202
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_mask_reg_2_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_mask_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_CH_01_MASK_REG_2_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_CH_01_MASK_REG_2_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_CH_01_MASK_REG_2_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_CH_01_MASK_REG_2_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_mask_reg_2_ch_01_mask_reg_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_mask_reg_2_ch_01_mask_reg_2_setf(uint32_t ch01maskreg2)
{
	ASSERT_ERR((((uint32_t)ch01maskreg2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_ADDR, (uint32_t)ch01maskreg2 << 0);
}

/**
 * @brief MAC_ELA_CH_01_MASK_REG_3 register definition
 *  Channel 01 Mask Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_MASK_REG3            0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000080C)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_OFFSET      0x0000080C
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_INDEX       0x00000203
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_mask_reg_3_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_mask_reg_3_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_CH_01_MASK_REG_3_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_CH_01_MASK_REG_3_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_CH_01_MASK_REG_3_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_CH_01_MASK_REG_3_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_mask_reg_3_ch_01_mask_reg_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_mask_reg_3_ch_01_mask_reg_3_setf(uint32_t ch01maskreg3)
{
	ASSERT_ERR((((uint32_t)ch01maskreg3 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_ADDR, (uint32_t)ch01maskreg3 << 0);
}

/**
 * @brief MAC_ELA_CH_01_MASK_REG_4 register definition
 *  Channel 01 Mask Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_MASK_REG4            0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000810)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_OFFSET      0x00000810
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_INDEX       0x00000204
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_mask_reg_4_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_mask_reg_4_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_CH_01_MASK_REG_4_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_CH_01_MASK_REG_4_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_CH_01_MASK_REG_4_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_CH_01_MASK_REG_4_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_mask_reg_4_ch_01_mask_reg_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_mask_reg_4_ch_01_mask_reg_4_setf(uint32_t ch01maskreg4)
{
	ASSERT_ERR((((uint32_t)ch01maskreg4 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_ADDR, (uint32_t)ch01maskreg4 << 0);
}

/**
 * @brief MAC_ELA_CH_01_MASK_REG_5 register definition
 *  Channel 01 Mask Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_MASK_REG5            0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000814)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_OFFSET      0x00000814
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_INDEX       0x00000205
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_mask_reg_5_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_mask_reg_5_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_CH_01_MASK_REG_5_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_CH_01_MASK_REG_5_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_CH_01_MASK_REG_5_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_CH_01_MASK_REG_5_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_mask_reg_5_ch_01_mask_reg_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_mask_reg_5_ch_01_mask_reg_5_setf(uint32_t ch01maskreg5)
{
	ASSERT_ERR((((uint32_t)ch01maskreg5 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_ADDR, (uint32_t)ch01maskreg5 << 0);
}

/**
 * @brief MAC_ELA_CH_01_MASK_REG_6 register definition
 *  Channel 01 Mask Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_MASK_REG6            0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000818)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_OFFSET      0x00000818
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_INDEX       0x00000206
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_mask_reg_6_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_mask_reg_6_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_CH_01_MASK_REG_6_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_CH_01_MASK_REG_6_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_CH_01_MASK_REG_6_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_CH_01_MASK_REG_6_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_mask_reg_6_ch_01_mask_reg_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_mask_reg_6_ch_01_mask_reg_6_setf(uint32_t ch01maskreg6)
{
	ASSERT_ERR((((uint32_t)ch01maskreg6 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_ADDR, (uint32_t)ch01maskreg6 << 0);
}

/**
 * @brief MAC_ELA_CH_01_MASK_REG_7 register definition
 *  Channel 01 Mask Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_MASK_REG7            0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000081C)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_OFFSET      0x0000081C
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_INDEX       0x00000207
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_mask_reg_7_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_mask_reg_7_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_CH_01_MASK_REG_7_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_CH_01_MASK_REG_7_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_CH_01_MASK_REG_7_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_CH_01_MASK_REG_7_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_mask_reg_7_ch_01_mask_reg_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_mask_reg_7_ch_01_mask_reg_7_setf(uint32_t ch01maskreg7)
{
	ASSERT_ERR((((uint32_t)ch01maskreg7 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_ADDR, (uint32_t)ch01maskreg7 << 0);
}

/**
 * @brief MAC_ELA_CH_0_EN register definition
 *  Channel 0 Enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_EN                    0              
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_0_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000820)
#define LCU_COMMON_MAC_ELA_CH_0_EN_OFFSET      0x00000820
#define LCU_COMMON_MAC_ELA_CH_0_EN_INDEX       0x00000208
#define LCU_COMMON_MAC_ELA_CH_0_EN_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_0_en_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_0_EN_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_0_en_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_0_EN_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_0_EN_CH_0_EN_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_MAC_ELA_CH_0_EN_CH_0_EN_POS    0

#define LCU_COMMON_MAC_ELA_CH_0_EN_CH_0_EN_RST    0x0

__INLINE uint8_t lcu_common_mac_ela_ch_0_en_ch_0_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_0_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_0_en_ch_0_en_setf(uint8_t ch0en)
{
	ASSERT_ERR((((uint32_t)ch0en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_0_EN_ADDR, (uint32_t)ch0en << 0);
}

/**
 * @brief MAC_ELA_CH_1_EN register definition
 *  Channel 1 Enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_EN                    0              
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_1_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000824)
#define LCU_COMMON_MAC_ELA_CH_1_EN_OFFSET      0x00000824
#define LCU_COMMON_MAC_ELA_CH_1_EN_INDEX       0x00000209
#define LCU_COMMON_MAC_ELA_CH_1_EN_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_1_en_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_1_EN_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_1_en_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_1_EN_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_1_EN_CH_1_EN_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_MAC_ELA_CH_1_EN_CH_1_EN_POS    0

#define LCU_COMMON_MAC_ELA_CH_1_EN_CH_1_EN_RST    0x0

__INLINE uint8_t lcu_common_mac_ela_ch_1_en_ch_1_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_1_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_1_en_ch_1_en_setf(uint8_t ch1en)
{
	ASSERT_ERR((((uint32_t)ch1en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_1_EN_ADDR, (uint32_t)ch1en << 0);
}

/**
 * @brief MAC_ELA_CH_0_SELECT register definition
 *  Channel 0 Select register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:00 CH0_SELECT                0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000828)
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_OFFSET      0x00000828
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_INDEX       0x0000020A
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_0_select_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_0_SELECT_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_0_select_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_0_SELECT_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_CH_0_SELECT_MASK    ((uint32_t)0x0000003F)
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_CH_0_SELECT_LSB    0
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_CH_0_SELECT_WIDTH    ((uint32_t)0x00000006)

#define LCU_COMMON_MAC_ELA_CH_0_SELECT_CH_0_SELECT_RST    0x0

__INLINE uint8_t lcu_common_mac_ela_ch_0_select_ch_0_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_0_SELECT_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_0_select_ch_0_select_setf(uint8_t ch0select)
{
	ASSERT_ERR((((uint32_t)ch0select << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_0_SELECT_ADDR, (uint32_t)ch0select << 0);
}

/**
 * @brief MAC_ELA_CH_1_SELECT register definition
 *  Channel 1 Select register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 CH1_SELECT                0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000082C)
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_OFFSET      0x0000082C
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_INDEX       0x0000020B
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_1_select_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_1_SELECT_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_1_select_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_1_SELECT_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_CH_1_SELECT_MASK    ((uint32_t)0x0000001F)
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_CH_1_SELECT_LSB    0
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_CH_1_SELECT_WIDTH    ((uint32_t)0x00000005)

#define LCU_COMMON_MAC_ELA_CH_1_SELECT_CH_1_SELECT_RST    0x0

__INLINE uint8_t lcu_common_mac_ela_ch_1_select_ch_1_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_1_SELECT_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_1_select_ch_1_select_setf(uint8_t ch1select)
{
	ASSERT_ERR((((uint32_t)ch1select << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_1_SELECT_ADDR, (uint32_t)ch1select << 0);
}

/**
 * @brief MAC_ELA_CH_0_TRIG_MODE register definition
 *  Channel 0 Trigger mode register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_TRIG_MODE             0              
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000830)
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_OFFSET      0x00000830
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_INDEX       0x0000020C
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_0_trig_mode_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_0_trig_mode_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_CH_0_TRIG_MODE_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_CH_0_TRIG_MODE_POS    0

#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_CH_0_TRIG_MODE_RST    0x0

__INLINE uint8_t lcu_common_mac_ela_ch_0_trig_mode_ch_0_trig_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_0_trig_mode_ch_0_trig_mode_setf(uint8_t ch0trigmode)
{
	ASSERT_ERR((((uint32_t)ch0trigmode << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_ADDR, (uint32_t)ch0trigmode << 0);
}

/**
 * @brief MAC_ELA_CH_1_TRIG_MODE register definition
 *  Channel 1 Trigger mode register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_TRIG_MODE             0              
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000834)
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_OFFSET      0x00000834
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_INDEX       0x0000020D
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_1_trig_mode_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_1_trig_mode_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_CH_1_TRIG_MODE_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_CH_1_TRIG_MODE_POS    0

#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_CH_1_TRIG_MODE_RST    0x0

__INLINE uint8_t lcu_common_mac_ela_ch_1_trig_mode_ch_1_trig_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_1_trig_mode_ch_1_trig_mode_setf(uint8_t ch1trigmode)
{
	ASSERT_ERR((((uint32_t)ch1trigmode << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_ADDR, (uint32_t)ch1trigmode << 0);
}

/**
 * @brief MAC_ELA_CH_0_TRIG_EN register definition
 *  Channel 0 Trigger Enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_TRIG_EN               0              
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000838)
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_OFFSET      0x00000838
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_INDEX       0x0000020E
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_RESET       0x00000000

__INLINE void lcu_common_mac_ela_ch_0_trig_en_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_CH_0_TRIG_EN_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_CH_0_TRIG_EN_POS    0

#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_CH_0_TRIG_EN_RST    0x0

__INLINE void lcu_common_mac_ela_ch_0_trig_en_ch_0_trig_en_setf(uint8_t ch0trigen)
{
	ASSERT_ERR((((uint32_t)ch0trigen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_ADDR, (uint32_t)ch0trigen << 0);
}

/**
 * @brief MAC_ELA_CH_1_TRIG_EN register definition
 *  Channel 1 Trigger Enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_TRIG_EN               0              
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000083C)
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_OFFSET      0x0000083C
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_INDEX       0x0000020F
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_RESET       0x00000000

__INLINE void lcu_common_mac_ela_ch_1_trig_en_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_CH_1_TRIG_EN_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_CH_1_TRIG_EN_POS    0

#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_CH_1_TRIG_EN_RST    0x0

__INLINE void lcu_common_mac_ela_ch_1_trig_en_ch_1_trig_en_setf(uint8_t ch1trigen)
{
	ASSERT_ERR((((uint32_t)ch1trigen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_ADDR, (uint32_t)ch1trigen << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_PTRN_REG_0 register definition
 *  Channel 01 Trigger Pattern register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_PTRN_REG0       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000840)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_OFFSET      0x00000840
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_INDEX       0x00000210
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_ptrn_reg_0_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_CH_01_TRIG_PTRN_REG_0_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_CH_01_TRIG_PTRN_REG_0_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_CH_01_TRIG_PTRN_REG_0_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_CH_01_TRIG_PTRN_REG_0_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_ptrn_reg_0_ch_01_trig_ptrn_reg_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_0_ch_01_trig_ptrn_reg_0_setf(uint32_t ch01trigptrnreg0)
{
	ASSERT_ERR((((uint32_t)ch01trigptrnreg0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_ADDR, (uint32_t)ch01trigptrnreg0 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_PTRN_REG_1 register definition
 *  Channel 01 Trigger Pattern register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_PTRN_REG1       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000844)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_OFFSET      0x00000844
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_INDEX       0x00000211
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_ptrn_reg_1_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_CH_01_TRIG_PTRN_REG_1_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_CH_01_TRIG_PTRN_REG_1_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_CH_01_TRIG_PTRN_REG_1_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_CH_01_TRIG_PTRN_REG_1_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_ptrn_reg_1_ch_01_trig_ptrn_reg_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_1_ch_01_trig_ptrn_reg_1_setf(uint32_t ch01trigptrnreg1)
{
	ASSERT_ERR((((uint32_t)ch01trigptrnreg1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_ADDR, (uint32_t)ch01trigptrnreg1 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_PTRN_REG_2 register definition
 *  Channel 01 Trigger Pattern register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_PTRN_REG2       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000848)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_OFFSET      0x00000848
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_INDEX       0x00000212
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_ptrn_reg_2_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_CH_01_TRIG_PTRN_REG_2_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_CH_01_TRIG_PTRN_REG_2_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_CH_01_TRIG_PTRN_REG_2_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_CH_01_TRIG_PTRN_REG_2_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_ptrn_reg_2_ch_01_trig_ptrn_reg_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_2_ch_01_trig_ptrn_reg_2_setf(uint32_t ch01trigptrnreg2)
{
	ASSERT_ERR((((uint32_t)ch01trigptrnreg2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_ADDR, (uint32_t)ch01trigptrnreg2 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_PTRN_REG_3 register definition
 *  Channel 01 Trigger Pattern register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_PTRN_REG3       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000084C)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_OFFSET      0x0000084C
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_INDEX       0x00000213
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_ptrn_reg_3_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_3_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_CH_01_TRIG_PTRN_REG_3_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_CH_01_TRIG_PTRN_REG_3_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_CH_01_TRIG_PTRN_REG_3_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_CH_01_TRIG_PTRN_REG_3_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_ptrn_reg_3_ch_01_trig_ptrn_reg_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_3_ch_01_trig_ptrn_reg_3_setf(uint32_t ch01trigptrnreg3)
{
	ASSERT_ERR((((uint32_t)ch01trigptrnreg3 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_ADDR, (uint32_t)ch01trigptrnreg3 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_PTRN_REG_4 register definition
 *  Channel 01 Trigger Pattern register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_PTRN_REG4       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000850)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_OFFSET      0x00000850
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_INDEX       0x00000214
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_ptrn_reg_4_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_4_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_CH_01_TRIG_PTRN_REG_4_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_CH_01_TRIG_PTRN_REG_4_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_CH_01_TRIG_PTRN_REG_4_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_CH_01_TRIG_PTRN_REG_4_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_ptrn_reg_4_ch_01_trig_ptrn_reg_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_4_ch_01_trig_ptrn_reg_4_setf(uint32_t ch01trigptrnreg4)
{
	ASSERT_ERR((((uint32_t)ch01trigptrnreg4 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_ADDR, (uint32_t)ch01trigptrnreg4 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_PTRN_REG_5 register definition
 *  Channel 01 Trigger Pattern register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_PTRN_REG5       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000854)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_OFFSET      0x00000854
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_INDEX       0x00000215
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_ptrn_reg_5_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_5_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_CH_01_TRIG_PTRN_REG_5_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_CH_01_TRIG_PTRN_REG_5_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_CH_01_TRIG_PTRN_REG_5_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_CH_01_TRIG_PTRN_REG_5_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_ptrn_reg_5_ch_01_trig_ptrn_reg_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_5_ch_01_trig_ptrn_reg_5_setf(uint32_t ch01trigptrnreg5)
{
	ASSERT_ERR((((uint32_t)ch01trigptrnreg5 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_ADDR, (uint32_t)ch01trigptrnreg5 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_PTRN_REG_6 register definition
 *  Channel 01 Trigger Pattern register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_PTRN_REG6       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000858)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_OFFSET      0x00000858
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_INDEX       0x00000216
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_ptrn_reg_6_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_6_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_CH_01_TRIG_PTRN_REG_6_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_CH_01_TRIG_PTRN_REG_6_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_CH_01_TRIG_PTRN_REG_6_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_CH_01_TRIG_PTRN_REG_6_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_ptrn_reg_6_ch_01_trig_ptrn_reg_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_6_ch_01_trig_ptrn_reg_6_setf(uint32_t ch01trigptrnreg6)
{
	ASSERT_ERR((((uint32_t)ch01trigptrnreg6 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_ADDR, (uint32_t)ch01trigptrnreg6 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_PTRN_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_PTRN_REG7       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000085C)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_OFFSET      0x0000085C
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_INDEX       0x00000217
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_ptrn_reg_7_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_7_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_CH_01_TRIG_PTRN_REG_7_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_CH_01_TRIG_PTRN_REG_7_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_CH_01_TRIG_PTRN_REG_7_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_CH_01_TRIG_PTRN_REG_7_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_ptrn_reg_7_ch_01_trig_ptrn_reg_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_ptrn_reg_7_ch_01_trig_ptrn_reg_7_setf(uint32_t ch01trigptrnreg7)
{
	ASSERT_ERR((((uint32_t)ch01trigptrnreg7 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_ADDR, (uint32_t)ch01trigptrnreg7 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_MASK_REG_0 register definition
 *  Channel 01 Trigger Mask register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_MASK_REG0       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000860)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_OFFSET      0x00000860
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_INDEX       0x00000218
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_mask_reg_0_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_CH_01_TRIG_MASK_REG_0_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_CH_01_TRIG_MASK_REG_0_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_CH_01_TRIG_MASK_REG_0_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_CH_01_TRIG_MASK_REG_0_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_mask_reg_0_ch_01_trig_mask_reg_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_0_ch_01_trig_mask_reg_0_setf(uint32_t ch01trigmaskreg0)
{
	ASSERT_ERR((((uint32_t)ch01trigmaskreg0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_ADDR, (uint32_t)ch01trigmaskreg0 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_MASK_REG_1 register definition
 *  Channel 01 Trigger Mask register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_MASK_REG1       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000864)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_OFFSET      0x00000864
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_INDEX       0x00000219
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_mask_reg_1_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_CH_01_TRIG_MASK_REG_1_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_CH_01_TRIG_MASK_REG_1_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_CH_01_TRIG_MASK_REG_1_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_CH_01_TRIG_MASK_REG_1_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_mask_reg_1_ch_01_trig_mask_reg_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_1_ch_01_trig_mask_reg_1_setf(uint32_t ch01trigmaskreg1)
{
	ASSERT_ERR((((uint32_t)ch01trigmaskreg1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_ADDR, (uint32_t)ch01trigmaskreg1 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_MASK_REG_2 register definition
 *  Channel 01 Trigger Mask register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_MASK_REG2       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000868)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_OFFSET      0x00000868
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_INDEX       0x0000021A
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_mask_reg_2_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_CH_01_TRIG_MASK_REG_2_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_CH_01_TRIG_MASK_REG_2_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_CH_01_TRIG_MASK_REG_2_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_CH_01_TRIG_MASK_REG_2_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_mask_reg_2_ch_01_trig_mask_reg_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_2_ch_01_trig_mask_reg_2_setf(uint32_t ch01trigmaskreg2)
{
	ASSERT_ERR((((uint32_t)ch01trigmaskreg2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_ADDR, (uint32_t)ch01trigmaskreg2 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_MASK_REG_3 register definition
 *  Channel 01 Trigger Mask register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_MASK_REG3       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000086C)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_OFFSET      0x0000086C
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_INDEX       0x0000021B
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_mask_reg_3_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_3_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_CH_01_TRIG_MASK_REG_3_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_CH_01_TRIG_MASK_REG_3_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_CH_01_TRIG_MASK_REG_3_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_CH_01_TRIG_MASK_REG_3_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_mask_reg_3_ch_01_trig_mask_reg_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_3_ch_01_trig_mask_reg_3_setf(uint32_t ch01trigmaskreg3)
{
	ASSERT_ERR((((uint32_t)ch01trigmaskreg3 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_ADDR, (uint32_t)ch01trigmaskreg3 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_MASK_REG_4 register definition
 *  Channel 01 Trigger Mask register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_MASK_REG4       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000870)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_OFFSET      0x00000870
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_INDEX       0x0000021C
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_mask_reg_4_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_4_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_CH_01_TRIG_MASK_REG_4_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_CH_01_TRIG_MASK_REG_4_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_CH_01_TRIG_MASK_REG_4_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_CH_01_TRIG_MASK_REG_4_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_mask_reg_4_ch_01_trig_mask_reg_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_4_ch_01_trig_mask_reg_4_setf(uint32_t ch01trigmaskreg4)
{
	ASSERT_ERR((((uint32_t)ch01trigmaskreg4 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_ADDR, (uint32_t)ch01trigmaskreg4 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_MASK_REG_5 register definition
 *  Channel 01 Trigger Mask register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_MASK_REG5       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000874)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_OFFSET      0x00000874
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_INDEX       0x0000021D
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_mask_reg_5_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_5_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_CH_01_TRIG_MASK_REG_5_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_CH_01_TRIG_MASK_REG_5_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_CH_01_TRIG_MASK_REG_5_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_CH_01_TRIG_MASK_REG_5_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_mask_reg_5_ch_01_trig_mask_reg_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_5_ch_01_trig_mask_reg_5_setf(uint32_t ch01trigmaskreg5)
{
	ASSERT_ERR((((uint32_t)ch01trigmaskreg5 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_ADDR, (uint32_t)ch01trigmaskreg5 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_MASK_REG_6 register definition
 *  Channel 01 Trigger Mask register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_MASK_REG6       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000878)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_OFFSET      0x00000878
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_INDEX       0x0000021E
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_mask_reg_6_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_6_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_CH_01_TRIG_MASK_REG_6_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_CH_01_TRIG_MASK_REG_6_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_CH_01_TRIG_MASK_REG_6_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_CH_01_TRIG_MASK_REG_6_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_mask_reg_6_ch_01_trig_mask_reg_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_6_ch_01_trig_mask_reg_6_setf(uint32_t ch01trigmaskreg6)
{
	ASSERT_ERR((((uint32_t)ch01trigmaskreg6 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_ADDR, (uint32_t)ch01trigmaskreg6 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_MASK_REG_7 register definition
 *  Channel 01 Trigger Mask register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_MASK_REG7       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000087C)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_OFFSET      0x0000087C
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_INDEX       0x0000021F
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_01_trig_mask_reg_7_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_ADDR);
}

__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_7_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_ADDR, value);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_CH_01_TRIG_MASK_REG_7_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_CH_01_TRIG_MASK_REG_7_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_CH_01_TRIG_MASK_REG_7_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_CH_01_TRIG_MASK_REG_7_RST    0x0

__INLINE uint32_t lcu_common_mac_ela_ch_01_trig_mask_reg_7_ch_01_trig_mask_reg_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_mac_ela_ch_01_trig_mask_reg_7_ch_01_trig_mask_reg_7_setf(uint32_t ch01trigmaskreg7)
{
	ASSERT_ERR((((uint32_t)ch01trigmaskreg7 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_ADDR, (uint32_t)ch01trigmaskreg7 << 0);
}

/**
 * @brief MAC_ELA_CH_0_TRIG_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 TRIG_STATUS               0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000880)
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_OFFSET      0x00000880
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_INDEX       0x00000220
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_0_trig_status_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_ADDR);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_TRIG_STATUS_MASK    ((uint32_t)0x00000003)
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_TRIG_STATUS_LSB    0
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_TRIG_STATUS_WIDTH    ((uint32_t)0x00000002)

#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_TRIG_STATUS_RST    0x0

__INLINE uint8_t lcu_common_mac_ela_ch_0_trig_status_trig_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief MAC_ELA_CH_1_TRIG_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 TRIG_STATUS               0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000884)
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_OFFSET      0x00000884
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_INDEX       0x00000221
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_RESET       0x00000000

__INLINE uint32_t  lcu_common_mac_ela_ch_1_trig_status_get(void)
{
	return REG_PL_RD(LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_ADDR);
}

// field definitions
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_TRIG_STATUS_MASK    ((uint32_t)0x00000003)
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_TRIG_STATUS_LSB    0
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_TRIG_STATUS_WIDTH    ((uint32_t)0x00000002)

#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_TRIG_STATUS_RST    0x0

__INLINE uint8_t lcu_common_mac_ela_ch_1_trig_status_trig_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief LCU_BT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    LCU_BT_EN                 0              
 * </pre>
 */
#define LCU_COMMON_LCU_BT_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000900)
#define LCU_COMMON_LCU_BT_EN_OFFSET      0x00000900
#define LCU_COMMON_LCU_BT_EN_INDEX       0x00000240
#define LCU_COMMON_LCU_BT_EN_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_en_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_EN_ADDR);
}

__INLINE void lcu_common_lcu_bt_en_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_EN_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_EN_LCU_BT_EN_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_BT_EN_LCU_BT_EN_POS    0

#define LCU_COMMON_LCU_BT_EN_LCU_BT_EN_RST    0x0

__INLINE uint8_t lcu_common_lcu_bt_en_lcu_bt_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_en_lcu_bt_en_setf(uint8_t lcubten)
{
	ASSERT_ERR((((uint32_t)lcubten << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_EN_ADDR, (uint32_t)lcubten << 0);
}

/**
 * @brief LCU_BT_START register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    LCU_BT_START              0              
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000904)
#define LCU_COMMON_LCU_BT_START_OFFSET      0x00000904
#define LCU_COMMON_LCU_BT_START_INDEX       0x00000241
#define LCU_COMMON_LCU_BT_START_RESET       0x00000000

__INLINE void lcu_common_lcu_bt_start_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_START_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_START_LCU_BT_START_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_BT_START_LCU_BT_START_POS    0

#define LCU_COMMON_LCU_BT_START_LCU_BT_START_RST    0x0

__INLINE void lcu_common_lcu_bt_start_lcu_bt_start_setf(uint8_t lcubtstart)
{
	ASSERT_ERR((((uint32_t)lcubtstart << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_START_ADDR, (uint32_t)lcubtstart << 0);
}

/**
 * @brief LCU_BT_START_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    LCU_BT_EXT_STRT_EN        0              
 *    00    LCU_BT_STRT_PTRN_EN       0              
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000908)
#define LCU_COMMON_LCU_BT_START_EN_OFFSET      0x00000908
#define LCU_COMMON_LCU_BT_START_EN_INDEX       0x00000242
#define LCU_COMMON_LCU_BT_START_EN_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_start_en_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_START_EN_ADDR);
}

__INLINE void lcu_common_lcu_bt_start_en_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_START_EN_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_START_EN_LCU_BT_EXT_STRT_EN_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_BT_START_EN_LCU_BT_EXT_STRT_EN_POS    1
#define LCU_COMMON_LCU_BT_START_EN_LCU_BT_STRT_PTRN_EN_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_BT_START_EN_LCU_BT_STRT_PTRN_EN_POS    0

#define LCU_COMMON_LCU_BT_START_EN_LCU_BT_EXT_STRT_EN_RST    0x0
#define LCU_COMMON_LCU_BT_START_EN_LCU_BT_STRT_PTRN_EN_RST    0x0

__INLINE void lcu_common_lcu_bt_start_en_pack(uint8_t lcu_bt_ext_strt_en, uint8_t lcu_bt_strt_ptrn_en)
{
	ASSERT_ERR((((uint32_t)lcu_bt_ext_strt_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)lcu_bt_strt_ptrn_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_START_EN_ADDR,  ((uint32_t)lcu_bt_ext_strt_en << 1) |((uint32_t)lcu_bt_strt_ptrn_en << 0));
}

__INLINE void lcu_common_lcu_bt_start_en_unpack(uint8_t* lcu_bt_ext_strt_en, uint8_t* lcu_bt_strt_ptrn_en)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_START_EN_ADDR);

	*lcu_bt_ext_strt_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*lcu_bt_strt_ptrn_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_bt_start_en_lcu_bt_ext_strt_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_START_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void lcu_common_lcu_bt_start_en_lcu_bt_ext_strt_en_setf(uint8_t lcubtextstrten)
{
	ASSERT_ERR((((uint32_t)lcubtextstrten << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_START_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_BT_START_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)lcubtextstrten <<1));
}
__INLINE uint8_t lcu_common_lcu_bt_start_en_lcu_bt_strt_ptrn_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_START_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void lcu_common_lcu_bt_start_en_lcu_bt_strt_ptrn_en_setf(uint8_t lcubtstrtptrnen)
{
	ASSERT_ERR((((uint32_t)lcubtstrtptrnen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_START_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_BT_START_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)lcubtstrtptrnen <<0));
}

/**
 * @brief LCU_BT_START_PTRN_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_START_PTRN         0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000090C)
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_OFFSET      0x0000090C
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_INDEX       0x00000243
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_start_ptrn_reg_0_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_START_PTRN_REG_0_ADDR);
}

__INLINE void lcu_common_lcu_bt_start_ptrn_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_START_PTRN_REG_0_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_LCU_BT_START_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_LCU_BT_START_PTRN_LSB    0
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_LCU_BT_START_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_LCU_BT_START_PTRN_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_start_ptrn_reg_0_lcu_bt_start_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_START_PTRN_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_start_ptrn_reg_0_lcu_bt_start_ptrn_setf(uint32_t lcubtstartptrn)
{
	ASSERT_ERR((((uint32_t)lcubtstartptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_START_PTRN_REG_0_ADDR, (uint32_t)lcubtstartptrn << 0);
}

/**
 * @brief LCU_BT_START_PTRN_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_START_PTRN         0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000910)
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_OFFSET      0x00000910
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_INDEX       0x00000244
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_start_ptrn_reg_1_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_START_PTRN_REG_1_ADDR);
}

__INLINE void lcu_common_lcu_bt_start_ptrn_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_START_PTRN_REG_1_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_LCU_BT_START_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_LCU_BT_START_PTRN_LSB    0
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_LCU_BT_START_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_LCU_BT_START_PTRN_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_start_ptrn_reg_1_lcu_bt_start_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_START_PTRN_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_start_ptrn_reg_1_lcu_bt_start_ptrn_setf(uint32_t lcubtstartptrn)
{
	ASSERT_ERR((((uint32_t)lcubtstartptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_START_PTRN_REG_1_ADDR, (uint32_t)lcubtstartptrn << 0);
}

/**
 * @brief LCU_BT_START_PTRN_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:00 LCU_BT_START_PTRN         0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000914)
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_OFFSET      0x00000914
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_INDEX       0x00000245
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_start_ptrn_reg_2_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_START_PTRN_REG_2_ADDR);
}

__INLINE void lcu_common_lcu_bt_start_ptrn_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_START_PTRN_REG_2_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_LCU_BT_START_PTRN_MASK    ((uint32_t)0x03FFFFFF)
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_LCU_BT_START_PTRN_LSB    0
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_LCU_BT_START_PTRN_WIDTH    ((uint32_t)0x0000001A)

#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_LCU_BT_START_PTRN_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_start_ptrn_reg_2_lcu_bt_start_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_START_PTRN_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_start_ptrn_reg_2_lcu_bt_start_ptrn_setf(uint32_t lcubtstartptrn)
{
	ASSERT_ERR((((uint32_t)lcubtstartptrn << 0) & ~((uint32_t)0x03FFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_START_PTRN_REG_2_ADDR, (uint32_t)lcubtstartptrn << 0);
}

/**
 * @brief LCU_BT_START_PTRN_MASK_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_START_PTRN_MASK    0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000918)
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_OFFSET      0x00000918
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_INDEX       0x00000246
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_start_ptrn_mask_reg_0_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_ADDR);
}

__INLINE void lcu_common_lcu_bt_start_ptrn_mask_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_LCU_BT_START_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_LCU_BT_START_PTRN_MASK_LSB    0
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_LCU_BT_START_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_LCU_BT_START_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_start_ptrn_mask_reg_0_lcu_bt_start_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_start_ptrn_mask_reg_0_lcu_bt_start_ptrn_mask_setf(uint32_t lcubtstartptrnmask)
{
	ASSERT_ERR((((uint32_t)lcubtstartptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_ADDR, (uint32_t)lcubtstartptrnmask << 0);
}

/**
 * @brief LCU_BT_START_PTRN_MASK_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_START_PTRN_MASK    0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000091C)
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_OFFSET      0x0000091C
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_INDEX       0x00000247
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_start_ptrn_mask_reg_1_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_ADDR);
}

__INLINE void lcu_common_lcu_bt_start_ptrn_mask_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_LCU_BT_START_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_LCU_BT_START_PTRN_MASK_LSB    0
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_LCU_BT_START_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_LCU_BT_START_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_start_ptrn_mask_reg_1_lcu_bt_start_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_start_ptrn_mask_reg_1_lcu_bt_start_ptrn_mask_setf(uint32_t lcubtstartptrnmask)
{
	ASSERT_ERR((((uint32_t)lcubtstartptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_ADDR, (uint32_t)lcubtstartptrnmask << 0);
}

/**
 * @brief LCU_BT_START_PTRN_MASK_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:00 LCU_BT_START_PTRN_MASK    0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000920)
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_OFFSET      0x00000920
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_INDEX       0x00000248
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_start_ptrn_mask_reg_2_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_ADDR);
}

__INLINE void lcu_common_lcu_bt_start_ptrn_mask_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_LCU_BT_START_PTRN_MASK_MASK    ((uint32_t)0x03FFFFFF)
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_LCU_BT_START_PTRN_MASK_LSB    0
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_LCU_BT_START_PTRN_MASK_WIDTH    ((uint32_t)0x0000001A)

#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_LCU_BT_START_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_start_ptrn_mask_reg_2_lcu_bt_start_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_start_ptrn_mask_reg_2_lcu_bt_start_ptrn_mask_setf(uint32_t lcubtstartptrnmask)
{
	ASSERT_ERR((((uint32_t)lcubtstartptrnmask << 0) & ~((uint32_t)0x03FFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_ADDR, (uint32_t)lcubtstartptrnmask << 0);
}

/**
 * @brief LCU_BT_STOP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    LCU_BT_STOP               0              
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000924)
#define LCU_COMMON_LCU_BT_STOP_OFFSET      0x00000924
#define LCU_COMMON_LCU_BT_STOP_INDEX       0x00000249
#define LCU_COMMON_LCU_BT_STOP_RESET       0x00000000

__INLINE void lcu_common_lcu_bt_stop_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_STOP_LCU_BT_STOP_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_BT_STOP_LCU_BT_STOP_POS    0

#define LCU_COMMON_LCU_BT_STOP_LCU_BT_STOP_RST    0x0

__INLINE void lcu_common_lcu_bt_stop_lcu_bt_stop_setf(uint8_t lcubtstop)
{
	ASSERT_ERR((((uint32_t)lcubtstop << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_ADDR, (uint32_t)lcubtstop << 0);
}

/**
 * @brief LCU_BT_STOP_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    LCU_BT_EXT_STOP_EN        0              
 *    00    LCU_BT_STOP_PTRN_EN       0              
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000928)
#define LCU_COMMON_LCU_BT_STOP_EN_OFFSET      0x00000928
#define LCU_COMMON_LCU_BT_STOP_EN_INDEX       0x0000024A
#define LCU_COMMON_LCU_BT_STOP_EN_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_stop_en_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_STOP_EN_ADDR);
}

__INLINE void lcu_common_lcu_bt_stop_en_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_EN_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_STOP_EN_LCU_BT_EXT_STOP_EN_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_BT_STOP_EN_LCU_BT_EXT_STOP_EN_POS    1
#define LCU_COMMON_LCU_BT_STOP_EN_LCU_BT_STOP_PTRN_EN_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_BT_STOP_EN_LCU_BT_STOP_PTRN_EN_POS    0

#define LCU_COMMON_LCU_BT_STOP_EN_LCU_BT_EXT_STOP_EN_RST    0x0
#define LCU_COMMON_LCU_BT_STOP_EN_LCU_BT_STOP_PTRN_EN_RST    0x0

__INLINE void lcu_common_lcu_bt_stop_en_pack(uint8_t lcu_bt_ext_stop_en, uint8_t lcu_bt_stop_ptrn_en)
{
	ASSERT_ERR((((uint32_t)lcu_bt_ext_stop_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)lcu_bt_stop_ptrn_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_EN_ADDR,  ((uint32_t)lcu_bt_ext_stop_en << 1) |((uint32_t)lcu_bt_stop_ptrn_en << 0));
}

__INLINE void lcu_common_lcu_bt_stop_en_unpack(uint8_t* lcu_bt_ext_stop_en, uint8_t* lcu_bt_stop_ptrn_en)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_STOP_EN_ADDR);

	*lcu_bt_ext_stop_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*lcu_bt_stop_ptrn_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_bt_stop_en_lcu_bt_ext_stop_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_STOP_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void lcu_common_lcu_bt_stop_en_lcu_bt_ext_stop_en_setf(uint8_t lcubtextstopen)
{
	ASSERT_ERR((((uint32_t)lcubtextstopen << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_BT_STOP_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)lcubtextstopen <<1));
}
__INLINE uint8_t lcu_common_lcu_bt_stop_en_lcu_bt_stop_ptrn_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_STOP_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void lcu_common_lcu_bt_stop_en_lcu_bt_stop_ptrn_en_setf(uint8_t lcubtstopptrnen)
{
	ASSERT_ERR((((uint32_t)lcubtstopptrnen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_EN_ADDR, (REG_PL_RD(LCU_COMMON_LCU_BT_STOP_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)lcubtstopptrnen <<0));
}

/**
 * @brief LCU_BT_STOP_PTRN_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_STOP_PTRN          0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000092C)
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_OFFSET      0x0000092C
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_INDEX       0x0000024B
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_stop_ptrn_reg_0_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_ADDR);
}

__INLINE void lcu_common_lcu_bt_stop_ptrn_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_LCU_BT_STOP_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_LCU_BT_STOP_PTRN_LSB    0
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_LCU_BT_STOP_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_LCU_BT_STOP_PTRN_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_stop_ptrn_reg_0_lcu_bt_stop_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_stop_ptrn_reg_0_lcu_bt_stop_ptrn_setf(uint32_t lcubtstopptrn)
{
	ASSERT_ERR((((uint32_t)lcubtstopptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_ADDR, (uint32_t)lcubtstopptrn << 0);
}

/**
 * @brief LCU_BT_STOP_PTRN_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_STOP_PTRN          0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000930)
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_OFFSET      0x00000930
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_INDEX       0x0000024C
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_stop_ptrn_reg_1_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_ADDR);
}

__INLINE void lcu_common_lcu_bt_stop_ptrn_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_LCU_BT_STOP_PTRN_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_LCU_BT_STOP_PTRN_LSB    0
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_LCU_BT_STOP_PTRN_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_LCU_BT_STOP_PTRN_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_stop_ptrn_reg_1_lcu_bt_stop_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_stop_ptrn_reg_1_lcu_bt_stop_ptrn_setf(uint32_t lcubtstopptrn)
{
	ASSERT_ERR((((uint32_t)lcubtstopptrn << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_ADDR, (uint32_t)lcubtstopptrn << 0);
}

/**
 * @brief LCU_BT_STOP_PTRN_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:00 LCU_BT_STOP_PTRN          0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000934)
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_OFFSET      0x00000934
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_INDEX       0x0000024D
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_stop_ptrn_reg_2_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_ADDR);
}

__INLINE void lcu_common_lcu_bt_stop_ptrn_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_LCU_BT_STOP_PTRN_MASK    ((uint32_t)0x03FFFFFF)
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_LCU_BT_STOP_PTRN_LSB    0
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_LCU_BT_STOP_PTRN_WIDTH    ((uint32_t)0x0000001A)

#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_LCU_BT_STOP_PTRN_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_stop_ptrn_reg_2_lcu_bt_stop_ptrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_stop_ptrn_reg_2_lcu_bt_stop_ptrn_setf(uint32_t lcubtstopptrn)
{
	ASSERT_ERR((((uint32_t)lcubtstopptrn << 0) & ~((uint32_t)0x03FFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_ADDR, (uint32_t)lcubtstopptrn << 0);
}

/**
 * @brief LCU_BT_STOP_PTRN_MASK_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_STOP_PTRN_MASK     0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000938)
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_OFFSET      0x00000938
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_INDEX       0x0000024E
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_stop_ptrn_mask_reg_0_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_ADDR);
}

__INLINE void lcu_common_lcu_bt_stop_ptrn_mask_reg_0_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_LCU_BT_STOP_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_LCU_BT_STOP_PTRN_MASK_LSB    0
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_LCU_BT_STOP_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_LCU_BT_STOP_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_stop_ptrn_mask_reg_0_lcu_bt_stop_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_stop_ptrn_mask_reg_0_lcu_bt_stop_ptrn_mask_setf(uint32_t lcubtstopptrnmask)
{
	ASSERT_ERR((((uint32_t)lcubtstopptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_ADDR, (uint32_t)lcubtstopptrnmask << 0);
}

/**
 * @brief LCU_BT_STOP_PTRN_MASK_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_STOP_PTRN_MASK     0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000093C)
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_OFFSET      0x0000093C
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_INDEX       0x0000024F
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_stop_ptrn_mask_reg_1_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_ADDR);
}

__INLINE void lcu_common_lcu_bt_stop_ptrn_mask_reg_1_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_LCU_BT_STOP_PTRN_MASK_MASK    ((uint32_t)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_LCU_BT_STOP_PTRN_MASK_LSB    0
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_LCU_BT_STOP_PTRN_MASK_WIDTH    ((uint32_t)0x00000020)

#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_LCU_BT_STOP_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_stop_ptrn_mask_reg_1_lcu_bt_stop_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_stop_ptrn_mask_reg_1_lcu_bt_stop_ptrn_mask_setf(uint32_t lcubtstopptrnmask)
{
	ASSERT_ERR((((uint32_t)lcubtstopptrnmask << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_ADDR, (uint32_t)lcubtstopptrnmask << 0);
}

/**
 * @brief LCU_BT_STOP_PTRN_MASK_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:00 LCU_BT_STOP_PTRN_MASK     0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000940)
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_OFFSET      0x00000940
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_INDEX       0x00000250
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_stop_ptrn_mask_reg_2_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_ADDR);
}

__INLINE void lcu_common_lcu_bt_stop_ptrn_mask_reg_2_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_LCU_BT_STOP_PTRN_MASK_MASK    ((uint32_t)0x03FFFFFF)
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_LCU_BT_STOP_PTRN_MASK_LSB    0
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_LCU_BT_STOP_PTRN_MASK_WIDTH    ((uint32_t)0x0000001A)

#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_LCU_BT_STOP_PTRN_MASK_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_stop_ptrn_mask_reg_2_lcu_bt_stop_ptrn_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_stop_ptrn_mask_reg_2_lcu_bt_stop_ptrn_mask_setf(uint32_t lcubtstopptrnmask)
{
	ASSERT_ERR((((uint32_t)lcubtstopptrnmask << 0) & ~((uint32_t)0x03FFFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_ADDR, (uint32_t)lcubtstopptrnmask << 0);
}

/**
 * @brief LCU_BT_CH_VALID register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 LCU_BT_CH_VALID           0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_CH_VALID_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000944)
#define LCU_COMMON_LCU_BT_CH_VALID_OFFSET      0x00000944
#define LCU_COMMON_LCU_BT_CH_VALID_INDEX       0x00000251
#define LCU_COMMON_LCU_BT_CH_VALID_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_ch_valid_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_CH_VALID_ADDR);
}

__INLINE void lcu_common_lcu_bt_ch_valid_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_CH_VALID_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_CH_VALID_LCU_BT_CH_VALID_MASK    ((uint32_t)0x000FFFFF)
#define LCU_COMMON_LCU_BT_CH_VALID_LCU_BT_CH_VALID_LSB    0
#define LCU_COMMON_LCU_BT_CH_VALID_LCU_BT_CH_VALID_WIDTH    ((uint32_t)0x00000014)

#define LCU_COMMON_LCU_BT_CH_VALID_LCU_BT_CH_VALID_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_ch_valid_lcu_bt_ch_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_CH_VALID_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_ch_valid_lcu_bt_ch_valid_setf(uint32_t lcubtchvalid)
{
	ASSERT_ERR((((uint32_t)lcubtchvalid << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_CH_VALID_ADDR, (uint32_t)lcubtchvalid << 0);
}

/**
 * @brief LCU_BT_CTPREV_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 LCU_BT_CTPREV_EN          0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_CTPREV_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000948)
#define LCU_COMMON_LCU_BT_CTPREV_EN_OFFSET      0x00000948
#define LCU_COMMON_LCU_BT_CTPREV_EN_INDEX       0x00000252
#define LCU_COMMON_LCU_BT_CTPREV_EN_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_ctprev_en_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_CTPREV_EN_ADDR);
}

__INLINE void lcu_common_lcu_bt_ctprev_en_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_CTPREV_EN_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_CTPREV_EN_LCU_BT_CTPREV_EN_MASK    ((uint32_t)0x000FFFFF)
#define LCU_COMMON_LCU_BT_CTPREV_EN_LCU_BT_CTPREV_EN_LSB    0
#define LCU_COMMON_LCU_BT_CTPREV_EN_LCU_BT_CTPREV_EN_WIDTH    ((uint32_t)0x00000014)

#define LCU_COMMON_LCU_BT_CTPREV_EN_LCU_BT_CTPREV_EN_RST    0x0

__INLINE uint32_t lcu_common_lcu_bt_ctprev_en_lcu_bt_ctprev_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_CTPREV_EN_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void lcu_common_lcu_bt_ctprev_en_lcu_bt_ctprev_en_setf(uint32_t lcubtctpreven)
{
	ASSERT_ERR((((uint32_t)lcubtctpreven << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_CTPREV_EN_ADDR, (uint32_t)lcubtctpreven << 0);
}

/**
 * @brief LCU_BT_PTRN_MATCH_SEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    STOP_PTRN_MATCH_SEL       0              
 *    00    STRT_PTRN_MATCH_SEL       0              
 * </pre>
 */
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x0000094C)
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_OFFSET      0x0000094C
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_INDEX       0x00000253
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_ptrn_match_sel_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR);
}

__INLINE void lcu_common_lcu_bt_ptrn_match_sel_set(uint32_t value)
{
	REG_PL_WR(LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR, value);
}

// field definitions
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_STOP_PTRN_MATCH_SEL_BIT    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_STOP_PTRN_MATCH_SEL_POS    1
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_STRT_PTRN_MATCH_SEL_BIT    ((uint32_t)0x00000001)
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_STRT_PTRN_MATCH_SEL_POS    0

#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_STOP_PTRN_MATCH_SEL_RST    0x0
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_STRT_PTRN_MATCH_SEL_RST    0x0

__INLINE void lcu_common_lcu_bt_ptrn_match_sel_pack(uint8_t stop_ptrn_match_sel, uint8_t strt_ptrn_match_sel)
{
	ASSERT_ERR((((uint32_t)stop_ptrn_match_sel << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)strt_ptrn_match_sel << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR,  ((uint32_t)stop_ptrn_match_sel << 1) |((uint32_t)strt_ptrn_match_sel << 0));
}

__INLINE void lcu_common_lcu_bt_ptrn_match_sel_unpack(uint8_t* stop_ptrn_match_sel, uint8_t* strt_ptrn_match_sel)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR);

	*stop_ptrn_match_sel = (localVal & ((uint32_t)0x00000002)) >>  1;
	*strt_ptrn_match_sel = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_bt_ptrn_match_sel_stop_ptrn_match_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void lcu_common_lcu_bt_ptrn_match_sel_stop_ptrn_match_sel_setf(uint8_t stopptrnmatchsel)
{
	ASSERT_ERR((((uint32_t)stopptrnmatchsel << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR, (REG_PL_RD(LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)stopptrnmatchsel <<1));
}
__INLINE uint8_t lcu_common_lcu_bt_ptrn_match_sel_strt_ptrn_match_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void lcu_common_lcu_bt_ptrn_match_sel_strt_ptrn_match_sel_setf(uint8_t strtptrnmatchsel)
{
	ASSERT_ERR((((uint32_t)strtptrnmatchsel << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR, (REG_PL_RD(LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)strtptrnmatchsel <<0));
}

/**
 * @brief LCU_BT_TRIG_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:14 EXT_STOP_TRIG_STAT        0x0
 *    09:08 STOP_PTRN_TRIG_STAT       0x0
 *    05:04 EXT_STRT_TRIG_STAT        0x0
 *    01:00 STRT_PTRN_TRIG_STAT       0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR        (REG_LCU_COMMON_BASE_ADDR+0x00000950)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_OFFSET      0x00000950
#define LCU_COMMON_LCU_BT_TRIG_STATUS_INDEX       0x00000254
#define LCU_COMMON_LCU_BT_TRIG_STATUS_RESET       0x00000000

__INLINE uint32_t  lcu_common_lcu_bt_trig_status_get(void)
{
	return REG_PL_RD(LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR);
}

// field definitions
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STOP_TRIG_STAT_MASK    ((uint32_t)0x0000C000)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STOP_TRIG_STAT_LSB    14
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STOP_TRIG_STAT_WIDTH    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STOP_PTRN_TRIG_STAT_MASK    ((uint32_t)0x00000300)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STOP_PTRN_TRIG_STAT_LSB    8
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STOP_PTRN_TRIG_STAT_WIDTH    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STRT_TRIG_STAT_MASK    ((uint32_t)0x00000030)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STRT_TRIG_STAT_LSB    4
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STRT_TRIG_STAT_WIDTH    ((uint32_t)0x00000002)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STRT_PTRN_TRIG_STAT_MASK    ((uint32_t)0x00000003)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STRT_PTRN_TRIG_STAT_LSB    0
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STRT_PTRN_TRIG_STAT_WIDTH    ((uint32_t)0x00000002)

#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STOP_TRIG_STAT_RST    0x0
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STOP_PTRN_TRIG_STAT_RST    0x0
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STRT_TRIG_STAT_RST    0x0
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STRT_PTRN_TRIG_STAT_RST    0x0

__INLINE void lcu_common_lcu_bt_trig_status_unpack(uint8_t* ext_stop_trig_stat, uint8_t* stop_ptrn_trig_stat, uint8_t* ext_strt_trig_stat, uint8_t* strt_ptrn_trig_stat)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR);

	*ext_stop_trig_stat = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*stop_ptrn_trig_stat = (localVal & ((uint32_t)0x00000300)) >>  8;
	*ext_strt_trig_stat = (localVal & ((uint32_t)0x00000030)) >>  4;
	*strt_ptrn_trig_stat = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t lcu_common_lcu_bt_trig_status_ext_stop_trig_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE uint8_t lcu_common_lcu_bt_trig_status_stop_ptrn_trig_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE uint8_t lcu_common_lcu_bt_trig_status_ext_strt_trig_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE uint8_t lcu_common_lcu_bt_trig_status_strt_ptrn_trig_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}


#undef DBG_FILEID
#endif //_REG_LCU_COMMON_H_
