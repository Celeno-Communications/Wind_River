#ifndef _REG_MODEM_BF_H_
#define _REG_MODEM_BF_H_

#include <stdint.h>
#include "phy/_reg_modem_bf.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_MODEM_BF__H__FILEID__

#define REG_MODEM_BF_COUNT  67


/**
 * @brief SEL_PAUSE register definition
 *  Beamformer module select, reset and pause/resume register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    pause                     0              
 *    00    module_sel                0              
 * </pre>
 */
#define MODEM_BF_SEL_PAUSE_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000000)
#define MODEM_BF_SEL_PAUSE_OFFSET      0x00000000
#define MODEM_BF_SEL_PAUSE_INDEX       0x00000000
#define MODEM_BF_SEL_PAUSE_RESET       0x00000000

__INLINE uint32_t  modem_bf_sel_pause_get(void)
{
	return REG_PL_RD(MODEM_BF_SEL_PAUSE_ADDR);
}

__INLINE void modem_bf_sel_pause_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_SEL_PAUSE_ADDR, value);
}

// field definitions
#define MODEM_BF_SEL_PAUSE_PAUSE_BIT        ((uint32_t)0x00000002)
#define MODEM_BF_SEL_PAUSE_PAUSE_POS        1
#define MODEM_BF_SEL_PAUSE_MODULE_SEL_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_SEL_PAUSE_MODULE_SEL_POS    0

#define MODEM_BF_SEL_PAUSE_PAUSE_RST        0x0
#define MODEM_BF_SEL_PAUSE_MODULE_SEL_RST    0x0

__INLINE void modem_bf_sel_pause_pack(uint8_t pause, uint8_t module_sel)
{
	ASSERT_ERR((((uint32_t)pause << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)module_sel << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_SEL_PAUSE_ADDR,  ((uint32_t)pause << 1) |((uint32_t)module_sel << 0));
}

__INLINE void modem_bf_sel_pause_unpack(uint8_t* pause, uint8_t* module_sel)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_SEL_PAUSE_ADDR);

	*pause = (localVal & ((uint32_t)0x00000002)) >>  1;
	*module_sel = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_sel_pause_pause_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_SEL_PAUSE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void modem_bf_sel_pause_pause_setf(uint8_t pause)
{
	ASSERT_ERR((((uint32_t)pause << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MODEM_BF_SEL_PAUSE_ADDR, (REG_PL_RD(MODEM_BF_SEL_PAUSE_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)pause <<1));
}
__INLINE uint8_t modem_bf_sel_pause_module_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_SEL_PAUSE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void modem_bf_sel_pause_module_sel_setf(uint8_t modulesel)
{
	ASSERT_ERR((((uint32_t)modulesel << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_SEL_PAUSE_ADDR, (REG_PL_RD(MODEM_BF_SEL_PAUSE_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)modulesel <<0));
}

/**
 * @brief DEBUG register definition
 *  Beamformer LCU Debug register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:01 debug_mode                0x0
 *    00    debug_en                  0              
 * </pre>
 */
#define MODEM_BF_DEBUG_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000004)
#define MODEM_BF_DEBUG_OFFSET      0x00000004
#define MODEM_BF_DEBUG_INDEX       0x00000001
#define MODEM_BF_DEBUG_RESET       0x00000000

__INLINE uint32_t  modem_bf_debug_get(void)
{
	return REG_PL_RD(MODEM_BF_DEBUG_ADDR);
}

__INLINE void modem_bf_debug_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEBUG_ADDR, value);
}

// field definitions
#define MODEM_BF_DEBUG_DEBUG_MODE_MASK      ((uint32_t)0x0000003E)
#define MODEM_BF_DEBUG_DEBUG_MODE_LSB       1
#define MODEM_BF_DEBUG_DEBUG_MODE_WIDTH     ((uint32_t)0x00000005)
#define MODEM_BF_DEBUG_DEBUG_EN_BIT         ((uint32_t)0x00000001)
#define MODEM_BF_DEBUG_DEBUG_EN_POS         0

#define MODEM_BF_DEBUG_DEBUG_MODE_RST       0x0
#define MODEM_BF_DEBUG_DEBUG_EN_RST         0x0

__INLINE void modem_bf_debug_pack(uint8_t debug_mode, uint8_t debug_en)
{
	ASSERT_ERR((((uint32_t)debug_mode << 1) & ~((uint32_t)0x0000003E)) == 0);
	ASSERT_ERR((((uint32_t)debug_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEBUG_ADDR,  ((uint32_t)debug_mode << 1) |((uint32_t)debug_en << 0));
}

__INLINE void modem_bf_debug_unpack(uint8_t* debug_mode, uint8_t* debug_en)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEBUG_ADDR);

	*debug_mode = (localVal & ((uint32_t)0x0000003E)) >>  1;
	*debug_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_debug_debug_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEBUG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003E)) >> 1);
}
__INLINE void modem_bf_debug_debug_mode_setf(uint8_t debugmode)
{
	ASSERT_ERR((((uint32_t)debugmode << 1) & ~((uint32_t)0x0000003E)) == 0);
	REG_PL_WR(MODEM_BF_DEBUG_ADDR, (REG_PL_RD(MODEM_BF_DEBUG_ADDR) & ~((uint32_t)0x0000003E)) | ((uint32_t)debugmode <<1));
}
__INLINE uint8_t modem_bf_debug_debug_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEBUG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void modem_bf_debug_debug_en_setf(uint8_t debugen)
{
	ASSERT_ERR((((uint32_t)debugen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEBUG_ADDR, (REG_PL_RD(MODEM_BF_DEBUG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)debugen <<0));
}

/**
 * @brief PACK_STATIC_CONFIG register definition
 *  Pack Acc Static Configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    enable_mcci               0              
 *    00    saturate_snrs             0              
 * </pre>
 */
#define MODEM_BF_PACK_STATIC_CONFIG_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000008)
#define MODEM_BF_PACK_STATIC_CONFIG_OFFSET      0x00000008
#define MODEM_BF_PACK_STATIC_CONFIG_INDEX       0x00000002
#define MODEM_BF_PACK_STATIC_CONFIG_RESET       0x00000000

__INLINE uint32_t  modem_bf_pack_static_config_get(void)
{
	return REG_PL_RD(MODEM_BF_PACK_STATIC_CONFIG_ADDR);
}

__INLINE void modem_bf_pack_static_config_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_PACK_STATIC_CONFIG_ADDR, value);
}

// field definitions
#define MODEM_BF_PACK_STATIC_CONFIG_ENABLE_MCCI_BIT    ((uint32_t)0x00000002)
#define MODEM_BF_PACK_STATIC_CONFIG_ENABLE_MCCI_POS    1
#define MODEM_BF_PACK_STATIC_CONFIG_SATURATE_SNRS_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_PACK_STATIC_CONFIG_SATURATE_SNRS_POS    0

#define MODEM_BF_PACK_STATIC_CONFIG_ENABLE_MCCI_RST    0x0
#define MODEM_BF_PACK_STATIC_CONFIG_SATURATE_SNRS_RST    0x0

__INLINE void modem_bf_pack_static_config_pack(uint8_t enable_mcci, uint8_t saturate_snrs)
{
	ASSERT_ERR((((uint32_t)enable_mcci << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)saturate_snrs << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_PACK_STATIC_CONFIG_ADDR,  ((uint32_t)enable_mcci << 1) |((uint32_t)saturate_snrs << 0));
}

__INLINE void modem_bf_pack_static_config_unpack(uint8_t* enable_mcci, uint8_t* saturate_snrs)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_STATIC_CONFIG_ADDR);

	*enable_mcci = (localVal & ((uint32_t)0x00000002)) >>  1;
	*saturate_snrs = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_pack_static_config_enable_mcci_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void modem_bf_pack_static_config_enable_mcci_setf(uint8_t enablemcci)
{
	ASSERT_ERR((((uint32_t)enablemcci << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MODEM_BF_PACK_STATIC_CONFIG_ADDR, (REG_PL_RD(MODEM_BF_PACK_STATIC_CONFIG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)enablemcci <<1));
}
__INLINE uint8_t modem_bf_pack_static_config_saturate_snrs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void modem_bf_pack_static_config_saturate_snrs_setf(uint8_t saturatesnrs)
{
	ASSERT_ERR((((uint32_t)saturatesnrs << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_PACK_STATIC_CONFIG_ADDR, (REG_PL_RD(MODEM_BF_PACK_STATIC_CONFIG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)saturatesnrs <<0));
}

/**
 * @brief PACK_ADDR register definition
 *  Pack Acc DSP read and write address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 addr_dst                  0x0
 *    15:00 addr_src                  0x0
 * </pre>
 */
#define MODEM_BF_PACK_ADDR_ADDR        (REG_MODEM_BF_BASE_ADDR+0x0000000C)
#define MODEM_BF_PACK_ADDR_OFFSET      0x0000000C
#define MODEM_BF_PACK_ADDR_INDEX       0x00000003
#define MODEM_BF_PACK_ADDR_RESET       0x00000000

__INLINE uint32_t  modem_bf_pack_addr_get(void)
{
	return REG_PL_RD(MODEM_BF_PACK_ADDR_ADDR);
}

__INLINE void modem_bf_pack_addr_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_PACK_ADDR_ADDR, value);
}

// field definitions
#define MODEM_BF_PACK_ADDR_ADDR_DST_MASK    ((uint32_t)0xFFFF0000)
#define MODEM_BF_PACK_ADDR_ADDR_DST_LSB     16
#define MODEM_BF_PACK_ADDR_ADDR_DST_WIDTH    ((uint32_t)0x00000010)
#define MODEM_BF_PACK_ADDR_ADDR_SRC_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_PACK_ADDR_ADDR_SRC_LSB     0
#define MODEM_BF_PACK_ADDR_ADDR_SRC_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_PACK_ADDR_ADDR_DST_RST     0x0
#define MODEM_BF_PACK_ADDR_ADDR_SRC_RST     0x0

__INLINE void modem_bf_pack_addr_pack(uint16_t addr_dst, uint16_t addr_src)
{
	ASSERT_ERR((((uint32_t)addr_dst << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)addr_src << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_PACK_ADDR_ADDR,  ((uint32_t)addr_dst << 16) |((uint32_t)addr_src << 0));
}

__INLINE void modem_bf_pack_addr_unpack(uint16_t* addr_dst, uint16_t* addr_src)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_ADDR_ADDR);

	*addr_dst = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*addr_src = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t modem_bf_pack_addr_addr_dst_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_ADDR_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void modem_bf_pack_addr_addr_dst_setf(uint16_t addrdst)
{
	ASSERT_ERR((((uint32_t)addrdst << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MODEM_BF_PACK_ADDR_ADDR, (REG_PL_RD(MODEM_BF_PACK_ADDR_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)addrdst <<16));
}
__INLINE uint16_t modem_bf_pack_addr_addr_src_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_ADDR_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void modem_bf_pack_addr_addr_src_setf(uint16_t addrsrc)
{
	ASSERT_ERR((((uint32_t)addrsrc << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_PACK_ADDR_ADDR, (REG_PL_RD(MODEM_BF_PACK_ADDR_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)addrsrc <<0));
}

/**
 * @brief PACK_CONFIG register definition
 *  Pack Acc config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26    disable_cmprs_rpt_byte_pad 0              
 *    25    disable_valid_flag        0              
 *    24    disable_header            0              
 *    20:16 report_type               0x0
 *    15:00 length                    0x0
 * </pre>
 */
#define MODEM_BF_PACK_CONFIG_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000010)
#define MODEM_BF_PACK_CONFIG_OFFSET      0x00000010
#define MODEM_BF_PACK_CONFIG_INDEX       0x00000004
#define MODEM_BF_PACK_CONFIG_RESET       0x00000000

__INLINE uint32_t  modem_bf_pack_config_get(void)
{
	return REG_PL_RD(MODEM_BF_PACK_CONFIG_ADDR);
}

__INLINE void modem_bf_pack_config_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_PACK_CONFIG_ADDR, value);
}

// field definitions
#define MODEM_BF_PACK_CONFIG_DISABLE_CMPRS_RPT_BYTE_PAD_BIT    ((uint32_t)0x04000000)
#define MODEM_BF_PACK_CONFIG_DISABLE_CMPRS_RPT_BYTE_PAD_POS    26
#define MODEM_BF_PACK_CONFIG_DISABLE_VALID_FLAG_BIT    ((uint32_t)0x02000000)
#define MODEM_BF_PACK_CONFIG_DISABLE_VALID_FLAG_POS    25
#define MODEM_BF_PACK_CONFIG_DISABLE_HEADER_BIT    ((uint32_t)0x01000000)
#define MODEM_BF_PACK_CONFIG_DISABLE_HEADER_POS    24
#define MODEM_BF_PACK_CONFIG_REPORT_TYPE_MASK    ((uint32_t)0x001F0000)
#define MODEM_BF_PACK_CONFIG_REPORT_TYPE_LSB    16
#define MODEM_BF_PACK_CONFIG_REPORT_TYPE_WIDTH    ((uint32_t)0x00000005)
#define MODEM_BF_PACK_CONFIG_LENGTH_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_PACK_CONFIG_LENGTH_LSB     0
#define MODEM_BF_PACK_CONFIG_LENGTH_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_PACK_CONFIG_DISABLE_CMPRS_RPT_BYTE_PAD_RST    0x0
#define MODEM_BF_PACK_CONFIG_DISABLE_VALID_FLAG_RST    0x0
#define MODEM_BF_PACK_CONFIG_DISABLE_HEADER_RST    0x0
#define MODEM_BF_PACK_CONFIG_REPORT_TYPE_RST    0x0
#define MODEM_BF_PACK_CONFIG_LENGTH_RST     0x0

__INLINE void modem_bf_pack_config_pack(uint8_t disable_cmprs_rpt_byte_pad, uint8_t disable_valid_flag, uint8_t disable_header, uint8_t report_type, uint16_t length)
{
	ASSERT_ERR((((uint32_t)disable_cmprs_rpt_byte_pad << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)disable_valid_flag << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)disable_header << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)report_type << 16) & ~((uint32_t)0x001F0000)) == 0);
	ASSERT_ERR((((uint32_t)length << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_PACK_CONFIG_ADDR,  ((uint32_t)disable_cmprs_rpt_byte_pad << 26) |((uint32_t)disable_valid_flag << 25) |((uint32_t)disable_header << 24) |((uint32_t)report_type << 16) |((uint32_t)length << 0));
}

__INLINE void modem_bf_pack_config_unpack(uint8_t* disable_cmprs_rpt_byte_pad, uint8_t* disable_valid_flag, uint8_t* disable_header, uint8_t* report_type, uint16_t* length)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_CONFIG_ADDR);

	*disable_cmprs_rpt_byte_pad = (localVal & ((uint32_t)0x04000000)) >>  26;
	*disable_valid_flag = (localVal & ((uint32_t)0x02000000)) >>  25;
	*disable_header = (localVal & ((uint32_t)0x01000000)) >>  24;
	*report_type = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*length = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint8_t modem_bf_pack_config_disable_cmprs_rpt_byte_pad_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void modem_bf_pack_config_disable_cmprs_rpt_byte_pad_setf(uint8_t disablecmprsrptbytepad)
{
	ASSERT_ERR((((uint32_t)disablecmprsrptbytepad << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(MODEM_BF_PACK_CONFIG_ADDR, (REG_PL_RD(MODEM_BF_PACK_CONFIG_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)disablecmprsrptbytepad <<26));
}
__INLINE uint8_t modem_bf_pack_config_disable_valid_flag_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void modem_bf_pack_config_disable_valid_flag_setf(uint8_t disablevalidflag)
{
	ASSERT_ERR((((uint32_t)disablevalidflag << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(MODEM_BF_PACK_CONFIG_ADDR, (REG_PL_RD(MODEM_BF_PACK_CONFIG_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)disablevalidflag <<25));
}
__INLINE uint8_t modem_bf_pack_config_disable_header_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void modem_bf_pack_config_disable_header_setf(uint8_t disableheader)
{
	ASSERT_ERR((((uint32_t)disableheader << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(MODEM_BF_PACK_CONFIG_ADDR, (REG_PL_RD(MODEM_BF_PACK_CONFIG_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)disableheader <<24));
}
__INLINE uint8_t modem_bf_pack_config_report_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE void modem_bf_pack_config_report_type_setf(uint8_t reporttype)
{
	ASSERT_ERR((((uint32_t)reporttype << 16) & ~((uint32_t)0x001F0000)) == 0);
	REG_PL_WR(MODEM_BF_PACK_CONFIG_ADDR, (REG_PL_RD(MODEM_BF_PACK_CONFIG_ADDR) & ~((uint32_t)0x001F0000)) | ((uint32_t)reporttype <<16));
}
__INLINE uint16_t modem_bf_pack_config_length_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_CONFIG_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void modem_bf_pack_config_length_setf(uint16_t length)
{
	ASSERT_ERR((((uint32_t)length << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_PACK_CONFIG_ADDR, (REG_PL_RD(MODEM_BF_PACK_CONFIG_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)length <<0));
}

/**
 * @brief PACK_LENGTH register definition
 *  Pack Acc length  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 length_in_bytes           0x0
 *    06:04 Angles_Length_Type        0x0
 * </pre>
 */
#define MODEM_BF_PACK_LENGTH_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000014)
#define MODEM_BF_PACK_LENGTH_OFFSET      0x00000014
#define MODEM_BF_PACK_LENGTH_INDEX       0x00000005
#define MODEM_BF_PACK_LENGTH_RESET       0x00000000

__INLINE uint32_t  modem_bf_pack_length_get(void)
{
	return REG_PL_RD(MODEM_BF_PACK_LENGTH_ADDR);
}

__INLINE void modem_bf_pack_length_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_PACK_LENGTH_ADDR, value);
}

// field definitions
#define MODEM_BF_PACK_LENGTH_LENGTH_IN_BYTES_MASK    ((uint32_t)0xFFFF0000)
#define MODEM_BF_PACK_LENGTH_LENGTH_IN_BYTES_LSB    16
#define MODEM_BF_PACK_LENGTH_LENGTH_IN_BYTES_WIDTH    ((uint32_t)0x00000010)
#define MODEM_BF_PACK_LENGTH_ANGLES_LENGTH_TYPE_MASK    ((uint32_t)0x00000070)
#define MODEM_BF_PACK_LENGTH_ANGLES_LENGTH_TYPE_LSB    4
#define MODEM_BF_PACK_LENGTH_ANGLES_LENGTH_TYPE_WIDTH    ((uint32_t)0x00000003)

#define MODEM_BF_PACK_LENGTH_LENGTH_IN_BYTES_RST    0x0
#define MODEM_BF_PACK_LENGTH_ANGLES_LENGTH_TYPE_RST    0x0

__INLINE void modem_bf_pack_length_pack(uint16_t length_in_bytes, uint8_t angles_length_type)
{
	ASSERT_ERR((((uint32_t)length_in_bytes << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)angles_length_type << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(MODEM_BF_PACK_LENGTH_ADDR,  ((uint32_t)length_in_bytes << 16) |((uint32_t)angles_length_type << 4));
}

__INLINE void modem_bf_pack_length_unpack(uint16_t* length_in_bytes, uint8_t* angles_length_type)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_LENGTH_ADDR);

	*length_in_bytes = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*angles_length_type = (localVal & ((uint32_t)0x00000070)) >>  4;
}

__INLINE uint16_t modem_bf_pack_length_length_in_bytes_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_LENGTH_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void modem_bf_pack_length_length_in_bytes_setf(uint16_t lengthinbytes)
{
	ASSERT_ERR((((uint32_t)lengthinbytes << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MODEM_BF_PACK_LENGTH_ADDR, (REG_PL_RD(MODEM_BF_PACK_LENGTH_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)lengthinbytes <<16));
}
__INLINE uint8_t modem_bf_pack_length_angles_length_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_LENGTH_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void modem_bf_pack_length_angles_length_type_setf(uint8_t angleslengthtype)
{
	ASSERT_ERR((((uint32_t)angleslengthtype << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(MODEM_BF_PACK_LENGTH_ADDR, (REG_PL_RD(MODEM_BF_PACK_LENGTH_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)angleslengthtype <<4));
}

/**
 * @brief PACK_MU_CONFIG_1 register definition
 *  Mu Pack Acc config 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:20 NSC_angles2               0x0
 *    18    srst                      0              
 *    17    cqi_flag                  0              
 *    16    mu_flag                   0              
 *    15:00 length_snrs               0x0
 * </pre>
 */
#define MODEM_BF_PACK_MU_CONFIG_1_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000018)
#define MODEM_BF_PACK_MU_CONFIG_1_OFFSET      0x00000018
#define MODEM_BF_PACK_MU_CONFIG_1_INDEX       0x00000006
#define MODEM_BF_PACK_MU_CONFIG_1_RESET       0x00000000

__INLINE uint32_t  modem_bf_pack_mu_config_1_get(void)
{
	return REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_1_ADDR);
}

__INLINE void modem_bf_pack_mu_config_1_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_PACK_MU_CONFIG_1_ADDR, value);
}

// field definitions
#define MODEM_BF_PACK_MU_CONFIG_1_NSC_ANGLES_2_MASK    ((uint32_t)0x1FF00000)
#define MODEM_BF_PACK_MU_CONFIG_1_NSC_ANGLES_2_LSB    20
#define MODEM_BF_PACK_MU_CONFIG_1_NSC_ANGLES_2_WIDTH    ((uint32_t)0x00000009)
#define MODEM_BF_PACK_MU_CONFIG_1_SRST_BIT    ((uint32_t)0x00040000)
#define MODEM_BF_PACK_MU_CONFIG_1_SRST_POS    18
#define MODEM_BF_PACK_MU_CONFIG_1_CQI_FLAG_BIT    ((uint32_t)0x00020000)
#define MODEM_BF_PACK_MU_CONFIG_1_CQI_FLAG_POS    17
#define MODEM_BF_PACK_MU_CONFIG_1_MU_FLAG_BIT    ((uint32_t)0x00010000)
#define MODEM_BF_PACK_MU_CONFIG_1_MU_FLAG_POS    16
#define MODEM_BF_PACK_MU_CONFIG_1_LENGTH_SNRS_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_PACK_MU_CONFIG_1_LENGTH_SNRS_LSB    0
#define MODEM_BF_PACK_MU_CONFIG_1_LENGTH_SNRS_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_PACK_MU_CONFIG_1_NSC_ANGLES_2_RST    0x0
#define MODEM_BF_PACK_MU_CONFIG_1_SRST_RST    0x0
#define MODEM_BF_PACK_MU_CONFIG_1_CQI_FLAG_RST    0x0
#define MODEM_BF_PACK_MU_CONFIG_1_MU_FLAG_RST    0x0
#define MODEM_BF_PACK_MU_CONFIG_1_LENGTH_SNRS_RST    0x0

__INLINE void modem_bf_pack_mu_config_1_pack(uint16_t nsc_angles2, uint8_t srst, uint8_t cqi_flag, uint8_t mu_flag, uint16_t length_snrs)
{
	ASSERT_ERR((((uint32_t)nsc_angles2 << 20) & ~((uint32_t)0x1FF00000)) == 0);
	ASSERT_ERR((((uint32_t)srst << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)cqi_flag << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)mu_flag << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)length_snrs << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_PACK_MU_CONFIG_1_ADDR,  ((uint32_t)nsc_angles2 << 20) |((uint32_t)srst << 18) |((uint32_t)cqi_flag << 17) |((uint32_t)mu_flag << 16) |((uint32_t)length_snrs << 0));
}

__INLINE void modem_bf_pack_mu_config_1_unpack(uint16_t* nsc_angles2, uint8_t* srst, uint8_t* cqi_flag, uint8_t* mu_flag, uint16_t* length_snrs)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_1_ADDR);

	*nsc_angles2 = (localVal & ((uint32_t)0x1FF00000)) >>  20;
	*srst = (localVal & ((uint32_t)0x00040000)) >>  18;
	*cqi_flag = (localVal & ((uint32_t)0x00020000)) >>  17;
	*mu_flag = (localVal & ((uint32_t)0x00010000)) >>  16;
	*length_snrs = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t modem_bf_pack_mu_config_1_nsc_angles_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x1FF00000)) >> 20);
}
__INLINE void modem_bf_pack_mu_config_1_nsc_angles_2_setf(uint16_t nscangles2)
{
	ASSERT_ERR((((uint32_t)nscangles2 << 20) & ~((uint32_t)0x1FF00000)) == 0);
	REG_PL_WR(MODEM_BF_PACK_MU_CONFIG_1_ADDR, (REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_1_ADDR) & ~((uint32_t)0x1FF00000)) | ((uint32_t)nscangles2 <<20));
}
__INLINE uint8_t modem_bf_pack_mu_config_1_srst_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void modem_bf_pack_mu_config_1_srst_setf(uint8_t srst)
{
	ASSERT_ERR((((uint32_t)srst << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(MODEM_BF_PACK_MU_CONFIG_1_ADDR, (REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_1_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)srst <<18));
}
__INLINE uint8_t modem_bf_pack_mu_config_1_cqi_flag_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void modem_bf_pack_mu_config_1_cqi_flag_setf(uint8_t cqiflag)
{
	ASSERT_ERR((((uint32_t)cqiflag << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(MODEM_BF_PACK_MU_CONFIG_1_ADDR, (REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_1_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)cqiflag <<17));
}
__INLINE uint8_t modem_bf_pack_mu_config_1_mu_flag_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void modem_bf_pack_mu_config_1_mu_flag_setf(uint8_t muflag)
{
	ASSERT_ERR((((uint32_t)muflag << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(MODEM_BF_PACK_MU_CONFIG_1_ADDR, (REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_1_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)muflag <<16));
}
__INLINE uint16_t modem_bf_pack_mu_config_1_length_snrs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void modem_bf_pack_mu_config_1_length_snrs_setf(uint16_t lengthsnrs)
{
	ASSERT_ERR((((uint32_t)lengthsnrs << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_PACK_MU_CONFIG_1_ADDR, (REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_1_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)lengthsnrs <<0));
}

/**
 * @brief PACK_MU_CONFIG_2 register definition
 *  Mu Pack Acc config 2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    valid_snrs_addr           0              
 *    15:00 addr_src_snrs             0x0
 * </pre>
 */
#define MODEM_BF_PACK_MU_CONFIG_2_ADDR        (REG_MODEM_BF_BASE_ADDR+0x0000001C)
#define MODEM_BF_PACK_MU_CONFIG_2_OFFSET      0x0000001C
#define MODEM_BF_PACK_MU_CONFIG_2_INDEX       0x00000007
#define MODEM_BF_PACK_MU_CONFIG_2_RESET       0x00000000

__INLINE uint32_t  modem_bf_pack_mu_config_2_get(void)
{
	return REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_2_ADDR);
}

__INLINE void modem_bf_pack_mu_config_2_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_PACK_MU_CONFIG_2_ADDR, value);
}

// field definitions
#define MODEM_BF_PACK_MU_CONFIG_2_VALID_SNRS_ADDR_BIT    ((uint32_t)0x00010000)
#define MODEM_BF_PACK_MU_CONFIG_2_VALID_SNRS_ADDR_POS    16
#define MODEM_BF_PACK_MU_CONFIG_2_ADDR_SRC_SNRS_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_PACK_MU_CONFIG_2_ADDR_SRC_SNRS_LSB    0
#define MODEM_BF_PACK_MU_CONFIG_2_ADDR_SRC_SNRS_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_PACK_MU_CONFIG_2_VALID_SNRS_ADDR_RST    0x0
#define MODEM_BF_PACK_MU_CONFIG_2_ADDR_SRC_SNRS_RST    0x0

__INLINE void modem_bf_pack_mu_config_2_pack(uint8_t valid_snrs_addr, uint16_t addr_src_snrs)
{
	ASSERT_ERR((((uint32_t)valid_snrs_addr << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)addr_src_snrs << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_PACK_MU_CONFIG_2_ADDR,  ((uint32_t)valid_snrs_addr << 16) |((uint32_t)addr_src_snrs << 0));
}

__INLINE void modem_bf_pack_mu_config_2_unpack(uint8_t* valid_snrs_addr, uint16_t* addr_src_snrs)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_2_ADDR);

	*valid_snrs_addr = (localVal & ((uint32_t)0x00010000)) >>  16;
	*addr_src_snrs = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint8_t modem_bf_pack_mu_config_2_valid_snrs_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void modem_bf_pack_mu_config_2_valid_snrs_addr_setf(uint8_t validsnrsaddr)
{
	ASSERT_ERR((((uint32_t)validsnrsaddr << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(MODEM_BF_PACK_MU_CONFIG_2_ADDR, (REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_2_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)validsnrsaddr <<16));
}
__INLINE uint16_t modem_bf_pack_mu_config_2_addr_src_snrs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void modem_bf_pack_mu_config_2_addr_src_snrs_setf(uint16_t addrsrcsnrs)
{
	ASSERT_ERR((((uint32_t)addrsrcsnrs << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_PACK_MU_CONFIG_2_ADDR, (REG_PL_RD(MODEM_BF_PACK_MU_CONFIG_2_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)addrsrcsnrs <<0));
}

/**
 * @brief PACK_STATUS register definition
 *  Pack Acc status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    PACK_Paused               0              
 *    01    PACK_Busy                 0              
 *    00    FIC_Busy                  0              
 * </pre>
 */
#define MODEM_BF_PACK_STATUS_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000020)
#define MODEM_BF_PACK_STATUS_OFFSET      0x00000020
#define MODEM_BF_PACK_STATUS_INDEX       0x00000008
#define MODEM_BF_PACK_STATUS_RESET       0x00000000

__INLINE uint32_t  modem_bf_pack_status_get(void)
{
	return REG_PL_RD(MODEM_BF_PACK_STATUS_ADDR);
}

// field definitions
#define MODEM_BF_PACK_STATUS_PACK_PAUSED_BIT    ((uint32_t)0x00000004)
#define MODEM_BF_PACK_STATUS_PACK_PAUSED_POS    2
#define MODEM_BF_PACK_STATUS_PACK_BUSY_BIT    ((uint32_t)0x00000002)
#define MODEM_BF_PACK_STATUS_PACK_BUSY_POS    1
#define MODEM_BF_PACK_STATUS_FIC_BUSY_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_PACK_STATUS_FIC_BUSY_POS    0

#define MODEM_BF_PACK_STATUS_PACK_PAUSED_RST    0x0
#define MODEM_BF_PACK_STATUS_PACK_BUSY_RST    0x0
#define MODEM_BF_PACK_STATUS_FIC_BUSY_RST    0x0

__INLINE void modem_bf_pack_status_unpack(uint8_t* pack_paused, uint8_t* pack_busy, uint8_t* fic_busy)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_STATUS_ADDR);

	*pack_paused = (localVal & ((uint32_t)0x00000004)) >>  2;
	*pack_busy = (localVal & ((uint32_t)0x00000002)) >>  1;
	*fic_busy = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_pack_status_pack_paused_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t modem_bf_pack_status_pack_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t modem_bf_pack_status_fic_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief PACK_MCCI_INTERRUPT register definition
 *  Pack Acc mcci address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 fic_wr_addr_mcci          0x0
 * </pre>
 */
#define MODEM_BF_PACK_MCCI_INTERRUPT_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000024)
#define MODEM_BF_PACK_MCCI_INTERRUPT_OFFSET      0x00000024
#define MODEM_BF_PACK_MCCI_INTERRUPT_INDEX       0x00000009
#define MODEM_BF_PACK_MCCI_INTERRUPT_RESET       0x00000000

__INLINE uint32_t  modem_bf_pack_mcci_interrupt_get(void)
{
	return REG_PL_RD(MODEM_BF_PACK_MCCI_INTERRUPT_ADDR);
}

__INLINE void modem_bf_pack_mcci_interrupt_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_PACK_MCCI_INTERRUPT_ADDR, value);
}

// field definitions
#define MODEM_BF_PACK_MCCI_INTERRUPT_FIC_WR_ADDR_MCCI_MASK    ((uint32_t)0xFFFFFFFF)
#define MODEM_BF_PACK_MCCI_INTERRUPT_FIC_WR_ADDR_MCCI_LSB    0
#define MODEM_BF_PACK_MCCI_INTERRUPT_FIC_WR_ADDR_MCCI_WIDTH    ((uint32_t)0x00000020)

#define MODEM_BF_PACK_MCCI_INTERRUPT_FIC_WR_ADDR_MCCI_RST    0x0

__INLINE uint32_t modem_bf_pack_mcci_interrupt_fic_wr_addr_mcci_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_PACK_MCCI_INTERRUPT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void modem_bf_pack_mcci_interrupt_fic_wr_addr_mcci_setf(uint32_t ficwraddrmcci)
{
	ASSERT_ERR((((uint32_t)ficwraddrmcci << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MODEM_BF_PACK_MCCI_INTERRUPT_ADDR, (uint32_t)ficwraddrmcci << 0);
}

/**
 * @brief DEPACK_SRST register definition
 *  Depacker State Soft Reset register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    state_reset               0              
 * </pre>
 */
#define MODEM_BF_DEPACK_SRST_ADDR        (REG_MODEM_BF_BASE_ADDR+0x0000002C)
#define MODEM_BF_DEPACK_SRST_OFFSET      0x0000002C
#define MODEM_BF_DEPACK_SRST_INDEX       0x0000000B
#define MODEM_BF_DEPACK_SRST_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_srst_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_SRST_ADDR);
}

__INLINE void modem_bf_depack_srst_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_SRST_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_SRST_STATE_RESET_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_DEPACK_SRST_STATE_RESET_POS    0

#define MODEM_BF_DEPACK_SRST_STATE_RESET_RST    0x0

__INLINE uint8_t modem_bf_depack_srst_state_reset_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SRST_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_srst_state_reset_setf(uint8_t statereset)
{
	ASSERT_ERR((((uint32_t)statereset << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_SRST_ADDR, (uint32_t)statereset << 0);
}

/**
 * @brief DEPACK_CONFIG register definition
 *  Depacker configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    disable_he_cmprs_rpt_byte_pad 0              
 *    03    log2_lin_snrs             0              
 *    02    disable_snrs              0              
 *    01    disable_regroup           0              
 *    00    header_sel                0              
 * </pre>
 */
#define MODEM_BF_DEPACK_CONFIG_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000030)
#define MODEM_BF_DEPACK_CONFIG_OFFSET      0x00000030
#define MODEM_BF_DEPACK_CONFIG_INDEX       0x0000000C
#define MODEM_BF_DEPACK_CONFIG_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_config_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_CONFIG_ADDR);
}

__INLINE void modem_bf_depack_config_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_CONFIG_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_CONFIG_DISABLE_HE_CMPRS_RPT_BYTE_PAD_BIT    ((uint32_t)0x00000010)
#define MODEM_BF_DEPACK_CONFIG_DISABLE_HE_CMPRS_RPT_BYTE_PAD_POS    4
#define MODEM_BF_DEPACK_CONFIG_LOG_2_LIN_SNRS_BIT    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_CONFIG_LOG_2_LIN_SNRS_POS    3
#define MODEM_BF_DEPACK_CONFIG_DISABLE_SNRS_BIT    ((uint32_t)0x00000004)
#define MODEM_BF_DEPACK_CONFIG_DISABLE_SNRS_POS    2
#define MODEM_BF_DEPACK_CONFIG_DISABLE_REGROUP_BIT    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_CONFIG_DISABLE_REGROUP_POS    1
#define MODEM_BF_DEPACK_CONFIG_HEADER_SEL_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_DEPACK_CONFIG_HEADER_SEL_POS    0

#define MODEM_BF_DEPACK_CONFIG_DISABLE_HE_CMPRS_RPT_BYTE_PAD_RST    0x0
#define MODEM_BF_DEPACK_CONFIG_LOG_2_LIN_SNRS_RST    0x0
#define MODEM_BF_DEPACK_CONFIG_DISABLE_SNRS_RST    0x0
#define MODEM_BF_DEPACK_CONFIG_DISABLE_REGROUP_RST    0x0
#define MODEM_BF_DEPACK_CONFIG_HEADER_SEL_RST    0x0

__INLINE void modem_bf_depack_config_pack(uint8_t disable_he_cmprs_rpt_byte_pad, uint8_t log2_lin_snrs, uint8_t disable_snrs, uint8_t disable_regroup, uint8_t header_sel)
{
	ASSERT_ERR((((uint32_t)disable_he_cmprs_rpt_byte_pad << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)log2_lin_snrs << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)disable_snrs << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)disable_regroup << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)header_sel << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_CONFIG_ADDR,  ((uint32_t)disable_he_cmprs_rpt_byte_pad << 4) |((uint32_t)log2_lin_snrs << 3) |((uint32_t)disable_snrs << 2) |((uint32_t)disable_regroup << 1) |((uint32_t)header_sel << 0));
}

__INLINE void modem_bf_depack_config_unpack(uint8_t* disable_he_cmprs_rpt_byte_pad, uint8_t* log2_lin_snrs, uint8_t* disable_snrs, uint8_t* disable_regroup, uint8_t* header_sel)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_CONFIG_ADDR);

	*disable_he_cmprs_rpt_byte_pad = (localVal & ((uint32_t)0x00000010)) >>  4;
	*log2_lin_snrs = (localVal & ((uint32_t)0x00000008)) >>  3;
	*disable_snrs = (localVal & ((uint32_t)0x00000004)) >>  2;
	*disable_regroup = (localVal & ((uint32_t)0x00000002)) >>  1;
	*header_sel = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_depack_config_disable_he_cmprs_rpt_byte_pad_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void modem_bf_depack_config_disable_he_cmprs_rpt_byte_pad_setf(uint8_t disablehecmprsrptbytepad)
{
	ASSERT_ERR((((uint32_t)disablehecmprsrptbytepad << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_CONFIG_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_CONFIG_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)disablehecmprsrptbytepad <<4));
}
__INLINE uint8_t modem_bf_depack_config_log_2_lin_snrs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void modem_bf_depack_config_log_2_lin_snrs_setf(uint8_t log2linsnrs)
{
	ASSERT_ERR((((uint32_t)log2linsnrs << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_CONFIG_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_CONFIG_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)log2linsnrs <<3));
}
__INLINE uint8_t modem_bf_depack_config_disable_snrs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void modem_bf_depack_config_disable_snrs_setf(uint8_t disablesnrs)
{
	ASSERT_ERR((((uint32_t)disablesnrs << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_CONFIG_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_CONFIG_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)disablesnrs <<2));
}
__INLINE uint8_t modem_bf_depack_config_disable_regroup_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void modem_bf_depack_config_disable_regroup_setf(uint8_t disableregroup)
{
	ASSERT_ERR((((uint32_t)disableregroup << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_CONFIG_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_CONFIG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)disableregroup <<1));
}
__INLINE uint8_t modem_bf_depack_config_header_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void modem_bf_depack_config_header_sel_setf(uint8_t headersel)
{
	ASSERT_ERR((((uint32_t)headersel << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_CONFIG_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_CONFIG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)headersel <<0));
}

/**
 * @brief DEPACK_DBG_1 register definition
 *  Depacker debug register 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 dbg_RU_end                0x0
 *    22:16 dbg_RU_start              0x0
 *    15    dbg_FT                    0              
 *    14:12 dbg_angle_type            0x0
 *    11:10 dbg_NG_targ               0x0
 *    09:08 dbg_NG_orig               0x0
 *    07:05 dbg_NC_idx                0x0
 *    04:02 dbg_NR_idx                0x0
 *    01:00 dbg_BW_idx                0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DBG_1_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000034)
#define MODEM_BF_DEPACK_DBG_1_OFFSET      0x00000034
#define MODEM_BF_DEPACK_DBG_1_INDEX       0x0000000D
#define MODEM_BF_DEPACK_DBG_1_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dbg_1_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR);
}

__INLINE void modem_bf_depack_dbg_1_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DBG_1_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DBG_1_DBG_RU_END_MASK    ((uint32_t)0x7F000000)
#define MODEM_BF_DEPACK_DBG_1_DBG_RU_END_LSB    24
#define MODEM_BF_DEPACK_DBG_1_DBG_RU_END_WIDTH    ((uint32_t)0x00000007)
#define MODEM_BF_DEPACK_DBG_1_DBG_RU_START_MASK    ((uint32_t)0x007F0000)
#define MODEM_BF_DEPACK_DBG_1_DBG_RU_START_LSB    16
#define MODEM_BF_DEPACK_DBG_1_DBG_RU_START_WIDTH    ((uint32_t)0x00000007)
#define MODEM_BF_DEPACK_DBG_1_DBG_FT_BIT    ((uint32_t)0x00008000)
#define MODEM_BF_DEPACK_DBG_1_DBG_FT_POS    15
#define MODEM_BF_DEPACK_DBG_1_DBG_ANGLE_TYPE_MASK    ((uint32_t)0x00007000)
#define MODEM_BF_DEPACK_DBG_1_DBG_ANGLE_TYPE_LSB    12
#define MODEM_BF_DEPACK_DBG_1_DBG_ANGLE_TYPE_WIDTH    ((uint32_t)0x00000003)
#define MODEM_BF_DEPACK_DBG_1_DBG_NG_TARG_MASK    ((uint32_t)0x00000C00)
#define MODEM_BF_DEPACK_DBG_1_DBG_NG_TARG_LSB    10
#define MODEM_BF_DEPACK_DBG_1_DBG_NG_TARG_WIDTH    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_DBG_1_DBG_NG_ORIG_MASK    ((uint32_t)0x00000300)
#define MODEM_BF_DEPACK_DBG_1_DBG_NG_ORIG_LSB    8
#define MODEM_BF_DEPACK_DBG_1_DBG_NG_ORIG_WIDTH    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_DBG_1_DBG_NC_IDX_MASK    ((uint32_t)0x000000E0)
#define MODEM_BF_DEPACK_DBG_1_DBG_NC_IDX_LSB    5
#define MODEM_BF_DEPACK_DBG_1_DBG_NC_IDX_WIDTH    ((uint32_t)0x00000003)
#define MODEM_BF_DEPACK_DBG_1_DBG_NR_IDX_MASK    ((uint32_t)0x0000001C)
#define MODEM_BF_DEPACK_DBG_1_DBG_NR_IDX_LSB    2
#define MODEM_BF_DEPACK_DBG_1_DBG_NR_IDX_WIDTH    ((uint32_t)0x00000003)
#define MODEM_BF_DEPACK_DBG_1_DBG_BW_IDX_MASK    ((uint32_t)0x00000003)
#define MODEM_BF_DEPACK_DBG_1_DBG_BW_IDX_LSB    0
#define MODEM_BF_DEPACK_DBG_1_DBG_BW_IDX_WIDTH    ((uint32_t)0x00000002)

#define MODEM_BF_DEPACK_DBG_1_DBG_RU_END_RST    0x0
#define MODEM_BF_DEPACK_DBG_1_DBG_RU_START_RST    0x0
#define MODEM_BF_DEPACK_DBG_1_DBG_FT_RST    0x0
#define MODEM_BF_DEPACK_DBG_1_DBG_ANGLE_TYPE_RST    0x0
#define MODEM_BF_DEPACK_DBG_1_DBG_NG_TARG_RST    0x0
#define MODEM_BF_DEPACK_DBG_1_DBG_NG_ORIG_RST    0x0
#define MODEM_BF_DEPACK_DBG_1_DBG_NC_IDX_RST    0x0
#define MODEM_BF_DEPACK_DBG_1_DBG_NR_IDX_RST    0x0
#define MODEM_BF_DEPACK_DBG_1_DBG_BW_IDX_RST    0x0

__INLINE void modem_bf_depack_dbg_1_pack(uint8_t dbg_ru_end, uint8_t dbg_ru_start, uint8_t dbg_ft, uint8_t dbg_angle_type, uint8_t dbg_ng_targ, uint8_t dbg_ng_orig, uint8_t dbg_nc_idx, uint8_t dbg_nr_idx, uint8_t dbg_bw_idx)
{
	ASSERT_ERR((((uint32_t)dbg_ru_end << 24) & ~((uint32_t)0x7F000000)) == 0);
	ASSERT_ERR((((uint32_t)dbg_ru_start << 16) & ~((uint32_t)0x007F0000)) == 0);
	ASSERT_ERR((((uint32_t)dbg_ft << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)dbg_angle_type << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)dbg_ng_targ << 10) & ~((uint32_t)0x00000C00)) == 0);
	ASSERT_ERR((((uint32_t)dbg_ng_orig << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)dbg_nc_idx << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)dbg_nr_idx << 2) & ~((uint32_t)0x0000001C)) == 0);
	ASSERT_ERR((((uint32_t)dbg_bw_idx << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_1_ADDR,  ((uint32_t)dbg_ru_end << 24) |((uint32_t)dbg_ru_start << 16) |((uint32_t)dbg_ft << 15) |((uint32_t)dbg_angle_type << 12) |((uint32_t)dbg_ng_targ << 10) |((uint32_t)dbg_ng_orig << 8) |((uint32_t)dbg_nc_idx << 5) |((uint32_t)dbg_nr_idx << 2) |((uint32_t)dbg_bw_idx << 0));
}

__INLINE void modem_bf_depack_dbg_1_unpack(uint8_t* dbg_ru_end, uint8_t* dbg_ru_start, uint8_t* dbg_ft, uint8_t* dbg_angle_type, uint8_t* dbg_ng_targ, uint8_t* dbg_ng_orig, uint8_t* dbg_nc_idx, uint8_t* dbg_nr_idx, uint8_t* dbg_bw_idx)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR);

	*dbg_ru_end = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*dbg_ru_start = (localVal & ((uint32_t)0x007F0000)) >>  16;
	*dbg_ft = (localVal & ((uint32_t)0x00008000)) >>  15;
	*dbg_angle_type = (localVal & ((uint32_t)0x00007000)) >>  12;
	*dbg_ng_targ = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*dbg_ng_orig = (localVal & ((uint32_t)0x00000300)) >>  8;
	*dbg_nc_idx = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*dbg_nr_idx = (localVal & ((uint32_t)0x0000001C)) >>  2;
	*dbg_bw_idx = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t modem_bf_depack_dbg_1_dbg_ru_end_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE void modem_bf_depack_dbg_1_dbg_ru_end_setf(uint8_t dbgruend)
{
	ASSERT_ERR((((uint32_t)dbgruend << 24) & ~((uint32_t)0x7F000000)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_1_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)dbgruend <<24));
}
__INLINE uint8_t modem_bf_depack_dbg_1_dbg_ru_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x007F0000)) >> 16);
}
__INLINE void modem_bf_depack_dbg_1_dbg_ru_start_setf(uint8_t dbgrustart)
{
	ASSERT_ERR((((uint32_t)dbgrustart << 16) & ~((uint32_t)0x007F0000)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_1_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)dbgrustart <<16));
}
__INLINE uint8_t modem_bf_depack_dbg_1_dbg_ft_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void modem_bf_depack_dbg_1_dbg_ft_setf(uint8_t dbgft)
{
	ASSERT_ERR((((uint32_t)dbgft << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_1_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)dbgft <<15));
}
__INLINE uint8_t modem_bf_depack_dbg_1_dbg_angle_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void modem_bf_depack_dbg_1_dbg_angle_type_setf(uint8_t dbgangletype)
{
	ASSERT_ERR((((uint32_t)dbgangletype << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_1_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)dbgangletype <<12));
}
__INLINE uint8_t modem_bf_depack_dbg_1_dbg_ng_targ_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE void modem_bf_depack_dbg_1_dbg_ng_targ_setf(uint8_t dbgngtarg)
{
	ASSERT_ERR((((uint32_t)dbgngtarg << 10) & ~((uint32_t)0x00000C00)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_1_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)dbgngtarg <<10));
}
__INLINE uint8_t modem_bf_depack_dbg_1_dbg_ng_orig_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void modem_bf_depack_dbg_1_dbg_ng_orig_setf(uint8_t dbgngorig)
{
	ASSERT_ERR((((uint32_t)dbgngorig << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_1_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)dbgngorig <<8));
}
__INLINE uint8_t modem_bf_depack_dbg_1_dbg_nc_idx_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void modem_bf_depack_dbg_1_dbg_nc_idx_setf(uint8_t dbgncidx)
{
	ASSERT_ERR((((uint32_t)dbgncidx << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_1_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)dbgncidx <<5));
}
__INLINE uint8_t modem_bf_depack_dbg_1_dbg_nr_idx_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001C)) >> 2);
}
__INLINE void modem_bf_depack_dbg_1_dbg_nr_idx_setf(uint8_t dbgnridx)
{
	ASSERT_ERR((((uint32_t)dbgnridx << 2) & ~((uint32_t)0x0000001C)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_1_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR) & ~((uint32_t)0x0000001C)) | ((uint32_t)dbgnridx <<2));
}
__INLINE uint8_t modem_bf_depack_dbg_1_dbg_bw_idx_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void modem_bf_depack_dbg_1_dbg_bw_idx_setf(uint8_t dbgbwidx)
{
	ASSERT_ERR((((uint32_t)dbgbwidx << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_1_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_1_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)dbgbwidx <<0));
}

/**
 * @brief DEPACK_DBG_2 register definition
 *  Depacker debug register 2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:20 dbg_NSC_DSNR              0x0
 *    16:08 dbg_NSC_angles            0x0
 *    07:02 dbg_padding               0x0
 *    01:00 dbg_format                0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DBG_2_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000038)
#define MODEM_BF_DEPACK_DBG_2_OFFSET      0x00000038
#define MODEM_BF_DEPACK_DBG_2_INDEX       0x0000000E
#define MODEM_BF_DEPACK_DBG_2_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dbg_2_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DBG_2_ADDR);
}

__INLINE void modem_bf_depack_dbg_2_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DBG_2_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DBG_2_DBG_NSC_DSNR_MASK    ((uint32_t)0x1FF00000)
#define MODEM_BF_DEPACK_DBG_2_DBG_NSC_DSNR_LSB    20
#define MODEM_BF_DEPACK_DBG_2_DBG_NSC_DSNR_WIDTH    ((uint32_t)0x00000009)
#define MODEM_BF_DEPACK_DBG_2_DBG_NSC_ANGLES_MASK    ((uint32_t)0x0001FF00)
#define MODEM_BF_DEPACK_DBG_2_DBG_NSC_ANGLES_LSB    8
#define MODEM_BF_DEPACK_DBG_2_DBG_NSC_ANGLES_WIDTH    ((uint32_t)0x00000009)
#define MODEM_BF_DEPACK_DBG_2_DBG_PADDING_MASK    ((uint32_t)0x000000FC)
#define MODEM_BF_DEPACK_DBG_2_DBG_PADDING_LSB    2
#define MODEM_BF_DEPACK_DBG_2_DBG_PADDING_WIDTH    ((uint32_t)0x00000006)
#define MODEM_BF_DEPACK_DBG_2_DBG_FORMAT_MASK    ((uint32_t)0x00000003)
#define MODEM_BF_DEPACK_DBG_2_DBG_FORMAT_LSB    0
#define MODEM_BF_DEPACK_DBG_2_DBG_FORMAT_WIDTH    ((uint32_t)0x00000002)

#define MODEM_BF_DEPACK_DBG_2_DBG_NSC_DSNR_RST    0x0
#define MODEM_BF_DEPACK_DBG_2_DBG_NSC_ANGLES_RST    0x0
#define MODEM_BF_DEPACK_DBG_2_DBG_PADDING_RST    0x0
#define MODEM_BF_DEPACK_DBG_2_DBG_FORMAT_RST    0x0

__INLINE void modem_bf_depack_dbg_2_pack(uint16_t dbg_nsc_dsnr, uint16_t dbg_nsc_angles, uint8_t dbg_padding, uint8_t dbg_format)
{
	ASSERT_ERR((((uint32_t)dbg_nsc_dsnr << 20) & ~((uint32_t)0x1FF00000)) == 0);
	ASSERT_ERR((((uint32_t)dbg_nsc_angles << 8) & ~((uint32_t)0x0001FF00)) == 0);
	ASSERT_ERR((((uint32_t)dbg_padding << 2) & ~((uint32_t)0x000000FC)) == 0);
	ASSERT_ERR((((uint32_t)dbg_format << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_2_ADDR,  ((uint32_t)dbg_nsc_dsnr << 20) |((uint32_t)dbg_nsc_angles << 8) |((uint32_t)dbg_padding << 2) |((uint32_t)dbg_format << 0));
}

__INLINE void modem_bf_depack_dbg_2_unpack(uint16_t* dbg_nsc_dsnr, uint16_t* dbg_nsc_angles, uint8_t* dbg_padding, uint8_t* dbg_format)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_2_ADDR);

	*dbg_nsc_dsnr = (localVal & ((uint32_t)0x1FF00000)) >>  20;
	*dbg_nsc_angles = (localVal & ((uint32_t)0x0001FF00)) >>  8;
	*dbg_padding = (localVal & ((uint32_t)0x000000FC)) >>  2;
	*dbg_format = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t modem_bf_depack_dbg_2_dbg_nsc_dsnr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x1FF00000)) >> 20);
}
__INLINE void modem_bf_depack_dbg_2_dbg_nsc_dsnr_setf(uint16_t dbgnscdsnr)
{
	ASSERT_ERR((((uint32_t)dbgnscdsnr << 20) & ~((uint32_t)0x1FF00000)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_2_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_2_ADDR) & ~((uint32_t)0x1FF00000)) | ((uint32_t)dbgnscdsnr <<20));
}
__INLINE uint16_t modem_bf_depack_dbg_2_dbg_nsc_angles_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0001FF00)) >> 8);
}
__INLINE void modem_bf_depack_dbg_2_dbg_nsc_angles_setf(uint16_t dbgnscangles)
{
	ASSERT_ERR((((uint32_t)dbgnscangles << 8) & ~((uint32_t)0x0001FF00)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_2_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_2_ADDR) & ~((uint32_t)0x0001FF00)) | ((uint32_t)dbgnscangles <<8));
}
__INLINE uint8_t modem_bf_depack_dbg_2_dbg_padding_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FC)) >> 2);
}
__INLINE void modem_bf_depack_dbg_2_dbg_padding_setf(uint8_t dbgpadding)
{
	ASSERT_ERR((((uint32_t)dbgpadding << 2) & ~((uint32_t)0x000000FC)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_2_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_2_ADDR) & ~((uint32_t)0x000000FC)) | ((uint32_t)dbgpadding <<2));
}
__INLINE uint8_t modem_bf_depack_dbg_2_dbg_format_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DBG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void modem_bf_depack_dbg_2_dbg_format_setf(uint8_t dbgformat)
{
	ASSERT_ERR((((uint32_t)dbgformat << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DBG_2_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DBG_2_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)dbgformat <<0));
}

/**
 * @brief DEPACK_STATUS register definition
 *  Depacker arming and progress report register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25    depack_paused             0              
 *    24:16 NSC                       0x0
 *    12    angles_or_dsnr            0              
 *    10:08 active_config             0x0
 *    07:00 armed                     0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_STATUS_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000040)
#define MODEM_BF_DEPACK_STATUS_OFFSET      0x00000040
#define MODEM_BF_DEPACK_STATUS_INDEX       0x00000010
#define MODEM_BF_DEPACK_STATUS_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_status_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_STATUS_ADDR);
}

// field definitions
#define MODEM_BF_DEPACK_STATUS_DEPACK_PAUSED_BIT    ((uint32_t)0x02000000)
#define MODEM_BF_DEPACK_STATUS_DEPACK_PAUSED_POS    25
#define MODEM_BF_DEPACK_STATUS_NSC_MASK     ((uint32_t)0x01FF0000)
#define MODEM_BF_DEPACK_STATUS_NSC_LSB      16
#define MODEM_BF_DEPACK_STATUS_NSC_WIDTH    ((uint32_t)0x00000009)
#define MODEM_BF_DEPACK_STATUS_ANGLES_OR_DSNR_BIT    ((uint32_t)0x00001000)
#define MODEM_BF_DEPACK_STATUS_ANGLES_OR_DSNR_POS    12
#define MODEM_BF_DEPACK_STATUS_ACTIVE_CONFIG_MASK    ((uint32_t)0x00000700)
#define MODEM_BF_DEPACK_STATUS_ACTIVE_CONFIG_LSB    8
#define MODEM_BF_DEPACK_STATUS_ACTIVE_CONFIG_WIDTH    ((uint32_t)0x00000003)
#define MODEM_BF_DEPACK_STATUS_ARMED_MASK    ((uint32_t)0x000000FF)
#define MODEM_BF_DEPACK_STATUS_ARMED_LSB    0
#define MODEM_BF_DEPACK_STATUS_ARMED_WIDTH    ((uint32_t)0x00000008)

#define MODEM_BF_DEPACK_STATUS_DEPACK_PAUSED_RST    0x0
#define MODEM_BF_DEPACK_STATUS_NSC_RST      0x0
#define MODEM_BF_DEPACK_STATUS_ANGLES_OR_DSNR_RST    0x0
#define MODEM_BF_DEPACK_STATUS_ACTIVE_CONFIG_RST    0x0
#define MODEM_BF_DEPACK_STATUS_ARMED_RST    0x0

__INLINE void modem_bf_depack_status_unpack(uint8_t* depack_paused, uint16_t* nsc, uint8_t* angles_or_dsnr, uint8_t* active_config, uint8_t* armed)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_STATUS_ADDR);

	*depack_paused = (localVal & ((uint32_t)0x02000000)) >>  25;
	*nsc = (localVal & ((uint32_t)0x01FF0000)) >>  16;
	*angles_or_dsnr = (localVal & ((uint32_t)0x00001000)) >>  12;
	*active_config = (localVal & ((uint32_t)0x00000700)) >>  8;
	*armed = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t modem_bf_depack_status_depack_paused_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE uint16_t modem_bf_depack_status_nsc_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_STATUS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x01FF0000)) >> 16);
}
__INLINE uint8_t modem_bf_depack_status_angles_or_dsnr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t modem_bf_depack_status_active_config_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE uint8_t modem_bf_depack_status_armed_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief DEPACK_HDR_1 register definition
 *  Depacker extracted header information register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:25 RU_end                    0x0
 *    22:16 RU_start                  0x0
 *    15    FT                        0              
 *    14:12 angle_type                0x0
 *    11:10 NG_targ                   0x0
 *    09:08 NG_orig                   0x0
 *    07:05 NC_idx                    0x0
 *    04:02 NR_idx                    0x0
 *    01:00 BW_idx                    0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_HDR_1_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000044)
#define MODEM_BF_DEPACK_HDR_1_OFFSET      0x00000044
#define MODEM_BF_DEPACK_HDR_1_INDEX       0x00000011
#define MODEM_BF_DEPACK_HDR_1_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_hdr_1_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_HDR_1_ADDR);
}

// field definitions
#define MODEM_BF_DEPACK_HDR_1_RU_END_MASK    ((uint32_t)0xFE000000)
#define MODEM_BF_DEPACK_HDR_1_RU_END_LSB    25
#define MODEM_BF_DEPACK_HDR_1_RU_END_WIDTH    ((uint32_t)0x00000007)
#define MODEM_BF_DEPACK_HDR_1_RU_START_MASK    ((uint32_t)0x007F0000)
#define MODEM_BF_DEPACK_HDR_1_RU_START_LSB    16
#define MODEM_BF_DEPACK_HDR_1_RU_START_WIDTH    ((uint32_t)0x00000007)
#define MODEM_BF_DEPACK_HDR_1_FT_BIT        ((uint32_t)0x00008000)
#define MODEM_BF_DEPACK_HDR_1_FT_POS        15
#define MODEM_BF_DEPACK_HDR_1_ANGLE_TYPE_MASK    ((uint32_t)0x00007000)
#define MODEM_BF_DEPACK_HDR_1_ANGLE_TYPE_LSB    12
#define MODEM_BF_DEPACK_HDR_1_ANGLE_TYPE_WIDTH    ((uint32_t)0x00000003)
#define MODEM_BF_DEPACK_HDR_1_NG_TARG_MASK    ((uint32_t)0x00000C00)
#define MODEM_BF_DEPACK_HDR_1_NG_TARG_LSB    10
#define MODEM_BF_DEPACK_HDR_1_NG_TARG_WIDTH    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_HDR_1_NG_ORIG_MASK    ((uint32_t)0x00000300)
#define MODEM_BF_DEPACK_HDR_1_NG_ORIG_LSB    8
#define MODEM_BF_DEPACK_HDR_1_NG_ORIG_WIDTH    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_HDR_1_NC_IDX_MASK    ((uint32_t)0x000000E0)
#define MODEM_BF_DEPACK_HDR_1_NC_IDX_LSB    5
#define MODEM_BF_DEPACK_HDR_1_NC_IDX_WIDTH    ((uint32_t)0x00000003)
#define MODEM_BF_DEPACK_HDR_1_NR_IDX_MASK    ((uint32_t)0x0000001C)
#define MODEM_BF_DEPACK_HDR_1_NR_IDX_LSB    2
#define MODEM_BF_DEPACK_HDR_1_NR_IDX_WIDTH    ((uint32_t)0x00000003)
#define MODEM_BF_DEPACK_HDR_1_BW_IDX_MASK    ((uint32_t)0x00000003)
#define MODEM_BF_DEPACK_HDR_1_BW_IDX_LSB    0
#define MODEM_BF_DEPACK_HDR_1_BW_IDX_WIDTH    ((uint32_t)0x00000002)

#define MODEM_BF_DEPACK_HDR_1_RU_END_RST    0x0
#define MODEM_BF_DEPACK_HDR_1_RU_START_RST    0x0
#define MODEM_BF_DEPACK_HDR_1_FT_RST        0x0
#define MODEM_BF_DEPACK_HDR_1_ANGLE_TYPE_RST    0x0
#define MODEM_BF_DEPACK_HDR_1_NG_TARG_RST    0x0
#define MODEM_BF_DEPACK_HDR_1_NG_ORIG_RST    0x0
#define MODEM_BF_DEPACK_HDR_1_NC_IDX_RST    0x0
#define MODEM_BF_DEPACK_HDR_1_NR_IDX_RST    0x0
#define MODEM_BF_DEPACK_HDR_1_BW_IDX_RST    0x0

__INLINE void modem_bf_depack_hdr_1_unpack(uint8_t* ru_end, uint8_t* ru_start, uint8_t* ft, uint8_t* angle_type, uint8_t* ng_targ, uint8_t* ng_orig, uint8_t* nc_idx, uint8_t* nr_idx, uint8_t* bw_idx)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_1_ADDR);

	*ru_end = (localVal & ((uint32_t)0xFE000000)) >>  25;
	*ru_start = (localVal & ((uint32_t)0x007F0000)) >>  16;
	*ft = (localVal & ((uint32_t)0x00008000)) >>  15;
	*angle_type = (localVal & ((uint32_t)0x00007000)) >>  12;
	*ng_targ = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*ng_orig = (localVal & ((uint32_t)0x00000300)) >>  8;
	*nc_idx = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*nr_idx = (localVal & ((uint32_t)0x0000001C)) >>  2;
	*bw_idx = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t modem_bf_depack_hdr_1_ru_end_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFE000000)) >> 25);
}
__INLINE uint8_t modem_bf_depack_hdr_1_ru_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x007F0000)) >> 16);
}
__INLINE uint8_t modem_bf_depack_hdr_1_ft_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t modem_bf_depack_hdr_1_angle_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE uint8_t modem_bf_depack_hdr_1_ng_targ_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE uint8_t modem_bf_depack_hdr_1_ng_orig_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE uint8_t modem_bf_depack_hdr_1_nc_idx_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE uint8_t modem_bf_depack_hdr_1_nr_idx_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001C)) >> 2);
}
__INLINE uint8_t modem_bf_depack_hdr_1_bw_idx_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief DEPACK_HDR_2 register definition
 *  Depacker extracted header information register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:20 NSC_DSNR                  0x0
 *    16:08 NSC_angles                0x0
 *    07:02 padding                   0x0
 *    01:00 format                    0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_HDR_2_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000048)
#define MODEM_BF_DEPACK_HDR_2_OFFSET      0x00000048
#define MODEM_BF_DEPACK_HDR_2_INDEX       0x00000012
#define MODEM_BF_DEPACK_HDR_2_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_hdr_2_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_HDR_2_ADDR);
}

// field definitions
#define MODEM_BF_DEPACK_HDR_2_NSC_DSNR_MASK    ((uint32_t)0x1FF00000)
#define MODEM_BF_DEPACK_HDR_2_NSC_DSNR_LSB    20
#define MODEM_BF_DEPACK_HDR_2_NSC_DSNR_WIDTH    ((uint32_t)0x00000009)
#define MODEM_BF_DEPACK_HDR_2_NSC_ANGLES_MASK    ((uint32_t)0x0001FF00)
#define MODEM_BF_DEPACK_HDR_2_NSC_ANGLES_LSB    8
#define MODEM_BF_DEPACK_HDR_2_NSC_ANGLES_WIDTH    ((uint32_t)0x00000009)
#define MODEM_BF_DEPACK_HDR_2_PADDING_MASK    ((uint32_t)0x000000FC)
#define MODEM_BF_DEPACK_HDR_2_PADDING_LSB    2
#define MODEM_BF_DEPACK_HDR_2_PADDING_WIDTH    ((uint32_t)0x00000006)
#define MODEM_BF_DEPACK_HDR_2_FORMAT_MASK    ((uint32_t)0x00000003)
#define MODEM_BF_DEPACK_HDR_2_FORMAT_LSB    0
#define MODEM_BF_DEPACK_HDR_2_FORMAT_WIDTH    ((uint32_t)0x00000002)

#define MODEM_BF_DEPACK_HDR_2_NSC_DSNR_RST    0x0
#define MODEM_BF_DEPACK_HDR_2_NSC_ANGLES_RST    0x0
#define MODEM_BF_DEPACK_HDR_2_PADDING_RST    0x0
#define MODEM_BF_DEPACK_HDR_2_FORMAT_RST    0x0

__INLINE void modem_bf_depack_hdr_2_unpack(uint16_t* nsc_dsnr, uint16_t* nsc_angles, uint8_t* padding, uint8_t* format)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_2_ADDR);

	*nsc_dsnr = (localVal & ((uint32_t)0x1FF00000)) >>  20;
	*nsc_angles = (localVal & ((uint32_t)0x0001FF00)) >>  8;
	*padding = (localVal & ((uint32_t)0x000000FC)) >>  2;
	*format = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t modem_bf_depack_hdr_2_nsc_dsnr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x1FF00000)) >> 20);
}
__INLINE uint16_t modem_bf_depack_hdr_2_nsc_angles_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0001FF00)) >> 8);
}
__INLINE uint8_t modem_bf_depack_hdr_2_padding_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FC)) >> 2);
}
__INLINE uint8_t modem_bf_depack_hdr_2_format_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief DEPACK_SNR_1 register definition
 *  Depacker Av SNR 0 to 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 SNR3                      0x0
 *    23:16 SNR2                      0x0
 *    15:08 SNR1                      0x0
 *    07:00 SNR0                      0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_SNR_1_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000050)
#define MODEM_BF_DEPACK_SNR_1_OFFSET      0x00000050
#define MODEM_BF_DEPACK_SNR_1_INDEX       0x00000014
#define MODEM_BF_DEPACK_SNR_1_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_snr_1_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_SNR_1_ADDR);
}

// field definitions
#define MODEM_BF_DEPACK_SNR_1_SNR_3_MASK    ((uint32_t)0xFF000000)
#define MODEM_BF_DEPACK_SNR_1_SNR_3_LSB     24
#define MODEM_BF_DEPACK_SNR_1_SNR_3_WIDTH    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_SNR_1_SNR_2_MASK    ((uint32_t)0x00FF0000)
#define MODEM_BF_DEPACK_SNR_1_SNR_2_LSB     16
#define MODEM_BF_DEPACK_SNR_1_SNR_2_WIDTH    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_SNR_1_SNR_1_MASK    ((uint32_t)0x0000FF00)
#define MODEM_BF_DEPACK_SNR_1_SNR_1_LSB     8
#define MODEM_BF_DEPACK_SNR_1_SNR_1_WIDTH    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_SNR_1_SNR_0_MASK    ((uint32_t)0x000000FF)
#define MODEM_BF_DEPACK_SNR_1_SNR_0_LSB     0
#define MODEM_BF_DEPACK_SNR_1_SNR_0_WIDTH    ((uint32_t)0x00000008)

#define MODEM_BF_DEPACK_SNR_1_SNR_3_RST     0x0
#define MODEM_BF_DEPACK_SNR_1_SNR_2_RST     0x0
#define MODEM_BF_DEPACK_SNR_1_SNR_1_RST     0x0
#define MODEM_BF_DEPACK_SNR_1_SNR_0_RST     0x0

__INLINE void modem_bf_depack_snr_1_unpack(uint8_t* snr3, uint8_t* snr2, uint8_t* snr1, uint8_t* snr0)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SNR_1_ADDR);

	*snr3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*snr2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*snr1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*snr0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t modem_bf_depack_snr_1_snr_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SNR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint8_t modem_bf_depack_snr_1_snr_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SNR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t modem_bf_depack_snr_1_snr_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SNR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t modem_bf_depack_snr_1_snr_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SNR_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief DEPACK_SNR_2 register definition
 *  Depacker Av SNR 4 to 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 SNR7                      0x0
 *    23:16 SNR6                      0x0
 *    15:08 SNR5                      0x0
 *    07:00 SNR4                      0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_SNR_2_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000054)
#define MODEM_BF_DEPACK_SNR_2_OFFSET      0x00000054
#define MODEM_BF_DEPACK_SNR_2_INDEX       0x00000015
#define MODEM_BF_DEPACK_SNR_2_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_snr_2_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_SNR_2_ADDR);
}

// field definitions
#define MODEM_BF_DEPACK_SNR_2_SNR_7_MASK    ((uint32_t)0xFF000000)
#define MODEM_BF_DEPACK_SNR_2_SNR_7_LSB     24
#define MODEM_BF_DEPACK_SNR_2_SNR_7_WIDTH    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_SNR_2_SNR_6_MASK    ((uint32_t)0x00FF0000)
#define MODEM_BF_DEPACK_SNR_2_SNR_6_LSB     16
#define MODEM_BF_DEPACK_SNR_2_SNR_6_WIDTH    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_SNR_2_SNR_5_MASK    ((uint32_t)0x0000FF00)
#define MODEM_BF_DEPACK_SNR_2_SNR_5_LSB     8
#define MODEM_BF_DEPACK_SNR_2_SNR_5_WIDTH    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_SNR_2_SNR_4_MASK    ((uint32_t)0x000000FF)
#define MODEM_BF_DEPACK_SNR_2_SNR_4_LSB     0
#define MODEM_BF_DEPACK_SNR_2_SNR_4_WIDTH    ((uint32_t)0x00000008)

#define MODEM_BF_DEPACK_SNR_2_SNR_7_RST     0x0
#define MODEM_BF_DEPACK_SNR_2_SNR_6_RST     0x0
#define MODEM_BF_DEPACK_SNR_2_SNR_5_RST     0x0
#define MODEM_BF_DEPACK_SNR_2_SNR_4_RST     0x0

__INLINE void modem_bf_depack_snr_2_unpack(uint8_t* snr7, uint8_t* snr6, uint8_t* snr5, uint8_t* snr4)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SNR_2_ADDR);

	*snr7 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*snr6 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*snr5 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*snr4 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t modem_bf_depack_snr_2_snr_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SNR_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint8_t modem_bf_depack_snr_2_snr_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SNR_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t modem_bf_depack_snr_2_snr_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SNR_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t modem_bf_depack_snr_2_snr_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SNR_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief DEPACK_SRC_ADDR_0 register definition
 *  Config 0 address for input header register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 src_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_SRC_ADDR_0_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000060)
#define MODEM_BF_DEPACK_SRC_ADDR_0_OFFSET      0x00000060
#define MODEM_BF_DEPACK_SRC_ADDR_0_INDEX       0x00000018
#define MODEM_BF_DEPACK_SRC_ADDR_0_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_src_addr_0_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_0_ADDR);
}

__INLINE void modem_bf_depack_src_addr_0_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_0_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_SRC_ADDR_0_SRC_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_SRC_ADDR_0_SRC_ADDR_LSB    0
#define MODEM_BF_DEPACK_SRC_ADDR_0_SRC_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_SRC_ADDR_0_SRC_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_src_addr_0_src_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_0_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_src_addr_0_src_addr_setf(uint16_t srcaddr)
{
	ASSERT_ERR((((uint32_t)srcaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_0_ADDR, (uint32_t)srcaddr << 0);
}

/**
 * @brief DEPACK_DST_ADDR_0 register definition
 *  Config 0 destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_ADDR_0_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000064)
#define MODEM_BF_DEPACK_DST_ADDR_0_OFFSET      0x00000064
#define MODEM_BF_DEPACK_DST_ADDR_0_INDEX       0x00000019
#define MODEM_BF_DEPACK_DST_ADDR_0_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_addr_0_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_0_ADDR);
}

__INLINE void modem_bf_depack_dst_addr_0_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_0_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_ADDR_0_DST_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_ADDR_0_DST_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_ADDR_0_DST_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_ADDR_0_DST_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_addr_0_dst_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_0_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_addr_0_dst_addr_setf(uint16_t dstaddr)
{
	ASSERT_ERR((((uint32_t)dstaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_0_ADDR, (uint32_t)dstaddr << 0);
}

/**
 * @brief DEPACK_DST_SNR_ADDR_0 register definition
 *  Config 0 DSNR destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_snr_addr              0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_SNR_ADDR_0_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000068)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_0_OFFSET      0x00000068
#define MODEM_BF_DEPACK_DST_SNR_ADDR_0_INDEX       0x0000001A
#define MODEM_BF_DEPACK_DST_SNR_ADDR_0_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_snr_addr_0_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_0_ADDR);
}

__INLINE void modem_bf_depack_dst_snr_addr_0_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_0_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_SNR_ADDR_0_DST_SNR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_0_DST_SNR_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_SNR_ADDR_0_DST_SNR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_SNR_ADDR_0_DST_SNR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_snr_addr_0_dst_snr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_0_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_snr_addr_0_dst_snr_addr_setf(uint16_t dstsnraddr)
{
	ASSERT_ERR((((uint32_t)dstsnraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_0_ADDR, (uint32_t)dstsnraddr << 0);
}

/**
 * @brief DEPACK_HDR_ADDR_0 register definition
 *  Config 0 output header address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 hdr_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_HDR_ADDR_0_ADDR        (REG_MODEM_BF_BASE_ADDR+0x0000006C)
#define MODEM_BF_DEPACK_HDR_ADDR_0_OFFSET      0x0000006C
#define MODEM_BF_DEPACK_HDR_ADDR_0_INDEX       0x0000001B
#define MODEM_BF_DEPACK_HDR_ADDR_0_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_hdr_addr_0_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_0_ADDR);
}

__INLINE void modem_bf_depack_hdr_addr_0_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_0_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_HDR_ADDR_0_HDR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_HDR_ADDR_0_HDR_ADDR_LSB    0
#define MODEM_BF_DEPACK_HDR_ADDR_0_HDR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_HDR_ADDR_0_HDR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_hdr_addr_0_hdr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_0_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_hdr_addr_0_hdr_addr_setf(uint16_t hdraddr)
{
	ASSERT_ERR((((uint32_t)hdraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_0_ADDR, (uint32_t)hdraddr << 0);
}

/**
 * @brief DEPACK_MCCI_ADDR_0 register definition
 *  Config 0 MCCI message address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mcci_addr                 0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_MCCI_ADDR_0_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000070)
#define MODEM_BF_DEPACK_MCCI_ADDR_0_OFFSET      0x00000070
#define MODEM_BF_DEPACK_MCCI_ADDR_0_INDEX       0x0000001C
#define MODEM_BF_DEPACK_MCCI_ADDR_0_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_mcci_addr_0_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_0_ADDR);
}

__INLINE void modem_bf_depack_mcci_addr_0_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_0_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_MCCI_ADDR_0_MCCI_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MODEM_BF_DEPACK_MCCI_ADDR_0_MCCI_ADDR_LSB    0
#define MODEM_BF_DEPACK_MCCI_ADDR_0_MCCI_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MODEM_BF_DEPACK_MCCI_ADDR_0_MCCI_ADDR_RST    0x0

__INLINE uint32_t modem_bf_depack_mcci_addr_0_mcci_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_mcci_addr_0_mcci_addr_setf(uint32_t mcciaddr)
{
	ASSERT_ERR((((uint32_t)mcciaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_0_ADDR, (uint32_t)mcciaddr << 0);
}

/**
 * @brief DEPACK_DYN_0 register definition
 *  Config 0 dynamic configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    mcci_disable              0              
 *    02:01 ng_target                 0x0
 *    00    enable                    0              
 * </pre>
 */
#define MODEM_BF_DEPACK_DYN_0_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000074)
#define MODEM_BF_DEPACK_DYN_0_OFFSET      0x00000074
#define MODEM_BF_DEPACK_DYN_0_INDEX       0x0000001D
#define MODEM_BF_DEPACK_DYN_0_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dyn_0_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DYN_0_ADDR);
}

__INLINE void modem_bf_depack_dyn_0_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DYN_0_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DYN_0_MCCI_DISABLE_BIT    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_DYN_0_MCCI_DISABLE_POS    3
#define MODEM_BF_DEPACK_DYN_0_NG_TARGET_MASK    ((uint32_t)0x00000006)
#define MODEM_BF_DEPACK_DYN_0_NG_TARGET_LSB    1
#define MODEM_BF_DEPACK_DYN_0_NG_TARGET_WIDTH    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_DYN_0_ENABLE_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_DEPACK_DYN_0_ENABLE_POS    0

#define MODEM_BF_DEPACK_DYN_0_MCCI_DISABLE_RST    0x0
#define MODEM_BF_DEPACK_DYN_0_NG_TARGET_RST    0x0
#define MODEM_BF_DEPACK_DYN_0_ENABLE_RST    0x0

__INLINE void modem_bf_depack_dyn_0_pack(uint8_t mcci_disable, uint8_t ng_target, uint8_t enable)
{
	ASSERT_ERR((((uint32_t)mcci_disable << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)ng_target << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_0_ADDR,  ((uint32_t)mcci_disable << 3) |((uint32_t)ng_target << 1) |((uint32_t)enable << 0));
}

__INLINE void modem_bf_depack_dyn_0_unpack(uint8_t* mcci_disable, uint8_t* ng_target, uint8_t* enable)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_0_ADDR);

	*mcci_disable = (localVal & ((uint32_t)0x00000008)) >>  3;
	*ng_target = (localVal & ((uint32_t)0x00000006)) >>  1;
	*enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_depack_dyn_0_mcci_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void modem_bf_depack_dyn_0_mcci_disable_setf(uint8_t mccidisable)
{
	ASSERT_ERR((((uint32_t)mccidisable << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_0_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)mccidisable <<3));
}
__INLINE uint8_t modem_bf_depack_dyn_0_ng_target_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void modem_bf_depack_dyn_0_ng_target_setf(uint8_t ngtarget)
{
	ASSERT_ERR((((uint32_t)ngtarget << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_0_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_0_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)ngtarget <<1));
}
__INLINE uint8_t modem_bf_depack_dyn_0_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void modem_bf_depack_dyn_0_enable_setf(uint8_t enable)
{
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_0_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enable <<0));
}

/**
 * @brief DEPACK_SRC_ADDR_1 register definition
 *  Config 1 address for input header register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 src_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_SRC_ADDR_1_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000080)
#define MODEM_BF_DEPACK_SRC_ADDR_1_OFFSET      0x00000080
#define MODEM_BF_DEPACK_SRC_ADDR_1_INDEX       0x00000020
#define MODEM_BF_DEPACK_SRC_ADDR_1_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_src_addr_1_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_1_ADDR);
}

__INLINE void modem_bf_depack_src_addr_1_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_1_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_SRC_ADDR_1_SRC_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_SRC_ADDR_1_SRC_ADDR_LSB    0
#define MODEM_BF_DEPACK_SRC_ADDR_1_SRC_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_SRC_ADDR_1_SRC_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_src_addr_1_src_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_1_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_src_addr_1_src_addr_setf(uint16_t srcaddr)
{
	ASSERT_ERR((((uint32_t)srcaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_1_ADDR, (uint32_t)srcaddr << 0);
}

/**
 * @brief DEPACK_DST_ADDR_1 register definition
 *  Config 1 destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_ADDR_1_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000084)
#define MODEM_BF_DEPACK_DST_ADDR_1_OFFSET      0x00000084
#define MODEM_BF_DEPACK_DST_ADDR_1_INDEX       0x00000021
#define MODEM_BF_DEPACK_DST_ADDR_1_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_addr_1_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_1_ADDR);
}

__INLINE void modem_bf_depack_dst_addr_1_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_1_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_ADDR_1_DST_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_ADDR_1_DST_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_ADDR_1_DST_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_ADDR_1_DST_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_addr_1_dst_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_1_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_addr_1_dst_addr_setf(uint16_t dstaddr)
{
	ASSERT_ERR((((uint32_t)dstaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_1_ADDR, (uint32_t)dstaddr << 0);
}

/**
 * @brief DEPACK_DST_SNR_ADDR_1 register definition
 *  Config 1 DSNR destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_snr_addr              0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_SNR_ADDR_1_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000088)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_1_OFFSET      0x00000088
#define MODEM_BF_DEPACK_DST_SNR_ADDR_1_INDEX       0x00000022
#define MODEM_BF_DEPACK_DST_SNR_ADDR_1_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_snr_addr_1_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_1_ADDR);
}

__INLINE void modem_bf_depack_dst_snr_addr_1_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_1_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_SNR_ADDR_1_DST_SNR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_1_DST_SNR_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_SNR_ADDR_1_DST_SNR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_SNR_ADDR_1_DST_SNR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_snr_addr_1_dst_snr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_1_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_snr_addr_1_dst_snr_addr_setf(uint16_t dstsnraddr)
{
	ASSERT_ERR((((uint32_t)dstsnraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_1_ADDR, (uint32_t)dstsnraddr << 0);
}

/**
 * @brief DEPACK_HDR_ADDR_1 register definition
 *  Config 1 output header address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 hdr_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_HDR_ADDR_1_ADDR        (REG_MODEM_BF_BASE_ADDR+0x0000008C)
#define MODEM_BF_DEPACK_HDR_ADDR_1_OFFSET      0x0000008C
#define MODEM_BF_DEPACK_HDR_ADDR_1_INDEX       0x00000023
#define MODEM_BF_DEPACK_HDR_ADDR_1_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_hdr_addr_1_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_1_ADDR);
}

__INLINE void modem_bf_depack_hdr_addr_1_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_1_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_HDR_ADDR_1_HDR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_HDR_ADDR_1_HDR_ADDR_LSB    0
#define MODEM_BF_DEPACK_HDR_ADDR_1_HDR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_HDR_ADDR_1_HDR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_hdr_addr_1_hdr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_1_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_hdr_addr_1_hdr_addr_setf(uint16_t hdraddr)
{
	ASSERT_ERR((((uint32_t)hdraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_1_ADDR, (uint32_t)hdraddr << 0);
}

/**
 * @brief DEPACK_MCCI_ADDR_1 register definition
 *  Config 1 MCCI message address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mcci_addr                 0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_MCCI_ADDR_1_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000090)
#define MODEM_BF_DEPACK_MCCI_ADDR_1_OFFSET      0x00000090
#define MODEM_BF_DEPACK_MCCI_ADDR_1_INDEX       0x00000024
#define MODEM_BF_DEPACK_MCCI_ADDR_1_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_mcci_addr_1_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_1_ADDR);
}

__INLINE void modem_bf_depack_mcci_addr_1_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_1_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_MCCI_ADDR_1_MCCI_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MODEM_BF_DEPACK_MCCI_ADDR_1_MCCI_ADDR_LSB    0
#define MODEM_BF_DEPACK_MCCI_ADDR_1_MCCI_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MODEM_BF_DEPACK_MCCI_ADDR_1_MCCI_ADDR_RST    0x0

__INLINE uint32_t modem_bf_depack_mcci_addr_1_mcci_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_mcci_addr_1_mcci_addr_setf(uint32_t mcciaddr)
{
	ASSERT_ERR((((uint32_t)mcciaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_1_ADDR, (uint32_t)mcciaddr << 0);
}

/**
 * @brief DEPACK_DYN_1 register definition
 *  Config 1 dynamic configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    mcci_disable              0              
 *    02:01 ng_target                 0x0
 *    00    enable                    0              
 * </pre>
 */
#define MODEM_BF_DEPACK_DYN_1_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000094)
#define MODEM_BF_DEPACK_DYN_1_OFFSET      0x00000094
#define MODEM_BF_DEPACK_DYN_1_INDEX       0x00000025
#define MODEM_BF_DEPACK_DYN_1_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dyn_1_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DYN_1_ADDR);
}

__INLINE void modem_bf_depack_dyn_1_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DYN_1_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DYN_1_MCCI_DISABLE_BIT    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_DYN_1_MCCI_DISABLE_POS    3
#define MODEM_BF_DEPACK_DYN_1_NG_TARGET_MASK    ((uint32_t)0x00000006)
#define MODEM_BF_DEPACK_DYN_1_NG_TARGET_LSB    1
#define MODEM_BF_DEPACK_DYN_1_NG_TARGET_WIDTH    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_DYN_1_ENABLE_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_DEPACK_DYN_1_ENABLE_POS    0

#define MODEM_BF_DEPACK_DYN_1_MCCI_DISABLE_RST    0x0
#define MODEM_BF_DEPACK_DYN_1_NG_TARGET_RST    0x0
#define MODEM_BF_DEPACK_DYN_1_ENABLE_RST    0x0

__INLINE void modem_bf_depack_dyn_1_pack(uint8_t mcci_disable, uint8_t ng_target, uint8_t enable)
{
	ASSERT_ERR((((uint32_t)mcci_disable << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)ng_target << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_1_ADDR,  ((uint32_t)mcci_disable << 3) |((uint32_t)ng_target << 1) |((uint32_t)enable << 0));
}

__INLINE void modem_bf_depack_dyn_1_unpack(uint8_t* mcci_disable, uint8_t* ng_target, uint8_t* enable)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_1_ADDR);

	*mcci_disable = (localVal & ((uint32_t)0x00000008)) >>  3;
	*ng_target = (localVal & ((uint32_t)0x00000006)) >>  1;
	*enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_depack_dyn_1_mcci_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void modem_bf_depack_dyn_1_mcci_disable_setf(uint8_t mccidisable)
{
	ASSERT_ERR((((uint32_t)mccidisable << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_1_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_1_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)mccidisable <<3));
}
__INLINE uint8_t modem_bf_depack_dyn_1_ng_target_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void modem_bf_depack_dyn_1_ng_target_setf(uint8_t ngtarget)
{
	ASSERT_ERR((((uint32_t)ngtarget << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_1_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_1_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)ngtarget <<1));
}
__INLINE uint8_t modem_bf_depack_dyn_1_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void modem_bf_depack_dyn_1_enable_setf(uint8_t enable)
{
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_1_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enable <<0));
}

/**
 * @brief DEPACK_SRC_ADDR_2 register definition
 *  Config 2 address for input header register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 src_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_SRC_ADDR_2_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000A0)
#define MODEM_BF_DEPACK_SRC_ADDR_2_OFFSET      0x000000A0
#define MODEM_BF_DEPACK_SRC_ADDR_2_INDEX       0x00000028
#define MODEM_BF_DEPACK_SRC_ADDR_2_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_src_addr_2_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_2_ADDR);
}

__INLINE void modem_bf_depack_src_addr_2_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_2_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_SRC_ADDR_2_SRC_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_SRC_ADDR_2_SRC_ADDR_LSB    0
#define MODEM_BF_DEPACK_SRC_ADDR_2_SRC_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_SRC_ADDR_2_SRC_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_src_addr_2_src_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_2_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_src_addr_2_src_addr_setf(uint16_t srcaddr)
{
	ASSERT_ERR((((uint32_t)srcaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_2_ADDR, (uint32_t)srcaddr << 0);
}

/**
 * @brief DEPACK_DST_ADDR_2 register definition
 *  Config 2 destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_ADDR_2_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000A4)
#define MODEM_BF_DEPACK_DST_ADDR_2_OFFSET      0x000000A4
#define MODEM_BF_DEPACK_DST_ADDR_2_INDEX       0x00000029
#define MODEM_BF_DEPACK_DST_ADDR_2_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_addr_2_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_2_ADDR);
}

__INLINE void modem_bf_depack_dst_addr_2_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_2_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_ADDR_2_DST_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_ADDR_2_DST_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_ADDR_2_DST_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_ADDR_2_DST_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_addr_2_dst_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_2_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_addr_2_dst_addr_setf(uint16_t dstaddr)
{
	ASSERT_ERR((((uint32_t)dstaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_2_ADDR, (uint32_t)dstaddr << 0);
}

/**
 * @brief DEPACK_DST_SNR_ADDR_2 register definition
 *  Config 2 DSNR destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_snr_addr              0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_SNR_ADDR_2_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000A8)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_2_OFFSET      0x000000A8
#define MODEM_BF_DEPACK_DST_SNR_ADDR_2_INDEX       0x0000002A
#define MODEM_BF_DEPACK_DST_SNR_ADDR_2_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_snr_addr_2_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_2_ADDR);
}

__INLINE void modem_bf_depack_dst_snr_addr_2_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_2_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_SNR_ADDR_2_DST_SNR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_2_DST_SNR_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_SNR_ADDR_2_DST_SNR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_SNR_ADDR_2_DST_SNR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_snr_addr_2_dst_snr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_2_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_snr_addr_2_dst_snr_addr_setf(uint16_t dstsnraddr)
{
	ASSERT_ERR((((uint32_t)dstsnraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_2_ADDR, (uint32_t)dstsnraddr << 0);
}

/**
 * @brief DEPACK_HDR_ADDR_2 register definition
 *  Config 2 output header address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 hdr_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_HDR_ADDR_2_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000AC)
#define MODEM_BF_DEPACK_HDR_ADDR_2_OFFSET      0x000000AC
#define MODEM_BF_DEPACK_HDR_ADDR_2_INDEX       0x0000002B
#define MODEM_BF_DEPACK_HDR_ADDR_2_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_hdr_addr_2_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_2_ADDR);
}

__INLINE void modem_bf_depack_hdr_addr_2_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_2_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_HDR_ADDR_2_HDR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_HDR_ADDR_2_HDR_ADDR_LSB    0
#define MODEM_BF_DEPACK_HDR_ADDR_2_HDR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_HDR_ADDR_2_HDR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_hdr_addr_2_hdr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_2_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_hdr_addr_2_hdr_addr_setf(uint16_t hdraddr)
{
	ASSERT_ERR((((uint32_t)hdraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_2_ADDR, (uint32_t)hdraddr << 0);
}

/**
 * @brief DEPACK_MCCI_ADDR_2 register definition
 *  Config 2 MCCI message address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mcci_addr                 0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_MCCI_ADDR_2_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000B0)
#define MODEM_BF_DEPACK_MCCI_ADDR_2_OFFSET      0x000000B0
#define MODEM_BF_DEPACK_MCCI_ADDR_2_INDEX       0x0000002C
#define MODEM_BF_DEPACK_MCCI_ADDR_2_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_mcci_addr_2_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_2_ADDR);
}

__INLINE void modem_bf_depack_mcci_addr_2_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_2_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_MCCI_ADDR_2_MCCI_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MODEM_BF_DEPACK_MCCI_ADDR_2_MCCI_ADDR_LSB    0
#define MODEM_BF_DEPACK_MCCI_ADDR_2_MCCI_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MODEM_BF_DEPACK_MCCI_ADDR_2_MCCI_ADDR_RST    0x0

__INLINE uint32_t modem_bf_depack_mcci_addr_2_mcci_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_mcci_addr_2_mcci_addr_setf(uint32_t mcciaddr)
{
	ASSERT_ERR((((uint32_t)mcciaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_2_ADDR, (uint32_t)mcciaddr << 0);
}

/**
 * @brief DEPACK_DYN_2 register definition
 *  Config 2 dynamic configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    mcci_disable              0              
 *    02:01 ng_target                 0x0
 *    00    enable                    0              
 * </pre>
 */
#define MODEM_BF_DEPACK_DYN_2_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000B4)
#define MODEM_BF_DEPACK_DYN_2_OFFSET      0x000000B4
#define MODEM_BF_DEPACK_DYN_2_INDEX       0x0000002D
#define MODEM_BF_DEPACK_DYN_2_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dyn_2_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DYN_2_ADDR);
}

__INLINE void modem_bf_depack_dyn_2_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DYN_2_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DYN_2_MCCI_DISABLE_BIT    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_DYN_2_MCCI_DISABLE_POS    3
#define MODEM_BF_DEPACK_DYN_2_NG_TARGET_MASK    ((uint32_t)0x00000006)
#define MODEM_BF_DEPACK_DYN_2_NG_TARGET_LSB    1
#define MODEM_BF_DEPACK_DYN_2_NG_TARGET_WIDTH    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_DYN_2_ENABLE_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_DEPACK_DYN_2_ENABLE_POS    0

#define MODEM_BF_DEPACK_DYN_2_MCCI_DISABLE_RST    0x0
#define MODEM_BF_DEPACK_DYN_2_NG_TARGET_RST    0x0
#define MODEM_BF_DEPACK_DYN_2_ENABLE_RST    0x0

__INLINE void modem_bf_depack_dyn_2_pack(uint8_t mcci_disable, uint8_t ng_target, uint8_t enable)
{
	ASSERT_ERR((((uint32_t)mcci_disable << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)ng_target << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_2_ADDR,  ((uint32_t)mcci_disable << 3) |((uint32_t)ng_target << 1) |((uint32_t)enable << 0));
}

__INLINE void modem_bf_depack_dyn_2_unpack(uint8_t* mcci_disable, uint8_t* ng_target, uint8_t* enable)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_2_ADDR);

	*mcci_disable = (localVal & ((uint32_t)0x00000008)) >>  3;
	*ng_target = (localVal & ((uint32_t)0x00000006)) >>  1;
	*enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_depack_dyn_2_mcci_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void modem_bf_depack_dyn_2_mcci_disable_setf(uint8_t mccidisable)
{
	ASSERT_ERR((((uint32_t)mccidisable << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_2_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_2_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)mccidisable <<3));
}
__INLINE uint8_t modem_bf_depack_dyn_2_ng_target_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void modem_bf_depack_dyn_2_ng_target_setf(uint8_t ngtarget)
{
	ASSERT_ERR((((uint32_t)ngtarget << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_2_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_2_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)ngtarget <<1));
}
__INLINE uint8_t modem_bf_depack_dyn_2_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void modem_bf_depack_dyn_2_enable_setf(uint8_t enable)
{
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_2_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_2_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enable <<0));
}

/**
 * @brief DEPACK_SRC_ADDR_3 register definition
 *  Config 3 address for input header register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 src_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_SRC_ADDR_3_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000C0)
#define MODEM_BF_DEPACK_SRC_ADDR_3_OFFSET      0x000000C0
#define MODEM_BF_DEPACK_SRC_ADDR_3_INDEX       0x00000030
#define MODEM_BF_DEPACK_SRC_ADDR_3_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_src_addr_3_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_3_ADDR);
}

__INLINE void modem_bf_depack_src_addr_3_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_3_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_SRC_ADDR_3_SRC_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_SRC_ADDR_3_SRC_ADDR_LSB    0
#define MODEM_BF_DEPACK_SRC_ADDR_3_SRC_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_SRC_ADDR_3_SRC_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_src_addr_3_src_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_3_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_src_addr_3_src_addr_setf(uint16_t srcaddr)
{
	ASSERT_ERR((((uint32_t)srcaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_3_ADDR, (uint32_t)srcaddr << 0);
}

/**
 * @brief DEPACK_DST_ADDR_3 register definition
 *  Config 3 destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_ADDR_3_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000C4)
#define MODEM_BF_DEPACK_DST_ADDR_3_OFFSET      0x000000C4
#define MODEM_BF_DEPACK_DST_ADDR_3_INDEX       0x00000031
#define MODEM_BF_DEPACK_DST_ADDR_3_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_addr_3_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_3_ADDR);
}

__INLINE void modem_bf_depack_dst_addr_3_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_3_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_ADDR_3_DST_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_ADDR_3_DST_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_ADDR_3_DST_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_ADDR_3_DST_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_addr_3_dst_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_3_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_addr_3_dst_addr_setf(uint16_t dstaddr)
{
	ASSERT_ERR((((uint32_t)dstaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_3_ADDR, (uint32_t)dstaddr << 0);
}

/**
 * @brief DEPACK_DST_SNR_ADDR_3 register definition
 *  Config 3 DSNR destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_snr_addr              0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_SNR_ADDR_3_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000C8)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_3_OFFSET      0x000000C8
#define MODEM_BF_DEPACK_DST_SNR_ADDR_3_INDEX       0x00000032
#define MODEM_BF_DEPACK_DST_SNR_ADDR_3_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_snr_addr_3_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_3_ADDR);
}

__INLINE void modem_bf_depack_dst_snr_addr_3_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_3_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_SNR_ADDR_3_DST_SNR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_3_DST_SNR_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_SNR_ADDR_3_DST_SNR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_SNR_ADDR_3_DST_SNR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_snr_addr_3_dst_snr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_3_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_snr_addr_3_dst_snr_addr_setf(uint16_t dstsnraddr)
{
	ASSERT_ERR((((uint32_t)dstsnraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_3_ADDR, (uint32_t)dstsnraddr << 0);
}

/**
 * @brief DEPACK_HDR_ADDR_3 register definition
 *  Config 3 output header address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 hdr_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_HDR_ADDR_3_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000CC)
#define MODEM_BF_DEPACK_HDR_ADDR_3_OFFSET      0x000000CC
#define MODEM_BF_DEPACK_HDR_ADDR_3_INDEX       0x00000033
#define MODEM_BF_DEPACK_HDR_ADDR_3_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_hdr_addr_3_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_3_ADDR);
}

__INLINE void modem_bf_depack_hdr_addr_3_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_3_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_HDR_ADDR_3_HDR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_HDR_ADDR_3_HDR_ADDR_LSB    0
#define MODEM_BF_DEPACK_HDR_ADDR_3_HDR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_HDR_ADDR_3_HDR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_hdr_addr_3_hdr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_3_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_hdr_addr_3_hdr_addr_setf(uint16_t hdraddr)
{
	ASSERT_ERR((((uint32_t)hdraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_3_ADDR, (uint32_t)hdraddr << 0);
}

/**
 * @brief DEPACK_MCCI_ADDR_3 register definition
 *  Config 3 MCCI message address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mcci_addr                 0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_MCCI_ADDR_3_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000D0)
#define MODEM_BF_DEPACK_MCCI_ADDR_3_OFFSET      0x000000D0
#define MODEM_BF_DEPACK_MCCI_ADDR_3_INDEX       0x00000034
#define MODEM_BF_DEPACK_MCCI_ADDR_3_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_mcci_addr_3_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_3_ADDR);
}

__INLINE void modem_bf_depack_mcci_addr_3_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_3_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_MCCI_ADDR_3_MCCI_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MODEM_BF_DEPACK_MCCI_ADDR_3_MCCI_ADDR_LSB    0
#define MODEM_BF_DEPACK_MCCI_ADDR_3_MCCI_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MODEM_BF_DEPACK_MCCI_ADDR_3_MCCI_ADDR_RST    0x0

__INLINE uint32_t modem_bf_depack_mcci_addr_3_mcci_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_mcci_addr_3_mcci_addr_setf(uint32_t mcciaddr)
{
	ASSERT_ERR((((uint32_t)mcciaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_3_ADDR, (uint32_t)mcciaddr << 0);
}

/**
 * @brief DEPACK_DYN_3 register definition
 *  Config 3 dynamic configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    mcci_disable              0              
 *    02:01 ng_target                 0x0
 *    00    enable                    0              
 * </pre>
 */
#define MODEM_BF_DEPACK_DYN_3_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000D4)
#define MODEM_BF_DEPACK_DYN_3_OFFSET      0x000000D4
#define MODEM_BF_DEPACK_DYN_3_INDEX       0x00000035
#define MODEM_BF_DEPACK_DYN_3_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dyn_3_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DYN_3_ADDR);
}

__INLINE void modem_bf_depack_dyn_3_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DYN_3_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DYN_3_MCCI_DISABLE_BIT    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_DYN_3_MCCI_DISABLE_POS    3
#define MODEM_BF_DEPACK_DYN_3_NG_TARGET_MASK    ((uint32_t)0x00000006)
#define MODEM_BF_DEPACK_DYN_3_NG_TARGET_LSB    1
#define MODEM_BF_DEPACK_DYN_3_NG_TARGET_WIDTH    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_DYN_3_ENABLE_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_DEPACK_DYN_3_ENABLE_POS    0

#define MODEM_BF_DEPACK_DYN_3_MCCI_DISABLE_RST    0x0
#define MODEM_BF_DEPACK_DYN_3_NG_TARGET_RST    0x0
#define MODEM_BF_DEPACK_DYN_3_ENABLE_RST    0x0

__INLINE void modem_bf_depack_dyn_3_pack(uint8_t mcci_disable, uint8_t ng_target, uint8_t enable)
{
	ASSERT_ERR((((uint32_t)mcci_disable << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)ng_target << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_3_ADDR,  ((uint32_t)mcci_disable << 3) |((uint32_t)ng_target << 1) |((uint32_t)enable << 0));
}

__INLINE void modem_bf_depack_dyn_3_unpack(uint8_t* mcci_disable, uint8_t* ng_target, uint8_t* enable)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_3_ADDR);

	*mcci_disable = (localVal & ((uint32_t)0x00000008)) >>  3;
	*ng_target = (localVal & ((uint32_t)0x00000006)) >>  1;
	*enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_depack_dyn_3_mcci_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void modem_bf_depack_dyn_3_mcci_disable_setf(uint8_t mccidisable)
{
	ASSERT_ERR((((uint32_t)mccidisable << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_3_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_3_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)mccidisable <<3));
}
__INLINE uint8_t modem_bf_depack_dyn_3_ng_target_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void modem_bf_depack_dyn_3_ng_target_setf(uint8_t ngtarget)
{
	ASSERT_ERR((((uint32_t)ngtarget << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_3_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_3_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)ngtarget <<1));
}
__INLINE uint8_t modem_bf_depack_dyn_3_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void modem_bf_depack_dyn_3_enable_setf(uint8_t enable)
{
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_3_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_3_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enable <<0));
}

/**
 * @brief DEPACK_SRC_ADDR_4 register definition
 *  Config 4 address for input header register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 src_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_SRC_ADDR_4_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000E0)
#define MODEM_BF_DEPACK_SRC_ADDR_4_OFFSET      0x000000E0
#define MODEM_BF_DEPACK_SRC_ADDR_4_INDEX       0x00000038
#define MODEM_BF_DEPACK_SRC_ADDR_4_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_src_addr_4_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_4_ADDR);
}

__INLINE void modem_bf_depack_src_addr_4_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_4_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_SRC_ADDR_4_SRC_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_SRC_ADDR_4_SRC_ADDR_LSB    0
#define MODEM_BF_DEPACK_SRC_ADDR_4_SRC_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_SRC_ADDR_4_SRC_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_src_addr_4_src_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_4_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_src_addr_4_src_addr_setf(uint16_t srcaddr)
{
	ASSERT_ERR((((uint32_t)srcaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_4_ADDR, (uint32_t)srcaddr << 0);
}

/**
 * @brief DEPACK_DST_ADDR_4 register definition
 *  Config 4 destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_ADDR_4_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000E4)
#define MODEM_BF_DEPACK_DST_ADDR_4_OFFSET      0x000000E4
#define MODEM_BF_DEPACK_DST_ADDR_4_INDEX       0x00000039
#define MODEM_BF_DEPACK_DST_ADDR_4_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_addr_4_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_4_ADDR);
}

__INLINE void modem_bf_depack_dst_addr_4_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_4_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_ADDR_4_DST_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_ADDR_4_DST_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_ADDR_4_DST_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_ADDR_4_DST_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_addr_4_dst_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_4_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_addr_4_dst_addr_setf(uint16_t dstaddr)
{
	ASSERT_ERR((((uint32_t)dstaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_4_ADDR, (uint32_t)dstaddr << 0);
}

/**
 * @brief DEPACK_DST_SNR_ADDR_4 register definition
 *  Config 4 DSNR destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_snr_addr              0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_SNR_ADDR_4_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000E8)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_4_OFFSET      0x000000E8
#define MODEM_BF_DEPACK_DST_SNR_ADDR_4_INDEX       0x0000003A
#define MODEM_BF_DEPACK_DST_SNR_ADDR_4_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_snr_addr_4_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_4_ADDR);
}

__INLINE void modem_bf_depack_dst_snr_addr_4_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_4_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_SNR_ADDR_4_DST_SNR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_4_DST_SNR_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_SNR_ADDR_4_DST_SNR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_SNR_ADDR_4_DST_SNR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_snr_addr_4_dst_snr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_4_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_snr_addr_4_dst_snr_addr_setf(uint16_t dstsnraddr)
{
	ASSERT_ERR((((uint32_t)dstsnraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_4_ADDR, (uint32_t)dstsnraddr << 0);
}

/**
 * @brief DEPACK_HDR_ADDR_4 register definition
 *  Config 4 output header address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 hdr_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_HDR_ADDR_4_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000EC)
#define MODEM_BF_DEPACK_HDR_ADDR_4_OFFSET      0x000000EC
#define MODEM_BF_DEPACK_HDR_ADDR_4_INDEX       0x0000003B
#define MODEM_BF_DEPACK_HDR_ADDR_4_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_hdr_addr_4_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_4_ADDR);
}

__INLINE void modem_bf_depack_hdr_addr_4_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_4_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_HDR_ADDR_4_HDR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_HDR_ADDR_4_HDR_ADDR_LSB    0
#define MODEM_BF_DEPACK_HDR_ADDR_4_HDR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_HDR_ADDR_4_HDR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_hdr_addr_4_hdr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_4_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_hdr_addr_4_hdr_addr_setf(uint16_t hdraddr)
{
	ASSERT_ERR((((uint32_t)hdraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_4_ADDR, (uint32_t)hdraddr << 0);
}

/**
 * @brief DEPACK_MCCI_ADDR_4 register definition
 *  Config 4 MCCI message address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mcci_addr                 0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_MCCI_ADDR_4_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000F0)
#define MODEM_BF_DEPACK_MCCI_ADDR_4_OFFSET      0x000000F0
#define MODEM_BF_DEPACK_MCCI_ADDR_4_INDEX       0x0000003C
#define MODEM_BF_DEPACK_MCCI_ADDR_4_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_mcci_addr_4_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_4_ADDR);
}

__INLINE void modem_bf_depack_mcci_addr_4_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_4_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_MCCI_ADDR_4_MCCI_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MODEM_BF_DEPACK_MCCI_ADDR_4_MCCI_ADDR_LSB    0
#define MODEM_BF_DEPACK_MCCI_ADDR_4_MCCI_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MODEM_BF_DEPACK_MCCI_ADDR_4_MCCI_ADDR_RST    0x0

__INLINE uint32_t modem_bf_depack_mcci_addr_4_mcci_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_mcci_addr_4_mcci_addr_setf(uint32_t mcciaddr)
{
	ASSERT_ERR((((uint32_t)mcciaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_4_ADDR, (uint32_t)mcciaddr << 0);
}

/**
 * @brief DEPACK_DYN_4 register definition
 *  Config 4 dynamic configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    mcci_disable              0              
 *    02:01 ng_target                 0x0
 *    00    enable                    0              
 * </pre>
 */
#define MODEM_BF_DEPACK_DYN_4_ADDR        (REG_MODEM_BF_BASE_ADDR+0x000000F4)
#define MODEM_BF_DEPACK_DYN_4_OFFSET      0x000000F4
#define MODEM_BF_DEPACK_DYN_4_INDEX       0x0000003D
#define MODEM_BF_DEPACK_DYN_4_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dyn_4_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DYN_4_ADDR);
}

__INLINE void modem_bf_depack_dyn_4_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DYN_4_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DYN_4_MCCI_DISABLE_BIT    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_DYN_4_MCCI_DISABLE_POS    3
#define MODEM_BF_DEPACK_DYN_4_NG_TARGET_MASK    ((uint32_t)0x00000006)
#define MODEM_BF_DEPACK_DYN_4_NG_TARGET_LSB    1
#define MODEM_BF_DEPACK_DYN_4_NG_TARGET_WIDTH    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_DYN_4_ENABLE_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_DEPACK_DYN_4_ENABLE_POS    0

#define MODEM_BF_DEPACK_DYN_4_MCCI_DISABLE_RST    0x0
#define MODEM_BF_DEPACK_DYN_4_NG_TARGET_RST    0x0
#define MODEM_BF_DEPACK_DYN_4_ENABLE_RST    0x0

__INLINE void modem_bf_depack_dyn_4_pack(uint8_t mcci_disable, uint8_t ng_target, uint8_t enable)
{
	ASSERT_ERR((((uint32_t)mcci_disable << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)ng_target << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_4_ADDR,  ((uint32_t)mcci_disable << 3) |((uint32_t)ng_target << 1) |((uint32_t)enable << 0));
}

__INLINE void modem_bf_depack_dyn_4_unpack(uint8_t* mcci_disable, uint8_t* ng_target, uint8_t* enable)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_4_ADDR);

	*mcci_disable = (localVal & ((uint32_t)0x00000008)) >>  3;
	*ng_target = (localVal & ((uint32_t)0x00000006)) >>  1;
	*enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_depack_dyn_4_mcci_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void modem_bf_depack_dyn_4_mcci_disable_setf(uint8_t mccidisable)
{
	ASSERT_ERR((((uint32_t)mccidisable << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_4_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_4_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)mccidisable <<3));
}
__INLINE uint8_t modem_bf_depack_dyn_4_ng_target_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void modem_bf_depack_dyn_4_ng_target_setf(uint8_t ngtarget)
{
	ASSERT_ERR((((uint32_t)ngtarget << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_4_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_4_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)ngtarget <<1));
}
__INLINE uint8_t modem_bf_depack_dyn_4_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_4_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void modem_bf_depack_dyn_4_enable_setf(uint8_t enable)
{
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_4_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_4_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enable <<0));
}

/**
 * @brief DEPACK_SRC_ADDR_5 register definition
 *  Config 5 address for input header register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 src_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_SRC_ADDR_5_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000100)
#define MODEM_BF_DEPACK_SRC_ADDR_5_OFFSET      0x00000100
#define MODEM_BF_DEPACK_SRC_ADDR_5_INDEX       0x00000040
#define MODEM_BF_DEPACK_SRC_ADDR_5_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_src_addr_5_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_5_ADDR);
}

__INLINE void modem_bf_depack_src_addr_5_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_5_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_SRC_ADDR_5_SRC_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_SRC_ADDR_5_SRC_ADDR_LSB    0
#define MODEM_BF_DEPACK_SRC_ADDR_5_SRC_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_SRC_ADDR_5_SRC_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_src_addr_5_src_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_5_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_src_addr_5_src_addr_setf(uint16_t srcaddr)
{
	ASSERT_ERR((((uint32_t)srcaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_5_ADDR, (uint32_t)srcaddr << 0);
}

/**
 * @brief DEPACK_DST_ADDR_5 register definition
 *  Config 5 destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_ADDR_5_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000104)
#define MODEM_BF_DEPACK_DST_ADDR_5_OFFSET      0x00000104
#define MODEM_BF_DEPACK_DST_ADDR_5_INDEX       0x00000041
#define MODEM_BF_DEPACK_DST_ADDR_5_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_addr_5_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_5_ADDR);
}

__INLINE void modem_bf_depack_dst_addr_5_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_5_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_ADDR_5_DST_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_ADDR_5_DST_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_ADDR_5_DST_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_ADDR_5_DST_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_addr_5_dst_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_5_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_addr_5_dst_addr_setf(uint16_t dstaddr)
{
	ASSERT_ERR((((uint32_t)dstaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_5_ADDR, (uint32_t)dstaddr << 0);
}

/**
 * @brief DEPACK_DST_SNR_ADDR_5 register definition
 *  Config 5 DSNR destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_snr_addr              0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_SNR_ADDR_5_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000108)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_5_OFFSET      0x00000108
#define MODEM_BF_DEPACK_DST_SNR_ADDR_5_INDEX       0x00000042
#define MODEM_BF_DEPACK_DST_SNR_ADDR_5_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_snr_addr_5_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_5_ADDR);
}

__INLINE void modem_bf_depack_dst_snr_addr_5_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_5_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_SNR_ADDR_5_DST_SNR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_5_DST_SNR_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_SNR_ADDR_5_DST_SNR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_SNR_ADDR_5_DST_SNR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_snr_addr_5_dst_snr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_5_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_snr_addr_5_dst_snr_addr_setf(uint16_t dstsnraddr)
{
	ASSERT_ERR((((uint32_t)dstsnraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_5_ADDR, (uint32_t)dstsnraddr << 0);
}

/**
 * @brief DEPACK_HDR_ADDR_5 register definition
 *  Config 5 output header address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 hdr_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_HDR_ADDR_5_ADDR        (REG_MODEM_BF_BASE_ADDR+0x0000010C)
#define MODEM_BF_DEPACK_HDR_ADDR_5_OFFSET      0x0000010C
#define MODEM_BF_DEPACK_HDR_ADDR_5_INDEX       0x00000043
#define MODEM_BF_DEPACK_HDR_ADDR_5_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_hdr_addr_5_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_5_ADDR);
}

__INLINE void modem_bf_depack_hdr_addr_5_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_5_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_HDR_ADDR_5_HDR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_HDR_ADDR_5_HDR_ADDR_LSB    0
#define MODEM_BF_DEPACK_HDR_ADDR_5_HDR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_HDR_ADDR_5_HDR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_hdr_addr_5_hdr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_5_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_hdr_addr_5_hdr_addr_setf(uint16_t hdraddr)
{
	ASSERT_ERR((((uint32_t)hdraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_5_ADDR, (uint32_t)hdraddr << 0);
}

/**
 * @brief DEPACK_MCCI_ADDR_5 register definition
 *  Config 5 MCCI message address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mcci_addr                 0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_MCCI_ADDR_5_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000110)
#define MODEM_BF_DEPACK_MCCI_ADDR_5_OFFSET      0x00000110
#define MODEM_BF_DEPACK_MCCI_ADDR_5_INDEX       0x00000044
#define MODEM_BF_DEPACK_MCCI_ADDR_5_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_mcci_addr_5_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_5_ADDR);
}

__INLINE void modem_bf_depack_mcci_addr_5_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_5_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_MCCI_ADDR_5_MCCI_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MODEM_BF_DEPACK_MCCI_ADDR_5_MCCI_ADDR_LSB    0
#define MODEM_BF_DEPACK_MCCI_ADDR_5_MCCI_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MODEM_BF_DEPACK_MCCI_ADDR_5_MCCI_ADDR_RST    0x0

__INLINE uint32_t modem_bf_depack_mcci_addr_5_mcci_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_5_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_mcci_addr_5_mcci_addr_setf(uint32_t mcciaddr)
{
	ASSERT_ERR((((uint32_t)mcciaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_5_ADDR, (uint32_t)mcciaddr << 0);
}

/**
 * @brief DEPACK_DYN_5 register definition
 *  Config 5 dynamic configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    mcci_disable              0              
 *    02:01 ng_target                 0x0
 *    00    enable                    0              
 * </pre>
 */
#define MODEM_BF_DEPACK_DYN_5_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000114)
#define MODEM_BF_DEPACK_DYN_5_OFFSET      0x00000114
#define MODEM_BF_DEPACK_DYN_5_INDEX       0x00000045
#define MODEM_BF_DEPACK_DYN_5_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dyn_5_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DYN_5_ADDR);
}

__INLINE void modem_bf_depack_dyn_5_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DYN_5_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DYN_5_MCCI_DISABLE_BIT    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_DYN_5_MCCI_DISABLE_POS    3
#define MODEM_BF_DEPACK_DYN_5_NG_TARGET_MASK    ((uint32_t)0x00000006)
#define MODEM_BF_DEPACK_DYN_5_NG_TARGET_LSB    1
#define MODEM_BF_DEPACK_DYN_5_NG_TARGET_WIDTH    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_DYN_5_ENABLE_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_DEPACK_DYN_5_ENABLE_POS    0

#define MODEM_BF_DEPACK_DYN_5_MCCI_DISABLE_RST    0x0
#define MODEM_BF_DEPACK_DYN_5_NG_TARGET_RST    0x0
#define MODEM_BF_DEPACK_DYN_5_ENABLE_RST    0x0

__INLINE void modem_bf_depack_dyn_5_pack(uint8_t mcci_disable, uint8_t ng_target, uint8_t enable)
{
	ASSERT_ERR((((uint32_t)mcci_disable << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)ng_target << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_5_ADDR,  ((uint32_t)mcci_disable << 3) |((uint32_t)ng_target << 1) |((uint32_t)enable << 0));
}

__INLINE void modem_bf_depack_dyn_5_unpack(uint8_t* mcci_disable, uint8_t* ng_target, uint8_t* enable)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_5_ADDR);

	*mcci_disable = (localVal & ((uint32_t)0x00000008)) >>  3;
	*ng_target = (localVal & ((uint32_t)0x00000006)) >>  1;
	*enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_depack_dyn_5_mcci_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void modem_bf_depack_dyn_5_mcci_disable_setf(uint8_t mccidisable)
{
	ASSERT_ERR((((uint32_t)mccidisable << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_5_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_5_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)mccidisable <<3));
}
__INLINE uint8_t modem_bf_depack_dyn_5_ng_target_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void modem_bf_depack_dyn_5_ng_target_setf(uint8_t ngtarget)
{
	ASSERT_ERR((((uint32_t)ngtarget << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_5_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_5_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)ngtarget <<1));
}
__INLINE uint8_t modem_bf_depack_dyn_5_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void modem_bf_depack_dyn_5_enable_setf(uint8_t enable)
{
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_5_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_5_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enable <<0));
}

/**
 * @brief DEPACK_SRC_ADDR_6 register definition
 *  Config 6 address for input header register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 src_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_SRC_ADDR_6_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000120)
#define MODEM_BF_DEPACK_SRC_ADDR_6_OFFSET      0x00000120
#define MODEM_BF_DEPACK_SRC_ADDR_6_INDEX       0x00000048
#define MODEM_BF_DEPACK_SRC_ADDR_6_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_src_addr_6_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_6_ADDR);
}

__INLINE void modem_bf_depack_src_addr_6_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_6_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_SRC_ADDR_6_SRC_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_SRC_ADDR_6_SRC_ADDR_LSB    0
#define MODEM_BF_DEPACK_SRC_ADDR_6_SRC_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_SRC_ADDR_6_SRC_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_src_addr_6_src_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_6_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_src_addr_6_src_addr_setf(uint16_t srcaddr)
{
	ASSERT_ERR((((uint32_t)srcaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_6_ADDR, (uint32_t)srcaddr << 0);
}

/**
 * @brief DEPACK_DST_ADDR_6 register definition
 *  Config 6 destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_ADDR_6_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000124)
#define MODEM_BF_DEPACK_DST_ADDR_6_OFFSET      0x00000124
#define MODEM_BF_DEPACK_DST_ADDR_6_INDEX       0x00000049
#define MODEM_BF_DEPACK_DST_ADDR_6_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_addr_6_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_6_ADDR);
}

__INLINE void modem_bf_depack_dst_addr_6_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_6_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_ADDR_6_DST_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_ADDR_6_DST_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_ADDR_6_DST_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_ADDR_6_DST_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_addr_6_dst_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_6_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_addr_6_dst_addr_setf(uint16_t dstaddr)
{
	ASSERT_ERR((((uint32_t)dstaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_6_ADDR, (uint32_t)dstaddr << 0);
}

/**
 * @brief DEPACK_DST_SNR_ADDR_6 register definition
 *  Config 6 DSNR destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_snr_addr              0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_SNR_ADDR_6_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000128)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_6_OFFSET      0x00000128
#define MODEM_BF_DEPACK_DST_SNR_ADDR_6_INDEX       0x0000004A
#define MODEM_BF_DEPACK_DST_SNR_ADDR_6_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_snr_addr_6_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_6_ADDR);
}

__INLINE void modem_bf_depack_dst_snr_addr_6_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_6_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_SNR_ADDR_6_DST_SNR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_6_DST_SNR_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_SNR_ADDR_6_DST_SNR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_SNR_ADDR_6_DST_SNR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_snr_addr_6_dst_snr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_6_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_snr_addr_6_dst_snr_addr_setf(uint16_t dstsnraddr)
{
	ASSERT_ERR((((uint32_t)dstsnraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_6_ADDR, (uint32_t)dstsnraddr << 0);
}

/**
 * @brief DEPACK_HDR_ADDR_6 register definition
 *  Config 6 output header address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 hdr_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_HDR_ADDR_6_ADDR        (REG_MODEM_BF_BASE_ADDR+0x0000012C)
#define MODEM_BF_DEPACK_HDR_ADDR_6_OFFSET      0x0000012C
#define MODEM_BF_DEPACK_HDR_ADDR_6_INDEX       0x0000004B
#define MODEM_BF_DEPACK_HDR_ADDR_6_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_hdr_addr_6_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_6_ADDR);
}

__INLINE void modem_bf_depack_hdr_addr_6_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_6_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_HDR_ADDR_6_HDR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_HDR_ADDR_6_HDR_ADDR_LSB    0
#define MODEM_BF_DEPACK_HDR_ADDR_6_HDR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_HDR_ADDR_6_HDR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_hdr_addr_6_hdr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_6_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_hdr_addr_6_hdr_addr_setf(uint16_t hdraddr)
{
	ASSERT_ERR((((uint32_t)hdraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_6_ADDR, (uint32_t)hdraddr << 0);
}

/**
 * @brief DEPACK_MCCI_ADDR_6 register definition
 *  Config 6 MCCI message address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mcci_addr                 0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_MCCI_ADDR_6_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000130)
#define MODEM_BF_DEPACK_MCCI_ADDR_6_OFFSET      0x00000130
#define MODEM_BF_DEPACK_MCCI_ADDR_6_INDEX       0x0000004C
#define MODEM_BF_DEPACK_MCCI_ADDR_6_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_mcci_addr_6_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_6_ADDR);
}

__INLINE void modem_bf_depack_mcci_addr_6_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_6_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_MCCI_ADDR_6_MCCI_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MODEM_BF_DEPACK_MCCI_ADDR_6_MCCI_ADDR_LSB    0
#define MODEM_BF_DEPACK_MCCI_ADDR_6_MCCI_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MODEM_BF_DEPACK_MCCI_ADDR_6_MCCI_ADDR_RST    0x0

__INLINE uint32_t modem_bf_depack_mcci_addr_6_mcci_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_6_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_mcci_addr_6_mcci_addr_setf(uint32_t mcciaddr)
{
	ASSERT_ERR((((uint32_t)mcciaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_6_ADDR, (uint32_t)mcciaddr << 0);
}

/**
 * @brief DEPACK_DYN_6 register definition
 *  Config 6 dynamic configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    mcci_disable              0              
 *    02:01 ng_target                 0x0
 *    00    enable                    0              
 * </pre>
 */
#define MODEM_BF_DEPACK_DYN_6_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000134)
#define MODEM_BF_DEPACK_DYN_6_OFFSET      0x00000134
#define MODEM_BF_DEPACK_DYN_6_INDEX       0x0000004D
#define MODEM_BF_DEPACK_DYN_6_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dyn_6_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DYN_6_ADDR);
}

__INLINE void modem_bf_depack_dyn_6_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DYN_6_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DYN_6_MCCI_DISABLE_BIT    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_DYN_6_MCCI_DISABLE_POS    3
#define MODEM_BF_DEPACK_DYN_6_NG_TARGET_MASK    ((uint32_t)0x00000006)
#define MODEM_BF_DEPACK_DYN_6_NG_TARGET_LSB    1
#define MODEM_BF_DEPACK_DYN_6_NG_TARGET_WIDTH    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_DYN_6_ENABLE_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_DEPACK_DYN_6_ENABLE_POS    0

#define MODEM_BF_DEPACK_DYN_6_MCCI_DISABLE_RST    0x0
#define MODEM_BF_DEPACK_DYN_6_NG_TARGET_RST    0x0
#define MODEM_BF_DEPACK_DYN_6_ENABLE_RST    0x0

__INLINE void modem_bf_depack_dyn_6_pack(uint8_t mcci_disable, uint8_t ng_target, uint8_t enable)
{
	ASSERT_ERR((((uint32_t)mcci_disable << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)ng_target << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_6_ADDR,  ((uint32_t)mcci_disable << 3) |((uint32_t)ng_target << 1) |((uint32_t)enable << 0));
}

__INLINE void modem_bf_depack_dyn_6_unpack(uint8_t* mcci_disable, uint8_t* ng_target, uint8_t* enable)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_6_ADDR);

	*mcci_disable = (localVal & ((uint32_t)0x00000008)) >>  3;
	*ng_target = (localVal & ((uint32_t)0x00000006)) >>  1;
	*enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_depack_dyn_6_mcci_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void modem_bf_depack_dyn_6_mcci_disable_setf(uint8_t mccidisable)
{
	ASSERT_ERR((((uint32_t)mccidisable << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_6_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_6_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)mccidisable <<3));
}
__INLINE uint8_t modem_bf_depack_dyn_6_ng_target_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void modem_bf_depack_dyn_6_ng_target_setf(uint8_t ngtarget)
{
	ASSERT_ERR((((uint32_t)ngtarget << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_6_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_6_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)ngtarget <<1));
}
__INLINE uint8_t modem_bf_depack_dyn_6_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_6_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void modem_bf_depack_dyn_6_enable_setf(uint8_t enable)
{
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_6_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_6_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enable <<0));
}

/**
 * @brief DEPACK_SRC_ADDR_7 register definition
 *  Config 7 address for input header register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 src_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_SRC_ADDR_7_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000140)
#define MODEM_BF_DEPACK_SRC_ADDR_7_OFFSET      0x00000140
#define MODEM_BF_DEPACK_SRC_ADDR_7_INDEX       0x00000050
#define MODEM_BF_DEPACK_SRC_ADDR_7_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_src_addr_7_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_7_ADDR);
}

__INLINE void modem_bf_depack_src_addr_7_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_7_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_SRC_ADDR_7_SRC_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_SRC_ADDR_7_SRC_ADDR_LSB    0
#define MODEM_BF_DEPACK_SRC_ADDR_7_SRC_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_SRC_ADDR_7_SRC_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_src_addr_7_src_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_SRC_ADDR_7_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_src_addr_7_src_addr_setf(uint16_t srcaddr)
{
	ASSERT_ERR((((uint32_t)srcaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_SRC_ADDR_7_ADDR, (uint32_t)srcaddr << 0);
}

/**
 * @brief DEPACK_DST_ADDR_7 register definition
 *  Config 7 destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_ADDR_7_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000144)
#define MODEM_BF_DEPACK_DST_ADDR_7_OFFSET      0x00000144
#define MODEM_BF_DEPACK_DST_ADDR_7_INDEX       0x00000051
#define MODEM_BF_DEPACK_DST_ADDR_7_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_addr_7_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_7_ADDR);
}

__INLINE void modem_bf_depack_dst_addr_7_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_7_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_ADDR_7_DST_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_ADDR_7_DST_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_ADDR_7_DST_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_ADDR_7_DST_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_addr_7_dst_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_ADDR_7_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_addr_7_dst_addr_setf(uint16_t dstaddr)
{
	ASSERT_ERR((((uint32_t)dstaddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_ADDR_7_ADDR, (uint32_t)dstaddr << 0);
}

/**
 * @brief DEPACK_DST_SNR_ADDR_7 register definition
 *  Config 7 DSNR destination address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 dst_snr_addr              0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_DST_SNR_ADDR_7_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000148)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_7_OFFSET      0x00000148
#define MODEM_BF_DEPACK_DST_SNR_ADDR_7_INDEX       0x00000052
#define MODEM_BF_DEPACK_DST_SNR_ADDR_7_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dst_snr_addr_7_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_7_ADDR);
}

__INLINE void modem_bf_depack_dst_snr_addr_7_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_7_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DST_SNR_ADDR_7_DST_SNR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_DST_SNR_ADDR_7_DST_SNR_ADDR_LSB    0
#define MODEM_BF_DEPACK_DST_SNR_ADDR_7_DST_SNR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_DST_SNR_ADDR_7_DST_SNR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_dst_snr_addr_7_dst_snr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DST_SNR_ADDR_7_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_dst_snr_addr_7_dst_snr_addr_setf(uint16_t dstsnraddr)
{
	ASSERT_ERR((((uint32_t)dstsnraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DST_SNR_ADDR_7_ADDR, (uint32_t)dstsnraddr << 0);
}

/**
 * @brief DEPACK_HDR_ADDR_7 register definition
 *  Config 7 output header address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 hdr_addr                  0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_HDR_ADDR_7_ADDR        (REG_MODEM_BF_BASE_ADDR+0x0000014C)
#define MODEM_BF_DEPACK_HDR_ADDR_7_OFFSET      0x0000014C
#define MODEM_BF_DEPACK_HDR_ADDR_7_INDEX       0x00000053
#define MODEM_BF_DEPACK_HDR_ADDR_7_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_hdr_addr_7_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_7_ADDR);
}

__INLINE void modem_bf_depack_hdr_addr_7_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_7_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_HDR_ADDR_7_HDR_ADDR_MASK    ((uint32_t)0x0000FFFF)
#define MODEM_BF_DEPACK_HDR_ADDR_7_HDR_ADDR_LSB    0
#define MODEM_BF_DEPACK_HDR_ADDR_7_HDR_ADDR_WIDTH    ((uint32_t)0x00000010)

#define MODEM_BF_DEPACK_HDR_ADDR_7_HDR_ADDR_RST    0x0

__INLINE uint16_t modem_bf_depack_hdr_addr_7_hdr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_HDR_ADDR_7_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_hdr_addr_7_hdr_addr_setf(uint16_t hdraddr)
{
	ASSERT_ERR((((uint32_t)hdraddr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_HDR_ADDR_7_ADDR, (uint32_t)hdraddr << 0);
}

/**
 * @brief DEPACK_MCCI_ADDR_7 register definition
 *  Config 7 MCCI message address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 mcci_addr                 0x0
 * </pre>
 */
#define MODEM_BF_DEPACK_MCCI_ADDR_7_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000150)
#define MODEM_BF_DEPACK_MCCI_ADDR_7_OFFSET      0x00000150
#define MODEM_BF_DEPACK_MCCI_ADDR_7_INDEX       0x00000054
#define MODEM_BF_DEPACK_MCCI_ADDR_7_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_mcci_addr_7_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_7_ADDR);
}

__INLINE void modem_bf_depack_mcci_addr_7_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_7_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_MCCI_ADDR_7_MCCI_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MODEM_BF_DEPACK_MCCI_ADDR_7_MCCI_ADDR_LSB    0
#define MODEM_BF_DEPACK_MCCI_ADDR_7_MCCI_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MODEM_BF_DEPACK_MCCI_ADDR_7_MCCI_ADDR_RST    0x0

__INLINE uint32_t modem_bf_depack_mcci_addr_7_mcci_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_MCCI_ADDR_7_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void modem_bf_depack_mcci_addr_7_mcci_addr_setf(uint32_t mcciaddr)
{
	ASSERT_ERR((((uint32_t)mcciaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_MCCI_ADDR_7_ADDR, (uint32_t)mcciaddr << 0);
}

/**
 * @brief DEPACK_DYN_7 register definition
 *  Config 7 dynamic configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    mcci_disable              0              
 *    02:01 ng_target                 0x0
 *    00    enable                    0              
 * </pre>
 */
#define MODEM_BF_DEPACK_DYN_7_ADDR        (REG_MODEM_BF_BASE_ADDR+0x00000154)
#define MODEM_BF_DEPACK_DYN_7_OFFSET      0x00000154
#define MODEM_BF_DEPACK_DYN_7_INDEX       0x00000055
#define MODEM_BF_DEPACK_DYN_7_RESET       0x00000000

__INLINE uint32_t  modem_bf_depack_dyn_7_get(void)
{
	return REG_PL_RD(MODEM_BF_DEPACK_DYN_7_ADDR);
}

__INLINE void modem_bf_depack_dyn_7_set(uint32_t value)
{
	REG_PL_WR(MODEM_BF_DEPACK_DYN_7_ADDR, value);
}

// field definitions
#define MODEM_BF_DEPACK_DYN_7_MCCI_DISABLE_BIT    ((uint32_t)0x00000008)
#define MODEM_BF_DEPACK_DYN_7_MCCI_DISABLE_POS    3
#define MODEM_BF_DEPACK_DYN_7_NG_TARGET_MASK    ((uint32_t)0x00000006)
#define MODEM_BF_DEPACK_DYN_7_NG_TARGET_LSB    1
#define MODEM_BF_DEPACK_DYN_7_NG_TARGET_WIDTH    ((uint32_t)0x00000002)
#define MODEM_BF_DEPACK_DYN_7_ENABLE_BIT    ((uint32_t)0x00000001)
#define MODEM_BF_DEPACK_DYN_7_ENABLE_POS    0

#define MODEM_BF_DEPACK_DYN_7_MCCI_DISABLE_RST    0x0
#define MODEM_BF_DEPACK_DYN_7_NG_TARGET_RST    0x0
#define MODEM_BF_DEPACK_DYN_7_ENABLE_RST    0x0

__INLINE void modem_bf_depack_dyn_7_pack(uint8_t mcci_disable, uint8_t ng_target, uint8_t enable)
{
	ASSERT_ERR((((uint32_t)mcci_disable << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)ng_target << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_7_ADDR,  ((uint32_t)mcci_disable << 3) |((uint32_t)ng_target << 1) |((uint32_t)enable << 0));
}

__INLINE void modem_bf_depack_dyn_7_unpack(uint8_t* mcci_disable, uint8_t* ng_target, uint8_t* enable)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_7_ADDR);

	*mcci_disable = (localVal & ((uint32_t)0x00000008)) >>  3;
	*ng_target = (localVal & ((uint32_t)0x00000006)) >>  1;
	*enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t modem_bf_depack_dyn_7_mcci_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void modem_bf_depack_dyn_7_mcci_disable_setf(uint8_t mccidisable)
{
	ASSERT_ERR((((uint32_t)mccidisable << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_7_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_7_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)mccidisable <<3));
}
__INLINE uint8_t modem_bf_depack_dyn_7_ng_target_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void modem_bf_depack_dyn_7_ng_target_setf(uint8_t ngtarget)
{
	ASSERT_ERR((((uint32_t)ngtarget << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_7_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_7_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)ngtarget <<1));
}
__INLINE uint8_t modem_bf_depack_dyn_7_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MODEM_BF_DEPACK_DYN_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void modem_bf_depack_dyn_7_enable_setf(uint8_t enable)
{
	ASSERT_ERR((((uint32_t)enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MODEM_BF_DEPACK_DYN_7_ADDR, (REG_PL_RD(MODEM_BF_DEPACK_DYN_7_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)enable <<0));
}


#undef DBG_FILEID
#endif //_REG_MODEM_BF_H_
