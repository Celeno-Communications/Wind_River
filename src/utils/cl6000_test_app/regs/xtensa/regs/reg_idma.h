#ifndef _REG_IDMA_H_
#define _REG_IDMA_H_

#include <stdint.h>
#include "_reg_idma.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_IDMA__H__FILEID__

#define REG_IDMA_COUNT  55


/**
 * @brief IDMA_SW_RST register definition
 *  Software reset register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    SW_RST                    0              
 * </pre>
 */
#define IDMA_IDMA_SW_RST_ADDR        (REG_IDMA_BASE_ADDR+0x00000000)
#define IDMA_IDMA_SW_RST_OFFSET      0x00000000
#define IDMA_IDMA_SW_RST_INDEX       0x00000000
#define IDMA_IDMA_SW_RST_RESET       0x00000000

__INLINE void idma_idma_sw_rst_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SW_RST_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SW_RST_SW_RST_BIT         ((uint32_t)0x00000001)
#define IDMA_IDMA_SW_RST_SW_RST_POS         0

#define IDMA_IDMA_SW_RST_SW_RST_RST         0x0

__INLINE void idma_idma_sw_rst_sw_rst_setf(uint8_t swrst)
{
	ASSERT_ERR((((uint32_t)swrst << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IDMA_IDMA_SW_RST_ADDR, (uint32_t)swrst << 0);
}

/**
 * @brief IDMA_STOP register definition
 *  Stop DMA processing register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    IDMA_STOP                 0              
 * </pre>
 */
#define IDMA_IDMA_STOP_ADDR        (REG_IDMA_BASE_ADDR+0x00000004)
#define IDMA_IDMA_STOP_OFFSET      0x00000004
#define IDMA_IDMA_STOP_INDEX       0x00000001
#define IDMA_IDMA_STOP_RESET       0x00000000

__INLINE uint32_t  idma_idma_stop_get(void)
{
	return REG_PL_RD(IDMA_IDMA_STOP_ADDR);
}

__INLINE void idma_idma_stop_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_STOP_ADDR, value);
}

// field definitions
#define IDMA_IDMA_STOP_IDMA_STOP_BIT        ((uint32_t)0x00000001)
#define IDMA_IDMA_STOP_IDMA_STOP_POS        0

#define IDMA_IDMA_STOP_IDMA_STOP_RST        0x0

__INLINE uint8_t idma_idma_stop_idma_stop_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_STOP_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void idma_idma_stop_idma_stop_setf(uint8_t idmastop)
{
	ASSERT_ERR((((uint32_t)idmastop << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IDMA_IDMA_STOP_ADDR, (uint32_t)idmastop << 0);
}

/**
 * @brief IDMA_INT_RAW_STAT register definition
 *  Raw interrupt register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23    SET5_OVERWRITE_ERR        0              
 *    22    SET5_AXI_WR_ERR           0              
 *    21    SET5_AXI_RD_ERR           0              
 *    20    SET5_COMPLETE             0              
 *    19    SET4_OVERWRITE_ERR        0              
 *    18    SET4_AXI_WR_ERR           0              
 *    17    SET4_AXI_RD_ERR           0              
 *    16    SET4_COMPLETE             0              
 *    15    SET3_OVERWRITE_ERR        0              
 *    14    SET3_AXI_WR_ERR           0              
 *    13    SET3_AXI_RD_ERR           0              
 *    12    SET3_COMPLETE             0              
 *    11    SET2_OVERWRITE_ERR        0              
 *    10    SET2_AXI_WR_ERR           0              
 *    09    SET2_AXI_RD_ERR           0              
 *    08    SET2_COMPLETE             0              
 *    07    SET1_OVERWRITE_ERR        0              
 *    06    SET1_AXI_WR_ERR           0              
 *    05    SET1_AXI_RD_ERR           0              
 *    04    SET1_COMPLETE             0              
 *    03    SET0_OVERWRITE_ERR        0              
 *    02    SET0_AXI_WR_ERR           0              
 *    01    SET0_AXI_RD_ERR           0              
 *    00    SET0_COMPLETE             0              
 * </pre>
 */
#define IDMA_IDMA_INT_RAW_STAT_ADDR        (REG_IDMA_BASE_ADDR+0x00000008)
#define IDMA_IDMA_INT_RAW_STAT_OFFSET      0x00000008
#define IDMA_IDMA_INT_RAW_STAT_INDEX       0x00000002
#define IDMA_IDMA_INT_RAW_STAT_RESET       0x00000000

__INLINE uint32_t  idma_idma_int_raw_stat_get(void)
{
	return REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
}

// field definitions
#define IDMA_IDMA_INT_RAW_STAT_SET_5_OVERWRITE_ERR_BIT    ((uint32_t)0x00800000)
#define IDMA_IDMA_INT_RAW_STAT_SET_5_OVERWRITE_ERR_POS    23
#define IDMA_IDMA_INT_RAW_STAT_SET_5_AXI_WR_ERR_BIT    ((uint32_t)0x00400000)
#define IDMA_IDMA_INT_RAW_STAT_SET_5_AXI_WR_ERR_POS    22
#define IDMA_IDMA_INT_RAW_STAT_SET_5_AXI_RD_ERR_BIT    ((uint32_t)0x00200000)
#define IDMA_IDMA_INT_RAW_STAT_SET_5_AXI_RD_ERR_POS    21
#define IDMA_IDMA_INT_RAW_STAT_SET_5_COMPLETE_BIT    ((uint32_t)0x00100000)
#define IDMA_IDMA_INT_RAW_STAT_SET_5_COMPLETE_POS    20
#define IDMA_IDMA_INT_RAW_STAT_SET_4_OVERWRITE_ERR_BIT    ((uint32_t)0x00080000)
#define IDMA_IDMA_INT_RAW_STAT_SET_4_OVERWRITE_ERR_POS    19
#define IDMA_IDMA_INT_RAW_STAT_SET_4_AXI_WR_ERR_BIT    ((uint32_t)0x00040000)
#define IDMA_IDMA_INT_RAW_STAT_SET_4_AXI_WR_ERR_POS    18
#define IDMA_IDMA_INT_RAW_STAT_SET_4_AXI_RD_ERR_BIT    ((uint32_t)0x00020000)
#define IDMA_IDMA_INT_RAW_STAT_SET_4_AXI_RD_ERR_POS    17
#define IDMA_IDMA_INT_RAW_STAT_SET_4_COMPLETE_BIT    ((uint32_t)0x00010000)
#define IDMA_IDMA_INT_RAW_STAT_SET_4_COMPLETE_POS    16
#define IDMA_IDMA_INT_RAW_STAT_SET_3_OVERWRITE_ERR_BIT    ((uint32_t)0x00008000)
#define IDMA_IDMA_INT_RAW_STAT_SET_3_OVERWRITE_ERR_POS    15
#define IDMA_IDMA_INT_RAW_STAT_SET_3_AXI_WR_ERR_BIT    ((uint32_t)0x00004000)
#define IDMA_IDMA_INT_RAW_STAT_SET_3_AXI_WR_ERR_POS    14
#define IDMA_IDMA_INT_RAW_STAT_SET_3_AXI_RD_ERR_BIT    ((uint32_t)0x00002000)
#define IDMA_IDMA_INT_RAW_STAT_SET_3_AXI_RD_ERR_POS    13
#define IDMA_IDMA_INT_RAW_STAT_SET_3_COMPLETE_BIT    ((uint32_t)0x00001000)
#define IDMA_IDMA_INT_RAW_STAT_SET_3_COMPLETE_POS    12
#define IDMA_IDMA_INT_RAW_STAT_SET_2_OVERWRITE_ERR_BIT    ((uint32_t)0x00000800)
#define IDMA_IDMA_INT_RAW_STAT_SET_2_OVERWRITE_ERR_POS    11
#define IDMA_IDMA_INT_RAW_STAT_SET_2_AXI_WR_ERR_BIT    ((uint32_t)0x00000400)
#define IDMA_IDMA_INT_RAW_STAT_SET_2_AXI_WR_ERR_POS    10
#define IDMA_IDMA_INT_RAW_STAT_SET_2_AXI_RD_ERR_BIT    ((uint32_t)0x00000200)
#define IDMA_IDMA_INT_RAW_STAT_SET_2_AXI_RD_ERR_POS    9
#define IDMA_IDMA_INT_RAW_STAT_SET_2_COMPLETE_BIT    ((uint32_t)0x00000100)
#define IDMA_IDMA_INT_RAW_STAT_SET_2_COMPLETE_POS    8
#define IDMA_IDMA_INT_RAW_STAT_SET_1_OVERWRITE_ERR_BIT    ((uint32_t)0x00000080)
#define IDMA_IDMA_INT_RAW_STAT_SET_1_OVERWRITE_ERR_POS    7
#define IDMA_IDMA_INT_RAW_STAT_SET_1_AXI_WR_ERR_BIT    ((uint32_t)0x00000040)
#define IDMA_IDMA_INT_RAW_STAT_SET_1_AXI_WR_ERR_POS    6
#define IDMA_IDMA_INT_RAW_STAT_SET_1_AXI_RD_ERR_BIT    ((uint32_t)0x00000020)
#define IDMA_IDMA_INT_RAW_STAT_SET_1_AXI_RD_ERR_POS    5
#define IDMA_IDMA_INT_RAW_STAT_SET_1_COMPLETE_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_INT_RAW_STAT_SET_1_COMPLETE_POS    4
#define IDMA_IDMA_INT_RAW_STAT_SET_0_OVERWRITE_ERR_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_INT_RAW_STAT_SET_0_OVERWRITE_ERR_POS    3
#define IDMA_IDMA_INT_RAW_STAT_SET_0_AXI_WR_ERR_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_INT_RAW_STAT_SET_0_AXI_WR_ERR_POS    2
#define IDMA_IDMA_INT_RAW_STAT_SET_0_AXI_RD_ERR_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_INT_RAW_STAT_SET_0_AXI_RD_ERR_POS    1
#define IDMA_IDMA_INT_RAW_STAT_SET_0_COMPLETE_BIT    ((uint32_t)0x00000001)
#define IDMA_IDMA_INT_RAW_STAT_SET_0_COMPLETE_POS    0

#define IDMA_IDMA_INT_RAW_STAT_SET_5_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_5_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_5_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_5_COMPLETE_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_4_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_4_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_4_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_4_COMPLETE_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_3_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_3_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_3_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_3_COMPLETE_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_2_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_2_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_2_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_2_COMPLETE_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_1_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_1_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_1_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_1_COMPLETE_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_0_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_0_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_0_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_INT_RAW_STAT_SET_0_COMPLETE_RST    0x0

__INLINE void idma_idma_int_raw_stat_unpack(uint8_t* set5_overwrite_err, uint8_t* set5_axi_wr_err, uint8_t* set5_axi_rd_err, uint8_t* set5_complete, uint8_t* set4_overwrite_err, uint8_t* set4_axi_wr_err, uint8_t* set4_axi_rd_err, uint8_t* set4_complete, uint8_t* set3_overwrite_err, uint8_t* set3_axi_wr_err, uint8_t* set3_axi_rd_err, uint8_t* set3_complete, uint8_t* set2_overwrite_err, uint8_t* set2_axi_wr_err, uint8_t* set2_axi_rd_err, uint8_t* set2_complete, uint8_t* set1_overwrite_err, uint8_t* set1_axi_wr_err, uint8_t* set1_axi_rd_err, uint8_t* set1_complete, uint8_t* set0_overwrite_err, uint8_t* set0_axi_wr_err, uint8_t* set0_axi_rd_err, uint8_t* set0_complete)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);

	*set5_overwrite_err = (localVal & ((uint32_t)0x00800000)) >>  23;
	*set5_axi_wr_err = (localVal & ((uint32_t)0x00400000)) >>  22;
	*set5_axi_rd_err = (localVal & ((uint32_t)0x00200000)) >>  21;
	*set5_complete = (localVal & ((uint32_t)0x00100000)) >>  20;
	*set4_overwrite_err = (localVal & ((uint32_t)0x00080000)) >>  19;
	*set4_axi_wr_err = (localVal & ((uint32_t)0x00040000)) >>  18;
	*set4_axi_rd_err = (localVal & ((uint32_t)0x00020000)) >>  17;
	*set4_complete = (localVal & ((uint32_t)0x00010000)) >>  16;
	*set3_overwrite_err = (localVal & ((uint32_t)0x00008000)) >>  15;
	*set3_axi_wr_err = (localVal & ((uint32_t)0x00004000)) >>  14;
	*set3_axi_rd_err = (localVal & ((uint32_t)0x00002000)) >>  13;
	*set3_complete = (localVal & ((uint32_t)0x00001000)) >>  12;
	*set2_overwrite_err = (localVal & ((uint32_t)0x00000800)) >>  11;
	*set2_axi_wr_err = (localVal & ((uint32_t)0x00000400)) >>  10;
	*set2_axi_rd_err = (localVal & ((uint32_t)0x00000200)) >>  9;
	*set2_complete = (localVal & ((uint32_t)0x00000100)) >>  8;
	*set1_overwrite_err = (localVal & ((uint32_t)0x00000080)) >>  7;
	*set1_axi_wr_err = (localVal & ((uint32_t)0x00000040)) >>  6;
	*set1_axi_rd_err = (localVal & ((uint32_t)0x00000020)) >>  5;
	*set1_complete = (localVal & ((uint32_t)0x00000010)) >>  4;
	*set0_overwrite_err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*set0_axi_wr_err = (localVal & ((uint32_t)0x00000004)) >>  2;
	*set0_axi_rd_err = (localVal & ((uint32_t)0x00000002)) >>  1;
	*set0_complete = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_int_raw_stat_set_5_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_5_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_5_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_5_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_4_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_4_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_4_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_4_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_3_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_3_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_3_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_3_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_2_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_2_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_2_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_2_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_1_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_1_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_1_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_1_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_0_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_0_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_0_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t idma_idma_int_raw_stat_set_0_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_INT_RAW_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief IDMA_UMAC_INT_EN register definition
 *  Interrupt enable for UMAC register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23    SET5_OVERWRITE_ERR_EN     0              
 *    22    SET5_AXI_WR_ERR_EN        0              
 *    21    SET5_AXI_RD_ERR_EN        0              
 *    20    SET5_COMPLETE_EN          0              
 *    19    SET4_OVERWRITE_ERR_EN     0              
 *    18    SET4_AXI_WR_ERR_EN        0              
 *    17    SET4_AXI_RD_ERR_EN        0              
 *    16    SET4_COMPLETE_EN          0              
 *    15    SET3_OVERWRITE_ERR_EN     0              
 *    14    SET3_AXI_WR_ERR_EN        0              
 *    13    SET3_AXI_RD_ERR_EN        0              
 *    12    SET3_COMPLETE_EN          0              
 *    11    SET2_OVERWRITE_ERR_EN     0              
 *    10    SET2_AXI_WR_ERR_EN        0              
 *    09    SET2_AXI_RD_ERR_EN        0              
 *    08    SET2_COMPLETE_EN          0              
 *    07    SET1_OVERWRITE_ERR_EN     0              
 *    06    SET1_AXI_WR_ERR_EN        0              
 *    05    SET1_AXI_RD_ERR_EN        0              
 *    04    SET1_COMPLETE_EN          0              
 *    03    SET0_OVERWRITE_ERR_EN     0              
 *    02    SET0_AXI_WR_ERR_EN        0              
 *    01    SET0_AXI_RD_ERR_EN        0              
 *    00    SET0_COMPLETE_EN          0              
 * </pre>
 */
#define IDMA_IDMA_UMAC_INT_EN_ADDR        (REG_IDMA_BASE_ADDR+0x0000000C)
#define IDMA_IDMA_UMAC_INT_EN_OFFSET      0x0000000C
#define IDMA_IDMA_UMAC_INT_EN_INDEX       0x00000003
#define IDMA_IDMA_UMAC_INT_EN_RESET       0x00000000

__INLINE uint32_t  idma_idma_umac_int_en_get(void)
{
	return REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
}

__INLINE void idma_idma_umac_int_en_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, value);
}

// field definitions
#define IDMA_IDMA_UMAC_INT_EN_SET_5_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00800000)
#define IDMA_IDMA_UMAC_INT_EN_SET_5_OVERWRITE_ERR_EN_POS    23
#define IDMA_IDMA_UMAC_INT_EN_SET_5_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00400000)
#define IDMA_IDMA_UMAC_INT_EN_SET_5_AXI_WR_ERR_EN_POS    22
#define IDMA_IDMA_UMAC_INT_EN_SET_5_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00200000)
#define IDMA_IDMA_UMAC_INT_EN_SET_5_AXI_RD_ERR_EN_POS    21
#define IDMA_IDMA_UMAC_INT_EN_SET_5_COMPLETE_EN_BIT    ((uint32_t)0x00100000)
#define IDMA_IDMA_UMAC_INT_EN_SET_5_COMPLETE_EN_POS    20
#define IDMA_IDMA_UMAC_INT_EN_SET_4_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00080000)
#define IDMA_IDMA_UMAC_INT_EN_SET_4_OVERWRITE_ERR_EN_POS    19
#define IDMA_IDMA_UMAC_INT_EN_SET_4_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00040000)
#define IDMA_IDMA_UMAC_INT_EN_SET_4_AXI_WR_ERR_EN_POS    18
#define IDMA_IDMA_UMAC_INT_EN_SET_4_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00020000)
#define IDMA_IDMA_UMAC_INT_EN_SET_4_AXI_RD_ERR_EN_POS    17
#define IDMA_IDMA_UMAC_INT_EN_SET_4_COMPLETE_EN_BIT    ((uint32_t)0x00010000)
#define IDMA_IDMA_UMAC_INT_EN_SET_4_COMPLETE_EN_POS    16
#define IDMA_IDMA_UMAC_INT_EN_SET_3_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00008000)
#define IDMA_IDMA_UMAC_INT_EN_SET_3_OVERWRITE_ERR_EN_POS    15
#define IDMA_IDMA_UMAC_INT_EN_SET_3_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00004000)
#define IDMA_IDMA_UMAC_INT_EN_SET_3_AXI_WR_ERR_EN_POS    14
#define IDMA_IDMA_UMAC_INT_EN_SET_3_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00002000)
#define IDMA_IDMA_UMAC_INT_EN_SET_3_AXI_RD_ERR_EN_POS    13
#define IDMA_IDMA_UMAC_INT_EN_SET_3_COMPLETE_EN_BIT    ((uint32_t)0x00001000)
#define IDMA_IDMA_UMAC_INT_EN_SET_3_COMPLETE_EN_POS    12
#define IDMA_IDMA_UMAC_INT_EN_SET_2_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00000800)
#define IDMA_IDMA_UMAC_INT_EN_SET_2_OVERWRITE_ERR_EN_POS    11
#define IDMA_IDMA_UMAC_INT_EN_SET_2_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00000400)
#define IDMA_IDMA_UMAC_INT_EN_SET_2_AXI_WR_ERR_EN_POS    10
#define IDMA_IDMA_UMAC_INT_EN_SET_2_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00000200)
#define IDMA_IDMA_UMAC_INT_EN_SET_2_AXI_RD_ERR_EN_POS    9
#define IDMA_IDMA_UMAC_INT_EN_SET_2_COMPLETE_EN_BIT    ((uint32_t)0x00000100)
#define IDMA_IDMA_UMAC_INT_EN_SET_2_COMPLETE_EN_POS    8
#define IDMA_IDMA_UMAC_INT_EN_SET_1_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00000080)
#define IDMA_IDMA_UMAC_INT_EN_SET_1_OVERWRITE_ERR_EN_POS    7
#define IDMA_IDMA_UMAC_INT_EN_SET_1_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00000040)
#define IDMA_IDMA_UMAC_INT_EN_SET_1_AXI_WR_ERR_EN_POS    6
#define IDMA_IDMA_UMAC_INT_EN_SET_1_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00000020)
#define IDMA_IDMA_UMAC_INT_EN_SET_1_AXI_RD_ERR_EN_POS    5
#define IDMA_IDMA_UMAC_INT_EN_SET_1_COMPLETE_EN_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_UMAC_INT_EN_SET_1_COMPLETE_EN_POS    4
#define IDMA_IDMA_UMAC_INT_EN_SET_0_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_UMAC_INT_EN_SET_0_OVERWRITE_ERR_EN_POS    3
#define IDMA_IDMA_UMAC_INT_EN_SET_0_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_UMAC_INT_EN_SET_0_AXI_WR_ERR_EN_POS    2
#define IDMA_IDMA_UMAC_INT_EN_SET_0_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_UMAC_INT_EN_SET_0_AXI_RD_ERR_EN_POS    1
#define IDMA_IDMA_UMAC_INT_EN_SET_0_COMPLETE_EN_BIT    ((uint32_t)0x00000001)
#define IDMA_IDMA_UMAC_INT_EN_SET_0_COMPLETE_EN_POS    0

#define IDMA_IDMA_UMAC_INT_EN_SET_5_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_5_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_5_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_5_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_4_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_4_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_4_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_4_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_3_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_3_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_3_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_3_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_2_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_2_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_2_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_2_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_1_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_1_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_1_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_1_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_0_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_0_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_0_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_UMAC_INT_EN_SET_0_COMPLETE_EN_RST    0x0

__INLINE void idma_idma_umac_int_en_pack(uint8_t set5_overwrite_err_en, uint8_t set5_axi_wr_err_en, uint8_t set5_axi_rd_err_en, uint8_t set5_complete_en, uint8_t set4_overwrite_err_en, uint8_t set4_axi_wr_err_en, uint8_t set4_axi_rd_err_en, uint8_t set4_complete_en, uint8_t set3_overwrite_err_en, uint8_t set3_axi_wr_err_en, uint8_t set3_axi_rd_err_en, uint8_t set3_complete_en, uint8_t set2_overwrite_err_en, uint8_t set2_axi_wr_err_en, uint8_t set2_axi_rd_err_en, uint8_t set2_complete_en, uint8_t set1_overwrite_err_en, uint8_t set1_axi_wr_err_en, uint8_t set1_axi_rd_err_en, uint8_t set1_complete_en, uint8_t set0_overwrite_err_en, uint8_t set0_axi_wr_err_en, uint8_t set0_axi_rd_err_en, uint8_t set0_complete_en)
{
	ASSERT_ERR((((uint32_t)set5_overwrite_err_en << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)set5_axi_wr_err_en << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)set5_axi_rd_err_en << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)set5_complete_en << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)set4_overwrite_err_en << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)set4_axi_wr_err_en << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)set4_axi_rd_err_en << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)set4_complete_en << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)set3_overwrite_err_en << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)set3_axi_wr_err_en << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)set3_axi_rd_err_en << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)set3_complete_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)set2_overwrite_err_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)set2_axi_wr_err_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)set2_axi_rd_err_en << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)set2_complete_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)set1_overwrite_err_en << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)set1_axi_wr_err_en << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)set1_axi_rd_err_en << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)set1_complete_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)set0_overwrite_err_en << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)set0_axi_wr_err_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)set0_axi_rd_err_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)set0_complete_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR,  ((uint32_t)set5_overwrite_err_en << 23) |((uint32_t)set5_axi_wr_err_en << 22) |((uint32_t)set5_axi_rd_err_en << 21) |((uint32_t)set5_complete_en << 20) |((uint32_t)set4_overwrite_err_en << 19) |((uint32_t)set4_axi_wr_err_en << 18) |((uint32_t)set4_axi_rd_err_en << 17) |((uint32_t)set4_complete_en << 16) |((uint32_t)set3_overwrite_err_en << 15) |((uint32_t)set3_axi_wr_err_en << 14) |((uint32_t)set3_axi_rd_err_en << 13) |((uint32_t)set3_complete_en << 12) |((uint32_t)set2_overwrite_err_en << 11) |((uint32_t)set2_axi_wr_err_en << 10) |((uint32_t)set2_axi_rd_err_en << 9) |((uint32_t)set2_complete_en << 8) |((uint32_t)set1_overwrite_err_en << 7) |((uint32_t)set1_axi_wr_err_en << 6) |((uint32_t)set1_axi_rd_err_en << 5) |((uint32_t)set1_complete_en << 4) |((uint32_t)set0_overwrite_err_en << 3) |((uint32_t)set0_axi_wr_err_en << 2) |((uint32_t)set0_axi_rd_err_en << 1) |((uint32_t)set0_complete_en << 0));
}

__INLINE void idma_idma_umac_int_en_unpack(uint8_t* set5_overwrite_err_en, uint8_t* set5_axi_wr_err_en, uint8_t* set5_axi_rd_err_en, uint8_t* set5_complete_en, uint8_t* set4_overwrite_err_en, uint8_t* set4_axi_wr_err_en, uint8_t* set4_axi_rd_err_en, uint8_t* set4_complete_en, uint8_t* set3_overwrite_err_en, uint8_t* set3_axi_wr_err_en, uint8_t* set3_axi_rd_err_en, uint8_t* set3_complete_en, uint8_t* set2_overwrite_err_en, uint8_t* set2_axi_wr_err_en, uint8_t* set2_axi_rd_err_en, uint8_t* set2_complete_en, uint8_t* set1_overwrite_err_en, uint8_t* set1_axi_wr_err_en, uint8_t* set1_axi_rd_err_en, uint8_t* set1_complete_en, uint8_t* set0_overwrite_err_en, uint8_t* set0_axi_wr_err_en, uint8_t* set0_axi_rd_err_en, uint8_t* set0_complete_en)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);

	*set5_overwrite_err_en = (localVal & ((uint32_t)0x00800000)) >>  23;
	*set5_axi_wr_err_en = (localVal & ((uint32_t)0x00400000)) >>  22;
	*set5_axi_rd_err_en = (localVal & ((uint32_t)0x00200000)) >>  21;
	*set5_complete_en = (localVal & ((uint32_t)0x00100000)) >>  20;
	*set4_overwrite_err_en = (localVal & ((uint32_t)0x00080000)) >>  19;
	*set4_axi_wr_err_en = (localVal & ((uint32_t)0x00040000)) >>  18;
	*set4_axi_rd_err_en = (localVal & ((uint32_t)0x00020000)) >>  17;
	*set4_complete_en = (localVal & ((uint32_t)0x00010000)) >>  16;
	*set3_overwrite_err_en = (localVal & ((uint32_t)0x00008000)) >>  15;
	*set3_axi_wr_err_en = (localVal & ((uint32_t)0x00004000)) >>  14;
	*set3_axi_rd_err_en = (localVal & ((uint32_t)0x00002000)) >>  13;
	*set3_complete_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*set2_overwrite_err_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*set2_axi_wr_err_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*set2_axi_rd_err_en = (localVal & ((uint32_t)0x00000200)) >>  9;
	*set2_complete_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*set1_overwrite_err_en = (localVal & ((uint32_t)0x00000080)) >>  7;
	*set1_axi_wr_err_en = (localVal & ((uint32_t)0x00000040)) >>  6;
	*set1_axi_rd_err_en = (localVal & ((uint32_t)0x00000020)) >>  5;
	*set1_complete_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*set0_overwrite_err_en = (localVal & ((uint32_t)0x00000008)) >>  3;
	*set0_axi_wr_err_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*set0_axi_rd_err_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*set0_complete_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_umac_int_en_set_5_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void idma_idma_umac_int_en_set_5_overwrite_err_en_setf(uint8_t set5overwriteerren)
{
	ASSERT_ERR((((uint32_t)set5overwriteerren << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)set5overwriteerren <<23));
}
__INLINE uint8_t idma_idma_umac_int_en_set_5_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void idma_idma_umac_int_en_set_5_axi_wr_err_en_setf(uint8_t set5axiwrerren)
{
	ASSERT_ERR((((uint32_t)set5axiwrerren << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)set5axiwrerren <<22));
}
__INLINE uint8_t idma_idma_umac_int_en_set_5_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void idma_idma_umac_int_en_set_5_axi_rd_err_en_setf(uint8_t set5axirderren)
{
	ASSERT_ERR((((uint32_t)set5axirderren << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)set5axirderren <<21));
}
__INLINE uint8_t idma_idma_umac_int_en_set_5_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void idma_idma_umac_int_en_set_5_complete_en_setf(uint8_t set5completeen)
{
	ASSERT_ERR((((uint32_t)set5completeen << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)set5completeen <<20));
}
__INLINE uint8_t idma_idma_umac_int_en_set_4_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void idma_idma_umac_int_en_set_4_overwrite_err_en_setf(uint8_t set4overwriteerren)
{
	ASSERT_ERR((((uint32_t)set4overwriteerren << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)set4overwriteerren <<19));
}
__INLINE uint8_t idma_idma_umac_int_en_set_4_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void idma_idma_umac_int_en_set_4_axi_wr_err_en_setf(uint8_t set4axiwrerren)
{
	ASSERT_ERR((((uint32_t)set4axiwrerren << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)set4axiwrerren <<18));
}
__INLINE uint8_t idma_idma_umac_int_en_set_4_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void idma_idma_umac_int_en_set_4_axi_rd_err_en_setf(uint8_t set4axirderren)
{
	ASSERT_ERR((((uint32_t)set4axirderren << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)set4axirderren <<17));
}
__INLINE uint8_t idma_idma_umac_int_en_set_4_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void idma_idma_umac_int_en_set_4_complete_en_setf(uint8_t set4completeen)
{
	ASSERT_ERR((((uint32_t)set4completeen << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)set4completeen <<16));
}
__INLINE uint8_t idma_idma_umac_int_en_set_3_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void idma_idma_umac_int_en_set_3_overwrite_err_en_setf(uint8_t set3overwriteerren)
{
	ASSERT_ERR((((uint32_t)set3overwriteerren << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)set3overwriteerren <<15));
}
__INLINE uint8_t idma_idma_umac_int_en_set_3_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void idma_idma_umac_int_en_set_3_axi_wr_err_en_setf(uint8_t set3axiwrerren)
{
	ASSERT_ERR((((uint32_t)set3axiwrerren << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)set3axiwrerren <<14));
}
__INLINE uint8_t idma_idma_umac_int_en_set_3_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void idma_idma_umac_int_en_set_3_axi_rd_err_en_setf(uint8_t set3axirderren)
{
	ASSERT_ERR((((uint32_t)set3axirderren << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)set3axirderren <<13));
}
__INLINE uint8_t idma_idma_umac_int_en_set_3_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void idma_idma_umac_int_en_set_3_complete_en_setf(uint8_t set3completeen)
{
	ASSERT_ERR((((uint32_t)set3completeen << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)set3completeen <<12));
}
__INLINE uint8_t idma_idma_umac_int_en_set_2_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void idma_idma_umac_int_en_set_2_overwrite_err_en_setf(uint8_t set2overwriteerren)
{
	ASSERT_ERR((((uint32_t)set2overwriteerren << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)set2overwriteerren <<11));
}
__INLINE uint8_t idma_idma_umac_int_en_set_2_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void idma_idma_umac_int_en_set_2_axi_wr_err_en_setf(uint8_t set2axiwrerren)
{
	ASSERT_ERR((((uint32_t)set2axiwrerren << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)set2axiwrerren <<10));
}
__INLINE uint8_t idma_idma_umac_int_en_set_2_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void idma_idma_umac_int_en_set_2_axi_rd_err_en_setf(uint8_t set2axirderren)
{
	ASSERT_ERR((((uint32_t)set2axirderren << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)set2axirderren <<9));
}
__INLINE uint8_t idma_idma_umac_int_en_set_2_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void idma_idma_umac_int_en_set_2_complete_en_setf(uint8_t set2completeen)
{
	ASSERT_ERR((((uint32_t)set2completeen << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)set2completeen <<8));
}
__INLINE uint8_t idma_idma_umac_int_en_set_1_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void idma_idma_umac_int_en_set_1_overwrite_err_en_setf(uint8_t set1overwriteerren)
{
	ASSERT_ERR((((uint32_t)set1overwriteerren << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)set1overwriteerren <<7));
}
__INLINE uint8_t idma_idma_umac_int_en_set_1_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void idma_idma_umac_int_en_set_1_axi_wr_err_en_setf(uint8_t set1axiwrerren)
{
	ASSERT_ERR((((uint32_t)set1axiwrerren << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)set1axiwrerren <<6));
}
__INLINE uint8_t idma_idma_umac_int_en_set_1_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void idma_idma_umac_int_en_set_1_axi_rd_err_en_setf(uint8_t set1axirderren)
{
	ASSERT_ERR((((uint32_t)set1axirderren << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)set1axirderren <<5));
}
__INLINE uint8_t idma_idma_umac_int_en_set_1_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void idma_idma_umac_int_en_set_1_complete_en_setf(uint8_t set1completeen)
{
	ASSERT_ERR((((uint32_t)set1completeen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)set1completeen <<4));
}
__INLINE uint8_t idma_idma_umac_int_en_set_0_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void idma_idma_umac_int_en_set_0_overwrite_err_en_setf(uint8_t set0overwriteerren)
{
	ASSERT_ERR((((uint32_t)set0overwriteerren << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)set0overwriteerren <<3));
}
__INLINE uint8_t idma_idma_umac_int_en_set_0_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void idma_idma_umac_int_en_set_0_axi_wr_err_en_setf(uint8_t set0axiwrerren)
{
	ASSERT_ERR((((uint32_t)set0axiwrerren << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)set0axiwrerren <<2));
}
__INLINE uint8_t idma_idma_umac_int_en_set_0_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void idma_idma_umac_int_en_set_0_axi_rd_err_en_setf(uint8_t set0axirderren)
{
	ASSERT_ERR((((uint32_t)set0axirderren << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)set0axirderren <<1));
}
__INLINE uint8_t idma_idma_umac_int_en_set_0_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void idma_idma_umac_int_en_set_0_complete_en_setf(uint8_t set0completeen)
{
	ASSERT_ERR((((uint32_t)set0completeen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IDMA_IDMA_UMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_UMAC_INT_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)set0completeen <<0));
}

/**
 * @brief IDMA_LMAC_INT_EN register definition
 *  Interrupt enable for LMAC register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23    SET5_OVERWRITE_ERR_EN     0              
 *    22    SET5_AXI_WR_ERR_EN        0              
 *    21    SET5_AXI_RD_ERR_EN        0              
 *    20    SET5_COMPLETE_EN          0              
 *    19    SET4_OVERWRITE_ERR_EN     0              
 *    18    SET4_AXI_WR_ERR_EN        0              
 *    17    SET4_AXI_RD_ERR_EN        0              
 *    16    SET4_COMPLETE_EN          0              
 *    15    SET3_OVERWRITE_ERR_EN     0              
 *    14    SET3_AXI_WR_ERR_EN        0              
 *    13    SET3_AXI_RD_ERR_EN        0              
 *    12    SET3_COMPLETE_EN          0              
 *    11    SET2_OVERWRITE_ERR_EN     0              
 *    10    SET2_AXI_WR_ERR_EN        0              
 *    09    SET2_AXI_RD_ERR_EN        0              
 *    08    SET2_COMPLETE_EN          0              
 *    07    SET1_OVERWRITE_ERR_EN     0              
 *    06    SET1_AXI_WR_ERR_EN        0              
 *    05    SET1_AXI_RD_ERR_EN        0              
 *    04    SET1_COMPLETE_EN          0              
 *    03    SET0_OVERWRITE_ERR_EN     0              
 *    02    SET0_AXI_WR_ERR_EN        0              
 *    01    SET0_AXI_RD_ERR_EN        0              
 *    00    SET0_COMPLETE_EN          0              
 * </pre>
 */
#define IDMA_IDMA_LMAC_INT_EN_ADDR        (REG_IDMA_BASE_ADDR+0x00000010)
#define IDMA_IDMA_LMAC_INT_EN_OFFSET      0x00000010
#define IDMA_IDMA_LMAC_INT_EN_INDEX       0x00000004
#define IDMA_IDMA_LMAC_INT_EN_RESET       0x00000000

__INLINE uint32_t  idma_idma_lmac_int_en_get(void)
{
	return REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
}

__INLINE void idma_idma_lmac_int_en_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, value);
}

// field definitions
#define IDMA_IDMA_LMAC_INT_EN_SET_5_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00800000)
#define IDMA_IDMA_LMAC_INT_EN_SET_5_OVERWRITE_ERR_EN_POS    23
#define IDMA_IDMA_LMAC_INT_EN_SET_5_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00400000)
#define IDMA_IDMA_LMAC_INT_EN_SET_5_AXI_WR_ERR_EN_POS    22
#define IDMA_IDMA_LMAC_INT_EN_SET_5_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00200000)
#define IDMA_IDMA_LMAC_INT_EN_SET_5_AXI_RD_ERR_EN_POS    21
#define IDMA_IDMA_LMAC_INT_EN_SET_5_COMPLETE_EN_BIT    ((uint32_t)0x00100000)
#define IDMA_IDMA_LMAC_INT_EN_SET_5_COMPLETE_EN_POS    20
#define IDMA_IDMA_LMAC_INT_EN_SET_4_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00080000)
#define IDMA_IDMA_LMAC_INT_EN_SET_4_OVERWRITE_ERR_EN_POS    19
#define IDMA_IDMA_LMAC_INT_EN_SET_4_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00040000)
#define IDMA_IDMA_LMAC_INT_EN_SET_4_AXI_WR_ERR_EN_POS    18
#define IDMA_IDMA_LMAC_INT_EN_SET_4_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00020000)
#define IDMA_IDMA_LMAC_INT_EN_SET_4_AXI_RD_ERR_EN_POS    17
#define IDMA_IDMA_LMAC_INT_EN_SET_4_COMPLETE_EN_BIT    ((uint32_t)0x00010000)
#define IDMA_IDMA_LMAC_INT_EN_SET_4_COMPLETE_EN_POS    16
#define IDMA_IDMA_LMAC_INT_EN_SET_3_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00008000)
#define IDMA_IDMA_LMAC_INT_EN_SET_3_OVERWRITE_ERR_EN_POS    15
#define IDMA_IDMA_LMAC_INT_EN_SET_3_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00004000)
#define IDMA_IDMA_LMAC_INT_EN_SET_3_AXI_WR_ERR_EN_POS    14
#define IDMA_IDMA_LMAC_INT_EN_SET_3_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00002000)
#define IDMA_IDMA_LMAC_INT_EN_SET_3_AXI_RD_ERR_EN_POS    13
#define IDMA_IDMA_LMAC_INT_EN_SET_3_COMPLETE_EN_BIT    ((uint32_t)0x00001000)
#define IDMA_IDMA_LMAC_INT_EN_SET_3_COMPLETE_EN_POS    12
#define IDMA_IDMA_LMAC_INT_EN_SET_2_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00000800)
#define IDMA_IDMA_LMAC_INT_EN_SET_2_OVERWRITE_ERR_EN_POS    11
#define IDMA_IDMA_LMAC_INT_EN_SET_2_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00000400)
#define IDMA_IDMA_LMAC_INT_EN_SET_2_AXI_WR_ERR_EN_POS    10
#define IDMA_IDMA_LMAC_INT_EN_SET_2_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00000200)
#define IDMA_IDMA_LMAC_INT_EN_SET_2_AXI_RD_ERR_EN_POS    9
#define IDMA_IDMA_LMAC_INT_EN_SET_2_COMPLETE_EN_BIT    ((uint32_t)0x00000100)
#define IDMA_IDMA_LMAC_INT_EN_SET_2_COMPLETE_EN_POS    8
#define IDMA_IDMA_LMAC_INT_EN_SET_1_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00000080)
#define IDMA_IDMA_LMAC_INT_EN_SET_1_OVERWRITE_ERR_EN_POS    7
#define IDMA_IDMA_LMAC_INT_EN_SET_1_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00000040)
#define IDMA_IDMA_LMAC_INT_EN_SET_1_AXI_WR_ERR_EN_POS    6
#define IDMA_IDMA_LMAC_INT_EN_SET_1_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00000020)
#define IDMA_IDMA_LMAC_INT_EN_SET_1_AXI_RD_ERR_EN_POS    5
#define IDMA_IDMA_LMAC_INT_EN_SET_1_COMPLETE_EN_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_LMAC_INT_EN_SET_1_COMPLETE_EN_POS    4
#define IDMA_IDMA_LMAC_INT_EN_SET_0_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_LMAC_INT_EN_SET_0_OVERWRITE_ERR_EN_POS    3
#define IDMA_IDMA_LMAC_INT_EN_SET_0_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_LMAC_INT_EN_SET_0_AXI_WR_ERR_EN_POS    2
#define IDMA_IDMA_LMAC_INT_EN_SET_0_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_LMAC_INT_EN_SET_0_AXI_RD_ERR_EN_POS    1
#define IDMA_IDMA_LMAC_INT_EN_SET_0_COMPLETE_EN_BIT    ((uint32_t)0x00000001)
#define IDMA_IDMA_LMAC_INT_EN_SET_0_COMPLETE_EN_POS    0

#define IDMA_IDMA_LMAC_INT_EN_SET_5_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_5_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_5_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_5_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_4_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_4_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_4_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_4_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_3_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_3_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_3_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_3_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_2_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_2_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_2_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_2_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_1_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_1_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_1_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_1_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_0_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_0_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_0_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_LMAC_INT_EN_SET_0_COMPLETE_EN_RST    0x0

__INLINE void idma_idma_lmac_int_en_pack(uint8_t set5_overwrite_err_en, uint8_t set5_axi_wr_err_en, uint8_t set5_axi_rd_err_en, uint8_t set5_complete_en, uint8_t set4_overwrite_err_en, uint8_t set4_axi_wr_err_en, uint8_t set4_axi_rd_err_en, uint8_t set4_complete_en, uint8_t set3_overwrite_err_en, uint8_t set3_axi_wr_err_en, uint8_t set3_axi_rd_err_en, uint8_t set3_complete_en, uint8_t set2_overwrite_err_en, uint8_t set2_axi_wr_err_en, uint8_t set2_axi_rd_err_en, uint8_t set2_complete_en, uint8_t set1_overwrite_err_en, uint8_t set1_axi_wr_err_en, uint8_t set1_axi_rd_err_en, uint8_t set1_complete_en, uint8_t set0_overwrite_err_en, uint8_t set0_axi_wr_err_en, uint8_t set0_axi_rd_err_en, uint8_t set0_complete_en)
{
	ASSERT_ERR((((uint32_t)set5_overwrite_err_en << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)set5_axi_wr_err_en << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)set5_axi_rd_err_en << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)set5_complete_en << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)set4_overwrite_err_en << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)set4_axi_wr_err_en << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)set4_axi_rd_err_en << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)set4_complete_en << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)set3_overwrite_err_en << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)set3_axi_wr_err_en << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)set3_axi_rd_err_en << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)set3_complete_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)set2_overwrite_err_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)set2_axi_wr_err_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)set2_axi_rd_err_en << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)set2_complete_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)set1_overwrite_err_en << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)set1_axi_wr_err_en << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)set1_axi_rd_err_en << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)set1_complete_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)set0_overwrite_err_en << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)set0_axi_wr_err_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)set0_axi_rd_err_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)set0_complete_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR,  ((uint32_t)set5_overwrite_err_en << 23) |((uint32_t)set5_axi_wr_err_en << 22) |((uint32_t)set5_axi_rd_err_en << 21) |((uint32_t)set5_complete_en << 20) |((uint32_t)set4_overwrite_err_en << 19) |((uint32_t)set4_axi_wr_err_en << 18) |((uint32_t)set4_axi_rd_err_en << 17) |((uint32_t)set4_complete_en << 16) |((uint32_t)set3_overwrite_err_en << 15) |((uint32_t)set3_axi_wr_err_en << 14) |((uint32_t)set3_axi_rd_err_en << 13) |((uint32_t)set3_complete_en << 12) |((uint32_t)set2_overwrite_err_en << 11) |((uint32_t)set2_axi_wr_err_en << 10) |((uint32_t)set2_axi_rd_err_en << 9) |((uint32_t)set2_complete_en << 8) |((uint32_t)set1_overwrite_err_en << 7) |((uint32_t)set1_axi_wr_err_en << 6) |((uint32_t)set1_axi_rd_err_en << 5) |((uint32_t)set1_complete_en << 4) |((uint32_t)set0_overwrite_err_en << 3) |((uint32_t)set0_axi_wr_err_en << 2) |((uint32_t)set0_axi_rd_err_en << 1) |((uint32_t)set0_complete_en << 0));
}

__INLINE void idma_idma_lmac_int_en_unpack(uint8_t* set5_overwrite_err_en, uint8_t* set5_axi_wr_err_en, uint8_t* set5_axi_rd_err_en, uint8_t* set5_complete_en, uint8_t* set4_overwrite_err_en, uint8_t* set4_axi_wr_err_en, uint8_t* set4_axi_rd_err_en, uint8_t* set4_complete_en, uint8_t* set3_overwrite_err_en, uint8_t* set3_axi_wr_err_en, uint8_t* set3_axi_rd_err_en, uint8_t* set3_complete_en, uint8_t* set2_overwrite_err_en, uint8_t* set2_axi_wr_err_en, uint8_t* set2_axi_rd_err_en, uint8_t* set2_complete_en, uint8_t* set1_overwrite_err_en, uint8_t* set1_axi_wr_err_en, uint8_t* set1_axi_rd_err_en, uint8_t* set1_complete_en, uint8_t* set0_overwrite_err_en, uint8_t* set0_axi_wr_err_en, uint8_t* set0_axi_rd_err_en, uint8_t* set0_complete_en)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);

	*set5_overwrite_err_en = (localVal & ((uint32_t)0x00800000)) >>  23;
	*set5_axi_wr_err_en = (localVal & ((uint32_t)0x00400000)) >>  22;
	*set5_axi_rd_err_en = (localVal & ((uint32_t)0x00200000)) >>  21;
	*set5_complete_en = (localVal & ((uint32_t)0x00100000)) >>  20;
	*set4_overwrite_err_en = (localVal & ((uint32_t)0x00080000)) >>  19;
	*set4_axi_wr_err_en = (localVal & ((uint32_t)0x00040000)) >>  18;
	*set4_axi_rd_err_en = (localVal & ((uint32_t)0x00020000)) >>  17;
	*set4_complete_en = (localVal & ((uint32_t)0x00010000)) >>  16;
	*set3_overwrite_err_en = (localVal & ((uint32_t)0x00008000)) >>  15;
	*set3_axi_wr_err_en = (localVal & ((uint32_t)0x00004000)) >>  14;
	*set3_axi_rd_err_en = (localVal & ((uint32_t)0x00002000)) >>  13;
	*set3_complete_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*set2_overwrite_err_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*set2_axi_wr_err_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*set2_axi_rd_err_en = (localVal & ((uint32_t)0x00000200)) >>  9;
	*set2_complete_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*set1_overwrite_err_en = (localVal & ((uint32_t)0x00000080)) >>  7;
	*set1_axi_wr_err_en = (localVal & ((uint32_t)0x00000040)) >>  6;
	*set1_axi_rd_err_en = (localVal & ((uint32_t)0x00000020)) >>  5;
	*set1_complete_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*set0_overwrite_err_en = (localVal & ((uint32_t)0x00000008)) >>  3;
	*set0_axi_wr_err_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*set0_axi_rd_err_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*set0_complete_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_lmac_int_en_set_5_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void idma_idma_lmac_int_en_set_5_overwrite_err_en_setf(uint8_t set5overwriteerren)
{
	ASSERT_ERR((((uint32_t)set5overwriteerren << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)set5overwriteerren <<23));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_5_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void idma_idma_lmac_int_en_set_5_axi_wr_err_en_setf(uint8_t set5axiwrerren)
{
	ASSERT_ERR((((uint32_t)set5axiwrerren << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)set5axiwrerren <<22));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_5_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void idma_idma_lmac_int_en_set_5_axi_rd_err_en_setf(uint8_t set5axirderren)
{
	ASSERT_ERR((((uint32_t)set5axirderren << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)set5axirderren <<21));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_5_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void idma_idma_lmac_int_en_set_5_complete_en_setf(uint8_t set5completeen)
{
	ASSERT_ERR((((uint32_t)set5completeen << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)set5completeen <<20));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_4_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void idma_idma_lmac_int_en_set_4_overwrite_err_en_setf(uint8_t set4overwriteerren)
{
	ASSERT_ERR((((uint32_t)set4overwriteerren << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)set4overwriteerren <<19));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_4_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void idma_idma_lmac_int_en_set_4_axi_wr_err_en_setf(uint8_t set4axiwrerren)
{
	ASSERT_ERR((((uint32_t)set4axiwrerren << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)set4axiwrerren <<18));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_4_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void idma_idma_lmac_int_en_set_4_axi_rd_err_en_setf(uint8_t set4axirderren)
{
	ASSERT_ERR((((uint32_t)set4axirderren << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)set4axirderren <<17));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_4_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void idma_idma_lmac_int_en_set_4_complete_en_setf(uint8_t set4completeen)
{
	ASSERT_ERR((((uint32_t)set4completeen << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)set4completeen <<16));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_3_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void idma_idma_lmac_int_en_set_3_overwrite_err_en_setf(uint8_t set3overwriteerren)
{
	ASSERT_ERR((((uint32_t)set3overwriteerren << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)set3overwriteerren <<15));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_3_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void idma_idma_lmac_int_en_set_3_axi_wr_err_en_setf(uint8_t set3axiwrerren)
{
	ASSERT_ERR((((uint32_t)set3axiwrerren << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)set3axiwrerren <<14));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_3_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void idma_idma_lmac_int_en_set_3_axi_rd_err_en_setf(uint8_t set3axirderren)
{
	ASSERT_ERR((((uint32_t)set3axirderren << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)set3axirderren <<13));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_3_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void idma_idma_lmac_int_en_set_3_complete_en_setf(uint8_t set3completeen)
{
	ASSERT_ERR((((uint32_t)set3completeen << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)set3completeen <<12));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_2_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void idma_idma_lmac_int_en_set_2_overwrite_err_en_setf(uint8_t set2overwriteerren)
{
	ASSERT_ERR((((uint32_t)set2overwriteerren << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)set2overwriteerren <<11));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_2_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void idma_idma_lmac_int_en_set_2_axi_wr_err_en_setf(uint8_t set2axiwrerren)
{
	ASSERT_ERR((((uint32_t)set2axiwrerren << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)set2axiwrerren <<10));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_2_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void idma_idma_lmac_int_en_set_2_axi_rd_err_en_setf(uint8_t set2axirderren)
{
	ASSERT_ERR((((uint32_t)set2axirderren << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)set2axirderren <<9));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_2_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void idma_idma_lmac_int_en_set_2_complete_en_setf(uint8_t set2completeen)
{
	ASSERT_ERR((((uint32_t)set2completeen << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)set2completeen <<8));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_1_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void idma_idma_lmac_int_en_set_1_overwrite_err_en_setf(uint8_t set1overwriteerren)
{
	ASSERT_ERR((((uint32_t)set1overwriteerren << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)set1overwriteerren <<7));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_1_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void idma_idma_lmac_int_en_set_1_axi_wr_err_en_setf(uint8_t set1axiwrerren)
{
	ASSERT_ERR((((uint32_t)set1axiwrerren << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)set1axiwrerren <<6));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_1_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void idma_idma_lmac_int_en_set_1_axi_rd_err_en_setf(uint8_t set1axirderren)
{
	ASSERT_ERR((((uint32_t)set1axirderren << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)set1axirderren <<5));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_1_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void idma_idma_lmac_int_en_set_1_complete_en_setf(uint8_t set1completeen)
{
	ASSERT_ERR((((uint32_t)set1completeen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)set1completeen <<4));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_0_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void idma_idma_lmac_int_en_set_0_overwrite_err_en_setf(uint8_t set0overwriteerren)
{
	ASSERT_ERR((((uint32_t)set0overwriteerren << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)set0overwriteerren <<3));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_0_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void idma_idma_lmac_int_en_set_0_axi_wr_err_en_setf(uint8_t set0axiwrerren)
{
	ASSERT_ERR((((uint32_t)set0axiwrerren << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)set0axiwrerren <<2));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_0_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void idma_idma_lmac_int_en_set_0_axi_rd_err_en_setf(uint8_t set0axirderren)
{
	ASSERT_ERR((((uint32_t)set0axirderren << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)set0axirderren <<1));
}
__INLINE uint8_t idma_idma_lmac_int_en_set_0_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void idma_idma_lmac_int_en_set_0_complete_en_setf(uint8_t set0completeen)
{
	ASSERT_ERR((((uint32_t)set0completeen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IDMA_IDMA_LMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_LMAC_INT_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)set0completeen <<0));
}

/**
 * @brief IDMA_SMAC_INT_EN register definition
 *  Interrupt enable for SMAC register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23    SET5_OVERWRITE_ERR_EN     0              
 *    22    SET5_AXI_WR_ERR_EN        0              
 *    21    SET5_AXI_RD_ERR_EN        0              
 *    20    SET5_COMPLETE_EN          0              
 *    19    SET4_OVERWRITE_ERR_EN     0              
 *    18    SET4_AXI_WR_ERR_EN        0              
 *    17    SET4_AXI_RD_ERR_EN        0              
 *    16    SET4_COMPLETE_EN          0              
 *    15    SET3_OVERWRITE_ERR_EN     0              
 *    14    SET3_AXI_WR_ERR_EN        0              
 *    13    SET3_AXI_RD_ERR_EN        0              
 *    12    SET3_COMPLETE_EN          0              
 *    11    SET2_OVERWRITE_ERR_EN     0              
 *    10    SET2_AXI_WR_ERR_EN        0              
 *    09    SET2_AXI_RD_ERR_EN        0              
 *    08    SET2_COMPLETE_EN          0              
 *    07    SET1_OVERWRITE_ERR_EN     0              
 *    06    SET1_AXI_WR_ERR_EN        0              
 *    05    SET1_AXI_RD_ERR_EN        0              
 *    04    SET1_COMPLETE_EN          0              
 *    03    SET0_OVERWRITE_ERR_EN     0              
 *    02    SET0_AXI_WR_ERR_EN        0              
 *    01    SET0_AXI_RD_ERR_EN        0              
 *    00    SET0_COMPLETE_EN          0              
 * </pre>
 */
#define IDMA_IDMA_SMAC_INT_EN_ADDR        (REG_IDMA_BASE_ADDR+0x00000014)
#define IDMA_IDMA_SMAC_INT_EN_OFFSET      0x00000014
#define IDMA_IDMA_SMAC_INT_EN_INDEX       0x00000005
#define IDMA_IDMA_SMAC_INT_EN_RESET       0x00000000

__INLINE uint32_t  idma_idma_smac_int_en_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
}

__INLINE void idma_idma_smac_int_en_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SMAC_INT_EN_SET_5_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00800000)
#define IDMA_IDMA_SMAC_INT_EN_SET_5_OVERWRITE_ERR_EN_POS    23
#define IDMA_IDMA_SMAC_INT_EN_SET_5_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00400000)
#define IDMA_IDMA_SMAC_INT_EN_SET_5_AXI_WR_ERR_EN_POS    22
#define IDMA_IDMA_SMAC_INT_EN_SET_5_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00200000)
#define IDMA_IDMA_SMAC_INT_EN_SET_5_AXI_RD_ERR_EN_POS    21
#define IDMA_IDMA_SMAC_INT_EN_SET_5_COMPLETE_EN_BIT    ((uint32_t)0x00100000)
#define IDMA_IDMA_SMAC_INT_EN_SET_5_COMPLETE_EN_POS    20
#define IDMA_IDMA_SMAC_INT_EN_SET_4_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00080000)
#define IDMA_IDMA_SMAC_INT_EN_SET_4_OVERWRITE_ERR_EN_POS    19
#define IDMA_IDMA_SMAC_INT_EN_SET_4_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00040000)
#define IDMA_IDMA_SMAC_INT_EN_SET_4_AXI_WR_ERR_EN_POS    18
#define IDMA_IDMA_SMAC_INT_EN_SET_4_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00020000)
#define IDMA_IDMA_SMAC_INT_EN_SET_4_AXI_RD_ERR_EN_POS    17
#define IDMA_IDMA_SMAC_INT_EN_SET_4_COMPLETE_EN_BIT    ((uint32_t)0x00010000)
#define IDMA_IDMA_SMAC_INT_EN_SET_4_COMPLETE_EN_POS    16
#define IDMA_IDMA_SMAC_INT_EN_SET_3_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00008000)
#define IDMA_IDMA_SMAC_INT_EN_SET_3_OVERWRITE_ERR_EN_POS    15
#define IDMA_IDMA_SMAC_INT_EN_SET_3_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00004000)
#define IDMA_IDMA_SMAC_INT_EN_SET_3_AXI_WR_ERR_EN_POS    14
#define IDMA_IDMA_SMAC_INT_EN_SET_3_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00002000)
#define IDMA_IDMA_SMAC_INT_EN_SET_3_AXI_RD_ERR_EN_POS    13
#define IDMA_IDMA_SMAC_INT_EN_SET_3_COMPLETE_EN_BIT    ((uint32_t)0x00001000)
#define IDMA_IDMA_SMAC_INT_EN_SET_3_COMPLETE_EN_POS    12
#define IDMA_IDMA_SMAC_INT_EN_SET_2_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00000800)
#define IDMA_IDMA_SMAC_INT_EN_SET_2_OVERWRITE_ERR_EN_POS    11
#define IDMA_IDMA_SMAC_INT_EN_SET_2_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00000400)
#define IDMA_IDMA_SMAC_INT_EN_SET_2_AXI_WR_ERR_EN_POS    10
#define IDMA_IDMA_SMAC_INT_EN_SET_2_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00000200)
#define IDMA_IDMA_SMAC_INT_EN_SET_2_AXI_RD_ERR_EN_POS    9
#define IDMA_IDMA_SMAC_INT_EN_SET_2_COMPLETE_EN_BIT    ((uint32_t)0x00000100)
#define IDMA_IDMA_SMAC_INT_EN_SET_2_COMPLETE_EN_POS    8
#define IDMA_IDMA_SMAC_INT_EN_SET_1_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00000080)
#define IDMA_IDMA_SMAC_INT_EN_SET_1_OVERWRITE_ERR_EN_POS    7
#define IDMA_IDMA_SMAC_INT_EN_SET_1_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00000040)
#define IDMA_IDMA_SMAC_INT_EN_SET_1_AXI_WR_ERR_EN_POS    6
#define IDMA_IDMA_SMAC_INT_EN_SET_1_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00000020)
#define IDMA_IDMA_SMAC_INT_EN_SET_1_AXI_RD_ERR_EN_POS    5
#define IDMA_IDMA_SMAC_INT_EN_SET_1_COMPLETE_EN_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_SMAC_INT_EN_SET_1_COMPLETE_EN_POS    4
#define IDMA_IDMA_SMAC_INT_EN_SET_0_OVERWRITE_ERR_EN_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_SMAC_INT_EN_SET_0_OVERWRITE_ERR_EN_POS    3
#define IDMA_IDMA_SMAC_INT_EN_SET_0_AXI_WR_ERR_EN_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_SMAC_INT_EN_SET_0_AXI_WR_ERR_EN_POS    2
#define IDMA_IDMA_SMAC_INT_EN_SET_0_AXI_RD_ERR_EN_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_SMAC_INT_EN_SET_0_AXI_RD_ERR_EN_POS    1
#define IDMA_IDMA_SMAC_INT_EN_SET_0_COMPLETE_EN_BIT    ((uint32_t)0x00000001)
#define IDMA_IDMA_SMAC_INT_EN_SET_0_COMPLETE_EN_POS    0

#define IDMA_IDMA_SMAC_INT_EN_SET_5_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_5_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_5_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_5_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_4_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_4_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_4_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_4_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_3_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_3_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_3_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_3_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_2_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_2_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_2_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_2_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_1_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_1_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_1_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_1_COMPLETE_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_0_OVERWRITE_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_0_AXI_WR_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_0_AXI_RD_ERR_EN_RST    0x0
#define IDMA_IDMA_SMAC_INT_EN_SET_0_COMPLETE_EN_RST    0x0

__INLINE void idma_idma_smac_int_en_pack(uint8_t set5_overwrite_err_en, uint8_t set5_axi_wr_err_en, uint8_t set5_axi_rd_err_en, uint8_t set5_complete_en, uint8_t set4_overwrite_err_en, uint8_t set4_axi_wr_err_en, uint8_t set4_axi_rd_err_en, uint8_t set4_complete_en, uint8_t set3_overwrite_err_en, uint8_t set3_axi_wr_err_en, uint8_t set3_axi_rd_err_en, uint8_t set3_complete_en, uint8_t set2_overwrite_err_en, uint8_t set2_axi_wr_err_en, uint8_t set2_axi_rd_err_en, uint8_t set2_complete_en, uint8_t set1_overwrite_err_en, uint8_t set1_axi_wr_err_en, uint8_t set1_axi_rd_err_en, uint8_t set1_complete_en, uint8_t set0_overwrite_err_en, uint8_t set0_axi_wr_err_en, uint8_t set0_axi_rd_err_en, uint8_t set0_complete_en)
{
	ASSERT_ERR((((uint32_t)set5_overwrite_err_en << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)set5_axi_wr_err_en << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)set5_axi_rd_err_en << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)set5_complete_en << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)set4_overwrite_err_en << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)set4_axi_wr_err_en << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)set4_axi_rd_err_en << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)set4_complete_en << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)set3_overwrite_err_en << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)set3_axi_wr_err_en << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)set3_axi_rd_err_en << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)set3_complete_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)set2_overwrite_err_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)set2_axi_wr_err_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)set2_axi_rd_err_en << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)set2_complete_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)set1_overwrite_err_en << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)set1_axi_wr_err_en << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)set1_axi_rd_err_en << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)set1_complete_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)set0_overwrite_err_en << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)set0_axi_wr_err_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)set0_axi_rd_err_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)set0_complete_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR,  ((uint32_t)set5_overwrite_err_en << 23) |((uint32_t)set5_axi_wr_err_en << 22) |((uint32_t)set5_axi_rd_err_en << 21) |((uint32_t)set5_complete_en << 20) |((uint32_t)set4_overwrite_err_en << 19) |((uint32_t)set4_axi_wr_err_en << 18) |((uint32_t)set4_axi_rd_err_en << 17) |((uint32_t)set4_complete_en << 16) |((uint32_t)set3_overwrite_err_en << 15) |((uint32_t)set3_axi_wr_err_en << 14) |((uint32_t)set3_axi_rd_err_en << 13) |((uint32_t)set3_complete_en << 12) |((uint32_t)set2_overwrite_err_en << 11) |((uint32_t)set2_axi_wr_err_en << 10) |((uint32_t)set2_axi_rd_err_en << 9) |((uint32_t)set2_complete_en << 8) |((uint32_t)set1_overwrite_err_en << 7) |((uint32_t)set1_axi_wr_err_en << 6) |((uint32_t)set1_axi_rd_err_en << 5) |((uint32_t)set1_complete_en << 4) |((uint32_t)set0_overwrite_err_en << 3) |((uint32_t)set0_axi_wr_err_en << 2) |((uint32_t)set0_axi_rd_err_en << 1) |((uint32_t)set0_complete_en << 0));
}

__INLINE void idma_idma_smac_int_en_unpack(uint8_t* set5_overwrite_err_en, uint8_t* set5_axi_wr_err_en, uint8_t* set5_axi_rd_err_en, uint8_t* set5_complete_en, uint8_t* set4_overwrite_err_en, uint8_t* set4_axi_wr_err_en, uint8_t* set4_axi_rd_err_en, uint8_t* set4_complete_en, uint8_t* set3_overwrite_err_en, uint8_t* set3_axi_wr_err_en, uint8_t* set3_axi_rd_err_en, uint8_t* set3_complete_en, uint8_t* set2_overwrite_err_en, uint8_t* set2_axi_wr_err_en, uint8_t* set2_axi_rd_err_en, uint8_t* set2_complete_en, uint8_t* set1_overwrite_err_en, uint8_t* set1_axi_wr_err_en, uint8_t* set1_axi_rd_err_en, uint8_t* set1_complete_en, uint8_t* set0_overwrite_err_en, uint8_t* set0_axi_wr_err_en, uint8_t* set0_axi_rd_err_en, uint8_t* set0_complete_en)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);

	*set5_overwrite_err_en = (localVal & ((uint32_t)0x00800000)) >>  23;
	*set5_axi_wr_err_en = (localVal & ((uint32_t)0x00400000)) >>  22;
	*set5_axi_rd_err_en = (localVal & ((uint32_t)0x00200000)) >>  21;
	*set5_complete_en = (localVal & ((uint32_t)0x00100000)) >>  20;
	*set4_overwrite_err_en = (localVal & ((uint32_t)0x00080000)) >>  19;
	*set4_axi_wr_err_en = (localVal & ((uint32_t)0x00040000)) >>  18;
	*set4_axi_rd_err_en = (localVal & ((uint32_t)0x00020000)) >>  17;
	*set4_complete_en = (localVal & ((uint32_t)0x00010000)) >>  16;
	*set3_overwrite_err_en = (localVal & ((uint32_t)0x00008000)) >>  15;
	*set3_axi_wr_err_en = (localVal & ((uint32_t)0x00004000)) >>  14;
	*set3_axi_rd_err_en = (localVal & ((uint32_t)0x00002000)) >>  13;
	*set3_complete_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*set2_overwrite_err_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*set2_axi_wr_err_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*set2_axi_rd_err_en = (localVal & ((uint32_t)0x00000200)) >>  9;
	*set2_complete_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*set1_overwrite_err_en = (localVal & ((uint32_t)0x00000080)) >>  7;
	*set1_axi_wr_err_en = (localVal & ((uint32_t)0x00000040)) >>  6;
	*set1_axi_rd_err_en = (localVal & ((uint32_t)0x00000020)) >>  5;
	*set1_complete_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*set0_overwrite_err_en = (localVal & ((uint32_t)0x00000008)) >>  3;
	*set0_axi_wr_err_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*set0_axi_rd_err_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*set0_complete_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_smac_int_en_set_5_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void idma_idma_smac_int_en_set_5_overwrite_err_en_setf(uint8_t set5overwriteerren)
{
	ASSERT_ERR((((uint32_t)set5overwriteerren << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)set5overwriteerren <<23));
}
__INLINE uint8_t idma_idma_smac_int_en_set_5_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void idma_idma_smac_int_en_set_5_axi_wr_err_en_setf(uint8_t set5axiwrerren)
{
	ASSERT_ERR((((uint32_t)set5axiwrerren << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)set5axiwrerren <<22));
}
__INLINE uint8_t idma_idma_smac_int_en_set_5_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void idma_idma_smac_int_en_set_5_axi_rd_err_en_setf(uint8_t set5axirderren)
{
	ASSERT_ERR((((uint32_t)set5axirderren << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)set5axirderren <<21));
}
__INLINE uint8_t idma_idma_smac_int_en_set_5_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void idma_idma_smac_int_en_set_5_complete_en_setf(uint8_t set5completeen)
{
	ASSERT_ERR((((uint32_t)set5completeen << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)set5completeen <<20));
}
__INLINE uint8_t idma_idma_smac_int_en_set_4_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void idma_idma_smac_int_en_set_4_overwrite_err_en_setf(uint8_t set4overwriteerren)
{
	ASSERT_ERR((((uint32_t)set4overwriteerren << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)set4overwriteerren <<19));
}
__INLINE uint8_t idma_idma_smac_int_en_set_4_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void idma_idma_smac_int_en_set_4_axi_wr_err_en_setf(uint8_t set4axiwrerren)
{
	ASSERT_ERR((((uint32_t)set4axiwrerren << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)set4axiwrerren <<18));
}
__INLINE uint8_t idma_idma_smac_int_en_set_4_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void idma_idma_smac_int_en_set_4_axi_rd_err_en_setf(uint8_t set4axirderren)
{
	ASSERT_ERR((((uint32_t)set4axirderren << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)set4axirderren <<17));
}
__INLINE uint8_t idma_idma_smac_int_en_set_4_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void idma_idma_smac_int_en_set_4_complete_en_setf(uint8_t set4completeen)
{
	ASSERT_ERR((((uint32_t)set4completeen << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)set4completeen <<16));
}
__INLINE uint8_t idma_idma_smac_int_en_set_3_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void idma_idma_smac_int_en_set_3_overwrite_err_en_setf(uint8_t set3overwriteerren)
{
	ASSERT_ERR((((uint32_t)set3overwriteerren << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)set3overwriteerren <<15));
}
__INLINE uint8_t idma_idma_smac_int_en_set_3_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void idma_idma_smac_int_en_set_3_axi_wr_err_en_setf(uint8_t set3axiwrerren)
{
	ASSERT_ERR((((uint32_t)set3axiwrerren << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)set3axiwrerren <<14));
}
__INLINE uint8_t idma_idma_smac_int_en_set_3_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void idma_idma_smac_int_en_set_3_axi_rd_err_en_setf(uint8_t set3axirderren)
{
	ASSERT_ERR((((uint32_t)set3axirderren << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)set3axirderren <<13));
}
__INLINE uint8_t idma_idma_smac_int_en_set_3_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void idma_idma_smac_int_en_set_3_complete_en_setf(uint8_t set3completeen)
{
	ASSERT_ERR((((uint32_t)set3completeen << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)set3completeen <<12));
}
__INLINE uint8_t idma_idma_smac_int_en_set_2_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void idma_idma_smac_int_en_set_2_overwrite_err_en_setf(uint8_t set2overwriteerren)
{
	ASSERT_ERR((((uint32_t)set2overwriteerren << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)set2overwriteerren <<11));
}
__INLINE uint8_t idma_idma_smac_int_en_set_2_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void idma_idma_smac_int_en_set_2_axi_wr_err_en_setf(uint8_t set2axiwrerren)
{
	ASSERT_ERR((((uint32_t)set2axiwrerren << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)set2axiwrerren <<10));
}
__INLINE uint8_t idma_idma_smac_int_en_set_2_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void idma_idma_smac_int_en_set_2_axi_rd_err_en_setf(uint8_t set2axirderren)
{
	ASSERT_ERR((((uint32_t)set2axirderren << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)set2axirderren <<9));
}
__INLINE uint8_t idma_idma_smac_int_en_set_2_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void idma_idma_smac_int_en_set_2_complete_en_setf(uint8_t set2completeen)
{
	ASSERT_ERR((((uint32_t)set2completeen << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)set2completeen <<8));
}
__INLINE uint8_t idma_idma_smac_int_en_set_1_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void idma_idma_smac_int_en_set_1_overwrite_err_en_setf(uint8_t set1overwriteerren)
{
	ASSERT_ERR((((uint32_t)set1overwriteerren << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)set1overwriteerren <<7));
}
__INLINE uint8_t idma_idma_smac_int_en_set_1_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void idma_idma_smac_int_en_set_1_axi_wr_err_en_setf(uint8_t set1axiwrerren)
{
	ASSERT_ERR((((uint32_t)set1axiwrerren << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)set1axiwrerren <<6));
}
__INLINE uint8_t idma_idma_smac_int_en_set_1_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void idma_idma_smac_int_en_set_1_axi_rd_err_en_setf(uint8_t set1axirderren)
{
	ASSERT_ERR((((uint32_t)set1axirderren << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)set1axirderren <<5));
}
__INLINE uint8_t idma_idma_smac_int_en_set_1_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void idma_idma_smac_int_en_set_1_complete_en_setf(uint8_t set1completeen)
{
	ASSERT_ERR((((uint32_t)set1completeen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)set1completeen <<4));
}
__INLINE uint8_t idma_idma_smac_int_en_set_0_overwrite_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void idma_idma_smac_int_en_set_0_overwrite_err_en_setf(uint8_t set0overwriteerren)
{
	ASSERT_ERR((((uint32_t)set0overwriteerren << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)set0overwriteerren <<3));
}
__INLINE uint8_t idma_idma_smac_int_en_set_0_axi_wr_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void idma_idma_smac_int_en_set_0_axi_wr_err_en_setf(uint8_t set0axiwrerren)
{
	ASSERT_ERR((((uint32_t)set0axiwrerren << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)set0axiwrerren <<2));
}
__INLINE uint8_t idma_idma_smac_int_en_set_0_axi_rd_err_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void idma_idma_smac_int_en_set_0_axi_rd_err_en_setf(uint8_t set0axirderren)
{
	ASSERT_ERR((((uint32_t)set0axirderren << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)set0axirderren <<1));
}
__INLINE uint8_t idma_idma_smac_int_en_set_0_complete_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void idma_idma_smac_int_en_set_0_complete_en_setf(uint8_t set0completeen)
{
	ASSERT_ERR((((uint32_t)set0completeen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IDMA_IDMA_SMAC_INT_EN_ADDR, (REG_PL_RD(IDMA_IDMA_SMAC_INT_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)set0completeen <<0));
}

/**
 * @brief IDMA_UMAC_INT_STAT register definition
 *  Interrupt after enable for UMAC register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23    SET5_OVERWRITE_ERR        0              
 *    22    SET5_AXI_WR_ERR           0              
 *    21    SET5_AXI_RD_ERR           0              
 *    20    SET5_COMPLETE             0              
 *    19    SET4_OVERWRITE_ERR        0              
 *    18    SET4_AXI_WR_ERR           0              
 *    17    SET4_AXI_RD_ERR           0              
 *    16    SET4_COMPLETE             0              
 *    15    SET3_OVERWRITE_ERR        0              
 *    14    SET3_AXI_WR_ERR           0              
 *    13    SET3_AXI_RD_ERR           0              
 *    12    SET3_COMPLETE             0              
 *    11    SET2_OVERWRITE_ERR        0              
 *    10    SET2_AXI_WR_ERR           0              
 *    09    SET2_AXI_RD_ERR           0              
 *    08    SET2_COMPLETE             0              
 *    07    SET1_OVERWRITE_ERR        0              
 *    06    SET1_AXI_WR_ERR           0              
 *    05    SET1_AXI_RD_ERR           0              
 *    04    SET1_COMPLETE             0              
 *    03    SET0_OVERWRITE_ERR        0              
 *    02    SET0_AXI_WR_ERR           0              
 *    01    SET0_AXI_RD_ERR           0              
 *    00    SET0_COMPLETE             0              
 * </pre>
 */
#define IDMA_IDMA_UMAC_INT_STAT_ADDR        (REG_IDMA_BASE_ADDR+0x00000018)
#define IDMA_IDMA_UMAC_INT_STAT_OFFSET      0x00000018
#define IDMA_IDMA_UMAC_INT_STAT_INDEX       0x00000006
#define IDMA_IDMA_UMAC_INT_STAT_RESET       0x00000000

__INLINE uint32_t  idma_idma_umac_int_stat_get(void)
{
	return REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
}

// field definitions
#define IDMA_IDMA_UMAC_INT_STAT_SET_5_OVERWRITE_ERR_BIT    ((uint32_t)0x00800000)
#define IDMA_IDMA_UMAC_INT_STAT_SET_5_OVERWRITE_ERR_POS    23
#define IDMA_IDMA_UMAC_INT_STAT_SET_5_AXI_WR_ERR_BIT    ((uint32_t)0x00400000)
#define IDMA_IDMA_UMAC_INT_STAT_SET_5_AXI_WR_ERR_POS    22
#define IDMA_IDMA_UMAC_INT_STAT_SET_5_AXI_RD_ERR_BIT    ((uint32_t)0x00200000)
#define IDMA_IDMA_UMAC_INT_STAT_SET_5_AXI_RD_ERR_POS    21
#define IDMA_IDMA_UMAC_INT_STAT_SET_5_COMPLETE_BIT    ((uint32_t)0x00100000)
#define IDMA_IDMA_UMAC_INT_STAT_SET_5_COMPLETE_POS    20
#define IDMA_IDMA_UMAC_INT_STAT_SET_4_OVERWRITE_ERR_BIT    ((uint32_t)0x00080000)
#define IDMA_IDMA_UMAC_INT_STAT_SET_4_OVERWRITE_ERR_POS    19
#define IDMA_IDMA_UMAC_INT_STAT_SET_4_AXI_WR_ERR_BIT    ((uint32_t)0x00040000)
#define IDMA_IDMA_UMAC_INT_STAT_SET_4_AXI_WR_ERR_POS    18
#define IDMA_IDMA_UMAC_INT_STAT_SET_4_AXI_RD_ERR_BIT    ((uint32_t)0x00020000)
#define IDMA_IDMA_UMAC_INT_STAT_SET_4_AXI_RD_ERR_POS    17
#define IDMA_IDMA_UMAC_INT_STAT_SET_4_COMPLETE_BIT    ((uint32_t)0x00010000)
#define IDMA_IDMA_UMAC_INT_STAT_SET_4_COMPLETE_POS    16
#define IDMA_IDMA_UMAC_INT_STAT_SET_3_OVERWRITE_ERR_BIT    ((uint32_t)0x00008000)
#define IDMA_IDMA_UMAC_INT_STAT_SET_3_OVERWRITE_ERR_POS    15
#define IDMA_IDMA_UMAC_INT_STAT_SET_3_AXI_WR_ERR_BIT    ((uint32_t)0x00004000)
#define IDMA_IDMA_UMAC_INT_STAT_SET_3_AXI_WR_ERR_POS    14
#define IDMA_IDMA_UMAC_INT_STAT_SET_3_AXI_RD_ERR_BIT    ((uint32_t)0x00002000)
#define IDMA_IDMA_UMAC_INT_STAT_SET_3_AXI_RD_ERR_POS    13
#define IDMA_IDMA_UMAC_INT_STAT_SET_3_COMPLETE_BIT    ((uint32_t)0x00001000)
#define IDMA_IDMA_UMAC_INT_STAT_SET_3_COMPLETE_POS    12
#define IDMA_IDMA_UMAC_INT_STAT_SET_2_OVERWRITE_ERR_BIT    ((uint32_t)0x00000800)
#define IDMA_IDMA_UMAC_INT_STAT_SET_2_OVERWRITE_ERR_POS    11
#define IDMA_IDMA_UMAC_INT_STAT_SET_2_AXI_WR_ERR_BIT    ((uint32_t)0x00000400)
#define IDMA_IDMA_UMAC_INT_STAT_SET_2_AXI_WR_ERR_POS    10
#define IDMA_IDMA_UMAC_INT_STAT_SET_2_AXI_RD_ERR_BIT    ((uint32_t)0x00000200)
#define IDMA_IDMA_UMAC_INT_STAT_SET_2_AXI_RD_ERR_POS    9
#define IDMA_IDMA_UMAC_INT_STAT_SET_2_COMPLETE_BIT    ((uint32_t)0x00000100)
#define IDMA_IDMA_UMAC_INT_STAT_SET_2_COMPLETE_POS    8
#define IDMA_IDMA_UMAC_INT_STAT_SET_1_OVERWRITE_ERR_BIT    ((uint32_t)0x00000080)
#define IDMA_IDMA_UMAC_INT_STAT_SET_1_OVERWRITE_ERR_POS    7
#define IDMA_IDMA_UMAC_INT_STAT_SET_1_AXI_WR_ERR_BIT    ((uint32_t)0x00000040)
#define IDMA_IDMA_UMAC_INT_STAT_SET_1_AXI_WR_ERR_POS    6
#define IDMA_IDMA_UMAC_INT_STAT_SET_1_AXI_RD_ERR_BIT    ((uint32_t)0x00000020)
#define IDMA_IDMA_UMAC_INT_STAT_SET_1_AXI_RD_ERR_POS    5
#define IDMA_IDMA_UMAC_INT_STAT_SET_1_COMPLETE_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_UMAC_INT_STAT_SET_1_COMPLETE_POS    4
#define IDMA_IDMA_UMAC_INT_STAT_SET_0_OVERWRITE_ERR_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_UMAC_INT_STAT_SET_0_OVERWRITE_ERR_POS    3
#define IDMA_IDMA_UMAC_INT_STAT_SET_0_AXI_WR_ERR_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_UMAC_INT_STAT_SET_0_AXI_WR_ERR_POS    2
#define IDMA_IDMA_UMAC_INT_STAT_SET_0_AXI_RD_ERR_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_UMAC_INT_STAT_SET_0_AXI_RD_ERR_POS    1
#define IDMA_IDMA_UMAC_INT_STAT_SET_0_COMPLETE_BIT    ((uint32_t)0x00000001)
#define IDMA_IDMA_UMAC_INT_STAT_SET_0_COMPLETE_POS    0

#define IDMA_IDMA_UMAC_INT_STAT_SET_5_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_5_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_5_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_5_COMPLETE_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_4_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_4_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_4_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_4_COMPLETE_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_3_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_3_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_3_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_3_COMPLETE_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_2_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_2_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_2_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_2_COMPLETE_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_1_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_1_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_1_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_1_COMPLETE_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_0_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_0_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_0_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_UMAC_INT_STAT_SET_0_COMPLETE_RST    0x0

__INLINE void idma_idma_umac_int_stat_unpack(uint8_t* set5_overwrite_err, uint8_t* set5_axi_wr_err, uint8_t* set5_axi_rd_err, uint8_t* set5_complete, uint8_t* set4_overwrite_err, uint8_t* set4_axi_wr_err, uint8_t* set4_axi_rd_err, uint8_t* set4_complete, uint8_t* set3_overwrite_err, uint8_t* set3_axi_wr_err, uint8_t* set3_axi_rd_err, uint8_t* set3_complete, uint8_t* set2_overwrite_err, uint8_t* set2_axi_wr_err, uint8_t* set2_axi_rd_err, uint8_t* set2_complete, uint8_t* set1_overwrite_err, uint8_t* set1_axi_wr_err, uint8_t* set1_axi_rd_err, uint8_t* set1_complete, uint8_t* set0_overwrite_err, uint8_t* set0_axi_wr_err, uint8_t* set0_axi_rd_err, uint8_t* set0_complete)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);

	*set5_overwrite_err = (localVal & ((uint32_t)0x00800000)) >>  23;
	*set5_axi_wr_err = (localVal & ((uint32_t)0x00400000)) >>  22;
	*set5_axi_rd_err = (localVal & ((uint32_t)0x00200000)) >>  21;
	*set5_complete = (localVal & ((uint32_t)0x00100000)) >>  20;
	*set4_overwrite_err = (localVal & ((uint32_t)0x00080000)) >>  19;
	*set4_axi_wr_err = (localVal & ((uint32_t)0x00040000)) >>  18;
	*set4_axi_rd_err = (localVal & ((uint32_t)0x00020000)) >>  17;
	*set4_complete = (localVal & ((uint32_t)0x00010000)) >>  16;
	*set3_overwrite_err = (localVal & ((uint32_t)0x00008000)) >>  15;
	*set3_axi_wr_err = (localVal & ((uint32_t)0x00004000)) >>  14;
	*set3_axi_rd_err = (localVal & ((uint32_t)0x00002000)) >>  13;
	*set3_complete = (localVal & ((uint32_t)0x00001000)) >>  12;
	*set2_overwrite_err = (localVal & ((uint32_t)0x00000800)) >>  11;
	*set2_axi_wr_err = (localVal & ((uint32_t)0x00000400)) >>  10;
	*set2_axi_rd_err = (localVal & ((uint32_t)0x00000200)) >>  9;
	*set2_complete = (localVal & ((uint32_t)0x00000100)) >>  8;
	*set1_overwrite_err = (localVal & ((uint32_t)0x00000080)) >>  7;
	*set1_axi_wr_err = (localVal & ((uint32_t)0x00000040)) >>  6;
	*set1_axi_rd_err = (localVal & ((uint32_t)0x00000020)) >>  5;
	*set1_complete = (localVal & ((uint32_t)0x00000010)) >>  4;
	*set0_overwrite_err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*set0_axi_wr_err = (localVal & ((uint32_t)0x00000004)) >>  2;
	*set0_axi_rd_err = (localVal & ((uint32_t)0x00000002)) >>  1;
	*set0_complete = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_umac_int_stat_set_5_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_5_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_5_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_5_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_4_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_4_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_4_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_4_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_3_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_3_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_3_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_3_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_2_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_2_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_2_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_2_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_1_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_1_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_1_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_1_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_0_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_0_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_0_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t idma_idma_umac_int_stat_set_0_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_UMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief IDMA_LMAC_INT_STAT register definition
 *  Interrupt after enable for LMAC register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23    SET5_OVERWRITE_ERR        0              
 *    22    SET5_AXI_WR_ERR           0              
 *    21    SET5_AXI_RD_ERR           0              
 *    20    SET5_COMPLETE             0              
 *    19    SET4_OVERWRITE_ERR        0              
 *    18    SET4_AXI_WR_ERR           0              
 *    17    SET4_AXI_RD_ERR           0              
 *    16    SET4_COMPLETE             0              
 *    15    SET3_OVERWRITE_ERR        0              
 *    14    SET3_AXI_WR_ERR           0              
 *    13    SET3_AXI_RD_ERR           0              
 *    12    SET3_COMPLETE             0              
 *    11    SET2_OVERWRITE_ERR        0              
 *    10    SET2_AXI_WR_ERR           0              
 *    09    SET2_AXI_RD_ERR           0              
 *    08    SET2_COMPLETE             0              
 *    07    SET1_OVERWRITE_ERR        0              
 *    06    SET1_AXI_WR_ERR           0              
 *    05    SET1_AXI_RD_ERR           0              
 *    04    SET1_COMPLETE             0              
 *    03    SET0_OVERWRITE_ERR        0              
 *    02    SET0_AXI_WR_ERR           0              
 *    01    SET0_AXI_RD_ERR           0              
 *    00    SET0_COMPLETE             0              
 * </pre>
 */
#define IDMA_IDMA_LMAC_INT_STAT_ADDR        (REG_IDMA_BASE_ADDR+0x0000001C)
#define IDMA_IDMA_LMAC_INT_STAT_OFFSET      0x0000001C
#define IDMA_IDMA_LMAC_INT_STAT_INDEX       0x00000007
#define IDMA_IDMA_LMAC_INT_STAT_RESET       0x00000000

__INLINE uint32_t  idma_idma_lmac_int_stat_get(void)
{
	return REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
}

// field definitions
#define IDMA_IDMA_LMAC_INT_STAT_SET_5_OVERWRITE_ERR_BIT    ((uint32_t)0x00800000)
#define IDMA_IDMA_LMAC_INT_STAT_SET_5_OVERWRITE_ERR_POS    23
#define IDMA_IDMA_LMAC_INT_STAT_SET_5_AXI_WR_ERR_BIT    ((uint32_t)0x00400000)
#define IDMA_IDMA_LMAC_INT_STAT_SET_5_AXI_WR_ERR_POS    22
#define IDMA_IDMA_LMAC_INT_STAT_SET_5_AXI_RD_ERR_BIT    ((uint32_t)0x00200000)
#define IDMA_IDMA_LMAC_INT_STAT_SET_5_AXI_RD_ERR_POS    21
#define IDMA_IDMA_LMAC_INT_STAT_SET_5_COMPLETE_BIT    ((uint32_t)0x00100000)
#define IDMA_IDMA_LMAC_INT_STAT_SET_5_COMPLETE_POS    20
#define IDMA_IDMA_LMAC_INT_STAT_SET_4_OVERWRITE_ERR_BIT    ((uint32_t)0x00080000)
#define IDMA_IDMA_LMAC_INT_STAT_SET_4_OVERWRITE_ERR_POS    19
#define IDMA_IDMA_LMAC_INT_STAT_SET_4_AXI_WR_ERR_BIT    ((uint32_t)0x00040000)
#define IDMA_IDMA_LMAC_INT_STAT_SET_4_AXI_WR_ERR_POS    18
#define IDMA_IDMA_LMAC_INT_STAT_SET_4_AXI_RD_ERR_BIT    ((uint32_t)0x00020000)
#define IDMA_IDMA_LMAC_INT_STAT_SET_4_AXI_RD_ERR_POS    17
#define IDMA_IDMA_LMAC_INT_STAT_SET_4_COMPLETE_BIT    ((uint32_t)0x00010000)
#define IDMA_IDMA_LMAC_INT_STAT_SET_4_COMPLETE_POS    16
#define IDMA_IDMA_LMAC_INT_STAT_SET_3_OVERWRITE_ERR_BIT    ((uint32_t)0x00008000)
#define IDMA_IDMA_LMAC_INT_STAT_SET_3_OVERWRITE_ERR_POS    15
#define IDMA_IDMA_LMAC_INT_STAT_SET_3_AXI_WR_ERR_BIT    ((uint32_t)0x00004000)
#define IDMA_IDMA_LMAC_INT_STAT_SET_3_AXI_WR_ERR_POS    14
#define IDMA_IDMA_LMAC_INT_STAT_SET_3_AXI_RD_ERR_BIT    ((uint32_t)0x00002000)
#define IDMA_IDMA_LMAC_INT_STAT_SET_3_AXI_RD_ERR_POS    13
#define IDMA_IDMA_LMAC_INT_STAT_SET_3_COMPLETE_BIT    ((uint32_t)0x00001000)
#define IDMA_IDMA_LMAC_INT_STAT_SET_3_COMPLETE_POS    12
#define IDMA_IDMA_LMAC_INT_STAT_SET_2_OVERWRITE_ERR_BIT    ((uint32_t)0x00000800)
#define IDMA_IDMA_LMAC_INT_STAT_SET_2_OVERWRITE_ERR_POS    11
#define IDMA_IDMA_LMAC_INT_STAT_SET_2_AXI_WR_ERR_BIT    ((uint32_t)0x00000400)
#define IDMA_IDMA_LMAC_INT_STAT_SET_2_AXI_WR_ERR_POS    10
#define IDMA_IDMA_LMAC_INT_STAT_SET_2_AXI_RD_ERR_BIT    ((uint32_t)0x00000200)
#define IDMA_IDMA_LMAC_INT_STAT_SET_2_AXI_RD_ERR_POS    9
#define IDMA_IDMA_LMAC_INT_STAT_SET_2_COMPLETE_BIT    ((uint32_t)0x00000100)
#define IDMA_IDMA_LMAC_INT_STAT_SET_2_COMPLETE_POS    8
#define IDMA_IDMA_LMAC_INT_STAT_SET_1_OVERWRITE_ERR_BIT    ((uint32_t)0x00000080)
#define IDMA_IDMA_LMAC_INT_STAT_SET_1_OVERWRITE_ERR_POS    7
#define IDMA_IDMA_LMAC_INT_STAT_SET_1_AXI_WR_ERR_BIT    ((uint32_t)0x00000040)
#define IDMA_IDMA_LMAC_INT_STAT_SET_1_AXI_WR_ERR_POS    6
#define IDMA_IDMA_LMAC_INT_STAT_SET_1_AXI_RD_ERR_BIT    ((uint32_t)0x00000020)
#define IDMA_IDMA_LMAC_INT_STAT_SET_1_AXI_RD_ERR_POS    5
#define IDMA_IDMA_LMAC_INT_STAT_SET_1_COMPLETE_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_LMAC_INT_STAT_SET_1_COMPLETE_POS    4
#define IDMA_IDMA_LMAC_INT_STAT_SET_0_OVERWRITE_ERR_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_LMAC_INT_STAT_SET_0_OVERWRITE_ERR_POS    3
#define IDMA_IDMA_LMAC_INT_STAT_SET_0_AXI_WR_ERR_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_LMAC_INT_STAT_SET_0_AXI_WR_ERR_POS    2
#define IDMA_IDMA_LMAC_INT_STAT_SET_0_AXI_RD_ERR_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_LMAC_INT_STAT_SET_0_AXI_RD_ERR_POS    1
#define IDMA_IDMA_LMAC_INT_STAT_SET_0_COMPLETE_BIT    ((uint32_t)0x00000001)
#define IDMA_IDMA_LMAC_INT_STAT_SET_0_COMPLETE_POS    0

#define IDMA_IDMA_LMAC_INT_STAT_SET_5_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_5_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_5_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_5_COMPLETE_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_4_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_4_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_4_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_4_COMPLETE_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_3_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_3_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_3_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_3_COMPLETE_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_2_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_2_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_2_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_2_COMPLETE_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_1_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_1_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_1_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_1_COMPLETE_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_0_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_0_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_0_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_LMAC_INT_STAT_SET_0_COMPLETE_RST    0x0

__INLINE void idma_idma_lmac_int_stat_unpack(uint8_t* set5_overwrite_err, uint8_t* set5_axi_wr_err, uint8_t* set5_axi_rd_err, uint8_t* set5_complete, uint8_t* set4_overwrite_err, uint8_t* set4_axi_wr_err, uint8_t* set4_axi_rd_err, uint8_t* set4_complete, uint8_t* set3_overwrite_err, uint8_t* set3_axi_wr_err, uint8_t* set3_axi_rd_err, uint8_t* set3_complete, uint8_t* set2_overwrite_err, uint8_t* set2_axi_wr_err, uint8_t* set2_axi_rd_err, uint8_t* set2_complete, uint8_t* set1_overwrite_err, uint8_t* set1_axi_wr_err, uint8_t* set1_axi_rd_err, uint8_t* set1_complete, uint8_t* set0_overwrite_err, uint8_t* set0_axi_wr_err, uint8_t* set0_axi_rd_err, uint8_t* set0_complete)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);

	*set5_overwrite_err = (localVal & ((uint32_t)0x00800000)) >>  23;
	*set5_axi_wr_err = (localVal & ((uint32_t)0x00400000)) >>  22;
	*set5_axi_rd_err = (localVal & ((uint32_t)0x00200000)) >>  21;
	*set5_complete = (localVal & ((uint32_t)0x00100000)) >>  20;
	*set4_overwrite_err = (localVal & ((uint32_t)0x00080000)) >>  19;
	*set4_axi_wr_err = (localVal & ((uint32_t)0x00040000)) >>  18;
	*set4_axi_rd_err = (localVal & ((uint32_t)0x00020000)) >>  17;
	*set4_complete = (localVal & ((uint32_t)0x00010000)) >>  16;
	*set3_overwrite_err = (localVal & ((uint32_t)0x00008000)) >>  15;
	*set3_axi_wr_err = (localVal & ((uint32_t)0x00004000)) >>  14;
	*set3_axi_rd_err = (localVal & ((uint32_t)0x00002000)) >>  13;
	*set3_complete = (localVal & ((uint32_t)0x00001000)) >>  12;
	*set2_overwrite_err = (localVal & ((uint32_t)0x00000800)) >>  11;
	*set2_axi_wr_err = (localVal & ((uint32_t)0x00000400)) >>  10;
	*set2_axi_rd_err = (localVal & ((uint32_t)0x00000200)) >>  9;
	*set2_complete = (localVal & ((uint32_t)0x00000100)) >>  8;
	*set1_overwrite_err = (localVal & ((uint32_t)0x00000080)) >>  7;
	*set1_axi_wr_err = (localVal & ((uint32_t)0x00000040)) >>  6;
	*set1_axi_rd_err = (localVal & ((uint32_t)0x00000020)) >>  5;
	*set1_complete = (localVal & ((uint32_t)0x00000010)) >>  4;
	*set0_overwrite_err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*set0_axi_wr_err = (localVal & ((uint32_t)0x00000004)) >>  2;
	*set0_axi_rd_err = (localVal & ((uint32_t)0x00000002)) >>  1;
	*set0_complete = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_lmac_int_stat_set_5_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_5_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_5_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_5_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_4_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_4_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_4_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_4_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_3_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_3_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_3_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_3_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_2_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_2_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_2_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_2_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_1_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_1_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_1_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_1_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_0_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_0_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_0_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t idma_idma_lmac_int_stat_set_0_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_LMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief IDMA_SMAC_INT_STAT register definition
 *  Interrupt after enable for SMAC register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23    SET5_OVERWRITE_ERR        0              
 *    22    SET5_AXI_WR_ERR           0              
 *    21    SET5_AXI_RD_ERR           0              
 *    20    SET5_COMPLETE             0              
 *    19    SET4_OVERWRITE_ERR        0              
 *    18    SET4_AXI_WR_ERR           0              
 *    17    SET4_AXI_RD_ERR           0              
 *    16    SET4_COMPLETE             0              
 *    15    SET3_OVERWRITE_ERR        0              
 *    14    SET3_AXI_WR_ERR           0              
 *    13    SET3_AXI_RD_ERR           0              
 *    12    SET3_COMPLETE             0              
 *    11    SET2_OVERWRITE_ERR        0              
 *    10    SET2_AXI_WR_ERR           0              
 *    09    SET2_AXI_RD_ERR           0              
 *    08    SET2_COMPLETE             0              
 *    07    SET1_OVERWRITE_ERR        0              
 *    06    SET1_AXI_WR_ERR           0              
 *    05    SET1_AXI_RD_ERR           0              
 *    04    SET1_COMPLETE             0              
 *    03    SET0_OVERWRITE_ERR        0              
 *    02    SET0_AXI_WR_ERR           0              
 *    01    SET0_AXI_RD_ERR           0              
 *    00    SET0_COMPLETE             0              
 * </pre>
 */
#define IDMA_IDMA_SMAC_INT_STAT_ADDR        (REG_IDMA_BASE_ADDR+0x00000020)
#define IDMA_IDMA_SMAC_INT_STAT_OFFSET      0x00000020
#define IDMA_IDMA_SMAC_INT_STAT_INDEX       0x00000008
#define IDMA_IDMA_SMAC_INT_STAT_RESET       0x00000000

__INLINE uint32_t  idma_idma_smac_int_stat_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
}

// field definitions
#define IDMA_IDMA_SMAC_INT_STAT_SET_5_OVERWRITE_ERR_BIT    ((uint32_t)0x00800000)
#define IDMA_IDMA_SMAC_INT_STAT_SET_5_OVERWRITE_ERR_POS    23
#define IDMA_IDMA_SMAC_INT_STAT_SET_5_AXI_WR_ERR_BIT    ((uint32_t)0x00400000)
#define IDMA_IDMA_SMAC_INT_STAT_SET_5_AXI_WR_ERR_POS    22
#define IDMA_IDMA_SMAC_INT_STAT_SET_5_AXI_RD_ERR_BIT    ((uint32_t)0x00200000)
#define IDMA_IDMA_SMAC_INT_STAT_SET_5_AXI_RD_ERR_POS    21
#define IDMA_IDMA_SMAC_INT_STAT_SET_5_COMPLETE_BIT    ((uint32_t)0x00100000)
#define IDMA_IDMA_SMAC_INT_STAT_SET_5_COMPLETE_POS    20
#define IDMA_IDMA_SMAC_INT_STAT_SET_4_OVERWRITE_ERR_BIT    ((uint32_t)0x00080000)
#define IDMA_IDMA_SMAC_INT_STAT_SET_4_OVERWRITE_ERR_POS    19
#define IDMA_IDMA_SMAC_INT_STAT_SET_4_AXI_WR_ERR_BIT    ((uint32_t)0x00040000)
#define IDMA_IDMA_SMAC_INT_STAT_SET_4_AXI_WR_ERR_POS    18
#define IDMA_IDMA_SMAC_INT_STAT_SET_4_AXI_RD_ERR_BIT    ((uint32_t)0x00020000)
#define IDMA_IDMA_SMAC_INT_STAT_SET_4_AXI_RD_ERR_POS    17
#define IDMA_IDMA_SMAC_INT_STAT_SET_4_COMPLETE_BIT    ((uint32_t)0x00010000)
#define IDMA_IDMA_SMAC_INT_STAT_SET_4_COMPLETE_POS    16
#define IDMA_IDMA_SMAC_INT_STAT_SET_3_OVERWRITE_ERR_BIT    ((uint32_t)0x00008000)
#define IDMA_IDMA_SMAC_INT_STAT_SET_3_OVERWRITE_ERR_POS    15
#define IDMA_IDMA_SMAC_INT_STAT_SET_3_AXI_WR_ERR_BIT    ((uint32_t)0x00004000)
#define IDMA_IDMA_SMAC_INT_STAT_SET_3_AXI_WR_ERR_POS    14
#define IDMA_IDMA_SMAC_INT_STAT_SET_3_AXI_RD_ERR_BIT    ((uint32_t)0x00002000)
#define IDMA_IDMA_SMAC_INT_STAT_SET_3_AXI_RD_ERR_POS    13
#define IDMA_IDMA_SMAC_INT_STAT_SET_3_COMPLETE_BIT    ((uint32_t)0x00001000)
#define IDMA_IDMA_SMAC_INT_STAT_SET_3_COMPLETE_POS    12
#define IDMA_IDMA_SMAC_INT_STAT_SET_2_OVERWRITE_ERR_BIT    ((uint32_t)0x00000800)
#define IDMA_IDMA_SMAC_INT_STAT_SET_2_OVERWRITE_ERR_POS    11
#define IDMA_IDMA_SMAC_INT_STAT_SET_2_AXI_WR_ERR_BIT    ((uint32_t)0x00000400)
#define IDMA_IDMA_SMAC_INT_STAT_SET_2_AXI_WR_ERR_POS    10
#define IDMA_IDMA_SMAC_INT_STAT_SET_2_AXI_RD_ERR_BIT    ((uint32_t)0x00000200)
#define IDMA_IDMA_SMAC_INT_STAT_SET_2_AXI_RD_ERR_POS    9
#define IDMA_IDMA_SMAC_INT_STAT_SET_2_COMPLETE_BIT    ((uint32_t)0x00000100)
#define IDMA_IDMA_SMAC_INT_STAT_SET_2_COMPLETE_POS    8
#define IDMA_IDMA_SMAC_INT_STAT_SET_1_OVERWRITE_ERR_BIT    ((uint32_t)0x00000080)
#define IDMA_IDMA_SMAC_INT_STAT_SET_1_OVERWRITE_ERR_POS    7
#define IDMA_IDMA_SMAC_INT_STAT_SET_1_AXI_WR_ERR_BIT    ((uint32_t)0x00000040)
#define IDMA_IDMA_SMAC_INT_STAT_SET_1_AXI_WR_ERR_POS    6
#define IDMA_IDMA_SMAC_INT_STAT_SET_1_AXI_RD_ERR_BIT    ((uint32_t)0x00000020)
#define IDMA_IDMA_SMAC_INT_STAT_SET_1_AXI_RD_ERR_POS    5
#define IDMA_IDMA_SMAC_INT_STAT_SET_1_COMPLETE_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_SMAC_INT_STAT_SET_1_COMPLETE_POS    4
#define IDMA_IDMA_SMAC_INT_STAT_SET_0_OVERWRITE_ERR_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_SMAC_INT_STAT_SET_0_OVERWRITE_ERR_POS    3
#define IDMA_IDMA_SMAC_INT_STAT_SET_0_AXI_WR_ERR_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_SMAC_INT_STAT_SET_0_AXI_WR_ERR_POS    2
#define IDMA_IDMA_SMAC_INT_STAT_SET_0_AXI_RD_ERR_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_SMAC_INT_STAT_SET_0_AXI_RD_ERR_POS    1
#define IDMA_IDMA_SMAC_INT_STAT_SET_0_COMPLETE_BIT    ((uint32_t)0x00000001)
#define IDMA_IDMA_SMAC_INT_STAT_SET_0_COMPLETE_POS    0

#define IDMA_IDMA_SMAC_INT_STAT_SET_5_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_5_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_5_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_5_COMPLETE_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_4_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_4_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_4_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_4_COMPLETE_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_3_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_3_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_3_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_3_COMPLETE_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_2_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_2_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_2_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_2_COMPLETE_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_1_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_1_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_1_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_1_COMPLETE_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_0_OVERWRITE_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_0_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_0_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_SMAC_INT_STAT_SET_0_COMPLETE_RST    0x0

__INLINE void idma_idma_smac_int_stat_unpack(uint8_t* set5_overwrite_err, uint8_t* set5_axi_wr_err, uint8_t* set5_axi_rd_err, uint8_t* set5_complete, uint8_t* set4_overwrite_err, uint8_t* set4_axi_wr_err, uint8_t* set4_axi_rd_err, uint8_t* set4_complete, uint8_t* set3_overwrite_err, uint8_t* set3_axi_wr_err, uint8_t* set3_axi_rd_err, uint8_t* set3_complete, uint8_t* set2_overwrite_err, uint8_t* set2_axi_wr_err, uint8_t* set2_axi_rd_err, uint8_t* set2_complete, uint8_t* set1_overwrite_err, uint8_t* set1_axi_wr_err, uint8_t* set1_axi_rd_err, uint8_t* set1_complete, uint8_t* set0_overwrite_err, uint8_t* set0_axi_wr_err, uint8_t* set0_axi_rd_err, uint8_t* set0_complete)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);

	*set5_overwrite_err = (localVal & ((uint32_t)0x00800000)) >>  23;
	*set5_axi_wr_err = (localVal & ((uint32_t)0x00400000)) >>  22;
	*set5_axi_rd_err = (localVal & ((uint32_t)0x00200000)) >>  21;
	*set5_complete = (localVal & ((uint32_t)0x00100000)) >>  20;
	*set4_overwrite_err = (localVal & ((uint32_t)0x00080000)) >>  19;
	*set4_axi_wr_err = (localVal & ((uint32_t)0x00040000)) >>  18;
	*set4_axi_rd_err = (localVal & ((uint32_t)0x00020000)) >>  17;
	*set4_complete = (localVal & ((uint32_t)0x00010000)) >>  16;
	*set3_overwrite_err = (localVal & ((uint32_t)0x00008000)) >>  15;
	*set3_axi_wr_err = (localVal & ((uint32_t)0x00004000)) >>  14;
	*set3_axi_rd_err = (localVal & ((uint32_t)0x00002000)) >>  13;
	*set3_complete = (localVal & ((uint32_t)0x00001000)) >>  12;
	*set2_overwrite_err = (localVal & ((uint32_t)0x00000800)) >>  11;
	*set2_axi_wr_err = (localVal & ((uint32_t)0x00000400)) >>  10;
	*set2_axi_rd_err = (localVal & ((uint32_t)0x00000200)) >>  9;
	*set2_complete = (localVal & ((uint32_t)0x00000100)) >>  8;
	*set1_overwrite_err = (localVal & ((uint32_t)0x00000080)) >>  7;
	*set1_axi_wr_err = (localVal & ((uint32_t)0x00000040)) >>  6;
	*set1_axi_rd_err = (localVal & ((uint32_t)0x00000020)) >>  5;
	*set1_complete = (localVal & ((uint32_t)0x00000010)) >>  4;
	*set0_overwrite_err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*set0_axi_wr_err = (localVal & ((uint32_t)0x00000004)) >>  2;
	*set0_axi_rd_err = (localVal & ((uint32_t)0x00000002)) >>  1;
	*set0_complete = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_smac_int_stat_set_5_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_5_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_5_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_5_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_4_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_4_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_4_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_4_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_3_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_3_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_3_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_3_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_2_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_2_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_2_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_2_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_1_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_1_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_1_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_1_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_0_overwrite_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_0_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_0_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t idma_idma_smac_int_stat_set_0_complete_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SMAC_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief IDMA_INT_CLR register definition
 *  Interrupt clear register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23    SET5_OVERWRITE_ERR_CLR    0              
 *    22    SET5_AXI_WR_ERR_CLR       0              
 *    21    SET5_AXI_RD_ERR_CLR       0              
 *    20    SET5_COMPLETE_CLR         0              
 *    19    SET4_OVERWRITE_ERR_CLR    0              
 *    18    SET4_AXI_WR_ERR_CLR       0              
 *    17    SET4_AXI_RD_ERR_CLR       0              
 *    16    SET4_COMPLETE_CLR         0              
 *    15    SET3_OVERWRITE_ERR_CLR    0              
 *    14    SET3_AXI_WR_ERR_CLR       0              
 *    13    SET3_AXI_RD_ERR_CLR       0              
 *    12    SET3_COMPLETE_CLR         0              
 *    11    SET2_OVERWRITE_ERR_CLR    0              
 *    10    SET2_AXI_WR_ERR_CLR       0              
 *    09    SET2_AXI_RD_ERR_CLR       0              
 *    08    SET2_COMPLETE_CLR         0              
 *    07    SET1_OVERWRITE_ERR_CLR    0              
 *    06    SET1_AXI_WR_ERR_CLR       0              
 *    05    SET1_AXI_RD_ERR_CLR       0              
 *    04    SET1_COMPLETE_CLR         0              
 *    03    SET0_OVERWRITE_ERR_CLR    0              
 *    02    SET0_AXI_WR_ERR_CLR       0              
 *    01    SET0_AXI_RD_ERR_CLR       0              
 *    00    SET0_COMPLETE_CLR         0              
 * </pre>
 */
#define IDMA_IDMA_INT_CLR_ADDR        (REG_IDMA_BASE_ADDR+0x00000024)
#define IDMA_IDMA_INT_CLR_OFFSET      0x00000024
#define IDMA_IDMA_INT_CLR_INDEX       0x00000009
#define IDMA_IDMA_INT_CLR_RESET       0x00000000

__INLINE void idma_idma_int_clr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_INT_CLR_SET_5_OVERWRITE_ERR_CLR_BIT    ((uint32_t)0x00800000)
#define IDMA_IDMA_INT_CLR_SET_5_OVERWRITE_ERR_CLR_POS    23
#define IDMA_IDMA_INT_CLR_SET_5_AXI_WR_ERR_CLR_BIT    ((uint32_t)0x00400000)
#define IDMA_IDMA_INT_CLR_SET_5_AXI_WR_ERR_CLR_POS    22
#define IDMA_IDMA_INT_CLR_SET_5_AXI_RD_ERR_CLR_BIT    ((uint32_t)0x00200000)
#define IDMA_IDMA_INT_CLR_SET_5_AXI_RD_ERR_CLR_POS    21
#define IDMA_IDMA_INT_CLR_SET_5_COMPLETE_CLR_BIT    ((uint32_t)0x00100000)
#define IDMA_IDMA_INT_CLR_SET_5_COMPLETE_CLR_POS    20
#define IDMA_IDMA_INT_CLR_SET_4_OVERWRITE_ERR_CLR_BIT    ((uint32_t)0x00080000)
#define IDMA_IDMA_INT_CLR_SET_4_OVERWRITE_ERR_CLR_POS    19
#define IDMA_IDMA_INT_CLR_SET_4_AXI_WR_ERR_CLR_BIT    ((uint32_t)0x00040000)
#define IDMA_IDMA_INT_CLR_SET_4_AXI_WR_ERR_CLR_POS    18
#define IDMA_IDMA_INT_CLR_SET_4_AXI_RD_ERR_CLR_BIT    ((uint32_t)0x00020000)
#define IDMA_IDMA_INT_CLR_SET_4_AXI_RD_ERR_CLR_POS    17
#define IDMA_IDMA_INT_CLR_SET_4_COMPLETE_CLR_BIT    ((uint32_t)0x00010000)
#define IDMA_IDMA_INT_CLR_SET_4_COMPLETE_CLR_POS    16
#define IDMA_IDMA_INT_CLR_SET_3_OVERWRITE_ERR_CLR_BIT    ((uint32_t)0x00008000)
#define IDMA_IDMA_INT_CLR_SET_3_OVERWRITE_ERR_CLR_POS    15
#define IDMA_IDMA_INT_CLR_SET_3_AXI_WR_ERR_CLR_BIT    ((uint32_t)0x00004000)
#define IDMA_IDMA_INT_CLR_SET_3_AXI_WR_ERR_CLR_POS    14
#define IDMA_IDMA_INT_CLR_SET_3_AXI_RD_ERR_CLR_BIT    ((uint32_t)0x00002000)
#define IDMA_IDMA_INT_CLR_SET_3_AXI_RD_ERR_CLR_POS    13
#define IDMA_IDMA_INT_CLR_SET_3_COMPLETE_CLR_BIT    ((uint32_t)0x00001000)
#define IDMA_IDMA_INT_CLR_SET_3_COMPLETE_CLR_POS    12
#define IDMA_IDMA_INT_CLR_SET_2_OVERWRITE_ERR_CLR_BIT    ((uint32_t)0x00000800)
#define IDMA_IDMA_INT_CLR_SET_2_OVERWRITE_ERR_CLR_POS    11
#define IDMA_IDMA_INT_CLR_SET_2_AXI_WR_ERR_CLR_BIT    ((uint32_t)0x00000400)
#define IDMA_IDMA_INT_CLR_SET_2_AXI_WR_ERR_CLR_POS    10
#define IDMA_IDMA_INT_CLR_SET_2_AXI_RD_ERR_CLR_BIT    ((uint32_t)0x00000200)
#define IDMA_IDMA_INT_CLR_SET_2_AXI_RD_ERR_CLR_POS    9
#define IDMA_IDMA_INT_CLR_SET_2_COMPLETE_CLR_BIT    ((uint32_t)0x00000100)
#define IDMA_IDMA_INT_CLR_SET_2_COMPLETE_CLR_POS    8
#define IDMA_IDMA_INT_CLR_SET_1_OVERWRITE_ERR_CLR_BIT    ((uint32_t)0x00000080)
#define IDMA_IDMA_INT_CLR_SET_1_OVERWRITE_ERR_CLR_POS    7
#define IDMA_IDMA_INT_CLR_SET_1_AXI_WR_ERR_CLR_BIT    ((uint32_t)0x00000040)
#define IDMA_IDMA_INT_CLR_SET_1_AXI_WR_ERR_CLR_POS    6
#define IDMA_IDMA_INT_CLR_SET_1_AXI_RD_ERR_CLR_BIT    ((uint32_t)0x00000020)
#define IDMA_IDMA_INT_CLR_SET_1_AXI_RD_ERR_CLR_POS    5
#define IDMA_IDMA_INT_CLR_SET_1_COMPLETE_CLR_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_INT_CLR_SET_1_COMPLETE_CLR_POS    4
#define IDMA_IDMA_INT_CLR_SET_0_OVERWRITE_ERR_CLR_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_INT_CLR_SET_0_OVERWRITE_ERR_CLR_POS    3
#define IDMA_IDMA_INT_CLR_SET_0_AXI_WR_ERR_CLR_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_INT_CLR_SET_0_AXI_WR_ERR_CLR_POS    2
#define IDMA_IDMA_INT_CLR_SET_0_AXI_RD_ERR_CLR_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_INT_CLR_SET_0_AXI_RD_ERR_CLR_POS    1
#define IDMA_IDMA_INT_CLR_SET_0_COMPLETE_CLR_BIT    ((uint32_t)0x00000001)
#define IDMA_IDMA_INT_CLR_SET_0_COMPLETE_CLR_POS    0

#define IDMA_IDMA_INT_CLR_SET_5_OVERWRITE_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_5_AXI_WR_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_5_AXI_RD_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_5_COMPLETE_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_4_OVERWRITE_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_4_AXI_WR_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_4_AXI_RD_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_4_COMPLETE_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_3_OVERWRITE_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_3_AXI_WR_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_3_AXI_RD_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_3_COMPLETE_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_2_OVERWRITE_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_2_AXI_WR_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_2_AXI_RD_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_2_COMPLETE_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_1_OVERWRITE_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_1_AXI_WR_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_1_AXI_RD_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_1_COMPLETE_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_0_OVERWRITE_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_0_AXI_WR_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_0_AXI_RD_ERR_CLR_RST    0x0
#define IDMA_IDMA_INT_CLR_SET_0_COMPLETE_CLR_RST    0x0

__INLINE void idma_idma_int_clr_pack(uint8_t set5_overwrite_err_clr, uint8_t set5_axi_wr_err_clr, uint8_t set5_axi_rd_err_clr, uint8_t set5_complete_clr, uint8_t set4_overwrite_err_clr, uint8_t set4_axi_wr_err_clr, uint8_t set4_axi_rd_err_clr, uint8_t set4_complete_clr, uint8_t set3_overwrite_err_clr, uint8_t set3_axi_wr_err_clr, uint8_t set3_axi_rd_err_clr, uint8_t set3_complete_clr, uint8_t set2_overwrite_err_clr, uint8_t set2_axi_wr_err_clr, uint8_t set2_axi_rd_err_clr, uint8_t set2_complete_clr, uint8_t set1_overwrite_err_clr, uint8_t set1_axi_wr_err_clr, uint8_t set1_axi_rd_err_clr, uint8_t set1_complete_clr, uint8_t set0_overwrite_err_clr, uint8_t set0_axi_wr_err_clr, uint8_t set0_axi_rd_err_clr, uint8_t set0_complete_clr)
{
	ASSERT_ERR((((uint32_t)set5_overwrite_err_clr << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)set5_axi_wr_err_clr << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)set5_axi_rd_err_clr << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)set5_complete_clr << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)set4_overwrite_err_clr << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)set4_axi_wr_err_clr << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)set4_axi_rd_err_clr << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)set4_complete_clr << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)set3_overwrite_err_clr << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)set3_axi_wr_err_clr << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)set3_axi_rd_err_clr << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)set3_complete_clr << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)set2_overwrite_err_clr << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)set2_axi_wr_err_clr << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)set2_axi_rd_err_clr << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)set2_complete_clr << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)set1_overwrite_err_clr << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)set1_axi_wr_err_clr << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)set1_axi_rd_err_clr << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)set1_complete_clr << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)set0_overwrite_err_clr << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)set0_axi_wr_err_clr << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)set0_axi_rd_err_clr << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)set0_complete_clr << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR,  ((uint32_t)set5_overwrite_err_clr << 23) |((uint32_t)set5_axi_wr_err_clr << 22) |((uint32_t)set5_axi_rd_err_clr << 21) |((uint32_t)set5_complete_clr << 20) |((uint32_t)set4_overwrite_err_clr << 19) |((uint32_t)set4_axi_wr_err_clr << 18) |((uint32_t)set4_axi_rd_err_clr << 17) |((uint32_t)set4_complete_clr << 16) |((uint32_t)set3_overwrite_err_clr << 15) |((uint32_t)set3_axi_wr_err_clr << 14) |((uint32_t)set3_axi_rd_err_clr << 13) |((uint32_t)set3_complete_clr << 12) |((uint32_t)set2_overwrite_err_clr << 11) |((uint32_t)set2_axi_wr_err_clr << 10) |((uint32_t)set2_axi_rd_err_clr << 9) |((uint32_t)set2_complete_clr << 8) |((uint32_t)set1_overwrite_err_clr << 7) |((uint32_t)set1_axi_wr_err_clr << 6) |((uint32_t)set1_axi_rd_err_clr << 5) |((uint32_t)set1_complete_clr << 4) |((uint32_t)set0_overwrite_err_clr << 3) |((uint32_t)set0_axi_wr_err_clr << 2) |((uint32_t)set0_axi_rd_err_clr << 1) |((uint32_t)set0_complete_clr << 0));
}

__INLINE void idma_idma_int_clr_set_5_overwrite_err_clr_setf(uint8_t set5overwriteerrclr)
{
	ASSERT_ERR((((uint32_t)set5overwriteerrclr << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)set5overwriteerrclr <<23));
}
__INLINE void idma_idma_int_clr_set_5_axi_wr_err_clr_setf(uint8_t set5axiwrerrclr)
{
	ASSERT_ERR((((uint32_t)set5axiwrerrclr << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)set5axiwrerrclr <<22));
}
__INLINE void idma_idma_int_clr_set_5_axi_rd_err_clr_setf(uint8_t set5axirderrclr)
{
	ASSERT_ERR((((uint32_t)set5axirderrclr << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)set5axirderrclr <<21));
}
__INLINE void idma_idma_int_clr_set_5_complete_clr_setf(uint8_t set5completeclr)
{
	ASSERT_ERR((((uint32_t)set5completeclr << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)set5completeclr <<20));
}
__INLINE void idma_idma_int_clr_set_4_overwrite_err_clr_setf(uint8_t set4overwriteerrclr)
{
	ASSERT_ERR((((uint32_t)set4overwriteerrclr << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)set4overwriteerrclr <<19));
}
__INLINE void idma_idma_int_clr_set_4_axi_wr_err_clr_setf(uint8_t set4axiwrerrclr)
{
	ASSERT_ERR((((uint32_t)set4axiwrerrclr << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)set4axiwrerrclr <<18));
}
__INLINE void idma_idma_int_clr_set_4_axi_rd_err_clr_setf(uint8_t set4axirderrclr)
{
	ASSERT_ERR((((uint32_t)set4axirderrclr << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)set4axirderrclr <<17));
}
__INLINE void idma_idma_int_clr_set_4_complete_clr_setf(uint8_t set4completeclr)
{
	ASSERT_ERR((((uint32_t)set4completeclr << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)set4completeclr <<16));
}
__INLINE void idma_idma_int_clr_set_3_overwrite_err_clr_setf(uint8_t set3overwriteerrclr)
{
	ASSERT_ERR((((uint32_t)set3overwriteerrclr << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)set3overwriteerrclr <<15));
}
__INLINE void idma_idma_int_clr_set_3_axi_wr_err_clr_setf(uint8_t set3axiwrerrclr)
{
	ASSERT_ERR((((uint32_t)set3axiwrerrclr << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)set3axiwrerrclr <<14));
}
__INLINE void idma_idma_int_clr_set_3_axi_rd_err_clr_setf(uint8_t set3axirderrclr)
{
	ASSERT_ERR((((uint32_t)set3axirderrclr << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)set3axirderrclr <<13));
}
__INLINE void idma_idma_int_clr_set_3_complete_clr_setf(uint8_t set3completeclr)
{
	ASSERT_ERR((((uint32_t)set3completeclr << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)set3completeclr <<12));
}
__INLINE void idma_idma_int_clr_set_2_overwrite_err_clr_setf(uint8_t set2overwriteerrclr)
{
	ASSERT_ERR((((uint32_t)set2overwriteerrclr << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)set2overwriteerrclr <<11));
}
__INLINE void idma_idma_int_clr_set_2_axi_wr_err_clr_setf(uint8_t set2axiwrerrclr)
{
	ASSERT_ERR((((uint32_t)set2axiwrerrclr << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)set2axiwrerrclr <<10));
}
__INLINE void idma_idma_int_clr_set_2_axi_rd_err_clr_setf(uint8_t set2axirderrclr)
{
	ASSERT_ERR((((uint32_t)set2axirderrclr << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)set2axirderrclr <<9));
}
__INLINE void idma_idma_int_clr_set_2_complete_clr_setf(uint8_t set2completeclr)
{
	ASSERT_ERR((((uint32_t)set2completeclr << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)set2completeclr <<8));
}
__INLINE void idma_idma_int_clr_set_1_overwrite_err_clr_setf(uint8_t set1overwriteerrclr)
{
	ASSERT_ERR((((uint32_t)set1overwriteerrclr << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)set1overwriteerrclr <<7));
}
__INLINE void idma_idma_int_clr_set_1_axi_wr_err_clr_setf(uint8_t set1axiwrerrclr)
{
	ASSERT_ERR((((uint32_t)set1axiwrerrclr << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)set1axiwrerrclr <<6));
}
__INLINE void idma_idma_int_clr_set_1_axi_rd_err_clr_setf(uint8_t set1axirderrclr)
{
	ASSERT_ERR((((uint32_t)set1axirderrclr << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)set1axirderrclr <<5));
}
__INLINE void idma_idma_int_clr_set_1_complete_clr_setf(uint8_t set1completeclr)
{
	ASSERT_ERR((((uint32_t)set1completeclr << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)set1completeclr <<4));
}
__INLINE void idma_idma_int_clr_set_0_overwrite_err_clr_setf(uint8_t set0overwriteerrclr)
{
	ASSERT_ERR((((uint32_t)set0overwriteerrclr << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)set0overwriteerrclr <<3));
}
__INLINE void idma_idma_int_clr_set_0_axi_wr_err_clr_setf(uint8_t set0axiwrerrclr)
{
	ASSERT_ERR((((uint32_t)set0axiwrerrclr << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)set0axiwrerrclr <<2));
}
__INLINE void idma_idma_int_clr_set_0_axi_rd_err_clr_setf(uint8_t set0axirderrclr)
{
	ASSERT_ERR((((uint32_t)set0axirderrclr << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)set0axirderrclr <<1));
}
__INLINE void idma_idma_int_clr_set_0_complete_clr_setf(uint8_t set0completeclr)
{
	ASSERT_ERR((((uint32_t)set0completeclr << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_CLR_ADDR, (REG_PL_RD(IDMA_IDMA_INT_CLR_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)set0completeclr <<0));
}

/**
 * @brief IDMA_INT_FORCE register definition
 *  Force interrupt for debug register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23    SET5_OVERWRITE_ERR_FORCE  0              
 *    22    SET5_AXI_WR_ERR_FORCE     0              
 *    21    SET5_AXI_RD_ERR_FORCE     0              
 *    20    SET5_COMPLETE_FORCE       0              
 *    19    SET4_OVERWRITE_ERR_FORCE  0              
 *    18    SET4_AXI_WR_ERR_FORCE     0              
 *    17    SET4_AXI_RD_ERR_FORCE     0              
 *    16    SET4_COMPLETE_FORCE       0              
 *    15    SET3_OVERWRITE_ERR_FORCE  0              
 *    14    SET3_AXI_WR_ERR_FORCE     0              
 *    13    SET3_AXI_RD_ERR_FORCE     0              
 *    12    SET3_COMPLETE_FORCE       0              
 *    11    SET2_OVERWRITE_ERR_FORCE  0              
 *    10    SET2_AXI_WR_ERR_FORCE     0              
 *    09    SET2_AXI_RD_ERR_FORCE     0              
 *    08    SET2_COMPLETE_FORCE       0              
 *    07    SET1_OVERWRITE_ERR_FORCE  0              
 *    06    SET1_AXI_WR_ERR_FORCE     0              
 *    05    SET1_AXI_RD_ERR_FORCE     0              
 *    04    SET1_COMPLETE_FORCE       0              
 *    03    SET0_OVERWRITE_ERR_FORCE  0              
 *    02    SET0_AXI_WR_ERR_FORCE     0              
 *    01    SET0_AXI_RD_ERR_FORCE     0              
 *    00    SET0_COMPLETE_FORCE       0              
 * </pre>
 */
#define IDMA_IDMA_INT_FORCE_ADDR        (REG_IDMA_BASE_ADDR+0x00000028)
#define IDMA_IDMA_INT_FORCE_OFFSET      0x00000028
#define IDMA_IDMA_INT_FORCE_INDEX       0x0000000A
#define IDMA_IDMA_INT_FORCE_RESET       0x00000000

__INLINE void idma_idma_int_force_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, value);
}

// field definitions
#define IDMA_IDMA_INT_FORCE_SET_5_OVERWRITE_ERR_FORCE_BIT    ((uint32_t)0x00800000)
#define IDMA_IDMA_INT_FORCE_SET_5_OVERWRITE_ERR_FORCE_POS    23
#define IDMA_IDMA_INT_FORCE_SET_5_AXI_WR_ERR_FORCE_BIT    ((uint32_t)0x00400000)
#define IDMA_IDMA_INT_FORCE_SET_5_AXI_WR_ERR_FORCE_POS    22
#define IDMA_IDMA_INT_FORCE_SET_5_AXI_RD_ERR_FORCE_BIT    ((uint32_t)0x00200000)
#define IDMA_IDMA_INT_FORCE_SET_5_AXI_RD_ERR_FORCE_POS    21
#define IDMA_IDMA_INT_FORCE_SET_5_COMPLETE_FORCE_BIT    ((uint32_t)0x00100000)
#define IDMA_IDMA_INT_FORCE_SET_5_COMPLETE_FORCE_POS    20
#define IDMA_IDMA_INT_FORCE_SET_4_OVERWRITE_ERR_FORCE_BIT    ((uint32_t)0x00080000)
#define IDMA_IDMA_INT_FORCE_SET_4_OVERWRITE_ERR_FORCE_POS    19
#define IDMA_IDMA_INT_FORCE_SET_4_AXI_WR_ERR_FORCE_BIT    ((uint32_t)0x00040000)
#define IDMA_IDMA_INT_FORCE_SET_4_AXI_WR_ERR_FORCE_POS    18
#define IDMA_IDMA_INT_FORCE_SET_4_AXI_RD_ERR_FORCE_BIT    ((uint32_t)0x00020000)
#define IDMA_IDMA_INT_FORCE_SET_4_AXI_RD_ERR_FORCE_POS    17
#define IDMA_IDMA_INT_FORCE_SET_4_COMPLETE_FORCE_BIT    ((uint32_t)0x00010000)
#define IDMA_IDMA_INT_FORCE_SET_4_COMPLETE_FORCE_POS    16
#define IDMA_IDMA_INT_FORCE_SET_3_OVERWRITE_ERR_FORCE_BIT    ((uint32_t)0x00008000)
#define IDMA_IDMA_INT_FORCE_SET_3_OVERWRITE_ERR_FORCE_POS    15
#define IDMA_IDMA_INT_FORCE_SET_3_AXI_WR_ERR_FORCE_BIT    ((uint32_t)0x00004000)
#define IDMA_IDMA_INT_FORCE_SET_3_AXI_WR_ERR_FORCE_POS    14
#define IDMA_IDMA_INT_FORCE_SET_3_AXI_RD_ERR_FORCE_BIT    ((uint32_t)0x00002000)
#define IDMA_IDMA_INT_FORCE_SET_3_AXI_RD_ERR_FORCE_POS    13
#define IDMA_IDMA_INT_FORCE_SET_3_COMPLETE_FORCE_BIT    ((uint32_t)0x00001000)
#define IDMA_IDMA_INT_FORCE_SET_3_COMPLETE_FORCE_POS    12
#define IDMA_IDMA_INT_FORCE_SET_2_OVERWRITE_ERR_FORCE_BIT    ((uint32_t)0x00000800)
#define IDMA_IDMA_INT_FORCE_SET_2_OVERWRITE_ERR_FORCE_POS    11
#define IDMA_IDMA_INT_FORCE_SET_2_AXI_WR_ERR_FORCE_BIT    ((uint32_t)0x00000400)
#define IDMA_IDMA_INT_FORCE_SET_2_AXI_WR_ERR_FORCE_POS    10
#define IDMA_IDMA_INT_FORCE_SET_2_AXI_RD_ERR_FORCE_BIT    ((uint32_t)0x00000200)
#define IDMA_IDMA_INT_FORCE_SET_2_AXI_RD_ERR_FORCE_POS    9
#define IDMA_IDMA_INT_FORCE_SET_2_COMPLETE_FORCE_BIT    ((uint32_t)0x00000100)
#define IDMA_IDMA_INT_FORCE_SET_2_COMPLETE_FORCE_POS    8
#define IDMA_IDMA_INT_FORCE_SET_1_OVERWRITE_ERR_FORCE_BIT    ((uint32_t)0x00000080)
#define IDMA_IDMA_INT_FORCE_SET_1_OVERWRITE_ERR_FORCE_POS    7
#define IDMA_IDMA_INT_FORCE_SET_1_AXI_WR_ERR_FORCE_BIT    ((uint32_t)0x00000040)
#define IDMA_IDMA_INT_FORCE_SET_1_AXI_WR_ERR_FORCE_POS    6
#define IDMA_IDMA_INT_FORCE_SET_1_AXI_RD_ERR_FORCE_BIT    ((uint32_t)0x00000020)
#define IDMA_IDMA_INT_FORCE_SET_1_AXI_RD_ERR_FORCE_POS    5
#define IDMA_IDMA_INT_FORCE_SET_1_COMPLETE_FORCE_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_INT_FORCE_SET_1_COMPLETE_FORCE_POS    4
#define IDMA_IDMA_INT_FORCE_SET_0_OVERWRITE_ERR_FORCE_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_INT_FORCE_SET_0_OVERWRITE_ERR_FORCE_POS    3
#define IDMA_IDMA_INT_FORCE_SET_0_AXI_WR_ERR_FORCE_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_INT_FORCE_SET_0_AXI_WR_ERR_FORCE_POS    2
#define IDMA_IDMA_INT_FORCE_SET_0_AXI_RD_ERR_FORCE_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_INT_FORCE_SET_0_AXI_RD_ERR_FORCE_POS    1
#define IDMA_IDMA_INT_FORCE_SET_0_COMPLETE_FORCE_BIT    ((uint32_t)0x00000001)
#define IDMA_IDMA_INT_FORCE_SET_0_COMPLETE_FORCE_POS    0

#define IDMA_IDMA_INT_FORCE_SET_5_OVERWRITE_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_5_AXI_WR_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_5_AXI_RD_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_5_COMPLETE_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_4_OVERWRITE_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_4_AXI_WR_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_4_AXI_RD_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_4_COMPLETE_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_3_OVERWRITE_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_3_AXI_WR_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_3_AXI_RD_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_3_COMPLETE_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_2_OVERWRITE_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_2_AXI_WR_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_2_AXI_RD_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_2_COMPLETE_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_1_OVERWRITE_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_1_AXI_WR_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_1_AXI_RD_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_1_COMPLETE_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_0_OVERWRITE_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_0_AXI_WR_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_0_AXI_RD_ERR_FORCE_RST    0x0
#define IDMA_IDMA_INT_FORCE_SET_0_COMPLETE_FORCE_RST    0x0

__INLINE void idma_idma_int_force_pack(uint8_t set5_overwrite_err_force, uint8_t set5_axi_wr_err_force, uint8_t set5_axi_rd_err_force, uint8_t set5_complete_force, uint8_t set4_overwrite_err_force, uint8_t set4_axi_wr_err_force, uint8_t set4_axi_rd_err_force, uint8_t set4_complete_force, uint8_t set3_overwrite_err_force, uint8_t set3_axi_wr_err_force, uint8_t set3_axi_rd_err_force, uint8_t set3_complete_force, uint8_t set2_overwrite_err_force, uint8_t set2_axi_wr_err_force, uint8_t set2_axi_rd_err_force, uint8_t set2_complete_force, uint8_t set1_overwrite_err_force, uint8_t set1_axi_wr_err_force, uint8_t set1_axi_rd_err_force, uint8_t set1_complete_force, uint8_t set0_overwrite_err_force, uint8_t set0_axi_wr_err_force, uint8_t set0_axi_rd_err_force, uint8_t set0_complete_force)
{
	ASSERT_ERR((((uint32_t)set5_overwrite_err_force << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)set5_axi_wr_err_force << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)set5_axi_rd_err_force << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)set5_complete_force << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)set4_overwrite_err_force << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)set4_axi_wr_err_force << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)set4_axi_rd_err_force << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)set4_complete_force << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)set3_overwrite_err_force << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)set3_axi_wr_err_force << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)set3_axi_rd_err_force << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)set3_complete_force << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)set2_overwrite_err_force << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)set2_axi_wr_err_force << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)set2_axi_rd_err_force << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)set2_complete_force << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)set1_overwrite_err_force << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)set1_axi_wr_err_force << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)set1_axi_rd_err_force << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)set1_complete_force << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)set0_overwrite_err_force << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)set0_axi_wr_err_force << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)set0_axi_rd_err_force << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)set0_complete_force << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR,  ((uint32_t)set5_overwrite_err_force << 23) |((uint32_t)set5_axi_wr_err_force << 22) |((uint32_t)set5_axi_rd_err_force << 21) |((uint32_t)set5_complete_force << 20) |((uint32_t)set4_overwrite_err_force << 19) |((uint32_t)set4_axi_wr_err_force << 18) |((uint32_t)set4_axi_rd_err_force << 17) |((uint32_t)set4_complete_force << 16) |((uint32_t)set3_overwrite_err_force << 15) |((uint32_t)set3_axi_wr_err_force << 14) |((uint32_t)set3_axi_rd_err_force << 13) |((uint32_t)set3_complete_force << 12) |((uint32_t)set2_overwrite_err_force << 11) |((uint32_t)set2_axi_wr_err_force << 10) |((uint32_t)set2_axi_rd_err_force << 9) |((uint32_t)set2_complete_force << 8) |((uint32_t)set1_overwrite_err_force << 7) |((uint32_t)set1_axi_wr_err_force << 6) |((uint32_t)set1_axi_rd_err_force << 5) |((uint32_t)set1_complete_force << 4) |((uint32_t)set0_overwrite_err_force << 3) |((uint32_t)set0_axi_wr_err_force << 2) |((uint32_t)set0_axi_rd_err_force << 1) |((uint32_t)set0_complete_force << 0));
}

__INLINE void idma_idma_int_force_set_5_overwrite_err_force_setf(uint8_t set5overwriteerrforce)
{
	ASSERT_ERR((((uint32_t)set5overwriteerrforce << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)set5overwriteerrforce <<23));
}
__INLINE void idma_idma_int_force_set_5_axi_wr_err_force_setf(uint8_t set5axiwrerrforce)
{
	ASSERT_ERR((((uint32_t)set5axiwrerrforce << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)set5axiwrerrforce <<22));
}
__INLINE void idma_idma_int_force_set_5_axi_rd_err_force_setf(uint8_t set5axirderrforce)
{
	ASSERT_ERR((((uint32_t)set5axirderrforce << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)set5axirderrforce <<21));
}
__INLINE void idma_idma_int_force_set_5_complete_force_setf(uint8_t set5completeforce)
{
	ASSERT_ERR((((uint32_t)set5completeforce << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)set5completeforce <<20));
}
__INLINE void idma_idma_int_force_set_4_overwrite_err_force_setf(uint8_t set4overwriteerrforce)
{
	ASSERT_ERR((((uint32_t)set4overwriteerrforce << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)set4overwriteerrforce <<19));
}
__INLINE void idma_idma_int_force_set_4_axi_wr_err_force_setf(uint8_t set4axiwrerrforce)
{
	ASSERT_ERR((((uint32_t)set4axiwrerrforce << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)set4axiwrerrforce <<18));
}
__INLINE void idma_idma_int_force_set_4_axi_rd_err_force_setf(uint8_t set4axirderrforce)
{
	ASSERT_ERR((((uint32_t)set4axirderrforce << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)set4axirderrforce <<17));
}
__INLINE void idma_idma_int_force_set_4_complete_force_setf(uint8_t set4completeforce)
{
	ASSERT_ERR((((uint32_t)set4completeforce << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)set4completeforce <<16));
}
__INLINE void idma_idma_int_force_set_3_overwrite_err_force_setf(uint8_t set3overwriteerrforce)
{
	ASSERT_ERR((((uint32_t)set3overwriteerrforce << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)set3overwriteerrforce <<15));
}
__INLINE void idma_idma_int_force_set_3_axi_wr_err_force_setf(uint8_t set3axiwrerrforce)
{
	ASSERT_ERR((((uint32_t)set3axiwrerrforce << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)set3axiwrerrforce <<14));
}
__INLINE void idma_idma_int_force_set_3_axi_rd_err_force_setf(uint8_t set3axirderrforce)
{
	ASSERT_ERR((((uint32_t)set3axirderrforce << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)set3axirderrforce <<13));
}
__INLINE void idma_idma_int_force_set_3_complete_force_setf(uint8_t set3completeforce)
{
	ASSERT_ERR((((uint32_t)set3completeforce << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)set3completeforce <<12));
}
__INLINE void idma_idma_int_force_set_2_overwrite_err_force_setf(uint8_t set2overwriteerrforce)
{
	ASSERT_ERR((((uint32_t)set2overwriteerrforce << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)set2overwriteerrforce <<11));
}
__INLINE void idma_idma_int_force_set_2_axi_wr_err_force_setf(uint8_t set2axiwrerrforce)
{
	ASSERT_ERR((((uint32_t)set2axiwrerrforce << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)set2axiwrerrforce <<10));
}
__INLINE void idma_idma_int_force_set_2_axi_rd_err_force_setf(uint8_t set2axirderrforce)
{
	ASSERT_ERR((((uint32_t)set2axirderrforce << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)set2axirderrforce <<9));
}
__INLINE void idma_idma_int_force_set_2_complete_force_setf(uint8_t set2completeforce)
{
	ASSERT_ERR((((uint32_t)set2completeforce << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)set2completeforce <<8));
}
__INLINE void idma_idma_int_force_set_1_overwrite_err_force_setf(uint8_t set1overwriteerrforce)
{
	ASSERT_ERR((((uint32_t)set1overwriteerrforce << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)set1overwriteerrforce <<7));
}
__INLINE void idma_idma_int_force_set_1_axi_wr_err_force_setf(uint8_t set1axiwrerrforce)
{
	ASSERT_ERR((((uint32_t)set1axiwrerrforce << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)set1axiwrerrforce <<6));
}
__INLINE void idma_idma_int_force_set_1_axi_rd_err_force_setf(uint8_t set1axirderrforce)
{
	ASSERT_ERR((((uint32_t)set1axirderrforce << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)set1axirderrforce <<5));
}
__INLINE void idma_idma_int_force_set_1_complete_force_setf(uint8_t set1completeforce)
{
	ASSERT_ERR((((uint32_t)set1completeforce << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)set1completeforce <<4));
}
__INLINE void idma_idma_int_force_set_0_overwrite_err_force_setf(uint8_t set0overwriteerrforce)
{
	ASSERT_ERR((((uint32_t)set0overwriteerrforce << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)set0overwriteerrforce <<3));
}
__INLINE void idma_idma_int_force_set_0_axi_wr_err_force_setf(uint8_t set0axiwrerrforce)
{
	ASSERT_ERR((((uint32_t)set0axiwrerrforce << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)set0axiwrerrforce <<2));
}
__INLINE void idma_idma_int_force_set_0_axi_rd_err_force_setf(uint8_t set0axirderrforce)
{
	ASSERT_ERR((((uint32_t)set0axirderrforce << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)set0axirderrforce <<1));
}
__INLINE void idma_idma_int_force_set_0_complete_force_setf(uint8_t set0completeforce)
{
	ASSERT_ERR((((uint32_t)set0completeforce << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IDMA_IDMA_INT_FORCE_ADDR, (REG_PL_RD(IDMA_IDMA_INT_FORCE_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)set0completeforce <<0));
}

/**
 * @brief IDMA_SET_0_SOURCE_ADDR register definition
 *  Set0 DMA source address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SOURCE_ADDR               0x0
 * </pre>
 */
#define IDMA_IDMA_SET_0_SOURCE_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x00000030)
#define IDMA_IDMA_SET_0_SOURCE_ADDR_OFFSET      0x00000030
#define IDMA_IDMA_SET_0_SOURCE_ADDR_INDEX       0x0000000C
#define IDMA_IDMA_SET_0_SOURCE_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_0_source_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_0_SOURCE_ADDR_ADDR);
}

__INLINE void idma_idma_set_0_source_addr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_0_SOURCE_ADDR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_0_SOURCE_ADDR_SOURCE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_0_SOURCE_ADDR_SOURCE_ADDR_LSB    0
#define IDMA_IDMA_SET_0_SOURCE_ADDR_SOURCE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_0_SOURCE_ADDR_SOURCE_ADDR_RST    0x0

__INLINE uint32_t idma_idma_set_0_source_addr_source_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_0_SOURCE_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_0_source_addr_source_addr_setf(uint32_t sourceaddr)
{
	ASSERT_ERR((((uint32_t)sourceaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_0_SOURCE_ADDR_ADDR, (uint32_t)sourceaddr << 0);
}

/**
 * @brief IDMA_SET_0_DEST_ADDR register definition
 *  Set0 DMA destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DEST_ADDR                 0x0
 * </pre>
 */
#define IDMA_IDMA_SET_0_DEST_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x00000034)
#define IDMA_IDMA_SET_0_DEST_ADDR_OFFSET      0x00000034
#define IDMA_IDMA_SET_0_DEST_ADDR_INDEX       0x0000000D
#define IDMA_IDMA_SET_0_DEST_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_0_dest_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_0_DEST_ADDR_ADDR);
}

__INLINE void idma_idma_set_0_dest_addr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_0_DEST_ADDR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_0_DEST_ADDR_DEST_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_0_DEST_ADDR_DEST_ADDR_LSB    0
#define IDMA_IDMA_SET_0_DEST_ADDR_DEST_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_0_DEST_ADDR_DEST_ADDR_RST    0x0

__INLINE uint32_t idma_idma_set_0_dest_addr_dest_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_0_DEST_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_0_dest_addr_dest_addr_setf(uint32_t destaddr)
{
	ASSERT_ERR((((uint32_t)destaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_0_DEST_ADDR_ADDR, (uint32_t)destaddr << 0);
}

/**
 * @brief IDMA_SET_0_INFO register definition
 *  Set0 DMA info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 SIZE                      0x0
 * </pre>
 */
#define IDMA_IDMA_SET_0_INFO_ADDR        (REG_IDMA_BASE_ADDR+0x00000038)
#define IDMA_IDMA_SET_0_INFO_OFFSET      0x00000038
#define IDMA_IDMA_SET_0_INFO_INDEX       0x0000000E
#define IDMA_IDMA_SET_0_INFO_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_0_info_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_0_INFO_ADDR);
}

__INLINE void idma_idma_set_0_info_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_0_INFO_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_0_INFO_SIZE_MASK      ((uint32_t)0x0000FFFF)
#define IDMA_IDMA_SET_0_INFO_SIZE_LSB       0
#define IDMA_IDMA_SET_0_INFO_SIZE_WIDTH     ((uint32_t)0x00000010)

#define IDMA_IDMA_SET_0_INFO_SIZE_RST       0x0

__INLINE uint16_t idma_idma_set_0_info_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_0_INFO_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void idma_idma_set_0_info_size_setf(uint16_t size)
{
	ASSERT_ERR((((uint32_t)size << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_0_INFO_ADDR, (uint32_t)size << 0);
}

/**
 * @brief IDMA_SET_0_STATUS register definition
 *  Set0 DMA status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    REQ_FIFO_OF_ERR           0              
 *    03    AXI_WR_ERR                0              
 *    02    AXI_RD_ERR                0              
 *    01    REQUEST                   0              
 *    00    BUSY                      0              
 * </pre>
 */
#define IDMA_IDMA_SET_0_STATUS_ADDR        (REG_IDMA_BASE_ADDR+0x0000003C)
#define IDMA_IDMA_SET_0_STATUS_OFFSET      0x0000003C
#define IDMA_IDMA_SET_0_STATUS_INDEX       0x0000000F
#define IDMA_IDMA_SET_0_STATUS_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_0_status_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_0_STATUS_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_0_STATUS_REQ_FIFO_OF_ERR_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_SET_0_STATUS_REQ_FIFO_OF_ERR_POS    4
#define IDMA_IDMA_SET_0_STATUS_AXI_WR_ERR_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_SET_0_STATUS_AXI_WR_ERR_POS    3
#define IDMA_IDMA_SET_0_STATUS_AXI_RD_ERR_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_SET_0_STATUS_AXI_RD_ERR_POS    2
#define IDMA_IDMA_SET_0_STATUS_REQUEST_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_SET_0_STATUS_REQUEST_POS    1
#define IDMA_IDMA_SET_0_STATUS_BUSY_BIT     ((uint32_t)0x00000001)
#define IDMA_IDMA_SET_0_STATUS_BUSY_POS     0

#define IDMA_IDMA_SET_0_STATUS_REQ_FIFO_OF_ERR_RST    0x0
#define IDMA_IDMA_SET_0_STATUS_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_SET_0_STATUS_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_SET_0_STATUS_REQUEST_RST    0x0
#define IDMA_IDMA_SET_0_STATUS_BUSY_RST     0x0

__INLINE void idma_idma_set_0_status_unpack(uint8_t* req_fifo_of_err, uint8_t* axi_wr_err, uint8_t* axi_rd_err, uint8_t* request, uint8_t* busy)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_0_STATUS_ADDR);

	*req_fifo_of_err = (localVal & ((uint32_t)0x00000010)) >>  4;
	*axi_wr_err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*axi_rd_err = (localVal & ((uint32_t)0x00000004)) >>  2;
	*request = (localVal & ((uint32_t)0x00000002)) >>  1;
	*busy = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_set_0_status_req_fifo_of_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_0_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t idma_idma_set_0_status_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_0_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t idma_idma_set_0_status_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_0_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t idma_idma_set_0_status_request_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_0_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t idma_idma_set_0_status_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_0_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief IDMA_SET_1_SOURCE_ADDR register definition
 *  Set1 DMA source address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SOURCE_ADDR               0x0
 * </pre>
 */
#define IDMA_IDMA_SET_1_SOURCE_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x00000040)
#define IDMA_IDMA_SET_1_SOURCE_ADDR_OFFSET      0x00000040
#define IDMA_IDMA_SET_1_SOURCE_ADDR_INDEX       0x00000010
#define IDMA_IDMA_SET_1_SOURCE_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_1_source_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_1_SOURCE_ADDR_ADDR);
}

__INLINE void idma_idma_set_1_source_addr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_1_SOURCE_ADDR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_1_SOURCE_ADDR_SOURCE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_1_SOURCE_ADDR_SOURCE_ADDR_LSB    0
#define IDMA_IDMA_SET_1_SOURCE_ADDR_SOURCE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_1_SOURCE_ADDR_SOURCE_ADDR_RST    0x0

__INLINE uint32_t idma_idma_set_1_source_addr_source_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_1_SOURCE_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_1_source_addr_source_addr_setf(uint32_t sourceaddr)
{
	ASSERT_ERR((((uint32_t)sourceaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_1_SOURCE_ADDR_ADDR, (uint32_t)sourceaddr << 0);
}

/**
 * @brief IDMA_SET_1_DEST_ADDR register definition
 *  Set1 DMA destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DEST_ADDR                 0x0
 * </pre>
 */
#define IDMA_IDMA_SET_1_DEST_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x00000044)
#define IDMA_IDMA_SET_1_DEST_ADDR_OFFSET      0x00000044
#define IDMA_IDMA_SET_1_DEST_ADDR_INDEX       0x00000011
#define IDMA_IDMA_SET_1_DEST_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_1_dest_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_1_DEST_ADDR_ADDR);
}

__INLINE void idma_idma_set_1_dest_addr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_1_DEST_ADDR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_1_DEST_ADDR_DEST_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_1_DEST_ADDR_DEST_ADDR_LSB    0
#define IDMA_IDMA_SET_1_DEST_ADDR_DEST_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_1_DEST_ADDR_DEST_ADDR_RST    0x0

__INLINE uint32_t idma_idma_set_1_dest_addr_dest_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_1_DEST_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_1_dest_addr_dest_addr_setf(uint32_t destaddr)
{
	ASSERT_ERR((((uint32_t)destaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_1_DEST_ADDR_ADDR, (uint32_t)destaddr << 0);
}

/**
 * @brief IDMA_SET_1_INFO register definition
 *  Set1 DMA info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 SIZE                      0x0
 * </pre>
 */
#define IDMA_IDMA_SET_1_INFO_ADDR        (REG_IDMA_BASE_ADDR+0x00000048)
#define IDMA_IDMA_SET_1_INFO_OFFSET      0x00000048
#define IDMA_IDMA_SET_1_INFO_INDEX       0x00000012
#define IDMA_IDMA_SET_1_INFO_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_1_info_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_1_INFO_ADDR);
}

__INLINE void idma_idma_set_1_info_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_1_INFO_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_1_INFO_SIZE_MASK      ((uint32_t)0x0000FFFF)
#define IDMA_IDMA_SET_1_INFO_SIZE_LSB       0
#define IDMA_IDMA_SET_1_INFO_SIZE_WIDTH     ((uint32_t)0x00000010)

#define IDMA_IDMA_SET_1_INFO_SIZE_RST       0x0

__INLINE uint16_t idma_idma_set_1_info_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_1_INFO_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void idma_idma_set_1_info_size_setf(uint16_t size)
{
	ASSERT_ERR((((uint32_t)size << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_1_INFO_ADDR, (uint32_t)size << 0);
}

/**
 * @brief IDMA_SET_1_STATUS register definition
 *  Set1 DMA status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    REQ_FIFO_OF_ERR           0              
 *    03    AXI_WR_ERR                0              
 *    02    AXI_RD_ERR                0              
 *    01    REQUEST                   0              
 *    00    BUSY                      0              
 * </pre>
 */
#define IDMA_IDMA_SET_1_STATUS_ADDR        (REG_IDMA_BASE_ADDR+0x0000004C)
#define IDMA_IDMA_SET_1_STATUS_OFFSET      0x0000004C
#define IDMA_IDMA_SET_1_STATUS_INDEX       0x00000013
#define IDMA_IDMA_SET_1_STATUS_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_1_status_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_1_STATUS_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_1_STATUS_REQ_FIFO_OF_ERR_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_SET_1_STATUS_REQ_FIFO_OF_ERR_POS    4
#define IDMA_IDMA_SET_1_STATUS_AXI_WR_ERR_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_SET_1_STATUS_AXI_WR_ERR_POS    3
#define IDMA_IDMA_SET_1_STATUS_AXI_RD_ERR_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_SET_1_STATUS_AXI_RD_ERR_POS    2
#define IDMA_IDMA_SET_1_STATUS_REQUEST_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_SET_1_STATUS_REQUEST_POS    1
#define IDMA_IDMA_SET_1_STATUS_BUSY_BIT     ((uint32_t)0x00000001)
#define IDMA_IDMA_SET_1_STATUS_BUSY_POS     0

#define IDMA_IDMA_SET_1_STATUS_REQ_FIFO_OF_ERR_RST    0x0
#define IDMA_IDMA_SET_1_STATUS_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_SET_1_STATUS_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_SET_1_STATUS_REQUEST_RST    0x0
#define IDMA_IDMA_SET_1_STATUS_BUSY_RST     0x0

__INLINE void idma_idma_set_1_status_unpack(uint8_t* req_fifo_of_err, uint8_t* axi_wr_err, uint8_t* axi_rd_err, uint8_t* request, uint8_t* busy)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_1_STATUS_ADDR);

	*req_fifo_of_err = (localVal & ((uint32_t)0x00000010)) >>  4;
	*axi_wr_err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*axi_rd_err = (localVal & ((uint32_t)0x00000004)) >>  2;
	*request = (localVal & ((uint32_t)0x00000002)) >>  1;
	*busy = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_set_1_status_req_fifo_of_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_1_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t idma_idma_set_1_status_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_1_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t idma_idma_set_1_status_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_1_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t idma_idma_set_1_status_request_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_1_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t idma_idma_set_1_status_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_1_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief IDMA_SET_2_SOURCE_ADDR register definition
 *  Set2 DMA source address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SOURCE_ADDR               0x0
 * </pre>
 */
#define IDMA_IDMA_SET_2_SOURCE_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x00000050)
#define IDMA_IDMA_SET_2_SOURCE_ADDR_OFFSET      0x00000050
#define IDMA_IDMA_SET_2_SOURCE_ADDR_INDEX       0x00000014
#define IDMA_IDMA_SET_2_SOURCE_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_2_source_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_2_SOURCE_ADDR_ADDR);
}

__INLINE void idma_idma_set_2_source_addr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_2_SOURCE_ADDR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_2_SOURCE_ADDR_SOURCE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_2_SOURCE_ADDR_SOURCE_ADDR_LSB    0
#define IDMA_IDMA_SET_2_SOURCE_ADDR_SOURCE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_2_SOURCE_ADDR_SOURCE_ADDR_RST    0x0

__INLINE uint32_t idma_idma_set_2_source_addr_source_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_2_SOURCE_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_2_source_addr_source_addr_setf(uint32_t sourceaddr)
{
	ASSERT_ERR((((uint32_t)sourceaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_2_SOURCE_ADDR_ADDR, (uint32_t)sourceaddr << 0);
}

/**
 * @brief IDMA_SET_2_DEST_ADDR register definition
 *  Set2 DMA destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DEST_ADDR                 0x0
 * </pre>
 */
#define IDMA_IDMA_SET_2_DEST_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x00000054)
#define IDMA_IDMA_SET_2_DEST_ADDR_OFFSET      0x00000054
#define IDMA_IDMA_SET_2_DEST_ADDR_INDEX       0x00000015
#define IDMA_IDMA_SET_2_DEST_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_2_dest_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_2_DEST_ADDR_ADDR);
}

__INLINE void idma_idma_set_2_dest_addr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_2_DEST_ADDR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_2_DEST_ADDR_DEST_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_2_DEST_ADDR_DEST_ADDR_LSB    0
#define IDMA_IDMA_SET_2_DEST_ADDR_DEST_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_2_DEST_ADDR_DEST_ADDR_RST    0x0

__INLINE uint32_t idma_idma_set_2_dest_addr_dest_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_2_DEST_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_2_dest_addr_dest_addr_setf(uint32_t destaddr)
{
	ASSERT_ERR((((uint32_t)destaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_2_DEST_ADDR_ADDR, (uint32_t)destaddr << 0);
}

/**
 * @brief IDMA_SET_2_INFO register definition
 *  Set2 DMA info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 SIZE                      0x0
 * </pre>
 */
#define IDMA_IDMA_SET_2_INFO_ADDR        (REG_IDMA_BASE_ADDR+0x00000058)
#define IDMA_IDMA_SET_2_INFO_OFFSET      0x00000058
#define IDMA_IDMA_SET_2_INFO_INDEX       0x00000016
#define IDMA_IDMA_SET_2_INFO_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_2_info_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_2_INFO_ADDR);
}

__INLINE void idma_idma_set_2_info_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_2_INFO_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_2_INFO_SIZE_MASK      ((uint32_t)0x0000FFFF)
#define IDMA_IDMA_SET_2_INFO_SIZE_LSB       0
#define IDMA_IDMA_SET_2_INFO_SIZE_WIDTH     ((uint32_t)0x00000010)

#define IDMA_IDMA_SET_2_INFO_SIZE_RST       0x0

__INLINE uint16_t idma_idma_set_2_info_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_2_INFO_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void idma_idma_set_2_info_size_setf(uint16_t size)
{
	ASSERT_ERR((((uint32_t)size << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_2_INFO_ADDR, (uint32_t)size << 0);
}

/**
 * @brief IDMA_SET_2_STATUS register definition
 *  Set2 DMA status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    REQ_FIFO_OF_ERR           0              
 *    03    AXI_WR_ERR                0              
 *    02    AXI_RD_ERR                0              
 *    01    REQUEST                   0              
 *    00    BUSY                      0              
 * </pre>
 */
#define IDMA_IDMA_SET_2_STATUS_ADDR        (REG_IDMA_BASE_ADDR+0x0000005C)
#define IDMA_IDMA_SET_2_STATUS_OFFSET      0x0000005C
#define IDMA_IDMA_SET_2_STATUS_INDEX       0x00000017
#define IDMA_IDMA_SET_2_STATUS_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_2_status_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_2_STATUS_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_2_STATUS_REQ_FIFO_OF_ERR_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_SET_2_STATUS_REQ_FIFO_OF_ERR_POS    4
#define IDMA_IDMA_SET_2_STATUS_AXI_WR_ERR_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_SET_2_STATUS_AXI_WR_ERR_POS    3
#define IDMA_IDMA_SET_2_STATUS_AXI_RD_ERR_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_SET_2_STATUS_AXI_RD_ERR_POS    2
#define IDMA_IDMA_SET_2_STATUS_REQUEST_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_SET_2_STATUS_REQUEST_POS    1
#define IDMA_IDMA_SET_2_STATUS_BUSY_BIT     ((uint32_t)0x00000001)
#define IDMA_IDMA_SET_2_STATUS_BUSY_POS     0

#define IDMA_IDMA_SET_2_STATUS_REQ_FIFO_OF_ERR_RST    0x0
#define IDMA_IDMA_SET_2_STATUS_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_SET_2_STATUS_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_SET_2_STATUS_REQUEST_RST    0x0
#define IDMA_IDMA_SET_2_STATUS_BUSY_RST     0x0

__INLINE void idma_idma_set_2_status_unpack(uint8_t* req_fifo_of_err, uint8_t* axi_wr_err, uint8_t* axi_rd_err, uint8_t* request, uint8_t* busy)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_2_STATUS_ADDR);

	*req_fifo_of_err = (localVal & ((uint32_t)0x00000010)) >>  4;
	*axi_wr_err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*axi_rd_err = (localVal & ((uint32_t)0x00000004)) >>  2;
	*request = (localVal & ((uint32_t)0x00000002)) >>  1;
	*busy = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_set_2_status_req_fifo_of_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_2_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t idma_idma_set_2_status_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_2_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t idma_idma_set_2_status_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_2_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t idma_idma_set_2_status_request_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_2_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t idma_idma_set_2_status_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_2_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief IDMA_SET_3_SOURCE_ADDR register definition
 *  Set3 DMA source address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SOURCE_ADDR               0x0
 * </pre>
 */
#define IDMA_IDMA_SET_3_SOURCE_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x00000060)
#define IDMA_IDMA_SET_3_SOURCE_ADDR_OFFSET      0x00000060
#define IDMA_IDMA_SET_3_SOURCE_ADDR_INDEX       0x00000018
#define IDMA_IDMA_SET_3_SOURCE_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_3_source_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_3_SOURCE_ADDR_ADDR);
}

__INLINE void idma_idma_set_3_source_addr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_3_SOURCE_ADDR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_3_SOURCE_ADDR_SOURCE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_3_SOURCE_ADDR_SOURCE_ADDR_LSB    0
#define IDMA_IDMA_SET_3_SOURCE_ADDR_SOURCE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_3_SOURCE_ADDR_SOURCE_ADDR_RST    0x0

__INLINE uint32_t idma_idma_set_3_source_addr_source_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_3_SOURCE_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_3_source_addr_source_addr_setf(uint32_t sourceaddr)
{
	ASSERT_ERR((((uint32_t)sourceaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_3_SOURCE_ADDR_ADDR, (uint32_t)sourceaddr << 0);
}

/**
 * @brief IDMA_SET_3_DEST_ADDR register definition
 *  Set3 DMA destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DEST_ADDR                 0x0
 * </pre>
 */
#define IDMA_IDMA_SET_3_DEST_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x00000064)
#define IDMA_IDMA_SET_3_DEST_ADDR_OFFSET      0x00000064
#define IDMA_IDMA_SET_3_DEST_ADDR_INDEX       0x00000019
#define IDMA_IDMA_SET_3_DEST_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_3_dest_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_3_DEST_ADDR_ADDR);
}

__INLINE void idma_idma_set_3_dest_addr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_3_DEST_ADDR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_3_DEST_ADDR_DEST_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_3_DEST_ADDR_DEST_ADDR_LSB    0
#define IDMA_IDMA_SET_3_DEST_ADDR_DEST_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_3_DEST_ADDR_DEST_ADDR_RST    0x0

__INLINE uint32_t idma_idma_set_3_dest_addr_dest_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_3_DEST_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_3_dest_addr_dest_addr_setf(uint32_t destaddr)
{
	ASSERT_ERR((((uint32_t)destaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_3_DEST_ADDR_ADDR, (uint32_t)destaddr << 0);
}

/**
 * @brief IDMA_SET_3_INFO register definition
 *  Set3 DMA info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 SIZE                      0x0
 * </pre>
 */
#define IDMA_IDMA_SET_3_INFO_ADDR        (REG_IDMA_BASE_ADDR+0x00000068)
#define IDMA_IDMA_SET_3_INFO_OFFSET      0x00000068
#define IDMA_IDMA_SET_3_INFO_INDEX       0x0000001A
#define IDMA_IDMA_SET_3_INFO_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_3_info_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_3_INFO_ADDR);
}

__INLINE void idma_idma_set_3_info_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_3_INFO_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_3_INFO_SIZE_MASK      ((uint32_t)0x0000FFFF)
#define IDMA_IDMA_SET_3_INFO_SIZE_LSB       0
#define IDMA_IDMA_SET_3_INFO_SIZE_WIDTH     ((uint32_t)0x00000010)

#define IDMA_IDMA_SET_3_INFO_SIZE_RST       0x0

__INLINE uint16_t idma_idma_set_3_info_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_3_INFO_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void idma_idma_set_3_info_size_setf(uint16_t size)
{
	ASSERT_ERR((((uint32_t)size << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_3_INFO_ADDR, (uint32_t)size << 0);
}

/**
 * @brief IDMA_SET_3_STATUS register definition
 *  Set3 DMA status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    REQ_FIFO_OF_ERR           0              
 *    03    AXI_WR_ERR                0              
 *    02    AXI_RD_ERR                0              
 *    01    REQUEST                   0              
 *    00    BUSY                      0              
 * </pre>
 */
#define IDMA_IDMA_SET_3_STATUS_ADDR        (REG_IDMA_BASE_ADDR+0x0000006C)
#define IDMA_IDMA_SET_3_STATUS_OFFSET      0x0000006C
#define IDMA_IDMA_SET_3_STATUS_INDEX       0x0000001B
#define IDMA_IDMA_SET_3_STATUS_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_3_status_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_3_STATUS_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_3_STATUS_REQ_FIFO_OF_ERR_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_SET_3_STATUS_REQ_FIFO_OF_ERR_POS    4
#define IDMA_IDMA_SET_3_STATUS_AXI_WR_ERR_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_SET_3_STATUS_AXI_WR_ERR_POS    3
#define IDMA_IDMA_SET_3_STATUS_AXI_RD_ERR_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_SET_3_STATUS_AXI_RD_ERR_POS    2
#define IDMA_IDMA_SET_3_STATUS_REQUEST_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_SET_3_STATUS_REQUEST_POS    1
#define IDMA_IDMA_SET_3_STATUS_BUSY_BIT     ((uint32_t)0x00000001)
#define IDMA_IDMA_SET_3_STATUS_BUSY_POS     0

#define IDMA_IDMA_SET_3_STATUS_REQ_FIFO_OF_ERR_RST    0x0
#define IDMA_IDMA_SET_3_STATUS_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_SET_3_STATUS_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_SET_3_STATUS_REQUEST_RST    0x0
#define IDMA_IDMA_SET_3_STATUS_BUSY_RST     0x0

__INLINE void idma_idma_set_3_status_unpack(uint8_t* req_fifo_of_err, uint8_t* axi_wr_err, uint8_t* axi_rd_err, uint8_t* request, uint8_t* busy)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_3_STATUS_ADDR);

	*req_fifo_of_err = (localVal & ((uint32_t)0x00000010)) >>  4;
	*axi_wr_err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*axi_rd_err = (localVal & ((uint32_t)0x00000004)) >>  2;
	*request = (localVal & ((uint32_t)0x00000002)) >>  1;
	*busy = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_set_3_status_req_fifo_of_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_3_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t idma_idma_set_3_status_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_3_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t idma_idma_set_3_status_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_3_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t idma_idma_set_3_status_request_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_3_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t idma_idma_set_3_status_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_3_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief IDMA_SET_4_SOURCE_ADDR register definition
 *  Set4 DMA source address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SOURCE_ADDR               0x0
 * </pre>
 */
#define IDMA_IDMA_SET_4_SOURCE_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x00000070)
#define IDMA_IDMA_SET_4_SOURCE_ADDR_OFFSET      0x00000070
#define IDMA_IDMA_SET_4_SOURCE_ADDR_INDEX       0x0000001C
#define IDMA_IDMA_SET_4_SOURCE_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_4_source_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_4_SOURCE_ADDR_ADDR);
}

__INLINE void idma_idma_set_4_source_addr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_4_SOURCE_ADDR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_4_SOURCE_ADDR_SOURCE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_4_SOURCE_ADDR_SOURCE_ADDR_LSB    0
#define IDMA_IDMA_SET_4_SOURCE_ADDR_SOURCE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_4_SOURCE_ADDR_SOURCE_ADDR_RST    0x0

__INLINE uint32_t idma_idma_set_4_source_addr_source_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_4_SOURCE_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_4_source_addr_source_addr_setf(uint32_t sourceaddr)
{
	ASSERT_ERR((((uint32_t)sourceaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_4_SOURCE_ADDR_ADDR, (uint32_t)sourceaddr << 0);
}

/**
 * @brief IDMA_SET_4_DEST_ADDR register definition
 *  Set4 DMA destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DEST_ADDR                 0x0
 * </pre>
 */
#define IDMA_IDMA_SET_4_DEST_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x00000074)
#define IDMA_IDMA_SET_4_DEST_ADDR_OFFSET      0x00000074
#define IDMA_IDMA_SET_4_DEST_ADDR_INDEX       0x0000001D
#define IDMA_IDMA_SET_4_DEST_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_4_dest_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_4_DEST_ADDR_ADDR);
}

__INLINE void idma_idma_set_4_dest_addr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_4_DEST_ADDR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_4_DEST_ADDR_DEST_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_4_DEST_ADDR_DEST_ADDR_LSB    0
#define IDMA_IDMA_SET_4_DEST_ADDR_DEST_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_4_DEST_ADDR_DEST_ADDR_RST    0x0

__INLINE uint32_t idma_idma_set_4_dest_addr_dest_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_4_DEST_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_4_dest_addr_dest_addr_setf(uint32_t destaddr)
{
	ASSERT_ERR((((uint32_t)destaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_4_DEST_ADDR_ADDR, (uint32_t)destaddr << 0);
}

/**
 * @brief IDMA_SET_4_INFO register definition
 *  Set4 DMA info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 SIZE                      0x0
 * </pre>
 */
#define IDMA_IDMA_SET_4_INFO_ADDR        (REG_IDMA_BASE_ADDR+0x00000078)
#define IDMA_IDMA_SET_4_INFO_OFFSET      0x00000078
#define IDMA_IDMA_SET_4_INFO_INDEX       0x0000001E
#define IDMA_IDMA_SET_4_INFO_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_4_info_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_4_INFO_ADDR);
}

__INLINE void idma_idma_set_4_info_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_4_INFO_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_4_INFO_SIZE_MASK      ((uint32_t)0x0000FFFF)
#define IDMA_IDMA_SET_4_INFO_SIZE_LSB       0
#define IDMA_IDMA_SET_4_INFO_SIZE_WIDTH     ((uint32_t)0x00000010)

#define IDMA_IDMA_SET_4_INFO_SIZE_RST       0x0

__INLINE uint16_t idma_idma_set_4_info_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_4_INFO_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void idma_idma_set_4_info_size_setf(uint16_t size)
{
	ASSERT_ERR((((uint32_t)size << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_4_INFO_ADDR, (uint32_t)size << 0);
}

/**
 * @brief IDMA_SET_4_STATUS register definition
 *  Set4 DMA status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    REQ_FIFO_OF_ERR           0              
 *    03    AXI_WR_ERR                0              
 *    02    AXI_RD_ERR                0              
 *    01    REQUEST                   0              
 *    00    BUSY                      0              
 * </pre>
 */
#define IDMA_IDMA_SET_4_STATUS_ADDR        (REG_IDMA_BASE_ADDR+0x0000007C)
#define IDMA_IDMA_SET_4_STATUS_OFFSET      0x0000007C
#define IDMA_IDMA_SET_4_STATUS_INDEX       0x0000001F
#define IDMA_IDMA_SET_4_STATUS_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_4_status_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_4_STATUS_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_4_STATUS_REQ_FIFO_OF_ERR_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_SET_4_STATUS_REQ_FIFO_OF_ERR_POS    4
#define IDMA_IDMA_SET_4_STATUS_AXI_WR_ERR_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_SET_4_STATUS_AXI_WR_ERR_POS    3
#define IDMA_IDMA_SET_4_STATUS_AXI_RD_ERR_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_SET_4_STATUS_AXI_RD_ERR_POS    2
#define IDMA_IDMA_SET_4_STATUS_REQUEST_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_SET_4_STATUS_REQUEST_POS    1
#define IDMA_IDMA_SET_4_STATUS_BUSY_BIT     ((uint32_t)0x00000001)
#define IDMA_IDMA_SET_4_STATUS_BUSY_POS     0

#define IDMA_IDMA_SET_4_STATUS_REQ_FIFO_OF_ERR_RST    0x0
#define IDMA_IDMA_SET_4_STATUS_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_SET_4_STATUS_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_SET_4_STATUS_REQUEST_RST    0x0
#define IDMA_IDMA_SET_4_STATUS_BUSY_RST     0x0

__INLINE void idma_idma_set_4_status_unpack(uint8_t* req_fifo_of_err, uint8_t* axi_wr_err, uint8_t* axi_rd_err, uint8_t* request, uint8_t* busy)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_4_STATUS_ADDR);

	*req_fifo_of_err = (localVal & ((uint32_t)0x00000010)) >>  4;
	*axi_wr_err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*axi_rd_err = (localVal & ((uint32_t)0x00000004)) >>  2;
	*request = (localVal & ((uint32_t)0x00000002)) >>  1;
	*busy = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_set_4_status_req_fifo_of_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_4_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t idma_idma_set_4_status_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_4_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t idma_idma_set_4_status_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_4_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t idma_idma_set_4_status_request_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_4_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t idma_idma_set_4_status_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_4_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief IDMA_SET_5_SOURCE_ADDR register definition
 *  Set5 DMA source address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SOURCE_ADDR               0x0
 * </pre>
 */
#define IDMA_IDMA_SET_5_SOURCE_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x00000080)
#define IDMA_IDMA_SET_5_SOURCE_ADDR_OFFSET      0x00000080
#define IDMA_IDMA_SET_5_SOURCE_ADDR_INDEX       0x00000020
#define IDMA_IDMA_SET_5_SOURCE_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_5_source_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_5_SOURCE_ADDR_ADDR);
}

__INLINE void idma_idma_set_5_source_addr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_5_SOURCE_ADDR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_5_SOURCE_ADDR_SOURCE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_5_SOURCE_ADDR_SOURCE_ADDR_LSB    0
#define IDMA_IDMA_SET_5_SOURCE_ADDR_SOURCE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_5_SOURCE_ADDR_SOURCE_ADDR_RST    0x0

__INLINE uint32_t idma_idma_set_5_source_addr_source_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_5_SOURCE_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_5_source_addr_source_addr_setf(uint32_t sourceaddr)
{
	ASSERT_ERR((((uint32_t)sourceaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_5_SOURCE_ADDR_ADDR, (uint32_t)sourceaddr << 0);
}

/**
 * @brief IDMA_SET_5_DEST_ADDR register definition
 *  Set5 DMA destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DEST_ADDR                 0x0
 * </pre>
 */
#define IDMA_IDMA_SET_5_DEST_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x00000084)
#define IDMA_IDMA_SET_5_DEST_ADDR_OFFSET      0x00000084
#define IDMA_IDMA_SET_5_DEST_ADDR_INDEX       0x00000021
#define IDMA_IDMA_SET_5_DEST_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_5_dest_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_5_DEST_ADDR_ADDR);
}

__INLINE void idma_idma_set_5_dest_addr_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_5_DEST_ADDR_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_5_DEST_ADDR_DEST_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_5_DEST_ADDR_DEST_ADDR_LSB    0
#define IDMA_IDMA_SET_5_DEST_ADDR_DEST_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_5_DEST_ADDR_DEST_ADDR_RST    0x0

__INLINE uint32_t idma_idma_set_5_dest_addr_dest_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_5_DEST_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_5_dest_addr_dest_addr_setf(uint32_t destaddr)
{
	ASSERT_ERR((((uint32_t)destaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_5_DEST_ADDR_ADDR, (uint32_t)destaddr << 0);
}

/**
 * @brief IDMA_SET_5_INFO register definition
 *  Set5 DMA info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 SIZE                      0x0
 * </pre>
 */
#define IDMA_IDMA_SET_5_INFO_ADDR        (REG_IDMA_BASE_ADDR+0x00000088)
#define IDMA_IDMA_SET_5_INFO_OFFSET      0x00000088
#define IDMA_IDMA_SET_5_INFO_INDEX       0x00000022
#define IDMA_IDMA_SET_5_INFO_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_5_info_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_5_INFO_ADDR);
}

__INLINE void idma_idma_set_5_info_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_5_INFO_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_5_INFO_SIZE_MASK      ((uint32_t)0x0000FFFF)
#define IDMA_IDMA_SET_5_INFO_SIZE_LSB       0
#define IDMA_IDMA_SET_5_INFO_SIZE_WIDTH     ((uint32_t)0x00000010)

#define IDMA_IDMA_SET_5_INFO_SIZE_RST       0x0

__INLINE uint16_t idma_idma_set_5_info_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_5_INFO_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void idma_idma_set_5_info_size_setf(uint16_t size)
{
	ASSERT_ERR((((uint32_t)size << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_5_INFO_ADDR, (uint32_t)size << 0);
}

/**
 * @brief IDMA_SET_5_STATUS register definition
 *  Set5 DMA status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    REQ_FIFO_OF_ERR           0              
 *    03    AXI_WR_ERR                0              
 *    02    AXI_RD_ERR                0              
 *    01    REQUEST                   0              
 *    00    BUSY                      0              
 * </pre>
 */
#define IDMA_IDMA_SET_5_STATUS_ADDR        (REG_IDMA_BASE_ADDR+0x0000008C)
#define IDMA_IDMA_SET_5_STATUS_OFFSET      0x0000008C
#define IDMA_IDMA_SET_5_STATUS_INDEX       0x00000023
#define IDMA_IDMA_SET_5_STATUS_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_5_status_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_5_STATUS_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_5_STATUS_REQ_FIFO_OF_ERR_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_SET_5_STATUS_REQ_FIFO_OF_ERR_POS    4
#define IDMA_IDMA_SET_5_STATUS_AXI_WR_ERR_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_SET_5_STATUS_AXI_WR_ERR_POS    3
#define IDMA_IDMA_SET_5_STATUS_AXI_RD_ERR_BIT    ((uint32_t)0x00000004)
#define IDMA_IDMA_SET_5_STATUS_AXI_RD_ERR_POS    2
#define IDMA_IDMA_SET_5_STATUS_REQUEST_BIT    ((uint32_t)0x00000002)
#define IDMA_IDMA_SET_5_STATUS_REQUEST_POS    1
#define IDMA_IDMA_SET_5_STATUS_BUSY_BIT     ((uint32_t)0x00000001)
#define IDMA_IDMA_SET_5_STATUS_BUSY_POS     0

#define IDMA_IDMA_SET_5_STATUS_REQ_FIFO_OF_ERR_RST    0x0
#define IDMA_IDMA_SET_5_STATUS_AXI_WR_ERR_RST    0x0
#define IDMA_IDMA_SET_5_STATUS_AXI_RD_ERR_RST    0x0
#define IDMA_IDMA_SET_5_STATUS_REQUEST_RST    0x0
#define IDMA_IDMA_SET_5_STATUS_BUSY_RST     0x0

__INLINE void idma_idma_set_5_status_unpack(uint8_t* req_fifo_of_err, uint8_t* axi_wr_err, uint8_t* axi_rd_err, uint8_t* request, uint8_t* busy)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_5_STATUS_ADDR);

	*req_fifo_of_err = (localVal & ((uint32_t)0x00000010)) >>  4;
	*axi_wr_err = (localVal & ((uint32_t)0x00000008)) >>  3;
	*axi_rd_err = (localVal & ((uint32_t)0x00000004)) >>  2;
	*request = (localVal & ((uint32_t)0x00000002)) >>  1;
	*busy = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t idma_idma_set_5_status_req_fifo_of_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_5_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t idma_idma_set_5_status_axi_wr_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_5_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t idma_idma_set_5_status_axi_rd_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_5_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t idma_idma_set_5_status_request_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_5_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t idma_idma_set_5_status_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_5_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief IDMA_SET_0_CNT register definition
 *  Set0 completions counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DMA_COMP_CNT              0x0
 * </pre>
 */
#define IDMA_IDMA_SET_0_CNT_ADDR        (REG_IDMA_BASE_ADDR+0x00000090)
#define IDMA_IDMA_SET_0_CNT_OFFSET      0x00000090
#define IDMA_IDMA_SET_0_CNT_INDEX       0x00000024
#define IDMA_IDMA_SET_0_CNT_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_0_cnt_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_0_CNT_ADDR);
}

__INLINE void idma_idma_set_0_cnt_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_SET_0_CNT_ADDR, value);
}

// field definitions
#define IDMA_IDMA_SET_0_CNT_DMA_COMP_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_0_CNT_DMA_COMP_CNT_LSB    0
#define IDMA_IDMA_SET_0_CNT_DMA_COMP_CNT_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_0_CNT_DMA_COMP_CNT_RST    0x0

__INLINE uint32_t idma_idma_set_0_cnt_dma_comp_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_0_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_set_0_cnt_dma_comp_cnt_setf(uint32_t dmacompcnt)
{
	ASSERT_ERR((((uint32_t)dmacompcnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_SET_0_CNT_ADDR, (uint32_t)dmacompcnt << 0);
}

/**
 * @brief IDMA_SET_1_CNT register definition
 *  Set1 completions counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DMA_COMP_CNT              0x0
 * </pre>
 */
#define IDMA_IDMA_SET_1_CNT_ADDR        (REG_IDMA_BASE_ADDR+0x00000094)
#define IDMA_IDMA_SET_1_CNT_OFFSET      0x00000094
#define IDMA_IDMA_SET_1_CNT_INDEX       0x00000025
#define IDMA_IDMA_SET_1_CNT_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_1_cnt_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_1_CNT_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_1_CNT_DMA_COMP_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_1_CNT_DMA_COMP_CNT_LSB    0
#define IDMA_IDMA_SET_1_CNT_DMA_COMP_CNT_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_1_CNT_DMA_COMP_CNT_RST    0x0

__INLINE uint32_t idma_idma_set_1_cnt_dma_comp_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_1_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief IDMA_SET_2_CNT register definition
 *  Set2 completions counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DMA_COMP_CNT              0x0
 * </pre>
 */
#define IDMA_IDMA_SET_2_CNT_ADDR        (REG_IDMA_BASE_ADDR+0x00000098)
#define IDMA_IDMA_SET_2_CNT_OFFSET      0x00000098
#define IDMA_IDMA_SET_2_CNT_INDEX       0x00000026
#define IDMA_IDMA_SET_2_CNT_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_2_cnt_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_2_CNT_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_2_CNT_DMA_COMP_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_2_CNT_DMA_COMP_CNT_LSB    0
#define IDMA_IDMA_SET_2_CNT_DMA_COMP_CNT_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_2_CNT_DMA_COMP_CNT_RST    0x0

__INLINE uint32_t idma_idma_set_2_cnt_dma_comp_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_2_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief IDMA_SET_3_CNT register definition
 *  Set3 completions counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DMA_COMP_CNT              0x0
 * </pre>
 */
#define IDMA_IDMA_SET_3_CNT_ADDR        (REG_IDMA_BASE_ADDR+0x0000009C)
#define IDMA_IDMA_SET_3_CNT_OFFSET      0x0000009C
#define IDMA_IDMA_SET_3_CNT_INDEX       0x00000027
#define IDMA_IDMA_SET_3_CNT_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_3_cnt_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_3_CNT_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_3_CNT_DMA_COMP_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_3_CNT_DMA_COMP_CNT_LSB    0
#define IDMA_IDMA_SET_3_CNT_DMA_COMP_CNT_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_3_CNT_DMA_COMP_CNT_RST    0x0

__INLINE uint32_t idma_idma_set_3_cnt_dma_comp_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_3_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief IDMA_SET_4_CNT register definition
 *  Set4 completions counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DMA_COMP_CNT              0x0
 * </pre>
 */
#define IDMA_IDMA_SET_4_CNT_ADDR        (REG_IDMA_BASE_ADDR+0x000000A0)
#define IDMA_IDMA_SET_4_CNT_OFFSET      0x000000A0
#define IDMA_IDMA_SET_4_CNT_INDEX       0x00000028
#define IDMA_IDMA_SET_4_CNT_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_4_cnt_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_4_CNT_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_4_CNT_DMA_COMP_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_4_CNT_DMA_COMP_CNT_LSB    0
#define IDMA_IDMA_SET_4_CNT_DMA_COMP_CNT_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_4_CNT_DMA_COMP_CNT_RST    0x0

__INLINE uint32_t idma_idma_set_4_cnt_dma_comp_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_4_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief IDMA_SET_5_CNT register definition
 *  Set5 completions counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DMA_COMP_CNT              0x0
 * </pre>
 */
#define IDMA_IDMA_SET_5_CNT_ADDR        (REG_IDMA_BASE_ADDR+0x000000A4)
#define IDMA_IDMA_SET_5_CNT_OFFSET      0x000000A4
#define IDMA_IDMA_SET_5_CNT_INDEX       0x00000029
#define IDMA_IDMA_SET_5_CNT_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_5_cnt_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_5_CNT_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_5_CNT_DMA_COMP_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_5_CNT_DMA_COMP_CNT_LSB    0
#define IDMA_IDMA_SET_5_CNT_DMA_COMP_CNT_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_5_CNT_DMA_COMP_CNT_RST    0x0

__INLINE uint32_t idma_idma_set_5_cnt_dma_comp_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_5_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief IDMA_ACTIVE_MIN_CYC register definition
 *  Min activation cycles register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ACTIVE_MIN_CYC            0xffffffff
 * </pre>
 */
#define IDMA_IDMA_ACTIVE_MIN_CYC_ADDR        (REG_IDMA_BASE_ADDR+0x000000B0)
#define IDMA_IDMA_ACTIVE_MIN_CYC_OFFSET      0x000000B0
#define IDMA_IDMA_ACTIVE_MIN_CYC_INDEX       0x0000002C
#define IDMA_IDMA_ACTIVE_MIN_CYC_RESET       0xFFFFFFFF

__INLINE uint32_t  idma_idma_active_min_cyc_get(void)
{
	return REG_PL_RD(IDMA_IDMA_ACTIVE_MIN_CYC_ADDR);
}

__INLINE void idma_idma_active_min_cyc_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_ACTIVE_MIN_CYC_ADDR, value);
}

// field definitions
#define IDMA_IDMA_ACTIVE_MIN_CYC_ACTIVE_MIN_CYC_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_ACTIVE_MIN_CYC_ACTIVE_MIN_CYC_LSB    0
#define IDMA_IDMA_ACTIVE_MIN_CYC_ACTIVE_MIN_CYC_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_ACTIVE_MIN_CYC_ACTIVE_MIN_CYC_RST    0xffffffff

__INLINE uint32_t idma_idma_active_min_cyc_active_min_cyc_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_ACTIVE_MIN_CYC_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_active_min_cyc_active_min_cyc_setf(uint32_t activemincyc)
{
	ASSERT_ERR((((uint32_t)activemincyc << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_ACTIVE_MIN_CYC_ADDR, (uint32_t)activemincyc << 0);
}

/**
 * @brief IDMA_ACTIVE_MAX_CYC register definition
 *  Max activation cycles register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ACTIVE_MAX_CYC            0x0
 * </pre>
 */
#define IDMA_IDMA_ACTIVE_MAX_CYC_ADDR        (REG_IDMA_BASE_ADDR+0x000000B4)
#define IDMA_IDMA_ACTIVE_MAX_CYC_OFFSET      0x000000B4
#define IDMA_IDMA_ACTIVE_MAX_CYC_INDEX       0x0000002D
#define IDMA_IDMA_ACTIVE_MAX_CYC_RESET       0x00000000

__INLINE uint32_t  idma_idma_active_max_cyc_get(void)
{
	return REG_PL_RD(IDMA_IDMA_ACTIVE_MAX_CYC_ADDR);
}

__INLINE void idma_idma_active_max_cyc_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_ACTIVE_MAX_CYC_ADDR, value);
}

// field definitions
#define IDMA_IDMA_ACTIVE_MAX_CYC_ACTIVE_MAX_CYC_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_ACTIVE_MAX_CYC_ACTIVE_MAX_CYC_LSB    0
#define IDMA_IDMA_ACTIVE_MAX_CYC_ACTIVE_MAX_CYC_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_ACTIVE_MAX_CYC_ACTIVE_MAX_CYC_RST    0x0

__INLINE uint32_t idma_idma_active_max_cyc_active_max_cyc_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_ACTIVE_MAX_CYC_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_active_max_cyc_active_max_cyc_setf(uint32_t activemaxcyc)
{
	ASSERT_ERR((((uint32_t)activemaxcyc << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_ACTIVE_MAX_CYC_ADDR, (uint32_t)activemaxcyc << 0);
}

/**
 * @brief IDMA_ACTIVE_AVG_CYC register definition
 *  Average activation cycles register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ACTIVE_AVG_CYC            0x0
 * </pre>
 */
#define IDMA_IDMA_ACTIVE_AVG_CYC_ADDR        (REG_IDMA_BASE_ADDR+0x000000B8)
#define IDMA_IDMA_ACTIVE_AVG_CYC_OFFSET      0x000000B8
#define IDMA_IDMA_ACTIVE_AVG_CYC_INDEX       0x0000002E
#define IDMA_IDMA_ACTIVE_AVG_CYC_RESET       0x00000000

__INLINE uint32_t  idma_idma_active_avg_cyc_get(void)
{
	return REG_PL_RD(IDMA_IDMA_ACTIVE_AVG_CYC_ADDR);
}

__INLINE void idma_idma_active_avg_cyc_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_ACTIVE_AVG_CYC_ADDR, value);
}

// field definitions
#define IDMA_IDMA_ACTIVE_AVG_CYC_ACTIVE_AVG_CYC_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_ACTIVE_AVG_CYC_ACTIVE_AVG_CYC_LSB    0
#define IDMA_IDMA_ACTIVE_AVG_CYC_ACTIVE_AVG_CYC_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_ACTIVE_AVG_CYC_ACTIVE_AVG_CYC_RST    0x0

__INLINE uint32_t idma_idma_active_avg_cyc_active_avg_cyc_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_ACTIVE_AVG_CYC_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_active_avg_cyc_active_avg_cyc_setf(uint32_t activeavgcyc)
{
	ASSERT_ERR((((uint32_t)activeavgcyc << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_ACTIVE_AVG_CYC_ADDR, (uint32_t)activeavgcyc << 0);
}

/**
 * @brief IDMA_PROC_MIN_CYC register definition
 *  Min activation cycles register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PROC_MIN_CYC              0xffffffff
 * </pre>
 */
#define IDMA_IDMA_PROC_MIN_CYC_ADDR        (REG_IDMA_BASE_ADDR+0x000000BC)
#define IDMA_IDMA_PROC_MIN_CYC_OFFSET      0x000000BC
#define IDMA_IDMA_PROC_MIN_CYC_INDEX       0x0000002F
#define IDMA_IDMA_PROC_MIN_CYC_RESET       0xFFFFFFFF

__INLINE uint32_t  idma_idma_proc_min_cyc_get(void)
{
	return REG_PL_RD(IDMA_IDMA_PROC_MIN_CYC_ADDR);
}

__INLINE void idma_idma_proc_min_cyc_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_PROC_MIN_CYC_ADDR, value);
}

// field definitions
#define IDMA_IDMA_PROC_MIN_CYC_PROC_MIN_CYC_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_PROC_MIN_CYC_PROC_MIN_CYC_LSB    0
#define IDMA_IDMA_PROC_MIN_CYC_PROC_MIN_CYC_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_PROC_MIN_CYC_PROC_MIN_CYC_RST    0xffffffff

__INLINE uint32_t idma_idma_proc_min_cyc_proc_min_cyc_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PROC_MIN_CYC_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_proc_min_cyc_proc_min_cyc_setf(uint32_t procmincyc)
{
	ASSERT_ERR((((uint32_t)procmincyc << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_PROC_MIN_CYC_ADDR, (uint32_t)procmincyc << 0);
}

/**
 * @brief IDMA_PROC_MAX_CYC register definition
 *  Max activation cycles register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PROC_MAX_CYC              0x0
 * </pre>
 */
#define IDMA_IDMA_PROC_MAX_CYC_ADDR        (REG_IDMA_BASE_ADDR+0x000000C0)
#define IDMA_IDMA_PROC_MAX_CYC_OFFSET      0x000000C0
#define IDMA_IDMA_PROC_MAX_CYC_INDEX       0x00000030
#define IDMA_IDMA_PROC_MAX_CYC_RESET       0x00000000

__INLINE uint32_t  idma_idma_proc_max_cyc_get(void)
{
	return REG_PL_RD(IDMA_IDMA_PROC_MAX_CYC_ADDR);
}

__INLINE void idma_idma_proc_max_cyc_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_PROC_MAX_CYC_ADDR, value);
}

// field definitions
#define IDMA_IDMA_PROC_MAX_CYC_PROC_MAX_CYC_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_PROC_MAX_CYC_PROC_MAX_CYC_LSB    0
#define IDMA_IDMA_PROC_MAX_CYC_PROC_MAX_CYC_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_PROC_MAX_CYC_PROC_MAX_CYC_RST    0x0

__INLINE uint32_t idma_idma_proc_max_cyc_proc_max_cyc_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PROC_MAX_CYC_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_proc_max_cyc_proc_max_cyc_setf(uint32_t procmaxcyc)
{
	ASSERT_ERR((((uint32_t)procmaxcyc << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_PROC_MAX_CYC_ADDR, (uint32_t)procmaxcyc << 0);
}

/**
 * @brief IDMA_PROC_AVG_CYC register definition
 *  Average activation cycles register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PROC_AVG_CYC              0x0
 * </pre>
 */
#define IDMA_IDMA_PROC_AVG_CYC_ADDR        (REG_IDMA_BASE_ADDR+0x000000C4)
#define IDMA_IDMA_PROC_AVG_CYC_OFFSET      0x000000C4
#define IDMA_IDMA_PROC_AVG_CYC_INDEX       0x00000031
#define IDMA_IDMA_PROC_AVG_CYC_RESET       0x00000000

__INLINE uint32_t  idma_idma_proc_avg_cyc_get(void)
{
	return REG_PL_RD(IDMA_IDMA_PROC_AVG_CYC_ADDR);
}

__INLINE void idma_idma_proc_avg_cyc_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_PROC_AVG_CYC_ADDR, value);
}

// field definitions
#define IDMA_IDMA_PROC_AVG_CYC_PROC_AVG_CYC_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_PROC_AVG_CYC_PROC_AVG_CYC_LSB    0
#define IDMA_IDMA_PROC_AVG_CYC_PROC_AVG_CYC_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_PROC_AVG_CYC_PROC_AVG_CYC_RST    0x0

__INLINE uint32_t idma_idma_proc_avg_cyc_proc_avg_cyc_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PROC_AVG_CYC_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void idma_idma_proc_avg_cyc_proc_avg_cyc_setf(uint32_t procavgcyc)
{
	ASSERT_ERR((((uint32_t)procavgcyc << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IDMA_IDMA_PROC_AVG_CYC_ADDR, (uint32_t)procavgcyc << 0);
}

/**
 * @brief IDMA_AXI_ERR_ADDR register definition
 *  AXI error address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 AXI_ERR_ADDR              0x0
 * </pre>
 */
#define IDMA_IDMA_AXI_ERR_ADDR_ADDR        (REG_IDMA_BASE_ADDR+0x000000D0)
#define IDMA_IDMA_AXI_ERR_ADDR_OFFSET      0x000000D0
#define IDMA_IDMA_AXI_ERR_ADDR_INDEX       0x00000034
#define IDMA_IDMA_AXI_ERR_ADDR_RESET       0x00000000

__INLINE uint32_t  idma_idma_axi_err_addr_get(void)
{
	return REG_PL_RD(IDMA_IDMA_AXI_ERR_ADDR_ADDR);
}

// field definitions
#define IDMA_IDMA_AXI_ERR_ADDR_AXI_ERR_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_AXI_ERR_ADDR_AXI_ERR_ADDR_LSB    0
#define IDMA_IDMA_AXI_ERR_ADDR_AXI_ERR_ADDR_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_AXI_ERR_ADDR_AXI_ERR_ADDR_RST    0x0

__INLINE uint32_t idma_idma_axi_err_addr_axi_err_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_AXI_ERR_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief IDMA_AXI_ERR_INFO register definition
 *  AXI error information register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    AXI_ERR_VALID             0              
 *    03    AXI_ERR_TYPE              0              
 *    02:00 AXI_ERR_SET               0x0
 * </pre>
 */
#define IDMA_IDMA_AXI_ERR_INFO_ADDR        (REG_IDMA_BASE_ADDR+0x000000D4)
#define IDMA_IDMA_AXI_ERR_INFO_OFFSET      0x000000D4
#define IDMA_IDMA_AXI_ERR_INFO_INDEX       0x00000035
#define IDMA_IDMA_AXI_ERR_INFO_RESET       0x00000000

__INLINE uint32_t  idma_idma_axi_err_info_get(void)
{
	return REG_PL_RD(IDMA_IDMA_AXI_ERR_INFO_ADDR);
}

// field definitions
#define IDMA_IDMA_AXI_ERR_INFO_AXI_ERR_VALID_BIT    ((uint32_t)0x00000010)
#define IDMA_IDMA_AXI_ERR_INFO_AXI_ERR_VALID_POS    4
#define IDMA_IDMA_AXI_ERR_INFO_AXI_ERR_TYPE_BIT    ((uint32_t)0x00000008)
#define IDMA_IDMA_AXI_ERR_INFO_AXI_ERR_TYPE_POS    3
#define IDMA_IDMA_AXI_ERR_INFO_AXI_ERR_SET_MASK    ((uint32_t)0x00000007)
#define IDMA_IDMA_AXI_ERR_INFO_AXI_ERR_SET_LSB    0
#define IDMA_IDMA_AXI_ERR_INFO_AXI_ERR_SET_WIDTH    ((uint32_t)0x00000003)

#define IDMA_IDMA_AXI_ERR_INFO_AXI_ERR_VALID_RST    0x0
#define IDMA_IDMA_AXI_ERR_INFO_AXI_ERR_TYPE_RST    0x0
#define IDMA_IDMA_AXI_ERR_INFO_AXI_ERR_SET_RST    0x0

__INLINE void idma_idma_axi_err_info_unpack(uint8_t* axi_err_valid, uint8_t* axi_err_type, uint8_t* axi_err_set)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_AXI_ERR_INFO_ADDR);

	*axi_err_valid = (localVal & ((uint32_t)0x00000010)) >>  4;
	*axi_err_type = (localVal & ((uint32_t)0x00000008)) >>  3;
	*axi_err_set = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t idma_idma_axi_err_info_axi_err_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_AXI_ERR_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t idma_idma_axi_err_info_axi_err_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_AXI_ERR_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t idma_idma_axi_err_info_axi_err_set_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_AXI_ERR_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief IDMA_SET_OVERWRITE_ERR_DATA register definition
 *  Overwrite error data register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SET_OVERWRITE_ERR_DATA    0x0
 * </pre>
 */
#define IDMA_IDMA_SET_OVERWRITE_ERR_DATA_ADDR        (REG_IDMA_BASE_ADDR+0x000000D8)
#define IDMA_IDMA_SET_OVERWRITE_ERR_DATA_OFFSET      0x000000D8
#define IDMA_IDMA_SET_OVERWRITE_ERR_DATA_INDEX       0x00000036
#define IDMA_IDMA_SET_OVERWRITE_ERR_DATA_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_overwrite_err_data_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_OVERWRITE_ERR_DATA_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_OVERWRITE_ERR_DATA_SET_OVERWRITE_ERR_DATA_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_SET_OVERWRITE_ERR_DATA_SET_OVERWRITE_ERR_DATA_LSB    0
#define IDMA_IDMA_SET_OVERWRITE_ERR_DATA_SET_OVERWRITE_ERR_DATA_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_SET_OVERWRITE_ERR_DATA_SET_OVERWRITE_ERR_DATA_RST    0x0

__INLINE uint32_t idma_idma_set_overwrite_err_data_set_overwrite_err_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_OVERWRITE_ERR_DATA_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief IDMA_SET_OVERWRITE_ERR_INFO register definition
 *  Overwrite error address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    SET_OVERWRITE_ERR_VALID   0              
 *    07:00 SET_OVERWRITE_ERR_ADDR    0x0
 * </pre>
 */
#define IDMA_IDMA_SET_OVERWRITE_ERR_INFO_ADDR        (REG_IDMA_BASE_ADDR+0x000000DC)
#define IDMA_IDMA_SET_OVERWRITE_ERR_INFO_OFFSET      0x000000DC
#define IDMA_IDMA_SET_OVERWRITE_ERR_INFO_INDEX       0x00000037
#define IDMA_IDMA_SET_OVERWRITE_ERR_INFO_RESET       0x00000000

__INLINE uint32_t  idma_idma_set_overwrite_err_info_get(void)
{
	return REG_PL_RD(IDMA_IDMA_SET_OVERWRITE_ERR_INFO_ADDR);
}

// field definitions
#define IDMA_IDMA_SET_OVERWRITE_ERR_INFO_SET_OVERWRITE_ERR_VALID_BIT    ((uint32_t)0x80000000)
#define IDMA_IDMA_SET_OVERWRITE_ERR_INFO_SET_OVERWRITE_ERR_VALID_POS    31
#define IDMA_IDMA_SET_OVERWRITE_ERR_INFO_SET_OVERWRITE_ERR_ADDR_MASK    ((uint32_t)0x000000FF)
#define IDMA_IDMA_SET_OVERWRITE_ERR_INFO_SET_OVERWRITE_ERR_ADDR_LSB    0
#define IDMA_IDMA_SET_OVERWRITE_ERR_INFO_SET_OVERWRITE_ERR_ADDR_WIDTH    ((uint32_t)0x00000008)

#define IDMA_IDMA_SET_OVERWRITE_ERR_INFO_SET_OVERWRITE_ERR_VALID_RST    0x0
#define IDMA_IDMA_SET_OVERWRITE_ERR_INFO_SET_OVERWRITE_ERR_ADDR_RST    0x0

__INLINE void idma_idma_set_overwrite_err_info_unpack(uint8_t* set_overwrite_err_valid, uint8_t* set_overwrite_err_addr)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_OVERWRITE_ERR_INFO_ADDR);

	*set_overwrite_err_valid = (localVal & ((uint32_t)0x80000000)) >>  31;
	*set_overwrite_err_addr = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t idma_idma_set_overwrite_err_info_set_overwrite_err_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_OVERWRITE_ERR_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE uint8_t idma_idma_set_overwrite_err_info_set_overwrite_err_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_SET_OVERWRITE_ERR_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief IDMA_PRC_DBG register definition
 *  Processor debug register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    SMAC_INT                  0              
 *    30    LMAC_INT                  0              
 *    29    UMAC_INT                  0              
 *    28:21 AVAILABLE_WR_BURST_CNT    0x0
 *    20:17 WR_DW_CNT_LSB             0x0
 *    16:13 RD_DW_CNT_LSB             0x0
 *    12    DATA_FIFO_POP             0              
 *    11    DATA_FIFO_PUSH            0              
 *    10    REQ_FIFO_POP              0              
 *    09    REQ_FIFO_PUSH             0              
 *    08:06 WR_SM                     0x0
 *    05:03 RD_SM                     0x0
 *    02:00 PRC_SM                    0x0
 * </pre>
 */
#define IDMA_IDMA_PRC_DBG_ADDR        (REG_IDMA_BASE_ADDR+0x000000F0)
#define IDMA_IDMA_PRC_DBG_OFFSET      0x000000F0
#define IDMA_IDMA_PRC_DBG_INDEX       0x0000003C
#define IDMA_IDMA_PRC_DBG_RESET       0x00000000

__INLINE uint32_t  idma_idma_prc_dbg_get(void)
{
	return REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
}

// field definitions
#define IDMA_IDMA_PRC_DBG_SMAC_INT_BIT      ((uint32_t)0x80000000)
#define IDMA_IDMA_PRC_DBG_SMAC_INT_POS      31
#define IDMA_IDMA_PRC_DBG_LMAC_INT_BIT      ((uint32_t)0x40000000)
#define IDMA_IDMA_PRC_DBG_LMAC_INT_POS      30
#define IDMA_IDMA_PRC_DBG_UMAC_INT_BIT      ((uint32_t)0x20000000)
#define IDMA_IDMA_PRC_DBG_UMAC_INT_POS      29
#define IDMA_IDMA_PRC_DBG_AVAILABLE_WR_BURST_CNT_MASK    ((uint32_t)0x1FE00000)
#define IDMA_IDMA_PRC_DBG_AVAILABLE_WR_BURST_CNT_LSB    21
#define IDMA_IDMA_PRC_DBG_AVAILABLE_WR_BURST_CNT_WIDTH    ((uint32_t)0x00000008)
#define IDMA_IDMA_PRC_DBG_WR_DW_CNT_LSB_MASK    ((uint32_t)0x001E0000)
#define IDMA_IDMA_PRC_DBG_WR_DW_CNT_LSB_LSB    17
#define IDMA_IDMA_PRC_DBG_WR_DW_CNT_LSB_WIDTH    ((uint32_t)0x00000004)
#define IDMA_IDMA_PRC_DBG_RD_DW_CNT_LSB_MASK    ((uint32_t)0x0001E000)
#define IDMA_IDMA_PRC_DBG_RD_DW_CNT_LSB_LSB    13
#define IDMA_IDMA_PRC_DBG_RD_DW_CNT_LSB_WIDTH    ((uint32_t)0x00000004)
#define IDMA_IDMA_PRC_DBG_DATA_FIFO_POP_BIT    ((uint32_t)0x00001000)
#define IDMA_IDMA_PRC_DBG_DATA_FIFO_POP_POS    12
#define IDMA_IDMA_PRC_DBG_DATA_FIFO_PUSH_BIT    ((uint32_t)0x00000800)
#define IDMA_IDMA_PRC_DBG_DATA_FIFO_PUSH_POS    11
#define IDMA_IDMA_PRC_DBG_REQ_FIFO_POP_BIT    ((uint32_t)0x00000400)
#define IDMA_IDMA_PRC_DBG_REQ_FIFO_POP_POS    10
#define IDMA_IDMA_PRC_DBG_REQ_FIFO_PUSH_BIT    ((uint32_t)0x00000200)
#define IDMA_IDMA_PRC_DBG_REQ_FIFO_PUSH_POS    9
#define IDMA_IDMA_PRC_DBG_WR_SM_MASK        ((uint32_t)0x000001C0)
#define IDMA_IDMA_PRC_DBG_WR_SM_LSB         6
#define IDMA_IDMA_PRC_DBG_WR_SM_WIDTH       ((uint32_t)0x00000003)
#define IDMA_IDMA_PRC_DBG_RD_SM_MASK        ((uint32_t)0x00000038)
#define IDMA_IDMA_PRC_DBG_RD_SM_LSB         3
#define IDMA_IDMA_PRC_DBG_RD_SM_WIDTH       ((uint32_t)0x00000003)
#define IDMA_IDMA_PRC_DBG_PRC_SM_MASK       ((uint32_t)0x00000007)
#define IDMA_IDMA_PRC_DBG_PRC_SM_LSB        0
#define IDMA_IDMA_PRC_DBG_PRC_SM_WIDTH      ((uint32_t)0x00000003)

#define IDMA_IDMA_PRC_DBG_SMAC_INT_RST      0x0
#define IDMA_IDMA_PRC_DBG_LMAC_INT_RST      0x0
#define IDMA_IDMA_PRC_DBG_UMAC_INT_RST      0x0
#define IDMA_IDMA_PRC_DBG_AVAILABLE_WR_BURST_CNT_RST    0x0
#define IDMA_IDMA_PRC_DBG_WR_DW_CNT_LSB_RST    0x0
#define IDMA_IDMA_PRC_DBG_RD_DW_CNT_LSB_RST    0x0
#define IDMA_IDMA_PRC_DBG_DATA_FIFO_POP_RST    0x0
#define IDMA_IDMA_PRC_DBG_DATA_FIFO_PUSH_RST    0x0
#define IDMA_IDMA_PRC_DBG_REQ_FIFO_POP_RST    0x0
#define IDMA_IDMA_PRC_DBG_REQ_FIFO_PUSH_RST    0x0
#define IDMA_IDMA_PRC_DBG_WR_SM_RST         0x0
#define IDMA_IDMA_PRC_DBG_RD_SM_RST         0x0
#define IDMA_IDMA_PRC_DBG_PRC_SM_RST        0x0

__INLINE void idma_idma_prc_dbg_unpack(uint8_t* smac_int, uint8_t* lmac_int, uint8_t* umac_int, uint8_t* available_wr_burst_cnt, uint8_t* wr_dw_cnt_lsb, uint8_t* rd_dw_cnt_lsb, uint8_t* data_fifo_pop, uint8_t* data_fifo_push, uint8_t* req_fifo_pop, uint8_t* req_fifo_push, uint8_t* wr_sm, uint8_t* rd_sm, uint8_t* prc_sm)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);

	*smac_int = (localVal & ((uint32_t)0x80000000)) >>  31;
	*lmac_int = (localVal & ((uint32_t)0x40000000)) >>  30;
	*umac_int = (localVal & ((uint32_t)0x20000000)) >>  29;
	*available_wr_burst_cnt = (localVal & ((uint32_t)0x1FE00000)) >>  21;
	*wr_dw_cnt_lsb = (localVal & ((uint32_t)0x001E0000)) >>  17;
	*rd_dw_cnt_lsb = (localVal & ((uint32_t)0x0001E000)) >>  13;
	*data_fifo_pop = (localVal & ((uint32_t)0x00001000)) >>  12;
	*data_fifo_push = (localVal & ((uint32_t)0x00000800)) >>  11;
	*req_fifo_pop = (localVal & ((uint32_t)0x00000400)) >>  10;
	*req_fifo_push = (localVal & ((uint32_t)0x00000200)) >>  9;
	*wr_sm = (localVal & ((uint32_t)0x000001C0)) >>  6;
	*rd_sm = (localVal & ((uint32_t)0x00000038)) >>  3;
	*prc_sm = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t idma_idma_prc_dbg_smac_int_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE uint8_t idma_idma_prc_dbg_lmac_int_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE uint8_t idma_idma_prc_dbg_umac_int_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE uint8_t idma_idma_prc_dbg_available_wr_burst_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1FE00000)) >> 21);
}
__INLINE uint8_t idma_idma_prc_dbg_wr_dw_cnt_lsb_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001E0000)) >> 17);
}
__INLINE uint8_t idma_idma_prc_dbg_rd_dw_cnt_lsb_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0001E000)) >> 13);
}
__INLINE uint8_t idma_idma_prc_dbg_data_fifo_pop_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t idma_idma_prc_dbg_data_fifo_push_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t idma_idma_prc_dbg_req_fifo_pop_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t idma_idma_prc_dbg_req_fifo_push_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t idma_idma_prc_dbg_wr_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001C0)) >> 6);
}
__INLINE uint8_t idma_idma_prc_dbg_rd_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE uint8_t idma_idma_prc_dbg_prc_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_PRC_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief IDMA_AXI_DBG register definition
 *  AXI debug register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:04 AXI_WR_SM                 0x0
 *    03:02 RESERVED                  0x0
 *    01:00 AXI_RD_SM                 0x0
 * </pre>
 */
#define IDMA_IDMA_AXI_DBG_ADDR        (REG_IDMA_BASE_ADDR+0x000000F4)
#define IDMA_IDMA_AXI_DBG_OFFSET      0x000000F4
#define IDMA_IDMA_AXI_DBG_INDEX       0x0000003D
#define IDMA_IDMA_AXI_DBG_RESET       0x00000000

__INLINE uint32_t  idma_idma_axi_dbg_get(void)
{
	return REG_PL_RD(IDMA_IDMA_AXI_DBG_ADDR);
}

// field definitions
#define IDMA_IDMA_AXI_DBG_AXI_WR_SM_MASK    ((uint32_t)0x000000F0)
#define IDMA_IDMA_AXI_DBG_AXI_WR_SM_LSB     4
#define IDMA_IDMA_AXI_DBG_AXI_WR_SM_WIDTH    ((uint32_t)0x00000004)
#define IDMA_IDMA_AXI_DBG_RESERVED_MASK     ((uint32_t)0x0000000C)
#define IDMA_IDMA_AXI_DBG_RESERVED_LSB      2
#define IDMA_IDMA_AXI_DBG_RESERVED_WIDTH    ((uint32_t)0x00000002)
#define IDMA_IDMA_AXI_DBG_AXI_RD_SM_MASK    ((uint32_t)0x00000003)
#define IDMA_IDMA_AXI_DBG_AXI_RD_SM_LSB     0
#define IDMA_IDMA_AXI_DBG_AXI_RD_SM_WIDTH    ((uint32_t)0x00000002)

#define IDMA_IDMA_AXI_DBG_AXI_WR_SM_RST     0x0
#define IDMA_IDMA_AXI_DBG_RESERVED_RST      0x0
#define IDMA_IDMA_AXI_DBG_AXI_RD_SM_RST     0x0

__INLINE void idma_idma_axi_dbg_unpack(uint8_t* axi_wr_sm, uint8_t* reserved, uint8_t* axi_rd_sm)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_AXI_DBG_ADDR);

	*axi_wr_sm = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*reserved = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*axi_rd_sm = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t idma_idma_axi_dbg_axi_wr_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_AXI_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t idma_idma_axi_dbg_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_AXI_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE uint8_t idma_idma_axi_dbg_axi_rd_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_AXI_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief IDMA_DBG_CONFIG register definition
 *  Debug config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    DBG_EN                    0              
 *    02:00 DBG_SEL                   0x0
 * </pre>
 */
#define IDMA_IDMA_DBG_CONFIG_ADDR        (REG_IDMA_BASE_ADDR+0x000000F8)
#define IDMA_IDMA_DBG_CONFIG_OFFSET      0x000000F8
#define IDMA_IDMA_DBG_CONFIG_INDEX       0x0000003E
#define IDMA_IDMA_DBG_CONFIG_RESET       0x00000000

__INLINE uint32_t  idma_idma_dbg_config_get(void)
{
	return REG_PL_RD(IDMA_IDMA_DBG_CONFIG_ADDR);
}

__INLINE void idma_idma_dbg_config_set(uint32_t value)
{
	REG_PL_WR(IDMA_IDMA_DBG_CONFIG_ADDR, value);
}

// field definitions
#define IDMA_IDMA_DBG_CONFIG_DBG_EN_BIT     ((uint32_t)0x00000008)
#define IDMA_IDMA_DBG_CONFIG_DBG_EN_POS     3
#define IDMA_IDMA_DBG_CONFIG_DBG_SEL_MASK    ((uint32_t)0x00000007)
#define IDMA_IDMA_DBG_CONFIG_DBG_SEL_LSB    0
#define IDMA_IDMA_DBG_CONFIG_DBG_SEL_WIDTH    ((uint32_t)0x00000003)

#define IDMA_IDMA_DBG_CONFIG_DBG_EN_RST     0x0
#define IDMA_IDMA_DBG_CONFIG_DBG_SEL_RST    0x0

__INLINE void idma_idma_dbg_config_pack(uint8_t dbg_en, uint8_t dbg_sel)
{
	ASSERT_ERR((((uint32_t)dbg_en << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)dbg_sel << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IDMA_IDMA_DBG_CONFIG_ADDR,  ((uint32_t)dbg_en << 3) |((uint32_t)dbg_sel << 0));
}

__INLINE void idma_idma_dbg_config_unpack(uint8_t* dbg_en, uint8_t* dbg_sel)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_DBG_CONFIG_ADDR);

	*dbg_en = (localVal & ((uint32_t)0x00000008)) >>  3;
	*dbg_sel = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t idma_idma_dbg_config_dbg_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_DBG_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void idma_idma_dbg_config_dbg_en_setf(uint8_t dbgen)
{
	ASSERT_ERR((((uint32_t)dbgen << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(IDMA_IDMA_DBG_CONFIG_ADDR, (REG_PL_RD(IDMA_IDMA_DBG_CONFIG_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)dbgen <<3));
}
__INLINE uint8_t idma_idma_dbg_config_dbg_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_DBG_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void idma_idma_dbg_config_dbg_sel_setf(uint8_t dbgsel)
{
	ASSERT_ERR((((uint32_t)dbgsel << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IDMA_IDMA_DBG_CONFIG_ADDR, (REG_PL_RD(IDMA_IDMA_DBG_CONFIG_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)dbgsel <<0));
}

/**
 * @brief IDMA_DBG_DATA register definition
 *  Debug data register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DBG_DATA                  0x0
 * </pre>
 */
#define IDMA_IDMA_DBG_DATA_ADDR        (REG_IDMA_BASE_ADDR+0x000000FC)
#define IDMA_IDMA_DBG_DATA_OFFSET      0x000000FC
#define IDMA_IDMA_DBG_DATA_INDEX       0x0000003F
#define IDMA_IDMA_DBG_DATA_RESET       0x00000000

__INLINE uint32_t  idma_idma_dbg_data_get(void)
{
	return REG_PL_RD(IDMA_IDMA_DBG_DATA_ADDR);
}

// field definitions
#define IDMA_IDMA_DBG_DATA_DBG_DATA_MASK    ((uint32_t)0xFFFFFFFF)
#define IDMA_IDMA_DBG_DATA_DBG_DATA_LSB     0
#define IDMA_IDMA_DBG_DATA_DBG_DATA_WIDTH    ((uint32_t)0x00000020)

#define IDMA_IDMA_DBG_DATA_DBG_DATA_RST     0x0

__INLINE uint32_t idma_idma_dbg_data_dbg_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(IDMA_IDMA_DBG_DATA_ADDR);
	return (uint32_t)(localVal >> 0);
}


#undef DBG_FILEID
#endif //_REG_IDMA_H_
