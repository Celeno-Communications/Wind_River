#ifndef _REG_FPGA_DPHY_COMMON_H_
#define _REG_FPGA_DPHY_COMMON_H_

#include <stdint.h>
#include "dphy/_reg_fpga_dphy_common.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_FPGA_DPHY_COMMON__H__FILEID__

#define REG_FPGA_DPHY_COMMON_COUNT  25


/**
 * @brief DPY_SW_RESET register definition
 *  Puts DPHY control logic into reset state. AHB doma register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    DPY_SW_RESET              0              
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_SW_RESET_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000000)
#define FPGA_DPHY_COMMON_DPY_SW_RESET_OFFSET      0x00000000
#define FPGA_DPHY_COMMON_DPY_SW_RESET_INDEX       0x00000000
#define FPGA_DPHY_COMMON_DPY_SW_RESET_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_common_dpy_sw_reset_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_SW_RESET_ADDR);
}

__INLINE void fpga_dphy_common_dpy_sw_reset_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_SW_RESET_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_SW_RESET_DPY_SW_RESET_BIT    ((uint32_t)0x00000001)
#define FPGA_DPHY_COMMON_DPY_SW_RESET_DPY_SW_RESET_POS    0

#define FPGA_DPHY_COMMON_DPY_SW_RESET_DPY_SW_RESET_RST    0x0

__INLINE uint8_t fpga_dphy_common_dpy_sw_reset_dpy_sw_reset_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_SW_RESET_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_sw_reset_dpy_sw_reset_setf(uint8_t dpyswreset)
{
	ASSERT_ERR((((uint32_t)dpyswreset << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_SW_RESET_ADDR, (uint32_t)dpyswreset << 0);
}

/**
 * @brief DPY_AHB_ERR_CNT register definition
 *  Counts the number of AHB Errors register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 DPY_AHB_SIZE_ERR          0x0
 *    15:08 DPY_AHB_RW_ERR            0x0
 *    07:00 DPY_AHB_ADDR_ERR          0x0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000004)
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_OFFSET      0x00000004
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_INDEX       0x00000001
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_common_dpy_ahb_err_cnt_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_ADDR);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_DPY_AHB_SIZE_ERR_MASK    ((uint32_t)0x00FF0000)
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_DPY_AHB_SIZE_ERR_LSB    16
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_DPY_AHB_SIZE_ERR_WIDTH    ((uint32_t)0x00000008)
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_DPY_AHB_RW_ERR_MASK    ((uint32_t)0x0000FF00)
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_DPY_AHB_RW_ERR_LSB    8
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_DPY_AHB_RW_ERR_WIDTH    ((uint32_t)0x00000008)
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_DPY_AHB_ADDR_ERR_MASK    ((uint32_t)0x000000FF)
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_DPY_AHB_ADDR_ERR_LSB    0
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_DPY_AHB_ADDR_ERR_WIDTH    ((uint32_t)0x00000008)

#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_DPY_AHB_SIZE_ERR_RST    0x0
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_DPY_AHB_RW_ERR_RST    0x0
#define FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_DPY_AHB_ADDR_ERR_RST    0x0

__INLINE void fpga_dphy_common_dpy_ahb_err_cnt_unpack(uint8_t* dpy_ahb_size_err, uint8_t* dpy_ahb_rw_err, uint8_t* dpy_ahb_addr_err)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_ADDR);

	*dpy_ahb_size_err = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*dpy_ahb_rw_err = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*dpy_ahb_addr_err = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t fpga_dphy_common_dpy_ahb_err_cnt_dpy_ahb_size_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t fpga_dphy_common_dpy_ahb_err_cnt_dpy_ahb_rw_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t fpga_dphy_common_dpy_ahb_err_cnt_dpy_ahb_addr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_AHB_ERR_CNT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief DPY_NORM register definition
 *  Holds “exact” number of cycles to 0.2us emulated t register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16:00 DPY_NORM                  0x3000
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_NORM_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000008)
#define FPGA_DPHY_COMMON_DPY_NORM_OFFSET      0x00000008
#define FPGA_DPHY_COMMON_DPY_NORM_INDEX       0x00000002
#define FPGA_DPHY_COMMON_DPY_NORM_RESET       0x00003000

__INLINE uint32_t  fpga_dphy_common_dpy_norm_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_NORM_ADDR);
}

__INLINE void fpga_dphy_common_dpy_norm_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_NORM_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_NORM_DPY_NORM_MASK    ((uint32_t)0x0001FFFF)
#define FPGA_DPHY_COMMON_DPY_NORM_DPY_NORM_LSB    0
#define FPGA_DPHY_COMMON_DPY_NORM_DPY_NORM_WIDTH    ((uint32_t)0x00000011)

#define FPGA_DPHY_COMMON_DPY_NORM_DPY_NORM_RST    0x3000

__INLINE uint32_t fpga_dphy_common_dpy_norm_dpy_norm_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_NORM_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_norm_dpy_norm_setf(uint32_t dpynorm)
{
	ASSERT_ERR((((uint32_t)dpynorm << 0) & ~((uint32_t)0x0001FFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_NORM_ADDR, (uint32_t)dpynorm << 0);
}

/**
 * @brief DPY_PHY_DLY_MIN register definition
 *  Tx req. to “data on air” timing register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_PHY_DLY_MIN           0x2D0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MIN_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x0000000C)
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MIN_OFFSET      0x0000000C
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MIN_INDEX       0x00000003
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MIN_RESET       0x000002D0

__INLINE uint32_t  fpga_dphy_common_dpy_phy_dly_min_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_PHY_DLY_MIN_ADDR);
}

__INLINE void fpga_dphy_common_dpy_phy_dly_min_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PHY_DLY_MIN_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MIN_DPY_PHY_DLY_MIN_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MIN_DPY_PHY_DLY_MIN_LSB    0
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MIN_DPY_PHY_DLY_MIN_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MIN_DPY_PHY_DLY_MIN_RST    0x2D0

__INLINE uint32_t fpga_dphy_common_dpy_phy_dly_min_dpy_phy_dly_min_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_PHY_DLY_MIN_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_phy_dly_min_dpy_phy_dly_min_setf(uint32_t dpyphydlymin)
{
	ASSERT_ERR((((uint32_t)dpyphydlymin << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PHY_DLY_MIN_ADDR, (uint32_t)dpyphydlymin << 0);
}

/**
 * @brief DPY_PHY_DLY_MAX register definition
 *  Tx req. to “data on air” timing register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_PHY_DLY_MAX           0x2D0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MAX_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000010)
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MAX_OFFSET      0x00000010
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MAX_INDEX       0x00000004
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MAX_RESET       0x000002D0

__INLINE uint32_t  fpga_dphy_common_dpy_phy_dly_max_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_PHY_DLY_MAX_ADDR);
}

__INLINE void fpga_dphy_common_dpy_phy_dly_max_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PHY_DLY_MAX_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MAX_DPY_PHY_DLY_MAX_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MAX_DPY_PHY_DLY_MAX_LSB    0
#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MAX_DPY_PHY_DLY_MAX_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_PHY_DLY_MAX_DPY_PHY_DLY_MAX_RST    0x2D0

__INLINE uint32_t fpga_dphy_common_dpy_phy_dly_max_dpy_phy_dly_max_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_PHY_DLY_MAX_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_phy_dly_max_dpy_phy_dly_max_setf(uint32_t dpyphydlymax)
{
	ASSERT_ERR((((uint32_t)dpyphydlymax << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PHY_DLY_MAX_ADDR, (uint32_t)dpyphydlymax << 0);
}

/**
 * @brief DPY_TX_VEC_2_DLY_MIN register definition
 *  PHY expectation on Txvec2 arrival related to TXREQ register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_TX_VEC2_DLY_MIN       0x960
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MIN_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000014)
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MIN_OFFSET      0x00000014
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MIN_INDEX       0x00000005
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MIN_RESET       0x00000960

__INLINE uint32_t  fpga_dphy_common_dpy_tx_vec_2_dly_min_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MIN_ADDR);
}

__INLINE void fpga_dphy_common_dpy_tx_vec_2_dly_min_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MIN_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MIN_DPY_TX_VEC_2_DLY_MIN_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MIN_DPY_TX_VEC_2_DLY_MIN_LSB    0
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MIN_DPY_TX_VEC_2_DLY_MIN_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MIN_DPY_TX_VEC_2_DLY_MIN_RST    0x960

__INLINE uint32_t fpga_dphy_common_dpy_tx_vec_2_dly_min_dpy_tx_vec_2_dly_min_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MIN_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_tx_vec_2_dly_min_dpy_tx_vec_2_dly_min_setf(uint32_t dpytxvec2dlymin)
{
	ASSERT_ERR((((uint32_t)dpytxvec2dlymin << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MIN_ADDR, (uint32_t)dpytxvec2dlymin << 0);
}

/**
 * @brief DPY_TX_VEC_2_DLY_MAX register definition
 *  PHY expectation on Txvec2 arrival related to TXREQ register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_TX_VEC2_DLY_MAX       0x960
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MAX_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000018)
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MAX_OFFSET      0x00000018
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MAX_INDEX       0x00000006
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MAX_RESET       0x00000960

__INLINE uint32_t  fpga_dphy_common_dpy_tx_vec_2_dly_max_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MAX_ADDR);
}

__INLINE void fpga_dphy_common_dpy_tx_vec_2_dly_max_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MAX_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MAX_DPY_TX_VEC_2_DLY_MAX_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MAX_DPY_TX_VEC_2_DLY_MAX_LSB    0
#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MAX_DPY_TX_VEC_2_DLY_MAX_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MAX_DPY_TX_VEC_2_DLY_MAX_RST    0x960

__INLINE uint32_t fpga_dphy_common_dpy_tx_vec_2_dly_max_dpy_tx_vec_2_dly_max_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MAX_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_tx_vec_2_dly_max_dpy_tx_vec_2_dly_max_setf(uint32_t dpytxvec2dlymax)
{
	ASSERT_ERR((((uint32_t)dpytxvec2dlymax << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_TX_VEC_2_DLY_MAX_ADDR, (uint32_t)dpytxvec2dlymax << 0);
}

/**
 * @brief DPY_PHY_RDY_DLY_MIN register definition
 *  Represents the time between PhyRdyMAC to first sym register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_PHY_RDY_DLY_MIN       0x3C0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MIN_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x0000001C)
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MIN_OFFSET      0x0000001C
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MIN_INDEX       0x00000007
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MIN_RESET       0x000003C0

__INLINE uint32_t  fpga_dphy_common_dpy_phy_rdy_dly_min_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MIN_ADDR);
}

__INLINE void fpga_dphy_common_dpy_phy_rdy_dly_min_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MIN_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MIN_DPY_PHY_RDY_DLY_MIN_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MIN_DPY_PHY_RDY_DLY_MIN_LSB    0
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MIN_DPY_PHY_RDY_DLY_MIN_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MIN_DPY_PHY_RDY_DLY_MIN_RST    0x3C0

__INLINE uint32_t fpga_dphy_common_dpy_phy_rdy_dly_min_dpy_phy_rdy_dly_min_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MIN_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_phy_rdy_dly_min_dpy_phy_rdy_dly_min_setf(uint32_t dpyphyrdydlymin)
{
	ASSERT_ERR((((uint32_t)dpyphyrdydlymin << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MIN_ADDR, (uint32_t)dpyphyrdydlymin << 0);
}

/**
 * @brief DPY_PHY_RDY_DLY_MAX register definition
 *  Represents the time between PhyRdyMAC to first sym register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_PHY_RDY_DLY_MAX       0x3C0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MAX_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000020)
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MAX_OFFSET      0x00000020
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MAX_INDEX       0x00000008
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MAX_RESET       0x000003C0

__INLINE uint32_t  fpga_dphy_common_dpy_phy_rdy_dly_max_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MAX_ADDR);
}

__INLINE void fpga_dphy_common_dpy_phy_rdy_dly_max_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MAX_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MAX_DPY_PHY_RDY_DLY_MAX_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MAX_DPY_PHY_RDY_DLY_MAX_LSB    0
#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MAX_DPY_PHY_RDY_DLY_MAX_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MAX_DPY_PHY_RDY_DLY_MAX_RST    0x3C0

__INLINE uint32_t fpga_dphy_common_dpy_phy_rdy_dly_max_dpy_phy_rdy_dly_max_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MAX_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_phy_rdy_dly_max_dpy_phy_rdy_dly_max_setf(uint32_t dpyphyrdydlymax)
{
	ASSERT_ERR((((uint32_t)dpyphyrdydlymax << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PHY_RDY_DLY_MAX_ADDR, (uint32_t)dpyphyrdydlymax << 0);
}

/**
 * @brief DPY_TX_2_RX_CCA_ON_MIN register definition
 *  Time from data on air until CCA is set register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_TX2_RX_CCA_ON_MIN     0x3C0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MIN_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000024)
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MIN_OFFSET      0x00000024
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MIN_INDEX       0x00000009
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MIN_RESET       0x000003C0

__INLINE uint32_t  fpga_dphy_common_dpy_tx_2_rx_cca_on_min_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MIN_ADDR);
}

__INLINE void fpga_dphy_common_dpy_tx_2_rx_cca_on_min_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MIN_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MIN_DPY_TX_2_RX_CCA_ON_MIN_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MIN_DPY_TX_2_RX_CCA_ON_MIN_LSB    0
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MIN_DPY_TX_2_RX_CCA_ON_MIN_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MIN_DPY_TX_2_RX_CCA_ON_MIN_RST    0x3C0

__INLINE uint32_t fpga_dphy_common_dpy_tx_2_rx_cca_on_min_dpy_tx_2_rx_cca_on_min_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MIN_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_tx_2_rx_cca_on_min_dpy_tx_2_rx_cca_on_min_setf(uint32_t dpytx2rxccaonmin)
{
	ASSERT_ERR((((uint32_t)dpytx2rxccaonmin << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MIN_ADDR, (uint32_t)dpytx2rxccaonmin << 0);
}

/**
 * @brief DPY_TX_2_RX_CCA_ON_MAX register definition
 *  Time from data on air until CCA is set register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_TX2_RX_CCA_ON_MAX     0x3C0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MAX_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000028)
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MAX_OFFSET      0x00000028
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MAX_INDEX       0x0000000A
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MAX_RESET       0x000003C0

__INLINE uint32_t  fpga_dphy_common_dpy_tx_2_rx_cca_on_max_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MAX_ADDR);
}

__INLINE void fpga_dphy_common_dpy_tx_2_rx_cca_on_max_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MAX_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MAX_DPY_TX_2_RX_CCA_ON_MAX_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MAX_DPY_TX_2_RX_CCA_ON_MAX_LSB    0
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MAX_DPY_TX_2_RX_CCA_ON_MAX_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MAX_DPY_TX_2_RX_CCA_ON_MAX_RST    0x3C0

__INLINE uint32_t fpga_dphy_common_dpy_tx_2_rx_cca_on_max_dpy_tx_2_rx_cca_on_max_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MAX_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_tx_2_rx_cca_on_max_dpy_tx_2_rx_cca_on_max_setf(uint32_t dpytx2rxccaonmax)
{
	ASSERT_ERR((((uint32_t)dpytx2rxccaonmax << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_ON_MAX_ADDR, (uint32_t)dpytx2rxccaonmax << 0);
}

/**
 * @brief DPY_TX_2_RX_CCA_OFF_MIN register definition
 *  Time from RXENDFORTIMING until CCA is reset register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_TX2_RX_CCA_OFF_MIN    0x3C0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MIN_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x0000002C)
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MIN_OFFSET      0x0000002C
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MIN_INDEX       0x0000000B
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MIN_RESET       0x000003C0

__INLINE uint32_t  fpga_dphy_common_dpy_tx_2_rx_cca_off_min_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MIN_ADDR);
}

__INLINE void fpga_dphy_common_dpy_tx_2_rx_cca_off_min_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MIN_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MIN_DPY_TX_2_RX_CCA_OFF_MIN_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MIN_DPY_TX_2_RX_CCA_OFF_MIN_LSB    0
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MIN_DPY_TX_2_RX_CCA_OFF_MIN_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MIN_DPY_TX_2_RX_CCA_OFF_MIN_RST    0x3C0

__INLINE uint32_t fpga_dphy_common_dpy_tx_2_rx_cca_off_min_dpy_tx_2_rx_cca_off_min_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MIN_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_tx_2_rx_cca_off_min_dpy_tx_2_rx_cca_off_min_setf(uint32_t dpytx2rxccaoffmin)
{
	ASSERT_ERR((((uint32_t)dpytx2rxccaoffmin << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MIN_ADDR, (uint32_t)dpytx2rxccaoffmin << 0);
}

/**
 * @brief DPY_TX_2_RX_CCA_OFF_MAX register definition
 *  Time from RXENDFORTIMING until CCA is reset register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_TX2_RX_CCA_OFF_MAX    0x3C0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MAX_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000030)
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MAX_OFFSET      0x00000030
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MAX_INDEX       0x0000000C
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MAX_RESET       0x000003C0

__INLINE uint32_t  fpga_dphy_common_dpy_tx_2_rx_cca_off_max_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MAX_ADDR);
}

__INLINE void fpga_dphy_common_dpy_tx_2_rx_cca_off_max_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MAX_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MAX_DPY_TX_2_RX_CCA_OFF_MAX_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MAX_DPY_TX_2_RX_CCA_OFF_MAX_LSB    0
#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MAX_DPY_TX_2_RX_CCA_OFF_MAX_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MAX_DPY_TX_2_RX_CCA_OFF_MAX_RST    0x3C0

__INLINE uint32_t fpga_dphy_common_dpy_tx_2_rx_cca_off_max_dpy_tx_2_rx_cca_off_max_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MAX_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_tx_2_rx_cca_off_max_dpy_tx_2_rx_cca_off_max_setf(uint32_t dpytx2rxccaoffmax)
{
	ASSERT_ERR((((uint32_t)dpytx2rxccaoffmax << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_TX_2_RX_CCA_OFF_MAX_ADDR, (uint32_t)dpytx2rxccaoffmax << 0);
}

/**
 * @brief DPY_PRCSS_DLY_MIN register definition
 *  Timing from symbol arriving to TX-PHY until receiv register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_PRCSS_DLY_MIN         0x1E0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MIN_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000034)
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MIN_OFFSET      0x00000034
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MIN_INDEX       0x0000000D
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MIN_RESET       0x000001E0

__INLINE uint32_t  fpga_dphy_common_dpy_prcss_dly_min_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MIN_ADDR);
}

__INLINE void fpga_dphy_common_dpy_prcss_dly_min_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MIN_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MIN_DPY_PRCSS_DLY_MIN_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MIN_DPY_PRCSS_DLY_MIN_LSB    0
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MIN_DPY_PRCSS_DLY_MIN_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MIN_DPY_PRCSS_DLY_MIN_RST    0x1E0

__INLINE uint32_t fpga_dphy_common_dpy_prcss_dly_min_dpy_prcss_dly_min_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MIN_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_prcss_dly_min_dpy_prcss_dly_min_setf(uint32_t dpyprcssdlymin)
{
	ASSERT_ERR((((uint32_t)dpyprcssdlymin << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MIN_ADDR, (uint32_t)dpyprcssdlymin << 0);
}

/**
 * @brief DPY_PRCSS_DLY_MAX register definition
 *  Timing from symbol arriving to TX-PHY until receiv register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_PRCSS_DLY_MAX         0x1E0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MAX_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000038)
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MAX_OFFSET      0x00000038
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MAX_INDEX       0x0000000E
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MAX_RESET       0x000001E0

__INLINE uint32_t  fpga_dphy_common_dpy_prcss_dly_max_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MAX_ADDR);
}

__INLINE void fpga_dphy_common_dpy_prcss_dly_max_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MAX_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MAX_DPY_PRCSS_DLY_MAX_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MAX_DPY_PRCSS_DLY_MAX_LSB    0
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MAX_DPY_PRCSS_DLY_MAX_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MAX_DPY_PRCSS_DLY_MAX_RST    0x1E0

__INLINE uint32_t fpga_dphy_common_dpy_prcss_dly_max_dpy_prcss_dly_max_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MAX_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_prcss_dly_max_dpy_prcss_dly_max_setf(uint32_t dpyprcssdlymax)
{
	ASSERT_ERR((((uint32_t)dpyprcssdlymax << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_MAX_ADDR, (uint32_t)dpyprcssdlymax << 0);
}

/**
 * @brief DPY_PRCSS_DLY_NO_OFDM_MIN register definition
 *  Timing from symbol arriving to TX-PHY until receiv register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_PRCSS_DLY_NO_OFDM_MIN 0x0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MIN_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x0000003C)
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MIN_OFFSET      0x0000003C
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MIN_INDEX       0x0000000F
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MIN_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_common_dpy_prcss_dly_no_ofdm_min_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MIN_ADDR);
}

__INLINE void fpga_dphy_common_dpy_prcss_dly_no_ofdm_min_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MIN_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MIN_DPY_PRCSS_DLY_NO_OFDM_MIN_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MIN_DPY_PRCSS_DLY_NO_OFDM_MIN_LSB    0
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MIN_DPY_PRCSS_DLY_NO_OFDM_MIN_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MIN_DPY_PRCSS_DLY_NO_OFDM_MIN_RST    0x0

__INLINE uint32_t fpga_dphy_common_dpy_prcss_dly_no_ofdm_min_dpy_prcss_dly_no_ofdm_min_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MIN_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_prcss_dly_no_ofdm_min_dpy_prcss_dly_no_ofdm_min_setf(uint32_t dpyprcssdlynoofdmmin)
{
	ASSERT_ERR((((uint32_t)dpyprcssdlynoofdmmin << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MIN_ADDR, (uint32_t)dpyprcssdlynoofdmmin << 0);
}

/**
 * @brief DPY_PRCSS_DLY_NO_OFDM_MAX register definition
 *  Timing from symbol arriving to TX-PHY until receiv register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 DPY_PRCSS_DLY_NO_OFDM_MAX 0x0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MAX_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000040)
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MAX_OFFSET      0x00000040
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MAX_INDEX       0x00000010
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MAX_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_common_dpy_prcss_dly_no_ofdm_max_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MAX_ADDR);
}

__INLINE void fpga_dphy_common_dpy_prcss_dly_no_ofdm_max_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MAX_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MAX_DPY_PRCSS_DLY_NO_OFDM_MAX_MASK    ((uint32_t)0x000FFFFF)
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MAX_DPY_PRCSS_DLY_NO_OFDM_MAX_LSB    0
#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MAX_DPY_PRCSS_DLY_NO_OFDM_MAX_WIDTH    ((uint32_t)0x00000014)

#define FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MAX_DPY_PRCSS_DLY_NO_OFDM_MAX_RST    0x0

__INLINE uint32_t fpga_dphy_common_dpy_prcss_dly_no_ofdm_max_dpy_prcss_dly_no_ofdm_max_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MAX_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_prcss_dly_no_ofdm_max_dpy_prcss_dly_no_ofdm_max_setf(uint32_t dpyprcssdlynoofdmmax)
{
	ASSERT_ERR((((uint32_t)dpyprcssdlynoofdmmax << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_PRCSS_DLY_NO_OFDM_MAX_ADDR, (uint32_t)dpyprcssdlynoofdmmax << 0);
}

/**
 * @brief DPY_STA_DIS_DL register definition
 *  Writing 1 in the relevant bit disables the station register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 DPY_STA_DIS_DL            0x0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_STA_DIS_DL_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000044)
#define FPGA_DPHY_COMMON_DPY_STA_DIS_DL_OFFSET      0x00000044
#define FPGA_DPHY_COMMON_DPY_STA_DIS_DL_INDEX       0x00000011
#define FPGA_DPHY_COMMON_DPY_STA_DIS_DL_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_common_dpy_sta_dis_dl_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_STA_DIS_DL_ADDR);
}

__INLINE void fpga_dphy_common_dpy_sta_dis_dl_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_STA_DIS_DL_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_STA_DIS_DL_DPY_STA_DIS_DL_MASK    ((uint32_t)0x000000FF)
#define FPGA_DPHY_COMMON_DPY_STA_DIS_DL_DPY_STA_DIS_DL_LSB    0
#define FPGA_DPHY_COMMON_DPY_STA_DIS_DL_DPY_STA_DIS_DL_WIDTH    ((uint32_t)0x00000008)

#define FPGA_DPHY_COMMON_DPY_STA_DIS_DL_DPY_STA_DIS_DL_RST    0x0

__INLINE uint8_t fpga_dphy_common_dpy_sta_dis_dl_dpy_sta_dis_dl_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_STA_DIS_DL_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_sta_dis_dl_dpy_sta_dis_dl_setf(uint8_t dpystadisdl)
{
	ASSERT_ERR((((uint32_t)dpystadisdl << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_STA_DIS_DL_ADDR, (uint32_t)dpystadisdl << 0);
}

/**
 * @brief DPY_STA_DIS_UL register definition
 *  Writing 1 in the relevant bit disables the station register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 DPY_STA_DIS_UL            0x0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_STA_DIS_UL_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000048)
#define FPGA_DPHY_COMMON_DPY_STA_DIS_UL_OFFSET      0x00000048
#define FPGA_DPHY_COMMON_DPY_STA_DIS_UL_INDEX       0x00000012
#define FPGA_DPHY_COMMON_DPY_STA_DIS_UL_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_common_dpy_sta_dis_ul_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_STA_DIS_UL_ADDR);
}

__INLINE void fpga_dphy_common_dpy_sta_dis_ul_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_STA_DIS_UL_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_STA_DIS_UL_DPY_STA_DIS_UL_MASK    ((uint32_t)0x000000FF)
#define FPGA_DPHY_COMMON_DPY_STA_DIS_UL_DPY_STA_DIS_UL_LSB    0
#define FPGA_DPHY_COMMON_DPY_STA_DIS_UL_DPY_STA_DIS_UL_WIDTH    ((uint32_t)0x00000008)

#define FPGA_DPHY_COMMON_DPY_STA_DIS_UL_DPY_STA_DIS_UL_RST    0x0

__INLINE uint8_t fpga_dphy_common_dpy_sta_dis_ul_dpy_sta_dis_ul_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_STA_DIS_UL_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_sta_dis_ul_dpy_sta_dis_ul_setf(uint8_t dpystadisul)
{
	ASSERT_ERR((((uint32_t)dpystadisul << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_STA_DIS_UL_ADDR, (uint32_t)dpystadisul << 0);
}

/**
 * @brief DPY_INJECT_ERR register definition
 *  Error injection (emulates channel faults) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DPY_INJECT_ERR            0x0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_INJECT_ERR_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x0000004C)
#define FPGA_DPHY_COMMON_DPY_INJECT_ERR_OFFSET      0x0000004C
#define FPGA_DPHY_COMMON_DPY_INJECT_ERR_INDEX       0x00000013
#define FPGA_DPHY_COMMON_DPY_INJECT_ERR_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_common_dpy_inject_err_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_INJECT_ERR_ADDR);
}

__INLINE void fpga_dphy_common_dpy_inject_err_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_INJECT_ERR_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_INJECT_ERR_DPY_INJECT_ERR_MASK    ((uint32_t)0xFFFFFFFF)
#define FPGA_DPHY_COMMON_DPY_INJECT_ERR_DPY_INJECT_ERR_LSB    0
#define FPGA_DPHY_COMMON_DPY_INJECT_ERR_DPY_INJECT_ERR_WIDTH    ((uint32_t)0x00000020)

#define FPGA_DPHY_COMMON_DPY_INJECT_ERR_DPY_INJECT_ERR_RST    0x0

__INLINE uint32_t fpga_dphy_common_dpy_inject_err_dpy_inject_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_INJECT_ERR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_inject_err_dpy_inject_err_setf(uint32_t dpyinjecterr)
{
	ASSERT_ERR((((uint32_t)dpyinjecterr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_INJECT_ERR_ADDR, (uint32_t)dpyinjecterr << 0);
}

/**
 * @brief DPY_INJECT_RXERR register definition
 *  Generate random errors on selected frames register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:12 DPY_INJECT_RXERR_CYCLE    0x0
 *    11:00 DPY_INJECT_RXERR_FRAME    0x0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_INJECT_RXERR_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000050)
#define FPGA_DPHY_COMMON_DPY_INJECT_RXERR_OFFSET      0x00000050
#define FPGA_DPHY_COMMON_DPY_INJECT_RXERR_INDEX       0x00000014
#define FPGA_DPHY_COMMON_DPY_INJECT_RXERR_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_common_dpy_inject_rxerr_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_INJECT_RXERR_ADDR);
}

__INLINE void fpga_dphy_common_dpy_inject_rxerr_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_INJECT_RXERR_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_INJECT_RXERR_DPY_INJECT_RXERR_CYCLE_MASK    ((uint32_t)0xFFFFF000)
#define FPGA_DPHY_COMMON_DPY_INJECT_RXERR_DPY_INJECT_RXERR_CYCLE_LSB    12
#define FPGA_DPHY_COMMON_DPY_INJECT_RXERR_DPY_INJECT_RXERR_CYCLE_WIDTH    ((uint32_t)0x00000014)
#define FPGA_DPHY_COMMON_DPY_INJECT_RXERR_DPY_INJECT_RXERR_FRAME_MASK    ((uint32_t)0x00000FFF)
#define FPGA_DPHY_COMMON_DPY_INJECT_RXERR_DPY_INJECT_RXERR_FRAME_LSB    0
#define FPGA_DPHY_COMMON_DPY_INJECT_RXERR_DPY_INJECT_RXERR_FRAME_WIDTH    ((uint32_t)0x0000000C)

#define FPGA_DPHY_COMMON_DPY_INJECT_RXERR_DPY_INJECT_RXERR_CYCLE_RST    0x0
#define FPGA_DPHY_COMMON_DPY_INJECT_RXERR_DPY_INJECT_RXERR_FRAME_RST    0x0

__INLINE void fpga_dphy_common_dpy_inject_rxerr_pack(uint32_t dpy_inject_rxerr_cycle, uint16_t dpy_inject_rxerr_frame)
{
	ASSERT_ERR((((uint32_t)dpy_inject_rxerr_cycle << 12) & ~((uint32_t)0xFFFFF000)) == 0);
	ASSERT_ERR((((uint32_t)dpy_inject_rxerr_frame << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_INJECT_RXERR_ADDR,  ((uint32_t)dpy_inject_rxerr_cycle << 12) |((uint32_t)dpy_inject_rxerr_frame << 0));
}

__INLINE void fpga_dphy_common_dpy_inject_rxerr_unpack(uint32_t* dpy_inject_rxerr_cycle, uint16_t* dpy_inject_rxerr_frame)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_INJECT_RXERR_ADDR);

	*dpy_inject_rxerr_cycle = (localVal & ((uint32_t)0xFFFFF000)) >>  12;
	*dpy_inject_rxerr_frame = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE void fpga_dphy_common_dpy_inject_rxerr_dpy_inject_rxerr_cycle_setf(uint32_t dpyinjectrxerrcycle)
{
	ASSERT_ERR((((uint32_t)dpyinjectrxerrcycle << 12) & ~((uint32_t)0xFFFFF000)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_INJECT_RXERR_ADDR, (REG_PL_RD(FPGA_DPHY_COMMON_DPY_INJECT_RXERR_ADDR) & ~((uint32_t)0xFFFFF000)) | ((uint32_t)dpyinjectrxerrcycle <<12));
}
__INLINE uint16_t fpga_dphy_common_dpy_inject_rxerr_dpy_inject_rxerr_frame_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_INJECT_RXERR_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void fpga_dphy_common_dpy_inject_rxerr_dpy_inject_rxerr_frame_setf(uint16_t dpyinjectrxerrframe)
{
	ASSERT_ERR((((uint32_t)dpyinjectrxerrframe << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_INJECT_RXERR_ADDR, (REG_PL_RD(FPGA_DPHY_COMMON_DPY_INJECT_RXERR_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)dpyinjectrxerrframe <<0));
}

/**
 * @brief DPY_FORCE_CCA_AP register definition
 *  When relevant bit is set, CCA_AP is forced in the  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 DPY_FORCE_CCA_AP          0x0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_AP_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000054)
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_AP_OFFSET      0x00000054
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_AP_INDEX       0x00000015
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_AP_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_common_dpy_force_cca_ap_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_FORCE_CCA_AP_ADDR);
}

__INLINE void fpga_dphy_common_dpy_force_cca_ap_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_FORCE_CCA_AP_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_AP_DPY_FORCE_CCA_AP_MASK    ((uint32_t)0x000000FF)
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_AP_DPY_FORCE_CCA_AP_LSB    0
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_AP_DPY_FORCE_CCA_AP_WIDTH    ((uint32_t)0x00000008)

#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_AP_DPY_FORCE_CCA_AP_RST    0x0

__INLINE uint8_t fpga_dphy_common_dpy_force_cca_ap_dpy_force_cca_ap_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_FORCE_CCA_AP_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_force_cca_ap_dpy_force_cca_ap_setf(uint8_t dpyforceccaap)
{
	ASSERT_ERR((((uint32_t)dpyforceccaap << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_FORCE_CCA_AP_ADDR, (uint32_t)dpyforceccaap << 0);
}

/**
 * @brief DPY_FORCE_CCA_STA_REG_0 register definition
 *  When relevant bit is set, CCA is forced register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DPY_FORCE_CCA_STA_REG0    0x0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_0_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000058)
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_0_OFFSET      0x00000058
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_0_INDEX       0x00000016
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_0_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_common_dpy_force_cca_sta_reg_0_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_0_ADDR);
}

__INLINE void fpga_dphy_common_dpy_force_cca_sta_reg_0_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_0_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_0_DPY_FORCE_CCA_STA_REG_0_MASK    ((uint32_t)0xFFFFFFFF)
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_0_DPY_FORCE_CCA_STA_REG_0_LSB    0
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_0_DPY_FORCE_CCA_STA_REG_0_WIDTH    ((uint32_t)0x00000020)

#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_0_DPY_FORCE_CCA_STA_REG_0_RST    0x0

__INLINE uint32_t fpga_dphy_common_dpy_force_cca_sta_reg_0_dpy_force_cca_sta_reg_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_force_cca_sta_reg_0_dpy_force_cca_sta_reg_0_setf(uint32_t dpyforceccastareg0)
{
	ASSERT_ERR((((uint32_t)dpyforceccastareg0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_0_ADDR, (uint32_t)dpyforceccastareg0 << 0);
}

/**
 * @brief DPY_FORCE_CCA_STA_REG_1 register definition
 *  When relevant bit is set, CCA is forced register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DPY_FORCE_CCA_STA_REG1    0x0
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_1_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x0000005C)
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_1_OFFSET      0x0000005C
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_1_INDEX       0x00000017
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_1_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_common_dpy_force_cca_sta_reg_1_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_1_ADDR);
}

__INLINE void fpga_dphy_common_dpy_force_cca_sta_reg_1_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_1_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_1_DPY_FORCE_CCA_STA_REG_1_MASK    ((uint32_t)0xFFFFFFFF)
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_1_DPY_FORCE_CCA_STA_REG_1_LSB    0
#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_1_DPY_FORCE_CCA_STA_REG_1_WIDTH    ((uint32_t)0x00000020)

#define FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_1_DPY_FORCE_CCA_STA_REG_1_RST    0x0

__INLINE uint32_t fpga_dphy_common_dpy_force_cca_sta_reg_1_dpy_force_cca_sta_reg_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_force_cca_sta_reg_1_dpy_force_cca_sta_reg_1_setf(uint32_t dpyforceccastareg1)
{
	ASSERT_ERR((((uint32_t)dpyforceccastareg1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_FORCE_CCA_STA_REG_1_ADDR, (uint32_t)dpyforceccastareg1 << 0);
}

/**
 * @brief DPY_COMMON_CCA register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    COMMON_CCA                0              
 * </pre>
 */
#define FPGA_DPHY_COMMON_DPY_COMMON_CCA_ADDR        (REG_FPGA_DPHY_COMMON_BASE_ADDR+0x00000060)
#define FPGA_DPHY_COMMON_DPY_COMMON_CCA_OFFSET      0x00000060
#define FPGA_DPHY_COMMON_DPY_COMMON_CCA_INDEX       0x00000018
#define FPGA_DPHY_COMMON_DPY_COMMON_CCA_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_common_dpy_common_cca_get(void)
{
	return REG_PL_RD(FPGA_DPHY_COMMON_DPY_COMMON_CCA_ADDR);
}

__INLINE void fpga_dphy_common_dpy_common_cca_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_COMMON_CCA_ADDR, value);
}

// field definitions
#define FPGA_DPHY_COMMON_DPY_COMMON_CCA_COMMON_CCA_BIT    ((uint32_t)0x00000001)
#define FPGA_DPHY_COMMON_DPY_COMMON_CCA_COMMON_CCA_POS    0

#define FPGA_DPHY_COMMON_DPY_COMMON_CCA_COMMON_CCA_RST    0x0

__INLINE uint8_t fpga_dphy_common_dpy_common_cca_common_cca_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_COMMON_DPY_COMMON_CCA_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void fpga_dphy_common_dpy_common_cca_common_cca_setf(uint8_t commoncca)
{
	ASSERT_ERR((((uint32_t)commoncca << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(FPGA_DPHY_COMMON_DPY_COMMON_CCA_ADDR, (uint32_t)commoncca << 0);
}


#undef DBG_FILEID
#endif //_REG_FPGA_DPHY_COMMON_H_
