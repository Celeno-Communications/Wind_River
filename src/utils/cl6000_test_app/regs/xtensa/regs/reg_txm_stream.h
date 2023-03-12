#ifndef _REG_TXM_STREAM_H_
#define _REG_TXM_STREAM_H_

#include <stdint.h>
#include "_reg_txm_stream.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_TXM_STREAM__H__FILEID__

#define CE_TXM_STREAM_ADDR_OFFSET(_i)  (_i << 8 )

#define REG_TXM_STREAM_COUNT  49


/**
 * @brief TXM_STR_TXD_INFO register definition
 *  Stream TXD size info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:04 TXD_SIZE                  0x0
 *    03:00 TXD_MSDU_MAX_NUM          0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_TXD_INFO_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000000)
#define TXM_STREAM_TXM_STR_TXD_INFO_OFFSET      0x00000000
#define TXM_STREAM_TXM_STR_TXD_INFO_INDEX       0x00000000
#define TXM_STREAM_TXM_STR_TXD_INFO_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_txd_info_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_txd_info_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_TXD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_TXD_INFO_TXD_SIZE_MASK    ((uint32_t)0x00000FF0)
#define TXM_STREAM_TXM_STR_TXD_INFO_TXD_SIZE_LSB    4
#define TXM_STREAM_TXM_STR_TXD_INFO_TXD_SIZE_WIDTH    ((uint32_t)0x00000008)
#define TXM_STREAM_TXM_STR_TXD_INFO_TXD_MSDU_MAX_NUM_MASK    ((uint32_t)0x0000000F)
#define TXM_STREAM_TXM_STR_TXD_INFO_TXD_MSDU_MAX_NUM_LSB    0
#define TXM_STREAM_TXM_STR_TXD_INFO_TXD_MSDU_MAX_NUM_WIDTH    ((uint32_t)0x00000004)

#define TXM_STREAM_TXM_STR_TXD_INFO_TXD_SIZE_RST    0x0
#define TXM_STREAM_TXM_STR_TXD_INFO_TXD_MSDU_MAX_NUM_RST    0x0

__INLINE void txm_stream_txm_str_txd_info_pack(uint8_t txd_size, uint8_t txd_msdu_max_num, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)txd_size << 4) & ~((uint32_t)0x00000FF0)) == 0);
	ASSERT_ERR((((uint32_t)txd_msdu_max_num << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_TXD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)),  ((uint32_t)txd_size << 4) |((uint32_t)txd_msdu_max_num << 0));
}

__INLINE void txm_stream_txm_str_txd_info_unpack(uint8_t* txd_size, uint8_t* txd_msdu_max_num, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*txd_size = (localVal & ((uint32_t)0x00000FF0)) >>  4;
	*txd_msdu_max_num = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t txm_stream_txm_str_txd_info_txd_size_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000FF0)) >> 4);
}
__INLINE void txm_stream_txm_str_txd_info_txd_size_setf(uint8_t txdsize,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)txdsize << 4) & ~((uint32_t)0x00000FF0)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_TXD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_TXD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000FF0)) | ((uint32_t)txdsize <<4));
}
__INLINE uint8_t txm_stream_txm_str_txd_info_txd_msdu_max_num_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void txm_stream_txm_str_txd_info_txd_msdu_max_num_setf(uint8_t txdmsdumaxnum,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)txdmsdumaxnum << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_TXD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_TXD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x0000000F)) | ((uint32_t)txdmsdumaxnum <<0));
}

/**
 * @brief TXM_STR_TXD_BASE_PTR register definition
 *  Stream TXD ring base address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXD_BASE_PTR              0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_TXD_BASE_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000004)
#define TXM_STREAM_TXM_STR_TXD_BASE_PTR_OFFSET      0x00000004
#define TXM_STREAM_TXM_STR_TXD_BASE_PTR_INDEX       0x00000001
#define TXM_STREAM_TXM_STR_TXD_BASE_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_txd_base_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_BASE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_txd_base_ptr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_TXD_BASE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_TXD_BASE_PTR_TXD_BASE_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_TXD_BASE_PTR_TXD_BASE_PTR_LSB    0
#define TXM_STREAM_TXM_STR_TXD_BASE_PTR_TXD_BASE_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_TXD_BASE_PTR_TXD_BASE_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_txd_base_ptr_txd_base_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_BASE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_txd_base_ptr_txd_base_ptr_setf(uint32_t txdbaseptr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)txdbaseptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_TXD_BASE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)txdbaseptr << 0);
}

/**
 * @brief TXM_STR_TXD_WRAP_PTR register definition
 *  Stream TXD ring wrap address  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXD_WRAP_PTR              0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_TXD_WRAP_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000008)
#define TXM_STREAM_TXM_STR_TXD_WRAP_PTR_OFFSET      0x00000008
#define TXM_STREAM_TXM_STR_TXD_WRAP_PTR_INDEX       0x00000002
#define TXM_STREAM_TXM_STR_TXD_WRAP_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_txd_wrap_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_WRAP_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_txd_wrap_ptr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_TXD_WRAP_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_TXD_WRAP_PTR_TXD_WRAP_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_TXD_WRAP_PTR_TXD_WRAP_PTR_LSB    0
#define TXM_STREAM_TXM_STR_TXD_WRAP_PTR_TXD_WRAP_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_TXD_WRAP_PTR_TXD_WRAP_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_txd_wrap_ptr_txd_wrap_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_WRAP_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_txd_wrap_ptr_txd_wrap_ptr_setf(uint32_t txdwrapptr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)txdwrapptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_TXD_WRAP_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)txdwrapptr << 0);
}

/**
 * @brief TXM_STR_TXD_START_PTR register definition
 *  Stream TXD start fill pointer register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXD_START_PTR             0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_TXD_START_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000010)
#define TXM_STREAM_TXM_STR_TXD_START_PTR_OFFSET      0x00000010
#define TXM_STREAM_TXM_STR_TXD_START_PTR_INDEX       0x00000004
#define TXM_STREAM_TXM_STR_TXD_START_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_txd_start_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_START_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_txd_start_ptr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_TXD_START_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_TXD_START_PTR_TXD_START_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_TXD_START_PTR_TXD_START_PTR_LSB    0
#define TXM_STREAM_TXM_STR_TXD_START_PTR_TXD_START_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_TXD_START_PTR_TXD_START_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_txd_start_ptr_txd_start_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_START_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_txd_start_ptr_txd_start_ptr_setf(uint32_t txdstartptr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)txdstartptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_TXD_START_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)txdstartptr << 0);
}

/**
 * @brief TXM_STR_TXD_END_PTR register definition
 *  Stream TXD end fill pointer register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXD_END_PTR               0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_TXD_END_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000014)
#define TXM_STREAM_TXM_STR_TXD_END_PTR_OFFSET      0x00000014
#define TXM_STREAM_TXM_STR_TXD_END_PTR_INDEX       0x00000005
#define TXM_STREAM_TXM_STR_TXD_END_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_txd_end_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_END_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_txd_end_ptr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_TXD_END_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_TXD_END_PTR_TXD_END_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_TXD_END_PTR_TXD_END_PTR_LSB    0
#define TXM_STREAM_TXM_STR_TXD_END_PTR_TXD_END_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_TXD_END_PTR_TXD_END_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_txd_end_ptr_txd_end_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_END_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_txd_end_ptr_txd_end_ptr_setf(uint32_t txdendptr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)txdendptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_TXD_END_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)txdendptr << 0);
}

/**
 * @brief TXM_STR_CMD register definition
 *  Stream command register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02:00 CMD                       0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_CMD_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000018)
#define TXM_STREAM_TXM_STR_CMD_OFFSET      0x00000018
#define TXM_STREAM_TXM_STR_CMD_INDEX       0x00000006
#define TXM_STREAM_TXM_STR_CMD_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_cmd_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_CMD_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_cmd_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_CMD_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_CMD_CMD_MASK     ((uint32_t)0x00000007)
#define TXM_STREAM_TXM_STR_CMD_CMD_LSB      0
#define TXM_STREAM_TXM_STR_CMD_CMD_WIDTH    ((uint32_t)0x00000003)

#define TXM_STREAM_TXM_STR_CMD_CMD_RST      0x0

__INLINE uint8_t txm_stream_txm_str_cmd_cmd_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_CMD_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_cmd_cmd_setf(uint8_t cmd, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)cmd << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_CMD_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)cmd << 0);
}

/**
 * @brief TXM_STR_MPDU_NUM register definition
 *  Number of MPDUs in AMPDU register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:00 MPDU_NUM                  0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_MPDU_NUM_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x0000001C)
#define TXM_STREAM_TXM_STR_MPDU_NUM_OFFSET      0x0000001C
#define TXM_STREAM_TXM_STR_MPDU_NUM_INDEX       0x00000007
#define TXM_STREAM_TXM_STR_MPDU_NUM_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_mpdu_num_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_MPDU_NUM_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_mpdu_num_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_MPDU_NUM_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_MPDU_NUM_MPDU_NUM_MASK    ((uint32_t)0x000003FF)
#define TXM_STREAM_TXM_STR_MPDU_NUM_MPDU_NUM_LSB    0
#define TXM_STREAM_TXM_STR_MPDU_NUM_MPDU_NUM_WIDTH    ((uint32_t)0x0000000A)

#define TXM_STREAM_TXM_STR_MPDU_NUM_MPDU_NUM_RST    0x0

__INLINE uint16_t txm_stream_txm_str_mpdu_num_mpdu_num_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_MPDU_NUM_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_mpdu_num_mpdu_num_setf(uint16_t mpdunum, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)mpdunum << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_MPDU_NUM_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)mpdunum << 0);
}

/**
 * @brief TXM_STR_PRF_BUFF_LIMIT register definition
 *  Prefetch buffer limit register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:08 MAX_BYTE_COUNT_FILL       0x2000
 *    07:00 MAX_MPDU_FILL             0x10
 * </pre>
 */
#define TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000030)
#define TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_OFFSET      0x00000030
#define TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_INDEX       0x0000000C
#define TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_RESET       0x00200010

__INLINE uint32_t  txm_stream_txm_str_prf_buff_limit_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_prf_buff_limit_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_MAX_BYTE_COUNT_FILL_MASK    ((uint32_t)0x00FFFF00)
#define TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_MAX_BYTE_COUNT_FILL_LSB    8
#define TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_MAX_BYTE_COUNT_FILL_WIDTH    ((uint32_t)0x00000010)
#define TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_MAX_MPDU_FILL_MASK    ((uint32_t)0x000000FF)
#define TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_MAX_MPDU_FILL_LSB    0
#define TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_MAX_MPDU_FILL_WIDTH    ((uint32_t)0x00000008)

#define TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_MAX_BYTE_COUNT_FILL_RST    0x2000
#define TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_MAX_MPDU_FILL_RST    0x10

__INLINE void txm_stream_txm_str_prf_buff_limit_pack(uint16_t max_byte_count_fill, uint8_t max_mpdu_fill, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)max_byte_count_fill << 8) & ~((uint32_t)0x00FFFF00)) == 0);
	ASSERT_ERR((((uint32_t)max_mpdu_fill << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)),  ((uint32_t)max_byte_count_fill << 8) |((uint32_t)max_mpdu_fill << 0));
}

__INLINE void txm_stream_txm_str_prf_buff_limit_unpack(uint16_t* max_byte_count_fill, uint8_t* max_mpdu_fill, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*max_byte_count_fill = (localVal & ((uint32_t)0x00FFFF00)) >>  8;
	*max_mpdu_fill = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint16_t txm_stream_txm_str_prf_buff_limit_max_byte_count_fill_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)((localVal & ((uint32_t)0x00FFFF00)) >> 8);
}
__INLINE void txm_stream_txm_str_prf_buff_limit_max_byte_count_fill_setf(uint16_t maxbytecountfill,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)maxbytecountfill << 8) & ~((uint32_t)0x00FFFF00)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00FFFF00)) | ((uint32_t)maxbytecountfill <<8));
}
__INLINE uint8_t txm_stream_txm_str_prf_buff_limit_max_mpdu_fill_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void txm_stream_txm_str_prf_buff_limit_max_mpdu_fill_setf(uint8_t maxmpdufill,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)maxmpdufill << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_PRF_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x000000FF)) | ((uint32_t)maxmpdufill <<0));
}

/**
 * @brief TXM_STR_ACTIVE_BUFF_LIMIT register definition
 *  Active buffer limit register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 QUEUE_BALANCE_TH_BYTES    0x4000
 * </pre>
 */
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_LIMIT_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000034)
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_LIMIT_OFFSET      0x00000034
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_LIMIT_INDEX       0x0000000D
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_LIMIT_RESET       0x00004000

__INLINE uint32_t  txm_stream_txm_str_active_buff_limit_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ACTIVE_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_active_buff_limit_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_ACTIVE_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_LIMIT_QUEUE_BALANCE_TH_BYTES_MASK    ((uint32_t)0x0000FFFF)
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_LIMIT_QUEUE_BALANCE_TH_BYTES_LSB    0
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_LIMIT_QUEUE_BALANCE_TH_BYTES_WIDTH    ((uint32_t)0x00000010)

#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_LIMIT_QUEUE_BALANCE_TH_BYTES_RST    0x4000

__INLINE uint16_t txm_stream_txm_str_active_buff_limit_queue_balance_th_bytes_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ACTIVE_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_active_buff_limit_queue_balance_th_bytes_setf(uint16_t queuebalancethbytes, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)queuebalancethbytes << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_ACTIVE_BUFF_LIMIT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)queuebalancethbytes << 0);
}

/**
 * @brief TXM_STR_PRF_BUFF_SIZE register definition
 *  Prefetch TX buffer size register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 PREFETCH_BUFF_SIZE        0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_PRF_BUFF_SIZE_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000038)
#define TXM_STREAM_TXM_STR_PRF_BUFF_SIZE_OFFSET      0x00000038
#define TXM_STREAM_TXM_STR_PRF_BUFF_SIZE_INDEX       0x0000000E
#define TXM_STREAM_TXM_STR_PRF_BUFF_SIZE_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_prf_buff_size_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRF_BUFF_SIZE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_prf_buff_size_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_PRF_BUFF_SIZE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_PRF_BUFF_SIZE_PREFETCH_BUFF_SIZE_MASK    ((uint32_t)0x0000FFFF)
#define TXM_STREAM_TXM_STR_PRF_BUFF_SIZE_PREFETCH_BUFF_SIZE_LSB    0
#define TXM_STREAM_TXM_STR_PRF_BUFF_SIZE_PREFETCH_BUFF_SIZE_WIDTH    ((uint32_t)0x00000010)

#define TXM_STREAM_TXM_STR_PRF_BUFF_SIZE_PREFETCH_BUFF_SIZE_RST    0x0

__INLINE uint16_t txm_stream_txm_str_prf_buff_size_prefetch_buff_size_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRF_BUFF_SIZE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_prf_buff_size_prefetch_buff_size_setf(uint16_t prefetchbuffsize, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)prefetchbuffsize << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_PRF_BUFF_SIZE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)prefetchbuffsize << 0);
}

/**
 * @brief TXM_STR_PRF_BUFF_BASE_PTR register definition
 *  Base starting address of pre-fetch TX buffer register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PREFETCH_BUFF_BASE_PTR    0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_PRF_BUFF_BASE_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x0000003C)
#define TXM_STREAM_TXM_STR_PRF_BUFF_BASE_PTR_OFFSET      0x0000003C
#define TXM_STREAM_TXM_STR_PRF_BUFF_BASE_PTR_INDEX       0x0000000F
#define TXM_STREAM_TXM_STR_PRF_BUFF_BASE_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_prf_buff_base_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRF_BUFF_BASE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_prf_buff_base_ptr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_PRF_BUFF_BASE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_PRF_BUFF_BASE_PTR_PREFETCH_BUFF_BASE_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_PRF_BUFF_BASE_PTR_PREFETCH_BUFF_BASE_PTR_LSB    0
#define TXM_STREAM_TXM_STR_PRF_BUFF_BASE_PTR_PREFETCH_BUFF_BASE_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_PRF_BUFF_BASE_PTR_PREFETCH_BUFF_BASE_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_prf_buff_base_ptr_prefetch_buff_base_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRF_BUFF_BASE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_prf_buff_base_ptr_prefetch_buff_base_ptr_setf(uint32_t prefetchbuffbaseptr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)prefetchbuffbaseptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_PRF_BUFF_BASE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)prefetchbuffbaseptr << 0);
}

/**
 * @brief TXM_STR_ACTIVE_BUFF_SIZE register definition
 *  Active TX buffer size register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 ACTIVE_BUFF_SIZE          0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_SIZE_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000040)
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_SIZE_OFFSET      0x00000040
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_SIZE_INDEX       0x00000010
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_SIZE_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_active_buff_size_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ACTIVE_BUFF_SIZE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_active_buff_size_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_ACTIVE_BUFF_SIZE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_SIZE_ACTIVE_BUFF_SIZE_MASK    ((uint32_t)0x0000FFFF)
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_SIZE_ACTIVE_BUFF_SIZE_LSB    0
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_SIZE_ACTIVE_BUFF_SIZE_WIDTH    ((uint32_t)0x00000010)

#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_SIZE_ACTIVE_BUFF_SIZE_RST    0x0

__INLINE uint16_t txm_stream_txm_str_active_buff_size_active_buff_size_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ACTIVE_BUFF_SIZE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_active_buff_size_active_buff_size_setf(uint16_t activebuffsize, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)activebuffsize << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_ACTIVE_BUFF_SIZE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)activebuffsize << 0);
}

/**
 * @brief TXM_STR_ACTIVE_BUFF_BASE_PTR register definition
 *  Base starting address of active TX buffer register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ACTIVE_BUFF_BASE_PTR      0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_BASE_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000044)
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_BASE_PTR_OFFSET      0x00000044
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_BASE_PTR_INDEX       0x00000011
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_BASE_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_active_buff_base_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ACTIVE_BUFF_BASE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_active_buff_base_ptr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_ACTIVE_BUFF_BASE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_BASE_PTR_ACTIVE_BUFF_BASE_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_BASE_PTR_ACTIVE_BUFF_BASE_PTR_LSB    0
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_BASE_PTR_ACTIVE_BUFF_BASE_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_BASE_PTR_ACTIVE_BUFF_BASE_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_active_buff_base_ptr_active_buff_base_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ACTIVE_BUFF_BASE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_active_buff_base_ptr_active_buff_base_ptr_setf(uint32_t activebuffbaseptr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)activebuffbaseptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_ACTIVE_BUFF_BASE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)activebuffbaseptr << 0);
}

/**
 * @brief TXM_STR_ACTIVE_BUFF_INFO register definition
 *  Active buffer info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    ACTIVE_BUFF_INCLUDE       0              
 *    00    ACTIVE_BUFF_CYCLIC        0              
 * </pre>
 */
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000048)
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_OFFSET      0x00000048
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_INDEX       0x00000012
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_active_buff_info_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_active_buff_info_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ACTIVE_BUFF_INCLUDE_BIT    ((uint32_t)0x00000002)
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ACTIVE_BUFF_INCLUDE_POS    1
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ACTIVE_BUFF_CYCLIC_BIT    ((uint32_t)0x00000001)
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ACTIVE_BUFF_CYCLIC_POS    0

#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ACTIVE_BUFF_INCLUDE_RST    0x0
#define TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ACTIVE_BUFF_CYCLIC_RST    0x0

__INLINE void txm_stream_txm_str_active_buff_info_pack(uint8_t active_buff_include, uint8_t active_buff_cyclic, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)active_buff_include << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)active_buff_cyclic << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)),  ((uint32_t)active_buff_include << 1) |((uint32_t)active_buff_cyclic << 0));
}

__INLINE void txm_stream_txm_str_active_buff_info_unpack(uint8_t* active_buff_include, uint8_t* active_buff_cyclic, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*active_buff_include = (localVal & ((uint32_t)0x00000002)) >>  1;
	*active_buff_cyclic = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t txm_stream_txm_str_active_buff_info_active_buff_include_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void txm_stream_txm_str_active_buff_info_active_buff_include_setf(uint8_t activebuffinclude,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)activebuffinclude << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000002)) | ((uint32_t)activebuffinclude <<1));
}
__INLINE uint8_t txm_stream_txm_str_active_buff_info_active_buff_cyclic_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void txm_stream_txm_str_active_buff_info_active_buff_cyclic_setf(uint8_t activebuffcyclic,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)activebuffcyclic << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_ACTIVE_BUFF_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000001)) | ((uint32_t)activebuffcyclic <<0));
}

/**
 * @brief TXM_STR_BUFF_START_FILL_PTR register definition
 *  Start fill address of TX buffer register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BUFF_START_FILL_PTR       0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_BUFF_START_FILL_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x0000004C)
#define TXM_STREAM_TXM_STR_BUFF_START_FILL_PTR_OFFSET      0x0000004C
#define TXM_STREAM_TXM_STR_BUFF_START_FILL_PTR_INDEX       0x00000013
#define TXM_STREAM_TXM_STR_BUFF_START_FILL_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_buff_start_fill_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_START_FILL_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_buff_start_fill_ptr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_BUFF_START_FILL_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_BUFF_START_FILL_PTR_BUFF_START_FILL_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_BUFF_START_FILL_PTR_BUFF_START_FILL_PTR_LSB    0
#define TXM_STREAM_TXM_STR_BUFF_START_FILL_PTR_BUFF_START_FILL_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_BUFF_START_FILL_PTR_BUFF_START_FILL_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_buff_start_fill_ptr_buff_start_fill_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_START_FILL_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_buff_start_fill_ptr_buff_start_fill_ptr_setf(uint32_t buffstartfillptr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)buffstartfillptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_BUFF_START_FILL_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)buffstartfillptr << 0);
}

/**
 * @brief TXM_STR_AMPDU_INFO register definition
 *  AMPDU info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08    VLAN_STRIP                0              
 *    07:00 MPDU_TRAILER_SIZE         0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_AMPDU_INFO_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000050)
#define TXM_STREAM_TXM_STR_AMPDU_INFO_OFFSET      0x00000050
#define TXM_STREAM_TXM_STR_AMPDU_INFO_INDEX       0x00000014
#define TXM_STREAM_TXM_STR_AMPDU_INFO_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_ampdu_info_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_AMPDU_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_ampdu_info_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_AMPDU_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_AMPDU_INFO_VLAN_STRIP_BIT    ((uint32_t)0x00000100)
#define TXM_STREAM_TXM_STR_AMPDU_INFO_VLAN_STRIP_POS    8
#define TXM_STREAM_TXM_STR_AMPDU_INFO_MPDU_TRAILER_SIZE_MASK    ((uint32_t)0x000000FF)
#define TXM_STREAM_TXM_STR_AMPDU_INFO_MPDU_TRAILER_SIZE_LSB    0
#define TXM_STREAM_TXM_STR_AMPDU_INFO_MPDU_TRAILER_SIZE_WIDTH    ((uint32_t)0x00000008)

#define TXM_STREAM_TXM_STR_AMPDU_INFO_VLAN_STRIP_RST    0x0
#define TXM_STREAM_TXM_STR_AMPDU_INFO_MPDU_TRAILER_SIZE_RST    0x0

__INLINE void txm_stream_txm_str_ampdu_info_pack(uint8_t vlan_strip, uint8_t mpdu_trailer_size, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)vlan_strip << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)mpdu_trailer_size << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_AMPDU_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)),  ((uint32_t)vlan_strip << 8) |((uint32_t)mpdu_trailer_size << 0));
}

__INLINE void txm_stream_txm_str_ampdu_info_unpack(uint8_t* vlan_strip, uint8_t* mpdu_trailer_size, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_AMPDU_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*vlan_strip = (localVal & ((uint32_t)0x00000100)) >>  8;
	*mpdu_trailer_size = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t txm_stream_txm_str_ampdu_info_vlan_strip_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_AMPDU_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void txm_stream_txm_str_ampdu_info_vlan_strip_setf(uint8_t vlanstrip,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)vlanstrip << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_AMPDU_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_AMPDU_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000100)) | ((uint32_t)vlanstrip <<8));
}
__INLINE uint8_t txm_stream_txm_str_ampdu_info_mpdu_trailer_size_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_AMPDU_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void txm_stream_txm_str_ampdu_info_mpdu_trailer_size_setf(uint8_t mpdutrailersize,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)mpdutrailersize << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_AMPDU_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_AMPDU_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x000000FF)) | ((uint32_t)mpdutrailersize <<0));
}

/**
 * @brief TXM_STR_THD_PHY_CTL_INFO_1 register definition
 *  THD.phy_ctl_info1 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PHY_CTL_INFO1             0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_1_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000070)
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_1_OFFSET      0x00000070
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_1_INDEX       0x0000001C
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_1_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_thd_phy_ctl_info_1_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_1_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_thd_phy_ctl_info_1_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_1_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_1_PHY_CTL_INFO_1_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_1_PHY_CTL_INFO_1_LSB    0
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_1_PHY_CTL_INFO_1_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_1_PHY_CTL_INFO_1_RST    0x0

__INLINE uint32_t txm_stream_txm_str_thd_phy_ctl_info_1_phy_ctl_info_1_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_1_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_thd_phy_ctl_info_1_phy_ctl_info_1_setf(uint32_t phyctlinfo1, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)phyctlinfo1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_1_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)phyctlinfo1 << 0);
}

/**
 * @brief TXM_STR_THD_PHY_CTL_INFO_2 register definition
 *  THD.phy_ctl_info2 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PHY_CTL_INFO2             0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_2_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000074)
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_2_OFFSET      0x00000074
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_2_INDEX       0x0000001D
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_2_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_thd_phy_ctl_info_2_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_2_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_thd_phy_ctl_info_2_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_2_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_2_PHY_CTL_INFO_2_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_2_PHY_CTL_INFO_2_LSB    0
#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_2_PHY_CTL_INFO_2_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_2_PHY_CTL_INFO_2_RST    0x0

__INLINE uint32_t txm_stream_txm_str_thd_phy_ctl_info_2_phy_ctl_info_2_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_2_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_thd_phy_ctl_info_2_phy_ctl_info_2_setf(uint32_t phyctlinfo2, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)phyctlinfo2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_THD_PHY_CTL_INFO_2_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)phyctlinfo2 << 0);
}

/**
 * @brief TXM_STR_THD_BAR_POINTER_ADDR register definition
 *  THD.bar_pointer_addr configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 THD_BAR_POINTER_ADDR      0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_THD_BAR_POINTER_ADDR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000078)
#define TXM_STREAM_TXM_STR_THD_BAR_POINTER_ADDR_OFFSET      0x00000078
#define TXM_STREAM_TXM_STR_THD_BAR_POINTER_ADDR_INDEX       0x0000001E
#define TXM_STREAM_TXM_STR_THD_BAR_POINTER_ADDR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_thd_bar_pointer_addr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_THD_BAR_POINTER_ADDR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_thd_bar_pointer_addr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_THD_BAR_POINTER_ADDR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_THD_BAR_POINTER_ADDR_THD_BAR_POINTER_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_THD_BAR_POINTER_ADDR_THD_BAR_POINTER_ADDR_LSB    0
#define TXM_STREAM_TXM_STR_THD_BAR_POINTER_ADDR_THD_BAR_POINTER_ADDR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_THD_BAR_POINTER_ADDR_THD_BAR_POINTER_ADDR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_thd_bar_pointer_addr_thd_bar_pointer_addr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_THD_BAR_POINTER_ADDR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_thd_bar_pointer_addr_thd_bar_pointer_addr_setf(uint32_t thdbarpointeraddr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)thdbarpointeraddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_THD_BAR_POINTER_ADDR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)thdbarpointeraddr << 0);
}

/**
 * @brief TXM_STR_THD_MAC_CTL_INFO_1 register definition
 *  THD.mac_ctl_info1 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MAC_CTL_INFO1             0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_1_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000080)
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_1_OFFSET      0x00000080
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_1_INDEX       0x00000020
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_1_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_thd_mac_ctl_info_1_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_1_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_thd_mac_ctl_info_1_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_1_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_1_MAC_CTL_INFO_1_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_1_MAC_CTL_INFO_1_LSB    0
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_1_MAC_CTL_INFO_1_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_1_MAC_CTL_INFO_1_RST    0x0

__INLINE uint32_t txm_stream_txm_str_thd_mac_ctl_info_1_mac_ctl_info_1_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_1_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_thd_mac_ctl_info_1_mac_ctl_info_1_setf(uint32_t macctlinfo1, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)macctlinfo1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_1_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)macctlinfo1 << 0);
}

/**
 * @brief TXM_STR_THD_MAC_CTL_INFO_2 register definition
 *  THD.mac_ctl_info2 configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MAC_CTL_INFO2             0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_2_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000084)
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_2_OFFSET      0x00000084
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_2_INDEX       0x00000021
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_2_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_thd_mac_ctl_info_2_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_2_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_thd_mac_ctl_info_2_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_2_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_2_MAC_CTL_INFO_2_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_2_MAC_CTL_INFO_2_LSB    0
#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_2_MAC_CTL_INFO_2_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_2_MAC_CTL_INFO_2_RST    0x0

__INLINE uint32_t txm_stream_txm_str_thd_mac_ctl_info_2_mac_ctl_info_2_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_2_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_thd_mac_ctl_info_2_mac_ctl_info_2_setf(uint32_t macctlinfo2, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)macctlinfo2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_THD_MAC_CTL_INFO_2_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)macctlinfo2 << 0);
}

/**
 * @brief TXM_STR_PCIEW_BASE_ADDR register definition
 *  PCIEW_D<X>_LLI_BASE register address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PCIEW_DX_LLI_BASE_ADDR    0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_PCIEW_BASE_ADDR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000088)
#define TXM_STREAM_TXM_STR_PCIEW_BASE_ADDR_OFFSET      0x00000088
#define TXM_STREAM_TXM_STR_PCIEW_BASE_ADDR_INDEX       0x00000022
#define TXM_STREAM_TXM_STR_PCIEW_BASE_ADDR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_pciew_base_addr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PCIEW_BASE_ADDR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_pciew_base_addr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_PCIEW_BASE_ADDR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_PCIEW_BASE_ADDR_PCIEW_DX_LLI_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_PCIEW_BASE_ADDR_PCIEW_DX_LLI_BASE_ADDR_LSB    0
#define TXM_STREAM_TXM_STR_PCIEW_BASE_ADDR_PCIEW_DX_LLI_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_PCIEW_BASE_ADDR_PCIEW_DX_LLI_BASE_ADDR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_pciew_base_addr_pciew_dx_lli_base_addr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PCIEW_BASE_ADDR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_pciew_base_addr_pciew_dx_lli_base_addr_setf(uint32_t pciewdxllibaseaddr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)pciewdxllibaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_PCIEW_BASE_ADDR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)pciewdxllibaseaddr << 0);
}

/**
 * @brief TXM_STR_LLI_DONE_BYTE_CNT register definition
 *  Stream LLI done int bytes TH register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 LLI_DONE_INT_LLI_BYTE_CNT 0x2000
 *    15:00 LLI_DONE_INT_MPDU_BYTE_CNT 0x2000
 * </pre>
 */
#define TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x0000008C)
#define TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_OFFSET      0x0000008C
#define TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_INDEX       0x00000023
#define TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_RESET       0x20002000

__INLINE uint32_t  txm_stream_txm_str_lli_done_byte_cnt_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_lli_done_byte_cnt_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_LLI_DONE_INT_LLI_BYTE_CNT_MASK    ((uint32_t)0xFFFF0000)
#define TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_LLI_DONE_INT_LLI_BYTE_CNT_LSB    16
#define TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_LLI_DONE_INT_LLI_BYTE_CNT_WIDTH    ((uint32_t)0x00000010)
#define TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_LLI_DONE_INT_MPDU_BYTE_CNT_MASK    ((uint32_t)0x0000FFFF)
#define TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_LLI_DONE_INT_MPDU_BYTE_CNT_LSB    0
#define TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_LLI_DONE_INT_MPDU_BYTE_CNT_WIDTH    ((uint32_t)0x00000010)

#define TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_LLI_DONE_INT_LLI_BYTE_CNT_RST    0x2000
#define TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_LLI_DONE_INT_MPDU_BYTE_CNT_RST    0x2000

__INLINE void txm_stream_txm_str_lli_done_byte_cnt_pack(uint16_t lli_done_int_lli_byte_cnt, uint16_t lli_done_int_mpdu_byte_cnt, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)lli_done_int_lli_byte_cnt << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)lli_done_int_mpdu_byte_cnt << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)),  ((uint32_t)lli_done_int_lli_byte_cnt << 16) |((uint32_t)lli_done_int_mpdu_byte_cnt << 0));
}

__INLINE void txm_stream_txm_str_lli_done_byte_cnt_unpack(uint16_t* lli_done_int_lli_byte_cnt, uint16_t* lli_done_int_mpdu_byte_cnt, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*lli_done_int_lli_byte_cnt = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*lli_done_int_mpdu_byte_cnt = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t txm_stream_txm_str_lli_done_byte_cnt_lli_done_int_lli_byte_cnt_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void txm_stream_txm_str_lli_done_byte_cnt_lli_done_int_lli_byte_cnt_setf(uint16_t llidoneintllibytecnt,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)llidoneintllibytecnt << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)llidoneintllibytecnt <<16));
}
__INLINE uint16_t txm_stream_txm_str_lli_done_byte_cnt_lli_done_int_mpdu_byte_cnt_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void txm_stream_txm_str_lli_done_byte_cnt_lli_done_int_mpdu_byte_cnt_setf(uint16_t llidoneintmpdubytecnt,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)llidoneintmpdubytecnt << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_LLI_DONE_BYTE_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)llidoneintmpdubytecnt <<0));
}

/**
 * @brief TXM_STR_LLI_INFO register definition
 *  LLI info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:30 LLI_CNT_EN_MODE           0x0
 *    29    LLI_SHARED                1              
 *    28:12 SPARE                     0x0
 *    11:08 LLI_CHANNEL_INDEX         0x0
 *    07:00 LLI_DONE_INT_MPDU_CNT     0x10
 * </pre>
 */
#define TXM_STREAM_TXM_STR_LLI_INFO_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000090)
#define TXM_STREAM_TXM_STR_LLI_INFO_OFFSET      0x00000090
#define TXM_STREAM_TXM_STR_LLI_INFO_INDEX       0x00000024
#define TXM_STREAM_TXM_STR_LLI_INFO_RESET       0x20000010

__INLINE uint32_t  txm_stream_txm_str_lli_info_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_lli_info_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_CNT_EN_MODE_MASK    ((uint32_t)0xC0000000)
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_CNT_EN_MODE_LSB    30
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_CNT_EN_MODE_WIDTH    ((uint32_t)0x00000002)
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_SHARED_BIT    ((uint32_t)0x20000000)
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_SHARED_POS    29
#define TXM_STREAM_TXM_STR_LLI_INFO_SPARE_MASK    ((uint32_t)0x1FFFF000)
#define TXM_STREAM_TXM_STR_LLI_INFO_SPARE_LSB    12
#define TXM_STREAM_TXM_STR_LLI_INFO_SPARE_WIDTH    ((uint32_t)0x00000011)
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_CHANNEL_INDEX_MASK    ((uint32_t)0x00000F00)
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_CHANNEL_INDEX_LSB    8
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_CHANNEL_INDEX_WIDTH    ((uint32_t)0x00000004)
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_DONE_INT_MPDU_CNT_MASK    ((uint32_t)0x000000FF)
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_DONE_INT_MPDU_CNT_LSB    0
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_DONE_INT_MPDU_CNT_WIDTH    ((uint32_t)0x00000008)

#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_CNT_EN_MODE_RST    0x0
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_SHARED_RST    0x1
#define TXM_STREAM_TXM_STR_LLI_INFO_SPARE_RST    0x0
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_CHANNEL_INDEX_RST    0x0
#define TXM_STREAM_TXM_STR_LLI_INFO_LLI_DONE_INT_MPDU_CNT_RST    0x10

__INLINE void txm_stream_txm_str_lli_info_pack(uint8_t lli_cnt_en_mode, uint8_t lli_shared, uint32_t spare, uint8_t lli_channel_index, uint8_t lli_done_int_mpdu_cnt, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)lli_cnt_en_mode << 30) & ~((uint32_t)0xC0000000)) == 0);
	ASSERT_ERR((((uint32_t)lli_shared << 29) & ~((uint32_t)0x20000000)) == 0);
	ASSERT_ERR((((uint32_t)spare << 12) & ~((uint32_t)0x1FFFF000)) == 0);
	ASSERT_ERR((((uint32_t)lli_channel_index << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)lli_done_int_mpdu_cnt << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)),  ((uint32_t)lli_cnt_en_mode << 30) |((uint32_t)lli_shared << 29) |((uint32_t)spare << 12) |((uint32_t)lli_channel_index << 8) |((uint32_t)lli_done_int_mpdu_cnt << 0));
}

__INLINE void txm_stream_txm_str_lli_info_unpack(uint8_t* lli_cnt_en_mode, uint8_t* lli_shared, uint32_t* spare, uint8_t* lli_channel_index, uint8_t* lli_done_int_mpdu_cnt, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*lli_cnt_en_mode = (localVal & ((uint32_t)0xC0000000)) >>  30;
	*lli_shared = (localVal & ((uint32_t)0x20000000)) >>  29;
	*spare = (localVal & ((uint32_t)0x1FFFF000)) >>  12;
	*lli_channel_index = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*lli_done_int_mpdu_cnt = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t txm_stream_txm_str_lli_info_lli_cnt_en_mode_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0xC0000000)) >> 30);
}
__INLINE void txm_stream_txm_str_lli_info_lli_cnt_en_mode_setf(uint8_t llicntenmode,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)llicntenmode << 30) & ~((uint32_t)0xC0000000)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0xC0000000)) | ((uint32_t)llicntenmode <<30));
}
__INLINE uint8_t txm_stream_txm_str_lli_info_lli_shared_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE void txm_stream_txm_str_lli_info_lli_shared_setf(uint8_t llishared,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)llishared << 29) & ~((uint32_t)0x20000000)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x20000000)) | ((uint32_t)llishared <<29));
}
__INLINE uint32_t txm_stream_txm_str_lli_info_spare_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)((localVal & ((uint32_t)0x1FFFF000)) >> 12);
}
__INLINE void txm_stream_txm_str_lli_info_spare_setf(uint32_t spare,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)spare << 12) & ~((uint32_t)0x1FFFF000)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x1FFFF000)) | ((uint32_t)spare <<12));
}
__INLINE uint8_t txm_stream_txm_str_lli_info_lli_channel_index_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void txm_stream_txm_str_lli_info_lli_channel_index_setf(uint8_t llichannelindex,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)llichannelindex << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000F00)) | ((uint32_t)llichannelindex <<8));
}
__INLINE uint8_t txm_stream_txm_str_lli_info_lli_done_int_mpdu_cnt_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void txm_stream_txm_str_lli_info_lli_done_int_mpdu_cnt_setf(uint8_t llidoneintmpducnt,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)llidoneintmpducnt << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x000000FF)) | ((uint32_t)llidoneintmpducnt <<0));
}

/**
 * @brief TXM_STR_MACHW_MAPPING register definition
 *  Stream to MACHW interrupt mapping register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    MACHW_ACTIVE              0              
 *    30:04 SPARE                     0x0
 *    03:00 MACHW_INDEX               0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000094)
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_OFFSET      0x00000094
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_INDEX       0x00000025
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_machw_mapping_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_machw_mapping_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_MACHW_ACTIVE_BIT    ((uint32_t)0x80000000)
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_MACHW_ACTIVE_POS    31
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_SPARE_MASK    ((uint32_t)0x7FFFFFF0)
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_SPARE_LSB    4
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_SPARE_WIDTH    ((uint32_t)0x0000001B)
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_MACHW_INDEX_MASK    ((uint32_t)0x0000000F)
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_MACHW_INDEX_LSB    0
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_MACHW_INDEX_WIDTH    ((uint32_t)0x00000004)

#define TXM_STREAM_TXM_STR_MACHW_MAPPING_MACHW_ACTIVE_RST    0x0
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_SPARE_RST    0x0
#define TXM_STREAM_TXM_STR_MACHW_MAPPING_MACHW_INDEX_RST    0x0

__INLINE void txm_stream_txm_str_machw_mapping_pack(uint8_t machw_active, uint32_t spare, uint8_t machw_index, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)machw_active << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)spare << 4) & ~((uint32_t)0x7FFFFFF0)) == 0);
	ASSERT_ERR((((uint32_t)machw_index << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)),  ((uint32_t)machw_active << 31) |((uint32_t)spare << 4) |((uint32_t)machw_index << 0));
}

__INLINE void txm_stream_txm_str_machw_mapping_unpack(uint8_t* machw_active, uint32_t* spare, uint8_t* machw_index, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*machw_active = (localVal & ((uint32_t)0x80000000)) >>  31;
	*spare = (localVal & ((uint32_t)0x7FFFFFF0)) >>  4;
	*machw_index = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t txm_stream_txm_str_machw_mapping_machw_active_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void txm_stream_txm_str_machw_mapping_machw_active_setf(uint8_t machwactive,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)machwactive << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x80000000)) | ((uint32_t)machwactive <<31));
}
__INLINE uint32_t txm_stream_txm_str_machw_mapping_spare_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)((localVal & ((uint32_t)0x7FFFFFF0)) >> 4);
}
__INLINE void txm_stream_txm_str_machw_mapping_spare_setf(uint32_t spare,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)spare << 4) & ~((uint32_t)0x7FFFFFF0)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x7FFFFFF0)) | ((uint32_t)spare <<4));
}
__INLINE uint8_t txm_stream_txm_str_machw_mapping_machw_index_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void txm_stream_txm_str_machw_mapping_machw_index_setf(uint8_t machwindex,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)machwindex << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_MACHW_MAPPING_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x0000000F)) | ((uint32_t)machwindex <<0));
}

/**
 * @brief TXM_STR_AXI_ERR_ADDR register definition
 *  AXI read address that caused the error register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 AXI_ERR_ADDR              0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_AXI_ERR_ADDR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x00000098)
#define TXM_STREAM_TXM_STR_AXI_ERR_ADDR_OFFSET      0x00000098
#define TXM_STREAM_TXM_STR_AXI_ERR_ADDR_INDEX       0x00000026
#define TXM_STREAM_TXM_STR_AXI_ERR_ADDR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_axi_err_addr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_AXI_ERR_ADDR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_AXI_ERR_ADDR_AXI_ERR_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_AXI_ERR_ADDR_AXI_ERR_ADDR_LSB    0
#define TXM_STREAM_TXM_STR_AXI_ERR_ADDR_AXI_ERR_ADDR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_AXI_ERR_ADDR_AXI_ERR_ADDR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_axi_err_addr_axi_err_addr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_AXI_ERR_ADDR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief TXM_STR_ERR_STAT register definition
 *  Stream error status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    02    FREE_UNDERRUN_ERR         0              
 *    01    AXI_RD_ERR                0              
 *    00    LAST_TXD_NOT_FOUND_ERR    0              
 * </pre>
 */
#define TXM_STREAM_TXM_STR_ERR_STAT_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x0000009C)
#define TXM_STREAM_TXM_STR_ERR_STAT_OFFSET      0x0000009C
#define TXM_STREAM_TXM_STR_ERR_STAT_INDEX       0x00000027
#define TXM_STREAM_TXM_STR_ERR_STAT_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_err_stat_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ERR_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_ERR_STAT_FREE_UNDERRUN_ERR_BIT    ((uint32_t)0x00000004)
#define TXM_STREAM_TXM_STR_ERR_STAT_FREE_UNDERRUN_ERR_POS    2
#define TXM_STREAM_TXM_STR_ERR_STAT_AXI_RD_ERR_BIT    ((uint32_t)0x00000002)
#define TXM_STREAM_TXM_STR_ERR_STAT_AXI_RD_ERR_POS    1
#define TXM_STREAM_TXM_STR_ERR_STAT_LAST_TXD_NOT_FOUND_ERR_BIT    ((uint32_t)0x00000001)
#define TXM_STREAM_TXM_STR_ERR_STAT_LAST_TXD_NOT_FOUND_ERR_POS    0

#define TXM_STREAM_TXM_STR_ERR_STAT_FREE_UNDERRUN_ERR_RST    0x0
#define TXM_STREAM_TXM_STR_ERR_STAT_AXI_RD_ERR_RST    0x0
#define TXM_STREAM_TXM_STR_ERR_STAT_LAST_TXD_NOT_FOUND_ERR_RST    0x0

__INLINE void txm_stream_txm_str_err_stat_unpack(uint8_t* free_underrun_err, uint8_t* axi_rd_err, uint8_t* last_txd_not_found_err, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ERR_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*free_underrun_err = (localVal & ((uint32_t)0x00000004)) >>  2;
	*axi_rd_err = (localVal & ((uint32_t)0x00000002)) >>  1;
	*last_txd_not_found_err = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t txm_stream_txm_str_err_stat_free_underrun_err_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ERR_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t txm_stream_txm_str_err_stat_axi_rd_err_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ERR_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t txm_stream_txm_str_err_stat_last_txd_not_found_err_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_ERR_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief TXM_STR_INT_RAW_STAT register definition
 *  Stream raw interrupt register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    ERR                       0              
 *    04    PRF_BUFF_OVERFLOW         0              
 *    03    THD_DONE                  0              
 *    02    STR_BUFF_FREE             0              
 *    01    STR_INACTIVE              0              
 *    00    TXD_PREFETCH_END          0              
 * </pre>
 */
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000A0)
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_OFFSET      0x000000A0
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_INDEX       0x00000028
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_int_raw_stat_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_RAW_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_ERR_BIT    ((uint32_t)0x00000020)
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_ERR_POS    5
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_PRF_BUFF_OVERFLOW_BIT    ((uint32_t)0x00000010)
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_PRF_BUFF_OVERFLOW_POS    4
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_THD_DONE_BIT    ((uint32_t)0x00000008)
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_THD_DONE_POS    3
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_STR_BUFF_FREE_BIT    ((uint32_t)0x00000004)
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_STR_BUFF_FREE_POS    2
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_STR_INACTIVE_BIT    ((uint32_t)0x00000002)
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_STR_INACTIVE_POS    1
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_TXD_PREFETCH_END_BIT    ((uint32_t)0x00000001)
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_TXD_PREFETCH_END_POS    0

#define TXM_STREAM_TXM_STR_INT_RAW_STAT_ERR_RST    0x0
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_PRF_BUFF_OVERFLOW_RST    0x0
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_THD_DONE_RST    0x0
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_STR_BUFF_FREE_RST    0x0
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_STR_INACTIVE_RST    0x0
#define TXM_STREAM_TXM_STR_INT_RAW_STAT_TXD_PREFETCH_END_RST    0x0

__INLINE void txm_stream_txm_str_int_raw_stat_unpack(uint8_t* err, uint8_t* prf_buff_overflow, uint8_t* thd_done, uint8_t* str_buff_free, uint8_t* str_inactive, uint8_t* txd_prefetch_end, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_RAW_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*err = (localVal & ((uint32_t)0x00000020)) >>  5;
	*prf_buff_overflow = (localVal & ((uint32_t)0x00000010)) >>  4;
	*thd_done = (localVal & ((uint32_t)0x00000008)) >>  3;
	*str_buff_free = (localVal & ((uint32_t)0x00000004)) >>  2;
	*str_inactive = (localVal & ((uint32_t)0x00000002)) >>  1;
	*txd_prefetch_end = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t txm_stream_txm_str_int_raw_stat_err_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_RAW_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t txm_stream_txm_str_int_raw_stat_prf_buff_overflow_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_RAW_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t txm_stream_txm_str_int_raw_stat_thd_done_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_RAW_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t txm_stream_txm_str_int_raw_stat_str_buff_free_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_RAW_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t txm_stream_txm_str_int_raw_stat_str_inactive_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_RAW_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t txm_stream_txm_str_int_raw_stat_txd_prefetch_end_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_RAW_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief TXM_STR_INT_EN register definition
 *  Stream interrupt enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    ERR_EN                    0              
 *    04    PRF_BUFF_OVERFLOW_EN      0              
 *    03    THD_DONE_EN               0              
 *    02    STR_BUFF_FREE_EN          0              
 *    01    STR_INACTIVE_EN           0              
 *    00    TXD_PREFETCH_END_EN       0              
 * </pre>
 */
#define TXM_STREAM_TXM_STR_INT_EN_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000A4)
#define TXM_STREAM_TXM_STR_INT_EN_OFFSET      0x000000A4
#define TXM_STREAM_TXM_STR_INT_EN_INDEX       0x00000029
#define TXM_STREAM_TXM_STR_INT_EN_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_int_en_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_int_en_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_INT_EN_ERR_EN_BIT    ((uint32_t)0x00000020)
#define TXM_STREAM_TXM_STR_INT_EN_ERR_EN_POS    5
#define TXM_STREAM_TXM_STR_INT_EN_PRF_BUFF_OVERFLOW_EN_BIT    ((uint32_t)0x00000010)
#define TXM_STREAM_TXM_STR_INT_EN_PRF_BUFF_OVERFLOW_EN_POS    4
#define TXM_STREAM_TXM_STR_INT_EN_THD_DONE_EN_BIT    ((uint32_t)0x00000008)
#define TXM_STREAM_TXM_STR_INT_EN_THD_DONE_EN_POS    3
#define TXM_STREAM_TXM_STR_INT_EN_STR_BUFF_FREE_EN_BIT    ((uint32_t)0x00000004)
#define TXM_STREAM_TXM_STR_INT_EN_STR_BUFF_FREE_EN_POS    2
#define TXM_STREAM_TXM_STR_INT_EN_STR_INACTIVE_EN_BIT    ((uint32_t)0x00000002)
#define TXM_STREAM_TXM_STR_INT_EN_STR_INACTIVE_EN_POS    1
#define TXM_STREAM_TXM_STR_INT_EN_TXD_PREFETCH_END_EN_BIT    ((uint32_t)0x00000001)
#define TXM_STREAM_TXM_STR_INT_EN_TXD_PREFETCH_END_EN_POS    0

#define TXM_STREAM_TXM_STR_INT_EN_ERR_EN_RST    0x0
#define TXM_STREAM_TXM_STR_INT_EN_PRF_BUFF_OVERFLOW_EN_RST    0x0
#define TXM_STREAM_TXM_STR_INT_EN_THD_DONE_EN_RST    0x0
#define TXM_STREAM_TXM_STR_INT_EN_STR_BUFF_FREE_EN_RST    0x0
#define TXM_STREAM_TXM_STR_INT_EN_STR_INACTIVE_EN_RST    0x0
#define TXM_STREAM_TXM_STR_INT_EN_TXD_PREFETCH_END_EN_RST    0x0

__INLINE void txm_stream_txm_str_int_en_pack(uint8_t err_en, uint8_t prf_buff_overflow_en, uint8_t thd_done_en, uint8_t str_buff_free_en, uint8_t str_inactive_en, uint8_t txd_prefetch_end_en, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)err_en << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)prf_buff_overflow_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)thd_done_en << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)str_buff_free_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)str_inactive_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)txd_prefetch_end_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)),  ((uint32_t)err_en << 5) |((uint32_t)prf_buff_overflow_en << 4) |((uint32_t)thd_done_en << 3) |((uint32_t)str_buff_free_en << 2) |((uint32_t)str_inactive_en << 1) |((uint32_t)txd_prefetch_end_en << 0));
}

__INLINE void txm_stream_txm_str_int_en_unpack(uint8_t* err_en, uint8_t* prf_buff_overflow_en, uint8_t* thd_done_en, uint8_t* str_buff_free_en, uint8_t* str_inactive_en, uint8_t* txd_prefetch_end_en, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*err_en = (localVal & ((uint32_t)0x00000020)) >>  5;
	*prf_buff_overflow_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*thd_done_en = (localVal & ((uint32_t)0x00000008)) >>  3;
	*str_buff_free_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*str_inactive_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*txd_prefetch_end_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t txm_stream_txm_str_int_en_err_en_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void txm_stream_txm_str_int_en_err_en_setf(uint8_t erren,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)erren << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000020)) | ((uint32_t)erren <<5));
}
__INLINE uint8_t txm_stream_txm_str_int_en_prf_buff_overflow_en_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void txm_stream_txm_str_int_en_prf_buff_overflow_en_setf(uint8_t prfbuffoverflowen,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)prfbuffoverflowen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000010)) | ((uint32_t)prfbuffoverflowen <<4));
}
__INLINE uint8_t txm_stream_txm_str_int_en_thd_done_en_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void txm_stream_txm_str_int_en_thd_done_en_setf(uint8_t thddoneen,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)thddoneen << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000008)) | ((uint32_t)thddoneen <<3));
}
__INLINE uint8_t txm_stream_txm_str_int_en_str_buff_free_en_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void txm_stream_txm_str_int_en_str_buff_free_en_setf(uint8_t strbufffreeen,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)strbufffreeen << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000004)) | ((uint32_t)strbufffreeen <<2));
}
__INLINE uint8_t txm_stream_txm_str_int_en_str_inactive_en_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void txm_stream_txm_str_int_en_str_inactive_en_setf(uint8_t strinactiveen,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)strinactiveen << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000002)) | ((uint32_t)strinactiveen <<1));
}
__INLINE uint8_t txm_stream_txm_str_int_en_txd_prefetch_end_en_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void txm_stream_txm_str_int_en_txd_prefetch_end_en_setf(uint8_t txdprefetchenden,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)txdprefetchenden << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_INT_EN_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000001)) | ((uint32_t)txdprefetchenden <<0));
}

/**
 * @brief TXM_STR_INT_STAT register definition
 *  Stream interrupt after enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    ERR                       0              
 *    04    PRF_BUFF_OVERFLOW         0              
 *    03    THD_DONE                  0              
 *    02    STR_BUFF_FREE             0              
 *    01    STR_INACTIVE              0              
 *    00    TXD_PREFETCH_END          0              
 * </pre>
 */
#define TXM_STREAM_TXM_STR_INT_STAT_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000A8)
#define TXM_STREAM_TXM_STR_INT_STAT_OFFSET      0x000000A8
#define TXM_STREAM_TXM_STR_INT_STAT_INDEX       0x0000002A
#define TXM_STREAM_TXM_STR_INT_STAT_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_int_stat_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_INT_STAT_ERR_BIT    ((uint32_t)0x00000020)
#define TXM_STREAM_TXM_STR_INT_STAT_ERR_POS    5
#define TXM_STREAM_TXM_STR_INT_STAT_PRF_BUFF_OVERFLOW_BIT    ((uint32_t)0x00000010)
#define TXM_STREAM_TXM_STR_INT_STAT_PRF_BUFF_OVERFLOW_POS    4
#define TXM_STREAM_TXM_STR_INT_STAT_THD_DONE_BIT    ((uint32_t)0x00000008)
#define TXM_STREAM_TXM_STR_INT_STAT_THD_DONE_POS    3
#define TXM_STREAM_TXM_STR_INT_STAT_STR_BUFF_FREE_BIT    ((uint32_t)0x00000004)
#define TXM_STREAM_TXM_STR_INT_STAT_STR_BUFF_FREE_POS    2
#define TXM_STREAM_TXM_STR_INT_STAT_STR_INACTIVE_BIT    ((uint32_t)0x00000002)
#define TXM_STREAM_TXM_STR_INT_STAT_STR_INACTIVE_POS    1
#define TXM_STREAM_TXM_STR_INT_STAT_TXD_PREFETCH_END_BIT    ((uint32_t)0x00000001)
#define TXM_STREAM_TXM_STR_INT_STAT_TXD_PREFETCH_END_POS    0

#define TXM_STREAM_TXM_STR_INT_STAT_ERR_RST    0x0
#define TXM_STREAM_TXM_STR_INT_STAT_PRF_BUFF_OVERFLOW_RST    0x0
#define TXM_STREAM_TXM_STR_INT_STAT_THD_DONE_RST    0x0
#define TXM_STREAM_TXM_STR_INT_STAT_STR_BUFF_FREE_RST    0x0
#define TXM_STREAM_TXM_STR_INT_STAT_STR_INACTIVE_RST    0x0
#define TXM_STREAM_TXM_STR_INT_STAT_TXD_PREFETCH_END_RST    0x0

__INLINE void txm_stream_txm_str_int_stat_unpack(uint8_t* err, uint8_t* prf_buff_overflow, uint8_t* thd_done, uint8_t* str_buff_free, uint8_t* str_inactive, uint8_t* txd_prefetch_end, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*err = (localVal & ((uint32_t)0x00000020)) >>  5;
	*prf_buff_overflow = (localVal & ((uint32_t)0x00000010)) >>  4;
	*thd_done = (localVal & ((uint32_t)0x00000008)) >>  3;
	*str_buff_free = (localVal & ((uint32_t)0x00000004)) >>  2;
	*str_inactive = (localVal & ((uint32_t)0x00000002)) >>  1;
	*txd_prefetch_end = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t txm_stream_txm_str_int_stat_err_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t txm_stream_txm_str_int_stat_prf_buff_overflow_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t txm_stream_txm_str_int_stat_thd_done_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t txm_stream_txm_str_int_stat_str_buff_free_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t txm_stream_txm_str_int_stat_str_inactive_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t txm_stream_txm_str_int_stat_txd_prefetch_end_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_INT_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief TXM_STR_INT_CLR register definition
 *  Stream interrupt clear register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    ERR_CLR                   0              
 *    04    PRF_BUFF_OVERFLOW_CLR     0              
 *    03    THD_DONE_CLR              0              
 *    02    STR_BUFF_FREE_CLR         0              
 *    01    STR_INACTIVE_CLR          0              
 *    00    TXD_PREFETCH_END_CLR      0              
 * </pre>
 */
#define TXM_STREAM_TXM_STR_INT_CLR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000AC)
#define TXM_STREAM_TXM_STR_INT_CLR_OFFSET      0x000000AC
#define TXM_STREAM_TXM_STR_INT_CLR_INDEX       0x0000002B
#define TXM_STREAM_TXM_STR_INT_CLR_RESET       0x00000000

__INLINE void  txm_stream_txm_str_int_clr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_INT_CLR_ERR_CLR_BIT    ((uint32_t)0x00000020)
#define TXM_STREAM_TXM_STR_INT_CLR_ERR_CLR_POS    5
#define TXM_STREAM_TXM_STR_INT_CLR_PRF_BUFF_OVERFLOW_CLR_BIT    ((uint32_t)0x00000010)
#define TXM_STREAM_TXM_STR_INT_CLR_PRF_BUFF_OVERFLOW_CLR_POS    4
#define TXM_STREAM_TXM_STR_INT_CLR_THD_DONE_CLR_BIT    ((uint32_t)0x00000008)
#define TXM_STREAM_TXM_STR_INT_CLR_THD_DONE_CLR_POS    3
#define TXM_STREAM_TXM_STR_INT_CLR_STR_BUFF_FREE_CLR_BIT    ((uint32_t)0x00000004)
#define TXM_STREAM_TXM_STR_INT_CLR_STR_BUFF_FREE_CLR_POS    2
#define TXM_STREAM_TXM_STR_INT_CLR_STR_INACTIVE_CLR_BIT    ((uint32_t)0x00000002)
#define TXM_STREAM_TXM_STR_INT_CLR_STR_INACTIVE_CLR_POS    1
#define TXM_STREAM_TXM_STR_INT_CLR_TXD_PREFETCH_END_CLR_BIT    ((uint32_t)0x00000001)
#define TXM_STREAM_TXM_STR_INT_CLR_TXD_PREFETCH_END_CLR_POS    0

#define TXM_STREAM_TXM_STR_INT_CLR_ERR_CLR_RST    0x0
#define TXM_STREAM_TXM_STR_INT_CLR_PRF_BUFF_OVERFLOW_CLR_RST    0x0
#define TXM_STREAM_TXM_STR_INT_CLR_THD_DONE_CLR_RST    0x0
#define TXM_STREAM_TXM_STR_INT_CLR_STR_BUFF_FREE_CLR_RST    0x0
#define TXM_STREAM_TXM_STR_INT_CLR_STR_INACTIVE_CLR_RST    0x0
#define TXM_STREAM_TXM_STR_INT_CLR_TXD_PREFETCH_END_CLR_RST    0x0

__INLINE void txm_stream_txm_str_int_clr_pack(uint8_t err_clr, uint8_t prf_buff_overflow_clr, uint8_t thd_done_clr, uint8_t str_buff_free_clr, uint8_t str_inactive_clr, uint8_t txd_prefetch_end_clr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)err_clr << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)prf_buff_overflow_clr << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)thd_done_clr << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)str_buff_free_clr << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)str_inactive_clr << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)txd_prefetch_end_clr << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)),  ((uint32_t)err_clr << 5) |((uint32_t)prf_buff_overflow_clr << 4) |((uint32_t)thd_done_clr << 3) |((uint32_t)str_buff_free_clr << 2) |((uint32_t)str_inactive_clr << 1) |((uint32_t)txd_prefetch_end_clr << 0));
}

__INLINE void txm_stream_txm_str_int_clr_err_clr_setf(uint8_t errclr,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)errclr << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000020)) | ((uint32_t)errclr <<5));
}
__INLINE void txm_stream_txm_str_int_clr_prf_buff_overflow_clr_setf(uint8_t prfbuffoverflowclr,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)prfbuffoverflowclr << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000010)) | ((uint32_t)prfbuffoverflowclr <<4));
}
__INLINE void txm_stream_txm_str_int_clr_thd_done_clr_setf(uint8_t thddoneclr,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)thddoneclr << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000008)) | ((uint32_t)thddoneclr <<3));
}
__INLINE void txm_stream_txm_str_int_clr_str_buff_free_clr_setf(uint8_t strbufffreeclr,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)strbufffreeclr << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000004)) | ((uint32_t)strbufffreeclr <<2));
}
__INLINE void txm_stream_txm_str_int_clr_str_inactive_clr_setf(uint8_t strinactiveclr,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)strinactiveclr << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000002)) | ((uint32_t)strinactiveclr <<1));
}
__INLINE void txm_stream_txm_str_int_clr_txd_prefetch_end_clr_setf(uint8_t txdprefetchendclr,uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)txdprefetchendclr << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (REG_PL_RD(TXM_STREAM_TXM_STR_INT_CLR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)) & ~((uint32_t)0x00000001)) | ((uint32_t)txdprefetchendclr <<0));
}

/**
 * @brief TXM_STR_STATE register definition
 *  Stream debug state machines register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    27:24 FR_STATE                  0x0
 *    20:16 WR_STATE                  0x0
 *    15:12 RD_STATE                  0x0
 *    08:04 SPX_STATE                 0x0
 *    02:00 STR_STATE                 0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_STATE_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000B0)
#define TXM_STREAM_TXM_STR_STATE_OFFSET      0x000000B0
#define TXM_STREAM_TXM_STR_STATE_INDEX       0x0000002C
#define TXM_STREAM_TXM_STR_STATE_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_state_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_STATE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_STATE_FR_STATE_MASK    ((uint32_t)0x0F000000)
#define TXM_STREAM_TXM_STR_STATE_FR_STATE_LSB    24
#define TXM_STREAM_TXM_STR_STATE_FR_STATE_WIDTH    ((uint32_t)0x00000004)
#define TXM_STREAM_TXM_STR_STATE_WR_STATE_MASK    ((uint32_t)0x001F0000)
#define TXM_STREAM_TXM_STR_STATE_WR_STATE_LSB    16
#define TXM_STREAM_TXM_STR_STATE_WR_STATE_WIDTH    ((uint32_t)0x00000005)
#define TXM_STREAM_TXM_STR_STATE_RD_STATE_MASK    ((uint32_t)0x0000F000)
#define TXM_STREAM_TXM_STR_STATE_RD_STATE_LSB    12
#define TXM_STREAM_TXM_STR_STATE_RD_STATE_WIDTH    ((uint32_t)0x00000004)
#define TXM_STREAM_TXM_STR_STATE_SPX_STATE_MASK    ((uint32_t)0x000001F0)
#define TXM_STREAM_TXM_STR_STATE_SPX_STATE_LSB    4
#define TXM_STREAM_TXM_STR_STATE_SPX_STATE_WIDTH    ((uint32_t)0x00000005)
#define TXM_STREAM_TXM_STR_STATE_STR_STATE_MASK    ((uint32_t)0x00000007)
#define TXM_STREAM_TXM_STR_STATE_STR_STATE_LSB    0
#define TXM_STREAM_TXM_STR_STATE_STR_STATE_WIDTH    ((uint32_t)0x00000003)

#define TXM_STREAM_TXM_STR_STATE_FR_STATE_RST    0x0
#define TXM_STREAM_TXM_STR_STATE_WR_STATE_RST    0x0
#define TXM_STREAM_TXM_STR_STATE_RD_STATE_RST    0x0
#define TXM_STREAM_TXM_STR_STATE_SPX_STATE_RST    0x0
#define TXM_STREAM_TXM_STR_STATE_STR_STATE_RST    0x0

__INLINE void txm_stream_txm_str_state_unpack(uint8_t* fr_state, uint8_t* wr_state, uint8_t* rd_state, uint8_t* spx_state, uint8_t* str_state, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_STATE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*fr_state = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*wr_state = (localVal & ((uint32_t)0x001F0000)) >>  16;
	*rd_state = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*spx_state = (localVal & ((uint32_t)0x000001F0)) >>  4;
	*str_state = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t txm_stream_txm_str_state_fr_state_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_STATE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE uint8_t txm_stream_txm_str_state_wr_state_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_STATE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x001F0000)) >> 16);
}
__INLINE uint8_t txm_stream_txm_str_state_rd_state_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_STATE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE uint8_t txm_stream_txm_str_state_spx_state_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_STATE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x000001F0)) >> 4);
}
__INLINE uint8_t txm_stream_txm_str_state_str_state_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_STATE_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief TXM_STR_TXD_CURR_PTR register definition
 *  Stream current TXD pointer register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXD_CURR_PTR              0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_TXD_CURR_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000B4)
#define TXM_STREAM_TXM_STR_TXD_CURR_PTR_OFFSET      0x000000B4
#define TXM_STREAM_TXM_STR_TXD_CURR_PTR_INDEX       0x0000002D
#define TXM_STREAM_TXM_STR_TXD_CURR_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_txd_curr_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_CURR_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_TXD_CURR_PTR_TXD_CURR_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_TXD_CURR_PTR_TXD_CURR_PTR_LSB    0
#define TXM_STREAM_TXM_STR_TXD_CURR_PTR_TXD_CURR_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_TXD_CURR_PTR_TXD_CURR_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_txd_curr_ptr_txd_curr_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_TXD_CURR_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief TXM_STR_PRC_STAT register definition
 *  Stream prefetch status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    PRF_EXCEED                0              
 *    30    PRF_MAX_BYTE_COUNT        0              
 *    29    PRF_MAX_MPDU              0              
 *    28    LAST_MSDU                 0              
 *    27:24 MSDU_CNT                  0x0
 *    23:12 LLI_CNT                   0x0
 *    09:00 MPDU_CNT                  0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_PRC_STAT_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000B8)
#define TXM_STREAM_TXM_STR_PRC_STAT_OFFSET      0x000000B8
#define TXM_STREAM_TXM_STR_PRC_STAT_INDEX       0x0000002E
#define TXM_STREAM_TXM_STR_PRC_STAT_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_prc_stat_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRC_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_PRC_STAT_PRF_EXCEED_BIT    ((uint32_t)0x80000000)
#define TXM_STREAM_TXM_STR_PRC_STAT_PRF_EXCEED_POS    31
#define TXM_STREAM_TXM_STR_PRC_STAT_PRF_MAX_BYTE_COUNT_BIT    ((uint32_t)0x40000000)
#define TXM_STREAM_TXM_STR_PRC_STAT_PRF_MAX_BYTE_COUNT_POS    30
#define TXM_STREAM_TXM_STR_PRC_STAT_PRF_MAX_MPDU_BIT    ((uint32_t)0x20000000)
#define TXM_STREAM_TXM_STR_PRC_STAT_PRF_MAX_MPDU_POS    29
#define TXM_STREAM_TXM_STR_PRC_STAT_LAST_MSDU_BIT    ((uint32_t)0x10000000)
#define TXM_STREAM_TXM_STR_PRC_STAT_LAST_MSDU_POS    28
#define TXM_STREAM_TXM_STR_PRC_STAT_MSDU_CNT_MASK    ((uint32_t)0x0F000000)
#define TXM_STREAM_TXM_STR_PRC_STAT_MSDU_CNT_LSB    24
#define TXM_STREAM_TXM_STR_PRC_STAT_MSDU_CNT_WIDTH    ((uint32_t)0x00000004)
#define TXM_STREAM_TXM_STR_PRC_STAT_LLI_CNT_MASK    ((uint32_t)0x00FFF000)
#define TXM_STREAM_TXM_STR_PRC_STAT_LLI_CNT_LSB    12
#define TXM_STREAM_TXM_STR_PRC_STAT_LLI_CNT_WIDTH    ((uint32_t)0x0000000C)
#define TXM_STREAM_TXM_STR_PRC_STAT_MPDU_CNT_MASK    ((uint32_t)0x000003FF)
#define TXM_STREAM_TXM_STR_PRC_STAT_MPDU_CNT_LSB    0
#define TXM_STREAM_TXM_STR_PRC_STAT_MPDU_CNT_WIDTH    ((uint32_t)0x0000000A)

#define TXM_STREAM_TXM_STR_PRC_STAT_PRF_EXCEED_RST    0x0
#define TXM_STREAM_TXM_STR_PRC_STAT_PRF_MAX_BYTE_COUNT_RST    0x0
#define TXM_STREAM_TXM_STR_PRC_STAT_PRF_MAX_MPDU_RST    0x0
#define TXM_STREAM_TXM_STR_PRC_STAT_LAST_MSDU_RST    0x0
#define TXM_STREAM_TXM_STR_PRC_STAT_MSDU_CNT_RST    0x0
#define TXM_STREAM_TXM_STR_PRC_STAT_LLI_CNT_RST    0x0
#define TXM_STREAM_TXM_STR_PRC_STAT_MPDU_CNT_RST    0x0

__INLINE void txm_stream_txm_str_prc_stat_unpack(uint8_t* prf_exceed, uint8_t* prf_max_byte_count, uint8_t* prf_max_mpdu, uint8_t* last_msdu, uint8_t* msdu_cnt, uint16_t* lli_cnt, uint16_t* mpdu_cnt, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRC_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*prf_exceed = (localVal & ((uint32_t)0x80000000)) >>  31;
	*prf_max_byte_count = (localVal & ((uint32_t)0x40000000)) >>  30;
	*prf_max_mpdu = (localVal & ((uint32_t)0x20000000)) >>  29;
	*last_msdu = (localVal & ((uint32_t)0x10000000)) >>  28;
	*msdu_cnt = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*lli_cnt = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*mpdu_cnt = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t txm_stream_txm_str_prc_stat_prf_exceed_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRC_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE uint8_t txm_stream_txm_str_prc_stat_prf_max_byte_count_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRC_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x40000000)) >> 30);
}
__INLINE uint8_t txm_stream_txm_str_prc_stat_prf_max_mpdu_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRC_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x20000000)) >> 29);
}
__INLINE uint8_t txm_stream_txm_str_prc_stat_last_msdu_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRC_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE uint8_t txm_stream_txm_str_prc_stat_msdu_cnt_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRC_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE uint16_t txm_stream_txm_str_prc_stat_lli_cnt_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRC_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE uint16_t txm_stream_txm_str_prc_stat_mpdu_cnt_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_PRC_STAT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}

/**
 * @brief TXM_STR_BUFF_LEVEL register definition
 *  Stream buffer occupancy level register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 ACTIVE_BYTE_CNT_LEVEL     0x0
 *    15:00 PRF_BYTE_CNT_LEVEL        0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_BUFF_LEVEL_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000BC)
#define TXM_STREAM_TXM_STR_BUFF_LEVEL_OFFSET      0x000000BC
#define TXM_STREAM_TXM_STR_BUFF_LEVEL_INDEX       0x0000002F
#define TXM_STREAM_TXM_STR_BUFF_LEVEL_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_buff_level_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_LEVEL_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_BUFF_LEVEL_ACTIVE_BYTE_CNT_LEVEL_MASK    ((uint32_t)0xFFFF0000)
#define TXM_STREAM_TXM_STR_BUFF_LEVEL_ACTIVE_BYTE_CNT_LEVEL_LSB    16
#define TXM_STREAM_TXM_STR_BUFF_LEVEL_ACTIVE_BYTE_CNT_LEVEL_WIDTH    ((uint32_t)0x00000010)
#define TXM_STREAM_TXM_STR_BUFF_LEVEL_PRF_BYTE_CNT_LEVEL_MASK    ((uint32_t)0x0000FFFF)
#define TXM_STREAM_TXM_STR_BUFF_LEVEL_PRF_BYTE_CNT_LEVEL_LSB    0
#define TXM_STREAM_TXM_STR_BUFF_LEVEL_PRF_BYTE_CNT_LEVEL_WIDTH    ((uint32_t)0x00000010)

#define TXM_STREAM_TXM_STR_BUFF_LEVEL_ACTIVE_BYTE_CNT_LEVEL_RST    0x0
#define TXM_STREAM_TXM_STR_BUFF_LEVEL_PRF_BYTE_CNT_LEVEL_RST    0x0

__INLINE void txm_stream_txm_str_buff_level_unpack(uint16_t* active_byte_cnt_level, uint16_t* prf_byte_cnt_level, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_LEVEL_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*active_byte_cnt_level = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*prf_byte_cnt_level = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t txm_stream_txm_str_buff_level_active_byte_cnt_level_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_LEVEL_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t txm_stream_txm_str_buff_level_prf_byte_cnt_level_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_LEVEL_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief TXM_STR_BUFF_CURR_PTR register definition
 *  Stream current buffer pointer  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BUFF_CURR_PTR             0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_BUFF_CURR_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000C0)
#define TXM_STREAM_TXM_STR_BUFF_CURR_PTR_OFFSET      0x000000C0
#define TXM_STREAM_TXM_STR_BUFF_CURR_PTR_INDEX       0x00000030
#define TXM_STREAM_TXM_STR_BUFF_CURR_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_buff_curr_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_CURR_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_buff_curr_ptr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_BUFF_CURR_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_BUFF_CURR_PTR_BUFF_CURR_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_BUFF_CURR_PTR_BUFF_CURR_PTR_LSB    0
#define TXM_STREAM_TXM_STR_BUFF_CURR_PTR_BUFF_CURR_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_BUFF_CURR_PTR_BUFF_CURR_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_buff_curr_ptr_buff_curr_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_CURR_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_buff_curr_ptr_buff_curr_ptr_setf(uint32_t buffcurrptr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)buffcurrptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_BUFF_CURR_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)buffcurrptr << 0);
}

/**
 * @brief TXM_STR_BUFF_PREPARE_START_PTR register definition
 *  Buffer MPDU start pointer in prefetch state register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BUFF_PREPARE_START_PTR    0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_START_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000C4)
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_START_PTR_OFFSET      0x000000C4
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_START_PTR_INDEX       0x00000031
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_START_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_buff_prepare_start_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_PREPARE_START_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_buff_prepare_start_ptr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_BUFF_PREPARE_START_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_START_PTR_BUFF_PREPARE_START_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_START_PTR_BUFF_PREPARE_START_PTR_LSB    0
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_START_PTR_BUFF_PREPARE_START_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_BUFF_PREPARE_START_PTR_BUFF_PREPARE_START_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_buff_prepare_start_ptr_buff_prepare_start_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_PREPARE_START_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_buff_prepare_start_ptr_buff_prepare_start_ptr_setf(uint32_t buffpreparestartptr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)buffpreparestartptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_BUFF_PREPARE_START_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)buffpreparestartptr << 0);
}

/**
 * @brief TXM_STR_BUFF_PREPARE_END_PTR register definition
 *  Buffer MPDU end (last) pointer in prefetch state register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BUFF_PREPARE_END_PTR      0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_END_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000C8)
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_END_PTR_OFFSET      0x000000C8
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_END_PTR_INDEX       0x00000032
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_END_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_buff_prepare_end_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_PREPARE_END_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_buff_prepare_end_ptr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_BUFF_PREPARE_END_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_END_PTR_BUFF_PREPARE_END_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_END_PTR_BUFF_PREPARE_END_PTR_LSB    0
#define TXM_STREAM_TXM_STR_BUFF_PREPARE_END_PTR_BUFF_PREPARE_END_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_BUFF_PREPARE_END_PTR_BUFF_PREPARE_END_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_buff_prepare_end_ptr_buff_prepare_end_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_PREPARE_END_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_buff_prepare_end_ptr_buff_prepare_end_ptr_setf(uint32_t buffprepareendptr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)buffprepareendptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_BUFF_PREPARE_END_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)buffprepareendptr << 0);
}

/**
 * @brief TXM_STR_BUFF_ACTIVE_START_PTR register definition
 *  Buffer MPDU start pointer in active state register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BUFF_ACTIVE_START_PTR     0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_START_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000CC)
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_START_PTR_OFFSET      0x000000CC
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_START_PTR_INDEX       0x00000033
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_START_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_buff_active_start_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_ACTIVE_START_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_buff_active_start_ptr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_BUFF_ACTIVE_START_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_START_PTR_BUFF_ACTIVE_START_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_START_PTR_BUFF_ACTIVE_START_PTR_LSB    0
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_START_PTR_BUFF_ACTIVE_START_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_START_PTR_BUFF_ACTIVE_START_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_buff_active_start_ptr_buff_active_start_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_ACTIVE_START_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_buff_active_start_ptr_buff_active_start_ptr_setf(uint32_t buffactivestartptr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)buffactivestartptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_BUFF_ACTIVE_START_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)buffactivestartptr << 0);
}

/**
 * @brief TXM_STR_BUFF_ACTIVE_END_PTR register definition
 *  Buffer MPDU end (last) pointer in active state register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BUFF_ACTIVE_END_PTR       0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_END_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000D0)
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_END_PTR_OFFSET      0x000000D0
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_END_PTR_INDEX       0x00000034
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_END_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_buff_active_end_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_ACTIVE_END_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

__INLINE void  txm_stream_txm_str_buff_active_end_ptr_set(uint32_t value, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	REG_PL_WR((TXM_STREAM_TXM_STR_BUFF_ACTIVE_END_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), value);
}

// field definitions
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_END_PTR_BUFF_ACTIVE_END_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_END_PTR_BUFF_ACTIVE_END_PTR_LSB    0
#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_END_PTR_BUFF_ACTIVE_END_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_BUFF_ACTIVE_END_PTR_BUFF_ACTIVE_END_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_buff_active_end_ptr_buff_active_end_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BUFF_ACTIVE_END_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_stream_txm_str_buff_active_end_ptr_buff_active_end_ptr_setf(uint32_t buffactiveendptr, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	ASSERT_ERR((((uint32_t)buffactiveendptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR((TXM_STREAM_TXM_STR_BUFF_ACTIVE_END_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx)), (uint32_t)buffactiveendptr << 0);
}

/**
 * @brief TXM_STR_OLDEST_THD_INFO register definition
 *  Oldest THD info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:08 OLDEST_THD_MPDU_NUM       0x0
 *    06:00 OLDEST_THD_INDEX          0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_OLDEST_THD_INFO_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000D4)
#define TXM_STREAM_TXM_STR_OLDEST_THD_INFO_OFFSET      0x000000D4
#define TXM_STREAM_TXM_STR_OLDEST_THD_INFO_INDEX       0x00000035
#define TXM_STREAM_TXM_STR_OLDEST_THD_INFO_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_oldest_thd_info_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_OLDEST_THD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_OLDEST_THD_INFO_OLDEST_THD_MPDU_NUM_MASK    ((uint32_t)0x0003FF00)
#define TXM_STREAM_TXM_STR_OLDEST_THD_INFO_OLDEST_THD_MPDU_NUM_LSB    8
#define TXM_STREAM_TXM_STR_OLDEST_THD_INFO_OLDEST_THD_MPDU_NUM_WIDTH    ((uint32_t)0x0000000A)
#define TXM_STREAM_TXM_STR_OLDEST_THD_INFO_OLDEST_THD_INDEX_MASK    ((uint32_t)0x0000007F)
#define TXM_STREAM_TXM_STR_OLDEST_THD_INFO_OLDEST_THD_INDEX_LSB    0
#define TXM_STREAM_TXM_STR_OLDEST_THD_INFO_OLDEST_THD_INDEX_WIDTH    ((uint32_t)0x00000007)

#define TXM_STREAM_TXM_STR_OLDEST_THD_INFO_OLDEST_THD_MPDU_NUM_RST    0x0
#define TXM_STREAM_TXM_STR_OLDEST_THD_INFO_OLDEST_THD_INDEX_RST    0x0

__INLINE void txm_stream_txm_str_oldest_thd_info_unpack(uint16_t* oldest_thd_mpdu_num, uint8_t* oldest_thd_index, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_OLDEST_THD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*oldest_thd_mpdu_num = (localVal & ((uint32_t)0x0003FF00)) >>  8;
	*oldest_thd_index = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint16_t txm_stream_txm_str_oldest_thd_info_oldest_thd_mpdu_num_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_OLDEST_THD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)((localVal & ((uint32_t)0x0003FF00)) >> 8);
}
__INLINE uint8_t txm_stream_txm_str_oldest_thd_info_oldest_thd_index_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_OLDEST_THD_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}

/**
 * @brief TXM_STR_CURR_THD_PTR register definition
 *  Current THD pointer in buffer register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CURR_THD_PTR              0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_CURR_THD_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000D8)
#define TXM_STREAM_TXM_STR_CURR_THD_PTR_OFFSET      0x000000D8
#define TXM_STREAM_TXM_STR_CURR_THD_PTR_INDEX       0x00000036
#define TXM_STREAM_TXM_STR_CURR_THD_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_curr_thd_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_CURR_THD_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_CURR_THD_PTR_CURR_THD_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_CURR_THD_PTR_CURR_THD_PTR_LSB    0
#define TXM_STREAM_TXM_STR_CURR_THD_PTR_CURR_THD_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_CURR_THD_PTR_CURR_THD_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_curr_thd_ptr_curr_thd_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_CURR_THD_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief TXM_STR_CURR_THD_MPDU_NUM register definition
 *  Current THD MPDU number register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:00 CURR_THD_MPDU_NUM         0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_CURR_THD_MPDU_NUM_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000DC)
#define TXM_STREAM_TXM_STR_CURR_THD_MPDU_NUM_OFFSET      0x000000DC
#define TXM_STREAM_TXM_STR_CURR_THD_MPDU_NUM_INDEX       0x00000037
#define TXM_STREAM_TXM_STR_CURR_THD_MPDU_NUM_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_curr_thd_mpdu_num_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_CURR_THD_MPDU_NUM_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_CURR_THD_MPDU_NUM_CURR_THD_MPDU_NUM_MASK    ((uint32_t)0x000003FF)
#define TXM_STREAM_TXM_STR_CURR_THD_MPDU_NUM_CURR_THD_MPDU_NUM_LSB    0
#define TXM_STREAM_TXM_STR_CURR_THD_MPDU_NUM_CURR_THD_MPDU_NUM_WIDTH    ((uint32_t)0x0000000A)

#define TXM_STREAM_TXM_STR_CURR_THD_MPDU_NUM_CURR_THD_MPDU_NUM_RST    0x0

__INLINE uint16_t txm_stream_txm_str_curr_thd_mpdu_num_curr_thd_mpdu_num_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_CURR_THD_MPDU_NUM_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief TXM_STR_LAST_THD_AMPDU_PTR register definition
 *  Last THD in AMPDU buffer pointer register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LAST_THD_AMPDU_PTR        0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_LAST_THD_AMPDU_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000E0)
#define TXM_STREAM_TXM_STR_LAST_THD_AMPDU_PTR_OFFSET      0x000000E0
#define TXM_STREAM_TXM_STR_LAST_THD_AMPDU_PTR_INDEX       0x00000038
#define TXM_STREAM_TXM_STR_LAST_THD_AMPDU_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_last_thd_ampdu_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LAST_THD_AMPDU_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_LAST_THD_AMPDU_PTR_LAST_THD_AMPDU_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_LAST_THD_AMPDU_PTR_LAST_THD_AMPDU_PTR_LSB    0
#define TXM_STREAM_TXM_STR_LAST_THD_AMPDU_PTR_LAST_THD_AMPDU_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_LAST_THD_AMPDU_PTR_LAST_THD_AMPDU_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_last_thd_ampdu_ptr_last_thd_ampdu_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LAST_THD_AMPDU_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief TXM_STR_LAST_THD_DONE_PTR register definition
 *  Last THD done buffer pointer register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LAST_THD_DONE_PTR         0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000E8)
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_PTR_OFFSET      0x000000E8
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_PTR_INDEX       0x0000003A
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_last_thd_done_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LAST_THD_DONE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_PTR_LAST_THD_DONE_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_PTR_LAST_THD_DONE_PTR_LSB    0
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_PTR_LAST_THD_DONE_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_LAST_THD_DONE_PTR_LAST_THD_DONE_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_last_thd_done_ptr_last_thd_done_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LAST_THD_DONE_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief TXM_STR_LAST_THD_DONE_MPDU_NUM register definition
 *  Last THD done MPDU number register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:00 LAST_THD_DONE_MPDU_NUM    0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_MPDU_NUM_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000EC)
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_MPDU_NUM_OFFSET      0x000000EC
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_MPDU_NUM_INDEX       0x0000003B
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_MPDU_NUM_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_last_thd_done_mpdu_num_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LAST_THD_DONE_MPDU_NUM_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_MPDU_NUM_LAST_THD_DONE_MPDU_NUM_MASK    ((uint32_t)0x000003FF)
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_MPDU_NUM_LAST_THD_DONE_MPDU_NUM_LSB    0
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_MPDU_NUM_LAST_THD_DONE_MPDU_NUM_WIDTH    ((uint32_t)0x0000000A)

#define TXM_STREAM_TXM_STR_LAST_THD_DONE_MPDU_NUM_LAST_THD_DONE_MPDU_NUM_RST    0x0

__INLINE uint16_t txm_stream_txm_str_last_thd_done_mpdu_num_last_thd_done_mpdu_num_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LAST_THD_DONE_MPDU_NUM_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief TXM_STR_LAST_THD_DONE_NEXT_PTR register definition
 *  Next THD after last THD done buffer pointer register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LAST_THD_DONE_NEXT_PTR    0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_NEXT_PTR_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000F0)
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_NEXT_PTR_OFFSET      0x000000F0
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_NEXT_PTR_INDEX       0x0000003C
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_NEXT_PTR_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_last_thd_done_next_ptr_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LAST_THD_DONE_NEXT_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_NEXT_PTR_LAST_THD_DONE_NEXT_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_NEXT_PTR_LAST_THD_DONE_NEXT_PTR_LSB    0
#define TXM_STREAM_TXM_STR_LAST_THD_DONE_NEXT_PTR_LAST_THD_DONE_NEXT_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_STREAM_TXM_STR_LAST_THD_DONE_NEXT_PTR_LAST_THD_DONE_NEXT_PTR_RST    0x0

__INLINE uint32_t txm_stream_txm_str_last_thd_done_next_ptr_last_thd_done_next_ptr_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LAST_THD_DONE_NEXT_PTR_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief TXM_STR_LLI_INT_DONE_INFO register definition
 *  LLI done status info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09:08 LLI_INT_DONE_REASON       0x0
 *    07:00 LLI_INT_DONE_MPDU_NUM     0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000F8)
#define TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_OFFSET      0x000000F8
#define TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_INDEX       0x0000003E
#define TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_lli_int_done_info_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_LLI_INT_DONE_REASON_MASK    ((uint32_t)0x00000300)
#define TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_LLI_INT_DONE_REASON_LSB    8
#define TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_LLI_INT_DONE_REASON_WIDTH    ((uint32_t)0x00000002)
#define TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_LLI_INT_DONE_MPDU_NUM_MASK    ((uint32_t)0x000000FF)
#define TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_LLI_INT_DONE_MPDU_NUM_LSB    0
#define TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_LLI_INT_DONE_MPDU_NUM_WIDTH    ((uint32_t)0x00000008)

#define TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_LLI_INT_DONE_REASON_RST    0x0
#define TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_LLI_INT_DONE_MPDU_NUM_RST    0x0

__INLINE void txm_stream_txm_str_lli_int_done_info_unpack(uint8_t* lli_int_done_reason, uint8_t* lli_int_done_mpdu_num, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*lli_int_done_reason = (localVal & ((uint32_t)0x00000300)) >>  8;
	*lli_int_done_mpdu_num = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t txm_stream_txm_str_lli_int_done_info_lli_int_done_reason_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE uint8_t txm_stream_txm_str_lli_int_done_info_lli_int_done_mpdu_num_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_LLI_INT_DONE_INFO_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief TXM_STR_BYTE_FETCH_CNT register definition
 *  Stream fetched bytes statistics register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 LLI_BYTE_CNT              0x0
 *    15:00 MPDU_BYTE_CNT             0x0
 * </pre>
 */
#define TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_ADDR        (REG_TXM_STREAM_BASE_ADDR+0x000000FC)
#define TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_OFFSET      0x000000FC
#define TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_INDEX       0x0000003F
#define TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_RESET       0x00000000

__INLINE uint32_t  txm_stream_txm_str_byte_fetch_cnt_get(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (localVal);
}

// field definitions
#define TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_LLI_BYTE_CNT_MASK    ((uint32_t)0xFFFF0000)
#define TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_LLI_BYTE_CNT_LSB    16
#define TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_LLI_BYTE_CNT_WIDTH    ((uint32_t)0x00000010)
#define TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_MPDU_BYTE_CNT_MASK    ((uint32_t)0x0000FFFF)
#define TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_MPDU_BYTE_CNT_LSB    0
#define TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_MPDU_BYTE_CNT_WIDTH    ((uint32_t)0x00000010)

#define TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_LLI_BYTE_CNT_RST    0x0
#define TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_MPDU_BYTE_CNT_RST    0x0

__INLINE void txm_stream_txm_str_byte_fetch_cnt_unpack(uint16_t* lli_byte_cnt, uint16_t* mpdu_byte_cnt, uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));

	*lli_byte_cnt = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*mpdu_byte_cnt = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t txm_stream_txm_str_byte_fetch_cnt_lli_byte_cnt_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t txm_stream_txm_str_byte_fetch_cnt_mpdu_byte_cnt_getf(uint8_t stream_idx)
{
	ASSERT_ERR_REG(stream_idx < TXM_STREAM_CNT);
	uint32_t localVal = REG_PL_RD(TXM_STREAM_TXM_STR_BYTE_FETCH_CNT_ADDR + CE_TXM_STREAM_ADDR_OFFSET(stream_idx));
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}


#undef DBG_FILEID
#endif //_REG_TXM_STREAM_H_
