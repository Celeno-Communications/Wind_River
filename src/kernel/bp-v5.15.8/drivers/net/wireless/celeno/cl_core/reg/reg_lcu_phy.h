/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef REG_LCU_PHY_H
#define REG_LCU_PHY_H

#include "reg_access.h"
#include "chip.h"

#define REG_LCU_PHY_BASE_ADDR 0x004AE000

/**
 * @brief LCU_CH_0_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_EN                    0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_EN_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000000)
#define LCU_PHY_LCU_CH_0_EN_OFFSET      0x00000000
#define LCU_PHY_LCU_CH_0_EN_INDEX       0x00000000
#define LCU_PHY_LCU_CH_0_EN_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_0_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_0_EN_ADDR);
}

static inline void lcu_phy_lcu_ch_0_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_EN_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_0_EN_CH_0_EN_BIT     ((u32)0x00000001)
#define LCU_PHY_LCU_CH_0_EN_CH_0_EN_POS     0

#define LCU_PHY_LCU_CH_0_EN_CH_0_EN_RST     0x0

static inline u8 lcu_phy_lcu_ch_0_en_ch_0_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_EN_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_0_en_ch_0_en_setf(struct cl_chip *chip, u8 ch0en)
{
	ASSERT_ERR_CHIP((((u32)ch0en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_EN_ADDR, (u32)ch0en << 0);
}

/**
 * @brief LCU_CH_1_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_EN                    0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_EN_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000004)
#define LCU_PHY_LCU_CH_1_EN_OFFSET      0x00000004
#define LCU_PHY_LCU_CH_1_EN_INDEX       0x00000001
#define LCU_PHY_LCU_CH_1_EN_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_1_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_1_EN_ADDR);
}

static inline void lcu_phy_lcu_ch_1_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_EN_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_1_EN_CH_1_EN_BIT     ((u32)0x00000001)
#define LCU_PHY_LCU_CH_1_EN_CH_1_EN_POS     0

#define LCU_PHY_LCU_CH_1_EN_CH_1_EN_RST     0x0

static inline u8 lcu_phy_lcu_ch_1_en_ch_1_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_EN_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_1_en_ch_1_en_setf(struct cl_chip *chip, u8 ch1en)
{
	ASSERT_ERR_CHIP((((u32)ch1en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_EN_ADDR, (u32)ch1en << 0);
}

/**
 * @brief LCU_CH_0_CONF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:08 CH0_TYPE                  0x0
 *    04    CH0_SIZE                  0
 *    01:00 CH0_MODE                  0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_CONF_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000008)
#define LCU_PHY_LCU_CH_0_CONF_OFFSET      0x00000008
#define LCU_PHY_LCU_CH_0_CONF_INDEX       0x00000002
#define LCU_PHY_LCU_CH_0_CONF_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_0_conf_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_0_CONF_ADDR);
}

static inline void lcu_phy_lcu_ch_0_conf_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CONF_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_0_CONF_CH_0_TYPE_MASK    ((u32)0x00000F00)
#define LCU_PHY_LCU_CH_0_CONF_CH_0_TYPE_LSB    8
#define LCU_PHY_LCU_CH_0_CONF_CH_0_TYPE_WIDTH    ((u32)0x00000004)
#define LCU_PHY_LCU_CH_0_CONF_CH_0_SIZE_BIT    ((u32)0x00000010)
#define LCU_PHY_LCU_CH_0_CONF_CH_0_SIZE_POS    4
#define LCU_PHY_LCU_CH_0_CONF_CH_0_MODE_MASK    ((u32)0x00000003)
#define LCU_PHY_LCU_CH_0_CONF_CH_0_MODE_LSB    0
#define LCU_PHY_LCU_CH_0_CONF_CH_0_MODE_WIDTH    ((u32)0x00000002)

#define LCU_PHY_LCU_CH_0_CONF_CH_0_TYPE_RST    0x0
#define LCU_PHY_LCU_CH_0_CONF_CH_0_SIZE_RST    0x0
#define LCU_PHY_LCU_CH_0_CONF_CH_0_MODE_RST    0x0

static inline void lcu_phy_lcu_ch_0_conf_pack(struct cl_chip *chip, u8 ch0_type, u8 ch0_size, u8 ch0_mode)
{
	ASSERT_ERR_CHIP((((u32)ch0_type << 8) & ~((u32)0x00000F00)) == 0);
	ASSERT_ERR_CHIP((((u32)ch0_size << 4) & ~((u32)0x00000010)) == 0);
	ASSERT_ERR_CHIP((((u32)ch0_mode << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CONF_ADDR, ((u32)ch0_type << 8) | ((u32)ch0_size << 4) | ((u32)ch0_mode << 0));
}

static inline void lcu_phy_lcu_ch_0_conf_unpack(struct cl_chip *chip, u8 *ch0_type, u8 *ch0_size, u8 *ch0_mode)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_CONF_ADDR);

	*ch0_type = (local_val & ((u32)0x00000F00)) >> 8;
	*ch0_size = (local_val & ((u32)0x00000010)) >> 4;
	*ch0_mode = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u8 lcu_phy_lcu_ch_0_conf_ch_0_type_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000F00)) >> 8);
}

static inline void lcu_phy_lcu_ch_0_conf_ch_0_type_setf(struct cl_chip *chip, u8 ch0type)
{
	ASSERT_ERR_CHIP((((u32)ch0type << 8) & ~((u32)0x00000F00)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CONF_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_CH_0_CONF_ADDR) & ~((u32)0x00000F00)) | ((u32)ch0type << 8));
}

static inline u8 lcu_phy_lcu_ch_0_conf_ch_0_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline void lcu_phy_lcu_ch_0_conf_ch_0_size_setf(struct cl_chip *chip, u8 ch0size)
{
	ASSERT_ERR_CHIP((((u32)ch0size << 4) & ~((u32)0x00000010)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CONF_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_CH_0_CONF_ADDR) & ~((u32)0x00000010)) | ((u32)ch0size << 4));
}

static inline u8 lcu_phy_lcu_ch_0_conf_ch_0_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void lcu_phy_lcu_ch_0_conf_ch_0_mode_setf(struct cl_chip *chip, u8 ch0mode)
{
	ASSERT_ERR_CHIP((((u32)ch0mode << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CONF_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_CH_0_CONF_ADDR) & ~((u32)0x00000003)) | ((u32)ch0mode << 0));
}

/**
 * @brief LCU_CH_1_CONF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:08 CH1_TYPE                  0x0
 *    04    CH1_SIZE                  0
 *    01:00 CH1_MODE                  0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_CONF_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000000C)
#define LCU_PHY_LCU_CH_1_CONF_OFFSET      0x0000000C
#define LCU_PHY_LCU_CH_1_CONF_INDEX       0x00000003
#define LCU_PHY_LCU_CH_1_CONF_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_1_conf_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_1_CONF_ADDR);
}

static inline void lcu_phy_lcu_ch_1_conf_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_CONF_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_1_CONF_CH_1_TYPE_MASK    ((u32)0x00000F00)
#define LCU_PHY_LCU_CH_1_CONF_CH_1_TYPE_LSB    8
#define LCU_PHY_LCU_CH_1_CONF_CH_1_TYPE_WIDTH    ((u32)0x00000004)
#define LCU_PHY_LCU_CH_1_CONF_CH_1_SIZE_BIT    ((u32)0x00000010)
#define LCU_PHY_LCU_CH_1_CONF_CH_1_SIZE_POS    4
#define LCU_PHY_LCU_CH_1_CONF_CH_1_MODE_MASK    ((u32)0x00000003)
#define LCU_PHY_LCU_CH_1_CONF_CH_1_MODE_LSB    0
#define LCU_PHY_LCU_CH_1_CONF_CH_1_MODE_WIDTH    ((u32)0x00000002)

#define LCU_PHY_LCU_CH_1_CONF_CH_1_TYPE_RST    0x0
#define LCU_PHY_LCU_CH_1_CONF_CH_1_SIZE_RST    0x0
#define LCU_PHY_LCU_CH_1_CONF_CH_1_MODE_RST    0x0

static inline void lcu_phy_lcu_ch_1_conf_pack(struct cl_chip *chip, u8 ch1_type, u8 ch1_size, u8 ch1_mode)
{
	ASSERT_ERR_CHIP((((u32)ch1_type << 8) & ~((u32)0x00000F00)) == 0);
	ASSERT_ERR_CHIP((((u32)ch1_size << 4) & ~((u32)0x00000010)) == 0);
	ASSERT_ERR_CHIP((((u32)ch1_mode << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_CONF_ADDR, ((u32)ch1_type << 8) | ((u32)ch1_size << 4) | ((u32)ch1_mode << 0));
}

static inline void lcu_phy_lcu_ch_1_conf_unpack(struct cl_chip *chip, u8 *ch1_type, u8 *ch1_size, u8 *ch1_mode)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_CONF_ADDR);

	*ch1_type = (local_val & ((u32)0x00000F00)) >> 8;
	*ch1_size = (local_val & ((u32)0x00000010)) >> 4;
	*ch1_mode = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u8 lcu_phy_lcu_ch_1_conf_ch_1_type_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000F00)) >> 8);
}

static inline void lcu_phy_lcu_ch_1_conf_ch_1_type_setf(struct cl_chip *chip, u8 ch1type)
{
	ASSERT_ERR_CHIP((((u32)ch1type << 8) & ~((u32)0x00000F00)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_CONF_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_CH_1_CONF_ADDR) & ~((u32)0x00000F00)) | ((u32)ch1type << 8));
}

static inline u8 lcu_phy_lcu_ch_1_conf_ch_1_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline u8 lcu_phy_lcu_ch_1_conf_ch_1_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void lcu_phy_lcu_ch_1_conf_ch_1_mode_setf(struct cl_chip *chip, u8 ch1mode)
{
	ASSERT_ERR_CHIP((((u32)ch1mode << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_CONF_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_CH_1_CONF_ADDR) & ~((u32)0x00000003)) | ((u32)ch1mode << 0));
}

/**
 * @brief LCU_CH_0_CHAINS_BITMAP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 CH0_CHAINS_BITMAP         0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000010)
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_OFFSET      0x00000010
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_INDEX       0x00000004
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_0_chains_bitmap_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_0_CHAINS_BITMAP_ADDR);
}

static inline void lcu_phy_lcu_ch_0_chains_bitmap_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CHAINS_BITMAP_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_CH_0_CHAINS_BITMAP_MASK    ((u32)0x00000003)
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_CH_0_CHAINS_BITMAP_LSB    0
#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_CH_0_CHAINS_BITMAP_WIDTH    ((u32)0x00000002)

#define LCU_PHY_LCU_CH_0_CHAINS_BITMAP_CH_0_CHAINS_BITMAP_RST    0x0

static inline u8 lcu_phy_lcu_ch_0_chains_bitmap_ch_0_chains_bitmap_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_CHAINS_BITMAP_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_0_chains_bitmap_ch_0_chains_bitmap_setf(struct cl_chip *chip, u8 ch0chainsbitmap)
{
	ASSERT_ERR_CHIP((((u32)ch0chainsbitmap << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CHAINS_BITMAP_ADDR, (u32)ch0chainsbitmap << 0);
}

/**
 * @brief LCU_CH_1_CHAINS_BITMAP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 CH1_CHAINS_BITMAP         0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000014)
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_OFFSET      0x00000014
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_INDEX       0x00000005
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_1_chains_bitmap_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_1_CHAINS_BITMAP_ADDR);
}

static inline void lcu_phy_lcu_ch_1_chains_bitmap_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_CHAINS_BITMAP_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_CH_1_CHAINS_BITMAP_MASK    ((u32)0x00000003)
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_CH_1_CHAINS_BITMAP_LSB    0
#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_CH_1_CHAINS_BITMAP_WIDTH    ((u32)0x00000002)

#define LCU_PHY_LCU_CH_1_CHAINS_BITMAP_CH_1_CHAINS_BITMAP_RST    0x0

static inline u8 lcu_phy_lcu_ch_1_chains_bitmap_ch_1_chains_bitmap_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_CHAINS_BITMAP_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_1_chains_bitmap_ch_1_chains_bitmap_setf(struct cl_chip *chip, u8 ch1chainsbitmap)
{
	ASSERT_ERR_CHIP((((u32)ch1chainsbitmap << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_CHAINS_BITMAP_ADDR, (u32)ch1chainsbitmap << 0);
}

/**
 * @brief LCU_CH_0_DECIMATION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02:00 CH0_DECIMATION            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_DECIMATION_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000018)
#define LCU_PHY_LCU_CH_0_DECIMATION_OFFSET      0x00000018
#define LCU_PHY_LCU_CH_0_DECIMATION_INDEX       0x00000006
#define LCU_PHY_LCU_CH_0_DECIMATION_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_0_decimation_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_0_DECIMATION_ADDR);
}

static inline void lcu_phy_lcu_ch_0_decimation_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_DECIMATION_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_0_DECIMATION_CH_0_DECIMATION_MASK    ((u32)0x00000007)
#define LCU_PHY_LCU_CH_0_DECIMATION_CH_0_DECIMATION_LSB    0
#define LCU_PHY_LCU_CH_0_DECIMATION_CH_0_DECIMATION_WIDTH    ((u32)0x00000003)

#define LCU_PHY_LCU_CH_0_DECIMATION_CH_0_DECIMATION_RST    0x0

static inline u8 lcu_phy_lcu_ch_0_decimation_ch_0_decimation_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_DECIMATION_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_0_decimation_ch_0_decimation_setf(struct cl_chip *chip, u8 ch0decimation)
{
	ASSERT_ERR_CHIP((((u32)ch0decimation << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_DECIMATION_ADDR, (u32)ch0decimation << 0);
}

/**
 * @brief LCU_CH_1_DECIMATION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02:00 CH1_DECIMATION            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_DECIMATION_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000001C)
#define LCU_PHY_LCU_CH_1_DECIMATION_OFFSET      0x0000001C
#define LCU_PHY_LCU_CH_1_DECIMATION_INDEX       0x00000007
#define LCU_PHY_LCU_CH_1_DECIMATION_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_1_decimation_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_1_DECIMATION_ADDR);
}

static inline void lcu_phy_lcu_ch_1_decimation_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_DECIMATION_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_1_DECIMATION_CH_1_DECIMATION_MASK    ((u32)0x00000007)
#define LCU_PHY_LCU_CH_1_DECIMATION_CH_1_DECIMATION_LSB    0
#define LCU_PHY_LCU_CH_1_DECIMATION_CH_1_DECIMATION_WIDTH    ((u32)0x00000003)

#define LCU_PHY_LCU_CH_1_DECIMATION_CH_1_DECIMATION_RST    0x0

static inline u8 lcu_phy_lcu_ch_1_decimation_ch_1_decimation_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_DECIMATION_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_1_decimation_ch_1_decimation_setf(struct cl_chip *chip, u8 ch1decimation)
{
	ASSERT_ERR_CHIP((((u32)ch1decimation << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_DECIMATION_ADDR, (u32)ch1decimation << 0);
}

/**
 * @brief LCU_CH_0_START register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_START                 0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_START_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000020)
#define LCU_PHY_LCU_CH_0_START_OFFSET      0x00000020
#define LCU_PHY_LCU_CH_0_START_INDEX       0x00000008
#define LCU_PHY_LCU_CH_0_START_RESET       0x00000000

static inline void lcu_phy_lcu_ch_0_start_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_START_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_0_START_CH_0_START_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_0_START_CH_0_START_POS    0

#define LCU_PHY_LCU_CH_0_START_CH_0_START_RST    0x0

static inline void lcu_phy_lcu_ch_0_start_ch_0_start_setf(struct cl_chip *chip, u8 ch0start)
{
	ASSERT_ERR_CHIP((((u32)ch0start << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_START_ADDR, (u32)ch0start << 0);
}

/**
 * @brief LCU_CH_1_START register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_START                 0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_START_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000024)
#define LCU_PHY_LCU_CH_1_START_OFFSET      0x00000024
#define LCU_PHY_LCU_CH_1_START_INDEX       0x00000009
#define LCU_PHY_LCU_CH_1_START_RESET       0x00000000

static inline void lcu_phy_lcu_ch_1_start_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_START_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_1_START_CH_1_START_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_1_START_CH_1_START_POS    0

#define LCU_PHY_LCU_CH_1_START_CH_1_START_RST    0x0

static inline void lcu_phy_lcu_ch_1_start_ch_1_start_setf(struct cl_chip *chip, u8 ch1start)
{
	ASSERT_ERR_CHIP((((u32)ch1start << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_START_ADDR, (u32)ch1start << 0);
}

/**
 * @brief LCU_CH_0_START_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    CH0_EXT_STRT_EN           0
 *    00    CH0_STRT_PTRN_EN          0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_START_EN_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000028)
#define LCU_PHY_LCU_CH_0_START_EN_OFFSET      0x00000028
#define LCU_PHY_LCU_CH_0_START_EN_INDEX       0x0000000A
#define LCU_PHY_LCU_CH_0_START_EN_RESET       0x00000000

static inline void lcu_phy_lcu_ch_0_start_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_START_EN_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_0_START_EN_CH_0_EXT_STRT_EN_BIT    ((u32)0x00000002)
#define LCU_PHY_LCU_CH_0_START_EN_CH_0_EXT_STRT_EN_POS    1
#define LCU_PHY_LCU_CH_0_START_EN_CH_0_STRT_PTRN_EN_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_0_START_EN_CH_0_STRT_PTRN_EN_POS    0

#define LCU_PHY_LCU_CH_0_START_EN_CH_0_EXT_STRT_EN_RST    0x0
#define LCU_PHY_LCU_CH_0_START_EN_CH_0_STRT_PTRN_EN_RST    0x0

static inline void lcu_phy_lcu_ch_0_start_en_pack(struct cl_chip *chip, u8 ch0_ext_strt_en, u8 ch0_strt_ptrn_en)
{
	ASSERT_ERR_CHIP((((u32)ch0_ext_strt_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)ch0_strt_ptrn_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_START_EN_ADDR, ((u32)ch0_ext_strt_en << 1) | ((u32)ch0_strt_ptrn_en << 0));
}

static inline void lcu_phy_lcu_ch_0_start_en_ch_0_ext_strt_en_setf(struct cl_chip *chip, u8 ch0extstrten)
{
	ASSERT_ERR_CHIP((((u32)ch0extstrten << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_START_EN_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_CH_0_START_EN_ADDR) & ~((u32)0x00000002)) | ((u32)ch0extstrten << 1));
}

static inline void lcu_phy_lcu_ch_0_start_en_ch_0_strt_ptrn_en_setf(struct cl_chip *chip, u8 ch0strtptrnen)
{
	ASSERT_ERR_CHIP((((u32)ch0strtptrnen << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_START_EN_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_CH_0_START_EN_ADDR) & ~((u32)0x00000001)) | ((u32)ch0strtptrnen << 0));
}

/**
 * @brief LCU_CH_1_START_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_STRT_PTRN_EN          0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_START_EN_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000002C)
#define LCU_PHY_LCU_CH_1_START_EN_OFFSET      0x0000002C
#define LCU_PHY_LCU_CH_1_START_EN_INDEX       0x0000000B
#define LCU_PHY_LCU_CH_1_START_EN_RESET       0x00000000

static inline void lcu_phy_lcu_ch_1_start_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_START_EN_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_1_START_EN_CH_1_STRT_PTRN_EN_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_1_START_EN_CH_1_STRT_PTRN_EN_POS    0

#define LCU_PHY_LCU_CH_1_START_EN_CH_1_STRT_PTRN_EN_RST    0x0

static inline void lcu_phy_lcu_ch_1_start_en_ch_1_strt_ptrn_en_setf(struct cl_chip *chip, u8 ch1strtptrnen)
{
	ASSERT_ERR_CHIP((((u32)ch1strtptrnen << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_START_EN_ADDR, (u32)ch1strtptrnen << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000030)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_OFFSET      0x00000030
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_INDEX       0x0000000C
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_0_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_0_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_CH_01_STRT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_CH_01_STRT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_0_CH_01_STRT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_0_ch_01_strt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_0_ch_01_strt_ptrn_setf(struct cl_chip *chip, u32 ch01strtptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_0_ADDR, (u32)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000034)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_OFFSET      0x00000034
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_INDEX       0x0000000D
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_1_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_1_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_CH_01_STRT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_CH_01_STRT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_1_CH_01_STRT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_1_ch_01_strt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_1_ch_01_strt_ptrn_setf(struct cl_chip *chip, u32 ch01strtptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_1_ADDR, (u32)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000038)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_OFFSET      0x00000038
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_INDEX       0x0000000E
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_2_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_2_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_CH_01_STRT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_CH_01_STRT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_2_CH_01_STRT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_2_ch_01_strt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_2_ch_01_strt_ptrn_setf(struct cl_chip *chip, u32 ch01strtptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_2_ADDR, (u32)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000003C)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_OFFSET      0x0000003C
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_INDEX       0x0000000F
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_3_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_3_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_CH_01_STRT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_CH_01_STRT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_3_CH_01_STRT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_3_ch_01_strt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_3_ch_01_strt_ptrn_setf(struct cl_chip *chip, u32 ch01strtptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_3_ADDR, (u32)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000040)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_OFFSET      0x00000040
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_INDEX       0x00000010
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_4_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_4_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_CH_01_STRT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_CH_01_STRT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_4_CH_01_STRT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_4_ch_01_strt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_4_ch_01_strt_ptrn_setf(struct cl_chip *chip, u32 ch01strtptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_4_ADDR, (u32)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000044)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_OFFSET      0x00000044
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_INDEX       0x00000011
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_5_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_5_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_CH_01_STRT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_CH_01_STRT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_5_CH_01_STRT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_5_ch_01_strt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_5_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_5_ch_01_strt_ptrn_setf(struct cl_chip *chip, u32 ch01strtptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_5_ADDR, (u32)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000048)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_OFFSET      0x00000048
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_INDEX       0x00000012
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_6_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_6_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_CH_01_STRT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_CH_01_STRT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_6_CH_01_STRT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_6_ch_01_strt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_6_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_6_ch_01_strt_ptrn_setf(struct cl_chip *chip, u32 ch01strtptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_6_ADDR, (u32)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000004C)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_OFFSET      0x0000004C
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_INDEX       0x00000013
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_7_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_7_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_CH_01_STRT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_CH_01_STRT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_CH_01_STRT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_REG_7_CH_01_STRT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_reg_7_ch_01_strt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_7_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_reg_7_ch_01_strt_ptrn_setf(struct cl_chip *chip, u32 ch01strtptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_REG_7_ADDR, (u32)ch01strtptrn << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000050)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_OFFSET      0x00000050
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_INDEX       0x00000014
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_CH_01_STRT_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_CH_01_STRT_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_CH_01_STRT_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_0_ch_01_strt_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_0_ch_01_strt_ptrn_mask_setf(struct cl_chip *chip, u32 ch01strtptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_0_ADDR, (u32)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000054)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_OFFSET      0x00000054
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_INDEX       0x00000015
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_CH_01_STRT_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_CH_01_STRT_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_CH_01_STRT_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_1_ch_01_strt_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_1_ch_01_strt_ptrn_mask_setf(struct cl_chip *chip, u32 ch01strtptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_1_ADDR, (u32)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000058)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_OFFSET      0x00000058
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_INDEX       0x00000016
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_CH_01_STRT_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_CH_01_STRT_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_CH_01_STRT_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_2_ch_01_strt_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_2_ch_01_strt_ptrn_mask_setf(struct cl_chip *chip, u32 ch01strtptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_2_ADDR, (u32)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000005C)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_OFFSET      0x0000005C
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_INDEX       0x00000017
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_CH_01_STRT_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_CH_01_STRT_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_CH_01_STRT_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_3_ch_01_strt_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_3_ch_01_strt_ptrn_mask_setf(struct cl_chip *chip, u32 ch01strtptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_3_ADDR, (u32)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000060)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_OFFSET      0x00000060
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_INDEX       0x00000018
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_CH_01_STRT_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_CH_01_STRT_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_CH_01_STRT_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_4_ch_01_strt_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_4_ch_01_strt_ptrn_mask_setf(struct cl_chip *chip, u32 ch01strtptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_4_ADDR, (u32)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000064)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_OFFSET      0x00000064
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_INDEX       0x00000019
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_CH_01_STRT_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_CH_01_STRT_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_CH_01_STRT_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_5_ch_01_strt_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_5_ch_01_strt_ptrn_mask_setf(struct cl_chip *chip, u32 ch01strtptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_5_ADDR, (u32)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000068)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_OFFSET      0x00000068
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_INDEX       0x0000001A
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_CH_01_STRT_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_CH_01_STRT_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_CH_01_STRT_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_6_ch_01_strt_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_6_ch_01_strt_ptrn_mask_setf(struct cl_chip *chip, u32 ch01strtptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_6_ADDR, (u32)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_01_START_PTRN_MASK_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STRT_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000006C)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_OFFSET      0x0000006C
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_INDEX       0x0000001B
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_ADDR);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_CH_01_STRT_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_CH_01_STRT_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_CH_01_STRT_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_CH_01_STRT_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_start_ptrn_mask_reg_7_ch_01_strt_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_start_ptrn_mask_reg_7_ch_01_strt_ptrn_mask_setf(struct cl_chip *chip, u32 ch01strtptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01strtptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_START_PTRN_MASK_REG_7_ADDR, (u32)ch01strtptrnmask << 0);
}

/**
 * @brief LCU_CH_0_STOP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_STOP                  0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_STOP_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000070)
#define LCU_PHY_LCU_CH_0_STOP_OFFSET      0x00000070
#define LCU_PHY_LCU_CH_0_STOP_INDEX       0x0000001C
#define LCU_PHY_LCU_CH_0_STOP_RESET       0x00000000

static inline void lcu_phy_lcu_ch_0_stop_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_STOP_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_0_STOP_CH_0_STOP_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_0_STOP_CH_0_STOP_POS    0

#define LCU_PHY_LCU_CH_0_STOP_CH_0_STOP_RST    0x0

static inline void lcu_phy_lcu_ch_0_stop_ch_0_stop_setf(struct cl_chip *chip, u8 ch0stop)
{
	ASSERT_ERR_CHIP((((u32)ch0stop << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_STOP_ADDR, (u32)ch0stop << 0);
}

/**
 * @brief LCU_CH_1_STOP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_STOP                  0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_STOP_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000074)
#define LCU_PHY_LCU_CH_1_STOP_OFFSET      0x00000074
#define LCU_PHY_LCU_CH_1_STOP_INDEX       0x0000001D
#define LCU_PHY_LCU_CH_1_STOP_RESET       0x00000000

static inline void lcu_phy_lcu_ch_1_stop_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_STOP_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_1_STOP_CH_1_STOP_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_1_STOP_CH_1_STOP_POS    0

#define LCU_PHY_LCU_CH_1_STOP_CH_1_STOP_RST    0x0

static inline void lcu_phy_lcu_ch_1_stop_ch_1_stop_setf(struct cl_chip *chip, u8 ch1stop)
{
	ASSERT_ERR_CHIP((((u32)ch1stop << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_STOP_ADDR, (u32)ch1stop << 0);
}

/**
 * @brief LCU_CH_0_STOP_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    CH0_EXT_STOP_EN           0
 *    01    CH0_FIC_STOP_EN           0
 *    00    CH0_STOP_PTRN_EN          0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_STOP_EN_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000078)
#define LCU_PHY_LCU_CH_0_STOP_EN_OFFSET      0x00000078
#define LCU_PHY_LCU_CH_0_STOP_EN_INDEX       0x0000001E
#define LCU_PHY_LCU_CH_0_STOP_EN_RESET       0x00000000

static inline void lcu_phy_lcu_ch_0_stop_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_STOP_EN_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_EXT_STOP_EN_BIT    ((u32)0x00000004)
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_EXT_STOP_EN_POS    2
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_FIC_STOP_EN_BIT    ((u32)0x00000002)
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_FIC_STOP_EN_POS    1
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_STOP_PTRN_EN_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_STOP_PTRN_EN_POS    0

#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_EXT_STOP_EN_RST    0x0
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_FIC_STOP_EN_RST    0x0
#define LCU_PHY_LCU_CH_0_STOP_EN_CH_0_STOP_PTRN_EN_RST    0x0

static inline void lcu_phy_lcu_ch_0_stop_en_pack(struct cl_chip *chip, u8 ch0_ext_stop_en, u8 ch0_fic_stop_en, u8 ch0_stop_ptrn_en)
{
	ASSERT_ERR_CHIP((((u32)ch0_ext_stop_en << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)ch0_fic_stop_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)ch0_stop_ptrn_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_STOP_EN_ADDR, ((u32)ch0_ext_stop_en << 2) | ((u32)ch0_fic_stop_en << 1) | ((u32)ch0_stop_ptrn_en << 0));
}

static inline void lcu_phy_lcu_ch_0_stop_en_ch_0_ext_stop_en_setf(struct cl_chip *chip, u8 ch0extstopen)
{
	ASSERT_ERR_CHIP((((u32)ch0extstopen << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_STOP_EN_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_CH_0_STOP_EN_ADDR) & ~((u32)0x00000004)) | ((u32)ch0extstopen << 2));
}

static inline void lcu_phy_lcu_ch_0_stop_en_ch_0_fic_stop_en_setf(struct cl_chip *chip, u8 ch0ficstopen)
{
	ASSERT_ERR_CHIP((((u32)ch0ficstopen << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_STOP_EN_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_CH_0_STOP_EN_ADDR) & ~((u32)0x00000002)) | ((u32)ch0ficstopen << 1));
}

static inline void lcu_phy_lcu_ch_0_stop_en_ch_0_stop_ptrn_en_setf(struct cl_chip *chip, u8 ch0stopptrnen)
{
	ASSERT_ERR_CHIP((((u32)ch0stopptrnen << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_STOP_EN_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_CH_0_STOP_EN_ADDR) & ~((u32)0x00000001)) | ((u32)ch0stopptrnen << 0));
}

/**
 * @brief LCU_CH_1_STOP_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    CH1_FIC_STOP_EN           0
 *    00    CH1_STOP_PTRN_EN          0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_STOP_EN_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000007C)
#define LCU_PHY_LCU_CH_1_STOP_EN_OFFSET      0x0000007C
#define LCU_PHY_LCU_CH_1_STOP_EN_INDEX       0x0000001F
#define LCU_PHY_LCU_CH_1_STOP_EN_RESET       0x00000000

static inline void lcu_phy_lcu_ch_1_stop_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_STOP_EN_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_1_STOP_EN_CH_1_FIC_STOP_EN_BIT    ((u32)0x00000002)
#define LCU_PHY_LCU_CH_1_STOP_EN_CH_1_FIC_STOP_EN_POS    1
#define LCU_PHY_LCU_CH_1_STOP_EN_CH_1_STOP_PTRN_EN_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_1_STOP_EN_CH_1_STOP_PTRN_EN_POS    0

#define LCU_PHY_LCU_CH_1_STOP_EN_CH_1_FIC_STOP_EN_RST    0x0
#define LCU_PHY_LCU_CH_1_STOP_EN_CH_1_STOP_PTRN_EN_RST    0x0

static inline void lcu_phy_lcu_ch_1_stop_en_pack(struct cl_chip *chip, u8 ch1_fic_stop_en, u8 ch1_stop_ptrn_en)
{
	ASSERT_ERR_CHIP((((u32)ch1_fic_stop_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)ch1_stop_ptrn_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_STOP_EN_ADDR, ((u32)ch1_fic_stop_en << 1) | ((u32)ch1_stop_ptrn_en << 0));
}

static inline void lcu_phy_lcu_ch_1_stop_en_ch_1_fic_stop_en_setf(struct cl_chip *chip, u8 ch1ficstopen)
{
	ASSERT_ERR_CHIP((((u32)ch1ficstopen << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_STOP_EN_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_CH_1_STOP_EN_ADDR) & ~((u32)0x00000002)) | ((u32)ch1ficstopen << 1));
}

static inline void lcu_phy_lcu_ch_1_stop_en_ch_1_stop_ptrn_en_setf(struct cl_chip *chip, u8 ch1stopptrnen)
{
	ASSERT_ERR_CHIP((((u32)ch1stopptrnen << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_STOP_EN_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_CH_1_STOP_EN_ADDR) & ~((u32)0x00000001)) | ((u32)ch1stopptrnen << 0));
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000080)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_OFFSET      0x00000080
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_INDEX       0x00000020
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_CH_01_STOP_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_CH_01_STOP_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_CH_01_STOP_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_0_ch_01_stop_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_0_ch_01_stop_ptrn_setf(struct cl_chip *chip, u32 ch01stopptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_0_ADDR, (u32)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000084)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_OFFSET      0x00000084
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_INDEX       0x00000021
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_CH_01_STOP_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_CH_01_STOP_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_CH_01_STOP_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_1_ch_01_stop_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_1_ch_01_stop_ptrn_setf(struct cl_chip *chip, u32 ch01stopptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_1_ADDR, (u32)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000088)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_OFFSET      0x00000088
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_INDEX       0x00000022
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_CH_01_STOP_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_CH_01_STOP_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_CH_01_STOP_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_2_ch_01_stop_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_2_ch_01_stop_ptrn_setf(struct cl_chip *chip, u32 ch01stopptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_2_ADDR, (u32)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000008C)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_OFFSET      0x0000008C
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_INDEX       0x00000023
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_CH_01_STOP_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_CH_01_STOP_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_CH_01_STOP_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_3_ch_01_stop_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_3_ch_01_stop_ptrn_setf(struct cl_chip *chip, u32 ch01stopptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_3_ADDR, (u32)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000090)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_OFFSET      0x00000090
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_INDEX       0x00000024
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_CH_01_STOP_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_CH_01_STOP_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_CH_01_STOP_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_4_ch_01_stop_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_4_ch_01_stop_ptrn_setf(struct cl_chip *chip, u32 ch01stopptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_4_ADDR, (u32)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000094)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_OFFSET      0x00000094
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_INDEX       0x00000025
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_CH_01_STOP_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_CH_01_STOP_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_CH_01_STOP_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_5_ch_01_stop_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_5_ch_01_stop_ptrn_setf(struct cl_chip *chip, u32 ch01stopptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_5_ADDR, (u32)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000098)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_OFFSET      0x00000098
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_INDEX       0x00000026
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_CH_01_STOP_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_CH_01_STOP_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_CH_01_STOP_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_6_ch_01_stop_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_6_ch_01_stop_ptrn_setf(struct cl_chip *chip, u32 ch01stopptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_6_ADDR, (u32)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN            0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000009C)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_OFFSET      0x0000009C
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_INDEX       0x00000027
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_CH_01_STOP_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_CH_01_STOP_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_CH_01_STOP_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_CH_01_STOP_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_reg_7_ch_01_stop_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_reg_7_ch_01_stop_ptrn_setf(struct cl_chip *chip, u32 ch01stopptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_REG_7_ADDR, (u32)ch01stopptrn << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000A0)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_OFFSET      0x000000A0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_INDEX       0x00000028
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_CH_01_STOP_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_CH_01_STOP_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_CH_01_STOP_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_0_ch_01_stop_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_0_ch_01_stop_ptrn_mask_setf(struct cl_chip *chip, u32 ch01stopptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_0_ADDR, (u32)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000A4)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_OFFSET      0x000000A4
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_INDEX       0x00000029
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_CH_01_STOP_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_CH_01_STOP_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_CH_01_STOP_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_1_ch_01_stop_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_1_ch_01_stop_ptrn_mask_setf(struct cl_chip *chip, u32 ch01stopptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_1_ADDR, (u32)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000A8)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_OFFSET      0x000000A8
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_INDEX       0x0000002A
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_CH_01_STOP_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_CH_01_STOP_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_CH_01_STOP_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_2_ch_01_stop_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_2_ch_01_stop_ptrn_mask_setf(struct cl_chip *chip, u32 ch01stopptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_2_ADDR, (u32)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000AC)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_OFFSET      0x000000AC
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_INDEX       0x0000002B
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_CH_01_STOP_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_CH_01_STOP_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_CH_01_STOP_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_3_ch_01_stop_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_3_ch_01_stop_ptrn_mask_setf(struct cl_chip *chip, u32 ch01stopptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_3_ADDR, (u32)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000B0)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_OFFSET      0x000000B0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_INDEX       0x0000002C
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_CH_01_STOP_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_CH_01_STOP_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_CH_01_STOP_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_4_ch_01_stop_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_4_ch_01_stop_ptrn_mask_setf(struct cl_chip *chip, u32 ch01stopptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_4_ADDR, (u32)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000B4)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_OFFSET      0x000000B4
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_INDEX       0x0000002D
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_CH_01_STOP_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_CH_01_STOP_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_CH_01_STOP_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_5_ch_01_stop_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_5_ch_01_stop_ptrn_mask_setf(struct cl_chip *chip, u32 ch01stopptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_5_ADDR, (u32)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000B8)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_OFFSET      0x000000B8
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_INDEX       0x0000002E
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_CH_01_STOP_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_CH_01_STOP_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_CH_01_STOP_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_6_ch_01_stop_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_6_ch_01_stop_ptrn_mask_setf(struct cl_chip *chip, u32 ch01stopptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_6_ADDR, (u32)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_01_STOP_PTRN_MASK_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_STOP_PTRN_MASK       0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000BC)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_OFFSET      0x000000BC
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_INDEX       0x0000002F
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_ADDR);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_CH_01_STOP_PTRN_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_CH_01_STOP_PTRN_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_CH_01_STOP_PTRN_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_CH_01_STOP_PTRN_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_7_ch_01_stop_ptrn_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_stop_ptrn_mask_reg_7_ch_01_stop_ptrn_mask_setf(struct cl_chip *chip, u32 ch01stopptrnmask)
{
	ASSERT_ERR_CHIP((((u32)ch01stopptrnmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_STOP_PTRN_MASK_REG_7_ADDR, (u32)ch01stopptrnmask << 0);
}

/**
 * @brief LCU_CH_0_CTPREV_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_CTPREV_EN             0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_CTPREV_EN_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000C0)
#define LCU_PHY_LCU_CH_0_CTPREV_EN_OFFSET      0x000000C0
#define LCU_PHY_LCU_CH_0_CTPREV_EN_INDEX       0x00000030
#define LCU_PHY_LCU_CH_0_CTPREV_EN_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_0_ctprev_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_0_CTPREV_EN_ADDR);
}

static inline void lcu_phy_lcu_ch_0_ctprev_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CTPREV_EN_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_0_CTPREV_EN_CH_0_CTPREV_EN_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_0_CTPREV_EN_CH_0_CTPREV_EN_POS    0

#define LCU_PHY_LCU_CH_0_CTPREV_EN_CH_0_CTPREV_EN_RST    0x0

static inline u8 lcu_phy_lcu_ch_0_ctprev_en_ch_0_ctprev_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_CTPREV_EN_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_0_ctprev_en_ch_0_ctprev_en_setf(struct cl_chip *chip, u8 ch0ctpreven)
{
	ASSERT_ERR_CHIP((((u32)ch0ctpreven << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CTPREV_EN_ADDR, (u32)ch0ctpreven << 0);
}

/**
 * @brief LCU_CH_1_CTPREV_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_CTPREV_EN             0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_CTPREV_EN_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000C4)
#define LCU_PHY_LCU_CH_1_CTPREV_EN_OFFSET      0x000000C4
#define LCU_PHY_LCU_CH_1_CTPREV_EN_INDEX       0x00000031
#define LCU_PHY_LCU_CH_1_CTPREV_EN_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_1_ctprev_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_1_CTPREV_EN_ADDR);
}

static inline void lcu_phy_lcu_ch_1_ctprev_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_CTPREV_EN_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_1_CTPREV_EN_CH_1_CTPREV_EN_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_1_CTPREV_EN_CH_1_CTPREV_EN_POS    0

#define LCU_PHY_LCU_CH_1_CTPREV_EN_CH_1_CTPREV_EN_RST    0x0

static inline u8 lcu_phy_lcu_ch_1_ctprev_en_ch_1_ctprev_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_CTPREV_EN_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_1_ctprev_en_ch_1_ctprev_en_setf(struct cl_chip *chip, u8 ch1ctpreven)
{
	ASSERT_ERR_CHIP((((u32)ch1ctpreven << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_CTPREV_EN_ADDR, (u32)ch1ctpreven << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000D0)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_OFFSET      0x000000D0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_INDEX       0x00000034
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_CH_01_CTPREV_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_CH_01_CTPREV_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_CH_01_CTPREV_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_0_ch_01_ctprev_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_0_ch_01_ctprev_mask_setf(struct cl_chip *chip, u32 ch01ctprevmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctprevmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_0_ADDR, (u32)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000D4)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_OFFSET      0x000000D4
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_INDEX       0x00000035
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_CH_01_CTPREV_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_CH_01_CTPREV_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_CH_01_CTPREV_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_1_ch_01_ctprev_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_1_ch_01_ctprev_mask_setf(struct cl_chip *chip, u32 ch01ctprevmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctprevmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_1_ADDR, (u32)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000D8)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_OFFSET      0x000000D8
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_INDEX       0x00000036
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_CH_01_CTPREV_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_CH_01_CTPREV_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_CH_01_CTPREV_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_2_ch_01_ctprev_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_2_ch_01_ctprev_mask_setf(struct cl_chip *chip, u32 ch01ctprevmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctprevmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_2_ADDR, (u32)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000DC)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_OFFSET      0x000000DC
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_INDEX       0x00000037
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_CH_01_CTPREV_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_CH_01_CTPREV_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_CH_01_CTPREV_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_3_ch_01_ctprev_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_3_ch_01_ctprev_mask_setf(struct cl_chip *chip, u32 ch01ctprevmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctprevmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_3_ADDR, (u32)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000E0)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_OFFSET      0x000000E0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_INDEX       0x00000038
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_CH_01_CTPREV_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_CH_01_CTPREV_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_CH_01_CTPREV_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_4_ch_01_ctprev_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_4_ch_01_ctprev_mask_setf(struct cl_chip *chip, u32 ch01ctprevmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctprevmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_4_ADDR, (u32)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000E4)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_OFFSET      0x000000E4
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_INDEX       0x00000039
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_CH_01_CTPREV_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_CH_01_CTPREV_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_CH_01_CTPREV_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_5_ch_01_ctprev_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_5_ch_01_ctprev_mask_setf(struct cl_chip *chip, u32 ch01ctprevmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctprevmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_5_ADDR, (u32)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000E8)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_OFFSET      0x000000E8
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_INDEX       0x0000003A
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_CH_01_CTPREV_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_CH_01_CTPREV_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_CH_01_CTPREV_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_6_ch_01_ctprev_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_6_ch_01_ctprev_mask_setf(struct cl_chip *chip, u32 ch01ctprevmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctprevmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_6_ADDR, (u32)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_01_CTPREV_MASK_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPREV_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000EC)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_OFFSET      0x000000EC
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_INDEX       0x0000003B
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_CH_01_CTPREV_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_CH_01_CTPREV_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_CH_01_CTPREV_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_CH_01_CTPREV_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctprev_mask_reg_7_ch_01_ctprev_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctprev_mask_reg_7_ch_01_ctprev_mask_setf(struct cl_chip *chip, u32 ch01ctprevmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctprevmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPREV_MASK_REG_7_ADDR, (u32)ch01ctprevmask << 0);
}

/**
 * @brief LCU_CH_0_CTPATT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_CTPATT_EN             0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_CTPATT_EN_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000F0)
#define LCU_PHY_LCU_CH_0_CTPATT_EN_OFFSET      0x000000F0
#define LCU_PHY_LCU_CH_0_CTPATT_EN_INDEX       0x0000003C
#define LCU_PHY_LCU_CH_0_CTPATT_EN_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_0_ctpatt_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_0_CTPATT_EN_ADDR);
}

static inline void lcu_phy_lcu_ch_0_ctpatt_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CTPATT_EN_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_0_CTPATT_EN_CH_0_CTPATT_EN_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_0_CTPATT_EN_CH_0_CTPATT_EN_POS    0

#define LCU_PHY_LCU_CH_0_CTPATT_EN_CH_0_CTPATT_EN_RST    0x0

static inline u8 lcu_phy_lcu_ch_0_ctpatt_en_ch_0_ctpatt_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_CTPATT_EN_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_0_ctpatt_en_ch_0_ctpatt_en_setf(struct cl_chip *chip, u8 ch0ctpatten)
{
	ASSERT_ERR_CHIP((((u32)ch0ctpatten << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CTPATT_EN_ADDR, (u32)ch0ctpatten << 0);
}

/**
 * @brief LCU_CH_0_CTPATT_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH0_CTPATT_MODE           0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_CTPATT_MODE_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000F4)
#define LCU_PHY_LCU_CH_0_CTPATT_MODE_OFFSET      0x000000F4
#define LCU_PHY_LCU_CH_0_CTPATT_MODE_INDEX       0x0000003D
#define LCU_PHY_LCU_CH_0_CTPATT_MODE_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_0_ctpatt_mode_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_0_CTPATT_MODE_ADDR);
}

static inline void lcu_phy_lcu_ch_0_ctpatt_mode_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CTPATT_MODE_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_0_CTPATT_MODE_CH_0_CTPATT_MODE_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_0_CTPATT_MODE_CH_0_CTPATT_MODE_POS    0

#define LCU_PHY_LCU_CH_0_CTPATT_MODE_CH_0_CTPATT_MODE_RST    0x0

static inline u8 lcu_phy_lcu_ch_0_ctpatt_mode_ch_0_ctpatt_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_CTPATT_MODE_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_0_ctpatt_mode_ch_0_ctpatt_mode_setf(struct cl_chip *chip, u8 ch0ctpattmode)
{
	ASSERT_ERR_CHIP((((u32)ch0ctpattmode << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_0_CTPATT_MODE_ADDR, (u32)ch0ctpattmode << 0);
}

/**
 * @brief LCU_CH_1_CTPATT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_CTPATT_EN             0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_CTPATT_EN_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000F8)
#define LCU_PHY_LCU_CH_1_CTPATT_EN_OFFSET      0x000000F8
#define LCU_PHY_LCU_CH_1_CTPATT_EN_INDEX       0x0000003E
#define LCU_PHY_LCU_CH_1_CTPATT_EN_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_1_ctpatt_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_1_CTPATT_EN_ADDR);
}

static inline void lcu_phy_lcu_ch_1_ctpatt_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_CTPATT_EN_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_1_CTPATT_EN_CH_1_CTPATT_EN_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_1_CTPATT_EN_CH_1_CTPATT_EN_POS    0

#define LCU_PHY_LCU_CH_1_CTPATT_EN_CH_1_CTPATT_EN_RST    0x0

static inline u8 lcu_phy_lcu_ch_1_ctpatt_en_ch_1_ctpatt_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_CTPATT_EN_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_1_ctpatt_en_ch_1_ctpatt_en_setf(struct cl_chip *chip, u8 ch1ctpatten)
{
	ASSERT_ERR_CHIP((((u32)ch1ctpatten << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_CTPATT_EN_ADDR, (u32)ch1ctpatten << 0);
}

/**
 * @brief LCU_CH_1_CTPATT_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    CH1_CTPATT_MODE           0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_CTPATT_MODE_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x000000FC)
#define LCU_PHY_LCU_CH_1_CTPATT_MODE_OFFSET      0x000000FC
#define LCU_PHY_LCU_CH_1_CTPATT_MODE_INDEX       0x0000003F
#define LCU_PHY_LCU_CH_1_CTPATT_MODE_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_1_ctpatt_mode_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_1_CTPATT_MODE_ADDR);
}

static inline void lcu_phy_lcu_ch_1_ctpatt_mode_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_CTPATT_MODE_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_1_CTPATT_MODE_CH_1_CTPATT_MODE_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_CH_1_CTPATT_MODE_CH_1_CTPATT_MODE_POS    0

#define LCU_PHY_LCU_CH_1_CTPATT_MODE_CH_1_CTPATT_MODE_RST    0x0

static inline u8 lcu_phy_lcu_ch_1_ctpatt_mode_ch_1_ctpatt_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_CTPATT_MODE_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_1_ctpatt_mode_ch_1_ctpatt_mode_setf(struct cl_chip *chip, u8 ch1ctpattmode)
{
	ASSERT_ERR_CHIP((((u32)ch1ctpattmode << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_1_CTPATT_MODE_ADDR, (u32)ch1ctpattmode << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000100)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_OFFSET      0x00000100
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_INDEX       0x00000040
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_CH_01_CTPATT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_CH_01_CTPATT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_CH_01_CTPATT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_0_ch_01_ctpatt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_0_ch_01_ctpatt_ptrn_setf(struct cl_chip *chip, u32 ch01ctpattptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_0_ADDR, (u32)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000104)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_OFFSET      0x00000104
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_INDEX       0x00000041
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_CH_01_CTPATT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_CH_01_CTPATT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_CH_01_CTPATT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_1_ch_01_ctpatt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_1_ch_01_ctpatt_ptrn_setf(struct cl_chip *chip, u32 ch01ctpattptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_1_ADDR, (u32)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000108)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_OFFSET      0x00000108
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_INDEX       0x00000042
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_CH_01_CTPATT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_CH_01_CTPATT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_CH_01_CTPATT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_2_ch_01_ctpatt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_2_ch_01_ctpatt_ptrn_setf(struct cl_chip *chip, u32 ch01ctpattptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_2_ADDR, (u32)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000010C)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_OFFSET      0x0000010C
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_INDEX       0x00000043
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_CH_01_CTPATT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_CH_01_CTPATT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_CH_01_CTPATT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_3_ch_01_ctpatt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_3_ch_01_ctpatt_ptrn_setf(struct cl_chip *chip, u32 ch01ctpattptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_3_ADDR, (u32)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000110)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_OFFSET      0x00000110
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_INDEX       0x00000044
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_CH_01_CTPATT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_CH_01_CTPATT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_CH_01_CTPATT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_4_ch_01_ctpatt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_4_ch_01_ctpatt_ptrn_setf(struct cl_chip *chip, u32 ch01ctpattptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_4_ADDR, (u32)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000114)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_OFFSET      0x00000114
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_INDEX       0x00000045
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_CH_01_CTPATT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_CH_01_CTPATT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_CH_01_CTPATT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_5_ch_01_ctpatt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_5_ch_01_ctpatt_ptrn_setf(struct cl_chip *chip, u32 ch01ctpattptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_5_ADDR, (u32)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000118)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_OFFSET      0x00000118
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_INDEX       0x00000046
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_CH_01_CTPATT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_CH_01_CTPATT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_CH_01_CTPATT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_6_ch_01_ctpatt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_6_ch_01_ctpatt_ptrn_setf(struct cl_chip *chip, u32 ch01ctpattptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_6_ADDR, (u32)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_PTRN_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_PTRN          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000011C)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_OFFSET      0x0000011C
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_INDEX       0x00000047
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_CH_01_CTPATT_PTRN_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_CH_01_CTPATT_PTRN_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_CH_01_CTPATT_PTRN_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_CH_01_CTPATT_PTRN_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_7_ch_01_ctpatt_ptrn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_ptrn_reg_7_ch_01_ctpatt_ptrn_setf(struct cl_chip *chip, u32 ch01ctpattptrn)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattptrn << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_PTRN_REG_7_ADDR, (u32)ch01ctpattptrn << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000120)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_OFFSET      0x00000120
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_INDEX       0x00000048
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_CH_01_CTPATT_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_CH_01_CTPATT_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_CH_01_CTPATT_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_0_ch_01_ctpatt_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_0_ch_01_ctpatt_mask_setf(struct cl_chip *chip, u32 ch01ctpattmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_0_ADDR, (u32)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000124)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_OFFSET      0x00000124
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_INDEX       0x00000049
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_CH_01_CTPATT_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_CH_01_CTPATT_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_CH_01_CTPATT_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_1_ch_01_ctpatt_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_1_ch_01_ctpatt_mask_setf(struct cl_chip *chip, u32 ch01ctpattmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_1_ADDR, (u32)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000128)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_OFFSET      0x00000128
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_INDEX       0x0000004A
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_CH_01_CTPATT_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_CH_01_CTPATT_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_CH_01_CTPATT_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_2_ch_01_ctpatt_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_2_ch_01_ctpatt_mask_setf(struct cl_chip *chip, u32 ch01ctpattmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_2_ADDR, (u32)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000012C)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_OFFSET      0x0000012C
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_INDEX       0x0000004B
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_CH_01_CTPATT_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_CH_01_CTPATT_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_CH_01_CTPATT_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_3_ch_01_ctpatt_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_3_ch_01_ctpatt_mask_setf(struct cl_chip *chip, u32 ch01ctpattmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_3_ADDR, (u32)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000130)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_OFFSET      0x00000130
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_INDEX       0x0000004C
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_CH_01_CTPATT_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_CH_01_CTPATT_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_CH_01_CTPATT_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_4_ch_01_ctpatt_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_4_ch_01_ctpatt_mask_setf(struct cl_chip *chip, u32 ch01ctpattmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_4_ADDR, (u32)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000134)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_OFFSET      0x00000134
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_INDEX       0x0000004D
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_CH_01_CTPATT_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_CH_01_CTPATT_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_CH_01_CTPATT_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_5_ch_01_ctpatt_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_5_ch_01_ctpatt_mask_setf(struct cl_chip *chip, u32 ch01ctpattmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_5_ADDR, (u32)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000138)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_OFFSET      0x00000138
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_INDEX       0x0000004E
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_CH_01_CTPATT_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_CH_01_CTPATT_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_CH_01_CTPATT_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_6_ch_01_ctpatt_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_6_ch_01_ctpatt_mask_setf(struct cl_chip *chip, u32 ch01ctpattmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_6_ADDR, (u32)ch01ctpattmask << 0);
}

/**
 * @brief LCU_CH_01_CTPATT_MASK_REG_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CH01_CTPATT_MASK          0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000013C)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_OFFSET      0x0000013C
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_INDEX       0x0000004F
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_ADDR);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_CH_01_CTPATT_MASK_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_CH_01_CTPATT_MASK_LSB    0
#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_CH_01_CTPATT_MASK_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_CH_01_CTPATT_MASK_RST    0x0

static inline u32 lcu_phy_lcu_ch_01_ctpatt_mask_reg_7_ch_01_ctpatt_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_ch_01_ctpatt_mask_reg_7_ch_01_ctpatt_mask_setf(struct cl_chip *chip, u32 ch01ctpattmask)
{
	ASSERT_ERR_CHIP((((u32)ch01ctpattmask << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_CH_01_CTPATT_MASK_REG_7_ADDR, (u32)ch01ctpattmask << 0);
}

/**
 * @brief LCU_MICTORS_BITMAP_REG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:24 MICTOR4_INDX              0x3F
 *    23:18 MICTOR3_INDX              0x3F
 *    17:12 MICTOR2_INDX              0x3F
 *    11:06 MICTOR1_INDX              0x3F
 *    05:00 MICTOR0_INDX              0x3F
 * </pre>
 */
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000140)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_OFFSET      0x00000140
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_INDEX       0x00000050
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_RESET       0x3FFFFFFF

static inline u32 lcu_phy_lcu_mictors_bitmap_reg_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);
}

static inline void lcu_phy_lcu_mictors_bitmap_reg_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_4_INDX_MASK    ((u32)0x3F000000)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_4_INDX_LSB    24
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_4_INDX_WIDTH    ((u32)0x00000006)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_3_INDX_MASK    ((u32)0x00FC0000)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_3_INDX_LSB    18
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_3_INDX_WIDTH    ((u32)0x00000006)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_2_INDX_MASK    ((u32)0x0003F000)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_2_INDX_LSB    12
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_2_INDX_WIDTH    ((u32)0x00000006)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_1_INDX_MASK    ((u32)0x00000FC0)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_1_INDX_LSB    6
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_1_INDX_WIDTH    ((u32)0x00000006)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_0_INDX_MASK    ((u32)0x0000003F)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_0_INDX_LSB    0
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_0_INDX_WIDTH    ((u32)0x00000006)

#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_4_INDX_RST    0x3F
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_3_INDX_RST    0x3F
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_2_INDX_RST    0x3F
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_1_INDX_RST    0x3F
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_0_MICTOR_0_INDX_RST    0x3F

static inline void lcu_phy_lcu_mictors_bitmap_reg_0_pack(struct cl_chip *chip, u8 mictor4_indx, u8 mictor3_indx, u8 mictor2_indx, u8 mictor1_indx, u8 mictor0_indx)
{
	ASSERT_ERR_CHIP((((u32)mictor4_indx << 24) & ~((u32)0x3F000000)) == 0);
	ASSERT_ERR_CHIP((((u32)mictor3_indx << 18) & ~((u32)0x00FC0000)) == 0);
	ASSERT_ERR_CHIP((((u32)mictor2_indx << 12) & ~((u32)0x0003F000)) == 0);
	ASSERT_ERR_CHIP((((u32)mictor1_indx << 6) & ~((u32)0x00000FC0)) == 0);
	ASSERT_ERR_CHIP((((u32)mictor0_indx << 0) & ~((u32)0x0000003F)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, ((u32)mictor4_indx << 24) | ((u32)mictor3_indx << 18) | ((u32)mictor2_indx << 12) | ((u32)mictor1_indx << 6) | ((u32)mictor0_indx << 0));
}

static inline void lcu_phy_lcu_mictors_bitmap_reg_0_unpack(struct cl_chip *chip, u8 *mictor4_indx, u8 *mictor3_indx, u8 *mictor2_indx, u8 *mictor1_indx, u8 *mictor0_indx)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);

	*mictor4_indx = (local_val & ((u32)0x3F000000)) >> 24;
	*mictor3_indx = (local_val & ((u32)0x00FC0000)) >> 18;
	*mictor2_indx = (local_val & ((u32)0x0003F000)) >> 12;
	*mictor1_indx = (local_val & ((u32)0x00000FC0)) >> 6;
	*mictor0_indx = (local_val & ((u32)0x0000003F)) >> 0;
}

static inline u8 lcu_phy_lcu_mictors_bitmap_reg_0_mictor_4_indx_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);

	return (u8)((local_val & ((u32)0x3F000000)) >> 24);
}

static inline void lcu_phy_lcu_mictors_bitmap_reg_0_mictor_4_indx_setf(struct cl_chip *chip, u8 mictor4indx)
{
	ASSERT_ERR_CHIP((((u32)mictor4indx << 24) & ~((u32)0x3F000000)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR) & ~((u32)0x3F000000)) | ((u32)mictor4indx << 24));
}

static inline u8 lcu_phy_lcu_mictors_bitmap_reg_0_mictor_3_indx_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);

	return (u8)((local_val & ((u32)0x00FC0000)) >> 18);
}

static inline void lcu_phy_lcu_mictors_bitmap_reg_0_mictor_3_indx_setf(struct cl_chip *chip, u8 mictor3indx)
{
	ASSERT_ERR_CHIP((((u32)mictor3indx << 18) & ~((u32)0x00FC0000)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR) & ~((u32)0x00FC0000)) | ((u32)mictor3indx << 18));
}

static inline u8 lcu_phy_lcu_mictors_bitmap_reg_0_mictor_2_indx_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);

	return (u8)((local_val & ((u32)0x0003F000)) >> 12);
}

static inline void lcu_phy_lcu_mictors_bitmap_reg_0_mictor_2_indx_setf(struct cl_chip *chip, u8 mictor2indx)
{
	ASSERT_ERR_CHIP((((u32)mictor2indx << 12) & ~((u32)0x0003F000)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR) & ~((u32)0x0003F000)) | ((u32)mictor2indx << 12));
}

static inline u8 lcu_phy_lcu_mictors_bitmap_reg_0_mictor_1_indx_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);

	return (u8)((local_val & ((u32)0x00000FC0)) >> 6);
}

static inline void lcu_phy_lcu_mictors_bitmap_reg_0_mictor_1_indx_setf(struct cl_chip *chip, u8 mictor1indx)
{
	ASSERT_ERR_CHIP((((u32)mictor1indx << 6) & ~((u32)0x00000FC0)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR) & ~((u32)0x00000FC0)) | ((u32)mictor1indx << 6));
}

static inline u8 lcu_phy_lcu_mictors_bitmap_reg_0_mictor_0_indx_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR);

	return (u8)((local_val & ((u32)0x0000003F)) >> 0);
}

static inline void lcu_phy_lcu_mictors_bitmap_reg_0_mictor_0_indx_setf(struct cl_chip *chip, u8 mictor0indx)
{
	ASSERT_ERR_CHIP((((u32)mictor0indx << 0) & ~((u32)0x0000003F)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_0_ADDR) & ~((u32)0x0000003F)) | ((u32)mictor0indx << 0));
}

/**
 * @brief LCU_MICTORS_BITMAP_REG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:06 MICTOR6_INDX              0x3F
 *    05:00 MICTOR5_INDX              0x3F
 * </pre>
 */
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000144)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_OFFSET      0x00000144
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_INDEX       0x00000051
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_RESET       0x00000FFF

static inline u32 lcu_phy_lcu_mictors_bitmap_reg_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR);
}

static inline void lcu_phy_lcu_mictors_bitmap_reg_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_6_INDX_MASK    ((u32)0x00000FC0)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_6_INDX_LSB    6
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_6_INDX_WIDTH    ((u32)0x00000006)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_5_INDX_MASK    ((u32)0x0000003F)
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_5_INDX_LSB    0
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_5_INDX_WIDTH    ((u32)0x00000006)

#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_6_INDX_RST    0x3F
#define LCU_PHY_LCU_MICTORS_BITMAP_REG_1_MICTOR_5_INDX_RST    0x3F

static inline void lcu_phy_lcu_mictors_bitmap_reg_1_pack(struct cl_chip *chip, u8 mictor6_indx, u8 mictor5_indx)
{
	ASSERT_ERR_CHIP((((u32)mictor6_indx << 6) & ~((u32)0x00000FC0)) == 0);
	ASSERT_ERR_CHIP((((u32)mictor5_indx << 0) & ~((u32)0x0000003F)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR, ((u32)mictor6_indx << 6) | ((u32)mictor5_indx << 0));
}

static inline void lcu_phy_lcu_mictors_bitmap_reg_1_unpack(struct cl_chip *chip, u8 *mictor6_indx, u8 *mictor5_indx)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR);

	*mictor6_indx = (local_val & ((u32)0x00000FC0)) >> 6;
	*mictor5_indx = (local_val & ((u32)0x0000003F)) >> 0;
}

static inline u8 lcu_phy_lcu_mictors_bitmap_reg_1_mictor_6_indx_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR);

	return (u8)((local_val & ((u32)0x00000FC0)) >> 6);
}

static inline void lcu_phy_lcu_mictors_bitmap_reg_1_mictor_6_indx_setf(struct cl_chip *chip, u8 mictor6indx)
{
	ASSERT_ERR_CHIP((((u32)mictor6indx << 6) & ~((u32)0x00000FC0)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR) & ~((u32)0x00000FC0)) | ((u32)mictor6indx << 6));
}

static inline u8 lcu_phy_lcu_mictors_bitmap_reg_1_mictor_5_indx_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR);

	return (u8)((local_val & ((u32)0x0000003F)) >> 0);
}

static inline void lcu_phy_lcu_mictors_bitmap_reg_1_mictor_5_indx_setf(struct cl_chip *chip, u8 mictor5indx)
{
	ASSERT_ERR_CHIP((((u32)mictor5indx << 0) & ~((u32)0x0000003F)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_MICTORS_BITMAP_REG_1_ADDR) & ~((u32)0x0000003F)) | ((u32)mictor5indx << 0));
}

/**
 * @brief LCU_DMEM_START_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DMEM_START_ADDR           0x0
 * </pre>
 */
#define LCU_PHY_LCU_DMEM_START_ADDR_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000148)
#define LCU_PHY_LCU_DMEM_START_ADDR_OFFSET      0x00000148
#define LCU_PHY_LCU_DMEM_START_ADDR_INDEX       0x00000052
#define LCU_PHY_LCU_DMEM_START_ADDR_RESET       0x00000000

static inline u32 lcu_phy_lcu_dmem_start_addr_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_DMEM_START_ADDR_ADDR);
}

static inline void lcu_phy_lcu_dmem_start_addr_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_DMEM_START_ADDR_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_DMEM_START_ADDR_DMEM_START_ADDR_MASK    ((u32)0xFFFFFFFF)
#define LCU_PHY_LCU_DMEM_START_ADDR_DMEM_START_ADDR_LSB    0
#define LCU_PHY_LCU_DMEM_START_ADDR_DMEM_START_ADDR_WIDTH    ((u32)0x00000020)

#define LCU_PHY_LCU_DMEM_START_ADDR_DMEM_START_ADDR_RST    0x0

static inline u32 lcu_phy_lcu_dmem_start_addr_dmem_start_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_DMEM_START_ADDR_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_dmem_start_addr_dmem_start_addr_setf(struct cl_chip *chip, u32 dmemstartaddr)
{
	ASSERT_ERR_CHIP((((u32)dmemstartaddr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_DMEM_START_ADDR_ADDR, (u32)dmemstartaddr << 0);
}

/**
 * @brief LCU_DMEM_SIZE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DMEM_SIZE                 0x0
 * </pre>
 */
#define LCU_PHY_LCU_DMEM_SIZE_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000014C)
#define LCU_PHY_LCU_DMEM_SIZE_OFFSET      0x0000014C
#define LCU_PHY_LCU_DMEM_SIZE_INDEX       0x00000053
#define LCU_PHY_LCU_DMEM_SIZE_RESET       0x00000000

static inline u32 lcu_phy_lcu_dmem_size_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_DMEM_SIZE_ADDR);
}

static inline void lcu_phy_lcu_dmem_size_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_DMEM_SIZE_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_DMEM_SIZE_DMEM_SIZE_MASK    ((u32)0x000FFFFF)
#define LCU_PHY_LCU_DMEM_SIZE_DMEM_SIZE_LSB    0
#define LCU_PHY_LCU_DMEM_SIZE_DMEM_SIZE_WIDTH    ((u32)0x00000014)

#define LCU_PHY_LCU_DMEM_SIZE_DMEM_SIZE_RST    0x0

static inline u32 lcu_phy_lcu_dmem_size_dmem_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_DMEM_SIZE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void lcu_phy_lcu_dmem_size_dmem_size_setf(struct cl_chip *chip, u32 dmemsize)
{
	ASSERT_ERR_CHIP((((u32)dmemsize << 0) & ~((u32)0x000FFFFF)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_DMEM_SIZE_ADDR, (u32)dmemsize << 0);
}

/**
 * @brief LCU_MPIF_DATA_SEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 MPIF_DATA_SEL             0x1
 * </pre>
 */
#define LCU_PHY_LCU_MPIF_DATA_SEL_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000150)
#define LCU_PHY_LCU_MPIF_DATA_SEL_OFFSET      0x00000150
#define LCU_PHY_LCU_MPIF_DATA_SEL_INDEX       0x00000054
#define LCU_PHY_LCU_MPIF_DATA_SEL_RESET       0x00000001

static inline u32 lcu_phy_lcu_mpif_data_sel_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_MPIF_DATA_SEL_ADDR);
}

static inline void lcu_phy_lcu_mpif_data_sel_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_MPIF_DATA_SEL_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_MPIF_DATA_SEL_MPIF_DATA_SEL_MASK    ((u32)0x00000003)
#define LCU_PHY_LCU_MPIF_DATA_SEL_MPIF_DATA_SEL_LSB    0
#define LCU_PHY_LCU_MPIF_DATA_SEL_MPIF_DATA_SEL_WIDTH    ((u32)0x00000002)

#define LCU_PHY_LCU_MPIF_DATA_SEL_MPIF_DATA_SEL_RST    0x1

static inline u8 lcu_phy_lcu_mpif_data_sel_mpif_data_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_MPIF_DATA_SEL_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_mpif_data_sel_mpif_data_sel_setf(struct cl_chip *chip, u8 mpifdatasel)
{
	ASSERT_ERR_CHIP((((u32)mpifdatasel << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_MPIF_DATA_SEL_ADDR, (u32)mpifdatasel << 0);
}

/**
 * @brief LCU_SW_RST register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    SW_RST                    0
 * </pre>
 */
#define LCU_PHY_LCU_SW_RST_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000154)
#define LCU_PHY_LCU_SW_RST_OFFSET      0x00000154
#define LCU_PHY_LCU_SW_RST_INDEX       0x00000055
#define LCU_PHY_LCU_SW_RST_RESET       0x00000000

static inline void lcu_phy_lcu_sw_rst_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_SW_RST_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_SW_RST_SW_RST_BIT       ((u32)0x00000001)
#define LCU_PHY_LCU_SW_RST_SW_RST_POS       0

#define LCU_PHY_LCU_SW_RST_SW_RST_RST       0x0

static inline void lcu_phy_lcu_sw_rst_sw_rst_setf(struct cl_chip *chip, u8 swrst)
{
	ASSERT_ERR_CHIP((((u32)swrst << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_SW_RST_ADDR, (u32)swrst << 0);
}

/**
 * @brief LCU_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    AXI_WDATA_FIFO_OVF        0
 *    04    AXI_ADDR_FIFO_OVF         0
 *    03    MICTOR2_OVF               0
 *    02    MICTOR1_OVF               0
 *    01    MICTOR0_OVF               0
 *    00    DSP_DMEM_FINISH           0
 * </pre>
 */
#define LCU_PHY_LCU_STATUS_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000158)
#define LCU_PHY_LCU_STATUS_OFFSET      0x00000158
#define LCU_PHY_LCU_STATUS_INDEX       0x00000056
#define LCU_PHY_LCU_STATUS_RESET       0x00000000

static inline u32 lcu_phy_lcu_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_STATUS_ADDR);
}

/* Field definitions */
#define LCU_PHY_LCU_STATUS_AXI_WDATA_FIFO_OVF_BIT    ((u32)0x00000020)
#define LCU_PHY_LCU_STATUS_AXI_WDATA_FIFO_OVF_POS    5
#define LCU_PHY_LCU_STATUS_AXI_ADDR_FIFO_OVF_BIT    ((u32)0x00000010)
#define LCU_PHY_LCU_STATUS_AXI_ADDR_FIFO_OVF_POS    4
#define LCU_PHY_LCU_STATUS_MICTOR_2_OVF_BIT    ((u32)0x00000008)
#define LCU_PHY_LCU_STATUS_MICTOR_2_OVF_POS    3
#define LCU_PHY_LCU_STATUS_MICTOR_1_OVF_BIT    ((u32)0x00000004)
#define LCU_PHY_LCU_STATUS_MICTOR_1_OVF_POS    2
#define LCU_PHY_LCU_STATUS_MICTOR_0_OVF_BIT    ((u32)0x00000002)
#define LCU_PHY_LCU_STATUS_MICTOR_0_OVF_POS    1
#define LCU_PHY_LCU_STATUS_DSP_DMEM_FINISH_BIT    ((u32)0x00000001)
#define LCU_PHY_LCU_STATUS_DSP_DMEM_FINISH_POS    0

#define LCU_PHY_LCU_STATUS_AXI_WDATA_FIFO_OVF_RST    0x0
#define LCU_PHY_LCU_STATUS_AXI_ADDR_FIFO_OVF_RST    0x0
#define LCU_PHY_LCU_STATUS_MICTOR_2_OVF_RST    0x0
#define LCU_PHY_LCU_STATUS_MICTOR_1_OVF_RST    0x0
#define LCU_PHY_LCU_STATUS_MICTOR_0_OVF_RST    0x0
#define LCU_PHY_LCU_STATUS_DSP_DMEM_FINISH_RST    0x0

static inline void lcu_phy_lcu_status_unpack(struct cl_chip *chip, u8 *axi_wdata_fifo_ovf, u8 *axi_addr_fifo_ovf, u8 *mictor2_ovf, u8 *mictor1_ovf, u8 *mictor0_ovf, u8 *dsp_dmem_finish)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_STATUS_ADDR);

	*axi_wdata_fifo_ovf = (local_val & ((u32)0x00000020)) >> 5;
	*axi_addr_fifo_ovf = (local_val & ((u32)0x00000010)) >> 4;
	*mictor2_ovf = (local_val & ((u32)0x00000008)) >> 3;
	*mictor1_ovf = (local_val & ((u32)0x00000004)) >> 2;
	*mictor0_ovf = (local_val & ((u32)0x00000002)) >> 1;
	*dsp_dmem_finish = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 lcu_phy_lcu_status_axi_wdata_fifo_ovf_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000020)) >> 5);
}

static inline u8 lcu_phy_lcu_status_axi_addr_fifo_ovf_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline u8 lcu_phy_lcu_status_mictor_2_ovf_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline u8 lcu_phy_lcu_status_mictor_1_ovf_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline u8 lcu_phy_lcu_status_mictor_0_ovf_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline u8 lcu_phy_lcu_status_dsp_dmem_finish_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

/**
 * @brief LCU_CH_0_TRIG_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 CH0_EXT_STOP_TRIG_STAT    0x0
 *    13:12 CH0_FIC_STOP_TRIG_STAT    0x0
 *    09:08 CH0_STOP_PTRN_TRIG_STAT   0x0
 *    05:04 CH0_EXT_STRT_TRIG_STAT    0x0
 *    01:00 CH0_STRT_PTRN_TRIG_STAT   0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000015C)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_OFFSET      0x0000015C
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_INDEX       0x00000057
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_0_trig_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STOP_TRIG_STAT_MASK    ((u32)0x00030000)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STOP_TRIG_STAT_LSB    16
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STOP_TRIG_STAT_WIDTH    ((u32)0x00000002)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_FIC_STOP_TRIG_STAT_MASK    ((u32)0x00003000)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_FIC_STOP_TRIG_STAT_LSB    12
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_FIC_STOP_TRIG_STAT_WIDTH    ((u32)0x00000002)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STOP_PTRN_TRIG_STAT_MASK    ((u32)0x00000300)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STOP_PTRN_TRIG_STAT_LSB    8
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STOP_PTRN_TRIG_STAT_WIDTH    ((u32)0x00000002)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STRT_TRIG_STAT_MASK    ((u32)0x00000030)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STRT_TRIG_STAT_LSB    4
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STRT_TRIG_STAT_WIDTH    ((u32)0x00000002)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STRT_PTRN_TRIG_STAT_MASK    ((u32)0x00000003)
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STRT_PTRN_TRIG_STAT_LSB    0
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STRT_PTRN_TRIG_STAT_WIDTH    ((u32)0x00000002)

#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STOP_TRIG_STAT_RST    0x0
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_FIC_STOP_TRIG_STAT_RST    0x0
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STOP_PTRN_TRIG_STAT_RST    0x0
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_EXT_STRT_TRIG_STAT_RST    0x0
#define LCU_PHY_LCU_CH_0_TRIG_STATUS_CH_0_STRT_PTRN_TRIG_STAT_RST    0x0

static inline void lcu_phy_lcu_ch_0_trig_status_unpack(struct cl_chip *chip, u8 *ch0_ext_stop_trig_stat, u8 *ch0_fic_stop_trig_stat, u8 *ch0_stop_ptrn_trig_stat, u8 *ch0_ext_strt_trig_stat, u8 *ch0_strt_ptrn_trig_stat)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);

	*ch0_ext_stop_trig_stat = (local_val & ((u32)0x00030000)) >> 16;
	*ch0_fic_stop_trig_stat = (local_val & ((u32)0x00003000)) >> 12;
	*ch0_stop_ptrn_trig_stat = (local_val & ((u32)0x00000300)) >> 8;
	*ch0_ext_strt_trig_stat = (local_val & ((u32)0x00000030)) >> 4;
	*ch0_strt_ptrn_trig_stat = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u8 lcu_phy_lcu_ch_0_trig_status_ch_0_ext_stop_trig_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00030000)) >> 16);
}

static inline u8 lcu_phy_lcu_ch_0_trig_status_ch_0_fic_stop_trig_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00003000)) >> 12);
}

static inline u8 lcu_phy_lcu_ch_0_trig_status_ch_0_stop_ptrn_trig_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000300)) >> 8);
}

static inline u8 lcu_phy_lcu_ch_0_trig_status_ch_0_ext_strt_trig_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000030)) >> 4);
}

static inline u8 lcu_phy_lcu_ch_0_trig_status_ch_0_strt_ptrn_trig_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_0_TRIG_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

/**
 * @brief LCU_CH_1_TRIG_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:08 CH1_FIC_STOP_TRIG_STAT    0x0
 *    05:04 CH1_STOP_PTRN_TRIG_STAT   0x0
 *    01:00 CH1_STRT_PTRN_TRIG_STAT   0x0
 * </pre>
 */
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000160)
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_OFFSET      0x00000160
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_INDEX       0x00000058
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_RESET       0x00000000

static inline u32 lcu_phy_lcu_ch_1_trig_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_CH_1_TRIG_STATUS_ADDR);
}

/* Field definitions */
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_FIC_STOP_TRIG_STAT_MASK    ((u32)0x00000300)
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_FIC_STOP_TRIG_STAT_LSB    8
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_FIC_STOP_TRIG_STAT_WIDTH    ((u32)0x00000002)
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STOP_PTRN_TRIG_STAT_MASK    ((u32)0x00000030)
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STOP_PTRN_TRIG_STAT_LSB    4
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STOP_PTRN_TRIG_STAT_WIDTH    ((u32)0x00000002)
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STRT_PTRN_TRIG_STAT_MASK    ((u32)0x00000003)
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STRT_PTRN_TRIG_STAT_LSB    0
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STRT_PTRN_TRIG_STAT_WIDTH    ((u32)0x00000002)

#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_FIC_STOP_TRIG_STAT_RST    0x0
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STOP_PTRN_TRIG_STAT_RST    0x0
#define LCU_PHY_LCU_CH_1_TRIG_STATUS_CH_1_STRT_PTRN_TRIG_STAT_RST    0x0

static inline void lcu_phy_lcu_ch_1_trig_status_unpack(struct cl_chip *chip, u8 *ch1_fic_stop_trig_stat, u8 *ch1_stop_ptrn_trig_stat, u8 *ch1_strt_ptrn_trig_stat)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_TRIG_STATUS_ADDR);

	*ch1_fic_stop_trig_stat = (local_val & ((u32)0x00000300)) >> 8;
	*ch1_stop_ptrn_trig_stat = (local_val & ((u32)0x00000030)) >> 4;
	*ch1_strt_ptrn_trig_stat = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u8 lcu_phy_lcu_ch_1_trig_status_ch_1_fic_stop_trig_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_TRIG_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000300)) >> 8);
}

static inline u8 lcu_phy_lcu_ch_1_trig_status_ch_1_stop_ptrn_trig_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_TRIG_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000030)) >> 4);
}

static inline u8 lcu_phy_lcu_ch_1_trig_status_ch_1_strt_ptrn_trig_stat_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_CH_1_TRIG_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

/**
 * @brief LCU_RX_RIU_OUT_SEL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02:00 RX_RIU_OUT_SEL            0x0
 * </pre>
 */
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000164)
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_OFFSET      0x00000164
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_INDEX       0x00000059
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_RESET       0x00000000

static inline u32 lcu_phy_lcu_rx_riu_out_sel_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_RX_RIU_OUT_SEL_ADDR);
}

static inline void lcu_phy_lcu_rx_riu_out_sel_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_RX_RIU_OUT_SEL_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_RX_RIU_OUT_SEL_MASK    ((u32)0x00000007)
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_RX_RIU_OUT_SEL_LSB    0
#define LCU_PHY_LCU_RX_RIU_OUT_SEL_RX_RIU_OUT_SEL_WIDTH    ((u32)0x00000003)

#define LCU_PHY_LCU_RX_RIU_OUT_SEL_RX_RIU_OUT_SEL_RST    0x0

static inline u8 lcu_phy_lcu_rx_riu_out_sel_rx_riu_out_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_RX_RIU_OUT_SEL_ADDR);

	return (u8)(local_val >> 0);
}

static inline void lcu_phy_lcu_rx_riu_out_sel_rx_riu_out_sel_setf(struct cl_chip *chip, u8 rxriuoutsel)
{
	ASSERT_ERR_CHIP((((u32)rxriuoutsel << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_RX_RIU_OUT_SEL_ADDR, (u32)rxriuoutsel << 0);
}

/**
 * @brief LCU_RIU_OUT_COMB_CONF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    S2_3_CONF                 0
 *    01:00 CH_BW                     0x0
 * </pre>
 */
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x00000168)
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_OFFSET      0x00000168
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_INDEX       0x0000005A
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_RESET       0x00000000

static inline u32 lcu_phy_lcu_riu_out_comb_conf_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR);
}

static inline void lcu_phy_lcu_riu_out_comb_conf_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_S_2_3_CONF_BIT    ((u32)0x00000004)
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_S_2_3_CONF_POS    2
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_CH_BW_MASK    ((u32)0x00000003)
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_CH_BW_LSB    0
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_CH_BW_WIDTH    ((u32)0x00000002)

#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_S_2_3_CONF_RST    0x0
#define LCU_PHY_LCU_RIU_OUT_COMB_CONF_CH_BW_RST    0x0

static inline void lcu_phy_lcu_riu_out_comb_conf_pack(struct cl_chip *chip, u8 s2_3_conf, u8 ch_bw)
{
	ASSERT_ERR_CHIP((((u32)s2_3_conf << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)ch_bw << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR, ((u32)s2_3_conf << 2) | ((u32)ch_bw << 0));
}

static inline void lcu_phy_lcu_riu_out_comb_conf_unpack(struct cl_chip *chip, u8 *s2_3_conf, u8 *ch_bw)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR);

	*s2_3_conf = (local_val & ((u32)0x00000004)) >> 2;
	*ch_bw = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u8 lcu_phy_lcu_riu_out_comb_conf_s_2_3_conf_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void lcu_phy_lcu_riu_out_comb_conf_s_2_3_conf_setf(struct cl_chip *chip, u8 s23conf)
{
	ASSERT_ERR_CHIP((((u32)s23conf << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR) & ~((u32)0x00000004)) | ((u32)s23conf << 2));
}

static inline u8 lcu_phy_lcu_riu_out_comb_conf_ch_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void lcu_phy_lcu_riu_out_comb_conf_ch_bw_setf(struct cl_chip *chip, u8 chbw)
{
	ASSERT_ERR_CHIP((((u32)chbw << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_RIU_OUT_COMB_CONF_ADDR) & ~((u32)0x00000003)) | ((u32)chbw << 0));
}

/**
 * @brief LCU_STATUS_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    AXI_WDATA_FIFO_OVF_CLEAR  0
 *    04    AXI_ADDR_FIFO_OVF_CLEAR   0
 *    03    MICTOR2_OVF_CLEAR         0
 *    02    MICTOR1_OVF_CLEAR         0
 *    01    MICTOR0_OVF_CLEAR         0
 * </pre>
 */
#define LCU_PHY_LCU_STATUS_CLEAR_ADDR        (REG_LCU_PHY_BASE_ADDR + 0x0000016C)
#define LCU_PHY_LCU_STATUS_CLEAR_OFFSET      0x0000016C
#define LCU_PHY_LCU_STATUS_CLEAR_INDEX       0x0000005B
#define LCU_PHY_LCU_STATUS_CLEAR_RESET       0x00000000

static inline void lcu_phy_lcu_status_clear_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, LCU_PHY_LCU_STATUS_CLEAR_ADDR, value);
}

/* Field definitions */
#define LCU_PHY_LCU_STATUS_CLEAR_AXI_WDATA_FIFO_OVF_CLEAR_BIT    ((u32)0x00000020)
#define LCU_PHY_LCU_STATUS_CLEAR_AXI_WDATA_FIFO_OVF_CLEAR_POS    5
#define LCU_PHY_LCU_STATUS_CLEAR_AXI_ADDR_FIFO_OVF_CLEAR_BIT    ((u32)0x00000010)
#define LCU_PHY_LCU_STATUS_CLEAR_AXI_ADDR_FIFO_OVF_CLEAR_POS    4
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_2_OVF_CLEAR_BIT    ((u32)0x00000008)
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_2_OVF_CLEAR_POS    3
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_1_OVF_CLEAR_BIT    ((u32)0x00000004)
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_1_OVF_CLEAR_POS    2
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_0_OVF_CLEAR_BIT    ((u32)0x00000002)
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_0_OVF_CLEAR_POS    1

#define LCU_PHY_LCU_STATUS_CLEAR_AXI_WDATA_FIFO_OVF_CLEAR_RST    0x0
#define LCU_PHY_LCU_STATUS_CLEAR_AXI_ADDR_FIFO_OVF_CLEAR_RST    0x0
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_2_OVF_CLEAR_RST    0x0
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_1_OVF_CLEAR_RST    0x0
#define LCU_PHY_LCU_STATUS_CLEAR_MICTOR_0_OVF_CLEAR_RST    0x0

static inline void lcu_phy_lcu_status_clear_pack(struct cl_chip *chip, u8 axi_wdata_fifo_ovf_clear, u8 axi_addr_fifo_ovf_clear, u8 mictor2_ovf_clear, u8 mictor1_ovf_clear, u8 mictor0_ovf_clear)
{
	ASSERT_ERR_CHIP((((u32)axi_wdata_fifo_ovf_clear << 5) & ~((u32)0x00000020)) == 0);
	ASSERT_ERR_CHIP((((u32)axi_addr_fifo_ovf_clear << 4) & ~((u32)0x00000010)) == 0);
	ASSERT_ERR_CHIP((((u32)mictor2_ovf_clear << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)mictor1_ovf_clear << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)mictor0_ovf_clear << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_STATUS_CLEAR_ADDR, ((u32)axi_wdata_fifo_ovf_clear << 5) | ((u32)axi_addr_fifo_ovf_clear << 4) | ((u32)mictor2_ovf_clear << 3) | ((u32)mictor1_ovf_clear << 2) | ((u32)mictor0_ovf_clear << 1));
}

static inline void lcu_phy_lcu_status_clear_axi_wdata_fifo_ovf_clear_setf(struct cl_chip *chip, u8 axiwdatafifoovfclear)
{
	ASSERT_ERR_CHIP((((u32)axiwdatafifoovfclear << 5) & ~((u32)0x00000020)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_STATUS_CLEAR_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_STATUS_CLEAR_ADDR) & ~((u32)0x00000020)) | ((u32)axiwdatafifoovfclear << 5));
}

static inline void lcu_phy_lcu_status_clear_axi_addr_fifo_ovf_clear_setf(struct cl_chip *chip, u8 axiaddrfifoovfclear)
{
	ASSERT_ERR_CHIP((((u32)axiaddrfifoovfclear << 4) & ~((u32)0x00000010)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_STATUS_CLEAR_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_STATUS_CLEAR_ADDR) & ~((u32)0x00000010)) | ((u32)axiaddrfifoovfclear << 4));
}

static inline void lcu_phy_lcu_status_clear_mictor_2_ovf_clear_setf(struct cl_chip *chip, u8 mictor2ovfclear)
{
	ASSERT_ERR_CHIP((((u32)mictor2ovfclear << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_STATUS_CLEAR_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_STATUS_CLEAR_ADDR) & ~((u32)0x00000008)) | ((u32)mictor2ovfclear << 3));
}

static inline void lcu_phy_lcu_status_clear_mictor_1_ovf_clear_setf(struct cl_chip *chip, u8 mictor1ovfclear)
{
	ASSERT_ERR_CHIP((((u32)mictor1ovfclear << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_STATUS_CLEAR_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_STATUS_CLEAR_ADDR) & ~((u32)0x00000004)) | ((u32)mictor1ovfclear << 2));
}

static inline void lcu_phy_lcu_status_clear_mictor_0_ovf_clear_setf(struct cl_chip *chip, u8 mictor0ovfclear)
{
	ASSERT_ERR_CHIP((((u32)mictor0ovfclear << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, LCU_PHY_LCU_STATUS_CLEAR_ADDR, (cl_reg_read(chip, LCU_PHY_LCU_STATUS_CLEAR_ADDR) & ~((u32)0x00000002)) | ((u32)mictor0ovfclear << 1));
}

#endif /* REG_LCU_PHY_H */
