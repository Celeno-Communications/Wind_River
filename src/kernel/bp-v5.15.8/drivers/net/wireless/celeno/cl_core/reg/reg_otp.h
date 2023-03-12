/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef _REG_OTP_H_
#define _REG_OTP_H_

#include "chip.h"
#include "reg_access.h"

#define REG_OTP_BASE_ADDR 0x007C9000

/**
 * @brief OTP_CMD register definition
 *  OTP command register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 OTP_CMD                   0x0
 * </pre>
 */
#define OTP_OTP_CMD_ADDR        (REG_OTP_BASE_ADDR + 0x00000000)
#define OTP_OTP_CMD_OFFSET      0x00000000
#define OTP_OTP_CMD_INDEX       0x00000000
#define OTP_OTP_CMD_RESET       0x00000000

static inline void otp_otp_cmd_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, OTP_OTP_CMD_ADDR, value);
}

// field definitions
#define OTP_OTP_CMD_OTP_CMD_MASK            ((u32)0x00000003)
#define OTP_OTP_CMD_OTP_CMD_LSB             0
#define OTP_OTP_CMD_OTP_CMD_WIDTH           ((u32)0x00000002)

#define OTP_OTP_CMD_OTP_CMD_RST             0x0

static inline void otp_otp_cmd_otp_cmd_setf(struct cl_chip *chip, u8 otpcmd)
{
	ASSERT_ERR_CHIP((((u32)otpcmd << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, OTP_OTP_CMD_ADDR, (u32)otpcmd << 0);
}

/**
 * @brief OTP_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    OTP_PWOK                  1
 *    03    OTP_RD_DED                0
 *    02    OTP_RD_SEC                0
 *    01    OTP_READY                 1
 *    00    OTP_WRITE_FAILED          0
 * </pre>
 */
#define OTP_OTP_STAT_ADDR        (REG_OTP_BASE_ADDR + 0x00000004)
#define OTP_OTP_STAT_OFFSET      0x00000004
#define OTP_OTP_STAT_INDEX       0x00000001
#define OTP_OTP_STAT_RESET       0x00000012

static inline u32  otp_otp_stat_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, OTP_OTP_STAT_ADDR);
}

// field definitions
#define OTP_OTP_STAT_OTP_PWOK_BIT           ((u32)0x00000010)
#define OTP_OTP_STAT_OTP_PWOK_POS           4
#define OTP_OTP_STAT_OTP_RD_DED_BIT         ((u32)0x00000008)
#define OTP_OTP_STAT_OTP_RD_DED_POS         3
#define OTP_OTP_STAT_OTP_RD_SEC_BIT         ((u32)0x00000004)
#define OTP_OTP_STAT_OTP_RD_SEC_POS         2
#define OTP_OTP_STAT_OTP_READY_BIT          ((u32)0x00000002)
#define OTP_OTP_STAT_OTP_READY_POS          1
#define OTP_OTP_STAT_OTP_WRITE_FAILED_BIT    ((u32)0x00000001)
#define OTP_OTP_STAT_OTP_WRITE_FAILED_POS    0

#define OTP_OTP_STAT_OTP_PWOK_RST           0x1
#define OTP_OTP_STAT_OTP_RD_DED_RST         0x0
#define OTP_OTP_STAT_OTP_RD_SEC_RST         0x0
#define OTP_OTP_STAT_OTP_READY_RST          0x1
#define OTP_OTP_STAT_OTP_WRITE_FAILED_RST    0x0

static inline void otp_otp_stat_unpack(struct cl_chip *chip, u8 *otp_pwok, u8 *otp_rd_ded, u8 *otp_rd_sec, u8 *otp_ready, u8 *otp_write_failed)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_STAT_ADDR);

	*otp_pwok = (local_val & ((u32)0x00000010)) >> 4;
	*otp_rd_ded = (local_val & ((u32)0x00000008)) >> 3;
	*otp_rd_sec = (local_val & ((u32)0x00000004)) >> 2;
	*otp_ready = (local_val & ((u32)0x00000002)) >> 1;
	*otp_write_failed = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 otp_otp_stat_otp_pwok_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline u8 otp_otp_stat_otp_rd_ded_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline u8 otp_otp_stat_otp_rd_sec_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline u8 otp_otp_stat_otp_ready_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline u8 otp_otp_stat_otp_write_failed_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

/**
 * @brief OTP_READ_VAL register definition
 *  OTP read value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 OTP_READ_VAL              0x0
 * </pre>
 */
#define OTP_OTP_READ_VAL_ADDR        (REG_OTP_BASE_ADDR + 0x00000008)
#define OTP_OTP_READ_VAL_OFFSET      0x00000008
#define OTP_OTP_READ_VAL_INDEX       0x00000002
#define OTP_OTP_READ_VAL_RESET       0x00000000

static inline u32  otp_otp_read_val_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, OTP_OTP_READ_VAL_ADDR);
}

// field definitions
#define OTP_OTP_READ_VAL_OTP_READ_VAL_MASK    ((u32)0xFFFFFFFF)
#define OTP_OTP_READ_VAL_OTP_READ_VAL_LSB    0
#define OTP_OTP_READ_VAL_OTP_READ_VAL_WIDTH    ((u32)0x00000020)

#define OTP_OTP_READ_VAL_OTP_READ_VAL_RST    0x0

static inline u32 otp_otp_read_val_otp_read_val_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_READ_VAL_ADDR);

	return (u32)(local_val >>  0);
}

/**
 * @brief OTP_ADDR register definition
 *  OTP address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    SUPPADD                   0
 *    07:00 OTP_ADDR                  0x0
 * </pre>
 */
#define OTP_OTP_ADDR_ADDR        (REG_OTP_BASE_ADDR + 0x0000000C)
#define OTP_OTP_ADDR_OFFSET      0x0000000C
#define OTP_OTP_ADDR_INDEX       0x00000003
#define OTP_OTP_ADDR_RESET       0x00000000

static inline u32  otp_otp_addr_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, OTP_OTP_ADDR_ADDR);
}

static inline void otp_otp_addr_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, OTP_OTP_ADDR_ADDR, value);
}

// field definitions
#define OTP_OTP_ADDR_SUPPADD_BIT            ((u32)0x80000000)
#define OTP_OTP_ADDR_SUPPADD_POS            31
#define OTP_OTP_ADDR_OTP_ADDR_MASK          ((u32)0x000000FF)
#define OTP_OTP_ADDR_OTP_ADDR_LSB           0
#define OTP_OTP_ADDR_OTP_ADDR_WIDTH         ((u32)0x00000008)

#define OTP_OTP_ADDR_SUPPADD_RST            0x0
#define OTP_OTP_ADDR_OTP_ADDR_RST           0x0

static inline void otp_otp_addr_pack(struct cl_chip *chip, u8 suppadd, u8 otp_addr)
{
	ASSERT_ERR_CHIP((((u32)suppadd << 31) & ~((u32)0x80000000)) == 0);
	ASSERT_ERR_CHIP((((u32)otp_addr << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, OTP_OTP_ADDR_ADDR,  ((u32)suppadd << 31) | ((u32)otp_addr << 0));
}

static inline void otp_otp_addr_unpack(struct cl_chip *chip, u8 *suppadd, u8 *otp_addr)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_ADDR_ADDR);

	*suppadd = (local_val & ((u32)0x80000000)) >> 31;
	*otp_addr = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u8 otp_otp_addr_suppadd_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_ADDR_ADDR);

	return (u8)((local_val & ((u32)0x80000000)) >> 31);
}

static inline void otp_otp_addr_suppadd_setf(struct cl_chip *chip, u8 suppadd)
{
	ASSERT_ERR_CHIP((((u32)suppadd << 31) & ~((u32)0x80000000)) == 0);
	cl_reg_write(chip, OTP_OTP_ADDR_ADDR, (cl_reg_read(chip, OTP_OTP_ADDR_ADDR) & ~((u32)0x80000000)) | ((u32)suppadd << 31));
}

static inline u8 otp_otp_addr_otp_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_ADDR_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void otp_otp_addr_otp_addr_setf(struct cl_chip *chip, u8 otpaddr)
{
	ASSERT_ERR_CHIP((((u32)otpaddr << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, OTP_OTP_ADDR_ADDR, (cl_reg_read(chip, OTP_OTP_ADDR_ADDR) & ~((u32)0x000000FF)) | ((u32)otpaddr << 0));
}

/**
 * @brief OTP_WRITE_VAL register definition
 *  OTP write value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 OTP_WRITE_VAL             0x0
 * </pre>
 */
#define OTP_OTP_WRITE_VAL_ADDR        (REG_OTP_BASE_ADDR + 0x00000010)
#define OTP_OTP_WRITE_VAL_OFFSET      0x00000010
#define OTP_OTP_WRITE_VAL_INDEX       0x00000004
#define OTP_OTP_WRITE_VAL_RESET       0x00000000

static inline u32  otp_otp_write_val_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, OTP_OTP_WRITE_VAL_ADDR);
}

static inline void otp_otp_write_val_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, OTP_OTP_WRITE_VAL_ADDR, value);
}

// field definitions
#define OTP_OTP_WRITE_VAL_OTP_WRITE_VAL_MASK    ((u32)0xFFFFFFFF)
#define OTP_OTP_WRITE_VAL_OTP_WRITE_VAL_LSB    0
#define OTP_OTP_WRITE_VAL_OTP_WRITE_VAL_WIDTH    ((u32)0x00000020)

#define OTP_OTP_WRITE_VAL_OTP_WRITE_VAL_RST    0x0

static inline u32 otp_otp_write_val_otp_write_val_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_WRITE_VAL_ADDR);

	return (u32)(local_val >> 0);
}

static inline void otp_otp_write_val_otp_write_val_setf(struct cl_chip *chip, u32 otpwriteval)
{
	ASSERT_ERR_CHIP((((u32)otpwriteval << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, OTP_OTP_WRITE_VAL_ADDR, (u32)otpwriteval << 0);
}

/**
 * @brief OTP_KEY register definition
 *  OTP key register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 OTP_KEY                   0x0
 * </pre>
 */
#define OTP_OTP_KEY_ADDR        (REG_OTP_BASE_ADDR + 0x00000014)
#define OTP_OTP_KEY_OFFSET      0x00000014
#define OTP_OTP_KEY_INDEX       0x00000005
#define OTP_OTP_KEY_RESET       0x00000000

static inline void otp_otp_key_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, OTP_OTP_KEY_ADDR, value);
}

// field definitions
#define OTP_OTP_KEY_OTP_KEY_MASK            ((u32)0xFFFFFFFF)
#define OTP_OTP_KEY_OTP_KEY_LSB             0
#define OTP_OTP_KEY_OTP_KEY_WIDTH           ((u32)0x00000020)

#define OTP_OTP_KEY_OTP_KEY_RST             0x0

static inline void otp_otp_key_otp_key_setf(struct cl_chip *chip, u32 otpkey)
{
	ASSERT_ERR_CHIP((((u32)otpkey << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, OTP_OTP_KEY_ADDR, (u32)otpkey << 0);
}

/**
 * @brief OTP_CLK_DIV register definition
 *  OTP clock divisor register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08:00 OTP_CLK_DIV               0x8
 * </pre>
 */
#define OTP_OTP_CLK_DIV_ADDR        (REG_OTP_BASE_ADDR + 0x00000018)
#define OTP_OTP_CLK_DIV_OFFSET      0x00000018
#define OTP_OTP_CLK_DIV_INDEX       0x00000006
#define OTP_OTP_CLK_DIV_RESET       0x00000008

static inline u32  otp_otp_clk_div_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, OTP_OTP_CLK_DIV_ADDR);
}

static inline void otp_otp_clk_div_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, OTP_OTP_CLK_DIV_ADDR, value);
}

// field definitions
#define OTP_OTP_CLK_DIV_OTP_CLK_DIV_MASK    ((u32)0x000001FF)
#define OTP_OTP_CLK_DIV_OTP_CLK_DIV_LSB     0
#define OTP_OTP_CLK_DIV_OTP_CLK_DIV_WIDTH    ((u32)0x00000009)

#define OTP_OTP_CLK_DIV_OTP_CLK_DIV_RST     0x8

static inline u16 otp_otp_clk_div_otp_clk_div_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_CLK_DIV_ADDR);

	return (u16)(local_val >> 0);
}

static inline void otp_otp_clk_div_otp_clk_div_setf(struct cl_chip *chip, u16 otpclkdiv)
{
	ASSERT_ERR_CHIP((((u32)otpclkdiv << 0) & ~((u32)0x000001FF)) == 0);
	cl_reg_write(chip, OTP_OTP_CLK_DIV_ADDR, (u32)otpclkdiv << 0);
}

/**
 * @brief OTP_CONFIG_REG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 OTP_CONFIG_REG            0x74a10cb0
 * </pre>
 */
#define OTP_OTP_CONFIG_REG_ADDR        (REG_OTP_BASE_ADDR + 0x0000001C)
#define OTP_OTP_CONFIG_REG_OFFSET      0x0000001C
#define OTP_OTP_CONFIG_REG_INDEX       0x00000007
#define OTP_OTP_CONFIG_REG_RESET       0x74A10CB0

static inline u32  otp_otp_config_reg_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, OTP_OTP_CONFIG_REG_ADDR);
}

static inline void otp_otp_config_reg_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, OTP_OTP_CONFIG_REG_ADDR, value);
}

// field definitions
#define OTP_OTP_CONFIG_REG_OTP_CONFIG_REG_MASK    ((u32)0xFFFFFFFF)
#define OTP_OTP_CONFIG_REG_OTP_CONFIG_REG_LSB    0
#define OTP_OTP_CONFIG_REG_OTP_CONFIG_REG_WIDTH    ((u32)0x00000020)

#define OTP_OTP_CONFIG_REG_OTP_CONFIG_REG_RST    0x74a10cb0

static inline u32 otp_otp_config_reg_otp_config_reg_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_CONFIG_REG_ADDR);

	return (u32)(local_val >> 0);
}

static inline void otp_otp_config_reg_otp_config_reg_setf(struct cl_chip *chip, u32 otpconfigreg)
{
	ASSERT_ERR_CHIP((((u32)otpconfigreg << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, OTP_OTP_CONFIG_REG_ADDR, (u32)otpconfigreg << 0);
}

/**
 * @brief OTP_PDN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    PDN_RST                   0
 * </pre>
 */
#define OTP_OTP_PDN_ADDR        (REG_OTP_BASE_ADDR + 0x00000020)
#define OTP_OTP_PDN_OFFSET      0x00000020
#define OTP_OTP_PDN_INDEX       0x00000008
#define OTP_OTP_PDN_RESET       0x00000000

static inline void otp_otp_pdn_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, OTP_OTP_PDN_ADDR, value);
}

// field definitions
#define OTP_OTP_PDN_PDN_RST_BIT             ((u32)0x00000001)
#define OTP_OTP_PDN_PDN_RST_POS             0

#define OTP_OTP_PDN_PDN_RST_RST             0x0

static inline void otp_otp_pdn_pdn_rst_setf(struct cl_chip *chip, u8 pdnrst)
{
	ASSERT_ERR_CHIP((((u32)pdnrst << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, OTP_OTP_PDN_ADDR, (u32)pdnrst << 0);
}

/**
 * @brief OTP_BIST_ACTIVATE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    BIST2_ACT                 0
 *    00    BIST1_ACT                 0
 * </pre>
 */
#define OTP_OTP_BIST_ACTIVATE_ADDR        (REG_OTP_BASE_ADDR + 0x00000024)
#define OTP_OTP_BIST_ACTIVATE_OFFSET      0x00000024
#define OTP_OTP_BIST_ACTIVATE_INDEX       0x00000009
#define OTP_OTP_BIST_ACTIVATE_RESET       0x00000000

static inline void otp_otp_bist_activate_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, OTP_OTP_BIST_ACTIVATE_ADDR, value);
}

// field definitions
#define OTP_OTP_BIST_ACTIVATE_BIST_2_ACT_BIT    ((u32)0x00000002)
#define OTP_OTP_BIST_ACTIVATE_BIST_2_ACT_POS    1
#define OTP_OTP_BIST_ACTIVATE_BIST_1_ACT_BIT    ((u32)0x00000001)
#define OTP_OTP_BIST_ACTIVATE_BIST_1_ACT_POS    0

#define OTP_OTP_BIST_ACTIVATE_BIST_2_ACT_RST    0x0
#define OTP_OTP_BIST_ACTIVATE_BIST_1_ACT_RST    0x0

static inline void otp_otp_bist_activate_pack(struct cl_chip *chip, u8 bist2_act, u8 bist1_act)
{
	ASSERT_ERR_CHIP((((u32)bist2_act << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)bist1_act << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, OTP_OTP_BIST_ACTIVATE_ADDR,  ((u32)bist2_act <<  1) | ((u32)bist1_act <<  0));
}

static inline void otp_otp_bist_activate_bist_2_act_setf(struct cl_chip *chip, u8 bist2act)
{
	ASSERT_ERR_CHIP((((u32)bist2act << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, OTP_OTP_BIST_ACTIVATE_ADDR, (cl_reg_read(chip, OTP_OTP_BIST_ACTIVATE_ADDR) & ~((u32)0x00000002)) | ((u32)bist2act << 1));
}

static inline void otp_otp_bist_activate_bist_1_act_setf(struct cl_chip *chip, u8 bist1act)
{
	ASSERT_ERR_CHIP((((u32)bist1act << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, OTP_OTP_BIST_ACTIVATE_ADDR, (cl_reg_read(chip, OTP_OTP_BIST_ACTIVATE_ADDR) & ~((u32)0x00000001)) | ((u32)bist1act << 0));
}

/**
 * @brief OTP_BIST_1_TIMING register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 RBACT1_TIMING             0x12E8
 * </pre>
 */
#define OTP_OTP_BIST_1_TIMING_ADDR        (REG_OTP_BASE_ADDR + 0x00000028)
#define OTP_OTP_BIST_1_TIMING_OFFSET      0x00000028
#define OTP_OTP_BIST_1_TIMING_INDEX       0x0000000A
#define OTP_OTP_BIST_1_TIMING_RESET       0x000012E8

static inline u32  otp_otp_bist_1_timing_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, OTP_OTP_BIST_1_TIMING_ADDR);
}

static inline void otp_otp_bist_1_timing_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, OTP_OTP_BIST_1_TIMING_ADDR, value);
}

// field definitions
#define OTP_OTP_BIST_1_TIMING_RBACT_1_TIMING_MASK    ((u32)0x0000FFFF)
#define OTP_OTP_BIST_1_TIMING_RBACT_1_TIMING_LSB    0
#define OTP_OTP_BIST_1_TIMING_RBACT_1_TIMING_WIDTH    ((u32)0x00000010)

#define OTP_OTP_BIST_1_TIMING_RBACT_1_TIMING_RST    0x12E8

static inline u16 otp_otp_bist_1_timing_rbact_1_timing_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_BIST_1_TIMING_ADDR);

	return (u16)(local_val >> 0);
}

static inline void otp_otp_bist_1_timing_rbact_1_timing_setf(struct cl_chip *chip, u16 rbact1timing)
{
	ASSERT_ERR_CHIP((((u32)rbact1timing << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, OTP_OTP_BIST_1_TIMING_ADDR, (u32)rbact1timing << 0);
}

/**
 * @brief OTP_BIST_2_TIMING register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BIST2_TIMING              0x0
 * </pre>
 */
#define OTP_OTP_BIST_2_TIMING_ADDR        (REG_OTP_BASE_ADDR + 0x0000002C)
#define OTP_OTP_BIST_2_TIMING_OFFSET      0x0000002C
#define OTP_OTP_BIST_2_TIMING_INDEX       0x0000000B
#define OTP_OTP_BIST_2_TIMING_RESET       0x00000000

static inline u32  otp_otp_bist_2_timing_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, OTP_OTP_BIST_2_TIMING_ADDR);
}

// field definitions
#define OTP_OTP_BIST_2_TIMING_BIST_2_TIMING_MASK    ((u32)0xFFFFFFFF)
#define OTP_OTP_BIST_2_TIMING_BIST_2_TIMING_LSB    0
#define OTP_OTP_BIST_2_TIMING_BIST_2_TIMING_WIDTH    ((u32)0x00000020)

#define OTP_OTP_BIST_2_TIMING_BIST_2_TIMING_RST    0x0

static inline u32 otp_otp_bist_2_timing_bist_2_timing_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_BIST_2_TIMING_ADDR);

	return (u32)(local_val >> 0);
}

/**
 * @brief OTP_BIST_RESULT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    18:12 BIST2_FAIL                0x0
 *    11:04 BIST1_FAIL                0x0
 *    02    BBAD                      0
 *    01    BEND2                     0
 *    00    BEND1                     0
 * </pre>
 */
#define OTP_OTP_BIST_RESULT_ADDR        (REG_OTP_BASE_ADDR + 0x00000030)
#define OTP_OTP_BIST_RESULT_OFFSET      0x00000030
#define OTP_OTP_BIST_RESULT_INDEX       0x0000000C
#define OTP_OTP_BIST_RESULT_RESET       0x00000000

static inline u32  otp_otp_bist_result_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, OTP_OTP_BIST_RESULT_ADDR);
}

// field definitions
#define OTP_OTP_BIST_RESULT_BIST_2_FAIL_MASK    ((u32)0x0007F000)
#define OTP_OTP_BIST_RESULT_BIST_2_FAIL_LSB    12
#define OTP_OTP_BIST_RESULT_BIST_2_FAIL_WIDTH    ((u32)0x00000007)
#define OTP_OTP_BIST_RESULT_BIST_1_FAIL_MASK    ((u32)0x00000FF0)
#define OTP_OTP_BIST_RESULT_BIST_1_FAIL_LSB    4
#define OTP_OTP_BIST_RESULT_BIST_1_FAIL_WIDTH    ((u32)0x00000008)
#define OTP_OTP_BIST_RESULT_BBAD_BIT        ((u32)0x00000004)
#define OTP_OTP_BIST_RESULT_BBAD_POS        2
#define OTP_OTP_BIST_RESULT_BEND_2_BIT      ((u32)0x00000002)
#define OTP_OTP_BIST_RESULT_BEND_2_POS      1
#define OTP_OTP_BIST_RESULT_BEND_1_BIT      ((u32)0x00000001)
#define OTP_OTP_BIST_RESULT_BEND_1_POS      0

#define OTP_OTP_BIST_RESULT_BIST_2_FAIL_RST    0x0
#define OTP_OTP_BIST_RESULT_BIST_1_FAIL_RST    0x0
#define OTP_OTP_BIST_RESULT_BBAD_RST        0x0
#define OTP_OTP_BIST_RESULT_BEND_2_RST      0x0
#define OTP_OTP_BIST_RESULT_BEND_1_RST      0x0

static inline void otp_otp_bist_result_unpack(struct cl_chip *chip, u8 *bist2_fail, u8 *bist1_fail, u8 *bbad, u8 *bend2, u8 *bend1)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_BIST_RESULT_ADDR);

	*bist2_fail = (local_val & ((u32)0x0007F000)) >> 12;
	*bist1_fail = (local_val & ((u32)0x00000FF0)) >> 4;
	*bbad = (local_val & ((u32)0x00000004)) >> 2;
	*bend2 = (local_val & ((u32)0x00000002)) >> 1;
	*bend1 = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 otp_otp_bist_result_bist_2_fail_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_BIST_RESULT_ADDR);

	return (u8)((local_val & ((u32)0x0007F000)) >> 12);
}

static inline u8 otp_otp_bist_result_bist_1_fail_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_BIST_RESULT_ADDR);

	return (u8)((local_val & ((u32)0x00000FF0)) >> 4);
}

static inline u8 otp_otp_bist_result_bbad_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_BIST_RESULT_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline u8 otp_otp_bist_result_bend_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_BIST_RESULT_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline u8 otp_otp_bist_result_bend_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, OTP_OTP_BIST_RESULT_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

#endif //_REG_OTP_H_
