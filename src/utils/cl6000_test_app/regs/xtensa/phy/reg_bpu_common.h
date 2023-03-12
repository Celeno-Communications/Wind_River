#ifndef _REG_BPU_COMMON_H_
#define _REG_BPU_COMMON_H_

#include <stdint.h>
#include "phy/_reg_bpu_common.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_BPU_COMMON__H__FILEID__

#define REG_BPU_COMMON_COUNT  21


/**
 * @brief VERSION register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 VERSION                   0x0
 * </pre>
 */
#define BPU_COMMON_VERSION_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000000)
#define BPU_COMMON_VERSION_OFFSET      0x00000000
#define BPU_COMMON_VERSION_INDEX       0x00000000
#define BPU_COMMON_VERSION_RESET       0x00000000

__INLINE uint32_t  bpu_common_version_get(void)
{
	return REG_PL_RD(BPU_COMMON_VERSION_ADDR);
}

// field definitions
#define BPU_COMMON_VERSION_VERSION_MASK     ((uint32_t)0xFFFFFFFF)
#define BPU_COMMON_VERSION_VERSION_LSB      0
#define BPU_COMMON_VERSION_VERSION_WIDTH    ((uint32_t)0x00000020)

#define BPU_COMMON_VERSION_VERSION_RST      0x0

__INLINE uint32_t bpu_common_version_version_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_VERSION_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief ENABLE register definition
 *  Tx or Rx enable bits per user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:08 RXEN                      0x0
 *    07:00 TXEN                      0x0
 * </pre>
 */
#define BPU_COMMON_ENABLE_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000004)
#define BPU_COMMON_ENABLE_OFFSET      0x00000004
#define BPU_COMMON_ENABLE_INDEX       0x00000001
#define BPU_COMMON_ENABLE_RESET       0x00000000

__INLINE uint32_t  bpu_common_enable_get(void)
{
	return REG_PL_RD(BPU_COMMON_ENABLE_ADDR);
}

__INLINE void bpu_common_enable_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_ENABLE_ADDR, value);
}

// field definitions
#define BPU_COMMON_ENABLE_RXEN_MASK         ((uint32_t)0x0000FF00)
#define BPU_COMMON_ENABLE_RXEN_LSB          8
#define BPU_COMMON_ENABLE_RXEN_WIDTH        ((uint32_t)0x00000008)
#define BPU_COMMON_ENABLE_TXEN_MASK         ((uint32_t)0x000000FF)
#define BPU_COMMON_ENABLE_TXEN_LSB          0
#define BPU_COMMON_ENABLE_TXEN_WIDTH        ((uint32_t)0x00000008)

#define BPU_COMMON_ENABLE_RXEN_RST          0x0
#define BPU_COMMON_ENABLE_TXEN_RST          0x0

__INLINE void bpu_common_enable_pack(uint8_t rxen, uint8_t txen)
{
	ASSERT_ERR((((uint32_t)rxen << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)txen << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BPU_COMMON_ENABLE_ADDR,  ((uint32_t)rxen << 8) |((uint32_t)txen << 0));
}

__INLINE void bpu_common_enable_unpack(uint8_t* rxen, uint8_t* txen)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_ENABLE_ADDR);

	*rxen = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*txen = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t bpu_common_enable_rxen_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_ENABLE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void bpu_common_enable_rxen_setf(uint8_t rxen)
{
	ASSERT_ERR((((uint32_t)rxen << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(BPU_COMMON_ENABLE_ADDR, (REG_PL_RD(BPU_COMMON_ENABLE_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)rxen <<8));
}
__INLINE uint8_t bpu_common_enable_txen_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_ENABLE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void bpu_common_enable_txen_setf(uint8_t txen)
{
	ASSERT_ERR((((uint32_t)txen << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BPU_COMMON_ENABLE_ADDR, (REG_PL_RD(BPU_COMMON_ENABLE_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)txen <<0));
}

/**
 * @brief CONFIG_0 register definition
 *  BPU configuration register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08:07 TX_SYMBOL_GEN_MODE        0x0
 *    06    VHT_SEG_PARSER_EN         0              
 *    05    DISABLE_FIC_MESS          0              
 *    04:01 MODE                      0x0
 *    00    SCRAM_EN                  0              
 * </pre>
 */
#define BPU_COMMON_CONFIG_0_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000008)
#define BPU_COMMON_CONFIG_0_OFFSET      0x00000008
#define BPU_COMMON_CONFIG_0_INDEX       0x00000002
#define BPU_COMMON_CONFIG_0_RESET       0x00000000

__INLINE uint32_t  bpu_common_config_0_get(void)
{
	return REG_PL_RD(BPU_COMMON_CONFIG_0_ADDR);
}

__INLINE void bpu_common_config_0_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_CONFIG_0_ADDR, value);
}

// field definitions
#define BPU_COMMON_CONFIG_0_TX_SYMBOL_GEN_MODE_MASK    ((uint32_t)0x00000180)
#define BPU_COMMON_CONFIG_0_TX_SYMBOL_GEN_MODE_LSB    7
#define BPU_COMMON_CONFIG_0_TX_SYMBOL_GEN_MODE_WIDTH    ((uint32_t)0x00000002)
#define BPU_COMMON_CONFIG_0_VHT_SEG_PARSER_EN_BIT    ((uint32_t)0x00000040)
#define BPU_COMMON_CONFIG_0_VHT_SEG_PARSER_EN_POS    6
#define BPU_COMMON_CONFIG_0_DISABLE_FIC_MESS_BIT    ((uint32_t)0x00000020)
#define BPU_COMMON_CONFIG_0_DISABLE_FIC_MESS_POS    5
#define BPU_COMMON_CONFIG_0_MODE_MASK       ((uint32_t)0x0000001E)
#define BPU_COMMON_CONFIG_0_MODE_LSB        1
#define BPU_COMMON_CONFIG_0_MODE_WIDTH      ((uint32_t)0x00000004)
#define BPU_COMMON_CONFIG_0_SCRAM_EN_BIT    ((uint32_t)0x00000001)
#define BPU_COMMON_CONFIG_0_SCRAM_EN_POS    0

#define BPU_COMMON_CONFIG_0_TX_SYMBOL_GEN_MODE_RST    0x0
#define BPU_COMMON_CONFIG_0_VHT_SEG_PARSER_EN_RST    0x0
#define BPU_COMMON_CONFIG_0_DISABLE_FIC_MESS_RST    0x0
#define BPU_COMMON_CONFIG_0_MODE_RST        0x0
#define BPU_COMMON_CONFIG_0_SCRAM_EN_RST    0x0

__INLINE void bpu_common_config_0_pack(uint8_t tx_symbol_gen_mode, uint8_t vht_seg_parser_en, uint8_t disable_fic_mess, uint8_t mode, uint8_t scram_en)
{
	ASSERT_ERR((((uint32_t)tx_symbol_gen_mode << 7) & ~((uint32_t)0x00000180)) == 0);
	ASSERT_ERR((((uint32_t)vht_seg_parser_en << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)disable_fic_mess << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)mode << 1) & ~((uint32_t)0x0000001E)) == 0);
	ASSERT_ERR((((uint32_t)scram_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BPU_COMMON_CONFIG_0_ADDR,  ((uint32_t)tx_symbol_gen_mode << 7) |((uint32_t)vht_seg_parser_en << 6) |((uint32_t)disable_fic_mess << 5) |((uint32_t)mode << 1) |((uint32_t)scram_en << 0));
}

__INLINE void bpu_common_config_0_unpack(uint8_t* tx_symbol_gen_mode, uint8_t* vht_seg_parser_en, uint8_t* disable_fic_mess, uint8_t* mode, uint8_t* scram_en)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CONFIG_0_ADDR);

	*tx_symbol_gen_mode = (localVal & ((uint32_t)0x00000180)) >>  7;
	*vht_seg_parser_en = (localVal & ((uint32_t)0x00000040)) >>  6;
	*disable_fic_mess = (localVal & ((uint32_t)0x00000020)) >>  5;
	*mode = (localVal & ((uint32_t)0x0000001E)) >>  1;
	*scram_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t bpu_common_config_0_tx_symbol_gen_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000180)) >> 7);
}
__INLINE void bpu_common_config_0_tx_symbol_gen_mode_setf(uint8_t txsymbolgenmode)
{
	ASSERT_ERR((((uint32_t)txsymbolgenmode << 7) & ~((uint32_t)0x00000180)) == 0);
	REG_PL_WR(BPU_COMMON_CONFIG_0_ADDR, (REG_PL_RD(BPU_COMMON_CONFIG_0_ADDR) & ~((uint32_t)0x00000180)) | ((uint32_t)txsymbolgenmode <<7));
}
__INLINE uint8_t bpu_common_config_0_vht_seg_parser_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void bpu_common_config_0_vht_seg_parser_en_setf(uint8_t vhtsegparseren)
{
	ASSERT_ERR((((uint32_t)vhtsegparseren << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(BPU_COMMON_CONFIG_0_ADDR, (REG_PL_RD(BPU_COMMON_CONFIG_0_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)vhtsegparseren <<6));
}
__INLINE uint8_t bpu_common_config_0_disable_fic_mess_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void bpu_common_config_0_disable_fic_mess_setf(uint8_t disableficmess)
{
	ASSERT_ERR((((uint32_t)disableficmess << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(BPU_COMMON_CONFIG_0_ADDR, (REG_PL_RD(BPU_COMMON_CONFIG_0_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)disableficmess <<5));
}
__INLINE uint8_t bpu_common_config_0_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001E)) >> 1);
}
__INLINE void bpu_common_config_0_mode_setf(uint8_t mode)
{
	ASSERT_ERR((((uint32_t)mode << 1) & ~((uint32_t)0x0000001E)) == 0);
	REG_PL_WR(BPU_COMMON_CONFIG_0_ADDR, (REG_PL_RD(BPU_COMMON_CONFIG_0_ADDR) & ~((uint32_t)0x0000001E)) | ((uint32_t)mode <<1));
}
__INLINE uint8_t bpu_common_config_0_scram_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CONFIG_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void bpu_common_config_0_scram_en_setf(uint8_t scramen)
{
	ASSERT_ERR((((uint32_t)scramen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BPU_COMMON_CONFIG_0_ADDR, (REG_PL_RD(BPU_COMMON_CONFIG_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)scramen <<0));
}

/**
 * @brief CONFIG_BPL register definition
 *  BPUL parameters register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    DISABLE_TONE_DE_MAP       0              
 *    02    LDPC_CW_FIFO_BYP          0              
 *    00    LDPC_SIGN                 0              
 * </pre>
 */
#define BPU_COMMON_CONFIG_BPL_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x0000000C)
#define BPU_COMMON_CONFIG_BPL_OFFSET      0x0000000C
#define BPU_COMMON_CONFIG_BPL_INDEX       0x00000003
#define BPU_COMMON_CONFIG_BPL_RESET       0x00000000

__INLINE uint32_t  bpu_common_config_bpl_get(void)
{
	return REG_PL_RD(BPU_COMMON_CONFIG_BPL_ADDR);
}

__INLINE void bpu_common_config_bpl_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_CONFIG_BPL_ADDR, value);
}

// field definitions
#define BPU_COMMON_CONFIG_BPL_DISABLE_TONE_DE_MAP_BIT    ((uint32_t)0x00000008)
#define BPU_COMMON_CONFIG_BPL_DISABLE_TONE_DE_MAP_POS    3
#define BPU_COMMON_CONFIG_BPL_LDPC_CW_FIFO_BYP_BIT    ((uint32_t)0x00000004)
#define BPU_COMMON_CONFIG_BPL_LDPC_CW_FIFO_BYP_POS    2
#define BPU_COMMON_CONFIG_BPL_LDPC_SIGN_BIT    ((uint32_t)0x00000001)
#define BPU_COMMON_CONFIG_BPL_LDPC_SIGN_POS    0

#define BPU_COMMON_CONFIG_BPL_DISABLE_TONE_DE_MAP_RST    0x0
#define BPU_COMMON_CONFIG_BPL_LDPC_CW_FIFO_BYP_RST    0x0
#define BPU_COMMON_CONFIG_BPL_LDPC_SIGN_RST    0x0

__INLINE void bpu_common_config_bpl_pack(uint8_t disable_tone_de_map, uint8_t ldpc_cw_fifo_byp, uint8_t ldpc_sign)
{
	ASSERT_ERR((((uint32_t)disable_tone_de_map << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)ldpc_cw_fifo_byp << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)ldpc_sign << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BPU_COMMON_CONFIG_BPL_ADDR,  ((uint32_t)disable_tone_de_map << 3) |((uint32_t)ldpc_cw_fifo_byp << 2) |((uint32_t)ldpc_sign << 0));
}

__INLINE void bpu_common_config_bpl_unpack(uint8_t* disable_tone_de_map, uint8_t* ldpc_cw_fifo_byp, uint8_t* ldpc_sign)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CONFIG_BPL_ADDR);

	*disable_tone_de_map = (localVal & ((uint32_t)0x00000008)) >>  3;
	*ldpc_cw_fifo_byp = (localVal & ((uint32_t)0x00000004)) >>  2;
	*ldpc_sign = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t bpu_common_config_bpl_disable_tone_de_map_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CONFIG_BPL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void bpu_common_config_bpl_disable_tone_de_map_setf(uint8_t disabletonedemap)
{
	ASSERT_ERR((((uint32_t)disabletonedemap << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(BPU_COMMON_CONFIG_BPL_ADDR, (REG_PL_RD(BPU_COMMON_CONFIG_BPL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)disabletonedemap <<3));
}
__INLINE uint8_t bpu_common_config_bpl_ldpc_cw_fifo_byp_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CONFIG_BPL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void bpu_common_config_bpl_ldpc_cw_fifo_byp_setf(uint8_t ldpccwfifobyp)
{
	ASSERT_ERR((((uint32_t)ldpccwfifobyp << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(BPU_COMMON_CONFIG_BPL_ADDR, (REG_PL_RD(BPU_COMMON_CONFIG_BPL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)ldpccwfifobyp <<2));
}
__INLINE uint8_t bpu_common_config_bpl_ldpc_sign_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CONFIG_BPL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void bpu_common_config_bpl_ldpc_sign_setf(uint8_t ldpcsign)
{
	ASSERT_ERR((((uint32_t)ldpcsign << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BPU_COMMON_CONFIG_BPL_ADDR, (REG_PL_RD(BPU_COMMON_CONFIG_BPL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)ldpcsign <<0));
}

/**
 * @brief MEM_PTR_SYM_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MEM_PTR_SYM_0             0x0
 * </pre>
 */
#define BPU_COMMON_MEM_PTR_SYM_0_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000010)
#define BPU_COMMON_MEM_PTR_SYM_0_OFFSET      0x00000010
#define BPU_COMMON_MEM_PTR_SYM_0_INDEX       0x00000004
#define BPU_COMMON_MEM_PTR_SYM_0_RESET       0x00000000

__INLINE uint32_t  bpu_common_mem_ptr_sym_0_get(void)
{
	return REG_PL_RD(BPU_COMMON_MEM_PTR_SYM_0_ADDR);
}

__INLINE void bpu_common_mem_ptr_sym_0_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_MEM_PTR_SYM_0_ADDR, value);
}

// field definitions
#define BPU_COMMON_MEM_PTR_SYM_0_MEM_PTR_SYM_0_MASK    ((uint32_t)0xFFFFFFFF)
#define BPU_COMMON_MEM_PTR_SYM_0_MEM_PTR_SYM_0_LSB    0
#define BPU_COMMON_MEM_PTR_SYM_0_MEM_PTR_SYM_0_WIDTH    ((uint32_t)0x00000020)

#define BPU_COMMON_MEM_PTR_SYM_0_MEM_PTR_SYM_0_RST    0x0

__INLINE uint32_t bpu_common_mem_ptr_sym_0_mem_ptr_sym_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MEM_PTR_SYM_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bpu_common_mem_ptr_sym_0_mem_ptr_sym_0_setf(uint32_t memptrsym0)
{
	ASSERT_ERR((((uint32_t)memptrsym0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BPU_COMMON_MEM_PTR_SYM_0_ADDR, (uint32_t)memptrsym0 << 0);
}

/**
 * @brief MEM_PTR_SYM_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MEM_PTR_SYM_1             0x0
 * </pre>
 */
#define BPU_COMMON_MEM_PTR_SYM_1_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000014)
#define BPU_COMMON_MEM_PTR_SYM_1_OFFSET      0x00000014
#define BPU_COMMON_MEM_PTR_SYM_1_INDEX       0x00000005
#define BPU_COMMON_MEM_PTR_SYM_1_RESET       0x00000000

__INLINE uint32_t  bpu_common_mem_ptr_sym_1_get(void)
{
	return REG_PL_RD(BPU_COMMON_MEM_PTR_SYM_1_ADDR);
}

__INLINE void bpu_common_mem_ptr_sym_1_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_MEM_PTR_SYM_1_ADDR, value);
}

// field definitions
#define BPU_COMMON_MEM_PTR_SYM_1_MEM_PTR_SYM_1_MASK    ((uint32_t)0xFFFFFFFF)
#define BPU_COMMON_MEM_PTR_SYM_1_MEM_PTR_SYM_1_LSB    0
#define BPU_COMMON_MEM_PTR_SYM_1_MEM_PTR_SYM_1_WIDTH    ((uint32_t)0x00000020)

#define BPU_COMMON_MEM_PTR_SYM_1_MEM_PTR_SYM_1_RST    0x0

__INLINE uint32_t bpu_common_mem_ptr_sym_1_mem_ptr_sym_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MEM_PTR_SYM_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bpu_common_mem_ptr_sym_1_mem_ptr_sym_1_setf(uint32_t memptrsym1)
{
	ASSERT_ERR((((uint32_t)memptrsym1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BPU_COMMON_MEM_PTR_SYM_1_ADDR, (uint32_t)memptrsym1 << 0);
}

/**
 * @brief MEM_PTR_SYM_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MEM_PTR_SYM_2             0x0
 * </pre>
 */
#define BPU_COMMON_MEM_PTR_SYM_2_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000018)
#define BPU_COMMON_MEM_PTR_SYM_2_OFFSET      0x00000018
#define BPU_COMMON_MEM_PTR_SYM_2_INDEX       0x00000006
#define BPU_COMMON_MEM_PTR_SYM_2_RESET       0x00000000

__INLINE uint32_t  bpu_common_mem_ptr_sym_2_get(void)
{
	return REG_PL_RD(BPU_COMMON_MEM_PTR_SYM_2_ADDR);
}

__INLINE void bpu_common_mem_ptr_sym_2_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_MEM_PTR_SYM_2_ADDR, value);
}

// field definitions
#define BPU_COMMON_MEM_PTR_SYM_2_MEM_PTR_SYM_2_MASK    ((uint32_t)0xFFFFFFFF)
#define BPU_COMMON_MEM_PTR_SYM_2_MEM_PTR_SYM_2_LSB    0
#define BPU_COMMON_MEM_PTR_SYM_2_MEM_PTR_SYM_2_WIDTH    ((uint32_t)0x00000020)

#define BPU_COMMON_MEM_PTR_SYM_2_MEM_PTR_SYM_2_RST    0x0

__INLINE uint32_t bpu_common_mem_ptr_sym_2_mem_ptr_sym_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MEM_PTR_SYM_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bpu_common_mem_ptr_sym_2_mem_ptr_sym_2_setf(uint32_t memptrsym2)
{
	ASSERT_ERR((((uint32_t)memptrsym2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BPU_COMMON_MEM_PTR_SYM_2_ADDR, (uint32_t)memptrsym2 << 0);
}

/**
 * @brief MEM_PTR_SYM_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MEM_PTR_SYM_3             0x0
 * </pre>
 */
#define BPU_COMMON_MEM_PTR_SYM_3_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x0000001C)
#define BPU_COMMON_MEM_PTR_SYM_3_OFFSET      0x0000001C
#define BPU_COMMON_MEM_PTR_SYM_3_INDEX       0x00000007
#define BPU_COMMON_MEM_PTR_SYM_3_RESET       0x00000000

__INLINE uint32_t  bpu_common_mem_ptr_sym_3_get(void)
{
	return REG_PL_RD(BPU_COMMON_MEM_PTR_SYM_3_ADDR);
}

__INLINE void bpu_common_mem_ptr_sym_3_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_MEM_PTR_SYM_3_ADDR, value);
}

// field definitions
#define BPU_COMMON_MEM_PTR_SYM_3_MEM_PTR_SYM_3_MASK    ((uint32_t)0xFFFFFFFF)
#define BPU_COMMON_MEM_PTR_SYM_3_MEM_PTR_SYM_3_LSB    0
#define BPU_COMMON_MEM_PTR_SYM_3_MEM_PTR_SYM_3_WIDTH    ((uint32_t)0x00000020)

#define BPU_COMMON_MEM_PTR_SYM_3_MEM_PTR_SYM_3_RST    0x0

__INLINE uint32_t bpu_common_mem_ptr_sym_3_mem_ptr_sym_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MEM_PTR_SYM_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bpu_common_mem_ptr_sym_3_mem_ptr_sym_3_setf(uint32_t memptrsym3)
{
	ASSERT_ERR((((uint32_t)memptrsym3 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BPU_COMMON_MEM_PTR_SYM_3_ADDR, (uint32_t)memptrsym3 << 0);
}

/**
 * @brief MPU_2_BPU_MAP register definition
 *  Mapping between BPU to MPU user register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 BPU_USER7_MPU_POS         0xF
 *    27:24 BPU_USER6_MPU_POS         0xF
 *    23:20 BPU_USER5_MPU_POS         0xF
 *    19:16 BPU_USER4_MPU_POS         0xF
 *    15:12 BPU_USER3_MPU_POS         0xF
 *    11:08 BPU_USER2_MPU_POS         0xF
 *    07:04 BPU_USER1_MPU_POS         0xF
 *    03:00 BPU_USER0_MPU_POS         0xF
 * </pre>
 */
#define BPU_COMMON_MPU_2_BPU_MAP_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000020)
#define BPU_COMMON_MPU_2_BPU_MAP_OFFSET      0x00000020
#define BPU_COMMON_MPU_2_BPU_MAP_INDEX       0x00000008
#define BPU_COMMON_MPU_2_BPU_MAP_RESET       0xFFFFFFFF

__INLINE uint32_t  bpu_common_mpu_2_bpu_map_get(void)
{
	return REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR);
}

__INLINE void bpu_common_mpu_2_bpu_map_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_MPU_2_BPU_MAP_ADDR, value);
}

// field definitions
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_7_MPU_POS_MASK    ((uint32_t)0xF0000000)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_7_MPU_POS_LSB    28
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_7_MPU_POS_WIDTH    ((uint32_t)0x00000004)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_6_MPU_POS_MASK    ((uint32_t)0x0F000000)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_6_MPU_POS_LSB    24
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_6_MPU_POS_WIDTH    ((uint32_t)0x00000004)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_5_MPU_POS_MASK    ((uint32_t)0x00F00000)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_5_MPU_POS_LSB    20
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_5_MPU_POS_WIDTH    ((uint32_t)0x00000004)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_4_MPU_POS_MASK    ((uint32_t)0x000F0000)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_4_MPU_POS_LSB    16
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_4_MPU_POS_WIDTH    ((uint32_t)0x00000004)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_3_MPU_POS_MASK    ((uint32_t)0x0000F000)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_3_MPU_POS_LSB    12
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_3_MPU_POS_WIDTH    ((uint32_t)0x00000004)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_2_MPU_POS_MASK    ((uint32_t)0x00000F00)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_2_MPU_POS_LSB    8
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_2_MPU_POS_WIDTH    ((uint32_t)0x00000004)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_1_MPU_POS_MASK    ((uint32_t)0x000000F0)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_1_MPU_POS_LSB    4
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_1_MPU_POS_WIDTH    ((uint32_t)0x00000004)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_0_MPU_POS_MASK    ((uint32_t)0x0000000F)
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_0_MPU_POS_LSB    0
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_0_MPU_POS_WIDTH    ((uint32_t)0x00000004)

#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_7_MPU_POS_RST    0xF
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_6_MPU_POS_RST    0xF
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_5_MPU_POS_RST    0xF
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_4_MPU_POS_RST    0xF
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_3_MPU_POS_RST    0xF
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_2_MPU_POS_RST    0xF
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_1_MPU_POS_RST    0xF
#define BPU_COMMON_MPU_2_BPU_MAP_BPU_USER_0_MPU_POS_RST    0xF

__INLINE void bpu_common_mpu_2_bpu_map_pack(uint8_t bpu_user7_mpu_pos, uint8_t bpu_user6_mpu_pos, uint8_t bpu_user5_mpu_pos, uint8_t bpu_user4_mpu_pos, uint8_t bpu_user3_mpu_pos, uint8_t bpu_user2_mpu_pos, uint8_t bpu_user1_mpu_pos, uint8_t bpu_user0_mpu_pos)
{
	ASSERT_ERR((((uint32_t)bpu_user7_mpu_pos << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)bpu_user6_mpu_pos << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)bpu_user5_mpu_pos << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)bpu_user4_mpu_pos << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)bpu_user3_mpu_pos << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)bpu_user2_mpu_pos << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)bpu_user1_mpu_pos << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)bpu_user0_mpu_pos << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(BPU_COMMON_MPU_2_BPU_MAP_ADDR,  ((uint32_t)bpu_user7_mpu_pos << 28) |((uint32_t)bpu_user6_mpu_pos << 24) |((uint32_t)bpu_user5_mpu_pos << 20) |((uint32_t)bpu_user4_mpu_pos << 16) |((uint32_t)bpu_user3_mpu_pos << 12) |((uint32_t)bpu_user2_mpu_pos << 8) |((uint32_t)bpu_user1_mpu_pos << 4) |((uint32_t)bpu_user0_mpu_pos << 0));
}

__INLINE void bpu_common_mpu_2_bpu_map_unpack(uint8_t* bpu_user7_mpu_pos, uint8_t* bpu_user6_mpu_pos, uint8_t* bpu_user5_mpu_pos, uint8_t* bpu_user4_mpu_pos, uint8_t* bpu_user3_mpu_pos, uint8_t* bpu_user2_mpu_pos, uint8_t* bpu_user1_mpu_pos, uint8_t* bpu_user0_mpu_pos)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR);

	*bpu_user7_mpu_pos = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*bpu_user6_mpu_pos = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*bpu_user5_mpu_pos = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*bpu_user4_mpu_pos = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*bpu_user3_mpu_pos = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*bpu_user2_mpu_pos = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*bpu_user1_mpu_pos = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*bpu_user0_mpu_pos = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t bpu_common_mpu_2_bpu_map_bpu_user_7_mpu_pos_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void bpu_common_mpu_2_bpu_map_bpu_user_7_mpu_pos_setf(uint8_t bpuuser7mpupos)
{
	ASSERT_ERR((((uint32_t)bpuuser7mpupos << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(BPU_COMMON_MPU_2_BPU_MAP_ADDR, (REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)bpuuser7mpupos <<28));
}
__INLINE uint8_t bpu_common_mpu_2_bpu_map_bpu_user_6_mpu_pos_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void bpu_common_mpu_2_bpu_map_bpu_user_6_mpu_pos_setf(uint8_t bpuuser6mpupos)
{
	ASSERT_ERR((((uint32_t)bpuuser6mpupos << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(BPU_COMMON_MPU_2_BPU_MAP_ADDR, (REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)bpuuser6mpupos <<24));
}
__INLINE uint8_t bpu_common_mpu_2_bpu_map_bpu_user_5_mpu_pos_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void bpu_common_mpu_2_bpu_map_bpu_user_5_mpu_pos_setf(uint8_t bpuuser5mpupos)
{
	ASSERT_ERR((((uint32_t)bpuuser5mpupos << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(BPU_COMMON_MPU_2_BPU_MAP_ADDR, (REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)bpuuser5mpupos <<20));
}
__INLINE uint8_t bpu_common_mpu_2_bpu_map_bpu_user_4_mpu_pos_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void bpu_common_mpu_2_bpu_map_bpu_user_4_mpu_pos_setf(uint8_t bpuuser4mpupos)
{
	ASSERT_ERR((((uint32_t)bpuuser4mpupos << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(BPU_COMMON_MPU_2_BPU_MAP_ADDR, (REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)bpuuser4mpupos <<16));
}
__INLINE uint8_t bpu_common_mpu_2_bpu_map_bpu_user_3_mpu_pos_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void bpu_common_mpu_2_bpu_map_bpu_user_3_mpu_pos_setf(uint8_t bpuuser3mpupos)
{
	ASSERT_ERR((((uint32_t)bpuuser3mpupos << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(BPU_COMMON_MPU_2_BPU_MAP_ADDR, (REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)bpuuser3mpupos <<12));
}
__INLINE uint8_t bpu_common_mpu_2_bpu_map_bpu_user_2_mpu_pos_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void bpu_common_mpu_2_bpu_map_bpu_user_2_mpu_pos_setf(uint8_t bpuuser2mpupos)
{
	ASSERT_ERR((((uint32_t)bpuuser2mpupos << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(BPU_COMMON_MPU_2_BPU_MAP_ADDR, (REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)bpuuser2mpupos <<8));
}
__INLINE uint8_t bpu_common_mpu_2_bpu_map_bpu_user_1_mpu_pos_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void bpu_common_mpu_2_bpu_map_bpu_user_1_mpu_pos_setf(uint8_t bpuuser1mpupos)
{
	ASSERT_ERR((((uint32_t)bpuuser1mpupos << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(BPU_COMMON_MPU_2_BPU_MAP_ADDR, (REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)bpuuser1mpupos <<4));
}
__INLINE uint8_t bpu_common_mpu_2_bpu_map_bpu_user_0_mpu_pos_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void bpu_common_mpu_2_bpu_map_bpu_user_0_mpu_pos_setf(uint8_t bpuuser0mpupos)
{
	ASSERT_ERR((((uint32_t)bpuuser0mpupos << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(BPU_COMMON_MPU_2_BPU_MAP_ADDR, (REG_PL_RD(BPU_COMMON_MPU_2_BPU_MAP_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)bpuuser0mpupos <<0));
}

/**
 * @brief LDPC_ENC_CW_FIFO_SIZE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 LDPC_ENC_CW_FIFO_SIZE     0x50
 * </pre>
 */
#define BPU_COMMON_LDPC_ENC_CW_FIFO_SIZE_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000024)
#define BPU_COMMON_LDPC_ENC_CW_FIFO_SIZE_OFFSET      0x00000024
#define BPU_COMMON_LDPC_ENC_CW_FIFO_SIZE_INDEX       0x00000009
#define BPU_COMMON_LDPC_ENC_CW_FIFO_SIZE_RESET       0x00000050

__INLINE uint32_t  bpu_common_ldpc_enc_cw_fifo_size_get(void)
{
	return REG_PL_RD(BPU_COMMON_LDPC_ENC_CW_FIFO_SIZE_ADDR);
}

__INLINE void bpu_common_ldpc_enc_cw_fifo_size_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_LDPC_ENC_CW_FIFO_SIZE_ADDR, value);
}

// field definitions
#define BPU_COMMON_LDPC_ENC_CW_FIFO_SIZE_LDPC_ENC_CW_FIFO_SIZE_MASK    ((uint32_t)0x000000FF)
#define BPU_COMMON_LDPC_ENC_CW_FIFO_SIZE_LDPC_ENC_CW_FIFO_SIZE_LSB    0
#define BPU_COMMON_LDPC_ENC_CW_FIFO_SIZE_LDPC_ENC_CW_FIFO_SIZE_WIDTH    ((uint32_t)0x00000008)

#define BPU_COMMON_LDPC_ENC_CW_FIFO_SIZE_LDPC_ENC_CW_FIFO_SIZE_RST    0x50

__INLINE uint8_t bpu_common_ldpc_enc_cw_fifo_size_ldpc_enc_cw_fifo_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_LDPC_ENC_CW_FIFO_SIZE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void bpu_common_ldpc_enc_cw_fifo_size_ldpc_enc_cw_fifo_size_setf(uint8_t ldpcenccwfifosize)
{
	ASSERT_ERR((((uint32_t)ldpcenccwfifosize << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BPU_COMMON_LDPC_ENC_CW_FIFO_SIZE_ADDR, (uint32_t)ldpcenccwfifosize << 0);
}

/**
 * @brief INT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10    MSG_EN                    0              
 *    09    TX_DONE_EN                0              
 *    08    RX_DONE_EN                0              
 *    07:00 BPL_INT_EN                0x0
 * </pre>
 */
#define BPU_COMMON_INT_EN_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000028)
#define BPU_COMMON_INT_EN_OFFSET      0x00000028
#define BPU_COMMON_INT_EN_INDEX       0x0000000A
#define BPU_COMMON_INT_EN_RESET       0x00000000

__INLINE uint32_t  bpu_common_int_en_get(void)
{
	return REG_PL_RD(BPU_COMMON_INT_EN_ADDR);
}

__INLINE void bpu_common_int_en_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_INT_EN_ADDR, value);
}

// field definitions
#define BPU_COMMON_INT_EN_MSG_EN_BIT        ((uint32_t)0x00000400)
#define BPU_COMMON_INT_EN_MSG_EN_POS        10
#define BPU_COMMON_INT_EN_TX_DONE_EN_BIT    ((uint32_t)0x00000200)
#define BPU_COMMON_INT_EN_TX_DONE_EN_POS    9
#define BPU_COMMON_INT_EN_RX_DONE_EN_BIT    ((uint32_t)0x00000100)
#define BPU_COMMON_INT_EN_RX_DONE_EN_POS    8
#define BPU_COMMON_INT_EN_BPL_INT_EN_MASK    ((uint32_t)0x000000FF)
#define BPU_COMMON_INT_EN_BPL_INT_EN_LSB    0
#define BPU_COMMON_INT_EN_BPL_INT_EN_WIDTH    ((uint32_t)0x00000008)

#define BPU_COMMON_INT_EN_MSG_EN_RST        0x0
#define BPU_COMMON_INT_EN_TX_DONE_EN_RST    0x0
#define BPU_COMMON_INT_EN_RX_DONE_EN_RST    0x0
#define BPU_COMMON_INT_EN_BPL_INT_EN_RST    0x0

__INLINE void bpu_common_int_en_pack(uint8_t msg_en, uint8_t tx_done_en, uint8_t rx_done_en, uint8_t bpl_int_en)
{
	ASSERT_ERR((((uint32_t)msg_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)tx_done_en << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)rx_done_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)bpl_int_en << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BPU_COMMON_INT_EN_ADDR,  ((uint32_t)msg_en << 10) |((uint32_t)tx_done_en << 9) |((uint32_t)rx_done_en << 8) |((uint32_t)bpl_int_en << 0));
}

__INLINE void bpu_common_int_en_unpack(uint8_t* msg_en, uint8_t* tx_done_en, uint8_t* rx_done_en, uint8_t* bpl_int_en)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_EN_ADDR);

	*msg_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*tx_done_en = (localVal & ((uint32_t)0x00000200)) >>  9;
	*rx_done_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*bpl_int_en = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t bpu_common_int_en_msg_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void bpu_common_int_en_msg_en_setf(uint8_t msgen)
{
	ASSERT_ERR((((uint32_t)msgen << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(BPU_COMMON_INT_EN_ADDR, (REG_PL_RD(BPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)msgen <<10));
}
__INLINE uint8_t bpu_common_int_en_tx_done_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void bpu_common_int_en_tx_done_en_setf(uint8_t txdoneen)
{
	ASSERT_ERR((((uint32_t)txdoneen << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(BPU_COMMON_INT_EN_ADDR, (REG_PL_RD(BPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)txdoneen <<9));
}
__INLINE uint8_t bpu_common_int_en_rx_done_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void bpu_common_int_en_rx_done_en_setf(uint8_t rxdoneen)
{
	ASSERT_ERR((((uint32_t)rxdoneen << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(BPU_COMMON_INT_EN_ADDR, (REG_PL_RD(BPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)rxdoneen <<8));
}
__INLINE uint8_t bpu_common_int_en_bpl_int_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void bpu_common_int_en_bpl_int_en_setf(uint8_t bplinten)
{
	ASSERT_ERR((((uint32_t)bplinten << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BPU_COMMON_INT_EN_ADDR, (REG_PL_RD(BPU_COMMON_INT_EN_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)bplinten <<0));
}

/**
 * @brief INT_STAT_RAW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10    MSG_RAW                   0              
 *    09    TX_DONE_RAW               0              
 *    08    RX_DONE_RAW               0              
 *    07    BPL_INT_RAW_EPC           0              
 *    06    BPL_INT_RAW_EEC           0              
 *    05    BPL_INT_RAW_DPC           0              
 *    04    BPL_INT_RAW_DDC           0              
 *    03    BPL_INT_RAW_DPS           0              
 *    02    BPL_INT_RAW_RXD           0              
 *    01    BPL_INT_RAW_TXD           0              
 *    00    BPL_INT_RAW_MSG           0              
 * </pre>
 */
#define BPU_COMMON_INT_STAT_RAW_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x0000002C)
#define BPU_COMMON_INT_STAT_RAW_OFFSET      0x0000002C
#define BPU_COMMON_INT_STAT_RAW_INDEX       0x0000000B
#define BPU_COMMON_INT_STAT_RAW_RESET       0x00000000

__INLINE uint32_t  bpu_common_int_stat_raw_get(void)
{
	return REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);
}

// field definitions
#define BPU_COMMON_INT_STAT_RAW_MSG_RAW_BIT    ((uint32_t)0x00000400)
#define BPU_COMMON_INT_STAT_RAW_MSG_RAW_POS    10
#define BPU_COMMON_INT_STAT_RAW_TX_DONE_RAW_BIT    ((uint32_t)0x00000200)
#define BPU_COMMON_INT_STAT_RAW_TX_DONE_RAW_POS    9
#define BPU_COMMON_INT_STAT_RAW_RX_DONE_RAW_BIT    ((uint32_t)0x00000100)
#define BPU_COMMON_INT_STAT_RAW_RX_DONE_RAW_POS    8
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_EPC_BIT    ((uint32_t)0x00000080)
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_EPC_POS    7
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_EEC_BIT    ((uint32_t)0x00000040)
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_EEC_POS    6
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_DPC_BIT    ((uint32_t)0x00000020)
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_DPC_POS    5
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_DDC_BIT    ((uint32_t)0x00000010)
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_DDC_POS    4
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_DPS_BIT    ((uint32_t)0x00000008)
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_DPS_POS    3
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_RXD_BIT    ((uint32_t)0x00000004)
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_RXD_POS    2
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_TXD_BIT    ((uint32_t)0x00000002)
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_TXD_POS    1
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_MSG_BIT    ((uint32_t)0x00000001)
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_MSG_POS    0

#define BPU_COMMON_INT_STAT_RAW_MSG_RAW_RST    0x0
#define BPU_COMMON_INT_STAT_RAW_TX_DONE_RAW_RST    0x0
#define BPU_COMMON_INT_STAT_RAW_RX_DONE_RAW_RST    0x0
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_EPC_RST    0x0
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_EEC_RST    0x0
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_DPC_RST    0x0
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_DDC_RST    0x0
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_DPS_RST    0x0
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_RXD_RST    0x0
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_TXD_RST    0x0
#define BPU_COMMON_INT_STAT_RAW_BPL_INT_RAW_MSG_RST    0x0

__INLINE void bpu_common_int_stat_raw_unpack(uint8_t* msg_raw, uint8_t* tx_done_raw, uint8_t* rx_done_raw, uint8_t* bpl_int_raw_epc, uint8_t* bpl_int_raw_eec, uint8_t* bpl_int_raw_dpc, uint8_t* bpl_int_raw_ddc, uint8_t* bpl_int_raw_dps, uint8_t* bpl_int_raw_rxd, uint8_t* bpl_int_raw_txd, uint8_t* bpl_int_raw_msg)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);

	*msg_raw = (localVal & ((uint32_t)0x00000400)) >>  10;
	*tx_done_raw = (localVal & ((uint32_t)0x00000200)) >>  9;
	*rx_done_raw = (localVal & ((uint32_t)0x00000100)) >>  8;
	*bpl_int_raw_epc = (localVal & ((uint32_t)0x00000080)) >>  7;
	*bpl_int_raw_eec = (localVal & ((uint32_t)0x00000040)) >>  6;
	*bpl_int_raw_dpc = (localVal & ((uint32_t)0x00000020)) >>  5;
	*bpl_int_raw_ddc = (localVal & ((uint32_t)0x00000010)) >>  4;
	*bpl_int_raw_dps = (localVal & ((uint32_t)0x00000008)) >>  3;
	*bpl_int_raw_rxd = (localVal & ((uint32_t)0x00000004)) >>  2;
	*bpl_int_raw_txd = (localVal & ((uint32_t)0x00000002)) >>  1;
	*bpl_int_raw_msg = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t bpu_common_int_stat_raw_msg_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t bpu_common_int_stat_raw_tx_done_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t bpu_common_int_stat_raw_rx_done_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t bpu_common_int_stat_raw_bpl_int_raw_epc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t bpu_common_int_stat_raw_bpl_int_raw_eec_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t bpu_common_int_stat_raw_bpl_int_raw_dpc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t bpu_common_int_stat_raw_bpl_int_raw_ddc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t bpu_common_int_stat_raw_bpl_int_raw_dps_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t bpu_common_int_stat_raw_bpl_int_raw_rxd_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t bpu_common_int_stat_raw_bpl_int_raw_txd_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t bpu_common_int_stat_raw_bpl_int_raw_msg_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief INT_STAT_MASKED register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10    MSG_MASKED                0              
 *    09    TX_DONE_MASKED            0              
 *    08    RX_DONE_MASKED            0              
 *    07:00 BPL_INT_MASKED            0x0
 * </pre>
 */
#define BPU_COMMON_INT_STAT_MASKED_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000030)
#define BPU_COMMON_INT_STAT_MASKED_OFFSET      0x00000030
#define BPU_COMMON_INT_STAT_MASKED_INDEX       0x0000000C
#define BPU_COMMON_INT_STAT_MASKED_RESET       0x00000000

__INLINE uint32_t  bpu_common_int_stat_masked_get(void)
{
	return REG_PL_RD(BPU_COMMON_INT_STAT_MASKED_ADDR);
}

// field definitions
#define BPU_COMMON_INT_STAT_MASKED_MSG_MASKED_BIT    ((uint32_t)0x00000400)
#define BPU_COMMON_INT_STAT_MASKED_MSG_MASKED_POS    10
#define BPU_COMMON_INT_STAT_MASKED_TX_DONE_MASKED_BIT    ((uint32_t)0x00000200)
#define BPU_COMMON_INT_STAT_MASKED_TX_DONE_MASKED_POS    9
#define BPU_COMMON_INT_STAT_MASKED_RX_DONE_MASKED_BIT    ((uint32_t)0x00000100)
#define BPU_COMMON_INT_STAT_MASKED_RX_DONE_MASKED_POS    8
#define BPU_COMMON_INT_STAT_MASKED_BPL_INT_MASKED_MASK    ((uint32_t)0x000000FF)
#define BPU_COMMON_INT_STAT_MASKED_BPL_INT_MASKED_LSB    0
#define BPU_COMMON_INT_STAT_MASKED_BPL_INT_MASKED_WIDTH    ((uint32_t)0x00000008)

#define BPU_COMMON_INT_STAT_MASKED_MSG_MASKED_RST    0x0
#define BPU_COMMON_INT_STAT_MASKED_TX_DONE_MASKED_RST    0x0
#define BPU_COMMON_INT_STAT_MASKED_RX_DONE_MASKED_RST    0x0
#define BPU_COMMON_INT_STAT_MASKED_BPL_INT_MASKED_RST    0x0

__INLINE void bpu_common_int_stat_masked_unpack(uint8_t* msg_masked, uint8_t* tx_done_masked, uint8_t* rx_done_masked, uint8_t* bpl_int_masked)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_MASKED_ADDR);

	*msg_masked = (localVal & ((uint32_t)0x00000400)) >>  10;
	*tx_done_masked = (localVal & ((uint32_t)0x00000200)) >>  9;
	*rx_done_masked = (localVal & ((uint32_t)0x00000100)) >>  8;
	*bpl_int_masked = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t bpu_common_int_stat_masked_msg_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t bpu_common_int_stat_masked_tx_done_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t bpu_common_int_stat_masked_rx_done_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t bpu_common_int_stat_masked_bpl_int_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief INT_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10    MSG_ACK                   0              
 *    09    TX_DONE_ACK               0              
 *    08    RX_DONE_ACK               0              
 *    07:00 BPL_INT_ACK               0x0
 * </pre>
 */
#define BPU_COMMON_INT_ACK_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000034)
#define BPU_COMMON_INT_ACK_OFFSET      0x00000034
#define BPU_COMMON_INT_ACK_INDEX       0x0000000D
#define BPU_COMMON_INT_ACK_RESET       0x00000000

__INLINE uint32_t  bpu_common_int_ack_get(void)
{
	return REG_PL_RD(BPU_COMMON_INT_ACK_ADDR);
}

__INLINE void bpu_common_int_ack_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_INT_ACK_ADDR, value);
}

__INLINE void bpu_common_int_ack_clear(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_INT_ACK_ADDR, value);
}

// field definitions
#define BPU_COMMON_INT_ACK_MSG_ACK_BIT      ((uint32_t)0x00000400)
#define BPU_COMMON_INT_ACK_MSG_ACK_POS      10
#define BPU_COMMON_INT_ACK_TX_DONE_ACK_BIT    ((uint32_t)0x00000200)
#define BPU_COMMON_INT_ACK_TX_DONE_ACK_POS    9
#define BPU_COMMON_INT_ACK_RX_DONE_ACK_BIT    ((uint32_t)0x00000100)
#define BPU_COMMON_INT_ACK_RX_DONE_ACK_POS    8
#define BPU_COMMON_INT_ACK_BPL_INT_ACK_MASK    ((uint32_t)0x000000FF)
#define BPU_COMMON_INT_ACK_BPL_INT_ACK_LSB    0
#define BPU_COMMON_INT_ACK_BPL_INT_ACK_WIDTH    ((uint32_t)0x00000008)

#define BPU_COMMON_INT_ACK_MSG_ACK_RST      0x0
#define BPU_COMMON_INT_ACK_TX_DONE_ACK_RST    0x0
#define BPU_COMMON_INT_ACK_RX_DONE_ACK_RST    0x0
#define BPU_COMMON_INT_ACK_BPL_INT_ACK_RST    0x0

__INLINE void bpu_common_int_ack_pack(uint8_t msg_ack, uint8_t tx_done_ack, uint8_t rx_done_ack, uint8_t bpl_int_ack)
{
	ASSERT_ERR((((uint32_t)msg_ack << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)tx_done_ack << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)rx_done_ack << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)bpl_int_ack << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BPU_COMMON_INT_ACK_ADDR,  ((uint32_t)msg_ack << 10) |((uint32_t)tx_done_ack << 9) |((uint32_t)rx_done_ack << 8) |((uint32_t)bpl_int_ack << 0));
}

__INLINE void bpu_common_int_ack_unpack(uint8_t* msg_ack, uint8_t* tx_done_ack, uint8_t* rx_done_ack, uint8_t* bpl_int_ack)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_ACK_ADDR);

	*msg_ack = (localVal & ((uint32_t)0x00000400)) >>  10;
	*tx_done_ack = (localVal & ((uint32_t)0x00000200)) >>  9;
	*rx_done_ack = (localVal & ((uint32_t)0x00000100)) >>  8;
	*bpl_int_ack = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t bpu_common_int_ack_msg_ack_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_ACK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void bpu_common_int_ack_msg_ack_setf(uint8_t msgack)
{
	ASSERT_ERR((((uint32_t)msgack << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(BPU_COMMON_INT_ACK_ADDR, (REG_PL_RD(BPU_COMMON_INT_ACK_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)msgack <<10));
}
__INLINE void bpu_common_int_ack_msg_ack_clearf(uint8_t msgack)
{
	ASSERT_ERR((((uint32_t)msgack << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(BPU_COMMON_INT_ACK_ADDR, (REG_PL_RD(BPU_COMMON_INT_ACK_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)msgack << 10));
}
__INLINE uint8_t bpu_common_int_ack_tx_done_ack_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_ACK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void bpu_common_int_ack_tx_done_ack_setf(uint8_t txdoneack)
{
	ASSERT_ERR((((uint32_t)txdoneack << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(BPU_COMMON_INT_ACK_ADDR, (REG_PL_RD(BPU_COMMON_INT_ACK_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)txdoneack <<9));
}
__INLINE void bpu_common_int_ack_tx_done_ack_clearf(uint8_t txdoneack)
{
	ASSERT_ERR((((uint32_t)txdoneack << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(BPU_COMMON_INT_ACK_ADDR, (REG_PL_RD(BPU_COMMON_INT_ACK_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)txdoneack << 9));
}
__INLINE uint8_t bpu_common_int_ack_rx_done_ack_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_ACK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void bpu_common_int_ack_rx_done_ack_setf(uint8_t rxdoneack)
{
	ASSERT_ERR((((uint32_t)rxdoneack << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(BPU_COMMON_INT_ACK_ADDR, (REG_PL_RD(BPU_COMMON_INT_ACK_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)rxdoneack <<8));
}
__INLINE void bpu_common_int_ack_rx_done_ack_clearf(uint8_t rxdoneack)
{
	ASSERT_ERR((((uint32_t)rxdoneack << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(BPU_COMMON_INT_ACK_ADDR, (REG_PL_RD(BPU_COMMON_INT_ACK_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)rxdoneack << 8));
}
__INLINE uint8_t bpu_common_int_ack_bpl_int_ack_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_INT_ACK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void bpu_common_int_ack_bpl_int_ack_setf(uint8_t bplintack)
{
	ASSERT_ERR((((uint32_t)bplintack << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BPU_COMMON_INT_ACK_ADDR, (REG_PL_RD(BPU_COMMON_INT_ACK_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)bplintack <<0));
}
__INLINE void bpu_common_int_ack_bpl_int_ack_clearf(uint8_t bplintack)
{
	ASSERT_ERR((((uint32_t)bplintack << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BPU_COMMON_INT_ACK_ADDR, (REG_PL_RD(BPU_COMMON_INT_ACK_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)bplintack << 0));
}

/**
 * @brief BPU_COMMON_STATUS register definition
 *  Common status register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    RX_PACKET_DONE            0              
 *    04    TX_PACKET_DONE            0              
 *    03    RX_DONE                   0              
 *    02    RX_ON_GOING               0              
 *    01    TX_DONE                   0              
 *    00    TX_ON_GOING               0              
 * </pre>
 */
#define BPU_COMMON_BPU_COMMON_STATUS_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000038)
#define BPU_COMMON_BPU_COMMON_STATUS_OFFSET      0x00000038
#define BPU_COMMON_BPU_COMMON_STATUS_INDEX       0x0000000E
#define BPU_COMMON_BPU_COMMON_STATUS_RESET       0x00000000

__INLINE uint32_t  bpu_common_bpu_common_status_get(void)
{
	return REG_PL_RD(BPU_COMMON_BPU_COMMON_STATUS_ADDR);
}

// field definitions
#define BPU_COMMON_BPU_COMMON_STATUS_RX_PACKET_DONE_BIT    ((uint32_t)0x00000020)
#define BPU_COMMON_BPU_COMMON_STATUS_RX_PACKET_DONE_POS    5
#define BPU_COMMON_BPU_COMMON_STATUS_TX_PACKET_DONE_BIT    ((uint32_t)0x00000010)
#define BPU_COMMON_BPU_COMMON_STATUS_TX_PACKET_DONE_POS    4
#define BPU_COMMON_BPU_COMMON_STATUS_RX_DONE_BIT    ((uint32_t)0x00000008)
#define BPU_COMMON_BPU_COMMON_STATUS_RX_DONE_POS    3
#define BPU_COMMON_BPU_COMMON_STATUS_RX_ON_GOING_BIT    ((uint32_t)0x00000004)
#define BPU_COMMON_BPU_COMMON_STATUS_RX_ON_GOING_POS    2
#define BPU_COMMON_BPU_COMMON_STATUS_TX_DONE_BIT    ((uint32_t)0x00000002)
#define BPU_COMMON_BPU_COMMON_STATUS_TX_DONE_POS    1
#define BPU_COMMON_BPU_COMMON_STATUS_TX_ON_GOING_BIT    ((uint32_t)0x00000001)
#define BPU_COMMON_BPU_COMMON_STATUS_TX_ON_GOING_POS    0

#define BPU_COMMON_BPU_COMMON_STATUS_RX_PACKET_DONE_RST    0x0
#define BPU_COMMON_BPU_COMMON_STATUS_TX_PACKET_DONE_RST    0x0
#define BPU_COMMON_BPU_COMMON_STATUS_RX_DONE_RST    0x0
#define BPU_COMMON_BPU_COMMON_STATUS_RX_ON_GOING_RST    0x0
#define BPU_COMMON_BPU_COMMON_STATUS_TX_DONE_RST    0x0
#define BPU_COMMON_BPU_COMMON_STATUS_TX_ON_GOING_RST    0x0

__INLINE void bpu_common_bpu_common_status_unpack(uint8_t* rx_packet_done, uint8_t* tx_packet_done, uint8_t* rx_done, uint8_t* rx_on_going, uint8_t* tx_done, uint8_t* tx_on_going)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_BPU_COMMON_STATUS_ADDR);

	*rx_packet_done = (localVal & ((uint32_t)0x00000020)) >>  5;
	*tx_packet_done = (localVal & ((uint32_t)0x00000010)) >>  4;
	*rx_done = (localVal & ((uint32_t)0x00000008)) >>  3;
	*rx_on_going = (localVal & ((uint32_t)0x00000004)) >>  2;
	*tx_done = (localVal & ((uint32_t)0x00000002)) >>  1;
	*tx_on_going = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t bpu_common_bpu_common_status_rx_packet_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_BPU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t bpu_common_bpu_common_status_tx_packet_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_BPU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t bpu_common_bpu_common_status_rx_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_BPU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t bpu_common_bpu_common_status_rx_on_going_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_BPU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t bpu_common_bpu_common_status_tx_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_BPU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t bpu_common_bpu_common_status_tx_on_going_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_BPU_COMMON_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief BPU_SYM_CNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BPU_SYM_CNT               0x0
 * </pre>
 */
#define BPU_COMMON_BPU_SYM_CNT_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x0000003C)
#define BPU_COMMON_BPU_SYM_CNT_OFFSET      0x0000003C
#define BPU_COMMON_BPU_SYM_CNT_INDEX       0x0000000F
#define BPU_COMMON_BPU_SYM_CNT_RESET       0x00000000

__INLINE uint32_t  bpu_common_bpu_sym_cnt_get(void)
{
	return REG_PL_RD(BPU_COMMON_BPU_SYM_CNT_ADDR);
}

// field definitions
#define BPU_COMMON_BPU_SYM_CNT_BPU_SYM_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define BPU_COMMON_BPU_SYM_CNT_BPU_SYM_CNT_LSB    0
#define BPU_COMMON_BPU_SYM_CNT_BPU_SYM_CNT_WIDTH    ((uint32_t)0x00000020)

#define BPU_COMMON_BPU_SYM_CNT_BPU_SYM_CNT_RST    0x0

__INLINE uint32_t bpu_common_bpu_sym_cnt_bpu_sym_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_BPU_SYM_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LDPC_TX_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:30 LDPC_USER_STATE_MACHINE   0x0
 *    29:00 LAST_10_LDPC_OUT_USERS    0x0
 * </pre>
 */
#define BPU_COMMON_LDPC_TX_STATUS_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000040)
#define BPU_COMMON_LDPC_TX_STATUS_OFFSET      0x00000040
#define BPU_COMMON_LDPC_TX_STATUS_INDEX       0x00000010
#define BPU_COMMON_LDPC_TX_STATUS_RESET       0x00000000

__INLINE uint32_t  bpu_common_ldpc_tx_status_get(void)
{
	return REG_PL_RD(BPU_COMMON_LDPC_TX_STATUS_ADDR);
}

// field definitions
#define BPU_COMMON_LDPC_TX_STATUS_LDPC_USER_STATE_MACHINE_MASK    ((uint32_t)0xC0000000)
#define BPU_COMMON_LDPC_TX_STATUS_LDPC_USER_STATE_MACHINE_LSB    30
#define BPU_COMMON_LDPC_TX_STATUS_LDPC_USER_STATE_MACHINE_WIDTH    ((uint32_t)0x00000002)
#define BPU_COMMON_LDPC_TX_STATUS_LAST_10_LDPC_OUT_USERS_MASK    ((uint32_t)0x3FFFFFFF)
#define BPU_COMMON_LDPC_TX_STATUS_LAST_10_LDPC_OUT_USERS_LSB    0
#define BPU_COMMON_LDPC_TX_STATUS_LAST_10_LDPC_OUT_USERS_WIDTH    ((uint32_t)0x0000001E)

#define BPU_COMMON_LDPC_TX_STATUS_LDPC_USER_STATE_MACHINE_RST    0x0
#define BPU_COMMON_LDPC_TX_STATUS_LAST_10_LDPC_OUT_USERS_RST    0x0

__INLINE void bpu_common_ldpc_tx_status_unpack(uint8_t* ldpc_user_state_machine, uint32_t* last_10_ldpc_out_users)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_LDPC_TX_STATUS_ADDR);

	*ldpc_user_state_machine = (localVal & ((uint32_t)0xC0000000)) >>  30;
	*last_10_ldpc_out_users = (localVal & ((uint32_t)0x3FFFFFFF)) >>  0;
}

__INLINE uint8_t bpu_common_ldpc_tx_status_ldpc_user_state_machine_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_LDPC_TX_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xC0000000)) >> 30);
}
__INLINE uint32_t bpu_common_ldpc_tx_status_last_10_ldpc_out_users_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_LDPC_TX_STATUS_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0x3FFFFFFF)) >> 0);
}

/**
 * @brief LAST_10_BPU_PROCESSED register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:00 LAST_10_BPU_PROCESSED     0x0
 * </pre>
 */
#define BPU_COMMON_LAST_10_BPU_PROCESSED_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000044)
#define BPU_COMMON_LAST_10_BPU_PROCESSED_OFFSET      0x00000044
#define BPU_COMMON_LAST_10_BPU_PROCESSED_INDEX       0x00000011
#define BPU_COMMON_LAST_10_BPU_PROCESSED_RESET       0x00000000

__INLINE uint32_t  bpu_common_last_10_bpu_processed_get(void)
{
	return REG_PL_RD(BPU_COMMON_LAST_10_BPU_PROCESSED_ADDR);
}

// field definitions
#define BPU_COMMON_LAST_10_BPU_PROCESSED_LAST_10_BPU_PROCESSED_MASK    ((uint32_t)0x3FFFFFFF)
#define BPU_COMMON_LAST_10_BPU_PROCESSED_LAST_10_BPU_PROCESSED_LSB    0
#define BPU_COMMON_LAST_10_BPU_PROCESSED_LAST_10_BPU_PROCESSED_WIDTH    ((uint32_t)0x0000001E)

#define BPU_COMMON_LAST_10_BPU_PROCESSED_LAST_10_BPU_PROCESSED_RST    0x0

__INLINE uint32_t bpu_common_last_10_bpu_processed_last_10_bpu_processed_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_LAST_10_BPU_PROCESSED_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief DEBUG_SEL register definition
 *    register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 DEBUG3_SEL                0x0
 *    23:16 DEBUG2_SEL                0x0
 *    15:08 DEBUG1_SEL                0x0
 *    07:00 DEBUG0_SEL                0x0
 * </pre>
 */
#define BPU_COMMON_DEBUG_SEL_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000048)
#define BPU_COMMON_DEBUG_SEL_OFFSET      0x00000048
#define BPU_COMMON_DEBUG_SEL_INDEX       0x00000012
#define BPU_COMMON_DEBUG_SEL_RESET       0x00000000

__INLINE uint32_t  bpu_common_debug_sel_get(void)
{
	return REG_PL_RD(BPU_COMMON_DEBUG_SEL_ADDR);
}

__INLINE void bpu_common_debug_sel_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_DEBUG_SEL_ADDR, value);
}

// field definitions
#define BPU_COMMON_DEBUG_SEL_DEBUG_3_SEL_MASK    ((uint32_t)0xFF000000)
#define BPU_COMMON_DEBUG_SEL_DEBUG_3_SEL_LSB    24
#define BPU_COMMON_DEBUG_SEL_DEBUG_3_SEL_WIDTH    ((uint32_t)0x00000008)
#define BPU_COMMON_DEBUG_SEL_DEBUG_2_SEL_MASK    ((uint32_t)0x00FF0000)
#define BPU_COMMON_DEBUG_SEL_DEBUG_2_SEL_LSB    16
#define BPU_COMMON_DEBUG_SEL_DEBUG_2_SEL_WIDTH    ((uint32_t)0x00000008)
#define BPU_COMMON_DEBUG_SEL_DEBUG_1_SEL_MASK    ((uint32_t)0x0000FF00)
#define BPU_COMMON_DEBUG_SEL_DEBUG_1_SEL_LSB    8
#define BPU_COMMON_DEBUG_SEL_DEBUG_1_SEL_WIDTH    ((uint32_t)0x00000008)
#define BPU_COMMON_DEBUG_SEL_DEBUG_0_SEL_MASK    ((uint32_t)0x000000FF)
#define BPU_COMMON_DEBUG_SEL_DEBUG_0_SEL_LSB    0
#define BPU_COMMON_DEBUG_SEL_DEBUG_0_SEL_WIDTH    ((uint32_t)0x00000008)

#define BPU_COMMON_DEBUG_SEL_DEBUG_3_SEL_RST    0x0
#define BPU_COMMON_DEBUG_SEL_DEBUG_2_SEL_RST    0x0
#define BPU_COMMON_DEBUG_SEL_DEBUG_1_SEL_RST    0x0
#define BPU_COMMON_DEBUG_SEL_DEBUG_0_SEL_RST    0x0

__INLINE void bpu_common_debug_sel_pack(uint8_t debug3_sel, uint8_t debug2_sel, uint8_t debug1_sel, uint8_t debug0_sel)
{
	ASSERT_ERR((((uint32_t)debug3_sel << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)debug2_sel << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)debug1_sel << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)debug0_sel << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BPU_COMMON_DEBUG_SEL_ADDR,  ((uint32_t)debug3_sel << 24) |((uint32_t)debug2_sel << 16) |((uint32_t)debug1_sel << 8) |((uint32_t)debug0_sel << 0));
}

__INLINE void bpu_common_debug_sel_unpack(uint8_t* debug3_sel, uint8_t* debug2_sel, uint8_t* debug1_sel, uint8_t* debug0_sel)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_DEBUG_SEL_ADDR);

	*debug3_sel = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*debug2_sel = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*debug1_sel = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*debug0_sel = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t bpu_common_debug_sel_debug_3_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_DEBUG_SEL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void bpu_common_debug_sel_debug_3_sel_setf(uint8_t debug3sel)
{
	ASSERT_ERR((((uint32_t)debug3sel << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(BPU_COMMON_DEBUG_SEL_ADDR, (REG_PL_RD(BPU_COMMON_DEBUG_SEL_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)debug3sel <<24));
}
__INLINE uint8_t bpu_common_debug_sel_debug_2_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_DEBUG_SEL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void bpu_common_debug_sel_debug_2_sel_setf(uint8_t debug2sel)
{
	ASSERT_ERR((((uint32_t)debug2sel << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(BPU_COMMON_DEBUG_SEL_ADDR, (REG_PL_RD(BPU_COMMON_DEBUG_SEL_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)debug2sel <<16));
}
__INLINE uint8_t bpu_common_debug_sel_debug_1_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_DEBUG_SEL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void bpu_common_debug_sel_debug_1_sel_setf(uint8_t debug1sel)
{
	ASSERT_ERR((((uint32_t)debug1sel << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(BPU_COMMON_DEBUG_SEL_ADDR, (REG_PL_RD(BPU_COMMON_DEBUG_SEL_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)debug1sel <<8));
}
__INLINE uint8_t bpu_common_debug_sel_debug_0_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_DEBUG_SEL_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void bpu_common_debug_sel_debug_0_sel_setf(uint8_t debug0sel)
{
	ASSERT_ERR((((uint32_t)debug0sel << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BPU_COMMON_DEBUG_SEL_ADDR, (REG_PL_RD(BPU_COMMON_DEBUG_SEL_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)debug0sel <<0));
}

/**
 * @brief DEBUG_SEL_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    DEBUG_EN                  0              
 *    15:08 DEBUG5_SEL                0x0
 *    07:00 DEBUG4_SEL                0x0
 * </pre>
 */
#define BPU_COMMON_DEBUG_SEL_1_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x0000004C)
#define BPU_COMMON_DEBUG_SEL_1_OFFSET      0x0000004C
#define BPU_COMMON_DEBUG_SEL_1_INDEX       0x00000013
#define BPU_COMMON_DEBUG_SEL_1_RESET       0x00000000

__INLINE uint32_t  bpu_common_debug_sel_1_get(void)
{
	return REG_PL_RD(BPU_COMMON_DEBUG_SEL_1_ADDR);
}

__INLINE void bpu_common_debug_sel_1_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_DEBUG_SEL_1_ADDR, value);
}

// field definitions
#define BPU_COMMON_DEBUG_SEL_1_DEBUG_EN_BIT    ((uint32_t)0x00010000)
#define BPU_COMMON_DEBUG_SEL_1_DEBUG_EN_POS    16
#define BPU_COMMON_DEBUG_SEL_1_DEBUG_5_SEL_MASK    ((uint32_t)0x0000FF00)
#define BPU_COMMON_DEBUG_SEL_1_DEBUG_5_SEL_LSB    8
#define BPU_COMMON_DEBUG_SEL_1_DEBUG_5_SEL_WIDTH    ((uint32_t)0x00000008)
#define BPU_COMMON_DEBUG_SEL_1_DEBUG_4_SEL_MASK    ((uint32_t)0x000000FF)
#define BPU_COMMON_DEBUG_SEL_1_DEBUG_4_SEL_LSB    0
#define BPU_COMMON_DEBUG_SEL_1_DEBUG_4_SEL_WIDTH    ((uint32_t)0x00000008)

#define BPU_COMMON_DEBUG_SEL_1_DEBUG_EN_RST    0x0
#define BPU_COMMON_DEBUG_SEL_1_DEBUG_5_SEL_RST    0x0
#define BPU_COMMON_DEBUG_SEL_1_DEBUG_4_SEL_RST    0x0

__INLINE void bpu_common_debug_sel_1_pack(uint8_t debug_en, uint8_t debug5_sel, uint8_t debug4_sel)
{
	ASSERT_ERR((((uint32_t)debug_en << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)debug5_sel << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)debug4_sel << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BPU_COMMON_DEBUG_SEL_1_ADDR,  ((uint32_t)debug_en << 16) |((uint32_t)debug5_sel << 8) |((uint32_t)debug4_sel << 0));
}

__INLINE void bpu_common_debug_sel_1_unpack(uint8_t* debug_en, uint8_t* debug5_sel, uint8_t* debug4_sel)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_DEBUG_SEL_1_ADDR);

	*debug_en = (localVal & ((uint32_t)0x00010000)) >>  16;
	*debug5_sel = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*debug4_sel = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t bpu_common_debug_sel_1_debug_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_DEBUG_SEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void bpu_common_debug_sel_1_debug_en_setf(uint8_t debugen)
{
	ASSERT_ERR((((uint32_t)debugen << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(BPU_COMMON_DEBUG_SEL_1_ADDR, (REG_PL_RD(BPU_COMMON_DEBUG_SEL_1_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)debugen <<16));
}
__INLINE uint8_t bpu_common_debug_sel_1_debug_5_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_DEBUG_SEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void bpu_common_debug_sel_1_debug_5_sel_setf(uint8_t debug5sel)
{
	ASSERT_ERR((((uint32_t)debug5sel << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(BPU_COMMON_DEBUG_SEL_1_ADDR, (REG_PL_RD(BPU_COMMON_DEBUG_SEL_1_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)debug5sel <<8));
}
__INLINE uint8_t bpu_common_debug_sel_1_debug_4_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_DEBUG_SEL_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void bpu_common_debug_sel_1_debug_4_sel_setf(uint8_t debug4sel)
{
	ASSERT_ERR((((uint32_t)debug4sel << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BPU_COMMON_DEBUG_SEL_1_ADDR, (REG_PL_RD(BPU_COMMON_DEBUG_SEL_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)debug4sel <<0));
}

/**
 * @brief CLOCK_GATE_CONFIG register definition
 *  Clock gating configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07    Reg_Sampling_En           0              
 *    06    Tx_Interlever_Start_Sym_Sel 1              
 *    05    Viterbi_Rx_Clock_Gate_En  1              
 *    04    Interlever_Tx_Clock_Gate_En 1              
 *    03    LDPCRx_Clock_Gate_En      1              
 *    02    LDPCTx_Clock_Gate_En      1              
 *    01    BCCRx_Clock_Gate_En       1              
 *    00    BCCTx_Clock_Gate_En       1              
 * </pre>
 */
#define BPU_COMMON_CLOCK_GATE_CONFIG_ADDR        (REG_BPU_COMMON_BASE_ADDR+0x00000050)
#define BPU_COMMON_CLOCK_GATE_CONFIG_OFFSET      0x00000050
#define BPU_COMMON_CLOCK_GATE_CONFIG_INDEX       0x00000014
#define BPU_COMMON_CLOCK_GATE_CONFIG_RESET       0x0000007F

__INLINE uint32_t  bpu_common_clock_gate_config_get(void)
{
	return REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR);
}

__INLINE void bpu_common_clock_gate_config_set(uint32_t value)
{
	REG_PL_WR(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR, value);
}

// field definitions
#define BPU_COMMON_CLOCK_GATE_CONFIG_REG_SAMPLING_EN_BIT    ((uint32_t)0x00000080)
#define BPU_COMMON_CLOCK_GATE_CONFIG_REG_SAMPLING_EN_POS    7
#define BPU_COMMON_CLOCK_GATE_CONFIG_TX_INTERLEVER_START_SYM_SEL_BIT    ((uint32_t)0x00000040)
#define BPU_COMMON_CLOCK_GATE_CONFIG_TX_INTERLEVER_START_SYM_SEL_POS    6
#define BPU_COMMON_CLOCK_GATE_CONFIG_VITERBI_RX_CLOCK_GATE_EN_BIT    ((uint32_t)0x00000020)
#define BPU_COMMON_CLOCK_GATE_CONFIG_VITERBI_RX_CLOCK_GATE_EN_POS    5
#define BPU_COMMON_CLOCK_GATE_CONFIG_INTERLEVER_TX_CLOCK_GATE_EN_BIT    ((uint32_t)0x00000010)
#define BPU_COMMON_CLOCK_GATE_CONFIG_INTERLEVER_TX_CLOCK_GATE_EN_POS    4
#define BPU_COMMON_CLOCK_GATE_CONFIG_LDPCRX_CLOCK_GATE_EN_BIT    ((uint32_t)0x00000008)
#define BPU_COMMON_CLOCK_GATE_CONFIG_LDPCRX_CLOCK_GATE_EN_POS    3
#define BPU_COMMON_CLOCK_GATE_CONFIG_LDPCTX_CLOCK_GATE_EN_BIT    ((uint32_t)0x00000004)
#define BPU_COMMON_CLOCK_GATE_CONFIG_LDPCTX_CLOCK_GATE_EN_POS    2
#define BPU_COMMON_CLOCK_GATE_CONFIG_BCCRX_CLOCK_GATE_EN_BIT    ((uint32_t)0x00000002)
#define BPU_COMMON_CLOCK_GATE_CONFIG_BCCRX_CLOCK_GATE_EN_POS    1
#define BPU_COMMON_CLOCK_GATE_CONFIG_BCCTX_CLOCK_GATE_EN_BIT    ((uint32_t)0x00000001)
#define BPU_COMMON_CLOCK_GATE_CONFIG_BCCTX_CLOCK_GATE_EN_POS    0

#define BPU_COMMON_CLOCK_GATE_CONFIG_REG_SAMPLING_EN_RST    0x0
#define BPU_COMMON_CLOCK_GATE_CONFIG_TX_INTERLEVER_START_SYM_SEL_RST    0x1
#define BPU_COMMON_CLOCK_GATE_CONFIG_VITERBI_RX_CLOCK_GATE_EN_RST    0x1
#define BPU_COMMON_CLOCK_GATE_CONFIG_INTERLEVER_TX_CLOCK_GATE_EN_RST    0x1
#define BPU_COMMON_CLOCK_GATE_CONFIG_LDPCRX_CLOCK_GATE_EN_RST    0x1
#define BPU_COMMON_CLOCK_GATE_CONFIG_LDPCTX_CLOCK_GATE_EN_RST    0x1
#define BPU_COMMON_CLOCK_GATE_CONFIG_BCCRX_CLOCK_GATE_EN_RST    0x1
#define BPU_COMMON_CLOCK_GATE_CONFIG_BCCTX_CLOCK_GATE_EN_RST    0x1

__INLINE void bpu_common_clock_gate_config_pack(uint8_t reg_sampling_en, uint8_t tx_interlever_start_sym_sel, uint8_t viterbi_rx_clock_gate_en, uint8_t interlever_tx_clock_gate_en, uint8_t ldpcrx_clock_gate_en, uint8_t ldpctx_clock_gate_en, uint8_t bccrx_clock_gate_en, uint8_t bcctx_clock_gate_en)
{
	ASSERT_ERR((((uint32_t)reg_sampling_en << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)tx_interlever_start_sym_sel << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)viterbi_rx_clock_gate_en << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)interlever_tx_clock_gate_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)ldpcrx_clock_gate_en << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)ldpctx_clock_gate_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)bccrx_clock_gate_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)bcctx_clock_gate_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR,  ((uint32_t)reg_sampling_en << 7) |((uint32_t)tx_interlever_start_sym_sel << 6) |((uint32_t)viterbi_rx_clock_gate_en << 5) |((uint32_t)interlever_tx_clock_gate_en << 4) |((uint32_t)ldpcrx_clock_gate_en << 3) |((uint32_t)ldpctx_clock_gate_en << 2) |((uint32_t)bccrx_clock_gate_en << 1) |((uint32_t)bcctx_clock_gate_en << 0));
}

__INLINE void bpu_common_clock_gate_config_unpack(uint8_t* reg_sampling_en, uint8_t* tx_interlever_start_sym_sel, uint8_t* viterbi_rx_clock_gate_en, uint8_t* interlever_tx_clock_gate_en, uint8_t* ldpcrx_clock_gate_en, uint8_t* ldpctx_clock_gate_en, uint8_t* bccrx_clock_gate_en, uint8_t* bcctx_clock_gate_en)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR);

	*reg_sampling_en = (localVal & ((uint32_t)0x00000080)) >>  7;
	*tx_interlever_start_sym_sel = (localVal & ((uint32_t)0x00000040)) >>  6;
	*viterbi_rx_clock_gate_en = (localVal & ((uint32_t)0x00000020)) >>  5;
	*interlever_tx_clock_gate_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*ldpcrx_clock_gate_en = (localVal & ((uint32_t)0x00000008)) >>  3;
	*ldpctx_clock_gate_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*bccrx_clock_gate_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*bcctx_clock_gate_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t bpu_common_clock_gate_config_reg_sampling_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void bpu_common_clock_gate_config_reg_sampling_en_setf(uint8_t regsamplingen)
{
	ASSERT_ERR((((uint32_t)regsamplingen << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR, (REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)regsamplingen <<7));
}
__INLINE uint8_t bpu_common_clock_gate_config_tx_interlever_start_sym_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void bpu_common_clock_gate_config_tx_interlever_start_sym_sel_setf(uint8_t txinterleverstartsymsel)
{
	ASSERT_ERR((((uint32_t)txinterleverstartsymsel << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR, (REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)txinterleverstartsymsel <<6));
}
__INLINE uint8_t bpu_common_clock_gate_config_viterbi_rx_clock_gate_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void bpu_common_clock_gate_config_viterbi_rx_clock_gate_en_setf(uint8_t viterbirxclockgateen)
{
	ASSERT_ERR((((uint32_t)viterbirxclockgateen << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR, (REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)viterbirxclockgateen <<5));
}
__INLINE uint8_t bpu_common_clock_gate_config_interlever_tx_clock_gate_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void bpu_common_clock_gate_config_interlever_tx_clock_gate_en_setf(uint8_t interlevertxclockgateen)
{
	ASSERT_ERR((((uint32_t)interlevertxclockgateen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR, (REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)interlevertxclockgateen <<4));
}
__INLINE uint8_t bpu_common_clock_gate_config_ldpcrx_clock_gate_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void bpu_common_clock_gate_config_ldpcrx_clock_gate_en_setf(uint8_t ldpcrxclockgateen)
{
	ASSERT_ERR((((uint32_t)ldpcrxclockgateen << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR, (REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)ldpcrxclockgateen <<3));
}
__INLINE uint8_t bpu_common_clock_gate_config_ldpctx_clock_gate_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void bpu_common_clock_gate_config_ldpctx_clock_gate_en_setf(uint8_t ldpctxclockgateen)
{
	ASSERT_ERR((((uint32_t)ldpctxclockgateen << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR, (REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)ldpctxclockgateen <<2));
}
__INLINE uint8_t bpu_common_clock_gate_config_bccrx_clock_gate_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void bpu_common_clock_gate_config_bccrx_clock_gate_en_setf(uint8_t bccrxclockgateen)
{
	ASSERT_ERR((((uint32_t)bccrxclockgateen << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR, (REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)bccrxclockgateen <<1));
}
__INLINE uint8_t bpu_common_clock_gate_config_bcctx_clock_gate_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void bpu_common_clock_gate_config_bcctx_clock_gate_en_setf(uint8_t bcctxclockgateen)
{
	ASSERT_ERR((((uint32_t)bcctxclockgateen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR, (REG_PL_RD(BPU_COMMON_CLOCK_GATE_CONFIG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)bcctxclockgateen <<0));
}


#undef DBG_FILEID
#endif //_REG_BPU_COMMON_H_
