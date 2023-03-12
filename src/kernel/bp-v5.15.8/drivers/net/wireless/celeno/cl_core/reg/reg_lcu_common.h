/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef REG_LCU_COMMON_H
#define REG_LCU_COMMON_H

#include "reg_access.h"
#include "chip.h"

#define REG_LCU_COMMON_BASE_ADDR 0x007CF000

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
#define LCU_COMMON_VCI_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000000)
#define LCU_COMMON_VCI_OFFSET      0x00000000
#define LCU_COMMON_VCI_INDEX       0x00000000
#define LCU_COMMON_VCI_RESET       0x00000000

static inline u32 lcu_common_vci_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_VCI_ADDR);
}

static inline void lcu_common_vci_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_VCI_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_VCI_CH_5_VCI_MASK    ((u32)0x00300000)
#define LCU_COMMON_VCI_CH_5_VCI_LSB    20
#define LCU_COMMON_VCI_CH_5_VCI_WIDTH    ((u32)0x00000002)
#define LCU_COMMON_VCI_CH_4_VCI_MASK    ((u32)0x00030000)
#define LCU_COMMON_VCI_CH_4_VCI_LSB    16
#define LCU_COMMON_VCI_CH_4_VCI_WIDTH    ((u32)0x00000002)
#define LCU_COMMON_VCI_CH_3_VCI_MASK    ((u32)0x00003000)
#define LCU_COMMON_VCI_CH_3_VCI_LSB    12
#define LCU_COMMON_VCI_CH_3_VCI_WIDTH    ((u32)0x00000002)
#define LCU_COMMON_VCI_CH_2_VCI_MASK    ((u32)0x00000300)
#define LCU_COMMON_VCI_CH_2_VCI_LSB    8
#define LCU_COMMON_VCI_CH_2_VCI_WIDTH    ((u32)0x00000002)
#define LCU_COMMON_VCI_CH_1_VCI_MASK    ((u32)0x00000030)
#define LCU_COMMON_VCI_CH_1_VCI_LSB    4
#define LCU_COMMON_VCI_CH_1_VCI_WIDTH    ((u32)0x00000002)
#define LCU_COMMON_VCI_CH_0_VCI_MASK    ((u32)0x00000003)
#define LCU_COMMON_VCI_CH_0_VCI_LSB    0
#define LCU_COMMON_VCI_CH_0_VCI_WIDTH    ((u32)0x00000002)

#define LCU_COMMON_VCI_CH_5_VCI_RST    0x0
#define LCU_COMMON_VCI_CH_4_VCI_RST    0x0
#define LCU_COMMON_VCI_CH_3_VCI_RST    0x0
#define LCU_COMMON_VCI_CH_2_VCI_RST    0x0
#define LCU_COMMON_VCI_CH_1_VCI_RST    0x0
#define LCU_COMMON_VCI_CH_0_VCI_RST    0x0

static inline void lcu_common_vci_pack(struct cl_chip *chip, u8 ch5_vci, u8 ch4_vci, u8 ch3_vci, u8 ch2_vci, u8 ch1_vci, u8 ch0_vci)
{
	ASSERT_ERR_CHIP((((u32)ch5_vci << 20) & ~((u32)0x00300000)) == 0);
	ASSERT_ERR_CHIP((((u32)ch4_vci << 16) & ~((u32)0x00030000)) == 0);
	ASSERT_ERR_CHIP((((u32)ch3_vci << 12) & ~((u32)0x00003000)) == 0);
	ASSERT_ERR_CHIP((((u32)ch2_vci << 8) & ~((u32)0x00000300)) == 0);
	ASSERT_ERR_CHIP((((u32)ch1_vci << 4) & ~((u32)0x00000030)) == 0);
	ASSERT_ERR_CHIP((((u32)ch0_vci << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, LCU_COMMON_VCI_ADDR, ((u32)ch5_vci << 20) | ((u32)ch4_vci << 16) | ((u32)ch3_vci << 12) | ((u32)ch2_vci << 8) | ((u32)ch1_vci << 4) | ((u32)ch0_vci << 0));
}

static inline void lcu_common_vci_unpack(struct cl_chip *chip, u8 *ch5_vci, u8 *ch4_vci, u8 *ch3_vci, u8 *ch2_vci, u8 *ch1_vci, u8 *ch0_vci)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_VCI_ADDR);

	*ch5_vci = (local_val & ((u32)0x00300000)) >> 20;
	*ch4_vci = (local_val & ((u32)0x00030000)) >> 16;
	*ch3_vci = (local_val & ((u32)0x00003000)) >> 12;
	*ch2_vci = (local_val & ((u32)0x00000300)) >> 8;
	*ch1_vci = (local_val & ((u32)0x00000030)) >> 4;
	*ch0_vci = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u8 lcu_common_vci_ch_5_vci_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_VCI_ADDR);

	return (u8)((local_val & ((u32)0x00300000)) >> 20);
}

static inline void lcu_common_vci_ch_5_vci_setf(struct cl_chip *chip, u8 ch5vci)
{
	ASSERT_ERR_CHIP((((u32)ch5vci << 20) & ~((u32)0x00300000)) == 0);
	cl_reg_write(chip, LCU_COMMON_VCI_ADDR, (cl_reg_read(chip, LCU_COMMON_VCI_ADDR) & ~((u32)0x00300000)) | ((u32)ch5vci << 20));
}

static inline u8 lcu_common_vci_ch_4_vci_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_VCI_ADDR);

	return (u8)((local_val & ((u32)0x00030000)) >> 16);
}

static inline void lcu_common_vci_ch_4_vci_setf(struct cl_chip *chip, u8 ch4vci)
{
	ASSERT_ERR_CHIP((((u32)ch4vci << 16) & ~((u32)0x00030000)) == 0);
	cl_reg_write(chip, LCU_COMMON_VCI_ADDR, (cl_reg_read(chip, LCU_COMMON_VCI_ADDR) & ~((u32)0x00030000)) | ((u32)ch4vci << 16));
}

static inline u8 lcu_common_vci_ch_3_vci_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_VCI_ADDR);

	return (u8)((local_val & ((u32)0x00003000)) >> 12);
}

static inline void lcu_common_vci_ch_3_vci_setf(struct cl_chip *chip, u8 ch3vci)
{
	ASSERT_ERR_CHIP((((u32)ch3vci << 12) & ~((u32)0x00003000)) == 0);
	cl_reg_write(chip, LCU_COMMON_VCI_ADDR, (cl_reg_read(chip, LCU_COMMON_VCI_ADDR) & ~((u32)0x00003000)) | ((u32)ch3vci << 12));
}

static inline u8 lcu_common_vci_ch_2_vci_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_VCI_ADDR);

	return (u8)((local_val & ((u32)0x00000300)) >> 8);
}

static inline void lcu_common_vci_ch_2_vci_setf(struct cl_chip *chip, u8 ch2vci)
{
	ASSERT_ERR_CHIP((((u32)ch2vci << 8) & ~((u32)0x00000300)) == 0);
	cl_reg_write(chip, LCU_COMMON_VCI_ADDR, (cl_reg_read(chip, LCU_COMMON_VCI_ADDR) & ~((u32)0x00000300)) | ((u32)ch2vci << 8));
}

static inline u8 lcu_common_vci_ch_1_vci_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_VCI_ADDR);

	return (u8)((local_val & ((u32)0x00000030)) >> 4);
}

static inline void lcu_common_vci_ch_1_vci_setf(struct cl_chip *chip, u8 ch1vci)
{
	ASSERT_ERR_CHIP((((u32)ch1vci << 4) & ~((u32)0x00000030)) == 0);
	cl_reg_write(chip, LCU_COMMON_VCI_ADDR, (cl_reg_read(chip, LCU_COMMON_VCI_ADDR) & ~((u32)0x00000030)) | ((u32)ch1vci << 4));
}

static inline u8 lcu_common_vci_ch_0_vci_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_VCI_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void lcu_common_vci_ch_0_vci_setf(struct cl_chip *chip, u8 ch0vci)
{
	ASSERT_ERR_CHIP((((u32)ch0vci << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, LCU_COMMON_VCI_ADDR, (cl_reg_read(chip, LCU_COMMON_VCI_ADDR) & ~((u32)0x00000003)) | ((u32)ch0vci << 0));
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
#define LCU_COMMON_REC_FIRST_SAMP_TS_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000004)
#define LCU_COMMON_REC_FIRST_SAMP_TS_OFFSET      0x00000004
#define LCU_COMMON_REC_FIRST_SAMP_TS_INDEX       0x00000001
#define LCU_COMMON_REC_FIRST_SAMP_TS_RESET       0x00000000

static inline u32 lcu_common_rec_first_samp_ts_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_REC_FIRST_SAMP_TS_ADDR);
}

/* field definitions */
#define LCU_COMMON_REC_FIRST_SAMP_TS_REC_FIRST_SAMP_TS_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_REC_FIRST_SAMP_TS_REC_FIRST_SAMP_TS_LSB    0
#define LCU_COMMON_REC_FIRST_SAMP_TS_REC_FIRST_SAMP_TS_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_REC_FIRST_SAMP_TS_REC_FIRST_SAMP_TS_RST    0x0

static inline u32 lcu_common_rec_first_samp_ts_rec_first_samp_ts_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_REC_FIRST_SAMP_TS_ADDR);

	return (u32)(local_val >> 0);
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
#define LCU_COMMON_REC_START_TS_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000008)
#define LCU_COMMON_REC_START_TS_OFFSET      0x00000008
#define LCU_COMMON_REC_START_TS_INDEX       0x00000002
#define LCU_COMMON_REC_START_TS_RESET       0x00000000

static inline u32 lcu_common_rec_start_ts_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_REC_START_TS_ADDR);
}

/* field definitions */
#define LCU_COMMON_REC_START_TS_REC_START_TS_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_REC_START_TS_REC_START_TS_LSB    0
#define LCU_COMMON_REC_START_TS_REC_START_TS_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_REC_START_TS_REC_START_TS_RST    0x0

static inline u32 lcu_common_rec_start_ts_rec_start_ts_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_REC_START_TS_ADDR);

	return (u32)(local_val >> 0);
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
#define LCU_COMMON_REC_END_TS_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000000C)
#define LCU_COMMON_REC_END_TS_OFFSET      0x0000000C
#define LCU_COMMON_REC_END_TS_INDEX       0x00000003
#define LCU_COMMON_REC_END_TS_RESET       0x00000000

static inline u32 lcu_common_rec_end_ts_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_REC_END_TS_ADDR);
}

/* field definitions */
#define LCU_COMMON_REC_END_TS_REC_END_TS_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_REC_END_TS_REC_END_TS_LSB    0
#define LCU_COMMON_REC_END_TS_REC_END_TS_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_REC_END_TS_REC_END_TS_RST    0x0

static inline u32 lcu_common_rec_end_ts_rec_end_ts_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_REC_END_TS_ADDR);

	return (u32)(local_val >> 0);
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
#define LCU_COMMON_REC_STOP_TS_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000010)
#define LCU_COMMON_REC_STOP_TS_OFFSET      0x00000010
#define LCU_COMMON_REC_STOP_TS_INDEX       0x00000004
#define LCU_COMMON_REC_STOP_TS_RESET       0x00000000

static inline u32 lcu_common_rec_stop_ts_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_REC_STOP_TS_ADDR);
}

/* field definitions */
#define LCU_COMMON_REC_STOP_TS_REC_STOP_TS_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_REC_STOP_TS_REC_STOP_TS_LSB    0
#define LCU_COMMON_REC_STOP_TS_REC_STOP_TS_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_REC_STOP_TS_REC_STOP_TS_RST    0x0

static inline u32 lcu_common_rec_stop_ts_rec_stop_ts_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_REC_STOP_TS_ADDR);

	return (u32)(local_val >> 0);
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
#define LCU_COMMON_BUF_START_ADDR_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000014)
#define LCU_COMMON_BUF_START_ADDR_OFFSET      0x00000014
#define LCU_COMMON_BUF_START_ADDR_INDEX       0x00000005
#define LCU_COMMON_BUF_START_ADDR_RESET       0x00000000

static inline u32 lcu_common_buf_start_addr_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_BUF_START_ADDR_ADDR);
}

static inline void lcu_common_buf_start_addr_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_BUF_START_ADDR_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_BUF_START_ADDR_BUF_START_ADDR_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_BUF_START_ADDR_BUF_START_ADDR_LSB    0
#define LCU_COMMON_BUF_START_ADDR_BUF_START_ADDR_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_BUF_START_ADDR_BUF_START_ADDR_RST    0x0

static inline u32 lcu_common_buf_start_addr_buf_start_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_BUF_START_ADDR_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_buf_start_addr_buf_start_addr_setf(struct cl_chip *chip, u32 bufstartaddr)
{
	ASSERT_ERR_CHIP((((u32)bufstartaddr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_BUF_START_ADDR_ADDR, (u32)bufstartaddr << 0);
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
#define LCU_COMMON_BUF_END_ADDR_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000018)
#define LCU_COMMON_BUF_END_ADDR_OFFSET      0x00000018
#define LCU_COMMON_BUF_END_ADDR_INDEX       0x00000006
#define LCU_COMMON_BUF_END_ADDR_RESET       0x00000000

static inline u32 lcu_common_buf_end_addr_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_BUF_END_ADDR_ADDR);
}

static inline void lcu_common_buf_end_addr_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_BUF_END_ADDR_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_BUF_END_ADDR_BUF_END_ADDR_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_BUF_END_ADDR_BUF_END_ADDR_LSB    0
#define LCU_COMMON_BUF_END_ADDR_BUF_END_ADDR_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_BUF_END_ADDR_BUF_END_ADDR_RST    0x0

static inline u32 lcu_common_buf_end_addr_buf_end_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_BUF_END_ADDR_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_buf_end_addr_buf_end_addr_setf(struct cl_chip *chip, u32 bufendaddr)
{
	ASSERT_ERR_CHIP((((u32)bufendaddr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_BUF_END_ADDR_ADDR, (u32)bufendaddr << 0);
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
#define LCU_COMMON_CAPTURE_MODE_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000001C)
#define LCU_COMMON_CAPTURE_MODE_OFFSET      0x0000001C
#define LCU_COMMON_CAPTURE_MODE_INDEX       0x00000007
#define LCU_COMMON_CAPTURE_MODE_RESET       0x00000000

static inline u32 lcu_common_capture_mode_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_CAPTURE_MODE_ADDR);
}

static inline void lcu_common_capture_mode_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_CAPTURE_MODE_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_CAPTURE_MODE_CAPTURE_MODE_BIT    ((u32)0x00000001)
#define LCU_COMMON_CAPTURE_MODE_CAPTURE_MODE_POS    0

#define LCU_COMMON_CAPTURE_MODE_CAPTURE_MODE_RST    0x0

static inline u8 lcu_common_capture_mode_capture_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CAPTURE_MODE_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_common_capture_mode_capture_mode_setf(struct cl_chip *chip, u8 capturemode)
{
	ASSERT_ERR_CHIP((((u32)capturemode << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CAPTURE_MODE_ADDR, (u32)capturemode << 0);
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
#define LCU_COMMON_REC_CMD_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000020)
#define LCU_COMMON_REC_CMD_OFFSET      0x00000020
#define LCU_COMMON_REC_CMD_INDEX       0x00000008
#define LCU_COMMON_REC_CMD_RESET       0x00000000

static inline void lcu_common_rec_cmd_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_REC_CMD_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_REC_CMD_STOP_REC_BIT    ((u32)0x00000004)
#define LCU_COMMON_REC_CMD_STOP_REC_POS    2
#define LCU_COMMON_REC_CMD_START_REC_BIT    ((u32)0x00000002)
#define LCU_COMMON_REC_CMD_START_REC_POS    1
#define LCU_COMMON_REC_CMD_REC_ARM_BIT    ((u32)0x00000001)
#define LCU_COMMON_REC_CMD_REC_ARM_POS    0

#define LCU_COMMON_REC_CMD_STOP_REC_RST    0x0
#define LCU_COMMON_REC_CMD_START_REC_RST    0x0
#define LCU_COMMON_REC_CMD_REC_ARM_RST    0x0

static inline void lcu_common_rec_cmd_pack(struct cl_chip *chip, u8 stop_rec, u8 start_rec, u8 rec_arm)
{
	ASSERT_ERR_CHIP((((u32)stop_rec << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)start_rec << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)rec_arm << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_REC_CMD_ADDR, ((u32)stop_rec << 2) | ((u32)start_rec << 1) | ((u32)rec_arm << 0));
}

static inline void lcu_common_rec_cmd_stop_rec_setf(struct cl_chip *chip, u8 stoprec)
{
	ASSERT_ERR_CHIP((((u32)stoprec << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_COMMON_REC_CMD_ADDR, (cl_reg_read(chip, LCU_COMMON_REC_CMD_ADDR) & ~((u32)0x00000004)) | ((u32)stoprec << 2));
}

static inline void lcu_common_rec_cmd_start_rec_setf(struct cl_chip *chip, u8 startrec)
{
	ASSERT_ERR_CHIP((((u32)startrec << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_REC_CMD_ADDR, (cl_reg_read(chip, LCU_COMMON_REC_CMD_ADDR) & ~((u32)0x00000002)) | ((u32)startrec << 1));
}

static inline void lcu_common_rec_cmd_rec_arm_setf(struct cl_chip *chip, u8 recarm)
{
	ASSERT_ERR_CHIP((((u32)recarm << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_REC_CMD_ADDR, (cl_reg_read(chip, LCU_COMMON_REC_CMD_ADDR) & ~((u32)0x00000001)) | ((u32)recarm << 0));
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
#define LCU_COMMON_STOP_EXTRA_SAMPLES_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000024)
#define LCU_COMMON_STOP_EXTRA_SAMPLES_OFFSET      0x00000024
#define LCU_COMMON_STOP_EXTRA_SAMPLES_INDEX       0x00000009
#define LCU_COMMON_STOP_EXTRA_SAMPLES_RESET       0x00000000

static inline u32 lcu_common_stop_extra_samples_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_STOP_EXTRA_SAMPLES_ADDR);
}

static inline void lcu_common_stop_extra_samples_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_STOP_EXTRA_SAMPLES_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_STOP_EXTRA_SAMPLES_STOP_EXTRA_SAMPLES_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_STOP_EXTRA_SAMPLES_STOP_EXTRA_SAMPLES_LSB    0
#define LCU_COMMON_STOP_EXTRA_SAMPLES_STOP_EXTRA_SAMPLES_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_STOP_EXTRA_SAMPLES_STOP_EXTRA_SAMPLES_RST    0x0

static inline u32 lcu_common_stop_extra_samples_stop_extra_samples_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_STOP_EXTRA_SAMPLES_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_stop_extra_samples_stop_extra_samples_setf(struct cl_chip *chip, u32 stopextrasamples)
{
	ASSERT_ERR_CHIP((((u32)stopextrasamples << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_STOP_EXTRA_SAMPLES_ADDR, (u32)stopextrasamples << 0);
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
#define LCU_COMMON_STOP_EXTRA_CYCLES_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000028)
#define LCU_COMMON_STOP_EXTRA_CYCLES_OFFSET      0x00000028
#define LCU_COMMON_STOP_EXTRA_CYCLES_INDEX       0x0000000A
#define LCU_COMMON_STOP_EXTRA_CYCLES_RESET       0x00000000

static inline u32 lcu_common_stop_extra_cycles_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_STOP_EXTRA_CYCLES_ADDR);
}

static inline void lcu_common_stop_extra_cycles_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_STOP_EXTRA_CYCLES_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_STOP_EXTRA_CYCLES_STOP_EXTRA_CYCLES_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_STOP_EXTRA_CYCLES_STOP_EXTRA_CYCLES_LSB    0
#define LCU_COMMON_STOP_EXTRA_CYCLES_STOP_EXTRA_CYCLES_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_STOP_EXTRA_CYCLES_STOP_EXTRA_CYCLES_RST    0x0

static inline u32 lcu_common_stop_extra_cycles_stop_extra_cycles_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_STOP_EXTRA_CYCLES_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_stop_extra_cycles_stop_extra_cycles_setf(struct cl_chip *chip, u32 stopextracycles)
{
	ASSERT_ERR_CHIP((((u32)stopextracycles << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_STOP_EXTRA_CYCLES_ADDR, (u32)stopextracycles << 0);
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
#define LCU_COMMON_WRITE_ADDR_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000002C)
#define LCU_COMMON_WRITE_ADDR_OFFSET      0x0000002C
#define LCU_COMMON_WRITE_ADDR_INDEX       0x0000000B
#define LCU_COMMON_WRITE_ADDR_RESET       0x00000000

static inline u32 lcu_common_write_addr_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_WRITE_ADDR_ADDR);
}

/* field definitions */
#define LCU_COMMON_WRITE_ADDR_WRITE_ADDR_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_WRITE_ADDR_WRITE_ADDR_LSB    0
#define LCU_COMMON_WRITE_ADDR_WRITE_ADDR_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_WRITE_ADDR_WRITE_ADDR_RST    0x0

static inline u32 lcu_common_write_addr_write_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_WRITE_ADDR_ADDR);

	return (u32)(local_val >> 0);
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
#define LCU_COMMON_REC_STOP_ADDR_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000030)
#define LCU_COMMON_REC_STOP_ADDR_OFFSET      0x00000030
#define LCU_COMMON_REC_STOP_ADDR_INDEX       0x0000000C
#define LCU_COMMON_REC_STOP_ADDR_RESET       0x00000000

static inline u32 lcu_common_rec_stop_addr_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_REC_STOP_ADDR_ADDR);
}

/* field definitions */
#define LCU_COMMON_REC_STOP_ADDR_REC_STOP_ADDR_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_REC_STOP_ADDR_REC_STOP_ADDR_LSB    0
#define LCU_COMMON_REC_STOP_ADDR_REC_STOP_ADDR_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_REC_STOP_ADDR_REC_STOP_ADDR_RST    0x0

static inline u32 lcu_common_rec_stop_addr_rec_stop_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_REC_STOP_ADDR_ADDR);

	return (u32)(local_val >> 0);
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
#define LCU_COMMON_BLOCK_SIZE_EXPONENT_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000034)
#define LCU_COMMON_BLOCK_SIZE_EXPONENT_OFFSET      0x00000034
#define LCU_COMMON_BLOCK_SIZE_EXPONENT_INDEX       0x0000000D
#define LCU_COMMON_BLOCK_SIZE_EXPONENT_RESET       0x0000000C

static inline u32 lcu_common_block_size_exponent_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_BLOCK_SIZE_EXPONENT_ADDR);
}

static inline void lcu_common_block_size_exponent_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_BLOCK_SIZE_EXPONENT_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_BLOCK_SIZE_EXPONENT_BLOCK_SIZE_EXP_MASK    ((u32)0x000000FF)
#define LCU_COMMON_BLOCK_SIZE_EXPONENT_BLOCK_SIZE_EXP_LSB    0
#define LCU_COMMON_BLOCK_SIZE_EXPONENT_BLOCK_SIZE_EXP_WIDTH    ((u32)0x00000008)

#define LCU_COMMON_BLOCK_SIZE_EXPONENT_BLOCK_SIZE_EXP_RST    0xC

static inline u8 lcu_common_block_size_exponent_block_size_exp_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_BLOCK_SIZE_EXPONENT_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_common_block_size_exponent_block_size_exp_setf(struct cl_chip *chip, u8 blocksizeexp)
{
	ASSERT_ERR_CHIP((((u32)blocksizeexp << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, LCU_COMMON_BLOCK_SIZE_EXPONENT_ADDR, (u32)blocksizeexp << 0);
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
#define LCU_COMMON_BLOCK_WR_COUNTER_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000038)
#define LCU_COMMON_BLOCK_WR_COUNTER_OFFSET      0x00000038
#define LCU_COMMON_BLOCK_WR_COUNTER_INDEX       0x0000000E
#define LCU_COMMON_BLOCK_WR_COUNTER_RESET       0x00000000

static inline u32 lcu_common_block_wr_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_BLOCK_WR_COUNTER_ADDR);
}

/* field definitions */
#define LCU_COMMON_BLOCK_WR_COUNTER_BLOCK_COUNTER_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_BLOCK_WR_COUNTER_BLOCK_COUNTER_LSB    0
#define LCU_COMMON_BLOCK_WR_COUNTER_BLOCK_COUNTER_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_BLOCK_WR_COUNTER_BLOCK_COUNTER_RST    0x0

static inline u32 lcu_common_block_wr_counter_block_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_BLOCK_WR_COUNTER_ADDR);

	return (u32)(local_val >> 0);
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
#define LCU_COMMON_BLOCK_RD_COUNTER_INC_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000003C)
#define LCU_COMMON_BLOCK_RD_COUNTER_INC_OFFSET      0x0000003C
#define LCU_COMMON_BLOCK_RD_COUNTER_INC_INDEX       0x0000000F
#define LCU_COMMON_BLOCK_RD_COUNTER_INC_RESET       0x00000000

static inline void lcu_common_block_rd_counter_inc_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_BLOCK_RD_COUNTER_INC_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_BLOCK_RD_COUNTER_INC_BLOCK_RD_COUNTER_INC_MASK    ((u32)0x0000000F)
#define LCU_COMMON_BLOCK_RD_COUNTER_INC_BLOCK_RD_COUNTER_INC_LSB    0
#define LCU_COMMON_BLOCK_RD_COUNTER_INC_BLOCK_RD_COUNTER_INC_WIDTH    ((u32)0x00000004)

#define LCU_COMMON_BLOCK_RD_COUNTER_INC_BLOCK_RD_COUNTER_INC_RST    0x0

static inline void lcu_common_block_rd_counter_inc_block_rd_counter_inc_setf(struct cl_chip *chip, u8 blockrdcounterinc)
{
	ASSERT_ERR_CHIP((((u32)blockrdcounterinc << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, LCU_COMMON_BLOCK_RD_COUNTER_INC_ADDR, (u32)blockrdcounterinc << 0);
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
#define LCU_COMMON_BLOCK_RD_COUNTER_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000040)
#define LCU_COMMON_BLOCK_RD_COUNTER_OFFSET      0x00000040
#define LCU_COMMON_BLOCK_RD_COUNTER_INDEX       0x00000010
#define LCU_COMMON_BLOCK_RD_COUNTER_RESET       0x00000000

static inline u32 lcu_common_block_rd_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_BLOCK_RD_COUNTER_ADDR);
}

/* field definitions */
#define LCU_COMMON_BLOCK_RD_COUNTER_BLOCK_RD_COUNTER_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_BLOCK_RD_COUNTER_BLOCK_RD_COUNTER_LSB    0
#define LCU_COMMON_BLOCK_RD_COUNTER_BLOCK_RD_COUNTER_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_BLOCK_RD_COUNTER_BLOCK_RD_COUNTER_RST    0x0

static inline u32 lcu_common_block_rd_counter_block_rd_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_BLOCK_RD_COUNTER_ADDR);

	return (u32)(local_val >> 0);
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
#define LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000044)
#define LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_OFFSET      0x00000044
#define LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_INDEX       0x00000011
#define LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_RESET       0x00000000

static inline u32 lcu_common_block_counters_max_diff_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_ADDR);
}

/* field definitions */
#define LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_BLOCK_COUNTERS_MAX_DIFF_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_BLOCK_COUNTERS_MAX_DIFF_LSB    0
#define LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_BLOCK_COUNTERS_MAX_DIFF_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_BLOCK_COUNTERS_MAX_DIFF_RST    0x0

static inline u32 lcu_common_block_counters_max_diff_block_counters_max_diff_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_BLOCK_COUNTERS_MAX_DIFF_ADDR);

	return (u32)(local_val >> 0);
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
#define LCU_COMMON_SW_RST_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000048)
#define LCU_COMMON_SW_RST_OFFSET      0x00000048
#define LCU_COMMON_SW_RST_INDEX       0x00000012
#define LCU_COMMON_SW_RST_RESET       0x00000000

static inline void lcu_common_sw_rst_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_SW_RST_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_SW_RST_SW_RST_BIT    ((u32)0x00000001)
#define LCU_COMMON_SW_RST_SW_RST_POS    0

#define LCU_COMMON_SW_RST_SW_RST_RST    0x0

static inline void lcu_common_sw_rst_sw_rst_setf(struct cl_chip *chip, u8 swrst)
{
	ASSERT_ERR_CHIP((((u32)swrst << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_SW_RST_ADDR, (u32)swrst << 0);
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
#define LCU_COMMON_STATUS_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000004C)
#define LCU_COMMON_STATUS_OFFSET      0x0000004C
#define LCU_COMMON_STATUS_INDEX       0x00000013
#define LCU_COMMON_STATUS_RESET       0x0000FF00

static inline u32 lcu_common_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_STATUS_ADDR);
}

/* field definitions */
#define LCU_COMMON_STATUS_CH_PEND_IND_BIT    ((u32)0x00010000)
#define LCU_COMMON_STATUS_CH_PEND_IND_POS    16
#define LCU_COMMON_STATUS_STOP_INITIATOR_MASK    ((u32)0x0000F000)
#define LCU_COMMON_STATUS_STOP_INITIATOR_LSB    12
#define LCU_COMMON_STATUS_STOP_INITIATOR_WIDTH    ((u32)0x00000004)
#define LCU_COMMON_STATUS_START_INITIATOR_MASK    ((u32)0x00000F00)
#define LCU_COMMON_STATUS_START_INITIATOR_LSB    8
#define LCU_COMMON_STATUS_START_INITIATOR_WIDTH    ((u32)0x00000004)
#define LCU_COMMON_STATUS_CH_5_OVF_BIT    ((u32)0x00000080)
#define LCU_COMMON_STATUS_CH_5_OVF_POS    7
#define LCU_COMMON_STATUS_CH_4_OVF_BIT    ((u32)0x00000040)
#define LCU_COMMON_STATUS_CH_4_OVF_POS    6
#define LCU_COMMON_STATUS_CH_3_OVF_BIT    ((u32)0x00000020)
#define LCU_COMMON_STATUS_CH_3_OVF_POS    5
#define LCU_COMMON_STATUS_CH_2_OVF_BIT    ((u32)0x00000010)
#define LCU_COMMON_STATUS_CH_2_OVF_POS    4
#define LCU_COMMON_STATUS_STATUS_MASK    ((u32)0x0000000F)
#define LCU_COMMON_STATUS_STATUS_LSB    0
#define LCU_COMMON_STATUS_STATUS_WIDTH    ((u32)0x00000004)

#define LCU_COMMON_STATUS_CH_PEND_IND_RST    0x0
#define LCU_COMMON_STATUS_STOP_INITIATOR_RST    0xF
#define LCU_COMMON_STATUS_START_INITIATOR_RST    0xF
#define LCU_COMMON_STATUS_CH_5_OVF_RST    0x0
#define LCU_COMMON_STATUS_CH_4_OVF_RST    0x0
#define LCU_COMMON_STATUS_CH_3_OVF_RST    0x0
#define LCU_COMMON_STATUS_CH_2_OVF_RST    0x0
#define LCU_COMMON_STATUS_STATUS_RST    0x0

static inline void lcu_common_status_unpack(struct cl_chip *chip, u8 *ch_pend_ind, u8 *stop_initiator, u8 *start_initiator, u8 *ch5_ovf, u8 *ch4_ovf, u8 *ch3_ovf, u8 *ch2_ovf, u8 *status)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_STATUS_ADDR);

	*ch_pend_ind = (local_val & ((u32)0x00010000)) >> 16;
	*stop_initiator = (local_val & ((u32)0x0000F000)) >> 12;
	*start_initiator = (local_val & ((u32)0x00000F00)) >> 8;
	*ch5_ovf = (local_val & ((u32)0x00000080)) >> 7;
	*ch4_ovf = (local_val & ((u32)0x00000040)) >> 6;
	*ch3_ovf = (local_val & ((u32)0x00000020)) >> 5;
	*ch2_ovf = (local_val & ((u32)0x00000010)) >> 4;
	*status = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 lcu_common_status_ch_pend_ind_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline u8 lcu_common_status_stop_initiator_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x0000F000)) >> 12);
}

static inline u8 lcu_common_status_start_initiator_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000F00)) >> 8);
}

static inline u8 lcu_common_status_ch_5_ovf_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000080)) >> 7);
}

static inline u8 lcu_common_status_ch_4_ovf_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000040)) >> 6);
}

static inline u8 lcu_common_status_ch_3_ovf_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000020)) >> 5);
}

static inline u8 lcu_common_status_ch_2_ovf_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline u8 lcu_common_status_status_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
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
#define LCU_COMMON_INT_RAW_STAT_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000050)
#define LCU_COMMON_INT_RAW_STAT_OFFSET      0x00000050
#define LCU_COMMON_INT_RAW_STAT_INDEX       0x00000014
#define LCU_COMMON_INT_RAW_STAT_RESET       0x00000000

static inline u32 lcu_common_int_raw_stat_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_INT_RAW_STAT_ADDR);
}

/* field definitions */
#define LCU_COMMON_INT_RAW_STAT_ERROR_BIT    ((u32)0x00000004)
#define LCU_COMMON_INT_RAW_STAT_ERROR_POS    2
#define LCU_COMMON_INT_RAW_STAT_FINAL_SAMPLE_BIT    ((u32)0x00000002)
#define LCU_COMMON_INT_RAW_STAT_FINAL_SAMPLE_POS    1
#define LCU_COMMON_INT_RAW_STAT_BLOCK_FILL_BIT    ((u32)0x00000001)
#define LCU_COMMON_INT_RAW_STAT_BLOCK_FILL_POS    0

#define LCU_COMMON_INT_RAW_STAT_ERROR_RST    0x0
#define LCU_COMMON_INT_RAW_STAT_FINAL_SAMPLE_RST    0x0
#define LCU_COMMON_INT_RAW_STAT_BLOCK_FILL_RST    0x0

static inline void lcu_common_int_raw_stat_unpack(struct cl_chip *chip, u8 *error, u8 *final_sample, u8 *block_fill)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_INT_RAW_STAT_ADDR);

	*error = (local_val & ((u32)0x00000004)) >> 2;
	*final_sample = (local_val & ((u32)0x00000002)) >> 1;
	*block_fill = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_int_raw_stat_error_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_INT_RAW_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline u8 lcu_common_int_raw_stat_final_sample_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_INT_RAW_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline u8 lcu_common_int_raw_stat_block_fill_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_INT_RAW_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
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
#define LCU_COMMON_LMAC_INT_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000054)
#define LCU_COMMON_LMAC_INT_EN_OFFSET      0x00000054
#define LCU_COMMON_LMAC_INT_EN_INDEX       0x00000015
#define LCU_COMMON_LMAC_INT_EN_RESET       0x00000000

static inline u32 lcu_common_lmac_int_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LMAC_INT_EN_ADDR);
}

static inline void lcu_common_lmac_int_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LMAC_INT_EN_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LMAC_INT_EN_ERROR_INT_EN_BIT    ((u32)0x00000004)
#define LCU_COMMON_LMAC_INT_EN_ERROR_INT_EN_POS    2
#define LCU_COMMON_LMAC_INT_EN_FINAL_SAMPLE_INT_EN_BIT    ((u32)0x00000002)
#define LCU_COMMON_LMAC_INT_EN_FINAL_SAMPLE_INT_EN_POS    1
#define LCU_COMMON_LMAC_INT_EN_BLOCK_FILL_INT_EN_BIT    ((u32)0x00000001)
#define LCU_COMMON_LMAC_INT_EN_BLOCK_FILL_INT_EN_POS    0

#define LCU_COMMON_LMAC_INT_EN_ERROR_INT_EN_RST    0x0
#define LCU_COMMON_LMAC_INT_EN_FINAL_SAMPLE_INT_EN_RST    0x0
#define LCU_COMMON_LMAC_INT_EN_BLOCK_FILL_INT_EN_RST    0x0

static inline void lcu_common_lmac_int_en_pack(struct cl_chip *chip, u8 error_int_en, u8 final_sample_int_en, u8 block_fill_int_en)
{
	ASSERT_ERR_CHIP((((u32)error_int_en << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)final_sample_int_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)block_fill_int_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_LMAC_INT_EN_ADDR, ((u32)error_int_en << 2) | ((u32)final_sample_int_en << 1) | ((u32)block_fill_int_en << 0));
}

static inline void lcu_common_lmac_int_en_unpack(struct cl_chip *chip, u8 *error_int_en, u8 *final_sample_int_en, u8 *block_fill_int_en)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LMAC_INT_EN_ADDR);

	*error_int_en = (local_val & ((u32)0x00000004)) >> 2;
	*final_sample_int_en = (local_val & ((u32)0x00000002)) >> 1;
	*block_fill_int_en = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_lmac_int_en_error_int_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LMAC_INT_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void lcu_common_lmac_int_en_error_int_en_setf(struct cl_chip *chip, u8 errorinten)
{
	ASSERT_ERR_CHIP((((u32)errorinten << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_COMMON_LMAC_INT_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_LMAC_INT_EN_ADDR) & ~((u32)0x00000004)) | ((u32)errorinten << 2));
}

static inline u8 lcu_common_lmac_int_en_final_sample_int_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LMAC_INT_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void lcu_common_lmac_int_en_final_sample_int_en_setf(struct cl_chip *chip, u8 finalsampleinten)
{
	ASSERT_ERR_CHIP((((u32)finalsampleinten << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_LMAC_INT_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_LMAC_INT_EN_ADDR) & ~((u32)0x00000002)) | ((u32)finalsampleinten << 1));
}

static inline u8 lcu_common_lmac_int_en_block_fill_int_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LMAC_INT_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void lcu_common_lmac_int_en_block_fill_int_en_setf(struct cl_chip *chip, u8 blockfillinten)
{
	ASSERT_ERR_CHIP((((u32)blockfillinten << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_LMAC_INT_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_LMAC_INT_EN_ADDR) & ~((u32)0x00000001)) | ((u32)blockfillinten << 0));
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
#define LCU_COMMON_UMAC_INT_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000058)
#define LCU_COMMON_UMAC_INT_EN_OFFSET      0x00000058
#define LCU_COMMON_UMAC_INT_EN_INDEX       0x00000016
#define LCU_COMMON_UMAC_INT_EN_RESET       0x00000000

static inline u32 lcu_common_umac_int_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_UMAC_INT_EN_ADDR);
}

static inline void lcu_common_umac_int_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_UMAC_INT_EN_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_UMAC_INT_EN_ERROR_INT_EN_BIT    ((u32)0x00000004)
#define LCU_COMMON_UMAC_INT_EN_ERROR_INT_EN_POS    2
#define LCU_COMMON_UMAC_INT_EN_FINAL_SAMPLE_INT_EN_BIT    ((u32)0x00000002)
#define LCU_COMMON_UMAC_INT_EN_FINAL_SAMPLE_INT_EN_POS    1
#define LCU_COMMON_UMAC_INT_EN_BLOCK_FILL_INT_EN_BIT    ((u32)0x00000001)
#define LCU_COMMON_UMAC_INT_EN_BLOCK_FILL_INT_EN_POS    0

#define LCU_COMMON_UMAC_INT_EN_ERROR_INT_EN_RST    0x0
#define LCU_COMMON_UMAC_INT_EN_FINAL_SAMPLE_INT_EN_RST    0x0
#define LCU_COMMON_UMAC_INT_EN_BLOCK_FILL_INT_EN_RST    0x0

static inline void lcu_common_umac_int_en_pack(struct cl_chip *chip, u8 error_int_en, u8 final_sample_int_en, u8 block_fill_int_en)
{
	ASSERT_ERR_CHIP((((u32)error_int_en << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)final_sample_int_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)block_fill_int_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_UMAC_INT_EN_ADDR, ((u32)error_int_en << 2) | ((u32)final_sample_int_en << 1) | ((u32)block_fill_int_en << 0));
}

static inline void lcu_common_umac_int_en_unpack(struct cl_chip *chip, u8 *error_int_en, u8 *final_sample_int_en, u8 *block_fill_int_en)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_UMAC_INT_EN_ADDR);

	*error_int_en = (local_val & ((u32)0x00000004)) >> 2;
	*final_sample_int_en = (local_val & ((u32)0x00000002)) >> 1;
	*block_fill_int_en = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_umac_int_en_error_int_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_UMAC_INT_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void lcu_common_umac_int_en_error_int_en_setf(struct cl_chip *chip, u8 errorinten)
{
	ASSERT_ERR_CHIP((((u32)errorinten << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_COMMON_UMAC_INT_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_UMAC_INT_EN_ADDR) & ~((u32)0x00000004)) | ((u32)errorinten << 2));
}

static inline u8 lcu_common_umac_int_en_final_sample_int_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_UMAC_INT_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void lcu_common_umac_int_en_final_sample_int_en_setf(struct cl_chip *chip, u8 finalsampleinten)
{
	ASSERT_ERR_CHIP((((u32)finalsampleinten << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_UMAC_INT_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_UMAC_INT_EN_ADDR) & ~((u32)0x00000002)) | ((u32)finalsampleinten << 1));
}

static inline u8 lcu_common_umac_int_en_block_fill_int_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_UMAC_INT_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void lcu_common_umac_int_en_block_fill_int_en_setf(struct cl_chip *chip, u8 blockfillinten)
{
	ASSERT_ERR_CHIP((((u32)blockfillinten << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_UMAC_INT_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_UMAC_INT_EN_ADDR) & ~((u32)0x00000001)) | ((u32)blockfillinten << 0));
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
#define LCU_COMMON_SMAC_INT_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000005C)
#define LCU_COMMON_SMAC_INT_EN_OFFSET      0x0000005C
#define LCU_COMMON_SMAC_INT_EN_INDEX       0x00000017
#define LCU_COMMON_SMAC_INT_EN_RESET       0x00000000

static inline u32 lcu_common_smac_int_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_SMAC_INT_EN_ADDR);
}

static inline void lcu_common_smac_int_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_SMAC_INT_EN_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_SMAC_INT_EN_ERROR_INT_EN_BIT    ((u32)0x00000004)
#define LCU_COMMON_SMAC_INT_EN_ERROR_INT_EN_POS    2
#define LCU_COMMON_SMAC_INT_EN_FINAL_SAMPLE_INT_EN_BIT    ((u32)0x00000002)
#define LCU_COMMON_SMAC_INT_EN_FINAL_SAMPLE_INT_EN_POS    1
#define LCU_COMMON_SMAC_INT_EN_BLOCK_FILL_INT_EN_BIT    ((u32)0x00000001)
#define LCU_COMMON_SMAC_INT_EN_BLOCK_FILL_INT_EN_POS    0

#define LCU_COMMON_SMAC_INT_EN_ERROR_INT_EN_RST    0x0
#define LCU_COMMON_SMAC_INT_EN_FINAL_SAMPLE_INT_EN_RST    0x0
#define LCU_COMMON_SMAC_INT_EN_BLOCK_FILL_INT_EN_RST    0x0

static inline void lcu_common_smac_int_en_pack(struct cl_chip *chip, u8 error_int_en, u8 final_sample_int_en, u8 block_fill_int_en)
{
	ASSERT_ERR_CHIP((((u32)error_int_en << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)final_sample_int_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)block_fill_int_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_SMAC_INT_EN_ADDR, ((u32)error_int_en << 2) | ((u32)final_sample_int_en << 1) | ((u32)block_fill_int_en << 0));
}

static inline void lcu_common_smac_int_en_unpack(struct cl_chip *chip, u8 *error_int_en, u8 *final_sample_int_en, u8 *block_fill_int_en)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_SMAC_INT_EN_ADDR);

	*error_int_en = (local_val & ((u32)0x00000004)) >> 2;
	*final_sample_int_en = (local_val & ((u32)0x00000002)) >> 1;
	*block_fill_int_en = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_smac_int_en_error_int_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_SMAC_INT_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void lcu_common_smac_int_en_error_int_en_setf(struct cl_chip *chip, u8 errorinten)
{
	ASSERT_ERR_CHIP((((u32)errorinten << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_COMMON_SMAC_INT_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_SMAC_INT_EN_ADDR) & ~((u32)0x00000004)) | ((u32)errorinten << 2));
}

static inline u8 lcu_common_smac_int_en_final_sample_int_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_SMAC_INT_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void lcu_common_smac_int_en_final_sample_int_en_setf(struct cl_chip *chip, u8 finalsampleinten)
{
	ASSERT_ERR_CHIP((((u32)finalsampleinten << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_SMAC_INT_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_SMAC_INT_EN_ADDR) & ~((u32)0x00000002)) | ((u32)finalsampleinten << 1));
}

static inline u8 lcu_common_smac_int_en_block_fill_int_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_SMAC_INT_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void lcu_common_smac_int_en_block_fill_int_en_setf(struct cl_chip *chip, u8 blockfillinten)
{
	ASSERT_ERR_CHIP((((u32)blockfillinten << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_SMAC_INT_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_SMAC_INT_EN_ADDR) & ~((u32)0x00000001)) | ((u32)blockfillinten << 0));
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
#define LCU_COMMON_INT_FORCE_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000060)
#define LCU_COMMON_INT_FORCE_OFFSET      0x00000060
#define LCU_COMMON_INT_FORCE_INDEX       0x00000018
#define LCU_COMMON_INT_FORCE_RESET       0x00000000

static inline void lcu_common_int_force_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_INT_FORCE_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_INT_FORCE_ERROR_INT_FORCE_BIT    ((u32)0x00000004)
#define LCU_COMMON_INT_FORCE_ERROR_INT_FORCE_POS    2
#define LCU_COMMON_INT_FORCE_FINAL_SAMPLE_INT_FORCE_BIT    ((u32)0x00000002)
#define LCU_COMMON_INT_FORCE_FINAL_SAMPLE_INT_FORCE_POS    1
#define LCU_COMMON_INT_FORCE_BLOCK_FILL_INT_FORCE_BIT    ((u32)0x00000001)
#define LCU_COMMON_INT_FORCE_BLOCK_FILL_INT_FORCE_POS    0

#define LCU_COMMON_INT_FORCE_ERROR_INT_FORCE_RST    0x0
#define LCU_COMMON_INT_FORCE_FINAL_SAMPLE_INT_FORCE_RST    0x0
#define LCU_COMMON_INT_FORCE_BLOCK_FILL_INT_FORCE_RST    0x0

static inline void lcu_common_int_force_pack(struct cl_chip *chip, u8 error_int_force, u8 final_sample_int_force, u8 block_fill_int_force)
{
	ASSERT_ERR_CHIP((((u32)error_int_force << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)final_sample_int_force << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)block_fill_int_force << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_INT_FORCE_ADDR, ((u32)error_int_force << 2) | ((u32)final_sample_int_force << 1) | ((u32)block_fill_int_force << 0));
}

static inline void lcu_common_int_force_error_int_force_setf(struct cl_chip *chip, u8 errorintforce)
{
	ASSERT_ERR_CHIP((((u32)errorintforce << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_COMMON_INT_FORCE_ADDR, (cl_reg_read(chip, LCU_COMMON_INT_FORCE_ADDR) & ~((u32)0x00000004)) | ((u32)errorintforce << 2));
}

static inline void lcu_common_int_force_final_sample_int_force_setf(struct cl_chip *chip, u8 finalsampleintforce)
{
	ASSERT_ERR_CHIP((((u32)finalsampleintforce << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_INT_FORCE_ADDR, (cl_reg_read(chip, LCU_COMMON_INT_FORCE_ADDR) & ~((u32)0x00000002)) | ((u32)finalsampleintforce << 1));
}

static inline void lcu_common_int_force_block_fill_int_force_setf(struct cl_chip *chip, u8 blockfillintforce)
{
	ASSERT_ERR_CHIP((((u32)blockfillintforce << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_INT_FORCE_ADDR, (cl_reg_read(chip, LCU_COMMON_INT_FORCE_ADDR) & ~((u32)0x00000001)) | ((u32)blockfillintforce << 0));
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
#define LCU_COMMON_INT_CLEAR_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000064)
#define LCU_COMMON_INT_CLEAR_OFFSET      0x00000064
#define LCU_COMMON_INT_CLEAR_INDEX       0x00000019
#define LCU_COMMON_INT_CLEAR_RESET       0x00000000

static inline void lcu_common_int_clear_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_INT_CLEAR_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_INT_CLEAR_ERROR_INT_CLEAR_BIT    ((u32)0x00000004)
#define LCU_COMMON_INT_CLEAR_ERROR_INT_CLEAR_POS    2
#define LCU_COMMON_INT_CLEAR_FINAL_SAMPLE_INT_CLEAR_BIT    ((u32)0x00000002)
#define LCU_COMMON_INT_CLEAR_FINAL_SAMPLE_INT_CLEAR_POS    1
#define LCU_COMMON_INT_CLEAR_BLOCK_FILL_INT_CLEAR_BIT    ((u32)0x00000001)
#define LCU_COMMON_INT_CLEAR_BLOCK_FILL_INT_CLEAR_POS    0

#define LCU_COMMON_INT_CLEAR_ERROR_INT_CLEAR_RST    0x0
#define LCU_COMMON_INT_CLEAR_FINAL_SAMPLE_INT_CLEAR_RST    0x0
#define LCU_COMMON_INT_CLEAR_BLOCK_FILL_INT_CLEAR_RST    0x0

static inline void lcu_common_int_clear_pack(struct cl_chip *chip, u8 error_int_clear, u8 final_sample_int_clear, u8 block_fill_int_clear)
{
	ASSERT_ERR_CHIP((((u32)error_int_clear << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)final_sample_int_clear << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)block_fill_int_clear << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_INT_CLEAR_ADDR, ((u32)error_int_clear << 2) | ((u32)final_sample_int_clear << 1) | ((u32)block_fill_int_clear << 0));
}

static inline void lcu_common_int_clear_error_int_clear_setf(struct cl_chip *chip, u8 errorintclear)
{
	ASSERT_ERR_CHIP((((u32)errorintclear << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_COMMON_INT_CLEAR_ADDR, (cl_reg_read(chip, LCU_COMMON_INT_CLEAR_ADDR) & ~((u32)0x00000004)) | ((u32)errorintclear << 2));
}

static inline void lcu_common_int_clear_final_sample_int_clear_setf(struct cl_chip *chip, u8 finalsampleintclear)
{
	ASSERT_ERR_CHIP((((u32)finalsampleintclear << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_INT_CLEAR_ADDR, (cl_reg_read(chip, LCU_COMMON_INT_CLEAR_ADDR) & ~((u32)0x00000002)) | ((u32)finalsampleintclear << 1));
}

static inline void lcu_common_int_clear_block_fill_int_clear_setf(struct cl_chip *chip, u8 blockfillintclear)
{
	ASSERT_ERR_CHIP((((u32)blockfillintclear << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_INT_CLEAR_ADDR, (cl_reg_read(chip, LCU_COMMON_INT_CLEAR_ADDR) & ~((u32)0x00000001)) | ((u32)blockfillintclear << 0));
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
#define LCU_COMMON_LMAC_INT_STAT_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000068)
#define LCU_COMMON_LMAC_INT_STAT_OFFSET      0x00000068
#define LCU_COMMON_LMAC_INT_STAT_INDEX       0x0000001A
#define LCU_COMMON_LMAC_INT_STAT_RESET       0x00000000

static inline u32 lcu_common_lmac_int_stat_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LMAC_INT_STAT_ADDR);
}

/* field definitions */
#define LCU_COMMON_LMAC_INT_STAT_ERROR_INT_STATUS_BIT    ((u32)0x00000004)
#define LCU_COMMON_LMAC_INT_STAT_ERROR_INT_STATUS_POS    2
#define LCU_COMMON_LMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_BIT    ((u32)0x00000002)
#define LCU_COMMON_LMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_POS    1
#define LCU_COMMON_LMAC_INT_STAT_BLOCK_FILL_INT_STATUS_BIT    ((u32)0x00000001)
#define LCU_COMMON_LMAC_INT_STAT_BLOCK_FILL_INT_STATUS_POS    0

#define LCU_COMMON_LMAC_INT_STAT_ERROR_INT_STATUS_RST    0x0
#define LCU_COMMON_LMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_RST    0x0
#define LCU_COMMON_LMAC_INT_STAT_BLOCK_FILL_INT_STATUS_RST    0x0

static inline void lcu_common_lmac_int_stat_unpack(struct cl_chip *chip, u8 *error_int_status, u8 *final_sample_int_status, u8 *block_fill_int_status)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LMAC_INT_STAT_ADDR);

	*error_int_status = (local_val & ((u32)0x00000004)) >> 2;
	*final_sample_int_status = (local_val & ((u32)0x00000002)) >> 1;
	*block_fill_int_status = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_lmac_int_stat_error_int_status_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LMAC_INT_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline u8 lcu_common_lmac_int_stat_final_sample_int_status_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LMAC_INT_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline u8 lcu_common_lmac_int_stat_block_fill_int_status_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LMAC_INT_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
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
#define LCU_COMMON_UMAC_INT_STAT_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000006C)
#define LCU_COMMON_UMAC_INT_STAT_OFFSET      0x0000006C
#define LCU_COMMON_UMAC_INT_STAT_INDEX       0x0000001B
#define LCU_COMMON_UMAC_INT_STAT_RESET       0x00000000

static inline u32 lcu_common_umac_int_stat_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_UMAC_INT_STAT_ADDR);
}

/* field definitions */
#define LCU_COMMON_UMAC_INT_STAT_ERROR_INT_STATUS_BIT    ((u32)0x00000004)
#define LCU_COMMON_UMAC_INT_STAT_ERROR_INT_STATUS_POS    2
#define LCU_COMMON_UMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_BIT    ((u32)0x00000002)
#define LCU_COMMON_UMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_POS    1
#define LCU_COMMON_UMAC_INT_STAT_BLOCK_FILL_INT_STATUS_BIT    ((u32)0x00000001)
#define LCU_COMMON_UMAC_INT_STAT_BLOCK_FILL_INT_STATUS_POS    0

#define LCU_COMMON_UMAC_INT_STAT_ERROR_INT_STATUS_RST    0x0
#define LCU_COMMON_UMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_RST    0x0
#define LCU_COMMON_UMAC_INT_STAT_BLOCK_FILL_INT_STATUS_RST    0x0

static inline void lcu_common_umac_int_stat_unpack(struct cl_chip *chip, u8 *error_int_status, u8 *final_sample_int_status, u8 *block_fill_int_status)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_UMAC_INT_STAT_ADDR);

	*error_int_status = (local_val & ((u32)0x00000004)) >> 2;
	*final_sample_int_status = (local_val & ((u32)0x00000002)) >> 1;
	*block_fill_int_status = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_umac_int_stat_error_int_status_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_UMAC_INT_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline u8 lcu_common_umac_int_stat_final_sample_int_status_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_UMAC_INT_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline u8 lcu_common_umac_int_stat_block_fill_int_status_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_UMAC_INT_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
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
#define LCU_COMMON_SMAC_INT_STAT_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000070)
#define LCU_COMMON_SMAC_INT_STAT_OFFSET      0x00000070
#define LCU_COMMON_SMAC_INT_STAT_INDEX       0x0000001C
#define LCU_COMMON_SMAC_INT_STAT_RESET       0x00000000

static inline u32 lcu_common_smac_int_stat_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_SMAC_INT_STAT_ADDR);
}

/* field definitions */
#define LCU_COMMON_SMAC_INT_STAT_ERROR_INT_STATUS_BIT    ((u32)0x00000004)
#define LCU_COMMON_SMAC_INT_STAT_ERROR_INT_STATUS_POS    2
#define LCU_COMMON_SMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_BIT    ((u32)0x00000002)
#define LCU_COMMON_SMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_POS    1
#define LCU_COMMON_SMAC_INT_STAT_BLOCK_FILL_INT_STATUS_BIT    ((u32)0x00000001)
#define LCU_COMMON_SMAC_INT_STAT_BLOCK_FILL_INT_STATUS_POS    0

#define LCU_COMMON_SMAC_INT_STAT_ERROR_INT_STATUS_RST    0x0
#define LCU_COMMON_SMAC_INT_STAT_FINAL_SAMPLE_INT_STATUS_RST    0x0
#define LCU_COMMON_SMAC_INT_STAT_BLOCK_FILL_INT_STATUS_RST    0x0

static inline void lcu_common_smac_int_stat_unpack(struct cl_chip *chip, u8 *error_int_status, u8 *final_sample_int_status, u8 *block_fill_int_status)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_SMAC_INT_STAT_ADDR);

	*error_int_status = (local_val & ((u32)0x00000004)) >> 2;
	*final_sample_int_status = (local_val & ((u32)0x00000002)) >> 1;
	*block_fill_int_status = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_smac_int_stat_error_int_status_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_SMAC_INT_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline u8 lcu_common_smac_int_stat_final_sample_int_status_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_SMAC_INT_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline u8 lcu_common_smac_int_stat_block_fill_int_status_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_SMAC_INT_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
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
#define LCU_COMMON_PENDING_CH_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000074)
#define LCU_COMMON_PENDING_CH_REG_0_OFFSET      0x00000074
#define LCU_COMMON_PENDING_CH_REG_0_INDEX       0x0000001D
#define LCU_COMMON_PENDING_CH_REG_0_RESET       0x00000000

static inline u32 lcu_common_pending_ch_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_PENDING_CH_REG_0_ADDR);
}

/* field definitions */
#define LCU_COMMON_PENDING_CH_REG_0_PENDING_CH_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_PENDING_CH_REG_0_PENDING_CH_LSB    0
#define LCU_COMMON_PENDING_CH_REG_0_PENDING_CH_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_PENDING_CH_REG_0_PENDING_CH_RST    0x0

static inline u32 lcu_common_pending_ch_reg_0_pending_ch_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_PENDING_CH_REG_0_ADDR);

	return (u32)(local_val >> 0);
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
#define LCU_COMMON_PENDING_CH_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000078)
#define LCU_COMMON_PENDING_CH_REG_1_OFFSET      0x00000078
#define LCU_COMMON_PENDING_CH_REG_1_INDEX       0x0000001E
#define LCU_COMMON_PENDING_CH_REG_1_RESET       0x00000000

static inline u32 lcu_common_pending_ch_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_PENDING_CH_REG_1_ADDR);
}

/* field definitions */
#define LCU_COMMON_PENDING_CH_REG_1_PENDING_CH_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_PENDING_CH_REG_1_PENDING_CH_LSB    0
#define LCU_COMMON_PENDING_CH_REG_1_PENDING_CH_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_PENDING_CH_REG_1_PENDING_CH_RST    0x0

static inline u32 lcu_common_pending_ch_reg_1_pending_ch_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_PENDING_CH_REG_1_ADDR);

	return (u32)(local_val >> 0);
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
#define LCU_COMMON_PENDING_CH_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000007C)
#define LCU_COMMON_PENDING_CH_REG_2_OFFSET      0x0000007C
#define LCU_COMMON_PENDING_CH_REG_2_INDEX       0x0000001F
#define LCU_COMMON_PENDING_CH_REG_2_RESET       0x00000000

static inline u32 lcu_common_pending_ch_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_PENDING_CH_REG_2_ADDR);
}

/* field definitions */
#define LCU_COMMON_PENDING_CH_REG_2_PENDING_CH_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_PENDING_CH_REG_2_PENDING_CH_LSB    0
#define LCU_COMMON_PENDING_CH_REG_2_PENDING_CH_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_PENDING_CH_REG_2_PENDING_CH_RST    0x0

static inline u32 lcu_common_pending_ch_reg_2_pending_ch_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_PENDING_CH_REG_2_ADDR);

	return (u32)(local_val >> 0);
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
#define LCU_COMMON_PENDING_CH_REG_3_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000080)
#define LCU_COMMON_PENDING_CH_REG_3_OFFSET      0x00000080
#define LCU_COMMON_PENDING_CH_REG_3_INDEX       0x00000020
#define LCU_COMMON_PENDING_CH_REG_3_RESET       0x00000000

static inline u32 lcu_common_pending_ch_reg_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_PENDING_CH_REG_3_ADDR);
}

/* field definitions */
#define LCU_COMMON_PENDING_CH_REG_3_PENDING_CH_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_PENDING_CH_REG_3_PENDING_CH_LSB    0
#define LCU_COMMON_PENDING_CH_REG_3_PENDING_CH_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_PENDING_CH_REG_3_PENDING_CH_RST    0x0

static inline u32 lcu_common_pending_ch_reg_3_pending_ch_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_PENDING_CH_REG_3_ADDR);

	return (u32)(local_val >> 0);
}

/**
 * @brief LCU_COMMON_CC_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    LCU_CC_MODE               0
 * </pre>
 */
#define LCU_COMMON_CC_MODE_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000084)
#define LCU_COMMON_CC_MODE_OFFSET      0x00000084
#define LCU_COMMON_CC_MODE_INDEX       0x00000021
#define LCU_COMMON_CC_MODE_RESET       0x00000000

static inline u32 lcu_common_cc_mode_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_CC_MODE_ADDR);
}

static inline void lcu_common_cc_mode_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_CC_MODE_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_CC_MODE_LCU_CC_MODE_BIT    ((u32)0x00000001)
#define LCU_COMMON_CC_MODE_LCU_CC_MODE_POS    0

#define LCU_COMMON_CC_MODE_LCU_CC_MODE_RST    0x0

static inline u8 lcu_common_cc_mode_lcu_cc_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CC_MODE_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_common_cc_mode_lcu_cc_mode_setf(struct cl_chip *chip, u8 lcuccmode)
{
	ASSERT_ERR_CHIP((((u32)lcuccmode << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CC_MODE_ADDR, (u32)lcuccmode << 0);
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
#define LCU_COMMON_CC_START_STOP_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000088)
#define LCU_COMMON_CC_START_STOP_OFFSET      0x00000088
#define LCU_COMMON_CC_START_STOP_INDEX       0x00000022
#define LCU_COMMON_CC_START_STOP_RESET       0x00000000

static inline void lcu_common_cc_start_stop_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_CC_START_STOP_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_CC_START_STOP_LCU_CC_STOP_BIT    ((u32)0x00000002)
#define LCU_COMMON_CC_START_STOP_LCU_CC_STOP_POS    1
#define LCU_COMMON_CC_START_STOP_LCU_CC_START_BIT    ((u32)0x00000001)
#define LCU_COMMON_CC_START_STOP_LCU_CC_START_POS    0

#define LCU_COMMON_CC_START_STOP_LCU_CC_STOP_RST    0x0
#define LCU_COMMON_CC_START_STOP_LCU_CC_START_RST    0x0

static inline void lcu_common_cc_start_stop_pack(struct cl_chip *chip, u8 lcu_cc_stop, u8 lcu_cc_start)
{
	ASSERT_ERR_CHIP((((u32)lcu_cc_stop << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)lcu_cc_start << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CC_START_STOP_ADDR, ((u32)lcu_cc_stop << 1) | ((u32)lcu_cc_start << 0));
}

static inline void lcu_common_cc_start_stop_lcu_cc_stop_setf(struct cl_chip *chip, u8 lcuccstop)
{
	ASSERT_ERR_CHIP((((u32)lcuccstop << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_CC_START_STOP_ADDR, (cl_reg_read(chip, LCU_COMMON_CC_START_STOP_ADDR) & ~((u32)0x00000002)) | ((u32)lcuccstop << 1));
}

static inline void lcu_common_cc_start_stop_lcu_cc_start_setf(struct cl_chip *chip, u8 lcuccstart)
{
	ASSERT_ERR_CHIP((((u32)lcuccstart << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CC_START_STOP_ADDR, (cl_reg_read(chip, LCU_COMMON_CC_START_STOP_ADDR) & ~((u32)0x00000001)) | ((u32)lcuccstart << 0));
}

/**
 * @brief LCU_COMMON_CC_CPU_SEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 LCU_CC_CPU_SEL            0x0
 * </pre>
 */
#define LCU_COMMON_CC_CPU_SEL_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000008C)
#define LCU_COMMON_CC_CPU_SEL_OFFSET      0x0000008C
#define LCU_COMMON_CC_CPU_SEL_INDEX       0x00000023
#define LCU_COMMON_CC_CPU_SEL_RESET       0x00000000

static inline u32 lcu_common_cc_cpu_sel_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_CC_CPU_SEL_ADDR);
}

static inline void lcu_common_cc_cpu_sel_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_CC_CPU_SEL_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_CC_CPU_SEL_LCU_CC_CPU_SEL_MASK    ((u32)0x00000003)
#define LCU_COMMON_CC_CPU_SEL_LCU_CC_CPU_SEL_LSB    0
#define LCU_COMMON_CC_CPU_SEL_LCU_CC_CPU_SEL_WIDTH    ((u32)0x00000002)

#define LCU_COMMON_CC_CPU_SEL_LCU_CC_CPU_SEL_RST    0x0

static inline u8 lcu_common_cc_cpu_sel_lcu_cc_cpu_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CC_CPU_SEL_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_common_cc_cpu_sel_lcu_cc_cpu_sel_setf(struct cl_chip *chip, u8 lcucccpusel)
{
	ASSERT_ERR_CHIP((((u32)lcucccpusel << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, LCU_COMMON_CC_CPU_SEL_ADDR, (u32)lcucccpusel << 0);
}

/**
 * @brief LCU_COMMON_CC_START_PC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_CC_START_PC           0x0
 * </pre>
 */
#define LCU_COMMON_CC_START_PC_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000090)
#define LCU_COMMON_CC_START_PC_OFFSET      0x00000090
#define LCU_COMMON_CC_START_PC_INDEX       0x00000024
#define LCU_COMMON_CC_START_PC_RESET       0x00000000

static inline u32 lcu_common_cc_start_pc_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_CC_START_PC_ADDR);
}

static inline void lcu_common_cc_start_pc_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_CC_START_PC_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_CC_START_PC_LCU_CC_START_PC_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_CC_START_PC_LCU_CC_START_PC_LSB    0
#define LCU_COMMON_CC_START_PC_LCU_CC_START_PC_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_CC_START_PC_LCU_CC_START_PC_RST    0x0

static inline u32 lcu_common_cc_start_pc_lcu_cc_start_pc_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CC_START_PC_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_cc_start_pc_lcu_cc_start_pc_setf(struct cl_chip *chip, u32 lcuccstartpc)
{
	ASSERT_ERR_CHIP((((u32)lcuccstartpc << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_CC_START_PC_ADDR, (u32)lcuccstartpc << 0);
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
#define LCU_COMMON_CH_0_CONF_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000100)
#define LCU_COMMON_CH_0_CONF_OFFSET      0x00000100
#define LCU_COMMON_CH_0_CONF_INDEX       0x00000040
#define LCU_COMMON_CH_0_CONF_RESET       0x00000000

static inline u32 lcu_common_ch_0_conf_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_CH_0_CONF_ADDR);
}

static inline void lcu_common_ch_0_conf_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_CH_0_CONF_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_CH_0_CONF_CH_0_WRITE_VCI_BIT    ((u32)0x00000004)
#define LCU_COMMON_CH_0_CONF_CH_0_WRITE_VCI_POS    2
#define LCU_COMMON_CH_0_CONF_CH_0_WRITE_TS_BIT    ((u32)0x00000002)
#define LCU_COMMON_CH_0_CONF_CH_0_WRITE_TS_POS    1
#define LCU_COMMON_CH_0_CONF_CH_0_REC_FORMAT_BIT    ((u32)0x00000001)
#define LCU_COMMON_CH_0_CONF_CH_0_REC_FORMAT_POS    0

#define LCU_COMMON_CH_0_CONF_CH_0_WRITE_VCI_RST    0x0
#define LCU_COMMON_CH_0_CONF_CH_0_WRITE_TS_RST    0x0
#define LCU_COMMON_CH_0_CONF_CH_0_REC_FORMAT_RST    0x0

static inline void lcu_common_ch_0_conf_pack(struct cl_chip *chip, u8 ch0_write_vci, u8 ch0_write_ts, u8 ch0_rec_format)
{
	ASSERT_ERR_CHIP((((u32)ch0_write_vci << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)ch0_write_ts << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)ch0_rec_format << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_0_CONF_ADDR, ((u32)ch0_write_vci << 2) | ((u32)ch0_write_ts << 1) | ((u32)ch0_rec_format << 0));
}

static inline void lcu_common_ch_0_conf_unpack(struct cl_chip *chip, u8 *ch0_write_vci, u8 *ch0_write_ts, u8 *ch0_rec_format)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_0_CONF_ADDR);

	*ch0_write_vci = (local_val & ((u32)0x00000004)) >> 2;
	*ch0_write_ts = (local_val & ((u32)0x00000002)) >> 1;
	*ch0_rec_format = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_ch_0_conf_ch_0_write_vci_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_0_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void lcu_common_ch_0_conf_ch_0_write_vci_setf(struct cl_chip *chip, u8 ch0writevci)
{
	ASSERT_ERR_CHIP((((u32)ch0writevci << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_0_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_0_CONF_ADDR) & ~((u32)0x00000004)) | ((u32)ch0writevci << 2));
}

static inline u8 lcu_common_ch_0_conf_ch_0_write_ts_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_0_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void lcu_common_ch_0_conf_ch_0_write_ts_setf(struct cl_chip *chip, u8 ch0writets)
{
	ASSERT_ERR_CHIP((((u32)ch0writets << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_0_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_0_CONF_ADDR) & ~((u32)0x00000002)) | ((u32)ch0writets << 1));
}

static inline u8 lcu_common_ch_0_conf_ch_0_rec_format_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_0_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void lcu_common_ch_0_conf_ch_0_rec_format_setf(struct cl_chip *chip, u8 ch0recformat)
{
	ASSERT_ERR_CHIP((((u32)ch0recformat << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_0_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_0_CONF_ADDR) & ~((u32)0x00000001)) | ((u32)ch0recformat << 0));
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
#define LCU_COMMON_CH_1_CONF_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000104)
#define LCU_COMMON_CH_1_CONF_OFFSET      0x00000104
#define LCU_COMMON_CH_1_CONF_INDEX       0x00000041
#define LCU_COMMON_CH_1_CONF_RESET       0x00000000

static inline u32 lcu_common_ch_1_conf_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_CH_1_CONF_ADDR);
}

static inline void lcu_common_ch_1_conf_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_CH_1_CONF_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_CH_1_CONF_CH_1_WRITE_VCI_BIT    ((u32)0x00000004)
#define LCU_COMMON_CH_1_CONF_CH_1_WRITE_VCI_POS    2
#define LCU_COMMON_CH_1_CONF_CH_1_WRITE_TS_BIT    ((u32)0x00000002)
#define LCU_COMMON_CH_1_CONF_CH_1_WRITE_TS_POS    1
#define LCU_COMMON_CH_1_CONF_CH_1_REC_FORMAT_BIT    ((u32)0x00000001)
#define LCU_COMMON_CH_1_CONF_CH_1_REC_FORMAT_POS    0

#define LCU_COMMON_CH_1_CONF_CH_1_WRITE_VCI_RST    0x0
#define LCU_COMMON_CH_1_CONF_CH_1_WRITE_TS_RST    0x0
#define LCU_COMMON_CH_1_CONF_CH_1_REC_FORMAT_RST    0x0

static inline void lcu_common_ch_1_conf_pack(struct cl_chip *chip, u8 ch1_write_vci, u8 ch1_write_ts, u8 ch1_rec_format)
{
	ASSERT_ERR_CHIP((((u32)ch1_write_vci << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)ch1_write_ts << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)ch1_rec_format << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_1_CONF_ADDR, ((u32)ch1_write_vci << 2) | ((u32)ch1_write_ts << 1) | ((u32)ch1_rec_format << 0));
}

static inline void lcu_common_ch_1_conf_unpack(struct cl_chip *chip, u8 *ch1_write_vci, u8 *ch1_write_ts, u8 *ch1_rec_format)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_1_CONF_ADDR);

	*ch1_write_vci = (local_val & ((u32)0x00000004)) >> 2;
	*ch1_write_ts = (local_val & ((u32)0x00000002)) >> 1;
	*ch1_rec_format = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_ch_1_conf_ch_1_write_vci_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_1_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void lcu_common_ch_1_conf_ch_1_write_vci_setf(struct cl_chip *chip, u8 ch1writevci)
{
	ASSERT_ERR_CHIP((((u32)ch1writevci << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_1_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_1_CONF_ADDR) & ~((u32)0x00000004)) | ((u32)ch1writevci << 2));
}

static inline u8 lcu_common_ch_1_conf_ch_1_write_ts_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_1_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void lcu_common_ch_1_conf_ch_1_write_ts_setf(struct cl_chip *chip, u8 ch1writets)
{
	ASSERT_ERR_CHIP((((u32)ch1writets << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_1_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_1_CONF_ADDR) & ~((u32)0x00000002)) | ((u32)ch1writets << 1));
}

static inline u8 lcu_common_ch_1_conf_ch_1_rec_format_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_1_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void lcu_common_ch_1_conf_ch_1_rec_format_setf(struct cl_chip *chip, u8 ch1recformat)
{
	ASSERT_ERR_CHIP((((u32)ch1recformat << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_1_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_1_CONF_ADDR) & ~((u32)0x00000001)) | ((u32)ch1recformat << 0));
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
#define LCU_COMMON_CH_2_CONF_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000108)
#define LCU_COMMON_CH_2_CONF_OFFSET      0x00000108
#define LCU_COMMON_CH_2_CONF_INDEX       0x00000042
#define LCU_COMMON_CH_2_CONF_RESET       0x00000000

static inline u32 lcu_common_ch_2_conf_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_CH_2_CONF_ADDR);
}

static inline void lcu_common_ch_2_conf_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_CH_2_CONF_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_CH_2_CONF_CH_2_WRITE_VCI_BIT    ((u32)0x00000004)
#define LCU_COMMON_CH_2_CONF_CH_2_WRITE_VCI_POS    2
#define LCU_COMMON_CH_2_CONF_CH_2_WRITE_TS_BIT    ((u32)0x00000002)
#define LCU_COMMON_CH_2_CONF_CH_2_WRITE_TS_POS    1
#define LCU_COMMON_CH_2_CONF_CH_2_REC_FORMAT_BIT    ((u32)0x00000001)
#define LCU_COMMON_CH_2_CONF_CH_2_REC_FORMAT_POS    0

#define LCU_COMMON_CH_2_CONF_CH_2_WRITE_VCI_RST    0x0
#define LCU_COMMON_CH_2_CONF_CH_2_WRITE_TS_RST    0x0
#define LCU_COMMON_CH_2_CONF_CH_2_REC_FORMAT_RST    0x0

static inline void lcu_common_ch_2_conf_pack(struct cl_chip *chip, u8 ch2_write_vci, u8 ch2_write_ts, u8 ch2_rec_format)
{
	ASSERT_ERR_CHIP((((u32)ch2_write_vci << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)ch2_write_ts << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)ch2_rec_format << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_2_CONF_ADDR, ((u32)ch2_write_vci << 2) | ((u32)ch2_write_ts << 1) | ((u32)ch2_rec_format << 0));
}

static inline void lcu_common_ch_2_conf_unpack(struct cl_chip *chip, u8 *ch2_write_vci, u8 *ch2_write_ts, u8 *ch2_rec_format)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_2_CONF_ADDR);

	*ch2_write_vci = (local_val & ((u32)0x00000004)) >> 2;
	*ch2_write_ts = (local_val & ((u32)0x00000002)) >> 1;
	*ch2_rec_format = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_ch_2_conf_ch_2_write_vci_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_2_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void lcu_common_ch_2_conf_ch_2_write_vci_setf(struct cl_chip *chip, u8 ch2writevci)
{
	ASSERT_ERR_CHIP((((u32)ch2writevci << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_2_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_2_CONF_ADDR) & ~((u32)0x00000004)) | ((u32)ch2writevci << 2));
}

static inline u8 lcu_common_ch_2_conf_ch_2_write_ts_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_2_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void lcu_common_ch_2_conf_ch_2_write_ts_setf(struct cl_chip *chip, u8 ch2writets)
{
	ASSERT_ERR_CHIP((((u32)ch2writets << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_2_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_2_CONF_ADDR) & ~((u32)0x00000002)) | ((u32)ch2writets << 1));
}

static inline u8 lcu_common_ch_2_conf_ch_2_rec_format_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_2_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void lcu_common_ch_2_conf_ch_2_rec_format_setf(struct cl_chip *chip, u8 ch2recformat)
{
	ASSERT_ERR_CHIP((((u32)ch2recformat << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_2_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_2_CONF_ADDR) & ~((u32)0x00000001)) | ((u32)ch2recformat << 0));
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
#define LCU_COMMON_CH_3_CONF_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000010C)
#define LCU_COMMON_CH_3_CONF_OFFSET      0x0000010C
#define LCU_COMMON_CH_3_CONF_INDEX       0x00000043
#define LCU_COMMON_CH_3_CONF_RESET       0x00000000

static inline u32 lcu_common_ch_3_conf_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_CH_3_CONF_ADDR);
}

static inline void lcu_common_ch_3_conf_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_CH_3_CONF_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_CH_3_CONF_CH_3_WRITE_VCI_BIT    ((u32)0x00000004)
#define LCU_COMMON_CH_3_CONF_CH_3_WRITE_VCI_POS    2
#define LCU_COMMON_CH_3_CONF_CH_3_WRITE_TS_BIT    ((u32)0x00000002)
#define LCU_COMMON_CH_3_CONF_CH_3_WRITE_TS_POS    1
#define LCU_COMMON_CH_3_CONF_CH_3_REC_FORMAT_BIT    ((u32)0x00000001)
#define LCU_COMMON_CH_3_CONF_CH_3_REC_FORMAT_POS    0

#define LCU_COMMON_CH_3_CONF_CH_3_WRITE_VCI_RST    0x0
#define LCU_COMMON_CH_3_CONF_CH_3_WRITE_TS_RST    0x0
#define LCU_COMMON_CH_3_CONF_CH_3_REC_FORMAT_RST    0x0

static inline void lcu_common_ch_3_conf_pack(struct cl_chip *chip, u8 ch3_write_vci, u8 ch3_write_ts, u8 ch3_rec_format)
{
	ASSERT_ERR_CHIP((((u32)ch3_write_vci << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)ch3_write_ts << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)ch3_rec_format << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_3_CONF_ADDR, ((u32)ch3_write_vci << 2) | ((u32)ch3_write_ts << 1) | ((u32)ch3_rec_format << 0));
}

static inline void lcu_common_ch_3_conf_unpack(struct cl_chip *chip, u8 *ch3_write_vci, u8 *ch3_write_ts, u8 *ch3_rec_format)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_3_CONF_ADDR);

	*ch3_write_vci = (local_val & ((u32)0x00000004)) >> 2;
	*ch3_write_ts = (local_val & ((u32)0x00000002)) >> 1;
	*ch3_rec_format = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_ch_3_conf_ch_3_write_vci_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_3_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void lcu_common_ch_3_conf_ch_3_write_vci_setf(struct cl_chip *chip, u8 ch3writevci)
{
	ASSERT_ERR_CHIP((((u32)ch3writevci << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_3_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_3_CONF_ADDR) & ~((u32)0x00000004)) | ((u32)ch3writevci << 2));
}

static inline u8 lcu_common_ch_3_conf_ch_3_write_ts_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_3_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void lcu_common_ch_3_conf_ch_3_write_ts_setf(struct cl_chip *chip, u8 ch3writets)
{
	ASSERT_ERR_CHIP((((u32)ch3writets << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_3_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_3_CONF_ADDR) & ~((u32)0x00000002)) | ((u32)ch3writets << 1));
}

static inline u8 lcu_common_ch_3_conf_ch_3_rec_format_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_3_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void lcu_common_ch_3_conf_ch_3_rec_format_setf(struct cl_chip *chip, u8 ch3recformat)
{
	ASSERT_ERR_CHIP((((u32)ch3recformat << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_3_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_3_CONF_ADDR) & ~((u32)0x00000001)) | ((u32)ch3recformat << 0));
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
#define LCU_COMMON_CH_4_CONF_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000110)
#define LCU_COMMON_CH_4_CONF_OFFSET      0x00000110
#define LCU_COMMON_CH_4_CONF_INDEX       0x00000044
#define LCU_COMMON_CH_4_CONF_RESET       0x00000000

static inline u32 lcu_common_ch_4_conf_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_CH_4_CONF_ADDR);
}

static inline void lcu_common_ch_4_conf_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_CH_4_CONF_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_CH_4_CONF_CH_4_WRITE_VCI_BIT    ((u32)0x00000004)
#define LCU_COMMON_CH_4_CONF_CH_4_WRITE_VCI_POS    2
#define LCU_COMMON_CH_4_CONF_CH_4_WRITE_TS_BIT    ((u32)0x00000002)
#define LCU_COMMON_CH_4_CONF_CH_4_WRITE_TS_POS    1
#define LCU_COMMON_CH_4_CONF_CH_4_REC_FORMAT_BIT    ((u32)0x00000001)
#define LCU_COMMON_CH_4_CONF_CH_4_REC_FORMAT_POS    0

#define LCU_COMMON_CH_4_CONF_CH_4_WRITE_VCI_RST    0x0
#define LCU_COMMON_CH_4_CONF_CH_4_WRITE_TS_RST    0x0
#define LCU_COMMON_CH_4_CONF_CH_4_REC_FORMAT_RST    0x0

static inline void lcu_common_ch_4_conf_pack(struct cl_chip *chip, u8 ch4_write_vci, u8 ch4_write_ts, u8 ch4_rec_format)
{
	ASSERT_ERR_CHIP((((u32)ch4_write_vci << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)ch4_write_ts << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)ch4_rec_format << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_4_CONF_ADDR, ((u32)ch4_write_vci << 2) | ((u32)ch4_write_ts << 1) | ((u32)ch4_rec_format << 0));
}

static inline void lcu_common_ch_4_conf_unpack(struct cl_chip *chip, u8 *ch4_write_vci, u8 *ch4_write_ts, u8 *ch4_rec_format)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_4_CONF_ADDR);

	*ch4_write_vci = (local_val & ((u32)0x00000004)) >> 2;
	*ch4_write_ts = (local_val & ((u32)0x00000002)) >> 1;
	*ch4_rec_format = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_ch_4_conf_ch_4_write_vci_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_4_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void lcu_common_ch_4_conf_ch_4_write_vci_setf(struct cl_chip *chip, u8 ch4writevci)
{
	ASSERT_ERR_CHIP((((u32)ch4writevci << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_4_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_4_CONF_ADDR) & ~((u32)0x00000004)) | ((u32)ch4writevci << 2));
}

static inline u8 lcu_common_ch_4_conf_ch_4_write_ts_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_4_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void lcu_common_ch_4_conf_ch_4_write_ts_setf(struct cl_chip *chip, u8 ch4writets)
{
	ASSERT_ERR_CHIP((((u32)ch4writets << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_4_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_4_CONF_ADDR) & ~((u32)0x00000002)) | ((u32)ch4writets << 1));
}

static inline u8 lcu_common_ch_4_conf_ch_4_rec_format_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_4_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void lcu_common_ch_4_conf_ch_4_rec_format_setf(struct cl_chip *chip, u8 ch4recformat)
{
	ASSERT_ERR_CHIP((((u32)ch4recformat << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_4_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_4_CONF_ADDR) & ~((u32)0x00000001)) | ((u32)ch4recformat << 0));
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
#define LCU_COMMON_CH_5_CONF_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000114)
#define LCU_COMMON_CH_5_CONF_OFFSET      0x00000114
#define LCU_COMMON_CH_5_CONF_INDEX       0x00000045
#define LCU_COMMON_CH_5_CONF_RESET       0x00000000

static inline u32 lcu_common_ch_5_conf_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_CH_5_CONF_ADDR);
}

static inline void lcu_common_ch_5_conf_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_CH_5_CONF_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_CH_5_CONF_CH_5_WRITE_VCI_BIT    ((u32)0x00000004)
#define LCU_COMMON_CH_5_CONF_CH_5_WRITE_VCI_POS    2
#define LCU_COMMON_CH_5_CONF_CH_5_WRITE_TS_BIT    ((u32)0x00000002)
#define LCU_COMMON_CH_5_CONF_CH_5_WRITE_TS_POS    1
#define LCU_COMMON_CH_5_CONF_CH_5_REC_FORMAT_BIT    ((u32)0x00000001)
#define LCU_COMMON_CH_5_CONF_CH_5_REC_FORMAT_POS    0

#define LCU_COMMON_CH_5_CONF_CH_5_WRITE_VCI_RST    0x0
#define LCU_COMMON_CH_5_CONF_CH_5_WRITE_TS_RST    0x0
#define LCU_COMMON_CH_5_CONF_CH_5_REC_FORMAT_RST    0x0

static inline void lcu_common_ch_5_conf_pack(struct cl_chip *chip, u8 ch5_write_vci, u8 ch5_write_ts, u8 ch5_rec_format)
{
	ASSERT_ERR_CHIP((((u32)ch5_write_vci << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)ch5_write_ts << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)ch5_rec_format << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_5_CONF_ADDR, ((u32)ch5_write_vci << 2) | ((u32)ch5_write_ts << 1) | ((u32)ch5_rec_format << 0));
}

static inline void lcu_common_ch_5_conf_unpack(struct cl_chip *chip, u8 *ch5_write_vci, u8 *ch5_write_ts, u8 *ch5_rec_format)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_5_CONF_ADDR);

	*ch5_write_vci = (local_val & ((u32)0x00000004)) >> 2;
	*ch5_write_ts = (local_val & ((u32)0x00000002)) >> 1;
	*ch5_rec_format = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_ch_5_conf_ch_5_write_vci_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_5_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void lcu_common_ch_5_conf_ch_5_write_vci_setf(struct cl_chip *chip, u8 ch5writevci)
{
	ASSERT_ERR_CHIP((((u32)ch5writevci << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_5_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_5_CONF_ADDR) & ~((u32)0x00000004)) | ((u32)ch5writevci << 2));
}

static inline u8 lcu_common_ch_5_conf_ch_5_write_ts_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_5_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void lcu_common_ch_5_conf_ch_5_write_ts_setf(struct cl_chip *chip, u8 ch5writets)
{
	ASSERT_ERR_CHIP((((u32)ch5writets << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_5_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_5_CONF_ADDR) & ~((u32)0x00000002)) | ((u32)ch5writets << 1));
}

static inline u8 lcu_common_ch_5_conf_ch_5_rec_format_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_CH_5_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void lcu_common_ch_5_conf_ch_5_rec_format_setf(struct cl_chip *chip, u8 ch5recformat)
{
	ASSERT_ERR_CHIP((((u32)ch5recformat << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_CH_5_CONF_ADDR, (cl_reg_read(chip, LCU_COMMON_CH_5_CONF_ADDR) & ~((u32)0x00000001)) | ((u32)ch5recformat << 0));
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
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000800)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_OFFSET      0x00000800
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_INDEX       0x00000200
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_CH_01_MASK_REG_0_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_CH_01_MASK_REG_0_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_CH_01_MASK_REG_0_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_CH_01_MASK_REG_0_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_0_ch_01_mask_reg_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_0_ch_01_mask_reg_0_setf(struct cl_chip *chip, u32 ch01maskreg0)
{
	ASSERT_ERR_CHIP((((u32)ch01maskreg0 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_0_ADDR, (u32)ch01maskreg0 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000804)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_OFFSET      0x00000804
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_INDEX       0x00000201
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_CH_01_MASK_REG_1_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_CH_01_MASK_REG_1_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_CH_01_MASK_REG_1_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_CH_01_MASK_REG_1_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_1_ch_01_mask_reg_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_1_ch_01_mask_reg_1_setf(struct cl_chip *chip, u32 ch01maskreg1)
{
	ASSERT_ERR_CHIP((((u32)ch01maskreg1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_1_ADDR, (u32)ch01maskreg1 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000808)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_OFFSET      0x00000808
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_INDEX       0x00000202
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_CH_01_MASK_REG_2_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_CH_01_MASK_REG_2_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_CH_01_MASK_REG_2_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_CH_01_MASK_REG_2_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_2_ch_01_mask_reg_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_2_ch_01_mask_reg_2_setf(struct cl_chip *chip, u32 ch01maskreg2)
{
	ASSERT_ERR_CHIP((((u32)ch01maskreg2 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_2_ADDR, (u32)ch01maskreg2 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000080C)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_OFFSET      0x0000080C
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_INDEX       0x00000203
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_CH_01_MASK_REG_3_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_CH_01_MASK_REG_3_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_CH_01_MASK_REG_3_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_CH_01_MASK_REG_3_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_3_ch_01_mask_reg_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_3_ch_01_mask_reg_3_setf(struct cl_chip *chip, u32 ch01maskreg3)
{
	ASSERT_ERR_CHIP((((u32)ch01maskreg3 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_3_ADDR, (u32)ch01maskreg3 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000810)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_OFFSET      0x00000810
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_INDEX       0x00000204
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_CH_01_MASK_REG_4_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_CH_01_MASK_REG_4_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_CH_01_MASK_REG_4_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_CH_01_MASK_REG_4_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_4_ch_01_mask_reg_4_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_4_ch_01_mask_reg_4_setf(struct cl_chip *chip, u32 ch01maskreg4)
{
	ASSERT_ERR_CHIP((((u32)ch01maskreg4 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_4_ADDR, (u32)ch01maskreg4 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000814)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_OFFSET      0x00000814
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_INDEX       0x00000205
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_CH_01_MASK_REG_5_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_CH_01_MASK_REG_5_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_CH_01_MASK_REG_5_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_CH_01_MASK_REG_5_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_5_ch_01_mask_reg_5_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_5_ch_01_mask_reg_5_setf(struct cl_chip *chip, u32 ch01maskreg5)
{
	ASSERT_ERR_CHIP((((u32)ch01maskreg5 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_5_ADDR, (u32)ch01maskreg5 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000818)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_OFFSET      0x00000818
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_INDEX       0x00000206
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_CH_01_MASK_REG_6_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_CH_01_MASK_REG_6_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_CH_01_MASK_REG_6_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_CH_01_MASK_REG_6_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_6_ch_01_mask_reg_6_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_6_ch_01_mask_reg_6_setf(struct cl_chip *chip, u32 ch01maskreg6)
{
	ASSERT_ERR_CHIP((((u32)ch01maskreg6 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_6_ADDR, (u32)ch01maskreg6 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000081C)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_OFFSET      0x0000081C
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_INDEX       0x00000207
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_CH_01_MASK_REG_7_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_CH_01_MASK_REG_7_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_CH_01_MASK_REG_7_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_CH_01_MASK_REG_7_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_mask_reg_7_ch_01_mask_reg_7_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_mask_reg_7_ch_01_mask_reg_7_setf(struct cl_chip *chip, u32 ch01maskreg7)
{
	ASSERT_ERR_CHIP((((u32)ch01maskreg7 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_MASK_REG_7_ADDR, (u32)ch01maskreg7 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_0_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000820)
#define LCU_COMMON_MAC_ELA_CH_0_EN_OFFSET      0x00000820
#define LCU_COMMON_MAC_ELA_CH_0_EN_INDEX       0x00000208
#define LCU_COMMON_MAC_ELA_CH_0_EN_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_0_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_0_EN_ADDR);
}

static inline void lcu_common_mac_ela_ch_0_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_0_EN_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_0_EN_CH_0_EN_BIT    ((u32)0x00000001)
#define LCU_COMMON_MAC_ELA_CH_0_EN_CH_0_EN_POS    0

#define LCU_COMMON_MAC_ELA_CH_0_EN_CH_0_EN_RST    0x0

static inline u8 lcu_common_mac_ela_ch_0_en_ch_0_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_0_EN_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_0_en_ch_0_en_setf(struct cl_chip *chip, u8 ch0en)
{
	ASSERT_ERR_CHIP((((u32)ch0en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_0_EN_ADDR, (u32)ch0en << 0);
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
#define LCU_COMMON_MAC_ELA_CH_1_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000824)
#define LCU_COMMON_MAC_ELA_CH_1_EN_OFFSET      0x00000824
#define LCU_COMMON_MAC_ELA_CH_1_EN_INDEX       0x00000209
#define LCU_COMMON_MAC_ELA_CH_1_EN_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_1_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_1_EN_ADDR);
}

static inline void lcu_common_mac_ela_ch_1_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_1_EN_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_1_EN_CH_1_EN_BIT    ((u32)0x00000001)
#define LCU_COMMON_MAC_ELA_CH_1_EN_CH_1_EN_POS    0

#define LCU_COMMON_MAC_ELA_CH_1_EN_CH_1_EN_RST    0x0

static inline u8 lcu_common_mac_ela_ch_1_en_ch_1_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_1_EN_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_1_en_ch_1_en_setf(struct cl_chip *chip, u8 ch1en)
{
	ASSERT_ERR_CHIP((((u32)ch1en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_1_EN_ADDR, (u32)ch1en << 0);
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
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000828)
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_OFFSET      0x00000828
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_INDEX       0x0000020A
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_0_select_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_0_SELECT_ADDR);
}

static inline void lcu_common_mac_ela_ch_0_select_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_0_SELECT_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_CH_0_SELECT_MASK    ((u32)0x0000003F)
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_CH_0_SELECT_LSB    0
#define LCU_COMMON_MAC_ELA_CH_0_SELECT_CH_0_SELECT_WIDTH    ((u32)0x00000006)

#define LCU_COMMON_MAC_ELA_CH_0_SELECT_CH_0_SELECT_RST    0x0

static inline u8 lcu_common_mac_ela_ch_0_select_ch_0_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_0_SELECT_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_0_select_ch_0_select_setf(struct cl_chip *chip, u8 ch0select)
{
	ASSERT_ERR_CHIP((((u32)ch0select << 0) & ~((u32)0x0000003F)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_0_SELECT_ADDR, (u32)ch0select << 0);
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
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000082C)
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_OFFSET      0x0000082C
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_INDEX       0x0000020B
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_1_select_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_1_SELECT_ADDR);
}

static inline void lcu_common_mac_ela_ch_1_select_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_1_SELECT_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_CH_1_SELECT_MASK    ((u32)0x0000001F)
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_CH_1_SELECT_LSB    0
#define LCU_COMMON_MAC_ELA_CH_1_SELECT_CH_1_SELECT_WIDTH    ((u32)0x00000005)

#define LCU_COMMON_MAC_ELA_CH_1_SELECT_CH_1_SELECT_RST    0x0

static inline u8 lcu_common_mac_ela_ch_1_select_ch_1_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_1_SELECT_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_1_select_ch_1_select_setf(struct cl_chip *chip, u8 ch1select)
{
	ASSERT_ERR_CHIP((((u32)ch1select << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_1_SELECT_ADDR, (u32)ch1select << 0);
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
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000830)
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_OFFSET      0x00000830
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_INDEX       0x0000020C
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_0_trig_mode_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_ADDR);
}

static inline void lcu_common_mac_ela_ch_0_trig_mode_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_CH_0_TRIG_MODE_BIT    ((u32)0x00000001)
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_CH_0_TRIG_MODE_POS    0

#define LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_CH_0_TRIG_MODE_RST    0x0

static inline u8 lcu_common_mac_ela_ch_0_trig_mode_ch_0_trig_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_0_trig_mode_ch_0_trig_mode_setf(struct cl_chip *chip, u8 ch0trigmode)
{
	ASSERT_ERR_CHIP((((u32)ch0trigmode << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_0_TRIG_MODE_ADDR, (u32)ch0trigmode << 0);
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
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000834)
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_OFFSET      0x00000834
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_INDEX       0x0000020D
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_1_trig_mode_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_ADDR);
}

static inline void lcu_common_mac_ela_ch_1_trig_mode_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_CH_1_TRIG_MODE_BIT    ((u32)0x00000001)
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_CH_1_TRIG_MODE_POS    0

#define LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_CH_1_TRIG_MODE_RST    0x0

static inline u8 lcu_common_mac_ela_ch_1_trig_mode_ch_1_trig_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_1_trig_mode_ch_1_trig_mode_setf(struct cl_chip *chip, u8 ch1trigmode)
{
	ASSERT_ERR_CHIP((((u32)ch1trigmode << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_1_TRIG_MODE_ADDR, (u32)ch1trigmode << 0);
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
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000838)
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_OFFSET      0x00000838
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_INDEX       0x0000020E
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_RESET       0x00000000

static inline void lcu_common_mac_ela_ch_0_trig_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_CH_0_TRIG_EN_BIT    ((u32)0x00000001)
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_CH_0_TRIG_EN_POS    0

#define LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_CH_0_TRIG_EN_RST    0x0

static inline void lcu_common_mac_ela_ch_0_trig_en_ch_0_trig_en_setf(struct cl_chip *chip, u8 ch0trigen)
{
	ASSERT_ERR_CHIP((((u32)ch0trigen << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_0_TRIG_EN_ADDR, (u32)ch0trigen << 0);
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
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000083C)
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_OFFSET      0x0000083C
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_INDEX       0x0000020F
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_RESET       0x00000000

static inline void lcu_common_mac_ela_ch_1_trig_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_CH_1_TRIG_EN_BIT    ((u32)0x00000001)
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_CH_1_TRIG_EN_POS    0

#define LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_CH_1_TRIG_EN_RST    0x0

static inline void lcu_common_mac_ela_ch_1_trig_en_ch_1_trig_en_setf(struct cl_chip *chip, u8 ch1trigen)
{
	ASSERT_ERR_CHIP((((u32)ch1trigen << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_1_TRIG_EN_ADDR, (u32)ch1trigen << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000840)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_OFFSET      0x00000840
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_INDEX       0x00000210
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_CH_01_TRIG_PTRN_REG_0_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_CH_01_TRIG_PTRN_REG_0_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_CH_01_TRIG_PTRN_REG_0_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_CH_01_TRIG_PTRN_REG_0_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_0_ch_01_trig_ptrn_reg_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_0_ch_01_trig_ptrn_reg_0_setf(struct cl_chip *chip, u32 ch01trigptrnreg0)
{
	ASSERT_ERR_CHIP((((u32)ch01trigptrnreg0 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_0_ADDR, (u32)ch01trigptrnreg0 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000844)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_OFFSET      0x00000844
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_INDEX       0x00000211
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_CH_01_TRIG_PTRN_REG_1_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_CH_01_TRIG_PTRN_REG_1_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_CH_01_TRIG_PTRN_REG_1_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_CH_01_TRIG_PTRN_REG_1_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_1_ch_01_trig_ptrn_reg_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_1_ch_01_trig_ptrn_reg_1_setf(struct cl_chip *chip, u32 ch01trigptrnreg1)
{
	ASSERT_ERR_CHIP((((u32)ch01trigptrnreg1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_1_ADDR, (u32)ch01trigptrnreg1 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000848)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_OFFSET      0x00000848
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_INDEX       0x00000212
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_CH_01_TRIG_PTRN_REG_2_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_CH_01_TRIG_PTRN_REG_2_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_CH_01_TRIG_PTRN_REG_2_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_CH_01_TRIG_PTRN_REG_2_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_2_ch_01_trig_ptrn_reg_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_2_ch_01_trig_ptrn_reg_2_setf(struct cl_chip *chip, u32 ch01trigptrnreg2)
{
	ASSERT_ERR_CHIP((((u32)ch01trigptrnreg2 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_2_ADDR, (u32)ch01trigptrnreg2 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000084C)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_OFFSET      0x0000084C
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_INDEX       0x00000213
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_CH_01_TRIG_PTRN_REG_3_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_CH_01_TRIG_PTRN_REG_3_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_CH_01_TRIG_PTRN_REG_3_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_CH_01_TRIG_PTRN_REG_3_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_3_ch_01_trig_ptrn_reg_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_3_ch_01_trig_ptrn_reg_3_setf(struct cl_chip *chip, u32 ch01trigptrnreg3)
{
	ASSERT_ERR_CHIP((((u32)ch01trigptrnreg3 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_3_ADDR, (u32)ch01trigptrnreg3 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000850)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_OFFSET      0x00000850
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_INDEX       0x00000214
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_CH_01_TRIG_PTRN_REG_4_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_CH_01_TRIG_PTRN_REG_4_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_CH_01_TRIG_PTRN_REG_4_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_CH_01_TRIG_PTRN_REG_4_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_4_ch_01_trig_ptrn_reg_4_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_4_ch_01_trig_ptrn_reg_4_setf(struct cl_chip *chip, u32 ch01trigptrnreg4)
{
	ASSERT_ERR_CHIP((((u32)ch01trigptrnreg4 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_4_ADDR, (u32)ch01trigptrnreg4 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000854)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_OFFSET      0x00000854
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_INDEX       0x00000215
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_CH_01_TRIG_PTRN_REG_5_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_CH_01_TRIG_PTRN_REG_5_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_CH_01_TRIG_PTRN_REG_5_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_CH_01_TRIG_PTRN_REG_5_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_5_ch_01_trig_ptrn_reg_5_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_5_ch_01_trig_ptrn_reg_5_setf(struct cl_chip *chip, u32 ch01trigptrnreg5)
{
	ASSERT_ERR_CHIP((((u32)ch01trigptrnreg5 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_5_ADDR, (u32)ch01trigptrnreg5 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000858)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_OFFSET      0x00000858
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_INDEX       0x00000216
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_CH_01_TRIG_PTRN_REG_6_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_CH_01_TRIG_PTRN_REG_6_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_CH_01_TRIG_PTRN_REG_6_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_CH_01_TRIG_PTRN_REG_6_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_6_ch_01_trig_ptrn_reg_6_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_6_ch_01_trig_ptrn_reg_6_setf(struct cl_chip *chip, u32 ch01trigptrnreg6)
{
	ASSERT_ERR_CHIP((((u32)ch01trigptrnreg6 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_6_ADDR, (u32)ch01trigptrnreg6 << 0);
}

/**
 * @brief MAC_ELA_CH_01_TRIG_PTRN_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_TRIG_PTRN_REG7       0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000085C)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_OFFSET      0x0000085C
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_INDEX       0x00000217
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_CH_01_TRIG_PTRN_REG_7_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_CH_01_TRIG_PTRN_REG_7_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_CH_01_TRIG_PTRN_REG_7_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_CH_01_TRIG_PTRN_REG_7_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_ptrn_reg_7_ch_01_trig_ptrn_reg_7_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_ptrn_reg_7_ch_01_trig_ptrn_reg_7_setf(struct cl_chip *chip, u32 ch01trigptrnreg7)
{
	ASSERT_ERR_CHIP((((u32)ch01trigptrnreg7 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_PTRN_REG_7_ADDR, (u32)ch01trigptrnreg7 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000860)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_OFFSET      0x00000860
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_INDEX       0x00000218
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_CH_01_TRIG_MASK_REG_0_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_CH_01_TRIG_MASK_REG_0_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_CH_01_TRIG_MASK_REG_0_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_CH_01_TRIG_MASK_REG_0_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_0_ch_01_trig_mask_reg_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_0_ch_01_trig_mask_reg_0_setf(struct cl_chip *chip, u32 ch01trigmaskreg0)
{
	ASSERT_ERR_CHIP((((u32)ch01trigmaskreg0 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_0_ADDR, (u32)ch01trigmaskreg0 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000864)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_OFFSET      0x00000864
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_INDEX       0x00000219
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_CH_01_TRIG_MASK_REG_1_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_CH_01_TRIG_MASK_REG_1_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_CH_01_TRIG_MASK_REG_1_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_CH_01_TRIG_MASK_REG_1_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_1_ch_01_trig_mask_reg_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_1_ch_01_trig_mask_reg_1_setf(struct cl_chip *chip, u32 ch01trigmaskreg1)
{
	ASSERT_ERR_CHIP((((u32)ch01trigmaskreg1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_1_ADDR, (u32)ch01trigmaskreg1 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000868)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_OFFSET      0x00000868
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_INDEX       0x0000021A
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_CH_01_TRIG_MASK_REG_2_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_CH_01_TRIG_MASK_REG_2_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_CH_01_TRIG_MASK_REG_2_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_CH_01_TRIG_MASK_REG_2_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_2_ch_01_trig_mask_reg_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_2_ch_01_trig_mask_reg_2_setf(struct cl_chip *chip, u32 ch01trigmaskreg2)
{
	ASSERT_ERR_CHIP((((u32)ch01trigmaskreg2 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_2_ADDR, (u32)ch01trigmaskreg2 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000086C)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_OFFSET      0x0000086C
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_INDEX       0x0000021B
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_CH_01_TRIG_MASK_REG_3_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_CH_01_TRIG_MASK_REG_3_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_CH_01_TRIG_MASK_REG_3_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_CH_01_TRIG_MASK_REG_3_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_3_ch_01_trig_mask_reg_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_3_ch_01_trig_mask_reg_3_setf(struct cl_chip *chip, u32 ch01trigmaskreg3)
{
	ASSERT_ERR_CHIP((((u32)ch01trigmaskreg3 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_3_ADDR, (u32)ch01trigmaskreg3 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000870)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_OFFSET      0x00000870
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_INDEX       0x0000021C
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_CH_01_TRIG_MASK_REG_4_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_CH_01_TRIG_MASK_REG_4_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_CH_01_TRIG_MASK_REG_4_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_CH_01_TRIG_MASK_REG_4_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_4_ch_01_trig_mask_reg_4_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_4_ch_01_trig_mask_reg_4_setf(struct cl_chip *chip, u32 ch01trigmaskreg4)
{
	ASSERT_ERR_CHIP((((u32)ch01trigmaskreg4 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_4_ADDR, (u32)ch01trigmaskreg4 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000874)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_OFFSET      0x00000874
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_INDEX       0x0000021D
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_CH_01_TRIG_MASK_REG_5_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_CH_01_TRIG_MASK_REG_5_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_CH_01_TRIG_MASK_REG_5_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_CH_01_TRIG_MASK_REG_5_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_5_ch_01_trig_mask_reg_5_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_5_ch_01_trig_mask_reg_5_setf(struct cl_chip *chip, u32 ch01trigmaskreg5)
{
	ASSERT_ERR_CHIP((((u32)ch01trigmaskreg5 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_5_ADDR, (u32)ch01trigmaskreg5 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000878)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_OFFSET      0x00000878
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_INDEX       0x0000021E
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_CH_01_TRIG_MASK_REG_6_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_CH_01_TRIG_MASK_REG_6_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_CH_01_TRIG_MASK_REG_6_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_CH_01_TRIG_MASK_REG_6_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_6_ch_01_trig_mask_reg_6_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_6_ch_01_trig_mask_reg_6_setf(struct cl_chip *chip, u32 ch01trigmaskreg6)
{
	ASSERT_ERR_CHIP((((u32)ch01trigmaskreg6 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_6_ADDR, (u32)ch01trigmaskreg6 << 0);
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
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000087C)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_OFFSET      0x0000087C
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_INDEX       0x0000021F
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_ADDR);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_CH_01_TRIG_MASK_REG_7_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_CH_01_TRIG_MASK_REG_7_LSB    0
#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_CH_01_TRIG_MASK_REG_7_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_CH_01_TRIG_MASK_REG_7_RST    0x0

static inline u32 lcu_common_mac_ela_ch_01_trig_mask_reg_7_ch_01_trig_mask_reg_7_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_mac_ela_ch_01_trig_mask_reg_7_ch_01_trig_mask_reg_7_setf(struct cl_chip *chip, u32 ch01trigmaskreg7)
{
	ASSERT_ERR_CHIP((((u32)ch01trigmaskreg7 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_MAC_ELA_CH_01_TRIG_MASK_REG_7_ADDR, (u32)ch01trigmaskreg7 << 0);
}

/**
 * @brief MAC_ELA_CH_0_TRIG_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 TRIG_STATUS               0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000880)
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_OFFSET      0x00000880
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_INDEX       0x00000220
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_0_trig_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_ADDR);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_TRIG_STATUS_MASK    ((u32)0x00000003)
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_TRIG_STATUS_LSB    0
#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_TRIG_STATUS_WIDTH    ((u32)0x00000002)

#define LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_TRIG_STATUS_RST    0x0

static inline u8 lcu_common_mac_ela_ch_0_trig_status_trig_status_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_0_TRIG_STATUS_ADDR);

	return (u8)(local_val >> 0);
}

/**
 * @brief MAC_ELA_CH_1_TRIG_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 TRIG_STATUS               0x0
 * </pre>
 */
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000884)
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_OFFSET      0x00000884
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_INDEX       0x00000221
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_RESET       0x00000000

static inline u32 lcu_common_mac_ela_ch_1_trig_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_ADDR);
}

/* field definitions */
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_TRIG_STATUS_MASK    ((u32)0x00000003)
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_TRIG_STATUS_LSB    0
#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_TRIG_STATUS_WIDTH    ((u32)0x00000002)

#define LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_TRIG_STATUS_RST    0x0

static inline u8 lcu_common_mac_ela_ch_1_trig_status_trig_status_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_MAC_ELA_CH_1_TRIG_STATUS_ADDR);

	return (u8)(local_val >> 0);
}

/**
 * @brief LCU_BT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    LCU_BT_EN                 0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000900)
#define LCU_COMMON_LCU_BT_EN_OFFSET      0x00000900
#define LCU_COMMON_LCU_BT_EN_INDEX       0x00000240
#define LCU_COMMON_LCU_BT_EN_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_EN_ADDR);
}

static inline void lcu_common_lcu_bt_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_EN_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_EN_LCU_BT_EN_BIT    ((u32)0x00000001)
#define LCU_COMMON_LCU_BT_EN_LCU_BT_EN_POS    0

#define LCU_COMMON_LCU_BT_EN_LCU_BT_EN_RST    0x0

static inline u8 lcu_common_lcu_bt_en_lcu_bt_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_EN_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_en_lcu_bt_en_setf(struct cl_chip *chip, u8 lcubten)
{
	ASSERT_ERR_CHIP((((u32)lcubten << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_EN_ADDR, (u32)lcubten << 0);
}

/**
 * @brief LCU_BT_START register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    LCU_BT_START              0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000904)
#define LCU_COMMON_LCU_BT_START_OFFSET      0x00000904
#define LCU_COMMON_LCU_BT_START_INDEX       0x00000241
#define LCU_COMMON_LCU_BT_START_RESET       0x00000000

static inline void lcu_common_lcu_bt_start_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_START_LCU_BT_START_BIT    ((u32)0x00000001)
#define LCU_COMMON_LCU_BT_START_LCU_BT_START_POS    0

#define LCU_COMMON_LCU_BT_START_LCU_BT_START_RST    0x0

static inline void lcu_common_lcu_bt_start_lcu_bt_start_setf(struct cl_chip *chip, u8 lcubtstart)
{
	ASSERT_ERR_CHIP((((u32)lcubtstart << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_ADDR, (u32)lcubtstart << 0);
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
#define LCU_COMMON_LCU_BT_START_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000908)
#define LCU_COMMON_LCU_BT_START_EN_OFFSET      0x00000908
#define LCU_COMMON_LCU_BT_START_EN_INDEX       0x00000242
#define LCU_COMMON_LCU_BT_START_EN_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_start_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_START_EN_ADDR);
}

static inline void lcu_common_lcu_bt_start_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_EN_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_START_EN_LCU_BT_EXT_STRT_EN_BIT    ((u32)0x00000002)
#define LCU_COMMON_LCU_BT_START_EN_LCU_BT_EXT_STRT_EN_POS    1
#define LCU_COMMON_LCU_BT_START_EN_LCU_BT_STRT_PTRN_EN_BIT    ((u32)0x00000001)
#define LCU_COMMON_LCU_BT_START_EN_LCU_BT_STRT_PTRN_EN_POS    0

#define LCU_COMMON_LCU_BT_START_EN_LCU_BT_EXT_STRT_EN_RST    0x0
#define LCU_COMMON_LCU_BT_START_EN_LCU_BT_STRT_PTRN_EN_RST    0x0

static inline void lcu_common_lcu_bt_start_en_pack(struct cl_chip *chip, u8 lcu_bt_ext_strt_en, u8 lcu_bt_strt_ptrn_en)
{
	ASSERT_ERR_CHIP((((u32)lcu_bt_ext_strt_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)lcu_bt_strt_ptrn_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_EN_ADDR, ((u32)lcu_bt_ext_strt_en << 1) | ((u32)lcu_bt_strt_ptrn_en << 0));
}

static inline void lcu_common_lcu_bt_start_en_unpack(struct cl_chip *chip, u8 *lcu_bt_ext_strt_en, u8 *lcu_bt_strt_ptrn_en)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_START_EN_ADDR);

	*lcu_bt_ext_strt_en = (local_val & ((u32)0x00000002)) >> 1;
	*lcu_bt_strt_ptrn_en = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_lcu_bt_start_en_lcu_bt_ext_strt_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_START_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void lcu_common_lcu_bt_start_en_lcu_bt_ext_strt_en_setf(struct cl_chip *chip, u8 lcubtextstrten)
{
	ASSERT_ERR_CHIP((((u32)lcubtextstrten << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_LCU_BT_START_EN_ADDR) & ~((u32)0x00000002)) | ((u32)lcubtextstrten << 1));
}

static inline u8 lcu_common_lcu_bt_start_en_lcu_bt_strt_ptrn_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_START_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void lcu_common_lcu_bt_start_en_lcu_bt_strt_ptrn_en_setf(struct cl_chip *chip, u8 lcubtstrtptrnen)
{
	ASSERT_ERR_CHIP((((u32)lcubtstrtptrnen << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_LCU_BT_START_EN_ADDR) & ~((u32)0x00000001)) | ((u32)lcubtstrtptrnen << 0));
}

/**
 * @brief LCU_BT_START_PTRN_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_START_PTRN         0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000090C)
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_OFFSET      0x0000090C
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_INDEX       0x00000243
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_start_ptrn_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_START_PTRN_REG_0_ADDR);
}

static inline void lcu_common_lcu_bt_start_ptrn_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_PTRN_REG_0_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_LCU_BT_START_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_LCU_BT_START_PTRN_LSB    0
#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_LCU_BT_START_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_LCU_BT_START_PTRN_REG_0_LCU_BT_START_PTRN_RST    0x0

static inline u32 lcu_common_lcu_bt_start_ptrn_reg_0_lcu_bt_start_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_START_PTRN_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_start_ptrn_reg_0_lcu_bt_start_ptrn_setf(struct cl_chip *chip, u32 lcubtstartptrn)
{
	ASSERT_ERR_CHIP((((u32)lcubtstartptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_PTRN_REG_0_ADDR, (u32)lcubtstartptrn << 0);
}

/**
 * @brief LCU_BT_START_PTRN_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_START_PTRN         0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000910)
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_OFFSET      0x00000910
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_INDEX       0x00000244
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_start_ptrn_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_START_PTRN_REG_1_ADDR);
}

static inline void lcu_common_lcu_bt_start_ptrn_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_PTRN_REG_1_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_LCU_BT_START_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_LCU_BT_START_PTRN_LSB    0
#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_LCU_BT_START_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_LCU_BT_START_PTRN_REG_1_LCU_BT_START_PTRN_RST    0x0

static inline u32 lcu_common_lcu_bt_start_ptrn_reg_1_lcu_bt_start_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_START_PTRN_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_start_ptrn_reg_1_lcu_bt_start_ptrn_setf(struct cl_chip *chip, u32 lcubtstartptrn)
{
	ASSERT_ERR_CHIP((((u32)lcubtstartptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_PTRN_REG_1_ADDR, (u32)lcubtstartptrn << 0);
}

/**
 * @brief LCU_BT_START_PTRN_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:00 LCU_BT_START_PTRN         0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000914)
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_OFFSET      0x00000914
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_INDEX       0x00000245
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_start_ptrn_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_START_PTRN_REG_2_ADDR);
}

static inline void lcu_common_lcu_bt_start_ptrn_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_PTRN_REG_2_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_LCU_BT_START_PTRN_MASK    ((u32)0x03FFFFFF)
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_LCU_BT_START_PTRN_LSB    0
#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_LCU_BT_START_PTRN_WIDTH    ((u32)0x0000001A)

#define LCU_COMMON_LCU_BT_START_PTRN_REG_2_LCU_BT_START_PTRN_RST    0x0

static inline u32 lcu_common_lcu_bt_start_ptrn_reg_2_lcu_bt_start_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_START_PTRN_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_start_ptrn_reg_2_lcu_bt_start_ptrn_setf(struct cl_chip *chip, u32 lcubtstartptrn)
{
	ASSERT_ERR_CHIP((((u32)lcubtstartptrn << 0) & ~((u32)0x03FFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_PTRN_REG_2_ADDR, (u32)lcubtstartptrn << 0);
}

/**
 * @brief LCU_BT_START_PTRN_MASK_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_START_PTRN_MASK    0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000918)
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_OFFSET      0x00000918
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_INDEX       0x00000246
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_start_ptrn_mask_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_ADDR);
}

static inline void lcu_common_lcu_bt_start_ptrn_mask_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_LCU_BT_START_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_LCU_BT_START_PTRN_MASK_LSB    0
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_LCU_BT_START_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_LCU_BT_START_PTRN_MASK_RST    0x0

static inline u32 lcu_common_lcu_bt_start_ptrn_mask_reg_0_lcu_bt_start_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_start_ptrn_mask_reg_0_lcu_bt_start_ptrn_mask_setf(struct cl_chip *chip, u32 lcubtstartptrnmask)
{
	ASSERT_ERR_CHIP((((u32)lcubtstartptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_0_ADDR, (u32)lcubtstartptrnmask << 0);
}

/**
 * @brief LCU_BT_START_PTRN_MASK_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_START_PTRN_MASK    0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000091C)
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_OFFSET      0x0000091C
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_INDEX       0x00000247
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_start_ptrn_mask_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_ADDR);
}

static inline void lcu_common_lcu_bt_start_ptrn_mask_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_LCU_BT_START_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_LCU_BT_START_PTRN_MASK_LSB    0
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_LCU_BT_START_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_LCU_BT_START_PTRN_MASK_RST    0x0

static inline u32 lcu_common_lcu_bt_start_ptrn_mask_reg_1_lcu_bt_start_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_start_ptrn_mask_reg_1_lcu_bt_start_ptrn_mask_setf(struct cl_chip *chip, u32 lcubtstartptrnmask)
{
	ASSERT_ERR_CHIP((((u32)lcubtstartptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_1_ADDR, (u32)lcubtstartptrnmask << 0);
}

/**
 * @brief LCU_BT_START_PTRN_MASK_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:00 LCU_BT_START_PTRN_MASK    0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000920)
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_OFFSET      0x00000920
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_INDEX       0x00000248
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_start_ptrn_mask_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_ADDR);
}

static inline void lcu_common_lcu_bt_start_ptrn_mask_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_LCU_BT_START_PTRN_MASK_MASK    ((u32)0x03FFFFFF)
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_LCU_BT_START_PTRN_MASK_LSB    0
#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_LCU_BT_START_PTRN_MASK_WIDTH    ((u32)0x0000001A)

#define LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_LCU_BT_START_PTRN_MASK_RST    0x0

static inline u32 lcu_common_lcu_bt_start_ptrn_mask_reg_2_lcu_bt_start_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_start_ptrn_mask_reg_2_lcu_bt_start_ptrn_mask_setf(struct cl_chip *chip, u32 lcubtstartptrnmask)
{
	ASSERT_ERR_CHIP((((u32)lcubtstartptrnmask << 0) & ~((u32)0x03FFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_START_PTRN_MASK_REG_2_ADDR, (u32)lcubtstartptrnmask << 0);
}

/**
 * @brief LCU_BT_STOP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    LCU_BT_STOP               0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000924)
#define LCU_COMMON_LCU_BT_STOP_OFFSET      0x00000924
#define LCU_COMMON_LCU_BT_STOP_INDEX       0x00000249
#define LCU_COMMON_LCU_BT_STOP_RESET       0x00000000

static inline void lcu_common_lcu_bt_stop_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_STOP_LCU_BT_STOP_BIT    ((u32)0x00000001)
#define LCU_COMMON_LCU_BT_STOP_LCU_BT_STOP_POS    0

#define LCU_COMMON_LCU_BT_STOP_LCU_BT_STOP_RST    0x0

static inline void lcu_common_lcu_bt_stop_lcu_bt_stop_setf(struct cl_chip *chip, u8 lcubtstop)
{
	ASSERT_ERR_CHIP((((u32)lcubtstop << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_ADDR, (u32)lcubtstop << 0);
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
#define LCU_COMMON_LCU_BT_STOP_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000928)
#define LCU_COMMON_LCU_BT_STOP_EN_OFFSET      0x00000928
#define LCU_COMMON_LCU_BT_STOP_EN_INDEX       0x0000024A
#define LCU_COMMON_LCU_BT_STOP_EN_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_stop_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_EN_ADDR);
}

static inline void lcu_common_lcu_bt_stop_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_EN_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_STOP_EN_LCU_BT_EXT_STOP_EN_BIT    ((u32)0x00000002)
#define LCU_COMMON_LCU_BT_STOP_EN_LCU_BT_EXT_STOP_EN_POS    1
#define LCU_COMMON_LCU_BT_STOP_EN_LCU_BT_STOP_PTRN_EN_BIT    ((u32)0x00000001)
#define LCU_COMMON_LCU_BT_STOP_EN_LCU_BT_STOP_PTRN_EN_POS    0

#define LCU_COMMON_LCU_BT_STOP_EN_LCU_BT_EXT_STOP_EN_RST    0x0
#define LCU_COMMON_LCU_BT_STOP_EN_LCU_BT_STOP_PTRN_EN_RST    0x0

static inline void lcu_common_lcu_bt_stop_en_pack(struct cl_chip *chip, u8 lcu_bt_ext_stop_en, u8 lcu_bt_stop_ptrn_en)
{
	ASSERT_ERR_CHIP((((u32)lcu_bt_ext_stop_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)lcu_bt_stop_ptrn_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_EN_ADDR, ((u32)lcu_bt_ext_stop_en << 1) | ((u32)lcu_bt_stop_ptrn_en << 0));
}

static inline void lcu_common_lcu_bt_stop_en_unpack(struct cl_chip *chip, u8 *lcu_bt_ext_stop_en, u8 *lcu_bt_stop_ptrn_en)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_EN_ADDR);

	*lcu_bt_ext_stop_en = (local_val & ((u32)0x00000002)) >> 1;
	*lcu_bt_stop_ptrn_en = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_lcu_bt_stop_en_lcu_bt_ext_stop_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void lcu_common_lcu_bt_stop_en_lcu_bt_ext_stop_en_setf(struct cl_chip *chip, u8 lcubtextstopen)
{
	ASSERT_ERR_CHIP((((u32)lcubtextstopen << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_EN_ADDR) & ~((u32)0x00000002)) | ((u32)lcubtextstopen << 1));
}

static inline u8 lcu_common_lcu_bt_stop_en_lcu_bt_stop_ptrn_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void lcu_common_lcu_bt_stop_en_lcu_bt_stop_ptrn_en_setf(struct cl_chip *chip, u8 lcubtstopptrnen)
{
	ASSERT_ERR_CHIP((((u32)lcubtstopptrnen << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_EN_ADDR, (cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_EN_ADDR) & ~((u32)0x00000001)) | ((u32)lcubtstopptrnen << 0));
}

/**
 * @brief LCU_BT_STOP_PTRN_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_STOP_PTRN          0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000092C)
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_OFFSET      0x0000092C
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_INDEX       0x0000024B
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_stop_ptrn_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_ADDR);
}

static inline void lcu_common_lcu_bt_stop_ptrn_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_LCU_BT_STOP_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_LCU_BT_STOP_PTRN_LSB    0
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_LCU_BT_STOP_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_LCU_BT_STOP_PTRN_RST    0x0

static inline u32 lcu_common_lcu_bt_stop_ptrn_reg_0_lcu_bt_stop_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_stop_ptrn_reg_0_lcu_bt_stop_ptrn_setf(struct cl_chip *chip, u32 lcubtstopptrn)
{
	ASSERT_ERR_CHIP((((u32)lcubtstopptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_PTRN_REG_0_ADDR, (u32)lcubtstopptrn << 0);
}

/**
 * @brief LCU_BT_STOP_PTRN_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_STOP_PTRN          0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000930)
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_OFFSET      0x00000930
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_INDEX       0x0000024C
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_stop_ptrn_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_ADDR);
}

static inline void lcu_common_lcu_bt_stop_ptrn_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_LCU_BT_STOP_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_LCU_BT_STOP_PTRN_LSB    0
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_LCU_BT_STOP_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_LCU_BT_STOP_PTRN_RST    0x0

static inline u32 lcu_common_lcu_bt_stop_ptrn_reg_1_lcu_bt_stop_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_stop_ptrn_reg_1_lcu_bt_stop_ptrn_setf(struct cl_chip *chip, u32 lcubtstopptrn)
{
	ASSERT_ERR_CHIP((((u32)lcubtstopptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_PTRN_REG_1_ADDR, (u32)lcubtstopptrn << 0);
}

/**
 * @brief LCU_BT_STOP_PTRN_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:00 LCU_BT_STOP_PTRN          0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000934)
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_OFFSET      0x00000934
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_INDEX       0x0000024D
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_stop_ptrn_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_ADDR);
}

static inline void lcu_common_lcu_bt_stop_ptrn_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_LCU_BT_STOP_PTRN_MASK    ((u32)0x03FFFFFF)
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_LCU_BT_STOP_PTRN_LSB    0
#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_LCU_BT_STOP_PTRN_WIDTH    ((u32)0x0000001A)

#define LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_LCU_BT_STOP_PTRN_RST    0x0

static inline u32 lcu_common_lcu_bt_stop_ptrn_reg_2_lcu_bt_stop_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_stop_ptrn_reg_2_lcu_bt_stop_ptrn_setf(struct cl_chip *chip, u32 lcubtstopptrn)
{
	ASSERT_ERR_CHIP((((u32)lcubtstopptrn << 0) & ~((u32)0x03FFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_PTRN_REG_2_ADDR, (u32)lcubtstopptrn << 0);
}

/**
 * @brief LCU_BT_STOP_PTRN_MASK_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_STOP_PTRN_MASK     0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000938)
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_OFFSET      0x00000938
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_INDEX       0x0000024E
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_stop_ptrn_mask_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_ADDR);
}

static inline void lcu_common_lcu_bt_stop_ptrn_mask_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_LCU_BT_STOP_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_LCU_BT_STOP_PTRN_MASK_LSB    0
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_LCU_BT_STOP_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_LCU_BT_STOP_PTRN_MASK_RST    0x0

static inline u32 lcu_common_lcu_bt_stop_ptrn_mask_reg_0_lcu_bt_stop_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_stop_ptrn_mask_reg_0_lcu_bt_stop_ptrn_mask_setf(struct cl_chip *chip, u32 lcubtstopptrnmask)
{
	ASSERT_ERR_CHIP((((u32)lcubtstopptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_0_ADDR, (u32)lcubtstopptrnmask << 0);
}

/**
 * @brief LCU_BT_STOP_PTRN_MASK_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LCU_BT_STOP_PTRN_MASK     0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000093C)
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_OFFSET      0x0000093C
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_INDEX       0x0000024F
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_stop_ptrn_mask_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_ADDR);
}

static inline void lcu_common_lcu_bt_stop_ptrn_mask_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_LCU_BT_STOP_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_LCU_BT_STOP_PTRN_MASK_LSB    0
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_LCU_BT_STOP_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_LCU_BT_STOP_PTRN_MASK_RST    0x0

static inline u32 lcu_common_lcu_bt_stop_ptrn_mask_reg_1_lcu_bt_stop_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_stop_ptrn_mask_reg_1_lcu_bt_stop_ptrn_mask_setf(struct cl_chip *chip, u32 lcubtstopptrnmask)
{
	ASSERT_ERR_CHIP((((u32)lcubtstopptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_1_ADDR, (u32)lcubtstopptrnmask << 0);
}

/**
 * @brief LCU_BT_STOP_PTRN_MASK_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:00 LCU_BT_STOP_PTRN_MASK     0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000940)
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_OFFSET      0x00000940
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_INDEX       0x00000250
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_stop_ptrn_mask_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_ADDR);
}

static inline void lcu_common_lcu_bt_stop_ptrn_mask_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_LCU_BT_STOP_PTRN_MASK_MASK    ((u32)0x03FFFFFF)
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_LCU_BT_STOP_PTRN_MASK_LSB    0
#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_LCU_BT_STOP_PTRN_MASK_WIDTH    ((u32)0x0000001A)

#define LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_LCU_BT_STOP_PTRN_MASK_RST    0x0

static inline u32 lcu_common_lcu_bt_stop_ptrn_mask_reg_2_lcu_bt_stop_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_stop_ptrn_mask_reg_2_lcu_bt_stop_ptrn_mask_setf(struct cl_chip *chip, u32 lcubtstopptrnmask)
{
	ASSERT_ERR_CHIP((((u32)lcubtstopptrnmask << 0) & ~((u32)0x03FFFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_STOP_PTRN_MASK_REG_2_ADDR, (u32)lcubtstopptrnmask << 0);
}

/**
 * @brief LCU_BT_CH_VALID register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 LCU_BT_CH_VALID           0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_CH_VALID_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000944)
#define LCU_COMMON_LCU_BT_CH_VALID_OFFSET      0x00000944
#define LCU_COMMON_LCU_BT_CH_VALID_INDEX       0x00000251
#define LCU_COMMON_LCU_BT_CH_VALID_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_ch_valid_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_CH_VALID_ADDR);
}

static inline void lcu_common_lcu_bt_ch_valid_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_CH_VALID_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_CH_VALID_LCU_BT_CH_VALID_MASK    ((u32)0x000FFFFF)
#define LCU_COMMON_LCU_BT_CH_VALID_LCU_BT_CH_VALID_LSB    0
#define LCU_COMMON_LCU_BT_CH_VALID_LCU_BT_CH_VALID_WIDTH    ((u32)0x00000014)

#define LCU_COMMON_LCU_BT_CH_VALID_LCU_BT_CH_VALID_RST    0x0

static inline u32 lcu_common_lcu_bt_ch_valid_lcu_bt_ch_valid_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_CH_VALID_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_ch_valid_lcu_bt_ch_valid_setf(struct cl_chip *chip, u32 lcubtchvalid)
{
	ASSERT_ERR_CHIP((((u32)lcubtchvalid << 0) & ~((u32)0x000FFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_CH_VALID_ADDR, (u32)lcubtchvalid << 0);
}

/**
 * @brief LCU_BT_CTPREV_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 LCU_BT_CTPREV_EN          0x0
 * </pre>
 */
#define LCU_COMMON_LCU_BT_CTPREV_EN_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000948)
#define LCU_COMMON_LCU_BT_CTPREV_EN_OFFSET      0x00000948
#define LCU_COMMON_LCU_BT_CTPREV_EN_INDEX       0x00000252
#define LCU_COMMON_LCU_BT_CTPREV_EN_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_ctprev_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_CTPREV_EN_ADDR);
}

static inline void lcu_common_lcu_bt_ctprev_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_CTPREV_EN_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_CTPREV_EN_LCU_BT_CTPREV_EN_MASK    ((u32)0x000FFFFF)
#define LCU_COMMON_LCU_BT_CTPREV_EN_LCU_BT_CTPREV_EN_LSB    0
#define LCU_COMMON_LCU_BT_CTPREV_EN_LCU_BT_CTPREV_EN_WIDTH    ((u32)0x00000014)

#define LCU_COMMON_LCU_BT_CTPREV_EN_LCU_BT_CTPREV_EN_RST    0x0

static inline u32 lcu_common_lcu_bt_ctprev_en_lcu_bt_ctprev_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_CTPREV_EN_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_common_lcu_bt_ctprev_en_lcu_bt_ctprev_en_setf(struct cl_chip *chip, u32 lcubtctpreven)
{
	ASSERT_ERR_CHIP((((u32)lcubtctpreven << 0) & ~((u32)0x000FFFFF)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_CTPREV_EN_ADDR, (u32)lcubtctpreven << 0);
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
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x0000094C)
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_OFFSET      0x0000094C
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_INDEX       0x00000253
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_ptrn_match_sel_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR);
}

static inline void lcu_common_lcu_bt_ptrn_match_sel_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR, value);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_STOP_PTRN_MATCH_SEL_BIT    ((u32)0x00000002)
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_STOP_PTRN_MATCH_SEL_POS    1
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_STRT_PTRN_MATCH_SEL_BIT    ((u32)0x00000001)
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_STRT_PTRN_MATCH_SEL_POS    0

#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_STOP_PTRN_MATCH_SEL_RST    0x0
#define LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_STRT_PTRN_MATCH_SEL_RST    0x0

static inline void lcu_common_lcu_bt_ptrn_match_sel_pack(struct cl_chip *chip, u8 stop_ptrn_match_sel, u8 strt_ptrn_match_sel)
{
	ASSERT_ERR_CHIP((((u32)stop_ptrn_match_sel << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)strt_ptrn_match_sel << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR, ((u32)stop_ptrn_match_sel << 1) | ((u32)strt_ptrn_match_sel << 0));
}

static inline void lcu_common_lcu_bt_ptrn_match_sel_unpack(struct cl_chip *chip, u8 *stop_ptrn_match_sel, u8 *strt_ptrn_match_sel)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR);

	*stop_ptrn_match_sel = (local_val & ((u32)0x00000002)) >> 1;
	*strt_ptrn_match_sel = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_common_lcu_bt_ptrn_match_sel_stop_ptrn_match_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void lcu_common_lcu_bt_ptrn_match_sel_stop_ptrn_match_sel_setf(struct cl_chip *chip, u8 stopptrnmatchsel)
{
	ASSERT_ERR_CHIP((((u32)stopptrnmatchsel << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR, (cl_reg_read(chip, LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR) & ~((u32)0x00000002)) | ((u32)stopptrnmatchsel << 1));
}

static inline u8 lcu_common_lcu_bt_ptrn_match_sel_strt_ptrn_match_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void lcu_common_lcu_bt_ptrn_match_sel_strt_ptrn_match_sel_setf(struct cl_chip *chip, u8 strtptrnmatchsel)
{
	ASSERT_ERR_CHIP((((u32)strtptrnmatchsel << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR, (cl_reg_read(chip, LCU_COMMON_LCU_BT_PTRN_MATCH_SEL_ADDR) & ~((u32)0x00000001)) | ((u32)strtptrnmatchsel << 0));
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
#define LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR        (REG_LCU_COMMON_BASE_ADDR + 0x00000950)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_OFFSET      0x00000950
#define LCU_COMMON_LCU_BT_TRIG_STATUS_INDEX       0x00000254
#define LCU_COMMON_LCU_BT_TRIG_STATUS_RESET       0x00000000

static inline u32 lcu_common_lcu_bt_trig_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR);
}

/* field definitions */
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STOP_TRIG_STAT_MASK    ((u32)0x0000C000)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STOP_TRIG_STAT_LSB    14
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STOP_TRIG_STAT_WIDTH    ((u32)0x00000002)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STOP_PTRN_TRIG_STAT_MASK    ((u32)0x00000300)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STOP_PTRN_TRIG_STAT_LSB    8
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STOP_PTRN_TRIG_STAT_WIDTH    ((u32)0x00000002)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STRT_TRIG_STAT_MASK    ((u32)0x00000030)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STRT_TRIG_STAT_LSB    4
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STRT_TRIG_STAT_WIDTH    ((u32)0x00000002)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STRT_PTRN_TRIG_STAT_MASK    ((u32)0x00000003)
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STRT_PTRN_TRIG_STAT_LSB    0
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STRT_PTRN_TRIG_STAT_WIDTH    ((u32)0x00000002)

#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STOP_TRIG_STAT_RST    0x0
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STOP_PTRN_TRIG_STAT_RST    0x0
#define LCU_COMMON_LCU_BT_TRIG_STATUS_EXT_STRT_TRIG_STAT_RST    0x0
#define LCU_COMMON_LCU_BT_TRIG_STATUS_STRT_PTRN_TRIG_STAT_RST    0x0

static inline void lcu_common_lcu_bt_trig_status_unpack(struct cl_chip *chip, u8 *ext_stop_trig_stat, u8 *stop_ptrn_trig_stat, u8 *ext_strt_trig_stat, u8 *strt_ptrn_trig_stat)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR);

	*ext_stop_trig_stat = (local_val & ((u32)0x0000C000)) >> 14;
	*stop_ptrn_trig_stat = (local_val & ((u32)0x00000300)) >> 8;
	*ext_strt_trig_stat = (local_val & ((u32)0x00000030)) >> 4;
	*strt_ptrn_trig_stat = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u8 lcu_common_lcu_bt_trig_status_ext_stop_trig_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x0000C000)) >> 14);
}

static inline u8 lcu_common_lcu_bt_trig_status_stop_ptrn_trig_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000300)) >> 8);
}

static inline u8 lcu_common_lcu_bt_trig_status_ext_strt_trig_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000030)) >> 4);
}

static inline u8 lcu_common_lcu_bt_trig_status_strt_ptrn_trig_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_COMMON_LCU_BT_TRIG_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

#endif /* REG_LCU_COMMON_H */
