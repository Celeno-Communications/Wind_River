#ifndef _REG_FPGA_DPHY_AP0_H_
#define _REG_FPGA_DPHY_AP0_H_

#include <stdint.h>
#include "dphy/_reg_fpga_dphy_ap0.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_FPGA_DPHY_AP0__H__FILEID__

#define REG_FPGA_DPHY_AP0_COUNT  7


/**
 * @brief DPY_TX_BYTE_CNT register definition
 *  Counts total number of transmitted bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DPY_TX_BYTE_CNT           0x0
 * </pre>
 */
#define FPGA_DPHY_AP0_DPY_TX_BYTE_CNT_ADDR        (REG_FPGA_DPHY_AP0_BASE_ADDR+0x00000000)
#define FPGA_DPHY_AP0_DPY_TX_BYTE_CNT_OFFSET      0x00000000
#define FPGA_DPHY_AP0_DPY_TX_BYTE_CNT_INDEX       0x00000000
#define FPGA_DPHY_AP0_DPY_TX_BYTE_CNT_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_ap0_dpy_tx_byte_cnt_get(void)
{
	return REG_PL_RD(FPGA_DPHY_AP0_DPY_TX_BYTE_CNT_ADDR);
}

__INLINE void fpga_dphy_ap0_dpy_tx_byte_cnt_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_AP0_DPY_TX_BYTE_CNT_ADDR, value);
}

// field definitions
#define FPGA_DPHY_AP0_DPY_TX_BYTE_CNT_DPY_TX_BYTE_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define FPGA_DPHY_AP0_DPY_TX_BYTE_CNT_DPY_TX_BYTE_CNT_LSB    0
#define FPGA_DPHY_AP0_DPY_TX_BYTE_CNT_DPY_TX_BYTE_CNT_WIDTH    ((uint32_t)0x00000020)

#define FPGA_DPHY_AP0_DPY_TX_BYTE_CNT_DPY_TX_BYTE_CNT_RST    0x0

__INLINE uint32_t fpga_dphy_ap0_dpy_tx_byte_cnt_dpy_tx_byte_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_TX_BYTE_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_ap0_dpy_tx_byte_cnt_dpy_tx_byte_cnt_setf(uint32_t dpytxbytecnt)
{
	ASSERT_ERR((((uint32_t)dpytxbytecnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_AP0_DPY_TX_BYTE_CNT_ADDR, (uint32_t)dpytxbytecnt << 0);
}

/**
 * @brief DPY_TX_PKT_CNT register definition
 *  Counts total number of transmitted packets register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DPY_TX_PKT_CNT            0x0
 * </pre>
 */
#define FPGA_DPHY_AP0_DPY_TX_PKT_CNT_ADDR        (REG_FPGA_DPHY_AP0_BASE_ADDR+0x00000004)
#define FPGA_DPHY_AP0_DPY_TX_PKT_CNT_OFFSET      0x00000004
#define FPGA_DPHY_AP0_DPY_TX_PKT_CNT_INDEX       0x00000001
#define FPGA_DPHY_AP0_DPY_TX_PKT_CNT_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_ap0_dpy_tx_pkt_cnt_get(void)
{
	return REG_PL_RD(FPGA_DPHY_AP0_DPY_TX_PKT_CNT_ADDR);
}

__INLINE void fpga_dphy_ap0_dpy_tx_pkt_cnt_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_AP0_DPY_TX_PKT_CNT_ADDR, value);
}

// field definitions
#define FPGA_DPHY_AP0_DPY_TX_PKT_CNT_DPY_TX_PKT_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define FPGA_DPHY_AP0_DPY_TX_PKT_CNT_DPY_TX_PKT_CNT_LSB    0
#define FPGA_DPHY_AP0_DPY_TX_PKT_CNT_DPY_TX_PKT_CNT_WIDTH    ((uint32_t)0x00000020)

#define FPGA_DPHY_AP0_DPY_TX_PKT_CNT_DPY_TX_PKT_CNT_RST    0x0

__INLINE uint32_t fpga_dphy_ap0_dpy_tx_pkt_cnt_dpy_tx_pkt_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_TX_PKT_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_ap0_dpy_tx_pkt_cnt_dpy_tx_pkt_cnt_setf(uint32_t dpytxpktcnt)
{
	ASSERT_ERR((((uint32_t)dpytxpktcnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_AP0_DPY_TX_PKT_CNT_ADDR, (uint32_t)dpytxpktcnt << 0);
}

/**
 * @brief DPY_RX_BYTE_CNT register definition
 *  Counts total number of received bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DPY_RX_BYTE_CNT           0x0
 * </pre>
 */
#define FPGA_DPHY_AP0_DPY_RX_BYTE_CNT_ADDR        (REG_FPGA_DPHY_AP0_BASE_ADDR+0x00000008)
#define FPGA_DPHY_AP0_DPY_RX_BYTE_CNT_OFFSET      0x00000008
#define FPGA_DPHY_AP0_DPY_RX_BYTE_CNT_INDEX       0x00000002
#define FPGA_DPHY_AP0_DPY_RX_BYTE_CNT_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_ap0_dpy_rx_byte_cnt_get(void)
{
	return REG_PL_RD(FPGA_DPHY_AP0_DPY_RX_BYTE_CNT_ADDR);
}

__INLINE void fpga_dphy_ap0_dpy_rx_byte_cnt_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_AP0_DPY_RX_BYTE_CNT_ADDR, value);
}

// field definitions
#define FPGA_DPHY_AP0_DPY_RX_BYTE_CNT_DPY_RX_BYTE_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define FPGA_DPHY_AP0_DPY_RX_BYTE_CNT_DPY_RX_BYTE_CNT_LSB    0
#define FPGA_DPHY_AP0_DPY_RX_BYTE_CNT_DPY_RX_BYTE_CNT_WIDTH    ((uint32_t)0x00000020)

#define FPGA_DPHY_AP0_DPY_RX_BYTE_CNT_DPY_RX_BYTE_CNT_RST    0x0

__INLINE uint32_t fpga_dphy_ap0_dpy_rx_byte_cnt_dpy_rx_byte_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_RX_BYTE_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_ap0_dpy_rx_byte_cnt_dpy_rx_byte_cnt_setf(uint32_t dpyrxbytecnt)
{
	ASSERT_ERR((((uint32_t)dpyrxbytecnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_AP0_DPY_RX_BYTE_CNT_ADDR, (uint32_t)dpyrxbytecnt << 0);
}

/**
 * @brief DPY_RX_PKT_CNT register definition
 *  Counts total number of received packets register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DPY_RX_PKT_CNT            0x0
 * </pre>
 */
#define FPGA_DPHY_AP0_DPY_RX_PKT_CNT_ADDR        (REG_FPGA_DPHY_AP0_BASE_ADDR+0x0000000C)
#define FPGA_DPHY_AP0_DPY_RX_PKT_CNT_OFFSET      0x0000000C
#define FPGA_DPHY_AP0_DPY_RX_PKT_CNT_INDEX       0x00000003
#define FPGA_DPHY_AP0_DPY_RX_PKT_CNT_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_ap0_dpy_rx_pkt_cnt_get(void)
{
	return REG_PL_RD(FPGA_DPHY_AP0_DPY_RX_PKT_CNT_ADDR);
}

__INLINE void fpga_dphy_ap0_dpy_rx_pkt_cnt_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_AP0_DPY_RX_PKT_CNT_ADDR, value);
}

// field definitions
#define FPGA_DPHY_AP0_DPY_RX_PKT_CNT_DPY_RX_PKT_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define FPGA_DPHY_AP0_DPY_RX_PKT_CNT_DPY_RX_PKT_CNT_LSB    0
#define FPGA_DPHY_AP0_DPY_RX_PKT_CNT_DPY_RX_PKT_CNT_WIDTH    ((uint32_t)0x00000020)

#define FPGA_DPHY_AP0_DPY_RX_PKT_CNT_DPY_RX_PKT_CNT_RST    0x0

__INLINE uint32_t fpga_dphy_ap0_dpy_rx_pkt_cnt_dpy_rx_pkt_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_RX_PKT_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void fpga_dphy_ap0_dpy_rx_pkt_cnt_dpy_rx_pkt_cnt_setf(uint32_t dpyrxpktcnt)
{
	ASSERT_ERR((((uint32_t)dpyrxpktcnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(FPGA_DPHY_AP0_DPY_RX_PKT_CNT_ADDR, (uint32_t)dpyrxpktcnt << 0);
}

/**
 * @brief DPY_LAST_RX_LEN register definition
 *  Number of bytes in last received packet register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DPY_LAST_RX_LEN           0x0
 * </pre>
 */
#define FPGA_DPHY_AP0_DPY_LAST_RX_LEN_ADDR        (REG_FPGA_DPHY_AP0_BASE_ADDR+0x00000010)
#define FPGA_DPHY_AP0_DPY_LAST_RX_LEN_OFFSET      0x00000010
#define FPGA_DPHY_AP0_DPY_LAST_RX_LEN_INDEX       0x00000004
#define FPGA_DPHY_AP0_DPY_LAST_RX_LEN_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_ap0_dpy_last_rx_len_get(void)
{
	return REG_PL_RD(FPGA_DPHY_AP0_DPY_LAST_RX_LEN_ADDR);
}

// field definitions
#define FPGA_DPHY_AP0_DPY_LAST_RX_LEN_DPY_LAST_RX_LEN_MASK    ((uint32_t)0xFFFFFFFF)
#define FPGA_DPHY_AP0_DPY_LAST_RX_LEN_DPY_LAST_RX_LEN_LSB    0
#define FPGA_DPHY_AP0_DPY_LAST_RX_LEN_DPY_LAST_RX_LEN_WIDTH    ((uint32_t)0x00000020)

#define FPGA_DPHY_AP0_DPY_LAST_RX_LEN_DPY_LAST_RX_LEN_RST    0x0

__INLINE uint32_t fpga_dphy_ap0_dpy_last_rx_len_dpy_last_rx_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_LAST_RX_LEN_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief DPY_INTERNAL_STATE register definition
 *  Enables debug RAM record of each Tx and Rx packet  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    DPY_DBG_SET               0              
 *    02    DPY_DBG_RST               0              
 *    01    DPY_DBG_BAD               0              
 *    00    DPY_DBG_EN                0              
 * </pre>
 */
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR        (REG_FPGA_DPHY_AP0_BASE_ADDR+0x00000014)
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_OFFSET      0x00000014
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_INDEX       0x00000005
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_ap0_dpy_internal_state_get(void)
{
	return REG_PL_RD(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR);
}

__INLINE void fpga_dphy_ap0_dpy_internal_state_set(uint32_t value)
{
	REG_PL_WR(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR, value);
}

// field definitions
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_DPY_DBG_SET_BIT    ((uint32_t)0x00000008)
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_DPY_DBG_SET_POS    3
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_DPY_DBG_RST_BIT    ((uint32_t)0x00000004)
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_DPY_DBG_RST_POS    2
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_DPY_DBG_BAD_BIT    ((uint32_t)0x00000002)
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_DPY_DBG_BAD_POS    1
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_DPY_DBG_EN_BIT    ((uint32_t)0x00000001)
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_DPY_DBG_EN_POS    0

#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_DPY_DBG_SET_RST    0x0
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_DPY_DBG_RST_RST    0x0
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_DPY_DBG_BAD_RST    0x0
#define FPGA_DPHY_AP0_DPY_INTERNAL_STATE_DPY_DBG_EN_RST    0x0

__INLINE void fpga_dphy_ap0_dpy_internal_state_pack(uint8_t dpy_dbg_set, uint8_t dpy_dbg_rst, uint8_t dpy_dbg_bad, uint8_t dpy_dbg_en)
{
	ASSERT_ERR((((uint32_t)dpy_dbg_set << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)dpy_dbg_rst << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)dpy_dbg_bad << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)dpy_dbg_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR,  ((uint32_t)dpy_dbg_set << 3) |((uint32_t)dpy_dbg_rst << 2) |((uint32_t)dpy_dbg_bad << 1) |((uint32_t)dpy_dbg_en << 0));
}

__INLINE void fpga_dphy_ap0_dpy_internal_state_unpack(uint8_t* dpy_dbg_set, uint8_t* dpy_dbg_rst, uint8_t* dpy_dbg_bad, uint8_t* dpy_dbg_en)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR);

	*dpy_dbg_set = (localVal & ((uint32_t)0x00000008)) >>  3;
	*dpy_dbg_rst = (localVal & ((uint32_t)0x00000004)) >>  2;
	*dpy_dbg_bad = (localVal & ((uint32_t)0x00000002)) >>  1;
	*dpy_dbg_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t fpga_dphy_ap0_dpy_internal_state_dpy_dbg_set_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void fpga_dphy_ap0_dpy_internal_state_dpy_dbg_set_setf(uint8_t dpydbgset)
{
	ASSERT_ERR((((uint32_t)dpydbgset << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR, (REG_PL_RD(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)dpydbgset <<3));
}
__INLINE uint8_t fpga_dphy_ap0_dpy_internal_state_dpy_dbg_rst_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void fpga_dphy_ap0_dpy_internal_state_dpy_dbg_rst_setf(uint8_t dpydbgrst)
{
	ASSERT_ERR((((uint32_t)dpydbgrst << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR, (REG_PL_RD(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)dpydbgrst <<2));
}
__INLINE uint8_t fpga_dphy_ap0_dpy_internal_state_dpy_dbg_bad_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void fpga_dphy_ap0_dpy_internal_state_dpy_dbg_bad_setf(uint8_t dpydbgbad)
{
	ASSERT_ERR((((uint32_t)dpydbgbad << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR, (REG_PL_RD(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)dpydbgbad <<1));
}
__INLINE uint8_t fpga_dphy_ap0_dpy_internal_state_dpy_dbg_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void fpga_dphy_ap0_dpy_internal_state_dpy_dbg_en_setf(uint8_t dpydbgen)
{
	ASSERT_ERR((((uint32_t)dpydbgen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR, (REG_PL_RD(FPGA_DPHY_AP0_DPY_INTERNAL_STATE_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)dpydbgen <<0));
}

/**
 * @brief DPY_DBG_RAM_NEXT register definition
 *  The next Tx address inside the debug RAM to be wri register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 DPY_DBG_NEXT_RX           0x0
 *    11:00 DPY_DBG_NEXT_TX           0x0
 * </pre>
 */
#define FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_ADDR        (REG_FPGA_DPHY_AP0_BASE_ADDR+0x00000018)
#define FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_OFFSET      0x00000018
#define FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_INDEX       0x00000006
#define FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_RESET       0x00000000

__INLINE uint32_t  fpga_dphy_ap0_dpy_dbg_ram_next_get(void)
{
	return REG_PL_RD(FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_ADDR);
}

// field definitions
#define FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_DPY_DBG_NEXT_RX_MASK    ((uint32_t)0x0FFF0000)
#define FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_DPY_DBG_NEXT_RX_LSB    16
#define FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_DPY_DBG_NEXT_RX_WIDTH    ((uint32_t)0x0000000C)
#define FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_DPY_DBG_NEXT_TX_MASK    ((uint32_t)0x00000FFF)
#define FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_DPY_DBG_NEXT_TX_LSB    0
#define FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_DPY_DBG_NEXT_TX_WIDTH    ((uint32_t)0x0000000C)

#define FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_DPY_DBG_NEXT_RX_RST    0x0
#define FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_DPY_DBG_NEXT_TX_RST    0x0

__INLINE void fpga_dphy_ap0_dpy_dbg_ram_next_unpack(uint16_t* dpy_dbg_next_rx, uint16_t* dpy_dbg_next_tx)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_ADDR);

	*dpy_dbg_next_rx = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*dpy_dbg_next_tx = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t fpga_dphy_ap0_dpy_dbg_ram_next_dpy_dbg_next_rx_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t fpga_dphy_ap0_dpy_dbg_ram_next_dpy_dbg_next_tx_getf(void)
{
	uint32_t localVal = REG_PL_RD(FPGA_DPHY_AP0_DPY_DBG_RAM_NEXT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}


#undef DBG_FILEID
#endif //_REG_FPGA_DPHY_AP0_H_
