/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef REG_MACSYS_GCU_H
#define REG_MACSYS_GCU_H

#include <linux/types.h>
#include "reg_access.h"
#include "chip.h"

#define REG_MACSYS_GCU_BASE_ADDR 0x007C5000

/**
 * @brief CHIP_VERSION register definition
 *  Chip Version 8000B0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:08 PRODUCT_ID                0x6000
 *    07:04 STEP_ID                   0xA
 *    03:00 REV_ID                    0x0
 * </pre>
 */
#define MACSYS_GCU_CHIP_VERSION_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000050)
#define MACSYS_GCU_CHIP_VERSION_OFFSET      0x00000050
#define MACSYS_GCU_CHIP_VERSION_INDEX       0x00000014
#define MACSYS_GCU_CHIP_VERSION_RESET       0x006000A0

static inline u32 macsys_gcu_chip_version_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CHIP_VERSION_ADDR);
}

/* Field definitions */
#define MACSYS_GCU_CHIP_VERSION_PRODUCT_ID_MASK    ((u32)0x00FFFF00)
#define MACSYS_GCU_CHIP_VERSION_PRODUCT_ID_LSB    8
#define MACSYS_GCU_CHIP_VERSION_PRODUCT_ID_WIDTH    ((u32)0x00000010)
#define MACSYS_GCU_CHIP_VERSION_STEP_ID_MASK    ((u32)0x000000F0)
#define MACSYS_GCU_CHIP_VERSION_STEP_ID_LSB    4
#define MACSYS_GCU_CHIP_VERSION_STEP_ID_WIDTH    ((u32)0x00000004)
#define MACSYS_GCU_CHIP_VERSION_REV_ID_MASK    ((u32)0x0000000F)
#define MACSYS_GCU_CHIP_VERSION_REV_ID_LSB    0
#define MACSYS_GCU_CHIP_VERSION_REV_ID_WIDTH    ((u32)0x00000004)

#define MACSYS_GCU_CHIP_VERSION_PRODUCT_ID_RST    0x6000
#define MACSYS_GCU_CHIP_VERSION_STEP_ID_RST    0xA
#define MACSYS_GCU_CHIP_VERSION_REV_ID_RST    0x0

static inline void macsys_gcu_chip_version_unpack(struct cl_chip *chip, u16 *product_id, u8 *step_id, u8 *rev_id)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CHIP_VERSION_ADDR);

	*product_id = (local_val & ((u32)0x00FFFF00)) >> 8;
	*step_id = (local_val & ((u32)0x000000F0)) >> 4;
	*rev_id = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u16 macsys_gcu_chip_version_product_id_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CHIP_VERSION_ADDR);

	return (u16)((local_val & ((u32)0x00FFFF00)) >> 8);
}

static inline u8 macsys_gcu_chip_version_step_id_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CHIP_VERSION_ADDR);

	return (u8)((local_val & ((u32)0x000000F0)) >> 4);
}

static inline u8 macsys_gcu_chip_version_rev_id_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CHIP_VERSION_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

/**
 * @brief PCIE_SLV_AWMISC_INFO_LSB register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SLV_AWMISC_INFO_HDR_34_DW_LSB 0x0
 * </pre>
 */
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000060)
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_OFFSET      0x00000060
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_INDEX       0x00000018
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_RESET       0x00000000

static inline u32 macsys_gcu_pcie_slv_awmisc_info_lsb_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_ADDR);
}

static inline void macsys_gcu_pcie_slv_awmisc_info_lsb_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_SLV_AWMISC_INFO_HDR_34_DW_LSB_MASK    ((u32)0xFFFFFFFF)
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_SLV_AWMISC_INFO_HDR_34_DW_LSB_LSB    0
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_SLV_AWMISC_INFO_HDR_34_DW_LSB_WIDTH    ((u32)0x00000020)

#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_SLV_AWMISC_INFO_HDR_34_DW_LSB_RST    0x0

static inline u32 macsys_gcu_pcie_slv_awmisc_info_lsb_slv_awmisc_info_hdr_34_dw_lsb_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macsys_gcu_pcie_slv_awmisc_info_lsb_slv_awmisc_info_hdr_34_dw_lsb_setf(struct cl_chip *chip, u32 slvawmiscinfohdr34dwlsb)
{
	ASSERT_ERR_CHIP((((u32)slvawmiscinfohdr34dwlsb << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_ADDR, (u32)slvawmiscinfohdr34dwlsb << 0);
}

/**
 * @brief PCIE_SLV_AWMISC_INFO_MSB register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SLV_AWMISC_INFO_HDR_34_DW_MSB 0x0
 * </pre>
 */
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000064)
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_OFFSET      0x00000064
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_INDEX       0x00000019
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_RESET       0x00000000

static inline u32 macsys_gcu_pcie_slv_awmisc_info_msb_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_ADDR);
}

static inline void macsys_gcu_pcie_slv_awmisc_info_msb_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_SLV_AWMISC_INFO_HDR_34_DW_MSB_MASK    ((u32)0xFFFFFFFF)
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_SLV_AWMISC_INFO_HDR_34_DW_MSB_LSB    0
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_SLV_AWMISC_INFO_HDR_34_DW_MSB_WIDTH    ((u32)0x00000020)

#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_SLV_AWMISC_INFO_HDR_34_DW_MSB_RST    0x0

static inline u32 macsys_gcu_pcie_slv_awmisc_info_msb_slv_awmisc_info_hdr_34_dw_msb_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macsys_gcu_pcie_slv_awmisc_info_msb_slv_awmisc_info_hdr_34_dw_msb_setf(struct cl_chip *chip, u32 slvawmiscinfohdr34dwmsb)
{
	ASSERT_ERR_CHIP((((u32)slvawmiscinfohdr34dwmsb << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_ADDR, (u32)slvawmiscinfohdr34dwmsb << 0);
}

/**
 * @brief PCIE_GENERAL_CONF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12    APP_CLK_PM_EN             0
 *    11    AUX_CLK_ACTIVE            1
 *    10    APP_REQ_RETRY_EN          0
 *    09    APP_INIT_RST              0
 *    08    APP_XFER_PENDING          1
 *    07    APP_REQ_EXIT_L1           0
 *    06    APP_READY_ENTR_L23        1
 *    05    APP_REQ_ENTR_L1           0
 *    04    PHY_CLK_REQ_N             1
 *    03    APP_CLK_REQ_N             1
 *    02    APPS_PM_XMT_PME           0
 *    01    TX_LANE_FLIP_EN           0
 *    00    RX_LANE_FLIP_EN           0
 * </pre>
 */
#define MACSYS_GCU_PCIE_GENERAL_CONF_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000068)
#define MACSYS_GCU_PCIE_GENERAL_CONF_OFFSET      0x00000068
#define MACSYS_GCU_PCIE_GENERAL_CONF_INDEX       0x0000001A
#define MACSYS_GCU_PCIE_GENERAL_CONF_RESET       0x00000958

static inline u32 macsys_gcu_pcie_general_conf_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
}

static inline void macsys_gcu_pcie_general_conf_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_CLK_PM_EN_BIT    ((u32)0x00001000)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_CLK_PM_EN_POS    12
#define MACSYS_GCU_PCIE_GENERAL_CONF_AUX_CLK_ACTIVE_BIT    ((u32)0x00000800)
#define MACSYS_GCU_PCIE_GENERAL_CONF_AUX_CLK_ACTIVE_POS    11
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_RETRY_EN_BIT    ((u32)0x00000400)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_RETRY_EN_POS    10
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_INIT_RST_BIT    ((u32)0x00000200)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_INIT_RST_POS    9
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_XFER_PENDING_BIT    ((u32)0x00000100)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_XFER_PENDING_POS    8
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_EXIT_L_1_BIT    ((u32)0x00000080)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_EXIT_L_1_POS    7
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_READY_ENTR_L_23_BIT    ((u32)0x00000040)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_READY_ENTR_L_23_POS    6
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_ENTR_L_1_BIT    ((u32)0x00000020)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_ENTR_L_1_POS    5
#define MACSYS_GCU_PCIE_GENERAL_CONF_PHY_CLK_REQ_N_BIT    ((u32)0x00000010)
#define MACSYS_GCU_PCIE_GENERAL_CONF_PHY_CLK_REQ_N_POS    4
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_CLK_REQ_N_BIT    ((u32)0x00000008)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_CLK_REQ_N_POS    3
#define MACSYS_GCU_PCIE_GENERAL_CONF_APPS_PM_XMT_PME_BIT    ((u32)0x00000004)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APPS_PM_XMT_PME_POS    2
#define MACSYS_GCU_PCIE_GENERAL_CONF_TX_LANE_FLIP_EN_BIT    ((u32)0x00000002)
#define MACSYS_GCU_PCIE_GENERAL_CONF_TX_LANE_FLIP_EN_POS    1
#define MACSYS_GCU_PCIE_GENERAL_CONF_RX_LANE_FLIP_EN_BIT    ((u32)0x00000001)
#define MACSYS_GCU_PCIE_GENERAL_CONF_RX_LANE_FLIP_EN_POS    0

#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_CLK_PM_EN_RST    0x0
#define MACSYS_GCU_PCIE_GENERAL_CONF_AUX_CLK_ACTIVE_RST    0x1
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_RETRY_EN_RST    0x0
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_INIT_RST_RST    0x0
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_XFER_PENDING_RST    0x1
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_EXIT_L_1_RST    0x0
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_READY_ENTR_L_23_RST    0x1
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_ENTR_L_1_RST    0x0
#define MACSYS_GCU_PCIE_GENERAL_CONF_PHY_CLK_REQ_N_RST    0x1
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_CLK_REQ_N_RST    0x1
#define MACSYS_GCU_PCIE_GENERAL_CONF_APPS_PM_XMT_PME_RST    0x0
#define MACSYS_GCU_PCIE_GENERAL_CONF_TX_LANE_FLIP_EN_RST    0x0
#define MACSYS_GCU_PCIE_GENERAL_CONF_RX_LANE_FLIP_EN_RST    0x0

static inline void macsys_gcu_pcie_general_conf_pack(struct cl_chip *chip, u8 app_clk_pm_en, u8 aux_clk_active, u8 app_req_retry_en, u8 app_init_rst, u8 app_xfer_pending, u8 app_req_exit_l1, u8 app_ready_entr_l23, u8 app_req_entr_l1, u8 phy_clk_req_n, u8 app_clk_req_n, u8 apps_pm_xmt_pme, u8 tx_lane_flip_en, u8 rx_lane_flip_en)
{
	ASSERT_ERR_CHIP((((u32)app_clk_pm_en << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)aux_clk_active << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)app_req_retry_en << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)app_init_rst << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)app_xfer_pending << 8) & ~((u32)0x00000100)) == 0);
	ASSERT_ERR_CHIP((((u32)app_req_exit_l1 << 7) & ~((u32)0x00000080)) == 0);
	ASSERT_ERR_CHIP((((u32)app_ready_entr_l23 << 6) & ~((u32)0x00000040)) == 0);
	ASSERT_ERR_CHIP((((u32)app_req_entr_l1 << 5) & ~((u32)0x00000020)) == 0);
	ASSERT_ERR_CHIP((((u32)phy_clk_req_n << 4) & ~((u32)0x00000010)) == 0);
	ASSERT_ERR_CHIP((((u32)app_clk_req_n << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)apps_pm_xmt_pme << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)tx_lane_flip_en << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)rx_lane_flip_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, ((u32)app_clk_pm_en << 12) | ((u32)aux_clk_active << 11) | ((u32)app_req_retry_en << 10) | ((u32)app_init_rst << 9) | ((u32)app_xfer_pending << 8) | ((u32)app_req_exit_l1 << 7) | ((u32)app_ready_entr_l23 << 6) | ((u32)app_req_entr_l1 << 5) | ((u32)phy_clk_req_n << 4) | ((u32)app_clk_req_n << 3) | ((u32)apps_pm_xmt_pme << 2) | ((u32)tx_lane_flip_en << 1) | ((u32)rx_lane_flip_en << 0));
}

static inline void macsys_gcu_pcie_general_conf_unpack(struct cl_chip *chip, u8 *app_clk_pm_en, u8 *aux_clk_active, u8 *app_req_retry_en, u8 *app_init_rst, u8 *app_xfer_pending, u8 *app_req_exit_l1, u8 *app_ready_entr_l23, u8 *app_req_entr_l1, u8 *phy_clk_req_n, u8 *app_clk_req_n, u8 *apps_pm_xmt_pme, u8 *tx_lane_flip_en, u8 *rx_lane_flip_en)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	*app_clk_pm_en = (local_val & ((u32)0x00001000)) >> 12;
	*aux_clk_active = (local_val & ((u32)0x00000800)) >> 11;
	*app_req_retry_en = (local_val & ((u32)0x00000400)) >> 10;
	*app_init_rst = (local_val & ((u32)0x00000200)) >> 9;
	*app_xfer_pending = (local_val & ((u32)0x00000100)) >> 8;
	*app_req_exit_l1 = (local_val & ((u32)0x00000080)) >> 7;
	*app_ready_entr_l23 = (local_val & ((u32)0x00000040)) >> 6;
	*app_req_entr_l1 = (local_val & ((u32)0x00000020)) >> 5;
	*phy_clk_req_n = (local_val & ((u32)0x00000010)) >> 4;
	*app_clk_req_n = (local_val & ((u32)0x00000008)) >> 3;
	*apps_pm_xmt_pme = (local_val & ((u32)0x00000004)) >> 2;
	*tx_lane_flip_en = (local_val & ((u32)0x00000002)) >> 1;
	*rx_lane_flip_en = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macsys_gcu_pcie_general_conf_app_clk_pm_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void macsys_gcu_pcie_general_conf_app_clk_pm_en_setf(struct cl_chip *chip, u8 appclkpmen)
{
	ASSERT_ERR_CHIP((((u32)appclkpmen << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00001000)) | ((u32)appclkpmen << 12));
}

static inline u8 macsys_gcu_pcie_general_conf_aux_clk_active_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void macsys_gcu_pcie_general_conf_aux_clk_active_setf(struct cl_chip *chip, u8 auxclkactive)
{
	ASSERT_ERR_CHIP((((u32)auxclkactive << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00000800)) | ((u32)auxclkactive << 11));
}

static inline u8 macsys_gcu_pcie_general_conf_app_req_retry_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void macsys_gcu_pcie_general_conf_app_req_retry_en_setf(struct cl_chip *chip, u8 appreqretryen)
{
	ASSERT_ERR_CHIP((((u32)appreqretryen << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00000400)) | ((u32)appreqretryen << 10));
}

static inline u8 macsys_gcu_pcie_general_conf_app_init_rst_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void macsys_gcu_pcie_general_conf_app_init_rst_setf(struct cl_chip *chip, u8 appinitrst)
{
	ASSERT_ERR_CHIP((((u32)appinitrst << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00000200)) | ((u32)appinitrst << 9));
}

static inline u8 macsys_gcu_pcie_general_conf_app_xfer_pending_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000100)) >> 8);
}

static inline void macsys_gcu_pcie_general_conf_app_xfer_pending_setf(struct cl_chip *chip, u8 appxferpending)
{
	ASSERT_ERR_CHIP((((u32)appxferpending << 8) & ~((u32)0x00000100)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00000100)) | ((u32)appxferpending << 8));
}

static inline u8 macsys_gcu_pcie_general_conf_app_req_exit_l_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000080)) >> 7);
}

static inline void macsys_gcu_pcie_general_conf_app_req_exit_l_1_setf(struct cl_chip *chip, u8 appreqexitl1)
{
	ASSERT_ERR_CHIP((((u32)appreqexitl1 << 7) & ~((u32)0x00000080)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00000080)) | ((u32)appreqexitl1 << 7));
}

static inline u8 macsys_gcu_pcie_general_conf_app_ready_entr_l_23_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000040)) >> 6);
}

static inline void macsys_gcu_pcie_general_conf_app_ready_entr_l_23_setf(struct cl_chip *chip, u8 appreadyentrl23)
{
	ASSERT_ERR_CHIP((((u32)appreadyentrl23 << 6) & ~((u32)0x00000040)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00000040)) | ((u32)appreadyentrl23 << 6));
}

static inline u8 macsys_gcu_pcie_general_conf_app_req_entr_l_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000020)) >> 5);
}

static inline void macsys_gcu_pcie_general_conf_app_req_entr_l_1_setf(struct cl_chip *chip, u8 appreqentrl1)
{
	ASSERT_ERR_CHIP((((u32)appreqentrl1 << 5) & ~((u32)0x00000020)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00000020)) | ((u32)appreqentrl1 << 5));
}

static inline u8 macsys_gcu_pcie_general_conf_phy_clk_req_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline void macsys_gcu_pcie_general_conf_phy_clk_req_n_setf(struct cl_chip *chip, u8 phyclkreqn)
{
	ASSERT_ERR_CHIP((((u32)phyclkreqn << 4) & ~((u32)0x00000010)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00000010)) | ((u32)phyclkreqn << 4));
}

static inline u8 macsys_gcu_pcie_general_conf_app_clk_req_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void macsys_gcu_pcie_general_conf_app_clk_req_n_setf(struct cl_chip *chip, u8 appclkreqn)
{
	ASSERT_ERR_CHIP((((u32)appclkreqn << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00000008)) | ((u32)appclkreqn << 3));
}

static inline u8 macsys_gcu_pcie_general_conf_apps_pm_xmt_pme_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void macsys_gcu_pcie_general_conf_apps_pm_xmt_pme_setf(struct cl_chip *chip, u8 appspmxmtpme)
{
	ASSERT_ERR_CHIP((((u32)appspmxmtpme << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00000004)) | ((u32)appspmxmtpme << 2));
}

static inline u8 macsys_gcu_pcie_general_conf_tx_lane_flip_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void macsys_gcu_pcie_general_conf_tx_lane_flip_en_setf(struct cl_chip *chip, u8 txlaneflipen)
{
	ASSERT_ERR_CHIP((((u32)txlaneflipen << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00000002)) | ((u32)txlaneflipen << 1));
}

static inline u8 macsys_gcu_pcie_general_conf_rx_lane_flip_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macsys_gcu_pcie_general_conf_rx_lane_flip_en_setf(struct cl_chip *chip, u8 rxlaneflipen)
{
	ASSERT_ERR_CHIP((((u32)rxlaneflipen << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((u32)0x00000001)) | ((u32)rxlaneflipen << 0));
}

/**
 * @brief PCIE_PHY_BOOTER_DONE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    PCIE_PHY_BOOTER_DONE      0
 * </pre>
 */
#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x0000006C)
#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_OFFSET      0x0000006C
#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_INDEX       0x0000001B
#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_RESET       0x00000000

static inline u32 macsys_gcu_pcie_phy_booter_done_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_PCIE_PHY_BOOTER_DONE_ADDR);
}

static inline void macsys_gcu_pcie_phy_booter_done_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_PCIE_PHY_BOOTER_DONE_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_PCIE_PHY_BOOTER_DONE_BIT    ((u32)0x00000001)
#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_PCIE_PHY_BOOTER_DONE_POS    0

#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_PCIE_PHY_BOOTER_DONE_RST    0x0

static inline u8 macsys_gcu_pcie_phy_booter_done_pcie_phy_booter_done_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_PHY_BOOTER_DONE_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macsys_gcu_pcie_phy_booter_done_pcie_phy_booter_done_setf(struct cl_chip *chip, u8 pciephybooterdone)
{
	ASSERT_ERR_CHIP((((u32)pciephybooterdone << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_PHY_BOOTER_DONE_ADDR, (u32)pciephybooterdone << 0);
}

/**
 * @brief PCIE_APP_LTSSM_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    PCIE_BLOCK_RESET          0
 *    00    PCIE_APP_LTSS_EN          0
 * </pre>
 */
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000070)
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_OFFSET      0x00000070
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_INDEX       0x0000001C
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_RESET       0x00000000

static inline u32 macsys_gcu_pcie_app_ltssm_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR);
}

static inline void macsys_gcu_pcie_app_ltssm_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_PCIE_BLOCK_RESET_BIT    ((u32)0x00000002)
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_PCIE_BLOCK_RESET_POS    1
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_PCIE_APP_LTSS_EN_BIT    ((u32)0x00000001)
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_PCIE_APP_LTSS_EN_POS    0

#define MACSYS_GCU_PCIE_APP_LTSSM_EN_PCIE_BLOCK_RESET_RST    0x0
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_PCIE_APP_LTSS_EN_RST    0x0

static inline void macsys_gcu_pcie_app_ltssm_en_pack(struct cl_chip *chip, u8 pcie_block_reset, u8 pcie_app_ltss_en)
{
	ASSERT_ERR_CHIP((((u32)pcie_block_reset << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)pcie_app_ltss_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR, ((u32)pcie_block_reset << 1) | ((u32)pcie_app_ltss_en << 0));
}

static inline void macsys_gcu_pcie_app_ltssm_en_unpack(struct cl_chip *chip, u8 *pcie_block_reset, u8 *pcie_app_ltss_en)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR);

	*pcie_block_reset = (local_val & ((u32)0x00000002)) >> 1;
	*pcie_app_ltss_en = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macsys_gcu_pcie_app_ltssm_en_pcie_block_reset_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void macsys_gcu_pcie_app_ltssm_en_pcie_block_reset_setf(struct cl_chip *chip, u8 pcieblockreset)
{
	ASSERT_ERR_CHIP((((u32)pcieblockreset << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR) & ~((u32)0x00000002)) | ((u32)pcieblockreset << 1));
}

static inline u8 macsys_gcu_pcie_app_ltssm_en_pcie_app_ltss_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macsys_gcu_pcie_app_ltssm_en_pcie_app_ltss_en_setf(struct cl_chip *chip, u8 pcieappltssen)
{
	ASSERT_ERR_CHIP((((u32)pcieappltssen << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR) & ~((u32)0x00000001)) | ((u32)pcieappltssen << 0));
}

/**
 * @brief PCIE_CONF_0 register definition
 *  PCIE configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    22    PCIE_OPT_EN               0
 *    21:00 SLV_AWMISC_INFO           0x0
 * </pre>
 */
#define MACSYS_GCU_PCIE_CONF_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000080)
#define MACSYS_GCU_PCIE_CONF_0_OFFSET      0x00000080
#define MACSYS_GCU_PCIE_CONF_0_INDEX       0x00000020
#define MACSYS_GCU_PCIE_CONF_0_RESET       0x00000000

static inline u32 macsys_gcu_pcie_conf_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_PCIE_CONF_0_ADDR);
}

static inline void macsys_gcu_pcie_conf_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_PCIE_CONF_0_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_PCIE_CONF_0_PCIE_OPT_EN_BIT    ((u32)0x00400000)
#define MACSYS_GCU_PCIE_CONF_0_PCIE_OPT_EN_POS    22
#define MACSYS_GCU_PCIE_CONF_0_SLV_AWMISC_INFO_MASK    ((u32)0x003FFFFF)
#define MACSYS_GCU_PCIE_CONF_0_SLV_AWMISC_INFO_LSB    0
#define MACSYS_GCU_PCIE_CONF_0_SLV_AWMISC_INFO_WIDTH    ((u32)0x00000016)

#define MACSYS_GCU_PCIE_CONF_0_PCIE_OPT_EN_RST    0x0
#define MACSYS_GCU_PCIE_CONF_0_SLV_AWMISC_INFO_RST    0x0

static inline void macsys_gcu_pcie_conf_0_pack(struct cl_chip *chip, u8 pcie_opt_en, u32 slv_awmisc_info)
{
	ASSERT_ERR_CHIP((((u32)pcie_opt_en << 22) & ~((u32)0x00400000)) == 0);
	ASSERT_ERR_CHIP((((u32)slv_awmisc_info << 0) & ~((u32)0x003FFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_CONF_0_ADDR, ((u32)pcie_opt_en << 22) | ((u32)slv_awmisc_info << 0));
}

static inline void macsys_gcu_pcie_conf_0_unpack(struct cl_chip *chip, u8 *pcie_opt_en, u32 *slv_awmisc_info)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_CONF_0_ADDR);

	*pcie_opt_en = (local_val & ((u32)0x00400000)) >> 22;
	*slv_awmisc_info = (local_val & ((u32)0x003FFFFF)) >> 0;
}

static inline u8 macsys_gcu_pcie_conf_0_pcie_opt_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_CONF_0_ADDR);

	return (u8)((local_val & ((u32)0x00400000)) >> 22);
}

static inline void macsys_gcu_pcie_conf_0_pcie_opt_en_setf(struct cl_chip *chip, u8 pcieopten)
{
	ASSERT_ERR_CHIP((((u32)pcieopten << 22) & ~((u32)0x00400000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_CONF_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_CONF_0_ADDR) & ~((u32)0x00400000)) | ((u32)pcieopten << 22));
}

static inline u32 macsys_gcu_pcie_conf_0_slv_awmisc_info_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_CONF_0_ADDR);

	return (u32)((local_val & ((u32)0x003FFFFF)) >> 0);
}

static inline void macsys_gcu_pcie_conf_0_slv_awmisc_info_setf(struct cl_chip *chip, u32 slvawmiscinfo)
{
	ASSERT_ERR_CHIP((((u32)slvawmiscinfo << 0) & ~((u32)0x003FFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_CONF_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_PCIE_CONF_0_ADDR) & ~((u32)0x003FFFFF)) | ((u32)slvawmiscinfo << 0));
}

/**
 * @brief PCIE_CONF_1 register definition
 *  PCIE configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:00 SLV_ARMISC_INFO           0x0
 * </pre>
 */
#define MACSYS_GCU_PCIE_CONF_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000084)
#define MACSYS_GCU_PCIE_CONF_1_OFFSET      0x00000084
#define MACSYS_GCU_PCIE_CONF_1_INDEX       0x00000021
#define MACSYS_GCU_PCIE_CONF_1_RESET       0x00000000

static inline u32 macsys_gcu_pcie_conf_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_PCIE_CONF_1_ADDR);
}

static inline void macsys_gcu_pcie_conf_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_PCIE_CONF_1_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_PCIE_CONF_1_SLV_ARMISC_INFO_MASK    ((u32)0x003FFFFF)
#define MACSYS_GCU_PCIE_CONF_1_SLV_ARMISC_INFO_LSB    0
#define MACSYS_GCU_PCIE_CONF_1_SLV_ARMISC_INFO_WIDTH    ((u32)0x00000016)

#define MACSYS_GCU_PCIE_CONF_1_SLV_ARMISC_INFO_RST    0x0

static inline u32 macsys_gcu_pcie_conf_1_slv_armisc_info_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_CONF_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macsys_gcu_pcie_conf_1_slv_armisc_info_setf(struct cl_chip *chip, u32 slvarmiscinfo)
{
	ASSERT_ERR_CHIP((((u32)slvarmiscinfo << 0) & ~((u32)0x003FFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_CONF_1_ADDR, (u32)slvarmiscinfo << 0);
}

/**
 * @brief PCIE_WAKEUP_CMD register definition
 *  PCIE  wake up register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    OUTBAND_PWRUP_CMD         0
 * </pre>
 */
#define MACSYS_GCU_PCIE_WAKEUP_CMD_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000088)
#define MACSYS_GCU_PCIE_WAKEUP_CMD_OFFSET      0x00000088
#define MACSYS_GCU_PCIE_WAKEUP_CMD_INDEX       0x00000022
#define MACSYS_GCU_PCIE_WAKEUP_CMD_RESET       0x00000000

static inline u32 macsys_gcu_pcie_wakeup_cmd_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_PCIE_WAKEUP_CMD_ADDR);
}

static inline void macsys_gcu_pcie_wakeup_cmd_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_PCIE_WAKEUP_CMD_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_PCIE_WAKEUP_CMD_OUTBAND_PWRUP_CMD_BIT    ((u32)0x00000001)
#define MACSYS_GCU_PCIE_WAKEUP_CMD_OUTBAND_PWRUP_CMD_POS    0

#define MACSYS_GCU_PCIE_WAKEUP_CMD_OUTBAND_PWRUP_CMD_RST    0x0

static inline u8 macsys_gcu_pcie_wakeup_cmd_outband_pwrup_cmd_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PCIE_WAKEUP_CMD_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macsys_gcu_pcie_wakeup_cmd_outband_pwrup_cmd_setf(struct cl_chip *chip, u8 outbandpwrupcmd)
{
	ASSERT_ERR_CHIP((((u32)outbandpwrupcmd << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PCIE_WAKEUP_CMD_ADDR, (u32)outbandpwrupcmd << 0);
}

/**
 * @brief CYC_BUF_0 register definition
 *  cyclic buffer 0 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_0_BASE            0x0
 *    01:00 CYC_BUF_0_SIZE            0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000A0)
#define MACSYS_GCU_CYC_BUF_0_OFFSET      0x000000A0
#define MACSYS_GCU_CYC_BUF_0_INDEX       0x00000028
#define MACSYS_GCU_CYC_BUF_0_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_0_ADDR);
}

static inline void macsys_gcu_cyc_buf_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_0_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_0_pack(struct cl_chip *chip, u16 cyc_buf_0_base, u8 cyc_buf_0_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_0_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_0_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_0_ADDR, ((u32)cyc_buf_0_base << 12) | ((u32)cyc_buf_0_size << 0));
}

static inline void macsys_gcu_cyc_buf_0_unpack(struct cl_chip *chip, u16 *cyc_buf_0_base, u8 *cyc_buf_0_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_0_ADDR);

	*cyc_buf_0_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_0_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_0_cyc_buf_0_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_0_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_0_cyc_buf_0_base_setf(struct cl_chip *chip, u16 cycbuf0base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf0base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_0_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf0base << 12));
}

static inline u8 macsys_gcu_cyc_buf_0_cyc_buf_0_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_0_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_0_cyc_buf_0_size_setf(struct cl_chip *chip, u8 cycbuf0size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf0size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_0_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf0size << 0));
}

/**
 * @brief CYC_BUF_1 register definition
 *  cyclic buffer 1 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_1_BASE            0x0
 *    01:00 CYC_BUF_1_SIZE            0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000A4)
#define MACSYS_GCU_CYC_BUF_1_OFFSET      0x000000A4
#define MACSYS_GCU_CYC_BUF_1_INDEX       0x00000029
#define MACSYS_GCU_CYC_BUF_1_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_1_ADDR);
}

static inline void macsys_gcu_cyc_buf_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_1_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_1_pack(struct cl_chip *chip, u16 cyc_buf_1_base, u8 cyc_buf_1_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_1_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_1_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_1_ADDR, ((u32)cyc_buf_1_base << 12) | ((u32)cyc_buf_1_size << 0));
}

static inline void macsys_gcu_cyc_buf_1_unpack(struct cl_chip *chip, u16 *cyc_buf_1_base, u8 *cyc_buf_1_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_1_ADDR);

	*cyc_buf_1_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_1_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_1_cyc_buf_1_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_1_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_1_cyc_buf_1_base_setf(struct cl_chip *chip, u16 cycbuf1base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf1base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_1_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf1base << 12));
}

static inline u8 macsys_gcu_cyc_buf_1_cyc_buf_1_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_1_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_1_cyc_buf_1_size_setf(struct cl_chip *chip, u8 cycbuf1size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf1size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_1_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf1size << 0));
}

/**
 * @brief CYC_BUF_2 register definition
 *  cyclic buffer 2 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 cyc_buf_2_base            0x0
 *    01:00 cyc_buf_2_size            0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_2_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000A8)
#define MACSYS_GCU_CYC_BUF_2_OFFSET      0x000000A8
#define MACSYS_GCU_CYC_BUF_2_INDEX       0x0000002A
#define MACSYS_GCU_CYC_BUF_2_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_2_ADDR);
}

static inline void macsys_gcu_cyc_buf_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_2_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_2_pack(struct cl_chip *chip, u16 cyc_buf_2_base, u8 cyc_buf_2_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_2_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_2_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_2_ADDR, ((u32)cyc_buf_2_base << 12) | ((u32)cyc_buf_2_size << 0));
}

static inline void macsys_gcu_cyc_buf_2_unpack(struct cl_chip *chip, u16 *cyc_buf_2_base, u8 *cyc_buf_2_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_2_ADDR);

	*cyc_buf_2_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_2_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_2_cyc_buf_2_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_2_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_2_cyc_buf_2_base_setf(struct cl_chip *chip, u16 cycbuf2base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf2base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_2_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf2base << 12));
}

static inline u8 macsys_gcu_cyc_buf_2_cyc_buf_2_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_2_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_2_cyc_buf_2_size_setf(struct cl_chip *chip, u8 cycbuf2size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf2size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_2_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf2size << 0));
}

/**
 * @brief CYC_BUF_3 register definition
 *  cyclic buffer 3 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_3_BASE            0x0
 *    01:00 CYC_BUF_3_SIZE            0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_3_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000AC)
#define MACSYS_GCU_CYC_BUF_3_OFFSET      0x000000AC
#define MACSYS_GCU_CYC_BUF_3_INDEX       0x0000002B
#define MACSYS_GCU_CYC_BUF_3_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_3_ADDR);
}

static inline void macsys_gcu_cyc_buf_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_3_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_3_pack(struct cl_chip *chip, u16 cyc_buf_3_base, u8 cyc_buf_3_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_3_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_3_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_3_ADDR, ((u32)cyc_buf_3_base << 12) | ((u32)cyc_buf_3_size << 0));
}

static inline void macsys_gcu_cyc_buf_3_unpack(struct cl_chip *chip, u16 *cyc_buf_3_base, u8 *cyc_buf_3_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_3_ADDR);

	*cyc_buf_3_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_3_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_3_cyc_buf_3_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_3_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_3_cyc_buf_3_base_setf(struct cl_chip *chip, u16 cycbuf3base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf3base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_3_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf3base << 12));
}

static inline u8 macsys_gcu_cyc_buf_3_cyc_buf_3_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_3_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_3_cyc_buf_3_size_setf(struct cl_chip *chip, u8 cycbuf3size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf3size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_3_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf3size << 0));
}

/**
 * @brief CYC_BUF_4 register definition
 *  cyclic buffer 4 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_4_BASE            0x0
 *    01:00 CYC_BUF_4_SIZE            0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_4_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000B0)
#define MACSYS_GCU_CYC_BUF_4_OFFSET      0x000000B0
#define MACSYS_GCU_CYC_BUF_4_INDEX       0x0000002C
#define MACSYS_GCU_CYC_BUF_4_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_4_ADDR);
}

static inline void macsys_gcu_cyc_buf_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_4_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_4_pack(struct cl_chip *chip, u16 cyc_buf_4_base, u8 cyc_buf_4_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_4_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_4_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_4_ADDR, ((u32)cyc_buf_4_base << 12) | ((u32)cyc_buf_4_size << 0));
}

static inline void macsys_gcu_cyc_buf_4_unpack(struct cl_chip *chip, u16 *cyc_buf_4_base, u8 *cyc_buf_4_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_4_ADDR);

	*cyc_buf_4_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_4_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_4_cyc_buf_4_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_4_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_4_cyc_buf_4_base_setf(struct cl_chip *chip, u16 cycbuf4base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf4base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_4_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_4_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf4base << 12));
}

static inline u8 macsys_gcu_cyc_buf_4_cyc_buf_4_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_4_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_4_cyc_buf_4_size_setf(struct cl_chip *chip, u8 cycbuf4size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf4size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_4_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_4_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf4size << 0));
}

/**
 * @brief CYC_BUF_5 register definition
 *  cyclic buffer 5 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_5_BASE            0x0
 *    01:00 CYC_BUF_5_SIZE            0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_5_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000B4)
#define MACSYS_GCU_CYC_BUF_5_OFFSET      0x000000B4
#define MACSYS_GCU_CYC_BUF_5_INDEX       0x0000002D
#define MACSYS_GCU_CYC_BUF_5_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_5_ADDR);
}

static inline void macsys_gcu_cyc_buf_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_5_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_5_pack(struct cl_chip *chip, u16 cyc_buf_5_base, u8 cyc_buf_5_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_5_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_5_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_5_ADDR, ((u32)cyc_buf_5_base << 12) | ((u32)cyc_buf_5_size << 0));
}

static inline void macsys_gcu_cyc_buf_5_unpack(struct cl_chip *chip, u16 *cyc_buf_5_base, u8 *cyc_buf_5_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_5_ADDR);

	*cyc_buf_5_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_5_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_5_cyc_buf_5_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_5_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_5_cyc_buf_5_base_setf(struct cl_chip *chip, u16 cycbuf5base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf5base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_5_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_5_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf5base << 12));
}

static inline u8 macsys_gcu_cyc_buf_5_cyc_buf_5_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_5_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_5_cyc_buf_5_size_setf(struct cl_chip *chip, u8 cycbuf5size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf5size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_5_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_5_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf5size << 0));
}

/**
 * @brief CYC_BUF_6 register definition
 *  cyclic buffer 6 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_6_BASE            0x0
 *    01:00 CYC_BUF_6_SIZE            0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_6_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000B8)
#define MACSYS_GCU_CYC_BUF_6_OFFSET      0x000000B8
#define MACSYS_GCU_CYC_BUF_6_INDEX       0x0000002E
#define MACSYS_GCU_CYC_BUF_6_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_6_ADDR);
}

static inline void macsys_gcu_cyc_buf_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_6_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_6_pack(struct cl_chip *chip, u16 cyc_buf_6_base, u8 cyc_buf_6_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_6_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_6_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_6_ADDR, ((u32)cyc_buf_6_base << 12) | ((u32)cyc_buf_6_size << 0));
}

static inline void macsys_gcu_cyc_buf_6_unpack(struct cl_chip *chip, u16 *cyc_buf_6_base, u8 *cyc_buf_6_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_6_ADDR);

	*cyc_buf_6_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_6_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_6_cyc_buf_6_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_6_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_6_cyc_buf_6_base_setf(struct cl_chip *chip, u16 cycbuf6base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf6base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_6_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_6_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf6base << 12));
}

static inline u8 macsys_gcu_cyc_buf_6_cyc_buf_6_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_6_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_6_cyc_buf_6_size_setf(struct cl_chip *chip, u8 cycbuf6size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf6size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_6_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_6_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf6size << 0));
}

/**
 * @brief CYC_BUF_7 register definition
 *  cyclic buffer 7 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_7_BASE            0x0
 *    01:00 CYC_BUF_7_SIZE            0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_7_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000BC)
#define MACSYS_GCU_CYC_BUF_7_OFFSET      0x000000BC
#define MACSYS_GCU_CYC_BUF_7_INDEX       0x0000002F
#define MACSYS_GCU_CYC_BUF_7_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_7_ADDR);
}

static inline void macsys_gcu_cyc_buf_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_7_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_7_pack(struct cl_chip *chip, u16 cyc_buf_7_base, u8 cyc_buf_7_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_7_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_7_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_7_ADDR, ((u32)cyc_buf_7_base << 12) | ((u32)cyc_buf_7_size << 0));
}

static inline void macsys_gcu_cyc_buf_7_unpack(struct cl_chip *chip, u16 *cyc_buf_7_base, u8 *cyc_buf_7_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_7_ADDR);

	*cyc_buf_7_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_7_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_7_cyc_buf_7_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_7_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_7_cyc_buf_7_base_setf(struct cl_chip *chip, u16 cycbuf7base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf7base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_7_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_7_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf7base << 12));
}

static inline u8 macsys_gcu_cyc_buf_7_cyc_buf_7_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_7_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_7_cyc_buf_7_size_setf(struct cl_chip *chip, u8 cycbuf7size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf7size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_7_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_7_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf7size << 0));
}

/**
 * @brief CYC_BUF_8 register definition
 *  cyclic buffer 8 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_8_BASE            0x0
 *    01:00 CYC_BUF_8_SIZE            0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_8_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000C0)
#define MACSYS_GCU_CYC_BUF_8_OFFSET      0x000000C0
#define MACSYS_GCU_CYC_BUF_8_INDEX       0x00000030
#define MACSYS_GCU_CYC_BUF_8_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_8_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_8_ADDR);
}

static inline void macsys_gcu_cyc_buf_8_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_8_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_8_pack(struct cl_chip *chip, u16 cyc_buf_8_base, u8 cyc_buf_8_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_8_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_8_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_8_ADDR, ((u32)cyc_buf_8_base << 12) | ((u32)cyc_buf_8_size << 0));
}

static inline void macsys_gcu_cyc_buf_8_unpack(struct cl_chip *chip, u16 *cyc_buf_8_base, u8 *cyc_buf_8_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_8_ADDR);

	*cyc_buf_8_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_8_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_8_cyc_buf_8_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_8_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_8_cyc_buf_8_base_setf(struct cl_chip *chip, u16 cycbuf8base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf8base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_8_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_8_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf8base << 12));
}

static inline u8 macsys_gcu_cyc_buf_8_cyc_buf_8_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_8_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_8_cyc_buf_8_size_setf(struct cl_chip *chip, u8 cycbuf8size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf8size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_8_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_8_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf8size << 0));
}

/**
 * @brief CYC_BUF_9 register definition
 *  cyclic buffer 9 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_9_BASE            0x0
 *    01:00 CYC_BUF_9_SIZE            0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_9_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000C4)
#define MACSYS_GCU_CYC_BUF_9_OFFSET      0x000000C4
#define MACSYS_GCU_CYC_BUF_9_INDEX       0x00000031
#define MACSYS_GCU_CYC_BUF_9_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_9_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_9_ADDR);
}

static inline void macsys_gcu_cyc_buf_9_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_9_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_9_pack(struct cl_chip *chip, u16 cyc_buf_9_base, u8 cyc_buf_9_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_9_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_9_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_9_ADDR, ((u32)cyc_buf_9_base << 12) | ((u32)cyc_buf_9_size << 0));
}

static inline void macsys_gcu_cyc_buf_9_unpack(struct cl_chip *chip, u16 *cyc_buf_9_base, u8 *cyc_buf_9_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_9_ADDR);

	*cyc_buf_9_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_9_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_9_cyc_buf_9_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_9_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_9_cyc_buf_9_base_setf(struct cl_chip *chip, u16 cycbuf9base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf9base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_9_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_9_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf9base << 12));
}

static inline u8 macsys_gcu_cyc_buf_9_cyc_buf_9_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_9_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_9_cyc_buf_9_size_setf(struct cl_chip *chip, u8 cycbuf9size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf9size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_9_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_9_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf9size << 0));
}

/**
 * @brief CYC_BUF_10 register definition
 *  cyclic buffer 10 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_10_BASE           0x0
 *    01:00 CYC_BUF_10_SIZE           0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_10_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000C8)
#define MACSYS_GCU_CYC_BUF_10_OFFSET      0x000000C8
#define MACSYS_GCU_CYC_BUF_10_INDEX       0x00000032
#define MACSYS_GCU_CYC_BUF_10_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_10_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_10_ADDR);
}

static inline void macsys_gcu_cyc_buf_10_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_10_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_10_pack(struct cl_chip *chip, u16 cyc_buf_10_base, u8 cyc_buf_10_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_10_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_10_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_10_ADDR, ((u32)cyc_buf_10_base << 12) | ((u32)cyc_buf_10_size << 0));
}

static inline void macsys_gcu_cyc_buf_10_unpack(struct cl_chip *chip, u16 *cyc_buf_10_base, u8 *cyc_buf_10_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_10_ADDR);

	*cyc_buf_10_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_10_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_10_cyc_buf_10_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_10_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_10_cyc_buf_10_base_setf(struct cl_chip *chip, u16 cycbuf10base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf10base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_10_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_10_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf10base << 12));
}

static inline u8 macsys_gcu_cyc_buf_10_cyc_buf_10_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_10_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_10_cyc_buf_10_size_setf(struct cl_chip *chip, u8 cycbuf10size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf10size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_10_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_10_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf10size << 0));
}

/**
 * @brief CYC_BUF_11 register definition
 *  cyclic buffer 11 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_11_BASE           0x0
 *    01:00 CYC_BUF_11_SIZE           0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_11_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000CC)
#define MACSYS_GCU_CYC_BUF_11_OFFSET      0x000000CC
#define MACSYS_GCU_CYC_BUF_11_INDEX       0x00000033
#define MACSYS_GCU_CYC_BUF_11_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_11_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_11_ADDR);
}

static inline void macsys_gcu_cyc_buf_11_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_11_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_11_pack(struct cl_chip *chip, u16 cyc_buf_11_base, u8 cyc_buf_11_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_11_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_11_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_11_ADDR, ((u32)cyc_buf_11_base << 12) | ((u32)cyc_buf_11_size << 0));
}

static inline void macsys_gcu_cyc_buf_11_unpack(struct cl_chip *chip, u16 *cyc_buf_11_base, u8 *cyc_buf_11_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_11_ADDR);

	*cyc_buf_11_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_11_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_11_cyc_buf_11_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_11_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_11_cyc_buf_11_base_setf(struct cl_chip *chip, u16 cycbuf11base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf11base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_11_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_11_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf11base << 12));
}

static inline u8 macsys_gcu_cyc_buf_11_cyc_buf_11_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_11_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_11_cyc_buf_11_size_setf(struct cl_chip *chip, u8 cycbuf11size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf11size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_11_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_11_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf11size << 0));
}

/**
 * @brief CYC_BUF_12 register definition
 *  cyclic buffer 12 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_12_BASE           0x0
 *    01:00 CYC_BUF_12_SIZE           0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_12_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000D0)
#define MACSYS_GCU_CYC_BUF_12_OFFSET      0x000000D0
#define MACSYS_GCU_CYC_BUF_12_INDEX       0x00000034
#define MACSYS_GCU_CYC_BUF_12_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_12_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_12_ADDR);
}

static inline void macsys_gcu_cyc_buf_12_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_12_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_12_pack(struct cl_chip *chip, u16 cyc_buf_12_base, u8 cyc_buf_12_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_12_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_12_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_12_ADDR, ((u32)cyc_buf_12_base << 12) | ((u32)cyc_buf_12_size << 0));
}

static inline void macsys_gcu_cyc_buf_12_unpack(struct cl_chip *chip, u16 *cyc_buf_12_base, u8 *cyc_buf_12_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_12_ADDR);

	*cyc_buf_12_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_12_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_12_cyc_buf_12_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_12_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_12_cyc_buf_12_base_setf(struct cl_chip *chip, u16 cycbuf12base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf12base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_12_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_12_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf12base << 12));
}

static inline u8 macsys_gcu_cyc_buf_12_cyc_buf_12_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_12_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_12_cyc_buf_12_size_setf(struct cl_chip *chip, u8 cycbuf12size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf12size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_12_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_12_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf12size << 0));
}

/**
 * @brief CYC_BUF_13 register definition
 *  cyclic buffer 13 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_13_BASE           0x0
 *    01:00 CYC_BUF_13_SIZE           0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_13_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000D4)
#define MACSYS_GCU_CYC_BUF_13_OFFSET      0x000000D4
#define MACSYS_GCU_CYC_BUF_13_INDEX       0x00000035
#define MACSYS_GCU_CYC_BUF_13_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_13_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_13_ADDR);
}

static inline void macsys_gcu_cyc_buf_13_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_13_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_13_pack(struct cl_chip *chip, u16 cyc_buf_13_base, u8 cyc_buf_13_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_13_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_13_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_13_ADDR, ((u32)cyc_buf_13_base << 12) | ((u32)cyc_buf_13_size << 0));
}

static inline void macsys_gcu_cyc_buf_13_unpack(struct cl_chip *chip, u16 *cyc_buf_13_base, u8 *cyc_buf_13_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_13_ADDR);

	*cyc_buf_13_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_13_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_13_cyc_buf_13_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_13_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_13_cyc_buf_13_base_setf(struct cl_chip *chip, u16 cycbuf13base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf13base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_13_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_13_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf13base << 12));
}

static inline u8 macsys_gcu_cyc_buf_13_cyc_buf_13_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_13_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_13_cyc_buf_13_size_setf(struct cl_chip *chip, u8 cycbuf13size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf13size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_13_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_13_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf13size << 0));
}

/**
 * @brief CYC_BUF_14 register definition
 *  cyclic buffer 14 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_14_BASE           0x0
 *    01:00 CYC_BUF_14_SIZE           0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_14_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000D8)
#define MACSYS_GCU_CYC_BUF_14_OFFSET      0x000000D8
#define MACSYS_GCU_CYC_BUF_14_INDEX       0x00000036
#define MACSYS_GCU_CYC_BUF_14_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_14_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_14_ADDR);
}

static inline void macsys_gcu_cyc_buf_14_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_14_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_14_pack(struct cl_chip *chip, u16 cyc_buf_14_base, u8 cyc_buf_14_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_14_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_14_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_14_ADDR, ((u32)cyc_buf_14_base << 12) | ((u32)cyc_buf_14_size << 0));
}

static inline void macsys_gcu_cyc_buf_14_unpack(struct cl_chip *chip, u16 *cyc_buf_14_base, u8 *cyc_buf_14_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_14_ADDR);

	*cyc_buf_14_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_14_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_14_cyc_buf_14_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_14_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_14_cyc_buf_14_base_setf(struct cl_chip *chip, u16 cycbuf14base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf14base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_14_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_14_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf14base << 12));
}

static inline u8 macsys_gcu_cyc_buf_14_cyc_buf_14_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_14_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_14_cyc_buf_14_size_setf(struct cl_chip *chip, u8 cycbuf14size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf14size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_14_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_14_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf14size << 0));
}

/**
 * @brief CYC_BUF_15 register definition
 *  cyclic buffer 15 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_15_BASE           0x0
 *    01:00 CYC_BUF_15_SIZE           0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_15_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000DC)
#define MACSYS_GCU_CYC_BUF_15_OFFSET      0x000000DC
#define MACSYS_GCU_CYC_BUF_15_INDEX       0x00000037
#define MACSYS_GCU_CYC_BUF_15_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_15_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_15_ADDR);
}

static inline void macsys_gcu_cyc_buf_15_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_15_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_15_pack(struct cl_chip *chip, u16 cyc_buf_15_base, u8 cyc_buf_15_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_15_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_15_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_15_ADDR, ((u32)cyc_buf_15_base << 12) | ((u32)cyc_buf_15_size << 0));
}

static inline void macsys_gcu_cyc_buf_15_unpack(struct cl_chip *chip, u16 *cyc_buf_15_base, u8 *cyc_buf_15_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_15_ADDR);

	*cyc_buf_15_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_15_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_15_cyc_buf_15_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_15_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_15_cyc_buf_15_base_setf(struct cl_chip *chip, u16 cycbuf15base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf15base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_15_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_15_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf15base << 12));
}

static inline u8 macsys_gcu_cyc_buf_15_cyc_buf_15_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_15_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_15_cyc_buf_15_size_setf(struct cl_chip *chip, u8 cycbuf15size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf15size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_15_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_15_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf15size << 0));
}

/**
 * @brief CYC_BUF_16 register definition
 *  cyclic buffer 16 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_16_BASE           0x0
 *    01:00 CYC_BUF_16_SIZE           0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_16_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000E0)
#define MACSYS_GCU_CYC_BUF_16_OFFSET      0x000000E0
#define MACSYS_GCU_CYC_BUF_16_INDEX       0x00000038
#define MACSYS_GCU_CYC_BUF_16_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_16_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_16_ADDR);
}

static inline void macsys_gcu_cyc_buf_16_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_16_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_16_pack(struct cl_chip *chip, u16 cyc_buf_16_base, u8 cyc_buf_16_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_16_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_16_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_16_ADDR, ((u32)cyc_buf_16_base << 12) | ((u32)cyc_buf_16_size << 0));
}

static inline void macsys_gcu_cyc_buf_16_unpack(struct cl_chip *chip, u16 *cyc_buf_16_base, u8 *cyc_buf_16_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_16_ADDR);

	*cyc_buf_16_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_16_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_16_cyc_buf_16_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_16_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_16_cyc_buf_16_base_setf(struct cl_chip *chip, u16 cycbuf16base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf16base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_16_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_16_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf16base << 12));
}

static inline u8 macsys_gcu_cyc_buf_16_cyc_buf_16_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_16_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_16_cyc_buf_16_size_setf(struct cl_chip *chip, u8 cycbuf16size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf16size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_16_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_16_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf16size << 0));
}

/**
 * @brief CYC_BUF_17 register definition
 *  cyclic buffer 17 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_17_BASE           0x0
 *    01:00 CYC_BUF_17_SIZE           0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_17_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000E4)
#define MACSYS_GCU_CYC_BUF_17_OFFSET      0x000000E4
#define MACSYS_GCU_CYC_BUF_17_INDEX       0x00000039
#define MACSYS_GCU_CYC_BUF_17_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_17_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_17_ADDR);
}

static inline void macsys_gcu_cyc_buf_17_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_17_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_17_pack(struct cl_chip *chip, u16 cyc_buf_17_base, u8 cyc_buf_17_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_17_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_17_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_17_ADDR, ((u32)cyc_buf_17_base << 12) | ((u32)cyc_buf_17_size << 0));
}

static inline void macsys_gcu_cyc_buf_17_unpack(struct cl_chip *chip, u16 *cyc_buf_17_base, u8 *cyc_buf_17_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_17_ADDR);

	*cyc_buf_17_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_17_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_17_cyc_buf_17_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_17_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_17_cyc_buf_17_base_setf(struct cl_chip *chip, u16 cycbuf17base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf17base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_17_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_17_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf17base << 12));
}

static inline u8 macsys_gcu_cyc_buf_17_cyc_buf_17_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_17_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_17_cyc_buf_17_size_setf(struct cl_chip *chip, u8 cycbuf17size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf17size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_17_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_17_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf17size << 0));
}

/**
 * @brief CYC_BUF_18 register definition
 *  cyclic buffer 18 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_18_BASE           0x0
 *    01:00 CYC_BUF_18_SIZE           0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_18_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000E8)
#define MACSYS_GCU_CYC_BUF_18_OFFSET      0x000000E8
#define MACSYS_GCU_CYC_BUF_18_INDEX       0x0000003A
#define MACSYS_GCU_CYC_BUF_18_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_18_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_18_ADDR);
}

static inline void macsys_gcu_cyc_buf_18_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_18_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_18_pack(struct cl_chip *chip, u16 cyc_buf_18_base, u8 cyc_buf_18_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_18_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_18_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_18_ADDR, ((u32)cyc_buf_18_base << 12) | ((u32)cyc_buf_18_size << 0));
}

static inline void macsys_gcu_cyc_buf_18_unpack(struct cl_chip *chip, u16 *cyc_buf_18_base, u8 *cyc_buf_18_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_18_ADDR);

	*cyc_buf_18_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_18_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_18_cyc_buf_18_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_18_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_18_cyc_buf_18_base_setf(struct cl_chip *chip, u16 cycbuf18base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf18base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_18_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_18_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf18base << 12));
}

static inline u8 macsys_gcu_cyc_buf_18_cyc_buf_18_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_18_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_18_cyc_buf_18_size_setf(struct cl_chip *chip, u8 cycbuf18size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf18size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_18_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_18_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf18size << 0));
}

/**
 * @brief CYC_BUF_19 register definition
 *  cyclic buffer 19 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:12 CYC_BUF_19_BASE           0x0
 *    01:00 CYC_BUF_19_SIZE           0x0
 * </pre>
 */
#define MACSYS_GCU_CYC_BUF_19_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000EC)
#define MACSYS_GCU_CYC_BUF_19_OFFSET      0x000000EC
#define MACSYS_GCU_CYC_BUF_19_INDEX       0x0000003B
#define MACSYS_GCU_CYC_BUF_19_RESET       0x00000000

static inline u32 macsys_gcu_cyc_buf_19_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_CYC_BUF_19_ADDR);
}

static inline void macsys_gcu_cyc_buf_19_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_19_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_BASE_MASK    ((u32)0x001FF000)
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_BASE_WIDTH    ((u32)0x00000009)
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_SIZE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_SIZE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_SIZE_RST    0x0

static inline void macsys_gcu_cyc_buf_19_pack(struct cl_chip *chip, u16 cyc_buf_19_base, u8 cyc_buf_19_size)
{
	ASSERT_ERR_CHIP((((u32)cyc_buf_19_base << 12) & ~((u32)0x001FF000)) == 0);
	ASSERT_ERR_CHIP((((u32)cyc_buf_19_size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_19_ADDR, ((u32)cyc_buf_19_base << 12) | ((u32)cyc_buf_19_size << 0));
}

static inline void macsys_gcu_cyc_buf_19_unpack(struct cl_chip *chip, u16 *cyc_buf_19_base, u8 *cyc_buf_19_size)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_19_ADDR);

	*cyc_buf_19_base = (local_val & ((u32)0x001FF000)) >> 12;
	*cyc_buf_19_size = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u16 macsys_gcu_cyc_buf_19_cyc_buf_19_base_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_19_ADDR);

	return (u16)((local_val & ((u32)0x001FF000)) >> 12);
}

static inline void macsys_gcu_cyc_buf_19_cyc_buf_19_base_setf(struct cl_chip *chip, u16 cycbuf19base)
{
	ASSERT_ERR_CHIP((((u32)cycbuf19base << 12) & ~((u32)0x001FF000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_19_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_19_ADDR) & ~((u32)0x001FF000)) | ((u32)cycbuf19base << 12));
}

static inline u8 macsys_gcu_cyc_buf_19_cyc_buf_19_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_CYC_BUF_19_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_cyc_buf_19_cyc_buf_19_size_setf(struct cl_chip *chip, u8 cycbuf19size)
{
	ASSERT_ERR_CHIP((((u32)cycbuf19size << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_CYC_BUF_19_ADDR, (cl_reg_read(chip, MACSYS_GCU_CYC_BUF_19_ADDR) & ~((u32)0x00000003)) | ((u32)cycbuf19size << 0));
}

/**
 * @brief XT_CONTROL register definition
 *  Tensilica control register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21    smac_debug_en             0
 *    20    smac_break_in             0
 *    19    smac_ocd_halt_on_reset    1
 *    18    smac_run_stall            0
 *    17    smac_dreset_n             1
 *    16    smac_breset_n             0
 *    13    umac_debug_en             0
 *    12    umac_break_in             0
 *    11    umac_ocd_halt_on_reset    1
 *    10    umac_run_stall            0
 *    09    umac_dreset_n             1
 *    08    umac_breset_n             0
 *    05    lmac_debug_en             0
 *    04    lmac_break_in             0
 *    03    lmac_ocd_halt_on_reset    1
 *    02    lmac_run_stall            0
 *    01    lmac_dreset_n             1
 *    00    lmac_breset_n             0
 * </pre>
 */
#define MACSYS_GCU_XT_CONTROL_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000F0)
#define MACSYS_GCU_XT_CONTROL_OFFSET      0x000000F0
#define MACSYS_GCU_XT_CONTROL_INDEX       0x0000003C
#define MACSYS_GCU_XT_CONTROL_RESET       0x000A0A0A

static inline u32 macsys_gcu_xt_control_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);
}

static inline void macsys_gcu_xt_control_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_XT_CONTROL_SMAC_DEBUG_EN_BIT    ((u32)0x00200000)
#define MACSYS_GCU_XT_CONTROL_SMAC_DEBUG_EN_POS    21
#define MACSYS_GCU_XT_CONTROL_SMAC_BREAK_IN_BIT    ((u32)0x00100000)
#define MACSYS_GCU_XT_CONTROL_SMAC_BREAK_IN_POS    20
#define MACSYS_GCU_XT_CONTROL_SMAC_OCD_HALT_ON_RESET_BIT    ((u32)0x00080000)
#define MACSYS_GCU_XT_CONTROL_SMAC_OCD_HALT_ON_RESET_POS    19
#define MACSYS_GCU_XT_CONTROL_SMAC_RUN_STALL_BIT    ((u32)0x00040000)
#define MACSYS_GCU_XT_CONTROL_SMAC_RUN_STALL_POS    18
#define MACSYS_GCU_XT_CONTROL_SMAC_DRESET_N_BIT    ((u32)0x00020000)
#define MACSYS_GCU_XT_CONTROL_SMAC_DRESET_N_POS    17
#define MACSYS_GCU_XT_CONTROL_SMAC_BRESET_N_BIT    ((u32)0x00010000)
#define MACSYS_GCU_XT_CONTROL_SMAC_BRESET_N_POS    16
#define MACSYS_GCU_XT_CONTROL_UMAC_DEBUG_EN_BIT    ((u32)0x00002000)
#define MACSYS_GCU_XT_CONTROL_UMAC_DEBUG_EN_POS    13
#define MACSYS_GCU_XT_CONTROL_UMAC_BREAK_IN_BIT    ((u32)0x00001000)
#define MACSYS_GCU_XT_CONTROL_UMAC_BREAK_IN_POS    12
#define MACSYS_GCU_XT_CONTROL_UMAC_OCD_HALT_ON_RESET_BIT    ((u32)0x00000800)
#define MACSYS_GCU_XT_CONTROL_UMAC_OCD_HALT_ON_RESET_POS    11
#define MACSYS_GCU_XT_CONTROL_UMAC_RUN_STALL_BIT    ((u32)0x00000400)
#define MACSYS_GCU_XT_CONTROL_UMAC_RUN_STALL_POS    10
#define MACSYS_GCU_XT_CONTROL_UMAC_DRESET_N_BIT    ((u32)0x00000200)
#define MACSYS_GCU_XT_CONTROL_UMAC_DRESET_N_POS    9
#define MACSYS_GCU_XT_CONTROL_UMAC_BRESET_N_BIT    ((u32)0x00000100)
#define MACSYS_GCU_XT_CONTROL_UMAC_BRESET_N_POS    8
#define MACSYS_GCU_XT_CONTROL_LMAC_DEBUG_EN_BIT    ((u32)0x00000020)
#define MACSYS_GCU_XT_CONTROL_LMAC_DEBUG_EN_POS    5
#define MACSYS_GCU_XT_CONTROL_LMAC_BREAK_IN_BIT    ((u32)0x00000010)
#define MACSYS_GCU_XT_CONTROL_LMAC_BREAK_IN_POS    4
#define MACSYS_GCU_XT_CONTROL_LMAC_OCD_HALT_ON_RESET_BIT    ((u32)0x00000008)
#define MACSYS_GCU_XT_CONTROL_LMAC_OCD_HALT_ON_RESET_POS    3
#define MACSYS_GCU_XT_CONTROL_LMAC_RUN_STALL_BIT    ((u32)0x00000004)
#define MACSYS_GCU_XT_CONTROL_LMAC_RUN_STALL_POS    2
#define MACSYS_GCU_XT_CONTROL_LMAC_DRESET_N_BIT    ((u32)0x00000002)
#define MACSYS_GCU_XT_CONTROL_LMAC_DRESET_N_POS    1
#define MACSYS_GCU_XT_CONTROL_LMAC_BRESET_N_BIT    ((u32)0x00000001)
#define MACSYS_GCU_XT_CONTROL_LMAC_BRESET_N_POS    0

#define MACSYS_GCU_XT_CONTROL_SMAC_DEBUG_EN_RST    0x0
#define MACSYS_GCU_XT_CONTROL_SMAC_BREAK_IN_RST    0x0
#define MACSYS_GCU_XT_CONTROL_SMAC_OCD_HALT_ON_RESET_RST    0x1
#define MACSYS_GCU_XT_CONTROL_SMAC_RUN_STALL_RST    0x0
#define MACSYS_GCU_XT_CONTROL_SMAC_DRESET_N_RST    0x1
#define MACSYS_GCU_XT_CONTROL_SMAC_BRESET_N_RST    0x0
#define MACSYS_GCU_XT_CONTROL_UMAC_DEBUG_EN_RST    0x0
#define MACSYS_GCU_XT_CONTROL_UMAC_BREAK_IN_RST    0x0
#define MACSYS_GCU_XT_CONTROL_UMAC_OCD_HALT_ON_RESET_RST    0x1
#define MACSYS_GCU_XT_CONTROL_UMAC_RUN_STALL_RST    0x0
#define MACSYS_GCU_XT_CONTROL_UMAC_DRESET_N_RST    0x1
#define MACSYS_GCU_XT_CONTROL_UMAC_BRESET_N_RST    0x0
#define MACSYS_GCU_XT_CONTROL_LMAC_DEBUG_EN_RST    0x0
#define MACSYS_GCU_XT_CONTROL_LMAC_BREAK_IN_RST    0x0
#define MACSYS_GCU_XT_CONTROL_LMAC_OCD_HALT_ON_RESET_RST    0x1
#define MACSYS_GCU_XT_CONTROL_LMAC_RUN_STALL_RST    0x0
#define MACSYS_GCU_XT_CONTROL_LMAC_DRESET_N_RST    0x1
#define MACSYS_GCU_XT_CONTROL_LMAC_BRESET_N_RST    0x0

static inline void macsys_gcu_xt_control_pack(struct cl_chip *chip, u8 smac_debug_en, u8 smac_break_in, u8 smac_ocd_halt_on_reset, u8 smac_run_stall, u8 smac_dreset_n, u8 smac_breset_n, u8 umac_debug_en, u8 umac_break_in, u8 umac_ocd_halt_on_reset, u8 umac_run_stall, u8 umac_dreset_n, u8 umac_breset_n, u8 lmac_debug_en, u8 lmac_break_in, u8 lmac_ocd_halt_on_reset, u8 lmac_run_stall, u8 lmac_dreset_n, u8 lmac_breset_n)
{
	ASSERT_ERR_CHIP((((u32)smac_debug_en << 21) & ~((u32)0x00200000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_break_in << 20) & ~((u32)0x00100000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_ocd_halt_on_reset << 19) & ~((u32)0x00080000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_run_stall << 18) & ~((u32)0x00040000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_dreset_n << 17) & ~((u32)0x00020000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_breset_n << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_debug_en << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_break_in << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_ocd_halt_on_reset << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_run_stall << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_dreset_n << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_breset_n << 8) & ~((u32)0x00000100)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_debug_en << 5) & ~((u32)0x00000020)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_break_in << 4) & ~((u32)0x00000010)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_ocd_halt_on_reset << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_run_stall << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_dreset_n << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_breset_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, ((u32)smac_debug_en << 21) | ((u32)smac_break_in << 20) | ((u32)smac_ocd_halt_on_reset << 19) | ((u32)smac_run_stall << 18) | ((u32)smac_dreset_n << 17) | ((u32)smac_breset_n << 16) | ((u32)umac_debug_en << 13) | ((u32)umac_break_in << 12) | ((u32)umac_ocd_halt_on_reset << 11) | ((u32)umac_run_stall << 10) | ((u32)umac_dreset_n << 9) | ((u32)umac_breset_n << 8) | ((u32)lmac_debug_en << 5) | ((u32)lmac_break_in << 4) | ((u32)lmac_ocd_halt_on_reset << 3) | ((u32)lmac_run_stall << 2) | ((u32)lmac_dreset_n << 1) | ((u32)lmac_breset_n << 0));
}

static inline void macsys_gcu_xt_control_unpack(struct cl_chip *chip, u8 *smac_debug_en, u8 *smac_break_in, u8 *smac_ocd_halt_on_reset, u8 *smac_run_stall, u8 *smac_dreset_n, u8 *smac_breset_n, u8 *umac_debug_en, u8 *umac_break_in, u8 *umac_ocd_halt_on_reset, u8 *umac_run_stall, u8 *umac_dreset_n, u8 *umac_breset_n, u8 *lmac_debug_en, u8 *lmac_break_in, u8 *lmac_ocd_halt_on_reset, u8 *lmac_run_stall, u8 *lmac_dreset_n, u8 *lmac_breset_n)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	*smac_debug_en = (local_val & ((u32)0x00200000)) >> 21;
	*smac_break_in = (local_val & ((u32)0x00100000)) >> 20;
	*smac_ocd_halt_on_reset = (local_val & ((u32)0x00080000)) >> 19;
	*smac_run_stall = (local_val & ((u32)0x00040000)) >> 18;
	*smac_dreset_n = (local_val & ((u32)0x00020000)) >> 17;
	*smac_breset_n = (local_val & ((u32)0x00010000)) >> 16;
	*umac_debug_en = (local_val & ((u32)0x00002000)) >> 13;
	*umac_break_in = (local_val & ((u32)0x00001000)) >> 12;
	*umac_ocd_halt_on_reset = (local_val & ((u32)0x00000800)) >> 11;
	*umac_run_stall = (local_val & ((u32)0x00000400)) >> 10;
	*umac_dreset_n = (local_val & ((u32)0x00000200)) >> 9;
	*umac_breset_n = (local_val & ((u32)0x00000100)) >> 8;
	*lmac_debug_en = (local_val & ((u32)0x00000020)) >> 5;
	*lmac_break_in = (local_val & ((u32)0x00000010)) >> 4;
	*lmac_ocd_halt_on_reset = (local_val & ((u32)0x00000008)) >> 3;
	*lmac_run_stall = (local_val & ((u32)0x00000004)) >> 2;
	*lmac_dreset_n = (local_val & ((u32)0x00000002)) >> 1;
	*lmac_breset_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macsys_gcu_xt_control_smac_debug_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00200000)) >> 21);
}

static inline void macsys_gcu_xt_control_smac_debug_en_setf(struct cl_chip *chip, u8 smacdebugen)
{
	ASSERT_ERR_CHIP((((u32)smacdebugen << 21) & ~((u32)0x00200000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00200000)) | ((u32)smacdebugen << 21));
}

static inline u8 macsys_gcu_xt_control_smac_break_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00100000)) >> 20);
}

static inline void macsys_gcu_xt_control_smac_break_in_setf(struct cl_chip *chip, u8 smacbreakin)
{
	ASSERT_ERR_CHIP((((u32)smacbreakin << 20) & ~((u32)0x00100000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00100000)) | ((u32)smacbreakin << 20));
}

static inline u8 macsys_gcu_xt_control_smac_ocd_halt_on_reset_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00080000)) >> 19);
}

static inline void macsys_gcu_xt_control_smac_ocd_halt_on_reset_setf(struct cl_chip *chip, u8 smacocdhaltonreset)
{
	ASSERT_ERR_CHIP((((u32)smacocdhaltonreset << 19) & ~((u32)0x00080000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00080000)) | ((u32)smacocdhaltonreset << 19));
}

static inline u8 macsys_gcu_xt_control_smac_run_stall_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00040000)) >> 18);
}

static inline void macsys_gcu_xt_control_smac_run_stall_setf(struct cl_chip *chip, u8 smacrunstall)
{
	ASSERT_ERR_CHIP((((u32)smacrunstall << 18) & ~((u32)0x00040000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00040000)) | ((u32)smacrunstall << 18));
}

static inline u8 macsys_gcu_xt_control_smac_dreset_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00020000)) >> 17);
}

static inline void macsys_gcu_xt_control_smac_dreset_n_setf(struct cl_chip *chip, u8 smacdresetn)
{
	ASSERT_ERR_CHIP((((u32)smacdresetn << 17) & ~((u32)0x00020000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00020000)) | ((u32)smacdresetn << 17));
}

static inline u8 macsys_gcu_xt_control_smac_breset_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void macsys_gcu_xt_control_smac_breset_n_setf(struct cl_chip *chip, u8 smacbresetn)
{
	ASSERT_ERR_CHIP((((u32)smacbresetn << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00010000)) | ((u32)smacbresetn << 16));
}

static inline u8 macsys_gcu_xt_control_umac_debug_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void macsys_gcu_xt_control_umac_debug_en_setf(struct cl_chip *chip, u8 umacdebugen)
{
	ASSERT_ERR_CHIP((((u32)umacdebugen << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00002000)) | ((u32)umacdebugen << 13));
}

static inline u8 macsys_gcu_xt_control_umac_break_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void macsys_gcu_xt_control_umac_break_in_setf(struct cl_chip *chip, u8 umacbreakin)
{
	ASSERT_ERR_CHIP((((u32)umacbreakin << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00001000)) | ((u32)umacbreakin << 12));
}

static inline u8 macsys_gcu_xt_control_umac_ocd_halt_on_reset_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void macsys_gcu_xt_control_umac_ocd_halt_on_reset_setf(struct cl_chip *chip, u8 umacocdhaltonreset)
{
	ASSERT_ERR_CHIP((((u32)umacocdhaltonreset << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00000800)) | ((u32)umacocdhaltonreset << 11));
}

static inline u8 macsys_gcu_xt_control_umac_run_stall_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void macsys_gcu_xt_control_umac_run_stall_setf(struct cl_chip *chip, u8 umacrunstall)
{
	ASSERT_ERR_CHIP((((u32)umacrunstall << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00000400)) | ((u32)umacrunstall << 10));
}

static inline u8 macsys_gcu_xt_control_umac_dreset_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void macsys_gcu_xt_control_umac_dreset_n_setf(struct cl_chip *chip, u8 umacdresetn)
{
	ASSERT_ERR_CHIP((((u32)umacdresetn << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00000200)) | ((u32)umacdresetn << 9));
}

static inline u8 macsys_gcu_xt_control_umac_breset_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00000100)) >> 8);
}

static inline void macsys_gcu_xt_control_umac_breset_n_setf(struct cl_chip *chip, u8 umacbresetn)
{
	ASSERT_ERR_CHIP((((u32)umacbresetn << 8) & ~((u32)0x00000100)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00000100)) | ((u32)umacbresetn << 8));
}

static inline u8 macsys_gcu_xt_control_lmac_debug_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00000020)) >> 5);
}

static inline void macsys_gcu_xt_control_lmac_debug_en_setf(struct cl_chip *chip, u8 lmacdebugen)
{
	ASSERT_ERR_CHIP((((u32)lmacdebugen << 5) & ~((u32)0x00000020)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00000020)) | ((u32)lmacdebugen << 5));
}

static inline u8 macsys_gcu_xt_control_lmac_break_in_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline void macsys_gcu_xt_control_lmac_break_in_setf(struct cl_chip *chip, u8 lmacbreakin)
{
	ASSERT_ERR_CHIP((((u32)lmacbreakin << 4) & ~((u32)0x00000010)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00000010)) | ((u32)lmacbreakin << 4));
}

static inline u8 macsys_gcu_xt_control_lmac_ocd_halt_on_reset_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void macsys_gcu_xt_control_lmac_ocd_halt_on_reset_setf(struct cl_chip *chip, u8 lmacocdhaltonreset)
{
	ASSERT_ERR_CHIP((((u32)lmacocdhaltonreset << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00000008)) | ((u32)lmacocdhaltonreset << 3));
}

static inline u8 macsys_gcu_xt_control_lmac_run_stall_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void macsys_gcu_xt_control_lmac_run_stall_setf(struct cl_chip *chip, u8 lmacrunstall)
{
	ASSERT_ERR_CHIP((((u32)lmacrunstall << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00000004)) | ((u32)lmacrunstall << 2));
}

static inline u8 macsys_gcu_xt_control_lmac_dreset_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void macsys_gcu_xt_control_lmac_dreset_n_setf(struct cl_chip *chip, u8 lmacdresetn)
{
	ASSERT_ERR_CHIP((((u32)lmacdresetn << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00000002)) | ((u32)lmacdresetn << 1));
}

static inline u8 macsys_gcu_xt_control_lmac_breset_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macsys_gcu_xt_control_lmac_breset_n_setf(struct cl_chip *chip, u8 lmacbresetn)
{
	ASSERT_ERR_CHIP((((u32)lmacbresetn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_XT_CONTROL_ADDR, (cl_reg_read(chip, MACSYS_GCU_XT_CONTROL_ADDR) & ~((u32)0x00000001)) | ((u32)lmacbresetn << 0));
}

/**
 * @brief XT_STATUS register definition
 *  Tensilica status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    18    smac_break_out            0
 *    17    umac_break_out            0
 *    16    lmac_break_out            0
 * </pre>
 */
#define MACSYS_GCU_XT_STATUS_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000000F4)
#define MACSYS_GCU_XT_STATUS_OFFSET      0x000000F4
#define MACSYS_GCU_XT_STATUS_INDEX       0x0000003D
#define MACSYS_GCU_XT_STATUS_RESET       0x00000000

static inline u32 macsys_gcu_xt_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_XT_STATUS_ADDR);
}

/* Field definitions */
#define MACSYS_GCU_XT_STATUS_SMAC_BREAK_OUT_BIT    ((u32)0x00040000)
#define MACSYS_GCU_XT_STATUS_SMAC_BREAK_OUT_POS    18
#define MACSYS_GCU_XT_STATUS_UMAC_BREAK_OUT_BIT    ((u32)0x00020000)
#define MACSYS_GCU_XT_STATUS_UMAC_BREAK_OUT_POS    17
#define MACSYS_GCU_XT_STATUS_LMAC_BREAK_OUT_BIT    ((u32)0x00010000)
#define MACSYS_GCU_XT_STATUS_LMAC_BREAK_OUT_POS    16

#define MACSYS_GCU_XT_STATUS_SMAC_BREAK_OUT_RST    0x0
#define MACSYS_GCU_XT_STATUS_UMAC_BREAK_OUT_RST    0x0
#define MACSYS_GCU_XT_STATUS_LMAC_BREAK_OUT_RST    0x0

static inline void macsys_gcu_xt_status_unpack(struct cl_chip *chip, u8 *smac_break_out, u8 *umac_break_out, u8 *lmac_break_out)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_STATUS_ADDR);

	*smac_break_out = (local_val & ((u32)0x00040000)) >> 18;
	*umac_break_out = (local_val & ((u32)0x00020000)) >> 17;
	*lmac_break_out = (local_val & ((u32)0x00010000)) >> 16;
}

static inline u8 macsys_gcu_xt_status_smac_break_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00040000)) >> 18);
}

static inline u8 macsys_gcu_xt_status_umac_break_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00020000)) >> 17);
}

static inline u8 macsys_gcu_xt_status_lmac_break_out_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_XT_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

/**
 * @brief AHB_2_AXI_CTRL register definition
 *  AHB2AXI Bridge Control register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    WRITE_ORDER_PRESERVE_E2_W 0
 *    13    PREFETCH_EN_USBW          0
 *    12    PREFETCH_EN_MACHW         1
 *    11    PREFETCH_EN_PCIE          1
 *    10    PREFETCH_EN_PCIEW         0
 *    09    PREFETCH_EN_E2_W          0
 *    08    PREFETCH_EN_NATT          1
 *    05    BUFFERABLE_USBW           0
 *    04    BUFFERABLE_MACHW          1
 *    03    BUFFERABLE_PCIE           1
 *    02    BUFFERABLE_PCIEW          0
 *    01    BUFFERABLE_E2_W           0
 *    00    BUFFERABLE_NATT           0
 * </pre>
 */
#define MACSYS_GCU_AHB_2_AXI_CTRL_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000100)
#define MACSYS_GCU_AHB_2_AXI_CTRL_OFFSET      0x00000100
#define MACSYS_GCU_AHB_2_AXI_CTRL_INDEX       0x00000040
#define MACSYS_GCU_AHB_2_AXI_CTRL_RESET       0x00001918

static inline u32 macsys_gcu_ahb_2_axi_ctrl_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_AHB_2_AXI_CTRL_WRITE_ORDER_PRESERVE_E_2_W_BIT    ((u32)0x00010000)
#define MACSYS_GCU_AHB_2_AXI_CTRL_WRITE_ORDER_PRESERVE_E_2_W_POS    16
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_USBW_BIT    ((u32)0x00002000)
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_USBW_POS    13
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_MACHW_BIT    ((u32)0x00001000)
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_MACHW_POS    12
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_PCIE_BIT    ((u32)0x00000800)
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_PCIE_POS    11
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_PCIEW_BIT    ((u32)0x00000400)
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_PCIEW_POS    10
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_E_2_W_BIT    ((u32)0x00000200)
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_E_2_W_POS    9
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_NATT_BIT    ((u32)0x00000100)
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_NATT_POS    8
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_USBW_BIT    ((u32)0x00000020)
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_USBW_POS    5
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_MACHW_BIT    ((u32)0x00000010)
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_MACHW_POS    4
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_PCIE_BIT    ((u32)0x00000008)
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_PCIE_POS    3
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_PCIEW_BIT    ((u32)0x00000004)
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_PCIEW_POS    2
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_E_2_W_BIT    ((u32)0x00000002)
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_E_2_W_POS    1
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_NATT_BIT    ((u32)0x00000001)
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_NATT_POS    0

#define MACSYS_GCU_AHB_2_AXI_CTRL_WRITE_ORDER_PRESERVE_E_2_W_RST    0x0
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_USBW_RST    0x0
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_MACHW_RST    0x1
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_PCIE_RST    0x1
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_PCIEW_RST    0x0
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_E_2_W_RST    0x0
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_NATT_RST    0x1
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_USBW_RST    0x0
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_MACHW_RST    0x1
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_PCIE_RST    0x1
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_PCIEW_RST    0x0
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_E_2_W_RST    0x0
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_NATT_RST    0x0

static inline void macsys_gcu_ahb_2_axi_ctrl_pack(struct cl_chip *chip, u8 write_order_preserve_e2_w, u8 prefetch_en_usbw, u8 prefetch_en_machw, u8 prefetch_en_pcie, u8 prefetch_en_pciew, u8 prefetch_en_e2_w, u8 prefetch_en_natt, u8 bufferable_usbw, u8 bufferable_machw, u8 bufferable_pcie, u8 bufferable_pciew, u8 bufferable_e2_w, u8 bufferable_natt)
{
	ASSERT_ERR_CHIP((((u32)write_order_preserve_e2_w << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)prefetch_en_usbw << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)prefetch_en_machw << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)prefetch_en_pcie << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)prefetch_en_pciew << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)prefetch_en_e2_w << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)prefetch_en_natt << 8) & ~((u32)0x00000100)) == 0);
	ASSERT_ERR_CHIP((((u32)bufferable_usbw << 5) & ~((u32)0x00000020)) == 0);
	ASSERT_ERR_CHIP((((u32)bufferable_machw << 4) & ~((u32)0x00000010)) == 0);
	ASSERT_ERR_CHIP((((u32)bufferable_pcie << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)bufferable_pciew << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)bufferable_e2_w << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)bufferable_natt << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, ((u32)write_order_preserve_e2_w << 16) | ((u32)prefetch_en_usbw << 13) | ((u32)prefetch_en_machw << 12) | ((u32)prefetch_en_pcie << 11) | ((u32)prefetch_en_pciew << 10) | ((u32)prefetch_en_e2_w << 9) | ((u32)prefetch_en_natt << 8) | ((u32)bufferable_usbw << 5) | ((u32)bufferable_machw << 4) | ((u32)bufferable_pcie << 3) | ((u32)bufferable_pciew << 2) | ((u32)bufferable_e2_w << 1) | ((u32)bufferable_natt << 0));
}

static inline void macsys_gcu_ahb_2_axi_ctrl_unpack(struct cl_chip *chip, u8 *write_order_preserve_e2_w, u8 *prefetch_en_usbw, u8 *prefetch_en_machw, u8 *prefetch_en_pcie, u8 *prefetch_en_pciew, u8 *prefetch_en_e2_w, u8 *prefetch_en_natt, u8 *bufferable_usbw, u8 *bufferable_machw, u8 *bufferable_pcie, u8 *bufferable_pciew, u8 *bufferable_e2_w, u8 *bufferable_natt)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	*write_order_preserve_e2_w = (local_val & ((u32)0x00010000)) >> 16;
	*prefetch_en_usbw = (local_val & ((u32)0x00002000)) >> 13;
	*prefetch_en_machw = (local_val & ((u32)0x00001000)) >> 12;
	*prefetch_en_pcie = (local_val & ((u32)0x00000800)) >> 11;
	*prefetch_en_pciew = (local_val & ((u32)0x00000400)) >> 10;
	*prefetch_en_e2_w = (local_val & ((u32)0x00000200)) >> 9;
	*prefetch_en_natt = (local_val & ((u32)0x00000100)) >> 8;
	*bufferable_usbw = (local_val & ((u32)0x00000020)) >> 5;
	*bufferable_machw = (local_val & ((u32)0x00000010)) >> 4;
	*bufferable_pcie = (local_val & ((u32)0x00000008)) >> 3;
	*bufferable_pciew = (local_val & ((u32)0x00000004)) >> 2;
	*bufferable_e2_w = (local_val & ((u32)0x00000002)) >> 1;
	*bufferable_natt = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_write_order_preserve_e_2_w_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_write_order_preserve_e_2_w_setf(struct cl_chip *chip, u8 writeorderpreservee2w)
{
	ASSERT_ERR_CHIP((((u32)writeorderpreservee2w << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00010000)) | ((u32)writeorderpreservee2w << 16));
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_prefetch_en_usbw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_prefetch_en_usbw_setf(struct cl_chip *chip, u8 prefetchenusbw)
{
	ASSERT_ERR_CHIP((((u32)prefetchenusbw << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00002000)) | ((u32)prefetchenusbw << 13));
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_prefetch_en_machw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_prefetch_en_machw_setf(struct cl_chip *chip, u8 prefetchenmachw)
{
	ASSERT_ERR_CHIP((((u32)prefetchenmachw << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00001000)) | ((u32)prefetchenmachw << 12));
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_prefetch_en_pcie_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_prefetch_en_pcie_setf(struct cl_chip *chip, u8 prefetchenpcie)
{
	ASSERT_ERR_CHIP((((u32)prefetchenpcie << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00000800)) | ((u32)prefetchenpcie << 11));
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_prefetch_en_pciew_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_prefetch_en_pciew_setf(struct cl_chip *chip, u8 prefetchenpciew)
{
	ASSERT_ERR_CHIP((((u32)prefetchenpciew << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00000400)) | ((u32)prefetchenpciew << 10));
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_prefetch_en_e_2_w_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_prefetch_en_e_2_w_setf(struct cl_chip *chip, u8 prefetchene2w)
{
	ASSERT_ERR_CHIP((((u32)prefetchene2w << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00000200)) | ((u32)prefetchene2w << 9));
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_prefetch_en_natt_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000100)) >> 8);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_prefetch_en_natt_setf(struct cl_chip *chip, u8 prefetchennatt)
{
	ASSERT_ERR_CHIP((((u32)prefetchennatt << 8) & ~((u32)0x00000100)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00000100)) | ((u32)prefetchennatt << 8));
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_bufferable_usbw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000020)) >> 5);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_bufferable_usbw_setf(struct cl_chip *chip, u8 bufferableusbw)
{
	ASSERT_ERR_CHIP((((u32)bufferableusbw << 5) & ~((u32)0x00000020)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00000020)) | ((u32)bufferableusbw << 5));
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_bufferable_machw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_bufferable_machw_setf(struct cl_chip *chip, u8 bufferablemachw)
{
	ASSERT_ERR_CHIP((((u32)bufferablemachw << 4) & ~((u32)0x00000010)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00000010)) | ((u32)bufferablemachw << 4));
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_bufferable_pcie_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_bufferable_pcie_setf(struct cl_chip *chip, u8 bufferablepcie)
{
	ASSERT_ERR_CHIP((((u32)bufferablepcie << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00000008)) | ((u32)bufferablepcie << 3));
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_bufferable_pciew_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_bufferable_pciew_setf(struct cl_chip *chip, u8 bufferablepciew)
{
	ASSERT_ERR_CHIP((((u32)bufferablepciew << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00000004)) | ((u32)bufferablepciew << 2));
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_bufferable_e_2_w_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_bufferable_e_2_w_setf(struct cl_chip *chip, u8 bufferablee2w)
{
	ASSERT_ERR_CHIP((((u32)bufferablee2w << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00000002)) | ((u32)bufferablee2w << 1));
}

static inline u8 macsys_gcu_ahb_2_axi_ctrl_bufferable_natt_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macsys_gcu_ahb_2_axi_ctrl_bufferable_natt_setf(struct cl_chip *chip, u8 bufferablenatt)
{
	ASSERT_ERR_CHIP((((u32)bufferablenatt << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((u32)0x00000001)) | ((u32)bufferablenatt << 0));
}

/**
 * @brief DPHY_MUX_CTRL register definition
 *  Controls the behavior of the DPHY MUX register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 MUX_CTRL                  0x40
 * </pre>
 */
#define MACSYS_GCU_DPHY_MUX_CTRL_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000104)
#define MACSYS_GCU_DPHY_MUX_CTRL_OFFSET      0x00000104
#define MACSYS_GCU_DPHY_MUX_CTRL_INDEX       0x00000041
#define MACSYS_GCU_DPHY_MUX_CTRL_RESET       0x00000040

static inline u32 macsys_gcu_dphy_mux_ctrl_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_DPHY_MUX_CTRL_ADDR);
}

static inline void macsys_gcu_dphy_mux_ctrl_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_DPHY_MUX_CTRL_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_DPHY_MUX_CTRL_MUX_CTRL_MASK    ((u32)0x000000FF)
#define MACSYS_GCU_DPHY_MUX_CTRL_MUX_CTRL_LSB    0
#define MACSYS_GCU_DPHY_MUX_CTRL_MUX_CTRL_WIDTH    ((u32)0x00000008)

#define MACSYS_GCU_DPHY_MUX_CTRL_MUX_CTRL_RST    0x40

static inline u8 macsys_gcu_dphy_mux_ctrl_mux_ctrl_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_DPHY_MUX_CTRL_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macsys_gcu_dphy_mux_ctrl_mux_ctrl_setf(struct cl_chip *chip, u8 muxctrl)
{
	ASSERT_ERR_CHIP((((u32)muxctrl << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_DPHY_MUX_CTRL_ADDR, (u32)muxctrl << 0);
}

/**
 * @brief UART_IF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:02 CTS_IF_MODE               0x0
 *    01:00 RTS_IF_MODE               0x0
 * </pre>
 */
#define MACSYS_GCU_UART_IF_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000108)
#define MACSYS_GCU_UART_IF_OFFSET      0x00000108
#define MACSYS_GCU_UART_IF_INDEX       0x00000042
#define MACSYS_GCU_UART_IF_RESET       0x00000000

static inline u32 macsys_gcu_uart_if_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_UART_IF_ADDR);
}

static inline void macsys_gcu_uart_if_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_UART_IF_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_UART_IF_CTS_IF_MODE_MASK    ((u32)0x0000000C)
#define MACSYS_GCU_UART_IF_CTS_IF_MODE_LSB    2
#define MACSYS_GCU_UART_IF_CTS_IF_MODE_WIDTH    ((u32)0x00000002)
#define MACSYS_GCU_UART_IF_RTS_IF_MODE_MASK    ((u32)0x00000003)
#define MACSYS_GCU_UART_IF_RTS_IF_MODE_LSB    0
#define MACSYS_GCU_UART_IF_RTS_IF_MODE_WIDTH    ((u32)0x00000002)

#define MACSYS_GCU_UART_IF_CTS_IF_MODE_RST    0x0
#define MACSYS_GCU_UART_IF_RTS_IF_MODE_RST    0x0

static inline void macsys_gcu_uart_if_pack(struct cl_chip *chip, u8 cts_if_mode, u8 rts_if_mode)
{
	ASSERT_ERR_CHIP((((u32)cts_if_mode << 2) & ~((u32)0x0000000C)) == 0);
	ASSERT_ERR_CHIP((((u32)rts_if_mode << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UART_IF_ADDR, ((u32)cts_if_mode << 2) | ((u32)rts_if_mode << 0));
}

static inline void macsys_gcu_uart_if_unpack(struct cl_chip *chip, u8 *cts_if_mode, u8 *rts_if_mode)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UART_IF_ADDR);

	*cts_if_mode = (local_val & ((u32)0x0000000C)) >> 2;
	*rts_if_mode = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u8 macsys_gcu_uart_if_cts_if_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UART_IF_ADDR);

	return (u8)((local_val & ((u32)0x0000000C)) >> 2);
}

static inline void macsys_gcu_uart_if_cts_if_mode_setf(struct cl_chip *chip, u8 ctsifmode)
{
	ASSERT_ERR_CHIP((((u32)ctsifmode << 2) & ~((u32)0x0000000C)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UART_IF_ADDR, (cl_reg_read(chip, MACSYS_GCU_UART_IF_ADDR) & ~((u32)0x0000000C)) | ((u32)ctsifmode << 2));
}

static inline u8 macsys_gcu_uart_if_rts_if_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UART_IF_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macsys_gcu_uart_if_rts_if_mode_setf(struct cl_chip *chip, u8 rtsifmode)
{
	ASSERT_ERR_CHIP((((u32)rtsifmode << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UART_IF_ADDR, (cl_reg_read(chip, MACSYS_GCU_UART_IF_ADDR) & ~((u32)0x00000003)) | ((u32)rtsifmode << 0));
}

/**
 * @brief MACSYS_LA_SAMP_MASK_LOW register definition
 *  MAC system logic analyzer mask for low signals register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mac_la_sampling_mask_low  0x0
 * </pre>
 */
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000114)
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_OFFSET      0x00000114
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_INDEX       0x00000045
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_RESET       0x00000000

static inline u32 macsys_gcu_macsys_la_samp_mask_low_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_ADDR);
}

static inline void macsys_gcu_macsys_la_samp_mask_low_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_MAC_LA_SAMPLING_MASK_LOW_MASK    ((u32)0xFFFFFFFF)
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_MAC_LA_SAMPLING_MASK_LOW_LSB    0
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_MAC_LA_SAMPLING_MASK_LOW_WIDTH    ((u32)0x00000020)

#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_MAC_LA_SAMPLING_MASK_LOW_RST    0x0

static inline u32 macsys_gcu_macsys_la_samp_mask_low_mac_la_sampling_mask_low_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macsys_gcu_macsys_la_samp_mask_low_mac_la_sampling_mask_low_setf(struct cl_chip *chip, u32 maclasamplingmasklow)
{
	ASSERT_ERR_CHIP((((u32)maclasamplingmasklow << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_ADDR, (u32)maclasamplingmasklow << 0);
}

/**
 * @brief MACSYS_LA_SAMP_MASK_MID register definition
 *  MAC system logic analyzer mask for mid signals register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mac_la_sampling_mask_mid  0x0
 * </pre>
 */
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000118)
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_OFFSET      0x00000118
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_INDEX       0x00000046
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_RESET       0x00000000

static inline u32 macsys_gcu_macsys_la_samp_mask_mid_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_ADDR);
}

static inline void macsys_gcu_macsys_la_samp_mask_mid_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_MAC_LA_SAMPLING_MASK_MID_MASK    ((u32)0xFFFFFFFF)
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_MAC_LA_SAMPLING_MASK_MID_LSB    0
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_MAC_LA_SAMPLING_MASK_MID_WIDTH    ((u32)0x00000020)

#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_MAC_LA_SAMPLING_MASK_MID_RST    0x0

static inline u32 macsys_gcu_macsys_la_samp_mask_mid_mac_la_sampling_mask_mid_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macsys_gcu_macsys_la_samp_mask_mid_mac_la_sampling_mask_mid_setf(struct cl_chip *chip, u32 maclasamplingmaskmid)
{
	ASSERT_ERR_CHIP((((u32)maclasamplingmaskmid << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_ADDR, (u32)maclasamplingmaskmid << 0);
}

/**
 * @brief MACSYS_LA_SAMP_MASK_HIGH register definition
 *  MAC system logic analyzer mask for high signals register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mac_la_sampling_mask_high 0x0
 * </pre>
 */
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x0000011C)
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_OFFSET      0x0000011C
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_INDEX       0x00000047
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_RESET       0x00000000

static inline u32 macsys_gcu_macsys_la_samp_mask_high_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_ADDR);
}

static inline void macsys_gcu_macsys_la_samp_mask_high_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_MAC_LA_SAMPLING_MASK_HIGH_MASK    ((u32)0xFFFFFFFF)
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_MAC_LA_SAMPLING_MASK_HIGH_LSB    0
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_MAC_LA_SAMPLING_MASK_HIGH_WIDTH    ((u32)0x00000020)

#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_MAC_LA_SAMPLING_MASK_HIGH_RST    0x0

static inline u32 macsys_gcu_macsys_la_samp_mask_high_mac_la_sampling_mask_high_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macsys_gcu_macsys_la_samp_mask_high_mac_la_sampling_mask_high_setf(struct cl_chip *chip, u32 maclasamplingmaskhigh)
{
	ASSERT_ERR_CHIP((((u32)maclasamplingmaskhigh << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_ADDR, (u32)maclasamplingmaskhigh << 0);
}

/**
 * @brief MACSYS_LA_TRIG_MASK_LOW register definition
 *  MAC system logic analyzer trigger mask for low register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mac_la_trigger_mask_low   0x0
 * </pre>
 */
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000120)
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_OFFSET      0x00000120
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_INDEX       0x00000048
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_RESET       0x00000000

static inline u32 macsys_gcu_macsys_la_trig_mask_low_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_ADDR);
}

static inline void macsys_gcu_macsys_la_trig_mask_low_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_MAC_LA_TRIGGER_MASK_LOW_MASK    ((u32)0xFFFFFFFF)
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_MAC_LA_TRIGGER_MASK_LOW_LSB    0
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_MAC_LA_TRIGGER_MASK_LOW_WIDTH    ((u32)0x00000020)

#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_MAC_LA_TRIGGER_MASK_LOW_RST    0x0

static inline u32 macsys_gcu_macsys_la_trig_mask_low_mac_la_trigger_mask_low_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macsys_gcu_macsys_la_trig_mask_low_mac_la_trigger_mask_low_setf(struct cl_chip *chip, u32 maclatriggermasklow)
{
	ASSERT_ERR_CHIP((((u32)maclatriggermasklow << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_ADDR, (u32)maclatriggermasklow << 0);
}

/**
 * @brief MACSYS_LA_TRIG_MASK_MID register definition
 *  MAC system logic analyzer trigger mask for mid register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mac_la_trigger_mask_mid   0x0
 * </pre>
 */
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000124)
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_OFFSET      0x00000124
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_INDEX       0x00000049
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_RESET       0x00000000

static inline u32 macsys_gcu_macsys_la_trig_mask_mid_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_ADDR);
}

static inline void macsys_gcu_macsys_la_trig_mask_mid_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_MAC_LA_TRIGGER_MASK_MID_MASK    ((u32)0xFFFFFFFF)
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_MAC_LA_TRIGGER_MASK_MID_LSB    0
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_MAC_LA_TRIGGER_MASK_MID_WIDTH    ((u32)0x00000020)

#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_MAC_LA_TRIGGER_MASK_MID_RST    0x0

static inline u32 macsys_gcu_macsys_la_trig_mask_mid_mac_la_trigger_mask_mid_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macsys_gcu_macsys_la_trig_mask_mid_mac_la_trigger_mask_mid_setf(struct cl_chip *chip, u32 maclatriggermaskmid)
{
	ASSERT_ERR_CHIP((((u32)maclatriggermaskmid << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_ADDR, (u32)maclatriggermaskmid << 0);
}

/**
 * @brief MACSYS_LA_TRIG_MASK_HIGH register definition
 *  MAC system logic analyzer trigger mask for high register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mac_la_trigger_mask_high  0x0
 * </pre>
 */
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000128)
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_OFFSET      0x00000128
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_INDEX       0x0000004A
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_RESET       0x00000000

static inline u32 macsys_gcu_macsys_la_trig_mask_high_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_ADDR);
}

static inline void macsys_gcu_macsys_la_trig_mask_high_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_MAC_LA_TRIGGER_MASK_HIGH_MASK    ((u32)0xFFFFFFFF)
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_MAC_LA_TRIGGER_MASK_HIGH_LSB    0
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_MAC_LA_TRIGGER_MASK_HIGH_WIDTH    ((u32)0x00000020)

#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_MAC_LA_TRIGGER_MASK_HIGH_RST    0x0

static inline u32 macsys_gcu_macsys_la_trig_mask_high_mac_la_trigger_mask_high_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macsys_gcu_macsys_la_trig_mask_high_mac_la_trigger_mask_high_setf(struct cl_chip *chip, u32 maclatriggermaskhigh)
{
	ASSERT_ERR_CHIP((((u32)maclatriggermaskhigh << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_ADDR, (u32)maclatriggermaskhigh << 0);
}

/**
 * @brief HOST_IF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    USB_SPEED                 0
 *    00    HOST_INTERFACE            1
 * </pre>
 */
#define MACSYS_GCU_HOST_IF_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000140)
#define MACSYS_GCU_HOST_IF_OFFSET      0x00000140
#define MACSYS_GCU_HOST_IF_INDEX       0x00000050
#define MACSYS_GCU_HOST_IF_RESET       0x00000001

static inline u32 macsys_gcu_host_if_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_HOST_IF_ADDR);
}

static inline void macsys_gcu_host_if_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_HOST_IF_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_HOST_IF_USB_SPEED_BIT    ((u32)0x00000002)
#define MACSYS_GCU_HOST_IF_USB_SPEED_POS    1
#define MACSYS_GCU_HOST_IF_HOST_INTERFACE_BIT    ((u32)0x00000001)
#define MACSYS_GCU_HOST_IF_HOST_INTERFACE_POS    0

#define MACSYS_GCU_HOST_IF_USB_SPEED_RST    0x0
#define MACSYS_GCU_HOST_IF_HOST_INTERFACE_RST    0x1

static inline void macsys_gcu_host_if_pack(struct cl_chip *chip, u8 usb_speed, u8 host_interface)
{
	ASSERT_ERR_CHIP((((u32)usb_speed << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)host_interface << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_HOST_IF_ADDR, ((u32)usb_speed << 1) | ((u32)host_interface << 0));
}

static inline void macsys_gcu_host_if_unpack(struct cl_chip *chip, u8 *usb_speed, u8 *host_interface)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_HOST_IF_ADDR);

	*usb_speed = (local_val & ((u32)0x00000002)) >> 1;
	*host_interface = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macsys_gcu_host_if_usb_speed_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_HOST_IF_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void macsys_gcu_host_if_usb_speed_setf(struct cl_chip *chip, u8 usbspeed)
{
	ASSERT_ERR_CHIP((((u32)usbspeed << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MACSYS_GCU_HOST_IF_ADDR, (cl_reg_read(chip, MACSYS_GCU_HOST_IF_ADDR) & ~((u32)0x00000002)) | ((u32)usbspeed << 1));
}

static inline u8 macsys_gcu_host_if_host_interface_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_HOST_IF_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macsys_gcu_host_if_host_interface_setf(struct cl_chip *chip, u8 hostinterface)
{
	ASSERT_ERR_CHIP((((u32)hostinterface << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_HOST_IF_ADDR, (cl_reg_read(chip, MACSYS_GCU_HOST_IF_ADDR) & ~((u32)0x00000001)) | ((u32)hostinterface << 0));
}

/**
 * @brief UMAC_CONTROL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    UMAC_BOOT_SRC             0
 * </pre>
 */
#define MACSYS_GCU_UMAC_CONTROL_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000144)
#define MACSYS_GCU_UMAC_CONTROL_OFFSET      0x00000144
#define MACSYS_GCU_UMAC_CONTROL_INDEX       0x00000051
#define MACSYS_GCU_UMAC_CONTROL_RESET       0x00000000

static inline u32 macsys_gcu_umac_control_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_UMAC_CONTROL_ADDR);
}

static inline void macsys_gcu_umac_control_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_UMAC_CONTROL_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_UMAC_CONTROL_UMAC_BOOT_SRC_BIT    ((u32)0x00000001)
#define MACSYS_GCU_UMAC_CONTROL_UMAC_BOOT_SRC_POS    0

#define MACSYS_GCU_UMAC_CONTROL_UMAC_BOOT_SRC_RST    0x0

static inline u8 macsys_gcu_umac_control_umac_boot_src_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_CONTROL_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macsys_gcu_umac_control_umac_boot_src_setf(struct cl_chip *chip, u8 umacbootsrc)
{
	ASSERT_ERR_CHIP((((u32)umacbootsrc << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_CONTROL_ADDR, (u32)umacbootsrc << 0);
}

/**
 * @brief SMAC_CONTROL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    SMAC_BOOT_SRC             1
 * </pre>
 */
#define MACSYS_GCU_SMAC_CONTROL_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000148)
#define MACSYS_GCU_SMAC_CONTROL_OFFSET      0x00000148
#define MACSYS_GCU_SMAC_CONTROL_INDEX       0x00000052
#define MACSYS_GCU_SMAC_CONTROL_RESET       0x00000001

static inline u32 macsys_gcu_smac_control_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_SMAC_CONTROL_ADDR);
}

static inline void macsys_gcu_smac_control_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_SMAC_CONTROL_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_SMAC_CONTROL_SMAC_BOOT_SRC_BIT    ((u32)0x00000001)
#define MACSYS_GCU_SMAC_CONTROL_SMAC_BOOT_SRC_POS    0

#define MACSYS_GCU_SMAC_CONTROL_SMAC_BOOT_SRC_RST    0x1

static inline u8 macsys_gcu_smac_control_smac_boot_src_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_CONTROL_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macsys_gcu_smac_control_smac_boot_src_setf(struct cl_chip *chip, u8 smacbootsrc)
{
	ASSERT_ERR_CHIP((((u32)smacbootsrc << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_CONTROL_ADDR, (u32)smacbootsrc << 0);
}

/**
 * @brief USB_CAPABILITIES register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    SS_LPM_CAPABILITY         1
 *    00    HS_LPM_CAPABILITY         1
 * </pre>
 */
#define MACSYS_GCU_USB_CAPABILITIES_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x0000014C)
#define MACSYS_GCU_USB_CAPABILITIES_OFFSET      0x0000014C
#define MACSYS_GCU_USB_CAPABILITIES_INDEX       0x00000053
#define MACSYS_GCU_USB_CAPABILITIES_RESET       0x00000003

static inline u32 macsys_gcu_usb_capabilities_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_USB_CAPABILITIES_ADDR);
}

static inline void macsys_gcu_usb_capabilities_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_USB_CAPABILITIES_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_USB_CAPABILITIES_SS_LPM_CAPABILITY_BIT    ((u32)0x00000002)
#define MACSYS_GCU_USB_CAPABILITIES_SS_LPM_CAPABILITY_POS    1
#define MACSYS_GCU_USB_CAPABILITIES_HS_LPM_CAPABILITY_BIT    ((u32)0x00000001)
#define MACSYS_GCU_USB_CAPABILITIES_HS_LPM_CAPABILITY_POS    0

#define MACSYS_GCU_USB_CAPABILITIES_SS_LPM_CAPABILITY_RST    0x1
#define MACSYS_GCU_USB_CAPABILITIES_HS_LPM_CAPABILITY_RST    0x1

static inline void macsys_gcu_usb_capabilities_pack(struct cl_chip *chip, u8 ss_lpm_capability, u8 hs_lpm_capability)
{
	ASSERT_ERR_CHIP((((u32)ss_lpm_capability << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)hs_lpm_capability << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_CAPABILITIES_ADDR, ((u32)ss_lpm_capability << 1) | ((u32)hs_lpm_capability << 0));
}

static inline void macsys_gcu_usb_capabilities_unpack(struct cl_chip *chip, u8 *ss_lpm_capability, u8 *hs_lpm_capability)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_CAPABILITIES_ADDR);

	*ss_lpm_capability = (local_val & ((u32)0x00000002)) >> 1;
	*hs_lpm_capability = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macsys_gcu_usb_capabilities_ss_lpm_capability_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_CAPABILITIES_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void macsys_gcu_usb_capabilities_ss_lpm_capability_setf(struct cl_chip *chip, u8 sslpmcapability)
{
	ASSERT_ERR_CHIP((((u32)sslpmcapability << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_CAPABILITIES_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_CAPABILITIES_ADDR) & ~((u32)0x00000002)) | ((u32)sslpmcapability << 1));
}

static inline u8 macsys_gcu_usb_capabilities_hs_lpm_capability_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_CAPABILITIES_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macsys_gcu_usb_capabilities_hs_lpm_capability_setf(struct cl_chip *chip, u8 hslpmcapability)
{
	ASSERT_ERR_CHIP((((u32)hslpmcapability << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_CAPABILITIES_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_CAPABILITIES_ADDR) & ~((u32)0x00000001)) | ((u32)hslpmcapability << 0));
}

/**
 * @brief SMAC_INT_MAP_0 register definition
 *  SMAC interrupt map 0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 smac_int7_sel             0x1f
 *    24:20 smac_int6_sel             0x1f
 *    19:15 smac_int5_sel             0x1f
 *    14:10 smac_int4_sel             0x1f
 *    09:05 smac_int3_sel             0x1f
 *    04:00 smac_int2_sel             0x1f
 * </pre>
 */
#define MACSYS_GCU_SMAC_INT_MAP_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x0000016C)
#define MACSYS_GCU_SMAC_INT_MAP_0_OFFSET      0x0000016C
#define MACSYS_GCU_SMAC_INT_MAP_0_INDEX       0x0000005B
#define MACSYS_GCU_SMAC_INT_MAP_0_RESET       0x3FFFFFFF

static inline u32 macsys_gcu_smac_int_map_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR);
}

static inline void macsys_gcu_smac_int_map_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_7_SEL_MASK    ((u32)0x3E000000)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_7_SEL_LSB    25
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_7_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_6_SEL_MASK    ((u32)0x01F00000)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_6_SEL_LSB    20
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_6_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_5_SEL_MASK    ((u32)0x000F8000)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_5_SEL_LSB    15
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_5_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_4_SEL_MASK    ((u32)0x00007C00)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_4_SEL_LSB    10
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_4_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_3_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_3_SEL_LSB    5
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_3_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_2_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_2_SEL_LSB    0
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_2_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_7_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_6_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_5_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_4_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_3_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_2_SEL_RST    0x1f

static inline void macsys_gcu_smac_int_map_0_pack(struct cl_chip *chip, u8 smac_int7_sel, u8 smac_int6_sel, u8 smac_int5_sel, u8 smac_int4_sel, u8 smac_int3_sel, u8 smac_int2_sel)
{
	ASSERT_ERR_CHIP((((u32)smac_int7_sel << 25) & ~((u32)0x3E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int6_sel << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int5_sel << 15) & ~((u32)0x000F8000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int4_sel << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int3_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int2_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR, ((u32)smac_int7_sel << 25) | ((u32)smac_int6_sel << 20) | ((u32)smac_int5_sel << 15) | ((u32)smac_int4_sel << 10) | ((u32)smac_int3_sel << 5) | ((u32)smac_int2_sel << 0));
}

static inline void macsys_gcu_smac_int_map_0_unpack(struct cl_chip *chip, u8 *smac_int7_sel, u8 *smac_int6_sel, u8 *smac_int5_sel, u8 *smac_int4_sel, u8 *smac_int3_sel, u8 *smac_int2_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR);

	*smac_int7_sel = (local_val & ((u32)0x3E000000)) >> 25;
	*smac_int6_sel = (local_val & ((u32)0x01F00000)) >> 20;
	*smac_int5_sel = (local_val & ((u32)0x000F8000)) >> 15;
	*smac_int4_sel = (local_val & ((u32)0x00007C00)) >> 10;
	*smac_int3_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*smac_int2_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_smac_int_map_0_smac_int_7_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x3E000000)) >> 25);
}

static inline void macsys_gcu_smac_int_map_0_smac_int_7_sel_setf(struct cl_chip *chip, u8 smacint7sel)
{
	ASSERT_ERR_CHIP((((u32)smacint7sel << 25) & ~((u32)0x3E000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR) & ~((u32)0x3E000000)) | ((u32)smacint7sel << 25));
}

static inline u8 macsys_gcu_smac_int_map_0_smac_int_6_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macsys_gcu_smac_int_map_0_smac_int_6_sel_setf(struct cl_chip *chip, u8 smacint6sel)
{
	ASSERT_ERR_CHIP((((u32)smacint6sel << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR) & ~((u32)0x01F00000)) | ((u32)smacint6sel << 20));
}

static inline u8 macsys_gcu_smac_int_map_0_smac_int_5_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x000F8000)) >> 15);
}

static inline void macsys_gcu_smac_int_map_0_smac_int_5_sel_setf(struct cl_chip *chip, u8 smacint5sel)
{
	ASSERT_ERR_CHIP((((u32)smacint5sel << 15) & ~((u32)0x000F8000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR) & ~((u32)0x000F8000)) | ((u32)smacint5sel << 15));
}

static inline u8 macsys_gcu_smac_int_map_0_smac_int_4_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macsys_gcu_smac_int_map_0_smac_int_4_sel_setf(struct cl_chip *chip, u8 smacint4sel)
{
	ASSERT_ERR_CHIP((((u32)smacint4sel << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR) & ~((u32)0x00007C00)) | ((u32)smacint4sel << 10));
}

static inline u8 macsys_gcu_smac_int_map_0_smac_int_3_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_smac_int_map_0_smac_int_3_sel_setf(struct cl_chip *chip, u8 smacint3sel)
{
	ASSERT_ERR_CHIP((((u32)smacint3sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR) & ~((u32)0x000003E0)) | ((u32)smacint3sel << 5));
}

static inline u8 macsys_gcu_smac_int_map_0_smac_int_2_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_smac_int_map_0_smac_int_2_sel_setf(struct cl_chip *chip, u8 smacint2sel)
{
	ASSERT_ERR_CHIP((((u32)smacint2sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_0_ADDR) & ~((u32)0x0000001F)) | ((u32)smacint2sel << 0));
}

/**
 * @brief SMAC_INT_MAP_1 register definition
 *  SMAC interrupt map 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 smac_int13_sel            0x1f
 *    24:20 smac_int12_sel            0x1f
 *    19:15 smac_int11_sel            0x1f
 *    14:10 smac_int10_sel            0x1f
 *    09:05 smac_int9_sel             0x1f
 *    04:00 smac_int8_sel             0x1f
 * </pre>
 */
#define MACSYS_GCU_SMAC_INT_MAP_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000170)
#define MACSYS_GCU_SMAC_INT_MAP_1_OFFSET      0x00000170
#define MACSYS_GCU_SMAC_INT_MAP_1_INDEX       0x0000005C
#define MACSYS_GCU_SMAC_INT_MAP_1_RESET       0x3FFFFFFF

static inline u32 macsys_gcu_smac_int_map_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR);
}

static inline void macsys_gcu_smac_int_map_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_13_SEL_MASK    ((u32)0x3E000000)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_13_SEL_LSB    25
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_13_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_12_SEL_MASK    ((u32)0x01F00000)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_12_SEL_LSB    20
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_12_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_11_SEL_MASK    ((u32)0x000F8000)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_11_SEL_LSB    15
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_11_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_10_SEL_MASK    ((u32)0x00007C00)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_10_SEL_LSB    10
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_10_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_9_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_9_SEL_LSB    5
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_9_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_8_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_8_SEL_LSB    0
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_8_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_13_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_12_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_11_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_10_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_9_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_8_SEL_RST    0x1f

static inline void macsys_gcu_smac_int_map_1_pack(struct cl_chip *chip, u8 smac_int13_sel, u8 smac_int12_sel, u8 smac_int11_sel, u8 smac_int10_sel, u8 smac_int9_sel, u8 smac_int8_sel)
{
	ASSERT_ERR_CHIP((((u32)smac_int13_sel << 25) & ~((u32)0x3E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int12_sel << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int11_sel << 15) & ~((u32)0x000F8000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int10_sel << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int9_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int8_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR, ((u32)smac_int13_sel << 25) | ((u32)smac_int12_sel << 20) | ((u32)smac_int11_sel << 15) | ((u32)smac_int10_sel << 10) | ((u32)smac_int9_sel << 5) | ((u32)smac_int8_sel << 0));
}

static inline void macsys_gcu_smac_int_map_1_unpack(struct cl_chip *chip, u8 *smac_int13_sel, u8 *smac_int12_sel, u8 *smac_int11_sel, u8 *smac_int10_sel, u8 *smac_int9_sel, u8 *smac_int8_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR);

	*smac_int13_sel = (local_val & ((u32)0x3E000000)) >> 25;
	*smac_int12_sel = (local_val & ((u32)0x01F00000)) >> 20;
	*smac_int11_sel = (local_val & ((u32)0x000F8000)) >> 15;
	*smac_int10_sel = (local_val & ((u32)0x00007C00)) >> 10;
	*smac_int9_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*smac_int8_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_smac_int_map_1_smac_int_13_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x3E000000)) >> 25);
}

static inline void macsys_gcu_smac_int_map_1_smac_int_13_sel_setf(struct cl_chip *chip, u8 smacint13sel)
{
	ASSERT_ERR_CHIP((((u32)smacint13sel << 25) & ~((u32)0x3E000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR) & ~((u32)0x3E000000)) | ((u32)smacint13sel << 25));
}

static inline u8 macsys_gcu_smac_int_map_1_smac_int_12_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macsys_gcu_smac_int_map_1_smac_int_12_sel_setf(struct cl_chip *chip, u8 smacint12sel)
{
	ASSERT_ERR_CHIP((((u32)smacint12sel << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR) & ~((u32)0x01F00000)) | ((u32)smacint12sel << 20));
}

static inline u8 macsys_gcu_smac_int_map_1_smac_int_11_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x000F8000)) >> 15);
}

static inline void macsys_gcu_smac_int_map_1_smac_int_11_sel_setf(struct cl_chip *chip, u8 smacint11sel)
{
	ASSERT_ERR_CHIP((((u32)smacint11sel << 15) & ~((u32)0x000F8000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR) & ~((u32)0x000F8000)) | ((u32)smacint11sel << 15));
}

static inline u8 macsys_gcu_smac_int_map_1_smac_int_10_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macsys_gcu_smac_int_map_1_smac_int_10_sel_setf(struct cl_chip *chip, u8 smacint10sel)
{
	ASSERT_ERR_CHIP((((u32)smacint10sel << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR) & ~((u32)0x00007C00)) | ((u32)smacint10sel << 10));
}

static inline u8 macsys_gcu_smac_int_map_1_smac_int_9_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_smac_int_map_1_smac_int_9_sel_setf(struct cl_chip *chip, u8 smacint9sel)
{
	ASSERT_ERR_CHIP((((u32)smacint9sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR) & ~((u32)0x000003E0)) | ((u32)smacint9sel << 5));
}

static inline u8 macsys_gcu_smac_int_map_1_smac_int_8_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_smac_int_map_1_smac_int_8_sel_setf(struct cl_chip *chip, u8 smacint8sel)
{
	ASSERT_ERR_CHIP((((u32)smacint8sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_1_ADDR) & ~((u32)0x0000001F)) | ((u32)smacint8sel << 0));
}

/**
 * @brief SMAC_INT_MAP_2 register definition
 *  SMAC interrupt map 2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 smac_int19_sel            0x1f
 *    24:20 smac_int18_sel            0x1f
 *    19:15 smac_int17_sel            0x1f
 *    14:10 smac_int16_sel            0x1f
 *    09:05 smac_int15_sel            0x1f
 *    04:00 smac_int14_sel            0x1f
 * </pre>
 */
#define MACSYS_GCU_SMAC_INT_MAP_2_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000174)
#define MACSYS_GCU_SMAC_INT_MAP_2_OFFSET      0x00000174
#define MACSYS_GCU_SMAC_INT_MAP_2_INDEX       0x0000005D
#define MACSYS_GCU_SMAC_INT_MAP_2_RESET       0x3FFFFFFF

static inline u32 macsys_gcu_smac_int_map_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR);
}

static inline void macsys_gcu_smac_int_map_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_19_SEL_MASK    ((u32)0x3E000000)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_19_SEL_LSB    25
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_19_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_18_SEL_MASK    ((u32)0x01F00000)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_18_SEL_LSB    20
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_18_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_17_SEL_MASK    ((u32)0x000F8000)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_17_SEL_LSB    15
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_17_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_16_SEL_MASK    ((u32)0x00007C00)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_16_SEL_LSB    10
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_16_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_15_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_15_SEL_LSB    5
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_15_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_14_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_14_SEL_LSB    0
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_14_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_19_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_18_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_17_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_16_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_15_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_14_SEL_RST    0x1f

static inline void macsys_gcu_smac_int_map_2_pack(struct cl_chip *chip, u8 smac_int19_sel, u8 smac_int18_sel, u8 smac_int17_sel, u8 smac_int16_sel, u8 smac_int15_sel, u8 smac_int14_sel)
{
	ASSERT_ERR_CHIP((((u32)smac_int19_sel << 25) & ~((u32)0x3E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int18_sel << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int17_sel << 15) & ~((u32)0x000F8000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int16_sel << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int15_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int14_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR, ((u32)smac_int19_sel << 25) | ((u32)smac_int18_sel << 20) | ((u32)smac_int17_sel << 15) | ((u32)smac_int16_sel << 10) | ((u32)smac_int15_sel << 5) | ((u32)smac_int14_sel << 0));
}

static inline void macsys_gcu_smac_int_map_2_unpack(struct cl_chip *chip, u8 *smac_int19_sel, u8 *smac_int18_sel, u8 *smac_int17_sel, u8 *smac_int16_sel, u8 *smac_int15_sel, u8 *smac_int14_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR);

	*smac_int19_sel = (local_val & ((u32)0x3E000000)) >> 25;
	*smac_int18_sel = (local_val & ((u32)0x01F00000)) >> 20;
	*smac_int17_sel = (local_val & ((u32)0x000F8000)) >> 15;
	*smac_int16_sel = (local_val & ((u32)0x00007C00)) >> 10;
	*smac_int15_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*smac_int14_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_smac_int_map_2_smac_int_19_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x3E000000)) >> 25);
}

static inline void macsys_gcu_smac_int_map_2_smac_int_19_sel_setf(struct cl_chip *chip, u8 smacint19sel)
{
	ASSERT_ERR_CHIP((((u32)smacint19sel << 25) & ~((u32)0x3E000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR) & ~((u32)0x3E000000)) | ((u32)smacint19sel << 25));
}

static inline u8 macsys_gcu_smac_int_map_2_smac_int_18_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macsys_gcu_smac_int_map_2_smac_int_18_sel_setf(struct cl_chip *chip, u8 smacint18sel)
{
	ASSERT_ERR_CHIP((((u32)smacint18sel << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR) & ~((u32)0x01F00000)) | ((u32)smacint18sel << 20));
}

static inline u8 macsys_gcu_smac_int_map_2_smac_int_17_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x000F8000)) >> 15);
}

static inline void macsys_gcu_smac_int_map_2_smac_int_17_sel_setf(struct cl_chip *chip, u8 smacint17sel)
{
	ASSERT_ERR_CHIP((((u32)smacint17sel << 15) & ~((u32)0x000F8000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR) & ~((u32)0x000F8000)) | ((u32)smacint17sel << 15));
}

static inline u8 macsys_gcu_smac_int_map_2_smac_int_16_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macsys_gcu_smac_int_map_2_smac_int_16_sel_setf(struct cl_chip *chip, u8 smacint16sel)
{
	ASSERT_ERR_CHIP((((u32)smacint16sel << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR) & ~((u32)0x00007C00)) | ((u32)smacint16sel << 10));
}

static inline u8 macsys_gcu_smac_int_map_2_smac_int_15_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_smac_int_map_2_smac_int_15_sel_setf(struct cl_chip *chip, u8 smacint15sel)
{
	ASSERT_ERR_CHIP((((u32)smacint15sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR) & ~((u32)0x000003E0)) | ((u32)smacint15sel << 5));
}

static inline u8 macsys_gcu_smac_int_map_2_smac_int_14_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_smac_int_map_2_smac_int_14_sel_setf(struct cl_chip *chip, u8 smacint14sel)
{
	ASSERT_ERR_CHIP((((u32)smacint14sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_2_ADDR) & ~((u32)0x0000001F)) | ((u32)smacint14sel << 0));
}

/**
 * @brief SMAC_INT_MAP_3 register definition
 *  SMAC interrupt map 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 smac_int28_sel            0x1f
 *    24:20 smac_int25_sel            0x1f
 *    19:15 smac_int24_sel            0x1f
 *    14:10 smac_int23_sel            0x1f
 *    09:05 smac_int22_sel            0x1f
 *    04:00 smac_int21_sel            0x1f
 * </pre>
 */
#define MACSYS_GCU_SMAC_INT_MAP_3_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000178)
#define MACSYS_GCU_SMAC_INT_MAP_3_OFFSET      0x00000178
#define MACSYS_GCU_SMAC_INT_MAP_3_INDEX       0x0000005E
#define MACSYS_GCU_SMAC_INT_MAP_3_RESET       0x3FFFFFFF

static inline u32 macsys_gcu_smac_int_map_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR);
}

static inline void macsys_gcu_smac_int_map_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_28_SEL_MASK    ((u32)0x3E000000)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_28_SEL_LSB    25
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_28_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_25_SEL_MASK    ((u32)0x01F00000)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_25_SEL_LSB    20
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_25_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_24_SEL_MASK    ((u32)0x000F8000)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_24_SEL_LSB    15
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_24_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_23_SEL_MASK    ((u32)0x00007C00)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_23_SEL_LSB    10
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_23_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_22_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_22_SEL_LSB    5
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_22_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_21_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_21_SEL_LSB    0
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_21_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_28_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_25_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_24_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_23_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_22_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_21_SEL_RST    0x1f

static inline void macsys_gcu_smac_int_map_3_pack(struct cl_chip *chip, u8 smac_int28_sel, u8 smac_int25_sel, u8 smac_int24_sel, u8 smac_int23_sel, u8 smac_int22_sel, u8 smac_int21_sel)
{
	ASSERT_ERR_CHIP((((u32)smac_int28_sel << 25) & ~((u32)0x3E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int25_sel << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int24_sel << 15) & ~((u32)0x000F8000)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int23_sel << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int22_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int21_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR, ((u32)smac_int28_sel << 25) | ((u32)smac_int25_sel << 20) | ((u32)smac_int24_sel << 15) | ((u32)smac_int23_sel << 10) | ((u32)smac_int22_sel << 5) | ((u32)smac_int21_sel << 0));
}

static inline void macsys_gcu_smac_int_map_3_unpack(struct cl_chip *chip, u8 *smac_int28_sel, u8 *smac_int25_sel, u8 *smac_int24_sel, u8 *smac_int23_sel, u8 *smac_int22_sel, u8 *smac_int21_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR);

	*smac_int28_sel = (local_val & ((u32)0x3E000000)) >> 25;
	*smac_int25_sel = (local_val & ((u32)0x01F00000)) >> 20;
	*smac_int24_sel = (local_val & ((u32)0x000F8000)) >> 15;
	*smac_int23_sel = (local_val & ((u32)0x00007C00)) >> 10;
	*smac_int22_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*smac_int21_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_smac_int_map_3_smac_int_28_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x3E000000)) >> 25);
}

static inline void macsys_gcu_smac_int_map_3_smac_int_28_sel_setf(struct cl_chip *chip, u8 smacint28sel)
{
	ASSERT_ERR_CHIP((((u32)smacint28sel << 25) & ~((u32)0x3E000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR) & ~((u32)0x3E000000)) | ((u32)smacint28sel << 25));
}

static inline u8 macsys_gcu_smac_int_map_3_smac_int_25_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macsys_gcu_smac_int_map_3_smac_int_25_sel_setf(struct cl_chip *chip, u8 smacint25sel)
{
	ASSERT_ERR_CHIP((((u32)smacint25sel << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR) & ~((u32)0x01F00000)) | ((u32)smacint25sel << 20));
}

static inline u8 macsys_gcu_smac_int_map_3_smac_int_24_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x000F8000)) >> 15);
}

static inline void macsys_gcu_smac_int_map_3_smac_int_24_sel_setf(struct cl_chip *chip, u8 smacint24sel)
{
	ASSERT_ERR_CHIP((((u32)smacint24sel << 15) & ~((u32)0x000F8000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR) & ~((u32)0x000F8000)) | ((u32)smacint24sel << 15));
}

static inline u8 macsys_gcu_smac_int_map_3_smac_int_23_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macsys_gcu_smac_int_map_3_smac_int_23_sel_setf(struct cl_chip *chip, u8 smacint23sel)
{
	ASSERT_ERR_CHIP((((u32)smacint23sel << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR) & ~((u32)0x00007C00)) | ((u32)smacint23sel << 10));
}

static inline u8 macsys_gcu_smac_int_map_3_smac_int_22_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_smac_int_map_3_smac_int_22_sel_setf(struct cl_chip *chip, u8 smacint22sel)
{
	ASSERT_ERR_CHIP((((u32)smacint22sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR) & ~((u32)0x000003E0)) | ((u32)smacint22sel << 5));
}

static inline u8 macsys_gcu_smac_int_map_3_smac_int_21_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_smac_int_map_3_smac_int_21_sel_setf(struct cl_chip *chip, u8 smacint21sel)
{
	ASSERT_ERR_CHIP((((u32)smacint21sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_3_ADDR) & ~((u32)0x0000001F)) | ((u32)smacint21sel << 0));
}

/**
 * @brief SMAC_INT_MAP_4 register definition
 *  SMAC interrupt map 4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:05 smac_int30_sel            0x1f
 *    04:00 smac_int29_sel            0x1f
 * </pre>
 */
#define MACSYS_GCU_SMAC_INT_MAP_4_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x0000017C)
#define MACSYS_GCU_SMAC_INT_MAP_4_OFFSET      0x0000017C
#define MACSYS_GCU_SMAC_INT_MAP_4_INDEX       0x0000005F
#define MACSYS_GCU_SMAC_INT_MAP_4_RESET       0x000003FF

static inline u32 macsys_gcu_smac_int_map_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_4_ADDR);
}

static inline void macsys_gcu_smac_int_map_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_4_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_30_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_30_SEL_LSB    5
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_30_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_29_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_29_SEL_LSB    0
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_29_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_30_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_29_SEL_RST    0x1f

static inline void macsys_gcu_smac_int_map_4_pack(struct cl_chip *chip, u8 smac_int30_sel, u8 smac_int29_sel)
{
	ASSERT_ERR_CHIP((((u32)smac_int30_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)smac_int29_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_4_ADDR, ((u32)smac_int30_sel << 5) | ((u32)smac_int29_sel << 0));
}

static inline void macsys_gcu_smac_int_map_4_unpack(struct cl_chip *chip, u8 *smac_int30_sel, u8 *smac_int29_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_4_ADDR);

	*smac_int30_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*smac_int29_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_smac_int_map_4_smac_int_30_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_4_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_smac_int_map_4_smac_int_30_sel_setf(struct cl_chip *chip, u8 smacint30sel)
{
	ASSERT_ERR_CHIP((((u32)smacint30sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_4_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_4_ADDR) & ~((u32)0x000003E0)) | ((u32)smacint30sel << 5));
}

static inline u8 macsys_gcu_smac_int_map_4_smac_int_29_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_4_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_smac_int_map_4_smac_int_29_sel_setf(struct cl_chip *chip, u8 smacint29sel)
{
	ASSERT_ERR_CHIP((((u32)smacint29sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_SMAC_INT_MAP_4_ADDR, (cl_reg_read(chip, MACSYS_GCU_SMAC_INT_MAP_4_ADDR) & ~((u32)0x0000001F)) | ((u32)smacint29sel << 0));
}

/**
 * @brief LMAC_INT_MAP_0 register definition
 *  LMAC interrupt map 0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 lmac_int7_sel             0x1f
 *    24:20 lmac_int6_sel             0x1f
 *    19:15 lmac_int5_sel             0x1f
 *    14:10 lmac_int4_sel             0x1f
 *    09:05 lmac_int3_sel             0x1f
 *    04:00 lmac_int2_sel             0x1f
 * </pre>
 */
#define MACSYS_GCU_LMAC_INT_MAP_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000180)
#define MACSYS_GCU_LMAC_INT_MAP_0_OFFSET      0x00000180
#define MACSYS_GCU_LMAC_INT_MAP_0_INDEX       0x00000060
#define MACSYS_GCU_LMAC_INT_MAP_0_RESET       0x7FFFFFFF

static inline u32 macsys_gcu_lmac_int_map_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR);
}

static inline void macsys_gcu_lmac_int_map_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_7_SEL_MASK    ((u32)0x3E000000)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_7_SEL_LSB    25
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_7_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_6_SEL_MASK    ((u32)0x01F00000)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_6_SEL_LSB    20
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_6_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_5_SEL_MASK    ((u32)0x000F8000)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_5_SEL_LSB    15
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_5_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_4_SEL_MASK    ((u32)0x00007C00)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_4_SEL_LSB    10
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_4_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_3_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_3_SEL_LSB    5
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_3_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_2_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_2_SEL_LSB    0
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_2_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_7_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_6_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_5_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_4_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_3_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_2_SEL_RST    0x1f

static inline void macsys_gcu_lmac_int_map_0_pack(struct cl_chip *chip, u8 lmac_int7_sel, u8 lmac_int6_sel, u8 lmac_int5_sel, u8 lmac_int4_sel, u8 lmac_int3_sel, u8 lmac_int2_sel)
{
	ASSERT_ERR_CHIP((((u32)lmac_int7_sel << 25) & ~((u32)0x3E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int6_sel << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int5_sel << 15) & ~((u32)0x000F8000)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int4_sel << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int3_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int2_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR, ((u32)lmac_int7_sel << 25) | ((u32)lmac_int6_sel << 20) | ((u32)lmac_int5_sel << 15) | ((u32)lmac_int4_sel << 10) | ((u32)lmac_int3_sel << 5) | ((u32)lmac_int2_sel << 0));
}

static inline void macsys_gcu_lmac_int_map_0_unpack(struct cl_chip *chip, u8 *lmac_int7_sel, u8 *lmac_int6_sel, u8 *lmac_int5_sel, u8 *lmac_int4_sel, u8 *lmac_int3_sel, u8 *lmac_int2_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR);

	*lmac_int7_sel = (local_val & ((u32)0x3E000000)) >> 25;
	*lmac_int6_sel = (local_val & ((u32)0x01F00000)) >> 20;
	*lmac_int5_sel = (local_val & ((u32)0x000F8000)) >> 15;
	*lmac_int4_sel = (local_val & ((u32)0x00007C00)) >> 10;
	*lmac_int3_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*lmac_int2_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_lmac_int_map_0_lmac_int_7_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x3E000000)) >> 25);
}

static inline void macsys_gcu_lmac_int_map_0_lmac_int_7_sel_setf(struct cl_chip *chip, u8 lmacint7sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint7sel << 25) & ~((u32)0x3E000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR) & ~((u32)0x3E000000)) | ((u32)lmacint7sel << 25));
}

static inline u8 macsys_gcu_lmac_int_map_0_lmac_int_6_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macsys_gcu_lmac_int_map_0_lmac_int_6_sel_setf(struct cl_chip *chip, u8 lmacint6sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint6sel << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR) & ~((u32)0x01F00000)) | ((u32)lmacint6sel << 20));
}

static inline u8 macsys_gcu_lmac_int_map_0_lmac_int_5_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x000F8000)) >> 15);
}

static inline void macsys_gcu_lmac_int_map_0_lmac_int_5_sel_setf(struct cl_chip *chip, u8 lmacint5sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint5sel << 15) & ~((u32)0x000F8000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR) & ~((u32)0x000F8000)) | ((u32)lmacint5sel << 15));
}

static inline u8 macsys_gcu_lmac_int_map_0_lmac_int_4_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macsys_gcu_lmac_int_map_0_lmac_int_4_sel_setf(struct cl_chip *chip, u8 lmacint4sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint4sel << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR) & ~((u32)0x00007C00)) | ((u32)lmacint4sel << 10));
}

static inline u8 macsys_gcu_lmac_int_map_0_lmac_int_3_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_lmac_int_map_0_lmac_int_3_sel_setf(struct cl_chip *chip, u8 lmacint3sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint3sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR) & ~((u32)0x000003E0)) | ((u32)lmacint3sel << 5));
}

static inline u8 macsys_gcu_lmac_int_map_0_lmac_int_2_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_lmac_int_map_0_lmac_int_2_sel_setf(struct cl_chip *chip, u8 lmacint2sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint2sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_0_ADDR) & ~((u32)0x0000001F)) | ((u32)lmacint2sel << 0));
}

/**
 * @brief LMAC_INT_MAP_1 register definition
 *  LMAC interrupt map 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 lmac_int13_sel            0x1f
 *    24:20 lmac_int12_sel            0x1f
 *    19:15 lmac_int11_sel            0x1f
 *    14:10 lmac_int10_sel            0x1f
 *    09:05 lmac_int9_sel             0x1f
 *    04:00 lmac_int8_sel             0x1f
 * </pre>
 */
#define MACSYS_GCU_LMAC_INT_MAP_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000184)
#define MACSYS_GCU_LMAC_INT_MAP_1_OFFSET      0x00000184
#define MACSYS_GCU_LMAC_INT_MAP_1_INDEX       0x00000061
#define MACSYS_GCU_LMAC_INT_MAP_1_RESET       0x7FFFFFFF

static inline u32 macsys_gcu_lmac_int_map_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR);
}

static inline void macsys_gcu_lmac_int_map_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_13_SEL_MASK    ((u32)0x3E000000)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_13_SEL_LSB    25
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_13_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_12_SEL_MASK    ((u32)0x01F00000)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_12_SEL_LSB    20
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_12_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_11_SEL_MASK    ((u32)0x000F8000)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_11_SEL_LSB    15
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_11_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_10_SEL_MASK    ((u32)0x00007C00)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_10_SEL_LSB    10
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_10_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_9_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_9_SEL_LSB    5
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_9_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_8_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_8_SEL_LSB    0
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_8_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_13_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_12_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_11_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_10_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_9_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_8_SEL_RST    0x1f

static inline void macsys_gcu_lmac_int_map_1_pack(struct cl_chip *chip, u8 lmac_int13_sel, u8 lmac_int12_sel, u8 lmac_int11_sel, u8 lmac_int10_sel, u8 lmac_int9_sel, u8 lmac_int8_sel)
{
	ASSERT_ERR_CHIP((((u32)lmac_int13_sel << 25) & ~((u32)0x3E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int12_sel << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int11_sel << 15) & ~((u32)0x000F8000)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int10_sel << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int9_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int8_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR, ((u32)lmac_int13_sel << 25) | ((u32)lmac_int12_sel << 20) | ((u32)lmac_int11_sel << 15) | ((u32)lmac_int10_sel << 10) | ((u32)lmac_int9_sel << 5) | ((u32)lmac_int8_sel << 0));
}

static inline void macsys_gcu_lmac_int_map_1_unpack(struct cl_chip *chip, u8 *lmac_int13_sel, u8 *lmac_int12_sel, u8 *lmac_int11_sel, u8 *lmac_int10_sel, u8 *lmac_int9_sel, u8 *lmac_int8_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR);

	*lmac_int13_sel = (local_val & ((u32)0x3E000000)) >> 25;
	*lmac_int12_sel = (local_val & ((u32)0x01F00000)) >> 20;
	*lmac_int11_sel = (local_val & ((u32)0x000F8000)) >> 15;
	*lmac_int10_sel = (local_val & ((u32)0x00007C00)) >> 10;
	*lmac_int9_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*lmac_int8_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_lmac_int_map_1_lmac_int_13_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x3E000000)) >> 25);
}

static inline void macsys_gcu_lmac_int_map_1_lmac_int_13_sel_setf(struct cl_chip *chip, u8 lmacint13sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint13sel << 25) & ~((u32)0x3E000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR) & ~((u32)0x3E000000)) | ((u32)lmacint13sel << 25));
}

static inline u8 macsys_gcu_lmac_int_map_1_lmac_int_12_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macsys_gcu_lmac_int_map_1_lmac_int_12_sel_setf(struct cl_chip *chip, u8 lmacint12sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint12sel << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR) & ~((u32)0x01F00000)) | ((u32)lmacint12sel << 20));
}

static inline u8 macsys_gcu_lmac_int_map_1_lmac_int_11_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x000F8000)) >> 15);
}

static inline void macsys_gcu_lmac_int_map_1_lmac_int_11_sel_setf(struct cl_chip *chip, u8 lmacint11sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint11sel << 15) & ~((u32)0x000F8000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR) & ~((u32)0x000F8000)) | ((u32)lmacint11sel << 15));
}

static inline u8 macsys_gcu_lmac_int_map_1_lmac_int_10_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macsys_gcu_lmac_int_map_1_lmac_int_10_sel_setf(struct cl_chip *chip, u8 lmacint10sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint10sel << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR) & ~((u32)0x00007C00)) | ((u32)lmacint10sel << 10));
}

static inline u8 macsys_gcu_lmac_int_map_1_lmac_int_9_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_lmac_int_map_1_lmac_int_9_sel_setf(struct cl_chip *chip, u8 lmacint9sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint9sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR) & ~((u32)0x000003E0)) | ((u32)lmacint9sel << 5));
}

static inline u8 macsys_gcu_lmac_int_map_1_lmac_int_8_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_lmac_int_map_1_lmac_int_8_sel_setf(struct cl_chip *chip, u8 lmacint8sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint8sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_1_ADDR) & ~((u32)0x0000001F)) | ((u32)lmacint8sel << 0));
}

/**
 * @brief LMAC_INT_MAP_2 register definition
 *  LMAC interrupt map 2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 lmac_int19_sel            0x1f
 *    24:20 lmac_int18_sel            0x1f
 *    19:15 lmac_int17_sel            0x1f
 *    14:10 lmac_int16_sel            0x1f
 *    09:05 lmac_int15_sel            0x1f
 *    04:00 lmac_int14_sel            0x1f
 * </pre>
 */
#define MACSYS_GCU_LMAC_INT_MAP_2_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000188)
#define MACSYS_GCU_LMAC_INT_MAP_2_OFFSET      0x00000188
#define MACSYS_GCU_LMAC_INT_MAP_2_INDEX       0x00000062
#define MACSYS_GCU_LMAC_INT_MAP_2_RESET       0x3FFFFFFF

static inline u32 macsys_gcu_lmac_int_map_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR);
}

static inline void macsys_gcu_lmac_int_map_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_19_SEL_MASK    ((u32)0x3E000000)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_19_SEL_LSB    25
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_19_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_18_SEL_MASK    ((u32)0x01F00000)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_18_SEL_LSB    20
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_18_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_17_SEL_MASK    ((u32)0x000F8000)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_17_SEL_LSB    15
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_17_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_16_SEL_MASK    ((u32)0x00007C00)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_16_SEL_LSB    10
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_16_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_15_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_15_SEL_LSB    5
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_15_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_14_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_14_SEL_LSB    0
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_14_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_19_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_18_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_17_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_16_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_15_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_14_SEL_RST    0x1f

static inline void macsys_gcu_lmac_int_map_2_pack(struct cl_chip *chip, u8 lmac_int19_sel, u8 lmac_int18_sel, u8 lmac_int17_sel, u8 lmac_int16_sel, u8 lmac_int15_sel, u8 lmac_int14_sel)
{
	ASSERT_ERR_CHIP((((u32)lmac_int19_sel << 25) & ~((u32)0x3E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int18_sel << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int17_sel << 15) & ~((u32)0x000F8000)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int16_sel << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int15_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int14_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR, ((u32)lmac_int19_sel << 25) | ((u32)lmac_int18_sel << 20) | ((u32)lmac_int17_sel << 15) | ((u32)lmac_int16_sel << 10) | ((u32)lmac_int15_sel << 5) | ((u32)lmac_int14_sel << 0));
}

static inline void macsys_gcu_lmac_int_map_2_unpack(struct cl_chip *chip, u8 *lmac_int19_sel, u8 *lmac_int18_sel, u8 *lmac_int17_sel, u8 *lmac_int16_sel, u8 *lmac_int15_sel, u8 *lmac_int14_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR);

	*lmac_int19_sel = (local_val & ((u32)0x3E000000)) >> 25;
	*lmac_int18_sel = (local_val & ((u32)0x01F00000)) >> 20;
	*lmac_int17_sel = (local_val & ((u32)0x000F8000)) >> 15;
	*lmac_int16_sel = (local_val & ((u32)0x00007C00)) >> 10;
	*lmac_int15_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*lmac_int14_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_lmac_int_map_2_lmac_int_19_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x3E000000)) >> 25);
}

static inline void macsys_gcu_lmac_int_map_2_lmac_int_19_sel_setf(struct cl_chip *chip, u8 lmacint19sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint19sel << 25) & ~((u32)0x3E000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR) & ~((u32)0x3E000000)) | ((u32)lmacint19sel << 25));
}

static inline u8 macsys_gcu_lmac_int_map_2_lmac_int_18_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macsys_gcu_lmac_int_map_2_lmac_int_18_sel_setf(struct cl_chip *chip, u8 lmacint18sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint18sel << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR) & ~((u32)0x01F00000)) | ((u32)lmacint18sel << 20));
}

static inline u8 macsys_gcu_lmac_int_map_2_lmac_int_17_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x000F8000)) >> 15);
}

static inline void macsys_gcu_lmac_int_map_2_lmac_int_17_sel_setf(struct cl_chip *chip, u8 lmacint17sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint17sel << 15) & ~((u32)0x000F8000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR) & ~((u32)0x000F8000)) | ((u32)lmacint17sel << 15));
}

static inline u8 macsys_gcu_lmac_int_map_2_lmac_int_16_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macsys_gcu_lmac_int_map_2_lmac_int_16_sel_setf(struct cl_chip *chip, u8 lmacint16sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint16sel << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR) & ~((u32)0x00007C00)) | ((u32)lmacint16sel << 10));
}

static inline u8 macsys_gcu_lmac_int_map_2_lmac_int_15_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_lmac_int_map_2_lmac_int_15_sel_setf(struct cl_chip *chip, u8 lmacint15sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint15sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR) & ~((u32)0x000003E0)) | ((u32)lmacint15sel << 5));
}

static inline u8 macsys_gcu_lmac_int_map_2_lmac_int_14_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_lmac_int_map_2_lmac_int_14_sel_setf(struct cl_chip *chip, u8 lmacint14sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint14sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_2_ADDR) & ~((u32)0x0000001F)) | ((u32)lmacint14sel << 0));
}

/**
 * @brief LMAC_INT_MAP_3 register definition
 *  LMAC interrupt map 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 lmac_int28_sel            0x1f
 *    24:20 lmac_int25_sel            0x1f
 *    19:15 lmac_int24_sel            0x1f
 *    14:10 lmac_int23_sel            0x1f
 *    09:05 lmac_int22_sel            0x1f
 *    04:00 lmac_int21_sel            0x1f
 * </pre>
 */
#define MACSYS_GCU_LMAC_INT_MAP_3_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x0000018C)
#define MACSYS_GCU_LMAC_INT_MAP_3_OFFSET      0x0000018C
#define MACSYS_GCU_LMAC_INT_MAP_3_INDEX       0x00000063
#define MACSYS_GCU_LMAC_INT_MAP_3_RESET       0x3FFFFFFF

static inline u32 macsys_gcu_lmac_int_map_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR);
}

static inline void macsys_gcu_lmac_int_map_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_28_SEL_MASK    ((u32)0x3E000000)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_28_SEL_LSB    25
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_28_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_25_SEL_MASK    ((u32)0x01F00000)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_25_SEL_LSB    20
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_25_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_24_SEL_MASK    ((u32)0x000F8000)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_24_SEL_LSB    15
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_24_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_23_SEL_MASK    ((u32)0x00007C00)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_23_SEL_LSB    10
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_23_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_22_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_22_SEL_LSB    5
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_22_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_21_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_21_SEL_LSB    0
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_21_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_28_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_25_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_24_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_23_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_22_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_21_SEL_RST    0x1f

static inline void macsys_gcu_lmac_int_map_3_pack(struct cl_chip *chip, u8 lmac_int28_sel, u8 lmac_int25_sel, u8 lmac_int24_sel, u8 lmac_int23_sel, u8 lmac_int22_sel, u8 lmac_int21_sel)
{
	ASSERT_ERR_CHIP((((u32)lmac_int28_sel << 25) & ~((u32)0x3E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int25_sel << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int24_sel << 15) & ~((u32)0x000F8000)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int23_sel << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int22_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int21_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR, ((u32)lmac_int28_sel << 25) | ((u32)lmac_int25_sel << 20) | ((u32)lmac_int24_sel << 15) | ((u32)lmac_int23_sel << 10) | ((u32)lmac_int22_sel << 5) | ((u32)lmac_int21_sel << 0));
}

static inline void macsys_gcu_lmac_int_map_3_unpack(struct cl_chip *chip, u8 *lmac_int28_sel, u8 *lmac_int25_sel, u8 *lmac_int24_sel, u8 *lmac_int23_sel, u8 *lmac_int22_sel, u8 *lmac_int21_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR);

	*lmac_int28_sel = (local_val & ((u32)0x3E000000)) >> 25;
	*lmac_int25_sel = (local_val & ((u32)0x01F00000)) >> 20;
	*lmac_int24_sel = (local_val & ((u32)0x000F8000)) >> 15;
	*lmac_int23_sel = (local_val & ((u32)0x00007C00)) >> 10;
	*lmac_int22_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*lmac_int21_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_lmac_int_map_3_lmac_int_28_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x3E000000)) >> 25);
}

static inline void macsys_gcu_lmac_int_map_3_lmac_int_28_sel_setf(struct cl_chip *chip, u8 lmacint28sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint28sel << 25) & ~((u32)0x3E000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR) & ~((u32)0x3E000000)) | ((u32)lmacint28sel << 25));
}

static inline u8 macsys_gcu_lmac_int_map_3_lmac_int_25_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macsys_gcu_lmac_int_map_3_lmac_int_25_sel_setf(struct cl_chip *chip, u8 lmacint25sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint25sel << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR) & ~((u32)0x01F00000)) | ((u32)lmacint25sel << 20));
}

static inline u8 macsys_gcu_lmac_int_map_3_lmac_int_24_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x000F8000)) >> 15);
}

static inline void macsys_gcu_lmac_int_map_3_lmac_int_24_sel_setf(struct cl_chip *chip, u8 lmacint24sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint24sel << 15) & ~((u32)0x000F8000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR) & ~((u32)0x000F8000)) | ((u32)lmacint24sel << 15));
}

static inline u8 macsys_gcu_lmac_int_map_3_lmac_int_23_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macsys_gcu_lmac_int_map_3_lmac_int_23_sel_setf(struct cl_chip *chip, u8 lmacint23sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint23sel << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR) & ~((u32)0x00007C00)) | ((u32)lmacint23sel << 10));
}

static inline u8 macsys_gcu_lmac_int_map_3_lmac_int_22_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_lmac_int_map_3_lmac_int_22_sel_setf(struct cl_chip *chip, u8 lmacint22sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint22sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR) & ~((u32)0x000003E0)) | ((u32)lmacint22sel << 5));
}

static inline u8 macsys_gcu_lmac_int_map_3_lmac_int_21_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_lmac_int_map_3_lmac_int_21_sel_setf(struct cl_chip *chip, u8 lmacint21sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint21sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_3_ADDR) & ~((u32)0x0000001F)) | ((u32)lmacint21sel << 0));
}

/**
 * @brief LMAC_INT_MAP_4 register definition
 *  LMAC interrupt map 4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:05 lmac_int30_sel            0x1f
 *    04:00 lmac_int29_sel            0x1f
 * </pre>
 */
#define MACSYS_GCU_LMAC_INT_MAP_4_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000190)
#define MACSYS_GCU_LMAC_INT_MAP_4_OFFSET      0x00000190
#define MACSYS_GCU_LMAC_INT_MAP_4_INDEX       0x00000064
#define MACSYS_GCU_LMAC_INT_MAP_4_RESET       0x000003FF

static inline u32 macsys_gcu_lmac_int_map_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_4_ADDR);
}

static inline void macsys_gcu_lmac_int_map_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_4_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_30_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_30_SEL_LSB    5
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_30_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_29_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_29_SEL_LSB    0
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_29_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_30_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_29_SEL_RST    0x1f

static inline void macsys_gcu_lmac_int_map_4_pack(struct cl_chip *chip, u8 lmac_int30_sel, u8 lmac_int29_sel)
{
	ASSERT_ERR_CHIP((((u32)lmac_int30_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)lmac_int29_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_4_ADDR, ((u32)lmac_int30_sel << 5) | ((u32)lmac_int29_sel << 0));
}

static inline void macsys_gcu_lmac_int_map_4_unpack(struct cl_chip *chip, u8 *lmac_int30_sel, u8 *lmac_int29_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_4_ADDR);

	*lmac_int30_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*lmac_int29_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_lmac_int_map_4_lmac_int_30_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_4_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_lmac_int_map_4_lmac_int_30_sel_setf(struct cl_chip *chip, u8 lmacint30sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint30sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_4_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_4_ADDR) & ~((u32)0x000003E0)) | ((u32)lmacint30sel << 5));
}

static inline u8 macsys_gcu_lmac_int_map_4_lmac_int_29_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_4_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_lmac_int_map_4_lmac_int_29_sel_setf(struct cl_chip *chip, u8 lmacint29sel)
{
	ASSERT_ERR_CHIP((((u32)lmacint29sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_LMAC_INT_MAP_4_ADDR, (cl_reg_read(chip, MACSYS_GCU_LMAC_INT_MAP_4_ADDR) & ~((u32)0x0000001F)) | ((u32)lmacint29sel << 0));
}

/**
 * @brief UMAC_INT_MAP_0 register definition
 *  UMAC interrupt map 0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 umac_int7_sel             0x1f
 *    24:20 umac_int6_sel             0x1f
 *    19:15 umac_int5_sel             0x1f
 *    14:10 umac_int4_sel             0x1f
 *    09:05 umac_int3_sel             0x1f
 *    04:00 umac_int2_sel             0x1f
 * </pre>
 */
#define MACSYS_GCU_UMAC_INT_MAP_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000194)
#define MACSYS_GCU_UMAC_INT_MAP_0_OFFSET      0x00000194
#define MACSYS_GCU_UMAC_INT_MAP_0_INDEX       0x00000065
#define MACSYS_GCU_UMAC_INT_MAP_0_RESET       0x3FFFFFFF

static inline u32 macsys_gcu_umac_int_map_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR);
}

static inline void macsys_gcu_umac_int_map_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_7_SEL_MASK    ((u32)0x3E000000)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_7_SEL_LSB    25
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_7_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_6_SEL_MASK    ((u32)0x01F00000)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_6_SEL_LSB    20
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_6_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_5_SEL_MASK    ((u32)0x000F8000)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_5_SEL_LSB    15
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_5_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_4_SEL_MASK    ((u32)0x00007C00)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_4_SEL_LSB    10
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_4_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_3_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_3_SEL_LSB    5
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_3_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_2_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_2_SEL_LSB    0
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_2_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_7_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_6_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_5_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_4_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_3_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_2_SEL_RST    0x1f

static inline void macsys_gcu_umac_int_map_0_pack(struct cl_chip *chip, u8 umac_int7_sel, u8 umac_int6_sel, u8 umac_int5_sel, u8 umac_int4_sel, u8 umac_int3_sel, u8 umac_int2_sel)
{
	ASSERT_ERR_CHIP((((u32)umac_int7_sel << 25) & ~((u32)0x3E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int6_sel << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int5_sel << 15) & ~((u32)0x000F8000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int4_sel << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int3_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int2_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR, ((u32)umac_int7_sel << 25) | ((u32)umac_int6_sel << 20) | ((u32)umac_int5_sel << 15) | ((u32)umac_int4_sel << 10) | ((u32)umac_int3_sel << 5) | ((u32)umac_int2_sel << 0));
}

static inline void macsys_gcu_umac_int_map_0_unpack(struct cl_chip *chip, u8 *umac_int7_sel, u8 *umac_int6_sel, u8 *umac_int5_sel, u8 *umac_int4_sel, u8 *umac_int3_sel, u8 *umac_int2_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR);

	*umac_int7_sel = (local_val & ((u32)0x3E000000)) >> 25;
	*umac_int6_sel = (local_val & ((u32)0x01F00000)) >> 20;
	*umac_int5_sel = (local_val & ((u32)0x000F8000)) >> 15;
	*umac_int4_sel = (local_val & ((u32)0x00007C00)) >> 10;
	*umac_int3_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*umac_int2_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_umac_int_map_0_umac_int_7_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x3E000000)) >> 25);
}

static inline void macsys_gcu_umac_int_map_0_umac_int_7_sel_setf(struct cl_chip *chip, u8 umacint7sel)
{
	ASSERT_ERR_CHIP((((u32)umacint7sel << 25) & ~((u32)0x3E000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR) & ~((u32)0x3E000000)) | ((u32)umacint7sel << 25));
}

static inline u8 macsys_gcu_umac_int_map_0_umac_int_6_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macsys_gcu_umac_int_map_0_umac_int_6_sel_setf(struct cl_chip *chip, u8 umacint6sel)
{
	ASSERT_ERR_CHIP((((u32)umacint6sel << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR) & ~((u32)0x01F00000)) | ((u32)umacint6sel << 20));
}

static inline u8 macsys_gcu_umac_int_map_0_umac_int_5_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x000F8000)) >> 15);
}

static inline void macsys_gcu_umac_int_map_0_umac_int_5_sel_setf(struct cl_chip *chip, u8 umacint5sel)
{
	ASSERT_ERR_CHIP((((u32)umacint5sel << 15) & ~((u32)0x000F8000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR) & ~((u32)0x000F8000)) | ((u32)umacint5sel << 15));
}

static inline u8 macsys_gcu_umac_int_map_0_umac_int_4_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macsys_gcu_umac_int_map_0_umac_int_4_sel_setf(struct cl_chip *chip, u8 umacint4sel)
{
	ASSERT_ERR_CHIP((((u32)umacint4sel << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR) & ~((u32)0x00007C00)) | ((u32)umacint4sel << 10));
}

static inline u8 macsys_gcu_umac_int_map_0_umac_int_3_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_umac_int_map_0_umac_int_3_sel_setf(struct cl_chip *chip, u8 umacint3sel)
{
	ASSERT_ERR_CHIP((((u32)umacint3sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR) & ~((u32)0x000003E0)) | ((u32)umacint3sel << 5));
}

static inline u8 macsys_gcu_umac_int_map_0_umac_int_2_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_umac_int_map_0_umac_int_2_sel_setf(struct cl_chip *chip, u8 umacint2sel)
{
	ASSERT_ERR_CHIP((((u32)umacint2sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_0_ADDR) & ~((u32)0x0000001F)) | ((u32)umacint2sel << 0));
}

/**
 * @brief UMAC_INT_MAP_1 register definition
 *  UMAC interrupt map 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 umac_int13_sel            0x1f
 *    24:20 umac_int12_sel            0x1f
 *    19:15 umac_int11_sel            0x1f
 *    14:10 umac_int10_sel            0x1f
 *    09:05 umac_int9_sel             0x1f
 *    04:00 umac_int8_sel             0x1f
 * </pre>
 */
#define MACSYS_GCU_UMAC_INT_MAP_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x00000198)
#define MACSYS_GCU_UMAC_INT_MAP_1_OFFSET      0x00000198
#define MACSYS_GCU_UMAC_INT_MAP_1_INDEX       0x00000066
#define MACSYS_GCU_UMAC_INT_MAP_1_RESET       0x3FFFFFFF

static inline u32 macsys_gcu_umac_int_map_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR);
}

static inline void macsys_gcu_umac_int_map_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_13_SEL_MASK    ((u32)0x3E000000)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_13_SEL_LSB    25
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_13_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_12_SEL_MASK    ((u32)0x01F00000)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_12_SEL_LSB    20
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_12_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_11_SEL_MASK    ((u32)0x000F8000)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_11_SEL_LSB    15
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_11_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_10_SEL_MASK    ((u32)0x00007C00)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_10_SEL_LSB    10
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_10_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_9_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_9_SEL_LSB    5
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_9_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_8_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_8_SEL_LSB    0
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_8_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_13_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_12_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_11_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_10_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_9_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_8_SEL_RST    0x1f

static inline void macsys_gcu_umac_int_map_1_pack(struct cl_chip *chip, u8 umac_int13_sel, u8 umac_int12_sel, u8 umac_int11_sel, u8 umac_int10_sel, u8 umac_int9_sel, u8 umac_int8_sel)
{
	ASSERT_ERR_CHIP((((u32)umac_int13_sel << 25) & ~((u32)0x3E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int12_sel << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int11_sel << 15) & ~((u32)0x000F8000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int10_sel << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int9_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int8_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR, ((u32)umac_int13_sel << 25) | ((u32)umac_int12_sel << 20) | ((u32)umac_int11_sel << 15) | ((u32)umac_int10_sel << 10) | ((u32)umac_int9_sel << 5) | ((u32)umac_int8_sel << 0));
}

static inline void macsys_gcu_umac_int_map_1_unpack(struct cl_chip *chip, u8 *umac_int13_sel, u8 *umac_int12_sel, u8 *umac_int11_sel, u8 *umac_int10_sel, u8 *umac_int9_sel, u8 *umac_int8_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR);

	*umac_int13_sel = (local_val & ((u32)0x3E000000)) >> 25;
	*umac_int12_sel = (local_val & ((u32)0x01F00000)) >> 20;
	*umac_int11_sel = (local_val & ((u32)0x000F8000)) >> 15;
	*umac_int10_sel = (local_val & ((u32)0x00007C00)) >> 10;
	*umac_int9_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*umac_int8_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_umac_int_map_1_umac_int_13_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x3E000000)) >> 25);
}

static inline void macsys_gcu_umac_int_map_1_umac_int_13_sel_setf(struct cl_chip *chip, u8 umacint13sel)
{
	ASSERT_ERR_CHIP((((u32)umacint13sel << 25) & ~((u32)0x3E000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR) & ~((u32)0x3E000000)) | ((u32)umacint13sel << 25));
}

static inline u8 macsys_gcu_umac_int_map_1_umac_int_12_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macsys_gcu_umac_int_map_1_umac_int_12_sel_setf(struct cl_chip *chip, u8 umacint12sel)
{
	ASSERT_ERR_CHIP((((u32)umacint12sel << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR) & ~((u32)0x01F00000)) | ((u32)umacint12sel << 20));
}

static inline u8 macsys_gcu_umac_int_map_1_umac_int_11_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x000F8000)) >> 15);
}

static inline void macsys_gcu_umac_int_map_1_umac_int_11_sel_setf(struct cl_chip *chip, u8 umacint11sel)
{
	ASSERT_ERR_CHIP((((u32)umacint11sel << 15) & ~((u32)0x000F8000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR) & ~((u32)0x000F8000)) | ((u32)umacint11sel << 15));
}

static inline u8 macsys_gcu_umac_int_map_1_umac_int_10_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macsys_gcu_umac_int_map_1_umac_int_10_sel_setf(struct cl_chip *chip, u8 umacint10sel)
{
	ASSERT_ERR_CHIP((((u32)umacint10sel << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR) & ~((u32)0x00007C00)) | ((u32)umacint10sel << 10));
}

static inline u8 macsys_gcu_umac_int_map_1_umac_int_9_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_umac_int_map_1_umac_int_9_sel_setf(struct cl_chip *chip, u8 umacint9sel)
{
	ASSERT_ERR_CHIP((((u32)umacint9sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR) & ~((u32)0x000003E0)) | ((u32)umacint9sel << 5));
}

static inline u8 macsys_gcu_umac_int_map_1_umac_int_8_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_umac_int_map_1_umac_int_8_sel_setf(struct cl_chip *chip, u8 umacint8sel)
{
	ASSERT_ERR_CHIP((((u32)umacint8sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_1_ADDR) & ~((u32)0x0000001F)) | ((u32)umacint8sel << 0));
}

/**
 * @brief UMAC_INT_MAP_2 register definition
 *  UMAC interrupt map 2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 umac_int19_sel            0x1f
 *    24:20 umac_int18_sel            0x1f
 *    19:15 umac_int17_sel            0x1f
 *    14:10 umac_int16_sel            0x1f
 *    09:05 umac_int15_sel            0x1f
 *    04:00 umac_int14_sel            0x1f
 * </pre>
 */
#define MACSYS_GCU_UMAC_INT_MAP_2_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x0000019C)
#define MACSYS_GCU_UMAC_INT_MAP_2_OFFSET      0x0000019C
#define MACSYS_GCU_UMAC_INT_MAP_2_INDEX       0x00000067
#define MACSYS_GCU_UMAC_INT_MAP_2_RESET       0x3FFFFFFF

static inline u32 macsys_gcu_umac_int_map_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR);
}

static inline void macsys_gcu_umac_int_map_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_19_SEL_MASK    ((u32)0x3E000000)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_19_SEL_LSB    25
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_19_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_18_SEL_MASK    ((u32)0x01F00000)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_18_SEL_LSB    20
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_18_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_17_SEL_MASK    ((u32)0x000F8000)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_17_SEL_LSB    15
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_17_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_16_SEL_MASK    ((u32)0x00007C00)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_16_SEL_LSB    10
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_16_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_15_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_15_SEL_LSB    5
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_15_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_14_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_14_SEL_LSB    0
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_14_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_19_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_18_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_17_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_16_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_15_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_14_SEL_RST    0x1f

static inline void macsys_gcu_umac_int_map_2_pack(struct cl_chip *chip, u8 umac_int19_sel, u8 umac_int18_sel, u8 umac_int17_sel, u8 umac_int16_sel, u8 umac_int15_sel, u8 umac_int14_sel)
{
	ASSERT_ERR_CHIP((((u32)umac_int19_sel << 25) & ~((u32)0x3E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int18_sel << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int17_sel << 15) & ~((u32)0x000F8000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int16_sel << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int15_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int14_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR, ((u32)umac_int19_sel << 25) | ((u32)umac_int18_sel << 20) | ((u32)umac_int17_sel << 15) | ((u32)umac_int16_sel << 10) | ((u32)umac_int15_sel << 5) | ((u32)umac_int14_sel << 0));
}

static inline void macsys_gcu_umac_int_map_2_unpack(struct cl_chip *chip, u8 *umac_int19_sel, u8 *umac_int18_sel, u8 *umac_int17_sel, u8 *umac_int16_sel, u8 *umac_int15_sel, u8 *umac_int14_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR);

	*umac_int19_sel = (local_val & ((u32)0x3E000000)) >> 25;
	*umac_int18_sel = (local_val & ((u32)0x01F00000)) >> 20;
	*umac_int17_sel = (local_val & ((u32)0x000F8000)) >> 15;
	*umac_int16_sel = (local_val & ((u32)0x00007C00)) >> 10;
	*umac_int15_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*umac_int14_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_umac_int_map_2_umac_int_19_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x3E000000)) >> 25);
}

static inline void macsys_gcu_umac_int_map_2_umac_int_19_sel_setf(struct cl_chip *chip, u8 umacint19sel)
{
	ASSERT_ERR_CHIP((((u32)umacint19sel << 25) & ~((u32)0x3E000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR) & ~((u32)0x3E000000)) | ((u32)umacint19sel << 25));
}

static inline u8 macsys_gcu_umac_int_map_2_umac_int_18_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macsys_gcu_umac_int_map_2_umac_int_18_sel_setf(struct cl_chip *chip, u8 umacint18sel)
{
	ASSERT_ERR_CHIP((((u32)umacint18sel << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR) & ~((u32)0x01F00000)) | ((u32)umacint18sel << 20));
}

static inline u8 macsys_gcu_umac_int_map_2_umac_int_17_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x000F8000)) >> 15);
}

static inline void macsys_gcu_umac_int_map_2_umac_int_17_sel_setf(struct cl_chip *chip, u8 umacint17sel)
{
	ASSERT_ERR_CHIP((((u32)umacint17sel << 15) & ~((u32)0x000F8000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR) & ~((u32)0x000F8000)) | ((u32)umacint17sel << 15));
}

static inline u8 macsys_gcu_umac_int_map_2_umac_int_16_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macsys_gcu_umac_int_map_2_umac_int_16_sel_setf(struct cl_chip *chip, u8 umacint16sel)
{
	ASSERT_ERR_CHIP((((u32)umacint16sel << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR) & ~((u32)0x00007C00)) | ((u32)umacint16sel << 10));
}

static inline u8 macsys_gcu_umac_int_map_2_umac_int_15_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_umac_int_map_2_umac_int_15_sel_setf(struct cl_chip *chip, u8 umacint15sel)
{
	ASSERT_ERR_CHIP((((u32)umacint15sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR) & ~((u32)0x000003E0)) | ((u32)umacint15sel << 5));
}

static inline u8 macsys_gcu_umac_int_map_2_umac_int_14_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_umac_int_map_2_umac_int_14_sel_setf(struct cl_chip *chip, u8 umacint14sel)
{
	ASSERT_ERR_CHIP((((u32)umacint14sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_2_ADDR) & ~((u32)0x0000001F)) | ((u32)umacint14sel << 0));
}

/**
 * @brief UMAC_INT_MAP_3 register definition
 *  UMAC interrupt map 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:25 umac_int28_sel            0x1f
 *    24:20 umac_int25_sel            0x1f
 *    19:15 umac_int24_sel            0x1f
 *    14:10 umac_int23_sel            0x1f
 *    09:05 umac_int22_sel            0x1f
 *    04:00 umac_int21_sel            0x1f
 * </pre>
 */
#define MACSYS_GCU_UMAC_INT_MAP_3_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001A0)
#define MACSYS_GCU_UMAC_INT_MAP_3_OFFSET      0x000001A0
#define MACSYS_GCU_UMAC_INT_MAP_3_INDEX       0x00000068
#define MACSYS_GCU_UMAC_INT_MAP_3_RESET       0x3FFFFFFF

static inline u32 macsys_gcu_umac_int_map_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR);
}

static inline void macsys_gcu_umac_int_map_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_28_SEL_MASK    ((u32)0x3E000000)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_28_SEL_LSB    25
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_28_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_25_SEL_MASK    ((u32)0x01F00000)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_25_SEL_LSB    20
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_25_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_24_SEL_MASK    ((u32)0x000F8000)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_24_SEL_LSB    15
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_24_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_23_SEL_MASK    ((u32)0x00007C00)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_23_SEL_LSB    10
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_23_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_22_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_22_SEL_LSB    5
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_22_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_21_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_21_SEL_LSB    0
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_21_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_28_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_25_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_24_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_23_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_22_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_21_SEL_RST    0x1f

static inline void macsys_gcu_umac_int_map_3_pack(struct cl_chip *chip, u8 umac_int28_sel, u8 umac_int25_sel, u8 umac_int24_sel, u8 umac_int23_sel, u8 umac_int22_sel, u8 umac_int21_sel)
{
	ASSERT_ERR_CHIP((((u32)umac_int28_sel << 25) & ~((u32)0x3E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int25_sel << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int24_sel << 15) & ~((u32)0x000F8000)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int23_sel << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int22_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int21_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR, ((u32)umac_int28_sel << 25) | ((u32)umac_int25_sel << 20) | ((u32)umac_int24_sel << 15) | ((u32)umac_int23_sel << 10) | ((u32)umac_int22_sel << 5) | ((u32)umac_int21_sel << 0));
}

static inline void macsys_gcu_umac_int_map_3_unpack(struct cl_chip *chip, u8 *umac_int28_sel, u8 *umac_int25_sel, u8 *umac_int24_sel, u8 *umac_int23_sel, u8 *umac_int22_sel, u8 *umac_int21_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR);

	*umac_int28_sel = (local_val & ((u32)0x3E000000)) >> 25;
	*umac_int25_sel = (local_val & ((u32)0x01F00000)) >> 20;
	*umac_int24_sel = (local_val & ((u32)0x000F8000)) >> 15;
	*umac_int23_sel = (local_val & ((u32)0x00007C00)) >> 10;
	*umac_int22_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*umac_int21_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_umac_int_map_3_umac_int_28_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x3E000000)) >> 25);
}

static inline void macsys_gcu_umac_int_map_3_umac_int_28_sel_setf(struct cl_chip *chip, u8 umacint28sel)
{
	ASSERT_ERR_CHIP((((u32)umacint28sel << 25) & ~((u32)0x3E000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR) & ~((u32)0x3E000000)) | ((u32)umacint28sel << 25));
}

static inline u8 macsys_gcu_umac_int_map_3_umac_int_25_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macsys_gcu_umac_int_map_3_umac_int_25_sel_setf(struct cl_chip *chip, u8 umacint25sel)
{
	ASSERT_ERR_CHIP((((u32)umacint25sel << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR) & ~((u32)0x01F00000)) | ((u32)umacint25sel << 20));
}

static inline u8 macsys_gcu_umac_int_map_3_umac_int_24_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x000F8000)) >> 15);
}

static inline void macsys_gcu_umac_int_map_3_umac_int_24_sel_setf(struct cl_chip *chip, u8 umacint24sel)
{
	ASSERT_ERR_CHIP((((u32)umacint24sel << 15) & ~((u32)0x000F8000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR) & ~((u32)0x000F8000)) | ((u32)umacint24sel << 15));
}

static inline u8 macsys_gcu_umac_int_map_3_umac_int_23_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macsys_gcu_umac_int_map_3_umac_int_23_sel_setf(struct cl_chip *chip, u8 umacint23sel)
{
	ASSERT_ERR_CHIP((((u32)umacint23sel << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR) & ~((u32)0x00007C00)) | ((u32)umacint23sel << 10));
}

static inline u8 macsys_gcu_umac_int_map_3_umac_int_22_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_umac_int_map_3_umac_int_22_sel_setf(struct cl_chip *chip, u8 umacint22sel)
{
	ASSERT_ERR_CHIP((((u32)umacint22sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR) & ~((u32)0x000003E0)) | ((u32)umacint22sel << 5));
}

static inline u8 macsys_gcu_umac_int_map_3_umac_int_21_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_umac_int_map_3_umac_int_21_sel_setf(struct cl_chip *chip, u8 umacint21sel)
{
	ASSERT_ERR_CHIP((((u32)umacint21sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_3_ADDR) & ~((u32)0x0000001F)) | ((u32)umacint21sel << 0));
}

/**
 * @brief UMAC_INT_MAP_4 register definition
 *  UMAC interrupt map 4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:05 umac_int30_sel            0x1f
 *    04:00 umac_int29_sel            0x1f
 * </pre>
 */
#define MACSYS_GCU_UMAC_INT_MAP_4_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001A4)
#define MACSYS_GCU_UMAC_INT_MAP_4_OFFSET      0x000001A4
#define MACSYS_GCU_UMAC_INT_MAP_4_INDEX       0x00000069
#define MACSYS_GCU_UMAC_INT_MAP_4_RESET       0x000003FF

static inline u32 macsys_gcu_umac_int_map_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_4_ADDR);
}

static inline void macsys_gcu_umac_int_map_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_4_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_30_SEL_MASK    ((u32)0x000003E0)
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_30_SEL_LSB    5
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_30_SEL_WIDTH    ((u32)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_29_SEL_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_29_SEL_LSB    0
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_29_SEL_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_30_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_29_SEL_RST    0x1f

static inline void macsys_gcu_umac_int_map_4_pack(struct cl_chip *chip, u8 umac_int30_sel, u8 umac_int29_sel)
{
	ASSERT_ERR_CHIP((((u32)umac_int30_sel << 5) & ~((u32)0x000003E0)) == 0);
	ASSERT_ERR_CHIP((((u32)umac_int29_sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_4_ADDR, ((u32)umac_int30_sel << 5) | ((u32)umac_int29_sel << 0));
}

static inline void macsys_gcu_umac_int_map_4_unpack(struct cl_chip *chip, u8 *umac_int30_sel, u8 *umac_int29_sel)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_4_ADDR);

	*umac_int30_sel = (local_val & ((u32)0x000003E0)) >> 5;
	*umac_int29_sel = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macsys_gcu_umac_int_map_4_umac_int_30_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_4_ADDR);

	return (u8)((local_val & ((u32)0x000003E0)) >> 5);
}

static inline void macsys_gcu_umac_int_map_4_umac_int_30_sel_setf(struct cl_chip *chip, u8 umacint30sel)
{
	ASSERT_ERR_CHIP((((u32)umacint30sel << 5) & ~((u32)0x000003E0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_4_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_4_ADDR) & ~((u32)0x000003E0)) | ((u32)umacint30sel << 5));
}

static inline u8 macsys_gcu_umac_int_map_4_umac_int_29_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_4_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macsys_gcu_umac_int_map_4_umac_int_29_sel_setf(struct cl_chip *chip, u8 umacint29sel)
{
	ASSERT_ERR_CHIP((((u32)umacint29sel << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_UMAC_INT_MAP_4_ADDR, (cl_reg_read(chip, MACSYS_GCU_UMAC_INT_MAP_4_ADDR) & ~((u32)0x0000001F)) | ((u32)umacint29sel << 0));
}

/**
 * @brief AXI_ERROR_INT_ROUTE register definition
 *  Select the CPU that is interrupted when AXI error register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 CPU_SELECT                0x0
 * </pre>
 */
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001B0)
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_OFFSET      0x000001B0
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_INDEX       0x0000006C
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_RESET       0x00000000

static inline u32 macsys_gcu_axi_error_int_route_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_ROUTE_ADDR);
}

static inline void macsys_gcu_axi_error_int_route_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_AXI_ERROR_INT_ROUTE_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_CPU_SELECT_MASK    ((u32)0x0000000F)
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_CPU_SELECT_LSB    0
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_CPU_SELECT_WIDTH    ((u32)0x00000004)

#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_CPU_SELECT_RST    0x0

static inline u8 macsys_gcu_axi_error_int_route_cpu_select_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_ROUTE_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macsys_gcu_axi_error_int_route_cpu_select_setf(struct cl_chip *chip, u8 cpuselect)
{
	ASSERT_ERR_CHIP((((u32)cpuselect << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AXI_ERROR_INT_ROUTE_ADDR, (u32)cpuselect << 0);
}

/**
 * @brief AXI_ERROR_INT_RAWSTAT register definition
 *  AXI Error Slave Interrupt Raw Status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    PHY_AXI_ERROR_EVENT       0
 *    00    AXI_ERROR_EVENT           0
 * </pre>
 */
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001B4)
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_OFFSET      0x000001B4
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_INDEX       0x0000006D
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_RESET       0x00000000

static inline u32 macsys_gcu_axi_error_int_rawstat_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_ADDR);
}

/* Field definitions */
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_PHY_AXI_ERROR_EVENT_BIT    ((u32)0x00000002)
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_PHY_AXI_ERROR_EVENT_POS    1
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_AXI_ERROR_EVENT_BIT    ((u32)0x00000001)
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_AXI_ERROR_EVENT_POS    0

#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_PHY_AXI_ERROR_EVENT_RST    0x0
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_AXI_ERROR_EVENT_RST    0x0

static inline void macsys_gcu_axi_error_int_rawstat_unpack(struct cl_chip *chip, u8 *phy_axi_error_event, u8 *axi_error_event)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_ADDR);

	*phy_axi_error_event = (local_val & ((u32)0x00000002)) >> 1;
	*axi_error_event = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macsys_gcu_axi_error_int_rawstat_phy_axi_error_event_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline u8 macsys_gcu_axi_error_int_rawstat_axi_error_event_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

/**
 * @brief AXI_ERROR_INT_ENABLE register definition
 *  AXI Error Slave Interrupt Enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    PHY_AXI_ERROR_INT_ENABLE  0
 *    00    AXI_ERROR_INT_ENABLE      0
 * </pre>
 */
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001B8)
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_OFFSET      0x000001B8
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_INDEX       0x0000006E
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_RESET       0x00000000

static inline u32 macsys_gcu_axi_error_int_enable_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR);
}

static inline void macsys_gcu_axi_error_int_enable_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_PHY_AXI_ERROR_INT_ENABLE_BIT    ((u32)0x00000002)
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_PHY_AXI_ERROR_INT_ENABLE_POS    1
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_AXI_ERROR_INT_ENABLE_BIT    ((u32)0x00000001)
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_AXI_ERROR_INT_ENABLE_POS    0

#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_PHY_AXI_ERROR_INT_ENABLE_RST    0x0
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_AXI_ERROR_INT_ENABLE_RST    0x0

static inline void macsys_gcu_axi_error_int_enable_pack(struct cl_chip *chip, u8 phy_axi_error_int_enable, u8 axi_error_int_enable)
{
	ASSERT_ERR_CHIP((((u32)phy_axi_error_int_enable << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)axi_error_int_enable << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR, ((u32)phy_axi_error_int_enable << 1) | ((u32)axi_error_int_enable << 0));
}

static inline void macsys_gcu_axi_error_int_enable_unpack(struct cl_chip *chip, u8 *phy_axi_error_int_enable, u8 *axi_error_int_enable)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR);

	*phy_axi_error_int_enable = (local_val & ((u32)0x00000002)) >> 1;
	*axi_error_int_enable = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macsys_gcu_axi_error_int_enable_phy_axi_error_int_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void macsys_gcu_axi_error_int_enable_phy_axi_error_int_enable_setf(struct cl_chip *chip, u8 phyaxierrorintenable)
{
	ASSERT_ERR_CHIP((((u32)phyaxierrorintenable << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR, (cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR) & ~((u32)0x00000002)) | ((u32)phyaxierrorintenable << 1));
}

static inline u8 macsys_gcu_axi_error_int_enable_axi_error_int_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macsys_gcu_axi_error_int_enable_axi_error_int_enable_setf(struct cl_chip *chip, u8 axierrorintenable)
{
	ASSERT_ERR_CHIP((((u32)axierrorintenable << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR, (cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR) & ~((u32)0x00000001)) | ((u32)axierrorintenable << 0));
}

/**
 * @brief AXI_ERROR_INT_STATUS register definition
 *  AXI Error Slave Interrupt Status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    PHY_AXI_ERROR_EVENT       0
 *    00    AXI_ERROR_EVENT           0
 * </pre>
 */
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001C4)
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_OFFSET      0x000001C4
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_INDEX       0x00000071
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_RESET       0x00000000

static inline u32 macsys_gcu_axi_error_int_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_STATUS_ADDR);
}

/* Field definitions */
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_PHY_AXI_ERROR_EVENT_BIT    ((u32)0x00000002)
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_PHY_AXI_ERROR_EVENT_POS    1
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_AXI_ERROR_EVENT_BIT    ((u32)0x00000001)
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_AXI_ERROR_EVENT_POS    0

#define MACSYS_GCU_AXI_ERROR_INT_STATUS_PHY_AXI_ERROR_EVENT_RST    0x0
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_AXI_ERROR_EVENT_RST    0x0

static inline void macsys_gcu_axi_error_int_status_unpack(struct cl_chip *chip, u8 *phy_axi_error_event, u8 *axi_error_event)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_STATUS_ADDR);

	*phy_axi_error_event = (local_val & ((u32)0x00000002)) >> 1;
	*axi_error_event = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macsys_gcu_axi_error_int_status_phy_axi_error_event_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline u8 macsys_gcu_axi_error_int_status_axi_error_event_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INT_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

/**
 * @brief AXI_ERROR_ADDRESS register definition
 *  AXI Error Slave address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 AXI_ERROR_ADDRESS         0x0
 * </pre>
 */
#define MACSYS_GCU_AXI_ERROR_ADDRESS_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001C8)
#define MACSYS_GCU_AXI_ERROR_ADDRESS_OFFSET      0x000001C8
#define MACSYS_GCU_AXI_ERROR_ADDRESS_INDEX       0x00000072
#define MACSYS_GCU_AXI_ERROR_ADDRESS_RESET       0x00000000

static inline u32 macsys_gcu_axi_error_address_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_ADDRESS_ADDR);
}

/* Field definitions */
#define MACSYS_GCU_AXI_ERROR_ADDRESS_AXI_ERROR_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACSYS_GCU_AXI_ERROR_ADDRESS_AXI_ERROR_ADDRESS_LSB    0
#define MACSYS_GCU_AXI_ERROR_ADDRESS_AXI_ERROR_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACSYS_GCU_AXI_ERROR_ADDRESS_AXI_ERROR_ADDRESS_RST    0x0

static inline u32 macsys_gcu_axi_error_address_axi_error_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_ADDRESS_ADDR);

	return (u32)(local_val >> 0);
}

/**
 * @brief AXI_ERROR_INFO register definition
 *  AXI Error Information register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:12 BURST_LENGTH              0x0
 *    11:10 BURST_TYPE                0x0
 *    09    READ_WRITE_B              0
 *    08:00 AXI_ERROR_MASTER_ID       0x0
 * </pre>
 */
#define MACSYS_GCU_AXI_ERROR_INFO_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001CC)
#define MACSYS_GCU_AXI_ERROR_INFO_OFFSET      0x000001CC
#define MACSYS_GCU_AXI_ERROR_INFO_INDEX       0x00000073
#define MACSYS_GCU_AXI_ERROR_INFO_RESET       0x00000000

static inline u32 macsys_gcu_axi_error_info_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INFO_ADDR);
}

static inline void macsys_gcu_axi_error_info_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_AXI_ERROR_INFO_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_LENGTH_MASK    ((u32)0x0000F000)
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_LENGTH_LSB    12
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_LENGTH_WIDTH    ((u32)0x00000004)
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_TYPE_MASK    ((u32)0x00000C00)
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_TYPE_LSB    10
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_TYPE_WIDTH    ((u32)0x00000002)
#define MACSYS_GCU_AXI_ERROR_INFO_READ_WRITE_B_BIT    ((u32)0x00000200)
#define MACSYS_GCU_AXI_ERROR_INFO_READ_WRITE_B_POS    9
#define MACSYS_GCU_AXI_ERROR_INFO_AXI_ERROR_MASTER_ID_MASK    ((u32)0x000001FF)
#define MACSYS_GCU_AXI_ERROR_INFO_AXI_ERROR_MASTER_ID_LSB    0
#define MACSYS_GCU_AXI_ERROR_INFO_AXI_ERROR_MASTER_ID_WIDTH    ((u32)0x00000009)

#define MACSYS_GCU_AXI_ERROR_INFO_BURST_LENGTH_RST    0x0
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_TYPE_RST    0x0
#define MACSYS_GCU_AXI_ERROR_INFO_READ_WRITE_B_RST    0x0
#define MACSYS_GCU_AXI_ERROR_INFO_AXI_ERROR_MASTER_ID_RST    0x0

static inline void macsys_gcu_axi_error_info_pack(struct cl_chip *chip, u8 burst_length, u8 burst_type, u8 read_write_b, u16 axi_error_master_id)
{
	ASSERT_ERR_CHIP((((u32)burst_length << 12) & ~((u32)0x0000F000)) == 0);
	ASSERT_ERR_CHIP((((u32)burst_type << 10) & ~((u32)0x00000C00)) == 0);
	ASSERT_ERR_CHIP((((u32)read_write_b << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)axi_error_master_id << 0) & ~((u32)0x000001FF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AXI_ERROR_INFO_ADDR, ((u32)burst_length << 12) | ((u32)burst_type << 10) | ((u32)read_write_b << 9) | ((u32)axi_error_master_id << 0));
}

static inline void macsys_gcu_axi_error_info_unpack(struct cl_chip *chip, u8 *burst_length, u8 *burst_type, u8 *read_write_b, u16 *axi_error_master_id)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INFO_ADDR);

	*burst_length = (local_val & ((u32)0x0000F000)) >> 12;
	*burst_type = (local_val & ((u32)0x00000C00)) >> 10;
	*read_write_b = (local_val & ((u32)0x00000200)) >> 9;
	*axi_error_master_id = (local_val & ((u32)0x000001FF)) >> 0;
}

static inline u8 macsys_gcu_axi_error_info_burst_length_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INFO_ADDR);

	return (u8)((local_val & ((u32)0x0000F000)) >> 12);
}

static inline u8 macsys_gcu_axi_error_info_burst_type_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INFO_ADDR);

	return (u8)((local_val & ((u32)0x00000C00)) >> 10);
}

static inline u8 macsys_gcu_axi_error_info_read_write_b_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INFO_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline u16 macsys_gcu_axi_error_info_axi_error_master_id_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INFO_ADDR);

	return (u16)((local_val & ((u32)0x000001FF)) >> 0);
}

static inline void macsys_gcu_axi_error_info_axi_error_master_id_setf(struct cl_chip *chip, u16 axierrormasterid)
{
	ASSERT_ERR_CHIP((((u32)axierrormasterid << 0) & ~((u32)0x000001FF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_AXI_ERROR_INFO_ADDR, (cl_reg_read(chip, MACSYS_GCU_AXI_ERROR_INFO_ADDR) & ~((u32)0x000001FF)) | ((u32)axierrormasterid << 0));
}

/**
 * @brief PHY_AXI_ERROR_ADDRESS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PHY_AXI_ERROR_ADDRESS     0x0
 * </pre>
 */
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001D0)
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_OFFSET      0x000001D0
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_INDEX       0x00000074
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_RESET       0x00000000

static inline u32 macsys_gcu_phy_axi_error_address_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_ADDR);
}

/* Field definitions */
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_PHY_AXI_ERROR_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_PHY_AXI_ERROR_ADDRESS_LSB    0
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_PHY_AXI_ERROR_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_PHY_AXI_ERROR_ADDRESS_RST    0x0

static inline u32 macsys_gcu_phy_axi_error_address_phy_axi_error_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_ADDR);

	return (u32)(local_val >> 0);
}

/**
 * @brief PHY_AXI_ERROR_INFO register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10:07 PHY_AXI_ERROR_BURST_LEN   0x0
 *    06:05 PHY_AXI_ERROR_BURST_TYPE  0x0
 *    04    PHY_AXI_ERROR_RW          0
 *    03:00 PHY_AXI_ERROR_MASTER_ID   0x0
 * </pre>
 */
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001D4)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_OFFSET      0x000001D4
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_INDEX       0x00000075
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_RESET       0x00000000

static inline u32 macsys_gcu_phy_axi_error_info_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR);
}

static inline void macsys_gcu_phy_axi_error_info_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_LEN_MASK    ((u32)0x00000780)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_LEN_LSB    7
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_LEN_WIDTH    ((u32)0x00000004)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_TYPE_MASK    ((u32)0x00000060)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_TYPE_LSB    5
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_TYPE_WIDTH    ((u32)0x00000002)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_RW_BIT    ((u32)0x00000010)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_RW_POS    4
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_MASTER_ID_MASK    ((u32)0x0000000F)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_MASTER_ID_LSB    0
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_MASTER_ID_WIDTH    ((u32)0x00000004)

#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_LEN_RST    0x0
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_TYPE_RST    0x0
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_RW_RST    0x0
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_MASTER_ID_RST    0x0

static inline void macsys_gcu_phy_axi_error_info_pack(struct cl_chip *chip, u8 phy_axi_error_burst_len, u8 phy_axi_error_burst_type, u8 phy_axi_error_rw, u8 phy_axi_error_master_id)
{
	ASSERT_ERR_CHIP((((u32)phy_axi_error_burst_len << 7) & ~((u32)0x00000780)) == 0);
	ASSERT_ERR_CHIP((((u32)phy_axi_error_burst_type << 5) & ~((u32)0x00000060)) == 0);
	ASSERT_ERR_CHIP((((u32)phy_axi_error_rw << 4) & ~((u32)0x00000010)) == 0);
	ASSERT_ERR_CHIP((((u32)phy_axi_error_master_id << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR, ((u32)phy_axi_error_burst_len << 7) | ((u32)phy_axi_error_burst_type << 5) | ((u32)phy_axi_error_rw << 4) | ((u32)phy_axi_error_master_id << 0));
}

static inline void macsys_gcu_phy_axi_error_info_unpack(struct cl_chip *chip, u8 *phy_axi_error_burst_len, u8 *phy_axi_error_burst_type, u8 *phy_axi_error_rw, u8 *phy_axi_error_master_id)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR);

	*phy_axi_error_burst_len = (local_val & ((u32)0x00000780)) >> 7;
	*phy_axi_error_burst_type = (local_val & ((u32)0x00000060)) >> 5;
	*phy_axi_error_rw = (local_val & ((u32)0x00000010)) >> 4;
	*phy_axi_error_master_id = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 macsys_gcu_phy_axi_error_info_phy_axi_error_burst_len_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR);

	return (u8)((local_val & ((u32)0x00000780)) >> 7);
}

static inline u8 macsys_gcu_phy_axi_error_info_phy_axi_error_burst_type_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR);

	return (u8)((local_val & ((u32)0x00000060)) >> 5);
}

static inline u8 macsys_gcu_phy_axi_error_info_phy_axi_error_rw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline u8 macsys_gcu_phy_axi_error_info_phy_axi_error_master_id_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void macsys_gcu_phy_axi_error_info_phy_axi_error_master_id_setf(struct cl_chip *chip, u8 phyaxierrormasterid)
{
	ASSERT_ERR_CHIP((((u32)phyaxierrormasterid << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR, (cl_reg_read(chip, MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR) & ~((u32)0x0000000F)) | ((u32)phyaxierrormasterid << 0));
}

/**
 * @brief USB_2_PHY_CONFIG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30    SCP_EN                    1
 *    29    RX_LP_EN                  1
 *    28    RSTN_BYPASS               0
 *    27    HS_LP_MODE_EN             1
 *    26:25 SQL_CUR_ADJ               0x1
 *    24:22 PLLBW_SEL                 0x3
 *    21:20 HS_EMP_ADJ                0x0
 *    19    HS_EMP_EN                 0
 *    18:15 SQL_SP_ADJ                0x5
 *    14    CALIB_ONCE_EN             1
 *    13:12 HS_REG0_P8_ADJ            0x1
 *    11:09 REG14_ADJ                 0x0
 *    08    CDR_RST_SEL               0
 *    07:06 HS_RISE_TUNE              0x0
 *    05:03 FS_CROSS_ADJ              0x4
 *    02:00 LS_CROSS_ADJ              0x6
 * </pre>
 */
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001D8)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_OFFSET      0x000001D8
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_INDEX       0x00000076
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_RESET       0x6AC2D026

static inline u32 macsys_gcu_usb_2_phy_config_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
}

static inline void macsys_gcu_usb_2_phy_config_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SCP_EN_BIT    ((u32)0x40000000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SCP_EN_POS    30
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_RX_LP_EN_BIT    ((u32)0x20000000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_RX_LP_EN_POS    29
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_RSTN_BYPASS_BIT    ((u32)0x10000000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_RSTN_BYPASS_POS    28
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_LP_MODE_EN_BIT    ((u32)0x08000000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_LP_MODE_EN_POS    27
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_CUR_ADJ_MASK    ((u32)0x06000000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_CUR_ADJ_LSB    25
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_CUR_ADJ_WIDTH    ((u32)0x00000002)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_PLLBW_SEL_MASK    ((u32)0x01C00000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_PLLBW_SEL_LSB    22
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_PLLBW_SEL_WIDTH    ((u32)0x00000003)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_EMP_ADJ_MASK    ((u32)0x00300000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_EMP_ADJ_LSB    20
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_EMP_ADJ_WIDTH    ((u32)0x00000002)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_EMP_EN_BIT    ((u32)0x00080000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_EMP_EN_POS    19
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_SP_ADJ_MASK    ((u32)0x00078000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_SP_ADJ_LSB    15
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_SP_ADJ_WIDTH    ((u32)0x00000004)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_CALIB_ONCE_EN_BIT    ((u32)0x00004000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_CALIB_ONCE_EN_POS    14
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_REG_0_P_8_ADJ_MASK    ((u32)0x00003000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_REG_0_P_8_ADJ_LSB    12
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_REG_0_P_8_ADJ_WIDTH    ((u32)0x00000002)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_REG_14_ADJ_MASK    ((u32)0x00000E00)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_REG_14_ADJ_LSB    9
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_REG_14_ADJ_WIDTH    ((u32)0x00000003)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_CDR_RST_SEL_BIT    ((u32)0x00000100)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_CDR_RST_SEL_POS    8
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_RISE_TUNE_MASK    ((u32)0x000000C0)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_RISE_TUNE_LSB    6
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_RISE_TUNE_WIDTH    ((u32)0x00000002)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_FS_CROSS_ADJ_MASK    ((u32)0x00000038)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_FS_CROSS_ADJ_LSB    3
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_FS_CROSS_ADJ_WIDTH    ((u32)0x00000003)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_LS_CROSS_ADJ_MASK    ((u32)0x00000007)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_LS_CROSS_ADJ_LSB    0
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_LS_CROSS_ADJ_WIDTH    ((u32)0x00000003)

#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SCP_EN_RST    0x1
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_RX_LP_EN_RST    0x1
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_RSTN_BYPASS_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_LP_MODE_EN_RST    0x1
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_CUR_ADJ_RST    0x1
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_PLLBW_SEL_RST    0x3
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_EMP_ADJ_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_EMP_EN_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_SP_ADJ_RST    0x5
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_CALIB_ONCE_EN_RST    0x1
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_REG_0_P_8_ADJ_RST    0x1
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_REG_14_ADJ_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_CDR_RST_SEL_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_RISE_TUNE_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_FS_CROSS_ADJ_RST    0x4
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_LS_CROSS_ADJ_RST    0x6

static inline void macsys_gcu_usb_2_phy_config_0_pack(struct cl_chip *chip, u8 scp_en, u8 rx_lp_en, u8 rstn_bypass, u8 hs_lp_mode_en, u8 sql_cur_adj, u8 pllbw_sel, u8 hs_emp_adj, u8 hs_emp_en, u8 sql_sp_adj, u8 calib_once_en, u8 hs_reg0_p8_adj, u8 reg14_adj, u8 cdr_rst_sel, u8 hs_rise_tune, u8 fs_cross_adj, u8 ls_cross_adj)
{
	ASSERT_ERR_CHIP((((u32)scp_en << 30) & ~((u32)0x40000000)) == 0);
	ASSERT_ERR_CHIP((((u32)rx_lp_en << 29) & ~((u32)0x20000000)) == 0);
	ASSERT_ERR_CHIP((((u32)rstn_bypass << 28) & ~((u32)0x10000000)) == 0);
	ASSERT_ERR_CHIP((((u32)hs_lp_mode_en << 27) & ~((u32)0x08000000)) == 0);
	ASSERT_ERR_CHIP((((u32)sql_cur_adj << 25) & ~((u32)0x06000000)) == 0);
	ASSERT_ERR_CHIP((((u32)pllbw_sel << 22) & ~((u32)0x01C00000)) == 0);
	ASSERT_ERR_CHIP((((u32)hs_emp_adj << 20) & ~((u32)0x00300000)) == 0);
	ASSERT_ERR_CHIP((((u32)hs_emp_en << 19) & ~((u32)0x00080000)) == 0);
	ASSERT_ERR_CHIP((((u32)sql_sp_adj << 15) & ~((u32)0x00078000)) == 0);
	ASSERT_ERR_CHIP((((u32)calib_once_en << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)hs_reg0_p8_adj << 12) & ~((u32)0x00003000)) == 0);
	ASSERT_ERR_CHIP((((u32)reg14_adj << 9) & ~((u32)0x00000E00)) == 0);
	ASSERT_ERR_CHIP((((u32)cdr_rst_sel << 8) & ~((u32)0x00000100)) == 0);
	ASSERT_ERR_CHIP((((u32)hs_rise_tune << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)fs_cross_adj << 3) & ~((u32)0x00000038)) == 0);
	ASSERT_ERR_CHIP((((u32)ls_cross_adj << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, ((u32)scp_en << 30) | ((u32)rx_lp_en << 29) | ((u32)rstn_bypass << 28) | ((u32)hs_lp_mode_en << 27) | ((u32)sql_cur_adj << 25) | ((u32)pllbw_sel << 22) | ((u32)hs_emp_adj << 20) | ((u32)hs_emp_en << 19) | ((u32)sql_sp_adj << 15) | ((u32)calib_once_en << 14) | ((u32)hs_reg0_p8_adj << 12) | ((u32)reg14_adj << 9) | ((u32)cdr_rst_sel << 8) | ((u32)hs_rise_tune << 6) | ((u32)fs_cross_adj << 3) | ((u32)ls_cross_adj << 0));
}

static inline void macsys_gcu_usb_2_phy_config_0_unpack(struct cl_chip *chip, u8 *scp_en, u8 *rx_lp_en, u8 *rstn_bypass, u8 *hs_lp_mode_en, u8 *sql_cur_adj, u8 *pllbw_sel, u8 *hs_emp_adj, u8 *hs_emp_en, u8 *sql_sp_adj, u8 *calib_once_en, u8 *hs_reg0_p8_adj, u8 *reg14_adj, u8 *cdr_rst_sel, u8 *hs_rise_tune, u8 *fs_cross_adj, u8 *ls_cross_adj)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	*scp_en = (local_val & ((u32)0x40000000)) >> 30;
	*rx_lp_en = (local_val & ((u32)0x20000000)) >> 29;
	*rstn_bypass = (local_val & ((u32)0x10000000)) >> 28;
	*hs_lp_mode_en = (local_val & ((u32)0x08000000)) >> 27;
	*sql_cur_adj = (local_val & ((u32)0x06000000)) >> 25;
	*pllbw_sel = (local_val & ((u32)0x01C00000)) >> 22;
	*hs_emp_adj = (local_val & ((u32)0x00300000)) >> 20;
	*hs_emp_en = (local_val & ((u32)0x00080000)) >> 19;
	*sql_sp_adj = (local_val & ((u32)0x00078000)) >> 15;
	*calib_once_en = (local_val & ((u32)0x00004000)) >> 14;
	*hs_reg0_p8_adj = (local_val & ((u32)0x00003000)) >> 12;
	*reg14_adj = (local_val & ((u32)0x00000E00)) >> 9;
	*cdr_rst_sel = (local_val & ((u32)0x00000100)) >> 8;
	*hs_rise_tune = (local_val & ((u32)0x000000C0)) >> 6;
	*fs_cross_adj = (local_val & ((u32)0x00000038)) >> 3;
	*ls_cross_adj = (local_val & ((u32)0x00000007)) >> 0;
}

static inline u8 macsys_gcu_usb_2_phy_config_0_scp_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x40000000)) >> 30);
}

static inline void macsys_gcu_usb_2_phy_config_0_scp_en_setf(struct cl_chip *chip, u8 scpen)
{
	ASSERT_ERR_CHIP((((u32)scpen << 30) & ~((u32)0x40000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x40000000)) | ((u32)scpen << 30));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_rx_lp_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x20000000)) >> 29);
}

static inline void macsys_gcu_usb_2_phy_config_0_rx_lp_en_setf(struct cl_chip *chip, u8 rxlpen)
{
	ASSERT_ERR_CHIP((((u32)rxlpen << 29) & ~((u32)0x20000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x20000000)) | ((u32)rxlpen << 29));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_rstn_bypass_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x10000000)) >> 28);
}

static inline void macsys_gcu_usb_2_phy_config_0_rstn_bypass_setf(struct cl_chip *chip, u8 rstnbypass)
{
	ASSERT_ERR_CHIP((((u32)rstnbypass << 28) & ~((u32)0x10000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x10000000)) | ((u32)rstnbypass << 28));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_hs_lp_mode_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x08000000)) >> 27);
}

static inline void macsys_gcu_usb_2_phy_config_0_hs_lp_mode_en_setf(struct cl_chip *chip, u8 hslpmodeen)
{
	ASSERT_ERR_CHIP((((u32)hslpmodeen << 27) & ~((u32)0x08000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x08000000)) | ((u32)hslpmodeen << 27));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_sql_cur_adj_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x06000000)) >> 25);
}

static inline void macsys_gcu_usb_2_phy_config_0_sql_cur_adj_setf(struct cl_chip *chip, u8 sqlcuradj)
{
	ASSERT_ERR_CHIP((((u32)sqlcuradj << 25) & ~((u32)0x06000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x06000000)) | ((u32)sqlcuradj << 25));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_pllbw_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x01C00000)) >> 22);
}

static inline void macsys_gcu_usb_2_phy_config_0_pllbw_sel_setf(struct cl_chip *chip, u8 pllbwsel)
{
	ASSERT_ERR_CHIP((((u32)pllbwsel << 22) & ~((u32)0x01C00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x01C00000)) | ((u32)pllbwsel << 22));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_hs_emp_adj_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x00300000)) >> 20);
}

static inline void macsys_gcu_usb_2_phy_config_0_hs_emp_adj_setf(struct cl_chip *chip, u8 hsempadj)
{
	ASSERT_ERR_CHIP((((u32)hsempadj << 20) & ~((u32)0x00300000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x00300000)) | ((u32)hsempadj << 20));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_hs_emp_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x00080000)) >> 19);
}

static inline void macsys_gcu_usb_2_phy_config_0_hs_emp_en_setf(struct cl_chip *chip, u8 hsempen)
{
	ASSERT_ERR_CHIP((((u32)hsempen << 19) & ~((u32)0x00080000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x00080000)) | ((u32)hsempen << 19));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_sql_sp_adj_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x00078000)) >> 15);
}

static inline void macsys_gcu_usb_2_phy_config_0_sql_sp_adj_setf(struct cl_chip *chip, u8 sqlspadj)
{
	ASSERT_ERR_CHIP((((u32)sqlspadj << 15) & ~((u32)0x00078000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x00078000)) | ((u32)sqlspadj << 15));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_calib_once_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void macsys_gcu_usb_2_phy_config_0_calib_once_en_setf(struct cl_chip *chip, u8 calibonceen)
{
	ASSERT_ERR_CHIP((((u32)calibonceen << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x00004000)) | ((u32)calibonceen << 14));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_hs_reg_0_p_8_adj_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x00003000)) >> 12);
}

static inline void macsys_gcu_usb_2_phy_config_0_hs_reg_0_p_8_adj_setf(struct cl_chip *chip, u8 hsreg0p8adj)
{
	ASSERT_ERR_CHIP((((u32)hsreg0p8adj << 12) & ~((u32)0x00003000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x00003000)) | ((u32)hsreg0p8adj << 12));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_reg_14_adj_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x00000E00)) >> 9);
}

static inline void macsys_gcu_usb_2_phy_config_0_reg_14_adj_setf(struct cl_chip *chip, u8 reg14adj)
{
	ASSERT_ERR_CHIP((((u32)reg14adj << 9) & ~((u32)0x00000E00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x00000E00)) | ((u32)reg14adj << 9));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_cdr_rst_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x00000100)) >> 8);
}

static inline void macsys_gcu_usb_2_phy_config_0_cdr_rst_sel_setf(struct cl_chip *chip, u8 cdrrstsel)
{
	ASSERT_ERR_CHIP((((u32)cdrrstsel << 8) & ~((u32)0x00000100)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x00000100)) | ((u32)cdrrstsel << 8));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_hs_rise_tune_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void macsys_gcu_usb_2_phy_config_0_hs_rise_tune_setf(struct cl_chip *chip, u8 hsrisetune)
{
	ASSERT_ERR_CHIP((((u32)hsrisetune << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x000000C0)) | ((u32)hsrisetune << 6));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_fs_cross_adj_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x00000038)) >> 3);
}

static inline void macsys_gcu_usb_2_phy_config_0_fs_cross_adj_setf(struct cl_chip *chip, u8 fscrossadj)
{
	ASSERT_ERR_CHIP((((u32)fscrossadj << 3) & ~((u32)0x00000038)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x00000038)) | ((u32)fscrossadj << 3));
}

static inline u8 macsys_gcu_usb_2_phy_config_0_ls_cross_adj_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	return (u8)((local_val & ((u32)0x00000007)) >> 0);
}

static inline void macsys_gcu_usb_2_phy_config_0_ls_cross_adj_setf(struct cl_chip *chip, u8 lscrossadj)
{
	ASSERT_ERR_CHIP((((u32)lscrossadj << 0) & ~((u32)0x00000007)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((u32)0x00000007)) | ((u32)lscrossadj << 0));
}

/**
 * @brief USB_2_PHY_CONFIG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 GLOBAL_CONFIG             0x0
 *    23:20 VBUS_VLD_ADJ              0x7
 *    19:17 REG20_ADJ                 0x0
 *    16:13 DISC_ADJ                  0x8
 *    12:10 XOSC_CUR_ADJ              0x1
 *    09:06 CDR_TIMING_SEL            0x0
 *    05:04 CDR_BW_SEL                0x0
 *    03:00 SQL_VTH_ADJ               0x8
 * </pre>
 */
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001DC)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_OFFSET      0x000001DC
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_INDEX       0x00000077
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_RESET       0x00710408

static inline u32 macsys_gcu_usb_2_phy_config_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);
}

static inline void macsys_gcu_usb_2_phy_config_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_GLOBAL_CONFIG_MASK    ((u32)0xFF000000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_GLOBAL_CONFIG_LSB    24
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_GLOBAL_CONFIG_WIDTH    ((u32)0x00000008)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_VBUS_VLD_ADJ_MASK    ((u32)0x00F00000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_VBUS_VLD_ADJ_LSB    20
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_VBUS_VLD_ADJ_WIDTH    ((u32)0x00000004)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_REG_20_ADJ_MASK    ((u32)0x000E0000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_REG_20_ADJ_LSB    17
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_REG_20_ADJ_WIDTH    ((u32)0x00000003)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_DISC_ADJ_MASK    ((u32)0x0001E000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_DISC_ADJ_LSB    13
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_DISC_ADJ_WIDTH    ((u32)0x00000004)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_XOSC_CUR_ADJ_MASK    ((u32)0x00001C00)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_XOSC_CUR_ADJ_LSB    10
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_XOSC_CUR_ADJ_WIDTH    ((u32)0x00000003)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_TIMING_SEL_MASK    ((u32)0x000003C0)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_TIMING_SEL_LSB    6
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_TIMING_SEL_WIDTH    ((u32)0x00000004)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_BW_SEL_MASK    ((u32)0x00000030)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_BW_SEL_LSB    4
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_BW_SEL_WIDTH    ((u32)0x00000002)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_SQL_VTH_ADJ_MASK    ((u32)0x0000000F)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_SQL_VTH_ADJ_LSB    0
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_SQL_VTH_ADJ_WIDTH    ((u32)0x00000004)

#define MACSYS_GCU_USB_2_PHY_CONFIG_1_GLOBAL_CONFIG_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_VBUS_VLD_ADJ_RST    0x7
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_REG_20_ADJ_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_DISC_ADJ_RST    0x8
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_XOSC_CUR_ADJ_RST    0x1
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_TIMING_SEL_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_BW_SEL_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_SQL_VTH_ADJ_RST    0x8

static inline void macsys_gcu_usb_2_phy_config_1_pack(struct cl_chip *chip, u8 global_config, u8 vbus_vld_adj, u8 reg20_adj, u8 disc_adj, u8 xosc_cur_adj, u8 cdr_timing_sel, u8 cdr_bw_sel, u8 sql_vth_adj)
{
	ASSERT_ERR_CHIP((((u32)global_config << 24) & ~((u32)0xFF000000)) == 0);
	ASSERT_ERR_CHIP((((u32)vbus_vld_adj << 20) & ~((u32)0x00F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)reg20_adj << 17) & ~((u32)0x000E0000)) == 0);
	ASSERT_ERR_CHIP((((u32)disc_adj << 13) & ~((u32)0x0001E000)) == 0);
	ASSERT_ERR_CHIP((((u32)xosc_cur_adj << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)cdr_timing_sel << 6) & ~((u32)0x000003C0)) == 0);
	ASSERT_ERR_CHIP((((u32)cdr_bw_sel << 4) & ~((u32)0x00000030)) == 0);
	ASSERT_ERR_CHIP((((u32)sql_vth_adj << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, ((u32)global_config << 24) | ((u32)vbus_vld_adj << 20) | ((u32)reg20_adj << 17) | ((u32)disc_adj << 13) | ((u32)xosc_cur_adj << 10) | ((u32)cdr_timing_sel << 6) | ((u32)cdr_bw_sel << 4) | ((u32)sql_vth_adj << 0));
}

static inline void macsys_gcu_usb_2_phy_config_1_unpack(struct cl_chip *chip, u8 *global_config, u8 *vbus_vld_adj, u8 *reg20_adj, u8 *disc_adj, u8 *xosc_cur_adj, u8 *cdr_timing_sel, u8 *cdr_bw_sel, u8 *sql_vth_adj)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);

	*global_config = (local_val & ((u32)0xFF000000)) >> 24;
	*vbus_vld_adj = (local_val & ((u32)0x00F00000)) >> 20;
	*reg20_adj = (local_val & ((u32)0x000E0000)) >> 17;
	*disc_adj = (local_val & ((u32)0x0001E000)) >> 13;
	*xosc_cur_adj = (local_val & ((u32)0x00001C00)) >> 10;
	*cdr_timing_sel = (local_val & ((u32)0x000003C0)) >> 6;
	*cdr_bw_sel = (local_val & ((u32)0x00000030)) >> 4;
	*sql_vth_adj = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 macsys_gcu_usb_2_phy_config_1_global_config_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);

	return (u8)((local_val & ((u32)0xFF000000)) >> 24);
}

static inline void macsys_gcu_usb_2_phy_config_1_global_config_setf(struct cl_chip *chip, u8 globalconfig)
{
	ASSERT_ERR_CHIP((((u32)globalconfig << 24) & ~((u32)0xFF000000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((u32)0xFF000000)) | ((u32)globalconfig << 24));
}

static inline u8 macsys_gcu_usb_2_phy_config_1_vbus_vld_adj_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);

	return (u8)((local_val & ((u32)0x00F00000)) >> 20);
}

static inline void macsys_gcu_usb_2_phy_config_1_vbus_vld_adj_setf(struct cl_chip *chip, u8 vbusvldadj)
{
	ASSERT_ERR_CHIP((((u32)vbusvldadj << 20) & ~((u32)0x00F00000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((u32)0x00F00000)) | ((u32)vbusvldadj << 20));
}

static inline u8 macsys_gcu_usb_2_phy_config_1_reg_20_adj_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);

	return (u8)((local_val & ((u32)0x000E0000)) >> 17);
}

static inline void macsys_gcu_usb_2_phy_config_1_reg_20_adj_setf(struct cl_chip *chip, u8 reg20adj)
{
	ASSERT_ERR_CHIP((((u32)reg20adj << 17) & ~((u32)0x000E0000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((u32)0x000E0000)) | ((u32)reg20adj << 17));
}

static inline u8 macsys_gcu_usb_2_phy_config_1_disc_adj_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);

	return (u8)((local_val & ((u32)0x0001E000)) >> 13);
}

static inline void macsys_gcu_usb_2_phy_config_1_disc_adj_setf(struct cl_chip *chip, u8 discadj)
{
	ASSERT_ERR_CHIP((((u32)discadj << 13) & ~((u32)0x0001E000)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((u32)0x0001E000)) | ((u32)discadj << 13));
}

static inline u8 macsys_gcu_usb_2_phy_config_1_xosc_cur_adj_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void macsys_gcu_usb_2_phy_config_1_xosc_cur_adj_setf(struct cl_chip *chip, u8 xosccuradj)
{
	ASSERT_ERR_CHIP((((u32)xosccuradj << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((u32)0x00001C00)) | ((u32)xosccuradj << 10));
}

static inline u8 macsys_gcu_usb_2_phy_config_1_cdr_timing_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);

	return (u8)((local_val & ((u32)0x000003C0)) >> 6);
}

static inline void macsys_gcu_usb_2_phy_config_1_cdr_timing_sel_setf(struct cl_chip *chip, u8 cdrtimingsel)
{
	ASSERT_ERR_CHIP((((u32)cdrtimingsel << 6) & ~((u32)0x000003C0)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((u32)0x000003C0)) | ((u32)cdrtimingsel << 6));
}

static inline u8 macsys_gcu_usb_2_phy_config_1_cdr_bw_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);

	return (u8)((local_val & ((u32)0x00000030)) >> 4);
}

static inline void macsys_gcu_usb_2_phy_config_1_cdr_bw_sel_setf(struct cl_chip *chip, u8 cdrbwsel)
{
	ASSERT_ERR_CHIP((((u32)cdrbwsel << 4) & ~((u32)0x00000030)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((u32)0x00000030)) | ((u32)cdrbwsel << 4));
}

static inline u8 macsys_gcu_usb_2_phy_config_1_sql_vth_adj_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void macsys_gcu_usb_2_phy_config_1_sql_vth_adj_setf(struct cl_chip *chip, u8 sqlvthadj)
{
	ASSERT_ERR_CHIP((((u32)sqlvthadj << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((u32)0x0000000F)) | ((u32)sqlvthadj << 0));
}

/**
 * @brief USB_2_BIST_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:01 TEST_LOOP                 0x0
 *    00    BIST_EN_N                 1
 * </pre>
 */
#define MACSYS_GCU_USB_2_BIST_CTRL_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001E0)
#define MACSYS_GCU_USB_2_BIST_CTRL_OFFSET      0x000001E0
#define MACSYS_GCU_USB_2_BIST_CTRL_INDEX       0x00000078
#define MACSYS_GCU_USB_2_BIST_CTRL_RESET       0x00000001

static inline u32 macsys_gcu_usb_2_bist_ctrl_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_USB_2_BIST_CTRL_ADDR);
}

static inline void macsys_gcu_usb_2_bist_ctrl_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_USB_2_BIST_CTRL_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_USB_2_BIST_CTRL_TEST_LOOP_MASK    ((u32)0x0000000E)
#define MACSYS_GCU_USB_2_BIST_CTRL_TEST_LOOP_LSB    1
#define MACSYS_GCU_USB_2_BIST_CTRL_TEST_LOOP_WIDTH    ((u32)0x00000003)
#define MACSYS_GCU_USB_2_BIST_CTRL_BIST_EN_N_BIT    ((u32)0x00000001)
#define MACSYS_GCU_USB_2_BIST_CTRL_BIST_EN_N_POS    0

#define MACSYS_GCU_USB_2_BIST_CTRL_TEST_LOOP_RST    0x0
#define MACSYS_GCU_USB_2_BIST_CTRL_BIST_EN_N_RST    0x1

static inline void macsys_gcu_usb_2_bist_ctrl_pack(struct cl_chip *chip, u8 test_loop, u8 bist_en_n)
{
	ASSERT_ERR_CHIP((((u32)test_loop << 1) & ~((u32)0x0000000E)) == 0);
	ASSERT_ERR_CHIP((((u32)bist_en_n << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_BIST_CTRL_ADDR, ((u32)test_loop << 1) | ((u32)bist_en_n << 0));
}

static inline void macsys_gcu_usb_2_bist_ctrl_unpack(struct cl_chip *chip, u8 *test_loop, u8 *bist_en_n)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_BIST_CTRL_ADDR);

	*test_loop = (local_val & ((u32)0x0000000E)) >> 1;
	*bist_en_n = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macsys_gcu_usb_2_bist_ctrl_test_loop_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_BIST_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x0000000E)) >> 1);
}

static inline void macsys_gcu_usb_2_bist_ctrl_test_loop_setf(struct cl_chip *chip, u8 testloop)
{
	ASSERT_ERR_CHIP((((u32)testloop << 1) & ~((u32)0x0000000E)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_BIST_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_BIST_CTRL_ADDR) & ~((u32)0x0000000E)) | ((u32)testloop << 1));
}

static inline u8 macsys_gcu_usb_2_bist_ctrl_bist_en_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_BIST_CTRL_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macsys_gcu_usb_2_bist_ctrl_bist_en_n_setf(struct cl_chip *chip, u8 bistenn)
{
	ASSERT_ERR_CHIP((((u32)bistenn << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_BIST_CTRL_ADDR, (cl_reg_read(chip, MACSYS_GCU_USB_2_BIST_CTRL_ADDR) & ~((u32)0x00000001)) | ((u32)bistenn << 0));
}

/**
 * @brief USB_2_BIST_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    BIST_ERR                  0
 *    00    BIST_DONE                 0
 * </pre>
 */
#define MACSYS_GCU_USB_2_BIST_STATUS_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001E4)
#define MACSYS_GCU_USB_2_BIST_STATUS_OFFSET      0x000001E4
#define MACSYS_GCU_USB_2_BIST_STATUS_INDEX       0x00000079
#define MACSYS_GCU_USB_2_BIST_STATUS_RESET       0x00000000

static inline u32 macsys_gcu_usb_2_bist_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_USB_2_BIST_STATUS_ADDR);
}

/* Field definitions */
#define MACSYS_GCU_USB_2_BIST_STATUS_BIST_ERR_BIT    ((u32)0x00000002)
#define MACSYS_GCU_USB_2_BIST_STATUS_BIST_ERR_POS    1
#define MACSYS_GCU_USB_2_BIST_STATUS_BIST_DONE_BIT    ((u32)0x00000001)
#define MACSYS_GCU_USB_2_BIST_STATUS_BIST_DONE_POS    0

#define MACSYS_GCU_USB_2_BIST_STATUS_BIST_ERR_RST    0x0
#define MACSYS_GCU_USB_2_BIST_STATUS_BIST_DONE_RST    0x0

static inline void macsys_gcu_usb_2_bist_status_unpack(struct cl_chip *chip, u8 *bist_err, u8 *bist_done)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_BIST_STATUS_ADDR);

	*bist_err = (local_val & ((u32)0x00000002)) >> 1;
	*bist_done = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macsys_gcu_usb_2_bist_status_bist_err_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_BIST_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline u8 macsys_gcu_usb_2_bist_status_bist_done_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_BIST_STATUS_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

/**
 * @brief WD_TIME register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 WD_TIME                   0x14
 * </pre>
 */
#define MACSYS_GCU_WD_TIME_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001E8)
#define MACSYS_GCU_WD_TIME_OFFSET      0x000001E8
#define MACSYS_GCU_WD_TIME_INDEX       0x0000007A
#define MACSYS_GCU_WD_TIME_RESET       0x00000014

static inline u32 macsys_gcu_wd_time_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_WD_TIME_ADDR);
}

static inline void macsys_gcu_wd_time_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_WD_TIME_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_WD_TIME_WD_TIME_MASK     ((u32)0x0000001F)
#define MACSYS_GCU_WD_TIME_WD_TIME_LSB      0
#define MACSYS_GCU_WD_TIME_WD_TIME_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_WD_TIME_WD_TIME_RST      0x14

static inline u8 macsys_gcu_wd_time_wd_time_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_WD_TIME_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macsys_gcu_wd_time_wd_time_setf(struct cl_chip *chip, u8 wdtime)
{
	ASSERT_ERR_CHIP((((u32)wdtime << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACSYS_GCU_WD_TIME_ADDR, (u32)wdtime << 0);
}

/**
 * @brief WD_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    WD_EN                     0
 * </pre>
 */
#define MACSYS_GCU_WD_EN_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001EC)
#define MACSYS_GCU_WD_EN_OFFSET      0x000001EC
#define MACSYS_GCU_WD_EN_INDEX       0x0000007B
#define MACSYS_GCU_WD_EN_RESET       0x00000000

static inline u32 macsys_gcu_wd_en_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_WD_EN_ADDR);
}

static inline void macsys_gcu_wd_en_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_WD_EN_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_WD_EN_WD_EN_BIT          ((u32)0x00000001)
#define MACSYS_GCU_WD_EN_WD_EN_POS          0

#define MACSYS_GCU_WD_EN_WD_EN_RST          0x0

static inline u8 macsys_gcu_wd_en_wd_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_WD_EN_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macsys_gcu_wd_en_wd_en_setf(struct cl_chip *chip, u8 wden)
{
	ASSERT_ERR_CHIP((((u32)wden << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_WD_EN_ADDR, (u32)wden << 0);
}

/**
 * @brief WD_REWIND register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    WD_REWIND                 0
 * </pre>
 */
#define MACSYS_GCU_WD_REWIND_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001F0)
#define MACSYS_GCU_WD_REWIND_OFFSET      0x000001F0
#define MACSYS_GCU_WD_REWIND_INDEX       0x0000007C
#define MACSYS_GCU_WD_REWIND_RESET       0x00000000

static inline void macsys_gcu_wd_rewind_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_WD_REWIND_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_WD_REWIND_WD_REWIND_BIT    ((u32)0x00000001)
#define MACSYS_GCU_WD_REWIND_WD_REWIND_POS    0

#define MACSYS_GCU_WD_REWIND_WD_REWIND_RST    0x0

static inline void macsys_gcu_wd_rewind_wd_rewind_setf(struct cl_chip *chip, u8 wdrewind)
{
	ASSERT_ERR_CHIP((((u32)wdrewind << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACSYS_GCU_WD_REWIND_ADDR, (u32)wdrewind << 0);
}

/**
 * @brief WD_DYN_TIME register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 WD_DYN_TIME               0x14
 * </pre>
 */
#define MACSYS_GCU_WD_DYN_TIME_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001F4)
#define MACSYS_GCU_WD_DYN_TIME_OFFSET      0x000001F4
#define MACSYS_GCU_WD_DYN_TIME_INDEX       0x0000007D
#define MACSYS_GCU_WD_DYN_TIME_RESET       0x00000014

static inline u32 macsys_gcu_wd_dyn_time_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_WD_DYN_TIME_ADDR);
}

/* Field definitions */
#define MACSYS_GCU_WD_DYN_TIME_WD_DYN_TIME_MASK    ((u32)0x0000001F)
#define MACSYS_GCU_WD_DYN_TIME_WD_DYN_TIME_LSB    0
#define MACSYS_GCU_WD_DYN_TIME_WD_DYN_TIME_WIDTH    ((u32)0x00000005)

#define MACSYS_GCU_WD_DYN_TIME_WD_DYN_TIME_RST    0x14

static inline u8 macsys_gcu_wd_dyn_time_wd_dyn_time_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_WD_DYN_TIME_ADDR);

	return (u8)(local_val >> 0);
}

/**
 * @brief USB_2_PHY_TEST_CONFIG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USB2_PHY_TEST_CONFIG0     0x0
 * </pre>
 */
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001F8)
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_OFFSET      0x000001F8
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_INDEX       0x0000007E
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_RESET       0x00000000

static inline u32 macsys_gcu_usb_2_phy_test_config_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_ADDR);
}

static inline void macsys_gcu_usb_2_phy_test_config_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_USB_2_PHY_TEST_CONFIG_0_MASK    ((u32)0xFFFFFFFF)
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_USB_2_PHY_TEST_CONFIG_0_LSB    0
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_USB_2_PHY_TEST_CONFIG_0_WIDTH    ((u32)0x00000020)

#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_USB_2_PHY_TEST_CONFIG_0_RST    0x0

static inline u32 macsys_gcu_usb_2_phy_test_config_0_usb_2_phy_test_config_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macsys_gcu_usb_2_phy_test_config_0_usb_2_phy_test_config_0_setf(struct cl_chip *chip, u32 usb2phytestconfig0)
{
	ASSERT_ERR_CHIP((((u32)usb2phytestconfig0 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_ADDR, (u32)usb2phytestconfig0 << 0);
}

/**
 * @brief USB_2_PHY_TEST_CONFIG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USB2_PHY_TEST_CONFIG1     0x0
 * </pre>
 */
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR + 0x000001FC)
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_OFFSET      0x000001FC
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_INDEX       0x0000007F
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_RESET       0x00000000

static inline u32 macsys_gcu_usb_2_phy_test_config_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_ADDR);
}

static inline void macsys_gcu_usb_2_phy_test_config_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_ADDR, value);
}

/* Field definitions */
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_USB_2_PHY_TEST_CONFIG_1_MASK    ((u32)0xFFFFFFFF)
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_USB_2_PHY_TEST_CONFIG_1_LSB    0
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_USB_2_PHY_TEST_CONFIG_1_WIDTH    ((u32)0x00000020)

#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_USB_2_PHY_TEST_CONFIG_1_RST    0x0

static inline u32 macsys_gcu_usb_2_phy_test_config_1_usb_2_phy_test_config_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macsys_gcu_usb_2_phy_test_config_1_usb_2_phy_test_config_1_setf(struct cl_chip *chip, u32 usb2phytestconfig1)
{
	ASSERT_ERR_CHIP((((u32)usb2phytestconfig1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_ADDR, (u32)usb2phytestconfig1 << 0);
}

#endif /* REG_MACSYS_GCU_H */
