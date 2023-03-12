#ifndef _REG_MACSYS_GCU_H_
#define _REG_MACSYS_GCU_H_

#include <stdint.h>
#include "_reg_macsys_gcu.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_MACSYS_GCU__H__FILEID__

#define REG_MACSYS_GCU_COUNT  77


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
#define MACSYS_GCU_CHIP_VERSION_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000050)
#define MACSYS_GCU_CHIP_VERSION_OFFSET      0x00000050
#define MACSYS_GCU_CHIP_VERSION_INDEX       0x00000014
#define MACSYS_GCU_CHIP_VERSION_RESET       0x006000A0

__INLINE uint32_t  macsys_gcu_chip_version_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CHIP_VERSION_ADDR);
}

// field definitions
#define MACSYS_GCU_CHIP_VERSION_PRODUCT_ID_MASK    ((uint32_t)0x00FFFF00)
#define MACSYS_GCU_CHIP_VERSION_PRODUCT_ID_LSB    8
#define MACSYS_GCU_CHIP_VERSION_PRODUCT_ID_WIDTH    ((uint32_t)0x00000010)
#define MACSYS_GCU_CHIP_VERSION_STEP_ID_MASK    ((uint32_t)0x000000F0)
#define MACSYS_GCU_CHIP_VERSION_STEP_ID_LSB    4
#define MACSYS_GCU_CHIP_VERSION_STEP_ID_WIDTH    ((uint32_t)0x00000004)
#define MACSYS_GCU_CHIP_VERSION_REV_ID_MASK    ((uint32_t)0x0000000F)
#define MACSYS_GCU_CHIP_VERSION_REV_ID_LSB    0
#define MACSYS_GCU_CHIP_VERSION_REV_ID_WIDTH    ((uint32_t)0x00000004)

#define MACSYS_GCU_CHIP_VERSION_PRODUCT_ID_RST    0x6000
#define MACSYS_GCU_CHIP_VERSION_STEP_ID_RST    0xA
#define MACSYS_GCU_CHIP_VERSION_REV_ID_RST    0x0

__INLINE void macsys_gcu_chip_version_unpack(uint16_t* product_id, uint8_t* step_id, uint8_t* rev_id)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CHIP_VERSION_ADDR);

	*product_id = (localVal & ((uint32_t)0x00FFFF00)) >>  8;
	*step_id = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*rev_id = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t macsys_gcu_chip_version_product_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CHIP_VERSION_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFFF00)) >> 8);
}
__INLINE uint8_t macsys_gcu_chip_version_step_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CHIP_VERSION_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t macsys_gcu_chip_version_rev_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CHIP_VERSION_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief PCIE_SLV_AWMISC_INFO_LSB register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SLV_AWMISC_INFO_HDR_34_DW_LSB 0x0
 * </pre>
 */
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000060)
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_OFFSET      0x00000060
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_INDEX       0x00000018
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_pcie_slv_awmisc_info_lsb_get(void)
{
	return REG_PL_RD(MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_ADDR);
}

__INLINE void macsys_gcu_pcie_slv_awmisc_info_lsb_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_ADDR, value);
}

// field definitions
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_SLV_AWMISC_INFO_HDR_34_DW_LSB_MASK    ((uint32_t)0xFFFFFFFF)
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_SLV_AWMISC_INFO_HDR_34_DW_LSB_LSB    0
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_SLV_AWMISC_INFO_HDR_34_DW_LSB_WIDTH    ((uint32_t)0x00000020)

#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_SLV_AWMISC_INFO_HDR_34_DW_LSB_RST    0x0

__INLINE uint32_t macsys_gcu_pcie_slv_awmisc_info_lsb_slv_awmisc_info_hdr_34_dw_lsb_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macsys_gcu_pcie_slv_awmisc_info_lsb_slv_awmisc_info_hdr_34_dw_lsb_setf(uint32_t slvawmiscinfohdr34dwlsb)
{
	ASSERT_ERR((((uint32_t)slvawmiscinfohdr34dwlsb << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_SLV_AWMISC_INFO_LSB_ADDR, (uint32_t)slvawmiscinfohdr34dwlsb << 0);
}

/**
 * @brief PCIE_SLV_AWMISC_INFO_MSB register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SLV_AWMISC_INFO_HDR_34_DW_MSB 0x0
 * </pre>
 */
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000064)
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_OFFSET      0x00000064
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_INDEX       0x00000019
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_pcie_slv_awmisc_info_msb_get(void)
{
	return REG_PL_RD(MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_ADDR);
}

__INLINE void macsys_gcu_pcie_slv_awmisc_info_msb_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_ADDR, value);
}

// field definitions
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_SLV_AWMISC_INFO_HDR_34_DW_MSB_MASK    ((uint32_t)0xFFFFFFFF)
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_SLV_AWMISC_INFO_HDR_34_DW_MSB_LSB    0
#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_SLV_AWMISC_INFO_HDR_34_DW_MSB_WIDTH    ((uint32_t)0x00000020)

#define MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_SLV_AWMISC_INFO_HDR_34_DW_MSB_RST    0x0

__INLINE uint32_t macsys_gcu_pcie_slv_awmisc_info_msb_slv_awmisc_info_hdr_34_dw_msb_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macsys_gcu_pcie_slv_awmisc_info_msb_slv_awmisc_info_hdr_34_dw_msb_setf(uint32_t slvawmiscinfohdr34dwmsb)
{
	ASSERT_ERR((((uint32_t)slvawmiscinfohdr34dwmsb << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_SLV_AWMISC_INFO_MSB_ADDR, (uint32_t)slvawmiscinfohdr34dwmsb << 0);
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
#define MACSYS_GCU_PCIE_GENERAL_CONF_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000068)
#define MACSYS_GCU_PCIE_GENERAL_CONF_OFFSET      0x00000068
#define MACSYS_GCU_PCIE_GENERAL_CONF_INDEX       0x0000001A
#define MACSYS_GCU_PCIE_GENERAL_CONF_RESET       0x00000958

__INLINE uint32_t  macsys_gcu_pcie_general_conf_get(void)
{
	return REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
}

__INLINE void macsys_gcu_pcie_general_conf_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, value);
}

// field definitions
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_CLK_PM_EN_BIT    ((uint32_t)0x00001000)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_CLK_PM_EN_POS    12
#define MACSYS_GCU_PCIE_GENERAL_CONF_AUX_CLK_ACTIVE_BIT    ((uint32_t)0x00000800)
#define MACSYS_GCU_PCIE_GENERAL_CONF_AUX_CLK_ACTIVE_POS    11
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_RETRY_EN_BIT    ((uint32_t)0x00000400)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_RETRY_EN_POS    10
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_INIT_RST_BIT    ((uint32_t)0x00000200)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_INIT_RST_POS    9
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_XFER_PENDING_BIT    ((uint32_t)0x00000100)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_XFER_PENDING_POS    8
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_EXIT_L_1_BIT    ((uint32_t)0x00000080)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_EXIT_L_1_POS    7
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_READY_ENTR_L_23_BIT    ((uint32_t)0x00000040)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_READY_ENTR_L_23_POS    6
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_ENTR_L_1_BIT    ((uint32_t)0x00000020)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_REQ_ENTR_L_1_POS    5
#define MACSYS_GCU_PCIE_GENERAL_CONF_PHY_CLK_REQ_N_BIT    ((uint32_t)0x00000010)
#define MACSYS_GCU_PCIE_GENERAL_CONF_PHY_CLK_REQ_N_POS    4
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_CLK_REQ_N_BIT    ((uint32_t)0x00000008)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APP_CLK_REQ_N_POS    3
#define MACSYS_GCU_PCIE_GENERAL_CONF_APPS_PM_XMT_PME_BIT    ((uint32_t)0x00000004)
#define MACSYS_GCU_PCIE_GENERAL_CONF_APPS_PM_XMT_PME_POS    2
#define MACSYS_GCU_PCIE_GENERAL_CONF_TX_LANE_FLIP_EN_BIT    ((uint32_t)0x00000002)
#define MACSYS_GCU_PCIE_GENERAL_CONF_TX_LANE_FLIP_EN_POS    1
#define MACSYS_GCU_PCIE_GENERAL_CONF_RX_LANE_FLIP_EN_BIT    ((uint32_t)0x00000001)
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

__INLINE void macsys_gcu_pcie_general_conf_pack(uint8_t app_clk_pm_en, uint8_t aux_clk_active, uint8_t app_req_retry_en, uint8_t app_init_rst, uint8_t app_xfer_pending, uint8_t app_req_exit_l1, uint8_t app_ready_entr_l23, uint8_t app_req_entr_l1, uint8_t phy_clk_req_n, uint8_t app_clk_req_n, uint8_t apps_pm_xmt_pme, uint8_t tx_lane_flip_en, uint8_t rx_lane_flip_en)
{
	ASSERT_ERR((((uint32_t)app_clk_pm_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)aux_clk_active << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)app_req_retry_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)app_init_rst << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)app_xfer_pending << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)app_req_exit_l1 << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)app_ready_entr_l23 << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)app_req_entr_l1 << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)phy_clk_req_n << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)app_clk_req_n << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)apps_pm_xmt_pme << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)tx_lane_flip_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)rx_lane_flip_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR,  ((uint32_t)app_clk_pm_en << 12) |((uint32_t)aux_clk_active << 11) |((uint32_t)app_req_retry_en << 10) |((uint32_t)app_init_rst << 9) |((uint32_t)app_xfer_pending << 8) |((uint32_t)app_req_exit_l1 << 7) |((uint32_t)app_ready_entr_l23 << 6) |((uint32_t)app_req_entr_l1 << 5) |((uint32_t)phy_clk_req_n << 4) |((uint32_t)app_clk_req_n << 3) |((uint32_t)apps_pm_xmt_pme << 2) |((uint32_t)tx_lane_flip_en << 1) |((uint32_t)rx_lane_flip_en << 0));
}

__INLINE void macsys_gcu_pcie_general_conf_unpack(uint8_t* app_clk_pm_en, uint8_t* aux_clk_active, uint8_t* app_req_retry_en, uint8_t* app_init_rst, uint8_t* app_xfer_pending, uint8_t* app_req_exit_l1, uint8_t* app_ready_entr_l23, uint8_t* app_req_entr_l1, uint8_t* phy_clk_req_n, uint8_t* app_clk_req_n, uint8_t* apps_pm_xmt_pme, uint8_t* tx_lane_flip_en, uint8_t* rx_lane_flip_en)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);

	*app_clk_pm_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*aux_clk_active = (localVal & ((uint32_t)0x00000800)) >>  11;
	*app_req_retry_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*app_init_rst = (localVal & ((uint32_t)0x00000200)) >>  9;
	*app_xfer_pending = (localVal & ((uint32_t)0x00000100)) >>  8;
	*app_req_exit_l1 = (localVal & ((uint32_t)0x00000080)) >>  7;
	*app_ready_entr_l23 = (localVal & ((uint32_t)0x00000040)) >>  6;
	*app_req_entr_l1 = (localVal & ((uint32_t)0x00000020)) >>  5;
	*phy_clk_req_n = (localVal & ((uint32_t)0x00000010)) >>  4;
	*app_clk_req_n = (localVal & ((uint32_t)0x00000008)) >>  3;
	*apps_pm_xmt_pme = (localVal & ((uint32_t)0x00000004)) >>  2;
	*tx_lane_flip_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rx_lane_flip_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macsys_gcu_pcie_general_conf_app_clk_pm_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void macsys_gcu_pcie_general_conf_app_clk_pm_en_setf(uint8_t appclkpmen)
{
	ASSERT_ERR((((uint32_t)appclkpmen << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)appclkpmen <<12));
}
__INLINE uint8_t macsys_gcu_pcie_general_conf_aux_clk_active_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void macsys_gcu_pcie_general_conf_aux_clk_active_setf(uint8_t auxclkactive)
{
	ASSERT_ERR((((uint32_t)auxclkactive << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)auxclkactive <<11));
}
__INLINE uint8_t macsys_gcu_pcie_general_conf_app_req_retry_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void macsys_gcu_pcie_general_conf_app_req_retry_en_setf(uint8_t appreqretryen)
{
	ASSERT_ERR((((uint32_t)appreqretryen << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)appreqretryen <<10));
}
__INLINE uint8_t macsys_gcu_pcie_general_conf_app_init_rst_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void macsys_gcu_pcie_general_conf_app_init_rst_setf(uint8_t appinitrst)
{
	ASSERT_ERR((((uint32_t)appinitrst << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)appinitrst <<9));
}
__INLINE uint8_t macsys_gcu_pcie_general_conf_app_xfer_pending_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void macsys_gcu_pcie_general_conf_app_xfer_pending_setf(uint8_t appxferpending)
{
	ASSERT_ERR((((uint32_t)appxferpending << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)appxferpending <<8));
}
__INLINE uint8_t macsys_gcu_pcie_general_conf_app_req_exit_l_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void macsys_gcu_pcie_general_conf_app_req_exit_l_1_setf(uint8_t appreqexitl1)
{
	ASSERT_ERR((((uint32_t)appreqexitl1 << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)appreqexitl1 <<7));
}
__INLINE uint8_t macsys_gcu_pcie_general_conf_app_ready_entr_l_23_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void macsys_gcu_pcie_general_conf_app_ready_entr_l_23_setf(uint8_t appreadyentrl23)
{
	ASSERT_ERR((((uint32_t)appreadyentrl23 << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)appreadyentrl23 <<6));
}
__INLINE uint8_t macsys_gcu_pcie_general_conf_app_req_entr_l_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void macsys_gcu_pcie_general_conf_app_req_entr_l_1_setf(uint8_t appreqentrl1)
{
	ASSERT_ERR((((uint32_t)appreqentrl1 << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)appreqentrl1 <<5));
}
__INLINE uint8_t macsys_gcu_pcie_general_conf_phy_clk_req_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void macsys_gcu_pcie_general_conf_phy_clk_req_n_setf(uint8_t phyclkreqn)
{
	ASSERT_ERR((((uint32_t)phyclkreqn << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)phyclkreqn <<4));
}
__INLINE uint8_t macsys_gcu_pcie_general_conf_app_clk_req_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void macsys_gcu_pcie_general_conf_app_clk_req_n_setf(uint8_t appclkreqn)
{
	ASSERT_ERR((((uint32_t)appclkreqn << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)appclkreqn <<3));
}
__INLINE uint8_t macsys_gcu_pcie_general_conf_apps_pm_xmt_pme_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void macsys_gcu_pcie_general_conf_apps_pm_xmt_pme_setf(uint8_t appspmxmtpme)
{
	ASSERT_ERR((((uint32_t)appspmxmtpme << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)appspmxmtpme <<2));
}
__INLINE uint8_t macsys_gcu_pcie_general_conf_tx_lane_flip_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void macsys_gcu_pcie_general_conf_tx_lane_flip_en_setf(uint8_t txlaneflipen)
{
	ASSERT_ERR((((uint32_t)txlaneflipen << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)txlaneflipen <<1));
}
__INLINE uint8_t macsys_gcu_pcie_general_conf_rx_lane_flip_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macsys_gcu_pcie_general_conf_rx_lane_flip_en_setf(uint8_t rxlaneflipen)
{
	ASSERT_ERR((((uint32_t)rxlaneflipen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_GENERAL_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rxlaneflipen <<0));
}

/**
 * @brief PCIE_PHY_BOOTER_DONE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    PCIE_PHY_BOOTER_DONE      0              
 * </pre>
 */
#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x0000006C)
#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_OFFSET      0x0000006C
#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_INDEX       0x0000001B
#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_pcie_phy_booter_done_get(void)
{
	return REG_PL_RD(MACSYS_GCU_PCIE_PHY_BOOTER_DONE_ADDR);
}

__INLINE void macsys_gcu_pcie_phy_booter_done_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_PCIE_PHY_BOOTER_DONE_ADDR, value);
}

// field definitions
#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_PCIE_PHY_BOOTER_DONE_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_PCIE_PHY_BOOTER_DONE_POS    0

#define MACSYS_GCU_PCIE_PHY_BOOTER_DONE_PCIE_PHY_BOOTER_DONE_RST    0x0

__INLINE uint8_t macsys_gcu_pcie_phy_booter_done_pcie_phy_booter_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_PHY_BOOTER_DONE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macsys_gcu_pcie_phy_booter_done_pcie_phy_booter_done_setf(uint8_t pciephybooterdone)
{
	ASSERT_ERR((((uint32_t)pciephybooterdone << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_PHY_BOOTER_DONE_ADDR, (uint32_t)pciephybooterdone << 0);
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
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000070)
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_OFFSET      0x00000070
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_INDEX       0x0000001C
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_pcie_app_ltssm_en_get(void)
{
	return REG_PL_RD(MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR);
}

__INLINE void macsys_gcu_pcie_app_ltssm_en_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR, value);
}

// field definitions
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_PCIE_BLOCK_RESET_BIT    ((uint32_t)0x00000002)
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_PCIE_BLOCK_RESET_POS    1
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_PCIE_APP_LTSS_EN_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_PCIE_APP_LTSS_EN_POS    0

#define MACSYS_GCU_PCIE_APP_LTSSM_EN_PCIE_BLOCK_RESET_RST    0x0
#define MACSYS_GCU_PCIE_APP_LTSSM_EN_PCIE_APP_LTSS_EN_RST    0x0

__INLINE void macsys_gcu_pcie_app_ltssm_en_pack(uint8_t pcie_block_reset, uint8_t pcie_app_ltss_en)
{
	ASSERT_ERR((((uint32_t)pcie_block_reset << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)pcie_app_ltss_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR,  ((uint32_t)pcie_block_reset << 1) |((uint32_t)pcie_app_ltss_en << 0));
}

__INLINE void macsys_gcu_pcie_app_ltssm_en_unpack(uint8_t* pcie_block_reset, uint8_t* pcie_app_ltss_en)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR);

	*pcie_block_reset = (localVal & ((uint32_t)0x00000002)) >>  1;
	*pcie_app_ltss_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macsys_gcu_pcie_app_ltssm_en_pcie_block_reset_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void macsys_gcu_pcie_app_ltssm_en_pcie_block_reset_setf(uint8_t pcieblockreset)
{
	ASSERT_ERR((((uint32_t)pcieblockreset << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)pcieblockreset <<1));
}
__INLINE uint8_t macsys_gcu_pcie_app_ltssm_en_pcie_app_ltss_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macsys_gcu_pcie_app_ltssm_en_pcie_app_ltss_en_setf(uint8_t pcieappltssen)
{
	ASSERT_ERR((((uint32_t)pcieappltssen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_APP_LTSSM_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)pcieappltssen <<0));
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
#define MACSYS_GCU_PCIE_CONF_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000080)
#define MACSYS_GCU_PCIE_CONF_0_OFFSET      0x00000080
#define MACSYS_GCU_PCIE_CONF_0_INDEX       0x00000020
#define MACSYS_GCU_PCIE_CONF_0_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_pcie_conf_0_get(void)
{
	return REG_PL_RD(MACSYS_GCU_PCIE_CONF_0_ADDR);
}

__INLINE void macsys_gcu_pcie_conf_0_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_PCIE_CONF_0_ADDR, value);
}

// field definitions
#define MACSYS_GCU_PCIE_CONF_0_PCIE_OPT_EN_BIT    ((uint32_t)0x00400000)
#define MACSYS_GCU_PCIE_CONF_0_PCIE_OPT_EN_POS    22
#define MACSYS_GCU_PCIE_CONF_0_SLV_AWMISC_INFO_MASK    ((uint32_t)0x003FFFFF)
#define MACSYS_GCU_PCIE_CONF_0_SLV_AWMISC_INFO_LSB    0
#define MACSYS_GCU_PCIE_CONF_0_SLV_AWMISC_INFO_WIDTH    ((uint32_t)0x00000016)

#define MACSYS_GCU_PCIE_CONF_0_PCIE_OPT_EN_RST    0x0
#define MACSYS_GCU_PCIE_CONF_0_SLV_AWMISC_INFO_RST    0x0

__INLINE void macsys_gcu_pcie_conf_0_pack(uint8_t pcie_opt_en, uint32_t slv_awmisc_info)
{
	ASSERT_ERR((((uint32_t)pcie_opt_en << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)slv_awmisc_info << 0) & ~((uint32_t)0x003FFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_CONF_0_ADDR,  ((uint32_t)pcie_opt_en << 22) |((uint32_t)slv_awmisc_info << 0));
}

__INLINE void macsys_gcu_pcie_conf_0_unpack(uint8_t* pcie_opt_en, uint32_t* slv_awmisc_info)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_CONF_0_ADDR);

	*pcie_opt_en = (localVal & ((uint32_t)0x00400000)) >>  22;
	*slv_awmisc_info = (localVal & ((uint32_t)0x003FFFFF)) >>  0;
}

__INLINE uint8_t macsys_gcu_pcie_conf_0_pcie_opt_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void macsys_gcu_pcie_conf_0_pcie_opt_en_setf(uint8_t pcieopten)
{
	ASSERT_ERR((((uint32_t)pcieopten << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_CONF_0_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_CONF_0_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)pcieopten <<22));
}
__INLINE uint32_t macsys_gcu_pcie_conf_0_slv_awmisc_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_CONF_0_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0x003FFFFF)) >> 0);
}
__INLINE void macsys_gcu_pcie_conf_0_slv_awmisc_info_setf(uint32_t slvawmiscinfo)
{
	ASSERT_ERR((((uint32_t)slvawmiscinfo << 0) & ~((uint32_t)0x003FFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_CONF_0_ADDR, (REG_PL_RD(MACSYS_GCU_PCIE_CONF_0_ADDR) & ~((uint32_t)0x003FFFFF)) | ((uint32_t)slvawmiscinfo <<0));
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
#define MACSYS_GCU_PCIE_CONF_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000084)
#define MACSYS_GCU_PCIE_CONF_1_OFFSET      0x00000084
#define MACSYS_GCU_PCIE_CONF_1_INDEX       0x00000021
#define MACSYS_GCU_PCIE_CONF_1_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_pcie_conf_1_get(void)
{
	return REG_PL_RD(MACSYS_GCU_PCIE_CONF_1_ADDR);
}

__INLINE void macsys_gcu_pcie_conf_1_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_PCIE_CONF_1_ADDR, value);
}

// field definitions
#define MACSYS_GCU_PCIE_CONF_1_SLV_ARMISC_INFO_MASK    ((uint32_t)0x003FFFFF)
#define MACSYS_GCU_PCIE_CONF_1_SLV_ARMISC_INFO_LSB    0
#define MACSYS_GCU_PCIE_CONF_1_SLV_ARMISC_INFO_WIDTH    ((uint32_t)0x00000016)

#define MACSYS_GCU_PCIE_CONF_1_SLV_ARMISC_INFO_RST    0x0

__INLINE uint32_t macsys_gcu_pcie_conf_1_slv_armisc_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_CONF_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macsys_gcu_pcie_conf_1_slv_armisc_info_setf(uint32_t slvarmiscinfo)
{
	ASSERT_ERR((((uint32_t)slvarmiscinfo << 0) & ~((uint32_t)0x003FFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_CONF_1_ADDR, (uint32_t)slvarmiscinfo << 0);
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
#define MACSYS_GCU_PCIE_WAKEUP_CMD_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000088)
#define MACSYS_GCU_PCIE_WAKEUP_CMD_OFFSET      0x00000088
#define MACSYS_GCU_PCIE_WAKEUP_CMD_INDEX       0x00000022
#define MACSYS_GCU_PCIE_WAKEUP_CMD_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_pcie_wakeup_cmd_get(void)
{
	return REG_PL_RD(MACSYS_GCU_PCIE_WAKEUP_CMD_ADDR);
}

__INLINE void macsys_gcu_pcie_wakeup_cmd_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_PCIE_WAKEUP_CMD_ADDR, value);
}

// field definitions
#define MACSYS_GCU_PCIE_WAKEUP_CMD_OUTBAND_PWRUP_CMD_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_PCIE_WAKEUP_CMD_OUTBAND_PWRUP_CMD_POS    0

#define MACSYS_GCU_PCIE_WAKEUP_CMD_OUTBAND_PWRUP_CMD_RST    0x0

__INLINE uint8_t macsys_gcu_pcie_wakeup_cmd_outband_pwrup_cmd_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PCIE_WAKEUP_CMD_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macsys_gcu_pcie_wakeup_cmd_outband_pwrup_cmd_setf(uint8_t outbandpwrupcmd)
{
	ASSERT_ERR((((uint32_t)outbandpwrupcmd << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_PCIE_WAKEUP_CMD_ADDR, (uint32_t)outbandpwrupcmd << 0);
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
#define MACSYS_GCU_CYC_BUF_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000A0)
#define MACSYS_GCU_CYC_BUF_0_OFFSET      0x000000A0
#define MACSYS_GCU_CYC_BUF_0_INDEX       0x00000028
#define MACSYS_GCU_CYC_BUF_0_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_0_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_0_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_0_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_0_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_0_CYC_BUF_0_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_0_pack(uint16_t cyc_buf_0_base, uint8_t cyc_buf_0_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_0_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_0_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_0_ADDR,  ((uint32_t)cyc_buf_0_base << 12) |((uint32_t)cyc_buf_0_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_0_unpack(uint16_t* cyc_buf_0_base, uint8_t* cyc_buf_0_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_0_ADDR);

	*cyc_buf_0_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_0_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_0_cyc_buf_0_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_0_cyc_buf_0_base_setf(uint16_t cycbuf0base)
{
	ASSERT_ERR((((uint32_t)cycbuf0base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_0_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_0_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf0base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_0_cyc_buf_0_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_0_cyc_buf_0_size_setf(uint8_t cycbuf0size)
{
	ASSERT_ERR((((uint32_t)cycbuf0size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_0_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_0_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf0size <<0));
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
#define MACSYS_GCU_CYC_BUF_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000A4)
#define MACSYS_GCU_CYC_BUF_1_OFFSET      0x000000A4
#define MACSYS_GCU_CYC_BUF_1_INDEX       0x00000029
#define MACSYS_GCU_CYC_BUF_1_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_1_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_1_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_1_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_1_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_1_CYC_BUF_1_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_1_pack(uint16_t cyc_buf_1_base, uint8_t cyc_buf_1_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_1_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_1_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_1_ADDR,  ((uint32_t)cyc_buf_1_base << 12) |((uint32_t)cyc_buf_1_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_1_unpack(uint16_t* cyc_buf_1_base, uint8_t* cyc_buf_1_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_1_ADDR);

	*cyc_buf_1_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_1_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_1_cyc_buf_1_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_1_cyc_buf_1_base_setf(uint16_t cycbuf1base)
{
	ASSERT_ERR((((uint32_t)cycbuf1base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_1_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_1_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf1base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_1_cyc_buf_1_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_1_cyc_buf_1_size_setf(uint8_t cycbuf1size)
{
	ASSERT_ERR((((uint32_t)cycbuf1size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_1_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_1_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf1size <<0));
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
#define MACSYS_GCU_CYC_BUF_2_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000A8)
#define MACSYS_GCU_CYC_BUF_2_OFFSET      0x000000A8
#define MACSYS_GCU_CYC_BUF_2_INDEX       0x0000002A
#define MACSYS_GCU_CYC_BUF_2_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_2_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_2_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_2_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_2_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_2_CYC_BUF_2_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_2_pack(uint16_t cyc_buf_2_base, uint8_t cyc_buf_2_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_2_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_2_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_2_ADDR,  ((uint32_t)cyc_buf_2_base << 12) |((uint32_t)cyc_buf_2_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_2_unpack(uint16_t* cyc_buf_2_base, uint8_t* cyc_buf_2_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_2_ADDR);

	*cyc_buf_2_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_2_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_2_cyc_buf_2_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_2_cyc_buf_2_base_setf(uint16_t cycbuf2base)
{
	ASSERT_ERR((((uint32_t)cycbuf2base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_2_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_2_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf2base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_2_cyc_buf_2_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_2_cyc_buf_2_size_setf(uint8_t cycbuf2size)
{
	ASSERT_ERR((((uint32_t)cycbuf2size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_2_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_2_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf2size <<0));
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
#define MACSYS_GCU_CYC_BUF_3_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000AC)
#define MACSYS_GCU_CYC_BUF_3_OFFSET      0x000000AC
#define MACSYS_GCU_CYC_BUF_3_INDEX       0x0000002B
#define MACSYS_GCU_CYC_BUF_3_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_3_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_3_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_3_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_3_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_3_CYC_BUF_3_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_3_pack(uint16_t cyc_buf_3_base, uint8_t cyc_buf_3_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_3_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_3_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_3_ADDR,  ((uint32_t)cyc_buf_3_base << 12) |((uint32_t)cyc_buf_3_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_3_unpack(uint16_t* cyc_buf_3_base, uint8_t* cyc_buf_3_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_3_ADDR);

	*cyc_buf_3_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_3_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_3_cyc_buf_3_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_3_cyc_buf_3_base_setf(uint16_t cycbuf3base)
{
	ASSERT_ERR((((uint32_t)cycbuf3base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_3_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_3_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf3base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_3_cyc_buf_3_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_3_cyc_buf_3_size_setf(uint8_t cycbuf3size)
{
	ASSERT_ERR((((uint32_t)cycbuf3size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_3_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_3_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf3size <<0));
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
#define MACSYS_GCU_CYC_BUF_4_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000B0)
#define MACSYS_GCU_CYC_BUF_4_OFFSET      0x000000B0
#define MACSYS_GCU_CYC_BUF_4_INDEX       0x0000002C
#define MACSYS_GCU_CYC_BUF_4_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_4_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_4_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_4_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_4_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_4_CYC_BUF_4_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_4_pack(uint16_t cyc_buf_4_base, uint8_t cyc_buf_4_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_4_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_4_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_4_ADDR,  ((uint32_t)cyc_buf_4_base << 12) |((uint32_t)cyc_buf_4_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_4_unpack(uint16_t* cyc_buf_4_base, uint8_t* cyc_buf_4_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_4_ADDR);

	*cyc_buf_4_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_4_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_4_cyc_buf_4_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_4_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_4_cyc_buf_4_base_setf(uint16_t cycbuf4base)
{
	ASSERT_ERR((((uint32_t)cycbuf4base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_4_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_4_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf4base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_4_cyc_buf_4_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_4_cyc_buf_4_size_setf(uint8_t cycbuf4size)
{
	ASSERT_ERR((((uint32_t)cycbuf4size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_4_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_4_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf4size <<0));
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
#define MACSYS_GCU_CYC_BUF_5_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000B4)
#define MACSYS_GCU_CYC_BUF_5_OFFSET      0x000000B4
#define MACSYS_GCU_CYC_BUF_5_INDEX       0x0000002D
#define MACSYS_GCU_CYC_BUF_5_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_5_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_5_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_5_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_5_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_5_CYC_BUF_5_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_5_pack(uint16_t cyc_buf_5_base, uint8_t cyc_buf_5_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_5_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_5_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_5_ADDR,  ((uint32_t)cyc_buf_5_base << 12) |((uint32_t)cyc_buf_5_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_5_unpack(uint16_t* cyc_buf_5_base, uint8_t* cyc_buf_5_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_5_ADDR);

	*cyc_buf_5_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_5_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_5_cyc_buf_5_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_5_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_5_cyc_buf_5_base_setf(uint16_t cycbuf5base)
{
	ASSERT_ERR((((uint32_t)cycbuf5base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_5_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_5_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf5base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_5_cyc_buf_5_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_5_cyc_buf_5_size_setf(uint8_t cycbuf5size)
{
	ASSERT_ERR((((uint32_t)cycbuf5size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_5_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_5_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf5size <<0));
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
#define MACSYS_GCU_CYC_BUF_6_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000B8)
#define MACSYS_GCU_CYC_BUF_6_OFFSET      0x000000B8
#define MACSYS_GCU_CYC_BUF_6_INDEX       0x0000002E
#define MACSYS_GCU_CYC_BUF_6_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_6_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_6_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_6_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_6_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_6_CYC_BUF_6_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_6_pack(uint16_t cyc_buf_6_base, uint8_t cyc_buf_6_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_6_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_6_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_6_ADDR,  ((uint32_t)cyc_buf_6_base << 12) |((uint32_t)cyc_buf_6_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_6_unpack(uint16_t* cyc_buf_6_base, uint8_t* cyc_buf_6_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_6_ADDR);

	*cyc_buf_6_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_6_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_6_cyc_buf_6_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_6_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_6_cyc_buf_6_base_setf(uint16_t cycbuf6base)
{
	ASSERT_ERR((((uint32_t)cycbuf6base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_6_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_6_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf6base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_6_cyc_buf_6_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_6_cyc_buf_6_size_setf(uint8_t cycbuf6size)
{
	ASSERT_ERR((((uint32_t)cycbuf6size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_6_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_6_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf6size <<0));
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
#define MACSYS_GCU_CYC_BUF_7_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000BC)
#define MACSYS_GCU_CYC_BUF_7_OFFSET      0x000000BC
#define MACSYS_GCU_CYC_BUF_7_INDEX       0x0000002F
#define MACSYS_GCU_CYC_BUF_7_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_7_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_7_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_7_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_7_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_7_CYC_BUF_7_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_7_pack(uint16_t cyc_buf_7_base, uint8_t cyc_buf_7_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_7_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_7_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_7_ADDR,  ((uint32_t)cyc_buf_7_base << 12) |((uint32_t)cyc_buf_7_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_7_unpack(uint16_t* cyc_buf_7_base, uint8_t* cyc_buf_7_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_7_ADDR);

	*cyc_buf_7_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_7_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_7_cyc_buf_7_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_7_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_7_cyc_buf_7_base_setf(uint16_t cycbuf7base)
{
	ASSERT_ERR((((uint32_t)cycbuf7base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_7_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_7_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf7base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_7_cyc_buf_7_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_7_cyc_buf_7_size_setf(uint8_t cycbuf7size)
{
	ASSERT_ERR((((uint32_t)cycbuf7size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_7_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_7_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf7size <<0));
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
#define MACSYS_GCU_CYC_BUF_8_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000C0)
#define MACSYS_GCU_CYC_BUF_8_OFFSET      0x000000C0
#define MACSYS_GCU_CYC_BUF_8_INDEX       0x00000030
#define MACSYS_GCU_CYC_BUF_8_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_8_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_8_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_8_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_8_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_8_CYC_BUF_8_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_8_pack(uint16_t cyc_buf_8_base, uint8_t cyc_buf_8_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_8_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_8_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_8_ADDR,  ((uint32_t)cyc_buf_8_base << 12) |((uint32_t)cyc_buf_8_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_8_unpack(uint16_t* cyc_buf_8_base, uint8_t* cyc_buf_8_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_8_ADDR);

	*cyc_buf_8_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_8_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_8_cyc_buf_8_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_8_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_8_cyc_buf_8_base_setf(uint16_t cycbuf8base)
{
	ASSERT_ERR((((uint32_t)cycbuf8base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_8_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_8_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf8base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_8_cyc_buf_8_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_8_cyc_buf_8_size_setf(uint8_t cycbuf8size)
{
	ASSERT_ERR((((uint32_t)cycbuf8size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_8_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_8_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf8size <<0));
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
#define MACSYS_GCU_CYC_BUF_9_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000C4)
#define MACSYS_GCU_CYC_BUF_9_OFFSET      0x000000C4
#define MACSYS_GCU_CYC_BUF_9_INDEX       0x00000031
#define MACSYS_GCU_CYC_BUF_9_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_9_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_9_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_9_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_9_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_9_CYC_BUF_9_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_9_pack(uint16_t cyc_buf_9_base, uint8_t cyc_buf_9_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_9_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_9_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_9_ADDR,  ((uint32_t)cyc_buf_9_base << 12) |((uint32_t)cyc_buf_9_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_9_unpack(uint16_t* cyc_buf_9_base, uint8_t* cyc_buf_9_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_9_ADDR);

	*cyc_buf_9_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_9_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_9_cyc_buf_9_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_9_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_9_cyc_buf_9_base_setf(uint16_t cycbuf9base)
{
	ASSERT_ERR((((uint32_t)cycbuf9base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_9_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_9_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf9base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_9_cyc_buf_9_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_9_cyc_buf_9_size_setf(uint8_t cycbuf9size)
{
	ASSERT_ERR((((uint32_t)cycbuf9size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_9_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_9_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf9size <<0));
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
#define MACSYS_GCU_CYC_BUF_10_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000C8)
#define MACSYS_GCU_CYC_BUF_10_OFFSET      0x000000C8
#define MACSYS_GCU_CYC_BUF_10_INDEX       0x00000032
#define MACSYS_GCU_CYC_BUF_10_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_10_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_10_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_10_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_10_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_10_CYC_BUF_10_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_10_pack(uint16_t cyc_buf_10_base, uint8_t cyc_buf_10_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_10_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_10_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_10_ADDR,  ((uint32_t)cyc_buf_10_base << 12) |((uint32_t)cyc_buf_10_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_10_unpack(uint16_t* cyc_buf_10_base, uint8_t* cyc_buf_10_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_10_ADDR);

	*cyc_buf_10_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_10_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_10_cyc_buf_10_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_10_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_10_cyc_buf_10_base_setf(uint16_t cycbuf10base)
{
	ASSERT_ERR((((uint32_t)cycbuf10base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_10_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_10_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf10base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_10_cyc_buf_10_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_10_cyc_buf_10_size_setf(uint8_t cycbuf10size)
{
	ASSERT_ERR((((uint32_t)cycbuf10size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_10_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_10_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf10size <<0));
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
#define MACSYS_GCU_CYC_BUF_11_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000CC)
#define MACSYS_GCU_CYC_BUF_11_OFFSET      0x000000CC
#define MACSYS_GCU_CYC_BUF_11_INDEX       0x00000033
#define MACSYS_GCU_CYC_BUF_11_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_11_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_11_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_11_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_11_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_11_CYC_BUF_11_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_11_pack(uint16_t cyc_buf_11_base, uint8_t cyc_buf_11_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_11_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_11_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_11_ADDR,  ((uint32_t)cyc_buf_11_base << 12) |((uint32_t)cyc_buf_11_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_11_unpack(uint16_t* cyc_buf_11_base, uint8_t* cyc_buf_11_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_11_ADDR);

	*cyc_buf_11_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_11_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_11_cyc_buf_11_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_11_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_11_cyc_buf_11_base_setf(uint16_t cycbuf11base)
{
	ASSERT_ERR((((uint32_t)cycbuf11base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_11_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_11_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf11base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_11_cyc_buf_11_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_11_cyc_buf_11_size_setf(uint8_t cycbuf11size)
{
	ASSERT_ERR((((uint32_t)cycbuf11size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_11_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_11_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf11size <<0));
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
#define MACSYS_GCU_CYC_BUF_12_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000D0)
#define MACSYS_GCU_CYC_BUF_12_OFFSET      0x000000D0
#define MACSYS_GCU_CYC_BUF_12_INDEX       0x00000034
#define MACSYS_GCU_CYC_BUF_12_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_12_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_12_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_12_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_12_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_12_CYC_BUF_12_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_12_pack(uint16_t cyc_buf_12_base, uint8_t cyc_buf_12_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_12_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_12_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_12_ADDR,  ((uint32_t)cyc_buf_12_base << 12) |((uint32_t)cyc_buf_12_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_12_unpack(uint16_t* cyc_buf_12_base, uint8_t* cyc_buf_12_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_12_ADDR);

	*cyc_buf_12_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_12_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_12_cyc_buf_12_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_12_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_12_cyc_buf_12_base_setf(uint16_t cycbuf12base)
{
	ASSERT_ERR((((uint32_t)cycbuf12base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_12_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_12_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf12base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_12_cyc_buf_12_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_12_cyc_buf_12_size_setf(uint8_t cycbuf12size)
{
	ASSERT_ERR((((uint32_t)cycbuf12size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_12_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_12_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf12size <<0));
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
#define MACSYS_GCU_CYC_BUF_13_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000D4)
#define MACSYS_GCU_CYC_BUF_13_OFFSET      0x000000D4
#define MACSYS_GCU_CYC_BUF_13_INDEX       0x00000035
#define MACSYS_GCU_CYC_BUF_13_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_13_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_13_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_13_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_13_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_13_CYC_BUF_13_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_13_pack(uint16_t cyc_buf_13_base, uint8_t cyc_buf_13_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_13_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_13_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_13_ADDR,  ((uint32_t)cyc_buf_13_base << 12) |((uint32_t)cyc_buf_13_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_13_unpack(uint16_t* cyc_buf_13_base, uint8_t* cyc_buf_13_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_13_ADDR);

	*cyc_buf_13_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_13_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_13_cyc_buf_13_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_13_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_13_cyc_buf_13_base_setf(uint16_t cycbuf13base)
{
	ASSERT_ERR((((uint32_t)cycbuf13base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_13_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_13_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf13base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_13_cyc_buf_13_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_13_cyc_buf_13_size_setf(uint8_t cycbuf13size)
{
	ASSERT_ERR((((uint32_t)cycbuf13size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_13_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_13_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf13size <<0));
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
#define MACSYS_GCU_CYC_BUF_14_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000D8)
#define MACSYS_GCU_CYC_BUF_14_OFFSET      0x000000D8
#define MACSYS_GCU_CYC_BUF_14_INDEX       0x00000036
#define MACSYS_GCU_CYC_BUF_14_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_14_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_14_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_14_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_14_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_14_CYC_BUF_14_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_14_pack(uint16_t cyc_buf_14_base, uint8_t cyc_buf_14_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_14_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_14_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_14_ADDR,  ((uint32_t)cyc_buf_14_base << 12) |((uint32_t)cyc_buf_14_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_14_unpack(uint16_t* cyc_buf_14_base, uint8_t* cyc_buf_14_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_14_ADDR);

	*cyc_buf_14_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_14_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_14_cyc_buf_14_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_14_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_14_cyc_buf_14_base_setf(uint16_t cycbuf14base)
{
	ASSERT_ERR((((uint32_t)cycbuf14base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_14_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_14_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf14base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_14_cyc_buf_14_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_14_cyc_buf_14_size_setf(uint8_t cycbuf14size)
{
	ASSERT_ERR((((uint32_t)cycbuf14size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_14_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_14_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf14size <<0));
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
#define MACSYS_GCU_CYC_BUF_15_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000DC)
#define MACSYS_GCU_CYC_BUF_15_OFFSET      0x000000DC
#define MACSYS_GCU_CYC_BUF_15_INDEX       0x00000037
#define MACSYS_GCU_CYC_BUF_15_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_15_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_15_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_15_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_15_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_15_CYC_BUF_15_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_15_pack(uint16_t cyc_buf_15_base, uint8_t cyc_buf_15_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_15_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_15_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_15_ADDR,  ((uint32_t)cyc_buf_15_base << 12) |((uint32_t)cyc_buf_15_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_15_unpack(uint16_t* cyc_buf_15_base, uint8_t* cyc_buf_15_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_15_ADDR);

	*cyc_buf_15_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_15_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_15_cyc_buf_15_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_15_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_15_cyc_buf_15_base_setf(uint16_t cycbuf15base)
{
	ASSERT_ERR((((uint32_t)cycbuf15base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_15_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_15_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf15base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_15_cyc_buf_15_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_15_cyc_buf_15_size_setf(uint8_t cycbuf15size)
{
	ASSERT_ERR((((uint32_t)cycbuf15size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_15_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_15_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf15size <<0));
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
#define MACSYS_GCU_CYC_BUF_16_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000E0)
#define MACSYS_GCU_CYC_BUF_16_OFFSET      0x000000E0
#define MACSYS_GCU_CYC_BUF_16_INDEX       0x00000038
#define MACSYS_GCU_CYC_BUF_16_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_16_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_16_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_16_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_16_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_16_CYC_BUF_16_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_16_pack(uint16_t cyc_buf_16_base, uint8_t cyc_buf_16_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_16_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_16_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_16_ADDR,  ((uint32_t)cyc_buf_16_base << 12) |((uint32_t)cyc_buf_16_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_16_unpack(uint16_t* cyc_buf_16_base, uint8_t* cyc_buf_16_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_16_ADDR);

	*cyc_buf_16_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_16_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_16_cyc_buf_16_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_16_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_16_cyc_buf_16_base_setf(uint16_t cycbuf16base)
{
	ASSERT_ERR((((uint32_t)cycbuf16base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_16_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_16_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf16base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_16_cyc_buf_16_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_16_cyc_buf_16_size_setf(uint8_t cycbuf16size)
{
	ASSERT_ERR((((uint32_t)cycbuf16size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_16_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_16_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf16size <<0));
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
#define MACSYS_GCU_CYC_BUF_17_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000E4)
#define MACSYS_GCU_CYC_BUF_17_OFFSET      0x000000E4
#define MACSYS_GCU_CYC_BUF_17_INDEX       0x00000039
#define MACSYS_GCU_CYC_BUF_17_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_17_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_17_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_17_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_17_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_17_CYC_BUF_17_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_17_pack(uint16_t cyc_buf_17_base, uint8_t cyc_buf_17_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_17_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_17_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_17_ADDR,  ((uint32_t)cyc_buf_17_base << 12) |((uint32_t)cyc_buf_17_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_17_unpack(uint16_t* cyc_buf_17_base, uint8_t* cyc_buf_17_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_17_ADDR);

	*cyc_buf_17_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_17_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_17_cyc_buf_17_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_17_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_17_cyc_buf_17_base_setf(uint16_t cycbuf17base)
{
	ASSERT_ERR((((uint32_t)cycbuf17base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_17_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_17_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf17base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_17_cyc_buf_17_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_17_cyc_buf_17_size_setf(uint8_t cycbuf17size)
{
	ASSERT_ERR((((uint32_t)cycbuf17size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_17_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_17_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf17size <<0));
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
#define MACSYS_GCU_CYC_BUF_18_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000E8)
#define MACSYS_GCU_CYC_BUF_18_OFFSET      0x000000E8
#define MACSYS_GCU_CYC_BUF_18_INDEX       0x0000003A
#define MACSYS_GCU_CYC_BUF_18_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_18_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_18_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_18_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_18_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_18_CYC_BUF_18_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_18_pack(uint16_t cyc_buf_18_base, uint8_t cyc_buf_18_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_18_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_18_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_18_ADDR,  ((uint32_t)cyc_buf_18_base << 12) |((uint32_t)cyc_buf_18_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_18_unpack(uint16_t* cyc_buf_18_base, uint8_t* cyc_buf_18_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_18_ADDR);

	*cyc_buf_18_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_18_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_18_cyc_buf_18_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_18_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_18_cyc_buf_18_base_setf(uint16_t cycbuf18base)
{
	ASSERT_ERR((((uint32_t)cycbuf18base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_18_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_18_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf18base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_18_cyc_buf_18_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_18_cyc_buf_18_size_setf(uint8_t cycbuf18size)
{
	ASSERT_ERR((((uint32_t)cycbuf18size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_18_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_18_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf18size <<0));
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
#define MACSYS_GCU_CYC_BUF_19_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000EC)
#define MACSYS_GCU_CYC_BUF_19_OFFSET      0x000000EC
#define MACSYS_GCU_CYC_BUF_19_INDEX       0x0000003B
#define MACSYS_GCU_CYC_BUF_19_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_cyc_buf_19_get(void)
{
	return REG_PL_RD(MACSYS_GCU_CYC_BUF_19_ADDR);
}

__INLINE void macsys_gcu_cyc_buf_19_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_CYC_BUF_19_ADDR, value);
}

// field definitions
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_BASE_MASK    ((uint32_t)0x001FF000)
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_BASE_LSB    12
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_BASE_WIDTH    ((uint32_t)0x00000009)
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_SIZE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_SIZE_LSB    0
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_SIZE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_BASE_RST    0x0
#define MACSYS_GCU_CYC_BUF_19_CYC_BUF_19_SIZE_RST    0x0

__INLINE void macsys_gcu_cyc_buf_19_pack(uint16_t cyc_buf_19_base, uint8_t cyc_buf_19_size)
{
	ASSERT_ERR((((uint32_t)cyc_buf_19_base << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)cyc_buf_19_size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_19_ADDR,  ((uint32_t)cyc_buf_19_base << 12) |((uint32_t)cyc_buf_19_size << 0));
}

__INLINE void macsys_gcu_cyc_buf_19_unpack(uint16_t* cyc_buf_19_base, uint8_t* cyc_buf_19_size)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_19_ADDR);

	*cyc_buf_19_base = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*cyc_buf_19_size = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t macsys_gcu_cyc_buf_19_cyc_buf_19_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_19_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void macsys_gcu_cyc_buf_19_cyc_buf_19_base_setf(uint16_t cycbuf19base)
{
	ASSERT_ERR((((uint32_t)cycbuf19base << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_19_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_19_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)cycbuf19base <<12));
}
__INLINE uint8_t macsys_gcu_cyc_buf_19_cyc_buf_19_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_CYC_BUF_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_cyc_buf_19_cyc_buf_19_size_setf(uint8_t cycbuf19size)
{
	ASSERT_ERR((((uint32_t)cycbuf19size << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_CYC_BUF_19_ADDR, (REG_PL_RD(MACSYS_GCU_CYC_BUF_19_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cycbuf19size <<0));
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
#define MACSYS_GCU_XT_CONTROL_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000F0)
#define MACSYS_GCU_XT_CONTROL_OFFSET      0x000000F0
#define MACSYS_GCU_XT_CONTROL_INDEX       0x0000003C
#define MACSYS_GCU_XT_CONTROL_RESET       0x000A0A0A

__INLINE uint32_t  macsys_gcu_xt_control_get(void)
{
	return REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
}

__INLINE void macsys_gcu_xt_control_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, value);
}

// field definitions
#define MACSYS_GCU_XT_CONTROL_SMAC_DEBUG_EN_BIT    ((uint32_t)0x00200000)
#define MACSYS_GCU_XT_CONTROL_SMAC_DEBUG_EN_POS    21
#define MACSYS_GCU_XT_CONTROL_SMAC_BREAK_IN_BIT    ((uint32_t)0x00100000)
#define MACSYS_GCU_XT_CONTROL_SMAC_BREAK_IN_POS    20
#define MACSYS_GCU_XT_CONTROL_SMAC_OCD_HALT_ON_RESET_BIT    ((uint32_t)0x00080000)
#define MACSYS_GCU_XT_CONTROL_SMAC_OCD_HALT_ON_RESET_POS    19
#define MACSYS_GCU_XT_CONTROL_SMAC_RUN_STALL_BIT    ((uint32_t)0x00040000)
#define MACSYS_GCU_XT_CONTROL_SMAC_RUN_STALL_POS    18
#define MACSYS_GCU_XT_CONTROL_SMAC_DRESET_N_BIT    ((uint32_t)0x00020000)
#define MACSYS_GCU_XT_CONTROL_SMAC_DRESET_N_POS    17
#define MACSYS_GCU_XT_CONTROL_SMAC_BRESET_N_BIT    ((uint32_t)0x00010000)
#define MACSYS_GCU_XT_CONTROL_SMAC_BRESET_N_POS    16
#define MACSYS_GCU_XT_CONTROL_UMAC_DEBUG_EN_BIT    ((uint32_t)0x00002000)
#define MACSYS_GCU_XT_CONTROL_UMAC_DEBUG_EN_POS    13
#define MACSYS_GCU_XT_CONTROL_UMAC_BREAK_IN_BIT    ((uint32_t)0x00001000)
#define MACSYS_GCU_XT_CONTROL_UMAC_BREAK_IN_POS    12
#define MACSYS_GCU_XT_CONTROL_UMAC_OCD_HALT_ON_RESET_BIT    ((uint32_t)0x00000800)
#define MACSYS_GCU_XT_CONTROL_UMAC_OCD_HALT_ON_RESET_POS    11
#define MACSYS_GCU_XT_CONTROL_UMAC_RUN_STALL_BIT    ((uint32_t)0x00000400)
#define MACSYS_GCU_XT_CONTROL_UMAC_RUN_STALL_POS    10
#define MACSYS_GCU_XT_CONTROL_UMAC_DRESET_N_BIT    ((uint32_t)0x00000200)
#define MACSYS_GCU_XT_CONTROL_UMAC_DRESET_N_POS    9
#define MACSYS_GCU_XT_CONTROL_UMAC_BRESET_N_BIT    ((uint32_t)0x00000100)
#define MACSYS_GCU_XT_CONTROL_UMAC_BRESET_N_POS    8
#define MACSYS_GCU_XT_CONTROL_LMAC_DEBUG_EN_BIT    ((uint32_t)0x00000020)
#define MACSYS_GCU_XT_CONTROL_LMAC_DEBUG_EN_POS    5
#define MACSYS_GCU_XT_CONTROL_LMAC_BREAK_IN_BIT    ((uint32_t)0x00000010)
#define MACSYS_GCU_XT_CONTROL_LMAC_BREAK_IN_POS    4
#define MACSYS_GCU_XT_CONTROL_LMAC_OCD_HALT_ON_RESET_BIT    ((uint32_t)0x00000008)
#define MACSYS_GCU_XT_CONTROL_LMAC_OCD_HALT_ON_RESET_POS    3
#define MACSYS_GCU_XT_CONTROL_LMAC_RUN_STALL_BIT    ((uint32_t)0x00000004)
#define MACSYS_GCU_XT_CONTROL_LMAC_RUN_STALL_POS    2
#define MACSYS_GCU_XT_CONTROL_LMAC_DRESET_N_BIT    ((uint32_t)0x00000002)
#define MACSYS_GCU_XT_CONTROL_LMAC_DRESET_N_POS    1
#define MACSYS_GCU_XT_CONTROL_LMAC_BRESET_N_BIT    ((uint32_t)0x00000001)
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

__INLINE void macsys_gcu_xt_control_pack(uint8_t smac_debug_en, uint8_t smac_break_in, uint8_t smac_ocd_halt_on_reset, uint8_t smac_run_stall, uint8_t smac_dreset_n, uint8_t smac_breset_n, uint8_t umac_debug_en, uint8_t umac_break_in, uint8_t umac_ocd_halt_on_reset, uint8_t umac_run_stall, uint8_t umac_dreset_n, uint8_t umac_breset_n, uint8_t lmac_debug_en, uint8_t lmac_break_in, uint8_t lmac_ocd_halt_on_reset, uint8_t lmac_run_stall, uint8_t lmac_dreset_n, uint8_t lmac_breset_n)
{
	ASSERT_ERR((((uint32_t)smac_debug_en << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)smac_break_in << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)smac_ocd_halt_on_reset << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)smac_run_stall << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)smac_dreset_n << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)smac_breset_n << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)umac_debug_en << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)umac_break_in << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)umac_ocd_halt_on_reset << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)umac_run_stall << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)umac_dreset_n << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)umac_breset_n << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)lmac_debug_en << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)lmac_break_in << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)lmac_ocd_halt_on_reset << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)lmac_run_stall << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)lmac_dreset_n << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)lmac_breset_n << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR,  ((uint32_t)smac_debug_en << 21) |((uint32_t)smac_break_in << 20) |((uint32_t)smac_ocd_halt_on_reset << 19) |((uint32_t)smac_run_stall << 18) |((uint32_t)smac_dreset_n << 17) |((uint32_t)smac_breset_n << 16) |((uint32_t)umac_debug_en << 13) |((uint32_t)umac_break_in << 12) |((uint32_t)umac_ocd_halt_on_reset << 11) |((uint32_t)umac_run_stall << 10) |((uint32_t)umac_dreset_n << 9) |((uint32_t)umac_breset_n << 8) |((uint32_t)lmac_debug_en << 5) |((uint32_t)lmac_break_in << 4) |((uint32_t)lmac_ocd_halt_on_reset << 3) |((uint32_t)lmac_run_stall << 2) |((uint32_t)lmac_dreset_n << 1) |((uint32_t)lmac_breset_n << 0));
}

__INLINE void macsys_gcu_xt_control_unpack(uint8_t* smac_debug_en, uint8_t* smac_break_in, uint8_t* smac_ocd_halt_on_reset, uint8_t* smac_run_stall, uint8_t* smac_dreset_n, uint8_t* smac_breset_n, uint8_t* umac_debug_en, uint8_t* umac_break_in, uint8_t* umac_ocd_halt_on_reset, uint8_t* umac_run_stall, uint8_t* umac_dreset_n, uint8_t* umac_breset_n, uint8_t* lmac_debug_en, uint8_t* lmac_break_in, uint8_t* lmac_ocd_halt_on_reset, uint8_t* lmac_run_stall, uint8_t* lmac_dreset_n, uint8_t* lmac_breset_n)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);

	*smac_debug_en = (localVal & ((uint32_t)0x00200000)) >>  21;
	*smac_break_in = (localVal & ((uint32_t)0x00100000)) >>  20;
	*smac_ocd_halt_on_reset = (localVal & ((uint32_t)0x00080000)) >>  19;
	*smac_run_stall = (localVal & ((uint32_t)0x00040000)) >>  18;
	*smac_dreset_n = (localVal & ((uint32_t)0x00020000)) >>  17;
	*smac_breset_n = (localVal & ((uint32_t)0x00010000)) >>  16;
	*umac_debug_en = (localVal & ((uint32_t)0x00002000)) >>  13;
	*umac_break_in = (localVal & ((uint32_t)0x00001000)) >>  12;
	*umac_ocd_halt_on_reset = (localVal & ((uint32_t)0x00000800)) >>  11;
	*umac_run_stall = (localVal & ((uint32_t)0x00000400)) >>  10;
	*umac_dreset_n = (localVal & ((uint32_t)0x00000200)) >>  9;
	*umac_breset_n = (localVal & ((uint32_t)0x00000100)) >>  8;
	*lmac_debug_en = (localVal & ((uint32_t)0x00000020)) >>  5;
	*lmac_break_in = (localVal & ((uint32_t)0x00000010)) >>  4;
	*lmac_ocd_halt_on_reset = (localVal & ((uint32_t)0x00000008)) >>  3;
	*lmac_run_stall = (localVal & ((uint32_t)0x00000004)) >>  2;
	*lmac_dreset_n = (localVal & ((uint32_t)0x00000002)) >>  1;
	*lmac_breset_n = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macsys_gcu_xt_control_smac_debug_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void macsys_gcu_xt_control_smac_debug_en_setf(uint8_t smacdebugen)
{
	ASSERT_ERR((((uint32_t)smacdebugen << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)smacdebugen <<21));
}
__INLINE uint8_t macsys_gcu_xt_control_smac_break_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void macsys_gcu_xt_control_smac_break_in_setf(uint8_t smacbreakin)
{
	ASSERT_ERR((((uint32_t)smacbreakin << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)smacbreakin <<20));
}
__INLINE uint8_t macsys_gcu_xt_control_smac_ocd_halt_on_reset_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void macsys_gcu_xt_control_smac_ocd_halt_on_reset_setf(uint8_t smacocdhaltonreset)
{
	ASSERT_ERR((((uint32_t)smacocdhaltonreset << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)smacocdhaltonreset <<19));
}
__INLINE uint8_t macsys_gcu_xt_control_smac_run_stall_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void macsys_gcu_xt_control_smac_run_stall_setf(uint8_t smacrunstall)
{
	ASSERT_ERR((((uint32_t)smacrunstall << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)smacrunstall <<18));
}
__INLINE uint8_t macsys_gcu_xt_control_smac_dreset_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void macsys_gcu_xt_control_smac_dreset_n_setf(uint8_t smacdresetn)
{
	ASSERT_ERR((((uint32_t)smacdresetn << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)smacdresetn <<17));
}
__INLINE uint8_t macsys_gcu_xt_control_smac_breset_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void macsys_gcu_xt_control_smac_breset_n_setf(uint8_t smacbresetn)
{
	ASSERT_ERR((((uint32_t)smacbresetn << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)smacbresetn <<16));
}
__INLINE uint8_t macsys_gcu_xt_control_umac_debug_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void macsys_gcu_xt_control_umac_debug_en_setf(uint8_t umacdebugen)
{
	ASSERT_ERR((((uint32_t)umacdebugen << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)umacdebugen <<13));
}
__INLINE uint8_t macsys_gcu_xt_control_umac_break_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void macsys_gcu_xt_control_umac_break_in_setf(uint8_t umacbreakin)
{
	ASSERT_ERR((((uint32_t)umacbreakin << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)umacbreakin <<12));
}
__INLINE uint8_t macsys_gcu_xt_control_umac_ocd_halt_on_reset_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void macsys_gcu_xt_control_umac_ocd_halt_on_reset_setf(uint8_t umacocdhaltonreset)
{
	ASSERT_ERR((((uint32_t)umacocdhaltonreset << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)umacocdhaltonreset <<11));
}
__INLINE uint8_t macsys_gcu_xt_control_umac_run_stall_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void macsys_gcu_xt_control_umac_run_stall_setf(uint8_t umacrunstall)
{
	ASSERT_ERR((((uint32_t)umacrunstall << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)umacrunstall <<10));
}
__INLINE uint8_t macsys_gcu_xt_control_umac_dreset_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void macsys_gcu_xt_control_umac_dreset_n_setf(uint8_t umacdresetn)
{
	ASSERT_ERR((((uint32_t)umacdresetn << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)umacdresetn <<9));
}
__INLINE uint8_t macsys_gcu_xt_control_umac_breset_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void macsys_gcu_xt_control_umac_breset_n_setf(uint8_t umacbresetn)
{
	ASSERT_ERR((((uint32_t)umacbresetn << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)umacbresetn <<8));
}
__INLINE uint8_t macsys_gcu_xt_control_lmac_debug_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void macsys_gcu_xt_control_lmac_debug_en_setf(uint8_t lmacdebugen)
{
	ASSERT_ERR((((uint32_t)lmacdebugen << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)lmacdebugen <<5));
}
__INLINE uint8_t macsys_gcu_xt_control_lmac_break_in_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void macsys_gcu_xt_control_lmac_break_in_setf(uint8_t lmacbreakin)
{
	ASSERT_ERR((((uint32_t)lmacbreakin << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)lmacbreakin <<4));
}
__INLINE uint8_t macsys_gcu_xt_control_lmac_ocd_halt_on_reset_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void macsys_gcu_xt_control_lmac_ocd_halt_on_reset_setf(uint8_t lmacocdhaltonreset)
{
	ASSERT_ERR((((uint32_t)lmacocdhaltonreset << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)lmacocdhaltonreset <<3));
}
__INLINE uint8_t macsys_gcu_xt_control_lmac_run_stall_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void macsys_gcu_xt_control_lmac_run_stall_setf(uint8_t lmacrunstall)
{
	ASSERT_ERR((((uint32_t)lmacrunstall << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)lmacrunstall <<2));
}
__INLINE uint8_t macsys_gcu_xt_control_lmac_dreset_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void macsys_gcu_xt_control_lmac_dreset_n_setf(uint8_t lmacdresetn)
{
	ASSERT_ERR((((uint32_t)lmacdresetn << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)lmacdresetn <<1));
}
__INLINE uint8_t macsys_gcu_xt_control_lmac_breset_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macsys_gcu_xt_control_lmac_breset_n_setf(uint8_t lmacbresetn)
{
	ASSERT_ERR((((uint32_t)lmacbresetn << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_XT_CONTROL_ADDR, (REG_PL_RD(MACSYS_GCU_XT_CONTROL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)lmacbresetn <<0));
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
#define MACSYS_GCU_XT_STATUS_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000000F4)
#define MACSYS_GCU_XT_STATUS_OFFSET      0x000000F4
#define MACSYS_GCU_XT_STATUS_INDEX       0x0000003D
#define MACSYS_GCU_XT_STATUS_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_xt_status_get(void)
{
	return REG_PL_RD(MACSYS_GCU_XT_STATUS_ADDR);
}

// field definitions
#define MACSYS_GCU_XT_STATUS_SMAC_BREAK_OUT_BIT    ((uint32_t)0x00040000)
#define MACSYS_GCU_XT_STATUS_SMAC_BREAK_OUT_POS    18
#define MACSYS_GCU_XT_STATUS_UMAC_BREAK_OUT_BIT    ((uint32_t)0x00020000)
#define MACSYS_GCU_XT_STATUS_UMAC_BREAK_OUT_POS    17
#define MACSYS_GCU_XT_STATUS_LMAC_BREAK_OUT_BIT    ((uint32_t)0x00010000)
#define MACSYS_GCU_XT_STATUS_LMAC_BREAK_OUT_POS    16

#define MACSYS_GCU_XT_STATUS_SMAC_BREAK_OUT_RST    0x0
#define MACSYS_GCU_XT_STATUS_UMAC_BREAK_OUT_RST    0x0
#define MACSYS_GCU_XT_STATUS_LMAC_BREAK_OUT_RST    0x0

__INLINE void macsys_gcu_xt_status_unpack(uint8_t* smac_break_out, uint8_t* umac_break_out, uint8_t* lmac_break_out)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_STATUS_ADDR);

	*smac_break_out = (localVal & ((uint32_t)0x00040000)) >>  18;
	*umac_break_out = (localVal & ((uint32_t)0x00020000)) >>  17;
	*lmac_break_out = (localVal & ((uint32_t)0x00010000)) >>  16;
}

__INLINE uint8_t macsys_gcu_xt_status_smac_break_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE uint8_t macsys_gcu_xt_status_umac_break_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE uint8_t macsys_gcu_xt_status_lmac_break_out_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_XT_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
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
#define MACSYS_GCU_AHB_2_AXI_CTRL_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000100)
#define MACSYS_GCU_AHB_2_AXI_CTRL_OFFSET      0x00000100
#define MACSYS_GCU_AHB_2_AXI_CTRL_INDEX       0x00000040
#define MACSYS_GCU_AHB_2_AXI_CTRL_RESET       0x00001918

__INLINE uint32_t  macsys_gcu_ahb_2_axi_ctrl_get(void)
{
	return REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
}

__INLINE void macsys_gcu_ahb_2_axi_ctrl_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, value);
}

// field definitions
#define MACSYS_GCU_AHB_2_AXI_CTRL_WRITE_ORDER_PRESERVE_E_2_W_BIT    ((uint32_t)0x00010000)
#define MACSYS_GCU_AHB_2_AXI_CTRL_WRITE_ORDER_PRESERVE_E_2_W_POS    16
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_USBW_BIT    ((uint32_t)0x00002000)
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_USBW_POS    13
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_MACHW_BIT    ((uint32_t)0x00001000)
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_MACHW_POS    12
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_PCIE_BIT    ((uint32_t)0x00000800)
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_PCIE_POS    11
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_PCIEW_BIT    ((uint32_t)0x00000400)
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_PCIEW_POS    10
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_E_2_W_BIT    ((uint32_t)0x00000200)
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_E_2_W_POS    9
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_NATT_BIT    ((uint32_t)0x00000100)
#define MACSYS_GCU_AHB_2_AXI_CTRL_PREFETCH_EN_NATT_POS    8
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_USBW_BIT    ((uint32_t)0x00000020)
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_USBW_POS    5
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_MACHW_BIT    ((uint32_t)0x00000010)
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_MACHW_POS    4
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_PCIE_BIT    ((uint32_t)0x00000008)
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_PCIE_POS    3
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_PCIEW_BIT    ((uint32_t)0x00000004)
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_PCIEW_POS    2
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_E_2_W_BIT    ((uint32_t)0x00000002)
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_E_2_W_POS    1
#define MACSYS_GCU_AHB_2_AXI_CTRL_BUFFERABLE_NATT_BIT    ((uint32_t)0x00000001)
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

__INLINE void macsys_gcu_ahb_2_axi_ctrl_pack(uint8_t write_order_preserve_e2_w, uint8_t prefetch_en_usbw, uint8_t prefetch_en_machw, uint8_t prefetch_en_pcie, uint8_t prefetch_en_pciew, uint8_t prefetch_en_e2_w, uint8_t prefetch_en_natt, uint8_t bufferable_usbw, uint8_t bufferable_machw, uint8_t bufferable_pcie, uint8_t bufferable_pciew, uint8_t bufferable_e2_w, uint8_t bufferable_natt)
{
	ASSERT_ERR((((uint32_t)write_order_preserve_e2_w << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)prefetch_en_usbw << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)prefetch_en_machw << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)prefetch_en_pcie << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)prefetch_en_pciew << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)prefetch_en_e2_w << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)prefetch_en_natt << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)bufferable_usbw << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)bufferable_machw << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)bufferable_pcie << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)bufferable_pciew << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)bufferable_e2_w << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)bufferable_natt << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR,  ((uint32_t)write_order_preserve_e2_w << 16) |((uint32_t)prefetch_en_usbw << 13) |((uint32_t)prefetch_en_machw << 12) |((uint32_t)prefetch_en_pcie << 11) |((uint32_t)prefetch_en_pciew << 10) |((uint32_t)prefetch_en_e2_w << 9) |((uint32_t)prefetch_en_natt << 8) |((uint32_t)bufferable_usbw << 5) |((uint32_t)bufferable_machw << 4) |((uint32_t)bufferable_pcie << 3) |((uint32_t)bufferable_pciew << 2) |((uint32_t)bufferable_e2_w << 1) |((uint32_t)bufferable_natt << 0));
}

__INLINE void macsys_gcu_ahb_2_axi_ctrl_unpack(uint8_t* write_order_preserve_e2_w, uint8_t* prefetch_en_usbw, uint8_t* prefetch_en_machw, uint8_t* prefetch_en_pcie, uint8_t* prefetch_en_pciew, uint8_t* prefetch_en_e2_w, uint8_t* prefetch_en_natt, uint8_t* bufferable_usbw, uint8_t* bufferable_machw, uint8_t* bufferable_pcie, uint8_t* bufferable_pciew, uint8_t* bufferable_e2_w, uint8_t* bufferable_natt)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);

	*write_order_preserve_e2_w = (localVal & ((uint32_t)0x00010000)) >>  16;
	*prefetch_en_usbw = (localVal & ((uint32_t)0x00002000)) >>  13;
	*prefetch_en_machw = (localVal & ((uint32_t)0x00001000)) >>  12;
	*prefetch_en_pcie = (localVal & ((uint32_t)0x00000800)) >>  11;
	*prefetch_en_pciew = (localVal & ((uint32_t)0x00000400)) >>  10;
	*prefetch_en_e2_w = (localVal & ((uint32_t)0x00000200)) >>  9;
	*prefetch_en_natt = (localVal & ((uint32_t)0x00000100)) >>  8;
	*bufferable_usbw = (localVal & ((uint32_t)0x00000020)) >>  5;
	*bufferable_machw = (localVal & ((uint32_t)0x00000010)) >>  4;
	*bufferable_pcie = (localVal & ((uint32_t)0x00000008)) >>  3;
	*bufferable_pciew = (localVal & ((uint32_t)0x00000004)) >>  2;
	*bufferable_e2_w = (localVal & ((uint32_t)0x00000002)) >>  1;
	*bufferable_natt = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_write_order_preserve_e_2_w_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_write_order_preserve_e_2_w_setf(uint8_t writeorderpreservee2w)
{
	ASSERT_ERR((((uint32_t)writeorderpreservee2w << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)writeorderpreservee2w <<16));
}
__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_prefetch_en_usbw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_prefetch_en_usbw_setf(uint8_t prefetchenusbw)
{
	ASSERT_ERR((((uint32_t)prefetchenusbw << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)prefetchenusbw <<13));
}
__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_prefetch_en_machw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_prefetch_en_machw_setf(uint8_t prefetchenmachw)
{
	ASSERT_ERR((((uint32_t)prefetchenmachw << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)prefetchenmachw <<12));
}
__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_prefetch_en_pcie_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_prefetch_en_pcie_setf(uint8_t prefetchenpcie)
{
	ASSERT_ERR((((uint32_t)prefetchenpcie << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)prefetchenpcie <<11));
}
__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_prefetch_en_pciew_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_prefetch_en_pciew_setf(uint8_t prefetchenpciew)
{
	ASSERT_ERR((((uint32_t)prefetchenpciew << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)prefetchenpciew <<10));
}
__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_prefetch_en_e_2_w_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_prefetch_en_e_2_w_setf(uint8_t prefetchene2w)
{
	ASSERT_ERR((((uint32_t)prefetchene2w << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)prefetchene2w <<9));
}
__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_prefetch_en_natt_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_prefetch_en_natt_setf(uint8_t prefetchennatt)
{
	ASSERT_ERR((((uint32_t)prefetchennatt << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)prefetchennatt <<8));
}
__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_bufferable_usbw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_bufferable_usbw_setf(uint8_t bufferableusbw)
{
	ASSERT_ERR((((uint32_t)bufferableusbw << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)bufferableusbw <<5));
}
__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_bufferable_machw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_bufferable_machw_setf(uint8_t bufferablemachw)
{
	ASSERT_ERR((((uint32_t)bufferablemachw << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)bufferablemachw <<4));
}
__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_bufferable_pcie_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_bufferable_pcie_setf(uint8_t bufferablepcie)
{
	ASSERT_ERR((((uint32_t)bufferablepcie << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)bufferablepcie <<3));
}
__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_bufferable_pciew_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_bufferable_pciew_setf(uint8_t bufferablepciew)
{
	ASSERT_ERR((((uint32_t)bufferablepciew << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)bufferablepciew <<2));
}
__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_bufferable_e_2_w_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_bufferable_e_2_w_setf(uint8_t bufferablee2w)
{
	ASSERT_ERR((((uint32_t)bufferablee2w << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)bufferablee2w <<1));
}
__INLINE uint8_t macsys_gcu_ahb_2_axi_ctrl_bufferable_natt_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macsys_gcu_ahb_2_axi_ctrl_bufferable_natt_setf(uint8_t bufferablenatt)
{
	ASSERT_ERR((((uint32_t)bufferablenatt << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_AHB_2_AXI_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)bufferablenatt <<0));
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
#define MACSYS_GCU_DPHY_MUX_CTRL_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000104)
#define MACSYS_GCU_DPHY_MUX_CTRL_OFFSET      0x00000104
#define MACSYS_GCU_DPHY_MUX_CTRL_INDEX       0x00000041
#define MACSYS_GCU_DPHY_MUX_CTRL_RESET       0x00000040

__INLINE uint32_t  macsys_gcu_dphy_mux_ctrl_get(void)
{
	return REG_PL_RD(MACSYS_GCU_DPHY_MUX_CTRL_ADDR);
}

__INLINE void macsys_gcu_dphy_mux_ctrl_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_DPHY_MUX_CTRL_ADDR, value);
}

// field definitions
#define MACSYS_GCU_DPHY_MUX_CTRL_MUX_CTRL_MASK    ((uint32_t)0x000000FF)
#define MACSYS_GCU_DPHY_MUX_CTRL_MUX_CTRL_LSB    0
#define MACSYS_GCU_DPHY_MUX_CTRL_MUX_CTRL_WIDTH    ((uint32_t)0x00000008)

#define MACSYS_GCU_DPHY_MUX_CTRL_MUX_CTRL_RST    0x40

__INLINE uint8_t macsys_gcu_dphy_mux_ctrl_mux_ctrl_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_DPHY_MUX_CTRL_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macsys_gcu_dphy_mux_ctrl_mux_ctrl_setf(uint8_t muxctrl)
{
	ASSERT_ERR((((uint32_t)muxctrl << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACSYS_GCU_DPHY_MUX_CTRL_ADDR, (uint32_t)muxctrl << 0);
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
#define MACSYS_GCU_UART_IF_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000108)
#define MACSYS_GCU_UART_IF_OFFSET      0x00000108
#define MACSYS_GCU_UART_IF_INDEX       0x00000042
#define MACSYS_GCU_UART_IF_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_uart_if_get(void)
{
	return REG_PL_RD(MACSYS_GCU_UART_IF_ADDR);
}

__INLINE void macsys_gcu_uart_if_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_UART_IF_ADDR, value);
}

// field definitions
#define MACSYS_GCU_UART_IF_CTS_IF_MODE_MASK    ((uint32_t)0x0000000C)
#define MACSYS_GCU_UART_IF_CTS_IF_MODE_LSB    2
#define MACSYS_GCU_UART_IF_CTS_IF_MODE_WIDTH    ((uint32_t)0x00000002)
#define MACSYS_GCU_UART_IF_RTS_IF_MODE_MASK    ((uint32_t)0x00000003)
#define MACSYS_GCU_UART_IF_RTS_IF_MODE_LSB    0
#define MACSYS_GCU_UART_IF_RTS_IF_MODE_WIDTH    ((uint32_t)0x00000002)

#define MACSYS_GCU_UART_IF_CTS_IF_MODE_RST    0x0
#define MACSYS_GCU_UART_IF_RTS_IF_MODE_RST    0x0

__INLINE void macsys_gcu_uart_if_pack(uint8_t cts_if_mode, uint8_t rts_if_mode)
{
	ASSERT_ERR((((uint32_t)cts_if_mode << 2) & ~((uint32_t)0x0000000C)) == 0);
	ASSERT_ERR((((uint32_t)rts_if_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_UART_IF_ADDR,  ((uint32_t)cts_if_mode << 2) |((uint32_t)rts_if_mode << 0));
}

__INLINE void macsys_gcu_uart_if_unpack(uint8_t* cts_if_mode, uint8_t* rts_if_mode)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UART_IF_ADDR);

	*cts_if_mode = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*rts_if_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t macsys_gcu_uart_if_cts_if_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UART_IF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE void macsys_gcu_uart_if_cts_if_mode_setf(uint8_t ctsifmode)
{
	ASSERT_ERR((((uint32_t)ctsifmode << 2) & ~((uint32_t)0x0000000C)) == 0);
	REG_PL_WR(MACSYS_GCU_UART_IF_ADDR, (REG_PL_RD(MACSYS_GCU_UART_IF_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)ctsifmode <<2));
}
__INLINE uint8_t macsys_gcu_uart_if_rts_if_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UART_IF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macsys_gcu_uart_if_rts_if_mode_setf(uint8_t rtsifmode)
{
	ASSERT_ERR((((uint32_t)rtsifmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACSYS_GCU_UART_IF_ADDR, (REG_PL_RD(MACSYS_GCU_UART_IF_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)rtsifmode <<0));
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
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000114)
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_OFFSET      0x00000114
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_INDEX       0x00000045
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_macsys_la_samp_mask_low_get(void)
{
	return REG_PL_RD(MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_ADDR);
}

__INLINE void macsys_gcu_macsys_la_samp_mask_low_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_ADDR, value);
}

// field definitions
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_MAC_LA_SAMPLING_MASK_LOW_MASK    ((uint32_t)0xFFFFFFFF)
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_MAC_LA_SAMPLING_MASK_LOW_LSB    0
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_MAC_LA_SAMPLING_MASK_LOW_WIDTH    ((uint32_t)0x00000020)

#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_MAC_LA_SAMPLING_MASK_LOW_RST    0x0

__INLINE uint32_t macsys_gcu_macsys_la_samp_mask_low_mac_la_sampling_mask_low_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macsys_gcu_macsys_la_samp_mask_low_mac_la_sampling_mask_low_setf(uint32_t maclasamplingmasklow)
{
	ASSERT_ERR((((uint32_t)maclasamplingmasklow << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_MACSYS_LA_SAMP_MASK_LOW_ADDR, (uint32_t)maclasamplingmasklow << 0);
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
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000118)
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_OFFSET      0x00000118
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_INDEX       0x00000046
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_macsys_la_samp_mask_mid_get(void)
{
	return REG_PL_RD(MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_ADDR);
}

__INLINE void macsys_gcu_macsys_la_samp_mask_mid_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_ADDR, value);
}

// field definitions
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_MAC_LA_SAMPLING_MASK_MID_MASK    ((uint32_t)0xFFFFFFFF)
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_MAC_LA_SAMPLING_MASK_MID_LSB    0
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_MAC_LA_SAMPLING_MASK_MID_WIDTH    ((uint32_t)0x00000020)

#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_MAC_LA_SAMPLING_MASK_MID_RST    0x0

__INLINE uint32_t macsys_gcu_macsys_la_samp_mask_mid_mac_la_sampling_mask_mid_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macsys_gcu_macsys_la_samp_mask_mid_mac_la_sampling_mask_mid_setf(uint32_t maclasamplingmaskmid)
{
	ASSERT_ERR((((uint32_t)maclasamplingmaskmid << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_MACSYS_LA_SAMP_MASK_MID_ADDR, (uint32_t)maclasamplingmaskmid << 0);
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
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x0000011C)
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_OFFSET      0x0000011C
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_INDEX       0x00000047
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_macsys_la_samp_mask_high_get(void)
{
	return REG_PL_RD(MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_ADDR);
}

__INLINE void macsys_gcu_macsys_la_samp_mask_high_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_ADDR, value);
}

// field definitions
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_MAC_LA_SAMPLING_MASK_HIGH_MASK    ((uint32_t)0xFFFFFFFF)
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_MAC_LA_SAMPLING_MASK_HIGH_LSB    0
#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_MAC_LA_SAMPLING_MASK_HIGH_WIDTH    ((uint32_t)0x00000020)

#define MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_MAC_LA_SAMPLING_MASK_HIGH_RST    0x0

__INLINE uint32_t macsys_gcu_macsys_la_samp_mask_high_mac_la_sampling_mask_high_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macsys_gcu_macsys_la_samp_mask_high_mac_la_sampling_mask_high_setf(uint32_t maclasamplingmaskhigh)
{
	ASSERT_ERR((((uint32_t)maclasamplingmaskhigh << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_MACSYS_LA_SAMP_MASK_HIGH_ADDR, (uint32_t)maclasamplingmaskhigh << 0);
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
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000120)
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_OFFSET      0x00000120
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_INDEX       0x00000048
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_macsys_la_trig_mask_low_get(void)
{
	return REG_PL_RD(MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_ADDR);
}

__INLINE void macsys_gcu_macsys_la_trig_mask_low_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_ADDR, value);
}

// field definitions
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_MAC_LA_TRIGGER_MASK_LOW_MASK    ((uint32_t)0xFFFFFFFF)
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_MAC_LA_TRIGGER_MASK_LOW_LSB    0
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_MAC_LA_TRIGGER_MASK_LOW_WIDTH    ((uint32_t)0x00000020)

#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_MAC_LA_TRIGGER_MASK_LOW_RST    0x0

__INLINE uint32_t macsys_gcu_macsys_la_trig_mask_low_mac_la_trigger_mask_low_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macsys_gcu_macsys_la_trig_mask_low_mac_la_trigger_mask_low_setf(uint32_t maclatriggermasklow)
{
	ASSERT_ERR((((uint32_t)maclatriggermasklow << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_MACSYS_LA_TRIG_MASK_LOW_ADDR, (uint32_t)maclatriggermasklow << 0);
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
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000124)
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_OFFSET      0x00000124
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_INDEX       0x00000049
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_macsys_la_trig_mask_mid_get(void)
{
	return REG_PL_RD(MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_ADDR);
}

__INLINE void macsys_gcu_macsys_la_trig_mask_mid_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_ADDR, value);
}

// field definitions
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_MAC_LA_TRIGGER_MASK_MID_MASK    ((uint32_t)0xFFFFFFFF)
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_MAC_LA_TRIGGER_MASK_MID_LSB    0
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_MAC_LA_TRIGGER_MASK_MID_WIDTH    ((uint32_t)0x00000020)

#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_MAC_LA_TRIGGER_MASK_MID_RST    0x0

__INLINE uint32_t macsys_gcu_macsys_la_trig_mask_mid_mac_la_trigger_mask_mid_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macsys_gcu_macsys_la_trig_mask_mid_mac_la_trigger_mask_mid_setf(uint32_t maclatriggermaskmid)
{
	ASSERT_ERR((((uint32_t)maclatriggermaskmid << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_MACSYS_LA_TRIG_MASK_MID_ADDR, (uint32_t)maclatriggermaskmid << 0);
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
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000128)
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_OFFSET      0x00000128
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_INDEX       0x0000004A
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_macsys_la_trig_mask_high_get(void)
{
	return REG_PL_RD(MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_ADDR);
}

__INLINE void macsys_gcu_macsys_la_trig_mask_high_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_ADDR, value);
}

// field definitions
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_MAC_LA_TRIGGER_MASK_HIGH_MASK    ((uint32_t)0xFFFFFFFF)
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_MAC_LA_TRIGGER_MASK_HIGH_LSB    0
#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_MAC_LA_TRIGGER_MASK_HIGH_WIDTH    ((uint32_t)0x00000020)

#define MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_MAC_LA_TRIGGER_MASK_HIGH_RST    0x0

__INLINE uint32_t macsys_gcu_macsys_la_trig_mask_high_mac_la_trigger_mask_high_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macsys_gcu_macsys_la_trig_mask_high_mac_la_trigger_mask_high_setf(uint32_t maclatriggermaskhigh)
{
	ASSERT_ERR((((uint32_t)maclatriggermaskhigh << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_MACSYS_LA_TRIG_MASK_HIGH_ADDR, (uint32_t)maclatriggermaskhigh << 0);
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
#define MACSYS_GCU_HOST_IF_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000140)
#define MACSYS_GCU_HOST_IF_OFFSET      0x00000140
#define MACSYS_GCU_HOST_IF_INDEX       0x00000050
#define MACSYS_GCU_HOST_IF_RESET       0x00000001

__INLINE uint32_t  macsys_gcu_host_if_get(void)
{
	return REG_PL_RD(MACSYS_GCU_HOST_IF_ADDR);
}

__INLINE void macsys_gcu_host_if_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_HOST_IF_ADDR, value);
}

// field definitions
#define MACSYS_GCU_HOST_IF_USB_SPEED_BIT    ((uint32_t)0x00000002)
#define MACSYS_GCU_HOST_IF_USB_SPEED_POS    1
#define MACSYS_GCU_HOST_IF_HOST_INTERFACE_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_HOST_IF_HOST_INTERFACE_POS    0

#define MACSYS_GCU_HOST_IF_USB_SPEED_RST    0x0
#define MACSYS_GCU_HOST_IF_HOST_INTERFACE_RST    0x1

__INLINE void macsys_gcu_host_if_pack(uint8_t usb_speed, uint8_t host_interface)
{
	ASSERT_ERR((((uint32_t)usb_speed << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)host_interface << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_HOST_IF_ADDR,  ((uint32_t)usb_speed << 1) |((uint32_t)host_interface << 0));
}

__INLINE void macsys_gcu_host_if_unpack(uint8_t* usb_speed, uint8_t* host_interface)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_HOST_IF_ADDR);

	*usb_speed = (localVal & ((uint32_t)0x00000002)) >>  1;
	*host_interface = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macsys_gcu_host_if_usb_speed_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_HOST_IF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void macsys_gcu_host_if_usb_speed_setf(uint8_t usbspeed)
{
	ASSERT_ERR((((uint32_t)usbspeed << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MACSYS_GCU_HOST_IF_ADDR, (REG_PL_RD(MACSYS_GCU_HOST_IF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)usbspeed <<1));
}
__INLINE uint8_t macsys_gcu_host_if_host_interface_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_HOST_IF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macsys_gcu_host_if_host_interface_setf(uint8_t hostinterface)
{
	ASSERT_ERR((((uint32_t)hostinterface << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_HOST_IF_ADDR, (REG_PL_RD(MACSYS_GCU_HOST_IF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)hostinterface <<0));
}

/**
 * @brief UMAC_CONTROL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    UMAC_BOOT_SRC             0              
 * </pre>
 */
#define MACSYS_GCU_UMAC_CONTROL_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000144)
#define MACSYS_GCU_UMAC_CONTROL_OFFSET      0x00000144
#define MACSYS_GCU_UMAC_CONTROL_INDEX       0x00000051
#define MACSYS_GCU_UMAC_CONTROL_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_umac_control_get(void)
{
	return REG_PL_RD(MACSYS_GCU_UMAC_CONTROL_ADDR);
}

__INLINE void macsys_gcu_umac_control_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_UMAC_CONTROL_ADDR, value);
}

// field definitions
#define MACSYS_GCU_UMAC_CONTROL_UMAC_BOOT_SRC_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_UMAC_CONTROL_UMAC_BOOT_SRC_POS    0

#define MACSYS_GCU_UMAC_CONTROL_UMAC_BOOT_SRC_RST    0x0

__INLINE uint8_t macsys_gcu_umac_control_umac_boot_src_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_CONTROL_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macsys_gcu_umac_control_umac_boot_src_setf(uint8_t umacbootsrc)
{
	ASSERT_ERR((((uint32_t)umacbootsrc << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_CONTROL_ADDR, (uint32_t)umacbootsrc << 0);
}

/**
 * @brief SMAC_CONTROL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    SMAC_BOOT_SRC             1              
 * </pre>
 */
#define MACSYS_GCU_SMAC_CONTROL_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000148)
#define MACSYS_GCU_SMAC_CONTROL_OFFSET      0x00000148
#define MACSYS_GCU_SMAC_CONTROL_INDEX       0x00000052
#define MACSYS_GCU_SMAC_CONTROL_RESET       0x00000001

__INLINE uint32_t  macsys_gcu_smac_control_get(void)
{
	return REG_PL_RD(MACSYS_GCU_SMAC_CONTROL_ADDR);
}

__INLINE void macsys_gcu_smac_control_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_SMAC_CONTROL_ADDR, value);
}

// field definitions
#define MACSYS_GCU_SMAC_CONTROL_SMAC_BOOT_SRC_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_SMAC_CONTROL_SMAC_BOOT_SRC_POS    0

#define MACSYS_GCU_SMAC_CONTROL_SMAC_BOOT_SRC_RST    0x1

__INLINE uint8_t macsys_gcu_smac_control_smac_boot_src_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_CONTROL_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macsys_gcu_smac_control_smac_boot_src_setf(uint8_t smacbootsrc)
{
	ASSERT_ERR((((uint32_t)smacbootsrc << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_CONTROL_ADDR, (uint32_t)smacbootsrc << 0);
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
#define MACSYS_GCU_USB_CAPABILITIES_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x0000014C)
#define MACSYS_GCU_USB_CAPABILITIES_OFFSET      0x0000014C
#define MACSYS_GCU_USB_CAPABILITIES_INDEX       0x00000053
#define MACSYS_GCU_USB_CAPABILITIES_RESET       0x00000003

__INLINE uint32_t  macsys_gcu_usb_capabilities_get(void)
{
	return REG_PL_RD(MACSYS_GCU_USB_CAPABILITIES_ADDR);
}

__INLINE void macsys_gcu_usb_capabilities_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_USB_CAPABILITIES_ADDR, value);
}

// field definitions
#define MACSYS_GCU_USB_CAPABILITIES_SS_LPM_CAPABILITY_BIT    ((uint32_t)0x00000002)
#define MACSYS_GCU_USB_CAPABILITIES_SS_LPM_CAPABILITY_POS    1
#define MACSYS_GCU_USB_CAPABILITIES_HS_LPM_CAPABILITY_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_USB_CAPABILITIES_HS_LPM_CAPABILITY_POS    0

#define MACSYS_GCU_USB_CAPABILITIES_SS_LPM_CAPABILITY_RST    0x1
#define MACSYS_GCU_USB_CAPABILITIES_HS_LPM_CAPABILITY_RST    0x1

__INLINE void macsys_gcu_usb_capabilities_pack(uint8_t ss_lpm_capability, uint8_t hs_lpm_capability)
{
	ASSERT_ERR((((uint32_t)ss_lpm_capability << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)hs_lpm_capability << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_CAPABILITIES_ADDR,  ((uint32_t)ss_lpm_capability << 1) |((uint32_t)hs_lpm_capability << 0));
}

__INLINE void macsys_gcu_usb_capabilities_unpack(uint8_t* ss_lpm_capability, uint8_t* hs_lpm_capability)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_CAPABILITIES_ADDR);

	*ss_lpm_capability = (localVal & ((uint32_t)0x00000002)) >>  1;
	*hs_lpm_capability = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macsys_gcu_usb_capabilities_ss_lpm_capability_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_CAPABILITIES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void macsys_gcu_usb_capabilities_ss_lpm_capability_setf(uint8_t sslpmcapability)
{
	ASSERT_ERR((((uint32_t)sslpmcapability << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_CAPABILITIES_ADDR, (REG_PL_RD(MACSYS_GCU_USB_CAPABILITIES_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)sslpmcapability <<1));
}
__INLINE uint8_t macsys_gcu_usb_capabilities_hs_lpm_capability_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_CAPABILITIES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macsys_gcu_usb_capabilities_hs_lpm_capability_setf(uint8_t hslpmcapability)
{
	ASSERT_ERR((((uint32_t)hslpmcapability << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_CAPABILITIES_ADDR, (REG_PL_RD(MACSYS_GCU_USB_CAPABILITIES_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)hslpmcapability <<0));
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
#define MACSYS_GCU_SMAC_INT_MAP_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x0000016C)
#define MACSYS_GCU_SMAC_INT_MAP_0_OFFSET      0x0000016C
#define MACSYS_GCU_SMAC_INT_MAP_0_INDEX       0x0000005B
#define MACSYS_GCU_SMAC_INT_MAP_0_RESET       0x3FFFFFFF

__INLINE uint32_t  macsys_gcu_smac_int_map_0_get(void)
{
	return REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR);
}

__INLINE void macsys_gcu_smac_int_map_0_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_0_ADDR, value);
}

// field definitions
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_7_SEL_MASK    ((uint32_t)0x3E000000)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_7_SEL_LSB    25
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_7_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_6_SEL_MASK    ((uint32_t)0x01F00000)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_6_SEL_LSB    20
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_6_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_5_SEL_MASK    ((uint32_t)0x000F8000)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_5_SEL_LSB    15
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_5_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_4_SEL_MASK    ((uint32_t)0x00007C00)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_4_SEL_LSB    10
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_4_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_3_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_3_SEL_LSB    5
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_3_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_2_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_2_SEL_LSB    0
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_2_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_7_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_6_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_5_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_4_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_3_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_0_SMAC_INT_2_SEL_RST    0x1f

__INLINE void macsys_gcu_smac_int_map_0_pack(uint8_t smac_int7_sel, uint8_t smac_int6_sel, uint8_t smac_int5_sel, uint8_t smac_int4_sel, uint8_t smac_int3_sel, uint8_t smac_int2_sel)
{
	ASSERT_ERR((((uint32_t)smac_int7_sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int6_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int5_sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int4_sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)smac_int3_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)smac_int2_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_0_ADDR,  ((uint32_t)smac_int7_sel << 25) |((uint32_t)smac_int6_sel << 20) |((uint32_t)smac_int5_sel << 15) |((uint32_t)smac_int4_sel << 10) |((uint32_t)smac_int3_sel << 5) |((uint32_t)smac_int2_sel << 0));
}

__INLINE void macsys_gcu_smac_int_map_0_unpack(uint8_t* smac_int7_sel, uint8_t* smac_int6_sel, uint8_t* smac_int5_sel, uint8_t* smac_int4_sel, uint8_t* smac_int3_sel, uint8_t* smac_int2_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR);

	*smac_int7_sel = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*smac_int6_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*smac_int5_sel = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*smac_int4_sel = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*smac_int3_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*smac_int2_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_smac_int_map_0_smac_int_7_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void macsys_gcu_smac_int_map_0_smac_int_7_sel_setf(uint8_t smacint7sel)
{
	ASSERT_ERR((((uint32_t)smacint7sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)smacint7sel <<25));
}
__INLINE uint8_t macsys_gcu_smac_int_map_0_smac_int_6_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macsys_gcu_smac_int_map_0_smac_int_6_sel_setf(uint8_t smacint6sel)
{
	ASSERT_ERR((((uint32_t)smacint6sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)smacint6sel <<20));
}
__INLINE uint8_t macsys_gcu_smac_int_map_0_smac_int_5_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void macsys_gcu_smac_int_map_0_smac_int_5_sel_setf(uint8_t smacint5sel)
{
	ASSERT_ERR((((uint32_t)smacint5sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)smacint5sel <<15));
}
__INLINE uint8_t macsys_gcu_smac_int_map_0_smac_int_4_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macsys_gcu_smac_int_map_0_smac_int_4_sel_setf(uint8_t smacint4sel)
{
	ASSERT_ERR((((uint32_t)smacint4sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)smacint4sel <<10));
}
__INLINE uint8_t macsys_gcu_smac_int_map_0_smac_int_3_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_smac_int_map_0_smac_int_3_sel_setf(uint8_t smacint3sel)
{
	ASSERT_ERR((((uint32_t)smacint3sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)smacint3sel <<5));
}
__INLINE uint8_t macsys_gcu_smac_int_map_0_smac_int_2_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_smac_int_map_0_smac_int_2_sel_setf(uint8_t smacint2sel)
{
	ASSERT_ERR((((uint32_t)smacint2sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)smacint2sel <<0));
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
#define MACSYS_GCU_SMAC_INT_MAP_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000170)
#define MACSYS_GCU_SMAC_INT_MAP_1_OFFSET      0x00000170
#define MACSYS_GCU_SMAC_INT_MAP_1_INDEX       0x0000005C
#define MACSYS_GCU_SMAC_INT_MAP_1_RESET       0x3FFFFFFF

__INLINE uint32_t  macsys_gcu_smac_int_map_1_get(void)
{
	return REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR);
}

__INLINE void macsys_gcu_smac_int_map_1_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_1_ADDR, value);
}

// field definitions
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_13_SEL_MASK    ((uint32_t)0x3E000000)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_13_SEL_LSB    25
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_13_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_12_SEL_MASK    ((uint32_t)0x01F00000)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_12_SEL_LSB    20
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_12_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_11_SEL_MASK    ((uint32_t)0x000F8000)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_11_SEL_LSB    15
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_11_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_10_SEL_MASK    ((uint32_t)0x00007C00)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_10_SEL_LSB    10
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_10_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_9_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_9_SEL_LSB    5
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_9_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_8_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_8_SEL_LSB    0
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_8_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_13_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_12_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_11_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_10_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_9_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_1_SMAC_INT_8_SEL_RST    0x1f

__INLINE void macsys_gcu_smac_int_map_1_pack(uint8_t smac_int13_sel, uint8_t smac_int12_sel, uint8_t smac_int11_sel, uint8_t smac_int10_sel, uint8_t smac_int9_sel, uint8_t smac_int8_sel)
{
	ASSERT_ERR((((uint32_t)smac_int13_sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int12_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int11_sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int10_sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)smac_int9_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)smac_int8_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_1_ADDR,  ((uint32_t)smac_int13_sel << 25) |((uint32_t)smac_int12_sel << 20) |((uint32_t)smac_int11_sel << 15) |((uint32_t)smac_int10_sel << 10) |((uint32_t)smac_int9_sel << 5) |((uint32_t)smac_int8_sel << 0));
}

__INLINE void macsys_gcu_smac_int_map_1_unpack(uint8_t* smac_int13_sel, uint8_t* smac_int12_sel, uint8_t* smac_int11_sel, uint8_t* smac_int10_sel, uint8_t* smac_int9_sel, uint8_t* smac_int8_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR);

	*smac_int13_sel = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*smac_int12_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*smac_int11_sel = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*smac_int10_sel = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*smac_int9_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*smac_int8_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_smac_int_map_1_smac_int_13_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void macsys_gcu_smac_int_map_1_smac_int_13_sel_setf(uint8_t smacint13sel)
{
	ASSERT_ERR((((uint32_t)smacint13sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)smacint13sel <<25));
}
__INLINE uint8_t macsys_gcu_smac_int_map_1_smac_int_12_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macsys_gcu_smac_int_map_1_smac_int_12_sel_setf(uint8_t smacint12sel)
{
	ASSERT_ERR((((uint32_t)smacint12sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)smacint12sel <<20));
}
__INLINE uint8_t macsys_gcu_smac_int_map_1_smac_int_11_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void macsys_gcu_smac_int_map_1_smac_int_11_sel_setf(uint8_t smacint11sel)
{
	ASSERT_ERR((((uint32_t)smacint11sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)smacint11sel <<15));
}
__INLINE uint8_t macsys_gcu_smac_int_map_1_smac_int_10_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macsys_gcu_smac_int_map_1_smac_int_10_sel_setf(uint8_t smacint10sel)
{
	ASSERT_ERR((((uint32_t)smacint10sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)smacint10sel <<10));
}
__INLINE uint8_t macsys_gcu_smac_int_map_1_smac_int_9_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_smac_int_map_1_smac_int_9_sel_setf(uint8_t smacint9sel)
{
	ASSERT_ERR((((uint32_t)smacint9sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)smacint9sel <<5));
}
__INLINE uint8_t macsys_gcu_smac_int_map_1_smac_int_8_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_smac_int_map_1_smac_int_8_sel_setf(uint8_t smacint8sel)
{
	ASSERT_ERR((((uint32_t)smacint8sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)smacint8sel <<0));
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
#define MACSYS_GCU_SMAC_INT_MAP_2_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000174)
#define MACSYS_GCU_SMAC_INT_MAP_2_OFFSET      0x00000174
#define MACSYS_GCU_SMAC_INT_MAP_2_INDEX       0x0000005D
#define MACSYS_GCU_SMAC_INT_MAP_2_RESET       0x3FFFFFFF

__INLINE uint32_t  macsys_gcu_smac_int_map_2_get(void)
{
	return REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR);
}

__INLINE void macsys_gcu_smac_int_map_2_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_2_ADDR, value);
}

// field definitions
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_19_SEL_MASK    ((uint32_t)0x3E000000)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_19_SEL_LSB    25
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_19_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_18_SEL_MASK    ((uint32_t)0x01F00000)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_18_SEL_LSB    20
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_18_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_17_SEL_MASK    ((uint32_t)0x000F8000)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_17_SEL_LSB    15
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_17_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_16_SEL_MASK    ((uint32_t)0x00007C00)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_16_SEL_LSB    10
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_16_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_15_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_15_SEL_LSB    5
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_15_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_14_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_14_SEL_LSB    0
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_14_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_19_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_18_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_17_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_16_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_15_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_2_SMAC_INT_14_SEL_RST    0x1f

__INLINE void macsys_gcu_smac_int_map_2_pack(uint8_t smac_int19_sel, uint8_t smac_int18_sel, uint8_t smac_int17_sel, uint8_t smac_int16_sel, uint8_t smac_int15_sel, uint8_t smac_int14_sel)
{
	ASSERT_ERR((((uint32_t)smac_int19_sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int18_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int17_sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int16_sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)smac_int15_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)smac_int14_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_2_ADDR,  ((uint32_t)smac_int19_sel << 25) |((uint32_t)smac_int18_sel << 20) |((uint32_t)smac_int17_sel << 15) |((uint32_t)smac_int16_sel << 10) |((uint32_t)smac_int15_sel << 5) |((uint32_t)smac_int14_sel << 0));
}

__INLINE void macsys_gcu_smac_int_map_2_unpack(uint8_t* smac_int19_sel, uint8_t* smac_int18_sel, uint8_t* smac_int17_sel, uint8_t* smac_int16_sel, uint8_t* smac_int15_sel, uint8_t* smac_int14_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR);

	*smac_int19_sel = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*smac_int18_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*smac_int17_sel = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*smac_int16_sel = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*smac_int15_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*smac_int14_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_smac_int_map_2_smac_int_19_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void macsys_gcu_smac_int_map_2_smac_int_19_sel_setf(uint8_t smacint19sel)
{
	ASSERT_ERR((((uint32_t)smacint19sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)smacint19sel <<25));
}
__INLINE uint8_t macsys_gcu_smac_int_map_2_smac_int_18_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macsys_gcu_smac_int_map_2_smac_int_18_sel_setf(uint8_t smacint18sel)
{
	ASSERT_ERR((((uint32_t)smacint18sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)smacint18sel <<20));
}
__INLINE uint8_t macsys_gcu_smac_int_map_2_smac_int_17_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void macsys_gcu_smac_int_map_2_smac_int_17_sel_setf(uint8_t smacint17sel)
{
	ASSERT_ERR((((uint32_t)smacint17sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)smacint17sel <<15));
}
__INLINE uint8_t macsys_gcu_smac_int_map_2_smac_int_16_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macsys_gcu_smac_int_map_2_smac_int_16_sel_setf(uint8_t smacint16sel)
{
	ASSERT_ERR((((uint32_t)smacint16sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)smacint16sel <<10));
}
__INLINE uint8_t macsys_gcu_smac_int_map_2_smac_int_15_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_smac_int_map_2_smac_int_15_sel_setf(uint8_t smacint15sel)
{
	ASSERT_ERR((((uint32_t)smacint15sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)smacint15sel <<5));
}
__INLINE uint8_t macsys_gcu_smac_int_map_2_smac_int_14_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_smac_int_map_2_smac_int_14_sel_setf(uint8_t smacint14sel)
{
	ASSERT_ERR((((uint32_t)smacint14sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)smacint14sel <<0));
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
#define MACSYS_GCU_SMAC_INT_MAP_3_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000178)
#define MACSYS_GCU_SMAC_INT_MAP_3_OFFSET      0x00000178
#define MACSYS_GCU_SMAC_INT_MAP_3_INDEX       0x0000005E
#define MACSYS_GCU_SMAC_INT_MAP_3_RESET       0x3FFFFFFF

__INLINE uint32_t  macsys_gcu_smac_int_map_3_get(void)
{
	return REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR);
}

__INLINE void macsys_gcu_smac_int_map_3_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_3_ADDR, value);
}

// field definitions
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_28_SEL_MASK    ((uint32_t)0x3E000000)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_28_SEL_LSB    25
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_28_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_25_SEL_MASK    ((uint32_t)0x01F00000)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_25_SEL_LSB    20
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_25_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_24_SEL_MASK    ((uint32_t)0x000F8000)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_24_SEL_LSB    15
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_24_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_23_SEL_MASK    ((uint32_t)0x00007C00)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_23_SEL_LSB    10
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_23_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_22_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_22_SEL_LSB    5
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_22_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_21_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_21_SEL_LSB    0
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_21_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_28_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_25_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_24_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_23_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_22_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_3_SMAC_INT_21_SEL_RST    0x1f

__INLINE void macsys_gcu_smac_int_map_3_pack(uint8_t smac_int28_sel, uint8_t smac_int25_sel, uint8_t smac_int24_sel, uint8_t smac_int23_sel, uint8_t smac_int22_sel, uint8_t smac_int21_sel)
{
	ASSERT_ERR((((uint32_t)smac_int28_sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int25_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int24_sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)smac_int23_sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)smac_int22_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)smac_int21_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_3_ADDR,  ((uint32_t)smac_int28_sel << 25) |((uint32_t)smac_int25_sel << 20) |((uint32_t)smac_int24_sel << 15) |((uint32_t)smac_int23_sel << 10) |((uint32_t)smac_int22_sel << 5) |((uint32_t)smac_int21_sel << 0));
}

__INLINE void macsys_gcu_smac_int_map_3_unpack(uint8_t* smac_int28_sel, uint8_t* smac_int25_sel, uint8_t* smac_int24_sel, uint8_t* smac_int23_sel, uint8_t* smac_int22_sel, uint8_t* smac_int21_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR);

	*smac_int28_sel = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*smac_int25_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*smac_int24_sel = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*smac_int23_sel = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*smac_int22_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*smac_int21_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_smac_int_map_3_smac_int_28_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void macsys_gcu_smac_int_map_3_smac_int_28_sel_setf(uint8_t smacint28sel)
{
	ASSERT_ERR((((uint32_t)smacint28sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)smacint28sel <<25));
}
__INLINE uint8_t macsys_gcu_smac_int_map_3_smac_int_25_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macsys_gcu_smac_int_map_3_smac_int_25_sel_setf(uint8_t smacint25sel)
{
	ASSERT_ERR((((uint32_t)smacint25sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)smacint25sel <<20));
}
__INLINE uint8_t macsys_gcu_smac_int_map_3_smac_int_24_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void macsys_gcu_smac_int_map_3_smac_int_24_sel_setf(uint8_t smacint24sel)
{
	ASSERT_ERR((((uint32_t)smacint24sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)smacint24sel <<15));
}
__INLINE uint8_t macsys_gcu_smac_int_map_3_smac_int_23_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macsys_gcu_smac_int_map_3_smac_int_23_sel_setf(uint8_t smacint23sel)
{
	ASSERT_ERR((((uint32_t)smacint23sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)smacint23sel <<10));
}
__INLINE uint8_t macsys_gcu_smac_int_map_3_smac_int_22_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_smac_int_map_3_smac_int_22_sel_setf(uint8_t smacint22sel)
{
	ASSERT_ERR((((uint32_t)smacint22sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)smacint22sel <<5));
}
__INLINE uint8_t macsys_gcu_smac_int_map_3_smac_int_21_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_smac_int_map_3_smac_int_21_sel_setf(uint8_t smacint21sel)
{
	ASSERT_ERR((((uint32_t)smacint21sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)smacint21sel <<0));
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
#define MACSYS_GCU_SMAC_INT_MAP_4_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x0000017C)
#define MACSYS_GCU_SMAC_INT_MAP_4_OFFSET      0x0000017C
#define MACSYS_GCU_SMAC_INT_MAP_4_INDEX       0x0000005F
#define MACSYS_GCU_SMAC_INT_MAP_4_RESET       0x000003FF

__INLINE uint32_t  macsys_gcu_smac_int_map_4_get(void)
{
	return REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_4_ADDR);
}

__INLINE void macsys_gcu_smac_int_map_4_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_4_ADDR, value);
}

// field definitions
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_30_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_30_SEL_LSB    5
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_30_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_29_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_29_SEL_LSB    0
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_29_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_30_SEL_RST    0x1f
#define MACSYS_GCU_SMAC_INT_MAP_4_SMAC_INT_29_SEL_RST    0x1f

__INLINE void macsys_gcu_smac_int_map_4_pack(uint8_t smac_int30_sel, uint8_t smac_int29_sel)
{
	ASSERT_ERR((((uint32_t)smac_int30_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)smac_int29_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_4_ADDR,  ((uint32_t)smac_int30_sel << 5) |((uint32_t)smac_int29_sel << 0));
}

__INLINE void macsys_gcu_smac_int_map_4_unpack(uint8_t* smac_int30_sel, uint8_t* smac_int29_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_4_ADDR);

	*smac_int30_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*smac_int29_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_smac_int_map_4_smac_int_30_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_smac_int_map_4_smac_int_30_sel_setf(uint8_t smacint30sel)
{
	ASSERT_ERR((((uint32_t)smacint30sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_4_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_4_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)smacint30sel <<5));
}
__INLINE uint8_t macsys_gcu_smac_int_map_4_smac_int_29_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_smac_int_map_4_smac_int_29_sel_setf(uint8_t smacint29sel)
{
	ASSERT_ERR((((uint32_t)smacint29sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_SMAC_INT_MAP_4_ADDR, (REG_PL_RD(MACSYS_GCU_SMAC_INT_MAP_4_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)smacint29sel <<0));
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
#define MACSYS_GCU_LMAC_INT_MAP_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000180)
#define MACSYS_GCU_LMAC_INT_MAP_0_OFFSET      0x00000180
#define MACSYS_GCU_LMAC_INT_MAP_0_INDEX       0x00000060
#define MACSYS_GCU_LMAC_INT_MAP_0_RESET       0x7FFFFFFF

__INLINE uint32_t  macsys_gcu_lmac_int_map_0_get(void)
{
	return REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR);
}

__INLINE void macsys_gcu_lmac_int_map_0_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_0_ADDR, value);
}

// field definitions
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_7_SEL_MASK    ((uint32_t)0x3E000000)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_7_SEL_LSB    25
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_7_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_6_SEL_MASK    ((uint32_t)0x01F00000)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_6_SEL_LSB    20
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_6_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_5_SEL_MASK    ((uint32_t)0x000F8000)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_5_SEL_LSB    15
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_5_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_4_SEL_MASK    ((uint32_t)0x00007C00)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_4_SEL_LSB    10
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_4_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_3_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_3_SEL_LSB    5
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_3_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_2_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_2_SEL_LSB    0
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_2_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_7_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_6_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_5_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_4_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_3_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_0_LMAC_INT_2_SEL_RST    0x1f

__INLINE void macsys_gcu_lmac_int_map_0_pack(uint8_t lmac_int7_sel, uint8_t lmac_int6_sel, uint8_t lmac_int5_sel, uint8_t lmac_int4_sel, uint8_t lmac_int3_sel, uint8_t lmac_int2_sel)
{
	ASSERT_ERR((((uint32_t)lmac_int7_sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int6_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int5_sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int4_sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int3_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int2_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_0_ADDR,  ((uint32_t)lmac_int7_sel << 25) |((uint32_t)lmac_int6_sel << 20) |((uint32_t)lmac_int5_sel << 15) |((uint32_t)lmac_int4_sel << 10) |((uint32_t)lmac_int3_sel << 5) |((uint32_t)lmac_int2_sel << 0));
}

__INLINE void macsys_gcu_lmac_int_map_0_unpack(uint8_t* lmac_int7_sel, uint8_t* lmac_int6_sel, uint8_t* lmac_int5_sel, uint8_t* lmac_int4_sel, uint8_t* lmac_int3_sel, uint8_t* lmac_int2_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR);

	*lmac_int7_sel = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*lmac_int6_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*lmac_int5_sel = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*lmac_int4_sel = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*lmac_int3_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*lmac_int2_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_lmac_int_map_0_lmac_int_7_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void macsys_gcu_lmac_int_map_0_lmac_int_7_sel_setf(uint8_t lmacint7sel)
{
	ASSERT_ERR((((uint32_t)lmacint7sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)lmacint7sel <<25));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_0_lmac_int_6_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macsys_gcu_lmac_int_map_0_lmac_int_6_sel_setf(uint8_t lmacint6sel)
{
	ASSERT_ERR((((uint32_t)lmacint6sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)lmacint6sel <<20));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_0_lmac_int_5_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void macsys_gcu_lmac_int_map_0_lmac_int_5_sel_setf(uint8_t lmacint5sel)
{
	ASSERT_ERR((((uint32_t)lmacint5sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)lmacint5sel <<15));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_0_lmac_int_4_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macsys_gcu_lmac_int_map_0_lmac_int_4_sel_setf(uint8_t lmacint4sel)
{
	ASSERT_ERR((((uint32_t)lmacint4sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)lmacint4sel <<10));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_0_lmac_int_3_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_lmac_int_map_0_lmac_int_3_sel_setf(uint8_t lmacint3sel)
{
	ASSERT_ERR((((uint32_t)lmacint3sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)lmacint3sel <<5));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_0_lmac_int_2_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_lmac_int_map_0_lmac_int_2_sel_setf(uint8_t lmacint2sel)
{
	ASSERT_ERR((((uint32_t)lmacint2sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)lmacint2sel <<0));
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
#define MACSYS_GCU_LMAC_INT_MAP_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000184)
#define MACSYS_GCU_LMAC_INT_MAP_1_OFFSET      0x00000184
#define MACSYS_GCU_LMAC_INT_MAP_1_INDEX       0x00000061
#define MACSYS_GCU_LMAC_INT_MAP_1_RESET       0x7FFFFFFF

__INLINE uint32_t  macsys_gcu_lmac_int_map_1_get(void)
{
	return REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR);
}

__INLINE void macsys_gcu_lmac_int_map_1_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_1_ADDR, value);
}

// field definitions
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_13_SEL_MASK    ((uint32_t)0x3E000000)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_13_SEL_LSB    25
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_13_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_12_SEL_MASK    ((uint32_t)0x01F00000)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_12_SEL_LSB    20
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_12_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_11_SEL_MASK    ((uint32_t)0x000F8000)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_11_SEL_LSB    15
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_11_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_10_SEL_MASK    ((uint32_t)0x00007C00)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_10_SEL_LSB    10
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_10_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_9_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_9_SEL_LSB    5
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_9_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_8_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_8_SEL_LSB    0
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_8_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_13_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_12_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_11_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_10_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_9_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_1_LMAC_INT_8_SEL_RST    0x1f

__INLINE void macsys_gcu_lmac_int_map_1_pack(uint8_t lmac_int13_sel, uint8_t lmac_int12_sel, uint8_t lmac_int11_sel, uint8_t lmac_int10_sel, uint8_t lmac_int9_sel, uint8_t lmac_int8_sel)
{
	ASSERT_ERR((((uint32_t)lmac_int13_sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int12_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int11_sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int10_sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int9_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int8_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_1_ADDR,  ((uint32_t)lmac_int13_sel << 25) |((uint32_t)lmac_int12_sel << 20) |((uint32_t)lmac_int11_sel << 15) |((uint32_t)lmac_int10_sel << 10) |((uint32_t)lmac_int9_sel << 5) |((uint32_t)lmac_int8_sel << 0));
}

__INLINE void macsys_gcu_lmac_int_map_1_unpack(uint8_t* lmac_int13_sel, uint8_t* lmac_int12_sel, uint8_t* lmac_int11_sel, uint8_t* lmac_int10_sel, uint8_t* lmac_int9_sel, uint8_t* lmac_int8_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR);

	*lmac_int13_sel = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*lmac_int12_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*lmac_int11_sel = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*lmac_int10_sel = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*lmac_int9_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*lmac_int8_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_lmac_int_map_1_lmac_int_13_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void macsys_gcu_lmac_int_map_1_lmac_int_13_sel_setf(uint8_t lmacint13sel)
{
	ASSERT_ERR((((uint32_t)lmacint13sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)lmacint13sel <<25));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_1_lmac_int_12_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macsys_gcu_lmac_int_map_1_lmac_int_12_sel_setf(uint8_t lmacint12sel)
{
	ASSERT_ERR((((uint32_t)lmacint12sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)lmacint12sel <<20));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_1_lmac_int_11_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void macsys_gcu_lmac_int_map_1_lmac_int_11_sel_setf(uint8_t lmacint11sel)
{
	ASSERT_ERR((((uint32_t)lmacint11sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)lmacint11sel <<15));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_1_lmac_int_10_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macsys_gcu_lmac_int_map_1_lmac_int_10_sel_setf(uint8_t lmacint10sel)
{
	ASSERT_ERR((((uint32_t)lmacint10sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)lmacint10sel <<10));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_1_lmac_int_9_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_lmac_int_map_1_lmac_int_9_sel_setf(uint8_t lmacint9sel)
{
	ASSERT_ERR((((uint32_t)lmacint9sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)lmacint9sel <<5));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_1_lmac_int_8_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_lmac_int_map_1_lmac_int_8_sel_setf(uint8_t lmacint8sel)
{
	ASSERT_ERR((((uint32_t)lmacint8sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)lmacint8sel <<0));
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
#define MACSYS_GCU_LMAC_INT_MAP_2_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000188)
#define MACSYS_GCU_LMAC_INT_MAP_2_OFFSET      0x00000188
#define MACSYS_GCU_LMAC_INT_MAP_2_INDEX       0x00000062
#define MACSYS_GCU_LMAC_INT_MAP_2_RESET       0x3FFFFFFF

__INLINE uint32_t  macsys_gcu_lmac_int_map_2_get(void)
{
	return REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR);
}

__INLINE void macsys_gcu_lmac_int_map_2_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_2_ADDR, value);
}

// field definitions
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_19_SEL_MASK    ((uint32_t)0x3E000000)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_19_SEL_LSB    25
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_19_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_18_SEL_MASK    ((uint32_t)0x01F00000)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_18_SEL_LSB    20
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_18_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_17_SEL_MASK    ((uint32_t)0x000F8000)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_17_SEL_LSB    15
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_17_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_16_SEL_MASK    ((uint32_t)0x00007C00)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_16_SEL_LSB    10
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_16_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_15_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_15_SEL_LSB    5
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_15_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_14_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_14_SEL_LSB    0
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_14_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_19_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_18_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_17_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_16_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_15_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_2_LMAC_INT_14_SEL_RST    0x1f

__INLINE void macsys_gcu_lmac_int_map_2_pack(uint8_t lmac_int19_sel, uint8_t lmac_int18_sel, uint8_t lmac_int17_sel, uint8_t lmac_int16_sel, uint8_t lmac_int15_sel, uint8_t lmac_int14_sel)
{
	ASSERT_ERR((((uint32_t)lmac_int19_sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int18_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int17_sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int16_sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int15_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int14_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_2_ADDR,  ((uint32_t)lmac_int19_sel << 25) |((uint32_t)lmac_int18_sel << 20) |((uint32_t)lmac_int17_sel << 15) |((uint32_t)lmac_int16_sel << 10) |((uint32_t)lmac_int15_sel << 5) |((uint32_t)lmac_int14_sel << 0));
}

__INLINE void macsys_gcu_lmac_int_map_2_unpack(uint8_t* lmac_int19_sel, uint8_t* lmac_int18_sel, uint8_t* lmac_int17_sel, uint8_t* lmac_int16_sel, uint8_t* lmac_int15_sel, uint8_t* lmac_int14_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR);

	*lmac_int19_sel = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*lmac_int18_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*lmac_int17_sel = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*lmac_int16_sel = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*lmac_int15_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*lmac_int14_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_lmac_int_map_2_lmac_int_19_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void macsys_gcu_lmac_int_map_2_lmac_int_19_sel_setf(uint8_t lmacint19sel)
{
	ASSERT_ERR((((uint32_t)lmacint19sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)lmacint19sel <<25));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_2_lmac_int_18_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macsys_gcu_lmac_int_map_2_lmac_int_18_sel_setf(uint8_t lmacint18sel)
{
	ASSERT_ERR((((uint32_t)lmacint18sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)lmacint18sel <<20));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_2_lmac_int_17_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void macsys_gcu_lmac_int_map_2_lmac_int_17_sel_setf(uint8_t lmacint17sel)
{
	ASSERT_ERR((((uint32_t)lmacint17sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)lmacint17sel <<15));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_2_lmac_int_16_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macsys_gcu_lmac_int_map_2_lmac_int_16_sel_setf(uint8_t lmacint16sel)
{
	ASSERT_ERR((((uint32_t)lmacint16sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)lmacint16sel <<10));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_2_lmac_int_15_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_lmac_int_map_2_lmac_int_15_sel_setf(uint8_t lmacint15sel)
{
	ASSERT_ERR((((uint32_t)lmacint15sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)lmacint15sel <<5));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_2_lmac_int_14_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_lmac_int_map_2_lmac_int_14_sel_setf(uint8_t lmacint14sel)
{
	ASSERT_ERR((((uint32_t)lmacint14sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)lmacint14sel <<0));
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
#define MACSYS_GCU_LMAC_INT_MAP_3_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x0000018C)
#define MACSYS_GCU_LMAC_INT_MAP_3_OFFSET      0x0000018C
#define MACSYS_GCU_LMAC_INT_MAP_3_INDEX       0x00000063
#define MACSYS_GCU_LMAC_INT_MAP_3_RESET       0x3FFFFFFF

__INLINE uint32_t  macsys_gcu_lmac_int_map_3_get(void)
{
	return REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR);
}

__INLINE void macsys_gcu_lmac_int_map_3_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_3_ADDR, value);
}

// field definitions
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_28_SEL_MASK    ((uint32_t)0x3E000000)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_28_SEL_LSB    25
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_28_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_25_SEL_MASK    ((uint32_t)0x01F00000)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_25_SEL_LSB    20
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_25_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_24_SEL_MASK    ((uint32_t)0x000F8000)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_24_SEL_LSB    15
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_24_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_23_SEL_MASK    ((uint32_t)0x00007C00)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_23_SEL_LSB    10
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_23_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_22_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_22_SEL_LSB    5
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_22_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_21_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_21_SEL_LSB    0
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_21_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_28_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_25_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_24_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_23_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_22_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_3_LMAC_INT_21_SEL_RST    0x1f

__INLINE void macsys_gcu_lmac_int_map_3_pack(uint8_t lmac_int28_sel, uint8_t lmac_int25_sel, uint8_t lmac_int24_sel, uint8_t lmac_int23_sel, uint8_t lmac_int22_sel, uint8_t lmac_int21_sel)
{
	ASSERT_ERR((((uint32_t)lmac_int28_sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int25_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int24_sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int23_sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int22_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int21_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_3_ADDR,  ((uint32_t)lmac_int28_sel << 25) |((uint32_t)lmac_int25_sel << 20) |((uint32_t)lmac_int24_sel << 15) |((uint32_t)lmac_int23_sel << 10) |((uint32_t)lmac_int22_sel << 5) |((uint32_t)lmac_int21_sel << 0));
}

__INLINE void macsys_gcu_lmac_int_map_3_unpack(uint8_t* lmac_int28_sel, uint8_t* lmac_int25_sel, uint8_t* lmac_int24_sel, uint8_t* lmac_int23_sel, uint8_t* lmac_int22_sel, uint8_t* lmac_int21_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR);

	*lmac_int28_sel = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*lmac_int25_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*lmac_int24_sel = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*lmac_int23_sel = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*lmac_int22_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*lmac_int21_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_lmac_int_map_3_lmac_int_28_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void macsys_gcu_lmac_int_map_3_lmac_int_28_sel_setf(uint8_t lmacint28sel)
{
	ASSERT_ERR((((uint32_t)lmacint28sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)lmacint28sel <<25));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_3_lmac_int_25_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macsys_gcu_lmac_int_map_3_lmac_int_25_sel_setf(uint8_t lmacint25sel)
{
	ASSERT_ERR((((uint32_t)lmacint25sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)lmacint25sel <<20));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_3_lmac_int_24_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void macsys_gcu_lmac_int_map_3_lmac_int_24_sel_setf(uint8_t lmacint24sel)
{
	ASSERT_ERR((((uint32_t)lmacint24sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)lmacint24sel <<15));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_3_lmac_int_23_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macsys_gcu_lmac_int_map_3_lmac_int_23_sel_setf(uint8_t lmacint23sel)
{
	ASSERT_ERR((((uint32_t)lmacint23sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)lmacint23sel <<10));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_3_lmac_int_22_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_lmac_int_map_3_lmac_int_22_sel_setf(uint8_t lmacint22sel)
{
	ASSERT_ERR((((uint32_t)lmacint22sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)lmacint22sel <<5));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_3_lmac_int_21_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_lmac_int_map_3_lmac_int_21_sel_setf(uint8_t lmacint21sel)
{
	ASSERT_ERR((((uint32_t)lmacint21sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)lmacint21sel <<0));
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
#define MACSYS_GCU_LMAC_INT_MAP_4_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000190)
#define MACSYS_GCU_LMAC_INT_MAP_4_OFFSET      0x00000190
#define MACSYS_GCU_LMAC_INT_MAP_4_INDEX       0x00000064
#define MACSYS_GCU_LMAC_INT_MAP_4_RESET       0x000003FF

__INLINE uint32_t  macsys_gcu_lmac_int_map_4_get(void)
{
	return REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_4_ADDR);
}

__INLINE void macsys_gcu_lmac_int_map_4_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_4_ADDR, value);
}

// field definitions
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_30_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_30_SEL_LSB    5
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_30_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_29_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_29_SEL_LSB    0
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_29_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_30_SEL_RST    0x1f
#define MACSYS_GCU_LMAC_INT_MAP_4_LMAC_INT_29_SEL_RST    0x1f

__INLINE void macsys_gcu_lmac_int_map_4_pack(uint8_t lmac_int30_sel, uint8_t lmac_int29_sel)
{
	ASSERT_ERR((((uint32_t)lmac_int30_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)lmac_int29_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_4_ADDR,  ((uint32_t)lmac_int30_sel << 5) |((uint32_t)lmac_int29_sel << 0));
}

__INLINE void macsys_gcu_lmac_int_map_4_unpack(uint8_t* lmac_int30_sel, uint8_t* lmac_int29_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_4_ADDR);

	*lmac_int30_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*lmac_int29_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_lmac_int_map_4_lmac_int_30_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_lmac_int_map_4_lmac_int_30_sel_setf(uint8_t lmacint30sel)
{
	ASSERT_ERR((((uint32_t)lmacint30sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_4_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_4_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)lmacint30sel <<5));
}
__INLINE uint8_t macsys_gcu_lmac_int_map_4_lmac_int_29_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_lmac_int_map_4_lmac_int_29_sel_setf(uint8_t lmacint29sel)
{
	ASSERT_ERR((((uint32_t)lmacint29sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_LMAC_INT_MAP_4_ADDR, (REG_PL_RD(MACSYS_GCU_LMAC_INT_MAP_4_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)lmacint29sel <<0));
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
#define MACSYS_GCU_UMAC_INT_MAP_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000194)
#define MACSYS_GCU_UMAC_INT_MAP_0_OFFSET      0x00000194
#define MACSYS_GCU_UMAC_INT_MAP_0_INDEX       0x00000065
#define MACSYS_GCU_UMAC_INT_MAP_0_RESET       0x3FFFFFFF

__INLINE uint32_t  macsys_gcu_umac_int_map_0_get(void)
{
	return REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR);
}

__INLINE void macsys_gcu_umac_int_map_0_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_0_ADDR, value);
}

// field definitions
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_7_SEL_MASK    ((uint32_t)0x3E000000)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_7_SEL_LSB    25
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_7_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_6_SEL_MASK    ((uint32_t)0x01F00000)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_6_SEL_LSB    20
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_6_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_5_SEL_MASK    ((uint32_t)0x000F8000)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_5_SEL_LSB    15
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_5_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_4_SEL_MASK    ((uint32_t)0x00007C00)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_4_SEL_LSB    10
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_4_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_3_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_3_SEL_LSB    5
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_3_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_2_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_2_SEL_LSB    0
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_2_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_7_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_6_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_5_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_4_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_3_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_0_UMAC_INT_2_SEL_RST    0x1f

__INLINE void macsys_gcu_umac_int_map_0_pack(uint8_t umac_int7_sel, uint8_t umac_int6_sel, uint8_t umac_int5_sel, uint8_t umac_int4_sel, uint8_t umac_int3_sel, uint8_t umac_int2_sel)
{
	ASSERT_ERR((((uint32_t)umac_int7_sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int6_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int5_sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int4_sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)umac_int3_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)umac_int2_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_0_ADDR,  ((uint32_t)umac_int7_sel << 25) |((uint32_t)umac_int6_sel << 20) |((uint32_t)umac_int5_sel << 15) |((uint32_t)umac_int4_sel << 10) |((uint32_t)umac_int3_sel << 5) |((uint32_t)umac_int2_sel << 0));
}

__INLINE void macsys_gcu_umac_int_map_0_unpack(uint8_t* umac_int7_sel, uint8_t* umac_int6_sel, uint8_t* umac_int5_sel, uint8_t* umac_int4_sel, uint8_t* umac_int3_sel, uint8_t* umac_int2_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR);

	*umac_int7_sel = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*umac_int6_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*umac_int5_sel = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*umac_int4_sel = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*umac_int3_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*umac_int2_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_umac_int_map_0_umac_int_7_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void macsys_gcu_umac_int_map_0_umac_int_7_sel_setf(uint8_t umacint7sel)
{
	ASSERT_ERR((((uint32_t)umacint7sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)umacint7sel <<25));
}
__INLINE uint8_t macsys_gcu_umac_int_map_0_umac_int_6_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macsys_gcu_umac_int_map_0_umac_int_6_sel_setf(uint8_t umacint6sel)
{
	ASSERT_ERR((((uint32_t)umacint6sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)umacint6sel <<20));
}
__INLINE uint8_t macsys_gcu_umac_int_map_0_umac_int_5_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void macsys_gcu_umac_int_map_0_umac_int_5_sel_setf(uint8_t umacint5sel)
{
	ASSERT_ERR((((uint32_t)umacint5sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)umacint5sel <<15));
}
__INLINE uint8_t macsys_gcu_umac_int_map_0_umac_int_4_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macsys_gcu_umac_int_map_0_umac_int_4_sel_setf(uint8_t umacint4sel)
{
	ASSERT_ERR((((uint32_t)umacint4sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)umacint4sel <<10));
}
__INLINE uint8_t macsys_gcu_umac_int_map_0_umac_int_3_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_umac_int_map_0_umac_int_3_sel_setf(uint8_t umacint3sel)
{
	ASSERT_ERR((((uint32_t)umacint3sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)umacint3sel <<5));
}
__INLINE uint8_t macsys_gcu_umac_int_map_0_umac_int_2_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_umac_int_map_0_umac_int_2_sel_setf(uint8_t umacint2sel)
{
	ASSERT_ERR((((uint32_t)umacint2sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_0_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_0_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)umacint2sel <<0));
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
#define MACSYS_GCU_UMAC_INT_MAP_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x00000198)
#define MACSYS_GCU_UMAC_INT_MAP_1_OFFSET      0x00000198
#define MACSYS_GCU_UMAC_INT_MAP_1_INDEX       0x00000066
#define MACSYS_GCU_UMAC_INT_MAP_1_RESET       0x3FFFFFFF

__INLINE uint32_t  macsys_gcu_umac_int_map_1_get(void)
{
	return REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR);
}

__INLINE void macsys_gcu_umac_int_map_1_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_1_ADDR, value);
}

// field definitions
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_13_SEL_MASK    ((uint32_t)0x3E000000)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_13_SEL_LSB    25
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_13_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_12_SEL_MASK    ((uint32_t)0x01F00000)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_12_SEL_LSB    20
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_12_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_11_SEL_MASK    ((uint32_t)0x000F8000)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_11_SEL_LSB    15
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_11_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_10_SEL_MASK    ((uint32_t)0x00007C00)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_10_SEL_LSB    10
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_10_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_9_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_9_SEL_LSB    5
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_9_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_8_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_8_SEL_LSB    0
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_8_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_13_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_12_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_11_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_10_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_9_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_1_UMAC_INT_8_SEL_RST    0x1f

__INLINE void macsys_gcu_umac_int_map_1_pack(uint8_t umac_int13_sel, uint8_t umac_int12_sel, uint8_t umac_int11_sel, uint8_t umac_int10_sel, uint8_t umac_int9_sel, uint8_t umac_int8_sel)
{
	ASSERT_ERR((((uint32_t)umac_int13_sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int12_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int11_sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int10_sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)umac_int9_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)umac_int8_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_1_ADDR,  ((uint32_t)umac_int13_sel << 25) |((uint32_t)umac_int12_sel << 20) |((uint32_t)umac_int11_sel << 15) |((uint32_t)umac_int10_sel << 10) |((uint32_t)umac_int9_sel << 5) |((uint32_t)umac_int8_sel << 0));
}

__INLINE void macsys_gcu_umac_int_map_1_unpack(uint8_t* umac_int13_sel, uint8_t* umac_int12_sel, uint8_t* umac_int11_sel, uint8_t* umac_int10_sel, uint8_t* umac_int9_sel, uint8_t* umac_int8_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR);

	*umac_int13_sel = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*umac_int12_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*umac_int11_sel = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*umac_int10_sel = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*umac_int9_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*umac_int8_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_umac_int_map_1_umac_int_13_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void macsys_gcu_umac_int_map_1_umac_int_13_sel_setf(uint8_t umacint13sel)
{
	ASSERT_ERR((((uint32_t)umacint13sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)umacint13sel <<25));
}
__INLINE uint8_t macsys_gcu_umac_int_map_1_umac_int_12_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macsys_gcu_umac_int_map_1_umac_int_12_sel_setf(uint8_t umacint12sel)
{
	ASSERT_ERR((((uint32_t)umacint12sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)umacint12sel <<20));
}
__INLINE uint8_t macsys_gcu_umac_int_map_1_umac_int_11_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void macsys_gcu_umac_int_map_1_umac_int_11_sel_setf(uint8_t umacint11sel)
{
	ASSERT_ERR((((uint32_t)umacint11sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)umacint11sel <<15));
}
__INLINE uint8_t macsys_gcu_umac_int_map_1_umac_int_10_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macsys_gcu_umac_int_map_1_umac_int_10_sel_setf(uint8_t umacint10sel)
{
	ASSERT_ERR((((uint32_t)umacint10sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)umacint10sel <<10));
}
__INLINE uint8_t macsys_gcu_umac_int_map_1_umac_int_9_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_umac_int_map_1_umac_int_9_sel_setf(uint8_t umacint9sel)
{
	ASSERT_ERR((((uint32_t)umacint9sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)umacint9sel <<5));
}
__INLINE uint8_t macsys_gcu_umac_int_map_1_umac_int_8_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_umac_int_map_1_umac_int_8_sel_setf(uint8_t umacint8sel)
{
	ASSERT_ERR((((uint32_t)umacint8sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_1_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_1_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)umacint8sel <<0));
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
#define MACSYS_GCU_UMAC_INT_MAP_2_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x0000019C)
#define MACSYS_GCU_UMAC_INT_MAP_2_OFFSET      0x0000019C
#define MACSYS_GCU_UMAC_INT_MAP_2_INDEX       0x00000067
#define MACSYS_GCU_UMAC_INT_MAP_2_RESET       0x3FFFFFFF

__INLINE uint32_t  macsys_gcu_umac_int_map_2_get(void)
{
	return REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR);
}

__INLINE void macsys_gcu_umac_int_map_2_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_2_ADDR, value);
}

// field definitions
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_19_SEL_MASK    ((uint32_t)0x3E000000)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_19_SEL_LSB    25
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_19_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_18_SEL_MASK    ((uint32_t)0x01F00000)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_18_SEL_LSB    20
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_18_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_17_SEL_MASK    ((uint32_t)0x000F8000)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_17_SEL_LSB    15
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_17_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_16_SEL_MASK    ((uint32_t)0x00007C00)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_16_SEL_LSB    10
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_16_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_15_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_15_SEL_LSB    5
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_15_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_14_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_14_SEL_LSB    0
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_14_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_19_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_18_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_17_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_16_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_15_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_2_UMAC_INT_14_SEL_RST    0x1f

__INLINE void macsys_gcu_umac_int_map_2_pack(uint8_t umac_int19_sel, uint8_t umac_int18_sel, uint8_t umac_int17_sel, uint8_t umac_int16_sel, uint8_t umac_int15_sel, uint8_t umac_int14_sel)
{
	ASSERT_ERR((((uint32_t)umac_int19_sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int18_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int17_sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int16_sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)umac_int15_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)umac_int14_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_2_ADDR,  ((uint32_t)umac_int19_sel << 25) |((uint32_t)umac_int18_sel << 20) |((uint32_t)umac_int17_sel << 15) |((uint32_t)umac_int16_sel << 10) |((uint32_t)umac_int15_sel << 5) |((uint32_t)umac_int14_sel << 0));
}

__INLINE void macsys_gcu_umac_int_map_2_unpack(uint8_t* umac_int19_sel, uint8_t* umac_int18_sel, uint8_t* umac_int17_sel, uint8_t* umac_int16_sel, uint8_t* umac_int15_sel, uint8_t* umac_int14_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR);

	*umac_int19_sel = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*umac_int18_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*umac_int17_sel = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*umac_int16_sel = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*umac_int15_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*umac_int14_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_umac_int_map_2_umac_int_19_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void macsys_gcu_umac_int_map_2_umac_int_19_sel_setf(uint8_t umacint19sel)
{
	ASSERT_ERR((((uint32_t)umacint19sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)umacint19sel <<25));
}
__INLINE uint8_t macsys_gcu_umac_int_map_2_umac_int_18_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macsys_gcu_umac_int_map_2_umac_int_18_sel_setf(uint8_t umacint18sel)
{
	ASSERT_ERR((((uint32_t)umacint18sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)umacint18sel <<20));
}
__INLINE uint8_t macsys_gcu_umac_int_map_2_umac_int_17_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void macsys_gcu_umac_int_map_2_umac_int_17_sel_setf(uint8_t umacint17sel)
{
	ASSERT_ERR((((uint32_t)umacint17sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)umacint17sel <<15));
}
__INLINE uint8_t macsys_gcu_umac_int_map_2_umac_int_16_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macsys_gcu_umac_int_map_2_umac_int_16_sel_setf(uint8_t umacint16sel)
{
	ASSERT_ERR((((uint32_t)umacint16sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)umacint16sel <<10));
}
__INLINE uint8_t macsys_gcu_umac_int_map_2_umac_int_15_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_umac_int_map_2_umac_int_15_sel_setf(uint8_t umacint15sel)
{
	ASSERT_ERR((((uint32_t)umacint15sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)umacint15sel <<5));
}
__INLINE uint8_t macsys_gcu_umac_int_map_2_umac_int_14_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_umac_int_map_2_umac_int_14_sel_setf(uint8_t umacint14sel)
{
	ASSERT_ERR((((uint32_t)umacint14sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_2_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_2_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)umacint14sel <<0));
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
#define MACSYS_GCU_UMAC_INT_MAP_3_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001A0)
#define MACSYS_GCU_UMAC_INT_MAP_3_OFFSET      0x000001A0
#define MACSYS_GCU_UMAC_INT_MAP_3_INDEX       0x00000068
#define MACSYS_GCU_UMAC_INT_MAP_3_RESET       0x3FFFFFFF

__INLINE uint32_t  macsys_gcu_umac_int_map_3_get(void)
{
	return REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR);
}

__INLINE void macsys_gcu_umac_int_map_3_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_3_ADDR, value);
}

// field definitions
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_28_SEL_MASK    ((uint32_t)0x3E000000)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_28_SEL_LSB    25
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_28_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_25_SEL_MASK    ((uint32_t)0x01F00000)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_25_SEL_LSB    20
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_25_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_24_SEL_MASK    ((uint32_t)0x000F8000)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_24_SEL_LSB    15
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_24_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_23_SEL_MASK    ((uint32_t)0x00007C00)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_23_SEL_LSB    10
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_23_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_22_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_22_SEL_LSB    5
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_22_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_21_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_21_SEL_LSB    0
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_21_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_28_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_25_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_24_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_23_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_22_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_3_UMAC_INT_21_SEL_RST    0x1f

__INLINE void macsys_gcu_umac_int_map_3_pack(uint8_t umac_int28_sel, uint8_t umac_int25_sel, uint8_t umac_int24_sel, uint8_t umac_int23_sel, uint8_t umac_int22_sel, uint8_t umac_int21_sel)
{
	ASSERT_ERR((((uint32_t)umac_int28_sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int25_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int24_sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	ASSERT_ERR((((uint32_t)umac_int23_sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)umac_int22_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)umac_int21_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_3_ADDR,  ((uint32_t)umac_int28_sel << 25) |((uint32_t)umac_int25_sel << 20) |((uint32_t)umac_int24_sel << 15) |((uint32_t)umac_int23_sel << 10) |((uint32_t)umac_int22_sel << 5) |((uint32_t)umac_int21_sel << 0));
}

__INLINE void macsys_gcu_umac_int_map_3_unpack(uint8_t* umac_int28_sel, uint8_t* umac_int25_sel, uint8_t* umac_int24_sel, uint8_t* umac_int23_sel, uint8_t* umac_int22_sel, uint8_t* umac_int21_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR);

	*umac_int28_sel = (localVal & ((uint32_t)0x3E000000)) >>  25;
	*umac_int25_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*umac_int24_sel = (localVal & ((uint32_t)0x000F8000)) >>  15;
	*umac_int23_sel = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*umac_int22_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*umac_int21_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_umac_int_map_3_umac_int_28_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3E000000)) >> 25);
}
__INLINE void macsys_gcu_umac_int_map_3_umac_int_28_sel_setf(uint8_t umacint28sel)
{
	ASSERT_ERR((((uint32_t)umacint28sel << 25) & ~((uint32_t)0x3E000000)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x3E000000)) | ((uint32_t)umacint28sel <<25));
}
__INLINE uint8_t macsys_gcu_umac_int_map_3_umac_int_25_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macsys_gcu_umac_int_map_3_umac_int_25_sel_setf(uint8_t umacint25sel)
{
	ASSERT_ERR((((uint32_t)umacint25sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)umacint25sel <<20));
}
__INLINE uint8_t macsys_gcu_umac_int_map_3_umac_int_24_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F8000)) >> 15);
}
__INLINE void macsys_gcu_umac_int_map_3_umac_int_24_sel_setf(uint8_t umacint24sel)
{
	ASSERT_ERR((((uint32_t)umacint24sel << 15) & ~((uint32_t)0x000F8000)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x000F8000)) | ((uint32_t)umacint24sel <<15));
}
__INLINE uint8_t macsys_gcu_umac_int_map_3_umac_int_23_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macsys_gcu_umac_int_map_3_umac_int_23_sel_setf(uint8_t umacint23sel)
{
	ASSERT_ERR((((uint32_t)umacint23sel << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)umacint23sel <<10));
}
__INLINE uint8_t macsys_gcu_umac_int_map_3_umac_int_22_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_umac_int_map_3_umac_int_22_sel_setf(uint8_t umacint22sel)
{
	ASSERT_ERR((((uint32_t)umacint22sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)umacint22sel <<5));
}
__INLINE uint8_t macsys_gcu_umac_int_map_3_umac_int_21_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_umac_int_map_3_umac_int_21_sel_setf(uint8_t umacint21sel)
{
	ASSERT_ERR((((uint32_t)umacint21sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_3_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_3_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)umacint21sel <<0));
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
#define MACSYS_GCU_UMAC_INT_MAP_4_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001A4)
#define MACSYS_GCU_UMAC_INT_MAP_4_OFFSET      0x000001A4
#define MACSYS_GCU_UMAC_INT_MAP_4_INDEX       0x00000069
#define MACSYS_GCU_UMAC_INT_MAP_4_RESET       0x000003FF

__INLINE uint32_t  macsys_gcu_umac_int_map_4_get(void)
{
	return REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_4_ADDR);
}

__INLINE void macsys_gcu_umac_int_map_4_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_4_ADDR, value);
}

// field definitions
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_30_SEL_MASK    ((uint32_t)0x000003E0)
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_30_SEL_LSB    5
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_30_SEL_WIDTH    ((uint32_t)0x00000005)
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_29_SEL_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_29_SEL_LSB    0
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_29_SEL_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_30_SEL_RST    0x1f
#define MACSYS_GCU_UMAC_INT_MAP_4_UMAC_INT_29_SEL_RST    0x1f

__INLINE void macsys_gcu_umac_int_map_4_pack(uint8_t umac_int30_sel, uint8_t umac_int29_sel)
{
	ASSERT_ERR((((uint32_t)umac_int30_sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)umac_int29_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_4_ADDR,  ((uint32_t)umac_int30_sel << 5) |((uint32_t)umac_int29_sel << 0));
}

__INLINE void macsys_gcu_umac_int_map_4_unpack(uint8_t* umac_int30_sel, uint8_t* umac_int29_sel)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_4_ADDR);

	*umac_int30_sel = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*umac_int29_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macsys_gcu_umac_int_map_4_umac_int_30_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void macsys_gcu_umac_int_map_4_umac_int_30_sel_setf(uint8_t umacint30sel)
{
	ASSERT_ERR((((uint32_t)umacint30sel << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_4_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_4_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)umacint30sel <<5));
}
__INLINE uint8_t macsys_gcu_umac_int_map_4_umac_int_29_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macsys_gcu_umac_int_map_4_umac_int_29_sel_setf(uint8_t umacint29sel)
{
	ASSERT_ERR((((uint32_t)umacint29sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_UMAC_INT_MAP_4_ADDR, (REG_PL_RD(MACSYS_GCU_UMAC_INT_MAP_4_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)umacint29sel <<0));
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
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001B0)
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_OFFSET      0x000001B0
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_INDEX       0x0000006C
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_axi_error_int_route_get(void)
{
	return REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_ROUTE_ADDR);
}

__INLINE void macsys_gcu_axi_error_int_route_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_AXI_ERROR_INT_ROUTE_ADDR, value);
}

// field definitions
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_CPU_SELECT_MASK    ((uint32_t)0x0000000F)
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_CPU_SELECT_LSB    0
#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_CPU_SELECT_WIDTH    ((uint32_t)0x00000004)

#define MACSYS_GCU_AXI_ERROR_INT_ROUTE_CPU_SELECT_RST    0x0

__INLINE uint8_t macsys_gcu_axi_error_int_route_cpu_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_ROUTE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macsys_gcu_axi_error_int_route_cpu_select_setf(uint8_t cpuselect)
{
	ASSERT_ERR((((uint32_t)cpuselect << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACSYS_GCU_AXI_ERROR_INT_ROUTE_ADDR, (uint32_t)cpuselect << 0);
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
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001B4)
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_OFFSET      0x000001B4
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_INDEX       0x0000006D
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_axi_error_int_rawstat_get(void)
{
	return REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_ADDR);
}

// field definitions
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_PHY_AXI_ERROR_EVENT_BIT    ((uint32_t)0x00000002)
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_PHY_AXI_ERROR_EVENT_POS    1
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_AXI_ERROR_EVENT_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_AXI_ERROR_EVENT_POS    0

#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_PHY_AXI_ERROR_EVENT_RST    0x0
#define MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_AXI_ERROR_EVENT_RST    0x0

__INLINE void macsys_gcu_axi_error_int_rawstat_unpack(uint8_t* phy_axi_error_event, uint8_t* axi_error_event)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_ADDR);

	*phy_axi_error_event = (localVal & ((uint32_t)0x00000002)) >>  1;
	*axi_error_event = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macsys_gcu_axi_error_int_rawstat_phy_axi_error_event_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t macsys_gcu_axi_error_int_rawstat_axi_error_event_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_RAWSTAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
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
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001B8)
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_OFFSET      0x000001B8
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_INDEX       0x0000006E
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_axi_error_int_enable_get(void)
{
	return REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR);
}

__INLINE void macsys_gcu_axi_error_int_enable_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR, value);
}

// field definitions
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_PHY_AXI_ERROR_INT_ENABLE_BIT    ((uint32_t)0x00000002)
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_PHY_AXI_ERROR_INT_ENABLE_POS    1
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_AXI_ERROR_INT_ENABLE_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_AXI_ERROR_INT_ENABLE_POS    0

#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_PHY_AXI_ERROR_INT_ENABLE_RST    0x0
#define MACSYS_GCU_AXI_ERROR_INT_ENABLE_AXI_ERROR_INT_ENABLE_RST    0x0

__INLINE void macsys_gcu_axi_error_int_enable_pack(uint8_t phy_axi_error_int_enable, uint8_t axi_error_int_enable)
{
	ASSERT_ERR((((uint32_t)phy_axi_error_int_enable << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)axi_error_int_enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR,  ((uint32_t)phy_axi_error_int_enable << 1) |((uint32_t)axi_error_int_enable << 0));
}

__INLINE void macsys_gcu_axi_error_int_enable_unpack(uint8_t* phy_axi_error_int_enable, uint8_t* axi_error_int_enable)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR);

	*phy_axi_error_int_enable = (localVal & ((uint32_t)0x00000002)) >>  1;
	*axi_error_int_enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macsys_gcu_axi_error_int_enable_phy_axi_error_int_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void macsys_gcu_axi_error_int_enable_phy_axi_error_int_enable_setf(uint8_t phyaxierrorintenable)
{
	ASSERT_ERR((((uint32_t)phyaxierrorintenable << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR, (REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)phyaxierrorintenable <<1));
}
__INLINE uint8_t macsys_gcu_axi_error_int_enable_axi_error_int_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macsys_gcu_axi_error_int_enable_axi_error_int_enable_setf(uint8_t axierrorintenable)
{
	ASSERT_ERR((((uint32_t)axierrorintenable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR, (REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_ENABLE_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)axierrorintenable <<0));
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
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001C4)
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_OFFSET      0x000001C4
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_INDEX       0x00000071
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_axi_error_int_status_get(void)
{
	return REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_STATUS_ADDR);
}

// field definitions
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_PHY_AXI_ERROR_EVENT_BIT    ((uint32_t)0x00000002)
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_PHY_AXI_ERROR_EVENT_POS    1
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_AXI_ERROR_EVENT_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_AXI_ERROR_EVENT_POS    0

#define MACSYS_GCU_AXI_ERROR_INT_STATUS_PHY_AXI_ERROR_EVENT_RST    0x0
#define MACSYS_GCU_AXI_ERROR_INT_STATUS_AXI_ERROR_EVENT_RST    0x0

__INLINE void macsys_gcu_axi_error_int_status_unpack(uint8_t* phy_axi_error_event, uint8_t* axi_error_event)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_STATUS_ADDR);

	*phy_axi_error_event = (localVal & ((uint32_t)0x00000002)) >>  1;
	*axi_error_event = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macsys_gcu_axi_error_int_status_phy_axi_error_event_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t macsys_gcu_axi_error_int_status_axi_error_event_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INT_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
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
#define MACSYS_GCU_AXI_ERROR_ADDRESS_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001C8)
#define MACSYS_GCU_AXI_ERROR_ADDRESS_OFFSET      0x000001C8
#define MACSYS_GCU_AXI_ERROR_ADDRESS_INDEX       0x00000072
#define MACSYS_GCU_AXI_ERROR_ADDRESS_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_axi_error_address_get(void)
{
	return REG_PL_RD(MACSYS_GCU_AXI_ERROR_ADDRESS_ADDR);
}

// field definitions
#define MACSYS_GCU_AXI_ERROR_ADDRESS_AXI_ERROR_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACSYS_GCU_AXI_ERROR_ADDRESS_AXI_ERROR_ADDRESS_LSB    0
#define MACSYS_GCU_AXI_ERROR_ADDRESS_AXI_ERROR_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACSYS_GCU_AXI_ERROR_ADDRESS_AXI_ERROR_ADDRESS_RST    0x0

__INLINE uint32_t macsys_gcu_axi_error_address_axi_error_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
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
#define MACSYS_GCU_AXI_ERROR_INFO_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001CC)
#define MACSYS_GCU_AXI_ERROR_INFO_OFFSET      0x000001CC
#define MACSYS_GCU_AXI_ERROR_INFO_INDEX       0x00000073
#define MACSYS_GCU_AXI_ERROR_INFO_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_axi_error_info_get(void)
{
	return REG_PL_RD(MACSYS_GCU_AXI_ERROR_INFO_ADDR);
}

__INLINE void macsys_gcu_axi_error_info_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_AXI_ERROR_INFO_ADDR, value);
}

// field definitions
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_LENGTH_MASK    ((uint32_t)0x0000F000)
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_LENGTH_LSB    12
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_LENGTH_WIDTH    ((uint32_t)0x00000004)
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_TYPE_MASK    ((uint32_t)0x00000C00)
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_TYPE_LSB    10
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_TYPE_WIDTH    ((uint32_t)0x00000002)
#define MACSYS_GCU_AXI_ERROR_INFO_READ_WRITE_B_BIT    ((uint32_t)0x00000200)
#define MACSYS_GCU_AXI_ERROR_INFO_READ_WRITE_B_POS    9
#define MACSYS_GCU_AXI_ERROR_INFO_AXI_ERROR_MASTER_ID_MASK    ((uint32_t)0x000001FF)
#define MACSYS_GCU_AXI_ERROR_INFO_AXI_ERROR_MASTER_ID_LSB    0
#define MACSYS_GCU_AXI_ERROR_INFO_AXI_ERROR_MASTER_ID_WIDTH    ((uint32_t)0x00000009)

#define MACSYS_GCU_AXI_ERROR_INFO_BURST_LENGTH_RST    0x0
#define MACSYS_GCU_AXI_ERROR_INFO_BURST_TYPE_RST    0x0
#define MACSYS_GCU_AXI_ERROR_INFO_READ_WRITE_B_RST    0x0
#define MACSYS_GCU_AXI_ERROR_INFO_AXI_ERROR_MASTER_ID_RST    0x0

__INLINE void macsys_gcu_axi_error_info_pack(uint8_t burst_length, uint8_t burst_type, uint8_t read_write_b, uint16_t axi_error_master_id)
{
	ASSERT_ERR((((uint32_t)burst_length << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)burst_type << 10) & ~((uint32_t)0x00000C00)) == 0);
	ASSERT_ERR((((uint32_t)read_write_b << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)axi_error_master_id << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(MACSYS_GCU_AXI_ERROR_INFO_ADDR,  ((uint32_t)burst_length << 12) |((uint32_t)burst_type << 10) |((uint32_t)read_write_b << 9) |((uint32_t)axi_error_master_id << 0));
}

__INLINE void macsys_gcu_axi_error_info_unpack(uint8_t* burst_length, uint8_t* burst_type, uint8_t* read_write_b, uint16_t* axi_error_master_id)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INFO_ADDR);

	*burst_length = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*burst_type = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*read_write_b = (localVal & ((uint32_t)0x00000200)) >>  9;
	*axi_error_master_id = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t macsys_gcu_axi_error_info_burst_length_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE uint8_t macsys_gcu_axi_error_info_burst_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE uint8_t macsys_gcu_axi_error_info_read_write_b_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint16_t macsys_gcu_axi_error_info_axi_error_master_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_AXI_ERROR_INFO_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void macsys_gcu_axi_error_info_axi_error_master_id_setf(uint16_t axierrormasterid)
{
	ASSERT_ERR((((uint32_t)axierrormasterid << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(MACSYS_GCU_AXI_ERROR_INFO_ADDR, (REG_PL_RD(MACSYS_GCU_AXI_ERROR_INFO_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)axierrormasterid <<0));
}

/**
 * @brief PHY_AXI_ERROR_ADDRESS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PHY_AXI_ERROR_ADDRESS     0x0
 * </pre>
 */
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001D0)
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_OFFSET      0x000001D0
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_INDEX       0x00000074
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_phy_axi_error_address_get(void)
{
	return REG_PL_RD(MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_ADDR);
}

// field definitions
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_PHY_AXI_ERROR_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_PHY_AXI_ERROR_ADDRESS_LSB    0
#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_PHY_AXI_ERROR_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_PHY_AXI_ERROR_ADDRESS_RST    0x0

__INLINE uint32_t macsys_gcu_phy_axi_error_address_phy_axi_error_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PHY_AXI_ERROR_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
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
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001D4)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_OFFSET      0x000001D4
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_INDEX       0x00000075
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_phy_axi_error_info_get(void)
{
	return REG_PL_RD(MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR);
}

__INLINE void macsys_gcu_phy_axi_error_info_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR, value);
}

// field definitions
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_LEN_MASK    ((uint32_t)0x00000780)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_LEN_LSB    7
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_LEN_WIDTH    ((uint32_t)0x00000004)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_TYPE_MASK    ((uint32_t)0x00000060)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_TYPE_LSB    5
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_TYPE_WIDTH    ((uint32_t)0x00000002)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_RW_BIT    ((uint32_t)0x00000010)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_RW_POS    4
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_MASTER_ID_MASK    ((uint32_t)0x0000000F)
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_MASTER_ID_LSB    0
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_MASTER_ID_WIDTH    ((uint32_t)0x00000004)

#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_LEN_RST    0x0
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_TYPE_RST    0x0
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_RW_RST    0x0
#define MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_MASTER_ID_RST    0x0

__INLINE void macsys_gcu_phy_axi_error_info_pack(uint8_t phy_axi_error_burst_len, uint8_t phy_axi_error_burst_type, uint8_t phy_axi_error_rw, uint8_t phy_axi_error_master_id)
{
	ASSERT_ERR((((uint32_t)phy_axi_error_burst_len << 7) & ~((uint32_t)0x00000780)) == 0);
	ASSERT_ERR((((uint32_t)phy_axi_error_burst_type << 5) & ~((uint32_t)0x00000060)) == 0);
	ASSERT_ERR((((uint32_t)phy_axi_error_rw << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)phy_axi_error_master_id << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR,  ((uint32_t)phy_axi_error_burst_len << 7) |((uint32_t)phy_axi_error_burst_type << 5) |((uint32_t)phy_axi_error_rw << 4) |((uint32_t)phy_axi_error_master_id << 0));
}

__INLINE void macsys_gcu_phy_axi_error_info_unpack(uint8_t* phy_axi_error_burst_len, uint8_t* phy_axi_error_burst_type, uint8_t* phy_axi_error_rw, uint8_t* phy_axi_error_master_id)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR);

	*phy_axi_error_burst_len = (localVal & ((uint32_t)0x00000780)) >>  7;
	*phy_axi_error_burst_type = (localVal & ((uint32_t)0x00000060)) >>  5;
	*phy_axi_error_rw = (localVal & ((uint32_t)0x00000010)) >>  4;
	*phy_axi_error_master_id = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t macsys_gcu_phy_axi_error_info_phy_axi_error_burst_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000780)) >> 7);
}
__INLINE uint8_t macsys_gcu_phy_axi_error_info_phy_axi_error_burst_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000060)) >> 5);
}
__INLINE uint8_t macsys_gcu_phy_axi_error_info_phy_axi_error_rw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t macsys_gcu_phy_axi_error_info_phy_axi_error_master_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void macsys_gcu_phy_axi_error_info_phy_axi_error_master_id_setf(uint8_t phyaxierrormasterid)
{
	ASSERT_ERR((((uint32_t)phyaxierrormasterid << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR, (REG_PL_RD(MACSYS_GCU_PHY_AXI_ERROR_INFO_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)phyaxierrormasterid <<0));
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
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001D8)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_OFFSET      0x000001D8
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_INDEX       0x00000076
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_RESET       0x6AC2D026

__INLINE uint32_t  macsys_gcu_usb_2_phy_config_0_get(void)
{
	return REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
}

__INLINE void macsys_gcu_usb_2_phy_config_0_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, value);
}

// field definitions
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SCP_EN_BIT    ((uint32_t)0x40000000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SCP_EN_POS    30
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_RX_LP_EN_BIT    ((uint32_t)0x20000000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_RX_LP_EN_POS    29
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_RSTN_BYPASS_BIT    ((uint32_t)0x10000000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_RSTN_BYPASS_POS    28
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_LP_MODE_EN_BIT    ((uint32_t)0x08000000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_LP_MODE_EN_POS    27
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_CUR_ADJ_MASK    ((uint32_t)0x06000000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_CUR_ADJ_LSB    25
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_CUR_ADJ_WIDTH    ((uint32_t)0x00000002)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_PLLBW_SEL_MASK    ((uint32_t)0x01C00000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_PLLBW_SEL_LSB    22
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_PLLBW_SEL_WIDTH    ((uint32_t)0x00000003)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_EMP_ADJ_MASK    ((uint32_t)0x00300000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_EMP_ADJ_LSB    20
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_EMP_ADJ_WIDTH    ((uint32_t)0x00000002)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_EMP_EN_BIT    ((uint32_t)0x00080000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_EMP_EN_POS    19
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_SP_ADJ_MASK    ((uint32_t)0x00078000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_SP_ADJ_LSB    15
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_SQL_SP_ADJ_WIDTH    ((uint32_t)0x00000004)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_CALIB_ONCE_EN_BIT    ((uint32_t)0x00004000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_CALIB_ONCE_EN_POS    14
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_REG_0_P_8_ADJ_MASK    ((uint32_t)0x00003000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_REG_0_P_8_ADJ_LSB    12
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_REG_0_P_8_ADJ_WIDTH    ((uint32_t)0x00000002)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_REG_14_ADJ_MASK    ((uint32_t)0x00000E00)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_REG_14_ADJ_LSB    9
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_REG_14_ADJ_WIDTH    ((uint32_t)0x00000003)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_CDR_RST_SEL_BIT    ((uint32_t)0x00000100)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_CDR_RST_SEL_POS    8
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_RISE_TUNE_MASK    ((uint32_t)0x000000C0)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_RISE_TUNE_LSB    6
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_HS_RISE_TUNE_WIDTH    ((uint32_t)0x00000002)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_FS_CROSS_ADJ_MASK    ((uint32_t)0x00000038)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_FS_CROSS_ADJ_LSB    3
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_FS_CROSS_ADJ_WIDTH    ((uint32_t)0x00000003)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_LS_CROSS_ADJ_MASK    ((uint32_t)0x00000007)
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_LS_CROSS_ADJ_LSB    0
#define MACSYS_GCU_USB_2_PHY_CONFIG_0_LS_CROSS_ADJ_WIDTH    ((uint32_t)0x00000003)

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

__INLINE void macsys_gcu_usb_2_phy_config_0_pack(uint8_t scp_en, uint8_t rx_lp_en, uint8_t rstn_bypass, uint8_t hs_lp_mode_en, uint8_t sql_cur_adj, uint8_t pllbw_sel, uint8_t hs_emp_adj, uint8_t hs_emp_en, uint8_t sql_sp_adj, uint8_t calib_once_en, uint8_t hs_reg0_p8_adj, uint8_t reg14_adj, uint8_t cdr_rst_sel, uint8_t hs_rise_tune, uint8_t fs_cross_adj, uint8_t ls_cross_adj)
{
	ASSERT_ERR((((uint32_t)scp_en << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)rx_lp_en << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)rstn_bypass << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)hs_lp_mode_en << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)sql_cur_adj << 25) & ~((uint32_t)0x06000000)) == 0);
	ASSERT_ERR((((uint32_t)pllbw_sel << 22) & ~((uint32_t)0x01C00000)) == 0);
	ASSERT_ERR((((uint32_t)hs_emp_adj << 20) & ~((uint32_t)0x00300000)) == 0);
	ASSERT_ERR((((uint32_t)hs_emp_en << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)sql_sp_adj << 15) & ~((uint32_t)0x00078000)) == 0);
	ASSERT_ERR((((uint32_t)calib_once_en << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)hs_reg0_p8_adj << 12) & ~((uint32_t)0x00003000)) == 0);
	ASSERT_ERR((((uint32_t)reg14_adj << 9) & ~((uint32_t)0x00000E00)) == 0);
	ASSERT_ERR((((uint32_t)cdr_rst_sel << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)hs_rise_tune << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)fs_cross_adj << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)ls_cross_adj << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR,  ((uint32_t)scp_en << 30) |((uint32_t)rx_lp_en << 29) |((uint32_t)rstn_bypass << 28) |((uint32_t)hs_lp_mode_en << 27) |((uint32_t)sql_cur_adj << 25) |((uint32_t)pllbw_sel << 22) |((uint32_t)hs_emp_adj << 20) |((uint32_t)hs_emp_en << 19) |((uint32_t)sql_sp_adj << 15) |((uint32_t)calib_once_en << 14) |((uint32_t)hs_reg0_p8_adj << 12) |((uint32_t)reg14_adj << 9) |((uint32_t)cdr_rst_sel << 8) |((uint32_t)hs_rise_tune << 6) |((uint32_t)fs_cross_adj << 3) |((uint32_t)ls_cross_adj << 0));
}

__INLINE void macsys_gcu_usb_2_phy_config_0_unpack(uint8_t* scp_en, uint8_t* rx_lp_en, uint8_t* rstn_bypass, uint8_t* hs_lp_mode_en, uint8_t* sql_cur_adj, uint8_t* pllbw_sel, uint8_t* hs_emp_adj, uint8_t* hs_emp_en, uint8_t* sql_sp_adj, uint8_t* calib_once_en, uint8_t* hs_reg0_p8_adj, uint8_t* reg14_adj, uint8_t* cdr_rst_sel, uint8_t* hs_rise_tune, uint8_t* fs_cross_adj, uint8_t* ls_cross_adj)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);

	*scp_en = (localVal & ((uint32_t)0x40000000)) >>  30;
	*rx_lp_en = (localVal & ((uint32_t)0x20000000)) >>  29;
	*rstn_bypass = (localVal & ((uint32_t)0x10000000)) >>  28;
	*hs_lp_mode_en = (localVal & ((uint32_t)0x08000000)) >>  27;
	*sql_cur_adj = (localVal & ((uint32_t)0x06000000)) >>  25;
	*pllbw_sel = (localVal & ((uint32_t)0x01C00000)) >>  22;
	*hs_emp_adj = (localVal & ((uint32_t)0x00300000)) >>  20;
	*hs_emp_en = (localVal & ((uint32_t)0x00080000)) >>  19;
	*sql_sp_adj = (localVal & ((uint32_t)0x00078000)) >>  15;
	*calib_once_en = (localVal & ((uint32_t)0x00004000)) >>  14;
	*hs_reg0_p8_adj = (localVal & ((uint32_t)0x00003000)) >>  12;
	*reg14_adj = (localVal & ((uint32_t)0x00000E00)) >>  9;
	*cdr_rst_sel = (localVal & ((uint32_t)0x00000100)) >>  8;
	*hs_rise_tune = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*fs_cross_adj = (localVal & ((uint32_t)0x00000038)) >>  3;
	*ls_cross_adj = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_scp_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_scp_en_setf(uint8_t scpen)
{
	ASSERT_ERR((((uint32_t)scpen << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)scpen <<30));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_rx_lp_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_rx_lp_en_setf(uint8_t rxlpen)
{
	ASSERT_ERR((((uint32_t)rxlpen << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)rxlpen <<29));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_rstn_bypass_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_rstn_bypass_setf(uint8_t rstnbypass)
{
	ASSERT_ERR((((uint32_t)rstnbypass << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)rstnbypass <<28));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_hs_lp_mode_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_hs_lp_mode_en_setf(uint8_t hslpmodeen)
{
	ASSERT_ERR((((uint32_t)hslpmodeen << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)hslpmodeen <<27));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_sql_cur_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x06000000)) >> 25);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_sql_cur_adj_setf(uint8_t sqlcuradj)
{
	ASSERT_ERR((((uint32_t)sqlcuradj << 25) & ~((uint32_t)0x06000000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x06000000)) | ((uint32_t)sqlcuradj <<25));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_pllbw_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01C00000)) >> 22);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_pllbw_sel_setf(uint8_t pllbwsel)
{
	ASSERT_ERR((((uint32_t)pllbwsel << 22) & ~((uint32_t)0x01C00000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x01C00000)) | ((uint32_t)pllbwsel <<22));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_hs_emp_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00300000)) >> 20);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_hs_emp_adj_setf(uint8_t hsempadj)
{
	ASSERT_ERR((((uint32_t)hsempadj << 20) & ~((uint32_t)0x00300000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x00300000)) | ((uint32_t)hsempadj <<20));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_hs_emp_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_hs_emp_en_setf(uint8_t hsempen)
{
	ASSERT_ERR((((uint32_t)hsempen << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)hsempen <<19));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_sql_sp_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00078000)) >> 15);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_sql_sp_adj_setf(uint8_t sqlspadj)
{
	ASSERT_ERR((((uint32_t)sqlspadj << 15) & ~((uint32_t)0x00078000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x00078000)) | ((uint32_t)sqlspadj <<15));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_calib_once_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_calib_once_en_setf(uint8_t calibonceen)
{
	ASSERT_ERR((((uint32_t)calibonceen << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)calibonceen <<14));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_hs_reg_0_p_8_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003000)) >> 12);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_hs_reg_0_p_8_adj_setf(uint8_t hsreg0p8adj)
{
	ASSERT_ERR((((uint32_t)hsreg0p8adj << 12) & ~((uint32_t)0x00003000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)hsreg0p8adj <<12));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_reg_14_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000E00)) >> 9);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_reg_14_adj_setf(uint8_t reg14adj)
{
	ASSERT_ERR((((uint32_t)reg14adj << 9) & ~((uint32_t)0x00000E00)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x00000E00)) | ((uint32_t)reg14adj <<9));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_cdr_rst_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_cdr_rst_sel_setf(uint8_t cdrrstsel)
{
	ASSERT_ERR((((uint32_t)cdrrstsel << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cdrrstsel <<8));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_hs_rise_tune_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_hs_rise_tune_setf(uint8_t hsrisetune)
{
	ASSERT_ERR((((uint32_t)hsrisetune << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)hsrisetune <<6));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_fs_cross_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_fs_cross_adj_setf(uint8_t fscrossadj)
{
	ASSERT_ERR((((uint32_t)fscrossadj << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)fscrossadj <<3));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_0_ls_cross_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void macsys_gcu_usb_2_phy_config_0_ls_cross_adj_setf(uint8_t lscrossadj)
{
	ASSERT_ERR((((uint32_t)lscrossadj << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_0_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)lscrossadj <<0));
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
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001DC)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_OFFSET      0x000001DC
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_INDEX       0x00000077
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_RESET       0x00710408

__INLINE uint32_t  macsys_gcu_usb_2_phy_config_1_get(void)
{
	return REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);
}

__INLINE void macsys_gcu_usb_2_phy_config_1_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, value);
}

// field definitions
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_GLOBAL_CONFIG_MASK    ((uint32_t)0xFF000000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_GLOBAL_CONFIG_LSB    24
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_GLOBAL_CONFIG_WIDTH    ((uint32_t)0x00000008)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_VBUS_VLD_ADJ_MASK    ((uint32_t)0x00F00000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_VBUS_VLD_ADJ_LSB    20
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_VBUS_VLD_ADJ_WIDTH    ((uint32_t)0x00000004)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_REG_20_ADJ_MASK    ((uint32_t)0x000E0000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_REG_20_ADJ_LSB    17
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_REG_20_ADJ_WIDTH    ((uint32_t)0x00000003)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_DISC_ADJ_MASK    ((uint32_t)0x0001E000)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_DISC_ADJ_LSB    13
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_DISC_ADJ_WIDTH    ((uint32_t)0x00000004)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_XOSC_CUR_ADJ_MASK    ((uint32_t)0x00001C00)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_XOSC_CUR_ADJ_LSB    10
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_XOSC_CUR_ADJ_WIDTH    ((uint32_t)0x00000003)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_TIMING_SEL_MASK    ((uint32_t)0x000003C0)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_TIMING_SEL_LSB    6
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_TIMING_SEL_WIDTH    ((uint32_t)0x00000004)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_BW_SEL_MASK    ((uint32_t)0x00000030)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_BW_SEL_LSB    4
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_BW_SEL_WIDTH    ((uint32_t)0x00000002)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_SQL_VTH_ADJ_MASK    ((uint32_t)0x0000000F)
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_SQL_VTH_ADJ_LSB    0
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_SQL_VTH_ADJ_WIDTH    ((uint32_t)0x00000004)

#define MACSYS_GCU_USB_2_PHY_CONFIG_1_GLOBAL_CONFIG_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_VBUS_VLD_ADJ_RST    0x7
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_REG_20_ADJ_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_DISC_ADJ_RST    0x8
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_XOSC_CUR_ADJ_RST    0x1
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_TIMING_SEL_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_CDR_BW_SEL_RST    0x0
#define MACSYS_GCU_USB_2_PHY_CONFIG_1_SQL_VTH_ADJ_RST    0x8

__INLINE void macsys_gcu_usb_2_phy_config_1_pack(uint8_t global_config, uint8_t vbus_vld_adj, uint8_t reg20_adj, uint8_t disc_adj, uint8_t xosc_cur_adj, uint8_t cdr_timing_sel, uint8_t cdr_bw_sel, uint8_t sql_vth_adj)
{
	ASSERT_ERR((((uint32_t)global_config << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)vbus_vld_adj << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)reg20_adj << 17) & ~((uint32_t)0x000E0000)) == 0);
	ASSERT_ERR((((uint32_t)disc_adj << 13) & ~((uint32_t)0x0001E000)) == 0);
	ASSERT_ERR((((uint32_t)xosc_cur_adj << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)cdr_timing_sel << 6) & ~((uint32_t)0x000003C0)) == 0);
	ASSERT_ERR((((uint32_t)cdr_bw_sel << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)sql_vth_adj << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR,  ((uint32_t)global_config << 24) |((uint32_t)vbus_vld_adj << 20) |((uint32_t)reg20_adj << 17) |((uint32_t)disc_adj << 13) |((uint32_t)xosc_cur_adj << 10) |((uint32_t)cdr_timing_sel << 6) |((uint32_t)cdr_bw_sel << 4) |((uint32_t)sql_vth_adj << 0));
}

__INLINE void macsys_gcu_usb_2_phy_config_1_unpack(uint8_t* global_config, uint8_t* vbus_vld_adj, uint8_t* reg20_adj, uint8_t* disc_adj, uint8_t* xosc_cur_adj, uint8_t* cdr_timing_sel, uint8_t* cdr_bw_sel, uint8_t* sql_vth_adj)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);

	*global_config = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*vbus_vld_adj = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*reg20_adj = (localVal & ((uint32_t)0x000E0000)) >>  17;
	*disc_adj = (localVal & ((uint32_t)0x0001E000)) >>  13;
	*xosc_cur_adj = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*cdr_timing_sel = (localVal & ((uint32_t)0x000003C0)) >>  6;
	*cdr_bw_sel = (localVal & ((uint32_t)0x00000030)) >>  4;
	*sql_vth_adj = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t macsys_gcu_usb_2_phy_config_1_global_config_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void macsys_gcu_usb_2_phy_config_1_global_config_setf(uint8_t globalconfig)
{
	ASSERT_ERR((((uint32_t)globalconfig << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)globalconfig <<24));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_1_vbus_vld_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void macsys_gcu_usb_2_phy_config_1_vbus_vld_adj_setf(uint8_t vbusvldadj)
{
	ASSERT_ERR((((uint32_t)vbusvldadj << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)vbusvldadj <<20));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_1_reg_20_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000E0000)) >> 17);
}
__INLINE void macsys_gcu_usb_2_phy_config_1_reg_20_adj_setf(uint8_t reg20adj)
{
	ASSERT_ERR((((uint32_t)reg20adj << 17) & ~((uint32_t)0x000E0000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((uint32_t)0x000E0000)) | ((uint32_t)reg20adj <<17));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_1_disc_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0001E000)) >> 13);
}
__INLINE void macsys_gcu_usb_2_phy_config_1_disc_adj_setf(uint8_t discadj)
{
	ASSERT_ERR((((uint32_t)discadj << 13) & ~((uint32_t)0x0001E000)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((uint32_t)0x0001E000)) | ((uint32_t)discadj <<13));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_1_xosc_cur_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void macsys_gcu_usb_2_phy_config_1_xosc_cur_adj_setf(uint8_t xosccuradj)
{
	ASSERT_ERR((((uint32_t)xosccuradj << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)xosccuradj <<10));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_1_cdr_timing_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003C0)) >> 6);
}
__INLINE void macsys_gcu_usb_2_phy_config_1_cdr_timing_sel_setf(uint8_t cdrtimingsel)
{
	ASSERT_ERR((((uint32_t)cdrtimingsel << 6) & ~((uint32_t)0x000003C0)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((uint32_t)0x000003C0)) | ((uint32_t)cdrtimingsel <<6));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_1_cdr_bw_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void macsys_gcu_usb_2_phy_config_1_cdr_bw_sel_setf(uint8_t cdrbwsel)
{
	ASSERT_ERR((((uint32_t)cdrbwsel << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)cdrbwsel <<4));
}
__INLINE uint8_t macsys_gcu_usb_2_phy_config_1_sql_vth_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void macsys_gcu_usb_2_phy_config_1_sql_vth_adj_setf(uint8_t sqlvthadj)
{
	ASSERT_ERR((((uint32_t)sqlvthadj << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_PHY_CONFIG_1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)sqlvthadj <<0));
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
#define MACSYS_GCU_USB_2_BIST_CTRL_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001E0)
#define MACSYS_GCU_USB_2_BIST_CTRL_OFFSET      0x000001E0
#define MACSYS_GCU_USB_2_BIST_CTRL_INDEX       0x00000078
#define MACSYS_GCU_USB_2_BIST_CTRL_RESET       0x00000001

__INLINE uint32_t  macsys_gcu_usb_2_bist_ctrl_get(void)
{
	return REG_PL_RD(MACSYS_GCU_USB_2_BIST_CTRL_ADDR);
}

__INLINE void macsys_gcu_usb_2_bist_ctrl_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_USB_2_BIST_CTRL_ADDR, value);
}

// field definitions
#define MACSYS_GCU_USB_2_BIST_CTRL_TEST_LOOP_MASK    ((uint32_t)0x0000000E)
#define MACSYS_GCU_USB_2_BIST_CTRL_TEST_LOOP_LSB    1
#define MACSYS_GCU_USB_2_BIST_CTRL_TEST_LOOP_WIDTH    ((uint32_t)0x00000003)
#define MACSYS_GCU_USB_2_BIST_CTRL_BIST_EN_N_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_USB_2_BIST_CTRL_BIST_EN_N_POS    0

#define MACSYS_GCU_USB_2_BIST_CTRL_TEST_LOOP_RST    0x0
#define MACSYS_GCU_USB_2_BIST_CTRL_BIST_EN_N_RST    0x1

__INLINE void macsys_gcu_usb_2_bist_ctrl_pack(uint8_t test_loop, uint8_t bist_en_n)
{
	ASSERT_ERR((((uint32_t)test_loop << 1) & ~((uint32_t)0x0000000E)) == 0);
	ASSERT_ERR((((uint32_t)bist_en_n << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_BIST_CTRL_ADDR,  ((uint32_t)test_loop << 1) |((uint32_t)bist_en_n << 0));
}

__INLINE void macsys_gcu_usb_2_bist_ctrl_unpack(uint8_t* test_loop, uint8_t* bist_en_n)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_BIST_CTRL_ADDR);

	*test_loop = (localVal & ((uint32_t)0x0000000E)) >>  1;
	*bist_en_n = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macsys_gcu_usb_2_bist_ctrl_test_loop_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_BIST_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000E)) >> 1);
}
__INLINE void macsys_gcu_usb_2_bist_ctrl_test_loop_setf(uint8_t testloop)
{
	ASSERT_ERR((((uint32_t)testloop << 1) & ~((uint32_t)0x0000000E)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_BIST_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_BIST_CTRL_ADDR) & ~((uint32_t)0x0000000E)) | ((uint32_t)testloop <<1));
}
__INLINE uint8_t macsys_gcu_usb_2_bist_ctrl_bist_en_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_BIST_CTRL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macsys_gcu_usb_2_bist_ctrl_bist_en_n_setf(uint8_t bistenn)
{
	ASSERT_ERR((((uint32_t)bistenn << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_BIST_CTRL_ADDR, (REG_PL_RD(MACSYS_GCU_USB_2_BIST_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)bistenn <<0));
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
#define MACSYS_GCU_USB_2_BIST_STATUS_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001E4)
#define MACSYS_GCU_USB_2_BIST_STATUS_OFFSET      0x000001E4
#define MACSYS_GCU_USB_2_BIST_STATUS_INDEX       0x00000079
#define MACSYS_GCU_USB_2_BIST_STATUS_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_usb_2_bist_status_get(void)
{
	return REG_PL_RD(MACSYS_GCU_USB_2_BIST_STATUS_ADDR);
}

// field definitions
#define MACSYS_GCU_USB_2_BIST_STATUS_BIST_ERR_BIT    ((uint32_t)0x00000002)
#define MACSYS_GCU_USB_2_BIST_STATUS_BIST_ERR_POS    1
#define MACSYS_GCU_USB_2_BIST_STATUS_BIST_DONE_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_USB_2_BIST_STATUS_BIST_DONE_POS    0

#define MACSYS_GCU_USB_2_BIST_STATUS_BIST_ERR_RST    0x0
#define MACSYS_GCU_USB_2_BIST_STATUS_BIST_DONE_RST    0x0

__INLINE void macsys_gcu_usb_2_bist_status_unpack(uint8_t* bist_err, uint8_t* bist_done)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_BIST_STATUS_ADDR);

	*bist_err = (localVal & ((uint32_t)0x00000002)) >>  1;
	*bist_done = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macsys_gcu_usb_2_bist_status_bist_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_BIST_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t macsys_gcu_usb_2_bist_status_bist_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_BIST_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief WD_TIME register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 WD_TIME                   0x14
 * </pre>
 */
#define MACSYS_GCU_WD_TIME_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001E8)
#define MACSYS_GCU_WD_TIME_OFFSET      0x000001E8
#define MACSYS_GCU_WD_TIME_INDEX       0x0000007A
#define MACSYS_GCU_WD_TIME_RESET       0x00000014

__INLINE uint32_t  macsys_gcu_wd_time_get(void)
{
	return REG_PL_RD(MACSYS_GCU_WD_TIME_ADDR);
}

__INLINE void macsys_gcu_wd_time_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_WD_TIME_ADDR, value);
}

// field definitions
#define MACSYS_GCU_WD_TIME_WD_TIME_MASK     ((uint32_t)0x0000001F)
#define MACSYS_GCU_WD_TIME_WD_TIME_LSB      0
#define MACSYS_GCU_WD_TIME_WD_TIME_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_WD_TIME_WD_TIME_RST      0x14

__INLINE uint8_t macsys_gcu_wd_time_wd_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_WD_TIME_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macsys_gcu_wd_time_wd_time_setf(uint8_t wdtime)
{
	ASSERT_ERR((((uint32_t)wdtime << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACSYS_GCU_WD_TIME_ADDR, (uint32_t)wdtime << 0);
}

/**
 * @brief WD_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    WD_EN                     0              
 * </pre>
 */
#define MACSYS_GCU_WD_EN_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001EC)
#define MACSYS_GCU_WD_EN_OFFSET      0x000001EC
#define MACSYS_GCU_WD_EN_INDEX       0x0000007B
#define MACSYS_GCU_WD_EN_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_wd_en_get(void)
{
	return REG_PL_RD(MACSYS_GCU_WD_EN_ADDR);
}

__INLINE void macsys_gcu_wd_en_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_WD_EN_ADDR, value);
}

// field definitions
#define MACSYS_GCU_WD_EN_WD_EN_BIT          ((uint32_t)0x00000001)
#define MACSYS_GCU_WD_EN_WD_EN_POS          0

#define MACSYS_GCU_WD_EN_WD_EN_RST          0x0

__INLINE uint8_t macsys_gcu_wd_en_wd_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_WD_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macsys_gcu_wd_en_wd_en_setf(uint8_t wden)
{
	ASSERT_ERR((((uint32_t)wden << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_WD_EN_ADDR, (uint32_t)wden << 0);
}

/**
 * @brief WD_REWIND register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    WD_REWIND                 0              
 * </pre>
 */
#define MACSYS_GCU_WD_REWIND_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001F0)
#define MACSYS_GCU_WD_REWIND_OFFSET      0x000001F0
#define MACSYS_GCU_WD_REWIND_INDEX       0x0000007C
#define MACSYS_GCU_WD_REWIND_RESET       0x00000000

__INLINE void macsys_gcu_wd_rewind_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_WD_REWIND_ADDR, value);
}

// field definitions
#define MACSYS_GCU_WD_REWIND_WD_REWIND_BIT    ((uint32_t)0x00000001)
#define MACSYS_GCU_WD_REWIND_WD_REWIND_POS    0

#define MACSYS_GCU_WD_REWIND_WD_REWIND_RST    0x0

__INLINE void macsys_gcu_wd_rewind_wd_rewind_setf(uint8_t wdrewind)
{
	ASSERT_ERR((((uint32_t)wdrewind << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACSYS_GCU_WD_REWIND_ADDR, (uint32_t)wdrewind << 0);
}

/**
 * @brief WD_DYN_TIME register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 WD_DYN_TIME               0x14
 * </pre>
 */
#define MACSYS_GCU_WD_DYN_TIME_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001F4)
#define MACSYS_GCU_WD_DYN_TIME_OFFSET      0x000001F4
#define MACSYS_GCU_WD_DYN_TIME_INDEX       0x0000007D
#define MACSYS_GCU_WD_DYN_TIME_RESET       0x00000014

__INLINE uint32_t  macsys_gcu_wd_dyn_time_get(void)
{
	return REG_PL_RD(MACSYS_GCU_WD_DYN_TIME_ADDR);
}

// field definitions
#define MACSYS_GCU_WD_DYN_TIME_WD_DYN_TIME_MASK    ((uint32_t)0x0000001F)
#define MACSYS_GCU_WD_DYN_TIME_WD_DYN_TIME_LSB    0
#define MACSYS_GCU_WD_DYN_TIME_WD_DYN_TIME_WIDTH    ((uint32_t)0x00000005)

#define MACSYS_GCU_WD_DYN_TIME_WD_DYN_TIME_RST    0x14

__INLINE uint8_t macsys_gcu_wd_dyn_time_wd_dyn_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_WD_DYN_TIME_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief USB_2_PHY_TEST_CONFIG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USB2_PHY_TEST_CONFIG0     0x0
 * </pre>
 */
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001F8)
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_OFFSET      0x000001F8
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_INDEX       0x0000007E
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_usb_2_phy_test_config_0_get(void)
{
	return REG_PL_RD(MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_ADDR);
}

__INLINE void macsys_gcu_usb_2_phy_test_config_0_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_ADDR, value);
}

// field definitions
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_USB_2_PHY_TEST_CONFIG_0_MASK    ((uint32_t)0xFFFFFFFF)
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_USB_2_PHY_TEST_CONFIG_0_LSB    0
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_USB_2_PHY_TEST_CONFIG_0_WIDTH    ((uint32_t)0x00000020)

#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_USB_2_PHY_TEST_CONFIG_0_RST    0x0

__INLINE uint32_t macsys_gcu_usb_2_phy_test_config_0_usb_2_phy_test_config_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macsys_gcu_usb_2_phy_test_config_0_usb_2_phy_test_config_0_setf(uint32_t usb2phytestconfig0)
{
	ASSERT_ERR((((uint32_t)usb2phytestconfig0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_TEST_CONFIG_0_ADDR, (uint32_t)usb2phytestconfig0 << 0);
}

/**
 * @brief USB_2_PHY_TEST_CONFIG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USB2_PHY_TEST_CONFIG1     0x0
 * </pre>
 */
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_ADDR        (REG_MACSYS_GCU_BASE_ADDR+0x000001FC)
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_OFFSET      0x000001FC
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_INDEX       0x0000007F
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_RESET       0x00000000

__INLINE uint32_t  macsys_gcu_usb_2_phy_test_config_1_get(void)
{
	return REG_PL_RD(MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_ADDR);
}

__INLINE void macsys_gcu_usb_2_phy_test_config_1_set(uint32_t value)
{
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_ADDR, value);
}

// field definitions
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_USB_2_PHY_TEST_CONFIG_1_MASK    ((uint32_t)0xFFFFFFFF)
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_USB_2_PHY_TEST_CONFIG_1_LSB    0
#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_USB_2_PHY_TEST_CONFIG_1_WIDTH    ((uint32_t)0x00000020)

#define MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_USB_2_PHY_TEST_CONFIG_1_RST    0x0

__INLINE uint32_t macsys_gcu_usb_2_phy_test_config_1_usb_2_phy_test_config_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macsys_gcu_usb_2_phy_test_config_1_usb_2_phy_test_config_1_setf(uint32_t usb2phytestconfig1)
{
	ASSERT_ERR((((uint32_t)usb2phytestconfig1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACSYS_GCU_USB_2_PHY_TEST_CONFIG_1_ADDR, (uint32_t)usb2phytestconfig1 << 0);
}


#undef DBG_FILEID
#endif //_REG_MACSYS_GCU_H_
