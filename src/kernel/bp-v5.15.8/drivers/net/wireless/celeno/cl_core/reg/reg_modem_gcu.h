/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef REG_MODEM_GCU_H
#define REG_MODEM_GCU_H

#include <linux/types.h>
#include "reg_access.h"
#include "chip.h"

#define REG_MODEM_GCU_BASE_ADDR 0x004A0000

/**
 * @brief VERSION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:04 VERSION                   0x008000b
 *    03:00 PHY_WRAP_ID               0x0
 * </pre>
 */
#define MODEM_GCU_VERSION_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00000000)
#define MODEM_GCU_VERSION_OFFSET      0x00000000
#define MODEM_GCU_VERSION_INDEX       0x00000000
#define MODEM_GCU_VERSION_RESET       0x008000B0

static inline u32 modem_gcu_version_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_VERSION_ADDR);
}

/* Field definitions */
#define MODEM_GCU_VERSION_VERSION_MASK      ((u32)0xFFFFFFF0)
#define MODEM_GCU_VERSION_VERSION_LSB       4
#define MODEM_GCU_VERSION_VERSION_WIDTH     ((u32)0x0000001C)
#define MODEM_GCU_VERSION_PHY_WRAP_ID_MASK    ((u32)0x0000000F)
#define MODEM_GCU_VERSION_PHY_WRAP_ID_LSB    0
#define MODEM_GCU_VERSION_PHY_WRAP_ID_WIDTH    ((u32)0x00000004)

#define MODEM_GCU_VERSION_VERSION_RST       0x008000b
#define MODEM_GCU_VERSION_PHY_WRAP_ID_RST    0x0

static inline void modem_gcu_version_unpack(struct cl_chip *chip, u32 *version, u8 *phy_wrap_id)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_VERSION_ADDR);

	*version = (local_val & ((u32)0xFFFFFFF0)) >> 4;
	*phy_wrap_id = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u32 modem_gcu_version_version_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_VERSION_ADDR);

	return (u32)((local_val & ((u32)0xFFFFFFF0)) >> 4);
}

static inline u8 modem_gcu_version_phy_wrap_id_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_VERSION_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

/**
 * @brief MPU register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    MPU_CLK_EN                0
 *    12    MPU_REG_CLK_EN            0
 *    01    MPU_RST_N                 0
 *    00    MPU_REG_RST_N             0
 * </pre>
 */
#define MODEM_GCU_MPU_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00000004)
#define MODEM_GCU_MPU_OFFSET      0x00000004
#define MODEM_GCU_MPU_INDEX       0x00000001
#define MODEM_GCU_MPU_RESET       0x00000000

static inline u32 modem_gcu_mpu_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_MPU_ADDR);
}

static inline void modem_gcu_mpu_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_MPU_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_MPU_MPU_CLK_EN_BIT        ((u32)0x00002000)
#define MODEM_GCU_MPU_MPU_CLK_EN_POS        13
#define MODEM_GCU_MPU_MPU_REG_CLK_EN_BIT    ((u32)0x00001000)
#define MODEM_GCU_MPU_MPU_REG_CLK_EN_POS    12
#define MODEM_GCU_MPU_MPU_RST_N_BIT         ((u32)0x00000002)
#define MODEM_GCU_MPU_MPU_RST_N_POS         1
#define MODEM_GCU_MPU_MPU_REG_RST_N_BIT     ((u32)0x00000001)
#define MODEM_GCU_MPU_MPU_REG_RST_N_POS     0

#define MODEM_GCU_MPU_MPU_CLK_EN_RST        0x0
#define MODEM_GCU_MPU_MPU_REG_CLK_EN_RST    0x0
#define MODEM_GCU_MPU_MPU_RST_N_RST         0x0
#define MODEM_GCU_MPU_MPU_REG_RST_N_RST     0x0

static inline void modem_gcu_mpu_pack(struct cl_chip *chip, u8 mpu_clk_en, u8 mpu_reg_clk_en, u8 mpu_rst_n, u8 mpu_reg_rst_n)
{
	ASSERT_ERR_CHIP((((u32)mpu_clk_en << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)mpu_reg_clk_en << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)mpu_rst_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)mpu_reg_rst_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_MPU_ADDR, ((u32)mpu_clk_en << 13) | ((u32)mpu_reg_clk_en << 12) | ((u32)mpu_rst_n << 1) | ((u32)mpu_reg_rst_n << 0));
}

static inline void modem_gcu_mpu_unpack(struct cl_chip *chip, u8 *mpu_clk_en, u8 *mpu_reg_clk_en, u8 *mpu_rst_n, u8 *mpu_reg_rst_n)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MPU_ADDR);

	*mpu_clk_en = (local_val & ((u32)0x00002000)) >> 13;
	*mpu_reg_clk_en = (local_val & ((u32)0x00001000)) >> 12;
	*mpu_rst_n = (local_val & ((u32)0x00000002)) >> 1;
	*mpu_reg_rst_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_mpu_mpu_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MPU_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void modem_gcu_mpu_mpu_clk_en_setf(struct cl_chip *chip, u8 mpuclken)
{
	ASSERT_ERR_CHIP((((u32)mpuclken << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MODEM_GCU_MPU_ADDR, (cl_reg_read(chip, MODEM_GCU_MPU_ADDR) & ~((u32)0x00002000)) | ((u32)mpuclken << 13));
}

static inline u8 modem_gcu_mpu_mpu_reg_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MPU_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void modem_gcu_mpu_mpu_reg_clk_en_setf(struct cl_chip *chip, u8 mpuregclken)
{
	ASSERT_ERR_CHIP((((u32)mpuregclken << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MODEM_GCU_MPU_ADDR, (cl_reg_read(chip, MODEM_GCU_MPU_ADDR) & ~((u32)0x00001000)) | ((u32)mpuregclken << 12));
}

static inline u8 modem_gcu_mpu_mpu_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MPU_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_mpu_mpu_rst_n_setf(struct cl_chip *chip, u8 mpurstn)
{
	ASSERT_ERR_CHIP((((u32)mpurstn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_MPU_ADDR, (cl_reg_read(chip, MODEM_GCU_MPU_ADDR) & ~((u32)0x00000002)) | ((u32)mpurstn << 1));
}

static inline u8 modem_gcu_mpu_mpu_reg_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MPU_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_mpu_mpu_reg_rst_n_setf(struct cl_chip *chip, u8 mpuregrstn)
{
	ASSERT_ERR_CHIP((((u32)mpuregrstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_MPU_ADDR, (cl_reg_read(chip, MODEM_GCU_MPU_ADDR) & ~((u32)0x00000001)) | ((u32)mpuregrstn << 0));
}

/**
 * @brief BPU register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    BPUL_RX_CLK_EN            0
 *    15    BPU_CLK_EN                0
 *    14    BPU_RX_CLK_EN             0
 *    13    BPU_TX_CLK_EN             0
 *    12    BPU_REG_CLK_EN            0
 *    03    BPU_RST_N                 0
 *    02    BPU_RX_RST_N              0
 *    01    BPU_TX_RST_N              0
 *    00    BPU_REG_RST_N             0
 * </pre>
 */
#define MODEM_GCU_BPU_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00000008)
#define MODEM_GCU_BPU_OFFSET      0x00000008
#define MODEM_GCU_BPU_INDEX       0x00000002
#define MODEM_GCU_BPU_RESET       0x00000000

static inline u32 modem_gcu_bpu_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_BPU_ADDR);
}

static inline void modem_gcu_bpu_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_BPU_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_BPU_BPUL_RX_CLK_EN_BIT    ((u32)0x00010000)
#define MODEM_GCU_BPU_BPUL_RX_CLK_EN_POS    16
#define MODEM_GCU_BPU_BPU_CLK_EN_BIT        ((u32)0x00008000)
#define MODEM_GCU_BPU_BPU_CLK_EN_POS        15
#define MODEM_GCU_BPU_BPU_RX_CLK_EN_BIT     ((u32)0x00004000)
#define MODEM_GCU_BPU_BPU_RX_CLK_EN_POS     14
#define MODEM_GCU_BPU_BPU_TX_CLK_EN_BIT     ((u32)0x00002000)
#define MODEM_GCU_BPU_BPU_TX_CLK_EN_POS     13
#define MODEM_GCU_BPU_BPU_REG_CLK_EN_BIT    ((u32)0x00001000)
#define MODEM_GCU_BPU_BPU_REG_CLK_EN_POS    12
#define MODEM_GCU_BPU_BPU_RST_N_BIT         ((u32)0x00000008)
#define MODEM_GCU_BPU_BPU_RST_N_POS         3
#define MODEM_GCU_BPU_BPU_RX_RST_N_BIT      ((u32)0x00000004)
#define MODEM_GCU_BPU_BPU_RX_RST_N_POS      2
#define MODEM_GCU_BPU_BPU_TX_RST_N_BIT      ((u32)0x00000002)
#define MODEM_GCU_BPU_BPU_TX_RST_N_POS      1
#define MODEM_GCU_BPU_BPU_REG_RST_N_BIT     ((u32)0x00000001)
#define MODEM_GCU_BPU_BPU_REG_RST_N_POS     0

#define MODEM_GCU_BPU_BPUL_RX_CLK_EN_RST    0x0
#define MODEM_GCU_BPU_BPU_CLK_EN_RST        0x0
#define MODEM_GCU_BPU_BPU_RX_CLK_EN_RST     0x0
#define MODEM_GCU_BPU_BPU_TX_CLK_EN_RST     0x0
#define MODEM_GCU_BPU_BPU_REG_CLK_EN_RST    0x0
#define MODEM_GCU_BPU_BPU_RST_N_RST         0x0
#define MODEM_GCU_BPU_BPU_RX_RST_N_RST      0x0
#define MODEM_GCU_BPU_BPU_TX_RST_N_RST      0x0
#define MODEM_GCU_BPU_BPU_REG_RST_N_RST     0x0

static inline void modem_gcu_bpu_pack(struct cl_chip *chip, u8 bpul_rx_clk_en, u8 bpu_clk_en, u8 bpu_rx_clk_en, u8 bpu_tx_clk_en, u8 bpu_reg_clk_en, u8 bpu_rst_n, u8 bpu_rx_rst_n, u8 bpu_tx_rst_n, u8 bpu_reg_rst_n)
{
	ASSERT_ERR_CHIP((((u32)bpul_rx_clk_en << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)bpu_clk_en << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)bpu_rx_clk_en << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)bpu_tx_clk_en << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)bpu_reg_clk_en << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)bpu_rst_n << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)bpu_rx_rst_n << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)bpu_tx_rst_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)bpu_reg_rst_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_BPU_ADDR, ((u32)bpul_rx_clk_en << 16) | ((u32)bpu_clk_en << 15) | ((u32)bpu_rx_clk_en << 14) | ((u32)bpu_tx_clk_en << 13) | ((u32)bpu_reg_clk_en << 12) | ((u32)bpu_rst_n << 3) | ((u32)bpu_rx_rst_n << 2) | ((u32)bpu_tx_rst_n << 1) | ((u32)bpu_reg_rst_n << 0));
}

static inline void modem_gcu_bpu_unpack(struct cl_chip *chip, u8 *bpul_rx_clk_en, u8 *bpu_clk_en, u8 *bpu_rx_clk_en, u8 *bpu_tx_clk_en, u8 *bpu_reg_clk_en, u8 *bpu_rst_n, u8 *bpu_rx_rst_n, u8 *bpu_tx_rst_n, u8 *bpu_reg_rst_n)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BPU_ADDR);

	*bpul_rx_clk_en = (local_val & ((u32)0x00010000)) >> 16;
	*bpu_clk_en = (local_val & ((u32)0x00008000)) >> 15;
	*bpu_rx_clk_en = (local_val & ((u32)0x00004000)) >> 14;
	*bpu_tx_clk_en = (local_val & ((u32)0x00002000)) >> 13;
	*bpu_reg_clk_en = (local_val & ((u32)0x00001000)) >> 12;
	*bpu_rst_n = (local_val & ((u32)0x00000008)) >> 3;
	*bpu_rx_rst_n = (local_val & ((u32)0x00000004)) >> 2;
	*bpu_tx_rst_n = (local_val & ((u32)0x00000002)) >> 1;
	*bpu_reg_rst_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_bpu_bpul_rx_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BPU_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void modem_gcu_bpu_bpul_rx_clk_en_setf(struct cl_chip *chip, u8 bpulrxclken)
{
	ASSERT_ERR_CHIP((((u32)bpulrxclken << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, MODEM_GCU_BPU_ADDR, (cl_reg_read(chip, MODEM_GCU_BPU_ADDR) & ~((u32)0x00010000)) | ((u32)bpulrxclken << 16));
}

static inline u8 modem_gcu_bpu_bpu_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BPU_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void modem_gcu_bpu_bpu_clk_en_setf(struct cl_chip *chip, u8 bpuclken)
{
	ASSERT_ERR_CHIP((((u32)bpuclken << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, MODEM_GCU_BPU_ADDR, (cl_reg_read(chip, MODEM_GCU_BPU_ADDR) & ~((u32)0x00008000)) | ((u32)bpuclken << 15));
}

static inline u8 modem_gcu_bpu_bpu_rx_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BPU_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void modem_gcu_bpu_bpu_rx_clk_en_setf(struct cl_chip *chip, u8 bpurxclken)
{
	ASSERT_ERR_CHIP((((u32)bpurxclken << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, MODEM_GCU_BPU_ADDR, (cl_reg_read(chip, MODEM_GCU_BPU_ADDR) & ~((u32)0x00004000)) | ((u32)bpurxclken << 14));
}

static inline u8 modem_gcu_bpu_bpu_tx_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BPU_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void modem_gcu_bpu_bpu_tx_clk_en_setf(struct cl_chip *chip, u8 bputxclken)
{
	ASSERT_ERR_CHIP((((u32)bputxclken << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MODEM_GCU_BPU_ADDR, (cl_reg_read(chip, MODEM_GCU_BPU_ADDR) & ~((u32)0x00002000)) | ((u32)bputxclken << 13));
}

static inline u8 modem_gcu_bpu_bpu_reg_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BPU_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void modem_gcu_bpu_bpu_reg_clk_en_setf(struct cl_chip *chip, u8 bpuregclken)
{
	ASSERT_ERR_CHIP((((u32)bpuregclken << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MODEM_GCU_BPU_ADDR, (cl_reg_read(chip, MODEM_GCU_BPU_ADDR) & ~((u32)0x00001000)) | ((u32)bpuregclken << 12));
}

static inline u8 modem_gcu_bpu_bpu_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BPU_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void modem_gcu_bpu_bpu_rst_n_setf(struct cl_chip *chip, u8 bpurstn)
{
	ASSERT_ERR_CHIP((((u32)bpurstn << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, MODEM_GCU_BPU_ADDR, (cl_reg_read(chip, MODEM_GCU_BPU_ADDR) & ~((u32)0x00000008)) | ((u32)bpurstn << 3));
}

static inline u8 modem_gcu_bpu_bpu_rx_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BPU_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void modem_gcu_bpu_bpu_rx_rst_n_setf(struct cl_chip *chip, u8 bpurxrstn)
{
	ASSERT_ERR_CHIP((((u32)bpurxrstn << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, MODEM_GCU_BPU_ADDR, (cl_reg_read(chip, MODEM_GCU_BPU_ADDR) & ~((u32)0x00000004)) | ((u32)bpurxrstn << 2));
}

static inline u8 modem_gcu_bpu_bpu_tx_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BPU_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_bpu_bpu_tx_rst_n_setf(struct cl_chip *chip, u8 bputxrstn)
{
	ASSERT_ERR_CHIP((((u32)bputxrstn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_BPU_ADDR, (cl_reg_read(chip, MODEM_GCU_BPU_ADDR) & ~((u32)0x00000002)) | ((u32)bputxrstn << 1));
}

static inline u8 modem_gcu_bpu_bpu_reg_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BPU_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_bpu_bpu_reg_rst_n_setf(struct cl_chip *chip, u8 bpuregrstn)
{
	ASSERT_ERR_CHIP((((u32)bpuregrstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_BPU_ADDR, (cl_reg_read(chip, MODEM_GCU_BPU_ADDR) & ~((u32)0x00000001)) | ((u32)bpuregrstn << 0));
}

/**
 * @brief TFU register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    TFU_CLK_EN                0
 *    12    TFU_REG_CLK_EN            0
 *    01    TFU_RST_N                 0
 *    00    TFU_REG_RST_N             0
 * </pre>
 */
#define MODEM_GCU_TFU_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x0000000C)
#define MODEM_GCU_TFU_OFFSET      0x0000000C
#define MODEM_GCU_TFU_INDEX       0x00000003
#define MODEM_GCU_TFU_RESET       0x00000000

static inline u32 modem_gcu_tfu_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_TFU_ADDR);
}

static inline void modem_gcu_tfu_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_TFU_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_TFU_TFU_CLK_EN_BIT        ((u32)0x00002000)
#define MODEM_GCU_TFU_TFU_CLK_EN_POS        13
#define MODEM_GCU_TFU_TFU_REG_CLK_EN_BIT    ((u32)0x00001000)
#define MODEM_GCU_TFU_TFU_REG_CLK_EN_POS    12
#define MODEM_GCU_TFU_TFU_RST_N_BIT         ((u32)0x00000002)
#define MODEM_GCU_TFU_TFU_RST_N_POS         1
#define MODEM_GCU_TFU_TFU_REG_RST_N_BIT     ((u32)0x00000001)
#define MODEM_GCU_TFU_TFU_REG_RST_N_POS     0

#define MODEM_GCU_TFU_TFU_CLK_EN_RST        0x0
#define MODEM_GCU_TFU_TFU_REG_CLK_EN_RST    0x0
#define MODEM_GCU_TFU_TFU_RST_N_RST         0x0
#define MODEM_GCU_TFU_TFU_REG_RST_N_RST     0x0

static inline void modem_gcu_tfu_pack(struct cl_chip *chip, u8 tfu_clk_en, u8 tfu_reg_clk_en, u8 tfu_rst_n, u8 tfu_reg_rst_n)
{
	ASSERT_ERR_CHIP((((u32)tfu_clk_en << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)tfu_reg_clk_en << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)tfu_rst_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)tfu_reg_rst_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_TFU_ADDR, ((u32)tfu_clk_en << 13) | ((u32)tfu_reg_clk_en << 12) | ((u32)tfu_rst_n << 1) | ((u32)tfu_reg_rst_n << 0));
}

static inline void modem_gcu_tfu_unpack(struct cl_chip *chip, u8 *tfu_clk_en, u8 *tfu_reg_clk_en, u8 *tfu_rst_n, u8 *tfu_reg_rst_n)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TFU_ADDR);

	*tfu_clk_en = (local_val & ((u32)0x00002000)) >> 13;
	*tfu_reg_clk_en = (local_val & ((u32)0x00001000)) >> 12;
	*tfu_rst_n = (local_val & ((u32)0x00000002)) >> 1;
	*tfu_reg_rst_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_tfu_tfu_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TFU_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void modem_gcu_tfu_tfu_clk_en_setf(struct cl_chip *chip, u8 tfuclken)
{
	ASSERT_ERR_CHIP((((u32)tfuclken << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MODEM_GCU_TFU_ADDR, (cl_reg_read(chip, MODEM_GCU_TFU_ADDR) & ~((u32)0x00002000)) | ((u32)tfuclken << 13));
}

static inline u8 modem_gcu_tfu_tfu_reg_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TFU_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void modem_gcu_tfu_tfu_reg_clk_en_setf(struct cl_chip *chip, u8 tfuregclken)
{
	ASSERT_ERR_CHIP((((u32)tfuregclken << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MODEM_GCU_TFU_ADDR, (cl_reg_read(chip, MODEM_GCU_TFU_ADDR) & ~((u32)0x00001000)) | ((u32)tfuregclken << 12));
}

static inline u8 modem_gcu_tfu_tfu_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TFU_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_tfu_tfu_rst_n_setf(struct cl_chip *chip, u8 tfurstn)
{
	ASSERT_ERR_CHIP((((u32)tfurstn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_TFU_ADDR, (cl_reg_read(chip, MODEM_GCU_TFU_ADDR) & ~((u32)0x00000002)) | ((u32)tfurstn << 1));
}

static inline u8 modem_gcu_tfu_tfu_reg_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TFU_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_tfu_tfu_reg_rst_n_setf(struct cl_chip *chip, u8 tfuregrstn)
{
	ASSERT_ERR_CHIP((((u32)tfuregrstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_TFU_ADDR, (cl_reg_read(chip, MODEM_GCU_TFU_ADDR) & ~((u32)0x00000001)) | ((u32)tfuregrstn << 0));
}

/**
 * @brief SMU register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    SMU_CLK_EN                0
 *    12    SMU_REG_CLK_EN            0
 *    01    SMU_RST_N                 0
 *    00    SMU_REG_RST_N             0
 * </pre>
 */
#define MODEM_GCU_SMU_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00000010)
#define MODEM_GCU_SMU_OFFSET      0x00000010
#define MODEM_GCU_SMU_INDEX       0x00000004
#define MODEM_GCU_SMU_RESET       0x00000000

static inline u32 modem_gcu_smu_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_SMU_ADDR);
}

static inline void modem_gcu_smu_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_SMU_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_SMU_SMU_CLK_EN_BIT        ((u32)0x00002000)
#define MODEM_GCU_SMU_SMU_CLK_EN_POS        13
#define MODEM_GCU_SMU_SMU_REG_CLK_EN_BIT    ((u32)0x00001000)
#define MODEM_GCU_SMU_SMU_REG_CLK_EN_POS    12
#define MODEM_GCU_SMU_SMU_RST_N_BIT         ((u32)0x00000002)
#define MODEM_GCU_SMU_SMU_RST_N_POS         1
#define MODEM_GCU_SMU_SMU_REG_RST_N_BIT     ((u32)0x00000001)
#define MODEM_GCU_SMU_SMU_REG_RST_N_POS     0

#define MODEM_GCU_SMU_SMU_CLK_EN_RST        0x0
#define MODEM_GCU_SMU_SMU_REG_CLK_EN_RST    0x0
#define MODEM_GCU_SMU_SMU_RST_N_RST         0x0
#define MODEM_GCU_SMU_SMU_REG_RST_N_RST     0x0

static inline void modem_gcu_smu_pack(struct cl_chip *chip, u8 smu_clk_en, u8 smu_reg_clk_en, u8 smu_rst_n, u8 smu_reg_rst_n)
{
	ASSERT_ERR_CHIP((((u32)smu_clk_en << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)smu_reg_clk_en << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)smu_rst_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)smu_reg_rst_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_SMU_ADDR, ((u32)smu_clk_en << 13) | ((u32)smu_reg_clk_en << 12) | ((u32)smu_rst_n << 1) | ((u32)smu_reg_rst_n << 0));
}

static inline void modem_gcu_smu_unpack(struct cl_chip *chip, u8 *smu_clk_en, u8 *smu_reg_clk_en, u8 *smu_rst_n, u8 *smu_reg_rst_n)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_SMU_ADDR);

	*smu_clk_en = (local_val & ((u32)0x00002000)) >> 13;
	*smu_reg_clk_en = (local_val & ((u32)0x00001000)) >> 12;
	*smu_rst_n = (local_val & ((u32)0x00000002)) >> 1;
	*smu_reg_rst_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_smu_smu_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_SMU_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void modem_gcu_smu_smu_clk_en_setf(struct cl_chip *chip, u8 smuclken)
{
	ASSERT_ERR_CHIP((((u32)smuclken << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MODEM_GCU_SMU_ADDR, (cl_reg_read(chip, MODEM_GCU_SMU_ADDR) & ~((u32)0x00002000)) | ((u32)smuclken << 13));
}

static inline u8 modem_gcu_smu_smu_reg_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_SMU_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void modem_gcu_smu_smu_reg_clk_en_setf(struct cl_chip *chip, u8 smuregclken)
{
	ASSERT_ERR_CHIP((((u32)smuregclken << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MODEM_GCU_SMU_ADDR, (cl_reg_read(chip, MODEM_GCU_SMU_ADDR) & ~((u32)0x00001000)) | ((u32)smuregclken << 12));
}

static inline u8 modem_gcu_smu_smu_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_SMU_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_smu_smu_rst_n_setf(struct cl_chip *chip, u8 smurstn)
{
	ASSERT_ERR_CHIP((((u32)smurstn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_SMU_ADDR, (cl_reg_read(chip, MODEM_GCU_SMU_ADDR) & ~((u32)0x00000002)) | ((u32)smurstn << 1));
}

static inline u8 modem_gcu_smu_smu_reg_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_SMU_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_smu_smu_reg_rst_n_setf(struct cl_chip *chip, u8 smuregrstn)
{
	ASSERT_ERR_CHIP((((u32)smuregrstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_SMU_ADDR, (cl_reg_read(chip, MODEM_GCU_SMU_ADDR) & ~((u32)0x00000001)) | ((u32)smuregrstn << 0));
}

/**
 * @brief MUX_FIC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12    MUX_FIC_CLK_EN            0
 *    01    FIC_MUX_SOFT_RST_N        1
 *    00    MUX_FIC_RST_N             0
 * </pre>
 */
#define MODEM_GCU_MUX_FIC_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00000014)
#define MODEM_GCU_MUX_FIC_OFFSET      0x00000014
#define MODEM_GCU_MUX_FIC_INDEX       0x00000005
#define MODEM_GCU_MUX_FIC_RESET       0x00000002

static inline u32 modem_gcu_mux_fic_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_MUX_FIC_ADDR);
}

static inline void modem_gcu_mux_fic_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_MUX_FIC_MUX_FIC_CLK_EN_BIT    ((u32)0x00001000)
#define MODEM_GCU_MUX_FIC_MUX_FIC_CLK_EN_POS    12
#define MODEM_GCU_MUX_FIC_FIC_MUX_SOFT_RST_N_BIT    ((u32)0x00000002)
#define MODEM_GCU_MUX_FIC_FIC_MUX_SOFT_RST_N_POS    1
#define MODEM_GCU_MUX_FIC_MUX_FIC_RST_N_BIT    ((u32)0x00000001)
#define MODEM_GCU_MUX_FIC_MUX_FIC_RST_N_POS    0

#define MODEM_GCU_MUX_FIC_MUX_FIC_CLK_EN_RST    0x0
#define MODEM_GCU_MUX_FIC_FIC_MUX_SOFT_RST_N_RST    0x1
#define MODEM_GCU_MUX_FIC_MUX_FIC_RST_N_RST    0x0

static inline void modem_gcu_mux_fic_pack(struct cl_chip *chip, u8 mux_fic_clk_en, u8 fic_mux_soft_rst_n, u8 mux_fic_rst_n)
{
	ASSERT_ERR_CHIP((((u32)mux_fic_clk_en << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)fic_mux_soft_rst_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_fic_rst_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_ADDR, ((u32)mux_fic_clk_en << 12) | ((u32)fic_mux_soft_rst_n << 1) | ((u32)mux_fic_rst_n << 0));
}

static inline void modem_gcu_mux_fic_unpack(struct cl_chip *chip, u8 *mux_fic_clk_en, u8 *fic_mux_soft_rst_n, u8 *mux_fic_rst_n)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MUX_FIC_ADDR);

	*mux_fic_clk_en = (local_val & ((u32)0x00001000)) >> 12;
	*fic_mux_soft_rst_n = (local_val & ((u32)0x00000002)) >> 1;
	*mux_fic_rst_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_mux_fic_mux_fic_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MUX_FIC_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void modem_gcu_mux_fic_mux_fic_clk_en_setf(struct cl_chip *chip, u8 muxficclken)
{
	ASSERT_ERR_CHIP((((u32)muxficclken << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_ADDR, (cl_reg_read(chip, MODEM_GCU_MUX_FIC_ADDR) & ~((u32)0x00001000)) | ((u32)muxficclken << 12));
}

static inline u8 modem_gcu_mux_fic_fic_mux_soft_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MUX_FIC_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_mux_fic_fic_mux_soft_rst_n_setf(struct cl_chip *chip, u8 ficmuxsoftrstn)
{
	ASSERT_ERR_CHIP((((u32)ficmuxsoftrstn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_ADDR, (cl_reg_read(chip, MODEM_GCU_MUX_FIC_ADDR) & ~((u32)0x00000002)) | ((u32)ficmuxsoftrstn << 1));
}

static inline u8 modem_gcu_mux_fic_mux_fic_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MUX_FIC_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_mux_fic_mux_fic_rst_n_setf(struct cl_chip *chip, u8 muxficrstn)
{
	ASSERT_ERR_CHIP((((u32)muxficrstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_ADDR, (cl_reg_read(chip, MODEM_GCU_MUX_FIC_ADDR) & ~((u32)0x00000001)) | ((u32)muxficrstn << 0));
}

/**
 * @brief MUX_FIC_MESS_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MUX_FIC_MESS_PTR          0x0
 * </pre>
 */
#define MODEM_GCU_MUX_FIC_MESS_PTR_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00000018)
#define MODEM_GCU_MUX_FIC_MESS_PTR_OFFSET      0x00000018
#define MODEM_GCU_MUX_FIC_MESS_PTR_INDEX       0x00000006
#define MODEM_GCU_MUX_FIC_MESS_PTR_RESET       0x00000000

static inline u32 modem_gcu_mux_fic_mess_ptr_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_MUX_FIC_MESS_PTR_ADDR);
}

static inline void modem_gcu_mux_fic_mess_ptr_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_MESS_PTR_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_MUX_FIC_MESS_PTR_MUX_FIC_MESS_PTR_MASK    ((u32)0xFFFFFFFF)
#define MODEM_GCU_MUX_FIC_MESS_PTR_MUX_FIC_MESS_PTR_LSB    0
#define MODEM_GCU_MUX_FIC_MESS_PTR_MUX_FIC_MESS_PTR_WIDTH    ((u32)0x00000020)

#define MODEM_GCU_MUX_FIC_MESS_PTR_MUX_FIC_MESS_PTR_RST    0x0

static inline u32 modem_gcu_mux_fic_mess_ptr_mux_fic_mess_ptr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MUX_FIC_MESS_PTR_ADDR);

	return (u32)(local_val >> 0);
}

static inline void modem_gcu_mux_fic_mess_ptr_mux_fic_mess_ptr_setf(struct cl_chip *chip, u32 muxficmessptr)
{
	ASSERT_ERR_CHIP((((u32)muxficmessptr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_MESS_PTR_ADDR, (u32)muxficmessptr << 0);
}

/**
 * @brief MUX_FIC_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    FIC_ISOLATED              0
 *    17    FIC_ISOLATE               0
 *    16    DISABLE_FIC_MESS          0
 *    15:08 MUX_FIC_CONFLICT_DELAY_WRITE 0x0
 *    07:00 MUX_FIC_CONFLICT_DELAY_READ 0x0
 * </pre>
 */
#define MODEM_GCU_MUX_FIC_CONFIG_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x0000001C)
#define MODEM_GCU_MUX_FIC_CONFIG_OFFSET      0x0000001C
#define MODEM_GCU_MUX_FIC_CONFIG_INDEX       0x00000007
#define MODEM_GCU_MUX_FIC_CONFIG_RESET       0x00000000

static inline u32 modem_gcu_mux_fic_config_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR);
}

static inline void modem_gcu_mux_fic_config_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_MUX_FIC_CONFIG_FIC_ISOLATED_BIT    ((u32)0x80000000)
#define MODEM_GCU_MUX_FIC_CONFIG_FIC_ISOLATED_POS    31
#define MODEM_GCU_MUX_FIC_CONFIG_FIC_ISOLATE_BIT    ((u32)0x00020000)
#define MODEM_GCU_MUX_FIC_CONFIG_FIC_ISOLATE_POS    17
#define MODEM_GCU_MUX_FIC_CONFIG_DISABLE_FIC_MESS_BIT    ((u32)0x00010000)
#define MODEM_GCU_MUX_FIC_CONFIG_DISABLE_FIC_MESS_POS    16
#define MODEM_GCU_MUX_FIC_CONFIG_MUX_FIC_CONFLICT_DELAY_WRITE_MASK    ((u32)0x0000FF00)
#define MODEM_GCU_MUX_FIC_CONFIG_MUX_FIC_CONFLICT_DELAY_WRITE_LSB    8
#define MODEM_GCU_MUX_FIC_CONFIG_MUX_FIC_CONFLICT_DELAY_WRITE_WIDTH    ((u32)0x00000008)
#define MODEM_GCU_MUX_FIC_CONFIG_MUX_FIC_CONFLICT_DELAY_READ_MASK    ((u32)0x000000FF)
#define MODEM_GCU_MUX_FIC_CONFIG_MUX_FIC_CONFLICT_DELAY_READ_LSB    0
#define MODEM_GCU_MUX_FIC_CONFIG_MUX_FIC_CONFLICT_DELAY_READ_WIDTH    ((u32)0x00000008)

#define MODEM_GCU_MUX_FIC_CONFIG_FIC_ISOLATED_RST    0x0
#define MODEM_GCU_MUX_FIC_CONFIG_FIC_ISOLATE_RST    0x0
#define MODEM_GCU_MUX_FIC_CONFIG_DISABLE_FIC_MESS_RST    0x0
#define MODEM_GCU_MUX_FIC_CONFIG_MUX_FIC_CONFLICT_DELAY_WRITE_RST    0x0
#define MODEM_GCU_MUX_FIC_CONFIG_MUX_FIC_CONFLICT_DELAY_READ_RST    0x0

static inline void modem_gcu_mux_fic_config_pack(struct cl_chip *chip, u8 fic_isolated, u8 fic_isolate, u8 disable_fic_mess, u8 mux_fic_conflict_delay_write, u8 mux_fic_conflict_delay_read)
{
	ASSERT_ERR_CHIP((((u32)fic_isolated << 31) & ~((u32)0x80000000)) == 0);
	ASSERT_ERR_CHIP((((u32)fic_isolate << 17) & ~((u32)0x00020000)) == 0);
	ASSERT_ERR_CHIP((((u32)disable_fic_mess << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_fic_conflict_delay_write << 8) & ~((u32)0x0000FF00)) == 0);
	ASSERT_ERR_CHIP((((u32)mux_fic_conflict_delay_read << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR, ((u32)fic_isolated << 31) | ((u32)fic_isolate << 17) | ((u32)disable_fic_mess << 16) | ((u32)mux_fic_conflict_delay_write << 8) | ((u32)mux_fic_conflict_delay_read << 0));
}

static inline void modem_gcu_mux_fic_config_unpack(struct cl_chip *chip, u8 *fic_isolated, u8 *fic_isolate, u8 *disable_fic_mess, u8 *mux_fic_conflict_delay_write, u8 *mux_fic_conflict_delay_read)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR);

	*fic_isolated = (local_val & ((u32)0x80000000)) >> 31;
	*fic_isolate = (local_val & ((u32)0x00020000)) >> 17;
	*disable_fic_mess = (local_val & ((u32)0x00010000)) >> 16;
	*mux_fic_conflict_delay_write = (local_val & ((u32)0x0000FF00)) >> 8;
	*mux_fic_conflict_delay_read = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u8 modem_gcu_mux_fic_config_fic_isolated_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR);

	return (u8)((local_val & ((u32)0x80000000)) >> 31);
}

static inline void modem_gcu_mux_fic_config_fic_isolated_setf(struct cl_chip *chip, u8 ficisolated)
{
	ASSERT_ERR_CHIP((((u32)ficisolated << 31) & ~((u32)0x80000000)) == 0);
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR, (cl_reg_read(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR) & ~((u32)0x80000000)) | ((u32)ficisolated << 31));
}

static inline u8 modem_gcu_mux_fic_config_fic_isolate_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR);

	return (u8)((local_val & ((u32)0x00020000)) >> 17);
}

static inline void modem_gcu_mux_fic_config_fic_isolate_setf(struct cl_chip *chip, u8 ficisolate)
{
	ASSERT_ERR_CHIP((((u32)ficisolate << 17) & ~((u32)0x00020000)) == 0);
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR, (cl_reg_read(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR) & ~((u32)0x00020000)) | ((u32)ficisolate << 17));
}

static inline u8 modem_gcu_mux_fic_config_disable_fic_mess_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void modem_gcu_mux_fic_config_disable_fic_mess_setf(struct cl_chip *chip, u8 disableficmess)
{
	ASSERT_ERR_CHIP((((u32)disableficmess << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR, (cl_reg_read(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR) & ~((u32)0x00010000)) | ((u32)disableficmess << 16));
}

static inline u8 modem_gcu_mux_fic_config_mux_fic_conflict_delay_write_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR);

	return (u8)((local_val & ((u32)0x0000FF00)) >> 8);
}

static inline void modem_gcu_mux_fic_config_mux_fic_conflict_delay_write_setf(struct cl_chip *chip, u8 muxficconflictdelaywrite)
{
	ASSERT_ERR_CHIP((((u32)muxficconflictdelaywrite << 8) & ~((u32)0x0000FF00)) == 0);
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR, (cl_reg_read(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR) & ~((u32)0x0000FF00)) | ((u32)muxficconflictdelaywrite << 8));
}

static inline u8 modem_gcu_mux_fic_config_mux_fic_conflict_delay_read_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void modem_gcu_mux_fic_config_mux_fic_conflict_delay_read_setf(struct cl_chip *chip, u8 muxficconflictdelayread)
{
	ASSERT_ERR_CHIP((((u32)muxficconflictdelayread << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR, (cl_reg_read(chip, MODEM_GCU_MUX_FIC_CONFIG_ADDR) & ~((u32)0x000000FF)) | ((u32)muxficconflictdelayread << 0));
}

/**
 * @brief RIU_RST register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07    RIUFE_RST_N               0
 *    06    RIUAGC_RST_N              0
 *    05    RIU_MDM_B_RST_N           0
 *    04    RIULB_RST_N               0
 *    03    RIURC_RST_N               0
 *    02    RIU_RADAR_RST_N           0
 *    01    RIU_RST_N                 0
 *    00    RIU_REG_RST_N             0
 * </pre>
 */
#define MODEM_GCU_RIU_RST_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00000020)
#define MODEM_GCU_RIU_RST_OFFSET      0x00000020
#define MODEM_GCU_RIU_RST_INDEX       0x00000008
#define MODEM_GCU_RIU_RST_RESET       0x00000000

static inline u32 modem_gcu_riu_rst_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR);
}

static inline void modem_gcu_riu_rst_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_RIU_RST_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_RIU_RST_RIUFE_RST_N_BIT    ((u32)0x00000080)
#define MODEM_GCU_RIU_RST_RIUFE_RST_N_POS    7
#define MODEM_GCU_RIU_RST_RIUAGC_RST_N_BIT    ((u32)0x00000040)
#define MODEM_GCU_RIU_RST_RIUAGC_RST_N_POS    6
#define MODEM_GCU_RIU_RST_RIU_MDM_B_RST_N_BIT    ((u32)0x00000020)
#define MODEM_GCU_RIU_RST_RIU_MDM_B_RST_N_POS    5
#define MODEM_GCU_RIU_RST_RIULB_RST_N_BIT    ((u32)0x00000010)
#define MODEM_GCU_RIU_RST_RIULB_RST_N_POS    4
#define MODEM_GCU_RIU_RST_RIURC_RST_N_BIT    ((u32)0x00000008)
#define MODEM_GCU_RIU_RST_RIURC_RST_N_POS    3
#define MODEM_GCU_RIU_RST_RIU_RADAR_RST_N_BIT    ((u32)0x00000004)
#define MODEM_GCU_RIU_RST_RIU_RADAR_RST_N_POS    2
#define MODEM_GCU_RIU_RST_RIU_RST_N_BIT     ((u32)0x00000002)
#define MODEM_GCU_RIU_RST_RIU_RST_N_POS     1
#define MODEM_GCU_RIU_RST_RIU_REG_RST_N_BIT    ((u32)0x00000001)
#define MODEM_GCU_RIU_RST_RIU_REG_RST_N_POS    0

#define MODEM_GCU_RIU_RST_RIUFE_RST_N_RST    0x0
#define MODEM_GCU_RIU_RST_RIUAGC_RST_N_RST    0x0
#define MODEM_GCU_RIU_RST_RIU_MDM_B_RST_N_RST    0x0
#define MODEM_GCU_RIU_RST_RIULB_RST_N_RST    0x0
#define MODEM_GCU_RIU_RST_RIURC_RST_N_RST    0x0
#define MODEM_GCU_RIU_RST_RIU_RADAR_RST_N_RST    0x0
#define MODEM_GCU_RIU_RST_RIU_RST_N_RST     0x0
#define MODEM_GCU_RIU_RST_RIU_REG_RST_N_RST    0x0

static inline void modem_gcu_riu_rst_pack(struct cl_chip *chip, u8 riufe_rst_n, u8 riuagc_rst_n, u8 riu_mdm_b_rst_n, u8 riulb_rst_n, u8 riurc_rst_n, u8 riu_radar_rst_n, u8 riu_rst_n, u8 riu_reg_rst_n)
{
	ASSERT_ERR_CHIP((((u32)riufe_rst_n << 7) & ~((u32)0x00000080)) == 0);
	ASSERT_ERR_CHIP((((u32)riuagc_rst_n << 6) & ~((u32)0x00000040)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_mdm_b_rst_n << 5) & ~((u32)0x00000020)) == 0);
	ASSERT_ERR_CHIP((((u32)riulb_rst_n << 4) & ~((u32)0x00000010)) == 0);
	ASSERT_ERR_CHIP((((u32)riurc_rst_n << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_radar_rst_n << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_rst_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_reg_rst_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_RST_ADDR, ((u32)riufe_rst_n << 7) | ((u32)riuagc_rst_n << 6) | ((u32)riu_mdm_b_rst_n << 5) | ((u32)riulb_rst_n << 4) | ((u32)riurc_rst_n << 3) | ((u32)riu_radar_rst_n << 2) | ((u32)riu_rst_n << 1) | ((u32)riu_reg_rst_n << 0));
}

static inline void modem_gcu_riu_rst_unpack(struct cl_chip *chip, u8 *riufe_rst_n, u8 *riuagc_rst_n, u8 *riu_mdm_b_rst_n, u8 *riulb_rst_n, u8 *riurc_rst_n, u8 *riu_radar_rst_n, u8 *riu_rst_n, u8 *riu_reg_rst_n)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR);

	*riufe_rst_n = (local_val & ((u32)0x00000080)) >> 7;
	*riuagc_rst_n = (local_val & ((u32)0x00000040)) >> 6;
	*riu_mdm_b_rst_n = (local_val & ((u32)0x00000020)) >> 5;
	*riulb_rst_n = (local_val & ((u32)0x00000010)) >> 4;
	*riurc_rst_n = (local_val & ((u32)0x00000008)) >> 3;
	*riu_radar_rst_n = (local_val & ((u32)0x00000004)) >> 2;
	*riu_rst_n = (local_val & ((u32)0x00000002)) >> 1;
	*riu_reg_rst_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_riu_rst_riufe_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000080)) >> 7);
}

static inline void modem_gcu_riu_rst_riufe_rst_n_setf(struct cl_chip *chip, u8 riuferstn)
{
	ASSERT_ERR_CHIP((((u32)riuferstn << 7) & ~((u32)0x00000080)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_RST_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR) & ~((u32)0x00000080)) | ((u32)riuferstn << 7));
}

static inline u8 modem_gcu_riu_rst_riuagc_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000040)) >> 6);
}

static inline void modem_gcu_riu_rst_riuagc_rst_n_setf(struct cl_chip *chip, u8 riuagcrstn)
{
	ASSERT_ERR_CHIP((((u32)riuagcrstn << 6) & ~((u32)0x00000040)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_RST_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR) & ~((u32)0x00000040)) | ((u32)riuagcrstn << 6));
}

static inline u8 modem_gcu_riu_rst_riu_mdm_b_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000020)) >> 5);
}

static inline void modem_gcu_riu_rst_riu_mdm_b_rst_n_setf(struct cl_chip *chip, u8 riumdmbrstn)
{
	ASSERT_ERR_CHIP((((u32)riumdmbrstn << 5) & ~((u32)0x00000020)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_RST_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR) & ~((u32)0x00000020)) | ((u32)riumdmbrstn << 5));
}

static inline u8 modem_gcu_riu_rst_riulb_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline void modem_gcu_riu_rst_riulb_rst_n_setf(struct cl_chip *chip, u8 riulbrstn)
{
	ASSERT_ERR_CHIP((((u32)riulbrstn << 4) & ~((u32)0x00000010)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_RST_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR) & ~((u32)0x00000010)) | ((u32)riulbrstn << 4));
}

static inline u8 modem_gcu_riu_rst_riurc_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void modem_gcu_riu_rst_riurc_rst_n_setf(struct cl_chip *chip, u8 riurcrstn)
{
	ASSERT_ERR_CHIP((((u32)riurcrstn << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_RST_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR) & ~((u32)0x00000008)) | ((u32)riurcrstn << 3));
}

static inline u8 modem_gcu_riu_rst_riu_radar_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void modem_gcu_riu_rst_riu_radar_rst_n_setf(struct cl_chip *chip, u8 riuradarrstn)
{
	ASSERT_ERR_CHIP((((u32)riuradarrstn << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_RST_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR) & ~((u32)0x00000004)) | ((u32)riuradarrstn << 2));
}

static inline u8 modem_gcu_riu_rst_riu_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_riu_rst_riu_rst_n_setf(struct cl_chip *chip, u8 riurstn)
{
	ASSERT_ERR_CHIP((((u32)riurstn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_RST_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR) & ~((u32)0x00000002)) | ((u32)riurstn << 1));
}

static inline u8 modem_gcu_riu_rst_riu_reg_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_riu_rst_riu_reg_rst_n_setf(struct cl_chip *chip, u8 riuregrstn)
{
	ASSERT_ERR_CHIP((((u32)riuregrstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_RST_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_RST_ADDR) & ~((u32)0x00000001)) | ((u32)riuregrstn << 0));
}

/**
 * @brief RIU_CLK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17    RIUFE_EXT_CLK_EN          0
 *    16    RIUFRC_CLK_EN             0
 *    15    RIUADC_PWR_CLK_EN         0
 *    14    RIUFEA_5_CLK_EN           0
 *    13    RIUFEA_4_CLK_EN           0
 *    12    RIUFEA_3_CLK_EN           0
 *    11    RIUFEA_2_CLK_EN           0
 *    10    RIUFEA_1_CLK_EN           0
 *    09    RIUFEA_0_CLK_EN           0
 *    08    RIU_MDM_B_TX_CLK_EN       0
 *    07    RIU_MDM_B_RX_CLK_EN       0
 *    06    RIU_MDM_B_CLK_EN          0
 *    05    RIULB_CLK_EN              0
 *    04    RIURCR_CLK_EN             0
 *    03    RIU_RADAR_CLK_EN          0
 *    02    RIUAGC_CLK_EN             0
 *    01    RIU_CLK_EN                0
 *    00    RIU_REG_CLK_EN            0
 * </pre>
 */
#define MODEM_GCU_RIU_CLK_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00000024)
#define MODEM_GCU_RIU_CLK_OFFSET      0x00000024
#define MODEM_GCU_RIU_CLK_INDEX       0x00000009
#define MODEM_GCU_RIU_CLK_RESET       0x00000000

static inline u32 modem_gcu_riu_clk_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);
}

static inline void modem_gcu_riu_clk_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_RIU_CLK_RIUFE_EXT_CLK_EN_BIT    ((u32)0x00020000)
#define MODEM_GCU_RIU_CLK_RIUFE_EXT_CLK_EN_POS    17
#define MODEM_GCU_RIU_CLK_RIUFRC_CLK_EN_BIT    ((u32)0x00010000)
#define MODEM_GCU_RIU_CLK_RIUFRC_CLK_EN_POS    16
#define MODEM_GCU_RIU_CLK_RIUADC_PWR_CLK_EN_BIT    ((u32)0x00008000)
#define MODEM_GCU_RIU_CLK_RIUADC_PWR_CLK_EN_POS    15
#define MODEM_GCU_RIU_CLK_RIUFEA_5_CLK_EN_BIT    ((u32)0x00004000)
#define MODEM_GCU_RIU_CLK_RIUFEA_5_CLK_EN_POS    14
#define MODEM_GCU_RIU_CLK_RIUFEA_4_CLK_EN_BIT    ((u32)0x00002000)
#define MODEM_GCU_RIU_CLK_RIUFEA_4_CLK_EN_POS    13
#define MODEM_GCU_RIU_CLK_RIUFEA_3_CLK_EN_BIT    ((u32)0x00001000)
#define MODEM_GCU_RIU_CLK_RIUFEA_3_CLK_EN_POS    12
#define MODEM_GCU_RIU_CLK_RIUFEA_2_CLK_EN_BIT    ((u32)0x00000800)
#define MODEM_GCU_RIU_CLK_RIUFEA_2_CLK_EN_POS    11
#define MODEM_GCU_RIU_CLK_RIUFEA_1_CLK_EN_BIT    ((u32)0x00000400)
#define MODEM_GCU_RIU_CLK_RIUFEA_1_CLK_EN_POS    10
#define MODEM_GCU_RIU_CLK_RIUFEA_0_CLK_EN_BIT    ((u32)0x00000200)
#define MODEM_GCU_RIU_CLK_RIUFEA_0_CLK_EN_POS    9
#define MODEM_GCU_RIU_CLK_RIU_MDM_B_TX_CLK_EN_BIT    ((u32)0x00000100)
#define MODEM_GCU_RIU_CLK_RIU_MDM_B_TX_CLK_EN_POS    8
#define MODEM_GCU_RIU_CLK_RIU_MDM_B_RX_CLK_EN_BIT    ((u32)0x00000080)
#define MODEM_GCU_RIU_CLK_RIU_MDM_B_RX_CLK_EN_POS    7
#define MODEM_GCU_RIU_CLK_RIU_MDM_B_CLK_EN_BIT    ((u32)0x00000040)
#define MODEM_GCU_RIU_CLK_RIU_MDM_B_CLK_EN_POS    6
#define MODEM_GCU_RIU_CLK_RIULB_CLK_EN_BIT    ((u32)0x00000020)
#define MODEM_GCU_RIU_CLK_RIULB_CLK_EN_POS    5
#define MODEM_GCU_RIU_CLK_RIURCR_CLK_EN_BIT    ((u32)0x00000010)
#define MODEM_GCU_RIU_CLK_RIURCR_CLK_EN_POS    4
#define MODEM_GCU_RIU_CLK_RIU_RADAR_CLK_EN_BIT    ((u32)0x00000008)
#define MODEM_GCU_RIU_CLK_RIU_RADAR_CLK_EN_POS    3
#define MODEM_GCU_RIU_CLK_RIUAGC_CLK_EN_BIT    ((u32)0x00000004)
#define MODEM_GCU_RIU_CLK_RIUAGC_CLK_EN_POS    2
#define MODEM_GCU_RIU_CLK_RIU_CLK_EN_BIT    ((u32)0x00000002)
#define MODEM_GCU_RIU_CLK_RIU_CLK_EN_POS    1
#define MODEM_GCU_RIU_CLK_RIU_REG_CLK_EN_BIT    ((u32)0x00000001)
#define MODEM_GCU_RIU_CLK_RIU_REG_CLK_EN_POS    0

#define MODEM_GCU_RIU_CLK_RIUFE_EXT_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIUFRC_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIUADC_PWR_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIUFEA_5_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIUFEA_4_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIUFEA_3_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIUFEA_2_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIUFEA_1_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIUFEA_0_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIU_MDM_B_TX_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIU_MDM_B_RX_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIU_MDM_B_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIULB_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIURCR_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIU_RADAR_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIUAGC_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIU_CLK_EN_RST    0x0
#define MODEM_GCU_RIU_CLK_RIU_REG_CLK_EN_RST    0x0

static inline void modem_gcu_riu_clk_pack(struct cl_chip *chip, u8 riufe_ext_clk_en, u8 riufrc_clk_en, u8 riuadc_pwr_clk_en, u8 riufea_5_clk_en, u8 riufea_4_clk_en, u8 riufea_3_clk_en, u8 riufea_2_clk_en, u8 riufea_1_clk_en, u8 riufea_0_clk_en, u8 riu_mdm_b_tx_clk_en, u8 riu_mdm_b_rx_clk_en, u8 riu_mdm_b_clk_en, u8 riulb_clk_en, u8 riurcr_clk_en, u8 riu_radar_clk_en, u8 riuagc_clk_en, u8 riu_clk_en, u8 riu_reg_clk_en)
{
	ASSERT_ERR_CHIP((((u32)riufe_ext_clk_en << 17) & ~((u32)0x00020000)) == 0);
	ASSERT_ERR_CHIP((((u32)riufrc_clk_en << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)riuadc_pwr_clk_en << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)riufea_5_clk_en << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)riufea_4_clk_en << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)riufea_3_clk_en << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)riufea_2_clk_en << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)riufea_1_clk_en << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)riufea_0_clk_en << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_mdm_b_tx_clk_en << 8) & ~((u32)0x00000100)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_mdm_b_rx_clk_en << 7) & ~((u32)0x00000080)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_mdm_b_clk_en << 6) & ~((u32)0x00000040)) == 0);
	ASSERT_ERR_CHIP((((u32)riulb_clk_en << 5) & ~((u32)0x00000020)) == 0);
	ASSERT_ERR_CHIP((((u32)riurcr_clk_en << 4) & ~((u32)0x00000010)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_radar_clk_en << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)riuagc_clk_en << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_clk_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_reg_clk_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, ((u32)riufe_ext_clk_en << 17) | ((u32)riufrc_clk_en << 16) | ((u32)riuadc_pwr_clk_en << 15) | ((u32)riufea_5_clk_en << 14) | ((u32)riufea_4_clk_en << 13) | ((u32)riufea_3_clk_en << 12) | ((u32)riufea_2_clk_en << 11) | ((u32)riufea_1_clk_en << 10) | ((u32)riufea_0_clk_en << 9) | ((u32)riu_mdm_b_tx_clk_en << 8) | ((u32)riu_mdm_b_rx_clk_en << 7) | ((u32)riu_mdm_b_clk_en << 6) | ((u32)riulb_clk_en << 5) | ((u32)riurcr_clk_en << 4) | ((u32)riu_radar_clk_en << 3) | ((u32)riuagc_clk_en << 2) | ((u32)riu_clk_en << 1) | ((u32)riu_reg_clk_en << 0));
}

static inline void modem_gcu_riu_clk_unpack(struct cl_chip *chip, u8 *riufe_ext_clk_en, u8 *riufrc_clk_en, u8 *riuadc_pwr_clk_en, u8 *riufea_5_clk_en, u8 *riufea_4_clk_en, u8 *riufea_3_clk_en, u8 *riufea_2_clk_en, u8 *riufea_1_clk_en, u8 *riufea_0_clk_en, u8 *riu_mdm_b_tx_clk_en, u8 *riu_mdm_b_rx_clk_en, u8 *riu_mdm_b_clk_en, u8 *riulb_clk_en, u8 *riurcr_clk_en, u8 *riu_radar_clk_en, u8 *riuagc_clk_en, u8 *riu_clk_en, u8 *riu_reg_clk_en)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	*riufe_ext_clk_en = (local_val & ((u32)0x00020000)) >> 17;
	*riufrc_clk_en = (local_val & ((u32)0x00010000)) >> 16;
	*riuadc_pwr_clk_en = (local_val & ((u32)0x00008000)) >> 15;
	*riufea_5_clk_en = (local_val & ((u32)0x00004000)) >> 14;
	*riufea_4_clk_en = (local_val & ((u32)0x00002000)) >> 13;
	*riufea_3_clk_en = (local_val & ((u32)0x00001000)) >> 12;
	*riufea_2_clk_en = (local_val & ((u32)0x00000800)) >> 11;
	*riufea_1_clk_en = (local_val & ((u32)0x00000400)) >> 10;
	*riufea_0_clk_en = (local_val & ((u32)0x00000200)) >> 9;
	*riu_mdm_b_tx_clk_en = (local_val & ((u32)0x00000100)) >> 8;
	*riu_mdm_b_rx_clk_en = (local_val & ((u32)0x00000080)) >> 7;
	*riu_mdm_b_clk_en = (local_val & ((u32)0x00000040)) >> 6;
	*riulb_clk_en = (local_val & ((u32)0x00000020)) >> 5;
	*riurcr_clk_en = (local_val & ((u32)0x00000010)) >> 4;
	*riu_radar_clk_en = (local_val & ((u32)0x00000008)) >> 3;
	*riuagc_clk_en = (local_val & ((u32)0x00000004)) >> 2;
	*riu_clk_en = (local_val & ((u32)0x00000002)) >> 1;
	*riu_reg_clk_en = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_riu_clk_riufe_ext_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00020000)) >> 17);
}

static inline void modem_gcu_riu_clk_riufe_ext_clk_en_setf(struct cl_chip *chip, u8 riufeextclken)
{
	ASSERT_ERR_CHIP((((u32)riufeextclken << 17) & ~((u32)0x00020000)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00020000)) | ((u32)riufeextclken << 17));
}

static inline u8 modem_gcu_riu_clk_riufrc_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void modem_gcu_riu_clk_riufrc_clk_en_setf(struct cl_chip *chip, u8 riufrcclken)
{
	ASSERT_ERR_CHIP((((u32)riufrcclken << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00010000)) | ((u32)riufrcclken << 16));
}

static inline u8 modem_gcu_riu_clk_riuadc_pwr_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void modem_gcu_riu_clk_riuadc_pwr_clk_en_setf(struct cl_chip *chip, u8 riuadcpwrclken)
{
	ASSERT_ERR_CHIP((((u32)riuadcpwrclken << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00008000)) | ((u32)riuadcpwrclken << 15));
}

static inline u8 modem_gcu_riu_clk_riufea_5_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void modem_gcu_riu_clk_riufea_5_clk_en_setf(struct cl_chip *chip, u8 riufea5clken)
{
	ASSERT_ERR_CHIP((((u32)riufea5clken << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00004000)) | ((u32)riufea5clken << 14));
}

static inline u8 modem_gcu_riu_clk_riufea_4_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void modem_gcu_riu_clk_riufea_4_clk_en_setf(struct cl_chip *chip, u8 riufea4clken)
{
	ASSERT_ERR_CHIP((((u32)riufea4clken << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00002000)) | ((u32)riufea4clken << 13));
}

static inline u8 modem_gcu_riu_clk_riufea_3_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void modem_gcu_riu_clk_riufea_3_clk_en_setf(struct cl_chip *chip, u8 riufea3clken)
{
	ASSERT_ERR_CHIP((((u32)riufea3clken << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00001000)) | ((u32)riufea3clken << 12));
}

static inline u8 modem_gcu_riu_clk_riufea_2_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void modem_gcu_riu_clk_riufea_2_clk_en_setf(struct cl_chip *chip, u8 riufea2clken)
{
	ASSERT_ERR_CHIP((((u32)riufea2clken << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00000800)) | ((u32)riufea2clken << 11));
}

static inline u8 modem_gcu_riu_clk_riufea_1_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void modem_gcu_riu_clk_riufea_1_clk_en_setf(struct cl_chip *chip, u8 riufea1clken)
{
	ASSERT_ERR_CHIP((((u32)riufea1clken << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00000400)) | ((u32)riufea1clken << 10));
}

static inline u8 modem_gcu_riu_clk_riufea_0_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void modem_gcu_riu_clk_riufea_0_clk_en_setf(struct cl_chip *chip, u8 riufea0clken)
{
	ASSERT_ERR_CHIP((((u32)riufea0clken << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00000200)) | ((u32)riufea0clken << 9));
}

static inline u8 modem_gcu_riu_clk_riu_mdm_b_tx_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00000100)) >> 8);
}

static inline void modem_gcu_riu_clk_riu_mdm_b_tx_clk_en_setf(struct cl_chip *chip, u8 riumdmbtxclken)
{
	ASSERT_ERR_CHIP((((u32)riumdmbtxclken << 8) & ~((u32)0x00000100)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00000100)) | ((u32)riumdmbtxclken << 8));
}

static inline u8 modem_gcu_riu_clk_riu_mdm_b_rx_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00000080)) >> 7);
}

static inline void modem_gcu_riu_clk_riu_mdm_b_rx_clk_en_setf(struct cl_chip *chip, u8 riumdmbrxclken)
{
	ASSERT_ERR_CHIP((((u32)riumdmbrxclken << 7) & ~((u32)0x00000080)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00000080)) | ((u32)riumdmbrxclken << 7));
}

static inline u8 modem_gcu_riu_clk_riu_mdm_b_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00000040)) >> 6);
}

static inline void modem_gcu_riu_clk_riu_mdm_b_clk_en_setf(struct cl_chip *chip, u8 riumdmbclken)
{
	ASSERT_ERR_CHIP((((u32)riumdmbclken << 6) & ~((u32)0x00000040)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00000040)) | ((u32)riumdmbclken << 6));
}

static inline u8 modem_gcu_riu_clk_riulb_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00000020)) >> 5);
}

static inline void modem_gcu_riu_clk_riulb_clk_en_setf(struct cl_chip *chip, u8 riulbclken)
{
	ASSERT_ERR_CHIP((((u32)riulbclken << 5) & ~((u32)0x00000020)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00000020)) | ((u32)riulbclken << 5));
}

static inline u8 modem_gcu_riu_clk_riurcr_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline void modem_gcu_riu_clk_riurcr_clk_en_setf(struct cl_chip *chip, u8 riurcrclken)
{
	ASSERT_ERR_CHIP((((u32)riurcrclken << 4) & ~((u32)0x00000010)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00000010)) | ((u32)riurcrclken << 4));
}

static inline u8 modem_gcu_riu_clk_riu_radar_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void modem_gcu_riu_clk_riu_radar_clk_en_setf(struct cl_chip *chip, u8 riuradarclken)
{
	ASSERT_ERR_CHIP((((u32)riuradarclken << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00000008)) | ((u32)riuradarclken << 3));
}

static inline u8 modem_gcu_riu_clk_riuagc_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void modem_gcu_riu_clk_riuagc_clk_en_setf(struct cl_chip *chip, u8 riuagcclken)
{
	ASSERT_ERR_CHIP((((u32)riuagcclken << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00000004)) | ((u32)riuagcclken << 2));
}

static inline u8 modem_gcu_riu_clk_riu_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_riu_clk_riu_clk_en_setf(struct cl_chip *chip, u8 riuclken)
{
	ASSERT_ERR_CHIP((((u32)riuclken << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00000002)) | ((u32)riuclken << 1));
}

static inline u8 modem_gcu_riu_clk_riu_reg_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_riu_clk_riu_reg_clk_en_setf(struct cl_chip *chip, u8 riuregclken)
{
	ASSERT_ERR_CHIP((((u32)riuregclken << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_ADDR) & ~((u32)0x00000001)) | ((u32)riuregclken << 0));
}

/**
 * @brief SPU register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    SPU_CLK_EN                0
 *    12    SPU_REG_CLK_EN            0
 *    01    SPU_RST_N                 0
 *    00    SPU_REG_RST_N             0
 * </pre>
 */
#define MODEM_GCU_SPU_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00000030)
#define MODEM_GCU_SPU_OFFSET      0x00000030
#define MODEM_GCU_SPU_INDEX       0x0000000C
#define MODEM_GCU_SPU_RESET       0x00000000

static inline u32 modem_gcu_spu_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_SPU_ADDR);
}

static inline void modem_gcu_spu_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_SPU_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_SPU_SPU_CLK_EN_BIT        ((u32)0x00002000)
#define MODEM_GCU_SPU_SPU_CLK_EN_POS        13
#define MODEM_GCU_SPU_SPU_REG_CLK_EN_BIT    ((u32)0x00001000)
#define MODEM_GCU_SPU_SPU_REG_CLK_EN_POS    12
#define MODEM_GCU_SPU_SPU_RST_N_BIT         ((u32)0x00000002)
#define MODEM_GCU_SPU_SPU_RST_N_POS         1
#define MODEM_GCU_SPU_SPU_REG_RST_N_BIT     ((u32)0x00000001)
#define MODEM_GCU_SPU_SPU_REG_RST_N_POS     0

#define MODEM_GCU_SPU_SPU_CLK_EN_RST        0x0
#define MODEM_GCU_SPU_SPU_REG_CLK_EN_RST    0x0
#define MODEM_GCU_SPU_SPU_RST_N_RST         0x0
#define MODEM_GCU_SPU_SPU_REG_RST_N_RST     0x0

static inline void modem_gcu_spu_pack(struct cl_chip *chip, u8 spu_clk_en, u8 spu_reg_clk_en, u8 spu_rst_n, u8 spu_reg_rst_n)
{
	ASSERT_ERR_CHIP((((u32)spu_clk_en << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)spu_reg_clk_en << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)spu_rst_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)spu_reg_rst_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_SPU_ADDR, ((u32)spu_clk_en << 13) | ((u32)spu_reg_clk_en << 12) | ((u32)spu_rst_n << 1) | ((u32)spu_reg_rst_n << 0));
}

static inline void modem_gcu_spu_unpack(struct cl_chip *chip, u8 *spu_clk_en, u8 *spu_reg_clk_en, u8 *spu_rst_n, u8 *spu_reg_rst_n)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_SPU_ADDR);

	*spu_clk_en = (local_val & ((u32)0x00002000)) >> 13;
	*spu_reg_clk_en = (local_val & ((u32)0x00001000)) >> 12;
	*spu_rst_n = (local_val & ((u32)0x00000002)) >> 1;
	*spu_reg_rst_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_spu_spu_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_SPU_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void modem_gcu_spu_spu_clk_en_setf(struct cl_chip *chip, u8 spuclken)
{
	ASSERT_ERR_CHIP((((u32)spuclken << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MODEM_GCU_SPU_ADDR, (cl_reg_read(chip, MODEM_GCU_SPU_ADDR) & ~((u32)0x00002000)) | ((u32)spuclken << 13));
}

static inline u8 modem_gcu_spu_spu_reg_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_SPU_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void modem_gcu_spu_spu_reg_clk_en_setf(struct cl_chip *chip, u8 spuregclken)
{
	ASSERT_ERR_CHIP((((u32)spuregclken << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MODEM_GCU_SPU_ADDR, (cl_reg_read(chip, MODEM_GCU_SPU_ADDR) & ~((u32)0x00001000)) | ((u32)spuregclken << 12));
}

static inline u8 modem_gcu_spu_spu_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_SPU_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_spu_spu_rst_n_setf(struct cl_chip *chip, u8 spurstn)
{
	ASSERT_ERR_CHIP((((u32)spurstn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_SPU_ADDR, (cl_reg_read(chip, MODEM_GCU_SPU_ADDR) & ~((u32)0x00000002)) | ((u32)spurstn << 1));
}

static inline u8 modem_gcu_spu_spu_reg_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_SPU_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_spu_spu_reg_rst_n_setf(struct cl_chip *chip, u8 spuregrstn)
{
	ASSERT_ERR_CHIP((((u32)spuregrstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_SPU_ADDR, (cl_reg_read(chip, MODEM_GCU_SPU_ADDR) & ~((u32)0x00000001)) | ((u32)spuregrstn << 0));
}

/**
 * @brief LCU register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    14    LCU_HLF_CLK_EN            0
 *    13    LCU_CLK_EN                0
 *    12    LCU_REG_CLK_EN            0
 *    02    LCU_HLF_RST_N             0
 *    01    LCU_RST_N                 0
 *    00    LCU_REG_RST_N             0
 * </pre>
 */
#define MODEM_GCU_LCU_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00000034)
#define MODEM_GCU_LCU_OFFSET      0x00000034
#define MODEM_GCU_LCU_INDEX       0x0000000D
#define MODEM_GCU_LCU_RESET       0x00000000

static inline u32 modem_gcu_lcu_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_LCU_ADDR);
}

static inline void modem_gcu_lcu_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_LCU_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_LCU_LCU_HLF_CLK_EN_BIT    ((u32)0x00004000)
#define MODEM_GCU_LCU_LCU_HLF_CLK_EN_POS    14
#define MODEM_GCU_LCU_LCU_CLK_EN_BIT        ((u32)0x00002000)
#define MODEM_GCU_LCU_LCU_CLK_EN_POS        13
#define MODEM_GCU_LCU_LCU_REG_CLK_EN_BIT    ((u32)0x00001000)
#define MODEM_GCU_LCU_LCU_REG_CLK_EN_POS    12
#define MODEM_GCU_LCU_LCU_HLF_RST_N_BIT     ((u32)0x00000004)
#define MODEM_GCU_LCU_LCU_HLF_RST_N_POS     2
#define MODEM_GCU_LCU_LCU_RST_N_BIT         ((u32)0x00000002)
#define MODEM_GCU_LCU_LCU_RST_N_POS         1
#define MODEM_GCU_LCU_LCU_REG_RST_N_BIT     ((u32)0x00000001)
#define MODEM_GCU_LCU_LCU_REG_RST_N_POS     0

#define MODEM_GCU_LCU_LCU_HLF_CLK_EN_RST    0x0
#define MODEM_GCU_LCU_LCU_CLK_EN_RST        0x0
#define MODEM_GCU_LCU_LCU_REG_CLK_EN_RST    0x0
#define MODEM_GCU_LCU_LCU_HLF_RST_N_RST     0x0
#define MODEM_GCU_LCU_LCU_RST_N_RST         0x0
#define MODEM_GCU_LCU_LCU_REG_RST_N_RST     0x0

static inline void modem_gcu_lcu_pack(struct cl_chip *chip, u8 lcu_hlf_clk_en, u8 lcu_clk_en, u8 lcu_reg_clk_en, u8 lcu_hlf_rst_n, u8 lcu_rst_n, u8 lcu_reg_rst_n)
{
	ASSERT_ERR_CHIP((((u32)lcu_hlf_clk_en << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)lcu_clk_en << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)lcu_reg_clk_en << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)lcu_hlf_rst_n << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)lcu_rst_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)lcu_reg_rst_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_LCU_ADDR, ((u32)lcu_hlf_clk_en << 14) | ((u32)lcu_clk_en << 13) | ((u32)lcu_reg_clk_en << 12) | ((u32)lcu_hlf_rst_n << 2) | ((u32)lcu_rst_n << 1) | ((u32)lcu_reg_rst_n << 0));
}

static inline void modem_gcu_lcu_unpack(struct cl_chip *chip, u8 *lcu_hlf_clk_en, u8 *lcu_clk_en, u8 *lcu_reg_clk_en, u8 *lcu_hlf_rst_n, u8 *lcu_rst_n, u8 *lcu_reg_rst_n)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_LCU_ADDR);

	*lcu_hlf_clk_en = (local_val & ((u32)0x00004000)) >> 14;
	*lcu_clk_en = (local_val & ((u32)0x00002000)) >> 13;
	*lcu_reg_clk_en = (local_val & ((u32)0x00001000)) >> 12;
	*lcu_hlf_rst_n = (local_val & ((u32)0x00000004)) >> 2;
	*lcu_rst_n = (local_val & ((u32)0x00000002)) >> 1;
	*lcu_reg_rst_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_lcu_lcu_hlf_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_LCU_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void modem_gcu_lcu_lcu_hlf_clk_en_setf(struct cl_chip *chip, u8 lcuhlfclken)
{
	ASSERT_ERR_CHIP((((u32)lcuhlfclken << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, MODEM_GCU_LCU_ADDR, (cl_reg_read(chip, MODEM_GCU_LCU_ADDR) & ~((u32)0x00004000)) | ((u32)lcuhlfclken << 14));
}

static inline u8 modem_gcu_lcu_lcu_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_LCU_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void modem_gcu_lcu_lcu_clk_en_setf(struct cl_chip *chip, u8 lcuclken)
{
	ASSERT_ERR_CHIP((((u32)lcuclken << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MODEM_GCU_LCU_ADDR, (cl_reg_read(chip, MODEM_GCU_LCU_ADDR) & ~((u32)0x00002000)) | ((u32)lcuclken << 13));
}

static inline u8 modem_gcu_lcu_lcu_reg_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_LCU_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void modem_gcu_lcu_lcu_reg_clk_en_setf(struct cl_chip *chip, u8 lcuregclken)
{
	ASSERT_ERR_CHIP((((u32)lcuregclken << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MODEM_GCU_LCU_ADDR, (cl_reg_read(chip, MODEM_GCU_LCU_ADDR) & ~((u32)0x00001000)) | ((u32)lcuregclken << 12));
}

static inline u8 modem_gcu_lcu_lcu_hlf_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_LCU_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void modem_gcu_lcu_lcu_hlf_rst_n_setf(struct cl_chip *chip, u8 lcuhlfrstn)
{
	ASSERT_ERR_CHIP((((u32)lcuhlfrstn << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, MODEM_GCU_LCU_ADDR, (cl_reg_read(chip, MODEM_GCU_LCU_ADDR) & ~((u32)0x00000004)) | ((u32)lcuhlfrstn << 2));
}

static inline u8 modem_gcu_lcu_lcu_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_LCU_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_lcu_lcu_rst_n_setf(struct cl_chip *chip, u8 lcurstn)
{
	ASSERT_ERR_CHIP((((u32)lcurstn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_LCU_ADDR, (cl_reg_read(chip, MODEM_GCU_LCU_ADDR) & ~((u32)0x00000002)) | ((u32)lcurstn << 1));
}

static inline u8 modem_gcu_lcu_lcu_reg_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_LCU_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_lcu_lcu_reg_rst_n_setf(struct cl_chip *chip, u8 lcuregrstn)
{
	ASSERT_ERR_CHIP((((u32)lcuregrstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_LCU_ADDR, (cl_reg_read(chip, MODEM_GCU_LCU_ADDR) & ~((u32)0x00000001)) | ((u32)lcuregrstn << 0));
}

/**
 * @brief EPA register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    EPA_CLK_EN                0
 *    12    EPA_REG_CLK_EN            0
 *    01    EPA_RST_N                 0
 *    00    EPA_REG_RST_N             0
 * </pre>
 */
#define MODEM_GCU_EPA_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00000038)
#define MODEM_GCU_EPA_OFFSET      0x00000038
#define MODEM_GCU_EPA_INDEX       0x0000000E
#define MODEM_GCU_EPA_RESET       0x00000000

static inline u32 modem_gcu_epa_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_EPA_ADDR);
}

static inline void modem_gcu_epa_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_EPA_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_EPA_EPA_CLK_EN_BIT        ((u32)0x00002000)
#define MODEM_GCU_EPA_EPA_CLK_EN_POS        13
#define MODEM_GCU_EPA_EPA_REG_CLK_EN_BIT    ((u32)0x00001000)
#define MODEM_GCU_EPA_EPA_REG_CLK_EN_POS    12
#define MODEM_GCU_EPA_EPA_RST_N_BIT         ((u32)0x00000002)
#define MODEM_GCU_EPA_EPA_RST_N_POS         1
#define MODEM_GCU_EPA_EPA_REG_RST_N_BIT     ((u32)0x00000001)
#define MODEM_GCU_EPA_EPA_REG_RST_N_POS     0

#define MODEM_GCU_EPA_EPA_CLK_EN_RST        0x0
#define MODEM_GCU_EPA_EPA_REG_CLK_EN_RST    0x0
#define MODEM_GCU_EPA_EPA_RST_N_RST         0x0
#define MODEM_GCU_EPA_EPA_REG_RST_N_RST     0x0

static inline void modem_gcu_epa_pack(struct cl_chip *chip, u8 epa_clk_en, u8 epa_reg_clk_en, u8 epa_rst_n, u8 epa_reg_rst_n)
{
	ASSERT_ERR_CHIP((((u32)epa_clk_en << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)epa_reg_clk_en << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)epa_rst_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)epa_reg_rst_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_EPA_ADDR, ((u32)epa_clk_en << 13) | ((u32)epa_reg_clk_en << 12) | ((u32)epa_rst_n << 1) | ((u32)epa_reg_rst_n << 0));
}

static inline void modem_gcu_epa_unpack(struct cl_chip *chip, u8 *epa_clk_en, u8 *epa_reg_clk_en, u8 *epa_rst_n, u8 *epa_reg_rst_n)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_EPA_ADDR);

	*epa_clk_en = (local_val & ((u32)0x00002000)) >> 13;
	*epa_reg_clk_en = (local_val & ((u32)0x00001000)) >> 12;
	*epa_rst_n = (local_val & ((u32)0x00000002)) >> 1;
	*epa_reg_rst_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_epa_epa_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_EPA_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void modem_gcu_epa_epa_clk_en_setf(struct cl_chip *chip, u8 epaclken)
{
	ASSERT_ERR_CHIP((((u32)epaclken << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MODEM_GCU_EPA_ADDR, (cl_reg_read(chip, MODEM_GCU_EPA_ADDR) & ~((u32)0x00002000)) | ((u32)epaclken << 13));
}

static inline u8 modem_gcu_epa_epa_reg_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_EPA_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void modem_gcu_epa_epa_reg_clk_en_setf(struct cl_chip *chip, u8 eparegclken)
{
	ASSERT_ERR_CHIP((((u32)eparegclken << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MODEM_GCU_EPA_ADDR, (cl_reg_read(chip, MODEM_GCU_EPA_ADDR) & ~((u32)0x00001000)) | ((u32)eparegclken << 12));
}

static inline u8 modem_gcu_epa_epa_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_EPA_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_epa_epa_rst_n_setf(struct cl_chip *chip, u8 eparstn)
{
	ASSERT_ERR_CHIP((((u32)eparstn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_EPA_ADDR, (cl_reg_read(chip, MODEM_GCU_EPA_ADDR) & ~((u32)0x00000002)) | ((u32)eparstn << 1));
}

static inline u8 modem_gcu_epa_epa_reg_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_EPA_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_epa_epa_reg_rst_n_setf(struct cl_chip *chip, u8 eparegrstn)
{
	ASSERT_ERR_CHIP((((u32)eparegrstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_EPA_ADDR, (cl_reg_read(chip, MODEM_GCU_EPA_ADDR) & ~((u32)0x00000001)) | ((u32)eparegrstn << 0));
}

/**
 * @brief BF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    13    BF_CLK_EN                 0
 *    12    BF_REG_CLK_EN             0
 *    01    BF_RST_N                  0
 *    00    BF_REG_RST_N              0
 * </pre>
 */
#define MODEM_GCU_BF_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x0000003C)
#define MODEM_GCU_BF_OFFSET      0x0000003C
#define MODEM_GCU_BF_INDEX       0x0000000F
#define MODEM_GCU_BF_RESET       0x00000000

static inline u32 modem_gcu_bf_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_BF_ADDR);
}

static inline void modem_gcu_bf_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_BF_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_BF_BF_CLK_EN_BIT          ((u32)0x00002000)
#define MODEM_GCU_BF_BF_CLK_EN_POS          13
#define MODEM_GCU_BF_BF_REG_CLK_EN_BIT      ((u32)0x00001000)
#define MODEM_GCU_BF_BF_REG_CLK_EN_POS      12
#define MODEM_GCU_BF_BF_RST_N_BIT           ((u32)0x00000002)
#define MODEM_GCU_BF_BF_RST_N_POS           1
#define MODEM_GCU_BF_BF_REG_RST_N_BIT       ((u32)0x00000001)
#define MODEM_GCU_BF_BF_REG_RST_N_POS       0

#define MODEM_GCU_BF_BF_CLK_EN_RST          0x0
#define MODEM_GCU_BF_BF_REG_CLK_EN_RST      0x0
#define MODEM_GCU_BF_BF_RST_N_RST           0x0
#define MODEM_GCU_BF_BF_REG_RST_N_RST       0x0

static inline void modem_gcu_bf_pack(struct cl_chip *chip, u8 bf_clk_en, u8 bf_reg_clk_en, u8 bf_rst_n, u8 bf_reg_rst_n)
{
	ASSERT_ERR_CHIP((((u32)bf_clk_en << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)bf_reg_clk_en << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)bf_rst_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)bf_reg_rst_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_BF_ADDR, ((u32)bf_clk_en << 13) | ((u32)bf_reg_clk_en << 12) | ((u32)bf_rst_n << 1) | ((u32)bf_reg_rst_n << 0));
}

static inline void modem_gcu_bf_unpack(struct cl_chip *chip, u8 *bf_clk_en, u8 *bf_reg_clk_en, u8 *bf_rst_n, u8 *bf_reg_rst_n)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BF_ADDR);

	*bf_clk_en = (local_val & ((u32)0x00002000)) >> 13;
	*bf_reg_clk_en = (local_val & ((u32)0x00001000)) >> 12;
	*bf_rst_n = (local_val & ((u32)0x00000002)) >> 1;
	*bf_reg_rst_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_bf_bf_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BF_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void modem_gcu_bf_bf_clk_en_setf(struct cl_chip *chip, u8 bfclken)
{
	ASSERT_ERR_CHIP((((u32)bfclken << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MODEM_GCU_BF_ADDR, (cl_reg_read(chip, MODEM_GCU_BF_ADDR) & ~((u32)0x00002000)) | ((u32)bfclken << 13));
}

static inline u8 modem_gcu_bf_bf_reg_clk_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BF_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void modem_gcu_bf_bf_reg_clk_en_setf(struct cl_chip *chip, u8 bfregclken)
{
	ASSERT_ERR_CHIP((((u32)bfregclken << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MODEM_GCU_BF_ADDR, (cl_reg_read(chip, MODEM_GCU_BF_ADDR) & ~((u32)0x00001000)) | ((u32)bfregclken << 12));
}

static inline u8 modem_gcu_bf_bf_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BF_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_bf_bf_rst_n_setf(struct cl_chip *chip, u8 bfrstn)
{
	ASSERT_ERR_CHIP((((u32)bfrstn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_BF_ADDR, (cl_reg_read(chip, MODEM_GCU_BF_ADDR) & ~((u32)0x00000002)) | ((u32)bfrstn << 1));
}

static inline u8 modem_gcu_bf_bf_reg_rst_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_BF_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_bf_bf_reg_rst_n_setf(struct cl_chip *chip, u8 bfregrstn)
{
	ASSERT_ERR_CHIP((((u32)bfregrstn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_BF_ADDR, (cl_reg_read(chip, MODEM_GCU_BF_ADDR) & ~((u32)0x00000001)) | ((u32)bfregrstn << 0));
}

/**
 * @brief PHY_ID register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 phy_id                    0x0
 * </pre>
 */
#define MODEM_GCU_PHY_ID_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00000100)
#define MODEM_GCU_PHY_ID_OFFSET      0x00000100
#define MODEM_GCU_PHY_ID_INDEX       0x00000040
#define MODEM_GCU_PHY_ID_RESET       0x00000000

static inline u32 modem_gcu_phy_id_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_PHY_ID_ADDR);
}

/* Field definitions */
#define MODEM_GCU_PHY_ID_PHY_ID_MASK        ((u32)0x00000003)
#define MODEM_GCU_PHY_ID_PHY_ID_LSB         0
#define MODEM_GCU_PHY_ID_PHY_ID_WIDTH       ((u32)0x00000002)

#define MODEM_GCU_PHY_ID_PHY_ID_RST         0x0

static inline u8 modem_gcu_phy_id_phy_id_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_PHY_ID_ADDR);

	return (u8)(local_val >> 0);
}

/**
 * @brief Reserved register
 * Reserved register address is (REG_MODEM_GCU_BASE_ADDR + 0x00001004)
 */

/**
 * @brief Reserved register
 * Reserved register address is (REG_MODEM_GCU_BASE_ADDR + 0x00001008)
 */

/**
 * @brief Reserved register
 * Reserved register address is (REG_MODEM_GCU_BASE_ADDR + 0x0000100C)
 */

/**
 * @brief RIU_CLK_BW register definition
 *  RIU clocks BW. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:18 riu_afe_clk_2x_bw         0x0
 *    17    afe_clk_2x_split          0
 *    16    riulbgclk_bt              0
 *    15    riu_afe_clk_2x_bt         0
 *    14    riu_afe_clk_bt            0
 *    13    agc_clk_bw                0
 *    12:10 lb_mem_clk_bw             0x2
 *    09:08 agc_mem_clk_bw            0x1
 *    07:06 riu_afe_clk_bw            0x2
 *    05:04 phyfesync_bw              0x2
 *    03:02 adcpowclk_bw              0x2
 *    01:00 riulbgclk_bw              0x2
 * </pre>
 */
#define MODEM_GCU_RIU_CLK_BW_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00001240)
#define MODEM_GCU_RIU_CLK_BW_OFFSET      0x00001240
#define MODEM_GCU_RIU_CLK_BW_INDEX       0x00000490
#define MODEM_GCU_RIU_CLK_BW_RESET       0x000009AA

static inline u32 modem_gcu_riu_clk_bw_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);
}

static inline void modem_gcu_riu_clk_bw_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_2_X_BW_MASK    ((u32)0x000C0000)
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_2_X_BW_LSB    18
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_2_X_BW_WIDTH    ((u32)0x00000002)
#define MODEM_GCU_RIU_CLK_BW_AFE_CLK_2_X_SPLIT_BIT    ((u32)0x00020000)
#define MODEM_GCU_RIU_CLK_BW_AFE_CLK_2_X_SPLIT_POS    17
#define MODEM_GCU_RIU_CLK_BW_RIULBGCLK_BT_BIT    ((u32)0x00010000)
#define MODEM_GCU_RIU_CLK_BW_RIULBGCLK_BT_POS    16
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_2_X_BT_BIT    ((u32)0x00008000)
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_2_X_BT_POS    15
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_BT_BIT    ((u32)0x00004000)
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_BT_POS    14
#define MODEM_GCU_RIU_CLK_BW_AGC_CLK_BW_BIT    ((u32)0x00002000)
#define MODEM_GCU_RIU_CLK_BW_AGC_CLK_BW_POS    13
#define MODEM_GCU_RIU_CLK_BW_LB_MEM_CLK_BW_MASK    ((u32)0x00001C00)
#define MODEM_GCU_RIU_CLK_BW_LB_MEM_CLK_BW_LSB    10
#define MODEM_GCU_RIU_CLK_BW_LB_MEM_CLK_BW_WIDTH    ((u32)0x00000003)
#define MODEM_GCU_RIU_CLK_BW_AGC_MEM_CLK_BW_MASK    ((u32)0x00000300)
#define MODEM_GCU_RIU_CLK_BW_AGC_MEM_CLK_BW_LSB    8
#define MODEM_GCU_RIU_CLK_BW_AGC_MEM_CLK_BW_WIDTH    ((u32)0x00000002)
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_BW_MASK    ((u32)0x000000C0)
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_BW_LSB    6
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_BW_WIDTH    ((u32)0x00000002)
#define MODEM_GCU_RIU_CLK_BW_PHYFESYNC_BW_MASK    ((u32)0x00000030)
#define MODEM_GCU_RIU_CLK_BW_PHYFESYNC_BW_LSB    4
#define MODEM_GCU_RIU_CLK_BW_PHYFESYNC_BW_WIDTH    ((u32)0x00000002)
#define MODEM_GCU_RIU_CLK_BW_ADCPOWCLK_BW_MASK    ((u32)0x0000000C)
#define MODEM_GCU_RIU_CLK_BW_ADCPOWCLK_BW_LSB    2
#define MODEM_GCU_RIU_CLK_BW_ADCPOWCLK_BW_WIDTH    ((u32)0x00000002)
#define MODEM_GCU_RIU_CLK_BW_RIULBGCLK_BW_MASK    ((u32)0x00000003)
#define MODEM_GCU_RIU_CLK_BW_RIULBGCLK_BW_LSB    0
#define MODEM_GCU_RIU_CLK_BW_RIULBGCLK_BW_WIDTH    ((u32)0x00000002)

#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_2_X_BW_RST    0x0
#define MODEM_GCU_RIU_CLK_BW_AFE_CLK_2_X_SPLIT_RST    0x0
#define MODEM_GCU_RIU_CLK_BW_RIULBGCLK_BT_RST    0x0
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_2_X_BT_RST    0x0
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_BT_RST    0x0
#define MODEM_GCU_RIU_CLK_BW_AGC_CLK_BW_RST    0x0
#define MODEM_GCU_RIU_CLK_BW_LB_MEM_CLK_BW_RST    0x2
#define MODEM_GCU_RIU_CLK_BW_AGC_MEM_CLK_BW_RST    0x1
#define MODEM_GCU_RIU_CLK_BW_RIU_AFE_CLK_BW_RST    0x2
#define MODEM_GCU_RIU_CLK_BW_PHYFESYNC_BW_RST    0x2
#define MODEM_GCU_RIU_CLK_BW_ADCPOWCLK_BW_RST    0x2
#define MODEM_GCU_RIU_CLK_BW_RIULBGCLK_BW_RST    0x2

static inline void modem_gcu_riu_clk_bw_pack(struct cl_chip *chip, u8 riu_afe_clk_2x_bw, u8 afe_clk_2x_split, u8 riulbgclk_bt, u8 riu_afe_clk_2x_bt, u8 riu_afe_clk_bt, u8 agc_clk_bw, u8 lb_mem_clk_bw, u8 agc_mem_clk_bw, u8 riu_afe_clk_bw, u8 phyfesync_bw, u8 adcpowclk_bw, u8 riulbgclk_bw)
{
	ASSERT_ERR_CHIP((((u32)riu_afe_clk_2x_bw << 18) & ~((u32)0x000C0000)) == 0);
	ASSERT_ERR_CHIP((((u32)afe_clk_2x_split << 17) & ~((u32)0x00020000)) == 0);
	ASSERT_ERR_CHIP((((u32)riulbgclk_bt << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_afe_clk_2x_bt << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_afe_clk_bt << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)agc_clk_bw << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)lb_mem_clk_bw << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)agc_mem_clk_bw << 8) & ~((u32)0x00000300)) == 0);
	ASSERT_ERR_CHIP((((u32)riu_afe_clk_bw << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)phyfesync_bw << 4) & ~((u32)0x00000030)) == 0);
	ASSERT_ERR_CHIP((((u32)adcpowclk_bw << 2) & ~((u32)0x0000000C)) == 0);
	ASSERT_ERR_CHIP((((u32)riulbgclk_bw << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, ((u32)riu_afe_clk_2x_bw << 18) | ((u32)afe_clk_2x_split << 17) | ((u32)riulbgclk_bt << 16) | ((u32)riu_afe_clk_2x_bt << 15) | ((u32)riu_afe_clk_bt << 14) | ((u32)agc_clk_bw << 13) | ((u32)lb_mem_clk_bw << 10) | ((u32)agc_mem_clk_bw << 8) | ((u32)riu_afe_clk_bw << 6) | ((u32)phyfesync_bw << 4) | ((u32)adcpowclk_bw << 2) | ((u32)riulbgclk_bw << 0));
}

static inline void modem_gcu_riu_clk_bw_unpack(struct cl_chip *chip, u8 *riu_afe_clk_2x_bw, u8 *afe_clk_2x_split, u8 *riulbgclk_bt, u8 *riu_afe_clk_2x_bt, u8 *riu_afe_clk_bt, u8 *agc_clk_bw, u8 *lb_mem_clk_bw, u8 *agc_mem_clk_bw, u8 *riu_afe_clk_bw, u8 *phyfesync_bw, u8 *adcpowclk_bw, u8 *riulbgclk_bw)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	*riu_afe_clk_2x_bw = (local_val & ((u32)0x000C0000)) >> 18;
	*afe_clk_2x_split = (local_val & ((u32)0x00020000)) >> 17;
	*riulbgclk_bt = (local_val & ((u32)0x00010000)) >> 16;
	*riu_afe_clk_2x_bt = (local_val & ((u32)0x00008000)) >> 15;
	*riu_afe_clk_bt = (local_val & ((u32)0x00004000)) >> 14;
	*agc_clk_bw = (local_val & ((u32)0x00002000)) >> 13;
	*lb_mem_clk_bw = (local_val & ((u32)0x00001C00)) >> 10;
	*agc_mem_clk_bw = (local_val & ((u32)0x00000300)) >> 8;
	*riu_afe_clk_bw = (local_val & ((u32)0x000000C0)) >> 6;
	*phyfesync_bw = (local_val & ((u32)0x00000030)) >> 4;
	*adcpowclk_bw = (local_val & ((u32)0x0000000C)) >> 2;
	*riulbgclk_bw = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u8 modem_gcu_riu_clk_bw_riu_afe_clk_2_x_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	return (u8)((local_val & ((u32)0x000C0000)) >> 18);
}

static inline void modem_gcu_riu_clk_bw_riu_afe_clk_2_x_bw_setf(struct cl_chip *chip, u8 riuafeclk2xbw)
{
	ASSERT_ERR_CHIP((((u32)riuafeclk2xbw << 18) & ~((u32)0x000C0000)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR) & ~((u32)0x000C0000)) | ((u32)riuafeclk2xbw << 18));
}

static inline u8 modem_gcu_riu_clk_bw_afe_clk_2_x_split_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	return (u8)((local_val & ((u32)0x00020000)) >> 17);
}

static inline void modem_gcu_riu_clk_bw_afe_clk_2_x_split_setf(struct cl_chip *chip, u8 afeclk2xsplit)
{
	ASSERT_ERR_CHIP((((u32)afeclk2xsplit << 17) & ~((u32)0x00020000)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR) & ~((u32)0x00020000)) | ((u32)afeclk2xsplit << 17));
}

static inline u8 modem_gcu_riu_clk_bw_riulbgclk_bt_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void modem_gcu_riu_clk_bw_riulbgclk_bt_setf(struct cl_chip *chip, u8 riulbgclkbt)
{
	ASSERT_ERR_CHIP((((u32)riulbgclkbt << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR) & ~((u32)0x00010000)) | ((u32)riulbgclkbt << 16));
}

static inline u8 modem_gcu_riu_clk_bw_riu_afe_clk_2_x_bt_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void modem_gcu_riu_clk_bw_riu_afe_clk_2_x_bt_setf(struct cl_chip *chip, u8 riuafeclk2xbt)
{
	ASSERT_ERR_CHIP((((u32)riuafeclk2xbt << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR) & ~((u32)0x00008000)) | ((u32)riuafeclk2xbt << 15));
}

static inline u8 modem_gcu_riu_clk_bw_riu_afe_clk_bt_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void modem_gcu_riu_clk_bw_riu_afe_clk_bt_setf(struct cl_chip *chip, u8 riuafeclkbt)
{
	ASSERT_ERR_CHIP((((u32)riuafeclkbt << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR) & ~((u32)0x00004000)) | ((u32)riuafeclkbt << 14));
}

static inline u8 modem_gcu_riu_clk_bw_agc_clk_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void modem_gcu_riu_clk_bw_agc_clk_bw_setf(struct cl_chip *chip, u8 agcclkbw)
{
	ASSERT_ERR_CHIP((((u32)agcclkbw << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR) & ~((u32)0x00002000)) | ((u32)agcclkbw << 13));
}

static inline u8 modem_gcu_riu_clk_bw_lb_mem_clk_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void modem_gcu_riu_clk_bw_lb_mem_clk_bw_setf(struct cl_chip *chip, u8 lbmemclkbw)
{
	ASSERT_ERR_CHIP((((u32)lbmemclkbw << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR) & ~((u32)0x00001C00)) | ((u32)lbmemclkbw << 10));
}

static inline u8 modem_gcu_riu_clk_bw_agc_mem_clk_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	return (u8)((local_val & ((u32)0x00000300)) >> 8);
}

static inline void modem_gcu_riu_clk_bw_agc_mem_clk_bw_setf(struct cl_chip *chip, u8 agcmemclkbw)
{
	ASSERT_ERR_CHIP((((u32)agcmemclkbw << 8) & ~((u32)0x00000300)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR) & ~((u32)0x00000300)) | ((u32)agcmemclkbw << 8));
}

static inline u8 modem_gcu_riu_clk_bw_riu_afe_clk_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void modem_gcu_riu_clk_bw_riu_afe_clk_bw_setf(struct cl_chip *chip, u8 riuafeclkbw)
{
	ASSERT_ERR_CHIP((((u32)riuafeclkbw << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR) & ~((u32)0x000000C0)) | ((u32)riuafeclkbw << 6));
}

static inline u8 modem_gcu_riu_clk_bw_phyfesync_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	return (u8)((local_val & ((u32)0x00000030)) >> 4);
}

static inline void modem_gcu_riu_clk_bw_phyfesync_bw_setf(struct cl_chip *chip, u8 phyfesyncbw)
{
	ASSERT_ERR_CHIP((((u32)phyfesyncbw << 4) & ~((u32)0x00000030)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR) & ~((u32)0x00000030)) | ((u32)phyfesyncbw << 4));
}

static inline u8 modem_gcu_riu_clk_bw_adcpowclk_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	return (u8)((local_val & ((u32)0x0000000C)) >> 2);
}

static inline void modem_gcu_riu_clk_bw_adcpowclk_bw_setf(struct cl_chip *chip, u8 adcpowclkbw)
{
	ASSERT_ERR_CHIP((((u32)adcpowclkbw << 2) & ~((u32)0x0000000C)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR) & ~((u32)0x0000000C)) | ((u32)adcpowclkbw << 2));
}

static inline u8 modem_gcu_riu_clk_bw_riulbgclk_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void modem_gcu_riu_clk_bw_riulbgclk_bw_setf(struct cl_chip *chip, u8 riulbgclkbw)
{
	ASSERT_ERR_CHIP((((u32)riulbgclkbw << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MODEM_GCU_RIU_CLK_BW_ADDR, (cl_reg_read(chip, MODEM_GCU_RIU_CLK_BW_ADDR) & ~((u32)0x00000003)) | ((u32)riulbgclkbw << 0));
}

/**
 * @brief TIMER_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    T2_DONE                   0
 *    00    T1_DONE                   0
 * </pre>
 */
#define MODEM_GCU_TIMER_STAT_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00001300)
#define MODEM_GCU_TIMER_STAT_OFFSET      0x00001300
#define MODEM_GCU_TIMER_STAT_INDEX       0x000004C0
#define MODEM_GCU_TIMER_STAT_RESET       0x00000000

static inline u32 modem_gcu_timer_stat_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_TIMER_STAT_ADDR);
}

static inline void modem_gcu_timer_stat_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_TIMER_STAT_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_TIMER_STAT_T_2_DONE_BIT    ((u32)0x00000002)
#define MODEM_GCU_TIMER_STAT_T_2_DONE_POS    1
#define MODEM_GCU_TIMER_STAT_T_1_DONE_BIT    ((u32)0x00000001)
#define MODEM_GCU_TIMER_STAT_T_1_DONE_POS    0

#define MODEM_GCU_TIMER_STAT_T_2_DONE_RST    0x0
#define MODEM_GCU_TIMER_STAT_T_1_DONE_RST    0x0

static inline void modem_gcu_timer_stat_pack(struct cl_chip *chip, u8 t2_done, u8 t1_done)
{
	ASSERT_ERR_CHIP((((u32)t2_done << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)t1_done << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_STAT_ADDR, ((u32)t2_done << 1) | ((u32)t1_done << 0));
}

static inline void modem_gcu_timer_stat_unpack(struct cl_chip *chip, u8 *t2_done, u8 *t1_done)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_STAT_ADDR);

	*t2_done = (local_val & ((u32)0x00000002)) >> 1;
	*t1_done = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_timer_stat_t_2_done_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_timer_stat_t_2_done_setf(struct cl_chip *chip, u8 t2done)
{
	ASSERT_ERR_CHIP((((u32)t2done << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_STAT_ADDR, (cl_reg_read(chip, MODEM_GCU_TIMER_STAT_ADDR) & ~((u32)0x00000002)) | ((u32)t2done << 1));
}

static inline u8 modem_gcu_timer_stat_t_1_done_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_STAT_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_timer_stat_t_1_done_setf(struct cl_chip *chip, u8 t1done)
{
	ASSERT_ERR_CHIP((((u32)t1done << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_STAT_ADDR, (cl_reg_read(chip, MODEM_GCU_TIMER_STAT_ADDR) & ~((u32)0x00000001)) | ((u32)t1done << 0));
}

/**
 * @brief TIMER_INT_MASK register definition
 *  Interrupt Mask for Timers Interrupts register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    T2_DONE_MASK              0
 *    00    T1_DONE_MASK              0
 * </pre>
 */
#define MODEM_GCU_TIMER_INT_MASK_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00001304)
#define MODEM_GCU_TIMER_INT_MASK_OFFSET      0x00001304
#define MODEM_GCU_TIMER_INT_MASK_INDEX       0x000004C1
#define MODEM_GCU_TIMER_INT_MASK_RESET       0x00000000

static inline u32 modem_gcu_timer_int_mask_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_TIMER_INT_MASK_ADDR);
}

static inline void modem_gcu_timer_int_mask_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_TIMER_INT_MASK_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_TIMER_INT_MASK_T_2_DONE_MASK_BIT    ((u32)0x00000002)
#define MODEM_GCU_TIMER_INT_MASK_T_2_DONE_MASK_POS    1
#define MODEM_GCU_TIMER_INT_MASK_T_1_DONE_MASK_BIT    ((u32)0x00000001)
#define MODEM_GCU_TIMER_INT_MASK_T_1_DONE_MASK_POS    0

#define MODEM_GCU_TIMER_INT_MASK_T_2_DONE_MASK_RST    0x0
#define MODEM_GCU_TIMER_INT_MASK_T_1_DONE_MASK_RST    0x0

static inline void modem_gcu_timer_int_mask_pack(struct cl_chip *chip, u8 t2_done_mask, u8 t1_done_mask)
{
	ASSERT_ERR_CHIP((((u32)t2_done_mask << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)t1_done_mask << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_INT_MASK_ADDR, ((u32)t2_done_mask << 1) | ((u32)t1_done_mask << 0));
}

static inline void modem_gcu_timer_int_mask_unpack(struct cl_chip *chip, u8 *t2_done_mask, u8 *t1_done_mask)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_INT_MASK_ADDR);

	*t2_done_mask = (local_val & ((u32)0x00000002)) >> 1;
	*t1_done_mask = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_timer_int_mask_t_2_done_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_INT_MASK_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_timer_int_mask_t_2_done_mask_setf(struct cl_chip *chip, u8 t2donemask)
{
	ASSERT_ERR_CHIP((((u32)t2donemask << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_INT_MASK_ADDR, (cl_reg_read(chip, MODEM_GCU_TIMER_INT_MASK_ADDR) & ~((u32)0x00000002)) | ((u32)t2donemask << 1));
}

static inline u8 modem_gcu_timer_int_mask_t_1_done_mask_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_INT_MASK_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_timer_int_mask_t_1_done_mask_setf(struct cl_chip *chip, u8 t1donemask)
{
	ASSERT_ERR_CHIP((((u32)t1donemask << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_INT_MASK_ADDR, (cl_reg_read(chip, MODEM_GCU_TIMER_INT_MASK_ADDR) & ~((u32)0x00000001)) | ((u32)t1donemask << 0));
}

/**
 * @brief TIMER_1_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    CNT_EN                    0
 *    00    RPT                       0
 * </pre>
 */
#define MODEM_GCU_TIMER_1_CFG_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00001308)
#define MODEM_GCU_TIMER_1_CFG_OFFSET      0x00001308
#define MODEM_GCU_TIMER_1_CFG_INDEX       0x000004C2
#define MODEM_GCU_TIMER_1_CFG_RESET       0x00000000

static inline u32 modem_gcu_timer_1_cfg_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_TIMER_1_CFG_ADDR);
}

static inline void modem_gcu_timer_1_cfg_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_TIMER_1_CFG_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_TIMER_1_CFG_CNT_EN_BIT    ((u32)0x00000002)
#define MODEM_GCU_TIMER_1_CFG_CNT_EN_POS    1
#define MODEM_GCU_TIMER_1_CFG_RPT_BIT       ((u32)0x00000001)
#define MODEM_GCU_TIMER_1_CFG_RPT_POS       0

#define MODEM_GCU_TIMER_1_CFG_CNT_EN_RST    0x0
#define MODEM_GCU_TIMER_1_CFG_RPT_RST       0x0

static inline void modem_gcu_timer_1_cfg_pack(struct cl_chip *chip, u8 cnt_en, u8 rpt)
{
	ASSERT_ERR_CHIP((((u32)cnt_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)rpt << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_1_CFG_ADDR, ((u32)cnt_en << 1) | ((u32)rpt << 0));
}

static inline void modem_gcu_timer_1_cfg_unpack(struct cl_chip *chip, u8 *cnt_en, u8 *rpt)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_1_CFG_ADDR);

	*cnt_en = (local_val & ((u32)0x00000002)) >> 1;
	*rpt = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_timer_1_cfg_cnt_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_1_CFG_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_timer_1_cfg_cnt_en_setf(struct cl_chip *chip, u8 cnten)
{
	ASSERT_ERR_CHIP((((u32)cnten << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_1_CFG_ADDR, (cl_reg_read(chip, MODEM_GCU_TIMER_1_CFG_ADDR) & ~((u32)0x00000002)) | ((u32)cnten << 1));
}

static inline u8 modem_gcu_timer_1_cfg_rpt_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_1_CFG_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_timer_1_cfg_rpt_setf(struct cl_chip *chip, u8 rpt)
{
	ASSERT_ERR_CHIP((((u32)rpt << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_1_CFG_ADDR, (cl_reg_read(chip, MODEM_GCU_TIMER_1_CFG_ADDR) & ~((u32)0x00000001)) | ((u32)rpt << 0));
}

/**
 * @brief TIMER_2_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    CNT_EN                    0
 *    00    RPT                       0
 * </pre>
 */
#define MODEM_GCU_TIMER_2_CFG_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x0000130C)
#define MODEM_GCU_TIMER_2_CFG_OFFSET      0x0000130C
#define MODEM_GCU_TIMER_2_CFG_INDEX       0x000004C3
#define MODEM_GCU_TIMER_2_CFG_RESET       0x00000000

static inline u32 modem_gcu_timer_2_cfg_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_TIMER_2_CFG_ADDR);
}

static inline void modem_gcu_timer_2_cfg_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_TIMER_2_CFG_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_TIMER_2_CFG_CNT_EN_BIT    ((u32)0x00000002)
#define MODEM_GCU_TIMER_2_CFG_CNT_EN_POS    1
#define MODEM_GCU_TIMER_2_CFG_RPT_BIT       ((u32)0x00000001)
#define MODEM_GCU_TIMER_2_CFG_RPT_POS       0

#define MODEM_GCU_TIMER_2_CFG_CNT_EN_RST    0x0
#define MODEM_GCU_TIMER_2_CFG_RPT_RST       0x0

static inline void modem_gcu_timer_2_cfg_pack(struct cl_chip *chip, u8 cnt_en, u8 rpt)
{
	ASSERT_ERR_CHIP((((u32)cnt_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)rpt << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_2_CFG_ADDR, ((u32)cnt_en << 1) | ((u32)rpt << 0));
}

static inline void modem_gcu_timer_2_cfg_unpack(struct cl_chip *chip, u8 *cnt_en, u8 *rpt)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_2_CFG_ADDR);

	*cnt_en = (local_val & ((u32)0x00000002)) >> 1;
	*rpt = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 modem_gcu_timer_2_cfg_cnt_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_2_CFG_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void modem_gcu_timer_2_cfg_cnt_en_setf(struct cl_chip *chip, u8 cnten)
{
	ASSERT_ERR_CHIP((((u32)cnten << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_2_CFG_ADDR, (cl_reg_read(chip, MODEM_GCU_TIMER_2_CFG_ADDR) & ~((u32)0x00000002)) | ((u32)cnten << 1));
}

static inline u8 modem_gcu_timer_2_cfg_rpt_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_2_CFG_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void modem_gcu_timer_2_cfg_rpt_setf(struct cl_chip *chip, u8 rpt)
{
	ASSERT_ERR_CHIP((((u32)rpt << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_2_CFG_ADDR, (cl_reg_read(chip, MODEM_GCU_TIMER_2_CFG_ADDR) & ~((u32)0x00000001)) | ((u32)rpt << 0));
}

/**
 * @brief TIMER_1_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 INIT                      0x0
 * </pre>
 */
#define MODEM_GCU_TIMER_1_INIT_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00001310)
#define MODEM_GCU_TIMER_1_INIT_OFFSET      0x00001310
#define MODEM_GCU_TIMER_1_INIT_INDEX       0x000004C4
#define MODEM_GCU_TIMER_1_INIT_RESET       0x00000000

static inline u32 modem_gcu_timer_1_init_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_TIMER_1_INIT_ADDR);
}

static inline void modem_gcu_timer_1_init_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_TIMER_1_INIT_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_TIMER_1_INIT_INIT_MASK    ((u32)0xFFFFFFFF)
#define MODEM_GCU_TIMER_1_INIT_INIT_LSB     0
#define MODEM_GCU_TIMER_1_INIT_INIT_WIDTH    ((u32)0x00000020)

#define MODEM_GCU_TIMER_1_INIT_INIT_RST     0x0

static inline u32 modem_gcu_timer_1_init_init_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_1_INIT_ADDR);

	return (u32)(local_val >> 0);
}

static inline void modem_gcu_timer_1_init_init_setf(struct cl_chip *chip, u32 init)
{
	ASSERT_ERR_CHIP((((u32)init << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_1_INIT_ADDR, (u32)init << 0);
}

/**
 * @brief TIMER_2_INIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 INIT                      0x0
 * </pre>
 */
#define MODEM_GCU_TIMER_2_INIT_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00001314)
#define MODEM_GCU_TIMER_2_INIT_OFFSET      0x00001314
#define MODEM_GCU_TIMER_2_INIT_INDEX       0x000004C5
#define MODEM_GCU_TIMER_2_INIT_RESET       0x00000000

static inline u32 modem_gcu_timer_2_init_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_TIMER_2_INIT_ADDR);
}

static inline void modem_gcu_timer_2_init_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_TIMER_2_INIT_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_TIMER_2_INIT_INIT_MASK    ((u32)0xFFFFFFFF)
#define MODEM_GCU_TIMER_2_INIT_INIT_LSB     0
#define MODEM_GCU_TIMER_2_INIT_INIT_WIDTH    ((u32)0x00000020)

#define MODEM_GCU_TIMER_2_INIT_INIT_RST     0x0

static inline u32 modem_gcu_timer_2_init_init_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_TIMER_2_INIT_ADDR);

	return (u32)(local_val >> 0);
}

static inline void modem_gcu_timer_2_init_init_setf(struct cl_chip *chip, u32 init)
{
	ASSERT_ERR_CHIP((((u32)init << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MODEM_GCU_TIMER_2_INIT_ADDR, (u32)init << 0);
}

/**
 * @brief FRC_LOW register definition
 *  Lower 32 bits of 64 bit Free Running Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LOW                       0x0
 * </pre>
 */
#define MODEM_GCU_FRC_LOW_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00001320)
#define MODEM_GCU_FRC_LOW_OFFSET      0x00001320
#define MODEM_GCU_FRC_LOW_INDEX       0x000004C8
#define MODEM_GCU_FRC_LOW_RESET       0x00000000

static inline u32 modem_gcu_frc_low_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_FRC_LOW_ADDR);
}

static inline void modem_gcu_frc_low_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_FRC_LOW_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_FRC_LOW_LOW_MASK          ((u32)0xFFFFFFFF)
#define MODEM_GCU_FRC_LOW_LOW_LSB           0
#define MODEM_GCU_FRC_LOW_LOW_WIDTH         ((u32)0x00000020)

#define MODEM_GCU_FRC_LOW_LOW_RST           0x0

static inline u32 modem_gcu_frc_low_low_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_FRC_LOW_ADDR);

	return (u32)(local_val >> 0);
}

static inline void modem_gcu_frc_low_low_setf(struct cl_chip *chip, u32 low)
{
	ASSERT_ERR_CHIP((((u32)low << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MODEM_GCU_FRC_LOW_ADDR, (u32)low << 0);
}

/**
 * @brief FRC_HIGH register definition
 *  Higher 32 bits of 64 bit Free Running Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 HIGH                      0x0
 * </pre>
 */
#define MODEM_GCU_FRC_HIGH_ADDR        (REG_MODEM_GCU_BASE_ADDR + 0x00001324)
#define MODEM_GCU_FRC_HIGH_OFFSET      0x00001324
#define MODEM_GCU_FRC_HIGH_INDEX       0x000004C9
#define MODEM_GCU_FRC_HIGH_RESET       0x00000000

static inline u32 modem_gcu_frc_high_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MODEM_GCU_FRC_HIGH_ADDR);
}

static inline void modem_gcu_frc_high_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MODEM_GCU_FRC_HIGH_ADDR, value);
}

/* Field definitions */
#define MODEM_GCU_FRC_HIGH_HIGH_MASK        ((u32)0xFFFFFFFF)
#define MODEM_GCU_FRC_HIGH_HIGH_LSB         0
#define MODEM_GCU_FRC_HIGH_HIGH_WIDTH       ((u32)0x00000020)

#define MODEM_GCU_FRC_HIGH_HIGH_RST         0x0

static inline u32 modem_gcu_frc_high_high_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MODEM_GCU_FRC_HIGH_ADDR);

	return (u32)(local_val >> 0);
}

static inline void modem_gcu_frc_high_high_setf(struct cl_chip *chip, u32 high)
{
	ASSERT_ERR_CHIP((((u32)high << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MODEM_GCU_FRC_HIGH_ADDR, (u32)high << 0);
}

#endif /* REG_MODEM_GCU_H */
