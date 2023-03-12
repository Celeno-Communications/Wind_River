#ifndef _REG_USBC_H_
#define _REG_USBC_H_

#include <stdint.h>
#include "_reg_usbc.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_USBC__H__FILEID__

#define REG_USBC_COUNT  244


/**
 * @brief GSBUSCFG_0 register definition
 *  Global SoC Bus Configuration Register 0  This register configures system bus DMA options for the master bus, which may be configured as AHB, AXI, or Native. Options include burst length and cache type (bufferable/posted, cacheable/snoop, and so on). The application can program this register upon power-on, or a change in mode of operation after the DMA engine is halted.  xHCI Register Power-On Value:  If you are using a standard xHCI host driver, make sure to set the register s power-on value during coreConsultant configuration (DWC_USB3_GSBUSCFG0_INIT parameter) because the standard xHCI driver does not access this register.  For more details on this register, refer to the following sections:  -  Usage of Global SoC Bus Configuration Register 0 (GSBUSCFG0)  section in the Programming Guide  -  System Bus Interface  section in the Databook register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 DATRDREQINFO              0x0
 *    27:24 DESRDREQINFO              0x0
 *    23:20 DATWRREQINFO              0x0
 *    19:16 DESWRREQINFO              0x0
 *    15:12 reserved_15_12            0x0
 *    11    DATBIGEND                 0              
 *    10    DESBIGEND                 0              
 *    09:08 reserved_9_8              0x0
 *    07    INCR256_BRSTENA           0              
 *    06    INCR128_BRSTENA           0              
 *    05    INCR64_BRSTENA            0              
 *    04    INCR32_BRSTENA            0              
 *    03    INCR16_BRSTENA            0              
 *    02    INCR8_BRSTENA             0              
 *    01    INCR4_BRSTENA             1              
 *    00    INCRBRSTENA               0              
 * </pre>
 */
#define USBC_GSBUSCFG_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C100)
#define USBC_GSBUSCFG_0_OFFSET      0x0000C100
#define USBC_GSBUSCFG_0_INDEX       0x00003040
#define USBC_GSBUSCFG_0_RESET       0x00000002

__INLINE uint32_t  usbc_gsbuscfg_0_get(void)
{
	return REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
}

__INLINE void usbc_gsbuscfg_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, value);
}

// field definitions
#define USBC_GSBUSCFG_0_DATRDREQINFO_MASK    ((uint32_t)0xF0000000)
#define USBC_GSBUSCFG_0_DATRDREQINFO_LSB    28
#define USBC_GSBUSCFG_0_DATRDREQINFO_WIDTH    ((uint32_t)0x00000004)
#define USBC_GSBUSCFG_0_DESRDREQINFO_MASK    ((uint32_t)0x0F000000)
#define USBC_GSBUSCFG_0_DESRDREQINFO_LSB    24
#define USBC_GSBUSCFG_0_DESRDREQINFO_WIDTH    ((uint32_t)0x00000004)
#define USBC_GSBUSCFG_0_DATWRREQINFO_MASK    ((uint32_t)0x00F00000)
#define USBC_GSBUSCFG_0_DATWRREQINFO_LSB    20
#define USBC_GSBUSCFG_0_DATWRREQINFO_WIDTH    ((uint32_t)0x00000004)
#define USBC_GSBUSCFG_0_DESWRREQINFO_MASK    ((uint32_t)0x000F0000)
#define USBC_GSBUSCFG_0_DESWRREQINFO_LSB    16
#define USBC_GSBUSCFG_0_DESWRREQINFO_WIDTH    ((uint32_t)0x00000004)
#define USBC_GSBUSCFG_0_RESERVED_15_12_MASK    ((uint32_t)0x0000F000)
#define USBC_GSBUSCFG_0_RESERVED_15_12_LSB    12
#define USBC_GSBUSCFG_0_RESERVED_15_12_WIDTH    ((uint32_t)0x00000004)
#define USBC_GSBUSCFG_0_DATBIGEND_BIT       ((uint32_t)0x00000800)
#define USBC_GSBUSCFG_0_DATBIGEND_POS       11
#define USBC_GSBUSCFG_0_DESBIGEND_BIT       ((uint32_t)0x00000400)
#define USBC_GSBUSCFG_0_DESBIGEND_POS       10
#define USBC_GSBUSCFG_0_RESERVED_9_8_MASK    ((uint32_t)0x00000300)
#define USBC_GSBUSCFG_0_RESERVED_9_8_LSB    8
#define USBC_GSBUSCFG_0_RESERVED_9_8_WIDTH    ((uint32_t)0x00000002)
#define USBC_GSBUSCFG_0_INCR_256_BRSTENA_BIT    ((uint32_t)0x00000080)
#define USBC_GSBUSCFG_0_INCR_256_BRSTENA_POS    7
#define USBC_GSBUSCFG_0_INCR_128_BRSTENA_BIT    ((uint32_t)0x00000040)
#define USBC_GSBUSCFG_0_INCR_128_BRSTENA_POS    6
#define USBC_GSBUSCFG_0_INCR_64_BRSTENA_BIT    ((uint32_t)0x00000020)
#define USBC_GSBUSCFG_0_INCR_64_BRSTENA_POS    5
#define USBC_GSBUSCFG_0_INCR_32_BRSTENA_BIT    ((uint32_t)0x00000010)
#define USBC_GSBUSCFG_0_INCR_32_BRSTENA_POS    4
#define USBC_GSBUSCFG_0_INCR_16_BRSTENA_BIT    ((uint32_t)0x00000008)
#define USBC_GSBUSCFG_0_INCR_16_BRSTENA_POS    3
#define USBC_GSBUSCFG_0_INCR_8_BRSTENA_BIT    ((uint32_t)0x00000004)
#define USBC_GSBUSCFG_0_INCR_8_BRSTENA_POS    2
#define USBC_GSBUSCFG_0_INCR_4_BRSTENA_BIT    ((uint32_t)0x00000002)
#define USBC_GSBUSCFG_0_INCR_4_BRSTENA_POS    1
#define USBC_GSBUSCFG_0_INCRBRSTENA_BIT     ((uint32_t)0x00000001)
#define USBC_GSBUSCFG_0_INCRBRSTENA_POS     0

#define USBC_GSBUSCFG_0_DATRDREQINFO_RST    0x0
#define USBC_GSBUSCFG_0_DESRDREQINFO_RST    0x0
#define USBC_GSBUSCFG_0_DATWRREQINFO_RST    0x0
#define USBC_GSBUSCFG_0_DESWRREQINFO_RST    0x0
#define USBC_GSBUSCFG_0_RESERVED_15_12_RST    0x0
#define USBC_GSBUSCFG_0_DATBIGEND_RST       0x0
#define USBC_GSBUSCFG_0_DESBIGEND_RST       0x0
#define USBC_GSBUSCFG_0_RESERVED_9_8_RST    0x0
#define USBC_GSBUSCFG_0_INCR_256_BRSTENA_RST    0x0
#define USBC_GSBUSCFG_0_INCR_128_BRSTENA_RST    0x0
#define USBC_GSBUSCFG_0_INCR_64_BRSTENA_RST    0x0
#define USBC_GSBUSCFG_0_INCR_32_BRSTENA_RST    0x0
#define USBC_GSBUSCFG_0_INCR_16_BRSTENA_RST    0x0
#define USBC_GSBUSCFG_0_INCR_8_BRSTENA_RST    0x0
#define USBC_GSBUSCFG_0_INCR_4_BRSTENA_RST    0x1
#define USBC_GSBUSCFG_0_INCRBRSTENA_RST     0x0

__INLINE void usbc_gsbuscfg_0_pack(uint8_t datrdreqinfo, uint8_t desrdreqinfo, uint8_t datwrreqinfo, uint8_t deswrreqinfo, uint8_t reserved_15_12, uint8_t datbigend, uint8_t desbigend, uint8_t reserved_9_8, uint8_t incr256_brstena, uint8_t incr128_brstena, uint8_t incr64_brstena, uint8_t incr32_brstena, uint8_t incr16_brstena, uint8_t incr8_brstena, uint8_t incr4_brstena, uint8_t incrbrstena)
{
	ASSERT_ERR((((uint32_t)datrdreqinfo << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)desrdreqinfo << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)datwrreqinfo << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)deswrreqinfo << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_15_12 << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)datbigend << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)desbigend << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9_8 << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)incr256_brstena << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)incr128_brstena << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)incr64_brstena << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)incr32_brstena << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)incr16_brstena << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)incr8_brstena << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)incr4_brstena << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)incrbrstena << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR,  ((uint32_t)datrdreqinfo << 28) |((uint32_t)desrdreqinfo << 24) |((uint32_t)datwrreqinfo << 20) |((uint32_t)deswrreqinfo << 16) |((uint32_t)reserved_15_12 << 12) |((uint32_t)datbigend << 11) |((uint32_t)desbigend << 10) |((uint32_t)reserved_9_8 << 8) |((uint32_t)incr256_brstena << 7) |((uint32_t)incr128_brstena << 6) |((uint32_t)incr64_brstena << 5) |((uint32_t)incr32_brstena << 4) |((uint32_t)incr16_brstena << 3) |((uint32_t)incr8_brstena << 2) |((uint32_t)incr4_brstena << 1) |((uint32_t)incrbrstena << 0));
}

__INLINE void usbc_gsbuscfg_0_unpack(uint8_t* datrdreqinfo, uint8_t* desrdreqinfo, uint8_t* datwrreqinfo, uint8_t* deswrreqinfo, uint8_t* reserved_15_12, uint8_t* datbigend, uint8_t* desbigend, uint8_t* reserved_9_8, uint8_t* incr256_brstena, uint8_t* incr128_brstena, uint8_t* incr64_brstena, uint8_t* incr32_brstena, uint8_t* incr16_brstena, uint8_t* incr8_brstena, uint8_t* incr4_brstena, uint8_t* incrbrstena)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);

	*datrdreqinfo = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*desrdreqinfo = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*datwrreqinfo = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*deswrreqinfo = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*reserved_15_12 = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*datbigend = (localVal & ((uint32_t)0x00000800)) >>  11;
	*desbigend = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9_8 = (localVal & ((uint32_t)0x00000300)) >>  8;
	*incr256_brstena = (localVal & ((uint32_t)0x00000080)) >>  7;
	*incr128_brstena = (localVal & ((uint32_t)0x00000040)) >>  6;
	*incr64_brstena = (localVal & ((uint32_t)0x00000020)) >>  5;
	*incr32_brstena = (localVal & ((uint32_t)0x00000010)) >>  4;
	*incr16_brstena = (localVal & ((uint32_t)0x00000008)) >>  3;
	*incr8_brstena = (localVal & ((uint32_t)0x00000004)) >>  2;
	*incr4_brstena = (localVal & ((uint32_t)0x00000002)) >>  1;
	*incrbrstena = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t usbc_gsbuscfg_0_datrdreqinfo_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void usbc_gsbuscfg_0_datrdreqinfo_setf(uint8_t datrdreqinfo)
{
	ASSERT_ERR((((uint32_t)datrdreqinfo << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)datrdreqinfo <<28));
}
__INLINE uint8_t usbc_gsbuscfg_0_desrdreqinfo_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void usbc_gsbuscfg_0_desrdreqinfo_setf(uint8_t desrdreqinfo)
{
	ASSERT_ERR((((uint32_t)desrdreqinfo << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)desrdreqinfo <<24));
}
__INLINE uint8_t usbc_gsbuscfg_0_datwrreqinfo_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void usbc_gsbuscfg_0_datwrreqinfo_setf(uint8_t datwrreqinfo)
{
	ASSERT_ERR((((uint32_t)datwrreqinfo << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)datwrreqinfo <<20));
}
__INLINE uint8_t usbc_gsbuscfg_0_deswrreqinfo_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void usbc_gsbuscfg_0_deswrreqinfo_setf(uint8_t deswrreqinfo)
{
	ASSERT_ERR((((uint32_t)deswrreqinfo << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)deswrreqinfo <<16));
}
__INLINE uint8_t usbc_gsbuscfg_0_reserved_15_12_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE uint8_t usbc_gsbuscfg_0_datbigend_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_gsbuscfg_0_datbigend_setf(uint8_t datbigend)
{
	ASSERT_ERR((((uint32_t)datbigend << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)datbigend <<11));
}
__INLINE uint8_t usbc_gsbuscfg_0_desbigend_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_gsbuscfg_0_desbigend_setf(uint8_t desbigend)
{
	ASSERT_ERR((((uint32_t)desbigend << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)desbigend <<10));
}
__INLINE uint8_t usbc_gsbuscfg_0_reserved_9_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE uint8_t usbc_gsbuscfg_0_incr_256_brstena_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void usbc_gsbuscfg_0_incr_256_brstena_setf(uint8_t incr256brstena)
{
	ASSERT_ERR((((uint32_t)incr256brstena << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)incr256brstena <<7));
}
__INLINE uint8_t usbc_gsbuscfg_0_incr_128_brstena_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void usbc_gsbuscfg_0_incr_128_brstena_setf(uint8_t incr128brstena)
{
	ASSERT_ERR((((uint32_t)incr128brstena << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)incr128brstena <<6));
}
__INLINE uint8_t usbc_gsbuscfg_0_incr_64_brstena_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void usbc_gsbuscfg_0_incr_64_brstena_setf(uint8_t incr64brstena)
{
	ASSERT_ERR((((uint32_t)incr64brstena << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)incr64brstena <<5));
}
__INLINE uint8_t usbc_gsbuscfg_0_incr_32_brstena_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void usbc_gsbuscfg_0_incr_32_brstena_setf(uint8_t incr32brstena)
{
	ASSERT_ERR((((uint32_t)incr32brstena << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)incr32brstena <<4));
}
__INLINE uint8_t usbc_gsbuscfg_0_incr_16_brstena_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void usbc_gsbuscfg_0_incr_16_brstena_setf(uint8_t incr16brstena)
{
	ASSERT_ERR((((uint32_t)incr16brstena << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)incr16brstena <<3));
}
__INLINE uint8_t usbc_gsbuscfg_0_incr_8_brstena_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void usbc_gsbuscfg_0_incr_8_brstena_setf(uint8_t incr8brstena)
{
	ASSERT_ERR((((uint32_t)incr8brstena << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)incr8brstena <<2));
}
__INLINE uint8_t usbc_gsbuscfg_0_incr_4_brstena_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void usbc_gsbuscfg_0_incr_4_brstena_setf(uint8_t incr4brstena)
{
	ASSERT_ERR((((uint32_t)incr4brstena << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)incr4brstena <<1));
}
__INLINE uint8_t usbc_gsbuscfg_0_incrbrstena_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void usbc_gsbuscfg_0_incrbrstena_setf(uint8_t incrbrstena)
{
	ASSERT_ERR((((uint32_t)incrbrstena << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_0_ADDR, (REG_PL_RD(USBC_GSBUSCFG_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)incrbrstena <<0));
}

/**
 * @brief GSBUSCFG_1 register definition
 *  Global SoC Bus Configuration Register 1  xHCI Register Power-On Value:  If you are using a standard xHCI host driver, make sure to set the register s power-on value during coreConsultant configuration (DWC_USB3_GSBUSCFG1_INIT parameter) because the standard xHCI driver does not access this register.  For more details on this register, refer to  System Bus Interface  section in the Databook. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:13 reserved_31_13            0x0
 *    12    EN1_KPAGE                 0              
 *    11:08 Pipe_Trans_Limit          0x7
 *    07:00 reserved_7_0              0x0
 * </pre>
 */
#define USBC_GSBUSCFG_1_ADDR        (REG_USBC_BASE_ADDR+0x0000C104)
#define USBC_GSBUSCFG_1_OFFSET      0x0000C104
#define USBC_GSBUSCFG_1_INDEX       0x00003041
#define USBC_GSBUSCFG_1_RESET       0x00000700

__INLINE uint32_t  usbc_gsbuscfg_1_get(void)
{
	return REG_PL_RD(USBC_GSBUSCFG_1_ADDR);
}

__INLINE void usbc_gsbuscfg_1_set(uint32_t value)
{
	REG_PL_WR(USBC_GSBUSCFG_1_ADDR, value);
}

// field definitions
#define USBC_GSBUSCFG_1_RESERVED_31_13_MASK    ((uint32_t)0xFFFFE000)
#define USBC_GSBUSCFG_1_RESERVED_31_13_LSB    13
#define USBC_GSBUSCFG_1_RESERVED_31_13_WIDTH    ((uint32_t)0x00000013)
#define USBC_GSBUSCFG_1_EN_1_KPAGE_BIT      ((uint32_t)0x00001000)
#define USBC_GSBUSCFG_1_EN_1_KPAGE_POS      12
#define USBC_GSBUSCFG_1_PIPE_TRANS_LIMIT_MASK    ((uint32_t)0x00000F00)
#define USBC_GSBUSCFG_1_PIPE_TRANS_LIMIT_LSB    8
#define USBC_GSBUSCFG_1_PIPE_TRANS_LIMIT_WIDTH    ((uint32_t)0x00000004)
#define USBC_GSBUSCFG_1_RESERVED_7_0_MASK    ((uint32_t)0x000000FF)
#define USBC_GSBUSCFG_1_RESERVED_7_0_LSB    0
#define USBC_GSBUSCFG_1_RESERVED_7_0_WIDTH    ((uint32_t)0x00000008)

#define USBC_GSBUSCFG_1_RESERVED_31_13_RST    0x0
#define USBC_GSBUSCFG_1_EN_1_KPAGE_RST      0x0
#define USBC_GSBUSCFG_1_PIPE_TRANS_LIMIT_RST    0x7
#define USBC_GSBUSCFG_1_RESERVED_7_0_RST    0x0

__INLINE void usbc_gsbuscfg_1_pack(uint32_t reserved_31_13, uint8_t en1_kpage, uint8_t pipe_trans_limit, uint8_t reserved_7_0)
{
	ASSERT_ERR((((uint32_t)reserved_31_13 << 13) & ~((uint32_t)0xFFFFE000)) == 0);
	ASSERT_ERR((((uint32_t)en1_kpage << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)pipe_trans_limit << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_1_ADDR,  ((uint32_t)reserved_31_13 << 13) |((uint32_t)en1_kpage << 12) |((uint32_t)pipe_trans_limit << 8) |((uint32_t)reserved_7_0 << 0));
}

__INLINE void usbc_gsbuscfg_1_unpack(uint32_t* reserved_31_13, uint8_t* en1_kpage, uint8_t* pipe_trans_limit, uint8_t* reserved_7_0)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_1_ADDR);

	*reserved_31_13 = (localVal & ((uint32_t)0xFFFFE000)) >>  13;
	*en1_kpage = (localVal & ((uint32_t)0x00001000)) >>  12;
	*pipe_trans_limit = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*reserved_7_0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint32_t usbc_gsbuscfg_1_reserved_31_13_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_1_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFE000)) >> 13);
}
__INLINE uint8_t usbc_gsbuscfg_1_en_1_kpage_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void usbc_gsbuscfg_1_en_1_kpage_setf(uint8_t en1kpage)
{
	ASSERT_ERR((((uint32_t)en1kpage << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_1_ADDR, (REG_PL_RD(USBC_GSBUSCFG_1_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)en1kpage <<12));
}
__INLINE uint8_t usbc_gsbuscfg_1_pipe_trans_limit_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void usbc_gsbuscfg_1_pipe_trans_limit_setf(uint8_t pipetranslimit)
{
	ASSERT_ERR((((uint32_t)pipetranslimit << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(USBC_GSBUSCFG_1_ADDR, (REG_PL_RD(USBC_GSBUSCFG_1_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)pipetranslimit <<8));
}
__INLINE uint8_t usbc_gsbuscfg_1_reserved_7_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSBUSCFG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief GTXTHRCFG register definition
 *  Global Tx Threshold Control Register  For more information on  - Using this register, refer to  Packet Threshold and Burst Features for High Latency Systems  section in the Databook.  - Selecting values for the fields of this register, see the  TX/RX Data FIFO Sizes and TX/RX Threshold Control Register Settings  section in the User Guide. Note:  - GTXTHRCFG register is not applicable for Debug Target.  - GTXTHRCFG register is not applicable in USB 2.0-only mode. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    reserved_31               0              
 *    30    reserved_30               0              
 *    29    Usb_Tx_Pkt_Cnt_Sel        0              
 *    28    reserved_28               0              
 *    27:24 Usb_Tx_Pkt_Cnt            0x0
 *    23:16 Usb_Max_Tx_Burst_Size     0x0
 *    15    reserved_15               0              
 *    14    reserved_14               0              
 *    13:11 reserved_13_11            0x0
 *    10:00 reserved_10_0             0x0
 * </pre>
 */
#define USBC_GTXTHRCFG_ADDR        (REG_USBC_BASE_ADDR+0x0000C108)
#define USBC_GTXTHRCFG_OFFSET      0x0000C108
#define USBC_GTXTHRCFG_INDEX       0x00003042
#define USBC_GTXTHRCFG_RESET       0x00000000

__INLINE uint32_t  usbc_gtxthrcfg_get(void)
{
	return REG_PL_RD(USBC_GTXTHRCFG_ADDR);
}

__INLINE void usbc_gtxthrcfg_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXTHRCFG_ADDR, value);
}

// field definitions
#define USBC_GTXTHRCFG_RESERVED_31_BIT      ((uint32_t)0x80000000)
#define USBC_GTXTHRCFG_RESERVED_31_POS      31
#define USBC_GTXTHRCFG_RESERVED_30_BIT      ((uint32_t)0x40000000)
#define USBC_GTXTHRCFG_RESERVED_30_POS      30
#define USBC_GTXTHRCFG_USB_TX_PKT_CNT_SEL_BIT    ((uint32_t)0x20000000)
#define USBC_GTXTHRCFG_USB_TX_PKT_CNT_SEL_POS    29
#define USBC_GTXTHRCFG_RESERVED_28_BIT      ((uint32_t)0x10000000)
#define USBC_GTXTHRCFG_RESERVED_28_POS      28
#define USBC_GTXTHRCFG_USB_TX_PKT_CNT_MASK    ((uint32_t)0x0F000000)
#define USBC_GTXTHRCFG_USB_TX_PKT_CNT_LSB    24
#define USBC_GTXTHRCFG_USB_TX_PKT_CNT_WIDTH    ((uint32_t)0x00000004)
#define USBC_GTXTHRCFG_USB_MAX_TX_BURST_SIZE_MASK    ((uint32_t)0x00FF0000)
#define USBC_GTXTHRCFG_USB_MAX_TX_BURST_SIZE_LSB    16
#define USBC_GTXTHRCFG_USB_MAX_TX_BURST_SIZE_WIDTH    ((uint32_t)0x00000008)
#define USBC_GTXTHRCFG_RESERVED_15_BIT      ((uint32_t)0x00008000)
#define USBC_GTXTHRCFG_RESERVED_15_POS      15
#define USBC_GTXTHRCFG_RESERVED_14_BIT      ((uint32_t)0x00004000)
#define USBC_GTXTHRCFG_RESERVED_14_POS      14
#define USBC_GTXTHRCFG_RESERVED_13_11_MASK    ((uint32_t)0x00003800)
#define USBC_GTXTHRCFG_RESERVED_13_11_LSB    11
#define USBC_GTXTHRCFG_RESERVED_13_11_WIDTH    ((uint32_t)0x00000003)
#define USBC_GTXTHRCFG_RESERVED_10_0_MASK    ((uint32_t)0x000007FF)
#define USBC_GTXTHRCFG_RESERVED_10_0_LSB    0
#define USBC_GTXTHRCFG_RESERVED_10_0_WIDTH    ((uint32_t)0x0000000B)

#define USBC_GTXTHRCFG_RESERVED_31_RST      0x0
#define USBC_GTXTHRCFG_RESERVED_30_RST      0x0
#define USBC_GTXTHRCFG_USB_TX_PKT_CNT_SEL_RST    0x0
#define USBC_GTXTHRCFG_RESERVED_28_RST      0x0
#define USBC_GTXTHRCFG_USB_TX_PKT_CNT_RST    0x0
#define USBC_GTXTHRCFG_USB_MAX_TX_BURST_SIZE_RST    0x0
#define USBC_GTXTHRCFG_RESERVED_15_RST      0x0
#define USBC_GTXTHRCFG_RESERVED_14_RST      0x0
#define USBC_GTXTHRCFG_RESERVED_13_11_RST    0x0
#define USBC_GTXTHRCFG_RESERVED_10_0_RST    0x0

__INLINE void usbc_gtxthrcfg_pack(uint8_t reserved_31, uint8_t reserved_30, uint8_t usb_tx_pkt_cnt_sel, uint8_t reserved_28, uint8_t usb_tx_pkt_cnt, uint8_t usb_max_tx_burst_size, uint8_t reserved_15, uint8_t reserved_14, uint8_t reserved_13_11, uint16_t reserved_10_0)
{
	ASSERT_ERR((((uint32_t)reserved_31 << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_30 << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)usb_tx_pkt_cnt_sel << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_28 << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)usb_tx_pkt_cnt << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)usb_max_tx_burst_size << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_15 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_14 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_13_11 << 11) & ~((uint32_t)0x00003800)) == 0);
	ASSERT_ERR((((uint32_t)reserved_10_0 << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(USBC_GTXTHRCFG_ADDR,  ((uint32_t)reserved_31 << 31) |((uint32_t)reserved_30 << 30) |((uint32_t)usb_tx_pkt_cnt_sel << 29) |((uint32_t)reserved_28 << 28) |((uint32_t)usb_tx_pkt_cnt << 24) |((uint32_t)usb_max_tx_burst_size << 16) |((uint32_t)reserved_15 << 15) |((uint32_t)reserved_14 << 14) |((uint32_t)reserved_13_11 << 11) |((uint32_t)reserved_10_0 << 0));
}

__INLINE void usbc_gtxthrcfg_unpack(uint8_t* reserved_31, uint8_t* reserved_30, uint8_t* usb_tx_pkt_cnt_sel, uint8_t* reserved_28, uint8_t* usb_tx_pkt_cnt, uint8_t* usb_max_tx_burst_size, uint8_t* reserved_15, uint8_t* reserved_14, uint8_t* reserved_13_11, uint16_t* reserved_10_0)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXTHRCFG_ADDR);

	*reserved_31 = (localVal & ((uint32_t)0x80000000)) >>  31;
	*reserved_30 = (localVal & ((uint32_t)0x40000000)) >>  30;
	*usb_tx_pkt_cnt_sel = (localVal & ((uint32_t)0x20000000)) >>  29;
	*reserved_28 = (localVal & ((uint32_t)0x10000000)) >>  28;
	*usb_tx_pkt_cnt = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*usb_max_tx_burst_size = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*reserved_15 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*reserved_14 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*reserved_13_11 = (localVal & ((uint32_t)0x00003800)) >>  11;
	*reserved_10_0 = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint8_t usbc_gtxthrcfg_reserved_31_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE uint8_t usbc_gtxthrcfg_reserved_30_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE uint8_t usbc_gtxthrcfg_usb_tx_pkt_cnt_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void usbc_gtxthrcfg_usb_tx_pkt_cnt_sel_setf(uint8_t usbtxpktcntsel)
{
	ASSERT_ERR((((uint32_t)usbtxpktcntsel << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(USBC_GTXTHRCFG_ADDR, (REG_PL_RD(USBC_GTXTHRCFG_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)usbtxpktcntsel <<29));
}
__INLINE uint8_t usbc_gtxthrcfg_reserved_28_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE uint8_t usbc_gtxthrcfg_usb_tx_pkt_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void usbc_gtxthrcfg_usb_tx_pkt_cnt_setf(uint8_t usbtxpktcnt)
{
	ASSERT_ERR((((uint32_t)usbtxpktcnt << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(USBC_GTXTHRCFG_ADDR, (REG_PL_RD(USBC_GTXTHRCFG_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)usbtxpktcnt <<24));
}
__INLINE uint8_t usbc_gtxthrcfg_usb_max_tx_burst_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void usbc_gtxthrcfg_usb_max_tx_burst_size_setf(uint8_t usbmaxtxburstsize)
{
	ASSERT_ERR((((uint32_t)usbmaxtxburstsize << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(USBC_GTXTHRCFG_ADDR, (REG_PL_RD(USBC_GTXTHRCFG_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)usbmaxtxburstsize <<16));
}
__INLINE uint8_t usbc_gtxthrcfg_reserved_15_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t usbc_gtxthrcfg_reserved_14_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t usbc_gtxthrcfg_reserved_13_11_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003800)) >> 11);
}
__INLINE uint16_t usbc_gtxthrcfg_reserved_10_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXTHRCFG_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}

/**
 * @brief GRXTHRCFG register definition
 *  Global Rx Threshold Control Register  In a normal case, a Tx burst starts as soon as one packet is prefetched; an Rx burst starts as soon as 1-packet space is available. This works well as long as the system bus is faster than the USB 3.0 bus (a 1024-bytes packet takes ~2.2 microseconds on the USB bus in SS mode).   If the system bus latency is larger than 2.2 microseconds to access a 1024-byte packet, then starting a burst on 1-packet condition leads to an early abort of the burst causing unnecessary performance reduction.    To avoid underrun and overrun during the burst, in a high-latency bus system (like USB), threshold and burst size control is provided through GTXTHRCFG and GRXTHRCFG registers. Bit [29] of the GTXTHRCFG and GRXTHRCFG registers enables this feature.  For more information on  - Using this register, refer to  Packet Threshold and Burst Features for High Latency Systems  section in the Databook.  - Selecting values for the fields of this register, see the  TX/RX Data FIFO Sizes and TX/RX Threshold Control Register Settings  section in the User Guide. Note:  - GRXTHRCFG register is not applicable for Debug Target.  - There is an issue when ACK TP with NumP=0 followed by ACK TP with NumP=1 without ERDY TP sent by the device controller during a burst bulk OUT transfer. This may cause third-party USB 3.0 host controllers to keep waiting for the ERDY TP. The USB 3.0 specification states that  When an endpoint is not in a flow control condition, it shall not send an ERDY TP unless the endpoint is a Bulk endpoint that supports streams.  In this case, after the device sent the ACK TP (nump=1), the endpoint was not in the flow control, so it did not send an ERDY. The device would have sent ERDY if the next OUT packet was not received. When the next OUT packet was received, at that time there was enough buffer space to accept it, so the device accepted the packet by informing host that it is not no longer in the flow control. The Host should wait for the responses for all the OUT packets to return and then decide if the endpoint is still in flow control or not. The USB 3.1 specification supersedes all the USB 3.0 specification. The errata states that  If the host continues, or resumes, transactions to an endpoint, the endpoint shall re-evaluate its flow control state and respond appropriately.  However, there are no ECNs on the USB 3.0 for this issue. To work around this issue, the Global Rx Threshold mode must be disable by setting GRXTHRCFG.UsbRxPktCntSel=0. Instead, software can program the DCFG.NUMP mode (where fixed NUMP is transmitted always) instead of the RX threshold based nump mode to prevent the device from sending ACK TP with NumP=0. The NUMP in the ACK TP is the minimum value of (DCFG.NUMP, bMaxBurstSize) for each endpoint. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:30 reserved_31_30            0x0
 *    29    Usb_Rx_Pkt_Cnt_Sel        0              
 *    28    reserved_28               0              
 *    27:24 Usb_Rx_Pkt_Cnt            0x0
 *    23:19 Usb_Max_Rx_Burst_Size     0x0
 *    18:16 reserved_18_16            0x0
 *    15    reserved_15               0              
 *    14:13 reserved_14_13            0x0
 *    12:00 Resv_ISOCOUTSpc           0x0
 * </pre>
 */
#define USBC_GRXTHRCFG_ADDR        (REG_USBC_BASE_ADDR+0x0000C10C)
#define USBC_GRXTHRCFG_OFFSET      0x0000C10C
#define USBC_GRXTHRCFG_INDEX       0x00003043
#define USBC_GRXTHRCFG_RESET       0x00000000

__INLINE uint32_t  usbc_grxthrcfg_get(void)
{
	return REG_PL_RD(USBC_GRXTHRCFG_ADDR);
}

__INLINE void usbc_grxthrcfg_set(uint32_t value)
{
	REG_PL_WR(USBC_GRXTHRCFG_ADDR, value);
}

// field definitions
#define USBC_GRXTHRCFG_RESERVED_31_30_MASK    ((uint32_t)0xC0000000)
#define USBC_GRXTHRCFG_RESERVED_31_30_LSB    30
#define USBC_GRXTHRCFG_RESERVED_31_30_WIDTH    ((uint32_t)0x00000002)
#define USBC_GRXTHRCFG_USB_RX_PKT_CNT_SEL_BIT    ((uint32_t)0x20000000)
#define USBC_GRXTHRCFG_USB_RX_PKT_CNT_SEL_POS    29
#define USBC_GRXTHRCFG_RESERVED_28_BIT      ((uint32_t)0x10000000)
#define USBC_GRXTHRCFG_RESERVED_28_POS      28
#define USBC_GRXTHRCFG_USB_RX_PKT_CNT_MASK    ((uint32_t)0x0F000000)
#define USBC_GRXTHRCFG_USB_RX_PKT_CNT_LSB    24
#define USBC_GRXTHRCFG_USB_RX_PKT_CNT_WIDTH    ((uint32_t)0x00000004)
#define USBC_GRXTHRCFG_USB_MAX_RX_BURST_SIZE_MASK    ((uint32_t)0x00F80000)
#define USBC_GRXTHRCFG_USB_MAX_RX_BURST_SIZE_LSB    19
#define USBC_GRXTHRCFG_USB_MAX_RX_BURST_SIZE_WIDTH    ((uint32_t)0x00000005)
#define USBC_GRXTHRCFG_RESERVED_18_16_MASK    ((uint32_t)0x00070000)
#define USBC_GRXTHRCFG_RESERVED_18_16_LSB    16
#define USBC_GRXTHRCFG_RESERVED_18_16_WIDTH    ((uint32_t)0x00000003)
#define USBC_GRXTHRCFG_RESERVED_15_BIT      ((uint32_t)0x00008000)
#define USBC_GRXTHRCFG_RESERVED_15_POS      15
#define USBC_GRXTHRCFG_RESERVED_14_13_MASK    ((uint32_t)0x00006000)
#define USBC_GRXTHRCFG_RESERVED_14_13_LSB    13
#define USBC_GRXTHRCFG_RESERVED_14_13_WIDTH    ((uint32_t)0x00000002)
#define USBC_GRXTHRCFG_RESV_ISOCOUTSPC_MASK    ((uint32_t)0x00001FFF)
#define USBC_GRXTHRCFG_RESV_ISOCOUTSPC_LSB    0
#define USBC_GRXTHRCFG_RESV_ISOCOUTSPC_WIDTH    ((uint32_t)0x0000000D)

#define USBC_GRXTHRCFG_RESERVED_31_30_RST    0x0
#define USBC_GRXTHRCFG_USB_RX_PKT_CNT_SEL_RST    0x0
#define USBC_GRXTHRCFG_RESERVED_28_RST      0x0
#define USBC_GRXTHRCFG_USB_RX_PKT_CNT_RST    0x0
#define USBC_GRXTHRCFG_USB_MAX_RX_BURST_SIZE_RST    0x0
#define USBC_GRXTHRCFG_RESERVED_18_16_RST    0x0
#define USBC_GRXTHRCFG_RESERVED_15_RST      0x0
#define USBC_GRXTHRCFG_RESERVED_14_13_RST    0x0
#define USBC_GRXTHRCFG_RESV_ISOCOUTSPC_RST    0x0

__INLINE void usbc_grxthrcfg_pack(uint8_t reserved_31_30, uint8_t usb_rx_pkt_cnt_sel, uint8_t reserved_28, uint8_t usb_rx_pkt_cnt, uint8_t usb_max_rx_burst_size, uint8_t reserved_18_16, uint8_t reserved_15, uint8_t reserved_14_13, uint16_t resv_isocoutspc)
{
	ASSERT_ERR((((uint32_t)reserved_31_30 << 30) & ~((uint32_t)0xC0000000)) == 0);
	ASSERT_ERR((((uint32_t)usb_rx_pkt_cnt_sel << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_28 << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)usb_rx_pkt_cnt << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)usb_max_rx_burst_size << 19) & ~((uint32_t)0x00F80000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_18_16 << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_15 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_14_13 << 13) & ~((uint32_t)0x00006000)) == 0);
	ASSERT_ERR((((uint32_t)resv_isocoutspc << 0) & ~((uint32_t)0x00001FFF)) == 0);
	REG_PL_WR(USBC_GRXTHRCFG_ADDR,  ((uint32_t)reserved_31_30 << 30) |((uint32_t)usb_rx_pkt_cnt_sel << 29) |((uint32_t)reserved_28 << 28) |((uint32_t)usb_rx_pkt_cnt << 24) |((uint32_t)usb_max_rx_burst_size << 19) |((uint32_t)reserved_18_16 << 16) |((uint32_t)reserved_15 << 15) |((uint32_t)reserved_14_13 << 13) |((uint32_t)resv_isocoutspc << 0));
}

__INLINE void usbc_grxthrcfg_unpack(uint8_t* reserved_31_30, uint8_t* usb_rx_pkt_cnt_sel, uint8_t* reserved_28, uint8_t* usb_rx_pkt_cnt, uint8_t* usb_max_rx_burst_size, uint8_t* reserved_18_16, uint8_t* reserved_15, uint8_t* reserved_14_13, uint16_t* resv_isocoutspc)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXTHRCFG_ADDR);

	*reserved_31_30 = (localVal & ((uint32_t)0xC0000000)) >>  30;
	*usb_rx_pkt_cnt_sel = (localVal & ((uint32_t)0x20000000)) >>  29;
	*reserved_28 = (localVal & ((uint32_t)0x10000000)) >>  28;
	*usb_rx_pkt_cnt = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*usb_max_rx_burst_size = (localVal & ((uint32_t)0x00F80000)) >>  19;
	*reserved_18_16 = (localVal & ((uint32_t)0x00070000)) >>  16;
	*reserved_15 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*reserved_14_13 = (localVal & ((uint32_t)0x00006000)) >>  13;
	*resv_isocoutspc = (localVal & ((uint32_t)0x00001FFF)) >>  0;
}

__INLINE uint8_t usbc_grxthrcfg_reserved_31_30_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xC0000000)) >> 30);
}
__INLINE uint8_t usbc_grxthrcfg_usb_rx_pkt_cnt_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void usbc_grxthrcfg_usb_rx_pkt_cnt_sel_setf(uint8_t usbrxpktcntsel)
{
	ASSERT_ERR((((uint32_t)usbrxpktcntsel << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(USBC_GRXTHRCFG_ADDR, (REG_PL_RD(USBC_GRXTHRCFG_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)usbrxpktcntsel <<29));
}
__INLINE uint8_t usbc_grxthrcfg_reserved_28_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE uint8_t usbc_grxthrcfg_usb_rx_pkt_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void usbc_grxthrcfg_usb_rx_pkt_cnt_setf(uint8_t usbrxpktcnt)
{
	ASSERT_ERR((((uint32_t)usbrxpktcnt << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(USBC_GRXTHRCFG_ADDR, (REG_PL_RD(USBC_GRXTHRCFG_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)usbrxpktcnt <<24));
}
__INLINE uint8_t usbc_grxthrcfg_usb_max_rx_burst_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F80000)) >> 19);
}
__INLINE void usbc_grxthrcfg_usb_max_rx_burst_size_setf(uint8_t usbmaxrxburstsize)
{
	ASSERT_ERR((((uint32_t)usbmaxrxburstsize << 19) & ~((uint32_t)0x00F80000)) == 0);
	REG_PL_WR(USBC_GRXTHRCFG_ADDR, (REG_PL_RD(USBC_GRXTHRCFG_ADDR) & ~((uint32_t)0x00F80000)) | ((uint32_t)usbmaxrxburstsize <<19));
}
__INLINE uint8_t usbc_grxthrcfg_reserved_18_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE uint8_t usbc_grxthrcfg_reserved_15_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t usbc_grxthrcfg_reserved_14_13_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXTHRCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00006000)) >> 13);
}
__INLINE uint16_t usbc_grxthrcfg_resv_isocoutspc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXTHRCFG_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00001FFF)) >> 0);
}
__INLINE void usbc_grxthrcfg_resv_isocoutspc_setf(uint16_t resvisocoutspc)
{
	ASSERT_ERR((((uint32_t)resvisocoutspc << 0) & ~((uint32_t)0x00001FFF)) == 0);
	REG_PL_WR(USBC_GRXTHRCFG_ADDR, (REG_PL_RD(USBC_GRXTHRCFG_ADDR) & ~((uint32_t)0x00001FFF)) | ((uint32_t)resvisocoutspc <<0));
}

/**
 * @brief GCTL register definition
 *  Global Core Control Register  Refer to  workspace /src/DWC_usb3_params.v for details on `DWC_USB3_GCTL_INIT.  Note:   When Hibernation is not enabled, you can write any value to GblHibernationEn. It always returns 0 when read.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:19 PWRDNSCALE                0x618
 *    18    MASTERFILTBYPASS          0              
 *    17    BYPSSETADDR               0              
 *    16    U2_RSTECN                 1              
 *    15:14 FRMSCLDWN                 0x0
 *    13:12 PRTCAPDIR                 0x2
 *    11    CORESOFTRESET             0              
 *    10    SOFITPSYNC                0              
 *    09    U1_U2_Timer_Scale         0              
 *    08    DEBUGATTACH               0              
 *    07:06 RAMCLKSEL                 0x0
 *    05:04 SCALEDOWN                 0x0
 *    03    DISSCRAMBLE               0              
 *    02    U2_EXIT_LFPS              1              
 *    01    Gbl_Hibernation_En        0              
 *    00    DSBLCLKGTNG               0              
 * </pre>
 */
#define USBC_GCTL_ADDR        (REG_USBC_BASE_ADDR+0x0000C110)
#define USBC_GCTL_OFFSET      0x0000C110
#define USBC_GCTL_INDEX       0x00003044
#define USBC_GCTL_RESET       0x30C12004

__INLINE uint32_t  usbc_gctl_get(void)
{
	return REG_PL_RD(USBC_GCTL_ADDR);
}

__INLINE void usbc_gctl_set(uint32_t value)
{
	REG_PL_WR(USBC_GCTL_ADDR, value);
}

// field definitions
#define USBC_GCTL_PWRDNSCALE_MASK           ((uint32_t)0xFFF80000)
#define USBC_GCTL_PWRDNSCALE_LSB            19
#define USBC_GCTL_PWRDNSCALE_WIDTH          ((uint32_t)0x0000000D)
#define USBC_GCTL_MASTERFILTBYPASS_BIT      ((uint32_t)0x00040000)
#define USBC_GCTL_MASTERFILTBYPASS_POS      18
#define USBC_GCTL_BYPSSETADDR_BIT           ((uint32_t)0x00020000)
#define USBC_GCTL_BYPSSETADDR_POS           17
#define USBC_GCTL_U_2_RSTECN_BIT            ((uint32_t)0x00010000)
#define USBC_GCTL_U_2_RSTECN_POS            16
#define USBC_GCTL_FRMSCLDWN_MASK            ((uint32_t)0x0000C000)
#define USBC_GCTL_FRMSCLDWN_LSB             14
#define USBC_GCTL_FRMSCLDWN_WIDTH           ((uint32_t)0x00000002)
#define USBC_GCTL_PRTCAPDIR_MASK            ((uint32_t)0x00003000)
#define USBC_GCTL_PRTCAPDIR_LSB             12
#define USBC_GCTL_PRTCAPDIR_WIDTH           ((uint32_t)0x00000002)
#define USBC_GCTL_CORESOFTRESET_BIT         ((uint32_t)0x00000800)
#define USBC_GCTL_CORESOFTRESET_POS         11
#define USBC_GCTL_SOFITPSYNC_BIT            ((uint32_t)0x00000400)
#define USBC_GCTL_SOFITPSYNC_POS            10
#define USBC_GCTL_U_1_U_2_TIMER_SCALE_BIT    ((uint32_t)0x00000200)
#define USBC_GCTL_U_1_U_2_TIMER_SCALE_POS    9
#define USBC_GCTL_DEBUGATTACH_BIT           ((uint32_t)0x00000100)
#define USBC_GCTL_DEBUGATTACH_POS           8
#define USBC_GCTL_RAMCLKSEL_MASK            ((uint32_t)0x000000C0)
#define USBC_GCTL_RAMCLKSEL_LSB             6
#define USBC_GCTL_RAMCLKSEL_WIDTH           ((uint32_t)0x00000002)
#define USBC_GCTL_SCALEDOWN_MASK            ((uint32_t)0x00000030)
#define USBC_GCTL_SCALEDOWN_LSB             4
#define USBC_GCTL_SCALEDOWN_WIDTH           ((uint32_t)0x00000002)
#define USBC_GCTL_DISSCRAMBLE_BIT           ((uint32_t)0x00000008)
#define USBC_GCTL_DISSCRAMBLE_POS           3
#define USBC_GCTL_U_2_EXIT_LFPS_BIT         ((uint32_t)0x00000004)
#define USBC_GCTL_U_2_EXIT_LFPS_POS         2
#define USBC_GCTL_GBL_HIBERNATION_EN_BIT    ((uint32_t)0x00000002)
#define USBC_GCTL_GBL_HIBERNATION_EN_POS    1
#define USBC_GCTL_DSBLCLKGTNG_BIT           ((uint32_t)0x00000001)
#define USBC_GCTL_DSBLCLKGTNG_POS           0

#define USBC_GCTL_PWRDNSCALE_RST            0x618
#define USBC_GCTL_MASTERFILTBYPASS_RST      0x0
#define USBC_GCTL_BYPSSETADDR_RST           0x0
#define USBC_GCTL_U_2_RSTECN_RST            0x1
#define USBC_GCTL_FRMSCLDWN_RST             0x0
#define USBC_GCTL_PRTCAPDIR_RST             0x2
#define USBC_GCTL_CORESOFTRESET_RST         0x0
#define USBC_GCTL_SOFITPSYNC_RST            0x0
#define USBC_GCTL_U_1_U_2_TIMER_SCALE_RST    0x0
#define USBC_GCTL_DEBUGATTACH_RST           0x0
#define USBC_GCTL_RAMCLKSEL_RST             0x0
#define USBC_GCTL_SCALEDOWN_RST             0x0
#define USBC_GCTL_DISSCRAMBLE_RST           0x0
#define USBC_GCTL_U_2_EXIT_LFPS_RST         0x1
#define USBC_GCTL_GBL_HIBERNATION_EN_RST    0x0
#define USBC_GCTL_DSBLCLKGTNG_RST           0x0

__INLINE void usbc_gctl_pack(uint16_t pwrdnscale, uint8_t masterfiltbypass, uint8_t bypssetaddr, uint8_t u2_rstecn, uint8_t frmscldwn, uint8_t prtcapdir, uint8_t coresoftreset, uint8_t sofitpsync, uint8_t u1_u2_timer_scale, uint8_t debugattach, uint8_t ramclksel, uint8_t scaledown, uint8_t disscramble, uint8_t u2_exit_lfps, uint8_t gbl_hibernation_en, uint8_t dsblclkgtng)
{
	ASSERT_ERR((((uint32_t)pwrdnscale << 19) & ~((uint32_t)0xFFF80000)) == 0);
	ASSERT_ERR((((uint32_t)masterfiltbypass << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)bypssetaddr << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)u2_rstecn << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)frmscldwn << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)prtcapdir << 12) & ~((uint32_t)0x00003000)) == 0);
	ASSERT_ERR((((uint32_t)coresoftreset << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)sofitpsync << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)u1_u2_timer_scale << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)debugattach << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)ramclksel << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)scaledown << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)disscramble << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)u2_exit_lfps << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)gbl_hibernation_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)dsblclkgtng << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR,  ((uint32_t)pwrdnscale << 19) |((uint32_t)masterfiltbypass << 18) |((uint32_t)bypssetaddr << 17) |((uint32_t)u2_rstecn << 16) |((uint32_t)frmscldwn << 14) |((uint32_t)prtcapdir << 12) |((uint32_t)coresoftreset << 11) |((uint32_t)sofitpsync << 10) |((uint32_t)u1_u2_timer_scale << 9) |((uint32_t)debugattach << 8) |((uint32_t)ramclksel << 6) |((uint32_t)scaledown << 4) |((uint32_t)disscramble << 3) |((uint32_t)u2_exit_lfps << 2) |((uint32_t)gbl_hibernation_en << 1) |((uint32_t)dsblclkgtng << 0));
}

__INLINE void usbc_gctl_unpack(uint16_t* pwrdnscale, uint8_t* masterfiltbypass, uint8_t* bypssetaddr, uint8_t* u2_rstecn, uint8_t* frmscldwn, uint8_t* prtcapdir, uint8_t* coresoftreset, uint8_t* sofitpsync, uint8_t* u1_u2_timer_scale, uint8_t* debugattach, uint8_t* ramclksel, uint8_t* scaledown, uint8_t* disscramble, uint8_t* u2_exit_lfps, uint8_t* gbl_hibernation_en, uint8_t* dsblclkgtng)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);

	*pwrdnscale = (localVal & ((uint32_t)0xFFF80000)) >>  19;
	*masterfiltbypass = (localVal & ((uint32_t)0x00040000)) >>  18;
	*bypssetaddr = (localVal & ((uint32_t)0x00020000)) >>  17;
	*u2_rstecn = (localVal & ((uint32_t)0x00010000)) >>  16;
	*frmscldwn = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*prtcapdir = (localVal & ((uint32_t)0x00003000)) >>  12;
	*coresoftreset = (localVal & ((uint32_t)0x00000800)) >>  11;
	*sofitpsync = (localVal & ((uint32_t)0x00000400)) >>  10;
	*u1_u2_timer_scale = (localVal & ((uint32_t)0x00000200)) >>  9;
	*debugattach = (localVal & ((uint32_t)0x00000100)) >>  8;
	*ramclksel = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*scaledown = (localVal & ((uint32_t)0x00000030)) >>  4;
	*disscramble = (localVal & ((uint32_t)0x00000008)) >>  3;
	*u2_exit_lfps = (localVal & ((uint32_t)0x00000004)) >>  2;
	*gbl_hibernation_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*dsblclkgtng = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint16_t usbc_gctl_pwrdnscale_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFF80000)) >> 19);
}
__INLINE void usbc_gctl_pwrdnscale_setf(uint16_t pwrdnscale)
{
	ASSERT_ERR((((uint32_t)pwrdnscale << 19) & ~((uint32_t)0xFFF80000)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0xFFF80000)) | ((uint32_t)pwrdnscale <<19));
}
__INLINE uint8_t usbc_gctl_masterfiltbypass_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void usbc_gctl_masterfiltbypass_setf(uint8_t masterfiltbypass)
{
	ASSERT_ERR((((uint32_t)masterfiltbypass << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)masterfiltbypass <<18));
}
__INLINE uint8_t usbc_gctl_bypssetaddr_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void usbc_gctl_bypssetaddr_setf(uint8_t bypssetaddr)
{
	ASSERT_ERR((((uint32_t)bypssetaddr << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)bypssetaddr <<17));
}
__INLINE uint8_t usbc_gctl_u_2_rstecn_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void usbc_gctl_u_2_rstecn_setf(uint8_t u2rstecn)
{
	ASSERT_ERR((((uint32_t)u2rstecn << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)u2rstecn <<16));
}
__INLINE uint8_t usbc_gctl_frmscldwn_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void usbc_gctl_frmscldwn_setf(uint8_t frmscldwn)
{
	ASSERT_ERR((((uint32_t)frmscldwn << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)frmscldwn <<14));
}
__INLINE uint8_t usbc_gctl_prtcapdir_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003000)) >> 12);
}
__INLINE void usbc_gctl_prtcapdir_setf(uint8_t prtcapdir)
{
	ASSERT_ERR((((uint32_t)prtcapdir << 12) & ~((uint32_t)0x00003000)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)prtcapdir <<12));
}
__INLINE uint8_t usbc_gctl_coresoftreset_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_gctl_coresoftreset_setf(uint8_t coresoftreset)
{
	ASSERT_ERR((((uint32_t)coresoftreset << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)coresoftreset <<11));
}
__INLINE uint8_t usbc_gctl_sofitpsync_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_gctl_sofitpsync_setf(uint8_t sofitpsync)
{
	ASSERT_ERR((((uint32_t)sofitpsync << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)sofitpsync <<10));
}
__INLINE uint8_t usbc_gctl_u_1_u_2_timer_scale_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void usbc_gctl_u_1_u_2_timer_scale_setf(uint8_t u1u2timerscale)
{
	ASSERT_ERR((((uint32_t)u1u2timerscale << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)u1u2timerscale <<9));
}
__INLINE uint8_t usbc_gctl_debugattach_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_gctl_debugattach_setf(uint8_t debugattach)
{
	ASSERT_ERR((((uint32_t)debugattach << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)debugattach <<8));
}
__INLINE uint8_t usbc_gctl_ramclksel_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void usbc_gctl_ramclksel_setf(uint8_t ramclksel)
{
	ASSERT_ERR((((uint32_t)ramclksel << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)ramclksel <<6));
}
__INLINE uint8_t usbc_gctl_scaledown_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void usbc_gctl_scaledown_setf(uint8_t scaledown)
{
	ASSERT_ERR((((uint32_t)scaledown << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)scaledown <<4));
}
__INLINE uint8_t usbc_gctl_disscramble_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void usbc_gctl_disscramble_setf(uint8_t disscramble)
{
	ASSERT_ERR((((uint32_t)disscramble << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)disscramble <<3));
}
__INLINE uint8_t usbc_gctl_u_2_exit_lfps_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void usbc_gctl_u_2_exit_lfps_setf(uint8_t u2exitlfps)
{
	ASSERT_ERR((((uint32_t)u2exitlfps << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)u2exitlfps <<2));
}
__INLINE uint8_t usbc_gctl_gbl_hibernation_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t usbc_gctl_dsblclkgtng_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void usbc_gctl_dsblclkgtng_setf(uint8_t dsblclkgtng)
{
	ASSERT_ERR((((uint32_t)dsblclkgtng << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(USBC_GCTL_ADDR, (REG_PL_RD(USBC_GCTL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)dsblclkgtng <<0));
}

/**
 * @brief GPMSTS register definition
 *  Global Power Management Status Register  This debug register gives information on which event caused the hibernation exit. It provides internal status and state machine information, and is for Synopsys use only for debugging purposes.  This register is not applicable in USB 2.0-only mode. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 Port_Sel                  0x0
 *    27:17 reserved_27_17            0x0
 *    16:12 U3_Wakeup                 0x0
 *    11:10 reserved_10_11            0x0
 *    09:00 U2_Wakeup                 0x0
 * </pre>
 */
#define USBC_GPMSTS_ADDR        (REG_USBC_BASE_ADDR+0x0000C114)
#define USBC_GPMSTS_OFFSET      0x0000C114
#define USBC_GPMSTS_INDEX       0x00003045
#define USBC_GPMSTS_RESET       0x00000000

__INLINE uint32_t  usbc_gpmsts_get(void)
{
	return REG_PL_RD(USBC_GPMSTS_ADDR);
}

__INLINE void usbc_gpmsts_set(uint32_t value)
{
	REG_PL_WR(USBC_GPMSTS_ADDR, value);
}

// field definitions
#define USBC_GPMSTS_PORT_SEL_MASK           ((uint32_t)0xF0000000)
#define USBC_GPMSTS_PORT_SEL_LSB            28
#define USBC_GPMSTS_PORT_SEL_WIDTH          ((uint32_t)0x00000004)
#define USBC_GPMSTS_RESERVED_27_17_MASK     ((uint32_t)0x0FFE0000)
#define USBC_GPMSTS_RESERVED_27_17_LSB      17
#define USBC_GPMSTS_RESERVED_27_17_WIDTH    ((uint32_t)0x0000000B)
#define USBC_GPMSTS_U_3_WAKEUP_MASK         ((uint32_t)0x0001F000)
#define USBC_GPMSTS_U_3_WAKEUP_LSB          12
#define USBC_GPMSTS_U_3_WAKEUP_WIDTH        ((uint32_t)0x00000005)
#define USBC_GPMSTS_RESERVED_10_11_MASK     ((uint32_t)0x00000C00)
#define USBC_GPMSTS_RESERVED_10_11_LSB      10
#define USBC_GPMSTS_RESERVED_10_11_WIDTH    ((uint32_t)0x00000002)
#define USBC_GPMSTS_U_2_WAKEUP_MASK         ((uint32_t)0x000003FF)
#define USBC_GPMSTS_U_2_WAKEUP_LSB          0
#define USBC_GPMSTS_U_2_WAKEUP_WIDTH        ((uint32_t)0x0000000A)

#define USBC_GPMSTS_PORT_SEL_RST            0x0
#define USBC_GPMSTS_RESERVED_27_17_RST      0x0
#define USBC_GPMSTS_U_3_WAKEUP_RST          0x0
#define USBC_GPMSTS_RESERVED_10_11_RST      0x0
#define USBC_GPMSTS_U_2_WAKEUP_RST          0x0

__INLINE void usbc_gpmsts_pack(uint8_t port_sel, uint16_t reserved_27_17, uint8_t u3_wakeup, uint8_t reserved_10_11, uint16_t u2_wakeup)
{
	ASSERT_ERR((((uint32_t)port_sel << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_27_17 << 17) & ~((uint32_t)0x0FFE0000)) == 0);
	ASSERT_ERR((((uint32_t)u3_wakeup << 12) & ~((uint32_t)0x0001F000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_10_11 << 10) & ~((uint32_t)0x00000C00)) == 0);
	ASSERT_ERR((((uint32_t)u2_wakeup << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(USBC_GPMSTS_ADDR,  ((uint32_t)port_sel << 28) |((uint32_t)reserved_27_17 << 17) |((uint32_t)u3_wakeup << 12) |((uint32_t)reserved_10_11 << 10) |((uint32_t)u2_wakeup << 0));
}

__INLINE void usbc_gpmsts_unpack(uint8_t* port_sel, uint16_t* reserved_27_17, uint8_t* u3_wakeup, uint8_t* reserved_10_11, uint16_t* u2_wakeup)
{
	uint32_t localVal = REG_PL_RD(USBC_GPMSTS_ADDR);

	*port_sel = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*reserved_27_17 = (localVal & ((uint32_t)0x0FFE0000)) >>  17;
	*u3_wakeup = (localVal & ((uint32_t)0x0001F000)) >>  12;
	*reserved_10_11 = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*u2_wakeup = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE void usbc_gpmsts_port_sel_setf(uint8_t portsel)
{
	ASSERT_ERR((((uint32_t)portsel << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(USBC_GPMSTS_ADDR, (REG_PL_RD(USBC_GPMSTS_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)portsel <<28));
}
__INLINE uint16_t usbc_gpmsts_reserved_27_17_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPMSTS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFE0000)) >> 17);
}
__INLINE uint8_t usbc_gpmsts_u_3_wakeup_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPMSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0001F000)) >> 12);
}
__INLINE uint8_t usbc_gpmsts_reserved_10_11_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPMSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE uint16_t usbc_gpmsts_u_2_wakeup_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPMSTS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}

/**
 * @brief GSTS register definition
 *  Global Status Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:20 CBELT                     0x0
 *    19:12 reserved_19_12            0x0
 *    11    SSIC_IP                   0              
 *    10    OTG_IP                    0              
 *    09    BC_IP                     0              
 *    08    ADP_IP                    0              
 *    07    Host_IP                   0              
 *    06    Device_IP                 0              
 *    05    CSRTimeout                0              
 *    04    BUSERRADDRVLD             0              
 *    03:02 reserved_3_2              0x0
 *    01:00 CURMOD                    0x0
 * </pre>
 */
#define USBC_GSTS_ADDR        (REG_USBC_BASE_ADDR+0x0000C118)
#define USBC_GSTS_OFFSET      0x0000C118
#define USBC_GSTS_INDEX       0x00003046
#define USBC_GSTS_RESET       0x00000000

__INLINE uint32_t  usbc_gsts_get(void)
{
	return REG_PL_RD(USBC_GSTS_ADDR);
}

__INLINE void usbc_gsts_set(uint32_t value)
{
	REG_PL_WR(USBC_GSTS_ADDR, value);
}

// field definitions
#define USBC_GSTS_CBELT_MASK                ((uint32_t)0xFFF00000)
#define USBC_GSTS_CBELT_LSB                 20
#define USBC_GSTS_CBELT_WIDTH               ((uint32_t)0x0000000C)
#define USBC_GSTS_RESERVED_19_12_MASK       ((uint32_t)0x000FF000)
#define USBC_GSTS_RESERVED_19_12_LSB        12
#define USBC_GSTS_RESERVED_19_12_WIDTH      ((uint32_t)0x00000008)
#define USBC_GSTS_SSIC_IP_BIT               ((uint32_t)0x00000800)
#define USBC_GSTS_SSIC_IP_POS               11
#define USBC_GSTS_OTG_IP_BIT                ((uint32_t)0x00000400)
#define USBC_GSTS_OTG_IP_POS                10
#define USBC_GSTS_BC_IP_BIT                 ((uint32_t)0x00000200)
#define USBC_GSTS_BC_IP_POS                 9
#define USBC_GSTS_ADP_IP_BIT                ((uint32_t)0x00000100)
#define USBC_GSTS_ADP_IP_POS                8
#define USBC_GSTS_HOST_IP_BIT               ((uint32_t)0x00000080)
#define USBC_GSTS_HOST_IP_POS               7
#define USBC_GSTS_DEVICE_IP_BIT             ((uint32_t)0x00000040)
#define USBC_GSTS_DEVICE_IP_POS             6
#define USBC_GSTS_CSRTIMEOUT_BIT            ((uint32_t)0x00000020)
#define USBC_GSTS_CSRTIMEOUT_POS            5
#define USBC_GSTS_BUSERRADDRVLD_BIT         ((uint32_t)0x00000010)
#define USBC_GSTS_BUSERRADDRVLD_POS         4
#define USBC_GSTS_RESERVED_3_2_MASK         ((uint32_t)0x0000000C)
#define USBC_GSTS_RESERVED_3_2_LSB          2
#define USBC_GSTS_RESERVED_3_2_WIDTH        ((uint32_t)0x00000002)
#define USBC_GSTS_CURMOD_MASK               ((uint32_t)0x00000003)
#define USBC_GSTS_CURMOD_LSB                0
#define USBC_GSTS_CURMOD_WIDTH              ((uint32_t)0x00000002)

#define USBC_GSTS_CBELT_RST                 0x0
#define USBC_GSTS_RESERVED_19_12_RST        0x0
#define USBC_GSTS_SSIC_IP_RST               0x0
#define USBC_GSTS_OTG_IP_RST                0x0
#define USBC_GSTS_BC_IP_RST                 0x0
#define USBC_GSTS_ADP_IP_RST                0x0
#define USBC_GSTS_HOST_IP_RST               0x0
#define USBC_GSTS_DEVICE_IP_RST             0x0
#define USBC_GSTS_CSRTIMEOUT_RST            0x0
#define USBC_GSTS_BUSERRADDRVLD_RST         0x0
#define USBC_GSTS_RESERVED_3_2_RST          0x0
#define USBC_GSTS_CURMOD_RST                0x0

__INLINE void usbc_gsts_pack(uint16_t cbelt, uint8_t reserved_19_12, uint8_t ssic_ip, uint8_t otg_ip, uint8_t bc_ip, uint8_t adp_ip, uint8_t host_ip, uint8_t device_ip, uint8_t csrtimeout, uint8_t buserraddrvld, uint8_t reserved_3_2, uint8_t curmod)
{
	ASSERT_ERR((((uint32_t)cbelt << 20) & ~((uint32_t)0xFFF00000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_19_12 << 12) & ~((uint32_t)0x000FF000)) == 0);
	ASSERT_ERR((((uint32_t)ssic_ip << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)otg_ip << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)bc_ip << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)adp_ip << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)host_ip << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)device_ip << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)csrtimeout << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)buserraddrvld << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)reserved_3_2 << 2) & ~((uint32_t)0x0000000C)) == 0);
	ASSERT_ERR((((uint32_t)curmod << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(USBC_GSTS_ADDR,  ((uint32_t)cbelt << 20) |((uint32_t)reserved_19_12 << 12) |((uint32_t)ssic_ip << 11) |((uint32_t)otg_ip << 10) |((uint32_t)bc_ip << 9) |((uint32_t)adp_ip << 8) |((uint32_t)host_ip << 7) |((uint32_t)device_ip << 6) |((uint32_t)csrtimeout << 5) |((uint32_t)buserraddrvld << 4) |((uint32_t)reserved_3_2 << 2) |((uint32_t)curmod << 0));
}

__INLINE void usbc_gsts_unpack(uint16_t* cbelt, uint8_t* reserved_19_12, uint8_t* ssic_ip, uint8_t* otg_ip, uint8_t* bc_ip, uint8_t* adp_ip, uint8_t* host_ip, uint8_t* device_ip, uint8_t* csrtimeout, uint8_t* buserraddrvld, uint8_t* reserved_3_2, uint8_t* curmod)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);

	*cbelt = (localVal & ((uint32_t)0xFFF00000)) >>  20;
	*reserved_19_12 = (localVal & ((uint32_t)0x000FF000)) >>  12;
	*ssic_ip = (localVal & ((uint32_t)0x00000800)) >>  11;
	*otg_ip = (localVal & ((uint32_t)0x00000400)) >>  10;
	*bc_ip = (localVal & ((uint32_t)0x00000200)) >>  9;
	*adp_ip = (localVal & ((uint32_t)0x00000100)) >>  8;
	*host_ip = (localVal & ((uint32_t)0x00000080)) >>  7;
	*device_ip = (localVal & ((uint32_t)0x00000040)) >>  6;
	*csrtimeout = (localVal & ((uint32_t)0x00000020)) >>  5;
	*buserraddrvld = (localVal & ((uint32_t)0x00000010)) >>  4;
	*reserved_3_2 = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*curmod = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t usbc_gsts_cbelt_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFF00000)) >> 20);
}
__INLINE uint8_t usbc_gsts_reserved_19_12_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000FF000)) >> 12);
}
__INLINE uint8_t usbc_gsts_ssic_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t usbc_gsts_otg_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t usbc_gsts_bc_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_gsts_adp_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t usbc_gsts_host_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t usbc_gsts_device_ip_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t usbc_gsts_csrtimeout_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void usbc_gsts_csrtimeout_setf(uint8_t csrtimeout)
{
	ASSERT_ERR((((uint32_t)csrtimeout << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(USBC_GSTS_ADDR, (REG_PL_RD(USBC_GSTS_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)csrtimeout <<5));
}
__INLINE uint8_t usbc_gsts_buserraddrvld_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void usbc_gsts_buserraddrvld_setf(uint8_t buserraddrvld)
{
	ASSERT_ERR((((uint32_t)buserraddrvld << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(USBC_GSTS_ADDR, (REG_PL_RD(USBC_GSTS_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)buserraddrvld <<4));
}
__INLINE uint8_t usbc_gsts_reserved_3_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE uint8_t usbc_gsts_curmod_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief GUCTL_1 register definition
 *  Global User Control Register 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    DEV_DECOUPLE_L1_L2_EVT    0              
 *    30    DS_RXDET_MAX_TOUT_CTRL    0              
 *    29    FILTER_SE0_FSLS_EOP       0              
 *    28    TX_IPGAP_LINECHECK_DIS    0              
 *    27    DEV_TRB_OUT_SPR_IND       0              
 *    26    DEV_FORCE_20_CLK_FOR_30_CLK 0              
 *    25    P3_IN_U2                  0              
 *    24    DEV_L1_EXIT_BY_HW         0              
 *    23:21 IP_GAP_ADD_ON             0x0
 *    20    DEV_LSP_TAIL_LOCK_DIS     0              
 *    19    NAK_PER_ENH_FS            0              
 *    18    NAK_PER_ENH_HS            1              
 *    17    PARKMODE_DISABLE_SS       0              
 *    16    PARKMODE_DISABLE_HS       0              
 *    15    PARKMODE_DISABLE_FSLS     0              
 *    14:13 reserved_14_13            0x0
 *    12    Dis_USB2_Ref_Clk_Gtng     1              
 *    11    Dis_Ref_Clk_Gtng          1              
 *    10    RESUME_OPMODE_HS_HOST     0              
 *    09    DEV_HS_NYET_BULK_SPR      0              
 *    08    L1_SUSP_THRLD_EN_FOR_HOST 1              
 *    07:04 L1_SUSP_THRLD_FOR_HOST    0x8
 *    03    HC_ERRATA_ENABLE          1              
 *    02    HC_PARCHK_DISABLE         0              
 *    01    OVRLD_L1_SUSP_COM         1              
 *    00    LOA_FILTER_EN             0              
 * </pre>
 */
#define USBC_GUCTL_1_ADDR        (REG_USBC_BASE_ADDR+0x0000C11C)
#define USBC_GUCTL_1_OFFSET      0x0000C11C
#define USBC_GUCTL_1_INDEX       0x00003047
#define USBC_GUCTL_1_RESET       0x0004198A

__INLINE uint32_t  usbc_guctl_1_get(void)
{
	return REG_PL_RD(USBC_GUCTL_1_ADDR);
}

__INLINE void usbc_guctl_1_set(uint32_t value)
{
	REG_PL_WR(USBC_GUCTL_1_ADDR, value);
}

// field definitions
#define USBC_GUCTL_1_DEV_DECOUPLE_L_1_L_2_EVT_BIT    ((uint32_t)0x80000000)
#define USBC_GUCTL_1_DEV_DECOUPLE_L_1_L_2_EVT_POS    31
#define USBC_GUCTL_1_DS_RXDET_MAX_TOUT_CTRL_BIT    ((uint32_t)0x40000000)
#define USBC_GUCTL_1_DS_RXDET_MAX_TOUT_CTRL_POS    30
#define USBC_GUCTL_1_FILTER_SE_0_FSLS_EOP_BIT    ((uint32_t)0x20000000)
#define USBC_GUCTL_1_FILTER_SE_0_FSLS_EOP_POS    29
#define USBC_GUCTL_1_TX_IPGAP_LINECHECK_DIS_BIT    ((uint32_t)0x10000000)
#define USBC_GUCTL_1_TX_IPGAP_LINECHECK_DIS_POS    28
#define USBC_GUCTL_1_DEV_TRB_OUT_SPR_IND_BIT    ((uint32_t)0x08000000)
#define USBC_GUCTL_1_DEV_TRB_OUT_SPR_IND_POS    27
#define USBC_GUCTL_1_DEV_FORCE_20_CLK_FOR_30_CLK_BIT    ((uint32_t)0x04000000)
#define USBC_GUCTL_1_DEV_FORCE_20_CLK_FOR_30_CLK_POS    26
#define USBC_GUCTL_1_P_3_IN_U_2_BIT         ((uint32_t)0x02000000)
#define USBC_GUCTL_1_P_3_IN_U_2_POS         25
#define USBC_GUCTL_1_DEV_L_1_EXIT_BY_HW_BIT    ((uint32_t)0x01000000)
#define USBC_GUCTL_1_DEV_L_1_EXIT_BY_HW_POS    24
#define USBC_GUCTL_1_IP_GAP_ADD_ON_MASK     ((uint32_t)0x00E00000)
#define USBC_GUCTL_1_IP_GAP_ADD_ON_LSB      21
#define USBC_GUCTL_1_IP_GAP_ADD_ON_WIDTH    ((uint32_t)0x00000003)
#define USBC_GUCTL_1_DEV_LSP_TAIL_LOCK_DIS_BIT    ((uint32_t)0x00100000)
#define USBC_GUCTL_1_DEV_LSP_TAIL_LOCK_DIS_POS    20
#define USBC_GUCTL_1_NAK_PER_ENH_FS_BIT     ((uint32_t)0x00080000)
#define USBC_GUCTL_1_NAK_PER_ENH_FS_POS     19
#define USBC_GUCTL_1_NAK_PER_ENH_HS_BIT     ((uint32_t)0x00040000)
#define USBC_GUCTL_1_NAK_PER_ENH_HS_POS     18
#define USBC_GUCTL_1_PARKMODE_DISABLE_SS_BIT    ((uint32_t)0x00020000)
#define USBC_GUCTL_1_PARKMODE_DISABLE_SS_POS    17
#define USBC_GUCTL_1_PARKMODE_DISABLE_HS_BIT    ((uint32_t)0x00010000)
#define USBC_GUCTL_1_PARKMODE_DISABLE_HS_POS    16
#define USBC_GUCTL_1_PARKMODE_DISABLE_FSLS_BIT    ((uint32_t)0x00008000)
#define USBC_GUCTL_1_PARKMODE_DISABLE_FSLS_POS    15
#define USBC_GUCTL_1_RESERVED_14_13_MASK    ((uint32_t)0x00006000)
#define USBC_GUCTL_1_RESERVED_14_13_LSB     13
#define USBC_GUCTL_1_RESERVED_14_13_WIDTH    ((uint32_t)0x00000002)
#define USBC_GUCTL_1_DIS_USB_2_REF_CLK_GTNG_BIT    ((uint32_t)0x00001000)
#define USBC_GUCTL_1_DIS_USB_2_REF_CLK_GTNG_POS    12
#define USBC_GUCTL_1_DIS_REF_CLK_GTNG_BIT    ((uint32_t)0x00000800)
#define USBC_GUCTL_1_DIS_REF_CLK_GTNG_POS    11
#define USBC_GUCTL_1_RESUME_OPMODE_HS_HOST_BIT    ((uint32_t)0x00000400)
#define USBC_GUCTL_1_RESUME_OPMODE_HS_HOST_POS    10
#define USBC_GUCTL_1_DEV_HS_NYET_BULK_SPR_BIT    ((uint32_t)0x00000200)
#define USBC_GUCTL_1_DEV_HS_NYET_BULK_SPR_POS    9
#define USBC_GUCTL_1_L_1_SUSP_THRLD_EN_FOR_HOST_BIT    ((uint32_t)0x00000100)
#define USBC_GUCTL_1_L_1_SUSP_THRLD_EN_FOR_HOST_POS    8
#define USBC_GUCTL_1_L_1_SUSP_THRLD_FOR_HOST_MASK    ((uint32_t)0x000000F0)
#define USBC_GUCTL_1_L_1_SUSP_THRLD_FOR_HOST_LSB    4
#define USBC_GUCTL_1_L_1_SUSP_THRLD_FOR_HOST_WIDTH    ((uint32_t)0x00000004)
#define USBC_GUCTL_1_HC_ERRATA_ENABLE_BIT    ((uint32_t)0x00000008)
#define USBC_GUCTL_1_HC_ERRATA_ENABLE_POS    3
#define USBC_GUCTL_1_HC_PARCHK_DISABLE_BIT    ((uint32_t)0x00000004)
#define USBC_GUCTL_1_HC_PARCHK_DISABLE_POS    2
#define USBC_GUCTL_1_OVRLD_L_1_SUSP_COM_BIT    ((uint32_t)0x00000002)
#define USBC_GUCTL_1_OVRLD_L_1_SUSP_COM_POS    1
#define USBC_GUCTL_1_LOA_FILTER_EN_BIT      ((uint32_t)0x00000001)
#define USBC_GUCTL_1_LOA_FILTER_EN_POS      0

#define USBC_GUCTL_1_DEV_DECOUPLE_L_1_L_2_EVT_RST    0x0
#define USBC_GUCTL_1_DS_RXDET_MAX_TOUT_CTRL_RST    0x0
#define USBC_GUCTL_1_FILTER_SE_0_FSLS_EOP_RST    0x0
#define USBC_GUCTL_1_TX_IPGAP_LINECHECK_DIS_RST    0x0
#define USBC_GUCTL_1_DEV_TRB_OUT_SPR_IND_RST    0x0
#define USBC_GUCTL_1_DEV_FORCE_20_CLK_FOR_30_CLK_RST    0x0
#define USBC_GUCTL_1_P_3_IN_U_2_RST         0x0
#define USBC_GUCTL_1_DEV_L_1_EXIT_BY_HW_RST    0x0
#define USBC_GUCTL_1_IP_GAP_ADD_ON_RST      0x0
#define USBC_GUCTL_1_DEV_LSP_TAIL_LOCK_DIS_RST    0x0
#define USBC_GUCTL_1_NAK_PER_ENH_FS_RST     0x0
#define USBC_GUCTL_1_NAK_PER_ENH_HS_RST     0x1
#define USBC_GUCTL_1_PARKMODE_DISABLE_SS_RST    0x0
#define USBC_GUCTL_1_PARKMODE_DISABLE_HS_RST    0x0
#define USBC_GUCTL_1_PARKMODE_DISABLE_FSLS_RST    0x0
#define USBC_GUCTL_1_RESERVED_14_13_RST     0x0
#define USBC_GUCTL_1_DIS_USB_2_REF_CLK_GTNG_RST    0x1
#define USBC_GUCTL_1_DIS_REF_CLK_GTNG_RST    0x1
#define USBC_GUCTL_1_RESUME_OPMODE_HS_HOST_RST    0x0
#define USBC_GUCTL_1_DEV_HS_NYET_BULK_SPR_RST    0x0
#define USBC_GUCTL_1_L_1_SUSP_THRLD_EN_FOR_HOST_RST    0x1
#define USBC_GUCTL_1_L_1_SUSP_THRLD_FOR_HOST_RST    0x8
#define USBC_GUCTL_1_HC_ERRATA_ENABLE_RST    0x1
#define USBC_GUCTL_1_HC_PARCHK_DISABLE_RST    0x0
#define USBC_GUCTL_1_OVRLD_L_1_SUSP_COM_RST    0x1
#define USBC_GUCTL_1_LOA_FILTER_EN_RST      0x0

__INLINE void usbc_guctl_1_pack(uint8_t dev_decouple_l1_l2_evt, uint8_t ds_rxdet_max_tout_ctrl, uint8_t filter_se0_fsls_eop, uint8_t tx_ipgap_linecheck_dis, uint8_t dev_trb_out_spr_ind, uint8_t dev_force_20_clk_for_30_clk, uint8_t p3_in_u2, uint8_t dev_l1_exit_by_hw, uint8_t ip_gap_add_on, uint8_t dev_lsp_tail_lock_dis, uint8_t nak_per_enh_fs, uint8_t nak_per_enh_hs, uint8_t parkmode_disable_ss, uint8_t parkmode_disable_hs, uint8_t parkmode_disable_fsls, uint8_t reserved_14_13, uint8_t dis_usb2_ref_clk_gtng, uint8_t dis_ref_clk_gtng, uint8_t resume_opmode_hs_host, uint8_t dev_hs_nyet_bulk_spr, uint8_t l1_susp_thrld_en_for_host, uint8_t l1_susp_thrld_for_host, uint8_t hc_errata_enable, uint8_t hc_parchk_disable, uint8_t ovrld_l1_susp_com, uint8_t loa_filter_en)
{
	ASSERT_ERR((((uint32_t)dev_decouple_l1_l2_evt << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)ds_rxdet_max_tout_ctrl << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)filter_se0_fsls_eop << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)tx_ipgap_linecheck_dis << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)dev_trb_out_spr_ind << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)dev_force_20_clk_for_30_clk << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)p3_in_u2 << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)dev_l1_exit_by_hw << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)ip_gap_add_on << 21) & ~((uint32_t)0x00E00000)) == 0);
	ASSERT_ERR((((uint32_t)dev_lsp_tail_lock_dis << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)nak_per_enh_fs << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)nak_per_enh_hs << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)parkmode_disable_ss << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)parkmode_disable_hs << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)parkmode_disable_fsls << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_14_13 << 13) & ~((uint32_t)0x00006000)) == 0);
	ASSERT_ERR((((uint32_t)dis_usb2_ref_clk_gtng << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)dis_ref_clk_gtng << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)resume_opmode_hs_host << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)dev_hs_nyet_bulk_spr << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)l1_susp_thrld_en_for_host << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)l1_susp_thrld_for_host << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)hc_errata_enable << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)hc_parchk_disable << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)ovrld_l1_susp_com << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)loa_filter_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR,  ((uint32_t)dev_decouple_l1_l2_evt << 31) |((uint32_t)ds_rxdet_max_tout_ctrl << 30) |((uint32_t)filter_se0_fsls_eop << 29) |((uint32_t)tx_ipgap_linecheck_dis << 28) |((uint32_t)dev_trb_out_spr_ind << 27) |((uint32_t)dev_force_20_clk_for_30_clk << 26) |((uint32_t)p3_in_u2 << 25) |((uint32_t)dev_l1_exit_by_hw << 24) |((uint32_t)ip_gap_add_on << 21) |((uint32_t)dev_lsp_tail_lock_dis << 20) |((uint32_t)nak_per_enh_fs << 19) |((uint32_t)nak_per_enh_hs << 18) |((uint32_t)parkmode_disable_ss << 17) |((uint32_t)parkmode_disable_hs << 16) |((uint32_t)parkmode_disable_fsls << 15) |((uint32_t)reserved_14_13 << 13) |((uint32_t)dis_usb2_ref_clk_gtng << 12) |((uint32_t)dis_ref_clk_gtng << 11) |((uint32_t)resume_opmode_hs_host << 10) |((uint32_t)dev_hs_nyet_bulk_spr << 9) |((uint32_t)l1_susp_thrld_en_for_host << 8) |((uint32_t)l1_susp_thrld_for_host << 4) |((uint32_t)hc_errata_enable << 3) |((uint32_t)hc_parchk_disable << 2) |((uint32_t)ovrld_l1_susp_com << 1) |((uint32_t)loa_filter_en << 0));
}

__INLINE void usbc_guctl_1_unpack(uint8_t* dev_decouple_l1_l2_evt, uint8_t* ds_rxdet_max_tout_ctrl, uint8_t* filter_se0_fsls_eop, uint8_t* tx_ipgap_linecheck_dis, uint8_t* dev_trb_out_spr_ind, uint8_t* dev_force_20_clk_for_30_clk, uint8_t* p3_in_u2, uint8_t* dev_l1_exit_by_hw, uint8_t* ip_gap_add_on, uint8_t* dev_lsp_tail_lock_dis, uint8_t* nak_per_enh_fs, uint8_t* nak_per_enh_hs, uint8_t* parkmode_disable_ss, uint8_t* parkmode_disable_hs, uint8_t* parkmode_disable_fsls, uint8_t* reserved_14_13, uint8_t* dis_usb2_ref_clk_gtng, uint8_t* dis_ref_clk_gtng, uint8_t* resume_opmode_hs_host, uint8_t* dev_hs_nyet_bulk_spr, uint8_t* l1_susp_thrld_en_for_host, uint8_t* l1_susp_thrld_for_host, uint8_t* hc_errata_enable, uint8_t* hc_parchk_disable, uint8_t* ovrld_l1_susp_com, uint8_t* loa_filter_en)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);

	*dev_decouple_l1_l2_evt = (localVal & ((uint32_t)0x80000000)) >>  31;
	*ds_rxdet_max_tout_ctrl = (localVal & ((uint32_t)0x40000000)) >>  30;
	*filter_se0_fsls_eop = (localVal & ((uint32_t)0x20000000)) >>  29;
	*tx_ipgap_linecheck_dis = (localVal & ((uint32_t)0x10000000)) >>  28;
	*dev_trb_out_spr_ind = (localVal & ((uint32_t)0x08000000)) >>  27;
	*dev_force_20_clk_for_30_clk = (localVal & ((uint32_t)0x04000000)) >>  26;
	*p3_in_u2 = (localVal & ((uint32_t)0x02000000)) >>  25;
	*dev_l1_exit_by_hw = (localVal & ((uint32_t)0x01000000)) >>  24;
	*ip_gap_add_on = (localVal & ((uint32_t)0x00E00000)) >>  21;
	*dev_lsp_tail_lock_dis = (localVal & ((uint32_t)0x00100000)) >>  20;
	*nak_per_enh_fs = (localVal & ((uint32_t)0x00080000)) >>  19;
	*nak_per_enh_hs = (localVal & ((uint32_t)0x00040000)) >>  18;
	*parkmode_disable_ss = (localVal & ((uint32_t)0x00020000)) >>  17;
	*parkmode_disable_hs = (localVal & ((uint32_t)0x00010000)) >>  16;
	*parkmode_disable_fsls = (localVal & ((uint32_t)0x00008000)) >>  15;
	*reserved_14_13 = (localVal & ((uint32_t)0x00006000)) >>  13;
	*dis_usb2_ref_clk_gtng = (localVal & ((uint32_t)0x00001000)) >>  12;
	*dis_ref_clk_gtng = (localVal & ((uint32_t)0x00000800)) >>  11;
	*resume_opmode_hs_host = (localVal & ((uint32_t)0x00000400)) >>  10;
	*dev_hs_nyet_bulk_spr = (localVal & ((uint32_t)0x00000200)) >>  9;
	*l1_susp_thrld_en_for_host = (localVal & ((uint32_t)0x00000100)) >>  8;
	*l1_susp_thrld_for_host = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*hc_errata_enable = (localVal & ((uint32_t)0x00000008)) >>  3;
	*hc_parchk_disable = (localVal & ((uint32_t)0x00000004)) >>  2;
	*ovrld_l1_susp_com = (localVal & ((uint32_t)0x00000002)) >>  1;
	*loa_filter_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t usbc_guctl_1_dev_decouple_l_1_l_2_evt_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void usbc_guctl_1_dev_decouple_l_1_l_2_evt_setf(uint8_t devdecouplel1l2evt)
{
	ASSERT_ERR((((uint32_t)devdecouplel1l2evt << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)devdecouplel1l2evt <<31));
}
__INLINE uint8_t usbc_guctl_1_ds_rxdet_max_tout_ctrl_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void usbc_guctl_1_ds_rxdet_max_tout_ctrl_setf(uint8_t dsrxdetmaxtoutctrl)
{
	ASSERT_ERR((((uint32_t)dsrxdetmaxtoutctrl << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)dsrxdetmaxtoutctrl <<30));
}
__INLINE uint8_t usbc_guctl_1_filter_se_0_fsls_eop_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void usbc_guctl_1_filter_se_0_fsls_eop_setf(uint8_t filterse0fslseop)
{
	ASSERT_ERR((((uint32_t)filterse0fslseop << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)filterse0fslseop <<29));
}
__INLINE uint8_t usbc_guctl_1_tx_ipgap_linecheck_dis_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void usbc_guctl_1_tx_ipgap_linecheck_dis_setf(uint8_t txipgaplinecheckdis)
{
	ASSERT_ERR((((uint32_t)txipgaplinecheckdis << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)txipgaplinecheckdis <<28));
}
__INLINE uint8_t usbc_guctl_1_dev_trb_out_spr_ind_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void usbc_guctl_1_dev_trb_out_spr_ind_setf(uint8_t devtrboutsprind)
{
	ASSERT_ERR((((uint32_t)devtrboutsprind << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)devtrboutsprind <<27));
}
__INLINE uint8_t usbc_guctl_1_dev_force_20_clk_for_30_clk_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void usbc_guctl_1_dev_force_20_clk_for_30_clk_setf(uint8_t devforce20clkfor30clk)
{
	ASSERT_ERR((((uint32_t)devforce20clkfor30clk << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)devforce20clkfor30clk <<26));
}
__INLINE uint8_t usbc_guctl_1_p_3_in_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void usbc_guctl_1_p_3_in_u_2_setf(uint8_t p3inu2)
{
	ASSERT_ERR((((uint32_t)p3inu2 << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)p3inu2 <<25));
}
__INLINE uint8_t usbc_guctl_1_dev_l_1_exit_by_hw_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void usbc_guctl_1_dev_l_1_exit_by_hw_setf(uint8_t devl1exitbyhw)
{
	ASSERT_ERR((((uint32_t)devl1exitbyhw << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)devl1exitbyhw <<24));
}
__INLINE uint8_t usbc_guctl_1_ip_gap_add_on_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00E00000)) >> 21);
}
__INLINE void usbc_guctl_1_ip_gap_add_on_setf(uint8_t ipgapaddon)
{
	ASSERT_ERR((((uint32_t)ipgapaddon << 21) & ~((uint32_t)0x00E00000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00E00000)) | ((uint32_t)ipgapaddon <<21));
}
__INLINE uint8_t usbc_guctl_1_dev_lsp_tail_lock_dis_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void usbc_guctl_1_dev_lsp_tail_lock_dis_setf(uint8_t devlsptaillockdis)
{
	ASSERT_ERR((((uint32_t)devlsptaillockdis << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)devlsptaillockdis <<20));
}
__INLINE uint8_t usbc_guctl_1_nak_per_enh_fs_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void usbc_guctl_1_nak_per_enh_fs_setf(uint8_t nakperenhfs)
{
	ASSERT_ERR((((uint32_t)nakperenhfs << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)nakperenhfs <<19));
}
__INLINE uint8_t usbc_guctl_1_nak_per_enh_hs_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void usbc_guctl_1_nak_per_enh_hs_setf(uint8_t nakperenhhs)
{
	ASSERT_ERR((((uint32_t)nakperenhhs << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)nakperenhhs <<18));
}
__INLINE uint8_t usbc_guctl_1_parkmode_disable_ss_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void usbc_guctl_1_parkmode_disable_ss_setf(uint8_t parkmodedisabless)
{
	ASSERT_ERR((((uint32_t)parkmodedisabless << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)parkmodedisabless <<17));
}
__INLINE uint8_t usbc_guctl_1_parkmode_disable_hs_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void usbc_guctl_1_parkmode_disable_hs_setf(uint8_t parkmodedisablehs)
{
	ASSERT_ERR((((uint32_t)parkmodedisablehs << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)parkmodedisablehs <<16));
}
__INLINE uint8_t usbc_guctl_1_parkmode_disable_fsls_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void usbc_guctl_1_parkmode_disable_fsls_setf(uint8_t parkmodedisablefsls)
{
	ASSERT_ERR((((uint32_t)parkmodedisablefsls << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)parkmodedisablefsls <<15));
}
__INLINE uint8_t usbc_guctl_1_reserved_14_13_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00006000)) >> 13);
}
__INLINE uint8_t usbc_guctl_1_dis_usb_2_ref_clk_gtng_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t usbc_guctl_1_dis_ref_clk_gtng_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t usbc_guctl_1_resume_opmode_hs_host_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_guctl_1_resume_opmode_hs_host_setf(uint8_t resumeopmodehshost)
{
	ASSERT_ERR((((uint32_t)resumeopmodehshost << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)resumeopmodehshost <<10));
}
__INLINE uint8_t usbc_guctl_1_dev_hs_nyet_bulk_spr_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void usbc_guctl_1_dev_hs_nyet_bulk_spr_setf(uint8_t devhsnyetbulkspr)
{
	ASSERT_ERR((((uint32_t)devhsnyetbulkspr << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)devhsnyetbulkspr <<9));
}
__INLINE uint8_t usbc_guctl_1_l_1_susp_thrld_en_for_host_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_guctl_1_l_1_susp_thrld_en_for_host_setf(uint8_t l1suspthrldenforhost)
{
	ASSERT_ERR((((uint32_t)l1suspthrldenforhost << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)l1suspthrldenforhost <<8));
}
__INLINE uint8_t usbc_guctl_1_l_1_susp_thrld_for_host_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void usbc_guctl_1_l_1_susp_thrld_for_host_setf(uint8_t l1suspthrldforhost)
{
	ASSERT_ERR((((uint32_t)l1suspthrldforhost << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)l1suspthrldforhost <<4));
}
__INLINE uint8_t usbc_guctl_1_hc_errata_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void usbc_guctl_1_hc_errata_enable_setf(uint8_t hcerrataenable)
{
	ASSERT_ERR((((uint32_t)hcerrataenable << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)hcerrataenable <<3));
}
__INLINE uint8_t usbc_guctl_1_hc_parchk_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void usbc_guctl_1_hc_parchk_disable_setf(uint8_t hcparchkdisable)
{
	ASSERT_ERR((((uint32_t)hcparchkdisable << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)hcparchkdisable <<2));
}
__INLINE uint8_t usbc_guctl_1_ovrld_l_1_susp_com_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void usbc_guctl_1_ovrld_l_1_susp_com_setf(uint8_t ovrldl1suspcom)
{
	ASSERT_ERR((((uint32_t)ovrldl1suspcom << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)ovrldl1suspcom <<1));
}
__INLINE uint8_t usbc_guctl_1_loa_filter_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void usbc_guctl_1_loa_filter_en_setf(uint8_t loafilteren)
{
	ASSERT_ERR((((uint32_t)loafilteren << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(USBC_GUCTL_1_ADDR, (REG_PL_RD(USBC_GUCTL_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)loafilteren <<0));
}

/**
 * @brief GSNPSID register definition
 *  Global Synopsys ID Register  This is a read-only register that contains the release number of the controller. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SYNOPSYSID                0x5533330b
 * </pre>
 */
#define USBC_GSNPSID_ADDR        (REG_USBC_BASE_ADDR+0x0000C120)
#define USBC_GSNPSID_OFFSET      0x0000C120
#define USBC_GSNPSID_INDEX       0x00003048
#define USBC_GSNPSID_RESET       0x5533330B

__INLINE uint32_t  usbc_gsnpsid_get(void)
{
	return REG_PL_RD(USBC_GSNPSID_ADDR);
}

// field definitions
#define USBC_GSNPSID_SYNOPSYSID_MASK        ((uint32_t)0xFFFFFFFF)
#define USBC_GSNPSID_SYNOPSYSID_LSB         0
#define USBC_GSNPSID_SYNOPSYSID_WIDTH       ((uint32_t)0x00000020)

#define USBC_GSNPSID_SYNOPSYSID_RST         0x5533330b

__INLINE uint32_t usbc_gsnpsid_synopsysid_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GSNPSID_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief GGPIO register definition
 *  Global General Purpose Input/Output Register  The application can use this register for general purpose input and output ports or for debugging. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 GPO                       0x0
 *    15:00 GPI                       0x0
 * </pre>
 */
#define USBC_GGPIO_ADDR        (REG_USBC_BASE_ADDR+0x0000C124)
#define USBC_GGPIO_OFFSET      0x0000C124
#define USBC_GGPIO_INDEX       0x00003049
#define USBC_GGPIO_RESET       0x00000000

__INLINE uint32_t  usbc_ggpio_get(void)
{
	return REG_PL_RD(USBC_GGPIO_ADDR);
}

__INLINE void usbc_ggpio_set(uint32_t value)
{
	REG_PL_WR(USBC_GGPIO_ADDR, value);
}

// field definitions
#define USBC_GGPIO_GPO_MASK                 ((uint32_t)0xFFFF0000)
#define USBC_GGPIO_GPO_LSB                  16
#define USBC_GGPIO_GPO_WIDTH                ((uint32_t)0x00000010)
#define USBC_GGPIO_GPI_MASK                 ((uint32_t)0x0000FFFF)
#define USBC_GGPIO_GPI_LSB                  0
#define USBC_GGPIO_GPI_WIDTH                ((uint32_t)0x00000010)

#define USBC_GGPIO_GPO_RST                  0x0
#define USBC_GGPIO_GPI_RST                  0x0

__INLINE void usbc_ggpio_pack(uint16_t gpo, uint16_t gpi)
{
	ASSERT_ERR((((uint32_t)gpo << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)gpi << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GGPIO_ADDR,  ((uint32_t)gpo << 16) |((uint32_t)gpi << 0));
}

__INLINE void usbc_ggpio_unpack(uint16_t* gpo, uint16_t* gpi)
{
	uint32_t localVal = REG_PL_RD(USBC_GGPIO_ADDR);

	*gpo = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*gpi = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_ggpio_gpo_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GGPIO_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_ggpio_gpo_setf(uint16_t gpo)
{
	ASSERT_ERR((((uint32_t)gpo << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GGPIO_ADDR, (REG_PL_RD(USBC_GGPIO_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)gpo <<16));
}
__INLINE uint16_t usbc_ggpio_gpi_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GGPIO_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief GUID register definition
 *  Global User ID Register  This is a read/write register containing the User ID. The power-on value for this register is specified as the User Identification Register. Power-on value during coreConsultant configuration (parameter DWC_USB3_USERID). This register can be used in the following ways:  - To store the version or revision of your system;  - To store hardware configurations that are outside the controller;  - As a scratch register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USERID                    0xcafecafe
 * </pre>
 */
#define USBC_GUID_ADDR        (REG_USBC_BASE_ADDR+0x0000C128)
#define USBC_GUID_OFFSET      0x0000C128
#define USBC_GUID_INDEX       0x0000304A
#define USBC_GUID_RESET       0xCAFECAFE

__INLINE uint32_t  usbc_guid_get(void)
{
	return REG_PL_RD(USBC_GUID_ADDR);
}

__INLINE void usbc_guid_set(uint32_t value)
{
	REG_PL_WR(USBC_GUID_ADDR, value);
}

// field definitions
#define USBC_GUID_USERID_MASK               ((uint32_t)0xFFFFFFFF)
#define USBC_GUID_USERID_LSB                0
#define USBC_GUID_USERID_WIDTH              ((uint32_t)0x00000020)

#define USBC_GUID_USERID_RST                0xcafecafe

__INLINE uint32_t usbc_guid_userid_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUID_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_guid_userid_setf(uint32_t userid)
{
	ASSERT_ERR((((uint32_t)userid << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_GUID_ADDR, (uint32_t)userid << 0);
}

/**
 * @brief GUCTL register definition
 *  Global User Control Register:    This register provides a few options for the software to control the controller behavior in the Host mode. Most of the options are used to improve host inter-operability with different devices. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:22 REFCLKPER                 0x8
 *    21    No_Extr_Dl                0              
 *    20:18 reserved_20_18            0x0
 *    17    Sprs_Ctrl_Trans_En        0              
 *    16    Res_Bw_HSEPS              0              
 *    15    reserved_15               0              
 *    14    USBHst_In_Auto_Retry_En   0              
 *    13    En_Overlap_Chk            0              
 *    12    Ext_Cap_Suppt_EN          0              
 *    11    Insrt_Extr_FSBODI         0              
 *    10:09 DTCT                      0x0
 *    08:00 DTFT                      0x10
 * </pre>
 */
#define USBC_GUCTL_ADDR        (REG_USBC_BASE_ADDR+0x0000C12C)
#define USBC_GUCTL_OFFSET      0x0000C12C
#define USBC_GUCTL_INDEX       0x0000304B
#define USBC_GUCTL_RESET       0x02000010

__INLINE uint32_t  usbc_guctl_get(void)
{
	return REG_PL_RD(USBC_GUCTL_ADDR);
}

__INLINE void usbc_guctl_set(uint32_t value)
{
	REG_PL_WR(USBC_GUCTL_ADDR, value);
}

// field definitions
#define USBC_GUCTL_REFCLKPER_MASK           ((uint32_t)0xFFC00000)
#define USBC_GUCTL_REFCLKPER_LSB            22
#define USBC_GUCTL_REFCLKPER_WIDTH          ((uint32_t)0x0000000A)
#define USBC_GUCTL_NO_EXTR_DL_BIT           ((uint32_t)0x00200000)
#define USBC_GUCTL_NO_EXTR_DL_POS           21
#define USBC_GUCTL_RESERVED_20_18_MASK      ((uint32_t)0x001C0000)
#define USBC_GUCTL_RESERVED_20_18_LSB       18
#define USBC_GUCTL_RESERVED_20_18_WIDTH     ((uint32_t)0x00000003)
#define USBC_GUCTL_SPRS_CTRL_TRANS_EN_BIT    ((uint32_t)0x00020000)
#define USBC_GUCTL_SPRS_CTRL_TRANS_EN_POS    17
#define USBC_GUCTL_RES_BW_HSEPS_BIT         ((uint32_t)0x00010000)
#define USBC_GUCTL_RES_BW_HSEPS_POS         16
#define USBC_GUCTL_RESERVED_15_BIT          ((uint32_t)0x00008000)
#define USBC_GUCTL_RESERVED_15_POS          15
#define USBC_GUCTL_USBHST_IN_AUTO_RETRY_EN_BIT    ((uint32_t)0x00004000)
#define USBC_GUCTL_USBHST_IN_AUTO_RETRY_EN_POS    14
#define USBC_GUCTL_EN_OVERLAP_CHK_BIT       ((uint32_t)0x00002000)
#define USBC_GUCTL_EN_OVERLAP_CHK_POS       13
#define USBC_GUCTL_EXT_CAP_SUPPT_EN_BIT     ((uint32_t)0x00001000)
#define USBC_GUCTL_EXT_CAP_SUPPT_EN_POS     12
#define USBC_GUCTL_INSRT_EXTR_FSBODI_BIT    ((uint32_t)0x00000800)
#define USBC_GUCTL_INSRT_EXTR_FSBODI_POS    11
#define USBC_GUCTL_DTCT_MASK                ((uint32_t)0x00000600)
#define USBC_GUCTL_DTCT_LSB                 9
#define USBC_GUCTL_DTCT_WIDTH               ((uint32_t)0x00000002)
#define USBC_GUCTL_DTFT_MASK                ((uint32_t)0x000001FF)
#define USBC_GUCTL_DTFT_LSB                 0
#define USBC_GUCTL_DTFT_WIDTH               ((uint32_t)0x00000009)

#define USBC_GUCTL_REFCLKPER_RST            0x8
#define USBC_GUCTL_NO_EXTR_DL_RST           0x0
#define USBC_GUCTL_RESERVED_20_18_RST       0x0
#define USBC_GUCTL_SPRS_CTRL_TRANS_EN_RST    0x0
#define USBC_GUCTL_RES_BW_HSEPS_RST         0x0
#define USBC_GUCTL_RESERVED_15_RST          0x0
#define USBC_GUCTL_USBHST_IN_AUTO_RETRY_EN_RST    0x0
#define USBC_GUCTL_EN_OVERLAP_CHK_RST       0x0
#define USBC_GUCTL_EXT_CAP_SUPPT_EN_RST     0x0
#define USBC_GUCTL_INSRT_EXTR_FSBODI_RST    0x0
#define USBC_GUCTL_DTCT_RST                 0x0
#define USBC_GUCTL_DTFT_RST                 0x10

__INLINE void usbc_guctl_pack(uint16_t refclkper, uint8_t no_extr_dl, uint8_t reserved_20_18, uint8_t sprs_ctrl_trans_en, uint8_t res_bw_hseps, uint8_t reserved_15, uint8_t usbhst_in_auto_retry_en, uint8_t en_overlap_chk, uint8_t ext_cap_suppt_en, uint8_t insrt_extr_fsbodi, uint8_t dtct, uint16_t dtft)
{
	ASSERT_ERR((((uint32_t)refclkper << 22) & ~((uint32_t)0xFFC00000)) == 0);
	ASSERT_ERR((((uint32_t)no_extr_dl << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_20_18 << 18) & ~((uint32_t)0x001C0000)) == 0);
	ASSERT_ERR((((uint32_t)sprs_ctrl_trans_en << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)res_bw_hseps << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_15 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)usbhst_in_auto_retry_en << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)en_overlap_chk << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)ext_cap_suppt_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)insrt_extr_fsbodi << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)dtct << 9) & ~((uint32_t)0x00000600)) == 0);
	ASSERT_ERR((((uint32_t)dtft << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(USBC_GUCTL_ADDR,  ((uint32_t)refclkper << 22) |((uint32_t)no_extr_dl << 21) |((uint32_t)reserved_20_18 << 18) |((uint32_t)sprs_ctrl_trans_en << 17) |((uint32_t)res_bw_hseps << 16) |((uint32_t)reserved_15 << 15) |((uint32_t)usbhst_in_auto_retry_en << 14) |((uint32_t)en_overlap_chk << 13) |((uint32_t)ext_cap_suppt_en << 12) |((uint32_t)insrt_extr_fsbodi << 11) |((uint32_t)dtct << 9) |((uint32_t)dtft << 0));
}

__INLINE void usbc_guctl_unpack(uint16_t* refclkper, uint8_t* no_extr_dl, uint8_t* reserved_20_18, uint8_t* sprs_ctrl_trans_en, uint8_t* res_bw_hseps, uint8_t* reserved_15, uint8_t* usbhst_in_auto_retry_en, uint8_t* en_overlap_chk, uint8_t* ext_cap_suppt_en, uint8_t* insrt_extr_fsbodi, uint8_t* dtct, uint16_t* dtft)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);

	*refclkper = (localVal & ((uint32_t)0xFFC00000)) >>  22;
	*no_extr_dl = (localVal & ((uint32_t)0x00200000)) >>  21;
	*reserved_20_18 = (localVal & ((uint32_t)0x001C0000)) >>  18;
	*sprs_ctrl_trans_en = (localVal & ((uint32_t)0x00020000)) >>  17;
	*res_bw_hseps = (localVal & ((uint32_t)0x00010000)) >>  16;
	*reserved_15 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*usbhst_in_auto_retry_en = (localVal & ((uint32_t)0x00004000)) >>  14;
	*en_overlap_chk = (localVal & ((uint32_t)0x00002000)) >>  13;
	*ext_cap_suppt_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*insrt_extr_fsbodi = (localVal & ((uint32_t)0x00000800)) >>  11;
	*dtct = (localVal & ((uint32_t)0x00000600)) >>  9;
	*dtft = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t usbc_guctl_refclkper_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFC00000)) >> 22);
}
__INLINE void usbc_guctl_refclkper_setf(uint16_t refclkper)
{
	ASSERT_ERR((((uint32_t)refclkper << 22) & ~((uint32_t)0xFFC00000)) == 0);
	REG_PL_WR(USBC_GUCTL_ADDR, (REG_PL_RD(USBC_GUCTL_ADDR) & ~((uint32_t)0xFFC00000)) | ((uint32_t)refclkper <<22));
}
__INLINE uint8_t usbc_guctl_no_extr_dl_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void usbc_guctl_no_extr_dl_setf(uint8_t noextrdl)
{
	ASSERT_ERR((((uint32_t)noextrdl << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(USBC_GUCTL_ADDR, (REG_PL_RD(USBC_GUCTL_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)noextrdl <<21));
}
__INLINE uint8_t usbc_guctl_reserved_20_18_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001C0000)) >> 18);
}
__INLINE uint8_t usbc_guctl_sprs_ctrl_trans_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void usbc_guctl_sprs_ctrl_trans_en_setf(uint8_t sprsctrltransen)
{
	ASSERT_ERR((((uint32_t)sprsctrltransen << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(USBC_GUCTL_ADDR, (REG_PL_RD(USBC_GUCTL_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)sprsctrltransen <<17));
}
__INLINE uint8_t usbc_guctl_res_bw_hseps_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void usbc_guctl_res_bw_hseps_setf(uint8_t resbwhseps)
{
	ASSERT_ERR((((uint32_t)resbwhseps << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(USBC_GUCTL_ADDR, (REG_PL_RD(USBC_GUCTL_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)resbwhseps <<16));
}
__INLINE uint8_t usbc_guctl_reserved_15_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t usbc_guctl_usbhst_in_auto_retry_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void usbc_guctl_usbhst_in_auto_retry_en_setf(uint8_t usbhstinautoretryen)
{
	ASSERT_ERR((((uint32_t)usbhstinautoretryen << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(USBC_GUCTL_ADDR, (REG_PL_RD(USBC_GUCTL_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)usbhstinautoretryen <<14));
}
__INLINE uint8_t usbc_guctl_en_overlap_chk_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void usbc_guctl_en_overlap_chk_setf(uint8_t enoverlapchk)
{
	ASSERT_ERR((((uint32_t)enoverlapchk << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(USBC_GUCTL_ADDR, (REG_PL_RD(USBC_GUCTL_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)enoverlapchk <<13));
}
__INLINE uint8_t usbc_guctl_ext_cap_suppt_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void usbc_guctl_ext_cap_suppt_en_setf(uint8_t extcapsuppten)
{
	ASSERT_ERR((((uint32_t)extcapsuppten << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(USBC_GUCTL_ADDR, (REG_PL_RD(USBC_GUCTL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)extcapsuppten <<12));
}
__INLINE uint8_t usbc_guctl_insrt_extr_fsbodi_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_guctl_insrt_extr_fsbodi_setf(uint8_t insrtextrfsbodi)
{
	ASSERT_ERR((((uint32_t)insrtextrfsbodi << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_GUCTL_ADDR, (REG_PL_RD(USBC_GUCTL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)insrtextrfsbodi <<11));
}
__INLINE uint8_t usbc_guctl_dtct_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000600)) >> 9);
}
__INLINE void usbc_guctl_dtct_setf(uint8_t dtct)
{
	ASSERT_ERR((((uint32_t)dtct << 9) & ~((uint32_t)0x00000600)) == 0);
	REG_PL_WR(USBC_GUCTL_ADDR, (REG_PL_RD(USBC_GUCTL_ADDR) & ~((uint32_t)0x00000600)) | ((uint32_t)dtct <<9));
}
__INLINE uint16_t usbc_guctl_dtft_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void usbc_guctl_dtft_setf(uint16_t dtft)
{
	ASSERT_ERR((((uint32_t)dtft << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(USBC_GUCTL_ADDR, (REG_PL_RD(USBC_GUCTL_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)dtft <<0));
}

/**
 * @brief GBUSERRADDRLO register definition
 *  Gobal SoC Bus Error Address Register - Low  This is an alternate register for the GBUSERRADDR register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BUSERRADDR                0x0
 * </pre>
 */
#define USBC_GBUSERRADDRLO_ADDR        (REG_USBC_BASE_ADDR+0x0000C130)
#define USBC_GBUSERRADDRLO_OFFSET      0x0000C130
#define USBC_GBUSERRADDRLO_INDEX       0x0000304C
#define USBC_GBUSERRADDRLO_RESET       0x00000000

__INLINE uint32_t  usbc_gbuserraddrlo_get(void)
{
	return REG_PL_RD(USBC_GBUSERRADDRLO_ADDR);
}

// field definitions
#define USBC_GBUSERRADDRLO_BUSERRADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_GBUSERRADDRLO_BUSERRADDR_LSB    0
#define USBC_GBUSERRADDRLO_BUSERRADDR_WIDTH    ((uint32_t)0x00000020)

#define USBC_GBUSERRADDRLO_BUSERRADDR_RST    0x0

__INLINE uint32_t usbc_gbuserraddrlo_buserraddr_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GBUSERRADDRLO_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief GBUSERRADDRHI register definition
 *  Gobal SoC Bus Error Address Register - High  This is an alternate register for the GBUSERRADDR register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BUSERRADDR                0x0
 * </pre>
 */
#define USBC_GBUSERRADDRHI_ADDR        (REG_USBC_BASE_ADDR+0x0000C134)
#define USBC_GBUSERRADDRHI_OFFSET      0x0000C134
#define USBC_GBUSERRADDRHI_INDEX       0x0000304D
#define USBC_GBUSERRADDRHI_RESET       0x00000000

__INLINE uint32_t  usbc_gbuserraddrhi_get(void)
{
	return REG_PL_RD(USBC_GBUSERRADDRHI_ADDR);
}

// field definitions
#define USBC_GBUSERRADDRHI_BUSERRADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_GBUSERRADDRHI_BUSERRADDR_LSB    0
#define USBC_GBUSERRADDRHI_BUSERRADDR_WIDTH    ((uint32_t)0x00000020)

#define USBC_GBUSERRADDRHI_BUSERRADDR_RST    0x0

__INLINE uint32_t usbc_gbuserraddrhi_buserraddr_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GBUSERRADDRHI_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief GPRTBIMAPLO register definition
 *  Global SS Port to Bus Instance Mapping Register - Low  This is an alternate register for the GPRTBIMAP register.  Register fields are read-write with respect to number of port instantiated. writeAsRead constraint is added to limit side effects for unused fields.   For a configuration with number of USB 3.0 ports same as number of SS Bus Instances, do not remap during debug session. If you remap for some reason, then the debug host must be connected to a port which has a dedicated SS Bus Instance.  For example, if DWC_USB3_NUM_U3_ROOT_PORTS =3 and DWC_USB3_NUM_SS_USB_INSTANCES=3, and software maps the first SS port to the first SS BI and the second/third port to the second BI, then the debug host can be connected to the first port only.  Note: For reset values, refer to the corresponding values in the GPRTBIMAP register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 BINUM8                    0x0
 *    27:24 BINUM7                    0x0
 *    23:20 BINUM6                    0x0
 *    19:16 BINUM5                    0x0
 *    15:12 BINUM4                    0x0
 *    11:08 BINUM3                    0x0
 *    07:04 BINUM2                    0x0
 *    03:00 BINUM1                    0x0
 * </pre>
 */
#define USBC_GPRTBIMAPLO_ADDR        (REG_USBC_BASE_ADDR+0x0000C138)
#define USBC_GPRTBIMAPLO_OFFSET      0x0000C138
#define USBC_GPRTBIMAPLO_INDEX       0x0000304E
#define USBC_GPRTBIMAPLO_RESET       0x00000000

__INLINE uint32_t  usbc_gprtbimaplo_get(void)
{
	return REG_PL_RD(USBC_GPRTBIMAPLO_ADDR);
}

__INLINE void usbc_gprtbimaplo_set(uint32_t value)
{
	REG_PL_WR(USBC_GPRTBIMAPLO_ADDR, value);
}

// field definitions
#define USBC_GPRTBIMAPLO_BINUM_8_MASK       ((uint32_t)0xF0000000)
#define USBC_GPRTBIMAPLO_BINUM_8_LSB        28
#define USBC_GPRTBIMAPLO_BINUM_8_WIDTH      ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPLO_BINUM_7_MASK       ((uint32_t)0x0F000000)
#define USBC_GPRTBIMAPLO_BINUM_7_LSB        24
#define USBC_GPRTBIMAPLO_BINUM_7_WIDTH      ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPLO_BINUM_6_MASK       ((uint32_t)0x00F00000)
#define USBC_GPRTBIMAPLO_BINUM_6_LSB        20
#define USBC_GPRTBIMAPLO_BINUM_6_WIDTH      ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPLO_BINUM_5_MASK       ((uint32_t)0x000F0000)
#define USBC_GPRTBIMAPLO_BINUM_5_LSB        16
#define USBC_GPRTBIMAPLO_BINUM_5_WIDTH      ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPLO_BINUM_4_MASK       ((uint32_t)0x0000F000)
#define USBC_GPRTBIMAPLO_BINUM_4_LSB        12
#define USBC_GPRTBIMAPLO_BINUM_4_WIDTH      ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPLO_BINUM_3_MASK       ((uint32_t)0x00000F00)
#define USBC_GPRTBIMAPLO_BINUM_3_LSB        8
#define USBC_GPRTBIMAPLO_BINUM_3_WIDTH      ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPLO_BINUM_2_MASK       ((uint32_t)0x000000F0)
#define USBC_GPRTBIMAPLO_BINUM_2_LSB        4
#define USBC_GPRTBIMAPLO_BINUM_2_WIDTH      ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPLO_BINUM_1_MASK       ((uint32_t)0x0000000F)
#define USBC_GPRTBIMAPLO_BINUM_1_LSB        0
#define USBC_GPRTBIMAPLO_BINUM_1_WIDTH      ((uint32_t)0x00000004)

#define USBC_GPRTBIMAPLO_BINUM_8_RST        0x0
#define USBC_GPRTBIMAPLO_BINUM_7_RST        0x0
#define USBC_GPRTBIMAPLO_BINUM_6_RST        0x0
#define USBC_GPRTBIMAPLO_BINUM_5_RST        0x0
#define USBC_GPRTBIMAPLO_BINUM_4_RST        0x0
#define USBC_GPRTBIMAPLO_BINUM_3_RST        0x0
#define USBC_GPRTBIMAPLO_BINUM_2_RST        0x0
#define USBC_GPRTBIMAPLO_BINUM_1_RST        0x0

__INLINE void usbc_gprtbimaplo_pack(uint8_t binum8, uint8_t binum7, uint8_t binum6, uint8_t binum5, uint8_t binum4, uint8_t binum3, uint8_t binum2, uint8_t binum1)
{
	ASSERT_ERR((((uint32_t)binum8 << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)binum7 << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)binum6 << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)binum5 << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)binum4 << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)binum3 << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)binum2 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)binum1 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPLO_ADDR,  ((uint32_t)binum8 << 28) |((uint32_t)binum7 << 24) |((uint32_t)binum6 << 20) |((uint32_t)binum5 << 16) |((uint32_t)binum4 << 12) |((uint32_t)binum3 << 8) |((uint32_t)binum2 << 4) |((uint32_t)binum1 << 0));
}

__INLINE void usbc_gprtbimaplo_unpack(uint8_t* binum8, uint8_t* binum7, uint8_t* binum6, uint8_t* binum5, uint8_t* binum4, uint8_t* binum3, uint8_t* binum2, uint8_t* binum1)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPLO_ADDR);

	*binum8 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*binum7 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*binum6 = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*binum5 = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*binum4 = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*binum3 = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*binum2 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*binum1 = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t usbc_gprtbimaplo_binum_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void usbc_gprtbimaplo_binum_8_setf(uint8_t binum8)
{
	ASSERT_ERR((((uint32_t)binum8 << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAPLO_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)binum8 <<28));
}
__INLINE uint8_t usbc_gprtbimaplo_binum_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void usbc_gprtbimaplo_binum_7_setf(uint8_t binum7)
{
	ASSERT_ERR((((uint32_t)binum7 << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAPLO_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)binum7 <<24));
}
__INLINE uint8_t usbc_gprtbimaplo_binum_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void usbc_gprtbimaplo_binum_6_setf(uint8_t binum6)
{
	ASSERT_ERR((((uint32_t)binum6 << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAPLO_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)binum6 <<20));
}
__INLINE uint8_t usbc_gprtbimaplo_binum_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void usbc_gprtbimaplo_binum_5_setf(uint8_t binum5)
{
	ASSERT_ERR((((uint32_t)binum5 << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAPLO_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)binum5 <<16));
}
__INLINE uint8_t usbc_gprtbimaplo_binum_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_gprtbimaplo_binum_4_setf(uint8_t binum4)
{
	ASSERT_ERR((((uint32_t)binum4 << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAPLO_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)binum4 <<12));
}
__INLINE uint8_t usbc_gprtbimaplo_binum_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void usbc_gprtbimaplo_binum_3_setf(uint8_t binum3)
{
	ASSERT_ERR((((uint32_t)binum3 << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAPLO_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)binum3 <<8));
}
__INLINE uint8_t usbc_gprtbimaplo_binum_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void usbc_gprtbimaplo_binum_2_setf(uint8_t binum2)
{
	ASSERT_ERR((((uint32_t)binum2 << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAPLO_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)binum2 <<4));
}
__INLINE uint8_t usbc_gprtbimaplo_binum_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_gprtbimaplo_binum_1_setf(uint8_t binum1)
{
	ASSERT_ERR((((uint32_t)binum1 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAPLO_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)binum1 <<0));
}

/**
 * @brief GPRTBIMAPHI register definition
 *  Global SS Port to Bus Instance Mapping Register - High  This is an alternate register for the GPRTBIMAP register.  For a configuration with number of USB 3.0 ports same as number of SS Bus Instances, do not remap during debug session. If you remap for some reason, then the debug host must be connected to a port which has a dedicated SS Bus Instance.  For example, if DWC_USB3_NUM_U3_ROOT_PORTS =3 and DWC_USB3_NUM_SS_USB_INSTANCES=3, and software maps the first SS port to the first SS BI and the second/third port to the second BI, then the debug host can be connected to the first port only.  Note: For reset values, refer to the corresponding values in the GPRTBIMAP register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 reserved_31_28            0x0
 *    27:24 BINUM15                   0x0
 *    23:20 BINUM14                   0x0
 *    19:16 BINUM13                   0x0
 *    15:12 BINUM12                   0x0
 *    11:08 BINUM11                   0x0
 *    07:04 BINUM10                   0x0
 *    03:00 BINUM9                    0x0
 * </pre>
 */
#define USBC_GPRTBIMAPHI_ADDR        (REG_USBC_BASE_ADDR+0x0000C13C)
#define USBC_GPRTBIMAPHI_OFFSET      0x0000C13C
#define USBC_GPRTBIMAPHI_INDEX       0x0000304F
#define USBC_GPRTBIMAPHI_RESET       0x00000000

__INLINE uint32_t  usbc_gprtbimaphi_get(void)
{
	return REG_PL_RD(USBC_GPRTBIMAPHI_ADDR);
}

__INLINE void usbc_gprtbimaphi_set(uint32_t value)
{
	REG_PL_WR(USBC_GPRTBIMAPHI_ADDR, value);
}

// field definitions
#define USBC_GPRTBIMAPHI_RESERVED_31_28_MASK    ((uint32_t)0xF0000000)
#define USBC_GPRTBIMAPHI_RESERVED_31_28_LSB    28
#define USBC_GPRTBIMAPHI_RESERVED_31_28_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPHI_BINUM_15_MASK      ((uint32_t)0x0F000000)
#define USBC_GPRTBIMAPHI_BINUM_15_LSB       24
#define USBC_GPRTBIMAPHI_BINUM_15_WIDTH     ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPHI_BINUM_14_MASK      ((uint32_t)0x00F00000)
#define USBC_GPRTBIMAPHI_BINUM_14_LSB       20
#define USBC_GPRTBIMAPHI_BINUM_14_WIDTH     ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPHI_BINUM_13_MASK      ((uint32_t)0x000F0000)
#define USBC_GPRTBIMAPHI_BINUM_13_LSB       16
#define USBC_GPRTBIMAPHI_BINUM_13_WIDTH     ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPHI_BINUM_12_MASK      ((uint32_t)0x0000F000)
#define USBC_GPRTBIMAPHI_BINUM_12_LSB       12
#define USBC_GPRTBIMAPHI_BINUM_12_WIDTH     ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPHI_BINUM_11_MASK      ((uint32_t)0x00000F00)
#define USBC_GPRTBIMAPHI_BINUM_11_LSB       8
#define USBC_GPRTBIMAPHI_BINUM_11_WIDTH     ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPHI_BINUM_10_MASK      ((uint32_t)0x000000F0)
#define USBC_GPRTBIMAPHI_BINUM_10_LSB       4
#define USBC_GPRTBIMAPHI_BINUM_10_WIDTH     ((uint32_t)0x00000004)
#define USBC_GPRTBIMAPHI_BINUM_9_MASK       ((uint32_t)0x0000000F)
#define USBC_GPRTBIMAPHI_BINUM_9_LSB        0
#define USBC_GPRTBIMAPHI_BINUM_9_WIDTH      ((uint32_t)0x00000004)

#define USBC_GPRTBIMAPHI_RESERVED_31_28_RST    0x0
#define USBC_GPRTBIMAPHI_BINUM_15_RST       0x0
#define USBC_GPRTBIMAPHI_BINUM_14_RST       0x0
#define USBC_GPRTBIMAPHI_BINUM_13_RST       0x0
#define USBC_GPRTBIMAPHI_BINUM_12_RST       0x0
#define USBC_GPRTBIMAPHI_BINUM_11_RST       0x0
#define USBC_GPRTBIMAPHI_BINUM_10_RST       0x0
#define USBC_GPRTBIMAPHI_BINUM_9_RST        0x0

__INLINE void usbc_gprtbimaphi_pack(uint8_t reserved_31_28, uint8_t binum15, uint8_t binum14, uint8_t binum13, uint8_t binum12, uint8_t binum11, uint8_t binum10, uint8_t binum9)
{
	ASSERT_ERR((((uint32_t)reserved_31_28 << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)binum15 << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)binum14 << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)binum13 << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)binum12 << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)binum11 << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)binum10 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)binum9 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPHI_ADDR,  ((uint32_t)reserved_31_28 << 28) |((uint32_t)binum15 << 24) |((uint32_t)binum14 << 20) |((uint32_t)binum13 << 16) |((uint32_t)binum12 << 12) |((uint32_t)binum11 << 8) |((uint32_t)binum10 << 4) |((uint32_t)binum9 << 0));
}

__INLINE void usbc_gprtbimaphi_unpack(uint8_t* reserved_31_28, uint8_t* binum15, uint8_t* binum14, uint8_t* binum13, uint8_t* binum12, uint8_t* binum11, uint8_t* binum10, uint8_t* binum9)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPHI_ADDR);

	*reserved_31_28 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*binum15 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*binum14 = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*binum13 = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*binum12 = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*binum11 = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*binum10 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*binum9 = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t usbc_gprtbimaphi_reserved_31_28_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE uint8_t usbc_gprtbimaphi_binum_15_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void usbc_gprtbimaphi_binum_15_setf(uint8_t binum15)
{
	ASSERT_ERR((((uint32_t)binum15 << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAPHI_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)binum15 <<24));
}
__INLINE uint8_t usbc_gprtbimaphi_binum_14_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void usbc_gprtbimaphi_binum_14_setf(uint8_t binum14)
{
	ASSERT_ERR((((uint32_t)binum14 << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAPHI_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)binum14 <<20));
}
__INLINE uint8_t usbc_gprtbimaphi_binum_13_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void usbc_gprtbimaphi_binum_13_setf(uint8_t binum13)
{
	ASSERT_ERR((((uint32_t)binum13 << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAPHI_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)binum13 <<16));
}
__INLINE uint8_t usbc_gprtbimaphi_binum_12_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_gprtbimaphi_binum_12_setf(uint8_t binum12)
{
	ASSERT_ERR((((uint32_t)binum12 << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAPHI_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)binum12 <<12));
}
__INLINE uint8_t usbc_gprtbimaphi_binum_11_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void usbc_gprtbimaphi_binum_11_setf(uint8_t binum11)
{
	ASSERT_ERR((((uint32_t)binum11 << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAPHI_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)binum11 <<8));
}
__INLINE uint8_t usbc_gprtbimaphi_binum_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void usbc_gprtbimaphi_binum_10_setf(uint8_t binum10)
{
	ASSERT_ERR((((uint32_t)binum10 << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAPHI_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)binum10 <<4));
}
__INLINE uint8_t usbc_gprtbimaphi_binum_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAPHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_gprtbimaphi_binum_9_setf(uint8_t binum9)
{
	ASSERT_ERR((((uint32_t)binum9 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GPRTBIMAPHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAPHI_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)binum9 <<0));
}

/**
 * @brief GHWPARAMS_0 register definition
 *  Global Hardware Parameters Register 0  This register contains the hardware configuration options that you can select in the coreConsultant GUI.    For a description of each parameter, refer to the  Parameter Descriptions  chapter in the Databook. This information is also available in coreConsultant by right-clicking the parameter label and selecting  What s This  or by clicking the Help tab.    Note:   Some of the global hardware parameters are not currently modifiable in coreConsultant. These settings are in the   workspace /src/DWC_usb3_params.v file; you must not change them. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 ghwparams0_31_24          0x20
 *    23:16 ghwparams0_23_16          0x20
 *    15:08 ghwparams0_15_8           0x20
 *    07:06 ghwparams0_7_6            0x1
 *    05:03 ghwparams0_5_3            0x1
 *    02:00 ghwparams0_2_0            0x0
 * </pre>
 */
#define USBC_GHWPARAMS_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C140)
#define USBC_GHWPARAMS_0_OFFSET      0x0000C140
#define USBC_GHWPARAMS_0_INDEX       0x00003050
#define USBC_GHWPARAMS_0_RESET       0x20202048

__INLINE uint32_t  usbc_ghwparams_0_get(void)
{
	return REG_PL_RD(USBC_GHWPARAMS_0_ADDR);
}

// field definitions
#define USBC_GHWPARAMS_0_GHWPARAMS_0_31_24_MASK    ((uint32_t)0xFF000000)
#define USBC_GHWPARAMS_0_GHWPARAMS_0_31_24_LSB    24
#define USBC_GHWPARAMS_0_GHWPARAMS_0_31_24_WIDTH    ((uint32_t)0x00000008)
#define USBC_GHWPARAMS_0_GHWPARAMS_0_23_16_MASK    ((uint32_t)0x00FF0000)
#define USBC_GHWPARAMS_0_GHWPARAMS_0_23_16_LSB    16
#define USBC_GHWPARAMS_0_GHWPARAMS_0_23_16_WIDTH    ((uint32_t)0x00000008)
#define USBC_GHWPARAMS_0_GHWPARAMS_0_15_8_MASK    ((uint32_t)0x0000FF00)
#define USBC_GHWPARAMS_0_GHWPARAMS_0_15_8_LSB    8
#define USBC_GHWPARAMS_0_GHWPARAMS_0_15_8_WIDTH    ((uint32_t)0x00000008)
#define USBC_GHWPARAMS_0_GHWPARAMS_0_7_6_MASK    ((uint32_t)0x000000C0)
#define USBC_GHWPARAMS_0_GHWPARAMS_0_7_6_LSB    6
#define USBC_GHWPARAMS_0_GHWPARAMS_0_7_6_WIDTH    ((uint32_t)0x00000002)
#define USBC_GHWPARAMS_0_GHWPARAMS_0_5_3_MASK    ((uint32_t)0x00000038)
#define USBC_GHWPARAMS_0_GHWPARAMS_0_5_3_LSB    3
#define USBC_GHWPARAMS_0_GHWPARAMS_0_5_3_WIDTH    ((uint32_t)0x00000003)
#define USBC_GHWPARAMS_0_GHWPARAMS_0_2_0_MASK    ((uint32_t)0x00000007)
#define USBC_GHWPARAMS_0_GHWPARAMS_0_2_0_LSB    0
#define USBC_GHWPARAMS_0_GHWPARAMS_0_2_0_WIDTH    ((uint32_t)0x00000003)

#define USBC_GHWPARAMS_0_GHWPARAMS_0_31_24_RST    0x20
#define USBC_GHWPARAMS_0_GHWPARAMS_0_23_16_RST    0x20
#define USBC_GHWPARAMS_0_GHWPARAMS_0_15_8_RST    0x20
#define USBC_GHWPARAMS_0_GHWPARAMS_0_7_6_RST    0x1
#define USBC_GHWPARAMS_0_GHWPARAMS_0_5_3_RST    0x1
#define USBC_GHWPARAMS_0_GHWPARAMS_0_2_0_RST    0x0

__INLINE void usbc_ghwparams_0_unpack(uint8_t* ghwparams0_31_24, uint8_t* ghwparams0_23_16, uint8_t* ghwparams0_15_8, uint8_t* ghwparams0_7_6, uint8_t* ghwparams0_5_3, uint8_t* ghwparams0_2_0)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_0_ADDR);

	*ghwparams0_31_24 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*ghwparams0_23_16 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*ghwparams0_15_8 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*ghwparams0_7_6 = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*ghwparams0_5_3 = (localVal & ((uint32_t)0x00000038)) >>  3;
	*ghwparams0_2_0 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t usbc_ghwparams_0_ghwparams_0_31_24_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint8_t usbc_ghwparams_0_ghwparams_0_23_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t usbc_ghwparams_0_ghwparams_0_15_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t usbc_ghwparams_0_ghwparams_0_7_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE uint8_t usbc_ghwparams_0_ghwparams_0_5_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE uint8_t usbc_ghwparams_0_ghwparams_0_2_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief GHWPARAMS_1 register definition
 *  Global Hardware Parameters Register 1  This register contains the hardware configuration options that you can select in the coreConsultant GUI.    For a description of each parameter, refer to the  Parameter Descriptions  chapter in the Databook. This information is also available in coreConsultant by right-clicking the parameter label and selecting  What s This  or by clicking the Help tab.    Note:   Some of the global hardware parameters are not currently modifiable in coreConsultant. These settings are in the   workspace /src/DWC_usb3_params.v file; you must not change them. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    ghwparams1_31             0              
 *    30    ghwparams1_30             0              
 *    29    ghwparams1_29             0              
 *    28    ghwparams1_28             0              
 *    27    ghwparams1_27             0              
 *    26    ghwparams1_26             0              
 *    25:24 ghwparams1_25_24          0x1
 *    23    ghwparams1_23             0              
 *    22:21 ghwparams1_22_21          0x3
 *    20:15 ghwparams1_20_15          0x1
 *    14:12 ghwparams1_14_12          0x4
 *    11:09 ghwparams1_11_9           0x4
 *    08:06 ghwparams1_8_6            0x4
 *    05:03 ghwparams1_5_3            0x7
 *    02:00 ghwparams1_2_0            0x3
 * </pre>
 */
#define USBC_GHWPARAMS_1_ADDR        (REG_USBC_BASE_ADDR+0x0000C144)
#define USBC_GHWPARAMS_1_OFFSET      0x0000C144
#define USBC_GHWPARAMS_1_INDEX       0x00003051
#define USBC_GHWPARAMS_1_RESET       0x0160C93B

__INLINE uint32_t  usbc_ghwparams_1_get(void)
{
	return REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
}

// field definitions
#define USBC_GHWPARAMS_1_GHWPARAMS_1_31_BIT    ((uint32_t)0x80000000)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_31_POS    31
#define USBC_GHWPARAMS_1_GHWPARAMS_1_30_BIT    ((uint32_t)0x40000000)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_30_POS    30
#define USBC_GHWPARAMS_1_GHWPARAMS_1_29_BIT    ((uint32_t)0x20000000)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_29_POS    29
#define USBC_GHWPARAMS_1_GHWPARAMS_1_28_BIT    ((uint32_t)0x10000000)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_28_POS    28
#define USBC_GHWPARAMS_1_GHWPARAMS_1_27_BIT    ((uint32_t)0x08000000)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_27_POS    27
#define USBC_GHWPARAMS_1_GHWPARAMS_1_26_BIT    ((uint32_t)0x04000000)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_26_POS    26
#define USBC_GHWPARAMS_1_GHWPARAMS_1_25_24_MASK    ((uint32_t)0x03000000)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_25_24_LSB    24
#define USBC_GHWPARAMS_1_GHWPARAMS_1_25_24_WIDTH    ((uint32_t)0x00000002)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_23_BIT    ((uint32_t)0x00800000)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_23_POS    23
#define USBC_GHWPARAMS_1_GHWPARAMS_1_22_21_MASK    ((uint32_t)0x00600000)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_22_21_LSB    21
#define USBC_GHWPARAMS_1_GHWPARAMS_1_22_21_WIDTH    ((uint32_t)0x00000002)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_20_15_MASK    ((uint32_t)0x001F8000)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_20_15_LSB    15
#define USBC_GHWPARAMS_1_GHWPARAMS_1_20_15_WIDTH    ((uint32_t)0x00000006)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_14_12_MASK    ((uint32_t)0x00007000)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_14_12_LSB    12
#define USBC_GHWPARAMS_1_GHWPARAMS_1_14_12_WIDTH    ((uint32_t)0x00000003)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_11_9_MASK    ((uint32_t)0x00000E00)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_11_9_LSB    9
#define USBC_GHWPARAMS_1_GHWPARAMS_1_11_9_WIDTH    ((uint32_t)0x00000003)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_8_6_MASK    ((uint32_t)0x000001C0)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_8_6_LSB    6
#define USBC_GHWPARAMS_1_GHWPARAMS_1_8_6_WIDTH    ((uint32_t)0x00000003)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_5_3_MASK    ((uint32_t)0x00000038)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_5_3_LSB    3
#define USBC_GHWPARAMS_1_GHWPARAMS_1_5_3_WIDTH    ((uint32_t)0x00000003)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_2_0_MASK    ((uint32_t)0x00000007)
#define USBC_GHWPARAMS_1_GHWPARAMS_1_2_0_LSB    0
#define USBC_GHWPARAMS_1_GHWPARAMS_1_2_0_WIDTH    ((uint32_t)0x00000003)

#define USBC_GHWPARAMS_1_GHWPARAMS_1_31_RST    0x0
#define USBC_GHWPARAMS_1_GHWPARAMS_1_30_RST    0x0
#define USBC_GHWPARAMS_1_GHWPARAMS_1_29_RST    0x0
#define USBC_GHWPARAMS_1_GHWPARAMS_1_28_RST    0x0
#define USBC_GHWPARAMS_1_GHWPARAMS_1_27_RST    0x0
#define USBC_GHWPARAMS_1_GHWPARAMS_1_26_RST    0x0
#define USBC_GHWPARAMS_1_GHWPARAMS_1_25_24_RST    0x1
#define USBC_GHWPARAMS_1_GHWPARAMS_1_23_RST    0x0
#define USBC_GHWPARAMS_1_GHWPARAMS_1_22_21_RST    0x3
#define USBC_GHWPARAMS_1_GHWPARAMS_1_20_15_RST    0x1
#define USBC_GHWPARAMS_1_GHWPARAMS_1_14_12_RST    0x4
#define USBC_GHWPARAMS_1_GHWPARAMS_1_11_9_RST    0x4
#define USBC_GHWPARAMS_1_GHWPARAMS_1_8_6_RST    0x4
#define USBC_GHWPARAMS_1_GHWPARAMS_1_5_3_RST    0x7
#define USBC_GHWPARAMS_1_GHWPARAMS_1_2_0_RST    0x3

__INLINE void usbc_ghwparams_1_unpack(uint8_t* ghwparams1_31, uint8_t* ghwparams1_30, uint8_t* ghwparams1_29, uint8_t* ghwparams1_28, uint8_t* ghwparams1_27, uint8_t* ghwparams1_26, uint8_t* ghwparams1_25_24, uint8_t* ghwparams1_23, uint8_t* ghwparams1_22_21, uint8_t* ghwparams1_20_15, uint8_t* ghwparams1_14_12, uint8_t* ghwparams1_11_9, uint8_t* ghwparams1_8_6, uint8_t* ghwparams1_5_3, uint8_t* ghwparams1_2_0)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);

	*ghwparams1_31 = (localVal & ((uint32_t)0x80000000)) >>  31;
	*ghwparams1_30 = (localVal & ((uint32_t)0x40000000)) >>  30;
	*ghwparams1_29 = (localVal & ((uint32_t)0x20000000)) >>  29;
	*ghwparams1_28 = (localVal & ((uint32_t)0x10000000)) >>  28;
	*ghwparams1_27 = (localVal & ((uint32_t)0x08000000)) >>  27;
	*ghwparams1_26 = (localVal & ((uint32_t)0x04000000)) >>  26;
	*ghwparams1_25_24 = (localVal & ((uint32_t)0x03000000)) >>  24;
	*ghwparams1_23 = (localVal & ((uint32_t)0x00800000)) >>  23;
	*ghwparams1_22_21 = (localVal & ((uint32_t)0x00600000)) >>  21;
	*ghwparams1_20_15 = (localVal & ((uint32_t)0x001F8000)) >>  15;
	*ghwparams1_14_12 = (localVal & ((uint32_t)0x00007000)) >>  12;
	*ghwparams1_11_9 = (localVal & ((uint32_t)0x00000E00)) >>  9;
	*ghwparams1_8_6 = (localVal & ((uint32_t)0x000001C0)) >>  6;
	*ghwparams1_5_3 = (localVal & ((uint32_t)0x00000038)) >>  3;
	*ghwparams1_2_0 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_31_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_30_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_29_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_28_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_27_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_26_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_25_24_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x03000000)) >> 24);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_23_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_22_21_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00600000)) >> 21);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_20_15_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F8000)) >> 15);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_14_12_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_11_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000E00)) >> 9);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_8_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001C0)) >> 6);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_5_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE uint8_t usbc_ghwparams_1_ghwparams_1_2_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief GHWPARAMS_2 register definition
 *  Global Hardware Parameters Register 2  This register contains the hardware configuration options that you can select in the coreConsultant GUI.    For a description of each parameter, refer to the  Parameter Descriptions  chapter in the Databook. This information is also available in coreConsultant by right-clicking the parameter label and selecting  What s This  or by clicking the Help tab.    Note:   Some of the global hardware parameters are not currently modifiable in coreConsultant. These settings are in the   workspace /src/DWC_usb3_params.v file; you must not change them. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ghwparams2_31_0           0xcafecafe
 * </pre>
 */
#define USBC_GHWPARAMS_2_ADDR        (REG_USBC_BASE_ADDR+0x0000C148)
#define USBC_GHWPARAMS_2_OFFSET      0x0000C148
#define USBC_GHWPARAMS_2_INDEX       0x00003052
#define USBC_GHWPARAMS_2_RESET       0xCAFECAFE

__INLINE uint32_t  usbc_ghwparams_2_get(void)
{
	return REG_PL_RD(USBC_GHWPARAMS_2_ADDR);
}

// field definitions
#define USBC_GHWPARAMS_2_GHWPARAMS_2_31_0_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_GHWPARAMS_2_GHWPARAMS_2_31_0_LSB    0
#define USBC_GHWPARAMS_2_GHWPARAMS_2_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_GHWPARAMS_2_GHWPARAMS_2_31_0_RST    0xcafecafe

__INLINE uint32_t usbc_ghwparams_2_ghwparams_2_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_2_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief GHWPARAMS_3 register definition
 *  Global Hardware Parameters Register 3  This register contains the hardware configuration options that you can select in the coreConsultant GUI.    For a description of each parameter, refer to the  Parameter Descriptions  chapter in the Databook. This information is also available in coreConsultant by right-clicking the parameter label and selecting  What s This  or by clicking the Help tab.    Note:   Some of the global hardware parameters are not currently modifiable in coreConsultant. These settings are in the   workspace /src/DWC_usb3_params.v file; you must not change them. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    ghwparams3_31             0              
 *    30:23 ghwparams3_30_23          0x20
 *    22:18 ghwparams3_22_18          0x10
 *    17:12 ghwparams3_17_12          0x20
 *    11    ghwparams3_11             0              
 *    10    ghwparams3_10             0              
 *    09:08 ghwparams3_9_8            0x0
 *    07:06 ghwparams3_7_6            0x2
 *    05:04 ghwparams3_5_4            0x0
 *    03:02 ghwparams3_3_2            0x1
 *    01:00 ghwparams3_1_0            0x1
 * </pre>
 */
#define USBC_GHWPARAMS_3_ADDR        (REG_USBC_BASE_ADDR+0x0000C14C)
#define USBC_GHWPARAMS_3_OFFSET      0x0000C14C
#define USBC_GHWPARAMS_3_INDEX       0x00003053
#define USBC_GHWPARAMS_3_RESET       0x10420085

__INLINE uint32_t  usbc_ghwparams_3_get(void)
{
	return REG_PL_RD(USBC_GHWPARAMS_3_ADDR);
}

// field definitions
#define USBC_GHWPARAMS_3_GHWPARAMS_3_31_BIT    ((uint32_t)0x80000000)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_31_POS    31
#define USBC_GHWPARAMS_3_GHWPARAMS_3_30_23_MASK    ((uint32_t)0x7F800000)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_30_23_LSB    23
#define USBC_GHWPARAMS_3_GHWPARAMS_3_30_23_WIDTH    ((uint32_t)0x00000008)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_22_18_MASK    ((uint32_t)0x007C0000)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_22_18_LSB    18
#define USBC_GHWPARAMS_3_GHWPARAMS_3_22_18_WIDTH    ((uint32_t)0x00000005)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_17_12_MASK    ((uint32_t)0x0003F000)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_17_12_LSB    12
#define USBC_GHWPARAMS_3_GHWPARAMS_3_17_12_WIDTH    ((uint32_t)0x00000006)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_11_BIT    ((uint32_t)0x00000800)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_11_POS    11
#define USBC_GHWPARAMS_3_GHWPARAMS_3_10_BIT    ((uint32_t)0x00000400)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_10_POS    10
#define USBC_GHWPARAMS_3_GHWPARAMS_3_9_8_MASK    ((uint32_t)0x00000300)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_9_8_LSB    8
#define USBC_GHWPARAMS_3_GHWPARAMS_3_9_8_WIDTH    ((uint32_t)0x00000002)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_7_6_MASK    ((uint32_t)0x000000C0)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_7_6_LSB    6
#define USBC_GHWPARAMS_3_GHWPARAMS_3_7_6_WIDTH    ((uint32_t)0x00000002)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_5_4_MASK    ((uint32_t)0x00000030)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_5_4_LSB    4
#define USBC_GHWPARAMS_3_GHWPARAMS_3_5_4_WIDTH    ((uint32_t)0x00000002)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_3_2_MASK    ((uint32_t)0x0000000C)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_3_2_LSB    2
#define USBC_GHWPARAMS_3_GHWPARAMS_3_3_2_WIDTH    ((uint32_t)0x00000002)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_1_0_MASK    ((uint32_t)0x00000003)
#define USBC_GHWPARAMS_3_GHWPARAMS_3_1_0_LSB    0
#define USBC_GHWPARAMS_3_GHWPARAMS_3_1_0_WIDTH    ((uint32_t)0x00000002)

#define USBC_GHWPARAMS_3_GHWPARAMS_3_31_RST    0x0
#define USBC_GHWPARAMS_3_GHWPARAMS_3_30_23_RST    0x20
#define USBC_GHWPARAMS_3_GHWPARAMS_3_22_18_RST    0x10
#define USBC_GHWPARAMS_3_GHWPARAMS_3_17_12_RST    0x20
#define USBC_GHWPARAMS_3_GHWPARAMS_3_11_RST    0x0
#define USBC_GHWPARAMS_3_GHWPARAMS_3_10_RST    0x0
#define USBC_GHWPARAMS_3_GHWPARAMS_3_9_8_RST    0x0
#define USBC_GHWPARAMS_3_GHWPARAMS_3_7_6_RST    0x2
#define USBC_GHWPARAMS_3_GHWPARAMS_3_5_4_RST    0x0
#define USBC_GHWPARAMS_3_GHWPARAMS_3_3_2_RST    0x1
#define USBC_GHWPARAMS_3_GHWPARAMS_3_1_0_RST    0x1

__INLINE void usbc_ghwparams_3_unpack(uint8_t* ghwparams3_31, uint8_t* ghwparams3_30_23, uint8_t* ghwparams3_22_18, uint8_t* ghwparams3_17_12, uint8_t* ghwparams3_11, uint8_t* ghwparams3_10, uint8_t* ghwparams3_9_8, uint8_t* ghwparams3_7_6, uint8_t* ghwparams3_5_4, uint8_t* ghwparams3_3_2, uint8_t* ghwparams3_1_0)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_3_ADDR);

	*ghwparams3_31 = (localVal & ((uint32_t)0x80000000)) >>  31;
	*ghwparams3_30_23 = (localVal & ((uint32_t)0x7F800000)) >>  23;
	*ghwparams3_22_18 = (localVal & ((uint32_t)0x007C0000)) >>  18;
	*ghwparams3_17_12 = (localVal & ((uint32_t)0x0003F000)) >>  12;
	*ghwparams3_11 = (localVal & ((uint32_t)0x00000800)) >>  11;
	*ghwparams3_10 = (localVal & ((uint32_t)0x00000400)) >>  10;
	*ghwparams3_9_8 = (localVal & ((uint32_t)0x00000300)) >>  8;
	*ghwparams3_7_6 = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*ghwparams3_5_4 = (localVal & ((uint32_t)0x00000030)) >>  4;
	*ghwparams3_3_2 = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*ghwparams3_1_0 = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t usbc_ghwparams_3_ghwparams_3_31_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE uint8_t usbc_ghwparams_3_ghwparams_3_30_23_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F800000)) >> 23);
}
__INLINE uint8_t usbc_ghwparams_3_ghwparams_3_22_18_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x007C0000)) >> 18);
}
__INLINE uint8_t usbc_ghwparams_3_ghwparams_3_17_12_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0003F000)) >> 12);
}
__INLINE uint8_t usbc_ghwparams_3_ghwparams_3_11_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t usbc_ghwparams_3_ghwparams_3_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t usbc_ghwparams_3_ghwparams_3_9_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE uint8_t usbc_ghwparams_3_ghwparams_3_7_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE uint8_t usbc_ghwparams_3_ghwparams_3_5_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE uint8_t usbc_ghwparams_3_ghwparams_3_3_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE uint8_t usbc_ghwparams_3_ghwparams_3_1_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief GHWPARAMS_4 register definition
 *  Global Hardware Parameters Register 4  This register contains the hardware configuration options that you can select in the coreConsultant GUI.    For a description of each parameter, refer to the  Parameter Descriptions  chapter in the Databook. This information is also available in coreConsultant by right-clicking the parameter label and selecting  What s This  or by clicking the Help tab.    Note:   Some of the global hardware parameters are not currently modifiable in coreConsultant. These settings are in the   workspace /src/DWC_usb3_params.v file; you must not change them. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 ghwparams4_31_28          0x4
 *    27:24 ghwparams4_27_24          0x7
 *    23    ghwparams4_23             1              
 *    22    ghwparams4_22             0              
 *    21    ghwparams4_21             0              
 *    20:17 ghwparams4_20_17          0x1
 *    16:13 ghwparams4_16_13          0x1
 *    12    ghwparams4_12             0              
 *    11    ghwparams4_11             0              
 *    10:09 ghwparams4_10_9           0x0
 *    08:07 ghwparams4_8_7            0x0
 *    06    ghwparams4_6              0              
 *    05:00 ghwparams4_5_0            0x8
 * </pre>
 */
#define USBC_GHWPARAMS_4_ADDR        (REG_USBC_BASE_ADDR+0x0000C150)
#define USBC_GHWPARAMS_4_OFFSET      0x0000C150
#define USBC_GHWPARAMS_4_INDEX       0x00003054
#define USBC_GHWPARAMS_4_RESET       0x47822008

__INLINE uint32_t  usbc_ghwparams_4_get(void)
{
	return REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
}

// field definitions
#define USBC_GHWPARAMS_4_GHWPARAMS_4_31_28_MASK    ((uint32_t)0xF0000000)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_31_28_LSB    28
#define USBC_GHWPARAMS_4_GHWPARAMS_4_31_28_WIDTH    ((uint32_t)0x00000004)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_27_24_MASK    ((uint32_t)0x0F000000)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_27_24_LSB    24
#define USBC_GHWPARAMS_4_GHWPARAMS_4_27_24_WIDTH    ((uint32_t)0x00000004)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_23_BIT    ((uint32_t)0x00800000)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_23_POS    23
#define USBC_GHWPARAMS_4_GHWPARAMS_4_22_BIT    ((uint32_t)0x00400000)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_22_POS    22
#define USBC_GHWPARAMS_4_GHWPARAMS_4_21_BIT    ((uint32_t)0x00200000)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_21_POS    21
#define USBC_GHWPARAMS_4_GHWPARAMS_4_20_17_MASK    ((uint32_t)0x001E0000)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_20_17_LSB    17
#define USBC_GHWPARAMS_4_GHWPARAMS_4_20_17_WIDTH    ((uint32_t)0x00000004)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_16_13_MASK    ((uint32_t)0x0001E000)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_16_13_LSB    13
#define USBC_GHWPARAMS_4_GHWPARAMS_4_16_13_WIDTH    ((uint32_t)0x00000004)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_12_BIT    ((uint32_t)0x00001000)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_12_POS    12
#define USBC_GHWPARAMS_4_GHWPARAMS_4_11_BIT    ((uint32_t)0x00000800)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_11_POS    11
#define USBC_GHWPARAMS_4_GHWPARAMS_4_10_9_MASK    ((uint32_t)0x00000600)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_10_9_LSB    9
#define USBC_GHWPARAMS_4_GHWPARAMS_4_10_9_WIDTH    ((uint32_t)0x00000002)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_8_7_MASK    ((uint32_t)0x00000180)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_8_7_LSB    7
#define USBC_GHWPARAMS_4_GHWPARAMS_4_8_7_WIDTH    ((uint32_t)0x00000002)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_6_BIT    ((uint32_t)0x00000040)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_6_POS    6
#define USBC_GHWPARAMS_4_GHWPARAMS_4_5_0_MASK    ((uint32_t)0x0000003F)
#define USBC_GHWPARAMS_4_GHWPARAMS_4_5_0_LSB    0
#define USBC_GHWPARAMS_4_GHWPARAMS_4_5_0_WIDTH    ((uint32_t)0x00000006)

#define USBC_GHWPARAMS_4_GHWPARAMS_4_31_28_RST    0x4
#define USBC_GHWPARAMS_4_GHWPARAMS_4_27_24_RST    0x7
#define USBC_GHWPARAMS_4_GHWPARAMS_4_23_RST    0x1
#define USBC_GHWPARAMS_4_GHWPARAMS_4_22_RST    0x0
#define USBC_GHWPARAMS_4_GHWPARAMS_4_21_RST    0x0
#define USBC_GHWPARAMS_4_GHWPARAMS_4_20_17_RST    0x1
#define USBC_GHWPARAMS_4_GHWPARAMS_4_16_13_RST    0x1
#define USBC_GHWPARAMS_4_GHWPARAMS_4_12_RST    0x0
#define USBC_GHWPARAMS_4_GHWPARAMS_4_11_RST    0x0
#define USBC_GHWPARAMS_4_GHWPARAMS_4_10_9_RST    0x0
#define USBC_GHWPARAMS_4_GHWPARAMS_4_8_7_RST    0x0
#define USBC_GHWPARAMS_4_GHWPARAMS_4_6_RST    0x0
#define USBC_GHWPARAMS_4_GHWPARAMS_4_5_0_RST    0x8

__INLINE void usbc_ghwparams_4_unpack(uint8_t* ghwparams4_31_28, uint8_t* ghwparams4_27_24, uint8_t* ghwparams4_23, uint8_t* ghwparams4_22, uint8_t* ghwparams4_21, uint8_t* ghwparams4_20_17, uint8_t* ghwparams4_16_13, uint8_t* ghwparams4_12, uint8_t* ghwparams4_11, uint8_t* ghwparams4_10_9, uint8_t* ghwparams4_8_7, uint8_t* ghwparams4_6, uint8_t* ghwparams4_5_0)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);

	*ghwparams4_31_28 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*ghwparams4_27_24 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*ghwparams4_23 = (localVal & ((uint32_t)0x00800000)) >>  23;
	*ghwparams4_22 = (localVal & ((uint32_t)0x00400000)) >>  22;
	*ghwparams4_21 = (localVal & ((uint32_t)0x00200000)) >>  21;
	*ghwparams4_20_17 = (localVal & ((uint32_t)0x001E0000)) >>  17;
	*ghwparams4_16_13 = (localVal & ((uint32_t)0x0001E000)) >>  13;
	*ghwparams4_12 = (localVal & ((uint32_t)0x00001000)) >>  12;
	*ghwparams4_11 = (localVal & ((uint32_t)0x00000800)) >>  11;
	*ghwparams4_10_9 = (localVal & ((uint32_t)0x00000600)) >>  9;
	*ghwparams4_8_7 = (localVal & ((uint32_t)0x00000180)) >>  7;
	*ghwparams4_6 = (localVal & ((uint32_t)0x00000040)) >>  6;
	*ghwparams4_5_0 = (localVal & ((uint32_t)0x0000003F)) >>  0;
}

__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_31_28_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_27_24_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_23_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_22_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_21_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_20_17_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001E0000)) >> 17);
}
__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_16_13_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0001E000)) >> 13);
}
__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_12_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_11_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_10_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000600)) >> 9);
}
__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_8_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000180)) >> 7);
}
__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t usbc_ghwparams_4_ghwparams_4_5_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief GHWPARAMS_5 register definition
 *  Global Hardware Parameters Register 5  This register contains the hardware configuration options that you can select in the coreConsultant GUI.    For a description of each parameter, refer to the  Parameter Descriptions  chapter in the Databook. This information is also available in coreConsultant by right-clicking the parameter label and selecting  What s This  or by clicking the Help tab.    Note:   Some of the global hardware parameters are not currently modifiable in coreConsultant. These settings are in the   workspace /src/DWC_usb3_params.v file; you must not change them. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 ghwparams5_31_28          0x0
 *    27:22 ghwparams5_27_22          0x10
 *    21:16 ghwparams5_21_16          0x20
 *    15:10 ghwparams5_15_10          0x10
 *    09:04 ghwparams5_9_4            0x10
 *    03:00 ghwparams5_3_0            0x8
 * </pre>
 */
#define USBC_GHWPARAMS_5_ADDR        (REG_USBC_BASE_ADDR+0x0000C154)
#define USBC_GHWPARAMS_5_OFFSET      0x0000C154
#define USBC_GHWPARAMS_5_INDEX       0x00003055
#define USBC_GHWPARAMS_5_RESET       0x04204108

__INLINE uint32_t  usbc_ghwparams_5_get(void)
{
	return REG_PL_RD(USBC_GHWPARAMS_5_ADDR);
}

// field definitions
#define USBC_GHWPARAMS_5_GHWPARAMS_5_31_28_MASK    ((uint32_t)0xF0000000)
#define USBC_GHWPARAMS_5_GHWPARAMS_5_31_28_LSB    28
#define USBC_GHWPARAMS_5_GHWPARAMS_5_31_28_WIDTH    ((uint32_t)0x00000004)
#define USBC_GHWPARAMS_5_GHWPARAMS_5_27_22_MASK    ((uint32_t)0x0FC00000)
#define USBC_GHWPARAMS_5_GHWPARAMS_5_27_22_LSB    22
#define USBC_GHWPARAMS_5_GHWPARAMS_5_27_22_WIDTH    ((uint32_t)0x00000006)
#define USBC_GHWPARAMS_5_GHWPARAMS_5_21_16_MASK    ((uint32_t)0x003F0000)
#define USBC_GHWPARAMS_5_GHWPARAMS_5_21_16_LSB    16
#define USBC_GHWPARAMS_5_GHWPARAMS_5_21_16_WIDTH    ((uint32_t)0x00000006)
#define USBC_GHWPARAMS_5_GHWPARAMS_5_15_10_MASK    ((uint32_t)0x0000FC00)
#define USBC_GHWPARAMS_5_GHWPARAMS_5_15_10_LSB    10
#define USBC_GHWPARAMS_5_GHWPARAMS_5_15_10_WIDTH    ((uint32_t)0x00000006)
#define USBC_GHWPARAMS_5_GHWPARAMS_5_9_4_MASK    ((uint32_t)0x000003F0)
#define USBC_GHWPARAMS_5_GHWPARAMS_5_9_4_LSB    4
#define USBC_GHWPARAMS_5_GHWPARAMS_5_9_4_WIDTH    ((uint32_t)0x00000006)
#define USBC_GHWPARAMS_5_GHWPARAMS_5_3_0_MASK    ((uint32_t)0x0000000F)
#define USBC_GHWPARAMS_5_GHWPARAMS_5_3_0_LSB    0
#define USBC_GHWPARAMS_5_GHWPARAMS_5_3_0_WIDTH    ((uint32_t)0x00000004)

#define USBC_GHWPARAMS_5_GHWPARAMS_5_31_28_RST    0x0
#define USBC_GHWPARAMS_5_GHWPARAMS_5_27_22_RST    0x10
#define USBC_GHWPARAMS_5_GHWPARAMS_5_21_16_RST    0x20
#define USBC_GHWPARAMS_5_GHWPARAMS_5_15_10_RST    0x10
#define USBC_GHWPARAMS_5_GHWPARAMS_5_9_4_RST    0x10
#define USBC_GHWPARAMS_5_GHWPARAMS_5_3_0_RST    0x8

__INLINE void usbc_ghwparams_5_unpack(uint8_t* ghwparams5_31_28, uint8_t* ghwparams5_27_22, uint8_t* ghwparams5_21_16, uint8_t* ghwparams5_15_10, uint8_t* ghwparams5_9_4, uint8_t* ghwparams5_3_0)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_5_ADDR);

	*ghwparams5_31_28 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*ghwparams5_27_22 = (localVal & ((uint32_t)0x0FC00000)) >>  22;
	*ghwparams5_21_16 = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ghwparams5_15_10 = (localVal & ((uint32_t)0x0000FC00)) >>  10;
	*ghwparams5_9_4 = (localVal & ((uint32_t)0x000003F0)) >>  4;
	*ghwparams5_3_0 = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t usbc_ghwparams_5_ghwparams_5_31_28_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE uint8_t usbc_ghwparams_5_ghwparams_5_27_22_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0FC00000)) >> 22);
}
__INLINE uint8_t usbc_ghwparams_5_ghwparams_5_21_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE uint8_t usbc_ghwparams_5_ghwparams_5_15_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FC00)) >> 10);
}
__INLINE uint8_t usbc_ghwparams_5_ghwparams_5_9_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003F0)) >> 4);
}
__INLINE uint8_t usbc_ghwparams_5_ghwparams_5_3_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief GHWPARAMS_6 register definition
 *  Global Hardware Parameters Register 6  This register contains the hardware configuration options that you can select in the coreConsultant GUI.    For a description of each parameter, refer to the  Parameter Descriptions  chapter in the Databook. This information is also available in coreConsultant by right-clicking the parameter label and selecting  What s This  or by clicking the Help tab.    Note:   Some of the global hardware parameters are not currently modifiable in coreConsultant. These settings are in the   workspace /src/DWC_usb3_params.v file; you must not change them. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 ghwparams6_31_16          0x78c
 *    15    Bus_Fltrs_Support         0              
 *    14    BCSupport                 0              
 *    13    OTG_SS_Support            0              
 *    12    ADPSupport                0              
 *    11    HNPSupport                0              
 *    10    SRPSupport                0              
 *    09:08 ghwparams6_9_8            0x0
 *    07    ghwparams6_7              0              
 *    06    ghwparams6_6              0              
 *    05:00 ghwparams6_5_0            0x20
 * </pre>
 */
#define USBC_GHWPARAMS_6_ADDR        (REG_USBC_BASE_ADDR+0x0000C158)
#define USBC_GHWPARAMS_6_OFFSET      0x0000C158
#define USBC_GHWPARAMS_6_INDEX       0x00003056
#define USBC_GHWPARAMS_6_RESET       0x078C0020

__INLINE uint32_t  usbc_ghwparams_6_get(void)
{
	return REG_PL_RD(USBC_GHWPARAMS_6_ADDR);
}

// field definitions
#define USBC_GHWPARAMS_6_GHWPARAMS_6_31_16_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GHWPARAMS_6_GHWPARAMS_6_31_16_LSB    16
#define USBC_GHWPARAMS_6_GHWPARAMS_6_31_16_WIDTH    ((uint32_t)0x00000010)
#define USBC_GHWPARAMS_6_BUS_FLTRS_SUPPORT_BIT    ((uint32_t)0x00008000)
#define USBC_GHWPARAMS_6_BUS_FLTRS_SUPPORT_POS    15
#define USBC_GHWPARAMS_6_BCSUPPORT_BIT      ((uint32_t)0x00004000)
#define USBC_GHWPARAMS_6_BCSUPPORT_POS      14
#define USBC_GHWPARAMS_6_OTG_SS_SUPPORT_BIT    ((uint32_t)0x00002000)
#define USBC_GHWPARAMS_6_OTG_SS_SUPPORT_POS    13
#define USBC_GHWPARAMS_6_ADPSUPPORT_BIT     ((uint32_t)0x00001000)
#define USBC_GHWPARAMS_6_ADPSUPPORT_POS     12
#define USBC_GHWPARAMS_6_HNPSUPPORT_BIT     ((uint32_t)0x00000800)
#define USBC_GHWPARAMS_6_HNPSUPPORT_POS     11
#define USBC_GHWPARAMS_6_SRPSUPPORT_BIT     ((uint32_t)0x00000400)
#define USBC_GHWPARAMS_6_SRPSUPPORT_POS     10
#define USBC_GHWPARAMS_6_GHWPARAMS_6_9_8_MASK    ((uint32_t)0x00000300)
#define USBC_GHWPARAMS_6_GHWPARAMS_6_9_8_LSB    8
#define USBC_GHWPARAMS_6_GHWPARAMS_6_9_8_WIDTH    ((uint32_t)0x00000002)
#define USBC_GHWPARAMS_6_GHWPARAMS_6_7_BIT    ((uint32_t)0x00000080)
#define USBC_GHWPARAMS_6_GHWPARAMS_6_7_POS    7
#define USBC_GHWPARAMS_6_GHWPARAMS_6_6_BIT    ((uint32_t)0x00000040)
#define USBC_GHWPARAMS_6_GHWPARAMS_6_6_POS    6
#define USBC_GHWPARAMS_6_GHWPARAMS_6_5_0_MASK    ((uint32_t)0x0000003F)
#define USBC_GHWPARAMS_6_GHWPARAMS_6_5_0_LSB    0
#define USBC_GHWPARAMS_6_GHWPARAMS_6_5_0_WIDTH    ((uint32_t)0x00000006)

#define USBC_GHWPARAMS_6_GHWPARAMS_6_31_16_RST    0x78c
#define USBC_GHWPARAMS_6_BUS_FLTRS_SUPPORT_RST    0x0
#define USBC_GHWPARAMS_6_BCSUPPORT_RST      0x0
#define USBC_GHWPARAMS_6_OTG_SS_SUPPORT_RST    0x0
#define USBC_GHWPARAMS_6_ADPSUPPORT_RST     0x0
#define USBC_GHWPARAMS_6_HNPSUPPORT_RST     0x0
#define USBC_GHWPARAMS_6_SRPSUPPORT_RST     0x0
#define USBC_GHWPARAMS_6_GHWPARAMS_6_9_8_RST    0x0
#define USBC_GHWPARAMS_6_GHWPARAMS_6_7_RST    0x0
#define USBC_GHWPARAMS_6_GHWPARAMS_6_6_RST    0x0
#define USBC_GHWPARAMS_6_GHWPARAMS_6_5_0_RST    0x20

__INLINE void usbc_ghwparams_6_unpack(uint16_t* ghwparams6_31_16, uint8_t* bus_fltrs_support, uint8_t* bcsupport, uint8_t* otg_ss_support, uint8_t* adpsupport, uint8_t* hnpsupport, uint8_t* srpsupport, uint8_t* ghwparams6_9_8, uint8_t* ghwparams6_7, uint8_t* ghwparams6_6, uint8_t* ghwparams6_5_0)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_6_ADDR);

	*ghwparams6_31_16 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*bus_fltrs_support = (localVal & ((uint32_t)0x00008000)) >>  15;
	*bcsupport = (localVal & ((uint32_t)0x00004000)) >>  14;
	*otg_ss_support = (localVal & ((uint32_t)0x00002000)) >>  13;
	*adpsupport = (localVal & ((uint32_t)0x00001000)) >>  12;
	*hnpsupport = (localVal & ((uint32_t)0x00000800)) >>  11;
	*srpsupport = (localVal & ((uint32_t)0x00000400)) >>  10;
	*ghwparams6_9_8 = (localVal & ((uint32_t)0x00000300)) >>  8;
	*ghwparams6_7 = (localVal & ((uint32_t)0x00000080)) >>  7;
	*ghwparams6_6 = (localVal & ((uint32_t)0x00000040)) >>  6;
	*ghwparams6_5_0 = (localVal & ((uint32_t)0x0000003F)) >>  0;
}

__INLINE uint16_t usbc_ghwparams_6_ghwparams_6_31_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_6_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint8_t usbc_ghwparams_6_bus_fltrs_support_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t usbc_ghwparams_6_bcsupport_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t usbc_ghwparams_6_otg_ss_support_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t usbc_ghwparams_6_adpsupport_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t usbc_ghwparams_6_hnpsupport_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t usbc_ghwparams_6_srpsupport_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t usbc_ghwparams_6_ghwparams_6_9_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE uint8_t usbc_ghwparams_6_ghwparams_6_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t usbc_ghwparams_6_ghwparams_6_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t usbc_ghwparams_6_ghwparams_6_5_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief GHWPARAMS_7 register definition
 *  Global Hardware Parameters Register 7  This register contains the hardware configuration options that you can select in the coreConsultant GUI.    For a description of each parameter, refer to the  Parameter Descriptions  chapter in the Databook. This information is also available in coreConsultant by right-clicking the parameter label and selecting  What s This  or by clicking the Help tab.    Note:   Some of the global hardware parameters are not currently modifiable in coreConsultant. These settings are in the   workspace /src/DWC_usb3_params.v file; you must not change them. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 ghwparams7_31_16          0x30a
 *    15:00 ghwparams7_15_0           0x26b7
 * </pre>
 */
#define USBC_GHWPARAMS_7_ADDR        (REG_USBC_BASE_ADDR+0x0000C15C)
#define USBC_GHWPARAMS_7_OFFSET      0x0000C15C
#define USBC_GHWPARAMS_7_INDEX       0x00003057
#define USBC_GHWPARAMS_7_RESET       0x030A26B7

__INLINE uint32_t  usbc_ghwparams_7_get(void)
{
	return REG_PL_RD(USBC_GHWPARAMS_7_ADDR);
}

// field definitions
#define USBC_GHWPARAMS_7_GHWPARAMS_7_31_16_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GHWPARAMS_7_GHWPARAMS_7_31_16_LSB    16
#define USBC_GHWPARAMS_7_GHWPARAMS_7_31_16_WIDTH    ((uint32_t)0x00000010)
#define USBC_GHWPARAMS_7_GHWPARAMS_7_15_0_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GHWPARAMS_7_GHWPARAMS_7_15_0_LSB    0
#define USBC_GHWPARAMS_7_GHWPARAMS_7_15_0_WIDTH    ((uint32_t)0x00000010)

#define USBC_GHWPARAMS_7_GHWPARAMS_7_31_16_RST    0x30a
#define USBC_GHWPARAMS_7_GHWPARAMS_7_15_0_RST    0x26b7

__INLINE void usbc_ghwparams_7_unpack(uint16_t* ghwparams7_31_16, uint16_t* ghwparams7_15_0)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_7_ADDR);

	*ghwparams7_31_16 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ghwparams7_15_0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_ghwparams_7_ghwparams_7_31_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_7_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t usbc_ghwparams_7_ghwparams_7_15_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_7_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief GDBGFIFOSPACE register definition
 *  Global Debug Queue/FIFO Space Available Register  Bit Bash test should not be done on this debug register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SPACE_AVAILABLE           0x82
 *    15:09 reserved_15_9             0x0
 *    08:00 FIFO_QUEUE_SELECT         0x0
 * </pre>
 */
#define USBC_GDBGFIFOSPACE_ADDR        (REG_USBC_BASE_ADDR+0x0000C160)
#define USBC_GDBGFIFOSPACE_OFFSET      0x0000C160
#define USBC_GDBGFIFOSPACE_INDEX       0x00003058
#define USBC_GDBGFIFOSPACE_RESET       0x00820000

__INLINE uint32_t  usbc_gdbgfifospace_get(void)
{
	return REG_PL_RD(USBC_GDBGFIFOSPACE_ADDR);
}

__INLINE void usbc_gdbgfifospace_set(uint32_t value)
{
	REG_PL_WR(USBC_GDBGFIFOSPACE_ADDR, value);
}

// field definitions
#define USBC_GDBGFIFOSPACE_SPACE_AVAILABLE_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GDBGFIFOSPACE_SPACE_AVAILABLE_LSB    16
#define USBC_GDBGFIFOSPACE_SPACE_AVAILABLE_WIDTH    ((uint32_t)0x00000010)
#define USBC_GDBGFIFOSPACE_RESERVED_15_9_MASK    ((uint32_t)0x0000FE00)
#define USBC_GDBGFIFOSPACE_RESERVED_15_9_LSB    9
#define USBC_GDBGFIFOSPACE_RESERVED_15_9_WIDTH    ((uint32_t)0x00000007)
#define USBC_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_MASK    ((uint32_t)0x000001FF)
#define USBC_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_LSB    0
#define USBC_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_WIDTH    ((uint32_t)0x00000009)

#define USBC_GDBGFIFOSPACE_SPACE_AVAILABLE_RST    0x82
#define USBC_GDBGFIFOSPACE_RESERVED_15_9_RST    0x0
#define USBC_GDBGFIFOSPACE_FIFO_QUEUE_SELECT_RST    0x0

__INLINE void usbc_gdbgfifospace_pack(uint16_t space_available, uint8_t reserved_15_9, uint16_t fifo_queue_select)
{
	ASSERT_ERR((((uint32_t)space_available << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_15_9 << 9) & ~((uint32_t)0x0000FE00)) == 0);
	ASSERT_ERR((((uint32_t)fifo_queue_select << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(USBC_GDBGFIFOSPACE_ADDR,  ((uint32_t)space_available << 16) |((uint32_t)reserved_15_9 << 9) |((uint32_t)fifo_queue_select << 0));
}

__INLINE void usbc_gdbgfifospace_unpack(uint16_t* space_available, uint8_t* reserved_15_9, uint16_t* fifo_queue_select)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGFIFOSPACE_ADDR);

	*space_available = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*reserved_15_9 = (localVal & ((uint32_t)0x0000FE00)) >>  9;
	*fifo_queue_select = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint16_t usbc_gdbgfifospace_space_available_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGFIFOSPACE_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint8_t usbc_gdbgfifospace_reserved_15_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGFIFOSPACE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FE00)) >> 9);
}
__INLINE uint16_t usbc_gdbgfifospace_fifo_queue_select_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGFIFOSPACE_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void usbc_gdbgfifospace_fifo_queue_select_setf(uint16_t fifoqueueselect)
{
	ASSERT_ERR((((uint32_t)fifoqueueselect << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(USBC_GDBGFIFOSPACE_ADDR, (REG_PL_RD(USBC_GDBGFIFOSPACE_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)fifoqueueselect <<0));
}

/**
 * @brief GDBGLTSSM register definition
 *  Global Debug LTSSM Register  In multi-port host configuration, the port-number is defined by Port-Select[3:0] field in the GDBGFIFOSPACE register.    Note:   - GDBGLTSSM register is not applicable for USB 2.0-only mode.  - Bit Bash test should not be done on this debug register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    reserved_31_31            0              
 *    30    Rx_Elecidle               0              
 *    29    X3_XS_SWAPPING            0              
 *    28    X3_DS_HOST_SHUTDOWN       0              
 *    27    PRTDIRECTION              0              
 *    26    LTDBTIMEOUT               0              
 *    25:22 LTDBLINKSTATE             0x0
 *    21:18 LTDBSUBSTATE              0x0
 *    17    ELASTICBUFFERMODE         0              
 *    16    TXELECLDLE                1              
 *    15    RXPOLARITY                0              
 *    14    Tx_Det_Rx_Loopback        0              
 *    13:11 LTDBPhy_Cmd_State         0x0
 *    10:09 POWERDOWN                 0x2
 *    08    RXEQTRAIN                 0              
 *    07:06 TXDEEMPHASIS              0x1
 *    05:03 LTDBClk_State             0x0
 *    02    TXSWING                   0              
 *    01    RXTERMINATION             0              
 *    00    TXONESZEROS               0              
 * </pre>
 */
#define USBC_GDBGLTSSM_ADDR        (REG_USBC_BASE_ADDR+0x0000C164)
#define USBC_GDBGLTSSM_OFFSET      0x0000C164
#define USBC_GDBGLTSSM_INDEX       0x00003059
#define USBC_GDBGLTSSM_RESET       0x00010440

__INLINE uint32_t  usbc_gdbgltssm_get(void)
{
	return REG_PL_RD(USBC_GDBGLTSSM_ADDR);
}

// field definitions
#define USBC_GDBGLTSSM_RESERVED_31_31_BIT    ((uint32_t)0x80000000)
#define USBC_GDBGLTSSM_RESERVED_31_31_POS    31
#define USBC_GDBGLTSSM_RX_ELECIDLE_BIT      ((uint32_t)0x40000000)
#define USBC_GDBGLTSSM_RX_ELECIDLE_POS      30
#define USBC_GDBGLTSSM_X_3_XS_SWAPPING_BIT    ((uint32_t)0x20000000)
#define USBC_GDBGLTSSM_X_3_XS_SWAPPING_POS    29
#define USBC_GDBGLTSSM_X_3_DS_HOST_SHUTDOWN_BIT    ((uint32_t)0x10000000)
#define USBC_GDBGLTSSM_X_3_DS_HOST_SHUTDOWN_POS    28
#define USBC_GDBGLTSSM_PRTDIRECTION_BIT     ((uint32_t)0x08000000)
#define USBC_GDBGLTSSM_PRTDIRECTION_POS     27
#define USBC_GDBGLTSSM_LTDBTIMEOUT_BIT      ((uint32_t)0x04000000)
#define USBC_GDBGLTSSM_LTDBTIMEOUT_POS      26
#define USBC_GDBGLTSSM_LTDBLINKSTATE_MASK    ((uint32_t)0x03C00000)
#define USBC_GDBGLTSSM_LTDBLINKSTATE_LSB    22
#define USBC_GDBGLTSSM_LTDBLINKSTATE_WIDTH    ((uint32_t)0x00000004)
#define USBC_GDBGLTSSM_LTDBSUBSTATE_MASK    ((uint32_t)0x003C0000)
#define USBC_GDBGLTSSM_LTDBSUBSTATE_LSB     18
#define USBC_GDBGLTSSM_LTDBSUBSTATE_WIDTH    ((uint32_t)0x00000004)
#define USBC_GDBGLTSSM_ELASTICBUFFERMODE_BIT    ((uint32_t)0x00020000)
#define USBC_GDBGLTSSM_ELASTICBUFFERMODE_POS    17
#define USBC_GDBGLTSSM_TXELECLDLE_BIT       ((uint32_t)0x00010000)
#define USBC_GDBGLTSSM_TXELECLDLE_POS       16
#define USBC_GDBGLTSSM_RXPOLARITY_BIT       ((uint32_t)0x00008000)
#define USBC_GDBGLTSSM_RXPOLARITY_POS       15
#define USBC_GDBGLTSSM_TX_DET_RX_LOOPBACK_BIT    ((uint32_t)0x00004000)
#define USBC_GDBGLTSSM_TX_DET_RX_LOOPBACK_POS    14
#define USBC_GDBGLTSSM_LTDBPHY_CMD_STATE_MASK    ((uint32_t)0x00003800)
#define USBC_GDBGLTSSM_LTDBPHY_CMD_STATE_LSB    11
#define USBC_GDBGLTSSM_LTDBPHY_CMD_STATE_WIDTH    ((uint32_t)0x00000003)
#define USBC_GDBGLTSSM_POWERDOWN_MASK       ((uint32_t)0x00000600)
#define USBC_GDBGLTSSM_POWERDOWN_LSB        9
#define USBC_GDBGLTSSM_POWERDOWN_WIDTH      ((uint32_t)0x00000002)
#define USBC_GDBGLTSSM_RXEQTRAIN_BIT        ((uint32_t)0x00000100)
#define USBC_GDBGLTSSM_RXEQTRAIN_POS        8
#define USBC_GDBGLTSSM_TXDEEMPHASIS_MASK    ((uint32_t)0x000000C0)
#define USBC_GDBGLTSSM_TXDEEMPHASIS_LSB     6
#define USBC_GDBGLTSSM_TXDEEMPHASIS_WIDTH    ((uint32_t)0x00000002)
#define USBC_GDBGLTSSM_LTDBCLK_STATE_MASK    ((uint32_t)0x00000038)
#define USBC_GDBGLTSSM_LTDBCLK_STATE_LSB    3
#define USBC_GDBGLTSSM_LTDBCLK_STATE_WIDTH    ((uint32_t)0x00000003)
#define USBC_GDBGLTSSM_TXSWING_BIT          ((uint32_t)0x00000004)
#define USBC_GDBGLTSSM_TXSWING_POS          2
#define USBC_GDBGLTSSM_RXTERMINATION_BIT    ((uint32_t)0x00000002)
#define USBC_GDBGLTSSM_RXTERMINATION_POS    1
#define USBC_GDBGLTSSM_TXONESZEROS_BIT      ((uint32_t)0x00000001)
#define USBC_GDBGLTSSM_TXONESZEROS_POS      0

#define USBC_GDBGLTSSM_RESERVED_31_31_RST    0x0
#define USBC_GDBGLTSSM_RX_ELECIDLE_RST      0x0
#define USBC_GDBGLTSSM_X_3_XS_SWAPPING_RST    0x0
#define USBC_GDBGLTSSM_X_3_DS_HOST_SHUTDOWN_RST    0x0
#define USBC_GDBGLTSSM_PRTDIRECTION_RST     0x0
#define USBC_GDBGLTSSM_LTDBTIMEOUT_RST      0x0
#define USBC_GDBGLTSSM_LTDBLINKSTATE_RST    0x0
#define USBC_GDBGLTSSM_LTDBSUBSTATE_RST     0x0
#define USBC_GDBGLTSSM_ELASTICBUFFERMODE_RST    0x0
#define USBC_GDBGLTSSM_TXELECLDLE_RST       0x1
#define USBC_GDBGLTSSM_RXPOLARITY_RST       0x0
#define USBC_GDBGLTSSM_TX_DET_RX_LOOPBACK_RST    0x0
#define USBC_GDBGLTSSM_LTDBPHY_CMD_STATE_RST    0x0
#define USBC_GDBGLTSSM_POWERDOWN_RST        0x2
#define USBC_GDBGLTSSM_RXEQTRAIN_RST        0x0
#define USBC_GDBGLTSSM_TXDEEMPHASIS_RST     0x1
#define USBC_GDBGLTSSM_LTDBCLK_STATE_RST    0x0
#define USBC_GDBGLTSSM_TXSWING_RST          0x0
#define USBC_GDBGLTSSM_RXTERMINATION_RST    0x0
#define USBC_GDBGLTSSM_TXONESZEROS_RST      0x0

__INLINE void usbc_gdbgltssm_unpack(uint8_t* reserved_31_31, uint8_t* rx_elecidle, uint8_t* x3_xs_swapping, uint8_t* x3_ds_host_shutdown, uint8_t* prtdirection, uint8_t* ltdbtimeout, uint8_t* ltdblinkstate, uint8_t* ltdbsubstate, uint8_t* elasticbuffermode, uint8_t* txelecldle, uint8_t* rxpolarity, uint8_t* tx_det_rx_loopback, uint8_t* ltdbphy_cmd_state, uint8_t* powerdown, uint8_t* rxeqtrain, uint8_t* txdeemphasis, uint8_t* ltdbclk_state, uint8_t* txswing, uint8_t* rxtermination, uint8_t* txoneszeros)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);

	*reserved_31_31 = (localVal & ((uint32_t)0x80000000)) >>  31;
	*rx_elecidle = (localVal & ((uint32_t)0x40000000)) >>  30;
	*x3_xs_swapping = (localVal & ((uint32_t)0x20000000)) >>  29;
	*x3_ds_host_shutdown = (localVal & ((uint32_t)0x10000000)) >>  28;
	*prtdirection = (localVal & ((uint32_t)0x08000000)) >>  27;
	*ltdbtimeout = (localVal & ((uint32_t)0x04000000)) >>  26;
	*ltdblinkstate = (localVal & ((uint32_t)0x03C00000)) >>  22;
	*ltdbsubstate = (localVal & ((uint32_t)0x003C0000)) >>  18;
	*elasticbuffermode = (localVal & ((uint32_t)0x00020000)) >>  17;
	*txelecldle = (localVal & ((uint32_t)0x00010000)) >>  16;
	*rxpolarity = (localVal & ((uint32_t)0x00008000)) >>  15;
	*tx_det_rx_loopback = (localVal & ((uint32_t)0x00004000)) >>  14;
	*ltdbphy_cmd_state = (localVal & ((uint32_t)0x00003800)) >>  11;
	*powerdown = (localVal & ((uint32_t)0x00000600)) >>  9;
	*rxeqtrain = (localVal & ((uint32_t)0x00000100)) >>  8;
	*txdeemphasis = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*ltdbclk_state = (localVal & ((uint32_t)0x00000038)) >>  3;
	*txswing = (localVal & ((uint32_t)0x00000004)) >>  2;
	*rxtermination = (localVal & ((uint32_t)0x00000002)) >>  1;
	*txoneszeros = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t usbc_gdbgltssm_reserved_31_31_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE uint8_t usbc_gdbgltssm_rx_elecidle_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE uint8_t usbc_gdbgltssm_x_3_xs_swapping_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE uint8_t usbc_gdbgltssm_x_3_ds_host_shutdown_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE uint8_t usbc_gdbgltssm_prtdirection_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE uint8_t usbc_gdbgltssm_ltdbtimeout_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE uint8_t usbc_gdbgltssm_ltdblinkstate_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x03C00000)) >> 22);
}
__INLINE uint8_t usbc_gdbgltssm_ltdbsubstate_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003C0000)) >> 18);
}
__INLINE uint8_t usbc_gdbgltssm_elasticbuffermode_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE uint8_t usbc_gdbgltssm_txelecldle_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t usbc_gdbgltssm_rxpolarity_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t usbc_gdbgltssm_tx_det_rx_loopback_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t usbc_gdbgltssm_ltdbphy_cmd_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003800)) >> 11);
}
__INLINE uint8_t usbc_gdbgltssm_powerdown_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000600)) >> 9);
}
__INLINE uint8_t usbc_gdbgltssm_rxeqtrain_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t usbc_gdbgltssm_txdeemphasis_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE uint8_t usbc_gdbgltssm_ltdbclk_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE uint8_t usbc_gdbgltssm_txswing_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t usbc_gdbgltssm_rxtermination_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t usbc_gdbgltssm_txoneszeros_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLTSSM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief GDBGLNMCC register definition
 *  Global Debug LNMCC Register  Bit Bash test should not be done on this debug register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:09 reserved_31_9             0x0
 *    08:00 LNMCC_BERC                0x0
 * </pre>
 */
#define USBC_GDBGLNMCC_ADDR        (REG_USBC_BASE_ADDR+0x0000C168)
#define USBC_GDBGLNMCC_OFFSET      0x0000C168
#define USBC_GDBGLNMCC_INDEX       0x0000305A
#define USBC_GDBGLNMCC_RESET       0x00000000

__INLINE uint32_t  usbc_gdbglnmcc_get(void)
{
	return REG_PL_RD(USBC_GDBGLNMCC_ADDR);
}

// field definitions
#define USBC_GDBGLNMCC_RESERVED_31_9_MASK    ((uint32_t)0xFFFFFE00)
#define USBC_GDBGLNMCC_RESERVED_31_9_LSB    9
#define USBC_GDBGLNMCC_RESERVED_31_9_WIDTH    ((uint32_t)0x00000017)
#define USBC_GDBGLNMCC_LNMCC_BERC_MASK      ((uint32_t)0x000001FF)
#define USBC_GDBGLNMCC_LNMCC_BERC_LSB       0
#define USBC_GDBGLNMCC_LNMCC_BERC_WIDTH     ((uint32_t)0x00000009)

#define USBC_GDBGLNMCC_RESERVED_31_9_RST    0x0
#define USBC_GDBGLNMCC_LNMCC_BERC_RST       0x0

__INLINE void usbc_gdbglnmcc_unpack(uint32_t* reserved_31_9, uint16_t* lnmcc_berc)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLNMCC_ADDR);

	*reserved_31_9 = (localVal & ((uint32_t)0xFFFFFE00)) >>  9;
	*lnmcc_berc = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint32_t usbc_gdbglnmcc_reserved_31_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLNMCC_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFFE00)) >> 9);
}
__INLINE uint16_t usbc_gdbglnmcc_lnmcc_berc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLNMCC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}

/**
 * @brief GDBGBMU register definition
 *  Global Debug BMU Register  Bit Bash test should not be done on this debug register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:08 BMU_BCU                   0x0
 *    07:04 BMU_DCU                   0x0
 *    03:00 BMU_CCU                   0x0
 * </pre>
 */
#define USBC_GDBGBMU_ADDR        (REG_USBC_BASE_ADDR+0x0000C16C)
#define USBC_GDBGBMU_OFFSET      0x0000C16C
#define USBC_GDBGBMU_INDEX       0x0000305B
#define USBC_GDBGBMU_RESET       0x00000000

__INLINE uint32_t  usbc_gdbgbmu_get(void)
{
	return REG_PL_RD(USBC_GDBGBMU_ADDR);
}

// field definitions
#define USBC_GDBGBMU_BMU_BCU_MASK           ((uint32_t)0xFFFFFF00)
#define USBC_GDBGBMU_BMU_BCU_LSB            8
#define USBC_GDBGBMU_BMU_BCU_WIDTH          ((uint32_t)0x00000018)
#define USBC_GDBGBMU_BMU_DCU_MASK           ((uint32_t)0x000000F0)
#define USBC_GDBGBMU_BMU_DCU_LSB            4
#define USBC_GDBGBMU_BMU_DCU_WIDTH          ((uint32_t)0x00000004)
#define USBC_GDBGBMU_BMU_CCU_MASK           ((uint32_t)0x0000000F)
#define USBC_GDBGBMU_BMU_CCU_LSB            0
#define USBC_GDBGBMU_BMU_CCU_WIDTH          ((uint32_t)0x00000004)

#define USBC_GDBGBMU_BMU_BCU_RST            0x0
#define USBC_GDBGBMU_BMU_DCU_RST            0x0
#define USBC_GDBGBMU_BMU_CCU_RST            0x0

__INLINE void usbc_gdbgbmu_unpack(uint32_t* bmu_bcu, uint8_t* bmu_dcu, uint8_t* bmu_ccu)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGBMU_ADDR);

	*bmu_bcu = (localVal & ((uint32_t)0xFFFFFF00)) >>  8;
	*bmu_dcu = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*bmu_ccu = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint32_t usbc_gdbgbmu_bmu_bcu_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGBMU_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFFF00)) >> 8);
}
__INLINE uint8_t usbc_gdbgbmu_bmu_dcu_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGBMU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_gdbgbmu_bmu_ccu_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGBMU_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief GDBGLSPMUX_HST register definition
 *  Global Debug LSP MUX Register - Host  This register is for internal use only.  If DWC_USB3_PRESERVE_LOGIC_ANALYZER_SELECT is enabled during controller configuration, then the default values readout is X (Undefined).  Bit Bash test should not be done on this debug register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 reserved_31_24            0x0
 *    23:16 logic_analyzer_trace      0x3f
 *    15:14 reserved_15_14            0x0
 *    13:00 HOSTSELECT                0x0
 * </pre>
 */
#define USBC_GDBGLSPMUX_HST_ADDR        (REG_USBC_BASE_ADDR+0x0000C170)
#define USBC_GDBGLSPMUX_HST_OFFSET      0x0000C170
#define USBC_GDBGLSPMUX_HST_INDEX       0x0000305C
#define USBC_GDBGLSPMUX_HST_RESET       0x003F0000

__INLINE uint32_t  usbc_gdbglspmux_hst_get(void)
{
	return REG_PL_RD(USBC_GDBGLSPMUX_HST_ADDR);
}

__INLINE void usbc_gdbglspmux_hst_set(uint32_t value)
{
	REG_PL_WR(USBC_GDBGLSPMUX_HST_ADDR, value);
}

// field definitions
#define USBC_GDBGLSPMUX_HST_RESERVED_31_24_MASK    ((uint32_t)0xFF000000)
#define USBC_GDBGLSPMUX_HST_RESERVED_31_24_LSB    24
#define USBC_GDBGLSPMUX_HST_RESERVED_31_24_WIDTH    ((uint32_t)0x00000008)
#define USBC_GDBGLSPMUX_HST_LOGIC_ANALYZER_TRACE_MASK    ((uint32_t)0x00FF0000)
#define USBC_GDBGLSPMUX_HST_LOGIC_ANALYZER_TRACE_LSB    16
#define USBC_GDBGLSPMUX_HST_LOGIC_ANALYZER_TRACE_WIDTH    ((uint32_t)0x00000008)
#define USBC_GDBGLSPMUX_HST_RESERVED_15_14_MASK    ((uint32_t)0x0000C000)
#define USBC_GDBGLSPMUX_HST_RESERVED_15_14_LSB    14
#define USBC_GDBGLSPMUX_HST_RESERVED_15_14_WIDTH    ((uint32_t)0x00000002)
#define USBC_GDBGLSPMUX_HST_HOSTSELECT_MASK    ((uint32_t)0x00003FFF)
#define USBC_GDBGLSPMUX_HST_HOSTSELECT_LSB    0
#define USBC_GDBGLSPMUX_HST_HOSTSELECT_WIDTH    ((uint32_t)0x0000000E)

#define USBC_GDBGLSPMUX_HST_RESERVED_31_24_RST    0x0
#define USBC_GDBGLSPMUX_HST_LOGIC_ANALYZER_TRACE_RST    0x3f
#define USBC_GDBGLSPMUX_HST_RESERVED_15_14_RST    0x0
#define USBC_GDBGLSPMUX_HST_HOSTSELECT_RST    0x0

__INLINE void usbc_gdbglspmux_hst_pack(uint8_t reserved_31_24, uint8_t logic_analyzer_trace, uint8_t reserved_15_14, uint16_t hostselect)
{
	ASSERT_ERR((((uint32_t)reserved_31_24 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)logic_analyzer_trace << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_15_14 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)hostselect << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(USBC_GDBGLSPMUX_HST_ADDR,  ((uint32_t)reserved_31_24 << 24) |((uint32_t)logic_analyzer_trace << 16) |((uint32_t)reserved_15_14 << 14) |((uint32_t)hostselect << 0));
}

__INLINE void usbc_gdbglspmux_hst_unpack(uint8_t* reserved_31_24, uint8_t* logic_analyzer_trace, uint8_t* reserved_15_14, uint16_t* hostselect)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLSPMUX_HST_ADDR);

	*reserved_31_24 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*logic_analyzer_trace = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*reserved_15_14 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*hostselect = (localVal & ((uint32_t)0x00003FFF)) >>  0;
}

__INLINE uint8_t usbc_gdbglspmux_hst_reserved_31_24_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLSPMUX_HST_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint8_t usbc_gdbglspmux_hst_logic_analyzer_trace_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLSPMUX_HST_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void usbc_gdbglspmux_hst_logic_analyzer_trace_setf(uint8_t logicanalyzertrace)
{
	ASSERT_ERR((((uint32_t)logicanalyzertrace << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(USBC_GDBGLSPMUX_HST_ADDR, (REG_PL_RD(USBC_GDBGLSPMUX_HST_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)logicanalyzertrace <<16));
}
__INLINE uint8_t usbc_gdbglspmux_hst_reserved_15_14_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLSPMUX_HST_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE uint16_t usbc_gdbglspmux_hst_hostselect_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLSPMUX_HST_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00003FFF)) >> 0);
}
__INLINE void usbc_gdbglspmux_hst_hostselect_setf(uint16_t hostselect)
{
	ASSERT_ERR((((uint32_t)hostselect << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(USBC_GDBGLSPMUX_HST_ADDR, (REG_PL_RD(USBC_GDBGLSPMUX_HST_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)hostselect <<0));
}

/**
 * @brief GDBGLSP register definition
 *  Global Debug LSP Register  This register is for internal debug purposes only.  This register is for internal use only.  If DWC_USB3_PRESERVE_LOGIC_ANALYZER_SELECT is enabled during controller configuration, then the default values readout is X (Undefined).  Bit Bash test should not be done on this debug register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LSPDEBUG                  0x0
 * </pre>
 */
#define USBC_GDBGLSP_ADDR        (REG_USBC_BASE_ADDR+0x0000C174)
#define USBC_GDBGLSP_OFFSET      0x0000C174
#define USBC_GDBGLSP_INDEX       0x0000305D
#define USBC_GDBGLSP_RESET       0x00000000

__INLINE uint32_t  usbc_gdbglsp_get(void)
{
	return REG_PL_RD(USBC_GDBGLSP_ADDR);
}

// field definitions
#define USBC_GDBGLSP_LSPDEBUG_MASK          ((uint32_t)0xFFFFFFFF)
#define USBC_GDBGLSP_LSPDEBUG_LSB           0
#define USBC_GDBGLSP_LSPDEBUG_WIDTH         ((uint32_t)0x00000020)

#define USBC_GDBGLSP_LSPDEBUG_RST           0x0

__INLINE uint32_t usbc_gdbglsp_lspdebug_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGLSP_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief GDBGEPINFO_0 register definition
 *  Global Debug Endpoint Information Register 0  This register is for internal use only.  If DWC_USB3_PRESERVE_LOGIC_ANALYZER_SELECT is enabled during controller configuration, then the default values readout is X (Undefined).  Bit Bash test should not be done on this debug register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EPDEBUG                   0x0
 * </pre>
 */
#define USBC_GDBGEPINFO_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C178)
#define USBC_GDBGEPINFO_0_OFFSET      0x0000C178
#define USBC_GDBGEPINFO_0_INDEX       0x0000305E
#define USBC_GDBGEPINFO_0_RESET       0x00000000

__INLINE uint32_t  usbc_gdbgepinfo_0_get(void)
{
	return REG_PL_RD(USBC_GDBGEPINFO_0_ADDR);
}

// field definitions
#define USBC_GDBGEPINFO_0_EPDEBUG_MASK      ((uint32_t)0xFFFFFFFF)
#define USBC_GDBGEPINFO_0_EPDEBUG_LSB       0
#define USBC_GDBGEPINFO_0_EPDEBUG_WIDTH     ((uint32_t)0x00000020)

#define USBC_GDBGEPINFO_0_EPDEBUG_RST       0x0

__INLINE uint32_t usbc_gdbgepinfo_0_epdebug_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGEPINFO_0_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief GDBGEPINFO_1 register definition
 *  Global Debug Endpoint Information Register 1  This register is for internal use only.  If DWC_USB3_PRESERVE_LOGIC_ANALYZER_SELECT is enabled during controller configuration, then the default values readout is X (Undefined).  Bit Bash test should not be done on this debug register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EPDEBUG                   0x800000
 * </pre>
 */
#define USBC_GDBGEPINFO_1_ADDR        (REG_USBC_BASE_ADDR+0x0000C17C)
#define USBC_GDBGEPINFO_1_OFFSET      0x0000C17C
#define USBC_GDBGEPINFO_1_INDEX       0x0000305F
#define USBC_GDBGEPINFO_1_RESET       0x00800000

__INLINE uint32_t  usbc_gdbgepinfo_1_get(void)
{
	return REG_PL_RD(USBC_GDBGEPINFO_1_ADDR);
}

// field definitions
#define USBC_GDBGEPINFO_1_EPDEBUG_MASK      ((uint32_t)0xFFFFFFFF)
#define USBC_GDBGEPINFO_1_EPDEBUG_LSB       0
#define USBC_GDBGEPINFO_1_EPDEBUG_WIDTH     ((uint32_t)0x00000020)

#define USBC_GDBGEPINFO_1_EPDEBUG_RST       0x800000

__INLINE uint32_t usbc_gdbgepinfo_1_epdebug_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GDBGEPINFO_1_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief GPRTBIMAP_HSLO register definition
 *  Global High-Speed Port to Bus Instance Mapping Register - Low  This is an alternate register for the GPRTBIMAP_HS register.   - Register fields are read-write with respect to number of port instantiated. writeAsRead constraint is added to limit side effects for unused fields.   Note: For reset values, refer to the corresponding values in the GPRTBIMAP_HS register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 BINUM8                    0x0
 *    27:24 BINUM7                    0x0
 *    23:20 BINUM6                    0x0
 *    19:16 BINUM5                    0x0
 *    15:12 BINUM4                    0x0
 *    11:08 BINUM3                    0x0
 *    07:04 BINUM2                    0x0
 *    03:00 BINUM1                    0x0
 * </pre>
 */
#define USBC_GPRTBIMAP_HSLO_ADDR        (REG_USBC_BASE_ADDR+0x0000C180)
#define USBC_GPRTBIMAP_HSLO_OFFSET      0x0000C180
#define USBC_GPRTBIMAP_HSLO_INDEX       0x00003060
#define USBC_GPRTBIMAP_HSLO_RESET       0x00000000

__INLINE uint32_t  usbc_gprtbimap_hslo_get(void)
{
	return REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR);
}

__INLINE void usbc_gprtbimap_hslo_set(uint32_t value)
{
	REG_PL_WR(USBC_GPRTBIMAP_HSLO_ADDR, value);
}

// field definitions
#define USBC_GPRTBIMAP_HSLO_BINUM_8_MASK    ((uint32_t)0xF0000000)
#define USBC_GPRTBIMAP_HSLO_BINUM_8_LSB     28
#define USBC_GPRTBIMAP_HSLO_BINUM_8_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSLO_BINUM_7_MASK    ((uint32_t)0x0F000000)
#define USBC_GPRTBIMAP_HSLO_BINUM_7_LSB     24
#define USBC_GPRTBIMAP_HSLO_BINUM_7_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSLO_BINUM_6_MASK    ((uint32_t)0x00F00000)
#define USBC_GPRTBIMAP_HSLO_BINUM_6_LSB     20
#define USBC_GPRTBIMAP_HSLO_BINUM_6_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSLO_BINUM_5_MASK    ((uint32_t)0x000F0000)
#define USBC_GPRTBIMAP_HSLO_BINUM_5_LSB     16
#define USBC_GPRTBIMAP_HSLO_BINUM_5_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSLO_BINUM_4_MASK    ((uint32_t)0x0000F000)
#define USBC_GPRTBIMAP_HSLO_BINUM_4_LSB     12
#define USBC_GPRTBIMAP_HSLO_BINUM_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSLO_BINUM_3_MASK    ((uint32_t)0x00000F00)
#define USBC_GPRTBIMAP_HSLO_BINUM_3_LSB     8
#define USBC_GPRTBIMAP_HSLO_BINUM_3_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSLO_BINUM_2_MASK    ((uint32_t)0x000000F0)
#define USBC_GPRTBIMAP_HSLO_BINUM_2_LSB     4
#define USBC_GPRTBIMAP_HSLO_BINUM_2_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSLO_BINUM_1_MASK    ((uint32_t)0x0000000F)
#define USBC_GPRTBIMAP_HSLO_BINUM_1_LSB     0
#define USBC_GPRTBIMAP_HSLO_BINUM_1_WIDTH    ((uint32_t)0x00000004)

#define USBC_GPRTBIMAP_HSLO_BINUM_8_RST     0x0
#define USBC_GPRTBIMAP_HSLO_BINUM_7_RST     0x0
#define USBC_GPRTBIMAP_HSLO_BINUM_6_RST     0x0
#define USBC_GPRTBIMAP_HSLO_BINUM_5_RST     0x0
#define USBC_GPRTBIMAP_HSLO_BINUM_4_RST     0x0
#define USBC_GPRTBIMAP_HSLO_BINUM_3_RST     0x0
#define USBC_GPRTBIMAP_HSLO_BINUM_2_RST     0x0
#define USBC_GPRTBIMAP_HSLO_BINUM_1_RST     0x0

__INLINE void usbc_gprtbimap_hslo_pack(uint8_t binum8, uint8_t binum7, uint8_t binum6, uint8_t binum5, uint8_t binum4, uint8_t binum3, uint8_t binum2, uint8_t binum1)
{
	ASSERT_ERR((((uint32_t)binum8 << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)binum7 << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)binum6 << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)binum5 << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)binum4 << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)binum3 << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)binum2 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)binum1 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSLO_ADDR,  ((uint32_t)binum8 << 28) |((uint32_t)binum7 << 24) |((uint32_t)binum6 << 20) |((uint32_t)binum5 << 16) |((uint32_t)binum4 << 12) |((uint32_t)binum3 << 8) |((uint32_t)binum2 << 4) |((uint32_t)binum1 << 0));
}

__INLINE void usbc_gprtbimap_hslo_unpack(uint8_t* binum8, uint8_t* binum7, uint8_t* binum6, uint8_t* binum5, uint8_t* binum4, uint8_t* binum3, uint8_t* binum2, uint8_t* binum1)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR);

	*binum8 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*binum7 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*binum6 = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*binum5 = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*binum4 = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*binum3 = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*binum2 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*binum1 = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t usbc_gprtbimap_hslo_binum_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void usbc_gprtbimap_hslo_binum_8_setf(uint8_t binum8)
{
	ASSERT_ERR((((uint32_t)binum8 << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)binum8 <<28));
}
__INLINE uint8_t usbc_gprtbimap_hslo_binum_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void usbc_gprtbimap_hslo_binum_7_setf(uint8_t binum7)
{
	ASSERT_ERR((((uint32_t)binum7 << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)binum7 <<24));
}
__INLINE uint8_t usbc_gprtbimap_hslo_binum_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void usbc_gprtbimap_hslo_binum_6_setf(uint8_t binum6)
{
	ASSERT_ERR((((uint32_t)binum6 << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)binum6 <<20));
}
__INLINE uint8_t usbc_gprtbimap_hslo_binum_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void usbc_gprtbimap_hslo_binum_5_setf(uint8_t binum5)
{
	ASSERT_ERR((((uint32_t)binum5 << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)binum5 <<16));
}
__INLINE uint8_t usbc_gprtbimap_hslo_binum_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_gprtbimap_hslo_binum_4_setf(uint8_t binum4)
{
	ASSERT_ERR((((uint32_t)binum4 << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)binum4 <<12));
}
__INLINE uint8_t usbc_gprtbimap_hslo_binum_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void usbc_gprtbimap_hslo_binum_3_setf(uint8_t binum3)
{
	ASSERT_ERR((((uint32_t)binum3 << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)binum3 <<8));
}
__INLINE uint8_t usbc_gprtbimap_hslo_binum_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void usbc_gprtbimap_hslo_binum_2_setf(uint8_t binum2)
{
	ASSERT_ERR((((uint32_t)binum2 << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)binum2 <<4));
}
__INLINE uint8_t usbc_gprtbimap_hslo_binum_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_gprtbimap_hslo_binum_1_setf(uint8_t binum1)
{
	ASSERT_ERR((((uint32_t)binum1 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSLO_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)binum1 <<0));
}

/**
 * @brief GPRTBIMAP_HSHI register definition
 *  Global High-Speed Port to Bus Instance Mapping Register - High  This is an alternate register for the GPRTBIMAP_HS register.   - Register fields are read-write with respect to number of port instantiated. writeAsRead constraint is added to limit side effects for unused fields.   Note: For reset values, refer to the corresponding values in the GPRTBIMAP register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 reserved_31_28            0x0
 *    27:24 BINUM15                   0x0
 *    23:20 BINUM14                   0x0
 *    19:16 BINUM13                   0x0
 *    15:12 BINUM12                   0x0
 *    11:08 BINUM11                   0x0
 *    07:04 BINUM10                   0x0
 *    03:00 BINUM9                    0x0
 * </pre>
 */
#define USBC_GPRTBIMAP_HSHI_ADDR        (REG_USBC_BASE_ADDR+0x0000C184)
#define USBC_GPRTBIMAP_HSHI_OFFSET      0x0000C184
#define USBC_GPRTBIMAP_HSHI_INDEX       0x00003061
#define USBC_GPRTBIMAP_HSHI_RESET       0x00000000

__INLINE uint32_t  usbc_gprtbimap_hshi_get(void)
{
	return REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR);
}

__INLINE void usbc_gprtbimap_hshi_set(uint32_t value)
{
	REG_PL_WR(USBC_GPRTBIMAP_HSHI_ADDR, value);
}

// field definitions
#define USBC_GPRTBIMAP_HSHI_RESERVED_31_28_MASK    ((uint32_t)0xF0000000)
#define USBC_GPRTBIMAP_HSHI_RESERVED_31_28_LSB    28
#define USBC_GPRTBIMAP_HSHI_RESERVED_31_28_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSHI_BINUM_15_MASK    ((uint32_t)0x0F000000)
#define USBC_GPRTBIMAP_HSHI_BINUM_15_LSB    24
#define USBC_GPRTBIMAP_HSHI_BINUM_15_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSHI_BINUM_14_MASK    ((uint32_t)0x00F00000)
#define USBC_GPRTBIMAP_HSHI_BINUM_14_LSB    20
#define USBC_GPRTBIMAP_HSHI_BINUM_14_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSHI_BINUM_13_MASK    ((uint32_t)0x000F0000)
#define USBC_GPRTBIMAP_HSHI_BINUM_13_LSB    16
#define USBC_GPRTBIMAP_HSHI_BINUM_13_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSHI_BINUM_12_MASK    ((uint32_t)0x0000F000)
#define USBC_GPRTBIMAP_HSHI_BINUM_12_LSB    12
#define USBC_GPRTBIMAP_HSHI_BINUM_12_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSHI_BINUM_11_MASK    ((uint32_t)0x00000F00)
#define USBC_GPRTBIMAP_HSHI_BINUM_11_LSB    8
#define USBC_GPRTBIMAP_HSHI_BINUM_11_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSHI_BINUM_10_MASK    ((uint32_t)0x000000F0)
#define USBC_GPRTBIMAP_HSHI_BINUM_10_LSB    4
#define USBC_GPRTBIMAP_HSHI_BINUM_10_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_HSHI_BINUM_9_MASK    ((uint32_t)0x0000000F)
#define USBC_GPRTBIMAP_HSHI_BINUM_9_LSB     0
#define USBC_GPRTBIMAP_HSHI_BINUM_9_WIDTH    ((uint32_t)0x00000004)

#define USBC_GPRTBIMAP_HSHI_RESERVED_31_28_RST    0x0
#define USBC_GPRTBIMAP_HSHI_BINUM_15_RST    0x0
#define USBC_GPRTBIMAP_HSHI_BINUM_14_RST    0x0
#define USBC_GPRTBIMAP_HSHI_BINUM_13_RST    0x0
#define USBC_GPRTBIMAP_HSHI_BINUM_12_RST    0x0
#define USBC_GPRTBIMAP_HSHI_BINUM_11_RST    0x0
#define USBC_GPRTBIMAP_HSHI_BINUM_10_RST    0x0
#define USBC_GPRTBIMAP_HSHI_BINUM_9_RST     0x0

__INLINE void usbc_gprtbimap_hshi_pack(uint8_t reserved_31_28, uint8_t binum15, uint8_t binum14, uint8_t binum13, uint8_t binum12, uint8_t binum11, uint8_t binum10, uint8_t binum9)
{
	ASSERT_ERR((((uint32_t)reserved_31_28 << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)binum15 << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)binum14 << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)binum13 << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)binum12 << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)binum11 << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)binum10 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)binum9 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSHI_ADDR,  ((uint32_t)reserved_31_28 << 28) |((uint32_t)binum15 << 24) |((uint32_t)binum14 << 20) |((uint32_t)binum13 << 16) |((uint32_t)binum12 << 12) |((uint32_t)binum11 << 8) |((uint32_t)binum10 << 4) |((uint32_t)binum9 << 0));
}

__INLINE void usbc_gprtbimap_hshi_unpack(uint8_t* reserved_31_28, uint8_t* binum15, uint8_t* binum14, uint8_t* binum13, uint8_t* binum12, uint8_t* binum11, uint8_t* binum10, uint8_t* binum9)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR);

	*reserved_31_28 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*binum15 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*binum14 = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*binum13 = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*binum12 = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*binum11 = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*binum10 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*binum9 = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t usbc_gprtbimap_hshi_reserved_31_28_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE uint8_t usbc_gprtbimap_hshi_binum_15_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void usbc_gprtbimap_hshi_binum_15_setf(uint8_t binum15)
{
	ASSERT_ERR((((uint32_t)binum15 << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)binum15 <<24));
}
__INLINE uint8_t usbc_gprtbimap_hshi_binum_14_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void usbc_gprtbimap_hshi_binum_14_setf(uint8_t binum14)
{
	ASSERT_ERR((((uint32_t)binum14 << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)binum14 <<20));
}
__INLINE uint8_t usbc_gprtbimap_hshi_binum_13_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void usbc_gprtbimap_hshi_binum_13_setf(uint8_t binum13)
{
	ASSERT_ERR((((uint32_t)binum13 << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)binum13 <<16));
}
__INLINE uint8_t usbc_gprtbimap_hshi_binum_12_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_gprtbimap_hshi_binum_12_setf(uint8_t binum12)
{
	ASSERT_ERR((((uint32_t)binum12 << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)binum12 <<12));
}
__INLINE uint8_t usbc_gprtbimap_hshi_binum_11_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void usbc_gprtbimap_hshi_binum_11_setf(uint8_t binum11)
{
	ASSERT_ERR((((uint32_t)binum11 << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)binum11 <<8));
}
__INLINE uint8_t usbc_gprtbimap_hshi_binum_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void usbc_gprtbimap_hshi_binum_10_setf(uint8_t binum10)
{
	ASSERT_ERR((((uint32_t)binum10 << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)binum10 <<4));
}
__INLINE uint8_t usbc_gprtbimap_hshi_binum_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_gprtbimap_hshi_binum_9_setf(uint8_t binum9)
{
	ASSERT_ERR((((uint32_t)binum9 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_HSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_HSHI_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)binum9 <<0));
}

/**
 * @brief GPRTBIMAP_FSLO register definition
 *  Global Full-Speed Port to Bus Instance Mapping Register - Low  This is an alternate register for the GPRTBIMAP_FS register.   - Register fields are read-write with respect to number of port instantiated. writeAsRead constraint is added to limit side effects for unused fields.   Note: For reset values, refer to the corresponding values in the GPRTBIMAP_FS register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 BINUM8                    0x0
 *    27:24 BINUM7                    0x0
 *    23:20 BINUM6                    0x0
 *    19:16 BINUM5                    0x0
 *    15:12 BINUM4                    0x0
 *    11:08 BINUM3                    0x0
 *    07:04 BINUM2                    0x0
 *    03:00 BINUM1                    0x0
 * </pre>
 */
#define USBC_GPRTBIMAP_FSLO_ADDR        (REG_USBC_BASE_ADDR+0x0000C188)
#define USBC_GPRTBIMAP_FSLO_OFFSET      0x0000C188
#define USBC_GPRTBIMAP_FSLO_INDEX       0x00003062
#define USBC_GPRTBIMAP_FSLO_RESET       0x00000000

__INLINE uint32_t  usbc_gprtbimap_fslo_get(void)
{
	return REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR);
}

__INLINE void usbc_gprtbimap_fslo_set(uint32_t value)
{
	REG_PL_WR(USBC_GPRTBIMAP_FSLO_ADDR, value);
}

// field definitions
#define USBC_GPRTBIMAP_FSLO_BINUM_8_MASK    ((uint32_t)0xF0000000)
#define USBC_GPRTBIMAP_FSLO_BINUM_8_LSB     28
#define USBC_GPRTBIMAP_FSLO_BINUM_8_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSLO_BINUM_7_MASK    ((uint32_t)0x0F000000)
#define USBC_GPRTBIMAP_FSLO_BINUM_7_LSB     24
#define USBC_GPRTBIMAP_FSLO_BINUM_7_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSLO_BINUM_6_MASK    ((uint32_t)0x00F00000)
#define USBC_GPRTBIMAP_FSLO_BINUM_6_LSB     20
#define USBC_GPRTBIMAP_FSLO_BINUM_6_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSLO_BINUM_5_MASK    ((uint32_t)0x000F0000)
#define USBC_GPRTBIMAP_FSLO_BINUM_5_LSB     16
#define USBC_GPRTBIMAP_FSLO_BINUM_5_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSLO_BINUM_4_MASK    ((uint32_t)0x0000F000)
#define USBC_GPRTBIMAP_FSLO_BINUM_4_LSB     12
#define USBC_GPRTBIMAP_FSLO_BINUM_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSLO_BINUM_3_MASK    ((uint32_t)0x00000F00)
#define USBC_GPRTBIMAP_FSLO_BINUM_3_LSB     8
#define USBC_GPRTBIMAP_FSLO_BINUM_3_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSLO_BINUM_2_MASK    ((uint32_t)0x000000F0)
#define USBC_GPRTBIMAP_FSLO_BINUM_2_LSB     4
#define USBC_GPRTBIMAP_FSLO_BINUM_2_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSLO_BINUM_1_MASK    ((uint32_t)0x0000000F)
#define USBC_GPRTBIMAP_FSLO_BINUM_1_LSB     0
#define USBC_GPRTBIMAP_FSLO_BINUM_1_WIDTH    ((uint32_t)0x00000004)

#define USBC_GPRTBIMAP_FSLO_BINUM_8_RST     0x0
#define USBC_GPRTBIMAP_FSLO_BINUM_7_RST     0x0
#define USBC_GPRTBIMAP_FSLO_BINUM_6_RST     0x0
#define USBC_GPRTBIMAP_FSLO_BINUM_5_RST     0x0
#define USBC_GPRTBIMAP_FSLO_BINUM_4_RST     0x0
#define USBC_GPRTBIMAP_FSLO_BINUM_3_RST     0x0
#define USBC_GPRTBIMAP_FSLO_BINUM_2_RST     0x0
#define USBC_GPRTBIMAP_FSLO_BINUM_1_RST     0x0

__INLINE void usbc_gprtbimap_fslo_pack(uint8_t binum8, uint8_t binum7, uint8_t binum6, uint8_t binum5, uint8_t binum4, uint8_t binum3, uint8_t binum2, uint8_t binum1)
{
	ASSERT_ERR((((uint32_t)binum8 << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)binum7 << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)binum6 << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)binum5 << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)binum4 << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)binum3 << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)binum2 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)binum1 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSLO_ADDR,  ((uint32_t)binum8 << 28) |((uint32_t)binum7 << 24) |((uint32_t)binum6 << 20) |((uint32_t)binum5 << 16) |((uint32_t)binum4 << 12) |((uint32_t)binum3 << 8) |((uint32_t)binum2 << 4) |((uint32_t)binum1 << 0));
}

__INLINE void usbc_gprtbimap_fslo_unpack(uint8_t* binum8, uint8_t* binum7, uint8_t* binum6, uint8_t* binum5, uint8_t* binum4, uint8_t* binum3, uint8_t* binum2, uint8_t* binum1)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR);

	*binum8 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*binum7 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*binum6 = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*binum5 = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*binum4 = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*binum3 = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*binum2 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*binum1 = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t usbc_gprtbimap_fslo_binum_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void usbc_gprtbimap_fslo_binum_8_setf(uint8_t binum8)
{
	ASSERT_ERR((((uint32_t)binum8 << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)binum8 <<28));
}
__INLINE uint8_t usbc_gprtbimap_fslo_binum_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void usbc_gprtbimap_fslo_binum_7_setf(uint8_t binum7)
{
	ASSERT_ERR((((uint32_t)binum7 << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)binum7 <<24));
}
__INLINE uint8_t usbc_gprtbimap_fslo_binum_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void usbc_gprtbimap_fslo_binum_6_setf(uint8_t binum6)
{
	ASSERT_ERR((((uint32_t)binum6 << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)binum6 <<20));
}
__INLINE uint8_t usbc_gprtbimap_fslo_binum_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void usbc_gprtbimap_fslo_binum_5_setf(uint8_t binum5)
{
	ASSERT_ERR((((uint32_t)binum5 << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)binum5 <<16));
}
__INLINE uint8_t usbc_gprtbimap_fslo_binum_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_gprtbimap_fslo_binum_4_setf(uint8_t binum4)
{
	ASSERT_ERR((((uint32_t)binum4 << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)binum4 <<12));
}
__INLINE uint8_t usbc_gprtbimap_fslo_binum_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void usbc_gprtbimap_fslo_binum_3_setf(uint8_t binum3)
{
	ASSERT_ERR((((uint32_t)binum3 << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)binum3 <<8));
}
__INLINE uint8_t usbc_gprtbimap_fslo_binum_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void usbc_gprtbimap_fslo_binum_2_setf(uint8_t binum2)
{
	ASSERT_ERR((((uint32_t)binum2 << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)binum2 <<4));
}
__INLINE uint8_t usbc_gprtbimap_fslo_binum_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_gprtbimap_fslo_binum_1_setf(uint8_t binum1)
{
	ASSERT_ERR((((uint32_t)binum1 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSLO_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSLO_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)binum1 <<0));
}

/**
 * @brief GPRTBIMAP_FSHI register definition
 *  Global Full-Speed Port to Bus Instance Mapping Register - High  This is an alternate register for the GPRTBIMAP_FS register.   - Register fields are read-write with respect to number of port instantiated. writeAsRead constraint is added to limit side effects for unused fields.   Note: For reset values, refer to the corresponding values in the GPRTBIMAP_FS register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 reserved_31_28            0x0
 *    27:24 BINUM15                   0x0
 *    23:20 BINUM14                   0x0
 *    19:16 BINUM13                   0x0
 *    15:12 BINUM12                   0x0
 *    11:08 BINUM11                   0x0
 *    07:04 BINUM10                   0x0
 *    03:00 BINUM9                    0x0
 * </pre>
 */
#define USBC_GPRTBIMAP_FSHI_ADDR        (REG_USBC_BASE_ADDR+0x0000C18C)
#define USBC_GPRTBIMAP_FSHI_OFFSET      0x0000C18C
#define USBC_GPRTBIMAP_FSHI_INDEX       0x00003063
#define USBC_GPRTBIMAP_FSHI_RESET       0x00000000

__INLINE uint32_t  usbc_gprtbimap_fshi_get(void)
{
	return REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR);
}

__INLINE void usbc_gprtbimap_fshi_set(uint32_t value)
{
	REG_PL_WR(USBC_GPRTBIMAP_FSHI_ADDR, value);
}

// field definitions
#define USBC_GPRTBIMAP_FSHI_RESERVED_31_28_MASK    ((uint32_t)0xF0000000)
#define USBC_GPRTBIMAP_FSHI_RESERVED_31_28_LSB    28
#define USBC_GPRTBIMAP_FSHI_RESERVED_31_28_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSHI_BINUM_15_MASK    ((uint32_t)0x0F000000)
#define USBC_GPRTBIMAP_FSHI_BINUM_15_LSB    24
#define USBC_GPRTBIMAP_FSHI_BINUM_15_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSHI_BINUM_14_MASK    ((uint32_t)0x00F00000)
#define USBC_GPRTBIMAP_FSHI_BINUM_14_LSB    20
#define USBC_GPRTBIMAP_FSHI_BINUM_14_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSHI_BINUM_13_MASK    ((uint32_t)0x000F0000)
#define USBC_GPRTBIMAP_FSHI_BINUM_13_LSB    16
#define USBC_GPRTBIMAP_FSHI_BINUM_13_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSHI_BINUM_12_MASK    ((uint32_t)0x0000F000)
#define USBC_GPRTBIMAP_FSHI_BINUM_12_LSB    12
#define USBC_GPRTBIMAP_FSHI_BINUM_12_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSHI_BINUM_11_MASK    ((uint32_t)0x00000F00)
#define USBC_GPRTBIMAP_FSHI_BINUM_11_LSB    8
#define USBC_GPRTBIMAP_FSHI_BINUM_11_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSHI_BINUM_10_MASK    ((uint32_t)0x000000F0)
#define USBC_GPRTBIMAP_FSHI_BINUM_10_LSB    4
#define USBC_GPRTBIMAP_FSHI_BINUM_10_WIDTH    ((uint32_t)0x00000004)
#define USBC_GPRTBIMAP_FSHI_BINUM_9_MASK    ((uint32_t)0x0000000F)
#define USBC_GPRTBIMAP_FSHI_BINUM_9_LSB     0
#define USBC_GPRTBIMAP_FSHI_BINUM_9_WIDTH    ((uint32_t)0x00000004)

#define USBC_GPRTBIMAP_FSHI_RESERVED_31_28_RST    0x0
#define USBC_GPRTBIMAP_FSHI_BINUM_15_RST    0x0
#define USBC_GPRTBIMAP_FSHI_BINUM_14_RST    0x0
#define USBC_GPRTBIMAP_FSHI_BINUM_13_RST    0x0
#define USBC_GPRTBIMAP_FSHI_BINUM_12_RST    0x0
#define USBC_GPRTBIMAP_FSHI_BINUM_11_RST    0x0
#define USBC_GPRTBIMAP_FSHI_BINUM_10_RST    0x0
#define USBC_GPRTBIMAP_FSHI_BINUM_9_RST     0x0

__INLINE void usbc_gprtbimap_fshi_pack(uint8_t reserved_31_28, uint8_t binum15, uint8_t binum14, uint8_t binum13, uint8_t binum12, uint8_t binum11, uint8_t binum10, uint8_t binum9)
{
	ASSERT_ERR((((uint32_t)reserved_31_28 << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)binum15 << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)binum14 << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)binum13 << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)binum12 << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)binum11 << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)binum10 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)binum9 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSHI_ADDR,  ((uint32_t)reserved_31_28 << 28) |((uint32_t)binum15 << 24) |((uint32_t)binum14 << 20) |((uint32_t)binum13 << 16) |((uint32_t)binum12 << 12) |((uint32_t)binum11 << 8) |((uint32_t)binum10 << 4) |((uint32_t)binum9 << 0));
}

__INLINE void usbc_gprtbimap_fshi_unpack(uint8_t* reserved_31_28, uint8_t* binum15, uint8_t* binum14, uint8_t* binum13, uint8_t* binum12, uint8_t* binum11, uint8_t* binum10, uint8_t* binum9)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR);

	*reserved_31_28 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*binum15 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*binum14 = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*binum13 = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*binum12 = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*binum11 = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*binum10 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*binum9 = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t usbc_gprtbimap_fshi_reserved_31_28_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE uint8_t usbc_gprtbimap_fshi_binum_15_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void usbc_gprtbimap_fshi_binum_15_setf(uint8_t binum15)
{
	ASSERT_ERR((((uint32_t)binum15 << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)binum15 <<24));
}
__INLINE uint8_t usbc_gprtbimap_fshi_binum_14_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void usbc_gprtbimap_fshi_binum_14_setf(uint8_t binum14)
{
	ASSERT_ERR((((uint32_t)binum14 << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)binum14 <<20));
}
__INLINE uint8_t usbc_gprtbimap_fshi_binum_13_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void usbc_gprtbimap_fshi_binum_13_setf(uint8_t binum13)
{
	ASSERT_ERR((((uint32_t)binum13 << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)binum13 <<16));
}
__INLINE uint8_t usbc_gprtbimap_fshi_binum_12_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_gprtbimap_fshi_binum_12_setf(uint8_t binum12)
{
	ASSERT_ERR((((uint32_t)binum12 << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)binum12 <<12));
}
__INLINE uint8_t usbc_gprtbimap_fshi_binum_11_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void usbc_gprtbimap_fshi_binum_11_setf(uint8_t binum11)
{
	ASSERT_ERR((((uint32_t)binum11 << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)binum11 <<8));
}
__INLINE uint8_t usbc_gprtbimap_fshi_binum_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void usbc_gprtbimap_fshi_binum_10_setf(uint8_t binum10)
{
	ASSERT_ERR((((uint32_t)binum10 << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)binum10 <<4));
}
__INLINE uint8_t usbc_gprtbimap_fshi_binum_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_gprtbimap_fshi_binum_9_setf(uint8_t binum9)
{
	ASSERT_ERR((((uint32_t)binum9 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GPRTBIMAP_FSHI_ADDR, (REG_PL_RD(USBC_GPRTBIMAP_FSHI_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)binum9 <<0));
}

/**
 * @brief RESERVED_94 register definition
 *  Future Reserved Register at offset 0x94 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RESERVED_94_ADDR        (REG_USBC_BASE_ADDR+0x0000C194)
#define USBC_RESERVED_94_OFFSET      0x0000C194
#define USBC_RESERVED_94_INDEX       0x00003065
#define USBC_RESERVED_94_RESET       0x00000000

__INLINE uint32_t  usbc_reserved_94_get(void)
{
	return REG_PL_RD(USBC_RESERVED_94_ADDR);
}

// field definitions
#define USBC_RESERVED_94_RESERVED_31_0_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_RESERVED_94_RESERVED_31_0_LSB    0
#define USBC_RESERVED_94_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RESERVED_94_RESERVED_31_0_RST    0x0

__INLINE uint32_t usbc_reserved_94_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RESERVED_94_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RESERVED_98 register definition
 *  Future Reserved Register at offset 0x98 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RESERVED_98_ADDR        (REG_USBC_BASE_ADDR+0x0000C198)
#define USBC_RESERVED_98_OFFSET      0x0000C198
#define USBC_RESERVED_98_INDEX       0x00003066
#define USBC_RESERVED_98_RESET       0x00000000

__INLINE uint32_t  usbc_reserved_98_get(void)
{
	return REG_PL_RD(USBC_RESERVED_98_ADDR);
}

// field definitions
#define USBC_RESERVED_98_RESERVED_31_0_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_RESERVED_98_RESERVED_31_0_LSB    0
#define USBC_RESERVED_98_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RESERVED_98_RESERVED_31_0_RST    0x0

__INLINE uint32_t usbc_reserved_98_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RESERVED_98_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief GUCTL_2 register definition
 *  Global User Control Register 2:    This register provides a few options for the software to control the controller behavior in the Host and device mode. Most of the options are used to improve inter-operability with different hosts and devices. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:26 reserved_31_26            0x0
 *    25:19 EN_HP_PM_TIMER            0x33
 *    18:15 NOLOWPWRDUR               0x0
 *    14    Rst_actbitlater           0              
 *    13    reserved_13               0              
 *    12    Enable_Ep_Cache_Evict     0              
 *    11    Disable_CFC               0              
 *    10:05 Rx_Ping_Duration          0x20
 *    04:00 Tx_Ping_Duration          0xd
 * </pre>
 */
#define USBC_GUCTL_2_ADDR        (REG_USBC_BASE_ADDR+0x0000C19C)
#define USBC_GUCTL_2_OFFSET      0x0000C19C
#define USBC_GUCTL_2_INDEX       0x00003067
#define USBC_GUCTL_2_RESET       0x0198040D

__INLINE uint32_t  usbc_guctl_2_get(void)
{
	return REG_PL_RD(USBC_GUCTL_2_ADDR);
}

__INLINE void usbc_guctl_2_set(uint32_t value)
{
	REG_PL_WR(USBC_GUCTL_2_ADDR, value);
}

// field definitions
#define USBC_GUCTL_2_RESERVED_31_26_MASK    ((uint32_t)0xFC000000)
#define USBC_GUCTL_2_RESERVED_31_26_LSB     26
#define USBC_GUCTL_2_RESERVED_31_26_WIDTH    ((uint32_t)0x00000006)
#define USBC_GUCTL_2_EN_HP_PM_TIMER_MASK    ((uint32_t)0x03F80000)
#define USBC_GUCTL_2_EN_HP_PM_TIMER_LSB     19
#define USBC_GUCTL_2_EN_HP_PM_TIMER_WIDTH    ((uint32_t)0x00000007)
#define USBC_GUCTL_2_NOLOWPWRDUR_MASK       ((uint32_t)0x00078000)
#define USBC_GUCTL_2_NOLOWPWRDUR_LSB        15
#define USBC_GUCTL_2_NOLOWPWRDUR_WIDTH      ((uint32_t)0x00000004)
#define USBC_GUCTL_2_RST_ACTBITLATER_BIT    ((uint32_t)0x00004000)
#define USBC_GUCTL_2_RST_ACTBITLATER_POS    14
#define USBC_GUCTL_2_RESERVED_13_BIT        ((uint32_t)0x00002000)
#define USBC_GUCTL_2_RESERVED_13_POS        13
#define USBC_GUCTL_2_ENABLE_EP_CACHE_EVICT_BIT    ((uint32_t)0x00001000)
#define USBC_GUCTL_2_ENABLE_EP_CACHE_EVICT_POS    12
#define USBC_GUCTL_2_DISABLE_CFC_BIT        ((uint32_t)0x00000800)
#define USBC_GUCTL_2_DISABLE_CFC_POS        11
#define USBC_GUCTL_2_RX_PING_DURATION_MASK    ((uint32_t)0x000007E0)
#define USBC_GUCTL_2_RX_PING_DURATION_LSB    5
#define USBC_GUCTL_2_RX_PING_DURATION_WIDTH    ((uint32_t)0x00000006)
#define USBC_GUCTL_2_TX_PING_DURATION_MASK    ((uint32_t)0x0000001F)
#define USBC_GUCTL_2_TX_PING_DURATION_LSB    0
#define USBC_GUCTL_2_TX_PING_DURATION_WIDTH    ((uint32_t)0x00000005)

#define USBC_GUCTL_2_RESERVED_31_26_RST     0x0
#define USBC_GUCTL_2_EN_HP_PM_TIMER_RST     0x33
#define USBC_GUCTL_2_NOLOWPWRDUR_RST        0x0
#define USBC_GUCTL_2_RST_ACTBITLATER_RST    0x0
#define USBC_GUCTL_2_RESERVED_13_RST        0x0
#define USBC_GUCTL_2_ENABLE_EP_CACHE_EVICT_RST    0x0
#define USBC_GUCTL_2_DISABLE_CFC_RST        0x0
#define USBC_GUCTL_2_RX_PING_DURATION_RST    0x20
#define USBC_GUCTL_2_TX_PING_DURATION_RST    0xd

__INLINE void usbc_guctl_2_pack(uint8_t reserved_31_26, uint8_t en_hp_pm_timer, uint8_t nolowpwrdur, uint8_t rst_actbitlater, uint8_t reserved_13, uint8_t enable_ep_cache_evict, uint8_t disable_cfc, uint8_t rx_ping_duration, uint8_t tx_ping_duration)
{
	ASSERT_ERR((((uint32_t)reserved_31_26 << 26) & ~((uint32_t)0xFC000000)) == 0);
	ASSERT_ERR((((uint32_t)en_hp_pm_timer << 19) & ~((uint32_t)0x03F80000)) == 0);
	ASSERT_ERR((((uint32_t)nolowpwrdur << 15) & ~((uint32_t)0x00078000)) == 0);
	ASSERT_ERR((((uint32_t)rst_actbitlater << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_13 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)enable_ep_cache_evict << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)disable_cfc << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)rx_ping_duration << 5) & ~((uint32_t)0x000007E0)) == 0);
	ASSERT_ERR((((uint32_t)tx_ping_duration << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(USBC_GUCTL_2_ADDR,  ((uint32_t)reserved_31_26 << 26) |((uint32_t)en_hp_pm_timer << 19) |((uint32_t)nolowpwrdur << 15) |((uint32_t)rst_actbitlater << 14) |((uint32_t)reserved_13 << 13) |((uint32_t)enable_ep_cache_evict << 12) |((uint32_t)disable_cfc << 11) |((uint32_t)rx_ping_duration << 5) |((uint32_t)tx_ping_duration << 0));
}

__INLINE void usbc_guctl_2_unpack(uint8_t* reserved_31_26, uint8_t* en_hp_pm_timer, uint8_t* nolowpwrdur, uint8_t* rst_actbitlater, uint8_t* reserved_13, uint8_t* enable_ep_cache_evict, uint8_t* disable_cfc, uint8_t* rx_ping_duration, uint8_t* tx_ping_duration)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_2_ADDR);

	*reserved_31_26 = (localVal & ((uint32_t)0xFC000000)) >>  26;
	*en_hp_pm_timer = (localVal & ((uint32_t)0x03F80000)) >>  19;
	*nolowpwrdur = (localVal & ((uint32_t)0x00078000)) >>  15;
	*rst_actbitlater = (localVal & ((uint32_t)0x00004000)) >>  14;
	*reserved_13 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*enable_ep_cache_evict = (localVal & ((uint32_t)0x00001000)) >>  12;
	*disable_cfc = (localVal & ((uint32_t)0x00000800)) >>  11;
	*rx_ping_duration = (localVal & ((uint32_t)0x000007E0)) >>  5;
	*tx_ping_duration = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t usbc_guctl_2_reserved_31_26_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFC000000)) >> 26);
}
__INLINE void usbc_guctl_2_reserved_31_26_setf(uint8_t reserved3126)
{
	ASSERT_ERR((((uint32_t)reserved3126 << 26) & ~((uint32_t)0xFC000000)) == 0);
	REG_PL_WR(USBC_GUCTL_2_ADDR, (REG_PL_RD(USBC_GUCTL_2_ADDR) & ~((uint32_t)0xFC000000)) | ((uint32_t)reserved3126 <<26));
}
__INLINE uint8_t usbc_guctl_2_en_hp_pm_timer_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x03F80000)) >> 19);
}
__INLINE void usbc_guctl_2_en_hp_pm_timer_setf(uint8_t enhppmtimer)
{
	ASSERT_ERR((((uint32_t)enhppmtimer << 19) & ~((uint32_t)0x03F80000)) == 0);
	REG_PL_WR(USBC_GUCTL_2_ADDR, (REG_PL_RD(USBC_GUCTL_2_ADDR) & ~((uint32_t)0x03F80000)) | ((uint32_t)enhppmtimer <<19));
}
__INLINE uint8_t usbc_guctl_2_nolowpwrdur_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00078000)) >> 15);
}
__INLINE void usbc_guctl_2_nolowpwrdur_setf(uint8_t nolowpwrdur)
{
	ASSERT_ERR((((uint32_t)nolowpwrdur << 15) & ~((uint32_t)0x00078000)) == 0);
	REG_PL_WR(USBC_GUCTL_2_ADDR, (REG_PL_RD(USBC_GUCTL_2_ADDR) & ~((uint32_t)0x00078000)) | ((uint32_t)nolowpwrdur <<15));
}
__INLINE uint8_t usbc_guctl_2_rst_actbitlater_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void usbc_guctl_2_rst_actbitlater_setf(uint8_t rstactbitlater)
{
	ASSERT_ERR((((uint32_t)rstactbitlater << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(USBC_GUCTL_2_ADDR, (REG_PL_RD(USBC_GUCTL_2_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)rstactbitlater <<14));
}
__INLINE uint8_t usbc_guctl_2_reserved_13_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t usbc_guctl_2_enable_ep_cache_evict_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void usbc_guctl_2_enable_ep_cache_evict_setf(uint8_t enableepcacheevict)
{
	ASSERT_ERR((((uint32_t)enableepcacheevict << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(USBC_GUCTL_2_ADDR, (REG_PL_RD(USBC_GUCTL_2_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)enableepcacheevict <<12));
}
__INLINE uint8_t usbc_guctl_2_disable_cfc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_guctl_2_disable_cfc_setf(uint8_t disablecfc)
{
	ASSERT_ERR((((uint32_t)disablecfc << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_GUCTL_2_ADDR, (REG_PL_RD(USBC_GUCTL_2_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)disablecfc <<11));
}
__INLINE uint8_t usbc_guctl_2_rx_ping_duration_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000007E0)) >> 5);
}
__INLINE void usbc_guctl_2_rx_ping_duration_setf(uint8_t rxpingduration)
{
	ASSERT_ERR((((uint32_t)rxpingduration << 5) & ~((uint32_t)0x000007E0)) == 0);
	REG_PL_WR(USBC_GUCTL_2_ADDR, (REG_PL_RD(USBC_GUCTL_2_ADDR) & ~((uint32_t)0x000007E0)) | ((uint32_t)rxpingduration <<5));
}
__INLINE uint8_t usbc_guctl_2_tx_ping_duration_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void usbc_guctl_2_tx_ping_duration_setf(uint8_t txpingduration)
{
	ASSERT_ERR((((uint32_t)txpingduration << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(USBC_GUCTL_2_ADDR, (REG_PL_RD(USBC_GUCTL_2_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)txpingduration <<0));
}

/**
 * @brief GUSB_2_PHYCFG_0 register definition
 *  Global USB2 PHY Configuration Register  The application must program this register before starting any transactions on either the SoC bus or the USB.  In Device-only configurations, only one register is needed. In Host mode, per-port registers are implemented. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    PHYSOFTRST                0              
 *    30    U2_FREECLK_EXISTS         0              
 *    29    ULPI_LPM_WITH_OPMODE_CHK  0              
 *    28:27 HSIC_CON_WIDTH_ADJ        0x0
 *    26    INV_SEL_HSIC              0              
 *    25    OVRD_FSLS_DISC_TIME       0              
 *    24:22 LSTRD                     0x0
 *    21:19 LSIPD                     0x2
 *    18    ULPIEXTVBUSINDIACTOR      0              
 *    17    ULPIEXTVBUSDRV            0              
 *    16    reserved_16               0              
 *    15    ULPIAUTORES               0              
 *    14    reserved_14               0              
 *    13:10 USBTRDTIM                 0x9
 *    09    XCVRDLY                   0              
 *    08    ENBLSLPM                  0              
 *    07    PHYSEL                    0              
 *    06    SUSPENDUSB20              0              
 *    05    FSINTF                    0              
 *    04    ULPI_UTMI_Sel             0              
 *    03    PHYIF                     1              
 *    02:00 TOut_Cal                  0x0
 * </pre>
 */
#define USBC_GUSB_2_PHYCFG_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C200)
#define USBC_GUSB_2_PHYCFG_0_OFFSET      0x0000C200
#define USBC_GUSB_2_PHYCFG_0_INDEX       0x00003080
#define USBC_GUSB_2_PHYCFG_0_RESET       0x00102408

__INLINE uint32_t  usbc_gusb_2_phycfg_0_get(void)
{
	return REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
}

__INLINE void usbc_gusb_2_phycfg_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, value);
}

// field definitions
#define USBC_GUSB_2_PHYCFG_0_PHYSOFTRST_BIT    ((uint32_t)0x80000000)
#define USBC_GUSB_2_PHYCFG_0_PHYSOFTRST_POS    31
#define USBC_GUSB_2_PHYCFG_0_U_2_FREECLK_EXISTS_BIT    ((uint32_t)0x40000000)
#define USBC_GUSB_2_PHYCFG_0_U_2_FREECLK_EXISTS_POS    30
#define USBC_GUSB_2_PHYCFG_0_ULPI_LPM_WITH_OPMODE_CHK_BIT    ((uint32_t)0x20000000)
#define USBC_GUSB_2_PHYCFG_0_ULPI_LPM_WITH_OPMODE_CHK_POS    29
#define USBC_GUSB_2_PHYCFG_0_HSIC_CON_WIDTH_ADJ_MASK    ((uint32_t)0x18000000)
#define USBC_GUSB_2_PHYCFG_0_HSIC_CON_WIDTH_ADJ_LSB    27
#define USBC_GUSB_2_PHYCFG_0_HSIC_CON_WIDTH_ADJ_WIDTH    ((uint32_t)0x00000002)
#define USBC_GUSB_2_PHYCFG_0_INV_SEL_HSIC_BIT    ((uint32_t)0x04000000)
#define USBC_GUSB_2_PHYCFG_0_INV_SEL_HSIC_POS    26
#define USBC_GUSB_2_PHYCFG_0_OVRD_FSLS_DISC_TIME_BIT    ((uint32_t)0x02000000)
#define USBC_GUSB_2_PHYCFG_0_OVRD_FSLS_DISC_TIME_POS    25
#define USBC_GUSB_2_PHYCFG_0_LSTRD_MASK     ((uint32_t)0x01C00000)
#define USBC_GUSB_2_PHYCFG_0_LSTRD_LSB      22
#define USBC_GUSB_2_PHYCFG_0_LSTRD_WIDTH    ((uint32_t)0x00000003)
#define USBC_GUSB_2_PHYCFG_0_LSIPD_MASK     ((uint32_t)0x00380000)
#define USBC_GUSB_2_PHYCFG_0_LSIPD_LSB      19
#define USBC_GUSB_2_PHYCFG_0_LSIPD_WIDTH    ((uint32_t)0x00000003)
#define USBC_GUSB_2_PHYCFG_0_ULPIEXTVBUSINDIACTOR_BIT    ((uint32_t)0x00040000)
#define USBC_GUSB_2_PHYCFG_0_ULPIEXTVBUSINDIACTOR_POS    18
#define USBC_GUSB_2_PHYCFG_0_ULPIEXTVBUSDRV_BIT    ((uint32_t)0x00020000)
#define USBC_GUSB_2_PHYCFG_0_ULPIEXTVBUSDRV_POS    17
#define USBC_GUSB_2_PHYCFG_0_RESERVED_16_BIT    ((uint32_t)0x00010000)
#define USBC_GUSB_2_PHYCFG_0_RESERVED_16_POS    16
#define USBC_GUSB_2_PHYCFG_0_ULPIAUTORES_BIT    ((uint32_t)0x00008000)
#define USBC_GUSB_2_PHYCFG_0_ULPIAUTORES_POS    15
#define USBC_GUSB_2_PHYCFG_0_RESERVED_14_BIT    ((uint32_t)0x00004000)
#define USBC_GUSB_2_PHYCFG_0_RESERVED_14_POS    14
#define USBC_GUSB_2_PHYCFG_0_USBTRDTIM_MASK    ((uint32_t)0x00003C00)
#define USBC_GUSB_2_PHYCFG_0_USBTRDTIM_LSB    10
#define USBC_GUSB_2_PHYCFG_0_USBTRDTIM_WIDTH    ((uint32_t)0x00000004)
#define USBC_GUSB_2_PHYCFG_0_XCVRDLY_BIT    ((uint32_t)0x00000200)
#define USBC_GUSB_2_PHYCFG_0_XCVRDLY_POS    9
#define USBC_GUSB_2_PHYCFG_0_ENBLSLPM_BIT    ((uint32_t)0x00000100)
#define USBC_GUSB_2_PHYCFG_0_ENBLSLPM_POS    8
#define USBC_GUSB_2_PHYCFG_0_PHYSEL_BIT     ((uint32_t)0x00000080)
#define USBC_GUSB_2_PHYCFG_0_PHYSEL_POS     7
#define USBC_GUSB_2_PHYCFG_0_SUSPENDUSB_20_BIT    ((uint32_t)0x00000040)
#define USBC_GUSB_2_PHYCFG_0_SUSPENDUSB_20_POS    6
#define USBC_GUSB_2_PHYCFG_0_FSINTF_BIT     ((uint32_t)0x00000020)
#define USBC_GUSB_2_PHYCFG_0_FSINTF_POS     5
#define USBC_GUSB_2_PHYCFG_0_ULPI_UTMI_SEL_BIT    ((uint32_t)0x00000010)
#define USBC_GUSB_2_PHYCFG_0_ULPI_UTMI_SEL_POS    4
#define USBC_GUSB_2_PHYCFG_0_PHYIF_BIT      ((uint32_t)0x00000008)
#define USBC_GUSB_2_PHYCFG_0_PHYIF_POS      3
#define USBC_GUSB_2_PHYCFG_0_TOUT_CAL_MASK    ((uint32_t)0x00000007)
#define USBC_GUSB_2_PHYCFG_0_TOUT_CAL_LSB    0
#define USBC_GUSB_2_PHYCFG_0_TOUT_CAL_WIDTH    ((uint32_t)0x00000003)

#define USBC_GUSB_2_PHYCFG_0_PHYSOFTRST_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_U_2_FREECLK_EXISTS_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_ULPI_LPM_WITH_OPMODE_CHK_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_HSIC_CON_WIDTH_ADJ_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_INV_SEL_HSIC_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_OVRD_FSLS_DISC_TIME_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_LSTRD_RST      0x0
#define USBC_GUSB_2_PHYCFG_0_LSIPD_RST      0x2
#define USBC_GUSB_2_PHYCFG_0_ULPIEXTVBUSINDIACTOR_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_ULPIEXTVBUSDRV_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_RESERVED_16_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_ULPIAUTORES_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_RESERVED_14_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_USBTRDTIM_RST    0x9
#define USBC_GUSB_2_PHYCFG_0_XCVRDLY_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_ENBLSLPM_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_PHYSEL_RST     0x0
#define USBC_GUSB_2_PHYCFG_0_SUSPENDUSB_20_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_FSINTF_RST     0x0
#define USBC_GUSB_2_PHYCFG_0_ULPI_UTMI_SEL_RST    0x0
#define USBC_GUSB_2_PHYCFG_0_PHYIF_RST      0x1
#define USBC_GUSB_2_PHYCFG_0_TOUT_CAL_RST    0x0

__INLINE void usbc_gusb_2_phycfg_0_pack(uint8_t physoftrst, uint8_t u2_freeclk_exists, uint8_t ulpi_lpm_with_opmode_chk, uint8_t hsic_con_width_adj, uint8_t inv_sel_hsic, uint8_t ovrd_fsls_disc_time, uint8_t lstrd, uint8_t lsipd, uint8_t ulpiextvbusindiactor, uint8_t ulpiextvbusdrv, uint8_t reserved_16, uint8_t ulpiautores, uint8_t reserved_14, uint8_t usbtrdtim, uint8_t xcvrdly, uint8_t enblslpm, uint8_t physel, uint8_t suspendusb20, uint8_t fsintf, uint8_t ulpi_utmi_sel, uint8_t phyif, uint8_t tout_cal)
{
	ASSERT_ERR((((uint32_t)physoftrst << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)u2_freeclk_exists << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)ulpi_lpm_with_opmode_chk << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)hsic_con_width_adj << 27) & ~((uint32_t)0x18000000)) == 0);
	ASSERT_ERR((((uint32_t)inv_sel_hsic << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)ovrd_fsls_disc_time << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)lstrd << 22) & ~((uint32_t)0x01C00000)) == 0);
	ASSERT_ERR((((uint32_t)lsipd << 19) & ~((uint32_t)0x00380000)) == 0);
	ASSERT_ERR((((uint32_t)ulpiextvbusindiactor << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)ulpiextvbusdrv << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_16 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)ulpiautores << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_14 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)usbtrdtim << 10) & ~((uint32_t)0x00003C00)) == 0);
	ASSERT_ERR((((uint32_t)xcvrdly << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)enblslpm << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)physel << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)suspendusb20 << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)fsintf << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)ulpi_utmi_sel << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)phyif << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)tout_cal << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR,  ((uint32_t)physoftrst << 31) |((uint32_t)u2_freeclk_exists << 30) |((uint32_t)ulpi_lpm_with_opmode_chk << 29) |((uint32_t)hsic_con_width_adj << 27) |((uint32_t)inv_sel_hsic << 26) |((uint32_t)ovrd_fsls_disc_time << 25) |((uint32_t)lstrd << 22) |((uint32_t)lsipd << 19) |((uint32_t)ulpiextvbusindiactor << 18) |((uint32_t)ulpiextvbusdrv << 17) |((uint32_t)reserved_16 << 16) |((uint32_t)ulpiautores << 15) |((uint32_t)reserved_14 << 14) |((uint32_t)usbtrdtim << 10) |((uint32_t)xcvrdly << 9) |((uint32_t)enblslpm << 8) |((uint32_t)physel << 7) |((uint32_t)suspendusb20 << 6) |((uint32_t)fsintf << 5) |((uint32_t)ulpi_utmi_sel << 4) |((uint32_t)phyif << 3) |((uint32_t)tout_cal << 0));
}

__INLINE void usbc_gusb_2_phycfg_0_unpack(uint8_t* physoftrst, uint8_t* u2_freeclk_exists, uint8_t* ulpi_lpm_with_opmode_chk, uint8_t* hsic_con_width_adj, uint8_t* inv_sel_hsic, uint8_t* ovrd_fsls_disc_time, uint8_t* lstrd, uint8_t* lsipd, uint8_t* ulpiextvbusindiactor, uint8_t* ulpiextvbusdrv, uint8_t* reserved_16, uint8_t* ulpiautores, uint8_t* reserved_14, uint8_t* usbtrdtim, uint8_t* xcvrdly, uint8_t* enblslpm, uint8_t* physel, uint8_t* suspendusb20, uint8_t* fsintf, uint8_t* ulpi_utmi_sel, uint8_t* phyif, uint8_t* tout_cal)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);

	*physoftrst = (localVal & ((uint32_t)0x80000000)) >>  31;
	*u2_freeclk_exists = (localVal & ((uint32_t)0x40000000)) >>  30;
	*ulpi_lpm_with_opmode_chk = (localVal & ((uint32_t)0x20000000)) >>  29;
	*hsic_con_width_adj = (localVal & ((uint32_t)0x18000000)) >>  27;
	*inv_sel_hsic = (localVal & ((uint32_t)0x04000000)) >>  26;
	*ovrd_fsls_disc_time = (localVal & ((uint32_t)0x02000000)) >>  25;
	*lstrd = (localVal & ((uint32_t)0x01C00000)) >>  22;
	*lsipd = (localVal & ((uint32_t)0x00380000)) >>  19;
	*ulpiextvbusindiactor = (localVal & ((uint32_t)0x00040000)) >>  18;
	*ulpiextvbusdrv = (localVal & ((uint32_t)0x00020000)) >>  17;
	*reserved_16 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*ulpiautores = (localVal & ((uint32_t)0x00008000)) >>  15;
	*reserved_14 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*usbtrdtim = (localVal & ((uint32_t)0x00003C00)) >>  10;
	*xcvrdly = (localVal & ((uint32_t)0x00000200)) >>  9;
	*enblslpm = (localVal & ((uint32_t)0x00000100)) >>  8;
	*physel = (localVal & ((uint32_t)0x00000080)) >>  7;
	*suspendusb20 = (localVal & ((uint32_t)0x00000040)) >>  6;
	*fsintf = (localVal & ((uint32_t)0x00000020)) >>  5;
	*ulpi_utmi_sel = (localVal & ((uint32_t)0x00000010)) >>  4;
	*phyif = (localVal & ((uint32_t)0x00000008)) >>  3;
	*tout_cal = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t usbc_gusb_2_phycfg_0_physoftrst_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void usbc_gusb_2_phycfg_0_physoftrst_setf(uint8_t physoftrst)
{
	ASSERT_ERR((((uint32_t)physoftrst << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)physoftrst <<31));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_u_2_freeclk_exists_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void usbc_gusb_2_phycfg_0_u_2_freeclk_exists_setf(uint8_t u2freeclkexists)
{
	ASSERT_ERR((((uint32_t)u2freeclkexists << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)u2freeclkexists <<30));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_ulpi_lpm_with_opmode_chk_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void usbc_gusb_2_phycfg_0_ulpi_lpm_with_opmode_chk_setf(uint8_t ulpilpmwithopmodechk)
{
	ASSERT_ERR((((uint32_t)ulpilpmwithopmodechk << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)ulpilpmwithopmodechk <<29));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_hsic_con_width_adj_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x18000000)) >> 27);
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_inv_sel_hsic_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_ovrd_fsls_disc_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void usbc_gusb_2_phycfg_0_ovrd_fsls_disc_time_setf(uint8_t ovrdfslsdisctime)
{
	ASSERT_ERR((((uint32_t)ovrdfslsdisctime << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)ovrdfslsdisctime <<25));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_lstrd_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01C00000)) >> 22);
}
__INLINE void usbc_gusb_2_phycfg_0_lstrd_setf(uint8_t lstrd)
{
	ASSERT_ERR((((uint32_t)lstrd << 22) & ~((uint32_t)0x01C00000)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x01C00000)) | ((uint32_t)lstrd <<22));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_lsipd_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00380000)) >> 19);
}
__INLINE void usbc_gusb_2_phycfg_0_lsipd_setf(uint8_t lsipd)
{
	ASSERT_ERR((((uint32_t)lsipd << 19) & ~((uint32_t)0x00380000)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x00380000)) | ((uint32_t)lsipd <<19));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_ulpiextvbusindiactor_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void usbc_gusb_2_phycfg_0_ulpiextvbusindiactor_setf(uint8_t ulpiextvbusindiactor)
{
	ASSERT_ERR((((uint32_t)ulpiextvbusindiactor << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)ulpiextvbusindiactor <<18));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_ulpiextvbusdrv_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void usbc_gusb_2_phycfg_0_ulpiextvbusdrv_setf(uint8_t ulpiextvbusdrv)
{
	ASSERT_ERR((((uint32_t)ulpiextvbusdrv << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)ulpiextvbusdrv <<17));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_reserved_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_ulpiautores_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void usbc_gusb_2_phycfg_0_ulpiautores_setf(uint8_t ulpiautores)
{
	ASSERT_ERR((((uint32_t)ulpiautores << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)ulpiautores <<15));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_reserved_14_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_usbtrdtim_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003C00)) >> 10);
}
__INLINE void usbc_gusb_2_phycfg_0_usbtrdtim_setf(uint8_t usbtrdtim)
{
	ASSERT_ERR((((uint32_t)usbtrdtim << 10) & ~((uint32_t)0x00003C00)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x00003C00)) | ((uint32_t)usbtrdtim <<10));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_xcvrdly_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void usbc_gusb_2_phycfg_0_xcvrdly_setf(uint8_t xcvrdly)
{
	ASSERT_ERR((((uint32_t)xcvrdly << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)xcvrdly <<9));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_enblslpm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_gusb_2_phycfg_0_enblslpm_setf(uint8_t enblslpm)
{
	ASSERT_ERR((((uint32_t)enblslpm << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)enblslpm <<8));
}
__INLINE void usbc_gusb_2_phycfg_0_physel_setf(uint8_t physel)
{
	ASSERT_ERR((((uint32_t)physel << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)physel <<7));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_suspendusb_20_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void usbc_gusb_2_phycfg_0_suspendusb_20_setf(uint8_t suspendusb20)
{
	ASSERT_ERR((((uint32_t)suspendusb20 << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)suspendusb20 <<6));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_fsintf_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_ulpi_utmi_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_phyif_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void usbc_gusb_2_phycfg_0_phyif_setf(uint8_t phyif)
{
	ASSERT_ERR((((uint32_t)phyif << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)phyif <<3));
}
__INLINE uint8_t usbc_gusb_2_phycfg_0_tout_cal_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void usbc_gusb_2_phycfg_0_tout_cal_setf(uint8_t toutcal)
{
	ASSERT_ERR((((uint32_t)toutcal << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(USBC_GUSB_2_PHYCFG_0_ADDR, (REG_PL_RD(USBC_GUSB_2_PHYCFG_0_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)toutcal <<0));
}

/**
 * @brief GUSB_2_I_2_CCTL_0 register definition
 *  Reserved Register  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_GUSB_2_I_2_CCTL_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C240)
#define USBC_GUSB_2_I_2_CCTL_0_OFFSET      0x0000C240
#define USBC_GUSB_2_I_2_CCTL_0_INDEX       0x00003090
#define USBC_GUSB_2_I_2_CCTL_0_RESET       0x00000000

__INLINE uint32_t  usbc_gusb_2_i_2_cctl_0_get(void)
{
	return REG_PL_RD(USBC_GUSB_2_I_2_CCTL_0_ADDR);
}

// field definitions
#define USBC_GUSB_2_I_2_CCTL_0_RESERVED_31_0_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_GUSB_2_I_2_CCTL_0_RESERVED_31_0_LSB    0
#define USBC_GUSB_2_I_2_CCTL_0_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_GUSB_2_I_2_CCTL_0_RESERVED_31_0_RST    0x0

__INLINE uint32_t usbc_gusb_2_i_2_cctl_0_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_I_2_CCTL_0_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief GUSB_2_PHYACC_ULPI_0 register definition
 *  Global USB 2.0 ULPI PHY Vendor Control Register  The application uses this register to access the PHY registers. This register is always implemented when the ULPI PHY Interface is enabled during coreConsultant configuration (parameter DWC_USB3_HSPHY_INTERFACE = 2 or 3).  For an ULPI PHY, the controller uses the ULPI interface for PHY register access.  The application sets the Vendor Control register for PHY register access and times the PHY register access. The application polls the VStatus Done bit in this register for the completion of the PHY register access.  In Device-only configurations, only one register is needed. In Host mode, per-port registers are implemented. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:27 reserved_31_27            0x0
 *    26    DISUIPIDRVR               0              
 *    25    NEWREGREQ                 0              
 *    24    VSTSDONE                  0              
 *    23    VSTSBSY                   0              
 *    22    REGWR                     0              
 *    21:16 REGADDR                   0x0
 *    15:08 EXTREGADDR                0x0
 *    07:00 REGDATA                   0x0
 * </pre>
 */
#define USBC_GUSB_2_PHYACC_ULPI_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C280)
#define USBC_GUSB_2_PHYACC_ULPI_0_OFFSET      0x0000C280
#define USBC_GUSB_2_PHYACC_ULPI_0_INDEX       0x000030A0
#define USBC_GUSB_2_PHYACC_ULPI_0_RESET       0x00000000

__INLINE uint32_t  usbc_gusb_2_phyacc_ulpi_0_get(void)
{
	return REG_PL_RD(USBC_GUSB_2_PHYACC_ULPI_0_ADDR);
}

// field definitions
#define USBC_GUSB_2_PHYACC_ULPI_0_RESERVED_31_27_MASK    ((uint32_t)0xF8000000)
#define USBC_GUSB_2_PHYACC_ULPI_0_RESERVED_31_27_LSB    27
#define USBC_GUSB_2_PHYACC_ULPI_0_RESERVED_31_27_WIDTH    ((uint32_t)0x00000005)
#define USBC_GUSB_2_PHYACC_ULPI_0_DISUIPIDRVR_BIT    ((uint32_t)0x04000000)
#define USBC_GUSB_2_PHYACC_ULPI_0_DISUIPIDRVR_POS    26
#define USBC_GUSB_2_PHYACC_ULPI_0_NEWREGREQ_BIT    ((uint32_t)0x02000000)
#define USBC_GUSB_2_PHYACC_ULPI_0_NEWREGREQ_POS    25
#define USBC_GUSB_2_PHYACC_ULPI_0_VSTSDONE_BIT    ((uint32_t)0x01000000)
#define USBC_GUSB_2_PHYACC_ULPI_0_VSTSDONE_POS    24
#define USBC_GUSB_2_PHYACC_ULPI_0_VSTSBSY_BIT    ((uint32_t)0x00800000)
#define USBC_GUSB_2_PHYACC_ULPI_0_VSTSBSY_POS    23
#define USBC_GUSB_2_PHYACC_ULPI_0_REGWR_BIT    ((uint32_t)0x00400000)
#define USBC_GUSB_2_PHYACC_ULPI_0_REGWR_POS    22
#define USBC_GUSB_2_PHYACC_ULPI_0_REGADDR_MASK    ((uint32_t)0x003F0000)
#define USBC_GUSB_2_PHYACC_ULPI_0_REGADDR_LSB    16
#define USBC_GUSB_2_PHYACC_ULPI_0_REGADDR_WIDTH    ((uint32_t)0x00000006)
#define USBC_GUSB_2_PHYACC_ULPI_0_EXTREGADDR_MASK    ((uint32_t)0x0000FF00)
#define USBC_GUSB_2_PHYACC_ULPI_0_EXTREGADDR_LSB    8
#define USBC_GUSB_2_PHYACC_ULPI_0_EXTREGADDR_WIDTH    ((uint32_t)0x00000008)
#define USBC_GUSB_2_PHYACC_ULPI_0_REGDATA_MASK    ((uint32_t)0x000000FF)
#define USBC_GUSB_2_PHYACC_ULPI_0_REGDATA_LSB    0
#define USBC_GUSB_2_PHYACC_ULPI_0_REGDATA_WIDTH    ((uint32_t)0x00000008)

#define USBC_GUSB_2_PHYACC_ULPI_0_RESERVED_31_27_RST    0x0
#define USBC_GUSB_2_PHYACC_ULPI_0_DISUIPIDRVR_RST    0x0
#define USBC_GUSB_2_PHYACC_ULPI_0_NEWREGREQ_RST    0x0
#define USBC_GUSB_2_PHYACC_ULPI_0_VSTSDONE_RST    0x0
#define USBC_GUSB_2_PHYACC_ULPI_0_VSTSBSY_RST    0x0
#define USBC_GUSB_2_PHYACC_ULPI_0_REGWR_RST    0x0
#define USBC_GUSB_2_PHYACC_ULPI_0_REGADDR_RST    0x0
#define USBC_GUSB_2_PHYACC_ULPI_0_EXTREGADDR_RST    0x0
#define USBC_GUSB_2_PHYACC_ULPI_0_REGDATA_RST    0x0

__INLINE void usbc_gusb_2_phyacc_ulpi_0_unpack(uint8_t* reserved_31_27, uint8_t* disuipidrvr, uint8_t* newregreq, uint8_t* vstsdone, uint8_t* vstsbsy, uint8_t* regwr, uint8_t* regaddr, uint8_t* extregaddr, uint8_t* regdata)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYACC_ULPI_0_ADDR);

	*reserved_31_27 = (localVal & ((uint32_t)0xF8000000)) >>  27;
	*disuipidrvr = (localVal & ((uint32_t)0x04000000)) >>  26;
	*newregreq = (localVal & ((uint32_t)0x02000000)) >>  25;
	*vstsdone = (localVal & ((uint32_t)0x01000000)) >>  24;
	*vstsbsy = (localVal & ((uint32_t)0x00800000)) >>  23;
	*regwr = (localVal & ((uint32_t)0x00400000)) >>  22;
	*regaddr = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*extregaddr = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*regdata = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t usbc_gusb_2_phyacc_ulpi_0_reserved_31_27_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYACC_ULPI_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF8000000)) >> 27);
}
__INLINE uint8_t usbc_gusb_2_phyacc_ulpi_0_disuipidrvr_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYACC_ULPI_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE uint8_t usbc_gusb_2_phyacc_ulpi_0_newregreq_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYACC_ULPI_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE uint8_t usbc_gusb_2_phyacc_ulpi_0_vstsdone_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYACC_ULPI_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE uint8_t usbc_gusb_2_phyacc_ulpi_0_vstsbsy_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYACC_ULPI_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t usbc_gusb_2_phyacc_ulpi_0_regwr_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYACC_ULPI_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint8_t usbc_gusb_2_phyacc_ulpi_0_regaddr_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYACC_ULPI_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE uint8_t usbc_gusb_2_phyacc_ulpi_0_extregaddr_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYACC_ULPI_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t usbc_gusb_2_phyacc_ulpi_0_regdata_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_PHYACC_ULPI_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief GUSB_3_PIPECTL_0 register definition
 *  Global USB 3.0 PIPE Control Register  The application uses this register to configure the USB3 PHY and PIPE interface.  Device-only configuration requires only one register. In Host mode, registers are implemented for each port.  For more details on GUSB3PIPECTL(#n) bits, refer to section  GUSB3PIPECTLn Register  in the User Guide.  Note:  - GUSB3PIPECTLn registers are not applicable for USB 2.0-only mode. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    PHYSoft_Rst               0              
 *    30    Hst_Prt_Cmpl              0              
 *    29    U2_P3ok                   0              
 *    28    Dis_Rx_Det_P3             0              
 *    27    Ux_exit_in_Px             0              
 *    26    ping_enhancement_en       0              
 *    25    u1u2exitfail_to_recov     0              
 *    24    request_p1p2p3            1              
 *    23    Start_Rx_Det_U3_Rx_Det    0              
 *    22    Dis_Rx_Det_U3_Rx_Det      0              
 *    21:19 Delay_P1_P2_P3            0x1
 *    18    DELAYP1_TRANS             1              
 *    17    SUSPENDENABLE             0              
 *    16:15 DATWIDTH                  0x1
 *    14    Abort_Rx_Det_In_U2        0              
 *    13    Skip_Rx_Det               0              
 *    12    LFPSP0_Algn               0              
 *    11    P3_P2_Tran_OK             0              
 *    10    P3_Ex_Sig_P2              0              
 *    09    LFPSFILTER                0              
 *    08    RX_DETECT_to_Polling_LFPS_Control 0              
 *    07    SSICEn                    0              
 *    06    TX_SWING                  0              
 *    05:03 TX_MARGIN                 0x0
 *    02:01 SS_TX_DE_EMPHASIS         0x1
 *    00    ELASTIC_BUFFER_MODE       0              
 * </pre>
 */
#define USBC_GUSB_3_PIPECTL_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C2C0)
#define USBC_GUSB_3_PIPECTL_0_OFFSET      0x0000C2C0
#define USBC_GUSB_3_PIPECTL_0_INDEX       0x000030B0
#define USBC_GUSB_3_PIPECTL_0_RESET       0x010C8002

__INLINE uint32_t  usbc_gusb_3_pipectl_0_get(void)
{
	return REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
}

__INLINE void usbc_gusb_3_pipectl_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, value);
}

// field definitions
#define USBC_GUSB_3_PIPECTL_0_PHYSOFT_RST_BIT    ((uint32_t)0x80000000)
#define USBC_GUSB_3_PIPECTL_0_PHYSOFT_RST_POS    31
#define USBC_GUSB_3_PIPECTL_0_HST_PRT_CMPL_BIT    ((uint32_t)0x40000000)
#define USBC_GUSB_3_PIPECTL_0_HST_PRT_CMPL_POS    30
#define USBC_GUSB_3_PIPECTL_0_U_2_P_3_OK_BIT    ((uint32_t)0x20000000)
#define USBC_GUSB_3_PIPECTL_0_U_2_P_3_OK_POS    29
#define USBC_GUSB_3_PIPECTL_0_DIS_RX_DET_P_3_BIT    ((uint32_t)0x10000000)
#define USBC_GUSB_3_PIPECTL_0_DIS_RX_DET_P_3_POS    28
#define USBC_GUSB_3_PIPECTL_0_UX_EXIT_IN_PX_BIT    ((uint32_t)0x08000000)
#define USBC_GUSB_3_PIPECTL_0_UX_EXIT_IN_PX_POS    27
#define USBC_GUSB_3_PIPECTL_0_PING_ENHANCEMENT_EN_BIT    ((uint32_t)0x04000000)
#define USBC_GUSB_3_PIPECTL_0_PING_ENHANCEMENT_EN_POS    26
#define USBC_GUSB_3_PIPECTL_0_U_1_U_2_EXITFAIL_TO_RECOV_BIT    ((uint32_t)0x02000000)
#define USBC_GUSB_3_PIPECTL_0_U_1_U_2_EXITFAIL_TO_RECOV_POS    25
#define USBC_GUSB_3_PIPECTL_0_REQUEST_P_1_P_2_P_3_BIT    ((uint32_t)0x01000000)
#define USBC_GUSB_3_PIPECTL_0_REQUEST_P_1_P_2_P_3_POS    24
#define USBC_GUSB_3_PIPECTL_0_START_RX_DET_U_3_RX_DET_BIT    ((uint32_t)0x00800000)
#define USBC_GUSB_3_PIPECTL_0_START_RX_DET_U_3_RX_DET_POS    23
#define USBC_GUSB_3_PIPECTL_0_DIS_RX_DET_U_3_RX_DET_BIT    ((uint32_t)0x00400000)
#define USBC_GUSB_3_PIPECTL_0_DIS_RX_DET_U_3_RX_DET_POS    22
#define USBC_GUSB_3_PIPECTL_0_DELAY_P_1_P_2_P_3_MASK    ((uint32_t)0x00380000)
#define USBC_GUSB_3_PIPECTL_0_DELAY_P_1_P_2_P_3_LSB    19
#define USBC_GUSB_3_PIPECTL_0_DELAY_P_1_P_2_P_3_WIDTH    ((uint32_t)0x00000003)
#define USBC_GUSB_3_PIPECTL_0_DELAYP_1_TRANS_BIT    ((uint32_t)0x00040000)
#define USBC_GUSB_3_PIPECTL_0_DELAYP_1_TRANS_POS    18
#define USBC_GUSB_3_PIPECTL_0_SUSPENDENABLE_BIT    ((uint32_t)0x00020000)
#define USBC_GUSB_3_PIPECTL_0_SUSPENDENABLE_POS    17
#define USBC_GUSB_3_PIPECTL_0_DATWIDTH_MASK    ((uint32_t)0x00018000)
#define USBC_GUSB_3_PIPECTL_0_DATWIDTH_LSB    15
#define USBC_GUSB_3_PIPECTL_0_DATWIDTH_WIDTH    ((uint32_t)0x00000002)
#define USBC_GUSB_3_PIPECTL_0_ABORT_RX_DET_IN_U_2_BIT    ((uint32_t)0x00004000)
#define USBC_GUSB_3_PIPECTL_0_ABORT_RX_DET_IN_U_2_POS    14
#define USBC_GUSB_3_PIPECTL_0_SKIP_RX_DET_BIT    ((uint32_t)0x00002000)
#define USBC_GUSB_3_PIPECTL_0_SKIP_RX_DET_POS    13
#define USBC_GUSB_3_PIPECTL_0_LFPSP_0_ALGN_BIT    ((uint32_t)0x00001000)
#define USBC_GUSB_3_PIPECTL_0_LFPSP_0_ALGN_POS    12
#define USBC_GUSB_3_PIPECTL_0_P_3_P_2_TRAN_OK_BIT    ((uint32_t)0x00000800)
#define USBC_GUSB_3_PIPECTL_0_P_3_P_2_TRAN_OK_POS    11
#define USBC_GUSB_3_PIPECTL_0_P_3_EX_SIG_P_2_BIT    ((uint32_t)0x00000400)
#define USBC_GUSB_3_PIPECTL_0_P_3_EX_SIG_P_2_POS    10
#define USBC_GUSB_3_PIPECTL_0_LFPSFILTER_BIT    ((uint32_t)0x00000200)
#define USBC_GUSB_3_PIPECTL_0_LFPSFILTER_POS    9
#define USBC_GUSB_3_PIPECTL_0_RX_DETECT_TO_POLLING_LFPS_CONTROL_BIT    ((uint32_t)0x00000100)
#define USBC_GUSB_3_PIPECTL_0_RX_DETECT_TO_POLLING_LFPS_CONTROL_POS    8
#define USBC_GUSB_3_PIPECTL_0_SSICEN_BIT    ((uint32_t)0x00000080)
#define USBC_GUSB_3_PIPECTL_0_SSICEN_POS    7
#define USBC_GUSB_3_PIPECTL_0_TX_SWING_BIT    ((uint32_t)0x00000040)
#define USBC_GUSB_3_PIPECTL_0_TX_SWING_POS    6
#define USBC_GUSB_3_PIPECTL_0_TX_MARGIN_MASK    ((uint32_t)0x00000038)
#define USBC_GUSB_3_PIPECTL_0_TX_MARGIN_LSB    3
#define USBC_GUSB_3_PIPECTL_0_TX_MARGIN_WIDTH    ((uint32_t)0x00000003)
#define USBC_GUSB_3_PIPECTL_0_SS_TX_DE_EMPHASIS_MASK    ((uint32_t)0x00000006)
#define USBC_GUSB_3_PIPECTL_0_SS_TX_DE_EMPHASIS_LSB    1
#define USBC_GUSB_3_PIPECTL_0_SS_TX_DE_EMPHASIS_WIDTH    ((uint32_t)0x00000002)
#define USBC_GUSB_3_PIPECTL_0_ELASTIC_BUFFER_MODE_BIT    ((uint32_t)0x00000001)
#define USBC_GUSB_3_PIPECTL_0_ELASTIC_BUFFER_MODE_POS    0

#define USBC_GUSB_3_PIPECTL_0_PHYSOFT_RST_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_HST_PRT_CMPL_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_U_2_P_3_OK_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_DIS_RX_DET_P_3_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_UX_EXIT_IN_PX_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_PING_ENHANCEMENT_EN_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_U_1_U_2_EXITFAIL_TO_RECOV_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_REQUEST_P_1_P_2_P_3_RST    0x1
#define USBC_GUSB_3_PIPECTL_0_START_RX_DET_U_3_RX_DET_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_DIS_RX_DET_U_3_RX_DET_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_DELAY_P_1_P_2_P_3_RST    0x1
#define USBC_GUSB_3_PIPECTL_0_DELAYP_1_TRANS_RST    0x1
#define USBC_GUSB_3_PIPECTL_0_SUSPENDENABLE_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_DATWIDTH_RST    0x1
#define USBC_GUSB_3_PIPECTL_0_ABORT_RX_DET_IN_U_2_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_SKIP_RX_DET_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_LFPSP_0_ALGN_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_P_3_P_2_TRAN_OK_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_P_3_EX_SIG_P_2_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_LFPSFILTER_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_RX_DETECT_TO_POLLING_LFPS_CONTROL_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_SSICEN_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_TX_SWING_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_TX_MARGIN_RST    0x0
#define USBC_GUSB_3_PIPECTL_0_SS_TX_DE_EMPHASIS_RST    0x1
#define USBC_GUSB_3_PIPECTL_0_ELASTIC_BUFFER_MODE_RST    0x0

__INLINE void usbc_gusb_3_pipectl_0_pack(uint8_t physoft_rst, uint8_t hst_prt_cmpl, uint8_t u2_p3ok, uint8_t dis_rx_det_p3, uint8_t ux_exit_in_px, uint8_t ping_enhancement_en, uint8_t u1u2exitfail_to_recov, uint8_t request_p1p2p3, uint8_t start_rx_det_u3_rx_det, uint8_t dis_rx_det_u3_rx_det, uint8_t delay_p1_p2_p3, uint8_t delayp1_trans, uint8_t suspendenable, uint8_t datwidth, uint8_t abort_rx_det_in_u2, uint8_t skip_rx_det, uint8_t lfpsp0_algn, uint8_t p3_p2_tran_ok, uint8_t p3_ex_sig_p2, uint8_t lfpsfilter, uint8_t rx_detect_to_polling_lfps_control, uint8_t ssicen, uint8_t tx_swing, uint8_t tx_margin, uint8_t ss_tx_de_emphasis, uint8_t elastic_buffer_mode)
{
	ASSERT_ERR((((uint32_t)physoft_rst << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)hst_prt_cmpl << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)u2_p3ok << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)dis_rx_det_p3 << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)ux_exit_in_px << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)ping_enhancement_en << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)u1u2exitfail_to_recov << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)request_p1p2p3 << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)start_rx_det_u3_rx_det << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)dis_rx_det_u3_rx_det << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)delay_p1_p2_p3 << 19) & ~((uint32_t)0x00380000)) == 0);
	ASSERT_ERR((((uint32_t)delayp1_trans << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)suspendenable << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)datwidth << 15) & ~((uint32_t)0x00018000)) == 0);
	ASSERT_ERR((((uint32_t)abort_rx_det_in_u2 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)skip_rx_det << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)lfpsp0_algn << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)p3_p2_tran_ok << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)p3_ex_sig_p2 << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)lfpsfilter << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)rx_detect_to_polling_lfps_control << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)ssicen << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)tx_swing << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)tx_margin << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)ss_tx_de_emphasis << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)elastic_buffer_mode << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR,  ((uint32_t)physoft_rst << 31) |((uint32_t)hst_prt_cmpl << 30) |((uint32_t)u2_p3ok << 29) |((uint32_t)dis_rx_det_p3 << 28) |((uint32_t)ux_exit_in_px << 27) |((uint32_t)ping_enhancement_en << 26) |((uint32_t)u1u2exitfail_to_recov << 25) |((uint32_t)request_p1p2p3 << 24) |((uint32_t)start_rx_det_u3_rx_det << 23) |((uint32_t)dis_rx_det_u3_rx_det << 22) |((uint32_t)delay_p1_p2_p3 << 19) |((uint32_t)delayp1_trans << 18) |((uint32_t)suspendenable << 17) |((uint32_t)datwidth << 15) |((uint32_t)abort_rx_det_in_u2 << 14) |((uint32_t)skip_rx_det << 13) |((uint32_t)lfpsp0_algn << 12) |((uint32_t)p3_p2_tran_ok << 11) |((uint32_t)p3_ex_sig_p2 << 10) |((uint32_t)lfpsfilter << 9) |((uint32_t)rx_detect_to_polling_lfps_control << 8) |((uint32_t)ssicen << 7) |((uint32_t)tx_swing << 6) |((uint32_t)tx_margin << 3) |((uint32_t)ss_tx_de_emphasis << 1) |((uint32_t)elastic_buffer_mode << 0));
}

__INLINE void usbc_gusb_3_pipectl_0_unpack(uint8_t* physoft_rst, uint8_t* hst_prt_cmpl, uint8_t* u2_p3ok, uint8_t* dis_rx_det_p3, uint8_t* ux_exit_in_px, uint8_t* ping_enhancement_en, uint8_t* u1u2exitfail_to_recov, uint8_t* request_p1p2p3, uint8_t* start_rx_det_u3_rx_det, uint8_t* dis_rx_det_u3_rx_det, uint8_t* delay_p1_p2_p3, uint8_t* delayp1_trans, uint8_t* suspendenable, uint8_t* datwidth, uint8_t* abort_rx_det_in_u2, uint8_t* skip_rx_det, uint8_t* lfpsp0_algn, uint8_t* p3_p2_tran_ok, uint8_t* p3_ex_sig_p2, uint8_t* lfpsfilter, uint8_t* rx_detect_to_polling_lfps_control, uint8_t* ssicen, uint8_t* tx_swing, uint8_t* tx_margin, uint8_t* ss_tx_de_emphasis, uint8_t* elastic_buffer_mode)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);

	*physoft_rst = (localVal & ((uint32_t)0x80000000)) >>  31;
	*hst_prt_cmpl = (localVal & ((uint32_t)0x40000000)) >>  30;
	*u2_p3ok = (localVal & ((uint32_t)0x20000000)) >>  29;
	*dis_rx_det_p3 = (localVal & ((uint32_t)0x10000000)) >>  28;
	*ux_exit_in_px = (localVal & ((uint32_t)0x08000000)) >>  27;
	*ping_enhancement_en = (localVal & ((uint32_t)0x04000000)) >>  26;
	*u1u2exitfail_to_recov = (localVal & ((uint32_t)0x02000000)) >>  25;
	*request_p1p2p3 = (localVal & ((uint32_t)0x01000000)) >>  24;
	*start_rx_det_u3_rx_det = (localVal & ((uint32_t)0x00800000)) >>  23;
	*dis_rx_det_u3_rx_det = (localVal & ((uint32_t)0x00400000)) >>  22;
	*delay_p1_p2_p3 = (localVal & ((uint32_t)0x00380000)) >>  19;
	*delayp1_trans = (localVal & ((uint32_t)0x00040000)) >>  18;
	*suspendenable = (localVal & ((uint32_t)0x00020000)) >>  17;
	*datwidth = (localVal & ((uint32_t)0x00018000)) >>  15;
	*abort_rx_det_in_u2 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*skip_rx_det = (localVal & ((uint32_t)0x00002000)) >>  13;
	*lfpsp0_algn = (localVal & ((uint32_t)0x00001000)) >>  12;
	*p3_p2_tran_ok = (localVal & ((uint32_t)0x00000800)) >>  11;
	*p3_ex_sig_p2 = (localVal & ((uint32_t)0x00000400)) >>  10;
	*lfpsfilter = (localVal & ((uint32_t)0x00000200)) >>  9;
	*rx_detect_to_polling_lfps_control = (localVal & ((uint32_t)0x00000100)) >>  8;
	*ssicen = (localVal & ((uint32_t)0x00000080)) >>  7;
	*tx_swing = (localVal & ((uint32_t)0x00000040)) >>  6;
	*tx_margin = (localVal & ((uint32_t)0x00000038)) >>  3;
	*ss_tx_de_emphasis = (localVal & ((uint32_t)0x00000006)) >>  1;
	*elastic_buffer_mode = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t usbc_gusb_3_pipectl_0_physoft_rst_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void usbc_gusb_3_pipectl_0_physoft_rst_setf(uint8_t physoftrst)
{
	ASSERT_ERR((((uint32_t)physoftrst << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)physoftrst <<31));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_hst_prt_cmpl_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void usbc_gusb_3_pipectl_0_hst_prt_cmpl_setf(uint8_t hstprtcmpl)
{
	ASSERT_ERR((((uint32_t)hstprtcmpl << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)hstprtcmpl <<30));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_u_2_p_3_ok_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void usbc_gusb_3_pipectl_0_u_2_p_3_ok_setf(uint8_t u2p3ok)
{
	ASSERT_ERR((((uint32_t)u2p3ok << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)u2p3ok <<29));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_dis_rx_det_p_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void usbc_gusb_3_pipectl_0_dis_rx_det_p_3_setf(uint8_t disrxdetp3)
{
	ASSERT_ERR((((uint32_t)disrxdetp3 << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)disrxdetp3 <<28));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_ux_exit_in_px_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void usbc_gusb_3_pipectl_0_ux_exit_in_px_setf(uint8_t uxexitinpx)
{
	ASSERT_ERR((((uint32_t)uxexitinpx << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)uxexitinpx <<27));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_ping_enhancement_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void usbc_gusb_3_pipectl_0_ping_enhancement_en_setf(uint8_t pingenhancementen)
{
	ASSERT_ERR((((uint32_t)pingenhancementen << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)pingenhancementen <<26));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_u_1_u_2_exitfail_to_recov_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void usbc_gusb_3_pipectl_0_u_1_u_2_exitfail_to_recov_setf(uint8_t u1u2exitfailtorecov)
{
	ASSERT_ERR((((uint32_t)u1u2exitfailtorecov << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)u1u2exitfailtorecov <<25));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_request_p_1_p_2_p_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void usbc_gusb_3_pipectl_0_request_p_1_p_2_p_3_setf(uint8_t requestp1p2p3)
{
	ASSERT_ERR((((uint32_t)requestp1p2p3 << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)requestp1p2p3 <<24));
}
__INLINE void usbc_gusb_3_pipectl_0_start_rx_det_u_3_rx_det_setf(uint8_t startrxdetu3rxdet)
{
	ASSERT_ERR((((uint32_t)startrxdetu3rxdet << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)startrxdetu3rxdet <<23));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_dis_rx_det_u_3_rx_det_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void usbc_gusb_3_pipectl_0_dis_rx_det_u_3_rx_det_setf(uint8_t disrxdetu3rxdet)
{
	ASSERT_ERR((((uint32_t)disrxdetu3rxdet << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)disrxdetu3rxdet <<22));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_delay_p_1_p_2_p_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00380000)) >> 19);
}
__INLINE void usbc_gusb_3_pipectl_0_delay_p_1_p_2_p_3_setf(uint8_t delayp1p2p3)
{
	ASSERT_ERR((((uint32_t)delayp1p2p3 << 19) & ~((uint32_t)0x00380000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00380000)) | ((uint32_t)delayp1p2p3 <<19));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_delayp_1_trans_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void usbc_gusb_3_pipectl_0_delayp_1_trans_setf(uint8_t delayp1trans)
{
	ASSERT_ERR((((uint32_t)delayp1trans << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)delayp1trans <<18));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_suspendenable_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void usbc_gusb_3_pipectl_0_suspendenable_setf(uint8_t suspendenable)
{
	ASSERT_ERR((((uint32_t)suspendenable << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)suspendenable <<17));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_datwidth_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00018000)) >> 15);
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_abort_rx_det_in_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void usbc_gusb_3_pipectl_0_abort_rx_det_in_u_2_setf(uint8_t abortrxdetinu2)
{
	ASSERT_ERR((((uint32_t)abortrxdetinu2 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)abortrxdetinu2 <<14));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_skip_rx_det_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void usbc_gusb_3_pipectl_0_skip_rx_det_setf(uint8_t skiprxdet)
{
	ASSERT_ERR((((uint32_t)skiprxdet << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)skiprxdet <<13));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_lfpsp_0_algn_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void usbc_gusb_3_pipectl_0_lfpsp_0_algn_setf(uint8_t lfpsp0algn)
{
	ASSERT_ERR((((uint32_t)lfpsp0algn << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)lfpsp0algn <<12));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_p_3_p_2_tran_ok_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_gusb_3_pipectl_0_p_3_p_2_tran_ok_setf(uint8_t p3p2tranok)
{
	ASSERT_ERR((((uint32_t)p3p2tranok << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)p3p2tranok <<11));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_p_3_ex_sig_p_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_gusb_3_pipectl_0_p_3_ex_sig_p_2_setf(uint8_t p3exsigp2)
{
	ASSERT_ERR((((uint32_t)p3exsigp2 << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)p3exsigp2 <<10));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_lfpsfilter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void usbc_gusb_3_pipectl_0_lfpsfilter_setf(uint8_t lfpsfilter)
{
	ASSERT_ERR((((uint32_t)lfpsfilter << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)lfpsfilter <<9));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_rx_detect_to_polling_lfps_control_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_gusb_3_pipectl_0_rx_detect_to_polling_lfps_control_setf(uint8_t rxdetecttopollinglfpscontrol)
{
	ASSERT_ERR((((uint32_t)rxdetecttopollinglfpscontrol << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)rxdetecttopollinglfpscontrol <<8));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_ssicen_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void usbc_gusb_3_pipectl_0_ssicen_setf(uint8_t ssicen)
{
	ASSERT_ERR((((uint32_t)ssicen << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)ssicen <<7));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_tx_swing_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void usbc_gusb_3_pipectl_0_tx_swing_setf(uint8_t txswing)
{
	ASSERT_ERR((((uint32_t)txswing << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)txswing <<6));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_tx_margin_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void usbc_gusb_3_pipectl_0_tx_margin_setf(uint8_t txmargin)
{
	ASSERT_ERR((((uint32_t)txmargin << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)txmargin <<3));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_ss_tx_de_emphasis_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void usbc_gusb_3_pipectl_0_ss_tx_de_emphasis_setf(uint8_t sstxdeemphasis)
{
	ASSERT_ERR((((uint32_t)sstxdeemphasis << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)sstxdeemphasis <<1));
}
__INLINE uint8_t usbc_gusb_3_pipectl_0_elastic_buffer_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void usbc_gusb_3_pipectl_0_elastic_buffer_mode_setf(uint8_t elasticbuffermode)
{
	ASSERT_ERR((((uint32_t)elasticbuffermode << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(USBC_GUSB_3_PIPECTL_0_ADDR, (REG_PL_RD(USBC_GUSB_3_PIPECTL_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)elasticbuffermode <<0));
}

/**
 * @brief GTXFIFOSIZ_0_0 register definition
 *  Global Transmit FIFO Size Register  This register specifies the RAM start address and depth (both in MDWIDTH-bit words) for each implemented TxFIFO. The number of TxFIFOs depends on the configuration parameters including the number of Device IN Endpoints, number of Host Bus Instances, and presence of Debug Capability.  The register default values for each mode are assigned in coreConsultant based on the maximum packet size, number of packets to be buffered, speed of host bus instance, bus latency, and mode of operation (host, device, or, DBC). Upon reset and mode transitions, hardware automatically programs these registers to the default values. Consequently, there is typically no need for the software to modify the pre-defined default values.  For the debug capability mode, the currently mapped EP0 IN and EP1 IN TxFIFO numbers can be read from the GFIFOPRIDBC register.   For more details on the usage of the GTXFIFOSIZn and GRXFIFOSIZn registers for different modes of operation, refer to  Memory Requirements  chapter in the Databook. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x0
 *    15:00 TXFDEP_N                  0x82
 * </pre>
 */
#define USBC_GTXFIFOSIZ_0_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C300)
#define USBC_GTXFIFOSIZ_0_0_OFFSET      0x0000C300
#define USBC_GTXFIFOSIZ_0_0_INDEX       0x000030C0
#define USBC_GTXFIFOSIZ_0_0_RESET       0x00000082

__INLINE uint32_t  usbc_gtxfifosiz_0_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_0_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_0_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_0_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_0_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_0_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_0_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_0_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_0_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_0_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_0_0_TXFSTADDR_N_RST    0x0
#define USBC_GTXFIFOSIZ_0_0_TXFDEP_N_RST    0x82

__INLINE void usbc_gtxfifosiz_0_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_0_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_0_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_0_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_0_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_0_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_0_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_0_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_0_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_0_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_0_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_0_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_0_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_0_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_1_0 register definition
 *  Register GTXFIFOSIZ 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x82
 *    15:00 TXFDEP_N                  0x304
 * </pre>
 */
#define USBC_GTXFIFOSIZ_1_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C304)
#define USBC_GTXFIFOSIZ_1_0_OFFSET      0x0000C304
#define USBC_GTXFIFOSIZ_1_0_INDEX       0x000030C1
#define USBC_GTXFIFOSIZ_1_0_RESET       0x00820304

__INLINE uint32_t  usbc_gtxfifosiz_1_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_1_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_1_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_1_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_1_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_1_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_1_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_1_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_1_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_1_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_1_0_TXFSTADDR_N_RST    0x82
#define USBC_GTXFIFOSIZ_1_0_TXFDEP_N_RST    0x304

__INLINE void usbc_gtxfifosiz_1_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_1_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_1_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_1_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_1_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_1_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_1_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_1_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_1_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_1_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_1_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_1_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_1_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_1_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_2_0 register definition
 *  Transmit FIFOn RAM Start Address   This field contains the memory start address for TxFIFOn in MDWIDTH-bit words. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x386
 *    15:00 TXFDEP_N                  0x304
 * </pre>
 */
#define USBC_GTXFIFOSIZ_2_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C308)
#define USBC_GTXFIFOSIZ_2_0_OFFSET      0x0000C308
#define USBC_GTXFIFOSIZ_2_0_INDEX       0x000030C2
#define USBC_GTXFIFOSIZ_2_0_RESET       0x03860304

__INLINE uint32_t  usbc_gtxfifosiz_2_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_2_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_2_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_2_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_2_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_2_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_2_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_2_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_2_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_2_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_2_0_TXFSTADDR_N_RST    0x386
#define USBC_GTXFIFOSIZ_2_0_TXFDEP_N_RST    0x304

__INLINE void usbc_gtxfifosiz_2_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_2_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_2_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_2_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_2_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_2_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_2_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_2_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_2_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_2_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_2_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_2_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_2_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_2_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_3_0 register definition
 *  Register GTXFIFOSIZ 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x68a
 *    15:00 TXFDEP_N                  0x304
 * </pre>
 */
#define USBC_GTXFIFOSIZ_3_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C30C)
#define USBC_GTXFIFOSIZ_3_0_OFFSET      0x0000C30C
#define USBC_GTXFIFOSIZ_3_0_INDEX       0x000030C3
#define USBC_GTXFIFOSIZ_3_0_RESET       0x068A0304

__INLINE uint32_t  usbc_gtxfifosiz_3_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_3_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_3_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_3_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_3_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_3_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_3_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_3_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_3_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_3_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_3_0_TXFSTADDR_N_RST    0x68a
#define USBC_GTXFIFOSIZ_3_0_TXFDEP_N_RST    0x304

__INLINE void usbc_gtxfifosiz_3_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_3_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_3_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_3_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_3_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_3_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_3_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_3_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_3_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_3_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_3_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_3_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_3_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_3_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_4_0 register definition
 *  Register GTXFIFOSIZ 4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x98e
 *    15:00 TXFDEP_N                  0x304
 * </pre>
 */
#define USBC_GTXFIFOSIZ_4_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C310)
#define USBC_GTXFIFOSIZ_4_0_OFFSET      0x0000C310
#define USBC_GTXFIFOSIZ_4_0_INDEX       0x000030C4
#define USBC_GTXFIFOSIZ_4_0_RESET       0x098E0304

__INLINE uint32_t  usbc_gtxfifosiz_4_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_4_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_4_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_4_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_4_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_4_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_4_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_4_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_4_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_4_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_4_0_TXFSTADDR_N_RST    0x98e
#define USBC_GTXFIFOSIZ_4_0_TXFDEP_N_RST    0x304

__INLINE void usbc_gtxfifosiz_4_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_4_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_4_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_4_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_4_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_4_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_4_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_4_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_4_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_4_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_4_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_4_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_4_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_4_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_5_0 register definition
 *  Register GTXFIFOSIZ 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0xc92
 *    15:00 TXFDEP_N                  0x304
 * </pre>
 */
#define USBC_GTXFIFOSIZ_5_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C314)
#define USBC_GTXFIFOSIZ_5_0_OFFSET      0x0000C314
#define USBC_GTXFIFOSIZ_5_0_INDEX       0x000030C5
#define USBC_GTXFIFOSIZ_5_0_RESET       0x0C920304

__INLINE uint32_t  usbc_gtxfifosiz_5_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_5_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_5_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_5_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_5_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_5_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_5_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_5_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_5_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_5_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_5_0_TXFSTADDR_N_RST    0xc92
#define USBC_GTXFIFOSIZ_5_0_TXFDEP_N_RST    0x304

__INLINE void usbc_gtxfifosiz_5_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_5_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_5_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_5_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_5_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_5_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_5_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_5_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_5_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_5_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_5_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_5_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_5_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_5_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_6_0 register definition
 *  Register GTXFIFOSIZ 6 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0xf96
 *    15:00 TXFDEP_N                  0x304
 * </pre>
 */
#define USBC_GTXFIFOSIZ_6_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C318)
#define USBC_GTXFIFOSIZ_6_0_OFFSET      0x0000C318
#define USBC_GTXFIFOSIZ_6_0_INDEX       0x000030C6
#define USBC_GTXFIFOSIZ_6_0_RESET       0x0F960304

__INLINE uint32_t  usbc_gtxfifosiz_6_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_6_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_6_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_6_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_6_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_6_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_6_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_6_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_6_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_6_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_6_0_TXFSTADDR_N_RST    0xf96
#define USBC_GTXFIFOSIZ_6_0_TXFDEP_N_RST    0x304

__INLINE void usbc_gtxfifosiz_6_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_6_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_6_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_6_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_6_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_6_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_6_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_6_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_6_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_6_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_6_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_6_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_6_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_6_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_7_0 register definition
 *  Register GTXFIFOSIZ 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x129a
 *    15:00 TXFDEP_N                  0x304
 * </pre>
 */
#define USBC_GTXFIFOSIZ_7_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C31C)
#define USBC_GTXFIFOSIZ_7_0_OFFSET      0x0000C31C
#define USBC_GTXFIFOSIZ_7_0_INDEX       0x000030C7
#define USBC_GTXFIFOSIZ_7_0_RESET       0x129A0304

__INLINE uint32_t  usbc_gtxfifosiz_7_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_7_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_7_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_7_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_7_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_7_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_7_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_7_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_7_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_7_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_7_0_TXFSTADDR_N_RST    0x129a
#define USBC_GTXFIFOSIZ_7_0_TXFDEP_N_RST    0x304

__INLINE void usbc_gtxfifosiz_7_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_7_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_7_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_7_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_7_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_7_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_7_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_7_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_7_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_7_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_7_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_7_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_7_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_7_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_8_0 register definition
 *  Register GTXFIFOSIZ 8 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x159e
 *    15:00 TXFDEP_N                  0x304
 * </pre>
 */
#define USBC_GTXFIFOSIZ_8_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C320)
#define USBC_GTXFIFOSIZ_8_0_OFFSET      0x0000C320
#define USBC_GTXFIFOSIZ_8_0_INDEX       0x000030C8
#define USBC_GTXFIFOSIZ_8_0_RESET       0x159E0304

__INLINE uint32_t  usbc_gtxfifosiz_8_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_8_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_8_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_8_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_8_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_8_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_8_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_8_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_8_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_8_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_8_0_TXFSTADDR_N_RST    0x159e
#define USBC_GTXFIFOSIZ_8_0_TXFDEP_N_RST    0x304

__INLINE void usbc_gtxfifosiz_8_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_8_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_8_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_8_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_8_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_8_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_8_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_8_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_8_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_8_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_8_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_8_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_8_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_8_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_9_0 register definition
 *  Register GTXFIFOSIZ 9 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x18a2
 *    15:00 TXFDEP_N                  0x203
 * </pre>
 */
#define USBC_GTXFIFOSIZ_9_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C324)
#define USBC_GTXFIFOSIZ_9_0_OFFSET      0x0000C324
#define USBC_GTXFIFOSIZ_9_0_INDEX       0x000030C9
#define USBC_GTXFIFOSIZ_9_0_RESET       0x18A20203

__INLINE uint32_t  usbc_gtxfifosiz_9_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_9_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_9_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_9_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_9_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_9_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_9_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_9_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_9_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_9_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_9_0_TXFSTADDR_N_RST    0x18a2
#define USBC_GTXFIFOSIZ_9_0_TXFDEP_N_RST    0x203

__INLINE void usbc_gtxfifosiz_9_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_9_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_9_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_9_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_9_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_9_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_9_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_9_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_9_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_9_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_9_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_9_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_9_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_9_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_10_0 register definition
 *  GTXFIFOSIZ 10 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x1aa5
 *    15:00 TXFDEP_N                  0x203
 * </pre>
 */
#define USBC_GTXFIFOSIZ_10_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C328)
#define USBC_GTXFIFOSIZ_10_0_OFFSET      0x0000C328
#define USBC_GTXFIFOSIZ_10_0_INDEX       0x000030CA
#define USBC_GTXFIFOSIZ_10_0_RESET       0x1AA50203

__INLINE uint32_t  usbc_gtxfifosiz_10_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_10_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_10_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_10_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_10_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_10_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_10_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_10_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_10_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_10_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_10_0_TXFSTADDR_N_RST    0x1aa5
#define USBC_GTXFIFOSIZ_10_0_TXFDEP_N_RST    0x203

__INLINE void usbc_gtxfifosiz_10_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_10_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_10_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_10_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_10_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_10_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_10_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_10_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_10_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_10_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_10_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_10_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_10_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_10_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_11_0 register definition
 *  Register GTXFIFOSIZ 11 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x1ca8
 *    15:00 TXFDEP_N                  0x203
 * </pre>
 */
#define USBC_GTXFIFOSIZ_11_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C32C)
#define USBC_GTXFIFOSIZ_11_0_OFFSET      0x0000C32C
#define USBC_GTXFIFOSIZ_11_0_INDEX       0x000030CB
#define USBC_GTXFIFOSIZ_11_0_RESET       0x1CA80203

__INLINE uint32_t  usbc_gtxfifosiz_11_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_11_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_11_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_11_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_11_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_11_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_11_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_11_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_11_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_11_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_11_0_TXFSTADDR_N_RST    0x1ca8
#define USBC_GTXFIFOSIZ_11_0_TXFDEP_N_RST    0x203

__INLINE void usbc_gtxfifosiz_11_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_11_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_11_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_11_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_11_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_11_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_11_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_11_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_11_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_11_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_11_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_11_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_11_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_11_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_12_0 register definition
 *  GTXFIFOSIZ 12 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x1eab
 *    15:00 TXFDEP_N                  0x203
 * </pre>
 */
#define USBC_GTXFIFOSIZ_12_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C330)
#define USBC_GTXFIFOSIZ_12_0_OFFSET      0x0000C330
#define USBC_GTXFIFOSIZ_12_0_INDEX       0x000030CC
#define USBC_GTXFIFOSIZ_12_0_RESET       0x1EAB0203

__INLINE uint32_t  usbc_gtxfifosiz_12_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_12_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_12_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_12_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_12_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_12_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_12_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_12_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_12_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_12_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_12_0_TXFSTADDR_N_RST    0x1eab
#define USBC_GTXFIFOSIZ_12_0_TXFDEP_N_RST    0x203

__INLINE void usbc_gtxfifosiz_12_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_12_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_12_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_12_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_12_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_12_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_12_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_12_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_12_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_12_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_12_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_12_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_12_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_12_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_13_0 register definition
 *  Register GTXFIFOSIZ 13 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x20ae
 *    15:00 TXFDEP_N                  0x203
 * </pre>
 */
#define USBC_GTXFIFOSIZ_13_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C334)
#define USBC_GTXFIFOSIZ_13_0_OFFSET      0x0000C334
#define USBC_GTXFIFOSIZ_13_0_INDEX       0x000030CD
#define USBC_GTXFIFOSIZ_13_0_RESET       0x20AE0203

__INLINE uint32_t  usbc_gtxfifosiz_13_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_13_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_13_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_13_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_13_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_13_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_13_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_13_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_13_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_13_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_13_0_TXFSTADDR_N_RST    0x20ae
#define USBC_GTXFIFOSIZ_13_0_TXFDEP_N_RST    0x203

__INLINE void usbc_gtxfifosiz_13_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_13_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_13_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_13_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_13_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_13_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_13_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_13_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_13_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_13_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_13_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_13_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_13_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_13_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_14_0 register definition
 *  Register GTXFIFOSIZ 14 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x22b1
 *    15:00 TXFDEP_N                  0x203
 * </pre>
 */
#define USBC_GTXFIFOSIZ_14_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C338)
#define USBC_GTXFIFOSIZ_14_0_OFFSET      0x0000C338
#define USBC_GTXFIFOSIZ_14_0_INDEX       0x000030CE
#define USBC_GTXFIFOSIZ_14_0_RESET       0x22B10203

__INLINE uint32_t  usbc_gtxfifosiz_14_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_14_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_14_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_14_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_14_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_14_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_14_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_14_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_14_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_14_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_14_0_TXFSTADDR_N_RST    0x22b1
#define USBC_GTXFIFOSIZ_14_0_TXFDEP_N_RST    0x203

__INLINE void usbc_gtxfifosiz_14_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_14_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_14_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_14_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_14_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_14_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_14_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_14_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_14_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_14_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_14_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_14_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_14_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_14_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GTXFIFOSIZ_15_0 register definition
 *  Register GTXFIFOSIZ 15 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TXFSTADDR_N               0x24b4
 *    15:00 TXFDEP_N                  0x203
 * </pre>
 */
#define USBC_GTXFIFOSIZ_15_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C33C)
#define USBC_GTXFIFOSIZ_15_0_OFFSET      0x0000C33C
#define USBC_GTXFIFOSIZ_15_0_INDEX       0x000030CF
#define USBC_GTXFIFOSIZ_15_0_RESET       0x24B40203

__INLINE uint32_t  usbc_gtxfifosiz_15_0_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOSIZ_15_0_ADDR);
}

__INLINE void usbc_gtxfifosiz_15_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOSIZ_15_0_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOSIZ_15_0_TXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOSIZ_15_0_TXFSTADDR_N_LSB    16
#define USBC_GTXFIFOSIZ_15_0_TXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOSIZ_15_0_TXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOSIZ_15_0_TXFDEP_N_LSB    0
#define USBC_GTXFIFOSIZ_15_0_TXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOSIZ_15_0_TXFSTADDR_N_RST    0x24b4
#define USBC_GTXFIFOSIZ_15_0_TXFDEP_N_RST    0x203

__INLINE void usbc_gtxfifosiz_15_0_pack(uint16_t txfstaddr_n, uint16_t txfdep_n)
{
	ASSERT_ERR((((uint32_t)txfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)txfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_15_0_ADDR,  ((uint32_t)txfstaddr_n << 16) |((uint32_t)txfdep_n << 0));
}

__INLINE void usbc_gtxfifosiz_15_0_unpack(uint16_t* txfstaddr_n, uint16_t* txfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_15_0_ADDR);

	*txfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*txfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifosiz_15_0_txfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_15_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_gtxfifosiz_15_0_txfstaddr_n_setf(uint16_t txfstaddrn)
{
	ASSERT_ERR((((uint32_t)txfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_15_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_15_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txfstaddrn <<16));
}
__INLINE uint16_t usbc_gtxfifosiz_15_0_txfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOSIZ_15_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifosiz_15_0_txfdep_n_setf(uint16_t txfdepn)
{
	ASSERT_ERR((((uint32_t)txfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOSIZ_15_0_ADDR, (REG_PL_RD(USBC_GTXFIFOSIZ_15_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txfdepn <<0));
}

/**
 * @brief GRXFIFOSIZ_0_0 register definition
 *  Global Receive FIFO Size Register  This register specifies the RAM start address and depth (both in MDWIDTH-bit words) for each implemented RxFIFO. The number of RxFIFOs depends on the configuration parameters including the number of Host Bus Instances and presence of Debug Capability; device mode requires only one RxFIFO.  The register default values for each mode are assigned in coreConsultant based on the maximum packet size, number of packets to be buffered, speed of the host bus instance, bus latency, and mode of operation (host, device, or DBC). Upon reset and mode transitions, hardware automatically programs these registers to the default values. Consequently, there is typically no need for the software to modify the pre-defined default values.  For the debug capability mode, the currently mapped RxFIFO number can be read from the GFIFOPRIDBC register.  For more details on the usage of the GTXFIFOSIZn and GRXFIFOSIZn registers for different modes of operation, refer to  Memory Requirements  chapter in the Databook. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RXFSTADDR_N               0x0
 *    15:00 RXFDEP_N                  0x30a
 * </pre>
 */
#define USBC_GRXFIFOSIZ_0_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C380)
#define USBC_GRXFIFOSIZ_0_0_OFFSET      0x0000C380
#define USBC_GRXFIFOSIZ_0_0_INDEX       0x000030E0
#define USBC_GRXFIFOSIZ_0_0_RESET       0x0000030A

__INLINE uint32_t  usbc_grxfifosiz_0_0_get(void)
{
	return REG_PL_RD(USBC_GRXFIFOSIZ_0_0_ADDR);
}

__INLINE void usbc_grxfifosiz_0_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GRXFIFOSIZ_0_0_ADDR, value);
}

// field definitions
#define USBC_GRXFIFOSIZ_0_0_RXFSTADDR_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GRXFIFOSIZ_0_0_RXFSTADDR_N_LSB    16
#define USBC_GRXFIFOSIZ_0_0_RXFSTADDR_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GRXFIFOSIZ_0_0_RXFDEP_N_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GRXFIFOSIZ_0_0_RXFDEP_N_LSB    0
#define USBC_GRXFIFOSIZ_0_0_RXFDEP_N_WIDTH    ((uint32_t)0x00000010)

#define USBC_GRXFIFOSIZ_0_0_RXFSTADDR_N_RST    0x0
#define USBC_GRXFIFOSIZ_0_0_RXFDEP_N_RST    0x30a

__INLINE void usbc_grxfifosiz_0_0_pack(uint16_t rxfstaddr_n, uint16_t rxfdep_n)
{
	ASSERT_ERR((((uint32_t)rxfstaddr_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rxfdep_n << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GRXFIFOSIZ_0_0_ADDR,  ((uint32_t)rxfstaddr_n << 16) |((uint32_t)rxfdep_n << 0));
}

__INLINE void usbc_grxfifosiz_0_0_unpack(uint16_t* rxfstaddr_n, uint16_t* rxfdep_n)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXFIFOSIZ_0_0_ADDR);

	*rxfstaddr_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rxfdep_n = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_grxfifosiz_0_0_rxfstaddr_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXFIFOSIZ_0_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_grxfifosiz_0_0_rxfstaddr_n_setf(uint16_t rxfstaddrn)
{
	ASSERT_ERR((((uint32_t)rxfstaddrn << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_GRXFIFOSIZ_0_0_ADDR, (REG_PL_RD(USBC_GRXFIFOSIZ_0_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxfstaddrn <<16));
}
__INLINE uint16_t usbc_grxfifosiz_0_0_rxfdep_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GRXFIFOSIZ_0_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_grxfifosiz_0_0_rxfdep_n_setf(uint16_t rxfdepn)
{
	ASSERT_ERR((((uint32_t)rxfdepn << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GRXFIFOSIZ_0_0_ADDR, (REG_PL_RD(USBC_GRXFIFOSIZ_0_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxfdepn <<0));
}

/**
 * @brief GEVNTADRLO_0 register definition
 *  Global Event Buffer Address (Low) Register  This is an alternate register for the GEVNTADRn register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVNTADRLO                 0x0
 * </pre>
 */
#define USBC_GEVNTADRLO_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C400)
#define USBC_GEVNTADRLO_0_OFFSET      0x0000C400
#define USBC_GEVNTADRLO_0_INDEX       0x00003100
#define USBC_GEVNTADRLO_0_RESET       0x00000000

__INLINE uint32_t  usbc_gevntadrlo_0_get(void)
{
	return REG_PL_RD(USBC_GEVNTADRLO_0_ADDR);
}

__INLINE void usbc_gevntadrlo_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GEVNTADRLO_0_ADDR, value);
}

// field definitions
#define USBC_GEVNTADRLO_0_EVNTADRLO_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_GEVNTADRLO_0_EVNTADRLO_LSB     0
#define USBC_GEVNTADRLO_0_EVNTADRLO_WIDTH    ((uint32_t)0x00000020)

#define USBC_GEVNTADRLO_0_EVNTADRLO_RST     0x0

__INLINE uint32_t usbc_gevntadrlo_0_evntadrlo_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GEVNTADRLO_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_gevntadrlo_0_evntadrlo_setf(uint32_t evntadrlo)
{
	ASSERT_ERR((((uint32_t)evntadrlo << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_GEVNTADRLO_0_ADDR, (uint32_t)evntadrlo << 0);
}

/**
 * @brief GEVNTADRHI_0 register definition
 *  Global Event Buffer Address (High) Register  This is an alternate register for the GEVNTADRn register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVNTADRHI                 0x0
 * </pre>
 */
#define USBC_GEVNTADRHI_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C404)
#define USBC_GEVNTADRHI_0_OFFSET      0x0000C404
#define USBC_GEVNTADRHI_0_INDEX       0x00003101
#define USBC_GEVNTADRHI_0_RESET       0x00000000

__INLINE uint32_t  usbc_gevntadrhi_0_get(void)
{
	return REG_PL_RD(USBC_GEVNTADRHI_0_ADDR);
}

__INLINE void usbc_gevntadrhi_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GEVNTADRHI_0_ADDR, value);
}

// field definitions
#define USBC_GEVNTADRHI_0_EVNTADRHI_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_GEVNTADRHI_0_EVNTADRHI_LSB     0
#define USBC_GEVNTADRHI_0_EVNTADRHI_WIDTH    ((uint32_t)0x00000020)

#define USBC_GEVNTADRHI_0_EVNTADRHI_RST     0x0

__INLINE uint32_t usbc_gevntadrhi_0_evntadrhi_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GEVNTADRHI_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_gevntadrhi_0_evntadrhi_setf(uint32_t evntadrhi)
{
	ASSERT_ERR((((uint32_t)evntadrhi << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_GEVNTADRHI_0_ADDR, (uint32_t)evntadrhi << 0);
}

/**
 * @brief GEVNTSIZ_0 register definition
 *  Global Event Buffer Size Register  This register holds the Event Buffer Size and the Event Interrupt Mask bit. During power-on initialization, software must initialize the size with the number of bytes allocated for the Event Buffer. The Event Interrupt Mask will mask the interrupt, but events are still queued. After configuration, software must preserve the Event Buffer Size value when changing the Event Interrupt Mask. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    EVNTINTRPTMASK            0              
 *    30:16 reserved_30_16            0x0
 *    15:00 EVENTSIZ                  0x0
 * </pre>
 */
#define USBC_GEVNTSIZ_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C408)
#define USBC_GEVNTSIZ_0_OFFSET      0x0000C408
#define USBC_GEVNTSIZ_0_INDEX       0x00003102
#define USBC_GEVNTSIZ_0_RESET       0x00000000

__INLINE uint32_t  usbc_gevntsiz_0_get(void)
{
	return REG_PL_RD(USBC_GEVNTSIZ_0_ADDR);
}

__INLINE void usbc_gevntsiz_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GEVNTSIZ_0_ADDR, value);
}

// field definitions
#define USBC_GEVNTSIZ_0_EVNTINTRPTMASK_BIT    ((uint32_t)0x80000000)
#define USBC_GEVNTSIZ_0_EVNTINTRPTMASK_POS    31
#define USBC_GEVNTSIZ_0_RESERVED_30_16_MASK    ((uint32_t)0x7FFF0000)
#define USBC_GEVNTSIZ_0_RESERVED_30_16_LSB    16
#define USBC_GEVNTSIZ_0_RESERVED_30_16_WIDTH    ((uint32_t)0x0000000F)
#define USBC_GEVNTSIZ_0_EVENTSIZ_MASK       ((uint32_t)0x0000FFFF)
#define USBC_GEVNTSIZ_0_EVENTSIZ_LSB        0
#define USBC_GEVNTSIZ_0_EVENTSIZ_WIDTH      ((uint32_t)0x00000010)

#define USBC_GEVNTSIZ_0_EVNTINTRPTMASK_RST    0x0
#define USBC_GEVNTSIZ_0_RESERVED_30_16_RST    0x0
#define USBC_GEVNTSIZ_0_EVENTSIZ_RST        0x0

__INLINE void usbc_gevntsiz_0_pack(uint8_t evntintrptmask, uint16_t reserved_30_16, uint16_t eventsiz)
{
	ASSERT_ERR((((uint32_t)evntintrptmask << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_30_16 << 16) & ~((uint32_t)0x7FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)eventsiz << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GEVNTSIZ_0_ADDR,  ((uint32_t)evntintrptmask << 31) |((uint32_t)reserved_30_16 << 16) |((uint32_t)eventsiz << 0));
}

__INLINE void usbc_gevntsiz_0_unpack(uint8_t* evntintrptmask, uint16_t* reserved_30_16, uint16_t* eventsiz)
{
	uint32_t localVal = REG_PL_RD(USBC_GEVNTSIZ_0_ADDR);

	*evntintrptmask = (localVal & ((uint32_t)0x80000000)) >>  31;
	*reserved_30_16 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*eventsiz = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint8_t usbc_gevntsiz_0_evntintrptmask_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GEVNTSIZ_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void usbc_gevntsiz_0_evntintrptmask_setf(uint8_t evntintrptmask)
{
	ASSERT_ERR((((uint32_t)evntintrptmask << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(USBC_GEVNTSIZ_0_ADDR, (REG_PL_RD(USBC_GEVNTSIZ_0_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)evntintrptmask <<31));
}
__INLINE uint16_t usbc_gevntsiz_0_reserved_30_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GEVNTSIZ_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE uint16_t usbc_gevntsiz_0_eventsiz_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GEVNTSIZ_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gevntsiz_0_eventsiz_setf(uint16_t eventsiz)
{
	ASSERT_ERR((((uint32_t)eventsiz << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GEVNTSIZ_0_ADDR, (REG_PL_RD(USBC_GEVNTSIZ_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)eventsiz <<0));
}

/**
 * @brief GEVNTCOUNT_0 register definition
 *  Global Event Buffer Count Register  This register holds the number of valid bytes in the Event Buffer. During initialization, software must initialize the count by writing 0 to the Event Count field. Each time the hardware writes a new event to the Event Buffer, it increments this count. Most events are four bytes, but some events may span over multiple four byte entries. Whenever the count is greater than zero and if enabled, conditions for interrupt moderation are satisfied, the hardware raises the corresponding interrupt line (depending on the EvntIntMask bit in the GEVNTSIZn register). On an interrupt, software processes one or more events out of the Event Buffer. Afterwards, software must write the Event Count field with the number of bytes it processed. If Interrupt Moderation is enabled, then software needs to clear EVNT_HANDLER_BUSY bit.   Clock crossing delays may result in the continuous assertion of the interrupt after software acknowledges the last event. Therefore, when the interrupt line is asserted, software must read the GEVNTCOUNT register and only process events if the GEVNTCOUNT is greater than 0. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    EVNT_HANDLER_BUSY         0              
 *    30:16 reserved_30_16            0x0
 *    15:00 EVNTCOUNT                 0x0
 * </pre>
 */
#define USBC_GEVNTCOUNT_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C40C)
#define USBC_GEVNTCOUNT_0_OFFSET      0x0000C40C
#define USBC_GEVNTCOUNT_0_INDEX       0x00003103
#define USBC_GEVNTCOUNT_0_RESET       0x00000000

__INLINE uint32_t  usbc_gevntcount_0_get(void)
{
	return REG_PL_RD(USBC_GEVNTCOUNT_0_ADDR);
}

__INLINE void usbc_gevntcount_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GEVNTCOUNT_0_ADDR, value);
}

// field definitions
#define USBC_GEVNTCOUNT_0_EVNT_HANDLER_BUSY_BIT    ((uint32_t)0x80000000)
#define USBC_GEVNTCOUNT_0_EVNT_HANDLER_BUSY_POS    31
#define USBC_GEVNTCOUNT_0_RESERVED_30_16_MASK    ((uint32_t)0x7FFF0000)
#define USBC_GEVNTCOUNT_0_RESERVED_30_16_LSB    16
#define USBC_GEVNTCOUNT_0_RESERVED_30_16_WIDTH    ((uint32_t)0x0000000F)
#define USBC_GEVNTCOUNT_0_EVNTCOUNT_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GEVNTCOUNT_0_EVNTCOUNT_LSB     0
#define USBC_GEVNTCOUNT_0_EVNTCOUNT_WIDTH    ((uint32_t)0x00000010)

#define USBC_GEVNTCOUNT_0_EVNT_HANDLER_BUSY_RST    0x0
#define USBC_GEVNTCOUNT_0_RESERVED_30_16_RST    0x0
#define USBC_GEVNTCOUNT_0_EVNTCOUNT_RST     0x0

__INLINE void usbc_gevntcount_0_pack(uint8_t evnt_handler_busy, uint16_t reserved_30_16, uint16_t evntcount)
{
	ASSERT_ERR((((uint32_t)evnt_handler_busy << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_30_16 << 16) & ~((uint32_t)0x7FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)evntcount << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GEVNTCOUNT_0_ADDR,  ((uint32_t)evnt_handler_busy << 31) |((uint32_t)reserved_30_16 << 16) |((uint32_t)evntcount << 0));
}

__INLINE void usbc_gevntcount_0_unpack(uint8_t* evnt_handler_busy, uint16_t* reserved_30_16, uint16_t* evntcount)
{
	uint32_t localVal = REG_PL_RD(USBC_GEVNTCOUNT_0_ADDR);

	*evnt_handler_busy = (localVal & ((uint32_t)0x80000000)) >>  31;
	*reserved_30_16 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*evntcount = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint8_t usbc_gevntcount_0_evnt_handler_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GEVNTCOUNT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void usbc_gevntcount_0_evnt_handler_busy_setf(uint8_t evnthandlerbusy)
{
	ASSERT_ERR((((uint32_t)evnthandlerbusy << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(USBC_GEVNTCOUNT_0_ADDR, (REG_PL_RD(USBC_GEVNTCOUNT_0_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)evnthandlerbusy <<31));
}
__INLINE uint16_t usbc_gevntcount_0_reserved_30_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GEVNTCOUNT_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE uint16_t usbc_gevntcount_0_evntcount_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GEVNTCOUNT_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gevntcount_0_evntcount_setf(uint16_t evntcount)
{
	ASSERT_ERR((((uint32_t)evntcount << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GEVNTCOUNT_0_ADDR, (REG_PL_RD(USBC_GEVNTCOUNT_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)evntcount <<0));
}

/**
 * @brief GHWPARAMS_8 register definition
 *  Global Hardware Parameters Register 8  This register contains the hardware configuration options that you can select in the coreConsultant GUI.    For a description of each parameter, refer to the  Parameter Descriptions  chapter in the Databook. This information is also available in coreConsultant by right-clicking the parameter label and selecting  What s This  or by clicking the Help tab.    Note:   Some of the global hardware parameters are not currently modifiable in coreConsultant. These settings are in the   workspace /src/DWC_usb3_params.v file; you must not change them. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ghwparams8_32_0           0x78c
 * </pre>
 */
#define USBC_GHWPARAMS_8_ADDR        (REG_USBC_BASE_ADDR+0x0000C600)
#define USBC_GHWPARAMS_8_OFFSET      0x0000C600
#define USBC_GHWPARAMS_8_INDEX       0x00003180
#define USBC_GHWPARAMS_8_RESET       0x0000078C

__INLINE uint32_t  usbc_ghwparams_8_get(void)
{
	return REG_PL_RD(USBC_GHWPARAMS_8_ADDR);
}

// field definitions
#define USBC_GHWPARAMS_8_GHWPARAMS_8_32_0_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_GHWPARAMS_8_GHWPARAMS_8_32_0_LSB    0
#define USBC_GHWPARAMS_8_GHWPARAMS_8_32_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_GHWPARAMS_8_GHWPARAMS_8_32_0_RST    0x78c

__INLINE uint32_t usbc_ghwparams_8_ghwparams_8_32_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GHWPARAMS_8_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief GUCTL_3 register definition
 *  Global User Control Register 3  This register provides a few options for the software to control the controller behavior in the Host mode. Most of the options are used to improve host inter-operability with different devices. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:17 reserved_31_17            0x0
 *    16    Sch_Ping_early            1              
 *    15:00 reserved_15_0             0x0
 * </pre>
 */
#define USBC_GUCTL_3_ADDR        (REG_USBC_BASE_ADDR+0x0000C60C)
#define USBC_GUCTL_3_OFFSET      0x0000C60C
#define USBC_GUCTL_3_INDEX       0x00003183
#define USBC_GUCTL_3_RESET       0x00010000

__INLINE uint32_t  usbc_guctl_3_get(void)
{
	return REG_PL_RD(USBC_GUCTL_3_ADDR);
}

__INLINE void usbc_guctl_3_set(uint32_t value)
{
	REG_PL_WR(USBC_GUCTL_3_ADDR, value);
}

// field definitions
#define USBC_GUCTL_3_RESERVED_31_17_MASK    ((uint32_t)0xFFFE0000)
#define USBC_GUCTL_3_RESERVED_31_17_LSB     17
#define USBC_GUCTL_3_RESERVED_31_17_WIDTH    ((uint32_t)0x0000000F)
#define USBC_GUCTL_3_SCH_PING_EARLY_BIT     ((uint32_t)0x00010000)
#define USBC_GUCTL_3_SCH_PING_EARLY_POS     16
#define USBC_GUCTL_3_RESERVED_15_0_MASK     ((uint32_t)0x0000FFFF)
#define USBC_GUCTL_3_RESERVED_15_0_LSB      0
#define USBC_GUCTL_3_RESERVED_15_0_WIDTH    ((uint32_t)0x00000010)

#define USBC_GUCTL_3_RESERVED_31_17_RST     0x0
#define USBC_GUCTL_3_SCH_PING_EARLY_RST     0x1
#define USBC_GUCTL_3_RESERVED_15_0_RST      0x0

__INLINE void usbc_guctl_3_pack(uint16_t reserved_31_17, uint8_t sch_ping_early, uint16_t reserved_15_0)
{
	ASSERT_ERR((((uint32_t)reserved_31_17 << 17) & ~((uint32_t)0xFFFE0000)) == 0);
	ASSERT_ERR((((uint32_t)sch_ping_early << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_15_0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GUCTL_3_ADDR,  ((uint32_t)reserved_31_17 << 17) |((uint32_t)sch_ping_early << 16) |((uint32_t)reserved_15_0 << 0));
}

__INLINE void usbc_guctl_3_unpack(uint16_t* reserved_31_17, uint8_t* sch_ping_early, uint16_t* reserved_15_0)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_3_ADDR);

	*reserved_31_17 = (localVal & ((uint32_t)0xFFFE0000)) >>  17;
	*sch_ping_early = (localVal & ((uint32_t)0x00010000)) >>  16;
	*reserved_15_0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_guctl_3_reserved_31_17_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFE0000)) >> 17);
}
__INLINE void usbc_guctl_3_reserved_31_17_setf(uint16_t reserved3117)
{
	ASSERT_ERR((((uint32_t)reserved3117 << 17) & ~((uint32_t)0xFFFE0000)) == 0);
	REG_PL_WR(USBC_GUCTL_3_ADDR, (REG_PL_RD(USBC_GUCTL_3_ADDR) & ~((uint32_t)0xFFFE0000)) | ((uint32_t)reserved3117 <<17));
}
__INLINE uint8_t usbc_guctl_3_sch_ping_early_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void usbc_guctl_3_sch_ping_early_setf(uint8_t schpingearly)
{
	ASSERT_ERR((((uint32_t)schpingearly << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(USBC_GUCTL_3_ADDR, (REG_PL_RD(USBC_GUCTL_3_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)schpingearly <<16));
}
__INLINE uint16_t usbc_guctl_3_reserved_15_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUCTL_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_guctl_3_reserved_15_0_setf(uint16_t reserved150)
{
	ASSERT_ERR((((uint32_t)reserved150 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GUCTL_3_ADDR, (REG_PL_RD(USBC_GUCTL_3_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)reserved150 <<0));
}

/**
 * @brief GTXFIFOPRIDEV register definition
 *  Global Device TX FIFO DMA Priority Register  This register specifies the relative DMA priority level among the Device TXFIFOs (one per IN endpoint). Each register bit[n] controls the priority (1: high, 0: low) of each TXFIFO[n]. When multiple TXFIFOs compete for DMA service at a given time (that is, multiple TXQs contain TX DMA requests and their corresponding TXFIFOs have space available), the TX DMA arbiter grants access on a packet-basis in the following manner:  - 1. High-priority TXFIFOs are granted access using round-robin arbitration  - 2. Low-priority TXFIFOs are granted access using round-robin arbitration only after the high-priority TXFIFOs have no further processing to do (that is, either the TXQs are empty or the corresponding TXFIFOs are full). For scatter-gather packets, the arbiter grants successive DMA requests to the same FIFO until the entire packet is completed.  When configuring periodic IN endpoints, software must set register bit[n]=1, where n is the TXFIFO assignment. This ensures that the DMA for isochronous or interrupt IN endpoints are prioritized over bulk or control IN endpoints.  This register is present only when the controller is configured to operate in the device mode (includes DRD mode). The register size corresponds to the number of Device IN endpoints.  Note  - Since the device mode uses only one RXFIFO, there is no Device RXFIFO DMA Priority Register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 reserved_31_n             0x0
 *    15:00 gtxfifopridev             0x0
 * </pre>
 */
#define USBC_GTXFIFOPRIDEV_ADDR        (REG_USBC_BASE_ADDR+0x0000C610)
#define USBC_GTXFIFOPRIDEV_OFFSET      0x0000C610
#define USBC_GTXFIFOPRIDEV_INDEX       0x00003184
#define USBC_GTXFIFOPRIDEV_RESET       0x00000000

__INLINE uint32_t  usbc_gtxfifopridev_get(void)
{
	return REG_PL_RD(USBC_GTXFIFOPRIDEV_ADDR);
}

__INLINE void usbc_gtxfifopridev_set(uint32_t value)
{
	REG_PL_WR(USBC_GTXFIFOPRIDEV_ADDR, value);
}

// field definitions
#define USBC_GTXFIFOPRIDEV_RESERVED_31_N_MASK    ((uint32_t)0xFFFF0000)
#define USBC_GTXFIFOPRIDEV_RESERVED_31_N_LSB    16
#define USBC_GTXFIFOPRIDEV_RESERVED_31_N_WIDTH    ((uint32_t)0x00000010)
#define USBC_GTXFIFOPRIDEV_GTXFIFOPRIDEV_MASK    ((uint32_t)0x0000FFFF)
#define USBC_GTXFIFOPRIDEV_GTXFIFOPRIDEV_LSB    0
#define USBC_GTXFIFOPRIDEV_GTXFIFOPRIDEV_WIDTH    ((uint32_t)0x00000010)

#define USBC_GTXFIFOPRIDEV_RESERVED_31_N_RST    0x0
#define USBC_GTXFIFOPRIDEV_GTXFIFOPRIDEV_RST    0x0

__INLINE void usbc_gtxfifopridev_pack(uint16_t reserved_31_n, uint16_t gtxfifopridev)
{
	ASSERT_ERR((((uint32_t)reserved_31_n << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)gtxfifopridev << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOPRIDEV_ADDR,  ((uint32_t)reserved_31_n << 16) |((uint32_t)gtxfifopridev << 0));
}

__INLINE void usbc_gtxfifopridev_unpack(uint16_t* reserved_31_n, uint16_t* gtxfifopridev)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOPRIDEV_ADDR);

	*reserved_31_n = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*gtxfifopridev = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_gtxfifopridev_reserved_31_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOPRIDEV_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t usbc_gtxfifopridev_gtxfifopridev_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GTXFIFOPRIDEV_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_gtxfifopridev_gtxfifopridev_setf(uint16_t gtxfifopridev)
{
	ASSERT_ERR((((uint32_t)gtxfifopridev << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_GTXFIFOPRIDEV_ADDR, (REG_PL_RD(USBC_GTXFIFOPRIDEV_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)gtxfifopridev <<0));
}

/**
 * @brief GFLADJ register definition
 *  Global Frame Length Adjustment Register  This register provides options for the software to control the controller behavior with respect to SOF (Start of Frame) and ITP (Isochronous Timestamp Packet) timers and frame timer functionality. It provides an option to override the fladj_30mhz_reg sideband signal. In addition, it enables running SOF or ITP frame timer counters completely from the ref_clk. This facilitates hardware LPM in host mode with the SOF or ITP counters being run from the ref_clk signal. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    GFLADJ_REFCLK_240_MHZDECR_PLS1 0              
 *    30:24 GFLADJ_REFCLK_240_MHZ_DECR 0x0
 *    23    GFLADJ_REFCLK_LPM_SEL     0              
 *    22    reserved_22               0              
 *    21:08 GFLADJ_REFCLK_FLADJ       0x0
 *    07    GFLADJ_30_MHZ_SDBND_SEL   0              
 *    06    reserved_6                0              
 *    05:00 GFLADJ_30_MHZ             0x0
 * </pre>
 */
#define USBC_GFLADJ_ADDR        (REG_USBC_BASE_ADDR+0x0000C630)
#define USBC_GFLADJ_OFFSET      0x0000C630
#define USBC_GFLADJ_INDEX       0x0000318C
#define USBC_GFLADJ_RESET       0x00000000

__INLINE uint32_t  usbc_gfladj_get(void)
{
	return REG_PL_RD(USBC_GFLADJ_ADDR);
}

__INLINE void usbc_gfladj_set(uint32_t value)
{
	REG_PL_WR(USBC_GFLADJ_ADDR, value);
}

// field definitions
#define USBC_GFLADJ_GFLADJ_REFCLK_240_MHZDECR_PLS_1_BIT    ((uint32_t)0x80000000)
#define USBC_GFLADJ_GFLADJ_REFCLK_240_MHZDECR_PLS_1_POS    31
#define USBC_GFLADJ_GFLADJ_REFCLK_240_MHZ_DECR_MASK    ((uint32_t)0x7F000000)
#define USBC_GFLADJ_GFLADJ_REFCLK_240_MHZ_DECR_LSB    24
#define USBC_GFLADJ_GFLADJ_REFCLK_240_MHZ_DECR_WIDTH    ((uint32_t)0x00000007)
#define USBC_GFLADJ_GFLADJ_REFCLK_LPM_SEL_BIT    ((uint32_t)0x00800000)
#define USBC_GFLADJ_GFLADJ_REFCLK_LPM_SEL_POS    23
#define USBC_GFLADJ_RESERVED_22_BIT         ((uint32_t)0x00400000)
#define USBC_GFLADJ_RESERVED_22_POS         22
#define USBC_GFLADJ_GFLADJ_REFCLK_FLADJ_MASK    ((uint32_t)0x003FFF00)
#define USBC_GFLADJ_GFLADJ_REFCLK_FLADJ_LSB    8
#define USBC_GFLADJ_GFLADJ_REFCLK_FLADJ_WIDTH    ((uint32_t)0x0000000E)
#define USBC_GFLADJ_GFLADJ_30_MHZ_SDBND_SEL_BIT    ((uint32_t)0x00000080)
#define USBC_GFLADJ_GFLADJ_30_MHZ_SDBND_SEL_POS    7
#define USBC_GFLADJ_RESERVED_6_BIT          ((uint32_t)0x00000040)
#define USBC_GFLADJ_RESERVED_6_POS          6
#define USBC_GFLADJ_GFLADJ_30_MHZ_MASK      ((uint32_t)0x0000003F)
#define USBC_GFLADJ_GFLADJ_30_MHZ_LSB       0
#define USBC_GFLADJ_GFLADJ_30_MHZ_WIDTH     ((uint32_t)0x00000006)

#define USBC_GFLADJ_GFLADJ_REFCLK_240_MHZDECR_PLS_1_RST    0x0
#define USBC_GFLADJ_GFLADJ_REFCLK_240_MHZ_DECR_RST    0x0
#define USBC_GFLADJ_GFLADJ_REFCLK_LPM_SEL_RST    0x0
#define USBC_GFLADJ_RESERVED_22_RST         0x0
#define USBC_GFLADJ_GFLADJ_REFCLK_FLADJ_RST    0x0
#define USBC_GFLADJ_GFLADJ_30_MHZ_SDBND_SEL_RST    0x0
#define USBC_GFLADJ_RESERVED_6_RST          0x0
#define USBC_GFLADJ_GFLADJ_30_MHZ_RST       0x0

__INLINE void usbc_gfladj_pack(uint8_t gfladj_refclk_240_mhzdecr_pls1, uint8_t gfladj_refclk_240_mhz_decr, uint8_t gfladj_refclk_lpm_sel, uint8_t reserved_22, uint16_t gfladj_refclk_fladj, uint8_t gfladj_30_mhz_sdbnd_sel, uint8_t reserved_6, uint8_t gfladj_30_mhz)
{
	ASSERT_ERR((((uint32_t)gfladj_refclk_240_mhzdecr_pls1 << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)gfladj_refclk_240_mhz_decr << 24) & ~((uint32_t)0x7F000000)) == 0);
	ASSERT_ERR((((uint32_t)gfladj_refclk_lpm_sel << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_22 << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)gfladj_refclk_fladj << 8) & ~((uint32_t)0x003FFF00)) == 0);
	ASSERT_ERR((((uint32_t)gfladj_30_mhz_sdbnd_sel << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)reserved_6 << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)gfladj_30_mhz << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(USBC_GFLADJ_ADDR,  ((uint32_t)gfladj_refclk_240_mhzdecr_pls1 << 31) |((uint32_t)gfladj_refclk_240_mhz_decr << 24) |((uint32_t)gfladj_refclk_lpm_sel << 23) |((uint32_t)reserved_22 << 22) |((uint32_t)gfladj_refclk_fladj << 8) |((uint32_t)gfladj_30_mhz_sdbnd_sel << 7) |((uint32_t)reserved_6 << 6) |((uint32_t)gfladj_30_mhz << 0));
}

__INLINE void usbc_gfladj_unpack(uint8_t* gfladj_refclk_240_mhzdecr_pls1, uint8_t* gfladj_refclk_240_mhz_decr, uint8_t* gfladj_refclk_lpm_sel, uint8_t* reserved_22, uint16_t* gfladj_refclk_fladj, uint8_t* gfladj_30_mhz_sdbnd_sel, uint8_t* reserved_6, uint8_t* gfladj_30_mhz)
{
	uint32_t localVal = REG_PL_RD(USBC_GFLADJ_ADDR);

	*gfladj_refclk_240_mhzdecr_pls1 = (localVal & ((uint32_t)0x80000000)) >>  31;
	*gfladj_refclk_240_mhz_decr = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*gfladj_refclk_lpm_sel = (localVal & ((uint32_t)0x00800000)) >>  23;
	*reserved_22 = (localVal & ((uint32_t)0x00400000)) >>  22;
	*gfladj_refclk_fladj = (localVal & ((uint32_t)0x003FFF00)) >>  8;
	*gfladj_30_mhz_sdbnd_sel = (localVal & ((uint32_t)0x00000080)) >>  7;
	*reserved_6 = (localVal & ((uint32_t)0x00000040)) >>  6;
	*gfladj_30_mhz = (localVal & ((uint32_t)0x0000003F)) >>  0;
}

__INLINE uint8_t usbc_gfladj_gfladj_refclk_240_mhzdecr_pls_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GFLADJ_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void usbc_gfladj_gfladj_refclk_240_mhzdecr_pls_1_setf(uint8_t gfladjrefclk240mhzdecrpls1)
{
	ASSERT_ERR((((uint32_t)gfladjrefclk240mhzdecrpls1 << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(USBC_GFLADJ_ADDR, (REG_PL_RD(USBC_GFLADJ_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)gfladjrefclk240mhzdecrpls1 <<31));
}
__INLINE uint8_t usbc_gfladj_gfladj_refclk_240_mhz_decr_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GFLADJ_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE void usbc_gfladj_gfladj_refclk_240_mhz_decr_setf(uint8_t gfladjrefclk240mhzdecr)
{
	ASSERT_ERR((((uint32_t)gfladjrefclk240mhzdecr << 24) & ~((uint32_t)0x7F000000)) == 0);
	REG_PL_WR(USBC_GFLADJ_ADDR, (REG_PL_RD(USBC_GFLADJ_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)gfladjrefclk240mhzdecr <<24));
}
__INLINE uint8_t usbc_gfladj_gfladj_refclk_lpm_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GFLADJ_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void usbc_gfladj_gfladj_refclk_lpm_sel_setf(uint8_t gfladjrefclklpmsel)
{
	ASSERT_ERR((((uint32_t)gfladjrefclklpmsel << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(USBC_GFLADJ_ADDR, (REG_PL_RD(USBC_GFLADJ_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)gfladjrefclklpmsel <<23));
}
__INLINE uint8_t usbc_gfladj_reserved_22_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GFLADJ_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint16_t usbc_gfladj_gfladj_refclk_fladj_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GFLADJ_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x003FFF00)) >> 8);
}
__INLINE void usbc_gfladj_gfladj_refclk_fladj_setf(uint16_t gfladjrefclkfladj)
{
	ASSERT_ERR((((uint32_t)gfladjrefclkfladj << 8) & ~((uint32_t)0x003FFF00)) == 0);
	REG_PL_WR(USBC_GFLADJ_ADDR, (REG_PL_RD(USBC_GFLADJ_ADDR) & ~((uint32_t)0x003FFF00)) | ((uint32_t)gfladjrefclkfladj <<8));
}
__INLINE uint8_t usbc_gfladj_gfladj_30_mhz_sdbnd_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GFLADJ_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void usbc_gfladj_gfladj_30_mhz_sdbnd_sel_setf(uint8_t gfladj30mhzsdbndsel)
{
	ASSERT_ERR((((uint32_t)gfladj30mhzsdbndsel << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(USBC_GFLADJ_ADDR, (REG_PL_RD(USBC_GFLADJ_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)gfladj30mhzsdbndsel <<7));
}
__INLINE uint8_t usbc_gfladj_reserved_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GFLADJ_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t usbc_gfladj_gfladj_30_mhz_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GFLADJ_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003F)) >> 0);
}
__INLINE void usbc_gfladj_gfladj_30_mhz_setf(uint8_t gfladj30mhz)
{
	ASSERT_ERR((((uint32_t)gfladj30mhz << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(USBC_GFLADJ_ADDR, (REG_PL_RD(USBC_GFLADJ_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)gfladj30mhz <<0));
}

/**
 * @brief GUSB_2_RHBCTL_0 register definition
 *  Global USB 2.0 Root Hub Control Register  The application must program this register before starting any transactions on the USB if a non-default value is desired.  In Device-only configurations, only one register is needed.  In Host mode, per-port registers are implemented. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:04 Reserved_31_4             0x0
 *    03:00 OVRD_L1_TIMEOUT           0x0
 * </pre>
 */
#define USBC_GUSB_2_RHBCTL_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C640)
#define USBC_GUSB_2_RHBCTL_0_OFFSET      0x0000C640
#define USBC_GUSB_2_RHBCTL_0_INDEX       0x00003190
#define USBC_GUSB_2_RHBCTL_0_RESET       0x00000000

__INLINE uint32_t  usbc_gusb_2_rhbctl_0_get(void)
{
	return REG_PL_RD(USBC_GUSB_2_RHBCTL_0_ADDR);
}

__INLINE void usbc_gusb_2_rhbctl_0_set(uint32_t value)
{
	REG_PL_WR(USBC_GUSB_2_RHBCTL_0_ADDR, value);
}

// field definitions
#define USBC_GUSB_2_RHBCTL_0_RESERVED_31_4_MASK    ((uint32_t)0xFFFFFFF0)
#define USBC_GUSB_2_RHBCTL_0_RESERVED_31_4_LSB    4
#define USBC_GUSB_2_RHBCTL_0_RESERVED_31_4_WIDTH    ((uint32_t)0x0000001C)
#define USBC_GUSB_2_RHBCTL_0_OVRD_L_1_TIMEOUT_MASK    ((uint32_t)0x0000000F)
#define USBC_GUSB_2_RHBCTL_0_OVRD_L_1_TIMEOUT_LSB    0
#define USBC_GUSB_2_RHBCTL_0_OVRD_L_1_TIMEOUT_WIDTH    ((uint32_t)0x00000004)

#define USBC_GUSB_2_RHBCTL_0_RESERVED_31_4_RST    0x0
#define USBC_GUSB_2_RHBCTL_0_OVRD_L_1_TIMEOUT_RST    0x0

__INLINE void usbc_gusb_2_rhbctl_0_pack(uint32_t reserved_31_4, uint8_t ovrd_l1_timeout)
{
	ASSERT_ERR((((uint32_t)reserved_31_4 << 4) & ~((uint32_t)0xFFFFFFF0)) == 0);
	ASSERT_ERR((((uint32_t)ovrd_l1_timeout << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GUSB_2_RHBCTL_0_ADDR,  ((uint32_t)reserved_31_4 << 4) |((uint32_t)ovrd_l1_timeout << 0));
}

__INLINE void usbc_gusb_2_rhbctl_0_unpack(uint32_t* reserved_31_4, uint8_t* ovrd_l1_timeout)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_RHBCTL_0_ADDR);

	*reserved_31_4 = (localVal & ((uint32_t)0xFFFFFFF0)) >>  4;
	*ovrd_l1_timeout = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint32_t usbc_gusb_2_rhbctl_0_reserved_31_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_RHBCTL_0_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFFFF0)) >> 4);
}
__INLINE uint8_t usbc_gusb_2_rhbctl_0_ovrd_l_1_timeout_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_GUSB_2_RHBCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_gusb_2_rhbctl_0_ovrd_l_1_timeout_setf(uint8_t ovrdl1timeout)
{
	ASSERT_ERR((((uint32_t)ovrdl1timeout << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_GUSB_2_RHBCTL_0_ADDR, (REG_PL_RD(USBC_GUSB_2_RHBCTL_0_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)ovrdl1timeout <<0));
}

/**
 * @brief DCFG register definition
 *  Device Configuration Register.   This register configures the controller in Device mode after power-on or after certain control commands or enumeration. Do not make changes to this register after initial programming. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 reserved_31_25            0x0
 *    24    reserved_24               0              
 *    23    Ign_Strm_PP               0              
 *    22    LPMCAP                    0              
 *    21:17 NUMP                      0x4
 *    16:12 INTRNUM                   0x0
 *    11:10 reserved_10_11            0x2
 *    09:03 DEVADDR                   0x0
 *    02:00 DEVSPD                    0x4
 * </pre>
 */
#define USBC_DCFG_ADDR        (REG_USBC_BASE_ADDR+0x0000C700)
#define USBC_DCFG_OFFSET      0x0000C700
#define USBC_DCFG_INDEX       0x000031C0
#define USBC_DCFG_RESET       0x00080804

__INLINE uint32_t  usbc_dcfg_get(void)
{
	return REG_PL_RD(USBC_DCFG_ADDR);
}

__INLINE void usbc_dcfg_set(uint32_t value)
{
	REG_PL_WR(USBC_DCFG_ADDR, value);
}

// field definitions
#define USBC_DCFG_RESERVED_31_25_MASK       ((uint32_t)0xFE000000)
#define USBC_DCFG_RESERVED_31_25_LSB        25
#define USBC_DCFG_RESERVED_31_25_WIDTH      ((uint32_t)0x00000007)
#define USBC_DCFG_RESERVED_24_BIT           ((uint32_t)0x01000000)
#define USBC_DCFG_RESERVED_24_POS           24
#define USBC_DCFG_IGN_STRM_PP_BIT           ((uint32_t)0x00800000)
#define USBC_DCFG_IGN_STRM_PP_POS           23
#define USBC_DCFG_LPMCAP_BIT                ((uint32_t)0x00400000)
#define USBC_DCFG_LPMCAP_POS                22
#define USBC_DCFG_NUMP_MASK                 ((uint32_t)0x003E0000)
#define USBC_DCFG_NUMP_LSB                  17
#define USBC_DCFG_NUMP_WIDTH                ((uint32_t)0x00000005)
#define USBC_DCFG_INTRNUM_MASK              ((uint32_t)0x0001F000)
#define USBC_DCFG_INTRNUM_LSB               12
#define USBC_DCFG_INTRNUM_WIDTH             ((uint32_t)0x00000005)
#define USBC_DCFG_RESERVED_10_11_MASK       ((uint32_t)0x00000C00)
#define USBC_DCFG_RESERVED_10_11_LSB        10
#define USBC_DCFG_RESERVED_10_11_WIDTH      ((uint32_t)0x00000002)
#define USBC_DCFG_DEVADDR_MASK              ((uint32_t)0x000003F8)
#define USBC_DCFG_DEVADDR_LSB               3
#define USBC_DCFG_DEVADDR_WIDTH             ((uint32_t)0x00000007)
#define USBC_DCFG_DEVSPD_MASK               ((uint32_t)0x00000007)
#define USBC_DCFG_DEVSPD_LSB                0
#define USBC_DCFG_DEVSPD_WIDTH              ((uint32_t)0x00000003)

#define USBC_DCFG_RESERVED_31_25_RST        0x0
#define USBC_DCFG_RESERVED_24_RST           0x0
#define USBC_DCFG_IGN_STRM_PP_RST           0x0
#define USBC_DCFG_LPMCAP_RST                0x0
#define USBC_DCFG_NUMP_RST                  0x4
#define USBC_DCFG_INTRNUM_RST               0x0
#define USBC_DCFG_RESERVED_10_11_RST        0x2
#define USBC_DCFG_DEVADDR_RST               0x0
#define USBC_DCFG_DEVSPD_RST                0x4

__INLINE void usbc_dcfg_pack(uint8_t reserved_31_25, uint8_t reserved_24, uint8_t ign_strm_pp, uint8_t lpmcap, uint8_t nump, uint8_t intrnum, uint8_t reserved_10_11, uint8_t devaddr, uint8_t devspd)
{
	ASSERT_ERR((((uint32_t)reserved_31_25 << 25) & ~((uint32_t)0xFE000000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_24 << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)ign_strm_pp << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)lpmcap << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)nump << 17) & ~((uint32_t)0x003E0000)) == 0);
	ASSERT_ERR((((uint32_t)intrnum << 12) & ~((uint32_t)0x0001F000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_10_11 << 10) & ~((uint32_t)0x00000C00)) == 0);
	ASSERT_ERR((((uint32_t)devaddr << 3) & ~((uint32_t)0x000003F8)) == 0);
	ASSERT_ERR((((uint32_t)devspd << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(USBC_DCFG_ADDR,  ((uint32_t)reserved_31_25 << 25) |((uint32_t)reserved_24 << 24) |((uint32_t)ign_strm_pp << 23) |((uint32_t)lpmcap << 22) |((uint32_t)nump << 17) |((uint32_t)intrnum << 12) |((uint32_t)reserved_10_11 << 10) |((uint32_t)devaddr << 3) |((uint32_t)devspd << 0));
}

__INLINE void usbc_dcfg_unpack(uint8_t* reserved_31_25, uint8_t* reserved_24, uint8_t* ign_strm_pp, uint8_t* lpmcap, uint8_t* nump, uint8_t* intrnum, uint8_t* reserved_10_11, uint8_t* devaddr, uint8_t* devspd)
{
	uint32_t localVal = REG_PL_RD(USBC_DCFG_ADDR);

	*reserved_31_25 = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*reserved_24 = (localVal & ((uint32_t)0x01000000)) >>  24;
	*ign_strm_pp = (localVal & ((uint32_t)0x00800000)) >>  23;
	*lpmcap = (localVal & ((uint32_t)0x00400000)) >>  22;
	*nump = (localVal & ((uint32_t)0x003E0000)) >>  17;
	*intrnum = (localVal & ((uint32_t)0x0001F000)) >>  12;
	*reserved_10_11 = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*devaddr = (localVal & ((uint32_t)0x000003F8)) >>  3;
	*devspd = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t usbc_dcfg_reserved_31_25_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint8_t usbc_dcfg_reserved_24_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE uint8_t usbc_dcfg_ign_strm_pp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void usbc_dcfg_ign_strm_pp_setf(uint8_t ignstrmpp)
{
	ASSERT_ERR((((uint32_t)ignstrmpp << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(USBC_DCFG_ADDR, (REG_PL_RD(USBC_DCFG_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)ignstrmpp <<23));
}
__INLINE uint8_t usbc_dcfg_lpmcap_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void usbc_dcfg_lpmcap_setf(uint8_t lpmcap)
{
	ASSERT_ERR((((uint32_t)lpmcap << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(USBC_DCFG_ADDR, (REG_PL_RD(USBC_DCFG_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)lpmcap <<22));
}
__INLINE uint8_t usbc_dcfg_nump_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003E0000)) >> 17);
}
__INLINE void usbc_dcfg_nump_setf(uint8_t nump)
{
	ASSERT_ERR((((uint32_t)nump << 17) & ~((uint32_t)0x003E0000)) == 0);
	REG_PL_WR(USBC_DCFG_ADDR, (REG_PL_RD(USBC_DCFG_ADDR) & ~((uint32_t)0x003E0000)) | ((uint32_t)nump <<17));
}
__INLINE uint8_t usbc_dcfg_intrnum_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0001F000)) >> 12);
}
__INLINE void usbc_dcfg_intrnum_setf(uint8_t intrnum)
{
	ASSERT_ERR((((uint32_t)intrnum << 12) & ~((uint32_t)0x0001F000)) == 0);
	REG_PL_WR(USBC_DCFG_ADDR, (REG_PL_RD(USBC_DCFG_ADDR) & ~((uint32_t)0x0001F000)) | ((uint32_t)intrnum <<12));
}
__INLINE uint8_t usbc_dcfg_reserved_10_11_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE uint8_t usbc_dcfg_devaddr_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003F8)) >> 3);
}
__INLINE void usbc_dcfg_devaddr_setf(uint8_t devaddr)
{
	ASSERT_ERR((((uint32_t)devaddr << 3) & ~((uint32_t)0x000003F8)) == 0);
	REG_PL_WR(USBC_DCFG_ADDR, (REG_PL_RD(USBC_DCFG_ADDR) & ~((uint32_t)0x000003F8)) | ((uint32_t)devaddr <<3));
}
__INLINE uint8_t usbc_dcfg_devspd_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void usbc_dcfg_devspd_setf(uint8_t devspd)
{
	ASSERT_ERR((((uint32_t)devspd << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(USBC_DCFG_ADDR, (REG_PL_RD(USBC_DCFG_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)devspd <<0));
}

/**
 * @brief DCTL register definition
 *  Device Control Register  Note:  When Hibernation is not enabled using GCTL.GblHibernationEn field,  - you can write any value to CSS, CRS, L1HibernationEn, and KeepConnect fields  - L1HibernationEn, and KeepConnect fields always return 0 when read in this hibernation-disabled state register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    RUN_STOP                  0              
 *    30    CSFTRST                   0              
 *    29    reserved_29               0              
 *    28:24 HIRDTHRES                 0x0
 *    23:20 LPM_NYET_thres            0xf
 *    19    Keep_Connect              0              
 *    18    L1_Hibernation_En         0              
 *    17    CRS                       0              
 *    16    CSS                       0              
 *    15:13 reserved_15_13            0x0
 *    12    INITU2_ENA                0              
 *    11    ACCEPTU2_ENA              0              
 *    10    INITU1_ENA                0              
 *    09    ACCEPTU1_ENA              0              
 *    08:05 ULSTCHNGREQ               0x0
 *    04:01 TSTCTL                    0x0
 *    00    reserved_0                0              
 * </pre>
 */
#define USBC_DCTL_ADDR        (REG_USBC_BASE_ADDR+0x0000C704)
#define USBC_DCTL_OFFSET      0x0000C704
#define USBC_DCTL_INDEX       0x000031C1
#define USBC_DCTL_RESET       0x00F00000

__INLINE uint32_t  usbc_dctl_get(void)
{
	return REG_PL_RD(USBC_DCTL_ADDR);
}

__INLINE void usbc_dctl_set(uint32_t value)
{
	REG_PL_WR(USBC_DCTL_ADDR, value);
}

// field definitions
#define USBC_DCTL_RUN_STOP_BIT              ((uint32_t)0x80000000)
#define USBC_DCTL_RUN_STOP_POS              31
#define USBC_DCTL_CSFTRST_BIT               ((uint32_t)0x40000000)
#define USBC_DCTL_CSFTRST_POS               30
#define USBC_DCTL_RESERVED_29_BIT           ((uint32_t)0x20000000)
#define USBC_DCTL_RESERVED_29_POS           29
#define USBC_DCTL_HIRDTHRES_MASK            ((uint32_t)0x1F000000)
#define USBC_DCTL_HIRDTHRES_LSB             24
#define USBC_DCTL_HIRDTHRES_WIDTH           ((uint32_t)0x00000005)
#define USBC_DCTL_LPM_NYET_THRES_MASK       ((uint32_t)0x00F00000)
#define USBC_DCTL_LPM_NYET_THRES_LSB        20
#define USBC_DCTL_LPM_NYET_THRES_WIDTH      ((uint32_t)0x00000004)
#define USBC_DCTL_KEEP_CONNECT_BIT          ((uint32_t)0x00080000)
#define USBC_DCTL_KEEP_CONNECT_POS          19
#define USBC_DCTL_L_1_HIBERNATION_EN_BIT    ((uint32_t)0x00040000)
#define USBC_DCTL_L_1_HIBERNATION_EN_POS    18
#define USBC_DCTL_CRS_BIT                   ((uint32_t)0x00020000)
#define USBC_DCTL_CRS_POS                   17
#define USBC_DCTL_CSS_BIT                   ((uint32_t)0x00010000)
#define USBC_DCTL_CSS_POS                   16
#define USBC_DCTL_RESERVED_15_13_MASK       ((uint32_t)0x0000E000)
#define USBC_DCTL_RESERVED_15_13_LSB        13
#define USBC_DCTL_RESERVED_15_13_WIDTH      ((uint32_t)0x00000003)
#define USBC_DCTL_INITU_2_ENA_BIT           ((uint32_t)0x00001000)
#define USBC_DCTL_INITU_2_ENA_POS           12
#define USBC_DCTL_ACCEPTU_2_ENA_BIT         ((uint32_t)0x00000800)
#define USBC_DCTL_ACCEPTU_2_ENA_POS         11
#define USBC_DCTL_INITU_1_ENA_BIT           ((uint32_t)0x00000400)
#define USBC_DCTL_INITU_1_ENA_POS           10
#define USBC_DCTL_ACCEPTU_1_ENA_BIT         ((uint32_t)0x00000200)
#define USBC_DCTL_ACCEPTU_1_ENA_POS         9
#define USBC_DCTL_ULSTCHNGREQ_MASK          ((uint32_t)0x000001E0)
#define USBC_DCTL_ULSTCHNGREQ_LSB           5
#define USBC_DCTL_ULSTCHNGREQ_WIDTH         ((uint32_t)0x00000004)
#define USBC_DCTL_TSTCTL_MASK               ((uint32_t)0x0000001E)
#define USBC_DCTL_TSTCTL_LSB                1
#define USBC_DCTL_TSTCTL_WIDTH              ((uint32_t)0x00000004)
#define USBC_DCTL_RESERVED_0_BIT            ((uint32_t)0x00000001)
#define USBC_DCTL_RESERVED_0_POS            0

#define USBC_DCTL_RUN_STOP_RST              0x0
#define USBC_DCTL_CSFTRST_RST               0x0
#define USBC_DCTL_RESERVED_29_RST           0x0
#define USBC_DCTL_HIRDTHRES_RST             0x0
#define USBC_DCTL_LPM_NYET_THRES_RST        0xf
#define USBC_DCTL_KEEP_CONNECT_RST          0x0
#define USBC_DCTL_L_1_HIBERNATION_EN_RST    0x0
#define USBC_DCTL_CRS_RST                   0x0
#define USBC_DCTL_CSS_RST                   0x0
#define USBC_DCTL_RESERVED_15_13_RST        0x0
#define USBC_DCTL_INITU_2_ENA_RST           0x0
#define USBC_DCTL_ACCEPTU_2_ENA_RST         0x0
#define USBC_DCTL_INITU_1_ENA_RST           0x0
#define USBC_DCTL_ACCEPTU_1_ENA_RST         0x0
#define USBC_DCTL_ULSTCHNGREQ_RST           0x0
#define USBC_DCTL_TSTCTL_RST                0x0
#define USBC_DCTL_RESERVED_0_RST            0x0

__INLINE void usbc_dctl_pack(uint8_t run_stop, uint8_t csftrst, uint8_t reserved_29, uint8_t hirdthres, uint8_t lpm_nyet_thres, uint8_t keep_connect, uint8_t l1_hibernation_en, uint8_t crs, uint8_t css, uint8_t reserved_15_13, uint8_t initu2_ena, uint8_t acceptu2_ena, uint8_t initu1_ena, uint8_t acceptu1_ena, uint8_t ulstchngreq, uint8_t tstctl, uint8_t reserved_0)
{
	ASSERT_ERR((((uint32_t)run_stop << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)csftrst << 30) & ~((uint32_t)0x40000000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_29 << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)hirdthres << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)lpm_nyet_thres << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)keep_connect << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)l1_hibernation_en << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)crs << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)css << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_15_13 << 13) & ~((uint32_t)0x0000E000)) == 0);
	ASSERT_ERR((((uint32_t)initu2_ena << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)acceptu2_ena << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)initu1_ena << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)acceptu1_ena << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)ulstchngreq << 5) & ~((uint32_t)0x000001E0)) == 0);
	ASSERT_ERR((((uint32_t)tstctl << 1) & ~((uint32_t)0x0000001E)) == 0);
	ASSERT_ERR((((uint32_t)reserved_0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR,  ((uint32_t)run_stop << 31) |((uint32_t)csftrst << 30) |((uint32_t)reserved_29 << 29) |((uint32_t)hirdthres << 24) |((uint32_t)lpm_nyet_thres << 20) |((uint32_t)keep_connect << 19) |((uint32_t)l1_hibernation_en << 18) |((uint32_t)crs << 17) |((uint32_t)css << 16) |((uint32_t)reserved_15_13 << 13) |((uint32_t)initu2_ena << 12) |((uint32_t)acceptu2_ena << 11) |((uint32_t)initu1_ena << 10) |((uint32_t)acceptu1_ena << 9) |((uint32_t)ulstchngreq << 5) |((uint32_t)tstctl << 1) |((uint32_t)reserved_0 << 0));
}

__INLINE void usbc_dctl_unpack(uint8_t* run_stop, uint8_t* csftrst, uint8_t* reserved_29, uint8_t* hirdthres, uint8_t* lpm_nyet_thres, uint8_t* keep_connect, uint8_t* l1_hibernation_en, uint8_t* crs, uint8_t* css, uint8_t* reserved_15_13, uint8_t* initu2_ena, uint8_t* acceptu2_ena, uint8_t* initu1_ena, uint8_t* acceptu1_ena, uint8_t* ulstchngreq, uint8_t* tstctl, uint8_t* reserved_0)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);

	*run_stop = (localVal & ((uint32_t)0x80000000)) >>  31;
	*csftrst = (localVal & ((uint32_t)0x40000000)) >>  30;
	*reserved_29 = (localVal & ((uint32_t)0x20000000)) >>  29;
	*hirdthres = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*lpm_nyet_thres = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*keep_connect = (localVal & ((uint32_t)0x00080000)) >>  19;
	*l1_hibernation_en = (localVal & ((uint32_t)0x00040000)) >>  18;
	*crs = (localVal & ((uint32_t)0x00020000)) >>  17;
	*css = (localVal & ((uint32_t)0x00010000)) >>  16;
	*reserved_15_13 = (localVal & ((uint32_t)0x0000E000)) >>  13;
	*initu2_ena = (localVal & ((uint32_t)0x00001000)) >>  12;
	*acceptu2_ena = (localVal & ((uint32_t)0x00000800)) >>  11;
	*initu1_ena = (localVal & ((uint32_t)0x00000400)) >>  10;
	*acceptu1_ena = (localVal & ((uint32_t)0x00000200)) >>  9;
	*ulstchngreq = (localVal & ((uint32_t)0x000001E0)) >>  5;
	*tstctl = (localVal & ((uint32_t)0x0000001E)) >>  1;
	*reserved_0 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t usbc_dctl_run_stop_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void usbc_dctl_run_stop_setf(uint8_t runstop)
{
	ASSERT_ERR((((uint32_t)runstop << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)runstop <<31));
}
__INLINE uint8_t usbc_dctl_csftrst_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE void usbc_dctl_csftrst_setf(uint8_t csftrst)
{
	ASSERT_ERR((((uint32_t)csftrst << 30) & ~((uint32_t)0x40000000)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x40000000)) | ((uint32_t)csftrst <<30));
}
__INLINE uint8_t usbc_dctl_reserved_29_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE uint8_t usbc_dctl_hirdthres_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void usbc_dctl_hirdthres_setf(uint8_t hirdthres)
{
	ASSERT_ERR((((uint32_t)hirdthres << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)hirdthres <<24));
}
__INLINE uint8_t usbc_dctl_lpm_nyet_thres_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void usbc_dctl_lpm_nyet_thres_setf(uint8_t lpmnyetthres)
{
	ASSERT_ERR((((uint32_t)lpmnyetthres << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)lpmnyetthres <<20));
}
__INLINE uint8_t usbc_dctl_keep_connect_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void usbc_dctl_keep_connect_setf(uint8_t keepconnect)
{
	ASSERT_ERR((((uint32_t)keepconnect << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)keepconnect <<19));
}
__INLINE uint8_t usbc_dctl_l_1_hibernation_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void usbc_dctl_l_1_hibernation_en_setf(uint8_t l1hibernationen)
{
	ASSERT_ERR((((uint32_t)l1hibernationen << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)l1hibernationen <<18));
}
__INLINE uint8_t usbc_dctl_crs_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void usbc_dctl_crs_setf(uint8_t crs)
{
	ASSERT_ERR((((uint32_t)crs << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)crs <<17));
}
__INLINE uint8_t usbc_dctl_css_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void usbc_dctl_css_setf(uint8_t css)
{
	ASSERT_ERR((((uint32_t)css << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)css <<16));
}
__INLINE uint8_t usbc_dctl_reserved_15_13_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000E000)) >> 13);
}
__INLINE uint8_t usbc_dctl_initu_2_ena_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void usbc_dctl_initu_2_ena_setf(uint8_t initu2ena)
{
	ASSERT_ERR((((uint32_t)initu2ena << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)initu2ena <<12));
}
__INLINE uint8_t usbc_dctl_acceptu_2_ena_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_dctl_acceptu_2_ena_setf(uint8_t acceptu2ena)
{
	ASSERT_ERR((((uint32_t)acceptu2ena << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)acceptu2ena <<11));
}
__INLINE uint8_t usbc_dctl_initu_1_ena_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_dctl_initu_1_ena_setf(uint8_t initu1ena)
{
	ASSERT_ERR((((uint32_t)initu1ena << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)initu1ena <<10));
}
__INLINE uint8_t usbc_dctl_acceptu_1_ena_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void usbc_dctl_acceptu_1_ena_setf(uint8_t acceptu1ena)
{
	ASSERT_ERR((((uint32_t)acceptu1ena << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)acceptu1ena <<9));
}
__INLINE void usbc_dctl_ulstchngreq_setf(uint8_t ulstchngreq)
{
	ASSERT_ERR((((uint32_t)ulstchngreq << 5) & ~((uint32_t)0x000001E0)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x000001E0)) | ((uint32_t)ulstchngreq <<5));
}
__INLINE uint8_t usbc_dctl_tstctl_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001E)) >> 1);
}
__INLINE void usbc_dctl_tstctl_setf(uint8_t tstctl)
{
	ASSERT_ERR((((uint32_t)tstctl << 1) & ~((uint32_t)0x0000001E)) == 0);
	REG_PL_WR(USBC_DCTL_ADDR, (REG_PL_RD(USBC_DCTL_ADDR) & ~((uint32_t)0x0000001E)) | ((uint32_t)tstctl <<1));
}
__INLINE uint8_t usbc_dctl_reserved_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DCTL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief DEVTEN register definition
 *  Device Event Enable Register  This register controls the generation of device-specific events (see  Event Buffer Content for Device-Specific Events (DEVT)  section). If an enable bit is set to 0, the event will not be generated. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:17 reserved_31_17            0x0
 *    16    ECCERREN                  0              
 *    15    reserved_15               0              
 *    14    L1_WKUPEVTEN              0              
 *    12    VENDEVTSTRCVDEN           0              
 *    11    reserved_11               0              
 *    10    reserved_10               0              
 *    09    ERRTICERREVTEN            0              
 *    08    L1_SUSPEN                 0              
 *    07    SOFTEVTEN                 0              
 *    06    U3_L2_L1_Susp_En          0              
 *    05    Hibernation_Req_Evt_En    0              
 *    04    WKUPEVTEN                 0              
 *    03    ULSTCNGEN                 0              
 *    02    CONNECTDONEEVTEN          0              
 *    01    USBRSTEVTEN               0              
 *    00    DISSCONNEVTEN             0              
 * </pre>
 */
#define USBC_DEVTEN_ADDR        (REG_USBC_BASE_ADDR+0x0000C708)
#define USBC_DEVTEN_OFFSET      0x0000C708
#define USBC_DEVTEN_INDEX       0x000031C2
#define USBC_DEVTEN_RESET       0x00000000

__INLINE uint32_t  usbc_devten_get(void)
{
	return REG_PL_RD(USBC_DEVTEN_ADDR);
}

__INLINE void usbc_devten_set(uint32_t value)
{
	REG_PL_WR(USBC_DEVTEN_ADDR, value);
}

// field definitions
#define USBC_DEVTEN_RESERVED_31_17_MASK     ((uint32_t)0xFFFE0000)
#define USBC_DEVTEN_RESERVED_31_17_LSB      17
#define USBC_DEVTEN_RESERVED_31_17_WIDTH    ((uint32_t)0x0000000F)
#define USBC_DEVTEN_ECCERREN_BIT            ((uint32_t)0x00010000)
#define USBC_DEVTEN_ECCERREN_POS            16
#define USBC_DEVTEN_RESERVED_15_BIT         ((uint32_t)0x00008000)
#define USBC_DEVTEN_RESERVED_15_POS         15
#define USBC_DEVTEN_L_1_WKUPEVTEN_BIT       ((uint32_t)0x00004000)
#define USBC_DEVTEN_L_1_WKUPEVTEN_POS       14
#define USBC_DEVTEN_VENDEVTSTRCVDEN_BIT     ((uint32_t)0x00001000)
#define USBC_DEVTEN_VENDEVTSTRCVDEN_POS     12
#define USBC_DEVTEN_RESERVED_11_BIT         ((uint32_t)0x00000800)
#define USBC_DEVTEN_RESERVED_11_POS         11
#define USBC_DEVTEN_RESERVED_10_BIT         ((uint32_t)0x00000400)
#define USBC_DEVTEN_RESERVED_10_POS         10
#define USBC_DEVTEN_ERRTICERREVTEN_BIT      ((uint32_t)0x00000200)
#define USBC_DEVTEN_ERRTICERREVTEN_POS      9
#define USBC_DEVTEN_L_1_SUSPEN_BIT          ((uint32_t)0x00000100)
#define USBC_DEVTEN_L_1_SUSPEN_POS          8
#define USBC_DEVTEN_SOFTEVTEN_BIT           ((uint32_t)0x00000080)
#define USBC_DEVTEN_SOFTEVTEN_POS           7
#define USBC_DEVTEN_U_3_L_2_L_1_SUSP_EN_BIT    ((uint32_t)0x00000040)
#define USBC_DEVTEN_U_3_L_2_L_1_SUSP_EN_POS    6
#define USBC_DEVTEN_HIBERNATION_REQ_EVT_EN_BIT    ((uint32_t)0x00000020)
#define USBC_DEVTEN_HIBERNATION_REQ_EVT_EN_POS    5
#define USBC_DEVTEN_WKUPEVTEN_BIT           ((uint32_t)0x00000010)
#define USBC_DEVTEN_WKUPEVTEN_POS           4
#define USBC_DEVTEN_ULSTCNGEN_BIT           ((uint32_t)0x00000008)
#define USBC_DEVTEN_ULSTCNGEN_POS           3
#define USBC_DEVTEN_CONNECTDONEEVTEN_BIT    ((uint32_t)0x00000004)
#define USBC_DEVTEN_CONNECTDONEEVTEN_POS    2
#define USBC_DEVTEN_USBRSTEVTEN_BIT         ((uint32_t)0x00000002)
#define USBC_DEVTEN_USBRSTEVTEN_POS         1
#define USBC_DEVTEN_DISSCONNEVTEN_BIT       ((uint32_t)0x00000001)
#define USBC_DEVTEN_DISSCONNEVTEN_POS       0

#define USBC_DEVTEN_RESERVED_31_17_RST      0x0
#define USBC_DEVTEN_ECCERREN_RST            0x0
#define USBC_DEVTEN_RESERVED_15_RST         0x0
#define USBC_DEVTEN_L_1_WKUPEVTEN_RST       0x0
#define USBC_DEVTEN_VENDEVTSTRCVDEN_RST     0x0
#define USBC_DEVTEN_RESERVED_11_RST         0x0
#define USBC_DEVTEN_RESERVED_10_RST         0x0
#define USBC_DEVTEN_ERRTICERREVTEN_RST      0x0
#define USBC_DEVTEN_L_1_SUSPEN_RST          0x0
#define USBC_DEVTEN_SOFTEVTEN_RST           0x0
#define USBC_DEVTEN_U_3_L_2_L_1_SUSP_EN_RST    0x0
#define USBC_DEVTEN_HIBERNATION_REQ_EVT_EN_RST    0x0
#define USBC_DEVTEN_WKUPEVTEN_RST           0x0
#define USBC_DEVTEN_ULSTCNGEN_RST           0x0
#define USBC_DEVTEN_CONNECTDONEEVTEN_RST    0x0
#define USBC_DEVTEN_USBRSTEVTEN_RST         0x0
#define USBC_DEVTEN_DISSCONNEVTEN_RST       0x0

__INLINE void usbc_devten_pack(uint16_t reserved_31_17, uint8_t eccerren, uint8_t reserved_15, uint8_t l1_wkupevten, uint8_t vendevtstrcvden, uint8_t reserved_11, uint8_t reserved_10, uint8_t errticerrevten, uint8_t l1_suspen, uint8_t softevten, uint8_t u3_l2_l1_susp_en, uint8_t hibernation_req_evt_en, uint8_t wkupevten, uint8_t ulstcngen, uint8_t connectdoneevten, uint8_t usbrstevten, uint8_t dissconnevten)
{
	ASSERT_ERR((((uint32_t)reserved_31_17 << 17) & ~((uint32_t)0xFFFE0000)) == 0);
	ASSERT_ERR((((uint32_t)eccerren << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_15 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)l1_wkupevten << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)vendevtstrcvden << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_11 << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)reserved_10 << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)errticerrevten << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)l1_suspen << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)softevten << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)u3_l2_l1_susp_en << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)hibernation_req_evt_en << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)wkupevten << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)ulstcngen << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)connectdoneevten << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)usbrstevten << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)dissconnevten << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR,  ((uint32_t)reserved_31_17 << 17) |((uint32_t)eccerren << 16) |((uint32_t)reserved_15 << 15) |((uint32_t)l1_wkupevten << 14) |((uint32_t)vendevtstrcvden << 12) |((uint32_t)reserved_11 << 11) |((uint32_t)reserved_10 << 10) |((uint32_t)errticerrevten << 9) |((uint32_t)l1_suspen << 8) |((uint32_t)softevten << 7) |((uint32_t)u3_l2_l1_susp_en << 6) |((uint32_t)hibernation_req_evt_en << 5) |((uint32_t)wkupevten << 4) |((uint32_t)ulstcngen << 3) |((uint32_t)connectdoneevten << 2) |((uint32_t)usbrstevten << 1) |((uint32_t)dissconnevten << 0));
}

__INLINE void usbc_devten_unpack(uint16_t* reserved_31_17, uint8_t* eccerren, uint8_t* reserved_15, uint8_t* l1_wkupevten, uint8_t* vendevtstrcvden, uint8_t* reserved_11, uint8_t* reserved_10, uint8_t* errticerrevten, uint8_t* l1_suspen, uint8_t* softevten, uint8_t* u3_l2_l1_susp_en, uint8_t* hibernation_req_evt_en, uint8_t* wkupevten, uint8_t* ulstcngen, uint8_t* connectdoneevten, uint8_t* usbrstevten, uint8_t* dissconnevten)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);

	*reserved_31_17 = (localVal & ((uint32_t)0xFFFE0000)) >>  17;
	*eccerren = (localVal & ((uint32_t)0x00010000)) >>  16;
	*reserved_15 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*l1_wkupevten = (localVal & ((uint32_t)0x00004000)) >>  14;
	*vendevtstrcvden = (localVal & ((uint32_t)0x00001000)) >>  12;
	*reserved_11 = (localVal & ((uint32_t)0x00000800)) >>  11;
	*reserved_10 = (localVal & ((uint32_t)0x00000400)) >>  10;
	*errticerrevten = (localVal & ((uint32_t)0x00000200)) >>  9;
	*l1_suspen = (localVal & ((uint32_t)0x00000100)) >>  8;
	*softevten = (localVal & ((uint32_t)0x00000080)) >>  7;
	*u3_l2_l1_susp_en = (localVal & ((uint32_t)0x00000040)) >>  6;
	*hibernation_req_evt_en = (localVal & ((uint32_t)0x00000020)) >>  5;
	*wkupevten = (localVal & ((uint32_t)0x00000010)) >>  4;
	*ulstcngen = (localVal & ((uint32_t)0x00000008)) >>  3;
	*connectdoneevten = (localVal & ((uint32_t)0x00000004)) >>  2;
	*usbrstevten = (localVal & ((uint32_t)0x00000002)) >>  1;
	*dissconnevten = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint16_t usbc_devten_reserved_31_17_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFE0000)) >> 17);
}
__INLINE uint8_t usbc_devten_eccerren_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t usbc_devten_reserved_15_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t usbc_devten_l_1_wkupevten_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void usbc_devten_l_1_wkupevten_setf(uint8_t l1wkupevten)
{
	ASSERT_ERR((((uint32_t)l1wkupevten << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR, (REG_PL_RD(USBC_DEVTEN_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)l1wkupevten <<14));
}
__INLINE uint8_t usbc_devten_vendevtstrcvden_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void usbc_devten_vendevtstrcvden_setf(uint8_t vendevtstrcvden)
{
	ASSERT_ERR((((uint32_t)vendevtstrcvden << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR, (REG_PL_RD(USBC_DEVTEN_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)vendevtstrcvden <<12));
}
__INLINE uint8_t usbc_devten_reserved_11_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t usbc_devten_reserved_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t usbc_devten_errticerrevten_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void usbc_devten_errticerrevten_setf(uint8_t errticerrevten)
{
	ASSERT_ERR((((uint32_t)errticerrevten << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR, (REG_PL_RD(USBC_DEVTEN_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)errticerrevten <<9));
}
__INLINE uint8_t usbc_devten_l_1_suspen_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_devten_l_1_suspen_setf(uint8_t l1suspen)
{
	ASSERT_ERR((((uint32_t)l1suspen << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR, (REG_PL_RD(USBC_DEVTEN_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)l1suspen <<8));
}
__INLINE uint8_t usbc_devten_softevten_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void usbc_devten_softevten_setf(uint8_t softevten)
{
	ASSERT_ERR((((uint32_t)softevten << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR, (REG_PL_RD(USBC_DEVTEN_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)softevten <<7));
}
__INLINE uint8_t usbc_devten_u_3_l_2_l_1_susp_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void usbc_devten_u_3_l_2_l_1_susp_en_setf(uint8_t u3l2l1suspen)
{
	ASSERT_ERR((((uint32_t)u3l2l1suspen << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR, (REG_PL_RD(USBC_DEVTEN_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)u3l2l1suspen <<6));
}
__INLINE uint8_t usbc_devten_hibernation_req_evt_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void usbc_devten_hibernation_req_evt_en_setf(uint8_t hibernationreqevten)
{
	ASSERT_ERR((((uint32_t)hibernationreqevten << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR, (REG_PL_RD(USBC_DEVTEN_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)hibernationreqevten <<5));
}
__INLINE uint8_t usbc_devten_wkupevten_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void usbc_devten_wkupevten_setf(uint8_t wkupevten)
{
	ASSERT_ERR((((uint32_t)wkupevten << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR, (REG_PL_RD(USBC_DEVTEN_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)wkupevten <<4));
}
__INLINE uint8_t usbc_devten_ulstcngen_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void usbc_devten_ulstcngen_setf(uint8_t ulstcngen)
{
	ASSERT_ERR((((uint32_t)ulstcngen << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR, (REG_PL_RD(USBC_DEVTEN_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)ulstcngen <<3));
}
__INLINE uint8_t usbc_devten_connectdoneevten_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void usbc_devten_connectdoneevten_setf(uint8_t connectdoneevten)
{
	ASSERT_ERR((((uint32_t)connectdoneevten << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR, (REG_PL_RD(USBC_DEVTEN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)connectdoneevten <<2));
}
__INLINE uint8_t usbc_devten_usbrstevten_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void usbc_devten_usbrstevten_setf(uint8_t usbrstevten)
{
	ASSERT_ERR((((uint32_t)usbrstevten << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR, (REG_PL_RD(USBC_DEVTEN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)usbrstevten <<1));
}
__INLINE uint8_t usbc_devten_dissconnevten_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEVTEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void usbc_devten_dissconnevten_setf(uint8_t dissconnevten)
{
	ASSERT_ERR((((uint32_t)dissconnevten << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(USBC_DEVTEN_ADDR, (REG_PL_RD(USBC_DEVTEN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)dissconnevten <<0));
}

/**
 * @brief DSTS register definition
 *  Device Status Register  This register indicates the status of the device controller with respect to USB-related events.  Note:  When Hibernation is not enabled, RSS and SSS fields always return 0 when read. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:30 reserved_31_30            0x0
 *    29    DCNRD                     0              
 *    28    SRE                       0              
 *    27:26 reserved_27_26            0x0
 *    25    RSS                       0              
 *    24    SSS                       0              
 *    23    COREIDLE                  0              
 *    22    DEVCTRLHLT                1              
 *    21:18 USBLNKST                  0x4
 *    17    RXFIFOEMPTY               1              
 *    16:03 SOFFN                     0x0
 *    02:00 CONNECTSPD                0x4
 * </pre>
 */
#define USBC_DSTS_ADDR        (REG_USBC_BASE_ADDR+0x0000C70C)
#define USBC_DSTS_OFFSET      0x0000C70C
#define USBC_DSTS_INDEX       0x000031C3
#define USBC_DSTS_RESET       0x00520004

__INLINE uint32_t  usbc_dsts_get(void)
{
	return REG_PL_RD(USBC_DSTS_ADDR);
}

__INLINE void usbc_dsts_set(uint32_t value)
{
	REG_PL_WR(USBC_DSTS_ADDR, value);
}

// field definitions
#define USBC_DSTS_RESERVED_31_30_MASK       ((uint32_t)0xC0000000)
#define USBC_DSTS_RESERVED_31_30_LSB        30
#define USBC_DSTS_RESERVED_31_30_WIDTH      ((uint32_t)0x00000002)
#define USBC_DSTS_DCNRD_BIT                 ((uint32_t)0x20000000)
#define USBC_DSTS_DCNRD_POS                 29
#define USBC_DSTS_SRE_BIT                   ((uint32_t)0x10000000)
#define USBC_DSTS_SRE_POS                   28
#define USBC_DSTS_RESERVED_27_26_MASK       ((uint32_t)0x0C000000)
#define USBC_DSTS_RESERVED_27_26_LSB        26
#define USBC_DSTS_RESERVED_27_26_WIDTH      ((uint32_t)0x00000002)
#define USBC_DSTS_RSS_BIT                   ((uint32_t)0x02000000)
#define USBC_DSTS_RSS_POS                   25
#define USBC_DSTS_SSS_BIT                   ((uint32_t)0x01000000)
#define USBC_DSTS_SSS_POS                   24
#define USBC_DSTS_COREIDLE_BIT              ((uint32_t)0x00800000)
#define USBC_DSTS_COREIDLE_POS              23
#define USBC_DSTS_DEVCTRLHLT_BIT            ((uint32_t)0x00400000)
#define USBC_DSTS_DEVCTRLHLT_POS            22
#define USBC_DSTS_USBLNKST_MASK             ((uint32_t)0x003C0000)
#define USBC_DSTS_USBLNKST_LSB              18
#define USBC_DSTS_USBLNKST_WIDTH            ((uint32_t)0x00000004)
#define USBC_DSTS_RXFIFOEMPTY_BIT           ((uint32_t)0x00020000)
#define USBC_DSTS_RXFIFOEMPTY_POS           17
#define USBC_DSTS_SOFFN_MASK                ((uint32_t)0x0001FFF8)
#define USBC_DSTS_SOFFN_LSB                 3
#define USBC_DSTS_SOFFN_WIDTH               ((uint32_t)0x0000000E)
#define USBC_DSTS_CONNECTSPD_MASK           ((uint32_t)0x00000007)
#define USBC_DSTS_CONNECTSPD_LSB            0
#define USBC_DSTS_CONNECTSPD_WIDTH          ((uint32_t)0x00000003)

#define USBC_DSTS_RESERVED_31_30_RST        0x0
#define USBC_DSTS_DCNRD_RST                 0x0
#define USBC_DSTS_SRE_RST                   0x0
#define USBC_DSTS_RESERVED_27_26_RST        0x0
#define USBC_DSTS_RSS_RST                   0x0
#define USBC_DSTS_SSS_RST                   0x0
#define USBC_DSTS_COREIDLE_RST              0x0
#define USBC_DSTS_DEVCTRLHLT_RST            0x1
#define USBC_DSTS_USBLNKST_RST              0x4
#define USBC_DSTS_RXFIFOEMPTY_RST           0x1
#define USBC_DSTS_SOFFN_RST                 0x0
#define USBC_DSTS_CONNECTSPD_RST            0x4

__INLINE void usbc_dsts_pack(uint8_t reserved_31_30, uint8_t dcnrd, uint8_t sre, uint8_t reserved_27_26, uint8_t rss, uint8_t sss, uint8_t coreidle, uint8_t devctrlhlt, uint8_t usblnkst, uint8_t rxfifoempty, uint16_t soffn, uint8_t connectspd)
{
	ASSERT_ERR((((uint32_t)reserved_31_30 << 30) & ~((uint32_t)0xC0000000)) == 0);
	ASSERT_ERR((((uint32_t)dcnrd << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)sre << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_27_26 << 26) & ~((uint32_t)0x0C000000)) == 0);
	ASSERT_ERR((((uint32_t)rss << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)sss << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)coreidle << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)devctrlhlt << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)usblnkst << 18) & ~((uint32_t)0x003C0000)) == 0);
	ASSERT_ERR((((uint32_t)rxfifoempty << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)soffn << 3) & ~((uint32_t)0x0001FFF8)) == 0);
	ASSERT_ERR((((uint32_t)connectspd << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(USBC_DSTS_ADDR,  ((uint32_t)reserved_31_30 << 30) |((uint32_t)dcnrd << 29) |((uint32_t)sre << 28) |((uint32_t)reserved_27_26 << 26) |((uint32_t)rss << 25) |((uint32_t)sss << 24) |((uint32_t)coreidle << 23) |((uint32_t)devctrlhlt << 22) |((uint32_t)usblnkst << 18) |((uint32_t)rxfifoempty << 17) |((uint32_t)soffn << 3) |((uint32_t)connectspd << 0));
}

__INLINE void usbc_dsts_unpack(uint8_t* reserved_31_30, uint8_t* dcnrd, uint8_t* sre, uint8_t* reserved_27_26, uint8_t* rss, uint8_t* sss, uint8_t* coreidle, uint8_t* devctrlhlt, uint8_t* usblnkst, uint8_t* rxfifoempty, uint16_t* soffn, uint8_t* connectspd)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);

	*reserved_31_30 = (localVal & ((uint32_t)0xC0000000)) >>  30;
	*dcnrd = (localVal & ((uint32_t)0x20000000)) >>  29;
	*sre = (localVal & ((uint32_t)0x10000000)) >>  28;
	*reserved_27_26 = (localVal & ((uint32_t)0x0C000000)) >>  26;
	*rss = (localVal & ((uint32_t)0x02000000)) >>  25;
	*sss = (localVal & ((uint32_t)0x01000000)) >>  24;
	*coreidle = (localVal & ((uint32_t)0x00800000)) >>  23;
	*devctrlhlt = (localVal & ((uint32_t)0x00400000)) >>  22;
	*usblnkst = (localVal & ((uint32_t)0x003C0000)) >>  18;
	*rxfifoempty = (localVal & ((uint32_t)0x00020000)) >>  17;
	*soffn = (localVal & ((uint32_t)0x0001FFF8)) >>  3;
	*connectspd = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t usbc_dsts_reserved_31_30_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xC0000000)) >> 30);
}
__INLINE uint8_t usbc_dsts_dcnrd_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE uint8_t usbc_dsts_sre_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void usbc_dsts_sre_setf(uint8_t sre)
{
	ASSERT_ERR((((uint32_t)sre << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(USBC_DSTS_ADDR, (REG_PL_RD(USBC_DSTS_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)sre <<28));
}
__INLINE uint8_t usbc_dsts_reserved_27_26_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0C000000)) >> 26);
}
__INLINE uint8_t usbc_dsts_rss_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE uint8_t usbc_dsts_sss_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE uint8_t usbc_dsts_coreidle_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t usbc_dsts_devctrlhlt_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint8_t usbc_dsts_usblnkst_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003C0000)) >> 18);
}
__INLINE uint8_t usbc_dsts_rxfifoempty_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE uint16_t usbc_dsts_soffn_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0001FFF8)) >> 3);
}
__INLINE uint8_t usbc_dsts_connectspd_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DSTS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief DGCMDPAR register definition
 *  Device Generic Command Parameter Register  This register indicates the device command parameter. This must be programmed before or along with the device command. The available device commands are listed in DGCMD register. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DGCMDPAR_ADDR        (REG_USBC_BASE_ADDR+0x0000C710)
#define USBC_DGCMDPAR_OFFSET      0x0000C710
#define USBC_DGCMDPAR_INDEX       0x000031C4
#define USBC_DGCMDPAR_RESET       0x00000000

__INLINE uint32_t  usbc_dgcmdpar_get(void)
{
	return REG_PL_RD(USBC_DGCMDPAR_ADDR);
}

__INLINE void usbc_dgcmdpar_set(uint32_t value)
{
	REG_PL_WR(USBC_DGCMDPAR_ADDR, value);
}

// field definitions
#define USBC_DGCMDPAR_PARAMETER_MASK        ((uint32_t)0xFFFFFFFF)
#define USBC_DGCMDPAR_PARAMETER_LSB         0
#define USBC_DGCMDPAR_PARAMETER_WIDTH       ((uint32_t)0x00000020)

#define USBC_DGCMDPAR_PARAMETER_RST         0x0

__INLINE uint32_t usbc_dgcmdpar_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DGCMDPAR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_dgcmdpar_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DGCMDPAR_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DGCMD register definition
 *  Device Generic Command Register  This register enables software to program the controller using a single generic command interface to send link management packets and notifications. This register contains command, control, and status fields relevant to the current generic command, while the DGCMDPAR register provides the command parameter.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 reserved_31_16            0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    reserved_11               0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DGCMD_ADDR        (REG_USBC_BASE_ADDR+0x0000C714)
#define USBC_DGCMD_OFFSET      0x0000C714
#define USBC_DGCMD_INDEX       0x000031C5
#define USBC_DGCMD_RESET       0x00000000

__INLINE uint32_t  usbc_dgcmd_get(void)
{
	return REG_PL_RD(USBC_DGCMD_ADDR);
}

__INLINE void usbc_dgcmd_set(uint32_t value)
{
	REG_PL_WR(USBC_DGCMD_ADDR, value);
}

// field definitions
#define USBC_DGCMD_RESERVED_31_16_MASK      ((uint32_t)0xFFFF0000)
#define USBC_DGCMD_RESERVED_31_16_LSB       16
#define USBC_DGCMD_RESERVED_31_16_WIDTH     ((uint32_t)0x00000010)
#define USBC_DGCMD_CMDSTATUS_MASK           ((uint32_t)0x0000F000)
#define USBC_DGCMD_CMDSTATUS_LSB            12
#define USBC_DGCMD_CMDSTATUS_WIDTH          ((uint32_t)0x00000004)
#define USBC_DGCMD_RESERVED_11_BIT          ((uint32_t)0x00000800)
#define USBC_DGCMD_RESERVED_11_POS          11
#define USBC_DGCMD_CMDACT_BIT               ((uint32_t)0x00000400)
#define USBC_DGCMD_CMDACT_POS               10
#define USBC_DGCMD_RESERVED_9_BIT           ((uint32_t)0x00000200)
#define USBC_DGCMD_RESERVED_9_POS           9
#define USBC_DGCMD_CMDIOC_BIT               ((uint32_t)0x00000100)
#define USBC_DGCMD_CMDIOC_POS               8
#define USBC_DGCMD_CMDTYP_MASK              ((uint32_t)0x000000FF)
#define USBC_DGCMD_CMDTYP_LSB               0
#define USBC_DGCMD_CMDTYP_WIDTH             ((uint32_t)0x00000008)

#define USBC_DGCMD_RESERVED_31_16_RST       0x0
#define USBC_DGCMD_CMDSTATUS_RST            0x0
#define USBC_DGCMD_RESERVED_11_RST          0x0
#define USBC_DGCMD_CMDACT_RST               0x0
#define USBC_DGCMD_RESERVED_9_RST           0x0
#define USBC_DGCMD_CMDIOC_RST               0x0
#define USBC_DGCMD_CMDTYP_RST               0x0

__INLINE void usbc_dgcmd_pack(uint16_t reserved_31_16, uint8_t cmdstatus, uint8_t reserved_11, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)reserved_31_16 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_11 << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(USBC_DGCMD_ADDR,  ((uint32_t)reserved_31_16 << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)reserved_11 << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_dgcmd_unpack(uint16_t* reserved_31_16, uint8_t* cmdstatus, uint8_t* reserved_11, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DGCMD_ADDR);

	*reserved_31_16 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*reserved_11 = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*cmdtyp = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint16_t usbc_dgcmd_reserved_31_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DGCMD_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint8_t usbc_dgcmd_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DGCMD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE uint8_t usbc_dgcmd_reserved_11_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DGCMD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t usbc_dgcmd_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DGCMD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_dgcmd_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DGCMD_ADDR, (REG_PL_RD(USBC_DGCMD_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_dgcmd_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DGCMD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_dgcmd_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DGCMD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_dgcmd_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DGCMD_ADDR, (REG_PL_RD(USBC_DGCMD_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_dgcmd_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DGCMD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void usbc_dgcmd_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(USBC_DGCMD_ADDR, (REG_PL_RD(USBC_DGCMD_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DALEPENA register definition
 *  Device Active USB Endpoint Enable Register.   This register indicates whether a USB endpoint is active in a given configuration or interface. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 USBACTEP                  0x0
 * </pre>
 */
#define USBC_DALEPENA_ADDR        (REG_USBC_BASE_ADDR+0x0000C720)
#define USBC_DALEPENA_OFFSET      0x0000C720
#define USBC_DALEPENA_INDEX       0x000031C8
#define USBC_DALEPENA_RESET       0x00000000

__INLINE uint32_t  usbc_dalepena_get(void)
{
	return REG_PL_RD(USBC_DALEPENA_ADDR);
}

__INLINE void usbc_dalepena_set(uint32_t value)
{
	REG_PL_WR(USBC_DALEPENA_ADDR, value);
}

// field definitions
#define USBC_DALEPENA_USBACTEP_MASK         ((uint32_t)0xFFFFFFFF)
#define USBC_DALEPENA_USBACTEP_LSB          0
#define USBC_DALEPENA_USBACTEP_WIDTH        ((uint32_t)0x00000020)

#define USBC_DALEPENA_USBACTEP_RST          0x0

__INLINE uint32_t usbc_dalepena_usbactep_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DALEPENA_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_dalepena_usbactep_setf(uint32_t usbactep)
{
	ASSERT_ERR((((uint32_t)usbactep << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DALEPENA_ADDR, (uint32_t)usbactep << 0);
}

/**
 * @brief RSVD_0 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C724)
#define USBC_RSVD_0_OFFSET      0x0000C724
#define USBC_RSVD_0_INDEX       0x000031C9
#define USBC_RSVD_0_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_0_get(void)
{
	return REG_PL_RD(USBC_RSVD_0_ADDR);
}

// field definitions
#define USBC_RSVD_0_RESERVED_31_0_MASK      ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_0_RESERVED_31_0_LSB       0
#define USBC_RSVD_0_RESERVED_31_0_WIDTH     ((uint32_t)0x00000020)

#define USBC_RSVD_0_RESERVED_31_0_RST       0x0

__INLINE uint32_t usbc_rsvd_0_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_0_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_1 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_1_ADDR        (REG_USBC_BASE_ADDR+0x0000C728)
#define USBC_RSVD_1_OFFSET      0x0000C728
#define USBC_RSVD_1_INDEX       0x000031CA
#define USBC_RSVD_1_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_1_get(void)
{
	return REG_PL_RD(USBC_RSVD_1_ADDR);
}

// field definitions
#define USBC_RSVD_1_RESERVED_31_0_MASK      ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_1_RESERVED_31_0_LSB       0
#define USBC_RSVD_1_RESERVED_31_0_WIDTH     ((uint32_t)0x00000020)

#define USBC_RSVD_1_RESERVED_31_0_RST       0x0

__INLINE uint32_t usbc_rsvd_1_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_1_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_2 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_2_ADDR        (REG_USBC_BASE_ADDR+0x0000C72C)
#define USBC_RSVD_2_OFFSET      0x0000C72C
#define USBC_RSVD_2_INDEX       0x000031CB
#define USBC_RSVD_2_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_2_get(void)
{
	return REG_PL_RD(USBC_RSVD_2_ADDR);
}

// field definitions
#define USBC_RSVD_2_RESERVED_31_0_MASK      ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_2_RESERVED_31_0_LSB       0
#define USBC_RSVD_2_RESERVED_31_0_WIDTH     ((uint32_t)0x00000020)

#define USBC_RSVD_2_RESERVED_31_0_RST       0x0

__INLINE uint32_t usbc_rsvd_2_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_2_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_3 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_3_ADDR        (REG_USBC_BASE_ADDR+0x0000C730)
#define USBC_RSVD_3_OFFSET      0x0000C730
#define USBC_RSVD_3_INDEX       0x000031CC
#define USBC_RSVD_3_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_3_get(void)
{
	return REG_PL_RD(USBC_RSVD_3_ADDR);
}

// field definitions
#define USBC_RSVD_3_RESERVED_31_0_MASK      ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_3_RESERVED_31_0_LSB       0
#define USBC_RSVD_3_RESERVED_31_0_WIDTH     ((uint32_t)0x00000020)

#define USBC_RSVD_3_RESERVED_31_0_RST       0x0

__INLINE uint32_t usbc_rsvd_3_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_4 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_4_ADDR        (REG_USBC_BASE_ADDR+0x0000C734)
#define USBC_RSVD_4_OFFSET      0x0000C734
#define USBC_RSVD_4_INDEX       0x000031CD
#define USBC_RSVD_4_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_4_get(void)
{
	return REG_PL_RD(USBC_RSVD_4_ADDR);
}

// field definitions
#define USBC_RSVD_4_RESERVED_31_0_MASK      ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_4_RESERVED_31_0_LSB       0
#define USBC_RSVD_4_RESERVED_31_0_WIDTH     ((uint32_t)0x00000020)

#define USBC_RSVD_4_RESERVED_31_0_RST       0x0

__INLINE uint32_t usbc_rsvd_4_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_4_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_5 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_5_ADDR        (REG_USBC_BASE_ADDR+0x0000C738)
#define USBC_RSVD_5_OFFSET      0x0000C738
#define USBC_RSVD_5_INDEX       0x000031CE
#define USBC_RSVD_5_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_5_get(void)
{
	return REG_PL_RD(USBC_RSVD_5_ADDR);
}

// field definitions
#define USBC_RSVD_5_RESERVED_31_0_MASK      ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_5_RESERVED_31_0_LSB       0
#define USBC_RSVD_5_RESERVED_31_0_WIDTH     ((uint32_t)0x00000020)

#define USBC_RSVD_5_RESERVED_31_0_RST       0x0

__INLINE uint32_t usbc_rsvd_5_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_5_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_6 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_6_ADDR        (REG_USBC_BASE_ADDR+0x0000C73C)
#define USBC_RSVD_6_OFFSET      0x0000C73C
#define USBC_RSVD_6_INDEX       0x000031CF
#define USBC_RSVD_6_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_6_get(void)
{
	return REG_PL_RD(USBC_RSVD_6_ADDR);
}

// field definitions
#define USBC_RSVD_6_RESERVED_31_0_MASK      ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_6_RESERVED_31_0_LSB       0
#define USBC_RSVD_6_RESERVED_31_0_WIDTH     ((uint32_t)0x00000020)

#define USBC_RSVD_6_RESERVED_31_0_RST       0x0

__INLINE uint32_t usbc_rsvd_6_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_6_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_7 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_7_ADDR        (REG_USBC_BASE_ADDR+0x0000C740)
#define USBC_RSVD_7_OFFSET      0x0000C740
#define USBC_RSVD_7_INDEX       0x000031D0
#define USBC_RSVD_7_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_7_get(void)
{
	return REG_PL_RD(USBC_RSVD_7_ADDR);
}

// field definitions
#define USBC_RSVD_7_RESERVED_31_0_MASK      ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_7_RESERVED_31_0_LSB       0
#define USBC_RSVD_7_RESERVED_31_0_WIDTH     ((uint32_t)0x00000020)

#define USBC_RSVD_7_RESERVED_31_0_RST       0x0

__INLINE uint32_t usbc_rsvd_7_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_7_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_8 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_8_ADDR        (REG_USBC_BASE_ADDR+0x0000C744)
#define USBC_RSVD_8_OFFSET      0x0000C744
#define USBC_RSVD_8_INDEX       0x000031D1
#define USBC_RSVD_8_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_8_get(void)
{
	return REG_PL_RD(USBC_RSVD_8_ADDR);
}

// field definitions
#define USBC_RSVD_8_RESERVED_31_0_MASK      ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_8_RESERVED_31_0_LSB       0
#define USBC_RSVD_8_RESERVED_31_0_WIDTH     ((uint32_t)0x00000020)

#define USBC_RSVD_8_RESERVED_31_0_RST       0x0

__INLINE uint32_t usbc_rsvd_8_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_8_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_9 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_9_ADDR        (REG_USBC_BASE_ADDR+0x0000C748)
#define USBC_RSVD_9_OFFSET      0x0000C748
#define USBC_RSVD_9_INDEX       0x000031D2
#define USBC_RSVD_9_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_9_get(void)
{
	return REG_PL_RD(USBC_RSVD_9_ADDR);
}

// field definitions
#define USBC_RSVD_9_RESERVED_31_0_MASK      ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_9_RESERVED_31_0_LSB       0
#define USBC_RSVD_9_RESERVED_31_0_WIDTH     ((uint32_t)0x00000020)

#define USBC_RSVD_9_RESERVED_31_0_RST       0x0

__INLINE uint32_t usbc_rsvd_9_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_9_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_10 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_10_ADDR        (REG_USBC_BASE_ADDR+0x0000C74C)
#define USBC_RSVD_10_OFFSET      0x0000C74C
#define USBC_RSVD_10_INDEX       0x000031D3
#define USBC_RSVD_10_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_10_get(void)
{
	return REG_PL_RD(USBC_RSVD_10_ADDR);
}

// field definitions
#define USBC_RSVD_10_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_10_RESERVED_31_0_LSB      0
#define USBC_RSVD_10_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_10_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_10_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_10_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_11 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_11_ADDR        (REG_USBC_BASE_ADDR+0x0000C750)
#define USBC_RSVD_11_OFFSET      0x0000C750
#define USBC_RSVD_11_INDEX       0x000031D4
#define USBC_RSVD_11_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_11_get(void)
{
	return REG_PL_RD(USBC_RSVD_11_ADDR);
}

// field definitions
#define USBC_RSVD_11_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_11_RESERVED_31_0_LSB      0
#define USBC_RSVD_11_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_11_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_11_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_11_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_12 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_12_ADDR        (REG_USBC_BASE_ADDR+0x0000C754)
#define USBC_RSVD_12_OFFSET      0x0000C754
#define USBC_RSVD_12_INDEX       0x000031D5
#define USBC_RSVD_12_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_12_get(void)
{
	return REG_PL_RD(USBC_RSVD_12_ADDR);
}

// field definitions
#define USBC_RSVD_12_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_12_RESERVED_31_0_LSB      0
#define USBC_RSVD_12_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_12_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_12_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_12_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_13 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_13_ADDR        (REG_USBC_BASE_ADDR+0x0000C758)
#define USBC_RSVD_13_OFFSET      0x0000C758
#define USBC_RSVD_13_INDEX       0x000031D6
#define USBC_RSVD_13_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_13_get(void)
{
	return REG_PL_RD(USBC_RSVD_13_ADDR);
}

// field definitions
#define USBC_RSVD_13_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_13_RESERVED_31_0_LSB      0
#define USBC_RSVD_13_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_13_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_13_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_13_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_14 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_14_ADDR        (REG_USBC_BASE_ADDR+0x0000C75C)
#define USBC_RSVD_14_OFFSET      0x0000C75C
#define USBC_RSVD_14_INDEX       0x000031D7
#define USBC_RSVD_14_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_14_get(void)
{
	return REG_PL_RD(USBC_RSVD_14_ADDR);
}

// field definitions
#define USBC_RSVD_14_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_14_RESERVED_31_0_LSB      0
#define USBC_RSVD_14_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_14_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_14_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_14_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_15 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_15_ADDR        (REG_USBC_BASE_ADDR+0x0000C760)
#define USBC_RSVD_15_OFFSET      0x0000C760
#define USBC_RSVD_15_INDEX       0x000031D8
#define USBC_RSVD_15_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_15_get(void)
{
	return REG_PL_RD(USBC_RSVD_15_ADDR);
}

// field definitions
#define USBC_RSVD_15_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_15_RESERVED_31_0_LSB      0
#define USBC_RSVD_15_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_15_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_15_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_15_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_16 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_16_ADDR        (REG_USBC_BASE_ADDR+0x0000C764)
#define USBC_RSVD_16_OFFSET      0x0000C764
#define USBC_RSVD_16_INDEX       0x000031D9
#define USBC_RSVD_16_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_16_get(void)
{
	return REG_PL_RD(USBC_RSVD_16_ADDR);
}

// field definitions
#define USBC_RSVD_16_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_16_RESERVED_31_0_LSB      0
#define USBC_RSVD_16_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_16_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_16_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_16_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_17 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_17_ADDR        (REG_USBC_BASE_ADDR+0x0000C768)
#define USBC_RSVD_17_OFFSET      0x0000C768
#define USBC_RSVD_17_INDEX       0x000031DA
#define USBC_RSVD_17_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_17_get(void)
{
	return REG_PL_RD(USBC_RSVD_17_ADDR);
}

// field definitions
#define USBC_RSVD_17_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_17_RESERVED_31_0_LSB      0
#define USBC_RSVD_17_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_17_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_17_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_17_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_18 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_18_ADDR        (REG_USBC_BASE_ADDR+0x0000C76C)
#define USBC_RSVD_18_OFFSET      0x0000C76C
#define USBC_RSVD_18_INDEX       0x000031DB
#define USBC_RSVD_18_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_18_get(void)
{
	return REG_PL_RD(USBC_RSVD_18_ADDR);
}

// field definitions
#define USBC_RSVD_18_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_18_RESERVED_31_0_LSB      0
#define USBC_RSVD_18_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_18_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_18_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_18_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_19 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_19_ADDR        (REG_USBC_BASE_ADDR+0x0000C770)
#define USBC_RSVD_19_OFFSET      0x0000C770
#define USBC_RSVD_19_INDEX       0x000031DC
#define USBC_RSVD_19_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_19_get(void)
{
	return REG_PL_RD(USBC_RSVD_19_ADDR);
}

// field definitions
#define USBC_RSVD_19_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_19_RESERVED_31_0_LSB      0
#define USBC_RSVD_19_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_19_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_19_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_19_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_20 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_20_ADDR        (REG_USBC_BASE_ADDR+0x0000C774)
#define USBC_RSVD_20_OFFSET      0x0000C774
#define USBC_RSVD_20_INDEX       0x000031DD
#define USBC_RSVD_20_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_20_get(void)
{
	return REG_PL_RD(USBC_RSVD_20_ADDR);
}

// field definitions
#define USBC_RSVD_20_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_20_RESERVED_31_0_LSB      0
#define USBC_RSVD_20_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_20_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_20_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_20_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_21 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_21_ADDR        (REG_USBC_BASE_ADDR+0x0000C778)
#define USBC_RSVD_21_OFFSET      0x0000C778
#define USBC_RSVD_21_INDEX       0x000031DE
#define USBC_RSVD_21_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_21_get(void)
{
	return REG_PL_RD(USBC_RSVD_21_ADDR);
}

// field definitions
#define USBC_RSVD_21_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_21_RESERVED_31_0_LSB      0
#define USBC_RSVD_21_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_21_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_21_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_21_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_22 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_22_ADDR        (REG_USBC_BASE_ADDR+0x0000C77C)
#define USBC_RSVD_22_OFFSET      0x0000C77C
#define USBC_RSVD_22_INDEX       0x000031DF
#define USBC_RSVD_22_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_22_get(void)
{
	return REG_PL_RD(USBC_RSVD_22_ADDR);
}

// field definitions
#define USBC_RSVD_22_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_22_RESERVED_31_0_LSB      0
#define USBC_RSVD_22_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_22_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_22_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_22_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_23 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_23_ADDR        (REG_USBC_BASE_ADDR+0x0000C780)
#define USBC_RSVD_23_OFFSET      0x0000C780
#define USBC_RSVD_23_INDEX       0x000031E0
#define USBC_RSVD_23_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_23_get(void)
{
	return REG_PL_RD(USBC_RSVD_23_ADDR);
}

// field definitions
#define USBC_RSVD_23_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_23_RESERVED_31_0_LSB      0
#define USBC_RSVD_23_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_23_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_23_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_23_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_24 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_24_ADDR        (REG_USBC_BASE_ADDR+0x0000C784)
#define USBC_RSVD_24_OFFSET      0x0000C784
#define USBC_RSVD_24_INDEX       0x000031E1
#define USBC_RSVD_24_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_24_get(void)
{
	return REG_PL_RD(USBC_RSVD_24_ADDR);
}

// field definitions
#define USBC_RSVD_24_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_24_RESERVED_31_0_LSB      0
#define USBC_RSVD_24_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_24_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_24_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_24_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_25 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_25_ADDR        (REG_USBC_BASE_ADDR+0x0000C788)
#define USBC_RSVD_25_OFFSET      0x0000C788
#define USBC_RSVD_25_INDEX       0x000031E2
#define USBC_RSVD_25_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_25_get(void)
{
	return REG_PL_RD(USBC_RSVD_25_ADDR);
}

// field definitions
#define USBC_RSVD_25_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_25_RESERVED_31_0_LSB      0
#define USBC_RSVD_25_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_25_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_25_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_25_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_26 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_26_ADDR        (REG_USBC_BASE_ADDR+0x0000C78C)
#define USBC_RSVD_26_OFFSET      0x0000C78C
#define USBC_RSVD_26_INDEX       0x000031E3
#define USBC_RSVD_26_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_26_get(void)
{
	return REG_PL_RD(USBC_RSVD_26_ADDR);
}

// field definitions
#define USBC_RSVD_26_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_26_RESERVED_31_0_LSB      0
#define USBC_RSVD_26_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_26_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_26_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_26_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_27 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_27_ADDR        (REG_USBC_BASE_ADDR+0x0000C790)
#define USBC_RSVD_27_OFFSET      0x0000C790
#define USBC_RSVD_27_INDEX       0x000031E4
#define USBC_RSVD_27_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_27_get(void)
{
	return REG_PL_RD(USBC_RSVD_27_ADDR);
}

// field definitions
#define USBC_RSVD_27_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_27_RESERVED_31_0_LSB      0
#define USBC_RSVD_27_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_27_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_27_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_27_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_28 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_28_ADDR        (REG_USBC_BASE_ADDR+0x0000C794)
#define USBC_RSVD_28_OFFSET      0x0000C794
#define USBC_RSVD_28_INDEX       0x000031E5
#define USBC_RSVD_28_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_28_get(void)
{
	return REG_PL_RD(USBC_RSVD_28_ADDR);
}

// field definitions
#define USBC_RSVD_28_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_28_RESERVED_31_0_LSB      0
#define USBC_RSVD_28_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_28_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_28_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_28_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_29 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_29_ADDR        (REG_USBC_BASE_ADDR+0x0000C798)
#define USBC_RSVD_29_OFFSET      0x0000C798
#define USBC_RSVD_29_INDEX       0x000031E6
#define USBC_RSVD_29_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_29_get(void)
{
	return REG_PL_RD(USBC_RSVD_29_ADDR);
}

// field definitions
#define USBC_RSVD_29_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_29_RESERVED_31_0_LSB      0
#define USBC_RSVD_29_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_29_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_29_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_29_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_30 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_30_ADDR        (REG_USBC_BASE_ADDR+0x0000C79C)
#define USBC_RSVD_30_OFFSET      0x0000C79C
#define USBC_RSVD_30_INDEX       0x000031E7
#define USBC_RSVD_30_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_30_get(void)
{
	return REG_PL_RD(USBC_RSVD_30_ADDR);
}

// field definitions
#define USBC_RSVD_30_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_30_RESERVED_31_0_LSB      0
#define USBC_RSVD_30_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_30_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_30_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_30_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief RSVD_31 register definition
 *  Reserved register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 reserved_31_0             0x0
 * </pre>
 */
#define USBC_RSVD_31_ADDR        (REG_USBC_BASE_ADDR+0x0000C7A0)
#define USBC_RSVD_31_OFFSET      0x0000C7A0
#define USBC_RSVD_31_INDEX       0x000031E8
#define USBC_RSVD_31_RESET       0x00000000

__INLINE uint32_t  usbc_rsvd_31_get(void)
{
	return REG_PL_RD(USBC_RSVD_31_ADDR);
}

// field definitions
#define USBC_RSVD_31_RESERVED_31_0_MASK     ((uint32_t)0xFFFFFFFF)
#define USBC_RSVD_31_RESERVED_31_0_LSB      0
#define USBC_RSVD_31_RESERVED_31_0_WIDTH    ((uint32_t)0x00000020)

#define USBC_RSVD_31_RESERVED_31_0_RST      0x0

__INLINE uint32_t usbc_rsvd_31_reserved_31_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_RSVD_31_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief DEPCMDPAR_2_0 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C800)
#define USBC_DEPCMDPAR_2_0_OFFSET      0x0000C800
#define USBC_DEPCMDPAR_2_0_INDEX       0x00003200
#define USBC_DEPCMDPAR_2_0_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_0_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_0_ADDR);
}

__INLINE void usbc_depcmdpar_2_0_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_0_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_0_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_0_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_0_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_0_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_0_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_0_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_0_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_0 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C804)
#define USBC_DEPCMDPAR_1_0_OFFSET      0x0000C804
#define USBC_DEPCMDPAR_1_0_INDEX       0x00003201
#define USBC_DEPCMDPAR_1_0_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_0_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_0_ADDR);
}

__INLINE void usbc_depcmdpar_1_0_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_0_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_0_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_0_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_0_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_0_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_0_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_0_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_0_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_0 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C808)
#define USBC_DEPCMDPAR_0_0_OFFSET      0x0000C808
#define USBC_DEPCMDPAR_0_0_INDEX       0x00003202
#define USBC_DEPCMDPAR_0_0_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_0_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_0_ADDR);
}

__INLINE void usbc_depcmdpar_0_0_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_0_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_0_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_0_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_0_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_0_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_0_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_0_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_0_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_0 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_0_ADDR        (REG_USBC_BASE_ADDR+0x0000C80C)
#define USBC_DEPCMD_0_OFFSET      0x0000C80C
#define USBC_DEPCMD_0_INDEX       0x00003203
#define USBC_DEPCMD_0_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_0_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_0_ADDR);
}

__INLINE void usbc_depcmd_0_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_0_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_0_COMMANDPARAM_MASK     ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_0_COMMANDPARAM_LSB      16
#define USBC_DEPCMD_0_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_0_CMDSTATUS_MASK        ((uint32_t)0x0000F000)
#define USBC_DEPCMD_0_CMDSTATUS_LSB         12
#define USBC_DEPCMD_0_CMDSTATUS_WIDTH       ((uint32_t)0x00000004)
#define USBC_DEPCMD_0_HIPRI_FORCERM_BIT     ((uint32_t)0x00000800)
#define USBC_DEPCMD_0_HIPRI_FORCERM_POS     11
#define USBC_DEPCMD_0_CMDACT_BIT            ((uint32_t)0x00000400)
#define USBC_DEPCMD_0_CMDACT_POS            10
#define USBC_DEPCMD_0_RESERVED_9_BIT        ((uint32_t)0x00000200)
#define USBC_DEPCMD_0_RESERVED_9_POS        9
#define USBC_DEPCMD_0_CMDIOC_BIT            ((uint32_t)0x00000100)
#define USBC_DEPCMD_0_CMDIOC_POS            8
#define USBC_DEPCMD_0_RESERVED_7_4_MASK     ((uint32_t)0x000000F0)
#define USBC_DEPCMD_0_RESERVED_7_4_LSB      4
#define USBC_DEPCMD_0_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_0_CMDTYP_MASK           ((uint32_t)0x0000000F)
#define USBC_DEPCMD_0_CMDTYP_LSB            0
#define USBC_DEPCMD_0_CMDTYP_WIDTH          ((uint32_t)0x00000004)

#define USBC_DEPCMD_0_COMMANDPARAM_RST      0x0
#define USBC_DEPCMD_0_CMDSTATUS_RST         0x0
#define USBC_DEPCMD_0_HIPRI_FORCERM_RST     0x0
#define USBC_DEPCMD_0_CMDACT_RST            0x0
#define USBC_DEPCMD_0_RESERVED_9_RST        0x0
#define USBC_DEPCMD_0_CMDIOC_RST            0x0
#define USBC_DEPCMD_0_RESERVED_7_4_RST      0x0
#define USBC_DEPCMD_0_CMDTYP_RST            0x0

__INLINE void usbc_depcmd_0_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_0_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_0_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_0_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_0_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_0_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_0_ADDR, (REG_PL_RD(USBC_DEPCMD_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_0_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_0_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_0_ADDR, (REG_PL_RD(USBC_DEPCMD_0_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_0_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_0_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_0_ADDR, (REG_PL_RD(USBC_DEPCMD_0_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_0_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_0_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_0_ADDR, (REG_PL_RD(USBC_DEPCMD_0_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_0_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_0_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_0_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_0_ADDR, (REG_PL_RD(USBC_DEPCMD_0_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_0_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_0_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_0_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_0_ADDR, (REG_PL_RD(USBC_DEPCMD_0_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_1 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_1_ADDR        (REG_USBC_BASE_ADDR+0x0000C810)
#define USBC_DEPCMDPAR_2_1_OFFSET      0x0000C810
#define USBC_DEPCMDPAR_2_1_INDEX       0x00003204
#define USBC_DEPCMDPAR_2_1_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_1_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_1_ADDR);
}

__INLINE void usbc_depcmdpar_2_1_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_1_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_1_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_1_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_1_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_1_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_1_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_1_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_1_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_1 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_1_ADDR        (REG_USBC_BASE_ADDR+0x0000C814)
#define USBC_DEPCMDPAR_1_1_OFFSET      0x0000C814
#define USBC_DEPCMDPAR_1_1_INDEX       0x00003205
#define USBC_DEPCMDPAR_1_1_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_1_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_1_ADDR);
}

__INLINE void usbc_depcmdpar_1_1_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_1_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_1_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_1_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_1_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_1_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_1_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_1_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_1_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_1 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_1_ADDR        (REG_USBC_BASE_ADDR+0x0000C818)
#define USBC_DEPCMDPAR_0_1_OFFSET      0x0000C818
#define USBC_DEPCMDPAR_0_1_INDEX       0x00003206
#define USBC_DEPCMDPAR_0_1_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_1_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_1_ADDR);
}

__INLINE void usbc_depcmdpar_0_1_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_1_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_1_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_1_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_1_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_1_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_1_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_1_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_1_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_1 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_1_ADDR        (REG_USBC_BASE_ADDR+0x0000C81C)
#define USBC_DEPCMD_1_OFFSET      0x0000C81C
#define USBC_DEPCMD_1_INDEX       0x00003207
#define USBC_DEPCMD_1_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_1_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_1_ADDR);
}

__INLINE void usbc_depcmd_1_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_1_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_1_COMMANDPARAM_MASK     ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_1_COMMANDPARAM_LSB      16
#define USBC_DEPCMD_1_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_1_CMDSTATUS_MASK        ((uint32_t)0x0000F000)
#define USBC_DEPCMD_1_CMDSTATUS_LSB         12
#define USBC_DEPCMD_1_CMDSTATUS_WIDTH       ((uint32_t)0x00000004)
#define USBC_DEPCMD_1_HIPRI_FORCERM_BIT     ((uint32_t)0x00000800)
#define USBC_DEPCMD_1_HIPRI_FORCERM_POS     11
#define USBC_DEPCMD_1_CMDACT_BIT            ((uint32_t)0x00000400)
#define USBC_DEPCMD_1_CMDACT_POS            10
#define USBC_DEPCMD_1_RESERVED_9_BIT        ((uint32_t)0x00000200)
#define USBC_DEPCMD_1_RESERVED_9_POS        9
#define USBC_DEPCMD_1_CMDIOC_BIT            ((uint32_t)0x00000100)
#define USBC_DEPCMD_1_CMDIOC_POS            8
#define USBC_DEPCMD_1_RESERVED_7_4_MASK     ((uint32_t)0x000000F0)
#define USBC_DEPCMD_1_RESERVED_7_4_LSB      4
#define USBC_DEPCMD_1_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_1_CMDTYP_MASK           ((uint32_t)0x0000000F)
#define USBC_DEPCMD_1_CMDTYP_LSB            0
#define USBC_DEPCMD_1_CMDTYP_WIDTH          ((uint32_t)0x00000004)

#define USBC_DEPCMD_1_COMMANDPARAM_RST      0x0
#define USBC_DEPCMD_1_CMDSTATUS_RST         0x0
#define USBC_DEPCMD_1_HIPRI_FORCERM_RST     0x0
#define USBC_DEPCMD_1_CMDACT_RST            0x0
#define USBC_DEPCMD_1_RESERVED_9_RST        0x0
#define USBC_DEPCMD_1_CMDIOC_RST            0x0
#define USBC_DEPCMD_1_RESERVED_7_4_RST      0x0
#define USBC_DEPCMD_1_CMDTYP_RST            0x0

__INLINE void usbc_depcmd_1_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_1_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_1_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_1_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_1_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_1_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_1_ADDR, (REG_PL_RD(USBC_DEPCMD_1_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_1_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_1_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_1_ADDR, (REG_PL_RD(USBC_DEPCMD_1_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_1_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_1_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_1_ADDR, (REG_PL_RD(USBC_DEPCMD_1_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_1_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_1_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_1_ADDR, (REG_PL_RD(USBC_DEPCMD_1_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_1_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_1_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_1_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_1_ADDR, (REG_PL_RD(USBC_DEPCMD_1_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_1_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_1_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_1_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_1_ADDR, (REG_PL_RD(USBC_DEPCMD_1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_2 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_2_ADDR        (REG_USBC_BASE_ADDR+0x0000C820)
#define USBC_DEPCMDPAR_2_2_OFFSET      0x0000C820
#define USBC_DEPCMDPAR_2_2_INDEX       0x00003208
#define USBC_DEPCMDPAR_2_2_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_2_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_2_ADDR);
}

__INLINE void usbc_depcmdpar_2_2_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_2_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_2_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_2_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_2_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_2_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_2_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_2_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_2_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_2 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_2_ADDR        (REG_USBC_BASE_ADDR+0x0000C824)
#define USBC_DEPCMDPAR_1_2_OFFSET      0x0000C824
#define USBC_DEPCMDPAR_1_2_INDEX       0x00003209
#define USBC_DEPCMDPAR_1_2_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_2_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_2_ADDR);
}

__INLINE void usbc_depcmdpar_1_2_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_2_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_2_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_2_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_2_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_2_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_2_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_2_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_2_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_2 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_2_ADDR        (REG_USBC_BASE_ADDR+0x0000C828)
#define USBC_DEPCMDPAR_0_2_OFFSET      0x0000C828
#define USBC_DEPCMDPAR_0_2_INDEX       0x0000320A
#define USBC_DEPCMDPAR_0_2_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_2_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_2_ADDR);
}

__INLINE void usbc_depcmdpar_0_2_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_2_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_2_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_2_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_2_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_2_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_2_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_2_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_2_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_2 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_2_ADDR        (REG_USBC_BASE_ADDR+0x0000C82C)
#define USBC_DEPCMD_2_OFFSET      0x0000C82C
#define USBC_DEPCMD_2_INDEX       0x0000320B
#define USBC_DEPCMD_2_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_2_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_2_ADDR);
}

__INLINE void usbc_depcmd_2_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_2_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_2_COMMANDPARAM_MASK     ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_2_COMMANDPARAM_LSB      16
#define USBC_DEPCMD_2_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_2_CMDSTATUS_MASK        ((uint32_t)0x0000F000)
#define USBC_DEPCMD_2_CMDSTATUS_LSB         12
#define USBC_DEPCMD_2_CMDSTATUS_WIDTH       ((uint32_t)0x00000004)
#define USBC_DEPCMD_2_HIPRI_FORCERM_BIT     ((uint32_t)0x00000800)
#define USBC_DEPCMD_2_HIPRI_FORCERM_POS     11
#define USBC_DEPCMD_2_CMDACT_BIT            ((uint32_t)0x00000400)
#define USBC_DEPCMD_2_CMDACT_POS            10
#define USBC_DEPCMD_2_RESERVED_9_BIT        ((uint32_t)0x00000200)
#define USBC_DEPCMD_2_RESERVED_9_POS        9
#define USBC_DEPCMD_2_CMDIOC_BIT            ((uint32_t)0x00000100)
#define USBC_DEPCMD_2_CMDIOC_POS            8
#define USBC_DEPCMD_2_RESERVED_7_4_MASK     ((uint32_t)0x000000F0)
#define USBC_DEPCMD_2_RESERVED_7_4_LSB      4
#define USBC_DEPCMD_2_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_2_CMDTYP_MASK           ((uint32_t)0x0000000F)
#define USBC_DEPCMD_2_CMDTYP_LSB            0
#define USBC_DEPCMD_2_CMDTYP_WIDTH          ((uint32_t)0x00000004)

#define USBC_DEPCMD_2_COMMANDPARAM_RST      0x0
#define USBC_DEPCMD_2_CMDSTATUS_RST         0x0
#define USBC_DEPCMD_2_HIPRI_FORCERM_RST     0x0
#define USBC_DEPCMD_2_CMDACT_RST            0x0
#define USBC_DEPCMD_2_RESERVED_9_RST        0x0
#define USBC_DEPCMD_2_CMDIOC_RST            0x0
#define USBC_DEPCMD_2_RESERVED_7_4_RST      0x0
#define USBC_DEPCMD_2_CMDTYP_RST            0x0

__INLINE void usbc_depcmd_2_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_2_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_2_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_2_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_2_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_2_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_2_ADDR, (REG_PL_RD(USBC_DEPCMD_2_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_2_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_2_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_2_ADDR, (REG_PL_RD(USBC_DEPCMD_2_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_2_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_2_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_2_ADDR, (REG_PL_RD(USBC_DEPCMD_2_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_2_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_2_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_2_ADDR, (REG_PL_RD(USBC_DEPCMD_2_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_2_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_2_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_2_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_2_ADDR, (REG_PL_RD(USBC_DEPCMD_2_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_2_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_2_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_2_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_2_ADDR, (REG_PL_RD(USBC_DEPCMD_2_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_3 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_3_ADDR        (REG_USBC_BASE_ADDR+0x0000C830)
#define USBC_DEPCMDPAR_2_3_OFFSET      0x0000C830
#define USBC_DEPCMDPAR_2_3_INDEX       0x0000320C
#define USBC_DEPCMDPAR_2_3_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_3_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_3_ADDR);
}

__INLINE void usbc_depcmdpar_2_3_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_3_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_3_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_3_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_3_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_3_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_3_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_3_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_3_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_3 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_3_ADDR        (REG_USBC_BASE_ADDR+0x0000C834)
#define USBC_DEPCMDPAR_1_3_OFFSET      0x0000C834
#define USBC_DEPCMDPAR_1_3_INDEX       0x0000320D
#define USBC_DEPCMDPAR_1_3_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_3_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_3_ADDR);
}

__INLINE void usbc_depcmdpar_1_3_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_3_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_3_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_3_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_3_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_3_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_3_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_3_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_3_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_3 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_3_ADDR        (REG_USBC_BASE_ADDR+0x0000C838)
#define USBC_DEPCMDPAR_0_3_OFFSET      0x0000C838
#define USBC_DEPCMDPAR_0_3_INDEX       0x0000320E
#define USBC_DEPCMDPAR_0_3_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_3_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_3_ADDR);
}

__INLINE void usbc_depcmdpar_0_3_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_3_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_3_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_3_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_3_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_3_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_3_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_3_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_3_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_3 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_3_ADDR        (REG_USBC_BASE_ADDR+0x0000C83C)
#define USBC_DEPCMD_3_OFFSET      0x0000C83C
#define USBC_DEPCMD_3_INDEX       0x0000320F
#define USBC_DEPCMD_3_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_3_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_3_ADDR);
}

__INLINE void usbc_depcmd_3_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_3_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_3_COMMANDPARAM_MASK     ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_3_COMMANDPARAM_LSB      16
#define USBC_DEPCMD_3_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_3_CMDSTATUS_MASK        ((uint32_t)0x0000F000)
#define USBC_DEPCMD_3_CMDSTATUS_LSB         12
#define USBC_DEPCMD_3_CMDSTATUS_WIDTH       ((uint32_t)0x00000004)
#define USBC_DEPCMD_3_HIPRI_FORCERM_BIT     ((uint32_t)0x00000800)
#define USBC_DEPCMD_3_HIPRI_FORCERM_POS     11
#define USBC_DEPCMD_3_CMDACT_BIT            ((uint32_t)0x00000400)
#define USBC_DEPCMD_3_CMDACT_POS            10
#define USBC_DEPCMD_3_RESERVED_9_BIT        ((uint32_t)0x00000200)
#define USBC_DEPCMD_3_RESERVED_9_POS        9
#define USBC_DEPCMD_3_CMDIOC_BIT            ((uint32_t)0x00000100)
#define USBC_DEPCMD_3_CMDIOC_POS            8
#define USBC_DEPCMD_3_RESERVED_7_4_MASK     ((uint32_t)0x000000F0)
#define USBC_DEPCMD_3_RESERVED_7_4_LSB      4
#define USBC_DEPCMD_3_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_3_CMDTYP_MASK           ((uint32_t)0x0000000F)
#define USBC_DEPCMD_3_CMDTYP_LSB            0
#define USBC_DEPCMD_3_CMDTYP_WIDTH          ((uint32_t)0x00000004)

#define USBC_DEPCMD_3_COMMANDPARAM_RST      0x0
#define USBC_DEPCMD_3_CMDSTATUS_RST         0x0
#define USBC_DEPCMD_3_HIPRI_FORCERM_RST     0x0
#define USBC_DEPCMD_3_CMDACT_RST            0x0
#define USBC_DEPCMD_3_RESERVED_9_RST        0x0
#define USBC_DEPCMD_3_CMDIOC_RST            0x0
#define USBC_DEPCMD_3_RESERVED_7_4_RST      0x0
#define USBC_DEPCMD_3_CMDTYP_RST            0x0

__INLINE void usbc_depcmd_3_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_3_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_3_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_3_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_3_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_3_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_3_ADDR, (REG_PL_RD(USBC_DEPCMD_3_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_3_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_3_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_3_ADDR, (REG_PL_RD(USBC_DEPCMD_3_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_3_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_3_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_3_ADDR, (REG_PL_RD(USBC_DEPCMD_3_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_3_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_3_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_3_ADDR, (REG_PL_RD(USBC_DEPCMD_3_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_3_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_3_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_3_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_3_ADDR, (REG_PL_RD(USBC_DEPCMD_3_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_3_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_3_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_3_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_3_ADDR, (REG_PL_RD(USBC_DEPCMD_3_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_4 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_4_ADDR        (REG_USBC_BASE_ADDR+0x0000C840)
#define USBC_DEPCMDPAR_2_4_OFFSET      0x0000C840
#define USBC_DEPCMDPAR_2_4_INDEX       0x00003210
#define USBC_DEPCMDPAR_2_4_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_4_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_4_ADDR);
}

__INLINE void usbc_depcmdpar_2_4_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_4_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_4_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_4_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_4_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_4_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_4_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_4_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_4_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_4 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_4_ADDR        (REG_USBC_BASE_ADDR+0x0000C844)
#define USBC_DEPCMDPAR_1_4_OFFSET      0x0000C844
#define USBC_DEPCMDPAR_1_4_INDEX       0x00003211
#define USBC_DEPCMDPAR_1_4_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_4_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_4_ADDR);
}

__INLINE void usbc_depcmdpar_1_4_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_4_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_4_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_4_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_4_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_4_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_4_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_4_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_4_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_4 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_4_ADDR        (REG_USBC_BASE_ADDR+0x0000C848)
#define USBC_DEPCMDPAR_0_4_OFFSET      0x0000C848
#define USBC_DEPCMDPAR_0_4_INDEX       0x00003212
#define USBC_DEPCMDPAR_0_4_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_4_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_4_ADDR);
}

__INLINE void usbc_depcmdpar_0_4_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_4_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_4_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_4_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_4_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_4_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_4_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_4_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_4_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_4 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_4_ADDR        (REG_USBC_BASE_ADDR+0x0000C84C)
#define USBC_DEPCMD_4_OFFSET      0x0000C84C
#define USBC_DEPCMD_4_INDEX       0x00003213
#define USBC_DEPCMD_4_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_4_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_4_ADDR);
}

__INLINE void usbc_depcmd_4_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_4_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_4_COMMANDPARAM_MASK     ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_4_COMMANDPARAM_LSB      16
#define USBC_DEPCMD_4_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_4_CMDSTATUS_MASK        ((uint32_t)0x0000F000)
#define USBC_DEPCMD_4_CMDSTATUS_LSB         12
#define USBC_DEPCMD_4_CMDSTATUS_WIDTH       ((uint32_t)0x00000004)
#define USBC_DEPCMD_4_HIPRI_FORCERM_BIT     ((uint32_t)0x00000800)
#define USBC_DEPCMD_4_HIPRI_FORCERM_POS     11
#define USBC_DEPCMD_4_CMDACT_BIT            ((uint32_t)0x00000400)
#define USBC_DEPCMD_4_CMDACT_POS            10
#define USBC_DEPCMD_4_RESERVED_9_BIT        ((uint32_t)0x00000200)
#define USBC_DEPCMD_4_RESERVED_9_POS        9
#define USBC_DEPCMD_4_CMDIOC_BIT            ((uint32_t)0x00000100)
#define USBC_DEPCMD_4_CMDIOC_POS            8
#define USBC_DEPCMD_4_RESERVED_7_4_MASK     ((uint32_t)0x000000F0)
#define USBC_DEPCMD_4_RESERVED_7_4_LSB      4
#define USBC_DEPCMD_4_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_4_CMDTYP_MASK           ((uint32_t)0x0000000F)
#define USBC_DEPCMD_4_CMDTYP_LSB            0
#define USBC_DEPCMD_4_CMDTYP_WIDTH          ((uint32_t)0x00000004)

#define USBC_DEPCMD_4_COMMANDPARAM_RST      0x0
#define USBC_DEPCMD_4_CMDSTATUS_RST         0x0
#define USBC_DEPCMD_4_HIPRI_FORCERM_RST     0x0
#define USBC_DEPCMD_4_CMDACT_RST            0x0
#define USBC_DEPCMD_4_RESERVED_9_RST        0x0
#define USBC_DEPCMD_4_CMDIOC_RST            0x0
#define USBC_DEPCMD_4_RESERVED_7_4_RST      0x0
#define USBC_DEPCMD_4_CMDTYP_RST            0x0

__INLINE void usbc_depcmd_4_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_4_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_4_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_4_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_4_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_4_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_4_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_4_ADDR, (REG_PL_RD(USBC_DEPCMD_4_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_4_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_4_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_4_ADDR, (REG_PL_RD(USBC_DEPCMD_4_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_4_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_4_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_4_ADDR, (REG_PL_RD(USBC_DEPCMD_4_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_4_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_4_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_4_ADDR, (REG_PL_RD(USBC_DEPCMD_4_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_4_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_4_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_4_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_4_ADDR, (REG_PL_RD(USBC_DEPCMD_4_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_4_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_4_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_4_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_4_ADDR, (REG_PL_RD(USBC_DEPCMD_4_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_5 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_5_ADDR        (REG_USBC_BASE_ADDR+0x0000C850)
#define USBC_DEPCMDPAR_2_5_OFFSET      0x0000C850
#define USBC_DEPCMDPAR_2_5_INDEX       0x00003214
#define USBC_DEPCMDPAR_2_5_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_5_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_5_ADDR);
}

__INLINE void usbc_depcmdpar_2_5_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_5_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_5_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_5_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_5_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_5_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_5_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_5_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_5_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_5 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_5_ADDR        (REG_USBC_BASE_ADDR+0x0000C854)
#define USBC_DEPCMDPAR_1_5_OFFSET      0x0000C854
#define USBC_DEPCMDPAR_1_5_INDEX       0x00003215
#define USBC_DEPCMDPAR_1_5_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_5_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_5_ADDR);
}

__INLINE void usbc_depcmdpar_1_5_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_5_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_5_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_5_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_5_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_5_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_5_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_5_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_5_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_5 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_5_ADDR        (REG_USBC_BASE_ADDR+0x0000C858)
#define USBC_DEPCMDPAR_0_5_OFFSET      0x0000C858
#define USBC_DEPCMDPAR_0_5_INDEX       0x00003216
#define USBC_DEPCMDPAR_0_5_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_5_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_5_ADDR);
}

__INLINE void usbc_depcmdpar_0_5_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_5_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_5_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_5_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_5_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_5_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_5_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_5_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_5_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_5 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_5_ADDR        (REG_USBC_BASE_ADDR+0x0000C85C)
#define USBC_DEPCMD_5_OFFSET      0x0000C85C
#define USBC_DEPCMD_5_INDEX       0x00003217
#define USBC_DEPCMD_5_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_5_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_5_ADDR);
}

__INLINE void usbc_depcmd_5_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_5_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_5_COMMANDPARAM_MASK     ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_5_COMMANDPARAM_LSB      16
#define USBC_DEPCMD_5_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_5_CMDSTATUS_MASK        ((uint32_t)0x0000F000)
#define USBC_DEPCMD_5_CMDSTATUS_LSB         12
#define USBC_DEPCMD_5_CMDSTATUS_WIDTH       ((uint32_t)0x00000004)
#define USBC_DEPCMD_5_HIPRI_FORCERM_BIT     ((uint32_t)0x00000800)
#define USBC_DEPCMD_5_HIPRI_FORCERM_POS     11
#define USBC_DEPCMD_5_CMDACT_BIT            ((uint32_t)0x00000400)
#define USBC_DEPCMD_5_CMDACT_POS            10
#define USBC_DEPCMD_5_RESERVED_9_BIT        ((uint32_t)0x00000200)
#define USBC_DEPCMD_5_RESERVED_9_POS        9
#define USBC_DEPCMD_5_CMDIOC_BIT            ((uint32_t)0x00000100)
#define USBC_DEPCMD_5_CMDIOC_POS            8
#define USBC_DEPCMD_5_RESERVED_7_4_MASK     ((uint32_t)0x000000F0)
#define USBC_DEPCMD_5_RESERVED_7_4_LSB      4
#define USBC_DEPCMD_5_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_5_CMDTYP_MASK           ((uint32_t)0x0000000F)
#define USBC_DEPCMD_5_CMDTYP_LSB            0
#define USBC_DEPCMD_5_CMDTYP_WIDTH          ((uint32_t)0x00000004)

#define USBC_DEPCMD_5_COMMANDPARAM_RST      0x0
#define USBC_DEPCMD_5_CMDSTATUS_RST         0x0
#define USBC_DEPCMD_5_HIPRI_FORCERM_RST     0x0
#define USBC_DEPCMD_5_CMDACT_RST            0x0
#define USBC_DEPCMD_5_RESERVED_9_RST        0x0
#define USBC_DEPCMD_5_CMDIOC_RST            0x0
#define USBC_DEPCMD_5_RESERVED_7_4_RST      0x0
#define USBC_DEPCMD_5_CMDTYP_RST            0x0

__INLINE void usbc_depcmd_5_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_5_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_5_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_5_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_5_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_5_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_5_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_5_ADDR, (REG_PL_RD(USBC_DEPCMD_5_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_5_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_5_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_5_ADDR, (REG_PL_RD(USBC_DEPCMD_5_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_5_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_5_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_5_ADDR, (REG_PL_RD(USBC_DEPCMD_5_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_5_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_5_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_5_ADDR, (REG_PL_RD(USBC_DEPCMD_5_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_5_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_5_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_5_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_5_ADDR, (REG_PL_RD(USBC_DEPCMD_5_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_5_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_5_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_5_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_5_ADDR, (REG_PL_RD(USBC_DEPCMD_5_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_6 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_6_ADDR        (REG_USBC_BASE_ADDR+0x0000C860)
#define USBC_DEPCMDPAR_2_6_OFFSET      0x0000C860
#define USBC_DEPCMDPAR_2_6_INDEX       0x00003218
#define USBC_DEPCMDPAR_2_6_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_6_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_6_ADDR);
}

__INLINE void usbc_depcmdpar_2_6_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_6_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_6_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_6_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_6_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_6_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_6_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_6_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_6_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_6 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_6_ADDR        (REG_USBC_BASE_ADDR+0x0000C864)
#define USBC_DEPCMDPAR_1_6_OFFSET      0x0000C864
#define USBC_DEPCMDPAR_1_6_INDEX       0x00003219
#define USBC_DEPCMDPAR_1_6_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_6_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_6_ADDR);
}

__INLINE void usbc_depcmdpar_1_6_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_6_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_6_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_6_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_6_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_6_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_6_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_6_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_6_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_6 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_6_ADDR        (REG_USBC_BASE_ADDR+0x0000C868)
#define USBC_DEPCMDPAR_0_6_OFFSET      0x0000C868
#define USBC_DEPCMDPAR_0_6_INDEX       0x0000321A
#define USBC_DEPCMDPAR_0_6_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_6_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_6_ADDR);
}

__INLINE void usbc_depcmdpar_0_6_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_6_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_6_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_6_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_6_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_6_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_6_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_6_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_6_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_6 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_6_ADDR        (REG_USBC_BASE_ADDR+0x0000C86C)
#define USBC_DEPCMD_6_OFFSET      0x0000C86C
#define USBC_DEPCMD_6_INDEX       0x0000321B
#define USBC_DEPCMD_6_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_6_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_6_ADDR);
}

__INLINE void usbc_depcmd_6_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_6_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_6_COMMANDPARAM_MASK     ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_6_COMMANDPARAM_LSB      16
#define USBC_DEPCMD_6_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_6_CMDSTATUS_MASK        ((uint32_t)0x0000F000)
#define USBC_DEPCMD_6_CMDSTATUS_LSB         12
#define USBC_DEPCMD_6_CMDSTATUS_WIDTH       ((uint32_t)0x00000004)
#define USBC_DEPCMD_6_HIPRI_FORCERM_BIT     ((uint32_t)0x00000800)
#define USBC_DEPCMD_6_HIPRI_FORCERM_POS     11
#define USBC_DEPCMD_6_CMDACT_BIT            ((uint32_t)0x00000400)
#define USBC_DEPCMD_6_CMDACT_POS            10
#define USBC_DEPCMD_6_RESERVED_9_BIT        ((uint32_t)0x00000200)
#define USBC_DEPCMD_6_RESERVED_9_POS        9
#define USBC_DEPCMD_6_CMDIOC_BIT            ((uint32_t)0x00000100)
#define USBC_DEPCMD_6_CMDIOC_POS            8
#define USBC_DEPCMD_6_RESERVED_7_4_MASK     ((uint32_t)0x000000F0)
#define USBC_DEPCMD_6_RESERVED_7_4_LSB      4
#define USBC_DEPCMD_6_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_6_CMDTYP_MASK           ((uint32_t)0x0000000F)
#define USBC_DEPCMD_6_CMDTYP_LSB            0
#define USBC_DEPCMD_6_CMDTYP_WIDTH          ((uint32_t)0x00000004)

#define USBC_DEPCMD_6_COMMANDPARAM_RST      0x0
#define USBC_DEPCMD_6_CMDSTATUS_RST         0x0
#define USBC_DEPCMD_6_HIPRI_FORCERM_RST     0x0
#define USBC_DEPCMD_6_CMDACT_RST            0x0
#define USBC_DEPCMD_6_RESERVED_9_RST        0x0
#define USBC_DEPCMD_6_CMDIOC_RST            0x0
#define USBC_DEPCMD_6_RESERVED_7_4_RST      0x0
#define USBC_DEPCMD_6_CMDTYP_RST            0x0

__INLINE void usbc_depcmd_6_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_6_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_6_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_6_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_6_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_6_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_6_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_6_ADDR, (REG_PL_RD(USBC_DEPCMD_6_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_6_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_6_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_6_ADDR, (REG_PL_RD(USBC_DEPCMD_6_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_6_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_6_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_6_ADDR, (REG_PL_RD(USBC_DEPCMD_6_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_6_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_6_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_6_ADDR, (REG_PL_RD(USBC_DEPCMD_6_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_6_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_6_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_6_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_6_ADDR, (REG_PL_RD(USBC_DEPCMD_6_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_6_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_6_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_6_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_6_ADDR, (REG_PL_RD(USBC_DEPCMD_6_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_7 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_7_ADDR        (REG_USBC_BASE_ADDR+0x0000C870)
#define USBC_DEPCMDPAR_2_7_OFFSET      0x0000C870
#define USBC_DEPCMDPAR_2_7_INDEX       0x0000321C
#define USBC_DEPCMDPAR_2_7_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_7_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_7_ADDR);
}

__INLINE void usbc_depcmdpar_2_7_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_7_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_7_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_7_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_7_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_7_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_7_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_7_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_7_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_7 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_7_ADDR        (REG_USBC_BASE_ADDR+0x0000C874)
#define USBC_DEPCMDPAR_1_7_OFFSET      0x0000C874
#define USBC_DEPCMDPAR_1_7_INDEX       0x0000321D
#define USBC_DEPCMDPAR_1_7_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_7_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_7_ADDR);
}

__INLINE void usbc_depcmdpar_1_7_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_7_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_7_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_7_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_7_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_7_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_7_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_7_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_7_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_7 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_7_ADDR        (REG_USBC_BASE_ADDR+0x0000C878)
#define USBC_DEPCMDPAR_0_7_OFFSET      0x0000C878
#define USBC_DEPCMDPAR_0_7_INDEX       0x0000321E
#define USBC_DEPCMDPAR_0_7_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_7_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_7_ADDR);
}

__INLINE void usbc_depcmdpar_0_7_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_7_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_7_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_7_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_7_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_7_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_7_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_7_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_7_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_7 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_7_ADDR        (REG_USBC_BASE_ADDR+0x0000C87C)
#define USBC_DEPCMD_7_OFFSET      0x0000C87C
#define USBC_DEPCMD_7_INDEX       0x0000321F
#define USBC_DEPCMD_7_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_7_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_7_ADDR);
}

__INLINE void usbc_depcmd_7_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_7_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_7_COMMANDPARAM_MASK     ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_7_COMMANDPARAM_LSB      16
#define USBC_DEPCMD_7_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_7_CMDSTATUS_MASK        ((uint32_t)0x0000F000)
#define USBC_DEPCMD_7_CMDSTATUS_LSB         12
#define USBC_DEPCMD_7_CMDSTATUS_WIDTH       ((uint32_t)0x00000004)
#define USBC_DEPCMD_7_HIPRI_FORCERM_BIT     ((uint32_t)0x00000800)
#define USBC_DEPCMD_7_HIPRI_FORCERM_POS     11
#define USBC_DEPCMD_7_CMDACT_BIT            ((uint32_t)0x00000400)
#define USBC_DEPCMD_7_CMDACT_POS            10
#define USBC_DEPCMD_7_RESERVED_9_BIT        ((uint32_t)0x00000200)
#define USBC_DEPCMD_7_RESERVED_9_POS        9
#define USBC_DEPCMD_7_CMDIOC_BIT            ((uint32_t)0x00000100)
#define USBC_DEPCMD_7_CMDIOC_POS            8
#define USBC_DEPCMD_7_RESERVED_7_4_MASK     ((uint32_t)0x000000F0)
#define USBC_DEPCMD_7_RESERVED_7_4_LSB      4
#define USBC_DEPCMD_7_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_7_CMDTYP_MASK           ((uint32_t)0x0000000F)
#define USBC_DEPCMD_7_CMDTYP_LSB            0
#define USBC_DEPCMD_7_CMDTYP_WIDTH          ((uint32_t)0x00000004)

#define USBC_DEPCMD_7_COMMANDPARAM_RST      0x0
#define USBC_DEPCMD_7_CMDSTATUS_RST         0x0
#define USBC_DEPCMD_7_HIPRI_FORCERM_RST     0x0
#define USBC_DEPCMD_7_CMDACT_RST            0x0
#define USBC_DEPCMD_7_RESERVED_9_RST        0x0
#define USBC_DEPCMD_7_CMDIOC_RST            0x0
#define USBC_DEPCMD_7_RESERVED_7_4_RST      0x0
#define USBC_DEPCMD_7_CMDTYP_RST            0x0

__INLINE void usbc_depcmd_7_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_7_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_7_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_7_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_7_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_7_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_7_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_7_ADDR, (REG_PL_RD(USBC_DEPCMD_7_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_7_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_7_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_7_ADDR, (REG_PL_RD(USBC_DEPCMD_7_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_7_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_7_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_7_ADDR, (REG_PL_RD(USBC_DEPCMD_7_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_7_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_7_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_7_ADDR, (REG_PL_RD(USBC_DEPCMD_7_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_7_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_7_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_7_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_7_ADDR, (REG_PL_RD(USBC_DEPCMD_7_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_7_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_7_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_7_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_7_ADDR, (REG_PL_RD(USBC_DEPCMD_7_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_8 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_8_ADDR        (REG_USBC_BASE_ADDR+0x0000C880)
#define USBC_DEPCMDPAR_2_8_OFFSET      0x0000C880
#define USBC_DEPCMDPAR_2_8_INDEX       0x00003220
#define USBC_DEPCMDPAR_2_8_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_8_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_8_ADDR);
}

__INLINE void usbc_depcmdpar_2_8_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_8_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_8_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_8_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_8_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_8_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_8_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_8_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_8_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_8_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_8 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_8_ADDR        (REG_USBC_BASE_ADDR+0x0000C884)
#define USBC_DEPCMDPAR_1_8_OFFSET      0x0000C884
#define USBC_DEPCMDPAR_1_8_INDEX       0x00003221
#define USBC_DEPCMDPAR_1_8_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_8_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_8_ADDR);
}

__INLINE void usbc_depcmdpar_1_8_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_8_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_8_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_8_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_8_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_8_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_8_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_8_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_8_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_8_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_8 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_8_ADDR        (REG_USBC_BASE_ADDR+0x0000C888)
#define USBC_DEPCMDPAR_0_8_OFFSET      0x0000C888
#define USBC_DEPCMDPAR_0_8_INDEX       0x00003222
#define USBC_DEPCMDPAR_0_8_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_8_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_8_ADDR);
}

__INLINE void usbc_depcmdpar_0_8_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_8_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_8_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_8_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_8_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_8_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_8_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_8_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_8_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_8_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_8 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_8_ADDR        (REG_USBC_BASE_ADDR+0x0000C88C)
#define USBC_DEPCMD_8_OFFSET      0x0000C88C
#define USBC_DEPCMD_8_INDEX       0x00003223
#define USBC_DEPCMD_8_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_8_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_8_ADDR);
}

__INLINE void usbc_depcmd_8_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_8_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_8_COMMANDPARAM_MASK     ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_8_COMMANDPARAM_LSB      16
#define USBC_DEPCMD_8_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_8_CMDSTATUS_MASK        ((uint32_t)0x0000F000)
#define USBC_DEPCMD_8_CMDSTATUS_LSB         12
#define USBC_DEPCMD_8_CMDSTATUS_WIDTH       ((uint32_t)0x00000004)
#define USBC_DEPCMD_8_HIPRI_FORCERM_BIT     ((uint32_t)0x00000800)
#define USBC_DEPCMD_8_HIPRI_FORCERM_POS     11
#define USBC_DEPCMD_8_CMDACT_BIT            ((uint32_t)0x00000400)
#define USBC_DEPCMD_8_CMDACT_POS            10
#define USBC_DEPCMD_8_RESERVED_9_BIT        ((uint32_t)0x00000200)
#define USBC_DEPCMD_8_RESERVED_9_POS        9
#define USBC_DEPCMD_8_CMDIOC_BIT            ((uint32_t)0x00000100)
#define USBC_DEPCMD_8_CMDIOC_POS            8
#define USBC_DEPCMD_8_RESERVED_7_4_MASK     ((uint32_t)0x000000F0)
#define USBC_DEPCMD_8_RESERVED_7_4_LSB      4
#define USBC_DEPCMD_8_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_8_CMDTYP_MASK           ((uint32_t)0x0000000F)
#define USBC_DEPCMD_8_CMDTYP_LSB            0
#define USBC_DEPCMD_8_CMDTYP_WIDTH          ((uint32_t)0x00000004)

#define USBC_DEPCMD_8_COMMANDPARAM_RST      0x0
#define USBC_DEPCMD_8_CMDSTATUS_RST         0x0
#define USBC_DEPCMD_8_HIPRI_FORCERM_RST     0x0
#define USBC_DEPCMD_8_CMDACT_RST            0x0
#define USBC_DEPCMD_8_RESERVED_9_RST        0x0
#define USBC_DEPCMD_8_CMDIOC_RST            0x0
#define USBC_DEPCMD_8_RESERVED_7_4_RST      0x0
#define USBC_DEPCMD_8_CMDTYP_RST            0x0

__INLINE void usbc_depcmd_8_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_8_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_8_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_8_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_8_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_8_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_8_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_8_ADDR, (REG_PL_RD(USBC_DEPCMD_8_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_8_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_8_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_8_ADDR, (REG_PL_RD(USBC_DEPCMD_8_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_8_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_8_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_8_ADDR, (REG_PL_RD(USBC_DEPCMD_8_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_8_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_8_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_8_ADDR, (REG_PL_RD(USBC_DEPCMD_8_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_8_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_8_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_8_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_8_ADDR, (REG_PL_RD(USBC_DEPCMD_8_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_8_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_8_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_8_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_8_ADDR, (REG_PL_RD(USBC_DEPCMD_8_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_9 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_9_ADDR        (REG_USBC_BASE_ADDR+0x0000C890)
#define USBC_DEPCMDPAR_2_9_OFFSET      0x0000C890
#define USBC_DEPCMDPAR_2_9_INDEX       0x00003224
#define USBC_DEPCMDPAR_2_9_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_9_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_9_ADDR);
}

__INLINE void usbc_depcmdpar_2_9_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_9_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_9_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_9_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_9_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_9_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_9_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_9_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_9_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_9_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_9 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_9_ADDR        (REG_USBC_BASE_ADDR+0x0000C894)
#define USBC_DEPCMDPAR_1_9_OFFSET      0x0000C894
#define USBC_DEPCMDPAR_1_9_INDEX       0x00003225
#define USBC_DEPCMDPAR_1_9_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_9_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_9_ADDR);
}

__INLINE void usbc_depcmdpar_1_9_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_9_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_9_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_9_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_9_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_9_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_9_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_9_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_9_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_9_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_9 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_9_ADDR        (REG_USBC_BASE_ADDR+0x0000C898)
#define USBC_DEPCMDPAR_0_9_OFFSET      0x0000C898
#define USBC_DEPCMDPAR_0_9_INDEX       0x00003226
#define USBC_DEPCMDPAR_0_9_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_9_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_9_ADDR);
}

__INLINE void usbc_depcmdpar_0_9_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_9_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_9_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_9_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_9_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_9_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_9_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_9_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_9_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_9_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_9 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_9_ADDR        (REG_USBC_BASE_ADDR+0x0000C89C)
#define USBC_DEPCMD_9_OFFSET      0x0000C89C
#define USBC_DEPCMD_9_INDEX       0x00003227
#define USBC_DEPCMD_9_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_9_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_9_ADDR);
}

__INLINE void usbc_depcmd_9_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_9_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_9_COMMANDPARAM_MASK     ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_9_COMMANDPARAM_LSB      16
#define USBC_DEPCMD_9_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_9_CMDSTATUS_MASK        ((uint32_t)0x0000F000)
#define USBC_DEPCMD_9_CMDSTATUS_LSB         12
#define USBC_DEPCMD_9_CMDSTATUS_WIDTH       ((uint32_t)0x00000004)
#define USBC_DEPCMD_9_HIPRI_FORCERM_BIT     ((uint32_t)0x00000800)
#define USBC_DEPCMD_9_HIPRI_FORCERM_POS     11
#define USBC_DEPCMD_9_CMDACT_BIT            ((uint32_t)0x00000400)
#define USBC_DEPCMD_9_CMDACT_POS            10
#define USBC_DEPCMD_9_RESERVED_9_BIT        ((uint32_t)0x00000200)
#define USBC_DEPCMD_9_RESERVED_9_POS        9
#define USBC_DEPCMD_9_CMDIOC_BIT            ((uint32_t)0x00000100)
#define USBC_DEPCMD_9_CMDIOC_POS            8
#define USBC_DEPCMD_9_RESERVED_7_4_MASK     ((uint32_t)0x000000F0)
#define USBC_DEPCMD_9_RESERVED_7_4_LSB      4
#define USBC_DEPCMD_9_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_9_CMDTYP_MASK           ((uint32_t)0x0000000F)
#define USBC_DEPCMD_9_CMDTYP_LSB            0
#define USBC_DEPCMD_9_CMDTYP_WIDTH          ((uint32_t)0x00000004)

#define USBC_DEPCMD_9_COMMANDPARAM_RST      0x0
#define USBC_DEPCMD_9_CMDSTATUS_RST         0x0
#define USBC_DEPCMD_9_HIPRI_FORCERM_RST     0x0
#define USBC_DEPCMD_9_CMDACT_RST            0x0
#define USBC_DEPCMD_9_RESERVED_9_RST        0x0
#define USBC_DEPCMD_9_CMDIOC_RST            0x0
#define USBC_DEPCMD_9_RESERVED_7_4_RST      0x0
#define USBC_DEPCMD_9_CMDTYP_RST            0x0

__INLINE void usbc_depcmd_9_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_9_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_9_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_9_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_9_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_9_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_9_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_9_ADDR, (REG_PL_RD(USBC_DEPCMD_9_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_9_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_9_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_9_ADDR, (REG_PL_RD(USBC_DEPCMD_9_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_9_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_9_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_9_ADDR, (REG_PL_RD(USBC_DEPCMD_9_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_9_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_9_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_9_ADDR, (REG_PL_RD(USBC_DEPCMD_9_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_9_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_9_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_9_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_9_ADDR, (REG_PL_RD(USBC_DEPCMD_9_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_9_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_9_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_9_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_9_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_9_ADDR, (REG_PL_RD(USBC_DEPCMD_9_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_10 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_10_ADDR        (REG_USBC_BASE_ADDR+0x0000C8A0)
#define USBC_DEPCMDPAR_2_10_OFFSET      0x0000C8A0
#define USBC_DEPCMDPAR_2_10_INDEX       0x00003228
#define USBC_DEPCMDPAR_2_10_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_10_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_10_ADDR);
}

__INLINE void usbc_depcmdpar_2_10_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_10_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_10_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_10_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_10_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_10_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_10_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_10_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_10_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_10_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_10 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_10_ADDR        (REG_USBC_BASE_ADDR+0x0000C8A4)
#define USBC_DEPCMDPAR_1_10_OFFSET      0x0000C8A4
#define USBC_DEPCMDPAR_1_10_INDEX       0x00003229
#define USBC_DEPCMDPAR_1_10_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_10_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_10_ADDR);
}

__INLINE void usbc_depcmdpar_1_10_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_10_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_10_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_10_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_10_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_10_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_10_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_10_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_10_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_10_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_10 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_10_ADDR        (REG_USBC_BASE_ADDR+0x0000C8A8)
#define USBC_DEPCMDPAR_0_10_OFFSET      0x0000C8A8
#define USBC_DEPCMDPAR_0_10_INDEX       0x0000322A
#define USBC_DEPCMDPAR_0_10_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_10_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_10_ADDR);
}

__INLINE void usbc_depcmdpar_0_10_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_10_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_10_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_10_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_10_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_10_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_10_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_10_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_10_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_10_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_10 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_10_ADDR        (REG_USBC_BASE_ADDR+0x0000C8AC)
#define USBC_DEPCMD_10_OFFSET      0x0000C8AC
#define USBC_DEPCMD_10_INDEX       0x0000322B
#define USBC_DEPCMD_10_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_10_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_10_ADDR);
}

__INLINE void usbc_depcmd_10_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_10_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_10_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_10_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_10_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_10_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_10_CMDSTATUS_LSB        12
#define USBC_DEPCMD_10_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_10_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_10_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_10_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_10_CMDACT_POS           10
#define USBC_DEPCMD_10_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_10_RESERVED_9_POS       9
#define USBC_DEPCMD_10_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_10_CMDIOC_POS           8
#define USBC_DEPCMD_10_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_10_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_10_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_10_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_10_CMDTYP_LSB           0
#define USBC_DEPCMD_10_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_10_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_10_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_10_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_10_CMDACT_RST           0x0
#define USBC_DEPCMD_10_RESERVED_9_RST       0x0
#define USBC_DEPCMD_10_CMDIOC_RST           0x0
#define USBC_DEPCMD_10_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_10_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_10_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_10_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_10_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_10_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_10_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_10_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_10_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_10_ADDR, (REG_PL_RD(USBC_DEPCMD_10_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_10_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_10_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_10_ADDR, (REG_PL_RD(USBC_DEPCMD_10_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_10_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_10_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_10_ADDR, (REG_PL_RD(USBC_DEPCMD_10_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_10_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_10_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_10_ADDR, (REG_PL_RD(USBC_DEPCMD_10_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_10_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_10_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_10_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_10_ADDR, (REG_PL_RD(USBC_DEPCMD_10_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_10_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_10_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_10_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_10_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_10_ADDR, (REG_PL_RD(USBC_DEPCMD_10_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_11 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_11_ADDR        (REG_USBC_BASE_ADDR+0x0000C8B0)
#define USBC_DEPCMDPAR_2_11_OFFSET      0x0000C8B0
#define USBC_DEPCMDPAR_2_11_INDEX       0x0000322C
#define USBC_DEPCMDPAR_2_11_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_11_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_11_ADDR);
}

__INLINE void usbc_depcmdpar_2_11_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_11_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_11_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_11_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_11_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_11_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_11_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_11_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_11_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_11_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_11 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_11_ADDR        (REG_USBC_BASE_ADDR+0x0000C8B4)
#define USBC_DEPCMDPAR_1_11_OFFSET      0x0000C8B4
#define USBC_DEPCMDPAR_1_11_INDEX       0x0000322D
#define USBC_DEPCMDPAR_1_11_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_11_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_11_ADDR);
}

__INLINE void usbc_depcmdpar_1_11_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_11_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_11_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_11_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_11_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_11_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_11_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_11_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_11_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_11_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_11 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_11_ADDR        (REG_USBC_BASE_ADDR+0x0000C8B8)
#define USBC_DEPCMDPAR_0_11_OFFSET      0x0000C8B8
#define USBC_DEPCMDPAR_0_11_INDEX       0x0000322E
#define USBC_DEPCMDPAR_0_11_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_11_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_11_ADDR);
}

__INLINE void usbc_depcmdpar_0_11_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_11_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_11_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_11_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_11_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_11_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_11_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_11_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_11_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_11_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_11 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_11_ADDR        (REG_USBC_BASE_ADDR+0x0000C8BC)
#define USBC_DEPCMD_11_OFFSET      0x0000C8BC
#define USBC_DEPCMD_11_INDEX       0x0000322F
#define USBC_DEPCMD_11_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_11_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_11_ADDR);
}

__INLINE void usbc_depcmd_11_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_11_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_11_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_11_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_11_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_11_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_11_CMDSTATUS_LSB        12
#define USBC_DEPCMD_11_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_11_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_11_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_11_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_11_CMDACT_POS           10
#define USBC_DEPCMD_11_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_11_RESERVED_9_POS       9
#define USBC_DEPCMD_11_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_11_CMDIOC_POS           8
#define USBC_DEPCMD_11_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_11_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_11_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_11_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_11_CMDTYP_LSB           0
#define USBC_DEPCMD_11_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_11_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_11_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_11_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_11_CMDACT_RST           0x0
#define USBC_DEPCMD_11_RESERVED_9_RST       0x0
#define USBC_DEPCMD_11_CMDIOC_RST           0x0
#define USBC_DEPCMD_11_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_11_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_11_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_11_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_11_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_11_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_11_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_11_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_11_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_11_ADDR, (REG_PL_RD(USBC_DEPCMD_11_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_11_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_11_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_11_ADDR, (REG_PL_RD(USBC_DEPCMD_11_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_11_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_11_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_11_ADDR, (REG_PL_RD(USBC_DEPCMD_11_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_11_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_11_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_11_ADDR, (REG_PL_RD(USBC_DEPCMD_11_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_11_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_11_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_11_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_11_ADDR, (REG_PL_RD(USBC_DEPCMD_11_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_11_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_11_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_11_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_11_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_11_ADDR, (REG_PL_RD(USBC_DEPCMD_11_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_12 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_12_ADDR        (REG_USBC_BASE_ADDR+0x0000C8C0)
#define USBC_DEPCMDPAR_2_12_OFFSET      0x0000C8C0
#define USBC_DEPCMDPAR_2_12_INDEX       0x00003230
#define USBC_DEPCMDPAR_2_12_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_12_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_12_ADDR);
}

__INLINE void usbc_depcmdpar_2_12_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_12_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_12_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_12_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_12_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_12_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_12_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_12_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_12_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_12_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_12 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_12_ADDR        (REG_USBC_BASE_ADDR+0x0000C8C4)
#define USBC_DEPCMDPAR_1_12_OFFSET      0x0000C8C4
#define USBC_DEPCMDPAR_1_12_INDEX       0x00003231
#define USBC_DEPCMDPAR_1_12_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_12_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_12_ADDR);
}

__INLINE void usbc_depcmdpar_1_12_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_12_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_12_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_12_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_12_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_12_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_12_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_12_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_12_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_12_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_12 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_12_ADDR        (REG_USBC_BASE_ADDR+0x0000C8C8)
#define USBC_DEPCMDPAR_0_12_OFFSET      0x0000C8C8
#define USBC_DEPCMDPAR_0_12_INDEX       0x00003232
#define USBC_DEPCMDPAR_0_12_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_12_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_12_ADDR);
}

__INLINE void usbc_depcmdpar_0_12_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_12_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_12_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_12_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_12_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_12_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_12_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_12_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_12_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_12_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_12 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_12_ADDR        (REG_USBC_BASE_ADDR+0x0000C8CC)
#define USBC_DEPCMD_12_OFFSET      0x0000C8CC
#define USBC_DEPCMD_12_INDEX       0x00003233
#define USBC_DEPCMD_12_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_12_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_12_ADDR);
}

__INLINE void usbc_depcmd_12_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_12_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_12_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_12_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_12_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_12_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_12_CMDSTATUS_LSB        12
#define USBC_DEPCMD_12_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_12_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_12_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_12_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_12_CMDACT_POS           10
#define USBC_DEPCMD_12_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_12_RESERVED_9_POS       9
#define USBC_DEPCMD_12_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_12_CMDIOC_POS           8
#define USBC_DEPCMD_12_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_12_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_12_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_12_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_12_CMDTYP_LSB           0
#define USBC_DEPCMD_12_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_12_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_12_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_12_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_12_CMDACT_RST           0x0
#define USBC_DEPCMD_12_RESERVED_9_RST       0x0
#define USBC_DEPCMD_12_CMDIOC_RST           0x0
#define USBC_DEPCMD_12_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_12_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_12_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_12_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_12_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_12_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_12_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_12_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_12_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_12_ADDR, (REG_PL_RD(USBC_DEPCMD_12_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_12_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_12_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_12_ADDR, (REG_PL_RD(USBC_DEPCMD_12_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_12_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_12_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_12_ADDR, (REG_PL_RD(USBC_DEPCMD_12_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_12_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_12_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_12_ADDR, (REG_PL_RD(USBC_DEPCMD_12_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_12_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_12_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_12_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_12_ADDR, (REG_PL_RD(USBC_DEPCMD_12_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_12_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_12_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_12_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_12_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_12_ADDR, (REG_PL_RD(USBC_DEPCMD_12_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_13 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_13_ADDR        (REG_USBC_BASE_ADDR+0x0000C8D0)
#define USBC_DEPCMDPAR_2_13_OFFSET      0x0000C8D0
#define USBC_DEPCMDPAR_2_13_INDEX       0x00003234
#define USBC_DEPCMDPAR_2_13_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_13_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_13_ADDR);
}

__INLINE void usbc_depcmdpar_2_13_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_13_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_13_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_13_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_13_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_13_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_13_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_13_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_13_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_13_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_13 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_13_ADDR        (REG_USBC_BASE_ADDR+0x0000C8D4)
#define USBC_DEPCMDPAR_1_13_OFFSET      0x0000C8D4
#define USBC_DEPCMDPAR_1_13_INDEX       0x00003235
#define USBC_DEPCMDPAR_1_13_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_13_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_13_ADDR);
}

__INLINE void usbc_depcmdpar_1_13_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_13_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_13_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_13_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_13_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_13_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_13_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_13_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_13_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_13_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_13 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_13_ADDR        (REG_USBC_BASE_ADDR+0x0000C8D8)
#define USBC_DEPCMDPAR_0_13_OFFSET      0x0000C8D8
#define USBC_DEPCMDPAR_0_13_INDEX       0x00003236
#define USBC_DEPCMDPAR_0_13_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_13_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_13_ADDR);
}

__INLINE void usbc_depcmdpar_0_13_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_13_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_13_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_13_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_13_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_13_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_13_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_13_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_13_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_13_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_13 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_13_ADDR        (REG_USBC_BASE_ADDR+0x0000C8DC)
#define USBC_DEPCMD_13_OFFSET      0x0000C8DC
#define USBC_DEPCMD_13_INDEX       0x00003237
#define USBC_DEPCMD_13_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_13_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_13_ADDR);
}

__INLINE void usbc_depcmd_13_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_13_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_13_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_13_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_13_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_13_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_13_CMDSTATUS_LSB        12
#define USBC_DEPCMD_13_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_13_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_13_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_13_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_13_CMDACT_POS           10
#define USBC_DEPCMD_13_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_13_RESERVED_9_POS       9
#define USBC_DEPCMD_13_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_13_CMDIOC_POS           8
#define USBC_DEPCMD_13_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_13_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_13_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_13_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_13_CMDTYP_LSB           0
#define USBC_DEPCMD_13_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_13_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_13_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_13_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_13_CMDACT_RST           0x0
#define USBC_DEPCMD_13_RESERVED_9_RST       0x0
#define USBC_DEPCMD_13_CMDIOC_RST           0x0
#define USBC_DEPCMD_13_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_13_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_13_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_13_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_13_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_13_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_13_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_13_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_13_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_13_ADDR, (REG_PL_RD(USBC_DEPCMD_13_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_13_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_13_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_13_ADDR, (REG_PL_RD(USBC_DEPCMD_13_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_13_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_13_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_13_ADDR, (REG_PL_RD(USBC_DEPCMD_13_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_13_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_13_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_13_ADDR, (REG_PL_RD(USBC_DEPCMD_13_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_13_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_13_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_13_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_13_ADDR, (REG_PL_RD(USBC_DEPCMD_13_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_13_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_13_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_13_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_13_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_13_ADDR, (REG_PL_RD(USBC_DEPCMD_13_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_14 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_14_ADDR        (REG_USBC_BASE_ADDR+0x0000C8E0)
#define USBC_DEPCMDPAR_2_14_OFFSET      0x0000C8E0
#define USBC_DEPCMDPAR_2_14_INDEX       0x00003238
#define USBC_DEPCMDPAR_2_14_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_14_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_14_ADDR);
}

__INLINE void usbc_depcmdpar_2_14_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_14_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_14_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_14_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_14_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_14_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_14_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_14_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_14_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_14_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_14 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_14_ADDR        (REG_USBC_BASE_ADDR+0x0000C8E4)
#define USBC_DEPCMDPAR_1_14_OFFSET      0x0000C8E4
#define USBC_DEPCMDPAR_1_14_INDEX       0x00003239
#define USBC_DEPCMDPAR_1_14_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_14_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_14_ADDR);
}

__INLINE void usbc_depcmdpar_1_14_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_14_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_14_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_14_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_14_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_14_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_14_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_14_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_14_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_14_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_14 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_14_ADDR        (REG_USBC_BASE_ADDR+0x0000C8E8)
#define USBC_DEPCMDPAR_0_14_OFFSET      0x0000C8E8
#define USBC_DEPCMDPAR_0_14_INDEX       0x0000323A
#define USBC_DEPCMDPAR_0_14_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_14_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_14_ADDR);
}

__INLINE void usbc_depcmdpar_0_14_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_14_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_14_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_14_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_14_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_14_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_14_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_14_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_14_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_14_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_14 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_14_ADDR        (REG_USBC_BASE_ADDR+0x0000C8EC)
#define USBC_DEPCMD_14_OFFSET      0x0000C8EC
#define USBC_DEPCMD_14_INDEX       0x0000323B
#define USBC_DEPCMD_14_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_14_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_14_ADDR);
}

__INLINE void usbc_depcmd_14_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_14_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_14_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_14_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_14_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_14_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_14_CMDSTATUS_LSB        12
#define USBC_DEPCMD_14_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_14_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_14_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_14_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_14_CMDACT_POS           10
#define USBC_DEPCMD_14_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_14_RESERVED_9_POS       9
#define USBC_DEPCMD_14_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_14_CMDIOC_POS           8
#define USBC_DEPCMD_14_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_14_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_14_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_14_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_14_CMDTYP_LSB           0
#define USBC_DEPCMD_14_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_14_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_14_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_14_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_14_CMDACT_RST           0x0
#define USBC_DEPCMD_14_RESERVED_9_RST       0x0
#define USBC_DEPCMD_14_CMDIOC_RST           0x0
#define USBC_DEPCMD_14_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_14_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_14_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_14_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_14_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_14_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_14_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_14_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_14_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_14_ADDR, (REG_PL_RD(USBC_DEPCMD_14_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_14_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_14_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_14_ADDR, (REG_PL_RD(USBC_DEPCMD_14_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_14_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_14_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_14_ADDR, (REG_PL_RD(USBC_DEPCMD_14_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_14_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_14_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_14_ADDR, (REG_PL_RD(USBC_DEPCMD_14_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_14_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_14_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_14_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_14_ADDR, (REG_PL_RD(USBC_DEPCMD_14_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_14_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_14_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_14_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_14_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_14_ADDR, (REG_PL_RD(USBC_DEPCMD_14_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_15 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_15_ADDR        (REG_USBC_BASE_ADDR+0x0000C8F0)
#define USBC_DEPCMDPAR_2_15_OFFSET      0x0000C8F0
#define USBC_DEPCMDPAR_2_15_INDEX       0x0000323C
#define USBC_DEPCMDPAR_2_15_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_15_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_15_ADDR);
}

__INLINE void usbc_depcmdpar_2_15_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_15_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_15_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_15_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_15_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_15_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_15_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_15_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_15_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_15_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_15 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_15_ADDR        (REG_USBC_BASE_ADDR+0x0000C8F4)
#define USBC_DEPCMDPAR_1_15_OFFSET      0x0000C8F4
#define USBC_DEPCMDPAR_1_15_INDEX       0x0000323D
#define USBC_DEPCMDPAR_1_15_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_15_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_15_ADDR);
}

__INLINE void usbc_depcmdpar_1_15_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_15_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_15_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_15_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_15_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_15_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_15_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_15_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_15_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_15_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_15 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_15_ADDR        (REG_USBC_BASE_ADDR+0x0000C8F8)
#define USBC_DEPCMDPAR_0_15_OFFSET      0x0000C8F8
#define USBC_DEPCMDPAR_0_15_INDEX       0x0000323E
#define USBC_DEPCMDPAR_0_15_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_15_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_15_ADDR);
}

__INLINE void usbc_depcmdpar_0_15_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_15_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_15_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_15_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_15_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_15_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_15_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_15_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_15_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_15_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_15 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_15_ADDR        (REG_USBC_BASE_ADDR+0x0000C8FC)
#define USBC_DEPCMD_15_OFFSET      0x0000C8FC
#define USBC_DEPCMD_15_INDEX       0x0000323F
#define USBC_DEPCMD_15_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_15_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_15_ADDR);
}

__INLINE void usbc_depcmd_15_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_15_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_15_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_15_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_15_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_15_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_15_CMDSTATUS_LSB        12
#define USBC_DEPCMD_15_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_15_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_15_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_15_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_15_CMDACT_POS           10
#define USBC_DEPCMD_15_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_15_RESERVED_9_POS       9
#define USBC_DEPCMD_15_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_15_CMDIOC_POS           8
#define USBC_DEPCMD_15_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_15_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_15_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_15_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_15_CMDTYP_LSB           0
#define USBC_DEPCMD_15_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_15_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_15_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_15_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_15_CMDACT_RST           0x0
#define USBC_DEPCMD_15_RESERVED_9_RST       0x0
#define USBC_DEPCMD_15_CMDIOC_RST           0x0
#define USBC_DEPCMD_15_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_15_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_15_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_15_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_15_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_15_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_15_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_15_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_15_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_15_ADDR, (REG_PL_RD(USBC_DEPCMD_15_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_15_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_15_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_15_ADDR, (REG_PL_RD(USBC_DEPCMD_15_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_15_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_15_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_15_ADDR, (REG_PL_RD(USBC_DEPCMD_15_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_15_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_15_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_15_ADDR, (REG_PL_RD(USBC_DEPCMD_15_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_15_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_15_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_15_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_15_ADDR, (REG_PL_RD(USBC_DEPCMD_15_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_15_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_15_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_15_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_15_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_15_ADDR, (REG_PL_RD(USBC_DEPCMD_15_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_16 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_16_ADDR        (REG_USBC_BASE_ADDR+0x0000C900)
#define USBC_DEPCMDPAR_2_16_OFFSET      0x0000C900
#define USBC_DEPCMDPAR_2_16_INDEX       0x00003240
#define USBC_DEPCMDPAR_2_16_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_16_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_16_ADDR);
}

__INLINE void usbc_depcmdpar_2_16_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_16_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_16_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_16_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_16_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_16_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_16_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_16_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_16_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_16_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_16 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_16_ADDR        (REG_USBC_BASE_ADDR+0x0000C904)
#define USBC_DEPCMDPAR_1_16_OFFSET      0x0000C904
#define USBC_DEPCMDPAR_1_16_INDEX       0x00003241
#define USBC_DEPCMDPAR_1_16_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_16_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_16_ADDR);
}

__INLINE void usbc_depcmdpar_1_16_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_16_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_16_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_16_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_16_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_16_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_16_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_16_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_16_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_16_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_16 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_16_ADDR        (REG_USBC_BASE_ADDR+0x0000C908)
#define USBC_DEPCMDPAR_0_16_OFFSET      0x0000C908
#define USBC_DEPCMDPAR_0_16_INDEX       0x00003242
#define USBC_DEPCMDPAR_0_16_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_16_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_16_ADDR);
}

__INLINE void usbc_depcmdpar_0_16_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_16_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_16_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_16_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_16_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_16_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_16_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_16_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_16_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_16_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_16 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_16_ADDR        (REG_USBC_BASE_ADDR+0x0000C90C)
#define USBC_DEPCMD_16_OFFSET      0x0000C90C
#define USBC_DEPCMD_16_INDEX       0x00003243
#define USBC_DEPCMD_16_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_16_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_16_ADDR);
}

__INLINE void usbc_depcmd_16_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_16_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_16_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_16_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_16_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_16_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_16_CMDSTATUS_LSB        12
#define USBC_DEPCMD_16_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_16_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_16_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_16_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_16_CMDACT_POS           10
#define USBC_DEPCMD_16_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_16_RESERVED_9_POS       9
#define USBC_DEPCMD_16_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_16_CMDIOC_POS           8
#define USBC_DEPCMD_16_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_16_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_16_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_16_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_16_CMDTYP_LSB           0
#define USBC_DEPCMD_16_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_16_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_16_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_16_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_16_CMDACT_RST           0x0
#define USBC_DEPCMD_16_RESERVED_9_RST       0x0
#define USBC_DEPCMD_16_CMDIOC_RST           0x0
#define USBC_DEPCMD_16_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_16_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_16_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_16_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_16_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_16_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_16_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_16_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_16_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_16_ADDR, (REG_PL_RD(USBC_DEPCMD_16_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_16_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_16_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_16_ADDR, (REG_PL_RD(USBC_DEPCMD_16_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_16_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_16_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_16_ADDR, (REG_PL_RD(USBC_DEPCMD_16_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_16_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_16_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_16_ADDR, (REG_PL_RD(USBC_DEPCMD_16_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_16_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_16_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_16_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_16_ADDR, (REG_PL_RD(USBC_DEPCMD_16_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_16_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_16_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_16_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_16_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_16_ADDR, (REG_PL_RD(USBC_DEPCMD_16_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_17 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_17_ADDR        (REG_USBC_BASE_ADDR+0x0000C910)
#define USBC_DEPCMDPAR_2_17_OFFSET      0x0000C910
#define USBC_DEPCMDPAR_2_17_INDEX       0x00003244
#define USBC_DEPCMDPAR_2_17_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_17_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_17_ADDR);
}

__INLINE void usbc_depcmdpar_2_17_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_17_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_17_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_17_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_17_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_17_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_17_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_17_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_17_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_17_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_17 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_17_ADDR        (REG_USBC_BASE_ADDR+0x0000C914)
#define USBC_DEPCMDPAR_1_17_OFFSET      0x0000C914
#define USBC_DEPCMDPAR_1_17_INDEX       0x00003245
#define USBC_DEPCMDPAR_1_17_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_17_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_17_ADDR);
}

__INLINE void usbc_depcmdpar_1_17_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_17_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_17_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_17_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_17_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_17_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_17_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_17_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_17_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_17_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_17 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_17_ADDR        (REG_USBC_BASE_ADDR+0x0000C918)
#define USBC_DEPCMDPAR_0_17_OFFSET      0x0000C918
#define USBC_DEPCMDPAR_0_17_INDEX       0x00003246
#define USBC_DEPCMDPAR_0_17_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_17_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_17_ADDR);
}

__INLINE void usbc_depcmdpar_0_17_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_17_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_17_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_17_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_17_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_17_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_17_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_17_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_17_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_17_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_17 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_17_ADDR        (REG_USBC_BASE_ADDR+0x0000C91C)
#define USBC_DEPCMD_17_OFFSET      0x0000C91C
#define USBC_DEPCMD_17_INDEX       0x00003247
#define USBC_DEPCMD_17_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_17_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_17_ADDR);
}

__INLINE void usbc_depcmd_17_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_17_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_17_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_17_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_17_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_17_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_17_CMDSTATUS_LSB        12
#define USBC_DEPCMD_17_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_17_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_17_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_17_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_17_CMDACT_POS           10
#define USBC_DEPCMD_17_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_17_RESERVED_9_POS       9
#define USBC_DEPCMD_17_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_17_CMDIOC_POS           8
#define USBC_DEPCMD_17_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_17_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_17_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_17_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_17_CMDTYP_LSB           0
#define USBC_DEPCMD_17_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_17_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_17_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_17_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_17_CMDACT_RST           0x0
#define USBC_DEPCMD_17_RESERVED_9_RST       0x0
#define USBC_DEPCMD_17_CMDIOC_RST           0x0
#define USBC_DEPCMD_17_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_17_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_17_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_17_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_17_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_17_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_17_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_17_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_17_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_17_ADDR, (REG_PL_RD(USBC_DEPCMD_17_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_17_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_17_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_17_ADDR, (REG_PL_RD(USBC_DEPCMD_17_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_17_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_17_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_17_ADDR, (REG_PL_RD(USBC_DEPCMD_17_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_17_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_17_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_17_ADDR, (REG_PL_RD(USBC_DEPCMD_17_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_17_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_17_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_17_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_17_ADDR, (REG_PL_RD(USBC_DEPCMD_17_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_17_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_17_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_17_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_17_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_17_ADDR, (REG_PL_RD(USBC_DEPCMD_17_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_18 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_18_ADDR        (REG_USBC_BASE_ADDR+0x0000C920)
#define USBC_DEPCMDPAR_2_18_OFFSET      0x0000C920
#define USBC_DEPCMDPAR_2_18_INDEX       0x00003248
#define USBC_DEPCMDPAR_2_18_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_18_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_18_ADDR);
}

__INLINE void usbc_depcmdpar_2_18_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_18_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_18_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_18_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_18_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_18_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_18_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_18_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_18_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_18_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_18 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_18_ADDR        (REG_USBC_BASE_ADDR+0x0000C924)
#define USBC_DEPCMDPAR_1_18_OFFSET      0x0000C924
#define USBC_DEPCMDPAR_1_18_INDEX       0x00003249
#define USBC_DEPCMDPAR_1_18_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_18_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_18_ADDR);
}

__INLINE void usbc_depcmdpar_1_18_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_18_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_18_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_18_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_18_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_18_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_18_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_18_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_18_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_18_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_18 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_18_ADDR        (REG_USBC_BASE_ADDR+0x0000C928)
#define USBC_DEPCMDPAR_0_18_OFFSET      0x0000C928
#define USBC_DEPCMDPAR_0_18_INDEX       0x0000324A
#define USBC_DEPCMDPAR_0_18_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_18_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_18_ADDR);
}

__INLINE void usbc_depcmdpar_0_18_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_18_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_18_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_18_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_18_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_18_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_18_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_18_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_18_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_18_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_18 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_18_ADDR        (REG_USBC_BASE_ADDR+0x0000C92C)
#define USBC_DEPCMD_18_OFFSET      0x0000C92C
#define USBC_DEPCMD_18_INDEX       0x0000324B
#define USBC_DEPCMD_18_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_18_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_18_ADDR);
}

__INLINE void usbc_depcmd_18_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_18_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_18_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_18_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_18_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_18_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_18_CMDSTATUS_LSB        12
#define USBC_DEPCMD_18_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_18_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_18_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_18_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_18_CMDACT_POS           10
#define USBC_DEPCMD_18_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_18_RESERVED_9_POS       9
#define USBC_DEPCMD_18_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_18_CMDIOC_POS           8
#define USBC_DEPCMD_18_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_18_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_18_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_18_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_18_CMDTYP_LSB           0
#define USBC_DEPCMD_18_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_18_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_18_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_18_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_18_CMDACT_RST           0x0
#define USBC_DEPCMD_18_RESERVED_9_RST       0x0
#define USBC_DEPCMD_18_CMDIOC_RST           0x0
#define USBC_DEPCMD_18_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_18_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_18_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_18_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_18_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_18_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_18_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_18_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_18_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_18_ADDR, (REG_PL_RD(USBC_DEPCMD_18_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_18_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_18_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_18_ADDR, (REG_PL_RD(USBC_DEPCMD_18_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_18_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_18_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_18_ADDR, (REG_PL_RD(USBC_DEPCMD_18_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_18_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_18_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_18_ADDR, (REG_PL_RD(USBC_DEPCMD_18_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_18_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_18_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_18_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_18_ADDR, (REG_PL_RD(USBC_DEPCMD_18_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_18_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_18_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_18_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_18_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_18_ADDR, (REG_PL_RD(USBC_DEPCMD_18_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_19 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_19_ADDR        (REG_USBC_BASE_ADDR+0x0000C930)
#define USBC_DEPCMDPAR_2_19_OFFSET      0x0000C930
#define USBC_DEPCMDPAR_2_19_INDEX       0x0000324C
#define USBC_DEPCMDPAR_2_19_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_19_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_19_ADDR);
}

__INLINE void usbc_depcmdpar_2_19_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_19_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_19_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_19_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_19_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_19_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_19_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_19_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_19_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_19_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_19 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_19_ADDR        (REG_USBC_BASE_ADDR+0x0000C934)
#define USBC_DEPCMDPAR_1_19_OFFSET      0x0000C934
#define USBC_DEPCMDPAR_1_19_INDEX       0x0000324D
#define USBC_DEPCMDPAR_1_19_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_19_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_19_ADDR);
}

__INLINE void usbc_depcmdpar_1_19_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_19_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_19_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_19_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_19_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_19_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_19_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_19_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_19_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_19_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_19 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_19_ADDR        (REG_USBC_BASE_ADDR+0x0000C938)
#define USBC_DEPCMDPAR_0_19_OFFSET      0x0000C938
#define USBC_DEPCMDPAR_0_19_INDEX       0x0000324E
#define USBC_DEPCMDPAR_0_19_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_19_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_19_ADDR);
}

__INLINE void usbc_depcmdpar_0_19_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_19_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_19_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_19_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_19_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_19_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_19_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_19_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_19_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_19_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_19 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_19_ADDR        (REG_USBC_BASE_ADDR+0x0000C93C)
#define USBC_DEPCMD_19_OFFSET      0x0000C93C
#define USBC_DEPCMD_19_INDEX       0x0000324F
#define USBC_DEPCMD_19_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_19_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_19_ADDR);
}

__INLINE void usbc_depcmd_19_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_19_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_19_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_19_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_19_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_19_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_19_CMDSTATUS_LSB        12
#define USBC_DEPCMD_19_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_19_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_19_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_19_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_19_CMDACT_POS           10
#define USBC_DEPCMD_19_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_19_RESERVED_9_POS       9
#define USBC_DEPCMD_19_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_19_CMDIOC_POS           8
#define USBC_DEPCMD_19_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_19_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_19_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_19_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_19_CMDTYP_LSB           0
#define USBC_DEPCMD_19_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_19_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_19_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_19_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_19_CMDACT_RST           0x0
#define USBC_DEPCMD_19_RESERVED_9_RST       0x0
#define USBC_DEPCMD_19_CMDIOC_RST           0x0
#define USBC_DEPCMD_19_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_19_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_19_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_19_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_19_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_19_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_19_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_19_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_19_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_19_ADDR, (REG_PL_RD(USBC_DEPCMD_19_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_19_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_19_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_19_ADDR, (REG_PL_RD(USBC_DEPCMD_19_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_19_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_19_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_19_ADDR, (REG_PL_RD(USBC_DEPCMD_19_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_19_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_19_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_19_ADDR, (REG_PL_RD(USBC_DEPCMD_19_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_19_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_19_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_19_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_19_ADDR, (REG_PL_RD(USBC_DEPCMD_19_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_19_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_19_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_19_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_19_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_19_ADDR, (REG_PL_RD(USBC_DEPCMD_19_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_20 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_20_ADDR        (REG_USBC_BASE_ADDR+0x0000C940)
#define USBC_DEPCMDPAR_2_20_OFFSET      0x0000C940
#define USBC_DEPCMDPAR_2_20_INDEX       0x00003250
#define USBC_DEPCMDPAR_2_20_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_20_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_20_ADDR);
}

__INLINE void usbc_depcmdpar_2_20_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_20_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_20_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_20_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_20_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_20_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_20_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_20_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_20_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_20_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_20 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_20_ADDR        (REG_USBC_BASE_ADDR+0x0000C944)
#define USBC_DEPCMDPAR_1_20_OFFSET      0x0000C944
#define USBC_DEPCMDPAR_1_20_INDEX       0x00003251
#define USBC_DEPCMDPAR_1_20_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_20_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_20_ADDR);
}

__INLINE void usbc_depcmdpar_1_20_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_20_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_20_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_20_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_20_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_20_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_20_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_20_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_20_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_20_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_20 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_20_ADDR        (REG_USBC_BASE_ADDR+0x0000C948)
#define USBC_DEPCMDPAR_0_20_OFFSET      0x0000C948
#define USBC_DEPCMDPAR_0_20_INDEX       0x00003252
#define USBC_DEPCMDPAR_0_20_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_20_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_20_ADDR);
}

__INLINE void usbc_depcmdpar_0_20_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_20_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_20_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_20_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_20_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_20_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_20_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_20_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_20_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_20_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_20 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_20_ADDR        (REG_USBC_BASE_ADDR+0x0000C94C)
#define USBC_DEPCMD_20_OFFSET      0x0000C94C
#define USBC_DEPCMD_20_INDEX       0x00003253
#define USBC_DEPCMD_20_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_20_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_20_ADDR);
}

__INLINE void usbc_depcmd_20_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_20_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_20_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_20_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_20_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_20_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_20_CMDSTATUS_LSB        12
#define USBC_DEPCMD_20_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_20_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_20_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_20_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_20_CMDACT_POS           10
#define USBC_DEPCMD_20_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_20_RESERVED_9_POS       9
#define USBC_DEPCMD_20_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_20_CMDIOC_POS           8
#define USBC_DEPCMD_20_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_20_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_20_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_20_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_20_CMDTYP_LSB           0
#define USBC_DEPCMD_20_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_20_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_20_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_20_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_20_CMDACT_RST           0x0
#define USBC_DEPCMD_20_RESERVED_9_RST       0x0
#define USBC_DEPCMD_20_CMDIOC_RST           0x0
#define USBC_DEPCMD_20_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_20_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_20_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_20_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_20_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_20_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_20_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_20_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_20_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_20_ADDR, (REG_PL_RD(USBC_DEPCMD_20_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_20_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_20_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_20_ADDR, (REG_PL_RD(USBC_DEPCMD_20_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_20_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_20_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_20_ADDR, (REG_PL_RD(USBC_DEPCMD_20_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_20_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_20_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_20_ADDR, (REG_PL_RD(USBC_DEPCMD_20_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_20_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_20_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_20_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_20_ADDR, (REG_PL_RD(USBC_DEPCMD_20_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_20_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_20_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_20_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_20_ADDR, (REG_PL_RD(USBC_DEPCMD_20_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_21 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_21_ADDR        (REG_USBC_BASE_ADDR+0x0000C950)
#define USBC_DEPCMDPAR_2_21_OFFSET      0x0000C950
#define USBC_DEPCMDPAR_2_21_INDEX       0x00003254
#define USBC_DEPCMDPAR_2_21_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_21_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_21_ADDR);
}

__INLINE void usbc_depcmdpar_2_21_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_21_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_21_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_21_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_21_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_21_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_21_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_21_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_21_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_21_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_21 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_21_ADDR        (REG_USBC_BASE_ADDR+0x0000C954)
#define USBC_DEPCMDPAR_1_21_OFFSET      0x0000C954
#define USBC_DEPCMDPAR_1_21_INDEX       0x00003255
#define USBC_DEPCMDPAR_1_21_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_21_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_21_ADDR);
}

__INLINE void usbc_depcmdpar_1_21_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_21_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_21_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_21_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_21_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_21_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_21_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_21_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_21_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_21_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_21 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_21_ADDR        (REG_USBC_BASE_ADDR+0x0000C958)
#define USBC_DEPCMDPAR_0_21_OFFSET      0x0000C958
#define USBC_DEPCMDPAR_0_21_INDEX       0x00003256
#define USBC_DEPCMDPAR_0_21_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_21_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_21_ADDR);
}

__INLINE void usbc_depcmdpar_0_21_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_21_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_21_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_21_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_21_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_21_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_21_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_21_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_21_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_21_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_21 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_21_ADDR        (REG_USBC_BASE_ADDR+0x0000C95C)
#define USBC_DEPCMD_21_OFFSET      0x0000C95C
#define USBC_DEPCMD_21_INDEX       0x00003257
#define USBC_DEPCMD_21_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_21_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_21_ADDR);
}

__INLINE void usbc_depcmd_21_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_21_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_21_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_21_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_21_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_21_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_21_CMDSTATUS_LSB        12
#define USBC_DEPCMD_21_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_21_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_21_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_21_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_21_CMDACT_POS           10
#define USBC_DEPCMD_21_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_21_RESERVED_9_POS       9
#define USBC_DEPCMD_21_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_21_CMDIOC_POS           8
#define USBC_DEPCMD_21_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_21_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_21_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_21_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_21_CMDTYP_LSB           0
#define USBC_DEPCMD_21_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_21_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_21_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_21_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_21_CMDACT_RST           0x0
#define USBC_DEPCMD_21_RESERVED_9_RST       0x0
#define USBC_DEPCMD_21_CMDIOC_RST           0x0
#define USBC_DEPCMD_21_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_21_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_21_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_21_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_21_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_21_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_21_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_21_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_21_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_21_ADDR, (REG_PL_RD(USBC_DEPCMD_21_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_21_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_21_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_21_ADDR, (REG_PL_RD(USBC_DEPCMD_21_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_21_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_21_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_21_ADDR, (REG_PL_RD(USBC_DEPCMD_21_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_21_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_21_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_21_ADDR, (REG_PL_RD(USBC_DEPCMD_21_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_21_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_21_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_21_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_21_ADDR, (REG_PL_RD(USBC_DEPCMD_21_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_21_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_21_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_21_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_21_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_21_ADDR, (REG_PL_RD(USBC_DEPCMD_21_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_22 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_22_ADDR        (REG_USBC_BASE_ADDR+0x0000C960)
#define USBC_DEPCMDPAR_2_22_OFFSET      0x0000C960
#define USBC_DEPCMDPAR_2_22_INDEX       0x00003258
#define USBC_DEPCMDPAR_2_22_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_22_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_22_ADDR);
}

__INLINE void usbc_depcmdpar_2_22_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_22_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_22_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_22_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_22_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_22_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_22_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_22_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_22_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_22_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_22 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_22_ADDR        (REG_USBC_BASE_ADDR+0x0000C964)
#define USBC_DEPCMDPAR_1_22_OFFSET      0x0000C964
#define USBC_DEPCMDPAR_1_22_INDEX       0x00003259
#define USBC_DEPCMDPAR_1_22_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_22_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_22_ADDR);
}

__INLINE void usbc_depcmdpar_1_22_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_22_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_22_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_22_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_22_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_22_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_22_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_22_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_22_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_22_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_22 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_22_ADDR        (REG_USBC_BASE_ADDR+0x0000C968)
#define USBC_DEPCMDPAR_0_22_OFFSET      0x0000C968
#define USBC_DEPCMDPAR_0_22_INDEX       0x0000325A
#define USBC_DEPCMDPAR_0_22_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_22_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_22_ADDR);
}

__INLINE void usbc_depcmdpar_0_22_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_22_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_22_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_22_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_22_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_22_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_22_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_22_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_22_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_22_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_22 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_22_ADDR        (REG_USBC_BASE_ADDR+0x0000C96C)
#define USBC_DEPCMD_22_OFFSET      0x0000C96C
#define USBC_DEPCMD_22_INDEX       0x0000325B
#define USBC_DEPCMD_22_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_22_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_22_ADDR);
}

__INLINE void usbc_depcmd_22_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_22_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_22_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_22_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_22_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_22_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_22_CMDSTATUS_LSB        12
#define USBC_DEPCMD_22_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_22_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_22_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_22_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_22_CMDACT_POS           10
#define USBC_DEPCMD_22_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_22_RESERVED_9_POS       9
#define USBC_DEPCMD_22_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_22_CMDIOC_POS           8
#define USBC_DEPCMD_22_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_22_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_22_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_22_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_22_CMDTYP_LSB           0
#define USBC_DEPCMD_22_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_22_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_22_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_22_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_22_CMDACT_RST           0x0
#define USBC_DEPCMD_22_RESERVED_9_RST       0x0
#define USBC_DEPCMD_22_CMDIOC_RST           0x0
#define USBC_DEPCMD_22_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_22_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_22_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_22_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_22_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_22_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_22_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_22_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_22_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_22_ADDR, (REG_PL_RD(USBC_DEPCMD_22_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_22_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_22_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_22_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_22_ADDR, (REG_PL_RD(USBC_DEPCMD_22_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_22_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_22_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_22_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_22_ADDR, (REG_PL_RD(USBC_DEPCMD_22_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_22_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_22_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_22_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_22_ADDR, (REG_PL_RD(USBC_DEPCMD_22_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_22_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_22_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_22_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_22_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_22_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_22_ADDR, (REG_PL_RD(USBC_DEPCMD_22_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_22_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_22_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_22_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_22_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_22_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_22_ADDR, (REG_PL_RD(USBC_DEPCMD_22_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_23 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_23_ADDR        (REG_USBC_BASE_ADDR+0x0000C970)
#define USBC_DEPCMDPAR_2_23_OFFSET      0x0000C970
#define USBC_DEPCMDPAR_2_23_INDEX       0x0000325C
#define USBC_DEPCMDPAR_2_23_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_23_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_23_ADDR);
}

__INLINE void usbc_depcmdpar_2_23_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_23_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_23_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_23_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_23_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_23_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_23_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_23_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_23_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_23_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_23 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_23_ADDR        (REG_USBC_BASE_ADDR+0x0000C974)
#define USBC_DEPCMDPAR_1_23_OFFSET      0x0000C974
#define USBC_DEPCMDPAR_1_23_INDEX       0x0000325D
#define USBC_DEPCMDPAR_1_23_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_23_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_23_ADDR);
}

__INLINE void usbc_depcmdpar_1_23_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_23_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_23_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_23_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_23_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_23_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_23_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_23_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_23_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_23_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_23 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_23_ADDR        (REG_USBC_BASE_ADDR+0x0000C978)
#define USBC_DEPCMDPAR_0_23_OFFSET      0x0000C978
#define USBC_DEPCMDPAR_0_23_INDEX       0x0000325E
#define USBC_DEPCMDPAR_0_23_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_23_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_23_ADDR);
}

__INLINE void usbc_depcmdpar_0_23_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_23_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_23_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_23_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_23_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_23_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_23_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_23_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_23_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_23_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_23 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_23_ADDR        (REG_USBC_BASE_ADDR+0x0000C97C)
#define USBC_DEPCMD_23_OFFSET      0x0000C97C
#define USBC_DEPCMD_23_INDEX       0x0000325F
#define USBC_DEPCMD_23_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_23_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_23_ADDR);
}

__INLINE void usbc_depcmd_23_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_23_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_23_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_23_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_23_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_23_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_23_CMDSTATUS_LSB        12
#define USBC_DEPCMD_23_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_23_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_23_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_23_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_23_CMDACT_POS           10
#define USBC_DEPCMD_23_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_23_RESERVED_9_POS       9
#define USBC_DEPCMD_23_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_23_CMDIOC_POS           8
#define USBC_DEPCMD_23_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_23_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_23_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_23_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_23_CMDTYP_LSB           0
#define USBC_DEPCMD_23_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_23_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_23_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_23_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_23_CMDACT_RST           0x0
#define USBC_DEPCMD_23_RESERVED_9_RST       0x0
#define USBC_DEPCMD_23_CMDIOC_RST           0x0
#define USBC_DEPCMD_23_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_23_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_23_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_23_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_23_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_23_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_23_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_23_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_23_ADDR, (REG_PL_RD(USBC_DEPCMD_23_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_23_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_23_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_23_ADDR, (REG_PL_RD(USBC_DEPCMD_23_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_23_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_23_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_23_ADDR, (REG_PL_RD(USBC_DEPCMD_23_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_23_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_23_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_23_ADDR, (REG_PL_RD(USBC_DEPCMD_23_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_23_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_23_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_23_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_23_ADDR, (REG_PL_RD(USBC_DEPCMD_23_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_23_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_23_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_23_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_23_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_23_ADDR, (REG_PL_RD(USBC_DEPCMD_23_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_24 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_24_ADDR        (REG_USBC_BASE_ADDR+0x0000C980)
#define USBC_DEPCMDPAR_2_24_OFFSET      0x0000C980
#define USBC_DEPCMDPAR_2_24_INDEX       0x00003260
#define USBC_DEPCMDPAR_2_24_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_24_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_24_ADDR);
}

__INLINE void usbc_depcmdpar_2_24_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_24_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_24_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_24_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_24_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_24_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_24_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_24_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_24_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_24_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_24 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_24_ADDR        (REG_USBC_BASE_ADDR+0x0000C984)
#define USBC_DEPCMDPAR_1_24_OFFSET      0x0000C984
#define USBC_DEPCMDPAR_1_24_INDEX       0x00003261
#define USBC_DEPCMDPAR_1_24_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_24_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_24_ADDR);
}

__INLINE void usbc_depcmdpar_1_24_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_24_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_24_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_24_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_24_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_24_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_24_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_24_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_24_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_24_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_24 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_24_ADDR        (REG_USBC_BASE_ADDR+0x0000C988)
#define USBC_DEPCMDPAR_0_24_OFFSET      0x0000C988
#define USBC_DEPCMDPAR_0_24_INDEX       0x00003262
#define USBC_DEPCMDPAR_0_24_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_24_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_24_ADDR);
}

__INLINE void usbc_depcmdpar_0_24_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_24_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_24_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_24_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_24_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_24_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_24_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_24_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_24_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_24_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_24 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_24_ADDR        (REG_USBC_BASE_ADDR+0x0000C98C)
#define USBC_DEPCMD_24_OFFSET      0x0000C98C
#define USBC_DEPCMD_24_INDEX       0x00003263
#define USBC_DEPCMD_24_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_24_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_24_ADDR);
}

__INLINE void usbc_depcmd_24_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_24_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_24_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_24_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_24_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_24_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_24_CMDSTATUS_LSB        12
#define USBC_DEPCMD_24_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_24_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_24_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_24_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_24_CMDACT_POS           10
#define USBC_DEPCMD_24_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_24_RESERVED_9_POS       9
#define USBC_DEPCMD_24_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_24_CMDIOC_POS           8
#define USBC_DEPCMD_24_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_24_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_24_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_24_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_24_CMDTYP_LSB           0
#define USBC_DEPCMD_24_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_24_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_24_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_24_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_24_CMDACT_RST           0x0
#define USBC_DEPCMD_24_RESERVED_9_RST       0x0
#define USBC_DEPCMD_24_CMDIOC_RST           0x0
#define USBC_DEPCMD_24_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_24_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_24_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_24_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_24_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_24_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_24_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_24_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_24_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_24_ADDR, (REG_PL_RD(USBC_DEPCMD_24_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_24_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_24_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_24_ADDR, (REG_PL_RD(USBC_DEPCMD_24_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_24_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_24_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_24_ADDR, (REG_PL_RD(USBC_DEPCMD_24_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_24_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_24_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_24_ADDR, (REG_PL_RD(USBC_DEPCMD_24_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_24_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_24_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_24_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_24_ADDR, (REG_PL_RD(USBC_DEPCMD_24_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_24_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_24_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_24_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_24_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_24_ADDR, (REG_PL_RD(USBC_DEPCMD_24_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_25 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_25_ADDR        (REG_USBC_BASE_ADDR+0x0000C990)
#define USBC_DEPCMDPAR_2_25_OFFSET      0x0000C990
#define USBC_DEPCMDPAR_2_25_INDEX       0x00003264
#define USBC_DEPCMDPAR_2_25_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_25_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_25_ADDR);
}

__INLINE void usbc_depcmdpar_2_25_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_25_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_25_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_25_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_25_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_25_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_25_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_25_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_25_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_25_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_25 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_25_ADDR        (REG_USBC_BASE_ADDR+0x0000C994)
#define USBC_DEPCMDPAR_1_25_OFFSET      0x0000C994
#define USBC_DEPCMDPAR_1_25_INDEX       0x00003265
#define USBC_DEPCMDPAR_1_25_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_25_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_25_ADDR);
}

__INLINE void usbc_depcmdpar_1_25_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_25_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_25_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_25_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_25_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_25_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_25_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_25_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_25_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_25_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_25 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_25_ADDR        (REG_USBC_BASE_ADDR+0x0000C998)
#define USBC_DEPCMDPAR_0_25_OFFSET      0x0000C998
#define USBC_DEPCMDPAR_0_25_INDEX       0x00003266
#define USBC_DEPCMDPAR_0_25_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_25_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_25_ADDR);
}

__INLINE void usbc_depcmdpar_0_25_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_25_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_25_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_25_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_25_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_25_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_25_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_25_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_25_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_25_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_25 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_25_ADDR        (REG_USBC_BASE_ADDR+0x0000C99C)
#define USBC_DEPCMD_25_OFFSET      0x0000C99C
#define USBC_DEPCMD_25_INDEX       0x00003267
#define USBC_DEPCMD_25_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_25_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_25_ADDR);
}

__INLINE void usbc_depcmd_25_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_25_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_25_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_25_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_25_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_25_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_25_CMDSTATUS_LSB        12
#define USBC_DEPCMD_25_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_25_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_25_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_25_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_25_CMDACT_POS           10
#define USBC_DEPCMD_25_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_25_RESERVED_9_POS       9
#define USBC_DEPCMD_25_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_25_CMDIOC_POS           8
#define USBC_DEPCMD_25_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_25_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_25_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_25_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_25_CMDTYP_LSB           0
#define USBC_DEPCMD_25_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_25_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_25_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_25_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_25_CMDACT_RST           0x0
#define USBC_DEPCMD_25_RESERVED_9_RST       0x0
#define USBC_DEPCMD_25_CMDIOC_RST           0x0
#define USBC_DEPCMD_25_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_25_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_25_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_25_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_25_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_25_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_25_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_25_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_25_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_25_ADDR, (REG_PL_RD(USBC_DEPCMD_25_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_25_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_25_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_25_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_25_ADDR, (REG_PL_RD(USBC_DEPCMD_25_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_25_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_25_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_25_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_25_ADDR, (REG_PL_RD(USBC_DEPCMD_25_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_25_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_25_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_25_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_25_ADDR, (REG_PL_RD(USBC_DEPCMD_25_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_25_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_25_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_25_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_25_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_25_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_25_ADDR, (REG_PL_RD(USBC_DEPCMD_25_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_25_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_25_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_25_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_25_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_25_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_25_ADDR, (REG_PL_RD(USBC_DEPCMD_25_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_26 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_26_ADDR        (REG_USBC_BASE_ADDR+0x0000C9A0)
#define USBC_DEPCMDPAR_2_26_OFFSET      0x0000C9A0
#define USBC_DEPCMDPAR_2_26_INDEX       0x00003268
#define USBC_DEPCMDPAR_2_26_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_26_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_26_ADDR);
}

__INLINE void usbc_depcmdpar_2_26_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_26_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_26_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_26_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_26_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_26_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_26_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_26_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_26_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_26_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_26 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_26_ADDR        (REG_USBC_BASE_ADDR+0x0000C9A4)
#define USBC_DEPCMDPAR_1_26_OFFSET      0x0000C9A4
#define USBC_DEPCMDPAR_1_26_INDEX       0x00003269
#define USBC_DEPCMDPAR_1_26_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_26_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_26_ADDR);
}

__INLINE void usbc_depcmdpar_1_26_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_26_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_26_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_26_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_26_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_26_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_26_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_26_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_26_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_26_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_26 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_26_ADDR        (REG_USBC_BASE_ADDR+0x0000C9A8)
#define USBC_DEPCMDPAR_0_26_OFFSET      0x0000C9A8
#define USBC_DEPCMDPAR_0_26_INDEX       0x0000326A
#define USBC_DEPCMDPAR_0_26_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_26_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_26_ADDR);
}

__INLINE void usbc_depcmdpar_0_26_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_26_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_26_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_26_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_26_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_26_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_26_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_26_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_26_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_26_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_26 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_26_ADDR        (REG_USBC_BASE_ADDR+0x0000C9AC)
#define USBC_DEPCMD_26_OFFSET      0x0000C9AC
#define USBC_DEPCMD_26_INDEX       0x0000326B
#define USBC_DEPCMD_26_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_26_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_26_ADDR);
}

__INLINE void usbc_depcmd_26_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_26_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_26_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_26_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_26_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_26_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_26_CMDSTATUS_LSB        12
#define USBC_DEPCMD_26_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_26_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_26_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_26_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_26_CMDACT_POS           10
#define USBC_DEPCMD_26_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_26_RESERVED_9_POS       9
#define USBC_DEPCMD_26_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_26_CMDIOC_POS           8
#define USBC_DEPCMD_26_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_26_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_26_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_26_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_26_CMDTYP_LSB           0
#define USBC_DEPCMD_26_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_26_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_26_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_26_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_26_CMDACT_RST           0x0
#define USBC_DEPCMD_26_RESERVED_9_RST       0x0
#define USBC_DEPCMD_26_CMDIOC_RST           0x0
#define USBC_DEPCMD_26_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_26_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_26_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_26_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_26_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_26_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_26_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_26_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_26_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_26_ADDR, (REG_PL_RD(USBC_DEPCMD_26_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_26_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_26_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_26_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_26_ADDR, (REG_PL_RD(USBC_DEPCMD_26_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_26_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_26_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_26_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_26_ADDR, (REG_PL_RD(USBC_DEPCMD_26_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_26_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_26_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_26_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_26_ADDR, (REG_PL_RD(USBC_DEPCMD_26_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_26_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_26_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_26_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_26_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_26_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_26_ADDR, (REG_PL_RD(USBC_DEPCMD_26_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_26_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_26_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_26_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_26_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_26_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_26_ADDR, (REG_PL_RD(USBC_DEPCMD_26_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_27 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_27_ADDR        (REG_USBC_BASE_ADDR+0x0000C9B0)
#define USBC_DEPCMDPAR_2_27_OFFSET      0x0000C9B0
#define USBC_DEPCMDPAR_2_27_INDEX       0x0000326C
#define USBC_DEPCMDPAR_2_27_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_27_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_27_ADDR);
}

__INLINE void usbc_depcmdpar_2_27_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_27_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_27_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_27_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_27_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_27_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_27_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_27_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_27_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_27_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_27 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_27_ADDR        (REG_USBC_BASE_ADDR+0x0000C9B4)
#define USBC_DEPCMDPAR_1_27_OFFSET      0x0000C9B4
#define USBC_DEPCMDPAR_1_27_INDEX       0x0000326D
#define USBC_DEPCMDPAR_1_27_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_27_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_27_ADDR);
}

__INLINE void usbc_depcmdpar_1_27_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_27_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_27_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_27_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_27_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_27_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_27_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_27_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_27_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_27_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_27 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_27_ADDR        (REG_USBC_BASE_ADDR+0x0000C9B8)
#define USBC_DEPCMDPAR_0_27_OFFSET      0x0000C9B8
#define USBC_DEPCMDPAR_0_27_INDEX       0x0000326E
#define USBC_DEPCMDPAR_0_27_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_27_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_27_ADDR);
}

__INLINE void usbc_depcmdpar_0_27_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_27_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_27_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_27_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_27_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_27_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_27_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_27_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_27_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_27_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_27 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_27_ADDR        (REG_USBC_BASE_ADDR+0x0000C9BC)
#define USBC_DEPCMD_27_OFFSET      0x0000C9BC
#define USBC_DEPCMD_27_INDEX       0x0000326F
#define USBC_DEPCMD_27_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_27_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_27_ADDR);
}

__INLINE void usbc_depcmd_27_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_27_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_27_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_27_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_27_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_27_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_27_CMDSTATUS_LSB        12
#define USBC_DEPCMD_27_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_27_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_27_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_27_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_27_CMDACT_POS           10
#define USBC_DEPCMD_27_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_27_RESERVED_9_POS       9
#define USBC_DEPCMD_27_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_27_CMDIOC_POS           8
#define USBC_DEPCMD_27_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_27_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_27_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_27_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_27_CMDTYP_LSB           0
#define USBC_DEPCMD_27_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_27_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_27_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_27_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_27_CMDACT_RST           0x0
#define USBC_DEPCMD_27_RESERVED_9_RST       0x0
#define USBC_DEPCMD_27_CMDIOC_RST           0x0
#define USBC_DEPCMD_27_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_27_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_27_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_27_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_27_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_27_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_27_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_27_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_27_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_27_ADDR, (REG_PL_RD(USBC_DEPCMD_27_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_27_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_27_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_27_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_27_ADDR, (REG_PL_RD(USBC_DEPCMD_27_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_27_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_27_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_27_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_27_ADDR, (REG_PL_RD(USBC_DEPCMD_27_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_27_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_27_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_27_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_27_ADDR, (REG_PL_RD(USBC_DEPCMD_27_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_27_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_27_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_27_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_27_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_27_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_27_ADDR, (REG_PL_RD(USBC_DEPCMD_27_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_27_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_27_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_27_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_27_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_27_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_27_ADDR, (REG_PL_RD(USBC_DEPCMD_27_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_28 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_28_ADDR        (REG_USBC_BASE_ADDR+0x0000C9C0)
#define USBC_DEPCMDPAR_2_28_OFFSET      0x0000C9C0
#define USBC_DEPCMDPAR_2_28_INDEX       0x00003270
#define USBC_DEPCMDPAR_2_28_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_28_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_28_ADDR);
}

__INLINE void usbc_depcmdpar_2_28_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_28_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_28_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_28_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_28_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_28_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_28_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_28_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_28_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_28_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_28 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_28_ADDR        (REG_USBC_BASE_ADDR+0x0000C9C4)
#define USBC_DEPCMDPAR_1_28_OFFSET      0x0000C9C4
#define USBC_DEPCMDPAR_1_28_INDEX       0x00003271
#define USBC_DEPCMDPAR_1_28_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_28_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_28_ADDR);
}

__INLINE void usbc_depcmdpar_1_28_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_28_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_28_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_28_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_28_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_28_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_28_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_28_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_28_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_28_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_28 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_28_ADDR        (REG_USBC_BASE_ADDR+0x0000C9C8)
#define USBC_DEPCMDPAR_0_28_OFFSET      0x0000C9C8
#define USBC_DEPCMDPAR_0_28_INDEX       0x00003272
#define USBC_DEPCMDPAR_0_28_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_28_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_28_ADDR);
}

__INLINE void usbc_depcmdpar_0_28_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_28_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_28_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_28_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_28_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_28_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_28_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_28_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_28_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_28_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_28 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_28_ADDR        (REG_USBC_BASE_ADDR+0x0000C9CC)
#define USBC_DEPCMD_28_OFFSET      0x0000C9CC
#define USBC_DEPCMD_28_INDEX       0x00003273
#define USBC_DEPCMD_28_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_28_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_28_ADDR);
}

__INLINE void usbc_depcmd_28_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_28_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_28_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_28_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_28_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_28_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_28_CMDSTATUS_LSB        12
#define USBC_DEPCMD_28_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_28_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_28_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_28_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_28_CMDACT_POS           10
#define USBC_DEPCMD_28_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_28_RESERVED_9_POS       9
#define USBC_DEPCMD_28_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_28_CMDIOC_POS           8
#define USBC_DEPCMD_28_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_28_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_28_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_28_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_28_CMDTYP_LSB           0
#define USBC_DEPCMD_28_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_28_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_28_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_28_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_28_CMDACT_RST           0x0
#define USBC_DEPCMD_28_RESERVED_9_RST       0x0
#define USBC_DEPCMD_28_CMDIOC_RST           0x0
#define USBC_DEPCMD_28_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_28_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_28_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_28_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_28_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_28_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_28_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_28_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_28_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_28_ADDR, (REG_PL_RD(USBC_DEPCMD_28_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_28_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_28_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_28_ADDR, (REG_PL_RD(USBC_DEPCMD_28_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_28_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_28_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_28_ADDR, (REG_PL_RD(USBC_DEPCMD_28_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_28_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_28_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_28_ADDR, (REG_PL_RD(USBC_DEPCMD_28_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_28_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_28_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_28_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_28_ADDR, (REG_PL_RD(USBC_DEPCMD_28_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_28_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_28_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_28_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_28_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_28_ADDR, (REG_PL_RD(USBC_DEPCMD_28_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_29 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_29_ADDR        (REG_USBC_BASE_ADDR+0x0000C9D0)
#define USBC_DEPCMDPAR_2_29_OFFSET      0x0000C9D0
#define USBC_DEPCMDPAR_2_29_INDEX       0x00003274
#define USBC_DEPCMDPAR_2_29_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_29_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_29_ADDR);
}

__INLINE void usbc_depcmdpar_2_29_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_29_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_29_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_29_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_29_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_29_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_29_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_29_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_29_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_29_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_29 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_29_ADDR        (REG_USBC_BASE_ADDR+0x0000C9D4)
#define USBC_DEPCMDPAR_1_29_OFFSET      0x0000C9D4
#define USBC_DEPCMDPAR_1_29_INDEX       0x00003275
#define USBC_DEPCMDPAR_1_29_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_29_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_29_ADDR);
}

__INLINE void usbc_depcmdpar_1_29_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_29_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_29_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_29_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_29_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_29_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_29_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_29_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_29_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_29_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_29 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_29_ADDR        (REG_USBC_BASE_ADDR+0x0000C9D8)
#define USBC_DEPCMDPAR_0_29_OFFSET      0x0000C9D8
#define USBC_DEPCMDPAR_0_29_INDEX       0x00003276
#define USBC_DEPCMDPAR_0_29_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_29_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_29_ADDR);
}

__INLINE void usbc_depcmdpar_0_29_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_29_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_29_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_29_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_29_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_29_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_29_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_29_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_29_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_29_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_29 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_29_ADDR        (REG_USBC_BASE_ADDR+0x0000C9DC)
#define USBC_DEPCMD_29_OFFSET      0x0000C9DC
#define USBC_DEPCMD_29_INDEX       0x00003277
#define USBC_DEPCMD_29_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_29_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_29_ADDR);
}

__INLINE void usbc_depcmd_29_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_29_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_29_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_29_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_29_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_29_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_29_CMDSTATUS_LSB        12
#define USBC_DEPCMD_29_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_29_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_29_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_29_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_29_CMDACT_POS           10
#define USBC_DEPCMD_29_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_29_RESERVED_9_POS       9
#define USBC_DEPCMD_29_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_29_CMDIOC_POS           8
#define USBC_DEPCMD_29_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_29_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_29_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_29_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_29_CMDTYP_LSB           0
#define USBC_DEPCMD_29_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_29_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_29_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_29_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_29_CMDACT_RST           0x0
#define USBC_DEPCMD_29_RESERVED_9_RST       0x0
#define USBC_DEPCMD_29_CMDIOC_RST           0x0
#define USBC_DEPCMD_29_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_29_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_29_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_29_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_29_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_29_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_29_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_29_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_29_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_29_ADDR, (REG_PL_RD(USBC_DEPCMD_29_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_29_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_29_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_29_ADDR, (REG_PL_RD(USBC_DEPCMD_29_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_29_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_29_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_29_ADDR, (REG_PL_RD(USBC_DEPCMD_29_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_29_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_29_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_29_ADDR, (REG_PL_RD(USBC_DEPCMD_29_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_29_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_29_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_29_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_29_ADDR, (REG_PL_RD(USBC_DEPCMD_29_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_29_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_29_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_29_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_29_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_29_ADDR, (REG_PL_RD(USBC_DEPCMD_29_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_30 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_30_ADDR        (REG_USBC_BASE_ADDR+0x0000C9E0)
#define USBC_DEPCMDPAR_2_30_OFFSET      0x0000C9E0
#define USBC_DEPCMDPAR_2_30_INDEX       0x00003278
#define USBC_DEPCMDPAR_2_30_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_30_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_30_ADDR);
}

__INLINE void usbc_depcmdpar_2_30_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_30_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_30_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_30_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_30_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_30_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_30_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_30_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_30_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_30_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_30 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_30_ADDR        (REG_USBC_BASE_ADDR+0x0000C9E4)
#define USBC_DEPCMDPAR_1_30_OFFSET      0x0000C9E4
#define USBC_DEPCMDPAR_1_30_INDEX       0x00003279
#define USBC_DEPCMDPAR_1_30_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_30_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_30_ADDR);
}

__INLINE void usbc_depcmdpar_1_30_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_30_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_30_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_30_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_30_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_30_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_30_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_30_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_30_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_30_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_30 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_30_ADDR        (REG_USBC_BASE_ADDR+0x0000C9E8)
#define USBC_DEPCMDPAR_0_30_OFFSET      0x0000C9E8
#define USBC_DEPCMDPAR_0_30_INDEX       0x0000327A
#define USBC_DEPCMDPAR_0_30_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_30_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_30_ADDR);
}

__INLINE void usbc_depcmdpar_0_30_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_30_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_30_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_30_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_30_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_30_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_30_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_30_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_30_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_30_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_30 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_30_ADDR        (REG_USBC_BASE_ADDR+0x0000C9EC)
#define USBC_DEPCMD_30_OFFSET      0x0000C9EC
#define USBC_DEPCMD_30_INDEX       0x0000327B
#define USBC_DEPCMD_30_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_30_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_30_ADDR);
}

__INLINE void usbc_depcmd_30_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_30_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_30_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_30_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_30_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_30_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_30_CMDSTATUS_LSB        12
#define USBC_DEPCMD_30_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_30_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_30_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_30_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_30_CMDACT_POS           10
#define USBC_DEPCMD_30_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_30_RESERVED_9_POS       9
#define USBC_DEPCMD_30_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_30_CMDIOC_POS           8
#define USBC_DEPCMD_30_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_30_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_30_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_30_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_30_CMDTYP_LSB           0
#define USBC_DEPCMD_30_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_30_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_30_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_30_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_30_CMDACT_RST           0x0
#define USBC_DEPCMD_30_RESERVED_9_RST       0x0
#define USBC_DEPCMD_30_CMDIOC_RST           0x0
#define USBC_DEPCMD_30_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_30_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_30_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_30_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_30_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_30_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_30_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_30_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_30_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_30_ADDR, (REG_PL_RD(USBC_DEPCMD_30_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_30_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_30_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_30_ADDR, (REG_PL_RD(USBC_DEPCMD_30_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_30_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_30_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_30_ADDR, (REG_PL_RD(USBC_DEPCMD_30_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_30_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_30_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_30_ADDR, (REG_PL_RD(USBC_DEPCMD_30_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_30_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_30_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_30_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_30_ADDR, (REG_PL_RD(USBC_DEPCMD_30_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_30_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_30_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_30_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_30_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_30_ADDR, (REG_PL_RD(USBC_DEPCMD_30_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEPCMDPAR_2_31 register definition
 *  Device Physical Endpoint-n Command Parameter 2 Register (DEPCMDPAR2n)  This register indicates the physical endpoint command Parameter 2. It must be programmed before issuing the command.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_2_31_ADDR        (REG_USBC_BASE_ADDR+0x0000C9F0)
#define USBC_DEPCMDPAR_2_31_OFFSET      0x0000C9F0
#define USBC_DEPCMDPAR_2_31_INDEX       0x0000327C
#define USBC_DEPCMDPAR_2_31_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_2_31_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_2_31_ADDR);
}

__INLINE void usbc_depcmdpar_2_31_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_2_31_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_2_31_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_2_31_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_2_31_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_2_31_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_2_31_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_2_31_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_2_31_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_2_31_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_1_31 register definition
 *  Device Physical Endpoint-n Command Parameter 1 Register (DEPCMDPAR1n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_1_31_ADDR        (REG_USBC_BASE_ADDR+0x0000C9F4)
#define USBC_DEPCMDPAR_1_31_OFFSET      0x0000C9F4
#define USBC_DEPCMDPAR_1_31_INDEX       0x0000327D
#define USBC_DEPCMDPAR_1_31_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_1_31_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_1_31_ADDR);
}

__INLINE void usbc_depcmdpar_1_31_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_1_31_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_1_31_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_1_31_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_1_31_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_1_31_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_1_31_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_1_31_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_1_31_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_1_31_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMDPAR_0_31 register definition
 *  Device Physical Endpoint-n Command Parameter 0 Register (DEPCMDPAR0n) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PARAMETER                 0x0
 * </pre>
 */
#define USBC_DEPCMDPAR_0_31_ADDR        (REG_USBC_BASE_ADDR+0x0000C9F8)
#define USBC_DEPCMDPAR_0_31_OFFSET      0x0000C9F8
#define USBC_DEPCMDPAR_0_31_INDEX       0x0000327E
#define USBC_DEPCMDPAR_0_31_RESET       0x00000000

__INLINE uint32_t  usbc_depcmdpar_0_31_get(void)
{
	return REG_PL_RD(USBC_DEPCMDPAR_0_31_ADDR);
}

__INLINE void usbc_depcmdpar_0_31_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMDPAR_0_31_ADDR, value);
}

// field definitions
#define USBC_DEPCMDPAR_0_31_PARAMETER_MASK    ((uint32_t)0xFFFFFFFF)
#define USBC_DEPCMDPAR_0_31_PARAMETER_LSB    0
#define USBC_DEPCMDPAR_0_31_PARAMETER_WIDTH    ((uint32_t)0x00000020)

#define USBC_DEPCMDPAR_0_31_PARAMETER_RST    0x0

__INLINE uint32_t usbc_depcmdpar_0_31_parameter_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMDPAR_0_31_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void usbc_depcmdpar_0_31_parameter_setf(uint32_t parameter)
{
	ASSERT_ERR((((uint32_t)parameter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(USBC_DEPCMDPAR_0_31_ADDR, (uint32_t)parameter << 0);
}

/**
 * @brief DEPCMD_31 register definition
 *  Device Physical Endpoint-n Command Register  This register enables software to issue physical endpoint-specific commands. This register contains command, control, and status fields relevant to the current generic command, while the DEPCMDPAR[2:0]n registers provide command parameters and return status information.  Several fields (including Command Type) are write-only, so their read values are undefined. After power-on, prior to issuing the first endpoint command, the read value of this register is undefined. In particular, the CmdAct bit may be set after power-on. In this case, it is safe to issue an endpoint command. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMMANDPARAM              0x0
 *    15:12 CMDSTATUS                 0x0
 *    11    HIPRI_FORCERM             0              
 *    10    CMDACT                    0              
 *    09    reserved_9                0              
 *    08    CMDIOC                    0              
 *    07:04 reserved_7_4              0x0
 *    03:00 CMDTYP                    0x0
 * </pre>
 */
#define USBC_DEPCMD_31_ADDR        (REG_USBC_BASE_ADDR+0x0000C9FC)
#define USBC_DEPCMD_31_OFFSET      0x0000C9FC
#define USBC_DEPCMD_31_INDEX       0x0000327F
#define USBC_DEPCMD_31_RESET       0x00000000

__INLINE uint32_t  usbc_depcmd_31_get(void)
{
	return REG_PL_RD(USBC_DEPCMD_31_ADDR);
}

__INLINE void usbc_depcmd_31_set(uint32_t value)
{
	REG_PL_WR(USBC_DEPCMD_31_ADDR, value);
}

// field definitions
#define USBC_DEPCMD_31_COMMANDPARAM_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEPCMD_31_COMMANDPARAM_LSB     16
#define USBC_DEPCMD_31_COMMANDPARAM_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEPCMD_31_CMDSTATUS_MASK       ((uint32_t)0x0000F000)
#define USBC_DEPCMD_31_CMDSTATUS_LSB        12
#define USBC_DEPCMD_31_CMDSTATUS_WIDTH      ((uint32_t)0x00000004)
#define USBC_DEPCMD_31_HIPRI_FORCERM_BIT    ((uint32_t)0x00000800)
#define USBC_DEPCMD_31_HIPRI_FORCERM_POS    11
#define USBC_DEPCMD_31_CMDACT_BIT           ((uint32_t)0x00000400)
#define USBC_DEPCMD_31_CMDACT_POS           10
#define USBC_DEPCMD_31_RESERVED_9_BIT       ((uint32_t)0x00000200)
#define USBC_DEPCMD_31_RESERVED_9_POS       9
#define USBC_DEPCMD_31_CMDIOC_BIT           ((uint32_t)0x00000100)
#define USBC_DEPCMD_31_CMDIOC_POS           8
#define USBC_DEPCMD_31_RESERVED_7_4_MASK    ((uint32_t)0x000000F0)
#define USBC_DEPCMD_31_RESERVED_7_4_LSB     4
#define USBC_DEPCMD_31_RESERVED_7_4_WIDTH    ((uint32_t)0x00000004)
#define USBC_DEPCMD_31_CMDTYP_MASK          ((uint32_t)0x0000000F)
#define USBC_DEPCMD_31_CMDTYP_LSB           0
#define USBC_DEPCMD_31_CMDTYP_WIDTH         ((uint32_t)0x00000004)

#define USBC_DEPCMD_31_COMMANDPARAM_RST     0x0
#define USBC_DEPCMD_31_CMDSTATUS_RST        0x0
#define USBC_DEPCMD_31_HIPRI_FORCERM_RST    0x0
#define USBC_DEPCMD_31_CMDACT_RST           0x0
#define USBC_DEPCMD_31_RESERVED_9_RST       0x0
#define USBC_DEPCMD_31_CMDIOC_RST           0x0
#define USBC_DEPCMD_31_RESERVED_7_4_RST     0x0
#define USBC_DEPCMD_31_CMDTYP_RST           0x0

__INLINE void usbc_depcmd_31_pack(uint16_t commandparam, uint8_t cmdstatus, uint8_t hipri_forcerm, uint8_t cmdact, uint8_t reserved_9, uint8_t cmdioc, uint8_t reserved_7_4, uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)hipri_forcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)reserved_9 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)reserved_7_4 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_31_ADDR,  ((uint32_t)commandparam << 16) |((uint32_t)cmdstatus << 12) |((uint32_t)hipri_forcerm << 11) |((uint32_t)cmdact << 10) |((uint32_t)reserved_9 << 9) |((uint32_t)cmdioc << 8) |((uint32_t)reserved_7_4 << 4) |((uint32_t)cmdtyp << 0));
}

__INLINE void usbc_depcmd_31_unpack(uint16_t* commandparam, uint8_t* cmdstatus, uint8_t* hipri_forcerm, uint8_t* cmdact, uint8_t* reserved_9, uint8_t* cmdioc, uint8_t* reserved_7_4, uint8_t* cmdtyp)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_31_ADDR);

	*commandparam = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*cmdstatus = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*hipri_forcerm = (localVal & ((uint32_t)0x00000800)) >>  11;
	*cmdact = (localVal & ((uint32_t)0x00000400)) >>  10;
	*reserved_9 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*cmdioc = (localVal & ((uint32_t)0x00000100)) >>  8;
	*reserved_7_4 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*cmdtyp = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t usbc_depcmd_31_commandparam_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_31_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_depcmd_31_commandparam_setf(uint16_t commandparam)
{
	ASSERT_ERR((((uint32_t)commandparam << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEPCMD_31_ADDR, (REG_PL_RD(USBC_DEPCMD_31_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)commandparam <<16));
}
__INLINE uint8_t usbc_depcmd_31_cmdstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_31_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void usbc_depcmd_31_cmdstatus_setf(uint8_t cmdstatus)
{
	ASSERT_ERR((((uint32_t)cmdstatus << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(USBC_DEPCMD_31_ADDR, (REG_PL_RD(USBC_DEPCMD_31_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)cmdstatus <<12));
}
__INLINE uint8_t usbc_depcmd_31_hipri_forcerm_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_31_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_depcmd_31_hipri_forcerm_setf(uint8_t hipriforcerm)
{
	ASSERT_ERR((((uint32_t)hipriforcerm << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_DEPCMD_31_ADDR, (REG_PL_RD(USBC_DEPCMD_31_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)hipriforcerm <<11));
}
__INLINE uint8_t usbc_depcmd_31_cmdact_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_31_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void usbc_depcmd_31_cmdact_setf(uint8_t cmdact)
{
	ASSERT_ERR((((uint32_t)cmdact << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(USBC_DEPCMD_31_ADDR, (REG_PL_RD(USBC_DEPCMD_31_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)cmdact <<10));
}
__INLINE uint8_t usbc_depcmd_31_reserved_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_31_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t usbc_depcmd_31_cmdioc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_31_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void usbc_depcmd_31_cmdioc_setf(uint8_t cmdioc)
{
	ASSERT_ERR((((uint32_t)cmdioc << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(USBC_DEPCMD_31_ADDR, (REG_PL_RD(USBC_DEPCMD_31_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)cmdioc <<8));
}
__INLINE uint8_t usbc_depcmd_31_reserved_7_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_31_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t usbc_depcmd_31_cmdtyp_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEPCMD_31_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void usbc_depcmd_31_cmdtyp_setf(uint8_t cmdtyp)
{
	ASSERT_ERR((((uint32_t)cmdtyp << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(USBC_DEPCMD_31_ADDR, (REG_PL_RD(USBC_DEPCMD_31_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)cmdtyp <<0));
}

/**
 * @brief DEV_IMOD_0 register definition
 *  Device Interrupt Moderation Register (DEV_IMOD)  This register controls the Interrupt Moderation feature that allows the device software to throttle the interrupt rate.  Key Functions:  - Interrupt Moderation is enabled only when the IMOD Interval is programmed to a non-zero value.  - Interrupt is asserted whenever the IMOD (down) counter is 0, EVNT_HANDLER_BUSY is 0, and there are pending events (that is, event count is non-zero)  - GEVNTCOUNT[EVNT_HANDLER_BUSY] is set by hardware when interrupt is asserted, and cleared by software when interrupt processing is completed.  - The Interrupt line is de-asserted after the first write to the event count.  - IMOD counter is loaded with IMOD interval whenever the Interrupt line is de-asserted.  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 DEVICE_IMODC              0x0
 *    15:00 DEVICE_IMODI              0x0
 * </pre>
 */
#define USBC_DEV_IMOD_0_ADDR        (REG_USBC_BASE_ADDR+0x0000CA00)
#define USBC_DEV_IMOD_0_OFFSET      0x0000CA00
#define USBC_DEV_IMOD_0_INDEX       0x00003280
#define USBC_DEV_IMOD_0_RESET       0x00000000

__INLINE uint32_t  usbc_dev_imod_0_get(void)
{
	return REG_PL_RD(USBC_DEV_IMOD_0_ADDR);
}

__INLINE void usbc_dev_imod_0_set(uint32_t value)
{
	REG_PL_WR(USBC_DEV_IMOD_0_ADDR, value);
}

// field definitions
#define USBC_DEV_IMOD_0_DEVICE_IMODC_MASK    ((uint32_t)0xFFFF0000)
#define USBC_DEV_IMOD_0_DEVICE_IMODC_LSB    16
#define USBC_DEV_IMOD_0_DEVICE_IMODC_WIDTH    ((uint32_t)0x00000010)
#define USBC_DEV_IMOD_0_DEVICE_IMODI_MASK    ((uint32_t)0x0000FFFF)
#define USBC_DEV_IMOD_0_DEVICE_IMODI_LSB    0
#define USBC_DEV_IMOD_0_DEVICE_IMODI_WIDTH    ((uint32_t)0x00000010)

#define USBC_DEV_IMOD_0_DEVICE_IMODC_RST    0x0
#define USBC_DEV_IMOD_0_DEVICE_IMODI_RST    0x0

__INLINE void usbc_dev_imod_0_pack(uint16_t device_imodc, uint16_t device_imodi)
{
	ASSERT_ERR((((uint32_t)device_imodc << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)device_imodi << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_DEV_IMOD_0_ADDR,  ((uint32_t)device_imodc << 16) |((uint32_t)device_imodi << 0));
}

__INLINE void usbc_dev_imod_0_unpack(uint16_t* device_imodc, uint16_t* device_imodi)
{
	uint32_t localVal = REG_PL_RD(USBC_DEV_IMOD_0_ADDR);

	*device_imodc = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*device_imodi = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t usbc_dev_imod_0_device_imodc_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEV_IMOD_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_dev_imod_0_device_imodc_setf(uint16_t deviceimodc)
{
	ASSERT_ERR((((uint32_t)deviceimodc << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_DEV_IMOD_0_ADDR, (REG_PL_RD(USBC_DEV_IMOD_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)deviceimodc <<16));
}
__INLINE uint16_t usbc_dev_imod_0_device_imodi_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_DEV_IMOD_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void usbc_dev_imod_0_device_imodi_setf(uint16_t deviceimodi)
{
	ASSERT_ERR((((uint32_t)deviceimodi << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(USBC_DEV_IMOD_0_ADDR, (REG_PL_RD(USBC_DEV_IMOD_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)deviceimodi <<0));
}

/**
 * @brief LU_1_LFPSRXTIM_0 register definition
 *  U1/U2 LFPS Rx Timer Register  - Link Layer Register for U1/U2 LFPS RX Timers.   - This register is common for all SS ports. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RESERVED_16_31            0x0
 *    15:08 u1u2_lfps_exit_rx_clk     0x1f
 *    07:00 u1u2_exit_rsp_rx_clk      0x1f
 * </pre>
 */
#define USBC_LU_1_LFPSRXTIM_0_ADDR        (REG_USBC_BASE_ADDR+0x0000D000)
#define USBC_LU_1_LFPSRXTIM_0_OFFSET      0x0000D000
#define USBC_LU_1_LFPSRXTIM_0_INDEX       0x00003400
#define USBC_LU_1_LFPSRXTIM_0_RESET       0x00001F1F

__INLINE uint32_t  usbc_lu_1_lfpsrxtim_0_get(void)
{
	return REG_PL_RD(USBC_LU_1_LFPSRXTIM_0_ADDR);
}

__INLINE void usbc_lu_1_lfpsrxtim_0_set(uint32_t value)
{
	REG_PL_WR(USBC_LU_1_LFPSRXTIM_0_ADDR, value);
}

// field definitions
#define USBC_LU_1_LFPSRXTIM_0_RESERVED_16_31_MASK    ((uint32_t)0xFFFF0000)
#define USBC_LU_1_LFPSRXTIM_0_RESERVED_16_31_LSB    16
#define USBC_LU_1_LFPSRXTIM_0_RESERVED_16_31_WIDTH    ((uint32_t)0x00000010)
#define USBC_LU_1_LFPSRXTIM_0_U_1_U_2_LFPS_EXIT_RX_CLK_MASK    ((uint32_t)0x0000FF00)
#define USBC_LU_1_LFPSRXTIM_0_U_1_U_2_LFPS_EXIT_RX_CLK_LSB    8
#define USBC_LU_1_LFPSRXTIM_0_U_1_U_2_LFPS_EXIT_RX_CLK_WIDTH    ((uint32_t)0x00000008)
#define USBC_LU_1_LFPSRXTIM_0_U_1_U_2_EXIT_RSP_RX_CLK_MASK    ((uint32_t)0x000000FF)
#define USBC_LU_1_LFPSRXTIM_0_U_1_U_2_EXIT_RSP_RX_CLK_LSB    0
#define USBC_LU_1_LFPSRXTIM_0_U_1_U_2_EXIT_RSP_RX_CLK_WIDTH    ((uint32_t)0x00000008)

#define USBC_LU_1_LFPSRXTIM_0_RESERVED_16_31_RST    0x0
#define USBC_LU_1_LFPSRXTIM_0_U_1_U_2_LFPS_EXIT_RX_CLK_RST    0x1f
#define USBC_LU_1_LFPSRXTIM_0_U_1_U_2_EXIT_RSP_RX_CLK_RST    0x1f

__INLINE void usbc_lu_1_lfpsrxtim_0_pack(uint16_t reserved_16_31, uint8_t u1u2_lfps_exit_rx_clk, uint8_t u1u2_exit_rsp_rx_clk)
{
	ASSERT_ERR((((uint32_t)reserved_16_31 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)u1u2_lfps_exit_rx_clk << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)u1u2_exit_rsp_rx_clk << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(USBC_LU_1_LFPSRXTIM_0_ADDR,  ((uint32_t)reserved_16_31 << 16) |((uint32_t)u1u2_lfps_exit_rx_clk << 8) |((uint32_t)u1u2_exit_rsp_rx_clk << 0));
}

__INLINE void usbc_lu_1_lfpsrxtim_0_unpack(uint16_t* reserved_16_31, uint8_t* u1u2_lfps_exit_rx_clk, uint8_t* u1u2_exit_rsp_rx_clk)
{
	uint32_t localVal = REG_PL_RD(USBC_LU_1_LFPSRXTIM_0_ADDR);

	*reserved_16_31 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*u1u2_lfps_exit_rx_clk = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*u1u2_exit_rsp_rx_clk = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint16_t usbc_lu_1_lfpsrxtim_0_reserved_16_31_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LU_1_LFPSRXTIM_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void usbc_lu_1_lfpsrxtim_0_reserved_16_31_setf(uint16_t reserved1631)
{
	ASSERT_ERR((((uint32_t)reserved1631 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(USBC_LU_1_LFPSRXTIM_0_ADDR, (REG_PL_RD(USBC_LU_1_LFPSRXTIM_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)reserved1631 <<16));
}
__INLINE uint8_t usbc_lu_1_lfpsrxtim_0_u_1_u_2_lfps_exit_rx_clk_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LU_1_LFPSRXTIM_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void usbc_lu_1_lfpsrxtim_0_u_1_u_2_lfps_exit_rx_clk_setf(uint8_t u1u2lfpsexitrxclk)
{
	ASSERT_ERR((((uint32_t)u1u2lfpsexitrxclk << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(USBC_LU_1_LFPSRXTIM_0_ADDR, (REG_PL_RD(USBC_LU_1_LFPSRXTIM_0_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)u1u2lfpsexitrxclk <<8));
}
__INLINE uint8_t usbc_lu_1_lfpsrxtim_0_u_1_u_2_exit_rsp_rx_clk_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LU_1_LFPSRXTIM_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void usbc_lu_1_lfpsrxtim_0_u_1_u_2_exit_rsp_rx_clk_setf(uint8_t u1u2exitrsprxclk)
{
	ASSERT_ERR((((uint32_t)u1u2exitrsprxclk << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(USBC_LU_1_LFPSRXTIM_0_ADDR, (REG_PL_RD(USBC_LU_1_LFPSRXTIM_0_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)u1u2exitrsprxclk <<0));
}

/**
 * @brief LINK_SETTINGS_0 register definition
 *  Link Setting Register  - Link Layer User Control Register for enabling Link/PHY-specific options.   - This register is common for all SS ports. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    RESERVED_31               0              
 *    30:28 u1_resid_timer_us         0x4
 *    27    RESERVED_27               0              
 *    26:24 pm_lc_timer_us            0x5
 *    23:20 pm_entry_timer_us         0x9
 *    19:00 RESERVED_0_19             0x0
 * </pre>
 */
#define USBC_LINK_SETTINGS_0_ADDR        (REG_USBC_BASE_ADDR+0x0000D020)
#define USBC_LINK_SETTINGS_0_OFFSET      0x0000D020
#define USBC_LINK_SETTINGS_0_INDEX       0x00003408
#define USBC_LINK_SETTINGS_0_RESET       0x45900000

__INLINE uint32_t  usbc_link_settings_0_get(void)
{
	return REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR);
}

__INLINE void usbc_link_settings_0_set(uint32_t value)
{
	REG_PL_WR(USBC_LINK_SETTINGS_0_ADDR, value);
}

// field definitions
#define USBC_LINK_SETTINGS_0_RESERVED_31_BIT    ((uint32_t)0x80000000)
#define USBC_LINK_SETTINGS_0_RESERVED_31_POS    31
#define USBC_LINK_SETTINGS_0_U_1_RESID_TIMER_US_MASK    ((uint32_t)0x70000000)
#define USBC_LINK_SETTINGS_0_U_1_RESID_TIMER_US_LSB    28
#define USBC_LINK_SETTINGS_0_U_1_RESID_TIMER_US_WIDTH    ((uint32_t)0x00000003)
#define USBC_LINK_SETTINGS_0_RESERVED_27_BIT    ((uint32_t)0x08000000)
#define USBC_LINK_SETTINGS_0_RESERVED_27_POS    27
#define USBC_LINK_SETTINGS_0_PM_LC_TIMER_US_MASK    ((uint32_t)0x07000000)
#define USBC_LINK_SETTINGS_0_PM_LC_TIMER_US_LSB    24
#define USBC_LINK_SETTINGS_0_PM_LC_TIMER_US_WIDTH    ((uint32_t)0x00000003)
#define USBC_LINK_SETTINGS_0_PM_ENTRY_TIMER_US_MASK    ((uint32_t)0x00F00000)
#define USBC_LINK_SETTINGS_0_PM_ENTRY_TIMER_US_LSB    20
#define USBC_LINK_SETTINGS_0_PM_ENTRY_TIMER_US_WIDTH    ((uint32_t)0x00000004)
#define USBC_LINK_SETTINGS_0_RESERVED_0_19_MASK    ((uint32_t)0x000FFFFF)
#define USBC_LINK_SETTINGS_0_RESERVED_0_19_LSB    0
#define USBC_LINK_SETTINGS_0_RESERVED_0_19_WIDTH    ((uint32_t)0x00000014)

#define USBC_LINK_SETTINGS_0_RESERVED_31_RST    0x0
#define USBC_LINK_SETTINGS_0_U_1_RESID_TIMER_US_RST    0x4
#define USBC_LINK_SETTINGS_0_RESERVED_27_RST    0x0
#define USBC_LINK_SETTINGS_0_PM_LC_TIMER_US_RST    0x5
#define USBC_LINK_SETTINGS_0_PM_ENTRY_TIMER_US_RST    0x9
#define USBC_LINK_SETTINGS_0_RESERVED_0_19_RST    0x0

__INLINE void usbc_link_settings_0_pack(uint8_t reserved_31, uint8_t u1_resid_timer_us, uint8_t reserved_27, uint8_t pm_lc_timer_us, uint8_t pm_entry_timer_us, uint32_t reserved_0_19)
{
	ASSERT_ERR((((uint32_t)reserved_31 << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)u1_resid_timer_us << 28) & ~((uint32_t)0x70000000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_27 << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)pm_lc_timer_us << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)pm_entry_timer_us << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_0_19 << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(USBC_LINK_SETTINGS_0_ADDR,  ((uint32_t)reserved_31 << 31) |((uint32_t)u1_resid_timer_us << 28) |((uint32_t)reserved_27 << 27) |((uint32_t)pm_lc_timer_us << 24) |((uint32_t)pm_entry_timer_us << 20) |((uint32_t)reserved_0_19 << 0));
}

__INLINE void usbc_link_settings_0_unpack(uint8_t* reserved_31, uint8_t* u1_resid_timer_us, uint8_t* reserved_27, uint8_t* pm_lc_timer_us, uint8_t* pm_entry_timer_us, uint32_t* reserved_0_19)
{
	uint32_t localVal = REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR);

	*reserved_31 = (localVal & ((uint32_t)0x80000000)) >>  31;
	*u1_resid_timer_us = (localVal & ((uint32_t)0x70000000)) >>  28;
	*reserved_27 = (localVal & ((uint32_t)0x08000000)) >>  27;
	*pm_lc_timer_us = (localVal & ((uint32_t)0x07000000)) >>  24;
	*pm_entry_timer_us = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*reserved_0_19 = (localVal & ((uint32_t)0x000FFFFF)) >>  0;
}

__INLINE uint8_t usbc_link_settings_0_reserved_31_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void usbc_link_settings_0_reserved_31_setf(uint8_t reserved31)
{
	ASSERT_ERR((((uint32_t)reserved31 << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(USBC_LINK_SETTINGS_0_ADDR, (REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)reserved31 <<31));
}
__INLINE uint8_t usbc_link_settings_0_u_1_resid_timer_us_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x70000000)) >> 28);
}
__INLINE void usbc_link_settings_0_u_1_resid_timer_us_setf(uint8_t u1residtimerus)
{
	ASSERT_ERR((((uint32_t)u1residtimerus << 28) & ~((uint32_t)0x70000000)) == 0);
	REG_PL_WR(USBC_LINK_SETTINGS_0_ADDR, (REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)u1residtimerus <<28));
}
__INLINE uint8_t usbc_link_settings_0_reserved_27_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void usbc_link_settings_0_reserved_27_setf(uint8_t reserved27)
{
	ASSERT_ERR((((uint32_t)reserved27 << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(USBC_LINK_SETTINGS_0_ADDR, (REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)reserved27 <<27));
}
__INLINE uint8_t usbc_link_settings_0_pm_lc_timer_us_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void usbc_link_settings_0_pm_lc_timer_us_setf(uint8_t pmlctimerus)
{
	ASSERT_ERR((((uint32_t)pmlctimerus << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(USBC_LINK_SETTINGS_0_ADDR, (REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)pmlctimerus <<24));
}
__INLINE uint8_t usbc_link_settings_0_pm_entry_timer_us_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void usbc_link_settings_0_pm_entry_timer_us_setf(uint8_t pmentrytimerus)
{
	ASSERT_ERR((((uint32_t)pmentrytimerus << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(USBC_LINK_SETTINGS_0_ADDR, (REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)pmentrytimerus <<20));
}
__INLINE uint32_t usbc_link_settings_0_reserved_0_19_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0x000FFFFF)) >> 0);
}
__INLINE void usbc_link_settings_0_reserved_0_19_setf(uint32_t reserved019)
{
	ASSERT_ERR((((uint32_t)reserved019 << 0) & ~((uint32_t)0x000FFFFF)) == 0);
	REG_PL_WR(USBC_LINK_SETTINGS_0_ADDR, (REG_PL_RD(USBC_LINK_SETTINGS_0_ADDR) & ~((uint32_t)0x000FFFFF)) | ((uint32_t)reserved019 <<0));
}

/**
 * @brief LLUCTL_0 register definition
 *  Link User Control Register  - Link Layer User Control Register for enabling Link/PHY-specific options.   - This register is common for all SS ports. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:30 RESERVED_30_31            0x0
 *    29    support_p4_pg             0              
 *    28    support_p4                0              
 *    27:24 RESERVED_24_27            0x0
 *    23    Dis_Rx_Det_LTSSM_Timer_Ovrrd 1              
 *    22:13 RESERVED_13_22            0x0
 *    12    U2_P3_CPMok               0              
 *    11    en_reset_pipe_after_phy_mux 0              
 *    10:08 RESERVED_8_10             0x0
 *    07    mask_pipe_reset           1              
 *    06    RESERVED_6                0              
 *    05    no_ux_exit_p0_trans       0              
 *    04:00 RESERVED_0_4              0x0
 * </pre>
 */
#define USBC_LLUCTL_0_ADDR        (REG_USBC_BASE_ADDR+0x0000D024)
#define USBC_LLUCTL_0_OFFSET      0x0000D024
#define USBC_LLUCTL_0_INDEX       0x00003409
#define USBC_LLUCTL_0_RESET       0x00800080

__INLINE uint32_t  usbc_lluctl_0_get(void)
{
	return REG_PL_RD(USBC_LLUCTL_0_ADDR);
}

__INLINE void usbc_lluctl_0_set(uint32_t value)
{
	REG_PL_WR(USBC_LLUCTL_0_ADDR, value);
}

// field definitions
#define USBC_LLUCTL_0_RESERVED_30_31_MASK    ((uint32_t)0xC0000000)
#define USBC_LLUCTL_0_RESERVED_30_31_LSB    30
#define USBC_LLUCTL_0_RESERVED_30_31_WIDTH    ((uint32_t)0x00000002)
#define USBC_LLUCTL_0_SUPPORT_P_4_PG_BIT    ((uint32_t)0x20000000)
#define USBC_LLUCTL_0_SUPPORT_P_4_PG_POS    29
#define USBC_LLUCTL_0_SUPPORT_P_4_BIT       ((uint32_t)0x10000000)
#define USBC_LLUCTL_0_SUPPORT_P_4_POS       28
#define USBC_LLUCTL_0_RESERVED_24_27_MASK    ((uint32_t)0x0F000000)
#define USBC_LLUCTL_0_RESERVED_24_27_LSB    24
#define USBC_LLUCTL_0_RESERVED_24_27_WIDTH    ((uint32_t)0x00000004)
#define USBC_LLUCTL_0_DIS_RX_DET_LTSSM_TIMER_OVRRD_BIT    ((uint32_t)0x00800000)
#define USBC_LLUCTL_0_DIS_RX_DET_LTSSM_TIMER_OVRRD_POS    23
#define USBC_LLUCTL_0_RESERVED_13_22_MASK    ((uint32_t)0x007FE000)
#define USBC_LLUCTL_0_RESERVED_13_22_LSB    13
#define USBC_LLUCTL_0_RESERVED_13_22_WIDTH    ((uint32_t)0x0000000A)
#define USBC_LLUCTL_0_U_2_P_3_CPMOK_BIT     ((uint32_t)0x00001000)
#define USBC_LLUCTL_0_U_2_P_3_CPMOK_POS     12
#define USBC_LLUCTL_0_EN_RESET_PIPE_AFTER_PHY_MUX_BIT    ((uint32_t)0x00000800)
#define USBC_LLUCTL_0_EN_RESET_PIPE_AFTER_PHY_MUX_POS    11
#define USBC_LLUCTL_0_RESERVED_8_10_MASK    ((uint32_t)0x00000700)
#define USBC_LLUCTL_0_RESERVED_8_10_LSB     8
#define USBC_LLUCTL_0_RESERVED_8_10_WIDTH    ((uint32_t)0x00000003)
#define USBC_LLUCTL_0_MASK_PIPE_RESET_BIT    ((uint32_t)0x00000080)
#define USBC_LLUCTL_0_MASK_PIPE_RESET_POS    7
#define USBC_LLUCTL_0_RESERVED_6_BIT        ((uint32_t)0x00000040)
#define USBC_LLUCTL_0_RESERVED_6_POS        6
#define USBC_LLUCTL_0_NO_UX_EXIT_P_0_TRANS_BIT    ((uint32_t)0x00000020)
#define USBC_LLUCTL_0_NO_UX_EXIT_P_0_TRANS_POS    5
#define USBC_LLUCTL_0_RESERVED_0_4_MASK     ((uint32_t)0x0000001F)
#define USBC_LLUCTL_0_RESERVED_0_4_LSB      0
#define USBC_LLUCTL_0_RESERVED_0_4_WIDTH    ((uint32_t)0x00000005)

#define USBC_LLUCTL_0_RESERVED_30_31_RST    0x0
#define USBC_LLUCTL_0_SUPPORT_P_4_PG_RST    0x0
#define USBC_LLUCTL_0_SUPPORT_P_4_RST       0x0
#define USBC_LLUCTL_0_RESERVED_24_27_RST    0x0
#define USBC_LLUCTL_0_DIS_RX_DET_LTSSM_TIMER_OVRRD_RST    0x1
#define USBC_LLUCTL_0_RESERVED_13_22_RST    0x0
#define USBC_LLUCTL_0_U_2_P_3_CPMOK_RST     0x0
#define USBC_LLUCTL_0_EN_RESET_PIPE_AFTER_PHY_MUX_RST    0x0
#define USBC_LLUCTL_0_RESERVED_8_10_RST     0x0
#define USBC_LLUCTL_0_MASK_PIPE_RESET_RST    0x1
#define USBC_LLUCTL_0_RESERVED_6_RST        0x0
#define USBC_LLUCTL_0_NO_UX_EXIT_P_0_TRANS_RST    0x0
#define USBC_LLUCTL_0_RESERVED_0_4_RST      0x0

__INLINE void usbc_lluctl_0_pack(uint8_t reserved_30_31, uint8_t support_p4_pg, uint8_t support_p4, uint8_t reserved_24_27, uint8_t dis_rx_det_ltssm_timer_ovrrd, uint16_t reserved_13_22, uint8_t u2_p3_cpmok, uint8_t en_reset_pipe_after_phy_mux, uint8_t reserved_8_10, uint8_t mask_pipe_reset, uint8_t reserved_6, uint8_t no_ux_exit_p0_trans, uint8_t reserved_0_4)
{
	ASSERT_ERR((((uint32_t)reserved_30_31 << 30) & ~((uint32_t)0xC0000000)) == 0);
	ASSERT_ERR((((uint32_t)support_p4_pg << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)support_p4 << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_24_27 << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)dis_rx_det_ltssm_timer_ovrrd << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)reserved_13_22 << 13) & ~((uint32_t)0x007FE000)) == 0);
	ASSERT_ERR((((uint32_t)u2_p3_cpmok << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)en_reset_pipe_after_phy_mux << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)reserved_8_10 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)mask_pipe_reset << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)reserved_6 << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)no_ux_exit_p0_trans << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)reserved_0_4 << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR,  ((uint32_t)reserved_30_31 << 30) |((uint32_t)support_p4_pg << 29) |((uint32_t)support_p4 << 28) |((uint32_t)reserved_24_27 << 24) |((uint32_t)dis_rx_det_ltssm_timer_ovrrd << 23) |((uint32_t)reserved_13_22 << 13) |((uint32_t)u2_p3_cpmok << 12) |((uint32_t)en_reset_pipe_after_phy_mux << 11) |((uint32_t)reserved_8_10 << 8) |((uint32_t)mask_pipe_reset << 7) |((uint32_t)reserved_6 << 6) |((uint32_t)no_ux_exit_p0_trans << 5) |((uint32_t)reserved_0_4 << 0));
}

__INLINE void usbc_lluctl_0_unpack(uint8_t* reserved_30_31, uint8_t* support_p4_pg, uint8_t* support_p4, uint8_t* reserved_24_27, uint8_t* dis_rx_det_ltssm_timer_ovrrd, uint16_t* reserved_13_22, uint8_t* u2_p3_cpmok, uint8_t* en_reset_pipe_after_phy_mux, uint8_t* reserved_8_10, uint8_t* mask_pipe_reset, uint8_t* reserved_6, uint8_t* no_ux_exit_p0_trans, uint8_t* reserved_0_4)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);

	*reserved_30_31 = (localVal & ((uint32_t)0xC0000000)) >>  30;
	*support_p4_pg = (localVal & ((uint32_t)0x20000000)) >>  29;
	*support_p4 = (localVal & ((uint32_t)0x10000000)) >>  28;
	*reserved_24_27 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*dis_rx_det_ltssm_timer_ovrrd = (localVal & ((uint32_t)0x00800000)) >>  23;
	*reserved_13_22 = (localVal & ((uint32_t)0x007FE000)) >>  13;
	*u2_p3_cpmok = (localVal & ((uint32_t)0x00001000)) >>  12;
	*en_reset_pipe_after_phy_mux = (localVal & ((uint32_t)0x00000800)) >>  11;
	*reserved_8_10 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*mask_pipe_reset = (localVal & ((uint32_t)0x00000080)) >>  7;
	*reserved_6 = (localVal & ((uint32_t)0x00000040)) >>  6;
	*no_ux_exit_p0_trans = (localVal & ((uint32_t)0x00000020)) >>  5;
	*reserved_0_4 = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t usbc_lluctl_0_reserved_30_31_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xC0000000)) >> 30);
}
__INLINE void usbc_lluctl_0_reserved_30_31_setf(uint8_t reserved3031)
{
	ASSERT_ERR((((uint32_t)reserved3031 << 30) & ~((uint32_t)0xC0000000)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0xC0000000)) | ((uint32_t)reserved3031 <<30));
}
__INLINE uint8_t usbc_lluctl_0_support_p_4_pg_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void usbc_lluctl_0_support_p_4_pg_setf(uint8_t supportp4pg)
{
	ASSERT_ERR((((uint32_t)supportp4pg << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0x20000000)) | ((uint32_t)supportp4pg <<29));
}
__INLINE uint8_t usbc_lluctl_0_support_p_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void usbc_lluctl_0_support_p_4_setf(uint8_t supportp4)
{
	ASSERT_ERR((((uint32_t)supportp4 << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)supportp4 <<28));
}
__INLINE uint8_t usbc_lluctl_0_reserved_24_27_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void usbc_lluctl_0_reserved_24_27_setf(uint8_t reserved2427)
{
	ASSERT_ERR((((uint32_t)reserved2427 << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)reserved2427 <<24));
}
__INLINE uint8_t usbc_lluctl_0_dis_rx_det_ltssm_timer_ovrrd_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void usbc_lluctl_0_dis_rx_det_ltssm_timer_ovrrd_setf(uint8_t disrxdetltssmtimerovrrd)
{
	ASSERT_ERR((((uint32_t)disrxdetltssmtimerovrrd << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)disrxdetltssmtimerovrrd <<23));
}
__INLINE uint16_t usbc_lluctl_0_reserved_13_22_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x007FE000)) >> 13);
}
__INLINE void usbc_lluctl_0_reserved_13_22_setf(uint16_t reserved1322)
{
	ASSERT_ERR((((uint32_t)reserved1322 << 13) & ~((uint32_t)0x007FE000)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0x007FE000)) | ((uint32_t)reserved1322 <<13));
}
__INLINE uint8_t usbc_lluctl_0_u_2_p_3_cpmok_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void usbc_lluctl_0_u_2_p_3_cpmok_setf(uint8_t u2p3cpmok)
{
	ASSERT_ERR((((uint32_t)u2p3cpmok << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)u2p3cpmok <<12));
}
__INLINE uint8_t usbc_lluctl_0_en_reset_pipe_after_phy_mux_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void usbc_lluctl_0_en_reset_pipe_after_phy_mux_setf(uint8_t enresetpipeafterphymux)
{
	ASSERT_ERR((((uint32_t)enresetpipeafterphymux << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)enresetpipeafterphymux <<11));
}
__INLINE uint8_t usbc_lluctl_0_reserved_8_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void usbc_lluctl_0_reserved_8_10_setf(uint8_t reserved810)
{
	ASSERT_ERR((((uint32_t)reserved810 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)reserved810 <<8));
}
__INLINE uint8_t usbc_lluctl_0_mask_pipe_reset_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void usbc_lluctl_0_mask_pipe_reset_setf(uint8_t maskpipereset)
{
	ASSERT_ERR((((uint32_t)maskpipereset << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)maskpipereset <<7));
}
__INLINE uint8_t usbc_lluctl_0_reserved_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void usbc_lluctl_0_reserved_6_setf(uint8_t reserved6)
{
	ASSERT_ERR((((uint32_t)reserved6 << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)reserved6 <<6));
}
__INLINE uint8_t usbc_lluctl_0_no_ux_exit_p_0_trans_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void usbc_lluctl_0_no_ux_exit_p_0_trans_setf(uint8_t nouxexitp0trans)
{
	ASSERT_ERR((((uint32_t)nouxexitp0trans << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)nouxexitp0trans <<5));
}
__INLINE uint8_t usbc_lluctl_0_reserved_0_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LLUCTL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void usbc_lluctl_0_reserved_0_4_setf(uint8_t reserved04)
{
	ASSERT_ERR((((uint32_t)reserved04 << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(USBC_LLUCTL_0_ADDR, (REG_PL_RD(USBC_LLUCTL_0_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)reserved04 <<0));
}

/**
 * @brief LPTMDPDELAY_0 register definition
 *  Link Datapath Delay Register  - Link Layer Timer Register for P3CPM/P4 Residency.  - This register is common for all SS ports. register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:22 RESERVED_22_31            0x0
 *    21:10 p3cpmp4_residency         0x3
 *    09:00 RESERVED_0_9              0x0
 * </pre>
 */
#define USBC_LPTMDPDELAY_0_ADDR        (REG_USBC_BASE_ADDR+0x0000D028)
#define USBC_LPTMDPDELAY_0_OFFSET      0x0000D028
#define USBC_LPTMDPDELAY_0_INDEX       0x0000340A
#define USBC_LPTMDPDELAY_0_RESET       0x00000C00

__INLINE uint32_t  usbc_lptmdpdelay_0_get(void)
{
	return REG_PL_RD(USBC_LPTMDPDELAY_0_ADDR);
}

__INLINE void usbc_lptmdpdelay_0_set(uint32_t value)
{
	REG_PL_WR(USBC_LPTMDPDELAY_0_ADDR, value);
}

// field definitions
#define USBC_LPTMDPDELAY_0_RESERVED_22_31_MASK    ((uint32_t)0xFFC00000)
#define USBC_LPTMDPDELAY_0_RESERVED_22_31_LSB    22
#define USBC_LPTMDPDELAY_0_RESERVED_22_31_WIDTH    ((uint32_t)0x0000000A)
#define USBC_LPTMDPDELAY_0_P_3_CPMP_4_RESIDENCY_MASK    ((uint32_t)0x003FFC00)
#define USBC_LPTMDPDELAY_0_P_3_CPMP_4_RESIDENCY_LSB    10
#define USBC_LPTMDPDELAY_0_P_3_CPMP_4_RESIDENCY_WIDTH    ((uint32_t)0x0000000C)
#define USBC_LPTMDPDELAY_0_RESERVED_0_9_MASK    ((uint32_t)0x000003FF)
#define USBC_LPTMDPDELAY_0_RESERVED_0_9_LSB    0
#define USBC_LPTMDPDELAY_0_RESERVED_0_9_WIDTH    ((uint32_t)0x0000000A)

#define USBC_LPTMDPDELAY_0_RESERVED_22_31_RST    0x0
#define USBC_LPTMDPDELAY_0_P_3_CPMP_4_RESIDENCY_RST    0x3
#define USBC_LPTMDPDELAY_0_RESERVED_0_9_RST    0x0

__INLINE void usbc_lptmdpdelay_0_pack(uint16_t reserved_22_31, uint16_t p3cpmp4_residency, uint16_t reserved_0_9)
{
	ASSERT_ERR((((uint32_t)reserved_22_31 << 22) & ~((uint32_t)0xFFC00000)) == 0);
	ASSERT_ERR((((uint32_t)p3cpmp4_residency << 10) & ~((uint32_t)0x003FFC00)) == 0);
	ASSERT_ERR((((uint32_t)reserved_0_9 << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(USBC_LPTMDPDELAY_0_ADDR,  ((uint32_t)reserved_22_31 << 22) |((uint32_t)p3cpmp4_residency << 10) |((uint32_t)reserved_0_9 << 0));
}

__INLINE void usbc_lptmdpdelay_0_unpack(uint16_t* reserved_22_31, uint16_t* p3cpmp4_residency, uint16_t* reserved_0_9)
{
	uint32_t localVal = REG_PL_RD(USBC_LPTMDPDELAY_0_ADDR);

	*reserved_22_31 = (localVal & ((uint32_t)0xFFC00000)) >>  22;
	*p3cpmp4_residency = (localVal & ((uint32_t)0x003FFC00)) >>  10;
	*reserved_0_9 = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint16_t usbc_lptmdpdelay_0_reserved_22_31_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LPTMDPDELAY_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFC00000)) >> 22);
}
__INLINE void usbc_lptmdpdelay_0_reserved_22_31_setf(uint16_t reserved2231)
{
	ASSERT_ERR((((uint32_t)reserved2231 << 22) & ~((uint32_t)0xFFC00000)) == 0);
	REG_PL_WR(USBC_LPTMDPDELAY_0_ADDR, (REG_PL_RD(USBC_LPTMDPDELAY_0_ADDR) & ~((uint32_t)0xFFC00000)) | ((uint32_t)reserved2231 <<22));
}
__INLINE uint16_t usbc_lptmdpdelay_0_p_3_cpmp_4_residency_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LPTMDPDELAY_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x003FFC00)) >> 10);
}
__INLINE void usbc_lptmdpdelay_0_p_3_cpmp_4_residency_setf(uint16_t p3cpmp4residency)
{
	ASSERT_ERR((((uint32_t)p3cpmp4residency << 10) & ~((uint32_t)0x003FFC00)) == 0);
	REG_PL_WR(USBC_LPTMDPDELAY_0_ADDR, (REG_PL_RD(USBC_LPTMDPDELAY_0_ADDR) & ~((uint32_t)0x003FFC00)) | ((uint32_t)p3cpmp4residency <<10));
}
__INLINE uint16_t usbc_lptmdpdelay_0_reserved_0_9_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_LPTMDPDELAY_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void usbc_lptmdpdelay_0_reserved_0_9_setf(uint16_t reserved09)
{
	ASSERT_ERR((((uint32_t)reserved09 << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(USBC_LPTMDPDELAY_0_ADDR, (REG_PL_RD(USBC_LPTMDPDELAY_0_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)reserved09 <<0));
}

/**
 * @brief U_3_RHBDBG_0 register definition
 *  U3 Root Hub Debug Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:04 Reserved_1                0x0
 *    03    tpcfg_tout_ctrl           0              
 *    02:00 Reserved_0_2              0x0
 * </pre>
 */
#define USBC_U_3_RHBDBG_0_ADDR        (REG_USBC_BASE_ADDR+0x0000D800)
#define USBC_U_3_RHBDBG_0_OFFSET      0x0000D800
#define USBC_U_3_RHBDBG_0_INDEX       0x00003600
#define USBC_U_3_RHBDBG_0_RESET       0x00000000

__INLINE uint32_t  usbc_u_3_rhbdbg_0_get(void)
{
	return REG_PL_RD(USBC_U_3_RHBDBG_0_ADDR);
}

__INLINE void usbc_u_3_rhbdbg_0_set(uint32_t value)
{
	REG_PL_WR(USBC_U_3_RHBDBG_0_ADDR, value);
}

// field definitions
#define USBC_U_3_RHBDBG_0_RESERVED_1_MASK    ((uint32_t)0xFFFFFFF0)
#define USBC_U_3_RHBDBG_0_RESERVED_1_LSB    4
#define USBC_U_3_RHBDBG_0_RESERVED_1_WIDTH    ((uint32_t)0x0000001C)
#define USBC_U_3_RHBDBG_0_TPCFG_TOUT_CTRL_BIT    ((uint32_t)0x00000008)
#define USBC_U_3_RHBDBG_0_TPCFG_TOUT_CTRL_POS    3
#define USBC_U_3_RHBDBG_0_RESERVED_0_2_MASK    ((uint32_t)0x00000007)
#define USBC_U_3_RHBDBG_0_RESERVED_0_2_LSB    0
#define USBC_U_3_RHBDBG_0_RESERVED_0_2_WIDTH    ((uint32_t)0x00000003)

#define USBC_U_3_RHBDBG_0_RESERVED_1_RST    0x0
#define USBC_U_3_RHBDBG_0_TPCFG_TOUT_CTRL_RST    0x0
#define USBC_U_3_RHBDBG_0_RESERVED_0_2_RST    0x0

__INLINE void usbc_u_3_rhbdbg_0_pack(uint32_t reserved_1, uint8_t tpcfg_tout_ctrl, uint8_t reserved_0_2)
{
	ASSERT_ERR((((uint32_t)reserved_1 << 4) & ~((uint32_t)0xFFFFFFF0)) == 0);
	ASSERT_ERR((((uint32_t)tpcfg_tout_ctrl << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)reserved_0_2 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(USBC_U_3_RHBDBG_0_ADDR,  ((uint32_t)reserved_1 << 4) |((uint32_t)tpcfg_tout_ctrl << 3) |((uint32_t)reserved_0_2 << 0));
}

__INLINE void usbc_u_3_rhbdbg_0_unpack(uint32_t* reserved_1, uint8_t* tpcfg_tout_ctrl, uint8_t* reserved_0_2)
{
	uint32_t localVal = REG_PL_RD(USBC_U_3_RHBDBG_0_ADDR);

	*reserved_1 = (localVal & ((uint32_t)0xFFFFFFF0)) >>  4;
	*tpcfg_tout_ctrl = (localVal & ((uint32_t)0x00000008)) >>  3;
	*reserved_0_2 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint32_t usbc_u_3_rhbdbg_0_reserved_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_U_3_RHBDBG_0_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFFFF0)) >> 4);
}
__INLINE uint8_t usbc_u_3_rhbdbg_0_tpcfg_tout_ctrl_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_U_3_RHBDBG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void usbc_u_3_rhbdbg_0_tpcfg_tout_ctrl_setf(uint8_t tpcfgtoutctrl)
{
	ASSERT_ERR((((uint32_t)tpcfgtoutctrl << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(USBC_U_3_RHBDBG_0_ADDR, (REG_PL_RD(USBC_U_3_RHBDBG_0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)tpcfgtoutctrl <<3));
}
__INLINE uint8_t usbc_u_3_rhbdbg_0_reserved_0_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_U_3_RHBDBG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief U_3_RHBDBG_1 register definition
 *  U3 Root Hub Debug Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:04 Reserved_1                0x0
 *    03    tpcfg_tout_ctrl           0              
 *    02:00 Reserved_0_2              0x0
 * </pre>
 */
#define USBC_U_3_RHBDBG_1_ADDR        (REG_USBC_BASE_ADDR+0x0000D804)
#define USBC_U_3_RHBDBG_1_OFFSET      0x0000D804
#define USBC_U_3_RHBDBG_1_INDEX       0x00003601
#define USBC_U_3_RHBDBG_1_RESET       0x00000000

__INLINE uint32_t  usbc_u_3_rhbdbg_1_get(void)
{
	return REG_PL_RD(USBC_U_3_RHBDBG_1_ADDR);
}

__INLINE void usbc_u_3_rhbdbg_1_set(uint32_t value)
{
	REG_PL_WR(USBC_U_3_RHBDBG_1_ADDR, value);
}

// field definitions
#define USBC_U_3_RHBDBG_1_RESERVED_1_MASK    ((uint32_t)0xFFFFFFF0)
#define USBC_U_3_RHBDBG_1_RESERVED_1_LSB    4
#define USBC_U_3_RHBDBG_1_RESERVED_1_WIDTH    ((uint32_t)0x0000001C)
#define USBC_U_3_RHBDBG_1_TPCFG_TOUT_CTRL_BIT    ((uint32_t)0x00000008)
#define USBC_U_3_RHBDBG_1_TPCFG_TOUT_CTRL_POS    3
#define USBC_U_3_RHBDBG_1_RESERVED_0_2_MASK    ((uint32_t)0x00000007)
#define USBC_U_3_RHBDBG_1_RESERVED_0_2_LSB    0
#define USBC_U_3_RHBDBG_1_RESERVED_0_2_WIDTH    ((uint32_t)0x00000003)

#define USBC_U_3_RHBDBG_1_RESERVED_1_RST    0x0
#define USBC_U_3_RHBDBG_1_TPCFG_TOUT_CTRL_RST    0x0
#define USBC_U_3_RHBDBG_1_RESERVED_0_2_RST    0x0

__INLINE void usbc_u_3_rhbdbg_1_pack(uint32_t reserved_1, uint8_t tpcfg_tout_ctrl, uint8_t reserved_0_2)
{
	ASSERT_ERR((((uint32_t)reserved_1 << 4) & ~((uint32_t)0xFFFFFFF0)) == 0);
	ASSERT_ERR((((uint32_t)tpcfg_tout_ctrl << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)reserved_0_2 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(USBC_U_3_RHBDBG_1_ADDR,  ((uint32_t)reserved_1 << 4) |((uint32_t)tpcfg_tout_ctrl << 3) |((uint32_t)reserved_0_2 << 0));
}

__INLINE void usbc_u_3_rhbdbg_1_unpack(uint32_t* reserved_1, uint8_t* tpcfg_tout_ctrl, uint8_t* reserved_0_2)
{
	uint32_t localVal = REG_PL_RD(USBC_U_3_RHBDBG_1_ADDR);

	*reserved_1 = (localVal & ((uint32_t)0xFFFFFFF0)) >>  4;
	*tpcfg_tout_ctrl = (localVal & ((uint32_t)0x00000008)) >>  3;
	*reserved_0_2 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint32_t usbc_u_3_rhbdbg_1_reserved_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_U_3_RHBDBG_1_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFFFF0)) >> 4);
}
__INLINE uint8_t usbc_u_3_rhbdbg_1_tpcfg_tout_ctrl_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_U_3_RHBDBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void usbc_u_3_rhbdbg_1_tpcfg_tout_ctrl_setf(uint8_t tpcfgtoutctrl)
{
	ASSERT_ERR((((uint32_t)tpcfgtoutctrl << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(USBC_U_3_RHBDBG_1_ADDR, (REG_PL_RD(USBC_U_3_RHBDBG_1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)tpcfgtoutctrl <<3));
}
__INLINE uint8_t usbc_u_3_rhbdbg_1_reserved_0_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_U_3_RHBDBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief U_3_RHBDBG_2 register definition
 *  U3 Root Hub Debug Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:04 Reserved_1                0x0
 *    03    tpcfg_tout_ctrl           0              
 *    02:00 Reserved_0_2              0x0
 * </pre>
 */
#define USBC_U_3_RHBDBG_2_ADDR        (REG_USBC_BASE_ADDR+0x0000D808)
#define USBC_U_3_RHBDBG_2_OFFSET      0x0000D808
#define USBC_U_3_RHBDBG_2_INDEX       0x00003602
#define USBC_U_3_RHBDBG_2_RESET       0x00000000

__INLINE uint32_t  usbc_u_3_rhbdbg_2_get(void)
{
	return REG_PL_RD(USBC_U_3_RHBDBG_2_ADDR);
}

__INLINE void usbc_u_3_rhbdbg_2_set(uint32_t value)
{
	REG_PL_WR(USBC_U_3_RHBDBG_2_ADDR, value);
}

// field definitions
#define USBC_U_3_RHBDBG_2_RESERVED_1_MASK    ((uint32_t)0xFFFFFFF0)
#define USBC_U_3_RHBDBG_2_RESERVED_1_LSB    4
#define USBC_U_3_RHBDBG_2_RESERVED_1_WIDTH    ((uint32_t)0x0000001C)
#define USBC_U_3_RHBDBG_2_TPCFG_TOUT_CTRL_BIT    ((uint32_t)0x00000008)
#define USBC_U_3_RHBDBG_2_TPCFG_TOUT_CTRL_POS    3
#define USBC_U_3_RHBDBG_2_RESERVED_0_2_MASK    ((uint32_t)0x00000007)
#define USBC_U_3_RHBDBG_2_RESERVED_0_2_LSB    0
#define USBC_U_3_RHBDBG_2_RESERVED_0_2_WIDTH    ((uint32_t)0x00000003)

#define USBC_U_3_RHBDBG_2_RESERVED_1_RST    0x0
#define USBC_U_3_RHBDBG_2_TPCFG_TOUT_CTRL_RST    0x0
#define USBC_U_3_RHBDBG_2_RESERVED_0_2_RST    0x0

__INLINE void usbc_u_3_rhbdbg_2_pack(uint32_t reserved_1, uint8_t tpcfg_tout_ctrl, uint8_t reserved_0_2)
{
	ASSERT_ERR((((uint32_t)reserved_1 << 4) & ~((uint32_t)0xFFFFFFF0)) == 0);
	ASSERT_ERR((((uint32_t)tpcfg_tout_ctrl << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)reserved_0_2 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(USBC_U_3_RHBDBG_2_ADDR,  ((uint32_t)reserved_1 << 4) |((uint32_t)tpcfg_tout_ctrl << 3) |((uint32_t)reserved_0_2 << 0));
}

__INLINE void usbc_u_3_rhbdbg_2_unpack(uint32_t* reserved_1, uint8_t* tpcfg_tout_ctrl, uint8_t* reserved_0_2)
{
	uint32_t localVal = REG_PL_RD(USBC_U_3_RHBDBG_2_ADDR);

	*reserved_1 = (localVal & ((uint32_t)0xFFFFFFF0)) >>  4;
	*tpcfg_tout_ctrl = (localVal & ((uint32_t)0x00000008)) >>  3;
	*reserved_0_2 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint32_t usbc_u_3_rhbdbg_2_reserved_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_U_3_RHBDBG_2_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFFFF0)) >> 4);
}
__INLINE uint8_t usbc_u_3_rhbdbg_2_tpcfg_tout_ctrl_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_U_3_RHBDBG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void usbc_u_3_rhbdbg_2_tpcfg_tout_ctrl_setf(uint8_t tpcfgtoutctrl)
{
	ASSERT_ERR((((uint32_t)tpcfgtoutctrl << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(USBC_U_3_RHBDBG_2_ADDR, (REG_PL_RD(USBC_U_3_RHBDBG_2_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)tpcfgtoutctrl <<3));
}
__INLINE uint8_t usbc_u_3_rhbdbg_2_reserved_0_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(USBC_U_3_RHBDBG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}


#undef DBG_FILEID
#endif //_REG_USBC_H_
