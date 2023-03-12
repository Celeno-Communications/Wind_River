#ifndef _REG_BAP_H_
#define _REG_BAP_H_

#include <stdint.h>
#include "_reg_bap.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_BAP__H__FILEID__

#define CE_BAP_MU_ADDR_OFFSET(_i)  (_i << 2 )

#define REG_BAP_COUNT  158


/**
 * @brief BAP_TXDESC_SIZE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 TXDESC_SIZE               0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_SIZE_ADDR        (REG_BAP_BASE_ADDR+0x00000000)
#define BAP_BAP_TXDESC_SIZE_OFFSET      0x00000000
#define BAP_BAP_TXDESC_SIZE_INDEX       0x00000000
#define BAP_BAP_TXDESC_SIZE_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_size_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_SIZE_ADDR);
}

__INLINE void bap_bap_txdesc_size_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_SIZE_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_SIZE_TXDESC_SIZE_MASK    ((uint32_t)0x000000FF)
#define BAP_BAP_TXDESC_SIZE_TXDESC_SIZE_LSB    0
#define BAP_BAP_TXDESC_SIZE_TXDESC_SIZE_WIDTH    ((uint32_t)0x00000008)

#define BAP_BAP_TXDESC_SIZE_TXDESC_SIZE_RST    0x0

__INLINE uint8_t bap_bap_txdesc_size_txdesc_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_SIZE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_size_txdesc_size_setf(uint8_t txdescsize)
{
	ASSERT_ERR((((uint32_t)txdescsize << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_SIZE_ADDR, (uint32_t)txdescsize << 0);
}

/**
 * @brief BAP_RETRY_SIZE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 RETRY_SIZE                0x1
 * </pre>
 */
#define BAP_BAP_RETRY_SIZE_ADDR        (REG_BAP_BASE_ADDR+0x00000004)
#define BAP_BAP_RETRY_SIZE_OFFSET      0x00000004
#define BAP_BAP_RETRY_SIZE_INDEX       0x00000001
#define BAP_BAP_RETRY_SIZE_RESET       0x00000001

__INLINE uint32_t  bap_bap_retry_size_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRY_SIZE_ADDR);
}

__INLINE void bap_bap_retry_size_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRY_SIZE_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRY_SIZE_RETRY_SIZE_MASK    ((uint32_t)0x00000003)
#define BAP_BAP_RETRY_SIZE_RETRY_SIZE_LSB    0
#define BAP_BAP_RETRY_SIZE_RETRY_SIZE_WIDTH    ((uint32_t)0x00000002)

#define BAP_BAP_RETRY_SIZE_RETRY_SIZE_RST    0x1

__INLINE uint8_t bap_bap_retry_size_retry_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRY_SIZE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void bap_bap_retry_size_retry_size_setf(uint8_t retrysize)
{
	ASSERT_ERR((((uint32_t)retrysize << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_RETRY_SIZE_ADDR, (uint32_t)retrysize << 0);
}

/**
 * @brief BAP_MAX_RETRY register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 MAX_RETRY                 0x0
 * </pre>
 */
#define BAP_BAP_MAX_RETRY_ADDR        (REG_BAP_BASE_ADDR+0x00000008)
#define BAP_BAP_MAX_RETRY_OFFSET      0x00000008
#define BAP_BAP_MAX_RETRY_INDEX       0x00000002
#define BAP_BAP_MAX_RETRY_RESET       0x00000000

__INLINE uint32_t  bap_bap_max_retry_get(void)
{
	return REG_PL_RD(BAP_BAP_MAX_RETRY_ADDR);
}

__INLINE void bap_bap_max_retry_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_MAX_RETRY_ADDR, value);
}

// field definitions
#define BAP_BAP_MAX_RETRY_MAX_RETRY_MASK    ((uint32_t)0x000000FF)
#define BAP_BAP_MAX_RETRY_MAX_RETRY_LSB     0
#define BAP_BAP_MAX_RETRY_MAX_RETRY_WIDTH    ((uint32_t)0x00000008)

#define BAP_BAP_MAX_RETRY_MAX_RETRY_RST     0x0

__INLINE uint8_t bap_bap_max_retry_max_retry_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_MAX_RETRY_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void bap_bap_max_retry_max_retry_setf(uint8_t maxretry)
{
	ASSERT_ERR((((uint32_t)maxretry << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BAP_BAP_MAX_RETRY_ADDR, (uint32_t)maxretry << 0);
}

/**
 * @brief BAP_UPDATE_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03    RESET_RTRNS               1              
 *    02    LINKED_LIST_UPDATE_EN     1              
 *    01    DESC_UPDATE_EN            1              
 *    00    VALID_UPDATE_EN           1              
 * </pre>
 */
#define BAP_BAP_UPDATE_EN_ADDR        (REG_BAP_BASE_ADDR+0x0000000C)
#define BAP_BAP_UPDATE_EN_OFFSET      0x0000000C
#define BAP_BAP_UPDATE_EN_INDEX       0x00000003
#define BAP_BAP_UPDATE_EN_RESET       0x0000000F

__INLINE uint32_t  bap_bap_update_en_get(void)
{
	return REG_PL_RD(BAP_BAP_UPDATE_EN_ADDR);
}

__INLINE void bap_bap_update_en_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_UPDATE_EN_ADDR, value);
}

// field definitions
#define BAP_BAP_UPDATE_EN_RESET_RTRNS_BIT    ((uint32_t)0x00000008)
#define BAP_BAP_UPDATE_EN_RESET_RTRNS_POS    3
#define BAP_BAP_UPDATE_EN_LINKED_LIST_UPDATE_EN_BIT    ((uint32_t)0x00000004)
#define BAP_BAP_UPDATE_EN_LINKED_LIST_UPDATE_EN_POS    2
#define BAP_BAP_UPDATE_EN_DESC_UPDATE_EN_BIT    ((uint32_t)0x00000002)
#define BAP_BAP_UPDATE_EN_DESC_UPDATE_EN_POS    1
#define BAP_BAP_UPDATE_EN_VALID_UPDATE_EN_BIT    ((uint32_t)0x00000001)
#define BAP_BAP_UPDATE_EN_VALID_UPDATE_EN_POS    0

#define BAP_BAP_UPDATE_EN_RESET_RTRNS_RST    0x1
#define BAP_BAP_UPDATE_EN_LINKED_LIST_UPDATE_EN_RST    0x1
#define BAP_BAP_UPDATE_EN_DESC_UPDATE_EN_RST    0x1
#define BAP_BAP_UPDATE_EN_VALID_UPDATE_EN_RST    0x1

__INLINE void bap_bap_update_en_pack(uint8_t reset_rtrns, uint8_t linked_list_update_en, uint8_t desc_update_en, uint8_t valid_update_en)
{
	ASSERT_ERR((((uint32_t)reset_rtrns << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)linked_list_update_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)desc_update_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)valid_update_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BAP_BAP_UPDATE_EN_ADDR,  ((uint32_t)reset_rtrns << 3) |((uint32_t)linked_list_update_en << 2) |((uint32_t)desc_update_en << 1) |((uint32_t)valid_update_en << 0));
}

__INLINE void bap_bap_update_en_unpack(uint8_t* reset_rtrns, uint8_t* linked_list_update_en, uint8_t* desc_update_en, uint8_t* valid_update_en)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_UPDATE_EN_ADDR);

	*reset_rtrns = (localVal & ((uint32_t)0x00000008)) >>  3;
	*linked_list_update_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*desc_update_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*valid_update_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t bap_bap_update_en_reset_rtrns_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_UPDATE_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void bap_bap_update_en_reset_rtrns_setf(uint8_t resetrtrns)
{
	ASSERT_ERR((((uint32_t)resetrtrns << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(BAP_BAP_UPDATE_EN_ADDR, (REG_PL_RD(BAP_BAP_UPDATE_EN_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)resetrtrns <<3));
}
__INLINE uint8_t bap_bap_update_en_linked_list_update_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_UPDATE_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void bap_bap_update_en_linked_list_update_en_setf(uint8_t linkedlistupdateen)
{
	ASSERT_ERR((((uint32_t)linkedlistupdateen << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(BAP_BAP_UPDATE_EN_ADDR, (REG_PL_RD(BAP_BAP_UPDATE_EN_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)linkedlistupdateen <<2));
}
__INLINE uint8_t bap_bap_update_en_desc_update_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_UPDATE_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void bap_bap_update_en_desc_update_en_setf(uint8_t descupdateen)
{
	ASSERT_ERR((((uint32_t)descupdateen << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(BAP_BAP_UPDATE_EN_ADDR, (REG_PL_RD(BAP_BAP_UPDATE_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)descupdateen <<1));
}
__INLINE uint8_t bap_bap_update_en_valid_update_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_UPDATE_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void bap_bap_update_en_valid_update_en_setf(uint8_t validupdateen)
{
	ASSERT_ERR((((uint32_t)validupdateen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BAP_BAP_UPDATE_EN_ADDR, (REG_PL_RD(BAP_BAP_UPDATE_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)validupdateen <<0));
}

/**
 * @brief BAP_DESC_VALID_PARAM register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:08 DESC_VALID_WSTRB          0x1
 *    07:00 DESC_VALID_OFFSET         0x0
 * </pre>
 */
#define BAP_BAP_DESC_VALID_PARAM_ADDR        (REG_BAP_BASE_ADDR+0x00000010)
#define BAP_BAP_DESC_VALID_PARAM_OFFSET      0x00000010
#define BAP_BAP_DESC_VALID_PARAM_INDEX       0x00000004
#define BAP_BAP_DESC_VALID_PARAM_RESET       0x00000100

__INLINE uint32_t  bap_bap_desc_valid_param_get(void)
{
	return REG_PL_RD(BAP_BAP_DESC_VALID_PARAM_ADDR);
}

__INLINE void bap_bap_desc_valid_param_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_DESC_VALID_PARAM_ADDR, value);
}

// field definitions
#define BAP_BAP_DESC_VALID_PARAM_DESC_VALID_WSTRB_MASK    ((uint32_t)0x00000F00)
#define BAP_BAP_DESC_VALID_PARAM_DESC_VALID_WSTRB_LSB    8
#define BAP_BAP_DESC_VALID_PARAM_DESC_VALID_WSTRB_WIDTH    ((uint32_t)0x00000004)
#define BAP_BAP_DESC_VALID_PARAM_DESC_VALID_OFFSET_MASK    ((uint32_t)0x000000FF)
#define BAP_BAP_DESC_VALID_PARAM_DESC_VALID_OFFSET_LSB    0
#define BAP_BAP_DESC_VALID_PARAM_DESC_VALID_OFFSET_WIDTH    ((uint32_t)0x00000008)

#define BAP_BAP_DESC_VALID_PARAM_DESC_VALID_WSTRB_RST    0x1
#define BAP_BAP_DESC_VALID_PARAM_DESC_VALID_OFFSET_RST    0x0

__INLINE void bap_bap_desc_valid_param_pack(uint8_t desc_valid_wstrb, uint8_t desc_valid_offset)
{
	ASSERT_ERR((((uint32_t)desc_valid_wstrb << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)desc_valid_offset << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BAP_BAP_DESC_VALID_PARAM_ADDR,  ((uint32_t)desc_valid_wstrb << 8) |((uint32_t)desc_valid_offset << 0));
}

__INLINE void bap_bap_desc_valid_param_unpack(uint8_t* desc_valid_wstrb, uint8_t* desc_valid_offset)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_DESC_VALID_PARAM_ADDR);

	*desc_valid_wstrb = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*desc_valid_offset = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t bap_bap_desc_valid_param_desc_valid_wstrb_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_DESC_VALID_PARAM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void bap_bap_desc_valid_param_desc_valid_wstrb_setf(uint8_t descvalidwstrb)
{
	ASSERT_ERR((((uint32_t)descvalidwstrb << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(BAP_BAP_DESC_VALID_PARAM_ADDR, (REG_PL_RD(BAP_BAP_DESC_VALID_PARAM_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)descvalidwstrb <<8));
}
__INLINE uint8_t bap_bap_desc_valid_param_desc_valid_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_DESC_VALID_PARAM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void bap_bap_desc_valid_param_desc_valid_offset_setf(uint8_t descvalidoffset)
{
	ASSERT_ERR((((uint32_t)descvalidoffset << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BAP_BAP_DESC_VALID_PARAM_ADDR, (REG_PL_RD(BAP_BAP_DESC_VALID_PARAM_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)descvalidoffset <<0));
}

/**
 * @brief BAP_DESC_NEXT_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 DESC_NEXT_OFFSET          0x0
 * </pre>
 */
#define BAP_BAP_DESC_NEXT_OFFSET_ADDR        (REG_BAP_BASE_ADDR+0x00000014)
#define BAP_BAP_DESC_NEXT_OFFSET_OFFSET      0x00000014
#define BAP_BAP_DESC_NEXT_OFFSET_INDEX       0x00000005
#define BAP_BAP_DESC_NEXT_OFFSET_RESET       0x00000000

__INLINE uint32_t  bap_bap_desc_next_offset_get(void)
{
	return REG_PL_RD(BAP_BAP_DESC_NEXT_OFFSET_ADDR);
}

__INLINE void bap_bap_desc_next_offset_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_DESC_NEXT_OFFSET_ADDR, value);
}

// field definitions
#define BAP_BAP_DESC_NEXT_OFFSET_DESC_NEXT_OFFSET_MASK    ((uint32_t)0x000000FF)
#define BAP_BAP_DESC_NEXT_OFFSET_DESC_NEXT_OFFSET_LSB    0
#define BAP_BAP_DESC_NEXT_OFFSET_DESC_NEXT_OFFSET_WIDTH    ((uint32_t)0x00000008)

#define BAP_BAP_DESC_NEXT_OFFSET_DESC_NEXT_OFFSET_RST    0x0

__INLINE uint8_t bap_bap_desc_next_offset_desc_next_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_DESC_NEXT_OFFSET_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void bap_bap_desc_next_offset_desc_next_offset_setf(uint8_t descnextoffset)
{
	ASSERT_ERR((((uint32_t)descnextoffset << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BAP_BAP_DESC_NEXT_OFFSET_ADDR, (uint32_t)descnextoffset << 0);
}

/**
 * @brief BAP_TXDESC_BASE_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_BASE_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_BASE_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000020)
#define BAP_BAP_TXDESC_BASE_ADDR_OFFSET      0x00000020
#define BAP_BAP_TXDESC_BASE_ADDR_INDEX       0x00000008
#define BAP_BAP_TXDESC_BASE_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_base_addr_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_BASE_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_txdesc_base_addr_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_TXDESC_BASE_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_TXDESC_BASE_ADDR_TXDESC_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_BASE_ADDR_TXDESC_BASE_ADDR_LSB    0
#define BAP_BAP_TXDESC_BASE_ADDR_TXDESC_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_BASE_ADDR_TXDESC_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_base_addr_txdesc_base_addr_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_BASE_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_base_addr_txdesc_base_addr_setf(uint32_t txdescbaseaddr, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)txdescbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((BAP_BAP_TXDESC_BASE_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (uint32_t)txdescbaseaddr << 0);
}

/**
 * @brief BAP_TXDESC_BASE_1_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_BASE_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_BASE_1_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000024)
#define BAP_BAP_TXDESC_BASE_1_ADDR_OFFSET      0x00000024
#define BAP_BAP_TXDESC_BASE_1_ADDR_INDEX       0x00000009
#define BAP_BAP_TXDESC_BASE_1_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_base_1_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_BASE_1_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_base_1_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_BASE_1_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_BASE_1_ADDR_TXDESC_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_BASE_1_ADDR_TXDESC_BASE_ADDR_LSB    0
#define BAP_BAP_TXDESC_BASE_1_ADDR_TXDESC_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_BASE_1_ADDR_TXDESC_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_base_1_addr_txdesc_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_BASE_1_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_base_1_addr_txdesc_base_addr_setf(uint32_t txdescbaseaddr)
{
	ASSERT_ERR((((uint32_t)txdescbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_BASE_1_ADDR_ADDR, (uint32_t)txdescbaseaddr << 0);
}

/**
 * @brief BAP_TXDESC_BASE_2_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_BASE_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_BASE_2_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000028)
#define BAP_BAP_TXDESC_BASE_2_ADDR_OFFSET      0x00000028
#define BAP_BAP_TXDESC_BASE_2_ADDR_INDEX       0x0000000A
#define BAP_BAP_TXDESC_BASE_2_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_base_2_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_BASE_2_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_base_2_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_BASE_2_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_BASE_2_ADDR_TXDESC_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_BASE_2_ADDR_TXDESC_BASE_ADDR_LSB    0
#define BAP_BAP_TXDESC_BASE_2_ADDR_TXDESC_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_BASE_2_ADDR_TXDESC_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_base_2_addr_txdesc_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_BASE_2_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_base_2_addr_txdesc_base_addr_setf(uint32_t txdescbaseaddr)
{
	ASSERT_ERR((((uint32_t)txdescbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_BASE_2_ADDR_ADDR, (uint32_t)txdescbaseaddr << 0);
}

/**
 * @brief BAP_TXDESC_BASE_3_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_BASE_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_BASE_3_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x0000002C)
#define BAP_BAP_TXDESC_BASE_3_ADDR_OFFSET      0x0000002C
#define BAP_BAP_TXDESC_BASE_3_ADDR_INDEX       0x0000000B
#define BAP_BAP_TXDESC_BASE_3_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_base_3_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_BASE_3_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_base_3_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_BASE_3_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_BASE_3_ADDR_TXDESC_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_BASE_3_ADDR_TXDESC_BASE_ADDR_LSB    0
#define BAP_BAP_TXDESC_BASE_3_ADDR_TXDESC_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_BASE_3_ADDR_TXDESC_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_base_3_addr_txdesc_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_BASE_3_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_base_3_addr_txdesc_base_addr_setf(uint32_t txdescbaseaddr)
{
	ASSERT_ERR((((uint32_t)txdescbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_BASE_3_ADDR_ADDR, (uint32_t)txdescbaseaddr << 0);
}

/**
 * @brief BAP_TXDESC_BASE_4_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_BASE_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_BASE_4_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000030)
#define BAP_BAP_TXDESC_BASE_4_ADDR_OFFSET      0x00000030
#define BAP_BAP_TXDESC_BASE_4_ADDR_INDEX       0x0000000C
#define BAP_BAP_TXDESC_BASE_4_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_base_4_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_BASE_4_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_base_4_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_BASE_4_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_BASE_4_ADDR_TXDESC_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_BASE_4_ADDR_TXDESC_BASE_ADDR_LSB    0
#define BAP_BAP_TXDESC_BASE_4_ADDR_TXDESC_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_BASE_4_ADDR_TXDESC_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_base_4_addr_txdesc_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_BASE_4_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_base_4_addr_txdesc_base_addr_setf(uint32_t txdescbaseaddr)
{
	ASSERT_ERR((((uint32_t)txdescbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_BASE_4_ADDR_ADDR, (uint32_t)txdescbaseaddr << 0);
}

/**
 * @brief BAP_TXDESC_BASE_5_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_BASE_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_BASE_5_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000034)
#define BAP_BAP_TXDESC_BASE_5_ADDR_OFFSET      0x00000034
#define BAP_BAP_TXDESC_BASE_5_ADDR_INDEX       0x0000000D
#define BAP_BAP_TXDESC_BASE_5_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_base_5_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_BASE_5_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_base_5_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_BASE_5_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_BASE_5_ADDR_TXDESC_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_BASE_5_ADDR_TXDESC_BASE_ADDR_LSB    0
#define BAP_BAP_TXDESC_BASE_5_ADDR_TXDESC_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_BASE_5_ADDR_TXDESC_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_base_5_addr_txdesc_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_BASE_5_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_base_5_addr_txdesc_base_addr_setf(uint32_t txdescbaseaddr)
{
	ASSERT_ERR((((uint32_t)txdescbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_BASE_5_ADDR_ADDR, (uint32_t)txdescbaseaddr << 0);
}

/**
 * @brief BAP_TXDESC_BASE_6_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_BASE_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_BASE_6_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000038)
#define BAP_BAP_TXDESC_BASE_6_ADDR_OFFSET      0x00000038
#define BAP_BAP_TXDESC_BASE_6_ADDR_INDEX       0x0000000E
#define BAP_BAP_TXDESC_BASE_6_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_base_6_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_BASE_6_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_base_6_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_BASE_6_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_BASE_6_ADDR_TXDESC_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_BASE_6_ADDR_TXDESC_BASE_ADDR_LSB    0
#define BAP_BAP_TXDESC_BASE_6_ADDR_TXDESC_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_BASE_6_ADDR_TXDESC_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_base_6_addr_txdesc_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_BASE_6_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_base_6_addr_txdesc_base_addr_setf(uint32_t txdescbaseaddr)
{
	ASSERT_ERR((((uint32_t)txdescbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_BASE_6_ADDR_ADDR, (uint32_t)txdescbaseaddr << 0);
}

/**
 * @brief BAP_TXDESC_BASE_7_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_BASE_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_BASE_7_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x0000003C)
#define BAP_BAP_TXDESC_BASE_7_ADDR_OFFSET      0x0000003C
#define BAP_BAP_TXDESC_BASE_7_ADDR_INDEX       0x0000000F
#define BAP_BAP_TXDESC_BASE_7_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_base_7_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_BASE_7_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_base_7_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_BASE_7_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_BASE_7_ADDR_TXDESC_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_BASE_7_ADDR_TXDESC_BASE_ADDR_LSB    0
#define BAP_BAP_TXDESC_BASE_7_ADDR_TXDESC_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_BASE_7_ADDR_TXDESC_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_base_7_addr_txdesc_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_BASE_7_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_base_7_addr_txdesc_base_addr_setf(uint32_t txdescbaseaddr)
{
	ASSERT_ERR((((uint32_t)txdescbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_BASE_7_ADDR_ADDR, (uint32_t)txdescbaseaddr << 0);
}

/**
 * @brief BAP_TXDESC_WRAP_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_WRAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_WRAP_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000040)
#define BAP_BAP_TXDESC_WRAP_ADDR_OFFSET      0x00000040
#define BAP_BAP_TXDESC_WRAP_ADDR_INDEX       0x00000010
#define BAP_BAP_TXDESC_WRAP_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_wrap_addr_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_WRAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_txdesc_wrap_addr_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_TXDESC_WRAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_TXDESC_WRAP_ADDR_TXDESC_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_WRAP_ADDR_TXDESC_WRAP_ADDR_LSB    0
#define BAP_BAP_TXDESC_WRAP_ADDR_TXDESC_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_WRAP_ADDR_TXDESC_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_wrap_addr_txdesc_wrap_addr_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_WRAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_wrap_addr_txdesc_wrap_addr_setf(uint32_t txdescwrapaddr, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)txdescwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((BAP_BAP_TXDESC_WRAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (uint32_t)txdescwrapaddr << 0);
}

/**
 * @brief BAP_TXDESC_WRAP_1_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_WRAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_WRAP_1_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000044)
#define BAP_BAP_TXDESC_WRAP_1_ADDR_OFFSET      0x00000044
#define BAP_BAP_TXDESC_WRAP_1_ADDR_INDEX       0x00000011
#define BAP_BAP_TXDESC_WRAP_1_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_wrap_1_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_WRAP_1_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_wrap_1_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_1_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_WRAP_1_ADDR_TXDESC_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_WRAP_1_ADDR_TXDESC_WRAP_ADDR_LSB    0
#define BAP_BAP_TXDESC_WRAP_1_ADDR_TXDESC_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_WRAP_1_ADDR_TXDESC_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_wrap_1_addr_txdesc_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_WRAP_1_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_wrap_1_addr_txdesc_wrap_addr_setf(uint32_t txdescwrapaddr)
{
	ASSERT_ERR((((uint32_t)txdescwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_1_ADDR_ADDR, (uint32_t)txdescwrapaddr << 0);
}

/**
 * @brief BAP_TXDESC_WRAP_2_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_WRAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_WRAP_2_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000048)
#define BAP_BAP_TXDESC_WRAP_2_ADDR_OFFSET      0x00000048
#define BAP_BAP_TXDESC_WRAP_2_ADDR_INDEX       0x00000012
#define BAP_BAP_TXDESC_WRAP_2_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_wrap_2_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_WRAP_2_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_wrap_2_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_2_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_WRAP_2_ADDR_TXDESC_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_WRAP_2_ADDR_TXDESC_WRAP_ADDR_LSB    0
#define BAP_BAP_TXDESC_WRAP_2_ADDR_TXDESC_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_WRAP_2_ADDR_TXDESC_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_wrap_2_addr_txdesc_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_WRAP_2_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_wrap_2_addr_txdesc_wrap_addr_setf(uint32_t txdescwrapaddr)
{
	ASSERT_ERR((((uint32_t)txdescwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_2_ADDR_ADDR, (uint32_t)txdescwrapaddr << 0);
}

/**
 * @brief BAP_TXDESC_WRAP_3_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_WRAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_WRAP_3_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x0000004C)
#define BAP_BAP_TXDESC_WRAP_3_ADDR_OFFSET      0x0000004C
#define BAP_BAP_TXDESC_WRAP_3_ADDR_INDEX       0x00000013
#define BAP_BAP_TXDESC_WRAP_3_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_wrap_3_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_WRAP_3_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_wrap_3_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_3_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_WRAP_3_ADDR_TXDESC_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_WRAP_3_ADDR_TXDESC_WRAP_ADDR_LSB    0
#define BAP_BAP_TXDESC_WRAP_3_ADDR_TXDESC_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_WRAP_3_ADDR_TXDESC_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_wrap_3_addr_txdesc_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_WRAP_3_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_wrap_3_addr_txdesc_wrap_addr_setf(uint32_t txdescwrapaddr)
{
	ASSERT_ERR((((uint32_t)txdescwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_3_ADDR_ADDR, (uint32_t)txdescwrapaddr << 0);
}

/**
 * @brief BAP_TXDESC_WRAP_4_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_WRAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_WRAP_4_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000050)
#define BAP_BAP_TXDESC_WRAP_4_ADDR_OFFSET      0x00000050
#define BAP_BAP_TXDESC_WRAP_4_ADDR_INDEX       0x00000014
#define BAP_BAP_TXDESC_WRAP_4_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_wrap_4_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_WRAP_4_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_wrap_4_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_4_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_WRAP_4_ADDR_TXDESC_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_WRAP_4_ADDR_TXDESC_WRAP_ADDR_LSB    0
#define BAP_BAP_TXDESC_WRAP_4_ADDR_TXDESC_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_WRAP_4_ADDR_TXDESC_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_wrap_4_addr_txdesc_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_WRAP_4_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_wrap_4_addr_txdesc_wrap_addr_setf(uint32_t txdescwrapaddr)
{
	ASSERT_ERR((((uint32_t)txdescwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_4_ADDR_ADDR, (uint32_t)txdescwrapaddr << 0);
}

/**
 * @brief BAP_TXDESC_WRAP_5_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_WRAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_WRAP_5_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000054)
#define BAP_BAP_TXDESC_WRAP_5_ADDR_OFFSET      0x00000054
#define BAP_BAP_TXDESC_WRAP_5_ADDR_INDEX       0x00000015
#define BAP_BAP_TXDESC_WRAP_5_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_wrap_5_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_WRAP_5_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_wrap_5_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_5_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_WRAP_5_ADDR_TXDESC_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_WRAP_5_ADDR_TXDESC_WRAP_ADDR_LSB    0
#define BAP_BAP_TXDESC_WRAP_5_ADDR_TXDESC_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_WRAP_5_ADDR_TXDESC_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_wrap_5_addr_txdesc_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_WRAP_5_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_wrap_5_addr_txdesc_wrap_addr_setf(uint32_t txdescwrapaddr)
{
	ASSERT_ERR((((uint32_t)txdescwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_5_ADDR_ADDR, (uint32_t)txdescwrapaddr << 0);
}

/**
 * @brief BAP_TXDESC_WRAP_6_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_LAST_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_WRAP_6_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000058)
#define BAP_BAP_TXDESC_WRAP_6_ADDR_OFFSET      0x00000058
#define BAP_BAP_TXDESC_WRAP_6_ADDR_INDEX       0x00000016
#define BAP_BAP_TXDESC_WRAP_6_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_wrap_6_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_WRAP_6_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_wrap_6_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_6_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_WRAP_6_ADDR_TXDESC_LAST_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_WRAP_6_ADDR_TXDESC_LAST_ADDR_LSB    0
#define BAP_BAP_TXDESC_WRAP_6_ADDR_TXDESC_LAST_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_WRAP_6_ADDR_TXDESC_LAST_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_wrap_6_addr_txdesc_last_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_WRAP_6_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_wrap_6_addr_txdesc_last_addr_setf(uint32_t txdesclastaddr)
{
	ASSERT_ERR((((uint32_t)txdesclastaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_6_ADDR_ADDR, (uint32_t)txdesclastaddr << 0);
}

/**
 * @brief BAP_TXDESC_WRAP_7_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_WRAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_WRAP_7_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x0000005C)
#define BAP_BAP_TXDESC_WRAP_7_ADDR_OFFSET      0x0000005C
#define BAP_BAP_TXDESC_WRAP_7_ADDR_INDEX       0x00000017
#define BAP_BAP_TXDESC_WRAP_7_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_wrap_7_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_WRAP_7_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_wrap_7_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_7_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_WRAP_7_ADDR_TXDESC_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_WRAP_7_ADDR_TXDESC_WRAP_ADDR_LSB    0
#define BAP_BAP_TXDESC_WRAP_7_ADDR_TXDESC_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_WRAP_7_ADDR_TXDESC_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_txdesc_wrap_7_addr_txdesc_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_WRAP_7_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_wrap_7_addr_txdesc_wrap_addr_setf(uint32_t txdescwrapaddr)
{
	ASSERT_ERR((((uint32_t)txdescwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_WRAP_7_ADDR_ADDR, (uint32_t)txdescwrapaddr << 0);
}

/**
 * @brief BAP_TXDESC_START_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_START              0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_START_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000060)
#define BAP_BAP_TXDESC_START_ADDR_OFFSET      0x00000060
#define BAP_BAP_TXDESC_START_ADDR_INDEX       0x00000018
#define BAP_BAP_TXDESC_START_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_start_addr_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_START_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_txdesc_start_addr_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_TXDESC_START_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_TXDESC_START_ADDR_TXDESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_START_ADDR_TXDESC_START_LSB    0
#define BAP_BAP_TXDESC_START_ADDR_TXDESC_START_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_START_ADDR_TXDESC_START_RST    0x0

__INLINE uint32_t bap_bap_txdesc_start_addr_txdesc_start_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_START_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_start_addr_txdesc_start_setf(uint32_t txdescstart, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)txdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((BAP_BAP_TXDESC_START_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (uint32_t)txdescstart << 0);
}

/**
 * @brief BAP_TXDESC_START_1_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_START              0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_START_1_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000064)
#define BAP_BAP_TXDESC_START_1_ADDR_OFFSET      0x00000064
#define BAP_BAP_TXDESC_START_1_ADDR_INDEX       0x00000019
#define BAP_BAP_TXDESC_START_1_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_start_1_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_START_1_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_start_1_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_START_1_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_START_1_ADDR_TXDESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_START_1_ADDR_TXDESC_START_LSB    0
#define BAP_BAP_TXDESC_START_1_ADDR_TXDESC_START_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_START_1_ADDR_TXDESC_START_RST    0x0

__INLINE uint32_t bap_bap_txdesc_start_1_addr_txdesc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_START_1_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_start_1_addr_txdesc_start_setf(uint32_t txdescstart)
{
	ASSERT_ERR((((uint32_t)txdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_START_1_ADDR_ADDR, (uint32_t)txdescstart << 0);
}

/**
 * @brief BAP_TXDESC_START_2_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_START              0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_START_2_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000068)
#define BAP_BAP_TXDESC_START_2_ADDR_OFFSET      0x00000068
#define BAP_BAP_TXDESC_START_2_ADDR_INDEX       0x0000001A
#define BAP_BAP_TXDESC_START_2_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_start_2_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_START_2_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_start_2_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_START_2_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_START_2_ADDR_TXDESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_START_2_ADDR_TXDESC_START_LSB    0
#define BAP_BAP_TXDESC_START_2_ADDR_TXDESC_START_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_START_2_ADDR_TXDESC_START_RST    0x0

__INLINE uint32_t bap_bap_txdesc_start_2_addr_txdesc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_START_2_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_start_2_addr_txdesc_start_setf(uint32_t txdescstart)
{
	ASSERT_ERR((((uint32_t)txdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_START_2_ADDR_ADDR, (uint32_t)txdescstart << 0);
}

/**
 * @brief BAP_TXDESC_START_3_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_START              0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_START_3_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x0000006C)
#define BAP_BAP_TXDESC_START_3_ADDR_OFFSET      0x0000006C
#define BAP_BAP_TXDESC_START_3_ADDR_INDEX       0x0000001B
#define BAP_BAP_TXDESC_START_3_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_start_3_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_START_3_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_start_3_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_START_3_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_START_3_ADDR_TXDESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_START_3_ADDR_TXDESC_START_LSB    0
#define BAP_BAP_TXDESC_START_3_ADDR_TXDESC_START_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_START_3_ADDR_TXDESC_START_RST    0x0

__INLINE uint32_t bap_bap_txdesc_start_3_addr_txdesc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_START_3_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_start_3_addr_txdesc_start_setf(uint32_t txdescstart)
{
	ASSERT_ERR((((uint32_t)txdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_START_3_ADDR_ADDR, (uint32_t)txdescstart << 0);
}

/**
 * @brief BAP_TXDESC_START_4_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_START              0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_START_4_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000070)
#define BAP_BAP_TXDESC_START_4_ADDR_OFFSET      0x00000070
#define BAP_BAP_TXDESC_START_4_ADDR_INDEX       0x0000001C
#define BAP_BAP_TXDESC_START_4_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_start_4_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_START_4_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_start_4_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_START_4_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_START_4_ADDR_TXDESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_START_4_ADDR_TXDESC_START_LSB    0
#define BAP_BAP_TXDESC_START_4_ADDR_TXDESC_START_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_START_4_ADDR_TXDESC_START_RST    0x0

__INLINE uint32_t bap_bap_txdesc_start_4_addr_txdesc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_START_4_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_start_4_addr_txdesc_start_setf(uint32_t txdescstart)
{
	ASSERT_ERR((((uint32_t)txdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_START_4_ADDR_ADDR, (uint32_t)txdescstart << 0);
}

/**
 * @brief BAP_TXDESC_START_5_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_START              0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_START_5_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000074)
#define BAP_BAP_TXDESC_START_5_ADDR_OFFSET      0x00000074
#define BAP_BAP_TXDESC_START_5_ADDR_INDEX       0x0000001D
#define BAP_BAP_TXDESC_START_5_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_start_5_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_START_5_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_start_5_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_START_5_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_START_5_ADDR_TXDESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_START_5_ADDR_TXDESC_START_LSB    0
#define BAP_BAP_TXDESC_START_5_ADDR_TXDESC_START_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_START_5_ADDR_TXDESC_START_RST    0x0

__INLINE uint32_t bap_bap_txdesc_start_5_addr_txdesc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_START_5_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_start_5_addr_txdesc_start_setf(uint32_t txdescstart)
{
	ASSERT_ERR((((uint32_t)txdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_START_5_ADDR_ADDR, (uint32_t)txdescstart << 0);
}

/**
 * @brief BAP_TXDESC_START_6_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_START              0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_START_6_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000078)
#define BAP_BAP_TXDESC_START_6_ADDR_OFFSET      0x00000078
#define BAP_BAP_TXDESC_START_6_ADDR_INDEX       0x0000001E
#define BAP_BAP_TXDESC_START_6_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_start_6_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_START_6_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_start_6_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_START_6_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_START_6_ADDR_TXDESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_START_6_ADDR_TXDESC_START_LSB    0
#define BAP_BAP_TXDESC_START_6_ADDR_TXDESC_START_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_START_6_ADDR_TXDESC_START_RST    0x0

__INLINE uint32_t bap_bap_txdesc_start_6_addr_txdesc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_START_6_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_start_6_addr_txdesc_start_setf(uint32_t txdescstart)
{
	ASSERT_ERR((((uint32_t)txdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_START_6_ADDR_ADDR, (uint32_t)txdescstart << 0);
}

/**
 * @brief BAP_TXDESC_START_7_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXDESC_START              0x0
 * </pre>
 */
#define BAP_BAP_TXDESC_START_7_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x0000007C)
#define BAP_BAP_TXDESC_START_7_ADDR_OFFSET      0x0000007C
#define BAP_BAP_TXDESC_START_7_ADDR_INDEX       0x0000001F
#define BAP_BAP_TXDESC_START_7_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_txdesc_start_7_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_TXDESC_START_7_ADDR_ADDR);
}

__INLINE void bap_bap_txdesc_start_7_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_TXDESC_START_7_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_TXDESC_START_7_ADDR_TXDESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_TXDESC_START_7_ADDR_TXDESC_START_LSB    0
#define BAP_BAP_TXDESC_START_7_ADDR_TXDESC_START_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_TXDESC_START_7_ADDR_TXDESC_START_RST    0x0

__INLINE uint32_t bap_bap_txdesc_start_7_addr_txdesc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_TXDESC_START_7_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_txdesc_start_7_addr_txdesc_start_setf(uint32_t txdescstart)
{
	ASSERT_ERR((((uint32_t)txdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_TXDESC_START_7_ADDR_ADDR, (uint32_t)txdescstart << 0);
}

/**
 * @brief BAP_USER_SENT_SN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 SENT_LAST_SN              0x0
 *    11:00 SENT_FIRST_SN             0x0
 * </pre>
 */
#define BAP_BAP_USER_SENT_SN_ADDR        (REG_BAP_BASE_ADDR+0x00000080)
#define BAP_BAP_USER_SENT_SN_OFFSET      0x00000080
#define BAP_BAP_USER_SENT_SN_INDEX       0x00000020
#define BAP_BAP_USER_SENT_SN_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_sent_sn_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_SENT_SN_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_user_sent_sn_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_USER_SENT_SN_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_USER_SENT_SN_SENT_LAST_SN_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_SENT_SN_SENT_LAST_SN_LSB    16
#define BAP_BAP_USER_SENT_SN_SENT_LAST_SN_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_SENT_SN_SENT_FIRST_SN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_SENT_SN_SENT_FIRST_SN_LSB    0
#define BAP_BAP_USER_SENT_SN_SENT_FIRST_SN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_SENT_SN_SENT_LAST_SN_RST    0x0
#define BAP_BAP_USER_SENT_SN_SENT_FIRST_SN_RST    0x0

__INLINE void bap_bap_user_sent_sn_pack(uint16_t sent_last_sn, uint16_t sent_first_sn, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)sent_last_sn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)sent_first_sn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR((BAP_BAP_USER_SENT_SN_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)),  ((uint32_t)sent_last_sn << 16) |((uint32_t)sent_first_sn << 0));
}

__INLINE void bap_bap_user_sent_sn_unpack(uint16_t* sent_last_sn, uint16_t* sent_first_sn, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_SENT_SN_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));

	*sent_last_sn = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*sent_first_sn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_sent_sn_sent_last_sn_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_SENT_SN_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void bap_bap_user_sent_sn_sent_last_sn_setf(uint16_t sentlastsn,uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)sentlastsn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR((BAP_BAP_USER_SENT_SN_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (REG_PL_RD(BAP_BAP_USER_SENT_SN_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)sentlastsn <<16));
}
__INLINE uint16_t bap_bap_user_sent_sn_sent_first_sn_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_SENT_SN_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_sent_sn_sent_first_sn_setf(uint16_t sentfirstsn,uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)sentfirstsn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR((BAP_BAP_USER_SENT_SN_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (REG_PL_RD(BAP_BAP_USER_SENT_SN_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)) & ~((uint32_t)0x00000FFF)) | ((uint32_t)sentfirstsn <<0));
}

/**
 * @brief BAP_USER_1_SENT_SN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 SENT_LAST_SN              0x0
 *    11:00 SENT_FIRST_SN             0x0
 * </pre>
 */
#define BAP_BAP_USER_1_SENT_SN_ADDR        (REG_BAP_BASE_ADDR+0x00000084)
#define BAP_BAP_USER_1_SENT_SN_OFFSET      0x00000084
#define BAP_BAP_USER_1_SENT_SN_INDEX       0x00000021
#define BAP_BAP_USER_1_SENT_SN_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_1_sent_sn_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_1_SENT_SN_ADDR);
}

__INLINE void bap_bap_user_1_sent_sn_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_1_SENT_SN_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_1_SENT_SN_SENT_LAST_SN_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_1_SENT_SN_SENT_LAST_SN_LSB    16
#define BAP_BAP_USER_1_SENT_SN_SENT_LAST_SN_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_1_SENT_SN_SENT_FIRST_SN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_1_SENT_SN_SENT_FIRST_SN_LSB    0
#define BAP_BAP_USER_1_SENT_SN_SENT_FIRST_SN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_1_SENT_SN_SENT_LAST_SN_RST    0x0
#define BAP_BAP_USER_1_SENT_SN_SENT_FIRST_SN_RST    0x0

__INLINE void bap_bap_user_1_sent_sn_pack(uint16_t sent_last_sn, uint16_t sent_first_sn)
{
	ASSERT_ERR((((uint32_t)sent_last_sn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)sent_first_sn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_SENT_SN_ADDR,  ((uint32_t)sent_last_sn << 16) |((uint32_t)sent_first_sn << 0));
}

__INLINE void bap_bap_user_1_sent_sn_unpack(uint16_t* sent_last_sn, uint16_t* sent_first_sn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_SENT_SN_ADDR);

	*sent_last_sn = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*sent_first_sn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_1_sent_sn_sent_last_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void bap_bap_user_1_sent_sn_sent_last_sn_setf(uint16_t sentlastsn)
{
	ASSERT_ERR((((uint32_t)sentlastsn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_1_SENT_SN_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)sentlastsn <<16));
}
__INLINE uint16_t bap_bap_user_1_sent_sn_sent_first_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_1_sent_sn_sent_first_sn_setf(uint16_t sentfirstsn)
{
	ASSERT_ERR((((uint32_t)sentfirstsn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_1_SENT_SN_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)sentfirstsn <<0));
}

/**
 * @brief BAP_USER_2_SENT_SN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 SENT_LAST_SN              0x0
 *    11:00 SENT_FIRST_SN             0x0
 * </pre>
 */
#define BAP_BAP_USER_2_SENT_SN_ADDR        (REG_BAP_BASE_ADDR+0x00000088)
#define BAP_BAP_USER_2_SENT_SN_OFFSET      0x00000088
#define BAP_BAP_USER_2_SENT_SN_INDEX       0x00000022
#define BAP_BAP_USER_2_SENT_SN_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_2_sent_sn_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_2_SENT_SN_ADDR);
}

__INLINE void bap_bap_user_2_sent_sn_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_2_SENT_SN_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_2_SENT_SN_SENT_LAST_SN_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_2_SENT_SN_SENT_LAST_SN_LSB    16
#define BAP_BAP_USER_2_SENT_SN_SENT_LAST_SN_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_2_SENT_SN_SENT_FIRST_SN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_2_SENT_SN_SENT_FIRST_SN_LSB    0
#define BAP_BAP_USER_2_SENT_SN_SENT_FIRST_SN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_2_SENT_SN_SENT_LAST_SN_RST    0x0
#define BAP_BAP_USER_2_SENT_SN_SENT_FIRST_SN_RST    0x0

__INLINE void bap_bap_user_2_sent_sn_pack(uint16_t sent_last_sn, uint16_t sent_first_sn)
{
	ASSERT_ERR((((uint32_t)sent_last_sn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)sent_first_sn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_SENT_SN_ADDR,  ((uint32_t)sent_last_sn << 16) |((uint32_t)sent_first_sn << 0));
}

__INLINE void bap_bap_user_2_sent_sn_unpack(uint16_t* sent_last_sn, uint16_t* sent_first_sn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_SENT_SN_ADDR);

	*sent_last_sn = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*sent_first_sn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_2_sent_sn_sent_last_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void bap_bap_user_2_sent_sn_sent_last_sn_setf(uint16_t sentlastsn)
{
	ASSERT_ERR((((uint32_t)sentlastsn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_2_SENT_SN_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)sentlastsn <<16));
}
__INLINE uint16_t bap_bap_user_2_sent_sn_sent_first_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_2_sent_sn_sent_first_sn_setf(uint16_t sentfirstsn)
{
	ASSERT_ERR((((uint32_t)sentfirstsn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_2_SENT_SN_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)sentfirstsn <<0));
}

/**
 * @brief BAP_USER_3_SENT_SN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 SENT_LAST_SN              0x0
 *    11:00 SENT_FIRST_SN             0x0
 * </pre>
 */
#define BAP_BAP_USER_3_SENT_SN_ADDR        (REG_BAP_BASE_ADDR+0x0000008C)
#define BAP_BAP_USER_3_SENT_SN_OFFSET      0x0000008C
#define BAP_BAP_USER_3_SENT_SN_INDEX       0x00000023
#define BAP_BAP_USER_3_SENT_SN_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_3_sent_sn_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_3_SENT_SN_ADDR);
}

__INLINE void bap_bap_user_3_sent_sn_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_3_SENT_SN_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_3_SENT_SN_SENT_LAST_SN_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_3_SENT_SN_SENT_LAST_SN_LSB    16
#define BAP_BAP_USER_3_SENT_SN_SENT_LAST_SN_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_3_SENT_SN_SENT_FIRST_SN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_3_SENT_SN_SENT_FIRST_SN_LSB    0
#define BAP_BAP_USER_3_SENT_SN_SENT_FIRST_SN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_3_SENT_SN_SENT_LAST_SN_RST    0x0
#define BAP_BAP_USER_3_SENT_SN_SENT_FIRST_SN_RST    0x0

__INLINE void bap_bap_user_3_sent_sn_pack(uint16_t sent_last_sn, uint16_t sent_first_sn)
{
	ASSERT_ERR((((uint32_t)sent_last_sn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)sent_first_sn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_SENT_SN_ADDR,  ((uint32_t)sent_last_sn << 16) |((uint32_t)sent_first_sn << 0));
}

__INLINE void bap_bap_user_3_sent_sn_unpack(uint16_t* sent_last_sn, uint16_t* sent_first_sn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_SENT_SN_ADDR);

	*sent_last_sn = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*sent_first_sn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_3_sent_sn_sent_last_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void bap_bap_user_3_sent_sn_sent_last_sn_setf(uint16_t sentlastsn)
{
	ASSERT_ERR((((uint32_t)sentlastsn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_3_SENT_SN_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)sentlastsn <<16));
}
__INLINE uint16_t bap_bap_user_3_sent_sn_sent_first_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_3_sent_sn_sent_first_sn_setf(uint16_t sentfirstsn)
{
	ASSERT_ERR((((uint32_t)sentfirstsn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_3_SENT_SN_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)sentfirstsn <<0));
}

/**
 * @brief BAP_USER_4_SENT_SN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 SENT_LAST_SN              0x0
 *    11:00 SENT_FIRST_SN             0x0
 * </pre>
 */
#define BAP_BAP_USER_4_SENT_SN_ADDR        (REG_BAP_BASE_ADDR+0x00000090)
#define BAP_BAP_USER_4_SENT_SN_OFFSET      0x00000090
#define BAP_BAP_USER_4_SENT_SN_INDEX       0x00000024
#define BAP_BAP_USER_4_SENT_SN_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_4_sent_sn_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_4_SENT_SN_ADDR);
}

__INLINE void bap_bap_user_4_sent_sn_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_4_SENT_SN_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_4_SENT_SN_SENT_LAST_SN_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_4_SENT_SN_SENT_LAST_SN_LSB    16
#define BAP_BAP_USER_4_SENT_SN_SENT_LAST_SN_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_4_SENT_SN_SENT_FIRST_SN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_4_SENT_SN_SENT_FIRST_SN_LSB    0
#define BAP_BAP_USER_4_SENT_SN_SENT_FIRST_SN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_4_SENT_SN_SENT_LAST_SN_RST    0x0
#define BAP_BAP_USER_4_SENT_SN_SENT_FIRST_SN_RST    0x0

__INLINE void bap_bap_user_4_sent_sn_pack(uint16_t sent_last_sn, uint16_t sent_first_sn)
{
	ASSERT_ERR((((uint32_t)sent_last_sn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)sent_first_sn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_SENT_SN_ADDR,  ((uint32_t)sent_last_sn << 16) |((uint32_t)sent_first_sn << 0));
}

__INLINE void bap_bap_user_4_sent_sn_unpack(uint16_t* sent_last_sn, uint16_t* sent_first_sn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_SENT_SN_ADDR);

	*sent_last_sn = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*sent_first_sn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_4_sent_sn_sent_last_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void bap_bap_user_4_sent_sn_sent_last_sn_setf(uint16_t sentlastsn)
{
	ASSERT_ERR((((uint32_t)sentlastsn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_4_SENT_SN_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)sentlastsn <<16));
}
__INLINE uint16_t bap_bap_user_4_sent_sn_sent_first_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_4_sent_sn_sent_first_sn_setf(uint16_t sentfirstsn)
{
	ASSERT_ERR((((uint32_t)sentfirstsn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_4_SENT_SN_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)sentfirstsn <<0));
}

/**
 * @brief BAP_USER_5_SENT_SN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 SENT_LAST_SN              0x0
 *    11:00 SENT_FIRST_SN             0x0
 * </pre>
 */
#define BAP_BAP_USER_5_SENT_SN_ADDR        (REG_BAP_BASE_ADDR+0x00000094)
#define BAP_BAP_USER_5_SENT_SN_OFFSET      0x00000094
#define BAP_BAP_USER_5_SENT_SN_INDEX       0x00000025
#define BAP_BAP_USER_5_SENT_SN_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_5_sent_sn_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_5_SENT_SN_ADDR);
}

__INLINE void bap_bap_user_5_sent_sn_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_5_SENT_SN_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_5_SENT_SN_SENT_LAST_SN_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_5_SENT_SN_SENT_LAST_SN_LSB    16
#define BAP_BAP_USER_5_SENT_SN_SENT_LAST_SN_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_5_SENT_SN_SENT_FIRST_SN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_5_SENT_SN_SENT_FIRST_SN_LSB    0
#define BAP_BAP_USER_5_SENT_SN_SENT_FIRST_SN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_5_SENT_SN_SENT_LAST_SN_RST    0x0
#define BAP_BAP_USER_5_SENT_SN_SENT_FIRST_SN_RST    0x0

__INLINE void bap_bap_user_5_sent_sn_pack(uint16_t sent_last_sn, uint16_t sent_first_sn)
{
	ASSERT_ERR((((uint32_t)sent_last_sn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)sent_first_sn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_SENT_SN_ADDR,  ((uint32_t)sent_last_sn << 16) |((uint32_t)sent_first_sn << 0));
}

__INLINE void bap_bap_user_5_sent_sn_unpack(uint16_t* sent_last_sn, uint16_t* sent_first_sn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_SENT_SN_ADDR);

	*sent_last_sn = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*sent_first_sn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_5_sent_sn_sent_last_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void bap_bap_user_5_sent_sn_sent_last_sn_setf(uint16_t sentlastsn)
{
	ASSERT_ERR((((uint32_t)sentlastsn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_5_SENT_SN_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)sentlastsn <<16));
}
__INLINE uint16_t bap_bap_user_5_sent_sn_sent_first_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_5_sent_sn_sent_first_sn_setf(uint16_t sentfirstsn)
{
	ASSERT_ERR((((uint32_t)sentfirstsn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_5_SENT_SN_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)sentfirstsn <<0));
}

/**
 * @brief BAP_USER_6_SENT_SN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 SENT_LAST_SN              0x0
 *    11:00 SENT_FIRST_SN             0x0
 * </pre>
 */
#define BAP_BAP_USER_6_SENT_SN_ADDR        (REG_BAP_BASE_ADDR+0x00000098)
#define BAP_BAP_USER_6_SENT_SN_OFFSET      0x00000098
#define BAP_BAP_USER_6_SENT_SN_INDEX       0x00000026
#define BAP_BAP_USER_6_SENT_SN_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_6_sent_sn_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_6_SENT_SN_ADDR);
}

__INLINE void bap_bap_user_6_sent_sn_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_6_SENT_SN_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_6_SENT_SN_SENT_LAST_SN_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_6_SENT_SN_SENT_LAST_SN_LSB    16
#define BAP_BAP_USER_6_SENT_SN_SENT_LAST_SN_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_6_SENT_SN_SENT_FIRST_SN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_6_SENT_SN_SENT_FIRST_SN_LSB    0
#define BAP_BAP_USER_6_SENT_SN_SENT_FIRST_SN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_6_SENT_SN_SENT_LAST_SN_RST    0x0
#define BAP_BAP_USER_6_SENT_SN_SENT_FIRST_SN_RST    0x0

__INLINE void bap_bap_user_6_sent_sn_pack(uint16_t sent_last_sn, uint16_t sent_first_sn)
{
	ASSERT_ERR((((uint32_t)sent_last_sn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)sent_first_sn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_SENT_SN_ADDR,  ((uint32_t)sent_last_sn << 16) |((uint32_t)sent_first_sn << 0));
}

__INLINE void bap_bap_user_6_sent_sn_unpack(uint16_t* sent_last_sn, uint16_t* sent_first_sn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_SENT_SN_ADDR);

	*sent_last_sn = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*sent_first_sn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_6_sent_sn_sent_last_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void bap_bap_user_6_sent_sn_sent_last_sn_setf(uint16_t sentlastsn)
{
	ASSERT_ERR((((uint32_t)sentlastsn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_6_SENT_SN_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)sentlastsn <<16));
}
__INLINE uint16_t bap_bap_user_6_sent_sn_sent_first_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_6_sent_sn_sent_first_sn_setf(uint16_t sentfirstsn)
{
	ASSERT_ERR((((uint32_t)sentfirstsn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_6_SENT_SN_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)sentfirstsn <<0));
}

/**
 * @brief BAP_USER_7_SENT_SN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 SENT_LAST_SN              0x0
 *    11:00 SENT_FIRST_SN             0x0
 * </pre>
 */
#define BAP_BAP_USER_7_SENT_SN_ADDR        (REG_BAP_BASE_ADDR+0x0000009C)
#define BAP_BAP_USER_7_SENT_SN_OFFSET      0x0000009C
#define BAP_BAP_USER_7_SENT_SN_INDEX       0x00000027
#define BAP_BAP_USER_7_SENT_SN_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_7_sent_sn_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_7_SENT_SN_ADDR);
}

__INLINE void bap_bap_user_7_sent_sn_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_7_SENT_SN_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_7_SENT_SN_SENT_LAST_SN_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_7_SENT_SN_SENT_LAST_SN_LSB    16
#define BAP_BAP_USER_7_SENT_SN_SENT_LAST_SN_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_7_SENT_SN_SENT_FIRST_SN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_7_SENT_SN_SENT_FIRST_SN_LSB    0
#define BAP_BAP_USER_7_SENT_SN_SENT_FIRST_SN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_7_SENT_SN_SENT_LAST_SN_RST    0x0
#define BAP_BAP_USER_7_SENT_SN_SENT_FIRST_SN_RST    0x0

__INLINE void bap_bap_user_7_sent_sn_pack(uint16_t sent_last_sn, uint16_t sent_first_sn)
{
	ASSERT_ERR((((uint32_t)sent_last_sn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)sent_first_sn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_SENT_SN_ADDR,  ((uint32_t)sent_last_sn << 16) |((uint32_t)sent_first_sn << 0));
}

__INLINE void bap_bap_user_7_sent_sn_unpack(uint16_t* sent_last_sn, uint16_t* sent_first_sn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_SENT_SN_ADDR);

	*sent_last_sn = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*sent_first_sn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_7_sent_sn_sent_last_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE void bap_bap_user_7_sent_sn_sent_last_sn_setf(uint16_t sentlastsn)
{
	ASSERT_ERR((((uint32_t)sentlastsn << 16) & ~((uint32_t)0x0FFF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_7_SENT_SN_ADDR) & ~((uint32_t)0x0FFF0000)) | ((uint32_t)sentlastsn <<16));
}
__INLINE uint16_t bap_bap_user_7_sent_sn_sent_first_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_SENT_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_7_sent_sn_sent_first_sn_setf(uint16_t sentfirstsn)
{
	ASSERT_ERR((((uint32_t)sentfirstsn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_SENT_SN_ADDR, (REG_PL_RD(BAP_BAP_USER_7_SENT_SN_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)sentfirstsn <<0));
}

/**
 * @brief BAP_SENT_BITMAP_BASE_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_BASE_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_BASE_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000A0)
#define BAP_BAP_SENT_BITMAP_BASE_ADDR_OFFSET      0x000000A0
#define BAP_BAP_SENT_BITMAP_BASE_ADDR_INDEX       0x00000028
#define BAP_BAP_SENT_BITMAP_BASE_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_base_addr_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_sent_bitmap_base_addr_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_SENT_BITMAP_BASE_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_BASE_ADDR_SENT_BITMAP_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_BASE_ADDR_SENT_BITMAP_BASE_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_BASE_ADDR_SENT_BITMAP_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_BASE_ADDR_SENT_BITMAP_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_base_addr_sent_bitmap_base_addr_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_base_addr_sent_bitmap_base_addr_setf(uint32_t sentbitmapbaseaddr, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)sentbitmapbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((BAP_BAP_SENT_BITMAP_BASE_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (uint32_t)sentbitmapbaseaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_BASE_1_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_BASE_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_BASE_1_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000A4)
#define BAP_BAP_SENT_BITMAP_BASE_1_ADDR_OFFSET      0x000000A4
#define BAP_BAP_SENT_BITMAP_BASE_1_ADDR_INDEX       0x00000029
#define BAP_BAP_SENT_BITMAP_BASE_1_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_base_1_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_1_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_base_1_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_1_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_BASE_1_ADDR_SENT_BITMAP_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_BASE_1_ADDR_SENT_BITMAP_BASE_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_BASE_1_ADDR_SENT_BITMAP_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_BASE_1_ADDR_SENT_BITMAP_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_base_1_addr_sent_bitmap_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_1_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_base_1_addr_sent_bitmap_base_addr_setf(uint32_t sentbitmapbaseaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_1_ADDR_ADDR, (uint32_t)sentbitmapbaseaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_BASE_2_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_BASE_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_BASE_2_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000A8)
#define BAP_BAP_SENT_BITMAP_BASE_2_ADDR_OFFSET      0x000000A8
#define BAP_BAP_SENT_BITMAP_BASE_2_ADDR_INDEX       0x0000002A
#define BAP_BAP_SENT_BITMAP_BASE_2_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_base_2_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_2_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_base_2_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_2_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_BASE_2_ADDR_SENT_BITMAP_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_BASE_2_ADDR_SENT_BITMAP_BASE_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_BASE_2_ADDR_SENT_BITMAP_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_BASE_2_ADDR_SENT_BITMAP_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_base_2_addr_sent_bitmap_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_2_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_base_2_addr_sent_bitmap_base_addr_setf(uint32_t sentbitmapbaseaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_2_ADDR_ADDR, (uint32_t)sentbitmapbaseaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_BASE_3_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_BASE_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_BASE_3_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000AC)
#define BAP_BAP_SENT_BITMAP_BASE_3_ADDR_OFFSET      0x000000AC
#define BAP_BAP_SENT_BITMAP_BASE_3_ADDR_INDEX       0x0000002B
#define BAP_BAP_SENT_BITMAP_BASE_3_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_base_3_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_3_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_base_3_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_3_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_BASE_3_ADDR_SENT_BITMAP_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_BASE_3_ADDR_SENT_BITMAP_BASE_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_BASE_3_ADDR_SENT_BITMAP_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_BASE_3_ADDR_SENT_BITMAP_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_base_3_addr_sent_bitmap_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_3_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_base_3_addr_sent_bitmap_base_addr_setf(uint32_t sentbitmapbaseaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_3_ADDR_ADDR, (uint32_t)sentbitmapbaseaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_BASE_4_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_BASE_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_BASE_4_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000B0)
#define BAP_BAP_SENT_BITMAP_BASE_4_ADDR_OFFSET      0x000000B0
#define BAP_BAP_SENT_BITMAP_BASE_4_ADDR_INDEX       0x0000002C
#define BAP_BAP_SENT_BITMAP_BASE_4_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_base_4_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_4_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_base_4_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_4_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_BASE_4_ADDR_SENT_BITMAP_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_BASE_4_ADDR_SENT_BITMAP_BASE_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_BASE_4_ADDR_SENT_BITMAP_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_BASE_4_ADDR_SENT_BITMAP_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_base_4_addr_sent_bitmap_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_4_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_base_4_addr_sent_bitmap_base_addr_setf(uint32_t sentbitmapbaseaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_4_ADDR_ADDR, (uint32_t)sentbitmapbaseaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_BASE_5_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_BASE_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_BASE_5_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000B4)
#define BAP_BAP_SENT_BITMAP_BASE_5_ADDR_OFFSET      0x000000B4
#define BAP_BAP_SENT_BITMAP_BASE_5_ADDR_INDEX       0x0000002D
#define BAP_BAP_SENT_BITMAP_BASE_5_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_base_5_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_5_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_base_5_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_5_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_BASE_5_ADDR_SENT_BITMAP_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_BASE_5_ADDR_SENT_BITMAP_BASE_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_BASE_5_ADDR_SENT_BITMAP_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_BASE_5_ADDR_SENT_BITMAP_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_base_5_addr_sent_bitmap_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_5_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_base_5_addr_sent_bitmap_base_addr_setf(uint32_t sentbitmapbaseaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_5_ADDR_ADDR, (uint32_t)sentbitmapbaseaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_BASE_6_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_BASE_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_BASE_6_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000B8)
#define BAP_BAP_SENT_BITMAP_BASE_6_ADDR_OFFSET      0x000000B8
#define BAP_BAP_SENT_BITMAP_BASE_6_ADDR_INDEX       0x0000002E
#define BAP_BAP_SENT_BITMAP_BASE_6_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_base_6_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_6_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_base_6_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_6_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_BASE_6_ADDR_SENT_BITMAP_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_BASE_6_ADDR_SENT_BITMAP_BASE_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_BASE_6_ADDR_SENT_BITMAP_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_BASE_6_ADDR_SENT_BITMAP_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_base_6_addr_sent_bitmap_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_6_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_base_6_addr_sent_bitmap_base_addr_setf(uint32_t sentbitmapbaseaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_6_ADDR_ADDR, (uint32_t)sentbitmapbaseaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_BASE_7_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_BASE_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_BASE_7_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000BC)
#define BAP_BAP_SENT_BITMAP_BASE_7_ADDR_OFFSET      0x000000BC
#define BAP_BAP_SENT_BITMAP_BASE_7_ADDR_INDEX       0x0000002F
#define BAP_BAP_SENT_BITMAP_BASE_7_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_base_7_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_7_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_base_7_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_7_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_BASE_7_ADDR_SENT_BITMAP_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_BASE_7_ADDR_SENT_BITMAP_BASE_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_BASE_7_ADDR_SENT_BITMAP_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_BASE_7_ADDR_SENT_BITMAP_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_base_7_addr_sent_bitmap_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_BASE_7_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_base_7_addr_sent_bitmap_base_addr_setf(uint32_t sentbitmapbaseaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_BASE_7_ADDR_ADDR, (uint32_t)sentbitmapbaseaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_WRAP_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_WRAP_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_WRAP_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000C0)
#define BAP_BAP_SENT_BITMAP_WRAP_ADDR_OFFSET      0x000000C0
#define BAP_BAP_SENT_BITMAP_WRAP_ADDR_INDEX       0x00000030
#define BAP_BAP_SENT_BITMAP_WRAP_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_wrap_addr_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_sent_bitmap_wrap_addr_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_SENT_BITMAP_WRAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_WRAP_ADDR_SENT_BITMAP_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_WRAP_ADDR_SENT_BITMAP_WRAP_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_WRAP_ADDR_SENT_BITMAP_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_WRAP_ADDR_SENT_BITMAP_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_wrap_addr_sent_bitmap_wrap_addr_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_wrap_addr_sent_bitmap_wrap_addr_setf(uint32_t sentbitmapwrapaddr, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)sentbitmapwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((BAP_BAP_SENT_BITMAP_WRAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (uint32_t)sentbitmapwrapaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_WRAP_1_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_WRAP_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_WRAP_1_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000C4)
#define BAP_BAP_SENT_BITMAP_WRAP_1_ADDR_OFFSET      0x000000C4
#define BAP_BAP_SENT_BITMAP_WRAP_1_ADDR_INDEX       0x00000031
#define BAP_BAP_SENT_BITMAP_WRAP_1_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_wrap_1_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_1_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_wrap_1_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_1_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_WRAP_1_ADDR_SENT_BITMAP_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_WRAP_1_ADDR_SENT_BITMAP_WRAP_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_WRAP_1_ADDR_SENT_BITMAP_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_WRAP_1_ADDR_SENT_BITMAP_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_wrap_1_addr_sent_bitmap_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_1_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_wrap_1_addr_sent_bitmap_wrap_addr_setf(uint32_t sentbitmapwrapaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_1_ADDR_ADDR, (uint32_t)sentbitmapwrapaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_WRAP_2_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_WRAP_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_WRAP_2_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000C8)
#define BAP_BAP_SENT_BITMAP_WRAP_2_ADDR_OFFSET      0x000000C8
#define BAP_BAP_SENT_BITMAP_WRAP_2_ADDR_INDEX       0x00000032
#define BAP_BAP_SENT_BITMAP_WRAP_2_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_wrap_2_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_2_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_wrap_2_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_2_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_WRAP_2_ADDR_SENT_BITMAP_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_WRAP_2_ADDR_SENT_BITMAP_WRAP_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_WRAP_2_ADDR_SENT_BITMAP_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_WRAP_2_ADDR_SENT_BITMAP_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_wrap_2_addr_sent_bitmap_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_2_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_wrap_2_addr_sent_bitmap_wrap_addr_setf(uint32_t sentbitmapwrapaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_2_ADDR_ADDR, (uint32_t)sentbitmapwrapaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_WRAP_3_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_WRAP_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_WRAP_3_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000CC)
#define BAP_BAP_SENT_BITMAP_WRAP_3_ADDR_OFFSET      0x000000CC
#define BAP_BAP_SENT_BITMAP_WRAP_3_ADDR_INDEX       0x00000033
#define BAP_BAP_SENT_BITMAP_WRAP_3_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_wrap_3_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_3_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_wrap_3_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_3_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_WRAP_3_ADDR_SENT_BITMAP_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_WRAP_3_ADDR_SENT_BITMAP_WRAP_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_WRAP_3_ADDR_SENT_BITMAP_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_WRAP_3_ADDR_SENT_BITMAP_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_wrap_3_addr_sent_bitmap_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_3_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_wrap_3_addr_sent_bitmap_wrap_addr_setf(uint32_t sentbitmapwrapaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_3_ADDR_ADDR, (uint32_t)sentbitmapwrapaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_WRAP_4_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_WRAP_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_WRAP_4_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000D0)
#define BAP_BAP_SENT_BITMAP_WRAP_4_ADDR_OFFSET      0x000000D0
#define BAP_BAP_SENT_BITMAP_WRAP_4_ADDR_INDEX       0x00000034
#define BAP_BAP_SENT_BITMAP_WRAP_4_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_wrap_4_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_4_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_wrap_4_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_4_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_WRAP_4_ADDR_SENT_BITMAP_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_WRAP_4_ADDR_SENT_BITMAP_WRAP_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_WRAP_4_ADDR_SENT_BITMAP_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_WRAP_4_ADDR_SENT_BITMAP_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_wrap_4_addr_sent_bitmap_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_4_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_wrap_4_addr_sent_bitmap_wrap_addr_setf(uint32_t sentbitmapwrapaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_4_ADDR_ADDR, (uint32_t)sentbitmapwrapaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_WRAP_5_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_WRAP_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_WRAP_5_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000D4)
#define BAP_BAP_SENT_BITMAP_WRAP_5_ADDR_OFFSET      0x000000D4
#define BAP_BAP_SENT_BITMAP_WRAP_5_ADDR_INDEX       0x00000035
#define BAP_BAP_SENT_BITMAP_WRAP_5_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_wrap_5_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_5_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_wrap_5_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_5_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_WRAP_5_ADDR_SENT_BITMAP_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_WRAP_5_ADDR_SENT_BITMAP_WRAP_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_WRAP_5_ADDR_SENT_BITMAP_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_WRAP_5_ADDR_SENT_BITMAP_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_wrap_5_addr_sent_bitmap_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_5_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_wrap_5_addr_sent_bitmap_wrap_addr_setf(uint32_t sentbitmapwrapaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_5_ADDR_ADDR, (uint32_t)sentbitmapwrapaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_WRAP_6_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_WRAP_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_WRAP_6_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000D8)
#define BAP_BAP_SENT_BITMAP_WRAP_6_ADDR_OFFSET      0x000000D8
#define BAP_BAP_SENT_BITMAP_WRAP_6_ADDR_INDEX       0x00000036
#define BAP_BAP_SENT_BITMAP_WRAP_6_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_wrap_6_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_6_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_wrap_6_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_6_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_WRAP_6_ADDR_SENT_BITMAP_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_WRAP_6_ADDR_SENT_BITMAP_WRAP_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_WRAP_6_ADDR_SENT_BITMAP_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_WRAP_6_ADDR_SENT_BITMAP_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_wrap_6_addr_sent_bitmap_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_6_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_wrap_6_addr_sent_bitmap_wrap_addr_setf(uint32_t sentbitmapwrapaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_6_ADDR_ADDR, (uint32_t)sentbitmapwrapaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_WRAP_7_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SENT_BITMAP_WRAP_ADDR     0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_WRAP_7_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x000000DC)
#define BAP_BAP_SENT_BITMAP_WRAP_7_ADDR_OFFSET      0x000000DC
#define BAP_BAP_SENT_BITMAP_WRAP_7_ADDR_INDEX       0x00000037
#define BAP_BAP_SENT_BITMAP_WRAP_7_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_wrap_7_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_7_ADDR_ADDR);
}

__INLINE void bap_bap_sent_bitmap_wrap_7_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_7_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_WRAP_7_ADDR_SENT_BITMAP_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_SENT_BITMAP_WRAP_7_ADDR_SENT_BITMAP_WRAP_ADDR_LSB    0
#define BAP_BAP_SENT_BITMAP_WRAP_7_ADDR_SENT_BITMAP_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_SENT_BITMAP_WRAP_7_ADDR_SENT_BITMAP_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_sent_bitmap_wrap_7_addr_sent_bitmap_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_WRAP_7_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_wrap_7_addr_sent_bitmap_wrap_addr_setf(uint32_t sentbitmapwrapaddr)
{
	ASSERT_ERR((((uint32_t)sentbitmapwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_WRAP_7_ADDR_ADDR, (uint32_t)sentbitmapwrapaddr << 0);
}

/**
 * @brief BAP_SENT_BITMAP_FIRST_INDEX register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 VALID_FIRST_INDEX         0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_FIRST_INDEX_ADDR        (REG_BAP_BASE_ADDR+0x000000E0)
#define BAP_BAP_SENT_BITMAP_FIRST_INDEX_OFFSET      0x000000E0
#define BAP_BAP_SENT_BITMAP_FIRST_INDEX_INDEX       0x00000038
#define BAP_BAP_SENT_BITMAP_FIRST_INDEX_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_first_index_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_FIRST_INDEX_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_sent_bitmap_first_index_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_SENT_BITMAP_FIRST_INDEX_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_FIRST_INDEX_VALID_FIRST_INDEX_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_SENT_BITMAP_FIRST_INDEX_VALID_FIRST_INDEX_LSB    0
#define BAP_BAP_SENT_BITMAP_FIRST_INDEX_VALID_FIRST_INDEX_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_SENT_BITMAP_FIRST_INDEX_VALID_FIRST_INDEX_RST    0x0

__INLINE uint16_t bap_bap_sent_bitmap_first_index_valid_first_index_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_FIRST_INDEX_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint16_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_first_index_valid_first_index_setf(uint16_t validfirstindex, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)validfirstindex << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR((BAP_BAP_SENT_BITMAP_FIRST_INDEX_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (uint32_t)validfirstindex << 0);
}

/**
 * @brief BAP_SENT_BITMAP_1_FIRST_INDEX register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 VALID_FIRST_INDEX         0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_1_FIRST_INDEX_ADDR        (REG_BAP_BASE_ADDR+0x000000E4)
#define BAP_BAP_SENT_BITMAP_1_FIRST_INDEX_OFFSET      0x000000E4
#define BAP_BAP_SENT_BITMAP_1_FIRST_INDEX_INDEX       0x00000039
#define BAP_BAP_SENT_BITMAP_1_FIRST_INDEX_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_1_first_index_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_1_FIRST_INDEX_ADDR);
}

__INLINE void bap_bap_sent_bitmap_1_first_index_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_1_FIRST_INDEX_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_1_FIRST_INDEX_VALID_FIRST_INDEX_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_SENT_BITMAP_1_FIRST_INDEX_VALID_FIRST_INDEX_LSB    0
#define BAP_BAP_SENT_BITMAP_1_FIRST_INDEX_VALID_FIRST_INDEX_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_SENT_BITMAP_1_FIRST_INDEX_VALID_FIRST_INDEX_RST    0x0

__INLINE uint16_t bap_bap_sent_bitmap_1_first_index_valid_first_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_1_FIRST_INDEX_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_1_first_index_valid_first_index_setf(uint16_t validfirstindex)
{
	ASSERT_ERR((((uint32_t)validfirstindex << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_1_FIRST_INDEX_ADDR, (uint32_t)validfirstindex << 0);
}

/**
 * @brief BAP_SENT_BITMAP_2_FIRST_INDEX register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 VALID_FIRST_INDEX         0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_2_FIRST_INDEX_ADDR        (REG_BAP_BASE_ADDR+0x000000E8)
#define BAP_BAP_SENT_BITMAP_2_FIRST_INDEX_OFFSET      0x000000E8
#define BAP_BAP_SENT_BITMAP_2_FIRST_INDEX_INDEX       0x0000003A
#define BAP_BAP_SENT_BITMAP_2_FIRST_INDEX_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_2_first_index_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_2_FIRST_INDEX_ADDR);
}

__INLINE void bap_bap_sent_bitmap_2_first_index_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_2_FIRST_INDEX_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_2_FIRST_INDEX_VALID_FIRST_INDEX_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_SENT_BITMAP_2_FIRST_INDEX_VALID_FIRST_INDEX_LSB    0
#define BAP_BAP_SENT_BITMAP_2_FIRST_INDEX_VALID_FIRST_INDEX_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_SENT_BITMAP_2_FIRST_INDEX_VALID_FIRST_INDEX_RST    0x0

__INLINE uint16_t bap_bap_sent_bitmap_2_first_index_valid_first_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_2_FIRST_INDEX_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_2_first_index_valid_first_index_setf(uint16_t validfirstindex)
{
	ASSERT_ERR((((uint32_t)validfirstindex << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_2_FIRST_INDEX_ADDR, (uint32_t)validfirstindex << 0);
}

/**
 * @brief BAP_SENT_BITMAP_3_FIRST_INDEX register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 VALID_FIRST_INDEX         0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_3_FIRST_INDEX_ADDR        (REG_BAP_BASE_ADDR+0x000000EC)
#define BAP_BAP_SENT_BITMAP_3_FIRST_INDEX_OFFSET      0x000000EC
#define BAP_BAP_SENT_BITMAP_3_FIRST_INDEX_INDEX       0x0000003B
#define BAP_BAP_SENT_BITMAP_3_FIRST_INDEX_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_3_first_index_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_3_FIRST_INDEX_ADDR);
}

__INLINE void bap_bap_sent_bitmap_3_first_index_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_3_FIRST_INDEX_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_3_FIRST_INDEX_VALID_FIRST_INDEX_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_SENT_BITMAP_3_FIRST_INDEX_VALID_FIRST_INDEX_LSB    0
#define BAP_BAP_SENT_BITMAP_3_FIRST_INDEX_VALID_FIRST_INDEX_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_SENT_BITMAP_3_FIRST_INDEX_VALID_FIRST_INDEX_RST    0x0

__INLINE uint16_t bap_bap_sent_bitmap_3_first_index_valid_first_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_3_FIRST_INDEX_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_3_first_index_valid_first_index_setf(uint16_t validfirstindex)
{
	ASSERT_ERR((((uint32_t)validfirstindex << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_3_FIRST_INDEX_ADDR, (uint32_t)validfirstindex << 0);
}

/**
 * @brief BAP_SENT_BITMAP_4_FIRST_INDEX register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 VALID_FIRST_INDEX         0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_4_FIRST_INDEX_ADDR        (REG_BAP_BASE_ADDR+0x000000F0)
#define BAP_BAP_SENT_BITMAP_4_FIRST_INDEX_OFFSET      0x000000F0
#define BAP_BAP_SENT_BITMAP_4_FIRST_INDEX_INDEX       0x0000003C
#define BAP_BAP_SENT_BITMAP_4_FIRST_INDEX_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_4_first_index_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_4_FIRST_INDEX_ADDR);
}

__INLINE void bap_bap_sent_bitmap_4_first_index_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_4_FIRST_INDEX_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_4_FIRST_INDEX_VALID_FIRST_INDEX_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_SENT_BITMAP_4_FIRST_INDEX_VALID_FIRST_INDEX_LSB    0
#define BAP_BAP_SENT_BITMAP_4_FIRST_INDEX_VALID_FIRST_INDEX_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_SENT_BITMAP_4_FIRST_INDEX_VALID_FIRST_INDEX_RST    0x0

__INLINE uint16_t bap_bap_sent_bitmap_4_first_index_valid_first_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_4_FIRST_INDEX_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_4_first_index_valid_first_index_setf(uint16_t validfirstindex)
{
	ASSERT_ERR((((uint32_t)validfirstindex << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_4_FIRST_INDEX_ADDR, (uint32_t)validfirstindex << 0);
}

/**
 * @brief BAP_SENT_BITMAP_5_FIRST_INDEX register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 VALID_FIRST_INDEX         0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_5_FIRST_INDEX_ADDR        (REG_BAP_BASE_ADDR+0x000000F4)
#define BAP_BAP_SENT_BITMAP_5_FIRST_INDEX_OFFSET      0x000000F4
#define BAP_BAP_SENT_BITMAP_5_FIRST_INDEX_INDEX       0x0000003D
#define BAP_BAP_SENT_BITMAP_5_FIRST_INDEX_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_5_first_index_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_5_FIRST_INDEX_ADDR);
}

__INLINE void bap_bap_sent_bitmap_5_first_index_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_5_FIRST_INDEX_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_5_FIRST_INDEX_VALID_FIRST_INDEX_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_SENT_BITMAP_5_FIRST_INDEX_VALID_FIRST_INDEX_LSB    0
#define BAP_BAP_SENT_BITMAP_5_FIRST_INDEX_VALID_FIRST_INDEX_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_SENT_BITMAP_5_FIRST_INDEX_VALID_FIRST_INDEX_RST    0x0

__INLINE uint16_t bap_bap_sent_bitmap_5_first_index_valid_first_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_5_FIRST_INDEX_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_5_first_index_valid_first_index_setf(uint16_t validfirstindex)
{
	ASSERT_ERR((((uint32_t)validfirstindex << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_5_FIRST_INDEX_ADDR, (uint32_t)validfirstindex << 0);
}

/**
 * @brief BAP_SENT_BITMAP_6_FIRST_INDEX register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 VALID_FIRST_INDEX         0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_6_FIRST_INDEX_ADDR        (REG_BAP_BASE_ADDR+0x000000F8)
#define BAP_BAP_SENT_BITMAP_6_FIRST_INDEX_OFFSET      0x000000F8
#define BAP_BAP_SENT_BITMAP_6_FIRST_INDEX_INDEX       0x0000003E
#define BAP_BAP_SENT_BITMAP_6_FIRST_INDEX_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_6_first_index_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_6_FIRST_INDEX_ADDR);
}

__INLINE void bap_bap_sent_bitmap_6_first_index_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_6_FIRST_INDEX_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_6_FIRST_INDEX_VALID_FIRST_INDEX_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_SENT_BITMAP_6_FIRST_INDEX_VALID_FIRST_INDEX_LSB    0
#define BAP_BAP_SENT_BITMAP_6_FIRST_INDEX_VALID_FIRST_INDEX_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_SENT_BITMAP_6_FIRST_INDEX_VALID_FIRST_INDEX_RST    0x0

__INLINE uint16_t bap_bap_sent_bitmap_6_first_index_valid_first_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_6_FIRST_INDEX_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_6_first_index_valid_first_index_setf(uint16_t validfirstindex)
{
	ASSERT_ERR((((uint32_t)validfirstindex << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_6_FIRST_INDEX_ADDR, (uint32_t)validfirstindex << 0);
}

/**
 * @brief BAP_SENT_BITMAP_7_FIRST_INDEX register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 VALID_FIRST_INDEX         0x0
 * </pre>
 */
#define BAP_BAP_SENT_BITMAP_7_FIRST_INDEX_ADDR        (REG_BAP_BASE_ADDR+0x000000FC)
#define BAP_BAP_SENT_BITMAP_7_FIRST_INDEX_OFFSET      0x000000FC
#define BAP_BAP_SENT_BITMAP_7_FIRST_INDEX_INDEX       0x0000003F
#define BAP_BAP_SENT_BITMAP_7_FIRST_INDEX_RESET       0x00000000

__INLINE uint32_t  bap_bap_sent_bitmap_7_first_index_get(void)
{
	return REG_PL_RD(BAP_BAP_SENT_BITMAP_7_FIRST_INDEX_ADDR);
}

__INLINE void bap_bap_sent_bitmap_7_first_index_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SENT_BITMAP_7_FIRST_INDEX_ADDR, value);
}

// field definitions
#define BAP_BAP_SENT_BITMAP_7_FIRST_INDEX_VALID_FIRST_INDEX_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_SENT_BITMAP_7_FIRST_INDEX_VALID_FIRST_INDEX_LSB    0
#define BAP_BAP_SENT_BITMAP_7_FIRST_INDEX_VALID_FIRST_INDEX_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_SENT_BITMAP_7_FIRST_INDEX_VALID_FIRST_INDEX_RST    0x0

__INLINE uint16_t bap_bap_sent_bitmap_7_first_index_valid_first_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_SENT_BITMAP_7_FIRST_INDEX_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void bap_bap_sent_bitmap_7_first_index_valid_first_index_setf(uint16_t validfirstindex)
{
	ASSERT_ERR((((uint32_t)validfirstindex << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_SENT_BITMAP_7_FIRST_INDEX_ADDR, (uint32_t)validfirstindex << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_BASE_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_BASE_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_BASE_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000100)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_ADDR_OFFSET      0x00000100
#define BAP_BAP_RETRANSMIT_CNTR_BASE_ADDR_INDEX       0x00000040
#define BAP_BAP_RETRANSMIT_CNTR_BASE_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_base_addr_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_retransmit_cntr_base_addr_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_RETRANSMIT_CNTR_BASE_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_BASE_ADDR_RETRANSMIT_CNTR_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_ADDR_RETRANSMIT_CNTR_BASE_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_BASE_ADDR_RETRANSMIT_CNTR_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_BASE_ADDR_RETRANSMIT_CNTR_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_base_addr_retransmit_cntr_base_addr_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_base_addr_retransmit_cntr_base_addr_setf(uint32_t retransmitcntrbaseaddr, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)retransmitcntrbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((BAP_BAP_RETRANSMIT_CNTR_BASE_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (uint32_t)retransmitcntrbaseaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_BASE_1_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_BASE_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_BASE_1_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000104)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_1_ADDR_OFFSET      0x00000104
#define BAP_BAP_RETRANSMIT_CNTR_BASE_1_ADDR_INDEX       0x00000041
#define BAP_BAP_RETRANSMIT_CNTR_BASE_1_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_base_1_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_1_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_base_1_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_1_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_BASE_1_ADDR_RETRANSMIT_CNTR_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_1_ADDR_RETRANSMIT_CNTR_BASE_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_BASE_1_ADDR_RETRANSMIT_CNTR_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_BASE_1_ADDR_RETRANSMIT_CNTR_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_base_1_addr_retransmit_cntr_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_1_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_base_1_addr_retransmit_cntr_base_addr_setf(uint32_t retransmitcntrbaseaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_1_ADDR_ADDR, (uint32_t)retransmitcntrbaseaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_BASE_2_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_BASE_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_BASE_2_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000108)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_2_ADDR_OFFSET      0x00000108
#define BAP_BAP_RETRANSMIT_CNTR_BASE_2_ADDR_INDEX       0x00000042
#define BAP_BAP_RETRANSMIT_CNTR_BASE_2_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_base_2_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_2_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_base_2_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_2_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_BASE_2_ADDR_RETRANSMIT_CNTR_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_2_ADDR_RETRANSMIT_CNTR_BASE_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_BASE_2_ADDR_RETRANSMIT_CNTR_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_BASE_2_ADDR_RETRANSMIT_CNTR_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_base_2_addr_retransmit_cntr_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_2_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_base_2_addr_retransmit_cntr_base_addr_setf(uint32_t retransmitcntrbaseaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_2_ADDR_ADDR, (uint32_t)retransmitcntrbaseaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_BASE_3_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_BASE_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_BASE_3_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x0000010C)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_3_ADDR_OFFSET      0x0000010C
#define BAP_BAP_RETRANSMIT_CNTR_BASE_3_ADDR_INDEX       0x00000043
#define BAP_BAP_RETRANSMIT_CNTR_BASE_3_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_base_3_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_3_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_base_3_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_3_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_BASE_3_ADDR_RETRANSMIT_CNTR_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_3_ADDR_RETRANSMIT_CNTR_BASE_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_BASE_3_ADDR_RETRANSMIT_CNTR_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_BASE_3_ADDR_RETRANSMIT_CNTR_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_base_3_addr_retransmit_cntr_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_3_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_base_3_addr_retransmit_cntr_base_addr_setf(uint32_t retransmitcntrbaseaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_3_ADDR_ADDR, (uint32_t)retransmitcntrbaseaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_BASE_4_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_BASE_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_BASE_4_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000110)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_4_ADDR_OFFSET      0x00000110
#define BAP_BAP_RETRANSMIT_CNTR_BASE_4_ADDR_INDEX       0x00000044
#define BAP_BAP_RETRANSMIT_CNTR_BASE_4_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_base_4_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_4_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_base_4_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_4_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_BASE_4_ADDR_RETRANSMIT_CNTR_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_4_ADDR_RETRANSMIT_CNTR_BASE_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_BASE_4_ADDR_RETRANSMIT_CNTR_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_BASE_4_ADDR_RETRANSMIT_CNTR_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_base_4_addr_retransmit_cntr_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_4_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_base_4_addr_retransmit_cntr_base_addr_setf(uint32_t retransmitcntrbaseaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_4_ADDR_ADDR, (uint32_t)retransmitcntrbaseaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_BASE_5_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_BASE_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_BASE_5_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000114)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_5_ADDR_OFFSET      0x00000114
#define BAP_BAP_RETRANSMIT_CNTR_BASE_5_ADDR_INDEX       0x00000045
#define BAP_BAP_RETRANSMIT_CNTR_BASE_5_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_base_5_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_5_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_base_5_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_5_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_BASE_5_ADDR_RETRANSMIT_CNTR_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_5_ADDR_RETRANSMIT_CNTR_BASE_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_BASE_5_ADDR_RETRANSMIT_CNTR_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_BASE_5_ADDR_RETRANSMIT_CNTR_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_base_5_addr_retransmit_cntr_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_5_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_base_5_addr_retransmit_cntr_base_addr_setf(uint32_t retransmitcntrbaseaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_5_ADDR_ADDR, (uint32_t)retransmitcntrbaseaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_BASE_6_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_BASE_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_BASE_6_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000118)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_6_ADDR_OFFSET      0x00000118
#define BAP_BAP_RETRANSMIT_CNTR_BASE_6_ADDR_INDEX       0x00000046
#define BAP_BAP_RETRANSMIT_CNTR_BASE_6_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_base_6_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_6_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_base_6_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_6_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_BASE_6_ADDR_RETRANSMIT_CNTR_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_6_ADDR_RETRANSMIT_CNTR_BASE_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_BASE_6_ADDR_RETRANSMIT_CNTR_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_BASE_6_ADDR_RETRANSMIT_CNTR_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_base_6_addr_retransmit_cntr_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_6_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_base_6_addr_retransmit_cntr_base_addr_setf(uint32_t retransmitcntrbaseaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_6_ADDR_ADDR, (uint32_t)retransmitcntrbaseaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_BASE_7_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_BASE_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_BASE_7_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x0000011C)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_7_ADDR_OFFSET      0x0000011C
#define BAP_BAP_RETRANSMIT_CNTR_BASE_7_ADDR_INDEX       0x00000047
#define BAP_BAP_RETRANSMIT_CNTR_BASE_7_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_base_7_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_7_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_base_7_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_7_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_BASE_7_ADDR_RETRANSMIT_CNTR_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_BASE_7_ADDR_RETRANSMIT_CNTR_BASE_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_BASE_7_ADDR_RETRANSMIT_CNTR_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_BASE_7_ADDR_RETRANSMIT_CNTR_BASE_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_base_7_addr_retransmit_cntr_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_BASE_7_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_base_7_addr_retransmit_cntr_base_addr_setf(uint32_t retransmitcntrbaseaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_BASE_7_ADDR_ADDR, (uint32_t)retransmitcntrbaseaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_WRAP_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_WRAP_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000120)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_ADDR_OFFSET      0x00000120
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_ADDR_INDEX       0x00000048
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_wrap_addr_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_retransmit_cntr_wrap_addr_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_RETRANSMIT_CNTR_WRAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_WRAP_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_wrap_addr_retransmit_cntr_wrap_addr_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_wrap_addr_retransmit_cntr_wrap_addr_setf(uint32_t retransmitcntrwrapaddr, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)retransmitcntrwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((BAP_BAP_RETRANSMIT_CNTR_WRAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (uint32_t)retransmitcntrwrapaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_WRAP_1_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_WRAP_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_1_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000124)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_1_ADDR_OFFSET      0x00000124
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_1_ADDR_INDEX       0x00000049
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_1_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_wrap_1_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_1_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_wrap_1_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_1_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_1_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_1_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_1_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_WRAP_1_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_wrap_1_addr_retransmit_cntr_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_1_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_wrap_1_addr_retransmit_cntr_wrap_addr_setf(uint32_t retransmitcntrwrapaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_1_ADDR_ADDR, (uint32_t)retransmitcntrwrapaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_WRAP_2_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_WRAP_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_2_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000128)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_2_ADDR_OFFSET      0x00000128
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_2_ADDR_INDEX       0x0000004A
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_2_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_wrap_2_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_2_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_wrap_2_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_2_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_2_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_2_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_2_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_WRAP_2_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_wrap_2_addr_retransmit_cntr_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_2_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_wrap_2_addr_retransmit_cntr_wrap_addr_setf(uint32_t retransmitcntrwrapaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_2_ADDR_ADDR, (uint32_t)retransmitcntrwrapaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_WRAP_3_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_WRAP_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_3_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x0000012C)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_3_ADDR_OFFSET      0x0000012C
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_3_ADDR_INDEX       0x0000004B
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_3_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_wrap_3_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_3_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_wrap_3_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_3_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_3_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_3_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_3_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_WRAP_3_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_wrap_3_addr_retransmit_cntr_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_3_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_wrap_3_addr_retransmit_cntr_wrap_addr_setf(uint32_t retransmitcntrwrapaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_3_ADDR_ADDR, (uint32_t)retransmitcntrwrapaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_WRAP_4_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_WRAP_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_4_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000130)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_4_ADDR_OFFSET      0x00000130
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_4_ADDR_INDEX       0x0000004C
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_4_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_wrap_4_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_4_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_wrap_4_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_4_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_4_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_4_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_4_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_WRAP_4_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_wrap_4_addr_retransmit_cntr_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_4_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_wrap_4_addr_retransmit_cntr_wrap_addr_setf(uint32_t retransmitcntrwrapaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_4_ADDR_ADDR, (uint32_t)retransmitcntrwrapaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_WRAP_5_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_WRAP_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_5_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000134)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_5_ADDR_OFFSET      0x00000134
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_5_ADDR_INDEX       0x0000004D
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_5_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_wrap_5_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_5_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_wrap_5_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_5_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_5_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_5_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_5_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_WRAP_5_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_wrap_5_addr_retransmit_cntr_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_5_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_wrap_5_addr_retransmit_cntr_wrap_addr_setf(uint32_t retransmitcntrwrapaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_5_ADDR_ADDR, (uint32_t)retransmitcntrwrapaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_WRAP_6_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_WRAP_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_6_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000138)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_6_ADDR_OFFSET      0x00000138
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_6_ADDR_INDEX       0x0000004E
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_6_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_wrap_6_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_6_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_wrap_6_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_6_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_6_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_6_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_6_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_WRAP_6_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_wrap_6_addr_retransmit_cntr_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_6_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_wrap_6_addr_retransmit_cntr_wrap_addr_setf(uint32_t retransmitcntrwrapaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_6_ADDR_ADDR, (uint32_t)retransmitcntrwrapaddr << 0);
}

/**
 * @brief BAP_RETRANSMIT_CNTR_WRAP_7_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RETRANSMIT_CNTR_WRAP_ADDR 0x0
 * </pre>
 */
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_7_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x0000013C)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_7_ADDR_OFFSET      0x0000013C
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_7_ADDR_INDEX       0x0000004F
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_7_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_retransmit_cntr_wrap_7_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_7_ADDR_ADDR);
}

__INLINE void bap_bap_retransmit_cntr_wrap_7_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_7_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_7_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_7_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_LSB    0
#define BAP_BAP_RETRANSMIT_CNTR_WRAP_7_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RETRANSMIT_CNTR_WRAP_7_ADDR_RETRANSMIT_CNTR_WRAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_retransmit_cntr_wrap_7_addr_retransmit_cntr_wrap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RETRANSMIT_CNTR_WRAP_7_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_retransmit_cntr_wrap_7_addr_retransmit_cntr_wrap_addr_setf(uint32_t retransmitcntrwrapaddr)
{
	ASSERT_ERR((((uint32_t)retransmitcntrwrapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RETRANSMIT_CNTR_WRAP_7_ADDR_ADDR, (uint32_t)retransmitcntrwrapaddr << 0);
}

/**
 * @brief BAP_USER_RCVD_PARAMETERS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 BA_AGREEMENT_SIZE         0x0
 *    23:16 RCVD_BITMAP_SIZE          0x0
 *    11:00 RCVD_SSN                  0x0
 * </pre>
 */
#define BAP_BAP_USER_RCVD_PARAMETERS_ADDR        (REG_BAP_BASE_ADDR+0x00000140)
#define BAP_BAP_USER_RCVD_PARAMETERS_OFFSET      0x00000140
#define BAP_BAP_USER_RCVD_PARAMETERS_INDEX       0x00000050
#define BAP_BAP_USER_RCVD_PARAMETERS_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_rcvd_parameters_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_user_rcvd_parameters_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_USER_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_MASK    ((uint32_t)0xFF000000)
#define BAP_BAP_USER_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_LSB    24
#define BAP_BAP_USER_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_USER_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_LSB    16
#define BAP_BAP_USER_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_RCVD_PARAMETERS_RCVD_SSN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_RCVD_PARAMETERS_RCVD_SSN_LSB    0
#define BAP_BAP_USER_RCVD_PARAMETERS_RCVD_SSN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_RST    0x0
#define BAP_BAP_USER_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_RST    0x0
#define BAP_BAP_USER_RCVD_PARAMETERS_RCVD_SSN_RST    0x0

__INLINE void bap_bap_user_rcvd_parameters_pack(uint8_t ba_agreement_size, uint8_t rcvd_bitmap_size, uint16_t rcvd_ssn, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)ba_agreement_size << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_bitmap_size << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_ssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR((BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)),  ((uint32_t)ba_agreement_size << 24) |((uint32_t)rcvd_bitmap_size << 16) |((uint32_t)rcvd_ssn << 0));
}

__INLINE void bap_bap_user_rcvd_parameters_unpack(uint8_t* ba_agreement_size, uint8_t* rcvd_bitmap_size, uint16_t* rcvd_ssn, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));

	*ba_agreement_size = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rcvd_bitmap_size = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rcvd_ssn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_rcvd_parameters_ba_agreement_size_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void bap_bap_user_rcvd_parameters_ba_agreement_size_setf(uint8_t baagreementsize,uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)baagreementsize << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR((BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (REG_PL_RD(BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)) & ~((uint32_t)0xFF000000)) | ((uint32_t)baagreementsize <<24));
}
__INLINE uint8_t bap_bap_user_rcvd_parameters_rcvd_bitmap_size_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void bap_bap_user_rcvd_parameters_rcvd_bitmap_size_setf(uint8_t rcvdbitmapsize,uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)rcvdbitmapsize << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR((BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (REG_PL_RD(BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rcvdbitmapsize <<16));
}
__INLINE uint16_t bap_bap_user_rcvd_parameters_rcvd_ssn_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_rcvd_parameters_rcvd_ssn_setf(uint16_t rcvdssn,uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)rcvdssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR((BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (REG_PL_RD(BAP_BAP_USER_RCVD_PARAMETERS_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)) & ~((uint32_t)0x00000FFF)) | ((uint32_t)rcvdssn <<0));
}

/**
 * @brief BAP_USER_1_RCVD_PARAMETERS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 BA_AGREEMENT_SIZE         0x0
 *    23:16 RCVD_BITMAP_SIZE          0x0
 *    11:00 RCVD_SSN                  0x0
 * </pre>
 */
#define BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR        (REG_BAP_BASE_ADDR+0x00000144)
#define BAP_BAP_USER_1_RCVD_PARAMETERS_OFFSET      0x00000144
#define BAP_BAP_USER_1_RCVD_PARAMETERS_INDEX       0x00000051
#define BAP_BAP_USER_1_RCVD_PARAMETERS_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_1_rcvd_parameters_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR);
}

__INLINE void bap_bap_user_1_rcvd_parameters_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_1_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_MASK    ((uint32_t)0xFF000000)
#define BAP_BAP_USER_1_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_LSB    24
#define BAP_BAP_USER_1_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_1_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_USER_1_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_LSB    16
#define BAP_BAP_USER_1_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_1_RCVD_PARAMETERS_RCVD_SSN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_1_RCVD_PARAMETERS_RCVD_SSN_LSB    0
#define BAP_BAP_USER_1_RCVD_PARAMETERS_RCVD_SSN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_1_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_RST    0x0
#define BAP_BAP_USER_1_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_RST    0x0
#define BAP_BAP_USER_1_RCVD_PARAMETERS_RCVD_SSN_RST    0x0

__INLINE void bap_bap_user_1_rcvd_parameters_pack(uint8_t ba_agreement_size, uint8_t rcvd_bitmap_size, uint16_t rcvd_ssn)
{
	ASSERT_ERR((((uint32_t)ba_agreement_size << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_bitmap_size << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_ssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR,  ((uint32_t)ba_agreement_size << 24) |((uint32_t)rcvd_bitmap_size << 16) |((uint32_t)rcvd_ssn << 0));
}

__INLINE void bap_bap_user_1_rcvd_parameters_unpack(uint8_t* ba_agreement_size, uint8_t* rcvd_bitmap_size, uint16_t* rcvd_ssn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR);

	*ba_agreement_size = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rcvd_bitmap_size = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rcvd_ssn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_1_rcvd_parameters_ba_agreement_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void bap_bap_user_1_rcvd_parameters_ba_agreement_size_setf(uint8_t baagreementsize)
{
	ASSERT_ERR((((uint32_t)baagreementsize << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)baagreementsize <<24));
}
__INLINE uint8_t bap_bap_user_1_rcvd_parameters_rcvd_bitmap_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void bap_bap_user_1_rcvd_parameters_rcvd_bitmap_size_setf(uint8_t rcvdbitmapsize)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapsize << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rcvdbitmapsize <<16));
}
__INLINE uint16_t bap_bap_user_1_rcvd_parameters_rcvd_ssn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_1_rcvd_parameters_rcvd_ssn_setf(uint16_t rcvdssn)
{
	ASSERT_ERR((((uint32_t)rcvdssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_1_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)rcvdssn <<0));
}

/**
 * @brief BAP_USER_2_RCVD_PARAMETERS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 BA_AGREEMENT_SIZE         0x0
 *    23:16 RCVD_BITMAP_SIZE          0x0
 *    11:00 RCVD_SSN                  0x0
 * </pre>
 */
#define BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR        (REG_BAP_BASE_ADDR+0x00000148)
#define BAP_BAP_USER_2_RCVD_PARAMETERS_OFFSET      0x00000148
#define BAP_BAP_USER_2_RCVD_PARAMETERS_INDEX       0x00000052
#define BAP_BAP_USER_2_RCVD_PARAMETERS_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_2_rcvd_parameters_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR);
}

__INLINE void bap_bap_user_2_rcvd_parameters_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_2_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_MASK    ((uint32_t)0xFF000000)
#define BAP_BAP_USER_2_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_LSB    24
#define BAP_BAP_USER_2_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_2_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_USER_2_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_LSB    16
#define BAP_BAP_USER_2_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_2_RCVD_PARAMETERS_RCVD_SSN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_2_RCVD_PARAMETERS_RCVD_SSN_LSB    0
#define BAP_BAP_USER_2_RCVD_PARAMETERS_RCVD_SSN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_2_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_RST    0x0
#define BAP_BAP_USER_2_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_RST    0x0
#define BAP_BAP_USER_2_RCVD_PARAMETERS_RCVD_SSN_RST    0x0

__INLINE void bap_bap_user_2_rcvd_parameters_pack(uint8_t ba_agreement_size, uint8_t rcvd_bitmap_size, uint16_t rcvd_ssn)
{
	ASSERT_ERR((((uint32_t)ba_agreement_size << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_bitmap_size << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_ssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR,  ((uint32_t)ba_agreement_size << 24) |((uint32_t)rcvd_bitmap_size << 16) |((uint32_t)rcvd_ssn << 0));
}

__INLINE void bap_bap_user_2_rcvd_parameters_unpack(uint8_t* ba_agreement_size, uint8_t* rcvd_bitmap_size, uint16_t* rcvd_ssn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR);

	*ba_agreement_size = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rcvd_bitmap_size = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rcvd_ssn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_2_rcvd_parameters_ba_agreement_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void bap_bap_user_2_rcvd_parameters_ba_agreement_size_setf(uint8_t baagreementsize)
{
	ASSERT_ERR((((uint32_t)baagreementsize << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)baagreementsize <<24));
}
__INLINE uint8_t bap_bap_user_2_rcvd_parameters_rcvd_bitmap_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void bap_bap_user_2_rcvd_parameters_rcvd_bitmap_size_setf(uint8_t rcvdbitmapsize)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapsize << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rcvdbitmapsize <<16));
}
__INLINE uint16_t bap_bap_user_2_rcvd_parameters_rcvd_ssn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_2_rcvd_parameters_rcvd_ssn_setf(uint16_t rcvdssn)
{
	ASSERT_ERR((((uint32_t)rcvdssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_2_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)rcvdssn <<0));
}

/**
 * @brief BAP_USER_3_RCVD_PARAMETERS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 BA_AGREEMENT_SIZE         0x0
 *    23:16 RCVD_BITMAP_SIZE          0x0
 *    11:00 RCVD_SSN                  0x0
 * </pre>
 */
#define BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR        (REG_BAP_BASE_ADDR+0x0000014C)
#define BAP_BAP_USER_3_RCVD_PARAMETERS_OFFSET      0x0000014C
#define BAP_BAP_USER_3_RCVD_PARAMETERS_INDEX       0x00000053
#define BAP_BAP_USER_3_RCVD_PARAMETERS_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_3_rcvd_parameters_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR);
}

__INLINE void bap_bap_user_3_rcvd_parameters_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_3_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_MASK    ((uint32_t)0xFF000000)
#define BAP_BAP_USER_3_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_LSB    24
#define BAP_BAP_USER_3_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_3_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_USER_3_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_LSB    16
#define BAP_BAP_USER_3_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_3_RCVD_PARAMETERS_RCVD_SSN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_3_RCVD_PARAMETERS_RCVD_SSN_LSB    0
#define BAP_BAP_USER_3_RCVD_PARAMETERS_RCVD_SSN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_3_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_RST    0x0
#define BAP_BAP_USER_3_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_RST    0x0
#define BAP_BAP_USER_3_RCVD_PARAMETERS_RCVD_SSN_RST    0x0

__INLINE void bap_bap_user_3_rcvd_parameters_pack(uint8_t ba_agreement_size, uint8_t rcvd_bitmap_size, uint16_t rcvd_ssn)
{
	ASSERT_ERR((((uint32_t)ba_agreement_size << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_bitmap_size << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_ssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR,  ((uint32_t)ba_agreement_size << 24) |((uint32_t)rcvd_bitmap_size << 16) |((uint32_t)rcvd_ssn << 0));
}

__INLINE void bap_bap_user_3_rcvd_parameters_unpack(uint8_t* ba_agreement_size, uint8_t* rcvd_bitmap_size, uint16_t* rcvd_ssn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR);

	*ba_agreement_size = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rcvd_bitmap_size = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rcvd_ssn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_3_rcvd_parameters_ba_agreement_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void bap_bap_user_3_rcvd_parameters_ba_agreement_size_setf(uint8_t baagreementsize)
{
	ASSERT_ERR((((uint32_t)baagreementsize << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)baagreementsize <<24));
}
__INLINE uint8_t bap_bap_user_3_rcvd_parameters_rcvd_bitmap_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void bap_bap_user_3_rcvd_parameters_rcvd_bitmap_size_setf(uint8_t rcvdbitmapsize)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapsize << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rcvdbitmapsize <<16));
}
__INLINE uint16_t bap_bap_user_3_rcvd_parameters_rcvd_ssn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_3_rcvd_parameters_rcvd_ssn_setf(uint16_t rcvdssn)
{
	ASSERT_ERR((((uint32_t)rcvdssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_3_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)rcvdssn <<0));
}

/**
 * @brief BAP_USER_4_RCVD_PARAMETERS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 BA_AGREEMENT_SIZE         0x0
 *    23:16 RCVD_BITMAP_SIZE          0x0
 *    11:00 RCVD_SSN                  0x0
 * </pre>
 */
#define BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR        (REG_BAP_BASE_ADDR+0x00000150)
#define BAP_BAP_USER_4_RCVD_PARAMETERS_OFFSET      0x00000150
#define BAP_BAP_USER_4_RCVD_PARAMETERS_INDEX       0x00000054
#define BAP_BAP_USER_4_RCVD_PARAMETERS_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_4_rcvd_parameters_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR);
}

__INLINE void bap_bap_user_4_rcvd_parameters_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_4_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_MASK    ((uint32_t)0xFF000000)
#define BAP_BAP_USER_4_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_LSB    24
#define BAP_BAP_USER_4_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_4_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_USER_4_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_LSB    16
#define BAP_BAP_USER_4_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_4_RCVD_PARAMETERS_RCVD_SSN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_4_RCVD_PARAMETERS_RCVD_SSN_LSB    0
#define BAP_BAP_USER_4_RCVD_PARAMETERS_RCVD_SSN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_4_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_RST    0x0
#define BAP_BAP_USER_4_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_RST    0x0
#define BAP_BAP_USER_4_RCVD_PARAMETERS_RCVD_SSN_RST    0x0

__INLINE void bap_bap_user_4_rcvd_parameters_pack(uint8_t ba_agreement_size, uint8_t rcvd_bitmap_size, uint16_t rcvd_ssn)
{
	ASSERT_ERR((((uint32_t)ba_agreement_size << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_bitmap_size << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_ssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR,  ((uint32_t)ba_agreement_size << 24) |((uint32_t)rcvd_bitmap_size << 16) |((uint32_t)rcvd_ssn << 0));
}

__INLINE void bap_bap_user_4_rcvd_parameters_unpack(uint8_t* ba_agreement_size, uint8_t* rcvd_bitmap_size, uint16_t* rcvd_ssn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR);

	*ba_agreement_size = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rcvd_bitmap_size = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rcvd_ssn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_4_rcvd_parameters_ba_agreement_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void bap_bap_user_4_rcvd_parameters_ba_agreement_size_setf(uint8_t baagreementsize)
{
	ASSERT_ERR((((uint32_t)baagreementsize << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)baagreementsize <<24));
}
__INLINE uint8_t bap_bap_user_4_rcvd_parameters_rcvd_bitmap_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void bap_bap_user_4_rcvd_parameters_rcvd_bitmap_size_setf(uint8_t rcvdbitmapsize)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapsize << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rcvdbitmapsize <<16));
}
__INLINE uint16_t bap_bap_user_4_rcvd_parameters_rcvd_ssn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_4_rcvd_parameters_rcvd_ssn_setf(uint16_t rcvdssn)
{
	ASSERT_ERR((((uint32_t)rcvdssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_4_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)rcvdssn <<0));
}

/**
 * @brief BAP_USER_5_RCVD_PARAMETERS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 BA_AGREEMENT_SIZE         0x0
 *    23:16 RCVD_BITMAP_SIZE          0x0
 *    11:00 RCVD_SSN                  0x0
 * </pre>
 */
#define BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR        (REG_BAP_BASE_ADDR+0x00000154)
#define BAP_BAP_USER_5_RCVD_PARAMETERS_OFFSET      0x00000154
#define BAP_BAP_USER_5_RCVD_PARAMETERS_INDEX       0x00000055
#define BAP_BAP_USER_5_RCVD_PARAMETERS_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_5_rcvd_parameters_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR);
}

__INLINE void bap_bap_user_5_rcvd_parameters_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_5_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_MASK    ((uint32_t)0xFF000000)
#define BAP_BAP_USER_5_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_LSB    24
#define BAP_BAP_USER_5_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_5_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_USER_5_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_LSB    16
#define BAP_BAP_USER_5_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_5_RCVD_PARAMETERS_RCVD_SSN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_5_RCVD_PARAMETERS_RCVD_SSN_LSB    0
#define BAP_BAP_USER_5_RCVD_PARAMETERS_RCVD_SSN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_5_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_RST    0x0
#define BAP_BAP_USER_5_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_RST    0x0
#define BAP_BAP_USER_5_RCVD_PARAMETERS_RCVD_SSN_RST    0x0

__INLINE void bap_bap_user_5_rcvd_parameters_pack(uint8_t ba_agreement_size, uint8_t rcvd_bitmap_size, uint16_t rcvd_ssn)
{
	ASSERT_ERR((((uint32_t)ba_agreement_size << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_bitmap_size << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_ssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR,  ((uint32_t)ba_agreement_size << 24) |((uint32_t)rcvd_bitmap_size << 16) |((uint32_t)rcvd_ssn << 0));
}

__INLINE void bap_bap_user_5_rcvd_parameters_unpack(uint8_t* ba_agreement_size, uint8_t* rcvd_bitmap_size, uint16_t* rcvd_ssn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR);

	*ba_agreement_size = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rcvd_bitmap_size = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rcvd_ssn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_5_rcvd_parameters_ba_agreement_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void bap_bap_user_5_rcvd_parameters_ba_agreement_size_setf(uint8_t baagreementsize)
{
	ASSERT_ERR((((uint32_t)baagreementsize << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)baagreementsize <<24));
}
__INLINE uint8_t bap_bap_user_5_rcvd_parameters_rcvd_bitmap_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void bap_bap_user_5_rcvd_parameters_rcvd_bitmap_size_setf(uint8_t rcvdbitmapsize)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapsize << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rcvdbitmapsize <<16));
}
__INLINE uint16_t bap_bap_user_5_rcvd_parameters_rcvd_ssn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_5_rcvd_parameters_rcvd_ssn_setf(uint16_t rcvdssn)
{
	ASSERT_ERR((((uint32_t)rcvdssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_5_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)rcvdssn <<0));
}

/**
 * @brief BAP_USER_6_RCVD_PARAMETERS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 BA_AGREEMENT_SIZE         0x0
 *    23:16 RCVD_BITMAP_SIZE          0x0
 *    11:00 RCVD_SSN                  0x0
 * </pre>
 */
#define BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR        (REG_BAP_BASE_ADDR+0x00000158)
#define BAP_BAP_USER_6_RCVD_PARAMETERS_OFFSET      0x00000158
#define BAP_BAP_USER_6_RCVD_PARAMETERS_INDEX       0x00000056
#define BAP_BAP_USER_6_RCVD_PARAMETERS_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_6_rcvd_parameters_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR);
}

__INLINE void bap_bap_user_6_rcvd_parameters_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_6_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_MASK    ((uint32_t)0xFF000000)
#define BAP_BAP_USER_6_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_LSB    24
#define BAP_BAP_USER_6_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_6_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_USER_6_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_LSB    16
#define BAP_BAP_USER_6_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_6_RCVD_PARAMETERS_RCVD_SSN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_6_RCVD_PARAMETERS_RCVD_SSN_LSB    0
#define BAP_BAP_USER_6_RCVD_PARAMETERS_RCVD_SSN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_6_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_RST    0x0
#define BAP_BAP_USER_6_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_RST    0x0
#define BAP_BAP_USER_6_RCVD_PARAMETERS_RCVD_SSN_RST    0x0

__INLINE void bap_bap_user_6_rcvd_parameters_pack(uint8_t ba_agreement_size, uint8_t rcvd_bitmap_size, uint16_t rcvd_ssn)
{
	ASSERT_ERR((((uint32_t)ba_agreement_size << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_bitmap_size << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_ssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR,  ((uint32_t)ba_agreement_size << 24) |((uint32_t)rcvd_bitmap_size << 16) |((uint32_t)rcvd_ssn << 0));
}

__INLINE void bap_bap_user_6_rcvd_parameters_unpack(uint8_t* ba_agreement_size, uint8_t* rcvd_bitmap_size, uint16_t* rcvd_ssn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR);

	*ba_agreement_size = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rcvd_bitmap_size = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rcvd_ssn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_6_rcvd_parameters_ba_agreement_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void bap_bap_user_6_rcvd_parameters_ba_agreement_size_setf(uint8_t baagreementsize)
{
	ASSERT_ERR((((uint32_t)baagreementsize << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)baagreementsize <<24));
}
__INLINE uint8_t bap_bap_user_6_rcvd_parameters_rcvd_bitmap_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void bap_bap_user_6_rcvd_parameters_rcvd_bitmap_size_setf(uint8_t rcvdbitmapsize)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapsize << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rcvdbitmapsize <<16));
}
__INLINE uint16_t bap_bap_user_6_rcvd_parameters_rcvd_ssn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_6_rcvd_parameters_rcvd_ssn_setf(uint16_t rcvdssn)
{
	ASSERT_ERR((((uint32_t)rcvdssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_6_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)rcvdssn <<0));
}

/**
 * @brief BAP_USER_7_RCVD_PARAMETERS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 BA_AGREEMENT_SIZE         0x0
 *    23:16 RCVD_BITMAP_SIZE          0x0
 *    11:00 RCVD_SSN                  0x0
 * </pre>
 */
#define BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR        (REG_BAP_BASE_ADDR+0x0000015C)
#define BAP_BAP_USER_7_RCVD_PARAMETERS_OFFSET      0x0000015C
#define BAP_BAP_USER_7_RCVD_PARAMETERS_INDEX       0x00000057
#define BAP_BAP_USER_7_RCVD_PARAMETERS_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_7_rcvd_parameters_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR);
}

__INLINE void bap_bap_user_7_rcvd_parameters_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_7_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_MASK    ((uint32_t)0xFF000000)
#define BAP_BAP_USER_7_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_LSB    24
#define BAP_BAP_USER_7_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_7_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_USER_7_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_LSB    16
#define BAP_BAP_USER_7_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_USER_7_RCVD_PARAMETERS_RCVD_SSN_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_7_RCVD_PARAMETERS_RCVD_SSN_LSB    0
#define BAP_BAP_USER_7_RCVD_PARAMETERS_RCVD_SSN_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_7_RCVD_PARAMETERS_BA_AGREEMENT_SIZE_RST    0x0
#define BAP_BAP_USER_7_RCVD_PARAMETERS_RCVD_BITMAP_SIZE_RST    0x0
#define BAP_BAP_USER_7_RCVD_PARAMETERS_RCVD_SSN_RST    0x0

__INLINE void bap_bap_user_7_rcvd_parameters_pack(uint8_t ba_agreement_size, uint8_t rcvd_bitmap_size, uint16_t rcvd_ssn)
{
	ASSERT_ERR((((uint32_t)ba_agreement_size << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_bitmap_size << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)rcvd_ssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR,  ((uint32_t)ba_agreement_size << 24) |((uint32_t)rcvd_bitmap_size << 16) |((uint32_t)rcvd_ssn << 0));
}

__INLINE void bap_bap_user_7_rcvd_parameters_unpack(uint8_t* ba_agreement_size, uint8_t* rcvd_bitmap_size, uint16_t* rcvd_ssn)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR);

	*ba_agreement_size = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rcvd_bitmap_size = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rcvd_ssn = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_7_rcvd_parameters_ba_agreement_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void bap_bap_user_7_rcvd_parameters_ba_agreement_size_setf(uint8_t baagreementsize)
{
	ASSERT_ERR((((uint32_t)baagreementsize << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)baagreementsize <<24));
}
__INLINE uint8_t bap_bap_user_7_rcvd_parameters_rcvd_bitmap_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void bap_bap_user_7_rcvd_parameters_rcvd_bitmap_size_setf(uint8_t rcvdbitmapsize)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapsize << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)rcvdbitmapsize <<16));
}
__INLINE uint16_t bap_bap_user_7_rcvd_parameters_rcvd_ssn_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void bap_bap_user_7_rcvd_parameters_rcvd_ssn_setf(uint16_t rcvdssn)
{
	ASSERT_ERR((((uint32_t)rcvdssn << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR, (REG_PL_RD(BAP_BAP_USER_7_RCVD_PARAMETERS_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)rcvdssn <<0));
}

/**
 * @brief BAP_RCVD_BITMAP_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RCVD_BITMAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_RCVD_BITMAP_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000160)
#define BAP_BAP_RCVD_BITMAP_ADDR_OFFSET      0x00000160
#define BAP_BAP_RCVD_BITMAP_ADDR_INDEX       0x00000058
#define BAP_BAP_RCVD_BITMAP_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_rcvd_bitmap_addr_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_RCVD_BITMAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_rcvd_bitmap_addr_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_RCVD_BITMAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_RCVD_BITMAP_ADDR_RCVD_BITMAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RCVD_BITMAP_ADDR_RCVD_BITMAP_ADDR_LSB    0
#define BAP_BAP_RCVD_BITMAP_ADDR_RCVD_BITMAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RCVD_BITMAP_ADDR_RCVD_BITMAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_rcvd_bitmap_addr_rcvd_bitmap_addr_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_RCVD_BITMAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_rcvd_bitmap_addr_rcvd_bitmap_addr_setf(uint32_t rcvdbitmapaddr, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)rcvdbitmapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((BAP_BAP_RCVD_BITMAP_ADDR_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (uint32_t)rcvdbitmapaddr << 0);
}

/**
 * @brief BAP_RCVD_BITMAP_1_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RCVD_BITMAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_RCVD_BITMAP_1_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000164)
#define BAP_BAP_RCVD_BITMAP_1_ADDR_OFFSET      0x00000164
#define BAP_BAP_RCVD_BITMAP_1_ADDR_INDEX       0x00000059
#define BAP_BAP_RCVD_BITMAP_1_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_rcvd_bitmap_1_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RCVD_BITMAP_1_ADDR_ADDR);
}

__INLINE void bap_bap_rcvd_bitmap_1_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_1_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RCVD_BITMAP_1_ADDR_RCVD_BITMAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RCVD_BITMAP_1_ADDR_RCVD_BITMAP_ADDR_LSB    0
#define BAP_BAP_RCVD_BITMAP_1_ADDR_RCVD_BITMAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RCVD_BITMAP_1_ADDR_RCVD_BITMAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_rcvd_bitmap_1_addr_rcvd_bitmap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RCVD_BITMAP_1_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_rcvd_bitmap_1_addr_rcvd_bitmap_addr_setf(uint32_t rcvdbitmapaddr)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_1_ADDR_ADDR, (uint32_t)rcvdbitmapaddr << 0);
}

/**
 * @brief BAP_RCVD_BITMAP_2_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RCVD_BITMAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_RCVD_BITMAP_2_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000168)
#define BAP_BAP_RCVD_BITMAP_2_ADDR_OFFSET      0x00000168
#define BAP_BAP_RCVD_BITMAP_2_ADDR_INDEX       0x0000005A
#define BAP_BAP_RCVD_BITMAP_2_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_rcvd_bitmap_2_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RCVD_BITMAP_2_ADDR_ADDR);
}

__INLINE void bap_bap_rcvd_bitmap_2_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_2_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RCVD_BITMAP_2_ADDR_RCVD_BITMAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RCVD_BITMAP_2_ADDR_RCVD_BITMAP_ADDR_LSB    0
#define BAP_BAP_RCVD_BITMAP_2_ADDR_RCVD_BITMAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RCVD_BITMAP_2_ADDR_RCVD_BITMAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_rcvd_bitmap_2_addr_rcvd_bitmap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RCVD_BITMAP_2_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_rcvd_bitmap_2_addr_rcvd_bitmap_addr_setf(uint32_t rcvdbitmapaddr)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_2_ADDR_ADDR, (uint32_t)rcvdbitmapaddr << 0);
}

/**
 * @brief BAP_RCVD_BITMAP_3_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RCVD_BITMAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_RCVD_BITMAP_3_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x0000016C)
#define BAP_BAP_RCVD_BITMAP_3_ADDR_OFFSET      0x0000016C
#define BAP_BAP_RCVD_BITMAP_3_ADDR_INDEX       0x0000005B
#define BAP_BAP_RCVD_BITMAP_3_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_rcvd_bitmap_3_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RCVD_BITMAP_3_ADDR_ADDR);
}

__INLINE void bap_bap_rcvd_bitmap_3_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_3_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RCVD_BITMAP_3_ADDR_RCVD_BITMAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RCVD_BITMAP_3_ADDR_RCVD_BITMAP_ADDR_LSB    0
#define BAP_BAP_RCVD_BITMAP_3_ADDR_RCVD_BITMAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RCVD_BITMAP_3_ADDR_RCVD_BITMAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_rcvd_bitmap_3_addr_rcvd_bitmap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RCVD_BITMAP_3_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_rcvd_bitmap_3_addr_rcvd_bitmap_addr_setf(uint32_t rcvdbitmapaddr)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_3_ADDR_ADDR, (uint32_t)rcvdbitmapaddr << 0);
}

/**
 * @brief BAP_RCVD_BITMAP_4_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RCVD_BITMAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_RCVD_BITMAP_4_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000170)
#define BAP_BAP_RCVD_BITMAP_4_ADDR_OFFSET      0x00000170
#define BAP_BAP_RCVD_BITMAP_4_ADDR_INDEX       0x0000005C
#define BAP_BAP_RCVD_BITMAP_4_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_rcvd_bitmap_4_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RCVD_BITMAP_4_ADDR_ADDR);
}

__INLINE void bap_bap_rcvd_bitmap_4_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_4_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RCVD_BITMAP_4_ADDR_RCVD_BITMAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RCVD_BITMAP_4_ADDR_RCVD_BITMAP_ADDR_LSB    0
#define BAP_BAP_RCVD_BITMAP_4_ADDR_RCVD_BITMAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RCVD_BITMAP_4_ADDR_RCVD_BITMAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_rcvd_bitmap_4_addr_rcvd_bitmap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RCVD_BITMAP_4_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_rcvd_bitmap_4_addr_rcvd_bitmap_addr_setf(uint32_t rcvdbitmapaddr)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_4_ADDR_ADDR, (uint32_t)rcvdbitmapaddr << 0);
}

/**
 * @brief BAP_RCVD_BITMAP_5_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RCVD_BITMAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_RCVD_BITMAP_5_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000174)
#define BAP_BAP_RCVD_BITMAP_5_ADDR_OFFSET      0x00000174
#define BAP_BAP_RCVD_BITMAP_5_ADDR_INDEX       0x0000005D
#define BAP_BAP_RCVD_BITMAP_5_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_rcvd_bitmap_5_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RCVD_BITMAP_5_ADDR_ADDR);
}

__INLINE void bap_bap_rcvd_bitmap_5_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_5_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RCVD_BITMAP_5_ADDR_RCVD_BITMAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RCVD_BITMAP_5_ADDR_RCVD_BITMAP_ADDR_LSB    0
#define BAP_BAP_RCVD_BITMAP_5_ADDR_RCVD_BITMAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RCVD_BITMAP_5_ADDR_RCVD_BITMAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_rcvd_bitmap_5_addr_rcvd_bitmap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RCVD_BITMAP_5_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_rcvd_bitmap_5_addr_rcvd_bitmap_addr_setf(uint32_t rcvdbitmapaddr)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_5_ADDR_ADDR, (uint32_t)rcvdbitmapaddr << 0);
}

/**
 * @brief BAP_RCVD_BITMAP_6_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RCVD_BITMAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_RCVD_BITMAP_6_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x00000178)
#define BAP_BAP_RCVD_BITMAP_6_ADDR_OFFSET      0x00000178
#define BAP_BAP_RCVD_BITMAP_6_ADDR_INDEX       0x0000005E
#define BAP_BAP_RCVD_BITMAP_6_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_rcvd_bitmap_6_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RCVD_BITMAP_6_ADDR_ADDR);
}

__INLINE void bap_bap_rcvd_bitmap_6_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_6_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RCVD_BITMAP_6_ADDR_RCVD_BITMAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RCVD_BITMAP_6_ADDR_RCVD_BITMAP_ADDR_LSB    0
#define BAP_BAP_RCVD_BITMAP_6_ADDR_RCVD_BITMAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RCVD_BITMAP_6_ADDR_RCVD_BITMAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_rcvd_bitmap_6_addr_rcvd_bitmap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RCVD_BITMAP_6_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_rcvd_bitmap_6_addr_rcvd_bitmap_addr_setf(uint32_t rcvdbitmapaddr)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_6_ADDR_ADDR, (uint32_t)rcvdbitmapaddr << 0);
}

/**
 * @brief BAP_RCVD_BITMAP_7_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RCVD_BITMAP_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_RCVD_BITMAP_7_ADDR_ADDR        (REG_BAP_BASE_ADDR+0x0000017C)
#define BAP_BAP_RCVD_BITMAP_7_ADDR_OFFSET      0x0000017C
#define BAP_BAP_RCVD_BITMAP_7_ADDR_INDEX       0x0000005F
#define BAP_BAP_RCVD_BITMAP_7_ADDR_RESET       0x00000000

__INLINE uint32_t  bap_bap_rcvd_bitmap_7_addr_get(void)
{
	return REG_PL_RD(BAP_BAP_RCVD_BITMAP_7_ADDR_ADDR);
}

__INLINE void bap_bap_rcvd_bitmap_7_addr_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_7_ADDR_ADDR, value);
}

// field definitions
#define BAP_BAP_RCVD_BITMAP_7_ADDR_RCVD_BITMAP_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_RCVD_BITMAP_7_ADDR_RCVD_BITMAP_ADDR_LSB    0
#define BAP_BAP_RCVD_BITMAP_7_ADDR_RCVD_BITMAP_ADDR_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_RCVD_BITMAP_7_ADDR_RCVD_BITMAP_ADDR_RST    0x0

__INLINE uint32_t bap_bap_rcvd_bitmap_7_addr_rcvd_bitmap_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_RCVD_BITMAP_7_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void bap_bap_rcvd_bitmap_7_addr_rcvd_bitmap_addr_setf(uint32_t rcvdbitmapaddr)
{
	ASSERT_ERR((((uint32_t)rcvdbitmapaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(BAP_BAP_RCVD_BITMAP_7_ADDR_ADDR, (uint32_t)rcvdbitmapaddr << 0);
}

/**
 * @brief BAP_USER_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    BAP_VALID                 0              
 *    04    BAP_RETRNS_UPDATE_EN      1              
 *    01:00 BAP_MODE                  0x0
 * </pre>
 */
#define BAP_BAP_USER_MODE_ADDR        (REG_BAP_BASE_ADDR+0x00000180)
#define BAP_BAP_USER_MODE_OFFSET      0x00000180
#define BAP_BAP_USER_MODE_INDEX       0x00000060
#define BAP_BAP_USER_MODE_RESET       0x00000010

__INLINE uint32_t  bap_bap_user_mode_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_user_mode_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_USER_MODE_BAP_VALID_BIT     ((uint32_t)0x80000000)
#define BAP_BAP_USER_MODE_BAP_VALID_POS     31
#define BAP_BAP_USER_MODE_BAP_RETRNS_UPDATE_EN_BIT    ((uint32_t)0x00000010)
#define BAP_BAP_USER_MODE_BAP_RETRNS_UPDATE_EN_POS    4
#define BAP_BAP_USER_MODE_BAP_MODE_MASK     ((uint32_t)0x00000003)
#define BAP_BAP_USER_MODE_BAP_MODE_LSB      0
#define BAP_BAP_USER_MODE_BAP_MODE_WIDTH    ((uint32_t)0x00000002)

#define BAP_BAP_USER_MODE_BAP_VALID_RST     0x0
#define BAP_BAP_USER_MODE_BAP_RETRNS_UPDATE_EN_RST    0x1
#define BAP_BAP_USER_MODE_BAP_MODE_RST      0x0

__INLINE void bap_bap_user_mode_pack(uint8_t bap_valid, uint8_t bap_retrns_update_en, uint8_t bap_mode, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)bap_valid << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)bap_retrns_update_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)bap_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR((BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)),  ((uint32_t)bap_valid << 31) |((uint32_t)bap_retrns_update_en << 4) |((uint32_t)bap_mode << 0));
}

__INLINE void bap_bap_user_mode_unpack(uint8_t* bap_valid, uint8_t* bap_retrns_update_en, uint8_t* bap_mode, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));

	*bap_valid = (localVal & ((uint32_t)0x80000000)) >>  31;
	*bap_retrns_update_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*bap_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t bap_bap_user_mode_bap_valid_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void bap_bap_user_mode_bap_valid_setf(uint8_t bapvalid,uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)bapvalid << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR((BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (REG_PL_RD(BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)) & ~((uint32_t)0x80000000)) | ((uint32_t)bapvalid <<31));
}
__INLINE uint8_t bap_bap_user_mode_bap_retrns_update_en_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void bap_bap_user_mode_bap_retrns_update_en_setf(uint8_t bapretrnsupdateen,uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)bapretrnsupdateen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR((BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (REG_PL_RD(BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)) & ~((uint32_t)0x00000010)) | ((uint32_t)bapretrnsupdateen <<4));
}
__INLINE uint8_t bap_bap_user_mode_bap_mode_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void bap_bap_user_mode_bap_mode_setf(uint8_t bapmode,uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)bapmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR((BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (REG_PL_RD(BAP_BAP_USER_MODE_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)) & ~((uint32_t)0x00000003)) | ((uint32_t)bapmode <<0));
}

/**
 * @brief BAP_USER_1_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    BAP_VALID                 0              
 *    04    BAP_RETRNS_UPDATE_EN      1              
 *    01:00 BAP_MODE                  0x0
 * </pre>
 */
#define BAP_BAP_USER_1_MODE_ADDR        (REG_BAP_BASE_ADDR+0x00000184)
#define BAP_BAP_USER_1_MODE_OFFSET      0x00000184
#define BAP_BAP_USER_1_MODE_INDEX       0x00000061
#define BAP_BAP_USER_1_MODE_RESET       0x00000010

__INLINE uint32_t  bap_bap_user_1_mode_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_1_MODE_ADDR);
}

__INLINE void bap_bap_user_1_mode_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_1_MODE_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_1_MODE_BAP_VALID_BIT    ((uint32_t)0x80000000)
#define BAP_BAP_USER_1_MODE_BAP_VALID_POS    31
#define BAP_BAP_USER_1_MODE_BAP_RETRNS_UPDATE_EN_BIT    ((uint32_t)0x00000010)
#define BAP_BAP_USER_1_MODE_BAP_RETRNS_UPDATE_EN_POS    4
#define BAP_BAP_USER_1_MODE_BAP_MODE_MASK    ((uint32_t)0x00000003)
#define BAP_BAP_USER_1_MODE_BAP_MODE_LSB    0
#define BAP_BAP_USER_1_MODE_BAP_MODE_WIDTH    ((uint32_t)0x00000002)

#define BAP_BAP_USER_1_MODE_BAP_VALID_RST    0x0
#define BAP_BAP_USER_1_MODE_BAP_RETRNS_UPDATE_EN_RST    0x1
#define BAP_BAP_USER_1_MODE_BAP_MODE_RST    0x0

__INLINE void bap_bap_user_1_mode_pack(uint8_t bap_valid, uint8_t bap_retrns_update_en, uint8_t bap_mode)
{
	ASSERT_ERR((((uint32_t)bap_valid << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)bap_retrns_update_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)bap_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_MODE_ADDR,  ((uint32_t)bap_valid << 31) |((uint32_t)bap_retrns_update_en << 4) |((uint32_t)bap_mode << 0));
}

__INLINE void bap_bap_user_1_mode_unpack(uint8_t* bap_valid, uint8_t* bap_retrns_update_en, uint8_t* bap_mode)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_MODE_ADDR);

	*bap_valid = (localVal & ((uint32_t)0x80000000)) >>  31;
	*bap_retrns_update_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*bap_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t bap_bap_user_1_mode_bap_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void bap_bap_user_1_mode_bap_valid_setf(uint8_t bapvalid)
{
	ASSERT_ERR((((uint32_t)bapvalid << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_1_MODE_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)bapvalid <<31));
}
__INLINE uint8_t bap_bap_user_1_mode_bap_retrns_update_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void bap_bap_user_1_mode_bap_retrns_update_en_setf(uint8_t bapretrnsupdateen)
{
	ASSERT_ERR((((uint32_t)bapretrnsupdateen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_1_MODE_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)bapretrnsupdateen <<4));
}
__INLINE uint8_t bap_bap_user_1_mode_bap_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void bap_bap_user_1_mode_bap_mode_setf(uint8_t bapmode)
{
	ASSERT_ERR((((uint32_t)bapmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_1_MODE_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)bapmode <<0));
}

/**
 * @brief BAP_USER_2_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    BAP_VALID                 0              
 *    04    BAP_RETRNS_UPDATE_EN      1              
 *    01:00 BAP_MODE                  0x0
 * </pre>
 */
#define BAP_BAP_USER_2_MODE_ADDR        (REG_BAP_BASE_ADDR+0x00000188)
#define BAP_BAP_USER_2_MODE_OFFSET      0x00000188
#define BAP_BAP_USER_2_MODE_INDEX       0x00000062
#define BAP_BAP_USER_2_MODE_RESET       0x00000010

__INLINE uint32_t  bap_bap_user_2_mode_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_2_MODE_ADDR);
}

__INLINE void bap_bap_user_2_mode_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_2_MODE_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_2_MODE_BAP_VALID_BIT    ((uint32_t)0x80000000)
#define BAP_BAP_USER_2_MODE_BAP_VALID_POS    31
#define BAP_BAP_USER_2_MODE_BAP_RETRNS_UPDATE_EN_BIT    ((uint32_t)0x00000010)
#define BAP_BAP_USER_2_MODE_BAP_RETRNS_UPDATE_EN_POS    4
#define BAP_BAP_USER_2_MODE_BAP_MODE_MASK    ((uint32_t)0x00000003)
#define BAP_BAP_USER_2_MODE_BAP_MODE_LSB    0
#define BAP_BAP_USER_2_MODE_BAP_MODE_WIDTH    ((uint32_t)0x00000002)

#define BAP_BAP_USER_2_MODE_BAP_VALID_RST    0x0
#define BAP_BAP_USER_2_MODE_BAP_RETRNS_UPDATE_EN_RST    0x1
#define BAP_BAP_USER_2_MODE_BAP_MODE_RST    0x0

__INLINE void bap_bap_user_2_mode_pack(uint8_t bap_valid, uint8_t bap_retrns_update_en, uint8_t bap_mode)
{
	ASSERT_ERR((((uint32_t)bap_valid << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)bap_retrns_update_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)bap_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_MODE_ADDR,  ((uint32_t)bap_valid << 31) |((uint32_t)bap_retrns_update_en << 4) |((uint32_t)bap_mode << 0));
}

__INLINE void bap_bap_user_2_mode_unpack(uint8_t* bap_valid, uint8_t* bap_retrns_update_en, uint8_t* bap_mode)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_MODE_ADDR);

	*bap_valid = (localVal & ((uint32_t)0x80000000)) >>  31;
	*bap_retrns_update_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*bap_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t bap_bap_user_2_mode_bap_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void bap_bap_user_2_mode_bap_valid_setf(uint8_t bapvalid)
{
	ASSERT_ERR((((uint32_t)bapvalid << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_2_MODE_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)bapvalid <<31));
}
__INLINE uint8_t bap_bap_user_2_mode_bap_retrns_update_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void bap_bap_user_2_mode_bap_retrns_update_en_setf(uint8_t bapretrnsupdateen)
{
	ASSERT_ERR((((uint32_t)bapretrnsupdateen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_2_MODE_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)bapretrnsupdateen <<4));
}
__INLINE uint8_t bap_bap_user_2_mode_bap_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void bap_bap_user_2_mode_bap_mode_setf(uint8_t bapmode)
{
	ASSERT_ERR((((uint32_t)bapmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_2_MODE_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)bapmode <<0));
}

/**
 * @brief BAP_USER_3_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    BAP_VALID                 0              
 *    04    BAP_RETRNS_UPDATE_EN      1              
 *    01:00 BAP_MODE                  0x0
 * </pre>
 */
#define BAP_BAP_USER_3_MODE_ADDR        (REG_BAP_BASE_ADDR+0x0000018C)
#define BAP_BAP_USER_3_MODE_OFFSET      0x0000018C
#define BAP_BAP_USER_3_MODE_INDEX       0x00000063
#define BAP_BAP_USER_3_MODE_RESET       0x00000010

__INLINE uint32_t  bap_bap_user_3_mode_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_3_MODE_ADDR);
}

__INLINE void bap_bap_user_3_mode_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_3_MODE_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_3_MODE_BAP_VALID_BIT    ((uint32_t)0x80000000)
#define BAP_BAP_USER_3_MODE_BAP_VALID_POS    31
#define BAP_BAP_USER_3_MODE_BAP_RETRNS_UPDATE_EN_BIT    ((uint32_t)0x00000010)
#define BAP_BAP_USER_3_MODE_BAP_RETRNS_UPDATE_EN_POS    4
#define BAP_BAP_USER_3_MODE_BAP_MODE_MASK    ((uint32_t)0x00000003)
#define BAP_BAP_USER_3_MODE_BAP_MODE_LSB    0
#define BAP_BAP_USER_3_MODE_BAP_MODE_WIDTH    ((uint32_t)0x00000002)

#define BAP_BAP_USER_3_MODE_BAP_VALID_RST    0x0
#define BAP_BAP_USER_3_MODE_BAP_RETRNS_UPDATE_EN_RST    0x1
#define BAP_BAP_USER_3_MODE_BAP_MODE_RST    0x0

__INLINE void bap_bap_user_3_mode_pack(uint8_t bap_valid, uint8_t bap_retrns_update_en, uint8_t bap_mode)
{
	ASSERT_ERR((((uint32_t)bap_valid << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)bap_retrns_update_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)bap_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_MODE_ADDR,  ((uint32_t)bap_valid << 31) |((uint32_t)bap_retrns_update_en << 4) |((uint32_t)bap_mode << 0));
}

__INLINE void bap_bap_user_3_mode_unpack(uint8_t* bap_valid, uint8_t* bap_retrns_update_en, uint8_t* bap_mode)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_MODE_ADDR);

	*bap_valid = (localVal & ((uint32_t)0x80000000)) >>  31;
	*bap_retrns_update_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*bap_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t bap_bap_user_3_mode_bap_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void bap_bap_user_3_mode_bap_valid_setf(uint8_t bapvalid)
{
	ASSERT_ERR((((uint32_t)bapvalid << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_3_MODE_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)bapvalid <<31));
}
__INLINE uint8_t bap_bap_user_3_mode_bap_retrns_update_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void bap_bap_user_3_mode_bap_retrns_update_en_setf(uint8_t bapretrnsupdateen)
{
	ASSERT_ERR((((uint32_t)bapretrnsupdateen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_3_MODE_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)bapretrnsupdateen <<4));
}
__INLINE uint8_t bap_bap_user_3_mode_bap_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void bap_bap_user_3_mode_bap_mode_setf(uint8_t bapmode)
{
	ASSERT_ERR((((uint32_t)bapmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_3_MODE_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)bapmode <<0));
}

/**
 * @brief BAP_USER_4_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    BAP_VALID                 0              
 *    04    BAP_RETRNS_UPDATE_EN      1              
 *    01:00 BAP_MODE                  0x0
 * </pre>
 */
#define BAP_BAP_USER_4_MODE_ADDR        (REG_BAP_BASE_ADDR+0x00000190)
#define BAP_BAP_USER_4_MODE_OFFSET      0x00000190
#define BAP_BAP_USER_4_MODE_INDEX       0x00000064
#define BAP_BAP_USER_4_MODE_RESET       0x00000010

__INLINE uint32_t  bap_bap_user_4_mode_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_4_MODE_ADDR);
}

__INLINE void bap_bap_user_4_mode_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_4_MODE_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_4_MODE_BAP_VALID_BIT    ((uint32_t)0x80000000)
#define BAP_BAP_USER_4_MODE_BAP_VALID_POS    31
#define BAP_BAP_USER_4_MODE_BAP_RETRNS_UPDATE_EN_BIT    ((uint32_t)0x00000010)
#define BAP_BAP_USER_4_MODE_BAP_RETRNS_UPDATE_EN_POS    4
#define BAP_BAP_USER_4_MODE_BAP_MODE_MASK    ((uint32_t)0x00000003)
#define BAP_BAP_USER_4_MODE_BAP_MODE_LSB    0
#define BAP_BAP_USER_4_MODE_BAP_MODE_WIDTH    ((uint32_t)0x00000002)

#define BAP_BAP_USER_4_MODE_BAP_VALID_RST    0x0
#define BAP_BAP_USER_4_MODE_BAP_RETRNS_UPDATE_EN_RST    0x1
#define BAP_BAP_USER_4_MODE_BAP_MODE_RST    0x0

__INLINE void bap_bap_user_4_mode_pack(uint8_t bap_valid, uint8_t bap_retrns_update_en, uint8_t bap_mode)
{
	ASSERT_ERR((((uint32_t)bap_valid << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)bap_retrns_update_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)bap_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_MODE_ADDR,  ((uint32_t)bap_valid << 31) |((uint32_t)bap_retrns_update_en << 4) |((uint32_t)bap_mode << 0));
}

__INLINE void bap_bap_user_4_mode_unpack(uint8_t* bap_valid, uint8_t* bap_retrns_update_en, uint8_t* bap_mode)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_MODE_ADDR);

	*bap_valid = (localVal & ((uint32_t)0x80000000)) >>  31;
	*bap_retrns_update_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*bap_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t bap_bap_user_4_mode_bap_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void bap_bap_user_4_mode_bap_valid_setf(uint8_t bapvalid)
{
	ASSERT_ERR((((uint32_t)bapvalid << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_4_MODE_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)bapvalid <<31));
}
__INLINE uint8_t bap_bap_user_4_mode_bap_retrns_update_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void bap_bap_user_4_mode_bap_retrns_update_en_setf(uint8_t bapretrnsupdateen)
{
	ASSERT_ERR((((uint32_t)bapretrnsupdateen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_4_MODE_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)bapretrnsupdateen <<4));
}
__INLINE uint8_t bap_bap_user_4_mode_bap_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void bap_bap_user_4_mode_bap_mode_setf(uint8_t bapmode)
{
	ASSERT_ERR((((uint32_t)bapmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_4_MODE_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)bapmode <<0));
}

/**
 * @brief BAP_USER_5_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    BAP_VALID                 0              
 *    04    BAP_RETRNS_UPDATE_EN      1              
 *    01:00 BAP_MODE                  0x0
 * </pre>
 */
#define BAP_BAP_USER_5_MODE_ADDR        (REG_BAP_BASE_ADDR+0x00000194)
#define BAP_BAP_USER_5_MODE_OFFSET      0x00000194
#define BAP_BAP_USER_5_MODE_INDEX       0x00000065
#define BAP_BAP_USER_5_MODE_RESET       0x00000010

__INLINE uint32_t  bap_bap_user_5_mode_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_5_MODE_ADDR);
}

__INLINE void bap_bap_user_5_mode_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_5_MODE_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_5_MODE_BAP_VALID_BIT    ((uint32_t)0x80000000)
#define BAP_BAP_USER_5_MODE_BAP_VALID_POS    31
#define BAP_BAP_USER_5_MODE_BAP_RETRNS_UPDATE_EN_BIT    ((uint32_t)0x00000010)
#define BAP_BAP_USER_5_MODE_BAP_RETRNS_UPDATE_EN_POS    4
#define BAP_BAP_USER_5_MODE_BAP_MODE_MASK    ((uint32_t)0x00000003)
#define BAP_BAP_USER_5_MODE_BAP_MODE_LSB    0
#define BAP_BAP_USER_5_MODE_BAP_MODE_WIDTH    ((uint32_t)0x00000002)

#define BAP_BAP_USER_5_MODE_BAP_VALID_RST    0x0
#define BAP_BAP_USER_5_MODE_BAP_RETRNS_UPDATE_EN_RST    0x1
#define BAP_BAP_USER_5_MODE_BAP_MODE_RST    0x0

__INLINE void bap_bap_user_5_mode_pack(uint8_t bap_valid, uint8_t bap_retrns_update_en, uint8_t bap_mode)
{
	ASSERT_ERR((((uint32_t)bap_valid << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)bap_retrns_update_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)bap_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_MODE_ADDR,  ((uint32_t)bap_valid << 31) |((uint32_t)bap_retrns_update_en << 4) |((uint32_t)bap_mode << 0));
}

__INLINE void bap_bap_user_5_mode_unpack(uint8_t* bap_valid, uint8_t* bap_retrns_update_en, uint8_t* bap_mode)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_MODE_ADDR);

	*bap_valid = (localVal & ((uint32_t)0x80000000)) >>  31;
	*bap_retrns_update_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*bap_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t bap_bap_user_5_mode_bap_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void bap_bap_user_5_mode_bap_valid_setf(uint8_t bapvalid)
{
	ASSERT_ERR((((uint32_t)bapvalid << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_5_MODE_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)bapvalid <<31));
}
__INLINE uint8_t bap_bap_user_5_mode_bap_retrns_update_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void bap_bap_user_5_mode_bap_retrns_update_en_setf(uint8_t bapretrnsupdateen)
{
	ASSERT_ERR((((uint32_t)bapretrnsupdateen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_5_MODE_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)bapretrnsupdateen <<4));
}
__INLINE uint8_t bap_bap_user_5_mode_bap_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void bap_bap_user_5_mode_bap_mode_setf(uint8_t bapmode)
{
	ASSERT_ERR((((uint32_t)bapmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_5_MODE_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)bapmode <<0));
}

/**
 * @brief BAP_USER_6_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    BAP_VALID                 0              
 *    04    BAP_RETRNS_UPDATE_EN      1              
 *    01:00 BAP_MODE                  0x0
 * </pre>
 */
#define BAP_BAP_USER_6_MODE_ADDR        (REG_BAP_BASE_ADDR+0x00000198)
#define BAP_BAP_USER_6_MODE_OFFSET      0x00000198
#define BAP_BAP_USER_6_MODE_INDEX       0x00000066
#define BAP_BAP_USER_6_MODE_RESET       0x00000010

__INLINE uint32_t  bap_bap_user_6_mode_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_6_MODE_ADDR);
}

__INLINE void bap_bap_user_6_mode_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_6_MODE_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_6_MODE_BAP_VALID_BIT    ((uint32_t)0x80000000)
#define BAP_BAP_USER_6_MODE_BAP_VALID_POS    31
#define BAP_BAP_USER_6_MODE_BAP_RETRNS_UPDATE_EN_BIT    ((uint32_t)0x00000010)
#define BAP_BAP_USER_6_MODE_BAP_RETRNS_UPDATE_EN_POS    4
#define BAP_BAP_USER_6_MODE_BAP_MODE_MASK    ((uint32_t)0x00000003)
#define BAP_BAP_USER_6_MODE_BAP_MODE_LSB    0
#define BAP_BAP_USER_6_MODE_BAP_MODE_WIDTH    ((uint32_t)0x00000002)

#define BAP_BAP_USER_6_MODE_BAP_VALID_RST    0x0
#define BAP_BAP_USER_6_MODE_BAP_RETRNS_UPDATE_EN_RST    0x1
#define BAP_BAP_USER_6_MODE_BAP_MODE_RST    0x0

__INLINE void bap_bap_user_6_mode_pack(uint8_t bap_valid, uint8_t bap_retrns_update_en, uint8_t bap_mode)
{
	ASSERT_ERR((((uint32_t)bap_valid << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)bap_retrns_update_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)bap_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_MODE_ADDR,  ((uint32_t)bap_valid << 31) |((uint32_t)bap_retrns_update_en << 4) |((uint32_t)bap_mode << 0));
}

__INLINE void bap_bap_user_6_mode_unpack(uint8_t* bap_valid, uint8_t* bap_retrns_update_en, uint8_t* bap_mode)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_MODE_ADDR);

	*bap_valid = (localVal & ((uint32_t)0x80000000)) >>  31;
	*bap_retrns_update_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*bap_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t bap_bap_user_6_mode_bap_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void bap_bap_user_6_mode_bap_valid_setf(uint8_t bapvalid)
{
	ASSERT_ERR((((uint32_t)bapvalid << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_6_MODE_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)bapvalid <<31));
}
__INLINE uint8_t bap_bap_user_6_mode_bap_retrns_update_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void bap_bap_user_6_mode_bap_retrns_update_en_setf(uint8_t bapretrnsupdateen)
{
	ASSERT_ERR((((uint32_t)bapretrnsupdateen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_6_MODE_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)bapretrnsupdateen <<4));
}
__INLINE uint8_t bap_bap_user_6_mode_bap_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void bap_bap_user_6_mode_bap_mode_setf(uint8_t bapmode)
{
	ASSERT_ERR((((uint32_t)bapmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_6_MODE_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)bapmode <<0));
}

/**
 * @brief BAP_USER_7_MODE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    BAP_VALID                 0              
 *    04    BAP_RETRNS_UPDATE_EN      1              
 *    01:00 BAP_MODE                  0x0
 * </pre>
 */
#define BAP_BAP_USER_7_MODE_ADDR        (REG_BAP_BASE_ADDR+0x0000019C)
#define BAP_BAP_USER_7_MODE_OFFSET      0x0000019C
#define BAP_BAP_USER_7_MODE_INDEX       0x00000067
#define BAP_BAP_USER_7_MODE_RESET       0x00000010

__INLINE uint32_t  bap_bap_user_7_mode_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_7_MODE_ADDR);
}

__INLINE void bap_bap_user_7_mode_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_7_MODE_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_7_MODE_BAP_VALID_BIT    ((uint32_t)0x80000000)
#define BAP_BAP_USER_7_MODE_BAP_VALID_POS    31
#define BAP_BAP_USER_7_MODE_BAP_RETRNS_UPDATE_EN_BIT    ((uint32_t)0x00000010)
#define BAP_BAP_USER_7_MODE_BAP_RETRNS_UPDATE_EN_POS    4
#define BAP_BAP_USER_7_MODE_BAP_MODE_MASK    ((uint32_t)0x00000003)
#define BAP_BAP_USER_7_MODE_BAP_MODE_LSB    0
#define BAP_BAP_USER_7_MODE_BAP_MODE_WIDTH    ((uint32_t)0x00000002)

#define BAP_BAP_USER_7_MODE_BAP_VALID_RST    0x0
#define BAP_BAP_USER_7_MODE_BAP_RETRNS_UPDATE_EN_RST    0x1
#define BAP_BAP_USER_7_MODE_BAP_MODE_RST    0x0

__INLINE void bap_bap_user_7_mode_pack(uint8_t bap_valid, uint8_t bap_retrns_update_en, uint8_t bap_mode)
{
	ASSERT_ERR((((uint32_t)bap_valid << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)bap_retrns_update_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)bap_mode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_MODE_ADDR,  ((uint32_t)bap_valid << 31) |((uint32_t)bap_retrns_update_en << 4) |((uint32_t)bap_mode << 0));
}

__INLINE void bap_bap_user_7_mode_unpack(uint8_t* bap_valid, uint8_t* bap_retrns_update_en, uint8_t* bap_mode)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_MODE_ADDR);

	*bap_valid = (localVal & ((uint32_t)0x80000000)) >>  31;
	*bap_retrns_update_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*bap_mode = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t bap_bap_user_7_mode_bap_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void bap_bap_user_7_mode_bap_valid_setf(uint8_t bapvalid)
{
	ASSERT_ERR((((uint32_t)bapvalid << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_7_MODE_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)bapvalid <<31));
}
__INLINE uint8_t bap_bap_user_7_mode_bap_retrns_update_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void bap_bap_user_7_mode_bap_retrns_update_en_setf(uint8_t bapretrnsupdateen)
{
	ASSERT_ERR((((uint32_t)bapretrnsupdateen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_7_MODE_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)bapretrnsupdateen <<4));
}
__INLINE uint8_t bap_bap_user_7_mode_bap_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void bap_bap_user_7_mode_bap_mode_setf(uint8_t bapmode)
{
	ASSERT_ERR((((uint32_t)bapmode << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_MODE_ADDR, (REG_PL_RD(BAP_BAP_USER_7_MODE_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)bapmode <<0));
}

/**
 * @brief BAP_USER_FIRST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FIRST_DESC                0x0
 * </pre>
 */
#define BAP_BAP_USER_FIRST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001A0)
#define BAP_BAP_USER_FIRST_DESC_OFFSET      0x000001A0
#define BAP_BAP_USER_FIRST_DESC_INDEX       0x00000068
#define BAP_BAP_USER_FIRST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_first_desc_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_FIRST_DESC_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

// field definitions
#define BAP_BAP_USER_FIRST_DESC_FIRST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_FIRST_DESC_FIRST_DESC_LSB    0
#define BAP_BAP_USER_FIRST_DESC_FIRST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_FIRST_DESC_FIRST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_first_desc_first_desc_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_FIRST_DESC_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_1_FIRST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FIRST_DESC                0x0
 * </pre>
 */
#define BAP_BAP_USER_1_FIRST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001A4)
#define BAP_BAP_USER_1_FIRST_DESC_OFFSET      0x000001A4
#define BAP_BAP_USER_1_FIRST_DESC_INDEX       0x00000069
#define BAP_BAP_USER_1_FIRST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_1_first_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_1_FIRST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_1_FIRST_DESC_FIRST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_1_FIRST_DESC_FIRST_DESC_LSB    0
#define BAP_BAP_USER_1_FIRST_DESC_FIRST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_1_FIRST_DESC_FIRST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_1_first_desc_first_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_FIRST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_2_FIRST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FIRST_DESC                0x0
 * </pre>
 */
#define BAP_BAP_USER_2_FIRST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001A8)
#define BAP_BAP_USER_2_FIRST_DESC_OFFSET      0x000001A8
#define BAP_BAP_USER_2_FIRST_DESC_INDEX       0x0000006A
#define BAP_BAP_USER_2_FIRST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_2_first_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_2_FIRST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_2_FIRST_DESC_FIRST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_2_FIRST_DESC_FIRST_DESC_LSB    0
#define BAP_BAP_USER_2_FIRST_DESC_FIRST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_2_FIRST_DESC_FIRST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_2_first_desc_first_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_FIRST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_3_FIRST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FIRST_DESC                0x0
 * </pre>
 */
#define BAP_BAP_USER_3_FIRST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001AC)
#define BAP_BAP_USER_3_FIRST_DESC_OFFSET      0x000001AC
#define BAP_BAP_USER_3_FIRST_DESC_INDEX       0x0000006B
#define BAP_BAP_USER_3_FIRST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_3_first_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_3_FIRST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_3_FIRST_DESC_FIRST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_3_FIRST_DESC_FIRST_DESC_LSB    0
#define BAP_BAP_USER_3_FIRST_DESC_FIRST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_3_FIRST_DESC_FIRST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_3_first_desc_first_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_FIRST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_4_FIRST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FIRST_DESC                0x0
 * </pre>
 */
#define BAP_BAP_USER_4_FIRST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001B0)
#define BAP_BAP_USER_4_FIRST_DESC_OFFSET      0x000001B0
#define BAP_BAP_USER_4_FIRST_DESC_INDEX       0x0000006C
#define BAP_BAP_USER_4_FIRST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_4_first_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_4_FIRST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_4_FIRST_DESC_FIRST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_4_FIRST_DESC_FIRST_DESC_LSB    0
#define BAP_BAP_USER_4_FIRST_DESC_FIRST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_4_FIRST_DESC_FIRST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_4_first_desc_first_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_FIRST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_5_FIRST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FIRST_DESC                0x0
 * </pre>
 */
#define BAP_BAP_USER_5_FIRST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001B4)
#define BAP_BAP_USER_5_FIRST_DESC_OFFSET      0x000001B4
#define BAP_BAP_USER_5_FIRST_DESC_INDEX       0x0000006D
#define BAP_BAP_USER_5_FIRST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_5_first_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_5_FIRST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_5_FIRST_DESC_FIRST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_5_FIRST_DESC_FIRST_DESC_LSB    0
#define BAP_BAP_USER_5_FIRST_DESC_FIRST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_5_FIRST_DESC_FIRST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_5_first_desc_first_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_FIRST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_6_FIRST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FIRST_DESC                0x0
 * </pre>
 */
#define BAP_BAP_USER_6_FIRST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001B8)
#define BAP_BAP_USER_6_FIRST_DESC_OFFSET      0x000001B8
#define BAP_BAP_USER_6_FIRST_DESC_INDEX       0x0000006E
#define BAP_BAP_USER_6_FIRST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_6_first_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_6_FIRST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_6_FIRST_DESC_FIRST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_6_FIRST_DESC_FIRST_DESC_LSB    0
#define BAP_BAP_USER_6_FIRST_DESC_FIRST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_6_FIRST_DESC_FIRST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_6_first_desc_first_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_FIRST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_7_FIRST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 FIRST_DESC                0x0
 * </pre>
 */
#define BAP_BAP_USER_7_FIRST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001BC)
#define BAP_BAP_USER_7_FIRST_DESC_OFFSET      0x000001BC
#define BAP_BAP_USER_7_FIRST_DESC_INDEX       0x0000006F
#define BAP_BAP_USER_7_FIRST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_7_first_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_7_FIRST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_7_FIRST_DESC_FIRST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_7_FIRST_DESC_FIRST_DESC_LSB    0
#define BAP_BAP_USER_7_FIRST_DESC_FIRST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_7_FIRST_DESC_FIRST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_7_first_desc_first_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_FIRST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_LAST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LAST_DESC                 0x0
 * </pre>
 */
#define BAP_BAP_USER_LAST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001C0)
#define BAP_BAP_USER_LAST_DESC_OFFSET      0x000001C0
#define BAP_BAP_USER_LAST_DESC_INDEX       0x00000070
#define BAP_BAP_USER_LAST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_last_desc_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_LAST_DESC_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

// field definitions
#define BAP_BAP_USER_LAST_DESC_LAST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_LAST_DESC_LAST_DESC_LSB    0
#define BAP_BAP_USER_LAST_DESC_LAST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_LAST_DESC_LAST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_last_desc_last_desc_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_LAST_DESC_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_1_LAST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LAST_DESC                 0x0
 * </pre>
 */
#define BAP_BAP_USER_1_LAST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001C4)
#define BAP_BAP_USER_1_LAST_DESC_OFFSET      0x000001C4
#define BAP_BAP_USER_1_LAST_DESC_INDEX       0x00000071
#define BAP_BAP_USER_1_LAST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_1_last_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_1_LAST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_1_LAST_DESC_LAST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_1_LAST_DESC_LAST_DESC_LSB    0
#define BAP_BAP_USER_1_LAST_DESC_LAST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_1_LAST_DESC_LAST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_1_last_desc_last_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_LAST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_2_LAST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LAST_DESC                 0x0
 * </pre>
 */
#define BAP_BAP_USER_2_LAST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001C8)
#define BAP_BAP_USER_2_LAST_DESC_OFFSET      0x000001C8
#define BAP_BAP_USER_2_LAST_DESC_INDEX       0x00000072
#define BAP_BAP_USER_2_LAST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_2_last_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_2_LAST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_2_LAST_DESC_LAST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_2_LAST_DESC_LAST_DESC_LSB    0
#define BAP_BAP_USER_2_LAST_DESC_LAST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_2_LAST_DESC_LAST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_2_last_desc_last_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_LAST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_3_LAST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LAST_DESC                 0x0
 * </pre>
 */
#define BAP_BAP_USER_3_LAST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001CC)
#define BAP_BAP_USER_3_LAST_DESC_OFFSET      0x000001CC
#define BAP_BAP_USER_3_LAST_DESC_INDEX       0x00000073
#define BAP_BAP_USER_3_LAST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_3_last_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_3_LAST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_3_LAST_DESC_LAST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_3_LAST_DESC_LAST_DESC_LSB    0
#define BAP_BAP_USER_3_LAST_DESC_LAST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_3_LAST_DESC_LAST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_3_last_desc_last_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_LAST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_4_LAST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LAST_DESC                 0x0
 * </pre>
 */
#define BAP_BAP_USER_4_LAST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001D0)
#define BAP_BAP_USER_4_LAST_DESC_OFFSET      0x000001D0
#define BAP_BAP_USER_4_LAST_DESC_INDEX       0x00000074
#define BAP_BAP_USER_4_LAST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_4_last_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_4_LAST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_4_LAST_DESC_LAST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_4_LAST_DESC_LAST_DESC_LSB    0
#define BAP_BAP_USER_4_LAST_DESC_LAST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_4_LAST_DESC_LAST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_4_last_desc_last_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_LAST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_5_LAST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LAST_DESC                 0x0
 * </pre>
 */
#define BAP_BAP_USER_5_LAST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001D4)
#define BAP_BAP_USER_5_LAST_DESC_OFFSET      0x000001D4
#define BAP_BAP_USER_5_LAST_DESC_INDEX       0x00000075
#define BAP_BAP_USER_5_LAST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_5_last_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_5_LAST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_5_LAST_DESC_LAST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_5_LAST_DESC_LAST_DESC_LSB    0
#define BAP_BAP_USER_5_LAST_DESC_LAST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_5_LAST_DESC_LAST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_5_last_desc_last_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_LAST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_6_LAST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LAST_DESC                 0x0
 * </pre>
 */
#define BAP_BAP_USER_6_LAST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001D8)
#define BAP_BAP_USER_6_LAST_DESC_OFFSET      0x000001D8
#define BAP_BAP_USER_6_LAST_DESC_INDEX       0x00000076
#define BAP_BAP_USER_6_LAST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_6_last_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_6_LAST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_6_LAST_DESC_LAST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_6_LAST_DESC_LAST_DESC_LSB    0
#define BAP_BAP_USER_6_LAST_DESC_LAST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_6_LAST_DESC_LAST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_6_last_desc_last_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_LAST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_7_LAST_DESC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LAST_DESC                 0x0
 * </pre>
 */
#define BAP_BAP_USER_7_LAST_DESC_ADDR        (REG_BAP_BASE_ADDR+0x000001DC)
#define BAP_BAP_USER_7_LAST_DESC_OFFSET      0x000001DC
#define BAP_BAP_USER_7_LAST_DESC_INDEX       0x00000077
#define BAP_BAP_USER_7_LAST_DESC_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_7_last_desc_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_7_LAST_DESC_ADDR);
}

// field definitions
#define BAP_BAP_USER_7_LAST_DESC_LAST_DESC_MASK    ((uint32_t)0xFFFFFFFF)
#define BAP_BAP_USER_7_LAST_DESC_LAST_DESC_LSB    0
#define BAP_BAP_USER_7_LAST_DESC_LAST_DESC_WIDTH    ((uint32_t)0x00000020)

#define BAP_BAP_USER_7_LAST_DESC_LAST_DESC_RST    0x0

__INLINE uint32_t bap_bap_user_7_last_desc_last_desc_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_LAST_DESC_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief BAP_USER_STAT_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL                  0x0
 *    11:00 NUM_SUCCESS               0x0
 * </pre>
 */
#define BAP_BAP_USER_STAT_1_ADDR        (REG_BAP_BASE_ADDR+0x000001E0)
#define BAP_BAP_USER_STAT_1_OFFSET      0x000001E0
#define BAP_BAP_USER_STAT_1_INDEX       0x00000078
#define BAP_BAP_USER_STAT_1_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_stat_1_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_STAT_1_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

// field definitions
#define BAP_BAP_USER_STAT_1_NUM_FAIL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_STAT_1_NUM_FAIL_LSB    16
#define BAP_BAP_USER_STAT_1_NUM_FAIL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_STAT_1_NUM_SUCCESS_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_STAT_1_NUM_SUCCESS_LSB    0
#define BAP_BAP_USER_STAT_1_NUM_SUCCESS_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_STAT_1_NUM_FAIL_RST    0x0
#define BAP_BAP_USER_STAT_1_NUM_SUCCESS_RST    0x0

__INLINE void bap_bap_user_stat_1_unpack(uint16_t* num_fail, uint16_t* num_success, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_STAT_1_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));

	*num_fail = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_success = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_stat_1_num_fail_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_STAT_1_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_stat_1_num_success_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_STAT_1_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_1_STAT_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL                  0x0
 *    11:00 NUM_SUCCESS               0x0
 * </pre>
 */
#define BAP_BAP_USER_1_STAT_1_ADDR        (REG_BAP_BASE_ADDR+0x000001E4)
#define BAP_BAP_USER_1_STAT_1_OFFSET      0x000001E4
#define BAP_BAP_USER_1_STAT_1_INDEX       0x00000079
#define BAP_BAP_USER_1_STAT_1_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_1_stat_1_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_1_STAT_1_ADDR);
}

// field definitions
#define BAP_BAP_USER_1_STAT_1_NUM_FAIL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_1_STAT_1_NUM_FAIL_LSB    16
#define BAP_BAP_USER_1_STAT_1_NUM_FAIL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_1_STAT_1_NUM_SUCCESS_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_1_STAT_1_NUM_SUCCESS_LSB    0
#define BAP_BAP_USER_1_STAT_1_NUM_SUCCESS_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_1_STAT_1_NUM_FAIL_RST    0x0
#define BAP_BAP_USER_1_STAT_1_NUM_SUCCESS_RST    0x0

__INLINE void bap_bap_user_1_stat_1_unpack(uint16_t* num_fail, uint16_t* num_success)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_STAT_1_ADDR);

	*num_fail = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_success = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_1_stat_1_num_fail_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_1_stat_1_num_success_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_2_STAT_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL                  0x0
 *    11:00 NUM_SUCCESS               0x0
 * </pre>
 */
#define BAP_BAP_USER_2_STAT_1_ADDR        (REG_BAP_BASE_ADDR+0x000001E8)
#define BAP_BAP_USER_2_STAT_1_OFFSET      0x000001E8
#define BAP_BAP_USER_2_STAT_1_INDEX       0x0000007A
#define BAP_BAP_USER_2_STAT_1_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_2_stat_1_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_2_STAT_1_ADDR);
}

// field definitions
#define BAP_BAP_USER_2_STAT_1_NUM_FAIL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_2_STAT_1_NUM_FAIL_LSB    16
#define BAP_BAP_USER_2_STAT_1_NUM_FAIL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_2_STAT_1_NUM_SUCCESS_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_2_STAT_1_NUM_SUCCESS_LSB    0
#define BAP_BAP_USER_2_STAT_1_NUM_SUCCESS_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_2_STAT_1_NUM_FAIL_RST    0x0
#define BAP_BAP_USER_2_STAT_1_NUM_SUCCESS_RST    0x0

__INLINE void bap_bap_user_2_stat_1_unpack(uint16_t* num_fail, uint16_t* num_success)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_STAT_1_ADDR);

	*num_fail = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_success = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_2_stat_1_num_fail_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_2_stat_1_num_success_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_3_STAT_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL                  0x0
 *    11:00 NUM_SUCCESS               0x0
 * </pre>
 */
#define BAP_BAP_USER_3_STAT_1_ADDR        (REG_BAP_BASE_ADDR+0x000001EC)
#define BAP_BAP_USER_3_STAT_1_OFFSET      0x000001EC
#define BAP_BAP_USER_3_STAT_1_INDEX       0x0000007B
#define BAP_BAP_USER_3_STAT_1_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_3_stat_1_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_3_STAT_1_ADDR);
}

// field definitions
#define BAP_BAP_USER_3_STAT_1_NUM_FAIL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_3_STAT_1_NUM_FAIL_LSB    16
#define BAP_BAP_USER_3_STAT_1_NUM_FAIL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_3_STAT_1_NUM_SUCCESS_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_3_STAT_1_NUM_SUCCESS_LSB    0
#define BAP_BAP_USER_3_STAT_1_NUM_SUCCESS_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_3_STAT_1_NUM_FAIL_RST    0x0
#define BAP_BAP_USER_3_STAT_1_NUM_SUCCESS_RST    0x0

__INLINE void bap_bap_user_3_stat_1_unpack(uint16_t* num_fail, uint16_t* num_success)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_STAT_1_ADDR);

	*num_fail = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_success = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_3_stat_1_num_fail_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_3_stat_1_num_success_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_4_STAT_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL                  0x0
 *    11:00 NUM_SUCCESS               0x0
 * </pre>
 */
#define BAP_BAP_USER_4_STAT_1_ADDR        (REG_BAP_BASE_ADDR+0x000001F0)
#define BAP_BAP_USER_4_STAT_1_OFFSET      0x000001F0
#define BAP_BAP_USER_4_STAT_1_INDEX       0x0000007C
#define BAP_BAP_USER_4_STAT_1_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_4_stat_1_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_4_STAT_1_ADDR);
}

// field definitions
#define BAP_BAP_USER_4_STAT_1_NUM_FAIL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_4_STAT_1_NUM_FAIL_LSB    16
#define BAP_BAP_USER_4_STAT_1_NUM_FAIL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_4_STAT_1_NUM_SUCCESS_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_4_STAT_1_NUM_SUCCESS_LSB    0
#define BAP_BAP_USER_4_STAT_1_NUM_SUCCESS_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_4_STAT_1_NUM_FAIL_RST    0x0
#define BAP_BAP_USER_4_STAT_1_NUM_SUCCESS_RST    0x0

__INLINE void bap_bap_user_4_stat_1_unpack(uint16_t* num_fail, uint16_t* num_success)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_STAT_1_ADDR);

	*num_fail = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_success = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_4_stat_1_num_fail_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_4_stat_1_num_success_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_5_STAT_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL                  0x0
 *    11:00 NUM_SUCCESS               0x0
 * </pre>
 */
#define BAP_BAP_USER_5_STAT_1_ADDR        (REG_BAP_BASE_ADDR+0x000001F4)
#define BAP_BAP_USER_5_STAT_1_OFFSET      0x000001F4
#define BAP_BAP_USER_5_STAT_1_INDEX       0x0000007D
#define BAP_BAP_USER_5_STAT_1_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_5_stat_1_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_5_STAT_1_ADDR);
}

// field definitions
#define BAP_BAP_USER_5_STAT_1_NUM_FAIL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_5_STAT_1_NUM_FAIL_LSB    16
#define BAP_BAP_USER_5_STAT_1_NUM_FAIL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_5_STAT_1_NUM_SUCCESS_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_5_STAT_1_NUM_SUCCESS_LSB    0
#define BAP_BAP_USER_5_STAT_1_NUM_SUCCESS_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_5_STAT_1_NUM_FAIL_RST    0x0
#define BAP_BAP_USER_5_STAT_1_NUM_SUCCESS_RST    0x0

__INLINE void bap_bap_user_5_stat_1_unpack(uint16_t* num_fail, uint16_t* num_success)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_STAT_1_ADDR);

	*num_fail = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_success = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_5_stat_1_num_fail_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_5_stat_1_num_success_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_6_STAT_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL                  0x0
 *    11:00 NUM_SUCCESS               0x0
 * </pre>
 */
#define BAP_BAP_USER_6_STAT_1_ADDR        (REG_BAP_BASE_ADDR+0x000001F8)
#define BAP_BAP_USER_6_STAT_1_OFFSET      0x000001F8
#define BAP_BAP_USER_6_STAT_1_INDEX       0x0000007E
#define BAP_BAP_USER_6_STAT_1_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_6_stat_1_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_6_STAT_1_ADDR);
}

// field definitions
#define BAP_BAP_USER_6_STAT_1_NUM_FAIL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_6_STAT_1_NUM_FAIL_LSB    16
#define BAP_BAP_USER_6_STAT_1_NUM_FAIL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_6_STAT_1_NUM_SUCCESS_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_6_STAT_1_NUM_SUCCESS_LSB    0
#define BAP_BAP_USER_6_STAT_1_NUM_SUCCESS_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_6_STAT_1_NUM_FAIL_RST    0x0
#define BAP_BAP_USER_6_STAT_1_NUM_SUCCESS_RST    0x0

__INLINE void bap_bap_user_6_stat_1_unpack(uint16_t* num_fail, uint16_t* num_success)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_STAT_1_ADDR);

	*num_fail = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_success = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_6_stat_1_num_fail_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_6_stat_1_num_success_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_7_STAT_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL                  0x0
 *    11:00 NUM_SUCCESS               0x0
 * </pre>
 */
#define BAP_BAP_USER_7_STAT_1_ADDR        (REG_BAP_BASE_ADDR+0x000001FC)
#define BAP_BAP_USER_7_STAT_1_OFFSET      0x000001FC
#define BAP_BAP_USER_7_STAT_1_INDEX       0x0000007F
#define BAP_BAP_USER_7_STAT_1_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_7_stat_1_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_7_STAT_1_ADDR);
}

// field definitions
#define BAP_BAP_USER_7_STAT_1_NUM_FAIL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_7_STAT_1_NUM_FAIL_LSB    16
#define BAP_BAP_USER_7_STAT_1_NUM_FAIL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_7_STAT_1_NUM_SUCCESS_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_7_STAT_1_NUM_SUCCESS_LSB    0
#define BAP_BAP_USER_7_STAT_1_NUM_SUCCESS_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_7_STAT_1_NUM_FAIL_RST    0x0
#define BAP_BAP_USER_7_STAT_1_NUM_SUCCESS_RST    0x0

__INLINE void bap_bap_user_7_stat_1_unpack(uint16_t* num_fail, uint16_t* num_success)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_STAT_1_ADDR);

	*num_fail = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_success = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_7_stat_1_num_fail_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_7_stat_1_num_success_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_STAT_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL_TOTAL            0x0
 *    11:00 NUM_RETRY_LMT_REACHED     0x0
 * </pre>
 */
#define BAP_BAP_USER_STAT_2_ADDR        (REG_BAP_BASE_ADDR+0x00000200)
#define BAP_BAP_USER_STAT_2_OFFSET      0x00000200
#define BAP_BAP_USER_STAT_2_INDEX       0x00000080
#define BAP_BAP_USER_STAT_2_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_stat_2_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_STAT_2_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

// field definitions
#define BAP_BAP_USER_STAT_2_NUM_FAIL_TOTAL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_STAT_2_NUM_FAIL_TOTAL_LSB    16
#define BAP_BAP_USER_STAT_2_NUM_FAIL_TOTAL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_STAT_2_NUM_RETRY_LMT_REACHED_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_STAT_2_NUM_RETRY_LMT_REACHED_LSB    0
#define BAP_BAP_USER_STAT_2_NUM_RETRY_LMT_REACHED_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_STAT_2_NUM_FAIL_TOTAL_RST    0x0
#define BAP_BAP_USER_STAT_2_NUM_RETRY_LMT_REACHED_RST    0x0

__INLINE void bap_bap_user_stat_2_unpack(uint16_t* num_fail_total, uint16_t* num_retry_lmt_reached, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_STAT_2_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));

	*num_fail_total = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_retry_lmt_reached = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_stat_2_num_fail_total_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_STAT_2_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_stat_2_num_retry_lmt_reached_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_STAT_2_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_1_STAT_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL_TOTAL            0x0
 *    11:00 NUM_RETRY_LMT_REACHED     0x0
 * </pre>
 */
#define BAP_BAP_USER_1_STAT_2_ADDR        (REG_BAP_BASE_ADDR+0x00000204)
#define BAP_BAP_USER_1_STAT_2_OFFSET      0x00000204
#define BAP_BAP_USER_1_STAT_2_INDEX       0x00000081
#define BAP_BAP_USER_1_STAT_2_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_1_stat_2_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_1_STAT_2_ADDR);
}

// field definitions
#define BAP_BAP_USER_1_STAT_2_NUM_FAIL_TOTAL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_1_STAT_2_NUM_FAIL_TOTAL_LSB    16
#define BAP_BAP_USER_1_STAT_2_NUM_FAIL_TOTAL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_1_STAT_2_NUM_RETRY_LMT_REACHED_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_1_STAT_2_NUM_RETRY_LMT_REACHED_LSB    0
#define BAP_BAP_USER_1_STAT_2_NUM_RETRY_LMT_REACHED_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_1_STAT_2_NUM_FAIL_TOTAL_RST    0x0
#define BAP_BAP_USER_1_STAT_2_NUM_RETRY_LMT_REACHED_RST    0x0

__INLINE void bap_bap_user_1_stat_2_unpack(uint16_t* num_fail_total, uint16_t* num_retry_lmt_reached)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_STAT_2_ADDR);

	*num_fail_total = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_retry_lmt_reached = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_1_stat_2_num_fail_total_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_1_stat_2_num_retry_lmt_reached_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_2_STAT_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL_TOTAL            0x0
 *    11:00 NUM_RETRY_LMT_REACHED     0x0
 * </pre>
 */
#define BAP_BAP_USER_2_STAT_2_ADDR        (REG_BAP_BASE_ADDR+0x00000208)
#define BAP_BAP_USER_2_STAT_2_OFFSET      0x00000208
#define BAP_BAP_USER_2_STAT_2_INDEX       0x00000082
#define BAP_BAP_USER_2_STAT_2_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_2_stat_2_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_2_STAT_2_ADDR);
}

// field definitions
#define BAP_BAP_USER_2_STAT_2_NUM_FAIL_TOTAL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_2_STAT_2_NUM_FAIL_TOTAL_LSB    16
#define BAP_BAP_USER_2_STAT_2_NUM_FAIL_TOTAL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_2_STAT_2_NUM_RETRY_LMT_REACHED_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_2_STAT_2_NUM_RETRY_LMT_REACHED_LSB    0
#define BAP_BAP_USER_2_STAT_2_NUM_RETRY_LMT_REACHED_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_2_STAT_2_NUM_FAIL_TOTAL_RST    0x0
#define BAP_BAP_USER_2_STAT_2_NUM_RETRY_LMT_REACHED_RST    0x0

__INLINE void bap_bap_user_2_stat_2_unpack(uint16_t* num_fail_total, uint16_t* num_retry_lmt_reached)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_STAT_2_ADDR);

	*num_fail_total = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_retry_lmt_reached = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_2_stat_2_num_fail_total_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_2_stat_2_num_retry_lmt_reached_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_3_STAT_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL_TOTAL            0x0
 *    11:00 NUM_RETRY_LMT_REACHED     0x0
 * </pre>
 */
#define BAP_BAP_USER_3_STAT_2_ADDR        (REG_BAP_BASE_ADDR+0x0000020C)
#define BAP_BAP_USER_3_STAT_2_OFFSET      0x0000020C
#define BAP_BAP_USER_3_STAT_2_INDEX       0x00000083
#define BAP_BAP_USER_3_STAT_2_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_3_stat_2_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_3_STAT_2_ADDR);
}

// field definitions
#define BAP_BAP_USER_3_STAT_2_NUM_FAIL_TOTAL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_3_STAT_2_NUM_FAIL_TOTAL_LSB    16
#define BAP_BAP_USER_3_STAT_2_NUM_FAIL_TOTAL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_3_STAT_2_NUM_RETRY_LMT_REACHED_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_3_STAT_2_NUM_RETRY_LMT_REACHED_LSB    0
#define BAP_BAP_USER_3_STAT_2_NUM_RETRY_LMT_REACHED_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_3_STAT_2_NUM_FAIL_TOTAL_RST    0x0
#define BAP_BAP_USER_3_STAT_2_NUM_RETRY_LMT_REACHED_RST    0x0

__INLINE void bap_bap_user_3_stat_2_unpack(uint16_t* num_fail_total, uint16_t* num_retry_lmt_reached)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_STAT_2_ADDR);

	*num_fail_total = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_retry_lmt_reached = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_3_stat_2_num_fail_total_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_3_stat_2_num_retry_lmt_reached_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_4_STAT_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL_TOTAL            0x0
 *    11:00 NUM_RETRY_LMT_REACHED     0x0
 * </pre>
 */
#define BAP_BAP_USER_4_STAT_2_ADDR        (REG_BAP_BASE_ADDR+0x00000210)
#define BAP_BAP_USER_4_STAT_2_OFFSET      0x00000210
#define BAP_BAP_USER_4_STAT_2_INDEX       0x00000084
#define BAP_BAP_USER_4_STAT_2_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_4_stat_2_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_4_STAT_2_ADDR);
}

// field definitions
#define BAP_BAP_USER_4_STAT_2_NUM_FAIL_TOTAL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_4_STAT_2_NUM_FAIL_TOTAL_LSB    16
#define BAP_BAP_USER_4_STAT_2_NUM_FAIL_TOTAL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_4_STAT_2_NUM_RETRY_LMT_REACHED_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_4_STAT_2_NUM_RETRY_LMT_REACHED_LSB    0
#define BAP_BAP_USER_4_STAT_2_NUM_RETRY_LMT_REACHED_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_4_STAT_2_NUM_FAIL_TOTAL_RST    0x0
#define BAP_BAP_USER_4_STAT_2_NUM_RETRY_LMT_REACHED_RST    0x0

__INLINE void bap_bap_user_4_stat_2_unpack(uint16_t* num_fail_total, uint16_t* num_retry_lmt_reached)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_STAT_2_ADDR);

	*num_fail_total = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_retry_lmt_reached = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_4_stat_2_num_fail_total_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_4_stat_2_num_retry_lmt_reached_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_5_STAT_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL_TOTAL            0x0
 *    11:00 NUM_RETRY_LMT_REACHED     0x0
 * </pre>
 */
#define BAP_BAP_USER_5_STAT_2_ADDR        (REG_BAP_BASE_ADDR+0x00000214)
#define BAP_BAP_USER_5_STAT_2_OFFSET      0x00000214
#define BAP_BAP_USER_5_STAT_2_INDEX       0x00000085
#define BAP_BAP_USER_5_STAT_2_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_5_stat_2_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_5_STAT_2_ADDR);
}

// field definitions
#define BAP_BAP_USER_5_STAT_2_NUM_FAIL_TOTAL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_5_STAT_2_NUM_FAIL_TOTAL_LSB    16
#define BAP_BAP_USER_5_STAT_2_NUM_FAIL_TOTAL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_5_STAT_2_NUM_RETRY_LMT_REACHED_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_5_STAT_2_NUM_RETRY_LMT_REACHED_LSB    0
#define BAP_BAP_USER_5_STAT_2_NUM_RETRY_LMT_REACHED_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_5_STAT_2_NUM_FAIL_TOTAL_RST    0x0
#define BAP_BAP_USER_5_STAT_2_NUM_RETRY_LMT_REACHED_RST    0x0

__INLINE void bap_bap_user_5_stat_2_unpack(uint16_t* num_fail_total, uint16_t* num_retry_lmt_reached)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_STAT_2_ADDR);

	*num_fail_total = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_retry_lmt_reached = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_5_stat_2_num_fail_total_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_5_stat_2_num_retry_lmt_reached_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_6_STAT_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL_TOTAL            0x0
 *    11:00 NUM_RETRY_LMT_REACHED     0x0
 * </pre>
 */
#define BAP_BAP_USER_6_STAT_2_ADDR        (REG_BAP_BASE_ADDR+0x00000218)
#define BAP_BAP_USER_6_STAT_2_OFFSET      0x00000218
#define BAP_BAP_USER_6_STAT_2_INDEX       0x00000086
#define BAP_BAP_USER_6_STAT_2_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_6_stat_2_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_6_STAT_2_ADDR);
}

// field definitions
#define BAP_BAP_USER_6_STAT_2_NUM_FAIL_TOTAL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_6_STAT_2_NUM_FAIL_TOTAL_LSB    16
#define BAP_BAP_USER_6_STAT_2_NUM_FAIL_TOTAL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_6_STAT_2_NUM_RETRY_LMT_REACHED_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_6_STAT_2_NUM_RETRY_LMT_REACHED_LSB    0
#define BAP_BAP_USER_6_STAT_2_NUM_RETRY_LMT_REACHED_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_6_STAT_2_NUM_FAIL_TOTAL_RST    0x0
#define BAP_BAP_USER_6_STAT_2_NUM_RETRY_LMT_REACHED_RST    0x0

__INLINE void bap_bap_user_6_stat_2_unpack(uint16_t* num_fail_total, uint16_t* num_retry_lmt_reached)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_STAT_2_ADDR);

	*num_fail_total = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_retry_lmt_reached = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_6_stat_2_num_fail_total_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_6_stat_2_num_retry_lmt_reached_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_7_STAT_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 NUM_FAIL_TOTAL            0x0
 *    11:00 NUM_RETRY_LMT_REACHED     0x0
 * </pre>
 */
#define BAP_BAP_USER_7_STAT_2_ADDR        (REG_BAP_BASE_ADDR+0x0000021C)
#define BAP_BAP_USER_7_STAT_2_OFFSET      0x0000021C
#define BAP_BAP_USER_7_STAT_2_INDEX       0x00000087
#define BAP_BAP_USER_7_STAT_2_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_7_stat_2_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_7_STAT_2_ADDR);
}

// field definitions
#define BAP_BAP_USER_7_STAT_2_NUM_FAIL_TOTAL_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_7_STAT_2_NUM_FAIL_TOTAL_LSB    16
#define BAP_BAP_USER_7_STAT_2_NUM_FAIL_TOTAL_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_7_STAT_2_NUM_RETRY_LMT_REACHED_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_7_STAT_2_NUM_RETRY_LMT_REACHED_LSB    0
#define BAP_BAP_USER_7_STAT_2_NUM_RETRY_LMT_REACHED_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_7_STAT_2_NUM_FAIL_TOTAL_RST    0x0
#define BAP_BAP_USER_7_STAT_2_NUM_RETRY_LMT_REACHED_RST    0x0

__INLINE void bap_bap_user_7_stat_2_unpack(uint16_t* num_fail_total, uint16_t* num_retry_lmt_reached)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_STAT_2_ADDR);

	*num_fail_total = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*num_retry_lmt_reached = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_7_stat_2_num_fail_total_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_7_stat_2_num_retry_lmt_reached_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_STAT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_STAT_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 ABOVE_BAW                 0x0
 *    11:00 BELOW_BAW                 0x0
 * </pre>
 */
#define BAP_BAP_USER_STAT_3_ADDR        (REG_BAP_BASE_ADDR+0x00000220)
#define BAP_BAP_USER_STAT_3_OFFSET      0x00000220
#define BAP_BAP_USER_STAT_3_INDEX       0x00000088
#define BAP_BAP_USER_STAT_3_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_stat_3_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_STAT_3_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

// field definitions
#define BAP_BAP_USER_STAT_3_ABOVE_BAW_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_STAT_3_ABOVE_BAW_LSB    16
#define BAP_BAP_USER_STAT_3_ABOVE_BAW_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_STAT_3_BELOW_BAW_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_STAT_3_BELOW_BAW_LSB    0
#define BAP_BAP_USER_STAT_3_BELOW_BAW_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_STAT_3_ABOVE_BAW_RST    0x0
#define BAP_BAP_USER_STAT_3_BELOW_BAW_RST    0x0

__INLINE void bap_bap_user_stat_3_unpack(uint16_t* above_baw, uint16_t* below_baw, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_STAT_3_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));

	*above_baw = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*below_baw = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_stat_3_above_baw_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_STAT_3_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_stat_3_below_baw_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_STAT_3_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_1_STAT_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 ABOVE_BAW                 0x0
 *    11:00 BELOW_BAW                 0x0
 * </pre>
 */
#define BAP_BAP_USER_1_STAT_3_ADDR        (REG_BAP_BASE_ADDR+0x00000224)
#define BAP_BAP_USER_1_STAT_3_OFFSET      0x00000224
#define BAP_BAP_USER_1_STAT_3_INDEX       0x00000089
#define BAP_BAP_USER_1_STAT_3_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_1_stat_3_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_1_STAT_3_ADDR);
}

// field definitions
#define BAP_BAP_USER_1_STAT_3_ABOVE_BAW_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_1_STAT_3_ABOVE_BAW_LSB    16
#define BAP_BAP_USER_1_STAT_3_ABOVE_BAW_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_1_STAT_3_BELOW_BAW_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_1_STAT_3_BELOW_BAW_LSB    0
#define BAP_BAP_USER_1_STAT_3_BELOW_BAW_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_1_STAT_3_ABOVE_BAW_RST    0x0
#define BAP_BAP_USER_1_STAT_3_BELOW_BAW_RST    0x0

__INLINE void bap_bap_user_1_stat_3_unpack(uint16_t* above_baw, uint16_t* below_baw)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_STAT_3_ADDR);

	*above_baw = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*below_baw = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_1_stat_3_above_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_1_stat_3_below_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_2_STAT_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 ABOVE_BAW                 0x0
 *    11:00 BELOW_BAW                 0x0
 * </pre>
 */
#define BAP_BAP_USER_2_STAT_3_ADDR        (REG_BAP_BASE_ADDR+0x00000228)
#define BAP_BAP_USER_2_STAT_3_OFFSET      0x00000228
#define BAP_BAP_USER_2_STAT_3_INDEX       0x0000008A
#define BAP_BAP_USER_2_STAT_3_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_2_stat_3_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_2_STAT_3_ADDR);
}

// field definitions
#define BAP_BAP_USER_2_STAT_3_ABOVE_BAW_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_2_STAT_3_ABOVE_BAW_LSB    16
#define BAP_BAP_USER_2_STAT_3_ABOVE_BAW_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_2_STAT_3_BELOW_BAW_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_2_STAT_3_BELOW_BAW_LSB    0
#define BAP_BAP_USER_2_STAT_3_BELOW_BAW_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_2_STAT_3_ABOVE_BAW_RST    0x0
#define BAP_BAP_USER_2_STAT_3_BELOW_BAW_RST    0x0

__INLINE void bap_bap_user_2_stat_3_unpack(uint16_t* above_baw, uint16_t* below_baw)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_STAT_3_ADDR);

	*above_baw = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*below_baw = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_2_stat_3_above_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_2_stat_3_below_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_3_STAT_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 ABOVE_BAW                 0x0
 *    11:00 BELOW_BAW                 0x0
 * </pre>
 */
#define BAP_BAP_USER_3_STAT_3_ADDR        (REG_BAP_BASE_ADDR+0x0000022C)
#define BAP_BAP_USER_3_STAT_3_OFFSET      0x0000022C
#define BAP_BAP_USER_3_STAT_3_INDEX       0x0000008B
#define BAP_BAP_USER_3_STAT_3_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_3_stat_3_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_3_STAT_3_ADDR);
}

// field definitions
#define BAP_BAP_USER_3_STAT_3_ABOVE_BAW_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_3_STAT_3_ABOVE_BAW_LSB    16
#define BAP_BAP_USER_3_STAT_3_ABOVE_BAW_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_3_STAT_3_BELOW_BAW_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_3_STAT_3_BELOW_BAW_LSB    0
#define BAP_BAP_USER_3_STAT_3_BELOW_BAW_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_3_STAT_3_ABOVE_BAW_RST    0x0
#define BAP_BAP_USER_3_STAT_3_BELOW_BAW_RST    0x0

__INLINE void bap_bap_user_3_stat_3_unpack(uint16_t* above_baw, uint16_t* below_baw)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_STAT_3_ADDR);

	*above_baw = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*below_baw = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_3_stat_3_above_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_3_stat_3_below_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_4_STAT_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 ABOVE_BAW                 0x0
 *    11:00 BELOW_BAW                 0x0
 * </pre>
 */
#define BAP_BAP_USER_4_STAT_3_ADDR        (REG_BAP_BASE_ADDR+0x00000230)
#define BAP_BAP_USER_4_STAT_3_OFFSET      0x00000230
#define BAP_BAP_USER_4_STAT_3_INDEX       0x0000008C
#define BAP_BAP_USER_4_STAT_3_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_4_stat_3_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_4_STAT_3_ADDR);
}

// field definitions
#define BAP_BAP_USER_4_STAT_3_ABOVE_BAW_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_4_STAT_3_ABOVE_BAW_LSB    16
#define BAP_BAP_USER_4_STAT_3_ABOVE_BAW_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_4_STAT_3_BELOW_BAW_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_4_STAT_3_BELOW_BAW_LSB    0
#define BAP_BAP_USER_4_STAT_3_BELOW_BAW_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_4_STAT_3_ABOVE_BAW_RST    0x0
#define BAP_BAP_USER_4_STAT_3_BELOW_BAW_RST    0x0

__INLINE void bap_bap_user_4_stat_3_unpack(uint16_t* above_baw, uint16_t* below_baw)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_STAT_3_ADDR);

	*above_baw = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*below_baw = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_4_stat_3_above_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_4_stat_3_below_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_5_STAT_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 ABOVE_BAW                 0x0
 *    11:00 BELOW_BAW                 0x0
 * </pre>
 */
#define BAP_BAP_USER_5_STAT_3_ADDR        (REG_BAP_BASE_ADDR+0x00000234)
#define BAP_BAP_USER_5_STAT_3_OFFSET      0x00000234
#define BAP_BAP_USER_5_STAT_3_INDEX       0x0000008D
#define BAP_BAP_USER_5_STAT_3_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_5_stat_3_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_5_STAT_3_ADDR);
}

// field definitions
#define BAP_BAP_USER_5_STAT_3_ABOVE_BAW_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_5_STAT_3_ABOVE_BAW_LSB    16
#define BAP_BAP_USER_5_STAT_3_ABOVE_BAW_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_5_STAT_3_BELOW_BAW_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_5_STAT_3_BELOW_BAW_LSB    0
#define BAP_BAP_USER_5_STAT_3_BELOW_BAW_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_5_STAT_3_ABOVE_BAW_RST    0x0
#define BAP_BAP_USER_5_STAT_3_BELOW_BAW_RST    0x0

__INLINE void bap_bap_user_5_stat_3_unpack(uint16_t* above_baw, uint16_t* below_baw)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_STAT_3_ADDR);

	*above_baw = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*below_baw = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_5_stat_3_above_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_5_stat_3_below_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_6_STAT_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 ABOVE_BAW                 0x0
 *    11:00 BELOW_BAW                 0x0
 * </pre>
 */
#define BAP_BAP_USER_6_STAT_3_ADDR        (REG_BAP_BASE_ADDR+0x00000238)
#define BAP_BAP_USER_6_STAT_3_OFFSET      0x00000238
#define BAP_BAP_USER_6_STAT_3_INDEX       0x0000008E
#define BAP_BAP_USER_6_STAT_3_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_6_stat_3_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_6_STAT_3_ADDR);
}

// field definitions
#define BAP_BAP_USER_6_STAT_3_ABOVE_BAW_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_6_STAT_3_ABOVE_BAW_LSB    16
#define BAP_BAP_USER_6_STAT_3_ABOVE_BAW_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_6_STAT_3_BELOW_BAW_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_6_STAT_3_BELOW_BAW_LSB    0
#define BAP_BAP_USER_6_STAT_3_BELOW_BAW_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_6_STAT_3_ABOVE_BAW_RST    0x0
#define BAP_BAP_USER_6_STAT_3_BELOW_BAW_RST    0x0

__INLINE void bap_bap_user_6_stat_3_unpack(uint16_t* above_baw, uint16_t* below_baw)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_STAT_3_ADDR);

	*above_baw = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*below_baw = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_6_stat_3_above_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_6_stat_3_below_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_USER_7_STAT_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:16 ABOVE_BAW                 0x0
 *    11:00 BELOW_BAW                 0x0
 * </pre>
 */
#define BAP_BAP_USER_7_STAT_3_ADDR        (REG_BAP_BASE_ADDR+0x0000023C)
#define BAP_BAP_USER_7_STAT_3_OFFSET      0x0000023C
#define BAP_BAP_USER_7_STAT_3_INDEX       0x0000008F
#define BAP_BAP_USER_7_STAT_3_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_7_stat_3_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_7_STAT_3_ADDR);
}

// field definitions
#define BAP_BAP_USER_7_STAT_3_ABOVE_BAW_MASK    ((uint32_t)0x0FFF0000)
#define BAP_BAP_USER_7_STAT_3_ABOVE_BAW_LSB    16
#define BAP_BAP_USER_7_STAT_3_ABOVE_BAW_WIDTH    ((uint32_t)0x0000000C)
#define BAP_BAP_USER_7_STAT_3_BELOW_BAW_MASK    ((uint32_t)0x00000FFF)
#define BAP_BAP_USER_7_STAT_3_BELOW_BAW_LSB    0
#define BAP_BAP_USER_7_STAT_3_BELOW_BAW_WIDTH    ((uint32_t)0x0000000C)

#define BAP_BAP_USER_7_STAT_3_ABOVE_BAW_RST    0x0
#define BAP_BAP_USER_7_STAT_3_BELOW_BAW_RST    0x0

__INLINE void bap_bap_user_7_stat_3_unpack(uint16_t* above_baw, uint16_t* below_baw)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_STAT_3_ADDR);

	*above_baw = (localVal & ((uint32_t)0x0FFF0000)) >>  16;
	*below_baw = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint16_t bap_bap_user_7_stat_3_above_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0FFF0000)) >> 16);
}
__INLINE uint16_t bap_bap_user_7_stat_3_below_baw_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_STAT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief BAP_INT_RAW_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 AXI_ERROR                 0x0
 *    07:00 BAP_DONE                  0x0
 * </pre>
 */
#define BAP_BAP_INT_RAW_STATUS_ADDR        (REG_BAP_BASE_ADDR+0x00000240)
#define BAP_BAP_INT_RAW_STATUS_OFFSET      0x00000240
#define BAP_BAP_INT_RAW_STATUS_INDEX       0x00000090
#define BAP_BAP_INT_RAW_STATUS_RESET       0x00000000

__INLINE uint32_t  bap_bap_int_raw_status_get(void)
{
	return REG_PL_RD(BAP_BAP_INT_RAW_STATUS_ADDR);
}

// field definitions
#define BAP_BAP_INT_RAW_STATUS_AXI_ERROR_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_INT_RAW_STATUS_AXI_ERROR_LSB    16
#define BAP_BAP_INT_RAW_STATUS_AXI_ERROR_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_INT_RAW_STATUS_BAP_DONE_MASK    ((uint32_t)0x000000FF)
#define BAP_BAP_INT_RAW_STATUS_BAP_DONE_LSB    0
#define BAP_BAP_INT_RAW_STATUS_BAP_DONE_WIDTH    ((uint32_t)0x00000008)

#define BAP_BAP_INT_RAW_STATUS_AXI_ERROR_RST    0x0
#define BAP_BAP_INT_RAW_STATUS_BAP_DONE_RST    0x0

__INLINE void bap_bap_int_raw_status_unpack(uint8_t* axi_error, uint8_t* bap_done)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_INT_RAW_STATUS_ADDR);

	*axi_error = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*bap_done = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t bap_bap_int_raw_status_axi_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_INT_RAW_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t bap_bap_int_raw_status_bap_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_INT_RAW_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief BAP_INT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 AXI_ERROR_EN              0x0
 *    07:00 BAP_DONE_EN               0x0
 * </pre>
 */
#define BAP_BAP_INT_EN_ADDR        (REG_BAP_BASE_ADDR+0x00000244)
#define BAP_BAP_INT_EN_OFFSET      0x00000244
#define BAP_BAP_INT_EN_INDEX       0x00000091
#define BAP_BAP_INT_EN_RESET       0x00000000

__INLINE uint32_t  bap_bap_int_en_get(void)
{
	return REG_PL_RD(BAP_BAP_INT_EN_ADDR);
}

__INLINE void bap_bap_int_en_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_INT_EN_ADDR, value);
}

// field definitions
#define BAP_BAP_INT_EN_AXI_ERROR_EN_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_INT_EN_AXI_ERROR_EN_LSB     16
#define BAP_BAP_INT_EN_AXI_ERROR_EN_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_INT_EN_BAP_DONE_EN_MASK     ((uint32_t)0x000000FF)
#define BAP_BAP_INT_EN_BAP_DONE_EN_LSB      0
#define BAP_BAP_INT_EN_BAP_DONE_EN_WIDTH    ((uint32_t)0x00000008)

#define BAP_BAP_INT_EN_AXI_ERROR_EN_RST     0x0
#define BAP_BAP_INT_EN_BAP_DONE_EN_RST      0x0

__INLINE void bap_bap_int_en_pack(uint8_t axi_error_en, uint8_t bap_done_en)
{
	ASSERT_ERR((((uint32_t)axi_error_en << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)bap_done_en << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BAP_BAP_INT_EN_ADDR,  ((uint32_t)axi_error_en << 16) |((uint32_t)bap_done_en << 0));
}

__INLINE void bap_bap_int_en_unpack(uint8_t* axi_error_en, uint8_t* bap_done_en)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_INT_EN_ADDR);

	*axi_error_en = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*bap_done_en = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t bap_bap_int_en_axi_error_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void bap_bap_int_en_axi_error_en_setf(uint8_t axierroren)
{
	ASSERT_ERR((((uint32_t)axierroren << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(BAP_BAP_INT_EN_ADDR, (REG_PL_RD(BAP_BAP_INT_EN_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)axierroren <<16));
}
__INLINE uint8_t bap_bap_int_en_bap_done_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void bap_bap_int_en_bap_done_en_setf(uint8_t bapdoneen)
{
	ASSERT_ERR((((uint32_t)bapdoneen << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BAP_BAP_INT_EN_ADDR, (REG_PL_RD(BAP_BAP_INT_EN_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)bapdoneen <<0));
}

/**
 * @brief BAP_INT_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 AXI_ERROR                 0x0
 *    07:00 BAP_DONE                  0x0
 * </pre>
 */
#define BAP_BAP_INT_STATUS_ADDR        (REG_BAP_BASE_ADDR+0x00000248)
#define BAP_BAP_INT_STATUS_OFFSET      0x00000248
#define BAP_BAP_INT_STATUS_INDEX       0x00000092
#define BAP_BAP_INT_STATUS_RESET       0x00000000

__INLINE uint32_t  bap_bap_int_status_get(void)
{
	return REG_PL_RD(BAP_BAP_INT_STATUS_ADDR);
}

// field definitions
#define BAP_BAP_INT_STATUS_AXI_ERROR_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_INT_STATUS_AXI_ERROR_LSB    16
#define BAP_BAP_INT_STATUS_AXI_ERROR_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_INT_STATUS_BAP_DONE_MASK    ((uint32_t)0x000000FF)
#define BAP_BAP_INT_STATUS_BAP_DONE_LSB     0
#define BAP_BAP_INT_STATUS_BAP_DONE_WIDTH    ((uint32_t)0x00000008)

#define BAP_BAP_INT_STATUS_AXI_ERROR_RST    0x0
#define BAP_BAP_INT_STATUS_BAP_DONE_RST     0x0

__INLINE void bap_bap_int_status_unpack(uint8_t* axi_error, uint8_t* bap_done)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_INT_STATUS_ADDR);

	*axi_error = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*bap_done = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t bap_bap_int_status_axi_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_INT_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t bap_bap_int_status_bap_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_INT_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief BAP_INT_FORCE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 AXI_ERROR_FORCE           0x0
 *    07:00 BAP_DONE_FORCE            0x0
 * </pre>
 */
#define BAP_BAP_INT_FORCE_ADDR        (REG_BAP_BASE_ADDR+0x0000024C)
#define BAP_BAP_INT_FORCE_OFFSET      0x0000024C
#define BAP_BAP_INT_FORCE_INDEX       0x00000093
#define BAP_BAP_INT_FORCE_RESET       0x00000000

__INLINE void bap_bap_int_force_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_INT_FORCE_ADDR, value);
}

// field definitions
#define BAP_BAP_INT_FORCE_AXI_ERROR_FORCE_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_INT_FORCE_AXI_ERROR_FORCE_LSB    16
#define BAP_BAP_INT_FORCE_AXI_ERROR_FORCE_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_INT_FORCE_BAP_DONE_FORCE_MASK    ((uint32_t)0x000000FF)
#define BAP_BAP_INT_FORCE_BAP_DONE_FORCE_LSB    0
#define BAP_BAP_INT_FORCE_BAP_DONE_FORCE_WIDTH    ((uint32_t)0x00000008)

#define BAP_BAP_INT_FORCE_AXI_ERROR_FORCE_RST    0x0
#define BAP_BAP_INT_FORCE_BAP_DONE_FORCE_RST    0x0

__INLINE void bap_bap_int_force_pack(uint8_t axi_error_force, uint8_t bap_done_force)
{
	ASSERT_ERR((((uint32_t)axi_error_force << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)bap_done_force << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BAP_BAP_INT_FORCE_ADDR,  ((uint32_t)axi_error_force << 16) |((uint32_t)bap_done_force << 0));
}

__INLINE void bap_bap_int_force_axi_error_force_setf(uint8_t axierrorforce)
{
	ASSERT_ERR((((uint32_t)axierrorforce << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(BAP_BAP_INT_FORCE_ADDR, (REG_PL_RD(BAP_BAP_INT_FORCE_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)axierrorforce <<16));
}
__INLINE void bap_bap_int_force_bap_done_force_setf(uint8_t bapdoneforce)
{
	ASSERT_ERR((((uint32_t)bapdoneforce << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BAP_BAP_INT_FORCE_ADDR, (REG_PL_RD(BAP_BAP_INT_FORCE_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)bapdoneforce <<0));
}

/**
 * @brief BAP_INT_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 AXI_ERROR_CLEAR           0x0
 *    07:00 BAP_DONE_CLEAR            0x0
 * </pre>
 */
#define BAP_BAP_INT_CLEAR_ADDR        (REG_BAP_BASE_ADDR+0x00000250)
#define BAP_BAP_INT_CLEAR_OFFSET      0x00000250
#define BAP_BAP_INT_CLEAR_INDEX       0x00000094
#define BAP_BAP_INT_CLEAR_RESET       0x00000000

__INLINE void bap_bap_int_clear_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_INT_CLEAR_ADDR, value);
}

// field definitions
#define BAP_BAP_INT_CLEAR_AXI_ERROR_CLEAR_MASK    ((uint32_t)0x00FF0000)
#define BAP_BAP_INT_CLEAR_AXI_ERROR_CLEAR_LSB    16
#define BAP_BAP_INT_CLEAR_AXI_ERROR_CLEAR_WIDTH    ((uint32_t)0x00000008)
#define BAP_BAP_INT_CLEAR_BAP_DONE_CLEAR_MASK    ((uint32_t)0x000000FF)
#define BAP_BAP_INT_CLEAR_BAP_DONE_CLEAR_LSB    0
#define BAP_BAP_INT_CLEAR_BAP_DONE_CLEAR_WIDTH    ((uint32_t)0x00000008)

#define BAP_BAP_INT_CLEAR_AXI_ERROR_CLEAR_RST    0x0
#define BAP_BAP_INT_CLEAR_BAP_DONE_CLEAR_RST    0x0

__INLINE void bap_bap_int_clear_pack(uint8_t axi_error_clear, uint8_t bap_done_clear)
{
	ASSERT_ERR((((uint32_t)axi_error_clear << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)bap_done_clear << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BAP_BAP_INT_CLEAR_ADDR,  ((uint32_t)axi_error_clear << 16) |((uint32_t)bap_done_clear << 0));
}

__INLINE void bap_bap_int_clear_axi_error_clear_setf(uint8_t axierrorclear)
{
	ASSERT_ERR((((uint32_t)axierrorclear << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(BAP_BAP_INT_CLEAR_ADDR, (REG_PL_RD(BAP_BAP_INT_CLEAR_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)axierrorclear <<16));
}
__INLINE void bap_bap_int_clear_bap_done_clear_setf(uint8_t bapdoneclear)
{
	ASSERT_ERR((((uint32_t)bapdoneclear << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(BAP_BAP_INT_CLEAR_ADDR, (REG_PL_RD(BAP_BAP_INT_CLEAR_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)bapdoneclear <<0));
}

/**
 * @brief BAP_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 BAP_USER_STATUS           0x0
 * </pre>
 */
#define BAP_BAP_STATUS_ADDR        (REG_BAP_BASE_ADDR+0x00000254)
#define BAP_BAP_STATUS_OFFSET      0x00000254
#define BAP_BAP_STATUS_INDEX       0x00000095
#define BAP_BAP_STATUS_RESET       0x00000000

__INLINE uint32_t  bap_bap_status_get(void)
{
	return REG_PL_RD(BAP_BAP_STATUS_ADDR);
}

// field definitions
#define BAP_BAP_STATUS_BAP_USER_STATUS_MASK    ((uint32_t)0x000000FF)
#define BAP_BAP_STATUS_BAP_USER_STATUS_LSB    0
#define BAP_BAP_STATUS_BAP_USER_STATUS_WIDTH    ((uint32_t)0x00000008)

#define BAP_BAP_STATUS_BAP_USER_STATUS_RST    0x0

__INLINE uint8_t bap_bap_status_bap_user_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_STATUS_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief BAP_DEBUG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:20 BAP_WR_STATE              0x0
 *    19:16 BAP_RD_STATE              0x0
 *    07:00 BAP_USER_ACTIVE           0x0
 * </pre>
 */
#define BAP_BAP_DEBUG_ADDR        (REG_BAP_BASE_ADDR+0x00000258)
#define BAP_BAP_DEBUG_OFFSET      0x00000258
#define BAP_BAP_DEBUG_INDEX       0x00000096
#define BAP_BAP_DEBUG_RESET       0x00000000

__INLINE uint32_t  bap_bap_debug_get(void)
{
	return REG_PL_RD(BAP_BAP_DEBUG_ADDR);
}

// field definitions
#define BAP_BAP_DEBUG_BAP_WR_STATE_MASK     ((uint32_t)0x00F00000)
#define BAP_BAP_DEBUG_BAP_WR_STATE_LSB      20
#define BAP_BAP_DEBUG_BAP_WR_STATE_WIDTH    ((uint32_t)0x00000004)
#define BAP_BAP_DEBUG_BAP_RD_STATE_MASK     ((uint32_t)0x000F0000)
#define BAP_BAP_DEBUG_BAP_RD_STATE_LSB      16
#define BAP_BAP_DEBUG_BAP_RD_STATE_WIDTH    ((uint32_t)0x00000004)
#define BAP_BAP_DEBUG_BAP_USER_ACTIVE_MASK    ((uint32_t)0x000000FF)
#define BAP_BAP_DEBUG_BAP_USER_ACTIVE_LSB    0
#define BAP_BAP_DEBUG_BAP_USER_ACTIVE_WIDTH    ((uint32_t)0x00000008)

#define BAP_BAP_DEBUG_BAP_WR_STATE_RST      0x0
#define BAP_BAP_DEBUG_BAP_RD_STATE_RST      0x0
#define BAP_BAP_DEBUG_BAP_USER_ACTIVE_RST    0x0

__INLINE void bap_bap_debug_unpack(uint8_t* bap_wr_state, uint8_t* bap_rd_state, uint8_t* bap_user_active)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_DEBUG_ADDR);

	*bap_wr_state = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*bap_rd_state = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*bap_user_active = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t bap_bap_debug_bap_wr_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_DEBUG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE uint8_t bap_bap_debug_bap_rd_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_DEBUG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE uint8_t bap_bap_debug_bap_user_active_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_DEBUG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief BAP_SW_RST register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    SW_RESET                  0              
 * </pre>
 */
#define BAP_BAP_SW_RST_ADDR        (REG_BAP_BASE_ADDR+0x0000025C)
#define BAP_BAP_SW_RST_OFFSET      0x0000025C
#define BAP_BAP_SW_RST_INDEX       0x00000097
#define BAP_BAP_SW_RST_RESET       0x00000000

__INLINE void bap_bap_sw_rst_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_SW_RST_ADDR, value);
}

// field definitions
#define BAP_BAP_SW_RST_SW_RESET_BIT         ((uint32_t)0x00000001)
#define BAP_BAP_SW_RST_SW_RESET_POS         0

#define BAP_BAP_SW_RST_SW_RESET_RST         0x0

__INLINE void bap_bap_sw_rst_sw_reset_setf(uint8_t swreset)
{
	ASSERT_ERR((((uint32_t)swreset << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(BAP_BAP_SW_RST_ADDR, (uint32_t)swreset << 0);
}

/**
 * @brief BAP_USER_TXDESC_ADDR_MASK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    USE_TXDESC_HIGH_ADDR      0              
 *    13:00 TXDESC_HIGH_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_USER_TXDESC_ADDR_MASK_ADDR        (REG_BAP_BASE_ADDR+0x00000260)
#define BAP_BAP_USER_TXDESC_ADDR_MASK_OFFSET      0x00000260
#define BAP_BAP_USER_TXDESC_ADDR_MASK_INDEX       0x00000098
#define BAP_BAP_USER_TXDESC_ADDR_MASK_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_txdesc_addr_mask_get(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_TXDESC_ADDR_MASK_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (localVal);
}

__INLINE void  bap_bap_user_txdesc_addr_mask_set(uint32_t value, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	REG_PL_WR((BAP_BAP_USER_TXDESC_ADDR_MASK_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), value);
}

// field definitions
#define BAP_BAP_USER_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_BIT    ((uint32_t)0x00010000)
#define BAP_BAP_USER_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_POS    16
#define BAP_BAP_USER_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_MASK    ((uint32_t)0x00003FFF)
#define BAP_BAP_USER_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_LSB    0
#define BAP_BAP_USER_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_WIDTH    ((uint32_t)0x0000000E)

#define BAP_BAP_USER_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_RST    0x0
#define BAP_BAP_USER_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_RST    0x0

__INLINE void bap_bap_user_txdesc_addr_mask_pack(uint8_t use_txdesc_high_addr, uint16_t txdesc_high_addr, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)use_txdesc_high_addr << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)txdesc_high_addr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR((BAP_BAP_USER_TXDESC_ADDR_MASK_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)),  ((uint32_t)use_txdesc_high_addr << 16) |((uint32_t)txdesc_high_addr << 0));
}

__INLINE void bap_bap_user_txdesc_addr_mask_unpack(uint8_t* use_txdesc_high_addr, uint16_t* txdesc_high_addr, uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_TXDESC_ADDR_MASK_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));

	*use_txdesc_high_addr = (localVal & ((uint32_t)0x00010000)) >>  16;
	*txdesc_high_addr = (localVal & ((uint32_t)0x00003FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_txdesc_addr_mask_use_txdesc_high_addr_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_TXDESC_ADDR_MASK_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void bap_bap_user_txdesc_addr_mask_use_txdesc_high_addr_setf(uint8_t usetxdeschighaddr,uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)usetxdeschighaddr << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR((BAP_BAP_USER_TXDESC_ADDR_MASK_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (REG_PL_RD(BAP_BAP_USER_TXDESC_ADDR_MASK_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)) & ~((uint32_t)0x00010000)) | ((uint32_t)usetxdeschighaddr <<16));
}
__INLINE uint16_t bap_bap_user_txdesc_addr_mask_txdesc_high_addr_getf(uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_TXDESC_ADDR_MASK_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx));
	return (uint16_t)((localVal & ((uint32_t)0x00003FFF)) >> 0);
}
__INLINE void bap_bap_user_txdesc_addr_mask_txdesc_high_addr_setf(uint16_t txdeschighaddr,uint8_t mu_idx)
{
	ASSERT_ERR_REG(mu_idx < MAX_MU_CNT);
	ASSERT_ERR((((uint32_t)txdeschighaddr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR((BAP_BAP_USER_TXDESC_ADDR_MASK_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)), (REG_PL_RD(BAP_BAP_USER_TXDESC_ADDR_MASK_ADDR + CE_BAP_MU_ADDR_OFFSET(mu_idx)) & ~((uint32_t)0x00003FFF)) | ((uint32_t)txdeschighaddr <<0));
}

/**
 * @brief BAP_USER_1_TXDESC_ADDR_MASK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    USE_TXDESC_HIGH_ADDR      0              
 *    13:00 TXDESC_HIGH_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_USER_1_TXDESC_ADDR_MASK_ADDR        (REG_BAP_BASE_ADDR+0x00000264)
#define BAP_BAP_USER_1_TXDESC_ADDR_MASK_OFFSET      0x00000264
#define BAP_BAP_USER_1_TXDESC_ADDR_MASK_INDEX       0x00000099
#define BAP_BAP_USER_1_TXDESC_ADDR_MASK_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_1_txdesc_addr_mask_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_1_TXDESC_ADDR_MASK_ADDR);
}

__INLINE void bap_bap_user_1_txdesc_addr_mask_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_1_TXDESC_ADDR_MASK_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_1_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_BIT    ((uint32_t)0x00010000)
#define BAP_BAP_USER_1_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_POS    16
#define BAP_BAP_USER_1_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_MASK    ((uint32_t)0x00003FFF)
#define BAP_BAP_USER_1_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_LSB    0
#define BAP_BAP_USER_1_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_WIDTH    ((uint32_t)0x0000000E)

#define BAP_BAP_USER_1_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_RST    0x0
#define BAP_BAP_USER_1_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_RST    0x0

__INLINE void bap_bap_user_1_txdesc_addr_mask_pack(uint8_t use_txdesc_high_addr, uint16_t txdesc_high_addr)
{
	ASSERT_ERR((((uint32_t)use_txdesc_high_addr << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)txdesc_high_addr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_TXDESC_ADDR_MASK_ADDR,  ((uint32_t)use_txdesc_high_addr << 16) |((uint32_t)txdesc_high_addr << 0));
}

__INLINE void bap_bap_user_1_txdesc_addr_mask_unpack(uint8_t* use_txdesc_high_addr, uint16_t* txdesc_high_addr)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_TXDESC_ADDR_MASK_ADDR);

	*use_txdesc_high_addr = (localVal & ((uint32_t)0x00010000)) >>  16;
	*txdesc_high_addr = (localVal & ((uint32_t)0x00003FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_1_txdesc_addr_mask_use_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_TXDESC_ADDR_MASK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void bap_bap_user_1_txdesc_addr_mask_use_txdesc_high_addr_setf(uint8_t usetxdeschighaddr)
{
	ASSERT_ERR((((uint32_t)usetxdeschighaddr << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_1_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)usetxdeschighaddr <<16));
}
__INLINE uint16_t bap_bap_user_1_txdesc_addr_mask_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_1_TXDESC_ADDR_MASK_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00003FFF)) >> 0);
}
__INLINE void bap_bap_user_1_txdesc_addr_mask_txdesc_high_addr_setf(uint16_t txdeschighaddr)
{
	ASSERT_ERR((((uint32_t)txdeschighaddr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_1_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_1_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)txdeschighaddr <<0));
}

/**
 * @brief BAP_USER_2_TXDESC_ADDR_MASK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    USE_TXDESC_HIGH_ADDR      0              
 *    13:00 TXDESC_HIGH_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_USER_2_TXDESC_ADDR_MASK_ADDR        (REG_BAP_BASE_ADDR+0x00000268)
#define BAP_BAP_USER_2_TXDESC_ADDR_MASK_OFFSET      0x00000268
#define BAP_BAP_USER_2_TXDESC_ADDR_MASK_INDEX       0x0000009A
#define BAP_BAP_USER_2_TXDESC_ADDR_MASK_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_2_txdesc_addr_mask_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_2_TXDESC_ADDR_MASK_ADDR);
}

__INLINE void bap_bap_user_2_txdesc_addr_mask_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_2_TXDESC_ADDR_MASK_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_2_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_BIT    ((uint32_t)0x00010000)
#define BAP_BAP_USER_2_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_POS    16
#define BAP_BAP_USER_2_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_MASK    ((uint32_t)0x00003FFF)
#define BAP_BAP_USER_2_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_LSB    0
#define BAP_BAP_USER_2_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_WIDTH    ((uint32_t)0x0000000E)

#define BAP_BAP_USER_2_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_RST    0x0
#define BAP_BAP_USER_2_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_RST    0x0

__INLINE void bap_bap_user_2_txdesc_addr_mask_pack(uint8_t use_txdesc_high_addr, uint16_t txdesc_high_addr)
{
	ASSERT_ERR((((uint32_t)use_txdesc_high_addr << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)txdesc_high_addr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_TXDESC_ADDR_MASK_ADDR,  ((uint32_t)use_txdesc_high_addr << 16) |((uint32_t)txdesc_high_addr << 0));
}

__INLINE void bap_bap_user_2_txdesc_addr_mask_unpack(uint8_t* use_txdesc_high_addr, uint16_t* txdesc_high_addr)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_TXDESC_ADDR_MASK_ADDR);

	*use_txdesc_high_addr = (localVal & ((uint32_t)0x00010000)) >>  16;
	*txdesc_high_addr = (localVal & ((uint32_t)0x00003FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_2_txdesc_addr_mask_use_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_TXDESC_ADDR_MASK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void bap_bap_user_2_txdesc_addr_mask_use_txdesc_high_addr_setf(uint8_t usetxdeschighaddr)
{
	ASSERT_ERR((((uint32_t)usetxdeschighaddr << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_2_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)usetxdeschighaddr <<16));
}
__INLINE uint16_t bap_bap_user_2_txdesc_addr_mask_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_2_TXDESC_ADDR_MASK_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00003FFF)) >> 0);
}
__INLINE void bap_bap_user_2_txdesc_addr_mask_txdesc_high_addr_setf(uint16_t txdeschighaddr)
{
	ASSERT_ERR((((uint32_t)txdeschighaddr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_2_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_2_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)txdeschighaddr <<0));
}

/**
 * @brief BAP_USER_3_TXDESC_ADDR_MASK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    USE_TXDESC_HIGH_ADDR      0              
 *    13:00 TXDESC_HIGH_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_USER_3_TXDESC_ADDR_MASK_ADDR        (REG_BAP_BASE_ADDR+0x0000026C)
#define BAP_BAP_USER_3_TXDESC_ADDR_MASK_OFFSET      0x0000026C
#define BAP_BAP_USER_3_TXDESC_ADDR_MASK_INDEX       0x0000009B
#define BAP_BAP_USER_3_TXDESC_ADDR_MASK_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_3_txdesc_addr_mask_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_3_TXDESC_ADDR_MASK_ADDR);
}

__INLINE void bap_bap_user_3_txdesc_addr_mask_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_3_TXDESC_ADDR_MASK_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_3_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_BIT    ((uint32_t)0x00010000)
#define BAP_BAP_USER_3_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_POS    16
#define BAP_BAP_USER_3_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_MASK    ((uint32_t)0x00003FFF)
#define BAP_BAP_USER_3_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_LSB    0
#define BAP_BAP_USER_3_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_WIDTH    ((uint32_t)0x0000000E)

#define BAP_BAP_USER_3_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_RST    0x0
#define BAP_BAP_USER_3_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_RST    0x0

__INLINE void bap_bap_user_3_txdesc_addr_mask_pack(uint8_t use_txdesc_high_addr, uint16_t txdesc_high_addr)
{
	ASSERT_ERR((((uint32_t)use_txdesc_high_addr << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)txdesc_high_addr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_TXDESC_ADDR_MASK_ADDR,  ((uint32_t)use_txdesc_high_addr << 16) |((uint32_t)txdesc_high_addr << 0));
}

__INLINE void bap_bap_user_3_txdesc_addr_mask_unpack(uint8_t* use_txdesc_high_addr, uint16_t* txdesc_high_addr)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_TXDESC_ADDR_MASK_ADDR);

	*use_txdesc_high_addr = (localVal & ((uint32_t)0x00010000)) >>  16;
	*txdesc_high_addr = (localVal & ((uint32_t)0x00003FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_3_txdesc_addr_mask_use_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_TXDESC_ADDR_MASK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void bap_bap_user_3_txdesc_addr_mask_use_txdesc_high_addr_setf(uint8_t usetxdeschighaddr)
{
	ASSERT_ERR((((uint32_t)usetxdeschighaddr << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_3_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)usetxdeschighaddr <<16));
}
__INLINE uint16_t bap_bap_user_3_txdesc_addr_mask_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_3_TXDESC_ADDR_MASK_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00003FFF)) >> 0);
}
__INLINE void bap_bap_user_3_txdesc_addr_mask_txdesc_high_addr_setf(uint16_t txdeschighaddr)
{
	ASSERT_ERR((((uint32_t)txdeschighaddr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_3_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_3_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)txdeschighaddr <<0));
}

/**
 * @brief BAP_USER_4_TXDESC_ADDR_MASK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    USE_TXDESC_HIGH_ADDR      0              
 *    13:00 TXDESC_HIGH_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_USER_4_TXDESC_ADDR_MASK_ADDR        (REG_BAP_BASE_ADDR+0x00000270)
#define BAP_BAP_USER_4_TXDESC_ADDR_MASK_OFFSET      0x00000270
#define BAP_BAP_USER_4_TXDESC_ADDR_MASK_INDEX       0x0000009C
#define BAP_BAP_USER_4_TXDESC_ADDR_MASK_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_4_txdesc_addr_mask_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_4_TXDESC_ADDR_MASK_ADDR);
}

__INLINE void bap_bap_user_4_txdesc_addr_mask_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_4_TXDESC_ADDR_MASK_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_4_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_BIT    ((uint32_t)0x00010000)
#define BAP_BAP_USER_4_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_POS    16
#define BAP_BAP_USER_4_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_MASK    ((uint32_t)0x00003FFF)
#define BAP_BAP_USER_4_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_LSB    0
#define BAP_BAP_USER_4_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_WIDTH    ((uint32_t)0x0000000E)

#define BAP_BAP_USER_4_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_RST    0x0
#define BAP_BAP_USER_4_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_RST    0x0

__INLINE void bap_bap_user_4_txdesc_addr_mask_pack(uint8_t use_txdesc_high_addr, uint16_t txdesc_high_addr)
{
	ASSERT_ERR((((uint32_t)use_txdesc_high_addr << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)txdesc_high_addr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_TXDESC_ADDR_MASK_ADDR,  ((uint32_t)use_txdesc_high_addr << 16) |((uint32_t)txdesc_high_addr << 0));
}

__INLINE void bap_bap_user_4_txdesc_addr_mask_unpack(uint8_t* use_txdesc_high_addr, uint16_t* txdesc_high_addr)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_TXDESC_ADDR_MASK_ADDR);

	*use_txdesc_high_addr = (localVal & ((uint32_t)0x00010000)) >>  16;
	*txdesc_high_addr = (localVal & ((uint32_t)0x00003FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_4_txdesc_addr_mask_use_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_TXDESC_ADDR_MASK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void bap_bap_user_4_txdesc_addr_mask_use_txdesc_high_addr_setf(uint8_t usetxdeschighaddr)
{
	ASSERT_ERR((((uint32_t)usetxdeschighaddr << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_4_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)usetxdeschighaddr <<16));
}
__INLINE uint16_t bap_bap_user_4_txdesc_addr_mask_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_4_TXDESC_ADDR_MASK_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00003FFF)) >> 0);
}
__INLINE void bap_bap_user_4_txdesc_addr_mask_txdesc_high_addr_setf(uint16_t txdeschighaddr)
{
	ASSERT_ERR((((uint32_t)txdeschighaddr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_4_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_4_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)txdeschighaddr <<0));
}

/**
 * @brief BAP_USER_5_TXDESC_ADDR_MASK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    USE_TXDESC_HIGH_ADDR      0              
 *    13:00 TXDESC_HIGH_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_USER_5_TXDESC_ADDR_MASK_ADDR        (REG_BAP_BASE_ADDR+0x00000274)
#define BAP_BAP_USER_5_TXDESC_ADDR_MASK_OFFSET      0x00000274
#define BAP_BAP_USER_5_TXDESC_ADDR_MASK_INDEX       0x0000009D
#define BAP_BAP_USER_5_TXDESC_ADDR_MASK_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_5_txdesc_addr_mask_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_5_TXDESC_ADDR_MASK_ADDR);
}

__INLINE void bap_bap_user_5_txdesc_addr_mask_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_5_TXDESC_ADDR_MASK_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_5_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_BIT    ((uint32_t)0x00010000)
#define BAP_BAP_USER_5_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_POS    16
#define BAP_BAP_USER_5_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_MASK    ((uint32_t)0x00003FFF)
#define BAP_BAP_USER_5_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_LSB    0
#define BAP_BAP_USER_5_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_WIDTH    ((uint32_t)0x0000000E)

#define BAP_BAP_USER_5_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_RST    0x0
#define BAP_BAP_USER_5_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_RST    0x0

__INLINE void bap_bap_user_5_txdesc_addr_mask_pack(uint8_t use_txdesc_high_addr, uint16_t txdesc_high_addr)
{
	ASSERT_ERR((((uint32_t)use_txdesc_high_addr << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)txdesc_high_addr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_TXDESC_ADDR_MASK_ADDR,  ((uint32_t)use_txdesc_high_addr << 16) |((uint32_t)txdesc_high_addr << 0));
}

__INLINE void bap_bap_user_5_txdesc_addr_mask_unpack(uint8_t* use_txdesc_high_addr, uint16_t* txdesc_high_addr)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_TXDESC_ADDR_MASK_ADDR);

	*use_txdesc_high_addr = (localVal & ((uint32_t)0x00010000)) >>  16;
	*txdesc_high_addr = (localVal & ((uint32_t)0x00003FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_5_txdesc_addr_mask_use_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_TXDESC_ADDR_MASK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void bap_bap_user_5_txdesc_addr_mask_use_txdesc_high_addr_setf(uint8_t usetxdeschighaddr)
{
	ASSERT_ERR((((uint32_t)usetxdeschighaddr << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_5_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)usetxdeschighaddr <<16));
}
__INLINE uint16_t bap_bap_user_5_txdesc_addr_mask_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_5_TXDESC_ADDR_MASK_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00003FFF)) >> 0);
}
__INLINE void bap_bap_user_5_txdesc_addr_mask_txdesc_high_addr_setf(uint16_t txdeschighaddr)
{
	ASSERT_ERR((((uint32_t)txdeschighaddr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_5_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_5_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)txdeschighaddr <<0));
}

/**
 * @brief BAP_USER_6_TXDESC_ADDR_MASK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    USE_TXDESC_HIGH_ADDR      0              
 *    13:00 TXDESC_HIGH_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_USER_6_TXDESC_ADDR_MASK_ADDR        (REG_BAP_BASE_ADDR+0x00000278)
#define BAP_BAP_USER_6_TXDESC_ADDR_MASK_OFFSET      0x00000278
#define BAP_BAP_USER_6_TXDESC_ADDR_MASK_INDEX       0x0000009E
#define BAP_BAP_USER_6_TXDESC_ADDR_MASK_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_6_txdesc_addr_mask_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_6_TXDESC_ADDR_MASK_ADDR);
}

__INLINE void bap_bap_user_6_txdesc_addr_mask_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_6_TXDESC_ADDR_MASK_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_6_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_BIT    ((uint32_t)0x00010000)
#define BAP_BAP_USER_6_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_POS    16
#define BAP_BAP_USER_6_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_MASK    ((uint32_t)0x00003FFF)
#define BAP_BAP_USER_6_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_LSB    0
#define BAP_BAP_USER_6_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_WIDTH    ((uint32_t)0x0000000E)

#define BAP_BAP_USER_6_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_RST    0x0
#define BAP_BAP_USER_6_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_RST    0x0

__INLINE void bap_bap_user_6_txdesc_addr_mask_pack(uint8_t use_txdesc_high_addr, uint16_t txdesc_high_addr)
{
	ASSERT_ERR((((uint32_t)use_txdesc_high_addr << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)txdesc_high_addr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_TXDESC_ADDR_MASK_ADDR,  ((uint32_t)use_txdesc_high_addr << 16) |((uint32_t)txdesc_high_addr << 0));
}

__INLINE void bap_bap_user_6_txdesc_addr_mask_unpack(uint8_t* use_txdesc_high_addr, uint16_t* txdesc_high_addr)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_TXDESC_ADDR_MASK_ADDR);

	*use_txdesc_high_addr = (localVal & ((uint32_t)0x00010000)) >>  16;
	*txdesc_high_addr = (localVal & ((uint32_t)0x00003FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_6_txdesc_addr_mask_use_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_TXDESC_ADDR_MASK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void bap_bap_user_6_txdesc_addr_mask_use_txdesc_high_addr_setf(uint8_t usetxdeschighaddr)
{
	ASSERT_ERR((((uint32_t)usetxdeschighaddr << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_6_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)usetxdeschighaddr <<16));
}
__INLINE uint16_t bap_bap_user_6_txdesc_addr_mask_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_6_TXDESC_ADDR_MASK_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00003FFF)) >> 0);
}
__INLINE void bap_bap_user_6_txdesc_addr_mask_txdesc_high_addr_setf(uint16_t txdeschighaddr)
{
	ASSERT_ERR((((uint32_t)txdeschighaddr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_6_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_6_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)txdeschighaddr <<0));
}

/**
 * @brief BAP_USER_7_TXDESC_ADDR_MASK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    USE_TXDESC_HIGH_ADDR      0              
 *    13:00 TXDESC_HIGH_ADDR          0x0
 * </pre>
 */
#define BAP_BAP_USER_7_TXDESC_ADDR_MASK_ADDR        (REG_BAP_BASE_ADDR+0x0000027C)
#define BAP_BAP_USER_7_TXDESC_ADDR_MASK_OFFSET      0x0000027C
#define BAP_BAP_USER_7_TXDESC_ADDR_MASK_INDEX       0x0000009F
#define BAP_BAP_USER_7_TXDESC_ADDR_MASK_RESET       0x00000000

__INLINE uint32_t  bap_bap_user_7_txdesc_addr_mask_get(void)
{
	return REG_PL_RD(BAP_BAP_USER_7_TXDESC_ADDR_MASK_ADDR);
}

__INLINE void bap_bap_user_7_txdesc_addr_mask_set(uint32_t value)
{
	REG_PL_WR(BAP_BAP_USER_7_TXDESC_ADDR_MASK_ADDR, value);
}

// field definitions
#define BAP_BAP_USER_7_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_BIT    ((uint32_t)0x00010000)
#define BAP_BAP_USER_7_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_POS    16
#define BAP_BAP_USER_7_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_MASK    ((uint32_t)0x00003FFF)
#define BAP_BAP_USER_7_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_LSB    0
#define BAP_BAP_USER_7_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_WIDTH    ((uint32_t)0x0000000E)

#define BAP_BAP_USER_7_TXDESC_ADDR_MASK_USE_TXDESC_HIGH_ADDR_RST    0x0
#define BAP_BAP_USER_7_TXDESC_ADDR_MASK_TXDESC_HIGH_ADDR_RST    0x0

__INLINE void bap_bap_user_7_txdesc_addr_mask_pack(uint8_t use_txdesc_high_addr, uint16_t txdesc_high_addr)
{
	ASSERT_ERR((((uint32_t)use_txdesc_high_addr << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)txdesc_high_addr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_TXDESC_ADDR_MASK_ADDR,  ((uint32_t)use_txdesc_high_addr << 16) |((uint32_t)txdesc_high_addr << 0));
}

__INLINE void bap_bap_user_7_txdesc_addr_mask_unpack(uint8_t* use_txdesc_high_addr, uint16_t* txdesc_high_addr)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_TXDESC_ADDR_MASK_ADDR);

	*use_txdesc_high_addr = (localVal & ((uint32_t)0x00010000)) >>  16;
	*txdesc_high_addr = (localVal & ((uint32_t)0x00003FFF)) >>  0;
}

__INLINE uint8_t bap_bap_user_7_txdesc_addr_mask_use_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_TXDESC_ADDR_MASK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void bap_bap_user_7_txdesc_addr_mask_use_txdesc_high_addr_setf(uint8_t usetxdeschighaddr)
{
	ASSERT_ERR((((uint32_t)usetxdeschighaddr << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_7_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)usetxdeschighaddr <<16));
}
__INLINE uint16_t bap_bap_user_7_txdesc_addr_mask_txdesc_high_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(BAP_BAP_USER_7_TXDESC_ADDR_MASK_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00003FFF)) >> 0);
}
__INLINE void bap_bap_user_7_txdesc_addr_mask_txdesc_high_addr_setf(uint16_t txdeschighaddr)
{
	ASSERT_ERR((((uint32_t)txdeschighaddr << 0) & ~((uint32_t)0x00003FFF)) == 0);
	REG_PL_WR(BAP_BAP_USER_7_TXDESC_ADDR_MASK_ADDR, (REG_PL_RD(BAP_BAP_USER_7_TXDESC_ADDR_MASK_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)txdeschighaddr <<0));
}


#undef DBG_FILEID
#endif //_REG_BAP_H_
